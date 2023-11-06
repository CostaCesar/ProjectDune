#include "Interface.h"

extern S_ArrayUsuarios Usuarios;
extern S_ArrayPostagens Postagens;
extern S_Usuario* Usuario_Logado;
extern S_Usuario* Usuario_Ativo;

int main(int argc, char** argv)
{
    int Resultado = 0;
    CarregarArquivo_Usuarios(&Usuarios, "users.bin");
    CarregarArquivo_Postagens(&Postagens, "posts.bin");
    while (1)
    {
        if(Mostrar_Tela_Inicio() == 1)
        {
            Deslogar_Usuario(&Usuario_Logado);
            SalvarArquivo_Postagens(&Postagens, "posts.bin");
            SalvarArquivo_Usuarios(&Usuarios, "users.bin");
            Liberar_Usuarios_Profundo(&Usuarios);
            Liberar_Postagens_Profundo(&Postagens);
            break;
        }
    }
    
    return 0;
}