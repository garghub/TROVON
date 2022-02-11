static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
void * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
unsigned long V_13 = F_2 ( V_4 -> V_14 [ V_11 ] ) ;
V_10 = F_3 ( V_2 , V_15 , V_4 -> V_16 [ V_11 ] ,
V_13 , V_6 , V_4 -> V_17 ) ;
if ( F_4 ( V_10 ) )
goto free;
V_2 -> V_18 [ V_11 ] . V_10 = V_10 ;
V_2 -> V_18 [ V_11 ] . V_19 = V_4 -> V_14 [ V_11 ] ;
}
return 0 ;
free:
for (; V_11 > 0 ; -- V_11 ) {
F_5 ( V_2 , V_20 , V_2 -> V_18 [ V_11 - 1 ] . V_10 ) ;
V_2 -> V_18 [ V_11 - 1 ] . V_10 = NULL ;
}
return - V_21 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
F_5 ( V_2 , V_20 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
V_2 -> V_18 [ V_11 ] . V_10 = NULL ;
F_7 ( 3 , L_1 , V_11 , V_2 -> V_22 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_18 [ V_11 ] . V_10 )
F_5 ( V_2 , V_23 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
V_2 -> V_18 [ V_11 ] . V_10 = NULL ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( ! V_25 -> V_10 )
return;
if ( V_25 -> V_26 )
F_5 ( V_2 , V_27 , V_25 -> V_10 ) ;
F_5 ( V_2 , V_28 , V_25 -> V_10 ) ;
F_10 ( V_25 -> V_29 ) ;
V_25 -> V_10 = NULL ;
V_25 -> V_29 = NULL ;
V_25 -> V_26 = 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_9 ( V_2 , & V_2 -> V_18 [ V_11 ] ) ;
}
static void F_12 ( struct V_3 * V_4 , unsigned int V_30 )
{
unsigned int V_31 , V_11 ;
struct V_1 * V_2 ;
for ( V_31 = V_4 -> V_32 ; V_31 < V_4 -> V_32 + V_30 ; ++ V_31 ) {
V_2 = V_4 -> V_33 [ V_31 ] ;
if ( ! V_2 )
continue;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
V_2 -> V_18 [ V_11 ] . V_19 = V_4 -> V_14 [ V_11 ] ;
}
}
static void F_13 ( struct V_3 * V_4 , unsigned int V_30 )
{
unsigned int V_31 , V_11 ;
struct V_1 * V_2 ;
unsigned long V_34 ;
if ( V_4 -> V_32 ) {
struct V_24 * V_25 ;
V_2 = V_4 -> V_33 [ V_4 -> V_32 - 1 ] ;
V_25 = & V_2 -> V_18 [ V_2 -> V_12 - 1 ] ;
V_34 = F_2 ( V_25 -> V_35 . V_36 + V_25 -> V_19 ) ;
} else {
V_34 = 0 ;
}
for ( V_31 = V_4 -> V_32 ; V_31 < V_4 -> V_32 + V_30 ; ++ V_31 ) {
V_2 = V_4 -> V_33 [ V_31 ] ;
if ( ! V_2 )
continue;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_18 [ V_11 ] . V_35 . V_36 = V_34 ;
F_7 ( 3 , L_2 ,
V_31 , V_11 , V_34 ) ;
V_34 += V_2 -> V_18 [ V_11 ] . V_19 ;
V_34 = F_2 ( V_34 ) ;
}
}
}
static int F_14 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int V_32 , unsigned int V_12 )
{
unsigned int V_31 ;
struct V_1 * V_2 ;
int V_39 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
V_2 = F_15 ( V_4 -> V_40 , V_41 ) ;
if ( ! V_2 ) {
F_7 ( 1 , L_3 ) ;
break;
}
V_2 -> V_42 = V_43 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_22 = V_4 -> V_32 + V_31 ;
V_2 -> type = V_4 -> type ;
V_2 -> V_38 = V_38 ;
if ( V_38 == V_44 ) {
V_39 = F_1 ( V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_4
L_5 , V_31 ) ;
F_16 ( V_2 ) ;
break;
}
V_39 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_6
L_7 , V_31 , V_2 ) ;
F_6 ( V_2 ) ;
F_16 ( V_2 ) ;
break;
}
}
V_4 -> V_33 [ V_4 -> V_32 + V_31 ] = V_2 ;
}
F_12 ( V_4 , V_31 ) ;
if ( V_38 == V_44 )
F_13 ( V_4 , V_31 ) ;
F_7 ( 1 , L_8 ,
V_31 , V_12 ) ;
return V_31 ;
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_46 )
{
unsigned int V_31 ;
struct V_1 * V_2 ;
for ( V_31 = V_4 -> V_32 - V_46 ; V_31 < V_4 -> V_32 ;
++ V_31 ) {
V_2 = V_4 -> V_33 [ V_31 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_38 == V_44 )
F_6 ( V_2 ) ;
else if ( V_4 -> V_38 == V_47 )
F_11 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
}
static int F_19 ( struct V_3 * V_4 , unsigned int V_46 )
{
unsigned int V_31 ;
for ( V_31 = V_4 -> V_32 - V_46 ; V_31 < V_4 -> V_32 ;
++ V_31 ) {
if ( V_4 -> V_33 [ V_31 ] == NULL )
continue;
if ( V_4 -> V_33 [ V_31 ] -> V_42 == V_48 ) {
F_7 ( 1 , L_9 ) ;
return - V_49 ;
}
}
for ( V_31 = V_4 -> V_32 - V_46 ; V_31 < V_4 -> V_32 ;
++ V_31 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_31 ] ;
if ( V_2 && V_2 -> V_18 [ 0 ] . V_10 )
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_18 ( V_4 , V_46 ) ;
#ifdef F_21
if ( V_4 -> V_32 ) {
bool V_51 = V_4 -> V_52 != V_4 -> V_53 ||
V_4 -> V_54 != V_4 -> V_55 ;
if ( V_51 || V_56 ) {
F_22 ( L_10 , V_4 ,
V_51 ? L_11 : L_12 ) ;
F_22 ( L_13 ,
V_4 -> V_57 , V_4 -> V_52 ,
V_4 -> V_53 ) ;
F_22 ( L_14 ,
V_4 -> V_54 , V_4 -> V_55 ) ;
}
V_4 -> V_57 = 0 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
V_4 -> V_52 = 0 ;
V_4 -> V_53 = 0 ;
}
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; ++ V_31 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_31 ] ;
bool V_51 = V_2 -> V_58 != V_2 -> V_59 ||
V_2 -> V_60 != V_2 -> V_61 ||
V_2 -> V_62 != V_2 -> V_63 ||
V_2 -> V_64 != V_2 -> V_65 ||
V_2 -> V_66 != V_2 -> V_67 ||
V_2 -> V_68 != V_2 -> V_69 ||
V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_72 != V_2 -> V_73 ;
if ( V_51 || V_56 ) {
F_22 ( L_15 ,
V_4 , V_31 , V_51 ? L_11 : L_12 ) ;
F_22 ( L_16 ,
V_2 -> V_72 , V_2 -> V_73 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_22 ( L_17 ,
V_2 -> V_68 , V_2 -> V_69 ) ;
F_22 ( L_18 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_60 , V_2 -> V_61 ,
V_2 -> V_74 ) ;
F_22 ( L_19 ,
V_2 -> V_62 , V_2 -> V_63 ) ;
F_22 ( L_20 ,
V_2 -> V_64 , V_2 -> V_65 ,
V_2 -> V_66 , V_2 -> V_67 ) ;
F_22 ( L_21 ,
V_2 -> V_75 ,
V_2 -> V_76 ,
V_2 -> V_77 ,
V_2 -> V_78 ) ;
}
}
#endif
for ( V_31 = V_4 -> V_32 - V_46 ; V_31 < V_4 -> V_32 ;
++ V_31 ) {
F_16 ( V_4 -> V_33 [ V_31 ] ) ;
V_4 -> V_33 [ V_31 ] = NULL ;
}
V_4 -> V_32 -= V_46 ;
if ( ! V_4 -> V_32 ) {
V_4 -> V_38 = 0 ;
F_23 ( & V_4 -> V_79 ) ;
}
return 0 ;
}
bool F_24 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
void * V_10 = V_2 -> V_18 [ V_11 ] . V_10 ;
if ( V_10 && F_25 ( V_2 , V_80 , V_10 ) > 1 )
return true ;
}
return false ;
}
static bool F_26 ( struct V_3 * V_4 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; ++ V_31 ) {
if ( F_24 ( V_4 , V_4 -> V_33 [ V_31 ] ) )
return true ;
}
return false ;
}
int F_27 ( struct V_3 * V_4 , unsigned int V_22 , void * V_81 )
{
return F_28 ( V_4 , V_82 , V_4 -> V_33 [ V_22 ] , V_81 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_84 ) || ! V_4 -> V_85 -> V_86 ||
! V_4 -> V_85 -> V_23 )
return - V_87 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_88 ) || ! V_4 -> V_85 -> V_15 ||
! V_4 -> V_85 -> V_20 || ! V_4 -> V_85 -> V_89 )
return - V_87 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_83 & V_90 ) || ! V_4 -> V_85 -> V_91 ||
! V_4 -> V_85 -> V_28 || ! V_4 -> V_85 -> V_92 ||
! V_4 -> V_85 -> V_27 )
return - V_87 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_37 V_38 , unsigned int type )
{
if ( V_38 != V_44 && V_38 != V_93 &&
V_38 != V_47 ) {
F_7 ( 1 , L_22 ) ;
return - V_87 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_23 ) ;
return - V_87 ;
}
if ( V_38 == V_44 && F_30 ( V_4 ) ) {
F_7 ( 1 , L_24 ) ;
return - V_87 ;
}
if ( V_38 == V_93 && F_29 ( V_4 ) ) {
F_7 ( 1 , L_25 ) ;
return - V_87 ;
}
if ( V_38 == V_47 && F_31 ( V_4 ) ) {
F_7 ( 1 , L_26 ) ;
return - V_87 ;
}
if ( F_33 ( V_4 ) ) {
F_7 ( 1 , L_27 ) ;
return - V_94 ;
}
return 0 ;
}
int F_34 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int * V_95 )
{
unsigned int V_32 , V_96 , V_12 = 0 ;
int V_39 ;
if ( V_4 -> V_97 ) {
F_7 ( 1 , L_28 ) ;
return - V_94 ;
}
if ( * V_95 == 0 || V_4 -> V_32 != 0 || V_4 -> V_38 != V_38 ) {
F_35 ( & V_4 -> V_98 ) ;
if ( V_4 -> V_38 == V_44 && F_26 ( V_4 ) ) {
F_36 ( & V_4 -> V_98 ) ;
F_7 ( 1 , L_29 ) ;
return - V_94 ;
}
F_37 ( V_4 ) ;
V_39 = F_19 ( V_4 , V_4 -> V_32 ) ;
F_36 ( & V_4 -> V_98 ) ;
if ( V_39 )
return V_39 ;
if ( * V_95 == 0 )
return 0 ;
}
V_32 = F_38 (unsigned int, *count, VB2_MAX_FRAME) ;
V_32 = F_39 (unsigned int, num_buffers, q->min_buffers_needed) ;
memset ( V_4 -> V_14 , 0 , sizeof( V_4 -> V_14 ) ) ;
memset ( V_4 -> V_16 , 0 , sizeof( V_4 -> V_16 ) ) ;
V_4 -> V_38 = V_38 ;
V_39 = F_40 ( V_4 , V_99 , V_4 , NULL , & V_32 , & V_12 ,
V_4 -> V_14 , V_4 -> V_16 ) ;
if ( V_39 )
return V_39 ;
V_96 =
F_14 ( V_4 , V_38 , V_32 , V_12 ) ;
if ( V_96 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_21 ;
}
if ( V_96 < V_4 -> V_100 )
V_39 = - V_21 ;
if ( ! V_39 && V_96 < V_32 ) {
V_32 = V_96 ;
V_39 = F_40 ( V_4 , V_99 , V_4 , NULL , & V_32 ,
& V_12 , V_4 -> V_14 , V_4 -> V_16 ) ;
if ( ! V_39 && V_96 < V_32 )
V_39 = - V_21 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_4 -> V_32 = V_96 ;
if ( V_39 < 0 ) {
F_19 ( V_4 , V_96 ) ;
F_36 ( & V_4 -> V_98 ) ;
return V_39 ;
}
F_36 ( & V_4 -> V_98 ) ;
* V_95 = V_96 ;
V_4 -> V_101 = ! V_4 -> V_7 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 , enum V_37 V_38 ,
unsigned int * V_95 , const void * V_102 )
{
unsigned int V_12 = 0 , V_32 , V_96 ;
int V_39 ;
if ( V_4 -> V_32 == V_103 ) {
F_7 ( 1 , L_31 ) ;
return - V_104 ;
}
if ( ! V_4 -> V_32 ) {
memset ( V_4 -> V_14 , 0 , sizeof( V_4 -> V_14 ) ) ;
memset ( V_4 -> V_16 , 0 , sizeof( V_4 -> V_16 ) ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_101 = ! V_4 -> V_7 ;
}
V_32 = F_42 ( * V_95 , V_103 - V_4 -> V_32 ) ;
V_39 = F_40 ( V_4 , V_99 , V_4 , V_102 , & V_32 ,
& V_12 , V_4 -> V_14 , V_4 -> V_16 ) ;
if ( V_39 )
return V_39 ;
V_96 = F_14 ( V_4 , V_38 , V_32 ,
V_12 ) ;
if ( V_96 == 0 ) {
F_7 ( 1 , L_30 ) ;
return - V_21 ;
}
if ( V_96 < V_32 ) {
V_32 = V_96 ;
V_39 = F_40 ( V_4 , V_99 , V_4 , V_102 , & V_32 ,
& V_12 , V_4 -> V_14 , V_4 -> V_16 ) ;
if ( ! V_39 && V_96 < V_32 )
V_39 = - V_21 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_4 -> V_32 += V_96 ;
if ( V_39 < 0 ) {
F_19 ( V_4 , V_96 ) ;
F_36 ( & V_4 -> V_98 ) ;
return - V_21 ;
}
F_36 ( & V_4 -> V_98 ) ;
* V_95 = V_96 ;
return 0 ;
}
void * F_43 ( struct V_1 * V_2 , unsigned int V_105 )
{
if ( V_105 > V_2 -> V_12 || ! V_2 -> V_18 [ V_105 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_106 , V_2 -> V_18 [ V_105 ] . V_10 ) ;
}
void * F_44 ( struct V_1 * V_2 , unsigned int V_105 )
{
if ( V_105 >= V_2 -> V_12 || ! V_2 -> V_18 [ V_105 ] . V_10 )
return NULL ;
return F_3 ( V_2 , V_107 , V_2 -> V_18 [ V_105 ] . V_10 ) ;
}
void F_45 ( struct V_1 * V_2 , enum V_108 V_42 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_109 ;
unsigned int V_11 ;
if ( F_46 ( V_2 -> V_42 != V_110 ) )
return;
if ( F_46 ( V_42 != V_111 &&
V_42 != V_112 &&
V_42 != V_113 &&
V_42 != V_114 ) )
V_42 = V_112 ;
#ifdef F_21
V_2 -> V_69 ++ ;
#endif
F_7 ( 4 , L_32 ,
V_2 -> V_22 , V_42 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_115 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
F_47 ( & V_4 -> V_116 , V_109 ) ;
if ( V_42 == V_113 ||
V_42 == V_114 ) {
V_2 -> V_42 = V_113 ;
} else {
F_48 ( & V_2 -> V_117 , & V_4 -> V_118 ) ;
V_2 -> V_42 = V_42 ;
}
F_49 ( & V_4 -> V_119 ) ;
F_50 ( & V_4 -> V_116 , V_109 ) ;
F_51 ( V_4 , V_2 ) ;
switch ( V_42 ) {
case V_113 :
return;
case V_114 :
if ( V_4 -> V_120 )
F_52 ( V_2 ) ;
return;
default:
F_53 ( & V_4 -> V_121 ) ;
break;
}
}
void F_54 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_109 ;
F_47 ( & V_4 -> V_116 , V_109 ) ;
F_55 (vb, &q->done_list, done_entry)
V_2 -> V_42 = V_112 ;
F_50 ( & V_4 -> V_116 , V_109 ) ;
}
static int F_56 ( struct V_1 * V_2 , const void * V_81 )
{
int V_39 = F_28 ( V_2 -> V_3 , V_122 ,
V_2 , V_81 , V_2 -> V_18 ) ;
return V_39 ? V_39 : F_17 ( V_2 , V_123 , V_2 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_24 V_18 [ V_124 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_39 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_125 = V_2 -> V_18 [ 0 ] . V_10 == NULL ;
memset ( V_18 , 0 , sizeof( V_18 [ 0 ] ) * V_2 -> V_12 ) ;
V_39 = F_28 ( V_2 -> V_3 , V_122 , V_2 , V_81 , V_18 ) ;
if ( V_39 )
return V_39 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_18 [ V_11 ] . V_35 . V_126 &&
V_2 -> V_18 [ V_11 ] . V_35 . V_126 == V_18 [ V_11 ] . V_35 . V_126
&& V_2 -> V_18 [ V_11 ] . V_19 == V_18 [ V_11 ] . V_19 )
continue;
F_7 ( 3 , L_33
L_34 , V_11 ) ;
if ( V_18 [ V_11 ] . V_19 < V_4 -> V_14 [ V_11 ] ) {
F_7 ( 1 , L_35
L_36 ,
V_18 [ V_11 ] . V_19 ,
V_4 -> V_14 [ V_11 ] , V_11 ) ;
V_39 = - V_87 ;
goto V_127;
}
if ( V_2 -> V_18 [ V_11 ] . V_10 ) {
if ( ! V_125 ) {
V_125 = true ;
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_5 ( V_2 , V_23 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
}
V_2 -> V_18 [ V_11 ] . V_10 = NULL ;
V_2 -> V_18 [ V_11 ] . V_128 = 0 ;
V_2 -> V_18 [ V_11 ] . V_19 = 0 ;
V_2 -> V_18 [ V_11 ] . V_35 . V_126 = 0 ;
V_2 -> V_18 [ V_11 ] . V_129 = 0 ;
V_10 = F_3 ( V_2 , V_86 , V_4 -> V_16 [ V_11 ] ,
V_18 [ V_11 ] . V_35 . V_126 ,
V_18 [ V_11 ] . V_19 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
F_7 ( 1 , L_37
L_38 , V_11 ) ;
V_39 = V_10 ? F_58 ( V_10 ) : - V_87 ;
goto V_127;
}
V_2 -> V_18 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_18 [ V_11 ] . V_128 = V_18 [ V_11 ] . V_128 ;
V_2 -> V_18 [ V_11 ] . V_19 = V_18 [ V_11 ] . V_19 ;
V_2 -> V_18 [ V_11 ] . V_35 . V_126 = V_18 [ V_11 ] . V_35 . V_126 ;
V_2 -> V_18 [ V_11 ] . V_129 = V_18 [ V_11 ] . V_129 ;
}
if ( V_125 ) {
V_39 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_39 ) ;
goto V_127;
}
}
V_39 = F_17 ( V_2 , V_123 , V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_40 ) ;
F_20 ( V_2 , V_50 , V_2 ) ;
goto V_127;
}
return 0 ;
V_127:
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_18 [ V_11 ] . V_10 )
F_5 ( V_2 , V_23 ,
V_2 -> V_18 [ V_11 ] . V_10 ) ;
V_2 -> V_18 [ V_11 ] . V_10 = NULL ;
V_2 -> V_18 [ V_11 ] . V_35 . V_126 = 0 ;
V_2 -> V_18 [ V_11 ] . V_19 = 0 ;
}
return V_39 ;
}
static int F_59 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_24 V_18 [ V_124 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_10 ;
unsigned int V_11 ;
int V_39 ;
enum V_5 V_6 =
V_4 -> V_7 ? V_8 : V_9 ;
bool V_125 = V_2 -> V_18 [ 0 ] . V_10 == NULL ;
memset ( V_18 , 0 , sizeof( V_18 [ 0 ] ) * V_2 -> V_12 ) ;
V_39 = F_28 ( V_2 -> V_3 , V_122 , V_2 , V_81 , V_18 ) ;
if ( V_39 )
return V_39 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
struct V_130 * V_29 = F_60 ( V_18 [ V_11 ] . V_35 . V_131 ) ;
if ( F_4 ( V_29 ) ) {
F_7 ( 1 , L_41 ,
V_11 ) ;
V_39 = - V_87 ;
goto V_127;
}
if ( V_18 [ V_11 ] . V_19 == 0 )
V_18 [ V_11 ] . V_19 = V_29 -> V_13 ;
if ( V_18 [ V_11 ] . V_19 < V_4 -> V_14 [ V_11 ] ) {
F_7 ( 1 , L_42 ,
V_11 ) ;
V_39 = - V_87 ;
goto V_127;
}
if ( V_29 == V_2 -> V_18 [ V_11 ] . V_29 &&
V_2 -> V_18 [ V_11 ] . V_19 == V_18 [ V_11 ] . V_19 ) {
F_10 ( V_29 ) ;
continue;
}
F_7 ( 1 , L_43 , V_11 ) ;
if ( ! V_125 ) {
V_125 = true ;
F_20 ( V_2 , V_50 , V_2 ) ;
}
F_9 ( V_2 , & V_2 -> V_18 [ V_11 ] ) ;
V_2 -> V_18 [ V_11 ] . V_128 = 0 ;
V_2 -> V_18 [ V_11 ] . V_19 = 0 ;
V_2 -> V_18 [ V_11 ] . V_35 . V_131 = 0 ;
V_2 -> V_18 [ V_11 ] . V_129 = 0 ;
V_10 = F_3 ( V_2 , V_91 ,
V_4 -> V_16 [ V_11 ] , V_29 , V_18 [ V_11 ] . V_19 ,
V_6 ) ;
if ( F_61 ( V_10 ) ) {
F_7 ( 1 , L_44 ) ;
V_39 = F_58 ( V_10 ) ;
F_10 ( V_29 ) ;
goto V_127;
}
V_2 -> V_18 [ V_11 ] . V_29 = V_29 ;
V_2 -> V_18 [ V_11 ] . V_10 = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_39 = F_25 ( V_2 , V_92 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
if ( V_39 ) {
F_7 ( 1 , L_45 ,
V_11 ) ;
goto V_127;
}
V_2 -> V_18 [ V_11 ] . V_26 = 1 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_18 [ V_11 ] . V_128 = V_18 [ V_11 ] . V_128 ;
V_2 -> V_18 [ V_11 ] . V_19 = V_18 [ V_11 ] . V_19 ;
V_2 -> V_18 [ V_11 ] . V_35 . V_131 = V_18 [ V_11 ] . V_35 . V_131 ;
V_2 -> V_18 [ V_11 ] . V_129 = V_18 [ V_11 ] . V_129 ;
}
if ( V_125 ) {
V_39 = F_17 ( V_2 , V_45 , V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_39 ) ;
goto V_127;
}
}
V_39 = F_17 ( V_2 , V_123 , V_2 ) ;
if ( V_39 ) {
F_7 ( 1 , L_40 ) ;
F_20 ( V_2 , V_50 , V_2 ) ;
goto V_127;
}
return 0 ;
V_127:
F_11 ( V_2 ) ;
return V_39 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_11 ;
V_2 -> V_42 = V_110 ;
F_62 ( & V_4 -> V_119 ) ;
F_63 ( V_4 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
F_5 ( V_2 , V_132 , V_2 -> V_18 [ V_11 ] . V_10 ) ;
F_20 ( V_2 , V_133 , V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_81 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_39 ;
if ( V_4 -> error ) {
F_7 ( 1 , L_46 ) ;
return - V_134 ;
}
V_2 -> V_42 = V_48 ;
switch ( V_4 -> V_38 ) {
case V_44 :
V_39 = F_56 ( V_2 , V_81 ) ;
break;
case V_93 :
V_39 = F_57 ( V_2 , V_81 ) ;
break;
case V_47 :
V_39 = F_59 ( V_2 , V_81 ) ;
break;
default:
F_65 ( 1 , L_47 ) ;
V_39 = - V_87 ;
}
if ( V_39 )
F_7 ( 1 , L_48 , V_39 ) ;
V_2 -> V_42 = V_39 ? V_43 : V_135 ;
return V_39 ;
}
int F_66 ( struct V_3 * V_4 , unsigned int V_22 , void * V_81 )
{
struct V_1 * V_2 ;
int V_39 ;
V_2 = V_4 -> V_33 [ V_22 ] ;
if ( V_2 -> V_42 != V_43 ) {
F_7 ( 1 , L_49 ,
V_2 -> V_42 ) ;
return - V_87 ;
}
V_39 = F_64 ( V_2 , V_81 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
if ( V_39 )
return V_39 ;
F_7 ( 1 , L_50 , V_2 -> V_22 ) ;
return V_39 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_39 ;
F_55 (vb, &q->queued_list, queued_entry)
F_52 ( V_2 ) ;
V_4 -> V_120 = 1 ;
V_39 = F_40 ( V_4 , V_136 , V_4 ,
F_68 ( & V_4 -> V_119 ) ) ;
if ( ! V_39 )
return 0 ;
V_4 -> V_120 = 0 ;
F_7 ( 1 , L_51 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_119 ) ) ) {
unsigned V_137 ;
for ( V_137 = 0 ; V_137 < V_4 -> V_32 ; ++ V_137 ) {
V_2 = V_4 -> V_33 [ V_137 ] ;
if ( V_2 -> V_42 == V_110 )
F_45 ( V_2 , V_113 ) ;
}
F_46 ( F_68 ( & V_4 -> V_119 ) ) ;
}
F_46 ( ! F_69 ( & V_4 -> V_118 ) ) ;
return V_39 ;
}
int F_70 ( struct V_3 * V_4 , unsigned int V_22 , void * V_81 )
{
struct V_1 * V_2 ;
int V_39 ;
V_2 = V_4 -> V_33 [ V_22 ] ;
switch ( V_2 -> V_42 ) {
case V_43 :
V_39 = F_64 ( V_2 , V_81 ) ;
if ( V_39 )
return V_39 ;
break;
case V_135 :
break;
case V_48 :
F_7 ( 1 , L_52 ) ;
return - V_87 ;
default:
F_7 ( 1 , L_49 , V_2 -> V_42 ) ;
return - V_87 ;
}
F_48 ( & V_2 -> V_138 , & V_4 -> V_79 ) ;
V_4 -> V_139 ++ ;
V_4 -> V_101 = false ;
V_2 -> V_42 = V_113 ;
F_28 ( V_4 , V_140 , V_2 , V_81 ) ;
F_71 ( V_4 , V_2 ) ;
if ( V_4 -> V_120 )
F_52 ( V_2 ) ;
V_39 = F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_97 && ! V_4 -> V_120 &&
V_4 -> V_139 >= V_4 -> V_100 ) {
V_39 = F_67 ( V_4 ) ;
if ( V_39 )
return V_39 ;
}
F_7 ( 1 , L_53 , V_2 -> V_22 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int V_141 )
{
for (; ; ) {
int V_39 ;
if ( ! V_4 -> V_97 ) {
F_7 ( 1 , L_54 ) ;
return - V_87 ;
}
if ( V_4 -> error ) {
F_7 ( 1 , L_55 ) ;
return - V_134 ;
}
if ( V_4 -> V_142 ) {
F_7 ( 3 , L_56 ) ;
return - V_143 ;
}
if ( ! F_69 ( & V_4 -> V_118 ) ) {
break;
}
if ( V_141 ) {
F_7 ( 1 , L_57
L_58 ) ;
return - V_49 ;
}
F_73 ( V_4 , V_144 , V_4 ) ;
F_7 ( 3 , L_59 ) ;
V_39 = F_74 ( V_4 -> V_121 ,
! F_69 ( & V_4 -> V_118 ) || ! V_4 -> V_97 ||
V_4 -> error ) ;
F_73 ( V_4 , V_145 , V_4 ) ;
if ( V_39 ) {
F_7 ( 1 , L_60 ) ;
return V_39 ;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
int V_141 )
{
unsigned long V_109 ;
int V_39 ;
V_39 = F_72 ( V_4 , V_141 ) ;
if ( V_39 )
return V_39 ;
F_47 ( & V_4 -> V_116 , V_109 ) ;
* V_2 = F_76 ( & V_4 -> V_118 , struct V_1 , V_117 ) ;
F_77 ( & ( * V_2 ) -> V_117 ) ;
F_50 ( & V_4 -> V_116 , V_109 ) ;
return V_39 ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_97 ) {
F_7 ( 1 , L_54 ) ;
return - V_87 ;
}
if ( V_4 -> V_120 )
F_79 ( V_4 -> V_121 , ! F_68 ( & V_4 -> V_119 ) ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_137 ;
if ( V_2 -> V_42 == V_43 )
return;
V_2 -> V_42 = V_43 ;
if ( V_4 -> V_38 == V_47 )
for ( V_137 = 0 ; V_137 < V_2 -> V_12 ; ++ V_137 ) {
if ( ! V_2 -> V_18 [ V_137 ] . V_26 )
continue;
F_5 ( V_2 , V_27 , V_2 -> V_18 [ V_137 ] . V_10 ) ;
V_2 -> V_18 [ V_137 ] . V_26 = 0 ;
}
}
int F_81 ( struct V_3 * V_4 , void * V_81 , bool V_141 )
{
struct V_1 * V_2 = NULL ;
int V_39 ;
V_39 = F_75 ( V_4 , & V_2 , V_141 ) ;
if ( V_39 < 0 )
return V_39 ;
switch ( V_2 -> V_42 ) {
case V_111 :
F_7 ( 3 , L_61 ) ;
break;
case V_112 :
F_7 ( 3 , L_62 ) ;
break;
default:
F_7 ( 1 , L_63 ) ;
return - V_87 ;
}
F_20 ( V_2 , V_146 , V_2 ) ;
V_39 = F_28 ( V_4 , V_82 , V_2 , V_81 ) ;
if ( V_39 )
return V_39 ;
F_77 ( & V_2 -> V_138 ) ;
V_4 -> V_139 -- ;
F_82 ( V_4 , V_2 ) ;
F_80 ( V_2 ) ;
F_7 ( 1 , L_64 ,
V_2 -> V_22 , V_2 -> V_42 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
unsigned int V_137 ;
if ( V_4 -> V_120 )
F_73 ( V_4 , V_147 , V_4 ) ;
if ( F_46 ( F_68 ( & V_4 -> V_119 ) ) ) {
for ( V_137 = 0 ; V_137 < V_4 -> V_32 ; ++ V_137 )
if ( V_4 -> V_33 [ V_137 ] -> V_42 == V_110 )
F_45 ( V_4 -> V_33 [ V_137 ] , V_112 ) ;
F_46 ( F_68 ( & V_4 -> V_119 ) ) ;
}
V_4 -> V_97 = 0 ;
V_4 -> V_120 = 0 ;
V_4 -> V_139 = 0 ;
V_4 -> error = 0 ;
F_23 ( & V_4 -> V_79 ) ;
F_23 ( & V_4 -> V_118 ) ;
F_83 ( & V_4 -> V_119 , 0 ) ;
F_84 ( & V_4 -> V_121 ) ;
for ( V_137 = 0 ; V_137 < V_4 -> V_32 ; ++ V_137 ) {
struct V_1 * V_2 = V_4 -> V_33 [ V_137 ] ;
if ( V_2 -> V_42 != V_43 ) {
V_2 -> V_42 = V_135 ;
F_20 ( V_2 , V_146 , V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
int F_85 ( struct V_3 * V_4 , unsigned int type )
{
int V_39 ;
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_87 ;
}
if ( V_4 -> V_97 ) {
F_7 ( 3 , L_66 ) ;
return 0 ;
}
if ( ! V_4 -> V_32 ) {
F_7 ( 1 , L_67 ) ;
return - V_87 ;
}
if ( V_4 -> V_32 < V_4 -> V_100 ) {
F_7 ( 1 , L_68 ,
V_4 -> V_100 ) ;
return - V_87 ;
}
if ( V_4 -> V_139 >= V_4 -> V_100 ) {
V_39 = F_67 ( V_4 ) ;
if ( V_39 ) {
F_37 ( V_4 ) ;
return V_39 ;
}
}
V_4 -> V_97 = 1 ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
void F_86 ( struct V_3 * V_4 )
{
V_4 -> error = 1 ;
F_84 ( & V_4 -> V_121 ) ;
}
int F_87 ( struct V_3 * V_4 , unsigned int type )
{
if ( type != V_4 -> type ) {
F_7 ( 1 , L_65 ) ;
return - V_87 ;
}
F_37 ( V_4 ) ;
V_4 -> V_101 = ! V_4 -> V_7 ;
V_4 -> V_142 = false ;
F_7 ( 3 , L_69 ) ;
return 0 ;
}
static int F_88 ( struct V_3 * V_4 , unsigned long V_34 ,
unsigned int * V_148 , unsigned int * V_149 )
{
struct V_1 * V_2 ;
unsigned int V_31 , V_11 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; ++ V_31 ) {
V_2 = V_4 -> V_33 [ V_31 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_18 [ V_11 ] . V_35 . V_36 == V_34 ) {
* V_148 = V_31 ;
* V_149 = V_11 ;
return 0 ;
}
}
}
return - V_87 ;
}
int F_89 ( struct V_3 * V_4 , int * V_131 , unsigned int type ,
unsigned int V_22 , unsigned int V_11 , unsigned int V_109 )
{
struct V_1 * V_2 = NULL ;
struct V_24 * V_150 ;
int V_39 ;
struct V_130 * V_29 ;
if ( V_4 -> V_38 != V_44 ) {
F_7 ( 1 , L_70 ) ;
return - V_87 ;
}
if ( ! V_4 -> V_85 -> V_151 ) {
F_7 ( 1 , L_71 ) ;
return - V_87 ;
}
if ( V_109 & ~ ( V_152 | V_153 ) ) {
F_7 ( 1 , L_72 ) ;
return - V_87 ;
}
if ( type != V_4 -> type ) {
F_7 ( 1 , L_73 ) ;
return - V_87 ;
}
if ( V_22 >= V_4 -> V_32 ) {
F_7 ( 1 , L_74 ) ;
return - V_87 ;
}
V_2 = V_4 -> V_33 [ V_22 ] ;
if ( V_11 >= V_2 -> V_12 ) {
F_7 ( 1 , L_75 ) ;
return - V_87 ;
}
if ( F_33 ( V_4 ) ) {
F_7 ( 1 , L_76 ) ;
return - V_94 ;
}
V_150 = & V_2 -> V_18 [ V_11 ] ;
V_29 = F_3 ( V_2 , V_151 , V_150 -> V_10 ,
V_109 & V_153 ) ;
if ( F_4 ( V_29 ) ) {
F_7 ( 1 , L_77 ,
V_22 , V_11 ) ;
return - V_87 ;
}
V_39 = F_90 ( V_29 , V_109 & ~ V_153 ) ;
if ( V_39 < 0 ) {
F_7 ( 3 , L_78 ,
V_22 , V_11 , V_39 ) ;
F_10 ( V_29 ) ;
return V_39 ;
}
F_7 ( 3 , L_79 ,
V_22 , V_11 , V_39 ) ;
* V_131 = V_39 ;
return 0 ;
}
int F_91 ( struct V_3 * V_4 , struct V_154 * V_155 )
{
unsigned long V_34 = V_155 -> V_156 << V_157 ;
struct V_1 * V_2 ;
unsigned int V_31 = 0 , V_11 = 0 ;
int V_39 ;
unsigned long V_19 ;
if ( V_4 -> V_38 != V_44 ) {
F_7 ( 1 , L_70 ) ;
return - V_87 ;
}
if ( ! ( V_155 -> V_158 & V_159 ) ) {
F_7 ( 1 , L_80 ) ;
return - V_87 ;
}
if ( V_4 -> V_7 ) {
if ( ! ( V_155 -> V_158 & V_160 ) ) {
F_7 ( 1 , L_81 ) ;
return - V_87 ;
}
} else {
if ( ! ( V_155 -> V_158 & V_161 ) ) {
F_7 ( 1 , L_82 ) ;
return - V_87 ;
}
}
if ( F_33 ( V_4 ) ) {
F_7 ( 1 , L_83 ) ;
return - V_94 ;
}
V_39 = F_88 ( V_4 , V_34 , & V_31 , & V_11 ) ;
if ( V_39 )
return V_39 ;
V_2 = V_4 -> V_33 [ V_31 ] ;
V_19 = F_2 ( V_2 -> V_18 [ V_11 ] . V_19 ) ;
if ( V_19 < ( V_155 -> V_162 - V_155 -> V_163 ) ) {
F_7 ( 1 ,
L_84 ) ;
return - V_87 ;
}
F_35 ( & V_4 -> V_98 ) ;
V_39 = F_25 ( V_2 , V_89 , V_2 -> V_18 [ V_11 ] . V_10 , V_155 ) ;
F_36 ( & V_4 -> V_98 ) ;
if ( V_39 )
return V_39 ;
F_7 ( 3 , L_85 , V_31 , V_11 ) ;
return 0 ;
}
unsigned long F_92 ( struct V_3 * V_4 ,
unsigned long V_164 ,
unsigned long V_165 ,
unsigned long V_166 ,
unsigned long V_109 )
{
unsigned long V_34 = V_166 << V_157 ;
struct V_1 * V_2 ;
unsigned int V_31 , V_11 ;
void * V_106 ;
int V_39 ;
if ( V_4 -> V_38 != V_44 ) {
F_7 ( 1 , L_70 ) ;
return - V_87 ;
}
V_39 = F_88 ( V_4 , V_34 , & V_31 , & V_11 ) ;
if ( V_39 )
return V_39 ;
V_2 = V_4 -> V_33 [ V_31 ] ;
V_106 = F_43 ( V_2 , V_11 ) ;
return V_106 ? ( unsigned long ) V_106 : - V_87 ;
}
int F_93 ( struct V_3 * V_4 )
{
if ( F_46 ( ! V_4 ) ||
F_46 ( ! V_4 -> V_167 ) ||
F_46 ( ! V_4 -> V_85 ) ||
F_46 ( ! V_4 -> type ) ||
F_46 ( ! V_4 -> V_83 ) ||
F_46 ( ! V_4 -> V_167 -> V_99 ) ||
F_46 ( ! V_4 -> V_167 -> V_133 ) )
return - V_87 ;
F_23 ( & V_4 -> V_79 ) ;
F_23 ( & V_4 -> V_118 ) ;
F_94 ( & V_4 -> V_116 ) ;
F_95 ( & V_4 -> V_98 ) ;
F_96 ( & V_4 -> V_121 ) ;
if ( V_4 -> V_40 == 0 )
V_4 -> V_40 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_97 ( struct V_3 * V_4 )
{
F_37 ( V_4 ) ;
F_35 ( & V_4 -> V_98 ) ;
F_19 ( V_4 , V_4 -> V_32 ) ;
F_36 ( & V_4 -> V_98 ) ;
}
