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
V_38 = F_3 ( V_3 , V_4 , V_23 ) ;
return V_38 ;
}
static int F_24 ( struct V_5 * V_4 , int V_41 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
int V_38 = 0 ;
switch ( V_41 ) {
case V_42 :
case V_43 :
case V_44 :
F_25 ( V_3 -> V_39 ) ;
V_38 = F_26 ( V_3 -> V_10 . V_9 ) ;
if ( V_38 )
goto V_45;
F_27 ( V_3 , V_46 , F_28 ( V_47 ) ) ;
break;
case V_48 :
case V_49 :
case V_50 :
F_29 ( V_3 -> V_10 . V_9 ) ;
F_27 ( V_3 , V_51 , 0 ) ;
F_27 ( V_3 , V_46 , 0 ) ;
F_30 ( V_3 -> V_39 ) ;
break;
default:
V_38 = - V_21 ;
break;
}
V_45:
return V_38 ;
}
static T_1
F_31 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_4 ) ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_1 V_52 ;
unsigned long V_53 ;
V_53 = F_32 ( V_3 -> V_10 . V_9 ) ;
V_53 -= V_14 -> V_17 ;
V_52 = F_33 ( V_14 , V_53 ) ;
if ( V_52 >= V_14 -> V_18 )
V_52 -= V_14 -> V_18 ;
return V_52 ;
}
static T_2 F_34 ( int V_54 , void * V_55 )
{
struct V_2 * V_3 = V_55 ;
T_3 V_56 ;
V_56 = F_35 ( V_3 , V_57 ) ;
if ( V_56 & F_28 ( V_58 ) ) {
F_36 ( & V_3 -> V_19 -> V_20 , L_3 ) ;
F_27 ( V_3 , V_59 , F_28 ( V_58 ) ) ;
} else {
F_36 ( & V_3 -> V_19 -> V_20 , L_4 ,
V_56 ) ;
F_27 ( V_3 , V_59 , V_56 ) ;
}
return V_60 ;
}
static int T_4 F_37 ( struct V_2 * V_3 )
{
struct V_61 V_33 = V_28 ;
struct V_62 * V_63 ;
int V_38 ;
V_38 = F_38 ( V_3 -> V_64 , V_3 -> V_64 -> V_65 ,
V_3 -> V_19 -> V_66 , 1 , 0 , & V_63 ) ;
if ( V_38 )
return V_38 ;
strcpy ( V_63 -> V_67 , V_3 -> V_64 -> V_65 ) ;
V_63 -> V_68 = V_3 ;
V_63 -> V_69 = 0 ;
V_3 -> V_63 = V_63 ;
F_39 ( V_63 , V_70 , & V_71 ) ;
V_38 = F_40 ( V_63 , V_72 ,
& V_3 -> V_19 -> V_20 , V_33 . V_73 * V_33 . V_74 ,
V_33 . V_75 ) ;
return V_38 ;
}
static bool F_41 ( struct V_8 * V_9 , void * V_76 )
{
struct V_77 * V_78 = V_76 ;
if ( V_78 -> V_79 == V_9 -> V_80 -> V_20 ) {
V_9 -> V_81 = V_78 ;
return true ;
} else
return false ;
}
static int F_42 ( struct V_2 * V_3 )
{
long V_82 = V_83 ;
int V_38 = - V_21 ;
int V_84 = 0 ;
while ( V_82 >= V_85 && V_84 < ( V_86 + 1 ) ) {
V_82 = F_43 ( V_3 -> V_39 , 256 * V_82 ) ;
if ( V_82 < 0 )
break;
if ( V_82 <= F_44 ( V_3 -> V_87 ) ) {
V_3 -> V_30 [ V_84 ] = V_82 / 256 ;
V_84 ++ ;
}
V_82 /= 256 * 2 ;
}
if ( V_84 ) {
int V_88 ;
for ( V_88 = 0 ; V_88 < ( V_84 / 2 ) ; V_88 ++ ) {
unsigned int V_89 = V_3 -> V_30 [ V_84 - 1 - V_88 ] ;
V_3 -> V_30 [ V_84 - 1 - V_88 ] = V_3 -> V_30 [ V_88 ] ;
V_3 -> V_30 [ V_88 ] = V_89 ;
}
V_3 -> V_35 . V_90 = V_84 ;
V_3 -> V_35 . V_91 = V_3 -> V_30 ;
V_3 -> V_35 . V_92 = 0 ;
V_3 -> V_31 = V_84 ;
V_38 = 0 ;
}
return V_38 ;
}
static int T_4 F_45 ( struct V_93 * V_19 )
{
struct V_94 * V_64 ;
struct V_2 * V_3 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_87 ;
struct V_99 * V_39 ;
int V_38 ;
int V_54 ;
V_96 = F_46 ( V_19 , V_100 , 0 ) ;
if ( ! V_96 ) {
F_4 ( & V_19 -> V_20 , L_5 ) ;
return - V_101 ;
}
V_54 = F_47 ( V_19 , 0 ) ;
if ( V_54 < 0 ) {
F_4 ( & V_19 -> V_20 , L_6 ) ;
return V_54 ;
}
V_98 = V_19 -> V_20 . V_102 ;
if ( ! V_98 ) {
F_4 ( & V_19 -> V_20 , L_7 ) ;
return - V_101 ;
}
V_87 = F_48 ( & V_19 -> V_20 , L_8 ) ;
if ( F_7 ( V_87 ) ) {
F_4 ( & V_19 -> V_20 , L_9 ) ;
return F_8 ( V_87 ) ;
}
V_39 = F_48 ( & V_19 -> V_20 , L_10 ) ;
if ( F_7 ( V_39 ) ) {
F_4 ( & V_19 -> V_20 , L_11 ) ;
V_38 = F_8 ( V_39 ) ;
goto V_103;
}
F_25 ( V_87 ) ;
V_38 = F_49 ( V_104 , V_105 ,
V_106 , sizeof( struct V_2 ) , & V_64 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_12 ) ;
goto V_107;
}
V_3 = F_50 ( V_64 ) ;
V_3 -> V_54 = V_54 ;
V_3 -> V_64 = V_64 ;
V_3 -> V_87 = V_87 ;
V_3 -> V_39 = V_39 ;
V_3 -> V_19 = V_19 ;
V_38 = F_42 ( V_3 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_19 -> V_20 , L_13 ) ;
goto V_108;
}
V_3 -> V_96 = F_51 ( V_96 -> V_109 , F_52 ( V_96 ) ) ;
if ( ! V_3 -> V_96 ) {
F_4 ( & V_19 -> V_20 , L_14 ) ;
goto V_108;
}
F_27 ( V_3 , V_51 , 0 ) ;
F_27 ( V_3 , V_46 , 0 ) ;
V_38 = F_53 ( V_54 , F_34 , 0 , L_15 , V_3 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_16 ) ;
goto V_110;
}
F_54 ( V_64 , & V_19 -> V_20 ) ;
if ( V_98 -> V_78 . V_79 ) {
struct V_77 * V_78 = & V_98 -> V_78 ;
T_5 V_92 ;
V_78 -> V_111 = V_96 -> V_109 + V_112 ;
F_55 ( V_92 ) ;
F_56 ( V_113 , V_92 ) ;
V_3 -> V_10 . V_9 = F_57 ( V_92 , F_41 , V_78 ) ;
}
if ( ! V_98 -> V_78 . V_79 || ! V_3 -> V_10 . V_9 ) {
F_4 ( & V_19 -> V_20 , L_17 ) ;
V_38 = - V_114 ;
goto V_115;
}
strcpy ( V_64 -> V_116 , L_18 ) ;
strcpy ( V_64 -> V_65 , L_18 ) ;
sprintf ( V_64 -> V_117 , L_19 ) ;
V_38 = F_37 ( V_3 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_20 ) ;
goto V_118;
}
V_38 = F_58 ( V_64 ) ;
if ( V_38 ) {
F_4 ( & V_19 -> V_20 , L_21 ) ;
goto V_118;
}
F_59 ( V_19 , V_64 ) ;
F_60 ( & V_19 -> V_20 , L_22 ,
V_3 -> V_96 , F_61 ( & V_3 -> V_10 . V_9 -> V_20 -> V_80 ) ) ;
return V_38 ;
V_118:
F_62 ( V_3 -> V_10 . V_9 ) ;
V_3 -> V_10 . V_9 = NULL ;
V_115:
F_54 ( V_64 , NULL ) ;
F_63 ( V_54 , V_3 ) ;
V_110:
F_64 ( V_3 -> V_96 ) ;
V_108:
F_65 ( V_64 ) ;
V_107:
F_66 ( V_39 ) ;
F_30 ( V_87 ) ;
V_103:
F_66 ( V_87 ) ;
return V_38 ;
}
static int F_67 ( struct V_93 * V_19 , T_6 V_119 )
{
struct V_94 * V_64 = F_68 ( V_19 ) ;
struct V_2 * V_3 = V_64 -> V_68 ;
F_29 ( V_3 -> V_10 . V_9 ) ;
F_30 ( V_3 -> V_39 ) ;
F_30 ( V_3 -> V_87 ) ;
return 0 ;
}
static int F_69 ( struct V_93 * V_19 )
{
struct V_94 * V_64 = F_68 ( V_19 ) ;
struct V_2 * V_3 = V_64 -> V_68 ;
F_25 ( V_3 -> V_87 ) ;
F_25 ( V_3 -> V_39 ) ;
if ( F_23 ( V_26 , & V_3 -> V_27 ) )
F_26 ( V_3 -> V_10 . V_9 ) ;
return 0 ;
}
static int T_7 F_70 ( struct V_93 * V_19 )
{
struct V_94 * V_64 = F_68 ( V_19 ) ;
struct V_2 * V_3 = F_50 ( V_64 ) ;
F_66 ( V_3 -> V_39 ) ;
F_30 ( V_3 -> V_87 ) ;
F_66 ( V_3 -> V_87 ) ;
F_62 ( V_3 -> V_10 . V_9 ) ;
V_3 -> V_10 . V_9 = NULL ;
F_54 ( V_64 , NULL ) ;
F_64 ( V_3 -> V_96 ) ;
F_63 ( V_3 -> V_54 , V_3 ) ;
F_65 ( V_64 ) ;
F_59 ( V_19 , NULL ) ;
return 0 ;
}
static int T_8 F_71 ( void )
{
return F_72 ( & V_120 ,
F_45 ) ;
}
static void T_9 F_73 ( void )
{
F_74 ( & V_120 ) ;
}
