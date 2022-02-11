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
static T_1 F_11 ( struct V_8 * V_9 , unsigned int * V_12 ,
const char * * V_13 , T_2 V_14 )
{
T_3 V_15 ;
V_15 = F_12 ( V_9 , ( void * * ) V_13 , V_14 ) ;
if ( V_15 < 0 )
return F_13 ( V_16 ) ;
* V_12 = V_15 ;
return 0 ;
}
static T_1 F_14 ( struct V_8 * V_9 , struct V_17 * V_18 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
V_18 -> V_19 = F_15 ( * V_6 ) ;
if ( V_18 -> V_19 > V_20 )
return F_2 ( V_21 ) ;
V_6 = F_7 ( V_9 , V_18 -> V_19 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
memcpy ( & V_18 -> V_22 [ 0 ] , V_6 , V_18 -> V_19 ) ;
memset ( & V_18 -> V_22 [ V_18 -> V_19 ] , 0 , sizeof( V_18 -> V_22 ) - V_18 -> V_19 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_8 * V_9 , T_4 * V_23 )
{
T_1 * V_6 ;
unsigned int V_24 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
V_24 = F_15 ( * V_6 ) ;
V_6 = F_7 ( V_9 , V_24 << 2 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
if ( F_17 ( V_24 > 0 ) )
V_23 [ 0 ] = F_15 ( * V_6 ++ ) ;
if ( V_24 > 1 )
V_23 [ 1 ] = F_15 ( * V_6 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_8 * V_9 , T_5 * V_25 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_26 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
memcpy ( V_25 -> V_22 , V_6 , V_26 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_8 * V_9 , T_5 * V_25 )
{
V_25 -> type = V_27 ;
return F_18 ( V_9 , V_25 ) ;
}
static T_1 F_20 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
T_1 * V_6 ;
T_1 V_30 ;
V_30 = F_11 ( V_9 , & V_29 -> V_31 , & V_29 -> V_32 , V_33 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
V_29 -> V_34 = F_15 ( * V_6 ++ ) ;
if ( V_29 -> V_34 <= V_35 ) {
V_29 -> V_36 = F_15 ( * V_6 ++ ) ;
} else {
F_21 ( L_2
L_3 ,
V_37 , V_29 -> V_34 ) ;
return F_2 ( V_38 ) ;
}
V_29 -> V_39 = F_15 ( * V_6 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_8 * V_9 , unsigned int * V_40 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_41 ) ;
* V_40 = F_15 ( * V_6 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_42 * args )
{
T_1 V_30 ;
V_30 = F_14 ( V_9 , & args -> V_18 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
return F_16 ( V_9 , args -> V_23 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_43 * args )
{
T_1 * V_6 ;
T_1 V_30 ;
V_30 = F_19 ( V_9 , & args -> V_25 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
args -> V_44 = F_15 ( * V_6 ) ;
return F_14 ( V_9 , & args -> V_18 ) ;
}
static T_1 F_25 ( struct V_8 * V_9 , T_5 * V_25 )
{
V_25 -> type = V_45 ;
return F_18 ( V_9 , V_25 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_46 * args )
{
T_1 * V_6 ;
T_1 V_30 = 0 ;
T_4 V_47 ;
V_6 = F_7 ( V_9 , 4 * sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
args -> V_49 = F_15 ( * V_6 ++ ) ;
V_47 = F_15 ( * V_6 ++ ) ;
args -> V_50 = F_15 ( * V_6 ++ ) ;
args -> V_51 = F_15 ( * V_6 ++ ) ;
if ( args -> V_51 == V_52 ) {
args -> V_53 . V_47 = V_47 ;
V_30 = F_14 ( V_9 , & args -> V_54 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
V_6 = F_7 ( V_9 , 2 * sizeof( V_55 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
V_6 = F_27 ( V_6 , & args -> V_53 . V_56 ) ;
V_6 = F_27 ( V_6 , & args -> V_53 . V_57 ) ;
return F_25 ( V_9 , & args -> V_58 ) ;
} else if ( args -> V_51 == V_59 ) {
V_6 = F_7 ( V_9 , 2 * sizeof( V_55 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
V_6 = F_27 ( V_6 , & args -> V_60 . V_61 ) ;
V_6 = F_27 ( V_6 , & args -> V_60 . V_62 ) ;
} else if ( args -> V_51 != V_63 )
return F_2 ( V_48 ) ;
return 0 ;
}
static
T_1 F_28 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_64 * args )
{
T_1 * V_6 ;
T_1 V_30 = 0 ;
T_6 V_65 ;
int V_66 , V_67 ;
args -> V_68 = 0 ;
V_6 = F_7 ( V_9 , sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_30 = F_2 ( V_48 ) ;
goto V_69;
}
V_66 = F_15 ( * V_6 ++ ) ;
if ( V_66 <= 0 )
goto V_69;
if ( V_66 > V_70 / sizeof( * args -> V_71 ) ) {
V_30 = F_2 ( V_48 ) ;
goto V_69;
}
args -> V_71 = F_29 ( V_66 , sizeof( * args -> V_71 ) , V_72 ) ;
if ( ! args -> V_71 ) {
V_30 = F_2 ( V_73 ) ;
goto V_69;
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
struct V_74 * V_75 = & args -> V_71 [ V_67 ] ;
V_6 = F_7 ( V_9 , ( 4 * sizeof( T_4 ) ) + V_76 ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_30 = F_2 ( V_48 ) ;
goto V_15;
}
V_65 = F_15 ( * V_6 ++ ) ;
if ( V_65 != 1 ) {
V_30 = F_2 ( V_77 ) ;
goto V_15;
}
V_75 -> V_78 = F_15 ( * V_6 ++ ) ;
if ( V_75 -> V_78 != V_79 &&
V_75 -> V_78 != V_80 ) {
V_30 = F_2 ( V_77 ) ;
goto V_15;
}
V_65 = F_15 ( * V_6 ++ ) ;
if ( ( ( V_75 -> V_78 == V_79 ) &&
( V_65 != V_76 + 8 ) ) ||
( ( V_75 -> V_78 == V_80 ) &&
( V_65 != V_76 + 4 ) ) ) {
V_30 = F_2 ( V_77 ) ;
goto V_15;
}
V_75 -> V_81 = F_15 ( * V_6 ++ ) ;
memcpy ( V_75 -> V_82 . V_22 , V_6 , V_76 ) ;
V_6 += F_30 ( V_76 ) ;
if ( V_75 -> V_81 == V_79 ) {
V_6 = F_7 ( V_9 , sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) ) {
V_30 = F_2 ( V_48 ) ;
goto V_15;
}
V_75 -> V_83 = F_15 ( * V_6 ++ ) ;
} else {
V_75 -> V_83 = 0 ;
}
args -> V_68 ++ ;
F_31 ( L_4 ,
V_37 , V_75 -> V_78 , V_75 -> V_81 ,
V_75 -> V_83 ) ;
}
V_69:
F_31 ( L_5 ,
V_37 , F_15 ( V_30 ) , args -> V_68 ) ;
return V_30 ;
V_15:
F_32 ( args -> V_71 ) ;
goto V_69;
}
static T_1 F_33 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , V_86 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
memcpy ( V_85 -> V_22 , V_6 , V_86 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_8 * V_9 ,
struct V_87 * V_88 )
{
T_1 * V_6 ;
int V_67 ;
T_1 V_30 ;
V_30 = F_33 ( V_9 , & V_88 -> V_89 ) ;
if ( V_30 )
goto V_69;
V_30 = F_2 ( V_16 ) ;
V_6 = F_7 ( V_9 , sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_69;
V_88 -> V_90 = F_15 ( * V_6 ++ ) ;
if ( V_88 -> V_90 ) {
V_6 = F_7 ( V_9 ,
V_88 -> V_90 * 2 * sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) )
goto V_69;
V_88 -> V_91 = F_29 ( V_88 -> V_90 ,
sizeof( * V_88 -> V_91 ) ,
V_72 ) ;
if ( F_9 ( V_88 -> V_91 == NULL ) )
goto V_69;
for ( V_67 = 0 ; V_67 < V_88 -> V_90 ; V_67 ++ ) {
V_88 -> V_91 [ V_67 ] . V_92 = F_15 ( * V_6 ++ ) ;
V_88 -> V_91 [ V_67 ] . V_93 = F_15 ( * V_6 ++ ) ;
}
}
V_30 = 0 ;
V_69:
return V_30 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_94 * args )
{
T_1 * V_6 ;
int V_67 ;
T_1 V_30 ;
V_30 = F_33 ( V_9 , & args -> V_95 ) ;
if ( V_30 )
return V_30 ;
V_6 = F_7 ( V_9 , 5 * sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
args -> V_96 = F_36 ( V_2 ) ;
args -> V_97 = F_15 ( * V_6 ++ ) ;
args -> V_98 = F_15 ( * V_6 ++ ) ;
args -> V_99 = F_15 ( * V_6 ++ ) ;
args -> V_100 = F_15 ( * V_6 ++ ) ;
args -> V_101 = F_15 ( * V_6 ++ ) ;
args -> V_102 = NULL ;
if ( args -> V_101 ) {
args -> V_102 = F_29 ( args -> V_101 ,
sizeof( * args -> V_102 ) ,
V_72 ) ;
if ( F_9 ( args -> V_102 == NULL ) )
return F_2 ( V_16 ) ;
for ( V_67 = 0 ; V_67 < args -> V_101 ; V_67 ++ ) {
V_30 = F_34 ( V_9 , & args -> V_102 [ V_67 ] ) ;
if ( V_30 ) {
args -> V_101 = V_67 ;
goto V_103;
}
}
}
return 0 ;
V_103:
for ( V_67 = 0 ; V_67 < args -> V_101 ; V_67 ++ )
F_32 ( args -> V_102 [ V_67 ] . V_91 ) ;
F_32 ( args -> V_102 ) ;
return V_30 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_104 * args )
{
T_4 V_23 [ 2 ] ;
T_1 * V_6 , V_30 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
args -> V_105 = F_15 ( * V_6 ++ ) ;
V_30 = F_16 ( V_9 , V_23 ) ;
if ( F_9 ( V_30 ) )
return V_30 ;
args -> V_106 = V_23 [ 0 ] ;
return 0 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_107 * args )
{
T_1 * V_6 ;
V_6 = F_7 ( V_9 , 4 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
args -> V_108 = F_15 ( * V_6 ++ ) ;
return 0 ;
}
static T_1 F_39 ( struct V_8 * V_9 , struct V_109 * args )
{
T_1 * V_6 ;
unsigned int V_12 ;
V_6 = F_7 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
V_6 = F_27 ( V_6 , & args -> V_110 . V_111 ) ;
V_12 = F_40 ( * V_6 ) ;
V_6 = F_7 ( V_9 , V_12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_48 ) ;
if ( V_12 == 20 ) {
V_6 += 2 ;
args -> V_110 . V_112 = F_40 ( * V_6 ++ ) ;
F_27 ( V_6 , & args -> V_110 . V_113 ) ;
args -> V_114 = true ;
} else {
args -> V_110 . V_112 = 0 ;
args -> V_110 . V_113 = 0 ;
args -> V_114 = false ;
}
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_109 * args )
{
T_1 V_30 ;
V_30 = F_14 ( V_9 , & args -> V_115 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
return F_39 ( V_9 , args ) ;
}
static T_1 F_42 ( struct V_8 * V_9 , unsigned int V_12 , const char * V_13 )
{
if ( F_9 ( F_43 ( V_9 , V_13 , V_12 ) < 0 ) )
return F_13 ( V_16 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_8 * V_9 , const T_4 * V_23 , T_1 * * V_116 )
{
T_1 V_117 [ 2 ] ;
T_1 * V_6 ;
V_117 [ 0 ] = F_2 ( V_23 [ 0 ] & V_118 ) ;
V_117 [ 1 ] = F_2 ( V_23 [ 1 ] & V_119 ) ;
if ( V_117 [ 1 ] != 0 ) {
V_6 = F_45 ( V_9 , 16 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
* V_6 ++ = F_2 ( 2 ) ;
* V_6 ++ = V_117 [ 0 ] ;
* V_6 ++ = V_117 [ 1 ] ;
} else if ( V_117 [ 0 ] != 0 ) {
V_6 = F_45 ( V_9 , 12 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
* V_6 ++ = F_2 ( 1 ) ;
* V_6 ++ = V_117 [ 0 ] ;
} else {
V_6 = F_45 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
* V_6 ++ = F_2 ( 0 ) ;
}
* V_116 = V_6 ;
return 0 ;
}
static T_1 F_46 ( struct V_8 * V_9 , const T_4 * V_23 , V_55 V_120 )
{
T_1 * V_6 ;
if ( ! ( V_23 [ 0 ] & V_121 ) )
return 0 ;
V_6 = F_45 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_16 ) ;
V_6 = F_47 ( V_6 , V_120 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_8 * V_9 , const T_4 * V_23 , V_55 V_19 )
{
T_1 * V_6 ;
if ( ! ( V_23 [ 0 ] & V_122 ) )
return 0 ;
V_6 = F_45 ( V_9 , 8 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_16 ) ;
V_6 = F_47 ( V_6 , V_19 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_8 * V_9 , const struct V_123 * time )
{
T_1 * V_6 ;
V_6 = F_45 ( V_9 , 12 ) ;
if ( F_9 ( ! V_6 ) )
return F_2 ( V_16 ) ;
V_6 = F_47 ( V_6 , time -> V_124 ) ;
* V_6 = F_2 ( time -> V_125 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_8 * V_9 , const T_4 * V_23 , const struct V_123 * time )
{
if ( ! ( V_23 [ 1 ] & V_126 ) )
return 0 ;
return F_49 ( V_9 , time ) ;
}
static T_1 F_51 ( struct V_8 * V_9 , const T_4 * V_23 , const struct V_123 * time )
{
if ( ! ( V_23 [ 1 ] & V_127 ) )
return 0 ;
return F_49 ( V_9 , time ) ;
}
static T_1 F_52 ( struct V_8 * V_9 , struct V_128 * V_29 )
{
T_1 V_30 ;
V_29 -> V_30 = F_45 ( V_9 , 4 ) ;
if ( F_9 ( V_29 -> V_30 == NULL ) )
return F_2 ( V_16 ) ;
V_30 = F_42 ( V_9 , V_29 -> V_31 , V_29 -> V_32 ) ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
V_29 -> V_39 = F_45 ( V_9 , 4 ) ;
if ( F_9 ( V_29 -> V_39 == NULL ) )
return F_2 ( V_16 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_8 * V_9 , T_4 V_40 , T_1 V_129 )
{
T_1 * V_6 ;
V_6 = F_45 ( V_9 , 8 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_41 ) ;
* V_6 ++ = F_2 ( V_40 ) ;
* V_6 = V_129 ;
return 0 ;
}
static T_1 F_54 ( struct V_1 * V_2 , struct V_8 * V_9 , const struct V_130 * V_129 )
{
T_1 * V_116 = NULL ;
T_1 V_30 = V_129 -> V_30 ;
if ( F_9 ( V_30 != 0 ) )
goto V_69;
V_30 = F_44 ( V_9 , V_129 -> V_23 , & V_116 ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_69;
V_30 = F_46 ( V_9 , V_129 -> V_23 , V_129 -> V_131 ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_69;
V_30 = F_48 ( V_9 , V_129 -> V_23 , V_129 -> V_19 ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_69;
V_30 = F_50 ( V_9 , V_129 -> V_23 , & V_129 -> ctime ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_69;
V_30 = F_51 ( V_9 , V_129 -> V_23 , & V_129 -> V_132 ) ;
* V_116 = F_2 ( ( unsigned int ) ( ( char * ) V_9 -> V_6 - ( char * ) ( V_116 + 1 ) ) ) ;
V_69:
return V_30 ;
}
static T_1 F_55 ( struct V_8 * V_9 ,
const struct V_84 * V_85 )
{
T_1 * V_6 ;
V_6 = F_45 ( V_9 , V_86 ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
memcpy ( V_6 , V_85 , V_86 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_133 * V_129 )
{
T_1 * V_6 ;
T_1 V_30 = V_129 -> V_134 ;
if ( F_9 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_55 ( V_9 , & V_129 -> V_135 ) ;
if ( V_30 )
return V_30 ;
V_6 = F_45 ( V_9 , 4 * sizeof( T_4 ) ) ;
if ( F_9 ( V_6 == NULL ) )
return F_2 ( V_16 ) ;
* V_6 ++ = F_2 ( V_129 -> V_136 ) ;
* V_6 ++ = F_2 ( V_129 -> V_137 ) ;
* V_6 ++ = F_2 ( V_129 -> V_138 ) ;
* V_6 ++ = F_2 ( V_129 -> V_139 ) ;
return 0 ;
}
static T_1
F_57 ( int V_140 , unsigned int V_141 , struct V_142 * * V_40 )
{
if ( V_141 == V_143 ) {
if ( V_140 != 0 )
return F_2 ( V_144 ) ;
} else {
if ( V_140 == 0 )
return F_2 ( V_145 ) ;
}
switch ( V_141 ) {
case V_146 :
case V_147 :
case V_143 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
* V_40 = & V_153 [ V_141 ] ;
break;
case V_154 :
case V_155 :
case V_156 :
case V_157 :
return F_2 ( V_158 ) ;
default:
return F_2 ( V_159 ) ;
}
return F_2 ( V_160 ) ;
}
static void F_58 ( struct V_161 * V_162 ,
struct V_163 * V_164 )
{
struct V_165 * V_166 = & V_162 -> V_167 ;
F_59 ( & V_166 -> V_168 ) ;
F_60 ( V_166 , V_164 ) ;
F_61 ( & V_166 -> V_168 ) ;
}
static void F_62 ( struct V_169 * V_170 )
{
if ( V_170 -> V_164 ) {
F_58 ( V_170 -> V_171 -> V_172 , V_170 -> V_164 ) ;
V_170 -> V_164 = NULL ;
}
}
static T_1
F_57 ( int V_140 , unsigned int V_141 , struct V_142 * * V_40 )
{
return F_2 ( V_38 ) ;
}
static void F_62 ( struct V_169 * V_170 )
{
}
static T_1
F_63 ( int V_140 , unsigned int V_141 , struct V_142 * * V_40 )
{
T_1 V_30 = F_57 ( V_140 , V_141 , V_40 ) ;
if ( V_30 != F_2 ( V_159 ) )
return V_30 ;
if ( V_141 == V_173 )
return F_2 ( V_158 ) ;
return F_2 ( V_159 ) ;
}
static T_1
F_63 ( int V_140 , unsigned int V_141 , struct V_142 * * V_40 )
{
return F_2 ( V_38 ) ;
}
static T_1
F_64 ( unsigned int V_141 , struct V_142 * * V_40 )
{
switch ( V_141 ) {
case V_146 :
case V_147 :
* V_40 = & V_153 [ V_141 ] ;
break;
default:
return F_2 ( V_159 ) ;
}
return F_2 ( V_160 ) ;
}
static T_1 F_65 ( int V_140 , struct V_1 * V_2 ,
struct V_8 * V_174 , void * V_3 ,
struct V_8 * V_175 , void * V_4 ,
struct V_169 * V_170 )
{
struct V_142 * V_40 = & V_153 [ 0 ] ;
unsigned int V_141 ;
T_1 V_30 ;
long V_14 ;
T_1 V_129 ;
V_30 = F_22 ( V_174 , & V_141 ) ;
if ( F_9 ( V_30 ) )
return V_30 ;
switch ( V_170 -> V_34 ) {
case 0 :
V_30 = F_64 ( V_141 , & V_40 ) ;
break;
case 1 :
V_30 = F_57 ( V_140 , V_141 , & V_40 ) ;
break;
case 2 :
V_30 = F_63 ( V_140 , V_141 , & V_40 ) ;
break;
default:
V_30 = F_2 ( V_38 ) ;
}
if ( V_30 == F_2 ( V_159 ) )
V_141 = V_176 ;
if ( V_30 )
goto V_177;
if ( V_170 -> V_178 ) {
V_30 = V_170 -> V_178 ;
goto V_177;
}
V_14 = V_175 -> V_179 - V_175 -> V_6 ;
if ( V_14 > 0 && V_14 < V_180 ) {
V_30 = V_40 -> V_181 ( V_2 , V_174 , V_3 ) ;
if ( F_17 ( V_30 == 0 ) )
V_30 = V_40 -> F_65 ( V_3 , V_4 , V_170 ) ;
} else
V_30 = F_2 ( V_16 ) ;
V_177:
V_129 = F_53 ( V_175 , V_141 , V_30 ) ;
if ( F_9 ( V_129 ) )
return V_129 ;
if ( V_40 -> V_182 != NULL && V_30 == 0 )
V_30 = V_40 -> V_182 ( V_2 , V_175 , V_4 ) ;
return V_30 ;
}
static T_1 F_66 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
struct V_28 V_183 = { 0 } ;
struct V_128 V_184 = { NULL } ;
struct V_8 V_174 , V_175 ;
T_1 * V_6 , V_30 ;
struct V_169 V_170 = {
. V_178 = 0 ,
. V_171 = NULL ,
. V_185 = F_67 ( V_2 ) ,
} ;
unsigned int V_39 = 0 ;
F_68 ( & V_174 , & V_2 -> V_186 , V_2 -> V_186 . V_187 [ 0 ] . V_188 ) ;
V_6 = ( T_1 * ) ( ( char * ) V_2 -> V_189 . V_187 [ 0 ] . V_188 + V_2 -> V_189 . V_187 [ 0 ] . V_190 ) ;
F_69 ( & V_175 , & V_2 -> V_189 , V_6 ) ;
V_30 = F_20 ( & V_174 , & V_183 ) ;
if ( V_30 == F_2 ( V_16 ) )
return V_191 ;
if ( V_183 . V_34 == 0 ) {
V_170 . V_171 = F_70 ( F_67 ( V_2 ) , V_183 . V_36 ) ;
if ( ! V_170 . V_171 || ! F_71 ( V_170 . V_171 , V_2 ) )
goto V_192;
}
V_170 . V_34 = V_183 . V_34 ;
V_184 . V_31 = V_183 . V_31 ;
V_184 . V_32 = V_183 . V_32 ;
if ( F_52 ( & V_175 , & V_184 ) != 0 )
return V_193 ;
while ( V_30 == 0 && V_39 != V_183 . V_39 ) {
V_30 = F_65 ( V_39 , V_2 , & V_174 ,
V_3 , & V_175 , V_4 , & V_170 ) ;
V_39 ++ ;
}
if ( F_9 ( V_30 == F_2 ( V_41 ) ) ) {
V_30 = F_2 ( V_16 ) ;
V_39 -- ;
}
* V_184 . V_30 = V_30 ;
* V_184 . V_39 = F_2 ( V_39 ) ;
F_62 ( & V_170 ) ;
F_72 ( V_170 . V_171 ) ;
return V_194 ;
V_192:
F_21 ( L_6 ) ;
return V_195 ;
}
