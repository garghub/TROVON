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
static void F_19 ( struct V_3 * V_4 , unsigned int V_44 )
{
unsigned int V_28 ;
if ( V_4 -> V_46 -> V_47 ) {
for ( V_28 = V_4 -> V_29 - V_44 ; V_28 < V_4 -> V_29 ;
++ V_28 ) {
if ( NULL == V_4 -> V_30 [ V_28 ] )
continue;
V_4 -> V_46 -> V_47 ( V_4 -> V_30 [ V_28 ] ) ;
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
F_20 ( & V_4 -> V_48 ) ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
if ( ! F_15 ( V_50 -> type ) )
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
static int F_22 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
unsigned int V_15 ;
unsigned int V_6 ;
if ( ! F_23 ( V_50 -> type ) )
return 0 ;
if ( F_15 ( V_50 -> type ) ) {
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
static bool F_24 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_13 [ V_6 ] . V_5 ;
if ( V_5 && F_3 ( V_4 , V_56 , V_5 ) > 1 )
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
static void F_26 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_50 , & V_2 -> V_18 , F_27 ( struct V_49 , V_33 ) ) ;
V_50 -> V_57 = V_2 -> V_18 . V_57 ;
V_50 -> V_58 = V_2 -> V_18 . V_58 ;
if ( F_15 ( V_4 -> type ) ) {
V_50 -> V_15 = V_2 -> V_7 ;
memcpy ( V_50 -> V_33 . V_13 , V_2 -> V_14 ,
V_50 -> V_15 * sizeof( struct V_32 ) ) ;
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
if ( F_24 ( V_4 , V_2 ) )
V_50 -> V_62 |= V_74 ;
}
int F_28 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_13 ) ;
return - V_51 ;
}
if ( V_50 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_14 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_30 [ V_50 -> V_19 ] ;
V_37 = F_21 ( V_2 , V_50 ) ;
if ( ! V_37 )
F_26 ( V_2 , V_50 ) ;
return V_37 ;
}
static int F_29 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_76 ) || ! V_4 -> V_77 -> V_78 ||
! V_4 -> V_77 -> V_20 )
return - V_51 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_79 ) || ! V_4 -> V_77 -> V_10 ||
! V_4 -> V_77 -> V_16 || ! V_4 -> V_77 -> V_80 )
return - V_51 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_75 & V_81 ) || ! V_4 -> V_77 -> V_82 ||
! V_4 -> V_77 -> V_25 || ! V_4 -> V_77 -> V_83 ||
! V_4 -> V_77 -> V_24 )
return - V_51 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
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
if ( V_36 == V_42 && F_30 ( V_4 ) ) {
F_6 ( 1 , L_17 ) ;
return - V_51 ;
}
if ( V_36 == V_53 && F_29 ( V_4 ) ) {
F_6 ( 1 , L_18 ) ;
return - V_51 ;
}
if ( V_36 == V_45 && F_31 ( V_4 ) ) {
F_6 ( 1 , L_19 ) ;
return - V_51 ;
}
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_20 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_87 * V_88 )
{
unsigned int V_29 , V_89 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_90 ) {
F_6 ( 1 , L_21 ) ;
return - V_86 ;
}
if ( V_88 -> V_91 == 0 || V_4 -> V_29 != 0 || V_4 -> V_36 != V_88 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_25 ( V_4 ) ) {
F_6 ( 1 , L_22 ) ;
return - V_86 ;
}
F_19 ( V_4 , V_4 -> V_29 ) ;
if ( V_88 -> V_91 == 0 )
return 0 ;
}
V_29 = F_34 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_88 -> V_36 ;
V_37 = F_17 ( V_4 , V_92 , V_4 , NULL , & V_29 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_4 , V_88 -> V_36 , V_29 , V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_89 = V_37 ;
if ( V_89 < V_29 ) {
V_29 = V_89 ;
V_37 = F_17 ( V_4 , V_92 , V_4 , NULL , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_89 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 = V_89 ;
if ( V_37 < 0 ) {
F_19 ( V_4 , V_89 ) ;
return V_37 ;
}
V_88 -> V_91 = V_89 ;
return 0 ;
}
int F_35 ( struct V_3 * V_4 , struct V_87 * V_88 )
{
int V_37 = F_32 ( V_4 , V_88 -> V_36 , V_88 -> type ) ;
return V_37 ? V_37 : F_33 ( V_4 , V_88 ) ;
}
static int F_36 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
unsigned int V_7 = 0 , V_29 , V_89 ;
int V_37 ;
if ( V_4 -> V_29 == V_95 ) {
F_6 ( 1 , L_24 ,
V_96 ) ;
return - V_97 ;
}
if ( ! V_4 -> V_29 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_94 -> V_36 ;
}
V_29 = F_37 ( V_94 -> V_91 , V_95 - V_4 -> V_29 ) ;
V_37 = F_17 ( V_4 , V_92 , V_4 , & V_94 -> V_98 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_4 , V_94 -> V_36 , V_29 ,
V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_89 = V_37 ;
if ( V_37 < V_29 ) {
V_29 = V_37 ;
V_37 = F_17 ( V_4 , V_92 , V_4 , & V_94 -> V_98 , & V_29 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_89 < V_29 )
V_37 = - V_17 ;
}
V_4 -> V_29 += V_89 ;
if ( V_37 < 0 ) {
F_19 ( V_4 , V_89 ) ;
return - V_17 ;
}
V_94 -> V_91 = V_89 ;
return 0 ;
}
int F_38 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
int V_37 = F_32 ( V_4 , V_94 -> V_36 , V_94 -> V_98 . type ) ;
V_94 -> V_19 = V_4 -> V_29 ;
if ( V_94 -> V_91 == 0 )
return V_37 != - V_86 ? V_37 : 0 ;
return V_37 ? V_37 : F_36 ( V_4 , V_94 ) ;
}
void * F_39 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_99 > V_2 -> V_7 || ! V_2 -> V_13 [ V_99 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_100 , V_2 -> V_13 [ V_99 ] . V_5 ) ;
}
void * F_40 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_99 > V_2 -> V_7 || ! V_2 -> V_13 [ V_99 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_101 , V_2 -> V_13 [ V_99 ] . V_5 ) ;
}
void F_41 ( struct V_1 * V_2 , enum V_102 V_40 )
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
F_42 ( & V_4 -> V_104 , V_62 ) ;
V_2 -> V_40 = V_40 ;
F_43 ( & V_2 -> V_105 , & V_4 -> V_106 ) ;
F_44 ( & V_4 -> V_107 ) ;
F_45 ( & V_4 -> V_104 , V_62 ) ;
F_46 ( & V_4 -> V_108 ) ;
}
static void F_47 ( struct V_1 * V_2 , const struct V_49 * V_50 ,
struct V_32 * V_14 )
{
unsigned int V_6 ;
if ( F_15 ( V_50 -> type ) ) {
if ( F_23 ( V_50 -> type ) ) {
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
if ( F_23 ( V_50 -> type ) ) {
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
static int F_48 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_32 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_23 ( V_4 -> type ) ;
F_47 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_60 &&
V_2 -> V_14 [ V_6 ] . V_33 . V_60 == V_13 [ V_6 ] . V_33 . V_60
&& V_2 -> V_14 [ V_6 ] . V_15 == V_13 [ V_6 ] . V_15 )
continue;
F_6 ( 3 , L_26
L_27 , V_6 ) ;
if ( V_13 [ V_6 ] . V_15 < V_4 -> V_9 [ V_6 ] ) {
F_6 ( 1 , L_28
L_29 ,
V_13 [ V_6 ] . V_15 ,
V_4 -> V_9 [ V_6 ] , V_6 ) ;
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
F_6 ( 1 , L_30
L_31 , V_6 ) ;
V_37 = V_5 ? F_49 ( V_5 ) : - V_51 ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
V_37 = F_17 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_32 ) ;
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
static int F_50 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
F_47 ( V_2 , V_50 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_32 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_23 ( V_4 -> type ) ;
F_47 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_113 * V_26 = F_52 ( V_13 [ V_6 ] . V_33 . V_61 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_33 ,
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
F_6 ( 1 , L_34 , V_6 ) ;
F_8 ( V_4 , & V_2 -> V_13 [ V_6 ] ) ;
memset ( & V_2 -> V_14 [ V_6 ] , 0 , sizeof( struct V_32 ) ) ;
V_5 = F_3 ( V_4 , V_82 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_111 ) ;
if ( F_53 ( V_5 ) ) {
F_6 ( 1 , L_35 ) ;
V_37 = F_49 ( V_5 ) ;
F_9 ( V_26 ) ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_3 ( V_4 , V_83 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
if ( V_37 ) {
F_6 ( 1 , L_36 ,
V_6 ) ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_23 = 1 ;
}
V_37 = F_17 ( V_4 , V_43 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_32 ) ;
goto V_112;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_14 [ V_6 ] = V_13 [ V_6 ] ;
return 0 ;
V_112:
F_10 ( V_2 ) ;
return V_37 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_66 ;
F_55 ( & V_4 -> V_107 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_114 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_4 -> V_46 -> V_115 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_37 ;
V_37 = F_22 ( V_2 , V_50 ) ;
if ( V_37 < 0 ) {
F_6 ( 1 , L_37 ,
V_96 , V_37 ) ;
return V_37 ;
}
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_50 ( V_2 , V_50 ) ;
break;
case V_53 :
V_37 = F_48 ( V_2 , V_50 ) ;
break;
case V_45 :
V_37 = F_51 ( V_2 , V_50 ) ;
break;
default:
F_57 ( 1 , L_38 ) ;
V_37 = - V_51 ;
}
if ( ! V_37 )
V_37 = F_17 ( V_4 , V_116 , V_2 ) ;
if ( V_37 )
F_6 ( 1 , L_39 , V_37 ) ;
else
V_2 -> V_40 = V_72 ;
return V_37 ;
}
static int F_58 ( struct V_3 * V_4 , struct V_49 * V_50 ,
const char * V_117 ,
int (* F_59)( struct V_3 * ,
struct V_49 * ,
struct V_1 * ) )
{
struct V_118 * V_119 = NULL ;
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_36 == V_53 ) {
V_119 = & V_120 -> V_121 -> V_119 ;
F_17 ( V_4 , V_122 , V_4 ) ;
F_60 ( V_119 ) ;
F_17 ( V_4 , V_123 , V_4 ) ;
}
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_40 , V_117 ) ;
V_37 = - V_86 ;
goto V_124;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_41 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
if ( V_50 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_42 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
V_2 = V_4 -> V_30 [ V_50 -> V_19 ] ;
if ( NULL == V_2 ) {
F_6 ( 1 , L_43 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
if ( V_50 -> V_36 != V_4 -> V_36 ) {
F_6 ( 1 , L_44 , V_117 ) ;
V_37 = - V_51 ;
goto V_124;
}
V_37 = F_21 ( V_2 , V_50 ) ;
if ( V_37 )
goto V_124;
V_37 = F_59 ( V_4 , V_50 , V_2 ) ;
if ( V_37 )
goto V_124;
F_26 ( V_2 , V_50 ) ;
F_6 ( 1 , L_45 , V_117 , V_2 -> V_18 . V_19 ) ;
V_124:
if ( V_119 )
F_61 ( V_119 ) ;
return V_37 ;
}
static int F_62 ( struct V_3 * V_4 , struct V_49 * V_50 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_40 != V_41 ) {
F_6 ( 1 , L_46 , V_96 ,
V_2 -> V_40 ) ;
return - V_51 ;
}
return F_56 ( V_2 , V_50 ) ;
}
int F_63 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
return F_58 ( V_4 , V_50 , L_47 , F_62 ) ;
}
static int F_64 ( struct V_3 * V_4 , struct V_49 * V_50 ,
struct V_1 * V_2 )
{
int V_37 ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_56 ( V_2 , V_50 ) ;
if ( V_37 )
return V_37 ;
case V_72 :
break;
default:
F_6 ( 1 , L_48 ) ;
return - V_51 ;
}
F_43 ( & V_2 -> V_125 , & V_4 -> V_48 ) ;
V_2 -> V_40 = V_65 ;
if ( V_4 -> V_90 )
F_54 ( V_2 ) ;
return 0 ;
}
int F_65 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
return F_58 ( V_4 , V_50 , L_49 , F_64 ) ;
}
static int F_66 ( struct V_3 * V_4 , int V_126 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_50 ) ;
return - V_51 ;
}
if ( ! F_67 ( & V_4 -> V_106 ) ) {
break;
}
if ( V_126 ) {
F_6 ( 1 , L_51
L_52 ) ;
return - V_127 ;
}
F_17 ( V_4 , V_122 , V_4 ) ;
F_6 ( 3 , L_53 ) ;
V_37 = F_68 ( V_4 -> V_108 ,
! F_67 ( & V_4 -> V_106 ) || ! V_4 -> V_90 ) ;
F_17 ( V_4 , V_123 , V_4 ) ;
if ( V_37 ) {
F_6 ( 1 , L_54 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_69 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_49 * V_50 , int V_126 )
{
unsigned long V_62 ;
int V_37 ;
V_37 = F_66 ( V_4 , V_126 ) ;
if ( V_37 )
return V_37 ;
F_42 ( & V_4 -> V_104 , V_62 ) ;
* V_2 = F_70 ( & V_4 -> V_106 , struct V_1 , V_105 ) ;
V_37 = F_21 ( * V_2 , V_50 ) ;
if ( ! V_37 )
F_71 ( & ( * V_2 ) -> V_105 ) ;
F_45 ( & V_4 -> V_104 , V_62 ) ;
return V_37 ;
}
int F_72 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_50 ) ;
return - V_51 ;
}
F_73 ( V_4 -> V_108 , ! F_74 ( & V_4 -> V_107 ) ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
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
int F_76 ( struct V_3 * V_4 , struct V_49 * V_50 , bool V_126 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_55 ) ;
return - V_86 ;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_56 ) ;
return - V_51 ;
}
V_37 = F_69 ( V_4 , & V_2 , V_50 , V_126 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_17 ( V_4 , V_129 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_57 ) ;
return V_37 ;
}
switch ( V_2 -> V_40 ) {
case V_70 :
F_6 ( 3 , L_58 ) ;
break;
case V_68 :
F_6 ( 3 , L_59 ) ;
break;
default:
F_6 ( 1 , L_60 ) ;
return - V_51 ;
}
F_26 ( V_2 , V_50 ) ;
F_71 ( & V_2 -> V_125 ) ;
F_75 ( V_2 ) ;
F_6 ( 1 , L_61 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
static void F_77 ( struct V_3 * V_4 )
{
unsigned int V_128 ;
if ( V_4 -> V_90 )
F_17 ( V_4 , V_130 , V_4 ) ;
V_4 -> V_90 = 0 ;
F_20 ( & V_4 -> V_48 ) ;
F_20 ( & V_4 -> V_106 ) ;
F_78 ( & V_4 -> V_107 , 0 ) ;
F_79 ( & V_4 -> V_108 ) ;
for ( V_128 = 0 ; V_128 < V_4 -> V_29 ; ++ V_128 )
F_75 ( V_4 -> V_30 [ V_128 ] ) ;
}
int F_80 ( struct V_3 * V_4 , enum V_84 type )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_62 ) ;
return - V_86 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_63 ) ;
return - V_51 ;
}
if ( V_4 -> V_90 ) {
F_6 ( 1 , L_64 ) ;
return - V_86 ;
}
F_81 (vb, &q->queued_list, queued_entry)
F_54 ( V_2 ) ;
V_37 = F_17 ( V_4 , V_131 , V_4 , F_74 ( & V_4 -> V_107 ) ) ;
if ( V_37 ) {
F_6 ( 1 , L_65 ) ;
F_77 ( V_4 ) ;
return V_37 ;
}
V_4 -> V_90 = 1 ;
F_6 ( 3 , L_66 ) ;
return 0 ;
}
int F_82 ( struct V_3 * V_4 , enum V_84 type )
{
if ( V_4 -> V_85 ) {
F_6 ( 1 , L_67 ) ;
return - V_86 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_68 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_90 ) {
F_6 ( 1 , L_69 ) ;
return - V_51 ;
}
F_77 ( V_4 ) ;
F_6 ( 3 , L_70 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 , unsigned long V_31 ,
unsigned int * V_132 , unsigned int * V_133 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; ++ V_28 ) {
V_2 = V_4 -> V_30 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_31 ) {
* V_132 = V_28 ;
* V_133 = V_6 ;
return 0 ;
}
}
}
return - V_51 ;
}
int F_84 ( struct V_3 * V_4 , struct V_134 * V_135 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_136 ;
int V_37 ;
struct V_113 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_77 -> V_137 ) {
F_6 ( 1 , L_72 ) ;
return - V_51 ;
}
if ( V_135 -> V_62 & ~ ( V_138 | V_139 ) ) {
F_6 ( 1 , L_73 ) ;
return - V_51 ;
}
if ( V_135 -> type != V_4 -> type ) {
F_6 ( 1 , L_74 ) ;
return - V_51 ;
}
if ( V_135 -> V_19 >= V_4 -> V_29 ) {
F_6 ( 1 , L_75 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_30 [ V_135 -> V_19 ] ;
if ( V_135 -> V_6 >= V_2 -> V_7 ) {
F_6 ( 1 , L_76 ) ;
return - V_51 ;
}
V_136 = & V_2 -> V_13 [ V_135 -> V_6 ] ;
V_26 = F_3 ( V_4 , V_137 , V_136 -> V_5 , V_135 -> V_62 & V_139 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_77 ,
V_135 -> V_19 , V_135 -> V_6 ) ;
return - V_51 ;
}
V_37 = F_85 ( V_26 , V_135 -> V_62 & ~ V_139 ) ;
if ( V_37 < 0 ) {
F_6 ( 3 , L_78 ,
V_135 -> V_19 , V_135 -> V_6 , V_37 ) ;
F_9 ( V_26 ) ;
return V_37 ;
}
F_6 ( 3 , L_79 ,
V_135 -> V_19 , V_135 -> V_6 , V_37 ) ;
V_135 -> V_61 = V_37 ;
return 0 ;
}
int F_86 ( struct V_3 * V_4 , struct V_140 * V_141 )
{
unsigned long V_31 = V_141 -> V_142 << V_143 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
if ( ! ( V_141 -> V_144 & V_145 ) ) {
F_6 ( 1 , L_80 ) ;
return - V_51 ;
}
if ( F_23 ( V_4 -> type ) ) {
if ( ! ( V_141 -> V_144 & V_146 ) ) {
F_6 ( 1 , L_81 ) ;
return - V_51 ;
}
} else {
if ( ! ( V_141 -> V_144 & V_147 ) ) {
F_6 ( 1 , L_82 ) ;
return - V_51 ;
}
}
V_37 = F_83 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_141 -> V_148 - V_141 -> V_149 ) ) {
F_6 ( 1 ,
L_83 ) ;
return - V_51 ;
}
V_37 = F_3 ( V_4 , V_80 , V_2 -> V_13 [ V_6 ] . V_5 , V_141 ) ;
if ( V_37 )
return V_37 ;
F_6 ( 3 , L_84 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_87 ( struct V_3 * V_4 ,
unsigned long V_150 ,
unsigned long V_151 ,
unsigned long V_152 ,
unsigned long V_62 )
{
unsigned long V_31 = V_152 << V_143 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
V_37 = F_83 ( V_4 , V_31 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_30 [ V_28 ] ;
return ( unsigned long ) F_39 ( V_2 , V_6 ) ;
}
unsigned int F_88 ( struct V_3 * V_4 , struct V_153 * V_153 , T_1 * V_154 )
{
struct V_155 * V_156 = F_89 ( V_153 ) ;
unsigned long V_157 = F_90 ( V_154 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_158 = 0 ;
unsigned long V_62 ;
if ( F_91 ( V_159 , & V_156 -> V_62 ) ) {
struct V_160 * V_161 = V_153 -> V_162 ;
if ( F_92 ( V_161 ) )
V_158 = V_163 ;
else if ( V_157 & V_163 )
F_93 ( V_153 , & V_161 -> V_154 , V_154 ) ;
}
if ( ! F_23 ( V_4 -> type ) && ! ( V_157 & ( V_164 | V_165 ) ) )
return V_158 ;
if ( F_23 ( V_4 -> type ) && ! ( V_157 & ( V_166 | V_167 ) ) )
return V_158 ;
if ( V_4 -> V_29 == 0 && V_4 -> V_85 == NULL ) {
if ( ! F_23 ( V_4 -> type ) && ( V_4 -> V_75 & V_168 ) &&
( V_157 & ( V_164 | V_165 ) ) ) {
if ( F_94 ( V_4 , 1 ) )
return V_158 | V_169 ;
}
if ( F_23 ( V_4 -> type ) && ( V_4 -> V_75 & V_170 ) &&
( V_157 & ( V_166 | V_167 ) ) ) {
if ( F_94 ( V_4 , 0 ) )
return V_158 | V_169 ;
return V_158 | V_166 | V_167 ;
}
}
if ( F_67 ( & V_4 -> V_48 ) )
return V_158 | V_169 ;
if ( F_67 ( & V_4 -> V_106 ) )
F_93 ( V_153 , & V_4 -> V_108 , V_154 ) ;
F_42 ( & V_4 -> V_104 , V_62 ) ;
if ( ! F_67 ( & V_4 -> V_106 ) )
V_2 = F_70 ( & V_4 -> V_106 , struct V_1 ,
V_105 ) ;
F_45 ( & V_4 -> V_104 , V_62 ) ;
if ( V_2 && ( V_2 -> V_40 == V_70
|| V_2 -> V_40 == V_68 ) ) {
return ( F_23 ( V_4 -> type ) ) ?
V_158 | V_166 | V_167 :
V_158 | V_164 | V_165 ;
}
return V_158 ;
}
int F_95 ( struct V_3 * V_4 )
{
if ( F_96 ( ! V_4 ) ||
F_96 ( ! V_4 -> V_46 ) ||
F_96 ( ! V_4 -> V_77 ) ||
F_96 ( ! V_4 -> type ) ||
F_96 ( ! V_4 -> V_75 ) ||
F_96 ( ! V_4 -> V_46 -> V_92 ) ||
F_96 ( ! V_4 -> V_46 -> V_115 ) ||
F_96 ( V_4 -> V_64 & ~ V_171 ) )
return - V_51 ;
F_96 ( V_4 -> V_64 == V_172 ) ;
F_20 ( & V_4 -> V_48 ) ;
F_20 ( & V_4 -> V_106 ) ;
F_97 ( & V_4 -> V_104 ) ;
F_98 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_99 ( struct V_3 * V_4 )
{
F_100 ( V_4 ) ;
F_77 ( V_4 ) ;
F_19 ( V_4 , V_4 -> V_29 ) ;
}
static int F_94 ( struct V_3 * V_4 , int V_173 )
{
struct V_174 * V_85 ;
int V_128 , V_37 ;
unsigned int V_91 = 0 ;
if ( ( V_173 && ! ( V_4 -> V_75 & V_168 ) ) ||
( ! V_173 && ! ( V_4 -> V_75 & V_170 ) ) )
F_101 () ;
if ( ! V_4 -> V_77 -> V_100 )
return - V_86 ;
if ( V_4 -> V_90 || V_4 -> V_29 > 0 )
return - V_86 ;
V_91 = 1 ;
F_6 ( 3 , L_85 ,
( V_173 ) ? L_86 : L_87 , V_91 , V_4 -> V_175 ) ;
V_85 = F_14 ( sizeof( struct V_174 ) , V_39 ) ;
if ( V_85 == NULL )
return - V_17 ;
V_85 -> V_62 = V_4 -> V_175 ;
V_85 -> V_88 . V_91 = V_91 ;
V_85 -> V_88 . V_36 = V_42 ;
V_85 -> V_88 . type = V_4 -> type ;
V_37 = F_35 ( V_4 , & V_85 -> V_88 ) ;
if ( V_37 )
goto V_176;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_86 ;
goto V_177;
}
for ( V_128 = 0 ; V_128 < V_4 -> V_29 ; V_128 ++ ) {
V_85 -> V_30 [ V_128 ] . V_100 = F_39 ( V_4 -> V_30 [ V_128 ] , 0 ) ;
if ( V_85 -> V_30 [ V_128 ] . V_100 == NULL ) {
V_37 = - V_51 ;
goto V_177;
}
V_85 -> V_30 [ V_128 ] . V_8 = F_102 ( V_4 -> V_30 [ V_128 ] , 0 ) ;
}
if ( V_173 ) {
for ( V_128 = 0 ; V_128 < V_4 -> V_29 ; V_128 ++ ) {
struct V_49 * V_50 = & V_85 -> V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> type = V_4 -> type ;
V_50 -> V_36 = V_4 -> V_36 ;
V_50 -> V_19 = V_128 ;
V_37 = F_65 ( V_4 , V_50 ) ;
if ( V_37 )
goto V_177;
V_85 -> V_30 [ V_128 ] . V_178 = 1 ;
}
V_37 = F_80 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_177;
}
V_4 -> V_85 = V_85 ;
return V_37 ;
V_177:
V_85 -> V_88 . V_91 = 0 ;
F_35 ( V_4 , & V_85 -> V_88 ) ;
V_176:
F_16 ( V_85 ) ;
return V_37 ;
}
static int F_100 ( struct V_3 * V_4 )
{
struct V_174 * V_85 = V_4 -> V_85 ;
if ( V_85 ) {
V_4 -> V_85 = NULL ;
F_82 ( V_4 , V_4 -> type ) ;
V_85 -> V_88 . V_91 = 0 ;
F_35 ( V_4 , & V_85 -> V_88 ) ;
F_16 ( V_85 ) ;
F_6 ( 3 , L_88 ) ;
}
return 0 ;
}
static T_2 F_103 ( struct V_3 * V_4 , char T_3 * V_179 , T_2 V_91 ,
T_4 * V_180 , int V_181 , int V_173 )
{
struct V_174 * V_85 ;
struct V_182 * V_183 ;
int V_37 , V_19 ;
F_6 ( 3 , L_89 ,
V_173 ? L_86 : L_87 , ( long ) * V_180 , V_91 ,
V_181 ? L_90 : L_91 ) ;
if ( ! V_179 )
return - V_51 ;
if ( ! V_4 -> V_85 ) {
V_37 = F_94 ( V_4 , V_173 ) ;
F_6 ( 3 , L_92 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_85 = V_4 -> V_85 ;
V_4 -> V_85 = NULL ;
V_19 = V_85 -> V_19 ;
V_183 = & V_85 -> V_30 [ V_19 ] ;
if ( V_183 -> V_178 ) {
struct V_1 * V_2 ;
memset ( & V_85 -> V_50 , 0 , sizeof( V_85 -> V_50 ) ) ;
V_85 -> V_50 . type = V_4 -> type ;
V_85 -> V_50 . V_36 = V_4 -> V_36 ;
V_85 -> V_50 . V_19 = V_19 ;
V_37 = F_76 ( V_4 , & V_85 -> V_50 , V_181 ) ;
F_6 ( 5 , L_93 , V_37 ) ;
if ( V_37 )
goto V_184;
V_85 -> V_185 += 1 ;
V_2 = V_4 -> V_30 [ V_19 ] ;
V_183 -> V_8 = F_104 ( V_2 , 0 ) ;
V_183 -> V_178 = 0 ;
}
if ( V_183 -> V_186 + V_91 > V_183 -> V_8 ) {
V_91 = V_183 -> V_8 - V_183 -> V_186 ;
F_6 ( 5 , L_94 , V_91 ) ;
}
F_6 ( 3 , L_95 ,
V_91 , V_19 , V_183 -> V_186 ) ;
if ( V_173 )
V_37 = F_105 ( V_179 , V_183 -> V_100 + V_183 -> V_186 , V_91 ) ;
else
V_37 = F_106 ( V_183 -> V_100 + V_183 -> V_186 , V_179 , V_91 ) ;
if ( V_37 ) {
F_6 ( 3 , L_96 ) ;
V_37 = - V_187 ;
goto V_184;
}
V_183 -> V_186 += V_91 ;
* V_180 += V_91 ;
if ( V_183 -> V_186 == V_183 -> V_8 ||
( ! V_173 && ( V_85 -> V_62 & V_188 ) ) ) {
if ( V_173 && ( V_85 -> V_62 & V_189 ) &&
V_85 -> V_185 == 1 ) {
F_6 ( 3 , L_97 ) ;
V_4 -> V_85 = V_85 ;
return F_100 ( V_4 ) ;
}
memset ( & V_85 -> V_50 , 0 , sizeof( V_85 -> V_50 ) ) ;
V_85 -> V_50 . type = V_4 -> type ;
V_85 -> V_50 . V_36 = V_4 -> V_36 ;
V_85 -> V_50 . V_19 = V_19 ;
V_85 -> V_50 . V_54 = V_183 -> V_186 ;
V_37 = F_65 ( V_4 , & V_85 -> V_50 ) ;
F_6 ( 5 , L_98 , V_37 ) ;
if ( V_37 )
goto V_184;
V_183 -> V_186 = 0 ;
V_183 -> V_178 = 1 ;
V_183 -> V_8 = V_4 -> V_30 [ 0 ] -> V_14 [ 0 ] . V_15 ;
V_85 -> V_190 += 1 ;
V_85 -> V_19 = ( V_19 + 1 ) % V_4 -> V_29 ;
if ( ! V_173 && ! V_4 -> V_90 ) {
V_37 = F_80 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_184;
}
}
if ( V_37 == 0 )
V_37 = V_91 ;
V_184:
V_4 -> V_85 = V_85 ;
return V_37 ;
}
T_2 F_107 ( struct V_3 * V_4 , char T_3 * V_179 , T_2 V_91 ,
T_4 * V_180 , int V_126 )
{
return F_103 ( V_4 , V_179 , V_91 , V_180 , V_126 , 1 ) ;
}
T_2 F_108 ( struct V_3 * V_4 , const char T_3 * V_179 , T_2 V_91 ,
T_4 * V_180 , int V_126 )
{
return F_103 ( V_4 , ( char T_3 * ) V_179 , V_91 ,
V_180 , V_126 , 0 ) ;
}
static inline bool F_109 ( struct V_155 * V_191 , struct V_153 * V_153 )
{
return V_191 -> V_192 -> V_193 && V_191 -> V_192 -> V_193 != V_153 -> V_162 ;
}
int F_110 ( struct V_153 * V_153 , void * V_194 ,
struct V_87 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
int V_158 = F_32 ( V_191 -> V_192 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_158 )
return V_158 ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
V_158 = F_33 ( V_191 -> V_192 , V_22 ) ;
if ( V_158 == 0 )
V_191 -> V_192 -> V_193 = V_22 -> V_91 ? V_153 -> V_162 : NULL ;
return V_158 ;
}
int F_111 ( struct V_153 * V_153 , void * V_194 ,
struct V_93 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
int V_158 = F_32 ( V_191 -> V_192 , V_22 -> V_36 , V_22 -> V_98 . type ) ;
V_22 -> V_19 = V_191 -> V_192 -> V_29 ;
if ( V_22 -> V_91 == 0 )
return V_158 != - V_86 ? V_158 : 0 ;
if ( V_158 )
return V_158 ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
V_158 = F_36 ( V_191 -> V_192 , V_22 ) ;
if ( V_158 == 0 )
V_191 -> V_192 -> V_193 = V_153 -> V_162 ;
return V_158 ;
}
int F_112 ( struct V_153 * V_153 , void * V_194 ,
struct V_49 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_63 ( V_191 -> V_192 , V_22 ) ;
}
int F_113 ( struct V_153 * V_153 , void * V_194 , struct V_49 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
return F_28 ( V_191 -> V_192 , V_22 ) ;
}
int F_114 ( struct V_153 * V_153 , void * V_194 , struct V_49 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_65 ( V_191 -> V_192 , V_22 ) ;
}
int F_115 ( struct V_153 * V_153 , void * V_194 , struct V_49 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_76 ( V_191 -> V_192 , V_22 , V_153 -> V_195 & V_196 ) ;
}
int F_116 ( struct V_153 * V_153 , void * V_194 , enum V_84 V_128 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_80 ( V_191 -> V_192 , V_128 ) ;
}
int F_117 ( struct V_153 * V_153 , void * V_194 , enum V_84 V_128 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_82 ( V_191 -> V_192 , V_128 ) ;
}
int F_118 ( struct V_153 * V_153 , void * V_194 , struct V_134 * V_22 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( F_109 ( V_191 , V_153 ) )
return - V_86 ;
return F_84 ( V_191 -> V_192 , V_22 ) ;
}
int F_119 ( struct V_153 * V_153 , struct V_140 * V_141 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_112 ;
if ( V_198 && F_120 ( V_198 ) )
return - V_199 ;
V_112 = F_86 ( V_191 -> V_192 , V_141 ) ;
if ( V_198 )
F_121 ( V_198 ) ;
return V_112 ;
}
int F_122 ( struct V_153 * V_153 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
if ( V_153 -> V_162 == V_191 -> V_192 -> V_193 ) {
F_99 ( V_191 -> V_192 ) ;
V_191 -> V_192 -> V_193 = NULL ;
}
return F_123 ( V_153 ) ;
}
T_5 F_124 ( struct V_153 * V_153 , const char T_3 * V_183 ,
T_2 V_91 , T_4 * V_180 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_112 = - V_86 ;
if ( V_198 && F_120 ( V_198 ) )
return - V_199 ;
if ( F_109 ( V_191 , V_153 ) )
goto exit;
V_112 = F_108 ( V_191 -> V_192 , V_183 , V_91 , V_180 ,
V_153 -> V_195 & V_196 ) ;
if ( V_191 -> V_192 -> V_85 )
V_191 -> V_192 -> V_193 = V_153 -> V_162 ;
exit:
if ( V_198 )
F_121 ( V_198 ) ;
return V_112 ;
}
T_5 F_125 ( struct V_153 * V_153 , char T_3 * V_183 ,
T_2 V_91 , T_4 * V_180 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_112 = - V_86 ;
if ( V_198 && F_120 ( V_198 ) )
return - V_199 ;
if ( F_109 ( V_191 , V_153 ) )
goto exit;
V_112 = F_107 ( V_191 -> V_192 , V_183 , V_91 , V_180 ,
V_153 -> V_195 & V_196 ) ;
if ( V_191 -> V_192 -> V_85 )
V_191 -> V_192 -> V_193 = V_153 -> V_162 ;
exit:
if ( V_198 )
F_121 ( V_198 ) ;
return V_112 ;
}
unsigned int F_126 ( struct V_153 * V_153 , T_1 * V_154 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
struct V_3 * V_4 = V_191 -> V_192 ;
struct V_197 * V_198 = V_4 -> V_198 ? V_4 -> V_198 : V_191 -> V_198 ;
unsigned long V_157 = F_90 ( V_154 ) ;
unsigned V_158 ;
void * V_85 ;
bool V_200 = false ;
if ( V_4 -> V_29 == 0 && V_4 -> V_85 == NULL ) {
if ( ! F_23 ( V_4 -> type ) && ( V_4 -> V_75 & V_168 ) &&
( V_157 & ( V_164 | V_165 ) ) )
V_200 = true ;
else if ( F_23 ( V_4 -> type ) && ( V_4 -> V_75 & V_170 ) &&
( V_157 & ( V_166 | V_167 ) ) )
V_200 = true ;
}
F_96 ( V_200 && ! V_198 ) ;
if ( V_200 && V_198 && F_120 ( V_198 ) )
return V_169 ;
V_85 = V_4 -> V_85 ;
V_158 = F_88 ( V_191 -> V_192 , V_153 , V_154 ) ;
if ( V_200 && ! V_85 && V_4 -> V_85 )
V_4 -> V_193 = V_153 -> V_162 ;
if ( V_200 && V_198 )
F_121 ( V_198 ) ;
return V_158 ;
}
unsigned long F_127 ( struct V_153 * V_153 , unsigned long V_150 ,
unsigned long V_151 , unsigned long V_152 , unsigned long V_62 )
{
struct V_155 * V_191 = F_89 ( V_153 ) ;
struct V_197 * V_198 = V_191 -> V_192 -> V_198 ? V_191 -> V_192 -> V_198 : V_191 -> V_198 ;
int V_37 ;
if ( V_198 && F_120 ( V_198 ) )
return - V_199 ;
V_37 = F_87 ( V_191 -> V_192 , V_150 , V_151 , V_152 , V_62 ) ;
if ( V_198 )
F_121 ( V_198 ) ;
return V_37 ;
}
void F_128 ( struct V_3 * V_201 )
{
F_121 ( V_201 -> V_198 ) ;
}
void F_129 ( struct V_3 * V_201 )
{
F_130 ( V_201 -> V_198 ) ;
}
