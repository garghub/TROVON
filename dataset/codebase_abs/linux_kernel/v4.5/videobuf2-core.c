static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
void * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
unsigned long V_13 = F_2 ( V_2 -> V_14 [ V_11 ] . V_15 ) ;
V_10 = F_3 ( V_2 , V_16 , V_4 -> V_17 [ V_11 ] ,
V_13 , V_6 , V_4 -> V_18 ) ;
if ( F_4 ( V_10 ) )
goto free;
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
return 0 ;
free:
for (; V_11 > 0 ; -- V_11 ) {
F_5 ( V_2 , V_19 , V_2 -> V_14 [ V_11 - 1 ] . V_10 ) ;
V_2 -> V_14 [ V_11 - 1 ] . V_10 = NULL ;
}
return - V_20 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
F_5 ( V_2 , V_19 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
F_7 ( 3 , L_1 , V_11 , V_2 -> V_21 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_10 )
F_5 ( V_2 , V_22 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
if ( ! V_24 -> V_10 )
return;
if ( V_24 -> V_25 )
F_5 ( V_2 , V_26 , V_24 -> V_10 ) ;
F_5 ( V_2 , V_27 , V_24 -> V_10 ) ;
F_10 ( V_24 -> V_28 ) ;
V_24 -> V_10 = NULL ;
V_24 -> V_28 = NULL ;
V_24 -> V_25 = 0 ;
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
unsigned long V_29 = 0 ;
if ( V_2 -> V_21 ) {
struct V_1 * V_30 = V_4 -> V_31 [ V_2 -> V_21 - 1 ] ;
struct V_23 * V_24 = & V_30 -> V_14 [ V_30 -> V_12 - 1 ] ;
V_29 = F_2 ( V_24 -> V_32 . V_33 + V_24 -> V_15 ) ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_32 . V_33 = V_29 ;
F_7 ( 3 , L_2 ,
V_2 -> V_21 , V_11 , V_29 ) ;
V_29 += V_2 -> V_14 [ V_11 ] . V_15 ;
V_29 = F_2 ( V_29 ) ;
}
}
static int F_13 ( struct V_3 * V_4 , enum V_34 V_35 ,
unsigned int V_36 , unsigned int V_12 ,
const unsigned V_37 [ V_38 ] )
{
unsigned int V_39 , V_11 ;
struct V_1 * V_2 ;
int V_40 ;
for ( V_39 = 0 ; V_39 < V_36 ; ++ V_39 ) {
V_2 = F_14 ( V_4 -> V_41 , V_42 ) ;
if ( ! V_2 ) {
F_7 ( 1 , L_3 ) ;
break;
}
V_2 -> V_43 = V_44 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_21 = V_4 -> V_36 + V_39 ;
V_2 -> type = V_4 -> type ;
V_2 -> V_35 = V_35 ;
for ( V_11 = 0 ; V_11 < V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_15 = V_37 [ V_11 ] ;
V_2 -> V_14 [ V_11 ] . V_45 = V_37 [ V_11 ] ;
}
V_4 -> V_31 [ V_2 -> V_21 ] = V_2 ;
if ( V_35 == V_46 ) {
V_40 = F_1 ( V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_4
L_5 , V_39 ) ;
V_4 -> V_31 [ V_2 -> V_21 ] = NULL ;
F_15 ( V_2 ) ;
break;
}
F_12 ( V_2 ) ;
V_40 = F_16 ( V_2 , V_47 , V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_6
L_7 , V_39 , V_2 ) ;
F_6 ( V_2 ) ;
V_4 -> V_31 [ V_2 -> V_21 ] = NULL ;
F_15 ( V_2 ) ;
break;
}
}
}
F_7 ( 1 , L_8 ,
V_39 , V_12 ) ;
return V_39 ;
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_48 )
{
unsigned int V_39 ;
struct V_1 * V_2 ;
for ( V_39 = V_4 -> V_36 - V_48 ; V_39 < V_4 -> V_36 ;
++ V_39 ) {
V_2 = V_4 -> V_31 [ V_39 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_35 == V_46 )
F_6 ( V_2 ) ;
else if ( V_4 -> V_35 == V_49 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
}
static int F_18 ( struct V_3 * V_4 , unsigned int V_48 )
{
unsigned int V_39 ;
for ( V_39 = V_4 -> V_36 - V_48 ; V_39 < V_4 -> V_36 ;
++ V_39 ) {
if ( V_4 -> V_31 [ V_39 ] == NULL )
continue;
if ( V_4 -> V_31 [ V_39 ] -> V_43 == V_50 ) {
F_7 ( 1 , L_9 ) ;
return - V_51 ;
}
}
for ( V_39 = V_4 -> V_36 - V_48 ; V_39 < V_4 -> V_36 ;
++ V_39 ) {
struct V_1 * V_2 = V_4 -> V_31 [ V_39 ] ;
if ( V_2 && V_2 -> V_14 [ 0 ] . V_10 )
F_19 ( V_2 , V_52 , V_2 ) ;
}
F_17 ( V_4 , V_48 ) ;
#ifdef F_20
if ( V_4 -> V_36 ) {
bool V_53 = V_4 -> V_54 != V_4 -> V_55 ||
V_4 -> V_56 != V_4 -> V_57 ;
if ( V_53 || V_58 ) {
F_21 ( L_10 , V_4 ,
V_53 ? L_11 : L_12 ) ;
F_21 ( L_13 ,
V_4 -> V_59 , V_4 -> V_54 ,
V_4 -> V_55 ) ;
F_21 ( L_14 ,
V_4 -> V_56 , V_4 -> V_57 ) ;
}
V_4 -> V_59 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_57 = 0 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
}
for ( V_39 = 0 ; V_39 < V_4 -> V_36 ; ++ V_39 ) {
struct V_1 * V_2 = V_4 -> V_31 [ V_39 ] ;
bool V_53 = V_2 -> V_60 != V_2 -> V_61 ||
V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ||
V_2 -> V_74 != V_2 -> V_75 ;
if ( V_53 || V_58 ) {
F_21 ( L_15 ,
V_4 , V_39 , V_53 ? L_11 : L_12 ) ;
F_21 ( L_16 ,
V_2 -> V_74 , V_2 -> V_75 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
F_21 ( L_17 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_21 ( L_18 ,
V_2 -> V_60 , V_2 -> V_61 ,
V_2 -> V_62 , V_2 -> V_63 ,
V_2 -> V_76 ) ;
F_21 ( L_19 ,
V_2 -> V_64 , V_2 -> V_65 ) ;
F_21 ( L_20 ,
V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_68 , V_2 -> V_69 ) ;
F_21 ( L_21 ,
V_2 -> V_77 ,
V_2 -> V_78 ,
V_2 -> V_79 ,
V_2 -> V_80 ) ;
}
}
#endif
for ( V_39 = V_4 -> V_36 - V_48 ; V_39 < V_4 -> V_36 ;
++ V_39 ) {
F_15 ( V_4 -> V_31 [ V_39 ] ) ;
V_4 -> V_31 [ V_39 ] = NULL ;
}
V_4 -> V_36 -= V_48 ;
if ( ! V_4 -> V_36 ) {
V_4 -> V_35 = 0 ;
F_22 ( & V_4 -> V_81 ) ;
}
return 0 ;
}
bool F_23 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
void * V_10 = V_2 -> V_14 [ V_11 ] . V_10 ;
if ( V_10 && F_24 ( V_2 , V_82 , V_10 ) > 1 )
return true ;
}
return false ;
}
static bool F_25 ( struct V_3 * V_4 )
{
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_36 ; ++ V_39 ) {
if ( F_23 ( V_4 , V_4 -> V_31 [ V_39 ] ) )
return true ;
}
return false ;
}
void F_26 ( struct V_3 * V_4 , unsigned int V_21 , void * V_83 )
{
F_27 ( V_4 , V_84 , V_4 -> V_31 [ V_21 ] , V_83 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_85 & V_86 ) || ! V_4 -> V_87 -> V_88 ||
! V_4 -> V_87 -> V_22 )
return - V_89 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_85 & V_90 ) || ! V_4 -> V_87 -> V_16 ||
! V_4 -> V_87 -> V_19 || ! V_4 -> V_87 -> V_91 )
return - V_89 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_85 & V_92 ) || ! V_4 -> V_87 -> V_93 ||
! V_4 -> V_87 -> V_27 || ! V_4 -> V_87 -> V_94 ||
! V_4 -> V_87 -> V_26 )
return - V_89 ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 ,
enum V_34 V_35 , unsigned int type )
{
if ( V_35 != V_46 && V_35 != V_95 &&
V_35 != V_49 ) {
F_7 ( 1 , L_22 ) ;
return - V_89 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_23 ) ;
return - V_89 ;
}
if ( V_35 == V_46 && F_29 ( V_4 ) ) {
F_7 ( 1 , L_24 ) ;
return - V_89 ;
}
if ( V_35 == V_95 && F_28 ( V_4 ) ) {
F_7 ( 1 , L_25 ) ;
return - V_89 ;
}
if ( V_35 == V_49 && F_30 ( V_4 ) ) {
F_7 ( 1 , L_26 ) ;
return - V_89 ;
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_27 ) ;
return - V_96 ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 , enum V_34 V_35 ,
unsigned int * V_97 )
{
unsigned int V_36 , V_98 , V_12 = 0 ;
unsigned V_37 [ V_38 ] = { } ;
int V_40 ;
if ( V_4 -> V_99 ) {
F_7 ( 1 , L_28 ) ;
return - V_96 ;
}
if ( * V_97 == 0 || V_4 -> V_36 != 0 || V_4 -> V_35 != V_35 ) {
F_34 ( & V_4 -> V_100 ) ;
if ( V_4 -> V_35 == V_46 && F_25 ( V_4 ) ) {
F_35 ( & V_4 -> V_100 ) ;
F_7 ( 1 , L_29 ) ;
return - V_96 ;
}
F_36 ( V_4 ) ;
V_40 = F_18 ( V_4 , V_4 -> V_36 ) ;
F_35 ( & V_4 -> V_100 ) ;
if ( V_40 )
return V_40 ;
if ( * V_97 == 0 )
return 0 ;
}
V_36 = F_37 (unsigned int, *count, VB2_MAX_FRAME) ;
V_36 = F_38 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_17 , 0 , sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_35 = V_35 ;
V_40 = F_39 ( V_4 , V_101 , V_4 , & V_36 , & V_12 ,
V_37 , V_4 -> V_17 ) ;
if ( V_40 )
return V_40 ;
V_98 =
F_13 ( V_4 , V_35 , V_36 , V_12 , V_37 ) ;
if ( V_98 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_20 ;
}
if ( V_98 < V_4 -> V_102 )
V_40 = - V_20 ;
if ( ! V_40 && V_98 < V_36 ) {
V_36 = V_98 ;
V_12 = 0 ;
V_40 = F_39 ( V_4 , V_101 , V_4 , & V_36 ,
& V_12 , V_37 , V_4 -> V_17 ) ;
if ( ! V_40 && V_98 < V_36 )
V_40 = - V_20 ;
}
F_34 ( & V_4 -> V_100 ) ;
V_4 -> V_36 = V_98 ;
if ( V_40 < 0 ) {
F_18 ( V_4 , V_98 ) ;
F_35 ( & V_4 -> V_100 ) ;
return V_40 ;
}
F_35 ( & V_4 -> V_100 ) ;
* V_97 = V_98 ;
V_4 -> V_103 = ! V_4 -> V_7 ;
return 0 ;
}
int F_40 ( struct V_3 * V_4 , enum V_34 V_35 ,
unsigned int * V_97 , unsigned V_104 ,
const unsigned V_105 [] )
{
unsigned int V_12 = 0 , V_36 , V_98 ;
unsigned V_37 [ V_38 ] = { } ;
int V_40 ;
if ( V_4 -> V_36 == V_106 ) {
F_7 ( 1 , L_31 ) ;
return - V_107 ;
}
if ( ! V_4 -> V_36 ) {
memset ( V_4 -> V_17 , 0 , sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_35 = V_35 ;
V_4 -> V_103 = ! V_4 -> V_7 ;
}
V_36 = F_41 ( * V_97 , V_106 - V_4 -> V_36 ) ;
if ( V_104 && V_105 ) {
V_12 = V_104 ;
memcpy ( V_37 , V_105 , sizeof( V_37 ) ) ;
}
V_40 = F_39 ( V_4 , V_101 , V_4 , & V_36 ,
& V_12 , V_37 , V_4 -> V_17 ) ;
if ( V_40 )
return V_40 ;
V_98 = F_13 ( V_4 , V_35 , V_36 ,
V_12 , V_37 ) ;
if ( V_98 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_20 ;
}
if ( V_98 < V_36 ) {
V_36 = V_98 ;
V_40 = F_39 ( V_4 , V_101 , V_4 , & V_36 ,
& V_12 , V_37 , V_4 -> V_17 ) ;
if ( ! V_40 && V_98 < V_36 )
V_40 = - V_20 ;
}
F_34 ( & V_4 -> V_100 ) ;
V_4 -> V_36 += V_98 ;
if ( V_40 < 0 ) {
F_18 ( V_4 , V_98 ) ;
F_35 ( & V_4 -> V_100 ) ;
return - V_20 ;
}
F_35 ( & V_4 -> V_100 ) ;
* V_97 = V_98 ;
return 0 ;
}
void * F_42 ( struct V_1 * V_2 , unsigned int V_108 )
{
if ( V_108 > V_2 -> V_12 || ! V_2 -> V_14 [ V_108 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_109 , V_2 -> V_14 [ V_108 ] . V_10 ) ;
}
void * F_43 ( struct V_1 * V_2 , unsigned int V_108 )
{
if ( V_108 >= V_2 -> V_12 || ! V_2 -> V_14 [ V_108 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_110 , V_2 -> V_14 [ V_108 ] . V_10 ) ;
}
void F_44 ( struct V_1 * V_2 , enum V_111 V_43 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_112 ;
unsigned int V_11 ;
if ( F_45 ( V_2 -> V_43 != V_113 ) )
return;
if ( F_45 ( V_43 != V_114 &&
V_43 != V_115 &&
V_43 != V_116 &&
V_43 != V_117 ) )
V_43 = V_115 ;
#ifdef F_20
V_2 -> V_71 ++ ;
#endif
F_7 ( 4 , L_32 ,
V_2 -> V_21 , V_43 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_118 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
F_46 ( & V_4 -> V_119 , V_112 ) ;
if ( V_43 == V_116 ||
V_43 == V_117 ) {
V_2 -> V_43 = V_116 ;
} else {
F_47 ( & V_2 -> V_120 , & V_4 -> V_121 ) ;
V_2 -> V_43 = V_43 ;
}
F_48 ( & V_4 -> V_122 ) ;
F_49 ( & V_4 -> V_119 , V_112 ) ;
F_50 ( V_4 , V_2 ) ;
switch ( V_43 ) {
case V_116 :
return;
case V_117 :
if ( V_4 -> V_123 )
F_51 ( V_2 ) ;
return;
default:
F_52 ( & V_4 -> V_124 ) ;
break;
}
}
void F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_112 ;
F_46 ( & V_4 -> V_119 , V_112 ) ;
F_54 (vb, &q->done_list, done_entry)
V_2 -> V_43 = V_115 ;
F_49 ( & V_4 -> V_119 , V_112 ) ;
}
static int F_55 ( struct V_1 * V_2 , const void * V_83 )
{
int V_40 = 0 ;
if ( V_83 )
V_40 = F_56 ( V_2 -> V_3 , V_125 ,
V_2 , V_83 , V_2 -> V_14 ) ;
return V_40 ? V_40 : F_16 ( V_2 , V_126 , V_2 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_83 )
{
struct V_23 V_14 [ V_38 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_40 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_127 = V_2 -> V_14 [ 0 ] . V_10 == NULL ;
memset ( V_14 , 0 , sizeof( V_14 [ 0 ] ) * V_2 -> V_12 ) ;
if ( V_83 )
V_40 = F_56 ( V_2 -> V_3 , V_125 ,
V_2 , V_83 , V_14 ) ;
if ( V_40 )
return V_40 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_32 . V_128 &&
V_2 -> V_14 [ V_11 ] . V_32 . V_128 == V_14 [ V_11 ] . V_32 . V_128
&& V_2 -> V_14 [ V_11 ] . V_15 == V_14 [ V_11 ] . V_15 )
continue;
F_7 ( 3 , L_33
L_34 , V_11 ) ;
if ( V_14 [ V_11 ] . V_15 < V_2 -> V_14 [ V_11 ] . V_45 ) {
F_7 ( 1 , L_35
L_36 ,
V_14 [ V_11 ] . V_15 ,
V_2 -> V_14 [ V_11 ] . V_45 ,
V_11 ) ;
V_40 = - V_89 ;
goto V_129;
}
if ( V_2 -> V_14 [ V_11 ] . V_10 ) {
if ( ! V_127 ) {
V_127 = true ;
F_19 ( V_2 , V_52 , V_2 ) ;
}
F_5 ( V_2 , V_22 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
}
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
V_2 -> V_14 [ V_11 ] . V_130 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
V_2 -> V_14 [ V_11 ] . V_32 . V_128 = 0 ;
V_2 -> V_14 [ V_11 ] . V_131 = 0 ;
V_10 = F_3 ( V_2 , V_88 , V_4 -> V_17 [ V_11 ] ,
V_14 [ V_11 ] . V_32 . V_128 ,
V_14 [ V_11 ] . V_15 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
F_7 ( 1 , L_37
L_38 , V_11 ) ;
V_40 = V_10 ? F_58 ( V_10 ) : - V_89 ;
goto V_129;
}
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_130 = V_14 [ V_11 ] . V_130 ;
V_2 -> V_14 [ V_11 ] . V_15 = V_14 [ V_11 ] . V_15 ;
V_2 -> V_14 [ V_11 ] . V_32 . V_128 = V_14 [ V_11 ] . V_32 . V_128 ;
V_2 -> V_14 [ V_11 ] . V_131 = V_14 [ V_11 ] . V_131 ;
}
if ( V_127 ) {
V_40 = F_16 ( V_2 , V_47 , V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_39 ) ;
goto V_129;
}
}
V_40 = F_16 ( V_2 , V_126 , V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_40 ) ;
F_19 ( V_2 , V_52 , V_2 ) ;
goto V_129;
}
return 0 ;
V_129:
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_10 )
F_5 ( V_2 , V_22 ,
V_2 -> V_14 [ V_11 ] . V_10 ) ;
V_2 -> V_14 [ V_11 ] . V_10 = NULL ;
V_2 -> V_14 [ V_11 ] . V_32 . V_128 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
}
return V_40 ;
}
static int F_59 ( struct V_1 * V_2 , const void * V_83 )
{
struct V_23 V_14 [ V_38 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_40 = 0 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_127 = V_2 -> V_14 [ 0 ] . V_10 == NULL ;
memset ( V_14 , 0 , sizeof( V_14 [ 0 ] ) * V_2 -> V_12 ) ;
if ( V_83 )
V_40 = F_56 ( V_2 -> V_3 , V_125 ,
V_2 , V_83 , V_14 ) ;
if ( V_40 )
return V_40 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
struct V_132 * V_28 = F_60 ( V_14 [ V_11 ] . V_32 . V_133 ) ;
if ( F_4 ( V_28 ) ) {
F_7 ( 1 , L_41 ,
V_11 ) ;
V_40 = - V_89 ;
goto V_129;
}
if ( V_14 [ V_11 ] . V_15 == 0 )
V_14 [ V_11 ] . V_15 = V_28 -> V_13 ;
if ( V_14 [ V_11 ] . V_15 < V_2 -> V_14 [ V_11 ] . V_45 ) {
F_7 ( 1 , L_42 ,
V_11 ) ;
V_40 = - V_89 ;
goto V_129;
}
if ( V_28 == V_2 -> V_14 [ V_11 ] . V_28 &&
V_2 -> V_14 [ V_11 ] . V_15 == V_14 [ V_11 ] . V_15 ) {
F_10 ( V_28 ) ;
continue;
}
F_7 ( 1 , L_43 , V_11 ) ;
if ( ! V_127 ) {
V_127 = true ;
F_19 ( V_2 , V_52 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_14 [ V_11 ] ) ;
V_2 -> V_14 [ V_11 ] . V_130 = 0 ;
V_2 -> V_14 [ V_11 ] . V_15 = 0 ;
V_2 -> V_14 [ V_11 ] . V_32 . V_133 = 0 ;
V_2 -> V_14 [ V_11 ] . V_131 = 0 ;
V_10 = F_3 ( V_2 , V_93 ,
V_4 -> V_17 [ V_11 ] , V_28 , V_14 [ V_11 ] . V_15 ,
V_6 ) ;
if ( F_61 ( V_10 ) ) {
F_7 ( 1 , L_44 ) ;
V_40 = F_58 ( V_10 ) ;
F_10 ( V_28 ) ;
goto V_129;
}
V_2 -> V_14 [ V_11 ] . V_28 = V_28 ;
V_2 -> V_14 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_40 = F_24 ( V_2 , V_94 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
if ( V_40 ) {
F_7 ( 1 , L_45 ,
V_11 ) ;
goto V_129;
}
V_2 -> V_14 [ V_11 ] . V_25 = 1 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_14 [ V_11 ] . V_130 = V_14 [ V_11 ] . V_130 ;
V_2 -> V_14 [ V_11 ] . V_15 = V_14 [ V_11 ] . V_15 ;
V_2 -> V_14 [ V_11 ] . V_32 . V_133 = V_14 [ V_11 ] . V_32 . V_133 ;
V_2 -> V_14 [ V_11 ] . V_131 = V_14 [ V_11 ] . V_131 ;
}
if ( V_127 ) {
V_40 = F_16 ( V_2 , V_47 , V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_39 ) ;
goto V_129;
}
}
V_40 = F_16 ( V_2 , V_126 , V_2 ) ;
if ( V_40 ) {
F_7 ( 1 , L_40 ) ;
F_19 ( V_2 , V_52 , V_2 ) ;
goto V_129;
}
return 0 ;
V_129:
F_11 ( V_2 ) ;
return V_40 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
V_2 -> V_43 = V_113 ;
F_62 ( & V_4 -> V_122 ) ;
F_63 ( V_4 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_134 , V_2 -> V_14 [ V_11 ] . V_10 ) ;
F_19 ( V_2 , V_135 , V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_83 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_40 ;
if ( V_4 -> error ) {
F_7 ( 1 , L_46 ) ;
return - V_136 ;
}
V_2 -> V_43 = V_50 ;
switch ( V_4 -> V_35 ) {
case V_46 :
V_40 = F_55 ( V_2 , V_83 ) ;
break;
case V_95 :
V_40 = F_57 ( V_2 , V_83 ) ;
break;
case V_49 :
V_40 = F_59 ( V_2 , V_83 ) ;
break;
default:
F_65 ( 1 , L_47 ) ;
V_40 = - V_89 ;
}
if ( V_40 )
F_7 ( 1 , L_48 , V_40 ) ;
V_2 -> V_43 = V_40 ? V_44 : V_137 ;
return V_40 ;
}
int F_66 ( struct V_3 * V_4 , unsigned int V_21 , void * V_83 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_4 -> V_31 [ V_21 ] ;
if ( V_2 -> V_43 != V_44 ) {
F_7 ( 1 , L_49 ,
V_2 -> V_43 ) ;
return - V_89 ;
}
V_40 = F_64 ( V_2 , V_83 ) ;
if ( V_40 )
return V_40 ;
F_27 ( V_4 , V_84 , V_2 , V_83 ) ;
F_7 ( 1 , L_50 , V_2 -> V_21 ) ;
return V_40 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_40 ;
F_54 (vb, &q->queued_list, queued_entry)
F_51 ( V_2 ) ;
V_4 -> V_123 = 1 ;
V_40 = F_39 ( V_4 , V_138 , V_4 ,
F_68 ( & V_4 -> V_122 ) ) ;
if ( ! V_40 )
return 0 ;
V_4 -> V_123 = 0 ;
F_7 ( 1 , L_51 ) ;
if ( F_45 ( F_68 ( & V_4 -> V_122 ) ) ) {
unsigned V_139 ;
for ( V_139 = 0 ; V_139 < V_4 -> V_36 ; ++ V_139 ) {
V_2 = V_4 -> V_31 [ V_139 ] ;
if ( V_2 -> V_43 == V_113 )
F_44 ( V_2 , V_116 ) ;
}
F_45 ( F_68 ( & V_4 -> V_122 ) ) ;
}
F_45 ( ! F_69 ( & V_4 -> V_121 ) ) ;
return V_40 ;
}
int F_70 ( struct V_3 * V_4 , unsigned int V_21 , void * V_83 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_4 -> V_31 [ V_21 ] ;
switch ( V_2 -> V_43 ) {
case V_44 :
V_40 = F_64 ( V_2 , V_83 ) ;
if ( V_40 )
return V_40 ;
break;
case V_137 :
break;
case V_50 :
F_7 ( 1 , L_52 ) ;
return - V_89 ;
default:
F_7 ( 1 , L_49 , V_2 -> V_43 ) ;
return - V_89 ;
}
F_47 ( & V_2 -> V_140 , & V_4 -> V_81 ) ;
V_4 -> V_141 ++ ;
V_4 -> V_103 = false ;
V_2 -> V_43 = V_116 ;
if ( V_83 )
F_27 ( V_4 , V_142 , V_2 , V_83 ) ;
F_71 ( V_4 , V_2 ) ;
if ( V_4 -> V_123 )
F_51 ( V_2 ) ;
if ( V_83 )
F_27 ( V_4 , V_84 , V_2 , V_83 ) ;
if ( V_4 -> V_99 && ! V_4 -> V_123 &&
V_4 -> V_141 >= V_4 -> V_102 ) {
V_40 = F_67 ( V_4 ) ;
if ( V_40 )
return V_40 ;
}
F_7 ( 1 , L_53 , V_2 -> V_21 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int V_143 )
{
for (; ; ) {
int V_40 ;
if ( ! V_4 -> V_99 ) {
F_7 ( 1 , L_54 ) ;
return - V_89 ;
}
if ( V_4 -> error ) {
F_7 ( 1 , L_55 ) ;
return - V_136 ;
}
if ( V_4 -> V_144 ) {
F_7 ( 3 , L_56 ) ;
return - V_145 ;
}
if ( ! F_69 ( & V_4 -> V_121 ) ) {
break;
}
if ( V_143 ) {
F_7 ( 1 , L_57
L_58 ) ;
return - V_51 ;
}
F_73 ( V_4 , V_146 , V_4 ) ;
F_7 ( 3 , L_59 ) ;
V_40 = F_74 ( V_4 -> V_124 ,
! F_69 ( & V_4 -> V_121 ) || ! V_4 -> V_99 ||
V_4 -> error ) ;
F_73 ( V_4 , V_147 , V_4 ) ;
if ( V_40 ) {
F_7 ( 1 , L_60 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
int V_143 )
{
unsigned long V_112 ;
int V_40 ;
V_40 = F_72 ( V_4 , V_143 ) ;
if ( V_40 )
return V_40 ;
F_46 ( & V_4 -> V_119 , V_112 ) ;
* V_2 = F_76 ( & V_4 -> V_121 , struct V_1 , V_120 ) ;
F_77 ( & ( * V_2 ) -> V_120 ) ;
F_49 ( & V_4 -> V_119 , V_112 ) ;
return V_40 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_99 ) {
F_7 ( 1 , L_54 ) ;
return - V_89 ;
}
if ( V_4 -> V_123 )
F_79 ( V_4 -> V_124 , ! F_68 ( & V_4 -> V_122 ) ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_139 ;
if ( V_2 -> V_43 == V_44 )
return;
V_2 -> V_43 = V_44 ;
if ( V_4 -> V_35 == V_49 )
for ( V_139 = 0 ; V_139 < V_2 -> V_12 ; ++ V_139 ) {
if ( ! V_2 -> V_14 [ V_139 ] . V_25 )
continue;
F_5 ( V_2 , V_26 , V_2 -> V_14 [ V_139 ] . V_10 ) ;
V_2 -> V_14 [ V_139 ] . V_25 = 0 ;
}
}
int F_81 ( struct V_3 * V_4 , unsigned int * V_148 , void * V_83 ,
bool V_143 )
{
struct V_1 * V_2 = NULL ;
int V_40 ;
V_40 = F_75 ( V_4 , & V_2 , V_143 ) ;
if ( V_40 < 0 )
return V_40 ;
switch ( V_2 -> V_43 ) {
case V_114 :
F_7 ( 3 , L_61 ) ;
break;
case V_115 :
F_7 ( 3 , L_62 ) ;
break;
default:
F_7 ( 1 , L_63 ) ;
return - V_89 ;
}
F_19 ( V_2 , V_149 , V_2 ) ;
if ( V_148 )
* V_148 = V_2 -> V_21 ;
if ( V_83 )
F_27 ( V_4 , V_84 , V_2 , V_83 ) ;
F_77 ( & V_2 -> V_140 ) ;
V_4 -> V_141 -- ;
F_82 ( V_4 , V_2 ) ;
F_80 ( V_2 ) ;
F_7 ( 1 , L_64 ,
V_2 -> V_21 , V_2 -> V_43 ) ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
unsigned int V_139 ;
if ( V_4 -> V_123 )
F_73 ( V_4 , V_150 , V_4 ) ;
if ( F_45 ( F_68 ( & V_4 -> V_122 ) ) ) {
for ( V_139 = 0 ; V_139 < V_4 -> V_36 ; ++ V_139 )
if ( V_4 -> V_31 [ V_139 ] -> V_43 == V_113 )
F_44 ( V_4 -> V_31 [ V_139 ] , V_115 ) ;
F_45 ( F_68 ( & V_4 -> V_122 ) ) ;
}
V_4 -> V_99 = 0 ;
V_4 -> V_123 = 0 ;
V_4 -> V_141 = 0 ;
V_4 -> error = 0 ;
F_22 ( & V_4 -> V_81 ) ;
F_22 ( & V_4 -> V_121 ) ;
F_83 ( & V_4 -> V_122 , 0 ) ;
F_84 ( & V_4 -> V_124 ) ;
for ( V_139 = 0 ; V_139 < V_4 -> V_36 ; ++ V_139 ) {
struct V_1 * V_2 = V_4 -> V_31 [ V_139 ] ;
if ( V_2 -> V_43 != V_44 ) {
V_2 -> V_43 = V_137 ;
F_19 ( V_2 , V_149 , V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
int F_85 ( struct V_3 * V_4 , unsigned int type )
{
int V_40 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_89 ;
}
if ( V_4 -> V_99 ) {
F_7 ( 3 , L_66 ) ;
return 0 ;
}
if ( ! V_4 -> V_36 ) {
F_7 ( 1 , L_67 ) ;
return - V_89 ;
}
if ( V_4 -> V_36 < V_4 -> V_102 ) {
F_7 ( 1 , L_68 ,
V_4 -> V_102 ) ;
return - V_89 ;
}
if ( V_4 -> V_141 >= V_4 -> V_102 ) {
V_40 = F_67 ( V_4 ) ;
if ( V_40 ) {
F_36 ( V_4 ) ;
return V_40 ;
}
}
V_4 -> V_99 = 1 ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
void F_86 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_84 ( & V_4 -> V_124 ) ;
}
int F_87 ( struct V_3 * V_4 , unsigned int type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_89 ;
}
F_36 ( V_4 ) ;
V_4 -> V_103 = ! V_4 -> V_7 ;
V_4 -> V_144 = false ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
static int F_88 ( struct V_3 * V_4 , unsigned long V_29 ,
unsigned int * V_151 , unsigned int * V_152 )
{
struct V_1 * V_2 ;
unsigned int V_39 , V_11 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_36 ; ++ V_39 ) {
V_2 = V_4 -> V_31 [ V_39 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_14 [ V_11 ] . V_32 . V_33 == V_29 ) {
* V_151 = V_39 ;
* V_152 = V_11 ;
return 0 ;
}
}
}
return - V_89 ;
}
int F_89 ( struct V_3 * V_4 , int * V_133 , unsigned int type ,
unsigned int V_21 , unsigned int V_11 , unsigned int V_112 )
{
struct V_1 * V_2 = NULL ;
struct V_23 * V_153 ;
int V_40 ;
struct V_132 * V_28 ;
if ( V_4 -> V_35 != V_46 ) {
F_7 ( 1 , L_70 ) ;
return - V_89 ;
}
if ( ! V_4 -> V_87 -> V_154 ) {
F_7 ( 1 , L_71 ) ;
return - V_89 ;
}
if ( V_112 & ~ ( V_155 | V_156 ) ) {
F_7 ( 1 , L_72 ) ;
return - V_89 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_73 ) ;
return - V_89 ;
}
if ( V_21 >= V_4 -> V_36 ) {
F_7 ( 1 , L_74 ) ;
return - V_89 ;
}
V_2 = V_4 -> V_31 [ V_21 ] ;
if ( V_11 >= V_2 -> V_12 ) {
F_7 ( 1 , L_75 ) ;
return - V_89 ;
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_76 ) ;
return - V_96 ;
}
V_153 = & V_2 -> V_14 [ V_11 ] ;
V_28 = F_3 ( V_2 , V_154 , V_153 -> V_10 ,
V_112 & V_156 ) ;
if ( F_4 ( V_28 ) ) {
F_7 ( 1 , L_77 ,
V_21 , V_11 ) ;
return - V_89 ;
}
V_40 = F_90 ( V_28 , V_112 & ~ V_156 ) ;
if ( V_40 < 0 ) {
F_7 ( 3 , L_78 ,
V_21 , V_11 , V_40 ) ;
F_10 ( V_28 ) ;
return V_40 ;
}
F_7 ( 3 , L_79 ,
V_21 , V_11 , V_40 ) ;
* V_133 = V_40 ;
return 0 ;
}
int F_91 ( struct V_3 * V_4 , struct V_157 * V_158 )
{
unsigned long V_29 = V_158 -> V_159 << V_160 ;
struct V_1 * V_2 ;
unsigned int V_39 = 0 , V_11 = 0 ;
int V_40 ;
unsigned long V_15 ;
if ( V_4 -> V_35 != V_46 ) {
F_7 ( 1 , L_70 ) ;
return - V_89 ;
}
if ( ! ( V_158 -> V_161 & V_162 ) ) {
F_7 ( 1 , L_80 ) ;
return - V_89 ;
}
if ( V_4 -> V_7 ) {
if ( ! ( V_158 -> V_161 & V_163 ) ) {
F_7 ( 1 , L_81 ) ;
return - V_89 ;
}
} else {
if ( ! ( V_158 -> V_161 & V_164 ) ) {
F_7 ( 1 , L_82 ) ;
return - V_89 ;
}
}
if ( F_32 ( V_4 ) ) {
F_7 ( 1 , L_83 ) ;
return - V_96 ;
}
V_40 = F_88 ( V_4 , V_29 , & V_39 , & V_11 ) ;
if ( V_40 )
return V_40 ;
V_2 = V_4 -> V_31 [ V_39 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_11 ] . V_15 ) ;
if ( V_15 < ( V_158 -> V_165 - V_158 -> V_166 ) ) {
F_7 ( 1 ,
L_84 ) ;
return - V_89 ;
}
F_34 ( & V_4 -> V_100 ) ;
V_40 = F_24 ( V_2 , V_91 , V_2 -> V_14 [ V_11 ] . V_10 , V_158 ) ;
F_35 ( & V_4 -> V_100 ) ;
if ( V_40 )
return V_40 ;
F_7 ( 3 , L_85 , V_39 , V_11 ) ;
return 0 ;
}
unsigned long F_92 ( struct V_3 * V_4 ,
unsigned long V_167 ,
unsigned long V_168 ,
unsigned long V_169 ,
unsigned long V_112 )
{
unsigned long V_29 = V_169 << V_160 ;
struct V_1 * V_2 ;
unsigned int V_39 , V_11 ;
void * V_109 ;
int V_40 ;
if ( V_4 -> V_35 != V_46 ) {
F_7 ( 1 , L_70 ) ;
return - V_89 ;
}
V_40 = F_88 ( V_4 , V_29 , & V_39 , & V_11 ) ;
if ( V_40 )
return V_40 ;
V_2 = V_4 -> V_31 [ V_39 ] ;
V_109 = F_42 ( V_2 , V_11 ) ;
return V_109 ? ( unsigned long ) V_109 : - V_89 ;
}
int F_93 ( struct V_3 * V_4 )
{
if ( F_45 ( ! V_4 ) ||
F_45 ( ! V_4 -> V_170 ) ||
F_45 ( ! V_4 -> V_87 ) ||
F_45 ( ! V_4 -> type ) ||
F_45 ( ! V_4 -> V_85 ) ||
F_45 ( ! V_4 -> V_170 -> V_101 ) ||
F_45 ( ! V_4 -> V_170 -> V_135 ) )
return - V_89 ;
F_22 ( & V_4 -> V_81 ) ;
F_22 ( & V_4 -> V_121 ) ;
F_94 ( & V_4 -> V_119 ) ;
F_95 ( & V_4 -> V_100 ) ;
F_96 ( & V_4 -> V_124 ) ;
if ( V_4 -> V_41 == 0 )
V_4 -> V_41 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_97 ( struct V_3 * V_4 )
{
F_98 ( V_4 ) ;
F_36 ( V_4 ) ;
F_34 ( & V_4 -> V_100 ) ;
F_18 ( V_4 , V_4 -> V_36 ) ;
F_35 ( & V_4 -> V_100 ) ;
}
unsigned int F_99 ( struct V_3 * V_4 , struct V_171 * V_171 ,
T_1 * V_172 )
{
unsigned long V_173 = F_100 ( V_172 ) ;
struct V_1 * V_2 = NULL ;
unsigned long V_112 ;
if ( ! V_4 -> V_7 && ! ( V_173 & ( V_174 | V_175 ) ) )
return 0 ;
if ( V_4 -> V_7 && ! ( V_173 & ( V_176 | V_177 ) ) )
return 0 ;
if ( V_4 -> V_36 == 0 && ! F_32 ( V_4 ) ) {
if ( ! V_4 -> V_7 && ( V_4 -> V_85 & V_178 ) &&
( V_173 & ( V_174 | V_175 ) ) ) {
if ( F_101 ( V_4 , 1 ) )
return V_179 ;
}
if ( V_4 -> V_7 && ( V_4 -> V_85 & V_180 ) &&
( V_173 & ( V_176 | V_177 ) ) ) {
if ( F_101 ( V_4 , 0 ) )
return V_179 ;
return V_176 | V_177 ;
}
}
if ( ! F_102 ( V_4 ) || V_4 -> error )
return V_179 ;
if ( V_4 -> V_7 && V_4 -> V_181 && V_4 -> V_141 < V_4 -> V_36 )
return V_176 | V_177 ;
if ( F_69 ( & V_4 -> V_121 ) ) {
if ( V_4 -> V_144 )
return V_174 | V_175 ;
F_103 ( V_171 , & V_4 -> V_124 , V_172 ) ;
}
F_46 ( & V_4 -> V_119 , V_112 ) ;
if ( ! F_69 ( & V_4 -> V_121 ) )
V_2 = F_76 ( & V_4 -> V_121 , struct V_1 ,
V_120 ) ;
F_49 ( & V_4 -> V_119 , V_112 ) ;
if ( V_2 && ( V_2 -> V_43 == V_114
|| V_2 -> V_43 == V_115 ) ) {
return ( V_4 -> V_7 ) ?
V_176 | V_177 :
V_174 | V_175 ;
}
return 0 ;
}
static int F_101 ( struct V_3 * V_4 , int V_182 )
{
struct V_183 * V_181 ;
int V_139 , V_40 ;
unsigned int V_97 = 0 ;
if ( F_45 ( ( V_182 && ! ( V_4 -> V_85 & V_178 ) ) ||
( ! V_182 && ! ( V_4 -> V_85 & V_180 ) ) ) )
return - V_89 ;
if ( ! V_4 -> V_87 -> V_109 )
return - V_96 ;
if ( V_4 -> V_99 || V_4 -> V_36 > 0 )
return - V_96 ;
V_97 = 1 ;
F_7 ( 3 , L_86 ,
( V_182 ) ? L_87 : L_88 , V_97 , V_4 -> V_184 ,
V_4 -> V_185 ) ;
V_181 = F_14 ( sizeof( * V_181 ) , V_42 ) ;
if ( V_181 == NULL )
return - V_20 ;
V_181 -> V_186 = V_4 -> V_184 ;
V_181 -> V_187 = V_4 -> V_185 ;
V_181 -> V_97 = V_97 ;
V_181 -> V_35 = V_46 ;
V_181 -> type = V_4 -> type ;
V_4 -> V_181 = V_181 ;
V_40 = F_33 ( V_4 , V_181 -> V_35 , & V_181 -> V_97 ) ;
if ( V_40 )
goto V_188;
if ( V_4 -> V_31 [ 0 ] -> V_12 != 1 ) {
V_40 = - V_96 ;
goto V_189;
}
for ( V_139 = 0 ; V_139 < V_4 -> V_36 ; V_139 ++ ) {
V_181 -> V_31 [ V_139 ] . V_109 = F_42 ( V_4 -> V_31 [ V_139 ] , 0 ) ;
if ( V_181 -> V_31 [ V_139 ] . V_109 == NULL ) {
V_40 = - V_89 ;
goto V_189;
}
V_181 -> V_31 [ V_139 ] . V_13 = F_104 ( V_4 -> V_31 [ V_139 ] , 0 ) ;
}
if ( V_182 ) {
for ( V_139 = 0 ; V_139 < V_4 -> V_36 ; V_139 ++ ) {
V_40 = F_70 ( V_4 , V_139 , NULL ) ;
if ( V_40 )
goto V_189;
V_181 -> V_31 [ V_139 ] . V_190 = 1 ;
}
V_181 -> V_191 = V_4 -> V_36 ;
V_181 -> V_192 = V_4 -> V_36 ;
}
V_40 = F_85 ( V_4 , V_4 -> type ) ;
if ( V_40 )
goto V_189;
return V_40 ;
V_189:
V_181 -> V_97 = 0 ;
F_33 ( V_4 , V_181 -> V_35 , & V_181 -> V_97 ) ;
V_188:
V_4 -> V_181 = NULL ;
F_15 ( V_181 ) ;
return V_40 ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_183 * V_181 = V_4 -> V_181 ;
if ( V_181 ) {
F_87 ( V_4 , V_4 -> type ) ;
V_4 -> V_181 = NULL ;
V_181 -> V_97 = 0 ;
F_33 ( V_4 , V_181 -> V_35 , & V_181 -> V_97 ) ;
F_15 ( V_181 ) ;
F_7 ( 3 , L_89 ) ;
}
return 0 ;
}
static T_2 F_105 ( struct V_3 * V_4 , char T_3 * V_193 , T_2 V_97 ,
T_4 * V_194 , int V_195 , int V_182 )
{
struct V_183 * V_181 ;
struct V_196 * V_197 ;
bool V_198 = V_4 -> V_198 ;
bool V_142 = ! V_182 && V_4 -> V_142 ;
unsigned V_21 ;
int V_40 ;
F_7 ( 3 , L_90 ,
V_182 ? L_87 : L_88 , ( long ) * V_194 , V_97 ,
V_195 ? L_91 : L_12 ) ;
if ( ! V_193 )
return - V_89 ;
if ( ! F_32 ( V_4 ) ) {
V_40 = F_101 ( V_4 , V_182 ) ;
F_7 ( 3 , L_92 , V_40 ) ;
if ( V_40 )
return V_40 ;
}
V_181 = V_4 -> V_181 ;
V_21 = V_181 -> V_192 ;
if ( V_21 >= V_4 -> V_36 ) {
struct V_1 * V_199 ;
V_40 = F_81 ( V_4 , & V_21 , NULL , V_195 ) ;
F_7 ( 5 , L_93 , V_40 ) ;
if ( V_40 )
return V_40 ;
V_181 -> V_200 += 1 ;
V_181 -> V_192 = V_21 ;
V_197 = & V_181 -> V_31 [ V_21 ] ;
V_199 = V_4 -> V_31 [ V_21 ] ;
V_197 -> V_201 = 0 ;
V_197 -> V_190 = 0 ;
V_197 -> V_13 = V_182 ? F_106 ( V_4 -> V_31 [ V_21 ] , 0 )
: F_104 ( V_4 -> V_31 [ V_21 ] , 0 ) ;
if ( V_198 && V_182 &&
V_199 -> V_14 [ 0 ] . V_131 < V_197 -> V_13 ) {
V_197 -> V_201 = V_199 -> V_14 [ 0 ] . V_131 ;
V_197 -> V_13 -= V_197 -> V_201 ;
}
} else {
V_197 = & V_181 -> V_31 [ V_21 ] ;
}
if ( V_197 -> V_201 + V_97 > V_197 -> V_13 ) {
V_97 = V_197 -> V_13 - V_197 -> V_201 ;
F_7 ( 5 , L_94 , V_97 ) ;
}
F_7 ( 3 , L_95 ,
V_97 , V_21 , V_197 -> V_201 ) ;
if ( V_182 )
V_40 = F_107 ( V_193 , V_197 -> V_109 + V_197 -> V_201 , V_97 ) ;
else
V_40 = F_108 ( V_197 -> V_109 + V_197 -> V_201 , V_193 , V_97 ) ;
if ( V_40 ) {
F_7 ( 3 , L_96 ) ;
return - V_202 ;
}
V_197 -> V_201 += V_97 ;
* V_194 += V_97 ;
if ( V_197 -> V_201 == V_197 -> V_13 || ( ! V_182 && V_181 -> V_187 ) ) {
struct V_1 * V_199 = V_4 -> V_31 [ V_21 ] ;
if ( V_182 && V_181 -> V_186 && V_181 -> V_200 == 1 ) {
F_7 ( 3 , L_97 ) ;
return F_98 ( V_4 ) ;
}
V_199 -> V_14 [ 0 ] . V_130 = V_197 -> V_201 ;
if ( V_142 )
V_199 -> V_203 = F_109 () ;
V_40 = F_70 ( V_4 , V_21 , NULL ) ;
F_7 ( 5 , L_98 , V_40 ) ;
if ( V_40 )
return V_40 ;
V_197 -> V_201 = 0 ;
V_197 -> V_190 = 1 ;
V_197 -> V_13 = F_104 ( V_4 -> V_31 [ V_21 ] , 0 ) ;
V_181 -> V_204 += 1 ;
if ( V_181 -> V_191 < V_4 -> V_36 )
V_181 -> V_191 ++ ;
V_181 -> V_192 = V_181 -> V_191 ;
}
if ( V_40 == 0 )
V_40 = V_97 ;
return V_40 ;
}
T_2 F_110 ( struct V_3 * V_4 , char T_3 * V_193 , T_2 V_97 ,
T_4 * V_194 , int V_143 )
{
return F_105 ( V_4 , V_193 , V_97 , V_194 , V_143 , 1 ) ;
}
T_2 F_111 ( struct V_3 * V_4 , const char T_3 * V_193 , T_2 V_97 ,
T_4 * V_194 , int V_143 )
{
return F_105 ( V_4 , ( char T_3 * ) V_193 , V_97 ,
V_194 , V_143 , 0 ) ;
}
static int F_112 ( void * V_193 )
{
struct V_3 * V_4 = V_193 ;
struct V_205 * V_206 = V_4 -> V_206 ;
bool V_142 = false ;
unsigned V_207 = 0 ;
unsigned V_21 = 0 ;
int V_40 = 0 ;
if ( V_4 -> V_7 ) {
V_207 = V_4 -> V_36 ;
V_142 = V_4 -> V_142 ;
}
F_113 () ;
for (; ; ) {
struct V_1 * V_2 ;
if ( V_207 ) {
V_2 = V_4 -> V_31 [ V_21 ++ ] ;
V_207 -- ;
} else {
F_73 ( V_4 , V_147 , V_4 ) ;
if ( ! V_206 -> V_208 )
V_40 = F_81 ( V_4 , & V_21 , NULL , 0 ) ;
F_73 ( V_4 , V_146 , V_4 ) ;
F_7 ( 5 , L_99 , V_40 ) ;
if ( ! V_40 )
V_2 = V_4 -> V_31 [ V_21 ] ;
}
if ( V_40 || V_206 -> V_208 )
break;
F_114 () ;
if ( V_2 -> V_43 != V_115 )
if ( V_206 -> V_209 ( V_2 , V_206 -> V_210 ) )
break;
F_73 ( V_4 , V_147 , V_4 ) ;
if ( V_142 )
V_2 -> V_203 = F_109 () ; ;
if ( ! V_206 -> V_208 )
V_40 = F_70 ( V_4 , V_2 -> V_21 , NULL ) ;
F_73 ( V_4 , V_146 , V_4 ) ;
if ( V_40 || V_206 -> V_208 )
break;
}
while ( ! F_115 () ) {
F_116 ( V_211 ) ;
F_117 () ;
}
return 0 ;
}
int F_118 ( struct V_3 * V_4 , T_5 V_209 , void * V_210 ,
const char * V_212 )
{
struct V_205 * V_206 ;
int V_40 = 0 ;
if ( V_4 -> V_206 )
return - V_96 ;
if ( F_119 ( V_4 ) )
return - V_96 ;
if ( F_45 ( V_4 -> V_181 ) )
return - V_96 ;
V_206 = F_14 ( sizeof( * V_206 ) , V_42 ) ;
if ( V_206 == NULL )
return - V_20 ;
V_206 -> V_209 = V_209 ;
V_206 -> V_210 = V_210 ;
V_40 = F_101 ( V_4 , ! V_4 -> V_7 ) ;
F_7 ( 3 , L_100 , V_40 ) ;
if ( V_40 )
goto V_213;
V_4 -> V_206 = V_206 ;
V_206 -> V_214 = F_120 ( F_112 , V_4 , L_101 , V_212 ) ;
if ( F_61 ( V_206 -> V_214 ) ) {
V_40 = F_58 ( V_206 -> V_214 ) ;
V_206 -> V_214 = NULL ;
goto V_215;
}
return 0 ;
V_215:
F_98 ( V_4 ) ;
V_213:
F_15 ( V_206 ) ;
return V_40 ;
}
int F_121 ( struct V_3 * V_4 )
{
struct V_205 * V_206 = V_4 -> V_206 ;
int V_129 ;
if ( V_206 == NULL )
return 0 ;
V_206 -> V_208 = true ;
F_86 ( V_4 ) ;
V_129 = F_122 ( V_206 -> V_214 ) ;
F_98 ( V_4 ) ;
V_206 -> V_214 = NULL ;
F_15 ( V_206 ) ;
V_4 -> V_206 = NULL ;
return V_129 ;
}
