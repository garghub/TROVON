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
F_5 ( V_2 , V_10 ) ;
for (; V_6 > 0 ; -- V_6 ) {
F_3 ( V_2 , V_16 , V_2 -> V_13 [ V_6 - 1 ] . V_5 ) ;
V_2 -> V_13 [ V_6 - 1 ] . V_5 = NULL ;
}
return - V_17 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
F_3 ( V_2 , V_16 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
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
F_3 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( ! V_22 -> V_5 )
return;
if ( V_22 -> V_23 )
F_3 ( V_2 , V_24 , V_22 -> V_5 ) ;
F_3 ( V_2 , V_25 , V_22 -> V_5 ) ;
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
F_19 ( V_2 , V_43 ) ;
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
static void F_20 ( struct V_3 * V_4 , unsigned int V_44 )
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
static int F_21 ( struct V_3 * V_4 , unsigned int V_44 )
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
F_18 ( V_2 , V_48 , V_2 ) ;
}
F_20 ( V_4 , V_44 ) ;
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
if ( V_5 && F_3 ( V_2 , V_85 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_29 ( struct V_3 * V_4 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
if ( F_28 ( V_4 , V_4 -> V_30 [ V_28 ] ) )
return true ;
}
return false ;
}
static void F_30 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_79 , & V_2 -> V_18 , F_31 ( struct V_78 , V_33 ) ) ;
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
int F_32 ( struct V_3 * V_4 , struct V_78 * V_79 )
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
F_30 ( V_2 , V_79 ) ;
return V_37 ;
}
static int F_33 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_108 ) || ! V_4 -> V_109 -> V_110 ||
! V_4 -> V_109 -> V_20 )
return - V_80 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_111 ) || ! V_4 -> V_109 -> V_10 ||
! V_4 -> V_109 -> V_16 || ! V_4 -> V_109 -> V_112 )
return - V_80 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_107 & V_113 ) || ! V_4 -> V_109 -> V_114 ||
! V_4 -> V_109 -> V_25 || ! V_4 -> V_109 -> V_115 ||
! V_4 -> V_109 -> V_24 )
return - V_80 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
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
if ( V_36 == V_42 && F_34 ( V_4 ) ) {
F_7 ( 1 , L_30 ) ;
return - V_80 ;
}
if ( V_36 == V_82 && F_33 ( V_4 ) ) {
F_7 ( 1 , L_31 ) ;
return - V_80 ;
}
if ( V_36 == V_45 && F_35 ( V_4 ) ) {
F_7 ( 1 , L_32 ) ;
return - V_80 ;
}
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_33 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
unsigned int V_29 , V_121 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_122 ) {
F_7 ( 1 , L_34 ) ;
return - V_118 ;
}
if ( V_120 -> V_123 == 0 || V_4 -> V_29 != 0 || V_4 -> V_36 != V_120 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_29 ( V_4 ) ) {
F_7 ( 1 , L_35 ) ;
return - V_118 ;
}
F_38 ( V_4 ) ;
V_37 = F_21 ( V_4 , V_4 -> V_29 ) ;
if ( V_37 )
return V_37 ;
if ( V_120 -> V_123 == 0 )
return 0 ;
}
V_29 = F_39 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
V_29 = F_40 (unsigned int, req->count, q->min_buffers_needed) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_120 -> V_36 ;
V_37 = F_41 ( V_4 , V_124 , V_4 , NULL , & V_29 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 ) {
F_42 ( V_4 , V_124 ) ;
return V_37 ;
}
V_121 = F_14 ( V_4 , V_120 -> V_36 , V_29 , V_7 ) ;
if ( V_121 == 0 ) {
F_7 ( 1 , L_36 ) ;
return - V_17 ;
}
if ( V_121 < V_4 -> V_125 )
V_37 = - V_17 ;
if ( ! V_37 && V_121 < V_29 ) {
V_29 = V_121 ;
V_37 = F_41 ( V_4 , V_124 , V_4 , NULL , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
F_42 ( V_4 , V_124 ) ;
if ( ! V_37 && V_121 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 = V_121 ;
if ( V_37 < 0 ) {
F_21 ( V_4 , V_121 ) ;
return V_37 ;
}
V_120 -> V_123 = V_121 ;
return 0 ;
}
int F_43 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
int V_37 = F_36 ( V_4 , V_120 -> V_36 , V_120 -> type ) ;
return V_37 ? V_37 : F_37 ( V_4 , V_120 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_126 * V_127 )
{
unsigned int V_7 = 0 , V_29 , V_121 ;
int V_37 ;
if ( V_4 -> V_29 == V_128 ) {
F_7 ( 1 , L_37 ,
V_129 ) ;
return - V_130 ;
}
if ( ! V_4 -> V_29 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_127 -> V_36 ;
}
V_29 = F_45 ( V_127 -> V_123 , V_128 - V_4 -> V_29 ) ;
V_37 = F_41 ( V_4 , V_124 , V_4 , & V_127 -> V_131 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 ) {
F_42 ( V_4 , V_124 ) ;
return V_37 ;
}
V_121 = F_14 ( V_4 , V_127 -> V_36 , V_29 ,
V_7 ) ;
if ( V_121 == 0 ) {
F_7 ( 1 , L_36 ) ;
return - V_17 ;
}
if ( V_121 < V_29 ) {
V_29 = V_121 ;
V_37 = F_41 ( V_4 , V_124 , V_4 , & V_127 -> V_131 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
F_42 ( V_4 , V_124 ) ;
if ( ! V_37 && V_121 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 += V_121 ;
if ( V_37 < 0 ) {
F_21 ( V_4 , V_121 ) ;
return - V_17 ;
}
V_127 -> V_123 = V_121 ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , struct V_126 * V_127 )
{
int V_37 = F_36 ( V_4 , V_127 -> V_36 , V_127 -> V_131 . type ) ;
V_127 -> V_19 = V_4 -> V_29 ;
if ( V_127 -> V_123 == 0 )
return V_37 != - V_118 ? V_37 : 0 ;
return V_37 ? V_37 : F_44 ( V_4 , V_127 ) ;
}
void * F_47 ( struct V_1 * V_2 , unsigned int V_132 )
{
if ( V_132 > V_2 -> V_7 || ! V_2 -> V_13 [ V_132 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_133 , V_2 -> V_13 [ V_132 ] . V_5 ) ;
}
void * F_48 ( struct V_1 * V_2 , unsigned int V_132 )
{
if ( V_132 > V_2 -> V_7 || ! V_2 -> V_13 [ V_132 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_134 , V_2 -> V_13 [ V_132 ] . V_5 ) ;
}
void F_49 ( struct V_1 * V_2 , enum V_135 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_91 ;
unsigned int V_6 ;
if ( F_50 ( V_2 -> V_40 != V_98 ) )
return;
if ( ! V_4 -> V_136 ) {
if ( F_50 ( V_40 != V_97 ) )
V_40 = V_97 ;
} else if ( ! F_50 ( ! V_4 -> V_136 ) ) {
if ( F_50 ( V_40 != V_102 &&
V_40 != V_100 ) )
V_40 = V_100 ;
}
#ifdef F_22
V_2 -> V_67 ++ ;
#endif
F_7 ( 4 , L_38 ,
V_2 -> V_18 . V_19 , V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_2 , V_137 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_51 ( & V_4 -> V_138 , V_91 ) ;
V_2 -> V_40 = V_40 ;
if ( V_40 != V_97 )
F_52 ( & V_2 -> V_139 , & V_4 -> V_140 ) ;
F_53 ( & V_4 -> V_141 ) ;
F_54 ( & V_4 -> V_138 , V_91 ) ;
if ( V_40 == V_97 )
return;
F_55 ( & V_4 -> V_142 ) ;
}
static void F_56 ( struct V_1 * V_2 , const struct V_78 * V_79 ,
struct V_32 * V_14 )
{
unsigned int V_6 ;
if ( F_16 ( V_79 -> type ) ) {
if ( F_27 ( V_79 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_83 =
V_79 -> V_33 . V_13 [ V_6 ] . V_83 ;
V_14 [ V_6 ] . V_84 =
V_79 -> V_33 . V_13 [ V_6 ] . V_84 ;
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
V_14 [ V_6 ] . V_84 =
V_79 -> V_33 . V_13 [ V_6 ] . V_84 ;
}
}
} else {
if ( F_27 ( V_79 -> type ) ) {
V_14 [ 0 ] . V_83 = V_79 -> V_83 ;
V_14 [ 0 ] . V_84 = 0 ;
}
if ( V_79 -> V_36 == V_82 ) {
V_14 [ 0 ] . V_33 . V_89 = V_79 -> V_33 . V_89 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
}
if ( V_79 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_90 = V_79 -> V_33 . V_90 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
V_14 [ 0 ] . V_84 = 0 ;
}
}
V_2 -> V_18 . V_91 = V_79 -> V_91 & ~ V_92 ;
if ( ( V_2 -> V_3 -> V_93 & V_94 ) !=
V_95 || ! F_27 ( V_79 -> type ) ) {
V_2 -> V_18 . V_91 &= ~ V_96 ;
}
if ( F_27 ( V_79 -> type ) ) {
V_2 -> V_18 . V_91 &= ~ V_143 ;
V_2 -> V_18 . V_144 = V_79 -> V_144 ;
} else {
V_2 -> V_18 . V_91 &= ~ V_145 ;
}
}
static int F_57 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_32 V_13 [ V_81 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_146 = ! F_27 ( V_4 -> type ) ;
bool V_147 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
F_56 ( V_2 , V_79 , V_13 ) ;
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
goto V_148;
}
if ( V_2 -> V_13 [ V_6 ] . V_5 ) {
if ( ! V_147 ) {
V_147 = true ;
F_18 ( V_2 , V_48 , V_2 ) ;
}
F_3 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
}
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_110 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_89 ,
V_13 [ V_6 ] . V_15 , V_146 ) ;
if ( F_4 ( V_5 ) ) {
F_7 ( 1 , L_43
L_44 , V_6 ) ;
F_5 ( V_2 , V_110 ) ;
V_37 = V_5 ? F_58 ( V_5 ) : - V_80 ;
goto V_148;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_147 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
F_19 ( V_2 , V_43 ) ;
goto V_148;
}
}
V_37 = F_18 ( V_2 , V_149 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_19 ( V_2 , V_149 ) ;
F_18 ( V_2 , V_48 , V_2 ) ;
goto V_148;
}
return 0 ;
V_148:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_89 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
}
return V_37 ;
}
static int F_59 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
int V_37 ;
F_56 ( V_2 , V_79 , V_2 -> V_14 ) ;
V_37 = F_18 ( V_2 , V_149 , V_2 ) ;
if ( V_37 )
F_19 ( V_2 , V_149 ) ;
return V_37 ;
}
static int F_60 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_32 V_13 [ V_81 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_146 = ! F_27 ( V_4 -> type ) ;
bool V_147 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
F_56 ( V_2 , V_79 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_150 * V_26 = F_61 ( V_13 [ V_6 ] . V_33 . V_90 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_47 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_148;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_13 [ V_6 ] . V_84 +
V_4 -> V_9 [ V_6 ] ) {
F_7 ( 1 , L_48 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_148;
}
if ( V_26 == V_2 -> V_13 [ V_6 ] . V_26 &&
V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 ) {
F_10 ( V_26 ) ;
continue;
}
F_7 ( 1 , L_49 , V_6 ) ;
if ( ! V_147 ) {
V_147 = true ;
F_18 ( V_2 , V_48 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_114 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_146 ) ;
if ( F_62 ( V_5 ) ) {
F_7 ( 1 , L_50 ) ;
F_5 ( V_2 , V_114 ) ;
V_37 = F_58 ( V_5 ) ;
F_10 ( V_26 ) ;
goto V_148;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_3 ( V_2 , V_115 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_7 ( 1 , L_51 ,
V_6 ) ;
F_5 ( V_2 , V_115 ) ;
goto V_148;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_147 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
F_19 ( V_2 , V_43 ) ;
goto V_148;
}
}
V_37 = F_18 ( V_2 , V_149 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_19 ( V_2 , V_149 ) ;
F_18 ( V_2 , V_48 , V_2 ) ;
goto V_148;
}
return 0 ;
V_148:
F_11 ( V_2 ) ;
return V_37 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_98 ;
F_64 ( & V_4 -> V_141 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_2 , V_151 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_18 ( V_2 , V_152 , V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_153 * V_154 ;
int V_37 ;
V_37 = F_26 ( V_2 , V_79 ) ;
if ( V_37 < 0 ) {
F_7 ( 1 , L_52 ,
V_129 , V_37 ) ;
return V_37 ;
}
V_2 -> V_40 = V_46 ;
V_2 -> V_18 . V_155 . V_156 = 0 ;
V_2 -> V_18 . V_155 . V_157 = 0 ;
V_2 -> V_18 . V_158 = 0 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_59 ( V_2 , V_79 ) ;
break;
case V_82 :
V_154 = & V_159 -> V_160 -> V_154 ;
F_41 ( V_4 , V_161 , V_4 ) ;
F_66 ( V_154 ) ;
F_41 ( V_4 , V_162 , V_4 ) ;
V_37 = F_57 ( V_2 , V_79 ) ;
F_67 ( V_154 ) ;
break;
case V_45 :
V_37 = F_60 ( V_2 , V_79 ) ;
break;
default:
F_68 ( 1 , L_53 ) ;
V_37 = - V_80 ;
}
if ( V_37 )
F_7 ( 1 , L_54 , V_37 ) ;
V_2 -> V_40 = V_37 ? V_41 : V_104 ;
return V_37 ;
}
static int F_69 ( struct V_3 * V_4 , struct V_78 * V_79 ,
const char * V_163 )
{
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_55 , V_163 ) ;
return - V_80 ;
}
if ( V_79 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_56 , V_163 ) ;
return - V_80 ;
}
if ( V_4 -> V_30 [ V_79 -> V_19 ] == NULL ) {
F_7 ( 1 , L_57 , V_163 ) ;
return - V_80 ;
}
if ( V_79 -> V_36 != V_4 -> V_36 ) {
F_7 ( 1 , L_58 , V_163 ) ;
return - V_80 ;
}
return F_25 ( V_4 -> V_30 [ V_79 -> V_19 ] , V_79 ) ;
}
int F_70 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_59 , V_129 ) ;
return - V_118 ;
}
V_37 = F_69 ( V_4 , V_79 , L_60 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
if ( V_2 -> V_40 != V_41 ) {
F_7 ( 1 , L_61 , V_129 ,
V_2 -> V_40 ) ;
return - V_80 ;
}
V_37 = F_65 ( V_2 , V_79 ) ;
if ( ! V_37 ) {
F_30 ( V_2 , V_79 ) ;
F_7 ( 1 , L_62 , V_129 , V_2 -> V_18 . V_19 ) ;
}
return V_37 ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_37 ;
F_72 (vb, &q->queued_list, queued_entry)
F_63 ( V_2 ) ;
V_37 = F_41 ( V_4 , V_164 , V_4 ,
F_73 ( & V_4 -> V_141 ) ) ;
V_4 -> V_136 = V_37 == 0 ;
if ( ! V_37 )
return 0 ;
F_42 ( V_4 , V_164 ) ;
F_7 ( 1 , L_63 ) ;
if ( F_50 ( F_73 ( & V_4 -> V_141 ) ) ) {
unsigned V_165 ;
for ( V_165 = 0 ; V_165 < V_4 -> V_29 ; ++ V_165 ) {
V_2 = V_4 -> V_30 [ V_165 ] ;
if ( V_2 -> V_40 == V_98 )
F_49 ( V_2 , V_97 ) ;
}
F_50 ( F_73 ( & V_4 -> V_141 ) ) ;
}
return V_37 ;
}
static int F_74 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_37 = F_69 ( V_4 , V_79 , L_64 ) ;
struct V_1 * V_2 ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_65 ( V_2 , V_79 ) ;
if ( V_37 )
return V_37 ;
break;
case V_104 :
break;
case V_46 :
F_7 ( 1 , L_65 ) ;
return - V_80 ;
default:
F_7 ( 1 , L_61 , V_129 ,
V_2 -> V_40 ) ;
return - V_80 ;
}
F_52 ( & V_2 -> V_166 , & V_4 -> V_77 ) ;
V_4 -> V_167 ++ ;
V_2 -> V_40 = V_97 ;
if ( F_27 ( V_4 -> type ) ) {
if ( ( V_4 -> V_93 & V_94 ) ==
V_95 )
V_2 -> V_18 . V_155 = V_79 -> V_155 ;
V_2 -> V_18 . V_91 |= V_79 -> V_91 & V_143 ;
if ( V_79 -> V_91 & V_143 )
V_2 -> V_18 . V_168 = V_79 -> V_168 ;
}
if ( V_4 -> V_136 )
F_63 ( V_2 ) ;
F_30 ( V_2 , V_79 ) ;
if ( V_4 -> V_122 && ! V_4 -> V_136 &&
V_4 -> V_167 >= V_4 -> V_125 ) {
V_37 = F_71 ( V_4 ) ;
if ( V_37 )
return V_37 ;
}
F_7 ( 1 , L_62 , V_129 , V_2 -> V_18 . V_19 ) ;
return 0 ;
}
int F_75 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_59 , V_129 ) ;
return - V_118 ;
}
return F_74 ( V_4 , V_79 ) ;
}
static int F_76 ( struct V_3 * V_4 , int V_169 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_122 ) {
F_7 ( 1 , L_66 ) ;
return - V_80 ;
}
if ( ! F_77 ( & V_4 -> V_140 ) ) {
break;
}
if ( V_169 ) {
F_7 ( 1 , L_67
L_68 ) ;
return - V_47 ;
}
F_41 ( V_4 , V_161 , V_4 ) ;
F_7 ( 3 , L_69 ) ;
V_37 = F_78 ( V_4 -> V_142 ,
! F_77 ( & V_4 -> V_140 ) || ! V_4 -> V_122 ) ;
F_41 ( V_4 , V_162 , V_4 ) ;
if ( V_37 ) {
F_7 ( 1 , L_70 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_79 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_78 * V_79 , int V_169 )
{
unsigned long V_91 ;
int V_37 ;
V_37 = F_76 ( V_4 , V_169 ) ;
if ( V_37 )
return V_37 ;
F_51 ( & V_4 -> V_138 , V_91 ) ;
* V_2 = F_80 ( & V_4 -> V_140 , struct V_1 , V_139 ) ;
V_37 = F_25 ( * V_2 , V_79 ) ;
if ( ! V_37 )
F_81 ( & ( * V_2 ) -> V_139 ) ;
F_54 ( & V_4 -> V_138 , V_91 ) ;
return V_37 ;
}
int F_82 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_122 ) {
F_7 ( 1 , L_66 ) ;
return - V_80 ;
}
if ( V_4 -> V_136 )
F_83 ( V_4 -> V_142 , ! F_73 ( & V_4 -> V_141 ) ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_165 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_165 = 0 ; V_165 < V_2 -> V_7 ; ++ V_165 ) {
if ( ! V_2 -> V_13 [ V_165 ] . V_23 )
continue;
F_3 ( V_2 , V_24 , V_2 -> V_13 [ V_165 ] . V_5 ) ;
V_2 -> V_13 [ V_165 ] . V_23 = 0 ;
}
}
static int F_85 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_169 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_71 ) ;
return - V_80 ;
}
V_37 = F_79 ( V_4 , & V_2 , V_79 , V_169 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_2 -> V_40 ) {
case V_102 :
F_7 ( 3 , L_72 ) ;
break;
case V_100 :
F_7 ( 3 , L_73 ) ;
break;
default:
F_7 ( 1 , L_74 ) ;
return - V_80 ;
}
F_18 ( V_2 , V_170 , V_2 ) ;
F_30 ( V_2 , V_79 ) ;
F_81 ( & V_2 -> V_166 ) ;
V_4 -> V_167 -- ;
F_84 ( V_2 ) ;
F_7 ( 1 , L_75 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
int F_86 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_169 )
{
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_76 ) ;
return - V_118 ;
}
return F_85 ( V_4 , V_79 , V_169 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
unsigned int V_165 ;
if ( V_4 -> V_136 )
F_41 ( V_4 , V_171 , V_4 ) ;
V_4 -> V_122 = 0 ;
V_4 -> V_136 = 0 ;
V_4 -> V_167 = 0 ;
if ( F_50 ( F_73 ( & V_4 -> V_141 ) ) ) {
for ( V_165 = 0 ; V_165 < V_4 -> V_29 ; ++ V_165 )
if ( V_4 -> V_30 [ V_165 ] -> V_40 == V_98 )
F_49 ( V_4 -> V_30 [ V_165 ] , V_100 ) ;
F_50 ( F_73 ( & V_4 -> V_141 ) ) ;
}
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_140 ) ;
F_87 ( & V_4 -> V_141 , 0 ) ;
F_88 ( & V_4 -> V_142 ) ;
for ( V_165 = 0 ; V_165 < V_4 -> V_29 ; ++ V_165 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_165 ] ;
if ( V_2 -> V_40 != V_41 ) {
V_2 -> V_40 = V_104 ;
F_18 ( V_2 , V_170 , V_2 ) ;
}
F_84 ( V_2 ) ;
}
}
static int F_89 ( struct V_3 * V_4 , enum V_116 type )
{
int V_37 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_77 ) ;
return - V_80 ;
}
if ( V_4 -> V_122 ) {
F_7 ( 3 , L_78 ) ;
return 0 ;
}
if ( ! V_4 -> V_29 ) {
F_7 ( 1 , L_79 ) ;
return - V_80 ;
}
if ( ! V_4 -> V_29 ) {
F_7 ( 1 , L_79 ) ;
return - V_80 ;
}
if ( V_4 -> V_29 < V_4 -> V_125 ) {
F_7 ( 1 , L_80 ,
V_4 -> V_125 ) ;
return - V_80 ;
}
if ( V_4 -> V_167 >= V_4 -> V_125 ) {
V_37 = F_71 ( V_4 ) ;
if ( V_37 ) {
F_38 ( V_4 ) ;
return V_37 ;
}
}
V_4 -> V_122 = 1 ;
F_7 ( 3 , L_81 ) ;
return 0 ;
}
int F_90 ( struct V_3 * V_4 , enum V_116 type )
{
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_82 ) ;
return - V_118 ;
}
return F_89 ( V_4 , type ) ;
}
static int F_91 ( struct V_3 * V_4 , enum V_116 type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_83 ) ;
return - V_80 ;
}
F_38 ( V_4 ) ;
F_7 ( 3 , L_84 ) ;
return 0 ;
}
int F_92 ( struct V_3 * V_4 , enum V_116 type )
{
if ( V_4 -> V_117 ) {
F_7 ( 1 , L_85 ) ;
return - V_118 ;
}
return F_91 ( V_4 , type ) ;
}
static int F_93 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_172 , unsigned int * V_173 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_31 ) {
* V_172 = V_28 ;
* V_173 = V_6 ;
return 0 ;
}
}
}
return - V_80 ;
}
int F_94 ( struct V_3 * V_4 , struct V_174 * V_175 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_176 ;
int V_37 ;
struct V_150 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_86 ) ;
return - V_80 ;
}
if ( ! V_4 -> V_109 -> V_177 ) {
F_7 ( 1 , L_87 ) ;
return - V_80 ;
}
if ( V_175 -> V_91 & ~ ( V_178 | V_179 ) ) {
F_7 ( 1 , L_88 ) ;
return - V_80 ;
}
if ( V_175 -> type != V_4 -> type ) {
F_7 ( 1 , L_89 ) ;
return - V_80 ;
}
if ( V_175 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_90 ) ;
return - V_80 ;
}
V_2 = V_4 -> V_30 [ V_175 -> V_19 ] ;
if ( V_175 -> V_6 >= V_2 -> V_7 ) {
F_7 ( 1 , L_91 ) ;
return - V_80 ;
}
V_176 = & V_2 -> V_13 [ V_175 -> V_6 ] ;
V_26 = F_3 ( V_2 , V_177 , V_176 -> V_5 , V_175 -> V_91 & V_179 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_92 ,
V_175 -> V_19 , V_175 -> V_6 ) ;
F_5 ( V_2 , V_177 ) ;
return - V_80 ;
}
V_37 = F_95 ( V_26 , V_175 -> V_91 & ~ V_179 ) ;
if ( V_37 < 0 ) {
F_7 ( 3 , L_93 ,
V_175 -> V_19 , V_175 -> V_6 , V_37 ) ;
F_10 ( V_26 ) ;
return V_37 ;
}
F_7 ( 3 , L_94 ,
V_175 -> V_19 , V_175 -> V_6 , V_37 ) ;
V_175 -> V_90 = V_37 ;
return 0 ;
}
int F_96 ( struct V_3 * V_4 , struct V_180 * V_181 )
{
unsigned long V_31 = V_181 -> V_182 << V_183 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_86 ) ;
return - V_80 ;
}
if ( ! ( V_181 -> V_184 & V_185 ) ) {
F_7 ( 1 , L_95 ) ;
return - V_80 ;
}
if ( F_27 ( V_4 -> type ) ) {
if ( ! ( V_181 -> V_184 & V_186 ) ) {
F_7 ( 1 , L_96 ) ;
return - V_80 ;
}
} else {
if ( ! ( V_181 -> V_184 & V_187 ) ) {
F_7 ( 1 , L_97 ) ;
return - V_80 ;
}
}
V_37 = F_93 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_181 -> V_188 - V_181 -> V_189 ) ) {
F_7 ( 1 ,
L_98 ) ;
return - V_80 ;
}
V_37 = F_3 ( V_2 , V_112 , V_2 -> V_13 [ V_6 ] . V_5 , V_181 ) ;
if ( V_37 ) {
F_5 ( V_2 , V_112 ) ;
return V_37 ;
}
F_7 ( 3 , L_99 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_97 ( struct V_3 * V_4 ,
unsigned long V_190 ,
unsigned long V_191 ,
unsigned long V_192 ,
unsigned long V_91 )
{
unsigned long V_31 = V_192 << V_183 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_86 ) ;
return - V_80 ;
}
V_37 = F_93 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
return ( unsigned long ) F_47 ( V_2 , V_6 ) ;
}
unsigned int F_98 ( struct V_3 * V_4 , struct V_193 * V_193 , T_1 * V_194 )
{
struct V_195 * V_196 = F_99 ( V_193 ) ;
unsigned long V_197 = F_100 ( V_194 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_198 = 0 ;
unsigned long V_91 ;
if ( F_101 ( V_199 , & V_196 -> V_91 ) ) {
struct V_200 * V_201 = V_193 -> V_202 ;
if ( F_102 ( V_201 ) )
V_198 = V_203 ;
else if ( V_197 & V_203 )
F_103 ( V_193 , & V_201 -> V_194 , V_194 ) ;
}
if ( ! F_27 ( V_4 -> type ) && ! ( V_197 & ( V_204 | V_205 ) ) )
return V_198 ;
if ( F_27 ( V_4 -> type ) && ! ( V_197 & ( V_206 | V_207 ) ) )
return V_198 ;
if ( V_4 -> V_29 == 0 && V_4 -> V_117 == NULL ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_208 ) &&
( V_197 & ( V_204 | V_205 ) ) ) {
if ( F_104 ( V_4 , 1 ) )
return V_198 | V_209 ;
}
if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_210 ) &&
( V_197 & ( V_206 | V_207 ) ) ) {
if ( F_104 ( V_4 , 0 ) )
return V_198 | V_209 ;
return V_198 | V_206 | V_207 ;
}
}
if ( F_77 ( & V_4 -> V_77 ) )
return V_198 | V_209 ;
if ( F_77 ( & V_4 -> V_140 ) )
F_103 ( V_193 , & V_4 -> V_142 , V_194 ) ;
F_51 ( & V_4 -> V_138 , V_91 ) ;
if ( ! F_77 ( & V_4 -> V_140 ) )
V_2 = F_80 ( & V_4 -> V_140 , struct V_1 ,
V_139 ) ;
F_54 ( & V_4 -> V_138 , V_91 ) ;
if ( V_2 && ( V_2 -> V_40 == V_102
|| V_2 -> V_40 == V_100 ) ) {
return ( F_27 ( V_4 -> type ) ) ?
V_198 | V_206 | V_207 :
V_198 | V_204 | V_205 ;
}
return V_198 ;
}
int F_105 ( struct V_3 * V_4 )
{
if ( F_50 ( ! V_4 ) ||
F_50 ( ! V_4 -> V_211 ) ||
F_50 ( ! V_4 -> V_109 ) ||
F_50 ( ! V_4 -> type ) ||
F_50 ( ! V_4 -> V_107 ) ||
F_50 ( ! V_4 -> V_211 -> V_124 ) ||
F_50 ( ! V_4 -> V_211 -> V_152 ) ||
F_50 ( V_4 -> V_93 &
~ ( V_94 |
V_96 ) ) )
return - V_80 ;
F_50 ( ( V_4 -> V_93 & V_94 ) ==
V_212 ) ;
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_140 ) ;
F_106 ( & V_4 -> V_138 ) ;
F_107 ( & V_4 -> V_142 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_108 ( struct V_3 * V_4 )
{
F_109 ( V_4 ) ;
F_38 ( V_4 ) ;
F_21 ( V_4 , V_4 -> V_29 ) ;
}
static int F_104 ( struct V_3 * V_4 , int V_213 )
{
struct V_214 * V_117 ;
int V_165 , V_37 ;
unsigned int V_123 = 0 ;
if ( F_50 ( ( V_213 && ! ( V_4 -> V_107 & V_208 ) ) ||
( ! V_213 && ! ( V_4 -> V_107 & V_210 ) ) ) )
return - V_80 ;
if ( ! V_4 -> V_109 -> V_133 )
return - V_118 ;
if ( V_4 -> V_122 || V_4 -> V_29 > 0 )
return - V_118 ;
V_123 = 1 ;
F_7 ( 3 , L_100 ,
( V_213 ) ? L_101 : L_102 , V_123 , V_4 -> V_215 ) ;
V_117 = F_15 ( sizeof( struct V_214 ) , V_39 ) ;
if ( V_117 == NULL )
return - V_17 ;
V_117 -> V_91 = V_4 -> V_215 ;
V_117 -> V_120 . V_123 = V_123 ;
V_117 -> V_120 . V_36 = V_42 ;
V_117 -> V_120 . type = V_4 -> type ;
V_37 = F_43 ( V_4 , & V_117 -> V_120 ) ;
if ( V_37 )
goto V_216;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_118 ;
goto V_217;
}
for ( V_165 = 0 ; V_165 < V_4 -> V_29 ; V_165 ++ ) {
V_117 -> V_30 [ V_165 ] . V_133 = F_47 ( V_4 -> V_30 [ V_165 ] , 0 ) ;
if ( V_117 -> V_30 [ V_165 ] . V_133 == NULL ) {
V_37 = - V_80 ;
goto V_217;
}
V_117 -> V_30 [ V_165 ] . V_8 = F_110 ( V_4 -> V_30 [ V_165 ] , 0 ) ;
}
if ( V_213 ) {
for ( V_165 = 0 ; V_165 < V_4 -> V_29 ; V_165 ++ ) {
struct V_78 * V_79 = & V_117 -> V_79 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_4 -> type ;
V_79 -> V_36 = V_4 -> V_36 ;
V_79 -> V_19 = V_165 ;
V_37 = F_75 ( V_4 , V_79 ) ;
if ( V_37 )
goto V_217;
V_117 -> V_30 [ V_165 ] . V_218 = 1 ;
}
V_117 -> V_219 = V_4 -> V_29 ;
V_117 -> V_220 = V_4 -> V_29 ;
}
V_37 = F_90 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_217;
V_4 -> V_117 = V_117 ;
return V_37 ;
V_217:
V_117 -> V_120 . V_123 = 0 ;
F_43 ( V_4 , & V_117 -> V_120 ) ;
V_216:
F_17 ( V_117 ) ;
return V_37 ;
}
static int F_109 ( struct V_3 * V_4 )
{
struct V_214 * V_117 = V_4 -> V_117 ;
if ( V_117 ) {
F_91 ( V_4 , V_4 -> type ) ;
V_4 -> V_117 = NULL ;
V_117 -> V_120 . V_123 = 0 ;
F_43 ( V_4 , & V_117 -> V_120 ) ;
F_17 ( V_117 ) ;
F_7 ( 3 , L_103 ) ;
}
return 0 ;
}
static T_2 F_111 ( struct V_3 * V_4 , char T_3 * V_221 , T_2 V_123 ,
T_4 * V_222 , int V_223 , int V_213 )
{
struct V_214 * V_117 ;
struct V_224 * V_225 ;
int V_37 , V_19 ;
F_7 ( 3 , L_104 ,
V_213 ? L_101 : L_102 , ( long ) * V_222 , V_123 ,
V_223 ? L_105 : L_12 ) ;
if ( ! V_221 )
return - V_80 ;
if ( ! V_4 -> V_117 ) {
V_37 = F_104 ( V_4 , V_213 ) ;
F_7 ( 3 , L_106 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_117 = V_4 -> V_117 ;
V_19 = V_117 -> V_220 ;
if ( V_19 >= V_4 -> V_29 ) {
memset ( & V_117 -> V_79 , 0 , sizeof( V_117 -> V_79 ) ) ;
V_117 -> V_79 . type = V_4 -> type ;
V_117 -> V_79 . V_36 = V_4 -> V_36 ;
V_37 = F_85 ( V_4 , & V_117 -> V_79 , V_223 ) ;
F_7 ( 5 , L_107 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_117 -> V_226 += 1 ;
V_117 -> V_220 = V_19 = V_117 -> V_79 . V_19 ;
V_225 = & V_117 -> V_30 [ V_19 ] ;
V_225 -> V_227 = 0 ;
V_225 -> V_218 = 0 ;
V_225 -> V_8 = V_213 ? F_112 ( V_4 -> V_30 [ V_19 ] , 0 )
: F_110 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
} else {
V_225 = & V_117 -> V_30 [ V_19 ] ;
}
if ( V_225 -> V_227 + V_123 > V_225 -> V_8 ) {
V_123 = V_225 -> V_8 - V_225 -> V_227 ;
F_7 ( 5 , L_108 , V_123 ) ;
}
F_7 ( 3 , L_109 ,
V_123 , V_19 , V_225 -> V_227 ) ;
if ( V_213 )
V_37 = F_113 ( V_221 , V_225 -> V_133 + V_225 -> V_227 , V_123 ) ;
else
V_37 = F_114 ( V_225 -> V_133 + V_225 -> V_227 , V_221 , V_123 ) ;
if ( V_37 ) {
F_7 ( 3 , L_110 ) ;
return - V_228 ;
}
V_225 -> V_227 += V_123 ;
* V_222 += V_123 ;
if ( V_225 -> V_227 == V_225 -> V_8 ||
( ! V_213 && ( V_117 -> V_91 & V_229 ) ) ) {
if ( V_213 && ( V_117 -> V_91 & V_230 ) &&
V_117 -> V_226 == 1 ) {
F_7 ( 3 , L_111 ) ;
return F_109 ( V_4 ) ;
}
memset ( & V_117 -> V_79 , 0 , sizeof( V_117 -> V_79 ) ) ;
V_117 -> V_79 . type = V_4 -> type ;
V_117 -> V_79 . V_36 = V_4 -> V_36 ;
V_117 -> V_79 . V_19 = V_19 ;
V_117 -> V_79 . V_83 = V_225 -> V_227 ;
V_37 = F_74 ( V_4 , & V_117 -> V_79 ) ;
F_7 ( 5 , L_112 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_225 -> V_227 = 0 ;
V_225 -> V_218 = 1 ;
V_225 -> V_8 = F_110 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
V_117 -> V_231 += 1 ;
if ( V_117 -> V_219 < V_4 -> V_29 )
V_117 -> V_219 ++ ;
V_117 -> V_220 = V_117 -> V_219 ;
}
if ( V_37 == 0 )
V_37 = V_123 ;
return V_37 ;
}
T_2 F_115 ( struct V_3 * V_4 , char T_3 * V_221 , T_2 V_123 ,
T_4 * V_222 , int V_169 )
{
return F_111 ( V_4 , V_221 , V_123 , V_222 , V_169 , 1 ) ;
}
T_2 F_116 ( struct V_3 * V_4 , const char T_3 * V_221 , T_2 V_123 ,
T_4 * V_222 , int V_169 )
{
return F_111 ( V_4 , ( char T_3 * ) V_221 , V_123 ,
V_222 , V_169 , 0 ) ;
}
static inline bool F_117 ( struct V_195 * V_232 , struct V_193 * V_193 )
{
return V_232 -> V_233 -> V_234 && V_232 -> V_233 -> V_234 != V_193 -> V_202 ;
}
int F_118 ( struct V_193 * V_193 , void * V_235 ,
struct V_119 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
int V_198 = F_36 ( V_232 -> V_233 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_198 )
return V_198 ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
V_198 = F_37 ( V_232 -> V_233 , V_22 ) ;
if ( V_198 == 0 )
V_232 -> V_233 -> V_234 = V_22 -> V_123 ? V_193 -> V_202 : NULL ;
return V_198 ;
}
int F_119 ( struct V_193 * V_193 , void * V_235 ,
struct V_126 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
int V_198 = F_36 ( V_232 -> V_233 , V_22 -> V_36 , V_22 -> V_131 . type ) ;
V_22 -> V_19 = V_232 -> V_233 -> V_29 ;
if ( V_22 -> V_123 == 0 )
return V_198 != - V_118 ? V_198 : 0 ;
if ( V_198 )
return V_198 ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
V_198 = F_44 ( V_232 -> V_233 , V_22 ) ;
if ( V_198 == 0 )
V_232 -> V_233 -> V_234 = V_193 -> V_202 ;
return V_198 ;
}
int F_120 ( struct V_193 * V_193 , void * V_235 ,
struct V_78 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_70 ( V_232 -> V_233 , V_22 ) ;
}
int F_121 ( struct V_193 * V_193 , void * V_235 , struct V_78 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
return F_32 ( V_232 -> V_233 , V_22 ) ;
}
int F_122 ( struct V_193 * V_193 , void * V_235 , struct V_78 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_75 ( V_232 -> V_233 , V_22 ) ;
}
int F_123 ( struct V_193 * V_193 , void * V_235 , struct V_78 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_86 ( V_232 -> V_233 , V_22 , V_193 -> V_236 & V_237 ) ;
}
int F_124 ( struct V_193 * V_193 , void * V_235 , enum V_116 V_165 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_90 ( V_232 -> V_233 , V_165 ) ;
}
int F_125 ( struct V_193 * V_193 , void * V_235 , enum V_116 V_165 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_92 ( V_232 -> V_233 , V_165 ) ;
}
int F_126 ( struct V_193 * V_193 , void * V_235 , struct V_174 * V_22 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( F_117 ( V_232 , V_193 ) )
return - V_118 ;
return F_94 ( V_232 -> V_233 , V_22 ) ;
}
int F_127 ( struct V_193 * V_193 , struct V_180 * V_181 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_238 * V_239 = V_232 -> V_233 -> V_239 ? V_232 -> V_233 -> V_239 : V_232 -> V_239 ;
int V_148 ;
if ( V_239 && F_128 ( V_239 ) )
return - V_240 ;
V_148 = F_96 ( V_232 -> V_233 , V_181 ) ;
if ( V_239 )
F_129 ( V_239 ) ;
return V_148 ;
}
int F_130 ( struct V_193 * V_193 , struct V_238 * V_239 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
if ( V_193 -> V_202 == V_232 -> V_233 -> V_234 ) {
if ( V_239 )
F_131 ( V_239 ) ;
F_108 ( V_232 -> V_233 ) ;
V_232 -> V_233 -> V_234 = NULL ;
if ( V_239 )
F_129 ( V_239 ) ;
}
return F_132 ( V_193 ) ;
}
int F_133 ( struct V_193 * V_193 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_238 * V_239 = V_232 -> V_233 -> V_239 ? V_232 -> V_233 -> V_239 : V_232 -> V_239 ;
return F_130 ( V_193 , V_239 ) ;
}
T_5 F_134 ( struct V_193 * V_193 , const char T_3 * V_225 ,
T_2 V_123 , T_4 * V_222 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_238 * V_239 = V_232 -> V_233 -> V_239 ? V_232 -> V_233 -> V_239 : V_232 -> V_239 ;
int V_148 = - V_118 ;
if ( V_239 && F_128 ( V_239 ) )
return - V_240 ;
if ( F_117 ( V_232 , V_193 ) )
goto exit;
V_148 = F_116 ( V_232 -> V_233 , V_225 , V_123 , V_222 ,
V_193 -> V_236 & V_237 ) ;
if ( V_232 -> V_233 -> V_117 )
V_232 -> V_233 -> V_234 = V_193 -> V_202 ;
exit:
if ( V_239 )
F_129 ( V_239 ) ;
return V_148 ;
}
T_5 F_135 ( struct V_193 * V_193 , char T_3 * V_225 ,
T_2 V_123 , T_4 * V_222 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_238 * V_239 = V_232 -> V_233 -> V_239 ? V_232 -> V_233 -> V_239 : V_232 -> V_239 ;
int V_148 = - V_118 ;
if ( V_239 && F_128 ( V_239 ) )
return - V_240 ;
if ( F_117 ( V_232 , V_193 ) )
goto exit;
V_148 = F_115 ( V_232 -> V_233 , V_225 , V_123 , V_222 ,
V_193 -> V_236 & V_237 ) ;
if ( V_232 -> V_233 -> V_117 )
V_232 -> V_233 -> V_234 = V_193 -> V_202 ;
exit:
if ( V_239 )
F_129 ( V_239 ) ;
return V_148 ;
}
unsigned int F_136 ( struct V_193 * V_193 , T_1 * V_194 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_3 * V_4 = V_232 -> V_233 ;
struct V_238 * V_239 = V_4 -> V_239 ? V_4 -> V_239 : V_232 -> V_239 ;
unsigned long V_197 = F_100 ( V_194 ) ;
unsigned V_198 ;
void * V_117 ;
bool V_241 = false ;
if ( V_4 -> V_29 == 0 && V_4 -> V_117 == NULL ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_208 ) &&
( V_197 & ( V_204 | V_205 ) ) )
V_241 = true ;
else if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_210 ) &&
( V_197 & ( V_206 | V_207 ) ) )
V_241 = true ;
}
F_50 ( V_241 && ! V_239 ) ;
if ( V_241 && V_239 && F_128 ( V_239 ) )
return V_209 ;
V_117 = V_4 -> V_117 ;
V_198 = F_98 ( V_232 -> V_233 , V_193 , V_194 ) ;
if ( V_241 && ! V_117 && V_4 -> V_117 )
V_4 -> V_234 = V_193 -> V_202 ;
if ( V_241 && V_239 )
F_129 ( V_239 ) ;
return V_198 ;
}
unsigned long F_137 ( struct V_193 * V_193 , unsigned long V_190 ,
unsigned long V_191 , unsigned long V_192 , unsigned long V_91 )
{
struct V_195 * V_232 = F_99 ( V_193 ) ;
struct V_238 * V_239 = V_232 -> V_233 -> V_239 ? V_232 -> V_233 -> V_239 : V_232 -> V_239 ;
int V_37 ;
if ( V_239 && F_128 ( V_239 ) )
return - V_240 ;
V_37 = F_97 ( V_232 -> V_233 , V_190 , V_191 , V_192 , V_91 ) ;
if ( V_239 )
F_129 ( V_239 ) ;
return V_37 ;
}
void F_138 ( struct V_3 * V_242 )
{
F_129 ( V_242 -> V_239 ) ;
}
void F_139 ( struct V_3 * V_242 )
{
F_131 ( V_242 -> V_239 ) ;
}
