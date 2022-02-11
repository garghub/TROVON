void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( F_3 ( V_1 ) , V_3 , V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 , T_1 V_6 )
{
F_5 ( L_1 , V_6 ) ;
}
void F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_2 ( V_9 , V_10 , 0xffffffff ) ;
}
int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_4 * V_11 = & V_9 -> V_11 ;
V_11 -> V_5 = F_4 ;
V_11 -> V_2 = V_12 |
V_13 ;
F_9 ( V_1 , V_11 ) ;
return 0 ;
}
void F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_2 ( V_9 , V_3 , 0x00000000 ) ;
}
T_2 F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_14 * V_15 = V_9 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_19 ;
T_1 V_20 ;
V_20 = F_12 ( V_9 , V_21 ) ;
F_2 ( V_9 , V_10 , V_20 ) ;
F_13 ( L_2 , V_20 ) ;
F_14 ( V_1 , V_20 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ )
if ( V_20 & F_15 ( V_17 -> V_23 [ V_19 ] ) )
F_16 ( V_15 , V_19 ) ;
return V_24 ;
}
int F_17 ( struct V_7 * V_8 , struct V_25 * V_26 )
{
F_18 ( F_7 ( V_8 ) ,
F_15 ( V_26 ) , true ) ;
return 0 ;
}
void F_19 ( struct V_7 * V_8 , struct V_25 * V_26 )
{
F_18 ( F_7 ( V_8 ) ,
F_15 ( V_26 ) , false ) ;
}
