static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_7 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_9 , V_2 -> V_8 + V_3 ) ;
V_4 = F_2 ( V_2 -> V_8 + V_10 ) ;
if ( ! ( V_4 & V_11 ) ) {
V_3 = V_2 -> V_5 -> V_6 + V_12 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_4 |= V_13 ;
F_3 ( V_4 , V_2 -> V_8 + V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_14 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_4 |= V_15 | V_16 ;
F_3 ( V_4 , V_2 -> V_8 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! F_6 ( L_1 , NULL , - 1 ) )
F_7 ( V_17 , F_8 ( V_17 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 ) )
V_2 -> V_18 = 133000000 ;
F_3 ( 0 , V_2 -> V_8 + V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_20 , F_8 ( V_20 ) ) ;
}
static int F_11 ( struct V_21 * V_22 , void * V_23 )
{
struct V_24 V_25 ;
return ! F_12 ( V_22 , & V_25 ) ;
}
static inline void F_13 ( void )
{
V_26 = F_14 ( L_2 , - 1 , NULL , 0 ) ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
const struct V_29 * V_5 = V_2 -> V_5 ;
const char * V_30 = F_16 ( & V_28 -> V_31 ) ;
struct V_32 * V_32 = F_17 ( - V_33 ) ;
struct V_34 * V_35 ;
const char * V_36 , * V_37 ;
void T_2 * V_38 ;
if ( ! V_26 )
F_13 () ;
V_35 = F_18 ( V_26 ) ;
if ( ! V_35 )
return - V_33 ;
V_32 = V_35 -> V_32 ;
if ( ! V_2 -> V_8
|| V_2 -> V_39 < V_5 -> V_6 + V_40 )
return - V_41 ;
V_36 = V_35 -> V_42 ;
V_38 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_2 -> V_18 ) {
V_32 = F_19 ( NULL , V_30 , V_36 , 0 ,
V_2 -> V_18 ) ;
goto V_43;
}
if ( V_5 -> V_44 & V_45 ) {
V_32 = F_20 ( NULL , V_30 , V_36 , 0 ,
V_38 , 0 , 0 , NULL ) ;
V_36 = V_30 ;
}
if ( V_5 -> V_44 & V_46 ) {
if ( ! F_2 ( V_38 ) )
F_3 ( V_47 , V_38 ) ;
V_37 = F_21 ( V_48 , L_3 , V_30 ) ;
if ( ! V_37 )
return - V_49 ;
V_32 = F_22 ( NULL , V_37 , V_36 ,
0 , V_38 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_36 = V_37 ;
V_37 = F_21 ( V_48 , L_4 , V_30 ) ;
if ( ! V_37 ) {
F_23 ( V_36 ) ;
return - V_49 ;
}
V_32 = F_20 ( NULL , V_37 , V_36 ,
V_50 | V_51 ,
V_38 , 31 , 0 , NULL ) ;
F_23 ( V_36 ) ;
F_23 ( V_37 ) ;
}
V_43:
if ( F_24 ( V_32 ) )
return F_25 ( V_32 ) ;
V_2 -> V_32 = V_32 ;
F_26 ( V_32 , V_5 -> V_52 , V_30 ) ;
return 0 ;
}
static int F_27 ( struct V_27 * V_28 ,
const struct V_53 * V_54 )
{
const struct V_29 * V_5 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
struct V_59 * V_60 ;
int V_61 ;
V_5 = ( const struct V_29 * ) V_54 -> V_62 ;
if ( ! V_5 ) {
V_60 = F_28 ( V_28 , NULL ) ;
return F_29 ( V_60 ) ? F_25 ( V_60 ) : 1 ;
}
V_2 = F_30 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
F_31 ( & V_58 ) ;
V_61 = F_32 ( V_28 , & V_58 , F_11 , NULL ) ;
if ( V_61 < 0 )
goto V_63;
F_33 (rentry, &resource_list, node)
if ( F_34 ( V_56 -> V_22 ) == V_64 ) {
if ( V_5 -> V_65 )
V_2 -> V_39 = V_5 -> V_65 ;
else
V_2 -> V_39 = F_35 ( V_56 -> V_22 ) ;
V_2 -> V_8 = F_36 ( V_56 -> V_22 -> V_66 ,
V_2 -> V_39 ) ;
break;
}
F_37 ( & V_58 ) ;
if ( ! V_2 -> V_8 ) {
V_61 = - V_49 ;
goto V_63;
}
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_67 )
V_5 -> V_67 ( V_2 ) ;
if ( V_5 -> V_44 & V_68 ) {
V_61 = F_15 ( V_28 , V_2 ) ;
if ( V_61 ) {
V_61 = 0 ;
goto V_63;
}
}
V_61 = F_38 ( V_28 ) ;
if ( V_61 ) {
V_61 = 0 ;
goto V_63;
}
V_28 -> V_62 = V_2 ;
V_60 = F_28 ( V_28 , V_5 -> V_69 ) ;
if ( ! F_29 ( V_60 ) ) {
return 1 ;
}
V_61 = F_25 ( V_60 ) ;
V_28 -> V_62 = NULL ;
V_63:
F_23 ( V_2 ) ;
return V_61 ;
}
static T_1 F_39 ( struct V_1 * V_2 , unsigned int V_70 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_70 ) ;
}
static void F_40 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_70 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_70 ) ;
}
static int F_41 ( struct V_71 * V_31 , unsigned int V_70 , T_1 * V_4 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
unsigned long V_44 ;
int V_61 ;
V_61 = F_42 ( F_43 ( V_31 ) , & V_28 ) ;
if ( F_44 ( V_61 ) )
return V_61 ;
F_45 ( & V_31 -> V_72 . V_73 , V_44 ) ;
if ( F_46 ( V_31 ) ) {
V_61 = - V_74 ;
goto V_43;
}
V_2 = F_47 ( V_28 ) ;
if ( F_44 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_61 = - V_33 ;
goto V_43;
}
* V_4 = F_39 ( V_2 , V_70 ) ;
V_43:
F_48 ( & V_31 -> V_72 . V_73 , V_44 ) ;
return V_61 ;
}
static T_3 F_49 ( struct V_71 * V_31 , struct V_75 * V_76 ,
char * V_77 )
{
T_1 V_78 = 0 ;
unsigned int V_70 ;
int V_61 ;
V_70 = strcmp ( V_76 -> V_76 . V_42 , L_5 ) ? V_79 : V_80 ;
V_61 = F_41 ( V_31 , V_70 , & V_78 ) ;
if ( V_61 )
return V_61 ;
return snprintf ( V_77 , V_81 , L_6 , V_78 ) ;
}
static T_3 F_50 ( struct V_71 * V_31 ,
struct V_75 * V_76 , char * V_77 )
{
T_1 V_82 = 0 ;
char * V_83 ;
int V_61 ;
V_61 = F_41 ( V_31 , V_12 , & V_82 ) ;
if ( V_61 )
return V_61 ;
V_83 = ( V_82 & V_84 ) ? L_7 : L_8 ;
return sprintf ( V_77 , L_9 , V_83 ) ;
}
static void F_51 ( struct V_71 * V_31 , T_4 V_4 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
T_1 V_82 , V_85 ;
V_82 = F_39 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_82 & V_84 ) {
V_82 &= ~ V_84 ;
F_40 ( V_82 , V_2 , V_12 ) ;
}
return;
}
V_85 = F_39 ( V_2 , V_79 ) & ~ V_86 ;
if ( V_4 >= V_87 ) {
V_85 |= V_88 ;
V_4 = V_89 ;
} else if ( V_4 > V_89 ) {
V_85 |= V_88 | V_90 ;
V_4 >>= V_91 ;
} else {
V_85 |= V_92 | V_90 ;
}
V_85 |= V_4 ;
F_40 ( V_85 , V_2 , V_79 ) ;
if ( ! ( V_82 & V_84 ) ) {
V_82 |= V_84 ;
F_40 ( V_82 , V_2 , V_12 ) ;
}
}
static void F_53 ( struct V_71 * V_31 ,
struct V_1 * V_2 )
{
unsigned int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
unsigned long V_3 = V_93 * sizeof( T_1 ) ;
V_2 -> V_95 [ V_93 ] = F_39 ( V_2 , V_3 ) ;
F_54 ( V_31 , L_10 ,
V_2 -> V_95 [ V_93 ] , V_3 ) ;
}
}
static void F_55 ( struct V_71 * V_31 ,
struct V_1 * V_2 )
{
unsigned int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
unsigned long V_3 = V_93 * sizeof( T_1 ) ;
F_40 ( V_2 -> V_95 [ V_93 ] , V_2 , V_3 ) ;
F_54 ( V_31 , L_11 ,
V_2 -> V_95 [ V_93 ] , V_3 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned int V_96 = 10 ;
if ( V_2 -> V_5 -> V_44 & V_97 )
V_96 = 0 ;
F_57 ( V_96 ) ;
}
static int F_58 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
int V_61 ;
V_61 = F_59 ( V_31 ) ;
if ( V_61 )
return V_61 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_44 & V_98 )
F_4 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_71 * V_31 )
{
F_61 ( V_31 ) ;
}
static int F_62 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
int V_61 ;
V_61 = F_63 ( V_31 ) ;
if ( V_61 )
return V_61 ;
if ( V_2 -> V_5 -> V_44 & V_98 )
F_53 ( V_31 , V_2 ) ;
return F_64 ( V_31 ) ;
}
static int F_65 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
int V_61 ;
V_61 = F_66 ( V_31 ) ;
if ( V_61 )
return V_61 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_44 & V_98 )
F_55 ( V_31 , V_2 ) ;
return F_67 ( V_31 ) ;
}
static void F_68 ( void )
{
T_1 V_99 = 0 ;
T_1 V_100 = V_101 | V_102 ;
T_1 V_103 = V_104 ;
T_1 V_105 = V_106 ;
T_1 V_107 , V_108 , V_109 , V_110 = 0xfe000ffe ;
int V_61 ;
V_61 = F_69 ( V_111 , & V_107 ) ;
if ( V_61 )
return;
F_70 ( & V_112 ) ;
V_61 = F_69 ( V_113 , & V_108 ) ;
if ( V_61 )
goto exit;
V_109 = ( ~ ( V_108 | V_107 ) ) & V_110 ;
if ( V_109 )
goto exit;
F_71 ( V_114 , V_115 ,
V_116 , V_103 , V_105 ) ;
F_71 ( V_117 , V_115 ,
V_116 , V_103 , V_105 ) ;
F_71 ( V_118 , V_119 ,
V_120 , V_99 , V_100 ) ;
exit:
F_72 ( & V_112 ) ;
}
static void F_73 ( void )
{
T_1 V_99 = V_121 | V_122 |
V_102 ;
T_1 V_100 = V_101 | V_102 ;
T_1 V_103 = V_123 ;
T_1 V_105 = V_106 ;
F_70 ( & V_112 ) ;
F_71 ( V_118 , V_119 ,
V_120 , V_99 , V_100 ) ;
F_71 ( V_117 , V_115 ,
V_116 , V_103 , V_105 ) ;
F_71 ( V_114 , V_115 ,
V_116 , V_103 , V_105 ) ;
F_72 ( & V_112 ) ;
}
static int F_74 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
int V_61 ;
V_61 = F_75 ( V_31 ) ;
if ( V_61 )
return V_61 ;
if ( V_2 -> V_5 -> V_44 & V_98 )
F_53 ( V_31 , V_2 ) ;
V_61 = F_61 ( V_31 ) ;
if ( V_124 & V_125 && F_76 () )
F_68 () ;
return V_61 ;
}
static int F_77 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
int V_61 ;
if ( V_124 & V_125 && F_76 () )
F_73 () ;
V_61 = F_59 ( V_31 ) ;
if ( V_61 )
return V_61 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_44 & V_98 )
F_55 ( V_31 , V_2 ) ;
return F_78 ( V_31 ) ;
}
static int F_79 ( struct V_126 * V_127 ,
unsigned long V_128 , void * V_129 )
{
struct V_59 * V_60 = F_80 ( V_129 ) ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
const struct V_53 * V_54 ;
V_54 = F_81 ( V_130 , & V_60 -> V_31 ) ;
if ( ! V_54 || ! V_54 -> V_62 )
return 0 ;
if ( F_42 ( F_43 ( & V_60 -> V_31 ) , & V_28 ) )
return 0 ;
V_2 = F_47 ( V_28 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_39 < V_2 -> V_5 -> V_6 + V_131 ) {
F_82 ( & V_60 -> V_31 , L_12 ) ;
return 0 ;
}
switch ( V_128 ) {
case V_132 :
F_83 ( & V_60 -> V_31 , & V_133 ) ;
break;
case V_134 :
case V_135 :
F_83 ( & V_60 -> V_31 , NULL ) ;
break;
case V_136 :
F_83 ( & V_60 -> V_31 , & V_133 ) ;
if ( V_2 -> V_5 -> V_44 & V_137 )
return F_84 ( & V_60 -> V_31 . V_138 ,
& V_139 ) ;
break;
case V_140 :
if ( V_2 -> V_5 -> V_44 & V_137 )
F_85 ( & V_60 -> V_31 . V_138 , & V_139 ) ;
F_83 ( & V_60 -> V_31 , NULL ) ;
break;
default:
break;
}
return 0 ;
}
static void F_86 ( struct V_71 * V_31 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_31 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_44 & V_137 ) )
return;
if ( V_2 -> V_39 >= V_2 -> V_5 -> V_6 + V_131 )
V_31 -> V_72 . V_141 = F_51 ;
else
F_82 ( V_31 , L_12 ) ;
}
static void F_87 ( struct V_71 * V_31 )
{
V_31 -> V_72 . V_141 = NULL ;
}
void T_5 F_88 ( void )
{
const struct V_142 * V_54 ;
int V_61 ;
V_61 = F_89 () ;
if ( V_61 )
return;
V_54 = F_90 ( V_143 ) ;
if ( V_54 )
V_124 |= V_125 ;
F_91 ( & V_144 , & V_145 ) ;
F_92 ( & V_146 ) ;
}
void T_5 F_88 ( void )
{
F_92 ( & V_146 ) ;
}
