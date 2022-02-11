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
if ( V_63 > V_66 / sizeof( * args -> V_67 ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_38;
}
args -> V_67 = F_26 ( V_63 * sizeof( * args -> V_67 ) , V_68 ) ;
if ( ! args -> V_67 ) {
V_26 = F_2 ( V_69 ) ;
goto V_38;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
struct V_70 * V_71 = & args -> V_67 [ V_64 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_2 ) ) + V_72 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_73;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( V_62 != 1 ) {
V_26 = F_2 ( V_74 ) ;
goto V_73;
}
V_71 -> V_75 = F_12 ( * V_6 ++ ) ;
if ( V_71 -> V_75 != V_76 &&
V_71 -> V_75 != V_77 ) {
V_26 = F_2 ( V_74 ) ;
goto V_73;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_71 -> V_75 == V_76 ) &&
( V_62 != V_72 + 8 ) ) ||
( ( V_71 -> V_75 == V_77 ) &&
( V_62 != V_72 + 4 ) ) ) {
V_26 = F_2 ( V_74 ) ;
goto V_73;
}
V_71 -> V_78 = F_12 ( * V_6 ++ ) ;
memcpy ( V_71 -> V_79 . V_20 , V_6 , V_72 ) ;
V_6 += F_27 ( V_72 ) ;
if ( V_71 -> V_78 == V_76 ) {
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_26 = F_2 ( V_45 ) ;
goto V_73;
}
V_71 -> V_80 = F_12 ( * V_6 ++ ) ;
} else {
V_71 -> V_80 = 0 ;
}
args -> V_65 ++ ;
F_18 ( L_8 ,
V_30 , V_71 -> V_75 , V_71 -> V_78 ,
V_71 -> V_80 ) ;
}
V_38:
F_18 ( L_9 ,
V_30 , F_12 ( V_26 ) , args -> V_65 ) ;
return V_26 ;
V_73:
F_28 ( args -> V_67 ) ;
goto V_38;
}
static T_1 F_29 ( struct V_8 * V_9 ,
struct V_81 * V_82 )
{
T_1 * V_6 ;
int V_12 = V_83 ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_82 -> V_20 , V_6 , V_12 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_26 ;
V_26 = F_29 ( V_9 , & V_85 -> V_86 ) ;
if ( V_26 )
goto V_38;
V_26 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
V_85 -> V_87 = F_12 ( * V_6 ++ ) ;
if ( V_85 -> V_87 ) {
V_6 = F_7 ( V_9 ,
V_85 -> V_87 * 2 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
V_85 -> V_88 = F_26 ( V_85 -> V_87 *
sizeof( * V_85 -> V_88 ) ,
V_68 ) ;
if ( F_9 ( V_85 -> V_88 == NULL ) )
goto V_38;
for ( V_64 = 0 ; V_64 < V_85 -> V_87 ; V_64 ++ ) {
V_85 -> V_88 [ V_64 ] . V_89 = F_12 ( * V_6 ++ ) ;
V_85 -> V_88 [ V_64 ] . V_90 = F_12 ( * V_6 ++ ) ;
}
}
V_26 = 0 ;
V_38:
return V_26 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_91 * args )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_26 ;
V_26 = F_29 ( V_9 , & args -> V_92 ) ;
if ( V_26 )
goto V_38;
V_26 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_38;
args -> V_93 = F_21 ( V_2 ) ;
args -> V_94 = F_12 ( * V_6 ++ ) ;
args -> V_95 = F_12 ( * V_6 ++ ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = F_12 ( * V_6 ++ ) ;
args -> V_99 = NULL ;
if ( args -> V_98 ) {
args -> V_99 = F_26 ( args -> V_98 *
sizeof( * args -> V_99 ) ,
V_68 ) ;
if ( F_9 ( args -> V_99 == NULL ) )
goto V_38;
for ( V_64 = 0 ; V_64 < args -> V_98 ; V_64 ++ ) {
V_26 = F_30 ( V_9 , & args -> V_99 [ V_64 ] ) ;
if ( V_26 )
goto V_100;
}
}
V_26 = 0 ;
F_18 ( L_10
L_11 ,
V_30 ,
( ( T_4 * ) & args -> V_92 ) [ 0 ] ,
( ( T_4 * ) & args -> V_92 ) [ 1 ] ,
( ( T_4 * ) & args -> V_92 ) [ 2 ] ,
( ( T_4 * ) & args -> V_92 ) [ 3 ] ,
args -> V_94 , args -> V_95 ,
args -> V_96 , args -> V_97 ,
args -> V_98 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
V_100:
for ( V_64 = 0 ; V_64 < args -> V_98 ; V_64 ++ )
F_28 ( args -> V_99 [ V_64 ] . V_88 ) ;
F_28 ( args -> V_99 ) ;
goto V_38;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_101 * args )
{
T_2 V_21 [ 2 ] ;
T_1 * V_6 , V_26 ;
args -> V_102 = F_21 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_103 = F_12 ( * V_6 ++ ) ;
V_26 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_26 ) )
return V_26 ;
args -> V_104 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_105 * args )
{
T_1 * V_6 ;
args -> V_106 = F_21 ( V_2 ) ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_107 = F_12 ( * V_6 ++ ) ;
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
static T_1 F_37 ( struct V_8 * V_9 , const T_2 * V_21 , T_1 * * V_108 )
{
T_1 V_109 [ 2 ] ;
T_1 * V_6 ;
V_109 [ 0 ] = F_2 ( V_21 [ 0 ] & V_110 ) ;
V_109 [ 1 ] = F_2 ( V_21 [ 1 ] & V_111 ) ;
if ( V_109 [ 1 ] != 0 ) {
V_6 = F_35 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_109 [ 0 ] ;
* V_6 ++ = V_109 [ 1 ] ;
} else if ( V_109 [ 0 ] != 0 ) {
V_6 = F_35 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_109 [ 0 ] ;
} else {
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_108 = V_6 ;
return 0 ;
}
static T_1 F_38 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_112 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_113 ) )
return 0 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , V_112 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_114 ) )
return 0 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_8 * V_9 , const struct V_115 * time )
{
T_1 * V_6 ;
V_6 = F_35 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_39 ( V_6 , time -> V_116 ) ;
* V_6 = F_2 ( time -> V_117 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_115 * time )
{
if ( ! ( V_21 [ 1 ] & V_118 ) )
return 0 ;
return F_41 ( V_9 , time ) ;
}
static T_1 F_43 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_115 * time )
{
if ( ! ( V_21 [ 1 ] & V_119 ) )
return 0 ;
return F_41 ( V_9 , time ) ;
}
static T_1 F_44 ( struct V_8 * V_9 , struct V_120 * V_25 )
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
static T_1 F_45 ( struct V_8 * V_9 , T_2 V_35 , T_1 V_121 )
{
T_1 * V_6 ;
V_6 = F_35 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_36 ) ;
* V_6 ++ = F_2 ( V_35 ) ;
* V_6 = V_121 ;
return 0 ;
}
static T_1 F_46 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_122 * V_121 )
{
T_1 * V_108 = NULL ;
T_1 V_26 = V_121 -> V_26 ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_37 ( V_9 , V_121 -> V_21 , & V_108 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_38 ( V_9 , V_121 -> V_21 , V_121 -> V_123 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_40 ( V_9 , V_121 -> V_21 , V_121 -> V_17 ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_42 ( V_9 , V_121 -> V_21 , & V_121 -> ctime ) ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
V_26 = F_43 ( V_9 , V_121 -> V_21 , & V_121 -> V_124 ) ;
* V_108 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_108 + 1 ) ) ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_47 ( struct V_8 * V_9 ,
const struct V_81 * V_82 )
{
T_1 * V_6 ;
int V_12 = V_83 ;
V_6 = F_35 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_82 , V_12 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_125 * V_121 )
{
T_1 * V_6 ;
unsigned V_26 = V_121 -> V_126 ;
if ( F_9 ( V_26 != 0 ) )
goto V_38;
F_47 ( V_9 , & V_121 -> V_127 ) ;
V_6 = F_35 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_121 -> V_128 ) ;
* V_6 ++ = F_2 ( V_121 -> V_129 ) ;
* V_6 ++ = F_2 ( V_121 -> V_130 ) ;
* V_6 ++ = F_2 ( V_121 -> V_131 ) ;
V_38:
F_18 ( L_6 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1
F_49 ( int V_132 , unsigned int V_133 , struct V_134 * * V_35 )
{
if ( V_133 == V_135 ) {
if ( V_132 != 0 )
return F_2 ( V_136 ) ;
} else {
if ( V_132 == 0 )
return F_2 ( V_137 ) ;
}
switch ( V_133 ) {
case V_138 :
case V_139 :
case V_135 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
* V_35 = & V_144 [ V_133 ] ;
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
return F_2 ( V_150 ) ;
default:
return F_2 ( V_151 ) ;
}
return F_2 ( V_152 ) ;
}
static void F_50 ( struct V_153 * V_154 )
{
struct V_155 * V_156 = & V_154 -> V_157 ;
F_51 ( & V_156 -> V_158 ) ;
V_156 -> V_159 = - 1 ;
F_52 ( V_154 ) ;
F_53 ( & V_156 -> V_158 ) ;
}
static void F_54 ( struct V_160 * V_161 )
{
if ( V_161 -> V_162 != - 1 )
F_50 ( V_161 -> V_163 -> V_164 ) ;
}
static T_1
F_49 ( int V_132 , unsigned int V_133 , struct V_134 * * V_35 )
{
return F_2 ( V_33 ) ;
}
static void F_54 ( struct V_160 * V_161 )
{
}
static T_1
F_55 ( unsigned int V_133 , struct V_134 * * V_35 )
{
switch ( V_133 ) {
case V_138 :
case V_139 :
* V_35 = & V_144 [ V_133 ] ;
break;
default:
return F_2 ( V_151 ) ;
}
return F_2 ( V_152 ) ;
}
static T_1 F_56 ( T_2 V_31 , int V_132 ,
struct V_1 * V_2 ,
struct V_8 * V_165 , void * V_3 ,
struct V_8 * V_166 , void * V_4 ,
struct V_160 * V_161 )
{
struct V_134 * V_35 = & V_144 [ 0 ] ;
unsigned int V_133 ;
T_1 V_26 ;
long V_167 ;
T_1 V_121 ;
F_18 ( L_12 , V_30 ) ;
V_26 = F_19 ( V_165 , & V_133 ) ;
if ( F_9 ( V_26 ) )
return V_26 ;
F_18 ( L_13 ,
V_30 , V_31 , V_132 , V_133 ) ;
V_26 = V_31 ? F_49 ( V_132 , V_133 , & V_35 ) :
F_55 ( V_133 , & V_35 ) ;
if ( V_26 == F_2 ( V_151 ) )
V_133 = V_168 ;
if ( V_26 )
goto V_169;
if ( V_161 -> V_170 ) {
V_26 = V_161 -> V_170 ;
goto V_169;
}
V_167 = V_166 -> V_171 - V_166 -> V_6 ;
if ( V_167 > 0 && V_167 < V_172 ) {
V_26 = V_35 -> V_173 ( V_2 , V_165 , V_3 ) ;
if ( F_15 ( V_26 == 0 ) )
V_26 = V_35 -> F_56 ( V_3 , V_4 , V_161 ) ;
} else
V_26 = F_2 ( V_14 ) ;
V_169:
V_121 = F_45 ( V_166 , V_133 , V_26 ) ;
if ( F_9 ( V_121 ) )
return V_121 ;
if ( V_35 -> V_174 != NULL && V_26 == 0 )
V_26 = V_35 -> V_174 ( V_2 , V_166 , V_4 ) ;
F_18 ( L_14 , V_30 , F_12 ( V_26 ) ) ;
return V_26 ;
}
static T_1 F_57 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_24 V_175 = { 0 } ;
struct V_120 V_176 = { NULL } ;
struct V_8 V_165 , V_166 ;
T_1 * V_6 , V_26 ;
struct V_160 V_161 = {
. V_170 = 0 ,
. V_163 = NULL ,
. V_162 = - 1 ,
} ;
unsigned int V_34 = 0 ;
F_18 ( L_12 , V_30 ) ;
F_58 ( & V_165 , & V_2 -> V_177 , V_2 -> V_177 . V_178 [ 0 ] . V_179 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_180 . V_178 [ 0 ] . V_179 + V_2 -> V_180 . V_178 [ 0 ] . V_181 ) ;
F_59 ( & V_166 , & V_2 -> V_180 , V_6 ) ;
V_26 = F_17 ( & V_165 , & V_175 ) ;
if ( V_26 == F_60 ( V_14 ) )
return V_182 ;
if ( V_175 . V_31 == 0 ) {
V_161 . V_163 = F_61 ( V_175 . V_32 ) ;
if ( ! V_161 . V_163 || ! F_62 ( V_161 . V_163 , V_2 ) )
return V_183 ;
}
V_176 . V_27 = V_175 . V_27 ;
V_176 . V_28 = V_175 . V_28 ;
if ( F_44 ( & V_166 , & V_176 ) != 0 )
return V_184 ;
while ( V_26 == 0 && V_34 != V_175 . V_34 ) {
V_26 = F_56 ( V_175 . V_31 , V_34 , V_2 ,
& V_165 , V_3 , & V_166 , V_4 , & V_161 ) ;
V_34 ++ ;
}
if ( F_9 ( V_26 == F_2 ( V_36 ) ) ) {
V_26 = F_2 ( V_14 ) ;
V_34 -- ;
}
* V_176 . V_26 = V_26 ;
* V_176 . V_34 = F_2 ( V_34 ) ;
F_54 ( & V_161 ) ;
F_63 ( V_161 . V_163 ) ;
F_18 ( L_15 , V_30 , F_12 ( V_26 ) ) ;
return V_185 ;
}
