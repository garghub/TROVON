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
V_31 -> V_41 [ V_28 ] . V_22 = F_16 ( V_30 -> V_42 ) ;
V_31 -> V_41 [ V_28 ] . V_43 = F_17 ( V_30 -> V_42 ) ;
if ( F_18 ( V_30 -> V_34 ) )
V_31 -> V_34 = V_30 -> V_34 -> V_44 ;
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
return false ;
if ( V_31 -> V_28 != V_45 )
return false ;
for ( V_21 = 0 ; V_21 < V_45 ; V_21 ++ ) {
if ( V_41 [ V_21 ] . V_22 != V_31 -> V_41 [ V_21 ] . V_22 ||
V_41 [ V_21 ] . V_43 != V_31 -> V_41 [ V_21 ] . V_43 )
return false ;
}
return true ;
}
int F_21 ( struct V_24 * V_31 ,
void * V_6 , void * V_7 , T_3 V_46 ,
struct V_18 * V_20 ,
int V_47 )
{
int V_21 , V_28 ;
struct V_22 * V_30 , * V_26 = & V_31 -> V_26 -> V_26 ;
struct V_9 * V_10 ;
struct V_36 * V_41 ;
if ( V_46 != V_31 -> V_40 )
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
( V_31 -> V_26 -> V_48 == V_49 ) ) {
F_5 ( L_4 ,
F_14 ( V_31 -> V_26 ) ) ;
return - V_50 ;
}
F_22 (devices, devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_20 [ V_21 ] . V_34 = V_31 -> V_26 -> V_34 -> V_44 ;
V_20 [ V_21 ] . V_42 = V_31 -> V_26 -> V_42 ;
F_23 ( V_20 [ V_21 ] . V_26 ,
F_24 ( V_26 ) ) ;
return 1 ;
}
F_12 ( V_21 >= V_47 ) ;
}
return 0 ;
}
int F_25 ( struct V_24 * V_31 , T_3 V_46 ,
struct V_18 * V_20 , int V_45 )
{
int V_51 ;
struct V_22 * V_30 ;
if ( V_31 -> V_40 != V_46 )
return 0 ;
F_8 (devices, count, index, tmp)
if ( V_30 == & V_31 -> V_26 -> V_26 ) {
F_23 ( V_20 [ V_51 ] . V_26 , NULL ) ;
F_26 () ;
F_9 ( V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_31 )
{
int V_52 = 0 ;
struct V_1 * V_53 ;
struct V_54 * V_2 ;
F_28 (dmaru) {
if ( V_53 -> V_3 )
continue;
V_2 = F_29 ( V_53 -> V_55 ,
struct V_54 , V_56 ) ;
V_52 = F_21 ( V_31 , ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_56 . V_17 ,
V_53 -> V_46 ,
V_53 -> V_20 , V_53 -> V_47 ) ;
if ( V_52 != 0 )
break;
}
if ( V_52 >= 0 )
V_52 = F_30 ( V_31 ) ;
if ( V_52 < 0 && V_38 == 0 )
V_38 = V_52 ;
return V_52 ;
}
static void F_31 ( struct V_24 * V_31 )
{
struct V_1 * V_53 ;
F_28 (dmaru)
if ( F_25 ( V_31 , V_53 -> V_46 ,
V_53 -> V_20 , V_53 -> V_47 ) )
break;
F_30 ( V_31 ) ;
}
static int F_32 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
struct V_25 * V_61 = F_33 ( V_60 ) ;
struct V_24 * V_31 ;
if ( V_61 -> V_32 )
return V_62 ;
if ( V_59 != V_33 && V_59 != V_63 )
return V_62 ;
V_31 = F_11 ( V_61 , V_59 ) ;
if ( ! V_31 )
return V_62 ;
F_34 ( & V_64 ) ;
if ( V_59 == V_33 )
F_27 ( V_31 ) ;
else if ( V_59 == V_63 )
F_31 ( V_31 ) ;
F_35 ( & V_64 ) ;
F_19 ( V_31 ) ;
return V_65 ;
}
static int T_1
F_36 ( struct V_66 * V_56 )
{
struct V_54 * V_2 ;
struct V_1 * V_53 ;
int V_52 = 0 ;
V_2 = (struct V_54 * ) V_56 ;
V_53 = F_13 ( sizeof( * V_53 ) , V_19 ) ;
if ( ! V_53 )
return - V_39 ;
V_53 -> V_55 = V_56 ;
V_53 -> V_67 = V_2 -> V_68 ;
V_53 -> V_46 = V_2 -> V_46 ;
V_53 -> V_3 = V_2 -> V_69 & 0x1 ;
V_53 -> V_20 = F_4 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_56 . V_17 ,
& V_53 -> V_47 ) ;
if ( V_53 -> V_47 && V_53 -> V_20 == NULL ) {
F_10 ( V_53 ) ;
return - V_39 ;
}
V_52 = F_37 ( V_53 ) ;
if ( V_52 ) {
F_7 ( & V_53 -> V_20 ,
& V_53 -> V_47 ) ;
F_10 ( V_53 ) ;
return V_52 ;
}
F_1 ( V_53 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_53 )
{
if ( V_53 -> V_20 && V_53 -> V_47 )
F_7 ( & V_53 -> V_20 , & V_53 -> V_47 ) ;
if ( V_53 -> V_70 )
F_39 ( V_53 -> V_70 ) ;
F_10 ( V_53 ) ;
}
static int T_1 F_40 ( struct V_66 * V_56 )
{
struct V_71 * V_72 = ( void * ) V_56 ;
if ( F_41 ( V_72 -> V_73 , V_56 -> V_17 - 8 ) == V_56 -> V_17 - 8 ) {
F_42 ( 1 , V_74 ,
L_5
L_6 ,
F_43 ( V_75 ) ,
F_43 ( V_76 ) ,
F_43 ( V_77 ) ) ;
return - V_50 ;
}
F_44 ( L_7 , V_72 -> V_78 ,
V_72 -> V_73 ) ;
return 0 ;
}
static int T_1
F_45 ( struct V_66 * V_56 )
{
struct V_79 * V_80 ;
struct V_1 * V_2 ;
V_80 = (struct V_79 * ) V_56 ;
F_28 (drhd) {
if ( V_2 -> V_67 == V_80 -> V_81 ) {
int V_82 = F_46 ( V_80 -> V_83 ) ;
if ( ! F_47 ( V_82 ) )
V_82 = - 1 ;
V_2 -> V_70 -> V_82 = V_82 ;
return 0 ;
}
}
F_42 (
1 , V_74 ,
L_8
L_6 ,
V_2 -> V_67 ,
F_43 ( V_75 ) ,
F_43 ( V_76 ) ,
F_43 ( V_77 ) ) ;
return 0 ;
}
static void T_1
F_48 ( struct V_66 * V_56 )
{
struct V_54 * V_2 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_79 * V_80 ;
switch ( V_56 -> type ) {
case V_88 :
V_2 = F_29 ( V_56 , struct V_54 ,
V_56 ) ;
F_44 ( L_9 ,
( unsigned long long ) V_2 -> V_68 , V_2 -> V_69 ) ;
break;
case V_89 :
V_85 = F_29 ( V_56 , struct V_84 ,
V_56 ) ;
F_44 ( L_10 ,
( unsigned long long ) V_85 -> V_81 ,
( unsigned long long ) V_85 -> V_90 ) ;
break;
case V_91 :
V_87 = F_29 ( V_56 , struct V_86 , V_56 ) ;
F_44 ( L_11 , V_87 -> V_69 ) ;
break;
case V_92 :
V_80 = F_29 ( V_56 , struct V_79 , V_56 ) ;
F_44 ( L_12 ,
( unsigned long long ) V_80 -> V_81 ,
V_80 -> V_83 ) ;
break;
case V_93 :
break;
}
}
static int T_1 F_49 ( void )
{
T_4 V_94 = V_95 ;
V_94 = F_50 ( V_96 , 0 ,
(struct V_97 * * ) & V_98 ,
& V_99 ) ;
if ( F_51 ( V_94 ) && ! V_98 ) {
F_5 ( L_13 ) ;
V_94 = V_100 ;
}
return ( F_51 ( V_94 ) ? 1 : 0 ) ;
}
static int T_1
F_52 ( void )
{
struct V_101 * V_102 ;
struct V_66 * V_103 ;
int V_52 = 0 ;
int V_104 = 0 ;
F_49 () ;
V_98 = F_53 ( V_98 ) ;
V_102 = (struct V_101 * ) V_98 ;
if ( ! V_102 )
return - V_105 ;
if ( V_102 -> V_106 < V_107 - 1 ) {
F_5 ( L_14 ) ;
return - V_50 ;
}
F_44 ( L_15 , V_102 -> V_106 + 1 ) ;
V_103 = (struct V_66 * ) ( V_102 + 1 ) ;
while ( ( ( unsigned long ) V_103 ) <
( ( ( unsigned long ) V_102 ) + V_98 -> V_17 ) ) {
if ( V_103 -> V_17 == 0 ) {
F_5 ( L_16 ) ;
V_52 = - V_50 ;
break;
}
F_48 ( V_103 ) ;
switch ( V_103 -> type ) {
case V_88 :
V_104 ++ ;
V_52 = F_36 ( V_103 ) ;
break;
case V_89 :
V_52 = F_54 ( V_103 ) ;
break;
case V_91 :
V_52 = F_55 ( V_103 ) ;
break;
case V_92 :
#ifdef F_56
V_52 = F_45 ( V_103 ) ;
#endif
break;
case V_93 :
V_52 = F_40 ( V_103 ) ;
break;
default:
F_5 ( L_17 ,
V_103 -> type ) ;
V_52 = 0 ;
break;
}
if ( V_52 )
break;
V_103 = ( ( void * ) V_103 + V_103 -> V_17 ) ;
}
if ( V_104 == 0 )
F_5 ( V_108 L_18 ) ;
return V_52 ;
}
static int F_57 ( struct V_18 V_20 [] ,
int V_8 , struct V_25 * V_26 )
{
int V_51 ;
struct V_22 * V_30 ;
while ( V_26 ) {
F_8 (devices, cnt, index, tmp)
if ( F_58 ( V_30 ) && V_26 == F_33 ( V_30 ) )
return 1 ;
V_26 = V_26 -> V_34 -> V_35 ;
}
return 0 ;
}
struct V_1 *
F_59 ( struct V_25 * V_26 )
{
struct V_1 * V_53 ;
struct V_54 * V_2 ;
V_26 = F_60 ( V_26 ) ;
F_61 () ;
F_28 (dmaru) {
V_2 = F_29 ( V_53 -> V_55 ,
struct V_54 ,
V_56 ) ;
if ( V_53 -> V_3 &&
V_2 -> V_46 == F_15 ( V_26 -> V_34 ) )
goto V_109;
if ( F_57 ( V_53 -> V_20 ,
V_53 -> V_47 , V_26 ) )
goto V_109;
}
V_53 = NULL ;
V_109:
F_62 () ;
return V_53 ;
}
static void T_1 F_63 ( T_5 V_78 ,
struct V_110 * V_111 )
{
struct V_1 * V_53 ;
struct V_54 * V_2 ;
struct V_9 * V_10 ;
struct V_22 * V_30 ;
int V_21 ;
struct V_36 * V_41 ;
F_28 (dmaru) {
V_2 = F_29 ( V_53 -> V_55 ,
struct V_54 ,
V_56 ) ;
for ( V_10 = ( void * ) ( V_2 + 1 ) ;
( unsigned long ) V_10 < ( ( unsigned long ) V_2 ) + V_2 -> V_56 . V_17 ;
V_10 = ( ( void * ) V_10 ) + V_10 -> V_17 ) {
if ( V_10 -> V_11 != V_12 )
continue;
if ( V_10 -> V_112 != V_78 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_44 ( L_19 ,
F_64 ( & V_111 -> V_26 ) , V_53 -> V_67 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_43 ) ;
F_22 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_53 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_53 -> V_20 [ V_21 ] . V_42 = F_65 ( V_41 -> V_22 ,
V_41 -> V_43 ) ;
F_23 ( V_53 -> V_20 [ V_21 ] . V_26 ,
F_24 ( & V_111 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_53 -> V_47 ) ;
}
}
F_5 ( L_20 ,
V_78 , F_64 ( & V_111 -> V_26 ) ) ;
}
static int T_1 F_66 ( void )
{
struct V_71 * V_72 ;
if ( V_98 == NULL )
return - V_105 ;
for ( V_72 = ( void * ) V_98 + sizeof( struct V_101 ) ;
( ( unsigned long ) V_72 ) < ( ( unsigned long ) V_98 ) + V_98 -> V_17 ;
V_72 = ( ( void * ) V_72 ) + V_72 -> V_56 . V_17 ) {
if ( V_72 -> V_56 . type == V_93 ) {
T_6 V_113 ;
struct V_110 * V_111 ;
if ( ! F_51 ( F_67 ( V_114 ,
V_72 -> V_73 ,
& V_113 ) ) ) {
F_68 ( L_21 ,
V_72 -> V_73 ) ;
continue;
}
F_69 ( V_113 , & V_111 ) ;
if ( ! V_111 ) {
F_68 ( L_22 ,
V_72 -> V_73 ) ;
continue;
}
F_63 ( V_72 -> V_78 , V_111 ) ;
}
}
return 0 ;
}
int T_1 F_70 ( void )
{
struct V_25 * V_26 = NULL ;
struct V_24 * V_31 ;
if ( V_38 != 1 )
return V_38 ;
if ( F_71 ( & V_5 ) ) {
V_38 = - V_105 ;
} else {
V_38 = 0 ;
F_66 () ;
F_72 (dev) {
if ( V_26 -> V_32 )
continue;
V_31 = F_11 ( V_26 ,
V_33 ) ;
if ( ! V_31 ) {
return V_38 ;
} else {
F_27 ( V_31 ) ;
F_19 ( V_31 ) ;
}
}
F_73 ( & V_115 , & V_116 ) ;
}
return V_38 ;
}
int T_1 F_74 ( void )
{
static int V_117 ;
int V_52 ;
if ( V_117 == 0 ) {
V_52 = F_52 () ;
if ( V_52 < 0 ) {
if ( V_52 != - V_105 )
F_44 ( L_23 ) ;
} else if ( F_71 ( & V_5 ) ) {
F_44 ( L_24 ) ;
V_52 = - V_105 ;
}
if ( V_52 < 0 )
V_117 = V_52 ;
else
V_117 = 1 ;
}
return V_117 < 0 ? V_117 : 0 ;
}
static void F_75 ( T_7 V_118 , const char * V_119 )
{
F_76 (
1 , V_74 ,
L_25
L_6 ,
V_118 , V_119 ,
F_43 ( V_75 ) ,
F_43 ( V_76 ) ,
F_43 ( V_77 ) ) ;
}
static int T_1 F_77 ( void )
{
struct V_101 * V_102 ;
struct V_66 * V_103 ;
struct V_54 * V_2 ;
V_102 = (struct V_101 * ) V_98 ;
V_103 = (struct V_66 * ) ( V_102 + 1 ) ;
while ( ( ( unsigned long ) V_103 ) <
( ( ( unsigned long ) V_102 ) + V_98 -> V_17 ) ) {
if ( V_103 -> V_17 == 0 ) {
F_5 ( L_16 ) ;
return 0 ;
}
if ( V_103 -> type == V_88 ) {
void T_8 * V_118 ;
T_7 V_120 , V_121 ;
V_2 = ( void * ) V_103 ;
if ( ! V_2 -> V_68 ) {
F_75 ( 0 , L_26 ) ;
goto V_122;
}
V_118 = F_78 ( V_2 -> V_68 , V_123 ) ;
if ( ! V_118 ) {
F_79 ( L_27 , V_2 -> V_68 ) ;
goto V_122;
}
V_120 = F_80 ( V_118 + V_124 ) ;
V_121 = F_80 ( V_118 + V_125 ) ;
F_81 ( V_118 , V_123 ) ;
if ( V_120 == ( V_126 ) - 1 && V_121 == ( V_126 ) - 1 ) {
F_75 ( V_2 -> V_68 ,
L_28 ) ;
goto V_122;
}
}
V_103 = ( ( void * ) V_103 + V_103 -> V_17 ) ;
}
return 1 ;
V_122:
return 0 ;
}
int T_1 F_82 ( void )
{
int V_52 ;
F_34 ( & V_64 ) ;
V_52 = F_49 () ;
if ( V_52 )
V_52 = F_77 () ;
{
if ( V_52 && ! V_127 && ! V_128 && ! V_129 ) {
V_128 = 1 ;
F_83 () ;
}
#ifdef F_84
if ( V_52 )
V_130 . V_70 . V_131 = V_132 ;
#endif
}
F_85 ( ( void T_8 * ) V_98 , V_99 ) ;
V_98 = NULL ;
F_35 ( & V_64 ) ;
return V_52 ? 1 : - V_105 ;
}
static void F_86 ( struct V_133 * V_70 )
{
F_87 ( V_70 -> V_134 ) ;
F_88 ( V_70 -> V_135 , V_70 -> V_136 ) ;
}
static int F_89 ( struct V_133 * V_70 , T_7 V_137 )
{
int V_138 , V_139 = 0 ;
V_70 -> V_135 = V_137 ;
V_70 -> V_136 = V_123 ;
if ( ! F_90 ( V_70 -> V_135 , V_70 -> V_136 , V_70 -> V_140 ) ) {
F_68 ( L_29 ) ;
V_139 = - V_141 ;
goto V_109;
}
V_70 -> V_134 = F_91 ( V_70 -> V_135 , V_70 -> V_136 ) ;
if ( ! V_70 -> V_134 ) {
F_68 ( L_30 ) ;
V_139 = - V_39 ;
goto V_142;
}
V_70 -> V_120 = F_80 ( V_70 -> V_134 + V_124 ) ;
V_70 -> V_121 = F_80 ( V_70 -> V_134 + V_125 ) ;
if ( V_70 -> V_120 == ( V_126 ) - 1 && V_70 -> V_121 == ( V_126 ) - 1 ) {
V_139 = - V_50 ;
F_75 ( V_137 , L_28 ) ;
goto V_143;
}
V_138 = F_92 ( int , F_93 ( V_70 -> V_121 ) ,
F_94 ( V_70 -> V_120 ) ) ;
V_138 = F_95 ( V_138 ) ;
if ( V_138 > V_70 -> V_136 ) {
F_87 ( V_70 -> V_134 ) ;
F_88 ( V_70 -> V_135 , V_70 -> V_136 ) ;
V_70 -> V_136 = V_138 ;
if ( ! F_90 ( V_70 -> V_135 , V_70 -> V_136 ,
V_70 -> V_140 ) ) {
F_68 ( L_29 ) ;
V_139 = - V_141 ;
goto V_109;
}
V_70 -> V_134 = F_91 ( V_70 -> V_135 , V_70 -> V_136 ) ;
if ( ! V_70 -> V_134 ) {
F_68 ( L_30 ) ;
V_139 = - V_39 ;
goto V_142;
}
}
V_139 = 0 ;
goto V_109;
V_143:
F_87 ( V_70 -> V_134 ) ;
V_142:
F_88 ( V_70 -> V_135 , V_70 -> V_136 ) ;
V_109:
return V_139 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_133 * V_70 ;
T_9 V_144 , V_145 ;
static int V_146 = 0 ;
int V_147 = 0 ;
int V_148 = 0 ;
int V_139 ;
if ( ! V_2 -> V_67 ) {
F_75 ( 0 , L_26 ) ;
return - V_50 ;
}
V_70 = F_13 ( sizeof( * V_70 ) , V_19 ) ;
if ( ! V_70 )
return - V_39 ;
V_70 -> V_149 = V_146 ++ ;
sprintf ( V_70 -> V_140 , L_31 , V_70 -> V_149 ) ;
V_139 = F_89 ( V_70 , V_2 -> V_67 ) ;
if ( V_139 ) {
F_68 ( L_32 , V_70 -> V_140 ) ;
goto error;
}
V_139 = - V_50 ;
V_147 = F_96 ( V_70 ) ;
if ( V_147 < 0 ) {
F_68 ( L_33 ,
V_70 -> V_149 ) ;
goto V_150;
}
V_148 = F_97 ( V_70 ) ;
if ( V_148 < 0 ) {
F_68 ( L_34 ,
V_70 -> V_149 ) ;
goto V_150;
}
V_70 -> V_147 = V_147 ;
V_70 -> V_148 = V_148 ;
V_70 -> V_46 = V_2 -> V_46 ;
V_70 -> V_82 = - 1 ;
V_144 = F_98 ( V_70 -> V_134 + V_151 ) ;
F_44 ( L_35 ,
V_70 -> V_149 ,
( unsigned long long ) V_2 -> V_67 ,
F_99 ( V_144 ) , F_100 ( V_144 ) ,
( unsigned long long ) V_70 -> V_120 ,
( unsigned long long ) V_70 -> V_121 ) ;
V_145 = F_98 ( V_70 -> V_134 + V_152 ) ;
if ( V_145 & V_153 )
V_70 -> V_154 |= V_155 ;
if ( V_145 & V_156 )
V_70 -> V_154 |= V_157 ;
if ( V_145 & V_158 )
V_70 -> V_154 |= V_159 ;
F_101 ( & V_70 -> V_160 ) ;
V_2 -> V_70 = V_70 ;
return 0 ;
V_150:
F_86 ( V_70 ) ;
error:
F_10 ( V_70 ) ;
return V_139 ;
}
static void F_39 ( struct V_133 * V_70 )
{
if ( V_70 -> V_161 ) {
F_102 ( V_70 -> V_161 , V_70 ) ;
F_103 ( V_70 -> V_161 , NULL ) ;
F_104 ( V_70 -> V_161 ) ;
}
if ( V_70 -> V_162 ) {
F_105 ( ( unsigned long ) V_70 -> V_162 -> V_163 ) ;
F_10 ( V_70 -> V_162 -> V_164 ) ;
F_10 ( V_70 -> V_162 ) ;
}
if ( V_70 -> V_134 )
F_86 ( V_70 ) ;
F_10 ( V_70 ) ;
}
static inline void F_106 ( struct V_165 * V_162 )
{
while ( V_162 -> V_164 [ V_162 -> V_166 ] == V_167 ||
V_162 -> V_164 [ V_162 -> V_166 ] == V_168 ) {
V_162 -> V_164 [ V_162 -> V_166 ] = V_169 ;
V_162 -> V_166 = ( V_162 -> V_166 + 1 ) % V_170 ;
V_162 -> V_171 ++ ;
}
}
static int F_107 ( struct V_133 * V_70 , int V_51 )
{
T_9 V_172 ;
int V_173 , V_174 ;
struct V_165 * V_162 = V_70 -> V_162 ;
int V_175 = ( V_51 + 1 ) % V_170 ;
if ( V_162 -> V_164 [ V_175 ] == V_168 )
return - V_176 ;
V_172 = F_98 ( V_70 -> V_134 + V_177 ) ;
if ( V_172 & V_178 ) {
V_173 = F_98 ( V_70 -> V_134 + V_179 ) ;
if ( ( V_173 >> V_180 ) == V_51 ) {
F_68 ( L_36
L_37 ,
( unsigned long long ) V_162 -> V_163 [ V_51 ] . V_181 ,
( unsigned long long ) V_162 -> V_163 [ V_51 ] . V_182 ) ;
memcpy ( & V_162 -> V_163 [ V_51 ] , & V_162 -> V_163 [ V_175 ] ,
sizeof( struct V_183 ) ) ;
F_108 ( V_70 , & V_162 -> V_163 [ V_51 ] ,
sizeof( struct V_183 ) ) ;
F_109 ( V_178 , V_70 -> V_134 + V_177 ) ;
return - V_50 ;
}
}
if ( V_172 & V_184 ) {
V_173 = F_98 ( V_70 -> V_134 + V_179 ) ;
V_173 = ( ( V_173 >> V_180 ) - 1 + V_170 ) % V_170 ;
V_173 |= 1 ;
V_174 = F_98 ( V_70 -> V_134 + V_185 ) ;
V_174 = ( ( V_174 >> V_180 ) - 1 + V_170 ) % V_170 ;
F_109 ( V_184 , V_70 -> V_134 + V_177 ) ;
do {
if ( V_162 -> V_164 [ V_173 ] == V_186 )
V_162 -> V_164 [ V_173 ] = V_168 ;
V_173 = ( V_173 - 2 + V_170 ) % V_170 ;
} while ( V_173 != V_174 );
if ( V_162 -> V_164 [ V_175 ] == V_168 )
return - V_176 ;
}
if ( V_172 & V_187 )
F_109 ( V_187 , V_70 -> V_134 + V_177 ) ;
return 0 ;
}
int F_110 ( struct V_183 * V_163 , struct V_133 * V_70 )
{
int V_188 ;
struct V_165 * V_162 = V_70 -> V_162 ;
struct V_183 * V_189 , V_190 ;
int V_175 , V_51 ;
unsigned long V_69 ;
if ( ! V_162 )
return 0 ;
V_189 = V_162 -> V_163 ;
V_191:
V_188 = 0 ;
F_111 ( & V_162 -> V_192 , V_69 ) ;
while ( V_162 -> V_171 < 3 ) {
F_112 ( & V_162 -> V_192 , V_69 ) ;
F_113 () ;
F_111 ( & V_162 -> V_192 , V_69 ) ;
}
V_51 = V_162 -> V_193 ;
V_175 = ( V_51 + 1 ) % V_170 ;
V_162 -> V_164 [ V_51 ] = V_162 -> V_164 [ V_175 ] = V_186 ;
V_189 [ V_51 ] = * V_163 ;
V_190 . V_181 = F_114 ( V_167 ) |
V_194 | V_195 ;
V_190 . V_182 = F_115 ( & V_162 -> V_164 [ V_175 ] ) ;
V_189 [ V_175 ] = V_190 ;
F_108 ( V_70 , & V_189 [ V_51 ] , sizeof( struct V_183 ) ) ;
F_108 ( V_70 , & V_189 [ V_175 ] , sizeof( struct V_183 ) ) ;
V_162 -> V_193 = ( V_162 -> V_193 + 2 ) % V_170 ;
V_162 -> V_171 -= 2 ;
F_109 ( V_162 -> V_193 << V_180 , V_70 -> V_134 + V_185 ) ;
while ( V_162 -> V_164 [ V_175 ] != V_167 ) {
V_188 = F_107 ( V_70 , V_51 ) ;
if ( V_188 )
break;
F_116 ( & V_162 -> V_192 ) ;
F_113 () ;
F_117 ( & V_162 -> V_192 ) ;
}
V_162 -> V_164 [ V_51 ] = V_167 ;
F_106 ( V_162 ) ;
F_112 ( & V_162 -> V_192 , V_69 ) ;
if ( V_188 == - V_176 )
goto V_191;
return V_188 ;
}
void F_118 ( struct V_133 * V_70 )
{
struct V_183 V_163 ;
V_163 . V_181 = V_196 ;
V_163 . V_182 = 0 ;
F_110 ( & V_163 , V_70 ) ;
}
void F_119 ( struct V_133 * V_70 , T_3 V_197 , T_3 V_198 , T_5 V_199 ,
T_7 type )
{
struct V_183 V_163 ;
V_163 . V_181 = F_120 ( V_199 ) | F_121 ( V_198 ) | F_122 ( V_197 )
| F_123 ( type ) | V_200 ;
V_163 . V_182 = 0 ;
F_110 ( & V_163 , V_70 ) ;
}
void F_124 ( struct V_133 * V_70 , T_3 V_197 , T_7 V_118 ,
unsigned int V_201 , T_7 type )
{
T_5 V_202 = 0 , V_203 = 0 ;
struct V_183 V_163 ;
int V_204 = 0 ;
if ( F_125 ( V_70 -> V_120 ) )
V_202 = 1 ;
if ( F_126 ( V_70 -> V_120 ) )
V_203 = 1 ;
V_163 . V_181 = F_127 ( V_197 ) | F_128 ( V_203 ) | F_129 ( V_202 )
| F_130 ( type ) | V_205 ;
V_163 . V_182 = F_131 ( V_118 ) | F_132 ( V_204 )
| F_133 ( V_201 ) ;
F_110 ( & V_163 , V_70 ) ;
}
void F_134 ( struct V_133 * V_70 , T_3 V_198 , T_3 V_206 ,
T_7 V_118 , unsigned V_207 )
{
struct V_183 V_163 ;
if ( V_207 ) {
F_12 ( V_118 & ( ( 1 << ( V_208 + V_207 ) ) - 1 ) ) ;
V_118 |= ( 1 << ( V_208 + V_207 - 1 ) ) - 1 ;
V_163 . V_182 = F_135 ( V_118 ) | V_209 ;
} else
V_163 . V_182 = F_135 ( V_118 ) ;
if ( V_206 >= V_210 )
V_206 = 0 ;
V_163 . V_181 = F_136 ( V_198 ) | F_137 ( V_206 ) |
V_211 ;
F_110 ( & V_163 , V_70 ) ;
}
void F_138 ( struct V_133 * V_70 )
{
unsigned long V_69 ;
T_9 V_145 ;
T_10 V_212 = F_139 () ;
if ( ! F_140 ( V_70 -> V_121 ) )
return;
F_111 ( & V_70 -> V_160 , V_69 ) ;
V_145 = F_80 ( V_70 -> V_134 + V_152 ) ;
if ( ! ( V_145 & V_158 ) )
goto V_7;
while ( ( F_98 ( V_70 -> V_134 + V_185 ) !=
F_98 ( V_70 -> V_134 + V_179 ) ) &&
( V_213 > ( F_139 () - V_212 ) ) )
F_113 () ;
V_70 -> V_154 &= ~ V_159 ;
F_109 ( V_70 -> V_154 , V_70 -> V_134 + V_214 ) ;
F_141 ( V_70 , V_152 , F_98 ,
! ( V_145 & V_158 ) , V_145 ) ;
V_7:
F_112 ( & V_70 -> V_160 , V_69 ) ;
}
static void F_142 ( struct V_133 * V_70 )
{
T_9 V_145 ;
unsigned long V_69 ;
struct V_165 * V_162 = V_70 -> V_162 ;
V_162 -> V_193 = V_162 -> V_166 = 0 ;
V_162 -> V_171 = V_170 ;
F_111 ( & V_70 -> V_160 , V_69 ) ;
F_109 ( 0 , V_70 -> V_134 + V_185 ) ;
F_143 ( V_70 -> V_134 + V_215 , F_115 ( V_162 -> V_163 ) ) ;
V_70 -> V_154 |= V_159 ;
F_109 ( V_70 -> V_154 , V_70 -> V_134 + V_214 ) ;
F_141 ( V_70 , V_152 , F_98 , ( V_145 & V_158 ) , V_145 ) ;
F_112 ( & V_70 -> V_160 , V_69 ) ;
}
int F_144 ( struct V_133 * V_70 )
{
struct V_165 * V_162 ;
struct V_216 * V_217 ;
if ( ! F_140 ( V_70 -> V_121 ) )
return - V_218 ;
if ( V_70 -> V_162 )
return 0 ;
V_70 -> V_162 = F_145 ( sizeof( * V_162 ) , V_219 ) ;
if ( ! V_70 -> V_162 )
return - V_39 ;
V_162 = V_70 -> V_162 ;
V_217 = F_146 ( V_70 -> V_82 , V_219 | V_220 , 0 ) ;
if ( ! V_217 ) {
F_10 ( V_162 ) ;
V_70 -> V_162 = NULL ;
return - V_39 ;
}
V_162 -> V_163 = F_147 ( V_217 ) ;
V_162 -> V_164 = F_13 ( V_170 * sizeof( int ) , V_219 ) ;
if ( ! V_162 -> V_164 ) {
F_105 ( ( unsigned long ) V_162 -> V_163 ) ;
F_10 ( V_162 ) ;
V_70 -> V_162 = NULL ;
return - V_39 ;
}
V_162 -> V_193 = V_162 -> V_166 = 0 ;
V_162 -> V_171 = V_170 ;
F_101 ( & V_162 -> V_192 ) ;
F_142 ( V_70 ) ;
return 0 ;
}
static const char * F_148 ( T_5 V_221 , int * V_222 )
{
if ( V_221 >= 0x20 && ( V_221 - 0x20 <
F_149 ( V_223 ) ) ) {
* V_222 = V_224 ;
return V_223 [ V_221 - 0x20 ] ;
} else if ( V_221 < F_149 ( V_225 ) ) {
* V_222 = V_226 ;
return V_225 [ V_221 ] ;
} else {
* V_222 = V_227 ;
return L_38 ;
}
}
void F_150 ( struct V_228 * V_60 )
{
struct V_133 * V_70 = F_151 ( V_60 ) ;
unsigned long V_229 ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
F_109 ( 0 , V_70 -> V_134 + V_230 ) ;
F_98 ( V_70 -> V_134 + V_230 ) ;
F_112 ( & V_70 -> V_160 , V_229 ) ;
}
void F_152 ( struct V_228 * V_60 )
{
unsigned long V_229 ;
struct V_133 * V_70 = F_151 ( V_60 ) ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
F_109 ( V_231 , V_70 -> V_134 + V_230 ) ;
F_98 ( V_70 -> V_134 + V_230 ) ;
F_112 ( & V_70 -> V_160 , V_229 ) ;
}
void F_153 ( int V_161 , struct V_232 * V_233 )
{
struct V_133 * V_70 = F_154 ( V_161 ) ;
unsigned long V_229 ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
F_109 ( V_233 -> V_60 , V_70 -> V_134 + V_234 ) ;
F_109 ( V_233 -> V_235 , V_70 -> V_134 + V_236 ) ;
F_109 ( V_233 -> V_237 , V_70 -> V_134 + V_238 ) ;
F_112 ( & V_70 -> V_160 , V_229 ) ;
}
void F_155 ( int V_161 , struct V_232 * V_233 )
{
struct V_133 * V_70 = F_154 ( V_161 ) ;
unsigned long V_229 ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
V_233 -> V_60 = F_98 ( V_70 -> V_134 + V_234 ) ;
V_233 -> V_235 = F_98 ( V_70 -> V_134 + V_236 ) ;
V_233 -> V_237 = F_98 ( V_70 -> V_134 + V_238 ) ;
F_112 ( & V_70 -> V_160 , V_229 ) ;
}
static int F_156 ( struct V_133 * V_70 , int type ,
T_5 V_221 , T_3 V_239 , unsigned long long V_118 )
{
const char * V_240 ;
int V_222 ;
V_240 = F_148 ( V_221 , & V_222 ) ;
if ( V_222 == V_224 )
F_68 ( L_39
L_40
L_41 ,
( V_239 >> 8 ) , F_16 ( V_239 & 0xFF ) ,
F_17 ( V_239 & 0xFF ) , V_118 >> 48 ,
V_221 , V_240 ) ;
else
F_68 ( L_42
L_43
L_44 ,
( type ? L_45 : L_46 ) ,
( V_239 >> 8 ) , F_16 ( V_239 & 0xFF ) ,
F_17 ( V_239 & 0xFF ) , V_118 , V_221 , V_240 ) ;
return 0 ;
}
T_11 F_157 ( int V_161 , void * V_241 )
{
struct V_133 * V_70 = V_241 ;
int V_134 , V_242 ;
T_9 V_243 ;
unsigned long V_229 ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
V_243 = F_98 ( V_70 -> V_134 + V_177 ) ;
if ( V_243 )
F_68 ( L_47 , V_243 ) ;
if ( ! ( V_243 & V_244 ) )
goto V_245;
V_242 = F_158 ( V_243 ) ;
V_134 = F_159 ( V_70 -> V_120 ) ;
while ( 1 ) {
T_5 V_221 ;
T_3 V_239 ;
T_7 V_246 ;
int type ;
T_9 V_60 ;
V_60 = F_98 ( V_70 -> V_134 + V_134 +
V_242 * V_247 + 12 ) ;
if ( ! ( V_60 & V_248 ) )
break;
V_221 = F_160 ( V_60 ) ;
type = F_161 ( V_60 ) ;
V_60 = F_98 ( V_70 -> V_134 + V_134 +
V_242 * V_247 + 8 ) ;
V_239 = F_162 ( V_60 ) ;
V_246 = F_80 ( V_70 -> V_134 + V_134 +
V_242 * V_247 ) ;
V_246 = F_163 ( V_246 ) ;
F_109 ( V_248 , V_70 -> V_134 + V_134 +
V_242 * V_247 + 12 ) ;
F_112 ( & V_70 -> V_160 , V_229 ) ;
F_156 ( V_70 , type , V_221 ,
V_239 , V_246 ) ;
V_242 ++ ;
if ( V_242 >= F_164 ( V_70 -> V_120 ) )
V_242 = 0 ;
F_111 ( & V_70 -> V_160 , V_229 ) ;
}
F_109 ( V_249 | V_244 , V_70 -> V_134 + V_177 ) ;
V_245:
F_112 ( & V_70 -> V_160 , V_229 ) ;
return V_250 ;
}
int F_165 ( struct V_133 * V_70 )
{
int V_161 , V_52 ;
if ( V_70 -> V_161 )
return 0 ;
V_161 = F_166 () ;
if ( ! V_161 ) {
F_68 ( L_48 ) ;
return - V_50 ;
}
F_103 ( V_161 , V_70 ) ;
V_70 -> V_161 = V_161 ;
V_52 = F_167 ( V_161 ) ;
if ( V_52 ) {
F_103 ( V_161 , NULL ) ;
V_70 -> V_161 = 0 ;
F_104 ( V_161 ) ;
return V_52 ;
}
V_52 = F_168 ( V_161 , F_157 , V_251 , V_70 -> V_140 , V_70 ) ;
if ( V_52 )
F_68 ( L_49 ) ;
return V_52 ;
}
int T_1 F_169 ( void )
{
struct V_1 * V_2 ;
struct V_133 * V_70 ;
F_170 (iommu, drhd) {
T_9 V_243 ;
int V_52 = F_165 ( V_70 ) ;
if ( V_52 ) {
F_68 ( L_50 ,
( unsigned long long ) V_2 -> V_67 , V_52 ) ;
return - 1 ;
}
F_157 ( V_70 -> V_161 , V_70 ) ;
V_243 = F_98 ( V_70 -> V_134 + V_177 ) ;
F_109 ( V_243 , V_70 -> V_134 + V_177 ) ;
}
return 0 ;
}
int F_171 ( struct V_133 * V_70 )
{
if ( ! F_140 ( V_70 -> V_121 ) )
return - V_218 ;
if ( ! V_70 -> V_162 )
return - V_218 ;
F_138 ( V_70 ) ;
F_142 ( V_70 ) ;
return 0 ;
}
int T_1 F_172 ( void )
{
struct V_101 * V_102 ;
V_102 = (struct V_101 * ) V_98 ;
if ( ! V_102 )
return 0 ;
return V_102 -> V_69 & 0x1 ;
}
static int T_1 F_173 ( void )
{
struct V_1 * V_53 , * V_252 ;
if ( V_253 || V_254 )
return 0 ;
if ( V_38 != 1 && ! F_71 ( & V_5 ) )
F_174 ( & V_115 , & V_116 ) ;
F_34 ( & V_64 ) ;
F_175 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_176 ( & V_53 -> V_4 ) ;
F_38 ( V_53 ) ;
}
F_35 ( & V_64 ) ;
return 0 ;
}
