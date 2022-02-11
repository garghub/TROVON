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
if ( V_26 -> V_28 > V_30 ) {
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
V_27 = F_14 ( V_9 , args -> V_21 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_41 * args )
{
T_1 * V_6 ;
T_1 V_27 ;
V_27 = F_16 ( V_9 , & args -> V_23 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_14 ) ;
goto V_40;
}
args -> V_42 = F_12 ( * V_6 ) ;
V_27 = F_13 ( V_9 , & args -> V_16 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_43 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_2 V_44 ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
args -> V_46 = F_12 ( * V_6 ++ ) ;
V_44 = F_12 ( * V_6 ++ ) ;
args -> V_47 = F_12 ( * V_6 ++ ) ;
args -> V_48 = F_12 ( * V_6 ++ ) ;
if ( args -> V_48 == V_49 ) {
args -> V_50 . V_44 = V_44 ;
V_27 = F_13 ( V_9 , & args -> V_51 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_6 = F_7 ( V_9 , 2 * sizeof( V_52 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
V_6 = F_24 ( V_6 , & args -> V_50 . V_53 ) ;
V_6 = F_24 ( V_6 , & args -> V_50 . V_54 ) ;
V_27 = F_16 ( V_9 , & args -> V_55 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
} else if ( args -> V_48 == V_56 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_52 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
V_6 = F_24 ( V_6 , & args -> V_57 . V_58 ) ;
V_6 = F_24 ( V_6 , & args -> V_57 . V_59 ) ;
} else if ( args -> V_48 != V_60 ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
F_19 ( L_7 ,
V_31 ,
args -> V_46 , V_44 ,
args -> V_47 , args -> V_48 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static
T_1 F_25 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_61 * args )
{
T_1 * V_6 ;
T_1 V_27 = 0 ;
T_4 V_62 ;
int V_63 , V_64 ;
args -> V_65 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
V_63 = F_12 ( * V_6 ++ ) ;
if ( V_63 <= 0 )
goto V_40;
if ( V_63 > V_66 / sizeof( * args -> V_67 ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_40;
}
args -> V_67 = F_26 ( V_63 , sizeof( * args -> V_67 ) , V_68 ) ;
if ( ! args -> V_67 ) {
V_27 = F_2 ( V_69 ) ;
goto V_40;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
struct V_70 * V_71 = & args -> V_67 [ V_64 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_2 ) ) + V_72 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_73;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( V_62 != 1 ) {
V_27 = F_2 ( V_74 ) ;
goto V_73;
}
V_71 -> V_75 = F_12 ( * V_6 ++ ) ;
if ( V_71 -> V_75 != V_76 &&
V_71 -> V_75 != V_77 ) {
V_27 = F_2 ( V_74 ) ;
goto V_73;
}
V_62 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_71 -> V_75 == V_76 ) &&
( V_62 != V_72 + 8 ) ) ||
( ( V_71 -> V_75 == V_77 ) &&
( V_62 != V_72 + 4 ) ) ) {
V_27 = F_2 ( V_74 ) ;
goto V_73;
}
V_71 -> V_78 = F_12 ( * V_6 ++ ) ;
memcpy ( V_71 -> V_79 . V_20 , V_6 , V_72 ) ;
V_6 += F_27 ( V_72 ) ;
if ( V_71 -> V_78 == V_76 ) {
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_27 = F_2 ( V_45 ) ;
goto V_73;
}
V_71 -> V_80 = F_12 ( * V_6 ++ ) ;
} else {
V_71 -> V_80 = 0 ;
}
args -> V_65 ++ ;
F_19 ( L_8 ,
V_31 , V_71 -> V_75 , V_71 -> V_78 ,
V_71 -> V_80 ) ;
}
V_40:
F_19 ( L_9 ,
V_31 , F_12 ( V_27 ) , args -> V_65 ) ;
return V_27 ;
V_73:
F_28 ( args -> V_67 ) ;
goto V_40;
}
static T_1 F_29 ( struct V_8 * V_9 ,
struct V_81 * V_82 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_83 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_82 -> V_20 , V_6 , V_83 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_27 ;
V_27 = F_29 ( V_9 , & V_85 -> V_86 ) ;
if ( V_27 )
goto V_40;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
V_85 -> V_87 = F_12 ( * V_6 ++ ) ;
if ( V_85 -> V_87 ) {
V_6 = F_7 ( V_9 ,
V_85 -> V_87 * 2 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
V_85 -> V_88 = F_26 ( V_85 -> V_87 ,
sizeof( * V_85 -> V_88 ) ,
V_68 ) ;
if ( F_9 ( V_85 -> V_88 == NULL ) )
goto V_40;
for ( V_64 = 0 ; V_64 < V_85 -> V_87 ; V_64 ++ ) {
V_85 -> V_88 [ V_64 ] . V_89 = F_12 ( * V_6 ++ ) ;
V_85 -> V_88 [ V_64 ] . V_90 = F_12 ( * V_6 ++ ) ;
}
}
V_27 = 0 ;
V_40:
return V_27 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_91 * args )
{
T_1 * V_6 ;
int V_64 ;
T_1 V_27 ;
V_27 = F_29 ( V_9 , & args -> V_92 ) ;
if ( V_27 )
goto V_40;
V_27 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_40;
args -> V_93 = F_32 ( V_2 ) ;
args -> V_94 = F_12 ( * V_6 ++ ) ;
args -> V_95 = F_12 ( * V_6 ++ ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = F_12 ( * V_6 ++ ) ;
args -> V_99 = NULL ;
if ( args -> V_98 ) {
args -> V_99 = F_26 ( args -> V_98 ,
sizeof( * args -> V_99 ) ,
V_68 ) ;
if ( F_9 ( args -> V_99 == NULL ) )
goto V_40;
for ( V_64 = 0 ; V_64 < args -> V_98 ; V_64 ++ ) {
V_27 = F_30 ( V_9 , & args -> V_99 [ V_64 ] ) ;
if ( V_27 ) {
args -> V_98 = V_64 ;
goto V_100;
}
}
}
V_27 = 0 ;
F_19 ( L_10
L_11 ,
V_31 ,
( ( T_4 * ) & args -> V_92 ) [ 0 ] ,
( ( T_4 * ) & args -> V_92 ) [ 1 ] ,
( ( T_4 * ) & args -> V_92 ) [ 2 ] ,
( ( T_4 * ) & args -> V_92 ) [ 3 ] ,
args -> V_94 , args -> V_95 ,
args -> V_96 , args -> V_97 ,
args -> V_98 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
V_100:
for ( V_64 = 0 ; V_64 < args -> V_98 ; V_64 ++ )
F_28 ( args -> V_99 [ V_64 ] . V_88 ) ;
F_28 ( args -> V_99 ) ;
goto V_40;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_101 * args )
{
T_2 V_21 [ 2 ] ;
T_1 * V_6 , V_27 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_102 = F_12 ( * V_6 ++ ) ;
V_27 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
args -> V_103 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_104 * args )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_45 ) ;
args -> V_105 = F_12 ( * V_6 ++ ) ;
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
static T_1 F_38 ( struct V_8 * V_9 , const T_2 * V_21 , T_1 * * V_106 )
{
T_1 V_107 [ 2 ] ;
T_1 * V_6 ;
V_107 [ 0 ] = F_2 ( V_21 [ 0 ] & V_108 ) ;
V_107 [ 1 ] = F_2 ( V_21 [ 1 ] & V_109 ) ;
if ( V_107 [ 1 ] != 0 ) {
V_6 = F_36 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_107 [ 0 ] ;
* V_6 ++ = V_107 [ 1 ] ;
} else if ( V_107 [ 0 ] != 0 ) {
V_6 = F_36 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_107 [ 0 ] ;
} else {
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_106 = V_6 ;
return 0 ;
}
static T_1 F_39 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_110 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_111 ) )
return 0 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , V_110 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_8 * V_9 , const T_2 * V_21 , V_52 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_112 ) )
return 0 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_8 * V_9 , const struct V_113 * time )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_40 ( V_6 , time -> V_114 ) ;
* V_6 = F_2 ( time -> V_115 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_113 * time )
{
if ( ! ( V_21 [ 1 ] & V_116 ) )
return 0 ;
return F_42 ( V_9 , time ) ;
}
static T_1 F_44 ( struct V_8 * V_9 , const T_2 * V_21 , const struct V_113 * time )
{
if ( ! ( V_21 [ 1 ] & V_117 ) )
return 0 ;
return F_42 ( V_9 , time ) ;
}
static T_1 F_45 ( struct V_8 * V_9 , struct V_118 * V_26 )
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
static T_1 F_46 ( struct V_8 * V_9 , T_2 V_37 , T_1 V_119 )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_38 ) ;
* V_6 ++ = F_2 ( V_37 ) ;
* V_6 = V_119 ;
return 0 ;
}
static T_1 F_47 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_120 * V_119 )
{
T_1 * V_106 = NULL ;
T_1 V_27 = V_119 -> V_27 ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_38 ( V_9 , V_119 -> V_21 , & V_106 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_39 ( V_9 , V_119 -> V_21 , V_119 -> V_121 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_41 ( V_9 , V_119 -> V_21 , V_119 -> V_17 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_43 ( V_9 , V_119 -> V_21 , & V_119 -> ctime ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_44 ( V_9 , V_119 -> V_21 , & V_119 -> V_122 ) ;
* V_106 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_106 + 1 ) ) ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_48 ( struct V_8 * V_9 ,
const struct V_81 * V_82 )
{
T_1 * V_6 ;
V_6 = F_36 ( V_9 , V_83 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_82 , V_83 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_123 * V_119 )
{
T_1 * V_6 ;
T_1 V_27 = V_119 -> V_124 ;
if ( F_9 ( V_27 != 0 ) )
goto V_40;
V_27 = F_48 ( V_9 , & V_119 -> V_125 ) ;
if ( V_27 )
goto V_40;
V_6 = F_36 ( V_9 , 4 * sizeof( T_2 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_119 -> V_126 ) ;
* V_6 ++ = F_2 ( V_119 -> V_127 ) ;
* V_6 ++ = F_2 ( V_119 -> V_128 ) ;
* V_6 ++ = F_2 ( V_119 -> V_129 ) ;
V_40:
F_19 ( L_6 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1
F_50 ( int V_130 , unsigned int V_131 , struct V_132 * * V_37 )
{
if ( V_131 == V_133 ) {
if ( V_130 != 0 )
return F_2 ( V_134 ) ;
} else {
if ( V_130 == 0 )
return F_2 ( V_135 ) ;
}
switch ( V_131 ) {
case V_136 :
case V_137 :
case V_133 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
* V_37 = & V_142 [ V_131 ] ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
return F_2 ( V_148 ) ;
default:
return F_2 ( V_149 ) ;
}
return F_2 ( V_150 ) ;
}
static void F_51 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_155 * V_156 = & V_152 -> V_157 ;
F_52 ( & V_156 -> V_158 ) ;
F_53 ( V_156 , V_154 ) ;
F_54 ( V_156 ) ;
F_55 ( & V_156 -> V_158 ) ;
}
static void F_56 ( struct V_159 * V_160 )
{
if ( V_160 -> V_154 ) {
F_51 ( V_160 -> V_161 -> V_162 , V_160 -> V_154 ) ;
V_160 -> V_154 = NULL ;
}
}
static T_1
F_50 ( int V_130 , unsigned int V_131 , struct V_132 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static void F_56 ( struct V_159 * V_160 )
{
}
static T_1
F_57 ( int V_130 , unsigned int V_131 , struct V_132 * * V_37 )
{
T_1 V_27 = F_50 ( V_130 , V_131 , V_37 ) ;
if ( V_27 != F_2 ( V_149 ) )
return V_27 ;
if ( V_131 == V_163 )
return F_2 ( V_148 ) ;
return F_2 ( V_149 ) ;
}
static T_1
F_57 ( int V_130 , unsigned int V_131 , struct V_132 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static T_1
F_58 ( unsigned int V_131 , struct V_132 * * V_37 )
{
switch ( V_131 ) {
case V_136 :
case V_137 :
* V_37 = & V_142 [ V_131 ] ;
break;
default:
return F_2 ( V_149 ) ;
}
return F_2 ( V_150 ) ;
}
static T_1 F_59 ( int V_130 , struct V_1 * V_2 ,
struct V_8 * V_164 , void * V_3 ,
struct V_8 * V_165 , void * V_4 ,
struct V_159 * V_160 )
{
struct V_132 * V_37 = & V_142 [ 0 ] ;
unsigned int V_131 ;
T_1 V_27 ;
long V_166 ;
T_1 V_119 ;
F_19 ( L_12 , V_31 ) ;
V_27 = F_20 ( V_164 , & V_131 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
F_19 ( L_13 ,
V_31 , V_160 -> V_32 , V_130 , V_131 ) ;
switch ( V_160 -> V_32 ) {
case 0 :
V_27 = F_58 ( V_131 , & V_37 ) ;
break;
case 1 :
V_27 = F_50 ( V_130 , V_131 , & V_37 ) ;
break;
case 2 :
V_27 = F_57 ( V_130 , V_131 , & V_37 ) ;
break;
default:
V_27 = F_2 ( V_35 ) ;
}
if ( V_27 == F_2 ( V_149 ) )
V_131 = V_167 ;
if ( V_27 )
goto V_168;
if ( V_160 -> V_169 ) {
V_27 = V_160 -> V_169 ;
goto V_168;
}
V_166 = V_165 -> V_170 - V_165 -> V_6 ;
if ( V_166 > 0 && V_166 < V_171 ) {
V_27 = V_37 -> V_172 ( V_2 , V_164 , V_3 ) ;
if ( F_15 ( V_27 == 0 ) )
V_27 = V_37 -> F_59 ( V_3 , V_4 , V_160 ) ;
} else
V_27 = F_2 ( V_14 ) ;
V_168:
V_119 = F_46 ( V_165 , V_131 , V_27 ) ;
if ( F_9 ( V_119 ) )
return V_119 ;
if ( V_37 -> V_173 != NULL && V_27 == 0 )
V_27 = V_37 -> V_173 ( V_2 , V_165 , V_4 ) ;
F_19 ( L_14 , V_31 , F_12 ( V_27 ) ) ;
return V_27 ;
}
static T_1 F_60 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_25 V_174 = { 0 } ;
struct V_118 V_175 = { NULL } ;
struct V_8 V_164 , V_165 ;
T_1 * V_6 , V_27 ;
struct V_159 V_160 = {
. V_169 = 0 ,
. V_161 = NULL ,
. V_176 = F_61 ( V_2 ) ,
} ;
unsigned int V_36 = 0 ;
F_19 ( L_12 , V_31 ) ;
F_62 ( & V_164 , & V_2 -> V_177 , V_2 -> V_177 . V_178 [ 0 ] . V_179 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_180 . V_178 [ 0 ] . V_179 + V_2 -> V_180 . V_178 [ 0 ] . V_181 ) ;
F_63 ( & V_165 , & V_2 -> V_180 , V_6 ) ;
V_27 = F_17 ( & V_164 , & V_174 ) ;
if ( V_27 == F_2 ( V_14 ) )
return V_182 ;
if ( V_174 . V_32 == 0 ) {
V_160 . V_161 = F_64 ( F_61 ( V_2 ) , V_174 . V_34 ) ;
if ( ! V_160 . V_161 || ! F_65 ( V_160 . V_161 , V_2 ) )
return V_183 ;
}
V_160 . V_32 = V_174 . V_32 ;
V_175 . V_28 = V_174 . V_28 ;
V_175 . V_29 = V_174 . V_29 ;
if ( F_45 ( & V_165 , & V_175 ) != 0 )
return V_184 ;
while ( V_27 == 0 && V_36 != V_174 . V_36 ) {
V_27 = F_59 ( V_36 , V_2 , & V_164 ,
V_3 , & V_165 , V_4 , & V_160 ) ;
V_36 ++ ;
}
if ( F_9 ( V_27 == F_2 ( V_38 ) ) ) {
V_27 = F_2 ( V_14 ) ;
V_36 -- ;
}
* V_175 . V_27 = V_27 ;
* V_175 . V_36 = F_2 ( V_36 ) ;
F_56 ( & V_160 ) ;
F_66 ( V_160 . V_161 ) ;
F_19 ( L_15 , V_31 , F_12 ( V_27 ) ) ;
return V_185 ;
}
