static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
unsigned long V_8 = F_2 ( V_4 -> V_9 [ V_6 ] ) ;
V_5 = F_3 ( V_4 , V_10 , V_4 -> V_11 [ V_6 ] ,
V_8 , V_4 -> V_12 ) ;
if ( F_4 ( V_5 ) )
goto free;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
V_2 -> V_14 [ V_6 ] . V_15 = V_4 -> V_9 [ V_6 ] ;
}
return 0 ;
free:
for (; V_6 > 0 ; -- V_6 ) {
F_3 ( V_4 , V_16 , V_2 -> V_13 [ V_6 - 1 ] . V_5 ) ;
V_2 -> V_13 [ V_6 - 1 ] . V_5 = NULL ;
}
return - V_17 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
F_3 ( V_4 , V_16 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
F_6 ( 3 , L_1 , V_6 ,
V_2 -> V_18 . V_19 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_4 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
}
}
static void F_8 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
if ( ! V_22 -> V_5 )
return;
if ( V_22 -> V_23 )
F_3 ( V_4 , V_24 , V_22 -> V_5 ) ;
F_3 ( V_4 , V_25 , V_22 -> V_5 ) ;
F_9 ( V_22 -> V_26 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_8 ( V_4 , & V_2 -> V_13 [ V_6 ] ) ;
}
static void F_11 ( struct V_3 * V_4 , unsigned int V_27 )
{
unsigned int V_28 , V_6 ;
struct V_1 * V_2 ;
unsigned long V_29 ;
if ( V_4 -> V_30 ) {
struct V_31 * V_22 ;
V_2 = V_4 -> V_32 [ V_4 -> V_30 - 1 ] ;
V_22 = & V_2 -> V_14 [ V_2 -> V_7 - 1 ] ;
V_29 = F_2 ( V_22 -> V_33 . V_34 + V_22 -> V_15 ) ;
} else {
V_29 = 0 ;
}
for ( V_28 = V_4 -> V_30 ; V_28 < V_4 -> V_30 + V_27 ; ++ V_28 ) {
V_2 = V_4 -> V_32 [ V_28 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_2 -> V_14 [ V_6 ] . V_15 = V_4 -> V_9 [ V_6 ] ;
V_2 -> V_14 [ V_6 ] . V_33 . V_34 = V_29 ;
F_6 ( 3 , L_2 ,
V_28 , V_6 , V_29 ) ;
V_29 += V_2 -> V_14 [ V_6 ] . V_15 ;
V_29 = F_2 ( V_29 ) ;
}
}
}
static int F_12 ( struct V_3 * V_4 , enum V_35 V_36 ,
unsigned int V_30 , unsigned int V_7 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
int V_37 ;
for ( V_28 = 0 ; V_28 < V_30 ; ++ V_28 ) {
V_2 = F_13 ( V_4 -> V_38 , V_39 ) ;
if ( ! V_2 ) {
F_6 ( 1 , L_3 ) ;
break;
}
if ( F_14 ( V_4 -> type ) )
V_2 -> V_18 . V_15 = V_7 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_18 . V_19 = V_4 -> V_30 + V_28 ;
V_2 -> V_18 . type = V_4 -> type ;
V_2 -> V_18 . V_36 = V_36 ;
if ( V_36 == V_42 ) {
V_37 = F_1 ( V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_4
L_5 , V_28 ) ;
F_15 ( V_2 ) ;
break;
}
V_37 = F_16 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_6
L_7 , V_28 , V_2 ) ;
F_5 ( V_2 ) ;
F_15 ( V_2 ) ;
break;
}
}
V_4 -> V_32 [ V_4 -> V_30 + V_28 ] = V_2 ;
}
F_11 ( V_4 , V_28 ) ;
F_6 ( 1 , L_8 ,
V_28 , V_7 ) ;
return V_28 ;
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
for ( V_28 = V_4 -> V_30 - V_44 ; V_28 < V_4 -> V_30 ;
++ V_28 ) {
V_2 = V_4 -> V_32 [ V_28 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_36 == V_42 )
F_5 ( V_2 ) ;
else if ( V_4 -> V_36 == V_45 )
F_10 ( V_2 ) ;
else
F_7 ( V_2 ) ;
}
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
if ( V_4 -> V_46 -> V_47 ) {
for ( V_28 = V_4 -> V_30 - V_44 ; V_28 < V_4 -> V_30 ;
++ V_28 ) {
if ( NULL == V_4 -> V_32 [ V_28 ] )
continue;
V_4 -> V_46 -> V_47 ( V_4 -> V_32 [ V_28 ] ) ;
}
}
F_17 ( V_4 , V_44 ) ;
for ( V_28 = V_4 -> V_30 - V_44 ; V_28 < V_4 -> V_30 ;
++ V_28 ) {
F_15 ( V_4 -> V_32 [ V_28 ] ) ;
V_4 -> V_32 [ V_28 ] = NULL ;
}
V_4 -> V_30 -= V_44 ;
if ( ! V_4 -> V_30 )
V_4 -> V_36 = 0 ;
F_19 ( & V_4 -> V_48 ) ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
if ( ! F_14 ( V_50 -> type ) )
return 0 ;
if ( NULL == V_50 -> V_33 . V_13 ) {
F_6 ( 1 , L_9
L_10 ) ;
return - V_51 ;
}
if ( V_50 -> V_15 < V_2 -> V_7 || V_50 -> V_15 > V_52 ) {
F_6 ( 1 , L_11
L_12 , V_2 -> V_7 , V_50 -> V_15 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
unsigned int V_15 ;
unsigned int V_6 ;
if ( ! F_22 ( V_50 -> type ) )
return 0 ;
if ( F_14 ( V_50 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_15 = ( V_50 -> V_36 == V_53 )
? V_50 -> V_33 . V_13 [ V_6 ] . V_15
: V_2 -> V_14 [ V_6 ] . V_15 ;
if ( V_50 -> V_33 . V_13 [ V_6 ] . V_54 > V_15 )
return - V_51 ;
if ( V_50 -> V_33 . V_13 [ V_6 ] . V_55 > 0 &&
V_50 -> V_33 . V_13 [ V_6 ] . V_55 >=
V_50 -> V_33 . V_13 [ V_6 ] . V_54 )
return - V_51 ;
}
} else {
V_15 = ( V_50 -> V_36 == V_53 )
? V_50 -> V_15 : V_2 -> V_14 [ 0 ] . V_15 ;
if ( V_50 -> V_54 > V_15 )
return - V_51 ;
}
return 0 ;
}
static bool F_23 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_13 [ V_6 ] . V_5 ;
if ( V_5 && F_3 ( V_4 , V_56 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_24 ( struct V_3 * V_4 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_30 ; ++ V_28 ) {
if ( F_23 ( V_4 , V_4 -> V_32 [ V_28 ] ) )
return true ;
}
return false ;
}
static void F_25 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_50 , & V_2 -> V_18 , F_26 ( struct V_49 , V_33 ) ) ;
V_50 -> V_57 = V_2 -> V_18 . V_57 ;
V_50 -> V_58 = V_2 -> V_18 . V_58 ;
if ( F_14 ( V_4 -> type ) ) {
V_50 -> V_15 = V_2 -> V_7 ;
memcpy ( V_50 -> V_33 . V_13 , V_2 -> V_14 ,
V_50 -> V_15 * sizeof( struct V_31 ) ) ;
} else {
V_50 -> V_15 = V_2 -> V_14 [ 0 ] . V_15 ;
V_50 -> V_54 = V_2 -> V_14 [ 0 ] . V_54 ;
if ( V_4 -> V_36 == V_42 )
V_50 -> V_33 . V_59 = V_2 -> V_14 [ 0 ] . V_33 . V_34 ;
else if ( V_4 -> V_36 == V_53 )
V_50 -> V_33 . V_60 = V_2 -> V_14 [ 0 ] . V_33 . V_60 ;
else if ( V_4 -> V_36 == V_45 )
V_50 -> V_33 . V_61 = V_2 -> V_14 [ 0 ] . V_33 . V_61 ;
}
V_50 -> V_62 &= ~ V_63 ;
V_50 -> V_62 |= V_4 -> V_64 ;
switch ( V_2 -> V_40 ) {
case V_65 :
case V_66 :
V_50 -> V_62 |= V_67 ;
break;
case V_68 :
V_50 -> V_62 |= V_69 ;
case V_70 :
V_50 -> V_62 |= V_71 ;
break;
case V_72 :
V_50 -> V_62 |= V_73 ;
break;
case V_41 :
break;
}
if ( F_23 ( V_4 , V_2 ) )
V_50 -> V_62 |= V_74 ;
}
int F_27 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_13 ) ;
return - V_51 ;
}
if ( V_50 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_14 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_32 [ V_50 -> V_19 ] ;
V_37 = F_20 ( V_2 , V_50 ) ;
if ( ! V_37 )
F_25 ( V_2 , V_50 ) ;
return V_37 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_76 ) || ! V_4 -> V_77 -> V_78 ||
! V_4 -> V_77 -> V_20 )
return - V_51 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_79 ) || ! V_4 -> V_77 -> V_10 ||
! V_4 -> V_77 -> V_16 || ! V_4 -> V_77 -> V_80 )
return - V_51 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_81 ) || ! V_4 -> V_77 -> V_82 ||
! V_4 -> V_77 -> V_25 || ! V_4 -> V_77 -> V_83 ||
! V_4 -> V_77 -> V_24 )
return - V_51 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
enum V_35 V_36 , enum V_84 type )
{
if ( V_36 != V_42 && V_36 != V_53 &&
V_36 != V_45 ) {
F_6 ( 1 , L_15 ) ;
return - V_51 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_16 ) ;
return - V_51 ;
}
if ( V_36 == V_42 && F_29 ( V_4 ) ) {
F_6 ( 1 , L_17 ) ;
return - V_51 ;
}
if ( V_36 == V_53 && F_28 ( V_4 ) ) {
F_6 ( 1 , L_18 ) ;
return - V_51 ;
}
if ( V_36 == V_45 && F_30 ( V_4 ) ) {
F_6 ( 1 , L_19 ) ;
return - V_51 ;
}
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_20 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_87 * V_88 )
{
unsigned int V_30 , V_89 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_90 ) {
F_6 ( 1 , L_21 ) ;
return - V_86 ;
}
if ( V_88 -> V_91 == 0 || V_4 -> V_30 != 0 || V_4 -> V_36 != V_88 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_24 ( V_4 ) ) {
F_6 ( 1 , L_22 ) ;
return - V_86 ;
}
F_18 ( V_4 , V_4 -> V_30 ) ;
if ( V_88 -> V_91 == 0 )
return 0 ;
}
V_30 = F_33 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_88 -> V_36 ;
V_37 = F_16 ( V_4 , V_92 , V_4 , NULL , & V_30 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_12 ( V_4 , V_88 -> V_36 , V_30 , V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_89 = V_37 ;
if ( V_89 < V_30 ) {
V_30 = V_89 ;
V_37 = F_16 ( V_4 , V_92 , V_4 , NULL , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_89 < V_30 )
V_37 = - V_17 ;
}
V_4 -> V_30 = V_89 ;
if ( V_37 < 0 ) {
F_18 ( V_4 , V_89 ) ;
return V_37 ;
}
V_88 -> V_91 = V_89 ;
return 0 ;
}
int F_34 ( struct V_3 * V_4 , struct V_87 * V_88 )
{
int V_37 = F_31 ( V_4 , V_88 -> V_36 , V_88 -> type ) ;
return V_37 ? V_37 : F_32 ( V_4 , V_88 ) ;
}
static int F_35 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
unsigned int V_7 = 0 , V_30 , V_89 ;
int V_37 ;
if ( V_4 -> V_30 == V_95 ) {
F_6 ( 1 , L_24 ,
V_96 ) ;
return - V_97 ;
}
if ( ! V_4 -> V_30 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_94 -> V_36 ;
}
V_30 = F_36 ( V_94 -> V_91 , V_95 - V_4 -> V_30 ) ;
V_37 = F_16 ( V_4 , V_92 , V_4 , & V_94 -> V_98 , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_12 ( V_4 , V_94 -> V_36 , V_30 ,
V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_89 = V_37 ;
if ( V_37 < V_30 ) {
V_30 = V_37 ;
V_37 = F_16 ( V_4 , V_92 , V_4 , & V_94 -> V_98 , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_89 < V_30 )
V_37 = - V_17 ;
}
V_4 -> V_30 += V_89 ;
if ( V_37 < 0 ) {
F_18 ( V_4 , V_89 ) ;
return - V_17 ;
}
V_94 -> V_91 = V_89 ;
return 0 ;
}
int F_37 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
int V_37 = F_31 ( V_4 , V_94 -> V_36 , V_94 -> V_98 . type ) ;
V_94 -> V_19 = V_4 -> V_30 ;
if ( V_94 -> V_91 == 0 )
return V_37 != - V_86 ? V_37 : 0 ;
return V_37 ? V_37 : F_35 ( V_4 , V_94 ) ;
}
void * F_38 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_99 > V_2 -> V_7 || ! V_2 -> V_13 [ V_99 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_100 , V_2 -> V_13 [ V_99 ] . V_5 ) ;
}
void * F_39 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_99 > V_2 -> V_7 || ! V_2 -> V_13 [ V_99 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_101 , V_2 -> V_13 [ V_99 ] . V_5 ) ;
}
void F_40 ( struct V_1 * V_2 , enum V_102 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_62 ;
unsigned int V_6 ;
if ( V_2 -> V_40 != V_66 )
return;
if ( V_40 != V_70 && V_40 != V_68 )
return;
F_6 ( 4 , L_25 ,
V_2 -> V_18 . V_19 , V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_103 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_41 ( & V_4 -> V_104 , V_62 ) ;
V_2 -> V_40 = V_40 ;
F_42 ( & V_2 -> V_105 , & V_4 -> V_106 ) ;
F_43 ( & V_4 -> V_107 ) ;
F_44 ( & V_4 -> V_104 , V_62 ) ;
F_45 ( & V_4 -> V_108 ) ;
}
static void F_46 ( struct V_1 * V_2 , const struct V_49 * V_50 ,
struct V_31 * V_14 )
{
unsigned int V_6 ;
if ( F_14 ( V_50 -> type ) ) {
if ( F_22 ( V_50 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_54 =
V_50 -> V_33 . V_13 [ V_6 ] . V_54 ;
V_14 [ V_6 ] . V_55 =
V_50 -> V_33 . V_13 [ V_6 ] . V_55 ;
}
}
if ( V_50 -> V_36 == V_53 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_60 =
V_50 -> V_33 . V_13 [ V_6 ] . V_33 . V_60 ;
V_14 [ V_6 ] . V_15 =
V_50 -> V_33 . V_13 [ V_6 ] . V_15 ;
}
}
if ( V_50 -> V_36 == V_45 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_61 =
V_50 -> V_33 . V_13 [ V_6 ] . V_33 . V_61 ;
V_14 [ V_6 ] . V_15 =
V_50 -> V_33 . V_13 [ V_6 ] . V_15 ;
V_14 [ V_6 ] . V_55 =
V_50 -> V_33 . V_13 [ V_6 ] . V_55 ;
}
}
} else {
if ( F_22 ( V_50 -> type ) ) {
V_14 [ 0 ] . V_54 = V_50 -> V_54 ;
V_14 [ 0 ] . V_55 = 0 ;
}
if ( V_50 -> V_36 == V_53 ) {
V_14 [ 0 ] . V_33 . V_60 = V_50 -> V_33 . V_60 ;
V_14 [ 0 ] . V_15 = V_50 -> V_15 ;
}
if ( V_50 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_61 = V_50 -> V_33 . V_61 ;
V_14 [ 0 ] . V_15 = V_50 -> V_15 ;
V_14 [ 0 ] . V_55 = 0 ;
}
}
V_2 -> V_18 . V_109 = V_50 -> V_109 ;
V_2 -> V_18 . V_110 = V_50 -> V_110 ;
V_2 -> V_18 . V_62 = V_50 -> V_62 & ~ V_63 ;
}
static int F_47 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_31 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_22 ( V_4 -> type ) ;
F_46 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_60 &&
V_2 -> V_14 [ V_6 ] . V_33 . V_60 == V_13 [ V_6 ] . V_33 . V_60
&& V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 )
continue;
F_6 ( 3 , L_26
L_27 , V_6 ) ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
V_37 = - V_51 ;
goto V_112;
}
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_4 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_60 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
V_5 = F_3 ( V_4 , V_78 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_60 ,
V_13 [ V_6 ] . V_15 , V_111 ) ;
if ( F_4 ( V_5 ) ) {
F_6 ( 1 , L_28
L_29 , V_6 ) ;
V_37 = V_5 ? F_48 ( V_5 ) : - V_51 ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
V_37 = F_16 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_30 ) ;
goto V_112;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
return 0 ;
V_112:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_4 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_60 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
}
return V_37 ;
}
static int F_49 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
F_46 ( V_2 , V_50 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_31 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_22 ( V_4 -> type ) ;
F_46 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_113 * V_26 = F_51 ( V_13 [ V_6 ] . V_33 . V_61 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_31 ,
V_6 ) ;
V_37 = - V_51 ;
goto V_112;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_13 [ V_6 ] . V_55 +
V_4 -> V_9 [ V_6 ] ) {
V_37 = - V_51 ;
goto V_112;
}
if ( V_26 == V_2 -> V_13 [ V_6 ] . V_26 &&
V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 ) {
F_9 ( V_26 ) ;
continue;
}
F_6 ( 1 , L_32 , V_6 ) ;
F_8 ( V_4 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_31 ) ) ;
V_5 = F_3 ( V_4 , V_82 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_111 ) ;
if ( F_52 ( V_5 ) ) {
F_6 ( 1 , L_33 ) ;
V_37 = F_48 ( V_5 ) ;
F_9 ( V_26 ) ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_3 ( V_4 , V_83 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_6 ( 1 , L_34 ,
V_6 ) ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
V_37 = F_16 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_30 ) ;
goto V_112;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
return 0 ;
V_112:
F_10 ( V_2 ) ;
return V_37 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_66 ;
F_54 ( & V_4 -> V_107 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_114 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_4 -> V_46 -> V_115 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_37 ;
V_37 = F_21 ( V_2 , V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_49 ( V_2 , V_50 ) ;
break;
case V_53 :
V_37 = F_47 ( V_2 , V_50 ) ;
break;
case V_45 :
V_37 = F_50 ( V_2 , V_50 ) ;
break;
default:
F_56 ( 1 , L_35 ) ;
V_37 = - V_51 ;
}
if ( ! V_37 )
V_37 = F_16 ( V_4 , V_116 , V_2 ) ;
if ( V_37 )
F_6 ( 1 , L_36 , V_37 ) ;
else
V_2 -> V_40 = V_72 ;
return V_37 ;
}
static int F_57 ( struct V_3 * V_4 , struct V_49 * V_50 ,
const char * V_117 ,
int (* F_58)( struct V_3 * ,
struct V_49 * ,
struct V_1 * ) )
{
struct V_118 * V_119 = NULL ;
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_36 == V_53 ) {
V_119 = & V_120 -> V_121 -> V_119 ;
F_16 ( V_4 , V_122 , V_4 ) ;
F_59 ( V_119 ) ;
F_16 ( V_4 , V_123 , V_4 ) ;
}
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_37 , V_117 ) ;
V_37 = - V_86 ;
goto V_124;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_38 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
if ( V_50 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_39 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
V_2 = V_4 -> V_32 [ V_50 -> V_19 ] ;
if ( NULL == V_2 ) {
F_6 ( 1 , L_40 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
if ( V_50 -> V_36 != V_4 -> V_36 ) {
F_6 ( 1 , L_41 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
V_37 = F_20 ( V_2 , V_50 ) ;
if ( V_37 )
goto V_124;
V_37 = F_58 ( V_4 , V_50 , V_2 ) ;
if ( V_37 )
goto V_124;
F_25 ( V_2 , V_50 ) ;
F_6 ( 1 , L_42 , V_117 , V_2 -> V_18 . V_19 ) ;
V_124:
if ( V_119 )
F_60 ( V_119 ) ;
return V_37 ;
}
static int F_61 ( struct V_3 * V_4 , struct V_49 * V_50 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_40 != V_41 ) {
F_6 ( 1 , L_43 , V_96 ,
V_2 -> V_40 ) ;
return - V_51 ;
}
return F_55 ( V_2 , V_50 ) ;
}
int F_62 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
return F_57 ( V_4 , V_50 , L_44 , F_61 ) ;
}
static int F_63 ( struct V_3 * V_4 , struct V_49 * V_50 ,
struct V_1 * V_2 )
{
int V_37 ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_55 ( V_2 , V_50 ) ;
if ( V_37 )
return V_37 ;
case V_72 :
break;
default:
F_6 ( 1 , L_45 ) ;
return - V_51 ;
}
F_42 ( & V_2 -> V_125 , & V_4 -> V_48 ) ;
V_2 -> V_40 = V_65 ;
if ( V_4 -> V_90 )
F_53 ( V_2 ) ;
return 0 ;
}
int F_64 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
return F_57 ( V_4 , V_50 , L_46 , F_63 ) ;
}
static int F_65 ( struct V_3 * V_4 , int V_126 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_47 ) ;
return - V_51 ;
}
if ( ! F_66 ( & V_4 -> V_106 ) ) {
break;
}
if ( V_126 ) {
F_6 ( 1 , L_48
L_49 ) ;
return - V_127 ;
}
F_16 ( V_4 , V_122 , V_4 ) ;
F_6 ( 3 , L_50 ) ;
V_37 = F_67 ( V_4 -> V_108 ,
! F_66 ( & V_4 -> V_106 ) || ! V_4 -> V_90 ) ;
F_16 ( V_4 , V_123 , V_4 ) ;
if ( V_37 ) {
F_6 ( 1 , L_51 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_68 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_49 * V_50 , int V_126 )
{
unsigned long V_62 ;
int V_37 ;
V_37 = F_65 ( V_4 , V_126 ) ;
if ( V_37 )
return V_37 ;
F_41 ( & V_4 -> V_104 , V_62 ) ;
* V_2 = F_69 ( & V_4 -> V_106 , struct V_1 , V_105 ) ;
V_37 = F_20 ( * V_2 , V_50 ) ;
if ( ! V_37 )
F_70 ( & ( * V_2 ) -> V_105 ) ;
F_44 ( & V_4 -> V_104 , V_62 ) ;
return V_37 ;
}
int F_71 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_47 ) ;
return - V_51 ;
}
F_72 ( V_4 -> V_108 , ! F_73 ( & V_4 -> V_107 ) ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_128 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_128 = 0 ; V_128 < V_2 -> V_7 ; ++ V_128 ) {
if ( ! V_2 -> V_13 [ V_128 ] . V_23 )
continue;
F_3 ( V_4 , V_24 , V_2 -> V_13 [ V_128 ] . V_5 ) ;
V_2 -> V_13 [ V_128 ] . V_23 = 0 ;
}
}
int F_75 ( struct V_3 * V_4 , struct V_49 * V_50 , bool V_126 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_52 ) ;
return - V_86 ;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_53 ) ;
return - V_51 ;
}
V_37 = F_68 ( V_4 , & V_2 , V_50 , V_126 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_16 ( V_4 , V_129 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_54 ) ;
return V_37 ;
}
switch ( V_2 -> V_40 ) {
case V_70 :
F_6 ( 3 , L_55 ) ;
break;
case V_68 :
F_6 ( 3 , L_56 ) ;
break;
default:
F_6 ( 1 , L_57 ) ;
return - V_51 ;
}
F_25 ( V_2 , V_50 ) ;
F_70 ( & V_2 -> V_125 ) ;
F_74 ( V_2 ) ;
F_6 ( 1 , L_58 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
static void F_76 ( struct V_3 * V_4 )
{
unsigned int V_128 ;
if ( V_4 -> V_90 )
F_16 ( V_4 , V_130 , V_4 ) ;
V_4 -> V_90 = 0 ;
F_19 ( & V_4 -> V_48 ) ;
F_19 ( & V_4 -> V_106 ) ;
F_77 ( & V_4 -> V_107 , 0 ) ;
F_78 ( & V_4 -> V_108 ) ;
for ( V_128 = 0 ; V_128 < V_4 -> V_30 ; ++ V_128 )
F_74 ( V_4 -> V_32 [ V_128 ] ) ;
}
int F_79 ( struct V_3 * V_4 , enum V_84 type )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_59 ) ;
return - V_86 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_60 ) ;
return - V_51 ;
}
if ( V_4 -> V_90 ) {
F_6 ( 1 , L_61 ) ;
return - V_86 ;
}
F_80 (vb, &q->queued_list, queued_entry)
F_53 ( V_2 ) ;
V_37 = F_16 ( V_4 , V_131 , V_4 , F_73 ( & V_4 -> V_107 ) ) ;
if ( V_37 ) {
F_6 ( 1 , L_62 ) ;
F_76 ( V_4 ) ;
return V_37 ;
}
V_4 -> V_90 = 1 ;
F_6 ( 3 , L_63 ) ;
return 0 ;
}
int F_81 ( struct V_3 * V_4 , enum V_84 type )
{
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_64 ) ;
return - V_86 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_65 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_66 ) ;
return - V_51 ;
}
F_76 ( V_4 ) ;
F_6 ( 3 , L_67 ) ;
return 0 ;
}
static int F_82 ( struct V_3 * V_4 , unsigned long V_29 ,
unsigned int * V_132 , unsigned int * V_133 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_30 ; ++ V_28 ) {
V_2 = V_4 -> V_32 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_29 ) {
* V_132 = V_28 ;
* V_133 = V_6 ;
return 0 ;
}
}
}
return - V_51 ;
}
int F_83 ( struct V_3 * V_4 , struct V_134 * V_135 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_136 ;
int V_37 ;
struct V_113 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_68 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_77 -> V_137 ) {
F_6 ( 1 , L_69 ) ;
return - V_51 ;
}
if ( V_135 -> V_62 & ~ V_138 ) {
F_6 ( 1 , L_70 ) ;
return - V_51 ;
}
if ( V_135 -> type != V_4 -> type ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
if ( V_135 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_72 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_32 [ V_135 -> V_19 ] ;
if ( V_135 -> V_6 >= V_2 -> V_7 ) {
F_6 ( 1 , L_73 ) ;
return - V_51 ;
}
V_136 = & V_2 -> V_13 [ V_135 -> V_6 ] ;
V_26 = F_3 ( V_4 , V_137 , V_136 -> V_5 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_74 ,
V_135 -> V_19 , V_135 -> V_6 ) ;
return - V_51 ;
}
V_37 = F_84 ( V_26 , V_135 -> V_62 ) ;
if ( V_37 < 0 ) {
F_6 ( 3 , L_75 ,
V_135 -> V_19 , V_135 -> V_6 , V_37 ) ;
F_9 ( V_26 ) ;
return V_37 ;
}
F_6 ( 3 , L_76 ,
V_135 -> V_19 , V_135 -> V_6 , V_37 ) ;
V_135 -> V_61 = V_37 ;
return 0 ;
}
int F_85 ( struct V_3 * V_4 , struct V_139 * V_140 )
{
unsigned long V_29 = V_140 -> V_141 << V_142 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_68 ) ;
return - V_51 ;
}
if ( ! ( V_140 -> V_143 & V_144 ) ) {
F_6 ( 1 , L_77 ) ;
return - V_51 ;
}
if ( F_22 ( V_4 -> type ) ) {
if ( ! ( V_140 -> V_143 & V_145 ) ) {
F_6 ( 1 , L_78 ) ;
return - V_51 ;
}
} else {
if ( ! ( V_140 -> V_143 & V_146 ) ) {
F_6 ( 1 , L_79 ) ;
return - V_51 ;
}
}
V_37 = F_82 ( V_4 , V_29 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_32 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_140 -> V_147 - V_140 -> V_148 ) ) {
F_6 ( 1 ,
L_80 ) ;
return - V_51 ;
}
V_37 = F_3 ( V_4 , V_80 , V_2 -> V_13 [ V_6 ] . V_5 , V_140 ) ;
if ( V_37 )
return V_37 ;
F_6 ( 3 , L_81 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_86 ( struct V_3 * V_4 ,
unsigned long V_149 ,
unsigned long V_150 ,
unsigned long V_151 ,
unsigned long V_62 )
{
unsigned long V_29 = V_151 << V_142 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_68 ) ;
return - V_51 ;
}
V_37 = F_82 ( V_4 , V_29 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_32 [ V_28 ] ;
return ( unsigned long ) F_38 ( V_2 , V_6 ) ;
}
unsigned int F_87 ( struct V_3 * V_4 , struct V_152 * V_152 , T_1 * V_153 )
{
struct V_154 * V_155 = F_88 ( V_152 ) ;
unsigned long V_156 = F_89 ( V_153 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_157 = 0 ;
unsigned long V_62 ;
if ( F_90 ( V_158 , & V_155 -> V_62 ) ) {
struct V_159 * V_160 = V_152 -> V_161 ;
if ( F_91 ( V_160 ) )
V_157 = V_162 ;
else if ( V_156 & V_162 )
F_92 ( V_152 , & V_160 -> V_153 , V_153 ) ;
}
if ( ! F_22 ( V_4 -> type ) && ! ( V_156 & ( V_163 | V_164 ) ) )
return V_157 ;
if ( F_22 ( V_4 -> type ) && ! ( V_156 & ( V_165 | V_166 ) ) )
return V_157 ;
if ( V_4 -> V_30 == 0 && V_4 -> V_85 == NULL ) {
if ( ! F_22 ( V_4 -> type ) && ( V_4 -> V_75 & V_167 ) &&
( V_156 & ( V_163 | V_164 ) ) ) {
if ( F_93 ( V_4 , 1 ) )
return V_157 | V_168 ;
}
if ( F_22 ( V_4 -> type ) && ( V_4 -> V_75 & V_169 ) &&
( V_156 & ( V_165 | V_166 ) ) ) {
if ( F_93 ( V_4 , 0 ) )
return V_157 | V_168 ;
return V_157 | V_165 | V_166 ;
}
}
if ( F_66 ( & V_4 -> V_48 ) )
return V_157 | V_168 ;
if ( F_66 ( & V_4 -> V_106 ) )
F_92 ( V_152 , & V_4 -> V_108 , V_153 ) ;
F_41 ( & V_4 -> V_104 , V_62 ) ;
if ( ! F_66 ( & V_4 -> V_106 ) )
V_2 = F_69 ( & V_4 -> V_106 , struct V_1 ,
V_105 ) ;
F_44 ( & V_4 -> V_104 , V_62 ) ;
if ( V_2 && ( V_2 -> V_40 == V_70
|| V_2 -> V_40 == V_68 ) ) {
return ( F_22 ( V_4 -> type ) ) ?
V_157 | V_165 | V_166 :
V_157 | V_163 | V_164 ;
}
return V_157 ;
}
int F_94 ( struct V_3 * V_4 )
{
if ( F_95 ( ! V_4 ) ||
F_95 ( ! V_4 -> V_46 ) ||
F_95 ( ! V_4 -> V_77 ) ||
F_95 ( ! V_4 -> type ) ||
F_95 ( ! V_4 -> V_75 ) ||
F_95 ( ! V_4 -> V_46 -> V_92 ) ||
F_95 ( ! V_4 -> V_46 -> V_115 ) ||
F_95 ( V_4 -> V_64 & ~ V_170 ) )
return - V_51 ;
F_95 ( V_4 -> V_64 == V_171 ) ;
F_19 ( & V_4 -> V_48 ) ;
F_19 ( & V_4 -> V_106 ) ;
F_96 ( & V_4 -> V_104 ) ;
F_97 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_98 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
F_76 ( V_4 ) ;
F_18 ( V_4 , V_4 -> V_30 ) ;
}
static int F_93 ( struct V_3 * V_4 , int V_172 )
{
struct V_173 * V_85 ;
int V_128 , V_37 ;
unsigned int V_91 = 0 ;
if ( ( V_172 && ! ( V_4 -> V_75 & V_167 ) ) ||
( ! V_172 && ! ( V_4 -> V_75 & V_169 ) ) )
F_100 () ;
if ( ! V_4 -> V_77 -> V_100 )
return - V_86 ;
if ( V_4 -> V_90 || V_4 -> V_30 > 0 )
return - V_86 ;
V_91 = 1 ;
F_6 ( 3 , L_82 ,
( V_172 ) ? L_83 : L_84 , V_91 , V_4 -> V_174 ) ;
V_85 = F_13 ( sizeof( struct V_173 ) , V_39 ) ;
if ( V_85 == NULL )
return - V_17 ;
V_85 -> V_62 = V_4 -> V_174 ;
V_85 -> V_88 . V_91 = V_91 ;
V_85 -> V_88 . V_36 = V_42 ;
V_85 -> V_88 . type = V_4 -> type ;
V_37 = F_34 ( V_4 , & V_85 -> V_88 ) ;
if ( V_37 )
goto V_175;
if ( V_4 -> V_32 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_86 ;
goto V_176;
}
for ( V_128 = 0 ; V_128 < V_4 -> V_30 ; V_128 ++ ) {
V_85 -> V_32 [ V_128 ] . V_100 = F_38 ( V_4 -> V_32 [ V_128 ] , 0 ) ;
if ( V_85 -> V_32 [ V_128 ] . V_100 == NULL ) {
V_37 = - V_51 ;
goto V_176;
}
V_85 -> V_32 [ V_128 ] . V_8 = F_101 ( V_4 -> V_32 [ V_128 ] , 0 ) ;
}
if ( V_172 ) {
for ( V_128 = 0 ; V_128 < V_4 -> V_30 ; V_128 ++ ) {
struct V_49 * V_50 = & V_85 -> V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> type = V_4 -> type ;
V_50 -> V_36 = V_4 -> V_36 ;
V_50 -> V_19 = V_128 ;
V_37 = F_64 ( V_4 , V_50 ) ;
if ( V_37 )
goto V_176;
V_85 -> V_32 [ V_128 ] . V_177 = 1 ;
}
V_37 = F_79 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_176;
}
V_4 -> V_85 = V_85 ;
return V_37 ;
V_176:
V_85 -> V_88 . V_91 = 0 ;
F_34 ( V_4 , & V_85 -> V_88 ) ;
V_175:
F_15 ( V_85 ) ;
return V_37 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_173 * V_85 = V_4 -> V_85 ;
if ( V_85 ) {
V_4 -> V_85 = NULL ;
F_81 ( V_4 , V_4 -> type ) ;
V_85 -> V_88 . V_91 = 0 ;
F_34 ( V_4 , & V_85 -> V_88 ) ;
F_15 ( V_85 ) ;
F_6 ( 3 , L_85 ) ;
}
return 0 ;
}
static T_2 F_102 ( struct V_3 * V_4 , char T_3 * V_178 , T_2 V_91 ,
T_4 * V_179 , int V_180 , int V_172 )
{
struct V_173 * V_85 ;
struct V_181 * V_182 ;
int V_37 , V_19 ;
F_6 ( 3 , L_86 ,
V_172 ? L_83 : L_84 , ( long ) * V_179 , V_91 ,
V_180 ? L_87 : L_88 ) ;
if ( ! V_178 )
return - V_51 ;
if ( ! V_4 -> V_85 ) {
V_37 = F_93 ( V_4 , V_172 ) ;
F_6 ( 3 , L_89 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_85 = V_4 -> V_85 ;
V_4 -> V_85 = NULL ;
V_19 = V_85 -> V_19 ;
V_182 = & V_85 -> V_32 [ V_19 ] ;
if ( V_182 -> V_177 ) {
struct V_1 * V_2 ;
memset ( & V_85 -> V_50 , 0 , sizeof( V_85 -> V_50 ) ) ;
V_85 -> V_50 . type = V_4 -> type ;
V_85 -> V_50 . V_36 = V_4 -> V_36 ;
V_85 -> V_50 . V_19 = V_19 ;
V_37 = F_75 ( V_4 , & V_85 -> V_50 , V_180 ) ;
F_6 ( 5 , L_90 , V_37 ) ;
if ( V_37 )
goto V_183;
V_85 -> V_184 += 1 ;
V_2 = V_4 -> V_32 [ V_19 ] ;
V_182 -> V_8 = F_103 ( V_2 , 0 ) ;
V_182 -> V_177 = 0 ;
}
if ( V_182 -> V_185 + V_91 > V_182 -> V_8 ) {
V_91 = V_182 -> V_8 - V_182 -> V_185 ;
F_6 ( 5 , L_91 , V_91 ) ;
}
F_6 ( 3 , L_92 ,
V_91 , V_19 , V_182 -> V_185 ) ;
if ( V_172 )
V_37 = F_104 ( V_178 , V_182 -> V_100 + V_182 -> V_185 , V_91 ) ;
else
V_37 = F_105 ( V_182 -> V_100 + V_182 -> V_185 , V_178 , V_91 ) ;
if ( V_37 ) {
F_6 ( 3 , L_93 ) ;
V_37 = - V_186 ;
goto V_183;
}
V_182 -> V_185 += V_91 ;
* V_179 += V_91 ;
if ( V_182 -> V_185 == V_182 -> V_8 ||
( ! V_172 && ( V_85 -> V_62 & V_187 ) ) ) {
if ( V_172 && ( V_85 -> V_62 & V_188 ) &&
V_85 -> V_184 == 1 ) {
F_6 ( 3 , L_94 ) ;
V_4 -> V_85 = V_85 ;
return F_99 ( V_4 ) ;
}
memset ( & V_85 -> V_50 , 0 , sizeof( V_85 -> V_50 ) ) ;
V_85 -> V_50 . type = V_4 -> type ;
V_85 -> V_50 . V_36 = V_4 -> V_36 ;
V_85 -> V_50 . V_19 = V_19 ;
V_85 -> V_50 . V_54 = V_182 -> V_185 ;
V_37 = F_64 ( V_4 , & V_85 -> V_50 ) ;
F_6 ( 5 , L_95 , V_37 ) ;
if ( V_37 )
goto V_183;
V_182 -> V_185 = 0 ;
V_182 -> V_177 = 1 ;
V_182 -> V_8 = V_4 -> V_32 [ 0 ] -> V_14 [ 0 ] . V_15 ;
V_85 -> V_189 += 1 ;
V_85 -> V_19 = ( V_19 + 1 ) % V_4 -> V_30 ;
if ( ! V_172 && ! V_4 -> V_90 ) {
V_37 = F_79 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_183;
}
}
if ( V_37 == 0 )
V_37 = V_91 ;
V_183:
V_4 -> V_85 = V_85 ;
return V_37 ;
}
T_2 F_106 ( struct V_3 * V_4 , char T_3 * V_178 , T_2 V_91 ,
T_4 * V_179 , int V_126 )
{
return F_102 ( V_4 , V_178 , V_91 , V_179 , V_126 , 1 ) ;
}
T_2 F_107 ( struct V_3 * V_4 , char T_3 * V_178 , T_2 V_91 ,
T_4 * V_179 , int V_126 )
{
return F_102 ( V_4 , V_178 , V_91 , V_179 , V_126 , 0 ) ;
}
static inline bool F_108 ( struct V_154 * V_190 , struct V_152 * V_152 )
{
return V_190 -> V_191 -> V_192 && V_190 -> V_191 -> V_192 != V_152 -> V_161 ;
}
int F_109 ( struct V_152 * V_152 , void * V_193 ,
struct V_87 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
int V_157 = F_31 ( V_190 -> V_191 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_157 )
return V_157 ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
V_157 = F_32 ( V_190 -> V_191 , V_22 ) ;
if ( V_157 == 0 )
V_190 -> V_191 -> V_192 = V_22 -> V_91 ? V_152 -> V_161 : NULL ;
return V_157 ;
}
int F_110 ( struct V_152 * V_152 , void * V_193 ,
struct V_93 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
int V_157 = F_31 ( V_190 -> V_191 , V_22 -> V_36 , V_22 -> V_98 . type ) ;
V_22 -> V_19 = V_190 -> V_191 -> V_30 ;
if ( V_22 -> V_91 == 0 )
return V_157 != - V_86 ? V_157 : 0 ;
if ( V_157 )
return V_157 ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
V_157 = F_35 ( V_190 -> V_191 , V_22 ) ;
if ( V_157 == 0 )
V_190 -> V_191 -> V_192 = V_152 -> V_161 ;
return V_157 ;
}
int F_111 ( struct V_152 * V_152 , void * V_193 ,
struct V_49 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_62 ( V_190 -> V_191 , V_22 ) ;
}
int F_112 ( struct V_152 * V_152 , void * V_193 , struct V_49 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
return F_27 ( V_190 -> V_191 , V_22 ) ;
}
int F_113 ( struct V_152 * V_152 , void * V_193 , struct V_49 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_64 ( V_190 -> V_191 , V_22 ) ;
}
int F_114 ( struct V_152 * V_152 , void * V_193 , struct V_49 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_75 ( V_190 -> V_191 , V_22 , V_152 -> V_194 & V_195 ) ;
}
int F_115 ( struct V_152 * V_152 , void * V_193 , enum V_84 V_128 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_79 ( V_190 -> V_191 , V_128 ) ;
}
int F_116 ( struct V_152 * V_152 , void * V_193 , enum V_84 V_128 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_81 ( V_190 -> V_191 , V_128 ) ;
}
int F_117 ( struct V_152 * V_152 , void * V_193 , struct V_134 * V_22 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( F_108 ( V_190 , V_152 ) )
return - V_86 ;
return F_83 ( V_190 -> V_191 , V_22 ) ;
}
int F_118 ( struct V_152 * V_152 , struct V_139 * V_140 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
struct V_196 * V_197 = V_190 -> V_191 -> V_197 ? V_190 -> V_191 -> V_197 : V_190 -> V_197 ;
int V_112 ;
if ( V_197 && F_119 ( V_197 ) )
return - V_198 ;
V_112 = F_85 ( V_190 -> V_191 , V_140 ) ;
if ( V_197 )
F_120 ( V_197 ) ;
return V_112 ;
}
int F_121 ( struct V_152 * V_152 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
if ( V_152 -> V_161 == V_190 -> V_191 -> V_192 ) {
F_98 ( V_190 -> V_191 ) ;
V_190 -> V_191 -> V_192 = NULL ;
}
return F_122 ( V_152 ) ;
}
T_5 F_123 ( struct V_152 * V_152 , char T_3 * V_182 ,
T_2 V_91 , T_4 * V_179 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
struct V_196 * V_197 = V_190 -> V_191 -> V_197 ? V_190 -> V_191 -> V_197 : V_190 -> V_197 ;
int V_112 = - V_86 ;
if ( V_197 && F_119 ( V_197 ) )
return - V_198 ;
if ( F_108 ( V_190 , V_152 ) )
goto exit;
V_112 = F_107 ( V_190 -> V_191 , V_182 , V_91 , V_179 ,
V_152 -> V_194 & V_195 ) ;
if ( V_190 -> V_191 -> V_85 )
V_190 -> V_191 -> V_192 = V_152 -> V_161 ;
exit:
if ( V_197 )
F_120 ( V_197 ) ;
return V_112 ;
}
T_5 F_124 ( struct V_152 * V_152 , char T_3 * V_182 ,
T_2 V_91 , T_4 * V_179 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
struct V_196 * V_197 = V_190 -> V_191 -> V_197 ? V_190 -> V_191 -> V_197 : V_190 -> V_197 ;
int V_112 = - V_86 ;
if ( V_197 && F_119 ( V_197 ) )
return - V_198 ;
if ( F_108 ( V_190 , V_152 ) )
goto exit;
V_112 = F_106 ( V_190 -> V_191 , V_182 , V_91 , V_179 ,
V_152 -> V_194 & V_195 ) ;
if ( V_190 -> V_191 -> V_85 )
V_190 -> V_191 -> V_192 = V_152 -> V_161 ;
exit:
if ( V_197 )
F_120 ( V_197 ) ;
return V_112 ;
}
unsigned int F_125 ( struct V_152 * V_152 , T_1 * V_153 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
struct V_3 * V_4 = V_190 -> V_191 ;
struct V_196 * V_197 = V_4 -> V_197 ? V_4 -> V_197 : V_190 -> V_197 ;
unsigned long V_156 = F_89 ( V_153 ) ;
unsigned V_157 ;
void * V_85 ;
bool V_199 = false ;
if ( V_4 -> V_30 == 0 && V_4 -> V_85 == NULL ) {
if ( ! F_22 ( V_4 -> type ) && ( V_4 -> V_75 & V_167 ) &&
( V_156 & ( V_163 | V_164 ) ) )
V_199 = true ;
else if ( F_22 ( V_4 -> type ) && ( V_4 -> V_75 & V_169 ) &&
( V_156 & ( V_165 | V_166 ) ) )
V_199 = true ;
}
F_95 ( V_199 && ! V_197 ) ;
if ( V_199 && V_197 && F_119 ( V_197 ) )
return V_168 ;
V_85 = V_4 -> V_85 ;
V_157 = F_87 ( V_190 -> V_191 , V_152 , V_153 ) ;
if ( V_199 && ! V_85 && V_4 -> V_85 )
V_4 -> V_192 = V_152 -> V_161 ;
if ( V_199 && V_197 )
F_120 ( V_197 ) ;
return V_157 ;
}
unsigned long F_126 ( struct V_152 * V_152 , unsigned long V_149 ,
unsigned long V_150 , unsigned long V_151 , unsigned long V_62 )
{
struct V_154 * V_190 = F_88 ( V_152 ) ;
struct V_196 * V_197 = V_190 -> V_191 -> V_197 ? V_190 -> V_191 -> V_197 : V_190 -> V_197 ;
int V_37 ;
if ( V_197 && F_119 ( V_197 ) )
return - V_198 ;
V_37 = F_86 ( V_190 -> V_191 , V_149 , V_150 , V_151 , V_62 ) ;
if ( V_197 )
F_120 ( V_197 ) ;
return V_37 ;
}
void F_127 ( struct V_3 * V_200 )
{
F_120 ( V_200 -> V_197 ) ;
}
void F_128 ( struct V_3 * V_200 )
{
F_129 ( V_200 -> V_197 ) ;
}
