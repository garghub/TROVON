static void T_1 F_1 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
struct V_4 * V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_5 ) ;
return;
}
F_4 ( V_2 , V_3 , V_6 ) ;
V_4 = F_5 ( NULL , L_2 , L_3 , 0 , 1 , 2 ) ;
if ( F_6 ( V_4 ) )
F_7 ( L_4 ,
V_5 , F_8 ( V_4 ) ) ;
V_4 = F_5 ( NULL , L_5 , L_3 , 0 , 20 , 1 ) ;
if ( F_6 ( V_4 ) )
F_7 ( L_6 ,
V_5 , F_8 ( V_4 ) ) ;
F_9 ( V_7 ,
F_10 ( V_7 ) ,
V_8 ) ;
F_11 ( V_9 ,
F_10 ( V_9 ) ) ;
F_12 ( V_2 , 9 , V_3 + F_13 ( 0 ) ,
V_10 ) ;
}
static void T_1 F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_11 ,
F_10 ( V_11 ) ) ;
}
static void T_1 F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_12 ,
F_10 ( V_12 ) ) ;
}
static void T_1 F_16 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_10 ( V_7 ) ; V_13 ++ ) {
struct V_14 * V_15 = & V_7 [ V_13 ] ;
struct V_16 * V_17 ;
if ( ! V_15 -> V_18 )
continue;
V_17 = V_15 -> V_18 ;
while ( V_17 -> V_17 > 0 ) {
V_17 -> V_19 = 0 ;
V_17 ++ ;
}
}
F_15 ( V_2 ) ;
}
