static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_5 * V_4 ,
enum V_6 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 . V_9 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_4 -> V_14 ;
unsigned long V_15 , V_16 ;
if ( V_14 -> V_17 & 1 || V_14 -> V_18 & 1 ) {
F_4 ( & V_3 -> V_19 -> V_20 , L_1 ) ;
return - V_21 ;
}
V_15 = F_5 ( V_14 , V_14 -> V_18 ) ;
V_16 = F_5 ( V_14 , V_14 -> V_22 ) ;
V_12 = F_6 ( V_9 , V_14 -> V_17 , V_15 ,
V_16 , V_23 ) ;
if ( F_7 ( V_12 ) ) {
F_4 ( & V_3 -> V_19 -> V_20 , L_2 ) ;
return F_8 ( V_12 ) ;
}
V_12 -> V_24 = F_1 ;
V_12 -> V_25 = V_3 ;
V_3 -> V_10 . V_12 = V_12 ;
F_9 ( V_26 , & V_3 -> V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
V_3 -> V_4 = V_4 ;
V_28 . V_29 = V_3 -> V_30 [ V_3 -> V_31 - 1 ] ;
V_28 . V_32 = V_3 -> V_30 [ 0 ] ;
V_4 -> V_14 -> V_33 = V_28 ;
return F_12 ( V_4 -> V_14 , 0 ,
V_34 , & V_3 -> V_35 ) ;
}
static int F_13 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
V_3 -> V_4 = NULL ;
return 0 ;
}
static int F_14 ( struct V_5 * V_4 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
int V_38 ;
V_38 = F_15 ( V_4 ,
F_16 ( V_37 ) ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 1 )
if ( F_17 ( V_26 , & V_3 -> V_27 ) )
F_18 ( V_3 -> V_10 . V_9 ) ;
return V_38 ;
}
static int F_19 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
if ( F_17 ( V_26 , & V_3 -> V_27 ) )
F_18 ( V_3 -> V_10 . V_9 ) ;
return F_20 ( V_4 ) ;
}
static int F_21 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
int V_38 ;
V_38 = F_22 ( V_3 -> V_39 , 256 * V_4 -> V_14 -> V_40 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_23 ( V_26 , & V_3 -> V_27 ) )
V_38 = F_3 ( V_3 , V_4 , V_41 ) ;
return V_38 ;
}
static int F_24 ( struct V_5 * V_4 , int V_42 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
int V_38 = 0 ;
switch ( V_42 ) {
case V_43 :
case V_44 :
case V_45 :
F_25 ( V_3 -> V_39 ) ;
V_38 = F_26 ( V_3 -> V_10 . V_9 ) ;
if ( V_38 )
goto V_46;
F_27 ( V_3 , V_47 , F_28 ( V_48 ) ) ;
break;
case V_49 :
case V_50 :
case V_51 :
F_29 ( V_3 -> V_10 . V_9 ) ;
F_27 ( V_3 , V_52 , 0 ) ;
F_27 ( V_3 , V_47 , 0 ) ;
F_30 ( V_3 -> V_39 ) ;
break;
default:
V_38 = - V_21 ;
break;
}
V_46:
return V_38 ;
}
static T_1
F_31 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_1 V_53 ;
unsigned long V_54 ;
V_54 = F_32 ( V_3 -> V_10 . V_9 ) ;
V_54 -= V_14 -> V_17 ;
V_53 = F_33 ( V_14 , V_54 ) ;
if ( V_53 >= V_14 -> V_18 )
V_53 -= V_14 -> V_18 ;
return V_53 ;
}
static T_2 F_34 ( int V_55 , void * V_56 )
{
struct V_2 * V_3 = V_56 ;
T_3 V_57 ;
V_57 = F_35 ( V_3 , V_58 ) ;
if ( V_57 & F_28 ( V_59 ) ) {
F_36 ( & V_3 -> V_19 -> V_20 , L_3 ) ;
F_27 ( V_3 , V_60 , F_28 ( V_59 ) ) ;
} else {
F_36 ( & V_3 -> V_19 -> V_20 , L_4 ,
V_57 ) ;
F_27 ( V_3 , V_60 , V_57 ) ;
}
return V_61 ;
}
static int T_4 F_37 ( struct V_2 * V_3 )
{
struct V_62 V_33 = V_28 ;
struct V_63 * V_64 ;
int V_38 ;
V_38 = F_38 ( V_3 -> V_65 , V_3 -> V_65 -> V_66 ,
V_3 -> V_19 -> V_67 , 1 , 0 , & V_64 ) ;
if ( V_38 )
return V_38 ;
strcpy ( V_64 -> V_68 , V_3 -> V_65 -> V_66 ) ;
V_64 -> V_69 = V_3 ;
V_64 -> V_70 = 0 ;
V_3 -> V_64 = V_64 ;
F_39 ( V_64 , V_71 , & V_72 ) ;
V_38 = F_40 ( V_64 , V_73 ,
& V_3 -> V_19 -> V_20 , V_33 . V_74 * V_33 . V_75 ,
V_33 . V_76 ) ;
return V_38 ;
}
static bool F_41 ( struct V_8 * V_9 , void * V_77 )
{
struct V_78 * V_79 = V_77 ;
if ( V_79 -> V_80 == V_9 -> V_81 -> V_20 ) {
V_9 -> V_82 = V_79 ;
return true ;
} else
return false ;
}
static int F_42 ( struct V_2 * V_3 )
{
long V_83 = V_84 ;
int V_38 = - V_21 ;
int V_85 = 0 ;
while ( V_83 >= V_86 && V_85 < ( V_87 + 1 ) ) {
V_83 = F_43 ( V_3 -> V_39 , 256 * V_83 ) ;
if ( V_83 < 0 )
break;
if ( V_83 <= F_44 ( V_3 -> V_88 ) ) {
V_3 -> V_30 [ V_85 ] = V_83 / 256 ;
V_85 ++ ;
}
V_83 /= 256 * 2 ;
}
if ( V_85 ) {
int V_89 ;
for ( V_89 = 0 ; V_89 < ( V_85 / 2 ) ; V_89 ++ ) {
unsigned int V_90 = V_3 -> V_30 [ V_85 - 1 - V_89 ] ;
V_3 -> V_30 [ V_85 - 1 - V_89 ] = V_3 -> V_30 [ V_89 ] ;
V_3 -> V_30 [ V_89 ] = V_90 ;
}
V_3 -> V_35 . V_91 = V_85 ;
V_3 -> V_35 . V_92 = V_3 -> V_30 ;
V_3 -> V_35 . V_93 = 0 ;
V_3 -> V_31 = V_85 ;
V_38 = 0 ;
}
return V_38 ;
}
static int T_4 F_45 ( struct V_94 * V_19 )
{
struct V_95 * V_65 ;
struct V_2 * V_3 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_88 ;
struct V_100 * V_39 ;
int V_38 ;
int V_55 ;
V_97 = F_46 ( V_19 , V_101 , 0 ) ;
if ( ! V_97 ) {
F_4 ( & V_19 -> V_20 , L_5 ) ;
return - V_102 ;
}
V_55 = F_47 ( V_19 , 0 ) ;
if ( V_55 < 0 ) {
F_4 ( & V_19 -> V_20 , L_6 ) ;
return V_55 ;
}
V_99 = V_19 -> V_20 . V_103 ;
if ( ! V_99 ) {
F_4 ( & V_19 -> V_20 , L_7 ) ;
return - V_102 ;
}
V_88 = F_48 ( & V_19 -> V_20 , L_8 ) ;
if ( F_7 ( V_88 ) ) {
F_4 ( & V_19 -> V_20 , L_9 ) ;
return F_8 ( V_88 ) ;
}
V_39 = F_48 ( & V_19 -> V_20 , L_10 ) ;
if ( F_7 ( V_39 ) ) {
F_4 ( & V_19 -> V_20 , L_11 ) ;
V_38 = F_8 ( V_39 ) ;
goto V_104;
}
F_25 ( V_88 ) ;
V_38 = F_49 ( V_105 , V_106 ,
V_107 , sizeof( struct V_2 ) , & V_65 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_12 ) ;
goto V_108;
}
V_3 = F_50 ( V_65 ) ;
V_3 -> V_55 = V_55 ;
V_3 -> V_65 = V_65 ;
V_3 -> V_88 = V_88 ;
V_3 -> V_39 = V_39 ;
V_3 -> V_19 = V_19 ;
V_38 = F_42 ( V_3 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_19 -> V_20 , L_13 ) ;
goto V_109;
}
V_3 -> V_97 = F_51 ( V_97 -> V_110 , F_52 ( V_97 ) ) ;
if ( ! V_3 -> V_97 ) {
F_4 ( & V_19 -> V_20 , L_14 ) ;
goto V_109;
}
F_27 ( V_3 , V_52 , 0 ) ;
F_27 ( V_3 , V_47 , 0 ) ;
V_38 = F_53 ( V_55 , F_34 , 0 , L_15 , V_3 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_16 ) ;
goto V_111;
}
F_54 ( V_65 , & V_19 -> V_20 ) ;
if ( V_99 -> V_79 . V_80 ) {
T_5 V_93 ;
F_55 ( V_93 ) ;
F_56 ( V_112 , V_93 ) ;
V_3 -> V_10 . V_9 = F_57 ( V_93 , F_41 , & V_99 -> V_79 ) ;
if ( V_3 -> V_10 . V_9 ) {
struct V_113 V_114 = {
. V_115 = V_97 -> V_110 + V_116 ,
. V_117 = V_118 ,
. V_119 = 1 ,
. V_120 = 1 ,
. V_7 = V_23 ,
. V_121 = false ,
} ;
F_58 ( V_3 -> V_10 . V_9 , & V_114 ) ;
}
}
if ( ! V_99 -> V_79 . V_80 || ! V_3 -> V_10 . V_9 ) {
F_4 ( & V_19 -> V_20 , L_17 ) ;
V_38 = - V_122 ;
goto V_123;
}
strcpy ( V_65 -> V_124 , L_18 ) ;
strcpy ( V_65 -> V_66 , L_18 ) ;
sprintf ( V_65 -> V_125 , L_19 ) ;
V_38 = F_37 ( V_3 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_20 ) ;
goto V_126;
}
V_38 = F_59 ( V_65 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_21 ) ;
goto V_126;
}
F_60 ( V_19 , V_65 ) ;
F_61 ( & V_19 -> V_20 , L_22 ,
V_3 -> V_97 , F_62 ( & V_3 -> V_10 . V_9 -> V_20 -> V_81 ) ) ;
return V_38 ;
V_126:
F_63 ( V_3 -> V_10 . V_9 ) ;
V_3 -> V_10 . V_9 = NULL ;
V_123:
F_54 ( V_65 , NULL ) ;
F_64 ( V_55 , V_3 ) ;
V_111:
F_65 ( V_3 -> V_97 ) ;
V_109:
F_66 ( V_65 ) ;
V_108:
F_67 ( V_39 ) ;
F_30 ( V_88 ) ;
V_104:
F_67 ( V_88 ) ;
return V_38 ;
}
static int F_68 ( struct V_94 * V_19 , T_6 V_127 )
{
struct V_95 * V_65 = F_69 ( V_19 ) ;
struct V_2 * V_3 = V_65 -> V_69 ;
F_29 ( V_3 -> V_10 . V_9 ) ;
F_30 ( V_3 -> V_39 ) ;
F_30 ( V_3 -> V_88 ) ;
return 0 ;
}
static int F_70 ( struct V_94 * V_19 )
{
struct V_95 * V_65 = F_69 ( V_19 ) ;
struct V_2 * V_3 = V_65 -> V_69 ;
F_25 ( V_3 -> V_88 ) ;
F_25 ( V_3 -> V_39 ) ;
if ( F_23 ( V_26 , & V_3 -> V_27 ) )
F_26 ( V_3 -> V_10 . V_9 ) ;
return 0 ;
}
static int T_7 F_71 ( struct V_94 * V_19 )
{
struct V_95 * V_65 = F_69 ( V_19 ) ;
struct V_2 * V_3 = F_50 ( V_65 ) ;
F_67 ( V_3 -> V_39 ) ;
F_30 ( V_3 -> V_88 ) ;
F_67 ( V_3 -> V_88 ) ;
F_63 ( V_3 -> V_10 . V_9 ) ;
V_3 -> V_10 . V_9 = NULL ;
F_54 ( V_65 , NULL ) ;
F_65 ( V_3 -> V_97 ) ;
F_64 ( V_3 -> V_55 , V_3 ) ;
F_66 ( V_65 ) ;
F_60 ( V_19 , NULL ) ;
return 0 ;
}
static int T_8 F_72 ( void )
{
return F_73 ( & V_128 ,
F_45 ) ;
}
static void T_9 F_74 ( void )
{
F_75 ( & V_128 ) ;
}
