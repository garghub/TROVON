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
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = V_2 -> V_16 + V_17 ,
. V_18 = V_19 ,
. V_20 = 16 ,
} ;
F_6 ( V_2 -> V_21 . V_22 ) ;
F_7 ( V_23 , V_2 -> V_21 . V_22 ) ;
V_2 -> V_21 . V_24 = V_10 -> V_25 ;
V_2 -> V_21 . V_26 =
F_8 ( V_2 -> V_21 . V_22 ,
V_10 -> V_27 ,
V_2 -> V_21 . V_24 ) ;
F_9 ( V_2 -> V_21 . V_26 , & V_12 ) ;
F_10 ( & V_2 -> V_21 . V_28 ) ;
}
static void F_11 ( void * V_29 )
{
struct V_30 * V_31 = V_29 ;
V_28 ( & V_31 -> V_5 -> V_21 . V_28 ) ;
}
static int F_12 ( struct V_30 * V_31 , struct V_32 * V_33 ,
int V_34 , enum V_35 V_13 )
{
struct V_36 * V_37 = NULL ;
struct V_38 * V_39 = NULL ;
T_1 V_40 ;
if ( V_13 != V_41 ) {
F_13 ( V_31 -> V_5 -> V_8 , L_1 ,
V_42 ) ;
return - V_43 ;
}
V_33 -> V_44 = F_14 ( V_33 -> V_44 , V_45 ) ;
V_39 = V_31 -> V_5 -> V_21 . V_26 ;
V_31 -> V_5 -> V_21 . V_33 = V_33 ;
V_31 -> V_5 -> V_21 . V_46 = F_15 ( V_39 -> V_5 -> V_8 ,
V_31 -> V_5 -> V_21 . V_33 , V_31 -> V_5 -> V_21 . V_47 ,
V_13 ) ;
if ( ! V_31 -> V_5 -> V_21 . V_46 ) {
F_13 ( V_31 -> V_5 -> V_8 , L_2 ,
V_42 ) ;
return - V_43 ;
}
F_16 ( V_31 -> V_5 -> V_8 , L_3 ,
V_42 ) ;
V_37 = F_17 ( V_39 ,
V_31 -> V_5 -> V_21 . V_33 , V_31 -> V_5 -> V_21 . V_46 ,
V_13 , V_48 | V_49 ) ;
if ( ! V_37 ) {
F_13 ( V_31 -> V_5 -> V_8 ,
L_4 , V_42 ) ;
return - V_43 ;
}
V_37 -> V_50 = F_11 ;
V_37 -> V_51 = V_31 ;
V_40 = F_18 ( V_37 ) ;
F_19 ( V_39 ) ;
return 0 ;
}
static void F_20 ( struct V_30 * V_31 )
{
struct V_38 * V_52 ;
V_52 = V_31 -> V_5 -> V_21 . V_26 ;
F_21 ( V_52 , V_53 , 0 ) ;
F_22 ( V_52 -> V_5 -> V_8 , V_31 -> V_5 -> V_21 . V_33 ,
V_31 -> V_5 -> V_21 . V_46 , V_41 ) ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_32 * V_33 , int V_34 )
{
int error = F_12 ( V_31 , V_33 , V_34 , V_41 ) ;
if ( error ) {
F_16 ( V_31 -> V_5 -> V_8 ,
L_5 , V_42 ) ;
return error ;
}
return V_34 ;
}
static int F_24 (
struct V_1 * V_2 ,
T_2 * V_54 , T_3 * V_55 , bool * V_56 )
{
int V_57 = 0 ;
struct V_30 * V_31 = V_2 -> V_4 ;
* V_56 = false ;
if ( V_58 == V_31 -> V_59 . V_60 ) {
if ( V_61 == V_31 -> V_59 . V_62 ) {
memcpy ( V_54 , & V_63 [ 0 ] ,
V_64 ) ;
* V_55 = V_64 ;
* V_56 = true ;
} else if ( V_65 ==
V_31 -> V_59 . V_62 ) {
memcpy ( V_54 , & V_66 [ 0 ] ,
V_67 ) ;
* V_55 = V_67 ;
* V_56 = true ;
} else {
F_13 ( V_2 -> V_8 , L_6 ,
V_42 ) ;
V_57 = - V_68 ;
goto V_69;
}
} else if ( V_70 == V_31 -> V_59 . V_60 ) {
if ( ! V_31 -> V_71 ) {
if ( V_61 == V_31 -> V_59 . V_62 ) {
memcpy ( V_54 , & V_72 [ 0 ] ,
V_64 ) ;
* V_55 = V_64 ;
* V_56 = true ;
} else if ( V_65 == V_31 -> V_59 . V_62 ) {
memcpy ( V_54 , & V_73 [ 0 ] ,
V_67 ) ;
* V_55 = V_67 ;
* V_56 = true ;
} else {
F_13 ( V_2 -> V_8 , L_6 ,
V_42 ) ;
V_57 = - V_68 ;
goto V_69;
}
} else {
F_16 ( V_2 -> V_8 ,
L_7 ,
V_42 ) ;
}
}
V_69:
return V_57 ;
}
static int F_25 ( struct V_1 * V_2 ,
bool V_74 )
{
int V_57 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_75 ) ;
if ( ! V_2 -> V_76 )
goto V_69;
if ( V_74 ) {
F_26 ( V_2 ,
& V_2 -> V_77 ) ;
V_2 -> V_78 = true ;
}
F_27 ( V_2 -> V_79 ) ;
V_57 = F_28 ( V_2 -> V_80 ) ;
if ( V_57 )
F_13 ( V_8 , L_8 , V_42 ) ;
V_2 -> V_76 = false ;
V_69:
F_3 ( & V_2 -> V_75 ) ;
return V_57 ;
}
static int F_29 ( struct V_1 * V_2 ,
bool V_81 )
{
int V_57 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_75 ) ;
if ( ! V_2 -> V_76 ) {
V_57 = F_30 ( V_2 -> V_80 ) ;
if ( V_57 ) {
F_13 ( V_8 , L_9 ,
V_42 ) ;
goto V_69;
}
V_57 = F_31 ( V_2 -> V_79 ) ;
if ( V_57 ) {
F_13 ( V_8 , L_10 , V_42 ) ;
V_57 = F_28 (
V_2 -> V_80 ) ;
goto V_69;
}
V_2 -> V_76 = true ;
}
if ( V_2 -> V_78 ) {
if ( V_81 ) {
V_2 -> V_78 = false ;
F_32 ( V_2 , & V_2 -> V_77 ) ;
}
}
V_69:
F_3 ( & V_2 -> V_75 ) ;
return V_57 ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_1 * * V_2 )
{
int V_57 ;
struct V_82 V_83 ;
struct V_84 * V_85 ;
struct V_1 * V_86 = NULL ;
V_57 = F_34 ( & V_6 . V_7 ) ;
if ( V_57 )
return V_57 ;
F_35 ( & V_6 . V_87 , & V_83 ) ;
V_85 = F_36 ( & V_83 ) ;
while ( V_85 ) {
V_86 = F_37 ( V_85 ,
struct V_1 , V_88 ) ;
F_2 ( & V_86 -> V_3 ) ;
if ( V_86 -> V_4 ) {
V_85 = F_36 ( & V_83 ) ;
} else {
V_86 -> V_4 = V_31 ;
V_31 -> V_5 = V_86 ;
F_3 ( & V_86 -> V_3 ) ;
break;
}
F_3 ( & V_86 -> V_3 ) ;
}
F_38 ( & V_83 ) ;
if ( ! V_85 ) {
return - V_89 ;
}
* V_2 = V_86 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
const T_2 * V_90 , unsigned int V_71 )
{
T_3 V_91 = 0 ;
int V_92 = 1 ;
F_40 ( & V_2 -> V_93 -> V_94 , V_95 ) ;
while ( V_71 >= 4 ) {
T_3 * V_96 = ( T_3 * ) V_90 ;
F_41 ( V_96 , V_92 ) ;
V_71 -= 4 ;
V_90 += 4 ;
}
if ( V_71 ) {
V_91 = 0 ;
while ( V_71 ) {
V_91 |= ( V_90 [ V_71 - 1 ] << ( 8 * ( V_71 - 1 ) ) ) ;
V_71 -- ;
}
F_41 ( & V_91 , V_92 ) ;
}
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
V_98 ;
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_57 = 0 ;
V_57 = F_45 ( V_2 , & V_31 -> V_59 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 , L_11 ,
V_42 ) ;
return V_57 ;
}
F_46 ( V_2 , V_31 ) ;
if ( V_31 -> V_59 . V_60 == V_70 )
F_39 ( V_2 , V_31 -> V_90 , V_31 -> V_71 ) ;
return V_57 ;
}
static int F_47 ( struct V_32 * V_33 , int V_99 , bool * V_100 )
{
int V_47 = 0 ;
bool V_101 = true ;
while ( V_99 > 0 && V_33 ) {
V_47 ++ ;
V_99 -= V_33 -> V_44 ;
if ( ( V_100 && ! F_48 ( V_33 -> V_102 , V_45 ) ) ||
( ! F_48 ( V_33 -> V_44 , V_45 ) && V_99 > 0 ) )
V_101 = false ;
V_33 = F_49 ( V_33 ) ;
}
if ( V_100 )
* V_100 = V_101 ;
if ( V_99 != 0 )
return - V_43 ;
return V_47 ;
}
static bool F_50 ( struct V_32 * V_33 , int V_103 )
{
bool V_100 ;
if ( F_47 ( V_33 , V_103 , & V_100 ) < 1 )
return false ;
return V_100 ;
}
static int F_51 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
if ( ! V_31 -> V_90 )
V_31 -> V_71 = 0 ;
memset ( & V_109 -> V_77 , 0 , sizeof( struct V_110 ) ) ;
V_109 -> V_111 = 0 ;
if ( V_112 == V_113 ) {
if ( V_105 -> V_114 < V_45 ) {
V_109 -> V_115 = false ;
F_55 ( L_12 ,
V_42 , V_45 ) ;
} else {
if ( V_105 -> V_114 >= V_116 &&
F_50 ( V_105 -> V_117 , V_105 -> V_114 ) ) {
V_109 -> V_115 = true ;
} else {
V_109 -> V_115 = false ;
F_55 ( L_13 ,
V_42 ,
V_116 ) ;
}
}
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 ,
const T_3 * V_118 , int V_44 )
{
int V_34 = V_44 / V_119 ;
F_40 ( & V_2 -> V_93 -> V_94 , V_95 ) ;
F_41 ( V_118 , V_34 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
const T_3 * V_118 , T_2 V_120 )
{
int V_92 = 1 ;
F_40 ( & V_2 -> V_93 -> V_94 , V_95 ) ;
while ( V_120 >= 4 ) {
F_41 ( V_118 , V_92 ) ;
V_120 -= 4 ;
V_118 ++ ;
}
if ( V_120 )
F_41 ( V_118 , V_92 ) ;
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
F_58 ( V_120 * 8 ) ;
F_16 ( V_2 -> V_8 , L_14 ,
V_42 , F_59 ( & V_2 -> V_93 -> V_121 ) ,
F_59 ( & V_2 -> V_93 -> V_94 ) & V_95 ) ;
V_98 ;
F_16 ( V_2 -> V_8 , L_15 ,
V_42 , F_59 ( & V_2 -> V_93 -> V_121 ) ,
F_59 ( & V_2 -> V_93 -> V_94 ) & V_95 ) ;
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
}
static void F_60 ( struct V_108 * V_31 , T_3 V_122 )
{
V_31 -> V_77 . V_44 . V_123 += V_122 ;
if ( V_31 -> V_77 . V_44 . V_123 < V_122 )
V_31 -> V_77 . V_44 . V_124 ++ ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_125 * V_59 )
{
int V_57 = 0 ;
if ( V_59 -> V_62 != V_61 &&
V_59 -> V_62 != V_65 )
return - V_126 ;
F_61 ( V_59 -> V_127 ) ;
switch ( V_59 -> V_62 ) {
case V_61 :
F_62 ( & V_2 -> V_93 -> V_128 , V_129 ) ;
break;
case V_65 :
F_40 ( & V_2 -> V_93 -> V_128 , V_129 ) ;
break;
default:
F_13 ( V_2 -> V_8 , L_16 ,
V_42 ) ;
return - V_126 ;
}
if ( V_58 == V_59 -> V_60 )
F_40 ( & V_2 -> V_93 -> V_128 ,
V_130 ) ;
else if ( V_70 == V_59 -> V_60 ) {
F_62 ( & V_2 -> V_93 -> V_128 , V_130 ) ;
if ( V_2 -> V_4 -> V_71 > V_131 ) {
F_16 ( V_2 -> V_8 , L_17 , V_42 ) ;
F_62 ( & V_2 -> V_93 -> V_128 ,
V_132 ) ;
} else {
F_16 ( V_2 -> V_8 , L_18 ,
V_42 ) ;
F_40 ( & V_2 -> V_93 -> V_128 ,
V_132 ) ;
}
} else {
V_57 = - V_126 ;
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
}
return V_57 ;
}
void F_46 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
V_133 ;
F_40 ( & V_2 -> V_93 -> V_94 , V_95 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_30 * V_31 , struct V_108 * V_109 ,
int V_134 , T_2 * V_135 , T_2 * V_136 ,
T_2 * V_137 )
{
int V_57 = 0 ;
T_3 V_138 ;
do {
if ( ( * V_137 + V_134 ) < V_131 ) {
for ( V_138 = 0 ; V_138 < V_134 ; V_138 ++ ) {
V_136 [ * V_137 + V_138 ] =
* ( V_135 + V_138 ) ;
}
* V_137 += V_134 ;
V_134 = 0 ;
} else {
if ( V_109 -> V_111 ) {
V_57 = F_32 ( V_2 ,
& V_2 -> V_77 ) ;
memmove ( V_109 -> V_77 . V_136 ,
V_2 -> V_77 . V_136 ,
V_131 / sizeof( T_3 ) ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 ,
L_20 ,
V_42 ) ;
goto V_69;
}
} else {
V_57 = F_44 ( V_2 , V_31 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 ,
L_21 ,
V_42 ) ;
goto V_69;
}
V_109 -> V_111 = 1 ;
}
if ( ( 0 == ( ( ( T_3 ) V_135 ) % 4 ) ) &&
( 0 == * V_137 ) )
F_56 ( V_2 ,
( const T_3 * ) V_135 ,
V_131 ) ;
else {
for ( V_138 = 0 ;
V_138 < ( T_3 ) ( V_131 - * V_137 ) ;
V_138 ++ ) {
V_136 [ * V_137 + V_138 ] =
* ( V_135 + V_138 ) ;
}
F_56 ( V_2 ,
( const T_3 * ) V_136 ,
V_131 ) ;
}
F_60 ( V_109 , V_131 ) ;
V_135 += ( V_131 - * V_137 ) ;
V_134 -= ( V_131 - * V_137 ) ;
* V_137 = 0 ;
V_57 = F_26 ( V_2 ,
& V_2 -> V_77 ) ;
memmove ( V_2 -> V_77 . V_136 ,
V_109 -> V_77 . V_136 ,
V_131 / sizeof( T_3 ) ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 , L_22 ,
V_42 ) ;
goto V_69;
}
}
} while ( V_134 != 0 );
V_69:
return V_57 ;
}
static int F_64 ( struct V_104 * V_105 )
{
int V_57 = 0 ;
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
struct V_1 * V_2 ;
T_2 V_139 [ V_67 ] ;
int V_140 = 0 ;
V_57 = F_33 ( V_31 , & V_2 ) ;
if ( V_57 )
return V_57 ;
F_16 ( V_2 -> V_8 , L_23 , V_42 , ( T_3 ) V_31 ) ;
if ( V_109 -> V_111 ) {
V_57 = F_32 ( V_2 , & V_2 -> V_77 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 , L_20 ,
V_42 ) ;
goto V_69;
}
}
if ( ! V_109 -> V_111 ) {
V_57 = F_45 ( V_2 , & V_31 -> V_59 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 ,
L_11 ,
V_42 ) ;
goto V_69;
}
if ( V_112 != V_113 || ! V_109 -> V_115 ) {
F_40 ( & V_2 -> V_93 -> V_128 ,
V_141 ) ;
} else {
F_62 ( & V_2 -> V_93 -> V_128 ,
V_141 ) ;
F_62 ( & V_2 -> V_93 -> V_128 ,
V_142 ) ;
}
V_133 ;
if ( V_31 -> V_59 . V_60 == V_70 )
F_39 ( V_2 , V_31 -> V_90 , V_31 -> V_71 ) ;
F_58 ( ( V_105 -> V_114 * 8 ) % 32 ) ;
V_109 -> V_111 = 1 ;
}
V_31 -> V_5 -> V_21 . V_47 = F_47 ( V_105 -> V_117 , V_105 -> V_114 , NULL ) ;
if ( ! V_31 -> V_5 -> V_21 . V_47 ) {
F_13 ( V_2 -> V_8 , L_24 ,
V_42 ) ;
V_57 = V_31 -> V_5 -> V_21 . V_47 ;
goto V_69;
}
V_140 = F_23 ( V_31 , V_105 -> V_117 , V_105 -> V_114 ) ;
if ( V_140 != V_105 -> V_114 ) {
F_13 ( V_2 -> V_8 , L_25 ,
V_42 ) ;
V_57 = V_140 ;
goto V_69;
}
F_65 ( & V_31 -> V_5 -> V_21 . V_28 ) ;
F_20 ( V_31 ) ;
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
if ( V_31 -> V_59 . V_60 == V_70 && V_31 -> V_90 ) {
unsigned int V_71 = V_31 -> V_71 ;
T_2 * V_90 = V_31 -> V_90 ;
F_16 ( V_2 -> V_8 , L_26 ,
V_42 , V_31 -> V_71 ) ;
F_39 ( V_2 , V_90 , V_71 ) ;
}
F_66 ( V_2 , V_139 , V_31 -> V_59 . V_62 ) ;
memcpy ( V_105 -> V_143 , V_139 , V_31 -> V_144 ) ;
V_69:
F_1 ( V_2 ) ;
F_67 ( V_31 -> V_90 ) ;
return V_57 ;
}
static int F_68 ( struct V_104 * V_105 )
{
int V_57 = 0 ;
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
struct V_1 * V_2 ;
T_2 V_139 [ V_67 ] ;
V_57 = F_33 ( V_31 , & V_2 ) ;
if ( V_57 )
return V_57 ;
F_16 ( V_2 -> V_8 , L_23 , V_42 , ( T_3 ) V_31 ) ;
if ( V_109 -> V_111 ) {
V_57 = F_32 ( V_2 , & V_2 -> V_77 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 ,
L_20 , V_42 ) ;
goto V_69;
}
} else if ( V_105 -> V_114 == 0 && V_31 -> V_71 == 0 ) {
T_2 V_54 [ V_67 ] ;
T_3 V_55 = 0 ;
bool V_56 = false ;
V_57 = F_24 ( V_2 , & V_54 [ 0 ] ,
& V_55 , & V_56 ) ;
if ( ! V_57 && F_69 ( V_55 == V_31 -> V_144 ) &&
V_56 ) {
memcpy ( V_105 -> V_143 , & V_54 [ 0 ] , V_31 -> V_144 ) ;
goto V_69;
} else if ( ! V_57 && ! V_56 ) {
F_16 ( V_2 -> V_8 ,
L_27 ,
V_42 ) ;
} else {
F_13 ( V_2 -> V_8 ,
L_28 ,
V_42 , V_57 ,
V_55 == V_31 -> V_144 ?
L_29 : L_30 ) ;
goto V_69;
}
} else if ( V_105 -> V_114 == 0 && V_31 -> V_71 > 0 ) {
F_13 ( V_2 -> V_8 , L_31 ,
V_42 ) ;
goto V_69;
}
if ( ! V_109 -> V_111 ) {
V_57 = F_44 ( V_2 , V_31 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 ,
L_21 , V_42 ) ;
goto V_69;
}
}
if ( V_109 -> V_77 . V_137 ) {
F_57 ( V_2 , V_109 -> V_77 . V_136 ,
V_109 -> V_77 . V_137 ) ;
} else {
V_98 ;
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
}
if ( V_31 -> V_59 . V_60 == V_70 && V_31 -> V_90 ) {
unsigned int V_71 = V_31 -> V_71 ;
T_2 * V_90 = V_31 -> V_90 ;
F_16 ( V_2 -> V_8 , L_26 ,
V_42 , V_31 -> V_71 ) ;
F_39 ( V_2 , V_90 , V_71 ) ;
}
F_66 ( V_2 , V_139 , V_31 -> V_59 . V_62 ) ;
memcpy ( V_105 -> V_143 , V_139 , V_31 -> V_144 ) ;
V_69:
F_1 ( V_2 ) ;
F_67 ( V_31 -> V_90 ) ;
return V_57 ;
}
int F_70 ( struct V_104 * V_105 )
{
int V_57 = 0 ;
T_2 V_137 = 0 ;
T_2 * V_136 ;
struct V_1 * V_2 ;
T_2 * V_135 ;
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
struct V_145 V_146 ;
int V_134 = F_71 ( V_105 , & V_146 ) ;
if ( V_134 == 0 )
return V_57 ;
V_137 = V_109 -> V_77 . V_137 ;
V_136 = ( T_2 * ) V_109 -> V_77 . V_136 ;
if ( V_134 > ( V_109 -> V_77 . V_44 . V_123 + V_134 ) &&
V_147 == V_109 -> V_77 . V_44 . V_124 ) {
F_72 ( L_32 , V_42 ) ;
return - V_126 ;
}
V_57 = F_33 ( V_31 , & V_2 ) ;
if ( V_57 )
return V_57 ;
while ( 0 != V_134 ) {
V_135 = V_146 . V_29 ;
V_57 = F_63 ( V_2 , V_31 , V_109 , V_134 ,
V_135 , V_136 , & V_137 ) ;
if ( V_57 ) {
F_13 ( V_2 -> V_8 , L_33 ,
V_42 ) ;
goto V_69;
}
V_134 = F_73 ( & V_146 , 0 ) ;
}
V_109 -> V_77 . V_137 = V_137 ;
F_16 ( V_2 -> V_8 , L_34 ,
V_42 , V_109 -> V_77 . V_137 , V_109 -> V_77 . V_148 ) ;
V_69:
F_1 ( V_2 ) ;
return V_57 ;
}
int F_32 ( struct V_1 * V_2 ,
const struct V_110 * V_149 )
{
T_3 V_150 ;
T_4 V_138 ;
int V_112 = V_58 ;
if ( NULL == V_149 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_126 ;
}
if ( V_149 -> V_137 > V_131 ||
( V_149 -> V_44 . V_123 % V_131 ) != 0 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_126 ;
}
V_133 ;
V_150 = V_149 -> V_150 ;
F_74 ( V_150 & V_151 , & V_2 -> V_93 -> V_128 ) ;
if ( F_42 ( & V_2 -> V_93 -> V_128 ) & V_130 )
V_112 = V_70 ;
else
V_112 = V_58 ;
for ( V_138 = 0 ; V_138 < V_152 ; V_138 ++ ) {
if ( ( V_138 >= 36 ) && ( V_112 == V_58 ) )
break;
F_74 ( V_149 -> V_153 [ V_138 ] ,
& V_2 -> V_93 -> V_154 [ V_138 ] ) ;
}
F_74 ( V_149 -> V_155 , & V_2 -> V_93 -> V_155 ) ;
F_74 ( V_149 -> V_156 , & V_2 -> V_93 -> V_156 ) ;
F_74 ( V_149 -> V_157 , & V_2 -> V_93 -> V_94 ) ;
F_74 ( V_150 , & V_2 -> V_93 -> V_128 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_110 * V_149 )
{
T_3 V_150 ;
T_3 V_138 ;
int V_112 = V_58 ;
if ( NULL == V_149 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_158 ;
}
while ( F_42 ( & V_2 -> V_93 -> V_94 ) & V_97 )
F_43 () ;
V_150 = F_59 ( & V_2 -> V_93 -> V_128 ) ;
V_149 -> V_157 = F_59 ( & V_2 -> V_93 -> V_94 ) ;
V_149 -> V_159 = F_59 ( & V_2 -> V_93 -> V_121 ) ;
if ( F_42 ( & V_2 -> V_93 -> V_128 ) & V_130 )
V_112 = V_70 ;
else
V_112 = V_58 ;
for ( V_138 = 0 ; V_138 < V_152 ; V_138 ++ ) {
if ( ( V_138 >= 36 ) && ( V_112 == V_58 ) )
break;
V_149 -> V_153 [ V_138 ] =
F_59 ( & V_2 -> V_93 -> V_154 [ V_138 ] ) ;
}
V_149 -> V_155 = F_59 ( & V_2 -> V_93 -> V_155 ) ;
V_149 -> V_156 = F_59 ( & V_2 -> V_93 -> V_156 ) ;
V_149 -> V_150 = V_150 ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
if ( V_160 == F_59 ( & V_2 -> V_93 -> V_161 ) &&
V_162 == F_59 ( & V_2 -> V_93 -> V_163 ) &&
V_164 == F_59 ( & V_2 -> V_93 -> V_165 ) &&
V_166 == F_59 ( & V_2 -> V_93 -> V_167 ) &&
V_168 == F_59 ( & V_2 -> V_93 -> V_169 ) &&
V_170 == F_59 ( & V_2 -> V_93 -> V_171 ) &&
V_172 == F_59 ( & V_2 -> V_93 -> V_173 ) &&
V_174 == F_59 ( & V_2 -> V_93 -> V_175 ) ) {
return 0 ;
}
F_13 ( V_2 -> V_8 , L_35 , V_42 ) ;
return - V_158 ;
}
void F_66 ( struct V_1 * V_2 ,
T_2 * V_139 , int V_62 )
{
T_3 V_176 , V_138 ;
int V_177 ;
if ( V_62 != V_61 && V_62 != V_65 ) {
F_13 ( V_2 -> V_8 , L_36 ,
V_42 , V_62 ) ;
return;
}
if ( V_62 == V_61 )
V_177 = V_64 / sizeof( T_3 ) ;
else
V_177 = V_67 / sizeof( T_3 ) ;
F_16 ( V_2 -> V_8 , L_37 ,
V_42 , ( T_3 ) V_139 ) ;
for ( V_138 = 0 ; V_138 < V_177 ; V_138 ++ ) {
V_176 = F_59 ( & V_2 -> V_93 -> V_178 [ V_138 ] ) ;
V_139 [ V_138 * 4 ] = ( T_2 ) ( ( V_176 >> 24 ) & 0xFF ) ;
V_139 [ V_138 * 4 + 1 ] = ( T_2 ) ( ( V_176 >> 16 ) & 0xFF ) ;
V_139 [ V_138 * 4 + 2 ] = ( T_2 ) ( ( V_176 >> 8 ) & 0xFF ) ;
V_139 [ V_138 * 4 + 3 ] = ( T_2 ) ( ( V_176 >> 0 ) & 0xFF ) ;
}
}
static int F_76 ( struct V_104 * V_105 )
{
int V_57 = 0 ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
if ( V_112 != V_113 || ! V_109 -> V_115 )
V_57 = F_70 ( V_105 ) ;
if ( V_57 ) {
F_72 ( L_38 , V_42 ) ;
}
return V_57 ;
}
static int F_77 ( struct V_104 * V_105 )
{
int V_57 = 0 ;
struct V_108 * V_109 = F_54 ( V_105 ) ;
F_55 ( L_39 , V_42 , V_105 -> V_114 ) ;
if ( ( V_112 == V_113 ) && V_109 -> V_115 )
V_57 = F_64 ( V_105 ) ;
else
V_57 = F_68 ( V_105 ) ;
if ( V_57 ) {
F_72 ( L_40 , V_42 ) ;
}
return V_57 ;
}
static int F_78 ( struct V_106 * V_107 ,
const T_2 * V_90 , unsigned int V_71 , int V_179 )
{
int V_57 = 0 ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
V_31 -> V_90 = F_79 ( V_90 , V_71 , V_180 ) ;
if ( ! V_31 -> V_90 ) {
F_72 ( L_41 ,
V_42 , V_179 ) ;
return - V_181 ;
}
V_31 -> V_71 = V_71 ;
return V_57 ;
}
static int F_80 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
V_31 -> V_59 . V_127 = V_182 ;
V_31 -> V_59 . V_62 = V_61 ;
V_31 -> V_59 . V_60 = V_58 ;
V_31 -> V_144 = V_64 ;
return F_51 ( V_105 ) ;
}
static int F_81 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
V_31 -> V_59 . V_127 = V_182 ;
V_31 -> V_59 . V_62 = V_65 ;
V_31 -> V_59 . V_60 = V_58 ;
V_31 -> V_144 = V_67 ;
return F_51 ( V_105 ) ;
}
static int F_82 ( struct V_104 * V_105 )
{
int V_183 , V_184 ;
V_184 = F_80 ( V_105 ) ;
if ( V_184 )
goto V_69;
V_184 = F_76 ( V_105 ) ;
V_183 = F_77 ( V_105 ) ;
V_69:
return V_184 ? V_184 : V_183 ;
}
static int F_83 ( struct V_104 * V_105 )
{
int V_183 , V_184 ;
V_184 = F_81 ( V_105 ) ;
if ( V_184 )
goto V_69;
V_184 = F_76 ( V_105 ) ;
V_183 = F_77 ( V_105 ) ;
V_69:
return V_184 ? V_184 : V_183 ;
}
static int F_84 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
V_31 -> V_59 . V_127 = V_182 ;
V_31 -> V_59 . V_62 = V_61 ;
V_31 -> V_59 . V_60 = V_70 ;
V_31 -> V_144 = V_64 ;
return F_51 ( V_105 ) ;
}
static int F_85 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = F_52 ( V_105 ) ;
struct V_30 * V_31 = F_53 ( V_107 ) ;
V_31 -> V_59 . V_127 = V_182 ;
V_31 -> V_59 . V_62 = V_65 ;
V_31 -> V_59 . V_60 = V_70 ;
V_31 -> V_144 = V_67 ;
return F_51 ( V_105 ) ;
}
static int F_86 ( struct V_104 * V_105 )
{
int V_183 , V_184 ;
V_184 = F_84 ( V_105 ) ;
if ( V_184 )
goto V_69;
V_184 = F_76 ( V_105 ) ;
V_183 = F_77 ( V_105 ) ;
V_69:
return V_184 ? V_184 : V_183 ;
}
static int F_87 ( struct V_104 * V_105 )
{
int V_183 , V_184 ;
V_184 = F_85 ( V_105 ) ;
if ( V_184 )
goto V_69;
V_184 = F_76 ( V_105 ) ;
V_183 = F_77 ( V_105 ) ;
V_69:
return V_184 ? V_184 : V_183 ;
}
static int F_88 ( struct V_106 * V_107 ,
const T_2 * V_90 , unsigned int V_71 )
{
return F_78 ( V_107 , V_90 , V_71 , V_61 ) ;
}
static int F_89 ( struct V_106 * V_107 ,
const T_2 * V_90 , unsigned int V_71 )
{
return F_78 ( V_107 , V_90 , V_71 , V_65 ) ;
}
static int F_90 ( struct V_185 * V_107 )
{
struct V_30 * V_31 = F_91 ( V_107 ) ;
struct V_186 * V_179 = V_107 -> V_187 ;
struct V_188 * V_189 ;
V_189 = F_37 ( F_92 ( V_179 ) ,
struct V_188 ,
V_190 ) ;
F_93 ( F_94 ( V_107 ) ,
sizeof( struct V_108 ) ) ;
V_31 -> V_59 . V_127 = V_182 ;
V_31 -> V_59 . V_62 = V_189 -> V_12 . V_62 ;
V_31 -> V_59 . V_60 = V_189 -> V_12 . V_60 ;
V_31 -> V_144 = V_189 -> V_190 . V_191 . V_144 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_57 ;
int V_192 ;
int V_138 ;
for ( V_192 = 0 ; V_192 < F_96 ( V_193 ) ; V_192 ++ ) {
V_57 = F_97 ( & V_193 [ V_192 ] . V_190 ) ;
if ( V_57 ) {
V_138 = V_192 ;
F_13 ( V_2 -> V_8 , L_42 ,
V_193 [ V_192 ] . V_190 . V_191 . V_93 . V_194 ) ;
goto V_195;
}
}
return 0 ;
V_195:
for ( V_192 = 0 ; V_192 < V_138 ; V_192 ++ )
F_98 ( & V_193 [ V_192 ] . V_190 ) ;
return V_57 ;
}
static void F_99 ( struct V_1 * V_2 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < F_96 ( V_193 ) ; V_192 ++ )
F_98 ( & V_193 [ V_192 ] . V_190 ) ;
}
static int F_100 ( struct V_196 * V_197 )
{
int V_57 = 0 ;
struct V_198 * V_199 = NULL ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_197 -> V_8 ;
V_2 = F_101 ( sizeof( * V_2 ) , V_200 ) ;
if ( ! V_2 ) {
V_57 = - V_181 ;
goto V_69;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = NULL ;
V_199 = F_102 ( V_197 , V_201 , 0 ) ;
if ( ! V_199 ) {
F_16 ( V_8 , L_43 , V_42 ) ;
V_57 = - V_202 ;
goto V_203;
}
V_199 = F_103 ( V_199 -> V_204 , F_104 ( V_199 ) , V_197 -> V_205 ) ;
if ( V_199 == NULL ) {
F_16 ( V_8 , L_44 , V_42 ) ;
V_57 = - V_89 ;
goto V_203;
}
V_2 -> V_16 = V_199 -> V_204 ;
V_2 -> V_93 = F_105 ( V_199 -> V_204 , F_104 ( V_199 ) ) ;
if ( ! V_2 -> V_93 ) {
F_13 ( V_8 , L_45 , V_42 ) ;
V_57 = - V_181 ;
goto V_206;
}
F_106 ( & V_2 -> V_3 ) ;
F_106 ( & V_2 -> V_75 ) ;
V_2 -> V_80 = F_107 ( V_8 , L_46 ) ;
if ( F_108 ( V_2 -> V_80 ) ) {
F_13 ( V_8 , L_47 , V_42 ) ;
V_57 = F_109 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
goto V_207;
}
V_2 -> V_79 = F_110 ( V_8 , NULL ) ;
if ( F_108 ( V_2 -> V_79 ) ) {
F_13 ( V_8 , L_48 , V_42 ) ;
V_57 = F_109 ( V_2 -> V_79 ) ;
goto V_208;
}
V_57 = F_111 ( V_2 -> V_79 ) ;
if ( V_57 ) {
F_13 ( V_8 , L_49 , V_42 ) ;
goto V_209;
}
V_57 = F_29 ( V_2 , false ) ;
if ( V_57 ) {
F_13 ( V_8 , L_50 , V_42 ) ;
goto V_210;
}
V_57 = F_75 ( V_2 ) ;
if ( V_57 ) {
F_13 ( V_8 , L_51 , V_42 ) ;
goto V_211;
}
if ( V_112 == V_113 )
F_5 ( V_2 , V_8 ) ;
F_112 ( V_197 , V_2 ) ;
F_113 ( & V_2 -> V_88 , & V_6 . V_87 ) ;
F_4 ( & V_6 . V_7 ) ;
V_57 = F_95 ( V_2 ) ;
if ( V_57 ) {
F_13 ( V_8 , L_52 ,
V_42 ) ;
goto V_211;
}
F_114 ( V_8 , L_53 ) ;
return 0 ;
V_211:
F_25 ( V_2 , false ) ;
V_210:
F_115 ( V_2 -> V_79 ) ;
V_209:
F_116 ( V_2 -> V_79 ) ;
V_208:
F_117 ( V_2 -> V_80 ) ;
V_207:
F_118 ( V_2 -> V_93 ) ;
V_206:
F_119 ( V_199 -> V_204 , F_104 ( V_199 ) ) ;
V_203:
F_67 ( V_2 ) ;
V_69:
return V_57 ;
}
static int F_120 ( struct V_196 * V_197 )
{
struct V_198 * V_199 ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_197 -> V_8 ;
V_2 = F_121 ( V_197 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_181 ;
}
if ( F_122 ( & V_6 . V_7 ) )
return - V_89 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 ) {
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
return - V_89 ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_123 ( & V_2 -> V_88 ) )
F_124 ( & V_2 -> V_88 ) ;
if ( F_125 ( & V_6 . V_87 . V_212 ) )
F_99 ( V_2 ) ;
if ( F_25 ( V_2 , false ) )
F_13 ( V_8 , L_55 ,
V_42 ) ;
F_115 ( V_2 -> V_79 ) ;
F_116 ( V_2 -> V_79 ) ;
F_117 ( V_2 -> V_80 ) ;
F_118 ( V_2 -> V_93 ) ;
V_199 = F_102 ( V_197 , V_201 , 0 ) ;
if ( V_199 )
F_119 ( V_199 -> V_204 , F_104 ( V_199 ) ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static void F_126 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = NULL ;
struct V_1 * V_2 ;
V_2 = F_121 ( V_197 ) ;
if ( ! V_2 ) {
F_13 ( & V_197 -> V_8 , L_54 ,
V_42 ) ;
return;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_122 ( & V_6 . V_7 ) )
F_16 ( & V_197 -> V_8 , L_56 ,
V_42 ) ;
V_2 -> V_4 ++ ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_123 ( & V_2 -> V_88 ) )
F_124 ( & V_2 -> V_88 ) ;
if ( F_125 ( & V_6 . V_87 . V_212 ) )
F_99 ( V_2 ) ;
F_118 ( V_2 -> V_93 ) ;
V_199 = F_102 ( V_197 , V_201 , 0 ) ;
if ( V_199 )
F_119 ( V_199 -> V_204 , F_104 ( V_199 ) ) ;
if ( F_25 ( V_2 , false ) )
F_13 ( & V_197 -> V_8 , L_55 ,
V_42 ) ;
}
static int F_127 ( struct V_5 * V_8 )
{
int V_57 ;
struct V_1 * V_2 ;
struct V_30 * V_213 = NULL ;
V_2 = F_128 ( V_8 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_181 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 ++ ;
F_3 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_213 ) {
if ( F_34 ( & V_6 . V_7 ) )
F_16 ( V_8 , L_57 ,
V_42 ) ;
V_57 = F_25 ( V_2 , false ) ;
} else {
V_57 = F_25 ( V_2 , true ) ;
}
if ( V_57 )
F_13 ( V_8 , L_58 , V_42 ) ;
return V_57 ;
}
static int F_129 ( struct V_5 * V_8 )
{
int V_57 = 0 ;
struct V_1 * V_2 ;
struct V_30 * V_213 = NULL ;
V_2 = F_128 ( V_8 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_181 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_213 )
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
F_4 ( & V_6 . V_7 ) ;
else
V_57 = F_29 ( V_2 , true ) ;
if ( V_57 )
F_13 ( V_8 , L_50 , V_42 ) ;
return V_57 ;
}
static int T_5 F_130 ( void )
{
F_131 ( & V_6 . V_87 , NULL , NULL ) ;
F_132 ( & V_6 . V_7 , 0 ) ;
return F_133 ( & V_214 ) ;
}
static void T_6 F_134 ( void )
{
F_135 ( & V_214 ) ;
}
