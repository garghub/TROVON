static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
void * V_10 ;
int V_11 ;
int V_12 = - V_13 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
unsigned long V_15 = F_2 ( V_2 -> V_16 [ V_11 ] . V_17 ) ;
V_10 = F_3 ( V_2 , V_18 ,
V_4 -> V_19 [ V_11 ] ? : V_4 -> V_20 ,
V_4 -> V_21 , V_15 , V_6 , V_4 -> V_22 ) ;
if ( F_4 ( V_10 ) ) {
if ( V_10 )
V_12 = F_5 ( V_10 ) ;
goto free;
}
V_2 -> V_16 [ V_11 ] . V_10 = V_10 ;
}
return 0 ;
free:
for (; V_11 > 0 ; -- V_11 ) {
F_6 ( V_2 , V_23 , V_2 -> V_16 [ V_11 - 1 ] . V_10 ) ;
V_2 -> V_16 [ V_11 - 1 ] . V_10 = NULL ;
}
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
F_6 ( V_2 , V_23 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
V_2 -> V_16 [ V_11 ] . V_10 = NULL ;
F_8 ( 3 , L_1 , V_11 , V_2 -> V_24 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
if ( V_2 -> V_16 [ V_11 ] . V_10 )
F_6 ( V_2 , V_25 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
V_2 -> V_16 [ V_11 ] . V_10 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( ! V_27 -> V_10 )
return;
if ( V_27 -> V_28 )
F_6 ( V_2 , V_29 , V_27 -> V_10 ) ;
F_6 ( V_2 , V_30 , V_27 -> V_10 ) ;
F_11 ( V_27 -> V_31 ) ;
V_27 -> V_10 = NULL ;
V_27 -> V_31 = NULL ;
V_27 -> V_28 = 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 )
F_10 ( V_2 , & V_2 -> V_16 [ V_11 ] ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
unsigned long V_32 = 0 ;
if ( V_2 -> V_24 ) {
struct V_1 * V_33 = V_4 -> V_34 [ V_2 -> V_24 - 1 ] ;
struct V_26 * V_27 = & V_33 -> V_16 [ V_33 -> V_14 - 1 ] ;
V_32 = F_2 ( V_27 -> V_35 . V_36 + V_27 -> V_17 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
V_2 -> V_16 [ V_11 ] . V_35 . V_36 = V_32 ;
F_8 ( 3 , L_2 ,
V_2 -> V_24 , V_11 , V_32 ) ;
V_32 += V_2 -> V_16 [ V_11 ] . V_17 ;
V_32 = F_2 ( V_32 ) ;
}
}
static int F_14 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int V_39 , unsigned int V_14 ,
const unsigned V_40 [ V_41 ] )
{
unsigned int V_42 , V_11 ;
struct V_1 * V_2 ;
int V_12 ;
for ( V_42 = 0 ; V_42 < V_39 ; ++ V_42 ) {
V_2 = F_15 ( V_4 -> V_43 , V_44 ) ;
if ( ! V_2 ) {
F_8 ( 1 , L_3 ) ;
break;
}
V_2 -> V_45 = V_46 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_24 = V_4 -> V_39 + V_42 ;
V_2 -> type = V_4 -> type ;
V_2 -> V_38 = V_38 ;
for ( V_11 = 0 ; V_11 < V_14 ; ++ V_11 ) {
V_2 -> V_16 [ V_11 ] . V_17 = V_40 [ V_11 ] ;
V_2 -> V_16 [ V_11 ] . V_47 = V_40 [ V_11 ] ;
}
V_4 -> V_34 [ V_2 -> V_24 ] = V_2 ;
if ( V_38 == V_48 ) {
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_4 ,
V_42 ) ;
V_4 -> V_34 [ V_2 -> V_24 ] = NULL ;
F_16 ( V_2 ) ;
break;
}
F_13 ( V_2 ) ;
V_12 = F_17 ( V_2 , V_49 , V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_5 ,
V_42 , V_2 ) ;
F_7 ( V_2 ) ;
V_4 -> V_34 [ V_2 -> V_24 ] = NULL ;
F_16 ( V_2 ) ;
break;
}
}
}
F_8 ( 1 , L_6 ,
V_42 , V_14 ) ;
return V_42 ;
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_50 )
{
unsigned int V_42 ;
struct V_1 * V_2 ;
for ( V_42 = V_4 -> V_39 - V_50 ; V_42 < V_4 -> V_39 ;
++ V_42 ) {
V_2 = V_4 -> V_34 [ V_42 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_38 == V_48 )
F_7 ( V_2 ) ;
else if ( V_4 -> V_38 == V_51 )
F_12 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
}
static int F_19 ( struct V_3 * V_4 , unsigned int V_50 )
{
unsigned int V_42 ;
for ( V_42 = V_4 -> V_39 - V_50 ; V_42 < V_4 -> V_39 ;
++ V_42 ) {
if ( V_4 -> V_34 [ V_42 ] == NULL )
continue;
if ( V_4 -> V_34 [ V_42 ] -> V_45 == V_52 ) {
F_8 ( 1 , L_7 ) ;
return - V_53 ;
}
}
for ( V_42 = V_4 -> V_39 - V_50 ; V_42 < V_4 -> V_39 ;
++ V_42 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_42 ] ;
if ( V_2 && V_2 -> V_16 [ 0 ] . V_10 )
F_20 ( V_2 , V_54 , V_2 ) ;
}
F_18 ( V_4 , V_50 ) ;
#ifdef F_21
if ( V_4 -> V_39 ) {
bool V_55 = V_4 -> V_56 != V_4 -> V_57 ||
V_4 -> V_58 != V_4 -> V_59 ;
if ( V_55 || V_60 ) {
F_22 ( L_8 , V_4 ,
V_55 ? L_9 : L_10 ) ;
F_22 ( L_11 ,
V_4 -> V_61 , V_4 -> V_56 ,
V_4 -> V_57 ) ;
F_22 ( L_12 ,
V_4 -> V_58 , V_4 -> V_59 ) ;
}
V_4 -> V_61 = 0 ;
V_4 -> V_58 = 0 ;
V_4 -> V_59 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_57 = 0 ;
}
for ( V_42 = 0 ; V_42 < V_4 -> V_39 ; ++ V_42 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_42 ] ;
bool V_55 = V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ||
V_2 -> V_74 != V_2 -> V_75 ||
V_2 -> V_76 != V_2 -> V_77 ;
if ( V_55 || V_60 ) {
F_22 ( L_13 ,
V_4 , V_42 , V_55 ? L_9 : L_10 ) ;
F_22 ( L_14 ,
V_2 -> V_76 , V_2 -> V_77 ,
V_2 -> V_74 , V_2 -> V_75 ) ;
F_22 ( L_15 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
F_22 ( L_16 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_64 , V_2 -> V_65 ,
V_2 -> V_78 ) ;
F_22 ( L_17 ,
V_2 -> V_66 , V_2 -> V_67 ) ;
F_22 ( L_18 ,
V_2 -> V_68 , V_2 -> V_69 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_22 ( L_19 ,
V_2 -> V_79 ,
V_2 -> V_80 ,
V_2 -> V_81 ,
V_2 -> V_82 ) ;
}
}
#endif
for ( V_42 = V_4 -> V_39 - V_50 ; V_42 < V_4 -> V_39 ;
++ V_42 ) {
F_16 ( V_4 -> V_34 [ V_42 ] ) ;
V_4 -> V_34 [ V_42 ] = NULL ;
}
V_4 -> V_39 -= V_50 ;
if ( ! V_4 -> V_39 ) {
V_4 -> V_38 = 0 ;
F_23 ( & V_4 -> V_83 ) ;
}
return 0 ;
}
bool F_24 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
void * V_10 = V_2 -> V_16 [ V_11 ] . V_10 ;
if ( V_10 && F_25 ( V_2 , V_84 , V_10 ) > 1 )
return true ;
}
return false ;
}
static bool F_26 ( struct V_3 * V_4 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_39 ; ++ V_42 ) {
if ( F_24 ( V_4 , V_4 -> V_34 [ V_42 ] ) )
return true ;
}
return false ;
}
void F_27 ( struct V_3 * V_4 , unsigned int V_24 , void * V_85 )
{
F_28 ( V_4 , V_86 , V_4 -> V_34 [ V_24 ] , V_85 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_88 ) || ! V_4 -> V_89 -> V_90 ||
! V_4 -> V_89 -> V_25 )
return - V_91 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_92 ) || ! V_4 -> V_89 -> V_18 ||
! V_4 -> V_89 -> V_23 || ! V_4 -> V_89 -> V_93 )
return - V_91 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_87 & V_94 ) || ! V_4 -> V_89 -> V_95 ||
! V_4 -> V_89 -> V_30 || ! V_4 -> V_89 -> V_96 ||
! V_4 -> V_89 -> V_29 )
return - V_91 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_37 V_38 , unsigned int type )
{
if ( V_38 != V_48 && V_38 != V_97 &&
V_38 != V_51 ) {
F_8 ( 1 , L_20 ) ;
return - V_91 ;
}
if ( type != V_4 -> type ) {
F_8 ( 1 , L_21 ) ;
return - V_91 ;
}
if ( V_38 == V_48 && F_30 ( V_4 ) ) {
F_8 ( 1 , L_22 ) ;
return - V_91 ;
}
if ( V_38 == V_97 && F_29 ( V_4 ) ) {
F_8 ( 1 , L_23 ) ;
return - V_91 ;
}
if ( V_38 == V_51 && F_31 ( V_4 ) ) {
F_8 ( 1 , L_24 ) ;
return - V_91 ;
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_25 ) ;
return - V_98 ;
}
return 0 ;
}
int F_34 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int * V_99 )
{
unsigned int V_39 , V_100 , V_14 = 0 ;
unsigned V_40 [ V_41 ] = { } ;
int V_12 ;
if ( V_4 -> V_101 ) {
F_8 ( 1 , L_26 ) ;
return - V_98 ;
}
if ( * V_99 == 0 || V_4 -> V_39 != 0 || V_4 -> V_38 != V_38 ) {
F_35 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_38 == V_48 && F_26 ( V_4 ) ) {
F_36 ( & V_4 -> V_102 ) ;
F_8 ( 1 , L_27 ) ;
return - V_98 ;
}
F_37 ( V_4 ) ;
V_12 = F_19 ( V_4 , V_4 -> V_39 ) ;
F_36 ( & V_4 -> V_102 ) ;
if ( V_12 )
return V_12 ;
if ( * V_99 == 0 )
return 0 ;
}
V_39 = F_38 (unsigned int, *count, VB2_MAX_FRAME) ;
V_39 = F_39 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_19 , 0 , sizeof( V_4 -> V_19 ) ) ;
V_4 -> V_38 = V_38 ;
V_12 = F_40 ( V_4 , V_103 , V_4 , & V_39 , & V_14 ,
V_40 , V_4 -> V_19 ) ;
if ( V_12 )
return V_12 ;
V_100 =
F_14 ( V_4 , V_38 , V_39 , V_14 , V_40 ) ;
if ( V_100 == 0 ) {
F_8 ( 1 , L_28 ) ;
return - V_13 ;
}
if ( V_100 < V_4 -> V_104 )
V_12 = - V_13 ;
if ( ! V_12 && V_100 < V_39 ) {
V_39 = V_100 ;
V_14 = 0 ;
V_12 = F_40 ( V_4 , V_103 , V_4 , & V_39 ,
& V_14 , V_40 , V_4 -> V_19 ) ;
if ( ! V_12 && V_100 < V_39 )
V_12 = - V_13 ;
}
F_35 ( & V_4 -> V_102 ) ;
V_4 -> V_39 = V_100 ;
if ( V_12 < 0 ) {
F_19 ( V_4 , V_100 ) ;
F_36 ( & V_4 -> V_102 ) ;
return V_12 ;
}
F_36 ( & V_4 -> V_102 ) ;
* V_99 = V_100 ;
V_4 -> V_105 = ! V_4 -> V_7 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int * V_99 , unsigned V_106 ,
const unsigned V_107 [] )
{
unsigned int V_14 = 0 , V_39 , V_100 ;
unsigned V_40 [ V_41 ] = { } ;
int V_12 ;
if ( V_4 -> V_39 == V_108 ) {
F_8 ( 1 , L_29 ) ;
return - V_109 ;
}
if ( ! V_4 -> V_39 ) {
memset ( V_4 -> V_19 , 0 , sizeof( V_4 -> V_19 ) ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_105 = ! V_4 -> V_7 ;
}
V_39 = F_42 ( * V_99 , V_108 - V_4 -> V_39 ) ;
if ( V_106 && V_107 ) {
V_14 = V_106 ;
memcpy ( V_40 , V_107 , sizeof( V_40 ) ) ;
}
V_12 = F_40 ( V_4 , V_103 , V_4 , & V_39 ,
& V_14 , V_40 , V_4 -> V_19 ) ;
if ( V_12 )
return V_12 ;
V_100 = F_14 ( V_4 , V_38 , V_39 ,
V_14 , V_40 ) ;
if ( V_100 == 0 ) {
F_8 ( 1 , L_28 ) ;
return - V_13 ;
}
if ( V_100 < V_39 ) {
V_39 = V_100 ;
V_12 = F_40 ( V_4 , V_103 , V_4 , & V_39 ,
& V_14 , V_40 , V_4 -> V_19 ) ;
if ( ! V_12 && V_100 < V_39 )
V_12 = - V_13 ;
}
F_35 ( & V_4 -> V_102 ) ;
V_4 -> V_39 += V_100 ;
if ( V_12 < 0 ) {
F_19 ( V_4 , V_100 ) ;
F_36 ( & V_4 -> V_102 ) ;
return - V_13 ;
}
F_36 ( & V_4 -> V_102 ) ;
* V_99 = V_100 ;
return 0 ;
}
void * F_43 ( struct V_1 * V_2 , unsigned int V_110 )
{
if ( V_110 >= V_2 -> V_14 || ! V_2 -> V_16 [ V_110 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_111 , V_2 -> V_16 [ V_110 ] . V_10 ) ;
}
void * F_44 ( struct V_1 * V_2 , unsigned int V_110 )
{
if ( V_110 >= V_2 -> V_14 || ! V_2 -> V_16 [ V_110 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_112 , V_2 -> V_16 [ V_110 ] . V_10 ) ;
}
void F_45 ( struct V_1 * V_2 , enum V_113 V_45 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_114 ;
unsigned int V_11 ;
if ( F_46 ( V_2 -> V_45 != V_115 ) )
return;
if ( F_46 ( V_45 != V_116 &&
V_45 != V_117 &&
V_45 != V_118 &&
V_45 != V_119 ) )
V_45 = V_117 ;
#ifdef F_21
V_2 -> V_73 ++ ;
#endif
F_8 ( 4 , L_30 ,
V_2 -> V_24 , V_45 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 )
F_6 ( V_2 , V_120 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
F_47 ( & V_4 -> V_121 , V_114 ) ;
if ( V_45 == V_118 ||
V_45 == V_119 ) {
V_2 -> V_45 = V_118 ;
} else {
F_48 ( & V_2 -> V_122 , & V_4 -> V_123 ) ;
V_2 -> V_45 = V_45 ;
}
F_49 ( & V_4 -> V_124 ) ;
F_50 ( & V_4 -> V_121 , V_114 ) ;
F_51 ( V_4 , V_2 ) ;
switch ( V_45 ) {
case V_118 :
return;
case V_119 :
if ( V_4 -> V_125 )
F_52 ( V_2 ) ;
return;
default:
F_53 ( & V_4 -> V_126 ) ;
break;
}
}
void F_54 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_114 ;
F_47 ( & V_4 -> V_121 , V_114 ) ;
F_55 (vb, &q->done_list, done_entry)
V_2 -> V_45 = V_117 ;
F_50 ( & V_4 -> V_121 , V_114 ) ;
}
static int F_56 ( struct V_1 * V_2 , const void * V_85 )
{
int V_12 = 0 ;
if ( V_85 )
V_12 = F_57 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_2 -> V_16 ) ;
return V_12 ? V_12 : F_17 ( V_2 , V_128 , V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_26 V_16 [ V_41 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_12 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_129 = V_2 -> V_16 [ 0 ] . V_10 == NULL ;
memset ( V_16 , 0 , sizeof( V_16 [ 0 ] ) * V_2 -> V_14 ) ;
if ( V_85 ) {
V_12 = F_57 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_16 ) ;
if ( V_12 )
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
if ( V_2 -> V_16 [ V_11 ] . V_35 . V_130 &&
V_2 -> V_16 [ V_11 ] . V_35 . V_130 == V_16 [ V_11 ] . V_35 . V_130
&& V_2 -> V_16 [ V_11 ] . V_17 == V_16 [ V_11 ] . V_17 )
continue;
F_8 ( 3 , L_31 ,
V_11 ) ;
if ( V_16 [ V_11 ] . V_17 < V_2 -> V_16 [ V_11 ] . V_47 ) {
F_8 ( 1 , L_32 ,
V_16 [ V_11 ] . V_17 ,
V_2 -> V_16 [ V_11 ] . V_47 ,
V_11 ) ;
V_12 = - V_91 ;
goto V_131;
}
if ( V_2 -> V_16 [ V_11 ] . V_10 ) {
if ( ! V_129 ) {
V_129 = true ;
F_20 ( V_2 , V_54 , V_2 ) ;
}
F_6 ( V_2 , V_25 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
}
V_2 -> V_16 [ V_11 ] . V_10 = NULL ;
V_2 -> V_16 [ V_11 ] . V_132 = 0 ;
V_2 -> V_16 [ V_11 ] . V_17 = 0 ;
V_2 -> V_16 [ V_11 ] . V_35 . V_130 = 0 ;
V_2 -> V_16 [ V_11 ] . V_133 = 0 ;
V_10 = F_3 ( V_2 , V_90 ,
V_4 -> V_19 [ V_11 ] ? : V_4 -> V_20 ,
V_16 [ V_11 ] . V_35 . V_130 ,
V_16 [ V_11 ] . V_17 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
F_8 ( 1 , L_33 ,
V_11 ) ;
V_12 = F_5 ( V_10 ) ;
goto V_131;
}
V_2 -> V_16 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
V_2 -> V_16 [ V_11 ] . V_132 = V_16 [ V_11 ] . V_132 ;
V_2 -> V_16 [ V_11 ] . V_17 = V_16 [ V_11 ] . V_17 ;
V_2 -> V_16 [ V_11 ] . V_35 . V_130 = V_16 [ V_11 ] . V_35 . V_130 ;
V_2 -> V_16 [ V_11 ] . V_133 = V_16 [ V_11 ] . V_133 ;
}
if ( V_129 ) {
V_12 = F_17 ( V_2 , V_49 , V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_34 ) ;
goto V_131;
}
}
V_12 = F_17 ( V_2 , V_128 , V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_35 ) ;
F_20 ( V_2 , V_54 , V_2 ) ;
goto V_131;
}
return 0 ;
V_131:
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
if ( V_2 -> V_16 [ V_11 ] . V_10 )
F_6 ( V_2 , V_25 ,
V_2 -> V_16 [ V_11 ] . V_10 ) ;
V_2 -> V_16 [ V_11 ] . V_10 = NULL ;
V_2 -> V_16 [ V_11 ] . V_35 . V_130 = 0 ;
V_2 -> V_16 [ V_11 ] . V_17 = 0 ;
}
return V_12 ;
}
static int F_59 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_26 V_16 [ V_41 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_12 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_129 = V_2 -> V_16 [ 0 ] . V_10 == NULL ;
memset ( V_16 , 0 , sizeof( V_16 [ 0 ] ) * V_2 -> V_14 ) ;
if ( V_85 ) {
V_12 = F_57 ( V_2 -> V_3 , V_127 ,
V_2 , V_85 , V_16 ) ;
if ( V_12 )
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
struct V_134 * V_31 = F_60 ( V_16 [ V_11 ] . V_35 . V_135 ) ;
if ( F_61 ( V_31 ) ) {
F_8 ( 1 , L_36 ,
V_11 ) ;
V_12 = - V_91 ;
goto V_131;
}
if ( V_16 [ V_11 ] . V_17 == 0 )
V_16 [ V_11 ] . V_17 = V_31 -> V_15 ;
if ( V_16 [ V_11 ] . V_17 < V_2 -> V_16 [ V_11 ] . V_47 ) {
F_8 ( 1 , L_37 ,
V_16 [ V_11 ] . V_17 , V_11 ,
V_2 -> V_16 [ V_11 ] . V_47 ) ;
F_11 ( V_31 ) ;
V_12 = - V_91 ;
goto V_131;
}
if ( V_31 == V_2 -> V_16 [ V_11 ] . V_31 &&
V_2 -> V_16 [ V_11 ] . V_17 == V_16 [ V_11 ] . V_17 ) {
F_11 ( V_31 ) ;
continue;
}
F_8 ( 1 , L_38 , V_11 ) ;
if ( ! V_129 ) {
V_129 = true ;
F_20 ( V_2 , V_54 , V_2 ) ;
}
F_10 ( V_2 , & V_2 -> V_16 [ V_11 ] ) ;
V_2 -> V_16 [ V_11 ] . V_132 = 0 ;
V_2 -> V_16 [ V_11 ] . V_17 = 0 ;
V_2 -> V_16 [ V_11 ] . V_35 . V_135 = 0 ;
V_2 -> V_16 [ V_11 ] . V_133 = 0 ;
V_10 = F_3 ( V_2 , V_95 ,
V_4 -> V_19 [ V_11 ] ? : V_4 -> V_20 ,
V_31 , V_16 [ V_11 ] . V_17 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
F_8 ( 1 , L_39 ) ;
V_12 = F_5 ( V_10 ) ;
F_11 ( V_31 ) ;
goto V_131;
}
V_2 -> V_16 [ V_11 ] . V_31 = V_31 ;
V_2 -> V_16 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
V_12 = F_25 ( V_2 , V_96 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
if ( V_12 ) {
F_8 ( 1 , L_40 ,
V_11 ) ;
goto V_131;
}
V_2 -> V_16 [ V_11 ] . V_28 = 1 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
V_2 -> V_16 [ V_11 ] . V_132 = V_16 [ V_11 ] . V_132 ;
V_2 -> V_16 [ V_11 ] . V_17 = V_16 [ V_11 ] . V_17 ;
V_2 -> V_16 [ V_11 ] . V_35 . V_135 = V_16 [ V_11 ] . V_35 . V_135 ;
V_2 -> V_16 [ V_11 ] . V_133 = V_16 [ V_11 ] . V_133 ;
}
if ( V_129 ) {
V_12 = F_17 ( V_2 , V_49 , V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_34 ) ;
goto V_131;
}
}
V_12 = F_17 ( V_2 , V_128 , V_2 ) ;
if ( V_12 ) {
F_8 ( 1 , L_35 ) ;
F_20 ( V_2 , V_54 , V_2 ) ;
goto V_131;
}
return 0 ;
V_131:
F_12 ( V_2 ) ;
return V_12 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
V_2 -> V_45 = V_115 ;
F_62 ( & V_4 -> V_124 ) ;
F_63 ( V_4 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 )
F_6 ( V_2 , V_136 , V_2 -> V_16 [ V_11 ] . V_10 ) ;
F_20 ( V_2 , V_137 , V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_85 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_12 ;
if ( V_4 -> error ) {
F_8 ( 1 , L_41 ) ;
return - V_138 ;
}
V_2 -> V_45 = V_52 ;
switch ( V_4 -> V_38 ) {
case V_48 :
V_12 = F_56 ( V_2 , V_85 ) ;
break;
case V_97 :
V_12 = F_58 ( V_2 , V_85 ) ;
break;
case V_51 :
V_12 = F_59 ( V_2 , V_85 ) ;
break;
default:
F_65 ( 1 , L_42 ) ;
V_12 = - V_91 ;
}
if ( V_12 )
F_8 ( 1 , L_43 , V_12 ) ;
V_2 -> V_45 = V_12 ? V_46 : V_139 ;
return V_12 ;
}
int F_66 ( struct V_3 * V_4 , unsigned int V_24 , void * V_85 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = V_4 -> V_34 [ V_24 ] ;
if ( V_2 -> V_45 != V_46 ) {
F_8 ( 1 , L_44 ,
V_2 -> V_45 ) ;
return - V_91 ;
}
V_12 = F_64 ( V_2 , V_85 ) ;
if ( V_12 )
return V_12 ;
F_28 ( V_4 , V_86 , V_2 , V_85 ) ;
F_8 ( 1 , L_45 , V_2 -> V_24 ) ;
return V_12 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_12 ;
F_55 (vb, &q->queued_list, queued_entry)
F_52 ( V_2 ) ;
V_4 -> V_125 = 1 ;
V_12 = F_40 ( V_4 , V_140 , V_4 ,
F_68 ( & V_4 -> V_124 ) ) ;
if ( ! V_12 )
return 0 ;
V_4 -> V_125 = 0 ;
F_8 ( 1 , L_46 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_124 ) ) ) {
unsigned V_141 ;
for ( V_141 = 0 ; V_141 < V_4 -> V_39 ; ++ V_141 ) {
V_2 = V_4 -> V_34 [ V_141 ] ;
if ( V_2 -> V_45 == V_115 )
F_45 ( V_2 , V_118 ) ;
}
F_46 ( F_68 ( & V_4 -> V_124 ) ) ;
}
F_46 ( ! F_69 ( & V_4 -> V_123 ) ) ;
return V_12 ;
}
int F_70 ( struct V_3 * V_4 , unsigned int V_24 , void * V_85 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = V_4 -> V_34 [ V_24 ] ;
switch ( V_2 -> V_45 ) {
case V_46 :
V_12 = F_64 ( V_2 , V_85 ) ;
if ( V_12 )
return V_12 ;
break;
case V_139 :
break;
case V_52 :
F_8 ( 1 , L_47 ) ;
return - V_91 ;
default:
F_8 ( 1 , L_44 , V_2 -> V_45 ) ;
return - V_91 ;
}
F_48 ( & V_2 -> V_142 , & V_4 -> V_83 ) ;
V_4 -> V_143 ++ ;
V_4 -> V_105 = false ;
V_2 -> V_45 = V_118 ;
if ( V_85 )
F_28 ( V_4 , V_144 , V_2 , V_85 ) ;
F_71 ( V_4 , V_2 ) ;
if ( V_4 -> V_125 )
F_52 ( V_2 ) ;
if ( V_85 )
F_28 ( V_4 , V_86 , V_2 , V_85 ) ;
if ( V_4 -> V_101 && ! V_4 -> V_125 &&
V_4 -> V_143 >= V_4 -> V_104 ) {
V_12 = F_67 ( V_4 ) ;
if ( V_12 )
return V_12 ;
}
F_8 ( 1 , L_48 , V_2 -> V_24 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int V_145 )
{
for (; ; ) {
int V_12 ;
if ( ! V_4 -> V_101 ) {
F_8 ( 1 , L_49 ) ;
return - V_91 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_50 ) ;
return - V_138 ;
}
if ( V_4 -> V_146 ) {
F_8 ( 3 , L_51 ) ;
return - V_147 ;
}
if ( ! F_69 ( & V_4 -> V_123 ) ) {
break;
}
if ( V_145 ) {
F_8 ( 1 , L_52 ) ;
return - V_53 ;
}
F_73 ( V_4 , V_148 , V_4 ) ;
F_8 ( 3 , L_53 ) ;
V_12 = F_74 ( V_4 -> V_126 ,
! F_69 ( & V_4 -> V_123 ) || ! V_4 -> V_101 ||
V_4 -> error ) ;
F_73 ( V_4 , V_149 , V_4 ) ;
if ( V_12 ) {
F_8 ( 1 , L_54 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
void * V_85 , int V_145 )
{
unsigned long V_114 ;
int V_12 = 0 ;
V_12 = F_72 ( V_4 , V_145 ) ;
if ( V_12 )
return V_12 ;
F_47 ( & V_4 -> V_121 , V_114 ) ;
* V_2 = F_76 ( & V_4 -> V_123 , struct V_1 , V_122 ) ;
if ( V_85 )
V_12 = F_57 ( V_4 , V_150 , * V_2 , V_85 ) ;
if ( ! V_12 )
F_77 ( & ( * V_2 ) -> V_122 ) ;
F_50 ( & V_4 -> V_121 , V_114 ) ;
return V_12 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_101 ) {
F_8 ( 1 , L_49 ) ;
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
if ( V_4 -> V_38 == V_51 )
for ( V_141 = 0 ; V_141 < V_2 -> V_14 ; ++ V_141 ) {
if ( ! V_2 -> V_16 [ V_141 ] . V_28 )
continue;
F_6 ( V_2 , V_29 , V_2 -> V_16 [ V_141 ] . V_10 ) ;
V_2 -> V_16 [ V_141 ] . V_28 = 0 ;
}
}
int F_81 ( struct V_3 * V_4 , unsigned int * V_151 , void * V_85 ,
bool V_145 )
{
struct V_1 * V_2 = NULL ;
int V_12 ;
V_12 = F_75 ( V_4 , & V_2 , V_85 , V_145 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_2 -> V_45 ) {
case V_116 :
F_8 ( 3 , L_55 ) ;
break;
case V_117 :
F_8 ( 3 , L_56 ) ;
break;
default:
F_8 ( 1 , L_57 ) ;
return - V_91 ;
}
F_20 ( V_2 , V_152 , V_2 ) ;
if ( V_151 )
* V_151 = V_2 -> V_24 ;
if ( V_85 )
F_28 ( V_4 , V_86 , V_2 , V_85 ) ;
F_77 ( & V_2 -> V_142 ) ;
V_4 -> V_143 -- ;
F_82 ( V_4 , V_2 ) ;
F_80 ( V_2 ) ;
F_8 ( 1 , L_58 ,
V_2 -> V_24 , V_2 -> V_45 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
unsigned int V_141 ;
if ( V_4 -> V_125 )
F_73 ( V_4 , V_153 , V_4 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_124 ) ) ) {
for ( V_141 = 0 ; V_141 < V_4 -> V_39 ; ++ V_141 )
if ( V_4 -> V_34 [ V_141 ] -> V_45 == V_115 )
F_45 ( V_4 -> V_34 [ V_141 ] , V_117 ) ;
F_46 ( F_68 ( & V_4 -> V_124 ) ) ;
}
V_4 -> V_101 = 0 ;
V_4 -> V_125 = 0 ;
V_4 -> V_143 = 0 ;
V_4 -> error = 0 ;
F_23 ( & V_4 -> V_83 ) ;
F_23 ( & V_4 -> V_123 ) ;
F_83 ( & V_4 -> V_124 , 0 ) ;
F_84 ( & V_4 -> V_126 ) ;
for ( V_141 = 0 ; V_141 < V_4 -> V_39 ; ++ V_141 ) {
struct V_1 * V_2 = V_4 -> V_34 [ V_141 ] ;
if ( V_2 -> V_45 != V_46 ) {
V_2 -> V_45 = V_139 ;
F_20 ( V_2 , V_152 , V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
int F_85 ( struct V_3 * V_4 , unsigned int type )
{
int V_12 ;
if ( type != V_4 -> type ) {
F_8 ( 1 , L_59 ) ;
return - V_91 ;
}
if ( V_4 -> V_101 ) {
F_8 ( 3 , L_60 ) ;
return 0 ;
}
if ( ! V_4 -> V_39 ) {
F_8 ( 1 , L_61 ) ;
return - V_91 ;
}
if ( V_4 -> V_39 < V_4 -> V_104 ) {
F_8 ( 1 , L_62 ,
V_4 -> V_104 ) ;
return - V_91 ;
}
if ( V_4 -> V_143 >= V_4 -> V_104 ) {
V_12 = F_86 ( V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_67 ( V_4 ) ;
if ( V_12 ) {
F_37 ( V_4 ) ;
return V_12 ;
}
}
V_4 -> V_101 = 1 ;
F_8 ( 3 , L_63 ) ;
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
F_8 ( 1 , L_59 ) ;
return - V_91 ;
}
F_37 ( V_4 ) ;
V_4 -> V_105 = ! V_4 -> V_7 ;
V_4 -> V_146 = false ;
F_8 ( 3 , L_63 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_4 , unsigned long V_32 ,
unsigned int * V_154 , unsigned int * V_155 )
{
struct V_1 * V_2 ;
unsigned int V_42 , V_11 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_39 ; ++ V_42 ) {
V_2 = V_4 -> V_34 [ V_42 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_14 ; ++ V_11 ) {
if ( V_2 -> V_16 [ V_11 ] . V_35 . V_36 == V_32 ) {
* V_154 = V_42 ;
* V_155 = V_11 ;
return 0 ;
}
}
}
return - V_91 ;
}
int F_90 ( struct V_3 * V_4 , int * V_135 , unsigned int type ,
unsigned int V_24 , unsigned int V_11 , unsigned int V_114 )
{
struct V_1 * V_2 = NULL ;
struct V_26 * V_156 ;
int V_12 ;
struct V_134 * V_31 ;
if ( V_4 -> V_38 != V_48 ) {
F_8 ( 1 , L_64 ) ;
return - V_91 ;
}
if ( ! V_4 -> V_89 -> V_157 ) {
F_8 ( 1 , L_65 ) ;
return - V_91 ;
}
if ( V_114 & ~ ( V_158 | V_159 ) ) {
F_8 ( 1 , L_66 ) ;
return - V_91 ;
}
if ( type != V_4 -> type ) {
F_8 ( 1 , L_67 ) ;
return - V_91 ;
}
if ( V_24 >= V_4 -> V_39 ) {
F_8 ( 1 , L_68 ) ;
return - V_91 ;
}
V_2 = V_4 -> V_34 [ V_24 ] ;
if ( V_11 >= V_2 -> V_14 ) {
F_8 ( 1 , L_69 ) ;
return - V_91 ;
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_70 ) ;
return - V_98 ;
}
V_156 = & V_2 -> V_16 [ V_11 ] ;
V_31 = F_3 ( V_2 , V_157 , V_156 -> V_10 ,
V_114 & V_159 ) ;
if ( F_61 ( V_31 ) ) {
F_8 ( 1 , L_71 ,
V_24 , V_11 ) ;
return - V_91 ;
}
V_12 = F_91 ( V_31 , V_114 & ~ V_159 ) ;
if ( V_12 < 0 ) {
F_8 ( 3 , L_72 ,
V_24 , V_11 , V_12 ) ;
F_11 ( V_31 ) ;
return V_12 ;
}
F_8 ( 3 , L_73 ,
V_24 , V_11 , V_12 ) ;
* V_135 = V_12 ;
return 0 ;
}
int F_92 ( struct V_3 * V_4 , struct V_160 * V_161 )
{
unsigned long V_32 = V_161 -> V_162 << V_163 ;
struct V_1 * V_2 ;
unsigned int V_42 = 0 , V_11 = 0 ;
int V_12 ;
unsigned long V_17 ;
if ( V_4 -> V_38 != V_48 ) {
F_8 ( 1 , L_64 ) ;
return - V_91 ;
}
if ( ! ( V_161 -> V_164 & V_165 ) ) {
F_8 ( 1 , L_74 ) ;
return - V_91 ;
}
if ( V_4 -> V_7 ) {
if ( ! ( V_161 -> V_164 & V_166 ) ) {
F_8 ( 1 , L_75 ) ;
return - V_91 ;
}
} else {
if ( ! ( V_161 -> V_164 & V_167 ) ) {
F_8 ( 1 , L_76 ) ;
return - V_91 ;
}
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_77 ) ;
return - V_98 ;
}
V_12 = F_89 ( V_4 , V_32 , & V_42 , & V_11 ) ;
if ( V_12 )
return V_12 ;
V_2 = V_4 -> V_34 [ V_42 ] ;
V_17 = F_2 ( V_2 -> V_16 [ V_11 ] . V_17 ) ;
if ( V_17 < ( V_161 -> V_168 - V_161 -> V_169 ) ) {
F_8 ( 1 ,
L_78 ) ;
return - V_91 ;
}
F_35 ( & V_4 -> V_102 ) ;
V_12 = F_25 ( V_2 , V_93 , V_2 -> V_16 [ V_11 ] . V_10 , V_161 ) ;
F_36 ( & V_4 -> V_102 ) ;
if ( V_12 )
return V_12 ;
F_8 ( 3 , L_79 , V_42 , V_11 ) ;
return 0 ;
}
unsigned long F_93 ( struct V_3 * V_4 ,
unsigned long V_170 ,
unsigned long V_171 ,
unsigned long V_172 ,
unsigned long V_114 )
{
unsigned long V_32 = V_172 << V_163 ;
struct V_1 * V_2 ;
unsigned int V_42 , V_11 ;
void * V_111 ;
int V_12 ;
if ( V_4 -> V_38 != V_48 ) {
F_8 ( 1 , L_64 ) ;
return - V_91 ;
}
V_12 = F_89 ( V_4 , V_32 , & V_42 , & V_11 ) ;
if ( V_12 )
return V_12 ;
V_2 = V_4 -> V_34 [ V_42 ] ;
V_111 = F_43 ( V_2 , V_11 ) ;
return V_111 ? ( unsigned long ) V_111 : - V_91 ;
}
int F_94 ( struct V_3 * V_4 )
{
if ( F_46 ( ! V_4 ) ||
F_46 ( ! V_4 -> V_173 ) ||
F_46 ( ! V_4 -> V_89 ) ||
F_46 ( ! V_4 -> type ) ||
F_46 ( ! V_4 -> V_87 ) ||
F_46 ( ! V_4 -> V_173 -> V_103 ) ||
F_46 ( ! V_4 -> V_173 -> V_137 ) )
return - V_91 ;
F_23 ( & V_4 -> V_83 ) ;
F_23 ( & V_4 -> V_123 ) ;
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
F_37 ( V_4 ) ;
F_35 ( & V_4 -> V_102 ) ;
F_19 ( V_4 , V_4 -> V_39 ) ;
F_36 ( & V_4 -> V_102 ) ;
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
if ( V_4 -> V_39 == 0 && ! F_33 ( V_4 ) ) {
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
if ( V_4 -> V_7 && V_4 -> V_185 && V_4 -> V_143 < V_4 -> V_39 )
return V_179 | V_180 ;
if ( F_69 ( & V_4 -> V_123 ) ) {
if ( V_4 -> V_146 )
return V_177 | V_178 ;
F_104 ( V_174 , & V_4 -> V_126 , V_175 ) ;
}
F_47 ( & V_4 -> V_121 , V_114 ) ;
if ( ! F_69 ( & V_4 -> V_123 ) )
V_2 = F_76 ( & V_4 -> V_123 , struct V_1 ,
V_122 ) ;
F_50 ( & V_4 -> V_121 , V_114 ) ;
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
int V_141 , V_12 ;
unsigned int V_99 = 0 ;
if ( F_46 ( ( V_186 && ! ( V_4 -> V_87 & V_181 ) ) ||
( ! V_186 && ! ( V_4 -> V_87 & V_183 ) ) ) )
return - V_91 ;
if ( ! V_4 -> V_89 -> V_111 )
return - V_98 ;
if ( V_4 -> V_101 || V_4 -> V_39 > 0 )
return - V_98 ;
V_99 = 1 ;
F_8 ( 3 , L_80 ,
( V_186 ) ? L_81 : L_82 , V_99 , V_4 -> V_188 ,
V_4 -> V_189 ) ;
V_185 = F_15 ( sizeof( * V_185 ) , V_44 ) ;
if ( V_185 == NULL )
return - V_13 ;
V_185 -> V_190 = V_4 -> V_188 ;
V_185 -> V_191 = V_4 -> V_189 ;
V_185 -> V_99 = V_99 ;
V_185 -> V_38 = V_48 ;
V_185 -> type = V_4 -> type ;
V_4 -> V_185 = V_185 ;
V_12 = F_34 ( V_4 , V_185 -> V_38 , & V_185 -> V_99 ) ;
if ( V_12 )
goto V_192;
if ( V_4 -> V_34 [ 0 ] -> V_14 != 1 ) {
V_12 = - V_98 ;
goto V_193;
}
for ( V_141 = 0 ; V_141 < V_4 -> V_39 ; V_141 ++ ) {
V_185 -> V_34 [ V_141 ] . V_111 = F_43 ( V_4 -> V_34 [ V_141 ] , 0 ) ;
if ( V_185 -> V_34 [ V_141 ] . V_111 == NULL ) {
V_12 = - V_91 ;
goto V_193;
}
V_185 -> V_34 [ V_141 ] . V_15 = F_105 ( V_4 -> V_34 [ V_141 ] , 0 ) ;
}
if ( V_186 ) {
for ( V_141 = 0 ; V_141 < V_4 -> V_39 ; V_141 ++ ) {
V_12 = F_70 ( V_4 , V_141 , NULL ) ;
if ( V_12 )
goto V_193;
V_185 -> V_34 [ V_141 ] . V_194 = 1 ;
}
V_185 -> V_195 = V_4 -> V_39 ;
V_185 -> V_196 = V_4 -> V_39 ;
}
V_12 = F_85 ( V_4 , V_4 -> type ) ;
if ( V_12 )
goto V_193;
return V_12 ;
V_193:
V_185 -> V_99 = 0 ;
F_34 ( V_4 , V_185 -> V_38 , & V_185 -> V_99 ) ;
V_192:
V_4 -> V_185 = NULL ;
F_16 ( V_185 ) ;
return V_12 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_187 * V_185 = V_4 -> V_185 ;
if ( V_185 ) {
F_88 ( V_4 , V_4 -> type ) ;
V_4 -> V_185 = NULL ;
V_185 -> V_99 = 0 ;
F_34 ( V_4 , V_185 -> V_38 , & V_185 -> V_99 ) ;
F_16 ( V_185 ) ;
F_8 ( 3 , L_83 ) ;
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
unsigned V_24 ;
int V_12 ;
F_8 ( 3 , L_84 ,
V_186 ? L_81 : L_82 , ( long ) * V_198 , V_99 ,
V_199 ? L_85 : L_10 ) ;
if ( ! V_197 )
return - V_91 ;
if ( ! F_33 ( V_4 ) ) {
V_12 = F_102 ( V_4 , V_186 ) ;
F_8 ( 3 , L_86 , V_12 ) ;
if ( V_12 )
return V_12 ;
}
V_185 = V_4 -> V_185 ;
V_24 = V_185 -> V_196 ;
if ( V_24 >= V_4 -> V_39 ) {
struct V_1 * V_203 ;
V_12 = F_81 ( V_4 , & V_24 , NULL , V_199 ) ;
F_8 ( 5 , L_87 , V_12 ) ;
if ( V_12 )
return V_12 ;
V_185 -> V_204 += 1 ;
V_185 -> V_196 = V_24 ;
V_201 = & V_185 -> V_34 [ V_24 ] ;
V_203 = V_4 -> V_34 [ V_24 ] ;
V_201 -> V_205 = 0 ;
V_201 -> V_194 = 0 ;
V_201 -> V_15 = V_186 ? F_107 ( V_4 -> V_34 [ V_24 ] , 0 )
: F_105 ( V_4 -> V_34 [ V_24 ] , 0 ) ;
if ( V_202 && V_186 &&
V_203 -> V_16 [ 0 ] . V_133 < V_201 -> V_15 ) {
V_201 -> V_205 = V_203 -> V_16 [ 0 ] . V_133 ;
V_201 -> V_15 -= V_201 -> V_205 ;
}
} else {
V_201 = & V_185 -> V_34 [ V_24 ] ;
}
if ( V_201 -> V_205 + V_99 > V_201 -> V_15 ) {
V_99 = V_201 -> V_15 - V_201 -> V_205 ;
F_8 ( 5 , L_88 , V_99 ) ;
}
F_8 ( 3 , L_89 ,
V_99 , V_24 , V_201 -> V_205 ) ;
if ( V_186 )
V_12 = F_108 ( V_197 , V_201 -> V_111 + V_201 -> V_205 , V_99 ) ;
else
V_12 = F_109 ( V_201 -> V_111 + V_201 -> V_205 , V_197 , V_99 ) ;
if ( V_12 ) {
F_8 ( 3 , L_90 ) ;
return - V_206 ;
}
V_201 -> V_205 += V_99 ;
* V_198 += V_99 ;
if ( V_201 -> V_205 == V_201 -> V_15 || ( ! V_186 && V_185 -> V_191 ) ) {
struct V_1 * V_203 = V_4 -> V_34 [ V_24 ] ;
if ( V_186 && V_185 -> V_190 && V_185 -> V_204 == 1 ) {
F_8 ( 3 , L_91 ) ;
return F_99 ( V_4 ) ;
}
V_203 -> V_16 [ 0 ] . V_132 = V_201 -> V_205 ;
if ( V_144 )
V_203 -> V_207 = F_110 () ;
V_12 = F_70 ( V_4 , V_24 , NULL ) ;
F_8 ( 5 , L_92 , V_12 ) ;
if ( V_12 )
return V_12 ;
V_201 -> V_205 = 0 ;
V_201 -> V_194 = 1 ;
V_201 -> V_15 = F_105 ( V_4 -> V_34 [ V_24 ] , 0 ) ;
V_185 -> V_208 += 1 ;
if ( V_185 -> V_195 < V_4 -> V_39 )
V_185 -> V_195 ++ ;
V_185 -> V_196 = V_185 -> V_195 ;
}
if ( V_12 == 0 )
V_12 = V_99 ;
return V_12 ;
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
unsigned V_24 = 0 ;
int V_12 = 0 ;
if ( V_4 -> V_7 ) {
V_211 = V_4 -> V_39 ;
V_144 = V_4 -> V_144 ;
}
F_114 () ;
for (; ; ) {
struct V_1 * V_2 ;
if ( V_211 ) {
V_2 = V_4 -> V_34 [ V_24 ++ ] ;
V_211 -- ;
} else {
F_73 ( V_4 , V_149 , V_4 ) ;
if ( ! V_210 -> V_212 )
V_12 = F_81 ( V_4 , & V_24 , NULL , 0 ) ;
F_73 ( V_4 , V_148 , V_4 ) ;
F_8 ( 5 , L_93 , V_12 ) ;
if ( ! V_12 )
V_2 = V_4 -> V_34 [ V_24 ] ;
}
if ( V_12 || V_210 -> V_212 )
break;
F_115 () ;
if ( V_2 -> V_45 != V_117 )
if ( V_210 -> V_213 ( V_2 , V_210 -> V_214 ) )
break;
F_73 ( V_4 , V_149 , V_4 ) ;
if ( V_144 )
V_2 -> V_207 = F_110 () ; ;
if ( ! V_210 -> V_212 )
V_12 = F_70 ( V_4 , V_2 -> V_24 , NULL ) ;
F_73 ( V_4 , V_148 , V_4 ) ;
if ( V_12 || V_210 -> V_212 )
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
int V_12 = 0 ;
if ( V_4 -> V_210 )
return - V_98 ;
if ( F_120 ( V_4 ) )
return - V_98 ;
if ( F_46 ( V_4 -> V_185 ) )
return - V_98 ;
V_210 = F_15 ( sizeof( * V_210 ) , V_44 ) ;
if ( V_210 == NULL )
return - V_13 ;
V_210 -> V_213 = V_213 ;
V_210 -> V_214 = V_214 ;
V_12 = F_102 ( V_4 , ! V_4 -> V_7 ) ;
F_8 ( 3 , L_94 , V_12 ) ;
if ( V_12 )
goto V_217;
V_4 -> V_210 = V_210 ;
V_210 -> V_218 = F_121 ( F_113 , V_4 , L_95 , V_216 ) ;
if ( F_4 ( V_210 -> V_218 ) ) {
V_12 = F_5 ( V_210 -> V_218 ) ;
V_210 -> V_218 = NULL ;
goto V_219;
}
return 0 ;
V_219:
F_99 ( V_4 ) ;
V_217:
F_16 ( V_210 ) ;
return V_12 ;
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
F_16 ( V_210 ) ;
V_4 -> V_210 = NULL ;
return V_131 ;
}
