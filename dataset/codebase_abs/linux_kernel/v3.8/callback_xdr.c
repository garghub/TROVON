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
if ( V_26 -> V_32 <= 1 ) {
V_26 -> V_33 = F_12 ( * V_6 ++ ) ;
} else {
F_18 ( L_3
L_4 ,
V_31 , V_26 -> V_32 ) ;
return F_2 ( V_34 ) ;
}
V_26 -> V_35 = F_12 ( * V_6 ) ;
F_19 ( L_5 , V_31 ,
V_26 -> V_32 , V_26 -> V_35 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_8 * V_9 , unsigned int * V_36 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_37 ) ;
* V_36 = F_12 ( * V_6 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_38 * args )
{
T_1 V_27 ;
V_27 = F_13 ( V_9 , & args -> V_16 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
args -> V_40 = F_22 ( V_2 ) ;
V_27 = F_14 ( V_9 , args -> V_21 ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_41 * args )
{
T_1 * V_6 ;
T_1 V_27 ;
args -> V_40 = F_22 ( V_2 ) ;
V_27 = F_16 ( V_9 , & args -> V_23 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_14 ) ;
goto V_39;
}
args -> V_42 = F_12 ( * V_6 ) ;
V_27 = F_13 ( V_9 , & args -> V_16 ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_43 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_2 V_44 ;
args -> V_45 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
args -> V_47 = F_12 ( * V_6 ++ ) ;
V_44 = F_12 ( * V_6 ++ ) ;
args -> V_48 = F_12 ( * V_6 ++ ) ;
args -> V_49 = F_12 ( * V_6 ++ ) ;
if ( args -> V_49 == V_50 ) {
args -> V_51 . V_44 = V_44 ;
V_27 = F_13 ( V_9 , & args -> V_52 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_6 = F_7 ( V_9 , 2 * sizeof( V_53 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
V_6 = F_25 ( V_6 , & args -> V_51 . V_54 ) ;
V_6 = F_25 ( V_6 , & args -> V_51 . V_55 ) ;
V_27 = F_16 ( V_9 , & args -> V_56 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
} else if ( args -> V_49 == V_57 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_53 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
V_6 = F_25 ( V_6 , & args -> V_58 . V_59 ) ;
V_6 = F_25 ( V_6 , & args -> V_58 . V_60 ) ;
} else if ( args -> V_49 != V_61 ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
F_19 ( L_7 ,
V_31 ,
args -> V_47 , V_44 ,
args -> V_48 , args -> V_49 ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static
T_1 F_26 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_62 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_4 V_63 ;
int V_64 , V_65 ;
args -> V_66 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
V_64 = F_12 ( * V_6 ++ ) ;
if ( V_64 <= 0 )
goto V_39;
if ( V_64 > V_67 / sizeof( * args -> V_68 ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_39;
}
args -> V_68 = F_27 ( V_64 * sizeof( * args -> V_68 ) , V_69 ) ;
if ( ! args -> V_68 ) {
V_27 = F_2 ( V_70 ) ;
goto V_39;
}
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
struct V_71 * V_72 = & args -> V_68 [ V_65 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_2 ) ) + V_73 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_74;
}
V_63 = F_12 ( * V_6 ++ ) ;
if ( V_63 != 1 ) {
V_27 = F_2 ( V_75 ) ;
goto V_74;
}
V_72 -> V_76 = F_12 ( * V_6 ++ ) ;
if ( V_72 -> V_76 != V_77 &&
V_72 -> V_76 != V_78 ) {
V_27 = F_2 ( V_75 ) ;
goto V_74;
}
V_63 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_72 -> V_76 == V_77 ) &&
( V_63 != V_73 + 8 ) ) ||
( ( V_72 -> V_76 == V_78 ) &&
( V_63 != V_73 + 4 ) ) ) {
V_27 = F_2 ( V_75 ) ;
goto V_74;
}
V_72 -> V_79 = F_12 ( * V_6 ++ ) ;
memcpy ( V_72 -> V_80 . V_20 , V_6 , V_73 ) ;
V_6 += F_28 ( V_73 ) ;
if ( V_72 -> V_79 == V_77 ) {
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_74;
}
V_72 -> V_81 = F_12 ( * V_6 ++ ) ;
} else {
V_72 -> V_81 = 0 ;
}
args -> V_66 ++ ;
F_19 ( L_8 ,
V_31 , V_72 -> V_76 , V_72 -> V_79 ,
V_72 -> V_81 ) ;
}
V_39:
F_19 ( L_9 ,
V_31 , F_12 ( V_27 ) , args -> V_66 ) ;
return V_27 ;
V_74:
F_29 ( args -> V_68 ) ;
goto V_39;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_82 * V_83 )
{
T_1 * V_6 ;
int V_12 = V_84 ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_83 -> V_20 , V_6 , V_12 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_8 * V_9 ,
struct V_85 * V_86 )
{
T_1 * V_6 ;
int V_65 ;
T_1 V_27 ;
V_27 = F_30 ( V_9 , & V_86 -> V_87 ) ;
if ( V_27 )
goto V_39;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_39;
V_86 -> V_88 = F_12 ( * V_6 ++ ) ;
if ( V_86 -> V_88 ) {
V_6 = F_7 ( V_9 ,
V_86 -> V_88 * 2 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_39;
V_86 -> V_89 = F_27 ( V_86 -> V_88 *
sizeof( * V_86 -> V_89 ) ,
V_69 ) ;
if ( F_9 ( V_86 -> V_89 == NULL ) )
goto V_39;
for ( V_65 = 0 ; V_65 < V_86 -> V_88 ; V_65 ++ ) {
V_86 -> V_89 [ V_65 ] . V_90 = F_12 ( * V_6 ++ ) ;
V_86 -> V_89 [ V_65 ] . V_91 = F_12 ( * V_6 ++ ) ;
}
}
V_27 = 0 ;
V_39:
return V_27 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_92 * args )
{
T_1 * V_6 ;
int V_65 ;
T_1 V_27 ;
V_27 = F_30 ( V_9 , & args -> V_93 ) ;
if ( V_27 )
goto V_39;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_39;
args -> V_94 = F_22 ( V_2 ) ;
args -> V_95 = F_12 ( * V_6 ++ ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = F_12 ( * V_6 ++ ) ;
args -> V_99 = F_12 ( * V_6 ++ ) ;
args -> V_100 = NULL ;
if ( args -> V_99 ) {
args -> V_100 = F_33 ( args -> V_99 ,
sizeof( * args -> V_100 ) ,
V_69 ) ;
if ( F_9 ( args -> V_100 == NULL ) )
goto V_39;
for ( V_65 = 0 ; V_65 < args -> V_99 ; V_65 ++ ) {
V_27 = F_31 ( V_9 , & args -> V_100 [ V_65 ] ) ;
if ( V_27 )
goto V_101;
}
}
V_27 = 0 ;
F_19 ( L_10
L_11 ,
V_31 ,
( ( T_4 * ) & args -> V_93 ) [ 0 ] ,
( ( T_4 * ) & args -> V_93 ) [ 1 ] ,
( ( T_4 * ) & args -> V_93 ) [ 2 ] ,
( ( T_4 * ) & args -> V_93 ) [ 3 ] ,
args -> V_95 , args -> V_96 ,
args -> V_97 , args -> V_98 ,
args -> V_99 ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
V_101:
for ( V_65 = 0 ; V_65 < args -> V_99 ; V_65 ++ )
F_29 ( args -> V_100 [ V_65 ] . V_89 ) ;
F_29 ( args -> V_100 ) ;
goto V_39;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_102 * args )
{
T_2 V_21 [ 2 ] ;
T_1 * V_6 , V_27 ;
args -> V_103 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_46 ) ;
args -> V_104 = F_12 ( * V_6 ++ ) ;
V_27 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
args -> V_105 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_106 * args )
{
T_1 * V_6 ;
args -> V_107 = F_22 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_46 ) ;
args -> V_108 = F_12 ( * V_6 ++ ) ;
return 0 ;
}
static T_1 F_36 ( struct V_8 * V_9 , unsigned int V_12 , const char * V_13 )
{
T_1 * V_6 ;
V_6 = F_37 ( V_9 , 4 + V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
F_38 ( V_6 , V_13 , V_12 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_8 * V_9 , const T_2 * V_21 , T_1 * * V_109 )
{
T_1 V_110 [ 2 ] ;
T_1 * V_6 ;
V_110 [ 0 ] = F_2 ( V_21 [ 0 ] & V_111 ) ;
V_110 [ 1 ] = F_2 ( V_21 [ 1 ] & V_112 ) ;
if ( V_110 [ 1 ] != 0 ) {
V_6 = F_37 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_110 [ 0 ] ;
* V_6 ++ = V_110 [ 1 ] ;
} else if ( V_110 [ 0 ] != 0 ) {
V_6 = F_37 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_110 [ 0 ] ;
} else {
V_6 = F_37 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_109 = V_6 ;
return 0 ;
}
static T_1 F_40 ( struct V_8 * V_9 , const T_2 * V_21 , V_53 V_113 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_114 ) )
return 0 ;
V_6 = F_37 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_41 ( V_6 , V_113 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_8 * V_9 , const T_2 * V_21 , V_53 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_115 ) )
return 0 ;
V_6 = F_37 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_41 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_8 * V_9 , const struct V_116 * time )
{
T_1 * V_6 ;
V_6 = F_37 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_41 ( V_6 , time -> V_117 ) ;
* V_6 = F_2 ( time -> V_118 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_116 * time )
{
if ( ! ( V_21 [ 1 ] & V_119 ) )
return 0 ;
return F_43 ( V_9 , time ) ;
}
static T_1 F_45 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_116 * time )
{
if ( ! ( V_21 [ 1 ] & V_120 ) )
return 0 ;
return F_43 ( V_9 , time ) ;
}
static T_1 F_46 ( struct V_8 * V_9 , struct V_121 * V_26 )
{
T_1 V_27 ;
V_26 -> V_27 = F_37 ( V_9 , 4 ) ;
if ( F_9 ( V_26 -> V_27 == NULL ) )
return F_2 ( V_14 ) ;
V_27 = F_36 ( V_9 , V_26 -> V_28 , V_26 -> V_29 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_26 -> V_35 = F_37 ( V_9 , 4 ) ;
if ( F_9 ( V_26 -> V_35 == NULL ) )
return F_2 ( V_14 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_8 * V_9 , T_2 V_36 , T_1 V_122 )
{
T_1 * V_6 ;
V_6 = F_37 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_37 ) ;
* V_6 ++ = F_2 ( V_36 ) ;
* V_6 = V_122 ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_123 * V_122 )
{
T_1 * V_109 = NULL ;
T_1 V_27 = V_122 -> V_27 ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_27 = F_39 ( V_9 , V_122 -> V_21 , & V_109 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_27 = F_40 ( V_9 , V_122 -> V_21 , V_122 -> V_124 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_27 = F_42 ( V_9 , V_122 -> V_21 , V_122 -> V_17 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_27 = F_44 ( V_9 , V_122 -> V_21 , & V_122 -> ctime ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
V_27 = F_45 ( V_9 , V_122 -> V_21 , & V_122 -> V_125 ) ;
* V_109 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_109 + 1 ) ) ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_49 ( struct V_8 * V_9 ,
const struct V_82 * V_83 )
{
T_1 * V_6 ;
int V_12 = V_84 ;
V_6 = F_37 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_83 , V_12 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_126 * V_122 )
{
T_1 * V_6 ;
T_1 V_27 = V_122 -> V_127 ;
if ( F_9 ( V_27 != 0 ) )
goto V_39;
F_49 ( V_9 , & V_122 -> V_128 ) ;
V_6 = F_37 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_122 -> V_129 ) ;
* V_6 ++ = F_2 ( V_122 -> V_130 ) ;
* V_6 ++ = F_2 ( V_122 -> V_131 ) ;
* V_6 ++ = F_2 ( V_122 -> V_132 ) ;
V_39:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1
F_51 ( int V_133 , unsigned int V_134 , struct V_135 * * V_36 )
{
if ( V_134 == V_136 ) {
if ( V_133 != 0 )
return F_2 ( V_137 ) ;
} else {
if ( V_133 == 0 )
return F_2 ( V_138 ) ;
}
switch ( V_134 ) {
case V_139 :
case V_140 :
case V_136 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
* V_36 = & V_145 [ V_134 ] ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
return F_2 ( V_151 ) ;
default:
return F_2 ( V_152 ) ;
}
return F_2 ( V_153 ) ;
}
static void F_52 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = & V_155 -> V_158 ;
F_53 ( & V_157 -> V_159 ) ;
V_157 -> V_160 = V_161 ;
F_54 ( V_155 , V_157 ) ;
F_55 ( & V_157 -> V_159 ) ;
}
static void F_56 ( struct V_162 * V_163 )
{
if ( V_163 -> V_164 != V_161 )
F_52 ( V_163 -> V_165 -> V_166 ) ;
}
static T_1
F_51 ( int V_133 , unsigned int V_134 , struct V_135 * * V_36 )
{
return F_2 ( V_34 ) ;
}
static void F_56 ( struct V_162 * V_163 )
{
}
static T_1
F_57 ( unsigned int V_134 , struct V_135 * * V_36 )
{
switch ( V_134 ) {
case V_139 :
case V_140 :
* V_36 = & V_145 [ V_134 ] ;
break;
default:
return F_2 ( V_152 ) ;
}
return F_2 ( V_153 ) ;
}
static T_1 F_58 ( T_2 V_32 , int V_133 ,
struct V_1 * V_2 ,
struct V_8 * V_167 , void * V_3 ,
struct V_8 * V_168 , void * V_4 ,
struct V_162 * V_163 )
{
struct V_135 * V_36 = & V_145 [ 0 ] ;
unsigned int V_134 ;
T_1 V_27 ;
long V_169 ;
T_1 V_122 ;
F_19 ( L_12 , V_31 ) ;
V_27 = F_20 ( V_167 , & V_134 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
F_19 ( L_13 ,
V_31 , V_32 , V_133 , V_134 ) ;
V_27 = V_32 ? F_51 ( V_133 , V_134 , & V_36 ) :
F_57 ( V_134 , & V_36 ) ;
if ( V_27 == F_2 ( V_152 ) )
V_134 = V_170 ;
if ( V_27 )
goto V_171;
if ( V_163 -> V_172 ) {
V_27 = V_163 -> V_172 ;
goto V_171;
}
V_169 = V_168 -> V_173 - V_168 -> V_6 ;
if ( V_169 > 0 && V_169 < V_174 ) {
V_27 = V_36 -> V_175 ( V_2 , V_167 , V_3 ) ;
if ( F_15 ( V_27 == 0 ) )
V_27 = V_36 -> F_58 ( V_3 , V_4 , V_163 ) ;
} else
V_27 = F_2 ( V_14 ) ;
V_171:
V_122 = F_47 ( V_168 , V_134 , V_27 ) ;
if ( F_9 ( V_122 ) )
return V_122 ;
if ( V_36 -> V_176 != NULL && V_27 == 0 )
V_27 = V_36 -> V_176 ( V_2 , V_168 , V_4 ) ;
F_19 ( L_14 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_59 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_25 V_177 = { 0 } ;
struct V_121 V_178 = { NULL } ;
struct V_8 V_167 , V_168 ;
T_1 * V_6 , V_27 ;
struct V_162 V_163 = {
. V_172 = 0 ,
. V_165 = NULL ,
. V_164 = V_161 ,
. V_179 = F_60 ( V_2 ) ,
} ;
unsigned int V_35 = 0 ;
F_19 ( L_12 , V_31 ) ;
F_61 ( & V_167 , & V_2 -> V_180 , V_2 -> V_180 . V_181 [ 0 ] . V_182 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_183 . V_181 [ 0 ] . V_182 + V_2 -> V_183 . V_181 [ 0 ] . V_184 ) ;
F_62 ( & V_168 , & V_2 -> V_183 , V_6 ) ;
V_27 = F_17 ( & V_167 , & V_177 ) ;
if ( V_27 == F_63 ( V_14 ) )
return V_185 ;
if ( V_177 . V_32 == 0 ) {
V_163 . V_165 = F_64 ( F_60 ( V_2 ) , V_177 . V_33 ) ;
if ( ! V_163 . V_165 || ! F_65 ( V_163 . V_165 , V_2 ) )
return V_186 ;
}
V_178 . V_28 = V_177 . V_28 ;
V_178 . V_29 = V_177 . V_29 ;
if ( F_46 ( & V_168 , & V_178 ) != 0 )
return V_187 ;
while ( V_27 == 0 && V_35 != V_177 . V_35 ) {
V_27 = F_58 ( V_177 . V_32 , V_35 , V_2 ,
& V_167 , V_3 , & V_168 , V_4 , & V_163 ) ;
V_35 ++ ;
}
if ( F_9 ( V_27 == F_2 ( V_37 ) ) ) {
V_27 = F_2 ( V_14 ) ;
V_35 -- ;
}
* V_178 . V_27 = V_27 ;
* V_178 . V_35 = F_2 ( V_35 ) ;
F_56 ( & V_163 ) ;
F_66 ( V_163 . V_165 ) ;
F_19 ( L_15 , V_31 , F_12 ( V_27 ) ) ;
return V_188 ;
}
