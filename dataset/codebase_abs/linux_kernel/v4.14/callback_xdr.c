static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_4 )
{
return F_4 ( V_2 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_4 )
{
return F_6 ( V_2 , V_4 ) ;
}
static T_1 * F_7 ( struct V_5 * V_6 , T_2 V_7 )
{
T_1 * V_4 ;
V_4 = F_8 ( V_6 , V_7 ) ;
if ( F_9 ( V_4 == NULL ) )
F_10 ( V_8 L_1 ) ;
return V_4 ;
}
static T_1 F_11 ( struct V_5 * V_6 , unsigned int * V_9 ,
const char * * V_10 , T_2 V_11 )
{
T_3 V_12 ;
V_12 = F_12 ( V_6 , ( void * * ) V_10 , V_11 ) ;
if ( V_12 < 0 )
return F_13 ( V_13 ) ;
* V_9 = V_12 ;
return 0 ;
}
static T_1 F_14 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
T_1 * V_4 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
V_15 -> V_16 = F_15 ( * V_4 ) ;
if ( V_15 -> V_16 > V_17 )
return F_2 ( V_18 ) ;
V_4 = F_7 ( V_6 , V_15 -> V_16 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
memcpy ( & V_15 -> V_19 [ 0 ] , V_4 , V_15 -> V_16 ) ;
memset ( & V_15 -> V_19 [ V_15 -> V_16 ] , 0 , sizeof( V_15 -> V_19 ) - V_15 -> V_16 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_5 * V_6 , T_4 * V_20 )
{
T_1 * V_4 ;
unsigned int V_21 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
V_21 = F_15 ( * V_4 ) ;
V_4 = F_7 ( V_6 , V_21 << 2 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
if ( F_17 ( V_21 > 0 ) )
V_20 [ 0 ] = F_15 ( * V_4 ++ ) ;
if ( V_21 > 1 )
V_20 [ 1 ] = F_15 ( * V_4 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_5 * V_6 , T_5 * V_22 )
{
T_1 * V_4 ;
V_4 = F_7 ( V_6 , V_23 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
memcpy ( V_22 -> V_19 , V_4 , V_23 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_5 * V_6 , T_5 * V_22 )
{
V_22 -> type = V_24 ;
return F_18 ( V_6 , V_22 ) ;
}
static T_1 F_20 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
T_1 * V_4 ;
T_1 V_27 ;
V_27 = F_11 ( V_6 , & V_26 -> V_28 , & V_26 -> V_29 , V_30 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_4 = F_7 ( V_6 , 12 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
V_26 -> V_31 = F_15 ( * V_4 ++ ) ;
if ( V_26 -> V_31 <= V_32 ) {
V_26 -> V_33 = F_15 ( * V_4 ++ ) ;
} else {
F_21 ( L_2
L_3 ,
V_34 , V_26 -> V_31 ) ;
return F_2 ( V_35 ) ;
}
V_26 -> V_36 = F_15 ( * V_4 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_5 * V_6 , unsigned int * V_37 )
{
T_1 * V_4 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_38 ) ;
* V_37 = F_15 ( * V_4 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 , void * V_39 )
{
struct V_40 * args = V_39 ;
T_1 V_27 ;
V_27 = F_14 ( V_6 , & args -> V_15 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
return F_16 ( V_6 , args -> V_20 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 , void * V_39 )
{
struct V_41 * args = V_39 ;
T_1 * V_4 ;
T_1 V_27 ;
V_27 = F_19 ( V_6 , & args -> V_22 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
args -> V_42 = F_15 ( * V_4 ) ;
return F_14 ( V_6 , & args -> V_15 ) ;
}
static T_1 F_25 ( struct V_5 * V_6 , T_5 * V_22 )
{
V_22 -> type = V_43 ;
return F_18 ( V_6 , V_22 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_5 * V_6 , void * V_39 )
{
struct V_44 * args = V_39 ;
T_1 * V_4 ;
T_1 V_27 = 0 ;
T_4 V_45 ;
V_4 = F_7 ( V_6 , 4 * sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
args -> V_47 = F_15 ( * V_4 ++ ) ;
V_45 = F_15 ( * V_4 ++ ) ;
args -> V_48 = F_15 ( * V_4 ++ ) ;
args -> V_49 = F_15 ( * V_4 ++ ) ;
if ( args -> V_49 == V_50 ) {
args -> V_51 . V_45 = V_45 ;
V_27 = F_14 ( V_6 , & args -> V_52 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_4 = F_7 ( V_6 , 2 * sizeof( V_53 ) ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
V_4 = F_27 ( V_4 , & args -> V_51 . V_54 ) ;
V_4 = F_27 ( V_4 , & args -> V_51 . V_55 ) ;
return F_25 ( V_6 , & args -> V_56 ) ;
} else if ( args -> V_49 == V_57 ) {
V_4 = F_7 ( V_6 , 2 * sizeof( V_53 ) ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
V_4 = F_27 ( V_4 , & args -> V_58 . V_59 ) ;
V_4 = F_27 ( V_4 , & args -> V_58 . V_60 ) ;
} else if ( args -> V_49 != V_61 )
return F_2 ( V_46 ) ;
return 0 ;
}
static
T_1 F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void * V_39 )
{
struct V_62 * args = V_39 ;
T_1 * V_4 ;
T_1 V_27 = 0 ;
T_6 V_63 ;
int V_64 , V_65 ;
args -> V_66 = 0 ;
V_4 = F_7 ( V_6 , sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_67;
}
V_64 = F_15 ( * V_4 ++ ) ;
if ( V_64 <= 0 )
goto V_67;
if ( V_64 > V_68 / sizeof( * args -> V_69 ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_67;
}
args -> V_69 = F_29 ( V_64 , sizeof( * args -> V_69 ) , V_70 ) ;
if ( ! args -> V_69 ) {
V_27 = F_2 ( V_71 ) ;
goto V_67;
}
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
struct V_72 * V_73 = & args -> V_69 [ V_65 ] ;
V_4 = F_7 ( V_6 , ( 4 * sizeof( T_4 ) ) + V_74 ) ;
if ( F_9 ( V_4 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_12;
}
V_63 = F_15 ( * V_4 ++ ) ;
if ( V_63 != 1 ) {
V_27 = F_2 ( V_75 ) ;
goto V_12;
}
V_73 -> V_76 = F_15 ( * V_4 ++ ) ;
if ( V_73 -> V_76 != V_77 &&
V_73 -> V_76 != V_78 ) {
V_27 = F_2 ( V_75 ) ;
goto V_12;
}
V_63 = F_15 ( * V_4 ++ ) ;
if ( ( ( V_73 -> V_76 == V_77 ) &&
( V_63 != V_74 + 8 ) ) ||
( ( V_73 -> V_76 == V_78 ) &&
( V_63 != V_74 + 4 ) ) ) {
V_27 = F_2 ( V_75 ) ;
goto V_12;
}
V_73 -> V_79 = F_15 ( * V_4 ++ ) ;
memcpy ( V_73 -> V_80 . V_19 , V_4 , V_74 ) ;
V_4 += F_30 ( V_74 ) ;
if ( V_73 -> V_79 == V_77 ) {
V_4 = F_7 ( V_6 , sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) ) {
V_27 = F_2 ( V_46 ) ;
goto V_12;
}
V_73 -> V_81 = F_15 ( * V_4 ++ ) ;
} else {
V_73 -> V_81 = 0 ;
}
args -> V_66 ++ ;
F_31 ( L_4 ,
V_34 , V_73 -> V_76 , V_73 -> V_79 ,
V_73 -> V_81 ) ;
}
V_67:
F_31 ( L_5 ,
V_34 , F_15 ( V_27 ) , args -> V_66 ) ;
return V_27 ;
V_12:
F_32 ( args -> V_69 ) ;
goto V_67;
}
static T_1 F_33 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
T_1 * V_4 ;
V_4 = F_7 ( V_6 , V_84 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
memcpy ( V_83 -> V_19 , V_4 , V_84 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_5 * V_6 ,
struct V_85 * V_86 )
{
T_1 * V_4 ;
int V_65 ;
T_1 V_27 ;
V_27 = F_33 ( V_6 , & V_86 -> V_87 ) ;
if ( V_27 )
goto V_67;
V_27 = F_2 ( V_13 ) ;
V_4 = F_7 ( V_6 , sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) )
goto V_67;
V_86 -> V_88 = F_15 ( * V_4 ++ ) ;
if ( V_86 -> V_88 ) {
V_4 = F_7 ( V_6 ,
V_86 -> V_88 * 2 * sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) )
goto V_67;
V_86 -> V_89 = F_29 ( V_86 -> V_88 ,
sizeof( * V_86 -> V_89 ) ,
V_70 ) ;
if ( F_9 ( V_86 -> V_89 == NULL ) )
goto V_67;
for ( V_65 = 0 ; V_65 < V_86 -> V_88 ; V_65 ++ ) {
V_86 -> V_89 [ V_65 ] . V_90 = F_15 ( * V_4 ++ ) ;
V_86 -> V_89 [ V_65 ] . V_91 = F_15 ( * V_4 ++ ) ;
}
}
V_27 = 0 ;
V_67:
return V_27 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void * V_39 )
{
struct V_92 * args = V_39 ;
T_1 * V_4 ;
int V_65 ;
T_1 V_27 ;
V_27 = F_33 ( V_6 , & args -> V_93 ) ;
if ( V_27 )
return V_27 ;
V_4 = F_7 ( V_6 , 5 * sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
args -> V_94 = F_36 ( V_2 ) ;
args -> V_95 = F_15 ( * V_4 ++ ) ;
args -> V_96 = F_15 ( * V_4 ++ ) ;
args -> V_97 = F_15 ( * V_4 ++ ) ;
args -> V_98 = F_15 ( * V_4 ++ ) ;
args -> V_99 = F_15 ( * V_4 ++ ) ;
args -> V_100 = NULL ;
if ( args -> V_99 ) {
args -> V_100 = F_29 ( args -> V_99 ,
sizeof( * args -> V_100 ) ,
V_70 ) ;
if ( F_9 ( args -> V_100 == NULL ) )
return F_2 ( V_13 ) ;
for ( V_65 = 0 ; V_65 < args -> V_99 ; V_65 ++ ) {
V_27 = F_34 ( V_6 , & args -> V_100 [ V_65 ] ) ;
if ( V_27 ) {
args -> V_99 = V_65 ;
goto V_101;
}
}
}
return 0 ;
V_101:
for ( V_65 = 0 ; V_65 < args -> V_99 ; V_65 ++ )
F_32 ( args -> V_100 [ V_65 ] . V_89 ) ;
F_32 ( args -> V_100 ) ;
return V_27 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void * V_39 )
{
struct V_102 * args = V_39 ;
T_4 V_20 [ 2 ] ;
T_1 * V_4 , V_27 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
args -> V_103 = F_15 ( * V_4 ++ ) ;
V_27 = F_16 ( V_6 , V_20 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
args -> V_104 = V_20 [ 0 ] ;
return 0 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void * V_39 )
{
struct V_105 * args = V_39 ;
T_1 * V_4 ;
V_4 = F_7 ( V_6 , 4 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
args -> V_106 = F_15 ( * V_4 ++ ) ;
return 0 ;
}
static T_1 F_39 ( struct V_5 * V_6 , struct V_107 * args )
{
T_1 * V_4 ;
unsigned int V_9 ;
V_4 = F_7 ( V_6 , 12 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
V_4 = F_27 ( V_4 , & args -> V_108 . V_109 ) ;
V_9 = F_40 ( * V_4 ) ;
V_4 = F_7 ( V_6 , V_9 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_46 ) ;
if ( V_9 == 20 ) {
V_4 += 2 ;
args -> V_108 . V_110 = F_40 ( * V_4 ++ ) ;
F_27 ( V_4 , & args -> V_108 . V_111 ) ;
args -> V_112 = true ;
} else {
args -> V_108 . V_110 = 0 ;
args -> V_108 . V_111 = 0 ;
args -> V_112 = false ;
}
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 , void * V_39 )
{
struct V_107 * args = V_39 ;
T_1 V_27 ;
V_27 = F_14 ( V_6 , & args -> V_113 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
return F_39 ( V_6 , args ) ;
}
static T_1 F_42 ( struct V_5 * V_6 , unsigned int V_9 , const char * V_10 )
{
if ( F_9 ( F_43 ( V_6 , V_10 , V_9 ) < 0 ) )
return F_13 ( V_13 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_5 * V_6 , const T_4 * V_20 , T_1 * * V_114 )
{
T_1 V_115 [ 2 ] ;
T_1 * V_4 ;
V_115 [ 0 ] = F_2 ( V_20 [ 0 ] & V_116 ) ;
V_115 [ 1 ] = F_2 ( V_20 [ 1 ] & V_117 ) ;
if ( V_115 [ 1 ] != 0 ) {
V_4 = F_45 ( V_6 , 16 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
* V_4 ++ = F_2 ( 2 ) ;
* V_4 ++ = V_115 [ 0 ] ;
* V_4 ++ = V_115 [ 1 ] ;
} else if ( V_115 [ 0 ] != 0 ) {
V_4 = F_45 ( V_6 , 12 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
* V_4 ++ = F_2 ( 1 ) ;
* V_4 ++ = V_115 [ 0 ] ;
} else {
V_4 = F_45 ( V_6 , 8 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
* V_4 ++ = F_2 ( 0 ) ;
}
* V_114 = V_4 ;
return 0 ;
}
static T_1 F_46 ( struct V_5 * V_6 , const T_4 * V_20 , V_53 V_118 )
{
T_1 * V_4 ;
if ( ! ( V_20 [ 0 ] & V_119 ) )
return 0 ;
V_4 = F_45 ( V_6 , 8 ) ;
if ( F_9 ( ! V_4 ) )
return F_2 ( V_13 ) ;
V_4 = F_47 ( V_4 , V_118 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_5 * V_6 , const T_4 * V_20 , V_53 V_16 )
{
T_1 * V_4 ;
if ( ! ( V_20 [ 0 ] & V_120 ) )
return 0 ;
V_4 = F_45 ( V_6 , 8 ) ;
if ( F_9 ( ! V_4 ) )
return F_2 ( V_13 ) ;
V_4 = F_47 ( V_4 , V_16 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_5 * V_6 , const struct V_121 * time )
{
T_1 * V_4 ;
V_4 = F_45 ( V_6 , 12 ) ;
if ( F_9 ( ! V_4 ) )
return F_2 ( V_13 ) ;
V_4 = F_47 ( V_4 , time -> V_122 ) ;
* V_4 = F_2 ( time -> V_123 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_5 * V_6 , const T_4 * V_20 , const struct V_121 * time )
{
if ( ! ( V_20 [ 1 ] & V_124 ) )
return 0 ;
return F_49 ( V_6 , time ) ;
}
static T_1 F_51 ( struct V_5 * V_6 , const T_4 * V_20 , const struct V_121 * time )
{
if ( ! ( V_20 [ 1 ] & V_125 ) )
return 0 ;
return F_49 ( V_6 , time ) ;
}
static T_1 F_52 ( struct V_5 * V_6 , struct V_126 * V_26 )
{
T_1 V_27 ;
V_26 -> V_27 = F_45 ( V_6 , 4 ) ;
if ( F_9 ( V_26 -> V_27 == NULL ) )
return F_2 ( V_13 ) ;
V_27 = F_42 ( V_6 , V_26 -> V_28 , V_26 -> V_29 ) ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_26 -> V_36 = F_45 ( V_6 , 4 ) ;
if ( F_9 ( V_26 -> V_36 == NULL ) )
return F_2 ( V_13 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_5 * V_6 , T_4 V_37 , T_1 V_127 )
{
T_1 * V_4 ;
V_4 = F_45 ( V_6 , 8 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_38 ) ;
* V_4 ++ = F_2 ( V_37 ) ;
* V_4 = V_127 ;
return 0 ;
}
static T_1 F_54 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const void * V_128 )
{
const struct V_129 * V_127 = V_128 ;
T_1 * V_114 = NULL ;
T_1 V_27 = V_127 -> V_27 ;
if ( F_9 ( V_27 != 0 ) )
goto V_67;
V_27 = F_44 ( V_6 , V_127 -> V_20 , & V_114 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_67;
V_27 = F_46 ( V_6 , V_127 -> V_20 , V_127 -> V_130 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_67;
V_27 = F_48 ( V_6 , V_127 -> V_20 , V_127 -> V_16 ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_67;
V_27 = F_50 ( V_6 , V_127 -> V_20 , & V_127 -> ctime ) ;
if ( F_9 ( V_27 != 0 ) )
goto V_67;
V_27 = F_51 ( V_6 , V_127 -> V_20 , & V_127 -> V_131 ) ;
* V_114 = F_2 ( ( unsigned int ) ( ( char * ) V_6 -> V_4 - ( char * ) ( V_114 + 1 ) ) ) ;
V_67:
return V_27 ;
}
static T_1 F_55 ( struct V_5 * V_6 ,
const struct V_82 * V_83 )
{
T_1 * V_4 ;
V_4 = F_45 ( V_6 , V_84 ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
memcpy ( V_4 , V_83 , V_84 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const void * V_128 )
{
const struct V_132 * V_127 = V_128 ;
T_1 * V_4 ;
T_1 V_27 = V_127 -> V_133 ;
if ( F_9 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_55 ( V_6 , & V_127 -> V_134 ) ;
if ( V_27 )
return V_27 ;
V_4 = F_45 ( V_6 , 4 * sizeof( T_4 ) ) ;
if ( F_9 ( V_4 == NULL ) )
return F_2 ( V_13 ) ;
* V_4 ++ = F_2 ( V_127 -> V_135 ) ;
* V_4 ++ = F_2 ( V_127 -> V_136 ) ;
* V_4 ++ = F_2 ( V_127 -> V_137 ) ;
* V_4 ++ = F_2 ( V_127 -> V_138 ) ;
return 0 ;
}
static T_1
F_57 ( int V_139 , unsigned int V_140 , struct V_141 * * V_37 )
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
* V_37 = & V_152 [ V_140 ] ;
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
static void F_58 ( struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_161 -> V_166 ;
F_59 ( & V_165 -> V_167 ) ;
F_60 ( V_165 , V_163 ) ;
F_61 ( & V_165 -> V_167 ) ;
}
static void F_62 ( struct V_168 * V_169 )
{
if ( V_169 -> V_163 ) {
F_58 ( V_169 -> V_170 -> V_171 , V_169 -> V_163 ) ;
V_169 -> V_163 = NULL ;
}
}
static T_1
F_57 ( int V_139 , unsigned int V_140 , struct V_141 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static void F_62 ( struct V_168 * V_169 )
{
}
static T_1
F_63 ( int V_139 , unsigned int V_140 , struct V_141 * * V_37 )
{
T_1 V_27 = F_57 ( V_139 , V_140 , V_37 ) ;
if ( V_27 != F_2 ( V_158 ) )
return V_27 ;
if ( V_140 == V_172 )
return F_2 ( V_157 ) ;
return F_2 ( V_158 ) ;
}
static T_1
F_63 ( int V_139 , unsigned int V_140 , struct V_141 * * V_37 )
{
return F_2 ( V_35 ) ;
}
static T_1
F_64 ( unsigned int V_140 , struct V_141 * * V_37 )
{
switch ( V_140 ) {
case V_145 :
case V_146 :
* V_37 = & V_152 [ V_140 ] ;
break;
default:
return F_2 ( V_158 ) ;
}
return F_2 ( V_159 ) ;
}
static T_1 F_65 ( int V_139 , struct V_1 * V_2 ,
struct V_5 * V_173 , void * V_39 ,
struct V_5 * V_174 , void * V_128 ,
struct V_168 * V_169 )
{
struct V_141 * V_37 = & V_152 [ 0 ] ;
unsigned int V_140 ;
T_1 V_27 ;
long V_11 ;
T_1 V_127 ;
V_27 = F_22 ( V_173 , & V_140 ) ;
if ( F_9 ( V_27 ) )
return V_27 ;
switch ( V_169 -> V_31 ) {
case 0 :
V_27 = F_64 ( V_140 , & V_37 ) ;
break;
case 1 :
V_27 = F_57 ( V_139 , V_140 , & V_37 ) ;
break;
case 2 :
V_27 = F_63 ( V_139 , V_140 , & V_37 ) ;
break;
default:
V_27 = F_2 ( V_35 ) ;
}
if ( V_27 == F_2 ( V_158 ) )
V_140 = V_175 ;
if ( V_27 )
goto V_176;
if ( V_169 -> V_177 ) {
V_27 = V_169 -> V_177 ;
goto V_176;
}
V_11 = V_174 -> V_178 - V_174 -> V_4 ;
if ( V_11 > 0 && V_11 < V_179 ) {
V_27 = V_37 -> V_180 ( V_2 , V_173 , V_39 ) ;
if ( F_17 ( V_27 == 0 ) )
V_27 = V_37 -> F_65 ( V_39 , V_128 , V_169 ) ;
} else
V_27 = F_2 ( V_13 ) ;
V_176:
V_127 = F_53 ( V_174 , V_140 , V_27 ) ;
if ( F_9 ( V_127 ) )
return V_127 ;
if ( V_37 -> V_181 != NULL && V_27 == 0 )
V_27 = V_37 -> V_181 ( V_2 , V_174 , V_128 ) ;
return V_27 ;
}
static T_1 F_66 ( struct V_1 * V_2 )
{
struct V_25 V_182 = { 0 } ;
struct V_126 V_183 = { NULL } ;
struct V_5 V_173 , V_174 ;
T_1 * V_4 , V_27 ;
struct V_168 V_169 = {
. V_177 = 0 ,
. V_170 = NULL ,
. V_184 = F_67 ( V_2 ) ,
} ;
unsigned int V_36 = 0 ;
F_68 ( & V_173 , & V_2 -> V_185 , V_2 -> V_185 . V_186 [ 0 ] . V_187 ) ;
V_4 = ( T_1 * ) ( ( char * ) V_2 -> V_188 . V_186 [ 0 ] . V_187 + V_2 -> V_188 . V_186 [ 0 ] . V_189 ) ;
F_69 ( & V_174 , & V_2 -> V_188 , V_4 ) ;
V_27 = F_20 ( & V_173 , & V_182 ) ;
if ( V_27 == F_2 ( V_13 ) )
return V_190 ;
if ( V_182 . V_31 == 0 ) {
V_169 . V_170 = F_70 ( F_67 ( V_2 ) , V_182 . V_33 ) ;
if ( ! V_169 . V_170 || ! F_71 ( V_169 . V_170 , V_2 ) )
goto V_191;
}
V_169 . V_31 = V_182 . V_31 ;
V_183 . V_28 = V_182 . V_28 ;
V_183 . V_29 = V_182 . V_29 ;
if ( F_52 ( & V_174 , & V_183 ) != 0 )
return V_192 ;
while ( V_27 == 0 && V_36 != V_182 . V_36 ) {
V_27 = F_65 ( V_36 , V_2 , & V_173 ,
V_2 -> V_193 , & V_174 , V_2 -> V_194 ,
& V_169 ) ;
V_36 ++ ;
}
if ( F_9 ( V_27 == F_2 ( V_38 ) ) ) {
V_27 = F_2 ( V_13 ) ;
V_36 -- ;
}
* V_183 . V_27 = V_27 ;
* V_183 . V_36 = F_2 ( V_36 ) ;
F_62 ( & V_169 ) ;
F_72 ( V_169 . V_170 ) ;
return V_195 ;
V_191:
F_21 ( L_6 ) ;
return V_196 ;
}
