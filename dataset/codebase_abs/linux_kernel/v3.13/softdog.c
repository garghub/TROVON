static void F_1 ( unsigned long V_1 )
{
if ( V_2 )
F_2 ( L_1 ) ;
else if ( V_3 ) {
F_2 ( L_2 ) ;
F_3 ( L_3 ) ;
} else {
F_2 ( L_4 ) ;
F_4 () ;
F_2 ( L_5 ) ;
}
}
static int F_5 ( struct V_4 * V_5 )
{
F_6 ( & V_6 , V_7 + ( V_5 -> V_8 * V_9 ) ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
F_8 ( & V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , unsigned int V_10 )
{
V_5 -> V_8 = V_10 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , unsigned long V_13 ,
void * V_14 )
{
if ( V_13 == V_15 || V_13 == V_16 )
F_7 ( NULL ) ;
return V_17 ;
}
static int T_1 F_11 ( void )
{
int V_18 ;
if ( V_19 < 1 || V_19 > 65535 ) {
F_12 ( L_6 ,
V_20 ) ;
return - V_21 ;
}
V_22 . V_8 = V_19 ;
F_13 ( & V_22 , V_23 ) ;
V_18 = F_14 ( & V_24 ) ;
if ( V_18 ) {
F_15 ( L_7 , V_18 ) ;
return V_18 ;
}
V_18 = F_16 ( & V_22 ) ;
if ( V_18 ) {
F_17 ( & V_24 ) ;
return V_18 ;
}
F_12 ( L_8 ,
V_2 , V_19 , V_3 , V_23 ) ;
return 0 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_22 ) ;
F_17 ( & V_24 ) ;
}
