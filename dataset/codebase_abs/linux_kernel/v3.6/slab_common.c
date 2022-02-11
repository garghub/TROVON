struct V_1 * F_1 ( const char * V_2 , T_1 V_3 , T_1 V_4 ,
unsigned long V_5 , void (* F_2)( void * ) )
{
struct V_1 * V_6 = NULL ;
#ifdef F_3
if ( ! V_2 || F_4 () || V_3 < sizeof( void * ) ||
V_3 > V_7 ) {
F_5 ( V_8 L_1
L_2 , V_2 ) ;
goto V_9;
}
#endif
F_6 () ;
F_7 ( & V_10 ) ;
#ifdef F_3
F_8 (s, &slab_caches, list) {
char V_11 ;
int V_12 ;
V_12 = F_9 ( V_6 -> V_2 , V_11 ) ;
if ( V_12 ) {
F_5 ( V_8
L_3 ,
V_6 -> V_13 ) ;
continue;
}
if ( ! strcmp ( V_6 -> V_2 , V_2 ) ) {
F_5 ( V_8 L_4
L_5 ,
V_2 ) ;
F_10 () ;
V_6 = NULL ;
goto V_14;
}
}
F_11 ( strchr ( V_2 , ' ' ) ) ;
#endif
V_6 = F_12 ( V_2 , V_3 , V_4 , V_5 , F_2 ) ;
#ifdef F_3
V_14:
#endif
F_13 ( & V_10 ) ;
F_14 () ;
#ifdef F_3
V_9:
#endif
if ( ! V_6 && ( V_5 & V_15 ) )
F_15 ( L_6 , V_2 ) ;
return V_6 ;
}
int F_16 ( void )
{
return V_16 >= V_17 ;
}
