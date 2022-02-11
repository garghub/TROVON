static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
unsigned long V_8 = F_2 ( V_4 -> V_9 [ V_6 ] ) ;
V_5 = F_3 ( V_2 , V_10 , V_4 -> V_11 [ V_6 ] ,
V_8 , V_4 -> V_12 ) ;
if ( F_4 ( V_5 ) )
goto free;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
V_2 -> V_14 [ V_6 ] . V_15 = V_4 -> V_9 [ V_6 ] ;
}
return 0 ;
free:
for (; V_6 > 0 ; -- V_6 ) {
F_5 ( V_2 , V_16 , V_2 -> V_13 [ V_6 - 1 ] . V_5 ) ;
V_2 -> V_13 [ V_6 - 1 ] . V_5 = NULL ;
}
return - V_17 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
F_5 ( V_2 , V_16 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
F_7 ( 3 , L_1 , V_6 ,
V_2 -> V_18 . V_19 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_5 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( ! V_22 -> V_5 )
return;
if ( V_22 -> V_23 )
F_5 ( V_2 , V_24 , V_22 -> V_5 ) ;
F_5 ( V_2 , V_25 , V_22 -> V_5 ) ;
F_10 ( V_22 -> V_26 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_9 ( V_2 , & V_2 -> V_13 [ V_6 ] ) ;
}
static void F_12 ( struct V_3 * V_4 , unsigned int V_27 )
{
unsigned int V_28 , V_6 ;
struct V_1 * V_2 ;
for ( V_28 = V_4 -> V_29 ; V_28 < V_4 -> V_29 + V_27 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] . V_15 = V_4 -> V_9 [ V_6 ] ;
}
}
static void F_13 ( struct V_3 * V_4 , unsigned int V_27 )
{
unsigned int V_28 , V_6 ;
struct V_1 * V_2 ;
unsigned long V_31 ;
if ( V_4 -> V_29 ) {
struct V_32 * V_22 ;
V_2 = V_4 -> V_30 [ V_4 -> V_29 - 1 ] ;
V_22 = & V_2 -> V_14 [ V_2 -> V_7 - 1 ] ;
V_31 = F_2 ( V_22 -> V_33 . V_34 + V_22 -> V_15 ) ;
} else {
V_31 = 0 ;
}
for ( V_28 = V_4 -> V_29 ; V_28 < V_4 -> V_29 + V_27 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_2 -> V_14 [ V_6 ] . V_33 . V_34 = V_31 ;
F_7 ( 3 , L_2 ,
V_28 , V_6 , V_31 ) ;
V_31 += V_2 -> V_14 [ V_6 ] . V_15 ;
V_31 = F_2 ( V_31 ) ;
}
}
}
static int F_14 ( struct V_3 * V_4 , enum V_35 V_36 ,
unsigned int V_29 , unsigned int V_7 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
int V_37 ;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 ) {
V_2 = F_15 ( V_4 -> V_38 , V_39 ) ;
if ( ! V_2 ) {
F_7 ( 1 , L_3 ) ;
break;
}
if ( F_16 ( V_4 -> type ) )
V_2 -> V_18 . V_15 = V_7 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_18 . V_19 = V_4 -> V_29 + V_28 ;
V_2 -> V_18 . type = V_4 -> type ;
V_2 -> V_18 . V_36 = V_36 ;
if ( V_36 == V_42 ) {
V_37 = F_1 ( V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_4
L_5 , V_28 ) ;
F_17 ( V_2 ) ;
break;
}
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_6
L_7 , V_28 , V_2 ) ;
F_6 ( V_2 ) ;
F_17 ( V_2 ) ;
break;
}
}
V_4 -> V_30 [ V_4 -> V_29 + V_28 ] = V_2 ;
}
F_12 ( V_4 , V_28 ) ;
if ( V_36 == V_42 )
F_13 ( V_4 , V_28 ) ;
F_7 ( 1 , L_8 ,
V_28 , V_7 ) ;
return V_28 ;
}
static void F_19 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_36 == V_42 )
F_6 ( V_2 ) ;
else if ( V_4 -> V_36 == V_45 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
}
static int F_20 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
if ( V_4 -> V_30 [ V_28 ] == NULL )
continue;
if ( V_4 -> V_30 [ V_28 ] -> V_40 == V_46 ) {
F_7 ( 1 , L_9 ) ;
return - V_47 ;
}
}
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_28 ] ;
if ( V_2 && V_2 -> V_13 [ 0 ] . V_5 )
F_21 ( V_2 , V_48 , V_2 ) ;
}
F_19 ( V_4 , V_44 ) ;
#ifdef F_22
if ( V_4 -> V_29 ) {
bool V_49 = V_4 -> V_50 != V_4 -> V_51 ||
V_4 -> V_52 != V_4 -> V_53 ;
if ( V_49 || V_54 ) {
F_23 ( L_10 , V_4 ,
V_49 ? L_11 : L_12 ) ;
F_23 ( L_13 ,
V_4 -> V_55 , V_4 -> V_50 ,
V_4 -> V_51 ) ;
F_23 ( L_14 ,
V_4 -> V_52 , V_4 -> V_53 ) ;
}
V_4 -> V_55 = 0 ;
V_4 -> V_52 = 0 ;
V_4 -> V_53 = 0 ;
V_4 -> V_50 = 0 ;
V_4 -> V_51 = 0 ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_28 ] ;
bool V_49 = V_2 -> V_56 != V_2 -> V_57 ||
V_2 -> V_58 != V_2 -> V_59 ||
V_2 -> V_60 != V_2 -> V_61 ||
V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ;
if ( V_49 || V_54 ) {
F_23 ( L_15 ,
V_4 , V_28 , V_49 ? L_11 : L_12 ) ;
F_23 ( L_16 ,
V_2 -> V_70 , V_2 -> V_71 ,
V_2 -> V_68 , V_2 -> V_69 ) ;
F_23 ( L_17 ,
V_2 -> V_66 , V_2 -> V_67 ) ;
F_23 ( L_18 ,
V_2 -> V_56 , V_2 -> V_57 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_72 ) ;
F_23 ( L_19 ,
V_2 -> V_60 , V_2 -> V_61 ) ;
F_23 ( L_20 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_64 , V_2 -> V_65 ) ;
F_23 ( L_21 ,
V_2 -> V_73 ,
V_2 -> V_74 ,
V_2 -> V_75 ,
V_2 -> V_76 ) ;
}
}
#endif
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
F_17 ( V_4 -> V_30 [ V_28 ] ) ;
V_4 -> V_30 [ V_28 ] = NULL ;
}
V_4 -> V_29 -= V_44 ;
if ( ! V_4 -> V_29 ) {
V_4 -> V_36 = 0 ;
F_24 ( & V_4 -> V_77 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
if ( ! F_16 ( V_79 -> type ) )
return 0 ;
if ( NULL == V_79 -> V_33 . V_13 ) {
F_7 ( 1 , L_22
L_23 ) ;
return - V_80 ;
}
if ( V_79 -> V_15 < V_2 -> V_7 || V_79 -> V_15 > V_81 ) {
F_7 ( 1 , L_24
L_25 , V_2 -> V_7 , V_79 -> V_15 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
unsigned int V_15 ;
unsigned int V_6 ;
if ( ! F_27 ( V_79 -> type ) )
return 0 ;
if ( F_16 ( V_79 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_15 = ( V_79 -> V_36 == V_82 )
? V_79 -> V_33 . V_13 [ V_6 ] . V_15
: V_2 -> V_14 [ V_6 ] . V_15 ;
if ( V_79 -> V_33 . V_13 [ V_6 ] . V_83 > V_15 )
return - V_80 ;
if ( V_79 -> V_33 . V_13 [ V_6 ] . V_84 > 0 &&
V_79 -> V_33 . V_13 [ V_6 ] . V_84 >=
V_79 -> V_33 . V_13 [ V_6 ] . V_83 )
return - V_80 ;
}
} else {
V_15 = ( V_79 -> V_36 == V_82 )
? V_79 -> V_15 : V_2 -> V_14 [ 0 ] . V_15 ;
if ( V_79 -> V_83 > V_15 )
return - V_80 ;
}
return 0 ;
}
static bool F_28 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_13 [ V_6 ] . V_5 ;
if ( V_5 && F_29 ( V_2 , V_85 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_30 ( struct V_3 * V_4 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
if ( F_28 ( V_4 , V_4 -> V_30 [ V_28 ] ) )
return true ;
}
return false ;
}
static void F_31 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_79 , & V_2 -> V_18 , F_32 ( struct V_78 , V_33 ) ) ;
V_79 -> V_86 = V_2 -> V_18 . V_86 ;
V_79 -> V_87 = V_2 -> V_18 . V_87 ;
if ( F_16 ( V_4 -> type ) ) {
V_79 -> V_15 = V_2 -> V_7 ;
memcpy ( V_79 -> V_33 . V_13 , V_2 -> V_14 ,
V_79 -> V_15 * sizeof( struct V_32 ) ) ;
} else {
V_79 -> V_15 = V_2 -> V_14 [ 0 ] . V_15 ;
V_79 -> V_83 = V_2 -> V_14 [ 0 ] . V_83 ;
if ( V_4 -> V_36 == V_42 )
V_79 -> V_33 . V_88 = V_2 -> V_14 [ 0 ] . V_33 . V_34 ;
else if ( V_4 -> V_36 == V_82 )
V_79 -> V_33 . V_89 = V_2 -> V_14 [ 0 ] . V_33 . V_89 ;
else if ( V_4 -> V_36 == V_45 )
V_79 -> V_33 . V_90 = V_2 -> V_14 [ 0 ] . V_33 . V_90 ;
}
V_79 -> V_91 &= ~ V_92 ;
V_79 -> V_91 |= V_4 -> V_93 & V_94 ;
if ( ( V_4 -> V_93 & V_94 ) !=
V_95 ) {
V_79 -> V_91 &= ~ V_96 ;
V_79 -> V_91 |= V_4 -> V_93 & V_96 ;
}
switch ( V_2 -> V_40 ) {
case V_97 :
case V_98 :
V_79 -> V_91 |= V_99 ;
break;
case V_100 :
V_79 -> V_91 |= V_101 ;
case V_102 :
V_79 -> V_91 |= V_103 ;
break;
case V_104 :
V_79 -> V_91 |= V_105 ;
break;
case V_46 :
case V_41 :
break;
}
if ( F_28 ( V_4 , V_2 ) )
V_79 -> V_91 |= V_106 ;
}
int F_33 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_26 ) ;
return - V_80 ;
}
if ( V_79 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_27 ) ;
return - V_80 ;
}
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
V_37 = F_25 ( V_2 , V_79 ) ;
if ( ! V_37 )
F_31 ( V_2 , V_79 ) ;
return V_37 ;
}
static int F_34 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_108 ) || ! V_4 -> V_109 -> V_110 ||
! V_4 -> V_109 -> V_20 )
return - V_80 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_111 ) || ! V_4 -> V_109 -> V_10 ||
! V_4 -> V_109 -> V_16 || ! V_4 -> V_109 -> V_112 )
return - V_80 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_113 ) || ! V_4 -> V_109 -> V_114 ||
! V_4 -> V_109 -> V_25 || ! V_4 -> V_109 -> V_115 ||
! V_4 -> V_109 -> V_24 )
return - V_80 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
enum V_35 V_36 , enum V_116 type )
{
if ( V_36 != V_42 && V_36 != V_82 &&
V_36 != V_45 ) {
F_7 ( 1 , L_28 ) ;
return - V_80 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_29 ) ;
return - V_80 ;
}
if ( V_36 == V_42 && F_35 ( V_4 ) ) {
F_7 ( 1 , L_30 ) ;
return - V_80 ;
}
if ( V_36 == V_82 && F_34 ( V_4 ) ) {
F_7 ( 1 , L_31 ) ;
return - V_80 ;
}
if ( V_36 == V_45 && F_36 ( V_4 ) ) {
F_7 ( 1 , L_32 ) ;
return - V_80 ;
}
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_118 * V_119 )
{
unsigned int V_29 , V_120 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_121 ) {
F_7 ( 1 , L_34 ) ;
return - V_117 ;
}
if ( V_119 -> V_122 == 0 || V_4 -> V_29 != 0 || V_4 -> V_36 != V_119 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_30 ( V_4 ) ) {
F_7 ( 1 , L_35 ) ;
return - V_117 ;
}
F_40 ( V_4 ) ;
V_37 = F_20 ( V_4 , V_4 -> V_29 ) ;
if ( V_37 )
return V_37 ;
if ( V_119 -> V_122 == 0 )
return 0 ;
}
V_29 = F_41 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
V_29 = F_42 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_119 -> V_36 ;
V_37 = F_43 ( V_4 , V_123 , V_4 , NULL , & V_29 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_120 = F_14 ( V_4 , V_119 -> V_36 , V_29 , V_7 ) ;
if ( V_120 == 0 ) {
F_7 ( 1 , L_36 ) ;
return - V_17 ;
}
if ( V_120 < V_4 -> V_124 )
V_37 = - V_17 ;
if ( ! V_37 && V_120 < V_29 ) {
V_29 = V_120 ;
V_37 = F_43 ( V_4 , V_123 , V_4 , NULL , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_120 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 = V_120 ;
if ( V_37 < 0 ) {
F_20 ( V_4 , V_120 ) ;
return V_37 ;
}
V_119 -> V_122 = V_120 ;
return 0 ;
}
int F_44 ( struct V_3 * V_4 , struct V_118 * V_119 )
{
int V_37 = F_37 ( V_4 , V_119 -> V_36 , V_119 -> type ) ;
return V_37 ? V_37 : F_39 ( V_4 , V_119 ) ;
}
static int F_45 ( struct V_3 * V_4 , struct V_125 * V_126 )
{
unsigned int V_7 = 0 , V_29 , V_120 ;
int V_37 ;
if ( V_4 -> V_29 == V_127 ) {
F_7 ( 1 , L_37 ) ;
return - V_128 ;
}
if ( ! V_4 -> V_29 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_126 -> V_36 ;
}
V_29 = F_46 ( V_126 -> V_122 , V_127 - V_4 -> V_29 ) ;
V_37 = F_43 ( V_4 , V_123 , V_4 , & V_126 -> V_129 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_120 = F_14 ( V_4 , V_126 -> V_36 , V_29 ,
V_7 ) ;
if ( V_120 == 0 ) {
F_7 ( 1 , L_36 ) ;
return - V_17 ;
}
if ( V_120 < V_29 ) {
V_29 = V_120 ;
V_37 = F_43 ( V_4 , V_123 , V_4 , & V_126 -> V_129 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_120 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 += V_120 ;
if ( V_37 < 0 ) {
F_20 ( V_4 , V_120 ) ;
return - V_17 ;
}
V_126 -> V_122 = V_120 ;
return 0 ;
}
int F_47 ( struct V_3 * V_4 , struct V_125 * V_126 )
{
int V_37 = F_37 ( V_4 , V_126 -> V_36 , V_126 -> V_129 . type ) ;
V_126 -> V_19 = V_4 -> V_29 ;
if ( V_126 -> V_122 == 0 )
return V_37 != - V_117 ? V_37 : 0 ;
return V_37 ? V_37 : F_45 ( V_4 , V_126 ) ;
}
void * F_48 ( struct V_1 * V_2 , unsigned int V_130 )
{
if ( V_130 > V_2 -> V_7 || ! V_2 -> V_13 [ V_130 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_131 , V_2 -> V_13 [ V_130 ] . V_5 ) ;
}
void * F_49 ( struct V_1 * V_2 , unsigned int V_130 )
{
if ( V_130 > V_2 -> V_7 || ! V_2 -> V_13 [ V_130 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_132 , V_2 -> V_13 [ V_130 ] . V_5 ) ;
}
void F_50 ( struct V_1 * V_2 , enum V_133 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_91 ;
unsigned int V_6 ;
if ( F_51 ( V_2 -> V_40 != V_98 ) )
return;
if ( ! V_4 -> V_134 ) {
if ( F_51 ( V_40 != V_97 ) )
V_40 = V_97 ;
} else if ( F_51 ( V_40 != V_102 &&
V_40 != V_100 ) ) {
V_40 = V_100 ;
}
#ifdef F_22
V_2 -> V_67 ++ ;
#endif
F_7 ( 4 , L_38 ,
V_2 -> V_18 . V_19 , V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_5 ( V_2 , V_135 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_52 ( & V_4 -> V_136 , V_91 ) ;
V_2 -> V_40 = V_40 ;
if ( V_40 != V_97 )
F_53 ( & V_2 -> V_137 , & V_4 -> V_138 ) ;
F_54 ( & V_4 -> V_139 ) ;
F_55 ( & V_4 -> V_136 , V_91 ) ;
if ( V_40 == V_97 )
return;
F_56 ( & V_4 -> V_140 ) ;
}
void F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_91 ;
F_52 ( & V_4 -> V_136 , V_91 ) ;
F_58 (vb, &q->done_list, done_entry)
V_2 -> V_40 = V_100 ;
F_55 ( & V_4 -> V_136 , V_91 ) ;
}
static void F_59 ( struct V_1 * V_2 , const struct V_78 * V_79 ,
struct V_32 * V_14 )
{
unsigned int V_6 ;
if ( F_16 ( V_79 -> type ) ) {
if ( F_27 ( V_79 -> type ) ) {
bool V_141 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
if ( V_79 -> V_33 . V_13 [ V_6 ] . V_83 )
break;
V_141 = V_6 < V_2 -> V_7 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_32 * V_142 = & V_14 [ V_6 ] ;
struct V_32 * V_143 = & V_79 -> V_33 . V_13 [ V_6 ] ;
V_142 -> V_83 = V_141 ?
V_143 -> V_83 : V_143 -> V_15 ;
V_142 -> V_84 = V_143 -> V_84 ;
}
}
if ( V_79 -> V_36 == V_82 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_89 =
V_79 -> V_33 . V_13 [ V_6 ] . V_33 . V_89 ;
V_14 [ V_6 ] . V_15 =
V_79 -> V_33 . V_13 [ V_6 ] . V_15 ;
}
}
if ( V_79 -> V_36 == V_45 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_90 =
V_79 -> V_33 . V_13 [ V_6 ] . V_33 . V_90 ;
V_14 [ V_6 ] . V_15 =
V_79 -> V_33 . V_13 [ V_6 ] . V_15 ;
}
}
} else {
if ( F_27 ( V_79 -> type ) )
V_14 [ 0 ] . V_83 =
V_79 -> V_83 ? V_79 -> V_83 : V_79 -> V_15 ;
else
V_14 [ 0 ] . V_83 = 0 ;
if ( V_79 -> V_36 == V_82 ) {
V_14 [ 0 ] . V_33 . V_89 = V_79 -> V_33 . V_89 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
}
if ( V_79 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_90 = V_79 -> V_33 . V_90 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
}
}
V_2 -> V_18 . V_91 = V_79 -> V_91 & ~ V_92 ;
if ( ( V_2 -> V_3 -> V_93 & V_94 ) !=
V_95 || ! F_27 ( V_79 -> type ) ) {
V_2 -> V_18 . V_91 &= ~ V_96 ;
}
if ( F_27 ( V_79 -> type ) ) {
V_2 -> V_18 . V_91 &= ~ V_144 ;
V_2 -> V_18 . V_145 = V_79 -> V_145 ;
} else {
V_2 -> V_18 . V_91 &= ~ V_146 ;
}
}
static int F_60 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
F_59 ( V_2 , V_79 , V_2 -> V_14 ) ;
return F_18 ( V_2 , V_147 , V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_32 V_13 [ V_81 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_148 = ! F_27 ( V_4 -> type ) ;
bool V_149 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
memset ( V_13 , 0 , sizeof( V_13 [ 0 ] ) * V_2 -> V_7 ) ;
F_59 ( V_2 , V_79 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_89 &&
V_2 -> V_14 [ V_6 ] . V_33 . V_89 == V_13 [ V_6 ] . V_33 . V_89
&& V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 )
continue;
F_7 ( 3 , L_39
L_40 , V_6 ) ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
F_7 ( 1 , L_41
L_42 ,
V_13 [ V_6 ] . V_15 ,
V_4 -> V_9 [ V_6 ] , V_6 ) ;
V_37 = - V_80 ;
goto V_150;
}
if ( V_2 -> V_13 [ V_6 ] . V_5 ) {
if ( ! V_149 ) {
V_149 = true ;
F_21 ( V_2 , V_48 , V_2 ) ;
}
F_5 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
}
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_110 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_89 ,
V_13 [ V_6 ] . V_15 , V_148 ) ;
if ( F_4 ( V_5 ) ) {
F_7 ( 1 , L_43
L_44 , V_6 ) ;
V_37 = V_5 ? F_62 ( V_5 ) : - V_80 ;
goto V_150;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_149 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
goto V_150;
}
}
V_37 = F_18 ( V_2 , V_147 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_21 ( V_2 , V_48 , V_2 ) ;
goto V_150;
}
return 0 ;
V_150:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_5 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_89 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
}
return V_37 ;
}
static int F_63 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_32 V_13 [ V_81 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_148 = ! F_27 ( V_4 -> type ) ;
bool V_149 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
memset ( V_13 , 0 , sizeof( V_13 [ 0 ] ) * V_2 -> V_7 ) ;
F_59 ( V_2 , V_79 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_151 * V_26 = F_64 ( V_13 [ V_6 ] . V_33 . V_90 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_47 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_150;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
F_7 ( 1 , L_48 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_150;
}
if ( V_26 == V_2 -> V_13 [ V_6 ] . V_26 &&
V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 ) {
F_10 ( V_26 ) ;
continue;
}
F_7 ( 1 , L_49 , V_6 ) ;
if ( ! V_149 ) {
V_149 = true ;
F_21 ( V_2 , V_48 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_114 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_148 ) ;
if ( F_65 ( V_5 ) ) {
F_7 ( 1 , L_50 ) ;
V_37 = F_62 ( V_5 ) ;
F_10 ( V_26 ) ;
goto V_150;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_29 ( V_2 , V_115 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_7 ( 1 , L_51 ,
V_6 ) ;
goto V_150;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_149 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
goto V_150;
}
}
V_37 = F_18 ( V_2 , V_147 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_21 ( V_2 , V_48 , V_2 ) ;
goto V_150;
}
return 0 ;
V_150:
F_11 ( V_2 ) ;
return V_37 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_98 ;
F_67 ( & V_4 -> V_139 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_5 ( V_2 , V_152 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_21 ( V_2 , V_153 , V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_154 * V_155 ;
int V_37 ;
V_37 = F_26 ( V_2 , V_79 ) ;
if ( V_37 < 0 ) {
F_7 ( 1 , L_52 , V_37 ) ;
return V_37 ;
}
if ( V_79 -> V_145 == V_156 && F_27 ( V_4 -> type ) ) {
F_7 ( 1 , L_53 ) ;
return - V_80 ;
}
V_2 -> V_40 = V_46 ;
V_2 -> V_18 . V_157 . V_158 = 0 ;
V_2 -> V_18 . V_157 . V_159 = 0 ;
V_2 -> V_18 . V_160 = 0 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_60 ( V_2 , V_79 ) ;
break;
case V_82 :
V_155 = & V_161 -> V_162 -> V_155 ;
F_69 ( V_4 , V_163 , V_4 ) ;
F_70 ( V_155 ) ;
F_69 ( V_4 , V_164 , V_4 ) ;
V_37 = F_61 ( V_2 , V_79 ) ;
F_71 ( V_155 ) ;
break;
case V_45 :
V_37 = F_63 ( V_2 , V_79 ) ;
break;
default:
F_72 ( 1 , L_54 ) ;
V_37 = - V_80 ;
}
if ( V_37 )
F_7 ( 1 , L_55 , V_37 ) ;
V_2 -> V_40 = V_37 ? V_41 : V_104 ;
return V_37 ;
}
static int F_73 ( struct V_3 * V_4 , struct V_78 * V_79 ,
const char * V_165 )
{
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_56 , V_165 ) ;
return - V_80 ;
}
if ( V_79 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_57 , V_165 ) ;
return - V_80 ;
}
if ( V_4 -> V_30 [ V_79 -> V_19 ] == NULL ) {
F_7 ( 1 , L_58 , V_165 ) ;
return - V_80 ;
}
if ( V_79 -> V_36 != V_4 -> V_36 ) {
F_7 ( 1 , L_59 , V_165 ) ;
return - V_80 ;
}
return F_25 ( V_4 -> V_30 [ V_79 -> V_19 ] , V_79 ) ;
}
int F_74 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
V_37 = F_73 ( V_4 , V_79 , L_60 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
if ( V_2 -> V_40 != V_41 ) {
F_7 ( 1 , L_61 ,
V_2 -> V_40 ) ;
return - V_80 ;
}
V_37 = F_68 ( V_2 , V_79 ) ;
if ( ! V_37 ) {
F_31 ( V_2 , V_79 ) ;
F_7 ( 1 , L_62 , V_2 -> V_18 . V_19 ) ;
}
return V_37 ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_37 ;
F_58 (vb, &q->queued_list, queued_entry)
F_66 ( V_2 ) ;
V_37 = F_43 ( V_4 , V_166 , V_4 ,
F_76 ( & V_4 -> V_139 ) ) ;
V_4 -> V_134 = V_37 == 0 ;
if ( ! V_37 )
return 0 ;
F_7 ( 1 , L_63 ) ;
if ( F_51 ( F_76 ( & V_4 -> V_139 ) ) ) {
unsigned V_167 ;
for ( V_167 = 0 ; V_167 < V_4 -> V_29 ; ++ V_167 ) {
V_2 = V_4 -> V_30 [ V_167 ] ;
if ( V_2 -> V_40 == V_98 )
F_50 ( V_2 , V_97 ) ;
}
F_51 ( F_76 ( & V_4 -> V_139 ) ) ;
}
return V_37 ;
}
static int F_77 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_37 = F_73 ( V_4 , V_79 , L_64 ) ;
struct V_1 * V_2 ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_68 ( V_2 , V_79 ) ;
if ( V_37 )
return V_37 ;
break;
case V_104 :
break;
case V_46 :
F_7 ( 1 , L_65 ) ;
return - V_80 ;
default:
F_7 ( 1 , L_61 , V_2 -> V_40 ) ;
return - V_80 ;
}
F_53 ( & V_2 -> V_168 , & V_4 -> V_77 ) ;
V_4 -> V_169 ++ ;
V_2 -> V_40 = V_97 ;
if ( F_27 ( V_4 -> type ) ) {
if ( ( V_4 -> V_93 & V_94 ) ==
V_95 )
V_2 -> V_18 . V_157 = V_79 -> V_157 ;
V_2 -> V_18 . V_91 |= V_79 -> V_91 & V_144 ;
if ( V_79 -> V_91 & V_144 )
V_2 -> V_18 . V_170 = V_79 -> V_170 ;
}
if ( V_4 -> V_134 )
F_66 ( V_2 ) ;
F_31 ( V_2 , V_79 ) ;
if ( V_4 -> V_121 && ! V_4 -> V_134 &&
V_4 -> V_169 >= V_4 -> V_124 ) {
V_37 = F_75 ( V_4 ) ;
if ( V_37 )
return V_37 ;
}
F_7 ( 1 , L_66 , V_2 -> V_18 . V_19 ) ;
return 0 ;
}
int F_78 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_77 ( V_4 , V_79 ) ;
}
static int F_79 ( struct V_3 * V_4 , int V_171 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_121 ) {
F_7 ( 1 , L_67 ) ;
return - V_80 ;
}
if ( ! F_80 ( & V_4 -> V_138 ) ) {
break;
}
if ( V_171 ) {
F_7 ( 1 , L_68
L_69 ) ;
return - V_47 ;
}
F_69 ( V_4 , V_163 , V_4 ) ;
F_7 ( 3 , L_70 ) ;
V_37 = F_81 ( V_4 -> V_140 ,
! F_80 ( & V_4 -> V_138 ) || ! V_4 -> V_121 ) ;
F_69 ( V_4 , V_164 , V_4 ) ;
if ( V_37 ) {
F_7 ( 1 , L_71 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_82 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_78 * V_79 , int V_171 )
{
unsigned long V_91 ;
int V_37 ;
V_37 = F_79 ( V_4 , V_171 ) ;
if ( V_37 )
return V_37 ;
F_52 ( & V_4 -> V_136 , V_91 ) ;
* V_2 = F_83 ( & V_4 -> V_138 , struct V_1 , V_137 ) ;
V_37 = F_25 ( * V_2 , V_79 ) ;
if ( ! V_37 )
F_84 ( & ( * V_2 ) -> V_137 ) ;
F_55 ( & V_4 -> V_136 , V_91 ) ;
return V_37 ;
}
int F_85 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_121 ) {
F_7 ( 1 , L_67 ) ;
return - V_80 ;
}
if ( V_4 -> V_134 )
F_86 ( V_4 -> V_140 , ! F_76 ( & V_4 -> V_139 ) ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_167 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_167 = 0 ; V_167 < V_2 -> V_7 ; ++ V_167 ) {
if ( ! V_2 -> V_13 [ V_167 ] . V_23 )
continue;
F_5 ( V_2 , V_24 , V_2 -> V_13 [ V_167 ] . V_5 ) ;
V_2 -> V_13 [ V_167 ] . V_23 = 0 ;
}
}
static int F_88 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_171 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_72 ) ;
return - V_80 ;
}
V_37 = F_82 ( V_4 , & V_2 , V_79 , V_171 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_2 -> V_40 ) {
case V_102 :
F_7 ( 3 , L_73 ) ;
break;
case V_100 :
F_7 ( 3 , L_74 ) ;
break;
default:
F_7 ( 1 , L_75 ) ;
return - V_80 ;
}
F_21 ( V_2 , V_172 , V_2 ) ;
F_31 ( V_2 , V_79 ) ;
F_84 ( & V_2 -> V_168 ) ;
V_4 -> V_169 -- ;
F_87 ( V_2 ) ;
F_7 ( 1 , L_76 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
int F_89 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_171 )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_88 ( V_4 , V_79 , V_171 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_167 ;
if ( V_4 -> V_134 )
F_69 ( V_4 , V_173 , V_4 ) ;
if ( F_51 ( F_76 ( & V_4 -> V_139 ) ) ) {
for ( V_167 = 0 ; V_167 < V_4 -> V_29 ; ++ V_167 )
if ( V_4 -> V_30 [ V_167 ] -> V_40 == V_98 )
F_50 ( V_4 -> V_30 [ V_167 ] , V_100 ) ;
F_51 ( F_76 ( & V_4 -> V_139 ) ) ;
}
V_4 -> V_121 = 0 ;
V_4 -> V_134 = 0 ;
V_4 -> V_169 = 0 ;
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_138 ) ;
F_90 ( & V_4 -> V_139 , 0 ) ;
F_91 ( & V_4 -> V_140 ) ;
for ( V_167 = 0 ; V_167 < V_4 -> V_29 ; ++ V_167 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_167 ] ;
if ( V_2 -> V_40 != V_41 ) {
V_2 -> V_40 = V_104 ;
F_21 ( V_2 , V_172 , V_2 ) ;
}
F_87 ( V_2 ) ;
}
}
static int F_92 ( struct V_3 * V_4 , enum V_116 type )
{
int V_37 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_77 ) ;
return - V_80 ;
}
if ( V_4 -> V_121 ) {
F_7 ( 3 , L_78 ) ;
return 0 ;
}
if ( ! V_4 -> V_29 ) {
F_7 ( 1 , L_79 ) ;
return - V_80 ;
}
if ( V_4 -> V_29 < V_4 -> V_124 ) {
F_7 ( 1 , L_80 ,
V_4 -> V_124 ) ;
return - V_80 ;
}
if ( V_4 -> V_169 >= V_4 -> V_124 ) {
V_37 = F_75 ( V_4 ) ;
if ( V_37 ) {
F_40 ( V_4 ) ;
return V_37 ;
}
}
V_4 -> V_121 = 1 ;
F_7 ( 3 , L_81 ) ;
return 0 ;
}
int F_93 ( struct V_3 * V_4 , enum V_116 type )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_92 ( V_4 , type ) ;
}
static int F_94 ( struct V_3 * V_4 , enum V_116 type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_77 ) ;
return - V_80 ;
}
F_40 ( V_4 ) ;
F_7 ( 3 , L_81 ) ;
return 0 ;
}
int F_95 ( struct V_3 * V_4 , enum V_116 type )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_94 ( V_4 , type ) ;
}
static int F_96 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_174 , unsigned int * V_175 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_31 ) {
* V_174 = V_28 ;
* V_175 = V_6 ;
return 0 ;
}
}
}
return - V_80 ;
}
int F_97 ( struct V_3 * V_4 , struct V_176 * V_177 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_178 ;
int V_37 ;
struct V_151 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_82 ) ;
return - V_80 ;
}
if ( ! V_4 -> V_109 -> V_179 ) {
F_7 ( 1 , L_83 ) ;
return - V_80 ;
}
if ( V_177 -> V_91 & ~ ( V_180 | V_181 ) ) {
F_7 ( 1 , L_84 ) ;
return - V_80 ;
}
if ( V_177 -> type != V_4 -> type ) {
F_7 ( 1 , L_72 ) ;
return - V_80 ;
}
if ( V_177 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_27 ) ;
return - V_80 ;
}
V_2 = V_4 -> V_30 [ V_177 -> V_19 ] ;
if ( V_177 -> V_6 >= V_2 -> V_7 ) {
F_7 ( 1 , L_85 ) ;
return - V_80 ;
}
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_86 ) ;
return - V_117 ;
}
V_178 = & V_2 -> V_13 [ V_177 -> V_6 ] ;
V_26 = F_3 ( V_2 , V_179 , V_178 -> V_5 , V_177 -> V_91 & V_181 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_87 ,
V_177 -> V_19 , V_177 -> V_6 ) ;
return - V_80 ;
}
V_37 = F_98 ( V_26 , V_177 -> V_91 & ~ V_181 ) ;
if ( V_37 < 0 ) {
F_7 ( 3 , L_88 ,
V_177 -> V_19 , V_177 -> V_6 , V_37 ) ;
F_10 ( V_26 ) ;
return V_37 ;
}
F_7 ( 3 , L_89 ,
V_177 -> V_19 , V_177 -> V_6 , V_37 ) ;
V_177 -> V_90 = V_37 ;
return 0 ;
}
int F_99 ( struct V_3 * V_4 , struct V_182 * V_183 )
{
unsigned long V_31 = V_183 -> V_184 << V_185 ;
struct V_1 * V_2 ;
unsigned int V_28 = 0 , V_6 = 0 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_82 ) ;
return - V_80 ;
}
if ( ! ( V_183 -> V_186 & V_187 ) ) {
F_7 ( 1 , L_90 ) ;
return - V_80 ;
}
if ( F_27 ( V_4 -> type ) ) {
if ( ! ( V_183 -> V_186 & V_188 ) ) {
F_7 ( 1 , L_91 ) ;
return - V_80 ;
}
} else {
if ( ! ( V_183 -> V_186 & V_189 ) ) {
F_7 ( 1 , L_92 ) ;
return - V_80 ;
}
}
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_93 ) ;
return - V_117 ;
}
V_37 = F_96 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_183 -> V_190 - V_183 -> V_191 ) ) {
F_7 ( 1 ,
L_94 ) ;
return - V_80 ;
}
V_37 = F_29 ( V_2 , V_112 , V_2 -> V_13 [ V_6 ] . V_5 , V_183 ) ;
if ( V_37 )
return V_37 ;
F_7 ( 3 , L_95 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_100 ( struct V_3 * V_4 ,
unsigned long V_192 ,
unsigned long V_193 ,
unsigned long V_194 ,
unsigned long V_91 )
{
unsigned long V_31 = V_194 << V_185 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_82 ) ;
return - V_80 ;
}
V_37 = F_96 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
return ( unsigned long ) F_48 ( V_2 , V_6 ) ;
}
unsigned int F_101 ( struct V_3 * V_4 , struct V_195 * V_195 , T_1 * V_196 )
{
struct V_197 * V_198 = F_102 ( V_195 ) ;
unsigned long V_199 = F_103 ( V_196 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_200 = 0 ;
unsigned long V_91 ;
if ( F_104 ( V_201 , & V_198 -> V_91 ) ) {
struct V_202 * V_203 = V_195 -> V_204 ;
if ( F_105 ( V_203 ) )
V_200 = V_205 ;
else if ( V_199 & V_205 )
F_106 ( V_195 , & V_203 -> V_196 , V_196 ) ;
}
if ( ! F_27 ( V_4 -> type ) && ! ( V_199 & ( V_206 | V_207 ) ) )
return V_200 ;
if ( F_27 ( V_4 -> type ) && ! ( V_199 & ( V_208 | V_209 ) ) )
return V_200 ;
if ( V_4 -> V_29 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_210 ) &&
( V_199 & ( V_206 | V_207 ) ) ) {
if ( F_107 ( V_4 , 1 ) )
return V_200 | V_211 ;
}
if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_212 ) &&
( V_199 & ( V_208 | V_209 ) ) ) {
if ( F_107 ( V_4 , 0 ) )
return V_200 | V_211 ;
return V_200 | V_208 | V_209 ;
}
}
if ( F_80 ( & V_4 -> V_77 ) )
return V_200 | V_211 ;
if ( F_80 ( & V_4 -> V_138 ) )
F_106 ( V_195 , & V_4 -> V_140 , V_196 ) ;
F_52 ( & V_4 -> V_136 , V_91 ) ;
if ( ! F_80 ( & V_4 -> V_138 ) )
V_2 = F_83 ( & V_4 -> V_138 , struct V_1 ,
V_137 ) ;
F_55 ( & V_4 -> V_136 , V_91 ) ;
if ( V_2 && ( V_2 -> V_40 == V_102
|| V_2 -> V_40 == V_100 ) ) {
return ( F_27 ( V_4 -> type ) ) ?
V_200 | V_208 | V_209 :
V_200 | V_206 | V_207 ;
}
return V_200 ;
}
int F_108 ( struct V_3 * V_4 )
{
if ( F_51 ( ! V_4 ) ||
F_51 ( ! V_4 -> V_213 ) ||
F_51 ( ! V_4 -> V_109 ) ||
F_51 ( ! V_4 -> type ) ||
F_51 ( ! V_4 -> V_107 ) ||
F_51 ( ! V_4 -> V_213 -> V_123 ) ||
F_51 ( ! V_4 -> V_213 -> V_153 ) ||
F_51 ( V_4 -> V_93 &
~ ( V_94 |
V_96 ) ) )
return - V_80 ;
F_51 ( ( V_4 -> V_93 & V_94 ) ==
V_214 ) ;
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_138 ) ;
F_109 ( & V_4 -> V_136 ) ;
F_110 ( & V_4 -> V_140 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_111 ( struct V_3 * V_4 )
{
F_112 ( V_4 ) ;
F_40 ( V_4 ) ;
F_20 ( V_4 , V_4 -> V_29 ) ;
}
static int F_107 ( struct V_3 * V_4 , int V_215 )
{
struct V_216 * V_217 ;
int V_167 , V_37 ;
unsigned int V_122 = 0 ;
if ( F_51 ( ( V_215 && ! ( V_4 -> V_107 & V_210 ) ) ||
( ! V_215 && ! ( V_4 -> V_107 & V_212 ) ) ) )
return - V_80 ;
if ( ! V_4 -> V_109 -> V_131 )
return - V_117 ;
if ( V_4 -> V_121 || V_4 -> V_29 > 0 )
return - V_117 ;
V_122 = 1 ;
F_7 ( 3 , L_96 ,
( V_215 ) ? L_97 : L_98 , V_122 , V_4 -> V_218 ) ;
V_217 = F_15 ( sizeof( struct V_216 ) , V_39 ) ;
if ( V_217 == NULL )
return - V_17 ;
V_217 -> V_91 = V_4 -> V_218 ;
V_217 -> V_119 . V_122 = V_122 ;
V_217 -> V_119 . V_36 = V_42 ;
V_217 -> V_119 . type = V_4 -> type ;
V_4 -> V_217 = V_217 ;
V_37 = F_39 ( V_4 , & V_217 -> V_119 ) ;
if ( V_37 )
goto V_219;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_117 ;
goto V_220;
}
for ( V_167 = 0 ; V_167 < V_4 -> V_29 ; V_167 ++ ) {
V_217 -> V_30 [ V_167 ] . V_131 = F_48 ( V_4 -> V_30 [ V_167 ] , 0 ) ;
if ( V_217 -> V_30 [ V_167 ] . V_131 == NULL ) {
V_37 = - V_80 ;
goto V_220;
}
V_217 -> V_30 [ V_167 ] . V_8 = F_113 ( V_4 -> V_30 [ V_167 ] , 0 ) ;
}
if ( V_215 ) {
bool V_221 = F_16 ( V_4 -> type ) ;
for ( V_167 = 0 ; V_167 < V_4 -> V_29 ; V_167 ++ ) {
struct V_78 * V_79 = & V_217 -> V_79 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_4 -> type ;
if ( V_221 ) {
memset ( & V_217 -> V_22 , 0 , sizeof( V_217 -> V_22 ) ) ;
V_79 -> V_33 . V_13 = & V_217 -> V_22 ;
V_79 -> V_15 = 1 ;
}
V_79 -> V_36 = V_4 -> V_36 ;
V_79 -> V_19 = V_167 ;
V_37 = F_77 ( V_4 , V_79 ) ;
if ( V_37 )
goto V_220;
V_217 -> V_30 [ V_167 ] . V_222 = 1 ;
}
V_217 -> V_223 = V_4 -> V_29 ;
V_217 -> V_224 = V_4 -> V_29 ;
}
V_37 = F_92 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_220;
return V_37 ;
V_220:
V_217 -> V_119 . V_122 = 0 ;
F_39 ( V_4 , & V_217 -> V_119 ) ;
V_219:
V_4 -> V_217 = NULL ;
F_17 ( V_217 ) ;
return V_37 ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_216 * V_217 = V_4 -> V_217 ;
if ( V_217 ) {
F_94 ( V_4 , V_4 -> type ) ;
V_4 -> V_217 = NULL ;
V_217 -> V_119 . V_122 = 0 ;
F_44 ( V_4 , & V_217 -> V_119 ) ;
F_17 ( V_217 ) ;
F_7 ( 3 , L_99 ) ;
}
return 0 ;
}
static T_2 F_114 ( struct V_3 * V_4 , char T_3 * V_225 , T_2 V_122 ,
T_4 * V_226 , int V_227 , int V_215 )
{
struct V_216 * V_217 ;
struct V_228 * V_229 ;
bool V_221 = F_16 ( V_4 -> type ) ;
bool V_230 = ! V_215 &&
( V_4 -> V_93 & V_94 ) ==
V_95 ;
int V_37 , V_19 ;
F_7 ( 3 , L_100 ,
V_215 ? L_97 : L_98 , ( long ) * V_226 , V_122 ,
V_227 ? L_101 : L_12 ) ;
if ( ! V_225 )
return - V_80 ;
if ( ! F_38 ( V_4 ) ) {
V_37 = F_107 ( V_4 , V_215 ) ;
F_7 ( 3 , L_102 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_217 = V_4 -> V_217 ;
V_19 = V_217 -> V_224 ;
if ( V_19 >= V_4 -> V_29 ) {
memset ( & V_217 -> V_79 , 0 , sizeof( V_217 -> V_79 ) ) ;
V_217 -> V_79 . type = V_4 -> type ;
V_217 -> V_79 . V_36 = V_4 -> V_36 ;
if ( V_221 ) {
memset ( & V_217 -> V_22 , 0 , sizeof( V_217 -> V_22 ) ) ;
V_217 -> V_79 . V_33 . V_13 = & V_217 -> V_22 ;
V_217 -> V_79 . V_15 = 1 ;
}
V_37 = F_88 ( V_4 , & V_217 -> V_79 , V_227 ) ;
F_7 ( 5 , L_103 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_217 -> V_231 += 1 ;
V_217 -> V_224 = V_19 = V_217 -> V_79 . V_19 ;
V_229 = & V_217 -> V_30 [ V_19 ] ;
V_229 -> V_232 = 0 ;
V_229 -> V_222 = 0 ;
V_229 -> V_8 = V_215 ? F_115 ( V_4 -> V_30 [ V_19 ] , 0 )
: F_113 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
} else {
V_229 = & V_217 -> V_30 [ V_19 ] ;
}
if ( V_229 -> V_232 + V_122 > V_229 -> V_8 ) {
V_122 = V_229 -> V_8 - V_229 -> V_232 ;
F_7 ( 5 , L_104 , V_122 ) ;
}
F_7 ( 3 , L_105 ,
V_122 , V_19 , V_229 -> V_232 ) ;
if ( V_215 )
V_37 = F_116 ( V_225 , V_229 -> V_131 + V_229 -> V_232 , V_122 ) ;
else
V_37 = F_117 ( V_229 -> V_131 + V_229 -> V_232 , V_225 , V_122 ) ;
if ( V_37 ) {
F_7 ( 3 , L_106 ) ;
return - V_233 ;
}
V_229 -> V_232 += V_122 ;
* V_226 += V_122 ;
if ( V_229 -> V_232 == V_229 -> V_8 ||
( ! V_215 && ( V_217 -> V_91 & V_234 ) ) ) {
if ( V_215 && ( V_217 -> V_91 & V_235 ) &&
V_217 -> V_231 == 1 ) {
F_7 ( 3 , L_107 ) ;
return F_112 ( V_4 ) ;
}
memset ( & V_217 -> V_79 , 0 , sizeof( V_217 -> V_79 ) ) ;
V_217 -> V_79 . type = V_4 -> type ;
V_217 -> V_79 . V_36 = V_4 -> V_36 ;
V_217 -> V_79 . V_19 = V_19 ;
V_217 -> V_79 . V_83 = V_229 -> V_232 ;
if ( V_221 ) {
memset ( & V_217 -> V_22 , 0 , sizeof( V_217 -> V_22 ) ) ;
V_217 -> V_22 . V_83 = V_229 -> V_232 ;
V_217 -> V_79 . V_33 . V_13 = & V_217 -> V_22 ;
V_217 -> V_79 . V_15 = 1 ;
}
if ( V_230 )
F_118 ( & V_217 -> V_79 . V_157 ) ;
V_37 = F_77 ( V_4 , & V_217 -> V_79 ) ;
F_7 ( 5 , L_108 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_229 -> V_232 = 0 ;
V_229 -> V_222 = 1 ;
V_229 -> V_8 = F_113 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
V_217 -> V_236 += 1 ;
if ( V_217 -> V_223 < V_4 -> V_29 )
V_217 -> V_223 ++ ;
V_217 -> V_224 = V_217 -> V_223 ;
}
if ( V_37 == 0 )
V_37 = V_122 ;
return V_37 ;
}
T_2 F_119 ( struct V_3 * V_4 , char T_3 * V_225 , T_2 V_122 ,
T_4 * V_226 , int V_171 )
{
return F_114 ( V_4 , V_225 , V_122 , V_226 , V_171 , 1 ) ;
}
T_2 F_120 ( struct V_3 * V_4 , const char T_3 * V_225 , T_2 V_122 ,
T_4 * V_226 , int V_171 )
{
return F_114 ( V_4 , ( char T_3 * ) V_225 , V_122 ,
V_226 , V_171 , 0 ) ;
}
static int F_121 ( void * V_225 )
{
struct V_3 * V_4 = V_225 ;
struct V_237 * V_238 = V_4 -> V_238 ;
struct V_216 * V_217 = V_4 -> V_217 ;
bool V_230 = false ;
int V_239 = 0 ;
int V_19 = 0 ;
int V_37 = 0 ;
if ( F_27 ( V_4 -> type ) ) {
V_239 = V_4 -> V_29 ;
V_230 =
( V_4 -> V_93 & V_94 ) ==
V_95 ;
}
F_122 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_217 -> V_79 , 0 , sizeof( V_217 -> V_79 ) ) ;
V_217 -> V_79 . type = V_4 -> type ;
V_217 -> V_79 . V_36 = V_4 -> V_36 ;
if ( V_239 ) {
V_217 -> V_79 . V_19 = V_19 ++ ;
V_239 -- ;
} else {
F_69 ( V_4 , V_164 , V_4 ) ;
V_37 = F_88 ( V_4 , & V_217 -> V_79 , 0 ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
F_7 ( 5 , L_109 , V_37 ) ;
}
if ( V_238 -> V_240 )
break;
if ( V_37 )
break;
F_123 () ;
V_2 = V_4 -> V_30 [ V_217 -> V_79 . V_19 ] ;
if ( ! ( V_217 -> V_79 . V_91 & V_101 ) )
V_37 = V_238 -> V_241 ( V_2 , V_238 -> V_242 ) ;
if ( V_37 )
break;
F_69 ( V_4 , V_164 , V_4 ) ;
if ( V_230 )
F_118 ( & V_217 -> V_79 . V_157 ) ;
V_37 = F_77 ( V_4 , & V_217 -> V_79 ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
if ( V_37 )
break;
}
while ( ! F_124 () ) {
F_125 ( V_243 ) ;
F_126 () ;
}
return 0 ;
}
int F_127 ( struct V_3 * V_4 , T_5 V_241 , void * V_242 ,
const char * V_244 )
{
struct V_237 * V_238 ;
int V_37 = 0 ;
if ( V_4 -> V_238 )
return - V_117 ;
if ( F_128 ( V_4 ) )
return - V_117 ;
if ( F_51 ( V_4 -> V_217 ) )
return - V_117 ;
V_238 = F_15 ( sizeof( * V_238 ) , V_39 ) ;
if ( V_238 == NULL )
return - V_17 ;
V_238 -> V_241 = V_241 ;
V_238 -> V_242 = V_242 ;
V_37 = F_107 ( V_4 , ! F_27 ( V_4 -> type ) ) ;
F_7 ( 3 , L_110 , V_37 ) ;
if ( V_37 )
goto V_245;
V_4 -> V_238 = V_238 ;
V_238 -> V_246 = F_129 ( F_121 , V_4 , L_111 , V_244 ) ;
if ( F_65 ( V_238 -> V_246 ) ) {
V_37 = F_62 ( V_238 -> V_246 ) ;
V_238 -> V_246 = NULL ;
goto V_247;
}
return 0 ;
V_247:
F_112 ( V_4 ) ;
V_245:
F_17 ( V_238 ) ;
return V_37 ;
}
int F_130 ( struct V_3 * V_4 )
{
struct V_237 * V_238 = V_4 -> V_238 ;
struct V_216 * V_217 = V_4 -> V_217 ;
int V_150 ;
if ( V_238 == NULL )
return 0 ;
F_69 ( V_4 , V_164 , V_4 ) ;
V_238 -> V_240 = true ;
F_94 ( V_4 , V_4 -> type ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
V_4 -> V_217 = NULL ;
V_217 -> V_119 . V_122 = 0 ;
F_44 ( V_4 , & V_217 -> V_119 ) ;
F_17 ( V_217 ) ;
V_150 = F_131 ( V_238 -> V_246 ) ;
V_238 -> V_246 = NULL ;
F_17 ( V_238 ) ;
V_4 -> V_217 = NULL ;
V_4 -> V_238 = NULL ;
return V_150 ;
}
static inline bool F_132 ( struct V_197 * V_248 , struct V_195 * V_195 )
{
return V_248 -> V_249 -> V_250 && V_248 -> V_249 -> V_250 != V_195 -> V_204 ;
}
int F_133 ( struct V_195 * V_195 , void * V_242 ,
struct V_118 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
int V_200 = F_37 ( V_248 -> V_249 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_200 )
return V_200 ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
V_200 = F_39 ( V_248 -> V_249 , V_22 ) ;
if ( V_200 == 0 )
V_248 -> V_249 -> V_250 = V_22 -> V_122 ? V_195 -> V_204 : NULL ;
return V_200 ;
}
int F_134 ( struct V_195 * V_195 , void * V_242 ,
struct V_125 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
int V_200 = F_37 ( V_248 -> V_249 , V_22 -> V_36 , V_22 -> V_129 . type ) ;
V_22 -> V_19 = V_248 -> V_249 -> V_29 ;
if ( V_22 -> V_122 == 0 )
return V_200 != - V_117 ? V_200 : 0 ;
if ( V_200 )
return V_200 ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
V_200 = F_45 ( V_248 -> V_249 , V_22 ) ;
if ( V_200 == 0 )
V_248 -> V_249 -> V_250 = V_195 -> V_204 ;
return V_200 ;
}
int F_135 ( struct V_195 * V_195 , void * V_242 ,
struct V_78 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_74 ( V_248 -> V_249 , V_22 ) ;
}
int F_136 ( struct V_195 * V_195 , void * V_242 , struct V_78 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
return F_33 ( V_248 -> V_249 , V_22 ) ;
}
int F_137 ( struct V_195 * V_195 , void * V_242 , struct V_78 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_78 ( V_248 -> V_249 , V_22 ) ;
}
int F_138 ( struct V_195 * V_195 , void * V_242 , struct V_78 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_89 ( V_248 -> V_249 , V_22 , V_195 -> V_251 & V_252 ) ;
}
int F_139 ( struct V_195 * V_195 , void * V_242 , enum V_116 V_167 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_93 ( V_248 -> V_249 , V_167 ) ;
}
int F_140 ( struct V_195 * V_195 , void * V_242 , enum V_116 V_167 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_95 ( V_248 -> V_249 , V_167 ) ;
}
int F_141 ( struct V_195 * V_195 , void * V_242 , struct V_176 * V_22 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( F_132 ( V_248 , V_195 ) )
return - V_117 ;
return F_97 ( V_248 -> V_249 , V_22 ) ;
}
int F_142 ( struct V_195 * V_195 , struct V_182 * V_183 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_253 * V_254 = V_248 -> V_249 -> V_254 ? V_248 -> V_249 -> V_254 : V_248 -> V_254 ;
int V_150 ;
if ( V_254 && F_143 ( V_254 ) )
return - V_255 ;
V_150 = F_99 ( V_248 -> V_249 , V_183 ) ;
if ( V_254 )
F_144 ( V_254 ) ;
return V_150 ;
}
int F_145 ( struct V_195 * V_195 , struct V_253 * V_254 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
if ( V_195 -> V_204 == V_248 -> V_249 -> V_250 ) {
if ( V_254 )
F_146 ( V_254 ) ;
F_111 ( V_248 -> V_249 ) ;
V_248 -> V_249 -> V_250 = NULL ;
if ( V_254 )
F_144 ( V_254 ) ;
}
return F_147 ( V_195 ) ;
}
int F_148 ( struct V_195 * V_195 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_253 * V_254 = V_248 -> V_249 -> V_254 ? V_248 -> V_249 -> V_254 : V_248 -> V_254 ;
return F_145 ( V_195 , V_254 ) ;
}
T_6 F_149 ( struct V_195 * V_195 , const char T_3 * V_229 ,
T_2 V_122 , T_4 * V_226 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_253 * V_254 = V_248 -> V_249 -> V_254 ? V_248 -> V_249 -> V_254 : V_248 -> V_254 ;
int V_150 = - V_117 ;
if ( V_254 && F_143 ( V_254 ) )
return - V_255 ;
if ( F_132 ( V_248 , V_195 ) )
goto exit;
V_150 = F_120 ( V_248 -> V_249 , V_229 , V_122 , V_226 ,
V_195 -> V_251 & V_252 ) ;
if ( V_248 -> V_249 -> V_217 )
V_248 -> V_249 -> V_250 = V_195 -> V_204 ;
exit:
if ( V_254 )
F_144 ( V_254 ) ;
return V_150 ;
}
T_6 F_150 ( struct V_195 * V_195 , char T_3 * V_229 ,
T_2 V_122 , T_4 * V_226 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_253 * V_254 = V_248 -> V_249 -> V_254 ? V_248 -> V_249 -> V_254 : V_248 -> V_254 ;
int V_150 = - V_117 ;
if ( V_254 && F_143 ( V_254 ) )
return - V_255 ;
if ( F_132 ( V_248 , V_195 ) )
goto exit;
V_150 = F_119 ( V_248 -> V_249 , V_229 , V_122 , V_226 ,
V_195 -> V_251 & V_252 ) ;
if ( V_248 -> V_249 -> V_217 )
V_248 -> V_249 -> V_250 = V_195 -> V_204 ;
exit:
if ( V_254 )
F_144 ( V_254 ) ;
return V_150 ;
}
unsigned int F_151 ( struct V_195 * V_195 , T_1 * V_196 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_3 * V_4 = V_248 -> V_249 ;
struct V_253 * V_254 = V_4 -> V_254 ? V_4 -> V_254 : V_248 -> V_254 ;
unsigned long V_199 = F_103 ( V_196 ) ;
unsigned V_200 ;
void * V_217 ;
bool V_256 = false ;
if ( V_4 -> V_29 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_210 ) &&
( V_199 & ( V_206 | V_207 ) ) )
V_256 = true ;
else if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_212 ) &&
( V_199 & ( V_208 | V_209 ) ) )
V_256 = true ;
}
F_51 ( V_256 && ! V_254 ) ;
if ( V_256 && V_254 && F_143 ( V_254 ) )
return V_211 ;
V_217 = V_4 -> V_217 ;
V_200 = F_101 ( V_248 -> V_249 , V_195 , V_196 ) ;
if ( V_256 && ! V_217 && V_4 -> V_217 )
V_4 -> V_250 = V_195 -> V_204 ;
if ( V_256 && V_254 )
F_144 ( V_254 ) ;
return V_200 ;
}
unsigned long F_152 ( struct V_195 * V_195 , unsigned long V_192 ,
unsigned long V_193 , unsigned long V_194 , unsigned long V_91 )
{
struct V_197 * V_248 = F_102 ( V_195 ) ;
struct V_253 * V_254 = V_248 -> V_249 -> V_254 ? V_248 -> V_249 -> V_254 : V_248 -> V_254 ;
int V_37 ;
if ( V_254 && F_143 ( V_254 ) )
return - V_255 ;
V_37 = F_100 ( V_248 -> V_249 , V_192 , V_193 , V_194 , V_91 ) ;
if ( V_254 )
F_144 ( V_254 ) ;
return V_37 ;
}
void F_153 ( struct V_3 * V_257 )
{
F_144 ( V_257 -> V_254 ) ;
}
void F_154 ( struct V_3 * V_257 )
{
F_146 ( V_257 -> V_254 ) ;
}
