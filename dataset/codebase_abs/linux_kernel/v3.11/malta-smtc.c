static void F_1 ( int V_1 , unsigned int V_2 )
{
F_2 ( V_1 , V_3 , V_2 ) ;
}
static void F_3 ( const struct V_4 * V_5 , unsigned int V_2 )
{
unsigned int V_6 ;
F_4 (i, mask)
F_1 ( V_6 , V_2 ) ;
}
static void F_5 ( void )
{
int V_7 ;
V_7 = F_6 () & V_8 ;
if ( V_7 != 0 ) {
F_7 ( V_9 ) ;
F_8 ( ( 0x100 << V_10 )
| ( 0x100 << V_11 ) ) ;
if ( V_12 >= 0 )
F_8 ( 0x100 << V_12 ) ;
}
F_9 () ;
}
static void F_10 ( int V_1 , struct V_13 * V_14 )
{
F_11 ( V_1 , V_14 ) ;
}
static void F_12 ( void )
{
F_13 () ;
}
static void F_14 ( void )
{
}
static void T_1 F_15 ( void )
{
V_15 = F_16 ( 0 ) ;
}
static void T_1 F_17 ( unsigned int V_16 )
{
F_18 ( V_16 ) ;
}
int F_19 ( struct V_17 * V_18 , const struct V_4 * V_19 ,
bool V_20 )
{
T_2 V_21 ;
int V_1 = 0 ;
void V_22 ( unsigned int V_23 , T_2 V_24 ) ;
F_20 ( & V_21 , V_19 ) ;
F_4 (cpu, affinity) {
if ( ( V_25 [ V_1 ] . V_26 != 0 ) || ! F_21 ( V_1 ) )
F_22 ( V_1 , V_21 ) ;
}
F_20 ( V_18 -> V_19 , & V_21 ) ;
if ( F_23 ( V_21 ) )
F_24 ( V_27
L_1 , V_18 -> V_23 ) ;
V_22 ( V_18 -> V_23 , V_21 ) ;
return V_28 ;
}
