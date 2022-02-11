static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
enum V_5 V_6 =
F_2 ( V_4 -> type ) ? V_7 : V_8 ;
void * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
unsigned long V_12 = F_3 ( V_4 -> V_13 [ V_10 ] ) ;
V_9 = F_4 ( V_2 , V_14 , V_4 -> V_15 [ V_10 ] ,
V_12 , V_6 , V_4 -> V_16 ) ;
if ( F_5 ( V_9 ) )
goto free;
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
V_2 -> V_18 [ V_10 ] . V_19 = V_4 -> V_13 [ V_10 ] ;
}
return 0 ;
free:
for (; V_10 > 0 ; -- V_10 ) {
F_6 ( V_2 , V_20 , V_2 -> V_17 [ V_10 - 1 ] . V_9 ) ;
V_2 -> V_17 [ V_10 - 1 ] . V_9 = NULL ;
}
return - V_21 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
F_6 ( V_2 , V_20 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
F_8 ( 3 , L_1 , V_10 ,
V_2 -> V_22 . V_23 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_17 [ V_10 ] . V_9 )
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
if ( ! V_26 -> V_9 )
return;
if ( V_26 -> V_27 )
F_6 ( V_2 , V_28 , V_26 -> V_9 ) ;
F_6 ( V_2 , V_29 , V_26 -> V_9 ) ;
F_11 ( V_26 -> V_30 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_10 ( V_2 , & V_2 -> V_17 [ V_10 ] ) ;
}
static void F_13 ( struct V_3 * V_4 , unsigned int V_31 )
{
unsigned int V_32 , V_10 ;
struct V_1 * V_2 ;
for ( V_32 = V_4 -> V_33 ; V_32 < V_4 -> V_33 + V_31 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
if ( ! V_2 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] . V_19 = V_4 -> V_13 [ V_10 ] ;
}
}
static void F_14 ( struct V_3 * V_4 , unsigned int V_31 )
{
unsigned int V_32 , V_10 ;
struct V_1 * V_2 ;
unsigned long V_35 ;
if ( V_4 -> V_33 ) {
struct V_36 * V_26 ;
V_2 = V_4 -> V_34 [ V_4 -> V_33 - 1 ] ;
V_26 = & V_2 -> V_18 [ V_2 -> V_11 - 1 ] ;
V_35 = F_3 ( V_26 -> V_37 . V_38 + V_26 -> V_19 ) ;
} else {
V_35 = 0 ;
}
for ( V_32 = V_4 -> V_33 ; V_32 < V_4 -> V_33 + V_31 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
if ( ! V_2 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_2 -> V_18 [ V_10 ] . V_37 . V_38 = V_35 ;
F_8 ( 3 , L_2 ,
V_32 , V_10 , V_35 ) ;
V_35 += V_2 -> V_18 [ V_10 ] . V_19 ;
V_35 = F_3 ( V_35 ) ;
}
}
}
static int F_15 ( struct V_3 * V_4 , enum V_39 V_40 ,
unsigned int V_33 , unsigned int V_11 )
{
unsigned int V_32 ;
struct V_1 * V_2 ;
int V_41 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
V_2 = F_16 ( V_4 -> V_42 , V_43 ) ;
if ( ! V_2 ) {
F_8 ( 1 , L_3 ) ;
break;
}
if ( F_17 ( V_4 -> type ) )
V_2 -> V_22 . V_19 = V_11 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_22 . V_23 = V_4 -> V_33 + V_32 ;
V_2 -> V_22 . type = V_4 -> type ;
V_2 -> V_22 . V_40 = V_40 ;
if ( V_40 == V_46 ) {
V_41 = F_1 ( V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_4
L_5 , V_32 ) ;
F_18 ( V_2 ) ;
break;
}
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_6
L_7 , V_32 , V_2 ) ;
F_7 ( V_2 ) ;
F_18 ( V_2 ) ;
break;
}
}
V_4 -> V_34 [ V_4 -> V_33 + V_32 ] = V_2 ;
}
F_13 ( V_4 , V_32 ) ;
if ( V_40 == V_46 )
F_14 ( V_4 , V_32 ) ;
F_8 ( 1 , L_8 ,
V_32 , V_11 ) ;
return V_32 ;
}
static void F_20 ( struct V_3 * V_4 , unsigned int V_48 )
{
unsigned int V_32 ;
struct V_1 * V_2 ;
for ( V_32 = V_4 -> V_33 - V_48 ; V_32 < V_4 -> V_33 ;
++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_40 == V_46 )
F_7 ( V_2 ) ;
else if ( V_4 -> V_40 == V_49 )
F_12 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
}
static int F_21 ( struct V_3 * V_4 , unsigned int V_48 )
{
unsigned int V_32 ;
for ( V_32 = V_4 -> V_33 - V_48 ; V_32 < V_4 -> V_33 ;
++ V_32 ) {
if ( V_4 -> V_34 [ V_32 ] == NULL )
continue;
if ( V_4 -> V_34 [ V_32 ] -> V_44 == V_50 ) {
F_8 ( 1 , L_9 ) ;
return - V_51 ;
}
}
for ( V_32 = V_4 -> V_33 - V_48 ; V_32 < V_4 -> V_33 ;
++ V_32 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_32 ] ;
if ( V_2 && V_2 -> V_17 [ 0 ] . V_9 )
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_20 ( V_4 , V_48 ) ;
#ifdef F_23
if ( V_4 -> V_33 ) {
bool V_53 = V_4 -> V_54 != V_4 -> V_55 ||
V_4 -> V_56 != V_4 -> V_57 ;
if ( V_53 || V_58 ) {
F_24 ( L_10 , V_4 ,
V_53 ? L_11 : L_12 ) ;
F_24 ( L_13 ,
V_4 -> V_59 , V_4 -> V_54 ,
V_4 -> V_55 ) ;
F_24 ( L_14 ,
V_4 -> V_56 , V_4 -> V_57 ) ;
}
V_4 -> V_59 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_57 = 0 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
}
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_32 ] ;
bool V_53 = V_2 -> V_60 != V_2 -> V_61 ||
V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ||
V_2 -> V_74 != V_2 -> V_75 ;
if ( V_53 || V_58 ) {
F_24 ( L_15 ,
V_4 , V_32 , V_53 ? L_11 : L_12 ) ;
F_24 ( L_16 ,
V_2 -> V_74 , V_2 -> V_75 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
F_24 ( L_17 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_24 ( L_18 ,
V_2 -> V_60 , V_2 -> V_61 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_76 ) ;
F_24 ( L_19 ,
V_2 -> V_64 , V_2 -> V_65 ) ;
F_24 ( L_20 ,
V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_68 , V_2 -> V_69 ) ;
F_24 ( L_21 ,
V_2 -> V_77 ,
V_2 -> V_78 ,
V_2 -> V_79 ,
V_2 -> V_80 ) ;
}
}
#endif
for ( V_32 = V_4 -> V_33 - V_48 ; V_32 < V_4 -> V_33 ;
++ V_32 ) {
F_18 ( V_4 -> V_34 [ V_32 ] ) ;
V_4 -> V_34 [ V_32 ] = NULL ;
}
V_4 -> V_33 -= V_48 ;
if ( ! V_4 -> V_33 ) {
V_4 -> V_40 = 0 ;
F_25 ( & V_4 -> V_81 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
if ( ! F_17 ( V_83 -> type ) )
return 0 ;
if ( NULL == V_83 -> V_37 . V_17 ) {
F_8 ( 1 , L_22
L_23 ) ;
return - V_84 ;
}
if ( V_83 -> V_19 < V_2 -> V_11 || V_83 -> V_19 > V_85 ) {
F_8 ( 1 , L_24
L_25 , V_2 -> V_11 , V_83 -> V_19 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
unsigned int V_19 ;
unsigned int V_86 ;
unsigned int V_10 ;
if ( ! F_2 ( V_83 -> type ) )
return 0 ;
if ( F_17 ( V_83 -> type ) ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_19 = ( V_83 -> V_40 == V_87 ||
V_83 -> V_40 == V_49 )
? V_83 -> V_37 . V_17 [ V_10 ] . V_19
: V_2 -> V_18 [ V_10 ] . V_19 ;
V_86 = V_83 -> V_37 . V_17 [ V_10 ] . V_86
? V_83 -> V_37 . V_17 [ V_10 ] . V_86 : V_19 ;
if ( V_83 -> V_37 . V_17 [ V_10 ] . V_86 > V_19 )
return - V_84 ;
if ( V_83 -> V_37 . V_17 [ V_10 ] . V_88 > 0 &&
V_83 -> V_37 . V_17 [ V_10 ] . V_88 >= V_86 )
return - V_84 ;
}
} else {
V_19 = ( V_83 -> V_40 == V_87 )
? V_83 -> V_19 : V_2 -> V_18 [ 0 ] . V_19 ;
V_86 = V_83 -> V_86 ? V_83 -> V_86 : V_19 ;
if ( V_83 -> V_86 > V_19 )
return - V_84 ;
}
return 0 ;
}
static bool F_28 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
void * V_9 = V_2 -> V_17 [ V_10 ] . V_9 ;
if ( V_9 && F_29 ( V_2 , V_89 , V_9 ) > 1 )
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
if ( F_28 ( V_4 , V_4 -> V_34 [ V_32 ] ) )
return true ;
}
return false ;
}
static void F_31 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_83 , & V_2 -> V_22 , F_32 ( struct V_82 , V_37 ) ) ;
V_83 -> V_90 = V_2 -> V_22 . V_90 ;
V_83 -> V_91 = V_2 -> V_22 . V_91 ;
if ( F_17 ( V_4 -> type ) ) {
V_83 -> V_19 = V_2 -> V_11 ;
memcpy ( V_83 -> V_37 . V_17 , V_2 -> V_18 ,
V_83 -> V_19 * sizeof( struct V_36 ) ) ;
} else {
V_83 -> V_19 = V_2 -> V_18 [ 0 ] . V_19 ;
V_83 -> V_86 = V_2 -> V_18 [ 0 ] . V_86 ;
if ( V_4 -> V_40 == V_46 )
V_83 -> V_37 . V_92 = V_2 -> V_18 [ 0 ] . V_37 . V_38 ;
else if ( V_4 -> V_40 == V_87 )
V_83 -> V_37 . V_93 = V_2 -> V_18 [ 0 ] . V_37 . V_93 ;
else if ( V_4 -> V_40 == V_49 )
V_83 -> V_37 . V_94 = V_2 -> V_18 [ 0 ] . V_37 . V_94 ;
}
V_83 -> V_95 &= ~ V_96 ;
V_83 -> V_95 |= V_4 -> V_97 & V_98 ;
if ( ( V_4 -> V_97 & V_98 ) !=
V_99 ) {
V_83 -> V_95 &= ~ V_100 ;
V_83 -> V_95 |= V_4 -> V_97 & V_100 ;
}
switch ( V_2 -> V_44 ) {
case V_101 :
case V_102 :
V_83 -> V_95 |= V_103 ;
break;
case V_104 :
V_83 -> V_95 |= V_105 ;
case V_106 :
V_83 -> V_95 |= V_107 ;
break;
case V_108 :
V_83 -> V_95 |= V_109 ;
break;
case V_50 :
case V_45 :
case V_110 :
break;
}
if ( F_28 ( V_4 , V_2 ) )
V_83 -> V_95 |= V_111 ;
}
int F_33 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_41 ;
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_26 ) ;
return - V_84 ;
}
if ( V_83 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_27 ) ;
return - V_84 ;
}
V_2 = V_4 -> V_34 [ V_83 -> V_23 ] ;
V_41 = F_26 ( V_2 , V_83 ) ;
if ( ! V_41 )
F_31 ( V_2 , V_83 ) ;
return V_41 ;
}
static int F_34 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_112 & V_113 ) || ! V_4 -> V_114 -> V_115 ||
! V_4 -> V_114 -> V_24 )
return - V_84 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_112 & V_116 ) || ! V_4 -> V_114 -> V_14 ||
! V_4 -> V_114 -> V_20 || ! V_4 -> V_114 -> V_117 )
return - V_84 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_112 & V_118 ) || ! V_4 -> V_114 -> V_119 ||
! V_4 -> V_114 -> V_29 || ! V_4 -> V_114 -> V_120 ||
! V_4 -> V_114 -> V_28 )
return - V_84 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
enum V_39 V_40 , enum V_121 type )
{
if ( V_40 != V_46 && V_40 != V_87 &&
V_40 != V_49 ) {
F_8 ( 1 , L_28 ) ;
return - V_84 ;
}
if ( type != V_4 -> type ) {
F_8 ( 1 , L_29 ) ;
return - V_84 ;
}
if ( V_40 == V_46 && F_35 ( V_4 ) ) {
F_8 ( 1 , L_30 ) ;
return - V_84 ;
}
if ( V_40 == V_87 && F_34 ( V_4 ) ) {
F_8 ( 1 , L_31 ) ;
return - V_84 ;
}
if ( V_40 == V_49 && F_36 ( V_4 ) ) {
F_8 ( 1 , L_32 ) ;
return - V_84 ;
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_123 * V_124 )
{
unsigned int V_33 , V_125 , V_11 = 0 ;
int V_41 ;
if ( V_4 -> V_126 ) {
F_8 ( 1 , L_34 ) ;
return - V_122 ;
}
if ( V_124 -> V_127 == 0 || V_4 -> V_33 != 0 || V_4 -> V_40 != V_124 -> V_40 ) {
F_40 ( & V_4 -> V_128 ) ;
if ( V_4 -> V_40 == V_46 && F_30 ( V_4 ) ) {
F_41 ( & V_4 -> V_128 ) ;
F_8 ( 1 , L_35 ) ;
return - V_122 ;
}
F_42 ( V_4 ) ;
V_41 = F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_128 ) ;
if ( V_41 )
return V_41 ;
if ( V_124 -> V_127 == 0 )
return 0 ;
}
V_33 = F_43 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
V_33 = F_44 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_13 , 0 , sizeof( V_4 -> V_13 ) ) ;
memset ( V_4 -> V_15 , 0 , sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_40 = V_124 -> V_40 ;
V_41 = F_45 ( V_4 , V_129 , V_4 , NULL , & V_33 , & V_11 ,
V_4 -> V_13 , V_4 -> V_15 ) ;
if ( V_41 )
return V_41 ;
V_125 = F_15 ( V_4 , V_124 -> V_40 , V_33 , V_11 ) ;
if ( V_125 == 0 ) {
F_8 ( 1 , L_36 ) ;
return - V_21 ;
}
if ( V_125 < V_4 -> V_130 )
V_41 = - V_21 ;
if ( ! V_41 && V_125 < V_33 ) {
V_33 = V_125 ;
V_41 = F_45 ( V_4 , V_129 , V_4 , NULL , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( ! V_41 && V_125 < V_33 )
V_41 = - V_21 ;
}
F_40 ( & V_4 -> V_128 ) ;
V_4 -> V_33 = V_125 ;
if ( V_41 < 0 ) {
F_21 ( V_4 , V_125 ) ;
F_41 ( & V_4 -> V_128 ) ;
return V_41 ;
}
F_41 ( & V_4 -> V_128 ) ;
V_124 -> V_127 = V_125 ;
V_4 -> V_131 = ! F_2 ( V_4 -> type ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , struct V_123 * V_124 )
{
int V_41 = F_37 ( V_4 , V_124 -> V_40 , V_124 -> type ) ;
return V_41 ? V_41 : F_39 ( V_4 , V_124 ) ;
}
static int F_47 ( struct V_3 * V_4 , struct V_132 * V_133 )
{
unsigned int V_11 = 0 , V_33 , V_125 ;
int V_41 ;
if ( V_4 -> V_33 == V_134 ) {
F_8 ( 1 , L_37 ) ;
return - V_135 ;
}
if ( ! V_4 -> V_33 ) {
memset ( V_4 -> V_13 , 0 , sizeof( V_4 -> V_13 ) ) ;
memset ( V_4 -> V_15 , 0 , sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_40 = V_133 -> V_40 ;
V_4 -> V_131 = ! F_2 ( V_4 -> type ) ;
}
V_33 = F_48 ( V_133 -> V_127 , V_134 - V_4 -> V_33 ) ;
V_41 = F_45 ( V_4 , V_129 , V_4 , & V_133 -> V_136 , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( V_41 )
return V_41 ;
V_125 = F_15 ( V_4 , V_133 -> V_40 , V_33 ,
V_11 ) ;
if ( V_125 == 0 ) {
F_8 ( 1 , L_36 ) ;
return - V_21 ;
}
if ( V_125 < V_33 ) {
V_33 = V_125 ;
V_41 = F_45 ( V_4 , V_129 , V_4 , & V_133 -> V_136 , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( ! V_41 && V_125 < V_33 )
V_41 = - V_21 ;
}
F_40 ( & V_4 -> V_128 ) ;
V_4 -> V_33 += V_125 ;
if ( V_41 < 0 ) {
F_21 ( V_4 , V_125 ) ;
F_41 ( & V_4 -> V_128 ) ;
return - V_21 ;
}
F_41 ( & V_4 -> V_128 ) ;
V_133 -> V_127 = V_125 ;
return 0 ;
}
int F_49 ( struct V_3 * V_4 , struct V_132 * V_133 )
{
int V_41 = F_37 ( V_4 , V_133 -> V_40 , V_133 -> V_136 . type ) ;
V_133 -> V_23 = V_4 -> V_33 ;
if ( V_133 -> V_127 == 0 )
return V_41 != - V_122 ? V_41 : 0 ;
return V_41 ? V_41 : F_47 ( V_4 , V_133 ) ;
}
void * F_50 ( struct V_1 * V_2 , unsigned int V_137 )
{
if ( V_137 > V_2 -> V_11 || ! V_2 -> V_17 [ V_137 ] . V_9 )
return NULL ;
return F_4 ( V_2 , V_138 , V_2 -> V_17 [ V_137 ] . V_9 ) ;
}
void * F_51 ( struct V_1 * V_2 , unsigned int V_137 )
{
if ( V_137 >= V_2 -> V_11 || ! V_2 -> V_17 [ V_137 ] . V_9 )
return NULL ;
return F_4 ( V_2 , V_139 , V_2 -> V_17 [ V_137 ] . V_9 ) ;
}
void F_52 ( struct V_1 * V_2 , enum V_140 V_44 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_95 ;
unsigned int V_10 ;
if ( F_53 ( V_2 -> V_44 != V_102 ) )
return;
if ( F_53 ( V_44 != V_106 &&
V_44 != V_104 &&
V_44 != V_101 &&
V_44 != V_110 ) )
V_44 = V_104 ;
#ifdef F_23
V_2 -> V_71 ++ ;
#endif
F_8 ( 4 , L_38 ,
V_2 -> V_22 . V_23 , V_44 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_141 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_54 ( & V_4 -> V_142 , V_95 ) ;
if ( V_44 == V_101 ||
V_44 == V_110 ) {
V_2 -> V_44 = V_101 ;
} else {
F_55 ( & V_2 -> V_143 , & V_4 -> V_144 ) ;
V_2 -> V_44 = V_44 ;
}
F_56 ( & V_4 -> V_145 ) ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
switch ( V_44 ) {
case V_101 :
return;
case V_110 :
if ( V_4 -> V_146 )
F_58 ( V_2 ) ;
return;
default:
F_59 ( & V_4 -> V_147 ) ;
break;
}
}
void F_60 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_95 ;
F_54 ( & V_4 -> V_142 , V_95 ) ;
F_61 (vb, &q->done_list, done_entry)
V_2 -> V_44 = V_104 ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
static bool V_148 ;
if ( V_148 )
return;
V_148 = true ;
F_53 ( 1 ) ;
F_63 ( L_39 ) ;
if ( V_2 -> V_3 -> V_149 )
F_63 ( L_40 ) ;
else
F_63 ( L_41 ) ;
}
static void F_64 ( struct V_1 * V_2 , const struct V_82 * V_83 ,
struct V_36 * V_18 )
{
unsigned int V_10 ;
if ( F_17 ( V_83 -> type ) ) {
if ( V_83 -> V_40 == V_87 ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_18 [ V_10 ] . V_37 . V_93 =
V_83 -> V_37 . V_17 [ V_10 ] . V_37 . V_93 ;
V_18 [ V_10 ] . V_19 =
V_83 -> V_37 . V_17 [ V_10 ] . V_19 ;
}
}
if ( V_83 -> V_40 == V_49 ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_18 [ V_10 ] . V_37 . V_94 =
V_83 -> V_37 . V_17 [ V_10 ] . V_37 . V_94 ;
V_18 [ V_10 ] . V_19 =
V_83 -> V_37 . V_17 [ V_10 ] . V_19 ;
}
}
if ( F_2 ( V_83 -> type ) ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
struct V_36 * V_150 = & V_18 [ V_10 ] ;
struct V_36 * V_151 = & V_83 -> V_37 . V_17 [ V_10 ] ;
if ( V_151 -> V_86 == 0 )
F_62 ( V_2 ) ;
if ( V_2 -> V_3 -> V_149 )
V_150 -> V_86 = V_151 -> V_86 ;
else
V_150 -> V_86 = V_151 -> V_86 ?
V_151 -> V_86 : V_150 -> V_19 ;
V_150 -> V_88 = V_151 -> V_88 ;
}
}
} else {
if ( V_83 -> V_40 == V_87 ) {
V_18 [ 0 ] . V_37 . V_93 = V_83 -> V_37 . V_93 ;
V_18 [ 0 ] . V_19 = V_83 -> V_19 ;
}
if ( V_83 -> V_40 == V_49 ) {
V_18 [ 0 ] . V_37 . V_94 = V_83 -> V_37 . V_94 ;
V_18 [ 0 ] . V_19 = V_83 -> V_19 ;
}
if ( F_2 ( V_83 -> type ) ) {
if ( V_83 -> V_86 == 0 )
F_62 ( V_2 ) ;
if ( V_2 -> V_3 -> V_149 )
V_18 [ 0 ] . V_86 = V_83 -> V_86 ;
else
V_18 [ 0 ] . V_86 = V_83 -> V_86 ?
V_83 -> V_86 : V_18 [ 0 ] . V_19 ;
} else
V_18 [ 0 ] . V_86 = 0 ;
}
V_2 -> V_22 . V_95 = V_83 -> V_95 & ~ V_96 ;
if ( ( V_2 -> V_3 -> V_97 & V_98 ) !=
V_99 || ! F_2 ( V_83 -> type ) ) {
V_2 -> V_22 . V_95 &= ~ V_100 ;
}
if ( F_2 ( V_83 -> type ) ) {
V_2 -> V_22 . V_95 &= ~ V_152 ;
V_2 -> V_22 . V_153 = V_83 -> V_153 ;
} else {
V_2 -> V_22 . V_95 &= ~ V_154 ;
}
}
static int F_65 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
F_64 ( V_2 , V_83 , V_2 -> V_18 ) ;
return F_19 ( V_2 , V_155 , V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_36 V_17 [ V_85 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_9 ;
unsigned int V_10 ;
int V_41 ;
enum V_5 V_6 =
F_2 ( V_4 -> type ) ? V_7 : V_8 ;
bool V_156 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_64 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_93 &&
V_2 -> V_18 [ V_10 ] . V_37 . V_93 == V_17 [ V_10 ] . V_37 . V_93
&& V_2 -> V_18 [ V_10 ] . V_19 == V_17 [ V_10 ] . V_19 )
continue;
F_8 ( 3 , L_42
L_43 , V_10 ) ;
if ( V_17 [ V_10 ] . V_19 < V_4 -> V_13 [ V_10 ] ) {
F_8 ( 1 , L_44
L_45 ,
V_17 [ V_10 ] . V_19 ,
V_4 -> V_13 [ V_10 ] , V_10 ) ;
V_41 = - V_84 ;
goto V_157;
}
if ( V_2 -> V_17 [ V_10 ] . V_9 ) {
if ( ! V_156 ) {
V_156 = true ;
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
}
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
memset ( & V_2 -> V_18 [ V_10 ] , 0 , sizeof( struct V_36 ) ) ;
V_9 = F_4 ( V_2 , V_115 , V_4 -> V_15 [ V_10 ] ,
V_17 [ V_10 ] . V_37 . V_93 ,
V_17 [ V_10 ] . V_19 , V_6 ) ;
if ( F_5 ( V_9 ) ) {
F_8 ( 1 , L_46
L_47 , V_10 ) ;
V_41 = V_9 ? F_67 ( V_9 ) : - V_84 ;
goto V_157;
}
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_156 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_48 ) ;
goto V_157;
}
}
V_41 = F_19 ( V_2 , V_155 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_49 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_157;
}
return 0 ;
V_157:
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_17 [ V_10 ] . V_9 )
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
V_2 -> V_18 [ V_10 ] . V_37 . V_93 = 0 ;
V_2 -> V_18 [ V_10 ] . V_19 = 0 ;
}
return V_41 ;
}
static int F_68 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_36 V_17 [ V_85 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_9 ;
unsigned int V_10 ;
int V_41 ;
enum V_5 V_6 =
F_2 ( V_4 -> type ) ? V_7 : V_8 ;
bool V_156 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_64 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
struct V_158 * V_30 = F_69 ( V_17 [ V_10 ] . V_37 . V_94 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_50 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_157;
}
if ( V_17 [ V_10 ] . V_19 == 0 )
V_17 [ V_10 ] . V_19 = V_30 -> V_12 ;
if ( V_17 [ V_10 ] . V_19 < V_4 -> V_13 [ V_10 ] ) {
F_8 ( 1 , L_51 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_157;
}
if ( V_30 == V_2 -> V_17 [ V_10 ] . V_30 &&
V_2 -> V_18 [ V_10 ] . V_19 == V_17 [ V_10 ] . V_19 ) {
F_11 ( V_30 ) ;
continue;
}
F_8 ( 1 , L_52 , V_10 ) ;
if ( ! V_156 ) {
V_156 = true ;
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_10 ( V_2 , & V_2 -> V_17 [ V_10 ] ) ;
memset ( & V_2 -> V_18 [ V_10 ] , 0 , sizeof( struct V_36 ) ) ;
V_9 = F_4 ( V_2 , V_119 , V_4 -> V_15 [ V_10 ] ,
V_30 , V_17 [ V_10 ] . V_19 , V_6 ) ;
if ( F_70 ( V_9 ) ) {
F_8 ( 1 , L_53 ) ;
V_41 = F_67 ( V_9 ) ;
F_11 ( V_30 ) ;
goto V_157;
}
V_2 -> V_17 [ V_10 ] . V_30 = V_30 ;
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_41 = F_29 ( V_2 , V_120 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
if ( V_41 ) {
F_8 ( 1 , L_54 ,
V_10 ) ;
goto V_157;
}
V_2 -> V_17 [ V_10 ] . V_27 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_156 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_48 ) ;
goto V_157;
}
}
V_41 = F_19 ( V_2 , V_155 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_49 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_157;
}
return 0 ;
V_157:
F_12 ( V_2 ) ;
return V_41 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_10 ;
V_2 -> V_44 = V_102 ;
F_71 ( & V_4 -> V_145 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_159 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_22 ( V_2 , V_160 , V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_41 ;
V_41 = F_27 ( V_2 , V_83 ) ;
if ( V_41 < 0 ) {
F_8 ( 1 , L_55 , V_41 ) ;
return V_41 ;
}
if ( V_83 -> V_153 == V_161 && F_2 ( V_4 -> type ) ) {
F_8 ( 1 , L_56 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_57 ) ;
return - V_162 ;
}
V_2 -> V_44 = V_50 ;
V_2 -> V_22 . V_163 . V_164 = 0 ;
V_2 -> V_22 . V_163 . V_165 = 0 ;
V_2 -> V_22 . V_166 = 0 ;
switch ( V_4 -> V_40 ) {
case V_46 :
V_41 = F_65 ( V_2 , V_83 ) ;
break;
case V_87 :
F_73 ( & V_167 -> V_168 -> V_169 ) ;
V_41 = F_66 ( V_2 , V_83 ) ;
F_74 ( & V_167 -> V_168 -> V_169 ) ;
break;
case V_49 :
V_41 = F_68 ( V_2 , V_83 ) ;
break;
default:
F_75 ( 1 , L_58 ) ;
V_41 = - V_84 ;
}
if ( V_41 )
F_8 ( 1 , L_59 , V_41 ) ;
V_2 -> V_44 = V_41 ? V_45 : V_108 ;
return V_41 ;
}
static int F_76 ( struct V_3 * V_4 , struct V_82 * V_83 ,
const char * V_170 )
{
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_60 , V_170 ) ;
return - V_84 ;
}
if ( V_83 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_61 , V_170 ) ;
return - V_84 ;
}
if ( V_4 -> V_34 [ V_83 -> V_23 ] == NULL ) {
F_8 ( 1 , L_62 , V_170 ) ;
return - V_84 ;
}
if ( V_83 -> V_40 != V_4 -> V_40 ) {
F_8 ( 1 , L_63 , V_170 ) ;
return - V_84 ;
}
return F_26 ( V_4 -> V_34 [ V_83 -> V_23 ] , V_83 ) ;
}
int F_77 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_41 ;
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
V_41 = F_76 ( V_4 , V_83 , L_64 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_83 -> V_23 ] ;
if ( V_2 -> V_44 != V_45 ) {
F_8 ( 1 , L_65 ,
V_2 -> V_44 ) ;
return - V_84 ;
}
V_41 = F_72 ( V_2 , V_83 ) ;
if ( ! V_41 ) {
F_31 ( V_2 , V_83 ) ;
F_8 ( 1 , L_66 , V_2 -> V_22 . V_23 ) ;
}
return V_41 ;
}
static int F_78 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_41 ;
F_61 (vb, &q->queued_list, queued_entry)
F_58 ( V_2 ) ;
V_4 -> V_146 = 1 ;
V_41 = F_45 ( V_4 , V_171 , V_4 ,
F_79 ( & V_4 -> V_145 ) ) ;
if ( ! V_41 )
return 0 ;
V_4 -> V_146 = 0 ;
F_8 ( 1 , L_67 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_145 ) ) ) {
unsigned V_172 ;
for ( V_172 = 0 ; V_172 < V_4 -> V_33 ; ++ V_172 ) {
V_2 = V_4 -> V_34 [ V_172 ] ;
if ( V_2 -> V_44 == V_102 )
F_52 ( V_2 , V_101 ) ;
}
F_53 ( F_79 ( & V_4 -> V_145 ) ) ;
}
F_53 ( ! F_80 ( & V_4 -> V_144 ) ) ;
return V_41 ;
}
static int F_81 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
int V_41 = F_76 ( V_4 , V_83 , L_68 ) ;
struct V_1 * V_2 ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_83 -> V_23 ] ;
switch ( V_2 -> V_44 ) {
case V_45 :
V_41 = F_72 ( V_2 , V_83 ) ;
if ( V_41 )
return V_41 ;
break;
case V_108 :
break;
case V_50 :
F_8 ( 1 , L_69 ) ;
return - V_84 ;
default:
F_8 ( 1 , L_65 , V_2 -> V_44 ) ;
return - V_84 ;
}
F_55 ( & V_2 -> V_173 , & V_4 -> V_81 ) ;
V_4 -> V_174 ++ ;
V_4 -> V_131 = false ;
V_2 -> V_44 = V_101 ;
if ( F_2 ( V_4 -> type ) ) {
if ( ( V_4 -> V_97 & V_98 ) ==
V_99 )
V_2 -> V_22 . V_163 = V_83 -> V_163 ;
V_2 -> V_22 . V_95 |= V_83 -> V_95 & V_152 ;
if ( V_83 -> V_95 & V_152 )
V_2 -> V_22 . V_175 = V_83 -> V_175 ;
}
if ( V_4 -> V_146 )
F_58 ( V_2 ) ;
F_31 ( V_2 , V_83 ) ;
if ( V_4 -> V_126 && ! V_4 -> V_146 &&
V_4 -> V_174 >= V_4 -> V_130 ) {
V_41 = F_78 ( V_4 ) ;
if ( V_41 )
return V_41 ;
}
F_8 ( 1 , L_70 , V_2 -> V_22 . V_23 ) ;
return 0 ;
}
int F_82 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_81 ( V_4 , V_83 ) ;
}
static int F_83 ( struct V_3 * V_4 , int V_176 )
{
for (; ; ) {
int V_41 ;
if ( ! V_4 -> V_126 ) {
F_8 ( 1 , L_71 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_72 ) ;
return - V_162 ;
}
if ( V_4 -> V_177 ) {
F_8 ( 3 , L_73 ) ;
return - V_178 ;
}
if ( ! F_80 ( & V_4 -> V_144 ) ) {
break;
}
if ( V_176 ) {
F_8 ( 1 , L_74
L_75 ) ;
return - V_51 ;
}
F_84 ( V_4 , V_179 , V_4 ) ;
F_8 ( 3 , L_76 ) ;
V_41 = F_85 ( V_4 -> V_147 ,
! F_80 ( & V_4 -> V_144 ) || ! V_4 -> V_126 ||
V_4 -> error ) ;
F_84 ( V_4 , V_180 , V_4 ) ;
if ( V_41 ) {
F_8 ( 1 , L_77 ) ;
return V_41 ;
}
}
return 0 ;
}
static int F_86 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_82 * V_83 , int V_176 )
{
unsigned long V_95 ;
int V_41 ;
V_41 = F_83 ( V_4 , V_176 ) ;
if ( V_41 )
return V_41 ;
F_54 ( & V_4 -> V_142 , V_95 ) ;
* V_2 = F_87 ( & V_4 -> V_144 , struct V_1 , V_143 ) ;
V_41 = F_26 ( * V_2 , V_83 ) ;
if ( ! V_41 )
F_88 ( & ( * V_2 ) -> V_143 ) ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
return V_41 ;
}
int F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_126 ) {
F_8 ( 1 , L_71 ) ;
return - V_84 ;
}
if ( V_4 -> V_146 )
F_90 ( V_4 -> V_147 , ! F_79 ( & V_4 -> V_145 ) ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_172 ;
if ( V_2 -> V_44 == V_45 )
return;
V_2 -> V_44 = V_45 ;
if ( V_4 -> V_40 == V_49 )
for ( V_172 = 0 ; V_172 < V_2 -> V_11 ; ++ V_172 ) {
if ( ! V_2 -> V_17 [ V_172 ] . V_27 )
continue;
F_6 ( V_2 , V_28 , V_2 -> V_17 [ V_172 ] . V_9 ) ;
V_2 -> V_17 [ V_172 ] . V_27 = 0 ;
}
}
static int F_92 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_176 )
{
struct V_1 * V_2 = NULL ;
int V_41 ;
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_78 ) ;
return - V_84 ;
}
V_41 = F_86 ( V_4 , & V_2 , V_83 , V_176 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_2 -> V_44 ) {
case V_106 :
F_8 ( 3 , L_79 ) ;
break;
case V_104 :
F_8 ( 3 , L_80 ) ;
break;
default:
F_8 ( 1 , L_81 ) ;
return - V_84 ;
}
F_22 ( V_2 , V_181 , V_2 ) ;
F_31 ( V_2 , V_83 ) ;
F_88 ( & V_2 -> V_173 ) ;
V_4 -> V_174 -- ;
if ( ! F_2 ( V_4 -> type ) &&
V_2 -> V_22 . V_95 & V_182 )
V_4 -> V_177 = true ;
F_91 ( V_2 ) ;
F_8 ( 1 , L_82 ,
V_2 -> V_22 . V_23 , V_2 -> V_44 ) ;
return 0 ;
}
int F_93 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_176 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_92 ( V_4 , V_83 , V_176 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
unsigned int V_172 ;
if ( V_4 -> V_146 )
F_84 ( V_4 , V_183 , V_4 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_145 ) ) ) {
for ( V_172 = 0 ; V_172 < V_4 -> V_33 ; ++ V_172 )
if ( V_4 -> V_34 [ V_172 ] -> V_44 == V_102 )
F_52 ( V_4 -> V_34 [ V_172 ] , V_104 ) ;
F_53 ( F_79 ( & V_4 -> V_145 ) ) ;
}
V_4 -> V_126 = 0 ;
V_4 -> V_146 = 0 ;
V_4 -> V_174 = 0 ;
V_4 -> error = 0 ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_144 ) ;
F_94 ( & V_4 -> V_145 , 0 ) ;
F_95 ( & V_4 -> V_147 ) ;
for ( V_172 = 0 ; V_172 < V_4 -> V_33 ; ++ V_172 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_172 ] ;
if ( V_2 -> V_44 != V_45 ) {
V_2 -> V_44 = V_108 ;
F_22 ( V_2 , V_181 , V_2 ) ;
}
F_91 ( V_2 ) ;
}
}
static int F_96 ( struct V_3 * V_4 , enum V_121 type )
{
int V_41 ;
if ( type != V_4 -> type ) {
F_8 ( 1 , L_83 ) ;
return - V_84 ;
}
if ( V_4 -> V_126 ) {
F_8 ( 3 , L_84 ) ;
return 0 ;
}
if ( ! V_4 -> V_33 ) {
F_8 ( 1 , L_85 ) ;
return - V_84 ;
}
if ( V_4 -> V_33 < V_4 -> V_130 ) {
F_8 ( 1 , L_86 ,
V_4 -> V_130 ) ;
return - V_84 ;
}
if ( V_4 -> V_174 >= V_4 -> V_130 ) {
V_41 = F_78 ( V_4 ) ;
if ( V_41 ) {
F_42 ( V_4 ) ;
return V_41 ;
}
}
V_4 -> V_126 = 1 ;
F_8 ( 3 , L_87 ) ;
return 0 ;
}
void F_97 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_95 ( & V_4 -> V_147 ) ;
}
int F_98 ( struct V_3 * V_4 , enum V_121 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_96 ( V_4 , type ) ;
}
static int F_99 ( struct V_3 * V_4 , enum V_121 type )
{
if ( type != V_4 -> type ) {
F_8 ( 1 , L_83 ) ;
return - V_84 ;
}
F_42 ( V_4 ) ;
V_4 -> V_131 = ! F_2 ( V_4 -> type ) ;
V_4 -> V_177 = false ;
F_8 ( 3 , L_87 ) ;
return 0 ;
}
int F_100 ( struct V_3 * V_4 , enum V_121 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_99 ( V_4 , type ) ;
}
static int F_101 ( struct V_3 * V_4 , unsigned long V_35 ,
unsigned int * V_184 , unsigned int * V_185 )
{
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_38 == V_35 ) {
* V_184 = V_32 ;
* V_185 = V_10 ;
return 0 ;
}
}
}
return - V_84 ;
}
int F_102 ( struct V_3 * V_4 , struct V_186 * V_187 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_188 ;
int V_41 ;
struct V_158 * V_30 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
if ( ! V_4 -> V_114 -> V_189 ) {
F_8 ( 1 , L_89 ) ;
return - V_84 ;
}
if ( V_187 -> V_95 & ~ ( V_190 | V_191 ) ) {
F_8 ( 1 , L_90 ) ;
return - V_84 ;
}
if ( V_187 -> type != V_4 -> type ) {
F_8 ( 1 , L_78 ) ;
return - V_84 ;
}
if ( V_187 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_27 ) ;
return - V_84 ;
}
V_2 = V_4 -> V_34 [ V_187 -> V_23 ] ;
if ( V_187 -> V_10 >= V_2 -> V_11 ) {
F_8 ( 1 , L_91 ) ;
return - V_84 ;
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_92 ) ;
return - V_122 ;
}
V_188 = & V_2 -> V_17 [ V_187 -> V_10 ] ;
V_30 = F_4 ( V_2 , V_189 , V_188 -> V_9 , V_187 -> V_95 & V_191 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_93 ,
V_187 -> V_23 , V_187 -> V_10 ) ;
return - V_84 ;
}
V_41 = F_103 ( V_30 , V_187 -> V_95 & ~ V_191 ) ;
if ( V_41 < 0 ) {
F_8 ( 3 , L_94 ,
V_187 -> V_23 , V_187 -> V_10 , V_41 ) ;
F_11 ( V_30 ) ;
return V_41 ;
}
F_8 ( 3 , L_95 ,
V_187 -> V_23 , V_187 -> V_10 , V_41 ) ;
V_187 -> V_94 = V_41 ;
return 0 ;
}
int F_104 ( struct V_3 * V_4 , struct V_192 * V_193 )
{
unsigned long V_35 = V_193 -> V_194 << V_195 ;
struct V_1 * V_2 ;
unsigned int V_32 = 0 , V_10 = 0 ;
int V_41 ;
unsigned long V_19 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
if ( ! ( V_193 -> V_196 & V_197 ) ) {
F_8 ( 1 , L_96 ) ;
return - V_84 ;
}
if ( F_2 ( V_4 -> type ) ) {
if ( ! ( V_193 -> V_196 & V_198 ) ) {
F_8 ( 1 , L_97 ) ;
return - V_84 ;
}
} else {
if ( ! ( V_193 -> V_196 & V_199 ) ) {
F_8 ( 1 , L_98 ) ;
return - V_84 ;
}
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_99 ) ;
return - V_122 ;
}
V_41 = F_101 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_19 = F_3 ( V_2 -> V_18 [ V_10 ] . V_19 ) ;
if ( V_19 < ( V_193 -> V_200 - V_193 -> V_201 ) ) {
F_8 ( 1 ,
L_100 ) ;
return - V_84 ;
}
F_40 ( & V_4 -> V_128 ) ;
V_41 = F_29 ( V_2 , V_117 , V_2 -> V_17 [ V_10 ] . V_9 , V_193 ) ;
F_41 ( & V_4 -> V_128 ) ;
if ( V_41 )
return V_41 ;
F_8 ( 3 , L_101 , V_32 , V_10 ) ;
return 0 ;
}
unsigned long F_105 ( struct V_3 * V_4 ,
unsigned long V_202 ,
unsigned long V_203 ,
unsigned long V_204 ,
unsigned long V_95 )
{
unsigned long V_35 = V_204 << V_195 ;
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
void * V_138 ;
int V_41 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
V_41 = F_101 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_138 = F_50 ( V_2 , V_10 ) ;
return V_138 ? ( unsigned long ) V_138 : - V_84 ;
}
unsigned int F_106 ( struct V_3 * V_4 , struct V_205 * V_205 , T_1 * V_206 )
{
struct V_207 * V_208 = F_107 ( V_205 ) ;
unsigned long V_209 = F_108 ( V_206 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_210 = 0 ;
unsigned long V_95 ;
if ( F_109 ( V_211 , & V_208 -> V_95 ) ) {
struct V_212 * V_213 = V_205 -> V_214 ;
if ( F_110 ( V_213 ) )
V_210 = V_215 ;
else if ( V_209 & V_215 )
F_111 ( V_205 , & V_213 -> V_206 , V_206 ) ;
}
if ( ! F_2 ( V_4 -> type ) && ! ( V_209 & ( V_216 | V_217 ) ) )
return V_210 ;
if ( F_2 ( V_4 -> type ) && ! ( V_209 & ( V_218 | V_219 ) ) )
return V_210 ;
if ( V_4 -> V_33 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_2 ( V_4 -> type ) && ( V_4 -> V_112 & V_220 ) &&
( V_209 & ( V_216 | V_217 ) ) ) {
if ( F_112 ( V_4 , 1 ) )
return V_210 | V_221 ;
}
if ( F_2 ( V_4 -> type ) && ( V_4 -> V_112 & V_222 ) &&
( V_209 & ( V_218 | V_219 ) ) ) {
if ( F_112 ( V_4 , 0 ) )
return V_210 | V_221 ;
return V_210 | V_218 | V_219 ;
}
}
if ( ! F_113 ( V_4 ) || V_4 -> error )
return V_210 | V_221 ;
if ( V_4 -> V_131 )
return V_210 | V_221 ;
if ( F_2 ( V_4 -> type ) && V_4 -> V_174 < V_4 -> V_33 )
return V_210 | V_218 | V_219 ;
if ( F_80 ( & V_4 -> V_144 ) ) {
if ( V_4 -> V_177 )
return V_210 | V_216 | V_217 ;
F_111 ( V_205 , & V_4 -> V_147 , V_206 ) ;
}
F_54 ( & V_4 -> V_142 , V_95 ) ;
if ( ! F_80 ( & V_4 -> V_144 ) )
V_2 = F_87 ( & V_4 -> V_144 , struct V_1 ,
V_143 ) ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
if ( V_2 && ( V_2 -> V_44 == V_106
|| V_2 -> V_44 == V_104 ) ) {
return ( F_2 ( V_4 -> type ) ) ?
V_210 | V_218 | V_219 :
V_210 | V_216 | V_217 ;
}
return V_210 ;
}
int F_114 ( struct V_3 * V_4 )
{
if ( F_53 ( ! V_4 ) ||
F_53 ( ! V_4 -> V_223 ) ||
F_53 ( ! V_4 -> V_114 ) ||
F_53 ( ! V_4 -> type ) ||
F_53 ( ! V_4 -> V_112 ) ||
F_53 ( ! V_4 -> V_223 -> V_129 ) ||
F_53 ( ! V_4 -> V_223 -> V_160 ) ||
F_53 ( V_4 -> V_97 &
~ ( V_98 |
V_100 ) ) )
return - V_84 ;
F_53 ( ( V_4 -> V_97 & V_98 ) ==
V_224 ) ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_144 ) ;
F_115 ( & V_4 -> V_142 ) ;
F_116 ( & V_4 -> V_128 ) ;
F_117 ( & V_4 -> V_147 ) ;
if ( V_4 -> V_42 == 0 )
V_4 -> V_42 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_118 ( struct V_3 * V_4 )
{
F_119 ( V_4 ) ;
F_42 ( V_4 ) ;
F_40 ( & V_4 -> V_128 ) ;
F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_128 ) ;
}
static int F_112 ( struct V_3 * V_4 , int V_225 )
{
struct V_226 * V_227 ;
int V_172 , V_41 ;
unsigned int V_127 = 0 ;
if ( F_53 ( ( V_225 && ! ( V_4 -> V_112 & V_220 ) ) ||
( ! V_225 && ! ( V_4 -> V_112 & V_222 ) ) ) )
return - V_84 ;
if ( ! V_4 -> V_114 -> V_138 )
return - V_122 ;
if ( V_4 -> V_126 || V_4 -> V_33 > 0 )
return - V_122 ;
V_127 = 1 ;
F_8 ( 3 , L_102 ,
( V_225 ) ? L_103 : L_104 , V_127 , V_4 -> V_228 ,
V_4 -> V_229 ) ;
V_227 = F_16 ( sizeof( struct V_226 ) , V_43 ) ;
if ( V_227 == NULL )
return - V_21 ;
V_227 -> V_230 = V_4 -> V_228 ;
V_227 -> V_231 = V_4 -> V_229 ;
V_227 -> V_124 . V_127 = V_127 ;
V_227 -> V_124 . V_40 = V_46 ;
V_227 -> V_124 . type = V_4 -> type ;
V_4 -> V_227 = V_227 ;
V_41 = F_39 ( V_4 , & V_227 -> V_124 ) ;
if ( V_41 )
goto V_232;
if ( V_4 -> V_34 [ 0 ] -> V_11 != 1 ) {
V_41 = - V_122 ;
goto V_233;
}
for ( V_172 = 0 ; V_172 < V_4 -> V_33 ; V_172 ++ ) {
V_227 -> V_34 [ V_172 ] . V_138 = F_50 ( V_4 -> V_34 [ V_172 ] , 0 ) ;
if ( V_227 -> V_34 [ V_172 ] . V_138 == NULL ) {
V_41 = - V_84 ;
goto V_233;
}
V_227 -> V_34 [ V_172 ] . V_12 = F_120 ( V_4 -> V_34 [ V_172 ] , 0 ) ;
}
if ( V_225 ) {
bool V_234 = F_17 ( V_4 -> type ) ;
for ( V_172 = 0 ; V_172 < V_4 -> V_33 ; V_172 ++ ) {
struct V_82 * V_83 = & V_227 -> V_83 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> type = V_4 -> type ;
if ( V_234 ) {
memset ( & V_227 -> V_26 , 0 , sizeof( V_227 -> V_26 ) ) ;
V_83 -> V_37 . V_17 = & V_227 -> V_26 ;
V_83 -> V_19 = 1 ;
}
V_83 -> V_40 = V_4 -> V_40 ;
V_83 -> V_23 = V_172 ;
V_41 = F_81 ( V_4 , V_83 ) ;
if ( V_41 )
goto V_233;
V_227 -> V_34 [ V_172 ] . V_235 = 1 ;
}
V_227 -> V_236 = V_4 -> V_33 ;
V_227 -> V_237 = V_4 -> V_33 ;
}
V_41 = F_96 ( V_4 , V_4 -> type ) ;
if ( V_41 )
goto V_233;
return V_41 ;
V_233:
V_227 -> V_124 . V_127 = 0 ;
F_39 ( V_4 , & V_227 -> V_124 ) ;
V_232:
V_4 -> V_227 = NULL ;
F_18 ( V_227 ) ;
return V_41 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_226 * V_227 = V_4 -> V_227 ;
if ( V_227 ) {
F_99 ( V_4 , V_4 -> type ) ;
V_4 -> V_227 = NULL ;
V_227 -> V_124 . V_127 = 0 ;
F_46 ( V_4 , & V_227 -> V_124 ) ;
F_18 ( V_227 ) ;
F_8 ( 3 , L_105 ) ;
}
return 0 ;
}
static T_2 F_121 ( struct V_3 * V_4 , char T_3 * V_238 , T_2 V_127 ,
T_4 * V_239 , int V_240 , int V_225 )
{
struct V_226 * V_227 ;
struct V_241 * V_242 ;
bool V_234 = F_17 ( V_4 -> type ) ;
bool V_243 = ! V_225 &&
( V_4 -> V_97 & V_98 ) ==
V_99 ;
int V_41 , V_23 ;
F_8 ( 3 , L_106 ,
V_225 ? L_103 : L_104 , ( long ) * V_239 , V_127 ,
V_240 ? L_107 : L_12 ) ;
if ( ! V_238 )
return - V_84 ;
if ( ! F_38 ( V_4 ) ) {
V_41 = F_112 ( V_4 , V_225 ) ;
F_8 ( 3 , L_108 , V_41 ) ;
if ( V_41 )
return V_41 ;
}
V_227 = V_4 -> V_227 ;
V_23 = V_227 -> V_237 ;
if ( V_23 >= V_4 -> V_33 ) {
memset ( & V_227 -> V_83 , 0 , sizeof( V_227 -> V_83 ) ) ;
V_227 -> V_83 . type = V_4 -> type ;
V_227 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_234 ) {
memset ( & V_227 -> V_26 , 0 , sizeof( V_227 -> V_26 ) ) ;
V_227 -> V_83 . V_37 . V_17 = & V_227 -> V_26 ;
V_227 -> V_83 . V_19 = 1 ;
}
V_41 = F_92 ( V_4 , & V_227 -> V_83 , V_240 ) ;
F_8 ( 5 , L_109 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_227 -> V_244 += 1 ;
V_227 -> V_237 = V_23 = V_227 -> V_83 . V_23 ;
V_242 = & V_227 -> V_34 [ V_23 ] ;
V_242 -> V_245 = 0 ;
V_242 -> V_235 = 0 ;
V_242 -> V_12 = V_225 ? F_122 ( V_4 -> V_34 [ V_23 ] , 0 )
: F_120 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
if ( V_234 && V_225 &&
V_227 -> V_83 . V_37 . V_17 [ 0 ] . V_88 < V_242 -> V_12 ) {
V_242 -> V_245 = V_227 -> V_83 . V_37 . V_17 [ 0 ] . V_88 ;
V_242 -> V_12 -= V_242 -> V_245 ;
}
} else {
V_242 = & V_227 -> V_34 [ V_23 ] ;
}
if ( V_242 -> V_245 + V_127 > V_242 -> V_12 ) {
V_127 = V_242 -> V_12 - V_242 -> V_245 ;
F_8 ( 5 , L_110 , V_127 ) ;
}
F_8 ( 3 , L_111 ,
V_127 , V_23 , V_242 -> V_245 ) ;
if ( V_225 )
V_41 = F_123 ( V_238 , V_242 -> V_138 + V_242 -> V_245 , V_127 ) ;
else
V_41 = F_124 ( V_242 -> V_138 + V_242 -> V_245 , V_238 , V_127 ) ;
if ( V_41 ) {
F_8 ( 3 , L_112 ) ;
return - V_246 ;
}
V_242 -> V_245 += V_127 ;
* V_239 += V_127 ;
if ( V_242 -> V_245 == V_242 -> V_12 || ( ! V_225 && V_227 -> V_231 ) ) {
if ( V_225 && V_227 -> V_230 && V_227 -> V_244 == 1 ) {
F_8 ( 3 , L_113 ) ;
return F_119 ( V_4 ) ;
}
memset ( & V_227 -> V_83 , 0 , sizeof( V_227 -> V_83 ) ) ;
V_227 -> V_83 . type = V_4 -> type ;
V_227 -> V_83 . V_40 = V_4 -> V_40 ;
V_227 -> V_83 . V_23 = V_23 ;
V_227 -> V_83 . V_86 = V_242 -> V_245 ;
if ( V_234 ) {
memset ( & V_227 -> V_26 , 0 , sizeof( V_227 -> V_26 ) ) ;
V_227 -> V_26 . V_86 = V_242 -> V_245 ;
V_227 -> V_83 . V_37 . V_17 = & V_227 -> V_26 ;
V_227 -> V_83 . V_19 = 1 ;
}
if ( V_243 )
F_125 ( & V_227 -> V_83 . V_163 ) ;
V_41 = F_81 ( V_4 , & V_227 -> V_83 ) ;
F_8 ( 5 , L_114 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_242 -> V_245 = 0 ;
V_242 -> V_235 = 1 ;
V_242 -> V_12 = F_120 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
V_227 -> V_247 += 1 ;
if ( V_227 -> V_236 < V_4 -> V_33 )
V_227 -> V_236 ++ ;
V_227 -> V_237 = V_227 -> V_236 ;
}
if ( V_41 == 0 )
V_41 = V_127 ;
return V_41 ;
}
T_2 F_126 ( struct V_3 * V_4 , char T_3 * V_238 , T_2 V_127 ,
T_4 * V_239 , int V_176 )
{
return F_121 ( V_4 , V_238 , V_127 , V_239 , V_176 , 1 ) ;
}
T_2 F_127 ( struct V_3 * V_4 , const char T_3 * V_238 , T_2 V_127 ,
T_4 * V_239 , int V_176 )
{
return F_121 ( V_4 , ( char T_3 * ) V_238 , V_127 ,
V_239 , V_176 , 0 ) ;
}
static int F_128 ( void * V_238 )
{
struct V_3 * V_4 = V_238 ;
struct V_248 * V_249 = V_4 -> V_249 ;
struct V_226 * V_227 = V_4 -> V_227 ;
bool V_243 = false ;
int V_250 = 0 ;
int V_23 = 0 ;
int V_41 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
V_250 = V_4 -> V_33 ;
V_243 =
( V_4 -> V_97 & V_98 ) ==
V_99 ;
}
F_129 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_227 -> V_83 , 0 , sizeof( V_227 -> V_83 ) ) ;
V_227 -> V_83 . type = V_4 -> type ;
V_227 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_250 ) {
V_227 -> V_83 . V_23 = V_23 ++ ;
V_250 -- ;
} else {
F_84 ( V_4 , V_180 , V_4 ) ;
if ( ! V_249 -> V_251 )
V_41 = F_92 ( V_4 , & V_227 -> V_83 , 0 ) ;
F_84 ( V_4 , V_179 , V_4 ) ;
F_8 ( 5 , L_115 , V_41 ) ;
}
if ( V_41 || V_249 -> V_251 )
break;
F_130 () ;
V_2 = V_4 -> V_34 [ V_227 -> V_83 . V_23 ] ;
if ( ! ( V_227 -> V_83 . V_95 & V_105 ) )
if ( V_249 -> V_252 ( V_2 , V_249 -> V_253 ) )
break;
F_84 ( V_4 , V_180 , V_4 ) ;
if ( V_243 )
F_125 ( & V_227 -> V_83 . V_163 ) ;
if ( ! V_249 -> V_251 )
V_41 = F_81 ( V_4 , & V_227 -> V_83 ) ;
F_84 ( V_4 , V_179 , V_4 ) ;
if ( V_41 || V_249 -> V_251 )
break;
}
while ( ! F_131 () ) {
F_132 ( V_254 ) ;
F_133 () ;
}
return 0 ;
}
int F_134 ( struct V_3 * V_4 , T_5 V_252 , void * V_253 ,
const char * V_255 )
{
struct V_248 * V_249 ;
int V_41 = 0 ;
if ( V_4 -> V_249 )
return - V_122 ;
if ( F_135 ( V_4 ) )
return - V_122 ;
if ( F_53 ( V_4 -> V_227 ) )
return - V_122 ;
V_249 = F_16 ( sizeof( * V_249 ) , V_43 ) ;
if ( V_249 == NULL )
return - V_21 ;
V_249 -> V_252 = V_252 ;
V_249 -> V_253 = V_253 ;
V_41 = F_112 ( V_4 , ! F_2 ( V_4 -> type ) ) ;
F_8 ( 3 , L_116 , V_41 ) ;
if ( V_41 )
goto V_256;
V_4 -> V_249 = V_249 ;
V_249 -> V_257 = F_136 ( F_128 , V_4 , L_117 , V_255 ) ;
if ( F_70 ( V_249 -> V_257 ) ) {
V_41 = F_67 ( V_249 -> V_257 ) ;
V_249 -> V_257 = NULL ;
goto V_258;
}
return 0 ;
V_258:
F_119 ( V_4 ) ;
V_256:
F_18 ( V_249 ) ;
return V_41 ;
}
int F_137 ( struct V_3 * V_4 )
{
struct V_248 * V_249 = V_4 -> V_249 ;
int V_157 ;
if ( V_249 == NULL )
return 0 ;
V_249 -> V_251 = true ;
F_97 ( V_4 ) ;
V_157 = F_138 ( V_249 -> V_257 ) ;
F_119 ( V_4 ) ;
V_249 -> V_257 = NULL ;
F_18 ( V_249 ) ;
V_4 -> V_249 = NULL ;
return V_157 ;
}
static inline bool F_139 ( struct V_207 * V_259 , struct V_205 * V_205 )
{
return V_259 -> V_260 -> V_261 && V_259 -> V_260 -> V_261 != V_205 -> V_214 ;
}
int F_140 ( struct V_205 * V_205 , void * V_253 ,
struct V_123 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
int V_210 = F_37 ( V_259 -> V_260 , V_26 -> V_40 , V_26 -> type ) ;
if ( V_210 )
return V_210 ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
V_210 = F_39 ( V_259 -> V_260 , V_26 ) ;
if ( V_210 == 0 )
V_259 -> V_260 -> V_261 = V_26 -> V_127 ? V_205 -> V_214 : NULL ;
return V_210 ;
}
int F_141 ( struct V_205 * V_205 , void * V_253 ,
struct V_132 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
int V_210 = F_37 ( V_259 -> V_260 , V_26 -> V_40 , V_26 -> V_136 . type ) ;
V_26 -> V_23 = V_259 -> V_260 -> V_33 ;
if ( V_26 -> V_127 == 0 )
return V_210 != - V_122 ? V_210 : 0 ;
if ( V_210 )
return V_210 ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
V_210 = F_47 ( V_259 -> V_260 , V_26 ) ;
if ( V_210 == 0 )
V_259 -> V_260 -> V_261 = V_205 -> V_214 ;
return V_210 ;
}
int F_142 ( struct V_205 * V_205 , void * V_253 ,
struct V_82 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_77 ( V_259 -> V_260 , V_26 ) ;
}
int F_143 ( struct V_205 * V_205 , void * V_253 , struct V_82 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
return F_33 ( V_259 -> V_260 , V_26 ) ;
}
int F_144 ( struct V_205 * V_205 , void * V_253 , struct V_82 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_82 ( V_259 -> V_260 , V_26 ) ;
}
int F_145 ( struct V_205 * V_205 , void * V_253 , struct V_82 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_93 ( V_259 -> V_260 , V_26 , V_205 -> V_262 & V_263 ) ;
}
int F_146 ( struct V_205 * V_205 , void * V_253 , enum V_121 V_172 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_98 ( V_259 -> V_260 , V_172 ) ;
}
int F_147 ( struct V_205 * V_205 , void * V_253 , enum V_121 V_172 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_100 ( V_259 -> V_260 , V_172 ) ;
}
int F_148 ( struct V_205 * V_205 , void * V_253 , struct V_186 * V_26 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( F_139 ( V_259 , V_205 ) )
return - V_122 ;
return F_102 ( V_259 -> V_260 , V_26 ) ;
}
int F_149 ( struct V_205 * V_205 , struct V_192 * V_193 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
return F_104 ( V_259 -> V_260 , V_193 ) ;
}
int F_150 ( struct V_205 * V_205 , struct V_264 * V_265 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
if ( V_265 )
F_40 ( V_265 ) ;
if ( V_205 -> V_214 == V_259 -> V_260 -> V_261 ) {
F_118 ( V_259 -> V_260 ) ;
V_259 -> V_260 -> V_261 = NULL ;
}
if ( V_265 )
F_41 ( V_265 ) ;
return F_151 ( V_205 ) ;
}
int F_152 ( struct V_205 * V_205 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
struct V_264 * V_265 = V_259 -> V_260 -> V_265 ? V_259 -> V_260 -> V_265 : V_259 -> V_265 ;
return F_150 ( V_205 , V_265 ) ;
}
T_6 F_153 ( struct V_205 * V_205 , const char T_3 * V_242 ,
T_2 V_127 , T_4 * V_239 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
struct V_264 * V_265 = V_259 -> V_260 -> V_265 ? V_259 -> V_260 -> V_265 : V_259 -> V_265 ;
int V_157 = - V_122 ;
if ( ! ( V_259 -> V_260 -> V_112 & V_222 ) )
return - V_84 ;
if ( V_265 && F_154 ( V_265 ) )
return - V_266 ;
if ( F_139 ( V_259 , V_205 ) )
goto exit;
V_157 = F_127 ( V_259 -> V_260 , V_242 , V_127 , V_239 ,
V_205 -> V_262 & V_263 ) ;
if ( V_259 -> V_260 -> V_227 )
V_259 -> V_260 -> V_261 = V_205 -> V_214 ;
exit:
if ( V_265 )
F_41 ( V_265 ) ;
return V_157 ;
}
T_6 F_155 ( struct V_205 * V_205 , char T_3 * V_242 ,
T_2 V_127 , T_4 * V_239 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
struct V_264 * V_265 = V_259 -> V_260 -> V_265 ? V_259 -> V_260 -> V_265 : V_259 -> V_265 ;
int V_157 = - V_122 ;
if ( ! ( V_259 -> V_260 -> V_112 & V_220 ) )
return - V_84 ;
if ( V_265 && F_154 ( V_265 ) )
return - V_266 ;
if ( F_139 ( V_259 , V_205 ) )
goto exit;
V_157 = F_126 ( V_259 -> V_260 , V_242 , V_127 , V_239 ,
V_205 -> V_262 & V_263 ) ;
if ( V_259 -> V_260 -> V_227 )
V_259 -> V_260 -> V_261 = V_205 -> V_214 ;
exit:
if ( V_265 )
F_41 ( V_265 ) ;
return V_157 ;
}
unsigned int F_156 ( struct V_205 * V_205 , T_1 * V_206 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
struct V_3 * V_4 = V_259 -> V_260 ;
struct V_264 * V_265 = V_4 -> V_265 ? V_4 -> V_265 : V_259 -> V_265 ;
unsigned V_210 ;
void * V_227 ;
F_53 ( ! V_265 ) ;
if ( V_265 && F_154 ( V_265 ) )
return V_221 ;
V_227 = V_4 -> V_227 ;
V_210 = F_106 ( V_259 -> V_260 , V_205 , V_206 ) ;
if ( ! V_227 && V_4 -> V_227 )
V_4 -> V_261 = V_205 -> V_214 ;
if ( V_265 )
F_41 ( V_265 ) ;
return V_210 ;
}
unsigned long F_157 ( struct V_205 * V_205 , unsigned long V_202 ,
unsigned long V_203 , unsigned long V_204 , unsigned long V_95 )
{
struct V_207 * V_259 = F_107 ( V_205 ) ;
return F_105 ( V_259 -> V_260 , V_202 , V_203 , V_204 , V_95 ) ;
}
void F_158 ( struct V_3 * V_267 )
{
F_41 ( V_267 -> V_265 ) ;
}
void F_159 ( struct V_3 * V_267 )
{
F_40 ( V_267 -> V_265 ) ;
}
