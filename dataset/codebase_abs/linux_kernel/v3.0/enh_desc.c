static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , void T_1 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_12 ) ) {
F_3 ( V_13 L_1 , V_5 -> V_10 . V_11 ) ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_14 ) ) {
F_3 ( V_13 L_2 ) ;
V_3 -> V_15 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_16 ) ) {
F_3 ( V_13 L_3 ) ;
V_3 -> V_17 ++ ;
F_4 ( V_6 ) ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_18 ) ) {
F_3 ( V_13 L_4 ) ;
V_3 -> V_19 ++ ;
V_9 -> V_20 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_21 ) ) {
F_3 ( V_13 L_5 ) ;
V_3 -> V_22 ++ ;
V_9 -> V_20 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_23 ) ) {
F_3 ( V_13 L_6 ) ;
V_9 -> V_24 += V_5 -> V_10 . V_11 . V_25 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_26 ) ) {
F_3 ( V_13 L_7 ) ;
V_9 -> V_24 += V_5 -> V_10 . V_11 . V_25 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_27 ) ) {
F_3 ( V_28 L_8 ) ;
V_3 -> V_29 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_30 ) ) {
F_3 ( V_13 L_9 ) ;
F_4 ( V_6 ) ;
V_3 -> V_31 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_32 ) ) {
F_3 ( V_13 L_10 ) ;
V_3 -> V_33 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_34 ) ) {
F_3 ( V_13 L_11 ) ;
V_3 -> V_35 ++ ;
F_4 ( V_6 ) ;
}
V_7 = - 1 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_36 ) ) {
F_3 ( V_28 L_12 ) ;
V_3 -> V_29 ++ ;
}
#ifdef F_5
if ( V_5 -> V_10 . V_11 . V_37 ) {
F_3 ( V_28 L_13 ) ;
V_3 -> V_38 ++ ;
}
#endif
return V_7 ;
}
static int F_6 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_39 ;
}
static int F_7 ( int V_40 , int type , int V_41 )
{
int V_7 = V_42 ;
T_2 V_43 = ( type << 2 | V_40 << 1 | V_41 ) & 0x7 ;
if ( V_43 == 0x0 ) {
F_3 ( V_28 L_14 ) ;
V_7 = V_44 ;
} else if ( V_43 == 0x4 ) {
F_3 ( V_28 L_15 ) ;
V_7 = V_42 ;
} else if ( V_43 == 0x5 ) {
F_3 ( V_13 L_16 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x6 ) {
F_3 ( V_13 L_17 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x7 ) {
F_3 ( V_13
L_18 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x1 ) {
F_3 ( V_13
L_19 ) ;
V_7 = V_46 ;
} else if ( V_43 == 0x3 ) {
F_3 ( V_13 L_20 ) ;
V_7 = V_46 ;
}
return V_7 ;
}
static int F_8 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_7 = V_42 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_12 ) ) {
F_3 ( V_13 L_21 ,
V_5 -> V_10 . V_47 ) ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_48 ) ) {
F_3 ( V_13 L_22 ) ;
V_3 -> V_49 ++ ;
V_9 -> V_50 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_51 ) ) {
F_3 ( V_13 L_23 ) ;
V_3 -> V_52 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_53 ) )
F_3 ( V_13 L_24 ) ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_23 ) ) {
F_3 ( V_13 L_6 ) ;
V_9 -> V_24 ++ ;
V_9 -> V_24 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_54 ) ) {
F_3 ( V_13 L_25 ) ;
V_3 -> V_55 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_56 ) ) {
F_3 ( V_13 L_26 ) ;
V_3 -> V_57 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_58 ) ) {
F_3 ( V_13 L_27 ) ;
V_3 -> V_59 ++ ;
V_9 -> V_60 ++ ;
}
V_7 = V_46 ;
}
V_7 = F_7 ( V_5 -> V_10 . V_47 . V_53 ,
V_5 -> V_10 . V_47 . V_61 , V_5 -> V_10 . V_47 . V_62 ) ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_63 ) ) {
F_3 ( V_13 L_28 ) ;
V_7 = V_46 ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_64 ) ) {
F_3 ( V_13 L_29 ) ;
V_3 -> V_65 ++ ;
V_7 = V_46 ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_66 ) ) {
F_3 ( V_13 L_30 ) ;
V_3 -> V_67 ++ ;
V_7 = V_46 ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_68 ) ) {
F_3 ( V_13 L_31 ) ;
V_3 -> V_69 ++ ;
V_7 = V_46 ;
}
#ifdef F_5
if ( V_5 -> V_10 . V_47 . V_70 ) {
F_3 ( V_28 L_32 ) ;
V_3 -> V_71 ++ ;
}
#endif
return V_7 ;
}
static void F_9 ( struct V_4 * V_5 , unsigned int V_72 ,
int V_73 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_5 -> V_10 . V_47 . V_75 = 1 ;
V_5 -> V_10 . V_47 . V_39 = V_76 - 1 ;
V_5 -> V_10 . V_47 . V_77 = V_76 - 1 ;
if ( V_74 == V_72 - 1 )
V_5 -> V_10 . V_47 . V_78 = 1 ;
if ( V_73 )
V_5 -> V_10 . V_47 . V_79 = 1 ;
V_5 ++ ;
}
}
static void F_10 ( struct V_4 * V_5 , unsigned int V_72 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_5 -> V_10 . V_11 . V_75 = 0 ;
if ( V_74 == V_72 - 1 )
V_5 -> V_10 . V_11 . V_78 = 1 ;
V_5 ++ ;
}
}
static int F_11 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_75 ;
}
static int F_12 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_47 . V_75 ;
}
static void F_13 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_75 = 1 ;
}
static void F_14 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_47 . V_75 = 1 ;
}
static int F_15 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_80 ;
}
static void F_16 ( struct V_4 * V_5 )
{
int V_81 = V_5 -> V_10 . V_11 . V_78 ;
memset ( V_5 , 0 , F_17 ( struct V_4 , V_82 ) ) ;
V_5 -> V_10 . V_11 . V_78 = V_81 ;
}
static void F_18 ( struct V_4 * V_5 , int V_83 , int V_84 ,
int V_85 )
{
V_5 -> V_10 . V_11 . V_86 = V_83 ;
if ( F_2 ( V_84 > V_87 ) ) {
V_5 -> V_10 . V_11 . V_39 = V_87 ;
V_5 -> V_10 . V_11 . V_77 = V_84 - V_87 ;
} else {
V_5 -> V_10 . V_11 . V_39 = V_84 ;
}
if ( F_19 ( V_85 ) )
V_5 -> V_10 . V_11 . V_88 = V_89 ;
}
static void F_20 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_90 = 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_80 = 1 ;
V_5 -> V_10 . V_11 . V_90 = 1 ;
}
static int F_22 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_47 . V_91 ;
}
