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
break;
}
if ( F_28 ( V_4 , V_2 ) )
V_83 -> V_95 |= V_110 ;
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
if ( ! ( V_4 -> V_111 & V_112 ) || ! V_4 -> V_113 -> V_114 ||
! V_4 -> V_113 -> V_24 )
return - V_84 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_111 & V_115 ) || ! V_4 -> V_113 -> V_14 ||
! V_4 -> V_113 -> V_20 || ! V_4 -> V_113 -> V_116 )
return - V_84 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_111 & V_117 ) || ! V_4 -> V_113 -> V_118 ||
! V_4 -> V_113 -> V_29 || ! V_4 -> V_113 -> V_119 ||
! V_4 -> V_113 -> V_28 )
return - V_84 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
enum V_39 V_40 , enum V_120 type )
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
return - V_121 ;
}
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_122 * V_123 )
{
unsigned int V_33 , V_124 , V_11 = 0 ;
int V_41 ;
if ( V_4 -> V_125 ) {
F_8 ( 1 , L_34 ) ;
return - V_121 ;
}
if ( V_123 -> V_126 == 0 || V_4 -> V_33 != 0 || V_4 -> V_40 != V_123 -> V_40 ) {
F_40 ( & V_4 -> V_127 ) ;
if ( V_4 -> V_40 == V_46 && F_30 ( V_4 ) ) {
F_41 ( & V_4 -> V_127 ) ;
F_8 ( 1 , L_35 ) ;
return - V_121 ;
}
F_42 ( V_4 ) ;
V_41 = F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_127 ) ;
if ( V_41 )
return V_41 ;
if ( V_123 -> V_126 == 0 )
return 0 ;
}
V_33 = F_43 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
V_33 = F_44 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_13 , 0 , sizeof( V_4 -> V_13 ) ) ;
memset ( V_4 -> V_15 , 0 , sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_40 = V_123 -> V_40 ;
V_41 = F_45 ( V_4 , V_128 , V_4 , NULL , & V_33 , & V_11 ,
V_4 -> V_13 , V_4 -> V_15 ) ;
if ( V_41 )
return V_41 ;
V_124 = F_15 ( V_4 , V_123 -> V_40 , V_33 , V_11 ) ;
if ( V_124 == 0 ) {
F_8 ( 1 , L_36 ) ;
return - V_21 ;
}
if ( V_124 < V_4 -> V_129 )
V_41 = - V_21 ;
if ( ! V_41 && V_124 < V_33 ) {
V_33 = V_124 ;
V_41 = F_45 ( V_4 , V_128 , V_4 , NULL , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( ! V_41 && V_124 < V_33 )
V_41 = - V_21 ;
}
F_40 ( & V_4 -> V_127 ) ;
V_4 -> V_33 = V_124 ;
if ( V_41 < 0 ) {
F_21 ( V_4 , V_124 ) ;
F_41 ( & V_4 -> V_127 ) ;
return V_41 ;
}
F_41 ( & V_4 -> V_127 ) ;
V_123 -> V_126 = V_124 ;
V_4 -> V_130 = ! F_2 ( V_4 -> type ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , struct V_122 * V_123 )
{
int V_41 = F_37 ( V_4 , V_123 -> V_40 , V_123 -> type ) ;
return V_41 ? V_41 : F_39 ( V_4 , V_123 ) ;
}
static int F_47 ( struct V_3 * V_4 , struct V_131 * V_132 )
{
unsigned int V_11 = 0 , V_33 , V_124 ;
int V_41 ;
if ( V_4 -> V_33 == V_133 ) {
F_8 ( 1 , L_37 ) ;
return - V_134 ;
}
if ( ! V_4 -> V_33 ) {
memset ( V_4 -> V_13 , 0 , sizeof( V_4 -> V_13 ) ) ;
memset ( V_4 -> V_15 , 0 , sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_40 = V_132 -> V_40 ;
V_4 -> V_130 = ! F_2 ( V_4 -> type ) ;
}
V_33 = F_48 ( V_132 -> V_126 , V_133 - V_4 -> V_33 ) ;
V_41 = F_45 ( V_4 , V_128 , V_4 , & V_132 -> V_135 , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( V_41 )
return V_41 ;
V_124 = F_15 ( V_4 , V_132 -> V_40 , V_33 ,
V_11 ) ;
if ( V_124 == 0 ) {
F_8 ( 1 , L_36 ) ;
return - V_21 ;
}
if ( V_124 < V_33 ) {
V_33 = V_124 ;
V_41 = F_45 ( V_4 , V_128 , V_4 , & V_132 -> V_135 , & V_33 ,
& V_11 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( ! V_41 && V_124 < V_33 )
V_41 = - V_21 ;
}
F_40 ( & V_4 -> V_127 ) ;
V_4 -> V_33 += V_124 ;
if ( V_41 < 0 ) {
F_21 ( V_4 , V_124 ) ;
F_41 ( & V_4 -> V_127 ) ;
return - V_21 ;
}
F_41 ( & V_4 -> V_127 ) ;
V_132 -> V_126 = V_124 ;
return 0 ;
}
int F_49 ( struct V_3 * V_4 , struct V_131 * V_132 )
{
int V_41 = F_37 ( V_4 , V_132 -> V_40 , V_132 -> V_135 . type ) ;
V_132 -> V_23 = V_4 -> V_33 ;
if ( V_132 -> V_126 == 0 )
return V_41 != - V_121 ? V_41 : 0 ;
return V_41 ? V_41 : F_47 ( V_4 , V_132 ) ;
}
void * F_50 ( struct V_1 * V_2 , unsigned int V_136 )
{
if ( V_136 > V_2 -> V_11 || ! V_2 -> V_17 [ V_136 ] . V_9 )
return NULL ;
return F_4 ( V_2 , V_137 , V_2 -> V_17 [ V_136 ] . V_9 ) ;
}
void * F_51 ( struct V_1 * V_2 , unsigned int V_136 )
{
if ( V_136 >= V_2 -> V_11 || ! V_2 -> V_17 [ V_136 ] . V_9 )
return NULL ;
return F_4 ( V_2 , V_138 , V_2 -> V_17 [ V_136 ] . V_9 ) ;
}
void F_52 ( struct V_1 * V_2 , enum V_139 V_44 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_95 ;
unsigned int V_10 ;
if ( F_53 ( V_2 -> V_44 != V_102 ) )
return;
if ( F_53 ( V_44 != V_106 &&
V_44 != V_104 &&
V_44 != V_101 ) )
V_44 = V_104 ;
#ifdef F_23
V_2 -> V_71 ++ ;
#endif
F_8 ( 4 , L_38 ,
V_2 -> V_22 . V_23 , V_44 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_140 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
V_2 -> V_44 = V_44 ;
if ( V_44 != V_101 )
F_55 ( & V_2 -> V_142 , & V_4 -> V_143 ) ;
F_56 ( & V_4 -> V_144 ) ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
if ( V_44 == V_101 )
return;
F_58 ( & V_4 -> V_145 ) ;
}
void F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_95 ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
F_60 (vb, &q->done_list, done_entry)
V_2 -> V_44 = V_104 ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
}
static void F_61 ( struct V_1 * V_2 , const struct V_82 * V_83 ,
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
struct V_36 * V_146 = & V_18 [ V_10 ] ;
struct V_36 * V_147 = & V_83 -> V_37 . V_17 [ V_10 ] ;
V_146 -> V_86 = V_147 -> V_86 ?
V_147 -> V_86 : V_146 -> V_19 ;
V_146 -> V_88 = V_147 -> V_88 ;
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
if ( F_2 ( V_83 -> type ) )
V_18 [ 0 ] . V_86 = V_83 -> V_86 ?
V_83 -> V_86 : V_18 [ 0 ] . V_19 ;
else
V_18 [ 0 ] . V_86 = 0 ;
}
V_2 -> V_22 . V_95 = V_83 -> V_95 & ~ V_96 ;
if ( ( V_2 -> V_3 -> V_97 & V_98 ) !=
V_99 || ! F_2 ( V_83 -> type ) ) {
V_2 -> V_22 . V_95 &= ~ V_100 ;
}
if ( F_2 ( V_83 -> type ) ) {
V_2 -> V_22 . V_95 &= ~ V_148 ;
V_2 -> V_22 . V_149 = V_83 -> V_149 ;
} else {
V_2 -> V_22 . V_95 &= ~ V_150 ;
}
}
static int F_62 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
F_61 ( V_2 , V_83 , V_2 -> V_18 ) ;
return F_19 ( V_2 , V_151 , V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_36 V_17 [ V_85 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_9 ;
unsigned int V_10 ;
int V_41 ;
enum V_5 V_6 =
F_2 ( V_4 -> type ) ? V_7 : V_8 ;
bool V_152 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_61 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_93 &&
V_2 -> V_18 [ V_10 ] . V_37 . V_93 == V_17 [ V_10 ] . V_37 . V_93
&& V_2 -> V_18 [ V_10 ] . V_19 == V_17 [ V_10 ] . V_19 )
continue;
F_8 ( 3 , L_39
L_40 , V_10 ) ;
if ( V_17 [ V_10 ] . V_19 < V_4 -> V_13 [ V_10 ] ) {
F_8 ( 1 , L_41
L_42 ,
V_17 [ V_10 ] . V_19 ,
V_4 -> V_13 [ V_10 ] , V_10 ) ;
V_41 = - V_84 ;
goto V_153;
}
if ( V_2 -> V_17 [ V_10 ] . V_9 ) {
if ( ! V_152 ) {
V_152 = true ;
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
}
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
memset ( & V_2 -> V_18 [ V_10 ] , 0 , sizeof( struct V_36 ) ) ;
V_9 = F_4 ( V_2 , V_114 , V_4 -> V_15 [ V_10 ] ,
V_17 [ V_10 ] . V_37 . V_93 ,
V_17 [ V_10 ] . V_19 , V_6 ) ;
if ( F_5 ( V_9 ) ) {
F_8 ( 1 , L_43
L_44 , V_10 ) ;
V_41 = V_9 ? F_64 ( V_9 ) : - V_84 ;
goto V_153;
}
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_152 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_45 ) ;
goto V_153;
}
}
V_41 = F_19 ( V_2 , V_151 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_46 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_153;
}
return 0 ;
V_153:
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_17 [ V_10 ] . V_9 )
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
V_2 -> V_18 [ V_10 ] . V_37 . V_93 = 0 ;
V_2 -> V_18 [ V_10 ] . V_19 = 0 ;
}
return V_41 ;
}
static int F_65 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_36 V_17 [ V_85 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_9 ;
unsigned int V_10 ;
int V_41 ;
enum V_5 V_6 =
F_2 ( V_4 -> type ) ? V_7 : V_8 ;
bool V_152 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_61 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
struct V_154 * V_30 = F_66 ( V_17 [ V_10 ] . V_37 . V_94 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_47 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_153;
}
if ( V_17 [ V_10 ] . V_19 == 0 )
V_17 [ V_10 ] . V_19 = V_30 -> V_12 ;
if ( V_17 [ V_10 ] . V_19 < V_4 -> V_13 [ V_10 ] ) {
F_8 ( 1 , L_48 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_153;
}
if ( V_30 == V_2 -> V_17 [ V_10 ] . V_30 &&
V_2 -> V_18 [ V_10 ] . V_19 == V_17 [ V_10 ] . V_19 ) {
F_11 ( V_30 ) ;
continue;
}
F_8 ( 1 , L_49 , V_10 ) ;
if ( ! V_152 ) {
V_152 = true ;
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_10 ( V_2 , & V_2 -> V_17 [ V_10 ] ) ;
memset ( & V_2 -> V_18 [ V_10 ] , 0 , sizeof( struct V_36 ) ) ;
V_9 = F_4 ( V_2 , V_118 , V_4 -> V_15 [ V_10 ] ,
V_30 , V_17 [ V_10 ] . V_19 , V_6 ) ;
if ( F_67 ( V_9 ) ) {
F_8 ( 1 , L_50 ) ;
V_41 = F_64 ( V_9 ) ;
F_11 ( V_30 ) ;
goto V_153;
}
V_2 -> V_17 [ V_10 ] . V_30 = V_30 ;
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_41 = F_29 ( V_2 , V_119 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
if ( V_41 ) {
F_8 ( 1 , L_51 ,
V_10 ) ;
goto V_153;
}
V_2 -> V_17 [ V_10 ] . V_27 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_152 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_45 ) ;
goto V_153;
}
}
V_41 = F_19 ( V_2 , V_151 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_46 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_153;
}
return 0 ;
V_153:
F_12 ( V_2 ) ;
return V_41 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_10 ;
V_2 -> V_44 = V_102 ;
F_69 ( & V_4 -> V_144 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_155 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_22 ( V_2 , V_156 , V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_41 ;
V_41 = F_27 ( V_2 , V_83 ) ;
if ( V_41 < 0 ) {
F_8 ( 1 , L_52 , V_41 ) ;
return V_41 ;
}
if ( V_83 -> V_149 == V_157 && F_2 ( V_4 -> type ) ) {
F_8 ( 1 , L_53 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_54 ) ;
return - V_158 ;
}
V_2 -> V_44 = V_50 ;
V_2 -> V_22 . V_159 . V_160 = 0 ;
V_2 -> V_22 . V_159 . V_161 = 0 ;
V_2 -> V_22 . V_162 = 0 ;
switch ( V_4 -> V_40 ) {
case V_46 :
V_41 = F_62 ( V_2 , V_83 ) ;
break;
case V_87 :
F_71 ( & V_163 -> V_164 -> V_165 ) ;
V_41 = F_63 ( V_2 , V_83 ) ;
F_72 ( & V_163 -> V_164 -> V_165 ) ;
break;
case V_49 :
V_41 = F_65 ( V_2 , V_83 ) ;
break;
default:
F_73 ( 1 , L_55 ) ;
V_41 = - V_84 ;
}
if ( V_41 )
F_8 ( 1 , L_56 , V_41 ) ;
V_2 -> V_44 = V_41 ? V_45 : V_108 ;
return V_41 ;
}
static int F_74 ( struct V_3 * V_4 , struct V_82 * V_83 ,
const char * V_166 )
{
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_57 , V_166 ) ;
return - V_84 ;
}
if ( V_83 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_58 , V_166 ) ;
return - V_84 ;
}
if ( V_4 -> V_34 [ V_83 -> V_23 ] == NULL ) {
F_8 ( 1 , L_59 , V_166 ) ;
return - V_84 ;
}
if ( V_83 -> V_40 != V_4 -> V_40 ) {
F_8 ( 1 , L_60 , V_166 ) ;
return - V_84 ;
}
return F_26 ( V_4 -> V_34 [ V_83 -> V_23 ] , V_83 ) ;
}
int F_75 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_41 ;
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
V_41 = F_74 ( V_4 , V_83 , L_61 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_83 -> V_23 ] ;
if ( V_2 -> V_44 != V_45 ) {
F_8 ( 1 , L_62 ,
V_2 -> V_44 ) ;
return - V_84 ;
}
V_41 = F_70 ( V_2 , V_83 ) ;
if ( ! V_41 ) {
F_31 ( V_2 , V_83 ) ;
F_8 ( 1 , L_63 , V_2 -> V_22 . V_23 ) ;
}
return V_41 ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_41 ;
F_60 (vb, &q->queued_list, queued_entry)
F_68 ( V_2 ) ;
V_4 -> V_167 = 1 ;
V_41 = F_45 ( V_4 , V_168 , V_4 ,
F_77 ( & V_4 -> V_144 ) ) ;
if ( ! V_41 )
return 0 ;
V_4 -> V_167 = 0 ;
F_8 ( 1 , L_64 ) ;
if ( F_53 ( F_77 ( & V_4 -> V_144 ) ) ) {
unsigned V_169 ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 ) {
V_2 = V_4 -> V_34 [ V_169 ] ;
if ( V_2 -> V_44 == V_102 )
F_52 ( V_2 , V_101 ) ;
}
F_53 ( F_77 ( & V_4 -> V_144 ) ) ;
}
F_53 ( ! F_78 ( & V_4 -> V_143 ) ) ;
return V_41 ;
}
static int F_79 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
int V_41 = F_74 ( V_4 , V_83 , L_65 ) ;
struct V_1 * V_2 ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_83 -> V_23 ] ;
switch ( V_2 -> V_44 ) {
case V_45 :
V_41 = F_70 ( V_2 , V_83 ) ;
if ( V_41 )
return V_41 ;
break;
case V_108 :
break;
case V_50 :
F_8 ( 1 , L_66 ) ;
return - V_84 ;
default:
F_8 ( 1 , L_62 , V_2 -> V_44 ) ;
return - V_84 ;
}
F_55 ( & V_2 -> V_170 , & V_4 -> V_81 ) ;
V_4 -> V_171 ++ ;
V_4 -> V_130 = false ;
V_2 -> V_44 = V_101 ;
if ( F_2 ( V_4 -> type ) ) {
if ( ( V_4 -> V_97 & V_98 ) ==
V_99 )
V_2 -> V_22 . V_159 = V_83 -> V_159 ;
V_2 -> V_22 . V_95 |= V_83 -> V_95 & V_148 ;
if ( V_83 -> V_95 & V_148 )
V_2 -> V_22 . V_172 = V_83 -> V_172 ;
}
if ( V_4 -> V_167 )
F_68 ( V_2 ) ;
F_31 ( V_2 , V_83 ) ;
if ( V_4 -> V_125 && ! V_4 -> V_167 &&
V_4 -> V_171 >= V_4 -> V_129 ) {
V_41 = F_76 ( V_4 ) ;
if ( V_41 )
return V_41 ;
}
F_8 ( 1 , L_67 , V_2 -> V_22 . V_23 ) ;
return 0 ;
}
int F_80 ( struct V_3 * V_4 , struct V_82 * V_83 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_79 ( V_4 , V_83 ) ;
}
static int F_81 ( struct V_3 * V_4 , int V_173 )
{
for (; ; ) {
int V_41 ;
if ( ! V_4 -> V_125 ) {
F_8 ( 1 , L_68 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_69 ) ;
return - V_158 ;
}
if ( ! F_78 ( & V_4 -> V_143 ) ) {
break;
}
if ( V_173 ) {
F_8 ( 1 , L_70
L_71 ) ;
return - V_51 ;
}
F_82 ( V_4 , V_174 , V_4 ) ;
F_8 ( 3 , L_72 ) ;
V_41 = F_83 ( V_4 -> V_145 ,
! F_78 ( & V_4 -> V_143 ) || ! V_4 -> V_125 ||
V_4 -> error ) ;
F_82 ( V_4 , V_175 , V_4 ) ;
if ( V_41 ) {
F_8 ( 1 , L_73 ) ;
return V_41 ;
}
}
return 0 ;
}
static int F_84 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_82 * V_83 , int V_173 )
{
unsigned long V_95 ;
int V_41 ;
V_41 = F_81 ( V_4 , V_173 ) ;
if ( V_41 )
return V_41 ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
* V_2 = F_85 ( & V_4 -> V_143 , struct V_1 , V_142 ) ;
V_41 = F_26 ( * V_2 , V_83 ) ;
if ( ! V_41 )
F_86 ( & ( * V_2 ) -> V_142 ) ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
return V_41 ;
}
int F_87 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_125 ) {
F_8 ( 1 , L_68 ) ;
return - V_84 ;
}
if ( V_4 -> V_167 )
F_88 ( V_4 -> V_145 , ! F_77 ( & V_4 -> V_144 ) ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
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
static int F_90 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_173 )
{
struct V_1 * V_2 = NULL ;
int V_41 ;
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_74 ) ;
return - V_84 ;
}
V_41 = F_84 ( V_4 , & V_2 , V_83 , V_173 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_2 -> V_44 ) {
case V_106 :
F_8 ( 3 , L_75 ) ;
break;
case V_104 :
F_8 ( 3 , L_76 ) ;
break;
default:
F_8 ( 1 , L_77 ) ;
return - V_84 ;
}
F_22 ( V_2 , V_176 , V_2 ) ;
F_31 ( V_2 , V_83 ) ;
F_86 ( & V_2 -> V_170 ) ;
V_4 -> V_171 -- ;
F_89 ( V_2 ) ;
F_8 ( 1 , L_78 ,
V_2 -> V_22 . V_23 , V_2 -> V_44 ) ;
return 0 ;
}
int F_91 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_173 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_90 ( V_4 , V_83 , V_173 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
unsigned int V_169 ;
if ( V_4 -> V_167 )
F_82 ( V_4 , V_177 , V_4 ) ;
if ( F_53 ( F_77 ( & V_4 -> V_144 ) ) ) {
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 )
if ( V_4 -> V_34 [ V_169 ] -> V_44 == V_102 )
F_52 ( V_4 -> V_34 [ V_169 ] , V_104 ) ;
F_53 ( F_77 ( & V_4 -> V_144 ) ) ;
}
V_4 -> V_125 = 0 ;
V_4 -> V_167 = 0 ;
V_4 -> V_171 = 0 ;
V_4 -> error = 0 ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_143 ) ;
F_92 ( & V_4 -> V_144 , 0 ) ;
F_93 ( & V_4 -> V_145 ) ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; ++ V_169 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_169 ] ;
if ( V_2 -> V_44 != V_45 ) {
V_2 -> V_44 = V_108 ;
F_22 ( V_2 , V_176 , V_2 ) ;
}
F_89 ( V_2 ) ;
}
}
static int F_94 ( struct V_3 * V_4 , enum V_120 type )
{
int V_41 ;
if ( type != V_4 -> type ) {
F_8 ( 1 , L_79 ) ;
return - V_84 ;
}
if ( V_4 -> V_125 ) {
F_8 ( 3 , L_80 ) ;
return 0 ;
}
if ( ! V_4 -> V_33 ) {
F_8 ( 1 , L_81 ) ;
return - V_84 ;
}
if ( V_4 -> V_33 < V_4 -> V_129 ) {
F_8 ( 1 , L_82 ,
V_4 -> V_129 ) ;
return - V_84 ;
}
if ( V_4 -> V_171 >= V_4 -> V_129 ) {
V_41 = F_76 ( V_4 ) ;
if ( V_41 ) {
F_42 ( V_4 ) ;
return V_41 ;
}
}
V_4 -> V_125 = 1 ;
F_8 ( 3 , L_83 ) ;
return 0 ;
}
void F_95 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_93 ( & V_4 -> V_145 ) ;
}
int F_96 ( struct V_3 * V_4 , enum V_120 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_94 ( V_4 , type ) ;
}
static int F_97 ( struct V_3 * V_4 , enum V_120 type )
{
if ( type != V_4 -> type ) {
F_8 ( 1 , L_79 ) ;
return - V_84 ;
}
F_42 ( V_4 ) ;
V_4 -> V_130 = ! F_2 ( V_4 -> type ) ;
F_8 ( 3 , L_83 ) ;
return 0 ;
}
int F_98 ( struct V_3 * V_4 , enum V_120 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_97 ( V_4 , type ) ;
}
static int F_99 ( struct V_3 * V_4 , unsigned long V_35 ,
unsigned int * V_178 , unsigned int * V_179 )
{
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_38 == V_35 ) {
* V_178 = V_32 ;
* V_179 = V_10 ;
return 0 ;
}
}
}
return - V_84 ;
}
int F_100 ( struct V_3 * V_4 , struct V_180 * V_181 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_182 ;
int V_41 ;
struct V_154 * V_30 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_84 ) ;
return - V_84 ;
}
if ( ! V_4 -> V_113 -> V_183 ) {
F_8 ( 1 , L_85 ) ;
return - V_84 ;
}
if ( V_181 -> V_95 & ~ ( V_184 | V_185 ) ) {
F_8 ( 1 , L_86 ) ;
return - V_84 ;
}
if ( V_181 -> type != V_4 -> type ) {
F_8 ( 1 , L_74 ) ;
return - V_84 ;
}
if ( V_181 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_27 ) ;
return - V_84 ;
}
V_2 = V_4 -> V_34 [ V_181 -> V_23 ] ;
if ( V_181 -> V_10 >= V_2 -> V_11 ) {
F_8 ( 1 , L_87 ) ;
return - V_84 ;
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_88 ) ;
return - V_121 ;
}
V_182 = & V_2 -> V_17 [ V_181 -> V_10 ] ;
V_30 = F_4 ( V_2 , V_183 , V_182 -> V_9 , V_181 -> V_95 & V_185 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_89 ,
V_181 -> V_23 , V_181 -> V_10 ) ;
return - V_84 ;
}
V_41 = F_101 ( V_30 , V_181 -> V_95 & ~ V_185 ) ;
if ( V_41 < 0 ) {
F_8 ( 3 , L_90 ,
V_181 -> V_23 , V_181 -> V_10 , V_41 ) ;
F_11 ( V_30 ) ;
return V_41 ;
}
F_8 ( 3 , L_91 ,
V_181 -> V_23 , V_181 -> V_10 , V_41 ) ;
V_181 -> V_94 = V_41 ;
return 0 ;
}
int F_102 ( struct V_3 * V_4 , struct V_186 * V_187 )
{
unsigned long V_35 = V_187 -> V_188 << V_189 ;
struct V_1 * V_2 ;
unsigned int V_32 = 0 , V_10 = 0 ;
int V_41 ;
unsigned long V_19 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_84 ) ;
return - V_84 ;
}
if ( ! ( V_187 -> V_190 & V_191 ) ) {
F_8 ( 1 , L_92 ) ;
return - V_84 ;
}
if ( F_2 ( V_4 -> type ) ) {
if ( ! ( V_187 -> V_190 & V_192 ) ) {
F_8 ( 1 , L_93 ) ;
return - V_84 ;
}
} else {
if ( ! ( V_187 -> V_190 & V_193 ) ) {
F_8 ( 1 , L_94 ) ;
return - V_84 ;
}
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_95 ) ;
return - V_121 ;
}
V_41 = F_99 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_19 = F_3 ( V_2 -> V_18 [ V_10 ] . V_19 ) ;
if ( V_19 < ( V_187 -> V_194 - V_187 -> V_195 ) ) {
F_8 ( 1 ,
L_96 ) ;
return - V_84 ;
}
F_40 ( & V_4 -> V_127 ) ;
V_41 = F_29 ( V_2 , V_116 , V_2 -> V_17 [ V_10 ] . V_9 , V_187 ) ;
F_41 ( & V_4 -> V_127 ) ;
if ( V_41 )
return V_41 ;
F_8 ( 3 , L_97 , V_32 , V_10 ) ;
return 0 ;
}
unsigned long F_103 ( struct V_3 * V_4 ,
unsigned long V_196 ,
unsigned long V_197 ,
unsigned long V_198 ,
unsigned long V_95 )
{
unsigned long V_35 = V_198 << V_189 ;
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
void * V_137 ;
int V_41 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_84 ) ;
return - V_84 ;
}
V_41 = F_99 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_137 = F_50 ( V_2 , V_10 ) ;
return V_137 ? ( unsigned long ) V_137 : - V_84 ;
}
unsigned int F_104 ( struct V_3 * V_4 , struct V_199 * V_199 , T_1 * V_200 )
{
struct V_201 * V_202 = F_105 ( V_199 ) ;
unsigned long V_203 = F_106 ( V_200 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_204 = 0 ;
unsigned long V_95 ;
if ( F_107 ( V_205 , & V_202 -> V_95 ) ) {
struct V_206 * V_207 = V_199 -> V_208 ;
if ( F_108 ( V_207 ) )
V_204 = V_209 ;
else if ( V_203 & V_209 )
F_109 ( V_199 , & V_207 -> V_200 , V_200 ) ;
}
if ( ! F_2 ( V_4 -> type ) && ! ( V_203 & ( V_210 | V_211 ) ) )
return V_204 ;
if ( F_2 ( V_4 -> type ) && ! ( V_203 & ( V_212 | V_213 ) ) )
return V_204 ;
if ( V_4 -> V_33 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_2 ( V_4 -> type ) && ( V_4 -> V_111 & V_214 ) &&
( V_203 & ( V_210 | V_211 ) ) ) {
if ( F_110 ( V_4 , 1 ) )
return V_204 | V_215 ;
}
if ( F_2 ( V_4 -> type ) && ( V_4 -> V_111 & V_216 ) &&
( V_203 & ( V_212 | V_213 ) ) ) {
if ( F_110 ( V_4 , 0 ) )
return V_204 | V_215 ;
return V_204 | V_212 | V_213 ;
}
}
if ( ! F_111 ( V_4 ) || V_4 -> error )
return V_204 | V_215 ;
if ( V_4 -> V_130 )
return V_204 | V_215 ;
if ( F_2 ( V_4 -> type ) && V_4 -> V_171 < V_4 -> V_33 )
return V_204 | V_212 | V_213 ;
if ( F_78 ( & V_4 -> V_143 ) )
F_109 ( V_199 , & V_4 -> V_145 , V_200 ) ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
if ( ! F_78 ( & V_4 -> V_143 ) )
V_2 = F_85 ( & V_4 -> V_143 , struct V_1 ,
V_142 ) ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
if ( V_2 && ( V_2 -> V_44 == V_106
|| V_2 -> V_44 == V_104 ) ) {
return ( F_2 ( V_4 -> type ) ) ?
V_204 | V_212 | V_213 :
V_204 | V_210 | V_211 ;
}
return V_204 ;
}
int F_112 ( struct V_3 * V_4 )
{
if ( F_53 ( ! V_4 ) ||
F_53 ( ! V_4 -> V_217 ) ||
F_53 ( ! V_4 -> V_113 ) ||
F_53 ( ! V_4 -> type ) ||
F_53 ( ! V_4 -> V_111 ) ||
F_53 ( ! V_4 -> V_217 -> V_128 ) ||
F_53 ( ! V_4 -> V_217 -> V_156 ) ||
F_53 ( V_4 -> V_97 &
~ ( V_98 |
V_100 ) ) )
return - V_84 ;
F_53 ( ( V_4 -> V_97 & V_98 ) ==
V_218 ) ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_143 ) ;
F_113 ( & V_4 -> V_141 ) ;
F_114 ( & V_4 -> V_127 ) ;
F_115 ( & V_4 -> V_145 ) ;
if ( V_4 -> V_42 == 0 )
V_4 -> V_42 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_116 ( struct V_3 * V_4 )
{
F_117 ( V_4 ) ;
F_42 ( V_4 ) ;
F_40 ( & V_4 -> V_127 ) ;
F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_127 ) ;
}
static int F_110 ( struct V_3 * V_4 , int V_219 )
{
struct V_220 * V_221 ;
int V_169 , V_41 ;
unsigned int V_126 = 0 ;
if ( F_53 ( ( V_219 && ! ( V_4 -> V_111 & V_214 ) ) ||
( ! V_219 && ! ( V_4 -> V_111 & V_216 ) ) ) )
return - V_84 ;
if ( ! V_4 -> V_113 -> V_137 )
return - V_121 ;
if ( V_4 -> V_125 || V_4 -> V_33 > 0 )
return - V_121 ;
V_126 = 1 ;
F_8 ( 3 , L_98 ,
( V_219 ) ? L_99 : L_100 , V_126 , V_4 -> V_222 ) ;
V_221 = F_16 ( sizeof( struct V_220 ) , V_43 ) ;
if ( V_221 == NULL )
return - V_21 ;
V_221 -> V_95 = V_4 -> V_222 ;
V_221 -> V_123 . V_126 = V_126 ;
V_221 -> V_123 . V_40 = V_46 ;
V_221 -> V_123 . type = V_4 -> type ;
V_4 -> V_221 = V_221 ;
V_41 = F_39 ( V_4 , & V_221 -> V_123 ) ;
if ( V_41 )
goto V_223;
if ( V_4 -> V_34 [ 0 ] -> V_11 != 1 ) {
V_41 = - V_121 ;
goto V_224;
}
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; V_169 ++ ) {
V_221 -> V_34 [ V_169 ] . V_137 = F_50 ( V_4 -> V_34 [ V_169 ] , 0 ) ;
if ( V_221 -> V_34 [ V_169 ] . V_137 == NULL ) {
V_41 = - V_84 ;
goto V_224;
}
V_221 -> V_34 [ V_169 ] . V_12 = F_118 ( V_4 -> V_34 [ V_169 ] , 0 ) ;
}
if ( V_219 ) {
bool V_225 = F_17 ( V_4 -> type ) ;
for ( V_169 = 0 ; V_169 < V_4 -> V_33 ; V_169 ++ ) {
struct V_82 * V_83 = & V_221 -> V_83 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> type = V_4 -> type ;
if ( V_225 ) {
memset ( & V_221 -> V_26 , 0 , sizeof( V_221 -> V_26 ) ) ;
V_83 -> V_37 . V_17 = & V_221 -> V_26 ;
V_83 -> V_19 = 1 ;
}
V_83 -> V_40 = V_4 -> V_40 ;
V_83 -> V_23 = V_169 ;
V_41 = F_79 ( V_4 , V_83 ) ;
if ( V_41 )
goto V_224;
V_221 -> V_34 [ V_169 ] . V_226 = 1 ;
}
V_221 -> V_227 = V_4 -> V_33 ;
V_221 -> V_228 = V_4 -> V_33 ;
}
V_41 = F_94 ( V_4 , V_4 -> type ) ;
if ( V_41 )
goto V_224;
return V_41 ;
V_224:
V_221 -> V_123 . V_126 = 0 ;
F_39 ( V_4 , & V_221 -> V_123 ) ;
V_223:
V_4 -> V_221 = NULL ;
F_18 ( V_221 ) ;
return V_41 ;
}
static int F_117 ( struct V_3 * V_4 )
{
struct V_220 * V_221 = V_4 -> V_221 ;
if ( V_221 ) {
F_97 ( V_4 , V_4 -> type ) ;
V_4 -> V_221 = NULL ;
V_221 -> V_123 . V_126 = 0 ;
F_46 ( V_4 , & V_221 -> V_123 ) ;
F_18 ( V_221 ) ;
F_8 ( 3 , L_101 ) ;
}
return 0 ;
}
static T_2 F_119 ( struct V_3 * V_4 , char T_3 * V_229 , T_2 V_126 ,
T_4 * V_230 , int V_231 , int V_219 )
{
struct V_220 * V_221 ;
struct V_232 * V_233 ;
bool V_225 = F_17 ( V_4 -> type ) ;
bool V_234 = ! V_219 &&
( V_4 -> V_97 & V_98 ) ==
V_99 ;
int V_41 , V_23 ;
F_8 ( 3 , L_102 ,
V_219 ? L_99 : L_100 , ( long ) * V_230 , V_126 ,
V_231 ? L_103 : L_12 ) ;
if ( ! V_229 )
return - V_84 ;
if ( ! F_38 ( V_4 ) ) {
V_41 = F_110 ( V_4 , V_219 ) ;
F_8 ( 3 , L_104 , V_41 ) ;
if ( V_41 )
return V_41 ;
}
V_221 = V_4 -> V_221 ;
V_23 = V_221 -> V_228 ;
if ( V_23 >= V_4 -> V_33 ) {
memset ( & V_221 -> V_83 , 0 , sizeof( V_221 -> V_83 ) ) ;
V_221 -> V_83 . type = V_4 -> type ;
V_221 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_225 ) {
memset ( & V_221 -> V_26 , 0 , sizeof( V_221 -> V_26 ) ) ;
V_221 -> V_83 . V_37 . V_17 = & V_221 -> V_26 ;
V_221 -> V_83 . V_19 = 1 ;
}
V_41 = F_90 ( V_4 , & V_221 -> V_83 , V_231 ) ;
F_8 ( 5 , L_105 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_221 -> V_235 += 1 ;
V_221 -> V_228 = V_23 = V_221 -> V_83 . V_23 ;
V_233 = & V_221 -> V_34 [ V_23 ] ;
V_233 -> V_236 = 0 ;
V_233 -> V_226 = 0 ;
V_233 -> V_12 = V_219 ? F_120 ( V_4 -> V_34 [ V_23 ] , 0 )
: F_118 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
if ( V_225 && V_219 &&
V_221 -> V_83 . V_37 . V_17 [ 0 ] . V_88 < V_233 -> V_12 ) {
V_233 -> V_236 = V_221 -> V_83 . V_37 . V_17 [ 0 ] . V_88 ;
V_233 -> V_12 -= V_233 -> V_236 ;
}
} else {
V_233 = & V_221 -> V_34 [ V_23 ] ;
}
if ( V_233 -> V_236 + V_126 > V_233 -> V_12 ) {
V_126 = V_233 -> V_12 - V_233 -> V_236 ;
F_8 ( 5 , L_106 , V_126 ) ;
}
F_8 ( 3 , L_107 ,
V_126 , V_23 , V_233 -> V_236 ) ;
if ( V_219 )
V_41 = F_121 ( V_229 , V_233 -> V_137 + V_233 -> V_236 , V_126 ) ;
else
V_41 = F_122 ( V_233 -> V_137 + V_233 -> V_236 , V_229 , V_126 ) ;
if ( V_41 ) {
F_8 ( 3 , L_108 ) ;
return - V_237 ;
}
V_233 -> V_236 += V_126 ;
* V_230 += V_126 ;
if ( V_233 -> V_236 == V_233 -> V_12 ||
( ! V_219 && ( V_221 -> V_95 & V_238 ) ) ) {
if ( V_219 && ( V_221 -> V_95 & V_239 ) &&
V_221 -> V_235 == 1 ) {
F_8 ( 3 , L_109 ) ;
return F_117 ( V_4 ) ;
}
memset ( & V_221 -> V_83 , 0 , sizeof( V_221 -> V_83 ) ) ;
V_221 -> V_83 . type = V_4 -> type ;
V_221 -> V_83 . V_40 = V_4 -> V_40 ;
V_221 -> V_83 . V_23 = V_23 ;
V_221 -> V_83 . V_86 = V_233 -> V_236 ;
if ( V_225 ) {
memset ( & V_221 -> V_26 , 0 , sizeof( V_221 -> V_26 ) ) ;
V_221 -> V_26 . V_86 = V_233 -> V_236 ;
V_221 -> V_83 . V_37 . V_17 = & V_221 -> V_26 ;
V_221 -> V_83 . V_19 = 1 ;
}
if ( V_234 )
F_123 ( & V_221 -> V_83 . V_159 ) ;
V_41 = F_79 ( V_4 , & V_221 -> V_83 ) ;
F_8 ( 5 , L_110 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_233 -> V_236 = 0 ;
V_233 -> V_226 = 1 ;
V_233 -> V_12 = F_118 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
V_221 -> V_240 += 1 ;
if ( V_221 -> V_227 < V_4 -> V_33 )
V_221 -> V_227 ++ ;
V_221 -> V_228 = V_221 -> V_227 ;
}
if ( V_41 == 0 )
V_41 = V_126 ;
return V_41 ;
}
T_2 F_124 ( struct V_3 * V_4 , char T_3 * V_229 , T_2 V_126 ,
T_4 * V_230 , int V_173 )
{
return F_119 ( V_4 , V_229 , V_126 , V_230 , V_173 , 1 ) ;
}
T_2 F_125 ( struct V_3 * V_4 , const char T_3 * V_229 , T_2 V_126 ,
T_4 * V_230 , int V_173 )
{
return F_119 ( V_4 , ( char T_3 * ) V_229 , V_126 ,
V_230 , V_173 , 0 ) ;
}
static int F_126 ( void * V_229 )
{
struct V_3 * V_4 = V_229 ;
struct V_241 * V_242 = V_4 -> V_242 ;
struct V_220 * V_221 = V_4 -> V_221 ;
bool V_234 = false ;
int V_243 = 0 ;
int V_23 = 0 ;
int V_41 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
V_243 = V_4 -> V_33 ;
V_234 =
( V_4 -> V_97 & V_98 ) ==
V_99 ;
}
F_127 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_221 -> V_83 , 0 , sizeof( V_221 -> V_83 ) ) ;
V_221 -> V_83 . type = V_4 -> type ;
V_221 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_243 ) {
V_221 -> V_83 . V_23 = V_23 ++ ;
V_243 -- ;
} else {
F_82 ( V_4 , V_175 , V_4 ) ;
if ( ! V_242 -> V_244 )
V_41 = F_90 ( V_4 , & V_221 -> V_83 , 0 ) ;
F_82 ( V_4 , V_174 , V_4 ) ;
F_8 ( 5 , L_111 , V_41 ) ;
}
if ( V_41 || V_242 -> V_244 )
break;
F_128 () ;
V_2 = V_4 -> V_34 [ V_221 -> V_83 . V_23 ] ;
if ( ! ( V_221 -> V_83 . V_95 & V_105 ) )
if ( V_242 -> V_245 ( V_2 , V_242 -> V_246 ) )
break;
F_82 ( V_4 , V_175 , V_4 ) ;
if ( V_234 )
F_123 ( & V_221 -> V_83 . V_159 ) ;
if ( ! V_242 -> V_244 )
V_41 = F_79 ( V_4 , & V_221 -> V_83 ) ;
F_82 ( V_4 , V_174 , V_4 ) ;
if ( V_41 || V_242 -> V_244 )
break;
}
while ( ! F_129 () ) {
F_130 ( V_247 ) ;
F_131 () ;
}
return 0 ;
}
int F_132 ( struct V_3 * V_4 , T_5 V_245 , void * V_246 ,
const char * V_248 )
{
struct V_241 * V_242 ;
int V_41 = 0 ;
if ( V_4 -> V_242 )
return - V_121 ;
if ( F_133 ( V_4 ) )
return - V_121 ;
if ( F_53 ( V_4 -> V_221 ) )
return - V_121 ;
V_242 = F_16 ( sizeof( * V_242 ) , V_43 ) ;
if ( V_242 == NULL )
return - V_21 ;
V_242 -> V_245 = V_245 ;
V_242 -> V_246 = V_246 ;
V_41 = F_110 ( V_4 , ! F_2 ( V_4 -> type ) ) ;
F_8 ( 3 , L_112 , V_41 ) ;
if ( V_41 )
goto V_249;
V_4 -> V_242 = V_242 ;
V_242 -> V_250 = F_134 ( F_126 , V_4 , L_113 , V_248 ) ;
if ( F_67 ( V_242 -> V_250 ) ) {
V_41 = F_64 ( V_242 -> V_250 ) ;
V_242 -> V_250 = NULL ;
goto V_251;
}
return 0 ;
V_251:
F_117 ( V_4 ) ;
V_249:
F_18 ( V_242 ) ;
return V_41 ;
}
int F_135 ( struct V_3 * V_4 )
{
struct V_241 * V_242 = V_4 -> V_242 ;
struct V_220 * V_221 = V_4 -> V_221 ;
int V_153 ;
if ( V_242 == NULL )
return 0 ;
V_242 -> V_244 = true ;
F_95 ( V_4 ) ;
V_153 = F_136 ( V_242 -> V_250 ) ;
F_117 ( V_4 ) ;
V_242 -> V_250 = NULL ;
F_18 ( V_242 ) ;
V_4 -> V_242 = NULL ;
return V_153 ;
}
static inline bool F_137 ( struct V_201 * V_252 , struct V_199 * V_199 )
{
return V_252 -> V_253 -> V_254 && V_252 -> V_253 -> V_254 != V_199 -> V_208 ;
}
int F_138 ( struct V_199 * V_199 , void * V_246 ,
struct V_122 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
int V_204 = F_37 ( V_252 -> V_253 , V_26 -> V_40 , V_26 -> type ) ;
if ( V_204 )
return V_204 ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
V_204 = F_39 ( V_252 -> V_253 , V_26 ) ;
if ( V_204 == 0 )
V_252 -> V_253 -> V_254 = V_26 -> V_126 ? V_199 -> V_208 : NULL ;
return V_204 ;
}
int F_139 ( struct V_199 * V_199 , void * V_246 ,
struct V_131 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
int V_204 = F_37 ( V_252 -> V_253 , V_26 -> V_40 , V_26 -> V_135 . type ) ;
V_26 -> V_23 = V_252 -> V_253 -> V_33 ;
if ( V_26 -> V_126 == 0 )
return V_204 != - V_121 ? V_204 : 0 ;
if ( V_204 )
return V_204 ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
V_204 = F_47 ( V_252 -> V_253 , V_26 ) ;
if ( V_204 == 0 )
V_252 -> V_253 -> V_254 = V_199 -> V_208 ;
return V_204 ;
}
int F_140 ( struct V_199 * V_199 , void * V_246 ,
struct V_82 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_75 ( V_252 -> V_253 , V_26 ) ;
}
int F_141 ( struct V_199 * V_199 , void * V_246 , struct V_82 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
return F_33 ( V_252 -> V_253 , V_26 ) ;
}
int F_142 ( struct V_199 * V_199 , void * V_246 , struct V_82 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_80 ( V_252 -> V_253 , V_26 ) ;
}
int F_143 ( struct V_199 * V_199 , void * V_246 , struct V_82 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_91 ( V_252 -> V_253 , V_26 , V_199 -> V_255 & V_256 ) ;
}
int F_144 ( struct V_199 * V_199 , void * V_246 , enum V_120 V_169 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_96 ( V_252 -> V_253 , V_169 ) ;
}
int F_145 ( struct V_199 * V_199 , void * V_246 , enum V_120 V_169 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_98 ( V_252 -> V_253 , V_169 ) ;
}
int F_146 ( struct V_199 * V_199 , void * V_246 , struct V_180 * V_26 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( F_137 ( V_252 , V_199 ) )
return - V_121 ;
return F_100 ( V_252 -> V_253 , V_26 ) ;
}
int F_147 ( struct V_199 * V_199 , struct V_186 * V_187 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
return F_102 ( V_252 -> V_253 , V_187 ) ;
}
int F_148 ( struct V_199 * V_199 , struct V_257 * V_258 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
if ( V_258 )
F_40 ( V_258 ) ;
if ( V_199 -> V_208 == V_252 -> V_253 -> V_254 ) {
F_116 ( V_252 -> V_253 ) ;
V_252 -> V_253 -> V_254 = NULL ;
}
if ( V_258 )
F_41 ( V_258 ) ;
return F_149 ( V_199 ) ;
}
int F_150 ( struct V_199 * V_199 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
struct V_257 * V_258 = V_252 -> V_253 -> V_258 ? V_252 -> V_253 -> V_258 : V_252 -> V_258 ;
return F_148 ( V_199 , V_258 ) ;
}
T_6 F_151 ( struct V_199 * V_199 , const char T_3 * V_233 ,
T_2 V_126 , T_4 * V_230 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
struct V_257 * V_258 = V_252 -> V_253 -> V_258 ? V_252 -> V_253 -> V_258 : V_252 -> V_258 ;
int V_153 = - V_121 ;
if ( V_258 && F_152 ( V_258 ) )
return - V_259 ;
if ( F_137 ( V_252 , V_199 ) )
goto exit;
V_153 = F_125 ( V_252 -> V_253 , V_233 , V_126 , V_230 ,
V_199 -> V_255 & V_256 ) ;
if ( V_252 -> V_253 -> V_221 )
V_252 -> V_253 -> V_254 = V_199 -> V_208 ;
exit:
if ( V_258 )
F_41 ( V_258 ) ;
return V_153 ;
}
T_6 F_153 ( struct V_199 * V_199 , char T_3 * V_233 ,
T_2 V_126 , T_4 * V_230 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
struct V_257 * V_258 = V_252 -> V_253 -> V_258 ? V_252 -> V_253 -> V_258 : V_252 -> V_258 ;
int V_153 = - V_121 ;
if ( V_258 && F_152 ( V_258 ) )
return - V_259 ;
if ( F_137 ( V_252 , V_199 ) )
goto exit;
V_153 = F_124 ( V_252 -> V_253 , V_233 , V_126 , V_230 ,
V_199 -> V_255 & V_256 ) ;
if ( V_252 -> V_253 -> V_221 )
V_252 -> V_253 -> V_254 = V_199 -> V_208 ;
exit:
if ( V_258 )
F_41 ( V_258 ) ;
return V_153 ;
}
unsigned int F_154 ( struct V_199 * V_199 , T_1 * V_200 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
struct V_3 * V_4 = V_252 -> V_253 ;
struct V_257 * V_258 = V_4 -> V_258 ? V_4 -> V_258 : V_252 -> V_258 ;
unsigned V_204 ;
void * V_221 ;
F_53 ( ! V_258 ) ;
if ( V_258 && F_152 ( V_258 ) )
return V_215 ;
V_221 = V_4 -> V_221 ;
V_204 = F_104 ( V_252 -> V_253 , V_199 , V_200 ) ;
if ( ! V_221 && V_4 -> V_221 )
V_4 -> V_254 = V_199 -> V_208 ;
if ( V_258 )
F_41 ( V_258 ) ;
return V_204 ;
}
unsigned long F_155 ( struct V_199 * V_199 , unsigned long V_196 ,
unsigned long V_197 , unsigned long V_198 , unsigned long V_95 )
{
struct V_201 * V_252 = F_105 ( V_199 ) ;
return F_103 ( V_252 -> V_253 , V_196 , V_197 , V_198 , V_95 ) ;
}
void F_156 ( struct V_3 * V_260 )
{
F_41 ( V_260 -> V_258 ) ;
}
void F_157 ( struct V_3 * V_260 )
{
F_40 ( V_260 -> V_258 ) ;
}
