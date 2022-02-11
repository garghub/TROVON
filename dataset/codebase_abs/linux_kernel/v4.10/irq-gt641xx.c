static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_5 , V_3 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_6 , V_4 ) ;
F_6 ( & V_5 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_8 ;
F_2 ( & V_5 , V_3 ) ;
V_8 = F_3 ( V_9 ) ;
V_8 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_9 , V_8 ) ;
F_6 ( & V_5 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 , V_8 ;
F_2 ( & V_5 , V_3 ) ;
V_8 = F_3 ( V_9 ) ;
V_8 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_9 , V_8 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_6 , V_4 ) ;
F_6 ( & V_5 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_8 ;
F_2 ( & V_5 , V_3 ) ;
V_8 = F_3 ( V_9 ) ;
V_8 |= F_4 ( V_2 -> V_7 ) ;
F_5 ( V_9 , V_8 ) ;
F_6 ( & V_5 , V_3 ) ;
}
void F_10 ( void )
{
T_1 V_4 , V_8 ;
int V_10 ;
V_4 = F_3 ( V_6 ) ;
V_8 = F_3 ( V_9 ) ;
V_4 &= V_8 ;
for ( V_10 = 1 ; V_10 < 30 ; V_10 ++ ) {
if ( V_4 & ( 1U << V_10 ) ) {
F_11 ( V_11 + V_10 ) ;
return;
}
}
F_12 ( & V_12 ) ;
}
void T_2 F_13 ( void )
{
int V_10 ;
F_5 ( V_9 , 0 ) ;
F_5 ( V_6 , 0 ) ;
for ( V_10 = 1 ; V_10 < 30 ; V_10 ++ )
F_14 ( V_11 + V_10 ,
& V_13 , V_14 ) ;
}
