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
V_100 = F_53 ( V_102 , 0 , & V_103 ) ;
if ( F_54 ( V_100 ) && ! V_103 ) {
F_5 ( L_14 ) ;
V_100 = V_104 ;
}
return ( F_54 ( V_100 ) ? 1 : 0 ) ;
}
static int F_55 ( struct V_72 * V_6 ,
T_1 V_105 , struct V_106 * V_107 )
{
int V_56 = 0 ;
struct V_72 * V_108 , * V_109 ;
struct V_72 * V_7 = ( ( void * ) V_6 ) + V_105 ;
for ( V_108 = V_6 ; V_108 < V_7 && V_56 == 0 ; V_108 = V_109 ) {
V_109 = ( void * ) V_108 + V_108 -> V_17 ;
if ( V_108 -> V_17 == 0 ) {
F_56 ( V_47 L_15 ) ;
break;
} else if ( V_109 > V_7 ) {
F_5 ( V_47 L_16 ) ;
V_56 = - V_54 ;
break;
}
if ( V_107 -> V_110 )
F_51 ( V_108 ) ;
if ( V_108 -> type >= V_111 ) {
F_56 ( L_17 ,
V_108 -> type ) ;
} else if ( V_107 -> V_107 [ V_108 -> type ] ) {
V_56 = V_107 -> V_107 [ V_108 -> type ] ( V_108 , V_107 -> V_73 [ V_108 -> type ] ) ;
} else if ( ! V_107 -> V_112 ) {
F_5 ( L_18 ,
V_108 -> type ) ;
V_56 = - V_54 ;
}
}
return V_56 ;
}
static inline int F_57 ( struct V_113 * V_114 ,
struct V_106 * V_107 )
{
return F_55 ( ( void * ) ( V_114 + 1 ) ,
V_114 -> V_60 . V_17 - sizeof( * V_114 ) , V_107 ) ;
}
static int T_3
F_58 ( void )
{
struct V_113 * V_114 ;
int V_56 = 0 ;
int V_115 = 0 ;
struct V_106 V_107 = {
. V_110 = true ,
. V_112 = true ,
. V_73 [ V_94 ] = & V_115 ,
. V_107 [ V_94 ] = & F_40 ,
. V_107 [ V_95 ] = & V_116 ,
. V_107 [ V_97 ] = & V_117 ,
. V_107 [ V_98 ] = & F_48 ,
. V_107 [ V_99 ] = & F_44 ,
} ;
F_52 () ;
V_103 = F_59 ( V_103 ) ;
V_114 = (struct V_113 * ) V_103 ;
if ( ! V_114 )
return - V_118 ;
if ( V_114 -> V_119 < V_120 - 1 ) {
F_5 ( L_19 ) ;
return - V_54 ;
}
F_21 ( L_20 , V_114 -> V_119 + 1 ) ;
V_56 = F_57 ( V_114 , & V_107 ) ;
if ( V_56 == 0 && V_115 == 0 )
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
struct V_121 * V_122 )
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
if ( V_10 -> V_123 != V_84 )
continue;
V_41 = ( void * ) ( V_10 + 1 ) ;
F_21 ( L_22 ,
F_67 ( & V_122 -> V_26 ) , V_57 -> V_70 ,
V_10 -> V_34 , V_41 -> V_22 , V_41 -> V_44 ) ;
F_23 (dmaru->devices, dmaru->devices_cnt, i, tmp)
if ( V_30 == NULL ) {
V_57 -> V_20 [ V_21 ] . V_34 = V_10 -> V_34 ;
V_57 -> V_20 [ V_21 ] . V_43 = F_68 ( V_41 -> V_22 ,
V_41 -> V_44 ) ;
F_24 ( V_57 -> V_20 [ V_21 ] . V_26 ,
F_25 ( & V_122 -> V_26 ) ) ;
return;
}
F_12 ( V_21 >= V_57 -> V_49 ) ;
}
}
F_5 ( L_23 ,
V_84 , F_67 ( & V_122 -> V_26 ) ) ;
}
static int T_3 F_69 ( void )
{
struct V_77 * V_78 ;
if ( V_103 == NULL )
return - V_118 ;
for ( V_78 = ( void * ) V_103 + sizeof( struct V_113 ) ;
( ( unsigned long ) V_78 ) < ( ( unsigned long ) V_103 ) + V_103 -> V_17 ;
V_78 = ( ( void * ) V_78 ) + V_78 -> V_60 . V_17 ) {
if ( V_78 -> V_60 . type == V_99 ) {
T_6 V_124 ;
struct V_121 * V_122 ;
if ( ! F_54 ( F_70 ( V_125 ,
V_78 -> V_79 ,
& V_124 ) ) ) {
F_71 ( L_24 ,
V_78 -> V_79 ) ;
continue;
}
if ( F_72 ( V_124 , & V_122 ) ) {
F_71 ( L_25 ,
V_78 -> V_79 ) ;
continue;
}
F_66 ( V_78 -> V_84 , V_122 ) ;
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
int V_56 ;
if ( V_128 == 0 ) {
V_56 = F_58 () ;
if ( V_56 < 0 ) {
if ( V_56 != - V_118 )
F_21 ( L_26 ) ;
} else if ( F_74 ( & V_5 ) ) {
F_21 ( L_27 ) ;
V_56 = - V_118 ;
}
if ( V_56 < 0 )
V_128 = V_56 ;
else
V_128 = 1 ;
}
return V_128 < 0 ? V_128 : 0 ;
}
static void F_78 ( T_7 V_129 , const char * V_130 )
{
F_79 (
1 , V_80 ,
L_28
L_7 ,
V_129 , V_130 ,
F_47 ( V_81 ) ,
F_47 ( V_82 ) ,
F_47 ( V_83 ) ) ;
}
static int T_8
F_80 ( struct V_72 * V_131 , void * V_73 )
{
struct V_58 * V_2 ;
void T_9 * V_129 ;
T_7 V_132 , V_133 ;
V_2 = ( void * ) V_131 ;
if ( ! V_2 -> V_71 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
if ( V_73 )
V_129 = F_81 ( V_2 -> V_71 , V_134 ) ;
else
V_129 = F_82 ( V_2 -> V_71 , V_134 ) ;
if ( ! V_129 ) {
F_5 ( L_30 , V_2 -> V_71 ) ;
return - V_54 ;
}
V_132 = F_83 ( V_129 + V_135 ) ;
V_133 = F_83 ( V_129 + V_136 ) ;
if ( V_73 )
F_84 ( V_129 ) ;
else
F_85 ( V_129 , V_134 ) ;
if ( V_132 == ( V_137 ) - 1 && V_133 == ( V_137 ) - 1 ) {
F_78 ( V_2 -> V_71 , L_31 ) ;
return - V_54 ;
}
return 0 ;
}
int T_3 F_86 ( void )
{
int V_56 ;
struct V_106 V_138 = {
. V_107 [ V_94 ] = & F_80 ,
. V_112 = true ,
} ;
F_36 ( & V_68 ) ;
V_56 = F_52 () ;
if ( V_56 )
V_56 = ! F_57 ( (struct V_113 * ) V_103 ,
& V_138 ) ;
if ( V_56 && ! V_139 && ! V_140 && ! V_141 ) {
V_140 = 1 ;
F_87 () ;
}
#ifdef F_88
if ( V_56 )
V_142 . V_76 . V_143 = V_144 ;
#endif
if ( V_103 ) {
F_89 ( V_103 ) ;
V_103 = NULL ;
}
F_37 ( & V_68 ) ;
return V_56 ? 1 : - V_118 ;
}
static void F_90 ( struct V_145 * V_76 )
{
F_84 ( V_76 -> V_146 ) ;
F_91 ( V_76 -> V_147 , V_76 -> V_148 ) ;
}
static int F_92 ( struct V_145 * V_76 , T_7 V_149 )
{
int V_150 , V_151 = 0 ;
V_76 -> V_147 = V_149 ;
V_76 -> V_148 = V_134 ;
if ( ! F_93 ( V_76 -> V_147 , V_76 -> V_148 , V_76 -> V_152 ) ) {
F_71 ( L_32 ) ;
V_151 = - V_153 ;
goto V_74;
}
V_76 -> V_146 = F_81 ( V_76 -> V_147 , V_76 -> V_148 ) ;
if ( ! V_76 -> V_146 ) {
F_71 ( L_33 ) ;
V_151 = - V_39 ;
goto V_154;
}
V_76 -> V_132 = F_83 ( V_76 -> V_146 + V_135 ) ;
V_76 -> V_133 = F_83 ( V_76 -> V_146 + V_136 ) ;
if ( V_76 -> V_132 == ( V_137 ) - 1 && V_76 -> V_133 == ( V_137 ) - 1 ) {
V_151 = - V_54 ;
F_78 ( V_149 , L_31 ) ;
goto V_155;
}
V_150 = F_94 ( int , F_95 ( V_76 -> V_133 ) ,
F_96 ( V_76 -> V_132 ) ) ;
V_150 = F_97 ( V_150 ) ;
if ( V_150 > V_76 -> V_148 ) {
F_84 ( V_76 -> V_146 ) ;
F_91 ( V_76 -> V_147 , V_76 -> V_148 ) ;
V_76 -> V_148 = V_150 ;
if ( ! F_93 ( V_76 -> V_147 , V_76 -> V_148 ,
V_76 -> V_152 ) ) {
F_71 ( L_32 ) ;
V_151 = - V_153 ;
goto V_74;
}
V_76 -> V_146 = F_81 ( V_76 -> V_147 , V_76 -> V_148 ) ;
if ( ! V_76 -> V_146 ) {
F_71 ( L_33 ) ;
V_151 = - V_39 ;
goto V_154;
}
}
V_151 = 0 ;
goto V_74;
V_155:
F_84 ( V_76 -> V_146 ) ;
V_154:
F_91 ( V_76 -> V_147 , V_76 -> V_148 ) ;
V_74:
return V_151 ;
}
static int F_98 ( struct V_145 * V_76 )
{
V_76 -> V_156 = F_99 ( V_157 ,
V_158 ) ;
if ( V_76 -> V_156 >= V_158 ) {
V_76 -> V_156 = - 1 ;
} else {
F_100 ( V_76 -> V_156 , V_157 ) ;
sprintf ( V_76 -> V_152 , L_34 , V_76 -> V_156 ) ;
}
return V_76 -> V_156 ;
}
static void F_101 ( struct V_145 * V_76 )
{
if ( V_76 -> V_156 >= 0 ) {
F_102 ( V_76 -> V_156 , V_157 ) ;
V_76 -> V_156 = - 1 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_145 * V_76 ;
T_10 V_159 , V_160 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_151 ;
if ( ! V_2 -> V_70 ) {
F_78 ( 0 , L_29 ) ;
return - V_54 ;
}
V_76 = F_13 ( sizeof( * V_76 ) , V_19 ) ;
if ( ! V_76 )
return - V_39 ;
if ( F_98 ( V_76 ) < 0 ) {
F_71 ( L_35 ) ;
V_151 = - V_163 ;
goto error;
}
V_151 = F_92 ( V_76 , V_2 -> V_70 ) ;
if ( V_151 ) {
F_71 ( L_36 , V_76 -> V_152 ) ;
goto V_164;
}
V_151 = - V_54 ;
V_161 = F_103 ( V_76 ) ;
if ( V_161 < 0 ) {
F_71 ( L_37 ,
V_76 -> V_156 ) ;
goto V_165;
}
V_162 = F_104 ( V_76 ) ;
if ( V_162 < 0 ) {
F_71 ( L_38 ,
V_76 -> V_156 ) ;
goto V_165;
}
V_76 -> V_161 = V_161 ;
V_76 -> V_162 = V_162 ;
V_76 -> V_48 = V_2 -> V_48 ;
V_76 -> V_88 = - 1 ;
V_159 = F_105 ( V_76 -> V_146 + V_166 ) ;
F_21 ( L_39 ,
V_76 -> V_152 ,
( unsigned long long ) V_2 -> V_70 ,
F_106 ( V_159 ) , F_107 ( V_159 ) ,
( unsigned long long ) V_76 -> V_132 ,
( unsigned long long ) V_76 -> V_133 ) ;
V_160 = F_105 ( V_76 -> V_146 + V_167 ) ;
if ( V_160 & V_168 )
V_76 -> V_169 |= V_170 ;
if ( V_160 & V_171 )
V_76 -> V_169 |= V_172 ;
if ( V_160 & V_173 )
V_76 -> V_169 |= V_174 ;
F_108 ( & V_76 -> V_175 ) ;
if ( V_176 ) {
V_151 = F_109 ( & V_76 -> V_76 , NULL ,
V_177 ,
L_40 , V_76 -> V_152 ) ;
if ( V_151 )
goto V_165;
F_110 ( & V_76 -> V_76 , & V_178 ) ;
V_151 = F_111 ( & V_76 -> V_76 ) ;
if ( V_151 )
goto V_165;
}
V_2 -> V_76 = V_76 ;
return 0 ;
V_165:
F_90 ( V_76 ) ;
V_164:
F_101 ( V_76 ) ;
error:
F_10 ( V_76 ) ;
return V_151 ;
}
static void F_43 ( struct V_145 * V_76 )
{
if ( V_176 ) {
F_112 ( & V_76 -> V_76 ) ;
F_113 ( & V_76 -> V_76 ) ;
}
if ( V_76 -> V_179 ) {
if ( V_76 -> V_180 ) {
F_114 ( V_76 -> V_180 , V_76 ) ;
F_115 ( V_76 -> V_180 ) ;
V_76 -> V_180 = 0 ;
}
F_114 ( V_76 -> V_179 , V_76 ) ;
F_115 ( V_76 -> V_179 ) ;
V_76 -> V_179 = 0 ;
}
if ( V_76 -> V_181 ) {
F_116 ( ( unsigned long ) V_76 -> V_181 -> V_182 ) ;
F_10 ( V_76 -> V_181 -> V_183 ) ;
F_10 ( V_76 -> V_181 ) ;
}
if ( V_76 -> V_146 )
F_90 ( V_76 ) ;
F_101 ( V_76 ) ;
F_10 ( V_76 ) ;
}
static inline void F_117 ( struct V_184 * V_181 )
{
while ( V_181 -> V_183 [ V_181 -> V_185 ] == V_186 ||
V_181 -> V_183 [ V_181 -> V_185 ] == V_187 ) {
V_181 -> V_183 [ V_181 -> V_185 ] = V_188 ;
V_181 -> V_185 = ( V_181 -> V_185 + 1 ) % V_189 ;
V_181 -> V_190 ++ ;
}
}
static int F_118 ( struct V_145 * V_76 , int V_55 )
{
T_10 V_191 ;
int V_192 , V_193 ;
struct V_184 * V_181 = V_76 -> V_181 ;
int V_194 = ( V_55 + 1 ) % V_189 ;
if ( V_181 -> V_183 [ V_194 ] == V_187 )
return - V_195 ;
V_191 = F_105 ( V_76 -> V_146 + V_196 ) ;
if ( V_191 & V_197 ) {
V_192 = F_105 ( V_76 -> V_146 + V_198 ) ;
if ( ( V_192 >> V_199 ) == V_55 ) {
F_71 ( L_41
L_42 ,
( unsigned long long ) V_181 -> V_182 [ V_55 ] . V_200 ,
( unsigned long long ) V_181 -> V_182 [ V_55 ] . V_201 ) ;
memcpy ( & V_181 -> V_182 [ V_55 ] , & V_181 -> V_182 [ V_194 ] ,
sizeof( struct V_202 ) ) ;
F_119 ( V_197 , V_76 -> V_146 + V_196 ) ;
return - V_54 ;
}
}
if ( V_191 & V_203 ) {
V_192 = F_105 ( V_76 -> V_146 + V_198 ) ;
V_192 = ( ( V_192 >> V_199 ) - 1 + V_189 ) % V_189 ;
V_192 |= 1 ;
V_193 = F_105 ( V_76 -> V_146 + V_204 ) ;
V_193 = ( ( V_193 >> V_199 ) - 1 + V_189 ) % V_189 ;
F_119 ( V_203 , V_76 -> V_146 + V_196 ) ;
do {
if ( V_181 -> V_183 [ V_192 ] == V_205 )
V_181 -> V_183 [ V_192 ] = V_187 ;
V_192 = ( V_192 - 2 + V_189 ) % V_189 ;
} while ( V_192 != V_193 );
if ( V_181 -> V_183 [ V_194 ] == V_187 )
return - V_195 ;
}
if ( V_191 & V_206 )
F_119 ( V_206 , V_76 -> V_146 + V_196 ) ;
return 0 ;
}
int F_120 ( struct V_202 * V_182 , struct V_145 * V_76 )
{
int V_207 ;
struct V_184 * V_181 = V_76 -> V_181 ;
struct V_202 * V_208 , V_209 ;
int V_194 , V_55 ;
unsigned long V_75 ;
if ( ! V_181 )
return 0 ;
V_208 = V_181 -> V_182 ;
V_210:
V_207 = 0 ;
F_121 ( & V_181 -> V_211 , V_75 ) ;
while ( V_181 -> V_190 < 3 ) {
F_122 ( & V_181 -> V_211 , V_75 ) ;
F_123 () ;
F_121 ( & V_181 -> V_211 , V_75 ) ;
}
V_55 = V_181 -> V_212 ;
V_194 = ( V_55 + 1 ) % V_189 ;
V_181 -> V_183 [ V_55 ] = V_181 -> V_183 [ V_194 ] = V_205 ;
V_208 [ V_55 ] = * V_182 ;
V_209 . V_200 = F_124 ( V_186 ) |
V_213 | V_214 ;
V_209 . V_201 = F_125 ( & V_181 -> V_183 [ V_194 ] ) ;
V_208 [ V_194 ] = V_209 ;
V_181 -> V_212 = ( V_181 -> V_212 + 2 ) % V_189 ;
V_181 -> V_190 -= 2 ;
F_119 ( V_181 -> V_212 << V_199 , V_76 -> V_146 + V_204 ) ;
while ( V_181 -> V_183 [ V_194 ] != V_186 ) {
V_207 = F_118 ( V_76 , V_55 ) ;
if ( V_207 )
break;
F_126 ( & V_181 -> V_211 ) ;
F_123 () ;
F_127 ( & V_181 -> V_211 ) ;
}
V_181 -> V_183 [ V_55 ] = V_186 ;
F_117 ( V_181 ) ;
F_122 ( & V_181 -> V_211 , V_75 ) ;
if ( V_207 == - V_195 )
goto V_210;
return V_207 ;
}
void F_128 ( struct V_145 * V_76 )
{
struct V_202 V_182 ;
V_182 . V_200 = V_215 ;
V_182 . V_201 = 0 ;
F_120 ( & V_182 , V_76 ) ;
}
void F_129 ( struct V_145 * V_76 , T_2 V_216 , T_2 V_217 , T_5 V_218 ,
T_7 type )
{
struct V_202 V_182 ;
V_182 . V_200 = F_130 ( V_218 ) | F_131 ( V_217 ) | F_132 ( V_216 )
| F_133 ( type ) | V_219 ;
V_182 . V_201 = 0 ;
F_120 ( & V_182 , V_76 ) ;
}
void F_134 ( struct V_145 * V_76 , T_2 V_216 , T_7 V_129 ,
unsigned int V_220 , T_7 type )
{
T_5 V_221 = 0 , V_222 = 0 ;
struct V_202 V_182 ;
int V_223 = 0 ;
if ( F_135 ( V_76 -> V_132 ) )
V_221 = 1 ;
if ( F_136 ( V_76 -> V_132 ) )
V_222 = 1 ;
V_182 . V_200 = F_137 ( V_216 ) | F_138 ( V_222 ) | F_139 ( V_221 )
| F_140 ( type ) | V_224 ;
V_182 . V_201 = F_141 ( V_129 ) | F_142 ( V_223 )
| F_143 ( V_220 ) ;
F_120 ( & V_182 , V_76 ) ;
}
void F_144 ( struct V_145 * V_76 , T_2 V_217 , T_2 V_225 ,
T_7 V_129 , unsigned V_226 )
{
struct V_202 V_182 ;
if ( V_226 ) {
F_12 ( V_129 & ( ( 1 << ( V_227 + V_226 ) ) - 1 ) ) ;
V_129 |= ( 1 << ( V_227 + V_226 - 1 ) ) - 1 ;
V_182 . V_201 = F_145 ( V_129 ) | V_228 ;
} else
V_182 . V_201 = F_145 ( V_129 ) ;
if ( V_225 >= V_229 )
V_225 = 0 ;
V_182 . V_200 = F_146 ( V_217 ) | F_147 ( V_225 ) |
V_230 ;
F_120 ( & V_182 , V_76 ) ;
}
void F_148 ( struct V_145 * V_76 )
{
unsigned long V_75 ;
T_10 V_160 ;
T_11 V_231 = F_149 () ;
if ( ! F_150 ( V_76 -> V_133 ) )
return;
F_121 ( & V_76 -> V_175 , V_75 ) ;
V_160 = F_105 ( V_76 -> V_146 + V_167 ) ;
if ( ! ( V_160 & V_173 ) )
goto V_7;
while ( ( F_105 ( V_76 -> V_146 + V_204 ) !=
F_105 ( V_76 -> V_146 + V_198 ) ) &&
( V_232 > ( F_149 () - V_231 ) ) )
F_123 () ;
V_76 -> V_169 &= ~ V_174 ;
F_119 ( V_76 -> V_169 , V_76 -> V_146 + V_233 ) ;
F_151 ( V_76 , V_167 , F_105 ,
! ( V_160 & V_173 ) , V_160 ) ;
V_7:
F_122 ( & V_76 -> V_175 , V_75 ) ;
}
static void F_152 ( struct V_145 * V_76 )
{
T_10 V_160 ;
unsigned long V_75 ;
struct V_184 * V_181 = V_76 -> V_181 ;
V_181 -> V_212 = V_181 -> V_185 = 0 ;
V_181 -> V_190 = V_189 ;
F_121 ( & V_76 -> V_175 , V_75 ) ;
F_119 ( 0 , V_76 -> V_146 + V_204 ) ;
F_153 ( V_76 -> V_146 + V_234 , F_125 ( V_181 -> V_182 ) ) ;
V_76 -> V_169 |= V_174 ;
F_119 ( V_76 -> V_169 , V_76 -> V_146 + V_233 ) ;
F_151 ( V_76 , V_167 , F_105 , ( V_160 & V_173 ) , V_160 ) ;
F_122 ( & V_76 -> V_175 , V_75 ) ;
}
int F_154 ( struct V_145 * V_76 )
{
struct V_184 * V_181 ;
struct V_235 * V_236 ;
if ( ! F_150 ( V_76 -> V_133 ) )
return - V_237 ;
if ( V_76 -> V_181 )
return 0 ;
V_76 -> V_181 = F_155 ( sizeof( * V_181 ) , V_238 ) ;
if ( ! V_76 -> V_181 )
return - V_39 ;
V_181 = V_76 -> V_181 ;
V_236 = F_156 ( V_76 -> V_88 , V_238 | V_239 , 0 ) ;
if ( ! V_236 ) {
F_10 ( V_181 ) ;
V_76 -> V_181 = NULL ;
return - V_39 ;
}
V_181 -> V_182 = F_157 ( V_236 ) ;
V_181 -> V_183 = F_13 ( V_189 * sizeof( int ) , V_238 ) ;
if ( ! V_181 -> V_183 ) {
F_116 ( ( unsigned long ) V_181 -> V_182 ) ;
F_10 ( V_181 ) ;
V_76 -> V_181 = NULL ;
return - V_39 ;
}
F_108 ( & V_181 -> V_211 ) ;
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
static inline int F_160 ( struct V_145 * V_76 , int V_179 )
{
if ( V_76 -> V_179 == V_179 )
return V_247 ;
else if ( V_76 -> V_180 == V_179 )
return V_248 ;
else
F_161 () ;
}
void F_162 ( struct V_249 * V_64 )
{
struct V_145 * V_76 = F_163 ( V_64 ) ;
int V_146 = F_160 ( V_76 , V_64 -> V_179 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
F_119 ( 0 , V_76 -> V_146 + V_146 ) ;
F_105 ( V_76 -> V_146 + V_146 ) ;
F_122 ( & V_76 -> V_175 , V_250 ) ;
}
void F_164 ( struct V_249 * V_64 )
{
struct V_145 * V_76 = F_163 ( V_64 ) ;
int V_146 = F_160 ( V_76 , V_64 -> V_179 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
F_119 ( V_251 , V_76 -> V_146 + V_146 ) ;
F_105 ( V_76 -> V_146 + V_146 ) ;
F_122 ( & V_76 -> V_175 , V_250 ) ;
}
void F_165 ( int V_179 , struct V_252 * V_253 )
{
struct V_145 * V_76 = F_166 ( V_179 ) ;
int V_146 = F_160 ( V_76 , V_179 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
F_119 ( V_253 -> V_64 , V_76 -> V_146 + V_146 + 4 ) ;
F_119 ( V_253 -> V_254 , V_76 -> V_146 + V_146 + 8 ) ;
F_119 ( V_253 -> V_255 , V_76 -> V_146 + V_146 + 12 ) ;
F_122 ( & V_76 -> V_175 , V_250 ) ;
}
void F_167 ( int V_179 , struct V_252 * V_253 )
{
struct V_145 * V_76 = F_166 ( V_179 ) ;
int V_146 = F_160 ( V_76 , V_179 ) ;
unsigned long V_250 ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
V_253 -> V_64 = F_105 ( V_76 -> V_146 + V_146 + 4 ) ;
V_253 -> V_254 = F_105 ( V_76 -> V_146 + V_146 + 8 ) ;
V_253 -> V_255 = F_105 ( V_76 -> V_146 + V_146 + 12 ) ;
F_122 ( & V_76 -> V_175 , V_250 ) ;
}
static int F_168 ( struct V_145 * V_76 , int type ,
T_5 V_240 , T_2 V_256 , unsigned long long V_129 )
{
const char * V_257 ;
int V_241 ;
V_257 = F_158 ( V_240 , & V_241 ) ;
if ( V_241 == V_243 )
F_71 ( L_44 ,
V_256 >> 8 , F_16 ( V_256 & 0xFF ) ,
F_17 ( V_256 & 0xFF ) , V_129 >> 48 ,
V_240 , V_257 ) ;
else
F_71 ( L_45 ,
type ? L_46 : L_47 ,
V_256 >> 8 , F_16 ( V_256 & 0xFF ) ,
F_17 ( V_256 & 0xFF ) , V_129 , V_240 , V_257 ) ;
return 0 ;
}
T_12 F_169 ( int V_179 , void * V_258 )
{
struct V_145 * V_76 = V_258 ;
int V_146 , V_259 ;
T_10 V_260 ;
unsigned long V_250 ;
bool V_261 ;
static F_170 ( V_262 ,
V_263 ,
V_264 ) ;
V_261 = ! F_171 ( & V_262 ) ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
V_260 = F_105 ( V_76 -> V_146 + V_196 ) ;
if ( V_260 && ! V_261 )
F_71 ( L_48 , V_260 ) ;
if ( ! ( V_260 & V_265 ) )
goto V_266;
V_259 = F_172 ( V_260 ) ;
V_146 = F_173 ( V_76 -> V_132 ) ;
while ( 1 ) {
T_5 V_240 ;
T_2 V_256 ;
T_7 V_267 ;
int type ;
T_10 V_64 ;
V_64 = F_105 ( V_76 -> V_146 + V_146 +
V_259 * V_268 + 12 ) ;
if ( ! ( V_64 & V_269 ) )
break;
if ( ! V_261 ) {
V_240 = F_174 ( V_64 ) ;
type = F_175 ( V_64 ) ;
V_64 = F_105 ( V_76 -> V_146 + V_146 +
V_259 * V_268 + 8 ) ;
V_256 = F_176 ( V_64 ) ;
V_267 = F_83 ( V_76 -> V_146 + V_146 +
V_259 * V_268 ) ;
V_267 = F_177 ( V_267 ) ;
}
F_119 ( V_269 , V_76 -> V_146 + V_146 +
V_259 * V_268 + 12 ) ;
F_122 ( & V_76 -> V_175 , V_250 ) ;
if ( ! V_261 )
F_168 ( V_76 , type , V_240 ,
V_256 , V_267 ) ;
V_259 ++ ;
if ( V_259 >= F_178 ( V_76 -> V_132 ) )
V_259 = 0 ;
F_121 ( & V_76 -> V_175 , V_250 ) ;
}
F_119 ( V_270 | V_265 , V_76 -> V_146 + V_196 ) ;
V_266:
F_122 ( & V_76 -> V_175 , V_250 ) ;
return V_271 ;
}
int F_179 ( struct V_145 * V_76 )
{
int V_179 , V_56 ;
if ( V_76 -> V_179 )
return 0 ;
V_179 = F_180 ( V_76 -> V_156 , V_76 -> V_88 , V_76 ) ;
if ( V_179 > 0 ) {
V_76 -> V_179 = V_179 ;
} else {
F_71 ( L_49 ) ;
return - V_54 ;
}
V_56 = F_181 ( V_179 , F_169 , V_272 , V_76 -> V_152 , V_76 ) ;
if ( V_56 )
F_71 ( L_50 ) ;
return V_56 ;
}
int T_3 F_182 ( void )
{
struct V_1 * V_2 ;
struct V_145 * V_76 ;
F_183 (iommu, drhd) {
T_10 V_260 ;
int V_56 = F_179 ( V_76 ) ;
if ( V_56 ) {
F_71 ( L_51 ,
( unsigned long long ) V_2 -> V_70 , V_56 ) ;
return - 1 ;
}
F_169 ( V_76 -> V_179 , V_76 ) ;
V_260 = F_105 ( V_76 -> V_146 + V_196 ) ;
F_119 ( V_260 , V_76 -> V_146 + V_196 ) ;
}
return 0 ;
}
int F_184 ( struct V_145 * V_76 )
{
if ( ! F_150 ( V_76 -> V_133 ) )
return - V_237 ;
if ( ! V_76 -> V_181 )
return - V_237 ;
F_148 ( V_76 ) ;
F_152 ( V_76 ) ;
return 0 ;
}
int T_3 F_185 ( void )
{
struct V_113 * V_114 ;
V_114 = (struct V_113 * ) V_103 ;
if ( ! V_114 )
return 0 ;
return V_114 -> V_75 & 0x1 ;
}
static inline bool F_186 ( void )
{
return V_273 || V_176 ;
}
static int T_3 F_187 ( void )
{
struct V_1 * V_57 , * V_274 ;
if ( F_186 () )
return 0 ;
if ( V_38 != 1 && ! F_74 ( & V_5 ) )
F_188 ( & V_126 , & V_127 ) ;
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
int V_56 = - V_118 ;
union V_280 * V_281 ;
struct V_72 * V_6 ;
struct V_106 V_282 ;
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
return - V_118 ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_107 [ V_283 [ V_276 ] ] = V_279 ;
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
return - V_118 ;
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
return - V_153 ;
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
int V_115 = 0 ;
V_56 = F_193 ( V_275 , V_284 ,
& F_80 , ( void * ) 1 ) ;
if ( V_56 )
goto V_74;
V_56 = F_193 ( V_275 , V_284 ,
& F_40 , ( void * ) & V_115 ) ;
if ( V_56 == 0 && V_115 == 0 ) {
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
& V_117 , NULL ) ;
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
