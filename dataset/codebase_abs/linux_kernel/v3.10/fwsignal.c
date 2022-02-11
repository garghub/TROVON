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
F_12 ( V_22 , L_3 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_21 -> V_23 ) ; V_3 ++ )
V_21 -> V_23 [ V_3 ] . V_24 = V_25 ;
}
static T_1 F_13 ( struct V_20 * V_26 )
{
T_1 V_3 ;
F_12 ( V_22 , L_3 ) ;
V_3 = ( V_26 -> V_27 + 1 ) % V_28 ;
while ( V_3 != V_26 -> V_27 ) {
if ( V_26 -> V_23 [ V_3 ] . V_24 == V_25 ) {
V_26 -> V_27 = V_3 ;
goto V_29;
}
V_3 ++ ;
if ( V_3 == V_28 )
V_3 = 0 ;
}
F_14 ( L_4 ) ;
V_26 -> V_30 ++ ;
V_3 = V_28 ;
V_29:
F_12 ( V_22 , L_5 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_20 * V_26 ,
struct V_11 * V_31 , T_1 V_32 )
{
F_12 ( V_22 , L_3 ) ;
if ( V_32 >= V_28 )
return - V_33 ;
if ( V_26 -> V_23 [ V_32 ] . V_24 != V_25 ) {
F_14 ( L_6 ) ;
V_26 -> V_34 ++ ;
return - V_10 ;
}
V_26 -> V_23 [ V_32 ] . V_24 = V_35 ;
V_26 -> V_23 [ V_32 ] . V_31 = V_31 ;
V_26 -> V_36 ++ ;
return 0 ;
}
static int F_16 ( struct V_20 * V_26 ,
T_1 V_32 , struct V_11 * * V_37 ,
bool V_38 )
{
F_12 ( V_22 , L_3 ) ;
if ( V_32 >= V_28 )
return - V_33 ;
if ( V_26 -> V_23 [ V_32 ] . V_24 == V_25 ) {
F_14 ( L_7 ) ;
V_26 -> V_39 ++ ;
return - V_10 ;
}
* V_37 = V_26 -> V_23 [ V_32 ] . V_31 ;
if ( V_38 ) {
V_26 -> V_23 [ V_32 ] . V_24 = V_25 ;
V_26 -> V_23 [ V_32 ] . V_31 = NULL ;
V_26 -> V_23 [ V_32 ] . V_40 = 0xff ;
V_26 -> V_41 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_20 * V_26 ,
T_1 V_32 , T_2 V_40 )
{
F_12 ( V_22 , L_3 ) ;
if ( V_32 >= V_28 )
return - V_33 ;
V_26 -> V_23 [ V_32 ] . V_40 = V_40 ;
if ( V_26 -> V_23 [ V_32 ] . V_24 != V_35 ) {
F_14 ( L_7 ) ;
return - V_10 ;
}
V_26 -> V_23 [ V_32 ] . V_24 = V_42 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_11 * V_31 , T_1 V_32 ,
int * V_40 )
{
F_12 ( V_22 , L_3 ) ;
* V_40 = 0xff ;
if ( V_32 >= V_28 )
return - V_33 ;
if ( V_21 -> V_23 [ V_32 ] . V_24 == V_25 ) {
F_14 ( L_8 ) ;
return - V_10 ;
}
* V_40 = V_21 -> V_23 [ V_32 ] . V_40 ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
bool (* F_20)( struct V_11 * , void * ) ,
int V_14 )
{
struct V_20 * V_26 = & V_7 -> V_21 ;
struct V_11 * V_12 ;
int V_3 ;
enum V_43 V_44 ;
F_12 ( V_22 , L_9 , V_14 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_26 -> V_23 ) ; V_3 ++ ) {
V_44 = V_26 -> V_23 [ V_3 ] . V_24 ;
if ( V_44 == V_35 ||
V_44 == V_42 ) {
V_12 = V_26 -> V_23 [ V_3 ] . V_31 ;
if ( F_20 == NULL || F_20 ( V_12 , & V_14 ) ) {
if ( V_44 == V_35 )
F_10 ( V_12 ) ;
V_26 -> V_23 [ V_3 ] . V_24 =
V_25 ;
}
}
}
}
static void F_21 ( struct V_45 * V_46 ,
T_2 * V_47 , T_2 V_14 )
{
F_12 ( V_22 ,
L_10 , V_46 , V_47 , V_14 ) ;
V_46 -> V_48 = 1 ;
V_46 -> V_24 = V_49 ;
V_46 -> V_50 = 0 ;
V_46 -> V_51 = V_14 ;
V_46 -> V_52 = 0xff ;
if ( V_47 )
memcpy ( & V_46 -> V_53 [ 0 ] , V_47 , V_54 ) ;
}
static
void F_22 ( struct V_45 * V_46 )
{
F_12 ( V_22 ,
L_11 , V_46 -> V_53 , V_46 -> V_51 ) ;
V_46 -> V_48 = 0 ;
V_46 -> V_24 = V_55 ;
V_46 -> V_50 = 0 ;
}
static struct V_45 *
F_23 ( struct V_6 * V_7 , T_2 * V_53 )
{
struct V_45 * V_56 ;
int V_3 ;
F_12 ( V_22 , L_12 , V_53 ) ;
if ( V_53 == NULL )
return F_24 ( - V_10 ) ;
V_56 = & V_7 -> V_46 . V_57 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_46 . V_57 ) ; V_3 ++ ) {
if ( V_56 -> V_48 && ! memcmp ( V_56 -> V_53 , V_53 , V_54 ) )
return V_56 ;
V_56 ++ ;
}
return F_24 ( - V_33 ) ;
}
static struct V_45 *
F_25 ( struct V_6 * V_7 , struct V_58 * V_59 ,
T_2 * V_60 )
{
struct V_45 * V_56 = & V_7 -> V_46 . V_61 ;
bool V_62 ;
enum V_63 V_64 ;
F_12 ( V_22 , L_13 , V_59 -> V_65 ) ;
V_62 = F_26 ( V_60 ) ;
V_64 = F_27 ( V_59 ) ;
V_56 = NULL ;
if ( ( V_62 || V_64 == V_66 ||
V_64 == V_67 ) && V_59 -> V_68 )
V_56 = V_59 -> V_68 ;
if ( V_56 != NULL && V_64 != V_66 )
goto V_29;
V_56 = F_23 ( V_7 , V_60 ) ;
if ( F_28 ( V_56 ) )
V_56 = & V_7 -> V_46 . V_61 ;
V_29:
F_12 ( V_22 , L_14 , V_56 ) ;
return V_56 ;
}
static bool F_29 ( struct V_6 * V_7 ,
struct V_45 * V_56 ,
int V_69 )
{
struct V_45 * V_70 ;
bool V_71 ;
if ( V_56 -> V_72 ) {
V_70 = & V_7 -> V_46 . V_73 [ V_56 -> V_51 ] ;
if ( V_70 -> V_24 == V_55 )
return true ;
}
V_71 = V_56 -> V_24 == V_55 &&
! V_56 -> V_50 && ! V_56 -> V_74 ;
return V_71 || ! ( V_56 -> V_52 & F_30 ( V_69 ) ) ;
}
static void F_31 ( struct V_6 * V_7 ,
struct V_45 * V_56 ,
int V_14 )
{
F_12 ( V_22 , L_15 ,
V_56 -> V_53 , V_56 -> V_51 , V_14 ) ;
if ( V_56 -> V_48 && ( V_14 == - 1 || V_14 == V_56 -> V_51 ) ) {
F_12 ( V_22 , L_16 ,
V_14 , V_56 -> V_75 . V_76 ) ;
F_7 ( V_7 , & V_56 -> V_75 , V_14 ) ;
V_56 -> V_48 = ! ! ( V_56 -> V_75 . V_76 ) ;
}
}
static void F_32 ( struct V_6 * V_7 ,
bool (* F_20)( struct V_11 * , void * ) ,
int V_14 )
{
struct V_77 * V_78 ;
struct V_16 * V_79 ;
struct V_11 * V_12 ;
int V_18 ;
T_1 V_80 ;
F_12 ( V_22 , L_9 , V_14 ) ;
V_79 = F_33 ( V_7 -> V_81 -> V_82 ) ;
if ( F_28 ( V_79 ) ) {
F_12 ( V_22 , L_17 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_79 -> V_19 ; V_18 ++ ) {
V_12 = F_9 ( V_79 , V_18 , F_20 , & V_14 ) ;
while ( V_12 ) {
V_80 = F_34 ( V_12 , V_83 ) ;
V_78 = & V_7 -> V_21 . V_23 [ V_80 ] ;
F_35 ( V_12 != V_78 -> V_31 ) ;
V_78 -> V_24 = V_25 ;
F_10 ( V_12 ) ;
V_12 = F_9 ( V_79 , V_18 , F_20 , & V_14 ) ;
}
}
}
static void F_36 ( struct V_6 * V_7 , int V_14 )
{
int V_3 ;
struct V_45 * V_84 ;
bool (* F_8)( struct V_11 * , void * ) = NULL ;
F_12 ( V_22 , L_9 , V_14 ) ;
if ( V_7 == NULL )
return;
if ( V_14 != - 1 )
F_8 = F_5 ;
V_84 = & V_7 -> V_46 . V_57 [ 0 ] ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_46 . V_57 ) ; V_3 ++ )
F_31 ( V_7 , & V_84 [ V_3 ] , V_14 ) ;
F_31 ( V_7 , & V_7 -> V_46 . V_61 , V_14 ) ;
F_32 ( V_7 , F_8 , V_14 ) ;
F_19 ( V_7 , F_8 , V_14 ) ;
}
static void F_37 ( struct V_6 * V_85 ,
struct V_45 * V_56 ,
int V_18 )
{
F_12 ( V_22 , L_12 , V_56 -> V_53 ) ;
if ( V_56 -> V_24 == V_55 ) {
if ( F_38 ( & V_56 -> V_75 , 3 << ( V_18 * 2 ) ) == 0 )
V_56 -> V_86 =
V_56 -> V_86 & ~ F_39 ( V_18 ) ;
else
V_56 -> V_86 =
V_56 -> V_86 | F_39 ( V_18 ) ;
}
if ( V_56 -> V_87 != V_56 -> V_86 )
V_56 -> V_88 = true ;
}
static void
F_40 ( struct V_6 * V_7 , struct V_16 * V_89 ,
T_2 V_90 )
{
struct V_58 * V_59 = V_7 -> V_81 -> V_91 [ V_90 ] ;
if ( F_35 ( ! V_59 ) )
return;
F_12 ( V_22 ,
L_18 , V_59 -> V_65 , V_59 -> V_14 ) ;
if ( ( V_59 -> V_92 & V_93 ) &&
V_89 -> V_76 <= V_94 )
F_41 ( V_59 ,
V_93 , false ) ;
if ( ! ( V_59 -> V_92 & V_93 ) &&
V_89 -> V_76 >= V_95 )
F_41 ( V_59 , V_93 , true ) ;
return;
}
static int F_42 ( struct V_6 * V_7 , T_3 V_96 )
{
F_12 ( V_97 , L_19 , V_96 ) ;
return 0 ;
}
static
int F_43 ( struct V_6 * V_7 , T_2 type , T_2 * V_98 )
{
struct V_45 * V_56 , * V_99 ;
T_2 V_72 ;
T_2 V_14 ;
T_2 * V_47 ;
V_72 = * V_98 ++ ;
V_14 = * V_98 ++ ;
V_47 = V_98 ;
V_56 = & V_7 -> V_46 . V_57 [ V_72 & 0x1F ] ;
if ( type == V_100 ) {
F_12 ( V_22 , L_20 , V_47 , V_14 ) ;
if ( V_56 -> V_48 ) {
F_31 ( V_7 , V_56 , - 1 ) ;
F_22 ( V_56 ) ;
} else
V_7 -> V_8 . V_101 ++ ;
return 0 ;
}
F_12 ( V_22 ,
L_21 , V_47 , V_72 , V_14 ) ;
V_99 = F_23 ( V_7 , V_47 ) ;
if ( F_28 ( V_99 ) ) {
if ( ! V_56 -> V_48 ) {
V_56 -> V_72 = V_72 ;
F_21 ( V_56 , V_47 , V_14 ) ;
F_44 ( & V_56 -> V_75 , V_102 ,
V_103 ) ;
} else {
V_7 -> V_8 . V_101 ++ ;
}
} else {
if ( V_56 != V_99 ) {
F_12 ( V_22 , L_22 ) ;
memcpy ( V_56 , V_99 ,
F_45 ( struct V_45 , V_75 ) ) ;
V_56 -> V_72 = V_72 ;
F_22 ( V_99 ) ;
} else {
F_12 ( V_22 , L_23 ) ;
F_35 ( V_56 -> V_72 != V_72 ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_98 )
{
struct V_45 * V_56 ;
T_2 V_72 ;
int V_3 ;
V_72 = V_98 [ 0 ] ;
V_56 = & V_7 -> V_46 . V_57 [ V_72 & 0x1F ] ;
if ( ! V_56 -> V_48 ) {
V_7 -> V_8 . V_104 ++ ;
return - V_105 ;
}
V_56 -> V_50 = 0 ;
if ( type == V_106 ) {
V_56 -> V_24 = V_49 ;
return V_107 ;
} else {
V_56 -> V_24 = V_55 ;
for ( V_3 = V_108 ; V_3 < V_109 ; V_3 ++ )
F_37 ( V_7 , V_56 , V_3 ) ;
}
return V_110 ;
}
static int F_47 ( struct V_6 * V_7 ,
T_2 type , T_2 * V_98 )
{
struct V_45 * V_56 ;
T_2 V_14 ;
int V_111 ;
V_14 = V_98 [ 0 ] ;
F_12 ( V_22 , L_9 , V_14 ) ;
if ( V_14 >= V_112 ) {
V_111 = - V_113 ;
goto V_114;
}
V_56 = & V_7 -> V_46 . V_73 [ V_14 ] ;
if ( ! V_56 -> V_48 ) {
V_111 = - V_105 ;
goto V_114;
}
switch ( type ) {
case V_115 :
V_56 -> V_24 = V_49 ;
return V_107 ;
case V_116 :
V_56 -> V_24 = V_55 ;
return V_110 ;
default:
V_111 = - V_10 ;
break;
}
V_114:
V_7 -> V_8 . V_117 ++ ;
return V_111 ;
}
static int F_48 ( struct V_6 * V_7 , T_2 type ,
T_2 * V_98 )
{
struct V_45 * V_56 ;
V_56 = & V_7 -> V_46 . V_57 [ V_98 [ 1 ] & 0x1F ] ;
if ( ! V_56 -> V_48 ) {
if ( type == V_118 )
V_7 -> V_8 . V_119 ++ ;
else
V_7 -> V_8 . V_120 ++ ;
return - V_105 ;
}
if ( type == V_118 )
V_56 -> V_50 = V_98 [ 0 ] ;
else
V_56 -> V_74 = V_98 [ 0 ] ;
V_56 -> V_52 = V_98 [ 2 ] ;
return V_107 ;
}
static void F_49 ( struct V_6 * V_7 ,
T_2 V_69 , T_2 V_121 )
{
int V_122 ;
int * V_123 ;
int * V_124 ;
if ( ! V_121 )
return;
if ( ( V_69 == V_108 ) &&
( V_7 -> V_125 [ 0 ] ) ) {
for ( V_122 = V_126 ; V_122 >= 0 ;
V_122 -- ) {
V_123 = & V_7 -> V_125 [ V_122 ] ;
if ( * V_123 ) {
V_7 -> V_127 |= ( 1 << V_122 ) ;
V_124 = & V_7 -> V_124 [ V_122 ] ;
if ( * V_123 >= V_121 ) {
* V_123 -= V_121 ;
* V_124 += V_121 ;
return;
} else {
V_121 -= * V_123 ;
* V_124 += * V_123 ;
* V_123 = 0 ;
}
}
}
}
V_7 -> V_127 |= 1 << V_69 ;
V_7 -> V_124 [ V_69 ] += V_121 ;
}
static void F_50 ( struct V_6 * V_7 )
{
if ( V_7 -> V_127 & V_7 -> V_128 )
F_51 ( V_7 -> V_129 , & V_7 -> V_130 ) ;
}
static void F_52 ( struct V_6 * V_7 , int V_69 ,
struct V_11 * V_131 )
{
struct V_45 * V_56 = F_53 ( V_131 ) -> V_132 ;
if ( F_53 ( V_131 ) -> V_133 & V_134 ) {
if ( V_7 -> V_135 != V_136 )
return;
F_49 ( V_7 , V_69 , 1 ) ;
} else {
if ( ! F_6 ( V_131 , V_137 ) )
V_56 -> V_50 ++ ;
}
F_50 ( V_7 ) ;
}
static int F_54 ( struct V_6 * V_7 ,
enum V_138 V_24 , int V_69 ,
struct V_11 * V_131 )
{
int V_18 = 2 * V_69 ;
T_1 * V_139 = & V_7 -> V_8 . V_140 ;
struct V_45 * V_56 ;
V_56 = F_53 ( V_131 ) -> V_132 ;
if ( V_56 == NULL ) {
F_14 ( L_24 , V_131 ) ;
return - V_33 ;
}
F_12 ( V_22 , L_25 , V_56 -> V_53 , V_56 -> V_75 . V_76 ) ;
if ( V_24 == V_141 ) {
V_18 += 1 ;
V_139 = & V_7 -> V_8 . V_142 ;
}
if ( F_55 ( & V_56 -> V_75 , V_18 , V_131 ) == NULL ) {
* V_139 += 1 ;
return - V_143 ;
}
V_7 -> V_128 |= 1 << V_69 ;
V_7 -> V_144 [ V_69 ] ++ ;
F_53 ( V_131 ) -> V_24 = V_24 ;
if ( V_24 == V_141 )
V_56 -> V_145 ++ ;
F_37 ( V_7 , V_56 , V_69 ) ;
F_40 ( V_7 , & V_56 -> V_75 ,
F_6 ( V_131 , V_15 ) ) ;
return 0 ;
}
static struct V_11 * F_56 ( struct V_6 * V_7 , int V_69 )
{
struct V_45 * V_84 ;
struct V_45 * V_56 ;
struct V_11 * V_131 ;
int V_146 = 1 ;
int V_147 ;
int V_148 ;
int V_149 ;
int V_150 ;
int V_3 ;
V_84 = (struct V_45 * ) & V_7 -> V_46 ;
V_147 = sizeof( V_7 -> V_46 ) / sizeof( struct V_45 ) ;
V_148 = V_7 -> V_151 [ V_69 ] ;
for ( V_3 = 0 ; V_3 < V_147 ; V_3 ++ ) {
V_56 = & V_84 [ ( V_148 + V_3 ) % V_147 ] ;
if ( ! V_56 -> V_48 ||
F_29 ( V_7 , V_56 , V_69 ) )
continue;
if ( V_56 -> V_152 )
V_150 = 2 ;
else
V_150 = 3 ;
V_131 = F_57 ( & V_56 -> V_75 , V_150 << ( V_69 * 2 ) , & V_149 ) ;
if ( V_131 == NULL ) {
if ( V_56 -> V_152 ) {
if ( V_56 -> V_153 >
V_56 -> V_145 )
return NULL ;
V_56 -> V_152 = false ;
V_131 = F_57 ( & V_56 -> V_75 ,
1 << ( V_69 * 2 ) , & V_149 ) ;
}
}
if ( V_131 == NULL )
continue;
if ( V_56 -> V_50 > 0 ) {
V_56 -> V_50 -- ;
if ( V_56 -> V_24 == V_55 )
V_146 = 0 ;
} else if ( V_56 -> V_74 > 0 ) {
V_56 -> V_74 -- ;
F_58 ( V_131 , V_137 , 1 ) ;
if ( V_56 -> V_24 == V_55 )
V_146 = 0 ;
}
F_58 ( V_131 , V_154 , V_146 ) ;
V_7 -> V_151 [ V_69 ] = ( V_148 + V_3 + 1 ) % V_147 ;
F_40 ( V_7 , & V_56 -> V_75 ,
F_6 ( V_131 ,
V_15 )
) ;
F_37 ( V_7 , V_56 , V_69 ) ;
V_7 -> V_144 [ V_69 ] -- ;
if ( V_7 -> V_144 [ V_69 ] == 0 )
V_7 -> V_128 &= ~ ( 1 << V_69 ) ;
goto V_29;
}
V_131 = NULL ;
V_29:
F_12 ( V_22 , L_26 , V_69 , V_131 ) ;
return V_131 ;
}
static int F_59 ( struct V_6 * V_7 , int V_69 ,
struct V_11 * V_12 , T_1 V_155 )
{
struct V_45 * V_56 = F_53 ( V_12 ) -> V_132 ;
T_1 V_80 ;
int V_111 ;
V_80 = F_34 ( V_12 , V_83 ) ;
if ( ! V_56 -> V_152 || V_56 -> V_156 != V_155 ) {
V_56 -> V_152 = true ;
V_56 -> V_145 = F_38 ( & V_56 -> V_75 ,
1 << ( V_69 * 2 + 1 ) ) ;
V_56 -> V_153 = V_56 -> V_157 ;
}
V_56 -> V_156 = V_155 ;
V_111 = F_54 ( V_7 , V_141 , V_69 , V_12 ) ;
if ( V_111 != 0 ) {
F_16 ( & V_7 -> V_21 , V_80 , & V_12 ,
true ) ;
} else {
F_17 ( & V_7 -> V_21 , V_80 ,
V_155 ) ;
V_56 -> V_145 ++ ;
}
return V_111 ;
}
static int
F_60 ( struct V_6 * V_7 , T_2 V_158 , T_1 V_80 ,
T_1 V_155 )
{
T_1 V_69 ;
int V_111 ;
bool V_159 = true ;
struct V_11 * V_12 ;
struct V_45 * V_56 = NULL ;
F_12 ( V_22 , L_27 ,
V_158 , V_80 ) ;
if ( V_158 == V_160 )
V_7 -> V_8 . V_161 ++ ;
else if ( V_158 == V_162 ) {
V_7 -> V_8 . V_163 ++ ;
V_159 = false ;
} else if ( V_158 == V_164 ) {
V_7 -> V_8 . V_165 ++ ;
V_159 = false ;
} else if ( V_158 == V_166 )
V_7 -> V_8 . V_167 ++ ;
else
F_14 ( L_28 ) ;
V_111 = F_16 ( & V_7 -> V_21 , V_80 , & V_12 ,
V_159 ) ;
if ( V_111 != 0 ) {
F_14 ( L_29 , V_80 ) ;
return V_111 ;
}
V_56 = F_53 ( V_12 ) -> V_132 ;
if ( F_35 ( ! V_56 ) ) {
F_10 ( V_12 ) ;
return - V_10 ;
}
V_69 = F_34 ( V_12 , V_168 ) ;
F_52 ( V_7 , V_69 , V_12 ) ;
if ( ! V_159 )
V_111 = F_59 ( V_7 , V_69 , V_12 , V_155 ) ;
if ( V_159 || V_111 ) {
V_56 -> V_157 -- ;
if ( V_56 -> V_152 )
V_56 -> V_153 -- ;
F_61 ( V_7 -> V_81 , V_12 , true ) ;
}
return 0 ;
}
static int F_62 ( struct V_6 * V_7 ,
T_2 * V_98 )
{
int V_3 ;
if ( V_7 -> V_135 != V_169 ) {
F_12 ( V_170 , L_30 ) ;
return V_110 ;
}
F_12 ( V_22 , L_31 , V_98 ) ;
for ( V_3 = 0 ; V_3 < V_171 ; V_3 ++ )
F_49 ( V_7 , V_3 , V_98 [ V_3 ] ) ;
F_12 ( V_170 , L_32 , V_7 -> V_127 ,
V_7 -> V_128 ) ;
return V_107 ;
}
static int F_63 ( struct V_6 * V_7 , T_2 * V_98 )
{
T_4 V_172 ;
T_1 V_173 ;
T_1 V_80 ;
T_1 V_155 ;
T_2 V_158 ;
V_7 -> V_8 . V_174 ++ ;
memcpy ( & V_172 , V_98 , sizeof( V_172 ) ) ;
V_173 = F_64 ( V_172 ) ;
V_158 = F_65 ( V_173 , V_175 ) ;
V_80 = F_65 ( V_173 , V_83 ) ;
V_155 = F_65 ( V_173 , V_176 ) ;
return F_60 ( V_7 , V_158 , V_80 , V_155 ) ;
}
static int F_66 ( struct V_6 * V_7 , T_2 * V_98 )
{
T_4 V_177 ;
memcpy ( & V_177 , & V_98 [ 2 ] , sizeof( V_177 ) ) ;
F_12 ( V_170 , L_33 , V_98 [ 1 ] ,
F_64 ( V_177 ) ) ;
return 0 ;
}
static int F_67 ( struct V_58 * V_59 ,
const struct V_178 * V_179 ,
void * V_98 )
{
struct V_6 * V_7 = V_59 -> V_81 -> V_7 ;
int V_3 ;
T_5 V_158 ;
T_2 * V_121 = V_98 ;
if ( V_179 -> V_180 < V_171 ) {
F_14 ( L_34 , V_179 -> V_180 ) ;
return - V_10 ;
}
F_12 ( V_22 , L_35 , V_121 ) ;
F_68 ( V_59 -> V_81 , V_158 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_124 ) ; V_3 ++ ) {
if ( * V_121 )
V_7 -> V_127 |= 1 << V_3 ;
else
V_7 -> V_127 &= ~ ( 1 << V_3 ) ;
V_7 -> V_124 [ V_3 ] = * V_121 ++ ;
}
F_50 ( V_7 ) ;
F_69 ( V_59 -> V_81 , V_158 ) ;
return 0 ;
}
int F_70 ( struct V_181 * V_81 , int V_14 , T_6 V_182 ,
struct V_11 * V_12 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
T_5 V_158 ;
T_2 * V_183 ;
T_6 V_184 ;
T_2 type ;
T_2 V_76 ;
T_2 * V_98 ;
T_7 V_173 ;
T_7 V_185 ;
F_12 ( V_22 , L_36 ,
V_14 , V_12 -> V_76 , V_182 ) ;
F_35 ( V_182 > V_12 -> V_76 ) ;
if ( ! V_182 || ! V_81 -> V_186 ) {
F_71 ( V_12 , V_182 ) ;
return 0 ;
}
F_68 ( V_81 , V_158 ) ;
V_7 -> V_8 . V_187 ++ ;
V_184 = V_182 ;
V_183 = V_12 -> V_98 ;
V_173 = V_110 ;
while ( V_184 > 0 ) {
type = V_183 [ 0 ] ;
if ( type == V_188 ) {
V_183 += 1 ;
V_184 -= 1 ;
continue;
}
V_76 = V_183 [ 1 ] ;
V_98 = V_183 + 2 ;
F_12 ( V_170 , L_37 , type ,
F_1 ( type ) , V_76 , * V_98 ) ;
if ( V_184 < V_76 + 2 )
break;
if ( V_76 != F_3 ( V_7 , type ) )
break;
V_185 = V_110 ;
switch ( type ) {
case V_189 :
case V_190 :
break;
case V_191 :
case V_100 :
F_43 ( V_7 , type , V_98 ) ;
break;
case V_106 :
case V_192 :
V_185 = F_46 ( V_7 , type , V_98 ) ;
break;
case V_115 :
case V_116 :
V_185 = F_47 ( V_7 , type ,
V_98 ) ;
break;
case V_118 :
case V_193 :
V_185 = F_48 ( V_7 , type , V_98 ) ;
break;
case V_194 :
F_63 ( V_7 , V_98 ) ;
break;
case V_195 :
V_185 = F_62 ( V_7 , V_98 ) ;
break;
case V_196 :
F_42 ( V_7 , * V_98 ) ;
break;
case V_197 :
F_66 ( V_7 , V_98 ) ;
break;
case V_198 :
case V_199 :
default:
V_7 -> V_8 . V_9 ++ ;
break;
}
if ( V_185 == V_107 )
V_173 = V_107 ;
V_183 += V_76 + 2 ;
V_184 -= V_76 + 2 ;
}
if ( V_184 != 0 )
V_7 -> V_8 . V_200 ++ ;
if ( V_173 == V_107 )
F_50 ( V_7 ) ;
F_71 ( V_12 , V_182 ) ;
if ( V_12 -> V_76 == 0 )
V_7 -> V_8 . V_201 ++ ;
F_69 ( V_81 , V_158 ) ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_45 * V_56 = F_53 ( V_12 ) -> V_132 ;
T_2 * V_202 ;
T_8 V_203 = 0 ;
T_2 V_204 ;
T_4 V_205 = F_73 ( F_53 ( V_12 ) -> V_206 ) ;
F_12 ( V_22 , L_38 ,
V_56 -> V_53 , V_56 -> V_51 , F_64 ( V_205 ) ) ;
if ( V_56 -> V_88 )
V_203 += 2 + V_207 ;
V_203 += 2 + V_208 ;
V_204 = F_74 ( V_203 , 4 ) - V_203 ;
V_203 += V_204 ;
F_75 ( V_12 , V_203 ) ;
V_202 = V_12 -> V_98 ;
V_202 [ 0 ] = V_198 ;
V_202 [ 1 ] = V_208 ;
memcpy ( & V_202 [ 2 ] , & V_205 , sizeof( V_205 ) ) ;
V_202 += V_208 + 2 ;
if ( V_56 -> V_88 ) {
V_56 -> V_88 = 0 ;
V_202 [ 0 ] = V_199 ;
V_202 [ 1 ] = V_207 ;
V_202 [ 2 ] = V_56 -> V_72 ;
V_202 [ 3 ] = V_56 -> V_86 ;
V_202 += V_207 + 2 ;
V_56 -> V_87 = V_56 -> V_86 ;
}
if ( V_204 )
memset ( V_202 , V_188 , V_204 ) ;
F_76 ( V_7 -> V_81 , F_6 ( V_12 , V_15 ) ,
V_203 >> 2 , V_12 ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_7 , int V_69 ,
struct V_11 * V_131 )
{
struct V_209 * V_210 = F_53 ( V_131 ) ;
struct V_45 * V_56 = V_210 -> V_132 ;
int V_211 = 0 ;
bool V_212 ;
int V_80 = V_28 ;
T_2 V_213 ;
T_2 V_14 ;
T_2 V_158 ;
V_212 = V_210 -> V_24 != V_141 ;
if ( V_212 ) {
V_80 = F_13 ( & V_7 -> V_21 ) ;
V_213 = V_56 -> V_214 [ V_69 ] ;
F_78 ( V_131 , V_83 , V_80 ) ;
F_78 ( V_131 , V_215 , V_213 ) ;
F_78 ( V_131 , V_176 , 1 ) ;
V_56 -> V_157 ++ ;
}
F_58 ( V_131 , V_216 , 1 ) ;
F_78 ( V_131 , V_168 , V_69 ) ;
V_158 = V_217 ;
if ( ! ( V_210 -> V_133 & V_134 ) ) {
V_158 |= V_218 ;
}
F_78 ( V_131 , V_175 , V_158 ) ;
if ( V_212 ) {
F_72 ( V_7 , V_131 ) ;
V_211 = F_15 ( & V_7 -> V_21 , V_131 , V_80 ) ;
if ( V_211 )
F_14 ( L_39 , V_211 ) ;
} else {
int V_40 ;
V_211 = F_79 ( V_7 -> V_81 , false , & V_14 , V_131 ) ;
if ( V_211 == 0 ) {
V_80 = F_34 ( V_131 , V_83 ) ;
F_18 ( & V_7 -> V_21 , V_131 ,
V_80 , & V_40 ) ;
F_78 ( V_131 , V_176 , V_40 ) ;
F_72 ( V_7 , V_131 ) ;
}
}
return V_211 ;
}
static void
F_80 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_45 * V_56 ;
enum V_138 V_24 ;
struct V_11 * V_37 ;
int V_211 = 0 ;
int V_69 ;
int V_80 ;
T_2 V_14 ;
V_69 = F_6 ( V_12 , V_168 ) ;
V_24 = F_53 ( V_12 ) -> V_24 ;
V_56 = F_53 ( V_12 ) -> V_132 ;
if ( V_56 != NULL ) {
if ( V_24 == V_141 ) {
V_37 = F_81 ( & V_56 -> V_75 , 2 * V_69 + 1 ,
V_12 ) ;
if ( V_37 == NULL ) {
F_14 ( L_40 ) ;
V_211 = - V_219 ;
}
} else {
V_80 = F_34 ( V_12 , V_83 ) ;
V_211 = F_79 ( V_7 -> V_81 , false , & V_14 , V_12 ) ;
if ( V_211 ) {
F_14 ( L_41 ) ;
F_16 ( & V_7 -> V_21 , V_80 ,
& V_37 , true ) ;
V_211 = - V_10 ;
goto V_114;
}
V_37 = F_81 ( & V_56 -> V_75 ,
2 * V_69 , V_12 ) ;
if ( V_37 == NULL ) {
F_14 ( L_42 ) ;
V_211 = - V_219 ;
}
F_16 ( & V_7 -> V_21 , V_80 , & V_37 ,
true ) ;
V_56 -> V_214 [ V_69 ] -- ;
}
if ( ! ( F_53 ( V_12 ) -> V_133 &
V_134 ) )
V_56 -> V_50 ++ ;
} else {
F_14 ( L_43 ) ;
V_211 = - V_33 ;
}
V_114:
if ( V_211 ) {
F_61 ( V_7 -> V_81 , V_12 , false ) ;
V_7 -> V_8 . V_220 ++ ;
} else
V_7 -> V_8 . V_221 ++ ;
}
static int F_82 ( struct V_6 * V_7 )
{
int V_122 ;
if ( F_83 ( V_7 -> V_222 , V_223 ) )
return - V_224 ;
for ( V_122 = 0 ; V_122 <= V_126 ; V_122 ++ ) {
if ( V_7 -> V_124 [ V_122 ] ) {
V_7 -> V_125 [ V_122 ] ++ ;
V_7 -> V_124 [ V_122 ] -- ;
if ( V_7 -> V_124 [ V_122 ] == 0 )
V_7 -> V_127 &= ~ ( 1 << V_122 ) ;
F_12 ( V_22 , L_44 , V_122 ) ;
return 0 ;
}
}
return - V_224 ;
}
static int F_84 ( struct V_6 * V_7 , int V_69 ,
struct V_11 * V_12 )
{
struct V_45 * V_56 = F_53 ( V_12 ) -> V_132 ;
int * V_225 = & V_7 -> V_124 [ V_69 ] ;
int V_146 = 1 ;
F_12 ( V_22 , L_45 , V_69 , * V_225 ) ;
if ( V_56 -> V_50 > 0 ) {
V_56 -> V_50 -- ;
if ( V_56 -> V_24 == V_55 )
V_146 = 0 ;
} else if ( V_56 -> V_74 > 0 ) {
V_56 -> V_74 -- ;
F_58 ( V_12 , V_137 , 1 ) ;
if ( V_56 -> V_24 == V_55 )
V_146 = 0 ;
}
F_58 ( V_12 , V_154 , V_146 ) ;
if ( ! V_146 ) {
F_12 ( V_22 , L_46 ) ;
return 0 ;
}
if ( V_69 != V_108 )
V_7 -> V_222 = V_223 +
V_226 ;
if ( ! ( * V_225 ) ) {
if ( V_69 == V_108 &&
F_82 ( V_7 ) == 0 )
return 0 ;
F_12 ( V_22 , L_47 , V_69 ) ;
return - V_224 ;
}
( * V_225 ) -- ;
if ( ! ( * V_225 ) )
V_7 -> V_127 &= ~ ( 1 << V_69 ) ;
F_12 ( V_22 , L_48 , V_69 , * V_225 ) ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 , int V_69 ,
struct V_11 * V_12 )
{
struct V_209 * V_210 = F_53 ( V_12 ) ;
struct V_45 * V_56 ;
struct V_227 * V_228 = V_7 -> V_81 -> V_82 ;
int V_211 ;
V_56 = V_210 -> V_132 ;
if ( F_28 ( V_56 ) )
return F_86 ( V_56 ) ;
V_211 = F_77 ( V_7 , V_69 , V_12 ) ;
if ( V_211 < 0 ) {
V_7 -> V_8 . V_229 ++ ;
goto V_230;
}
V_211 = F_87 ( V_228 , V_12 ) ;
if ( V_211 < 0 )
goto V_230;
V_56 -> V_214 [ V_69 ] ++ ;
V_7 -> V_8 . V_231 ++ ;
if ( F_53 ( V_12 ) -> V_133 & V_134 ) {
V_7 -> V_8 . V_232 [ V_69 ] ++ ;
V_7 -> V_8 . V_233 [ V_69 ] ++ ;
}
return V_211 ;
V_230:
F_80 ( V_7 , V_12 ) ;
return V_211 ;
}
int F_88 ( struct V_58 * V_59 , struct V_11 * V_12 )
{
struct V_181 * V_81 = V_59 -> V_81 ;
struct V_6 * V_7 = V_81 -> V_7 ;
struct V_209 * V_210 = F_53 ( V_12 ) ;
struct V_234 * V_235 = (struct V_234 * ) ( V_12 -> V_98 ) ;
T_5 V_158 ;
int V_69 = V_236 ;
bool V_62 = F_26 ( V_235 -> V_237 ) ;
if ( ! V_12 -> V_238 )
V_12 -> V_238 = F_89 ( V_12 ) ;
V_81 -> V_239 += ! ! V_62 ;
if ( F_90 ( V_235 -> V_240 ) == V_241 )
F_91 ( & V_59 -> V_242 ) ;
if ( ! F_92 ( V_7 ) ) {
F_76 ( V_81 , V_59 -> V_14 , 0 , V_12 ) ;
return F_87 ( V_81 -> V_82 , V_12 ) ;
}
V_210 -> V_133 = 0 ;
V_210 -> V_132 = F_25 ( V_7 , V_59 , V_235 -> V_237 ) ;
V_210 -> V_24 = V_243 ;
F_58 ( V_12 , V_15 , V_59 -> V_14 ) ;
if ( ! V_62 )
V_69 = V_244 [ V_12 -> V_238 ] ;
F_58 ( V_12 , V_168 , V_69 ) ;
F_12 ( V_22 , L_49 , V_235 -> V_237 ,
V_62 , V_69 ) ;
F_68 ( V_81 , V_158 ) ;
if ( V_210 -> V_132 -> V_152 ||
F_29 ( V_7 , V_210 -> V_132 , V_69 ) ||
F_38 ( & V_210 -> V_132 -> V_75 , 3 << ( V_69 * 2 ) ) ||
( ! V_62 &&
F_84 ( V_7 , V_69 , V_12 ) < 0 ) ) {
V_81 -> V_7 -> V_128 |= 1 << V_69 ;
F_54 ( V_7 , V_245 , V_69 , V_12 ) ;
} else {
if ( F_85 ( V_7 , V_69 , V_12 ) )
if ( ! V_62 )
F_52 ( V_7 , V_69 , V_12 ) ;
}
F_69 ( V_81 , V_158 ) ;
return 0 ;
}
void F_93 ( struct V_58 * V_59 )
{
struct V_45 * V_56 = V_59 -> V_68 ;
F_12 ( V_22 , L_13 , V_59 -> V_65 ) ;
if ( ! V_56 )
return;
F_21 ( V_56 , V_59 -> V_246 , V_59 -> V_14 ) ;
}
void F_94 ( struct V_58 * V_59 )
{
struct V_6 * V_7 = V_59 -> V_81 -> V_7 ;
struct V_45 * V_56 ;
F_12 ( V_22 , L_50 ,
V_59 -> V_65 , V_59 -> V_246 ) ;
if ( ! V_59 -> V_247 || ! V_59 -> V_81 -> V_186 )
return;
V_56 = & V_7 -> V_46 . V_73 [ V_59 -> V_14 ] ;
V_59 -> V_68 = V_56 ;
F_21 ( V_56 , V_59 -> V_246 , V_59 -> V_14 ) ;
F_44 ( & V_56 -> V_75 , V_102 ,
V_103 ) ;
}
void F_95 ( struct V_58 * V_59 )
{
struct V_45 * V_56 = V_59 -> V_68 ;
T_5 V_158 ;
F_12 ( V_22 , L_13 , V_59 -> V_65 ) ;
if ( ! V_56 )
return;
F_68 ( V_59 -> V_81 , V_158 ) ;
V_59 -> V_68 = NULL ;
F_22 ( V_56 ) ;
F_36 ( V_59 -> V_81 -> V_7 , V_59 -> V_14 ) ;
F_69 ( V_59 -> V_81 , V_158 ) ;
}
static void F_96 ( struct V_248 * V_249 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
T_5 V_158 ;
int V_69 ;
int V_225 ;
V_7 = F_97 ( V_249 , struct V_6 , V_130 ) ;
F_12 ( V_22 , L_51 , V_7 ) ;
F_68 ( V_7 -> V_81 , V_158 ) ;
for ( V_69 = V_109 ; V_69 >= 0 ; V_69 -- ) {
F_12 ( V_22 , L_52 , V_69 ,
V_7 -> V_124 [ V_69 ] ) ;
for ( V_225 = 0 ; V_225 < V_7 -> V_124 [ V_69 ] ; ) {
V_12 = F_56 ( V_7 , V_69 ) ;
if ( ! V_12 || F_85 ( V_7 , V_69 , V_12 ) )
break;
if ( F_53 ( V_12 ) -> V_133 &
V_134 )
V_225 ++ ;
}
if ( ( V_69 == V_108 ) &&
( V_225 == V_7 -> V_124 [ V_69 ] ) ) {
V_7 -> V_124 [ V_69 ] -= V_225 ;
while ( F_82 ( V_7 ) == 0 ) {
V_12 = F_56 ( V_7 , V_69 ) ;
if ( ! V_12 ) {
F_49 ( V_7 , V_69 , 1 ) ;
break;
}
if ( F_85 ( V_7 , V_69 , V_12 ) ) {
F_49 ( V_7 , V_69 , 1 ) ;
break;
}
}
} else {
V_7 -> V_124 [ V_69 ] -= V_225 ;
}
}
F_69 ( V_7 -> V_81 , V_158 ) ;
}
int F_98 ( struct V_181 * V_81 )
{
T_1 V_250 = V_251 ;
int V_211 ;
if ( ! V_81 -> V_186 )
return 0 ;
F_99 ( & V_81 -> V_252 ) ;
V_81 -> V_7 = F_100 ( sizeof( * ( V_81 -> V_7 ) ) , V_253 ) ;
if ( ! V_81 -> V_7 ) {
V_211 = - V_254 ;
goto V_114;
}
V_81 -> V_7 -> V_81 = V_81 ;
V_81 -> V_7 -> V_135 = V_135 ;
V_81 -> V_7 -> V_129 = F_101 ( L_53 ) ;
if ( V_81 -> V_7 -> V_129 == NULL ) {
F_14 ( L_54 ) ;
V_211 = - V_255 ;
goto V_114;
}
F_102 ( & V_81 -> V_7 -> V_130 , F_96 ) ;
if ( V_81 -> V_7 -> V_135 != V_256 )
V_250 |= V_257 |
V_258 |
V_259 ;
V_211 = F_103 ( V_81 , V_260 ,
F_67 ) ;
if ( V_211 < 0 ) {
F_14 ( L_55 ) ;
goto V_114;
}
if ( F_104 ( V_81 -> V_91 [ 0 ] , L_56 , V_250 ) ) {
F_14 ( L_57 ) ;
goto V_261;
}
F_11 ( & V_81 -> V_7 -> V_21 ) ;
F_21 ( & V_81 -> V_7 -> V_46 . V_61 , NULL , 0 ) ;
F_44 ( & V_81 -> V_7 -> V_46 . V_61 . V_75 , V_102 ,
V_103 ) ;
F_105 ( V_81 , & V_81 -> V_7 -> V_8 ) ;
F_14 ( L_58 ,
V_81 -> V_186 ? L_59 : L_60 , V_250 ) ;
return 0 ;
V_261:
F_106 ( V_81 , V_260 ) ;
V_114:
F_107 ( V_81 ) ;
return V_211 ;
}
void F_107 ( struct V_181 * V_81 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
T_5 V_158 ;
if ( ! V_7 )
return;
V_81 -> V_186 = false ;
if ( V_81 -> V_7 -> V_129 )
F_108 ( V_81 -> V_7 -> V_129 ) ;
F_68 ( V_81 , V_158 ) ;
F_36 ( V_7 , - 1 ) ;
V_81 -> V_7 = NULL ;
F_69 ( V_81 , V_158 ) ;
F_109 ( V_7 ) ;
}
bool F_92 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return false ;
F_12 ( V_22 , L_61 , V_7 -> V_135 ) ;
return V_7 -> V_135 != V_256 ;
}
void F_110 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
T_5 V_158 ;
F_68 ( V_7 -> V_81 , V_158 ) ;
F_60 ( V_7 , V_166 ,
F_34 ( V_12 , V_83 ) , 0 ) ;
if ( V_7 -> V_135 == V_169 &&
F_53 ( V_12 ) -> V_133 & V_134 ) {
F_49 ( V_7 ,
F_34 ( V_12 ,
V_168 ) ,
1 ) ;
F_50 ( V_7 ) ;
}
F_69 ( V_7 -> V_81 , V_158 ) ;
}
