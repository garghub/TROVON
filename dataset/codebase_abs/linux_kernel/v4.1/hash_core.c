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
F_21 ( V_52 ) ;
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
T_2 * V_53 , T_3 * V_54 , bool * V_55 )
{
int V_56 = 0 ;
struct V_30 * V_31 = V_2 -> V_4 ;
* V_55 = false ;
if ( V_57 == V_31 -> V_58 . V_59 ) {
if ( V_60 == V_31 -> V_58 . V_61 ) {
memcpy ( V_53 , & V_62 [ 0 ] ,
V_63 ) ;
* V_54 = V_63 ;
* V_55 = true ;
} else if ( V_64 ==
V_31 -> V_58 . V_61 ) {
memcpy ( V_53 , & V_65 [ 0 ] ,
V_66 ) ;
* V_54 = V_66 ;
* V_55 = true ;
} else {
F_13 ( V_2 -> V_8 , L_6 ,
V_42 ) ;
V_56 = - V_67 ;
goto V_68;
}
} else if ( V_69 == V_31 -> V_58 . V_59 ) {
if ( ! V_31 -> V_70 ) {
if ( V_60 == V_31 -> V_58 . V_61 ) {
memcpy ( V_53 , & V_71 [ 0 ] ,
V_63 ) ;
* V_54 = V_63 ;
* V_55 = true ;
} else if ( V_64 == V_31 -> V_58 . V_61 ) {
memcpy ( V_53 , & V_72 [ 0 ] ,
V_66 ) ;
* V_54 = V_66 ;
* V_55 = true ;
} else {
F_13 ( V_2 -> V_8 , L_6 ,
V_42 ) ;
V_56 = - V_67 ;
goto V_68;
}
} else {
F_16 ( V_2 -> V_8 ,
L_7 ,
V_42 ) ;
}
}
V_68:
return V_56 ;
}
static int F_25 ( struct V_1 * V_2 ,
bool V_73 )
{
int V_56 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_74 ) ;
if ( ! V_2 -> V_75 )
goto V_68;
if ( V_73 ) {
F_26 ( V_2 ,
& V_2 -> V_76 ) ;
V_2 -> V_77 = true ;
}
F_27 ( V_2 -> V_78 ) ;
V_56 = F_28 ( V_2 -> V_79 ) ;
if ( V_56 )
F_13 ( V_8 , L_8 , V_42 ) ;
V_2 -> V_75 = false ;
V_68:
F_3 ( & V_2 -> V_74 ) ;
return V_56 ;
}
static int F_29 ( struct V_1 * V_2 ,
bool V_80 )
{
int V_56 = 0 ;
struct V_5 * V_8 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_74 ) ;
if ( ! V_2 -> V_75 ) {
V_56 = F_30 ( V_2 -> V_79 ) ;
if ( V_56 ) {
F_13 ( V_8 , L_9 ,
V_42 ) ;
goto V_68;
}
V_56 = F_31 ( V_2 -> V_78 ) ;
if ( V_56 ) {
F_13 ( V_8 , L_10 , V_42 ) ;
V_56 = F_28 (
V_2 -> V_79 ) ;
goto V_68;
}
V_2 -> V_75 = true ;
}
if ( V_2 -> V_77 ) {
if ( V_80 ) {
V_2 -> V_77 = false ;
F_32 ( V_2 , & V_2 -> V_76 ) ;
}
}
V_68:
F_3 ( & V_2 -> V_74 ) ;
return V_56 ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_1 * * V_2 )
{
int V_56 ;
struct V_81 V_82 ;
struct V_83 * V_84 ;
struct V_1 * V_85 = NULL ;
V_56 = F_34 ( & V_6 . V_7 ) ;
if ( V_56 )
return V_56 ;
F_35 ( & V_6 . V_86 , & V_82 ) ;
V_84 = F_36 ( & V_82 ) ;
while ( V_84 ) {
V_85 = F_37 ( V_84 ,
struct V_1 , V_87 ) ;
F_2 ( & V_85 -> V_3 ) ;
if ( V_85 -> V_4 ) {
V_84 = F_36 ( & V_82 ) ;
} else {
V_85 -> V_4 = V_31 ;
V_31 -> V_5 = V_85 ;
F_3 ( & V_85 -> V_3 ) ;
break;
}
F_3 ( & V_85 -> V_3 ) ;
}
F_38 ( & V_82 ) ;
if ( ! V_84 ) {
return - V_88 ;
}
* V_2 = V_85 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
const T_2 * V_89 , unsigned int V_70 )
{
T_3 V_90 = 0 ;
int V_91 = 1 ;
F_40 ( & V_2 -> V_92 -> V_93 , V_94 ) ;
while ( V_70 >= 4 ) {
T_3 * V_95 = ( T_3 * ) V_89 ;
F_41 ( V_95 , V_91 ) ;
V_70 -= 4 ;
V_89 += 4 ;
}
if ( V_70 ) {
V_90 = 0 ;
while ( V_70 ) {
V_90 |= ( V_89 [ V_70 - 1 ] << ( 8 * ( V_70 - 1 ) ) ) ;
V_70 -- ;
}
F_41 ( & V_90 , V_91 ) ;
}
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
V_97 ;
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_56 = 0 ;
V_56 = F_45 ( V_2 , & V_31 -> V_58 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 , L_11 ,
V_42 ) ;
return V_56 ;
}
F_46 ( V_2 , V_31 ) ;
if ( V_31 -> V_58 . V_59 == V_69 )
F_39 ( V_2 , V_31 -> V_89 , V_31 -> V_70 ) ;
return V_56 ;
}
static int F_47 ( struct V_32 * V_33 , int V_98 , bool * V_99 )
{
int V_47 = 0 ;
bool V_100 = true ;
while ( V_98 > 0 && V_33 ) {
V_47 ++ ;
V_98 -= V_33 -> V_44 ;
if ( ( V_99 && ! F_48 ( V_33 -> V_101 , V_45 ) ) ||
( ! F_48 ( V_33 -> V_44 , V_45 ) && V_98 > 0 ) )
V_100 = false ;
V_33 = F_49 ( V_33 ) ;
}
if ( V_99 )
* V_99 = V_100 ;
if ( V_98 != 0 )
return - V_43 ;
return V_47 ;
}
static bool F_50 ( struct V_32 * V_33 , int V_102 )
{
bool V_99 ;
if ( F_47 ( V_33 , V_102 , & V_99 ) < 1 )
return false ;
return V_99 ;
}
static int F_51 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
if ( ! V_31 -> V_89 )
V_31 -> V_70 = 0 ;
memset ( & V_108 -> V_76 , 0 , sizeof( struct V_109 ) ) ;
V_108 -> V_110 = 0 ;
if ( V_111 == V_112 ) {
if ( V_104 -> V_113 < V_45 ) {
V_108 -> V_114 = false ;
F_55 ( L_12 ,
V_42 , V_45 ) ;
} else {
if ( V_104 -> V_113 >= V_115 &&
F_50 ( V_104 -> V_116 , V_104 -> V_113 ) ) {
V_108 -> V_114 = true ;
} else {
V_108 -> V_114 = false ;
F_55 ( L_13 ,
V_42 ,
V_115 ) ;
}
}
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 ,
const T_3 * V_117 , int V_44 )
{
int V_34 = V_44 / V_118 ;
F_40 ( & V_2 -> V_92 -> V_93 , V_94 ) ;
F_41 ( V_117 , V_34 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
const T_3 * V_117 , T_2 V_119 )
{
int V_91 = 1 ;
F_40 ( & V_2 -> V_92 -> V_93 , V_94 ) ;
while ( V_119 >= 4 ) {
F_41 ( V_117 , V_91 ) ;
V_119 -= 4 ;
V_117 ++ ;
}
if ( V_119 )
F_41 ( V_117 , V_91 ) ;
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
F_58 ( V_119 * 8 ) ;
F_16 ( V_2 -> V_8 , L_14 ,
V_42 , F_59 ( & V_2 -> V_92 -> V_120 ) ,
F_59 ( & V_2 -> V_92 -> V_93 ) & V_94 ) ;
V_97 ;
F_16 ( V_2 -> V_8 , L_15 ,
V_42 , F_59 ( & V_2 -> V_92 -> V_120 ) ,
F_59 ( & V_2 -> V_92 -> V_93 ) & V_94 ) ;
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
}
static void F_60 ( struct V_107 * V_31 , T_3 V_121 )
{
V_31 -> V_76 . V_44 . V_122 += V_121 ;
if ( V_31 -> V_76 . V_44 . V_122 < V_121 )
V_31 -> V_76 . V_44 . V_123 ++ ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_124 * V_58 )
{
int V_56 = 0 ;
if ( V_58 -> V_61 != V_60 &&
V_58 -> V_61 != V_64 )
return - V_125 ;
F_61 ( V_58 -> V_126 ) ;
switch ( V_58 -> V_61 ) {
case V_60 :
F_62 ( & V_2 -> V_92 -> V_127 , V_128 ) ;
break;
case V_64 :
F_40 ( & V_2 -> V_92 -> V_127 , V_128 ) ;
break;
default:
F_13 ( V_2 -> V_8 , L_16 ,
V_42 ) ;
return - V_125 ;
}
if ( V_57 == V_58 -> V_59 )
F_40 ( & V_2 -> V_92 -> V_127 ,
V_129 ) ;
else if ( V_69 == V_58 -> V_59 ) {
F_62 ( & V_2 -> V_92 -> V_127 , V_129 ) ;
if ( V_2 -> V_4 -> V_70 > V_130 ) {
F_16 ( V_2 -> V_8 , L_17 , V_42 ) ;
F_62 ( & V_2 -> V_92 -> V_127 ,
V_131 ) ;
} else {
F_16 ( V_2 -> V_8 , L_18 ,
V_42 ) ;
F_40 ( & V_2 -> V_92 -> V_127 ,
V_131 ) ;
}
} else {
V_56 = - V_125 ;
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
}
return V_56 ;
}
void F_46 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
V_132 ;
F_40 ( & V_2 -> V_92 -> V_93 , V_94 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_30 * V_31 , struct V_107 * V_108 ,
int V_133 , T_2 * V_134 , T_2 * V_135 ,
T_2 * V_136 )
{
int V_56 = 0 ;
T_3 V_137 ;
do {
if ( ( * V_136 + V_133 ) < V_130 ) {
for ( V_137 = 0 ; V_137 < V_133 ; V_137 ++ ) {
V_135 [ * V_136 + V_137 ] =
* ( V_134 + V_137 ) ;
}
* V_136 += V_133 ;
V_133 = 0 ;
} else {
if ( V_108 -> V_110 ) {
V_56 = F_32 ( V_2 ,
& V_2 -> V_76 ) ;
memmove ( V_108 -> V_76 . V_135 ,
V_2 -> V_76 . V_135 ,
V_130 / sizeof( T_3 ) ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 ,
L_20 ,
V_42 ) ;
goto V_68;
}
} else {
V_56 = F_44 ( V_2 , V_31 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 ,
L_21 ,
V_42 ) ;
goto V_68;
}
V_108 -> V_110 = 1 ;
}
if ( ( 0 == ( ( ( T_3 ) V_134 ) % 4 ) ) &&
( 0 == * V_136 ) )
F_56 ( V_2 ,
( const T_3 * ) V_134 ,
V_130 ) ;
else {
for ( V_137 = 0 ;
V_137 < ( T_3 ) ( V_130 - * V_136 ) ;
V_137 ++ ) {
V_135 [ * V_136 + V_137 ] =
* ( V_134 + V_137 ) ;
}
F_56 ( V_2 ,
( const T_3 * ) V_135 ,
V_130 ) ;
}
F_60 ( V_108 , V_130 ) ;
V_134 += ( V_130 - * V_136 ) ;
V_133 -= ( V_130 - * V_136 ) ;
* V_136 = 0 ;
V_56 = F_26 ( V_2 ,
& V_2 -> V_76 ) ;
memmove ( V_2 -> V_76 . V_135 ,
V_108 -> V_76 . V_135 ,
V_130 / sizeof( T_3 ) ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 , L_22 ,
V_42 ) ;
goto V_68;
}
}
} while ( V_133 != 0 );
V_68:
return V_56 ;
}
static int F_64 ( struct V_103 * V_104 )
{
int V_56 = 0 ;
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
struct V_1 * V_2 ;
T_2 V_138 [ V_66 ] ;
int V_139 = 0 ;
V_56 = F_33 ( V_31 , & V_2 ) ;
if ( V_56 )
return V_56 ;
F_16 ( V_2 -> V_8 , L_23 , V_42 , ( T_3 ) V_31 ) ;
if ( V_108 -> V_110 ) {
V_56 = F_32 ( V_2 , & V_2 -> V_76 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 , L_20 ,
V_42 ) ;
goto V_68;
}
}
if ( ! V_108 -> V_110 ) {
V_56 = F_45 ( V_2 , & V_31 -> V_58 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 ,
L_11 ,
V_42 ) ;
goto V_68;
}
if ( V_111 != V_112 || ! V_108 -> V_114 ) {
F_40 ( & V_2 -> V_92 -> V_127 ,
V_140 ) ;
} else {
F_62 ( & V_2 -> V_92 -> V_127 ,
V_140 ) ;
F_62 ( & V_2 -> V_92 -> V_127 ,
V_141 ) ;
}
V_132 ;
if ( V_31 -> V_58 . V_59 == V_69 )
F_39 ( V_2 , V_31 -> V_89 , V_31 -> V_70 ) ;
F_58 ( ( V_104 -> V_113 * 8 ) % 32 ) ;
V_108 -> V_110 = 1 ;
}
V_31 -> V_5 -> V_21 . V_47 = F_47 ( V_104 -> V_116 , V_104 -> V_113 , NULL ) ;
if ( ! V_31 -> V_5 -> V_21 . V_47 ) {
F_13 ( V_2 -> V_8 , L_24 ,
V_42 ) ;
V_56 = V_31 -> V_5 -> V_21 . V_47 ;
goto V_68;
}
V_139 = F_23 ( V_31 , V_104 -> V_116 , V_104 -> V_113 ) ;
if ( V_139 != V_104 -> V_113 ) {
F_13 ( V_2 -> V_8 , L_25 ,
V_42 ) ;
V_56 = V_139 ;
goto V_68;
}
F_65 ( & V_31 -> V_5 -> V_21 . V_28 ) ;
F_20 ( V_31 ) ;
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
if ( V_31 -> V_58 . V_59 == V_69 && V_31 -> V_89 ) {
unsigned int V_70 = V_31 -> V_70 ;
T_2 * V_89 = V_31 -> V_89 ;
F_16 ( V_2 -> V_8 , L_26 ,
V_42 , V_31 -> V_70 ) ;
F_39 ( V_2 , V_89 , V_70 ) ;
}
F_66 ( V_2 , V_138 , V_31 -> V_58 . V_61 ) ;
memcpy ( V_104 -> V_142 , V_138 , V_31 -> V_143 ) ;
V_68:
F_1 ( V_2 ) ;
F_67 ( V_31 -> V_89 ) ;
return V_56 ;
}
static int F_68 ( struct V_103 * V_104 )
{
int V_56 = 0 ;
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
struct V_1 * V_2 ;
T_2 V_138 [ V_66 ] ;
V_56 = F_33 ( V_31 , & V_2 ) ;
if ( V_56 )
return V_56 ;
F_16 ( V_2 -> V_8 , L_23 , V_42 , ( T_3 ) V_31 ) ;
if ( V_108 -> V_110 ) {
V_56 = F_32 ( V_2 , & V_2 -> V_76 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 ,
L_20 , V_42 ) ;
goto V_68;
}
} else if ( V_104 -> V_113 == 0 && V_31 -> V_70 == 0 ) {
T_2 V_53 [ V_66 ] ;
T_3 V_54 = 0 ;
bool V_55 = false ;
V_56 = F_24 ( V_2 , & V_53 [ 0 ] ,
& V_54 , & V_55 ) ;
if ( ! V_56 && F_69 ( V_54 == V_31 -> V_143 ) &&
V_55 ) {
memcpy ( V_104 -> V_142 , & V_53 [ 0 ] , V_31 -> V_143 ) ;
goto V_68;
} else if ( ! V_56 && ! V_55 ) {
F_16 ( V_2 -> V_8 ,
L_27 ,
V_42 ) ;
} else {
F_13 ( V_2 -> V_8 ,
L_28 ,
V_42 , V_56 ,
V_54 == V_31 -> V_143 ?
L_29 : L_30 ) ;
goto V_68;
}
} else if ( V_104 -> V_113 == 0 && V_31 -> V_70 > 0 ) {
F_13 ( V_2 -> V_8 , L_31 ,
V_42 ) ;
goto V_68;
}
if ( ! V_108 -> V_110 ) {
V_56 = F_44 ( V_2 , V_31 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 ,
L_21 , V_42 ) ;
goto V_68;
}
}
if ( V_108 -> V_76 . V_136 ) {
F_57 ( V_2 , V_108 -> V_76 . V_135 ,
V_108 -> V_76 . V_136 ) ;
} else {
V_97 ;
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
}
if ( V_31 -> V_58 . V_59 == V_69 && V_31 -> V_89 ) {
unsigned int V_70 = V_31 -> V_70 ;
T_2 * V_89 = V_31 -> V_89 ;
F_16 ( V_2 -> V_8 , L_26 ,
V_42 , V_31 -> V_70 ) ;
F_39 ( V_2 , V_89 , V_70 ) ;
}
F_66 ( V_2 , V_138 , V_31 -> V_58 . V_61 ) ;
memcpy ( V_104 -> V_142 , V_138 , V_31 -> V_143 ) ;
V_68:
F_1 ( V_2 ) ;
F_67 ( V_31 -> V_89 ) ;
return V_56 ;
}
int F_70 ( struct V_103 * V_104 )
{
int V_56 = 0 ;
T_2 V_136 = 0 ;
T_2 * V_135 ;
struct V_1 * V_2 ;
T_2 * V_134 ;
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
struct V_144 V_145 ;
int V_133 = F_71 ( V_104 , & V_145 ) ;
if ( V_133 == 0 )
return V_56 ;
V_136 = V_108 -> V_76 . V_136 ;
V_135 = ( T_2 * ) V_108 -> V_76 . V_135 ;
if ( V_133 > ( V_108 -> V_76 . V_44 . V_122 + V_133 ) &&
V_146 == V_108 -> V_76 . V_44 . V_123 ) {
F_72 ( L_32 , V_42 ) ;
return - V_125 ;
}
V_56 = F_33 ( V_31 , & V_2 ) ;
if ( V_56 )
return V_56 ;
while ( 0 != V_133 ) {
V_134 = V_145 . V_29 ;
V_56 = F_63 ( V_2 , V_31 , V_108 , V_133 ,
V_134 , V_135 , & V_136 ) ;
if ( V_56 ) {
F_13 ( V_2 -> V_8 , L_33 ,
V_42 ) ;
goto V_68;
}
V_133 = F_73 ( & V_145 , 0 ) ;
}
V_108 -> V_76 . V_136 = V_136 ;
F_16 ( V_2 -> V_8 , L_34 ,
V_42 , V_108 -> V_76 . V_136 , V_108 -> V_76 . V_147 ) ;
V_68:
F_1 ( V_2 ) ;
return V_56 ;
}
int F_32 ( struct V_1 * V_2 ,
const struct V_109 * V_148 )
{
T_3 V_149 ;
T_4 V_137 ;
int V_111 = V_57 ;
if ( NULL == V_148 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_125 ;
}
if ( V_148 -> V_136 > V_130 ||
( V_148 -> V_44 . V_122 % V_130 ) != 0 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_125 ;
}
V_132 ;
V_149 = V_148 -> V_149 ;
F_74 ( V_149 & V_150 , & V_2 -> V_92 -> V_127 ) ;
if ( F_42 ( & V_2 -> V_92 -> V_127 ) & V_129 )
V_111 = V_69 ;
else
V_111 = V_57 ;
for ( V_137 = 0 ; V_137 < V_151 ; V_137 ++ ) {
if ( ( V_137 >= 36 ) && ( V_111 == V_57 ) )
break;
F_74 ( V_148 -> V_152 [ V_137 ] ,
& V_2 -> V_92 -> V_153 [ V_137 ] ) ;
}
F_74 ( V_148 -> V_154 , & V_2 -> V_92 -> V_154 ) ;
F_74 ( V_148 -> V_155 , & V_2 -> V_92 -> V_155 ) ;
F_74 ( V_148 -> V_156 , & V_2 -> V_92 -> V_93 ) ;
F_74 ( V_149 , & V_2 -> V_92 -> V_127 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_109 * V_148 )
{
T_3 V_149 ;
T_3 V_137 ;
int V_111 = V_57 ;
if ( NULL == V_148 ) {
F_13 ( V_2 -> V_8 , L_19 ,
V_42 ) ;
return - V_157 ;
}
while ( F_42 ( & V_2 -> V_92 -> V_93 ) & V_96 )
F_43 () ;
V_149 = F_59 ( & V_2 -> V_92 -> V_127 ) ;
V_148 -> V_156 = F_59 ( & V_2 -> V_92 -> V_93 ) ;
V_148 -> V_158 = F_59 ( & V_2 -> V_92 -> V_120 ) ;
if ( F_42 ( & V_2 -> V_92 -> V_127 ) & V_129 )
V_111 = V_69 ;
else
V_111 = V_57 ;
for ( V_137 = 0 ; V_137 < V_151 ; V_137 ++ ) {
if ( ( V_137 >= 36 ) && ( V_111 == V_57 ) )
break;
V_148 -> V_152 [ V_137 ] =
F_59 ( & V_2 -> V_92 -> V_153 [ V_137 ] ) ;
}
V_148 -> V_154 = F_59 ( & V_2 -> V_92 -> V_154 ) ;
V_148 -> V_155 = F_59 ( & V_2 -> V_92 -> V_155 ) ;
V_148 -> V_149 = V_149 ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
if ( V_159 == F_59 ( & V_2 -> V_92 -> V_160 ) &&
V_161 == F_59 ( & V_2 -> V_92 -> V_162 ) &&
V_163 == F_59 ( & V_2 -> V_92 -> V_164 ) &&
V_165 == F_59 ( & V_2 -> V_92 -> V_166 ) &&
V_167 == F_59 ( & V_2 -> V_92 -> V_168 ) &&
V_169 == F_59 ( & V_2 -> V_92 -> V_170 ) &&
V_171 == F_59 ( & V_2 -> V_92 -> V_172 ) &&
V_173 == F_59 ( & V_2 -> V_92 -> V_174 ) ) {
return 0 ;
}
F_13 ( V_2 -> V_8 , L_35 , V_42 ) ;
return - V_157 ;
}
void F_66 ( struct V_1 * V_2 ,
T_2 * V_138 , int V_61 )
{
T_3 V_175 , V_137 ;
int V_176 ;
if ( V_61 != V_60 && V_61 != V_64 ) {
F_13 ( V_2 -> V_8 , L_36 ,
V_42 , V_61 ) ;
return;
}
if ( V_61 == V_60 )
V_176 = V_63 / sizeof( T_3 ) ;
else
V_176 = V_66 / sizeof( T_3 ) ;
F_16 ( V_2 -> V_8 , L_37 ,
V_42 , ( T_3 ) V_138 ) ;
for ( V_137 = 0 ; V_137 < V_176 ; V_137 ++ ) {
V_175 = F_59 ( & V_2 -> V_92 -> V_177 [ V_137 ] ) ;
V_138 [ V_137 * 4 ] = ( T_2 ) ( ( V_175 >> 24 ) & 0xFF ) ;
V_138 [ V_137 * 4 + 1 ] = ( T_2 ) ( ( V_175 >> 16 ) & 0xFF ) ;
V_138 [ V_137 * 4 + 2 ] = ( T_2 ) ( ( V_175 >> 8 ) & 0xFF ) ;
V_138 [ V_137 * 4 + 3 ] = ( T_2 ) ( ( V_175 >> 0 ) & 0xFF ) ;
}
}
static int F_76 ( struct V_103 * V_104 )
{
int V_56 = 0 ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
if ( V_111 != V_112 || ! V_108 -> V_114 )
V_56 = F_70 ( V_104 ) ;
if ( V_56 ) {
F_72 ( L_38 , V_42 ) ;
}
return V_56 ;
}
static int F_77 ( struct V_103 * V_104 )
{
int V_56 = 0 ;
struct V_107 * V_108 = F_54 ( V_104 ) ;
F_55 ( L_39 , V_42 , V_104 -> V_113 ) ;
if ( ( V_111 == V_112 ) && V_108 -> V_114 )
V_56 = F_64 ( V_104 ) ;
else
V_56 = F_68 ( V_104 ) ;
if ( V_56 ) {
F_72 ( L_40 , V_42 ) ;
}
return V_56 ;
}
static int F_78 ( struct V_105 * V_106 ,
const T_2 * V_89 , unsigned int V_70 , int V_178 )
{
int V_56 = 0 ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
V_31 -> V_89 = F_79 ( V_89 , V_70 , V_179 ) ;
if ( ! V_31 -> V_89 ) {
F_72 ( L_41 ,
V_42 , V_178 ) ;
return - V_180 ;
}
V_31 -> V_70 = V_70 ;
return V_56 ;
}
static int F_80 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
V_31 -> V_58 . V_126 = V_181 ;
V_31 -> V_58 . V_61 = V_60 ;
V_31 -> V_58 . V_59 = V_57 ;
V_31 -> V_143 = V_63 ;
return F_51 ( V_104 ) ;
}
static int F_81 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
V_31 -> V_58 . V_126 = V_181 ;
V_31 -> V_58 . V_61 = V_64 ;
V_31 -> V_58 . V_59 = V_57 ;
V_31 -> V_143 = V_66 ;
return F_51 ( V_104 ) ;
}
static int F_82 ( struct V_103 * V_104 )
{
int V_182 , V_183 ;
V_183 = F_80 ( V_104 ) ;
if ( V_183 )
goto V_68;
V_183 = F_76 ( V_104 ) ;
V_182 = F_77 ( V_104 ) ;
V_68:
return V_183 ? V_183 : V_182 ;
}
static int F_83 ( struct V_103 * V_104 )
{
int V_182 , V_183 ;
V_183 = F_81 ( V_104 ) ;
if ( V_183 )
goto V_68;
V_183 = F_76 ( V_104 ) ;
V_182 = F_77 ( V_104 ) ;
V_68:
return V_183 ? V_183 : V_182 ;
}
static int F_84 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
V_31 -> V_58 . V_126 = V_181 ;
V_31 -> V_58 . V_61 = V_60 ;
V_31 -> V_58 . V_59 = V_69 ;
V_31 -> V_143 = V_63 ;
return F_51 ( V_104 ) ;
}
static int F_85 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_52 ( V_104 ) ;
struct V_30 * V_31 = F_53 ( V_106 ) ;
V_31 -> V_58 . V_126 = V_181 ;
V_31 -> V_58 . V_61 = V_64 ;
V_31 -> V_58 . V_59 = V_69 ;
V_31 -> V_143 = V_66 ;
return F_51 ( V_104 ) ;
}
static int F_86 ( struct V_103 * V_104 )
{
int V_182 , V_183 ;
V_183 = F_84 ( V_104 ) ;
if ( V_183 )
goto V_68;
V_183 = F_76 ( V_104 ) ;
V_182 = F_77 ( V_104 ) ;
V_68:
return V_183 ? V_183 : V_182 ;
}
static int F_87 ( struct V_103 * V_104 )
{
int V_182 , V_183 ;
V_183 = F_85 ( V_104 ) ;
if ( V_183 )
goto V_68;
V_183 = F_76 ( V_104 ) ;
V_182 = F_77 ( V_104 ) ;
V_68:
return V_183 ? V_183 : V_182 ;
}
static int F_88 ( struct V_105 * V_106 ,
const T_2 * V_89 , unsigned int V_70 )
{
return F_78 ( V_106 , V_89 , V_70 , V_60 ) ;
}
static int F_89 ( struct V_105 * V_106 ,
const T_2 * V_89 , unsigned int V_70 )
{
return F_78 ( V_106 , V_89 , V_70 , V_64 ) ;
}
static int F_90 ( struct V_184 * V_106 )
{
struct V_30 * V_31 = F_91 ( V_106 ) ;
struct V_185 * V_178 = V_106 -> V_186 ;
struct V_187 * V_188 ;
V_188 = F_37 ( F_92 ( V_178 ) ,
struct V_187 ,
V_189 ) ;
F_93 ( F_94 ( V_106 ) ,
sizeof( struct V_107 ) ) ;
V_31 -> V_58 . V_126 = V_181 ;
V_31 -> V_58 . V_61 = V_188 -> V_12 . V_61 ;
V_31 -> V_58 . V_59 = V_188 -> V_12 . V_59 ;
V_31 -> V_143 = V_188 -> V_189 . V_190 . V_143 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_56 ;
int V_191 ;
int V_137 ;
for ( V_191 = 0 ; V_191 < F_96 ( V_192 ) ; V_191 ++ ) {
V_56 = F_97 ( & V_192 [ V_191 ] . V_189 ) ;
if ( V_56 ) {
V_137 = V_191 ;
F_13 ( V_2 -> V_8 , L_42 ,
V_192 [ V_191 ] . V_189 . V_190 . V_92 . V_193 ) ;
goto V_194;
}
}
return 0 ;
V_194:
for ( V_191 = 0 ; V_191 < V_137 ; V_191 ++ )
F_98 ( & V_192 [ V_191 ] . V_189 ) ;
return V_56 ;
}
static void F_99 ( struct V_1 * V_2 )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < F_96 ( V_192 ) ; V_191 ++ )
F_98 ( & V_192 [ V_191 ] . V_189 ) ;
}
static int F_100 ( struct V_195 * V_196 )
{
int V_56 = 0 ;
struct V_197 * V_198 = NULL ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_196 -> V_8 ;
V_2 = F_101 ( sizeof( * V_2 ) , V_199 ) ;
if ( ! V_2 ) {
V_56 = - V_180 ;
goto V_68;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = NULL ;
V_198 = F_102 ( V_196 , V_200 , 0 ) ;
if ( ! V_198 ) {
F_16 ( V_8 , L_43 , V_42 ) ;
V_56 = - V_201 ;
goto V_202;
}
V_198 = F_103 ( V_198 -> V_203 , F_104 ( V_198 ) , V_196 -> V_204 ) ;
if ( V_198 == NULL ) {
F_16 ( V_8 , L_44 , V_42 ) ;
V_56 = - V_88 ;
goto V_202;
}
V_2 -> V_16 = V_198 -> V_203 ;
V_2 -> V_92 = F_105 ( V_198 -> V_203 , F_104 ( V_198 ) ) ;
if ( ! V_2 -> V_92 ) {
F_13 ( V_8 , L_45 , V_42 ) ;
V_56 = - V_180 ;
goto V_205;
}
F_106 ( & V_2 -> V_3 ) ;
F_106 ( & V_2 -> V_74 ) ;
V_2 -> V_79 = F_107 ( V_8 , L_46 ) ;
if ( F_108 ( V_2 -> V_79 ) ) {
F_13 ( V_8 , L_47 , V_42 ) ;
V_56 = F_109 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
goto V_206;
}
V_2 -> V_78 = F_110 ( V_8 , NULL ) ;
if ( F_108 ( V_2 -> V_78 ) ) {
F_13 ( V_8 , L_48 , V_42 ) ;
V_56 = F_109 ( V_2 -> V_78 ) ;
goto V_207;
}
V_56 = F_111 ( V_2 -> V_78 ) ;
if ( V_56 ) {
F_13 ( V_8 , L_49 , V_42 ) ;
goto V_208;
}
V_56 = F_29 ( V_2 , false ) ;
if ( V_56 ) {
F_13 ( V_8 , L_50 , V_42 ) ;
goto V_209;
}
V_56 = F_75 ( V_2 ) ;
if ( V_56 ) {
F_13 ( V_8 , L_51 , V_42 ) ;
goto V_210;
}
if ( V_111 == V_112 )
F_5 ( V_2 , V_8 ) ;
F_112 ( V_196 , V_2 ) ;
F_113 ( & V_2 -> V_87 , & V_6 . V_86 ) ;
F_4 ( & V_6 . V_7 ) ;
V_56 = F_95 ( V_2 ) ;
if ( V_56 ) {
F_13 ( V_8 , L_52 ,
V_42 ) ;
goto V_210;
}
F_114 ( V_8 , L_53 ) ;
return 0 ;
V_210:
F_25 ( V_2 , false ) ;
V_209:
F_115 ( V_2 -> V_78 ) ;
V_208:
F_116 ( V_2 -> V_78 ) ;
V_207:
F_117 ( V_2 -> V_79 ) ;
V_206:
F_118 ( V_2 -> V_92 ) ;
V_205:
F_119 ( V_198 -> V_203 , F_104 ( V_198 ) ) ;
V_202:
F_67 ( V_2 ) ;
V_68:
return V_56 ;
}
static int F_120 ( struct V_195 * V_196 )
{
struct V_197 * V_198 ;
struct V_1 * V_2 ;
struct V_5 * V_8 = & V_196 -> V_8 ;
V_2 = F_121 ( V_196 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_180 ;
}
if ( F_122 ( & V_6 . V_7 ) )
return - V_88 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 ) {
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
return - V_88 ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_123 ( & V_2 -> V_87 ) )
F_124 ( & V_2 -> V_87 ) ;
if ( F_125 ( & V_6 . V_86 . V_211 ) )
F_99 ( V_2 ) ;
if ( F_25 ( V_2 , false ) )
F_13 ( V_8 , L_55 ,
V_42 ) ;
F_115 ( V_2 -> V_78 ) ;
F_116 ( V_2 -> V_78 ) ;
F_117 ( V_2 -> V_79 ) ;
F_118 ( V_2 -> V_92 ) ;
V_198 = F_102 ( V_196 , V_200 , 0 ) ;
if ( V_198 )
F_119 ( V_198 -> V_203 , F_104 ( V_198 ) ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static void F_126 ( struct V_195 * V_196 )
{
struct V_197 * V_198 = NULL ;
struct V_1 * V_2 ;
V_2 = F_121 ( V_196 ) ;
if ( ! V_2 ) {
F_13 ( & V_196 -> V_8 , L_54 ,
V_42 ) ;
return;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_122 ( & V_6 . V_7 ) )
F_16 ( & V_196 -> V_8 , L_56 ,
V_42 ) ;
V_2 -> V_4 ++ ;
}
F_3 ( & V_2 -> V_3 ) ;
if ( F_123 ( & V_2 -> V_87 ) )
F_124 ( & V_2 -> V_87 ) ;
if ( F_125 ( & V_6 . V_86 . V_211 ) )
F_99 ( V_2 ) ;
F_118 ( V_2 -> V_92 ) ;
V_198 = F_102 ( V_196 , V_200 , 0 ) ;
if ( V_198 )
F_119 ( V_198 -> V_203 , F_104 ( V_198 ) ) ;
if ( F_25 ( V_2 , false ) )
F_13 ( & V_196 -> V_8 , L_55 ,
V_42 ) ;
}
static int F_127 ( struct V_5 * V_8 )
{
int V_56 ;
struct V_1 * V_2 ;
struct V_30 * V_212 = NULL ;
V_2 = F_128 ( V_8 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_180 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 ++ ;
F_3 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_212 ) {
if ( F_34 ( & V_6 . V_7 ) )
F_16 ( V_8 , L_57 ,
V_42 ) ;
V_56 = F_25 ( V_2 , false ) ;
} else {
V_56 = F_25 ( V_2 , true ) ;
}
if ( V_56 )
F_13 ( V_8 , L_58 , V_42 ) ;
return V_56 ;
}
static int F_129 ( struct V_5 * V_8 )
{
int V_56 = 0 ;
struct V_1 * V_2 ;
struct V_30 * V_212 = NULL ;
V_2 = F_128 ( V_8 ) ;
if ( ! V_2 ) {
F_13 ( V_8 , L_54 , V_42 ) ;
return - V_180 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 == ++ V_212 )
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 )
F_4 ( & V_6 . V_7 ) ;
else
V_56 = F_29 ( V_2 , true ) ;
if ( V_56 )
F_13 ( V_8 , L_50 , V_42 ) ;
return V_56 ;
}
static int T_5 F_130 ( void )
{
F_131 ( & V_6 . V_86 , NULL , NULL ) ;
F_132 ( & V_6 . V_7 , 0 ) ;
return F_133 ( & V_213 ) ;
}
static void T_6 F_134 ( void )
{
F_135 ( & V_213 ) ;
}
