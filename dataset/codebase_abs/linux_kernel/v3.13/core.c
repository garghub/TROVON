char * F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return L_1 ;
return V_2 -> V_3 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_7 * V_3 ,
int V_8 )
{
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_3 = V_3 ;
F_3 ( & V_2 -> V_9 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 1 ;
F_5 ( & V_11 -> V_13 ) ;
}
void F_6 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 2 ;
F_5 ( & V_11 -> V_13 ) ;
}
void F_7 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 0 ;
F_8 ( & V_11 -> V_13 ) ;
F_9 ( V_11 -> V_14 ) ;
}
static void F_10 ( void * V_15 )
{
struct V_10 * V_11 = (struct V_10 * ) V_15 ;
struct V_5 * V_6 = V_11 -> V_6 ;
unsigned long V_16 ;
F_11 ( V_6 , V_16 ) ;
V_11 -> V_17 ( V_11 ) ;
if ( V_11 -> V_12 )
F_4 ( V_11 ) ;
F_12 ( V_6 , V_16 ) ;
}
static void F_13 ( struct V_18 * V_13 )
{
struct V_10 * V_11 = F_14 ( V_13 , struct V_10 , V_13 ) ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_19 * V_20 = F_15 ( V_6 ) ;
struct V_21 * V_22 ;
T_1 V_23 ;
T_2 V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_11 -> V_12 ; V_25 ++ ) {
if ( V_11 -> V_26 ( V_11 , & V_23 , & V_24 ) < 0 )
return;
V_22 = F_16 (
V_11 -> V_14 , V_23 , V_24 , V_11 -> V_27 ,
V_28 | V_29 ) ;
if ( ! V_22 ) {
F_17 ( V_20 , L_2 ) ;
return;
}
V_22 -> V_30 = F_10 ;
V_22 -> V_31 = V_11 ;
if ( F_18 ( V_22 ) < 0 ) {
F_17 ( V_20 , L_3 ) ;
return;
}
F_19 ( V_11 -> V_14 ) ;
}
}
int F_20 ( struct V_10 * V_11 )
{
return ! ! V_11 -> V_14 ;
}
int F_21 ( struct V_5 * V_6 , struct V_10 * V_11 ,
int V_32 , int V_8 ,
int (* V_26)( struct V_10 * V_11 ,
T_1 * V_23 , int * V_24 ) ,
int (* V_17)( struct V_10 * V_11 ) )
{
struct V_19 * V_20 = F_15 ( V_6 ) ;
struct V_33 V_34 ;
T_3 V_35 ;
int V_36 ;
if ( V_11 -> V_14 ) {
F_17 ( V_20 , L_4 ) ;
return - V_37 ;
}
F_22 ( V_35 ) ;
F_23 ( V_38 , V_35 ) ;
V_11 -> V_14 = F_24 ( V_35 , V_39 ,
( void * ) V_8 , V_20 ,
V_32 ? L_5 : L_6 ) ;
if ( ! V_11 -> V_14 ) {
F_17 ( V_20 , L_7 ) ;
return - V_37 ;
}
V_34 . V_40 = V_8 ;
V_34 . V_41 = 0 ;
V_34 . V_42 = 0 ;
V_34 . V_43 = V_32 ? V_44 : V_45 ;
V_36 = F_25 ( V_11 -> V_14 , & V_34 ) ;
if ( V_36 < 0 )
goto V_46;
V_11 -> V_27 = V_32 ? V_47 : V_48 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_26 = V_26 ;
V_11 -> V_17 = V_17 ;
F_26 ( & V_11 -> V_13 , F_13 ) ;
return 0 ;
V_46:
F_27 ( V_6 , V_11 ) ;
return V_36 ;
}
void F_27 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_14 )
F_28 ( V_11 -> V_14 ) ;
V_11 -> V_14 = NULL ;
}
int F_29 ( struct V_49 * V_50 ,
struct V_1 * V_2 ,
struct V_51 * V_52 )
{
if ( ! V_2 )
return - V_37 ;
if ( ! F_30 ( & V_2 -> V_9 ) ) {
struct V_5 * V_6 = F_31 ( V_2 ) ;
struct V_19 * V_20 = F_15 ( V_6 ) ;
F_17 ( V_20 , L_8 ,
F_1 ( V_2 ) ,
F_32 ( V_2 ) ) ;
return - V_37 ;
}
F_33 ( & V_2 -> V_9 , & V_52 -> V_53 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_9 ) ;
return 0 ;
}
int F_36 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
int V_8 = V_50 - V_6 -> V_50 ;
if ( ( V_8 < 0 ) || ( V_8 >= F_37 ( V_6 ) ) )
return - V_54 ;
return V_8 ;
}
struct V_49 * F_38 ( struct V_5 * V_6 , int V_8 )
{
if ( ( V_8 < 0 ) || ( V_8 >= F_37 ( V_6 ) ) )
return NULL ;
return V_6 -> V_50 + V_8 ;
}
static struct V_49 * F_39 ( struct V_55 * V_56 )
{
struct V_5 * V_6 = F_40 ( V_56 ) ;
return F_38 ( V_6 , V_56 -> V_8 ) ;
}
int F_41 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
return & V_50 -> V_57 == V_52 ;
}
int F_42 ( struct V_51 * V_52 , int V_58 )
{
struct V_59 * V_60 = V_52 -> V_60 ;
struct V_61 * V_62 = V_60 -> V_62 ;
int V_63 = V_52 -> V_64 + V_58 ;
V_63 %= ( V_62 -> V_65 * V_52 -> V_66 ) ;
return V_63 ;
}
void F_43 ( struct V_51 * V_52 , int V_67 )
{
V_52 -> V_64 += V_67 ;
if ( V_52 -> V_64 >= V_52 -> V_68 ) {
struct V_59 * V_60 = V_52 -> V_60 ;
struct V_61 * V_62 = V_60 -> V_62 ;
V_52 -> V_69 ++ ;
V_52 -> V_68 += V_52 -> V_66 ;
if ( V_52 -> V_69 >= V_62 -> V_65 ) {
V_52 -> V_64 = 0 ;
V_52 -> V_69 = 0 ;
V_52 -> V_68 = V_52 -> V_66 ;
}
F_44 ( V_60 ) ;
}
}
static int F_45 ( struct V_51 * V_52 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_62 ;
if ( ! F_30 ( & V_52 -> V_53 ) )
return - V_37 ;
F_3 ( & V_52 -> V_53 ) ;
V_52 -> V_60 = V_60 ;
V_52 -> V_64 = 0 ;
V_52 -> V_69 = 0 ;
V_52 -> V_66 = V_62 -> V_70 *
V_62 -> V_71 *
F_46 ( V_62 , 1 ) ;
V_52 -> V_68 = V_52 -> V_66 ;
return 0 ;
}
static
struct V_55 * F_47 ( struct V_59 * V_60 )
{
struct V_72 * V_73 = V_60 -> V_74 ;
return V_73 -> V_75 ;
}
static
struct V_51 * F_48 ( struct V_49 * V_50 ,
struct V_59 * V_60 )
{
if ( V_60 -> V_76 == V_77 )
return & V_50 -> V_57 ;
else
return & V_50 -> V_78 ;
}
static int F_49 ( struct V_59 * V_60 , int V_79 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = F_40 ( V_56 ) ;
struct V_49 * V_50 = F_39 ( V_56 ) ;
struct V_51 * V_52 = F_48 ( V_50 , V_60 ) ;
struct V_1 * V_2 = F_50 ( V_6 ,
F_36 ( V_6 , V_50 ) ,
F_41 ( V_50 , V_52 ) ) ;
int V_80 = F_32 ( V_2 ) ;
int V_36 ;
unsigned long V_16 ;
F_11 ( V_6 , V_16 ) ;
switch ( V_79 ) {
case V_81 :
V_36 = F_45 ( V_52 , V_60 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_51 ( V_6 , V_56 , V_83 , V_80 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_52 ( V_6 , V_50 , V_52 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_53 ( V_50 , V_52 , V_84 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_53 ( V_50 , V_52 , V_83 ) ;
if ( V_36 < 0 )
goto V_82;
break;
case V_85 :
V_36 = F_53 ( V_50 , V_52 , V_86 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_53 ( V_50 , V_52 , V_87 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_54 ( V_6 , V_50 , V_52 ) ;
if ( V_36 < 0 )
goto V_82;
V_36 = F_51 ( V_6 , V_56 , V_86 , V_80 ) ;
if ( V_36 < 0 )
goto V_82;
break;
default:
V_36 = - V_54 ;
}
V_82:
F_12 ( V_6 , V_16 ) ;
return V_36 ;
}
static int F_55 ( struct V_55 * V_56 , unsigned int V_88 )
{
struct V_49 * V_50 = F_39 ( V_56 ) ;
switch ( V_88 & V_89 ) {
case V_90 :
V_50 -> V_91 = 1 ;
break;
case V_92 :
V_50 -> V_91 = 0 ;
break;
default:
return - V_54 ;
}
switch ( V_88 & V_93 ) {
case V_94 :
V_50 -> V_95 = 0 ;
V_50 -> V_96 = 1 ;
break;
case V_97 :
V_50 -> V_95 = 1 ;
V_50 -> V_96 = 0 ;
break;
case V_98 :
V_50 -> V_95 = 1 ;
V_50 -> V_96 = 1 ;
break;
case V_99 :
default:
V_50 -> V_95 = 0 ;
V_50 -> V_96 = 0 ;
break;
}
switch ( V_88 & V_100 ) {
case V_101 :
V_50 -> V_102 = 0 ;
V_50 -> V_103 = 0 ;
break;
case V_104 :
V_50 -> V_102 = 1 ;
V_50 -> V_103 = 0 ;
break;
case V_105 :
V_50 -> V_102 = 1 ;
V_50 -> V_103 = 1 ;
break;
}
return 0 ;
}
static int F_56 ( struct V_106 * V_107 ,
struct V_108 * V_109 ,
struct V_5 * V_6 )
{
struct V_110 * V_111 ;
struct V_49 * V_50 ;
struct V_1 * V_112 , * V_113 ;
struct V_19 * V_20 = F_15 ( V_6 ) ;
int V_114 ;
int V_25 ;
for ( V_114 = 0 ; V_114 < 32 ; V_114 ++ ) {
V_112 = F_50 ( V_6 , V_114 , 1 ) ;
V_113 = F_50 ( V_6 , V_114 , 0 ) ;
if ( ! V_112 && ! V_113 )
break;
}
if ( ! V_114 ) {
F_17 ( V_20 , L_9 ) ;
return - V_37 ;
}
V_111 = F_57 ( V_20 , sizeof( * V_111 ) * V_114 , V_115 ) ;
V_50 = F_57 ( V_20 , sizeof( * V_50 ) * V_114 , V_115 ) ;
if ( ! V_111 || ! V_50 ) {
F_17 ( V_20 , L_10 ) ;
return - V_116 ;
}
for ( V_25 = 0 ; V_25 < V_114 ; V_25 ++ ) {
V_112 = F_50 ( V_6 , V_25 , 1 ) ;
V_113 = F_50 ( V_6 , V_25 , 0 ) ;
F_3 ( & V_50 [ V_25 ] . V_57 . V_53 ) ;
F_3 ( & V_50 [ V_25 ] . V_78 . V_53 ) ;
snprintf ( V_50 [ V_25 ] . V_4 , V_117 , L_11 , V_25 ) ;
V_111 [ V_25 ] . V_4 = V_50 [ V_25 ] . V_4 ;
V_111 [ V_25 ] . V_3 = & V_118 ;
if ( V_112 ) {
V_111 [ V_25 ] . V_57 . V_119 = V_120 ;
V_111 [ V_25 ] . V_57 . V_121 = V_122 ;
V_111 [ V_25 ] . V_57 . V_123 = 2 ;
V_111 [ V_25 ] . V_57 . V_124 = 2 ;
}
if ( V_113 ) {
V_111 [ V_25 ] . V_78 . V_119 = V_120 ;
V_111 [ V_25 ] . V_78 . V_121 = V_122 ;
V_111 [ V_25 ] . V_78 . V_123 = 2 ;
V_111 [ V_25 ] . V_78 . V_124 = 2 ;
}
F_58 ( V_20 , L_12 , V_50 [ V_25 ] . V_4 ,
V_112 ? L_13 : L_14 ,
V_113 ? L_15 : L_16 ) ;
}
V_6 -> V_114 = V_114 ;
V_6 -> V_125 = V_111 ;
V_6 -> V_50 = V_50 ;
return 0 ;
}
static void F_59 ( struct V_106 * V_107 ,
struct V_5 * V_6 )
{
}
static int F_60 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_62 ;
int V_36 = 0 ;
F_61 ( V_60 , & V_126 ) ;
V_36 = F_62 ( V_62 ,
V_127 ) ;
return V_36 ;
}
static int F_63 ( struct V_59 * V_60 ,
struct V_128 * V_129 )
{
return F_64 ( V_60 ,
F_65 ( V_129 ) ) ;
}
static T_4 F_66 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_62 ;
struct V_55 * V_56 = F_47 ( V_60 ) ;
struct V_49 * V_50 = F_39 ( V_56 ) ;
struct V_51 * V_52 = F_48 ( V_50 , V_60 ) ;
return F_67 ( V_62 , V_52 -> V_64 ) ;
}
static int F_68 ( struct V_72 * V_73 )
{
return F_69 (
V_73 -> V_130 ,
V_131 ,
V_73 -> V_132 -> V_133 -> V_20 ,
V_134 , V_135 ) ;
}
static void F_70 ( struct V_136 * V_130 )
{
F_71 ( V_130 ) ;
}
static int F_72 ( struct V_106 * V_107 )
{
struct V_108 * V_109 ;
struct V_5 * V_6 ;
struct V_19 * V_20 = & V_107 -> V_20 ;
int V_36 ;
V_109 = V_107 -> V_20 . V_137 ;
if ( ! V_109 ) {
F_17 ( V_20 , L_17 ) ;
return - V_138 ;
}
V_6 = F_57 ( V_20 , sizeof( * V_6 ) , V_115 ) ;
if ( ! V_6 ) {
F_17 ( V_20 , L_18 ) ;
return - V_138 ;
}
V_6 -> V_20 = V_20 ;
V_6 -> V_109 = V_109 ;
F_73 ( & V_6 -> V_139 ) ;
V_36 = F_74 ( V_107 , V_109 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_75 ( V_107 , V_109 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_76 ( V_107 , V_109 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_77 ( V_107 , V_109 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_56 ( V_107 , V_109 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_78 ( V_20 , & V_140 ) ;
if ( V_36 < 0 ) {
F_17 ( V_20 , L_19 ) ;
return V_36 ;
}
V_36 = F_79 ( V_20 , & V_141 ,
V_6 -> V_125 , F_37 ( V_6 ) ) ;
if ( V_36 < 0 ) {
F_17 ( V_20 , L_20 ) ;
goto V_142;
}
F_80 ( V_20 , V_6 ) ;
F_81 ( V_20 ) ;
F_82 ( V_20 , L_21 ) ;
return V_36 ;
V_142:
F_83 ( V_20 ) ;
return V_36 ;
}
static int F_84 ( struct V_106 * V_107 )
{
struct V_5 * V_6 = F_85 ( & V_107 -> V_20 ) ;
F_86 ( & V_107 -> V_20 ) ;
F_87 ( V_107 , V_6 ) ;
F_88 ( V_107 , V_6 ) ;
F_89 ( V_107 , V_6 ) ;
F_59 ( V_107 , V_6 ) ;
F_90 ( V_107 , V_6 ) ;
return 0 ;
}
