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
for ( V_28 = V_4 -> V_29 ; V_28 < V_4 -> V_29 + V_27 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] . V_15 = V_4 -> V_9 [ V_6 ] ;
}
}
static void F_12 ( struct V_3 * V_4 , unsigned int V_27 )
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
F_6 ( 3 , L_2 ,
V_28 , V_6 , V_31 ) ;
V_31 += V_2 -> V_14 [ V_6 ] . V_15 ;
V_31 = F_2 ( V_31 ) ;
}
}
}
static int F_13 ( struct V_3 * V_4 , enum V_35 V_36 ,
unsigned int V_29 , unsigned int V_7 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
int V_37 ;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 ) {
V_2 = F_14 ( V_4 -> V_38 , V_39 ) ;
if ( ! V_2 ) {
F_6 ( 1 , L_3 ) ;
break;
}
if ( F_15 ( V_4 -> type ) )
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
F_6 ( 1 , L_4
L_5 , V_28 ) ;
F_16 ( V_2 ) ;
break;
}
V_37 = F_17 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_6
L_7 , V_28 , V_2 ) ;
F_5 ( V_2 ) ;
F_16 ( V_2 ) ;
break;
}
}
V_4 -> V_30 [ V_4 -> V_29 + V_28 ] = V_2 ;
}
F_11 ( V_4 , V_28 ) ;
if ( V_36 == V_42 )
F_12 ( V_4 , V_28 ) ;
F_6 ( 1 , L_8 ,
V_28 , V_7 ) ;
return V_28 ;
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
struct V_1 * V_2 ;
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
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
static int F_19 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
if ( V_4 -> V_30 [ V_28 ] == NULL )
continue;
if ( V_4 -> V_30 [ V_28 ] -> V_40 == V_46 ) {
F_6 ( 1 , L_9 ) ;
return - V_47 ;
}
}
if ( V_4 -> V_48 -> V_49 ) {
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
if ( NULL == V_4 -> V_30 [ V_28 ] )
continue;
V_4 -> V_48 -> V_49 ( V_4 -> V_30 [ V_28 ] ) ;
}
}
F_18 ( V_4 , V_44 ) ;
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
F_16 ( V_4 -> V_30 [ V_28 ] ) ;
V_4 -> V_30 [ V_28 ] = NULL ;
}
V_4 -> V_29 -= V_44 ;
if ( ! V_4 -> V_29 )
V_4 -> V_36 = 0 ;
F_20 ( & V_4 -> V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
if ( ! F_15 ( V_52 -> type ) )
return 0 ;
if ( NULL == V_52 -> V_33 . V_13 ) {
F_6 ( 1 , L_10
L_11 ) ;
return - V_53 ;
}
if ( V_52 -> V_15 < V_2 -> V_7 || V_52 -> V_15 > V_54 ) {
F_6 ( 1 , L_12
L_13 , V_2 -> V_7 , V_52 -> V_15 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
unsigned int V_15 ;
unsigned int V_6 ;
if ( ! F_23 ( V_52 -> type ) )
return 0 ;
if ( F_15 ( V_52 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_15 = ( V_52 -> V_36 == V_55 )
? V_52 -> V_33 . V_13 [ V_6 ] . V_15
: V_2 -> V_14 [ V_6 ] . V_15 ;
if ( V_52 -> V_33 . V_13 [ V_6 ] . V_56 > V_15 )
return - V_53 ;
if ( V_52 -> V_33 . V_13 [ V_6 ] . V_57 > 0 &&
V_52 -> V_33 . V_13 [ V_6 ] . V_57 >=
V_52 -> V_33 . V_13 [ V_6 ] . V_56 )
return - V_53 ;
}
} else {
V_15 = ( V_52 -> V_36 == V_55 )
? V_52 -> V_15 : V_2 -> V_14 [ 0 ] . V_15 ;
if ( V_52 -> V_56 > V_15 )
return - V_53 ;
}
return 0 ;
}
static bool F_24 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_13 [ V_6 ] . V_5 ;
if ( V_5 && F_3 ( V_4 , V_58 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_25 ( struct V_3 * V_4 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
if ( F_24 ( V_4 , V_4 -> V_30 [ V_28 ] ) )
return true ;
}
return false ;
}
static void F_26 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_52 , & V_2 -> V_18 , F_27 ( struct V_51 , V_33 ) ) ;
V_52 -> V_59 = V_2 -> V_18 . V_59 ;
V_52 -> V_60 = V_2 -> V_18 . V_60 ;
if ( F_15 ( V_4 -> type ) ) {
V_52 -> V_15 = V_2 -> V_7 ;
memcpy ( V_52 -> V_33 . V_13 , V_2 -> V_14 ,
V_52 -> V_15 * sizeof( struct V_32 ) ) ;
} else {
V_52 -> V_15 = V_2 -> V_14 [ 0 ] . V_15 ;
V_52 -> V_56 = V_2 -> V_14 [ 0 ] . V_56 ;
if ( V_4 -> V_36 == V_42 )
V_52 -> V_33 . V_61 = V_2 -> V_14 [ 0 ] . V_33 . V_34 ;
else if ( V_4 -> V_36 == V_55 )
V_52 -> V_33 . V_62 = V_2 -> V_14 [ 0 ] . V_33 . V_62 ;
else if ( V_4 -> V_36 == V_45 )
V_52 -> V_33 . V_63 = V_2 -> V_14 [ 0 ] . V_33 . V_63 ;
}
V_52 -> V_64 &= ~ V_65 ;
V_52 -> V_64 |= V_4 -> V_66 ;
switch ( V_2 -> V_40 ) {
case V_67 :
case V_68 :
V_52 -> V_64 |= V_69 ;
break;
case V_70 :
V_52 -> V_64 |= V_71 ;
case V_72 :
V_52 -> V_64 |= V_73 ;
break;
case V_74 :
V_52 -> V_64 |= V_75 ;
break;
case V_46 :
case V_41 :
break;
}
if ( F_24 ( V_4 , V_2 ) )
V_52 -> V_64 |= V_76 ;
}
int F_28 ( struct V_3 * V_4 , struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_52 -> type != V_4 -> type ) {
F_6 ( 1 , L_14 ) ;
return - V_53 ;
}
if ( V_52 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_15 ) ;
return - V_53 ;
}
V_2 = V_4 -> V_30 [ V_52 -> V_19 ] ;
V_37 = F_21 ( V_2 , V_52 ) ;
if ( ! V_37 )
F_26 ( V_2 , V_52 ) ;
return V_37 ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_77 & V_78 ) || ! V_4 -> V_79 -> V_80 ||
! V_4 -> V_79 -> V_20 )
return - V_53 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_77 & V_81 ) || ! V_4 -> V_79 -> V_10 ||
! V_4 -> V_79 -> V_16 || ! V_4 -> V_79 -> V_82 )
return - V_53 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_77 & V_83 ) || ! V_4 -> V_79 -> V_84 ||
! V_4 -> V_79 -> V_25 || ! V_4 -> V_79 -> V_85 ||
! V_4 -> V_79 -> V_24 )
return - V_53 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
enum V_35 V_36 , enum V_86 type )
{
if ( V_36 != V_42 && V_36 != V_55 &&
V_36 != V_45 ) {
F_6 ( 1 , L_16 ) ;
return - V_53 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_17 ) ;
return - V_53 ;
}
if ( V_36 == V_42 && F_30 ( V_4 ) ) {
F_6 ( 1 , L_18 ) ;
return - V_53 ;
}
if ( V_36 == V_55 && F_29 ( V_4 ) ) {
F_6 ( 1 , L_19 ) ;
return - V_53 ;
}
if ( V_36 == V_45 && F_31 ( V_4 ) ) {
F_6 ( 1 , L_20 ) ;
return - V_53 ;
}
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_21 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
unsigned int V_29 , V_91 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_92 ) {
F_6 ( 1 , L_22 ) ;
return - V_88 ;
}
if ( V_90 -> V_93 == 0 || V_4 -> V_29 != 0 || V_4 -> V_36 != V_90 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_25 ( V_4 ) ) {
F_6 ( 1 , L_23 ) ;
return - V_88 ;
}
V_37 = F_19 ( V_4 , V_4 -> V_29 ) ;
if ( V_37 )
return V_37 ;
if ( V_90 -> V_93 == 0 )
return 0 ;
}
V_29 = F_34 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_90 -> V_36 ;
V_37 = F_17 ( V_4 , V_94 , V_4 , NULL , & V_29 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_4 , V_90 -> V_36 , V_29 , V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_24 ) ;
return - V_17 ;
}
V_91 = V_37 ;
if ( V_91 < V_29 ) {
V_29 = V_91 ;
V_37 = F_17 ( V_4 , V_94 , V_4 , NULL , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_91 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 = V_91 ;
if ( V_37 < 0 ) {
F_19 ( V_4 , V_91 ) ;
return V_37 ;
}
V_90 -> V_93 = V_91 ;
return 0 ;
}
int F_35 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
int V_37 = F_32 ( V_4 , V_90 -> V_36 , V_90 -> type ) ;
return V_37 ? V_37 : F_33 ( V_4 , V_90 ) ;
}
static int F_36 ( struct V_3 * V_4 , struct V_95 * V_96 )
{
unsigned int V_7 = 0 , V_29 , V_91 ;
int V_37 ;
if ( V_4 -> V_29 == V_97 ) {
F_6 ( 1 , L_25 ,
V_98 ) ;
return - V_99 ;
}
if ( ! V_4 -> V_29 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_96 -> V_36 ;
}
V_29 = F_37 ( V_96 -> V_93 , V_97 - V_4 -> V_29 ) ;
V_37 = F_17 ( V_4 , V_94 , V_4 , & V_96 -> V_100 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_4 , V_96 -> V_36 , V_29 ,
V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_24 ) ;
return - V_17 ;
}
V_91 = V_37 ;
if ( V_37 < V_29 ) {
V_29 = V_37 ;
V_37 = F_17 ( V_4 , V_94 , V_4 , & V_96 -> V_100 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_91 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 += V_91 ;
if ( V_37 < 0 ) {
F_19 ( V_4 , V_91 ) ;
return - V_17 ;
}
V_96 -> V_93 = V_91 ;
return 0 ;
}
int F_38 ( struct V_3 * V_4 , struct V_95 * V_96 )
{
int V_37 = F_32 ( V_4 , V_96 -> V_36 , V_96 -> V_100 . type ) ;
V_96 -> V_19 = V_4 -> V_29 ;
if ( V_96 -> V_93 == 0 )
return V_37 != - V_88 ? V_37 : 0 ;
return V_37 ? V_37 : F_36 ( V_4 , V_96 ) ;
}
void * F_39 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_101 > V_2 -> V_7 || ! V_2 -> V_13 [ V_101 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_102 , V_2 -> V_13 [ V_101 ] . V_5 ) ;
}
void * F_40 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_101 > V_2 -> V_7 || ! V_2 -> V_13 [ V_101 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_103 , V_2 -> V_13 [ V_101 ] . V_5 ) ;
}
void F_41 ( struct V_1 * V_2 , enum V_104 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_64 ;
unsigned int V_6 ;
if ( V_2 -> V_40 != V_68 )
return;
if ( V_40 != V_72 && V_40 != V_70 )
return;
F_6 ( 4 , L_26 ,
V_2 -> V_18 . V_19 , V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_105 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_42 ( & V_4 -> V_106 , V_64 ) ;
V_2 -> V_40 = V_40 ;
F_43 ( & V_2 -> V_107 , & V_4 -> V_108 ) ;
F_44 ( & V_4 -> V_109 ) ;
F_45 ( & V_4 -> V_106 , V_64 ) ;
F_46 ( & V_4 -> V_110 ) ;
}
static void F_47 ( struct V_1 * V_2 , const struct V_51 * V_52 ,
struct V_32 * V_14 )
{
unsigned int V_6 ;
if ( F_15 ( V_52 -> type ) ) {
if ( F_23 ( V_52 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_56 =
V_52 -> V_33 . V_13 [ V_6 ] . V_56 ;
V_14 [ V_6 ] . V_57 =
V_52 -> V_33 . V_13 [ V_6 ] . V_57 ;
}
}
if ( V_52 -> V_36 == V_55 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_62 =
V_52 -> V_33 . V_13 [ V_6 ] . V_33 . V_62 ;
V_14 [ V_6 ] . V_15 =
V_52 -> V_33 . V_13 [ V_6 ] . V_15 ;
}
}
if ( V_52 -> V_36 == V_45 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_63 =
V_52 -> V_33 . V_13 [ V_6 ] . V_33 . V_63 ;
V_14 [ V_6 ] . V_15 =
V_52 -> V_33 . V_13 [ V_6 ] . V_15 ;
V_14 [ V_6 ] . V_57 =
V_52 -> V_33 . V_13 [ V_6 ] . V_57 ;
}
}
} else {
if ( F_23 ( V_52 -> type ) ) {
V_14 [ 0 ] . V_56 = V_52 -> V_56 ;
V_14 [ 0 ] . V_57 = 0 ;
}
if ( V_52 -> V_36 == V_55 ) {
V_14 [ 0 ] . V_33 . V_62 = V_52 -> V_33 . V_62 ;
V_14 [ 0 ] . V_15 = V_52 -> V_15 ;
}
if ( V_52 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_63 = V_52 -> V_33 . V_63 ;
V_14 [ 0 ] . V_15 = V_52 -> V_15 ;
V_14 [ 0 ] . V_57 = 0 ;
}
}
V_2 -> V_18 . V_111 = V_52 -> V_111 ;
V_2 -> V_18 . V_112 = V_52 -> V_112 ;
V_2 -> V_18 . V_64 = V_52 -> V_64 & ~ V_65 ;
}
static int F_48 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_32 V_13 [ V_54 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_113 = ! F_23 ( V_4 -> type ) ;
F_47 ( V_2 , V_52 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_62 &&
V_2 -> V_14 [ V_6 ] . V_33 . V_62 == V_13 [ V_6 ] . V_33 . V_62
&& V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 )
continue;
F_6 ( 3 , L_27
L_28 , V_6 ) ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
F_6 ( 1 , L_29
L_30 ,
V_13 [ V_6 ] . V_15 ,
V_4 -> V_9 [ V_6 ] , V_6 ) ;
V_37 = - V_53 ;
goto V_114;
}
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_4 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_62 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
V_5 = F_3 ( V_4 , V_80 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_62 ,
V_13 [ V_6 ] . V_15 , V_113 ) ;
if ( F_4 ( V_5 ) ) {
F_6 ( 1 , L_31
L_32 , V_6 ) ;
V_37 = V_5 ? F_49 ( V_5 ) : - V_53 ;
goto V_114;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
V_37 = F_17 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_33 ) ;
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
return 0 ;
V_114:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_13 [ V_6 ] . V_5 )
F_3 ( V_4 , V_20 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_2 -> V_13 [ V_6 ] . V_5 = NULL ;
V_2 -> V_14 [ V_6 ] . V_33 . V_62 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
}
return V_37 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
F_47 ( V_2 , V_52 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_32 V_13 [ V_54 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_113 = ! F_23 ( V_4 -> type ) ;
F_47 ( V_2 , V_52 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_115 * V_26 = F_52 ( V_13 [ V_6 ] . V_33 . V_63 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_34 ,
V_6 ) ;
V_37 = - V_53 ;
goto V_114;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_13 [ V_6 ] . V_57 +
V_4 -> V_9 [ V_6 ] ) {
F_6 ( 1 , L_35 ,
V_6 ) ;
V_37 = - V_53 ;
goto V_114;
}
if ( V_26 == V_2 -> V_13 [ V_6 ] . V_26 &&
V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 ) {
F_9 ( V_26 ) ;
continue;
}
F_6 ( 1 , L_36 , V_6 ) ;
F_8 ( V_4 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_4 , V_84 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_113 ) ;
if ( F_53 ( V_5 ) ) {
F_6 ( 1 , L_37 ) ;
V_37 = F_49 ( V_5 ) ;
F_9 ( V_26 ) ;
goto V_114;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_3 ( V_4 , V_85 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_6 ( 1 , L_38 ,
V_6 ) ;
goto V_114;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
V_37 = F_17 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_33 ) ;
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
return 0 ;
V_114:
F_10 ( V_2 ) ;
return V_37 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_68 ;
F_55 ( & V_4 -> V_109 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_116 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_4 -> V_48 -> V_117 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
struct V_118 * V_119 ;
int V_37 ;
V_37 = F_22 ( V_2 , V_52 ) ;
if ( V_37 < 0 ) {
F_6 ( 1 , L_39 ,
V_98 , V_37 ) ;
return V_37 ;
}
V_2 -> V_40 = V_46 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_50 ( V_2 , V_52 ) ;
break;
case V_55 :
V_119 = & V_120 -> V_121 -> V_119 ;
F_17 ( V_4 , V_122 , V_4 ) ;
F_57 ( V_119 ) ;
F_17 ( V_4 , V_123 , V_4 ) ;
V_37 = F_48 ( V_2 , V_52 ) ;
F_58 ( V_119 ) ;
break;
case V_45 :
V_37 = F_51 ( V_2 , V_52 ) ;
break;
default:
F_59 ( 1 , L_40 ) ;
V_37 = - V_53 ;
}
if ( ! V_37 )
V_37 = F_17 ( V_4 , V_124 , V_2 ) ;
if ( V_37 )
F_6 ( 1 , L_41 , V_37 ) ;
V_2 -> V_40 = V_37 ? V_41 : V_74 ;
return V_37 ;
}
static int F_60 ( struct V_3 * V_4 , struct V_51 * V_52 ,
const char * V_125 )
{
if ( V_52 -> type != V_4 -> type ) {
F_6 ( 1 , L_42 , V_125 ) ;
return - V_53 ;
}
if ( V_52 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_43 , V_125 ) ;
return - V_53 ;
}
if ( V_4 -> V_30 [ V_52 -> V_19 ] == NULL ) {
F_6 ( 1 , L_44 , V_125 ) ;
return - V_53 ;
}
if ( V_52 -> V_36 != V_4 -> V_36 ) {
F_6 ( 1 , L_45 , V_125 ) ;
return - V_53 ;
}
return F_21 ( V_4 -> V_30 [ V_52 -> V_19 ] , V_52 ) ;
}
int F_61 ( struct V_3 * V_4 , struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_46 , V_98 ) ;
return - V_88 ;
}
V_37 = F_60 ( V_4 , V_52 , L_47 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_52 -> V_19 ] ;
if ( V_2 -> V_40 != V_41 ) {
F_6 ( 1 , L_48 , V_98 ,
V_2 -> V_40 ) ;
return - V_53 ;
}
V_37 = F_56 ( V_2 , V_52 ) ;
if ( ! V_37 ) {
F_26 ( V_2 , V_52 ) ;
F_6 ( 1 , L_49 , V_98 , V_2 -> V_18 . V_19 ) ;
}
return V_37 ;
}
static int F_62 ( struct V_3 * V_4 )
{
int V_37 ;
V_37 = F_17 ( V_4 , V_126 , V_4 , F_63 ( & V_4 -> V_109 ) ) ;
if ( V_37 == - V_99 ) {
F_6 ( 1 , L_50 ) ;
V_4 -> V_127 = 1 ;
return 0 ;
}
if ( V_37 )
F_6 ( 1 , L_51 ) ;
else
V_4 -> V_127 = 0 ;
return V_37 ;
}
static int F_64 ( struct V_3 * V_4 , struct V_51 * V_52 )
{
int V_37 = F_60 ( V_4 , V_52 , L_52 ) ;
struct V_1 * V_2 ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_52 -> V_19 ] ;
if ( V_2 -> V_40 != V_41 ) {
F_6 ( 1 , L_48 , V_98 ,
V_2 -> V_40 ) ;
return - V_53 ;
}
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_56 ( V_2 , V_52 ) ;
if ( V_37 )
return V_37 ;
break;
case V_74 :
break;
case V_46 :
F_6 ( 1 , L_53 ) ;
return - V_53 ;
default:
F_6 ( 1 , L_54 ) ;
return - V_53 ;
}
F_43 ( & V_2 -> V_128 , & V_4 -> V_50 ) ;
V_2 -> V_40 = V_67 ;
if ( V_4 -> V_92 )
F_54 ( V_2 ) ;
F_26 ( V_2 , V_52 ) ;
if ( V_4 -> V_127 ) {
V_37 = F_62 ( V_4 ) ;
if ( V_37 )
return V_37 ;
}
F_6 ( 1 , L_49 , V_98 , V_2 -> V_18 . V_19 ) ;
return 0 ;
}
int F_65 ( struct V_3 * V_4 , struct V_51 * V_52 )
{
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_46 , V_98 ) ;
return - V_88 ;
}
return F_64 ( V_4 , V_52 ) ;
}
static int F_66 ( struct V_3 * V_4 , int V_129 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_92 ) {
F_6 ( 1 , L_55 ) ;
return - V_53 ;
}
if ( ! F_67 ( & V_4 -> V_108 ) ) {
break;
}
if ( V_129 ) {
F_6 ( 1 , L_56
L_57 ) ;
return - V_47 ;
}
F_17 ( V_4 , V_122 , V_4 ) ;
F_6 ( 3 , L_58 ) ;
V_37 = F_68 ( V_4 -> V_110 ,
! F_67 ( & V_4 -> V_108 ) || ! V_4 -> V_92 ) ;
F_17 ( V_4 , V_123 , V_4 ) ;
if ( V_37 ) {
F_6 ( 1 , L_59 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_69 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_51 * V_52 , int V_129 )
{
unsigned long V_64 ;
int V_37 ;
V_37 = F_66 ( V_4 , V_129 ) ;
if ( V_37 )
return V_37 ;
F_42 ( & V_4 -> V_106 , V_64 ) ;
* V_2 = F_70 ( & V_4 -> V_108 , struct V_1 , V_107 ) ;
V_37 = F_21 ( * V_2 , V_52 ) ;
if ( ! V_37 )
F_71 ( & ( * V_2 ) -> V_107 ) ;
F_45 ( & V_4 -> V_106 , V_64 ) ;
return V_37 ;
}
int F_72 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_92 ) {
F_6 ( 1 , L_55 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_127 )
F_73 ( V_4 -> V_110 , ! F_63 ( & V_4 -> V_109 ) ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_130 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_130 = 0 ; V_130 < V_2 -> V_7 ; ++ V_130 ) {
if ( ! V_2 -> V_13 [ V_130 ] . V_23 )
continue;
F_3 ( V_4 , V_24 , V_2 -> V_13 [ V_130 ] . V_5 ) ;
V_2 -> V_13 [ V_130 ] . V_23 = 0 ;
}
}
static int F_75 ( struct V_3 * V_4 , struct V_51 * V_52 , bool V_129 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_52 -> type != V_4 -> type ) {
F_6 ( 1 , L_60 ) ;
return - V_53 ;
}
V_37 = F_69 ( V_4 , & V_2 , V_52 , V_129 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_17 ( V_4 , V_131 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_61 ) ;
return V_37 ;
}
switch ( V_2 -> V_40 ) {
case V_72 :
F_6 ( 3 , L_62 ) ;
break;
case V_70 :
F_6 ( 3 , L_63 ) ;
break;
default:
F_6 ( 1 , L_64 ) ;
return - V_53 ;
}
F_26 ( V_2 , V_52 ) ;
F_71 ( & V_2 -> V_128 ) ;
F_74 ( V_2 ) ;
F_6 ( 1 , L_65 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 , struct V_51 * V_52 , bool V_129 )
{
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_66 ) ;
return - V_88 ;
}
return F_75 ( V_4 , V_52 , V_129 ) ;
}
static void F_77 ( struct V_3 * V_4 )
{
unsigned int V_130 ;
if ( V_4 -> V_127 ) {
V_4 -> V_127 = 0 ;
V_4 -> V_92 = 0 ;
}
if ( V_4 -> V_92 )
F_17 ( V_4 , V_132 , V_4 ) ;
V_4 -> V_92 = 0 ;
F_20 ( & V_4 -> V_50 ) ;
F_20 ( & V_4 -> V_108 ) ;
F_78 ( & V_4 -> V_109 , 0 ) ;
F_79 ( & V_4 -> V_110 ) ;
for ( V_130 = 0 ; V_130 < V_4 -> V_29 ; ++ V_130 )
F_74 ( V_4 -> V_30 [ V_130 ] ) ;
}
static int F_80 ( struct V_3 * V_4 , enum V_86 type )
{
struct V_1 * V_2 ;
int V_37 ;
if ( type != V_4 -> type ) {
F_6 ( 1 , L_67 ) ;
return - V_53 ;
}
if ( V_4 -> V_92 ) {
F_6 ( 3 , L_68 ) ;
return 0 ;
}
if ( ! V_4 -> V_29 ) {
F_6 ( 1 , L_69 ) ;
return - V_53 ;
}
F_81 (vb, &q->queued_list, queued_entry)
F_54 ( V_2 ) ;
V_37 = F_62 ( V_4 ) ;
if ( V_37 ) {
F_77 ( V_4 ) ;
return V_37 ;
}
V_4 -> V_92 = 1 ;
F_6 ( 3 , L_70 ) ;
return 0 ;
}
int F_82 ( struct V_3 * V_4 , enum V_86 type )
{
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_71 ) ;
return - V_88 ;
}
return F_80 ( V_4 , type ) ;
}
static int F_83 ( struct V_3 * V_4 , enum V_86 type )
{
if ( type != V_4 -> type ) {
F_6 ( 1 , L_72 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_92 ) {
F_6 ( 3 , L_73 ) ;
return 0 ;
}
F_77 ( V_4 ) ;
F_6 ( 3 , L_74 ) ;
return 0 ;
}
int F_84 ( struct V_3 * V_4 , enum V_86 type )
{
if ( V_4 -> V_87 ) {
F_6 ( 1 , L_75 ) ;
return - V_88 ;
}
return F_83 ( V_4 , type ) ;
}
static int F_85 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_133 , unsigned int * V_134 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_31 ) {
* V_133 = V_28 ;
* V_134 = V_6 ;
return 0 ;
}
}
}
return - V_53 ;
}
int F_86 ( struct V_3 * V_4 , struct V_135 * V_136 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_137 ;
int V_37 ;
struct V_115 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_76 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_79 -> V_138 ) {
F_6 ( 1 , L_77 ) ;
return - V_53 ;
}
if ( V_136 -> V_64 & ~ ( V_139 | V_140 ) ) {
F_6 ( 1 , L_78 ) ;
return - V_53 ;
}
if ( V_136 -> type != V_4 -> type ) {
F_6 ( 1 , L_79 ) ;
return - V_53 ;
}
if ( V_136 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_80 ) ;
return - V_53 ;
}
V_2 = V_4 -> V_30 [ V_136 -> V_19 ] ;
if ( V_136 -> V_6 >= V_2 -> V_7 ) {
F_6 ( 1 , L_81 ) ;
return - V_53 ;
}
V_137 = & V_2 -> V_13 [ V_136 -> V_6 ] ;
V_26 = F_3 ( V_4 , V_138 , V_137 -> V_5 , V_136 -> V_64 & V_140 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_82 ,
V_136 -> V_19 , V_136 -> V_6 ) ;
return - V_53 ;
}
V_37 = F_87 ( V_26 , V_136 -> V_64 & ~ V_140 ) ;
if ( V_37 < 0 ) {
F_6 ( 3 , L_83 ,
V_136 -> V_19 , V_136 -> V_6 , V_37 ) ;
F_9 ( V_26 ) ;
return V_37 ;
}
F_6 ( 3 , L_84 ,
V_136 -> V_19 , V_136 -> V_6 , V_37 ) ;
V_136 -> V_63 = V_37 ;
return 0 ;
}
int F_88 ( struct V_3 * V_4 , struct V_141 * V_142 )
{
unsigned long V_31 = V_142 -> V_143 << V_144 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_76 ) ;
return - V_53 ;
}
if ( ! ( V_142 -> V_145 & V_146 ) ) {
F_6 ( 1 , L_85 ) ;
return - V_53 ;
}
if ( F_23 ( V_4 -> type ) ) {
if ( ! ( V_142 -> V_145 & V_147 ) ) {
F_6 ( 1 , L_86 ) ;
return - V_53 ;
}
} else {
if ( ! ( V_142 -> V_145 & V_148 ) ) {
F_6 ( 1 , L_87 ) ;
return - V_53 ;
}
}
V_37 = F_85 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_142 -> V_149 - V_142 -> V_150 ) ) {
F_6 ( 1 ,
L_88 ) ;
return - V_53 ;
}
V_37 = F_3 ( V_4 , V_82 , V_2 -> V_13 [ V_6 ] . V_5 , V_142 ) ;
if ( V_37 )
return V_37 ;
F_6 ( 3 , L_89 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_89 ( struct V_3 * V_4 ,
unsigned long V_151 ,
unsigned long V_152 ,
unsigned long V_153 ,
unsigned long V_64 )
{
unsigned long V_31 = V_153 << V_144 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_76 ) ;
return - V_53 ;
}
V_37 = F_85 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
return ( unsigned long ) F_39 ( V_2 , V_6 ) ;
}
unsigned int F_90 ( struct V_3 * V_4 , struct V_154 * V_154 , T_1 * V_155 )
{
struct V_156 * V_157 = F_91 ( V_154 ) ;
unsigned long V_158 = F_92 ( V_155 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_159 = 0 ;
unsigned long V_64 ;
if ( F_93 ( V_160 , & V_157 -> V_64 ) ) {
struct V_161 * V_162 = V_154 -> V_163 ;
if ( F_94 ( V_162 ) )
V_159 = V_164 ;
else if ( V_158 & V_164 )
F_95 ( V_154 , & V_162 -> V_155 , V_155 ) ;
}
if ( ! F_23 ( V_4 -> type ) && ! ( V_158 & ( V_165 | V_166 ) ) )
return V_159 ;
if ( F_23 ( V_4 -> type ) && ! ( V_158 & ( V_167 | V_168 ) ) )
return V_159 ;
if ( V_4 -> V_29 == 0 && V_4 -> V_87 == NULL ) {
if ( ! F_23 ( V_4 -> type ) && ( V_4 -> V_77 & V_169 ) &&
( V_158 & ( V_165 | V_166 ) ) ) {
if ( F_96 ( V_4 , 1 ) )
return V_159 | V_170 ;
}
if ( F_23 ( V_4 -> type ) && ( V_4 -> V_77 & V_171 ) &&
( V_158 & ( V_167 | V_168 ) ) ) {
if ( F_96 ( V_4 , 0 ) )
return V_159 | V_170 ;
return V_159 | V_167 | V_168 ;
}
}
if ( F_67 ( & V_4 -> V_50 ) )
return V_159 | V_170 ;
if ( F_67 ( & V_4 -> V_108 ) )
F_95 ( V_154 , & V_4 -> V_110 , V_155 ) ;
F_42 ( & V_4 -> V_106 , V_64 ) ;
if ( ! F_67 ( & V_4 -> V_108 ) )
V_2 = F_70 ( & V_4 -> V_108 , struct V_1 ,
V_107 ) ;
F_45 ( & V_4 -> V_106 , V_64 ) ;
if ( V_2 && ( V_2 -> V_40 == V_72
|| V_2 -> V_40 == V_70 ) ) {
return ( F_23 ( V_4 -> type ) ) ?
V_159 | V_167 | V_168 :
V_159 | V_165 | V_166 ;
}
return V_159 ;
}
int F_97 ( struct V_3 * V_4 )
{
if ( F_98 ( ! V_4 ) ||
F_98 ( ! V_4 -> V_48 ) ||
F_98 ( ! V_4 -> V_79 ) ||
F_98 ( ! V_4 -> type ) ||
F_98 ( ! V_4 -> V_77 ) ||
F_98 ( ! V_4 -> V_48 -> V_94 ) ||
F_98 ( ! V_4 -> V_48 -> V_117 ) ||
F_98 ( V_4 -> V_66 & ~ V_172 ) )
return - V_53 ;
F_98 ( V_4 -> V_66 == V_173 ) ;
F_20 ( & V_4 -> V_50 ) ;
F_20 ( & V_4 -> V_108 ) ;
F_99 ( & V_4 -> V_106 ) ;
F_100 ( & V_4 -> V_110 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_101 ( struct V_3 * V_4 )
{
F_102 ( V_4 ) ;
F_77 ( V_4 ) ;
F_19 ( V_4 , V_4 -> V_29 ) ;
}
static int F_96 ( struct V_3 * V_4 , int V_174 )
{
struct V_175 * V_87 ;
int V_130 , V_37 ;
unsigned int V_93 = 0 ;
if ( ( V_174 && ! ( V_4 -> V_77 & V_169 ) ) ||
( ! V_174 && ! ( V_4 -> V_77 & V_171 ) ) )
F_103 () ;
if ( ! V_4 -> V_79 -> V_102 )
return - V_88 ;
if ( V_4 -> V_92 || V_4 -> V_29 > 0 )
return - V_88 ;
V_93 = 1 ;
F_6 ( 3 , L_90 ,
( V_174 ) ? L_91 : L_92 , V_93 , V_4 -> V_176 ) ;
V_87 = F_14 ( sizeof( struct V_175 ) , V_39 ) ;
if ( V_87 == NULL )
return - V_17 ;
V_87 -> V_64 = V_4 -> V_176 ;
V_87 -> V_90 . V_93 = V_93 ;
V_87 -> V_90 . V_36 = V_42 ;
V_87 -> V_90 . type = V_4 -> type ;
V_37 = F_35 ( V_4 , & V_87 -> V_90 ) ;
if ( V_37 )
goto V_177;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_88 ;
goto V_178;
}
for ( V_130 = 0 ; V_130 < V_4 -> V_29 ; V_130 ++ ) {
V_87 -> V_30 [ V_130 ] . V_102 = F_39 ( V_4 -> V_30 [ V_130 ] , 0 ) ;
if ( V_87 -> V_30 [ V_130 ] . V_102 == NULL ) {
V_37 = - V_53 ;
goto V_178;
}
V_87 -> V_30 [ V_130 ] . V_8 = F_104 ( V_4 -> V_30 [ V_130 ] , 0 ) ;
}
if ( V_174 ) {
for ( V_130 = 0 ; V_130 < V_4 -> V_29 ; V_130 ++ ) {
struct V_51 * V_52 = & V_87 -> V_52 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> type = V_4 -> type ;
V_52 -> V_36 = V_4 -> V_36 ;
V_52 -> V_19 = V_130 ;
V_37 = F_65 ( V_4 , V_52 ) ;
if ( V_37 )
goto V_178;
V_87 -> V_30 [ V_130 ] . V_179 = 1 ;
}
V_87 -> V_19 = V_4 -> V_29 ;
}
V_37 = F_82 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_178;
V_4 -> V_87 = V_87 ;
return V_37 ;
V_178:
V_87 -> V_90 . V_93 = 0 ;
F_35 ( V_4 , & V_87 -> V_90 ) ;
V_177:
F_16 ( V_87 ) ;
return V_37 ;
}
static int F_102 ( struct V_3 * V_4 )
{
struct V_175 * V_87 = V_4 -> V_87 ;
if ( V_87 ) {
F_83 ( V_4 , V_4 -> type ) ;
V_4 -> V_87 = NULL ;
V_87 -> V_90 . V_93 = 0 ;
F_35 ( V_4 , & V_87 -> V_90 ) ;
F_16 ( V_87 ) ;
F_6 ( 3 , L_93 ) ;
}
return 0 ;
}
static T_2 F_105 ( struct V_3 * V_4 , char T_3 * V_180 , T_2 V_93 ,
T_4 * V_181 , int V_182 , int V_174 )
{
struct V_175 * V_87 ;
struct V_183 * V_184 ;
int V_37 , V_19 ;
F_6 ( 3 , L_94 ,
V_174 ? L_91 : L_92 , ( long ) * V_181 , V_93 ,
V_182 ? L_95 : L_96 ) ;
if ( ! V_180 )
return - V_53 ;
if ( ! V_4 -> V_87 ) {
V_37 = F_96 ( V_4 , V_174 ) ;
F_6 ( 3 , L_97 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_87 = V_4 -> V_87 ;
V_19 = V_87 -> V_19 ;
if ( V_19 >= V_4 -> V_29 ) {
memset ( & V_87 -> V_52 , 0 , sizeof( V_87 -> V_52 ) ) ;
V_87 -> V_52 . type = V_4 -> type ;
V_87 -> V_52 . V_36 = V_4 -> V_36 ;
V_37 = F_75 ( V_4 , & V_87 -> V_52 , V_182 ) ;
F_6 ( 5 , L_98 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_87 -> V_185 += 1 ;
V_19 = V_87 -> V_52 . V_19 ;
V_184 = & V_87 -> V_30 [ V_19 ] ;
V_184 -> V_186 = 0 ;
V_184 -> V_179 = 0 ;
V_184 -> V_8 = V_174 ? F_106 ( V_4 -> V_30 [ V_19 ] , 0 )
: F_104 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
} else {
V_184 = & V_87 -> V_30 [ V_19 ] ;
}
if ( V_184 -> V_186 + V_93 > V_184 -> V_8 ) {
V_93 = V_184 -> V_8 - V_184 -> V_186 ;
F_6 ( 5 , L_99 , V_93 ) ;
}
F_6 ( 3 , L_100 ,
V_93 , V_19 , V_184 -> V_186 ) ;
if ( V_174 )
V_37 = F_107 ( V_180 , V_184 -> V_102 + V_184 -> V_186 , V_93 ) ;
else
V_37 = F_108 ( V_184 -> V_102 + V_184 -> V_186 , V_180 , V_93 ) ;
if ( V_37 ) {
F_6 ( 3 , L_101 ) ;
return - V_187 ;
}
V_184 -> V_186 += V_93 ;
* V_181 += V_93 ;
if ( V_184 -> V_186 == V_184 -> V_8 ||
( ! V_174 && ( V_87 -> V_64 & V_188 ) ) ) {
if ( V_174 && ( V_87 -> V_64 & V_189 ) &&
V_87 -> V_185 == 1 ) {
F_6 ( 3 , L_102 ) ;
return F_102 ( V_4 ) ;
}
memset ( & V_87 -> V_52 , 0 , sizeof( V_87 -> V_52 ) ) ;
V_87 -> V_52 . type = V_4 -> type ;
V_87 -> V_52 . V_36 = V_4 -> V_36 ;
V_87 -> V_52 . V_19 = V_19 ;
V_87 -> V_52 . V_56 = V_184 -> V_186 ;
V_37 = F_64 ( V_4 , & V_87 -> V_52 ) ;
F_6 ( 5 , L_103 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_184 -> V_186 = 0 ;
V_184 -> V_179 = 1 ;
V_184 -> V_8 = F_104 ( V_4 -> V_30 [ V_19 ] , 0 ) ;
V_87 -> V_190 += 1 ;
if ( V_87 -> V_19 < V_4 -> V_29 )
V_87 -> V_19 ++ ;
}
if ( V_37 == 0 )
V_37 = V_93 ;
return V_37 ;
}
T_2 F_109 ( struct V_3 * V_4 , char T_3 * V_180 , T_2 V_93 ,
T_4 * V_181 , int V_129 )
{
return F_105 ( V_4 , V_180 , V_93 , V_181 , V_129 , 1 ) ;
}
T_2 F_110 ( struct V_3 * V_4 , const char T_3 * V_180 , T_2 V_93 ,
T_4 * V_181 , int V_129 )
{
return F_105 ( V_4 , ( char T_3 * ) V_180 , V_93 ,
V_181 , V_129 , 0 ) ;
}
static inline bool F_111 ( struct V_156 * V_191 , struct V_154 * V_154 )
{
return V_191 -> V_192 -> V_193 && V_191 -> V_192 -> V_193 != V_154 -> V_163 ;
}
int F_112 ( struct V_154 * V_154 , void * V_194 ,
struct V_89 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
int V_159 = F_32 ( V_191 -> V_192 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_159 )
return V_159 ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
V_159 = F_33 ( V_191 -> V_192 , V_22 ) ;
if ( V_159 == 0 )
V_191 -> V_192 -> V_193 = V_22 -> V_93 ? V_154 -> V_163 : NULL ;
return V_159 ;
}
int F_113 ( struct V_154 * V_154 , void * V_194 ,
struct V_95 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
int V_159 = F_32 ( V_191 -> V_192 , V_22 -> V_36 , V_22 -> V_100 . type ) ;
V_22 -> V_19 = V_191 -> V_192 -> V_29 ;
if ( V_22 -> V_93 == 0 )
return V_159 != - V_88 ? V_159 : 0 ;
if ( V_159 )
return V_159 ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
V_159 = F_36 ( V_191 -> V_192 , V_22 ) ;
if ( V_159 == 0 )
V_191 -> V_192 -> V_193 = V_154 -> V_163 ;
return V_159 ;
}
int F_114 ( struct V_154 * V_154 , void * V_194 ,
struct V_51 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_61 ( V_191 -> V_192 , V_22 ) ;
}
int F_115 ( struct V_154 * V_154 , void * V_194 , struct V_51 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
return F_28 ( V_191 -> V_192 , V_22 ) ;
}
int F_116 ( struct V_154 * V_154 , void * V_194 , struct V_51 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_65 ( V_191 -> V_192 , V_22 ) ;
}
int F_117 ( struct V_154 * V_154 , void * V_194 , struct V_51 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_76 ( V_191 -> V_192 , V_22 , V_154 -> V_195 & V_196 ) ;
}
int F_118 ( struct V_154 * V_154 , void * V_194 , enum V_86 V_130 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_82 ( V_191 -> V_192 , V_130 ) ;
}
int F_119 ( struct V_154 * V_154 , void * V_194 , enum V_86 V_130 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_84 ( V_191 -> V_192 , V_130 ) ;
}
int F_120 ( struct V_154 * V_154 , void * V_194 , struct V_135 * V_22 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( F_111 ( V_191 , V_154 ) )
return - V_88 ;
return F_86 ( V_191 -> V_192 , V_22 ) ;
}
int F_121 ( struct V_154 * V_154 , struct V_141 * V_142 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_114 ;
if ( V_198 && F_122 ( V_198 ) )
return - V_199 ;
V_114 = F_88 ( V_191 -> V_192 , V_142 ) ;
if ( V_198 )
F_123 ( V_198 ) ;
return V_114 ;
}
int F_124 ( struct V_154 * V_154 , struct V_197 * V_198 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
if ( V_154 -> V_163 == V_191 -> V_192 -> V_193 ) {
if ( V_198 )
F_125 ( V_198 ) ;
F_101 ( V_191 -> V_192 ) ;
V_191 -> V_192 -> V_193 = NULL ;
if ( V_198 )
F_123 ( V_198 ) ;
}
return F_126 ( V_154 ) ;
}
int F_127 ( struct V_154 * V_154 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
return F_124 ( V_154 , V_198 ) ;
}
T_5 F_128 ( struct V_154 * V_154 , const char T_3 * V_184 ,
T_2 V_93 , T_4 * V_181 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_114 = - V_88 ;
if ( V_198 && F_122 ( V_198 ) )
return - V_199 ;
if ( F_111 ( V_191 , V_154 ) )
goto exit;
V_114 = F_110 ( V_191 -> V_192 , V_184 , V_93 , V_181 ,
V_154 -> V_195 & V_196 ) ;
if ( V_191 -> V_192 -> V_87 )
V_191 -> V_192 -> V_193 = V_154 -> V_163 ;
exit:
if ( V_198 )
F_123 ( V_198 ) ;
return V_114 ;
}
T_5 F_129 ( struct V_154 * V_154 , char T_3 * V_184 ,
T_2 V_93 , T_4 * V_181 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_114 = - V_88 ;
if ( V_198 && F_122 ( V_198 ) )
return - V_199 ;
if ( F_111 ( V_191 , V_154 ) )
goto exit;
V_114 = F_109 ( V_191 -> V_192 , V_184 , V_93 , V_181 ,
V_154 -> V_195 & V_196 ) ;
if ( V_191 -> V_192 -> V_87 )
V_191 -> V_192 -> V_193 = V_154 -> V_163 ;
exit:
if ( V_198 )
F_123 ( V_198 ) ;
return V_114 ;
}
unsigned int F_130 ( struct V_154 * V_154 , T_1 * V_155 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_3 * V_4 = V_191 -> V_192 ;
struct V_197 * V_198 = V_4 -> V_198 ? V_4 -> V_198 : V_191 -> V_198 ;
unsigned long V_158 = F_92 ( V_155 ) ;
unsigned V_159 ;
void * V_87 ;
bool V_200 = false ;
if ( V_4 -> V_29 == 0 && V_4 -> V_87 == NULL ) {
if ( ! F_23 ( V_4 -> type ) && ( V_4 -> V_77 & V_169 ) &&
( V_158 & ( V_165 | V_166 ) ) )
V_200 = true ;
else if ( F_23 ( V_4 -> type ) && ( V_4 -> V_77 & V_171 ) &&
( V_158 & ( V_167 | V_168 ) ) )
V_200 = true ;
}
F_98 ( V_200 && ! V_198 ) ;
if ( V_200 && V_198 && F_122 ( V_198 ) )
return V_170 ;
V_87 = V_4 -> V_87 ;
V_159 = F_90 ( V_191 -> V_192 , V_154 , V_155 ) ;
if ( V_200 && ! V_87 && V_4 -> V_87 )
V_4 -> V_193 = V_154 -> V_163 ;
if ( V_200 && V_198 )
F_123 ( V_198 ) ;
return V_159 ;
}
unsigned long F_131 ( struct V_154 * V_154 , unsigned long V_151 ,
unsigned long V_152 , unsigned long V_153 , unsigned long V_64 )
{
struct V_156 * V_191 = F_91 ( V_154 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_37 ;
if ( V_198 && F_122 ( V_198 ) )
return - V_199 ;
V_37 = F_89 ( V_191 -> V_192 , V_151 , V_152 , V_153 , V_64 ) ;
if ( V_198 )
F_123 ( V_198 ) ;
return V_37 ;
}
void F_132 ( struct V_3 * V_201 )
{
F_123 ( V_201 -> V_198 ) ;
}
void F_133 ( struct V_3 * V_201 )
{
F_125 ( V_201 -> V_198 ) ;
}
