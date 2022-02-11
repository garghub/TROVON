static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 ( F_4 ( V_4 -> V_6 ) ) ;
V_5 &= ~ F_5 ( F_6 ( V_2 ) ) ;
F_7 ( V_5 , F_4 ( V_4 -> V_6 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 ( F_4 ( V_4 -> V_6 ) ) ;
V_5 |= F_5 ( F_6 ( V_2 ) ) ;
F_7 ( V_5 , F_4 ( V_4 -> V_6 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( F_5 ( F_6 ( V_2 ) ) , F_10 ( V_4 -> V_6 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = F_6 ( V_2 ) ;
T_1 V_9 , V_10 ;
V_9 = F_3 ( F_12 ( V_4 -> V_6 ) ) ;
V_10 = F_3 ( F_13 ( V_4 -> V_6 ) ) ;
if ( V_7 & ( V_11 ) ) {
F_14 ( V_2 , V_12 ) ;
V_9 &= ~ F_5 ( V_8 ) ;
V_10 |= F_5 ( V_8 ) ;
} else if ( V_7 & ( V_13 ) ) {
F_14 ( V_2 , V_12 ) ;
V_9 &= ~ F_5 ( V_8 ) ;
V_10 &= ~ F_5 ( V_8 ) ;
} else if ( V_7 & V_14 ) {
F_14 ( V_2 , V_15 ) ;
V_9 |= F_5 ( V_8 ) ;
V_10 |= F_5 ( V_8 ) ;
} else if ( V_7 & V_16 ) {
F_14 ( V_2 , V_15 ) ;
V_9 |= F_5 ( V_8 ) ;
V_10 &= ~ F_5 ( V_8 ) ;
} else {
F_14 ( V_2 , V_17 ) ;
F_15 ( L_1 ,
V_8 ) ;
}
F_7 ( V_9 , F_12 ( V_4 -> V_6 ) ) ;
F_7 ( V_10 , F_13 ( V_4 -> V_6 ) ) ;
return 0 ;
}
T_2 void T_3 F_16 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = & V_20 ;
int V_21 ;
T_1 V_22 ;
while ( ( V_22 = F_3 ( F_17 ( V_4 -> V_6 ) ) ) ) {
V_21 = F_18 ( V_22 ) - 1 ;
F_19 ( V_4 -> V_23 , V_21 , V_19 ) ;
}
}
static int F_20 ( struct V_24 * V_2 , unsigned int V_21 ,
T_4 V_25 )
{
struct V_3 * V_4 = V_2 -> V_26 ;
F_21 ( V_21 , V_4 ) ;
F_22 ( V_21 , & V_27 , V_17 ) ;
F_23 ( V_21 ) ;
return 0 ;
}
static void F_24 ( struct V_24 * V_2 , unsigned int V_21 )
{
F_22 ( V_21 , NULL , NULL ) ;
F_21 ( V_21 , NULL ) ;
}
int T_5 F_25 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
struct V_3 * V_4 = & V_20 ;
F_26 ( true ) ;
V_4 -> V_6 = F_27 ( V_29 , 0 ) ;
F_28 ( ! V_4 -> V_6 , L_2 ) ;
F_7 ( 0 , F_4 ( V_4 -> V_6 ) ) ;
F_7 ( 0 , F_29 ( V_4 -> V_6 ) ) ;
V_4 -> V_23 = F_30 ( V_29 , V_31 , 0 ,
& V_32 , V_4 ) ;
F_31 ( F_16 ) ;
return 0 ;
}
