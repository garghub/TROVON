static T_1 F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return F_2 ( V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_6 , void * V_7 )
{
return F_4 ( V_2 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_6 , void * V_7 )
{
return F_6 ( V_2 , V_6 ) ;
}
static T_1 * F_7 ( struct V_8 * V_9 , int V_10 )
{
T_1 * V_6 ;
V_6 = F_8 ( V_9 , V_10 ) ;
if ( F_9 ( V_6 == NULL ) )
F_10 ( V_11 L_1 ) ;
return V_6 ;
}
static T_1 F_11 ( struct V_8 * V_9 , unsigned int * V_12 , const char * * V_13 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_12 = F_12 ( * V_6 ) ;
if ( * V_12 != 0 ) {
V_6 = F_7 ( V_9 , * V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_13 = ( const char * ) V_6 ;
} else
* V_13 = NULL ;
return 0 ;
}
static T_1 F_13 ( struct V_8 * V_9 , struct V_15 * V_16 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
V_16 -> V_17 = F_12 ( * V_6 ) ;
if ( V_16 -> V_17 > V_18 )
return F_2 ( V_19 ) ;
V_6 = F_7 ( V_9 , V_16 -> V_17 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( & V_16 -> V_20 [ 0 ] , V_6 , V_16 -> V_17 ) ;
memset ( & V_16 -> V_20 [ V_16 -> V_17 ] , 0 , sizeof( V_16 -> V_20 ) - V_16 -> V_17 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_8 * V_9 , T_2 * V_21 )
{
T_1 * V_6 ;
unsigned int V_22 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
V_22 = F_12 ( * V_6 ) ;
V_6 = F_7 ( V_9 , V_22 << 2 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
if ( F_15 ( V_22 > 0 ) )
V_21 [ 0 ] = F_12 ( * V_6 ++ ) ;
if ( V_22 > 1 )
V_21 [ 1 ] = F_12 ( * V_6 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_8 * V_9 , T_3 * V_23 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_24 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_23 , V_6 , V_24 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_8 * V_9 , struct V_25 * V_26 )
{
T_1 * V_6 ;
T_1 V_27 ;
V_27 = F_11 ( V_9 , & V_26 -> V_28 , & V_26 -> V_29 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
if ( V_26 -> V_28 > V_30 - 12 ) {
F_10 ( L_2 ,
V_31 , V_26 -> V_28 ) ;
return F_2 ( V_14 ) ;
}
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
V_26 -> V_32 = F_12 ( * V_6 ++ ) ;
if ( V_26 -> V_32 <= V_33 ) {
V_26 -> V_34 = F_12 ( * V_6 ++ ) ;
} else {
F_18 ( L_3
L_4 ,
V_31 , V_26 -> V_32 ) ;
return F_2 ( V_35 ) ;
}
V_26 -> V_36 = F_12 ( * V_6 ) ;
F_19 ( L_5 , V_31 ,
V_26 -> V_32 , V_26 -> V_36 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_8 * V_9 , unsigned int * V_37 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_38 ) ;
* V_37 = F_12 ( * V_6 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_39 * args )
{
T_1 V_27 ;
V_27 = F_13 ( V_9 , & args -> V_16 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
args -> V_41 = F_22 ( V_2 ) ;
V_27 = F_14 ( V_9 , args -> V_21 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_42 * args )
{
T_1 * V_6 ;
T_1 V_27 ;
args -> V_41 = F_22 ( V_2 ) ;
V_27 = F_16 ( V_9 , & args -> V_23 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_14 ) ;
goto V_40;
}
args -> V_43 = F_12 ( * V_6 ) ;
V_27 = F_13 ( V_9 , & args -> V_16 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_44 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_2 V_45 ;
args -> V_46 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
args -> V_48 = F_12 ( * V_6 ++ ) ;
V_45 = F_12 ( * V_6 ++ ) ;
args -> V_49 = F_12 ( * V_6 ++ ) ;
args -> V_50 = F_12 ( * V_6 ++ ) ;
if ( args -> V_50 == V_51 ) {
args -> V_52 . V_45 = V_45 ;
V_27 = F_13 ( V_9 , & args -> V_53 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_6 = F_7 ( V_9 , 2 * sizeof( V_54 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
V_6 = F_25 ( V_6 , & args -> V_52 . V_55 ) ;
V_6 = F_25 ( V_6 , & args -> V_52 . V_56 ) ;
V_27 = F_16 ( V_9 , & args -> V_57 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
} else if ( args -> V_50 == V_58 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_54 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
V_6 = F_25 ( V_6 , & args -> V_59 . V_60 ) ;
V_6 = F_25 ( V_6 , & args -> V_59 . V_61 ) ;
} else if ( args -> V_50 != V_62 ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
F_19 ( L_7 ,
V_31 ,
args -> V_48 , V_45 ,
args -> V_49 , args -> V_50 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static
T_1 F_26 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_63 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_4 V_64 ;
int V_65 , V_66 ;
args -> V_67 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
V_65 = F_12 ( * V_6 ++ ) ;
if ( V_65 <= 0 )
goto V_40;
if ( V_65 > V_68 / sizeof( * args -> V_69 ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_40;
}
args -> V_69 = F_27 ( V_65 , sizeof( * args -> V_69 ) , V_70 ) ;
if ( ! args -> V_69 ) {
V_27 = F_2 ( V_71 ) ;
goto V_40;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
struct V_72 * V_73 = & args -> V_69 [ V_66 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_2 ) ) + V_74 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_75;
}
V_64 = F_12 ( * V_6 ++ ) ;
if ( V_64 != 1 ) {
V_27 = F_2 ( V_76 ) ;
goto V_75;
}
V_73 -> V_77 = F_12 ( * V_6 ++ ) ;
if ( V_73 -> V_77 != V_78 &&
V_73 -> V_77 != V_79 ) {
V_27 = F_2 ( V_76 ) ;
goto V_75;
}
V_64 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_73 -> V_77 == V_78 ) &&
( V_64 != V_74 + 8 ) ) ||
( ( V_73 -> V_77 == V_79 ) &&
( V_64 != V_74 + 4 ) ) ) {
V_27 = F_2 ( V_76 ) ;
goto V_75;
}
V_73 -> V_80 = F_12 ( * V_6 ++ ) ;
memcpy ( V_73 -> V_81 . V_20 , V_6 , V_74 ) ;
V_6 += F_28 ( V_74 ) ;
if ( V_73 -> V_80 == V_78 ) {
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_47 ) ;
goto V_75;
}
V_73 -> V_82 = F_12 ( * V_6 ++ ) ;
} else {
V_73 -> V_82 = 0 ;
}
args -> V_67 ++ ;
F_19 ( L_8 ,
V_31 , V_73 -> V_77 , V_73 -> V_80 ,
V_73 -> V_82 ) ;
}
V_40:
F_19 ( L_9 ,
V_31 , F_12 ( V_27 ) , args -> V_67 ) ;
return V_27 ;
V_75:
F_29 ( args -> V_69 ) ;
goto V_40;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_83 * V_84 )
{
T_1 * V_6 ;
int V_12 = V_85 ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_84 -> V_20 , V_6 , V_12 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_8 * V_9 ,
struct V_86 * V_87 )
{
T_1 * V_6 ;
int V_66 ;
T_1 V_27 ;
V_27 = F_30 ( V_9 , & V_87 -> V_88 ) ;
if ( V_27 )
goto V_40;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
V_87 -> V_89 = F_12 ( * V_6 ++ ) ;
if ( V_87 -> V_89 ) {
V_6 = F_7 ( V_9 ,
V_87 -> V_89 * 2 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
V_87 -> V_90 = F_27 ( V_87 -> V_89 ,
sizeof( * V_87 -> V_90 ) ,
V_70 ) ;
if ( F_9 ( V_87 -> V_90 == NULL ) )
goto V_40;
for ( V_66 = 0 ; V_66 < V_87 -> V_89 ; V_66 ++ ) {
V_87 -> V_90 [ V_66 ] . V_91 = F_12 ( * V_6 ++ ) ;
V_87 -> V_90 [ V_66 ] . V_92 = F_12 ( * V_6 ++ ) ;
}
}
V_27 = 0 ;
V_40:
return V_27 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_93 * args )
{
T_1 * V_6 ;
int V_66 ;
T_1 V_27 ;
V_27 = F_30 ( V_9 , & args -> V_94 ) ;
if ( V_27 )
goto V_40;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
args -> V_95 = F_22 ( V_2 ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = F_12 ( * V_6 ++ ) ;
args -> V_99 = F_12 ( * V_6 ++ ) ;
args -> V_100 = F_12 ( * V_6 ++ ) ;
args -> V_101 = NULL ;
if ( args -> V_100 ) {
args -> V_101 = F_27 ( args -> V_100 ,
sizeof( * args -> V_101 ) ,
V_70 ) ;
if ( F_9 ( args -> V_101 == NULL ) )
goto V_40;
for ( V_66 = 0 ; V_66 < args -> V_100 ; V_66 ++ ) {
V_27 = F_31 ( V_9 , & args -> V_101 [ V_66 ] ) ;
if ( V_27 ) {
args -> V_100 = V_66 ;
goto V_102;
}
}
}
V_27 = 0 ;
F_19 ( L_10
L_11 ,
V_31 ,
( ( T_4 * ) & args -> V_94 ) [ 0 ] ,
( ( T_4 * ) & args -> V_94 ) [ 1 ] ,
( ( T_4 * ) & args -> V_94 ) [ 2 ] ,
( ( T_4 * ) & args -> V_94 ) [ 3 ] ,
args -> V_96 , args -> V_97 ,
args -> V_98 , args -> V_99 ,
args -> V_100 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
V_102:
for ( V_66 = 0 ; V_66 < args -> V_100 ; V_66 ++ )
F_29 ( args -> V_101 [ V_66 ] . V_90 ) ;
F_29 ( args -> V_101 ) ;
goto V_40;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_103 * args )
{
T_2 V_21 [ 2 ] ;
T_1 * V_6 , V_27 ;
args -> V_104 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
args -> V_105 = F_12 ( * V_6 ++ ) ;
V_27 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
args -> V_106 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_107 * args )
{
T_1 * V_6 ;
args -> V_108 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
args -> V_109 = F_12 ( * V_6 ++ ) ;
return 0 ;
}
static T_1 F_35 ( struct V_8 * V_9 , unsigned int V_12 , const char * V_13 )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , 4 + V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
F_37 ( V_6 , V_13 , V_12 ) ;
return 0 ;
}
static T_1 F_38 ( struct V_8 * V_9 , const T_2 * V_21 , T_1 * * V_110 )
{
T_1 V_111 [ 2 ] ;
T_1 * V_6 ;
V_111 [ 0 ] = F_2 ( V_21 [ 0 ] & V_112 ) ;
V_111 [ 1 ] = F_2 ( V_21 [ 1 ] & V_113 ) ;
if ( V_111 [ 1 ] != 0 ) {
V_6 = F_36 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_111 [ 0 ] ;
* V_6 ++ = V_111 [ 1 ] ;
} else if ( V_111 [ 0 ] != 0 ) {
V_6 = F_36 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_111 [ 0 ] ;
} else {
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_110 = V_6 ;
return 0 ;
}
static T_1 F_39 ( struct V_8 * V_9 , const T_2 * V_21 , V_54 V_114 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_115 ) )
return 0 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , V_114 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_8 * V_9 , const T_2 * V_21 , V_54 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_116 ) )
return 0 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_8 * V_9 , const struct V_117 * time )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , time -> V_118 ) ;
* V_6 = F_2 ( time -> V_119 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_117 * time )
{
if ( ! ( V_21 [ 1 ] & V_120 ) )
return 0 ;
return F_42 ( V_9 , time ) ;
}
static T_1 F_44 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_117 * time )
{
if ( ! ( V_21 [ 1 ] & V_121 ) )
return 0 ;
return F_42 ( V_9 , time ) ;
}
static T_1 F_45 ( struct V_8 * V_9 , struct V_122 * V_26 )
{
T_1 V_27 ;
V_26 -> V_27 = F_36 ( V_9 , 4 ) ;
if ( F_9 ( V_26 -> V_27 == NULL ) )
return F_2 ( V_14 ) ;
V_27 = F_35 ( V_9 , V_26 -> V_28 , V_26 -> V_29 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_26 -> V_36 = F_36 ( V_9 , 4 ) ;
if ( F_9 ( V_26 -> V_36 == NULL ) )
return F_2 ( V_14 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_8 * V_9 , T_2 V_37 , T_1 V_123 )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_38 ) ;
* V_6 ++ = F_2 ( V_37 ) ;
* V_6 = V_123 ;
return 0 ;
}
static T_1 F_47 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_124 * V_123 )
{
T_1 * V_110 = NULL ;
T_1 V_27 = V_123 -> V_27 ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_38 ( V_9 , V_123 -> V_21 , & V_110 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_39 ( V_9 , V_123 -> V_21 , V_123 -> V_125 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_41 ( V_9 , V_123 -> V_21 , V_123 -> V_17 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_43 ( V_9 , V_123 -> V_21 , & V_123 -> ctime ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_44 ( V_9 , V_123 -> V_21 , & V_123 -> V_126 ) ;
* V_110 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_110 + 1 ) ) ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_48 ( struct V_8 * V_9 ,
const struct V_83 * V_84 )
{
T_1 * V_6 ;
int V_12 = V_85 ;
V_6 = F_36 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_84 , V_12 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_127 * V_123 )
{
T_1 * V_6 ;
T_1 V_27 = V_123 -> V_128 ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
F_48 ( V_9 , & V_123 -> V_129 ) ;
V_6 = F_36 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_123 -> V_130 ) ;
* V_6 ++ = F_2 ( V_123 -> V_131 ) ;
* V_6 ++ = F_2 ( V_123 -> V_132 ) ;
* V_6 ++ = F_2 ( V_123 -> V_133 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1
F_50 ( int V_134 , unsigned int V_135 , struct V_136 * * V_37 )
{
if ( V_135 == V_137 ) {
if ( V_134 != 0 )
return F_2 ( V_138 ) ;
} else {
if ( V_134 == 0 )
return F_2 ( V_139 ) ;
}
switch ( V_135 ) {
case V_140 :
case V_141 :
case V_137 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
* V_37 = & V_146 [ V_135 ] ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
return F_2 ( V_152 ) ;
default:
return F_2 ( V_153 ) ;
}
return F_2 ( V_154 ) ;
}
static void F_51 ( struct V_155 * V_156 )
{
struct V_157 * V_158 = & V_156 -> V_159 ;
F_52 ( & V_158 -> V_160 ) ;
V_158 -> V_161 = V_162 ;
F_53 ( V_158 ) ;
F_54 ( & V_158 -> V_160 ) ;
}
static void F_55 ( struct V_163 * V_164 )
{
if ( V_164 -> V_165 != V_162 )
F_51 ( V_164 -> V_166 -> V_167 ) ;
}
static T_1
F_50 ( int V_134 , unsigned int V_135 , struct V_136 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static void F_55 ( struct V_163 * V_164 )
{
}
static T_1
F_56 ( int V_134 , unsigned int V_135 , struct V_136 * * V_37 )
{
T_1 V_27 = F_50 ( V_134 , V_135 , V_37 ) ;
if ( V_27 != F_2 ( V_153 ) )
return V_27 ;
if ( V_135 == V_168 )
return F_2 ( V_152 ) ;
return F_2 ( V_153 ) ;
}
static T_1
F_56 ( int V_134 , unsigned int V_135 , struct V_136 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static T_1
F_57 ( unsigned int V_135 , struct V_136 * * V_37 )
{
switch ( V_135 ) {
case V_140 :
case V_141 :
* V_37 = & V_146 [ V_135 ] ;
break;
default:
return F_2 ( V_153 ) ;
}
return F_2 ( V_154 ) ;
}
static T_1 F_58 ( int V_134 , struct V_1 * V_2 ,
struct V_8 * V_169 , void * V_3 ,
struct V_8 * V_170 , void * V_4 ,
struct V_163 * V_164 )
{
struct V_136 * V_37 = & V_146 [ 0 ] ;
unsigned int V_135 ;
T_1 V_27 ;
long V_171 ;
T_1 V_123 ;
F_19 ( L_12 , V_31 ) ;
V_27 = F_20 ( V_169 , & V_135 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
F_19 ( L_13 ,
V_31 , V_164 -> V_32 , V_134 , V_135 ) ;
switch ( V_164 -> V_32 ) {
case 0 :
V_27 = F_57 ( V_135 , & V_37 ) ;
break;
case 1 :
V_27 = F_50 ( V_134 , V_135 , & V_37 ) ;
break;
case 2 :
V_27 = F_56 ( V_134 , V_135 , & V_37 ) ;
break;
default:
V_27 = F_2 ( V_35 ) ;
}
if ( V_27 == F_2 ( V_153 ) )
V_135 = V_172 ;
if ( V_27 )
goto V_173;
if ( V_164 -> V_174 ) {
V_27 = V_164 -> V_174 ;
goto V_173;
}
V_171 = V_170 -> V_175 - V_170 -> V_6 ;
if ( V_171 > 0 && V_171 < V_176 ) {
V_27 = V_37 -> V_177 ( V_2 , V_169 , V_3 ) ;
if ( F_15 ( V_27 == 0 ) )
V_27 = V_37 -> F_58 ( V_3 , V_4 , V_164 ) ;
} else
V_27 = F_2 ( V_14 ) ;
V_173:
V_123 = F_46 ( V_170 , V_135 , V_27 ) ;
if ( F_9 ( V_123 ) )
return V_123 ;
if ( V_37 -> V_178 != NULL && V_27 == 0 )
V_27 = V_37 -> V_178 ( V_2 , V_170 , V_4 ) ;
F_19 ( L_14 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_59 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_25 V_179 = { 0 } ;
struct V_122 V_180 = { NULL } ;
struct V_8 V_169 , V_170 ;
T_1 * V_6 , V_27 ;
struct V_163 V_164 = {
. V_174 = 0 ,
. V_166 = NULL ,
. V_165 = V_162 ,
. V_181 = F_60 ( V_2 ) ,
} ;
unsigned int V_36 = 0 ;
F_19 ( L_12 , V_31 ) ;
F_61 ( & V_169 , & V_2 -> V_182 , V_2 -> V_182 . V_183 [ 0 ] . V_184 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_185 . V_183 [ 0 ] . V_184 + V_2 -> V_185 . V_183 [ 0 ] . V_186 ) ;
F_62 ( & V_170 , & V_2 -> V_185 , V_6 ) ;
V_27 = F_17 ( & V_169 , & V_179 ) ;
if ( V_27 == F_2 ( V_14 ) )
return V_187 ;
if ( V_179 . V_32 == 0 ) {
V_164 . V_166 = F_63 ( F_60 ( V_2 ) , V_179 . V_34 ) ;
if ( ! V_164 . V_166 || ! F_64 ( V_164 . V_166 , V_2 ) )
return V_188 ;
}
V_164 . V_32 = V_179 . V_32 ;
V_180 . V_28 = V_179 . V_28 ;
V_180 . V_29 = V_179 . V_29 ;
if ( F_45 ( & V_170 , & V_180 ) != 0 )
return V_189 ;
while ( V_27 == 0 && V_36 != V_179 . V_36 ) {
V_27 = F_58 ( V_36 , V_2 , & V_169 ,
V_3 , & V_170 , V_4 , & V_164 ) ;
V_36 ++ ;
}
if ( F_9 ( V_27 == F_2 ( V_38 ) ) ) {
V_27 = F_2 ( V_14 ) ;
V_36 -- ;
}
* V_180 . V_27 = V_27 ;
* V_180 . V_36 = F_2 ( V_36 ) ;
F_55 ( & V_164 ) ;
F_65 ( V_164 . V_166 ) ;
F_19 ( L_15 , V_31 , F_12 ( V_27 ) ) ;
return V_190 ;
}
