

class Juego{
    private:
        int **m;
        int score;
    public:
        Juego(int **m,int score);
        double getscore();
        int **getmat();
        void setscore();
        void sumarpuntos();
        void llenarmat(int n);
        void P_JUEGO();
        void recorrer(int n);
        void MatrizSP(int, int, int, int);
        void imprimir();
        void UP(int);
        void DOWN(int);
        void RIGHT(int);
        void LEFT(int);
        void Puzzle_Juego();
        void zen_juego();
};

