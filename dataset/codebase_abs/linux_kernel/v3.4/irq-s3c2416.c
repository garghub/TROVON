static inline void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 ;
unsigned int V_5 ;
V_3 = F_2 ( V_6 ) ;
V_4 = F_2 ( V_7 ) ;
V_3 &= ~ V_4 ;
V_3 >>= ( V_1 - F_3 ( 0 ) ) ;
V_3 &= ( 1 << V_2 ) - 1 ;
V_5 = V_2 + V_1 ;
for (; V_1 < V_5 && V_3 ; V_1 ++ ) {
if ( V_3 & 1 )
F_4 ( V_1 ) ;
V_3 >>= 1 ;
}
}
static void F_5 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_10 , 4 ) ;
}
static void F_6 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_13 , V_14 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_13 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_13 , V_14 ) ;
}
static void F_12 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_15 , 4 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_16 , V_17 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_16 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_16 , V_17 ) ;
}
static void F_16 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_18 , 6 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_19 , V_20 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_19 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_19 , V_20 ) ;
}
static void F_20 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_21 , 3 ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_22 , V_23 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_22 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_22 , V_23 ) ;
}
static int T_1 F_24 ( unsigned int V_24 ,
void (* F_25)( unsigned int ,
struct V_8 * ) ,
struct V_25 * V_26 ,
unsigned int V_27 , unsigned int V_5 )
{
unsigned int V_28 ;
F_26 ( V_24 , & V_29 , V_30 ) ;
F_27 ( V_24 , F_25 ) ;
for ( V_28 = V_27 ; V_28 <= V_5 ; V_28 ++ ) {
F_26 ( V_28 , V_26 , V_30 ) ;
F_28 ( V_28 , V_31 ) ;
}
return 0 ;
}
static int T_1 F_29 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
F_30 ( V_36 L_1 ) ;
F_24 ( V_37 , F_12 , & V_38 ,
V_39 , V_40 ) ;
F_24 ( V_41 , F_16 ,
& V_42 , V_18 , V_43 ) ;
F_24 ( V_44 , F_20 ,
& V_45 ,
V_21 , V_46 ) ;
F_24 ( V_47 , F_5 ,
& V_48 ,
V_10 , V_49 ) ;
return 0 ;
}
static int T_1 F_31 ( void )
{
return F_32 ( & V_50 ) ;
}
