static const char * F_1 ( enum V_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 [ V_3 ] . V_5 ;
return L_1 ;
}
static const char * F_1 ( enum V_1 V_2 )
{
return L_2 ;
}
static int F_3 ( struct V_6 * V_7 ,
enum V_1 V_2 )
{
switch ( V_2 ) {
F_4
default:
V_7 -> V_8 . V_9 ++ ;
break;
}
return - V_10 ;
}
static bool F_5 ( struct V_11 * V_12 , void * V_13 )
{
T_1 V_14 = F_6 ( V_12 , V_15 ) ;
return V_14 == * ( int * ) V_13 ;
}
static void F_7 ( struct V_6 * V_7 , struct V_16 * V_17 ,
int V_14 )
{
bool (* F_8)( struct V_11 * , void * ) = NULL ;
struct V_11 * V_12 ;
int V_18 ;
if ( V_14 != - 1 )
F_8 = F_5 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_12 = F_9 ( V_17 , V_18 , F_8 , & V_14 ) ;
while ( V_12 ) {
F_10 ( V_12 ) ;
V_12 = F_9 ( V_17 , V_18 , F_8 , & V_14 ) ;
}
}
}
static void F_11 ( struct V_20 * V_21 )
{
int V_3 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_21 -> V_22 ) ; V_3 ++ )
V_21 -> V_22 [ V_3 ] . V_23 = V_24 ;
}
static T_1 F_12 ( struct V_20 * V_25 )
{
T_1 V_3 ;
V_3 = ( V_25 -> V_26 + 1 ) % V_27 ;
while ( V_3 != V_25 -> V_26 ) {
if ( V_25 -> V_22 [ V_3 ] . V_23 == V_24 ) {
V_25 -> V_26 = V_3 ;
goto V_28;
}
V_3 ++ ;
if ( V_3 == V_27 )
V_3 = 0 ;
}
F_13 ( L_3 ) ;
V_25 -> V_29 ++ ;
V_3 = V_27 ;
V_28:
return V_3 ;
}
static int F_14 ( struct V_20 * V_25 ,
struct V_11 * V_30 , T_1 V_31 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 != V_24 ) {
F_13 ( L_4 ) ;
V_25 -> V_33 ++ ;
return - V_10 ;
}
V_25 -> V_22 [ V_31 ] . V_23 = V_34 ;
V_25 -> V_22 [ V_31 ] . V_30 = V_30 ;
V_25 -> V_35 ++ ;
return 0 ;
}
static int F_15 ( struct V_20 * V_25 ,
T_1 V_31 , struct V_11 * * V_36 ,
bool V_37 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 == V_24 ) {
F_13 ( L_5 ) ;
V_25 -> V_38 ++ ;
return - V_10 ;
}
* V_36 = V_25 -> V_22 [ V_31 ] . V_30 ;
if ( V_37 ) {
V_25 -> V_22 [ V_31 ] . V_23 = V_24 ;
V_25 -> V_22 [ V_31 ] . V_30 = NULL ;
V_25 -> V_39 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_20 * V_25 ,
T_1 V_31 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 == V_24 ) {
F_13 ( L_5 ) ;
return - V_10 ;
}
V_25 -> V_22 [ V_31 ] . V_23 = V_40 ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 ,
bool (* F_18)( struct V_11 * , void * ) ,
int V_14 )
{
struct V_20 * V_25 = & V_7 -> V_21 ;
struct V_11 * V_12 ;
int V_3 ;
enum V_41 V_42 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_25 -> V_22 ) ; V_3 ++ ) {
V_42 = V_25 -> V_22 [ V_3 ] . V_23 ;
if ( V_42 == V_34 ||
V_42 == V_40 ) {
V_12 = V_25 -> V_22 [ V_3 ] . V_30 ;
if ( F_18 == NULL || F_18 ( V_12 , & V_14 ) ) {
if ( V_42 == V_34 )
F_10 ( V_12 ) ;
V_25 -> V_22 [ V_3 ] . V_23 =
V_24 ;
}
}
}
}
static void F_19 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
if ( V_44 == & V_7 -> V_44 . V_45 )
F_20 ( V_44 -> V_5 , L_6 , sizeof( V_44 -> V_5 ) ) ;
else if ( V_44 -> V_46 )
F_21 ( V_44 -> V_5 , sizeof( V_44 -> V_5 ) , L_7 ,
V_44 -> V_46 , V_44 -> V_47 ) ;
else
F_21 ( V_44 -> V_5 , sizeof( V_44 -> V_5 ) , L_8 ,
V_44 -> V_47 ) ;
}
static void F_22 ( struct V_43 * V_44 ,
T_2 * V_48 , T_2 V_14 )
{
F_23 ( V_49 ,
L_9 , V_44 , V_48 , V_14 ) ;
V_44 -> V_50 = 1 ;
V_44 -> V_23 = V_51 ;
V_44 -> V_52 = 0 ;
V_44 -> V_53 = 0 ;
V_44 -> V_47 = V_14 ;
V_44 -> V_54 = 0xff ;
if ( V_48 )
memcpy ( & V_44 -> V_55 [ 0 ] , V_48 , V_56 ) ;
}
static
void F_24 ( struct V_43 * V_44 )
{
F_23 ( V_49 ,
L_10 , V_44 -> V_55 , V_44 -> V_47 ) ;
V_44 -> V_50 = 0 ;
V_44 -> V_23 = V_57 ;
V_44 -> V_52 = 0 ;
V_44 -> V_53 = 0 ;
}
static struct V_43 *
F_25 ( struct V_6 * V_7 , T_2 * V_55 )
{
struct V_43 * V_58 ;
int V_3 ;
if ( V_55 == NULL )
return F_26 ( - V_10 ) ;
V_58 = & V_7 -> V_44 . V_59 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_44 . V_59 ) ; V_3 ++ ) {
if ( V_58 -> V_50 && ! memcmp ( V_58 -> V_55 , V_55 , V_56 ) )
return V_58 ;
V_58 ++ ;
}
return F_26 ( - V_32 ) ;
}
static struct V_43 *
F_27 ( struct V_6 * V_7 , struct V_60 * V_61 , T_2 * V_62 )
{
struct V_43 * V_58 = & V_7 -> V_44 . V_45 ;
bool V_63 ;
V_63 = F_28 ( V_62 ) ;
if ( V_63 && V_61 -> V_64 ) {
V_58 = V_61 -> V_64 ;
goto V_28;
}
V_58 = F_25 ( V_7 , V_62 ) ;
if ( F_29 ( V_58 ) )
V_58 = V_61 -> V_64 ;
V_28:
return V_58 ;
}
static bool F_30 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_65 )
{
struct V_43 * V_66 ;
bool V_67 ;
if ( V_58 -> V_46 ) {
V_66 = & V_7 -> V_44 . V_68 [ V_58 -> V_47 ] ;
if ( V_66 -> V_23 == V_57 )
return true ;
}
V_67 = V_58 -> V_23 == V_57 &&
! V_58 -> V_52 && ! V_58 -> V_53 ;
return V_67 || ! ( V_58 -> V_54 & F_31 ( V_65 ) ) ;
}
static void F_32 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_14 )
{
if ( V_58 -> V_50 && ( V_14 == - 1 || V_14 == V_58 -> V_47 ) ) {
F_7 ( V_7 , & V_58 -> V_69 , V_14 ) ;
V_58 -> V_50 = ! ! ( V_58 -> V_69 . V_70 ) ;
}
}
static void F_33 ( struct V_6 * V_7 ,
bool (* F_18)( struct V_11 * , void * ) ,
int V_14 )
{
struct V_71 * V_72 ;
struct V_16 * V_73 ;
struct V_11 * V_12 ;
int V_18 ;
T_1 V_74 ;
V_73 = F_34 ( V_7 -> V_75 -> V_76 ) ;
if ( F_29 ( V_73 ) ) {
F_23 ( V_49 , L_11 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_73 -> V_19 ; V_18 ++ ) {
V_12 = F_9 ( V_73 , V_18 , F_18 , & V_14 ) ;
while ( V_12 ) {
V_74 = F_35 ( V_12 , V_77 ) ;
V_72 = & V_7 -> V_21 . V_22 [ V_74 ] ;
F_36 ( V_12 != V_72 -> V_30 ) ;
V_72 -> V_23 = V_24 ;
F_10 ( V_12 ) ;
V_12 = F_9 ( V_73 , V_18 , F_18 , & V_14 ) ;
}
}
}
static void F_37 ( struct V_6 * V_7 , int V_14 )
{
int V_3 ;
struct V_43 * V_78 ;
bool (* F_8)( struct V_11 * , void * ) = NULL ;
if ( V_7 == NULL )
return;
if ( V_14 != - 1 )
F_8 = F_5 ;
V_78 = & V_7 -> V_44 . V_59 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_44 . V_59 ) ; V_3 ++ )
F_32 ( V_7 , & V_78 [ V_3 ] , V_14 ) ;
F_32 ( V_7 , & V_7 -> V_44 . V_45 , V_14 ) ;
F_33 ( V_7 , F_8 , V_14 ) ;
F_17 ( V_7 , F_8 , V_14 ) ;
}
static int F_38 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_43 * V_58 = F_39 ( V_12 ) -> V_79 ;
T_2 * V_80 ;
T_3 V_81 = 0 ;
T_2 V_82 ;
T_4 V_83 = F_40 ( F_39 ( V_12 ) -> V_84 ) ;
F_23 ( V_49 , L_12 ,
V_58 -> V_5 , F_6 ( V_12 , V_15 ) ,
F_41 ( V_83 ) , ( F_41 ( V_83 ) >> 8 ) & 0xffff ) ;
if ( V_58 -> V_85 )
V_81 += 2 + V_86 ;
V_81 += 2 + V_87 ;
V_82 = F_42 ( V_81 , 4 ) - V_81 ;
V_81 += V_82 ;
F_43 ( V_12 , V_81 ) ;
V_80 = V_12 -> V_88 ;
V_80 [ 0 ] = V_89 ;
V_80 [ 1 ] = V_87 ;
memcpy ( & V_80 [ 2 ] , & V_83 , sizeof( V_83 ) ) ;
V_80 += V_87 + 2 ;
if ( V_58 -> V_85 ) {
V_58 -> V_85 = 0 ;
V_80 [ 0 ] = V_90 ;
V_80 [ 1 ] = V_86 ;
V_80 [ 2 ] = V_58 -> V_46 ;
V_80 [ 3 ] = V_58 -> V_91 ;
F_23 ( V_49 , L_13 ,
V_58 -> V_46 , V_58 -> V_91 ) ;
V_80 += V_86 + 2 ;
V_58 -> V_92 = V_58 -> V_91 ;
}
if ( V_82 )
memset ( V_80 , V_93 , V_82 ) ;
F_44 ( V_7 -> V_75 , F_6 ( V_12 , V_15 ) ,
V_81 >> 2 , V_12 ) ;
return 0 ;
}
static bool F_45 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_65 , bool V_94 )
{
struct V_11 * V_12 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
T_5 V_99 ;
T_1 V_70 ;
if ( F_46 ( & V_58 -> V_69 , 3 << ( V_65 * 2 ) ) == 0 )
V_58 -> V_91 &= ~ F_47 ( V_65 ) ;
else
V_58 -> V_91 |= F_47 ( V_65 ) ;
V_58 -> V_85 = false ;
if ( V_58 -> V_92 != V_58 -> V_91 )
V_58 -> V_85 = true ;
if ( V_94 && V_58 -> V_85 &&
V_58 -> V_23 == V_57 ) {
V_70 = V_87 + 2 +
V_86 + 2 +
4 + V_7 -> V_75 -> V_100 ;
V_12 = F_48 ( V_70 ) ;
if ( V_12 == NULL )
return false ;
F_49 ( V_12 , V_70 ) ;
V_98 = F_39 ( V_12 ) ;
V_98 -> V_79 = V_58 ;
V_98 -> V_23 = V_101 ;
V_96 = V_7 -> V_75 -> V_76 ;
V_99 = F_38 ( V_7 , V_12 ) ;
if ( V_99 == 0 )
V_99 = F_50 ( V_96 , V_12 ) ;
if ( V_99 )
F_10 ( V_12 ) ;
return true ;
}
return false ;
}
static void
F_51 ( struct V_6 * V_7 , struct V_16 * V_102 ,
T_2 V_103 )
{
struct V_60 * V_61 = V_7 -> V_75 -> V_104 [ ! V_103 ? 0 : V_103 + 1 ] ;
if ( F_36 ( ! V_61 ) )
return;
if ( ( V_61 -> V_105 & V_106 ) &&
V_102 -> V_70 <= V_107 )
F_52 ( V_61 ,
V_106 , false ) ;
if ( ! ( V_61 -> V_105 & V_106 ) &&
V_102 -> V_70 >= V_108 ) {
V_7 -> V_8 . V_109 ++ ;
F_52 ( V_61 , V_106 , true ) ;
}
return;
}
static int F_53 ( struct V_6 * V_7 , T_6 V_110 )
{
F_23 ( V_111 , L_14 , V_110 ) ;
return 0 ;
}
static
int F_54 ( struct V_6 * V_7 , T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 , * V_112 ;
T_7 V_113 ;
T_2 V_46 ;
T_2 V_14 ;
T_2 * V_48 ;
V_46 = * V_88 ++ ;
V_14 = * V_88 ++ ;
V_48 = V_88 ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( type == V_114 ) {
if ( V_58 -> V_50 ) {
F_23 ( V_49 , L_15 ,
V_58 -> V_5 , V_48 ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
F_32 ( V_7 , V_58 , - 1 ) ;
F_24 ( V_58 ) ;
F_56 ( V_7 -> V_75 , V_113 ) ;
} else
V_7 -> V_8 . V_115 ++ ;
return 0 ;
}
V_112 = F_25 ( V_7 , V_48 ) ;
if ( F_29 ( V_112 ) ) {
if ( ! V_58 -> V_50 ) {
F_55 ( V_7 -> V_75 , V_113 ) ;
V_58 -> V_46 = V_46 ;
F_22 ( V_58 , V_48 , V_14 ) ;
F_19 ( V_7 , V_58 ) ;
F_57 ( & V_58 -> V_69 , V_116 ,
V_117 ) ;
F_56 ( V_7 -> V_75 , V_113 ) ;
F_23 ( V_49 , L_16 , V_58 -> V_5 , V_48 ) ;
} else {
V_7 -> V_8 . V_115 ++ ;
}
} else {
if ( V_58 != V_112 ) {
F_23 ( V_49 , L_17 , V_112 -> V_5 ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
memcpy ( V_58 , V_112 ,
F_58 ( struct V_43 , V_69 ) ) ;
V_58 -> V_46 = V_46 ;
F_24 ( V_112 ) ;
F_19 ( V_7 , V_58 ) ;
F_56 ( V_7 -> V_75 , V_113 ) ;
F_23 ( V_49 , L_18 , V_58 -> V_5 ,
V_48 ) ;
} else {
F_23 ( V_49 , L_19 ) ;
F_36 ( V_58 -> V_46 != V_46 ) ;
}
}
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 ;
T_7 V_113 ;
T_2 V_46 ;
int V_118 ;
V_46 = V_88 [ 0 ] ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
V_7 -> V_8 . V_119 ++ ;
return - V_120 ;
}
F_55 ( V_7 -> V_75 , V_113 ) ;
V_58 -> V_52 = 0 ;
V_58 -> V_53 = 0 ;
if ( type == V_121 ) {
V_58 -> V_23 = V_51 ;
V_118 = V_122 ;
} else {
V_58 -> V_23 = V_57 ;
F_45 ( V_7 , V_58 , V_123 , false ) ;
F_45 ( V_7 , V_58 , V_124 , false ) ;
F_45 ( V_7 , V_58 , V_125 , false ) ;
F_45 ( V_7 , V_58 , V_126 , true ) ;
V_118 = V_127 ;
}
F_56 ( V_7 -> V_75 , V_113 ) ;
return V_118 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 ;
T_7 V_113 ;
T_2 V_14 ;
int V_118 ;
V_14 = V_88 [ 0 ] ;
if ( V_14 >= V_128 ) {
V_118 = - V_129 ;
goto V_130;
}
V_58 = & V_7 -> V_44 . V_68 [ V_14 ] ;
if ( ! V_58 -> V_50 ) {
V_118 = - V_120 ;
goto V_130;
}
F_23 ( V_49 , L_20 , F_1 ( type ) , type ,
V_58 -> V_5 ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
switch ( type ) {
case V_131 :
V_58 -> V_23 = V_51 ;
V_118 = V_122 ;
break;
case V_132 :
V_58 -> V_23 = V_57 ;
V_118 = V_127 ;
break;
default:
V_118 = - V_10 ;
F_56 ( V_7 -> V_75 , V_113 ) ;
goto V_130;
}
F_56 ( V_7 -> V_75 , V_113 ) ;
return V_118 ;
V_130:
V_7 -> V_8 . V_133 ++ ;
return V_118 ;
}
static int F_61 ( struct V_6 * V_7 , T_2 type ,
T_2 * V_88 )
{
struct V_43 * V_58 ;
T_7 V_113 ;
V_58 = & V_7 -> V_44 . V_59 [ V_88 [ 1 ] & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
if ( type == V_134 )
V_7 -> V_8 . V_135 ++ ;
else
V_7 -> V_8 . V_136 ++ ;
return - V_120 ;
}
F_23 ( V_49 , L_21 ,
F_1 ( type ) , type , V_58 -> V_5 ,
V_88 [ 0 ] , V_88 [ 2 ] ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
if ( type == V_134 )
V_58 -> V_52 = V_88 [ 0 ] ;
else
V_58 -> V_53 = V_88 [ 0 ] ;
V_58 -> V_54 = V_88 [ 2 ] ;
F_56 ( V_7 -> V_75 , V_113 ) ;
return V_122 ;
}
static void
F_62 ( struct V_43 * V_58 ,
struct V_11 * V_12 )
{
if ( V_58 -> V_52 > 0 ) {
V_58 -> V_52 -- ;
F_63 ( V_12 , V_137 , 1 ) ;
F_63 ( V_12 , V_138 , 1 ) ;
if ( V_58 -> V_23 != V_57 )
F_13 ( L_22 ) ;
} else if ( V_58 -> V_53 > 0 ) {
V_58 -> V_53 -- ;
F_63 ( V_12 , V_137 , 1 ) ;
F_63 ( V_12 , V_138 , 0 ) ;
if ( V_58 -> V_23 != V_57 )
F_13 ( L_23 ) ;
} else {
F_63 ( V_12 , V_137 , 0 ) ;
F_63 ( V_12 , V_138 , 0 ) ;
}
}
static void F_64 ( struct V_11 * V_12 )
{
struct V_43 * V_58 = F_39 ( V_12 ) -> V_79 ;
if ( ( F_6 ( V_12 , V_138 ) ) &&
( V_58 -> V_23 == V_57 ) )
V_58 -> V_52 ++ ;
}
static void F_65 ( struct V_6 * V_7 ,
T_2 V_65 , T_2 V_139 )
{
int V_140 ;
int * V_141 ;
int * V_142 ;
if ( ! V_139 )
return;
V_7 -> V_143 |= 1 << V_65 ;
if ( ( V_65 == V_124 ) &&
( V_7 -> V_144 [ 0 ] ) ) {
for ( V_140 = V_126 ; V_140 >= 0 ;
V_140 -- ) {
V_141 = & V_7 -> V_144 [ V_140 ] ;
if ( * V_141 ) {
V_7 -> V_143 |= ( 1 << V_140 ) ;
V_142 = & V_7 -> V_142 [ V_140 ] ;
if ( * V_141 >= V_139 ) {
* V_141 -= V_139 ;
* V_142 += V_139 ;
return;
} else {
V_139 -= * V_141 ;
* V_142 += * V_141 ;
* V_141 = 0 ;
}
}
}
}
V_7 -> V_142 [ V_65 ] += V_139 ;
}
static void F_66 ( struct V_6 * V_7 )
{
if ( V_7 -> V_143 & V_7 -> V_145 )
F_67 ( V_7 -> V_146 , & V_7 -> V_147 ) ;
}
static int F_68 ( struct V_6 * V_7 ,
enum V_148 V_23 , int V_65 ,
struct V_11 * V_149 )
{
int V_18 = 2 * V_65 ;
T_1 * V_150 = & V_7 -> V_8 . V_151 ;
struct V_43 * V_58 ;
V_58 = F_39 ( V_149 ) -> V_79 ;
if ( V_58 == NULL ) {
F_13 ( L_24 , V_149 ) ;
return - V_32 ;
}
F_23 ( V_152 , L_25 , V_65 , V_149 ) ;
if ( V_23 == V_153 ) {
V_18 += 1 ;
V_150 = & V_7 -> V_8 . V_154 ;
}
if ( F_69 ( & V_58 -> V_69 , V_18 , V_149 ) == NULL ) {
* V_150 += 1 ;
return - V_155 ;
}
V_7 -> V_145 |= 1 << V_65 ;
V_7 -> V_156 [ V_65 ] ++ ;
F_39 ( V_149 ) -> V_23 = V_23 ;
F_45 ( V_7 , V_58 , V_65 , true ) ;
F_51 ( V_7 , & V_58 -> V_69 ,
F_6 ( V_149 , V_15 ) ) ;
return 0 ;
}
static struct V_11 * F_70 ( struct V_6 * V_7 , int V_65 )
{
struct V_43 * V_78 ;
struct V_43 * V_58 ;
struct V_11 * V_149 ;
int V_157 ;
int V_158 ;
int V_159 ;
int V_160 ;
int V_3 ;
V_78 = (struct V_43 * ) & V_7 -> V_44 ;
V_157 = sizeof( V_7 -> V_44 ) / sizeof( struct V_43 ) ;
V_158 = V_7 -> V_161 [ V_65 ] ;
for ( V_3 = 0 ; V_3 < V_157 ; V_3 ++ ) {
V_58 = & V_78 [ ( V_158 + V_3 ) % V_157 ] ;
if ( ! V_58 -> V_50 ||
F_30 ( V_7 , V_58 , V_65 ) )
continue;
if ( V_58 -> V_162 )
V_160 = 2 ;
else
V_160 = 3 ;
V_149 = F_71 ( & V_58 -> V_69 , V_160 << ( V_65 * 2 ) , & V_159 ) ;
if ( V_149 == NULL ) {
if ( V_58 -> V_162 ) {
if ( V_58 -> V_163 )
continue;
V_58 -> V_162 = false ;
V_149 = F_71 ( & V_58 -> V_69 ,
1 << ( V_65 * 2 ) , & V_159 ) ;
}
}
if ( V_149 == NULL )
continue;
F_62 ( V_58 , V_149 ) ;
V_7 -> V_161 [ V_65 ] = ( V_158 + V_3 + 1 ) % V_157 ;
F_51 ( V_7 , & V_58 -> V_69 ,
F_6 ( V_149 ,
V_15 )
) ;
F_45 ( V_7 , V_58 , V_65 , false ) ;
V_7 -> V_156 [ V_65 ] -- ;
if ( V_7 -> V_156 [ V_65 ] == 0 )
V_7 -> V_145 &= ~ ( 1 << V_65 ) ;
goto V_28;
}
V_149 = NULL ;
V_28:
F_23 ( V_152 , L_26 , V_65 , V_149 ) ;
return V_149 ;
}
static int F_72 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 , T_1 V_164 )
{
struct V_43 * V_58 = F_39 ( V_12 ) -> V_79 ;
T_1 V_74 ;
int V_118 ;
T_2 V_14 ;
V_74 = F_35 ( V_12 , V_77 ) ;
if ( ! V_58 -> V_162 ) {
V_58 -> V_162 = true ;
V_58 -> V_163 = V_58 -> V_165 ;
F_23 ( V_152 , L_27 ,
V_58 -> V_5 , V_58 -> V_165 ) ;
}
V_58 -> V_166 = V_164 ;
V_118 = F_73 ( V_7 -> V_75 , false , & V_14 , V_12 ) ;
if ( V_118 == 0 )
V_118 = F_68 ( V_7 , V_153 , V_65 ,
V_12 ) ;
if ( V_118 != 0 ) {
F_15 ( & V_7 -> V_21 , V_74 , & V_12 ,
true ) ;
} else {
F_16 ( & V_7 -> V_21 , V_74 ) ;
}
return V_118 ;
}
static int
F_74 ( struct V_6 * V_7 , T_2 V_113 , T_1 V_74 ,
T_1 V_164 )
{
T_1 V_65 ;
int V_118 ;
bool V_167 = true ;
struct V_11 * V_12 ;
struct V_97 * V_98 ;
struct V_43 * V_58 = NULL ;
F_23 ( V_152 , L_28 , V_113 ) ;
if ( V_113 == V_168 )
V_7 -> V_8 . V_169 ++ ;
else if ( V_113 == V_170 ) {
V_7 -> V_8 . V_171 ++ ;
V_167 = false ;
} else if ( V_113 == V_172 ) {
V_7 -> V_8 . V_173 ++ ;
V_167 = false ;
} else if ( V_113 == V_174 )
V_7 -> V_8 . V_175 ++ ;
else if ( V_113 == V_176 )
V_7 -> V_8 . V_177 ++ ;
else
F_13 ( L_29 ) ;
V_118 = F_15 ( & V_7 -> V_21 , V_74 , & V_12 ,
V_167 ) ;
if ( V_118 != 0 ) {
F_13 ( L_30 , V_74 ) ;
return V_118 ;
}
V_98 = F_39 ( V_12 ) ;
V_58 = V_98 -> V_79 ;
if ( F_36 ( ! V_58 ) ) {
F_10 ( V_12 ) ;
return - V_10 ;
}
V_58 -> V_165 -- ;
if ( V_58 -> V_162 && V_58 -> V_163 )
V_58 -> V_163 -- ;
F_23 ( V_152 , L_31 , V_58 -> V_5 , V_98 -> V_178 ,
V_98 -> V_84 ) ;
V_65 = F_35 ( V_12 , V_179 ) ;
if ( ( V_7 -> V_180 == V_181 ) ||
( F_6 ( V_12 , V_138 ) ) ||
( V_113 == V_176 ) ) {
F_65 ( V_7 , V_65 , 1 ) ;
F_66 ( V_7 ) ;
}
F_64 ( V_12 ) ;
if ( ! V_167 )
V_118 = F_72 ( V_7 , V_65 , V_12 , V_164 ) ;
if ( V_167 || V_118 )
F_75 ( V_7 -> V_75 , V_12 , true ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_7 ,
T_2 * V_88 )
{
T_7 V_113 ;
int V_3 ;
if ( V_7 -> V_180 != V_182 ) {
F_23 ( V_183 , L_32 ) ;
return V_127 ;
}
F_23 ( V_152 , L_33 , V_88 ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
for ( V_3 = 0 ; V_3 < V_184 ; V_3 ++ )
F_65 ( V_7 , V_3 , V_88 [ V_3 ] ) ;
F_23 ( V_152 , L_34 , V_7 -> V_143 ,
V_7 -> V_145 ) ;
F_56 ( V_7 -> V_75 , V_113 ) ;
return V_122 ;
}
static int F_77 ( struct V_6 * V_7 , T_2 * V_88 )
{
T_7 V_185 ;
T_4 V_186 ;
T_1 V_187 ;
T_1 V_74 ;
T_1 V_164 ;
T_2 V_113 ;
V_7 -> V_8 . V_188 ++ ;
memcpy ( & V_186 , V_88 , sizeof( V_186 ) ) ;
V_187 = F_41 ( V_186 ) ;
V_113 = F_78 ( V_187 , V_189 ) ;
V_74 = F_78 ( V_187 , V_77 ) ;
V_164 = F_78 ( V_187 , V_190 ) ;
F_55 ( V_7 -> V_75 , V_185 ) ;
F_74 ( V_7 , V_113 , V_74 , V_164 ) ;
F_56 ( V_7 -> V_75 , V_185 ) ;
return V_127 ;
}
static int F_79 ( struct V_6 * V_7 , T_2 * V_88 )
{
T_4 V_191 ;
memcpy ( & V_191 , & V_88 [ 2 ] , sizeof( V_191 ) ) ;
F_23 ( V_111 , L_35 , V_88 [ 1 ] ,
F_41 ( V_191 ) ) ;
return 0 ;
}
static int F_80 ( struct V_60 * V_61 ,
const struct V_192 * V_193 ,
void * V_88 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
int V_3 ;
T_7 V_113 ;
T_2 * V_139 = V_88 ;
if ( V_193 -> V_194 < V_184 ) {
F_13 ( L_36 , V_193 -> V_194 ) ;
return - V_10 ;
}
if ( V_7 -> V_195 )
return 0 ;
V_7 -> V_195 = true ;
F_23 ( V_49 , L_37 , V_139 ) ;
F_55 ( V_61 -> V_75 , V_113 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_142 ) ; V_3 ++ ) {
if ( * V_139 )
V_7 -> V_143 |= 1 << V_3 ;
else
V_7 -> V_143 &= ~ ( 1 << V_3 ) ;
V_7 -> V_142 [ V_3 ] = * V_139 ++ ;
}
F_66 ( V_7 ) ;
F_56 ( V_61 -> V_75 , V_113 ) ;
return 0 ;
}
static int F_81 ( struct V_60 * V_61 ,
const struct V_192 * V_193 ,
void * V_88 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
T_7 V_113 ;
F_55 ( V_61 -> V_75 , V_113 ) ;
if ( V_7 )
V_7 -> V_196 = true ;
F_56 ( V_61 -> V_75 , V_113 ) ;
return 0 ;
}
int F_82 ( struct V_197 * V_75 , int V_14 , T_8 V_198 ,
struct V_11 * V_12 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
T_2 * V_199 ;
T_8 V_200 ;
T_2 type ;
T_2 V_70 ;
T_2 * V_88 ;
T_5 V_187 ;
T_5 V_99 ;
F_23 ( V_201 , L_38 ,
V_14 , V_12 -> V_70 , V_198 ) ;
F_36 ( V_198 > V_12 -> V_70 ) ;
if ( ! V_198 || ! V_75 -> V_202 ) {
F_49 ( V_12 , V_198 ) ;
return 0 ;
}
V_7 -> V_8 . V_203 ++ ;
V_200 = V_198 ;
V_199 = V_12 -> V_88 ;
V_187 = V_127 ;
while ( V_200 > 0 ) {
type = V_199 [ 0 ] ;
if ( type == V_93 ) {
V_199 += 1 ;
V_200 -= 1 ;
continue;
}
V_70 = V_199 [ 1 ] ;
V_88 = V_199 + 2 ;
F_23 ( V_201 , L_39 ,
F_1 ( type ) , type , V_70 ,
F_3 ( V_7 , type ) ) ;
if ( V_200 < V_70 + 2 )
break;
if ( V_70 < F_3 ( V_7 , type ) )
break;
V_99 = V_127 ;
switch ( type ) {
case V_204 :
case V_205 :
break;
case V_206 :
case V_114 :
F_54 ( V_7 , type , V_88 ) ;
break;
case V_121 :
case V_207 :
V_99 = F_59 ( V_7 , type , V_88 ) ;
break;
case V_131 :
case V_132 :
V_99 = F_60 ( V_7 , type ,
V_88 ) ;
break;
case V_134 :
case V_208 :
V_99 = F_61 ( V_7 , type , V_88 ) ;
break;
case V_209 :
F_77 ( V_7 , V_88 ) ;
break;
case V_210 :
V_99 = F_76 ( V_7 , V_88 ) ;
break;
case V_211 :
F_53 ( V_7 , * V_88 ) ;
break;
case V_212 :
F_79 ( V_7 , V_88 ) ;
break;
case V_89 :
case V_90 :
default:
V_7 -> V_8 . V_9 ++ ;
break;
}
if ( V_99 == V_122 )
V_187 = V_122 ;
V_199 += V_70 + 2 ;
V_200 -= V_70 + 2 ;
}
if ( V_200 != 0 )
V_7 -> V_8 . V_213 ++ ;
if ( V_187 == V_122 )
F_66 ( V_7 ) ;
F_49 ( V_12 , V_198 ) ;
if ( V_12 -> V_70 == 0 )
V_7 -> V_8 . V_214 ++ ;
return 0 ;
}
static void F_83 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_149 )
{
struct V_97 * V_98 = F_39 ( V_149 ) ;
struct V_43 * V_58 = V_98 -> V_79 ;
T_2 V_113 ;
F_63 ( V_149 , V_215 , 1 ) ;
F_84 ( V_149 , V_190 , V_58 -> V_166 ) ;
V_113 = V_216 ;
if ( F_6 ( V_149 , V_137 ) ) {
V_113 |= V_217 ;
}
F_84 ( V_149 , V_189 , V_113 ) ;
F_38 ( V_7 , V_149 ) ;
}
static void F_85 ( struct V_6 * V_7 ,
struct V_11 * V_12 , int V_65 )
{
struct V_43 * V_58 ;
struct V_11 * V_36 ;
int V_218 , V_74 ;
int V_219 = 0 ;
V_58 = F_39 ( V_12 ) -> V_79 ;
if ( V_58 -> V_50 ) {
V_218 = 2 * V_65 ;
if ( F_39 ( V_12 ) -> V_23 == V_153 )
V_218 ++ ;
V_36 = F_86 ( & V_58 -> V_69 , V_218 , V_12 ) ;
if ( V_36 == NULL ) {
F_13 ( L_40 , V_58 -> V_5 , V_218 ) ;
V_219 = - V_220 ;
}
} else {
F_13 ( L_41 , V_58 -> V_5 ) ;
V_219 = - V_32 ;
}
if ( V_219 ) {
V_7 -> V_8 . V_221 ++ ;
V_74 = F_35 ( V_12 , V_77 ) ;
F_74 ( V_7 , V_176 ,
V_74 , 0 ) ;
} else {
V_7 -> V_8 . V_222 ++ ;
F_65 ( V_7 , V_65 , 1 ) ;
F_64 ( V_12 ) ;
}
}
static int F_87 ( struct V_6 * V_7 )
{
int V_140 ;
if ( F_88 ( V_7 -> V_223 , V_224 ) ) {
V_7 -> V_143 &= ~ ( 1 << V_124 ) ;
return - V_225 ;
}
for ( V_140 = 0 ; V_140 <= V_126 ; V_140 ++ ) {
if ( V_7 -> V_142 [ V_140 ] ) {
V_7 -> V_144 [ V_140 ] ++ ;
V_7 -> V_142 [ V_140 ] -- ;
if ( V_7 -> V_142 [ V_140 ] == 0 )
V_7 -> V_143 &= ~ ( 1 << V_140 ) ;
V_7 -> V_143 |= ( 1 << V_124 ) ;
F_23 ( V_152 , L_42 , V_140 ) ;
return 0 ;
}
}
V_7 -> V_143 &= ~ ( 1 << V_124 ) ;
return - V_225 ;
}
static int F_89 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 )
{
struct V_97 * V_98 = F_39 ( V_12 ) ;
struct V_43 * V_58 ;
struct V_95 * V_96 = V_7 -> V_75 -> V_76 ;
int V_219 ;
T_2 V_14 ;
V_58 = V_98 -> V_79 ;
if ( F_29 ( V_58 ) )
return F_90 ( V_58 ) ;
F_83 ( V_7 , V_65 , V_12 ) ;
V_219 = F_50 ( V_96 , V_12 ) ;
F_23 ( V_152 , L_43 , V_58 -> V_5 ,
V_98 -> V_178 , V_98 -> V_84 , V_219 ) ;
if ( V_219 < 0 ) {
F_73 ( V_7 -> V_75 , false , & V_14 , V_12 ) ;
goto V_226;
}
V_58 -> V_165 ++ ;
if ( V_58 -> V_162 )
V_58 -> V_163 ++ ;
V_7 -> V_8 . V_227 ++ ;
V_7 -> V_8 . V_228 [ V_65 ] ++ ;
if ( F_6 ( V_12 , V_137 ) )
V_7 -> V_8 . V_229 [ V_65 ] ++ ;
return V_219 ;
V_226:
F_85 ( V_7 , V_12 , V_65 ) ;
return V_219 ;
}
static int F_91 ( struct V_6 * V_7 , struct V_11 * V_149 ,
int V_65 )
{
struct V_97 * V_98 = F_39 ( V_149 ) ;
int V_219 , V_74 ;
V_74 = F_12 ( & V_7 -> V_21 ) ;
F_84 ( V_149 , V_77 , V_74 ) ;
F_84 ( V_149 , V_230 , V_98 -> V_79 -> V_231 [ V_65 ] ) ;
F_84 ( V_149 , V_179 , V_65 ) ;
V_219 = F_14 ( & V_7 -> V_21 , V_149 , V_74 ) ;
if ( ! V_219 )
V_98 -> V_79 -> V_231 [ V_65 ] ++ ;
else
V_7 -> V_8 . V_232 ++ ;
return V_219 ;
}
int F_92 ( struct V_60 * V_61 , struct V_11 * V_12 )
{
struct V_197 * V_75 = V_61 -> V_75 ;
struct V_6 * V_7 = V_75 -> V_7 ;
struct V_97 * V_98 = F_39 ( V_12 ) ;
struct V_233 * V_234 = (struct V_233 * ) ( V_12 -> V_88 ) ;
T_7 V_113 ;
int V_65 = V_235 ;
bool V_63 = F_28 ( V_234 -> V_236 ) ;
bool V_237 = V_234 -> V_238 == F_93 ( V_239 ) ;
if ( ! V_12 -> V_240 )
V_12 -> V_240 = F_94 ( V_12 ) ;
V_75 -> V_241 += ! ! V_63 ;
if ( V_237 )
F_95 ( & V_61 -> V_242 ) ;
if ( ! F_96 ( V_7 ) ) {
F_44 ( V_75 , V_61 -> V_14 , 0 , V_12 ) ;
return F_50 ( V_75 -> V_76 , V_12 ) ;
}
V_98 -> V_178 = 0 ;
V_98 -> V_23 = V_243 ;
F_63 ( V_12 , V_15 , V_61 -> V_14 ) ;
if ( ! V_63 )
V_65 = V_244 [ V_12 -> V_240 ] ;
F_55 ( V_75 , V_113 ) ;
if ( V_65 != V_124 && V_65 < V_235 )
V_7 -> V_223 = V_224 +
V_245 ;
V_98 -> V_79 = F_27 ( V_7 , V_61 , V_234 -> V_236 ) ;
F_23 ( V_152 , L_44 , V_98 -> V_79 -> V_5 ,
V_234 -> V_236 , V_63 , V_65 ) ;
if ( ! F_91 ( V_7 , V_12 , V_65 ) ) {
F_68 ( V_7 , V_246 , V_65 , V_12 ) ;
F_66 ( V_7 ) ;
} else {
F_13 ( L_45 ) ;
if ( V_237 ) {
F_97 ( & V_61 -> V_242 ) ;
if ( F_98 ( & V_61 -> V_247 ) )
F_99 ( & V_61 -> V_247 ) ;
}
F_10 ( V_12 ) ;
}
F_56 ( V_75 , V_113 ) ;
return 0 ;
}
void F_100 ( struct V_60 * V_61 )
{
struct V_43 * V_58 = V_61 -> V_64 ;
F_23 ( V_49 , L_46 , V_61 -> V_248 ) ;
if ( ! V_58 )
return;
F_22 ( V_58 , V_61 -> V_249 , V_61 -> V_14 ) ;
}
void F_101 ( struct V_60 * V_61 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
struct V_43 * V_58 ;
if ( ! V_61 -> V_250 || ! V_61 -> V_75 -> V_202 )
return;
V_58 = & V_7 -> V_44 . V_68 [ V_61 -> V_14 ] ;
V_61 -> V_64 = V_58 ;
F_22 ( V_58 , V_61 -> V_249 , V_61 -> V_14 ) ;
F_19 ( V_7 , V_58 ) ;
F_57 ( & V_58 -> V_69 , V_116 ,
V_117 ) ;
F_23 ( V_49 , L_47 , V_58 -> V_5 ) ;
}
void F_102 ( struct V_60 * V_61 )
{
struct V_43 * V_58 = V_61 -> V_64 ;
T_7 V_113 ;
if ( ! V_58 )
return;
F_55 ( V_61 -> V_75 , V_113 ) ;
V_61 -> V_64 = NULL ;
F_23 ( V_49 , L_48 , V_58 -> V_5 ) ;
F_24 ( V_58 ) ;
F_37 ( V_61 -> V_75 -> V_7 , V_61 -> V_14 ) ;
F_56 ( V_61 -> V_75 , V_113 ) ;
}
static void F_103 ( struct V_251 * V_252 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
T_7 V_113 ;
int V_65 ;
V_7 = F_104 ( V_252 , struct V_6 , V_147 ) ;
F_55 ( V_7 -> V_75 , V_113 ) ;
for ( V_65 = V_235 ; V_65 >= 0 && ! V_7 -> V_253 ;
V_65 -- ) {
while ( ( V_7 -> V_142 [ V_65 ] ) || ( ( ! V_7 -> V_196 ) &&
( V_65 == V_235 ) ) ) {
V_12 = F_70 ( V_7 , V_65 ) ;
if ( ! V_12 )
break;
V_7 -> V_142 [ V_65 ] -- ;
if ( F_89 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_253 )
break;
}
if ( ( V_65 == V_124 ) &&
( V_7 -> V_142 [ V_65 ] == 0 ) &&
( ! V_7 -> V_253 ) ) {
while ( F_87 ( V_7 ) == 0 ) {
V_12 = F_70 ( V_7 , V_65 ) ;
if ( ! V_12 ) {
F_65 ( V_7 , V_65 , 1 ) ;
break;
}
if ( F_89 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_253 )
break;
}
}
}
F_56 ( V_7 -> V_75 , V_113 ) ;
}
int F_105 ( struct V_197 * V_75 )
{
T_1 V_254 = V_255 ;
int V_219 ;
if ( ! V_75 -> V_202 )
return 0 ;
F_106 ( & V_75 -> V_256 ) ;
V_75 -> V_7 = F_107 ( sizeof( * ( V_75 -> V_7 ) ) , V_257 ) ;
if ( ! V_75 -> V_7 ) {
V_219 = - V_258 ;
goto V_130;
}
V_75 -> V_7 -> V_75 = V_75 ;
V_75 -> V_7 -> V_180 = V_180 ;
V_75 -> V_7 -> V_146 = F_108 ( L_49 ) ;
if ( V_75 -> V_7 -> V_146 == NULL ) {
F_13 ( L_50 ) ;
V_219 = - V_259 ;
goto V_130;
}
F_109 ( & V_75 -> V_7 -> V_147 , F_103 ) ;
if ( V_75 -> V_7 -> V_180 != V_260 )
V_254 |= V_261 |
V_262 |
V_263 ;
V_219 = F_110 ( V_75 , V_264 ,
F_80 ) ;
if ( V_219 < 0 ) {
F_13 ( L_51 ) ;
goto V_130;
}
V_219 = F_110 ( V_75 , V_265 ,
F_81 ) ;
if ( V_219 < 0 ) {
F_13 ( L_52 ) ;
F_111 ( V_75 , V_264 ) ;
goto V_130;
}
if ( F_112 ( V_75 -> V_104 [ 0 ] , L_53 , V_254 ) ) {
F_13 ( L_54 ) ;
goto V_266;
}
F_11 ( & V_75 -> V_7 -> V_21 ) ;
F_22 ( & V_75 -> V_7 -> V_44 . V_45 , NULL , 0 ) ;
F_19 ( V_75 -> V_7 , & V_75 -> V_7 -> V_44 . V_45 ) ;
F_57 ( & V_75 -> V_7 -> V_44 . V_45 . V_69 , V_116 ,
V_117 ) ;
F_113 ( V_75 , & V_75 -> V_7 -> V_8 ) ;
F_23 ( V_183 , L_55 ,
V_75 -> V_202 ? L_56 : L_57 , V_254 ) ;
return 0 ;
V_266:
F_111 ( V_75 , V_265 ) ;
F_111 ( V_75 , V_264 ) ;
V_130:
F_114 ( V_75 ) ;
return V_219 ;
}
void F_114 ( struct V_197 * V_75 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
T_7 V_113 ;
if ( ! V_7 )
return;
V_75 -> V_202 = false ;
if ( V_75 -> V_7 -> V_146 )
F_115 ( V_75 -> V_7 -> V_146 ) ;
F_55 ( V_75 , V_113 ) ;
F_37 ( V_7 , - 1 ) ;
V_75 -> V_7 = NULL ;
F_56 ( V_75 , V_113 ) ;
F_116 ( V_7 ) ;
}
bool F_96 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return false ;
return V_7 -> V_180 != V_260 ;
}
void F_117 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
T_7 V_113 ;
T_1 V_74 ;
if ( F_39 ( V_12 ) -> V_23 == V_101 ) {
F_10 ( V_12 ) ;
return;
}
F_55 ( V_7 -> V_75 , V_113 ) ;
V_74 = F_35 ( V_12 , V_77 ) ;
F_74 ( V_7 , V_176 , V_74 , 0 ) ;
F_56 ( V_7 -> V_75 , V_113 ) ;
}
void F_118 ( struct V_197 * V_75 , bool V_267 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
V_7 -> V_253 = V_267 ;
if ( ! V_267 )
F_66 ( V_7 ) ;
else
V_7 -> V_8 . V_268 ++ ;
}
