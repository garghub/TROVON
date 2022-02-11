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
static T_2 F_40 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
T_2 * V_80 ;
T_3 V_81 = 0 ;
T_2 V_82 ;
T_4 V_83 = F_42 ( F_41 ( V_12 ) -> V_84 ) ;
T_5 V_85 = F_43 ( F_41 ( V_12 ) -> V_86 ) ;
F_25 ( V_49 , L_12 ,
V_58 -> V_5 , F_8 ( V_12 , V_15 ) ,
( F_44 ( V_83 ) >> 8 ) & 0xffff ,
F_41 ( V_12 ) -> V_84 , F_41 ( V_12 ) -> V_86 ) ;
if ( V_58 -> V_87 )
V_81 += 2 + V_88 ;
if ( F_45 ( V_7 -> V_89 ) )
V_81 += V_90 ;
V_81 += 2 + V_91 ;
V_82 = F_46 ( V_81 , 4 ) - V_81 ;
V_81 += V_82 ;
F_47 ( V_12 , V_81 ) ;
V_80 = V_12 -> V_92 ;
V_80 [ 0 ] = V_93 ;
V_80 [ 1 ] = V_91 ;
memcpy ( & V_80 [ 2 ] , & V_83 , sizeof( V_83 ) ) ;
if ( F_45 ( V_7 -> V_89 ) ) {
V_80 [ 1 ] += V_90 ;
memcpy ( & V_80 [ 2 + V_91 ] , & V_85 ,
sizeof( V_85 ) ) ;
}
V_80 += V_80 [ 1 ] + 2 ;
if ( V_58 -> V_87 ) {
V_58 -> V_87 = 0 ;
V_80 [ 0 ] = V_94 ;
V_80 [ 1 ] = V_88 ;
V_80 [ 2 ] = V_58 -> V_46 ;
V_80 [ 3 ] = V_58 -> V_95 ;
F_25 ( V_49 , L_13 ,
V_58 -> V_46 , V_58 -> V_95 ) ;
V_80 += V_88 + 2 ;
V_58 -> V_96 = V_58 -> V_95 ;
}
if ( V_82 )
memset ( V_80 , V_97 , V_82 ) ;
return ( T_2 ) ( V_81 >> 2 ) ;
}
static bool F_48 ( struct V_6 * V_7 ,
struct V_43 * V_58 ,
int V_65 , bool V_98 )
{
struct V_11 * V_12 ;
struct V_99 * V_100 ;
T_6 V_101 ;
T_1 V_70 ;
T_2 V_81 ;
int V_14 ;
if ( F_49 ( & V_58 -> V_69 , 3 << ( V_65 * 2 ) ) == 0 )
V_58 -> V_95 &= ~ F_50 ( V_65 ) ;
else
V_58 -> V_95 |= F_50 ( V_65 ) ;
V_58 -> V_87 = false ;
if ( V_58 -> V_96 != V_58 -> V_95 )
V_58 -> V_87 = true ;
if ( V_98 && V_58 -> V_87 &&
V_58 -> V_23 == V_57 ) {
V_70 = V_91 + 2 +
V_90 +
V_88 + 2 +
4 + V_7 -> V_75 -> V_102 ;
V_12 = F_51 ( V_70 ) ;
if ( V_12 == NULL )
return false ;
F_52 ( V_12 , V_70 ) ;
V_100 = F_41 ( V_12 ) ;
V_100 -> V_79 = V_58 ;
V_100 -> V_23 = V_103 ;
V_100 -> V_84 = 0 ;
V_100 -> V_86 = 0 ;
V_81 = F_40 ( V_7 , V_12 ) ;
V_14 = F_8 ( V_12 , V_15 ) ;
F_6 ( V_7 ) ;
V_101 = F_53 ( V_7 -> V_75 , V_14 , V_81 , V_12 ) ;
F_5 ( V_7 ) ;
if ( V_101 )
F_12 ( V_12 ) ;
return true ;
}
return false ;
}
static void
F_54 ( struct V_6 * V_7 , struct V_16 * V_104 ,
T_2 V_105 )
{
struct V_60 * V_61 = V_7 -> V_75 -> V_106 [ ! V_105 ? 0 : V_105 + 1 ] ;
if ( F_38 ( ! V_61 ) )
return;
if ( ( V_61 -> V_107 & V_108 ) &&
V_104 -> V_70 <= V_109 )
F_55 ( V_61 ,
V_108 , false ) ;
if ( ! ( V_61 -> V_107 & V_108 ) &&
V_104 -> V_70 >= V_110 ) {
V_7 -> V_8 . V_111 ++ ;
F_55 ( V_61 , V_108 , true ) ;
}
return;
}
static int F_56 ( struct V_6 * V_7 , T_7 V_112 )
{
F_25 ( V_113 , L_14 , V_112 ) ;
return 0 ;
}
static
int F_57 ( struct V_6 * V_7 , T_2 type , T_2 * V_92 )
{
struct V_43 * V_58 , * V_114 ;
T_2 V_46 ;
T_2 V_14 ;
T_2 * V_48 ;
V_46 = * V_92 ++ ;
V_14 = * V_92 ++ ;
V_48 = V_92 ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( type == V_115 ) {
if ( V_58 -> V_50 ) {
F_25 ( V_49 , L_15 ,
V_58 -> V_5 , V_48 ) ;
F_5 ( V_7 ) ;
F_34 ( V_7 , V_58 , - 1 ) ;
F_26 ( V_58 ) ;
F_6 ( V_7 ) ;
} else
V_7 -> V_8 . V_116 ++ ;
return 0 ;
}
V_114 = F_27 ( V_7 , V_48 ) ;
if ( F_31 ( V_114 ) ) {
if ( ! V_58 -> V_50 ) {
F_5 ( V_7 ) ;
V_58 -> V_46 = V_46 ;
F_24 ( V_58 , V_48 , V_14 ) ;
F_21 ( V_7 , V_58 ) ;
F_58 ( & V_58 -> V_69 , V_117 ,
V_118 ) ;
F_6 ( V_7 ) ;
F_25 ( V_49 , L_16 , V_58 -> V_5 , V_48 ) ;
} else {
V_7 -> V_8 . V_116 ++ ;
}
} else {
if ( V_58 != V_114 ) {
F_25 ( V_49 , L_17 , V_114 -> V_5 ) ;
F_5 ( V_7 ) ;
memcpy ( V_58 , V_114 ,
F_59 ( struct V_43 , V_69 ) ) ;
V_58 -> V_46 = V_46 ;
F_26 ( V_114 ) ;
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
static int F_60 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_92 )
{
struct V_43 * V_58 ;
T_2 V_46 ;
int V_119 ;
V_46 = V_92 [ 0 ] ;
V_58 = & V_7 -> V_44 . V_59 [ V_46 & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
V_7 -> V_8 . V_120 ++ ;
return - V_121 ;
}
F_5 ( V_7 ) ;
V_58 -> V_52 = 0 ;
V_58 -> V_53 = 0 ;
if ( type == V_122 ) {
V_58 -> V_23 = V_51 ;
V_119 = V_123 ;
} else {
V_58 -> V_23 = V_57 ;
F_48 ( V_7 , V_58 , V_124 , false ) ;
F_48 ( V_7 , V_58 , V_125 , false ) ;
F_48 ( V_7 , V_58 , V_126 , false ) ;
F_48 ( V_7 , V_58 , V_127 , true ) ;
V_119 = V_128 ;
}
F_6 ( V_7 ) ;
return V_119 ;
}
static int F_61 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_92 )
{
struct V_43 * V_58 ;
T_2 V_14 ;
int V_119 ;
V_14 = V_92 [ 0 ] ;
if ( V_14 >= V_129 ) {
V_119 = - V_130 ;
goto V_131;
}
V_58 = & V_7 -> V_44 . V_68 [ V_14 ] ;
if ( ! V_58 -> V_50 ) {
V_119 = - V_121 ;
goto V_131;
}
F_25 ( V_49 , L_20 , F_1 ( type ) , type ,
V_58 -> V_5 ) ;
F_5 ( V_7 ) ;
switch ( type ) {
case V_132 :
V_58 -> V_23 = V_51 ;
V_119 = V_123 ;
break;
case V_133 :
V_58 -> V_23 = V_57 ;
V_119 = V_128 ;
break;
default:
V_119 = - V_10 ;
F_6 ( V_7 ) ;
goto V_131;
}
F_6 ( V_7 ) ;
return V_119 ;
V_131:
V_7 -> V_8 . V_134 ++ ;
return V_119 ;
}
static int F_62 ( struct V_6 * V_7 , T_2 type ,
T_2 * V_92 )
{
struct V_43 * V_58 ;
V_58 = & V_7 -> V_44 . V_59 [ V_92 [ 1 ] & 0x1F ] ;
if ( ! V_58 -> V_50 ) {
if ( type == V_135 )
V_7 -> V_8 . V_136 ++ ;
else
V_7 -> V_8 . V_137 ++ ;
return - V_121 ;
}
F_25 ( V_49 , L_21 ,
F_1 ( type ) , type , V_58 -> V_5 ,
V_92 [ 0 ] , V_92 [ 2 ] ) ;
F_5 ( V_7 ) ;
if ( type == V_135 )
V_58 -> V_52 = V_92 [ 0 ] ;
else
V_58 -> V_53 = V_92 [ 0 ] ;
V_58 -> V_54 = V_92 [ 2 ] ;
F_6 ( V_7 ) ;
return V_123 ;
}
static void
F_63 ( struct V_43 * V_58 ,
struct V_11 * V_12 )
{
if ( V_58 -> V_52 > 0 ) {
V_58 -> V_52 -- ;
F_64 ( V_12 , V_138 , 1 ) ;
F_64 ( V_12 , V_139 , 1 ) ;
if ( V_58 -> V_23 != V_57 )
F_15 ( L_22 ) ;
} else if ( V_58 -> V_53 > 0 ) {
V_58 -> V_53 -- ;
F_64 ( V_12 , V_138 , 1 ) ;
F_64 ( V_12 , V_139 , 0 ) ;
if ( V_58 -> V_23 != V_57 )
F_15 ( L_23 ) ;
} else {
F_64 ( V_12 , V_138 , 0 ) ;
F_64 ( V_12 , V_139 , 0 ) ;
}
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
if ( ( F_8 ( V_12 , V_139 ) ) &&
( V_58 -> V_23 == V_57 ) )
V_58 -> V_52 ++ ;
}
static void F_66 ( struct V_6 * V_7 ,
T_2 V_65 , T_2 V_140 )
{
int V_141 ;
int * V_142 ;
int * V_143 ;
if ( ! V_140 )
return;
V_7 -> V_144 |= 1 << V_65 ;
if ( ( V_65 == V_125 ) &&
( V_7 -> V_145 [ 0 ] ) ) {
for ( V_141 = V_127 ; V_141 >= 0 ;
V_141 -- ) {
V_142 = & V_7 -> V_145 [ V_141 ] ;
if ( * V_142 ) {
V_7 -> V_144 |= ( 1 << V_141 ) ;
V_143 = & V_7 -> V_143 [ V_141 ] ;
if ( * V_142 >= V_140 ) {
* V_142 -= V_140 ;
* V_143 += V_140 ;
return;
} else {
V_140 -= * V_142 ;
* V_143 += * V_142 ;
* V_142 = 0 ;
}
}
}
}
V_7 -> V_143 [ V_65 ] += V_140 ;
}
static void F_67 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_144 & V_7 -> V_146 ) ||
( ! F_68 ( V_7 ) && V_7 -> V_146 ) )
F_69 ( V_7 -> V_147 , & V_7 -> V_148 ) ;
}
static int F_70 ( struct V_6 * V_7 ,
enum V_149 V_23 , int V_65 ,
struct V_11 * V_150 )
{
int V_18 = 2 * V_65 ;
T_1 * V_151 = & V_7 -> V_8 . V_152 ;
struct V_43 * V_58 ;
struct V_16 * V_104 ;
struct V_153 * V_154 ;
struct V_11 * V_155 ;
struct V_11 * V_156 ;
T_1 V_157 ;
T_1 V_158 ;
V_58 = F_41 ( V_150 ) -> V_79 ;
if ( V_58 == NULL ) {
F_15 ( L_24 , V_150 ) ;
return - V_32 ;
}
F_25 ( V_159 , L_25 , V_65 , V_150 ) ;
if ( V_23 == V_160 ) {
V_18 += 1 ;
V_151 = & V_7 -> V_8 . V_161 ;
V_104 = & V_58 -> V_69 ;
if ( F_71 ( V_104 ) || F_72 ( V_104 , V_18 ) ) {
* V_151 += 1 ;
return - V_162 ;
}
V_154 = & V_104 -> V_17 [ V_18 ] . V_163 ;
V_155 = F_73 ( V_154 ) ;
V_156 = F_74 ( V_154 ) ;
V_157 = F_37 ( V_150 , V_164 ) ;
while ( V_155 != V_156 ) {
V_158 = F_37 ( V_156 ,
V_164 ) ;
if ( ( ( V_157 > V_158 ) &&
( ( V_157 - V_158 ) < 128 ) ) ||
( ( V_157 < V_158 ) &&
( ( V_158 - V_157 ) > 128 ) ) )
break;
V_156 = F_75 ( V_154 , V_156 ) ;
}
if ( V_156 == NULL ) {
F_76 ( V_154 , V_150 ) ;
} else {
V_158 = F_37 ( V_156 ,
V_164 ) ;
if ( ( ( V_157 > V_158 ) &&
( ( V_157 - V_158 ) < 128 ) ) ||
( ( V_157 < V_158 ) &&
( ( V_158 - V_157 ) > 128 ) ) ) {
F_77 ( V_154 , V_156 , V_150 ) ;
} else {
F_78 ( V_150 , V_156 -> V_165 , V_156 , V_154 ) ;
}
}
V_104 -> V_70 ++ ;
if ( V_104 -> V_166 < V_18 )
V_104 -> V_166 = ( T_2 ) V_18 ;
} else if ( F_79 ( & V_58 -> V_69 , V_18 , V_150 ) == NULL ) {
* V_151 += 1 ;
return - V_162 ;
}
V_7 -> V_146 |= 1 << V_65 ;
V_7 -> V_167 [ V_65 ] ++ ;
F_41 ( V_150 ) -> V_23 = V_23 ;
F_48 ( V_7 , V_58 , V_65 , true ) ;
F_54 ( V_7 , & V_58 -> V_69 ,
F_8 ( V_150 , V_15 ) ) ;
return 0 ;
}
static struct V_11 * F_80 ( struct V_6 * V_7 , int V_65 )
{
struct V_43 * V_78 ;
struct V_43 * V_58 ;
struct V_11 * V_150 ;
int V_168 ;
int V_169 ;
int V_170 ;
int V_171 ;
int V_3 ;
V_78 = (struct V_43 * ) & V_7 -> V_44 ;
V_168 = sizeof( V_7 -> V_44 ) / sizeof( struct V_43 ) ;
V_169 = V_7 -> V_172 [ V_65 ] ;
for ( V_3 = 0 ; V_3 < V_168 ; V_3 ++ ) {
V_58 = & V_78 [ ( V_169 + V_3 ) % V_168 ] ;
if ( ! V_58 -> V_50 ||
F_32 ( V_7 , V_58 , V_65 ) )
continue;
if ( V_58 -> V_173 )
V_171 = 2 ;
else
V_171 = 3 ;
V_150 = F_81 ( & V_58 -> V_69 , V_171 << ( V_65 * 2 ) , & V_170 ) ;
if ( V_150 == NULL ) {
if ( V_58 -> V_173 ) {
if ( V_58 -> V_174 )
continue;
V_58 -> V_173 = false ;
V_150 = F_81 ( & V_58 -> V_69 ,
1 << ( V_65 * 2 ) , & V_170 ) ;
}
}
if ( V_150 == NULL )
continue;
F_63 ( V_58 , V_150 ) ;
V_7 -> V_172 [ V_65 ] = ( V_169 + V_3 + 1 ) % V_168 ;
F_54 ( V_7 , & V_58 -> V_69 ,
F_8 ( V_150 ,
V_15 )
) ;
F_48 ( V_7 , V_58 , V_65 , false ) ;
V_7 -> V_167 [ V_65 ] -- ;
if ( V_7 -> V_167 [ V_65 ] == 0 )
V_7 -> V_146 &= ~ ( 1 << V_65 ) ;
goto V_28;
}
V_150 = NULL ;
V_28:
F_25 ( V_159 , L_26 , V_65 , V_150 ) ;
return V_150 ;
}
static int F_82 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 , T_2 V_14 ,
T_1 V_175 , T_3 V_176 )
{
struct V_43 * V_58 = F_41 ( V_12 ) -> V_79 ;
T_1 V_74 ;
int V_119 ;
V_74 = F_37 ( V_12 , V_77 ) ;
if ( ! V_58 -> V_173 ) {
V_58 -> V_173 = true ;
V_58 -> V_174 = V_58 -> V_177 ;
F_25 ( V_159 , L_27 ,
V_58 -> V_5 , V_58 -> V_177 ) ;
}
V_58 -> V_178 = V_175 ;
F_83 ( V_12 , V_179 , V_175 ) ;
F_41 ( V_12 ) -> V_86 = V_176 ;
if ( F_84 ( V_12 , V_180 ) ) {
F_85 ( V_12 , V_181 , 1 ) ;
F_85 ( V_12 , V_180 , 0 ) ;
} else {
F_85 ( V_12 , V_181 , 0 ) ;
}
V_119 = F_70 ( V_7 , V_160 , V_65 , V_12 ) ;
if ( V_119 != 0 ) {
F_17 ( & V_7 -> V_21 , V_74 , & V_12 , true ) ;
} else {
F_18 ( & V_7 -> V_21 , V_74 ) ;
}
return V_119 ;
}
static int
F_86 ( struct V_6 * V_7 , T_2 V_182 , T_1 V_74 ,
T_1 V_175 , T_3 V_176 )
{
T_1 V_65 ;
int V_119 ;
bool V_183 = true ;
struct V_11 * V_12 ;
struct V_99 * V_100 ;
struct V_43 * V_58 = NULL ;
T_2 V_14 ;
F_25 ( V_159 , L_28 , V_182 ) ;
if ( V_182 == V_184 )
V_7 -> V_8 . V_185 ++ ;
else if ( V_182 == V_186 ) {
V_7 -> V_8 . V_187 ++ ;
V_183 = false ;
} else if ( V_182 == V_188 ) {
V_7 -> V_8 . V_189 ++ ;
V_183 = false ;
} else if ( V_182 == V_190 )
V_7 -> V_8 . V_191 ++ ;
else if ( V_182 == V_192 )
V_7 -> V_8 . V_193 ++ ;
else
F_15 ( L_29 ) ;
V_119 = F_17 ( & V_7 -> V_21 , V_74 , & V_12 ,
V_183 ) ;
if ( V_119 != 0 ) {
F_15 ( L_30 , V_74 ) ;
return V_119 ;
}
V_100 = F_41 ( V_12 ) ;
V_58 = V_100 -> V_79 ;
if ( F_38 ( ! V_58 ) ) {
F_12 ( V_12 ) ;
return - V_10 ;
}
V_58 -> V_177 -- ;
if ( V_58 -> V_173 && V_58 -> V_174 )
V_58 -> V_174 -- ;
F_25 ( V_159 , L_31 , V_58 -> V_5 , V_182 ,
V_100 -> V_84 , V_176 ) ;
V_65 = F_37 ( V_12 , V_194 ) ;
if ( ( V_7 -> V_195 == V_196 ) ||
( F_8 ( V_12 , V_139 ) ) ||
( V_182 == V_192 ) ) {
F_66 ( V_7 , V_65 , 1 ) ;
F_67 ( V_7 ) ;
}
F_65 ( V_12 ) ;
if ( F_87 ( V_7 -> V_75 , false , & V_14 , V_12 ) ) {
F_12 ( V_12 ) ;
return - V_10 ;
}
if ( ! V_183 )
V_119 = F_82 ( V_7 , V_65 , V_12 , V_14 ,
V_175 , V_176 ) ;
if ( V_183 || V_119 )
F_88 ( V_7 -> V_75 , V_12 , V_14 , true ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 ,
T_2 * V_92 )
{
int V_3 ;
if ( V_7 -> V_195 != V_197 ) {
F_25 ( V_198 , L_32 ) ;
return V_128 ;
}
F_25 ( V_159 , L_33 , V_92 ) ;
F_5 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < V_199 ; V_3 ++ )
F_66 ( V_7 , V_3 , V_92 [ V_3 ] ) ;
F_25 ( V_159 , L_34 , V_7 -> V_144 ,
V_7 -> V_146 ) ;
F_6 ( V_7 ) ;
return V_123 ;
}
static int F_90 ( struct V_6 * V_7 , T_2 * V_92 )
{
T_4 V_200 ;
T_5 V_201 ;
T_1 V_202 ;
T_1 V_74 ;
T_1 V_175 ;
T_2 V_182 ;
T_3 V_176 ;
V_7 -> V_8 . V_203 ++ ;
memcpy ( & V_200 , V_92 , sizeof( V_200 ) ) ;
V_202 = F_44 ( V_200 ) ;
V_182 = F_91 ( V_202 , V_204 ) ;
V_74 = F_91 ( V_202 , V_77 ) ;
V_175 = F_91 ( V_202 , V_179 ) ;
if ( F_45 ( V_7 -> V_89 ) ) {
memcpy ( & V_201 , & V_92 [ V_91 ] ,
sizeof( V_201 ) ) ;
V_176 = F_92 ( V_201 ) ;
} else {
V_176 = 0 ;
}
F_5 ( V_7 ) ;
F_86 ( V_7 , V_182 , V_74 , V_175 , V_176 ) ;
F_6 ( V_7 ) ;
return V_128 ;
}
static int F_93 ( struct V_6 * V_7 , T_2 * V_92 )
{
T_4 V_205 ;
memcpy ( & V_205 , & V_92 [ 2 ] , sizeof( V_205 ) ) ;
F_25 ( V_113 , L_35 , V_92 [ 1 ] ,
F_44 ( V_205 ) ) ;
return 0 ;
}
static int F_94 ( struct V_60 * V_61 ,
const struct V_206 * V_207 ,
void * V_92 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
int V_3 ;
T_2 * V_140 = V_92 ;
if ( V_207 -> V_208 < V_199 ) {
F_15 ( L_36 , V_207 -> V_208 ) ;
return - V_10 ;
}
if ( V_7 -> V_209 )
return 0 ;
V_7 -> V_209 = true ;
F_25 ( V_49 , L_37 , V_140 ) ;
F_5 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_143 ) ; V_3 ++ ) {
if ( * V_140 )
V_7 -> V_144 |= 1 << V_3 ;
else
V_7 -> V_144 &= ~ ( 1 << V_3 ) ;
V_7 -> V_143 [ V_3 ] = * V_140 ++ ;
}
F_67 ( V_7 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_95 ( struct V_60 * V_61 ,
const struct V_206 * V_207 ,
void * V_92 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
F_5 ( V_7 ) ;
if ( V_7 )
V_7 -> V_210 = true ;
F_6 ( V_7 ) ;
return 0 ;
}
int F_96 ( struct V_211 * V_75 , int V_14 , T_8 V_212 ,
struct V_11 * V_12 )
{
struct V_213 * V_214 ;
struct V_6 * V_7 = V_75 -> V_7 ;
T_2 * V_215 ;
T_8 V_216 ;
T_2 type ;
T_2 V_70 ;
T_2 * V_92 ;
T_6 V_202 ;
T_6 V_101 ;
F_25 ( V_217 , L_38 ,
V_14 , V_12 -> V_70 , V_212 ) ;
F_38 ( V_212 > V_12 -> V_70 ) ;
if ( ! V_212 )
return 0 ;
if ( ( ! V_7 ) || ( ! V_7 -> V_218 ) ) {
F_52 ( V_12 , V_212 ) ;
return 0 ;
}
V_7 -> V_8 . V_219 ++ ;
V_216 = V_212 ;
V_215 = V_12 -> V_92 ;
V_202 = V_128 ;
while ( V_216 > 0 ) {
type = V_215 [ 0 ] ;
if ( type == V_97 ) {
V_215 += 1 ;
V_216 -= 1 ;
continue;
}
V_70 = V_215 [ 1 ] ;
V_92 = V_215 + 2 ;
F_25 ( V_217 , L_39 ,
F_1 ( type ) , type , V_70 ,
F_3 ( V_7 , type ) ) ;
if ( V_216 < V_70 + 2 )
break;
if ( V_70 < F_3 ( V_7 , type ) )
break;
V_101 = V_128 ;
switch ( type ) {
case V_220 :
break;
case V_221 :
V_214 = (struct V_213 * ) V_12 -> V_222 ;
V_214 -> V_223 = V_92 ;
break;
case V_224 :
case V_115 :
F_57 ( V_7 , type , V_92 ) ;
break;
case V_122 :
case V_225 :
V_101 = F_60 ( V_7 , type , V_92 ) ;
break;
case V_132 :
case V_133 :
V_101 = F_61 ( V_7 , type ,
V_92 ) ;
break;
case V_135 :
case V_226 :
V_101 = F_62 ( V_7 , type , V_92 ) ;
break;
case V_227 :
F_90 ( V_7 , V_92 ) ;
break;
case V_228 :
V_101 = F_89 ( V_7 , V_92 ) ;
break;
case V_229 :
F_56 ( V_7 , * V_92 ) ;
break;
case V_230 :
F_93 ( V_7 , V_92 ) ;
break;
case V_93 :
case V_94 :
default:
V_7 -> V_8 . V_9 ++ ;
break;
}
if ( V_101 == V_123 )
V_202 = V_123 ;
V_215 += V_70 + 2 ;
V_216 -= V_70 + 2 ;
}
if ( V_216 != 0 )
V_7 -> V_8 . V_231 ++ ;
if ( V_202 == V_123 )
F_67 ( V_7 ) ;
F_52 ( V_12 , V_212 ) ;
if ( V_12 -> V_70 == 0 )
V_7 -> V_8 . V_232 ++ ;
return 0 ;
}
static T_2 F_97 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_150 )
{
struct V_99 * V_100 = F_41 ( V_150 ) ;
struct V_43 * V_58 = V_100 -> V_79 ;
T_2 V_182 ;
if ( V_100 -> V_23 != V_160 )
F_83 ( V_150 , V_179 , V_58 -> V_178 ) ;
V_182 = V_233 ;
if ( F_8 ( V_150 , V_138 ) ) {
V_182 |= V_234 ;
}
F_83 ( V_150 , V_204 , V_182 ) ;
return F_40 ( V_7 , V_150 ) ;
}
static void F_98 ( struct V_6 * V_7 ,
struct V_11 * V_12 , int V_65 )
{
struct V_43 * V_58 ;
struct V_11 * V_36 ;
int V_235 , V_74 ;
int V_236 = 0 ;
V_58 = F_41 ( V_12 ) -> V_79 ;
if ( V_58 -> V_50 ) {
V_235 = 2 * V_65 ;
if ( F_41 ( V_12 ) -> V_23 == V_160 )
V_235 ++ ;
V_36 = F_99 ( & V_58 -> V_69 , V_235 , V_12 ) ;
if ( V_36 == NULL ) {
F_15 ( L_40 , V_58 -> V_5 , V_235 ) ;
V_236 = - V_237 ;
}
} else {
F_15 ( L_41 , V_58 -> V_5 ) ;
V_236 = - V_32 ;
}
if ( V_236 ) {
V_7 -> V_8 . V_238 ++ ;
V_74 = F_37 ( V_12 , V_77 ) ;
F_86 ( V_7 , V_192 ,
V_74 , 0 , 0 ) ;
} else {
V_7 -> V_8 . V_239 ++ ;
F_66 ( V_7 , V_65 , 1 ) ;
F_65 ( V_12 ) ;
}
}
static int F_100 ( struct V_6 * V_7 )
{
int V_141 ;
if ( F_101 ( V_7 -> V_240 , V_241 ) ) {
V_7 -> V_144 &= ~ ( 1 << V_125 ) ;
return - V_242 ;
}
for ( V_141 = 0 ; V_141 <= V_127 ; V_141 ++ ) {
if ( V_7 -> V_143 [ V_141 ] ) {
V_7 -> V_145 [ V_141 ] ++ ;
V_7 -> V_143 [ V_141 ] -- ;
if ( V_7 -> V_143 [ V_141 ] == 0 )
V_7 -> V_144 &= ~ ( 1 << V_141 ) ;
V_7 -> V_144 |= ( 1 << V_125 ) ;
F_25 ( V_159 , L_42 , V_141 ) ;
return 0 ;
}
}
V_7 -> V_144 &= ~ ( 1 << V_125 ) ;
return - V_242 ;
}
static int F_102 ( struct V_6 * V_7 , int V_65 ,
struct V_11 * V_12 )
{
struct V_99 * V_100 = F_41 ( V_12 ) ;
struct V_43 * V_58 ;
int V_236 ;
T_2 V_14 ;
T_2 V_81 ;
V_58 = V_100 -> V_79 ;
if ( F_31 ( V_58 ) )
return F_103 ( V_58 ) ;
V_81 = F_97 ( V_7 , V_65 , V_12 ) ;
V_58 -> V_177 ++ ;
if ( V_58 -> V_173 )
V_58 -> V_174 ++ ;
V_14 = F_8 ( V_12 , V_15 ) ;
F_6 ( V_7 ) ;
V_236 = F_53 ( V_7 -> V_75 , V_14 , V_81 , V_12 ) ;
F_5 ( V_7 ) ;
F_25 ( V_159 , L_43 , V_58 -> V_5 ,
V_100 -> V_243 , V_100 -> V_84 , V_236 ) ;
if ( V_236 < 0 ) {
V_58 -> V_177 -- ;
if ( V_58 -> V_173 )
V_58 -> V_174 -- ;
F_87 ( V_7 -> V_75 , false , & V_14 , V_12 ) ;
goto V_244;
}
V_7 -> V_8 . V_245 ++ ;
V_7 -> V_8 . V_246 [ V_65 ] ++ ;
if ( F_8 ( V_12 , V_138 ) )
V_7 -> V_8 . V_247 [ V_65 ] ++ ;
return V_236 ;
V_244:
F_98 ( V_7 , V_12 , V_65 ) ;
return V_236 ;
}
static int F_104 ( struct V_6 * V_7 , struct V_11 * V_150 ,
int V_65 )
{
struct V_99 * V_100 = F_41 ( V_150 ) ;
int V_236 , V_74 ;
V_100 -> V_84 = 0 ;
V_100 -> V_86 = 0 ;
V_74 = F_14 ( & V_7 -> V_21 ) ;
F_83 ( V_150 , V_77 , V_74 ) ;
F_83 ( V_150 , V_164 , V_100 -> V_79 -> V_176 [ V_65 ] ) ;
F_83 ( V_150 , V_194 , V_65 ) ;
V_236 = F_16 ( & V_7 -> V_21 , V_150 , V_74 ) ;
if ( ! V_236 )
V_100 -> V_79 -> V_176 [ V_65 ] ++ ;
else
V_7 -> V_8 . V_248 ++ ;
return V_236 ;
}
int F_105 ( struct V_60 * V_61 , struct V_11 * V_12 )
{
struct V_211 * V_75 = V_61 -> V_75 ;
struct V_6 * V_7 = V_75 -> V_7 ;
struct V_99 * V_100 = F_41 ( V_12 ) ;
struct V_249 * V_250 = (struct V_249 * ) ( V_12 -> V_92 ) ;
int V_65 = V_251 ;
bool V_63 = F_30 ( V_250 -> V_252 ) ;
int V_236 = 0 ;
F_25 ( V_159 , L_44 , F_106 ( V_250 -> V_253 ) ) ;
if ( ! V_12 -> V_254 )
V_12 -> V_254 = F_107 ( V_12 , NULL ) ;
V_75 -> V_255 += ! ! V_63 ;
if ( V_7 -> V_256 ) {
V_236 = F_53 ( V_75 , V_61 -> V_14 , 0 , V_12 ) ;
if ( V_236 < 0 )
F_88 ( V_75 , V_12 , V_61 -> V_14 , false ) ;
return V_236 ;
}
V_100 -> V_243 = 0 ;
V_100 -> V_23 = V_257 ;
F_64 ( V_12 , V_15 , V_61 -> V_14 ) ;
if ( ! V_63 )
V_65 = V_258 [ V_12 -> V_254 ] ;
F_5 ( V_7 ) ;
if ( V_65 != V_125 && V_65 < V_251 )
V_7 -> V_240 = V_241 +
V_259 ;
V_100 -> V_79 = F_29 ( V_7 , V_61 , V_250 -> V_252 ) ;
F_25 ( V_159 , L_45 , V_100 -> V_79 -> V_5 ,
V_250 -> V_252 , V_63 , V_65 ) ;
if ( ! F_104 ( V_7 , V_12 , V_65 ) ) {
F_70 ( V_7 , V_260 , V_65 , V_12 ) ;
F_67 ( V_7 ) ;
} else {
F_15 ( L_46 ) ;
F_88 ( V_75 , V_12 , V_61 -> V_14 , false ) ;
V_236 = - V_261 ;
}
F_6 ( V_7 ) ;
return V_236 ;
}
void F_108 ( struct V_60 * V_61 )
{
struct V_43 * V_58 = V_61 -> V_64 ;
F_25 ( V_49 , L_47 , V_61 -> V_262 ) ;
if ( ! V_58 )
return;
F_24 ( V_58 , V_61 -> V_263 , V_61 -> V_14 ) ;
}
void F_109 ( struct V_60 * V_61 )
{
struct V_6 * V_7 = V_61 -> V_75 -> V_7 ;
struct V_43 * V_58 ;
if ( ! V_61 -> V_264 )
return;
V_58 = & V_7 -> V_44 . V_68 [ V_61 -> V_14 ] ;
V_61 -> V_64 = V_58 ;
F_24 ( V_58 , V_61 -> V_263 , V_61 -> V_14 ) ;
F_21 ( V_7 , V_58 ) ;
F_58 ( & V_58 -> V_69 , V_117 ,
V_118 ) ;
F_25 ( V_49 , L_48 , V_58 -> V_5 ) ;
}
void F_110 ( struct V_60 * V_61 )
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
static void F_111 ( struct V_265 * V_266 )
{
struct V_6 * V_7 ;
struct V_211 * V_75 ;
struct V_11 * V_12 ;
int V_65 ;
T_1 V_74 ;
T_1 V_14 ;
int V_119 ;
V_7 = F_112 ( V_266 , struct V_6 , V_148 ) ;
V_75 = V_7 -> V_75 ;
F_5 ( V_7 ) ;
for ( V_65 = V_251 ; V_65 >= 0 && ! V_7 -> V_267 ;
V_65 -- ) {
if ( ! F_68 ( V_7 ) ) {
while ( ( V_12 = F_80 ( V_7 , V_65 ) ) != NULL ) {
V_74 = F_37 ( V_12 ,
V_77 ) ;
F_17 ( & V_7 -> V_21 , V_74 ,
& V_12 , true ) ;
V_14 = F_8 ( V_12 ,
V_15 ) ;
F_6 ( V_7 ) ;
V_119 = F_53 ( V_75 , V_14 , 0 , V_12 ) ;
F_5 ( V_7 ) ;
if ( V_119 < 0 )
F_88 ( V_75 , V_12 , V_14 ,
false ) ;
if ( V_7 -> V_267 )
break;
}
continue;
}
while ( ( V_7 -> V_143 [ V_65 ] ) || ( ( ! V_7 -> V_210 ) &&
( V_65 == V_251 ) ) ) {
V_12 = F_80 ( V_7 , V_65 ) ;
if ( ! V_12 )
break;
V_7 -> V_143 [ V_65 ] -- ;
if ( F_102 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_267 )
break;
}
if ( ( V_65 == V_125 ) &&
( V_7 -> V_143 [ V_65 ] == 0 ) &&
( ! V_7 -> V_267 ) ) {
while ( F_100 ( V_7 ) == 0 ) {
V_12 = F_80 ( V_7 , V_65 ) ;
if ( ! V_12 ) {
F_66 ( V_7 , V_65 , 1 ) ;
break;
}
if ( F_102 ( V_7 , V_65 , V_12 ) )
break;
if ( V_7 -> V_267 )
break;
}
}
}
F_6 ( V_7 ) ;
}
static int F_113 ( struct V_268 * V_176 , void * V_92 )
{
struct V_269 * V_76 = F_114 ( V_176 -> V_270 ) ;
struct V_271 * V_272 = & V_76 -> V_75 -> V_7 -> V_8 ;
F_115 ( V_176 ,
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72 ,
V_272 -> V_219 ,
V_272 -> V_232 ,
V_272 -> V_231 ,
V_272 -> V_9 ,
V_272 -> V_116 ,
V_272 -> V_120 ,
V_272 -> V_134 ,
V_272 -> V_245 ,
V_272 -> V_248 ,
V_272 -> V_239 ,
V_272 -> V_238 ,
V_272 -> V_152 ,
V_272 -> V_161 ,
V_272 -> V_203 ,
V_272 -> V_185 ,
V_272 -> V_187 ,
V_272 -> V_189 ,
V_272 -> V_191 ,
V_272 -> V_193 ,
V_272 -> V_273 ,
V_272 -> V_111 ,
V_272 -> V_246 [ 0 ] , V_272 -> V_246 [ 1 ] ,
V_272 -> V_246 [ 2 ] , V_272 -> V_246 [ 3 ] ,
V_272 -> V_246 [ 4 ] ,
V_272 -> V_247 [ 0 ] ,
V_272 -> V_247 [ 1 ] ,
V_272 -> V_247 [ 2 ] ,
V_272 -> V_247 [ 3 ] ,
V_272 -> V_247 [ 4 ] ) ;
return 0 ;
}
static int F_113 ( struct V_268 * V_176 , void * V_92 )
{
return 0 ;
}
int F_116 ( struct V_211 * V_75 )
{
struct V_6 * V_7 ;
T_1 V_274 = V_275 ;
int V_236 ;
T_1 V_89 ;
V_75 -> V_7 = F_117 ( sizeof( * ( V_75 -> V_7 ) ) , V_276 ) ;
if ( ! V_75 -> V_7 ) {
V_236 = - V_261 ;
goto V_131;
}
V_7 = V_75 -> V_7 ;
F_118 ( & V_7 -> V_277 ) ;
V_7 -> V_75 = V_75 ;
V_7 -> V_195 = V_195 ;
if ( ( V_75 -> V_76 -> V_278 == false ) &&
( V_195 == V_279 ) ) {
V_7 -> V_256 = true ;
F_25 ( V_198 , L_73 ) ;
return 0 ;
}
V_7 -> V_147 = F_119 ( L_74 ) ;
if ( V_7 -> V_147 == NULL ) {
F_15 ( L_75 ) ;
V_236 = - V_280 ;
goto V_131;
}
F_120 ( & V_7 -> V_148 , F_111 ) ;
if ( V_7 -> V_195 != V_279 )
V_274 |= V_281 |
V_282 |
V_283 |
V_284 ;
V_236 = F_121 ( V_75 , V_285 ,
F_94 ) ;
if ( V_236 < 0 ) {
F_15 ( L_76 ) ;
goto V_131;
}
V_236 = F_121 ( V_75 , V_286 ,
F_95 ) ;
if ( V_236 < 0 ) {
F_15 ( L_77 ) ;
F_122 ( V_75 , V_285 ) ;
goto V_131;
}
V_7 -> V_218 = true ;
if ( F_123 ( V_75 -> V_106 [ 0 ] , L_78 , V_274 ) ) {
F_15 ( L_79 ) ;
V_7 -> V_195 = V_279 ;
V_7 -> V_218 = false ;
}
if ( F_123 ( V_75 -> V_106 [ 0 ] , L_80 , 1 ) )
F_25 ( V_198 , L_81 ) ;
if ( F_124 ( V_75 -> V_106 [ 0 ] , L_82 , & V_89 ) == 0 ) {
if ( F_45 ( V_89 ) ) {
V_89 = 0 ;
F_125 ( V_89 , 1 ) ;
if ( F_123 ( V_75 -> V_106 [ 0 ] ,
L_82 , V_89 ) == 0 ) {
F_125 ( V_7 -> V_89 , 1 ) ;
}
}
}
F_13 ( & V_7 -> V_21 ) ;
F_24 ( & V_7 -> V_44 . V_45 , NULL , 0 ) ;
F_21 ( V_7 , & V_7 -> V_44 . V_45 ) ;
F_58 ( & V_7 -> V_44 . V_45 . V_69 , V_117 ,
V_118 ) ;
F_126 ( V_75 , L_83 ,
F_113 ) ;
F_25 ( V_198 , L_84 ,
V_7 -> V_218 ? L_85 : L_86 , V_274 ) ;
return 0 ;
V_131:
F_127 ( V_75 ) ;
return V_236 ;
}
void F_127 ( struct V_211 * V_75 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
if ( ! V_7 )
return;
if ( V_75 -> V_7 -> V_147 )
F_128 ( V_75 -> V_7 -> V_147 ) ;
F_5 ( V_7 ) ;
F_39 ( V_7 , - 1 ) ;
V_75 -> V_7 = NULL ;
F_6 ( V_7 ) ;
F_129 ( V_7 ) ;
}
bool F_68 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_209 )
return false ;
return V_7 -> V_195 != V_279 ;
}
void F_130 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
T_1 V_74 ;
if ( F_41 ( V_12 ) -> V_23 == V_103 ) {
F_12 ( V_12 ) ;
return;
}
F_5 ( V_7 ) ;
V_74 = F_37 ( V_12 , V_77 ) ;
F_86 ( V_7 , V_192 , V_74 , 0 , 0 ) ;
F_6 ( V_7 ) ;
}
void F_131 ( struct V_211 * V_75 , bool V_287 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
V_7 -> V_267 = V_287 ;
if ( ! V_287 )
F_67 ( V_7 ) ;
else
V_7 -> V_8 . V_273 ++ ;
}
