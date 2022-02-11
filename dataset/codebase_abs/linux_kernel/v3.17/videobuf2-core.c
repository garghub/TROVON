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
unsigned int V_82 ;
unsigned int V_6 ;
if ( ! F_27 ( V_79 -> type ) )
return 0 ;
if ( F_16 ( V_79 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_15 = ( V_79 -> V_36 == V_83 ||
V_79 -> V_36 == V_45 )
? V_79 -> V_33 . V_13 [ V_6 ] . V_15
: V_2 -> V_14 [ V_6 ] . V_15 ;
V_82 = V_79 -> V_33 . V_13 [ V_6 ] . V_82
? V_79 -> V_33 . V_13 [ V_6 ] . V_82 : V_15 ;
if ( V_79 -> V_33 . V_13 [ V_6 ] . V_82 > V_15 )
return - V_80 ;
if ( V_79 -> V_33 . V_13 [ V_6 ] . V_84 > 0 &&
V_79 -> V_33 . V_13 [ V_6 ] . V_84 >= V_82 )
return - V_80 ;
}
} else {
V_15 = ( V_79 -> V_36 == V_83 )
? V_79 -> V_15 : V_2 -> V_14 [ 0 ] . V_15 ;
V_82 = V_79 -> V_82 ? V_79 -> V_82 : V_15 ;
if ( V_79 -> V_82 > V_15 )
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
V_79 -> V_82 = V_2 -> V_14 [ 0 ] . V_82 ;
if ( V_4 -> V_36 == V_42 )
V_79 -> V_33 . V_88 = V_2 -> V_14 [ 0 ] . V_33 . V_34 ;
else if ( V_4 -> V_36 == V_83 )
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
if ( V_36 != V_42 && V_36 != V_83 &&
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
if ( V_36 == V_83 && F_34 ( V_4 ) ) {
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
V_4 -> V_125 = ! F_27 ( V_4 -> type ) ;
return 0 ;
}
int F_44 ( struct V_3 * V_4 , struct V_118 * V_119 )
{
int V_37 = F_37 ( V_4 , V_119 -> V_36 , V_119 -> type ) ;
return V_37 ? V_37 : F_39 ( V_4 , V_119 ) ;
}
static int F_45 ( struct V_3 * V_4 , struct V_126 * V_127 )
{
unsigned int V_7 = 0 , V_29 , V_120 ;
int V_37 ;
if ( V_4 -> V_29 == V_128 ) {
F_7 ( 1 , L_37 ) ;
return - V_129 ;
}
if ( ! V_4 -> V_29 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_127 -> V_36 ;
V_4 -> V_125 = ! F_27 ( V_4 -> type ) ;
}
V_29 = F_46 ( V_127 -> V_122 , V_128 - V_4 -> V_29 ) ;
V_37 = F_43 ( V_4 , V_123 , V_4 , & V_127 -> V_130 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_120 = F_14 ( V_4 , V_127 -> V_36 , V_29 ,
V_7 ) ;
if ( V_120 == 0 ) {
F_7 ( 1 , L_36 ) ;
return - V_17 ;
}
if ( V_120 < V_29 ) {
V_29 = V_120 ;
V_37 = F_43 ( V_4 , V_123 , V_4 , & V_127 -> V_130 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_120 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 += V_120 ;
if ( V_37 < 0 ) {
F_20 ( V_4 , V_120 ) ;
return - V_17 ;
}
V_127 -> V_122 = V_120 ;
return 0 ;
}
int F_47 ( struct V_3 * V_4 , struct V_126 * V_127 )
{
int V_37 = F_37 ( V_4 , V_127 -> V_36 , V_127 -> V_130 . type ) ;
V_127 -> V_19 = V_4 -> V_29 ;
if ( V_127 -> V_122 == 0 )
return V_37 != - V_117 ? V_37 : 0 ;
return V_37 ? V_37 : F_45 ( V_4 , V_127 ) ;
}
void * F_48 ( struct V_1 * V_2 , unsigned int V_131 )
{
if ( V_131 > V_2 -> V_7 || ! V_2 -> V_13 [ V_131 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_132 , V_2 -> V_13 [ V_131 ] . V_5 ) ;
}
void * F_49 ( struct V_1 * V_2 , unsigned int V_131 )
{
if ( V_131 >= V_2 -> V_7 || ! V_2 -> V_13 [ V_131 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_133 , V_2 -> V_13 [ V_131 ] . V_5 ) ;
}
void F_50 ( struct V_1 * V_2 , enum V_134 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_91 ;
unsigned int V_6 ;
if ( F_51 ( V_2 -> V_40 != V_98 ) )
return;
if ( F_51 ( V_40 != V_102 &&
V_40 != V_100 &&
V_40 != V_97 ) )
V_40 = V_100 ;
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
if ( V_79 -> V_36 == V_83 ) {
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
if ( F_27 ( V_79 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_32 * V_141 = & V_14 [ V_6 ] ;
struct V_32 * V_142 = & V_79 -> V_33 . V_13 [ V_6 ] ;
V_141 -> V_82 = V_142 -> V_82 ?
V_142 -> V_82 : V_141 -> V_15 ;
V_141 -> V_84 = V_142 -> V_84 ;
}
}
} else {
if ( V_79 -> V_36 == V_83 ) {
V_14 [ 0 ] . V_33 . V_89 = V_79 -> V_33 . V_89 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
}
if ( V_79 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_90 = V_79 -> V_33 . V_90 ;
V_14 [ 0 ] . V_15 = V_79 -> V_15 ;
}
if ( F_27 ( V_79 -> type ) )
V_14 [ 0 ] . V_82 = V_79 -> V_82 ?
V_79 -> V_82 : V_14 [ 0 ] . V_15 ;
else
V_14 [ 0 ] . V_82 = 0 ;
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
static int F_60 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
F_59 ( V_2 , V_79 , V_2 -> V_14 ) ;
return F_18 ( V_2 , V_146 , V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_32 V_13 [ V_81 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_147 = ! F_27 ( V_4 -> type ) ;
bool V_148 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
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
goto V_149;
}
if ( V_2 -> V_13 [ V_6 ] . V_5 ) {
if ( ! V_148 ) {
V_148 = true ;
F_21 ( V_2 , V_48 , V_2 ) ;
}
F_5 ( V_2 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
}
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_110 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_89 ,
V_13 [ V_6 ] . V_15 , V_147 ) ;
if ( F_4 ( V_5 ) ) {
F_7 ( 1 , L_43
L_44 , V_6 ) ;
V_37 = V_5 ? F_62 ( V_5 ) : - V_80 ;
goto V_149;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_148 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
goto V_149;
}
}
V_37 = F_18 ( V_2 , V_146 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_21 ( V_2 , V_48 , V_2 ) ;
goto V_149;
}
return 0 ;
V_149:
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
int V_147 = ! F_27 ( V_4 -> type ) ;
bool V_148 = V_2 -> V_13 [ 0 ] . V_5 == NULL ;
memset ( V_13 , 0 , sizeof( V_13 [ 0 ] ) * V_2 -> V_7 ) ;
F_59 ( V_2 , V_79 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_150 * V_26 = F_64 ( V_13 [ V_6 ] . V_33 . V_90 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_47 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_149;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
F_7 ( 1 , L_48 ,
V_6 ) ;
V_37 = - V_80 ;
goto V_149;
}
if ( V_26 == V_2 -> V_13 [ V_6 ] . V_26 &&
V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 ) {
F_10 ( V_26 ) ;
continue;
}
F_7 ( 1 , L_49 , V_6 ) ;
if ( ! V_148 ) {
V_148 = true ;
F_21 ( V_2 , V_48 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_2 , V_114 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_147 ) ;
if ( F_65 ( V_5 ) ) {
F_7 ( 1 , L_50 ) ;
V_37 = F_62 ( V_5 ) ;
F_10 ( V_26 ) ;
goto V_149;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_29 ( V_2 , V_115 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_7 ( 1 , L_51 ,
V_6 ) ;
goto V_149;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
if ( V_148 ) {
V_37 = F_18 ( V_2 , V_43 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_45 ) ;
goto V_149;
}
}
V_37 = F_18 ( V_2 , V_146 , V_2 ) ;
if ( V_37 ) {
F_7 ( 1 , L_46 ) ;
F_21 ( V_2 , V_48 , V_2 ) ;
goto V_149;
}
return 0 ;
V_149:
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
F_5 ( V_2 , V_151 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_21 ( V_2 , V_152 , V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_153 * V_154 ;
int V_37 ;
V_37 = F_26 ( V_2 , V_79 ) ;
if ( V_37 < 0 ) {
F_7 ( 1 , L_52 , V_37 ) ;
return V_37 ;
}
if ( V_79 -> V_144 == V_155 && F_27 ( V_4 -> type ) ) {
F_7 ( 1 , L_53 ) ;
return - V_80 ;
}
if ( V_4 -> error ) {
F_7 ( 1 , L_54 ) ;
return - V_156 ;
}
V_2 -> V_40 = V_46 ;
V_2 -> V_18 . V_157 . V_158 = 0 ;
V_2 -> V_18 . V_157 . V_159 = 0 ;
V_2 -> V_18 . V_160 = 0 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_60 ( V_2 , V_79 ) ;
break;
case V_83 :
V_154 = & V_161 -> V_162 -> V_154 ;
F_69 ( V_4 , V_163 , V_4 ) ;
F_70 ( V_154 ) ;
F_69 ( V_4 , V_164 , V_4 ) ;
V_37 = F_61 ( V_2 , V_79 ) ;
F_71 ( V_154 ) ;
break;
case V_45 :
V_37 = F_63 ( V_2 , V_79 ) ;
break;
default:
F_72 ( 1 , L_55 ) ;
V_37 = - V_80 ;
}
if ( V_37 )
F_7 ( 1 , L_56 , V_37 ) ;
V_2 -> V_40 = V_37 ? V_41 : V_104 ;
return V_37 ;
}
static int F_73 ( struct V_3 * V_4 , struct V_78 * V_79 ,
const char * V_165 )
{
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_57 , V_165 ) ;
return - V_80 ;
}
if ( V_79 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_58 , V_165 ) ;
return - V_80 ;
}
if ( V_4 -> V_30 [ V_79 -> V_19 ] == NULL ) {
F_7 ( 1 , L_59 , V_165 ) ;
return - V_80 ;
}
if ( V_79 -> V_36 != V_4 -> V_36 ) {
F_7 ( 1 , L_60 , V_165 ) ;
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
V_37 = F_73 ( V_4 , V_79 , L_61 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_79 -> V_19 ] ;
if ( V_2 -> V_40 != V_41 ) {
F_7 ( 1 , L_62 ,
V_2 -> V_40 ) ;
return - V_80 ;
}
V_37 = F_68 ( V_2 , V_79 ) ;
if ( ! V_37 ) {
F_31 ( V_2 , V_79 ) ;
F_7 ( 1 , L_63 , V_2 -> V_18 . V_19 ) ;
}
return V_37 ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_37 ;
F_58 (vb, &q->queued_list, queued_entry)
F_66 ( V_2 ) ;
V_4 -> V_166 = 1 ;
V_37 = F_43 ( V_4 , V_167 , V_4 ,
F_76 ( & V_4 -> V_139 ) ) ;
if ( ! V_37 )
return 0 ;
V_4 -> V_166 = 0 ;
F_7 ( 1 , L_64 ) ;
if ( F_51 ( F_76 ( & V_4 -> V_139 ) ) ) {
unsigned V_168 ;
for ( V_168 = 0 ; V_168 < V_4 -> V_29 ; ++ V_168 ) {
V_2 = V_4 -> V_30 [ V_168 ] ;
if ( V_2 -> V_40 == V_98 )
F_50 ( V_2 , V_97 ) ;
}
F_51 ( F_76 ( & V_4 -> V_139 ) ) ;
}
F_51 ( ! F_77 ( & V_4 -> V_138 ) ) ;
return V_37 ;
}
static int F_78 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_37 = F_73 ( V_4 , V_79 , L_65 ) ;
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
F_7 ( 1 , L_66 ) ;
return - V_80 ;
default:
F_7 ( 1 , L_62 , V_2 -> V_40 ) ;
return - V_80 ;
}
F_53 ( & V_2 -> V_169 , & V_4 -> V_77 ) ;
V_4 -> V_170 ++ ;
V_4 -> V_125 = false ;
V_2 -> V_40 = V_97 ;
if ( F_27 ( V_4 -> type ) ) {
if ( ( V_4 -> V_93 & V_94 ) ==
V_95 )
V_2 -> V_18 . V_157 = V_79 -> V_157 ;
V_2 -> V_18 . V_91 |= V_79 -> V_91 & V_143 ;
if ( V_79 -> V_91 & V_143 )
V_2 -> V_18 . V_171 = V_79 -> V_171 ;
}
if ( V_4 -> V_166 )
F_66 ( V_2 ) ;
F_31 ( V_2 , V_79 ) ;
if ( V_4 -> V_121 && ! V_4 -> V_166 &&
V_4 -> V_170 >= V_4 -> V_124 ) {
V_37 = F_75 ( V_4 ) ;
if ( V_37 )
return V_37 ;
}
F_7 ( 1 , L_67 , V_2 -> V_18 . V_19 ) ;
return 0 ;
}
int F_79 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_78 ( V_4 , V_79 ) ;
}
static int F_80 ( struct V_3 * V_4 , int V_172 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_121 ) {
F_7 ( 1 , L_68 ) ;
return - V_80 ;
}
if ( V_4 -> error ) {
F_7 ( 1 , L_69 ) ;
return - V_156 ;
}
if ( ! F_77 ( & V_4 -> V_138 ) ) {
break;
}
if ( V_172 ) {
F_7 ( 1 , L_70
L_71 ) ;
return - V_47 ;
}
F_69 ( V_4 , V_163 , V_4 ) ;
F_7 ( 3 , L_72 ) ;
V_37 = F_81 ( V_4 -> V_140 ,
! F_77 ( & V_4 -> V_138 ) || ! V_4 -> V_121 ||
V_4 -> error ) ;
F_69 ( V_4 , V_164 , V_4 ) ;
if ( V_37 ) {
F_7 ( 1 , L_73 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_82 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_78 * V_79 , int V_172 )
{
unsigned long V_91 ;
int V_37 ;
V_37 = F_80 ( V_4 , V_172 ) ;
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
F_7 ( 1 , L_68 ) ;
return - V_80 ;
}
if ( V_4 -> V_166 )
F_86 ( V_4 -> V_140 , ! F_76 ( & V_4 -> V_139 ) ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_168 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_168 = 0 ; V_168 < V_2 -> V_7 ; ++ V_168 ) {
if ( ! V_2 -> V_13 [ V_168 ] . V_23 )
continue;
F_5 ( V_2 , V_24 , V_2 -> V_13 [ V_168 ] . V_5 ) ;
V_2 -> V_13 [ V_168 ] . V_23 = 0 ;
}
}
static int F_88 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_172 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_79 -> type != V_4 -> type ) {
F_7 ( 1 , L_74 ) ;
return - V_80 ;
}
V_37 = F_82 ( V_4 , & V_2 , V_79 , V_172 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_2 -> V_40 ) {
case V_102 :
F_7 ( 3 , L_75 ) ;
break;
case V_100 :
F_7 ( 3 , L_76 ) ;
break;
default:
F_7 ( 1 , L_77 ) ;
return - V_80 ;
}
F_21 ( V_2 , V_173 , V_2 ) ;
F_31 ( V_2 , V_79 ) ;
F_84 ( & V_2 -> V_169 ) ;
V_4 -> V_170 -- ;
F_87 ( V_2 ) ;
F_7 ( 1 , L_78 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
int F_89 ( struct V_3 * V_4 , struct V_78 * V_79 , bool V_172 )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_88 ( V_4 , V_79 , V_172 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_168 ;
if ( V_4 -> V_166 )
F_69 ( V_4 , V_174 , V_4 ) ;
if ( F_51 ( F_76 ( & V_4 -> V_139 ) ) ) {
for ( V_168 = 0 ; V_168 < V_4 -> V_29 ; ++ V_168 )
if ( V_4 -> V_30 [ V_168 ] -> V_40 == V_98 )
F_50 ( V_4 -> V_30 [ V_168 ] , V_100 ) ;
F_51 ( F_76 ( & V_4 -> V_139 ) ) ;
}
V_4 -> V_121 = 0 ;
V_4 -> V_166 = 0 ;
V_4 -> V_170 = 0 ;
V_4 -> error = 0 ;
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_138 ) ;
F_90 ( & V_4 -> V_139 , 0 ) ;
F_91 ( & V_4 -> V_140 ) ;
for ( V_168 = 0 ; V_168 < V_4 -> V_29 ; ++ V_168 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_168 ] ;
if ( V_2 -> V_40 != V_41 ) {
V_2 -> V_40 = V_104 ;
F_21 ( V_2 , V_173 , V_2 ) ;
}
F_87 ( V_2 ) ;
}
}
static int F_92 ( struct V_3 * V_4 , enum V_116 type )
{
int V_37 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_79 ) ;
return - V_80 ;
}
if ( V_4 -> V_121 ) {
F_7 ( 3 , L_80 ) ;
return 0 ;
}
if ( ! V_4 -> V_29 ) {
F_7 ( 1 , L_81 ) ;
return - V_80 ;
}
if ( V_4 -> V_29 < V_4 -> V_124 ) {
F_7 ( 1 , L_82 ,
V_4 -> V_124 ) ;
return - V_80 ;
}
if ( V_4 -> V_170 >= V_4 -> V_124 ) {
V_37 = F_75 ( V_4 ) ;
if ( V_37 ) {
F_40 ( V_4 ) ;
return V_37 ;
}
}
V_4 -> V_121 = 1 ;
F_7 ( 3 , L_83 ) ;
return 0 ;
}
void F_93 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_91 ( & V_4 -> V_140 ) ;
}
int F_94 ( struct V_3 * V_4 , enum V_116 type )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_92 ( V_4 , type ) ;
}
static int F_95 ( struct V_3 * V_4 , enum V_116 type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_79 ) ;
return - V_80 ;
}
F_40 ( V_4 ) ;
V_4 -> V_125 = ! F_27 ( V_4 -> type ) ;
F_7 ( 3 , L_83 ) ;
return 0 ;
}
int F_96 ( struct V_3 * V_4 , enum V_116 type )
{
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_33 ) ;
return - V_117 ;
}
return F_95 ( V_4 , type ) ;
}
static int F_97 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_175 , unsigned int * V_176 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_31 ) {
* V_175 = V_28 ;
* V_176 = V_6 ;
return 0 ;
}
}
}
return - V_80 ;
}
int F_98 ( struct V_3 * V_4 , struct V_177 * V_178 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_179 ;
int V_37 ;
struct V_150 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_84 ) ;
return - V_80 ;
}
if ( ! V_4 -> V_109 -> V_180 ) {
F_7 ( 1 , L_85 ) ;
return - V_80 ;
}
if ( V_178 -> V_91 & ~ ( V_181 | V_182 ) ) {
F_7 ( 1 , L_86 ) ;
return - V_80 ;
}
if ( V_178 -> type != V_4 -> type ) {
F_7 ( 1 , L_74 ) ;
return - V_80 ;
}
if ( V_178 -> V_19 >= V_4 -> V_29 ) {
F_7 ( 1 , L_27 ) ;
return - V_80 ;
}
V_2 = V_4 -> V_30 [ V_178 -> V_19 ] ;
if ( V_178 -> V_6 >= V_2 -> V_7 ) {
F_7 ( 1 , L_87 ) ;
return - V_80 ;
}
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_88 ) ;
return - V_117 ;
}
V_179 = & V_2 -> V_13 [ V_178 -> V_6 ] ;
V_26 = F_3 ( V_2 , V_180 , V_179 -> V_5 , V_178 -> V_91 & V_182 ) ;
if ( F_4 ( V_26 ) ) {
F_7 ( 1 , L_89 ,
V_178 -> V_19 , V_178 -> V_6 ) ;
return - V_80 ;
}
V_37 = F_99 ( V_26 , V_178 -> V_91 & ~ V_182 ) ;
if ( V_37 < 0 ) {
F_7 ( 3 , L_90 ,
V_178 -> V_19 , V_178 -> V_6 , V_37 ) ;
F_10 ( V_26 ) ;
return V_37 ;
}
F_7 ( 3 , L_91 ,
V_178 -> V_19 , V_178 -> V_6 , V_37 ) ;
V_178 -> V_90 = V_37 ;
return 0 ;
}
int F_100 ( struct V_3 * V_4 , struct V_183 * V_184 )
{
unsigned long V_31 = V_184 -> V_185 << V_186 ;
struct V_1 * V_2 ;
unsigned int V_28 = 0 , V_6 = 0 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_84 ) ;
return - V_80 ;
}
if ( ! ( V_184 -> V_187 & V_188 ) ) {
F_7 ( 1 , L_92 ) ;
return - V_80 ;
}
if ( F_27 ( V_4 -> type ) ) {
if ( ! ( V_184 -> V_187 & V_189 ) ) {
F_7 ( 1 , L_93 ) ;
return - V_80 ;
}
} else {
if ( ! ( V_184 -> V_187 & V_190 ) ) {
F_7 ( 1 , L_94 ) ;
return - V_80 ;
}
}
if ( F_38 ( V_4 ) ) {
F_7 ( 1 , L_95 ) ;
return - V_117 ;
}
V_37 = F_97 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_184 -> V_191 - V_184 -> V_192 ) ) {
F_7 ( 1 ,
L_96 ) ;
return - V_80 ;
}
V_37 = F_29 ( V_2 , V_112 , V_2 -> V_13 [ V_6 ] . V_5 , V_184 ) ;
if ( V_37 )
return V_37 ;
F_7 ( 3 , L_97 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_101 ( struct V_3 * V_4 ,
unsigned long V_193 ,
unsigned long V_194 ,
unsigned long V_195 ,
unsigned long V_91 )
{
unsigned long V_31 = V_195 << V_186 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_7 ( 1 , L_84 ) ;
return - V_80 ;
}
V_37 = F_97 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
return ( unsigned long ) F_48 ( V_2 , V_6 ) ;
}
unsigned int F_102 ( struct V_3 * V_4 , struct V_196 * V_196 , T_1 * V_197 )
{
struct V_198 * V_199 = F_103 ( V_196 ) ;
unsigned long V_200 = F_104 ( V_197 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_201 = 0 ;
unsigned long V_91 ;
if ( F_105 ( V_202 , & V_199 -> V_91 ) ) {
struct V_203 * V_204 = V_196 -> V_205 ;
if ( F_106 ( V_204 ) )
V_201 = V_206 ;
else if ( V_200 & V_206 )
F_107 ( V_196 , & V_204 -> V_197 , V_197 ) ;
}
if ( ! F_27 ( V_4 -> type ) && ! ( V_200 & ( V_207 | V_208 ) ) )
return V_201 ;
if ( F_27 ( V_4 -> type ) && ! ( V_200 & ( V_209 | V_210 ) ) )
return V_201 ;
if ( V_4 -> V_29 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_211 ) &&
( V_200 & ( V_207 | V_208 ) ) ) {
if ( F_108 ( V_4 , 1 ) )
return V_201 | V_212 ;
}
if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_213 ) &&
( V_200 & ( V_209 | V_210 ) ) ) {
if ( F_108 ( V_4 , 0 ) )
return V_201 | V_212 ;
return V_201 | V_209 | V_210 ;
}
}
if ( ! F_109 ( V_4 ) || V_4 -> error )
return V_201 | V_212 ;
if ( V_4 -> V_125 )
return V_201 | V_212 ;
if ( F_27 ( V_4 -> type ) && V_4 -> V_170 < V_4 -> V_29 )
return V_201 | V_209 | V_210 ;
if ( F_77 ( & V_4 -> V_138 ) )
F_107 ( V_196 , & V_4 -> V_140 , V_197 ) ;
F_52 ( & V_4 -> V_136 , V_91 ) ;
if ( ! F_77 ( & V_4 -> V_138 ) )
V_2 = F_83 ( & V_4 -> V_138 , struct V_1 ,
V_137 ) ;
F_55 ( & V_4 -> V_136 , V_91 ) ;
if ( V_2 && ( V_2 -> V_40 == V_102
|| V_2 -> V_40 == V_100 ) ) {
return ( F_27 ( V_4 -> type ) ) ?
V_201 | V_209 | V_210 :
V_201 | V_207 | V_208 ;
}
return V_201 ;
}
int F_110 ( struct V_3 * V_4 )
{
if ( F_51 ( ! V_4 ) ||
F_51 ( ! V_4 -> V_214 ) ||
F_51 ( ! V_4 -> V_109 ) ||
F_51 ( ! V_4 -> type ) ||
F_51 ( ! V_4 -> V_107 ) ||
F_51 ( ! V_4 -> V_214 -> V_123 ) ||
F_51 ( ! V_4 -> V_214 -> V_152 ) ||
F_51 ( V_4 -> V_93 &
~ ( V_94 |
V_96 ) ) )
return - V_80 ;
F_51 ( ( V_4 -> V_93 & V_94 ) ==
V_215 ) ;
F_24 ( & V_4 -> V_77 ) ;
F_24 ( & V_4 -> V_138 ) ;
F_111 ( & V_4 -> V_136 ) ;
F_112 ( & V_4 -> V_140 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_113 ( struct V_3 * V_4 )
{
F_114 ( V_4 ) ;
F_40 ( V_4 ) ;
F_20 ( V_4 , V_4 -> V_29 ) ;
}
static int F_108 ( struct V_3 * V_4 , int V_216 )
{
struct V_217 * V_218 ;
int V_168 , V_37 ;
unsigned int V_122 = 0 ;
if ( F_51 ( ( V_216 && ! ( V_4 -> V_107 & V_211 ) ) ||
( ! V_216 && ! ( V_4 -> V_107 & V_213 ) ) ) )
return - V_80 ;
if ( ! V_4 -> V_109 -> V_132 )
return - V_117 ;
if ( V_4 -> V_121 || V_4 -> V_29 > 0 )
return - V_117 ;
V_122 = 1 ;
F_7 ( 3 , L_98 ,
( V_216 ) ? L_99 : L_100 , V_122 , V_4 -> V_219 ) ;
V_218 = F_15 ( sizeof( struct V_217 ) , V_39 ) ;
if ( V_218 == NULL )
return - V_17 ;
V_218 -> V_91 = V_4 -> V_219 ;
V_218 -> V_119 . V_122 = V_122 ;
V_218 -> V_119 . V_36 = V_42 ;
V_218 -> V_119 . type = V_4 -> type ;
V_4 -> V_218 = V_218 ;
V_37 = F_39 ( V_4 , & V_218 -> V_119 ) ;
if ( V_37 )
goto V_220;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_117 ;
goto V_221;
}
for ( V_168 = 0 ; V_168 < V_4 -> V_29 ; V_168 ++ ) {
V_218 -> V_30 [ V_168 ] . V_132 = F_48 ( V_4 -> V_30 [ V_168 ] , 0 ) ;
if ( V_218 -> V_30 [ V_168 ] . V_132 == NULL ) {
V_37 = - V_80 ;
goto V_221;
}
V_218 -> V_30 [ V_168 ] . V_8 = F_115 ( V_4 -> V_30 [ V_168 ] , 0 ) ;
}
if ( V_216 ) {
bool V_222 = F_16 ( V_4 -> type ) ;
for ( V_168 = 0 ; V_168 < V_4 -> V_29 ; V_168 ++ ) {
struct V_78 * V_79 = & V_218 -> V_79 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> type = V_4 -> type ;
if ( V_222 ) {
memset ( & V_218 -> V_22 , 0 , sizeof( V_218 -> V_22 ) ) ;
V_79 -> V_33 . V_13 = & V_218 -> V_22 ;
V_79 -> V_15 = 1 ;
}
V_79 -> V_36 = V_4 -> V_36 ;
V_79 -> V_19 = V_168 ;
V_37 = F_78 ( V_4 , V_79 ) ;
if ( V_37 )
goto V_221;
V_218 -> V_30 [ V_168 ] . V_223 = 1 ;
}
V_218 -> V_224 = V_4 -> V_29 ;
V_218 -> V_225 = V_4 -> V_29 ;
}
V_37 = F_92 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_221;
return V_37 ;
V_221:
V_218 -> V_119 . V_122 = 0 ;
F_39 ( V_4 , & V_218 -> V_119 ) ;
V_220:
V_4 -> V_218 = NULL ;
F_17 ( V_218 ) ;
return V_37 ;
}
static int F_114 ( struct V_3 * V_4 )
{
struct V_217 * V_218 = V_4 -> V_218 ;
if ( V_218 ) {
F_95 ( V_4 , V_4 -> type ) ;
V_4 -> V_218 = NULL ;
V_218 -> V_119 . V_122 = 0 ;
F_44 ( V_4 , & V_218 -> V_119 ) ;
F_17 ( V_218 ) ;
F_7 ( 3 , L_101 ) ;
}
return 0 ;
}
static T_2 F_116 ( struct V_3 * V_4 , char T_3 * V_226 , T_2 V_122 ,
T_4 * V_227 , int V_228 , int V_216 )
{
struct V_217 * V_218 ;
struct V_229 * V_230 ;
bool V_222 = F_16 ( V_4 -> type ) ;
bool V_231 = ! V_216 &&
( V_4 -> V_93 & V_94 ) ==
V_95 ;
int V_37 , V_19 ;
F_7 ( 3 , L_102 ,
V_216 ? L_99 : L_100 , ( long ) * V_227 , V_122 ,
V_228 ? L_103 : L_12 ) ;
if ( ! V_226 )
return - V_80 ;
if ( ! F_38 ( V_4 ) ) {
V_37 = F_108 ( V_4 , V_216 ) ;
F_7 ( 3 , L_104 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_218 = V_4 -> V_218 ;
V_19 = V_218 -> V_225 ;
if ( V_19 >= V_4 -> V_29 ) {
memset ( & V_218 -> V_79 , 0 , sizeof( V_218 -> V_79 ) ) ;
V_218 -> V_79 . type = V_4 -> type ;
V_218 -> V_79 . V_36 = V_4 -> V_36 ;
if ( V_222 ) {
memset ( & V_218 -> V_22 , 0 , sizeof( V_218 -> V_22 ) ) ;
V_218 -> V_79 . V_33 . V_13 = & V_218 -> V_22 ;
V_218 -> V_79 . V_15 = 1 ;
}
V_37 = F_88 ( V_4 , & V_218 -> V_79 , V_228 ) ;
F_7 ( 5 , L_105 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_218 -> V_232 += 1 ;
V_218 -> V_225 = V_19 = V_218 -> V_79 . V_19 ;
V_230 = & V_218 -> V_30 [ V_19 ] ;
V_230 -> V_233 = 0 ;
V_230 -> V_223 = 0 ;
V_230 -> V_8 = V_216 ? F_117 ( V_4 -> V_30 [ V_19 ] , 0 )
: F_115 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
} else {
V_230 = & V_218 -> V_30 [ V_19 ] ;
}
if ( V_230 -> V_233 + V_122 > V_230 -> V_8 ) {
V_122 = V_230 -> V_8 - V_230 -> V_233 ;
F_7 ( 5 , L_106 , V_122 ) ;
}
F_7 ( 3 , L_107 ,
V_122 , V_19 , V_230 -> V_233 ) ;
if ( V_216 )
V_37 = F_118 ( V_226 , V_230 -> V_132 + V_230 -> V_233 , V_122 ) ;
else
V_37 = F_119 ( V_230 -> V_132 + V_230 -> V_233 , V_226 , V_122 ) ;
if ( V_37 ) {
F_7 ( 3 , L_108 ) ;
return - V_234 ;
}
V_230 -> V_233 += V_122 ;
* V_227 += V_122 ;
if ( V_230 -> V_233 == V_230 -> V_8 ||
( ! V_216 && ( V_218 -> V_91 & V_235 ) ) ) {
if ( V_216 && ( V_218 -> V_91 & V_236 ) &&
V_218 -> V_232 == 1 ) {
F_7 ( 3 , L_109 ) ;
return F_114 ( V_4 ) ;
}
memset ( & V_218 -> V_79 , 0 , sizeof( V_218 -> V_79 ) ) ;
V_218 -> V_79 . type = V_4 -> type ;
V_218 -> V_79 . V_36 = V_4 -> V_36 ;
V_218 -> V_79 . V_19 = V_19 ;
V_218 -> V_79 . V_82 = V_230 -> V_233 ;
if ( V_222 ) {
memset ( & V_218 -> V_22 , 0 , sizeof( V_218 -> V_22 ) ) ;
V_218 -> V_22 . V_82 = V_230 -> V_233 ;
V_218 -> V_79 . V_33 . V_13 = & V_218 -> V_22 ;
V_218 -> V_79 . V_15 = 1 ;
}
if ( V_231 )
F_120 ( & V_218 -> V_79 . V_157 ) ;
V_37 = F_78 ( V_4 , & V_218 -> V_79 ) ;
F_7 ( 5 , L_110 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_230 -> V_233 = 0 ;
V_230 -> V_223 = 1 ;
V_230 -> V_8 = F_115 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
V_218 -> V_237 += 1 ;
if ( V_218 -> V_224 < V_4 -> V_29 )
V_218 -> V_224 ++ ;
V_218 -> V_225 = V_218 -> V_224 ;
}
if ( V_37 == 0 )
V_37 = V_122 ;
return V_37 ;
}
T_2 F_121 ( struct V_3 * V_4 , char T_3 * V_226 , T_2 V_122 ,
T_4 * V_227 , int V_172 )
{
return F_116 ( V_4 , V_226 , V_122 , V_227 , V_172 , 1 ) ;
}
T_2 F_122 ( struct V_3 * V_4 , const char T_3 * V_226 , T_2 V_122 ,
T_4 * V_227 , int V_172 )
{
return F_116 ( V_4 , ( char T_3 * ) V_226 , V_122 ,
V_227 , V_172 , 0 ) ;
}
static int F_123 ( void * V_226 )
{
struct V_3 * V_4 = V_226 ;
struct V_238 * V_239 = V_4 -> V_239 ;
struct V_217 * V_218 = V_4 -> V_218 ;
bool V_231 = false ;
int V_240 = 0 ;
int V_19 = 0 ;
int V_37 = 0 ;
if ( F_27 ( V_4 -> type ) ) {
V_240 = V_4 -> V_29 ;
V_231 =
( V_4 -> V_93 & V_94 ) ==
V_95 ;
}
F_124 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_218 -> V_79 , 0 , sizeof( V_218 -> V_79 ) ) ;
V_218 -> V_79 . type = V_4 -> type ;
V_218 -> V_79 . V_36 = V_4 -> V_36 ;
if ( V_240 ) {
V_218 -> V_79 . V_19 = V_19 ++ ;
V_240 -- ;
} else {
F_69 ( V_4 , V_164 , V_4 ) ;
V_37 = F_88 ( V_4 , & V_218 -> V_79 , 0 ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
F_7 ( 5 , L_111 , V_37 ) ;
}
if ( V_239 -> V_241 )
break;
if ( V_37 )
break;
F_125 () ;
V_2 = V_4 -> V_30 [ V_218 -> V_79 . V_19 ] ;
if ( ! ( V_218 -> V_79 . V_91 & V_101 ) )
V_37 = V_239 -> V_242 ( V_2 , V_239 -> V_243 ) ;
if ( V_37 )
break;
F_69 ( V_4 , V_164 , V_4 ) ;
if ( V_231 )
F_120 ( & V_218 -> V_79 . V_157 ) ;
V_37 = F_78 ( V_4 , & V_218 -> V_79 ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
if ( V_37 )
break;
}
while ( ! F_126 () ) {
F_127 ( V_244 ) ;
F_128 () ;
}
return 0 ;
}
int F_129 ( struct V_3 * V_4 , T_5 V_242 , void * V_243 ,
const char * V_245 )
{
struct V_238 * V_239 ;
int V_37 = 0 ;
if ( V_4 -> V_239 )
return - V_117 ;
if ( F_130 ( V_4 ) )
return - V_117 ;
if ( F_51 ( V_4 -> V_218 ) )
return - V_117 ;
V_239 = F_15 ( sizeof( * V_239 ) , V_39 ) ;
if ( V_239 == NULL )
return - V_17 ;
V_239 -> V_242 = V_242 ;
V_239 -> V_243 = V_243 ;
V_37 = F_108 ( V_4 , ! F_27 ( V_4 -> type ) ) ;
F_7 ( 3 , L_112 , V_37 ) ;
if ( V_37 )
goto V_246;
V_4 -> V_239 = V_239 ;
V_239 -> V_247 = F_131 ( F_123 , V_4 , L_113 , V_245 ) ;
if ( F_65 ( V_239 -> V_247 ) ) {
V_37 = F_62 ( V_239 -> V_247 ) ;
V_239 -> V_247 = NULL ;
goto V_248;
}
return 0 ;
V_248:
F_114 ( V_4 ) ;
V_246:
F_17 ( V_239 ) ;
return V_37 ;
}
int F_132 ( struct V_3 * V_4 )
{
struct V_238 * V_239 = V_4 -> V_239 ;
struct V_217 * V_218 = V_4 -> V_218 ;
int V_149 ;
if ( V_239 == NULL )
return 0 ;
F_69 ( V_4 , V_164 , V_4 ) ;
V_239 -> V_241 = true ;
F_95 ( V_4 , V_4 -> type ) ;
F_69 ( V_4 , V_163 , V_4 ) ;
V_4 -> V_218 = NULL ;
V_218 -> V_119 . V_122 = 0 ;
F_44 ( V_4 , & V_218 -> V_119 ) ;
F_17 ( V_218 ) ;
V_149 = F_133 ( V_239 -> V_247 ) ;
V_239 -> V_247 = NULL ;
F_17 ( V_239 ) ;
V_4 -> V_218 = NULL ;
V_4 -> V_239 = NULL ;
return V_149 ;
}
static inline bool F_134 ( struct V_198 * V_249 , struct V_196 * V_196 )
{
return V_249 -> V_250 -> V_251 && V_249 -> V_250 -> V_251 != V_196 -> V_205 ;
}
int F_135 ( struct V_196 * V_196 , void * V_243 ,
struct V_118 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
int V_201 = F_37 ( V_249 -> V_250 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_201 )
return V_201 ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
V_201 = F_39 ( V_249 -> V_250 , V_22 ) ;
if ( V_201 == 0 )
V_249 -> V_250 -> V_251 = V_22 -> V_122 ? V_196 -> V_205 : NULL ;
return V_201 ;
}
int F_136 ( struct V_196 * V_196 , void * V_243 ,
struct V_126 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
int V_201 = F_37 ( V_249 -> V_250 , V_22 -> V_36 , V_22 -> V_130 . type ) ;
V_22 -> V_19 = V_249 -> V_250 -> V_29 ;
if ( V_22 -> V_122 == 0 )
return V_201 != - V_117 ? V_201 : 0 ;
if ( V_201 )
return V_201 ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
V_201 = F_45 ( V_249 -> V_250 , V_22 ) ;
if ( V_201 == 0 )
V_249 -> V_250 -> V_251 = V_196 -> V_205 ;
return V_201 ;
}
int F_137 ( struct V_196 * V_196 , void * V_243 ,
struct V_78 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_74 ( V_249 -> V_250 , V_22 ) ;
}
int F_138 ( struct V_196 * V_196 , void * V_243 , struct V_78 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
return F_33 ( V_249 -> V_250 , V_22 ) ;
}
int F_139 ( struct V_196 * V_196 , void * V_243 , struct V_78 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_79 ( V_249 -> V_250 , V_22 ) ;
}
int F_140 ( struct V_196 * V_196 , void * V_243 , struct V_78 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_89 ( V_249 -> V_250 , V_22 , V_196 -> V_252 & V_253 ) ;
}
int F_141 ( struct V_196 * V_196 , void * V_243 , enum V_116 V_168 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_94 ( V_249 -> V_250 , V_168 ) ;
}
int F_142 ( struct V_196 * V_196 , void * V_243 , enum V_116 V_168 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_96 ( V_249 -> V_250 , V_168 ) ;
}
int F_143 ( struct V_196 * V_196 , void * V_243 , struct V_177 * V_22 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( F_134 ( V_249 , V_196 ) )
return - V_117 ;
return F_98 ( V_249 -> V_250 , V_22 ) ;
}
int F_144 ( struct V_196 * V_196 , struct V_183 * V_184 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_254 * V_255 = V_249 -> V_250 -> V_255 ? V_249 -> V_250 -> V_255 : V_249 -> V_255 ;
int V_149 ;
if ( V_255 && F_145 ( V_255 ) )
return - V_256 ;
V_149 = F_100 ( V_249 -> V_250 , V_184 ) ;
if ( V_255 )
F_146 ( V_255 ) ;
return V_149 ;
}
int F_147 ( struct V_196 * V_196 , struct V_254 * V_255 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
if ( V_196 -> V_205 == V_249 -> V_250 -> V_251 ) {
if ( V_255 )
F_148 ( V_255 ) ;
F_113 ( V_249 -> V_250 ) ;
V_249 -> V_250 -> V_251 = NULL ;
if ( V_255 )
F_146 ( V_255 ) ;
}
return F_149 ( V_196 ) ;
}
int F_150 ( struct V_196 * V_196 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_254 * V_255 = V_249 -> V_250 -> V_255 ? V_249 -> V_250 -> V_255 : V_249 -> V_255 ;
return F_147 ( V_196 , V_255 ) ;
}
T_6 F_151 ( struct V_196 * V_196 , const char T_3 * V_230 ,
T_2 V_122 , T_4 * V_227 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_254 * V_255 = V_249 -> V_250 -> V_255 ? V_249 -> V_250 -> V_255 : V_249 -> V_255 ;
int V_149 = - V_117 ;
if ( V_255 && F_145 ( V_255 ) )
return - V_256 ;
if ( F_134 ( V_249 , V_196 ) )
goto exit;
V_149 = F_122 ( V_249 -> V_250 , V_230 , V_122 , V_227 ,
V_196 -> V_252 & V_253 ) ;
if ( V_249 -> V_250 -> V_218 )
V_249 -> V_250 -> V_251 = V_196 -> V_205 ;
exit:
if ( V_255 )
F_146 ( V_255 ) ;
return V_149 ;
}
T_6 F_152 ( struct V_196 * V_196 , char T_3 * V_230 ,
T_2 V_122 , T_4 * V_227 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_254 * V_255 = V_249 -> V_250 -> V_255 ? V_249 -> V_250 -> V_255 : V_249 -> V_255 ;
int V_149 = - V_117 ;
if ( V_255 && F_145 ( V_255 ) )
return - V_256 ;
if ( F_134 ( V_249 , V_196 ) )
goto exit;
V_149 = F_121 ( V_249 -> V_250 , V_230 , V_122 , V_227 ,
V_196 -> V_252 & V_253 ) ;
if ( V_249 -> V_250 -> V_218 )
V_249 -> V_250 -> V_251 = V_196 -> V_205 ;
exit:
if ( V_255 )
F_146 ( V_255 ) ;
return V_149 ;
}
unsigned int F_153 ( struct V_196 * V_196 , T_1 * V_197 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_3 * V_4 = V_249 -> V_250 ;
struct V_254 * V_255 = V_4 -> V_255 ? V_4 -> V_255 : V_249 -> V_255 ;
unsigned long V_200 = F_104 ( V_197 ) ;
unsigned V_201 ;
void * V_218 ;
bool V_257 = false ;
if ( V_4 -> V_29 == 0 && ! F_38 ( V_4 ) ) {
if ( ! F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_211 ) &&
( V_200 & ( V_207 | V_208 ) ) )
V_257 = true ;
else if ( F_27 ( V_4 -> type ) && ( V_4 -> V_107 & V_213 ) &&
( V_200 & ( V_209 | V_210 ) ) )
V_257 = true ;
}
F_51 ( V_257 && ! V_255 ) ;
if ( V_257 && V_255 && F_145 ( V_255 ) )
return V_212 ;
V_218 = V_4 -> V_218 ;
V_201 = F_102 ( V_249 -> V_250 , V_196 , V_197 ) ;
if ( V_257 && ! V_218 && V_4 -> V_218 )
V_4 -> V_251 = V_196 -> V_205 ;
if ( V_257 && V_255 )
F_146 ( V_255 ) ;
return V_201 ;
}
unsigned long F_154 ( struct V_196 * V_196 , unsigned long V_193 ,
unsigned long V_194 , unsigned long V_195 , unsigned long V_91 )
{
struct V_198 * V_249 = F_103 ( V_196 ) ;
struct V_254 * V_255 = V_249 -> V_250 -> V_255 ? V_249 -> V_250 -> V_255 : V_249 -> V_255 ;
int V_37 ;
if ( V_255 && F_145 ( V_255 ) )
return - V_256 ;
V_37 = F_101 ( V_249 -> V_250 , V_193 , V_194 , V_195 , V_91 ) ;
if ( V_255 )
F_146 ( V_255 ) ;
return V_37 ;
}
void F_155 ( struct V_3 * V_258 )
{
F_146 ( V_258 -> V_255 ) ;
}
void F_156 ( struct V_3 * V_258 )
{
F_148 ( V_258 -> V_255 ) ;
}
