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
struct V_17 * V_18 = V_2 -> V_18 ;
if ( ! V_18 -> V_19 . V_20 || strcmp ( V_18 -> V_19 . V_20 , L_1 ) )
return;
if ( ! F_6 ( L_2 , NULL , - 1 ) )
F_7 ( V_21 , F_8 ( V_21 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 ) )
V_2 -> V_22 = 133000000 ;
F_3 ( 0 , V_2 -> V_8 + V_23 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( ! V_18 -> V_19 . V_20 || strcmp ( V_18 -> V_19 . V_20 , L_1 ) )
return;
F_7 ( V_24 , F_8 ( V_24 ) ) ;
}
static int F_11 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 V_29 ;
return ! F_12 ( V_26 , & V_29 ) ;
}
static inline void F_13 ( void )
{
V_30 = F_14 ( L_3 , - 1 , NULL , 0 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
const struct V_31 * V_5 = V_2 -> V_5 ;
const char * V_32 = F_16 ( & V_18 -> V_33 ) ;
struct V_34 * V_34 = F_17 ( - V_35 ) ;
struct V_36 * V_37 ;
const char * V_38 , * V_39 ;
void T_2 * V_40 ;
if ( ! V_30 )
F_13 () ;
V_37 = F_18 ( V_30 ) ;
if ( ! V_37 )
return - V_35 ;
V_34 = V_37 -> V_34 ;
if ( ! V_2 -> V_8
|| V_2 -> V_41 < V_5 -> V_6 + V_42 )
return - V_43 ;
V_38 = V_37 -> V_44 ;
V_40 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_2 -> V_22 ) {
V_34 = F_19 ( NULL , V_32 , V_38 , 0 ,
V_2 -> V_22 ) ;
goto V_45;
}
if ( V_5 -> V_46 & V_47 ) {
V_34 = F_20 ( NULL , V_32 , V_38 , 0 ,
V_40 , 0 , 0 , NULL ) ;
V_38 = V_32 ;
}
if ( V_5 -> V_46 & V_48 ) {
if ( ! F_2 ( V_40 ) )
F_3 ( V_49 , V_40 ) ;
V_39 = F_21 ( V_50 , L_4 , V_32 ) ;
if ( ! V_39 )
return - V_51 ;
V_34 = F_22 ( NULL , V_39 , V_38 ,
0 , V_40 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_38 = V_39 ;
V_39 = F_21 ( V_50 , L_5 , V_32 ) ;
if ( ! V_39 ) {
F_23 ( V_38 ) ;
return - V_51 ;
}
V_34 = F_20 ( NULL , V_39 , V_38 ,
V_52 | V_53 ,
V_40 , 31 , 0 , NULL ) ;
F_23 ( V_38 ) ;
F_23 ( V_39 ) ;
}
V_45:
if ( F_24 ( V_34 ) )
return F_25 ( V_34 ) ;
V_2 -> V_34 = V_34 ;
F_26 ( V_34 , V_5 -> V_54 , V_32 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 ,
const struct V_55 * V_56 )
{
const struct V_31 * V_5 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_59 V_60 ;
struct V_61 * V_62 ;
int V_63 ;
V_5 = ( const struct V_31 * ) V_56 -> V_64 ;
if ( ! V_5 ) {
V_62 = F_28 ( V_18 , NULL ) ;
return F_29 ( V_62 ) ? F_25 ( V_62 ) : 1 ;
}
V_2 = F_30 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
F_31 ( & V_60 ) ;
V_63 = F_32 ( V_18 , & V_60 , F_11 , NULL ) ;
if ( V_63 < 0 )
goto V_65;
F_33 (rentry, &resource_list, node)
if ( F_34 ( V_58 -> V_26 ) == V_66 ) {
if ( V_5 -> V_67 )
V_2 -> V_41 = V_5 -> V_67 ;
else
V_2 -> V_41 = F_35 ( V_58 -> V_26 ) ;
V_2 -> V_8 = F_36 ( V_58 -> V_26 -> V_68 ,
V_2 -> V_41 ) ;
break;
}
F_37 ( & V_60 ) ;
if ( ! V_2 -> V_8 ) {
V_63 = 0 ;
goto V_65;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_69 )
V_5 -> V_69 ( V_2 ) ;
if ( V_5 -> V_46 & V_70 ) {
V_63 = F_15 ( V_18 , V_2 ) ;
if ( V_63 ) {
V_63 = 0 ;
goto V_65;
}
}
V_63 = F_38 ( V_18 ) ;
if ( V_63 ) {
V_63 = 0 ;
goto V_65;
}
V_18 -> V_64 = V_2 ;
V_62 = F_28 ( V_18 , V_5 -> V_71 ) ;
if ( ! F_29 ( V_62 ) ) {
return 1 ;
}
V_63 = F_25 ( V_62 ) ;
V_18 -> V_64 = NULL ;
V_65:
F_23 ( V_2 ) ;
return V_63 ;
}
static T_1 F_39 ( struct V_1 * V_2 , unsigned int V_72 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_72 ) ;
}
static void F_40 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_72 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_72 ) ;
}
static int F_41 ( struct V_73 * V_33 , unsigned int V_72 , T_1 * V_4 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned long V_46 ;
int V_63 ;
V_63 = F_42 ( F_43 ( V_33 ) , & V_18 ) ;
if ( F_44 ( V_63 ) )
return V_63 ;
F_45 ( & V_33 -> V_74 . V_75 , V_46 ) ;
if ( F_46 ( V_33 ) ) {
V_63 = - V_76 ;
goto V_45;
}
V_2 = F_47 ( V_18 ) ;
if ( F_44 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_63 = - V_35 ;
goto V_45;
}
* V_4 = F_39 ( V_2 , V_72 ) ;
V_45:
F_48 ( & V_33 -> V_74 . V_75 , V_46 ) ;
return V_63 ;
}
static T_3 F_49 ( struct V_73 * V_33 , struct V_77 * V_78 ,
char * V_79 )
{
T_1 V_80 = 0 ;
unsigned int V_72 ;
int V_63 ;
V_72 = strcmp ( V_78 -> V_78 . V_44 , L_6 ) ? V_81 : V_82 ;
V_63 = F_41 ( V_33 , V_72 , & V_80 ) ;
if ( V_63 )
return V_63 ;
return snprintf ( V_79 , V_83 , L_7 , V_80 ) ;
}
static T_3 F_50 ( struct V_73 * V_33 ,
struct V_77 * V_78 , char * V_79 )
{
T_1 V_84 = 0 ;
char * V_85 ;
int V_63 ;
V_63 = F_41 ( V_33 , V_12 , & V_84 ) ;
if ( V_63 )
return V_63 ;
V_85 = ( V_84 & V_86 ) ? L_8 : L_9 ;
return sprintf ( V_79 , L_10 , V_85 ) ;
}
static void F_51 ( struct V_73 * V_33 , T_4 V_4 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
T_1 V_84 , V_87 ;
V_84 = F_39 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_84 & V_86 ) {
V_84 &= ~ V_86 ;
F_40 ( V_84 , V_2 , V_12 ) ;
}
return;
}
V_87 = F_39 ( V_2 , V_81 ) & ~ V_88 ;
if ( V_4 >= V_89 ) {
V_87 |= V_90 ;
V_4 = V_91 ;
} else if ( V_4 > V_91 ) {
V_87 |= V_90 | V_92 ;
V_4 >>= V_93 ;
} else {
V_87 |= V_94 | V_92 ;
}
V_87 |= V_4 ;
F_40 ( V_87 , V_2 , V_81 ) ;
if ( ! ( V_84 & V_86 ) ) {
V_84 |= V_86 ;
F_40 ( V_84 , V_2 , V_12 ) ;
}
}
static void F_53 ( struct V_73 * V_33 ,
struct V_1 * V_2 )
{
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
unsigned long V_3 = V_95 * sizeof( T_1 ) ;
V_2 -> V_97 [ V_95 ] = F_39 ( V_2 , V_3 ) ;
F_54 ( V_33 , L_11 ,
V_2 -> V_97 [ V_95 ] , V_3 ) ;
}
}
static void F_55 ( struct V_73 * V_33 ,
struct V_1 * V_2 )
{
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
unsigned long V_3 = V_95 * sizeof( T_1 ) ;
F_40 ( V_2 -> V_97 [ V_95 ] , V_2 , V_3 ) ;
F_54 ( V_33 , L_12 ,
V_2 -> V_97 [ V_95 ] , V_3 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned int V_98 = 10 ;
if ( V_2 -> V_5 -> V_46 & V_99 )
V_98 = 0 ;
F_57 ( V_98 ) ;
}
static int F_58 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
int V_63 ;
V_63 = F_59 ( V_33 ) ;
if ( V_63 )
return V_63 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_46 & V_100 )
F_4 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_73 * V_33 )
{
F_61 ( V_33 ) ;
}
static int F_62 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
int V_63 ;
V_63 = F_63 ( V_33 ) ;
if ( V_63 )
return V_63 ;
if ( V_2 -> V_5 -> V_46 & V_100 )
F_53 ( V_33 , V_2 ) ;
return F_64 ( V_33 ) ;
}
static int F_65 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
int V_63 ;
V_63 = F_66 ( V_33 ) ;
if ( V_63 )
return V_63 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_46 & V_100 )
F_55 ( V_33 , V_2 ) ;
return F_67 ( V_33 ) ;
}
static void F_68 ( void )
{
T_1 V_101 = 0 ;
T_1 V_102 = V_103 | V_104 ;
T_1 V_105 = V_106 ;
T_1 V_107 = V_108 ;
T_1 V_109 , V_110 , V_111 , V_112 = 0xfe000ffe ;
int V_63 ;
V_63 = F_69 ( V_113 , & V_109 ) ;
if ( V_63 )
return;
F_70 ( & V_114 ) ;
V_63 = F_69 ( V_115 , & V_110 ) ;
if ( V_63 )
goto exit;
V_111 = ( ~ ( V_110 | V_109 ) ) & V_112 ;
if ( V_111 )
goto exit;
F_71 ( V_116 , V_117 ,
V_118 , V_105 , V_107 ) ;
F_71 ( V_119 , V_117 ,
V_118 , V_105 , V_107 ) ;
F_71 ( V_120 , V_121 ,
V_122 , V_101 , V_102 ) ;
exit:
F_72 ( & V_114 ) ;
}
static void F_73 ( void )
{
T_1 V_101 = V_123 | V_124 |
V_104 ;
T_1 V_102 = V_103 | V_104 ;
T_1 V_105 = V_125 ;
T_1 V_107 = V_108 ;
F_70 ( & V_114 ) ;
F_71 ( V_120 , V_121 ,
V_122 , V_101 , V_102 ) ;
F_71 ( V_119 , V_117 ,
V_118 , V_105 , V_107 ) ;
F_71 ( V_116 , V_117 ,
V_118 , V_105 , V_107 ) ;
F_72 ( & V_114 ) ;
}
static int F_74 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
int V_63 ;
V_63 = F_75 ( V_33 ) ;
if ( V_63 )
return V_63 ;
if ( V_2 -> V_5 -> V_46 & V_100 )
F_53 ( V_33 , V_2 ) ;
V_63 = F_61 ( V_33 ) ;
if ( V_126 & V_127 && F_76 () )
F_68 () ;
return V_63 ;
}
static int F_77 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
int V_63 ;
if ( V_126 & V_127 && F_76 () )
F_73 () ;
V_63 = F_59 ( V_33 ) ;
if ( V_63 )
return V_63 ;
F_56 ( V_2 ) ;
if ( V_2 -> V_5 -> V_46 & V_100 )
F_55 ( V_33 , V_2 ) ;
return F_78 ( V_33 ) ;
}
static int F_79 ( struct V_128 * V_129 ,
unsigned long V_130 , void * V_131 )
{
struct V_61 * V_62 = F_80 ( V_131 ) ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
const struct V_55 * V_56 ;
V_56 = F_81 ( V_132 , & V_62 -> V_33 ) ;
if ( ! V_56 || ! V_56 -> V_64 )
return 0 ;
if ( F_42 ( F_43 ( & V_62 -> V_33 ) , & V_18 ) )
return 0 ;
V_2 = F_47 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_41 < V_2 -> V_5 -> V_6 + V_133 ) {
F_82 ( & V_62 -> V_33 , L_13 ) ;
return 0 ;
}
switch ( V_130 ) {
case V_134 :
F_83 ( & V_62 -> V_33 , & V_135 ) ;
break;
case V_136 :
case V_137 :
F_83 ( & V_62 -> V_33 , NULL ) ;
break;
case V_138 :
F_83 ( & V_62 -> V_33 , & V_135 ) ;
if ( V_2 -> V_5 -> V_46 & V_139 )
return F_84 ( & V_62 -> V_33 . V_140 ,
& V_141 ) ;
break;
case V_142 :
if ( V_2 -> V_5 -> V_46 & V_139 )
F_85 ( & V_62 -> V_33 . V_140 , & V_141 ) ;
F_83 ( & V_62 -> V_33 , NULL ) ;
break;
default:
break;
}
return 0 ;
}
static void F_86 ( struct V_73 * V_33 )
{
struct V_1 * V_2 = F_47 ( F_52 ( V_33 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_46 & V_139 ) )
return;
if ( V_2 -> V_41 >= V_2 -> V_5 -> V_6 + V_133 )
V_33 -> V_74 . V_143 = F_51 ;
else
F_82 ( V_33 , L_13 ) ;
}
static void F_87 ( struct V_73 * V_33 )
{
V_33 -> V_74 . V_143 = NULL ;
}
void T_5 F_88 ( void )
{
const struct V_144 * V_56 ;
int V_63 ;
V_63 = F_89 () ;
if ( V_63 )
return;
V_56 = F_90 ( V_145 ) ;
if ( V_56 )
V_126 |= V_127 ;
F_91 ( & V_146 , & V_147 ) ;
F_92 ( & V_148 ) ;
}
void T_5 F_88 ( void )
{
F_92 ( & V_148 ) ;
}
