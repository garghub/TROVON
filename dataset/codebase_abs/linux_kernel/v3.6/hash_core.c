static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 -> V_5 = NULL ;
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_5 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
F_6 ( V_2 -> V_11 . V_12 ) ;
F_7 ( V_13 , V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_14 = V_10 -> V_15 ;
V_2 -> V_11 . V_16 =
F_8 ( V_2 -> V_11 . V_12 ,
V_10 -> V_17 ,
V_2 -> V_11 . V_14 ) ;
F_9 ( & V_2 -> V_11 . V_18 ) ;
}
static void F_10 ( void * V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_19 ;
V_18 ( & V_21 -> V_5 -> V_11 . V_18 ) ;
}
static int F_11 ( struct V_20 * V_21 , struct V_22 * V_23 ,
int V_24 , enum V_25 V_26 )
{
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
T_1 V_31 ;
if ( V_26 != V_32 ) {
F_12 ( V_21 -> V_5 -> V_8 , L_1 ,
V_33 ) ;
return - V_34 ;
}
V_23 -> V_35 = F_13 ( V_23 -> V_35 , V_36 ) ;
V_30 = V_21 -> V_5 -> V_11 . V_16 ;
V_21 -> V_5 -> V_11 . V_23 = V_23 ;
V_21 -> V_5 -> V_11 . V_37 = F_14 ( V_30 -> V_5 -> V_8 ,
V_21 -> V_5 -> V_11 . V_23 , V_21 -> V_5 -> V_11 . V_38 ,
V_26 ) ;
if ( ! V_21 -> V_5 -> V_11 . V_37 ) {
F_12 ( V_21 -> V_5 -> V_8 ,
L_2 ,
V_33 ) ;
return - V_34 ;
}
F_15 ( V_21 -> V_5 -> V_8 , L_3
L_4 , V_33 ) ;
V_28 = V_30 -> V_5 -> V_39 ( V_30 ,
V_21 -> V_5 -> V_11 . V_23 , V_21 -> V_5 -> V_11 . V_37 ,
V_26 , V_40 | V_41 , NULL ) ;
if ( ! V_28 ) {
F_12 ( V_21 -> V_5 -> V_8 ,
L_5 , V_33 ) ;
return - V_34 ;
}
V_28 -> V_42 = F_10 ;
V_28 -> V_43 = V_21 ;
V_31 = V_28 -> V_44 ( V_28 ) ;
F_16 ( V_30 ) ;
return 0 ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_29 * V_45 ;
V_45 = V_21 -> V_5 -> V_11 . V_16 ;
V_45 -> V_5 -> V_46 ( V_45 , V_47 , 0 ) ;
F_18 ( V_45 -> V_5 -> V_8 , V_21 -> V_5 -> V_11 . V_23 ,
V_21 -> V_5 -> V_11 . V_37 , V_32 ) ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
int error = F_11 ( V_21 , V_23 , V_24 , V_32 ) ;
if ( error ) {
F_15 ( V_21 -> V_5 -> V_8 , L_6
L_7 , V_33 ) ;
return error ;
}
return V_24 ;
}
static int F_20 (
struct V_1 * V_2 ,
T_2 * V_48 , T_3 * V_49 , bool * V_50 )
{
int V_51 = 0 ;
struct V_20 * V_21 = V_2 -> V_4 ;
* V_50 = false ;
if ( V_52 == V_21 -> V_53 . V_54 ) {
if ( V_55 == V_21 -> V_53 . V_56 ) {
memcpy ( V_48 , & V_57 [ 0 ] ,
V_58 ) ;
* V_49 = V_58 ;
* V_50 = true ;
} else if ( V_59 ==
V_21 -> V_53 . V_56 ) {
memcpy ( V_48 , & V_60 [ 0 ] ,
V_61 ) ;
* V_49 = V_61 ;
* V_50 = true ;
} else {
F_12 ( V_2 -> V_8 , L_8
L_9
, V_33 ) ;
V_51 = - V_62 ;
goto V_63;
}
} else if ( V_64 == V_21 -> V_53 . V_54 ) {
if ( ! V_21 -> V_65 ) {
if ( V_55 == V_21 -> V_53 . V_56 ) {
memcpy ( V_48 , & V_66 [ 0 ] ,
V_58 ) ;
* V_49 = V_58 ;
* V_50 = true ;
} else if ( V_59 == V_21 -> V_53 . V_56 ) {
memcpy ( V_48 , & V_67 [ 0 ] ,
V_61 ) ;
* V_49 = V_61 ;
* V_50 = true ;
} else {
F_12 ( V_2 -> V_8 , L_8
L_9
, V_33 ) ;
V_51 = - V_62 ;
goto V_63;
}
} else {
F_15 ( V_2 -> V_8 , L_10
L_11 ,
V_33 ) ;
}
}
V_63:
return V_51 ;
}
static int F_21 (
struct V_1 * V_2 ,
bool V_68 )
{
int V_51 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_69 ) ;
if ( ! V_2 -> V_70 )
goto V_63;
if ( V_68 ) {
F_22 ( V_2 ,
& V_2 -> V_71 ) ;
V_2 -> V_72 = true ;
}
F_23 ( V_2 -> V_73 ) ;
V_51 = F_24 ( V_2 -> V_74 ) ;
if ( V_51 )
F_12 ( V_8 , L_12 , V_33 ) ;
V_2 -> V_70 = false ;
V_63:
F_3 ( & V_2 -> V_69 ) ;
return V_51 ;
}
static int F_25 (
struct V_1 * V_2 ,
bool V_75 )
{
int V_51 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_69 ) ;
if ( ! V_2 -> V_70 ) {
V_51 = F_26 ( V_2 -> V_74 ) ;
if ( V_51 ) {
F_12 ( V_8 , L_13 ,
V_33 ) ;
goto V_63;
}
V_51 = F_27 ( V_2 -> V_73 ) ;
if ( V_51 ) {
F_12 ( V_8 , L_14 ,
V_33 ) ;
V_51 = F_24 (
V_2 -> V_74 ) ;
goto V_63;
}
V_2 -> V_70 = true ;
}
if ( V_2 -> V_72 ) {
if ( V_75 ) {
V_2 -> V_72 = false ;
F_28 ( V_2 ,
& V_2 -> V_71 ) ;
}
}
V_63:
F_3 ( & V_2 -> V_69 ) ;
return V_51 ;
}
static int F_29 ( struct V_20 * V_21 ,
struct V_1 * * V_2 )
{
int V_51 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
struct V_1 * V_80 = NULL ;
V_51 = F_30 ( & V_6 . V_7 ) ;
if ( V_51 )
return V_51 ;
F_31 ( & V_6 . V_81 , & V_77 ) ;
V_79 = F_32 ( & V_77 ) ;
while ( V_79 ) {
V_80 = F_33 ( V_79 ,
struct V_1 , V_82 ) ;
F_2 ( & V_80 -> V_3 ) ;
if ( V_80 -> V_4 ) {
V_79 = F_32 ( & V_77 ) ;
} else {
V_80 -> V_4 = V_21 ;
V_21 -> V_5 = V_80 ;
F_3 ( & V_80 -> V_3 ) ;
break;
}
F_3 ( & V_80 -> V_3 ) ;
}
F_34 ( & V_77 ) ;
if ( ! V_79 ) {
return - V_83 ;
}
* V_2 = V_80 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
const T_2 * V_84 , unsigned int V_65 )
{
T_3 V_85 = 0 ;
int V_86 = 1 ;
F_36 ( & V_2 -> V_87 -> V_88 , V_89 ) ;
while ( V_65 >= 4 ) {
T_3 * V_90 = ( T_3 * ) V_84 ;
F_37 ( V_90 , V_86 ) ;
V_65 -= 4 ;
V_84 += 4 ;
}
if ( V_65 ) {
V_85 = 0 ;
while ( V_65 ) {
V_85 |= ( V_84 [ V_65 - 1 ] << ( 8 * ( V_65 - 1 ) ) ) ;
V_65 -- ;
}
F_37 ( & V_85 , V_86 ) ;
}
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
V_92 ;
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_51 = 0 ;
V_51 = F_40 ( V_2 , & V_21 -> V_53 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_15
L_16 , V_33 ) ;
return V_51 ;
}
F_41 ( V_2 , V_21 ) ;
if ( V_21 -> V_53 . V_54 == V_64 )
F_35 ( V_2 , V_21 -> V_84 , V_21 -> V_65 ) ;
return V_51 ;
}
static int F_42 ( struct V_22 * V_23 , int V_93 , bool * V_94 )
{
int V_38 = 0 ;
bool V_95 = true ;
while ( V_93 > 0 && V_23 ) {
V_38 ++ ;
V_93 -= V_23 -> V_35 ;
if ( ( V_94 && ! F_43 ( V_23 -> V_96 , V_36 ) )
|| ( ! F_43 ( V_23 -> V_35 , V_36 ) &&
V_93 > 0 ) )
V_95 = false ;
V_23 = F_44 ( V_23 ) ;
}
if ( V_94 )
* V_94 = V_95 ;
if ( V_93 != 0 )
return - V_34 ;
return V_38 ;
}
static bool F_45 ( struct V_22 * V_23 , int V_97 )
{
bool V_94 ;
if ( F_42 ( V_23 , V_97 , & V_94 ) < 1 )
return false ;
return V_94 ;
}
static int F_46 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
if ( ! V_21 -> V_84 )
V_21 -> V_65 = 0 ;
memset ( & V_103 -> V_71 , 0 , sizeof( struct V_104 ) ) ;
V_103 -> V_105 = 0 ;
if ( V_106 == V_107 ) {
if ( V_99 -> V_108 < V_36 ) {
V_103 -> V_109 = false ;
F_50 ( V_110 L_17
L_18 ,
V_33 , V_36 ) ;
} else {
if ( V_99 -> V_108 >= V_111 &&
F_45 ( V_99 -> V_112 ,
V_99 -> V_108 ) ) {
V_103 -> V_109 = true ;
} else {
V_103 -> V_109 = false ;
F_50 ( V_110 L_19
L_20
L_21
L_22 , V_33 ,
V_111 ) ;
}
}
}
return 0 ;
}
static void F_51 (
struct V_1 * V_2 ,
const T_3 * V_113 , int V_35 )
{
int V_24 = V_35 / V_114 ;
F_36 ( & V_2 -> V_87 -> V_88 , V_89 ) ;
F_37 ( V_113 , V_24 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
const T_3 * V_113 , T_2 V_115 )
{
int V_86 = 1 ;
F_36 ( & V_2 -> V_87 -> V_88 , V_89 ) ;
while ( V_115 >= 4 ) {
F_37 ( V_113 , V_86 ) ;
V_115 -= 4 ;
V_113 ++ ;
}
if ( V_115 )
F_37 ( V_113 , V_86 ) ;
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
F_53 ( V_115 * 8 ) ;
F_15 ( V_2 -> V_8 , L_23 , V_33 ,
F_54 ( & V_2 -> V_87 -> V_116 ) ,
( int ) ( F_54 ( & V_2 -> V_87 -> V_88 ) &
V_89 ) ) ;
V_92 ;
F_15 ( V_2 -> V_8 , L_24 ,
V_33 , F_54 ( & V_2 -> V_87 -> V_116 ) ,
( int ) ( F_54 ( & V_2 -> V_87 -> V_88 ) &
V_89 ) ) ;
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
}
static void F_55 ( struct V_102 * V_21 , T_3 V_117 )
{
V_21 -> V_71 . V_35 . V_118 += V_117 ;
if ( V_21 -> V_71 . V_35 . V_118 < V_117 )
V_21 -> V_71 . V_35 . V_119 ++ ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_120 * V_53 )
{
int V_51 = 0 ;
if ( V_53 -> V_56 != V_55 &&
V_53 -> V_56 != V_59 )
return - V_121 ;
F_56 ( V_53 -> V_122 ) ;
switch ( V_53 -> V_56 ) {
case V_55 :
F_57 ( & V_2 -> V_87 -> V_123 , V_124 ) ;
break;
case V_59 :
F_36 ( & V_2 -> V_87 -> V_123 , V_124 ) ;
break;
default:
F_12 ( V_2 -> V_8 , L_25 ,
V_33 ) ;
return - V_121 ;
}
if ( V_52 == V_53 -> V_54 )
F_36 ( & V_2 -> V_87 -> V_123 ,
V_125 ) ;
else if ( V_64 == V_53 -> V_54 ) {
F_57 ( & V_2 -> V_87 -> V_123 ,
V_125 ) ;
if ( V_2 -> V_4 -> V_65 > V_126 ) {
F_15 ( V_2 -> V_8 , L_26 , V_33 ) ;
F_57 ( & V_2 -> V_87 -> V_123 ,
V_127 ) ;
} else {
F_15 ( V_2 -> V_8 , L_27 ,
V_33 ) ;
F_36 ( & V_2 -> V_87 -> V_123 ,
V_127 ) ;
}
} else {
V_51 = - V_121 ;
F_12 ( V_2 -> V_8 , L_28 ,
V_33 ) ;
}
return V_51 ;
}
void F_41 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
V_128 ;
F_36 ( & V_2 -> V_87 -> V_88 , V_89 ) ;
}
int F_58 (
struct V_1 * V_2 ,
struct V_20 * V_21 , struct V_102 * V_103 ,
int V_129 , T_2 * V_130 , T_2 * V_131 , T_2 * V_132 )
{
int V_51 = 0 ;
T_3 V_133 ;
do {
if ( ( * V_132 + V_129 ) < V_126 ) {
for ( V_133 = 0 ; V_133 < V_129 ; V_133 ++ ) {
V_131 [ * V_132 + V_133 ] =
* ( V_130 + V_133 ) ;
}
* V_132 += V_129 ;
V_129 = 0 ;
} else {
if ( V_103 -> V_105 ) {
V_51 = F_28 ( V_2 ,
& V_2 -> V_71 ) ;
memmove ( V_103 -> V_71 . V_131 ,
V_2 -> V_71 . V_131 ,
V_126 / sizeof( T_3 ) ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_8
L_29
L_30 , V_33 ) ;
goto V_63;
}
} else {
V_51 = F_39 ( V_2 , V_21 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_8
L_31
L_30 , V_33 ) ;
goto V_63;
}
V_103 -> V_105 = 1 ;
}
if ( ( 0 == ( ( ( T_3 ) V_130 ) % 4 ) )
&& ( 0 == * V_132 ) )
F_51 ( V_2 ,
( const T_3 * )
V_130 , V_126 ) ;
else {
for ( V_133 = 0 ; V_133 <
( T_3 ) ( V_126 -
* V_132 ) ;
V_133 ++ ) {
V_131 [ * V_132 + V_133 ] =
* ( V_130 + V_133 ) ;
}
F_51 ( V_2 ,
( const T_3 * ) V_131 ,
V_126 ) ;
}
F_55 ( V_103 , V_126 ) ;
V_130 += ( V_126 - * V_132 ) ;
V_129 -= ( V_126 - * V_132 ) ;
* V_132 = 0 ;
V_51 = F_22 ( V_2 ,
& V_2 -> V_71 ) ;
memmove ( V_2 -> V_71 . V_131 ,
V_103 -> V_71 . V_131 ,
V_126 / sizeof( T_3 ) ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_8
L_32
L_30 , V_33 ) ;
goto V_63;
}
}
} while ( V_129 != 0 );
V_63:
return V_51 ;
}
static int F_59 ( struct V_98 * V_99 )
{
int V_51 = 0 ;
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
struct V_1 * V_2 ;
T_2 V_134 [ V_61 ] ;
int V_135 = 0 ;
V_51 = F_29 ( V_21 , & V_2 ) ;
if ( V_51 )
return V_51 ;
F_15 ( V_2 -> V_8 , L_33 , V_33 , ( T_3 ) V_21 ) ;
if ( V_103 -> V_105 ) {
V_51 = F_28 ( V_2 , & V_2 -> V_71 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_34
L_16 , V_33 ) ;
goto V_63;
}
}
if ( ! V_103 -> V_105 ) {
V_51 = F_40 ( V_2 , & V_21 -> V_53 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_8
L_35 ,
V_33 ) ;
goto V_63;
}
if ( V_106 != V_107 || ! V_103 -> V_109 ) {
F_36 ( & V_2 -> V_87 -> V_123 ,
V_136 ) ;
} else {
F_57 ( & V_2 -> V_87 -> V_123 ,
V_136 ) ;
F_57 ( & V_2 -> V_87 -> V_123 ,
V_137 ) ;
}
V_128 ;
if ( V_21 -> V_53 . V_54 == V_64 )
F_35 ( V_2 , V_21 -> V_84 , V_21 -> V_65 ) ;
F_53 ( ( V_99 -> V_108 * 8 ) % 32 ) ;
V_103 -> V_105 = 1 ;
}
V_21 -> V_5 -> V_11 . V_38 = F_42 ( V_99 -> V_112 , V_99 -> V_108 , NULL ) ;
if ( ! V_21 -> V_5 -> V_11 . V_38 ) {
F_12 ( V_2 -> V_8 , L_8
L_36 , V_33 ) ;
goto V_63;
}
V_135 = F_19 ( V_21 , V_99 -> V_112 , V_99 -> V_108 ) ;
if ( V_135 != V_99 -> V_108 ) {
F_12 ( V_2 -> V_8 , L_8
L_37 , V_33 ) ;
goto V_63;
}
F_60 ( & V_21 -> V_5 -> V_11 . V_18 ) ;
F_17 ( V_21 ) ;
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
if ( V_21 -> V_53 . V_54 == V_64 && V_21 -> V_84 ) {
unsigned int V_65 = V_21 -> V_65 ;
T_2 * V_84 = V_21 -> V_84 ;
F_15 ( V_2 -> V_8 , L_38 , V_33 ,
V_21 -> V_65 ) ;
F_35 ( V_2 , V_84 , V_65 ) ;
}
F_61 ( V_2 , V_134 , V_21 -> V_53 . V_56 ) ;
memcpy ( V_99 -> V_138 , V_134 , V_21 -> V_139 ) ;
V_63:
F_1 ( V_2 ) ;
F_62 ( V_21 -> V_84 ) ;
return V_51 ;
}
int F_63 ( struct V_98 * V_99 )
{
int V_51 = 0 ;
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
struct V_1 * V_2 ;
T_2 V_134 [ V_61 ] ;
V_51 = F_29 ( V_21 , & V_2 ) ;
if ( V_51 )
return V_51 ;
F_15 ( V_2 -> V_8 , L_33 , V_33 , ( T_3 ) V_21 ) ;
if ( V_103 -> V_105 ) {
V_51 = F_28 ( V_2 , & V_2 -> V_71 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_34
L_16 , V_33 ) ;
goto V_63;
}
} else if ( V_99 -> V_108 == 0 && V_21 -> V_65 == 0 ) {
T_2 V_48 [ V_61 ] ;
T_3 V_49 = 0 ;
bool V_50 = false ;
V_51 = F_20 ( V_2 , & V_48 [ 0 ] ,
& V_49 , & V_50 ) ;
if ( ! V_51 && F_64 ( V_49 == V_21 -> V_139 ) &&
V_50 ) {
memcpy ( V_99 -> V_138 , & V_48 [ 0 ] , V_21 -> V_139 ) ;
goto V_63;
} else if ( ! V_51 && ! V_50 ) {
F_15 ( V_2 -> V_8 , L_39
L_40 , V_33 ) ;
} else {
F_12 ( V_2 -> V_8 , L_41
L_42 , V_33 , V_51 ,
( V_49 == V_21 -> V_139 ) ?
L_43 : L_44 ) ;
goto V_63;
}
} else if ( V_99 -> V_108 == 0 && V_21 -> V_65 > 0 ) {
F_12 ( V_2 -> V_8 , L_45
L_46 , V_33 ) ;
goto V_63;
}
if ( ! V_103 -> V_105 ) {
V_51 = F_39 ( V_2 , V_21 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_47
L_16 , V_33 ) ;
goto V_63;
}
}
if ( V_103 -> V_71 . V_132 ) {
F_52 ( V_2 , V_103 -> V_71 . V_131 ,
V_103 -> V_71 . V_132 ) ;
} else {
V_92 ;
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
}
if ( V_21 -> V_53 . V_54 == V_64 && V_21 -> V_84 ) {
unsigned int V_65 = V_21 -> V_65 ;
T_2 * V_84 = V_21 -> V_84 ;
F_15 ( V_2 -> V_8 , L_38 , V_33 ,
V_21 -> V_65 ) ;
F_35 ( V_2 , V_84 , V_65 ) ;
}
F_61 ( V_2 , V_134 , V_21 -> V_53 . V_56 ) ;
memcpy ( V_99 -> V_138 , V_134 , V_21 -> V_139 ) ;
V_63:
F_1 ( V_2 ) ;
F_62 ( V_21 -> V_84 ) ;
return V_51 ;
}
int F_65 ( struct V_98 * V_99 )
{
int V_51 = 0 ;
T_2 V_132 = 0 ;
T_2 * V_131 ;
struct V_1 * V_2 ;
T_2 * V_130 ;
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
struct V_140 V_141 ;
int V_129 = F_66 ( V_99 , & V_141 ) ;
if ( V_129 == 0 )
return V_51 ;
V_132 = V_103 -> V_71 . V_132 ;
V_131 = ( T_2 * ) V_103 -> V_71 . V_131 ;
if ( V_129 > ( V_103 -> V_71 . V_35 . V_118 + V_129 ) &&
V_142 ==
V_103 -> V_71 . V_35 . V_119 ) {
F_67 ( V_110 L_48 ,
V_33 ) ;
return - V_121 ;
}
V_51 = F_29 ( V_21 , & V_2 ) ;
if ( V_51 )
return V_51 ;
while ( 0 != V_129 ) {
V_130 = V_141 . V_19 ;
V_51 = F_58 ( V_2 , V_21 , V_103 , V_129 ,
V_130 , V_131 , & V_132 ) ;
if ( V_51 ) {
F_12 ( V_2 -> V_8 , L_49
L_50 , V_33 ) ;
goto V_63;
}
V_129 = F_68 ( & V_141 , 0 ) ;
}
V_103 -> V_71 . V_132 = V_132 ;
F_15 ( V_2 -> V_8 , L_51 ,
V_33 , V_103 -> V_71 . V_132 ,
V_103 -> V_71 . V_143 ) ;
V_63:
F_1 ( V_2 ) ;
return V_51 ;
}
int F_28 ( struct V_1 * V_2 ,
const struct V_104 * V_144 )
{
T_3 V_145 ;
T_4 V_133 ;
int V_106 = V_52 ;
if ( NULL == V_144 ) {
F_12 ( V_2 -> V_8 , L_28 ,
V_33 ) ;
return - V_121 ;
}
if ( V_144 -> V_132 > V_126
|| ( V_144 -> V_35 . V_118 % V_126 ) != 0 ) {
F_12 ( V_2 -> V_8 , L_28 ,
V_33 ) ;
return - V_121 ;
}
V_128 ;
V_145 = V_144 -> V_145 ;
F_69 ( V_145 & V_146 , & V_2 -> V_87 -> V_123 ) ;
if ( V_2 -> V_87 -> V_123 & V_125 )
V_106 = V_64 ;
else
V_106 = V_52 ;
for ( V_133 = 0 ; V_133 < V_147 ; V_133 ++ ) {
if ( ( V_133 >= 36 ) && ( V_106 == V_52 ) )
break;
F_69 ( V_144 -> V_148 [ V_133 ] ,
& V_2 -> V_87 -> V_149 [ V_133 ] ) ;
}
F_69 ( V_144 -> V_150 , & V_2 -> V_87 -> V_150 ) ;
F_69 ( V_144 -> V_151 , & V_2 -> V_87 -> V_151 ) ;
F_69 ( V_144 -> V_152 , & V_2 -> V_87 -> V_88 ) ;
F_69 ( V_145 , & V_2 -> V_87 -> V_123 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_104 * V_144 )
{
T_3 V_145 ;
T_3 V_133 ;
int V_106 = V_52 ;
if ( NULL == V_144 ) {
F_12 ( V_2 -> V_8 , L_28 ,
V_33 ) ;
return - V_153 ;
}
while ( V_2 -> V_87 -> V_88 & V_91 )
F_38 () ;
V_145 = F_54 ( & V_2 -> V_87 -> V_123 ) ;
V_144 -> V_152 = F_54 ( & V_2 -> V_87 -> V_88 ) ;
V_144 -> V_154 = F_54 ( & V_2 -> V_87 -> V_116 ) ;
if ( V_2 -> V_87 -> V_123 & V_125 )
V_106 = V_64 ;
else
V_106 = V_52 ;
for ( V_133 = 0 ; V_133 < V_147 ; V_133 ++ ) {
if ( ( V_133 >= 36 ) && ( V_106 == V_52 ) )
break;
V_144 -> V_148 [ V_133 ] =
F_54 ( & V_2 -> V_87 -> V_149 [ V_133 ] ) ;
}
V_144 -> V_150 = F_54 ( & V_2 -> V_87 -> V_150 ) ;
V_144 -> V_151 = F_54 ( & V_2 -> V_87 -> V_151 ) ;
V_144 -> V_145 = V_145 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 )
{
if ( V_155 == F_54 ( & V_2 -> V_87 -> V_156 )
&& V_157 == F_54 ( & V_2 -> V_87 -> V_158 )
&& V_159 == F_54 ( & V_2 -> V_87 -> V_160 )
&& V_161 == F_54 ( & V_2 -> V_87 -> V_162 )
&& V_163 == F_54 ( & V_2 -> V_87 -> V_164 )
&& V_165 == F_54 ( & V_2 -> V_87 -> V_166 )
&& V_167 == F_54 ( & V_2 -> V_87 -> V_168 )
&& V_169 == F_54 ( & V_2 -> V_87 -> V_170 )
) {
return 0 ;
}
F_12 ( V_2 -> V_8 , L_52 ,
V_33 ) ;
return - V_153 ;
}
void F_61 ( struct V_1 * V_2 ,
T_2 * V_134 , int V_56 )
{
T_3 V_171 , V_133 ;
int V_172 ;
if ( V_56 != V_55 && V_56 != V_59 ) {
F_12 ( V_2 -> V_8 , L_53 ,
V_33 , V_56 ) ;
return;
}
if ( V_56 == V_55 )
V_172 = V_58 / sizeof( T_3 ) ;
else
V_172 = V_61 / sizeof( T_3 ) ;
F_15 ( V_2 -> V_8 , L_54 ,
V_33 , ( T_3 ) V_134 ) ;
for ( V_133 = 0 ; V_133 < V_172 ; V_133 ++ ) {
V_171 = F_54 ( & V_2 -> V_87 -> V_173 [ V_133 ] ) ;
V_134 [ V_133 * 4 ] = ( T_2 ) ( ( V_171 >> 24 ) & 0xFF ) ;
V_134 [ V_133 * 4 + 1 ] = ( T_2 ) ( ( V_171 >> 16 ) & 0xFF ) ;
V_134 [ V_133 * 4 + 2 ] = ( T_2 ) ( ( V_171 >> 8 ) & 0xFF ) ;
V_134 [ V_133 * 4 + 3 ] = ( T_2 ) ( ( V_171 >> 0 ) & 0xFF ) ;
}
}
static int F_71 ( struct V_98 * V_99 )
{
int V_51 = 0 ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
if ( V_106 != V_107 || ! V_103 -> V_109 )
V_51 = F_65 ( V_99 ) ;
if ( V_51 ) {
F_67 ( V_110 L_55 ,
V_33 ) ;
}
return V_51 ;
}
static int F_72 ( struct V_98 * V_99 )
{
int V_51 = 0 ;
struct V_102 * V_103 = F_49 ( V_99 ) ;
F_50 ( V_110 L_56 , V_33 , V_99 -> V_108 ) ;
if ( ( V_106 == V_107 ) && V_103 -> V_109 )
V_51 = F_59 ( V_99 ) ;
else
V_51 = F_63 ( V_99 ) ;
if ( V_51 ) {
F_67 ( V_110 L_57 ,
V_33 ) ;
}
return V_51 ;
}
static int F_73 ( struct V_100 * V_101 ,
const T_2 * V_84 , unsigned int V_65 , int V_174 )
{
int V_51 = 0 ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
V_21 -> V_84 = F_74 ( V_65 , V_175 ) ;
if ( ! V_21 -> V_84 ) {
F_67 ( V_110 L_58
L_59 , V_33 , V_174 ) ;
return - V_176 ;
}
memcpy ( V_21 -> V_84 , V_84 , V_65 ) ;
V_21 -> V_65 = V_65 ;
return V_51 ;
}
static int F_75 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
V_21 -> V_53 . V_122 = V_177 ;
V_21 -> V_53 . V_56 = V_55 ;
V_21 -> V_53 . V_54 = V_52 ;
V_21 -> V_139 = V_58 ;
return F_46 ( V_99 ) ;
}
static int F_76 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
V_21 -> V_53 . V_122 = V_177 ;
V_21 -> V_53 . V_56 = V_59 ;
V_21 -> V_53 . V_54 = V_52 ;
V_21 -> V_139 = V_61 ;
return F_46 ( V_99 ) ;
}
static int F_77 ( struct V_98 * V_99 )
{
int V_178 , V_179 ;
V_179 = F_75 ( V_99 ) ;
if ( V_179 )
goto V_63;
V_179 = F_71 ( V_99 ) ;
V_178 = F_72 ( V_99 ) ;
V_63:
return V_179 ? V_179 : V_178 ;
}
static int F_78 ( struct V_98 * V_99 )
{
int V_178 , V_179 ;
V_179 = F_76 ( V_99 ) ;
if ( V_179 )
goto V_63;
V_179 = F_71 ( V_99 ) ;
V_178 = F_72 ( V_99 ) ;
V_63:
return V_179 ? V_179 : V_178 ;
}
static int F_79 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
V_21 -> V_53 . V_122 = V_177 ;
V_21 -> V_53 . V_56 = V_55 ;
V_21 -> V_53 . V_54 = V_64 ;
V_21 -> V_139 = V_58 ;
return F_46 ( V_99 ) ;
}
static int F_80 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_47 ( V_99 ) ;
struct V_20 * V_21 = F_48 ( V_101 ) ;
V_21 -> V_53 . V_122 = V_177 ;
V_21 -> V_53 . V_56 = V_59 ;
V_21 -> V_53 . V_54 = V_64 ;
V_21 -> V_139 = V_61 ;
return F_46 ( V_99 ) ;
}
static int F_81 ( struct V_98 * V_99 )
{
int V_178 , V_179 ;
V_179 = F_79 ( V_99 ) ;
if ( V_179 )
goto V_63;
V_179 = F_71 ( V_99 ) ;
V_178 = F_72 ( V_99 ) ;
V_63:
return V_179 ? V_179 : V_178 ;
}
static int F_82 ( struct V_98 * V_99 )
{
int V_178 , V_179 ;
V_179 = F_80 ( V_99 ) ;
if ( V_179 )
goto V_63;
V_179 = F_71 ( V_99 ) ;
V_178 = F_72 ( V_99 ) ;
V_63:
return V_179 ? V_179 : V_178 ;
}
static int F_83 ( struct V_100 * V_101 ,
const T_2 * V_84 , unsigned int V_65 )
{
return F_73 ( V_101 , V_84 , V_65 , V_55 ) ;
}
static int F_84 ( struct V_100 * V_101 ,
const T_2 * V_84 , unsigned int V_65 )
{
return F_73 ( V_101 , V_84 , V_65 , V_59 ) ;
}
static int F_85 ( struct V_180 * V_101 )
{
struct V_20 * V_21 = F_86 ( V_101 ) ;
struct V_181 * V_174 = V_101 -> V_182 ;
struct V_183 * V_184 ;
V_184 = F_33 ( F_87 ( V_174 ) ,
struct V_183 ,
V_185 ) ;
F_88 ( F_89 ( V_101 ) ,
sizeof( struct V_102 ) ) ;
V_21 -> V_53 . V_122 = V_177 ;
V_21 -> V_53 . V_56 = V_184 -> V_186 . V_56 ;
V_21 -> V_53 . V_54 = V_184 -> V_186 . V_54 ;
V_21 -> V_139 = V_184 -> V_185 . V_187 . V_139 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_51 ;
int V_188 ;
int V_133 ;
for ( V_188 = 0 ; V_188 < F_91 ( V_189 ) ; V_188 ++ ) {
V_51 = F_92 ( & V_189 [ V_188 ] . V_185 ) ;
if ( V_51 ) {
V_133 = V_188 ;
F_12 ( V_2 -> V_8 , L_60 ,
V_189 [ V_188 ] . V_185 . V_187 . V_87 . V_190 ) ;
goto V_191;
}
}
return 0 ;
V_191:
for ( V_188 = 0 ; V_188 < V_133 ; V_188 ++ )
F_93 ( & V_189 [ V_188 ] . V_185 ) ;
return V_51 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_188 ;
for ( V_188 = 0 ; V_188 < F_91 ( V_189 ) ; V_188 ++ )
F_93 ( & V_189 [ V_188 ] . V_185 ) ;
}
static int F_95 ( struct V_192 * V_193 )
{
int V_51 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_193 -> V_8 ;
V_2 = F_96 ( sizeof( struct V_1 ) , V_196 ) ;
if ( ! V_2 ) {
F_15 ( V_8 , L_61 , V_33 ) ;
V_51 = - V_176 ;
goto V_63;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = NULL ;
V_195 = F_97 ( V_193 , V_197 , 0 ) ;
if ( ! V_195 ) {
F_15 ( V_8 , L_62 , V_33 ) ;
V_51 = - V_198 ;
goto V_199;
}
V_195 = F_98 ( V_195 -> V_200 , F_99 ( V_195 ) , V_193 -> V_201 ) ;
if ( V_195 == NULL ) {
F_15 ( V_8 , L_63 , V_33 ) ;
V_51 = - V_83 ;
goto V_199;
}
V_2 -> V_87 = F_100 ( V_195 -> V_200 , F_99 ( V_195 ) ) ;
if ( ! V_2 -> V_87 ) {
F_12 ( V_8 , L_64 ,
V_33 ) ;
V_51 = - V_176 ;
goto V_202;
}
F_101 ( & V_2 -> V_3 ) ;
F_101 ( & V_2 -> V_69 ) ;
V_2 -> V_74 = F_102 ( V_8 , L_65 ) ;
if ( F_103 ( V_2 -> V_74 ) ) {
F_12 ( V_8 , L_66 , V_33 ) ;
V_51 = F_104 ( V_2 -> V_74 ) ;
V_2 -> V_74 = NULL ;
goto V_203;
}
V_2 -> V_73 = F_105 ( V_8 , NULL ) ;
if ( F_103 ( V_2 -> V_73 ) ) {
F_12 ( V_8 , L_67 , V_33 ) ;
V_51 = F_104 ( V_2 -> V_73 ) ;
goto V_204;
}
V_51 = F_25 ( V_2 , false ) ;
if ( V_51 ) {
F_12 ( V_8 , L_68 , V_33 ) ;
goto V_205;
}
V_51 = F_70 ( V_2 ) ;
if ( V_51 ) {
F_12 ( V_8 , L_69 , V_33 ) ;
goto V_206;
}
if ( V_106 == V_107 )
F_5 ( V_2 , V_8 ) ;
F_106 ( V_193 , V_2 ) ;
F_107 ( & V_2 -> V_82 , & V_6 . V_81 ) ;
F_4 ( & V_6 . V_7 ) ;
V_51 = F_90 ( V_2 ) ;
if ( V_51 ) {
F_12 ( V_8 , L_70
L_16 , V_33 ) ;
goto V_206;
}
F_108 ( V_8 , L_71 , V_33 ) ;
return 0 ;
V_206:
F_21 ( V_2 , false ) ;
V_205:
F_109 ( V_2 -> V_73 ) ;
V_204:
F_110 ( V_2 -> V_74 ) ;
V_203:
F_111 ( V_2 -> V_87 ) ;
V_202:
F_112 ( V_195 -> V_200 , F_99 ( V_195 ) ) ;
V_199:
F_62 ( V_2 ) ;
V_63:
return V_51 ;
}
static int F_113 ( struct V_192 * V_193 )
{
struct V_194 * V_195 ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_193 -> V_8 ;
V_2 = F_114 ( V_193 ) ;
if ( ! V_2 ) {
F_12 ( V_8 , L_72 ,
V_33 ) ;
return - V_176 ;
}
if ( F_115 ( & V_6 . V_7 ) )
return - V_83 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 ) {
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
return - V_83 ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_116 ( & V_2 -> V_82 ) )
F_117 ( & V_2 -> V_82 ) ;
if ( F_118 ( & V_6 . V_81 . V_207 ) )
F_94 ( V_2 ) ;
if ( F_21 ( V_2 , false ) )
F_12 ( V_8 , L_73 ,
V_33 ) ;
F_109 ( V_2 -> V_73 ) ;
F_110 ( V_2 -> V_74 ) ;
F_111 ( V_2 -> V_87 ) ;
V_195 = F_97 ( V_193 , V_197 , 0 ) ;
if ( V_195 )
F_112 ( V_195 -> V_200 , F_99 ( V_195 ) ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static void F_119 ( struct V_192 * V_193 )
{
struct V_194 * V_195 = NULL ;
struct V_1 * V_2 ;
V_2 = F_114 ( V_193 ) ;
if ( ! V_2 ) {
F_12 ( & V_193 -> V_8 , L_74 ,
V_33 ) ;
return;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_115 ( & V_6 . V_7 ) )
F_15 ( & V_193 -> V_8 , L_75
L_76 , V_33 ) ;
V_2 -> V_4 ++ ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_116 ( & V_2 -> V_82 ) )
F_117 ( & V_2 -> V_82 ) ;
if ( F_118 ( & V_6 . V_81 . V_207 ) )
F_94 ( V_2 ) ;
F_111 ( V_2 -> V_87 ) ;
V_195 = F_97 ( V_193 , V_197 , 0 ) ;
if ( V_195 )
F_112 ( V_195 -> V_200 , F_99 ( V_195 ) ) ;
if ( F_21 ( V_2 , false ) )
F_12 ( & V_193 -> V_8 , L_77 ,
V_33 ) ;
}
static int F_120 ( struct V_5 * V_8 )
{
int V_51 ;
struct V_1 * V_2 ;
struct V_20 * V_208 = NULL ;
V_2 = F_121 ( V_8 ) ;
if ( ! V_2 ) {
F_12 ( V_8 , L_74 , V_33 ) ;
return - V_176 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 ++ ;
F_3 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_208 ) {
if ( F_30 ( & V_6 . V_7 ) )
F_15 ( V_8 , L_78 ,
V_33 ) ;
V_51 = F_21 ( V_2 , false ) ;
} else
V_51 = F_21 ( V_2 , true ) ;
if ( V_51 )
F_12 ( V_8 , L_79 , V_33 ) ;
return V_51 ;
}
static int F_122 ( struct V_5 * V_8 )
{
int V_51 = 0 ;
struct V_1 * V_2 ;
struct V_20 * V_208 = NULL ;
V_2 = F_121 ( V_8 ) ;
if ( ! V_2 ) {
F_12 ( V_8 , L_74 , V_33 ) ;
return - V_176 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_208 )
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
F_4 ( & V_6 . V_7 ) ;
else
V_51 = F_25 ( V_2 , true ) ;
if ( V_51 )
F_12 ( V_8 , L_68 , V_33 ) ;
return V_51 ;
}
static int T_5 F_123 ( void )
{
F_124 ( & V_6 . V_81 , NULL , NULL ) ;
F_125 ( & V_6 . V_7 , 0 ) ;
return F_126 ( & V_209 ) ;
}
static void T_6 F_127 ( void )
{
F_128 ( & V_209 ) ;
return;
}
