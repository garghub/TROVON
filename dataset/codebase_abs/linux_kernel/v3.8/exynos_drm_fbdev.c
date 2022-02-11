static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_14 ;
int V_15 ;
F_3 ( L_1 , V_16 ) ;
V_4 -> V_17 |= V_18 | V_19 | V_20 ;
V_14 = V_4 -> V_21 - V_4 -> V_22 ;
if ( V_14 > V_13 -> V_23 )
return - V_24 ;
V_15 = F_4 ( V_6 -> V_25 -> V_25 , V_4 , V_13 -> V_26 ,
V_13 -> V_27 , V_13 -> V_23 , & V_13 -> V_28 ) ;
if ( V_15 < 0 ) {
F_5 ( L_2 ) ;
return V_15 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_1 * V_31 = V_6 -> V_32 ;
struct V_33 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 ;
unsigned int V_23 = V_30 -> V_34 * V_30 -> V_35 * ( V_30 -> V_36 >> 3 ) ;
unsigned long V_37 ;
F_3 ( L_1 , __FILE__ ) ;
F_7 ( V_31 , V_30 -> V_38 [ 0 ] , V_30 -> V_39 ) ;
F_8 ( V_31 , V_6 , V_30 -> V_34 , V_30 -> V_35 ) ;
V_13 = F_9 ( V_30 , 0 ) ;
if ( ! V_13 ) {
F_10 ( L_3 ) ;
return - V_40 ;
}
if ( ! V_13 -> V_41 ) {
if ( F_11 ( V_25 ) ) {
unsigned int V_42 = V_13 -> V_23 >> V_43 ;
V_13 -> V_41 = F_12 ( V_13 -> V_26 , V_42 , V_44 ,
F_13 ( V_45 ) ) ;
} else {
T_1 V_27 = V_13 -> V_27 ;
if ( V_27 )
V_13 -> V_41 = F_14 ( V_27 ) ;
else
V_13 -> V_41 = ( void V_46 * ) NULL ;
}
if ( ! V_13 -> V_41 ) {
F_5 ( L_4 ) ;
return - V_47 ;
}
}
F_15 ( V_30 , 1 ) ;
V_37 = V_31 -> V_48 . V_49 * ( V_30 -> V_36 >> 3 ) ;
V_37 += V_31 -> V_48 . V_50 * V_30 -> V_38 [ 0 ] ;
V_25 -> V_51 . V_52 = ( V_53 ) V_13 -> V_27 ;
V_31 -> V_54 = V_13 -> V_41 + V_37 ;
if ( F_11 ( V_25 ) )
V_31 -> V_55 . V_56 = ( unsigned long )
( F_16 ( F_17 ( V_13 -> V_57 -> V_58 ) ) + V_37 ) ;
else
V_31 -> V_55 . V_56 = ( unsigned long ) V_13 -> V_27 ;
V_31 -> V_59 = V_23 ;
V_31 -> V_55 . V_60 = V_23 ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
struct V_8 * V_63 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_33 * V_25 = V_6 -> V_25 ;
struct V_1 * V_31 ;
struct V_64 V_65 = { 0 } ;
struct V_66 * V_67 = V_25 -> V_68 ;
unsigned long V_23 ;
int V_15 ;
F_3 ( L_1 , __FILE__ ) ;
F_3 ( L_5 ,
V_62 -> V_69 , V_62 -> V_70 ,
V_62 -> V_71 ) ;
V_65 . V_34 = V_62 -> V_69 ;
V_65 . V_35 = V_62 -> V_70 ;
V_65 . V_38 [ 0 ] = V_62 -> V_69 * ( V_62 -> V_71 >> 3 ) ;
V_65 . V_72 = F_19 ( V_62 -> V_71 ,
V_62 -> V_73 ) ;
F_20 ( & V_25 -> V_74 ) ;
V_31 = F_21 ( 0 , & V_67 -> V_25 ) ;
if ( ! V_31 ) {
F_5 ( L_6 ) ;
V_15 = - V_75 ;
goto V_76;
}
V_23 = V_65 . V_38 [ 0 ] * V_65 . V_35 ;
V_11 = F_22 ( V_25 , 0 , V_23 ) ;
if ( F_23 ( V_11 ) ) {
V_15 = F_24 ( V_11 ) ;
goto V_77;
}
V_63 -> V_11 = V_11 ;
V_6 -> V_30 = F_25 ( V_25 , & V_65 ,
& V_11 -> V_78 ) ;
if ( F_26 ( V_6 -> V_30 ) ) {
F_5 ( L_7 ) ;
V_15 = F_24 ( V_6 -> V_30 ) ;
goto V_79;
}
V_6 -> V_32 = V_31 ;
V_31 -> V_7 = V_6 ;
V_31 -> V_80 = V_81 ;
V_31 -> V_82 = & V_83 ;
V_15 = F_27 ( & V_31 -> V_84 , 256 , 0 ) ;
if ( V_15 ) {
F_5 ( L_8 ) ;
goto V_85;
}
V_15 = F_6 ( V_6 , V_6 -> V_30 ) ;
if ( V_15 < 0 )
goto V_86;
F_28 ( & V_25 -> V_74 ) ;
return V_15 ;
V_86:
F_29 ( & V_31 -> V_84 ) ;
V_85:
F_30 ( V_6 -> V_30 ) ;
V_79:
F_31 ( V_11 ) ;
V_77:
F_32 ( V_31 ) ;
V_76:
F_28 ( & V_25 -> V_74 ) ;
return V_15 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
int V_15 = 0 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_6 -> V_30 ) {
V_15 = F_18 ( V_6 , V_62 ) ;
if ( V_15 < 0 ) {
F_5 ( L_9 ) ;
return V_15 ;
}
V_15 = 1 ;
}
return V_15 ;
}
int F_34 ( struct V_33 * V_25 )
{
struct V_8 * V_32 ;
struct V_87 * V_88 = V_25 -> V_89 ;
struct V_5 * V_6 ;
unsigned int V_90 ;
int V_15 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_25 -> V_51 . V_90 || ! V_25 -> V_51 . V_91 )
return 0 ;
V_32 = F_35 ( sizeof( * V_32 ) , V_92 ) ;
if ( ! V_32 ) {
F_5 ( L_10 ) ;
return - V_75 ;
}
V_88 -> V_93 = V_6 = & V_32 -> V_5 ;
V_6 -> V_94 = & V_95 ;
V_90 = V_25 -> V_51 . V_90 ;
V_15 = F_36 ( V_25 , V_6 , V_90 , V_96 ) ;
if ( V_15 < 0 ) {
F_5 ( L_11 ) ;
goto V_97;
}
V_15 = F_37 ( V_6 ) ;
if ( V_15 < 0 ) {
F_5 ( L_12 ) ;
goto V_98;
}
V_15 = F_38 ( V_6 , V_99 ) ;
if ( V_15 < 0 ) {
F_5 ( L_13 ) ;
goto V_98;
}
return 0 ;
V_98:
F_39 ( V_6 ) ;
V_97:
V_88 -> V_93 = NULL ;
F_40 ( V_32 ) ;
return V_15 ;
}
static void F_41 ( struct V_33 * V_25 ,
struct V_5 * V_93 )
{
struct V_8 * V_9 = F_2 ( V_93 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_29 * V_30 ;
if ( F_11 ( V_25 ) && V_11 -> V_13 -> V_41 )
F_42 ( V_11 -> V_13 -> V_41 ) ;
if ( V_93 -> V_30 && V_93 -> V_30 -> V_94 ) {
V_30 = V_93 -> V_30 ;
if ( V_30 )
F_43 ( V_30 ) ;
}
if ( V_93 -> V_32 ) {
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_93 -> V_32 ;
V_15 = F_44 ( V_2 ) ;
if ( V_15 < 0 )
F_3 ( L_14 ) ;
if ( V_2 -> V_84 . V_100 )
F_29 ( & V_2 -> V_84 ) ;
F_32 ( V_2 ) ;
}
F_39 ( V_93 ) ;
}
void F_45 ( struct V_33 * V_25 )
{
struct V_87 * V_88 = V_25 -> V_89 ;
struct V_8 * V_32 ;
if ( ! V_88 || ! V_88 -> V_93 )
return;
V_32 = F_2 ( V_88 -> V_93 ) ;
if ( V_32 -> V_11 )
F_31 ( V_32 -> V_11 ) ;
F_41 ( V_25 , V_88 -> V_93 ) ;
F_40 ( V_32 ) ;
V_88 -> V_93 = NULL ;
}
void F_46 ( struct V_33 * V_25 )
{
struct V_87 * V_88 = V_25 -> V_89 ;
if ( ! V_88 || ! V_88 -> V_93 )
return;
F_47 ( V_88 -> V_93 ) ;
}
