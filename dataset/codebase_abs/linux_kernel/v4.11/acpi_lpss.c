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
F_4 ( V_2 ) ;
if ( F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 ) )
V_2 -> V_17 = 133000000 ;
F_3 ( 0 , V_2 -> V_8 + V_18 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_19 , F_8 ( V_19 ) ) ;
}
static int F_9 ( struct V_20 * V_21 , void * V_22 )
{
struct V_23 V_24 ;
return ! F_10 ( V_21 , & V_24 ) ;
}
static inline void F_11 ( void )
{
V_25 = F_12 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
const struct V_28 * V_5 = V_2 -> V_5 ;
const char * V_29 = F_14 ( & V_27 -> V_30 ) ;
struct V_31 * V_31 = F_15 ( - V_32 ) ;
struct V_33 * V_34 ;
const char * V_35 , * V_36 ;
void T_2 * V_37 ;
if ( ! V_25 )
F_11 () ;
V_34 = F_16 ( V_25 ) ;
if ( ! V_34 )
return - V_32 ;
V_31 = V_34 -> V_31 ;
if ( ! V_2 -> V_8
|| V_2 -> V_38 < V_5 -> V_6 + V_39 )
return - V_40 ;
V_35 = V_34 -> V_41 ;
V_37 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_2 -> V_17 ) {
V_31 = F_17 ( NULL , V_29 , V_35 , 0 ,
V_2 -> V_17 ) ;
goto V_42;
}
if ( V_5 -> V_43 & V_44 ) {
V_31 = F_18 ( NULL , V_29 , V_35 , 0 ,
V_37 , 0 , 0 , NULL ) ;
V_35 = V_29 ;
}
if ( V_5 -> V_43 & V_45 ) {
if ( ! F_2 ( V_37 ) )
F_3 ( V_46 , V_37 ) ;
V_36 = F_19 ( V_47 , L_2 , V_29 ) ;
if ( ! V_36 )
return - V_48 ;
V_31 = F_20 ( NULL , V_36 , V_35 ,
0 , V_37 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_35 = V_36 ;
V_36 = F_19 ( V_47 , L_3 , V_29 ) ;
if ( ! V_36 ) {
F_21 ( V_35 ) ;
return - V_48 ;
}
V_31 = F_18 ( NULL , V_36 , V_35 ,
V_49 | V_50 ,
V_37 , 31 , 0 , NULL ) ;
F_21 ( V_35 ) ;
F_21 ( V_36 ) ;
}
V_42:
if ( F_22 ( V_31 ) )
return F_23 ( V_31 ) ;
V_2 -> V_31 = V_31 ;
F_24 ( V_31 , V_5 -> V_51 , V_29 ) ;
return 0 ;
}
static int F_25 ( struct V_26 * V_27 ,
const struct V_52 * V_53 )
{
const struct V_28 * V_5 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
struct V_56 V_57 ;
struct V_58 * V_59 ;
int V_60 ;
V_5 = ( const struct V_28 * ) V_53 -> V_61 ;
if ( ! V_5 ) {
V_59 = F_26 ( V_27 , NULL ) ;
return F_27 ( V_59 ) ? F_23 ( V_59 ) : 1 ;
}
V_2 = F_28 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_29 ( & V_57 ) ;
V_60 = F_30 ( V_27 , & V_57 , F_9 , NULL ) ;
if ( V_60 < 0 )
goto V_62;
F_31 (rentry, &resource_list, node)
if ( F_32 ( V_55 -> V_21 ) == V_63 ) {
if ( V_5 -> V_64 )
V_2 -> V_38 = V_5 -> V_64 ;
else
V_2 -> V_38 = F_33 ( V_55 -> V_21 ) ;
V_2 -> V_8 = F_34 ( V_55 -> V_21 -> V_65 ,
V_2 -> V_38 ) ;
break;
}
F_35 ( & V_57 ) ;
if ( ! V_2 -> V_8 ) {
V_60 = - V_48 ;
goto V_62;
}
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_66 )
V_5 -> V_66 ( V_2 ) ;
if ( V_5 -> V_43 & V_67 ) {
V_60 = F_13 ( V_27 , V_2 ) ;
if ( V_60 ) {
V_60 = 0 ;
goto V_62;
}
}
V_60 = F_36 ( V_27 ) ;
if ( V_60 ) {
V_60 = 0 ;
goto V_62;
}
V_27 -> V_61 = V_2 ;
V_59 = F_26 ( V_27 , V_5 -> V_68 ) ;
if ( ! F_27 ( V_59 ) ) {
return 1 ;
}
V_60 = F_23 ( V_59 ) ;
V_27 -> V_61 = NULL ;
V_62:
F_21 ( V_2 ) ;
return V_60 ;
}
static T_1 F_37 ( struct V_1 * V_2 , unsigned int V_69 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_69 ) ;
}
static void F_38 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_69 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_69 ) ;
}
static int F_39 ( struct V_70 * V_30 , unsigned int V_69 , T_1 * V_4 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
unsigned long V_43 ;
int V_60 ;
V_60 = F_40 ( F_41 ( V_30 ) , & V_27 ) ;
if ( F_42 ( V_60 ) )
return V_60 ;
F_43 ( & V_30 -> V_71 . V_72 , V_43 ) ;
if ( F_44 ( V_30 ) ) {
V_60 = - V_73 ;
goto V_42;
}
V_2 = F_45 ( V_27 ) ;
if ( F_42 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_60 = - V_32 ;
goto V_42;
}
* V_4 = F_37 ( V_2 , V_69 ) ;
V_42:
F_46 ( & V_30 -> V_71 . V_72 , V_43 ) ;
return V_60 ;
}
static T_3 F_47 ( struct V_70 * V_30 , struct V_74 * V_75 ,
char * V_76 )
{
T_1 V_77 = 0 ;
unsigned int V_69 ;
int V_60 ;
V_69 = strcmp ( V_75 -> V_75 . V_41 , L_4 ) ? V_78 : V_79 ;
V_60 = F_39 ( V_30 , V_69 , & V_77 ) ;
if ( V_60 )
return V_60 ;
return snprintf ( V_76 , V_80 , L_5 , V_77 ) ;
}
static T_3 F_48 ( struct V_70 * V_30 ,
struct V_74 * V_75 , char * V_76 )
{
T_1 V_81 = 0 ;
char * V_82 ;
int V_60 ;
V_60 = F_39 ( V_30 , V_12 , & V_81 ) ;
if ( V_60 )
return V_60 ;
V_82 = ( V_81 & V_83 ) ? L_6 : L_7 ;
return sprintf ( V_76 , L_8 , V_82 ) ;
}
static void F_49 ( struct V_70 * V_30 , T_4 V_4 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
T_1 V_81 , V_84 ;
V_81 = F_37 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_81 & V_83 ) {
V_81 &= ~ V_83 ;
F_38 ( V_81 , V_2 , V_12 ) ;
}
return;
}
V_84 = F_37 ( V_2 , V_78 ) & ~ V_85 ;
if ( V_4 >= V_86 ) {
V_84 |= V_87 ;
V_4 = V_88 ;
} else if ( V_4 > V_88 ) {
V_84 |= V_87 | V_89 ;
V_4 >>= V_90 ;
} else {
V_84 |= V_91 | V_89 ;
}
V_84 |= V_4 ;
F_38 ( V_84 , V_2 , V_78 ) ;
if ( ! ( V_81 & V_83 ) ) {
V_81 |= V_83 ;
F_38 ( V_81 , V_2 , V_12 ) ;
}
}
static void F_51 ( struct V_70 * V_30 ,
struct V_1 * V_2 )
{
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
unsigned long V_3 = V_92 * sizeof( T_1 ) ;
V_2 -> V_94 [ V_92 ] = F_37 ( V_2 , V_3 ) ;
F_52 ( V_30 , L_9 ,
V_2 -> V_94 [ V_92 ] , V_3 ) ;
}
}
static void F_53 ( struct V_70 * V_30 ,
struct V_1 * V_2 )
{
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
unsigned long V_3 = V_92 * sizeof( T_1 ) ;
F_38 ( V_2 -> V_94 [ V_92 ] , V_2 , V_3 ) ;
F_52 ( V_30 , L_10 ,
V_2 -> V_94 [ V_92 ] , V_3 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned int V_95 = 10 ;
if ( V_2 -> V_5 -> V_43 & V_96 )
V_95 = 0 ;
F_55 ( V_95 ) ;
}
static int F_56 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
int V_60 ;
V_60 = F_57 ( V_30 ) ;
if ( V_60 )
return V_60 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_5 -> V_43 & V_97 )
F_4 ( V_2 ) ;
return 0 ;
}
static void F_58 ( struct V_70 * V_30 )
{
F_59 ( V_30 ) ;
}
static int F_60 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
int V_60 ;
V_60 = F_61 ( V_30 ) ;
if ( V_60 )
return V_60 ;
if ( V_2 -> V_5 -> V_43 & V_97 )
F_51 ( V_30 , V_2 ) ;
return F_62 ( V_30 ) ;
}
static int F_63 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
int V_60 ;
V_60 = F_64 ( V_30 ) ;
if ( V_60 )
return V_60 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_5 -> V_43 & V_97 )
F_53 ( V_30 , V_2 ) ;
return F_65 ( V_30 ) ;
}
static void F_66 ( void )
{
T_1 V_98 = 0 ;
T_1 V_99 = V_100 | V_101 ;
T_1 V_102 = V_103 ;
T_1 V_104 = V_105 ;
T_1 V_106 , V_107 , V_108 , V_109 = 0xfe000ffe ;
int V_60 ;
V_60 = F_67 ( V_110 , & V_106 ) ;
if ( V_60 )
return;
F_68 ( & V_111 ) ;
V_60 = F_67 ( V_112 , & V_107 ) ;
if ( V_60 )
goto exit;
V_108 = ( ~ ( V_107 | V_106 ) ) & V_109 ;
if ( V_108 )
goto exit;
F_69 ( V_113 , V_114 ,
V_115 , V_102 , V_104 ) ;
F_69 ( V_116 , V_114 ,
V_115 , V_102 , V_104 ) ;
F_69 ( V_117 , V_118 ,
V_119 , V_98 , V_99 ) ;
exit:
F_70 ( & V_111 ) ;
}
static void F_71 ( void )
{
T_1 V_98 = V_120 | V_121 |
V_101 ;
T_1 V_99 = V_100 | V_101 ;
T_1 V_102 = V_122 ;
T_1 V_104 = V_105 ;
F_68 ( & V_111 ) ;
F_69 ( V_117 , V_118 ,
V_119 , V_98 , V_99 ) ;
F_69 ( V_116 , V_114 ,
V_115 , V_102 , V_104 ) ;
F_69 ( V_113 , V_114 ,
V_115 , V_102 , V_104 ) ;
F_70 ( & V_111 ) ;
}
static int F_72 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
int V_60 ;
V_60 = F_73 ( V_30 ) ;
if ( V_60 )
return V_60 ;
if ( V_2 -> V_5 -> V_43 & V_97 )
F_51 ( V_30 , V_2 ) ;
V_60 = F_59 ( V_30 ) ;
if ( V_123 & V_124 && F_74 () )
F_66 () ;
return V_60 ;
}
static int F_75 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
int V_60 ;
if ( V_123 & V_124 && F_74 () )
F_71 () ;
V_60 = F_57 ( V_30 ) ;
if ( V_60 )
return V_60 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_5 -> V_43 & V_97 )
F_53 ( V_30 , V_2 ) ;
return F_76 ( V_30 ) ;
}
static int F_77 ( struct V_125 * V_126 ,
unsigned long V_127 , void * V_128 )
{
struct V_58 * V_59 = F_78 ( V_128 ) ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const struct V_52 * V_53 ;
V_53 = F_79 ( V_129 , & V_59 -> V_30 ) ;
if ( ! V_53 || ! V_53 -> V_61 )
return 0 ;
if ( F_40 ( F_41 ( & V_59 -> V_30 ) , & V_27 ) )
return 0 ;
V_2 = F_45 ( V_27 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_38 < V_2 -> V_5 -> V_6 + V_130 ) {
F_80 ( & V_59 -> V_30 , L_11 ) ;
return 0 ;
}
switch ( V_127 ) {
case V_131 :
F_81 ( & V_59 -> V_30 , & V_132 ) ;
break;
case V_133 :
case V_134 :
F_81 ( & V_59 -> V_30 , NULL ) ;
break;
case V_135 :
F_81 ( & V_59 -> V_30 , & V_132 ) ;
if ( V_2 -> V_5 -> V_43 & V_136 )
return F_82 ( & V_59 -> V_30 . V_137 ,
& V_138 ) ;
break;
case V_139 :
if ( V_2 -> V_5 -> V_43 & V_136 )
F_83 ( & V_59 -> V_30 . V_137 , & V_138 ) ;
F_81 ( & V_59 -> V_30 , NULL ) ;
break;
default:
break;
}
return 0 ;
}
static void F_84 ( struct V_70 * V_30 )
{
struct V_1 * V_2 = F_45 ( F_50 ( V_30 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_43 & V_136 ) )
return;
if ( V_2 -> V_38 >= V_2 -> V_5 -> V_6 + V_130 )
V_30 -> V_71 . V_140 = F_49 ;
else
F_80 ( V_30 , L_11 ) ;
}
static void F_85 ( struct V_70 * V_30 )
{
V_30 -> V_71 . V_140 = NULL ;
}
void T_5 F_86 ( void )
{
const struct V_141 * V_53 ;
int V_60 ;
V_60 = F_87 () ;
if ( V_60 )
return;
V_53 = F_88 ( V_142 ) ;
if ( V_53 )
V_123 |= V_124 ;
F_89 ( & V_143 , & V_144 ) ;
F_90 ( & V_145 ) ;
}
void T_5 F_86 ( void )
{
F_90 ( & V_145 ) ;
}
