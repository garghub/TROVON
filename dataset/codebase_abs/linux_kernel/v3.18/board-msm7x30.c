static void T_1 F_1 ( struct V_1 * V_1 , char * * V_2 )
{
for (; V_1 -> V_3 . V_4 ; V_1 = F_2 ( V_1 ) )
if ( V_1 -> V_3 . V_1 == V_5 && V_1 -> V_6 . V_7 . V_8 == 0x200000 ) {
V_1 -> V_6 . V_7 . V_8 = 0 ;
V_1 -> V_6 . V_7 . V_4 += V_9 ;
}
}
static void T_1 F_3 ( void )
{
F_4 ( 0x0 , V_9 ) ;
}
static int F_5 ( struct V_10 * V_11 , bool assert )
{
int V_12 ;
if ( assert ) {
V_12 = F_6 ( V_11 , V_13 ) ;
if ( V_12 )
F_7 ( L_1 ) ;
} else {
V_12 = F_6 ( V_11 , V_14 ) ;
if ( V_12 )
F_7 ( L_2 ) ;
}
return V_12 ;
}
static int F_8 ( struct V_10 * V_15 )
{
int V_12 ;
V_12 = F_6 ( V_15 , V_13 ) ;
if ( V_12 ) {
F_7 ( L_3 ) ;
return V_12 ;
}
F_9 ( 10000 , 12000 ) ;
V_12 = F_6 ( V_15 , V_14 ) ;
if ( V_12 )
F_7 ( L_4 ) ;
return V_12 ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
}
static void T_1 F_12 ( void )
{
V_16 . V_17 . V_18 = & V_19 ;
V_20 . V_17 . V_21 = & V_16 . V_17 ;
V_22 . V_17 . V_21 = & V_16 . V_17 ;
F_13 ( V_23 , F_14 ( V_23 ) ) ;
}
static void T_1 F_15 ( void )
{
F_16 () ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
}
