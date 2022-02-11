static void F_1 ( struct V_1 * V_2 )
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
T_1 V_29 ;
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
void * V_6 , void * V_7 , T_2 V_48 ,
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
int F_26 ( struct V_24 * V_31 , T_2 V_48 ,
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
static struct V_1 *
F_38 ( struct V_56 * V_2 )
{
struct V_1 * V_55 ;
F_39 (dmaru, &dmar_drhd_units, list)
if ( V_55 -> V_48 == V_2 -> V_48 &&
V_55 -> V_68 == V_2 -> V_69 )
return V_55 ;
return NULL ;
}
static int F_40 ( struct V_70 * V_58 , void * V_71 )
{
struct V_56 * V_2 ;
struct V_1 * V_55 ;
int V_54 = 0 ;
V_2 = (struct V_56 * ) V_58 ;
V_55 = F_38 ( V_2 ) ;
if ( V_55 )
goto V_72;
V_55 = F_13 ( sizeof( * V_55 ) + V_58 -> V_17 , V_19 ) ;
if ( ! V_55 )
return - V_39 ;
V_55 -> V_57 = ( void * ) ( V_55 + 1 ) ;
memcpy ( V_55 -> V_57 , V_58 , V_58 -> V_17 ) ;
V_55 -> V_68 = V_2 -> V_69 ;
V_55 -> V_48 = V_2 -> V_48 ;
V_55 -> V_3 = V_2 -> V_73 & 0x1 ;
V_55 -> V_20 = F_4 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_58 . V_17 ,
& V_55 -> V_49 ) ;
if ( V_55 -> V_49 && V_55 -> V_20 == NULL ) {
F_10 ( V_55 ) ;
return - V_39 ;
}
V_54 = F_41 ( V_55 ) ;
if ( V_54 ) {
F_7 ( & V_55 -> V_20 ,
& V_55 -> V_49 ) ;
F_10 ( V_55 ) ;
return V_54 ;
}
F_1 ( V_55 ) ;
V_72:
if ( V_71 )
( * ( int * ) V_71 ) ++ ;
return 0 ;
}
static void F_42 ( struct V_1 * V_55 )
{
if ( V_55 -> V_20 && V_55 -> V_49 )
F_7 ( & V_55 -> V_20 , & V_55 -> V_49 ) ;
if ( V_55 -> V_74 )
F_43 ( V_55 -> V_74 ) ;
F_10 ( V_55 ) ;
}
static int T_3 F_44 ( struct V_70 * V_58 ,
void * V_71 )
{
struct V_75 * V_76 = ( void * ) V_58 ;
if ( F_45 ( V_76 -> V_77 , V_58 -> V_17 - 8 ) == V_58 -> V_17 - 8 ) {
F_46 ( 1 , V_78 ,
L_6
L_7 ,
F_47 ( V_79 ) ,
F_47 ( V_80 ) ,
F_47 ( V_81 ) ) ;
return - V_52 ;
}
F_21 ( L_8 , V_76 -> V_82 ,
V_76 -> V_77 ) ;
return 0 ;
}
static int F_48 ( struct V_70 * V_58 , void * V_71 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 ;
V_84 = (struct V_83 * ) V_58 ;
F_30 (drhd) {
if ( V_2 -> V_68 == V_84 -> V_85 ) {
int V_86 = F_49 ( V_84 -> V_87 ) ;
if ( ! F_50 ( V_86 ) )
V_86 = - 1 ;
V_2 -> V_74 -> V_86 = V_86 ;
return 0 ;
}
}
F_46 (
1 , V_78 ,
L_9
L_7 ,
V_2 -> V_68 ,
F_47 ( V_79 ) ,
F_47 ( V_80 ) ,
F_47 ( V_81 ) ) ;
return 0 ;
}
static void T_3
F_51 ( struct V_70 * V_58 )
{
struct V_56 * V_2 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_83 * V_84 ;
switch ( V_58 -> type ) {
case V_92 :
V_2 = F_31 ( V_58 , struct V_56 ,
V_58 ) ;
F_21 ( L_10 ,
( unsigned long long ) V_2 -> V_69 , V_2 -> V_73 ) ;
break;
case V_93 :
V_89 = F_31 ( V_58 , struct V_88 ,
V_58 ) ;
F_21 ( L_11 ,
( unsigned long long ) V_89 -> V_85 ,
( unsigned long long ) V_89 -> V_94 ) ;
break;
case V_95 :
V_91 = F_31 ( V_58 , struct V_90 , V_58 ) ;
F_21 ( L_12 , V_91 -> V_73 ) ;
break;
case V_96 :
V_84 = F_31 ( V_58 , struct V_83 , V_58 ) ;
F_21 ( L_13 ,
( unsigned long long ) V_84 -> V_85 ,
V_84 -> V_87 ) ;
break;
case V_97 :
break;
}
}
static int T_3 F_52 ( void )
{
T_4 V_98 = V_99 ;
V_98 = F_53 ( V_100 , 0 ,
(struct V_101 * * ) & V_102 ,
& V_103 ) ;
if ( F_54 ( V_98 ) && ! V_102 ) {
F_5 ( L_14 ) ;
V_98 = V_104 ;
}
return ( F_54 ( V_98 ) ? 1 : 0 ) ;
}
static int F_55 ( struct V_70 * V_6 ,
T_1 V_105 , struct V_106 * V_107 )
{
int V_54 = 0 ;
struct V_70 * V_108 , * V_109 ;
struct V_70 * V_7 = ( ( void * ) V_6 ) + V_105 ;
for ( V_108 = V_6 ; V_108 < V_7 && V_54 == 0 ; V_108 = V_109 ) {
V_109 = ( void * ) V_108 + V_108 -> V_17 ;
if ( V_108 -> V_17 == 0 ) {
F_56 ( V_47 L_15 ) ;
break;
} else if ( V_109 > V_7 ) {
F_5 ( V_47 L_16 ) ;
V_54 = - V_52 ;
break;
}
if ( V_107 -> V_110 )
F_51 ( V_108 ) ;
if ( V_108 -> type >= V_111 ) {
F_56 ( L_17 ,
V_108 -> type ) ;
} else if ( V_107 -> V_107 [ V_108 -> type ] ) {
V_54 = V_107 -> V_107 [ V_108 -> type ] ( V_108 , V_107 -> V_71 [ V_108 -> type ] ) ;
} else if ( ! V_107 -> V_112 ) {
F_5 ( L_18 ,
V_108 -> type ) ;
V_54 = - V_52 ;
}
}
return V_54 ;
}
static inline int F_57 ( struct V_113 * V_114 ,
struct V_106 * V_107 )
{
return F_55 ( ( void * ) ( V_114 + 1 ) ,
V_114 -> V_58 . V_17 - sizeof( * V_114 ) , V_107 ) ;
}
static int T_3
F_58 ( void )
{
struct V_113 * V_114 ;
int V_54 = 0 ;
int V_115 = 0 ;
struct V_106 V_107 = {
. V_110 = true ,
. V_112 = true ,
. V_71 [ V_92 ] = & V_115 ,
. V_107 [ V_92 ] = & F_40 ,
. V_107 [ V_93 ] = & V_116 ,
. V_107 [ V_95 ] = & V_117 ,
. V_107 [ V_96 ] = & F_48 ,
. V_107 [ V_97 ] = & F_44 ,
} ;
F_52 () ;
V_102 = F_59 ( V_102 ) ;
V_114 = (struct V_113 * ) V_102 ;
if ( ! V_114 )
return - V_118 ;
if ( V_114 -> V_119 < V_120 - 1 ) {
F_5 ( L_19 ) ;
return - V_52 ;
}
F_21 ( L_20 , V_114 -> V_119 + 1 ) ;
V_54 = F_57 ( V_114 , & V_107 ) ;
if ( V_54 == 0 && V_115 == 0 )
F_5 ( V_47 L_21 ) ;
return V_54 ;
}
static int F_60 ( struct V_18 V_20 [] ,
int V_8 , struct V_25 * V_26 )
{
int V_53 ;
struct V_22 * V_30 ;
while ( V_26 ) {
F_8 (devices, cnt, index, tmp)
if ( F_61 ( V_30 ) && V_26 == F_35 ( V_30 ) )
return 1 ;
V_26 = V_26 -> V_34 -> V_35 ;
}
return 0 ;
}
struct V_1 *
F_62 ( struct V_25 * V_26 )
{
struct V_1 * V_55 ;
struct V_56 * V_2 ;
V_26 = F_63 ( V_26 ) ;
F_64 () ;
F_30 (dmaru) {
V_2 = F_31 ( V_55 -> V_57 ,
struct V_56 ,
V_58 ) ;
if ( V_55 -> V_3 &&
V_2 -> V_48 == F_15 ( V_26 -> V_34 ) )
goto V_72;
if ( F_60 ( V_55 -> V_20 ,
V_55 -> V_49 , V_26 ) )
goto V_72;
}
V_55 = NULL ;
V_72:
F_65 () ;
return V_55 ;
}
static void T_3 F_66 ( T_5 V_82 ,
struct V_121 * V_122 )
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
if ( V_10 -> V_123 != V_82 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_21 ( L_22 ,
F_67 ( & V_122 -> V_26 ) , V_55 -> V_68 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_44 ) ;
F_23 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_55 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_55 -> V_20 [ V_21 ] . V_43 = F_68 ( V_41 -> V_22 ,
V_41 -> V_44 ) ;
F_24 ( V_55 -> V_20 [ V_21 ] . V_26 ,
F_25 ( & V_122 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_55 -> V_49 ) ;
}
}
F_5 ( L_23 ,
V_82 , F_67 ( & V_122 -> V_26 ) ) ;
}
static int T_3 F_69 ( void )
{
struct V_75 * V_76 ;
if ( V_102 == NULL )
return - V_118 ;
for ( V_76 = ( void * ) V_102 + sizeof( struct V_113 ) ;
( ( unsigned long ) V_76 ) < ( ( unsigned long ) V_102 ) + V_102 -> V_17 ;
V_76 = ( ( void * ) V_76 ) + V_76 -> V_58 . V_17 ) {
if ( V_76 -> V_58 . type == V_97 ) {
T_6 V_124 ;
struct V_121 * V_122 ;
if ( ! F_54 ( F_70 ( V_125 ,
V_76 -> V_77 ,
& V_124 ) ) ) {
F_71 ( L_24 ,
V_76 -> V_77 ) ;
continue;
}
if ( F_72 ( V_124 , & V_122 ) ) {
F_71 ( L_25 ,
V_76 -> V_77 ) ;
continue;
}
F_66 ( V_76 -> V_82 , V_122 ) ;
}
}
return 0 ;
}
int T_3 F_73 ( void )
{
struct V_25 * V_26 = NULL ;
struct V_24 * V_31 ;
if ( V_38 != 1 )
return V_38 ;
if ( F_74 ( & V_5 ) ) {
V_38 = - V_118 ;
} else {
V_38 = 0 ;
F_69 () ;
F_75 (dev) {
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
F_76 ( & V_126 , & V_127 ) ;
}
return V_38 ;
}
int T_3 F_77 ( void )
{
static int V_128 ;
int V_54 ;
if ( V_128 == 0 ) {
V_54 = F_58 () ;
if ( V_54 < 0 ) {
if ( V_54 != - V_118 )
F_21 ( L_26 ) ;
} else if ( F_74 ( & V_5 ) ) {
F_21 ( L_27 ) ;
V_54 = - V_118 ;
}
if ( V_54 < 0 )
V_128 = V_54 ;
else
V_128 = 1 ;
}
return V_128 < 0 ? V_128 : 0 ;
}
static void F_78 ( T_7 V_129 , const char * V_130 )
{
F_79 (
1 , V_78 ,
L_28
L_7 ,
V_129 , V_130 ,
F_47 ( V_79 ) ,
F_47 ( V_80 ) ,
F_47 ( V_81 ) ) ;
}
static int T_8
F_80 ( struct V_70 * V_131 , void * V_71 )
{
struct V_56 * V_2 ;
void T_9 * V_129 ;
T_7 V_132 , V_133 ;
V_2 = ( void * ) V_131 ;
if ( ! V_2 -> V_69 ) {
F_78 ( 0 , L_29 ) ;
return - V_52 ;
}
if ( V_71 )
V_129 = F_81 ( V_2 -> V_69 , V_134 ) ;
else
V_129 = F_82 ( V_2 -> V_69 , V_134 ) ;
if ( ! V_129 ) {
F_5 ( L_30 , V_2 -> V_69 ) ;
return - V_52 ;
}
V_132 = F_83 ( V_129 + V_135 ) ;
V_133 = F_83 ( V_129 + V_136 ) ;
if ( V_71 )
F_84 ( V_129 ) ;
else
F_85 ( V_129 , V_134 ) ;
if ( V_132 == ( V_137 ) - 1 && V_133 == ( V_137 ) - 1 ) {
F_78 ( V_2 -> V_69 , L_31 ) ;
return - V_52 ;
}
return 0 ;
}
int T_3 F_86 ( void )
{
int V_54 ;
struct V_106 V_138 = {
. V_107 [ V_92 ] = & F_80 ,
. V_112 = true ,
} ;
F_36 ( & V_66 ) ;
V_54 = F_52 () ;
if ( V_54 )
V_54 = ! F_57 ( (struct V_113 * ) V_102 ,
& V_138 ) ;
if ( V_54 && ! V_139 && ! V_140 && ! V_141 ) {
V_140 = 1 ;
F_87 () ;
}
#ifdef F_88
if ( V_54 )
V_142 . V_74 . V_143 = V_144 ;
#endif
F_89 ( ( void T_9 * ) V_102 , V_103 ) ;
V_102 = NULL ;
F_37 ( & V_66 ) ;
return V_54 ? 1 : - V_118 ;
}
static void F_90 ( struct V_145 * V_74 )
{
F_84 ( V_74 -> V_146 ) ;
F_91 ( V_74 -> V_147 , V_74 -> V_148 ) ;
}
static int F_92 ( struct V_145 * V_74 , T_7 V_149 )
{
int V_150 , V_151 = 0 ;
V_74 -> V_147 = V_149 ;
V_74 -> V_148 = V_134 ;
if ( ! F_93 ( V_74 -> V_147 , V_74 -> V_148 , V_74 -> V_152 ) ) {
F_71 ( L_32 ) ;
V_151 = - V_153 ;
goto V_72;
}
V_74 -> V_146 = F_81 ( V_74 -> V_147 , V_74 -> V_148 ) ;
if ( ! V_74 -> V_146 ) {
F_71 ( L_33 ) ;
V_151 = - V_39 ;
goto V_154;
}
V_74 -> V_132 = F_83 ( V_74 -> V_146 + V_135 ) ;
V_74 -> V_133 = F_83 ( V_74 -> V_146 + V_136 ) ;
if ( V_74 -> V_132 == ( V_137 ) - 1 && V_74 -> V_133 == ( V_137 ) - 1 ) {
V_151 = - V_52 ;
F_78 ( V_149 , L_31 ) ;
goto V_155;
}
V_150 = F_94 ( int , F_95 ( V_74 -> V_133 ) ,
F_96 ( V_74 -> V_132 ) ) ;
V_150 = F_97 ( V_150 ) ;
if ( V_150 > V_74 -> V_148 ) {
F_84 ( V_74 -> V_146 ) ;
F_91 ( V_74 -> V_147 , V_74 -> V_148 ) ;
V_74 -> V_148 = V_150 ;
if ( ! F_93 ( V_74 -> V_147 , V_74 -> V_148 ,
V_74 -> V_152 ) ) {
F_71 ( L_32 ) ;
V_151 = - V_153 ;
goto V_72;
}
V_74 -> V_146 = F_81 ( V_74 -> V_147 , V_74 -> V_148 ) ;
if ( ! V_74 -> V_146 ) {
F_71 ( L_33 ) ;
V_151 = - V_39 ;
goto V_154;
}
}
V_151 = 0 ;
goto V_72;
V_155:
F_84 ( V_74 -> V_146 ) ;
V_154:
F_91 ( V_74 -> V_147 , V_74 -> V_148 ) ;
V_72:
return V_151 ;
}
static int F_98 ( struct V_145 * V_74 )
{
V_74 -> V_156 = F_99 ( V_157 ,
V_158 ) ;
if ( V_74 -> V_156 >= V_158 ) {
V_74 -> V_156 = - 1 ;
} else {
F_100 ( V_74 -> V_156 , V_157 ) ;
sprintf ( V_74 -> V_152 , L_34 , V_74 -> V_156 ) ;
}
return V_74 -> V_156 ;
}
static void F_101 ( struct V_145 * V_74 )
{
if ( V_74 -> V_156 >= 0 ) {
F_102 ( V_74 -> V_156 , V_157 ) ;
V_74 -> V_156 = - 1 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_145 * V_74 ;
T_10 V_159 , V_160 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_151 ;
if ( ! V_2 -> V_68 ) {
F_78 ( 0 , L_29 ) ;
return - V_52 ;
}
V_74 = F_13 ( sizeof( * V_74 ) , V_19 ) ;
if ( ! V_74 )
return - V_39 ;
if ( F_98 ( V_74 ) < 0 ) {
F_71 ( L_35 ) ;
V_151 = - V_163 ;
goto error;
}
V_151 = F_92 ( V_74 , V_2 -> V_68 ) ;
if ( V_151 ) {
F_71 ( L_36 , V_74 -> V_152 ) ;
goto V_164;
}
V_151 = - V_52 ;
V_161 = F_103 ( V_74 ) ;
if ( V_161 < 0 ) {
F_71 ( L_37 ,
V_74 -> V_156 ) ;
goto V_165;
}
V_162 = F_104 ( V_74 ) ;
if ( V_162 < 0 ) {
F_71 ( L_38 ,
V_74 -> V_156 ) ;
goto V_165;
}
V_74 -> V_161 = V_161 ;
V_74 -> V_162 = V_162 ;
V_74 -> V_48 = V_2 -> V_48 ;
V_74 -> V_86 = - 1 ;
V_159 = F_105 ( V_74 -> V_146 + V_166 ) ;
F_21 ( L_39 ,
V_74 -> V_152 ,
( unsigned long long ) V_2 -> V_68 ,
F_106 ( V_159 ) , F_107 ( V_159 ) ,
( unsigned long long ) V_74 -> V_132 ,
( unsigned long long ) V_74 -> V_133 ) ;
V_160 = F_105 ( V_74 -> V_146 + V_167 ) ;
if ( V_160 & V_168 )
V_74 -> V_169 |= V_170 ;
if ( V_160 & V_171 )
V_74 -> V_169 |= V_172 ;
if ( V_160 & V_173 )
V_74 -> V_169 |= V_174 ;
F_108 ( & V_74 -> V_175 ) ;
V_2 -> V_74 = V_74 ;
if ( V_176 )
V_74 -> V_177 = F_109 ( NULL , V_74 ,
V_178 ,
V_74 -> V_152 ) ;
return 0 ;
V_165:
F_90 ( V_74 ) ;
V_164:
F_101 ( V_74 ) ;
error:
F_10 ( V_74 ) ;
return V_151 ;
}
static void F_43 ( struct V_145 * V_74 )
{
F_110 ( V_74 -> V_177 ) ;
if ( V_74 -> V_179 ) {
F_111 ( V_74 -> V_179 , V_74 ) ;
F_112 ( V_74 -> V_179 ) ;
V_74 -> V_179 = 0 ;
}
if ( V_74 -> V_180 ) {
F_113 ( ( unsigned long ) V_74 -> V_180 -> V_181 ) ;
F_10 ( V_74 -> V_180 -> V_182 ) ;
F_10 ( V_74 -> V_180 ) ;
}
if ( V_74 -> V_146 )
F_90 ( V_74 ) ;
F_101 ( V_74 ) ;
F_10 ( V_74 ) ;
}
static inline void F_114 ( struct V_183 * V_180 )
{
while ( V_180 -> V_182 [ V_180 -> V_184 ] == V_185 ||
V_180 -> V_182 [ V_180 -> V_184 ] == V_186 ) {
V_180 -> V_182 [ V_180 -> V_184 ] = V_187 ;
V_180 -> V_184 = ( V_180 -> V_184 + 1 ) % V_188 ;
V_180 -> V_189 ++ ;
}
}
static int F_115 ( struct V_145 * V_74 , int V_53 )
{
T_10 V_190 ;
int V_191 , V_192 ;
struct V_183 * V_180 = V_74 -> V_180 ;
int V_193 = ( V_53 + 1 ) % V_188 ;
if ( V_180 -> V_182 [ V_193 ] == V_186 )
return - V_194 ;
V_190 = F_105 ( V_74 -> V_146 + V_195 ) ;
if ( V_190 & V_196 ) {
V_191 = F_105 ( V_74 -> V_146 + V_197 ) ;
if ( ( V_191 >> V_198 ) == V_53 ) {
F_71 ( L_40
L_41 ,
( unsigned long long ) V_180 -> V_181 [ V_53 ] . V_199 ,
( unsigned long long ) V_180 -> V_181 [ V_53 ] . V_200 ) ;
memcpy ( & V_180 -> V_181 [ V_53 ] , & V_180 -> V_181 [ V_193 ] ,
sizeof( struct V_201 ) ) ;
F_116 ( V_74 , & V_180 -> V_181 [ V_53 ] ,
sizeof( struct V_201 ) ) ;
F_117 ( V_196 , V_74 -> V_146 + V_195 ) ;
return - V_52 ;
}
}
if ( V_190 & V_202 ) {
V_191 = F_105 ( V_74 -> V_146 + V_197 ) ;
V_191 = ( ( V_191 >> V_198 ) - 1 + V_188 ) % V_188 ;
V_191 |= 1 ;
V_192 = F_105 ( V_74 -> V_146 + V_203 ) ;
V_192 = ( ( V_192 >> V_198 ) - 1 + V_188 ) % V_188 ;
F_117 ( V_202 , V_74 -> V_146 + V_195 ) ;
do {
if ( V_180 -> V_182 [ V_191 ] == V_204 )
V_180 -> V_182 [ V_191 ] = V_186 ;
V_191 = ( V_191 - 2 + V_188 ) % V_188 ;
} while ( V_191 != V_192 );
if ( V_180 -> V_182 [ V_193 ] == V_186 )
return - V_194 ;
}
if ( V_190 & V_205 )
F_117 ( V_205 , V_74 -> V_146 + V_195 ) ;
return 0 ;
}
int F_118 ( struct V_201 * V_181 , struct V_145 * V_74 )
{
int V_206 ;
struct V_183 * V_180 = V_74 -> V_180 ;
struct V_201 * V_207 , V_208 ;
int V_193 , V_53 ;
unsigned long V_73 ;
if ( ! V_180 )
return 0 ;
V_207 = V_180 -> V_181 ;
V_209:
V_206 = 0 ;
F_119 ( & V_180 -> V_210 , V_73 ) ;
while ( V_180 -> V_189 < 3 ) {
F_120 ( & V_180 -> V_210 , V_73 ) ;
F_121 () ;
F_119 ( & V_180 -> V_210 , V_73 ) ;
}
V_53 = V_180 -> V_211 ;
V_193 = ( V_53 + 1 ) % V_188 ;
V_180 -> V_182 [ V_53 ] = V_180 -> V_182 [ V_193 ] = V_204 ;
V_207 [ V_53 ] = * V_181 ;
V_208 . V_199 = F_122 ( V_185 ) |
V_212 | V_213 ;
V_208 . V_200 = F_123 ( & V_180 -> V_182 [ V_193 ] ) ;
V_207 [ V_193 ] = V_208 ;
F_116 ( V_74 , & V_207 [ V_53 ] , sizeof( struct V_201 ) ) ;
F_116 ( V_74 , & V_207 [ V_193 ] , sizeof( struct V_201 ) ) ;
V_180 -> V_211 = ( V_180 -> V_211 + 2 ) % V_188 ;
V_180 -> V_189 -= 2 ;
F_117 ( V_180 -> V_211 << V_198 , V_74 -> V_146 + V_203 ) ;
while ( V_180 -> V_182 [ V_193 ] != V_185 ) {
V_206 = F_115 ( V_74 , V_53 ) ;
if ( V_206 )
break;
F_124 ( & V_180 -> V_210 ) ;
F_121 () ;
F_125 ( & V_180 -> V_210 ) ;
}
V_180 -> V_182 [ V_53 ] = V_185 ;
F_114 ( V_180 ) ;
F_120 ( & V_180 -> V_210 , V_73 ) ;
if ( V_206 == - V_194 )
goto V_209;
return V_206 ;
}
void F_126 ( struct V_145 * V_74 )
{
struct V_201 V_181 ;
V_181 . V_199 = V_214 ;
V_181 . V_200 = 0 ;
F_118 ( & V_181 , V_74 ) ;
}
void F_127 ( struct V_145 * V_74 , T_2 V_215 , T_2 V_216 , T_5 V_217 ,
T_7 type )
{
struct V_201 V_181 ;
V_181 . V_199 = F_128 ( V_217 ) | F_129 ( V_216 ) | F_130 ( V_215 )
| F_131 ( type ) | V_218 ;
V_181 . V_200 = 0 ;
F_118 ( & V_181 , V_74 ) ;
}
void F_132 ( struct V_145 * V_74 , T_2 V_215 , T_7 V_129 ,
unsigned int V_219 , T_7 type )
{
T_5 V_220 = 0 , V_221 = 0 ;
struct V_201 V_181 ;
int V_222 = 0 ;
if ( F_133 ( V_74 -> V_132 ) )
V_220 = 1 ;
if ( F_134 ( V_74 -> V_132 ) )
V_221 = 1 ;
V_181 . V_199 = F_135 ( V_215 ) | F_136 ( V_221 ) | F_137 ( V_220 )
| F_138 ( type ) | V_223 ;
V_181 . V_200 = F_139 ( V_129 ) | F_140 ( V_222 )
| F_141 ( V_219 ) ;
F_118 ( & V_181 , V_74 ) ;
}
void F_142 ( struct V_145 * V_74 , T_2 V_216 , T_2 V_224 ,
T_7 V_129 , unsigned V_225 )
{
struct V_201 V_181 ;
if ( V_225 ) {
F_12 ( V_129 & ( ( 1 << ( V_226 + V_225 ) ) - 1 ) ) ;
V_129 |= ( 1 << ( V_226 + V_225 - 1 ) ) - 1 ;
V_181 . V_200 = F_143 ( V_129 ) | V_227 ;
} else
V_181 . V_200 = F_143 ( V_129 ) ;
if ( V_224 >= V_228 )
V_224 = 0 ;
V_181 . V_199 = F_144 ( V_216 ) | F_145 ( V_224 ) |
V_229 ;
F_118 ( & V_181 , V_74 ) ;
}
void F_146 ( struct V_145 * V_74 )
{
unsigned long V_73 ;
T_10 V_160 ;
T_11 V_230 = F_147 () ;
if ( ! F_148 ( V_74 -> V_133 ) )
return;
F_119 ( & V_74 -> V_175 , V_73 ) ;
V_160 = F_83 ( V_74 -> V_146 + V_167 ) ;
if ( ! ( V_160 & V_173 ) )
goto V_7;
while ( ( F_105 ( V_74 -> V_146 + V_203 ) !=
F_105 ( V_74 -> V_146 + V_197 ) ) &&
( V_231 > ( F_147 () - V_230 ) ) )
F_121 () ;
V_74 -> V_169 &= ~ V_174 ;
F_117 ( V_74 -> V_169 , V_74 -> V_146 + V_232 ) ;
F_149 ( V_74 , V_167 , F_105 ,
! ( V_160 & V_173 ) , V_160 ) ;
V_7:
F_120 ( & V_74 -> V_175 , V_73 ) ;
}
static void F_150 ( struct V_145 * V_74 )
{
T_10 V_160 ;
unsigned long V_73 ;
struct V_183 * V_180 = V_74 -> V_180 ;
V_180 -> V_211 = V_180 -> V_184 = 0 ;
V_180 -> V_189 = V_188 ;
F_119 ( & V_74 -> V_175 , V_73 ) ;
F_117 ( 0 , V_74 -> V_146 + V_203 ) ;
F_151 ( V_74 -> V_146 + V_233 , F_123 ( V_180 -> V_181 ) ) ;
V_74 -> V_169 |= V_174 ;
F_117 ( V_74 -> V_169 , V_74 -> V_146 + V_232 ) ;
F_149 ( V_74 , V_167 , F_105 , ( V_160 & V_173 ) , V_160 ) ;
F_120 ( & V_74 -> V_175 , V_73 ) ;
}
int F_152 ( struct V_145 * V_74 )
{
struct V_183 * V_180 ;
struct V_234 * V_235 ;
if ( ! F_148 ( V_74 -> V_133 ) )
return - V_236 ;
if ( V_74 -> V_180 )
return 0 ;
V_74 -> V_180 = F_153 ( sizeof( * V_180 ) , V_237 ) ;
if ( ! V_74 -> V_180 )
return - V_39 ;
V_180 = V_74 -> V_180 ;
V_235 = F_154 ( V_74 -> V_86 , V_237 | V_238 , 0 ) ;
if ( ! V_235 ) {
F_10 ( V_180 ) ;
V_74 -> V_180 = NULL ;
return - V_39 ;
}
V_180 -> V_181 = F_155 ( V_235 ) ;
V_180 -> V_182 = F_13 ( V_188 * sizeof( int ) , V_237 ) ;
if ( ! V_180 -> V_182 ) {
F_113 ( ( unsigned long ) V_180 -> V_181 ) ;
F_10 ( V_180 ) ;
V_74 -> V_180 = NULL ;
return - V_39 ;
}
F_108 ( & V_180 -> V_210 ) ;
F_150 ( V_74 ) ;
return 0 ;
}
static const char * F_156 ( T_5 V_239 , int * V_240 )
{
if ( V_239 >= 0x20 && ( V_239 - 0x20 <
F_157 ( V_241 ) ) ) {
* V_240 = V_242 ;
return V_241 [ V_239 - 0x20 ] ;
} else if ( V_239 < F_157 ( V_243 ) ) {
* V_240 = V_244 ;
return V_243 [ V_239 ] ;
} else {
* V_240 = V_245 ;
return L_42 ;
}
}
void F_158 ( struct V_246 * V_62 )
{
struct V_145 * V_74 = F_159 ( V_62 ) ;
unsigned long V_247 ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
F_117 ( 0 , V_74 -> V_146 + V_248 ) ;
F_105 ( V_74 -> V_146 + V_248 ) ;
F_120 ( & V_74 -> V_175 , V_247 ) ;
}
void F_160 ( struct V_246 * V_62 )
{
unsigned long V_247 ;
struct V_145 * V_74 = F_159 ( V_62 ) ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
F_117 ( V_249 , V_74 -> V_146 + V_248 ) ;
F_105 ( V_74 -> V_146 + V_248 ) ;
F_120 ( & V_74 -> V_175 , V_247 ) ;
}
void F_161 ( int V_179 , struct V_250 * V_251 )
{
struct V_145 * V_74 = F_162 ( V_179 ) ;
unsigned long V_247 ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
F_117 ( V_251 -> V_62 , V_74 -> V_146 + V_252 ) ;
F_117 ( V_251 -> V_253 , V_74 -> V_146 + V_254 ) ;
F_117 ( V_251 -> V_255 , V_74 -> V_146 + V_256 ) ;
F_120 ( & V_74 -> V_175 , V_247 ) ;
}
void F_163 ( int V_179 , struct V_250 * V_251 )
{
struct V_145 * V_74 = F_162 ( V_179 ) ;
unsigned long V_247 ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
V_251 -> V_62 = F_105 ( V_74 -> V_146 + V_252 ) ;
V_251 -> V_253 = F_105 ( V_74 -> V_146 + V_254 ) ;
V_251 -> V_255 = F_105 ( V_74 -> V_146 + V_256 ) ;
F_120 ( & V_74 -> V_175 , V_247 ) ;
}
static int F_164 ( struct V_145 * V_74 , int type ,
T_5 V_239 , T_2 V_257 , unsigned long long V_129 )
{
const char * V_258 ;
int V_240 ;
V_258 = F_156 ( V_239 , & V_240 ) ;
if ( V_240 == V_242 )
F_71 ( L_43
L_44
L_45 ,
( V_257 >> 8 ) , F_16 ( V_257 & 0xFF ) ,
F_17 ( V_257 & 0xFF ) , V_129 >> 48 ,
V_239 , V_258 ) ;
else
F_71 ( L_46
L_47
L_48 ,
( type ? L_49 : L_50 ) ,
( V_257 >> 8 ) , F_16 ( V_257 & 0xFF ) ,
F_17 ( V_257 & 0xFF ) , V_129 , V_239 , V_258 ) ;
return 0 ;
}
T_12 F_165 ( int V_179 , void * V_259 )
{
struct V_145 * V_74 = V_259 ;
int V_146 , V_260 ;
T_10 V_261 ;
unsigned long V_247 ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
V_261 = F_105 ( V_74 -> V_146 + V_195 ) ;
if ( V_261 )
F_71 ( L_51 , V_261 ) ;
if ( ! ( V_261 & V_262 ) )
goto V_263;
V_260 = F_166 ( V_261 ) ;
V_146 = F_167 ( V_74 -> V_132 ) ;
while ( 1 ) {
T_5 V_239 ;
T_2 V_257 ;
T_7 V_264 ;
int type ;
T_10 V_62 ;
V_62 = F_105 ( V_74 -> V_146 + V_146 +
V_260 * V_265 + 12 ) ;
if ( ! ( V_62 & V_266 ) )
break;
V_239 = F_168 ( V_62 ) ;
type = F_169 ( V_62 ) ;
V_62 = F_105 ( V_74 -> V_146 + V_146 +
V_260 * V_265 + 8 ) ;
V_257 = F_170 ( V_62 ) ;
V_264 = F_83 ( V_74 -> V_146 + V_146 +
V_260 * V_265 ) ;
V_264 = F_171 ( V_264 ) ;
F_117 ( V_266 , V_74 -> V_146 + V_146 +
V_260 * V_265 + 12 ) ;
F_120 ( & V_74 -> V_175 , V_247 ) ;
F_164 ( V_74 , type , V_239 ,
V_257 , V_264 ) ;
V_260 ++ ;
if ( V_260 >= F_172 ( V_74 -> V_132 ) )
V_260 = 0 ;
F_119 ( & V_74 -> V_175 , V_247 ) ;
}
F_117 ( V_267 | V_262 , V_74 -> V_146 + V_195 ) ;
V_263:
F_120 ( & V_74 -> V_175 , V_247 ) ;
return V_268 ;
}
int F_173 ( struct V_145 * V_74 )
{
int V_179 , V_54 ;
if ( V_74 -> V_179 )
return 0 ;
V_179 = F_174 ( V_74 -> V_156 , V_74 -> V_86 , V_74 ) ;
if ( V_179 > 0 ) {
V_74 -> V_179 = V_179 ;
} else {
F_71 ( L_52 ) ;
return - V_52 ;
}
V_54 = F_175 ( V_179 , F_165 , V_269 , V_74 -> V_152 , V_74 ) ;
if ( V_54 )
F_71 ( L_53 ) ;
return V_54 ;
}
int T_3 F_176 ( void )
{
struct V_1 * V_2 ;
struct V_145 * V_74 ;
F_177 (iommu, drhd) {
T_10 V_261 ;
int V_54 = F_173 ( V_74 ) ;
if ( V_54 ) {
F_71 ( L_54 ,
( unsigned long long ) V_2 -> V_68 , V_54 ) ;
return - 1 ;
}
F_165 ( V_74 -> V_179 , V_74 ) ;
V_261 = F_105 ( V_74 -> V_146 + V_195 ) ;
F_117 ( V_261 , V_74 -> V_146 + V_195 ) ;
}
return 0 ;
}
int F_178 ( struct V_145 * V_74 )
{
if ( ! F_148 ( V_74 -> V_133 ) )
return - V_236 ;
if ( ! V_74 -> V_180 )
return - V_236 ;
F_146 ( V_74 ) ;
F_150 ( V_74 ) ;
return 0 ;
}
int T_3 F_179 ( void )
{
struct V_113 * V_114 ;
V_114 = (struct V_113 * ) V_102 ;
if ( ! V_114 )
return 0 ;
return V_114 -> V_73 & 0x1 ;
}
static inline bool F_180 ( void )
{
return V_270 || V_176 ;
}
static int T_3 F_181 ( void )
{
struct V_1 * V_55 , * V_271 ;
if ( F_180 () )
return 0 ;
if ( V_38 != 1 && ! F_74 ( & V_5 ) )
F_182 ( & V_126 , & V_127 ) ;
F_36 ( & V_66 ) ;
F_183 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_184 ( & V_55 -> V_4 ) ;
F_42 ( V_55 ) ;
}
F_37 ( & V_66 ) ;
return 0 ;
}
static inline bool F_185 ( T_6 V_272 , int V_273 )
{
return F_186 ( V_272 , V_274 , V_275 , 1 << V_273 ) ;
}
static int F_187 ( T_6 V_272 , int V_273 ,
T_13 V_276 , void * V_71 )
{
int V_54 = - V_118 ;
union V_277 * V_278 ;
struct V_70 * V_6 ;
struct V_106 V_279 ;
static int V_280 [] = {
[ V_281 ] = V_92 ,
[ V_282 ] = V_95 ,
[ V_283 ] = V_96 ,
} ;
if ( ! F_185 ( V_272 , V_273 ) )
return 0 ;
V_278 = F_188 ( V_272 , V_274 , V_275 ,
V_273 , NULL , V_284 ) ;
if ( ! V_278 )
return - V_118 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_107 [ V_280 [ V_273 ] ] = V_276 ;
V_279 . V_71 [ V_280 [ V_273 ] ] = V_71 ;
V_6 = (struct V_70 * ) V_278 -> V_285 . V_286 ;
V_54 = F_55 ( V_6 , V_278 -> V_285 . V_17 , & V_279 ) ;
F_189 ( V_278 ) ;
return V_54 ;
}
static int F_190 ( struct V_70 * V_58 , void * V_71 )
{
int V_54 ;
struct V_1 * V_55 ;
V_55 = F_38 ( (struct V_56 * ) V_58 ) ;
if ( ! V_55 )
return - V_118 ;
V_54 = F_191 ( V_55 , true ) ;
if ( V_54 == 0 )
V_54 = F_192 ( V_55 , true ) ;
return V_54 ;
}
static int F_193 ( struct V_70 * V_58 , void * V_71 )
{
int V_21 , V_54 ;
struct V_22 * V_26 ;
struct V_1 * V_55 ;
V_55 = F_38 ( (struct V_56 * ) V_58 ) ;
if ( ! V_55 )
return 0 ;
if ( ! V_55 -> V_3 && V_55 -> V_20 && V_55 -> V_49 )
F_8 (dmaru->devices,
dmaru->devices_cnt, i, dev)
return - V_153 ;
V_54 = F_191 ( V_55 , false ) ;
if ( V_54 == 0 )
V_54 = F_192 ( V_55 , false ) ;
return V_54 ;
}
static int F_194 ( struct V_70 * V_58 , void * V_71 )
{
struct V_1 * V_55 ;
V_55 = F_38 ( (struct V_56 * ) V_58 ) ;
if ( V_55 ) {
F_195 ( & V_55 -> V_4 ) ;
F_28 () ;
F_42 ( V_55 ) ;
}
return 0 ;
}
static int F_196 ( T_6 V_272 )
{
int V_54 ;
int V_115 = 0 ;
V_54 = F_187 ( V_272 , V_281 ,
& F_80 , ( void * ) 1 ) ;
if ( V_54 )
goto V_72;
V_54 = F_187 ( V_272 , V_281 ,
& F_40 , ( void * ) & V_115 ) ;
if ( V_54 == 0 && V_115 == 0 ) {
F_5 ( V_47 L_55 ) ;
goto V_72;
} else if ( V_54 ) {
goto V_287;
}
V_54 = F_187 ( V_272 , V_283 ,
& F_48 , NULL ) ;
if ( V_54 )
goto V_287;
V_54 = F_187 ( V_272 , V_282 ,
& V_117 , NULL ) ;
if ( V_54 )
goto V_288;
V_54 = F_187 ( V_272 , V_281 ,
& F_190 , NULL ) ;
if ( ! V_54 )
return 0 ;
F_187 ( V_272 , V_281 ,
& F_193 , NULL ) ;
V_288:
F_187 ( V_272 , V_282 ,
& V_289 , NULL ) ;
V_287:
F_187 ( V_272 , V_281 ,
& F_194 , NULL ) ;
V_72:
return V_54 ;
}
static int F_197 ( T_6 V_272 )
{
int V_54 ;
V_54 = F_187 ( V_272 , V_282 ,
& V_290 , NULL ) ;
if ( V_54 )
return V_54 ;
V_54 = F_187 ( V_272 , V_281 ,
& F_193 , NULL ) ;
if ( V_54 == 0 ) {
F_198 ( F_187 ( V_272 , V_282 ,
& V_289 , NULL ) ) ;
F_198 ( F_187 ( V_272 , V_281 ,
& F_194 , NULL ) ) ;
} else {
F_187 ( V_272 , V_281 ,
& F_190 , NULL ) ;
}
return V_54 ;
}
static T_4 F_199 ( T_6 V_272 , T_10 V_291 ,
void * V_292 , void * * V_293 )
{
T_6 * V_294 = V_293 ;
if ( F_185 ( V_272 , V_281 ) ) {
* V_294 = V_272 ;
return V_295 ;
}
return V_99 ;
}
static int F_200 ( T_6 V_272 , bool V_296 )
{
int V_54 ;
T_6 V_30 = NULL ;
T_4 V_98 ;
if ( ! F_180 () )
return 0 ;
if ( F_185 ( V_272 , V_281 ) ) {
V_30 = V_272 ;
} else {
V_98 = F_201 ( V_297 , V_272 ,
V_298 ,
F_199 ,
NULL , NULL , & V_30 ) ;
if ( F_202 ( V_98 ) ) {
F_5 ( L_56 ) ;
return - V_299 ;
}
}
if ( V_30 == NULL )
return 0 ;
F_36 ( & V_66 ) ;
if ( V_296 )
V_54 = F_196 ( V_30 ) ;
else
V_54 = F_197 ( V_30 ) ;
F_37 ( & V_66 ) ;
return V_54 ;
}
int F_203 ( T_6 V_272 )
{
return F_200 ( V_272 , true ) ;
}
int F_204 ( T_6 V_272 )
{
return F_200 ( V_272 , false ) ;
}
