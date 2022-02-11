static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
void * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
unsigned long V_13 = F_2 ( V_2 -> V_14 [ V_11 ] . V_15 ) ;
V_10 = F_3 ( V_2 , V_16 ,
V_4 -> V_17 [ V_11 ] ? : V_4 -> V_18 ,
V_4 -> V_19 , V_13 , V_6 , V_4 -> V_20 ) ;
if ( F_4 ( V_10 ) )
goto free;
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
return 0 ;
free:
for (; V_11 > 0 ; -- V_11 ) {
F_5 ( V_2 , V_21 , V_2 -> V_14 [ V_11 - 1 ] . V_10 ) ;
V_2 -> V_14 [ V_11 - 1 ] . V_10 = NULL ;
}
return - V_22 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
F_5 ( V_2 , V_21 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
F_7 ( 3 , L_1 , V_11 , V_2 -> V_23 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_10 )
F_5 ( V_2 , V_24 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
if ( ! V_26 -> V_10 )
return;
if ( V_26 -> V_27 )
F_5 ( V_2 , V_28 , V_26 -> V_10 ) ;
F_5 ( V_2 , V_29 , V_26 -> V_10 ) ;
F_10 ( V_26 -> V_30 ) ;
V_26 -> V_10 = NULL ;
V_26 -> V_30 = NULL ;
V_26 -> V_27 = 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_9 ( V_2 , & V_2 -> V_14 [ V_11 ] ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
unsigned long V_31 = 0 ;
if ( V_2 -> V_23 ) {
struct V_1 * V_32 = V_4 -> V_33 [ V_2 -> V_23 - 1 ] ;
struct V_25 * V_26 = & V_32 -> V_14 [ V_32 -> V_12 - 1 ] ;
V_31 = F_2 ( V_26 -> V_34 . V_35 + V_26 -> V_15 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_34 . V_35 = V_31 ;
F_7 ( 3 , L_2 ,
V_2 -> V_23 , V_11 , V_31 ) ;
V_31 += V_2 -> V_14 [ V_11 ] . V_15 ;
V_31 = F_2 ( V_31 ) ;
}
}
static int F_13 ( struct V_3 * V_4 , enum V_36 V_37 ,
unsigned int V_38 , unsigned int V_12 ,
const unsigned V_39 [ V_40 ] )
{
unsigned int V_41 , V_11 ;
struct V_1 * V_2 ;
int V_42 ;
for ( V_41 = 0 ; V_41 < V_38 ; ++ V_41 ) {
V_2 = F_14 ( V_4 -> V_43 , V_44 ) ;
if ( ! V_2 ) {
F_7 ( 1 , L_3 ) ;
break;
}
V_2 -> V_45 = V_46 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = V_4 -> V_38 + V_41 ;
V_2 -> type = V_4 -> type ;
V_2 -> V_37 = V_37 ;
for ( V_11 = 0 ; V_11 < V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_15 = V_39 [ V_11 ] ;
V_2 -> V_14 [ V_11 ] . V_47 = V_39 [ V_11 ] ;
}
V_4 -> V_33 [ V_2 -> V_23 ] = V_2 ;
if ( V_37 == V_48 ) {
V_42 = F_1 ( V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_4
L_5 , V_41 ) ;
V_4 -> V_33 [ V_2 -> V_23 ] = NULL ;
F_15 ( V_2 ) ;
break;
}
F_12 ( V_2 ) ;
V_42 = F_16 ( V_2 , V_49 , V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_6
L_7 , V_41 , V_2 ) ;
F_6 ( V_2 ) ;
V_4 -> V_33 [ V_2 -> V_23 ] = NULL ;
F_15 ( V_2 ) ;
break;
}
}
}
F_7 ( 1 , L_8 ,
V_41 , V_12 ) ;
return V_41 ;
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_50 )
{
unsigned int V_41 ;
struct V_1 * V_2 ;
for ( V_41 = V_4 -> V_38 - V_50 ; V_41 < V_4 -> V_38 ;
++ V_41 ) {
V_2 = V_4 -> V_33 [ V_41 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_37 == V_48 )
F_6 ( V_2 ) ;
else if ( V_4 -> V_37 == V_51 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
}
static int F_18 ( struct V_3 * V_4 , unsigned int V_50 )
{
unsigned int V_41 ;
for ( V_41 = V_4 -> V_38 - V_50 ; V_41 < V_4 -> V_38 ;
++ V_41 ) {
if ( V_4 -> V_33 [ V_41 ] == NULL )
continue;
if ( V_4 -> V_33 [ V_41 ] -> V_45 == V_52 ) {
F_7 ( 1 , L_9 ) ;
return - V_53 ;
}
}
for ( V_41 = V_4 -> V_38 - V_50 ; V_41 < V_4 -> V_38 ;
++ V_41 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_41 ] ;
if ( V_2 && V_2 -> V_14 [ 0 ] . V_10 )
F_19 ( V_2 , V_54 , V_2 ) ;
}
F_17 ( V_4 , V_50 ) ;
#ifdef F_20
if ( V_4 -> V_38 ) {
bool V_55 = V_4 -> V_56 != V_4 -> V_57 ||
V_4 -> V_58 != V_4 -> V_59 ;
if ( V_55 || V_60 ) {
F_21 ( L_10 , V_4 ,
V_55 ? L_11 : L_12 ) ;
F_21 ( L_13 ,
V_4 -> V_61 , V_4 -> V_56 ,
V_4 -> V_57 ) ;
F_21 ( L_14 ,
V_4 -> V_58 , V_4 -> V_59 ) ;
}
V_4 -> V_61 = 0 ;
V_4 -> V_58 = 0 ;
V_4 -> V_59 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_57 = 0 ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_38 ; ++ V_41 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_41 ] ;
bool V_55 = V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ||
V_2 -> V_74 != V_2 -> V_75 ||
V_2 -> V_76 != V_2 -> V_77 ;
if ( V_55 || V_60 ) {
F_21 ( L_15 ,
V_4 , V_41 , V_55 ? L_11 : L_12 ) ;
F_21 ( L_16 ,
V_2 -> V_76 , V_2 -> V_77 ,
V_2 -> V_74 , V_2 -> V_75 ) ;
F_21 ( L_17 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
F_21 ( L_18 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_64 , V_2 -> V_65 ,
V_2 -> V_78 ) ;
F_21 ( L_19 ,
V_2 -> V_66 , V_2 -> V_67 ) ;
F_21 ( L_20 ,
V_2 -> V_68 , V_2 -> V_69 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_21 ( L_21 ,
V_2 -> V_79 ,
V_2 -> V_80 ,
V_2 -> V_81 ,
V_2 -> V_82 ) ;
}
}
#endif
for ( V_41 = V_4 -> V_38 - V_50 ; V_41 < V_4 -> V_38 ;
++ V_41 ) {
F_15 ( V_4 -> V_33 [ V_41 ] ) ;
V_4 -> V_33 [ V_41 ] = NULL ;
}
V_4 -> V_38 -= V_50 ;
if ( ! V_4 -> V_38 ) {
V_4 -> V_37 = 0 ;
F_22 ( & V_4 -> V_83 ) ;
}
return 0 ;
}
bool F_23 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
void * V_10 = V_2 -> V_14 [ V_11 ] . V_10 ;
if ( V_10 && F_24 ( V_2 , V_84 , V_10 ) > 1 )
return true ;
}
return false ;
}
static bool F_25 ( struct V_3 * V_4 )
{
unsigned int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_38 ; ++ V_41 ) {
if ( F_23 ( V_4 , V_4 -> V_33 [ V_41 ] ) )
return true ;
}
return false ;
}
void F_26 ( struct V_3 * V_4 , unsigned int V_23 , void * V_85 )
{
F_27 ( V_4 , V_86 , V_4 -> V_33 [ V_23 ] , V_85 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_88 ) || ! V_4 -> V_89 -> V_90 ||
! V_4 -> V_89 -> V_24 )
return - V_91 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_92 ) || ! V_4 -> V_89 -> V_16 ||
! V_4 -> V_89 -> V_21 || ! V_4 -> V_89 -> V_93 )
return - V_91 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_94 ) || ! V_4 -> V_89 -> V_95 ||
! V_4 -> V_89 -> V_29 || ! V_4 -> V_89 -> V_96 ||
! V_4 -> V_89 -> V_28 )
return - V_91 ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 ,
enum V_36 V_37 , unsigned int type )
{
if ( V_37 != V_48 && V_37 != V_97 &&
V_37 != V_51 ) {
F_7 ( 1 , L_22 ) ;
return - V_91 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_23 ) ;
return - V_91 ;
}
if ( V_37 == V_48 && F_29 ( V_4 ) ) {
F_7 ( 1 , L_24 ) ;
return - V_91 ;
}
if ( V_37 == V_97 && F_28 ( V_4 ) ) {
F_7 ( 1 , L_25 ) ;
return - V_91 ;
}
if ( V_37 == V_51 && F_30 ( V_4 ) ) {
F_7 ( 1 , L_26 ) ;
return - V_91 ;
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_27 ) ;
return - V_98 ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 , enum V_36 V_37 ,
unsigned int * V_99 )
{
unsigned int V_38 , V_100 , V_12 = 0 ;
unsigned V_39 [ V_40 ] = { } ;
int V_42 ;
if ( V_4 -> V_101 ) {
F_7 ( 1 , L_28 ) ;
return - V_98 ;
}
if ( * V_99 == 0 || V_4 -> V_38 != 0 || V_4 -> V_37 != V_37 ) {
F_34 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_37 == V_48 && F_25 ( V_4 ) ) {
F_35 ( & V_4 -> V_102 ) ;
F_7 ( 1 , L_29 ) ;
return - V_98 ;
}
F_36 ( V_4 ) ;
V_42 = F_18 ( V_4 , V_4 -> V_38 ) ;
F_35 ( & V_4 -> V_102 ) ;
if ( V_42 )
return V_42 ;
if ( * V_99 == 0 )
return 0 ;
}
V_38 = F_37 (unsigned int, *count, VB2_MAX_FRAME) ;
V_38 = F_38 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_17 , 0 , sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_37 = V_37 ;
V_42 = F_39 ( V_4 , V_103 , V_4 , & V_38 , & V_12 ,
V_39 , V_4 -> V_17 ) ;
if ( V_42 )
return V_42 ;
V_100 =
F_13 ( V_4 , V_37 , V_38 , V_12 , V_39 ) ;
if ( V_100 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_22 ;
}
if ( V_100 < V_4 -> V_104 )
V_42 = - V_22 ;
if ( ! V_42 && V_100 < V_38 ) {
V_38 = V_100 ;
V_12 = 0 ;
V_42 = F_39 ( V_4 , V_103 , V_4 , & V_38 ,
& V_12 , V_39 , V_4 -> V_17 ) ;
if ( ! V_42 && V_100 < V_38 )
V_42 = - V_22 ;
}
F_34 ( & V_4 -> V_102 ) ;
V_4 -> V_38 = V_100 ;
if ( V_42 < 0 ) {
F_18 ( V_4 , V_100 ) ;
F_35 ( & V_4 -> V_102 ) ;
return V_42 ;
}
F_35 ( & V_4 -> V_102 ) ;
* V_99 = V_100 ;
V_4 -> V_105 = ! V_4 -> V_7 ;
return 0 ;
}
int F_40 ( struct V_3 * V_4 , enum V_36 V_37 ,
unsigned int * V_99 , unsigned V_106 ,
const unsigned V_107 [] )
{
unsigned int V_12 = 0 , V_38 , V_100 ;
unsigned V_39 [ V_40 ] = { } ;
int V_42 ;
if ( V_4 -> V_38 == V_108 ) {
F_7 ( 1 , L_31 ) ;
return - V_109 ;
}
if ( ! V_4 -> V_38 ) {
memset ( V_4 -> V_17 , 0 , sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_37 = V_37 ;
V_4 -> V_105 = ! V_4 -> V_7 ;
}
V_38 = F_41 ( * V_99 , V_108 - V_4 -> V_38 ) ;
if ( V_106 && V_107 ) {
V_12 = V_106 ;
memcpy ( V_39 , V_107 , sizeof( V_39 ) ) ;
}
V_42 = F_39 ( V_4 , V_103 , V_4 , & V_38 ,
& V_12 , V_39 , V_4 -> V_17 ) ;
if ( V_42 )
return V_42 ;
V_100 = F_13 ( V_4 , V_37 , V_38 ,
V_12 , V_39 ) ;
if ( V_100 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_22 ;
}
if ( V_100 < V_38 ) {
V_38 = V_100 ;
V_42 = F_39 ( V_4 , V_103 , V_4 , & V_38 ,
& V_12 , V_39 , V_4 -> V_17 ) ;
if ( ! V_42 && V_100 < V_38 )
V_42 = - V_22 ;
}
F_34 ( & V_4 -> V_102 ) ;
V_4 -> V_38 += V_100 ;
if ( V_42 < 0 ) {
F_18 ( V_4 , V_100 ) ;
F_35 ( & V_4 -> V_102 ) ;
return - V_22 ;
}
F_35 ( & V_4 -> V_102 ) ;
* V_99 = V_100 ;
return 0 ;
}
void * F_42 ( struct V_1 * V_2 , unsigned int V_110 )
{
if ( V_110 > V_2 -> V_12 || ! V_2 -> V_14 [ V_110 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_111 , V_2 -> V_14 [ V_110 ] . V_10 ) ;
}
void * F_43 ( struct V_1 * V_2 , unsigned int V_110 )
{
if ( V_110 >= V_2 -> V_12 || ! V_2 -> V_14 [ V_110 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_112 , V_2 -> V_14 [ V_110 ] . V_10 ) ;
}
void F_44 ( struct V_1 * V_2 , enum V_113 V_45 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_114 ;
unsigned int V_11 ;
if ( F_45 ( V_2 -> V_45 != V_115 ) )
return;
if ( F_45 ( V_45 != V_116 &&
V_45 != V_117 &&
V_45 != V_118 &&
V_45 != V_119 ) )
V_45 = V_117 ;
#ifdef F_20
V_2 -> V_73 ++ ;
#endif
F_7 ( 4 , L_32 ,
V_2 -> V_23 , V_45 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_120 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
F_46 ( & V_4 -> V_121 , V_114 ) ;
if ( V_45 == V_118 ||
V_45 == V_119 ) {
V_2 -> V_45 = V_118 ;
} else {
F_47 ( & V_2 -> V_122 , & V_4 -> V_123 ) ;
V_2 -> V_45 = V_45 ;
}
F_48 ( & V_4 -> V_124 ) ;
F_49 ( & V_4 -> V_121 , V_114 ) ;
F_50 ( V_4 , V_2 ) ;
switch ( V_45 ) {
case V_118 :
return;
case V_119 :
if ( V_4 -> V_125 )
F_51 ( V_2 ) ;
return;
default:
F_52 ( & V_4 -> V_126 ) ;
break;
}
}
void F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_114 ;
F_46 ( & V_4 -> V_121 , V_114 ) ;
F_54 (vb, &q->done_list, done_entry)
V_2 -> V_45 = V_117 ;
F_49 ( & V_4 -> V_121 , V_114 ) ;
}
static int F_55 ( struct V_1 * V_2 , const void * V_85 )
{
int V_42 = 0 ;
if ( V_85 )
V_42 = F_56 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_2 -> V_14 ) ;
return V_42 ? V_42 : F_16 ( V_2 , V_128 , V_2 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_25 V_14 [ V_40 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_42 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_129 = V_2 -> V_14 [ 0 ] . V_10 == NULL ;
memset ( V_14 , 0 , sizeof( V_14 [ 0 ] ) * V_2 -> V_12 ) ;
if ( V_85 )
V_42 = F_56 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_14 ) ;
if ( V_42 )
return V_42 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_34 . V_130 &&
V_2 -> V_14 [ V_11 ] . V_34 . V_130 == V_14 [ V_11 ] . V_34 . V_130
&& V_2 -> V_14 [ V_11 ] . V_15 == V_14 [ V_11 ] . V_15 )
continue;
F_7 ( 3 , L_33
L_34 , V_11 ) ;
if ( V_14 [ V_11 ] . V_15 < V_2 -> V_14 [ V_11 ] . V_47 ) {
F_7 ( 1 , L_35
L_36 ,
V_14 [ V_11 ] . V_15 ,
V_2 -> V_14 [ V_11 ] . V_47 ,
V_11 ) ;
V_42 = - V_91 ;
goto V_131;
}
if ( V_2 -> V_14 [ V_11 ] . V_10 ) {
if ( ! V_129 ) {
V_129 = true ;
F_19 ( V_2 , V_54 , V_2 ) ;
}
F_5 ( V_2 , V_24 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
}
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
V_2 -> V_14 [ V_11 ] . V_132 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
V_2 -> V_14 [ V_11 ] . V_34 . V_130 = 0 ;
V_2 -> V_14 [ V_11 ] . V_133 = 0 ;
V_10 = F_3 ( V_2 , V_90 ,
V_4 -> V_17 [ V_11 ] ? : V_4 -> V_18 ,
V_14 [ V_11 ] . V_34 . V_130 ,
V_14 [ V_11 ] . V_15 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
F_7 ( 1 , L_37
L_38 , V_11 ) ;
V_42 = V_10 ? F_58 ( V_10 ) : - V_91 ;
goto V_131;
}
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_132 = V_14 [ V_11 ] . V_132 ;
V_2 -> V_14 [ V_11 ] . V_15 = V_14 [ V_11 ] . V_15 ;
V_2 -> V_14 [ V_11 ] . V_34 . V_130 = V_14 [ V_11 ] . V_34 . V_130 ;
V_2 -> V_14 [ V_11 ] . V_133 = V_14 [ V_11 ] . V_133 ;
}
if ( V_129 ) {
V_42 = F_16 ( V_2 , V_49 , V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_39 ) ;
goto V_131;
}
}
V_42 = F_16 ( V_2 , V_128 , V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_40 ) ;
F_19 ( V_2 , V_54 , V_2 ) ;
goto V_131;
}
return 0 ;
V_131:
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_10 )
F_5 ( V_2 , V_24 ,
V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
V_2 -> V_14 [ V_11 ] . V_34 . V_130 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
}
return V_42 ;
}
static int F_59 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_25 V_14 [ V_40 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_42 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_129 = V_2 -> V_14 [ 0 ] . V_10 == NULL ;
memset ( V_14 , 0 , sizeof( V_14 [ 0 ] ) * V_2 -> V_12 ) ;
if ( V_85 )
V_42 = F_56 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_14 ) ;
if ( V_42 )
return V_42 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
struct V_134 * V_30 = F_60 ( V_14 [ V_11 ] . V_34 . V_135 ) ;
if ( F_4 ( V_30 ) ) {
F_7 ( 1 , L_41 ,
V_11 ) ;
V_42 = - V_91 ;
goto V_131;
}
if ( V_14 [ V_11 ] . V_15 == 0 )
V_14 [ V_11 ] . V_15 = V_30 -> V_13 ;
if ( V_14 [ V_11 ] . V_15 < V_2 -> V_14 [ V_11 ] . V_47 ) {
F_7 ( 1 , L_42 ,
V_11 ) ;
F_10 ( V_30 ) ;
V_42 = - V_91 ;
goto V_131;
}
if ( V_30 == V_2 -> V_14 [ V_11 ] . V_30 &&
V_2 -> V_14 [ V_11 ] . V_15 == V_14 [ V_11 ] . V_15 ) {
F_10 ( V_30 ) ;
continue;
}
F_7 ( 1 , L_43 , V_11 ) ;
if ( ! V_129 ) {
V_129 = true ;
F_19 ( V_2 , V_54 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_14 [ V_11 ] ) ;
V_2 -> V_14 [ V_11 ] . V_132 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
V_2 -> V_14 [ V_11 ] . V_34 . V_135 = 0 ;
V_2 -> V_14 [ V_11 ] . V_133 = 0 ;
V_10 = F_3 ( V_2 , V_95 ,
V_4 -> V_17 [ V_11 ] ? : V_4 -> V_18 ,
V_30 , V_14 [ V_11 ] . V_15 , V_6 ) ;
if ( F_61 ( V_10 ) ) {
F_7 ( 1 , L_44 ) ;
V_42 = F_58 ( V_10 ) ;
F_10 ( V_30 ) ;
goto V_131;
}
V_2 -> V_14 [ V_11 ] . V_30 = V_30 ;
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_42 = F_24 ( V_2 , V_96 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
if ( V_42 ) {
F_7 ( 1 , L_45 ,
V_11 ) ;
goto V_131;
}
V_2 -> V_14 [ V_11 ] . V_27 = 1 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_132 = V_14 [ V_11 ] . V_132 ;
V_2 -> V_14 [ V_11 ] . V_15 = V_14 [ V_11 ] . V_15 ;
V_2 -> V_14 [ V_11 ] . V_34 . V_135 = V_14 [ V_11 ] . V_34 . V_135 ;
V_2 -> V_14 [ V_11 ] . V_133 = V_14 [ V_11 ] . V_133 ;
}
if ( V_129 ) {
V_42 = F_16 ( V_2 , V_49 , V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_39 ) ;
goto V_131;
}
}
V_42 = F_16 ( V_2 , V_128 , V_2 ) ;
if ( V_42 ) {
F_7 ( 1 , L_40 ) ;
F_19 ( V_2 , V_54 , V_2 ) ;
goto V_131;
}
return 0 ;
V_131:
F_11 ( V_2 ) ;
return V_42 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
V_2 -> V_45 = V_115 ;
F_62 ( & V_4 -> V_124 ) ;
F_63 ( V_4 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_136 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
F_19 ( V_2 , V_137 , V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_42 ;
if ( V_4 -> error ) {
F_7 ( 1 , L_46 ) ;
return - V_138 ;
}
V_2 -> V_45 = V_52 ;
switch ( V_4 -> V_37 ) {
case V_48 :
V_42 = F_55 ( V_2 , V_85 ) ;
break;
case V_97 :
V_42 = F_57 ( V_2 , V_85 ) ;
break;
case V_51 :
V_42 = F_59 ( V_2 , V_85 ) ;
break;
default:
F_65 ( 1 , L_47 ) ;
V_42 = - V_91 ;
}
if ( V_42 )
F_7 ( 1 , L_48 , V_42 ) ;
V_2 -> V_45 = V_42 ? V_46 : V_139 ;
return V_42 ;
}
int F_66 ( struct V_3 * V_4 , unsigned int V_23 , void * V_85 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = V_4 -> V_33 [ V_23 ] ;
if ( V_2 -> V_45 != V_46 ) {
F_7 ( 1 , L_49 ,
V_2 -> V_45 ) ;
return - V_91 ;
}
V_42 = F_64 ( V_2 , V_85 ) ;
if ( V_42 )
return V_42 ;
F_27 ( V_4 , V_86 , V_2 , V_85 ) ;
F_7 ( 1 , L_50 , V_2 -> V_23 ) ;
return V_42 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_42 ;
F_54 (vb, &q->queued_list, queued_entry)
F_51 ( V_2 ) ;
V_4 -> V_125 = 1 ;
V_42 = F_39 ( V_4 , V_140 , V_4 ,
F_68 ( & V_4 -> V_124 ) ) ;
if ( ! V_42 )
return 0 ;
V_4 -> V_125 = 0 ;
F_7 ( 1 , L_51 ) ;
if ( F_45 ( F_68 ( & V_4 -> V_124 ) ) ) {
unsigned V_141 ;
for ( V_141 = 0 ; V_141 < V_4 -> V_38 ; ++ V_141 ) {
V_2 = V_4 -> V_33 [ V_141 ] ;
if ( V_2 -> V_45 == V_115 )
F_44 ( V_2 , V_118 ) ;
}
F_45 ( F_68 ( & V_4 -> V_124 ) ) ;
}
F_45 ( ! F_69 ( & V_4 -> V_123 ) ) ;
return V_42 ;
}
int F_70 ( struct V_3 * V_4 , unsigned int V_23 , void * V_85 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = V_4 -> V_33 [ V_23 ] ;
switch ( V_2 -> V_45 ) {
case V_46 :
V_42 = F_64 ( V_2 , V_85 ) ;
if ( V_42 )
return V_42 ;
break;
case V_139 :
break;
case V_52 :
F_7 ( 1 , L_52 ) ;
return - V_91 ;
default:
F_7 ( 1 , L_49 , V_2 -> V_45 ) ;
return - V_91 ;
}
F_47 ( & V_2 -> V_142 , & V_4 -> V_83 ) ;
V_4 -> V_143 ++ ;
V_4 -> V_105 = false ;
V_2 -> V_45 = V_118 ;
if ( V_85 )
F_27 ( V_4 , V_144 , V_2 , V_85 ) ;
F_71 ( V_4 , V_2 ) ;
if ( V_4 -> V_125 )
F_51 ( V_2 ) ;
if ( V_85 )
F_27 ( V_4 , V_86 , V_2 , V_85 ) ;
if ( V_4 -> V_101 && ! V_4 -> V_125 &&
V_4 -> V_143 >= V_4 -> V_104 ) {
V_42 = F_67 ( V_4 ) ;
if ( V_42 )
return V_42 ;
}
F_7 ( 1 , L_53 , V_2 -> V_23 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int V_145 )
{
for (; ; ) {
int V_42 ;
if ( ! V_4 -> V_101 ) {
F_7 ( 1 , L_54 ) ;
return - V_91 ;
}
if ( V_4 -> error ) {
F_7 ( 1 , L_55 ) ;
return - V_138 ;
}
if ( V_4 -> V_146 ) {
F_7 ( 3 , L_56 ) ;
return - V_147 ;
}
if ( ! F_69 ( & V_4 -> V_123 ) ) {
break;
}
if ( V_145 ) {
F_7 ( 1 , L_57
L_58 ) ;
return - V_53 ;
}
F_73 ( V_4 , V_148 , V_4 ) ;
F_7 ( 3 , L_59 ) ;
V_42 = F_74 ( V_4 -> V_126 ,
! F_69 ( & V_4 -> V_123 ) || ! V_4 -> V_101 ||
V_4 -> error ) ;
F_73 ( V_4 , V_149 , V_4 ) ;
if ( V_42 ) {
F_7 ( 1 , L_60 ) ;
return V_42 ;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
void * V_85 , int V_145 )
{
unsigned long V_114 ;
int V_42 = 0 ;
V_42 = F_72 ( V_4 , V_145 ) ;
if ( V_42 )
return V_42 ;
F_46 ( & V_4 -> V_121 , V_114 ) ;
* V_2 = F_76 ( & V_4 -> V_123 , struct V_1 , V_122 ) ;
if ( V_85 )
V_42 = F_56 ( V_4 , V_150 , * V_2 , V_85 ) ;
if ( ! V_42 )
F_77 ( & ( * V_2 ) -> V_122 ) ;
F_49 ( & V_4 -> V_121 , V_114 ) ;
return V_42 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_101 ) {
F_7 ( 1 , L_54 ) ;
return - V_91 ;
}
if ( V_4 -> V_125 )
F_79 ( V_4 -> V_126 , ! F_68 ( & V_4 -> V_124 ) ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_141 ;
if ( V_2 -> V_45 == V_46 )
return;
V_2 -> V_45 = V_46 ;
if ( V_4 -> V_37 == V_51 )
for ( V_141 = 0 ; V_141 < V_2 -> V_12 ; ++ V_141 ) {
if ( ! V_2 -> V_14 [ V_141 ] . V_27 )
continue;
F_5 ( V_2 , V_28 , V_2 -> V_14 [ V_141 ] . V_10 ) ;
V_2 -> V_14 [ V_141 ] . V_27 = 0 ;
}
}
int F_81 ( struct V_3 * V_4 , unsigned int * V_151 , void * V_85 ,
bool V_145 )
{
struct V_1 * V_2 = NULL ;
int V_42 ;
V_42 = F_75 ( V_4 , & V_2 , V_85 , V_145 ) ;
if ( V_42 < 0 )
return V_42 ;
switch ( V_2 -> V_45 ) {
case V_116 :
F_7 ( 3 , L_61 ) ;
break;
case V_117 :
F_7 ( 3 , L_62 ) ;
break;
default:
F_7 ( 1 , L_63 ) ;
return - V_91 ;
}
F_19 ( V_2 , V_152 , V_2 ) ;
if ( V_151 )
* V_151 = V_2 -> V_23 ;
if ( V_85 )
F_27 ( V_4 , V_86 , V_2 , V_85 ) ;
F_77 ( & V_2 -> V_142 ) ;
V_4 -> V_143 -- ;
F_82 ( V_4 , V_2 ) ;
F_80 ( V_2 ) ;
F_7 ( 1 , L_64 ,
V_2 -> V_23 , V_2 -> V_45 ) ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
unsigned int V_141 ;
if ( V_4 -> V_125 )
F_73 ( V_4 , V_153 , V_4 ) ;
if ( F_45 ( F_68 ( & V_4 -> V_124 ) ) ) {
for ( V_141 = 0 ; V_141 < V_4 -> V_38 ; ++ V_141 )
if ( V_4 -> V_33 [ V_141 ] -> V_45 == V_115 )
F_44 ( V_4 -> V_33 [ V_141 ] , V_117 ) ;
F_45 ( F_68 ( & V_4 -> V_124 ) ) ;
}
V_4 -> V_101 = 0 ;
V_4 -> V_125 = 0 ;
V_4 -> V_143 = 0 ;
V_4 -> error = 0 ;
F_22 ( & V_4 -> V_83 ) ;
F_22 ( & V_4 -> V_123 ) ;
F_83 ( & V_4 -> V_124 , 0 ) ;
F_84 ( & V_4 -> V_126 ) ;
for ( V_141 = 0 ; V_141 < V_4 -> V_38 ; ++ V_141 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_141 ] ;
if ( V_2 -> V_45 != V_46 ) {
V_2 -> V_45 = V_139 ;
F_19 ( V_2 , V_152 , V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
int F_85 ( struct V_3 * V_4 , unsigned int type )
{
int V_42 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_91 ;
}
if ( V_4 -> V_101 ) {
F_7 ( 3 , L_66 ) ;
return 0 ;
}
if ( ! V_4 -> V_38 ) {
F_7 ( 1 , L_67 ) ;
return - V_91 ;
}
if ( V_4 -> V_38 < V_4 -> V_104 ) {
F_7 ( 1 , L_68 ,
V_4 -> V_104 ) ;
return - V_91 ;
}
if ( V_4 -> V_143 >= V_4 -> V_104 ) {
V_42 = F_86 ( V_4 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_67 ( V_4 ) ;
if ( V_42 ) {
F_36 ( V_4 ) ;
return V_42 ;
}
}
V_4 -> V_101 = 1 ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
void F_87 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_84 ( & V_4 -> V_126 ) ;
}
int F_88 ( struct V_3 * V_4 , unsigned int type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_91 ;
}
F_36 ( V_4 ) ;
V_4 -> V_105 = ! V_4 -> V_7 ;
V_4 -> V_146 = false ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_154 , unsigned int * V_155 )
{
struct V_1 * V_2 ;
unsigned int V_41 , V_11 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_38 ; ++ V_41 ) {
V_2 = V_4 -> V_33 [ V_41 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_34 . V_35 == V_31 ) {
* V_154 = V_41 ;
* V_155 = V_11 ;
return 0 ;
}
}
}
return - V_91 ;
}
int F_90 ( struct V_3 * V_4 , int * V_135 , unsigned int type ,
unsigned int V_23 , unsigned int V_11 , unsigned int V_114 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_156 ;
int V_42 ;
struct V_134 * V_30 ;
if ( V_4 -> V_37 != V_48 ) {
F_7 ( 1 , L_70 ) ;
return - V_91 ;
}
if ( ! V_4 -> V_89 -> V_157 ) {
F_7 ( 1 , L_71 ) ;
return - V_91 ;
}
if ( V_114 & ~ ( V_158 | V_159 ) ) {
F_7 ( 1 , L_72 ) ;
return - V_91 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_73 ) ;
return - V_91 ;
}
if ( V_23 >= V_4 -> V_38 ) {
F_7 ( 1 , L_74 ) ;
return - V_91 ;
}
V_2 = V_4 -> V_33 [ V_23 ] ;
if ( V_11 >= V_2 -> V_12 ) {
F_7 ( 1 , L_75 ) ;
return - V_91 ;
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_76 ) ;
return - V_98 ;
}
V_156 = & V_2 -> V_14 [ V_11 ] ;
V_30 = F_3 ( V_2 , V_157 , V_156 -> V_10 ,
V_114 & V_159 ) ;
if ( F_4 ( V_30 ) ) {
F_7 ( 1 , L_77 ,
V_23 , V_11 ) ;
return - V_91 ;
}
V_42 = F_91 ( V_30 , V_114 & ~ V_159 ) ;
if ( V_42 < 0 ) {
F_7 ( 3 , L_78 ,
V_23 , V_11 , V_42 ) ;
F_10 ( V_30 ) ;
return V_42 ;
}
F_7 ( 3 , L_79 ,
V_23 , V_11 , V_42 ) ;
* V_135 = V_42 ;
return 0 ;
}
int F_92 ( struct V_3 * V_4 , struct V_160 * V_161 )
{
unsigned long V_31 = V_161 -> V_162 << V_163 ;
struct V_1 * V_2 ;
unsigned int V_41 = 0 , V_11 = 0 ;
int V_42 ;
unsigned long V_15 ;
if ( V_4 -> V_37 != V_48 ) {
F_7 ( 1 , L_70 ) ;
return - V_91 ;
}
if ( ! ( V_161 -> V_164 & V_165 ) ) {
F_7 ( 1 , L_80 ) ;
return - V_91 ;
}
if ( V_4 -> V_7 ) {
if ( ! ( V_161 -> V_164 & V_166 ) ) {
F_7 ( 1 , L_81 ) ;
return - V_91 ;
}
} else {
if ( ! ( V_161 -> V_164 & V_167 ) ) {
F_7 ( 1 , L_82 ) ;
return - V_91 ;
}
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_83 ) ;
return - V_98 ;
}
V_42 = F_89 ( V_4 , V_31 , & V_41 , & V_11 ) ;
if ( V_42 )
return V_42 ;
V_2 = V_4 -> V_33 [ V_41 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_11 ] . V_15 ) ;
if ( V_15 < ( V_161 -> V_168 - V_161 -> V_169 ) ) {
F_7 ( 1 ,
L_84 ) ;
return - V_91 ;
}
F_34 ( & V_4 -> V_102 ) ;
V_42 = F_24 ( V_2 , V_93 , V_2 -> V_14 [ V_11 ] . V_10 , V_161 ) ;
F_35 ( & V_4 -> V_102 ) ;
if ( V_42 )
return V_42 ;
F_7 ( 3 , L_85 , V_41 , V_11 ) ;
return 0 ;
}
unsigned long F_93 ( struct V_3 * V_4 ,
unsigned long V_170 ,
unsigned long V_171 ,
unsigned long V_172 ,
unsigned long V_114 )
{
unsigned long V_31 = V_172 << V_163 ;
struct V_1 * V_2 ;
unsigned int V_41 , V_11 ;
void * V_111 ;
int V_42 ;
if ( V_4 -> V_37 != V_48 ) {
F_7 ( 1 , L_70 ) ;
return - V_91 ;
}
V_42 = F_89 ( V_4 , V_31 , & V_41 , & V_11 ) ;
if ( V_42 )
return V_42 ;
V_2 = V_4 -> V_33 [ V_41 ] ;
V_111 = F_42 ( V_2 , V_11 ) ;
return V_111 ? ( unsigned long ) V_111 : - V_91 ;
}
int F_94 ( struct V_3 * V_4 )
{
if ( F_45 ( ! V_4 ) ||
F_45 ( ! V_4 -> V_173 ) ||
F_45 ( ! V_4 -> V_89 ) ||
F_45 ( ! V_4 -> type ) ||
F_45 ( ! V_4 -> V_87 ) ||
F_45 ( ! V_4 -> V_173 -> V_103 ) ||
F_45 ( ! V_4 -> V_173 -> V_137 ) )
return - V_91 ;
F_22 ( & V_4 -> V_83 ) ;
F_22 ( & V_4 -> V_123 ) ;
F_95 ( & V_4 -> V_121 ) ;
F_96 ( & V_4 -> V_102 ) ;
F_97 ( & V_4 -> V_126 ) ;
if ( V_4 -> V_43 == 0 )
V_4 -> V_43 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_98 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
F_36 ( V_4 ) ;
F_34 ( & V_4 -> V_102 ) ;
F_18 ( V_4 , V_4 -> V_38 ) ;
F_35 ( & V_4 -> V_102 ) ;
}
unsigned int F_100 ( struct V_3 * V_4 , struct V_174 * V_174 ,
T_1 * V_175 )
{
unsigned long V_176 = F_101 ( V_175 ) ;
struct V_1 * V_2 = NULL ;
unsigned long V_114 ;
if ( ! V_4 -> V_7 && ! ( V_176 & ( V_177 | V_178 ) ) )
return 0 ;
if ( V_4 -> V_7 && ! ( V_176 & ( V_179 | V_180 ) ) )
return 0 ;
if ( V_4 -> V_38 == 0 && ! F_32 ( V_4 ) ) {
if ( ! V_4 -> V_7 && ( V_4 -> V_87 & V_181 ) &&
( V_176 & ( V_177 | V_178 ) ) ) {
if ( F_102 ( V_4 , 1 ) )
return V_182 ;
}
if ( V_4 -> V_7 && ( V_4 -> V_87 & V_183 ) &&
( V_176 & ( V_179 | V_180 ) ) ) {
if ( F_102 ( V_4 , 0 ) )
return V_182 ;
return V_179 | V_180 ;
}
}
if ( ! F_103 ( V_4 ) || V_4 -> error )
return V_182 ;
if ( V_4 -> V_184 &&
V_4 -> V_105 && ( V_176 & ( V_177 | V_178 ) ) )
return V_182 ;
if ( V_4 -> V_7 && V_4 -> V_185 && V_4 -> V_143 < V_4 -> V_38 )
return V_179 | V_180 ;
if ( F_69 ( & V_4 -> V_123 ) ) {
if ( V_4 -> V_146 )
return V_177 | V_178 ;
F_104 ( V_174 , & V_4 -> V_126 , V_175 ) ;
}
F_46 ( & V_4 -> V_121 , V_114 ) ;
if ( ! F_69 ( & V_4 -> V_123 ) )
V_2 = F_76 ( & V_4 -> V_123 , struct V_1 ,
V_122 ) ;
F_49 ( & V_4 -> V_121 , V_114 ) ;
if ( V_2 && ( V_2 -> V_45 == V_116
|| V_2 -> V_45 == V_117 ) ) {
return ( V_4 -> V_7 ) ?
V_179 | V_180 :
V_177 | V_178 ;
}
return 0 ;
}
static int F_102 ( struct V_3 * V_4 , int V_186 )
{
struct V_187 * V_185 ;
int V_141 , V_42 ;
unsigned int V_99 = 0 ;
if ( F_45 ( ( V_186 && ! ( V_4 -> V_87 & V_181 ) ) ||
( ! V_186 && ! ( V_4 -> V_87 & V_183 ) ) ) )
return - V_91 ;
if ( ! V_4 -> V_89 -> V_111 )
return - V_98 ;
if ( V_4 -> V_101 || V_4 -> V_38 > 0 )
return - V_98 ;
V_99 = 1 ;
F_7 ( 3 , L_86 ,
( V_186 ) ? L_87 : L_88 , V_99 , V_4 -> V_188 ,
V_4 -> V_189 ) ;
V_185 = F_14 ( sizeof( * V_185 ) , V_44 ) ;
if ( V_185 == NULL )
return - V_22 ;
V_185 -> V_190 = V_4 -> V_188 ;
V_185 -> V_191 = V_4 -> V_189 ;
V_185 -> V_99 = V_99 ;
V_185 -> V_37 = V_48 ;
V_185 -> type = V_4 -> type ;
V_4 -> V_185 = V_185 ;
V_42 = F_33 ( V_4 , V_185 -> V_37 , & V_185 -> V_99 ) ;
if ( V_42 )
goto V_192;
if ( V_4 -> V_33 [ 0 ] -> V_12 != 1 ) {
V_42 = - V_98 ;
goto V_193;
}
for ( V_141 = 0 ; V_141 < V_4 -> V_38 ; V_141 ++ ) {
V_185 -> V_33 [ V_141 ] . V_111 = F_42 ( V_4 -> V_33 [ V_141 ] , 0 ) ;
if ( V_185 -> V_33 [ V_141 ] . V_111 == NULL ) {
V_42 = - V_91 ;
goto V_193;
}
V_185 -> V_33 [ V_141 ] . V_13 = F_105 ( V_4 -> V_33 [ V_141 ] , 0 ) ;
}
if ( V_186 ) {
for ( V_141 = 0 ; V_141 < V_4 -> V_38 ; V_141 ++ ) {
V_42 = F_70 ( V_4 , V_141 , NULL ) ;
if ( V_42 )
goto V_193;
V_185 -> V_33 [ V_141 ] . V_194 = 1 ;
}
V_185 -> V_195 = V_4 -> V_38 ;
V_185 -> V_196 = V_4 -> V_38 ;
}
V_42 = F_85 ( V_4 , V_4 -> type ) ;
if ( V_42 )
goto V_193;
return V_42 ;
V_193:
V_185 -> V_99 = 0 ;
F_33 ( V_4 , V_185 -> V_37 , & V_185 -> V_99 ) ;
V_192:
V_4 -> V_185 = NULL ;
F_15 ( V_185 ) ;
return V_42 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_187 * V_185 = V_4 -> V_185 ;
if ( V_185 ) {
F_88 ( V_4 , V_4 -> type ) ;
V_4 -> V_185 = NULL ;
V_185 -> V_99 = 0 ;
F_33 ( V_4 , V_185 -> V_37 , & V_185 -> V_99 ) ;
F_15 ( V_185 ) ;
F_7 ( 3 , L_89 ) ;
}
return 0 ;
}
static T_2 F_106 ( struct V_3 * V_4 , char T_3 * V_197 , T_2 V_99 ,
T_4 * V_198 , int V_199 , int V_186 )
{
struct V_187 * V_185 ;
struct V_200 * V_201 ;
bool V_202 = V_4 -> V_202 ;
bool V_144 = ! V_186 && V_4 -> V_144 ;
unsigned V_23 ;
int V_42 ;
F_7 ( 3 , L_90 ,
V_186 ? L_87 : L_88 , ( long ) * V_198 , V_99 ,
V_199 ? L_91 : L_12 ) ;
if ( ! V_197 )
return - V_91 ;
if ( ! F_32 ( V_4 ) ) {
V_42 = F_102 ( V_4 , V_186 ) ;
F_7 ( 3 , L_92 , V_42 ) ;
if ( V_42 )
return V_42 ;
}
V_185 = V_4 -> V_185 ;
V_23 = V_185 -> V_196 ;
if ( V_23 >= V_4 -> V_38 ) {
struct V_1 * V_203 ;
V_42 = F_81 ( V_4 , & V_23 , NULL , V_199 ) ;
F_7 ( 5 , L_93 , V_42 ) ;
if ( V_42 )
return V_42 ;
V_185 -> V_204 += 1 ;
V_185 -> V_196 = V_23 ;
V_201 = & V_185 -> V_33 [ V_23 ] ;
V_203 = V_4 -> V_33 [ V_23 ] ;
V_201 -> V_205 = 0 ;
V_201 -> V_194 = 0 ;
V_201 -> V_13 = V_186 ? F_107 ( V_4 -> V_33 [ V_23 ] , 0 )
: F_105 ( V_4 -> V_33 [ V_23 ] , 0 ) ;
if ( V_202 && V_186 &&
V_203 -> V_14 [ 0 ] . V_133 < V_201 -> V_13 ) {
V_201 -> V_205 = V_203 -> V_14 [ 0 ] . V_133 ;
V_201 -> V_13 -= V_201 -> V_205 ;
}
} else {
V_201 = & V_185 -> V_33 [ V_23 ] ;
}
if ( V_201 -> V_205 + V_99 > V_201 -> V_13 ) {
V_99 = V_201 -> V_13 - V_201 -> V_205 ;
F_7 ( 5 , L_94 , V_99 ) ;
}
F_7 ( 3 , L_95 ,
V_99 , V_23 , V_201 -> V_205 ) ;
if ( V_186 )
V_42 = F_108 ( V_197 , V_201 -> V_111 + V_201 -> V_205 , V_99 ) ;
else
V_42 = F_109 ( V_201 -> V_111 + V_201 -> V_205 , V_197 , V_99 ) ;
if ( V_42 ) {
F_7 ( 3 , L_96 ) ;
return - V_206 ;
}
V_201 -> V_205 += V_99 ;
* V_198 += V_99 ;
if ( V_201 -> V_205 == V_201 -> V_13 || ( ! V_186 && V_185 -> V_191 ) ) {
struct V_1 * V_203 = V_4 -> V_33 [ V_23 ] ;
if ( V_186 && V_185 -> V_190 && V_185 -> V_204 == 1 ) {
F_7 ( 3 , L_97 ) ;
return F_99 ( V_4 ) ;
}
V_203 -> V_14 [ 0 ] . V_132 = V_201 -> V_205 ;
if ( V_144 )
V_203 -> V_207 = F_110 () ;
V_42 = F_70 ( V_4 , V_23 , NULL ) ;
F_7 ( 5 , L_98 , V_42 ) ;
if ( V_42 )
return V_42 ;
V_201 -> V_205 = 0 ;
V_201 -> V_194 = 1 ;
V_201 -> V_13 = F_105 ( V_4 -> V_33 [ V_23 ] , 0 ) ;
V_185 -> V_208 += 1 ;
if ( V_185 -> V_195 < V_4 -> V_38 )
V_185 -> V_195 ++ ;
V_185 -> V_196 = V_185 -> V_195 ;
}
if ( V_42 == 0 )
V_42 = V_99 ;
return V_42 ;
}
T_2 F_111 ( struct V_3 * V_4 , char T_3 * V_197 , T_2 V_99 ,
T_4 * V_198 , int V_145 )
{
return F_106 ( V_4 , V_197 , V_99 , V_198 , V_145 , 1 ) ;
}
T_2 F_112 ( struct V_3 * V_4 , const char T_3 * V_197 , T_2 V_99 ,
T_4 * V_198 , int V_145 )
{
return F_106 ( V_4 , ( char T_3 * ) V_197 , V_99 ,
V_198 , V_145 , 0 ) ;
}
static int F_113 ( void * V_197 )
{
struct V_3 * V_4 = V_197 ;
struct V_209 * V_210 = V_4 -> V_210 ;
bool V_144 = false ;
unsigned V_211 = 0 ;
unsigned V_23 = 0 ;
int V_42 = 0 ;
if ( V_4 -> V_7 ) {
V_211 = V_4 -> V_38 ;
V_144 = V_4 -> V_144 ;
}
F_114 () ;
for (; ; ) {
struct V_1 * V_2 ;
if ( V_211 ) {
V_2 = V_4 -> V_33 [ V_23 ++ ] ;
V_211 -- ;
} else {
F_73 ( V_4 , V_149 , V_4 ) ;
if ( ! V_210 -> V_212 )
V_42 = F_81 ( V_4 , & V_23 , NULL , 0 ) ;
F_73 ( V_4 , V_148 , V_4 ) ;
F_7 ( 5 , L_99 , V_42 ) ;
if ( ! V_42 )
V_2 = V_4 -> V_33 [ V_23 ] ;
}
if ( V_42 || V_210 -> V_212 )
break;
F_115 () ;
if ( V_2 -> V_45 != V_117 )
if ( V_210 -> V_213 ( V_2 , V_210 -> V_214 ) )
break;
F_73 ( V_4 , V_149 , V_4 ) ;
if ( V_144 )
V_2 -> V_207 = F_110 () ; ;
if ( ! V_210 -> V_212 )
V_42 = F_70 ( V_4 , V_2 -> V_23 , NULL ) ;
F_73 ( V_4 , V_148 , V_4 ) ;
if ( V_42 || V_210 -> V_212 )
break;
}
while ( ! F_116 () ) {
F_117 ( V_215 ) ;
F_118 () ;
}
return 0 ;
}
int F_119 ( struct V_3 * V_4 , T_5 V_213 , void * V_214 ,
const char * V_216 )
{
struct V_209 * V_210 ;
int V_42 = 0 ;
if ( V_4 -> V_210 )
return - V_98 ;
if ( F_120 ( V_4 ) )
return - V_98 ;
if ( F_45 ( V_4 -> V_185 ) )
return - V_98 ;
V_210 = F_14 ( sizeof( * V_210 ) , V_44 ) ;
if ( V_210 == NULL )
return - V_22 ;
V_210 -> V_213 = V_213 ;
V_210 -> V_214 = V_214 ;
V_42 = F_102 ( V_4 , ! V_4 -> V_7 ) ;
F_7 ( 3 , L_100 , V_42 ) ;
if ( V_42 )
goto V_217;
V_4 -> V_210 = V_210 ;
V_210 -> V_218 = F_121 ( F_113 , V_4 , L_101 , V_216 ) ;
if ( F_61 ( V_210 -> V_218 ) ) {
V_42 = F_58 ( V_210 -> V_218 ) ;
V_210 -> V_218 = NULL ;
goto V_219;
}
return 0 ;
V_219:
F_99 ( V_4 ) ;
V_217:
F_15 ( V_210 ) ;
return V_42 ;
}
int F_122 ( struct V_3 * V_4 )
{
struct V_209 * V_210 = V_4 -> V_210 ;
int V_131 ;
if ( V_210 == NULL )
return 0 ;
V_210 -> V_212 = true ;
F_87 ( V_4 ) ;
V_131 = F_123 ( V_210 -> V_218 ) ;
F_99 ( V_4 ) ;
V_210 -> V_218 = NULL ;
F_15 ( V_210 ) ;
V_4 -> V_210 = NULL ;
return V_131 ;
}
