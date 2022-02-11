static int F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
int V_5 , V_6 ;
V_6 = V_2 -> V_7 . V_8 ( V_2 -> V_9 , 0x40 , V_4 , & V_2 -> V_10 ) ;
if ( V_6 <= 0 ) {
F_2 ( V_2 -> V_9 , L_1 , V_6 ) ;
return V_6 ;
}
V_2 -> V_7 . V_6 = V_6 ;
memcpy ( V_2 -> V_10 . V_11 , V_3 , V_4 ) ;
F_3 ( V_2 , V_12 ,
V_13 | ( V_14 |
( ( V_6 - 1 ) << V_15 ) ) ) ;
V_5 = F_4 ( V_2 , V_16 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_2 , V_5 ) ;
V_5 = - V_17 ;
goto V_18;
}
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_5 = F_7 ( V_2 , V_19 , V_20 ,
V_21 , V_22 ,
L_3 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_4 , V_5 ) ;
goto V_18;
}
return 0 ;
V_18:
V_2 -> V_7 . V_23 ( V_2 -> V_9 , & V_2 -> V_10 , V_6 ) ;
F_8 ( V_2 , V_16 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_7 . V_24 ( V_2 -> V_9 , true , V_2 -> V_7 . V_6 ) ;
V_5 = F_7 ( V_2 , V_19 , V_20 ,
V_25 , V_26 ,
L_5 ) ;
V_2 -> V_7 . V_24 ( V_2 -> V_9 , false , V_2 -> V_7 . V_6 ) ;
V_2 -> V_7 . V_23 ( V_2 -> V_9 , & V_2 -> V_10 , V_2 -> V_7 . V_6 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
struct V_29 * V_30 = V_2 -> V_31 ;
int V_5 ;
if ( ! V_2 -> V_32 ) {
V_5 = F_11 ( & V_2 -> V_32 , V_2 -> V_33 , V_2 -> V_9 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_6 , V_5 ) ;
goto V_34;
}
}
if ( V_30 -> V_35 ) {
V_5 = F_12 ( V_2 , V_2 -> V_32 ,
V_36 , 0 ) ;
if ( V_5 < 0 )
goto V_34;
}
V_28 . V_37 = V_2 -> V_32 -> V_37 ;
V_28 . V_38 = V_2 -> V_32 -> V_38 ;
F_13 ( & V_28 ) ;
V_5 = F_1 ( V_2 , V_28 . V_37 , V_28 . V_38 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_7 , V_5 ) ;
goto V_34;
}
V_5 = F_9 ( V_2 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_8 , V_5 ) ;
F_8 ( V_2 , V_16 ) ;
goto V_34;
}
V_5 = F_14 ( V_30 -> V_39 , V_30 -> V_40 ,
F_15 ( V_41 ) ) ;
if ( V_5 == 0 ) {
F_2 ( V_2 -> V_9 , L_9 ) ;
F_8 ( V_2 , V_16 ) ;
V_5 = - V_17 ;
goto V_34;
}
V_30 -> V_42 = true ;
return 0 ;
V_34:
F_16 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
unsigned int V_44 = F_18 ( V_43 ) ;
struct V_45 V_46 ;
int V_5 ;
if ( ! V_30 -> V_42 ) {
V_30 -> V_40 = false ;
V_5 = F_10 ( V_2 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_10 , V_5 ) ;
return V_5 ;
}
V_30 -> V_47 . V_48 [ V_43 ] = V_49 ;
return V_5 ;
}
V_5 = F_4 ( V_2 , V_44 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_11 ,
V_43 , V_5 ) ;
goto V_50;
}
if ( V_43 == V_51 ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_30 -> V_40 = false ;
V_5 = F_14 ( V_30 -> V_39 , V_30 -> V_40 ,
F_15 ( V_41 ) ) ;
if ( V_5 == 0 ) {
F_2 ( V_2 -> V_9 ,
L_12 ,
F_19 ( V_2 , V_19 ) ,
F_19 ( V_2 , V_52 ) ) ;
goto V_50;
}
} else {
V_46 . V_44 = V_44 ;
V_46 . V_53 = V_44 ;
V_5 = F_20 ( & V_30 -> V_54 , V_55 ,
V_56 , & V_46 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_13 ,
V_43 , V_5 ) ;
goto V_50;
}
}
V_30 -> V_47 . V_48 [ V_43 ] = V_49 ;
return 0 ;
V_50:
F_8 ( V_2 , V_44 ) ;
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
unsigned int V_44 = F_18 ( V_43 ) ;
struct V_45 V_46 ;
int V_5 ;
V_46 . V_44 = V_44 ;
V_46 . V_53 = V_57 ;
V_5 = F_20 ( & V_30 -> V_54 , V_55 ,
V_56 , & V_46 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 ,
L_14 ,
V_43 ) ;
V_30 -> V_42 = false ;
}
if ( V_43 == V_51 ) {
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
}
V_5 = F_8 ( V_2 , V_44 ) ;
if ( V_5 < 0 ) {
F_2 ( V_2 -> V_9 , L_15 ,
V_43 , V_5 ) ;
return V_5 ;
}
V_30 -> V_47 . V_48 [ V_43 ] = V_58 ;
return V_5 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
return F_19 ( V_2 , V_52 ) ;
}
static T_2 F_25 ( int V_59 , void * V_60 )
{
struct V_1 * V_61 = V_60 ;
struct V_29 * V_30 = F_26 ( V_61 ) ;
struct V_62 * V_54 = & V_30 -> V_54 ;
struct V_63 V_64 = { 0 } ;
T_1 V_65 , V_66 , V_67 ;
int V_68 = 0 ;
if ( ! ( V_61 -> V_69 & V_70 ) )
return V_71 ;
V_65 = F_27 ( V_61 , V_72 ) ;
V_66 = F_27 ( V_61 , V_73 ) ;
if ( V_65 & V_74 ) {
F_28 ( V_61 , V_75 ,
V_76 , 0 ) ;
F_29 ( V_61 , V_72 ,
V_74 , V_74 ) ;
V_68 = 1 ;
F_28 ( V_61 , V_75 ,
V_76 , V_76 ) ;
}
if ( V_66 & V_77 ) {
V_67 = F_27 ( V_61 , V_78 ) ;
V_64 . V_79 = V_66 ;
V_64 . V_80 = V_67 ;
F_30 ( V_61 -> V_9 , L_16 ,
V_64 . V_79 ) ;
F_30 ( V_61 -> V_9 , L_17 ,
V_64 . V_80 ) ;
if ( F_31 ( V_64 . V_79 ) ) {
F_32 ( V_54 , V_64 ) ;
} else {
F_30 ( V_61 -> V_9 , L_18 ) ;
F_33 ( V_54 , V_64 ) ;
}
F_29 ( V_61 , V_73 ,
V_77 , V_77 ) ;
F_29 ( V_61 , V_81 ,
V_82 , V_82 ) ;
V_68 = 1 ;
}
if ( V_68 == 0 )
return V_71 ;
F_5 ( V_61 ) ;
F_34 ( & V_54 -> V_83 ) ;
return V_84 ;
}
static void F_35 ( struct V_62 * V_54 , struct V_85 * V_86 )
{
struct V_63 * V_64 = (struct V_63 * ) ( & V_86 -> V_64 ) ;
if ( V_86 -> V_87 )
F_36 ( V_54 -> V_61 , V_86 -> V_88 , V_86 -> V_87 ) ;
F_37 ( V_54 -> V_61 , V_89 ,
V_64 -> V_80 ) ;
F_37 ( V_54 -> V_61 , V_12 ,
V_64 -> V_79 | V_13 ) ;
}
static bool F_38 ( struct V_1 * V_61 )
{
T_1 V_90 ;
V_90 = F_27 ( V_61 , V_12 ) ;
return ( V_90 & V_13 ) ;
}
static int F_39 ( struct V_91 * V_9 , struct V_29 * V_30 )
{
struct V_62 * V_54 ;
int V_50 ;
V_54 = & V_30 -> V_54 ;
V_54 -> V_61 = V_30 -> V_61 ;
V_54 -> V_9 = V_9 ;
V_54 -> V_92 = V_93 ;
V_54 -> V_94 = V_95 ;
V_50 = F_40 ( V_54 ) ;
if ( V_50 )
return V_50 ;
V_54 -> V_96 . V_97 = F_35 ;
V_54 -> V_96 . V_98 = V_99 ;
V_54 -> V_96 . V_100 = F_38 ;
return 0 ;
}
int F_41 ( struct V_91 * V_9 , void T_3 * V_101 , int V_59 ,
const char * V_33 , struct V_102 V_7 ,
struct V_29 * * V_61 )
{
struct V_29 * V_30 ;
struct V_1 * V_103 ;
int V_5 ;
V_5 = F_42 ( V_9 , V_59 , V_33 , V_7 , V_61 , & V_104 ) ;
if ( V_5 < 0 ) {
F_2 ( V_9 , L_19 , V_105 ) ;
return V_5 ;
}
V_30 = * V_61 ;
V_103 = V_30 -> V_61 ;
V_103 -> V_106 = V_107 ;
V_103 -> V_108 . V_109 = V_101 ;
V_103 -> V_108 . V_110 = V_101 ;
V_103 -> V_108 . V_111 = V_112 ;
V_103 -> V_108 . V_113 = V_114 ;
V_103 -> V_108 . V_115 = V_116 ;
V_103 -> V_108 . V_117 = V_95 ;
F_43 ( V_103 , ( V_112 + V_116 ) ,
V_95 , V_114 ,
V_93 ) ;
V_5 = F_39 ( V_9 , V_30 ) ;
if ( V_5 ) {
F_44 ( V_103 ) ;
return V_5 ;
}
V_30 -> V_40 = false ;
F_45 ( & V_30 -> V_39 ) ;
return 0 ;
}
int F_46 ( struct V_91 * V_9 , struct V_29 * V_2 )
{
int V_5 ;
struct V_1 * V_103 = V_2 -> V_61 ;
V_5 = V_2 -> V_61 -> V_106 . V_118 ( V_103 ) ;
if ( V_5 < 0 ) {
F_2 ( V_9 , L_20 , V_5 ) ;
return V_5 ;
}
F_47 ( V_103 ) ;
V_2 -> V_35 = false ;
return 0 ;
}
void F_48 ( struct V_91 * V_9 , struct V_29 * V_2 )
{
if ( V_2 -> V_61 -> V_32 )
F_16 ( V_2 -> V_61 -> V_32 ) ;
F_49 ( V_2 ) ;
F_50 ( & V_2 -> V_54 ) ;
V_2 -> V_61 -> V_96 -> free ( V_2 -> V_61 ) ;
}
