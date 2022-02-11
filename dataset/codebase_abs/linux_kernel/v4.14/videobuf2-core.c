static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
int V_6 ;
int V_7 = - V_8 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
unsigned long V_10 = F_2 ( V_2 -> V_11 [ V_6 ] . V_12 ) ;
V_5 = F_3 ( V_2 , V_13 ,
V_4 -> V_14 [ V_6 ] ? : V_4 -> V_15 ,
V_4 -> V_16 , V_10 , V_4 -> V_17 , V_4 -> V_18 ) ;
if ( F_4 ( V_5 ) ) {
if ( V_5 )
V_7 = F_5 ( V_5 ) ;
goto free;
}
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
return 0 ;
free:
for (; V_6 > 0 ; -- V_6 ) {
F_6 ( V_2 , V_19 , V_2 -> V_11 [ V_6 - 1 ] . V_5 ) ;
V_2 -> V_11 [ V_6 - 1 ] . V_5 = NULL ;
}
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
F_6 ( V_2 , V_19 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
F_8 ( 3 , L_1 , V_6 , V_2 -> V_20 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_6 ( V_2 , V_21 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
if ( ! V_23 -> V_5 )
return;
if ( V_23 -> V_24 )
F_6 ( V_2 , V_25 , V_23 -> V_5 ) ;
F_6 ( V_2 , V_26 , V_23 -> V_5 ) ;
F_11 ( V_23 -> V_27 ) ;
V_23 -> V_5 = NULL ;
V_23 -> V_27 = NULL ;
V_23 -> V_24 = 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 )
F_10 ( V_2 , & V_2 -> V_11 [ V_6 ] ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
unsigned long V_28 = 0 ;
if ( V_2 -> V_20 ) {
struct V_1 * V_29 = V_4 -> V_30 [ V_2 -> V_20 - 1 ] ;
struct V_22 * V_23 = & V_29 -> V_11 [ V_29 -> V_9 - 1 ] ;
V_28 = F_2 ( V_23 -> V_31 . V_32 + V_23 -> V_12 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
V_2 -> V_11 [ V_6 ] . V_31 . V_32 = V_28 ;
F_8 ( 3 , L_2 ,
V_2 -> V_20 , V_6 , V_28 ) ;
V_28 += V_2 -> V_11 [ V_6 ] . V_12 ;
V_28 = F_2 ( V_28 ) ;
}
}
static int F_14 ( struct V_3 * V_4 , enum V_33 V_34 ,
unsigned int V_35 , unsigned int V_9 ,
const unsigned V_36 [ V_37 ] )
{
unsigned int V_38 , V_6 ;
struct V_1 * V_2 ;
int V_7 ;
for ( V_38 = 0 ; V_38 < V_35 ; ++ V_38 ) {
V_2 = F_15 ( V_4 -> V_39 , V_40 ) ;
if ( ! V_2 ) {
F_8 ( 1 , L_3 ) ;
break;
}
V_2 -> V_41 = V_42 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_20 = V_4 -> V_35 + V_38 ;
V_2 -> type = V_4 -> type ;
V_2 -> V_34 = V_34 ;
for ( V_6 = 0 ; V_6 < V_9 ; ++ V_6 ) {
V_2 -> V_11 [ V_6 ] . V_12 = V_36 [ V_6 ] ;
V_2 -> V_11 [ V_6 ] . V_43 = V_36 [ V_6 ] ;
}
V_4 -> V_30 [ V_2 -> V_20 ] = V_2 ;
if ( V_34 == V_44 ) {
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_4 ,
V_38 ) ;
V_4 -> V_30 [ V_2 -> V_20 ] = NULL ;
F_16 ( V_2 ) ;
break;
}
F_13 ( V_2 ) ;
V_7 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_5 ,
V_38 , V_2 ) ;
F_7 ( V_2 ) ;
V_4 -> V_30 [ V_2 -> V_20 ] = NULL ;
F_16 ( V_2 ) ;
break;
}
}
}
F_8 ( 1 , L_6 ,
V_38 , V_9 ) ;
return V_38 ;
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_46 )
{
unsigned int V_38 ;
struct V_1 * V_2 ;
for ( V_38 = V_4 -> V_35 - V_46 ; V_38 < V_4 -> V_35 ;
++ V_38 ) {
V_2 = V_4 -> V_30 [ V_38 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_34 == V_44 )
F_7 ( V_2 ) ;
else if ( V_4 -> V_34 == V_47 )
F_12 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
}
static int F_19 ( struct V_3 * V_4 , unsigned int V_46 )
{
unsigned int V_38 ;
for ( V_38 = V_4 -> V_35 - V_46 ; V_38 < V_4 -> V_35 ;
++ V_38 ) {
if ( V_4 -> V_30 [ V_38 ] == NULL )
continue;
if ( V_4 -> V_30 [ V_38 ] -> V_41 == V_48 ) {
F_8 ( 1 , L_7 ) ;
return - V_49 ;
}
}
for ( V_38 = V_4 -> V_35 - V_46 ; V_38 < V_4 -> V_35 ;
++ V_38 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_38 ] ;
if ( V_2 && V_2 -> V_11 [ 0 ] . V_5 )
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_18 ( V_4 , V_46 ) ;
#ifdef F_21
if ( V_4 -> V_35 ) {
bool V_51 = V_4 -> V_52 != V_4 -> V_53 ||
V_4 -> V_54 != V_4 -> V_55 ;
if ( V_51 || V_56 ) {
F_22 ( L_8 , V_4 ,
V_51 ? L_9 : L_10 ) ;
F_22 ( L_11 ,
V_4 -> V_57 , V_4 -> V_52 ,
V_4 -> V_53 ) ;
F_22 ( L_12 ,
V_4 -> V_54 , V_4 -> V_55 ) ;
}
V_4 -> V_57 = 0 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
V_4 -> V_52 = 0 ;
V_4 -> V_53 = 0 ;
}
for ( V_38 = 0 ; V_38 < V_4 -> V_35 ; ++ V_38 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_38 ] ;
bool V_51 = V_2 -> V_58 != V_2 -> V_59 ||
V_2 -> V_60 != V_2 -> V_61 ||
V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ;
if ( V_51 || V_56 ) {
F_22 ( L_13 ,
V_4 , V_38 , V_51 ? L_9 : L_10 ) ;
F_22 ( L_14 ,
V_2 -> V_72 , V_2 -> V_73 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_22 ( L_15 ,
V_2 -> V_68 , V_2 -> V_69 ) ;
F_22 ( L_16 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_60 , V_2 -> V_61 ,
V_2 -> V_74 ) ;
F_22 ( L_17 ,
V_2 -> V_62 , V_2 -> V_63 ) ;
F_22 ( L_18 ,
V_2 -> V_64 , V_2 -> V_65 ,
V_2 -> V_66 , V_2 -> V_67 ) ;
F_22 ( L_19 ,
V_2 -> V_75 ,
V_2 -> V_76 ,
V_2 -> V_77 ,
V_2 -> V_78 ) ;
}
}
#endif
for ( V_38 = V_4 -> V_35 - V_46 ; V_38 < V_4 -> V_35 ;
++ V_38 ) {
F_16 ( V_4 -> V_30 [ V_38 ] ) ;
V_4 -> V_30 [ V_38 ] = NULL ;
}
V_4 -> V_35 -= V_46 ;
if ( ! V_4 -> V_35 ) {
V_4 -> V_34 = 0 ;
F_23 ( & V_4 -> V_79 ) ;
}
return 0 ;
}
bool F_24 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
void * V_5 = V_2 -> V_11 [ V_6 ] . V_5 ;
if ( V_5 && F_25 ( V_2 , V_80 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_26 ( struct V_3 * V_4 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_35 ; ++ V_38 ) {
if ( F_24 ( V_4 , V_4 -> V_30 [ V_38 ] ) )
return true ;
}
return false ;
}
void F_27 ( struct V_3 * V_4 , unsigned int V_20 , void * V_81 )
{
F_28 ( V_4 , V_82 , V_4 -> V_30 [ V_20 ] , V_81 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_84 ) || ! V_4 -> V_85 -> V_86 ||
! V_4 -> V_85 -> V_21 )
return - V_87 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_88 ) || ! V_4 -> V_85 -> V_13 ||
! V_4 -> V_85 -> V_19 || ! V_4 -> V_85 -> V_89 )
return - V_87 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_90 ) || ! V_4 -> V_85 -> V_91 ||
! V_4 -> V_85 -> V_26 || ! V_4 -> V_85 -> V_92 ||
! V_4 -> V_85 -> V_25 )
return - V_87 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_33 V_34 , unsigned int type )
{
if ( V_34 != V_44 && V_34 != V_93 &&
V_34 != V_47 ) {
F_8 ( 1 , L_20 ) ;
return - V_87 ;
}
if ( type != V_4 -> type ) {
F_8 ( 1 , L_21 ) ;
return - V_87 ;
}
if ( V_34 == V_44 && F_30 ( V_4 ) ) {
F_8 ( 1 , L_22 ) ;
return - V_87 ;
}
if ( V_34 == V_93 && F_29 ( V_4 ) ) {
F_8 ( 1 , L_23 ) ;
return - V_87 ;
}
if ( V_34 == V_47 && F_31 ( V_4 ) ) {
F_8 ( 1 , L_24 ) ;
return - V_87 ;
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_25 ) ;
return - V_94 ;
}
return 0 ;
}
int F_34 ( struct V_3 * V_4 , enum V_33 V_34 ,
unsigned int * V_95 )
{
unsigned int V_35 , V_96 , V_9 = 0 ;
unsigned V_36 [ V_37 ] = { } ;
int V_7 ;
if ( V_4 -> V_97 ) {
F_8 ( 1 , L_26 ) ;
return - V_94 ;
}
if ( * V_95 == 0 || V_4 -> V_35 != 0 || V_4 -> V_34 != V_34 ) {
F_35 ( & V_4 -> V_98 ) ;
if ( V_4 -> V_34 == V_44 && F_26 ( V_4 ) ) {
F_36 ( & V_4 -> V_98 ) ;
F_8 ( 1 , L_27 ) ;
return - V_94 ;
}
F_37 ( V_4 ) ;
V_7 = F_19 ( V_4 , V_4 -> V_35 ) ;
F_36 ( & V_4 -> V_98 ) ;
if ( V_7 )
return V_7 ;
if ( * V_95 == 0 )
return 0 ;
}
V_35 = F_38 (unsigned int, *count, VB2_MAX_FRAME) ;
V_35 = F_39 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_14 , 0 , sizeof( V_4 -> V_14 ) ) ;
V_4 -> V_34 = V_34 ;
V_7 = F_40 ( V_4 , V_99 , V_4 , & V_35 , & V_9 ,
V_36 , V_4 -> V_14 ) ;
if ( V_7 )
return V_7 ;
V_96 =
F_14 ( V_4 , V_34 , V_35 , V_9 , V_36 ) ;
if ( V_96 == 0 ) {
F_8 ( 1 , L_28 ) ;
return - V_8 ;
}
if ( V_96 < V_4 -> V_100 )
V_7 = - V_8 ;
if ( ! V_7 && V_96 < V_35 ) {
V_35 = V_96 ;
V_9 = 0 ;
V_7 = F_40 ( V_4 , V_99 , V_4 , & V_35 ,
& V_9 , V_36 , V_4 -> V_14 ) ;
if ( ! V_7 && V_96 < V_35 )
V_7 = - V_8 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_4 -> V_35 = V_96 ;
if ( V_7 < 0 ) {
F_19 ( V_4 , V_96 ) ;
F_36 ( & V_4 -> V_98 ) ;
return V_7 ;
}
F_36 ( & V_4 -> V_98 ) ;
* V_95 = V_96 ;
V_4 -> V_101 = ! V_4 -> V_102 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 , enum V_33 V_34 ,
unsigned int * V_95 , unsigned V_103 ,
const unsigned V_104 [] )
{
unsigned int V_9 = 0 , V_35 , V_96 ;
unsigned V_36 [ V_37 ] = { } ;
int V_7 ;
if ( V_4 -> V_35 == V_105 ) {
F_8 ( 1 , L_29 ) ;
return - V_106 ;
}
if ( ! V_4 -> V_35 ) {
memset ( V_4 -> V_14 , 0 , sizeof( V_4 -> V_14 ) ) ;
V_4 -> V_34 = V_34 ;
V_4 -> V_101 = ! V_4 -> V_102 ;
}
V_35 = F_42 ( * V_95 , V_105 - V_4 -> V_35 ) ;
if ( V_103 && V_104 ) {
V_9 = V_103 ;
memcpy ( V_36 , V_104 , sizeof( V_36 ) ) ;
}
V_7 = F_40 ( V_4 , V_99 , V_4 , & V_35 ,
& V_9 , V_36 , V_4 -> V_14 ) ;
if ( V_7 )
return V_7 ;
V_96 = F_14 ( V_4 , V_34 , V_35 ,
V_9 , V_36 ) ;
if ( V_96 == 0 ) {
F_8 ( 1 , L_28 ) ;
return - V_8 ;
}
if ( V_96 < V_35 ) {
V_35 = V_96 ;
V_7 = F_40 ( V_4 , V_99 , V_4 , & V_35 ,
& V_9 , V_36 , V_4 -> V_14 ) ;
if ( ! V_7 && V_96 < V_35 )
V_7 = - V_8 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_4 -> V_35 += V_96 ;
if ( V_7 < 0 ) {
F_19 ( V_4 , V_96 ) ;
F_36 ( & V_4 -> V_98 ) ;
return - V_8 ;
}
F_36 ( & V_4 -> V_98 ) ;
* V_95 = V_96 ;
return 0 ;
}
void * F_43 ( struct V_1 * V_2 , unsigned int V_107 )
{
if ( V_107 >= V_2 -> V_9 || ! V_2 -> V_11 [ V_107 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_108 , V_2 -> V_11 [ V_107 ] . V_5 ) ;
}
void * F_44 ( struct V_1 * V_2 , unsigned int V_107 )
{
if ( V_107 >= V_2 -> V_9 || ! V_2 -> V_11 [ V_107 ] . V_5 )
return NULL ;
return F_3 ( V_2 , V_109 , V_2 -> V_11 [ V_107 ] . V_5 ) ;
}
void F_45 ( struct V_1 * V_2 , enum V_110 V_41 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_111 ;
unsigned int V_6 ;
if ( F_46 ( V_2 -> V_41 != V_112 ) )
return;
if ( F_46 ( V_41 != V_113 &&
V_41 != V_114 &&
V_41 != V_115 &&
V_41 != V_116 ) )
V_41 = V_114 ;
#ifdef F_21
V_2 -> V_69 ++ ;
#endif
F_8 ( 4 , L_30 ,
V_2 -> V_20 , V_41 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 )
F_6 ( V_2 , V_117 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
F_47 ( & V_4 -> V_118 , V_111 ) ;
if ( V_41 == V_115 ||
V_41 == V_116 ) {
V_2 -> V_41 = V_115 ;
} else {
F_48 ( & V_2 -> V_119 , & V_4 -> V_120 ) ;
V_2 -> V_41 = V_41 ;
}
F_49 ( & V_4 -> V_121 ) ;
F_50 ( & V_4 -> V_118 , V_111 ) ;
F_51 ( V_4 , V_2 ) ;
switch ( V_41 ) {
case V_115 :
return;
case V_116 :
if ( V_4 -> V_122 )
F_52 ( V_2 ) ;
return;
default:
F_53 ( & V_4 -> V_123 ) ;
break;
}
}
void F_54 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_111 ;
F_47 ( & V_4 -> V_118 , V_111 ) ;
F_55 (vb, &q->done_list, done_entry)
V_2 -> V_41 = V_114 ;
F_50 ( & V_4 -> V_118 , V_111 ) ;
}
static int F_56 ( struct V_1 * V_2 , const void * V_81 )
{
int V_7 = 0 ;
if ( V_81 )
V_7 = F_57 ( V_2 -> V_3 , V_124 ,
V_2 , V_81 , V_2 -> V_11 ) ;
return V_7 ? V_7 : F_17 ( V_2 , V_125 , V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_22 V_11 [ V_37 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_7 = 0 ;
bool V_126 = V_2 -> V_11 [ 0 ] . V_5 == NULL ;
memset ( V_11 , 0 , sizeof( V_11 [ 0 ] ) * V_2 -> V_9 ) ;
if ( V_81 ) {
V_7 = F_57 ( V_2 -> V_3 , V_124 ,
V_2 , V_81 , V_11 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_31 . V_127 &&
V_2 -> V_11 [ V_6 ] . V_31 . V_127 == V_11 [ V_6 ] . V_31 . V_127
&& V_2 -> V_11 [ V_6 ] . V_12 == V_11 [ V_6 ] . V_12 )
continue;
F_8 ( 3 , L_31 ,
V_6 ) ;
if ( V_11 [ V_6 ] . V_12 < V_2 -> V_11 [ V_6 ] . V_43 ) {
F_8 ( 1 , L_32 ,
V_11 [ V_6 ] . V_12 ,
V_2 -> V_11 [ V_6 ] . V_43 ,
V_6 ) ;
V_7 = - V_87 ;
goto V_128;
}
if ( V_2 -> V_11 [ V_6 ] . V_5 ) {
if ( ! V_126 ) {
V_126 = true ;
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_6 ( V_2 , V_21 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
}
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_11 [ V_6 ] . V_129 = 0 ;
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_31 . V_127 = 0 ;
V_2 -> V_11 [ V_6 ] . V_130 = 0 ;
V_5 = F_3 ( V_2 , V_86 ,
V_4 -> V_14 [ V_6 ] ? : V_4 -> V_15 ,
V_11 [ V_6 ] . V_31 . V_127 ,
V_11 [ V_6 ] . V_12 , V_4 -> V_17 ) ;
if ( F_59 ( V_5 ) ) {
F_8 ( 1 , L_33 ,
V_6 ) ;
V_7 = F_5 ( V_5 ) ;
goto V_128;
}
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
V_2 -> V_11 [ V_6 ] . V_129 = V_11 [ V_6 ] . V_129 ;
V_2 -> V_11 [ V_6 ] . V_12 = V_11 [ V_6 ] . V_12 ;
V_2 -> V_11 [ V_6 ] . V_31 . V_127 = V_11 [ V_6 ] . V_31 . V_127 ;
V_2 -> V_11 [ V_6 ] . V_130 = V_11 [ V_6 ] . V_130 ;
}
if ( V_126 ) {
V_7 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_34 ) ;
goto V_128;
}
}
V_7 = F_17 ( V_2 , V_125 , V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_35 ) ;
F_20 ( V_2 , V_50 , V_2 ) ;
goto V_128;
}
return 0 ;
V_128:
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_6 ( V_2 , V_21 ,
V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_11 [ V_6 ] . V_31 . V_127 = 0 ;
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
}
return V_7 ;
}
static int F_60 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_22 V_11 [ V_37 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_7 = 0 ;
bool V_126 = V_2 -> V_11 [ 0 ] . V_5 == NULL ;
memset ( V_11 , 0 , sizeof( V_11 [ 0 ] ) * V_2 -> V_9 ) ;
if ( V_81 ) {
V_7 = F_57 ( V_2 -> V_3 , V_124 ,
V_2 , V_81 , V_11 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
struct V_131 * V_27 = F_61 ( V_11 [ V_6 ] . V_31 . V_132 ) ;
if ( F_4 ( V_27 ) ) {
F_8 ( 1 , L_36 ,
V_6 ) ;
V_7 = - V_87 ;
goto V_128;
}
if ( V_11 [ V_6 ] . V_12 == 0 )
V_11 [ V_6 ] . V_12 = V_27 -> V_10 ;
if ( V_11 [ V_6 ] . V_12 < V_2 -> V_11 [ V_6 ] . V_43 ) {
F_8 ( 1 , L_37 ,
V_11 [ V_6 ] . V_12 , V_6 ,
V_2 -> V_11 [ V_6 ] . V_43 ) ;
F_11 ( V_27 ) ;
V_7 = - V_87 ;
goto V_128;
}
if ( V_27 == V_2 -> V_11 [ V_6 ] . V_27 &&
V_2 -> V_11 [ V_6 ] . V_12 == V_11 [ V_6 ] . V_12 ) {
F_11 ( V_27 ) ;
continue;
}
F_8 ( 3 , L_38 , V_6 ) ;
if ( ! V_126 ) {
V_126 = true ;
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_10 ( V_2 , & V_2 -> V_11 [ V_6 ] ) ;
V_2 -> V_11 [ V_6 ] . V_129 = 0 ;
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_31 . V_132 = 0 ;
V_2 -> V_11 [ V_6 ] . V_130 = 0 ;
V_5 = F_3 ( V_2 , V_91 ,
V_4 -> V_14 [ V_6 ] ? : V_4 -> V_15 ,
V_27 , V_11 [ V_6 ] . V_12 , V_4 -> V_17 ) ;
if ( F_59 ( V_5 ) ) {
F_8 ( 1 , L_39 ) ;
V_7 = F_5 ( V_5 ) ;
F_11 ( V_27 ) ;
goto V_128;
}
V_2 -> V_11 [ V_6 ] . V_27 = V_27 ;
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
V_7 = F_25 ( V_2 , V_92 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
if ( V_7 ) {
F_8 ( 1 , L_40 ,
V_6 ) ;
goto V_128;
}
V_2 -> V_11 [ V_6 ] . V_24 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
V_2 -> V_11 [ V_6 ] . V_129 = V_11 [ V_6 ] . V_129 ;
V_2 -> V_11 [ V_6 ] . V_12 = V_11 [ V_6 ] . V_12 ;
V_2 -> V_11 [ V_6 ] . V_31 . V_132 = V_11 [ V_6 ] . V_31 . V_132 ;
V_2 -> V_11 [ V_6 ] . V_130 = V_11 [ V_6 ] . V_130 ;
}
if ( V_126 ) {
V_7 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_34 ) ;
goto V_128;
}
}
V_7 = F_17 ( V_2 , V_125 , V_2 ) ;
if ( V_7 ) {
F_8 ( 1 , L_35 ) ;
F_20 ( V_2 , V_50 , V_2 ) ;
goto V_128;
}
return 0 ;
V_128:
F_12 ( V_2 ) ;
return V_7 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
V_2 -> V_41 = V_112 ;
F_62 ( & V_4 -> V_121 ) ;
F_63 ( V_4 , V_2 ) ;
F_20 ( V_2 , V_133 , V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
int V_7 ;
if ( V_4 -> error ) {
F_8 ( 1 , L_41 ) ;
return - V_134 ;
}
V_2 -> V_41 = V_48 ;
switch ( V_4 -> V_34 ) {
case V_44 :
V_7 = F_56 ( V_2 , V_81 ) ;
break;
case V_93 :
V_7 = F_58 ( V_2 , V_81 ) ;
break;
case V_47 :
V_7 = F_60 ( V_2 , V_81 ) ;
break;
default:
F_65 ( 1 , L_42 ) ;
V_7 = - V_87 ;
}
if ( V_7 ) {
F_8 ( 1 , L_43 , V_7 ) ;
V_2 -> V_41 = V_42 ;
return V_7 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 )
F_6 ( V_2 , V_135 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_41 = V_136 ;
return 0 ;
}
int F_66 ( struct V_3 * V_4 , unsigned int V_20 , void * V_81 )
{
struct V_1 * V_2 ;
int V_7 ;
V_2 = V_4 -> V_30 [ V_20 ] ;
if ( V_2 -> V_41 != V_42 ) {
F_8 ( 1 , L_44 ,
V_2 -> V_41 ) ;
return - V_87 ;
}
V_7 = F_64 ( V_2 , V_81 ) ;
if ( V_7 )
return V_7 ;
F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
F_8 ( 2 , L_45 , V_2 -> V_20 ) ;
return V_7 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_7 ;
F_55 (vb, &q->queued_list, queued_entry)
F_52 ( V_2 ) ;
V_4 -> V_122 = 1 ;
V_7 = F_40 ( V_4 , V_137 , V_4 ,
F_68 ( & V_4 -> V_121 ) ) ;
if ( ! V_7 )
return 0 ;
V_4 -> V_122 = 0 ;
F_8 ( 1 , L_46 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_121 ) ) ) {
unsigned V_138 ;
for ( V_138 = 0 ; V_138 < V_4 -> V_35 ; ++ V_138 ) {
V_2 = V_4 -> V_30 [ V_138 ] ;
if ( V_2 -> V_41 == V_112 )
F_45 ( V_2 , V_115 ) ;
}
F_46 ( F_68 ( & V_4 -> V_121 ) ) ;
}
F_46 ( ! F_69 ( & V_4 -> V_120 ) ) ;
return V_7 ;
}
int F_70 ( struct V_3 * V_4 , unsigned int V_20 , void * V_81 )
{
struct V_1 * V_2 ;
int V_7 ;
V_2 = V_4 -> V_30 [ V_20 ] ;
switch ( V_2 -> V_41 ) {
case V_42 :
V_7 = F_64 ( V_2 , V_81 ) ;
if ( V_7 )
return V_7 ;
break;
case V_136 :
break;
case V_48 :
F_8 ( 1 , L_47 ) ;
return - V_87 ;
default:
F_8 ( 1 , L_44 , V_2 -> V_41 ) ;
return - V_87 ;
}
F_48 ( & V_2 -> V_139 , & V_4 -> V_79 ) ;
V_4 -> V_140 ++ ;
V_4 -> V_101 = false ;
V_2 -> V_41 = V_115 ;
if ( V_81 )
F_28 ( V_4 , V_141 , V_2 , V_81 ) ;
F_71 ( V_4 , V_2 ) ;
if ( V_4 -> V_122 )
F_52 ( V_2 ) ;
if ( V_81 )
F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
if ( V_4 -> V_97 && ! V_4 -> V_122 &&
V_4 -> V_140 >= V_4 -> V_100 ) {
V_7 = F_67 ( V_4 ) ;
if ( V_7 )
return V_7 ;
}
F_8 ( 2 , L_48 , V_2 -> V_20 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int V_142 )
{
for (; ; ) {
int V_7 ;
if ( ! V_4 -> V_97 ) {
F_8 ( 1 , L_49 ) ;
return - V_87 ;
}
if ( V_4 -> error ) {
F_8 ( 1 , L_50 ) ;
return - V_134 ;
}
if ( V_4 -> V_143 ) {
F_8 ( 3 , L_51 ) ;
return - V_144 ;
}
if ( ! F_69 ( & V_4 -> V_120 ) ) {
break;
}
if ( V_142 ) {
F_8 ( 3 , L_52 ) ;
return - V_49 ;
}
F_73 ( V_4 , V_145 , V_4 ) ;
F_8 ( 3 , L_53 ) ;
V_7 = F_74 ( V_4 -> V_123 ,
! F_69 ( & V_4 -> V_120 ) || ! V_4 -> V_97 ||
V_4 -> error ) ;
F_73 ( V_4 , V_146 , V_4 ) ;
if ( V_7 ) {
F_8 ( 1 , L_54 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
void * V_81 , int V_142 )
{
unsigned long V_111 ;
int V_7 = 0 ;
V_7 = F_72 ( V_4 , V_142 ) ;
if ( V_7 )
return V_7 ;
F_47 ( & V_4 -> V_118 , V_111 ) ;
* V_2 = F_76 ( & V_4 -> V_120 , struct V_1 , V_119 ) ;
if ( V_81 )
V_7 = F_57 ( V_4 , V_147 , * V_2 , V_81 ) ;
if ( ! V_7 )
F_77 ( & ( * V_2 ) -> V_119 ) ;
F_50 ( & V_4 -> V_118 , V_111 ) ;
return V_7 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_97 ) {
F_8 ( 1 , L_49 ) ;
return - V_87 ;
}
if ( V_4 -> V_122 )
F_79 ( V_4 -> V_123 , ! F_68 ( & V_4 -> V_121 ) ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_138 ;
if ( V_2 -> V_41 == V_42 )
return;
V_2 -> V_41 = V_42 ;
if ( V_4 -> V_34 == V_47 )
for ( V_138 = 0 ; V_138 < V_2 -> V_9 ; ++ V_138 ) {
if ( ! V_2 -> V_11 [ V_138 ] . V_24 )
continue;
F_6 ( V_2 , V_25 , V_2 -> V_11 [ V_138 ] . V_5 ) ;
V_2 -> V_11 [ V_138 ] . V_24 = 0 ;
}
}
int F_81 ( struct V_3 * V_4 , unsigned int * V_148 , void * V_81 ,
bool V_142 )
{
struct V_1 * V_2 = NULL ;
int V_7 ;
V_7 = F_75 ( V_4 , & V_2 , V_81 , V_142 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_2 -> V_41 ) {
case V_113 :
F_8 ( 3 , L_55 ) ;
break;
case V_114 :
F_8 ( 3 , L_56 ) ;
break;
default:
F_8 ( 1 , L_57 ) ;
return - V_87 ;
}
F_20 ( V_2 , V_149 , V_2 ) ;
if ( V_148 )
* V_148 = V_2 -> V_20 ;
if ( V_81 )
F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
F_77 ( & V_2 -> V_139 ) ;
V_4 -> V_140 -- ;
F_82 ( V_4 , V_2 ) ;
F_80 ( V_2 ) ;
F_8 ( 2 , L_58 ,
V_2 -> V_20 , V_2 -> V_41 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
unsigned int V_138 ;
if ( V_4 -> V_122 )
F_73 ( V_4 , V_150 , V_4 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_121 ) ) ) {
for ( V_138 = 0 ; V_138 < V_4 -> V_35 ; ++ V_138 )
if ( V_4 -> V_30 [ V_138 ] -> V_41 == V_112 )
F_45 ( V_4 -> V_30 [ V_138 ] , V_114 ) ;
F_46 ( F_68 ( & V_4 -> V_121 ) ) ;
}
V_4 -> V_97 = 0 ;
V_4 -> V_122 = 0 ;
V_4 -> V_140 = 0 ;
V_4 -> error = 0 ;
F_23 ( & V_4 -> V_79 ) ;
F_23 ( & V_4 -> V_120 ) ;
F_83 ( & V_4 -> V_121 , 0 ) ;
F_84 ( & V_4 -> V_123 ) ;
for ( V_138 = 0 ; V_138 < V_4 -> V_35 ; ++ V_138 ) {
struct V_1 * V_2 = V_4 -> V_30 [ V_138 ] ;
if ( V_2 -> V_41 != V_42 ) {
V_2 -> V_41 = V_136 ;
F_20 ( V_2 , V_149 , V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
int F_85 ( struct V_3 * V_4 , unsigned int type )
{
int V_7 ;
if ( type != V_4 -> type ) {
F_8 ( 1 , L_59 ) ;
return - V_87 ;
}
if ( V_4 -> V_97 ) {
F_8 ( 3 , L_60 ) ;
return 0 ;
}
if ( ! V_4 -> V_35 ) {
F_8 ( 1 , L_61 ) ;
return - V_87 ;
}
if ( V_4 -> V_35 < V_4 -> V_100 ) {
F_8 ( 1 , L_62 ,
V_4 -> V_100 ) ;
return - V_87 ;
}
if ( V_4 -> V_140 >= V_4 -> V_100 ) {
V_7 = F_86 ( V_4 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_67 ( V_4 ) ;
if ( V_7 ) {
F_37 ( V_4 ) ;
return V_7 ;
}
}
V_4 -> V_97 = 1 ;
F_8 ( 3 , L_63 ) ;
return 0 ;
}
void F_87 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_84 ( & V_4 -> V_123 ) ;
}
int F_88 ( struct V_3 * V_4 , unsigned int type )
{
if ( type != V_4 -> type ) {
F_8 ( 1 , L_59 ) ;
return - V_87 ;
}
F_37 ( V_4 ) ;
V_4 -> V_101 = ! V_4 -> V_102 ;
V_4 -> V_143 = false ;
F_8 ( 3 , L_63 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_4 , unsigned long V_28 ,
unsigned int * V_151 , unsigned int * V_152 )
{
struct V_1 * V_2 ;
unsigned int V_38 , V_6 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_35 ; ++ V_38 ) {
V_2 = V_4 -> V_30 [ V_38 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_9 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_31 . V_32 == V_28 ) {
* V_151 = V_38 ;
* V_152 = V_6 ;
return 0 ;
}
}
}
return - V_87 ;
}
int F_90 ( struct V_3 * V_4 , int * V_132 , unsigned int type ,
unsigned int V_20 , unsigned int V_6 , unsigned int V_111 )
{
struct V_1 * V_2 = NULL ;
struct V_22 * V_153 ;
int V_7 ;
struct V_131 * V_27 ;
if ( V_4 -> V_34 != V_44 ) {
F_8 ( 1 , L_64 ) ;
return - V_87 ;
}
if ( ! V_4 -> V_85 -> V_154 ) {
F_8 ( 1 , L_65 ) ;
return - V_87 ;
}
if ( V_111 & ~ ( V_155 | V_156 ) ) {
F_8 ( 1 , L_66 ) ;
return - V_87 ;
}
if ( type != V_4 -> type ) {
F_8 ( 1 , L_67 ) ;
return - V_87 ;
}
if ( V_20 >= V_4 -> V_35 ) {
F_8 ( 1 , L_68 ) ;
return - V_87 ;
}
V_2 = V_4 -> V_30 [ V_20 ] ;
if ( V_6 >= V_2 -> V_9 ) {
F_8 ( 1 , L_69 ) ;
return - V_87 ;
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_70 ) ;
return - V_94 ;
}
V_153 = & V_2 -> V_11 [ V_6 ] ;
V_27 = F_3 ( V_2 , V_154 , V_153 -> V_5 ,
V_111 & V_156 ) ;
if ( F_4 ( V_27 ) ) {
F_8 ( 1 , L_71 ,
V_20 , V_6 ) ;
return - V_87 ;
}
V_7 = F_91 ( V_27 , V_111 & ~ V_156 ) ;
if ( V_7 < 0 ) {
F_8 ( 3 , L_72 ,
V_20 , V_6 , V_7 ) ;
F_11 ( V_27 ) ;
return V_7 ;
}
F_8 ( 3 , L_73 ,
V_20 , V_6 , V_7 ) ;
* V_132 = V_7 ;
return 0 ;
}
int F_92 ( struct V_3 * V_4 , struct V_157 * V_158 )
{
unsigned long V_28 = V_158 -> V_159 << V_160 ;
struct V_1 * V_2 ;
unsigned int V_38 = 0 , V_6 = 0 ;
int V_7 ;
unsigned long V_12 ;
if ( V_4 -> V_34 != V_44 ) {
F_8 ( 1 , L_64 ) ;
return - V_87 ;
}
if ( ! ( V_158 -> V_161 & V_162 ) ) {
F_8 ( 1 , L_74 ) ;
return - V_87 ;
}
if ( V_4 -> V_102 ) {
if ( ! ( V_158 -> V_161 & V_163 ) ) {
F_8 ( 1 , L_75 ) ;
return - V_87 ;
}
} else {
if ( ! ( V_158 -> V_161 & V_164 ) ) {
F_8 ( 1 , L_76 ) ;
return - V_87 ;
}
}
if ( F_33 ( V_4 ) ) {
F_8 ( 1 , L_77 ) ;
return - V_94 ;
}
V_7 = F_89 ( V_4 , V_28 , & V_38 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 = V_4 -> V_30 [ V_38 ] ;
V_12 = F_2 ( V_2 -> V_11 [ V_6 ] . V_12 ) ;
if ( V_12 < ( V_158 -> V_165 - V_158 -> V_166 ) ) {
F_8 ( 1 ,
L_78 ) ;
return - V_87 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_7 = F_25 ( V_2 , V_89 , V_2 -> V_11 [ V_6 ] . V_5 , V_158 ) ;
F_36 ( & V_4 -> V_98 ) ;
if ( V_7 )
return V_7 ;
F_8 ( 3 , L_79 , V_38 , V_6 ) ;
return 0 ;
}
unsigned long F_93 ( struct V_3 * V_4 ,
unsigned long V_167 ,
unsigned long V_168 ,
unsigned long V_169 ,
unsigned long V_111 )
{
unsigned long V_28 = V_169 << V_160 ;
struct V_1 * V_2 ;
unsigned int V_38 , V_6 ;
void * V_108 ;
int V_7 ;
if ( V_4 -> V_34 != V_44 ) {
F_8 ( 1 , L_64 ) ;
return - V_87 ;
}
V_7 = F_89 ( V_4 , V_28 , & V_38 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 = V_4 -> V_30 [ V_38 ] ;
V_108 = F_43 ( V_2 , V_6 ) ;
return V_108 ? ( unsigned long ) V_108 : - V_87 ;
}
int F_94 ( struct V_3 * V_4 )
{
if ( F_46 ( ! V_4 ) ||
F_46 ( ! V_4 -> V_170 ) ||
F_46 ( ! V_4 -> V_85 ) ||
F_46 ( ! V_4 -> type ) ||
F_46 ( ! V_4 -> V_83 ) ||
F_46 ( ! V_4 -> V_170 -> V_99 ) ||
F_46 ( ! V_4 -> V_170 -> V_133 ) )
return - V_87 ;
F_23 ( & V_4 -> V_79 ) ;
F_23 ( & V_4 -> V_120 ) ;
F_95 ( & V_4 -> V_118 ) ;
F_96 ( & V_4 -> V_98 ) ;
F_97 ( & V_4 -> V_123 ) ;
if ( V_4 -> V_39 == 0 )
V_4 -> V_39 = sizeof( struct V_1 ) ;
if ( V_4 -> V_171 )
V_4 -> V_17 = V_172 ;
else
V_4 -> V_17 = V_4 -> V_102 ? V_173 : V_174 ;
return 0 ;
}
void F_98 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
F_37 ( V_4 ) ;
F_35 ( & V_4 -> V_98 ) ;
F_19 ( V_4 , V_4 -> V_35 ) ;
F_36 ( & V_4 -> V_98 ) ;
}
unsigned int F_100 ( struct V_3 * V_4 , struct V_175 * V_175 ,
T_1 * V_176 )
{
unsigned long V_177 = F_101 ( V_176 ) ;
struct V_1 * V_2 = NULL ;
unsigned long V_111 ;
if ( ! V_4 -> V_102 && ! ( V_177 & ( V_178 | V_179 ) ) )
return 0 ;
if ( V_4 -> V_102 && ! ( V_177 & ( V_180 | V_181 ) ) )
return 0 ;
if ( V_4 -> V_35 == 0 && ! F_33 ( V_4 ) ) {
if ( ! V_4 -> V_102 && ( V_4 -> V_83 & V_182 ) &&
( V_177 & ( V_178 | V_179 ) ) ) {
if ( F_102 ( V_4 , 1 ) )
return V_183 ;
}
if ( V_4 -> V_102 && ( V_4 -> V_83 & V_184 ) &&
( V_177 & ( V_180 | V_181 ) ) ) {
if ( F_102 ( V_4 , 0 ) )
return V_183 ;
return V_180 | V_181 ;
}
}
if ( ! F_103 ( V_4 ) || V_4 -> error )
return V_183 ;
if ( V_4 -> V_185 &&
V_4 -> V_101 && ( V_177 & ( V_178 | V_179 ) ) )
return V_183 ;
if ( V_4 -> V_102 && V_4 -> V_186 && V_4 -> V_140 < V_4 -> V_35 )
return V_180 | V_181 ;
if ( F_69 ( & V_4 -> V_120 ) ) {
if ( V_4 -> V_143 )
return V_178 | V_179 ;
F_104 ( V_175 , & V_4 -> V_123 , V_176 ) ;
}
F_47 ( & V_4 -> V_118 , V_111 ) ;
if ( ! F_69 ( & V_4 -> V_120 ) )
V_2 = F_76 ( & V_4 -> V_120 , struct V_1 ,
V_119 ) ;
F_50 ( & V_4 -> V_118 , V_111 ) ;
if ( V_2 && ( V_2 -> V_41 == V_113
|| V_2 -> V_41 == V_114 ) ) {
return ( V_4 -> V_102 ) ?
V_180 | V_181 :
V_178 | V_179 ;
}
return 0 ;
}
static int F_102 ( struct V_3 * V_4 , int V_187 )
{
struct V_188 * V_186 ;
int V_138 , V_7 ;
unsigned int V_95 = 0 ;
if ( F_46 ( ( V_187 && ! ( V_4 -> V_83 & V_182 ) ) ||
( ! V_187 && ! ( V_4 -> V_83 & V_184 ) ) ) )
return - V_87 ;
if ( ! V_4 -> V_85 -> V_108 )
return - V_94 ;
if ( V_4 -> V_97 || V_4 -> V_35 > 0 )
return - V_94 ;
V_95 = 1 ;
F_8 ( 3 , L_80 ,
( V_187 ) ? L_81 : L_82 , V_95 , V_4 -> V_189 ,
V_4 -> V_190 ) ;
V_186 = F_15 ( sizeof( * V_186 ) , V_40 ) ;
if ( V_186 == NULL )
return - V_8 ;
V_186 -> V_191 = V_4 -> V_189 ;
V_186 -> V_192 = V_4 -> V_190 ;
V_186 -> V_95 = V_95 ;
V_186 -> V_34 = V_44 ;
V_186 -> type = V_4 -> type ;
V_4 -> V_186 = V_186 ;
V_7 = F_34 ( V_4 , V_186 -> V_34 , & V_186 -> V_95 ) ;
if ( V_7 )
goto V_193;
if ( V_4 -> V_30 [ 0 ] -> V_9 != 1 ) {
V_7 = - V_94 ;
goto V_194;
}
for ( V_138 = 0 ; V_138 < V_4 -> V_35 ; V_138 ++ ) {
V_186 -> V_30 [ V_138 ] . V_108 = F_43 ( V_4 -> V_30 [ V_138 ] , 0 ) ;
if ( V_186 -> V_30 [ V_138 ] . V_108 == NULL ) {
V_7 = - V_87 ;
goto V_194;
}
V_186 -> V_30 [ V_138 ] . V_10 = F_105 ( V_4 -> V_30 [ V_138 ] , 0 ) ;
}
if ( V_187 ) {
for ( V_138 = 0 ; V_138 < V_4 -> V_35 ; V_138 ++ ) {
V_7 = F_70 ( V_4 , V_138 , NULL ) ;
if ( V_7 )
goto V_194;
V_186 -> V_30 [ V_138 ] . V_195 = 1 ;
}
V_186 -> V_196 = V_4 -> V_35 ;
V_186 -> V_197 = V_4 -> V_35 ;
}
V_7 = F_85 ( V_4 , V_4 -> type ) ;
if ( V_7 )
goto V_194;
return V_7 ;
V_194:
V_186 -> V_95 = 0 ;
F_34 ( V_4 , V_186 -> V_34 , & V_186 -> V_95 ) ;
V_193:
V_4 -> V_186 = NULL ;
F_16 ( V_186 ) ;
return V_7 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_188 * V_186 = V_4 -> V_186 ;
if ( V_186 ) {
F_88 ( V_4 , V_4 -> type ) ;
V_4 -> V_186 = NULL ;
V_186 -> V_95 = 0 ;
F_34 ( V_4 , V_186 -> V_34 , & V_186 -> V_95 ) ;
F_16 ( V_186 ) ;
F_8 ( 3 , L_83 ) ;
}
return 0 ;
}
static T_2 F_106 ( struct V_3 * V_4 , char T_3 * V_198 , T_2 V_95 ,
T_4 * V_199 , int V_200 , int V_187 )
{
struct V_188 * V_186 ;
struct V_201 * V_202 ;
bool V_203 = V_4 -> V_203 ;
bool V_141 = ! V_187 && V_4 -> V_141 ;
unsigned V_20 ;
int V_7 ;
F_8 ( 3 , L_84 ,
V_187 ? L_81 : L_82 , ( long ) * V_199 , V_95 ,
V_200 ? L_85 : L_10 ) ;
if ( ! V_198 )
return - V_87 ;
if ( ! F_33 ( V_4 ) ) {
V_7 = F_102 ( V_4 , V_187 ) ;
F_8 ( 3 , L_86 , V_7 ) ;
if ( V_7 )
return V_7 ;
}
V_186 = V_4 -> V_186 ;
V_20 = V_186 -> V_197 ;
if ( V_20 >= V_4 -> V_35 ) {
struct V_1 * V_204 ;
V_7 = F_81 ( V_4 , & V_20 , NULL , V_200 ) ;
F_8 ( 5 , L_87 , V_7 ) ;
if ( V_7 )
return V_7 ;
V_186 -> V_205 += 1 ;
V_186 -> V_197 = V_20 ;
V_202 = & V_186 -> V_30 [ V_20 ] ;
V_204 = V_4 -> V_30 [ V_20 ] ;
V_202 -> V_206 = 0 ;
V_202 -> V_195 = 0 ;
V_202 -> V_10 = V_187 ? F_107 ( V_4 -> V_30 [ V_20 ] , 0 )
: F_105 ( V_4 -> V_30 [ V_20 ] , 0 ) ;
if ( V_203 && V_187 &&
V_204 -> V_11 [ 0 ] . V_130 < V_202 -> V_10 ) {
V_202 -> V_206 = V_204 -> V_11 [ 0 ] . V_130 ;
V_202 -> V_10 -= V_202 -> V_206 ;
}
} else {
V_202 = & V_186 -> V_30 [ V_20 ] ;
}
if ( V_202 -> V_206 + V_95 > V_202 -> V_10 ) {
V_95 = V_202 -> V_10 - V_202 -> V_206 ;
F_8 ( 5 , L_88 , V_95 ) ;
}
F_8 ( 3 , L_89 ,
V_95 , V_20 , V_202 -> V_206 ) ;
if ( V_187 )
V_7 = F_108 ( V_198 , V_202 -> V_108 + V_202 -> V_206 , V_95 ) ;
else
V_7 = F_109 ( V_202 -> V_108 + V_202 -> V_206 , V_198 , V_95 ) ;
if ( V_7 ) {
F_8 ( 3 , L_90 ) ;
return - V_207 ;
}
V_202 -> V_206 += V_95 ;
* V_199 += V_95 ;
if ( V_202 -> V_206 == V_202 -> V_10 || ( ! V_187 && V_186 -> V_192 ) ) {
struct V_1 * V_204 = V_4 -> V_30 [ V_20 ] ;
if ( V_187 && V_186 -> V_191 && V_186 -> V_205 == 1 ) {
F_8 ( 3 , L_91 ) ;
return F_99 ( V_4 ) ;
}
V_204 -> V_11 [ 0 ] . V_129 = V_202 -> V_206 ;
if ( V_141 )
V_204 -> V_208 = F_110 () ;
V_7 = F_70 ( V_4 , V_20 , NULL ) ;
F_8 ( 5 , L_92 , V_7 ) ;
if ( V_7 )
return V_7 ;
V_202 -> V_206 = 0 ;
V_202 -> V_195 = 1 ;
V_202 -> V_10 = F_105 ( V_4 -> V_30 [ V_20 ] , 0 ) ;
V_186 -> V_209 += 1 ;
if ( V_186 -> V_196 < V_4 -> V_35 )
V_186 -> V_196 ++ ;
V_186 -> V_197 = V_186 -> V_196 ;
}
if ( V_7 == 0 )
V_7 = V_95 ;
return V_7 ;
}
T_2 F_111 ( struct V_3 * V_4 , char T_3 * V_198 , T_2 V_95 ,
T_4 * V_199 , int V_142 )
{
return F_106 ( V_4 , V_198 , V_95 , V_199 , V_142 , 1 ) ;
}
T_2 F_112 ( struct V_3 * V_4 , const char T_3 * V_198 , T_2 V_95 ,
T_4 * V_199 , int V_142 )
{
return F_106 ( V_4 , ( char T_3 * ) V_198 , V_95 ,
V_199 , V_142 , 0 ) ;
}
static int F_113 ( void * V_198 )
{
struct V_3 * V_4 = V_198 ;
struct V_210 * V_211 = V_4 -> V_211 ;
bool V_141 = false ;
unsigned V_212 = 0 ;
unsigned V_20 = 0 ;
int V_7 = 0 ;
if ( V_4 -> V_102 ) {
V_212 = V_4 -> V_35 ;
V_141 = V_4 -> V_141 ;
}
F_114 () ;
for (; ; ) {
struct V_1 * V_2 ;
if ( V_212 ) {
V_2 = V_4 -> V_30 [ V_20 ++ ] ;
V_212 -- ;
} else {
F_73 ( V_4 , V_146 , V_4 ) ;
if ( ! V_211 -> V_213 )
V_7 = F_81 ( V_4 , & V_20 , NULL , 0 ) ;
F_73 ( V_4 , V_145 , V_4 ) ;
F_8 ( 5 , L_93 , V_7 ) ;
if ( ! V_7 )
V_2 = V_4 -> V_30 [ V_20 ] ;
}
if ( V_7 || V_211 -> V_213 )
break;
F_115 () ;
if ( V_2 -> V_41 != V_114 )
if ( V_211 -> V_214 ( V_2 , V_211 -> V_215 ) )
break;
F_73 ( V_4 , V_146 , V_4 ) ;
if ( V_141 )
V_2 -> V_208 = F_110 () ; ;
if ( ! V_211 -> V_213 )
V_7 = F_70 ( V_4 , V_2 -> V_20 , NULL ) ;
F_73 ( V_4 , V_145 , V_4 ) ;
if ( V_7 || V_211 -> V_213 )
break;
}
while ( ! F_116 () ) {
F_117 ( V_216 ) ;
F_118 () ;
}
return 0 ;
}
int F_119 ( struct V_3 * V_4 , T_5 V_214 , void * V_215 ,
const char * V_217 )
{
struct V_210 * V_211 ;
int V_7 = 0 ;
if ( V_4 -> V_211 )
return - V_94 ;
if ( F_120 ( V_4 ) )
return - V_94 ;
if ( F_46 ( V_4 -> V_186 ) )
return - V_94 ;
V_211 = F_15 ( sizeof( * V_211 ) , V_40 ) ;
if ( V_211 == NULL )
return - V_8 ;
V_211 -> V_214 = V_214 ;
V_211 -> V_215 = V_215 ;
V_7 = F_102 ( V_4 , ! V_4 -> V_102 ) ;
F_8 ( 3 , L_94 , V_7 ) ;
if ( V_7 )
goto V_218;
V_4 -> V_211 = V_211 ;
V_211 -> V_219 = F_121 ( F_113 , V_4 , L_95 , V_217 ) ;
if ( F_59 ( V_211 -> V_219 ) ) {
V_7 = F_5 ( V_211 -> V_219 ) ;
V_211 -> V_219 = NULL ;
goto V_220;
}
return 0 ;
V_220:
F_99 ( V_4 ) ;
V_218:
F_16 ( V_211 ) ;
return V_7 ;
}
int F_122 ( struct V_3 * V_4 )
{
struct V_210 * V_211 = V_4 -> V_211 ;
int V_128 ;
if ( V_211 == NULL )
return 0 ;
V_211 -> V_213 = true ;
F_87 ( V_4 ) ;
V_128 = F_123 ( V_211 -> V_219 ) ;
F_99 ( V_4 ) ;
V_211 -> V_219 = NULL ;
F_16 ( V_211 ) ;
V_4 -> V_211 = NULL ;
return V_128 ;
}
