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
if ( ( V_10 -> V_11 == V_13 &&
V_31 -> V_26 -> V_50 != V_51 ) ||
( V_10 -> V_11 == V_14 &&
( V_31 -> V_26 -> V_50 == V_51 &&
V_31 -> V_26 -> V_52 >> 8 != V_53 ) ) ) {
F_5 ( L_5 ,
F_14 ( V_31 -> V_26 ) ) ;
return - V_54 ;
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
int V_55 ;
struct V_22 * V_30 ;
if ( V_31 -> V_40 != V_48 )
return 0 ;
F_8 (devices, count, index, tmp)
if ( V_30 == & V_31 -> V_26 -> V_26 ) {
F_27 ( V_20 [ V_55 ] . V_26 , NULL ) ;
F_28 () ;
F_9 ( V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_29 ( struct V_24 * V_31 )
{
int V_56 = 0 ;
struct V_1 * V_57 ;
struct V_58 * V_2 ;
F_30 (dmaru) {
if ( V_57 -> V_3 )
continue;
V_2 = F_31 ( V_57 -> V_59 ,
struct V_58 , V_60 ) ;
V_56 = F_22 ( V_31 , ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_60 . V_17 ,
V_57 -> V_48 ,
V_57 -> V_20 , V_57 -> V_49 ) ;
if ( V_56 != 0 )
break;
}
if ( V_56 >= 0 )
V_56 = F_32 ( V_31 ) ;
if ( V_56 < 0 && V_38 == 0 )
V_38 = V_56 ;
return V_56 ;
}
static void F_33 ( struct V_24 * V_31 )
{
struct V_1 * V_57 ;
F_30 (dmaru)
if ( F_26 ( V_31 , V_57 -> V_48 ,
V_57 -> V_20 , V_57 -> V_49 ) )
break;
F_32 ( V_31 ) ;
}
static int F_34 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
struct V_25 * V_65 = F_35 ( V_64 ) ;
struct V_24 * V_31 ;
if ( V_65 -> V_32 )
return V_66 ;
if ( V_63 != V_33 &&
V_63 != V_67 )
return V_66 ;
V_31 = F_11 ( V_65 , V_63 ) ;
if ( ! V_31 )
return V_66 ;
F_36 ( & V_68 ) ;
if ( V_63 == V_33 )
F_29 ( V_31 ) ;
else if ( V_63 == V_67 )
F_33 ( V_31 ) ;
F_37 ( & V_68 ) ;
F_19 ( V_31 ) ;
return V_69 ;
}
static struct V_1 *
F_38 ( struct V_58 * V_2 )
{
struct V_1 * V_57 ;
F_39 (dmaru, &dmar_drhd_units, list)
if ( V_57 -> V_48 == V_2 -> V_48 &&
V_57 -> V_70 == V_2 -> V_71 )
return V_57 ;
return NULL ;
}
static int F_40 ( struct V_72 * V_60 , void * V_73 )
{
struct V_58 * V_2 ;
struct V_1 * V_57 ;
int V_56 = 0 ;
V_2 = (struct V_58 * ) V_60 ;
V_57 = F_38 ( V_2 ) ;
if ( V_57 )
goto V_74;
V_57 = F_13 ( sizeof( * V_57 ) + V_60 -> V_17 , V_19 ) ;
if ( ! V_57 )
return - V_39 ;
V_57 -> V_59 = ( void * ) ( V_57 + 1 ) ;
memcpy ( V_57 -> V_59 , V_60 , V_60 -> V_17 ) ;
V_57 -> V_70 = V_2 -> V_71 ;
V_57 -> V_48 = V_2 -> V_48 ;
V_57 -> V_3 = V_2 -> V_75 & 0x1 ;
V_57 -> V_20 = F_4 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_60 . V_17 ,
& V_57 -> V_49 ) ;
if ( V_57 -> V_49 && V_57 -> V_20 == NULL ) {
F_10 ( V_57 ) ;
return - V_39 ;
}
V_56 = F_41 ( V_57 ) ;
if ( V_56 ) {
F_7 ( & V_57 -> V_20 ,
& V_57 -> V_49 ) ;
F_10 ( V_57 ) ;
return V_56 ;
}
F_1 ( V_57 ) ;
V_74:
if ( V_73 )
( * ( int * ) V_73 ) ++ ;
return 0 ;
}
static void F_42 ( struct V_1 * V_57 )
{
if ( V_57 -> V_20 && V_57 -> V_49 )
F_7 ( & V_57 -> V_20 , & V_57 -> V_49 ) ;
if ( V_57 -> V_76 )
F_43 ( V_57 -> V_76 ) ;
F_10 ( V_57 ) ;
}
static int T_3 F_44 ( struct V_72 * V_60 ,
void * V_73 )
{
struct V_77 * V_78 = ( void * ) V_60 ;
if ( F_45 ( V_78 -> V_79 , V_60 -> V_17 - 8 ) == V_60 -> V_17 - 8 ) {
F_46 ( 1 , V_80 ,
L_6
L_7 ,
F_47 ( V_81 ) ,
F_47 ( V_82 ) ,
F_47 ( V_83 ) ) ;
return - V_54 ;
}
F_21 ( L_8 , V_78 -> V_84 ,
V_78 -> V_79 ) ;
return 0 ;
}
static int F_48 ( struct V_72 * V_60 , void * V_73 )
{
struct V_85 * V_86 ;
struct V_1 * V_2 ;
V_86 = (struct V_85 * ) V_60 ;
F_30 (drhd) {
if ( V_2 -> V_70 == V_86 -> V_87 ) {
int V_88 = F_49 ( V_86 -> V_89 ) ;
if ( ! F_50 ( V_88 ) )
V_88 = - 1 ;
V_2 -> V_76 -> V_88 = V_88 ;
return 0 ;
}
}
F_46 (
1 , V_80 ,
L_9
L_7 ,
V_2 -> V_70 ,
F_47 ( V_81 ) ,
F_47 ( V_82 ) ,
F_47 ( V_83 ) ) ;
return 0 ;
}
static void T_3
F_51 ( struct V_72 * V_60 )
{
struct V_58 * V_2 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_85 * V_86 ;
switch ( V_60 -> type ) {
case V_94 :
V_2 = F_31 ( V_60 , struct V_58 ,
V_60 ) ;
F_21 ( L_10 ,
( unsigned long long ) V_2 -> V_71 , V_2 -> V_75 ) ;
break;
case V_95 :
V_91 = F_31 ( V_60 , struct V_90 ,
V_60 ) ;
F_21 ( L_11 ,
( unsigned long long ) V_91 -> V_87 ,
( unsigned long long ) V_91 -> V_96 ) ;
break;
case V_97 :
V_93 = F_31 ( V_60 , struct V_92 , V_60 ) ;
F_21 ( L_12 , V_93 -> V_75 ) ;
break;
case V_98 :
V_86 = F_31 ( V_60 , struct V_85 , V_60 ) ;
F_21 ( L_13 ,
( unsigned long long ) V_86 -> V_87 ,
V_86 -> V_89 ) ;
break;
case V_99 :
break;
}
}
static int T_3 F_52 ( void )
{
T_4 V_100 = V_101 ;
V_100 = F_53 ( V_102 , 0 ,
(struct V_103 * * ) & V_104 ,
& V_105 ) ;
if ( F_54 ( V_100 ) && ! V_104 ) {
F_5 ( L_14 ) ;
V_100 = V_106 ;
}
return ( F_54 ( V_100 ) ? 1 : 0 ) ;
}
static int F_55 ( struct V_72 * V_6 ,
T_1 V_107 , struct V_108 * V_109 )
{
int V_56 = 0 ;
struct V_72 * V_110 , * V_111 ;
struct V_72 * V_7 = ( ( void * ) V_6 ) + V_107 ;
for ( V_110 = V_6 ; V_110 < V_7 && V_56 == 0 ; V_110 = V_111 ) {
V_111 = ( void * ) V_110 + V_110 -> V_17 ;
if ( V_110 -> V_17 == 0 ) {
F_56 ( V_47 L_15 ) ;
break;
} else if ( V_111 > V_7 ) {
F_5 ( V_47 L_16 ) ;
V_56 = - V_54 ;
break;
}
if ( V_109 -> V_112 )
F_51 ( V_110 ) ;
if ( V_110 -> type >= V_113 ) {
F_56 ( L_17 ,
V_110 -> type ) ;
} else if ( V_109 -> V_109 [ V_110 -> type ] ) {
V_56 = V_109 -> V_109 [ V_110 -> type ] ( V_110 , V_109 -> V_73 [ V_110 -> type ] ) ;
} else if ( ! V_109 -> V_114 ) {
F_5 ( L_18 ,
V_110 -> type ) ;
V_56 = - V_54 ;
}
}
return V_56 ;
}
static inline int F_57 ( struct V_115 * V_116 ,
struct V_108 * V_109 )
{
return F_55 ( ( void * ) ( V_116 + 1 ) ,
V_116 -> V_60 . V_17 - sizeof( * V_116 ) , V_109 ) ;
}
static int T_3
F_58 ( void )
{
struct V_115 * V_116 ;
int V_56 = 0 ;
int V_117 = 0 ;
struct V_108 V_109 = {
. V_112 = true ,
. V_114 = true ,
. V_73 [ V_94 ] = & V_117 ,
. V_109 [ V_94 ] = & F_40 ,
. V_109 [ V_95 ] = & V_118 ,
. V_109 [ V_97 ] = & V_119 ,
. V_109 [ V_98 ] = & F_48 ,
. V_109 [ V_99 ] = & F_44 ,
} ;
F_52 () ;
V_104 = F_59 ( V_104 ) ;
V_116 = (struct V_115 * ) V_104 ;
if ( ! V_116 )
return - V_120 ;
if ( V_116 -> V_121 < V_122 - 1 ) {
F_5 ( L_19 ) ;
return - V_54 ;
}
F_21 ( L_20 , V_116 -> V_121 + 1 ) ;
V_56 = F_57 ( V_116 , & V_109 ) ;
if ( V_56 == 0 && V_117 == 0 )
F_5 ( V_47 L_21 ) ;
return V_56 ;
}
static int F_60 ( struct V_18 V_20 [] ,
int V_8 , struct V_25 * V_26 )
{
int V_55 ;
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
struct V_1 * V_57 ;
struct V_58 * V_2 ;
V_26 = F_63 ( V_26 ) ;
F_64 () ;
F_30 (dmaru) {
V_2 = F_31 ( V_57 -> V_59 ,
struct V_58 ,
V_60 ) ;
if ( V_57 -> V_3 &&
V_2 -> V_48 == F_15 ( V_26 -> V_34 ) )
goto V_74;
if ( F_60 ( V_57 -> V_20 ,
V_57 -> V_49 , V_26 ) )
goto V_74;
}
V_57 = NULL ;
V_74:
F_65 () ;
return V_57 ;
}
static void T_3 F_66 ( T_5 V_84 ,
struct V_123 * V_124 )
{
struct V_1 * V_57 ;
struct V_58 * V_2 ;
struct V_9 * V_10 ;
struct V_22 * V_30 ;
int V_21 ;
struct V_36 * V_41 ;
F_30 (dmaru) {
V_2 = F_31 ( V_57 -> V_59 ,
struct V_58 ,
V_60 ) ;
for ( V_10 = ( void * ) ( V_2 + 1 ) ;
( unsigned long ) V_10 < ( ( unsigned long ) V_2 ) + V_2 -> V_60 . V_17 ;
V_10 = ( ( void * ) V_10 ) + V_10 -> V_17 ) {
if ( V_10 -> V_11 != V_12 )
continue;
if ( V_10 -> V_125 != V_84 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_21 ( L_22 ,
F_67 ( & V_124 -> V_26 ) , V_57 -> V_70 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_44 ) ;
F_23 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_57 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_57 -> V_20 [ V_21 ] . V_43 = F_68 ( V_41 -> V_22 ,
V_41 -> V_44 ) ;
F_24 ( V_57 -> V_20 [ V_21 ] . V_26 ,
F_25 ( & V_124 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_57 -> V_49 ) ;
}
}
F_5 ( L_23 ,
V_84 , F_67 ( & V_124 -> V_26 ) ) ;
}
static int T_3 F_69 ( void )
{
struct V_77 * V_78 ;
if ( V_104 == NULL )
return - V_120 ;
for ( V_78 = ( void * ) V_104 + sizeof( struct V_115 ) ;
( ( unsigned long ) V_78 ) < ( ( unsigned long ) V_104 ) + V_104 -> V_17 ;
V_78 = ( ( void * ) V_78 ) + V_78 -> V_60 . V_17 ) {
if ( V_78 -> V_60 . type == V_99 ) {
T_6 V_126 ;
struct V_123 * V_124 ;
if ( ! F_54 ( F_70 ( V_127 ,
V_78 -> V_79 ,
& V_126 ) ) ) {
F_71 ( L_24 ,
V_78 -> V_79 ) ;
continue;
}
if ( F_72 ( V_126 , & V_124 ) ) {
F_71 ( L_25 ,
V_78 -> V_79 ) ;
continue;
}
F_66 ( V_78 -> V_84 , V_124 ) ;
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
V_38 = - V_120 ;
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
F_76 ( & V_128 , & V_129 ) ;
}
return V_38 ;
}
int T_3 F_77 ( void )
{
static int V_130 ;
int V_56 ;
if ( V_130 == 0 ) {
V_56 = F_58 () ;
if ( V_56 < 0 ) {
if ( V_56 != - V_120 )
F_21 ( L_26 ) ;
} else if ( F_74 ( & V_5 ) ) {
F_21 ( L_27 ) ;
V_56 = - V_120 ;
}
if ( V_56 < 0 )
V_130 = V_56 ;
else
V_130 = 1 ;
}
return V_130 < 0 ? V_130 : 0 ;
}
static void F_78 ( T_7 V_131 , const char * V_132 )
{
F_79 (
1 , V_80 ,
L_28
L_7 ,
V_131 , V_132 ,
F_47 ( V_81 ) ,
F_47 ( V_82 ) ,
F_47 ( V_83 ) ) ;
}
static int T_8
F_80 ( struct V_72 * V_133 , void * V_73 )
{
struct V_58 * V_2 ;
void T_9 * V_131 ;
T_7 V_134 , V_135 ;
V_2 = ( void * ) V_133 ;
if ( ! V_2 -> V_71 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
if ( V_73 )
V_131 = F_81 ( V_2 -> V_71 , V_136 ) ;
else
V_131 = F_82 ( V_2 -> V_71 , V_136 ) ;
if ( ! V_131 ) {
F_5 ( L_30 , V_2 -> V_71 ) ;
return - V_54 ;
}
V_134 = F_83 ( V_131 + V_137 ) ;
V_135 = F_83 ( V_131 + V_138 ) ;
if ( V_73 )
F_84 ( V_131 ) ;
else
F_85 ( V_131 , V_136 ) ;
if ( V_134 == ( V_139 ) - 1 && V_135 == ( V_139 ) - 1 ) {
F_78 ( V_2 -> V_71 , L_31 ) ;
return - V_54 ;
}
return 0 ;
}
int T_3 F_86 ( void )
{
int V_56 ;
struct V_108 V_140 = {
. V_109 [ V_94 ] = & F_80 ,
. V_114 = true ,
} ;
F_36 ( & V_68 ) ;
V_56 = F_52 () ;
if ( V_56 )
V_56 = ! F_57 ( (struct V_115 * ) V_104 ,
& V_140 ) ;
if ( V_56 && ! V_141 && ! V_142 && ! V_143 ) {
V_142 = 1 ;
F_87 () ;
}
#ifdef F_88
if ( V_56 )
V_144 . V_76 . V_145 = V_146 ;
#endif
F_89 ( ( void T_9 * ) V_104 , V_105 ) ;
V_104 = NULL ;
F_37 ( & V_68 ) ;
return V_56 ? 1 : - V_120 ;
}
static void F_90 ( struct V_147 * V_76 )
{
F_84 ( V_76 -> V_148 ) ;
F_91 ( V_76 -> V_149 , V_76 -> V_150 ) ;
}
static int F_92 ( struct V_147 * V_76 , T_7 V_151 )
{
int V_152 , V_153 = 0 ;
V_76 -> V_149 = V_151 ;
V_76 -> V_150 = V_136 ;
if ( ! F_93 ( V_76 -> V_149 , V_76 -> V_150 , V_76 -> V_154 ) ) {
F_71 ( L_32 ) ;
V_153 = - V_155 ;
goto V_74;
}
V_76 -> V_148 = F_81 ( V_76 -> V_149 , V_76 -> V_150 ) ;
if ( ! V_76 -> V_148 ) {
F_71 ( L_33 ) ;
V_153 = - V_39 ;
goto V_156;
}
V_76 -> V_134 = F_83 ( V_76 -> V_148 + V_137 ) ;
V_76 -> V_135 = F_83 ( V_76 -> V_148 + V_138 ) ;
if ( V_76 -> V_134 == ( V_139 ) - 1 && V_76 -> V_135 == ( V_139 ) - 1 ) {
V_153 = - V_54 ;
F_78 ( V_151 , L_31 ) ;
goto V_157;
}
V_152 = F_94 ( int , F_95 ( V_76 -> V_135 ) ,
F_96 ( V_76 -> V_134 ) ) ;
V_152 = F_97 ( V_152 ) ;
if ( V_152 > V_76 -> V_150 ) {
F_84 ( V_76 -> V_148 ) ;
F_91 ( V_76 -> V_149 , V_76 -> V_150 ) ;
V_76 -> V_150 = V_152 ;
if ( ! F_93 ( V_76 -> V_149 , V_76 -> V_150 ,
V_76 -> V_154 ) ) {
F_71 ( L_32 ) ;
V_153 = - V_155 ;
goto V_74;
}
V_76 -> V_148 = F_81 ( V_76 -> V_149 , V_76 -> V_150 ) ;
if ( ! V_76 -> V_148 ) {
F_71 ( L_33 ) ;
V_153 = - V_39 ;
goto V_156;
}
}
V_153 = 0 ;
goto V_74;
V_157:
F_84 ( V_76 -> V_148 ) ;
V_156:
F_91 ( V_76 -> V_149 , V_76 -> V_150 ) ;
V_74:
return V_153 ;
}
static int F_98 ( struct V_147 * V_76 )
{
V_76 -> V_158 = F_99 ( V_159 ,
V_160 ) ;
if ( V_76 -> V_158 >= V_160 ) {
V_76 -> V_158 = - 1 ;
} else {
F_100 ( V_76 -> V_158 , V_159 ) ;
sprintf ( V_76 -> V_154 , L_34 , V_76 -> V_158 ) ;
}
return V_76 -> V_158 ;
}
static void F_101 ( struct V_147 * V_76 )
{
if ( V_76 -> V_158 >= 0 ) {
F_102 ( V_76 -> V_158 , V_159 ) ;
V_76 -> V_158 = - 1 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_147 * V_76 ;
T_10 V_161 , V_162 ;
int V_163 = 0 ;
int V_164 = 0 ;
int V_153 ;
if ( ! V_2 -> V_70 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
V_76 = F_13 ( sizeof( * V_76 ) , V_19 ) ;
if ( ! V_76 )
return - V_39 ;
if ( F_98 ( V_76 ) < 0 ) {
F_71 ( L_35 ) ;
V_153 = - V_165 ;
goto error;
}
V_153 = F_92 ( V_76 , V_2 -> V_70 ) ;
if ( V_153 ) {
F_71 ( L_36 , V_76 -> V_154 ) ;
goto V_166;
}
V_153 = - V_54 ;
V_163 = F_103 ( V_76 ) ;
if ( V_163 < 0 ) {
F_71 ( L_37 ,
V_76 -> V_158 ) ;
goto V_167;
}
V_164 = F_104 ( V_76 ) ;
if ( V_164 < 0 ) {
F_71 ( L_38 ,
V_76 -> V_158 ) ;
goto V_167;
}
V_76 -> V_163 = V_163 ;
V_76 -> V_164 = V_164 ;
V_76 -> V_48 = V_2 -> V_48 ;
V_76 -> V_88 = - 1 ;
V_161 = F_105 ( V_76 -> V_148 + V_168 ) ;
F_21 ( L_39 ,
V_76 -> V_154 ,
( unsigned long long ) V_2 -> V_70 ,
F_106 ( V_161 ) , F_107 ( V_161 ) ,
( unsigned long long ) V_76 -> V_134 ,
( unsigned long long ) V_76 -> V_135 ) ;
V_162 = F_105 ( V_76 -> V_148 + V_169 ) ;
if ( V_162 & V_170 )
V_76 -> V_171 |= V_172 ;
if ( V_162 & V_173 )
V_76 -> V_171 |= V_174 ;
if ( V_162 & V_175 )
V_76 -> V_171 |= V_176 ;
F_108 ( & V_76 -> V_177 ) ;
if ( V_178 ) {
V_76 -> V_179 = F_109 ( NULL , V_76 ,
V_180 ,
L_40 , V_76 -> V_154 ) ;
if ( F_110 ( V_76 -> V_179 ) ) {
V_153 = F_111 ( V_76 -> V_179 ) ;
goto V_167;
}
}
V_2 -> V_76 = V_76 ;
return 0 ;
V_167:
F_90 ( V_76 ) ;
V_166:
F_101 ( V_76 ) ;
error:
F_10 ( V_76 ) ;
return V_153 ;
}
static void F_43 ( struct V_147 * V_76 )
{
F_112 ( V_76 -> V_179 ) ;
if ( V_76 -> V_181 ) {
if ( V_76 -> V_182 ) {
F_113 ( V_76 -> V_182 , V_76 ) ;
F_114 ( V_76 -> V_182 ) ;
V_76 -> V_182 = 0 ;
}
F_113 ( V_76 -> V_181 , V_76 ) ;
F_114 ( V_76 -> V_181 ) ;
V_76 -> V_181 = 0 ;
}
if ( V_76 -> V_183 ) {
F_115 ( ( unsigned long ) V_76 -> V_183 -> V_184 ) ;
F_10 ( V_76 -> V_183 -> V_185 ) ;
F_10 ( V_76 -> V_183 ) ;
}
if ( V_76 -> V_148 )
F_90 ( V_76 ) ;
F_101 ( V_76 ) ;
F_10 ( V_76 ) ;
}
static inline void F_116 ( struct V_186 * V_183 )
{
while ( V_183 -> V_185 [ V_183 -> V_187 ] == V_188 ||
V_183 -> V_185 [ V_183 -> V_187 ] == V_189 ) {
V_183 -> V_185 [ V_183 -> V_187 ] = V_190 ;
V_183 -> V_187 = ( V_183 -> V_187 + 1 ) % V_191 ;
V_183 -> V_192 ++ ;
}
}
static int F_117 ( struct V_147 * V_76 , int V_55 )
{
T_10 V_193 ;
int V_194 , V_195 ;
struct V_186 * V_183 = V_76 -> V_183 ;
int V_196 = ( V_55 + 1 ) % V_191 ;
if ( V_183 -> V_185 [ V_196 ] == V_189 )
return - V_197 ;
V_193 = F_105 ( V_76 -> V_148 + V_198 ) ;
if ( V_193 & V_199 ) {
V_194 = F_105 ( V_76 -> V_148 + V_200 ) ;
if ( ( V_194 >> V_201 ) == V_55 ) {
F_71 ( L_41
L_42 ,
( unsigned long long ) V_183 -> V_184 [ V_55 ] . V_202 ,
( unsigned long long ) V_183 -> V_184 [ V_55 ] . V_203 ) ;
memcpy ( & V_183 -> V_184 [ V_55 ] , & V_183 -> V_184 [ V_196 ] ,
sizeof( struct V_204 ) ) ;
F_118 ( V_199 , V_76 -> V_148 + V_198 ) ;
return - V_54 ;
}
}
if ( V_193 & V_205 ) {
V_194 = F_105 ( V_76 -> V_148 + V_200 ) ;
V_194 = ( ( V_194 >> V_201 ) - 1 + V_191 ) % V_191 ;
V_194 |= 1 ;
V_195 = F_105 ( V_76 -> V_148 + V_206 ) ;
V_195 = ( ( V_195 >> V_201 ) - 1 + V_191 ) % V_191 ;
F_118 ( V_205 , V_76 -> V_148 + V_198 ) ;
do {
if ( V_183 -> V_185 [ V_194 ] == V_207 )
V_183 -> V_185 [ V_194 ] = V_189 ;
V_194 = ( V_194 - 2 + V_191 ) % V_191 ;
} while ( V_194 != V_195 );
if ( V_183 -> V_185 [ V_196 ] == V_189 )
return - V_197 ;
}
if ( V_193 & V_208 )
F_118 ( V_208 , V_76 -> V_148 + V_198 ) ;
return 0 ;
}
int F_119 ( struct V_204 * V_184 , struct V_147 * V_76 )
{
int V_209 ;
struct V_186 * V_183 = V_76 -> V_183 ;
struct V_204 * V_210 , V_211 ;
int V_196 , V_55 ;
unsigned long V_75 ;
if ( ! V_183 )
return 0 ;
V_210 = V_183 -> V_184 ;
V_212:
V_209 = 0 ;
F_120 ( & V_183 -> V_213 , V_75 ) ;
while ( V_183 -> V_192 < 3 ) {
F_121 ( & V_183 -> V_213 , V_75 ) ;
F_122 () ;
F_120 ( & V_183 -> V_213 , V_75 ) ;
}
V_55 = V_183 -> V_214 ;
V_196 = ( V_55 + 1 ) % V_191 ;
V_183 -> V_185 [ V_55 ] = V_183 -> V_185 [ V_196 ] = V_207 ;
V_210 [ V_55 ] = * V_184 ;
V_211 . V_202 = F_123 ( V_188 ) |
V_215 | V_216 ;
V_211 . V_203 = F_124 ( & V_183 -> V_185 [ V_196 ] ) ;
V_210 [ V_196 ] = V_211 ;
V_183 -> V_214 = ( V_183 -> V_214 + 2 ) % V_191 ;
V_183 -> V_192 -= 2 ;
F_118 ( V_183 -> V_214 << V_201 , V_76 -> V_148 + V_206 ) ;
while ( V_183 -> V_185 [ V_196 ] != V_188 ) {
V_209 = F_117 ( V_76 , V_55 ) ;
if ( V_209 )
break;
F_125 ( & V_183 -> V_213 ) ;
F_122 () ;
F_126 ( & V_183 -> V_213 ) ;
}
V_183 -> V_185 [ V_55 ] = V_188 ;
F_116 ( V_183 ) ;
F_121 ( & V_183 -> V_213 , V_75 ) ;
if ( V_209 == - V_197 )
goto V_212;
return V_209 ;
}
void F_127 ( struct V_147 * V_76 )
{
struct V_204 V_184 ;
V_184 . V_202 = V_217 ;
V_184 . V_203 = 0 ;
F_119 ( & V_184 , V_76 ) ;
}
void F_128 ( struct V_147 * V_76 , T_2 V_218 , T_2 V_219 , T_5 V_220 ,
T_7 type )
{
struct V_204 V_184 ;
V_184 . V_202 = F_129 ( V_220 ) | F_130 ( V_219 ) | F_131 ( V_218 )
| F_132 ( type ) | V_221 ;
V_184 . V_203 = 0 ;
F_119 ( & V_184 , V_76 ) ;
}
void F_133 ( struct V_147 * V_76 , T_2 V_218 , T_7 V_131 ,
unsigned int V_222 , T_7 type )
{
T_5 V_223 = 0 , V_224 = 0 ;
struct V_204 V_184 ;
int V_225 = 0 ;
if ( F_134 ( V_76 -> V_134 ) )
V_223 = 1 ;
if ( F_135 ( V_76 -> V_134 ) )
V_224 = 1 ;
V_184 . V_202 = F_136 ( V_218 ) | F_137 ( V_224 ) | F_138 ( V_223 )
| F_139 ( type ) | V_226 ;
V_184 . V_203 = F_140 ( V_131 ) | F_141 ( V_225 )
| F_142 ( V_222 ) ;
F_119 ( & V_184 , V_76 ) ;
}
void F_143 ( struct V_147 * V_76 , T_2 V_219 , T_2 V_227 ,
T_7 V_131 , unsigned V_228 )
{
struct V_204 V_184 ;
if ( V_228 ) {
F_12 ( V_131 & ( ( 1 << ( V_229 + V_228 ) ) - 1 ) ) ;
V_131 |= ( 1 << ( V_229 + V_228 - 1 ) ) - 1 ;
V_184 . V_203 = F_144 ( V_131 ) | V_230 ;
} else
V_184 . V_203 = F_144 ( V_131 ) ;
if ( V_227 >= V_231 )
V_227 = 0 ;
V_184 . V_202 = F_145 ( V_219 ) | F_146 ( V_227 ) |
V_232 ;
F_119 ( & V_184 , V_76 ) ;
}
void F_147 ( struct V_147 * V_76 )
{
unsigned long V_75 ;
T_10 V_162 ;
T_11 V_233 = F_148 () ;
if ( ! F_149 ( V_76 -> V_135 ) )
return;
F_120 ( & V_76 -> V_177 , V_75 ) ;
V_162 = F_105 ( V_76 -> V_148 + V_169 ) ;
if ( ! ( V_162 & V_175 ) )
goto V_7;
while ( ( F_105 ( V_76 -> V_148 + V_206 ) !=
F_105 ( V_76 -> V_148 + V_200 ) ) &&
( V_234 > ( F_148 () - V_233 ) ) )
F_122 () ;
V_76 -> V_171 &= ~ V_176 ;
F_118 ( V_76 -> V_171 , V_76 -> V_148 + V_235 ) ;
F_150 ( V_76 , V_169 , F_105 ,
! ( V_162 & V_175 ) , V_162 ) ;
V_7:
F_121 ( & V_76 -> V_177 , V_75 ) ;
}
static void F_151 ( struct V_147 * V_76 )
{
T_10 V_162 ;
unsigned long V_75 ;
struct V_186 * V_183 = V_76 -> V_183 ;
V_183 -> V_214 = V_183 -> V_187 = 0 ;
V_183 -> V_192 = V_191 ;
F_120 ( & V_76 -> V_177 , V_75 ) ;
F_118 ( 0 , V_76 -> V_148 + V_206 ) ;
F_152 ( V_76 -> V_148 + V_236 , F_124 ( V_183 -> V_184 ) ) ;
V_76 -> V_171 |= V_176 ;
F_118 ( V_76 -> V_171 , V_76 -> V_148 + V_235 ) ;
F_150 ( V_76 , V_169 , F_105 , ( V_162 & V_175 ) , V_162 ) ;
F_121 ( & V_76 -> V_177 , V_75 ) ;
}
int F_153 ( struct V_147 * V_76 )
{
struct V_186 * V_183 ;
struct V_237 * V_238 ;
if ( ! F_149 ( V_76 -> V_135 ) )
return - V_239 ;
if ( V_76 -> V_183 )
return 0 ;
V_76 -> V_183 = F_154 ( sizeof( * V_183 ) , V_240 ) ;
if ( ! V_76 -> V_183 )
return - V_39 ;
V_183 = V_76 -> V_183 ;
V_238 = F_155 ( V_76 -> V_88 , V_240 | V_241 , 0 ) ;
if ( ! V_238 ) {
F_10 ( V_183 ) ;
V_76 -> V_183 = NULL ;
return - V_39 ;
}
V_183 -> V_184 = F_156 ( V_238 ) ;
V_183 -> V_185 = F_13 ( V_191 * sizeof( int ) , V_240 ) ;
if ( ! V_183 -> V_185 ) {
F_115 ( ( unsigned long ) V_183 -> V_184 ) ;
F_10 ( V_183 ) ;
V_76 -> V_183 = NULL ;
return - V_39 ;
}
F_108 ( & V_183 -> V_213 ) ;
F_151 ( V_76 ) ;
return 0 ;
}
static const char * F_157 ( T_5 V_242 , int * V_243 )
{
if ( V_242 >= 0x20 && ( V_242 - 0x20 <
F_158 ( V_244 ) ) ) {
* V_243 = V_245 ;
return V_244 [ V_242 - 0x20 ] ;
} else if ( V_242 < F_158 ( V_246 ) ) {
* V_243 = V_247 ;
return V_246 [ V_242 ] ;
} else {
* V_243 = V_248 ;
return L_43 ;
}
}
static inline int F_159 ( struct V_147 * V_76 , int V_181 )
{
if ( V_76 -> V_181 == V_181 )
return V_249 ;
else if ( V_76 -> V_182 == V_181 )
return V_250 ;
else
F_160 () ;
}
void F_161 ( struct V_251 * V_64 )
{
struct V_147 * V_76 = F_162 ( V_64 ) ;
int V_148 = F_159 ( V_76 , V_64 -> V_181 ) ;
unsigned long V_252 ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
F_118 ( 0 , V_76 -> V_148 + V_148 ) ;
F_105 ( V_76 -> V_148 + V_148 ) ;
F_121 ( & V_76 -> V_177 , V_252 ) ;
}
void F_163 ( struct V_251 * V_64 )
{
struct V_147 * V_76 = F_162 ( V_64 ) ;
int V_148 = F_159 ( V_76 , V_64 -> V_181 ) ;
unsigned long V_252 ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
F_118 ( V_253 , V_76 -> V_148 + V_148 ) ;
F_105 ( V_76 -> V_148 + V_148 ) ;
F_121 ( & V_76 -> V_177 , V_252 ) ;
}
void F_164 ( int V_181 , struct V_254 * V_255 )
{
struct V_147 * V_76 = F_165 ( V_181 ) ;
int V_148 = F_159 ( V_76 , V_181 ) ;
unsigned long V_252 ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
F_118 ( V_255 -> V_64 , V_76 -> V_148 + V_148 + 4 ) ;
F_118 ( V_255 -> V_256 , V_76 -> V_148 + V_148 + 8 ) ;
F_118 ( V_255 -> V_257 , V_76 -> V_148 + V_148 + 12 ) ;
F_121 ( & V_76 -> V_177 , V_252 ) ;
}
void F_166 ( int V_181 , struct V_254 * V_255 )
{
struct V_147 * V_76 = F_165 ( V_181 ) ;
int V_148 = F_159 ( V_76 , V_181 ) ;
unsigned long V_252 ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
V_255 -> V_64 = F_105 ( V_76 -> V_148 + V_148 + 4 ) ;
V_255 -> V_256 = F_105 ( V_76 -> V_148 + V_148 + 8 ) ;
V_255 -> V_257 = F_105 ( V_76 -> V_148 + V_148 + 12 ) ;
F_121 ( & V_76 -> V_177 , V_252 ) ;
}
static int F_167 ( struct V_147 * V_76 , int type ,
T_5 V_242 , T_2 V_258 , unsigned long long V_131 )
{
const char * V_259 ;
int V_243 ;
V_259 = F_157 ( V_242 , & V_243 ) ;
if ( V_243 == V_245 )
F_71 ( L_44 ,
V_258 >> 8 , F_16 ( V_258 & 0xFF ) ,
F_17 ( V_258 & 0xFF ) , V_131 >> 48 ,
V_242 , V_259 ) ;
else
F_71 ( L_45 ,
type ? L_46 : L_47 ,
V_258 >> 8 , F_16 ( V_258 & 0xFF ) ,
F_17 ( V_258 & 0xFF ) , V_131 , V_242 , V_259 ) ;
return 0 ;
}
T_12 F_168 ( int V_181 , void * V_260 )
{
struct V_147 * V_76 = V_260 ;
int V_148 , V_261 ;
T_10 V_262 ;
unsigned long V_252 ;
bool V_263 ;
static F_169 ( V_264 ,
V_265 ,
V_266 ) ;
V_263 = ! F_170 ( & V_264 ) ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
V_262 = F_105 ( V_76 -> V_148 + V_198 ) ;
if ( V_262 && ! V_263 )
F_71 ( L_48 , V_262 ) ;
if ( ! ( V_262 & V_267 ) )
goto V_268;
V_261 = F_171 ( V_262 ) ;
V_148 = F_172 ( V_76 -> V_134 ) ;
while ( 1 ) {
T_5 V_242 ;
T_2 V_258 ;
T_7 V_269 ;
int type ;
T_10 V_64 ;
V_64 = F_105 ( V_76 -> V_148 + V_148 +
V_261 * V_270 + 12 ) ;
if ( ! ( V_64 & V_271 ) )
break;
if ( ! V_263 ) {
V_242 = F_173 ( V_64 ) ;
type = F_174 ( V_64 ) ;
V_64 = F_105 ( V_76 -> V_148 + V_148 +
V_261 * V_270 + 8 ) ;
V_258 = F_175 ( V_64 ) ;
V_269 = F_83 ( V_76 -> V_148 + V_148 +
V_261 * V_270 ) ;
V_269 = F_176 ( V_269 ) ;
}
F_118 ( V_271 , V_76 -> V_148 + V_148 +
V_261 * V_270 + 12 ) ;
F_121 ( & V_76 -> V_177 , V_252 ) ;
if ( ! V_263 )
F_167 ( V_76 , type , V_242 ,
V_258 , V_269 ) ;
V_261 ++ ;
if ( V_261 >= F_177 ( V_76 -> V_134 ) )
V_261 = 0 ;
F_120 ( & V_76 -> V_177 , V_252 ) ;
}
F_118 ( V_272 | V_267 , V_76 -> V_148 + V_198 ) ;
V_268:
F_121 ( & V_76 -> V_177 , V_252 ) ;
return V_273 ;
}
int F_178 ( struct V_147 * V_76 )
{
int V_181 , V_56 ;
if ( V_76 -> V_181 )
return 0 ;
V_181 = F_179 ( V_76 -> V_158 , V_76 -> V_88 , V_76 ) ;
if ( V_181 > 0 ) {
V_76 -> V_181 = V_181 ;
} else {
F_71 ( L_49 ) ;
return - V_54 ;
}
V_56 = F_180 ( V_181 , F_168 , V_274 , V_76 -> V_154 , V_76 ) ;
if ( V_56 )
F_71 ( L_50 ) ;
return V_56 ;
}
int T_3 F_181 ( void )
{
struct V_1 * V_2 ;
struct V_147 * V_76 ;
F_182 (iommu, drhd) {
T_10 V_262 ;
int V_56 = F_178 ( V_76 ) ;
if ( V_56 ) {
F_71 ( L_51 ,
( unsigned long long ) V_2 -> V_70 , V_56 ) ;
return - 1 ;
}
F_168 ( V_76 -> V_181 , V_76 ) ;
V_262 = F_105 ( V_76 -> V_148 + V_198 ) ;
F_118 ( V_262 , V_76 -> V_148 + V_198 ) ;
}
return 0 ;
}
int F_183 ( struct V_147 * V_76 )
{
if ( ! F_149 ( V_76 -> V_135 ) )
return - V_239 ;
if ( ! V_76 -> V_183 )
return - V_239 ;
F_147 ( V_76 ) ;
F_151 ( V_76 ) ;
return 0 ;
}
int T_3 F_184 ( void )
{
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) V_104 ;
if ( ! V_116 )
return 0 ;
return V_116 -> V_75 & 0x1 ;
}
static inline bool F_185 ( void )
{
return V_275 || V_178 ;
}
static int T_3 F_186 ( void )
{
struct V_1 * V_57 , * V_276 ;
if ( F_185 () )
return 0 ;
if ( V_38 != 1 && ! F_74 ( & V_5 ) )
F_187 ( & V_128 , & V_129 ) ;
F_36 ( & V_68 ) ;
F_188 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_189 ( & V_57 -> V_4 ) ;
F_42 ( V_57 ) ;
}
F_37 ( & V_68 ) ;
return 0 ;
}
static inline bool F_190 ( T_6 V_277 , int V_278 )
{
return F_191 ( V_277 , V_279 , V_280 , 1 << V_278 ) ;
}
static int F_192 ( T_6 V_277 , int V_278 ,
T_13 V_281 , void * V_73 )
{
int V_56 = - V_120 ;
union V_282 * V_283 ;
struct V_72 * V_6 ;
struct V_108 V_284 ;
static int V_285 [] = {
[ V_286 ] = V_94 ,
[ V_287 ] = V_97 ,
[ V_288 ] = V_98 ,
} ;
if ( ! F_190 ( V_277 , V_278 ) )
return 0 ;
V_283 = F_193 ( V_277 , V_279 , V_280 ,
V_278 , NULL , V_289 ) ;
if ( ! V_283 )
return - V_120 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_109 [ V_285 [ V_278 ] ] = V_281 ;
V_284 . V_73 [ V_285 [ V_278 ] ] = V_73 ;
V_6 = (struct V_72 * ) V_283 -> V_290 . V_291 ;
V_56 = F_55 ( V_6 , V_283 -> V_290 . V_17 , & V_284 ) ;
F_194 ( V_283 ) ;
return V_56 ;
}
static int F_195 ( struct V_72 * V_60 , void * V_73 )
{
int V_56 ;
struct V_1 * V_57 ;
V_57 = F_38 ( (struct V_58 * ) V_60 ) ;
if ( ! V_57 )
return - V_120 ;
V_56 = F_196 ( V_57 , true ) ;
if ( V_56 == 0 )
V_56 = F_197 ( V_57 , true ) ;
return V_56 ;
}
static int F_198 ( struct V_72 * V_60 , void * V_73 )
{
int V_21 , V_56 ;
struct V_22 * V_26 ;
struct V_1 * V_57 ;
V_57 = F_38 ( (struct V_58 * ) V_60 ) ;
if ( ! V_57 )
return 0 ;
if ( ! V_57 -> V_3 && V_57 -> V_20 && V_57 -> V_49 ) {
F_8 (dmaru->devices,
dmaru->devices_cnt, i, dev)
return - V_155 ;
}
V_56 = F_196 ( V_57 , false ) ;
if ( V_56 == 0 )
V_56 = F_197 ( V_57 , false ) ;
return V_56 ;
}
static int F_199 ( struct V_72 * V_60 , void * V_73 )
{
struct V_1 * V_57 ;
V_57 = F_38 ( (struct V_58 * ) V_60 ) ;
if ( V_57 ) {
F_200 ( & V_57 -> V_4 ) ;
F_28 () ;
F_42 ( V_57 ) ;
}
return 0 ;
}
static int F_201 ( T_6 V_277 )
{
int V_56 ;
int V_117 = 0 ;
V_56 = F_192 ( V_277 , V_286 ,
& F_80 , ( void * ) 1 ) ;
if ( V_56 )
goto V_74;
V_56 = F_192 ( V_277 , V_286 ,
& F_40 , ( void * ) & V_117 ) ;
if ( V_56 == 0 && V_117 == 0 ) {
F_5 ( V_47 L_52 ) ;
goto V_74;
} else if ( V_56 ) {
goto V_292;
}
V_56 = F_192 ( V_277 , V_288 ,
& F_48 , NULL ) ;
if ( V_56 )
goto V_292;
V_56 = F_192 ( V_277 , V_287 ,
& V_119 , NULL ) ;
if ( V_56 )
goto V_293;
V_56 = F_192 ( V_277 , V_286 ,
& F_195 , NULL ) ;
if ( ! V_56 )
return 0 ;
F_192 ( V_277 , V_286 ,
& F_198 , NULL ) ;
V_293:
F_192 ( V_277 , V_287 ,
& V_294 , NULL ) ;
V_292:
F_192 ( V_277 , V_286 ,
& F_199 , NULL ) ;
V_74:
return V_56 ;
}
static int F_202 ( T_6 V_277 )
{
int V_56 ;
V_56 = F_192 ( V_277 , V_287 ,
& V_295 , NULL ) ;
if ( V_56 )
return V_56 ;
V_56 = F_192 ( V_277 , V_286 ,
& F_198 , NULL ) ;
if ( V_56 == 0 ) {
F_203 ( F_192 ( V_277 , V_287 ,
& V_294 , NULL ) ) ;
F_203 ( F_192 ( V_277 , V_286 ,
& F_199 , NULL ) ) ;
} else {
F_192 ( V_277 , V_286 ,
& F_195 , NULL ) ;
}
return V_56 ;
}
static T_4 F_204 ( T_6 V_277 , T_10 V_296 ,
void * V_297 , void * * V_298 )
{
T_6 * V_299 = V_298 ;
if ( F_190 ( V_277 , V_286 ) ) {
* V_299 = V_277 ;
return V_300 ;
}
return V_101 ;
}
static int F_205 ( T_6 V_277 , bool V_301 )
{
int V_56 ;
T_6 V_30 = NULL ;
T_4 V_100 ;
if ( ! F_185 () )
return 0 ;
if ( F_190 ( V_277 , V_286 ) ) {
V_30 = V_277 ;
} else {
V_100 = F_206 ( V_302 , V_277 ,
V_303 ,
F_204 ,
NULL , NULL , & V_30 ) ;
if ( F_207 ( V_100 ) ) {
F_5 ( L_53 ) ;
return - V_304 ;
}
}
if ( V_30 == NULL )
return 0 ;
F_36 ( & V_68 ) ;
if ( V_301 )
V_56 = F_201 ( V_30 ) ;
else
V_56 = F_202 ( V_30 ) ;
F_37 ( & V_68 ) ;
return V_56 ;
}
int F_208 ( T_6 V_277 )
{
return F_205 ( V_277 , true ) ;
}
int F_209 ( T_6 V_277 )
{
return F_205 ( V_277 , false ) ;
}
