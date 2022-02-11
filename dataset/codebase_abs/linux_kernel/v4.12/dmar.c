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
if ( V_56 )
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
int V_56 ;
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
V_100 = F_53 ( V_102 , 0 , & V_103 ) ;
if ( F_54 ( V_100 ) && ! V_103 ) {
F_5 ( L_14 ) ;
V_100 = V_104 ;
}
return F_54 ( V_100 ) ? 0 : - V_105 ;
}
static int F_55 ( struct V_72 * V_6 ,
T_1 V_106 , struct V_107 * V_108 )
{
struct V_72 * V_109 , * V_110 ;
struct V_72 * V_7 = ( ( void * ) V_6 ) + V_106 ;
for ( V_109 = V_6 ; V_109 < V_7 ; V_109 = V_110 ) {
V_110 = ( void * ) V_109 + V_109 -> V_17 ;
if ( V_109 -> V_17 == 0 ) {
F_56 ( V_47 L_15 ) ;
break;
} else if ( V_110 > V_7 ) {
F_5 ( V_47 L_16 ) ;
return - V_54 ;
}
if ( V_108 -> V_111 )
F_51 ( V_109 ) ;
if ( V_109 -> type >= V_112 ) {
F_56 ( L_17 ,
V_109 -> type ) ;
} else if ( V_108 -> V_108 [ V_109 -> type ] ) {
int V_56 ;
V_56 = V_108 -> V_108 [ V_109 -> type ] ( V_109 , V_108 -> V_73 [ V_109 -> type ] ) ;
if ( V_56 )
return V_56 ;
} else if ( ! V_108 -> V_113 ) {
F_5 ( L_18 ,
V_109 -> type ) ;
return - V_54 ;
}
}
return 0 ;
}
static inline int F_57 ( struct V_114 * V_115 ,
struct V_107 * V_108 )
{
return F_55 ( ( void * ) ( V_115 + 1 ) ,
V_115 -> V_60 . V_17 - sizeof( * V_115 ) , V_108 ) ;
}
static int T_3
F_58 ( void )
{
struct V_114 * V_115 ;
int V_116 = 0 ;
int V_56 ;
struct V_107 V_108 = {
. V_111 = true ,
. V_113 = true ,
. V_73 [ V_94 ] = & V_116 ,
. V_108 [ V_94 ] = & F_40 ,
. V_108 [ V_95 ] = & V_117 ,
. V_108 [ V_97 ] = & V_118 ,
. V_108 [ V_98 ] = & F_48 ,
. V_108 [ V_99 ] = & F_44 ,
} ;
F_52 () ;
V_103 = F_59 ( V_103 ) ;
V_115 = (struct V_114 * ) V_103 ;
if ( ! V_115 )
return - V_119 ;
if ( V_115 -> V_120 < V_121 - 1 ) {
F_5 ( L_19 ) ;
return - V_54 ;
}
F_21 ( L_20 , V_115 -> V_120 + 1 ) ;
V_56 = F_57 ( V_115 , & V_108 ) ;
if ( V_56 == 0 && V_116 == 0 )
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
struct V_122 * V_123 )
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
if ( V_10 -> V_124 != V_84 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_21 ( L_22 ,
F_67 ( & V_123 -> V_26 ) , V_57 -> V_70 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_44 ) ;
F_23 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_57 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_57 -> V_20 [ V_21 ] . V_43 = F_68 ( V_41 -> V_22 ,
V_41 -> V_44 ) ;
F_24 ( V_57 -> V_20 [ V_21 ] . V_26 ,
F_25 ( & V_123 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_57 -> V_49 ) ;
}
}
F_5 ( L_23 ,
V_84 , F_67 ( & V_123 -> V_26 ) ) ;
}
static int T_3 F_69 ( void )
{
struct V_77 * V_78 ;
if ( V_103 == NULL )
return - V_119 ;
for ( V_78 = ( void * ) V_103 + sizeof( struct V_114 ) ;
( ( unsigned long ) V_78 ) < ( ( unsigned long ) V_103 ) + V_103 -> V_17 ;
V_78 = ( ( void * ) V_78 ) + V_78 -> V_60 . V_17 ) {
if ( V_78 -> V_60 . type == V_99 ) {
T_6 V_125 ;
struct V_122 * V_123 ;
if ( ! F_54 ( F_70 ( V_126 ,
V_78 -> V_79 ,
& V_125 ) ) ) {
F_71 ( L_24 ,
V_78 -> V_79 ) ;
continue;
}
if ( F_72 ( V_125 , & V_123 ) ) {
F_71 ( L_25 ,
V_78 -> V_79 ) ;
continue;
}
F_66 ( V_78 -> V_84 , V_123 ) ;
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
V_38 = - V_119 ;
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
F_76 ( & V_127 , & V_128 ) ;
}
return V_38 ;
}
int T_3 F_77 ( void )
{
static int V_129 ;
int V_56 ;
if ( V_129 == 0 ) {
V_56 = F_58 () ;
if ( V_56 < 0 ) {
if ( V_56 != - V_119 )
F_21 ( L_26 ) ;
} else if ( F_74 ( & V_5 ) ) {
F_21 ( L_27 ) ;
V_56 = - V_119 ;
}
if ( V_56 < 0 )
V_129 = V_56 ;
else
V_129 = 1 ;
}
return V_129 < 0 ? V_129 : 0 ;
}
static void F_78 ( T_7 V_130 , const char * V_131 )
{
F_79 (
1 , V_80 ,
L_28
L_7 ,
V_130 , V_131 ,
F_47 ( V_81 ) ,
F_47 ( V_82 ) ,
F_47 ( V_83 ) ) ;
}
static int T_8
F_80 ( struct V_72 * V_132 , void * V_73 )
{
struct V_58 * V_2 ;
void T_9 * V_130 ;
T_7 V_133 , V_134 ;
V_2 = ( void * ) V_132 ;
if ( ! V_2 -> V_71 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
if ( V_73 )
V_130 = F_81 ( V_2 -> V_71 , V_135 ) ;
else
V_130 = F_82 ( V_2 -> V_71 , V_135 ) ;
if ( ! V_130 ) {
F_5 ( L_30 , V_2 -> V_71 ) ;
return - V_54 ;
}
V_133 = F_83 ( V_130 + V_136 ) ;
V_134 = F_83 ( V_130 + V_137 ) ;
if ( V_73 )
F_84 ( V_130 ) ;
else
F_85 ( V_130 , V_135 ) ;
if ( V_133 == ( V_138 ) - 1 && V_134 == ( V_138 ) - 1 ) {
F_78 ( V_2 -> V_71 , L_31 ) ;
return - V_54 ;
}
return 0 ;
}
int T_3 F_86 ( void )
{
int V_56 ;
struct V_107 V_139 = {
. V_108 [ V_94 ] = & F_80 ,
. V_113 = true ,
} ;
F_36 ( & V_68 ) ;
V_56 = F_52 () ;
if ( ! V_56 )
V_56 = F_57 ( (struct V_114 * ) V_103 ,
& V_139 ) ;
if ( ! V_56 && ! V_140 && ! V_141 && ! V_142 ) {
V_141 = 1 ;
F_87 () ;
}
#ifdef F_88
if ( ! V_56 )
V_143 . V_76 . V_144 = V_145 ;
#endif
if ( V_103 ) {
F_89 ( V_103 ) ;
V_103 = NULL ;
}
F_37 ( & V_68 ) ;
return V_56 ? V_56 : 1 ;
}
static void F_90 ( struct V_146 * V_76 )
{
F_84 ( V_76 -> V_147 ) ;
F_91 ( V_76 -> V_148 , V_76 -> V_149 ) ;
}
static int F_92 ( struct V_146 * V_76 , T_7 V_150 )
{
int V_151 , V_152 = 0 ;
V_76 -> V_148 = V_150 ;
V_76 -> V_149 = V_135 ;
if ( ! F_93 ( V_76 -> V_148 , V_76 -> V_149 , V_76 -> V_153 ) ) {
F_71 ( L_32 ) ;
V_152 = - V_154 ;
goto V_74;
}
V_76 -> V_147 = F_81 ( V_76 -> V_148 , V_76 -> V_149 ) ;
if ( ! V_76 -> V_147 ) {
F_71 ( L_33 ) ;
V_152 = - V_39 ;
goto V_155;
}
V_76 -> V_133 = F_83 ( V_76 -> V_147 + V_136 ) ;
V_76 -> V_134 = F_83 ( V_76 -> V_147 + V_137 ) ;
if ( V_76 -> V_133 == ( V_138 ) - 1 && V_76 -> V_134 == ( V_138 ) - 1 ) {
V_152 = - V_54 ;
F_78 ( V_150 , L_31 ) ;
goto V_156;
}
V_151 = F_94 ( int , F_95 ( V_76 -> V_134 ) ,
F_96 ( V_76 -> V_133 ) ) ;
V_151 = F_97 ( V_151 ) ;
if ( V_151 > V_76 -> V_149 ) {
F_84 ( V_76 -> V_147 ) ;
F_91 ( V_76 -> V_148 , V_76 -> V_149 ) ;
V_76 -> V_149 = V_151 ;
if ( ! F_93 ( V_76 -> V_148 , V_76 -> V_149 ,
V_76 -> V_153 ) ) {
F_71 ( L_32 ) ;
V_152 = - V_154 ;
goto V_74;
}
V_76 -> V_147 = F_81 ( V_76 -> V_148 , V_76 -> V_149 ) ;
if ( ! V_76 -> V_147 ) {
F_71 ( L_33 ) ;
V_152 = - V_39 ;
goto V_155;
}
}
V_152 = 0 ;
goto V_74;
V_156:
F_84 ( V_76 -> V_147 ) ;
V_155:
F_91 ( V_76 -> V_148 , V_76 -> V_149 ) ;
V_74:
return V_152 ;
}
static int F_98 ( struct V_146 * V_76 )
{
V_76 -> V_157 = F_99 ( V_158 ,
V_159 ) ;
if ( V_76 -> V_157 >= V_159 ) {
V_76 -> V_157 = - 1 ;
} else {
F_100 ( V_76 -> V_157 , V_158 ) ;
sprintf ( V_76 -> V_153 , L_34 , V_76 -> V_157 ) ;
}
return V_76 -> V_157 ;
}
static void F_101 ( struct V_146 * V_76 )
{
if ( V_76 -> V_157 >= 0 ) {
F_102 ( V_76 -> V_157 , V_158 ) ;
V_76 -> V_157 = - 1 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_146 * V_76 ;
T_10 V_160 , V_161 ;
int V_162 = 0 ;
int V_163 = 0 ;
int V_152 ;
if ( ! V_2 -> V_70 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
V_76 = F_13 ( sizeof( * V_76 ) , V_19 ) ;
if ( ! V_76 )
return - V_39 ;
if ( F_98 ( V_76 ) < 0 ) {
F_71 ( L_35 ) ;
V_152 = - V_164 ;
goto error;
}
V_152 = F_92 ( V_76 , V_2 -> V_70 ) ;
if ( V_152 ) {
F_71 ( L_36 , V_76 -> V_153 ) ;
goto V_165;
}
V_152 = - V_54 ;
V_162 = F_103 ( V_76 ) ;
if ( V_162 < 0 ) {
F_71 ( L_37 ,
V_76 -> V_157 ) ;
goto V_166;
}
V_163 = F_104 ( V_76 ) ;
if ( V_163 < 0 ) {
F_71 ( L_38 ,
V_76 -> V_157 ) ;
goto V_166;
}
V_76 -> V_162 = V_162 ;
V_76 -> V_163 = V_163 ;
V_76 -> V_48 = V_2 -> V_48 ;
V_76 -> V_88 = - 1 ;
V_160 = F_105 ( V_76 -> V_147 + V_167 ) ;
F_21 ( L_39 ,
V_76 -> V_153 ,
( unsigned long long ) V_2 -> V_70 ,
F_106 ( V_160 ) , F_107 ( V_160 ) ,
( unsigned long long ) V_76 -> V_133 ,
( unsigned long long ) V_76 -> V_134 ) ;
V_161 = F_105 ( V_76 -> V_147 + V_168 ) ;
if ( V_161 & V_169 )
V_76 -> V_170 |= V_171 ;
if ( V_161 & V_172 )
V_76 -> V_170 |= V_173 ;
if ( V_161 & V_174 )
V_76 -> V_170 |= V_175 ;
F_108 ( & V_76 -> V_176 ) ;
if ( V_177 ) {
V_152 = F_109 ( & V_76 -> V_76 , NULL ,
V_178 ,
L_40 , V_76 -> V_153 ) ;
if ( V_152 )
goto V_166;
F_110 ( & V_76 -> V_76 , & V_179 ) ;
V_152 = F_111 ( & V_76 -> V_76 ) ;
if ( V_152 )
goto V_166;
}
V_2 -> V_76 = V_76 ;
return 0 ;
V_166:
F_90 ( V_76 ) ;
V_165:
F_101 ( V_76 ) ;
error:
F_10 ( V_76 ) ;
return V_152 ;
}
static void F_43 ( struct V_146 * V_76 )
{
if ( V_177 ) {
F_112 ( & V_76 -> V_76 ) ;
F_113 ( & V_76 -> V_76 ) ;
}
if ( V_76 -> V_180 ) {
if ( V_76 -> V_181 ) {
F_114 ( V_76 -> V_181 , V_76 ) ;
F_115 ( V_76 -> V_181 ) ;
V_76 -> V_181 = 0 ;
}
F_114 ( V_76 -> V_180 , V_76 ) ;
F_115 ( V_76 -> V_180 ) ;
V_76 -> V_180 = 0 ;
}
if ( V_76 -> V_182 ) {
F_116 ( ( unsigned long ) V_76 -> V_182 -> V_183 ) ;
F_10 ( V_76 -> V_182 -> V_184 ) ;
F_10 ( V_76 -> V_182 ) ;
}
if ( V_76 -> V_147 )
F_90 ( V_76 ) ;
F_101 ( V_76 ) ;
F_10 ( V_76 ) ;
}
static inline void F_117 ( struct V_185 * V_182 )
{
while ( V_182 -> V_184 [ V_182 -> V_186 ] == V_187 ||
V_182 -> V_184 [ V_182 -> V_186 ] == V_188 ) {
V_182 -> V_184 [ V_182 -> V_186 ] = V_189 ;
V_182 -> V_186 = ( V_182 -> V_186 + 1 ) % V_190 ;
V_182 -> V_191 ++ ;
}
}
static int F_118 ( struct V_146 * V_76 , int V_55 )
{
T_10 V_192 ;
int V_193 , V_194 ;
struct V_185 * V_182 = V_76 -> V_182 ;
int V_195 = ( V_55 + 1 ) % V_190 ;
if ( V_182 -> V_184 [ V_195 ] == V_188 )
return - V_196 ;
V_192 = F_105 ( V_76 -> V_147 + V_197 ) ;
if ( V_192 & V_198 ) {
V_193 = F_105 ( V_76 -> V_147 + V_199 ) ;
if ( ( V_193 >> V_200 ) == V_55 ) {
F_71 ( L_41
L_42 ,
( unsigned long long ) V_182 -> V_183 [ V_55 ] . V_201 ,
( unsigned long long ) V_182 -> V_183 [ V_55 ] . V_202 ) ;
memcpy ( & V_182 -> V_183 [ V_55 ] , & V_182 -> V_183 [ V_195 ] ,
sizeof( struct V_203 ) ) ;
F_119 ( V_198 , V_76 -> V_147 + V_197 ) ;
return - V_54 ;
}
}
if ( V_192 & V_204 ) {
V_193 = F_105 ( V_76 -> V_147 + V_199 ) ;
V_193 = ( ( V_193 >> V_200 ) - 1 + V_190 ) % V_190 ;
V_193 |= 1 ;
V_194 = F_105 ( V_76 -> V_147 + V_205 ) ;
V_194 = ( ( V_194 >> V_200 ) - 1 + V_190 ) % V_190 ;
F_119 ( V_204 , V_76 -> V_147 + V_197 ) ;
do {
if ( V_182 -> V_184 [ V_193 ] == V_206 )
V_182 -> V_184 [ V_193 ] = V_188 ;
V_193 = ( V_193 - 2 + V_190 ) % V_190 ;
} while ( V_193 != V_194 );
if ( V_182 -> V_184 [ V_195 ] == V_188 )
return - V_196 ;
}
if ( V_192 & V_207 )
F_119 ( V_207 , V_76 -> V_147 + V_197 ) ;
return 0 ;
}
int F_120 ( struct V_203 * V_183 , struct V_146 * V_76 )
{
int V_208 ;
struct V_185 * V_182 = V_76 -> V_182 ;
struct V_203 * V_209 , V_210 ;
int V_195 , V_55 ;
unsigned long V_75 ;
if ( ! V_182 )
return 0 ;
V_209 = V_182 -> V_183 ;
V_211:
V_208 = 0 ;
F_121 ( & V_182 -> V_212 , V_75 ) ;
while ( V_182 -> V_191 < 3 ) {
F_122 ( & V_182 -> V_212 , V_75 ) ;
F_123 () ;
F_121 ( & V_182 -> V_212 , V_75 ) ;
}
V_55 = V_182 -> V_213 ;
V_195 = ( V_55 + 1 ) % V_190 ;
V_182 -> V_184 [ V_55 ] = V_182 -> V_184 [ V_195 ] = V_206 ;
V_209 [ V_55 ] = * V_183 ;
V_210 . V_201 = F_124 ( V_187 ) |
V_214 | V_215 ;
V_210 . V_202 = F_125 ( & V_182 -> V_184 [ V_195 ] ) ;
V_209 [ V_195 ] = V_210 ;
V_182 -> V_213 = ( V_182 -> V_213 + 2 ) % V_190 ;
V_182 -> V_191 -= 2 ;
F_119 ( V_182 -> V_213 << V_200 , V_76 -> V_147 + V_205 ) ;
while ( V_182 -> V_184 [ V_195 ] != V_187 ) {
V_208 = F_118 ( V_76 , V_55 ) ;
if ( V_208 )
break;
F_126 ( & V_182 -> V_212 ) ;
F_123 () ;
F_127 ( & V_182 -> V_212 ) ;
}
V_182 -> V_184 [ V_55 ] = V_187 ;
F_117 ( V_182 ) ;
F_122 ( & V_182 -> V_212 , V_75 ) ;
if ( V_208 == - V_196 )
goto V_211;
return V_208 ;
}
void F_128 ( struct V_146 * V_76 )
{
struct V_203 V_183 ;
V_183 . V_201 = V_216 ;
V_183 . V_202 = 0 ;
F_120 ( & V_183 , V_76 ) ;
}
void F_129 ( struct V_146 * V_76 , T_2 V_217 , T_2 V_218 , T_5 V_219 ,
T_7 type )
{
struct V_203 V_183 ;
V_183 . V_201 = F_130 ( V_219 ) | F_131 ( V_218 ) | F_132 ( V_217 )
| F_133 ( type ) | V_220 ;
V_183 . V_202 = 0 ;
F_120 ( & V_183 , V_76 ) ;
}
void F_134 ( struct V_146 * V_76 , T_2 V_217 , T_7 V_130 ,
unsigned int V_221 , T_7 type )
{
T_5 V_222 = 0 , V_223 = 0 ;
struct V_203 V_183 ;
int V_224 = 0 ;
if ( F_135 ( V_76 -> V_133 ) )
V_222 = 1 ;
if ( F_136 ( V_76 -> V_133 ) )
V_223 = 1 ;
V_183 . V_201 = F_137 ( V_217 ) | F_138 ( V_223 ) | F_139 ( V_222 )
| F_140 ( type ) | V_225 ;
V_183 . V_202 = F_141 ( V_130 ) | F_142 ( V_224 )
| F_143 ( V_221 ) ;
F_120 ( & V_183 , V_76 ) ;
}
void F_144 ( struct V_146 * V_76 , T_2 V_218 , T_2 V_226 ,
T_7 V_130 , unsigned V_227 )
{
struct V_203 V_183 ;
if ( V_227 ) {
F_12 ( V_130 & ( ( 1 << ( V_228 + V_227 ) ) - 1 ) ) ;
V_130 |= ( 1 << ( V_228 + V_227 - 1 ) ) - 1 ;
V_183 . V_202 = F_145 ( V_130 ) | V_229 ;
} else
V_183 . V_202 = F_145 ( V_130 ) ;
if ( V_226 >= V_230 )
V_226 = 0 ;
V_183 . V_201 = F_146 ( V_218 ) | F_147 ( V_226 ) |
V_231 ;
F_120 ( & V_183 , V_76 ) ;
}
void F_148 ( struct V_146 * V_76 )
{
unsigned long V_75 ;
T_10 V_161 ;
T_11 V_232 = F_149 () ;
if ( ! F_150 ( V_76 -> V_134 ) )
return;
F_121 ( & V_76 -> V_176 , V_75 ) ;
V_161 = F_105 ( V_76 -> V_147 + V_168 ) ;
if ( ! ( V_161 & V_174 ) )
goto V_7;
while ( ( F_105 ( V_76 -> V_147 + V_205 ) !=
F_105 ( V_76 -> V_147 + V_199 ) ) &&
( V_233 > ( F_149 () - V_232 ) ) )
F_123 () ;
V_76 -> V_170 &= ~ V_175 ;
F_119 ( V_76 -> V_170 , V_76 -> V_147 + V_234 ) ;
F_151 ( V_76 , V_168 , F_105 ,
! ( V_161 & V_174 ) , V_161 ) ;
V_7:
F_122 ( & V_76 -> V_176 , V_75 ) ;
}
static void F_152 ( struct V_146 * V_76 )
{
T_10 V_161 ;
unsigned long V_75 ;
struct V_185 * V_182 = V_76 -> V_182 ;
V_182 -> V_213 = V_182 -> V_186 = 0 ;
V_182 -> V_191 = V_190 ;
F_121 ( & V_76 -> V_176 , V_75 ) ;
F_119 ( 0 , V_76 -> V_147 + V_205 ) ;
F_153 ( V_76 -> V_147 + V_235 , F_125 ( V_182 -> V_183 ) ) ;
V_76 -> V_170 |= V_175 ;
F_119 ( V_76 -> V_170 , V_76 -> V_147 + V_234 ) ;
F_151 ( V_76 , V_168 , F_105 , ( V_161 & V_174 ) , V_161 ) ;
F_122 ( & V_76 -> V_176 , V_75 ) ;
}
int F_154 ( struct V_146 * V_76 )
{
struct V_185 * V_182 ;
struct V_236 * V_237 ;
if ( ! F_150 ( V_76 -> V_134 ) )
return - V_105 ;
if ( V_76 -> V_182 )
return 0 ;
V_76 -> V_182 = F_155 ( sizeof( * V_182 ) , V_238 ) ;
if ( ! V_76 -> V_182 )
return - V_39 ;
V_182 = V_76 -> V_182 ;
V_237 = F_156 ( V_76 -> V_88 , V_238 | V_239 , 0 ) ;
if ( ! V_237 ) {
F_10 ( V_182 ) ;
V_76 -> V_182 = NULL ;
return - V_39 ;
}
V_182 -> V_183 = F_157 ( V_237 ) ;
V_182 -> V_184 = F_13 ( V_190 * sizeof( int ) , V_238 ) ;
if ( ! V_182 -> V_184 ) {
F_116 ( ( unsigned long ) V_182 -> V_183 ) ;
F_10 ( V_182 ) ;
V_76 -> V_182 = NULL ;
return - V_39 ;
}
F_108 ( & V_182 -> V_212 ) ;
F_152 ( V_76 ) ;
return 0 ;
}
static const char * F_158 ( T_5 V_240 , int * V_241 )
{
if ( V_240 >= 0x20 && ( V_240 - 0x20 <
F_159 ( V_242 ) ) ) {
* V_241 = V_243 ;
return V_242 [ V_240 - 0x20 ] ;
} else if ( V_240 < F_159 ( V_244 ) ) {
* V_241 = V_245 ;
return V_244 [ V_240 ] ;
} else {
* V_241 = V_246 ;
return L_43 ;
}
}
static inline int F_160 ( struct V_146 * V_76 , int V_180 )
{
if ( V_76 -> V_180 == V_180 )
return V_247 ;
else if ( V_76 -> V_181 == V_180 )
return V_248 ;
else
F_161 () ;
}
void F_162 ( struct V_249 * V_64 )
{
struct V_146 * V_76 = F_163 ( V_64 ) ;
int V_147 = F_160 ( V_76 , V_64 -> V_180 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
F_119 ( 0 , V_76 -> V_147 + V_147 ) ;
F_105 ( V_76 -> V_147 + V_147 ) ;
F_122 ( & V_76 -> V_176 , V_250 ) ;
}
void F_164 ( struct V_249 * V_64 )
{
struct V_146 * V_76 = F_163 ( V_64 ) ;
int V_147 = F_160 ( V_76 , V_64 -> V_180 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
F_119 ( V_251 , V_76 -> V_147 + V_147 ) ;
F_105 ( V_76 -> V_147 + V_147 ) ;
F_122 ( & V_76 -> V_176 , V_250 ) ;
}
void F_165 ( int V_180 , struct V_252 * V_253 )
{
struct V_146 * V_76 = F_166 ( V_180 ) ;
int V_147 = F_160 ( V_76 , V_180 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
F_119 ( V_253 -> V_64 , V_76 -> V_147 + V_147 + 4 ) ;
F_119 ( V_253 -> V_254 , V_76 -> V_147 + V_147 + 8 ) ;
F_119 ( V_253 -> V_255 , V_76 -> V_147 + V_147 + 12 ) ;
F_122 ( & V_76 -> V_176 , V_250 ) ;
}
void F_167 ( int V_180 , struct V_252 * V_253 )
{
struct V_146 * V_76 = F_166 ( V_180 ) ;
int V_147 = F_160 ( V_76 , V_180 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
V_253 -> V_64 = F_105 ( V_76 -> V_147 + V_147 + 4 ) ;
V_253 -> V_254 = F_105 ( V_76 -> V_147 + V_147 + 8 ) ;
V_253 -> V_255 = F_105 ( V_76 -> V_147 + V_147 + 12 ) ;
F_122 ( & V_76 -> V_176 , V_250 ) ;
}
static int F_168 ( struct V_146 * V_76 , int type ,
T_5 V_240 , T_2 V_256 , unsigned long long V_130 )
{
const char * V_257 ;
int V_241 ;
V_257 = F_158 ( V_240 , & V_241 ) ;
if ( V_241 == V_243 )
F_71 ( L_44 ,
V_256 >> 8 , F_16 ( V_256 & 0xFF ) ,
F_17 ( V_256 & 0xFF ) , V_130 >> 48 ,
V_240 , V_257 ) ;
else
F_71 ( L_45 ,
type ? L_46 : L_47 ,
V_256 >> 8 , F_16 ( V_256 & 0xFF ) ,
F_17 ( V_256 & 0xFF ) , V_130 , V_240 , V_257 ) ;
return 0 ;
}
T_12 F_169 ( int V_180 , void * V_258 )
{
struct V_146 * V_76 = V_258 ;
int V_147 , V_259 ;
T_10 V_260 ;
unsigned long V_250 ;
bool V_261 ;
static F_170 ( V_262 ,
V_263 ,
V_264 ) ;
V_261 = ! F_171 ( & V_262 ) ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
V_260 = F_105 ( V_76 -> V_147 + V_197 ) ;
if ( V_260 && ! V_261 )
F_71 ( L_48 , V_260 ) ;
if ( ! ( V_260 & V_265 ) )
goto V_266;
V_259 = F_172 ( V_260 ) ;
V_147 = F_173 ( V_76 -> V_133 ) ;
while ( 1 ) {
T_5 V_240 ;
T_2 V_256 ;
T_7 V_267 ;
int type ;
T_10 V_64 ;
V_64 = F_105 ( V_76 -> V_147 + V_147 +
V_259 * V_268 + 12 ) ;
if ( ! ( V_64 & V_269 ) )
break;
if ( ! V_261 ) {
V_240 = F_174 ( V_64 ) ;
type = F_175 ( V_64 ) ;
V_64 = F_105 ( V_76 -> V_147 + V_147 +
V_259 * V_268 + 8 ) ;
V_256 = F_176 ( V_64 ) ;
V_267 = F_83 ( V_76 -> V_147 + V_147 +
V_259 * V_268 ) ;
V_267 = F_177 ( V_267 ) ;
}
F_119 ( V_269 , V_76 -> V_147 + V_147 +
V_259 * V_268 + 12 ) ;
F_122 ( & V_76 -> V_176 , V_250 ) ;
if ( ! V_261 )
F_168 ( V_76 , type , V_240 ,
V_256 , V_267 ) ;
V_259 ++ ;
if ( V_259 >= F_178 ( V_76 -> V_133 ) )
V_259 = 0 ;
F_121 ( & V_76 -> V_176 , V_250 ) ;
}
F_119 ( V_270 | V_265 , V_76 -> V_147 + V_197 ) ;
V_266:
F_122 ( & V_76 -> V_176 , V_250 ) ;
return V_271 ;
}
int F_179 ( struct V_146 * V_76 )
{
int V_180 , V_56 ;
if ( V_76 -> V_180 )
return 0 ;
V_180 = F_180 ( V_76 -> V_157 , V_76 -> V_88 , V_76 ) ;
if ( V_180 > 0 ) {
V_76 -> V_180 = V_180 ;
} else {
F_71 ( L_49 ) ;
return - V_54 ;
}
V_56 = F_181 ( V_180 , F_169 , V_272 , V_76 -> V_153 , V_76 ) ;
if ( V_56 )
F_71 ( L_50 ) ;
return V_56 ;
}
int T_3 F_182 ( void )
{
struct V_1 * V_2 ;
struct V_146 * V_76 ;
F_183 (iommu, drhd) {
T_10 V_260 ;
int V_56 = F_179 ( V_76 ) ;
if ( V_56 ) {
F_71 ( L_51 ,
( unsigned long long ) V_2 -> V_70 , V_56 ) ;
return - 1 ;
}
F_169 ( V_76 -> V_180 , V_76 ) ;
V_260 = F_105 ( V_76 -> V_147 + V_197 ) ;
F_119 ( V_260 , V_76 -> V_147 + V_197 ) ;
}
return 0 ;
}
int F_184 ( struct V_146 * V_76 )
{
if ( ! F_150 ( V_76 -> V_134 ) )
return - V_105 ;
if ( ! V_76 -> V_182 )
return - V_105 ;
F_148 ( V_76 ) ;
F_152 ( V_76 ) ;
return 0 ;
}
int T_3 F_185 ( void )
{
struct V_114 * V_115 ;
V_115 = (struct V_114 * ) V_103 ;
if ( ! V_115 )
return 0 ;
return V_115 -> V_75 & 0x1 ;
}
static inline bool F_186 ( void )
{
return V_273 || V_177 ;
}
static int T_3 F_187 ( void )
{
struct V_1 * V_57 , * V_274 ;
if ( F_186 () )
return 0 ;
if ( V_38 != 1 && ! F_74 ( & V_5 ) )
F_188 ( & V_127 , & V_128 ) ;
F_36 ( & V_68 ) ;
F_189 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_190 ( & V_57 -> V_4 ) ;
F_42 ( V_57 ) ;
}
F_37 ( & V_68 ) ;
return 0 ;
}
static inline bool F_191 ( T_6 V_275 , int V_276 )
{
return F_192 ( V_275 , V_277 , V_278 , 1 << V_276 ) ;
}
static int F_193 ( T_6 V_275 , int V_276 ,
T_13 V_279 , void * V_73 )
{
int V_56 = - V_119 ;
union V_280 * V_281 ;
struct V_72 * V_6 ;
struct V_107 V_282 ;
static int V_283 [] = {
[ V_284 ] = V_94 ,
[ V_285 ] = V_97 ,
[ V_286 ] = V_98 ,
} ;
if ( ! F_191 ( V_275 , V_276 ) )
return 0 ;
V_281 = F_194 ( V_275 , V_277 , V_278 ,
V_276 , NULL , V_287 ) ;
if ( ! V_281 )
return - V_119 ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_108 [ V_283 [ V_276 ] ] = V_279 ;
V_282 . V_73 [ V_283 [ V_276 ] ] = V_73 ;
V_6 = (struct V_72 * ) V_281 -> V_288 . V_289 ;
V_56 = F_55 ( V_6 , V_281 -> V_288 . V_17 , & V_282 ) ;
F_195 ( V_281 ) ;
return V_56 ;
}
static int F_196 ( struct V_72 * V_60 , void * V_73 )
{
int V_56 ;
struct V_1 * V_57 ;
V_57 = F_38 ( (struct V_58 * ) V_60 ) ;
if ( ! V_57 )
return - V_119 ;
V_56 = F_197 ( V_57 , true ) ;
if ( V_56 == 0 )
V_56 = F_198 ( V_57 , true ) ;
return V_56 ;
}
static int F_199 ( struct V_72 * V_60 , void * V_73 )
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
return - V_154 ;
}
V_56 = F_197 ( V_57 , false ) ;
if ( V_56 == 0 )
V_56 = F_198 ( V_57 , false ) ;
return V_56 ;
}
static int F_200 ( struct V_72 * V_60 , void * V_73 )
{
struct V_1 * V_57 ;
V_57 = F_38 ( (struct V_58 * ) V_60 ) ;
if ( V_57 ) {
F_201 ( & V_57 -> V_4 ) ;
F_28 () ;
F_42 ( V_57 ) ;
}
return 0 ;
}
static int F_202 ( T_6 V_275 )
{
int V_56 ;
int V_116 = 0 ;
V_56 = F_193 ( V_275 , V_284 ,
& F_80 , ( void * ) 1 ) ;
if ( V_56 )
goto V_74;
V_56 = F_193 ( V_275 , V_284 ,
& F_40 , ( void * ) & V_116 ) ;
if ( V_56 == 0 && V_116 == 0 ) {
F_5 ( V_47 L_52 ) ;
goto V_74;
} else if ( V_56 ) {
goto V_290;
}
V_56 = F_193 ( V_275 , V_286 ,
& F_48 , NULL ) ;
if ( V_56 )
goto V_290;
V_56 = F_193 ( V_275 , V_285 ,
& V_118 , NULL ) ;
if ( V_56 )
goto V_291;
V_56 = F_193 ( V_275 , V_284 ,
& F_196 , NULL ) ;
if ( ! V_56 )
return 0 ;
F_193 ( V_275 , V_284 ,
& F_199 , NULL ) ;
V_291:
F_193 ( V_275 , V_285 ,
& V_292 , NULL ) ;
V_290:
F_193 ( V_275 , V_284 ,
& F_200 , NULL ) ;
V_74:
return V_56 ;
}
static int F_203 ( T_6 V_275 )
{
int V_56 ;
V_56 = F_193 ( V_275 , V_285 ,
& V_293 , NULL ) ;
if ( V_56 )
return V_56 ;
V_56 = F_193 ( V_275 , V_284 ,
& F_199 , NULL ) ;
if ( V_56 == 0 ) {
F_204 ( F_193 ( V_275 , V_285 ,
& V_292 , NULL ) ) ;
F_204 ( F_193 ( V_275 , V_284 ,
& F_200 , NULL ) ) ;
} else {
F_193 ( V_275 , V_284 ,
& F_196 , NULL ) ;
}
return V_56 ;
}
static T_4 F_205 ( T_6 V_275 , T_10 V_294 ,
void * V_295 , void * * V_296 )
{
T_6 * V_297 = V_296 ;
if ( F_191 ( V_275 , V_284 ) ) {
* V_297 = V_275 ;
return V_298 ;
}
return V_101 ;
}
static int F_206 ( T_6 V_275 , bool V_299 )
{
int V_56 ;
T_6 V_30 = NULL ;
T_4 V_100 ;
if ( ! F_186 () )
return 0 ;
if ( F_191 ( V_275 , V_284 ) ) {
V_30 = V_275 ;
} else {
V_100 = F_207 ( V_300 , V_275 ,
V_301 ,
F_205 ,
NULL , NULL , & V_30 ) ;
if ( F_208 ( V_100 ) ) {
F_5 ( L_53 ) ;
return - V_302 ;
}
}
if ( V_30 == NULL )
return 0 ;
F_36 ( & V_68 ) ;
if ( V_299 )
V_56 = F_202 ( V_30 ) ;
else
V_56 = F_203 ( V_30 ) ;
F_37 ( & V_68 ) ;
return V_56 ;
}
int F_209 ( T_6 V_275 )
{
return F_206 ( V_275 , true ) ;
}
int F_210 ( T_6 V_275 )
{
return F_206 ( V_275 , false ) ;
}
