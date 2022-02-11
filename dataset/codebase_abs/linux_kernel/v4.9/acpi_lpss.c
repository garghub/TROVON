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
V_58 = F_23 ( V_26 , NULL ) ;
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
V_58 = F_23 ( V_26 , V_5 -> V_67 ) ;
if ( ! F_24 ( V_58 ) ) {
return 1 ;
}
V_59 = F_20 ( V_58 ) ;
V_26 -> V_60 = NULL ;
V_61:
F_18 ( V_2 ) ;
return V_59 ;
}
static T_1 F_34 ( struct V_1 * V_2 , unsigned int V_68 )
{
return F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_68 ) ;
}
static void F_35 ( T_1 V_4 , struct V_1 * V_2 ,
unsigned int V_68 )
{
F_3 ( V_4 , V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_68 ) ;
}
static int F_36 ( struct V_69 * V_29 , unsigned int V_68 , T_1 * V_4 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
unsigned long V_42 ;
int V_59 ;
V_59 = F_37 ( F_38 ( V_29 ) , & V_26 ) ;
if ( F_39 ( V_59 ) )
return V_59 ;
F_40 ( & V_29 -> V_70 . V_71 , V_42 ) ;
if ( F_41 ( V_29 ) ) {
V_59 = - V_72 ;
goto V_41;
}
V_2 = F_42 ( V_26 ) ;
if ( F_39 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_59 = - V_31 ;
goto V_41;
}
* V_4 = F_34 ( V_2 , V_68 ) ;
V_41:
F_43 ( & V_29 -> V_70 . V_71 , V_42 ) ;
return V_59 ;
}
static T_3 F_44 ( struct V_69 * V_29 , struct V_73 * V_74 ,
char * V_75 )
{
T_1 V_76 = 0 ;
unsigned int V_68 ;
int V_59 ;
V_68 = strcmp ( V_74 -> V_74 . V_40 , L_4 ) ? V_77 : V_78 ;
V_59 = F_36 ( V_29 , V_68 , & V_76 ) ;
if ( V_59 )
return V_59 ;
return snprintf ( V_75 , V_79 , L_5 , V_76 ) ;
}
static T_3 F_45 ( struct V_69 * V_29 ,
struct V_73 * V_74 , char * V_75 )
{
T_1 V_80 = 0 ;
char * V_81 ;
int V_59 ;
V_59 = F_36 ( V_29 , V_12 , & V_80 ) ;
if ( V_59 )
return V_59 ;
V_81 = ( V_80 & V_82 ) ? L_6 : L_7 ;
return sprintf ( V_75 , L_8 , V_81 ) ;
}
static void F_46 ( struct V_69 * V_29 , T_4 V_4 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
T_1 V_80 , V_83 ;
V_80 = F_34 ( V_2 , V_12 ) ;
if ( V_4 < 0 ) {
if ( V_80 & V_82 ) {
V_80 &= ~ V_82 ;
F_35 ( V_80 , V_2 , V_12 ) ;
}
return;
}
V_83 = F_34 ( V_2 , V_77 ) & ~ V_84 ;
if ( V_4 >= V_85 ) {
V_83 |= V_86 ;
V_4 = V_87 ;
} else if ( V_4 > V_87 ) {
V_83 |= V_86 | V_88 ;
V_4 >>= V_89 ;
} else {
V_83 |= V_90 | V_88 ;
}
V_83 |= V_4 ;
F_35 ( V_83 , V_2 , V_77 ) ;
if ( ! ( V_80 & V_82 ) ) {
V_80 |= V_82 ;
F_35 ( V_80 , V_2 , V_12 ) ;
}
}
static void F_48 ( struct V_69 * V_29 ,
struct V_1 * V_2 )
{
unsigned int V_91 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
unsigned long V_3 = V_91 * sizeof( T_1 ) ;
V_2 -> V_93 [ V_91 ] = F_34 ( V_2 , V_3 ) ;
F_49 ( V_29 , L_9 ,
V_2 -> V_93 [ V_91 ] , V_3 ) ;
}
}
static void F_50 ( struct V_69 * V_29 ,
struct V_1 * V_2 )
{
unsigned int V_91 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
unsigned long V_3 = V_91 * sizeof( T_1 ) ;
F_35 ( V_2 -> V_93 [ V_91 ] , V_2 , V_3 ) ;
F_49 ( V_29 , L_10 ,
V_2 -> V_93 [ V_91 ] , V_3 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_94 = 10 ;
if ( V_2 -> V_5 -> V_42 & V_95 )
V_94 = 0 ;
F_52 ( V_94 ) ;
}
static int F_53 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_54 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_96 )
F_4 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_69 * V_29 )
{
F_56 ( V_29 ) ;
}
static int F_57 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_58 ( V_29 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_5 -> V_42 & V_96 )
F_48 ( V_29 , V_2 ) ;
return F_59 ( V_29 ) ;
}
static int F_60 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_61 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_96 )
F_50 ( V_29 , V_2 ) ;
return F_62 ( V_29 ) ;
}
static void F_63 ( void )
{
T_1 V_97 = 0 ;
T_1 V_98 = V_99 ;
T_1 V_100 = V_101 ;
T_1 V_102 = V_103 ;
T_1 V_104 , V_105 , V_106 , V_107 = 0xfe000ffe ;
int V_59 ;
V_59 = F_64 ( V_108 , & V_104 ) ;
if ( V_59 )
return;
F_65 ( & V_109 ) ;
V_59 = F_64 ( V_110 , & V_105 ) ;
if ( V_59 )
goto exit;
V_106 = ( ~ ( V_105 | V_104 ) ) & V_107 ;
if ( V_106 )
goto exit;
F_66 ( V_111 , V_112 ,
V_113 , V_100 , V_102 ) ;
F_66 ( V_114 , V_112 ,
V_113 , V_100 , V_102 ) ;
F_66 ( V_115 , V_116 ,
V_117 , V_97 , V_98 ) ;
exit:
F_67 ( & V_109 ) ;
}
static void F_68 ( void )
{
T_1 V_97 = V_118 | V_119 ;
T_1 V_98 = V_99 ;
T_1 V_100 = V_120 ;
T_1 V_102 = V_103 ;
F_65 ( & V_109 ) ;
F_66 ( V_115 , V_116 ,
V_117 , V_97 , V_98 ) ;
F_66 ( V_114 , V_112 ,
V_113 , V_100 , V_102 ) ;
F_66 ( V_111 , V_112 ,
V_113 , V_100 , V_102 ) ;
F_67 ( & V_109 ) ;
}
static int F_69 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
V_59 = F_70 ( V_29 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_5 -> V_42 & V_96 )
F_48 ( V_29 , V_2 ) ;
V_59 = F_56 ( V_29 ) ;
if ( V_121 & V_122 && F_71 () )
F_63 () ;
return V_59 ;
}
static int F_72 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
int V_59 ;
if ( V_121 & V_122 && F_71 () )
F_68 () ;
V_59 = F_54 ( V_29 ) ;
if ( V_59 )
return V_59 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 -> V_42 & V_96 )
F_50 ( V_29 , V_2 ) ;
return F_73 ( V_29 ) ;
}
static int F_74 ( struct V_123 * V_124 ,
unsigned long V_125 , void * V_126 )
{
struct V_57 * V_58 = F_75 ( V_126 ) ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
const struct V_51 * V_52 ;
V_52 = F_76 ( V_127 , & V_58 -> V_29 ) ;
if ( ! V_52 || ! V_52 -> V_60 )
return 0 ;
if ( F_37 ( F_38 ( & V_58 -> V_29 ) , & V_26 ) )
return 0 ;
V_2 = F_42 ( V_26 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_8 &&
V_2 -> V_37 < V_2 -> V_5 -> V_6 + V_128 ) {
F_77 ( & V_58 -> V_29 , L_11 ) ;
return 0 ;
}
switch ( V_125 ) {
case V_129 :
F_78 ( & V_58 -> V_29 , & V_130 ) ;
break;
case V_131 :
case V_132 :
F_78 ( & V_58 -> V_29 , NULL ) ;
break;
case V_133 :
F_78 ( & V_58 -> V_29 , & V_130 ) ;
if ( V_2 -> V_5 -> V_42 & V_134 )
return F_79 ( & V_58 -> V_29 . V_135 ,
& V_136 ) ;
break;
case V_137 :
if ( V_2 -> V_5 -> V_42 & V_134 )
F_80 ( & V_58 -> V_29 . V_135 , & V_136 ) ;
F_78 ( & V_58 -> V_29 , NULL ) ;
break;
default:
break;
}
return 0 ;
}
static void F_81 ( struct V_69 * V_29 )
{
struct V_1 * V_2 = F_42 ( F_47 ( V_29 ) ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! ( V_2 -> V_5 -> V_42 & V_134 ) )
return;
if ( V_2 -> V_37 >= V_2 -> V_5 -> V_6 + V_128 )
V_29 -> V_70 . V_138 = F_46 ;
else
F_77 ( V_29 , L_11 ) ;
}
static void F_82 ( struct V_69 * V_29 )
{
V_29 -> V_70 . V_138 = NULL ;
}
void T_5 F_83 ( void )
{
const struct V_139 * V_52 ;
int V_59 ;
V_59 = F_84 () ;
if ( V_59 )
return;
V_52 = F_85 ( V_140 ) ;
if ( V_52 )
V_121 |= V_122 ;
F_86 ( & V_141 , & V_142 ) ;
F_87 ( & V_143 ) ;
}
void T_5 F_83 ( void )
{
F_87 ( & V_143 ) ;
}
