static inline int F_1 ( void )
{
unsigned long V_1 ;
int V_2 ;
F_2 ( & V_3 , V_1 ) ;
V_2 = ( F_3 ( V_4 ) >> 4 ) - 1 ;
if ( V_2 == 0 || V_2 >= V_5 )
V_2 = - 1 ;
F_4 ( & V_3 , V_1 ) ;
return V_2 ;
}
static void F_5 ( void )
{
int V_2 ;
V_2 = F_1 () ;
if ( V_2 < 0 )
return;
F_6 ( V_2 ) ;
}
static inline int F_7 ( unsigned long V_6 )
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return V_6 ;
}
static inline unsigned int F_8 ( unsigned int V_7 )
{
return F_9 ( V_7 ) - 1 + V_8 ;
}
T_1 void F_10 ( void )
{
unsigned int V_7 = F_11 () & F_12 () & V_9 ;
int V_2 ;
V_2 = F_8 ( V_7 ) ;
if ( V_2 == V_10 )
F_5 () ;
else if ( V_2 >= 0 )
F_6 ( V_2 ) ;
else
F_13 () ;
}
void T_2 F_14 ( void )
{
int V_11 ;
F_15 () ;
if ( V_12 || V_13 ) {
int V_14 = V_12 ? 64 : 8 ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
F_16 ( V_11 , F_5 ) ;
}
}
