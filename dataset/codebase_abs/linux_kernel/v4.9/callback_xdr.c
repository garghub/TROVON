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
static T_1 * F_7 ( struct V_8 * V_9 , T_2 V_10 )
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
static T_1 F_14 ( struct V_8 * V_9 , T_3 * V_21 )
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
static T_1 F_16 ( struct V_8 * V_9 , T_4 * V_23 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_24 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_23 -> V_20 , V_6 , V_24 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_8 * V_9 , T_4 * V_23 )
{
V_23 -> type = V_25 ;
return F_16 ( V_9 , V_23 ) ;
}
static T_1 F_18 ( struct V_8 * V_9 , struct V_26 * V_27 )
{
T_1 * V_6 ;
T_1 V_28 ;
V_28 = F_11 ( V_9 , & V_27 -> V_29 , & V_27 -> V_30 ) ;
if ( F_9 ( V_28 != 0 ) )
return V_28 ;
if ( V_27 -> V_29 > V_31 ) {
F_10 ( L_2 ,
V_32 , V_27 -> V_29 ) ;
return F_2 ( V_14 ) ;
}
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
V_27 -> V_33 = F_12 ( * V_6 ++ ) ;
if ( V_27 -> V_33 <= V_34 ) {
V_27 -> V_35 = F_12 ( * V_6 ++ ) ;
} else {
F_19 ( L_3
L_4 ,
V_32 , V_27 -> V_33 ) ;
return F_2 ( V_36 ) ;
}
V_27 -> V_37 = F_12 ( * V_6 ) ;
F_20 ( L_5 , V_32 ,
V_27 -> V_33 , V_27 -> V_37 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_8 * V_9 , unsigned int * V_38 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_39 ) ;
* V_38 = F_12 ( * V_6 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_40 * args )
{
T_1 V_28 ;
V_28 = F_13 ( V_9 , & args -> V_16 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_14 ( V_9 , args -> V_21 ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_42 * args )
{
T_1 * V_6 ;
T_1 V_28 ;
V_28 = F_17 ( V_9 , & args -> V_23 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_14 ) ;
goto V_41;
}
args -> V_43 = F_12 ( * V_6 ) ;
V_28 = F_13 ( V_9 , & args -> V_16 ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1 F_24 ( struct V_8 * V_9 , T_4 * V_23 )
{
V_23 -> type = V_44 ;
return F_16 ( V_9 , V_23 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_45 * args )
{
T_1 * V_6 ;
T_1 V_28 = 0 ;
T_3 V_46 ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
args -> V_48 = F_12 ( * V_6 ++ ) ;
V_46 = F_12 ( * V_6 ++ ) ;
args -> V_49 = F_12 ( * V_6 ++ ) ;
args -> V_50 = F_12 ( * V_6 ++ ) ;
if ( args -> V_50 == V_51 ) {
args -> V_52 . V_46 = V_46 ;
V_28 = F_13 ( V_9 , & args -> V_53 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_6 = F_7 ( V_9 , 2 * sizeof( V_54 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
V_6 = F_26 ( V_6 , & args -> V_52 . V_55 ) ;
V_6 = F_26 ( V_6 , & args -> V_52 . V_56 ) ;
V_28 = F_24 ( V_9 , & args -> V_57 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
} else if ( args -> V_50 == V_58 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_54 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
V_6 = F_26 ( V_6 , & args -> V_59 . V_60 ) ;
V_6 = F_26 ( V_6 , & args -> V_59 . V_61 ) ;
} else if ( args -> V_50 != V_62 ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
F_20 ( L_7 ,
V_32 ,
args -> V_48 , V_46 ,
args -> V_49 , args -> V_50 ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static
T_1 F_27 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_63 * args )
{
T_1 * V_6 ;
T_1 V_28 = 0 ;
T_5 V_64 ;
int V_65 , V_66 ;
args -> V_67 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
V_65 = F_12 ( * V_6 ++ ) ;
if ( V_65 <= 0 )
goto V_41;
if ( V_65 > V_68 / sizeof( * args -> V_69 ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_41;
}
args -> V_69 = F_28 ( V_65 , sizeof( * args -> V_69 ) , V_70 ) ;
if ( ! args -> V_69 ) {
V_28 = F_2 ( V_71 ) ;
goto V_41;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
struct V_72 * V_73 = & args -> V_69 [ V_66 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_3 ) ) + V_74 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_75;
}
V_64 = F_12 ( * V_6 ++ ) ;
if ( V_64 != 1 ) {
V_28 = F_2 ( V_76 ) ;
goto V_75;
}
V_73 -> V_77 = F_12 ( * V_6 ++ ) ;
if ( V_73 -> V_77 != V_78 &&
V_73 -> V_77 != V_79 ) {
V_28 = F_2 ( V_76 ) ;
goto V_75;
}
V_64 = F_12 ( * V_6 ++ ) ;
if ( ( ( V_73 -> V_77 == V_78 ) &&
( V_64 != V_74 + 8 ) ) ||
( ( V_73 -> V_77 == V_79 ) &&
( V_64 != V_74 + 4 ) ) ) {
V_28 = F_2 ( V_76 ) ;
goto V_75;
}
V_73 -> V_80 = F_12 ( * V_6 ++ ) ;
memcpy ( V_73 -> V_81 . V_20 , V_6 , V_74 ) ;
V_6 += F_29 ( V_74 ) ;
if ( V_73 -> V_80 == V_78 ) {
V_6 = F_7 ( V_9 , sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_28 = F_2 ( V_47 ) ;
goto V_75;
}
V_73 -> V_82 = F_12 ( * V_6 ++ ) ;
} else {
V_73 -> V_82 = 0 ;
}
args -> V_67 ++ ;
F_20 ( L_8 ,
V_32 , V_73 -> V_77 , V_73 -> V_80 ,
V_73 -> V_82 ) ;
}
V_41:
F_20 ( L_9 ,
V_32 , F_12 ( V_28 ) , args -> V_67 ) ;
return V_28 ;
V_75:
F_30 ( args -> V_69 ) ;
goto V_41;
}
static T_1 F_31 ( struct V_8 * V_9 ,
struct V_83 * V_84 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_85 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_84 -> V_20 , V_6 , V_85 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_8 * V_9 ,
struct V_86 * V_87 )
{
T_1 * V_6 ;
int V_66 ;
T_1 V_28 ;
V_28 = F_31 ( V_9 , & V_87 -> V_88 ) ;
if ( V_28 )
goto V_41;
V_28 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_41;
V_87 -> V_89 = F_12 ( * V_6 ++ ) ;
if ( V_87 -> V_89 ) {
V_6 = F_7 ( V_9 ,
V_87 -> V_89 * 2 * sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_41;
V_87 -> V_90 = F_28 ( V_87 -> V_89 ,
sizeof( * V_87 -> V_90 ) ,
V_70 ) ;
if ( F_9 ( V_87 -> V_90 == NULL ) )
goto V_41;
for ( V_66 = 0 ; V_66 < V_87 -> V_89 ; V_66 ++ ) {
V_87 -> V_90 [ V_66 ] . V_91 = F_12 ( * V_6 ++ ) ;
V_87 -> V_90 [ V_66 ] . V_92 = F_12 ( * V_6 ++ ) ;
}
}
V_28 = 0 ;
V_41:
return V_28 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_93 * args )
{
T_1 * V_6 ;
int V_66 ;
T_1 V_28 ;
V_28 = F_31 ( V_9 , & args -> V_94 ) ;
if ( V_28 )
goto V_41;
V_28 = F_2 ( V_14 ) ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_41;
args -> V_95 = F_34 ( V_2 ) ;
args -> V_96 = F_12 ( * V_6 ++ ) ;
args -> V_97 = F_12 ( * V_6 ++ ) ;
args -> V_98 = F_12 ( * V_6 ++ ) ;
args -> V_99 = F_12 ( * V_6 ++ ) ;
args -> V_100 = F_12 ( * V_6 ++ ) ;
args -> V_101 = NULL ;
if ( args -> V_100 ) {
args -> V_101 = F_28 ( args -> V_100 ,
sizeof( * args -> V_101 ) ,
V_70 ) ;
if ( F_9 ( args -> V_101 == NULL ) )
goto V_41;
for ( V_66 = 0 ; V_66 < args -> V_100 ; V_66 ++ ) {
V_28 = F_32 ( V_9 , & args -> V_101 [ V_66 ] ) ;
if ( V_28 ) {
args -> V_100 = V_66 ;
goto V_102;
}
}
}
V_28 = 0 ;
F_20 ( L_10
L_11 ,
V_32 ,
( ( T_5 * ) & args -> V_94 ) [ 0 ] ,
( ( T_5 * ) & args -> V_94 ) [ 1 ] ,
( ( T_5 * ) & args -> V_94 ) [ 2 ] ,
( ( T_5 * ) & args -> V_94 ) [ 3 ] ,
args -> V_96 , args -> V_97 ,
args -> V_98 , args -> V_99 ,
args -> V_100 ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
V_102:
for ( V_66 = 0 ; V_66 < args -> V_100 ; V_66 ++ )
F_30 ( args -> V_101 [ V_66 ] . V_90 ) ;
F_30 ( args -> V_101 ) ;
goto V_41;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_103 * args )
{
T_3 V_21 [ 2 ] ;
T_1 * V_6 , V_28 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
args -> V_104 = F_12 ( * V_6 ++ ) ;
V_28 = F_14 ( V_9 , V_21 ) ;
if ( F_9 ( V_28 ) )
return V_28 ;
args -> V_105 = V_21 [ 0 ] ;
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_106 * args )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
args -> V_107 = F_12 ( * V_6 ++ ) ;
return 0 ;
}
static T_1 F_37 ( struct V_8 * V_9 , struct V_108 * args )
{
T_1 * V_6 ;
unsigned int V_12 ;
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
V_6 = F_26 ( V_6 , & args -> V_109 . V_110 ) ;
V_12 = F_38 ( * V_6 ) ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_47 ) ;
if ( V_12 == 20 ) {
V_6 += 2 ;
args -> V_109 . V_111 = F_38 ( * V_6 ++ ) ;
F_26 ( V_6 , & args -> V_109 . V_112 ) ;
args -> V_113 = true ;
} else {
args -> V_109 . V_111 = 0 ;
args -> V_109 . V_112 = 0 ;
args -> V_113 = false ;
}
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_108 * args )
{
T_1 V_28 ;
V_28 = F_13 ( V_9 , & args -> V_114 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_37 ( V_9 , args ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1 F_40 ( struct V_8 * V_9 , unsigned int V_12 , const char * V_13 )
{
T_1 * V_6 ;
V_6 = F_41 ( V_9 , 4 + V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
F_42 ( V_6 , V_13 , V_12 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_8 * V_9 , const T_3 * V_21 , T_1 * * V_115 )
{
T_1 V_116 [ 2 ] ;
T_1 * V_6 ;
V_116 [ 0 ] = F_2 ( V_21 [ 0 ] & V_117 ) ;
V_116 [ 1 ] = F_2 ( V_21 [ 1 ] & V_118 ) ;
if ( V_116 [ 1 ] != 0 ) {
V_6 = F_41 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_116 [ 0 ] ;
* V_6 ++ = V_116 [ 1 ] ;
} else if ( V_116 [ 0 ] != 0 ) {
V_6 = F_41 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_116 [ 0 ] ;
} else {
V_6 = F_41 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_115 = V_6 ;
return 0 ;
}
static T_1 F_44 ( struct V_8 * V_9 , const T_3 * V_21 , V_54 V_119 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_120 ) )
return 0 ;
V_6 = F_41 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_45 ( V_6 , V_119 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_8 * V_9 , const T_3 * V_21 , V_54 V_17 )
{
T_1 * V_6 ;
if ( ! ( V_21 [ 0 ] & V_121 ) )
return 0 ;
V_6 = F_41 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_45 ( V_6 , V_17 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_8 * V_9 , const struct V_122 * time )
{
T_1 * V_6 ;
V_6 = F_41 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_14 ) ;
V_6 = F_45 ( V_6 , time -> V_123 ) ;
* V_6 = F_2 ( time -> V_124 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_8 * V_9 , const T_3 * V_21 , const struct V_122 * time )
{
if ( ! ( V_21 [ 1 ] & V_125 ) )
return 0 ;
return F_47 ( V_9 , time ) ;
}
static T_1 F_49 ( struct V_8 * V_9 , const T_3 * V_21 , const struct V_122 * time )
{
if ( ! ( V_21 [ 1 ] & V_126 ) )
return 0 ;
return F_47 ( V_9 , time ) ;
}
static T_1 F_50 ( struct V_8 * V_9 , struct V_127 * V_27 )
{
T_1 V_28 ;
V_27 -> V_28 = F_41 ( V_9 , 4 ) ;
if ( F_9 ( V_27 -> V_28 == NULL ) )
return F_2 ( V_14 ) ;
V_28 = F_40 ( V_9 , V_27 -> V_29 , V_27 -> V_30 ) ;
if ( F_9 ( V_28 != 0 ) )
return V_28 ;
V_27 -> V_37 = F_41 ( V_9 , 4 ) ;
if ( F_9 ( V_27 -> V_37 == NULL ) )
return F_2 ( V_14 ) ;
return 0 ;
}
static T_1 F_51 ( struct V_8 * V_9 , T_3 V_38 , T_1 V_128 )
{
T_1 * V_6 ;
V_6 = F_41 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_39 ) ;
* V_6 ++ = F_2 ( V_38 ) ;
* V_6 = V_128 ;
return 0 ;
}
static T_1 F_52 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_129 * V_128 )
{
T_1 * V_115 = NULL ;
T_1 V_28 = V_128 -> V_28 ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_43 ( V_9 , V_128 -> V_21 , & V_115 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_44 ( V_9 , V_128 -> V_21 , V_128 -> V_130 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_46 ( V_9 , V_128 -> V_21 , V_128 -> V_17 ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_48 ( V_9 , V_128 -> V_21 , & V_128 -> ctime ) ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_49 ( V_9 , V_128 -> V_21 , & V_128 -> V_131 ) ;
* V_115 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_115 + 1 ) ) ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1 F_53 ( struct V_8 * V_9 ,
const struct V_83 * V_84 )
{
T_1 * V_6 ;
V_6 = F_41 ( V_9 , V_85 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
memcpy ( V_6 , V_84 , V_85 ) ;
return 0 ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_132 * V_128 )
{
T_1 * V_6 ;
T_1 V_28 = V_128 -> V_133 ;
if ( F_9 ( V_28 != 0 ) )
goto V_41;
V_28 = F_53 ( V_9 , & V_128 -> V_134 ) ;
if ( V_28 )
goto V_41;
V_6 = F_41 ( V_9 , 4 * sizeof( T_3 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_14 ) ;
* V_6 ++ = F_2 ( V_128 -> V_135 ) ;
* V_6 ++ = F_2 ( V_128 -> V_136 ) ;
* V_6 ++ = F_2 ( V_128 -> V_137 ) ;
* V_6 ++ = F_2 ( V_128 -> V_138 ) ;
V_41:
F_20 ( L_6 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1
F_55 ( int V_139 , unsigned int V_140 , struct V_141 * * V_38 )
{
if ( V_140 == V_142 ) {
if ( V_139 != 0 )
return F_2 ( V_143 ) ;
} else {
if ( V_139 == 0 )
return F_2 ( V_144 ) ;
}
switch ( V_140 ) {
case V_145 :
case V_146 :
case V_142 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
* V_38 = & V_152 [ V_140 ] ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
return F_2 ( V_157 ) ;
default:
return F_2 ( V_158 ) ;
}
return F_2 ( V_159 ) ;
}
static void F_56 ( struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_161 -> V_166 ;
F_57 ( & V_165 -> V_167 ) ;
F_58 ( V_165 , V_163 ) ;
F_59 ( V_165 ) ;
F_60 ( & V_165 -> V_167 ) ;
}
static void F_61 ( struct V_168 * V_169 )
{
if ( V_169 -> V_163 ) {
F_56 ( V_169 -> V_170 -> V_171 , V_169 -> V_163 ) ;
V_169 -> V_163 = NULL ;
}
}
static T_1
F_55 ( int V_139 , unsigned int V_140 , struct V_141 * * V_38 )
{
return F_2 ( V_36 ) ;
}
static void F_61 ( struct V_168 * V_169 )
{
}
static T_1
F_62 ( int V_139 , unsigned int V_140 , struct V_141 * * V_38 )
{
T_1 V_28 = F_55 ( V_139 , V_140 , V_38 ) ;
if ( V_28 != F_2 ( V_158 ) )
return V_28 ;
if ( V_140 == V_172 )
return F_2 ( V_157 ) ;
return F_2 ( V_158 ) ;
}
static T_1
F_62 ( int V_139 , unsigned int V_140 , struct V_141 * * V_38 )
{
return F_2 ( V_36 ) ;
}
static T_1
F_63 ( unsigned int V_140 , struct V_141 * * V_38 )
{
switch ( V_140 ) {
case V_145 :
case V_146 :
* V_38 = & V_152 [ V_140 ] ;
break;
default:
return F_2 ( V_158 ) ;
}
return F_2 ( V_159 ) ;
}
static T_1 F_64 ( int V_139 , struct V_1 * V_2 ,
struct V_8 * V_173 , void * V_3 ,
struct V_8 * V_174 , void * V_4 ,
struct V_168 * V_169 )
{
struct V_141 * V_38 = & V_152 [ 0 ] ;
unsigned int V_140 ;
T_1 V_28 ;
long V_175 ;
T_1 V_128 ;
F_20 ( L_12 , V_32 ) ;
V_28 = F_21 ( V_173 , & V_140 ) ;
if ( F_9 ( V_28 ) )
return V_28 ;
F_20 ( L_13 ,
V_32 , V_169 -> V_33 , V_139 , V_140 ) ;
switch ( V_169 -> V_33 ) {
case 0 :
V_28 = F_63 ( V_140 , & V_38 ) ;
break;
case 1 :
V_28 = F_55 ( V_139 , V_140 , & V_38 ) ;
break;
case 2 :
V_28 = F_62 ( V_139 , V_140 , & V_38 ) ;
break;
default:
V_28 = F_2 ( V_36 ) ;
}
if ( V_28 == F_2 ( V_158 ) )
V_140 = V_176 ;
if ( V_28 )
goto V_177;
if ( V_169 -> V_178 ) {
V_28 = V_169 -> V_178 ;
goto V_177;
}
V_175 = V_174 -> V_179 - V_174 -> V_6 ;
if ( V_175 > 0 && V_175 < V_180 ) {
V_28 = V_38 -> V_181 ( V_2 , V_173 , V_3 ) ;
if ( F_15 ( V_28 == 0 ) )
V_28 = V_38 -> F_64 ( V_3 , V_4 , V_169 ) ;
} else
V_28 = F_2 ( V_14 ) ;
V_177:
V_128 = F_51 ( V_174 , V_140 , V_28 ) ;
if ( F_9 ( V_128 ) )
return V_128 ;
if ( V_38 -> V_182 != NULL && V_28 == 0 )
V_28 = V_38 -> V_182 ( V_2 , V_174 , V_4 ) ;
F_20 ( L_14 , V_32 , F_12 ( V_28 ) ) ;
return V_28 ;
}
static T_1 F_65 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_26 V_183 = { 0 } ;
struct V_127 V_184 = { NULL } ;
struct V_8 V_173 , V_174 ;
T_1 * V_6 , V_28 ;
struct V_168 V_169 = {
. V_178 = 0 ,
. V_170 = NULL ,
. V_185 = F_66 ( V_2 ) ,
} ;
unsigned int V_37 = 0 ;
F_20 ( L_12 , V_32 ) ;
F_67 ( & V_173 , & V_2 -> V_186 , V_2 -> V_186 . V_187 [ 0 ] . V_188 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_189 . V_187 [ 0 ] . V_188 + V_2 -> V_189 . V_187 [ 0 ] . V_190 ) ;
F_68 ( & V_174 , & V_2 -> V_189 , V_6 ) ;
V_28 = F_18 ( & V_173 , & V_183 ) ;
if ( V_28 == F_2 ( V_14 ) )
return V_191 ;
if ( V_183 . V_33 == 0 ) {
V_169 . V_170 = F_69 ( F_66 ( V_2 ) , V_183 . V_35 ) ;
if ( ! V_169 . V_170 || ! F_70 ( V_169 . V_170 , V_2 ) )
goto V_192;
}
V_169 . V_33 = V_183 . V_33 ;
V_184 . V_29 = V_183 . V_29 ;
V_184 . V_30 = V_183 . V_30 ;
if ( F_50 ( & V_174 , & V_184 ) != 0 )
return V_193 ;
while ( V_28 == 0 && V_37 != V_183 . V_37 ) {
V_28 = F_64 ( V_37 , V_2 , & V_173 ,
V_3 , & V_174 , V_4 , & V_169 ) ;
V_37 ++ ;
}
if ( F_9 ( V_28 == F_2 ( V_39 ) ) ) {
V_28 = F_2 ( V_14 ) ;
V_37 -- ;
}
* V_184 . V_28 = V_28 ;
* V_184 . V_37 = F_2 ( V_37 ) ;
F_61 ( & V_169 ) ;
F_71 ( V_169 . V_170 ) ;
F_20 ( L_15 , V_32 , F_12 ( V_28 ) ) ;
return V_194 ;
V_192:
F_19 ( L_16 ) ;
return V_195 ;
}
