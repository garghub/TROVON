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
V_13 |
V_14 |
V_15 ;
F_9 ( V_1 , V_11 ) ;
return 0 ;
}
void F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_2 ( V_9 , V_3 , 0x00000000 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_21 ;
T_1 V_22 ;
V_22 = F_12 ( V_9 , V_23 ) ;
F_2 ( V_9 , V_10 , V_22 ) ;
F_13 ( L_2 , V_22 ) ;
F_14 ( V_1 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_19 -> V_24 ; V_21 ++ )
if ( V_22 & F_15 ( V_19 -> V_25 [ V_21 ] ) )
F_16 ( V_17 , V_21 ) ;
}
T_2 F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
T_1 V_26 ;
V_26 = F_12 ( V_9 , V_27 ) ;
F_13 ( L_3 , V_26 ) ;
if ( V_26 & V_28 )
F_11 ( V_1 ) ;
if ( V_26 & V_29 )
F_18 ( 0 , V_9 -> V_30 ) ;
return V_31 ;
}
int F_19 ( struct V_7 * V_8 , struct V_32 * V_33 )
{
F_20 ( F_7 ( V_8 ) ,
F_15 ( V_33 ) , true ) ;
return 0 ;
}
void F_21 ( struct V_7 * V_8 , struct V_32 * V_33 )
{
F_20 ( F_7 ( V_8 ) ,
F_15 ( V_33 ) , false ) ;
}
