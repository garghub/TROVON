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
static void F_5 ( struct V_6 * V_7 )
__acquires( &fws->spinlock
static void F_6 ( struct V_6 * V_7 )
__releases( &fws->spinlock
static bool F_7 ( struct V_11 * V_12 , void * V_13 )
{
T_1 V_14 = F_8 ( V_12 , V_15 ) ;
return V_14 == * ( int * ) V_13 ;
}
static void F_9 ( struct V_6 * V_7 , struct V_16 * V_17 ,
int V_14 )
{
bool (* F_10)( struct V_11 * , void * ) = NULL ;
struct V_11 * V_12 ;
int V_18 ;
if ( V_14 != - 1 )
F_10 = F_7 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_12 = F_11 ( V_17 , V_18 , F_10 , & V_14 ) ;
while ( V_12 ) {
F_12 ( V_12 ) ;
V_12 = F_11 ( V_17 , V_18 , F_10 , & V_14 ) ;
}
}
}
static void F_13 ( struct V_20 * V_21 )
{
int V_3 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_21 -> V_22 ) ; V_3 ++ )
V_21 -> V_22 [ V_3 ] . V_23 = V_24 ;
}
static T_1 F_14 ( struct V_20 * V_25 )
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
F_15 ( L_3 ) ;
V_25 -> V_29 ++ ;
V_3 = V_27 ;
V_28:
return V_3 ;
}
static int F_16 ( struct V_20 * V_25 ,
struct V_11 * V_30 , T_1 V_31 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 != V_24 ) {
F_15 ( L_4 ) ;
V_25 -> V_33 ++ ;
return - V_10 ;
}
V_25 -> V_22 [ V_31 ] . V_23 = V_34 ;
V_25 -> V_22 [ V_31 ] . V_30 = V_30 ;
V_25 -> V_35 ++ ;
return 0 ;
}
static int F_17 ( struct V_20 * V_25 ,
T_1 V_31 , struct V_11 * * V_36 ,
bool V_37 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 == V_24 ) {
F_15 ( L_5 ) ;
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
static int F_18 ( struct V_20 * V_25 ,
T_1 V_31 )
{
if ( V_31 >= V_27 )
return - V_32 ;
if ( V_25 -> V_22 [ V_31 ] . V_23 == V_24 ) {
F_15 ( L_5 ) ;
return - V_10 ;
}
V_25 -> V_22 [ V_31 ] . V_23 = V_40 ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
bool (* F_20)( struct V_11 * , void * ) ,
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
if ( F_20 == NULL || F_20 ( V_12 , & V_14 ) ) {
if ( V_42 == V_34 )
F_12 ( V_12 ) ;
V_25 -> V_22 [ V_3 ] . V_23 =
V_24 ;
}
}
}
}
static void F_21 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
if ( V_44 == & V_7 -> V_44 . V_45 )
F_22 ( V_44 -> V_5 , L_6 , sizeof( V_44 -> V_5 ) ) ;
else if ( V_44 -> V_46 )
F_23 ( V_44 -> V_5 , sizeof( V_44 -> V_5 ) , L_7 ,
V_44 -> V_46 , V_44 -> V_47 ) ;
else
F_23 ( V_44 -> V_5 , sizeof( V_44 -> V_5 ) , L_8 ,
V_44 -> V_47 ) ;
}
static void F_24 ( struct V_43 * V_44 ,
T_2 * V_48 , T_2 V_14 )
{
F_25 ( V_49 ,
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
void F_26 ( struct V_43 * V_44 )
{
F_25 ( V_49 ,
L_10 , V_44 -> V_55 , V_44 -> V_47 ) ;
V_44 -> V_50 = 0 ;
V_44 -> V_23 = V_57 ;
V_44 -> V_52 = 0 ;
V_44 -> V_53 = 0 ;
}
static struct V_43 *
F_27 ( struct V_6 * V_7 , T_2 * V_55 )
{
struct V_43 * V_58 ;
int V_3 ;
if ( V_55 == NULL )
return F_28 ( - V_10 ) ;
V_58 = & V_7 -> V_44 . V_59 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_44 . V_59 ) ; V_3 ++ ) {
if ( V_58 -> V_50 && ! memcmp ( V_58 -> V_55 , V_55 , V_56 ) )
return V_58 ;
V_58 ++ ;
}
return F_28 ( - V_32 ) ;
}
static struct V_43 *
F_29 ( struct V_6 * V_7 , struct V_60 * V_61 , T_2 * V_62 )
{
struct V_43 * V_58 = & V_7 -> V_44 . V_45 ;
bool V_63 ;
V_63 = F_30 ( V_62 ) ;
if ( V_63 && V_61 -> V_64 ) {
V_58 = V_61 -> V_64 ;
goto V_28;
}
V_58 = F_27 ( V_7 , V_62 ) ;
if ( F_31 ( V_58 ) )
V_58 = V_61 -> V_64 ;
V_28:
return V_58 ;
}
static bool F_32 ( struct V_6 * V_7 ,
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
return V_67 || ! ( V_58 -> V_54 & F_33 ( V_65 ) ) ;
}
static void F_34 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_14 )
{
if ( V_58 -> V_50 && ( V_14 == - 1 || V_14 == V_58 -> V_47 ) ) {
F_9 ( V_7 , & V_58 -> V_69 , V_14 ) ;
V_58 -> V_50 = ! ! ( V_58 -> V_69 . V_70 ) ;
}
}
static void F_35 ( struct V_6 * V_7 ,
bool (* F_20)( struct V_11 * , void * ) ,
int V_14 )
{
struct V_71 * V_72 ;
struct V_16 * V_73 ;
struct V_11 * V_12 ;
int V_18 ;
T_1 V_74 ;
V_73 = F_36 ( V_7 -> V_75 -> V_76 ) ;
if ( F_31 ( V_73 ) ) {
F_25 ( V_49 , L_11 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_73 -> V_19 ; V_18 ++ ) {
V_12 = F_11 ( V_73 , V_18 , F_20 , & V_14 ) ;
while ( V_12 ) {
V_74 = F_37 ( V_12 , V_77 ) ;
V_72 = & V_7 -> V_21 . V_22 [ V_74 ] ;
F_38 ( V_12 != V_72 -> V_30 ) ;
V_72 -> V_23 = V_24 ;
F_12 ( V_12 ) ;
V_12 = F_11 ( V_73 , V_18 , F_20 , & V_14 ) ;
}
}
}
static void F_39 ( struct V_6 * V_7 , int V_14 )
{
int V_3 ;
struct V_43 * V_78 ;
bool (* F_10)( struct V_11 * , void * ) = NULL ;
if ( V_7 == NULL )
return;
if ( V_14 != - 1 )
F_10 = F_7 ;
V_78 = & V_7 -> V_44 . V_59 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_44 . V_59 ) ; V_3 ++ )
F_34 ( V_7 , & V_78 [ V_3 ] , V_14 ) ;
F_34 ( V_7 , & V_7 -> V_44 . V_45 , V_14 ) ;
F_35 ( V_7 , F_10 , V_14 ) ;
F_19 ( V_7 , F_10 , V_14 ) ;
}
static int F_40 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
T_2 * V_80 ;
T_3 V_81 = 0 ;
T_2 V_82 ;
T_4 V_83 = F_42 ( F_41 ( V_12 ) -> V_84 ) ;
F_25 ( V_49 , L_12 ,
V_58 -> V_5 , F_8 ( V_12 , V_15 ) ,
F_43 ( V_83 ) , ( F_43 ( V_83 ) >> 8 ) & 0xffff ) ;
if ( V_58 -> V_85 )
V_81 += 2 + V_86 ;
V_81 += 2 + V_87 ;
V_82 = F_44 ( V_81 , 4 ) - V_81 ;
V_81 += V_82 ;
F_45 ( V_12 , V_81 ) ;
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
F_25 ( V_49 , L_13 ,
V_58 -> V_46 , V_58 -> V_91 ) ;
V_80 += V_86 + 2 ;
V_58 -> V_92 = V_58 -> V_91 ;
}
if ( V_82 )
memset ( V_80 , V_93 , V_82 ) ;
F_46 ( V_7 -> V_75 , F_8 ( V_12 , V_15 ) ,
V_81 >> 2 , V_12 ) ;
return 0 ;
}
static bool F_47 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_65 , bool V_94 )
{
struct V_11 * V_12 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
T_5 V_99 ;
T_1 V_70 ;
if ( F_48 ( & V_58 -> V_69 , 3 << ( V_65 * 2 ) ) == 0 )
V_58 -> V_91 &= ~ F_49 ( V_65 ) ;
else
V_58 -> V_91 |= F_49 ( V_65 ) ;
V_58 -> V_85 = false ;
if ( V_58 -> V_92 != V_58 -> V_91 )
V_58 -> V_85 = true ;
if ( V_94 && V_58 -> V_85 &&
V_58 -> V_23 == V_57 ) {
V_70 = V_87 + 2 +
V_86 + 2 +
4 + V_7 -> V_75 -> V_100 ;
V_12 = F_50 ( V_70 ) ;
if ( V_12 == NULL )
return false ;
F_51 ( V_12 , V_70 ) ;
V_98 = F_41 ( V_12 ) ;
V_98 -> V_79 = V_58 ;
V_98 -> V_23 = V_101 ;
V_96 = V_7 -> V_75 -> V_76 ;
V_99 = F_40 ( V_7 , V_12 ) ;
if ( V_99 == 0 ) {
F_6 ( V_7 ) ;
V_99 = F_52 ( V_96 , V_12 ) ;
F_5 ( V_7 ) ;
}
if ( V_99 )
F_12 ( V_12 ) ;
return true ;
}
return false ;
}
static void
F_53 ( struct V_6 * V_7 , struct V_16 * V_102 ,
T_2 V_103 )
{
struct V_60 * V_61 = V_7 -> V_75 -> V_104 [ ! V_103 ? 0 : V_103 + 1 ] ;
if ( F_38 ( ! V_61 ) )
return;
if ( ( V_61 -> V_105 & V_106 ) &&
V_102 -> V_70 <= V_107 )
F_54 ( V_61 ,
V_106 , false ) ;
if ( ! ( V_61 -> V_105 & V_106 ) &&
V_102 -> V_70 >= V_108 ) {
V_7 -> V_8 . V_109 ++ ;
F_54 ( V_61 , V_106 , true ) ;
}
return;
}
static int F_55 ( struct V_6 * V_7 , T_6 V_110 )
{
F_25 ( V_111 , L_14 , V_110 ) ;
return 0 ;
}
static
int F_56 ( struct V_6 * V_7 , T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 , * V_112 ;
T_2 V_46 ;
T_2 V_14 ;
T_2 * V_48 ;
V_46 = * V_88 ++ ;
V_14 = * V_88 ++ ;
V_48 = V_88 ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( type == V_113 ) {
if ( V_58 -> V_50 ) {
F_25 ( V_49 , L_15 ,
V_58 -> V_5 , V_48 ) ;
F_5 ( V_7 ) ;
F_34 ( V_7 , V_58 , - 1 ) ;
F_26 ( V_58 ) ;
F_6 ( V_7 ) ;
} else
V_7 -> V_8 . V_114 ++ ;
return 0 ;
}
V_112 = F_27 ( V_7 , V_48 ) ;
if ( F_31 ( V_112 ) ) {
if ( ! V_58 -> V_50 ) {
F_5 ( V_7 ) ;
V_58 -> V_46 = V_46 ;
F_24 ( V_58 , V_48 , V_14 ) ;
F_21 ( V_7 , V_58 ) ;
F_57 ( & V_58 -> V_69 , V_115 ,
V_116 ) ;
F_6 ( V_7 ) ;
F_25 ( V_49 , L_16 , V_58 -> V_5 , V_48 ) ;
} else {
V_7 -> V_8 . V_114 ++ ;
}
} else {
if ( V_58 != V_112 ) {
F_25 ( V_49 , L_17 , V_112 -> V_5 ) ;
F_5 ( V_7 ) ;
memcpy ( V_58 , V_112 ,
F_58 ( struct V_43 , V_69 ) ) ;
V_58 -> V_46 = V_46 ;
F_26 ( V_112 ) ;
F_21 ( V_7 , V_58 ) ;
F_6 ( V_7 ) ;
F_25 ( V_49 , L_18 , V_58 -> V_5 ,
V_48 ) ;
} else {
F_25 ( V_49 , L_19 ) ;
F_38 ( V_58 -> V_46 != V_46 ) ;
}
}
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 ;
T_2 V_46 ;
int V_117 ;
V_46 = V_88 [ 0 ] ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
V_7 -> V_8 . V_118 ++ ;
return - V_119 ;
}
F_5 ( V_7 ) ;
V_58 -> V_52 = 0 ;
V_58 -> V_53 = 0 ;
if ( type == V_120 ) {
V_58 -> V_23 = V_51 ;
V_117 = V_121 ;
} else {
V_58 -> V_23 = V_57 ;
F_47 ( V_7 , V_58 , V_122 , false ) ;
F_47 ( V_7 , V_58 , V_123 , false ) ;
F_47 ( V_7 , V_58 , V_124 , false ) ;
F_47 ( V_7 , V_58 , V_125 , true ) ;
V_117 = V_126 ;
}
F_6 ( V_7 ) ;
return V_117 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_88 )
{
struct V_43 * V_58 ;
T_2 V_14 ;
int V_117 ;
V_14 = V_88 [ 0 ] ;
if ( V_14 >= V_127 ) {
V_117 = - V_128 ;
goto V_129;
}
V_58 = & V_7 -> V_44 . V_68 [ V_14 ] ;
if ( ! V_58 -> V_50 ) {
V_117 = - V_119 ;
goto V_129;
}
F_25 ( V_49 , L_20 , F_1 ( type ) , type ,
V_58 -> V_5 ) ;
F_5 ( V_7 ) ;
switch ( type ) {
case V_130 :
V_58 -> V_23 = V_51 ;
V_117 = V_121 ;
break;
case V_131 :
V_58 -> V_23 = V_57 ;
V_117 = V_126 ;
break;
default:
V_117 = - V_10 ;
F_6 ( V_7 ) ;
goto V_129;
}
F_6 ( V_7 ) ;
return V_117 ;
V_129:
V_7 -> V_8 . V_132 ++ ;
return V_117 ;
}
static int F_61 ( struct V_6 * V_7 , T_2 type ,
T_2 * V_88 )
{
struct V_43 * V_58 ;
V_58 = & V_7 -> V_44 . V_59 [ V_88 [ 1 ] & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
if ( type == V_133 )
V_7 -> V_8 . V_134 ++ ;
else
V_7 -> V_8 . V_135 ++ ;
return - V_119 ;
}
F_25 ( V_49 , L_21 ,
F_1 ( type ) , type , V_58 -> V_5 ,
V_88 [ 0 ] , V_88 [ 2 ] ) ;
F_5 ( V_7 ) ;
if ( type == V_133 )
V_58 -> V_52 = V_88 [ 0 ] ;
else
V_58 -> V_53 = V_88 [ 0 ] ;
V_58 -> V_54 = V_88 [ 2 ] ;
F_6 ( V_7 ) ;
return V_121 ;
}
static void
F_62 ( struct V_43 * V_58 ,
struct V_11 * V_12 )
{
if ( V_58 -> V_52 > 0 ) {
V_58 -> V_52 -- ;
F_63 ( V_12 , V_136 , 1 ) ;
F_63 ( V_12 , V_137 , 1 ) ;
if ( V_58 -> V_23 != V_57 )
F_15 ( L_22 ) ;
} else if ( V_58 -> V_53 > 0 ) {
V_58 -> V_53 -- ;
F_63 ( V_12 , V_136 , 1 ) ;
F_63 ( V_12 , V_137 , 0 ) ;
if ( V_58 -> V_23 != V_57 )
F_15 ( L_23 ) ;
} else {
F_63 ( V_12 , V_136 , 0 ) ;
F_63 ( V_12 , V_137 , 0 ) ;
}
}
static void F_64 ( struct V_11 * V_12 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
if ( ( F_8 ( V_12 , V_137 ) ) &&
( V_58 -> V_23 == V_57 ) )
V_58 -> V_52 ++ ;
}
static void F_65 ( struct V_6 * V_7 ,
T_2 V_65 , T_2 V_138 )
{
int V_139 ;
int * V_140 ;
int * V_141 ;
if ( ! V_138 )
return;
V_7 -> V_142 |= 1 << V_65 ;
if ( ( V_65 == V_123 ) &&
( V_7 -> V_143 [ 0 ] ) ) {
for ( V_139 = V_125 ; V_139 >= 0 ;
V_139 -- ) {
V_140 = & V_7 -> V_143 [ V_139 ] ;
if ( * V_140 ) {
V_7 -> V_142 |= ( 1 << V_139 ) ;
V_141 = & V_7 -> V_141 [ V_139 ] ;
if ( * V_140 >= V_138 ) {
* V_140 -= V_138 ;
* V_141 += V_138 ;
return;
} else {
V_138 -= * V_140 ;
* V_141 += * V_140 ;
* V_140 = 0 ;
}
}
}
}
V_7 -> V_141 [ V_65 ] += V_138 ;
}
static void F_66 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_142 & V_7 -> V_144 ) ||
( ! F_67 ( V_7 ) && V_7 -> V_144 ) )
F_68 ( V_7 -> V_145 , & V_7 -> V_146 ) ;
}
static int F_69 ( struct V_6 * V_7 ,
enum V_147 V_23 , int V_65 ,
struct V_11 * V_148 )
{
int V_18 = 2 * V_65 ;
T_1 * V_149 = & V_7 -> V_8 . V_150 ;
struct V_43 * V_58 ;
V_58 = F_41 ( V_148 ) -> V_79 ;
if ( V_58 == NULL ) {
F_15 ( L_24 , V_148 ) ;
return - V_32 ;
}
F_25 ( V_151 , L_25 , V_65 , V_148 ) ;
if ( V_23 == V_152 ) {
V_18 += 1 ;
V_149 = & V_7 -> V_8 . V_153 ;
}
if ( F_70 ( & V_58 -> V_69 , V_18 , V_148 ) == NULL ) {
* V_149 += 1 ;
return - V_154 ;
}
V_7 -> V_144 |= 1 << V_65 ;
V_7 -> V_155 [ V_65 ] ++ ;
F_41 ( V_148 ) -> V_23 = V_23 ;
F_47 ( V_7 , V_58 , V_65 , true ) ;
F_53 ( V_7 , & V_58 -> V_69 ,
F_8 ( V_148 , V_15 ) ) ;
return 0 ;
}
static struct V_11 * F_71 ( struct V_6 * V_7 , int V_65 )
{
struct V_43 * V_78 ;
struct V_43 * V_58 ;
struct V_11 * V_148 ;
int V_156 ;
int V_157 ;
int V_158 ;
int V_159 ;
int V_3 ;
V_78 = (struct V_43 * ) & V_7 -> V_44 ;
V_156 = sizeof( V_7 -> V_44 ) / sizeof( struct V_43 ) ;
V_157 = V_7 -> V_160 [ V_65 ] ;
for ( V_3 = 0 ; V_3 < V_156 ; V_3 ++ ) {
V_58 = & V_78 [ ( V_157 + V_3 ) % V_156 ] ;
if ( ! V_58 -> V_50 ||
F_32 ( V_7 , V_58 , V_65 ) )
continue;
if ( V_58 -> V_161 )
V_159 = 2 ;
else
V_159 = 3 ;
V_148 = F_72 ( & V_58 -> V_69 , V_159 << ( V_65 * 2 ) , & V_158 ) ;
if ( V_148 == NULL ) {
if ( V_58 -> V_161 ) {
if ( V_58 -> V_162 )
continue;
V_58 -> V_161 = false ;
V_148 = F_72 ( & V_58 -> V_69 ,
1 << ( V_65 * 2 ) , & V_158 ) ;
}
}
if ( V_148 == NULL )
continue;
F_62 ( V_58 , V_148 ) ;
V_7 -> V_160 [ V_65 ] = ( V_157 + V_3 + 1 ) % V_156 ;
F_53 ( V_7 , & V_58 -> V_69 ,
F_8 ( V_148 ,
V_15 )
) ;
F_47 ( V_7 , V_58 , V_65 , false ) ;
V_7 -> V_155 [ V_65 ] -- ;
if ( V_7 -> V_155 [ V_65 ] == 0 )
V_7 -> V_144 &= ~ ( 1 << V_65 ) ;
goto V_28;
}
V_148 = NULL ;
V_28:
F_25 ( V_151 , L_26 , V_65 , V_148 ) ;
return V_148 ;
}
static int F_73 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 , T_1 V_163 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
T_1 V_74 ;
int V_117 ;
T_2 V_14 ;
V_74 = F_37 ( V_12 , V_77 ) ;
if ( ! V_58 -> V_161 ) {
V_58 -> V_161 = true ;
V_58 -> V_162 = V_58 -> V_164 ;
F_25 ( V_151 , L_27 ,
V_58 -> V_5 , V_58 -> V_164 ) ;
}
V_58 -> V_165 = V_163 ;
V_117 = F_74 ( V_7 -> V_75 , false , & V_14 , V_12 ) ;
if ( V_117 == 0 )
V_117 = F_69 ( V_7 , V_152 , V_65 ,
V_12 ) ;
if ( V_117 != 0 ) {
F_17 ( & V_7 -> V_21 , V_74 , & V_12 ,
true ) ;
} else {
F_18 ( & V_7 -> V_21 , V_74 ) ;
}
return V_117 ;
}
static int
F_75 ( struct V_6 * V_7 , T_2 V_166 , T_1 V_74 ,
T_1 V_163 )
{
T_1 V_65 ;
int V_117 ;
bool V_167 = true ;
struct V_11 * V_12 ;
struct V_97 * V_98 ;
struct V_43 * V_58 = NULL ;
F_25 ( V_151 , L_28 , V_166 ) ;
if ( V_166 == V_168 )
V_7 -> V_8 . V_169 ++ ;
else if ( V_166 == V_170 ) {
V_7 -> V_8 . V_171 ++ ;
V_167 = false ;
} else if ( V_166 == V_172 ) {
V_7 -> V_8 . V_173 ++ ;
V_167 = false ;
} else if ( V_166 == V_174 )
V_7 -> V_8 . V_175 ++ ;
else if ( V_166 == V_176 )
V_7 -> V_8 . V_177 ++ ;
else
F_15 ( L_29 ) ;
V_117 = F_17 ( & V_7 -> V_21 , V_74 , & V_12 ,
V_167 ) ;
if ( V_117 != 0 ) {
F_15 ( L_30 , V_74 ) ;
return V_117 ;
}
V_98 = F_41 ( V_12 ) ;
V_58 = V_98 -> V_79 ;
if ( F_38 ( ! V_58 ) ) {
F_12 ( V_12 ) ;
return - V_10 ;
}
V_58 -> V_164 -- ;
if ( V_58 -> V_161 && V_58 -> V_162 )
V_58 -> V_162 -- ;
F_25 ( V_151 , L_31 , V_58 -> V_5 , V_98 -> V_178 ,
V_98 -> V_84 ) ;
V_65 = F_37 ( V_12 , V_179 ) ;
if ( ( V_7 -> V_180 == V_181 ) ||
( F_8 ( V_12 , V_137 ) ) ||
( V_166 == V_176 ) ) {
F_65 ( V_7 , V_65 , 1 ) ;
F_66 ( V_7 ) ;
}
F_64 ( V_12 ) ;
if ( ! V_167 )
V_117 = F_73 ( V_7 , V_65 , V_12 , V_163 ) ;
if ( V_167 || V_117 )
F_76 ( V_7 -> V_75 , V_12 , true ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_7 ,
T_2 * V_88 )
{
int V_3 ;
if ( V_7 -> V_180 != V_182 ) {
F_25 ( V_183 , L_32 ) ;
return V_126 ;
}
F_25 ( V_151 , L_33 , V_88 ) ;
F_5 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < V_184 ; V_3 ++ )
F_65 ( V_7 , V_3 , V_88 [ V_3 ] ) ;
F_25 ( V_151 , L_34 , V_7 -> V_142 ,
V_7 -> V_144 ) ;
F_6 ( V_7 ) ;
return V_121 ;
}
static int F_78 ( struct V_6 * V_7 , T_2 * V_88 )
{
T_4 V_185 ;
T_1 V_186 ;
T_1 V_74 ;
T_1 V_163 ;
T_2 V_166 ;
V_7 -> V_8 . V_187 ++ ;
memcpy ( & V_185 , V_88 , sizeof( V_185 ) ) ;
V_186 = F_43 ( V_185 ) ;
V_166 = F_79 ( V_186 , V_188 ) ;
V_74 = F_79 ( V_186 , V_77 ) ;
V_163 = F_79 ( V_186 , V_189 ) ;
F_5 ( V_7 ) ;
F_75 ( V_7 , V_166 , V_74 , V_163 ) ;
F_6 ( V_7 ) ;
return V_126 ;
}
static int F_80 ( struct V_6 * V_7 , T_2 * V_88 )
{
T_4 V_190 ;
memcpy ( & V_190 , & V_88 [ 2 ] , sizeof( V_190 ) ) ;
F_25 ( V_111 , L_35 , V_88 [ 1 ] ,
F_43 ( V_190 ) ) ;
return 0 ;
}
static int F_81 ( struct V_60 * V_61 ,
const struct V_191 * V_192 ,
void * V_88 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
int V_3 ;
T_2 * V_138 = V_88 ;
if ( V_192 -> V_193 < V_184 ) {
F_15 ( L_36 , V_192 -> V_193 ) ;
return - V_10 ;
}
if ( V_7 -> V_194 )
return 0 ;
V_7 -> V_194 = true ;
F_25 ( V_49 , L_37 , V_138 ) ;
F_5 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_141 ) ; V_3 ++ ) {
if ( * V_138 )
V_7 -> V_142 |= 1 << V_3 ;
else
V_7 -> V_142 &= ~ ( 1 << V_3 ) ;
V_7 -> V_141 [ V_3 ] = * V_138 ++ ;
}
F_66 ( V_7 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_82 ( struct V_60 * V_61 ,
const struct V_191 * V_192 ,
void * V_88 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
F_5 ( V_7 ) ;
if ( V_7 )
V_7 -> V_195 = true ;
F_6 ( V_7 ) ;
return 0 ;
}
int F_83 ( struct V_196 * V_75 , int V_14 , T_7 V_197 ,
struct V_11 * V_12 )
{
struct V_198 * V_199 ;
struct V_6 * V_7 = V_75 -> V_7 ;
T_2 * V_200 ;
T_7 V_201 ;
T_2 type ;
T_2 V_70 ;
T_2 * V_88 ;
T_5 V_186 ;
T_5 V_99 ;
F_25 ( V_202 , L_38 ,
V_14 , V_12 -> V_70 , V_197 ) ;
F_38 ( V_197 > V_12 -> V_70 ) ;
if ( ! V_197 )
return 0 ;
if ( ! V_7 -> V_203 ) {
F_51 ( V_12 , V_197 ) ;
return 0 ;
}
V_7 -> V_8 . V_204 ++ ;
V_201 = V_197 ;
V_200 = V_12 -> V_88 ;
V_186 = V_126 ;
while ( V_201 > 0 ) {
type = V_200 [ 0 ] ;
if ( type == V_93 ) {
V_200 += 1 ;
V_201 -= 1 ;
continue;
}
V_70 = V_200 [ 1 ] ;
V_88 = V_200 + 2 ;
F_25 ( V_202 , L_39 ,
F_1 ( type ) , type , V_70 ,
F_3 ( V_7 , type ) ) ;
if ( V_201 < V_70 + 2 )
break;
if ( V_70 < F_3 ( V_7 , type ) )
break;
V_99 = V_126 ;
switch ( type ) {
case V_205 :
break;
case V_206 :
V_199 = (struct V_198 * ) V_12 -> V_207 ;
V_199 -> V_208 = V_88 ;
break;
case V_209 :
case V_113 :
F_56 ( V_7 , type , V_88 ) ;
break;
case V_120 :
case V_210 :
V_99 = F_59 ( V_7 , type , V_88 ) ;
break;
case V_130 :
case V_131 :
V_99 = F_60 ( V_7 , type ,
V_88 ) ;
break;
case V_133 :
case V_211 :
V_99 = F_61 ( V_7 , type , V_88 ) ;
break;
case V_212 :
F_78 ( V_7 , V_88 ) ;
break;
case V_213 :
V_99 = F_77 ( V_7 , V_88 ) ;
break;
case V_214 :
F_55 ( V_7 , * V_88 ) ;
break;
case V_215 :
F_80 ( V_7 , V_88 ) ;
break;
case V_89 :
case V_90 :
default:
V_7 -> V_8 . V_9 ++ ;
break;
}
if ( V_99 == V_121 )
V_186 = V_121 ;
V_200 += V_70 + 2 ;
V_201 -= V_70 + 2 ;
}
if ( V_201 != 0 )
V_7 -> V_8 . V_216 ++ ;
if ( V_186 == V_121 )
F_66 ( V_7 ) ;
F_51 ( V_12 , V_197 ) ;
if ( V_12 -> V_70 == 0 )
V_7 -> V_8 . V_217 ++ ;
return 0 ;
}
static void F_84 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_148 )
{
struct V_97 * V_98 = F_41 ( V_148 ) ;
struct V_43 * V_58 = V_98 -> V_79 ;
T_2 V_166 ;
F_63 ( V_148 , V_218 , 1 ) ;
F_85 ( V_148 , V_189 , V_58 -> V_165 ) ;
V_166 = V_219 ;
if ( F_8 ( V_148 , V_136 ) ) {
V_166 |= V_220 ;
}
F_85 ( V_148 , V_188 , V_166 ) ;
F_40 ( V_7 , V_148 ) ;
}
static void F_86 ( struct V_6 * V_7 ,
struct V_11 * V_12 , int V_65 )
{
struct V_43 * V_58 ;
struct V_11 * V_36 ;
int V_221 , V_74 ;
int V_222 = 0 ;
V_58 = F_41 ( V_12 ) -> V_79 ;
if ( V_58 -> V_50 ) {
V_221 = 2 * V_65 ;
if ( F_41 ( V_12 ) -> V_23 == V_152 )
V_221 ++ ;
V_36 = F_87 ( & V_58 -> V_69 , V_221 , V_12 ) ;
if ( V_36 == NULL ) {
F_15 ( L_40 , V_58 -> V_5 , V_221 ) ;
V_222 = - V_223 ;
}
} else {
F_15 ( L_41 , V_58 -> V_5 ) ;
V_222 = - V_32 ;
}
if ( V_222 ) {
V_7 -> V_8 . V_224 ++ ;
V_74 = F_37 ( V_12 , V_77 ) ;
F_75 ( V_7 , V_176 ,
V_74 , 0 ) ;
} else {
V_7 -> V_8 . V_225 ++ ;
F_65 ( V_7 , V_65 , 1 ) ;
F_64 ( V_12 ) ;
}
}
static int F_88 ( struct V_6 * V_7 )
{
int V_139 ;
if ( F_89 ( V_7 -> V_226 , V_227 ) ) {
V_7 -> V_142 &= ~ ( 1 << V_123 ) ;
return - V_228 ;
}
for ( V_139 = 0 ; V_139 <= V_125 ; V_139 ++ ) {
if ( V_7 -> V_141 [ V_139 ] ) {
V_7 -> V_143 [ V_139 ] ++ ;
V_7 -> V_141 [ V_139 ] -- ;
if ( V_7 -> V_141 [ V_139 ] == 0 )
V_7 -> V_142 &= ~ ( 1 << V_139 ) ;
V_7 -> V_142 |= ( 1 << V_123 ) ;
F_25 ( V_151 , L_42 , V_139 ) ;
return 0 ;
}
}
V_7 -> V_142 &= ~ ( 1 << V_123 ) ;
return - V_228 ;
}
static int F_90 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 )
{
struct V_97 * V_98 = F_41 ( V_12 ) ;
struct V_43 * V_58 ;
struct V_95 * V_96 = V_7 -> V_75 -> V_76 ;
int V_222 ;
T_2 V_14 ;
V_58 = V_98 -> V_79 ;
if ( F_31 ( V_58 ) )
return F_91 ( V_58 ) ;
F_84 ( V_7 , V_65 , V_12 ) ;
V_58 -> V_164 ++ ;
if ( V_58 -> V_161 )
V_58 -> V_162 ++ ;
F_6 ( V_7 ) ;
V_222 = F_52 ( V_96 , V_12 ) ;
F_5 ( V_7 ) ;
F_25 ( V_151 , L_43 , V_58 -> V_5 ,
V_98 -> V_178 , V_98 -> V_84 , V_222 ) ;
if ( V_222 < 0 ) {
V_58 -> V_164 -- ;
if ( V_58 -> V_161 )
V_58 -> V_162 -- ;
F_74 ( V_7 -> V_75 , false , & V_14 , V_12 ) ;
goto V_229;
}
V_7 -> V_8 . V_230 ++ ;
V_7 -> V_8 . V_231 [ V_65 ] ++ ;
if ( F_8 ( V_12 , V_136 ) )
V_7 -> V_8 . V_232 [ V_65 ] ++ ;
return V_222 ;
V_229:
F_86 ( V_7 , V_12 , V_65 ) ;
return V_222 ;
}
static int F_92 ( struct V_6 * V_7 , struct V_11 * V_148 ,
int V_65 )
{
struct V_97 * V_98 = F_41 ( V_148 ) ;
int V_222 , V_74 ;
V_74 = F_14 ( & V_7 -> V_21 ) ;
F_85 ( V_148 , V_77 , V_74 ) ;
F_85 ( V_148 , V_233 , V_98 -> V_79 -> V_234 [ V_65 ] ) ;
F_85 ( V_148 , V_179 , V_65 ) ;
V_222 = F_16 ( & V_7 -> V_21 , V_148 , V_74 ) ;
if ( ! V_222 )
V_98 -> V_79 -> V_234 [ V_65 ] ++ ;
else
V_7 -> V_8 . V_235 ++ ;
return V_222 ;
}
int F_93 ( struct V_60 * V_61 , struct V_11 * V_12 )
{
struct V_196 * V_75 = V_61 -> V_75 ;
struct V_6 * V_7 = V_75 -> V_7 ;
struct V_97 * V_98 = F_41 ( V_12 ) ;
struct V_236 * V_237 = (struct V_236 * ) ( V_12 -> V_88 ) ;
int V_65 = V_238 ;
bool V_63 = F_30 ( V_237 -> V_239 ) ;
bool V_240 = V_237 -> V_241 == F_94 ( V_242 ) ;
F_25 ( V_151 , L_44 , F_95 ( V_237 -> V_241 ) ) ;
if ( ! V_12 -> V_243 )
V_12 -> V_243 = F_96 ( V_12 ) ;
V_75 -> V_244 += ! ! V_63 ;
if ( V_240 )
F_97 ( & V_61 -> V_245 ) ;
V_98 -> V_178 = 0 ;
V_98 -> V_23 = V_246 ;
F_63 ( V_12 , V_15 , V_61 -> V_14 ) ;
if ( ! V_63 )
V_65 = V_247 [ V_12 -> V_243 ] ;
F_5 ( V_7 ) ;
if ( V_65 != V_123 && V_65 < V_238 )
V_7 -> V_226 = V_227 +
V_248 ;
V_98 -> V_79 = F_29 ( V_7 , V_61 , V_237 -> V_239 ) ;
F_25 ( V_151 , L_45 , V_98 -> V_79 -> V_5 ,
V_237 -> V_239 , V_63 , V_65 ) ;
if ( ! F_92 ( V_7 , V_12 , V_65 ) ) {
F_69 ( V_7 , V_249 , V_65 , V_12 ) ;
F_66 ( V_7 ) ;
} else {
F_15 ( L_46 ) ;
if ( V_240 ) {
F_98 ( & V_61 -> V_245 ) ;
if ( F_99 ( & V_61 -> V_250 ) )
F_100 ( & V_61 -> V_250 ) ;
}
F_12 ( V_12 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
void F_101 ( struct V_60 * V_61 )
{
struct V_43 * V_58 = V_61 -> V_64 ;
F_25 ( V_49 , L_47 , V_61 -> V_251 ) ;
if ( ! V_58 )
return;
F_24 ( V_58 , V_61 -> V_252 , V_61 -> V_14 ) ;
}
void F_102 ( struct V_60 * V_61 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
struct V_43 * V_58 ;
if ( ! V_61 -> V_253 )
return;
V_58 = & V_7 -> V_44 . V_68 [ V_61 -> V_14 ] ;
V_61 -> V_64 = V_58 ;
F_24 ( V_58 , V_61 -> V_252 , V_61 -> V_14 ) ;
F_21 ( V_7 , V_58 ) ;
F_57 ( & V_58 -> V_69 , V_115 ,
V_116 ) ;
F_25 ( V_49 , L_48 , V_58 -> V_5 ) ;
}
void F_103 ( struct V_60 * V_61 )
{
struct V_43 * V_58 = V_61 -> V_64 ;
if ( ! V_58 )
return;
F_5 ( V_61 -> V_75 -> V_7 ) ;
V_61 -> V_64 = NULL ;
F_25 ( V_49 , L_49 , V_58 -> V_5 ) ;
F_26 ( V_58 ) ;
F_39 ( V_61 -> V_75 -> V_7 , V_61 -> V_14 ) ;
F_6 ( V_61 -> V_75 -> V_7 ) ;
}
static void F_104 ( struct V_254 * V_255 )
{
struct V_6 * V_7 ;
struct V_196 * V_75 ;
struct V_11 * V_12 ;
int V_65 ;
T_1 V_74 ;
T_1 V_14 ;
int V_117 ;
V_7 = F_105 ( V_255 , struct V_6 , V_146 ) ;
V_75 = V_7 -> V_75 ;
F_5 ( V_7 ) ;
for ( V_65 = V_238 ; V_65 >= 0 && ! V_7 -> V_256 ;
V_65 -- ) {
if ( ! F_67 ( V_7 ) ) {
while ( ( V_12 = F_71 ( V_7 , V_65 ) ) != NULL ) {
V_74 = F_37 ( V_12 ,
V_77 ) ;
F_17 ( & V_7 -> V_21 , V_74 ,
& V_12 , true ) ;
V_14 = F_8 ( V_12 ,
V_15 ) ;
F_46 ( V_75 , V_14 , 0 , V_12 ) ;
F_6 ( V_7 ) ;
V_117 = F_52 ( V_75 -> V_76 , V_12 ) ;
F_5 ( V_7 ) ;
if ( V_117 < 0 )
F_76 ( V_75 , V_12 , false ) ;
if ( V_7 -> V_256 )
break;
}
continue;
}
while ( ( V_7 -> V_141 [ V_65 ] ) || ( ( ! V_7 -> V_195 ) &&
( V_65 == V_238 ) ) ) {
V_12 = F_71 ( V_7 , V_65 ) ;
if ( ! V_12 )
break;
V_7 -> V_141 [ V_65 ] -- ;
if ( F_90 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_256 )
break;
}
if ( ( V_65 == V_123 ) &&
( V_7 -> V_141 [ V_65 ] == 0 ) &&
( ! V_7 -> V_256 ) ) {
while ( F_88 ( V_7 ) == 0 ) {
V_12 = F_71 ( V_7 , V_65 ) ;
if ( ! V_12 ) {
F_65 ( V_7 , V_65 , 1 ) ;
break;
}
if ( F_90 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_256 )
break;
}
}
}
F_6 ( V_7 ) ;
}
int F_106 ( struct V_196 * V_75 )
{
struct V_6 * V_7 ;
T_1 V_257 = V_258 ;
int V_222 ;
V_75 -> V_7 = F_107 ( sizeof( * ( V_75 -> V_7 ) ) , V_259 ) ;
if ( ! V_75 -> V_7 ) {
V_222 = - V_260 ;
goto V_129;
}
V_7 = V_75 -> V_7 ;
F_108 ( & V_7 -> V_261 ) ;
V_7 -> V_75 = V_75 ;
V_7 -> V_180 = V_180 ;
V_7 -> V_145 = F_109 ( L_50 ) ;
if ( V_7 -> V_145 == NULL ) {
F_15 ( L_51 ) ;
V_222 = - V_262 ;
goto V_129;
}
F_110 ( & V_7 -> V_146 , F_104 ) ;
if ( V_7 -> V_180 != V_263 )
V_257 |= V_264 |
V_265 |
V_266 |
V_267 ;
V_222 = F_111 ( V_75 , V_268 ,
F_81 ) ;
if ( V_222 < 0 ) {
F_15 ( L_52 ) ;
goto V_129;
}
V_222 = F_111 ( V_75 , V_269 ,
F_82 ) ;
if ( V_222 < 0 ) {
F_15 ( L_53 ) ;
F_112 ( V_75 , V_268 ) ;
goto V_129;
}
V_7 -> V_203 = true ;
if ( F_113 ( V_75 -> V_104 [ 0 ] , L_54 , V_257 ) ) {
F_15 ( L_55 ) ;
V_7 -> V_180 = V_263 ;
V_7 -> V_203 = false ;
}
if ( F_113 ( V_75 -> V_104 [ 0 ] , L_56 , 1 ) )
F_25 ( V_183 , L_57 ) ;
F_13 ( & V_7 -> V_21 ) ;
F_24 ( & V_7 -> V_44 . V_45 , NULL , 0 ) ;
F_21 ( V_7 , & V_7 -> V_44 . V_45 ) ;
F_57 ( & V_7 -> V_44 . V_45 . V_69 , V_115 ,
V_116 ) ;
F_114 ( V_75 , & V_7 -> V_8 ) ;
F_25 ( V_183 , L_58 ,
V_7 -> V_203 ? L_59 : L_60 , V_257 ) ;
return 0 ;
V_129:
F_115 ( V_75 ) ;
return V_222 ;
}
void F_115 ( struct V_196 * V_75 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
if ( ! V_7 )
return;
if ( V_75 -> V_7 -> V_145 )
F_116 ( V_75 -> V_7 -> V_145 ) ;
F_5 ( V_7 ) ;
F_39 ( V_7 , - 1 ) ;
V_75 -> V_7 = NULL ;
F_6 ( V_7 ) ;
F_117 ( V_7 ) ;
}
bool F_67 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_194 )
return false ;
return V_7 -> V_180 != V_263 ;
}
void F_118 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
T_1 V_74 ;
if ( F_41 ( V_12 ) -> V_23 == V_101 ) {
F_12 ( V_12 ) ;
return;
}
F_5 ( V_7 ) ;
V_74 = F_37 ( V_12 , V_77 ) ;
F_75 ( V_7 , V_176 , V_74 , 0 ) ;
F_6 ( V_7 ) ;
}
void F_119 ( struct V_196 * V_75 , bool V_270 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
V_7 -> V_256 = V_270 ;
if ( ! V_270 )
F_66 ( V_7 ) ;
else
V_7 -> V_8 . V_271 ++ ;
}
