static void T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_4 , & V_5 ) ;
else
F_3 ( & V_2 -> V_4 , & V_5 ) ;
}
void * F_4 ( void * V_6 , void * V_7 , int * V_8 )
{
struct V_9 * V_10 ;
* V_8 = 0 ;
while ( V_6 < V_7 ) {
V_10 = V_6 ;
if ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_13 ||
V_10 -> V_11 == V_14 )
( * V_8 ) ++ ;
else if ( V_10 -> V_11 != V_15 &&
V_10 -> V_11 != V_16 ) {
F_5 ( L_1 ) ;
}
V_6 += V_10 -> V_17 ;
}
if ( * V_8 == 0 )
return NULL ;
return F_6 ( * V_8 , sizeof( struct V_18 ) , V_19 ) ;
}
void F_7 ( struct V_18 * * V_20 , int * V_8 )
{
int V_21 ;
struct V_22 * V_23 ;
if ( * V_20 && * V_8 ) {
F_8 (*devices, *cnt, i, tmp_dev)
F_9 ( V_23 ) ;
F_10 ( * V_20 ) ;
}
* V_20 = NULL ;
* V_8 = 0 ;
}
static struct V_24 *
F_11 ( struct V_25 * V_26 , unsigned long V_27 )
{
int V_28 = 0 ;
T_2 V_29 ;
struct V_25 * V_30 ;
struct V_24 * V_31 ;
F_12 ( V_26 -> V_32 ) ;
if ( V_27 == V_33 )
for ( V_30 = V_26 ; V_30 ; V_30 = V_30 -> V_34 -> V_35 )
V_28 ++ ;
V_29 = sizeof( * V_31 ) + V_28 * sizeof( struct V_36 ) ;
if ( V_29 <= sizeof( V_37 ) ) {
V_31 = (struct V_24 * ) V_37 ;
} else {
V_31 = F_13 ( V_29 , V_19 ) ;
if ( ! V_31 ) {
F_5 ( L_2
L_3 , F_14 ( V_26 ) ) ;
if ( V_38 == 0 )
V_38 = - V_39 ;
return NULL ;
}
}
V_31 -> V_27 = V_27 ;
V_31 -> V_26 = V_26 ;
V_31 -> V_40 = F_15 ( V_26 -> V_34 ) ;
V_31 -> V_28 = V_28 ;
if ( V_27 == V_33 ) {
for ( V_30 = V_26 ; V_30 ; V_30 = V_30 -> V_34 -> V_35 ) {
V_28 -- ;
V_31 -> V_41 [ V_28 ] . V_34 = V_30 -> V_34 -> V_42 ;
V_31 -> V_41 [ V_28 ] . V_22 = F_16 ( V_30 -> V_43 ) ;
V_31 -> V_41 [ V_28 ] . V_44 = F_17 ( V_30 -> V_43 ) ;
if ( F_18 ( V_30 -> V_34 ) )
V_31 -> V_34 = V_30 -> V_34 -> V_42 ;
}
}
return V_31 ;
}
static inline void F_19 ( struct V_24 * V_31 )
{
if ( ( void * ) V_31 != V_37 )
F_10 ( V_31 ) ;
}
static bool F_20 ( struct V_24 * V_31 , int V_34 ,
struct V_36 * V_41 , int V_45 )
{
int V_21 ;
if ( V_31 -> V_34 != V_34 )
goto V_46;
if ( V_31 -> V_28 != V_45 )
goto V_46;
for ( V_21 = 0 ; V_21 < V_45 ; V_21 ++ ) {
if ( V_41 [ V_21 ] . V_22 != V_31 -> V_41 [ V_21 ] . V_22 ||
V_41 [ V_21 ] . V_44 != V_31 -> V_41 [ V_21 ] . V_44 )
goto V_46;
}
return true ;
V_46:
if ( V_45 != 1 )
return false ;
V_21 = V_31 -> V_28 - 1 ;
if ( V_34 == V_31 -> V_41 [ V_21 ] . V_34 &&
V_41 [ 0 ] . V_22 == V_31 -> V_41 [ V_21 ] . V_22 &&
V_41 [ 0 ] . V_44 == V_31 -> V_41 [ V_21 ] . V_44 ) {
F_21 ( V_47 L_4 ,
V_34 , V_41 [ 0 ] . V_22 , V_41 [ 0 ] . V_44 ) ;
return true ;
}
return false ;
}
int F_22 ( struct V_24 * V_31 ,
void * V_6 , void * V_7 , T_3 V_48 ,
struct V_18 * V_20 ,
int V_49 )
{
int V_21 , V_28 ;
struct V_22 * V_30 , * V_26 = & V_31 -> V_26 -> V_26 ;
struct V_9 * V_10 ;
struct V_36 * V_41 ;
if ( V_48 != V_31 -> V_40 )
return 0 ;
for (; V_6 < V_7 ; V_6 += V_10 -> V_17 ) {
V_10 = V_6 ;
if ( V_10 -> V_11 != V_13 &&
V_10 -> V_11 != V_14 )
continue;
V_41 = (struct V_36 * ) ( V_10 + 1 ) ;
V_28 = ( V_10 -> V_17 - sizeof( * V_10 ) ) / sizeof( * V_41 ) ;
if ( ! F_20 ( V_31 , V_10 -> V_34 , V_41 , V_28 ) )
continue;
if ( ( V_10 -> V_11 == V_13 ) ^
( V_31 -> V_26 -> V_50 == V_51 ) ) {
F_5 ( L_5 ,
F_14 ( V_31 -> V_26 ) ) ;
return - V_52 ;
}
F_23 (devices, devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_20 [ V_21 ] . V_34 = V_31 -> V_26 -> V_34 -> V_42 ;
V_20 [ V_21 ] . V_43 = V_31 -> V_26 -> V_43 ;
F_24 ( V_20 [ V_21 ] . V_26 ,
F_25 ( V_26 ) ) ;
return 1 ;
}
F_12 ( V_21 >= V_49 ) ;
}
return 0 ;
}
int F_26 ( struct V_24 * V_31 , T_3 V_48 ,
struct V_18 * V_20 , int V_45 )
{
int V_53 ;
struct V_22 * V_30 ;
if ( V_31 -> V_40 != V_48 )
return 0 ;
F_8 (devices, count, index, tmp)
if ( V_30 == & V_31 -> V_26 -> V_26 ) {
F_27 ( V_20 [ V_53 ] . V_26 , NULL ) ;
F_28 () ;
F_9 ( V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_29 ( struct V_24 * V_31 )
{
int V_54 = 0 ;
struct V_1 * V_55 ;
struct V_56 * V_2 ;
F_30 (dmaru) {
if ( V_55 -> V_3 )
continue;
V_2 = F_31 ( V_55 -> V_57 ,
struct V_56 , V_58 ) ;
V_54 = F_22 ( V_31 , ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_58 . V_17 ,
V_55 -> V_48 ,
V_55 -> V_20 , V_55 -> V_49 ) ;
if ( V_54 != 0 )
break;
}
if ( V_54 >= 0 )
V_54 = F_32 ( V_31 ) ;
if ( V_54 < 0 && V_38 == 0 )
V_38 = V_54 ;
return V_54 ;
}
static void F_33 ( struct V_24 * V_31 )
{
struct V_1 * V_55 ;
F_30 (dmaru)
if ( F_26 ( V_31 , V_55 -> V_48 ,
V_55 -> V_20 , V_55 -> V_49 ) )
break;
F_32 ( V_31 ) ;
}
static int F_34 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
struct V_25 * V_63 = F_35 ( V_62 ) ;
struct V_24 * V_31 ;
if ( V_63 -> V_32 )
return V_64 ;
if ( V_61 != V_33 && V_61 != V_65 )
return V_64 ;
V_31 = F_11 ( V_63 , V_61 ) ;
if ( ! V_31 )
return V_64 ;
F_36 ( & V_66 ) ;
if ( V_61 == V_33 )
F_29 ( V_31 ) ;
else if ( V_61 == V_65 )
F_33 ( V_31 ) ;
F_37 ( & V_66 ) ;
F_19 ( V_31 ) ;
return V_67 ;
}
static int T_1
F_38 ( struct V_68 * V_58 )
{
struct V_56 * V_2 ;
struct V_1 * V_55 ;
int V_54 = 0 ;
V_2 = (struct V_56 * ) V_58 ;
V_55 = F_13 ( sizeof( * V_55 ) , V_19 ) ;
if ( ! V_55 )
return - V_39 ;
V_55 -> V_57 = V_58 ;
V_55 -> V_69 = V_2 -> V_70 ;
V_55 -> V_48 = V_2 -> V_48 ;
V_55 -> V_3 = V_2 -> V_71 & 0x1 ;
V_55 -> V_20 = F_4 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_58 . V_17 ,
& V_55 -> V_49 ) ;
if ( V_55 -> V_49 && V_55 -> V_20 == NULL ) {
F_10 ( V_55 ) ;
return - V_39 ;
}
V_54 = F_39 ( V_55 ) ;
if ( V_54 ) {
F_7 ( & V_55 -> V_20 ,
& V_55 -> V_49 ) ;
F_10 ( V_55 ) ;
return V_54 ;
}
F_1 ( V_55 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_55 )
{
if ( V_55 -> V_20 && V_55 -> V_49 )
F_7 ( & V_55 -> V_20 , & V_55 -> V_49 ) ;
if ( V_55 -> V_72 )
F_41 ( V_55 -> V_72 ) ;
F_10 ( V_55 ) ;
}
static int T_1 F_42 ( struct V_68 * V_58 )
{
struct V_73 * V_74 = ( void * ) V_58 ;
if ( F_43 ( V_74 -> V_75 , V_58 -> V_17 - 8 ) == V_58 -> V_17 - 8 ) {
F_44 ( 1 , V_76 ,
L_6
L_7 ,
F_45 ( V_77 ) ,
F_45 ( V_78 ) ,
F_45 ( V_79 ) ) ;
return - V_52 ;
}
F_21 ( L_8 , V_74 -> V_80 ,
V_74 -> V_75 ) ;
return 0 ;
}
static int T_1
F_46 ( struct V_68 * V_58 )
{
struct V_81 * V_82 ;
struct V_1 * V_2 ;
V_82 = (struct V_81 * ) V_58 ;
F_30 (drhd) {
if ( V_2 -> V_69 == V_82 -> V_83 ) {
int V_84 = F_47 ( V_82 -> V_85 ) ;
if ( ! F_48 ( V_84 ) )
V_84 = - 1 ;
V_2 -> V_72 -> V_84 = V_84 ;
return 0 ;
}
}
F_44 (
1 , V_76 ,
L_9
L_7 ,
V_2 -> V_69 ,
F_45 ( V_77 ) ,
F_45 ( V_78 ) ,
F_45 ( V_79 ) ) ;
return 0 ;
}
static void T_1
F_49 ( struct V_68 * V_58 )
{
struct V_56 * V_2 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_81 * V_82 ;
switch ( V_58 -> type ) {
case V_90 :
V_2 = F_31 ( V_58 , struct V_56 ,
V_58 ) ;
F_21 ( L_10 ,
( unsigned long long ) V_2 -> V_70 , V_2 -> V_71 ) ;
break;
case V_91 :
V_87 = F_31 ( V_58 , struct V_86 ,
V_58 ) ;
F_21 ( L_11 ,
( unsigned long long ) V_87 -> V_83 ,
( unsigned long long ) V_87 -> V_92 ) ;
break;
case V_93 :
V_89 = F_31 ( V_58 , struct V_88 , V_58 ) ;
F_21 ( L_12 , V_89 -> V_71 ) ;
break;
case V_94 :
V_82 = F_31 ( V_58 , struct V_81 , V_58 ) ;
F_21 ( L_13 ,
( unsigned long long ) V_82 -> V_83 ,
V_82 -> V_85 ) ;
break;
case V_95 :
break;
}
}
static int T_1 F_50 ( void )
{
T_4 V_96 = V_97 ;
V_96 = F_51 ( V_98 , 0 ,
(struct V_99 * * ) & V_100 ,
& V_101 ) ;
if ( F_52 ( V_96 ) && ! V_100 ) {
F_5 ( L_14 ) ;
V_96 = V_102 ;
}
return ( F_52 ( V_96 ) ? 1 : 0 ) ;
}
static int T_1
F_53 ( void )
{
struct V_103 * V_104 ;
struct V_68 * V_105 ;
int V_54 = 0 ;
int V_106 = 0 ;
F_50 () ;
V_100 = F_54 ( V_100 ) ;
V_104 = (struct V_103 * ) V_100 ;
if ( ! V_104 )
return - V_107 ;
if ( V_104 -> V_108 < V_109 - 1 ) {
F_5 ( L_15 ) ;
return - V_52 ;
}
F_21 ( L_16 , V_104 -> V_108 + 1 ) ;
V_105 = (struct V_68 * ) ( V_104 + 1 ) ;
while ( ( ( unsigned long ) V_105 ) <
( ( ( unsigned long ) V_104 ) + V_100 -> V_17 ) ) {
if ( V_105 -> V_17 == 0 ) {
F_5 ( L_17 ) ;
V_54 = - V_52 ;
break;
}
F_49 ( V_105 ) ;
switch ( V_105 -> type ) {
case V_90 :
V_106 ++ ;
V_54 = F_38 ( V_105 ) ;
break;
case V_91 :
V_54 = F_55 ( V_105 ) ;
break;
case V_93 :
V_54 = F_56 ( V_105 ) ;
break;
case V_94 :
#ifdef F_57
V_54 = F_46 ( V_105 ) ;
#endif
break;
case V_95 :
V_54 = F_42 ( V_105 ) ;
break;
default:
F_5 ( L_18 ,
V_105 -> type ) ;
V_54 = 0 ;
break;
}
if ( V_54 )
break;
V_105 = ( ( void * ) V_105 + V_105 -> V_17 ) ;
}
if ( V_106 == 0 )
F_5 ( V_47 L_19 ) ;
return V_54 ;
}
static int F_58 ( struct V_18 V_20 [] ,
int V_8 , struct V_25 * V_26 )
{
int V_53 ;
struct V_22 * V_30 ;
while ( V_26 ) {
F_8 (devices, cnt, index, tmp)
if ( F_59 ( V_30 ) && V_26 == F_35 ( V_30 ) )
return 1 ;
V_26 = V_26 -> V_34 -> V_35 ;
}
return 0 ;
}
struct V_1 *
F_60 ( struct V_25 * V_26 )
{
struct V_1 * V_55 ;
struct V_56 * V_2 ;
V_26 = F_61 ( V_26 ) ;
F_62 () ;
F_30 (dmaru) {
V_2 = F_31 ( V_55 -> V_57 ,
struct V_56 ,
V_58 ) ;
if ( V_55 -> V_3 &&
V_2 -> V_48 == F_15 ( V_26 -> V_34 ) )
goto V_110;
if ( F_58 ( V_55 -> V_20 ,
V_55 -> V_49 , V_26 ) )
goto V_110;
}
V_55 = NULL ;
V_110:
F_63 () ;
return V_55 ;
}
static void T_1 F_64 ( T_5 V_80 ,
struct V_111 * V_112 )
{
struct V_1 * V_55 ;
struct V_56 * V_2 ;
struct V_9 * V_10 ;
struct V_22 * V_30 ;
int V_21 ;
struct V_36 * V_41 ;
F_30 (dmaru) {
V_2 = F_31 ( V_55 -> V_57 ,
struct V_56 ,
V_58 ) ;
for ( V_10 = ( void * ) ( V_2 + 1 ) ;
( unsigned long ) V_10 < ( ( unsigned long ) V_2 ) + V_2 -> V_58 . V_17 ;
V_10 = ( ( void * ) V_10 ) + V_10 -> V_17 ) {
if ( V_10 -> V_11 != V_12 )
continue;
if ( V_10 -> V_113 != V_80 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_21 ( L_20 ,
F_65 ( & V_112 -> V_26 ) , V_55 -> V_69 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_44 ) ;
F_23 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_55 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_55 -> V_20 [ V_21 ] . V_43 = F_66 ( V_41 -> V_22 ,
V_41 -> V_44 ) ;
F_24 ( V_55 -> V_20 [ V_21 ] . V_26 ,
F_25 ( & V_112 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_55 -> V_49 ) ;
}
}
F_5 ( L_21 ,
V_80 , F_65 ( & V_112 -> V_26 ) ) ;
}
static int T_1 F_67 ( void )
{
struct V_73 * V_74 ;
if ( V_100 == NULL )
return - V_107 ;
for ( V_74 = ( void * ) V_100 + sizeof( struct V_103 ) ;
( ( unsigned long ) V_74 ) < ( ( unsigned long ) V_100 ) + V_100 -> V_17 ;
V_74 = ( ( void * ) V_74 ) + V_74 -> V_58 . V_17 ) {
if ( V_74 -> V_58 . type == V_95 ) {
T_6 V_114 ;
struct V_111 * V_112 ;
if ( ! F_52 ( F_68 ( V_115 ,
V_74 -> V_75 ,
& V_114 ) ) ) {
F_69 ( L_22 ,
V_74 -> V_75 ) ;
continue;
}
if ( F_70 ( V_114 , & V_112 ) ) {
F_69 ( L_23 ,
V_74 -> V_75 ) ;
continue;
}
F_64 ( V_74 -> V_80 , V_112 ) ;
}
}
return 0 ;
}
int T_1 F_71 ( void )
{
struct V_25 * V_26 = NULL ;
struct V_24 * V_31 ;
if ( V_38 != 1 )
return V_38 ;
if ( F_72 ( & V_5 ) ) {
V_38 = - V_107 ;
} else {
V_38 = 0 ;
F_67 () ;
F_73 (dev) {
if ( V_26 -> V_32 )
continue;
V_31 = F_11 ( V_26 ,
V_33 ) ;
if ( ! V_31 ) {
return V_38 ;
} else {
F_29 ( V_31 ) ;
F_19 ( V_31 ) ;
}
}
F_74 ( & V_116 , & V_117 ) ;
}
return V_38 ;
}
int T_1 F_75 ( void )
{
static int V_118 ;
int V_54 ;
if ( V_118 == 0 ) {
V_54 = F_53 () ;
if ( V_54 < 0 ) {
if ( V_54 != - V_107 )
F_21 ( L_24 ) ;
} else if ( F_72 ( & V_5 ) ) {
F_21 ( L_25 ) ;
V_54 = - V_107 ;
}
if ( V_54 < 0 )
V_118 = V_54 ;
else
V_118 = 1 ;
}
return V_118 < 0 ? V_118 : 0 ;
}
static void F_76 ( T_7 V_119 , const char * V_120 )
{
F_77 (
1 , V_76 ,
L_26
L_7 ,
V_119 , V_120 ,
F_45 ( V_77 ) ,
F_45 ( V_78 ) ,
F_45 ( V_79 ) ) ;
}
static int T_1 F_78 ( void )
{
struct V_103 * V_104 ;
struct V_68 * V_105 ;
struct V_56 * V_2 ;
V_104 = (struct V_103 * ) V_100 ;
V_105 = (struct V_68 * ) ( V_104 + 1 ) ;
while ( ( ( unsigned long ) V_105 ) <
( ( ( unsigned long ) V_104 ) + V_100 -> V_17 ) ) {
if ( V_105 -> V_17 == 0 ) {
F_5 ( L_17 ) ;
return 0 ;
}
if ( V_105 -> type == V_90 ) {
void T_8 * V_119 ;
T_7 V_121 , V_122 ;
V_2 = ( void * ) V_105 ;
if ( ! V_2 -> V_70 ) {
F_76 ( 0 , L_27 ) ;
goto V_123;
}
V_119 = F_79 ( V_2 -> V_70 , V_124 ) ;
if ( ! V_119 ) {
F_80 ( L_28 , V_2 -> V_70 ) ;
goto V_123;
}
V_121 = F_81 ( V_119 + V_125 ) ;
V_122 = F_81 ( V_119 + V_126 ) ;
F_82 ( V_119 , V_124 ) ;
if ( V_121 == ( V_127 ) - 1 && V_122 == ( V_127 ) - 1 ) {
F_76 ( V_2 -> V_70 ,
L_29 ) ;
goto V_123;
}
}
V_105 = ( ( void * ) V_105 + V_105 -> V_17 ) ;
}
return 1 ;
V_123:
return 0 ;
}
int T_1 F_83 ( void )
{
int V_54 ;
F_36 ( & V_66 ) ;
V_54 = F_50 () ;
if ( V_54 )
V_54 = F_78 () ;
{
if ( V_54 && ! V_128 && ! V_129 && ! V_130 ) {
V_129 = 1 ;
F_84 () ;
}
#ifdef F_85
if ( V_54 )
V_131 . V_72 . V_132 = V_133 ;
#endif
}
F_86 ( ( void T_8 * ) V_100 , V_101 ) ;
V_100 = NULL ;
F_37 ( & V_66 ) ;
return V_54 ? 1 : - V_107 ;
}
static void F_87 ( struct V_134 * V_72 )
{
F_88 ( V_72 -> V_135 ) ;
F_89 ( V_72 -> V_136 , V_72 -> V_137 ) ;
}
static int F_90 ( struct V_134 * V_72 , T_7 V_138 )
{
int V_139 , V_140 = 0 ;
V_72 -> V_136 = V_138 ;
V_72 -> V_137 = V_124 ;
if ( ! F_91 ( V_72 -> V_136 , V_72 -> V_137 , V_72 -> V_141 ) ) {
F_69 ( L_30 ) ;
V_140 = - V_142 ;
goto V_110;
}
V_72 -> V_135 = F_92 ( V_72 -> V_136 , V_72 -> V_137 ) ;
if ( ! V_72 -> V_135 ) {
F_69 ( L_31 ) ;
V_140 = - V_39 ;
goto V_143;
}
V_72 -> V_121 = F_81 ( V_72 -> V_135 + V_125 ) ;
V_72 -> V_122 = F_81 ( V_72 -> V_135 + V_126 ) ;
if ( V_72 -> V_121 == ( V_127 ) - 1 && V_72 -> V_122 == ( V_127 ) - 1 ) {
V_140 = - V_52 ;
F_76 ( V_138 , L_29 ) ;
goto V_144;
}
V_139 = F_93 ( int , F_94 ( V_72 -> V_122 ) ,
F_95 ( V_72 -> V_121 ) ) ;
V_139 = F_96 ( V_139 ) ;
if ( V_139 > V_72 -> V_137 ) {
F_88 ( V_72 -> V_135 ) ;
F_89 ( V_72 -> V_136 , V_72 -> V_137 ) ;
V_72 -> V_137 = V_139 ;
if ( ! F_91 ( V_72 -> V_136 , V_72 -> V_137 ,
V_72 -> V_141 ) ) {
F_69 ( L_30 ) ;
V_140 = - V_142 ;
goto V_110;
}
V_72 -> V_135 = F_92 ( V_72 -> V_136 , V_72 -> V_137 ) ;
if ( ! V_72 -> V_135 ) {
F_69 ( L_31 ) ;
V_140 = - V_39 ;
goto V_143;
}
}
V_140 = 0 ;
goto V_110;
V_144:
F_88 ( V_72 -> V_135 ) ;
V_143:
F_89 ( V_72 -> V_136 , V_72 -> V_137 ) ;
V_110:
return V_140 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_134 * V_72 ;
T_9 V_145 , V_146 ;
static int V_147 = 0 ;
int V_148 = 0 ;
int V_149 = 0 ;
int V_140 ;
if ( ! V_2 -> V_69 ) {
F_76 ( 0 , L_27 ) ;
return - V_52 ;
}
V_72 = F_13 ( sizeof( * V_72 ) , V_19 ) ;
if ( ! V_72 )
return - V_39 ;
V_72 -> V_150 = V_147 ++ ;
sprintf ( V_72 -> V_141 , L_32 , V_72 -> V_150 ) ;
V_140 = F_90 ( V_72 , V_2 -> V_69 ) ;
if ( V_140 ) {
F_69 ( L_33 , V_72 -> V_141 ) ;
goto error;
}
V_140 = - V_52 ;
V_148 = F_97 ( V_72 ) ;
if ( V_148 < 0 ) {
F_69 ( L_34 ,
V_72 -> V_150 ) ;
goto V_151;
}
V_149 = F_98 ( V_72 ) ;
if ( V_149 < 0 ) {
F_69 ( L_35 ,
V_72 -> V_150 ) ;
goto V_151;
}
V_72 -> V_148 = V_148 ;
V_72 -> V_149 = V_149 ;
V_72 -> V_48 = V_2 -> V_48 ;
V_72 -> V_84 = - 1 ;
V_145 = F_99 ( V_72 -> V_135 + V_152 ) ;
F_21 ( L_36 ,
V_72 -> V_150 ,
( unsigned long long ) V_2 -> V_69 ,
F_100 ( V_145 ) , F_101 ( V_145 ) ,
( unsigned long long ) V_72 -> V_121 ,
( unsigned long long ) V_72 -> V_122 ) ;
V_146 = F_99 ( V_72 -> V_135 + V_153 ) ;
if ( V_146 & V_154 )
V_72 -> V_155 |= V_156 ;
if ( V_146 & V_157 )
V_72 -> V_155 |= V_158 ;
if ( V_146 & V_159 )
V_72 -> V_155 |= V_160 ;
F_102 ( & V_72 -> V_161 ) ;
V_2 -> V_72 = V_72 ;
if ( V_162 )
V_72 -> V_163 = F_103 ( NULL , V_72 ,
V_164 ,
V_72 -> V_141 ) ;
return 0 ;
V_151:
F_87 ( V_72 ) ;
error:
F_10 ( V_72 ) ;
return V_140 ;
}
static void F_41 ( struct V_134 * V_72 )
{
F_104 ( V_72 -> V_163 ) ;
if ( V_72 -> V_165 ) {
F_105 ( V_72 -> V_165 , V_72 ) ;
F_106 ( V_72 -> V_165 , NULL ) ;
F_107 ( V_72 -> V_165 ) ;
}
if ( V_72 -> V_166 ) {
F_108 ( ( unsigned long ) V_72 -> V_166 -> V_167 ) ;
F_10 ( V_72 -> V_166 -> V_168 ) ;
F_10 ( V_72 -> V_166 ) ;
}
if ( V_72 -> V_135 )
F_87 ( V_72 ) ;
F_10 ( V_72 ) ;
}
static inline void F_109 ( struct V_169 * V_166 )
{
while ( V_166 -> V_168 [ V_166 -> V_170 ] == V_171 ||
V_166 -> V_168 [ V_166 -> V_170 ] == V_172 ) {
V_166 -> V_168 [ V_166 -> V_170 ] = V_173 ;
V_166 -> V_170 = ( V_166 -> V_170 + 1 ) % V_174 ;
V_166 -> V_175 ++ ;
}
}
static int F_110 ( struct V_134 * V_72 , int V_53 )
{
T_9 V_176 ;
int V_177 , V_178 ;
struct V_169 * V_166 = V_72 -> V_166 ;
int V_179 = ( V_53 + 1 ) % V_174 ;
if ( V_166 -> V_168 [ V_179 ] == V_172 )
return - V_180 ;
V_176 = F_99 ( V_72 -> V_135 + V_181 ) ;
if ( V_176 & V_182 ) {
V_177 = F_99 ( V_72 -> V_135 + V_183 ) ;
if ( ( V_177 >> V_184 ) == V_53 ) {
F_69 ( L_37
L_38 ,
( unsigned long long ) V_166 -> V_167 [ V_53 ] . V_185 ,
( unsigned long long ) V_166 -> V_167 [ V_53 ] . V_186 ) ;
memcpy ( & V_166 -> V_167 [ V_53 ] , & V_166 -> V_167 [ V_179 ] ,
sizeof( struct V_187 ) ) ;
F_111 ( V_72 , & V_166 -> V_167 [ V_53 ] ,
sizeof( struct V_187 ) ) ;
F_112 ( V_182 , V_72 -> V_135 + V_181 ) ;
return - V_52 ;
}
}
if ( V_176 & V_188 ) {
V_177 = F_99 ( V_72 -> V_135 + V_183 ) ;
V_177 = ( ( V_177 >> V_184 ) - 1 + V_174 ) % V_174 ;
V_177 |= 1 ;
V_178 = F_99 ( V_72 -> V_135 + V_189 ) ;
V_178 = ( ( V_178 >> V_184 ) - 1 + V_174 ) % V_174 ;
F_112 ( V_188 , V_72 -> V_135 + V_181 ) ;
do {
if ( V_166 -> V_168 [ V_177 ] == V_190 )
V_166 -> V_168 [ V_177 ] = V_172 ;
V_177 = ( V_177 - 2 + V_174 ) % V_174 ;
} while ( V_177 != V_178 );
if ( V_166 -> V_168 [ V_179 ] == V_172 )
return - V_180 ;
}
if ( V_176 & V_191 )
F_112 ( V_191 , V_72 -> V_135 + V_181 ) ;
return 0 ;
}
int F_113 ( struct V_187 * V_167 , struct V_134 * V_72 )
{
int V_192 ;
struct V_169 * V_166 = V_72 -> V_166 ;
struct V_187 * V_193 , V_194 ;
int V_179 , V_53 ;
unsigned long V_71 ;
if ( ! V_166 )
return 0 ;
V_193 = V_166 -> V_167 ;
V_195:
V_192 = 0 ;
F_114 ( & V_166 -> V_196 , V_71 ) ;
while ( V_166 -> V_175 < 3 ) {
F_115 ( & V_166 -> V_196 , V_71 ) ;
F_116 () ;
F_114 ( & V_166 -> V_196 , V_71 ) ;
}
V_53 = V_166 -> V_197 ;
V_179 = ( V_53 + 1 ) % V_174 ;
V_166 -> V_168 [ V_53 ] = V_166 -> V_168 [ V_179 ] = V_190 ;
V_193 [ V_53 ] = * V_167 ;
V_194 . V_185 = F_117 ( V_171 ) |
V_198 | V_199 ;
V_194 . V_186 = F_118 ( & V_166 -> V_168 [ V_179 ] ) ;
V_193 [ V_179 ] = V_194 ;
F_111 ( V_72 , & V_193 [ V_53 ] , sizeof( struct V_187 ) ) ;
F_111 ( V_72 , & V_193 [ V_179 ] , sizeof( struct V_187 ) ) ;
V_166 -> V_197 = ( V_166 -> V_197 + 2 ) % V_174 ;
V_166 -> V_175 -= 2 ;
F_112 ( V_166 -> V_197 << V_184 , V_72 -> V_135 + V_189 ) ;
while ( V_166 -> V_168 [ V_179 ] != V_171 ) {
V_192 = F_110 ( V_72 , V_53 ) ;
if ( V_192 )
break;
F_119 ( & V_166 -> V_196 ) ;
F_116 () ;
F_120 ( & V_166 -> V_196 ) ;
}
V_166 -> V_168 [ V_53 ] = V_171 ;
F_109 ( V_166 ) ;
F_115 ( & V_166 -> V_196 , V_71 ) ;
if ( V_192 == - V_180 )
goto V_195;
return V_192 ;
}
void F_121 ( struct V_134 * V_72 )
{
struct V_187 V_167 ;
V_167 . V_185 = V_200 ;
V_167 . V_186 = 0 ;
F_113 ( & V_167 , V_72 ) ;
}
void F_122 ( struct V_134 * V_72 , T_3 V_201 , T_3 V_202 , T_5 V_203 ,
T_7 type )
{
struct V_187 V_167 ;
V_167 . V_185 = F_123 ( V_203 ) | F_124 ( V_202 ) | F_125 ( V_201 )
| F_126 ( type ) | V_204 ;
V_167 . V_186 = 0 ;
F_113 ( & V_167 , V_72 ) ;
}
void F_127 ( struct V_134 * V_72 , T_3 V_201 , T_7 V_119 ,
unsigned int V_205 , T_7 type )
{
T_5 V_206 = 0 , V_207 = 0 ;
struct V_187 V_167 ;
int V_208 = 0 ;
if ( F_128 ( V_72 -> V_121 ) )
V_206 = 1 ;
if ( F_129 ( V_72 -> V_121 ) )
V_207 = 1 ;
V_167 . V_185 = F_130 ( V_201 ) | F_131 ( V_207 ) | F_132 ( V_206 )
| F_133 ( type ) | V_209 ;
V_167 . V_186 = F_134 ( V_119 ) | F_135 ( V_208 )
| F_136 ( V_205 ) ;
F_113 ( & V_167 , V_72 ) ;
}
void F_137 ( struct V_134 * V_72 , T_3 V_202 , T_3 V_210 ,
T_7 V_119 , unsigned V_211 )
{
struct V_187 V_167 ;
if ( V_211 ) {
F_12 ( V_119 & ( ( 1 << ( V_212 + V_211 ) ) - 1 ) ) ;
V_119 |= ( 1 << ( V_212 + V_211 - 1 ) ) - 1 ;
V_167 . V_186 = F_138 ( V_119 ) | V_213 ;
} else
V_167 . V_186 = F_138 ( V_119 ) ;
if ( V_210 >= V_214 )
V_210 = 0 ;
V_167 . V_185 = F_139 ( V_202 ) | F_140 ( V_210 ) |
V_215 ;
F_113 ( & V_167 , V_72 ) ;
}
void F_141 ( struct V_134 * V_72 )
{
unsigned long V_71 ;
T_9 V_146 ;
T_10 V_216 = F_142 () ;
if ( ! F_143 ( V_72 -> V_122 ) )
return;
F_114 ( & V_72 -> V_161 , V_71 ) ;
V_146 = F_81 ( V_72 -> V_135 + V_153 ) ;
if ( ! ( V_146 & V_159 ) )
goto V_7;
while ( ( F_99 ( V_72 -> V_135 + V_189 ) !=
F_99 ( V_72 -> V_135 + V_183 ) ) &&
( V_217 > ( F_142 () - V_216 ) ) )
F_116 () ;
V_72 -> V_155 &= ~ V_160 ;
F_112 ( V_72 -> V_155 , V_72 -> V_135 + V_218 ) ;
F_144 ( V_72 , V_153 , F_99 ,
! ( V_146 & V_159 ) , V_146 ) ;
V_7:
F_115 ( & V_72 -> V_161 , V_71 ) ;
}
static void F_145 ( struct V_134 * V_72 )
{
T_9 V_146 ;
unsigned long V_71 ;
struct V_169 * V_166 = V_72 -> V_166 ;
V_166 -> V_197 = V_166 -> V_170 = 0 ;
V_166 -> V_175 = V_174 ;
F_114 ( & V_72 -> V_161 , V_71 ) ;
F_112 ( 0 , V_72 -> V_135 + V_189 ) ;
F_146 ( V_72 -> V_135 + V_219 , F_118 ( V_166 -> V_167 ) ) ;
V_72 -> V_155 |= V_160 ;
F_112 ( V_72 -> V_155 , V_72 -> V_135 + V_218 ) ;
F_144 ( V_72 , V_153 , F_99 , ( V_146 & V_159 ) , V_146 ) ;
F_115 ( & V_72 -> V_161 , V_71 ) ;
}
int F_147 ( struct V_134 * V_72 )
{
struct V_169 * V_166 ;
struct V_220 * V_221 ;
if ( ! F_143 ( V_72 -> V_122 ) )
return - V_222 ;
if ( V_72 -> V_166 )
return 0 ;
V_72 -> V_166 = F_148 ( sizeof( * V_166 ) , V_223 ) ;
if ( ! V_72 -> V_166 )
return - V_39 ;
V_166 = V_72 -> V_166 ;
V_221 = F_149 ( V_72 -> V_84 , V_223 | V_224 , 0 ) ;
if ( ! V_221 ) {
F_10 ( V_166 ) ;
V_72 -> V_166 = NULL ;
return - V_39 ;
}
V_166 -> V_167 = F_150 ( V_221 ) ;
V_166 -> V_168 = F_13 ( V_174 * sizeof( int ) , V_223 ) ;
if ( ! V_166 -> V_168 ) {
F_108 ( ( unsigned long ) V_166 -> V_167 ) ;
F_10 ( V_166 ) ;
V_72 -> V_166 = NULL ;
return - V_39 ;
}
F_102 ( & V_166 -> V_196 ) ;
F_145 ( V_72 ) ;
return 0 ;
}
static const char * F_151 ( T_5 V_225 , int * V_226 )
{
if ( V_225 >= 0x20 && ( V_225 - 0x20 <
F_152 ( V_227 ) ) ) {
* V_226 = V_228 ;
return V_227 [ V_225 - 0x20 ] ;
} else if ( V_225 < F_152 ( V_229 ) ) {
* V_226 = V_230 ;
return V_229 [ V_225 ] ;
} else {
* V_226 = V_231 ;
return L_39 ;
}
}
void F_153 ( struct V_232 * V_62 )
{
struct V_134 * V_72 = F_154 ( V_62 ) ;
unsigned long V_233 ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
F_112 ( 0 , V_72 -> V_135 + V_234 ) ;
F_99 ( V_72 -> V_135 + V_234 ) ;
F_115 ( & V_72 -> V_161 , V_233 ) ;
}
void F_155 ( struct V_232 * V_62 )
{
unsigned long V_233 ;
struct V_134 * V_72 = F_154 ( V_62 ) ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
F_112 ( V_235 , V_72 -> V_135 + V_234 ) ;
F_99 ( V_72 -> V_135 + V_234 ) ;
F_115 ( & V_72 -> V_161 , V_233 ) ;
}
void F_156 ( int V_165 , struct V_236 * V_237 )
{
struct V_134 * V_72 = F_157 ( V_165 ) ;
unsigned long V_233 ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
F_112 ( V_237 -> V_62 , V_72 -> V_135 + V_238 ) ;
F_112 ( V_237 -> V_239 , V_72 -> V_135 + V_240 ) ;
F_112 ( V_237 -> V_241 , V_72 -> V_135 + V_242 ) ;
F_115 ( & V_72 -> V_161 , V_233 ) ;
}
void F_158 ( int V_165 , struct V_236 * V_237 )
{
struct V_134 * V_72 = F_157 ( V_165 ) ;
unsigned long V_233 ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
V_237 -> V_62 = F_99 ( V_72 -> V_135 + V_238 ) ;
V_237 -> V_239 = F_99 ( V_72 -> V_135 + V_240 ) ;
V_237 -> V_241 = F_99 ( V_72 -> V_135 + V_242 ) ;
F_115 ( & V_72 -> V_161 , V_233 ) ;
}
static int F_159 ( struct V_134 * V_72 , int type ,
T_5 V_225 , T_3 V_243 , unsigned long long V_119 )
{
const char * V_244 ;
int V_226 ;
V_244 = F_151 ( V_225 , & V_226 ) ;
if ( V_226 == V_228 )
F_69 ( L_40
L_41
L_42 ,
( V_243 >> 8 ) , F_16 ( V_243 & 0xFF ) ,
F_17 ( V_243 & 0xFF ) , V_119 >> 48 ,
V_225 , V_244 ) ;
else
F_69 ( L_43
L_44
L_45 ,
( type ? L_46 : L_47 ) ,
( V_243 >> 8 ) , F_16 ( V_243 & 0xFF ) ,
F_17 ( V_243 & 0xFF ) , V_119 , V_225 , V_244 ) ;
return 0 ;
}
T_11 F_160 ( int V_165 , void * V_245 )
{
struct V_134 * V_72 = V_245 ;
int V_135 , V_246 ;
T_9 V_247 ;
unsigned long V_233 ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
V_247 = F_99 ( V_72 -> V_135 + V_181 ) ;
if ( V_247 )
F_69 ( L_48 , V_247 ) ;
if ( ! ( V_247 & V_248 ) )
goto V_249;
V_246 = F_161 ( V_247 ) ;
V_135 = F_162 ( V_72 -> V_121 ) ;
while ( 1 ) {
T_5 V_225 ;
T_3 V_243 ;
T_7 V_250 ;
int type ;
T_9 V_62 ;
V_62 = F_99 ( V_72 -> V_135 + V_135 +
V_246 * V_251 + 12 ) ;
if ( ! ( V_62 & V_252 ) )
break;
V_225 = F_163 ( V_62 ) ;
type = F_164 ( V_62 ) ;
V_62 = F_99 ( V_72 -> V_135 + V_135 +
V_246 * V_251 + 8 ) ;
V_243 = F_165 ( V_62 ) ;
V_250 = F_81 ( V_72 -> V_135 + V_135 +
V_246 * V_251 ) ;
V_250 = F_166 ( V_250 ) ;
F_112 ( V_252 , V_72 -> V_135 + V_135 +
V_246 * V_251 + 12 ) ;
F_115 ( & V_72 -> V_161 , V_233 ) ;
F_159 ( V_72 , type , V_225 ,
V_243 , V_250 ) ;
V_246 ++ ;
if ( V_246 >= F_167 ( V_72 -> V_121 ) )
V_246 = 0 ;
F_114 ( & V_72 -> V_161 , V_233 ) ;
}
F_112 ( V_253 | V_248 , V_72 -> V_135 + V_181 ) ;
V_249:
F_115 ( & V_72 -> V_161 , V_233 ) ;
return V_254 ;
}
int F_168 ( struct V_134 * V_72 )
{
int V_165 , V_54 ;
if ( V_72 -> V_165 )
return 0 ;
V_165 = F_169 () ;
if ( V_165 <= 0 ) {
F_69 ( L_49 ) ;
return - V_52 ;
}
F_106 ( V_165 , V_72 ) ;
V_72 -> V_165 = V_165 ;
V_54 = F_170 ( V_165 ) ;
if ( V_54 ) {
F_106 ( V_165 , NULL ) ;
V_72 -> V_165 = 0 ;
F_107 ( V_165 ) ;
return V_54 ;
}
V_54 = F_171 ( V_165 , F_160 , V_255 , V_72 -> V_141 , V_72 ) ;
if ( V_54 )
F_69 ( L_50 ) ;
return V_54 ;
}
int T_1 F_172 ( void )
{
struct V_1 * V_2 ;
struct V_134 * V_72 ;
F_173 (iommu, drhd) {
T_9 V_247 ;
int V_54 = F_168 ( V_72 ) ;
if ( V_54 ) {
F_69 ( L_51 ,
( unsigned long long ) V_2 -> V_69 , V_54 ) ;
return - 1 ;
}
F_160 ( V_72 -> V_165 , V_72 ) ;
V_247 = F_99 ( V_72 -> V_135 + V_181 ) ;
F_112 ( V_247 , V_72 -> V_135 + V_181 ) ;
}
return 0 ;
}
int F_174 ( struct V_134 * V_72 )
{
if ( ! F_143 ( V_72 -> V_122 ) )
return - V_222 ;
if ( ! V_72 -> V_166 )
return - V_222 ;
F_141 ( V_72 ) ;
F_145 ( V_72 ) ;
return 0 ;
}
int T_1 F_175 ( void )
{
struct V_103 * V_104 ;
V_104 = (struct V_103 * ) V_100 ;
if ( ! V_104 )
return 0 ;
return V_104 -> V_71 & 0x1 ;
}
static int T_1 F_176 ( void )
{
struct V_1 * V_55 , * V_256 ;
if ( V_257 || V_162 )
return 0 ;
if ( V_38 != 1 && ! F_72 ( & V_5 ) )
F_177 ( & V_116 , & V_117 ) ;
F_36 ( & V_66 ) ;
F_178 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_179 ( & V_55 -> V_4 ) ;
F_40 ( V_55 ) ;
}
F_37 ( & V_66 ) ;
return 0 ;
}
