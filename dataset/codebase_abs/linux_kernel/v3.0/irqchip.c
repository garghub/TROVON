void F_1 ( unsigned int V_1 )
{
F_2 ( & V_2 ) ;
F_3 ( V_3 L_1 , V_1 ) ;
}
int F_4 ( struct V_4 * V_5 , void * V_6 )
{
int V_7 = * ( V_8 * ) V_6 , V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
if ( V_7 < V_13 ) {
struct V_14 * V_15 = F_5 ( V_7 ) ;
F_6 ( & V_15 -> V_16 , V_12 ) ;
V_11 = V_15 -> V_11 ;
if ( ! V_11 )
goto V_17;
F_7 ( V_5 , L_2 , V_7 ) ;
F_8 (j)
F_7 ( V_5 , L_3 , F_9 ( V_7 , V_9 ) ) ;
F_7 ( V_5 , L_4 , F_10 ( V_15 ) -> V_18 ) ;
F_7 ( V_5 , L_5 , V_11 -> V_18 ) ;
for ( V_11 = V_11 -> V_19 ; V_11 ; V_11 = V_11 -> V_19 )
F_7 ( V_5 , L_5 , V_11 -> V_18 ) ;
F_11 ( V_5 , '\n' ) ;
V_17:
F_12 ( & V_15 -> V_16 , V_12 ) ;
} else if ( V_7 == V_13 ) {
F_7 ( V_5 , L_6 ) ;
F_8 (j)
F_7 ( V_5 , L_3 , V_20 [ V_9 ] . V_21 ) ;
F_7 ( V_5 , L_7 ) ;
F_7 ( V_5 , L_8 , F_13 ( & V_2 ) ) ;
}
return 0 ;
}
static void F_14 ( int V_1 )
{
long V_22 = F_15 () & ( V_23 - 1 ) ;
if ( F_16 ( V_22 < ( sizeof( struct V_24 ) + V_25 ) ) ) {
F_17 () ;
F_18 ( L_9 ,
V_1 , V_22 - sizeof( struct V_24 ) ) ;
}
}
static inline void F_14 ( int V_1 ) { }
static void F_19 ( void )
{
unsigned short V_26 , V_27 ;
F_20 () ;
V_26 = F_21 () & ~ 0x8000 ;
V_27 = V_26 & ( V_26 - 1 ) ;
if ( V_27 == 0 )
F_22 () ;
}
static inline void F_19 ( void ) { }
T_1 void F_23 ( unsigned int V_1 , struct V_28 * V_29 )
{
struct V_28 * V_30 = F_24 ( V_29 ) ;
F_25 () ;
F_14 ( V_1 ) ;
if ( V_1 >= V_13 )
F_26 ( V_1 , & V_31 ) ;
else
F_27 ( V_1 ) ;
F_19 () ;
F_28 () ;
F_24 ( V_30 ) ;
}
void T_2 F_29 ( void )
{
F_30 () ;
#ifdef F_31
V_32 = 0 ;
F_32 ( V_33 ) ;
F_3 ( V_34 L_10 ,
1 << V_35 ) ;
#endif
}
