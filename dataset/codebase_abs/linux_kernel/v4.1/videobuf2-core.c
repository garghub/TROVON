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
if ( F_2 ( V_83 -> type ) ) {
if ( F_62 ( V_83 -> V_86 == 0 ) ) {
F_63 ( L_39 ) ;
if ( V_2 -> V_3 -> V_146 )
F_63 ( L_40 ) ;
else
F_63 ( L_41 ) ;
}
}
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
struct V_36 * V_147 = & V_18 [ V_10 ] ;
struct V_36 * V_148 = & V_83 -> V_37 . V_17 [ V_10 ] ;
if ( V_2 -> V_3 -> V_146 )
V_147 -> V_86 = V_148 -> V_86 ;
else
V_147 -> V_86 = V_148 -> V_86 ?
V_148 -> V_86 : V_147 -> V_19 ;
V_147 -> V_88 = V_148 -> V_88 ;
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
if ( V_2 -> V_3 -> V_146 )
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
V_2 -> V_22 . V_95 &= ~ V_149 ;
V_2 -> V_22 . V_150 = V_83 -> V_150 ;
} else {
V_2 -> V_22 . V_95 &= ~ V_151 ;
}
}
static int F_64 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
F_61 ( V_2 , V_83 , V_2 -> V_18 ) ;
return F_19 ( V_2 , V_152 , V_2 ) ;
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
bool V_153 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_61 ( V_2 , V_83 , V_17 ) ;
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
goto V_154;
}
if ( V_2 -> V_17 [ V_10 ] . V_9 ) {
if ( ! V_153 ) {
V_153 = true ;
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
F_8 ( 1 , L_46
L_47 , V_10 ) ;
V_41 = V_9 ? F_66 ( V_9 ) : - V_84 ;
goto V_154;
}
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_153 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_48 ) ;
goto V_154;
}
}
V_41 = F_19 ( V_2 , V_152 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_49 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_154;
}
return 0 ;
V_154:
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_17 [ V_10 ] . V_9 )
F_6 ( V_2 , V_24 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
V_2 -> V_17 [ V_10 ] . V_9 = NULL ;
V_2 -> V_18 [ V_10 ] . V_37 . V_93 = 0 ;
V_2 -> V_18 [ V_10 ] . V_19 = 0 ;
}
return V_41 ;
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
bool V_153 = V_2 -> V_17 [ 0 ] . V_9 == NULL ;
memset ( V_17 , 0 , sizeof( V_17 [ 0 ] ) * V_2 -> V_11 ) ;
F_61 ( V_2 , V_83 , V_17 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
struct V_155 * V_30 = F_68 ( V_17 [ V_10 ] . V_37 . V_94 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_50 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_154;
}
if ( V_17 [ V_10 ] . V_19 == 0 )
V_17 [ V_10 ] . V_19 = V_30 -> V_12 ;
if ( V_17 [ V_10 ] . V_19 < V_4 -> V_13 [ V_10 ] ) {
F_8 ( 1 , L_51 ,
V_10 ) ;
V_41 = - V_84 ;
goto V_154;
}
if ( V_30 == V_2 -> V_17 [ V_10 ] . V_30 &&
V_2 -> V_18 [ V_10 ] . V_19 == V_17 [ V_10 ] . V_19 ) {
F_11 ( V_30 ) ;
continue;
}
F_8 ( 1 , L_52 , V_10 ) ;
if ( ! V_153 ) {
V_153 = true ;
F_22 ( V_2 , V_52 , V_2 ) ;
}
F_10 ( V_2 , & V_2 -> V_17 [ V_10 ] ) ;
memset ( & V_2 -> V_18 [ V_10 ] , 0 , sizeof( struct V_36 ) ) ;
V_9 = F_4 ( V_2 , V_118 , V_4 -> V_15 [ V_10 ] ,
V_30 , V_17 [ V_10 ] . V_19 , V_6 ) ;
if ( F_69 ( V_9 ) ) {
F_8 ( 1 , L_53 ) ;
V_41 = F_66 ( V_9 ) ;
F_11 ( V_30 ) ;
goto V_154;
}
V_2 -> V_17 [ V_10 ] . V_30 = V_30 ;
V_2 -> V_17 [ V_10 ] . V_9 = V_9 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
V_41 = F_29 ( V_2 , V_119 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
if ( V_41 ) {
F_8 ( 1 , L_54 ,
V_10 ) ;
goto V_154;
}
V_2 -> V_17 [ V_10 ] . V_27 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
V_2 -> V_18 [ V_10 ] = V_17 [ V_10 ] ;
if ( V_153 ) {
V_41 = F_19 ( V_2 , V_47 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_48 ) ;
goto V_154;
}
}
V_41 = F_19 ( V_2 , V_152 , V_2 ) ;
if ( V_41 ) {
F_8 ( 1 , L_49 ) ;
F_22 ( V_2 , V_52 , V_2 ) ;
goto V_154;
}
return 0 ;
V_154:
F_12 ( V_2 ) ;
return V_41 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_10 ;
V_2 -> V_44 = V_102 ;
F_71 ( & V_4 -> V_144 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 )
F_6 ( V_2 , V_156 , V_2 -> V_17 [ V_10 ] . V_9 ) ;
F_22 ( V_2 , V_157 , V_2 ) ;
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
if ( V_83 -> V_150 == V_158 && F_2 ( V_4 -> type ) ) {
F_8 ( 1 , L_56 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_57 ) ;
return - V_159 ;
}
V_2 -> V_44 = V_50 ;
V_2 -> V_22 . V_160 . V_161 = 0 ;
V_2 -> V_22 . V_160 . V_162 = 0 ;
V_2 -> V_22 . V_163 = 0 ;
switch ( V_4 -> V_40 ) {
case V_46 :
V_41 = F_64 ( V_2 , V_83 ) ;
break;
case V_87 :
F_73 ( & V_164 -> V_165 -> V_166 ) ;
V_41 = F_65 ( V_2 , V_83 ) ;
F_74 ( & V_164 -> V_165 -> V_166 ) ;
break;
case V_49 :
V_41 = F_67 ( V_2 , V_83 ) ;
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
return - V_121 ;
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
F_60 (vb, &q->queued_list, queued_entry)
F_70 ( V_2 ) ;
V_4 -> V_168 = 1 ;
V_41 = F_45 ( V_4 , V_169 , V_4 ,
F_79 ( & V_4 -> V_144 ) ) ;
if ( ! V_41 )
return 0 ;
V_4 -> V_168 = 0 ;
F_8 ( 1 , L_67 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_144 ) ) ) {
unsigned V_170 ;
for ( V_170 = 0 ; V_170 < V_4 -> V_33 ; ++ V_170 ) {
V_2 = V_4 -> V_34 [ V_170 ] ;
if ( V_2 -> V_44 == V_102 )
F_52 ( V_2 , V_101 ) ;
}
F_53 ( F_79 ( & V_4 -> V_144 ) ) ;
}
F_53 ( ! F_80 ( & V_4 -> V_143 ) ) ;
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
F_55 ( & V_2 -> V_171 , & V_4 -> V_81 ) ;
V_4 -> V_172 ++ ;
V_4 -> V_130 = false ;
V_2 -> V_44 = V_101 ;
if ( F_2 ( V_4 -> type ) ) {
if ( ( V_4 -> V_97 & V_98 ) ==
V_99 )
V_2 -> V_22 . V_160 = V_83 -> V_160 ;
V_2 -> V_22 . V_95 |= V_83 -> V_95 & V_149 ;
if ( V_83 -> V_95 & V_149 )
V_2 -> V_22 . V_173 = V_83 -> V_173 ;
}
if ( V_4 -> V_168 )
F_70 ( V_2 ) ;
F_31 ( V_2 , V_83 ) ;
if ( V_4 -> V_125 && ! V_4 -> V_168 &&
V_4 -> V_172 >= V_4 -> V_129 ) {
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
return - V_121 ;
}
return F_81 ( V_4 , V_83 ) ;
}
static int F_83 ( struct V_3 * V_4 , int V_174 )
{
for (; ; ) {
int V_41 ;
if ( ! V_4 -> V_125 ) {
F_8 ( 1 , L_71 ) ;
return - V_84 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_72 ) ;
return - V_159 ;
}
if ( ! F_80 ( & V_4 -> V_143 ) ) {
break;
}
if ( V_174 ) {
F_8 ( 1 , L_73
L_74 ) ;
return - V_51 ;
}
F_84 ( V_4 , V_175 , V_4 ) ;
F_8 ( 3 , L_75 ) ;
V_41 = F_85 ( V_4 -> V_145 ,
! F_80 ( & V_4 -> V_143 ) || ! V_4 -> V_125 ||
V_4 -> error ) ;
F_84 ( V_4 , V_176 , V_4 ) ;
if ( V_41 ) {
F_8 ( 1 , L_76 ) ;
return V_41 ;
}
}
return 0 ;
}
static int F_86 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_82 * V_83 , int V_174 )
{
unsigned long V_95 ;
int V_41 ;
V_41 = F_83 ( V_4 , V_174 ) ;
if ( V_41 )
return V_41 ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
* V_2 = F_87 ( & V_4 -> V_143 , struct V_1 , V_142 ) ;
V_41 = F_26 ( * V_2 , V_83 ) ;
if ( ! V_41 )
F_88 ( & ( * V_2 ) -> V_142 ) ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
return V_41 ;
}
int F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_125 ) {
F_8 ( 1 , L_71 ) ;
return - V_84 ;
}
if ( V_4 -> V_168 )
F_90 ( V_4 -> V_145 , ! F_79 ( & V_4 -> V_144 ) ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_170 ;
if ( V_2 -> V_44 == V_45 )
return;
V_2 -> V_44 = V_45 ;
if ( V_4 -> V_40 == V_49 )
for ( V_170 = 0 ; V_170 < V_2 -> V_11 ; ++ V_170 ) {
if ( ! V_2 -> V_17 [ V_170 ] . V_27 )
continue;
F_6 ( V_2 , V_28 , V_2 -> V_17 [ V_170 ] . V_9 ) ;
V_2 -> V_17 [ V_170 ] . V_27 = 0 ;
}
}
static int F_92 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_174 )
{
struct V_1 * V_2 = NULL ;
int V_41 ;
if ( V_83 -> type != V_4 -> type ) {
F_8 ( 1 , L_77 ) ;
return - V_84 ;
}
V_41 = F_86 ( V_4 , & V_2 , V_83 , V_174 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_2 -> V_44 ) {
case V_106 :
F_8 ( 3 , L_78 ) ;
break;
case V_104 :
F_8 ( 3 , L_79 ) ;
break;
default:
F_8 ( 1 , L_80 ) ;
return - V_84 ;
}
F_22 ( V_2 , V_177 , V_2 ) ;
F_31 ( V_2 , V_83 ) ;
F_88 ( & V_2 -> V_171 ) ;
V_4 -> V_172 -- ;
F_91 ( V_2 ) ;
F_8 ( 1 , L_81 ,
V_2 -> V_22 . V_23 , V_2 -> V_44 ) ;
return 0 ;
}
int F_93 ( struct V_3 * V_4 , struct V_82 * V_83 , bool V_174 )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_92 ( V_4 , V_83 , V_174 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
unsigned int V_170 ;
if ( V_4 -> V_168 )
F_84 ( V_4 , V_178 , V_4 ) ;
if ( F_53 ( F_79 ( & V_4 -> V_144 ) ) ) {
for ( V_170 = 0 ; V_170 < V_4 -> V_33 ; ++ V_170 )
if ( V_4 -> V_34 [ V_170 ] -> V_44 == V_102 )
F_52 ( V_4 -> V_34 [ V_170 ] , V_104 ) ;
F_53 ( F_79 ( & V_4 -> V_144 ) ) ;
}
V_4 -> V_125 = 0 ;
V_4 -> V_168 = 0 ;
V_4 -> V_172 = 0 ;
V_4 -> error = 0 ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_143 ) ;
F_94 ( & V_4 -> V_144 , 0 ) ;
F_95 ( & V_4 -> V_145 ) ;
for ( V_170 = 0 ; V_170 < V_4 -> V_33 ; ++ V_170 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_170 ] ;
if ( V_2 -> V_44 != V_45 ) {
V_2 -> V_44 = V_108 ;
F_22 ( V_2 , V_177 , V_2 ) ;
}
F_91 ( V_2 ) ;
}
}
static int F_96 ( struct V_3 * V_4 , enum V_120 type )
{
int V_41 ;
if ( type != V_4 -> type ) {
F_8 ( 1 , L_82 ) ;
return - V_84 ;
}
if ( V_4 -> V_125 ) {
F_8 ( 3 , L_83 ) ;
return 0 ;
}
if ( ! V_4 -> V_33 ) {
F_8 ( 1 , L_84 ) ;
return - V_84 ;
}
if ( V_4 -> V_33 < V_4 -> V_129 ) {
F_8 ( 1 , L_85 ,
V_4 -> V_129 ) ;
return - V_84 ;
}
if ( V_4 -> V_172 >= V_4 -> V_129 ) {
V_41 = F_78 ( V_4 ) ;
if ( V_41 ) {
F_42 ( V_4 ) ;
return V_41 ;
}
}
V_4 -> V_125 = 1 ;
F_8 ( 3 , L_86 ) ;
return 0 ;
}
void F_97 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_95 ( & V_4 -> V_145 ) ;
}
int F_98 ( struct V_3 * V_4 , enum V_120 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_96 ( V_4 , type ) ;
}
static int F_99 ( struct V_3 * V_4 , enum V_120 type )
{
if ( type != V_4 -> type ) {
F_8 ( 1 , L_82 ) ;
return - V_84 ;
}
F_42 ( V_4 ) ;
V_4 -> V_130 = ! F_2 ( V_4 -> type ) ;
F_8 ( 3 , L_86 ) ;
return 0 ;
}
int F_100 ( struct V_3 * V_4 , enum V_120 type )
{
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_33 ) ;
return - V_121 ;
}
return F_99 ( V_4 , type ) ;
}
static int F_101 ( struct V_3 * V_4 , unsigned long V_35 ,
unsigned int * V_179 , unsigned int * V_180 )
{
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_33 ; ++ V_32 ) {
V_2 = V_4 -> V_34 [ V_32 ] ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; ++ V_10 ) {
if ( V_2 -> V_18 [ V_10 ] . V_37 . V_38 == V_35 ) {
* V_179 = V_32 ;
* V_180 = V_10 ;
return 0 ;
}
}
}
return - V_84 ;
}
int F_102 ( struct V_3 * V_4 , struct V_181 * V_182 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_183 ;
int V_41 ;
struct V_155 * V_30 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_87 ) ;
return - V_84 ;
}
if ( ! V_4 -> V_113 -> V_184 ) {
F_8 ( 1 , L_88 ) ;
return - V_84 ;
}
if ( V_182 -> V_95 & ~ ( V_185 | V_186 ) ) {
F_8 ( 1 , L_89 ) ;
return - V_84 ;
}
if ( V_182 -> type != V_4 -> type ) {
F_8 ( 1 , L_77 ) ;
return - V_84 ;
}
if ( V_182 -> V_23 >= V_4 -> V_33 ) {
F_8 ( 1 , L_27 ) ;
return - V_84 ;
}
V_2 = V_4 -> V_34 [ V_182 -> V_23 ] ;
if ( V_182 -> V_10 >= V_2 -> V_11 ) {
F_8 ( 1 , L_90 ) ;
return - V_84 ;
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_91 ) ;
return - V_121 ;
}
V_183 = & V_2 -> V_17 [ V_182 -> V_10 ] ;
V_30 = F_4 ( V_2 , V_184 , V_183 -> V_9 , V_182 -> V_95 & V_186 ) ;
if ( F_5 ( V_30 ) ) {
F_8 ( 1 , L_92 ,
V_182 -> V_23 , V_182 -> V_10 ) ;
return - V_84 ;
}
V_41 = F_103 ( V_30 , V_182 -> V_95 & ~ V_186 ) ;
if ( V_41 < 0 ) {
F_8 ( 3 , L_93 ,
V_182 -> V_23 , V_182 -> V_10 , V_41 ) ;
F_11 ( V_30 ) ;
return V_41 ;
}
F_8 ( 3 , L_94 ,
V_182 -> V_23 , V_182 -> V_10 , V_41 ) ;
V_182 -> V_94 = V_41 ;
return 0 ;
}
int F_104 ( struct V_3 * V_4 , struct V_187 * V_188 )
{
unsigned long V_35 = V_188 -> V_189 << V_190 ;
struct V_1 * V_2 ;
unsigned int V_32 = 0 , V_10 = 0 ;
int V_41 ;
unsigned long V_19 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_87 ) ;
return - V_84 ;
}
if ( ! ( V_188 -> V_191 & V_192 ) ) {
F_8 ( 1 , L_95 ) ;
return - V_84 ;
}
if ( F_2 ( V_4 -> type ) ) {
if ( ! ( V_188 -> V_191 & V_193 ) ) {
F_8 ( 1 , L_96 ) ;
return - V_84 ;
}
} else {
if ( ! ( V_188 -> V_191 & V_194 ) ) {
F_8 ( 1 , L_97 ) ;
return - V_84 ;
}
}
if ( F_38 ( V_4 ) ) {
F_8 ( 1 , L_98 ) ;
return - V_121 ;
}
V_41 = F_101 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_19 = F_3 ( V_2 -> V_18 [ V_10 ] . V_19 ) ;
if ( V_19 < ( V_188 -> V_195 - V_188 -> V_196 ) ) {
F_8 ( 1 ,
L_99 ) ;
return - V_84 ;
}
F_40 ( & V_4 -> V_127 ) ;
V_41 = F_29 ( V_2 , V_116 , V_2 -> V_17 [ V_10 ] . V_9 , V_188 ) ;
F_41 ( & V_4 -> V_127 ) ;
if ( V_41 )
return V_41 ;
F_8 ( 3 , L_100 , V_32 , V_10 ) ;
return 0 ;
}
unsigned long F_105 ( struct V_3 * V_4 ,
unsigned long V_197 ,
unsigned long V_198 ,
unsigned long V_199 ,
unsigned long V_95 )
{
unsigned long V_35 = V_199 << V_190 ;
struct V_1 * V_2 ;
unsigned int V_32 , V_10 ;
void * V_137 ;
int V_41 ;
if ( V_4 -> V_40 != V_46 ) {
F_8 ( 1 , L_87 ) ;
return - V_84 ;
}
V_41 = F_101 ( V_4 , V_35 , & V_32 , & V_10 ) ;
if ( V_41 )
return V_41 ;
V_2 = V_4 -> V_34 [ V_32 ] ;
V_137 = F_50 ( V_2 , V_10 ) ;
return V_137 ? ( unsigned long ) V_137 : - V_84 ;
}
unsigned int F_106 ( struct V_3 * V_4 , struct V_200 * V_200 , T_1 * V_201 )
{
struct V_202 * V_203 = F_107 ( V_200 ) ;
unsigned long V_204 = F_108 ( V_201 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_205 = 0 ;
unsigned long V_95 ;
if ( F_109 ( V_206 , & V_203 -> V_95 ) ) {
struct V_207 * V_208 = V_200 -> V_209 ;
if ( F_110 ( V_208 ) )
V_205 = V_210 ;
else if ( V_204 & V_210 )
F_111 ( V_200 , & V_208 -> V_201 , V_201 ) ;
}
if ( ! F_2 ( V_4 -> type ) && ! ( V_204 & ( V_211 | V_212 ) ) )
return V_205 ;
if ( F_2 ( V_4 -> type ) && ! ( V_204 & ( V_213 | V_214 ) ) )
return V_205 ;
if ( V_4 -> V_33 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_2 ( V_4 -> type ) && ( V_4 -> V_111 & V_215 ) &&
( V_204 & ( V_211 | V_212 ) ) ) {
if ( F_112 ( V_4 , 1 ) )
return V_205 | V_216 ;
}
if ( F_2 ( V_4 -> type ) && ( V_4 -> V_111 & V_217 ) &&
( V_204 & ( V_213 | V_214 ) ) ) {
if ( F_112 ( V_4 , 0 ) )
return V_205 | V_216 ;
return V_205 | V_213 | V_214 ;
}
}
if ( ! F_113 ( V_4 ) || V_4 -> error )
return V_205 | V_216 ;
if ( V_4 -> V_130 )
return V_205 | V_216 ;
if ( F_2 ( V_4 -> type ) && V_4 -> V_172 < V_4 -> V_33 )
return V_205 | V_213 | V_214 ;
if ( F_80 ( & V_4 -> V_143 ) )
F_111 ( V_200 , & V_4 -> V_145 , V_201 ) ;
F_54 ( & V_4 -> V_141 , V_95 ) ;
if ( ! F_80 ( & V_4 -> V_143 ) )
V_2 = F_87 ( & V_4 -> V_143 , struct V_1 ,
V_142 ) ;
F_57 ( & V_4 -> V_141 , V_95 ) ;
if ( V_2 && ( V_2 -> V_44 == V_106
|| V_2 -> V_44 == V_104 ) ) {
return ( F_2 ( V_4 -> type ) ) ?
V_205 | V_213 | V_214 :
V_205 | V_211 | V_212 ;
}
return V_205 ;
}
int F_114 ( struct V_3 * V_4 )
{
if ( F_53 ( ! V_4 ) ||
F_53 ( ! V_4 -> V_218 ) ||
F_53 ( ! V_4 -> V_113 ) ||
F_53 ( ! V_4 -> type ) ||
F_53 ( ! V_4 -> V_111 ) ||
F_53 ( ! V_4 -> V_218 -> V_128 ) ||
F_53 ( ! V_4 -> V_218 -> V_157 ) ||
F_53 ( V_4 -> V_97 &
~ ( V_98 |
V_100 ) ) )
return - V_84 ;
F_53 ( ( V_4 -> V_97 & V_98 ) ==
V_219 ) ;
F_25 ( & V_4 -> V_81 ) ;
F_25 ( & V_4 -> V_143 ) ;
F_115 ( & V_4 -> V_141 ) ;
F_116 ( & V_4 -> V_127 ) ;
F_117 ( & V_4 -> V_145 ) ;
if ( V_4 -> V_42 == 0 )
V_4 -> V_42 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_118 ( struct V_3 * V_4 )
{
F_119 ( V_4 ) ;
F_42 ( V_4 ) ;
F_40 ( & V_4 -> V_127 ) ;
F_21 ( V_4 , V_4 -> V_33 ) ;
F_41 ( & V_4 -> V_127 ) ;
}
static int F_112 ( struct V_3 * V_4 , int V_220 )
{
struct V_221 * V_222 ;
int V_170 , V_41 ;
unsigned int V_126 = 0 ;
if ( F_53 ( ( V_220 && ! ( V_4 -> V_111 & V_215 ) ) ||
( ! V_220 && ! ( V_4 -> V_111 & V_217 ) ) ) )
return - V_84 ;
if ( ! V_4 -> V_113 -> V_137 )
return - V_121 ;
if ( V_4 -> V_125 || V_4 -> V_33 > 0 )
return - V_121 ;
V_126 = 1 ;
F_8 ( 3 , L_101 ,
( V_220 ) ? L_102 : L_103 , V_126 , V_4 -> V_223 ,
V_4 -> V_224 ) ;
V_222 = F_16 ( sizeof( struct V_221 ) , V_43 ) ;
if ( V_222 == NULL )
return - V_21 ;
V_222 -> V_225 = V_4 -> V_223 ;
V_222 -> V_226 = V_4 -> V_224 ;
V_222 -> V_123 . V_126 = V_126 ;
V_222 -> V_123 . V_40 = V_46 ;
V_222 -> V_123 . type = V_4 -> type ;
V_4 -> V_222 = V_222 ;
V_41 = F_39 ( V_4 , & V_222 -> V_123 ) ;
if ( V_41 )
goto V_227;
if ( V_4 -> V_34 [ 0 ] -> V_11 != 1 ) {
V_41 = - V_121 ;
goto V_228;
}
for ( V_170 = 0 ; V_170 < V_4 -> V_33 ; V_170 ++ ) {
V_222 -> V_34 [ V_170 ] . V_137 = F_50 ( V_4 -> V_34 [ V_170 ] , 0 ) ;
if ( V_222 -> V_34 [ V_170 ] . V_137 == NULL ) {
V_41 = - V_84 ;
goto V_228;
}
V_222 -> V_34 [ V_170 ] . V_12 = F_120 ( V_4 -> V_34 [ V_170 ] , 0 ) ;
}
if ( V_220 ) {
bool V_229 = F_17 ( V_4 -> type ) ;
for ( V_170 = 0 ; V_170 < V_4 -> V_33 ; V_170 ++ ) {
struct V_82 * V_83 = & V_222 -> V_83 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> type = V_4 -> type ;
if ( V_229 ) {
memset ( & V_222 -> V_26 , 0 , sizeof( V_222 -> V_26 ) ) ;
V_83 -> V_37 . V_17 = & V_222 -> V_26 ;
V_83 -> V_19 = 1 ;
}
V_83 -> V_40 = V_4 -> V_40 ;
V_83 -> V_23 = V_170 ;
V_41 = F_81 ( V_4 , V_83 ) ;
if ( V_41 )
goto V_228;
V_222 -> V_34 [ V_170 ] . V_230 = 1 ;
}
V_222 -> V_231 = V_4 -> V_33 ;
V_222 -> V_232 = V_4 -> V_33 ;
}
V_41 = F_96 ( V_4 , V_4 -> type ) ;
if ( V_41 )
goto V_228;
return V_41 ;
V_228:
V_222 -> V_123 . V_126 = 0 ;
F_39 ( V_4 , & V_222 -> V_123 ) ;
V_227:
V_4 -> V_222 = NULL ;
F_18 ( V_222 ) ;
return V_41 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_221 * V_222 = V_4 -> V_222 ;
if ( V_222 ) {
F_99 ( V_4 , V_4 -> type ) ;
V_4 -> V_222 = NULL ;
V_222 -> V_123 . V_126 = 0 ;
F_46 ( V_4 , & V_222 -> V_123 ) ;
F_18 ( V_222 ) ;
F_8 ( 3 , L_104 ) ;
}
return 0 ;
}
static T_2 F_121 ( struct V_3 * V_4 , char T_3 * V_233 , T_2 V_126 ,
T_4 * V_234 , int V_235 , int V_220 )
{
struct V_221 * V_222 ;
struct V_236 * V_237 ;
bool V_229 = F_17 ( V_4 -> type ) ;
bool V_238 = ! V_220 &&
( V_4 -> V_97 & V_98 ) ==
V_99 ;
int V_41 , V_23 ;
F_8 ( 3 , L_105 ,
V_220 ? L_102 : L_103 , ( long ) * V_234 , V_126 ,
V_235 ? L_106 : L_12 ) ;
if ( ! V_233 )
return - V_84 ;
if ( ! F_38 ( V_4 ) ) {
V_41 = F_112 ( V_4 , V_220 ) ;
F_8 ( 3 , L_107 , V_41 ) ;
if ( V_41 )
return V_41 ;
}
V_222 = V_4 -> V_222 ;
V_23 = V_222 -> V_232 ;
if ( V_23 >= V_4 -> V_33 ) {
memset ( & V_222 -> V_83 , 0 , sizeof( V_222 -> V_83 ) ) ;
V_222 -> V_83 . type = V_4 -> type ;
V_222 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_229 ) {
memset ( & V_222 -> V_26 , 0 , sizeof( V_222 -> V_26 ) ) ;
V_222 -> V_83 . V_37 . V_17 = & V_222 -> V_26 ;
V_222 -> V_83 . V_19 = 1 ;
}
V_41 = F_92 ( V_4 , & V_222 -> V_83 , V_235 ) ;
F_8 ( 5 , L_108 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_222 -> V_239 += 1 ;
V_222 -> V_232 = V_23 = V_222 -> V_83 . V_23 ;
V_237 = & V_222 -> V_34 [ V_23 ] ;
V_237 -> V_240 = 0 ;
V_237 -> V_230 = 0 ;
V_237 -> V_12 = V_220 ? F_122 ( V_4 -> V_34 [ V_23 ] , 0 )
: F_120 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
if ( V_229 && V_220 &&
V_222 -> V_83 . V_37 . V_17 [ 0 ] . V_88 < V_237 -> V_12 ) {
V_237 -> V_240 = V_222 -> V_83 . V_37 . V_17 [ 0 ] . V_88 ;
V_237 -> V_12 -= V_237 -> V_240 ;
}
} else {
V_237 = & V_222 -> V_34 [ V_23 ] ;
}
if ( V_237 -> V_240 + V_126 > V_237 -> V_12 ) {
V_126 = V_237 -> V_12 - V_237 -> V_240 ;
F_8 ( 5 , L_109 , V_126 ) ;
}
F_8 ( 3 , L_110 ,
V_126 , V_23 , V_237 -> V_240 ) ;
if ( V_220 )
V_41 = F_123 ( V_233 , V_237 -> V_137 + V_237 -> V_240 , V_126 ) ;
else
V_41 = F_124 ( V_237 -> V_137 + V_237 -> V_240 , V_233 , V_126 ) ;
if ( V_41 ) {
F_8 ( 3 , L_111 ) ;
return - V_241 ;
}
V_237 -> V_240 += V_126 ;
* V_234 += V_126 ;
if ( V_237 -> V_240 == V_237 -> V_12 || ( ! V_220 && V_222 -> V_226 ) ) {
if ( V_220 && V_222 -> V_225 && V_222 -> V_239 == 1 ) {
F_8 ( 3 , L_112 ) ;
return F_119 ( V_4 ) ;
}
memset ( & V_222 -> V_83 , 0 , sizeof( V_222 -> V_83 ) ) ;
V_222 -> V_83 . type = V_4 -> type ;
V_222 -> V_83 . V_40 = V_4 -> V_40 ;
V_222 -> V_83 . V_23 = V_23 ;
V_222 -> V_83 . V_86 = V_237 -> V_240 ;
if ( V_229 ) {
memset ( & V_222 -> V_26 , 0 , sizeof( V_222 -> V_26 ) ) ;
V_222 -> V_26 . V_86 = V_237 -> V_240 ;
V_222 -> V_83 . V_37 . V_17 = & V_222 -> V_26 ;
V_222 -> V_83 . V_19 = 1 ;
}
if ( V_238 )
F_125 ( & V_222 -> V_83 . V_160 ) ;
V_41 = F_81 ( V_4 , & V_222 -> V_83 ) ;
F_8 ( 5 , L_113 , V_41 ) ;
if ( V_41 )
return V_41 ;
V_237 -> V_240 = 0 ;
V_237 -> V_230 = 1 ;
V_237 -> V_12 = F_120 ( V_4 -> V_34 [ V_23 ] , 0 ) ;
V_222 -> V_242 += 1 ;
if ( V_222 -> V_231 < V_4 -> V_33 )
V_222 -> V_231 ++ ;
V_222 -> V_232 = V_222 -> V_231 ;
}
if ( V_41 == 0 )
V_41 = V_126 ;
return V_41 ;
}
T_2 F_126 ( struct V_3 * V_4 , char T_3 * V_233 , T_2 V_126 ,
T_4 * V_234 , int V_174 )
{
return F_121 ( V_4 , V_233 , V_126 , V_234 , V_174 , 1 ) ;
}
T_2 F_127 ( struct V_3 * V_4 , const char T_3 * V_233 , T_2 V_126 ,
T_4 * V_234 , int V_174 )
{
return F_121 ( V_4 , ( char T_3 * ) V_233 , V_126 ,
V_234 , V_174 , 0 ) ;
}
static int F_128 ( void * V_233 )
{
struct V_3 * V_4 = V_233 ;
struct V_243 * V_244 = V_4 -> V_244 ;
struct V_221 * V_222 = V_4 -> V_222 ;
bool V_238 = false ;
int V_245 = 0 ;
int V_23 = 0 ;
int V_41 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
V_245 = V_4 -> V_33 ;
V_238 =
( V_4 -> V_97 & V_98 ) ==
V_99 ;
}
F_129 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_222 -> V_83 , 0 , sizeof( V_222 -> V_83 ) ) ;
V_222 -> V_83 . type = V_4 -> type ;
V_222 -> V_83 . V_40 = V_4 -> V_40 ;
if ( V_245 ) {
V_222 -> V_83 . V_23 = V_23 ++ ;
V_245 -- ;
} else {
F_84 ( V_4 , V_176 , V_4 ) ;
if ( ! V_244 -> V_246 )
V_41 = F_92 ( V_4 , & V_222 -> V_83 , 0 ) ;
F_84 ( V_4 , V_175 , V_4 ) ;
F_8 ( 5 , L_114 , V_41 ) ;
}
if ( V_41 || V_244 -> V_246 )
break;
F_130 () ;
V_2 = V_4 -> V_34 [ V_222 -> V_83 . V_23 ] ;
if ( ! ( V_222 -> V_83 . V_95 & V_105 ) )
if ( V_244 -> V_247 ( V_2 , V_244 -> V_248 ) )
break;
F_84 ( V_4 , V_176 , V_4 ) ;
if ( V_238 )
F_125 ( & V_222 -> V_83 . V_160 ) ;
if ( ! V_244 -> V_246 )
V_41 = F_81 ( V_4 , & V_222 -> V_83 ) ;
F_84 ( V_4 , V_175 , V_4 ) ;
if ( V_41 || V_244 -> V_246 )
break;
}
while ( ! F_131 () ) {
F_132 ( V_249 ) ;
F_133 () ;
}
return 0 ;
}
int F_134 ( struct V_3 * V_4 , T_5 V_247 , void * V_248 ,
const char * V_250 )
{
struct V_243 * V_244 ;
int V_41 = 0 ;
if ( V_4 -> V_244 )
return - V_121 ;
if ( F_135 ( V_4 ) )
return - V_121 ;
if ( F_53 ( V_4 -> V_222 ) )
return - V_121 ;
V_244 = F_16 ( sizeof( * V_244 ) , V_43 ) ;
if ( V_244 == NULL )
return - V_21 ;
V_244 -> V_247 = V_247 ;
V_244 -> V_248 = V_248 ;
V_41 = F_112 ( V_4 , ! F_2 ( V_4 -> type ) ) ;
F_8 ( 3 , L_115 , V_41 ) ;
if ( V_41 )
goto V_251;
V_4 -> V_244 = V_244 ;
V_244 -> V_252 = F_136 ( F_128 , V_4 , L_116 , V_250 ) ;
if ( F_69 ( V_244 -> V_252 ) ) {
V_41 = F_66 ( V_244 -> V_252 ) ;
V_244 -> V_252 = NULL ;
goto V_253;
}
return 0 ;
V_253:
F_119 ( V_4 ) ;
V_251:
F_18 ( V_244 ) ;
return V_41 ;
}
int F_137 ( struct V_3 * V_4 )
{
struct V_243 * V_244 = V_4 -> V_244 ;
int V_154 ;
if ( V_244 == NULL )
return 0 ;
V_244 -> V_246 = true ;
F_97 ( V_4 ) ;
V_154 = F_138 ( V_244 -> V_252 ) ;
F_119 ( V_4 ) ;
V_244 -> V_252 = NULL ;
F_18 ( V_244 ) ;
V_4 -> V_244 = NULL ;
return V_154 ;
}
static inline bool F_139 ( struct V_202 * V_254 , struct V_200 * V_200 )
{
return V_254 -> V_255 -> V_256 && V_254 -> V_255 -> V_256 != V_200 -> V_209 ;
}
int F_140 ( struct V_200 * V_200 , void * V_248 ,
struct V_122 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
int V_205 = F_37 ( V_254 -> V_255 , V_26 -> V_40 , V_26 -> type ) ;
if ( V_205 )
return V_205 ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
V_205 = F_39 ( V_254 -> V_255 , V_26 ) ;
if ( V_205 == 0 )
V_254 -> V_255 -> V_256 = V_26 -> V_126 ? V_200 -> V_209 : NULL ;
return V_205 ;
}
int F_141 ( struct V_200 * V_200 , void * V_248 ,
struct V_131 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
int V_205 = F_37 ( V_254 -> V_255 , V_26 -> V_40 , V_26 -> V_135 . type ) ;
V_26 -> V_23 = V_254 -> V_255 -> V_33 ;
if ( V_26 -> V_126 == 0 )
return V_205 != - V_121 ? V_205 : 0 ;
if ( V_205 )
return V_205 ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
V_205 = F_47 ( V_254 -> V_255 , V_26 ) ;
if ( V_205 == 0 )
V_254 -> V_255 -> V_256 = V_200 -> V_209 ;
return V_205 ;
}
int F_142 ( struct V_200 * V_200 , void * V_248 ,
struct V_82 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_77 ( V_254 -> V_255 , V_26 ) ;
}
int F_143 ( struct V_200 * V_200 , void * V_248 , struct V_82 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
return F_33 ( V_254 -> V_255 , V_26 ) ;
}
int F_144 ( struct V_200 * V_200 , void * V_248 , struct V_82 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_82 ( V_254 -> V_255 , V_26 ) ;
}
int F_145 ( struct V_200 * V_200 , void * V_248 , struct V_82 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_93 ( V_254 -> V_255 , V_26 , V_200 -> V_257 & V_258 ) ;
}
int F_146 ( struct V_200 * V_200 , void * V_248 , enum V_120 V_170 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_98 ( V_254 -> V_255 , V_170 ) ;
}
int F_147 ( struct V_200 * V_200 , void * V_248 , enum V_120 V_170 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_100 ( V_254 -> V_255 , V_170 ) ;
}
int F_148 ( struct V_200 * V_200 , void * V_248 , struct V_181 * V_26 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( F_139 ( V_254 , V_200 ) )
return - V_121 ;
return F_102 ( V_254 -> V_255 , V_26 ) ;
}
int F_149 ( struct V_200 * V_200 , struct V_187 * V_188 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
return F_104 ( V_254 -> V_255 , V_188 ) ;
}
int F_150 ( struct V_200 * V_200 , struct V_259 * V_260 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
if ( V_260 )
F_40 ( V_260 ) ;
if ( V_200 -> V_209 == V_254 -> V_255 -> V_256 ) {
F_118 ( V_254 -> V_255 ) ;
V_254 -> V_255 -> V_256 = NULL ;
}
if ( V_260 )
F_41 ( V_260 ) ;
return F_151 ( V_200 ) ;
}
int F_152 ( struct V_200 * V_200 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
struct V_259 * V_260 = V_254 -> V_255 -> V_260 ? V_254 -> V_255 -> V_260 : V_254 -> V_260 ;
return F_150 ( V_200 , V_260 ) ;
}
T_6 F_153 ( struct V_200 * V_200 , const char T_3 * V_237 ,
T_2 V_126 , T_4 * V_234 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
struct V_259 * V_260 = V_254 -> V_255 -> V_260 ? V_254 -> V_255 -> V_260 : V_254 -> V_260 ;
int V_154 = - V_121 ;
if ( ! ( V_254 -> V_255 -> V_111 & V_217 ) )
return - V_84 ;
if ( V_260 && F_154 ( V_260 ) )
return - V_261 ;
if ( F_139 ( V_254 , V_200 ) )
goto exit;
V_154 = F_127 ( V_254 -> V_255 , V_237 , V_126 , V_234 ,
V_200 -> V_257 & V_258 ) ;
if ( V_254 -> V_255 -> V_222 )
V_254 -> V_255 -> V_256 = V_200 -> V_209 ;
exit:
if ( V_260 )
F_41 ( V_260 ) ;
return V_154 ;
}
T_6 F_155 ( struct V_200 * V_200 , char T_3 * V_237 ,
T_2 V_126 , T_4 * V_234 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
struct V_259 * V_260 = V_254 -> V_255 -> V_260 ? V_254 -> V_255 -> V_260 : V_254 -> V_260 ;
int V_154 = - V_121 ;
if ( ! ( V_254 -> V_255 -> V_111 & V_215 ) )
return - V_84 ;
if ( V_260 && F_154 ( V_260 ) )
return - V_261 ;
if ( F_139 ( V_254 , V_200 ) )
goto exit;
V_154 = F_126 ( V_254 -> V_255 , V_237 , V_126 , V_234 ,
V_200 -> V_257 & V_258 ) ;
if ( V_254 -> V_255 -> V_222 )
V_254 -> V_255 -> V_256 = V_200 -> V_209 ;
exit:
if ( V_260 )
F_41 ( V_260 ) ;
return V_154 ;
}
unsigned int F_156 ( struct V_200 * V_200 , T_1 * V_201 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
struct V_3 * V_4 = V_254 -> V_255 ;
struct V_259 * V_260 = V_4 -> V_260 ? V_4 -> V_260 : V_254 -> V_260 ;
unsigned V_205 ;
void * V_222 ;
F_53 ( ! V_260 ) ;
if ( V_260 && F_154 ( V_260 ) )
return V_216 ;
V_222 = V_4 -> V_222 ;
V_205 = F_106 ( V_254 -> V_255 , V_200 , V_201 ) ;
if ( ! V_222 && V_4 -> V_222 )
V_4 -> V_256 = V_200 -> V_209 ;
if ( V_260 )
F_41 ( V_260 ) ;
return V_205 ;
}
unsigned long F_157 ( struct V_200 * V_200 , unsigned long V_197 ,
unsigned long V_198 , unsigned long V_199 , unsigned long V_95 )
{
struct V_202 * V_254 = F_107 ( V_200 ) ;
return F_105 ( V_254 -> V_255 , V_197 , V_198 , V_199 , V_95 ) ;
}
void F_158 ( struct V_3 * V_262 )
{
F_41 ( V_262 -> V_260 ) ;
}
void F_159 ( struct V_3 * V_262 )
{
F_40 ( V_262 -> V_260 ) ;
}
