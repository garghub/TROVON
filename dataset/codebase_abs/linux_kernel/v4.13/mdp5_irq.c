void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
F_2 ( F_3 ( V_1 ) , V_4 ,
V_2 ^ ( V_2 & V_3 ) ) ;
F_2 ( F_3 ( V_1 ) , V_5 , V_2 ) ;
}
static void F_4 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_7 , struct V_9 , V_10 ) ;
static F_6 ( V_11 , 5 * V_12 , 1 ) ;
extern bool V_13 ;
F_7 ( L_1 , V_8 ) ;
if ( V_13 && F_8 ( & V_11 ) ) {
struct V_14 V_15 = F_9 ( V_9 -> V_16 -> V_16 ) ;
F_10 ( V_9 -> V_16 , & V_15 ) ;
if ( V_9 -> V_17 )
F_11 ( V_9 -> V_17 , & V_15 ) ;
}
}
void F_12 ( struct V_18 * V_19 )
{
struct V_9 * V_9 = F_3 ( F_13 ( V_19 ) ) ;
F_14 ( V_9 ) ;
F_2 ( V_9 , V_4 , 0xffffffff ) ;
F_2 ( V_9 , V_5 , 0x00000000 ) ;
F_15 ( V_9 ) ;
}
int F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_13 ( V_19 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_6 * V_10 = & V_9 -> V_10 ;
V_10 -> V_7 = F_4 ;
V_10 -> V_2 = V_20 |
V_21 |
V_22 |
V_23 ;
F_14 ( V_9 ) ;
F_17 ( V_1 , V_10 ) ;
F_15 ( V_9 ) ;
return 0 ;
}
void F_18 ( struct V_18 * V_19 )
{
struct V_9 * V_9 = F_3 ( F_13 ( V_19 ) ) ;
F_14 ( V_9 ) ;
F_2 ( V_9 , V_5 , 0x00000000 ) ;
F_15 ( V_9 ) ;
}
T_2 F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_13 ( V_19 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_24 * V_16 = V_9 -> V_16 ;
struct V_25 * V_26 = V_16 -> V_27 ;
unsigned int V_28 ;
T_1 V_29 , V_30 ;
V_30 = F_20 ( V_9 , V_5 ) ;
V_29 = F_20 ( V_9 , V_31 ) & V_30 ;
F_2 ( V_9 , V_4 , V_29 ) ;
F_21 ( L_2 , V_29 ) ;
F_22 ( V_1 , V_29 ) ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
if ( V_29 & F_23 ( V_26 -> V_33 [ V_28 ] ) )
F_24 ( V_16 , V_28 ) ;
return V_34 ;
}
int F_25 ( struct V_18 * V_19 , struct V_35 * V_36 )
{
struct V_9 * V_9 = F_3 ( F_13 ( V_19 ) ) ;
F_14 ( V_9 ) ;
F_26 ( F_13 ( V_19 ) ,
F_23 ( V_36 ) , true ) ;
F_15 ( V_9 ) ;
return 0 ;
}
void F_27 ( struct V_18 * V_19 , struct V_35 * V_36 )
{
struct V_9 * V_9 = F_3 ( F_13 ( V_19 ) ) ;
F_14 ( V_9 ) ;
F_26 ( F_13 ( V_19 ) ,
F_23 ( V_36 ) , false ) ;
F_15 ( V_9 ) ;
}
