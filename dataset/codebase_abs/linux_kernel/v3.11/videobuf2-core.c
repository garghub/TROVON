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
static bool F_21 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_13 [ V_6 ] . V_5 ;
if ( V_5 && F_3 ( V_4 , V_53 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_22 ( struct V_3 * V_4 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_30 ; ++ V_28 ) {
if ( F_21 ( V_4 , V_4 -> V_32 [ V_28 ] ) )
return true ;
}
return false ;
}
static void F_23 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_50 , & V_2 -> V_18 , F_24 ( struct V_49 , V_33 ) ) ;
V_50 -> V_54 = V_2 -> V_18 . V_54 ;
V_50 -> V_55 = V_2 -> V_18 . V_55 ;
if ( F_14 ( V_4 -> type ) ) {
V_50 -> V_15 = V_2 -> V_7 ;
memcpy ( V_50 -> V_33 . V_13 , V_2 -> V_14 ,
V_50 -> V_15 * sizeof( struct V_31 ) ) ;
} else {
V_50 -> V_15 = V_2 -> V_14 [ 0 ] . V_15 ;
V_50 -> V_56 = V_2 -> V_14 [ 0 ] . V_56 ;
if ( V_4 -> V_36 == V_42 )
V_50 -> V_33 . V_57 = V_2 -> V_14 [ 0 ] . V_33 . V_34 ;
else if ( V_4 -> V_36 == V_58 )
V_50 -> V_33 . V_59 = V_2 -> V_14 [ 0 ] . V_33 . V_59 ;
else if ( V_4 -> V_36 == V_45 )
V_50 -> V_33 . V_60 = V_2 -> V_14 [ 0 ] . V_33 . V_60 ;
}
V_50 -> V_61 &= ~ V_62 ;
V_50 -> V_61 |= V_4 -> V_63 ;
switch ( V_2 -> V_40 ) {
case V_64 :
case V_65 :
V_50 -> V_61 |= V_66 ;
break;
case V_67 :
V_50 -> V_61 |= V_68 ;
case V_69 :
V_50 -> V_61 |= V_70 ;
break;
case V_71 :
V_50 -> V_61 |= V_72 ;
break;
case V_41 :
break;
}
if ( F_21 ( V_4 , V_2 ) )
V_50 -> V_61 |= V_73 ;
}
int F_25 ( struct V_3 * V_4 , struct V_49 * V_50 )
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
F_23 ( V_2 , V_50 ) ;
return V_37 ;
}
static int F_26 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_74 & V_75 ) || ! V_4 -> V_76 -> V_77 ||
! V_4 -> V_76 -> V_20 )
return - V_51 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_74 & V_78 ) || ! V_4 -> V_76 -> V_10 ||
! V_4 -> V_76 -> V_16 || ! V_4 -> V_76 -> V_79 )
return - V_51 ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_74 & V_80 ) || ! V_4 -> V_76 -> V_81 ||
! V_4 -> V_76 -> V_25 || ! V_4 -> V_76 -> V_82 ||
! V_4 -> V_76 -> V_24 )
return - V_51 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
enum V_35 V_36 , enum V_83 type )
{
if ( V_36 != V_42 && V_36 != V_58 &&
V_36 != V_45 ) {
F_6 ( 1 , L_15 ) ;
return - V_51 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_16 ) ;
return - V_51 ;
}
if ( V_36 == V_42 && F_27 ( V_4 ) ) {
F_6 ( 1 , L_17 ) ;
return - V_51 ;
}
if ( V_36 == V_58 && F_26 ( V_4 ) ) {
F_6 ( 1 , L_18 ) ;
return - V_51 ;
}
if ( V_36 == V_45 && F_28 ( V_4 ) ) {
F_6 ( 1 , L_19 ) ;
return - V_51 ;
}
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_20 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
unsigned int V_30 , V_88 , V_7 = 0 ;
int V_37 ;
if ( V_4 -> V_89 ) {
F_6 ( 1 , L_21 ) ;
return - V_85 ;
}
if ( V_87 -> V_90 == 0 || V_4 -> V_30 != 0 || V_4 -> V_36 != V_87 -> V_36 ) {
if ( V_4 -> V_36 == V_42 && F_22 ( V_4 ) ) {
F_6 ( 1 , L_22 ) ;
return - V_85 ;
}
F_18 ( V_4 , V_4 -> V_30 ) ;
if ( V_87 -> V_90 == 0 )
return 0 ;
}
V_30 = F_31 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_87 -> V_36 ;
V_37 = F_16 ( V_4 , V_91 , V_4 , NULL , & V_30 , & V_7 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_12 ( V_4 , V_87 -> V_36 , V_30 , V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_88 = V_37 ;
if ( V_88 < V_30 ) {
V_30 = V_88 ;
V_37 = F_16 ( V_4 , V_91 , V_4 , NULL , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_88 < V_30 )
V_37 = - V_17 ;
}
V_4 -> V_30 = V_88 ;
if ( V_37 < 0 ) {
F_18 ( V_4 , V_88 ) ;
return V_37 ;
}
V_87 -> V_90 = V_88 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
int V_37 = F_29 ( V_4 , V_87 -> V_36 , V_87 -> type ) ;
return V_37 ? V_37 : F_30 ( V_4 , V_87 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_92 * V_93 )
{
unsigned int V_7 = 0 , V_30 , V_88 ;
int V_37 ;
if ( V_4 -> V_30 == V_94 ) {
F_6 ( 1 , L_24 ,
V_95 ) ;
return - V_96 ;
}
if ( ! V_4 -> V_30 ) {
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_36 = V_93 -> V_36 ;
}
V_30 = F_34 ( V_93 -> V_90 , V_94 - V_4 -> V_30 ) ;
V_37 = F_16 ( V_4 , V_91 , V_4 , & V_93 -> V_97 , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_12 ( V_4 , V_93 -> V_36 , V_30 ,
V_7 ) ;
if ( V_37 == 0 ) {
F_6 ( 1 , L_23 ) ;
return - V_17 ;
}
V_88 = V_37 ;
if ( V_37 < V_30 ) {
V_30 = V_37 ;
V_37 = F_16 ( V_4 , V_91 , V_4 , & V_93 -> V_97 , & V_30 ,
& V_7 , V_4 -> V_9 , V_4 -> V_11 ) ;
if ( ! V_37 && V_88 < V_30 )
V_37 = - V_17 ;
}
V_4 -> V_30 += V_88 ;
if ( V_37 < 0 ) {
F_18 ( V_4 , V_88 ) ;
return - V_17 ;
}
V_93 -> V_90 = V_88 ;
return 0 ;
}
int F_35 ( struct V_3 * V_4 , struct V_92 * V_93 )
{
int V_37 = F_29 ( V_4 , V_93 -> V_36 , V_93 -> V_97 . type ) ;
V_93 -> V_19 = V_4 -> V_30 ;
if ( V_93 -> V_90 == 0 )
return V_37 != - V_85 ? V_37 : 0 ;
return V_37 ? V_37 : F_33 ( V_4 , V_93 ) ;
}
void * F_36 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_98 > V_2 -> V_7 || ! V_2 -> V_13 [ V_98 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_99 , V_2 -> V_13 [ V_98 ] . V_5 ) ;
}
void * F_37 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_98 > V_2 -> V_7 || ! V_2 -> V_13 [ V_98 ] . V_5 )
return NULL ;
return F_3 ( V_4 , V_100 , V_2 -> V_13 [ V_98 ] . V_5 ) ;
}
void F_38 ( struct V_1 * V_2 , enum V_101 V_40 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_61 ;
unsigned int V_6 ;
if ( V_2 -> V_40 != V_65 )
return;
if ( V_40 != V_69 && V_40 != V_67 )
return;
F_6 ( 4 , L_25 ,
V_2 -> V_18 . V_19 , V_40 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_102 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
F_39 ( & V_4 -> V_103 , V_61 ) ;
V_2 -> V_40 = V_40 ;
F_40 ( & V_2 -> V_104 , & V_4 -> V_105 ) ;
F_41 ( & V_4 -> V_106 ) ;
F_42 ( & V_4 -> V_103 , V_61 ) ;
F_43 ( & V_4 -> V_107 ) ;
}
static void F_44 ( struct V_1 * V_2 , const struct V_49 * V_50 ,
struct V_31 * V_14 )
{
unsigned int V_6 ;
if ( F_14 ( V_50 -> type ) ) {
if ( F_45 ( V_50 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_56 =
V_50 -> V_33 . V_13 [ V_6 ] . V_56 ;
V_14 [ V_6 ] . V_108 =
V_50 -> V_33 . V_13 [ V_6 ] . V_108 ;
}
}
if ( V_50 -> V_36 == V_58 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_59 =
V_50 -> V_33 . V_13 [ V_6 ] . V_33 . V_59 ;
V_14 [ V_6 ] . V_15 =
V_50 -> V_33 . V_13 [ V_6 ] . V_15 ;
}
}
if ( V_50 -> V_36 == V_45 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_14 [ V_6 ] . V_33 . V_60 =
V_50 -> V_33 . V_13 [ V_6 ] . V_33 . V_60 ;
V_14 [ V_6 ] . V_15 =
V_50 -> V_33 . V_13 [ V_6 ] . V_15 ;
V_14 [ V_6 ] . V_108 =
V_50 -> V_33 . V_13 [ V_6 ] . V_108 ;
}
}
} else {
if ( F_45 ( V_50 -> type ) ) {
V_14 [ 0 ] . V_56 = V_50 -> V_56 ;
V_14 [ 0 ] . V_108 = 0 ;
}
if ( V_50 -> V_36 == V_58 ) {
V_14 [ 0 ] . V_33 . V_59 = V_50 -> V_33 . V_59 ;
V_14 [ 0 ] . V_15 = V_50 -> V_15 ;
}
if ( V_50 -> V_36 == V_45 ) {
V_14 [ 0 ] . V_33 . V_60 = V_50 -> V_33 . V_60 ;
V_14 [ 0 ] . V_15 = V_50 -> V_15 ;
V_14 [ 0 ] . V_108 = 0 ;
}
}
V_2 -> V_18 . V_109 = V_50 -> V_109 ;
V_2 -> V_18 . V_110 = V_50 -> V_110 ;
V_2 -> V_18 . V_61 = V_50 -> V_61 & ~ V_62 ;
}
static int F_46 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_31 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_45 ( V_4 -> type ) ;
F_44 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_59 &&
V_2 -> V_14 [ V_6 ] . V_33 . V_59 == V_13 [ V_6 ] . V_33 . V_59
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
V_2 -> V_14 [ V_6 ] . V_33 . V_59 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
V_5 = F_3 ( V_4 , V_77 , V_4 -> V_11 [ V_6 ] ,
V_13 [ V_6 ] . V_33 . V_59 ,
V_13 [ V_6 ] . V_15 , V_111 ) ;
if ( F_4 ( V_5 ) ) {
F_6 ( 1 , L_28
L_29 , V_6 ) ;
V_37 = V_5 ? F_47 ( V_5 ) : - V_51 ;
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
V_2 -> V_14 [ V_6 ] . V_33 . V_59 = 0 ;
V_2 -> V_14 [ V_6 ] . V_15 = 0 ;
}
return V_37 ;
}
static int F_48 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
F_44 ( V_2 , V_50 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_31 V_13 [ V_52 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_37 ;
int V_111 = ! F_45 ( V_4 -> type ) ;
F_44 ( V_2 , V_50 , V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_113 * V_26 = F_50 ( V_13 [ V_6 ] . V_33 . V_60 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_31 ,
V_6 ) ;
V_37 = - V_51 ;
goto V_112;
}
if ( V_13 [ V_6 ] . V_15 == 0 )
V_13 [ V_6 ] . V_15 = V_26 -> V_8 ;
if ( V_13 [ V_6 ] . V_15 < V_13 [ V_6 ] . V_108 +
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
V_5 = F_3 ( V_4 , V_81 , V_4 -> V_11 [ V_6 ] ,
V_26 , V_13 [ V_6 ] . V_15 , V_111 ) ;
if ( F_51 ( V_5 ) ) {
F_6 ( 1 , L_33 ) ;
V_37 = F_47 ( V_5 ) ;
F_9 ( V_26 ) ;
goto V_112;
}
V_2 -> V_13 [ V_6 ] . V_26 = V_26 ;
V_2 -> V_13 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_37 = F_3 ( V_4 , V_82 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
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
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_40 = V_65 ;
F_53 ( & V_4 -> V_106 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_3 ( V_4 , V_114 , V_2 -> V_13 [ V_6 ] . V_5 ) ;
V_4 -> V_46 -> V_115 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_37 ;
switch ( V_4 -> V_36 ) {
case V_42 :
V_37 = F_48 ( V_2 , V_50 ) ;
break;
case V_58 :
V_37 = F_46 ( V_2 , V_50 ) ;
break;
case V_45 :
V_37 = F_49 ( V_2 , V_50 ) ;
break;
default:
F_55 ( 1 , L_35 ) ;
V_37 = - V_51 ;
}
if ( ! V_37 )
V_37 = F_16 ( V_4 , V_116 , V_2 ) ;
if ( V_37 )
F_6 ( 1 , L_36 , V_37 ) ;
else
V_2 -> V_40 = V_71 ;
return V_37 ;
}
int F_56 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_37 , V_95 ) ;
return - V_85 ;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_38 , V_95 ) ;
return - V_51 ;
}
if ( V_50 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_39 , V_95 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_32 [ V_50 -> V_19 ] ;
if ( NULL == V_2 ) {
F_6 ( 1 , L_40 , V_95 ) ;
return - V_51 ;
}
if ( V_50 -> V_36 != V_4 -> V_36 ) {
F_6 ( 1 , L_41 , V_95 ) ;
return - V_51 ;
}
if ( V_2 -> V_40 != V_41 ) {
F_6 ( 1 , L_42 , V_95 , V_2 -> V_40 ) ;
return - V_51 ;
}
V_37 = F_20 ( V_2 , V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_54 ( V_2 , V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
F_23 ( V_2 , V_50 ) ;
return 0 ;
}
int F_57 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
struct V_117 * V_118 = NULL ;
struct V_1 * V_2 ;
int V_37 = 0 ;
if ( V_4 -> V_36 == V_58 ) {
V_118 = & V_119 -> V_120 -> V_118 ;
F_16 ( V_4 , V_121 , V_4 ) ;
F_58 ( V_118 ) ;
F_16 ( V_4 , V_122 , V_4 ) ;
}
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_43 ) ;
V_37 = - V_85 ;
goto V_123;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_44 ) ;
V_37 = - V_51 ;
goto V_123;
}
if ( V_50 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_45 ) ;
V_37 = - V_51 ;
goto V_123;
}
V_2 = V_4 -> V_32 [ V_50 -> V_19 ] ;
if ( NULL == V_2 ) {
F_6 ( 1 , L_46 ) ;
V_37 = - V_51 ;
goto V_123;
}
if ( V_50 -> V_36 != V_4 -> V_36 ) {
F_6 ( 1 , L_47 ) ;
V_37 = - V_51 ;
goto V_123;
}
V_37 = F_20 ( V_2 , V_50 ) ;
if ( V_37 )
goto V_123;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = F_54 ( V_2 , V_50 ) ;
if ( V_37 )
goto V_123;
case V_71 :
break;
default:
F_6 ( 1 , L_48 ) ;
V_37 = - V_51 ;
goto V_123;
}
F_40 ( & V_2 -> V_124 , & V_4 -> V_48 ) ;
V_2 -> V_40 = V_64 ;
if ( V_4 -> V_89 )
F_52 ( V_2 ) ;
F_23 ( V_2 , V_50 ) ;
F_6 ( 1 , L_49 , V_2 -> V_18 . V_19 ) ;
V_123:
if ( V_118 )
F_59 ( V_118 ) ;
return V_37 ;
}
static int F_60 ( struct V_3 * V_4 , int V_125 )
{
for (; ; ) {
int V_37 ;
if ( ! V_4 -> V_89 ) {
F_6 ( 1 , L_50 ) ;
return - V_51 ;
}
if ( ! F_61 ( & V_4 -> V_105 ) ) {
break;
}
if ( V_125 ) {
F_6 ( 1 , L_51
L_52 ) ;
return - V_126 ;
}
F_16 ( V_4 , V_121 , V_4 ) ;
F_6 ( 3 , L_53 ) ;
V_37 = F_62 ( V_4 -> V_107 ,
! F_61 ( & V_4 -> V_105 ) || ! V_4 -> V_89 ) ;
F_16 ( V_4 , V_122 , V_4 ) ;
if ( V_37 ) {
F_6 ( 1 , L_54 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_63 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_49 * V_50 , int V_125 )
{
unsigned long V_61 ;
int V_37 ;
V_37 = F_60 ( V_4 , V_125 ) ;
if ( V_37 )
return V_37 ;
F_39 ( & V_4 -> V_103 , V_61 ) ;
* V_2 = F_64 ( & V_4 -> V_105 , struct V_1 , V_104 ) ;
V_37 = F_20 ( * V_2 , V_50 ) ;
if ( ! V_37 )
F_65 ( & ( * V_2 ) -> V_104 ) ;
F_42 ( & V_4 -> V_103 , V_61 ) ;
return V_37 ;
}
int F_66 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_89 ) {
F_6 ( 1 , L_50 ) ;
return - V_51 ;
}
F_67 ( V_4 -> V_107 , ! F_68 ( & V_4 -> V_106 ) ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_127 ;
if ( V_2 -> V_40 == V_41 )
return;
V_2 -> V_40 = V_41 ;
if ( V_4 -> V_36 == V_45 )
for ( V_127 = 0 ; V_127 < V_2 -> V_7 ; ++ V_127 ) {
if ( ! V_2 -> V_13 [ V_127 ] . V_23 )
continue;
F_3 ( V_4 , V_24 , V_2 -> V_13 [ V_127 ] . V_5 ) ;
V_2 -> V_13 [ V_127 ] . V_23 = 0 ;
}
}
int F_70 ( struct V_3 * V_4 , struct V_49 * V_50 , bool V_125 )
{
struct V_1 * V_2 = NULL ;
int V_37 ;
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_55 ) ;
return - V_85 ;
}
if ( V_50 -> type != V_4 -> type ) {
F_6 ( 1 , L_56 ) ;
return - V_51 ;
}
V_37 = F_63 ( V_4 , & V_2 , V_50 , V_125 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_16 ( V_4 , V_128 , V_2 ) ;
if ( V_37 ) {
F_6 ( 1 , L_57 ) ;
return V_37 ;
}
switch ( V_2 -> V_40 ) {
case V_69 :
F_6 ( 3 , L_58 ) ;
break;
case V_67 :
F_6 ( 3 , L_59 ) ;
break;
default:
F_6 ( 1 , L_60 ) ;
return - V_51 ;
}
F_23 ( V_2 , V_50 ) ;
F_65 ( & V_2 -> V_124 ) ;
F_69 ( V_2 ) ;
F_6 ( 1 , L_61 ,
V_2 -> V_18 . V_19 , V_2 -> V_40 ) ;
return 0 ;
}
static void F_71 ( struct V_3 * V_4 )
{
unsigned int V_127 ;
if ( V_4 -> V_89 )
F_16 ( V_4 , V_129 , V_4 ) ;
V_4 -> V_89 = 0 ;
F_19 ( & V_4 -> V_48 ) ;
F_19 ( & V_4 -> V_105 ) ;
F_72 ( & V_4 -> V_106 , 0 ) ;
F_73 ( & V_4 -> V_107 ) ;
for ( V_127 = 0 ; V_127 < V_4 -> V_30 ; ++ V_127 )
F_69 ( V_4 -> V_32 [ V_127 ] ) ;
}
int F_74 ( struct V_3 * V_4 , enum V_83 type )
{
struct V_1 * V_2 ;
int V_37 ;
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_62 ) ;
return - V_85 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_63 ) ;
return - V_51 ;
}
if ( V_4 -> V_89 ) {
F_6 ( 1 , L_64 ) ;
return - V_85 ;
}
F_75 (vb, &q->queued_list, queued_entry)
F_52 ( V_2 ) ;
V_37 = F_16 ( V_4 , V_130 , V_4 , F_68 ( & V_4 -> V_106 ) ) ;
if ( V_37 ) {
F_6 ( 1 , L_65 ) ;
F_71 ( V_4 ) ;
return V_37 ;
}
V_4 -> V_89 = 1 ;
F_6 ( 3 , L_66 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 , enum V_83 type )
{
if ( V_4 -> V_84 ) {
F_6 ( 1 , L_67 ) ;
return - V_85 ;
}
if ( type != V_4 -> type ) {
F_6 ( 1 , L_68 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_89 ) {
F_6 ( 1 , L_69 ) ;
return - V_51 ;
}
F_71 ( V_4 ) ;
F_6 ( 3 , L_70 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 , unsigned long V_29 ,
unsigned int * V_131 , unsigned int * V_132 )
{
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_30 ; ++ V_28 ) {
V_2 = V_4 -> V_32 [ V_28 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_14 [ V_6 ] . V_33 . V_34 == V_29 ) {
* V_131 = V_28 ;
* V_132 = V_6 ;
return 0 ;
}
}
}
return - V_51 ;
}
int F_78 ( struct V_3 * V_4 , struct V_133 * V_134 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_135 ;
int V_37 ;
struct V_113 * V_26 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_76 -> V_136 ) {
F_6 ( 1 , L_72 ) ;
return - V_51 ;
}
if ( V_134 -> V_61 & ~ V_137 ) {
F_6 ( 1 , L_73 ) ;
return - V_51 ;
}
if ( V_134 -> type != V_4 -> type ) {
F_6 ( 1 , L_44 ) ;
return - V_51 ;
}
if ( V_134 -> V_19 >= V_4 -> V_30 ) {
F_6 ( 1 , L_74 ) ;
return - V_51 ;
}
V_2 = V_4 -> V_32 [ V_134 -> V_19 ] ;
if ( V_134 -> V_6 >= V_2 -> V_7 ) {
F_6 ( 1 , L_75 ) ;
return - V_51 ;
}
V_135 = & V_2 -> V_13 [ V_134 -> V_6 ] ;
V_26 = F_3 ( V_4 , V_136 , V_135 -> V_5 ) ;
if ( F_4 ( V_26 ) ) {
F_6 ( 1 , L_76 ,
V_134 -> V_19 , V_134 -> V_6 ) ;
return - V_51 ;
}
V_37 = F_79 ( V_26 , V_134 -> V_61 ) ;
if ( V_37 < 0 ) {
F_6 ( 3 , L_77 ,
V_134 -> V_19 , V_134 -> V_6 , V_37 ) ;
F_9 ( V_26 ) ;
return V_37 ;
}
F_6 ( 3 , L_78 ,
V_134 -> V_19 , V_134 -> V_6 , V_37 ) ;
V_134 -> V_60 = V_37 ;
return 0 ;
}
int F_80 ( struct V_3 * V_4 , struct V_138 * V_139 )
{
unsigned long V_29 = V_139 -> V_140 << V_141 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
unsigned long V_15 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
if ( ! ( V_139 -> V_142 & V_143 ) ) {
F_6 ( 1 , L_79 ) ;
return - V_51 ;
}
if ( F_45 ( V_4 -> type ) ) {
if ( ! ( V_139 -> V_142 & V_144 ) ) {
F_6 ( 1 , L_80 ) ;
return - V_51 ;
}
} else {
if ( ! ( V_139 -> V_142 & V_145 ) ) {
F_6 ( 1 , L_81 ) ;
return - V_51 ;
}
}
V_37 = F_77 ( V_4 , V_29 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_32 [ V_28 ] ;
V_15 = F_2 ( V_2 -> V_14 [ V_6 ] . V_15 ) ;
if ( V_15 < ( V_139 -> V_146 - V_139 -> V_147 ) ) {
F_6 ( 1 ,
L_82 ) ;
return - V_51 ;
}
V_37 = F_3 ( V_4 , V_79 , V_2 -> V_13 [ V_6 ] . V_5 , V_139 ) ;
if ( V_37 )
return V_37 ;
F_6 ( 3 , L_83 , V_28 , V_6 ) ;
return 0 ;
}
unsigned long F_81 ( struct V_3 * V_4 ,
unsigned long V_148 ,
unsigned long V_149 ,
unsigned long V_150 ,
unsigned long V_61 )
{
unsigned long V_29 = V_150 << V_141 ;
struct V_1 * V_2 ;
unsigned int V_28 , V_6 ;
int V_37 ;
if ( V_4 -> V_36 != V_42 ) {
F_6 ( 1 , L_71 ) ;
return - V_51 ;
}
V_37 = F_77 ( V_4 , V_29 , & V_28 , & V_6 ) ;
if ( V_37 )
return V_37 ;
V_2 = V_4 -> V_32 [ V_28 ] ;
return ( unsigned long ) F_36 ( V_2 , V_6 ) ;
}
unsigned int F_82 ( struct V_3 * V_4 , struct V_151 * V_151 , T_1 * V_152 )
{
struct V_153 * V_154 = F_83 ( V_151 ) ;
unsigned long V_155 = F_84 ( V_152 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_156 = 0 ;
unsigned long V_61 ;
if ( F_85 ( V_157 , & V_154 -> V_61 ) ) {
struct V_158 * V_159 = V_151 -> V_160 ;
if ( F_86 ( V_159 ) )
V_156 = V_161 ;
else if ( V_155 & V_161 )
F_87 ( V_151 , & V_159 -> V_152 , V_152 ) ;
}
if ( ! F_45 ( V_4 -> type ) && ! ( V_155 & ( V_162 | V_163 ) ) )
return V_156 ;
if ( F_45 ( V_4 -> type ) && ! ( V_155 & ( V_164 | V_165 ) ) )
return V_156 ;
if ( V_4 -> V_30 == 0 && V_4 -> V_84 == NULL ) {
if ( ! F_45 ( V_4 -> type ) && ( V_4 -> V_74 & V_166 ) &&
( V_155 & ( V_162 | V_163 ) ) ) {
if ( F_88 ( V_4 , 1 ) )
return V_156 | V_167 ;
}
if ( F_45 ( V_4 -> type ) && ( V_4 -> V_74 & V_168 ) &&
( V_155 & ( V_164 | V_165 ) ) ) {
if ( F_88 ( V_4 , 0 ) )
return V_156 | V_167 ;
return V_156 | V_164 | V_165 ;
}
}
if ( F_61 ( & V_4 -> V_48 ) )
return V_156 | V_167 ;
if ( F_61 ( & V_4 -> V_105 ) )
F_87 ( V_151 , & V_4 -> V_107 , V_152 ) ;
F_39 ( & V_4 -> V_103 , V_61 ) ;
if ( ! F_61 ( & V_4 -> V_105 ) )
V_2 = F_64 ( & V_4 -> V_105 , struct V_1 ,
V_104 ) ;
F_42 ( & V_4 -> V_103 , V_61 ) ;
if ( V_2 && ( V_2 -> V_40 == V_69
|| V_2 -> V_40 == V_67 ) ) {
return ( F_45 ( V_4 -> type ) ) ?
V_156 | V_164 | V_165 :
V_156 | V_162 | V_163 ;
}
return V_156 ;
}
int F_89 ( struct V_3 * V_4 )
{
if ( F_90 ( ! V_4 ) ||
F_90 ( ! V_4 -> V_46 ) ||
F_90 ( ! V_4 -> V_76 ) ||
F_90 ( ! V_4 -> type ) ||
F_90 ( ! V_4 -> V_74 ) ||
F_90 ( ! V_4 -> V_46 -> V_91 ) ||
F_90 ( ! V_4 -> V_46 -> V_115 ) ||
F_90 ( V_4 -> V_63 & ~ V_169 ) )
return - V_51 ;
F_90 ( V_4 -> V_63 == V_170 ) ;
F_19 ( & V_4 -> V_48 ) ;
F_19 ( & V_4 -> V_105 ) ;
F_91 ( & V_4 -> V_103 ) ;
F_92 ( & V_4 -> V_107 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_38 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_93 ( struct V_3 * V_4 )
{
F_94 ( V_4 ) ;
F_71 ( V_4 ) ;
F_18 ( V_4 , V_4 -> V_30 ) ;
}
static int F_88 ( struct V_3 * V_4 , int V_171 )
{
struct V_172 * V_84 ;
int V_127 , V_37 ;
unsigned int V_90 = 0 ;
if ( ( V_171 && ! ( V_4 -> V_74 & V_166 ) ) ||
( ! V_171 && ! ( V_4 -> V_74 & V_168 ) ) )
F_95 () ;
if ( ! V_4 -> V_76 -> V_99 )
return - V_85 ;
if ( V_4 -> V_89 || V_4 -> V_30 > 0 )
return - V_85 ;
V_90 = 1 ;
F_6 ( 3 , L_84 ,
( V_171 ) ? L_85 : L_86 , V_90 , V_4 -> V_173 ) ;
V_84 = F_13 ( sizeof( struct V_172 ) , V_39 ) ;
if ( V_84 == NULL )
return - V_17 ;
V_84 -> V_61 = V_4 -> V_173 ;
V_84 -> V_87 . V_90 = V_90 ;
V_84 -> V_87 . V_36 = V_42 ;
V_84 -> V_87 . type = V_4 -> type ;
V_37 = F_32 ( V_4 , & V_84 -> V_87 ) ;
if ( V_37 )
goto V_174;
if ( V_4 -> V_32 [ 0 ] -> V_7 != 1 ) {
V_37 = - V_85 ;
goto V_175;
}
for ( V_127 = 0 ; V_127 < V_4 -> V_30 ; V_127 ++ ) {
V_84 -> V_32 [ V_127 ] . V_99 = F_36 ( V_4 -> V_32 [ V_127 ] , 0 ) ;
if ( V_84 -> V_32 [ V_127 ] . V_99 == NULL ) {
V_37 = - V_51 ;
goto V_175;
}
V_84 -> V_32 [ V_127 ] . V_8 = F_96 ( V_4 -> V_32 [ V_127 ] , 0 ) ;
}
if ( V_171 ) {
for ( V_127 = 0 ; V_127 < V_4 -> V_30 ; V_127 ++ ) {
struct V_49 * V_50 = & V_84 -> V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> type = V_4 -> type ;
V_50 -> V_36 = V_4 -> V_36 ;
V_50 -> V_19 = V_127 ;
V_37 = F_57 ( V_4 , V_50 ) ;
if ( V_37 )
goto V_175;
V_84 -> V_32 [ V_127 ] . V_176 = 1 ;
}
V_37 = F_74 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_175;
}
V_4 -> V_84 = V_84 ;
return V_37 ;
V_175:
V_84 -> V_87 . V_90 = 0 ;
F_32 ( V_4 , & V_84 -> V_87 ) ;
V_174:
F_15 ( V_84 ) ;
return V_37 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_172 * V_84 = V_4 -> V_84 ;
if ( V_84 ) {
V_4 -> V_84 = NULL ;
F_76 ( V_4 , V_4 -> type ) ;
V_84 -> V_87 . V_90 = 0 ;
F_32 ( V_4 , & V_84 -> V_87 ) ;
F_15 ( V_84 ) ;
F_6 ( 3 , L_87 ) ;
}
return 0 ;
}
static T_2 F_97 ( struct V_3 * V_4 , char T_3 * V_177 , T_2 V_90 ,
T_4 * V_178 , int V_179 , int V_171 )
{
struct V_172 * V_84 ;
struct V_180 * V_181 ;
int V_37 , V_19 ;
F_6 ( 3 , L_88 ,
V_171 ? L_85 : L_86 , ( long ) * V_178 , V_90 ,
V_179 ? L_89 : L_90 ) ;
if ( ! V_177 )
return - V_51 ;
if ( ! V_4 -> V_84 ) {
V_37 = F_88 ( V_4 , V_171 ) ;
F_6 ( 3 , L_91 , V_37 ) ;
if ( V_37 )
return V_37 ;
}
V_84 = V_4 -> V_84 ;
V_4 -> V_84 = NULL ;
V_19 = V_84 -> V_19 ;
V_181 = & V_84 -> V_32 [ V_19 ] ;
if ( V_181 -> V_176 ) {
struct V_1 * V_2 ;
memset ( & V_84 -> V_50 , 0 , sizeof( V_84 -> V_50 ) ) ;
V_84 -> V_50 . type = V_4 -> type ;
V_84 -> V_50 . V_36 = V_4 -> V_36 ;
V_84 -> V_50 . V_19 = V_19 ;
V_37 = F_70 ( V_4 , & V_84 -> V_50 , V_179 ) ;
F_6 ( 5 , L_92 , V_37 ) ;
if ( V_37 )
goto V_182;
V_84 -> V_183 += 1 ;
V_2 = V_4 -> V_32 [ V_19 ] ;
V_181 -> V_8 = F_98 ( V_2 , 0 ) ;
V_181 -> V_176 = 0 ;
}
if ( V_181 -> V_184 + V_90 > V_181 -> V_8 ) {
V_90 = V_181 -> V_8 - V_181 -> V_184 ;
F_6 ( 5 , L_93 , V_90 ) ;
}
F_6 ( 3 , L_94 ,
V_90 , V_19 , V_181 -> V_184 ) ;
if ( V_171 )
V_37 = F_99 ( V_177 , V_181 -> V_99 + V_181 -> V_184 , V_90 ) ;
else
V_37 = F_100 ( V_181 -> V_99 + V_181 -> V_184 , V_177 , V_90 ) ;
if ( V_37 ) {
F_6 ( 3 , L_95 ) ;
V_37 = - V_185 ;
goto V_182;
}
V_181 -> V_184 += V_90 ;
* V_178 += V_90 ;
if ( V_181 -> V_184 == V_181 -> V_8 ||
( ! V_171 && ( V_84 -> V_61 & V_186 ) ) ) {
if ( V_171 && ( V_84 -> V_61 & V_187 ) &&
V_84 -> V_183 == 1 ) {
F_6 ( 3 , L_96 ) ;
V_4 -> V_84 = V_84 ;
return F_94 ( V_4 ) ;
}
memset ( & V_84 -> V_50 , 0 , sizeof( V_84 -> V_50 ) ) ;
V_84 -> V_50 . type = V_4 -> type ;
V_84 -> V_50 . V_36 = V_4 -> V_36 ;
V_84 -> V_50 . V_19 = V_19 ;
V_84 -> V_50 . V_56 = V_181 -> V_184 ;
V_37 = F_57 ( V_4 , & V_84 -> V_50 ) ;
F_6 ( 5 , L_97 , V_37 ) ;
if ( V_37 )
goto V_182;
V_181 -> V_184 = 0 ;
V_181 -> V_176 = 1 ;
V_181 -> V_8 = V_4 -> V_32 [ 0 ] -> V_14 [ 0 ] . V_15 ;
V_84 -> V_188 += 1 ;
V_84 -> V_19 = ( V_19 + 1 ) % V_4 -> V_30 ;
if ( ! V_171 && ! V_4 -> V_89 ) {
V_37 = F_74 ( V_4 , V_4 -> type ) ;
if ( V_37 )
goto V_182;
}
}
if ( V_37 == 0 )
V_37 = V_90 ;
V_182:
V_4 -> V_84 = V_84 ;
return V_37 ;
}
T_2 F_101 ( struct V_3 * V_4 , char T_3 * V_177 , T_2 V_90 ,
T_4 * V_178 , int V_125 )
{
return F_97 ( V_4 , V_177 , V_90 , V_178 , V_125 , 1 ) ;
}
T_2 F_102 ( struct V_3 * V_4 , char T_3 * V_177 , T_2 V_90 ,
T_4 * V_178 , int V_125 )
{
return F_97 ( V_4 , V_177 , V_90 , V_178 , V_125 , 0 ) ;
}
static inline bool F_103 ( struct V_153 * V_189 , struct V_151 * V_151 )
{
return V_189 -> V_190 -> V_191 && V_189 -> V_190 -> V_191 != V_151 -> V_160 ;
}
int F_104 ( struct V_151 * V_151 , void * V_192 ,
struct V_86 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
int V_156 = F_29 ( V_189 -> V_190 , V_22 -> V_36 , V_22 -> type ) ;
if ( V_156 )
return V_156 ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
V_156 = F_30 ( V_189 -> V_190 , V_22 ) ;
if ( V_156 == 0 )
V_189 -> V_190 -> V_191 = V_22 -> V_90 ? V_151 -> V_160 : NULL ;
return V_156 ;
}
int F_105 ( struct V_151 * V_151 , void * V_192 ,
struct V_92 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
int V_156 = F_29 ( V_189 -> V_190 , V_22 -> V_36 , V_22 -> V_97 . type ) ;
V_22 -> V_19 = V_189 -> V_190 -> V_30 ;
if ( V_22 -> V_90 == 0 )
return V_156 != - V_85 ? V_156 : 0 ;
if ( V_156 )
return V_156 ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
V_156 = F_33 ( V_189 -> V_190 , V_22 ) ;
if ( V_156 == 0 )
V_189 -> V_190 -> V_191 = V_151 -> V_160 ;
return V_156 ;
}
int F_106 ( struct V_151 * V_151 , void * V_192 ,
struct V_49 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_56 ( V_189 -> V_190 , V_22 ) ;
}
int F_107 ( struct V_151 * V_151 , void * V_192 , struct V_49 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
return F_25 ( V_189 -> V_190 , V_22 ) ;
}
int F_108 ( struct V_151 * V_151 , void * V_192 , struct V_49 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_57 ( V_189 -> V_190 , V_22 ) ;
}
int F_109 ( struct V_151 * V_151 , void * V_192 , struct V_49 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_70 ( V_189 -> V_190 , V_22 , V_151 -> V_193 & V_194 ) ;
}
int F_110 ( struct V_151 * V_151 , void * V_192 , enum V_83 V_127 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_74 ( V_189 -> V_190 , V_127 ) ;
}
int F_111 ( struct V_151 * V_151 , void * V_192 , enum V_83 V_127 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_76 ( V_189 -> V_190 , V_127 ) ;
}
int F_112 ( struct V_151 * V_151 , void * V_192 , struct V_133 * V_22 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( F_103 ( V_189 , V_151 ) )
return - V_85 ;
return F_78 ( V_189 -> V_190 , V_22 ) ;
}
int F_113 ( struct V_151 * V_151 , struct V_138 * V_139 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
return F_80 ( V_189 -> V_190 , V_139 ) ;
}
int F_114 ( struct V_151 * V_151 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
if ( V_151 -> V_160 == V_189 -> V_190 -> V_191 ) {
F_93 ( V_189 -> V_190 ) ;
V_189 -> V_190 -> V_191 = NULL ;
}
return F_115 ( V_151 ) ;
}
T_5 F_116 ( struct V_151 * V_151 , char T_3 * V_181 ,
T_2 V_90 , T_4 * V_178 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
struct V_195 * V_196 = V_189 -> V_190 -> V_196 ? V_189 -> V_190 -> V_196 : V_189 -> V_196 ;
int V_112 = - V_85 ;
if ( V_196 && F_117 ( V_196 ) )
return - V_197 ;
if ( F_103 ( V_189 , V_151 ) )
goto exit;
V_112 = F_102 ( V_189 -> V_190 , V_181 , V_90 , V_178 ,
V_151 -> V_193 & V_194 ) ;
if ( V_189 -> V_190 -> V_84 )
V_189 -> V_190 -> V_191 = V_151 -> V_160 ;
exit:
if ( V_196 )
F_118 ( V_196 ) ;
return V_112 ;
}
T_5 F_119 ( struct V_151 * V_151 , char T_3 * V_181 ,
T_2 V_90 , T_4 * V_178 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
struct V_195 * V_196 = V_189 -> V_190 -> V_196 ? V_189 -> V_190 -> V_196 : V_189 -> V_196 ;
int V_112 = - V_85 ;
if ( V_196 && F_117 ( V_196 ) )
return - V_197 ;
if ( F_103 ( V_189 , V_151 ) )
goto exit;
V_112 = F_101 ( V_189 -> V_190 , V_181 , V_90 , V_178 ,
V_151 -> V_193 & V_194 ) ;
if ( V_189 -> V_190 -> V_84 )
V_189 -> V_190 -> V_191 = V_151 -> V_160 ;
exit:
if ( V_196 )
F_118 ( V_196 ) ;
return V_112 ;
}
unsigned int F_120 ( struct V_151 * V_151 , T_1 * V_152 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
struct V_3 * V_4 = V_189 -> V_190 ;
struct V_195 * V_196 = V_4 -> V_196 ? V_4 -> V_196 : V_189 -> V_196 ;
unsigned long V_155 = F_84 ( V_152 ) ;
unsigned V_156 ;
void * V_84 ;
bool V_198 = false ;
if ( V_4 -> V_30 == 0 && V_4 -> V_84 == NULL ) {
if ( ! F_45 ( V_4 -> type ) && ( V_4 -> V_74 & V_166 ) &&
( V_155 & ( V_162 | V_163 ) ) )
V_198 = true ;
else if ( F_45 ( V_4 -> type ) && ( V_4 -> V_74 & V_168 ) &&
( V_155 & ( V_164 | V_165 ) ) )
V_198 = true ;
}
F_90 ( V_198 && ! V_196 ) ;
if ( V_198 && V_196 && F_117 ( V_196 ) )
return V_167 ;
V_84 = V_4 -> V_84 ;
V_156 = F_82 ( V_189 -> V_190 , V_151 , V_152 ) ;
if ( V_198 && ! V_84 && V_4 -> V_84 )
V_4 -> V_191 = V_151 -> V_160 ;
if ( V_198 && V_196 )
F_118 ( V_196 ) ;
return V_156 ;
}
unsigned long F_121 ( struct V_151 * V_151 , unsigned long V_148 ,
unsigned long V_149 , unsigned long V_150 , unsigned long V_61 )
{
struct V_153 * V_189 = F_83 ( V_151 ) ;
return F_81 ( V_189 -> V_190 , V_148 , V_149 , V_150 , V_61 ) ;
}
void F_122 ( struct V_3 * V_199 )
{
F_118 ( V_199 -> V_196 ) ;
}
void F_123 ( struct V_3 * V_199 )
{
F_124 ( V_199 -> V_196 ) ;
}
