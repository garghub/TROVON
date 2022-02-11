static int F_1 ( int * V_1 , struct V_2 * * V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_2 * V_6 = NULL ;
if ( ( V_4 = F_2 () ) < 0 ) {
F_3 ( V_7 L_1 , V_4 ) ;
goto V_8;
}
V_5 = V_9 * sizeof( struct V_2 ) ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 == NULL ) {
F_3 ( L_2 , ( int ) V_5 ) ;
V_4 = - V_10 ;
goto V_8;
}
V_4 = F_5 ( V_11 , V_12 ,
0 , V_5 , ( T_1 ) V_6 , 0 , 0 , NULL ) ;
if ( V_4 != V_13 ) {
V_4 = - V_14 ;
F_6 ( V_6 ) ;
}
V_8:
* V_1 = V_9 ;
* V_3 = V_6 ;
return V_4 ;
}
static int F_7 ( char * V_15 ,
int * V_16 , int * V_17 , int * V_18 , int * V_19 )
{
char type ;
if ( sscanf ( V_15 , L_3 ,
V_16 , & type , V_17 , V_19 ) == 4 )
* V_18 = 0 ;
else
if ( sscanf ( V_15 , L_4 ,
V_16 , & type , V_17 , V_18 , V_19 ) != 5 )
return - 1 ;
return 0 ;
}
static int F_8 ( char * V_15 )
{
int V_20 ;
T_2 V_21 ;
T_3 V_22 ;
int V_16 , V_17 , V_18 , V_19 ;
int V_23 , V_24 , V_25 , V_26 ;
if ( F_7 ( V_15 , & V_16 , & V_17 , & V_18 , & V_19 ) )
return - 1 ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_21 = F_9 ( V_20 ) ;
V_22 = F_10 ( V_21 ) ;
V_23 = F_11 ( V_22 ) ;
V_24 = F_12 ( V_22 ) ;
V_25 = F_13 ( V_21 ) ;
V_26 = F_14 ( V_21 ) ;
if ( V_16 == V_23 && V_17 == V_24 &&
V_18 == V_25 && V_19 == V_26 ) {
break;
}
}
return F_15 ( V_20 ) ? V_20 : - 1 ;
}
static int F_16 ( struct V_2 * V_28 )
{
if ( ! F_17 ( V_28 ) && ! F_18 ( V_28 ) )
F_19 () ;
if ( F_20 ( V_28 ) )
return - 1 ;
return F_8 ( V_28 -> V_15 ) ;
}
static int F_21 ( struct V_2 * V_28 ,
struct V_2 * V_29 )
{
int V_30 ;
struct V_2 * V_31 ;
for ( V_30 = 0 , V_31 = V_29 ; V_31 != V_28 ; V_31 ++ ) {
if ( F_20 ( V_31 ) )
continue;
if ( F_22 ( V_31 , V_28 ) )
V_30 ++ ;
}
return V_30 ;
}
static const char * F_23 ( struct V_2 * V_28 ,
struct V_2 * V_29 , int * V_30 )
{
int V_32 ;
const char * V_33 = V_34 ;
if ( ( V_32 = F_17 ( V_28 ) ) || F_18 ( V_28 ) ) {
V_33 = V_32 ? V_35 : V_36 ;
* V_30 = F_16 ( V_28 ) ;
}
else {
* V_30 = F_21 ( V_28 , V_29 ) ;
if ( F_24 ( V_28 ) )
V_33 = V_37 ;
}
return V_33 ;
}
static void F_25 ( struct V_38 * V_39 )
{
char * V_31 ;
T_4 V_5 ;
int V_4 ;
for ( V_5 = V_40 ; V_5 < 16 * V_40 ; V_5 += V_40 ) {
if ( ! ( V_31 = F_26 ( V_5 , V_41 ) ) )
break;
V_4 = F_27 ( F_28 ( V_31 ) , V_5 ) ;
if ( V_4 == V_42 )
F_29 ( V_39 , V_31 ) ;
F_30 ( V_31 ) ;
if ( V_4 == V_42 || V_4 == V_43 )
break;
}
}
static inline int F_31 ( T_5 V_44 )
{
return V_44 < V_45 && F_32 ( V_44 ) && F_33 ( V_44 ) ;
}
static inline int F_34 ( T_5 V_44 )
{
return V_44 < V_45 && F_32 ( V_44 ) && F_35 ( V_44 ) -> V_46 ;
}
static struct V_2 *
F_36 ( struct V_2 * V_6 ,
int V_1 , int V_47 )
{
int V_48 ;
struct V_2 * V_31 = V_6 ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ , V_31 ++ ) {
if ( V_31 -> V_47 == V_47 )
return V_31 ;
}
return NULL ;
}
static int F_37 ( struct V_2 * V_6 ,
int V_1 , T_5 V_44 , T_5 * V_49 , T_5 * V_50 )
{
int V_4 ;
struct V_2 * V_51 = NULL ;
struct V_2 * V_52 ;
struct V_2 * V_53 ;
struct V_2 * V_54 ;
struct V_55 V_56 [ 16 ] ;
int V_5 , V_48 , V_57 ;
T_5 V_58 ;
int V_59 = 0 ;
int V_60 = 0 ;
if ( ! F_15 ( V_44 ) )
return - V_14 ;
if ( F_31 ( V_44 ) ) {
if ( V_50 )
* V_50 = V_44 ;
V_60 ++ ;
}
if ( F_34 ( V_44 ) ) {
if ( V_49 )
* V_49 = V_44 ;
V_59 ++ ;
}
if ( V_60 && V_59 )
return 0 ;
for ( V_48 = 0 , V_52 = V_6 ; V_48 < V_1 ; V_48 ++ , V_52 ++ ) {
if ( ! F_17 ( V_52 ) && ! F_18 ( V_52 ) )
continue;
if ( V_44 == F_16 ( V_52 ) ) {
V_51 = V_52 ;
break;
}
}
if ( ! V_51 ) {
V_4 = - V_61 ;
goto V_62;
}
V_5 = V_52 -> V_63 * sizeof( struct V_55 ) ;
F_38 ( V_5 > sizeof( V_56 ) ) ;
V_4 = F_5 ( V_11 ,
V_64 , V_51 -> V_47 , V_5 ,
( T_1 ) & V_56 , 0 , 0 , NULL ) ;
if ( V_4 != V_13 ) {
V_4 = - V_14 ;
goto V_62;
}
for ( V_54 = NULL , V_57 = 0 ; V_57 < V_52 -> V_63 ; V_57 ++ ) {
V_53 = F_36 ( V_6 , V_1 , V_56 [ V_57 ] . V_65 ) ;
if ( V_53 && F_24 ( V_53 ) )
V_54 = V_53 ;
if ( ! V_53 || F_20 ( V_53 ) ||
! F_17 ( V_53 ) || F_18 ( V_53 ) ) {
continue;
}
V_58 = F_16 ( V_53 ) ;
if ( ! V_60 && F_31 ( V_58 ) ) {
if ( V_50 )
* V_50 = V_58 ;
V_60 ++ ;
}
if ( ! V_59 && F_34 ( V_58 ) ) {
if ( V_49 )
* V_49 = V_58 ;
V_59 ++ ;
}
}
if ( V_54 && ( ! V_60 || ! V_59 ) ) {
V_5 = V_54 -> V_63 * sizeof( struct V_55 ) ;
F_38 ( V_5 > sizeof( V_56 ) ) ;
V_4 = F_5 ( V_11 ,
V_64 , V_54 -> V_47 , V_5 ,
( T_1 ) & V_56 , 0 , 0 , NULL ) ;
if ( V_4 != V_13 ) {
V_4 = - V_14 ;
goto V_62;
}
for ( V_57 = 0 ; V_57 < V_54 -> V_63 ; V_57 ++ ) {
V_53 = F_36 ( V_6 , V_1 ,
V_56 [ V_57 ] . V_65 ) ;
if ( ! V_53 || V_53 -> V_47 == V_44 ||
F_20 ( V_53 ) ||
! F_17 ( V_53 ) ||
F_18 ( V_53 ) ) {
continue;
}
V_58 = F_16 ( V_53 ) ;
if ( ! V_60 && F_31 ( V_58 ) ) {
if ( V_50 )
* V_50 = V_58 ;
V_60 ++ ;
}
if ( ! V_59 && F_34 ( V_58 ) ) {
if ( V_49 )
* V_49 = V_58 ;
V_59 ++ ;
}
if ( V_60 && V_59 )
break;
}
}
if ( ! V_60 || ! V_59 ) {
for ( V_48 = 0 , V_52 = V_6 ; V_48 < V_1 ; V_48 ++ , V_52 ++ ) {
if ( F_20 ( V_52 ) ||
F_18 ( V_52 ) ||
! F_17 ( V_52 ) ) {
continue;
}
V_58 = F_16 ( V_52 ) ;
if ( ! V_60 && F_31 ( V_58 ) ) {
if ( V_50 )
* V_50 = V_58 ;
V_60 ++ ;
}
if ( ! V_59 && F_34 ( V_58 ) ) {
if ( V_49 )
* V_49 = V_58 ;
V_59 ++ ;
}
if ( V_60 && V_59 )
break;
}
}
if ( ! V_60 || ! V_59 )
V_4 = - V_66 ;
V_62:
return V_4 ;
}
static int F_39 ( struct V_38 * V_39 , void * V_67 )
{
int V_5 ;
int V_68 ;
int V_4 = 0 ;
int V_48 ;
int V_57 ;
const char * V_33 ;
int V_30 ;
char V_69 ;
struct V_70 * V_58 ;
struct V_55 * V_56 ;
struct V_2 * V_31 ;
struct V_2 * V_28 = V_67 ;
struct V_2 * V_29 = V_39 -> V_71 ;
T_6 V_72 ;
T_6 V_73 ;
T_6 V_74 ;
T_6 V_75 ;
T_6 V_76 ;
T_6 V_77 ;
T_6 V_78 ;
T_7 V_79 ;
int V_80 ;
if ( V_28 == V_29 ) {
F_40 ( V_39 , L_5 ) ;
F_40 ( V_39 , L_6
L_7 ) ;
if ( F_41 ( 0 ,
& V_72 , & V_79 , & V_77 , & V_73 ,
& V_74 , & V_75 , & V_76 , & V_78 ) )
F_19 () ;
for ( V_80 = 63 ; V_80 > 0 ; V_80 -- ) {
if ( ( ( T_1 ) V_79 << V_77 ) & ( 1ULL << V_80 ) )
break;
}
F_40 ( V_39 , L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15 ,
V_75 , F_42 () -> V_81 ,
V_72 ? L_16 : L_17 ,
( T_1 ) V_79 << V_77 , V_80 , V_77 ,
V_73 , V_74 , V_76 , V_78 ) ;
F_25 ( V_39 ) ;
}
if ( F_20 ( V_28 ) ) {
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_82 && V_28 -> V_83 [ V_48 ] ; V_48 ++ ) {
if ( V_28 -> V_83 [ V_48 ] == ' ' )
V_28 -> V_83 [ V_48 ] = '_' ;
}
V_33 = F_23 ( V_28 , V_29 , & V_30 ) ;
F_40 ( V_39 , L_18 , V_33 , V_30 , V_28 -> V_15 ,
V_28 -> V_84 ? L_19 : L_20 , V_28 -> V_83 ) ;
if ( V_30 < 0 || ( ! F_17 ( V_28 ) && ! F_18 ( V_28 ) ) )
F_43 ( V_39 , '\n' ) ;
else {
T_5 V_85 = - 1 ;
T_5 V_86 = - 1 ;
F_40 ( V_39 , L_21 , F_44 ( V_30 ) ) ;
if ( F_37 ( V_29 , V_9 ,
V_30 , & V_85 , & V_86 ) == 0 ) {
F_40 ( V_39 , L_22 ,
V_85 , V_86 ) ;
}
if ( ! F_18 ( V_28 ) ) {
F_45 (i) {
F_40 ( V_39 , V_48 ? L_23 : L_24 ,
F_46 ( V_30 , V_48 ) ) ;
}
}
F_43 ( V_39 , '\n' ) ;
if ( ! F_18 ( V_28 ) ) {
F_47 (i, cpu_online_mask,
cpumask_of_node(ordinal)) {
V_69 = 'a' + F_48 ( V_48 ) ;
V_58 = F_49 ( V_48 ) ;
F_40 ( V_39 , L_25
L_26 ,
V_48 , V_28 -> V_15 , V_69 ,
V_58 -> V_87 / 1000000 ) ;
F_50 (j) {
F_40 ( V_39 , V_57 ? L_23 : L_24 ,
F_46 (
F_51 ( V_48 ) ,
F_51 ( V_57 ) ) ) ;
}
F_43 ( V_39 , '\n' ) ;
}
}
}
if ( V_28 -> V_63 ) {
V_5 = V_28 -> V_63 * sizeof( struct V_55 ) ;
if ( ( V_56 = F_26 ( V_5 , V_41 ) ) == NULL )
return - V_10 ;
V_4 = F_5 ( V_11 ,
V_64 , V_28 -> V_47 , V_5 ,
( T_1 ) V_56 , 0 , 0 , NULL ) ;
if ( V_4 != V_13 )
return - V_14 ;
for ( V_30 = 0 , V_31 = V_29 ; V_31 != V_28 ; V_31 ++ ) {
if ( ! F_20 ( V_31 ) )
V_30 += V_31 -> V_63 ;
}
for ( V_68 = 0 ; V_68 < V_28 -> V_63 ; V_68 ++ ) {
for ( V_31 = V_29 , V_48 = 0 ; V_48 < V_9 ; V_48 ++ , V_31 ++ ) {
if ( V_56 [ V_68 ] . V_65 == V_31 -> V_47 ) {
break;
}
}
F_40 ( V_39 , L_27 ,
V_30 + V_68 , V_28 -> V_15 , V_56 [ V_68 ] . V_88 ) ;
if ( V_48 >= V_9 ) {
F_29 ( V_39 , L_28
L_29 ) ;
continue;
}
if ( V_28 -> V_84 && V_31 -> V_84 )
F_29 ( V_39 , L_30 ) ;
else if ( F_20 ( V_31 ) )
F_29 ( V_39 , L_31 ) ;
else
F_29 ( V_39 , L_32 ) ;
F_40 ( V_39 , L_33 ,
V_31 -> V_15 , V_56 [ V_68 ] . V_89 ,
( F_52 ( V_28 ) ||
F_52 ( V_31 ) ) ? L_34 : L_35 ) ;
}
F_30 ( V_56 ) ;
}
return 0 ;
}
static void * F_53 ( struct V_38 * V_39 , T_8 * V_90 )
{
struct V_2 * V_29 = V_39 -> V_71 ;
if ( * V_90 < V_9 )
return ( void * ) ( V_29 + * V_90 ) ;
return NULL ;
}
static void * F_54 ( struct V_38 * V_39 , void * V_91 , T_8 * V_90 )
{
++ * V_90 ;
return F_53 ( V_39 , V_90 ) ;
}
static void F_55 ( struct V_38 * V_92 , void * V_91 )
{
return;
}
static void F_56 ( void * V_93 )
{
struct V_94 * V_95 = V_93 ;
int V_96 ;
V_96 = F_5 ( V_11 , V_95 -> V_52 ,
V_95 -> V_97 -> V_98 , V_95 -> V_97 -> V_5 ,
( T_1 ) V_95 -> V_31 , 0 , 0 , V_95 -> V_99 ) ;
V_95 -> V_3 = V_96 ;
}
static int F_57 ( struct V_94 * V_95 )
{
T_9 V_100 ;
T_9 V_101 ;
int V_96 = 0 ;
T_10 V_102 ;
V_100 = ( V_95 -> V_97 -> V_98 & V_103 ) >> 32 ;
V_101 = V_95 -> V_97 -> V_98 & V_104 ;
V_95 -> V_97 -> V_98 &= V_105 ;
if ( V_100 != V_106 ) {
if ( V_100 >= V_107 || ! F_58 ( V_100 ) ) {
V_96 = - V_14 ;
goto V_8;
}
}
if ( V_100 == V_106 ) {
F_56 ( V_95 ) ;
} else if ( V_100 == F_59 () ) {
F_56 ( V_95 ) ;
F_60 () ;
} else {
F_60 () ;
if ( V_101 ) {
F_61 ( V_100 , F_56 ,
V_95 , 1 ) ;
}
else {
V_102 = V_108 -> V_109 ;
F_62 ( V_108 , F_63 ( V_100 ) ) ;
F_56 ( V_95 ) ;
F_62 ( V_108 , & V_102 ) ;
}
}
V_96 = V_95 -> V_3 ;
V_8:
return V_96 ;
}
static int F_64 ( int V_110 )
{
int V_4 ;
switch( V_110 ) {
case V_13 :
V_4 = 0 ;
break;
case V_111 :
V_4 = - V_10 ;
break;
case V_112 :
V_4 = - V_113 ;
break;
case V_114 :
V_4 = - V_115 ;
break;
case V_116 :
V_4 = - V_117 ;
break;
case V_118 :
V_4 = - V_119 ;
break;
case V_120 :
default:
V_4 = - V_14 ;
break;
}
return V_4 ;
}
static long F_65 ( struct V_121 * V_122 , T_9 V_52 , unsigned long V_98 )
{
struct V_123 V_97 ;
struct V_70 * V_124 ;
struct V_2 * V_29 ;
struct V_2 * V_125 ;
struct V_94 V_95 ;
void * V_31 = NULL ;
int V_1 ;
char V_69 ;
int V_44 ;
int V_96 ;
int V_99 ;
int V_48 ;
int V_57 ;
if ( ( V_52 & V_126 ) < 10 ) {
V_96 = - V_14 ;
goto error;
}
V_96 = F_66 ( & V_97 , ( const void V_127 * ) V_98 ,
sizeof( struct V_123 ) ) ;
if ( V_96 != 0 ) {
V_96 = - V_128 ;
goto error;
}
if ( V_97 . V_129 ) {
V_31 = F_4 ( V_97 . V_5 ) ;
if ( ! V_31 ) {
V_96 = - V_10 ;
goto error;
}
}
if ( V_52 & V_130 ) {
V_96 = F_66 ( V_31 , ( const void V_127 * ) V_97 . V_129 , V_97 . V_5 ) ;
if ( V_96 != 0 ) {
V_96 = - V_128 ;
goto error;
}
}
switch ( V_52 ) {
case V_131 :
if ( V_97 . V_5 == sizeof( T_1 ) ) {
* ( T_1 * ) V_31 = ( T_1 ) F_67 () *
sizeof( struct V_2 ) ;
} else
if ( V_97 . V_5 < F_67 () * sizeof( struct V_2 ) ) {
V_96 = - V_10 ;
goto error;
} else
if ( ( V_96 = F_1 ( & V_1 , & V_29 ) ) == 0 ) {
int V_132 = 0 ;
memset ( V_31 , 0 , V_97 . V_5 ) ;
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ ) {
if ( ! F_17 ( V_29 + V_48 ) )
continue;
V_44 = F_16 ( V_29 + V_48 ) ;
F_50 (j) {
if ( V_44 != F_51 ( V_57 ) )
continue;
V_125 = (struct V_2 * ) V_31 + V_132 ++ ;
V_69 = 'a' + F_48 ( V_57 ) ;
V_124 = F_49 ( V_57 ) ;
V_125 -> V_47 = V_57 ;
snprintf ( V_125 -> V_83 ,
sizeof( V_125 -> V_83 ) ,
L_36 ,
V_124 -> V_87 / 1000000 ,
V_124 -> V_133 ) ;
snprintf ( V_125 -> V_15 ,
sizeof( V_125 -> V_15 ) ,
L_37 , V_29 [ V_48 ] . V_15 ,
V_69 ) ;
}
}
F_6 ( V_29 ) ;
}
break;
case V_134 :
if ( V_97 . V_5 != sizeof( T_1 ) ||
( V_44 = V_97 . V_98 ) < 0 || ! F_15 ( V_44 ) ) {
V_96 = - V_14 ;
goto error;
}
* ( T_1 * ) V_31 = ( T_1 ) F_44 ( V_44 ) ;
break;
case V_135 :
V_48 = V_97 . V_98 ;
if ( V_97 . V_5 != sizeof( T_1 ) || V_48 < 0 ) {
V_96 = - V_14 ;
goto error;
}
if ( ( V_96 = F_1 ( & V_1 , & V_29 ) ) == 0 ) {
if ( V_48 >= V_1 ) {
V_96 = - V_14 ;
F_6 ( V_29 ) ;
goto error;
}
if ( V_29 [ V_48 ] . V_47 != V_97 . V_98 ) {
for ( V_48 = 0 ; V_48 < V_1 ; V_48 ++ ) {
if ( V_29 [ V_48 ] . V_47 == V_97 . V_98 )
break;
}
}
if ( V_48 == V_1 ) {
V_96 = - V_14 ;
F_6 ( V_29 ) ;
goto error;
}
if ( ! F_17 ( V_29 + V_48 ) &&
! F_18 ( V_29 + V_48 ) ) {
V_96 = - V_61 ;
F_6 ( V_29 ) ;
goto error;
}
* ( T_1 * ) V_31 = ( T_1 ) F_16 ( V_29 + V_48 ) ;
F_6 ( V_29 ) ;
}
break;
case V_136 :
case V_137 :
case V_138 :
V_95 . V_31 = V_31 ;
V_95 . V_97 = & V_97 ;
V_95 . V_99 = & V_99 ;
V_95 . V_52 = V_52 ;
V_96 = F_57 ( & V_95 ) ;
if ( V_96 ) {
V_96 = F_64 ( V_96 ) ;
V_97 . V_99 = V_99 ;
goto error;
}
break;
default:
V_96 = F_5 ( V_11 , V_52 ,
V_97 . V_98 , V_97 . V_5 , ( T_1 ) V_31 , 0 , 0 , & V_99 ) ;
if ( V_96 ) {
V_96 = F_64 ( V_96 ) ;
goto error;
}
V_97 . V_99 = V_99 ;
break;
}
if ( V_52 & V_139 ) {
V_96 = F_68 ( ( void V_127 * ) V_97 . V_129 , V_31 , V_97 . V_5 ) ;
if ( V_96 != 0 ) {
V_96 = - V_128 ;
goto error;
}
}
error:
F_6 ( V_31 ) ;
return V_96 ;
}
static int F_2 ( void )
{
T_1 V_91 ;
int V_140 ;
int V_4 = 0 ;
F_69 ( & V_141 ) ;
if ( V_142 ) {
F_70 ( & V_141 ) ;
return V_4 ;
}
V_11 = ( V_143 ) F_71 () ;
V_140 = F_5 ( V_11 ,
( T_1 ) V_144 , 0 ,
( T_1 ) sizeof( T_1 ) , ( T_1 ) & V_91 , 0 , 0 , NULL ) ;
if ( V_140 != V_13 ) {
V_4 = - V_14 ;
goto V_8;
}
if ( ( V_142 = F_4 ( V_91 ) ) == NULL ) {
V_4 = - V_10 ;
goto V_8;
}
V_140 = F_5 ( V_11 ,
V_145 , 0 , V_91 ,
( T_1 ) V_142 , 0 , 0 , NULL ) ;
if ( V_140 != V_13 ) {
V_4 = - V_14 ;
goto V_8;
}
V_140 = F_5 ( V_11 ,
V_146 , 0 ,
sizeof( T_1 ) , ( T_1 ) & V_91 , 0 , 0 , NULL ) ;
if ( V_140 != V_13 ) {
V_4 = - V_14 ;
goto V_8;
}
V_9 = ( int ) V_91 ;
V_8:
if ( V_4 < 0 && V_142 ) {
F_6 ( V_142 ) ;
V_142 = NULL ;
V_9 = 0 ;
}
F_70 ( & V_141 ) ;
return V_4 ;
}
int F_72 ( struct V_147 * V_147 , struct V_121 * V_121 )
{
int V_4 ;
struct V_38 * V_148 ;
struct V_2 * V_6 ;
int V_1 ;
if ( ( V_4 = F_1 ( & V_1 , & V_6 ) ) == 0 ) {
V_4 = F_73 ( V_121 , & V_149 ) ;
V_148 = V_121 -> V_150 ;
V_148 -> V_71 = V_6 ;
}
return V_4 ;
}
int F_74 ( struct V_147 * V_147 , struct V_121 * V_121 )
{
struct V_38 * V_148 = V_121 -> V_150 ;
F_6 ( V_148 -> V_71 ) ;
return F_75 ( V_147 , V_121 ) ;
}
int F_76 ( T_5 V_44 ,
T_5 * V_49 , T_5 * V_50 )
{
int V_4 ;
int V_1 ;
struct V_2 * V_6 ;
if ( ( V_4 = F_1 ( & V_1 , & V_6 ) ) == 0 ) {
V_4 = F_37 ( V_6 , V_1 ,
V_44 , V_49 , V_50 ) ;
F_6 ( V_6 ) ;
}
return V_4 ;
}
static int T_11 F_77 ( void )
{
int V_4 ;
if ( ! F_78 ( L_38 ) )
return 0 ;
F_2 () ;
if ( ( V_4 = F_79 ( & V_151 ) ) != 0 ) {
F_3 ( V_7 L_39
L_40 , V_151 . V_83 ) ;
}
return V_4 ;
}
