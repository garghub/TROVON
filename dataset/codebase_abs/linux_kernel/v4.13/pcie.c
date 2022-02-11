static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , V_2 -> V_4 ) ) {
F_3 ( V_2 , L_1 ) ;
return - V_5 ;
}
return 0 ;
}
static int
F_4 ( struct V_6 * V_7 , struct V_8 * V_9 ,
T_1 V_10 , int V_11 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_14 V_15 ;
V_15 . V_16 = F_5 ( V_13 -> V_2 , V_9 -> V_17 , V_10 , V_11 ) ;
if ( F_6 ( V_13 -> V_2 , V_15 . V_16 ) ) {
F_7 ( V_7 , ERROR , L_2 ) ;
return - 1 ;
}
V_15 . V_18 = V_10 ;
F_8 ( V_9 , & V_15 ) ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , int V_11 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_14 V_15 ;
F_10 ( V_9 , & V_15 ) ;
F_11 ( V_13 -> V_2 , V_15 . V_16 , V_15 . V_18 , V_11 ) ;
}
static int F_12 ( struct V_6 * V_7 , int V_19 , T_2 V_17 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
F_13 ( V_17 , V_13 -> V_20 + V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , int V_19 , T_2 * V_17 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
* V_17 = F_15 ( V_13 -> V_20 + V_19 ) ;
if ( * V_17 == 0xffffffff )
return 0xffffffff ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
int V_19 , T_3 * V_17 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
* V_17 = F_17 ( V_13 -> V_20 + V_19 ) ;
return 0 ;
}
static bool F_18 ( struct V_6 * V_7 )
{
T_2 V_21 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( ! V_19 -> V_24 )
return true ;
if ( V_13 -> V_25 ) {
V_21 = F_19 ( V_13 -> V_25 ) ;
F_7 ( V_7 , V_26 ,
L_3 ,
V_21 ) ;
if ( V_21 == V_27 )
return true ;
}
return false ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
V_13 = F_22 ( V_29 ) ;
F_23 ( & V_13 -> V_30 ) ;
V_7 = V_13 -> V_7 ;
if ( ! V_7 ) {
F_3 ( V_2 , L_4 ) ;
return 0 ;
}
F_24 ( V_7 ) ;
if ( ! F_25 ( V_7 ) ) {
F_7 ( V_7 , ERROR ,
L_5 ) ;
V_7 -> V_31 = false ;
F_26 ( V_7 ) ;
return - V_32 ;
}
F_27 ( V_7 -> V_33 ) ;
V_7 -> V_34 = true ;
V_7 -> V_31 = false ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
V_13 = F_22 ( V_29 ) ;
if ( ! V_13 -> V_7 ) {
F_3 ( V_2 , L_6 ) ;
return 0 ;
}
V_7 = V_13 -> V_7 ;
if ( ! V_7 -> V_34 ) {
F_7 ( V_7 , V_35 ,
L_7 ) ;
return 0 ;
}
V_7 -> V_34 = false ;
F_29 ( F_30 ( V_7 , V_36 ) ,
V_37 ) ;
F_26 ( V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_28 * V_29 ,
const struct V_38 * V_39 )
{
struct V_12 * V_13 ;
int V_40 ;
F_32 ( L_8 ,
V_29 -> V_41 , V_29 -> V_1 , V_29 -> V_42 ) ;
V_13 = F_33 ( & V_29 -> V_2 , sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 )
return - V_44 ;
F_34 ( & V_13 -> V_30 ) ;
V_13 -> V_2 = V_29 ;
if ( V_39 -> V_45 ) {
struct V_46 * V_17 = ( void * ) V_39 -> V_45 ;
V_13 -> V_23 . V_19 = V_17 -> V_19 ;
V_13 -> V_23 . V_47 = V_17 -> V_47 ;
V_13 -> V_23 . V_48 = V_17 -> V_48 ;
V_13 -> V_23 . V_49 = V_17 -> V_49 ;
V_13 -> V_23 . V_50 = V_17 -> V_50 ;
V_13 -> V_23 . V_51 = V_17 -> V_51 ;
V_13 -> V_23 . V_52 = V_17 -> V_52 ;
F_35 ( & V_13 -> V_53 , V_54 ) ;
}
if ( V_29 -> V_2 . V_4 ) {
V_40 = F_1 ( & V_29 -> V_2 ) ;
if ( V_40 )
return V_40 ;
}
if ( F_36 ( V_13 , & V_13 -> V_30 , & V_55 ,
V_56 , & V_29 -> V_2 ) ) {
F_37 ( L_9 , V_57 ) ;
return - 1 ;
}
return 0 ;
}
static void F_38 ( struct V_28 * V_29 )
{
struct V_12 * V_13 ;
struct V_6 * V_7 ;
struct V_58 * V_59 ;
const struct V_22 * V_19 ;
T_2 V_60 ;
int V_40 ;
V_13 = F_22 ( V_29 ) ;
F_23 ( & V_13 -> V_30 ) ;
V_7 = V_13 -> V_7 ;
if ( ! V_7 || ! V_7 -> V_61 )
return;
V_19 = V_13 -> V_23 . V_19 ;
if ( V_19 )
V_40 = F_14 ( V_7 , V_19 -> V_60 , & V_60 ) ;
else
V_60 = - 1 ;
if ( V_60 == V_62 && ! V_7 -> V_63 ) {
F_39 ( V_7 ) ;
V_59 = F_30 ( V_7 , V_64 ) ;
F_40 ( V_59 ) ;
F_41 ( V_59 , V_65 ) ;
}
F_42 ( V_7 ) ;
}
static void F_43 ( struct V_28 * V_29 )
{
F_38 ( V_29 ) ;
return;
}
static void F_44 ( struct V_28 * V_29 )
{
struct V_12 * V_13 = F_22 ( V_29 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
if ( ! V_7 ) {
F_3 ( & V_29 -> V_2 , L_10 ,
V_57 ) ;
return;
}
F_7 ( V_7 , V_26 ,
L_11 ,
V_57 , V_29 -> V_41 , V_29 -> V_1 , V_29 -> V_42 ) ;
F_45 ( V_7 ) ;
F_46 ( V_66 , & V_13 -> V_67 ) ;
F_46 ( V_68 , & V_13 -> V_67 ) ;
F_7 ( V_7 , V_26 , L_12 , V_57 ) ;
}
static void F_47 ( struct V_28 * V_29 )
{
struct V_12 * V_13 = F_22 ( V_29 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
int V_40 ;
if ( ! V_7 ) {
F_3 ( & V_29 -> V_2 , L_10 ,
V_57 ) ;
return;
}
F_7 ( V_7 , V_26 ,
L_13 ,
V_57 , V_29 -> V_41 , V_29 -> V_1 , V_29 -> V_42 ) ;
V_40 = F_48 ( V_7 ) ;
if ( V_40 )
F_3 ( & V_29 -> V_2 , L_14 , V_40 ) ;
else
F_7 ( V_7 , V_26 , L_12 , V_57 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
int V_69 = 0 ;
while ( F_18 ( V_7 ) ) {
V_69 ++ ;
F_50 ( 10 , 20 ) ;
if ( V_69 == 5000 )
break;
}
return;
}
static void F_51 ( struct V_6 * V_7 ,
T_2 V_70 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
T_3 * V_71 ;
T_2 V_24 , V_72 ;
struct V_8 * V_73 = V_13 -> V_74 ;
for ( V_72 = 0 ; V_72 < V_70 ; V_72 ++ ) {
F_52 ( V_13 -> V_2 ,
F_53 ( V_73 ) ,
sizeof( V_24 ) ,
V_75 ) ;
V_71 = V_73 -> V_17 ;
V_24 = F_19 ( V_71 ) ;
if ( V_24 == V_76 ) {
F_7 ( V_7 , V_26 ,
L_15 , V_72 ) ;
break;
}
F_54 ( V_13 -> V_2 ,
F_53 ( V_73 ) ,
sizeof( V_24 ) ,
V_75 ) ;
F_50 ( 20 , 30 ) ;
}
if ( V_72 >= V_70 )
F_7 ( V_7 , V_26 ,
L_16 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
F_7 ( V_7 , V_77 ,
L_17 ) ;
if ( V_19 -> V_24 )
F_49 ( V_7 ) ;
if ( F_12 ( V_7 , V_19 -> V_60 , V_62 ) ) {
F_7 ( V_7 , ERROR ,
L_18 ) ;
return - 1 ;
}
if ( V_19 -> V_24 ) {
F_49 ( V_7 ) ;
F_7 ( V_7 , V_26 ,
L_19 ) ;
V_7 -> V_78 = V_79 ;
}
return 0 ;
}
static int F_56 ( struct V_6 * V_7 )
{
F_7 ( V_7 , V_80 ,
L_20 ) ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 )
{
if ( F_18 ( V_7 ) ) {
if ( F_12 ( V_7 , V_81 ,
0x00000000 ) ) {
F_7 ( V_7 , ERROR ,
L_21 ) ;
return - 1 ;
}
}
F_58 ( & V_7 -> V_82 , 0 ) ;
return 0 ;
}
static void F_59 ( struct V_6 * V_7 )
{
F_60 ( F_57 ( V_7 ) ) ;
}
static int F_61 ( struct V_6 * V_7 )
{
if ( F_18 ( V_7 ) ) {
if ( F_12 ( V_7 , V_81 ,
V_83 ) ) {
F_7 ( V_7 , ERROR ,
L_22 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_62 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_88 ; V_69 ++ ) {
V_13 -> V_89 [ V_69 ] = NULL ;
if ( V_19 -> V_90 ) {
V_13 -> V_91 [ V_69 ] = ( void * ) V_13 -> V_92 +
( sizeof( * V_87 ) * V_69 ) ;
V_87 = V_13 -> V_91 [ V_69 ] ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else {
V_13 -> V_91 [ V_69 ] = ( void * ) V_13 -> V_92 +
( sizeof( * V_85 ) * V_69 ) ;
V_85 = V_13 -> V_91 [ V_69 ] ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
}
return 0 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_8 * V_9 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
T_4 V_93 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_88 ; V_69 ++ ) {
V_9 = F_64 ( V_94 ,
V_43 ) ;
if ( ! V_9 ) {
F_7 ( V_7 , ERROR ,
L_23 ) ;
F_65 ( V_13 -> V_95 ) ;
return - V_44 ;
}
if ( F_4 ( V_7 , V_9 ,
V_94 ,
V_75 ) )
return - 1 ;
V_93 = F_53 ( V_9 ) ;
F_7 ( V_7 , V_26 ,
L_24 ,
V_9 , V_9 -> V_18 , V_9 -> V_17 , ( T_2 ) V_93 ,
( T_2 ) ( ( V_96 ) V_93 >> 32 ) ) ;
V_13 -> V_97 [ V_69 ] = V_9 ;
if ( V_19 -> V_90 ) {
V_13 -> V_98 [ V_69 ] = ( void * ) V_13 -> V_95 +
( sizeof( * V_87 ) * V_69 ) ;
V_87 = V_13 -> V_98 [ V_69 ] ;
V_87 -> V_99 = V_93 ;
V_87 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_87 -> V_101 = ( V_100 ) V_9 -> V_18 ;
V_87 -> V_11 = V_19 -> V_102 | V_19 -> V_103 ;
V_87 -> V_104 = 0 ;
} else {
V_13 -> V_98 [ V_69 ] = ( void * ) ( V_13 -> V_95 +
( sizeof( * V_85 ) * V_69 ) ) ;
V_85 = V_13 -> V_98 [ V_69 ] ;
V_85 -> V_99 = V_93 ;
V_85 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_85 -> V_11 = 0 ;
}
}
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_105 * V_85 ;
struct V_8 * V_9 ;
T_4 V_93 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_106 ; V_69 ++ ) {
V_9 = F_67 ( V_107 ) ;
if ( ! V_9 ) {
F_7 ( V_7 , ERROR ,
L_25 ) ;
F_65 ( V_13 -> V_108 ) ;
return - V_44 ;
}
F_68 ( V_9 , V_107 ) ;
if ( F_4 ( V_7 , V_9 , V_107 ,
V_75 ) )
return - 1 ;
V_93 = F_53 ( V_9 ) ;
F_7 ( V_7 , V_77 ,
L_26 ,
V_9 , V_9 -> V_18 , V_9 -> V_17 , ( T_2 ) V_93 ,
( T_2 ) ( ( V_96 ) V_93 >> 32 ) ) ;
V_13 -> V_109 [ V_69 ] = V_9 ;
V_13 -> V_110 [ V_69 ] = ( void * ) ( V_13 -> V_108 +
( sizeof( * V_85 ) * V_69 ) ) ;
V_85 = V_13 -> V_110 [ V_69 ] ;
V_85 -> V_99 = V_93 ;
V_85 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_85 -> V_11 = 0 ;
}
return 0 ;
}
static void F_69 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_8 * V_9 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_88 ; V_69 ++ ) {
if ( V_19 -> V_90 ) {
V_87 = V_13 -> V_91 [ V_69 ] ;
if ( V_13 -> V_89 [ V_69 ] ) {
V_9 = V_13 -> V_89 [ V_69 ] ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
F_70 ( V_9 ) ;
}
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else {
V_85 = V_13 -> V_91 [ V_69 ] ;
if ( V_13 -> V_89 [ V_69 ] ) {
V_9 = V_13 -> V_89 [ V_69 ] ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
F_70 ( V_9 ) ;
}
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
V_13 -> V_89 [ V_69 ] = NULL ;
}
F_58 ( & V_7 -> V_82 , 0 ) ;
return;
}
static void F_71 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_8 * V_9 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_88 ; V_69 ++ ) {
if ( V_19 -> V_90 ) {
V_87 = V_13 -> V_98 [ V_69 ] ;
if ( V_13 -> V_97 [ V_69 ] ) {
V_9 = V_13 -> V_97 [ V_69 ] ;
F_9 ( V_7 , V_9 ,
V_75 ) ;
F_70 ( V_9 ) ;
}
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else {
V_85 = V_13 -> V_98 [ V_69 ] ;
if ( V_13 -> V_97 [ V_69 ] ) {
V_9 = V_13 -> V_97 [ V_69 ] ;
F_9 ( V_7 , V_9 ,
V_75 ) ;
F_70 ( V_9 ) ;
}
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
V_13 -> V_97 [ V_69 ] = NULL ;
}
return;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_105 * V_85 ;
struct V_8 * V_9 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_106 ; V_69 ++ ) {
V_85 = V_13 -> V_110 [ V_69 ] ;
if ( V_13 -> V_109 [ V_69 ] ) {
V_9 = V_13 -> V_109 [ V_69 ] ;
F_9 ( V_7 , V_9 ,
V_75 ) ;
F_70 ( V_9 ) ;
}
V_13 -> V_109 [ V_69 ] = NULL ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
return;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
V_13 -> V_112 = 0 ;
if ( V_19 -> V_90 )
V_13 -> V_113 = 0 ;
else
V_13 -> V_113 |= V_19 -> V_114 ;
if ( V_19 -> V_90 )
V_13 -> V_115 = sizeof( struct V_86 ) *
V_88 ;
else
V_13 -> V_115 = sizeof( struct V_84 ) *
V_88 ;
F_7 ( V_7 , V_26 ,
L_27 ,
V_13 -> V_115 ) ;
V_13 -> V_92 = F_74 ( V_13 -> V_2 ,
V_13 -> V_115 ,
& V_13 -> V_116 ) ;
if ( ! V_13 -> V_92 ) {
F_7 ( V_7 , ERROR ,
L_28 ,
V_13 -> V_115 ) ;
return - V_44 ;
}
F_7 ( V_7 , V_117 ,
L_29 ,
V_13 -> V_92 , ( unsigned int ) V_13 -> V_116 ,
( T_2 ) ( ( V_96 ) V_13 -> V_116 >> 32 ) ,
V_13 -> V_115 ) ;
return F_62 ( V_7 ) ;
}
static int F_75 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
F_69 ( V_7 ) ;
if ( V_13 -> V_92 )
F_76 ( V_13 -> V_2 , V_13 -> V_115 ,
V_13 -> V_92 ,
V_13 -> V_116 ) ;
V_13 -> V_115 = 0 ;
V_13 -> V_112 = 0 ;
V_13 -> V_113 = 0 | V_19 -> V_114 ;
V_13 -> V_92 = NULL ;
V_13 -> V_116 = 0 ;
return 0 ;
}
static int F_77 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
V_13 -> V_118 = 0 ;
V_13 -> V_119 = V_19 -> V_120 ;
if ( V_19 -> V_90 )
V_13 -> V_121 = sizeof( struct V_86 ) *
V_88 ;
else
V_13 -> V_121 = sizeof( struct V_84 ) *
V_88 ;
F_7 ( V_7 , V_26 ,
L_30 ,
V_13 -> V_121 ) ;
V_13 -> V_95 = F_74 ( V_13 -> V_2 ,
V_13 -> V_121 ,
& V_13 -> V_122 ) ;
if ( ! V_13 -> V_95 ) {
F_7 ( V_7 , ERROR ,
L_28 ,
V_13 -> V_121 ) ;
return - V_44 ;
}
F_7 ( V_7 , V_117 ,
L_31 ,
V_13 -> V_95 , ( T_2 ) V_13 -> V_122 ,
( T_2 ) ( ( V_96 ) V_13 -> V_122 >> 32 ) ,
V_13 -> V_121 ) ;
return F_63 ( V_7 ) ;
}
static int F_78 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
F_71 ( V_7 ) ;
if ( V_13 -> V_95 )
F_76 ( V_13 -> V_2 , V_13 -> V_121 ,
V_13 -> V_95 ,
V_13 -> V_122 ) ;
V_13 -> V_121 = 0 ;
V_13 -> V_118 = 0 ;
V_13 -> V_119 = 0 | V_19 -> V_120 ;
V_13 -> V_95 = NULL ;
V_13 -> V_122 = 0 ;
return 0 ;
}
static int F_79 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
V_13 -> V_123 = 0 ;
V_13 -> V_124 = V_19 -> V_125 ;
V_13 -> V_126 = sizeof( struct V_105 ) *
V_106 ;
F_7 ( V_7 , V_26 ,
L_32 ,
V_13 -> V_126 ) ;
V_13 -> V_108 = F_74 ( V_13 -> V_2 ,
V_13 -> V_126 ,
& V_13 -> V_127 ) ;
if ( ! V_13 -> V_108 ) {
F_7 ( V_7 , ERROR ,
L_28 ,
V_13 -> V_126 ) ;
return - V_44 ;
}
F_7 ( V_7 , V_77 ,
L_33 ,
V_13 -> V_108 , ( T_2 ) V_13 -> V_127 ,
( T_2 ) ( ( V_96 ) V_13 -> V_127 >> 32 ) ,
V_13 -> V_126 ) ;
return F_66 ( V_7 ) ;
}
static int F_80 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
F_72 ( V_7 ) ;
if ( V_13 -> V_108 )
F_76 ( V_13 -> V_2 , V_13 -> V_126 ,
V_13 -> V_108 ,
V_13 -> V_127 ) ;
V_13 -> V_123 = 0 ;
V_13 -> V_124 = 0 | V_19 -> V_125 ;
V_13 -> V_126 = 0 ;
V_13 -> V_108 = NULL ;
V_13 -> V_127 = 0 ;
return 0 ;
}
static int F_81 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_8 * V_9 ;
V_9 = F_67 ( V_128 ) ;
if ( ! V_9 ) {
F_7 ( V_7 , ERROR ,
L_34 ) ;
return - V_44 ;
}
F_68 ( V_9 , V_128 ) ;
if ( F_4 ( V_7 , V_9 , V_128 ,
V_75 ) )
return - 1 ;
V_13 -> V_74 = V_9 ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 )
{
struct V_12 * V_13 ;
if ( ! V_7 )
return 0 ;
V_13 = V_7 -> V_13 ;
if ( V_13 && V_13 -> V_74 ) {
F_9 ( V_7 , V_13 -> V_74 ,
V_75 ) ;
F_70 ( V_13 -> V_74 ) ;
}
if ( V_13 && V_13 -> V_129 ) {
F_9 ( V_7 , V_13 -> V_129 ,
V_111 ) ;
F_70 ( V_13 -> V_129 ) ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
T_2 V_130 ;
V_13 -> V_25 = F_74 ( V_13 -> V_2 , sizeof( T_2 ) ,
& V_13 -> V_131 ) ;
if ( ! V_13 -> V_25 ) {
F_7 ( V_7 , ERROR ,
L_35 ) ;
return - V_44 ;
}
V_130 = V_27 ;
F_84 ( V_130 , V_13 -> V_25 ) ;
F_7 ( V_7 , V_26 ,
L_36 ,
F_85 ( V_13 -> V_25 ) ) ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
struct V_12 * V_13 ;
if ( ! V_7 )
return 0 ;
V_13 = V_7 -> V_13 ;
if ( V_13 && V_13 -> V_25 ) {
F_76 ( V_13 -> V_2 , sizeof( T_2 ) ,
V_13 -> V_25 ,
V_13 -> V_131 ) ;
V_13 -> V_25 = NULL ;
}
return 0 ;
}
static int F_87 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( ! F_88 ( V_13 , V_13 -> V_113 ) ) {
V_13 -> V_132 = 1 ;
if ( F_12 ( V_7 , V_133 ,
V_134 ) ) {
F_7 ( V_7 , ERROR ,
L_37 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
T_2 V_135 , V_136 , V_137 , V_138 = 0 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( ! F_18 ( V_7 ) )
F_55 ( V_7 ) ;
if ( F_14 ( V_7 , V_19 -> V_139 , & V_136 ) ) {
F_7 ( V_7 , ERROR ,
L_38 ) ;
return - 1 ;
}
F_7 ( V_7 , V_117 ,
L_39 ,
V_13 -> V_113 , V_136 ) ;
V_137 = V_88 << V_19 -> V_140 ;
while ( ( ( V_13 -> V_113 & V_19 -> V_141 ) !=
( V_136 & V_19 -> V_141 ) ) ||
( ( V_13 -> V_113 & V_19 -> V_114 ) !=
( V_136 & V_19 -> V_114 ) ) ) {
V_135 = ( V_13 -> V_113 & V_19 -> V_141 ) >>
V_19 -> V_140 ;
V_9 = V_13 -> V_89 [ V_135 ] ;
if ( V_9 ) {
F_7 ( V_7 , V_117 ,
L_40 ,
V_9 , V_135 ) ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
V_138 ++ ;
if ( V_13 -> V_132 )
F_90 ( V_7 , V_9 , 0 ,
- 1 ) ;
else
F_90 ( V_7 , V_9 , 0 , 0 ) ;
F_91 ( & V_7 -> V_82 ) ;
}
V_13 -> V_89 [ V_135 ] = NULL ;
if ( V_19 -> V_90 ) {
V_87 = V_13 -> V_91 [ V_135 ] ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else {
V_85 = V_13 -> V_91 [ V_135 ] ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
switch ( V_13 -> V_2 -> V_1 ) {
case V_142 :
V_13 -> V_113 ++ ;
break;
case V_143 :
case V_144 :
V_13 -> V_113 += V_19 -> V_145 ;
break;
}
if ( ( V_13 -> V_113 & V_19 -> V_141 ) == V_137 )
V_13 -> V_113 = ( ( V_13 -> V_113 &
V_19 -> V_114 ) ^
V_19 -> V_114 ) ;
}
if ( V_138 )
V_7 -> V_146 = false ;
if ( V_13 -> V_132 ) {
if ( F_88 ( V_13 , V_13 -> V_113 ) )
V_13 -> V_132 = 0 ;
else
F_87 ( V_7 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_147 * V_148 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
T_2 V_149 , V_137 , V_150 ;
int V_40 ;
T_4 V_93 ;
struct V_84 * V_85 = NULL ;
struct V_86 * V_87 = NULL ;
if ( ! ( V_9 -> V_17 && V_9 -> V_18 ) ) {
F_7 ( V_7 , ERROR ,
L_41 ,
V_57 , V_9 -> V_17 , V_9 -> V_18 ) ;
return - 1 ;
}
if ( ! F_18 ( V_7 ) )
F_55 ( V_7 ) ;
V_137 = V_88 << V_19 -> V_140 ;
F_7 ( V_7 , V_117 ,
L_42 ,
V_13 -> V_113 , V_13 -> V_112 ) ;
if ( F_93 ( V_13 ) ) {
T_3 * V_151 ;
V_7 -> V_146 = true ;
V_151 = V_9 -> V_17 ;
F_94 ( ( V_100 ) V_9 -> V_18 , V_151 + 0 ) ;
F_94 ( V_152 , V_151 + 2 ) ;
if ( F_4 ( V_7 , V_9 , V_9 -> V_18 ,
V_111 ) )
return - 1 ;
V_149 = ( V_13 -> V_112 & V_19 -> V_141 ) >> V_19 -> V_140 ;
V_93 = F_53 ( V_9 ) ;
V_13 -> V_89 [ V_149 ] = V_9 ;
F_95 ( & V_7 -> V_82 ) ;
if ( V_19 -> V_90 ) {
V_87 = V_13 -> V_91 [ V_149 ] ;
V_87 -> V_99 = V_93 ;
V_87 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_87 -> V_101 = ( V_100 ) V_9 -> V_18 ;
V_87 -> V_104 = 0 ;
V_87 -> V_11 = V_153 |
V_154 ;
} else {
V_85 = V_13 -> V_91 [ V_149 ] ;
V_85 -> V_99 = V_93 ;
V_85 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_85 -> V_11 = V_153 |
V_154 ;
}
switch ( V_13 -> V_2 -> V_1 ) {
case V_142 :
V_13 -> V_112 ++ ;
break;
case V_143 :
case V_144 :
V_13 -> V_112 += V_19 -> V_145 ;
break;
}
if ( ( V_13 -> V_112 & V_19 -> V_141 ) == V_137 )
V_13 -> V_112 = ( ( V_13 -> V_112 &
V_19 -> V_114 ) ^
V_19 -> V_114 ) ;
V_150 = V_13 -> V_119 & V_19 -> V_155 ;
if ( F_12 ( V_7 , V_19 -> V_156 ,
V_13 -> V_112 | V_150 ) ) {
F_7 ( V_7 , ERROR ,
L_43 ) ;
V_40 = - 1 ;
goto V_157;
}
if ( ( F_93 ( V_13 ) ) &&
V_148 -> V_158 ) {
F_7 ( V_7 , V_117 ,
L_44 ) ;
V_7 -> V_146 = false ;
} else {
if ( F_12 ( V_7 , V_133 ,
V_134 ) ) {
F_7 ( V_7 , ERROR ,
L_45 ) ;
V_40 = - 1 ;
goto V_157;
}
}
F_7 ( V_7 , V_117 ,
L_46
L_47 ,
V_13 -> V_113 , V_13 -> V_112 ) ;
} else {
F_7 ( V_7 , V_117 ,
L_48 ) ;
V_7 -> V_146 = true ;
if ( F_12 ( V_7 , V_133 ,
V_134 ) )
F_7 ( V_7 , ERROR ,
L_49 ) ;
return - V_159 ;
}
return - V_160 ;
V_157:
F_9 ( V_7 , V_9 , V_111 ) ;
V_13 -> V_89 [ V_149 ] = NULL ;
F_91 ( & V_7 -> V_82 ) ;
if ( V_19 -> V_90 )
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
else
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
return V_40 ;
}
static int F_96 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
T_2 V_161 , V_162 , V_163 ;
T_4 V_93 ;
int V_40 = 0 ;
struct V_8 * V_164 = NULL ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
if ( ! F_18 ( V_7 ) )
F_55 ( V_7 ) ;
if ( F_14 ( V_7 , V_19 -> V_165 , & V_161 ) ) {
F_7 ( V_7 , ERROR ,
L_50 ) ;
V_40 = - 1 ;
goto V_166;
}
V_13 -> V_118 = V_161 ;
while ( ( ( V_161 & V_19 -> V_167 ) !=
( V_13 -> V_119 & V_19 -> V_167 ) ) ||
( ( V_161 & V_19 -> V_120 ) ==
( V_13 -> V_119 & V_19 -> V_120 ) ) ) {
struct V_8 * V_168 ;
V_100 V_169 ;
V_162 = V_13 -> V_119 & V_19 -> V_167 ;
V_168 = V_13 -> V_97 [ V_162 ] ;
if ( ! V_168 )
return - V_44 ;
F_9 ( V_7 , V_168 , V_75 ) ;
V_13 -> V_97 [ V_162 ] = NULL ;
V_169 = F_97 ( V_168 -> V_17 ) ;
if ( F_60 ( V_169 <= V_7 -> V_170 ||
V_169 > V_94 ) ) {
F_7 ( V_7 , ERROR ,
L_51 ,
V_169 , V_13 -> V_119 , V_161 ) ;
F_70 ( V_168 ) ;
} else {
F_68 ( V_168 , V_169 ) ;
F_7 ( V_7 , V_117 ,
L_52 ,
V_13 -> V_119 , V_161 , V_169 ) ;
F_98 ( V_168 , V_7 -> V_170 ) ;
if ( V_7 -> V_171 ) {
F_99 ( & V_7 -> V_172 , V_168 ) ;
V_7 -> V_173 = true ;
F_95 ( & V_7 -> V_174 ) ;
} else {
F_100 ( V_7 , V_168 ) ;
}
}
V_164 = F_64 ( V_94 ,
V_43 ) ;
if ( ! V_164 ) {
F_7 ( V_7 , ERROR ,
L_53 ) ;
return - V_44 ;
}
if ( F_4 ( V_7 , V_164 ,
V_94 ,
V_75 ) )
return - 1 ;
V_93 = F_53 ( V_164 ) ;
F_7 ( V_7 , V_26 ,
L_54 ,
V_164 , V_162 ) ;
V_13 -> V_97 [ V_162 ] = V_164 ;
if ( V_19 -> V_90 ) {
V_87 = V_13 -> V_98 [ V_162 ] ;
V_87 -> V_99 = V_93 ;
V_87 -> V_18 = V_164 -> V_18 ;
V_87 -> V_101 = V_164 -> V_18 ;
V_87 -> V_104 = 0 ;
V_87 -> V_11 = V_19 -> V_103 | V_19 -> V_102 ;
} else {
V_85 = V_13 -> V_98 [ V_162 ] ;
V_85 -> V_99 = V_93 ;
V_85 -> V_18 = V_164 -> V_18 ;
V_85 -> V_11 = 0 ;
}
if ( ( ++ V_13 -> V_119 & V_19 -> V_167 ) ==
V_88 ) {
V_13 -> V_119 = ( ( V_13 -> V_119 &
V_19 -> V_120 ) ^
V_19 -> V_120 ) ;
}
F_7 ( V_7 , V_117 ,
L_55 ,
V_13 -> V_119 , V_161 ) ;
V_163 = V_13 -> V_112 & V_19 -> V_175 ;
if ( F_12 ( V_7 , V_19 -> V_176 ,
V_13 -> V_119 | V_163 ) ) {
F_7 ( V_7 , V_117 ,
L_56 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( F_14 ( V_7 , V_19 -> V_165 , & V_161 ) ) {
F_7 ( V_7 , ERROR ,
L_50 ) ;
V_40 = - 1 ;
goto V_166;
}
F_7 ( V_7 , V_117 ,
L_57 ) ;
V_13 -> V_118 = V_161 ;
}
V_166:
return V_40 ;
}
static int
F_101 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
T_4 V_93 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( ! ( V_9 -> V_17 && V_9 -> V_18 ) ) {
F_7 ( V_7 , ERROR ,
L_58 ,
V_57 , V_9 -> V_17 , V_9 -> V_18 ) ;
return - 1 ;
}
if ( F_4 ( V_7 , V_9 , V_9 -> V_18 , V_111 ) )
return - 1 ;
V_93 = F_53 ( V_9 ) ;
if ( F_12 ( V_7 , V_19 -> V_177 , ( T_2 ) V_93 ) ) {
F_7 ( V_7 , ERROR ,
L_59 ,
V_57 ) ;
F_9 ( V_7 , V_9 , V_111 ) ;
return - 1 ;
}
if ( F_12 ( V_7 , V_19 -> V_178 ,
( T_2 ) ( ( V_96 ) V_93 >> 32 ) ) ) {
F_7 ( V_7 , ERROR ,
L_59 ,
V_57 ) ;
F_9 ( V_7 , V_9 , V_111 ) ;
return - 1 ;
}
if ( F_12 ( V_7 , V_19 -> V_179 , V_9 -> V_18 ) ) {
F_7 ( V_7 , ERROR ,
L_60 ,
V_57 ) ;
F_9 ( V_7 , V_9 , V_111 ) ;
return - 1 ;
}
if ( F_12 ( V_7 , V_133 ,
V_180 ) ) {
F_7 ( V_7 , ERROR ,
L_61 , V_57 ) ;
F_9 ( V_7 , V_9 , V_111 ) ;
return - 1 ;
}
return 0 ;
}
static int F_102 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_181 = V_13 -> V_112 & V_19 -> V_175 ;
if ( F_12 ( V_7 , V_19 -> V_176 , V_13 -> V_119 |
V_181 ) ) {
F_7 ( V_7 , ERROR ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_103 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 = 0 ;
T_4 V_182 , V_183 ;
T_3 * V_151 = ( T_3 * ) V_9 -> V_17 ;
if ( ! ( V_9 -> V_17 && V_9 -> V_18 ) ) {
F_7 ( V_7 , ERROR ,
L_62 ,
V_57 , V_9 -> V_17 , V_9 -> V_18 ) ;
return - 1 ;
}
if ( ! V_13 -> V_74 ) {
F_7 ( V_7 , ERROR ,
L_63 ) ;
return - V_159 ;
}
if ( ! F_18 ( V_7 ) )
F_55 ( V_7 ) ;
V_7 -> V_184 = true ;
F_94 ( ( V_100 ) V_9 -> V_18 , & V_151 [ 0 ] ) ;
F_94 ( V_185 , & V_151 [ 2 ] ) ;
if ( F_4 ( V_7 , V_9 , V_9 -> V_18 , V_111 ) )
return - 1 ;
V_13 -> V_129 = V_9 ;
F_104 ( V_9 ) ;
if ( V_13 -> V_74 ) {
V_183 = F_53 ( V_13 -> V_74 ) ;
if ( F_12 ( V_7 , V_19 -> V_186 ,
( T_2 ) V_183 ) ) {
F_7 ( V_7 , ERROR ,
L_64 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( F_12 ( V_7 , V_19 -> V_187 ,
( T_2 ) ( ( V_96 ) V_183 >> 32 ) ) ) {
F_7 ( V_7 , ERROR ,
L_64 ) ;
V_40 = - 1 ;
goto V_166;
}
}
V_182 = F_53 ( V_13 -> V_129 ) ;
if ( F_12 ( V_7 , V_19 -> V_177 ,
( T_2 ) V_182 ) ) {
F_7 ( V_7 , ERROR ,
L_64 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( F_12 ( V_7 , V_19 -> V_178 ,
( T_2 ) ( ( V_96 ) V_182 >> 32 ) ) ) {
F_7 ( V_7 , ERROR ,
L_64 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( F_12 ( V_7 , V_19 -> V_179 ,
V_13 -> V_129 -> V_18 ) ) {
F_7 ( V_7 , ERROR ,
L_65 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( F_12 ( V_7 , V_133 ,
V_180 ) ) {
F_7 ( V_7 , ERROR ,
L_66 ) ;
V_40 = - 1 ;
goto V_166;
}
V_166:
if ( V_40 )
V_7 -> V_184 = false ;
return 0 ;
}
static int F_105 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_8 * V_9 = V_13 -> V_74 ;
int V_72 = 0 ;
V_100 V_169 ;
F_7 ( V_7 , V_80 ,
L_67 ) ;
if ( V_7 -> V_188 )
F_9 ( V_7 , V_9 , V_75 ) ;
else
F_52 ( V_13 -> V_2 ,
F_53 ( V_9 ) ,
V_128 ,
V_75 ) ;
if ( V_13 -> V_129 ) {
F_9 ( V_7 , V_13 -> V_129 ,
V_111 ) ;
F_70 ( V_13 -> V_129 ) ;
V_13 -> V_129 = NULL ;
}
V_169 = F_97 ( V_9 -> V_17 ) ;
F_68 ( V_9 , V_128 - V_9 -> V_18 ) ;
F_106 ( V_9 , V_169 ) ;
if ( ! V_7 -> V_188 ) {
if ( V_7 -> V_78 == V_189 ) {
F_54 ( V_13 -> V_2 ,
F_53 ( V_9 ) ,
V_190 ,
V_75 ) ;
if ( F_12 ( V_7 ,
V_133 ,
V_191 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
F_51 ( V_7 ,
V_192 ) ;
F_9 ( V_7 , V_9 ,
V_75 ) ;
F_98 ( V_9 , V_7 -> V_170 ) ;
while ( V_19 -> V_24 && ( V_72 ++ < 10 ) &&
F_18 ( V_7 ) )
F_50 ( 50 , 60 ) ;
F_61 ( V_7 ) ;
F_107 ( V_7 , V_9 -> V_17 ,
V_9 -> V_18 ) ;
} else {
F_7 ( V_7 , ERROR ,
L_69 ) ;
}
memcpy ( V_7 -> V_193 , V_9 -> V_17 ,
F_108 ( T_2 , V_194 , V_9 -> V_18 ) ) ;
F_109 ( V_9 , V_7 -> V_170 ) ;
if ( F_4 ( V_7 , V_9 , V_128 ,
V_75 ) )
return - 1 ;
} else if ( F_18 ( V_7 ) ) {
F_98 ( V_9 , V_7 -> V_170 ) ;
V_7 -> V_188 -> V_195 = V_9 ;
V_7 -> V_196 = true ;
V_13 -> V_74 = NULL ;
if ( F_12 ( V_7 , V_19 -> V_186 , 0 ) ) {
F_7 ( V_7 , ERROR ,
L_70 ) ;
return - 1 ;
}
if ( F_12 ( V_7 , V_19 -> V_187 , 0 ) ) {
F_7 ( V_7 , ERROR ,
L_71 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( V_9 ) {
V_13 -> V_74 = V_9 ;
F_109 ( V_13 -> V_74 , V_7 -> V_170 ) ;
if ( F_4 ( V_7 , V_9 , V_128 ,
V_75 ) )
return - 1 ;
}
return 0 ;
}
static int F_111 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
T_2 V_136 = V_13 -> V_124 & V_197 ;
T_2 V_161 , V_198 ;
struct V_105 * V_85 ;
if ( ! F_18 ( V_7 ) )
F_55 ( V_7 ) ;
if ( V_7 -> V_199 ) {
F_7 ( V_7 , V_77 ,
L_72
L_73 ) ;
return 0 ;
}
if ( V_136 >= V_106 ) {
F_7 ( V_7 , ERROR ,
L_74 ) ;
return - 1 ;
}
if ( F_14 ( V_7 , V_19 -> V_200 , & V_161 ) ) {
F_7 ( V_7 , ERROR ,
L_75 ) ;
return - 1 ;
}
F_7 ( V_7 , V_77 ,
L_76 ,
V_13 -> V_124 , V_161 ) ;
if ( ( ( V_161 & V_197 ) != ( V_13 -> V_124
& V_197 ) ) ||
( ( V_161 & V_19 -> V_125 ) ==
( V_13 -> V_124 & V_19 -> V_125 ) ) ) {
struct V_8 * V_201 ;
T_5 V_202 = 0 ;
V_100 V_203 ;
F_7 ( V_7 , V_26 ,
L_77 , V_136 ) ;
V_201 = V_13 -> V_109 [ V_136 ] ;
F_9 ( V_7 , V_201 , V_75 ) ;
V_13 -> V_109 [ V_136 ] = NULL ;
V_85 = V_13 -> V_110 [ V_136 ] ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
V_198 = F_19 (
& V_201 -> V_17 [ V_7 -> V_170 ] ) ;
V_7 -> V_204 = V_198 ;
memcpy ( & V_202 , V_201 -> V_17 , sizeof( T_5 ) ) ;
V_203 = F_112 ( V_202 ) ;
F_106 ( V_201 , V_203 ) ;
F_98 ( V_201 , V_7 -> V_170 ) ;
F_7 ( V_7 , V_77 ,
L_78 , V_203 ) ;
if ( ( V_203 > 0 ) && ( V_203 < V_107 ) )
memcpy ( V_7 -> V_205 , V_201 -> V_17 +
V_206 , V_203 -
V_206 ) ;
V_7 -> V_199 = true ;
V_7 -> V_207 = V_201 ;
} else {
if ( F_12 ( V_7 , V_133 ,
V_208 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_113 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 = 0 ;
T_2 V_136 = V_13 -> V_124 & V_197 ;
T_2 V_161 ;
struct V_105 * V_85 ;
if ( ! V_9 )
return 0 ;
if ( V_136 >= V_106 ) {
F_7 ( V_7 , ERROR ,
L_79 ,
V_136 ) ;
return - V_5 ;
}
if ( F_14 ( V_7 , V_19 -> V_200 , & V_161 ) ) {
F_7 ( V_7 , ERROR ,
L_80 ) ;
return - 1 ;
}
if ( ! V_13 -> V_109 [ V_136 ] ) {
F_109 ( V_9 , V_7 -> V_170 ) ;
F_68 ( V_9 , V_107 - V_9 -> V_18 ) ;
if ( F_4 ( V_7 , V_9 ,
V_107 ,
V_75 ) )
return - 1 ;
V_13 -> V_109 [ V_136 ] = V_9 ;
V_85 = V_13 -> V_110 [ V_136 ] ;
V_85 -> V_99 = F_53 ( V_9 ) ;
V_85 -> V_18 = ( V_100 ) V_9 -> V_18 ;
V_85 -> V_11 = 0 ;
V_9 = NULL ;
} else {
F_7 ( V_7 , ERROR ,
L_81 ,
V_136 , V_13 -> V_109 [ V_136 ] , V_9 ) ;
}
if ( ( ++ V_13 -> V_124 & V_197 ) == V_106 ) {
V_13 -> V_124 = ( ( V_13 -> V_124 &
V_19 -> V_125 ) ^
V_19 -> V_125 ) ;
}
F_7 ( V_7 , V_77 ,
L_82 ,
V_13 -> V_124 , V_161 ) ;
if ( F_12 ( V_7 , V_19 -> V_209 ,
V_13 -> V_124 ) ) {
F_7 ( V_7 , ERROR ,
L_83 ) ;
return - 1 ;
}
F_7 ( V_7 , V_77 ,
L_84 ) ;
V_40 = F_111 ( V_7 ) ;
return V_40 ;
}
static int F_114 ( struct V_6 * V_7 ,
const void * V_210 , T_2 V_211 ) {
const struct V_212 * V_213 ;
T_2 V_104 = 0 , V_202 , V_214 ;
int V_40 = 0 ;
bool V_215 = false ;
while ( 1 ) {
if ( V_104 + sizeof( V_213 -> V_216 ) < sizeof( V_213 -> V_216 ) ||
V_104 + sizeof( V_213 -> V_216 ) >= V_211 ) {
F_7 ( V_7 , ERROR ,
L_85 ) ;
V_40 = - 1 ;
goto V_166;
}
V_213 = V_210 + V_104 ;
V_214 = F_115 ( V_213 -> V_216 . V_214 ) ;
V_202 = F_115 ( V_213 -> V_216 . V_217 ) ;
V_104 += sizeof( V_213 -> V_216 ) ;
switch ( V_214 ) {
case V_218 :
if ( ! V_215 ) {
F_7 ( V_7 , ERROR ,
L_86 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_87 ) ;
V_40 = - 1 ;
goto V_166;
}
V_104 += V_202 ;
break;
case V_219 :
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_87 ) ;
V_40 = - 1 ;
goto V_166;
}
V_104 += V_202 ;
break;
case V_220 :
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_87 ) ;
V_40 = - 1 ;
goto V_166;
}
V_104 += V_202 ;
if ( V_104 >= V_211 ) {
F_7 ( V_7 , ERROR ,
L_85 ) ;
V_40 = - 1 ;
} else {
V_40 = V_104 ;
}
goto V_166;
case V_221 :
V_215 = true ;
break;
default:
F_7 ( V_7 , ERROR , L_88 ,
V_214 ) ;
V_40 = - 1 ;
goto V_166;
}
}
V_166:
return V_40 ;
}
static int F_116 ( struct V_6 * V_7 ,
struct V_222 * V_223 )
{
int V_40 ;
T_3 * V_210 = V_223 -> V_224 ;
T_2 V_211 = V_223 -> V_225 ;
T_2 V_104 = 0 ;
struct V_8 * V_9 ;
T_2 V_226 , V_227 = 0 , V_228 , V_18 , V_229 ;
T_2 V_230 = 0 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( ! V_210 || ! V_211 ) {
F_7 ( V_7 , ERROR ,
L_89 ) ;
return - 1 ;
}
F_7 ( V_7 , V_26 ,
L_90 ,
V_211 ) ;
if ( F_57 ( V_7 ) ) {
F_7 ( V_7 , ERROR ,
L_91 , V_57 ) ;
return - 1 ;
}
V_9 = F_67 ( V_128 ) ;
if ( ! V_9 ) {
V_40 = - V_44 ;
goto V_166;
}
V_40 = F_14 ( V_7 , V_231 , & V_229 ) ;
if ( V_40 ) {
F_7 ( V_7 , V_232 , L_92 ) ;
goto V_166;
}
if ( V_229 == V_233 ) {
V_40 = F_114 ( V_7 , V_210 , V_211 ) ;
if ( V_40 < 0 ) {
F_7 ( V_7 , ERROR , L_93 ) ;
goto V_166;
}
V_104 = V_40 ;
F_7 ( V_7 , V_234 ,
L_94 , V_104 ) ;
}
do {
T_2 V_235 = 0 ;
if ( V_104 >= V_211 )
break;
for ( V_228 = 0 ; V_228 < V_236 ; V_228 ++ ) {
V_40 = F_14 ( V_7 , V_19 -> V_179 ,
& V_18 ) ;
if ( V_40 ) {
F_7 ( V_7 , V_232 ,
L_95 ) ;
goto V_166;
}
if ( V_18 )
break;
F_50 ( 10 , 20 ) ;
}
if ( ! V_18 ) {
break;
} else if ( V_18 > V_128 ) {
F_7 ( V_7 , ERROR ,
L_96 ,
V_104 , V_18 ) ;
V_40 = - 1 ;
goto V_166;
}
V_226 = V_18 ;
if ( V_18 & F_117 ( 0 ) ) {
V_230 ++ ;
if ( V_230 > V_237 ) {
F_7 ( V_7 , ERROR ,
L_97
L_98 , V_104 ) ;
V_40 = - 1 ;
goto V_166;
}
F_7 ( V_7 , ERROR ,
L_99
L_100 ,
V_18 , V_226 ) ;
V_18 &= ~ F_117 ( 0 ) ;
V_226 = 0 ;
} else {
V_230 = 0 ;
if ( V_211 - V_104 < V_226 )
V_226 = V_211 - V_104 ;
V_227 = ( V_226 + V_13 -> V_23 . V_47 - 1 ) /
V_13 -> V_23 . V_47 ;
memmove ( V_9 -> V_17 , & V_210 [ V_104 ] , V_226 ) ;
}
F_68 ( V_9 , V_128 - V_9 -> V_18 ) ;
F_106 ( V_9 , V_227 * V_13 -> V_23 . V_47 ) ;
if ( F_101 ( V_7 , V_9 ) ) {
F_7 ( V_7 , ERROR ,
L_101 ) ;
V_40 = - 1 ;
goto V_166;
}
for ( V_228 = 0 ; V_228 < V_236 ; V_228 ++ ) {
if ( F_14 ( V_7 , V_238 ,
& V_235 ) ) {
F_7 ( V_7 , ERROR ,
L_102
L_103 ,
V_57 ) ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( ! ( V_235 & V_180 ) )
break;
F_50 ( 10 , 20 ) ;
}
if ( V_235 & V_180 ) {
F_7 ( V_7 , ERROR , L_104 ,
V_57 ) ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
V_40 = - 1 ;
goto V_166;
}
F_9 ( V_7 , V_9 , V_111 ) ;
V_104 += V_226 ;
} while ( true );
F_7 ( V_7 , V_234 ,
L_105 , V_104 ) ;
V_40 = 0 ;
V_166:
F_70 ( V_9 ) ;
return V_40 ;
}
static int
F_118 ( struct V_6 * V_7 , T_2 V_239 )
{
int V_40 = 0 ;
T_2 V_240 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
T_2 V_228 ;
if ( F_12 ( V_7 , V_241 ,
V_83 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
F_7 ( V_7 , V_26 ,
L_106 ) ;
if ( F_12 ( V_7 , V_19 -> V_242 ,
V_62 ) ) {
F_7 ( V_7 , ERROR ,
L_107 ) ;
return - 1 ;
}
for ( V_228 = 0 ; V_228 < V_239 ; V_228 ++ ) {
if ( F_14 ( V_7 , V_19 -> V_60 ,
& V_240 ) )
V_40 = - 1 ;
else
V_40 = 0 ;
F_7 ( V_7 , V_26 , L_108 ,
V_228 , V_40 , V_240 ) ;
if ( V_40 )
continue;
if ( V_240 == V_62 ) {
V_40 = 0 ;
break;
} else {
F_119 ( 100 ) ;
V_40 = - 1 ;
}
}
return V_40 ;
}
static int
F_120 ( struct V_6 * V_7 )
{
T_2 V_243 = 0 ;
int V_40 = 0 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_243 ) ) {
V_40 = - 1 ;
} else if ( ! V_243 ) {
F_7 ( V_7 , V_26 , L_109 ) ;
V_7 -> V_243 = 1 ;
} else {
F_7 ( V_7 , ERROR ,
L_110 , V_243 ) ;
}
return V_40 ;
}
static void F_121 ( struct V_6 * V_7 ,
int V_244 )
{
T_2 V_245 ;
unsigned long V_11 ;
struct V_12 * V_13 = V_7 -> V_13 ;
if ( V_13 -> V_246 ) {
F_122 ( & V_7 -> V_247 , V_11 ) ;
V_7 -> V_248 = 1 ;
F_123 ( & V_7 -> V_247 , V_11 ) ;
return;
}
if ( ! F_18 ( V_7 ) )
return;
if ( V_13 -> V_249 && V_244 >= 0 ) {
V_245 = F_117 ( V_244 ) ;
} else {
if ( F_14 ( V_7 , V_250 ,
& V_245 ) ) {
F_7 ( V_7 , ERROR , L_111 ) ;
return;
}
if ( ( V_245 == 0xFFFFFFFF ) || ! V_245 )
return;
F_57 ( V_7 ) ;
if ( F_12 ( V_7 , V_250 ,
~ V_245 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return;
}
}
if ( ! V_7 -> V_251 &&
V_7 -> V_78 == V_252 &&
F_18 ( V_7 ) ) {
V_7 -> V_78 = V_79 ;
V_7 -> V_253 = false ;
F_124 ( & V_7 -> V_254 ) ;
}
F_122 ( & V_7 -> V_247 , V_11 ) ;
V_7 -> V_248 |= V_245 ;
F_123 ( & V_7 -> V_247 , V_11 ) ;
F_7 ( V_7 , V_255 , L_112 , V_245 ) ;
}
static T_6 F_125 ( int V_256 , void * V_257 )
{
struct V_258 * V_259 = V_257 ;
struct V_28 * V_29 = V_259 -> V_2 ;
struct V_12 * V_13 ;
struct V_6 * V_7 ;
V_13 = F_22 ( V_29 ) ;
if ( ! V_13 -> V_7 ) {
F_37 ( L_113 , V_57 , V_13 ,
V_13 ? V_13 -> V_7 : NULL ) ;
goto exit;
}
V_7 = V_13 -> V_7 ;
if ( V_7 -> V_260 )
goto exit;
if ( V_13 -> V_249 )
F_121 ( V_7 , V_259 -> V_244 ) ;
else
F_121 ( V_7 , - 1 ) ;
F_126 ( V_7 ) ;
exit:
return V_261 ;
}
static int F_127 ( struct V_6 * V_7 )
{
int V_40 ;
T_2 V_245 = 0 ;
unsigned long V_11 ;
struct V_12 * V_13 = V_7 -> V_13 ;
F_122 ( & V_7 -> V_247 , V_11 ) ;
if ( ! V_13 -> V_246 ) {
V_245 = V_7 -> V_248 ;
}
V_7 -> V_248 = 0 ;
F_123 ( & V_7 -> V_247 , V_11 ) ;
if ( V_13 -> V_246 ) {
if ( F_18 ( V_7 ) ) {
if ( F_14 ( V_7 , V_250 ,
& V_245 ) ) {
F_7 ( V_7 , ERROR ,
L_111 ) ;
return - 1 ;
}
if ( ( V_245 != 0xFFFFFFFF ) && ( V_245 ) ) {
if ( F_12 ( V_7 ,
V_250 ,
~ V_245 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
if ( ! V_7 -> V_251 &&
V_7 -> V_78 == V_252 ) {
V_7 -> V_78 = V_79 ;
V_7 -> V_253 = false ;
F_124 ( & V_7 -> V_254 ) ;
}
}
}
}
if ( V_245 & V_262 ) {
V_245 &= ~ V_262 ;
F_7 ( V_7 , V_255 , L_114 ) ;
V_40 = F_89 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_263 ) {
V_245 &= ~ V_263 ;
F_7 ( V_7 , V_255 , L_115 ) ;
V_40 = F_96 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_264 ) {
V_245 &= ~ V_264 ;
F_7 ( V_7 , V_255 , L_116 ) ;
V_40 = F_111 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_265 ) {
V_245 &= ~ V_265 ;
if ( V_7 -> V_184 ) {
F_7 ( V_7 , V_255 ,
L_117 ) ;
V_7 -> V_184 = false ;
}
V_40 = F_105 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
F_7 ( V_7 , V_255 ,
L_118 ,
V_7 -> V_184 , V_7 -> V_146 ) ;
if ( ! V_13 -> V_246 && V_7 -> V_78 != V_252 )
F_61 ( V_7 ) ;
return 0 ;
}
static int F_128 ( struct V_6 * V_7 )
{
int V_40 ;
T_2 V_245 ;
unsigned long V_11 ;
F_122 ( & V_7 -> V_247 , V_11 ) ;
V_245 = V_7 -> V_248 ;
V_7 -> V_248 = 0 ;
F_123 ( & V_7 -> V_247 , V_11 ) ;
if ( V_245 & V_262 ) {
F_7 ( V_7 , V_255 ,
L_114 ) ;
V_40 = F_89 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_263 ) {
F_7 ( V_7 , V_255 ,
L_115 ) ;
V_40 = F_96 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_264 ) {
F_7 ( V_7 , V_255 ,
L_116 ) ;
V_40 = F_111 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_245 & V_265 ) {
if ( V_7 -> V_184 ) {
F_7 ( V_7 , V_255 ,
L_117 ) ;
V_7 -> V_184 = false ;
}
V_40 = F_105 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
F_7 ( V_7 , V_255 ,
L_118 ,
V_7 -> V_184 , V_7 -> V_146 ) ;
return 0 ;
}
static int F_129 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( V_13 -> V_249 )
return F_128 ( V_7 ) ;
else
return F_127 ( V_7 ) ;
}
static int F_130 ( struct V_6 * V_7 , T_3 type ,
struct V_8 * V_9 ,
struct V_147 * V_148 )
{
if ( ! V_9 ) {
F_7 ( V_7 , ERROR ,
L_119 , V_57 ) ;
return - 1 ;
}
if ( type == V_152 )
return F_92 ( V_7 , V_9 , V_148 ) ;
else if ( type == V_185 )
return F_103 ( V_7 , V_9 ) ;
return 0 ;
}
static int
F_131 ( struct V_6 * V_7 , char * V_266 )
{
char * V_267 = V_266 ;
char V_268 [ 256 ] , * V_269 ;
int V_69 ;
T_2 V_270 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_271 [] = { V_272 ,
V_273 ,
V_274 } ;
if ( ! V_267 )
return 0 ;
F_7 ( V_7 , V_234 , L_120 ) ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_270 ) ) {
F_7 ( V_7 , ERROR , L_121 ) ;
return 0 ;
}
V_269 = V_268 ;
F_7 ( V_7 , V_234 , L_122 ) ;
for ( V_69 = 0 ; V_69 < F_132 ( V_271 ) ; V_69 ++ ) {
F_14 ( V_7 , V_271 [ V_69 ] , & V_270 ) ;
V_269 += sprintf ( V_269 , L_123 ,
V_271 [ V_69 ] , V_270 ) ;
}
F_7 ( V_7 , V_234 , L_124 , V_268 ) ;
V_267 += sprintf ( V_267 , L_124 , V_268 ) ;
F_7 ( V_7 , V_234 , L_125 ) ;
return V_267 - V_266 ;
}
static enum V_275
F_133 ( struct V_6 * V_7 , T_3 V_276 )
{
int V_40 , V_228 ;
T_3 V_277 ;
T_2 V_60 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_60 ) )
return V_278 ;
V_40 = F_12 ( V_7 , V_19 -> V_279 ,
V_19 -> V_280 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR ,
L_126 ) ;
return V_278 ;
}
for ( V_228 = 0 ; V_228 < V_236 ; V_228 ++ ) {
F_16 ( V_7 , V_19 -> V_279 , & V_277 ) ;
if ( V_277 == V_281 )
return V_282 ;
if ( V_276 && V_277 == V_276 )
return V_283 ;
if ( V_277 != V_19 -> V_280 ) {
F_7 ( V_7 , V_35 ,
L_127 ) ;
V_40 = F_12 ( V_7 , V_19 -> V_279 ,
V_19 -> V_280 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR ,
L_126 ) ;
return V_278 ;
}
}
F_50 ( 100 , 200 ) ;
}
F_7 ( V_7 , ERROR , L_128 ) ;
return V_278 ;
}
static void F_134 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_284 = V_13 -> V_23 . V_19 ;
unsigned int V_19 , V_285 , V_286 ;
T_3 * V_287 , * V_288 , * V_289 , V_290 , V_291 ;
T_3 V_292 , V_69 , V_293 , V_276 = 0 ;
enum V_275 V_294 ;
T_2 V_295 ;
int V_40 ;
if ( ! V_13 -> V_23 . V_49 )
return;
for ( V_292 = 0 ; V_292 < V_7 -> V_51 ; V_292 ++ ) {
struct V_296 * V_297 =
& V_7 -> V_50 [ V_292 ] ;
if ( V_297 -> V_298 ) {
F_135 ( V_297 -> V_298 ) ;
V_297 -> V_298 = NULL ;
}
V_297 -> V_299 = 0 ;
}
F_7 ( V_7 , V_234 , L_129 ) ;
V_294 = F_133 ( V_7 , V_276 ) ;
if ( V_294 == V_278 )
return;
V_19 = V_284 -> V_300 ;
F_16 ( V_7 , V_19 , & V_290 ) ;
if ( V_290 == 0 )
V_291 = 1 ;
else
V_291 = V_290 ;
for ( V_292 = 0 ; V_292 < V_291 ; V_292 ++ ) {
struct V_296 * V_297 =
& V_7 -> V_50 [ V_292 ] ;
V_295 = 0 ;
if ( V_290 != 0 ) {
V_294 = F_133 ( V_7 , V_276 ) ;
if ( V_294 == V_278 )
return;
V_19 = V_284 -> V_300 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
F_16 ( V_7 , V_19 , & V_293 ) ;
V_295 |= ( V_293 << ( V_69 * 8 ) ) ;
V_19 ++ ;
}
} else {
V_295 = V_301 ;
}
if ( V_295 == 0 ) {
F_7 ( V_7 , V_234 , L_130 ) ;
V_40 = F_12 ( V_7 , V_284 -> V_279 ,
V_284 -> V_302 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_126 ) ;
return;
}
break;
}
F_7 ( V_7 , V_303 ,
L_131 , V_297 -> V_304 , V_295 ) ;
V_297 -> V_298 = F_136 ( V_295 + 1 ) ;
V_297 -> V_299 = V_295 ;
if ( ! V_297 -> V_298 ) {
F_7 ( V_7 , ERROR ,
L_132 , V_297 -> V_304 ) ;
return;
}
V_287 = V_297 -> V_298 ;
V_288 = V_287 + V_295 ;
V_276 = V_297 -> V_305 ;
F_7 ( V_7 , V_303 , L_133 ,
V_297 -> V_304 ) ;
do {
V_294 = F_133 ( V_7 , V_276 ) ;
if ( V_278 == V_294 )
return;
V_285 = V_284 -> V_300 ;
V_286 = V_284 -> V_306 ;
for ( V_19 = V_285 ; V_19 <= V_286 ; V_19 ++ ) {
F_16 ( V_7 , V_19 , V_287 ) ;
if ( V_287 < V_288 ) {
V_287 ++ ;
continue;
}
F_7 ( V_7 , ERROR ,
L_134 ) ;
V_289 =
F_137 ( V_295 + V_307 ) ;
if ( ! V_289 )
return;
memcpy ( V_289 , V_297 -> V_298 , V_295 ) ;
F_135 ( V_297 -> V_298 ) ;
V_297 -> V_298 = V_289 ;
V_289 = NULL ;
V_287 = V_297 -> V_298 + V_295 ;
V_295 += V_307 ;
V_288 = V_297 -> V_298 + V_295 ;
}
if ( V_294 != V_283 )
continue;
F_7 ( V_7 , V_303 ,
L_135 ,
V_297 -> V_304 , V_287 - V_297 -> V_298 ) ;
break;
} while ( true );
}
F_7 ( V_7 , V_234 , L_136 ) ;
}
static void F_138 ( struct V_6 * V_7 )
{
int V_308 ;
void * V_309 ;
V_308 = F_139 ( V_7 , & V_309 ) ;
F_134 ( V_7 ) ;
F_140 ( V_7 , V_309 , V_308 ) ;
}
static void F_141 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
F_142 ( V_13 -> V_2 ) ;
}
static void V_54 ( struct V_310 * V_53 )
{
struct V_12 * V_13 =
F_143 ( V_53 , struct V_12 , V_53 ) ;
if ( F_144 ( V_66 ,
& V_13 -> V_67 ) )
F_138 ( V_13 -> V_7 ) ;
if ( F_144 ( V_68 ,
& V_13 -> V_67 ) )
F_141 ( V_13 -> V_7 ) ;
}
static void F_145 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( ! F_146 ( V_66 ,
& V_13 -> V_67 ) )
F_147 ( & V_13 -> V_53 ) ;
}
static void F_148 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( ! F_146 ( V_68 , & V_13 -> V_67 ) )
F_147 ( & V_13 -> V_53 ) ;
}
static int F_149 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 ;
V_13 -> V_74 = NULL ;
V_40 = F_73 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_137 ) ;
goto V_311;
}
V_40 = F_77 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_138 ) ;
goto V_312;
}
V_40 = F_79 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_139 ) ;
goto V_313;
}
V_40 = F_81 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_140 ) ;
goto V_314;
}
if ( V_19 -> V_24 ) {
V_40 = F_83 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_141 ) ;
goto V_315;
}
} else {
V_13 -> V_25 = NULL ;
}
return 0 ;
V_315:
F_82 ( V_7 ) ;
V_314:
F_80 ( V_7 ) ;
V_313:
F_78 ( V_7 ) ;
V_312:
F_75 ( V_7 ) ;
V_311:
return V_40 ;
}
static void F_150 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( V_19 -> V_24 )
F_86 ( V_7 ) ;
F_82 ( V_7 ) ;
F_80 ( V_7 ) ;
F_78 ( V_7 ) ;
F_75 ( V_7 ) ;
V_13 -> V_74 = NULL ;
}
static int F_151 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
int V_40 ;
struct V_28 * V_29 = V_13 -> V_2 ;
F_152 ( V_29 , V_13 ) ;
V_40 = F_153 ( V_29 ) ;
if ( V_40 )
goto V_316;
F_154 ( V_29 ) ;
F_155 ( L_142 ) ;
V_40 = F_156 ( V_29 , F_157 ( 32 ) ) ;
if ( V_40 ) {
F_37 ( L_143 ) ;
goto V_317;
}
V_40 = F_158 ( V_29 , F_157 ( 32 ) ) ;
if ( V_40 ) {
F_37 ( L_144 ) ;
goto V_317;
}
V_40 = F_159 ( V_29 , 0 , V_318 ) ;
if ( V_40 ) {
F_37 ( L_145 ) ;
goto V_319;
}
V_13 -> V_320 = F_160 ( V_29 , 0 , 0 ) ;
if ( ! V_13 -> V_320 ) {
F_37 ( L_146 ) ;
V_40 = - V_321 ;
goto V_322;
}
V_40 = F_159 ( V_29 , 2 , V_318 ) ;
if ( V_40 ) {
F_37 ( L_147 ) ;
goto V_323;
}
V_13 -> V_20 = F_160 ( V_29 , 2 , 0 ) ;
if ( ! V_13 -> V_20 ) {
F_37 ( L_148 ) ;
V_40 = - V_321 ;
goto V_324;
}
F_155 ( L_149 ,
V_13 -> V_320 , V_13 -> V_20 ) ;
V_40 = F_149 ( V_7 ) ;
if ( V_40 )
goto V_325;
return 0 ;
V_325:
F_161 ( V_29 , V_13 -> V_20 ) ;
V_324:
F_162 ( V_29 , 2 ) ;
V_323:
F_161 ( V_29 , V_13 -> V_320 ) ;
V_322:
F_162 ( V_29 , 0 ) ;
V_319:
V_317:
F_163 ( V_29 ) ;
V_316:
return V_40 ;
}
static void F_164 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 ;
T_2 V_60 ;
F_165 ( & V_13 -> V_53 ) ;
V_40 = F_14 ( V_7 , V_19 -> V_60 , & V_60 ) ;
if ( V_60 == V_62 ) {
F_7 ( V_7 , V_26 ,
L_150 ) ;
if ( F_12 ( V_7 , V_19 -> V_242 , 0x00000000 ) )
F_7 ( V_7 , ERROR ,
L_151 ) ;
}
F_150 ( V_7 ) ;
if ( V_29 ) {
F_161 ( V_29 , V_13 -> V_320 ) ;
F_161 ( V_29 , V_13 -> V_20 ) ;
F_163 ( V_29 ) ;
F_162 ( V_29 , 2 ) ;
F_162 ( V_29 , 0 ) ;
}
}
static int F_166 ( struct V_6 * V_7 )
{
int V_40 , V_69 , V_326 ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
if ( V_13 -> V_23 . V_19 -> V_327 ) {
for ( V_69 = 0 ; V_69 < V_328 ; V_69 ++ )
V_13 -> V_329 [ V_69 ] . V_297 = V_69 ;
V_40 = F_167 ( V_29 , V_13 -> V_329 ,
V_328 ) ;
if ( ! V_40 ) {
for ( V_69 = 0 ; V_69 < V_328 ; V_69 ++ ) {
V_13 -> V_330 [ V_69 ] . V_2 = V_29 ;
V_13 -> V_330 [ V_69 ] . V_244 = V_69 ;
V_40 = F_168 ( V_13 -> V_329 [ V_69 ] . V_331 ,
F_125 , 0 ,
L_152 ,
& V_13 -> V_330 [ V_69 ] ) ;
if ( V_40 )
break;
}
if ( V_40 ) {
F_7 ( V_7 , V_26 , L_153 ,
V_40 ) ;
for ( V_326 = 0 ; V_326 < V_69 ; V_326 ++ )
F_169 ( V_13 -> V_329 [ V_326 ] . V_331 ,
& V_13 -> V_330 [ V_69 ] ) ;
F_170 ( V_29 ) ;
} else {
F_7 ( V_7 , V_234 , L_154 ) ;
V_13 -> V_249 = 1 ;
return 0 ;
}
}
}
if ( F_171 ( V_29 ) != 0 )
F_172 ( V_29 ) ;
else
V_13 -> V_246 = 1 ;
F_7 ( V_7 , V_26 , L_155 , V_13 -> V_246 ) ;
V_13 -> V_332 . V_2 = V_29 ;
V_13 -> V_332 . V_244 = - 1 ;
V_40 = F_168 ( V_29 -> V_256 , F_125 , V_333 ,
L_156 , & V_13 -> V_332 ) ;
if ( V_40 ) {
F_37 ( L_157 , V_40 ) ;
return - 1 ;
}
return 0 ;
}
static void F_173 ( struct V_6 * V_7 )
{
int V_334 = 0 ;
int V_335 , V_336 ;
struct V_12 * V_13 = V_7 -> V_13 ;
switch ( V_13 -> V_2 -> V_1 ) {
case V_142 :
strcpy ( V_7 -> V_337 , V_338 ) ;
break;
case V_143 :
F_12 ( V_7 , 0x0c58 , 0x80c00000 ) ;
F_14 ( V_7 , 0x0c58 , & V_334 ) ;
V_334 &= 0xff00 ;
switch ( V_334 ) {
case V_339 :
strcpy ( V_7 -> V_337 , V_340 ) ;
break;
case V_341 :
strcpy ( V_7 -> V_337 , V_342 ) ;
break;
default:
strcpy ( V_7 -> V_337 , V_343 ) ;
break;
}
break;
case V_144 :
F_14 ( V_7 , 0x8 , & V_334 ) ;
F_14 ( V_7 , 0x0cd0 , & V_335 ) ;
F_14 ( V_7 , 0x0cd4 , & V_336 ) ;
V_334 &= 0xff ;
V_335 &= 0x7 ;
V_336 &= 0xff ;
if ( V_334 == V_344 &&
V_336 == V_345 &&
V_335 == V_346 )
strcpy ( V_7 -> V_337 , V_347 ) ;
else
strcpy ( V_7 -> V_337 , V_348 ) ;
break;
default:
break;
}
}
static int F_174 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
V_13 -> V_7 = V_7 ;
if ( F_166 ( V_7 ) )
return - 1 ;
V_7 -> V_48 = V_13 -> V_23 . V_48 ;
V_7 -> V_50 = V_13 -> V_23 . V_50 ;
V_7 -> V_51 = V_13 -> V_23 . V_51 ;
V_7 -> V_349 = V_13 -> V_23 . V_52 ;
F_173 ( V_7 ) ;
return 0 ;
}
static void F_175 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
int V_69 ;
if ( V_13 -> V_249 ) {
for ( V_69 = 0 ; V_69 < V_328 ; V_69 ++ )
F_176 ( V_13 -> V_329 [ V_69 ] . V_331 ) ;
for ( V_69 = 0 ; V_69 < V_328 ; V_69 ++ )
F_169 ( V_13 -> V_329 [ V_69 ] . V_331 ,
& V_13 -> V_330 [ V_69 ] ) ;
V_13 -> V_249 = 0 ;
F_170 ( V_29 ) ;
} else {
F_7 ( V_7 , V_26 ,
L_158 , V_57 ) ;
F_169 ( V_13 -> V_2 -> V_256 , & V_13 -> V_332 ) ;
if ( V_13 -> V_246 )
F_172 ( V_29 ) ;
}
V_13 -> V_7 = NULL ;
}
static void F_177 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
int V_40 ;
struct V_28 * V_29 = V_13 -> V_2 ;
V_7 -> V_48 = V_13 -> V_23 . V_48 ;
V_40 = F_149 ( V_7 ) ;
if ( ! V_40 )
return;
F_161 ( V_29 , V_13 -> V_20 ) ;
}
static void F_178 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( F_12 ( V_7 , V_19 -> V_242 , 0x00000000 ) )
F_7 ( V_7 , ERROR , L_151 ) ;
V_7 -> V_350 = 0 ;
F_150 ( V_7 ) ;
}
