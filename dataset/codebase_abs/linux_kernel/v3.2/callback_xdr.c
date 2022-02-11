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
V_6 = F_7 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_23 -> V_20 , V_6 , 16 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_8 * V_9 , struct V_24 * V_25 )
{
T_1 * V_6 ;
T_1 V_26 ;
V_26 = F_11 ( V_9 , & V_25 -> V_27 , & V_25 -> V_28 ) ;
if ( F_9 ( V_26 != 0 ) )
return V_26 ;
if ( V_25 -> V_27 > V_29 - 12 ) {
F_10 ( L_2 ,
V_30 , V_25 -> V_27 ) ;
return F_2 ( V_14 ) ;
}
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
V_25 -> V_31 = F_12 ( * V_6 ++ ) ;
if ( V_25 -> V_31 <= 1 ) {
V_25 -> V_32 = F_12 ( * V_6 ++ ) ;
} else {
F_10 ( V_11 L_3
L_4 ,
V_30 , V_25 -> V_31 ) ;
return F_2 ( V_33 ) ;
}
V_25 -> V_34 = F_12 ( * V_6 ) ;
F_18 ( L_5 , V_30 ,
V_25 -> V_31 , V_25 -> V_34 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_8 * V_9 , unsigned int * V_35 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_36 ) ;
* V_35 = F_12 ( * V_6 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_37 * args )
{
T_1 V_26 ;
V_26 = F_13 ( V_9 , & args -> V_16 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
args -> V_39 = F_21 ( V_2 ) ;
V_26 = F_14 ( V_9 , args -> V_21 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_40 * args )
{
T_1 * V_6 ;
T_1 V_26 ;
args -> V_39 = F_21 ( V_2 ) ;
V_26 = F_16 ( V_9 , & args -> V_23 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_14 ) ;
goto V_38;
}
args -> V_41 = F_12 ( * V_6 ) ;
V_26 = F_13 ( V_9 , & args -> V_16 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_42 * args )
{
T_1 * V_6 ;
T_1 V_26 = 0 ;
T_2 V_43 ;
args -> V_44 = F_21 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
args -> V_46 = F_12 ( * V_6 ++ ) ;
V_43 = F_12 ( * V_6 ++ ) ;
args -> V_47 = F_12 ( * V_6 ++ ) ;
args -> V_48 = F_12 ( * V_6 ++ ) ;
if ( args -> V_48 == V_49 ) {
args -> V_50 . V_43 = V_43 ;
V_26 = F_13 ( V_9 , & args -> V_51 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_6 = F_7 ( V_9 , 2 * sizeof( V_52 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
V_6 = F_24 ( V_6 , & args -> V_50 . V_53 ) ;
V_6 = F_24 ( V_6 , & args -> V_50 . V_54 ) ;
V_26 = F_16 ( V_9 , & args -> V_55 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
} else if ( args -> V_48 == V_56 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_52 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
V_6 = F_24 ( V_6 , & args -> V_57 . V_58 ) ;
V_6 = F_24 ( V_6 , & args -> V_57 . V_59 ) ;
} else if ( args -> V_48 != V_60 ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
F_18 ( L_7 ,
V_30 ,
args -> V_46 , V_43 ,
args -> V_47 , args -> V_48 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static
T_1 F_25 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_61 * args )
{
T_1 * V_6 ;
T_1 V_26 = 0 ;
T_4 V_62 ;
int V_63 , V_64 ;
args -> V_65 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
V_63 = F_12 ( * V_6 ++ ) ;
if ( V_63 <= 0 )
goto V_38;
args -> V_66 = F_26 ( V_63 * sizeof( * args -> V_66 ) , V_67 ) ;
if ( ! args -> V_66 ) {
V_26 = F_2 ( V_68 ) ;
goto V_38;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
struct V_69 * V_70 = & args -> V_66 [ V_64 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_2 ) ) + V_71 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_72;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( V_62 != 1 ) {
V_26 = F_2 ( V_73 ) ;
goto V_72;
}
V_70 -> V_74 = F_12 ( * V_6 ++ ) ;
if ( V_70 -> V_74 != V_75 &&
V_70 -> V_74 != V_76 ) {
V_26 = F_2 ( V_73 ) ;
goto V_72;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_70 -> V_74 == V_75 ) &&
( V_62 != V_71 + 8 ) ) ||
( ( V_70 -> V_74 == V_76 ) &&
( V_62 != V_71 + 4 ) ) ) {
V_26 = F_2 ( V_73 ) ;
goto V_72;
}
V_70 -> V_77 = F_12 ( * V_6 ++ ) ;
memcpy ( V_70 -> V_78 . V_20 , V_6 , V_71 ) ;
V_6 += F_27 ( V_71 ) ;
if ( V_70 -> V_77 == V_75 ) {
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_72;
}
V_70 -> V_79 = F_12 ( * V_6 ++ ) ;
} else {
V_70 -> V_79 = 0 ;
}
args -> V_65 ++ ;
F_18 ( L_8 ,
V_30 , V_70 -> V_74 , V_70 -> V_77 ,
V_70 -> V_79 ) ;
}
V_38:
F_18 ( L_9 ,
V_30 , F_12 ( V_26 ) , args -> V_65 ) ;
return V_26 ;
V_72:
F_28 ( args -> V_66 ) ;
goto V_38;
}
static T_1 F_29 ( struct V_8 * V_9 ,
struct V_80 * V_81 )
{
T_1 * V_6 ;
int V_12 = V_82 ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_81 -> V_20 , V_6 , V_12 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_83 * V_84 )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_26 ;
V_26 = F_29 ( V_9 , & V_84 -> V_85 ) ;
if ( V_26 )
goto V_38;
V_26 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
V_84 -> V_86 = F_12 ( * V_6 ++ ) ;
if ( V_84 -> V_86 ) {
V_6 = F_7 ( V_9 ,
V_84 -> V_86 * 2 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
V_84 -> V_87 = F_26 ( V_84 -> V_86 *
sizeof( * V_84 -> V_87 ) ,
V_67 ) ;
if ( F_9 ( V_84 -> V_87 == NULL ) )
goto V_38;
for ( V_64 = 0 ; V_64 < V_84 -> V_86 ; V_64 ++ ) {
V_84 -> V_87 [ V_64 ] . V_88 = F_12 ( * V_6 ++ ) ;
V_84 -> V_87 [ V_64 ] . V_89 = F_12 ( * V_6 ++ ) ;
}
}
V_26 = 0 ;
V_38:
return V_26 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_90 * args )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_26 ;
V_26 = F_29 ( V_9 , & args -> V_91 ) ;
if ( V_26 )
goto V_38;
V_26 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
args -> V_92 = F_21 ( V_2 ) ;
args -> V_93 = F_12 ( * V_6 ++ ) ;
args -> V_94 = F_12 ( * V_6 ++ ) ;
args -> V_95 = F_12 ( * V_6 ++ ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = NULL ;
if ( args -> V_97 ) {
args -> V_98 = F_26 ( args -> V_97 *
sizeof( * args -> V_98 ) ,
V_67 ) ;
if ( F_9 ( args -> V_98 == NULL ) )
goto V_38;
for ( V_64 = 0 ; V_64 < args -> V_97 ; V_64 ++ ) {
V_26 = F_30 ( V_9 , & args -> V_98 [ V_64 ] ) ;
if ( V_26 )
goto V_99;
}
}
V_26 = 0 ;
F_18 ( L_10
L_11 ,
V_30 ,
( ( T_4 * ) & args -> V_91 ) [ 0 ] ,
( ( T_4 * ) & args -> V_91 ) [ 1 ] ,
( ( T_4 * ) & args -> V_91 ) [ 2 ] ,
( ( T_4 * ) & args -> V_91 ) [ 3 ] ,
args -> V_93 , args -> V_94 ,
args -> V_95 , args -> V_96 ,
args -> V_97 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
V_99:
for ( V_64 = 0 ; V_64 < args -> V_97 ; V_64 ++ )
F_28 ( args -> V_98 [ V_64 ] . V_87 ) ;
F_28 ( args -> V_98 ) ;
goto V_38;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_100 * args )
{
T_2 V_21 [ 2 ] ;
T_1 * V_6 , V_26 ;
args -> V_101 = F_21 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_102 = F_12 ( * V_6 ++ ) ;
V_26 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_26 ) )
return V_26 ;
args -> V_103 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_104 * args )
{
T_1 * V_6 ;
args -> V_105 = F_21 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_106 = F_12 ( * V_6 ++ ) ;
return 0 ;
}
static T_1 F_34 ( struct V_8 * V_9 , unsigned int V_12 , const char * V_13 )
{
T_1 * V_6 ;
V_6 = F_35 ( V_9 , 4 + V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
F_36 ( V_6 , V_13 , V_12 ) ;
return 0 ;
}
static T_1 F_37 ( struct V_8 * V_9 , const T_2 * V_21 , T_1 * * V_107 )
{
T_1 V_108 [ 2 ] ;
T_1 * V_6 ;
V_108 [ 0 ] = F_2 ( V_21 [ 0 ] & V_109 ) ;
V_108 [ 1 ] = F_2 ( V_21 [ 1 ] & V_110 ) ;
if ( V_108 [ 1 ] != 0 ) {
V_6 = F_35 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_108 [ 0 ] ;
* V_6 ++ = V_108 [ 1 ] ;
} else if ( V_108 [ 0 ] != 0 ) {
V_6 = F_35 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_108 [ 0 ] ;
} else {
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_107 = V_6 ;
return 0 ;
}
static T_1 F_38 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_111 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_112 ) )
return 0 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , V_111 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_113 ) )
return 0 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_8 * V_9 , const struct V_114 * time )
{
T_1 * V_6 ;
V_6 = F_35 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , time -> V_115 ) ;
* V_6 = F_2 ( time -> V_116 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_114 * time )
{
if ( ! ( V_21 [ 1 ] & V_117 ) )
return 0 ;
return F_41 ( V_9 , time ) ;
}
static T_1 F_43 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_114 * time )
{
if ( ! ( V_21 [ 1 ] & V_118 ) )
return 0 ;
return F_41 ( V_9 , time ) ;
}
static T_1 F_44 ( struct V_8 * V_9 , struct V_119 * V_25 )
{
T_1 V_26 ;
V_25 -> V_26 = F_35 ( V_9 , 4 ) ;
if ( F_9 ( V_25 -> V_26 == NULL ) )
return F_2 ( V_14 ) ;
V_26 = F_34 ( V_9 , V_25 -> V_27 , V_25 -> V_28 ) ;
if ( F_9 ( V_26 != 0 ) )
return V_26 ;
V_25 -> V_34 = F_35 ( V_9 , 4 ) ;
if ( F_9 ( V_25 -> V_34 == NULL ) )
return F_2 ( V_14 ) ;
return 0 ;
}
static T_1 F_45 ( struct V_8 * V_9 , T_2 V_35 , T_1 V_120 )
{
T_1 * V_6 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_36 ) ;
* V_6 ++ = F_2 ( V_35 ) ;
* V_6 = V_120 ;
return 0 ;
}
static T_1 F_46 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_121 * V_120 )
{
T_1 * V_107 = NULL ;
T_1 V_26 = V_120 -> V_26 ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_37 ( V_9 , V_120 -> V_21 , & V_107 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_38 ( V_9 , V_120 -> V_21 , V_120 -> V_122 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_40 ( V_9 , V_120 -> V_21 , V_120 -> V_17 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_42 ( V_9 , V_120 -> V_21 , & V_120 -> ctime ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_43 ( V_9 , V_120 -> V_21 , & V_120 -> V_123 ) ;
* V_107 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_107 + 1 ) ) ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_47 ( struct V_8 * V_9 ,
const struct V_80 * V_81 )
{
T_1 * V_6 ;
int V_12 = V_82 ;
V_6 = F_35 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_81 , V_12 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_124 * V_120 )
{
T_1 * V_6 ;
unsigned V_26 = V_120 -> V_125 ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
F_47 ( V_9 , & V_120 -> V_126 ) ;
V_6 = F_35 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_120 -> V_127 ) ;
* V_6 ++ = F_2 ( V_120 -> V_128 ) ;
* V_6 ++ = F_2 ( V_120 -> V_129 ) ;
* V_6 ++ = F_2 ( V_120 -> V_130 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1
F_49 ( int V_131 , unsigned int V_132 , struct V_133 * * V_35 )
{
if ( V_132 == V_134 ) {
if ( V_131 != 0 )
return F_2 ( V_135 ) ;
} else {
if ( V_131 == 0 )
return F_2 ( V_136 ) ;
}
switch ( V_132 ) {
case V_137 :
case V_138 :
case V_134 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
* V_35 = & V_143 [ V_132 ] ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
return F_2 ( V_149 ) ;
default:
return F_2 ( V_150 ) ;
}
return F_2 ( V_151 ) ;
}
static void F_50 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = & V_153 -> V_156 ;
F_51 ( & V_155 -> V_157 ) ;
V_155 -> V_158 = - 1 ;
F_52 ( V_153 ) ;
F_53 ( & V_155 -> V_157 ) ;
}
static void F_54 ( struct V_159 * V_160 )
{
if ( V_160 -> V_161 != - 1 )
F_50 ( V_160 -> V_162 -> V_163 ) ;
}
static T_1
F_49 ( int V_131 , unsigned int V_132 , struct V_133 * * V_35 )
{
return F_2 ( V_33 ) ;
}
static void F_54 ( struct V_159 * V_160 )
{
}
static T_1
F_55 ( unsigned int V_132 , struct V_133 * * V_35 )
{
switch ( V_132 ) {
case V_137 :
case V_138 :
* V_35 = & V_143 [ V_132 ] ;
break;
default:
return F_2 ( V_150 ) ;
}
return F_2 ( V_151 ) ;
}
static T_1 F_56 ( T_2 V_31 , int V_131 ,
struct V_1 * V_2 ,
struct V_8 * V_164 , void * V_3 ,
struct V_8 * V_165 , void * V_4 ,
struct V_159 * V_160 )
{
struct V_133 * V_35 = & V_143 [ 0 ] ;
unsigned int V_132 ;
T_1 V_26 ;
long V_166 ;
T_1 V_120 ;
F_18 ( L_12 , V_30 ) ;
V_26 = F_19 ( V_164 , & V_132 ) ;
if ( F_9 ( V_26 ) )
return V_26 ;
F_18 ( L_13 ,
V_30 , V_31 , V_131 , V_132 ) ;
V_26 = V_31 ? F_49 ( V_131 , V_132 , & V_35 ) :
F_55 ( V_132 , & V_35 ) ;
if ( V_26 == F_2 ( V_150 ) )
V_132 = V_167 ;
if ( V_26 )
goto V_168;
if ( V_160 -> V_169 ) {
V_26 = V_160 -> V_169 ;
goto V_168;
}
V_166 = V_165 -> V_170 - V_165 -> V_6 ;
if ( V_166 > 0 && V_166 < V_171 ) {
V_26 = V_35 -> V_172 ( V_2 , V_164 , V_3 ) ;
if ( F_15 ( V_26 == 0 ) )
V_26 = V_35 -> F_56 ( V_3 , V_4 , V_160 ) ;
} else
V_26 = F_2 ( V_14 ) ;
V_168:
V_120 = F_45 ( V_165 , V_132 , V_26 ) ;
if ( F_9 ( V_120 ) )
return V_120 ;
if ( V_35 -> V_173 != NULL && V_26 == 0 )
V_26 = V_35 -> V_173 ( V_2 , V_165 , V_4 ) ;
F_18 ( L_14 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_57 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_24 V_174 = { 0 } ;
struct V_119 V_175 = { NULL } ;
struct V_8 V_164 , V_165 ;
T_1 * V_6 , V_26 ;
struct V_159 V_160 = {
. V_169 = 0 ,
. V_162 = NULL ,
. V_161 = - 1 ,
} ;
unsigned int V_34 = 0 ;
F_18 ( L_12 , V_30 ) ;
F_58 ( & V_164 , & V_2 -> V_176 , V_2 -> V_176 . V_177 [ 0 ] . V_178 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_179 . V_177 [ 0 ] . V_178 + V_2 -> V_179 . V_177 [ 0 ] . V_180 ) ;
F_59 ( & V_165 , & V_2 -> V_179 , V_6 ) ;
V_26 = F_17 ( & V_164 , & V_174 ) ;
if ( V_26 == F_60 ( V_14 ) )
return V_181 ;
if ( V_174 . V_31 == 0 ) {
V_160 . V_162 = F_61 ( V_174 . V_32 ) ;
if ( ! V_160 . V_162 || ! F_62 ( V_160 . V_162 , V_2 ) )
return V_182 ;
}
V_175 . V_27 = V_174 . V_27 ;
V_175 . V_28 = V_174 . V_28 ;
if ( F_44 ( & V_165 , & V_175 ) != 0 )
return V_183 ;
while ( V_26 == 0 && V_34 != V_174 . V_34 ) {
V_26 = F_56 ( V_174 . V_31 , V_34 , V_2 ,
& V_164 , V_3 , & V_165 , V_4 , & V_160 ) ;
V_34 ++ ;
}
if ( F_9 ( V_26 == F_2 ( V_36 ) ) ) {
V_26 = F_2 ( V_14 ) ;
V_34 -- ;
}
* V_175 . V_26 = V_26 ;
* V_175 . V_34 = F_2 ( V_34 ) ;
F_54 ( & V_160 ) ;
F_63 ( V_160 . V_162 ) ;
F_18 ( L_15 , V_30 , F_12 ( V_26 ) ) ;
return V_184 ;
}
