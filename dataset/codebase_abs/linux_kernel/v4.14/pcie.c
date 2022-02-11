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
V_13 -> V_74 = NULL ;
}
if ( V_13 && V_13 -> V_129 ) {
F_9 ( V_7 , V_13 -> V_129 ,
V_111 ) ;
F_70 ( V_13 -> V_129 ) ;
V_13 -> V_129 = NULL ;
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
bool V_215 = false , V_216 = false ;
while ( 1 ) {
if ( V_104 + sizeof( V_213 -> V_217 ) < sizeof( V_213 -> V_217 ) ||
V_104 + sizeof( V_213 -> V_217 ) >= V_211 ) {
F_7 ( V_7 , ERROR ,
L_85 ) ;
V_40 = - 1 ;
goto V_166;
}
V_213 = V_210 + V_104 ;
V_214 = F_115 ( V_213 -> V_217 . V_214 ) ;
V_202 = F_115 ( V_213 -> V_217 . V_218 ) ;
V_104 += sizeof( V_213 -> V_217 ) ;
switch ( V_214 ) {
case V_219 :
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_86 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( ! V_216 ) {
F_7 ( V_7 , V_220 ,
L_87 ) ;
return 0 ;
}
if ( ! V_215 ) {
F_7 ( V_7 , ERROR ,
L_88 ) ;
V_40 = - 1 ;
goto V_166;
}
V_104 += V_202 ;
break;
case V_221 :
V_216 = true ;
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_86 ) ;
V_40 = - 1 ;
goto V_166;
}
V_104 += V_202 ;
break;
case V_222 :
V_216 = true ;
if ( V_104 + V_202 < V_202 ) {
F_7 ( V_7 , ERROR , L_86 ) ;
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
case V_223 :
V_216 = true ;
V_215 = true ;
break;
default:
F_7 ( V_7 , ERROR , L_89 ,
V_214 ) ;
V_40 = - 1 ;
goto V_166;
}
}
V_166:
return V_40 ;
}
static int F_116 ( struct V_6 * V_7 ,
struct V_224 * V_225 )
{
int V_40 ;
T_3 * V_210 = V_225 -> V_226 ;
T_2 V_211 = V_225 -> V_227 ;
T_2 V_104 = 0 ;
struct V_8 * V_9 ;
T_2 V_228 , V_229 = 0 , V_230 , V_18 , V_231 ;
T_2 V_232 = 0 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( ! V_210 || ! V_211 ) {
F_7 ( V_7 , ERROR ,
L_90 ) ;
return - 1 ;
}
F_7 ( V_7 , V_26 ,
L_91 ,
V_211 ) ;
if ( F_57 ( V_7 ) ) {
F_7 ( V_7 , ERROR ,
L_92 , V_57 ) ;
return - 1 ;
}
V_9 = F_67 ( V_128 ) ;
if ( ! V_9 ) {
V_40 = - V_44 ;
goto V_166;
}
V_40 = F_14 ( V_7 , V_233 , & V_231 ) ;
if ( V_40 ) {
F_7 ( V_7 , V_234 , L_93 ) ;
goto V_166;
}
if ( V_231 == V_235 ) {
V_40 = F_114 ( V_7 , V_210 , V_211 ) ;
if ( V_40 < 0 ) {
F_7 ( V_7 , ERROR , L_94 ) ;
goto V_166;
}
V_104 = V_40 ;
F_7 ( V_7 , V_220 ,
L_95 , V_104 ) ;
}
do {
T_2 V_236 = 0 ;
if ( V_104 >= V_211 )
break;
for ( V_230 = 0 ; V_230 < V_237 ; V_230 ++ ) {
V_40 = F_14 ( V_7 , V_19 -> V_179 ,
& V_18 ) ;
if ( V_40 ) {
F_7 ( V_7 , V_234 ,
L_96 ) ;
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
L_97 ,
V_104 , V_18 ) ;
V_40 = - 1 ;
goto V_166;
}
V_228 = V_18 ;
if ( V_18 & F_117 ( 0 ) ) {
V_232 ++ ;
if ( V_232 > V_238 ) {
F_7 ( V_7 , ERROR ,
L_98
L_99 , V_104 ) ;
V_40 = - 1 ;
goto V_166;
}
F_7 ( V_7 , ERROR ,
L_100
L_101 ,
V_18 , V_228 ) ;
V_18 &= ~ F_117 ( 0 ) ;
V_228 = 0 ;
} else {
V_232 = 0 ;
if ( V_211 - V_104 < V_228 )
V_228 = V_211 - V_104 ;
V_229 = ( V_228 + V_13 -> V_23 . V_47 - 1 ) /
V_13 -> V_23 . V_47 ;
memmove ( V_9 -> V_17 , & V_210 [ V_104 ] , V_228 ) ;
}
F_68 ( V_9 , V_128 - V_9 -> V_18 ) ;
F_106 ( V_9 , V_229 * V_13 -> V_23 . V_47 ) ;
if ( F_101 ( V_7 , V_9 ) ) {
F_7 ( V_7 , ERROR ,
L_102 ) ;
V_40 = - 1 ;
goto V_166;
}
for ( V_230 = 0 ; V_230 < V_237 ; V_230 ++ ) {
if ( F_14 ( V_7 , V_239 ,
& V_236 ) ) {
F_7 ( V_7 , ERROR ,
L_103
L_104 ,
V_57 ) ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
V_40 = - 1 ;
goto V_166;
}
if ( ! ( V_236 & V_180 ) )
break;
F_50 ( 10 , 20 ) ;
}
if ( V_236 & V_180 ) {
F_7 ( V_7 , ERROR , L_105 ,
V_57 ) ;
F_9 ( V_7 , V_9 ,
V_111 ) ;
V_40 = - 1 ;
goto V_166;
}
F_9 ( V_7 , V_9 , V_111 ) ;
V_104 += V_228 ;
} while ( true );
F_7 ( V_7 , V_220 ,
L_106 , V_104 ) ;
V_40 = 0 ;
V_166:
F_70 ( V_9 ) ;
return V_40 ;
}
static int
F_118 ( struct V_6 * V_7 , T_2 V_240 )
{
int V_40 = 0 ;
T_2 V_241 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
T_2 V_230 ;
if ( F_12 ( V_7 , V_242 ,
V_83 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
F_7 ( V_7 , V_26 ,
L_107 ) ;
if ( F_12 ( V_7 , V_19 -> V_243 ,
V_62 ) ) {
F_7 ( V_7 , ERROR ,
L_108 ) ;
return - 1 ;
}
for ( V_230 = 0 ; V_230 < V_240 ; V_230 ++ ) {
if ( F_14 ( V_7 , V_19 -> V_60 ,
& V_241 ) )
V_40 = - 1 ;
else
V_40 = 0 ;
F_7 ( V_7 , V_26 , L_109 ,
V_230 , V_40 , V_241 ) ;
if ( V_40 )
continue;
if ( V_241 == V_62 ) {
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
T_2 V_244 = 0 ;
int V_40 = 0 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_244 ) ) {
V_40 = - 1 ;
} else if ( ! V_244 ) {
F_7 ( V_7 , V_26 , L_110 ) ;
V_7 -> V_244 = 1 ;
} else {
F_7 ( V_7 , ERROR ,
L_111 , V_244 ) ;
}
return V_40 ;
}
static void F_121 ( struct V_6 * V_7 ,
int V_245 )
{
T_2 V_246 ;
unsigned long V_11 ;
struct V_12 * V_13 = V_7 -> V_13 ;
if ( V_13 -> V_247 ) {
F_122 ( & V_7 -> V_248 , V_11 ) ;
V_7 -> V_249 = 1 ;
F_123 ( & V_7 -> V_248 , V_11 ) ;
return;
}
if ( ! F_18 ( V_7 ) )
return;
if ( V_13 -> V_250 && V_245 >= 0 ) {
V_246 = F_117 ( V_245 ) ;
} else {
if ( F_14 ( V_7 , V_251 ,
& V_246 ) ) {
F_7 ( V_7 , ERROR , L_112 ) ;
return;
}
if ( ( V_246 == 0xFFFFFFFF ) || ! V_246 )
return;
F_57 ( V_7 ) ;
if ( F_12 ( V_7 , V_251 ,
~ V_246 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return;
}
}
if ( ! V_7 -> V_252 &&
V_7 -> V_78 == V_253 &&
F_18 ( V_7 ) ) {
V_7 -> V_78 = V_79 ;
V_7 -> V_254 = false ;
F_124 ( & V_7 -> V_255 ) ;
}
F_122 ( & V_7 -> V_248 , V_11 ) ;
V_7 -> V_249 |= V_246 ;
F_123 ( & V_7 -> V_248 , V_11 ) ;
F_7 ( V_7 , V_256 , L_113 , V_246 ) ;
}
static T_6 F_125 ( int V_257 , void * V_258 )
{
struct V_259 * V_260 = V_258 ;
struct V_28 * V_29 = V_260 -> V_2 ;
struct V_12 * V_13 ;
struct V_6 * V_7 ;
V_13 = F_22 ( V_29 ) ;
if ( ! V_13 -> V_7 ) {
F_37 ( L_114 , V_57 , V_13 ,
V_13 ? V_13 -> V_7 : NULL ) ;
goto exit;
}
V_7 = V_13 -> V_7 ;
if ( V_7 -> V_261 )
goto exit;
if ( V_13 -> V_250 )
F_121 ( V_7 , V_260 -> V_245 ) ;
else
F_121 ( V_7 , - 1 ) ;
F_126 ( V_7 ) ;
exit:
return V_262 ;
}
static int F_127 ( struct V_6 * V_7 )
{
int V_40 ;
T_2 V_246 = 0 ;
unsigned long V_11 ;
struct V_12 * V_13 = V_7 -> V_13 ;
F_122 ( & V_7 -> V_248 , V_11 ) ;
if ( ! V_13 -> V_247 ) {
V_246 = V_7 -> V_249 ;
}
V_7 -> V_249 = 0 ;
F_123 ( & V_7 -> V_248 , V_11 ) ;
if ( V_13 -> V_247 ) {
if ( F_18 ( V_7 ) ) {
if ( F_14 ( V_7 , V_251 ,
& V_246 ) ) {
F_7 ( V_7 , ERROR ,
L_112 ) ;
return - 1 ;
}
if ( ( V_246 != 0xFFFFFFFF ) && ( V_246 ) ) {
if ( F_12 ( V_7 ,
V_251 ,
~ V_246 ) ) {
F_7 ( V_7 , ERROR ,
L_68 ) ;
return - 1 ;
}
if ( ! V_7 -> V_252 &&
V_7 -> V_78 == V_253 ) {
V_7 -> V_78 = V_79 ;
V_7 -> V_254 = false ;
F_124 ( & V_7 -> V_255 ) ;
}
}
}
}
if ( V_246 & V_263 ) {
F_7 ( V_7 , V_256 , L_115 ) ;
V_40 = F_89 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_246 & V_264 ) {
F_7 ( V_7 , V_256 , L_116 ) ;
V_40 = F_96 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_246 & V_265 ) {
F_7 ( V_7 , V_256 , L_117 ) ;
V_40 = F_111 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_246 & V_266 ) {
if ( V_7 -> V_184 ) {
F_7 ( V_7 , V_256 ,
L_118 ) ;
V_7 -> V_184 = false ;
}
V_40 = F_105 ( V_7 ) ;
if ( V_40 )
return V_40 ;
}
F_7 ( V_7 , V_256 ,
L_119 ,
V_7 -> V_184 , V_7 -> V_146 ) ;
if ( ! V_13 -> V_247 && ! V_13 -> V_250 &&
V_7 -> V_78 != V_253 )
F_61 ( V_7 ) ;
return 0 ;
}
static int F_128 ( struct V_6 * V_7 , T_3 type ,
struct V_8 * V_9 ,
struct V_147 * V_148 )
{
if ( ! V_9 ) {
F_7 ( V_7 , ERROR ,
L_120 , V_57 ) ;
return - 1 ;
}
if ( type == V_152 )
return F_92 ( V_7 , V_9 , V_148 ) ;
else if ( type == V_185 )
return F_103 ( V_7 , V_9 ) ;
return 0 ;
}
static int
F_129 ( struct V_6 * V_7 , char * V_267 )
{
char * V_268 = V_267 ;
char V_269 [ 256 ] , * V_270 ;
int V_69 ;
T_2 V_271 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_272 [] = { V_273 ,
V_274 ,
V_275 } ;
if ( ! V_268 )
return 0 ;
F_7 ( V_7 , V_220 , L_121 ) ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_271 ) ) {
F_7 ( V_7 , ERROR , L_122 ) ;
return 0 ;
}
V_270 = V_269 ;
F_7 ( V_7 , V_220 , L_123 ) ;
for ( V_69 = 0 ; V_69 < F_130 ( V_272 ) ; V_69 ++ ) {
F_14 ( V_7 , V_272 [ V_69 ] , & V_271 ) ;
V_270 += sprintf ( V_270 , L_124 ,
V_272 [ V_69 ] , V_271 ) ;
}
F_7 ( V_7 , V_220 , L_125 , V_269 ) ;
V_268 += sprintf ( V_268 , L_125 , V_269 ) ;
F_7 ( V_7 , V_220 , L_126 ) ;
return V_268 - V_267 ;
}
static enum V_276
F_131 ( struct V_6 * V_7 , T_3 V_277 )
{
int V_40 , V_230 ;
T_3 V_278 ;
T_2 V_60 ;
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( F_14 ( V_7 , V_19 -> V_60 , & V_60 ) )
return V_279 ;
V_40 = F_12 ( V_7 , V_19 -> V_280 ,
V_19 -> V_281 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR ,
L_127 ) ;
return V_279 ;
}
for ( V_230 = 0 ; V_230 < V_237 ; V_230 ++ ) {
F_16 ( V_7 , V_19 -> V_280 , & V_278 ) ;
if ( V_278 == V_282 )
return V_283 ;
if ( V_277 && V_278 == V_277 )
return V_284 ;
if ( V_278 != V_19 -> V_281 ) {
F_7 ( V_7 , V_35 ,
L_128 ) ;
V_40 = F_12 ( V_7 , V_19 -> V_280 ,
V_19 -> V_281 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR ,
L_127 ) ;
return V_279 ;
}
}
F_50 ( 100 , 200 ) ;
}
F_7 ( V_7 , ERROR , L_129 ) ;
return V_279 ;
}
static void F_132 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_285 = V_13 -> V_23 . V_19 ;
unsigned int V_19 , V_286 , V_287 ;
T_3 * V_288 , * V_289 , * V_290 , V_291 , V_292 ;
T_3 V_293 , V_69 , V_294 , V_277 = 0 ;
enum V_276 V_295 ;
T_2 V_296 ;
int V_40 ;
if ( ! V_13 -> V_23 . V_49 )
return;
for ( V_293 = 0 ; V_293 < V_7 -> V_51 ; V_293 ++ ) {
struct V_297 * V_298 =
& V_7 -> V_50 [ V_293 ] ;
if ( V_298 -> V_299 ) {
F_133 ( V_298 -> V_299 ) ;
V_298 -> V_299 = NULL ;
}
V_298 -> V_300 = 0 ;
}
F_7 ( V_7 , V_220 , L_130 ) ;
V_295 = F_131 ( V_7 , V_277 ) ;
if ( V_295 == V_279 )
return;
V_19 = V_285 -> V_301 ;
F_16 ( V_7 , V_19 , & V_291 ) ;
if ( V_291 == 0 )
V_292 = 1 ;
else
V_292 = V_291 ;
for ( V_293 = 0 ; V_293 < V_292 ; V_293 ++ ) {
struct V_297 * V_298 =
& V_7 -> V_50 [ V_293 ] ;
V_296 = 0 ;
if ( V_291 != 0 ) {
V_295 = F_131 ( V_7 , V_277 ) ;
if ( V_295 == V_279 )
return;
V_19 = V_285 -> V_301 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
F_16 ( V_7 , V_19 , & V_294 ) ;
V_296 |= ( V_294 << ( V_69 * 8 ) ) ;
V_19 ++ ;
}
} else {
V_296 = V_302 ;
}
if ( V_296 == 0 ) {
F_7 ( V_7 , V_220 , L_131 ) ;
V_40 = F_12 ( V_7 , V_285 -> V_280 ,
V_285 -> V_303 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_127 ) ;
return;
}
break;
}
F_7 ( V_7 , V_304 ,
L_132 , V_298 -> V_305 , V_296 ) ;
V_298 -> V_299 = F_134 ( V_296 + 1 ) ;
V_298 -> V_300 = V_296 ;
if ( ! V_298 -> V_299 ) {
F_7 ( V_7 , ERROR ,
L_133 , V_298 -> V_305 ) ;
return;
}
V_288 = V_298 -> V_299 ;
V_289 = V_288 + V_296 ;
V_277 = V_298 -> V_306 ;
F_7 ( V_7 , V_304 , L_134 ,
V_298 -> V_305 ) ;
do {
V_295 = F_131 ( V_7 , V_277 ) ;
if ( V_279 == V_295 )
return;
V_286 = V_285 -> V_301 ;
V_287 = V_285 -> V_307 ;
for ( V_19 = V_286 ; V_19 <= V_287 ; V_19 ++ ) {
F_16 ( V_7 , V_19 , V_288 ) ;
if ( V_288 < V_289 ) {
V_288 ++ ;
continue;
}
F_7 ( V_7 , ERROR ,
L_135 ) ;
V_290 =
F_135 ( V_296 + V_308 ) ;
if ( ! V_290 )
return;
memcpy ( V_290 , V_298 -> V_299 , V_296 ) ;
F_133 ( V_298 -> V_299 ) ;
V_298 -> V_299 = V_290 ;
V_290 = NULL ;
V_288 = V_298 -> V_299 + V_296 ;
V_296 += V_308 ;
V_289 = V_298 -> V_299 + V_296 ;
}
if ( V_295 != V_284 )
continue;
F_7 ( V_7 , V_304 ,
L_136 ,
V_298 -> V_305 , V_288 - V_298 -> V_299 ) ;
break;
} while ( true );
}
F_7 ( V_7 , V_220 , L_137 ) ;
}
static void F_136 ( struct V_6 * V_7 )
{
int V_309 ;
void * V_310 ;
V_309 = F_137 ( V_7 , & V_310 ) ;
F_132 ( V_7 ) ;
F_138 ( V_7 , V_310 , V_309 ) ;
}
static void F_139 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
F_140 ( V_13 -> V_2 ) ;
}
static void V_54 ( struct V_311 * V_53 )
{
struct V_12 * V_13 =
F_141 ( V_53 , struct V_12 , V_53 ) ;
if ( F_142 ( V_66 ,
& V_13 -> V_67 ) )
F_136 ( V_13 -> V_7 ) ;
if ( F_142 ( V_68 ,
& V_13 -> V_67 ) )
F_139 ( V_13 -> V_7 ) ;
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( ! F_144 ( V_66 ,
& V_13 -> V_67 ) )
F_145 ( & V_13 -> V_53 ) ;
}
static void F_146 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
if ( ! F_144 ( V_68 , & V_13 -> V_67 ) )
F_145 ( & V_13 -> V_53 ) ;
}
static int F_147 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 ;
V_13 -> V_74 = NULL ;
V_40 = F_73 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_138 ) ;
goto V_312;
}
V_40 = F_77 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_139 ) ;
goto V_313;
}
V_40 = F_79 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_140 ) ;
goto V_314;
}
V_40 = F_81 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_141 ) ;
goto V_315;
}
if ( V_19 -> V_24 ) {
V_40 = F_83 ( V_7 ) ;
if ( V_40 ) {
F_7 ( V_7 , ERROR , L_142 ) ;
goto V_316;
}
} else {
V_13 -> V_25 = NULL ;
}
return 0 ;
V_316:
F_82 ( V_7 ) ;
V_315:
F_80 ( V_7 ) ;
V_314:
F_78 ( V_7 ) ;
V_313:
F_75 ( V_7 ) ;
V_312:
return V_40 ;
}
static void F_148 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
if ( V_19 -> V_24 )
F_86 ( V_7 ) ;
F_82 ( V_7 ) ;
F_80 ( V_7 ) ;
F_78 ( V_7 ) ;
F_75 ( V_7 ) ;
}
static int F_149 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
int V_40 ;
struct V_28 * V_29 = V_13 -> V_2 ;
F_150 ( V_29 , V_13 ) ;
V_40 = F_151 ( V_29 ) ;
if ( V_40 )
goto V_317;
F_152 ( V_29 ) ;
F_153 ( L_143 ) ;
V_40 = F_154 ( V_29 , F_155 ( 32 ) ) ;
if ( V_40 ) {
F_37 ( L_144 ) ;
goto V_318;
}
V_40 = F_156 ( V_29 , F_155 ( 32 ) ) ;
if ( V_40 ) {
F_37 ( L_145 ) ;
goto V_318;
}
V_40 = F_157 ( V_29 , 0 , V_319 ) ;
if ( V_40 ) {
F_37 ( L_146 ) ;
goto V_320;
}
V_13 -> V_321 = F_158 ( V_29 , 0 , 0 ) ;
if ( ! V_13 -> V_321 ) {
F_37 ( L_147 ) ;
V_40 = - V_322 ;
goto V_323;
}
V_40 = F_157 ( V_29 , 2 , V_319 ) ;
if ( V_40 ) {
F_37 ( L_148 ) ;
goto V_324;
}
V_13 -> V_20 = F_158 ( V_29 , 2 , 0 ) ;
if ( ! V_13 -> V_20 ) {
F_37 ( L_149 ) ;
V_40 = - V_322 ;
goto V_325;
}
F_153 ( L_150 ,
V_13 -> V_321 , V_13 -> V_20 ) ;
V_40 = F_147 ( V_7 ) ;
if ( V_40 )
goto V_326;
return 0 ;
V_326:
F_159 ( V_29 , V_13 -> V_20 ) ;
V_325:
F_160 ( V_29 , 2 ) ;
V_324:
F_159 ( V_29 , V_13 -> V_321 ) ;
V_323:
F_160 ( V_29 , 0 ) ;
V_320:
V_318:
F_161 ( V_29 ) ;
V_317:
return V_40 ;
}
static void F_162 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
int V_40 ;
T_2 V_60 ;
F_163 ( & V_13 -> V_53 ) ;
V_40 = F_14 ( V_7 , V_19 -> V_60 , & V_60 ) ;
if ( V_60 == V_62 ) {
F_7 ( V_7 , V_26 ,
L_151 ) ;
if ( F_12 ( V_7 , V_19 -> V_243 , 0x00000000 ) )
F_7 ( V_7 , ERROR ,
L_152 ) ;
}
F_161 ( V_29 ) ;
F_159 ( V_29 , V_13 -> V_321 ) ;
F_159 ( V_29 , V_13 -> V_20 ) ;
F_160 ( V_29 , 2 ) ;
F_160 ( V_29 , 0 ) ;
F_148 ( V_7 ) ;
}
static int F_164 ( struct V_6 * V_7 )
{
int V_40 , V_69 , V_327 ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
if ( V_13 -> V_23 . V_19 -> V_328 ) {
for ( V_69 = 0 ; V_69 < V_329 ; V_69 ++ )
V_13 -> V_330 [ V_69 ] . V_298 = V_69 ;
V_40 = F_165 ( V_29 , V_13 -> V_330 ,
V_329 ) ;
if ( ! V_40 ) {
for ( V_69 = 0 ; V_69 < V_329 ; V_69 ++ ) {
V_13 -> V_331 [ V_69 ] . V_2 = V_29 ;
V_13 -> V_331 [ V_69 ] . V_245 = V_69 ;
V_40 = F_166 ( V_13 -> V_330 [ V_69 ] . V_332 ,
F_125 , 0 ,
L_153 ,
& V_13 -> V_331 [ V_69 ] ) ;
if ( V_40 )
break;
}
if ( V_40 ) {
F_7 ( V_7 , V_26 , L_154 ,
V_40 ) ;
for ( V_327 = 0 ; V_327 < V_69 ; V_327 ++ )
F_167 ( V_13 -> V_330 [ V_327 ] . V_332 ,
& V_13 -> V_331 [ V_69 ] ) ;
F_168 ( V_29 ) ;
} else {
F_7 ( V_7 , V_220 , L_155 ) ;
V_13 -> V_250 = 1 ;
return 0 ;
}
}
}
if ( F_169 ( V_29 ) != 0 )
F_170 ( V_29 ) ;
else
V_13 -> V_247 = 1 ;
F_7 ( V_7 , V_26 , L_156 , V_13 -> V_247 ) ;
V_13 -> V_333 . V_2 = V_29 ;
V_13 -> V_333 . V_245 = - 1 ;
V_40 = F_166 ( V_29 -> V_257 , F_125 , V_334 ,
L_157 , & V_13 -> V_333 ) ;
if ( V_40 ) {
F_37 ( L_158 , V_40 ) ;
return - 1 ;
}
return 0 ;
}
static void F_171 ( struct V_6 * V_7 )
{
int V_335 = 0 ;
int V_336 , V_337 ;
struct V_12 * V_13 = V_7 -> V_13 ;
switch ( V_13 -> V_2 -> V_1 ) {
case V_142 :
strcpy ( V_7 -> V_338 , V_339 ) ;
break;
case V_143 :
F_12 ( V_7 , 0x0c58 , 0x80c00000 ) ;
F_14 ( V_7 , 0x0c58 , & V_335 ) ;
V_335 &= 0xff00 ;
switch ( V_335 ) {
case V_340 :
strcpy ( V_7 -> V_338 , V_341 ) ;
break;
case V_342 :
strcpy ( V_7 -> V_338 , V_343 ) ;
break;
default:
strcpy ( V_7 -> V_338 , V_344 ) ;
break;
}
break;
case V_144 :
F_14 ( V_7 , 0x8 , & V_335 ) ;
F_14 ( V_7 , 0x0cd0 , & V_336 ) ;
F_14 ( V_7 , 0x0cd4 , & V_337 ) ;
V_335 &= 0xff ;
V_336 &= 0x7 ;
V_337 &= 0xff ;
if ( V_335 == V_345 &&
V_337 == V_346 &&
V_336 == V_347 )
strcpy ( V_7 -> V_338 , V_348 ) ;
else
strcpy ( V_7 -> V_338 , V_349 ) ;
break;
default:
break;
}
}
static int F_172 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
V_13 -> V_7 = V_7 ;
if ( F_164 ( V_7 ) )
return - 1 ;
V_7 -> V_48 = V_13 -> V_23 . V_48 ;
V_7 -> V_50 = V_13 -> V_23 . V_50 ;
V_7 -> V_51 = V_13 -> V_23 . V_51 ;
V_7 -> V_350 = V_13 -> V_23 . V_52 ;
F_171 ( V_7 ) ;
return 0 ;
}
static void F_173 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
int V_69 ;
if ( V_13 -> V_250 ) {
for ( V_69 = 0 ; V_69 < V_329 ; V_69 ++ )
F_174 ( V_13 -> V_330 [ V_69 ] . V_332 ) ;
for ( V_69 = 0 ; V_69 < V_329 ; V_69 ++ )
F_167 ( V_13 -> V_330 [ V_69 ] . V_332 ,
& V_13 -> V_331 [ V_69 ] ) ;
V_13 -> V_250 = 0 ;
F_168 ( V_29 ) ;
} else {
F_7 ( V_7 , V_26 ,
L_159 , V_57 ) ;
F_167 ( V_13 -> V_2 -> V_257 , & V_13 -> V_333 ) ;
if ( V_13 -> V_247 )
F_170 ( V_29 ) ;
}
V_13 -> V_7 = NULL ;
}
static void F_175 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_28 * V_29 = V_13 -> V_2 ;
V_7 -> V_48 = V_13 -> V_23 . V_48 ;
F_147 ( V_7 ) ;
F_152 ( V_29 ) ;
}
static void F_176 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_22 * V_19 = V_13 -> V_23 . V_19 ;
struct V_28 * V_29 = V_13 -> V_2 ;
if ( F_12 ( V_7 , V_19 -> V_243 , 0x00000000 ) )
F_7 ( V_7 , ERROR , L_152 ) ;
F_177 ( V_29 ) ;
V_7 -> V_351 = 0 ;
F_148 ( V_7 ) ;
}
