void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
switch ( V_6 -> V_6 ) {
case V_9 :
F_2 ( V_2 , L_1 ,
& V_4 -> V_10 . V_11 . V_12 , & V_4 -> V_13 . V_11 . V_12 ) ;
break;
case V_14 :
F_2 ( V_2 , L_2 ,
V_4 -> V_10 . V_11 . V_15 , V_4 -> V_13 . V_11 . V_15 ) ;
break;
default:
break;
}
switch ( V_8 -> V_8 ) {
case V_16 :
F_2 ( V_2 , L_3 ,
V_4 -> V_13 . V_17 . V_18 . type ,
V_4 -> V_13 . V_17 . V_18 . V_19 ,
F_3 ( V_4 -> V_10 . V_17 . V_18 . V_20 ) ) ;
break;
case V_21 :
F_2 ( V_2 , L_4 ,
F_3 ( V_4 -> V_10 . V_17 . V_22 . V_23 ) ,
F_3 ( V_4 -> V_13 . V_17 . V_22 . V_23 ) ) ;
break;
case V_24 :
case V_25 :
F_2 ( V_2 , L_4 ,
F_3 ( V_4 -> V_10 . V_17 . V_26 . V_23 ) ,
F_3 ( V_4 -> V_13 . V_17 . V_26 . V_23 ) ) ;
break;
case V_27 :
F_2 ( V_2 , L_4 ,
F_3 ( V_4 -> V_10 . V_17 . V_28 . V_23 ) ,
F_3 ( V_4 -> V_13 . V_17 . V_28 . V_23 ) ) ;
break;
case V_29 :
F_2 ( V_2 , L_4 ,
F_3 ( V_4 -> V_10 . V_17 . V_30 . V_23 ) ,
F_3 ( V_4 -> V_13 . V_17 . V_30 . V_23 ) ) ;
break;
case V_31 :
F_2 ( V_2 , L_3 ,
V_4 -> V_13 . V_17 . V_18 . type ,
V_4 -> V_13 . V_17 . V_18 . V_19 ,
F_3 ( V_4 -> V_10 . V_17 . V_18 . V_20 ) ) ;
break;
case V_32 :
F_2 ( V_2 , L_5 ,
F_3 ( V_4 -> V_10 . V_17 . V_33 . V_34 ) ,
F_3 ( V_4 -> V_13 . V_17 . V_33 . V_34 ) ) ;
break;
default:
break;
}
}
static struct V_35 * F_4 ( struct V_1 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_39 ;
struct V_35 * V_40 ;
for ( V_38 -> V_41 = 0 ;
V_38 -> V_41 < V_38 -> V_42 ;
V_38 -> V_41 ++ ) {
V_40 = F_5 (
F_6 ( & V_38 -> V_43 [ V_38 -> V_41 ] ) ) ;
if ( ! F_7 ( V_40 ) )
return V_40 ;
}
return NULL ;
}
static struct V_35 * F_8 ( struct V_1 * V_36 ,
struct V_35 * V_44 )
{
struct V_37 * V_38 = V_36 -> V_39 ;
V_44 = F_5 ( F_9 ( V_44 ) ) ;
while ( F_7 ( V_44 ) ) {
if ( F_10 ( F_11 ( V_44 ) == V_38 -> V_41 ) ) {
if ( ++ V_38 -> V_41 >= V_38 -> V_42 )
return NULL ;
}
V_44 = F_5 (
F_6 ( & V_38 -> V_43 [ V_38 -> V_41 ] ) ) ;
}
return V_44 ;
}
static struct V_35 * F_12 ( struct V_1 * V_36 , T_1 V_45 )
{
struct V_35 * V_44 = F_4 ( V_36 ) ;
if ( V_44 )
while ( V_45 && ( V_44 = F_8 ( V_36 , V_44 ) ) )
V_45 -- ;
return V_45 ? NULL : V_44 ;
}
static void * F_13 ( struct V_1 * V_36 , T_1 * V_45 )
__acquires( T_2 )
{
struct V_37 * V_38 = V_36 -> V_39 ;
V_38 -> V_46 = F_14 () ;
F_15 () ;
F_16 ( & V_38 -> V_43 , & V_38 -> V_42 ) ;
return F_12 ( V_36 , * V_45 ) ;
}
static void * F_17 ( struct V_1 * V_2 , void * V_47 , T_1 * V_45 )
{
( * V_45 ) ++ ;
return F_8 ( V_2 , V_47 ) ;
}
static void F_18 ( struct V_1 * V_2 , void * V_47 )
__releases( T_2 )
{
F_19 () ;
}
static void F_20 ( struct V_1 * V_2 , const struct V_48 * V_49 )
{
int V_50 ;
T_3 V_51 ;
char * V_52 ;
V_50 = F_21 ( V_49 -> V_53 , & V_52 , & V_51 ) ;
if ( V_50 )
return;
F_2 ( V_2 , L_6 , V_52 ) ;
F_22 ( V_52 , V_51 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , const struct V_48 * V_49 )
{
}
static void F_23 ( struct V_1 * V_2 , const struct V_48 * V_49 ,
int V_54 )
{
const struct V_55 * V_56 = F_24 ( V_49 ) ;
if ( V_56 -> V_54 != V_54 )
return;
switch ( V_56 -> V_54 ) {
case V_57 :
F_2 ( V_2 , L_7 , V_56 -> V_20 ) ;
break;
case V_58 :
F_2 ( V_2 , L_8 , V_56 -> V_20 ) ;
break;
case V_59 :
F_2 ( V_2 , L_9 , V_56 -> V_20 ) ;
break;
default:
break;
}
}
static inline void F_23 ( struct V_1 * V_2 , const struct V_48 * V_49 ,
int V_54 )
{
}
static void F_25 ( struct V_1 * V_2 , const struct V_48 * V_49 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_60 * V_61 ;
T_4 V_62 ;
V_61 = F_26 ( V_49 ) ;
if ( V_61 ) {
V_62 = V_38 -> V_46 - V_61 -> V_63 ;
if ( V_62 > 0 )
V_62 = F_27 ( V_62 , V_64 ) ;
else
V_62 = 0 ;
F_2 ( V_2 , L_10 ,
( unsigned long long ) V_62 ) ;
}
return;
}
static inline void
F_25 ( struct V_1 * V_2 , const struct V_48 * V_49 )
{
}
static const char * F_28 ( T_5 V_65 )
{
switch ( V_65 ) {
case V_66 : return L_11 ;
case V_67 : return L_12 ;
}
return L_13 ;
}
static const char * F_29 ( T_5 V_65 )
{
switch ( V_65 ) {
case V_16 : return L_14 ;
case V_21 : return L_15 ;
case V_25 : return L_16 ;
case V_27 : return L_17 ;
case V_32 : return L_18 ;
case V_29 : return L_19 ;
case V_24 : return L_20 ;
}
return L_13 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_47 )
{
struct V_68 * V_43 = V_47 ;
struct V_48 * V_49 = F_31 ( V_43 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_69 * V_69 = F_32 ( V_2 ) ;
int V_50 = 0 ;
F_33 ( ! V_49 ) ;
if ( F_34 ( ! F_35 ( & V_49 -> V_70 . V_71 ) ) )
return 0 ;
if ( F_36 ( V_49 ) ) {
F_37 ( V_49 ) ;
goto V_72;
}
if ( F_38 ( V_43 ) )
goto V_72;
if ( ! F_39 ( F_40 ( V_49 ) , V_69 ) )
goto V_72;
V_6 = F_41 ( F_42 ( V_49 ) ) ;
F_33 ( ! V_6 ) ;
V_8 = F_43 ( F_42 ( V_49 ) , F_44 ( V_49 ) ) ;
F_33 ( ! V_8 ) ;
V_50 = - V_73 ;
F_2 ( V_2 , L_21 ,
F_28 ( V_6 -> V_6 ) , F_42 ( V_49 ) ,
F_29 ( V_8 -> V_8 ) , F_44 ( V_49 ) ,
F_45 ( V_49 ) / V_74 ) ;
if ( V_8 -> V_75 )
V_8 -> V_75 ( V_2 , V_49 ) ;
F_1 ( V_2 , & V_49 -> V_76 [ V_77 ] . V_4 ,
V_6 , V_8 ) ;
F_23 ( V_2 , V_49 , V_58 ) ;
if ( F_46 ( V_2 ) )
goto V_72;
if ( F_47 ( V_2 , V_49 , V_77 ) )
goto V_72;
if ( ! ( F_48 ( V_78 , & V_49 -> V_79 ) ) )
F_49 ( V_2 , L_22 ) ;
F_1 ( V_2 , & V_49 -> V_76 [ V_80 ] . V_4 ,
V_6 , V_8 ) ;
F_23 ( V_2 , V_49 , V_59 ) ;
if ( F_47 ( V_2 , V_49 , V_80 ) )
goto V_72;
if ( F_48 ( V_81 , & V_49 -> V_79 ) )
F_49 ( V_2 , L_23 ) ;
if ( F_46 ( V_2 ) )
goto V_72;
#if F_50 ( V_82 )
F_2 ( V_2 , L_24 , V_49 -> V_83 ) ;
#endif
F_20 ( V_2 , V_49 ) ;
F_23 ( V_2 , V_49 , V_57 ) ;
F_25 ( V_2 , V_49 ) ;
F_2 ( V_2 , L_25 , F_51 ( & V_49 -> V_70 . V_71 ) ) ;
if ( F_46 ( V_2 ) )
goto V_72;
V_50 = 0 ;
V_72:
F_52 ( V_49 ) ;
return V_50 ;
}
static int F_53 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_54 ( V_84 , V_85 , & V_86 ,
sizeof( struct V_37 ) ) ;
}
static void * F_55 ( struct V_1 * V_36 , T_1 * V_45 )
{
struct V_69 * V_69 = F_32 ( V_36 ) ;
int V_87 ;
if ( * V_45 == 0 )
return V_88 ;
for ( V_87 = * V_45 - 1 ; V_87 < V_89 ; ++ V_87 ) {
if ( ! F_56 ( V_87 ) )
continue;
* V_45 = V_87 + 1 ;
return F_57 ( V_69 -> V_49 . V_90 , V_87 ) ;
}
return NULL ;
}
static void * F_58 ( struct V_1 * V_36 , void * V_47 , T_1 * V_45 )
{
struct V_69 * V_69 = F_32 ( V_36 ) ;
int V_87 ;
for ( V_87 = * V_45 ; V_87 < V_89 ; ++ V_87 ) {
if ( ! F_56 ( V_87 ) )
continue;
* V_45 = V_87 + 1 ;
return F_57 ( V_69 -> V_49 . V_90 , V_87 ) ;
}
return NULL ;
}
static void F_59 ( struct V_1 * V_36 , void * V_47 )
{
}
static int F_60 ( struct V_1 * V_36 , void * V_47 )
{
struct V_69 * V_69 = F_32 ( V_36 ) ;
unsigned int V_91 = F_51 ( & V_69 -> V_49 . V_92 ) ;
const struct V_93 * V_38 = V_47 ;
if ( V_47 == V_88 ) {
F_49 ( V_36 , L_26 ) ;
return 0 ;
}
F_2 ( V_36 , L_27
L_28 ,
V_91 ,
0 ,
V_38 -> V_94 ,
0 ,
V_38 -> V_95 ,
V_38 -> V_96 ,
0 ,
0 ,
V_38 -> V_97 ,
V_38 -> V_98 ,
V_38 -> V_99 ,
V_38 -> V_100 ,
V_38 -> error ,
V_38 -> V_101 ,
V_38 -> V_102 ,
V_38 -> V_103 ,
V_38 -> V_104
) ;
return 0 ;
}
static int F_61 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_54 ( V_84 , V_85 , & V_105 ,
sizeof( struct V_106 ) ) ;
}
static int F_62 ( struct V_69 * V_69 )
{
struct V_107 * V_108 ;
T_6 V_109 ;
T_7 V_110 ;
V_108 = F_63 ( L_29 , 0440 , V_69 -> V_111 , & V_112 ) ;
if ( ! V_108 )
goto V_113;
V_109 = F_64 ( V_69 -> V_114 , 0 ) ;
V_110 = F_65 ( V_69 -> V_114 , 0 ) ;
if ( F_66 ( V_109 ) && F_67 ( V_110 ) )
F_68 ( V_108 , V_109 , V_110 ) ;
V_108 = F_63 ( L_29 , V_115 , V_69 -> V_116 ,
& V_117 ) ;
if ( ! V_108 )
goto V_118;
return 0 ;
V_118:
F_69 ( L_29 , V_69 -> V_111 ) ;
V_113:
return - V_119 ;
}
static void F_70 ( struct V_69 * V_69 )
{
F_69 ( L_29 , V_69 -> V_116 ) ;
F_69 ( L_29 , V_69 -> V_111 ) ;
}
static int F_62 ( struct V_69 * V_69 )
{
return 0 ;
}
static void F_70 ( struct V_69 * V_69 )
{
}
static int
F_71 ( struct V_120 * V_121 , int V_122 ,
void T_8 * V_123 , T_9 * V_124 , T_1 * V_125 )
{
int V_50 ;
V_50 = F_72 ( V_121 , V_122 , V_123 , V_124 , V_125 ) ;
if ( V_50 < 0 || ! V_122 )
return V_50 ;
V_50 = F_73 ( V_126 ) ;
V_126 = V_127 ;
return V_50 ;
}
static int F_74 ( struct V_69 * V_69 )
{
struct V_120 * V_121 ;
V_121 = F_75 ( V_128 , sizeof( V_128 ) ,
V_129 ) ;
if ( ! V_121 )
goto V_130;
V_121 [ 1 ] . V_131 = & V_69 -> V_49 . V_92 ;
V_121 [ 3 ] . V_131 = & V_69 -> V_49 . V_132 ;
V_121 [ 4 ] . V_131 = & V_69 -> V_49 . V_133 ;
if ( V_69 -> V_114 != & V_134 )
V_121 [ 0 ] . V_135 = NULL ;
if ( ! F_39 ( & V_136 , V_69 ) )
V_121 [ 2 ] . V_137 = 0444 ;
V_69 -> V_49 . V_138 = F_76 ( V_69 , L_30 , V_121 ) ;
if ( ! V_69 -> V_49 . V_138 )
goto V_139;
return 0 ;
V_139:
F_77 ( V_121 ) ;
V_130:
return - V_119 ;
}
static void F_78 ( struct V_69 * V_69 )
{
struct V_120 * V_121 ;
V_121 = V_69 -> V_49 . V_138 -> V_140 ;
F_79 ( V_69 -> V_49 . V_138 ) ;
F_77 ( V_121 ) ;
}
static int F_74 ( struct V_69 * V_69 )
{
return 0 ;
}
static void F_78 ( struct V_69 * V_69 )
{
}
static int F_80 ( struct V_69 * V_69 )
{
int V_50 ;
V_50 = F_81 ( V_69 ) ;
if ( V_50 < 0 )
goto V_141;
V_50 = F_62 ( V_69 ) ;
if ( V_50 < 0 )
goto V_142;
V_69 -> V_49 . V_132 = 1 ;
V_69 -> V_49 . V_133 = 0 ;
V_50 = F_74 ( V_69 ) ;
if ( V_50 < 0 )
goto V_143;
return 0 ;
V_143:
F_70 ( V_69 ) ;
V_142:
F_82 ( V_69 ) ;
V_141:
return V_50 ;
}
static void F_83 ( struct V_144 * V_145 )
{
struct V_69 * V_69 ;
F_84 (net, net_exit_list, exit_list) {
F_78 ( V_69 ) ;
F_70 ( V_69 ) ;
}
F_85 ( V_145 ) ;
}
static int T_10 F_86 ( void )
{
int V_50 = F_87 () ;
if ( V_50 < 0 )
goto V_146;
F_88 ( V_147 != V_148 ) ;
F_88 ( V_149 <= V_150 ) ;
#ifdef F_89
V_151 =
F_76 ( & V_136 , L_31 , V_152 ) ;
if ( ! V_151 ) {
F_90 ( L_32 ) ;
V_50 = - V_119 ;
goto V_143;
}
V_126 = V_127 ;
#endif
V_50 = F_91 ( & V_153 ) ;
if ( V_50 < 0 )
goto V_154;
F_92 () ;
return 0 ;
V_154:
#ifdef F_89
F_79 ( V_151 ) ;
V_143:
#endif
F_93 () ;
V_146:
return V_50 ;
}
static void T_11 F_94 ( void )
{
F_95 () ;
F_96 ( & V_153 ) ;
#ifdef F_89
F_79 ( V_151 ) ;
#endif
F_93 () ;
}
void F_97 ( void )
{
}
