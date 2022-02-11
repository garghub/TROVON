static int F_1 ( int V_1 , unsigned V_2 , unsigned V_3 )
{
int V_4 = V_1 + V_2 ;
int V_5 = 0 ;
if ( V_1 <= 0 ) {
if ( V_4 > 0 )
V_5 = F_2 ( unsigned , V_4 , V_3 ) ;
} else if ( V_1 <= V_3 ) {
V_5 = F_2 ( unsigned , V_3 - V_1 , V_2 ) ;
}
return V_5 ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 , int V_13 ,
unsigned int V_14 , unsigned int V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
struct V_22 * V_23 = & V_9 -> V_24 -> V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
V_26 = F_1 ( V_12 , V_14 , V_23 -> V_28 ) ;
V_27 = F_1 ( V_13 , V_15 , V_23 -> V_29 ) ;
if ( V_12 < 0 ) {
if ( V_26 )
V_16 -= V_12 ;
V_12 = 0 ;
}
if ( V_13 < 0 ) {
if ( V_27 )
V_17 -= V_13 ;
V_13 = 0 ;
}
V_21 -> V_30 = ( V_18 << 16 ) / V_14 ;
V_21 -> V_31 = ( V_19 << 16 ) / V_15 ;
V_21 -> V_16 = V_16 ;
V_21 -> V_17 = V_17 ;
V_21 -> V_32 = ( V_26 * V_21 -> V_30 ) >> 16 ;
V_21 -> V_33 = ( V_27 * V_21 -> V_31 ) >> 16 ;
V_21 -> V_34 = V_11 -> V_35 ;
V_21 -> V_36 = V_11 -> V_37 ;
V_21 -> V_38 = V_11 -> V_39 ;
V_21 -> V_40 = V_11 -> V_41 [ 0 ] ;
V_21 -> V_42 = V_11 -> V_42 ;
V_21 -> V_12 = V_12 ;
V_21 -> V_13 = V_13 ;
V_21 -> V_43 = V_26 ;
V_21 -> V_44 = V_27 ;
V_21 -> V_45 = V_23 -> V_28 ;
V_21 -> V_46 = V_23 -> V_29 ;
V_21 -> V_47 = V_23 -> V_48 ;
V_21 -> V_49 = V_23 -> V_50 ;
F_5 ( L_1 ,
V_21 -> V_12 , V_21 -> V_13 ,
V_21 -> V_43 , V_21 -> V_44 ) ;
V_7 -> V_9 = V_9 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_51 * V_24 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
int V_52 ;
int V_53 ;
if ( ! V_24 -> V_11 )
return 0 ;
V_52 = F_7 ( V_24 -> V_11 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
struct V_54 * V_55 =
F_8 ( V_24 -> V_11 , V_53 ) ;
if ( ! V_55 ) {
F_5 ( L_2 ) ;
return - V_56 ;
}
V_21 -> V_57 [ V_53 ] = V_55 -> V_57 +
V_24 -> V_11 -> V_58 [ V_53 ] ;
F_5 ( L_3 ,
V_53 , ( unsigned long ) V_21 -> V_57 [ V_53 ] ) ;
}
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_51 * V_59 )
{
struct V_51 * V_24 = V_7 -> V_24 ;
struct V_60 * V_61 = F_10 ( V_24 -> V_9 ) ;
struct V_20 * V_21 = F_4 ( V_7 ) ;
if ( ! V_24 -> V_9 )
return;
F_3 ( V_7 , V_24 -> V_9 , V_24 -> V_11 ,
V_24 -> V_12 , V_24 -> V_13 ,
V_24 -> V_14 , V_24 -> V_15 ,
V_24 -> V_16 >> 16 , V_24 -> V_17 >> 16 ,
V_24 -> V_18 >> 16 , V_24 -> V_19 >> 16 ) ;
if ( V_61 -> V_62 -> V_63 )
V_61 -> V_62 -> V_63 ( V_61 , V_21 -> V_64 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
struct V_51 * V_59 )
{
struct V_20 * V_21 = F_4 ( V_7 ) ;
struct V_60 * V_61 = F_10 ( V_59 -> V_9 ) ;
if ( ! V_59 -> V_9 )
return;
if ( V_61 -> V_62 -> V_65 )
V_61 -> V_62 -> V_65 ( V_61 ,
V_21 -> V_64 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
unsigned int V_64 )
{
struct V_66 * V_67 = V_7 -> V_67 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_71 * V_72 ;
V_72 = V_69 -> V_73 ;
if ( ! V_72 ) {
V_72 = F_13 ( V_67 , V_74 ,
L_4 , 0 , V_75 - 1 ) ;
if ( ! V_72 )
return;
V_69 -> V_73 = V_72 ;
}
F_14 ( & V_7 -> V_76 , V_72 , V_64 ) ;
}
int F_15 ( struct V_66 * V_67 ,
struct V_20 * V_21 ,
unsigned long V_77 , enum V_78 type ,
unsigned int V_64 )
{
int V_79 ;
V_79 = F_16 ( V_67 , & V_21 -> V_76 , V_77 ,
& V_80 , V_81 ,
F_17 ( V_81 ) , type ) ;
if ( V_79 ) {
F_18 ( L_5 ) ;
return V_79 ;
}
F_19 ( & V_21 -> V_76 , & V_82 ) ;
V_21 -> V_64 = V_64 ;
if ( type == V_83 )
F_12 ( & V_21 -> V_76 , V_64 ) ;
return 0 ;
}
