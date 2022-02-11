static void T_1 F_1 ( struct V_1 * V_1 , char * * V_2 ,
struct V_3 * V_4 )
{
for (; V_1 -> V_5 . V_6 ; V_1 = F_2 ( V_1 ) )
if ( V_1 -> V_5 . V_1 == V_7 && V_1 -> V_8 . V_9 . V_10 == 0x200000 ) {
V_1 -> V_8 . V_9 . V_10 = 0 ;
V_1 -> V_8 . V_9 . V_6 += V_11 ;
}
}
static void T_1 F_3 ( void )
{
F_4 ( 0x0 , V_11 ) ;
}
static int F_5 ( struct V_12 * V_13 , bool assert )
{
int V_14 ;
if ( assert ) {
V_14 = F_6 ( V_13 , V_15 ) ;
if ( V_14 )
F_7 ( L_1 ) ;
} else {
V_14 = F_6 ( V_13 , V_16 ) ;
if ( V_14 )
F_7 ( L_2 ) ;
}
return V_14 ;
}
static int F_8 ( struct V_12 * V_17 )
{
int V_14 ;
V_14 = F_6 ( V_17 , V_15 ) ;
if ( V_14 ) {
F_7 ( L_3 ) ;
return V_14 ;
}
F_9 ( 10000 , 12000 ) ;
V_14 = F_6 ( V_17 , V_16 ) ;
if ( V_14 )
F_7 ( L_4 ) ;
return V_14 ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
}
static void T_1 F_12 ( void )
{
V_18 . V_19 . V_20 = & V_21 ;
V_22 . V_19 . V_23 = & V_18 . V_19 ;
V_24 . V_19 . V_23 = & V_18 . V_19 ;
F_13 ( V_25 , F_14 ( V_25 ) ) ;
}
static void T_1 F_15 ( void )
{
F_16 () ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
}
