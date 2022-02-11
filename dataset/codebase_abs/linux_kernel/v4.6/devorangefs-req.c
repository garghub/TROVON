static int F_1 ( T_1 V_1 , int V_2 )
{
return F_2 ( V_1 , ( unsigned int ) V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
int V_5 = F_1 ( V_4 -> V_1 , V_6 ) ;
F_4 ( & V_4 -> V_7 , & V_8 [ V_5 ] ) ;
}
static struct V_3 * F_5 ( T_1 V_1 )
{
struct V_3 * V_4 , * V_9 ;
int V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
F_6 ( & V_10 ) ;
F_7 (op,
next,
&htable_ops_in_progress[index],
list) {
if ( V_4 -> V_1 == V_1 && ! F_8 ( V_4 ) &&
! F_9 ( V_4 ) ) {
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_10 ) ;
return V_4 ;
}
}
F_11 ( & V_10 ) ;
return NULL ;
}
static int F_12 ( void )
{
int V_11 = 1 ;
struct V_12 * V_13 = NULL ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
V_13 -> V_15 = 1 ;
V_11 = 0 ;
}
F_11 ( & V_14 ) ;
return V_11 ;
}
static int F_14 ( T_2 V_16 )
{
int V_15 = - 1 ;
struct V_12 * V_13 = NULL ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
if ( V_13 -> V_17 == V_16 ) {
V_15 = V_13 -> V_15 ;
break;
}
}
F_11 ( & V_14 ) ;
return V_15 ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
int V_20 = - V_21 ;
if ( ! ( V_19 -> V_22 & V_23 ) ) {
F_16 ( L_1 ,
V_24 ) ;
goto V_25;
}
V_20 = - V_26 ;
F_17 ( V_27 , L_2 ) ;
F_18 ( & V_28 ) ;
if ( V_29 == 0 ) {
V_29 = 1 ;
V_20 = 0 ;
} else {
F_19 () ;
}
F_20 ( & V_28 ) ;
V_25:
F_17 ( V_27 ,
L_3 ,
V_20 ) ;
return V_20 ;
}
static T_3 F_21 ( struct V_19 * V_19 ,
char T_4 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_3 * V_4 , * V_33 ;
T_2 V_34 = V_35 ;
static T_2 V_36 = V_37 ;
struct V_3 * V_38 = NULL ;
unsigned long V_20 ;
if ( ! ( V_19 -> V_22 & V_23 ) ) {
F_16 ( L_4 ,
V_24 ) ;
return - V_21 ;
}
if ( V_31 != V_39 ) {
F_16 ( L_5 ) ;
return - V_21 ;
}
V_40:
F_6 ( & V_41 ) ;
F_7 (op, temp, &orangefs_request_list, list) {
T_2 V_16 ;
F_6 ( & V_4 -> V_42 ) ;
if ( F_22 ( F_8 ( V_4 ) || F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_42 ) ;
continue;
}
V_16 = F_23 ( V_4 ) ;
if ( V_16 != V_43 ) {
int V_20 ;
V_20 = F_14 ( V_16 ) ;
if ( V_20 == 1 ) {
F_17 ( V_27 ,
L_6
L_7 ,
V_24 ,
F_24 ( V_4 -> V_1 ) ,
F_25 ( V_4 ) ) ;
F_11 ( & V_4 -> V_42 ) ;
continue;
} else if ( V_20 == - 1 &&
! ( V_4 -> V_44 . type ==
V_45 ||
V_4 -> V_44 . type ==
V_46 ) ) {
F_17 ( V_27 ,
L_8 ,
F_24 ( V_4 -> V_1 ) , F_25 ( V_4 ) ) ;
F_16 (
L_9 ,
V_16 ) ;
F_11 ( & V_4 -> V_42 ) ;
continue;
}
}
V_38 = V_4 ;
break;
}
if ( ! V_38 ) {
F_11 ( & V_41 ) ;
return - V_47 ;
}
F_17 ( V_27 , L_10 ,
V_24 ,
F_24 ( V_38 -> V_1 ) ,
F_25 ( V_38 ) ) ;
if ( F_26 ( V_38 ) || F_27 ( V_38 ) ) {
F_16 ( L_11 ) ;
F_10 ( & V_38 -> V_7 ) ;
F_11 ( & V_38 -> V_42 ) ;
F_11 ( & V_41 ) ;
return - V_47 ;
}
F_10 ( & V_38 -> V_7 ) ;
F_11 ( & V_41 ) ;
F_11 ( & V_38 -> V_42 ) ;
V_20 = F_28 ( V_30 , & V_34 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_30 + sizeof( T_2 ) , & V_36 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_30 + 2 * sizeof( T_2 ) , & V_38 -> V_1 , sizeof( T_1 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_30 + 2 * sizeof( T_2 ) + sizeof( T_1 ) , & V_38 -> V_44 ,
sizeof( struct V_48 ) ) ;
if ( V_20 != 0 )
goto error;
F_6 ( & V_10 ) ;
F_6 ( & V_38 -> V_42 ) ;
if ( F_22 ( F_9 ( V_38 ) ) ) {
F_11 ( & V_38 -> V_42 ) ;
F_11 ( & V_10 ) ;
F_29 ( & V_38 -> V_49 ) ;
goto V_40;
}
F_30 ( V_38 ) ;
F_17 ( V_27 ,
L_12 ,
V_24 ,
F_25 ( V_38 ) ,
V_38 -> V_50 ,
V_51 -> V_52 ) ;
F_3 ( V_38 ) ;
F_11 ( & V_38 -> V_42 ) ;
F_11 ( & V_10 ) ;
return V_39 ;
error:
F_16 ( L_13 ) ;
F_6 ( & V_41 ) ;
F_6 ( & V_38 -> V_42 ) ;
if ( F_31 ( ! F_9 ( V_38 ) ) ) {
F_32 ( V_38 ) ;
F_17 ( V_27 ,
L_14 ,
V_24 ,
F_25 ( V_38 ) ,
V_38 -> V_50 ,
V_51 -> V_52 ) ;
F_33 ( & V_38 -> V_7 , & V_53 ) ;
F_11 ( & V_38 -> V_42 ) ;
} else {
F_11 ( & V_38 -> V_42 ) ;
F_29 ( & V_38 -> V_49 ) ;
}
F_11 ( & V_41 ) ;
return - V_54 ;
}
static T_3 F_34 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
T_3 V_20 ;
struct V_3 * V_4 = NULL ;
struct {
T_7 V_59 ;
T_7 V_36 ;
T_1 V_1 ;
} V_60 ;
int V_61 = V_20 = F_35 ( V_58 ) ;
int V_62 ;
int V_63 = sizeof( struct V_64 ) ;
int V_65 = sizeof( V_60 ) ;
F_17 ( V_27 , L_15 ,
V_24 ,
V_61 ,
V_20 ) ;
if ( V_61 < V_66 ) {
F_16 ( L_16 ,
V_24 ,
V_61 ,
( unsigned int ) V_66 ) ;
return - V_54 ;
}
V_62 = F_36 ( & V_60 , V_65 , V_58 ) ;
if ( V_62 < V_65 ) {
F_16 ( L_17 , V_24 ) ;
return - V_54 ;
}
if ( V_60 . V_59 < V_67 ) {
F_16 ( L_18
L_19 ,
V_24 ,
V_60 . V_59 ,
V_67 ) ;
return - V_68 ;
}
if ( V_60 . V_36 != V_37 ) {
F_16 ( L_20 ) ;
return - V_68 ;
}
V_4 = F_5 ( V_60 . V_1 ) ;
if ( ! V_4 ) {
F_16 ( L_21 ,
F_24 ( V_60 . V_1 ) ) ;
return V_20 ;
}
V_62 = F_36 ( & V_4 -> V_69 , V_63 , V_58 ) ;
if ( V_62 != V_63 ) {
F_16 ( L_22 , V_24 ) ;
goto V_70;
}
if ( V_4 -> V_69 . V_71 )
goto V_72;
if ( ( V_65 + V_63 + V_4 -> V_69 . V_73 ) != V_61 ) {
F_16 ( L_23
L_24
L_25 ,
V_24 ,
V_65 ,
V_63 ,
V_4 -> V_69 . V_73 ,
V_61 ) ;
goto V_70;
}
if ( ( V_4 -> V_69 . type != V_74 ) &&
( V_4 -> V_69 . V_73 != 0 ) ) {
F_16 ( L_26 ,
V_24 ,
V_4 -> V_69 . type ) ;
goto V_70;
}
if ( ( V_4 -> V_69 . type == V_74 ) &&
( V_4 -> V_69 . V_73 == 0 ) ) {
F_16 ( L_27 ,
V_24 ,
V_4 -> V_69 . type ) ;
goto V_70;
}
if ( V_4 -> V_69 . type != V_74 )
goto V_72;
V_4 -> V_69 . V_75 =
F_37 ( V_4 -> V_69 . V_73 ) ;
if ( V_4 -> V_69 . V_75 == NULL ) {
F_16 ( L_28 ,
V_24 ) ;
goto V_76;
}
memset ( V_4 -> V_69 . V_75 , 0 , V_4 -> V_69 . V_73 ) ;
V_62 = F_36 ( V_4 -> V_69 . V_75 ,
V_4 -> V_69 . V_73 ,
V_58 ) ;
if ( V_62 != V_4 -> V_69 . V_73 ) {
F_16 ( L_29 , V_24 ) ;
F_38 ( V_4 -> V_69 . V_75 ) ;
goto V_70;
}
V_72:
F_6 ( & V_4 -> V_42 ) ;
if ( F_22 ( F_39 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_42 ) ;
F_40 ( V_4 ) ;
} else if ( F_22 ( F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_42 ) ;
F_29 ( & V_4 -> V_49 ) ;
} else {
F_41 ( V_4 ) ;
F_17 ( V_27 ,
L_30 ,
V_24 ,
F_25 ( V_4 ) ,
V_4 -> V_50 ,
V_51 -> V_52 ) ;
F_11 ( & V_4 -> V_42 ) ;
}
return V_20 ;
V_70:
V_4 -> V_69 . V_71 = - ( V_77 | 9 ) ;
V_20 = - V_54 ;
goto V_72;
V_76:
V_4 -> V_69 . V_71 = - ( V_77 | 8 ) ;
V_20 = - V_78 ;
goto V_72;
}
static int F_42 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
int V_11 = 0 ;
F_17 ( V_27 ,
L_31 ,
V_24 ) ;
F_18 ( & V_28 ) ;
F_43 () ;
V_29 = - 1 ;
V_11 = F_12 () ;
F_17 ( V_27 , L_32 ,
( V_11 ? L_33 : L_34 ) ) ;
F_44 () ;
F_45 () ;
F_46 () ;
F_17 ( V_27 ,
L_35 ) ;
V_29 = 0 ;
F_20 ( & V_28 ) ;
return 0 ;
}
int F_47 ( void )
{
int V_79 ;
F_18 ( & V_28 ) ;
V_79 = V_29 == 1 ? 0 : - V_80 ;
F_20 ( & V_28 ) ;
return V_79 ;
}
bool F_48 ( void )
{
return V_29 == 1 ;
}
static inline long F_49 ( unsigned int V_81 )
{
if ( F_50 ( V_81 ) != V_82 ) {
F_16 ( L_36 ,
V_81 ,
F_50 ( V_81 ) ,
V_82 ) ;
return - V_21 ;
}
if ( F_51 ( V_81 ) >= V_83 || F_51 ( V_81 ) <= 0 ) {
F_16 ( L_37 ,
F_51 ( V_81 ) , V_83 ) ;
return - V_84 ;
}
return 0 ;
}
static long F_52 ( unsigned int V_81 , unsigned long V_85 )
{
static T_2 V_36 = V_37 ;
static T_2 V_86 = V_39 ;
static T_2 V_87 = V_66 ;
struct V_88 V_89 ;
int V_20 = 0 ;
struct V_90 V_91 = { 0 } ;
struct V_92 V_93 = { 0 , 0 } ;
int V_94 = 1 ;
struct V_12 * V_13 ;
switch ( V_81 ) {
case V_95 :
return ( ( F_53 ( V_36 , ( T_2 T_4 * ) V_85 ) == - V_54 ) ?
- V_80 :
0 ) ;
case V_96 :
return ( ( F_53 ( V_86 ,
( T_2 T_4 * ) V_85 ) == - V_54 ) ?
- V_80 :
0 ) ;
case V_97 :
return ( ( F_53 ( V_87 ,
( T_2 T_4 * ) V_85 ) == - V_54 ) ?
- V_80 :
0 ) ;
case V_98 :
V_20 = F_54 ( & V_89 ,
(struct V_88 T_4 * )
V_85 ,
sizeof( struct V_88 ) ) ;
return V_20 ? - V_80 : F_55 ( & V_89 ) ;
case V_99 :
F_17 ( V_27 ,
L_38 ,
V_24 ) ;
V_20 = F_56 ( & V_100 ) ;
if ( V_20 < 0 )
return V_20 ;
F_17 ( V_27 ,
L_39 ,
V_24 ) ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
if ( ! V_13 -> V_7 . V_101 )
continue;
F_17 ( V_27 ,
L_40 ,
V_24 ,
V_13 ) ;
F_11 ( & V_14 ) ;
V_20 = F_57 ( V_13 ) ;
F_6 ( & V_14 ) ;
if ( V_20 ) {
F_17 ( V_27 ,
L_41 ,
V_13 ) ;
break;
}
}
F_11 ( & V_14 ) ;
F_17 ( V_27 ,
L_42 ,
V_24 ) ;
F_20 ( & V_100 ) ;
return V_20 ;
case V_102 :
V_20 = F_28 ( ( void T_4 * ) V_85 ,
& V_94 ,
sizeof( V_94 ) ) ;
if ( V_20 != 0 )
return - V_80 ;
else
return V_20 ;
case V_103 :
V_20 = F_54 ( & V_93 ,
( void T_4 * ) V_85 ,
sizeof( struct V_92 ) ) ;
if ( V_20 != 0 )
return - V_80 ;
V_104 . V_105 = V_93 . V_106 ;
V_104 . V_107 = V_93 . V_108 ;
F_58 ( L_43
L_44 ,
V_24 ,
( unsigned long long ) V_104 . V_105 ,
( unsigned long long ) V_104 . V_107 ) ;
return V_20 ;
case V_109 :
V_20 = F_54 ( & V_110 ,
( void T_4 * ) V_85 ,
V_111 ) ;
V_110 [ V_111 - 1 ] =
'\0' ;
if ( V_20 != 0 ) {
F_58 ( L_45 ,
V_24 ) ;
return - V_80 ;
}
F_58 ( L_46 ,
V_24 ) ;
if ( ! V_112 ) {
F_59 ( V_113 ) ;
if ( F_60 ( 0 ) ) {
F_16 ( L_47 ,
V_24 ) ;
return - V_80 ;
}
F_61 ( V_114 ) ;
V_114 =
F_62 (
V_115 ,
0444 ,
V_116 ,
V_113 ,
& V_117 ) ;
if ( ! V_114 ) {
F_16 ( L_48
L_49 ,
V_24 ,
V_115 ) ;
return - V_80 ;
}
}
F_63 ( & V_104 , 1 ) ;
F_61 ( V_118 ) ;
F_64 () ;
V_112 ++ ;
return V_20 ;
case V_119 :
V_20 = F_54 ( & V_91 ,
( void T_4 * ) V_85 ,
sizeof( V_91 ) ) ;
if ( V_20 != 0 )
return - V_80 ;
if ( V_91 . V_120 == V_121 ) {
if ( ( V_91 . V_122 == 0 )
&& ( V_123 ) ) {
return 0 ;
}
F_63 ( & V_91 . V_122 ,
V_91 . V_120 ) ;
V_124 = V_91 . V_122 ;
F_58 ( L_50
L_51 ,
V_24 ,
V_125 ,
( unsigned long long ) V_124 ) ;
} else if ( V_91 . V_120 == V_126 ) {
F_63 ( & V_91 . V_122 ,
V_91 . V_120 ) ;
F_58 ( L_52
L_51 ,
V_24 ,
V_127 ,
F_24 ( V_91 . V_122 ) ) ;
} else {
F_65 ( L_53 ) ;
return - V_21 ;
}
return V_20 ;
default:
return - V_84 ;
}
return - V_84 ;
}
static long F_66 ( struct V_19 * V_19 ,
unsigned int V_81 , unsigned long V_85 )
{
long V_20 ;
V_20 = F_49 ( V_81 ) ;
if ( V_20 < 0 )
return ( int ) V_20 ;
return ( int ) F_52 ( V_81 , V_85 ) ;
}
static unsigned long F_67 ( unsigned long args , long * error )
{
struct V_128 T_4 * V_129 = ( void T_4 * ) args ;
struct V_88 T_4 * V_130 =
F_68 ( sizeof( * V_130 ) ) ;
T_8 V_131 ;
* error = 0 ;
if ( F_69 ( V_131 , & V_129 -> V_132 ) )
goto V_133;
if ( F_53 ( F_70 ( V_131 ) , & V_130 -> V_132 ) )
goto V_133;
if ( F_71 ( & V_130 -> V_134 , & V_129 -> V_134 , sizeof( T_2 ) ) )
goto V_133;
if ( F_71 ( & V_130 -> V_135 , & V_129 -> V_135 , sizeof( T_2 ) ) )
goto V_133;
if ( F_71 ( & V_130 -> V_31 , & V_129 -> V_31 , sizeof( T_2 ) ) )
goto V_133;
return ( unsigned long ) V_130 ;
V_133:
* error = - V_54 ;
return 0 ;
}
static long F_72 ( struct V_19 * V_136 , unsigned int V_137 ,
unsigned long args )
{
long V_20 ;
unsigned long V_85 = args ;
V_20 = F_49 ( V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_137 == V_98 ) {
V_85 = F_67 ( args , & V_20 ) ;
if ( V_20 < 0 ) {
F_16 ( L_54 ) ;
return V_20 ;
}
}
return F_52 ( V_137 , V_85 ) ;
}
int F_73 ( void )
{
V_138 = F_74 ( 0 ,
V_139 ,
& V_140 ) ;
if ( V_138 < 0 ) {
F_17 ( V_27 ,
L_55 ,
V_139 , V_138 ) ;
return V_138 ;
}
F_17 ( V_27 ,
L_56 ,
V_139 ) ;
F_17 ( V_27 , L_57 ,
V_139 , V_138 ) ;
return 0 ;
}
void F_75 ( void )
{
F_76 ( V_138 , V_139 ) ;
F_17 ( V_27 ,
L_58 ,
V_139 ) ;
}
static unsigned int F_77 ( struct V_19 * V_19 ,
struct V_141 * V_142 )
{
int V_143 = 0 ;
F_78 ( V_19 , & V_144 , V_142 ) ;
if ( ! F_79 ( & V_53 ) )
V_143 |= V_145 ;
return V_143 ;
}
