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
static int F_6 ( struct V_19 * V_20 , void * V_21 )
{
struct V_22 V_23 ;
return ! F_7 ( V_20 , & V_23 ) ;
}
static inline void F_8 ( void )
{
V_24 = F_9 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_10 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
const struct V_27 * V_5 = V_2 -> V_5 ;
const char * V_28 = F_11 ( & V_26 -> V_29 ) ;
struct V_30 * V_30 = F_12 ( - V_31 ) ;
struct V_32 * V_33 ;
const char * V_34 , * V_35 ;
void T_2 * V_36 ;
if ( ! V_24 )
F_8 () ;
V_33 = F_13 ( V_24 ) ;
if ( ! V_33 )
return - V_31 ;
V_30 = V_33 -> V_30 ;
if ( ! V_2 -> V_8
|| V_2 -> V_37 < V_5 -> V_6 + V_38 )
return - V_39 ;
V_34 = V_33 -> V_40 ;
V_36 = V_2 -> V_8 + V_5 -> V_6 ;
if ( V_2 -> V_17 ) {
V_30 = F_14 ( NULL , V_28 , V_34 , 0 ,
V_2 -> V_17 ) ;
goto V_41;
}
if ( V_5 -> V_42 & V_43 ) {
V_30 = F_15 ( NULL , V_28 , V_34 , 0 ,
V_36 , 0 , 0 , NULL ) ;
V_34 = V_28 ;
}
if ( V_5 -> V_42 & V_44 ) {
if ( ! F_2 ( V_36 ) )
F_3 ( V_45 , V_36 ) ;
V_35 = F_16 ( V_46 , L_2 , V_28 ) ;
if ( ! V_35 )
return - V_47 ;
V_30 = F_17 ( NULL , V_35 , V_34 ,
0 , V_36 ,
1 , 15 , 16 , 15 , 0 , NULL ) ;
V_34 = V_35 ;
V_35 = F_16 ( V_46 , L_3 , V_28 ) ;
if ( ! V_35 ) {
F_18 ( V_34 ) ;
return - V_47 ;
}
V_30 = F_15 ( NULL , V_35 , V_34 ,
V_48 | V_49 ,
V_36 , 31 , 0 , NULL ) ;
F_18 ( V_34 ) ;
F_18 ( V_35 ) ;
}
V_41:
if ( F_19 ( V_30 ) )
return F_20 ( V_30 ) ;
V_2 -> V_30 = V_30 ;
F_21 ( V_30 , V_5 -> V_50 , V_28 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 ,
const struct V_51 * V_52 )
{
const struct V_27 * V_5 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
struct V_57 * V_58 ;
int V_59 ;
V_5 = ( const struct V_27 * ) V_52 -> V_60 ;
if ( ! V_5 ) {
V_58 = F_23 ( V_26 ) ;
return F_24 ( V_58 ) ? F_20 ( V_58 ) : 1 ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
F_26 ( & V_56 ) ;
V_59 = F_27 ( V_26 , & V_56 , F_6 , NULL ) ;
if ( V_59 < 0 )
goto V_61;
F_28 (rentry, &resource_list, node)
if ( F_29 ( V_54 -> V_20 ) == V_62 ) {
if ( V_5 -> V_63 )
V_2 -> V_37 = V_5 -> V_63 ;
else
V_2 -> V_37 = F_30 ( V_54 -> V_20 ) ;
V_2 -> V_8 = F_31 ( V_54 -> V_20 -> V_64 ,
V_2 -> V_37 ) ;
break;
}
F_32 ( & V_56 ) ;
if ( ! V_2 -> V_8 ) {
V_59 = - V_47 ;
goto V_61;
}
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_65 )
V_5 -> V_65 ( V_2 ) ;
if ( V_5 -> V_42 & V_66 ) {
V_59 = F_10 ( V_26 , V_2 ) ;
if ( V_59 ) {
V_59 = 0 ;
goto V_61;
}
}
V_59 = F_33 ( V_26 ) ;
if ( V_59 ) {
V_59 = 0 ;
goto V_61;
}
V_26 -> V_60 = V_2 ;
V_58 = F_23 ( V_26 ) ;
if ( ! F_24 ( V_58 ) ) {
return 1 ;
}
V_59 = F_20 ( V_58 ) ;
V_26 -> V_60 = NULL ;
V_61:
F_18 ( V_2 ) ;
return V_59 ;
}
static T_1 F_34 ( struct V_1 * V_2 , unsigned int V_67 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_67 ) ;
}
static void F_35 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_67 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_67 ) ;
}
static int F_36 ( struct V_68 * V_29 , unsigned int V_67 , T_1 * V_4 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
unsigned long V_42 ;
int V_59 ;
V_59 = F_37 ( F_38 ( V_29 ) , & V_26 ) ;
if ( F_39 ( V_59 ) )
return V_59 ;
F_40 ( & V_29 -> V_69 . V_70 , V_42 ) ;
if ( F_41 ( V_29 ) ) {
V_59 = - V_71 ;
goto V_41;
}
V_2 = F_42 ( V_26 ) ;
if ( F_39 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_59 = - V_31 ;
goto V_41;
}
* V_4 = F_34 ( V_2 , V_67 ) ;
V_41:
F_43 ( & V_29 -> V_69 . V_70 , V_42 ) ;
return V_59 ;
}
static T_3 F_44 ( struct V_68 * V_29 , struct V_72 * V_73 ,
char * V_74 )
{
T_1 V_75 = 0 ;
unsigned int V_67 ;
int V_59 ;
V_67 = strcmp ( V_73 -> V_73 . V_40 , L_4 ) ? V_76 : V_77 ;
V_59 = F_36 ( V_29 , V_67 , & V_75 ) ;
if ( V_59 )
return V_59 ;
return snprintf ( V_74 , V_78 , L_5 , V_75 ) ;
}
static T_3 F_45 ( struct V_68 * V_29 ,
struct V_72 * V_73 , char * V_74 )
{
T_1 V_79 = 0 ;
char * V_80 ;
int V_59 ;
V_59 = F_36 ( V_29 , V_12 , & V_79 ) ;
if ( V_59 )
return V_59 ;
V_80 = ( V_79 & V_81 ) ? L_6 : L_7 ;
return sprintf ( V_74 , L_8 , V_80 ) ;
}
static void F_46 ( struct V_68 * V_29 , T_4 V_4 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
T_1 V_79 , V_82 ;
V_79 = F_34 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_79 & V_81 ) {
V_79 &= ~ V_81 ;
F_35 ( V_79 , V_2 , V_12 ) ;
}
return;
}
V_82 = F_34 ( V_2 , V_76 ) & ~ V_83 ;
if ( V_4 >= V_84 ) {
V_82 |= V_85 ;
V_4 = V_86 ;
} else if ( V_4 > V_86 ) {
V_82 |= V_85 | V_87 ;
V_4 >>= V_88 ;
} else {
V_82 |= V_89 | V_87 ;
}
V_82 |= V_4 ;
F_35 ( V_82 , V_2 , V_76 ) ;
if ( ! ( V_79 & V_81 ) ) {
V_79 |= V_81 ;
F_35 ( V_79 , V_2 , V_12 ) ;
}
}
static void F_48 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
unsigned int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
unsigned long V_3 = V_90 * sizeof( T_1 ) ;
V_2 -> V_92 [ V_90 ] = F_34 ( V_2 , V_3 ) ;
F_49 ( V_29 , L_9 ,
V_2 -> V_92 [ V_90 ] , V_3 ) ;
}
}
static void F_50 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
unsigned int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
unsigned long V_3 = V_90 * sizeof( T_1 ) ;
F_35 ( V_2 -> V_92 [ V_90 ] , V_2 , V_3 ) ;
F_49 ( V_29 , L_10 ,
V_2 -> V_92 [ V_90 ] , V_3 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_93 = 10 ;
if ( V_2 -> V_5 -> V_42 & V_94 )
V_93 = 0 ;
F_52 ( V_93 ) ;
}
static int F_53 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_54 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_95 )
F_4 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_68 * V_29 )
{
F_56 ( V_29 ) ;
}
static int F_57 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_58 ( V_29 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_5 -> V_42 & V_95 )
F_48 ( V_29 , V_2 ) ;
return F_59 ( V_29 ) ;
}
static int F_60 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_61 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_95 )
F_50 ( V_29 , V_2 ) ;
return F_62 ( V_29 ) ;
}
static void F_63 ( void )
{
T_1 V_96 = 0 ;
T_1 V_97 = V_98 ;
T_1 V_99 = V_100 ;
T_1 V_101 = V_102 ;
T_1 V_103 , V_104 , V_105 , V_106 = 0xfe000ffe ;
int V_59 ;
V_59 = F_64 ( V_107 , & V_103 ) ;
if ( V_59 )
return;
F_65 ( & V_108 ) ;
V_59 = F_64 ( V_109 , & V_104 ) ;
if ( V_59 )
goto exit;
V_105 = ( ~ ( V_104 | V_103 ) ) & V_106 ;
if ( V_105 )
goto exit;
F_66 ( V_110 , V_111 ,
V_112 , V_99 , V_101 ) ;
F_66 ( V_113 , V_111 ,
V_112 , V_99 , V_101 ) ;
F_66 ( V_114 , V_115 ,
V_116 , V_96 , V_97 ) ;
exit:
F_67 ( & V_108 ) ;
}
static void F_68 ( void )
{
T_1 V_96 = V_117 | V_118 ;
T_1 V_97 = V_98 ;
T_1 V_99 = V_119 ;
T_1 V_101 = V_102 ;
F_65 ( & V_108 ) ;
F_66 ( V_114 , V_115 ,
V_116 , V_96 , V_97 ) ;
F_66 ( V_113 , V_111 ,
V_112 , V_99 , V_101 ) ;
F_66 ( V_110 , V_111 ,
V_112 , V_99 , V_101 ) ;
F_67 ( & V_108 ) ;
}
static int F_69 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_70 ( V_29 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_5 -> V_42 & V_95 )
F_48 ( V_29 , V_2 ) ;
V_59 = F_56 ( V_29 ) ;
if ( V_120 & V_121 && F_71 () )
F_63 () ;
return V_59 ;
}
static int F_72 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
if ( V_120 & V_121 && F_71 () )
F_68 () ;
V_59 = F_54 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_95 )
F_50 ( V_29 , V_2 ) ;
return F_73 ( V_29 ) ;
}
static int F_74 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
struct V_57 * V_58 = F_75 ( V_125 ) ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
const struct V_51 * V_52 ;
V_52 = F_76 ( V_126 , & V_58 -> V_29 ) ;
if ( ! V_52 || ! V_52 -> V_60 )
return 0 ;
if ( F_37 ( F_38 ( & V_58 -> V_29 ) , & V_26 ) )
return 0 ;
V_2 = F_42 ( V_26 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_37 < V_2 -> V_5 -> V_6 + V_127 ) {
F_77 ( & V_58 -> V_29 , L_11 ) ;
return 0 ;
}
switch ( V_124 ) {
case V_128 :
F_78 ( & V_58 -> V_29 , & V_129 ) ;
break;
case V_130 :
case V_131 :
F_78 ( & V_58 -> V_29 , NULL ) ;
break;
case V_132 :
F_78 ( & V_58 -> V_29 , & V_129 ) ;
if ( V_2 -> V_5 -> V_42 & V_133 )
return F_79 ( & V_58 -> V_29 . V_134 ,
& V_135 ) ;
break;
case V_136 :
if ( V_2 -> V_5 -> V_42 & V_133 )
F_80 ( & V_58 -> V_29 . V_134 , & V_135 ) ;
F_78 ( & V_58 -> V_29 , NULL ) ;
break;
default:
break;
}
return 0 ;
}
static void F_81 ( struct V_68 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_42 & V_133 ) )
return;
if ( V_2 -> V_37 >= V_2 -> V_5 -> V_6 + V_127 )
V_29 -> V_69 . V_137 = F_46 ;
else
F_77 ( V_29 , L_11 ) ;
}
static void F_82 ( struct V_68 * V_29 )
{
V_29 -> V_69 . V_137 = NULL ;
}
void T_5 F_83 ( void )
{
const struct V_138 * V_52 ;
int V_59 ;
V_59 = F_84 () ;
if ( V_59 )
return;
V_52 = F_85 ( V_139 ) ;
if ( V_52 )
V_120 |= V_121 ;
F_86 ( & V_140 , & V_141 ) ;
F_87 ( & V_142 ) ;
}
void T_5 F_83 ( void )
{
F_87 ( & V_142 ) ;
}
