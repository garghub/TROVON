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
F_58 ( V_4 , V_2 ) ;
switch ( V_44 ) {
case V_101 :
return;
case V_110 :
if ( V_4 -> V_146 )
F_59 ( V_2 ) ;
return;
default:
F_60 ( & V_4 -> V_147 ) ;
break;
}
}
void F_61 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_95 ;
F_54 ( & V_4 -> V_142 , V_95 ) ;
F_62 (vb, &q->done_list, done_entry)
V_2 -> V_44 = V_104 ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
static bool V_148 ;
if ( V_148 )
return;
V_148 = true ;
F_53 ( 1 ) ;
F_64 ( L_39 ) ;
if ( V_2 -> V_3 -> V_149 )
F_64 ( L_40 ) ;
else
F_64 ( L_41 ) ;
}
static void F_65 ( struct V_1 * V_2 , const struct V_82 * V_83 ,
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
F_63 ( V_2 ) ;
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
F_63 ( V_2 ) ;
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
static int F_66 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
F_65 ( V_2 , V_83 , V_2 -> V_18 ) ;
return F_19 ( V_2 , V_155 , V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 , const struct V_82 * V_83 )
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
F_65 ( V_2 , V_83 , V_17 ) ;
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
V_41 = V_9 ? F_68 ( V_9 ) : - V_84 ;
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
static int F_69 ( struct V_1 * V_2 , const struct V_82 * V_83 )
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
F_65 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
struct V_158 * V_30 = F_70 ( V_17 [ V_10 ] . V_37 . V_94 ) ;
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
if ( F_71 ( V_9 ) ) {
F_8 ( 1 , L_53 ) ;
V_41 = F_68 ( V_9 ) ;
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
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_10 ;
V_2 -> V_44 = V_102 ;
F_72 ( & V_4 -> V_145 ) ;
F_73 ( V_4 , V_2 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_159 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_22 ( V_2 , V_160 , V_2 ) ;
}
static int F_74 ( struct V_1 * V_2 , const struct V_82 * V_83 )
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
V_41 = F_66 ( V_2 , V_83 ) ;
break;
case V_87 :
V_41 = F_67 ( V_2 , V_83 ) ;
break;
case V_49 :
V_41 = F_69 ( V_2 , V_83 ) ;
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
const char * V_167 )
{
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_60 , V_167 ) ;
return - V_84 ;
}
if ( V_83 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_61 , V_167 ) ;
return - V_84 ;
}
if ( V_4 -> V_34 [ V_83 -> V_23 ] == NULL ) {
F_8 ( 1 , L_62 , V_167 ) ;
return - V_84 ;
}
if ( V_83 -> V_40 != V_4 -> V_40 ) {
F_8 ( 1 , L_63 , V_167 ) ;
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
V_41 = F_74 ( V_2 , V_83 ) ;
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
F_62 (vb, &q->queued_list, queued_entry)
F_59 ( V_2 ) ;
V_4 -> V_146 = 1 ;
V_41 = F_45 ( V_4 , V_168 , V_4 ,
F_79 ( & V_4 -> V_145 ) ) ;
if ( ! V_41 )
return 0 ;
V_4 -> V_146 = 0 ;
F_8 ( 1 , L_67 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_145 ) ) ) {
unsigned V_169 ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 ) {
V_2 = V_4 -> V_34 [ V_169 ] ;
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
V_41 = F_74 ( V_2 , V_83 ) ;
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
F_55 ( & V_2 -> V_170 , & V_4 -> V_81 ) ;
V_4 -> V_171 ++ ;
V_4 -> V_131 = false ;
V_2 -> V_44 = V_101 ;
if ( F_2 ( V_4 -> type ) ) {
if ( ( V_4 -> V_97 & V_98 ) ==
V_99 )
V_2 -> V_22 . V_163 = V_83 -> V_163 ;
V_2 -> V_22 . V_95 |= V_83 -> V_95 & V_152 ;
if ( V_83 -> V_95 & V_152 )
V_2 -> V_22 . V_172 = V_83 -> V_172 ;
}
F_82 ( V_4 , V_2 ) ;
if ( V_4 -> V_146 )
F_59 ( V_2 ) ;
F_31 ( V_2 , V_83 ) ;
if ( V_4 -> V_126 && ! V_4 -> V_146 &&
V_4 -> V_171 >= V_4 -> V_130 ) {
V_41 = F_78 ( V_4 ) ;
if ( V_41 )
return V_41 ;
}
F_8 ( 1 , L_70 , V_2 -> V_22 . V_23 ) ;
return 0 ;
}
int F_83 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_81 ( V_4 , V_83 ) ;
}
static int F_84 ( struct V_3 * V_4 , int V_173 )
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
if ( V_4 -> V_174 ) {
F_8 ( 3 , L_73 ) ;
return - V_175 ;
}
if ( ! F_80 ( & V_4 -> V_144 ) ) {
break;
}
if ( V_173 ) {
F_8 ( 1 , L_74
L_75 ) ;
return - V_51 ;
}
F_85 ( V_4 , V_176 , V_4 ) ;
F_8 ( 3 , L_76 ) ;
V_41 = F_86 ( V_4 -> V_147 ,
! F_80 ( & V_4 -> V_144 ) || ! V_4 -> V_126 ||
V_4 -> error ) ;
F_85 ( V_4 , V_177 , V_4 ) ;
if ( V_41 ) {
F_8 ( 1 , L_77 ) ;
return V_41 ;
}
}
return 0 ;
}
static int F_87 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_82 * V_83 , int V_173 )
{
unsigned long V_95 ;
int V_41 ;
V_41 = F_84 ( V_4 , V_173 ) ;
if ( V_41 )
return V_41 ;
F_54 ( & V_4 -> V_142 , V_95 ) ;
* V_2 = F_88 ( & V_4 -> V_144 , struct V_1 , V_143 ) ;
V_41 = F_26 ( * V_2 , V_83 ) ;
if ( ! V_41 )
F_89 ( & ( * V_2 ) -> V_143 ) ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
return V_41 ;
}
int F_90 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_126 ) {
F_8 ( 1 , L_71 ) ;
return - V_84 ;
}
if ( V_4 -> V_146 )
F_91 ( V_4 -> V_147 , ! F_79 ( & V_4 -> V_145 ) ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_169 ;
if ( V_2 -> V_44 == V_45 )
return;
V_2 -> V_44 = V_45 ;
if ( V_4 -> V_40 == V_49 )
for ( V_169 = 0 ; V_169 < V_2 -> V_11 ; ++ V_169 ) {
if ( ! V_2 -> V_17 [ V_169 ] . V_27 )
continue;
F_6 ( V_2 , V_28 , V_2 -> V_17 [ V_169 ] . V_9 ) ;
V_2 -> V_17 [ V_169 ] . V_27 = 0 ;
}
}
static int F_93 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_173 )
{
struct V_1 * V_2 = NULL ;
int V_41 ;
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_78 ) ;
return - V_84 ;
}
V_41 = F_87 ( V_4 , & V_2 , V_83 , V_173 ) ;
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
F_22 ( V_2 , V_178 , V_2 ) ;
F_31 ( V_2 , V_83 ) ;
F_89 ( & V_2 -> V_170 ) ;
V_4 -> V_171 -- ;
F_94 ( V_4 , V_2 ) ;
if ( ! F_2 ( V_4 -> type ) &&
V_2 -> V_22 . V_95 & V_179 )
V_4 -> V_174 = true ;
F_92 ( V_2 ) ;
F_8 ( 1 , L_82 ,
V_2 -> V_22 . V_23 , V_2 -> V_44 ) ;
return 0 ;
}
int F_95 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_173 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_93 ( V_4 , V_83 , V_173 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
unsigned int V_169 ;
if ( V_4 -> V_146 )
F_85 ( V_4 , V_180 , V_4 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_145 ) ) ) {
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 )
if ( V_4 -> V_34 [ V_169 ] -> V_44 == V_102 )
F_52 ( V_4 -> V_34 [ V_169 ] , V_104 ) ;
F_53 ( F_79 ( & V_4 -> V_145 ) ) ;
}
V_4 -> V_126 = 0 ;
V_4 -> V_146 = 0 ;
V_4 -> V_171 = 0 ;
V_4 -> error = 0 ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_144 ) ;
F_96 ( & V_4 -> V_145 , 0 ) ;
F_97 ( & V_4 -> V_147 ) ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_169 ] ;
if ( V_2 -> V_44 != V_45 ) {
V_2 -> V_44 = V_108 ;
F_22 ( V_2 , V_178 , V_2 ) ;
}
F_92 ( V_2 ) ;
}
}
static int F_98 ( struct V_3 * V_4 , enum V_121 type )
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
if ( V_4 -> V_171 >= V_4 -> V_130 ) {
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
void F_99 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_97 ( & V_4 -> V_147 ) ;
}
int F_100 ( struct V_3 * V_4 , enum V_121 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_98 ( V_4 , type ) ;
}
static int F_101 ( struct V_3 * V_4 , enum V_121 type )
{
if ( type != V_4 -> type ) {
F_8 ( 1 , L_83 ) ;
return - V_84 ;
}
F_42 ( V_4 ) ;
V_4 -> V_131 = ! F_2 ( V_4 -> type ) ;
V_4 -> V_174 = false ;
F_8 ( 3 , L_87 ) ;
return 0 ;
}
int F_102 ( struct V_3 * V_4 , enum V_121 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_122 ;
}
return F_101 ( V_4 , type ) ;
}
static int F_103 ( struct V_3 * V_4 , unsigned long V_35 ,
unsigned int * V_181 , unsigned int * V_182 )
{
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_38 == V_35 ) {
* V_181 = V_32 ;
* V_182 = V_10 ;
return 0 ;
}
}
}
return - V_84 ;
}
int F_104 ( struct V_3 * V_4 , struct V_183 * V_184 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_185 ;
int V_41 ;
struct V_158 * V_30 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
if ( ! V_4 -> V_114 -> V_186 ) {
F_8 ( 1 , L_89 ) ;
return - V_84 ;
}
if ( V_184 -> V_95 & ~ ( V_187 | V_188 ) ) {
F_8 ( 1 , L_90 ) ;
return - V_84 ;
}
if ( V_184 -> type != V_4 -> type ) {
F_8 ( 1 , L_78 ) ;
return - V_84 ;
}
if ( V_184 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_27 ) ;
return - V_84 ;
}
V_2 = V_4 -> V_34 [ V_184 -> V_23 ] ;
if ( V_184 -> V_10 >= V_2 -> V_11 ) {
F_8 ( 1 , L_91 ) ;
return - V_84 ;
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_92 ) ;
return - V_122 ;
}
V_185 = & V_2 -> V_17 [ V_184 -> V_10 ] ;
V_30 = F_4 ( V_2 , V_186 , V_185 -> V_9 , V_184 -> V_95 & V_188 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_93 ,
V_184 -> V_23 , V_184 -> V_10 ) ;
return - V_84 ;
}
V_41 = F_105 ( V_30 , V_184 -> V_95 & ~ V_188 ) ;
if ( V_41 < 0 ) {
F_8 ( 3 , L_94 ,
V_184 -> V_23 , V_184 -> V_10 , V_41 ) ;
F_11 ( V_30 ) ;
return V_41 ;
}
F_8 ( 3 , L_95 ,
V_184 -> V_23 , V_184 -> V_10 , V_41 ) ;
V_184 -> V_94 = V_41 ;
return 0 ;
}
int F_106 ( struct V_3 * V_4 , struct V_189 * V_190 )
{
unsigned long V_35 = V_190 -> V_191 << V_192 ;
struct V_1 * V_2 ;
unsigned int V_32 = 0 , V_10 = 0 ;
int V_41 ;
unsigned long V_19 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
if ( ! ( V_190 -> V_193 & V_194 ) ) {
F_8 ( 1 , L_96 ) ;
return - V_84 ;
}
if ( F_2 ( V_4 -> type ) ) {
if ( ! ( V_190 -> V_193 & V_195 ) ) {
F_8 ( 1 , L_97 ) ;
return - V_84 ;
}
} else {
if ( ! ( V_190 -> V_193 & V_196 ) ) {
F_8 ( 1 , L_98 ) ;
return - V_84 ;
}
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_99 ) ;
return - V_122 ;
}
V_41 = F_103 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_19 = F_3 ( V_2 -> V_18 [ V_10 ] . V_19 ) ;
if ( V_19 < ( V_190 -> V_197 - V_190 -> V_198 ) ) {
F_8 ( 1 ,
L_100 ) ;
return - V_84 ;
}
F_40 ( & V_4 -> V_128 ) ;
V_41 = F_29 ( V_2 , V_117 , V_2 -> V_17 [ V_10 ] . V_9 , V_190 ) ;
F_41 ( & V_4 -> V_128 ) ;
if ( V_41 )
return V_41 ;
F_8 ( 3 , L_101 , V_32 , V_10 ) ;
return 0 ;
}
unsigned long F_107 ( struct V_3 * V_4 ,
unsigned long V_199 ,
unsigned long V_200 ,
unsigned long V_201 ,
unsigned long V_95 )
{
unsigned long V_35 = V_201 << V_192 ;
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
void * V_138 ;
int V_41 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
V_41 = F_103 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_138 = F_50 ( V_2 , V_10 ) ;
return V_138 ? ( unsigned long ) V_138 : - V_84 ;
}
unsigned int F_108 ( struct V_3 * V_4 , struct V_202 * V_202 , T_1 * V_203 )
{
struct V_204 * V_205 = F_109 ( V_202 ) ;
unsigned long V_206 = F_110 ( V_203 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_207 = 0 ;
unsigned long V_95 ;
if ( F_111 ( V_208 , & V_205 -> V_95 ) ) {
struct V_209 * V_210 = V_202 -> V_211 ;
if ( F_112 ( V_210 ) )
V_207 = V_212 ;
else if ( V_206 & V_212 )
F_113 ( V_202 , & V_210 -> V_203 , V_203 ) ;
}
if ( ! F_2 ( V_4 -> type ) && ! ( V_206 & ( V_213 | V_214 ) ) )
return V_207 ;
if ( F_2 ( V_4 -> type ) && ! ( V_206 & ( V_215 | V_216 ) ) )
return V_207 ;
if ( V_4 -> V_33 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_2 ( V_4 -> type ) && ( V_4 -> V_112 & V_217 ) &&
( V_206 & ( V_213 | V_214 ) ) ) {
if ( F_114 ( V_4 , 1 ) )
return V_207 | V_218 ;
}
if ( F_2 ( V_4 -> type ) && ( V_4 -> V_112 & V_219 ) &&
( V_206 & ( V_215 | V_216 ) ) ) {
if ( F_114 ( V_4 , 0 ) )
return V_207 | V_218 ;
return V_207 | V_215 | V_216 ;
}
}
if ( ! F_115 ( V_4 ) || V_4 -> error )
return V_207 | V_218 ;
if ( V_4 -> V_131 )
return V_207 | V_218 ;
if ( F_2 ( V_4 -> type ) && V_4 -> V_171 < V_4 -> V_33 )
return V_207 | V_215 | V_216 ;
if ( F_80 ( & V_4 -> V_144 ) ) {
if ( V_4 -> V_174 )
return V_207 | V_213 | V_214 ;
F_113 ( V_202 , & V_4 -> V_147 , V_203 ) ;
}
F_54 ( & V_4 -> V_142 , V_95 ) ;
if ( ! F_80 ( & V_4 -> V_144 ) )
V_2 = F_88 ( & V_4 -> V_144 , struct V_1 ,
V_143 ) ;
F_57 ( & V_4 -> V_142 , V_95 ) ;
if ( V_2 && ( V_2 -> V_44 == V_106
|| V_2 -> V_44 == V_104 ) ) {
return ( F_2 ( V_4 -> type ) ) ?
V_207 | V_215 | V_216 :
V_207 | V_213 | V_214 ;
}
return V_207 ;
}
int F_116 ( struct V_3 * V_4 )
{
if ( F_53 ( ! V_4 ) ||
F_53 ( ! V_4 -> V_220 ) ||
F_53 ( ! V_4 -> V_114 ) ||
F_53 ( ! V_4 -> type ) ||
F_53 ( ! V_4 -> V_112 ) ||
F_53 ( ! V_4 -> V_220 -> V_129 ) ||
F_53 ( ! V_4 -> V_220 -> V_160 ) ||
F_53 ( V_4 -> V_97 &
~ ( V_98 |
V_100 ) ) )
return - V_84 ;
F_53 ( ( V_4 -> V_97 & V_98 ) ==
V_221 ) ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_144 ) ;
F_117 ( & V_4 -> V_142 ) ;
F_118 ( & V_4 -> V_128 ) ;
F_119 ( & V_4 -> V_147 ) ;
if ( V_4 -> V_42 == 0 )
V_4 -> V_42 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_120 ( struct V_3 * V_4 )
{
F_121 ( V_4 ) ;
F_42 ( V_4 ) ;
F_40 ( & V_4 -> V_128 ) ;
F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_128 ) ;
}
static int F_114 ( struct V_3 * V_4 , int V_222 )
{
struct V_223 * V_224 ;
int V_169 , V_41 ;
unsigned int V_127 = 0 ;
if ( F_53 ( ( V_222 && ! ( V_4 -> V_112 & V_217 ) ) ||
( ! V_222 && ! ( V_4 -> V_112 & V_219 ) ) ) )
return - V_84 ;
if ( ! V_4 -> V_114 -> V_138 )
return - V_122 ;
if ( V_4 -> V_126 || V_4 -> V_33 > 0 )
return - V_122 ;
V_127 = 1 ;
F_8 ( 3 , L_102 ,
( V_222 ) ? L_103 : L_104 , V_127 , V_4 -> V_225 ,
V_4 -> V_226 ) ;
V_224 = F_16 ( sizeof( struct V_223 ) , V_43 ) ;
if ( V_224 == NULL )
return - V_21 ;
V_224 -> V_227 = V_4 -> V_225 ;
V_224 -> V_228 = V_4 -> V_226 ;
V_224 -> V_124 . V_127 = V_127 ;
V_224 -> V_124 . V_40 = V_46 ;
V_224 -> V_124 . type = V_4 -> type ;
V_4 -> V_224 = V_224 ;
V_41 = F_39 ( V_4 , & V_224 -> V_124 ) ;
if ( V_41 )
goto V_229;
if ( V_4 -> V_34 [ 0 ] -> V_11 != 1 ) {
V_41 = - V_122 ;
goto V_230;
}
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; V_169 ++ ) {
V_224 -> V_34 [ V_169 ] . V_138 = F_50 ( V_4 -> V_34 [ V_169 ] , 0 ) ;
if ( V_224 -> V_34 [ V_169 ] . V_138 == NULL ) {
V_41 = - V_84 ;
goto V_230;
}
V_224 -> V_34 [ V_169 ] . V_12 = F_122 ( V_4 -> V_34 [ V_169 ] , 0 ) ;
}
if ( V_222 ) {
bool V_231 = F_17 ( V_4 -> type ) ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; V_169 ++ ) {
struct V_82 * V_83 = & V_224 -> V_83 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> type = V_4 -> type ;
if ( V_231 ) {
memset ( & V_224 -> V_26 , 0 , sizeof( V_224 -> V_26 ) ) ;
V_83 -> V_37 . V_17 = & V_224 -> V_26 ;
V_83 -> V_19 = 1 ;
}
V_83 -> V_40 = V_4 -> V_40 ;
V_83 -> V_23 = V_169 ;
V_41 = F_81 ( V_4 , V_83 ) ;
if ( V_41 )
goto V_230;
V_224 -> V_34 [ V_169 ] . V_232 = 1 ;
}
V_224 -> V_233 = V_4 -> V_33 ;
V_224 -> V_234 = V_4 -> V_33 ;
}
V_41 = F_98 ( V_4 , V_4 -> type ) ;
if ( V_41 )
goto V_230;
return V_41 ;
V_230:
V_224 -> V_124 . V_127 = 0 ;
F_39 ( V_4 , & V_224 -> V_124 ) ;
V_229:
V_4 -> V_224 = NULL ;
F_18 ( V_224 ) ;
return V_41 ;
}
static int F_121 ( struct V_3 * V_4 )
{
struct V_223 * V_224 = V_4 -> V_224 ;
if ( V_224 ) {
F_101 ( V_4 , V_4 -> type ) ;
V_4 -> V_224 = NULL ;
V_224 -> V_124 . V_127 = 0 ;
F_46 ( V_4 , & V_224 -> V_124 ) ;
F_18 ( V_224 ) ;
F_8 ( 3 , L_105 ) ;
}
return 0 ;
}
static T_2 F_123 ( struct V_3 * V_4 , char T_3 * V_235 , T_2 V_127 ,
T_4 * V_236 , int V_237 , int V_222 )
{
struct V_223 * V_224 ;
struct V_238 * V_239 ;
bool V_231 = F_17 ( V_4 -> type ) ;
bool V_240 = ! V_222 &&
( V_4 -> V_97 & V_98 ) ==
V_99 ;
int V_41 , V_23 ;
F_8 ( 3 , L_106 ,
V_222 ? L_103 : L_104 , ( long ) * V_236 , V_127 ,
V_237 ? L_107 : L_12 ) ;
if ( ! V_235 )
return - V_84 ;
if ( ! F_38 ( V_4 ) ) {
V_41 = F_114 ( V_4 , V_222 ) ;
F_8 ( 3 , L_108 , V_41 ) ;
if ( V_41 )
return V_41 ;
}
V_224 = V_4 -> V_224 ;
V_23 = V_224 -> V_234 ;
if ( V_23 >= V_4 -> V_33 ) {
memset ( & V_224 -> V_83 , 0 , sizeof( V_224 -> V_83 ) ) ;
V_224 -> V_83 . type = V_4 -> type ;
V_224 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_231 ) {
memset ( & V_224 -> V_26 , 0 , sizeof( V_224 -> V_26 ) ) ;
V_224 -> V_83 . V_37 . V_17 = & V_224 -> V_26 ;
V_224 -> V_83 . V_19 = 1 ;
}
V_41 = F_93 ( V_4 , & V_224 -> V_83 , V_237 ) ;
F_8 ( 5 , L_109 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_224 -> V_241 += 1 ;
V_224 -> V_234 = V_23 = V_224 -> V_83 . V_23 ;
V_239 = & V_224 -> V_34 [ V_23 ] ;
V_239 -> V_242 = 0 ;
V_239 -> V_232 = 0 ;
V_239 -> V_12 = V_222 ? F_124 ( V_4 -> V_34 [ V_23 ] , 0 )
: F_122 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
if ( V_231 && V_222 &&
V_224 -> V_83 . V_37 . V_17 [ 0 ] . V_88 < V_239 -> V_12 ) {
V_239 -> V_242 = V_224 -> V_83 . V_37 . V_17 [ 0 ] . V_88 ;
V_239 -> V_12 -= V_239 -> V_242 ;
}
} else {
V_239 = & V_224 -> V_34 [ V_23 ] ;
}
if ( V_239 -> V_242 + V_127 > V_239 -> V_12 ) {
V_127 = V_239 -> V_12 - V_239 -> V_242 ;
F_8 ( 5 , L_110 , V_127 ) ;
}
F_8 ( 3 , L_111 ,
V_127 , V_23 , V_239 -> V_242 ) ;
if ( V_222 )
V_41 = F_125 ( V_235 , V_239 -> V_138 + V_239 -> V_242 , V_127 ) ;
else
V_41 = F_126 ( V_239 -> V_138 + V_239 -> V_242 , V_235 , V_127 ) ;
if ( V_41 ) {
F_8 ( 3 , L_112 ) ;
return - V_243 ;
}
V_239 -> V_242 += V_127 ;
* V_236 += V_127 ;
if ( V_239 -> V_242 == V_239 -> V_12 || ( ! V_222 && V_224 -> V_228 ) ) {
if ( V_222 && V_224 -> V_227 && V_224 -> V_241 == 1 ) {
F_8 ( 3 , L_113 ) ;
return F_121 ( V_4 ) ;
}
memset ( & V_224 -> V_83 , 0 , sizeof( V_224 -> V_83 ) ) ;
V_224 -> V_83 . type = V_4 -> type ;
V_224 -> V_83 . V_40 = V_4 -> V_40 ;
V_224 -> V_83 . V_23 = V_23 ;
V_224 -> V_83 . V_86 = V_239 -> V_242 ;
if ( V_231 ) {
memset ( & V_224 -> V_26 , 0 , sizeof( V_224 -> V_26 ) ) ;
V_224 -> V_26 . V_86 = V_239 -> V_242 ;
V_224 -> V_83 . V_37 . V_17 = & V_224 -> V_26 ;
V_224 -> V_83 . V_19 = 1 ;
}
if ( V_240 )
F_127 ( & V_224 -> V_83 . V_163 ) ;
V_41 = F_81 ( V_4 , & V_224 -> V_83 ) ;
F_8 ( 5 , L_114 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_239 -> V_242 = 0 ;
V_239 -> V_232 = 1 ;
V_239 -> V_12 = F_122 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
V_224 -> V_244 += 1 ;
if ( V_224 -> V_233 < V_4 -> V_33 )
V_224 -> V_233 ++ ;
V_224 -> V_234 = V_224 -> V_233 ;
}
if ( V_41 == 0 )
V_41 = V_127 ;
return V_41 ;
}
T_2 F_128 ( struct V_3 * V_4 , char T_3 * V_235 , T_2 V_127 ,
T_4 * V_236 , int V_173 )
{
return F_123 ( V_4 , V_235 , V_127 , V_236 , V_173 , 1 ) ;
}
T_2 F_129 ( struct V_3 * V_4 , const char T_3 * V_235 , T_2 V_127 ,
T_4 * V_236 , int V_173 )
{
return F_123 ( V_4 , ( char T_3 * ) V_235 , V_127 ,
V_236 , V_173 , 0 ) ;
}
static int F_130 ( void * V_235 )
{
struct V_3 * V_4 = V_235 ;
struct V_245 * V_246 = V_4 -> V_246 ;
struct V_223 * V_224 = V_4 -> V_224 ;
bool V_240 = false ;
int V_247 = 0 ;
int V_23 = 0 ;
int V_41 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
V_247 = V_4 -> V_33 ;
V_240 =
( V_4 -> V_97 & V_98 ) ==
V_99 ;
}
F_131 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_224 -> V_83 , 0 , sizeof( V_224 -> V_83 ) ) ;
V_224 -> V_83 . type = V_4 -> type ;
V_224 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_247 ) {
V_224 -> V_83 . V_23 = V_23 ++ ;
V_247 -- ;
} else {
F_85 ( V_4 , V_177 , V_4 ) ;
if ( ! V_246 -> V_248 )
V_41 = F_93 ( V_4 , & V_224 -> V_83 , 0 ) ;
F_85 ( V_4 , V_176 , V_4 ) ;
F_8 ( 5 , L_115 , V_41 ) ;
}
if ( V_41 || V_246 -> V_248 )
break;
F_132 () ;
V_2 = V_4 -> V_34 [ V_224 -> V_83 . V_23 ] ;
if ( ! ( V_224 -> V_83 . V_95 & V_105 ) )
if ( V_246 -> V_249 ( V_2 , V_246 -> V_250 ) )
break;
F_85 ( V_4 , V_177 , V_4 ) ;
if ( V_240 )
F_127 ( & V_224 -> V_83 . V_163 ) ;
if ( ! V_246 -> V_248 )
V_41 = F_81 ( V_4 , & V_224 -> V_83 ) ;
F_85 ( V_4 , V_176 , V_4 ) ;
if ( V_41 || V_246 -> V_248 )
break;
}
while ( ! F_133 () ) {
F_134 ( V_251 ) ;
F_135 () ;
}
return 0 ;
}
int F_136 ( struct V_3 * V_4 , T_5 V_249 , void * V_250 ,
const char * V_252 )
{
struct V_245 * V_246 ;
int V_41 = 0 ;
if ( V_4 -> V_246 )
return - V_122 ;
if ( F_137 ( V_4 ) )
return - V_122 ;
if ( F_53 ( V_4 -> V_224 ) )
return - V_122 ;
V_246 = F_16 ( sizeof( * V_246 ) , V_43 ) ;
if ( V_246 == NULL )
return - V_21 ;
V_246 -> V_249 = V_249 ;
V_246 -> V_250 = V_250 ;
V_41 = F_114 ( V_4 , ! F_2 ( V_4 -> type ) ) ;
F_8 ( 3 , L_116 , V_41 ) ;
if ( V_41 )
goto V_253;
V_4 -> V_246 = V_246 ;
V_246 -> V_254 = F_138 ( F_130 , V_4 , L_117 , V_252 ) ;
if ( F_71 ( V_246 -> V_254 ) ) {
V_41 = F_68 ( V_246 -> V_254 ) ;
V_246 -> V_254 = NULL ;
goto V_255;
}
return 0 ;
V_255:
F_121 ( V_4 ) ;
V_253:
F_18 ( V_246 ) ;
return V_41 ;
}
int F_139 ( struct V_3 * V_4 )
{
struct V_245 * V_246 = V_4 -> V_246 ;
int V_157 ;
if ( V_246 == NULL )
return 0 ;
V_246 -> V_248 = true ;
F_99 ( V_4 ) ;
V_157 = F_140 ( V_246 -> V_254 ) ;
F_121 ( V_4 ) ;
V_246 -> V_254 = NULL ;
F_18 ( V_246 ) ;
V_4 -> V_246 = NULL ;
return V_157 ;
}
static inline bool F_141 ( struct V_204 * V_256 , struct V_202 * V_202 )
{
return V_256 -> V_257 -> V_258 && V_256 -> V_257 -> V_258 != V_202 -> V_211 ;
}
int F_142 ( struct V_202 * V_202 , void * V_250 ,
struct V_123 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
int V_207 = F_37 ( V_256 -> V_257 , V_26 -> V_40 , V_26 -> type ) ;
if ( V_207 )
return V_207 ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
V_207 = F_39 ( V_256 -> V_257 , V_26 ) ;
if ( V_207 == 0 )
V_256 -> V_257 -> V_258 = V_26 -> V_127 ? V_202 -> V_211 : NULL ;
return V_207 ;
}
int F_143 ( struct V_202 * V_202 , void * V_250 ,
struct V_132 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
int V_207 = F_37 ( V_256 -> V_257 , V_26 -> V_40 , V_26 -> V_136 . type ) ;
V_26 -> V_23 = V_256 -> V_257 -> V_33 ;
if ( V_26 -> V_127 == 0 )
return V_207 != - V_122 ? V_207 : 0 ;
if ( V_207 )
return V_207 ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
V_207 = F_47 ( V_256 -> V_257 , V_26 ) ;
if ( V_207 == 0 )
V_256 -> V_257 -> V_258 = V_202 -> V_211 ;
return V_207 ;
}
int F_144 ( struct V_202 * V_202 , void * V_250 ,
struct V_82 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_77 ( V_256 -> V_257 , V_26 ) ;
}
int F_145 ( struct V_202 * V_202 , void * V_250 , struct V_82 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
return F_33 ( V_256 -> V_257 , V_26 ) ;
}
int F_146 ( struct V_202 * V_202 , void * V_250 , struct V_82 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_83 ( V_256 -> V_257 , V_26 ) ;
}
int F_147 ( struct V_202 * V_202 , void * V_250 , struct V_82 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_95 ( V_256 -> V_257 , V_26 , V_202 -> V_259 & V_260 ) ;
}
int F_148 ( struct V_202 * V_202 , void * V_250 , enum V_121 V_169 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_100 ( V_256 -> V_257 , V_169 ) ;
}
int F_149 ( struct V_202 * V_202 , void * V_250 , enum V_121 V_169 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_102 ( V_256 -> V_257 , V_169 ) ;
}
int F_150 ( struct V_202 * V_202 , void * V_250 , struct V_183 * V_26 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( F_141 ( V_256 , V_202 ) )
return - V_122 ;
return F_104 ( V_256 -> V_257 , V_26 ) ;
}
int F_151 ( struct V_202 * V_202 , struct V_189 * V_190 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
return F_106 ( V_256 -> V_257 , V_190 ) ;
}
int F_152 ( struct V_202 * V_202 , struct V_261 * V_262 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
if ( V_262 )
F_40 ( V_262 ) ;
if ( V_202 -> V_211 == V_256 -> V_257 -> V_258 ) {
F_120 ( V_256 -> V_257 ) ;
V_256 -> V_257 -> V_258 = NULL ;
}
if ( V_262 )
F_41 ( V_262 ) ;
return F_153 ( V_202 ) ;
}
int F_154 ( struct V_202 * V_202 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
struct V_261 * V_262 = V_256 -> V_257 -> V_262 ? V_256 -> V_257 -> V_262 : V_256 -> V_262 ;
return F_152 ( V_202 , V_262 ) ;
}
T_6 F_155 ( struct V_202 * V_202 , const char T_3 * V_239 ,
T_2 V_127 , T_4 * V_236 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
struct V_261 * V_262 = V_256 -> V_257 -> V_262 ? V_256 -> V_257 -> V_262 : V_256 -> V_262 ;
int V_157 = - V_122 ;
if ( ! ( V_256 -> V_257 -> V_112 & V_219 ) )
return - V_84 ;
if ( V_262 && F_156 ( V_262 ) )
return - V_263 ;
if ( F_141 ( V_256 , V_202 ) )
goto exit;
V_157 = F_129 ( V_256 -> V_257 , V_239 , V_127 , V_236 ,
V_202 -> V_259 & V_260 ) ;
if ( V_256 -> V_257 -> V_224 )
V_256 -> V_257 -> V_258 = V_202 -> V_211 ;
exit:
if ( V_262 )
F_41 ( V_262 ) ;
return V_157 ;
}
T_6 F_157 ( struct V_202 * V_202 , char T_3 * V_239 ,
T_2 V_127 , T_4 * V_236 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
struct V_261 * V_262 = V_256 -> V_257 -> V_262 ? V_256 -> V_257 -> V_262 : V_256 -> V_262 ;
int V_157 = - V_122 ;
if ( ! ( V_256 -> V_257 -> V_112 & V_217 ) )
return - V_84 ;
if ( V_262 && F_156 ( V_262 ) )
return - V_263 ;
if ( F_141 ( V_256 , V_202 ) )
goto exit;
V_157 = F_128 ( V_256 -> V_257 , V_239 , V_127 , V_236 ,
V_202 -> V_259 & V_260 ) ;
if ( V_256 -> V_257 -> V_224 )
V_256 -> V_257 -> V_258 = V_202 -> V_211 ;
exit:
if ( V_262 )
F_41 ( V_262 ) ;
return V_157 ;
}
unsigned int F_158 ( struct V_202 * V_202 , T_1 * V_203 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
struct V_3 * V_4 = V_256 -> V_257 ;
struct V_261 * V_262 = V_4 -> V_262 ? V_4 -> V_262 : V_256 -> V_262 ;
unsigned V_207 ;
void * V_224 ;
F_53 ( ! V_262 ) ;
if ( V_262 && F_156 ( V_262 ) )
return V_218 ;
V_224 = V_4 -> V_224 ;
V_207 = F_108 ( V_256 -> V_257 , V_202 , V_203 ) ;
if ( ! V_224 && V_4 -> V_224 )
V_4 -> V_258 = V_202 -> V_211 ;
if ( V_262 )
F_41 ( V_262 ) ;
return V_207 ;
}
unsigned long F_159 ( struct V_202 * V_202 , unsigned long V_199 ,
unsigned long V_200 , unsigned long V_201 , unsigned long V_95 )
{
struct V_204 * V_256 = F_109 ( V_202 ) ;
return F_107 ( V_256 -> V_257 , V_199 , V_200 , V_201 , V_95 ) ;
}
void F_160 ( struct V_3 * V_264 )
{
F_41 ( V_264 -> V_262 ) ;
}
void F_161 ( struct V_3 * V_264 )
{
F_40 ( V_264 -> V_262 ) ;
}
