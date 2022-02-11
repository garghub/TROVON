static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_5 = F_2 ( V_4 , V_8 , V_4 -> V_9 [ V_6 ] ,
V_4 -> V_10 [ V_6 ] ) ;
if ( F_3 ( V_5 ) )
goto free;
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
V_2 -> V_12 [ V_6 ] . V_13 = V_4 -> V_10 [ V_6 ] ;
}
return 0 ;
free:
for (; V_6 > 0 ; -- V_6 ) {
F_2 ( V_4 , V_14 , V_2 -> V_11 [ V_6 - 1 ] . V_5 ) ;
V_2 -> V_11 [ V_6 - 1 ] . V_5 = NULL ;
}
return - V_15 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
F_2 ( V_4 , V_14 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
F_5 ( 3 , L_1 , V_6 ,
V_2 -> V_16 . V_17 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
}
}
static void F_7 ( struct V_3 * V_4 , struct V_19 * V_20 )
{
if ( ! V_20 -> V_5 )
return;
if ( V_20 -> V_21 )
F_2 ( V_4 , V_22 , V_20 -> V_5 ) ;
F_2 ( V_4 , V_23 , V_20 -> V_5 ) ;
F_8 ( V_20 -> V_24 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_7 ( V_4 , & V_2 -> V_11 [ V_6 ] ) ;
}
static void F_10 ( struct V_3 * V_4 , unsigned int V_25 )
{
unsigned int V_26 , V_6 ;
struct V_1 * V_2 ;
unsigned long V_27 ;
if ( V_4 -> V_28 ) {
struct V_29 * V_20 ;
V_2 = V_4 -> V_30 [ V_4 -> V_28 - 1 ] ;
V_20 = & V_2 -> V_12 [ V_2 -> V_7 - 1 ] ;
V_27 = F_11 ( V_20 -> V_31 . V_32 + V_20 -> V_13 ) ;
} else {
V_27 = 0 ;
}
for ( V_26 = V_4 -> V_28 ; V_26 < V_4 -> V_28 + V_25 ; ++ V_26 ) {
V_2 = V_4 -> V_30 [ V_26 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_2 -> V_12 [ V_6 ] . V_13 = V_4 -> V_10 [ V_6 ] ;
V_2 -> V_12 [ V_6 ] . V_31 . V_32 = V_27 ;
F_5 ( 3 , L_2 ,
V_26 , V_6 , V_27 ) ;
V_27 += V_2 -> V_12 [ V_6 ] . V_13 ;
V_27 = F_11 ( V_27 ) ;
}
}
}
static int F_12 ( struct V_3 * V_4 , enum V_33 V_34 ,
unsigned int V_28 , unsigned int V_7 )
{
unsigned int V_26 ;
struct V_1 * V_2 ;
int V_35 ;
for ( V_26 = 0 ; V_26 < V_28 ; ++ V_26 ) {
V_2 = F_13 ( V_4 -> V_36 , V_37 ) ;
if ( ! V_2 ) {
F_5 ( 1 , L_3 ) ;
break;
}
if ( F_14 ( V_4 -> type ) )
V_2 -> V_16 . V_13 = V_7 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_16 . V_17 = V_4 -> V_28 + V_26 ;
V_2 -> V_16 . type = V_4 -> type ;
V_2 -> V_16 . V_34 = V_34 ;
if ( V_34 == V_40 ) {
V_35 = F_1 ( V_2 ) ;
if ( V_35 ) {
F_5 ( 1 , L_4
L_5 , V_26 ) ;
F_15 ( V_2 ) ;
break;
}
V_35 = F_16 ( V_4 , V_41 , V_2 ) ;
if ( V_35 ) {
F_5 ( 1 , L_6
L_7 , V_26 , V_2 ) ;
F_4 ( V_2 ) ;
F_15 ( V_2 ) ;
break;
}
}
V_4 -> V_30 [ V_4 -> V_28 + V_26 ] = V_2 ;
}
F_10 ( V_4 , V_26 ) ;
F_5 ( 1 , L_8 ,
V_26 , V_7 ) ;
return V_26 ;
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_42 )
{
unsigned int V_26 ;
struct V_1 * V_2 ;
for ( V_26 = V_4 -> V_28 - V_42 ; V_26 < V_4 -> V_28 ;
++ V_26 ) {
V_2 = V_4 -> V_30 [ V_26 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_34 == V_40 )
F_4 ( V_2 ) ;
else if ( V_4 -> V_34 == V_43 )
F_9 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
}
static void F_18 ( struct V_3 * V_4 , unsigned int V_42 )
{
unsigned int V_26 ;
if ( V_4 -> V_44 -> V_45 ) {
for ( V_26 = V_4 -> V_28 - V_42 ; V_26 < V_4 -> V_28 ;
++ V_26 ) {
if ( NULL == V_4 -> V_30 [ V_26 ] )
continue;
V_4 -> V_44 -> V_45 ( V_4 -> V_30 [ V_26 ] ) ;
}
}
F_17 ( V_4 , V_42 ) ;
for ( V_26 = V_4 -> V_28 - V_42 ; V_26 < V_4 -> V_28 ;
++ V_26 ) {
F_15 ( V_4 -> V_30 [ V_26 ] ) ;
V_4 -> V_30 [ V_26 ] = NULL ;
}
V_4 -> V_28 -= V_42 ;
if ( ! V_4 -> V_28 )
V_4 -> V_34 = 0 ;
F_19 ( & V_4 -> V_46 ) ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
if ( ! F_14 ( V_48 -> type ) )
return 0 ;
if ( NULL == V_48 -> V_31 . V_11 ) {
F_5 ( 1 , L_9
L_10 ) ;
return - V_49 ;
}
if ( V_48 -> V_13 < V_2 -> V_7 || V_48 -> V_13 > V_50 ) {
F_5 ( 1 , L_11
L_12 , V_2 -> V_7 , V_48 -> V_13 ) ;
return - V_49 ;
}
return 0 ;
}
static bool F_21 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_11 [ V_6 ] . V_5 ;
if ( V_5 && F_2 ( V_4 , V_51 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_22 ( struct V_3 * V_4 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; ++ V_26 ) {
if ( F_21 ( V_4 , V_4 -> V_30 [ V_26 ] ) )
return true ;
}
return false ;
}
static void F_23 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_48 , & V_2 -> V_16 , F_24 ( struct V_47 , V_31 ) ) ;
V_48 -> V_52 = V_2 -> V_16 . V_52 ;
V_48 -> V_53 = V_2 -> V_16 . V_53 ;
if ( F_14 ( V_4 -> type ) ) {
V_48 -> V_13 = V_2 -> V_7 ;
memcpy ( V_48 -> V_31 . V_11 , V_2 -> V_12 ,
V_48 -> V_13 * sizeof( struct V_29 ) ) ;
} else {
V_48 -> V_13 = V_2 -> V_12 [ 0 ] . V_13 ;
V_48 -> V_54 = V_2 -> V_12 [ 0 ] . V_54 ;
if ( V_4 -> V_34 == V_40 )
V_48 -> V_31 . V_55 = V_2 -> V_12 [ 0 ] . V_31 . V_32 ;
else if ( V_4 -> V_34 == V_56 )
V_48 -> V_31 . V_57 = V_2 -> V_12 [ 0 ] . V_31 . V_57 ;
else if ( V_4 -> V_34 == V_43 )
V_48 -> V_31 . V_58 = V_2 -> V_12 [ 0 ] . V_31 . V_58 ;
}
V_48 -> V_59 &= ~ V_60 ;
switch ( V_2 -> V_38 ) {
case V_61 :
case V_62 :
V_48 -> V_59 |= V_63 ;
break;
case V_64 :
V_48 -> V_59 |= V_65 ;
case V_66 :
V_48 -> V_59 |= V_67 ;
break;
case V_68 :
V_48 -> V_59 |= V_69 ;
break;
case V_39 :
break;
}
if ( F_21 ( V_4 , V_2 ) )
V_48 -> V_59 |= V_70 ;
}
int F_25 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
struct V_1 * V_2 ;
int V_35 ;
if ( V_48 -> type != V_4 -> type ) {
F_5 ( 1 , L_13 ) ;
return - V_49 ;
}
if ( V_48 -> V_17 >= V_4 -> V_28 ) {
F_5 ( 1 , L_14 ) ;
return - V_49 ;
}
V_2 = V_4 -> V_30 [ V_48 -> V_17 ] ;
V_35 = F_20 ( V_2 , V_48 ) ;
if ( ! V_35 )
F_23 ( V_2 , V_48 ) ;
return V_35 ;
}
static int F_26 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_71 & V_72 ) || ! V_4 -> V_73 -> V_74 ||
! V_4 -> V_73 -> V_18 )
return - V_49 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_71 & V_75 ) || ! V_4 -> V_73 -> V_8 ||
! V_4 -> V_73 -> V_14 || ! V_4 -> V_73 -> V_76 )
return - V_49 ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_71 & V_77 ) || ! V_4 -> V_73 -> V_78 ||
! V_4 -> V_73 -> V_23 || ! V_4 -> V_73 -> V_79 ||
! V_4 -> V_73 -> V_22 )
return - V_49 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
enum V_33 V_34 , enum V_80 type )
{
if ( V_34 != V_40 && V_34 != V_56 &&
V_34 != V_43 ) {
F_5 ( 1 , L_15 ) ;
return - V_49 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_16 ) ;
return - V_49 ;
}
if ( V_34 == V_40 && F_27 ( V_4 ) ) {
F_5 ( 1 , L_17 ) ;
return - V_49 ;
}
if ( V_34 == V_56 && F_26 ( V_4 ) ) {
F_5 ( 1 , L_18 ) ;
return - V_49 ;
}
if ( V_34 == V_43 && F_28 ( V_4 ) ) {
F_5 ( 1 , L_19 ) ;
return - V_49 ;
}
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_20 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_83 * V_84 )
{
unsigned int V_28 , V_85 , V_7 = 0 ;
int V_35 ;
if ( V_4 -> V_86 ) {
F_5 ( 1 , L_21 ) ;
return - V_82 ;
}
if ( V_84 -> V_87 == 0 || V_4 -> V_28 != 0 || V_4 -> V_34 != V_84 -> V_34 ) {
if ( V_4 -> V_34 == V_40 && F_22 ( V_4 ) ) {
F_5 ( 1 , L_22 ) ;
return - V_82 ;
}
F_18 ( V_4 , V_4 -> V_28 ) ;
if ( V_84 -> V_87 == 0 )
return 0 ;
}
V_28 = F_31 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_34 = V_84 -> V_34 ;
V_35 = F_16 ( V_4 , V_88 , V_4 , NULL , & V_28 , & V_7 ,
V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_12 ( V_4 , V_84 -> V_34 , V_28 , V_7 ) ;
if ( V_35 == 0 ) {
F_5 ( 1 , L_23 ) ;
return - V_15 ;
}
V_85 = V_35 ;
if ( V_85 < V_28 ) {
V_28 = V_85 ;
V_35 = F_16 ( V_4 , V_88 , V_4 , NULL , & V_28 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_35 && V_85 < V_28 )
V_35 = - V_15 ;
}
V_4 -> V_28 = V_85 ;
if ( V_35 < 0 ) {
F_18 ( V_4 , V_85 ) ;
return V_35 ;
}
V_84 -> V_87 = V_85 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 , struct V_83 * V_84 )
{
int V_35 = F_29 ( V_4 , V_84 -> V_34 , V_84 -> type ) ;
return V_35 ? V_35 : F_30 ( V_4 , V_84 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
unsigned int V_7 = 0 , V_28 , V_85 ;
int V_35 ;
if ( V_4 -> V_28 == V_91 ) {
F_5 ( 1 , L_24 ,
V_92 ) ;
return - V_93 ;
}
if ( ! V_4 -> V_28 ) {
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_34 = V_90 -> V_34 ;
}
V_28 = F_34 ( V_90 -> V_87 , V_91 - V_4 -> V_28 ) ;
V_35 = F_16 ( V_4 , V_88 , V_4 , & V_90 -> V_94 , & V_28 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_12 ( V_4 , V_90 -> V_34 , V_28 ,
V_7 ) ;
if ( V_35 == 0 ) {
F_5 ( 1 , L_23 ) ;
return - V_15 ;
}
V_85 = V_35 ;
if ( V_35 < V_28 ) {
V_28 = V_35 ;
V_35 = F_16 ( V_4 , V_88 , V_4 , & V_90 -> V_94 , & V_28 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_35 && V_85 < V_28 )
V_35 = - V_15 ;
}
V_4 -> V_28 += V_85 ;
if ( V_35 < 0 ) {
F_18 ( V_4 , V_85 ) ;
return - V_15 ;
}
V_90 -> V_87 = V_85 ;
return 0 ;
}
int F_35 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
int V_35 = F_29 ( V_4 , V_90 -> V_34 , V_90 -> V_94 . type ) ;
V_90 -> V_17 = V_4 -> V_28 ;
if ( V_90 -> V_87 == 0 )
return V_35 != - V_82 ? V_35 : 0 ;
return V_35 ? V_35 : F_33 ( V_4 , V_90 ) ;
}
void * F_36 ( struct V_1 * V_2 , unsigned int V_95 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_95 > V_2 -> V_7 || ! V_2 -> V_11 [ V_95 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_96 , V_2 -> V_11 [ V_95 ] . V_5 ) ;
}
void * F_37 ( struct V_1 * V_2 , unsigned int V_95 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_95 > V_2 -> V_7 || ! V_2 -> V_11 [ V_95 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_97 , V_2 -> V_11 [ V_95 ] . V_5 ) ;
}
void F_38 ( struct V_1 * V_2 , enum V_98 V_38 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_59 ;
unsigned int V_6 ;
if ( V_2 -> V_38 != V_62 )
return;
if ( V_38 != V_66 && V_38 != V_64 )
return;
F_5 ( 4 , L_25 ,
V_2 -> V_16 . V_17 , V_2 -> V_38 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_2 ( V_4 , V_99 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
F_39 ( & V_4 -> V_100 , V_59 ) ;
V_2 -> V_38 = V_38 ;
F_40 ( & V_2 -> V_101 , & V_4 -> V_102 ) ;
F_41 ( & V_4 -> V_103 ) ;
F_42 ( & V_4 -> V_100 , V_59 ) ;
F_43 ( & V_4 -> V_104 ) ;
}
static void F_44 ( struct V_1 * V_2 , const struct V_47 * V_48 ,
struct V_29 * V_12 )
{
unsigned int V_6 ;
if ( F_14 ( V_48 -> type ) ) {
if ( F_45 ( V_48 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_54 =
V_48 -> V_31 . V_11 [ V_6 ] . V_54 ;
V_12 [ V_6 ] . V_105 =
V_48 -> V_31 . V_11 [ V_6 ] . V_105 ;
}
}
if ( V_48 -> V_34 == V_56 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_31 . V_57 =
V_48 -> V_31 . V_11 [ V_6 ] . V_31 . V_57 ;
V_12 [ V_6 ] . V_13 =
V_48 -> V_31 . V_11 [ V_6 ] . V_13 ;
}
}
if ( V_48 -> V_34 == V_43 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_31 . V_58 =
V_48 -> V_31 . V_11 [ V_6 ] . V_31 . V_58 ;
V_12 [ V_6 ] . V_13 =
V_48 -> V_31 . V_11 [ V_6 ] . V_13 ;
V_12 [ V_6 ] . V_105 =
V_48 -> V_31 . V_11 [ V_6 ] . V_105 ;
}
}
} else {
if ( F_45 ( V_48 -> type ) ) {
V_12 [ 0 ] . V_54 = V_48 -> V_54 ;
V_12 [ 0 ] . V_105 = 0 ;
}
if ( V_48 -> V_34 == V_56 ) {
V_12 [ 0 ] . V_31 . V_57 = V_48 -> V_31 . V_57 ;
V_12 [ 0 ] . V_13 = V_48 -> V_13 ;
}
if ( V_48 -> V_34 == V_43 ) {
V_12 [ 0 ] . V_31 . V_58 = V_48 -> V_31 . V_58 ;
V_12 [ 0 ] . V_13 = V_48 -> V_13 ;
V_12 [ 0 ] . V_105 = 0 ;
}
}
V_2 -> V_16 . V_106 = V_48 -> V_106 ;
V_2 -> V_16 . V_107 = V_48 -> V_107 ;
V_2 -> V_16 . V_59 = V_48 -> V_59 & ~ V_60 ;
}
static int F_46 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
struct V_29 V_11 [ V_50 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_35 ;
int V_108 = ! F_45 ( V_4 -> type ) ;
F_44 ( V_2 , V_48 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_6 ] . V_31 . V_57 &&
V_2 -> V_12 [ V_6 ] . V_31 . V_57 == V_11 [ V_6 ] . V_31 . V_57
&& V_2 -> V_12 [ V_6 ] . V_13 == V_11 [ V_6 ] . V_13 )
continue;
F_5 ( 3 , L_26
L_27 , V_6 ) ;
if ( V_11 [ V_6 ] . V_13 < V_4 -> V_10 [ V_6 ] ) {
V_35 = - V_49 ;
goto V_109;
}
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_31 . V_57 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
V_5 = F_2 ( V_4 , V_74 , V_4 -> V_9 [ V_6 ] ,
V_11 [ V_6 ] . V_31 . V_57 ,
V_11 [ V_6 ] . V_13 , V_108 ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( 1 , L_28
L_29 , V_6 ) ;
V_35 = V_5 ? F_47 ( V_5 ) : - V_49 ;
goto V_109;
}
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
V_35 = F_16 ( V_4 , V_41 , V_2 ) ;
if ( V_35 ) {
F_5 ( 1 , L_30 ) ;
goto V_109;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_12 [ V_6 ] = V_11 [ V_6 ] ;
return 0 ;
V_109:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_31 . V_57 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
}
return V_35 ;
}
static int F_48 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
F_44 ( V_2 , V_48 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
struct V_29 V_11 [ V_50 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_35 ;
int V_108 = ! F_45 ( V_4 -> type ) ;
F_44 ( V_2 , V_48 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
struct V_110 * V_24 = F_50 ( V_11 [ V_6 ] . V_31 . V_58 ) ;
if ( F_3 ( V_24 ) ) {
F_5 ( 1 , L_31 ,
V_6 ) ;
V_35 = - V_49 ;
goto V_109;
}
if ( V_11 [ V_6 ] . V_13 == 0 )
V_11 [ V_6 ] . V_13 = V_24 -> V_111 ;
if ( V_11 [ V_6 ] . V_13 < V_11 [ V_6 ] . V_105 +
V_4 -> V_10 [ V_6 ] ) {
V_35 = - V_49 ;
goto V_109;
}
if ( V_24 == V_2 -> V_11 [ V_6 ] . V_24 &&
V_2 -> V_12 [ V_6 ] . V_13 == V_11 [ V_6 ] . V_13 ) {
F_8 ( V_24 ) ;
continue;
}
F_5 ( 1 , L_32 , V_6 ) ;
F_7 ( V_4 , & V_2 -> V_11 [ V_6 ] ) ;
memset ( & V_2 -> V_12 [ V_6 ] , 0 , sizeof( struct V_29 ) ) ;
V_5 = F_2 ( V_4 , V_78 , V_4 -> V_9 [ V_6 ] ,
V_24 , V_11 [ V_6 ] . V_13 , V_108 ) ;
if ( F_51 ( V_5 ) ) {
F_5 ( 1 , L_33 ) ;
V_35 = F_47 ( V_5 ) ;
F_8 ( V_24 ) ;
goto V_109;
}
V_2 -> V_11 [ V_6 ] . V_24 = V_24 ;
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_35 = F_2 ( V_4 , V_79 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
if ( V_35 ) {
F_5 ( 1 , L_34 ,
V_6 ) ;
goto V_109;
}
V_2 -> V_11 [ V_6 ] . V_21 = 1 ;
}
V_35 = F_16 ( V_4 , V_41 , V_2 ) ;
if ( V_35 ) {
F_5 ( 1 , L_30 ) ;
goto V_109;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_12 [ V_6 ] = V_11 [ V_6 ] ;
return 0 ;
V_109:
F_9 ( V_2 ) ;
return V_35 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_6 ;
V_2 -> V_38 = V_62 ;
F_53 ( & V_4 -> V_103 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
F_2 ( V_4 , V_112 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_4 -> V_44 -> V_113 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_35 ;
switch ( V_4 -> V_34 ) {
case V_40 :
V_35 = F_48 ( V_2 , V_48 ) ;
break;
case V_56 :
V_35 = F_46 ( V_2 , V_48 ) ;
break;
case V_43 :
V_35 = F_49 ( V_2 , V_48 ) ;
break;
default:
F_55 ( 1 , L_35 ) ;
V_35 = - V_49 ;
}
if ( ! V_35 )
V_35 = F_16 ( V_4 , V_114 , V_2 ) ;
if ( V_35 )
F_5 ( 1 , L_36 , V_35 ) ;
else
V_2 -> V_38 = V_68 ;
return V_35 ;
}
int F_56 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
struct V_1 * V_2 ;
int V_35 ;
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_37 , V_92 ) ;
return - V_82 ;
}
if ( V_48 -> type != V_4 -> type ) {
F_5 ( 1 , L_38 , V_92 ) ;
return - V_49 ;
}
if ( V_48 -> V_17 >= V_4 -> V_28 ) {
F_5 ( 1 , L_39 , V_92 ) ;
return - V_49 ;
}
V_2 = V_4 -> V_30 [ V_48 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_40 , V_92 ) ;
return - V_49 ;
}
if ( V_48 -> V_34 != V_4 -> V_34 ) {
F_5 ( 1 , L_41 , V_92 ) ;
return - V_49 ;
}
if ( V_2 -> V_38 != V_39 ) {
F_5 ( 1 , L_42 , V_92 , V_2 -> V_38 ) ;
return - V_49 ;
}
V_35 = F_20 ( V_2 , V_48 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_54 ( V_2 , V_48 ) ;
if ( V_35 < 0 )
return V_35 ;
F_23 ( V_2 , V_48 ) ;
return 0 ;
}
int F_57 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
struct V_115 * V_116 = NULL ;
struct V_1 * V_2 ;
int V_35 = 0 ;
if ( V_4 -> V_34 == V_56 ) {
V_116 = & V_117 -> V_118 -> V_116 ;
F_16 ( V_4 , V_119 , V_4 ) ;
F_58 ( V_116 ) ;
F_16 ( V_4 , V_120 , V_4 ) ;
}
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_43 ) ;
V_35 = - V_82 ;
goto V_121;
}
if ( V_48 -> type != V_4 -> type ) {
F_5 ( 1 , L_44 ) ;
V_35 = - V_49 ;
goto V_121;
}
if ( V_48 -> V_17 >= V_4 -> V_28 ) {
F_5 ( 1 , L_45 ) ;
V_35 = - V_49 ;
goto V_121;
}
V_2 = V_4 -> V_30 [ V_48 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_46 ) ;
V_35 = - V_49 ;
goto V_121;
}
if ( V_48 -> V_34 != V_4 -> V_34 ) {
F_5 ( 1 , L_47 ) ;
V_35 = - V_49 ;
goto V_121;
}
V_35 = F_20 ( V_2 , V_48 ) ;
if ( V_35 )
goto V_121;
switch ( V_2 -> V_38 ) {
case V_39 :
V_35 = F_54 ( V_2 , V_48 ) ;
if ( V_35 )
goto V_121;
case V_68 :
break;
default:
F_5 ( 1 , L_48 ) ;
V_35 = - V_49 ;
goto V_121;
}
F_40 ( & V_2 -> V_122 , & V_4 -> V_46 ) ;
V_2 -> V_38 = V_61 ;
if ( V_4 -> V_86 )
F_52 ( V_2 ) ;
F_23 ( V_2 , V_48 ) ;
F_5 ( 1 , L_49 , V_2 -> V_16 . V_17 ) ;
V_121:
if ( V_116 )
F_59 ( V_116 ) ;
return V_35 ;
}
static int F_60 ( struct V_3 * V_4 , int V_123 )
{
for (; ; ) {
int V_35 ;
if ( ! V_4 -> V_86 ) {
F_5 ( 1 , L_50 ) ;
return - V_49 ;
}
if ( ! F_61 ( & V_4 -> V_102 ) ) {
break;
}
if ( V_123 ) {
F_5 ( 1 , L_51
L_52 ) ;
return - V_124 ;
}
F_16 ( V_4 , V_119 , V_4 ) ;
F_5 ( 3 , L_53 ) ;
V_35 = F_62 ( V_4 -> V_104 ,
! F_61 ( & V_4 -> V_102 ) || ! V_4 -> V_86 ) ;
F_16 ( V_4 , V_120 , V_4 ) ;
if ( V_35 ) {
F_5 ( 1 , L_54 ) ;
return V_35 ;
}
}
return 0 ;
}
static int F_63 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_47 * V_48 , int V_123 )
{
unsigned long V_59 ;
int V_35 ;
V_35 = F_60 ( V_4 , V_123 ) ;
if ( V_35 )
return V_35 ;
F_39 ( & V_4 -> V_100 , V_59 ) ;
* V_2 = F_64 ( & V_4 -> V_102 , struct V_1 , V_101 ) ;
V_35 = F_20 ( * V_2 , V_48 ) ;
if ( ! V_35 )
F_65 ( & ( * V_2 ) -> V_101 ) ;
F_42 ( & V_4 -> V_100 , V_59 ) ;
return V_35 ;
}
int F_66 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_86 ) {
F_5 ( 1 , L_50 ) ;
return - V_49 ;
}
F_67 ( V_4 -> V_104 , ! F_68 ( & V_4 -> V_103 ) ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned int V_125 ;
if ( V_2 -> V_38 == V_39 )
return;
V_2 -> V_38 = V_39 ;
if ( V_4 -> V_34 == V_43 )
for ( V_125 = 0 ; V_125 < V_2 -> V_7 ; ++ V_125 ) {
if ( ! V_2 -> V_11 [ V_125 ] . V_21 )
continue;
F_2 ( V_4 , V_22 , V_2 -> V_11 [ V_125 ] . V_5 ) ;
V_2 -> V_11 [ V_125 ] . V_21 = 0 ;
}
}
int F_70 ( struct V_3 * V_4 , struct V_47 * V_48 , bool V_123 )
{
struct V_1 * V_2 = NULL ;
int V_35 ;
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_55 ) ;
return - V_82 ;
}
if ( V_48 -> type != V_4 -> type ) {
F_5 ( 1 , L_56 ) ;
return - V_49 ;
}
V_35 = F_63 ( V_4 , & V_2 , V_48 , V_123 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_16 ( V_4 , V_126 , V_2 ) ;
if ( V_35 ) {
F_5 ( 1 , L_57 ) ;
return V_35 ;
}
switch ( V_2 -> V_38 ) {
case V_66 :
F_5 ( 3 , L_58 ) ;
break;
case V_64 :
F_5 ( 3 , L_59 ) ;
break;
default:
F_5 ( 1 , L_60 ) ;
return - V_49 ;
}
F_23 ( V_2 , V_48 ) ;
F_65 ( & V_2 -> V_122 ) ;
F_69 ( V_2 ) ;
F_5 ( 1 , L_61 ,
V_2 -> V_16 . V_17 , V_2 -> V_38 ) ;
return 0 ;
}
static void F_71 ( struct V_3 * V_4 )
{
unsigned int V_125 ;
if ( V_4 -> V_86 )
F_16 ( V_4 , V_127 , V_4 ) ;
V_4 -> V_86 = 0 ;
F_19 ( & V_4 -> V_46 ) ;
F_19 ( & V_4 -> V_102 ) ;
F_72 ( & V_4 -> V_103 , 0 ) ;
F_73 ( & V_4 -> V_104 ) ;
for ( V_125 = 0 ; V_125 < V_4 -> V_28 ; ++ V_125 )
F_69 ( V_4 -> V_30 [ V_125 ] ) ;
}
int F_74 ( struct V_3 * V_4 , enum V_80 type )
{
struct V_1 * V_2 ;
int V_35 ;
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_62 ) ;
return - V_82 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_63 ) ;
return - V_49 ;
}
if ( V_4 -> V_86 ) {
F_5 ( 1 , L_64 ) ;
return - V_82 ;
}
F_75 (vb, &q->queued_list, queued_entry)
F_52 ( V_2 ) ;
V_35 = F_16 ( V_4 , V_128 , V_4 , F_68 ( & V_4 -> V_103 ) ) ;
if ( V_35 ) {
F_5 ( 1 , L_65 ) ;
F_71 ( V_4 ) ;
return V_35 ;
}
V_4 -> V_86 = 1 ;
F_5 ( 3 , L_66 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 , enum V_80 type )
{
if ( V_4 -> V_81 ) {
F_5 ( 1 , L_67 ) ;
return - V_82 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_68 ) ;
return - V_49 ;
}
if ( ! V_4 -> V_86 ) {
F_5 ( 1 , L_69 ) ;
return - V_49 ;
}
F_71 ( V_4 ) ;
F_5 ( 3 , L_70 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 , unsigned long V_27 ,
unsigned int * V_129 , unsigned int * V_130 )
{
struct V_1 * V_2 ;
unsigned int V_26 , V_6 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; ++ V_26 ) {
V_2 = V_4 -> V_30 [ V_26 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_6 ] . V_31 . V_32 == V_27 ) {
* V_129 = V_26 ;
* V_130 = V_6 ;
return 0 ;
}
}
}
return - V_49 ;
}
int F_78 ( struct V_3 * V_4 , struct V_131 * V_132 )
{
struct V_1 * V_2 = NULL ;
struct V_19 * V_133 ;
int V_35 ;
struct V_110 * V_24 ;
if ( V_4 -> V_34 != V_40 ) {
F_5 ( 1 , L_71 ) ;
return - V_49 ;
}
if ( ! V_4 -> V_73 -> V_134 ) {
F_5 ( 1 , L_72 ) ;
return - V_49 ;
}
if ( V_132 -> V_59 & ~ V_135 ) {
F_5 ( 1 , L_73 ) ;
return - V_49 ;
}
if ( V_132 -> type != V_4 -> type ) {
F_5 ( 1 , L_44 ) ;
return - V_49 ;
}
if ( V_132 -> V_17 >= V_4 -> V_28 ) {
F_5 ( 1 , L_74 ) ;
return - V_49 ;
}
V_2 = V_4 -> V_30 [ V_132 -> V_17 ] ;
if ( V_132 -> V_6 >= V_2 -> V_7 ) {
F_5 ( 1 , L_75 ) ;
return - V_49 ;
}
V_133 = & V_2 -> V_11 [ V_132 -> V_6 ] ;
V_24 = F_2 ( V_4 , V_134 , V_133 -> V_5 ) ;
if ( F_3 ( V_24 ) ) {
F_5 ( 1 , L_76 ,
V_132 -> V_17 , V_132 -> V_6 ) ;
return - V_49 ;
}
V_35 = F_79 ( V_24 , V_132 -> V_59 ) ;
if ( V_35 < 0 ) {
F_5 ( 3 , L_77 ,
V_132 -> V_17 , V_132 -> V_6 , V_35 ) ;
F_8 ( V_24 ) ;
return V_35 ;
}
F_5 ( 3 , L_78 ,
V_132 -> V_17 , V_132 -> V_6 , V_35 ) ;
V_132 -> V_58 = V_35 ;
return 0 ;
}
int F_80 ( struct V_3 * V_4 , struct V_136 * V_137 )
{
unsigned long V_27 = V_137 -> V_138 << V_139 ;
struct V_1 * V_2 ;
unsigned int V_26 , V_6 ;
int V_35 ;
if ( V_4 -> V_34 != V_40 ) {
F_5 ( 1 , L_71 ) ;
return - V_49 ;
}
if ( ! ( V_137 -> V_140 & V_141 ) ) {
F_5 ( 1 , L_79 ) ;
return - V_49 ;
}
if ( F_45 ( V_4 -> type ) ) {
if ( ! ( V_137 -> V_140 & V_142 ) ) {
F_5 ( 1 , L_80 ) ;
return - V_49 ;
}
} else {
if ( ! ( V_137 -> V_140 & V_143 ) ) {
F_5 ( 1 , L_81 ) ;
return - V_49 ;
}
}
V_35 = F_77 ( V_4 , V_27 , & V_26 , & V_6 ) ;
if ( V_35 )
return V_35 ;
V_2 = V_4 -> V_30 [ V_26 ] ;
V_35 = F_2 ( V_4 , V_76 , V_2 -> V_11 [ V_6 ] . V_5 , V_137 ) ;
if ( V_35 )
return V_35 ;
F_5 ( 3 , L_82 , V_26 , V_6 ) ;
return 0 ;
}
unsigned long F_81 ( struct V_3 * V_4 ,
unsigned long V_144 ,
unsigned long V_145 ,
unsigned long V_146 ,
unsigned long V_59 )
{
unsigned long V_27 = V_146 << V_139 ;
struct V_1 * V_2 ;
unsigned int V_26 , V_6 ;
int V_35 ;
if ( V_4 -> V_34 != V_40 ) {
F_5 ( 1 , L_71 ) ;
return - V_49 ;
}
V_35 = F_77 ( V_4 , V_27 , & V_26 , & V_6 ) ;
if ( V_35 )
return V_35 ;
V_2 = V_4 -> V_30 [ V_26 ] ;
return ( unsigned long ) F_36 ( V_2 , V_6 ) ;
}
unsigned int F_82 ( struct V_3 * V_4 , struct V_147 * V_147 , T_1 * V_148 )
{
struct V_149 * V_150 = F_83 ( V_147 ) ;
unsigned long V_151 = F_84 ( V_148 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_152 = 0 ;
unsigned long V_59 ;
if ( F_85 ( V_153 , & V_150 -> V_59 ) ) {
struct V_154 * V_155 = V_147 -> V_156 ;
if ( F_86 ( V_155 ) )
V_152 = V_157 ;
else if ( V_151 & V_157 )
F_87 ( V_147 , & V_155 -> V_148 , V_148 ) ;
}
if ( V_4 -> V_28 == 0 && V_4 -> V_81 == NULL ) {
if ( ! F_45 ( V_4 -> type ) && ( V_4 -> V_71 & V_158 ) &&
( V_151 & ( V_159 | V_160 ) ) ) {
if ( F_88 ( V_4 , 1 ) )
return V_152 | V_161 ;
}
if ( F_45 ( V_4 -> type ) && ( V_4 -> V_71 & V_162 ) &&
( V_151 & ( V_163 | V_164 ) ) ) {
if ( F_88 ( V_4 , 0 ) )
return V_152 | V_161 ;
return V_152 | V_163 | V_164 ;
}
}
if ( F_61 ( & V_4 -> V_46 ) )
return V_152 | V_161 ;
F_87 ( V_147 , & V_4 -> V_104 , V_148 ) ;
F_39 ( & V_4 -> V_100 , V_59 ) ;
if ( ! F_61 ( & V_4 -> V_102 ) )
V_2 = F_64 ( & V_4 -> V_102 , struct V_1 ,
V_101 ) ;
F_42 ( & V_4 -> V_100 , V_59 ) ;
if ( V_2 && ( V_2 -> V_38 == V_66
|| V_2 -> V_38 == V_64 ) ) {
return ( F_45 ( V_4 -> type ) ) ?
V_152 | V_163 | V_164 :
V_152 | V_159 | V_160 ;
}
return V_152 ;
}
int F_89 ( struct V_3 * V_4 )
{
if ( F_90 ( ! V_4 ) ||
F_90 ( ! V_4 -> V_44 ) ||
F_90 ( ! V_4 -> V_73 ) ||
F_90 ( ! V_4 -> type ) ||
F_90 ( ! V_4 -> V_71 ) ||
F_90 ( ! V_4 -> V_44 -> V_88 ) ||
F_90 ( ! V_4 -> V_44 -> V_113 ) )
return - V_49 ;
F_19 ( & V_4 -> V_46 ) ;
F_19 ( & V_4 -> V_102 ) ;
F_91 ( & V_4 -> V_100 ) ;
F_92 ( & V_4 -> V_104 ) ;
if ( V_4 -> V_36 == 0 )
V_4 -> V_36 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_93 ( struct V_3 * V_4 )
{
F_94 ( V_4 ) ;
F_71 ( V_4 ) ;
F_18 ( V_4 , V_4 -> V_28 ) ;
}
static int F_88 ( struct V_3 * V_4 , int V_165 )
{
struct V_166 * V_81 ;
int V_125 , V_35 ;
unsigned int V_87 = 0 ;
if ( ( V_165 && ! ( V_4 -> V_71 & V_158 ) ) ||
( ! V_165 && ! ( V_4 -> V_71 & V_162 ) ) )
F_95 () ;
if ( ! V_4 -> V_73 -> V_96 )
return - V_82 ;
if ( V_4 -> V_86 || V_4 -> V_28 > 0 )
return - V_82 ;
V_87 = 1 ;
F_5 ( 3 , L_83 ,
( V_165 ) ? L_84 : L_85 , V_87 , V_4 -> V_167 ) ;
V_81 = F_13 ( sizeof( struct V_166 ) , V_37 ) ;
if ( V_81 == NULL )
return - V_15 ;
V_81 -> V_59 = V_4 -> V_167 ;
V_81 -> V_84 . V_87 = V_87 ;
V_81 -> V_84 . V_34 = V_40 ;
V_81 -> V_84 . type = V_4 -> type ;
V_35 = F_32 ( V_4 , & V_81 -> V_84 ) ;
if ( V_35 )
goto V_168;
if ( V_4 -> V_30 [ 0 ] -> V_7 != 1 ) {
V_35 = - V_82 ;
goto V_169;
}
for ( V_125 = 0 ; V_125 < V_4 -> V_28 ; V_125 ++ ) {
V_81 -> V_30 [ V_125 ] . V_96 = F_36 ( V_4 -> V_30 [ V_125 ] , 0 ) ;
if ( V_81 -> V_30 [ V_125 ] . V_96 == NULL )
goto V_169;
V_81 -> V_30 [ V_125 ] . V_111 = F_96 ( V_4 -> V_30 [ V_125 ] , 0 ) ;
}
if ( V_165 ) {
for ( V_125 = 0 ; V_125 < V_4 -> V_28 ; V_125 ++ ) {
struct V_47 * V_48 = & V_81 -> V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> type = V_4 -> type ;
V_48 -> V_34 = V_4 -> V_34 ;
V_48 -> V_17 = V_125 ;
V_35 = F_57 ( V_4 , V_48 ) ;
if ( V_35 )
goto V_169;
V_81 -> V_30 [ V_125 ] . V_170 = 1 ;
}
V_35 = F_74 ( V_4 , V_4 -> type ) ;
if ( V_35 )
goto V_169;
}
V_4 -> V_81 = V_81 ;
return V_35 ;
V_169:
V_81 -> V_84 . V_87 = 0 ;
F_32 ( V_4 , & V_81 -> V_84 ) ;
V_168:
F_15 ( V_81 ) ;
return V_35 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_166 * V_81 = V_4 -> V_81 ;
if ( V_81 ) {
V_4 -> V_81 = NULL ;
F_76 ( V_4 , V_4 -> type ) ;
V_81 -> V_84 . V_87 = 0 ;
F_32 ( V_4 , & V_81 -> V_84 ) ;
F_15 ( V_81 ) ;
F_5 ( 3 , L_86 ) ;
}
return 0 ;
}
static T_2 F_97 ( struct V_3 * V_4 , char T_3 * V_171 , T_2 V_87 ,
T_4 * V_172 , int V_173 , int V_165 )
{
struct V_166 * V_81 ;
struct V_174 * V_175 ;
int V_35 , V_17 ;
F_5 ( 3 , L_87 ,
V_165 ? L_84 : L_85 , ( long ) * V_172 , V_87 ,
V_173 ? L_88 : L_89 ) ;
if ( ! V_171 )
return - V_49 ;
if ( ! V_4 -> V_81 ) {
V_35 = F_88 ( V_4 , V_165 ) ;
F_5 ( 3 , L_90 , V_35 ) ;
if ( V_35 )
return V_35 ;
}
V_81 = V_4 -> V_81 ;
V_4 -> V_81 = NULL ;
V_17 = V_81 -> V_17 ;
V_175 = & V_81 -> V_30 [ V_17 ] ;
if ( V_175 -> V_170 ) {
struct V_1 * V_2 ;
memset ( & V_81 -> V_48 , 0 , sizeof( V_81 -> V_48 ) ) ;
V_81 -> V_48 . type = V_4 -> type ;
V_81 -> V_48 . V_34 = V_4 -> V_34 ;
V_81 -> V_48 . V_17 = V_17 ;
V_35 = F_70 ( V_4 , & V_81 -> V_48 , V_173 ) ;
F_5 ( 5 , L_91 , V_35 ) ;
if ( V_35 )
goto V_176;
V_81 -> V_177 += 1 ;
V_2 = V_4 -> V_30 [ V_17 ] ;
V_175 -> V_111 = F_98 ( V_2 , 0 ) ;
V_175 -> V_170 = 0 ;
}
if ( V_175 -> V_178 + V_87 > V_175 -> V_111 ) {
V_87 = V_175 -> V_111 - V_175 -> V_178 ;
F_5 ( 5 , L_92 , V_87 ) ;
}
F_5 ( 3 , L_93 ,
V_87 , V_17 , V_175 -> V_178 ) ;
if ( V_165 )
V_35 = F_99 ( V_171 , V_175 -> V_96 + V_175 -> V_178 , V_87 ) ;
else
V_35 = F_100 ( V_175 -> V_96 + V_175 -> V_178 , V_171 , V_87 ) ;
if ( V_35 ) {
F_5 ( 3 , L_94 ) ;
V_35 = - V_179 ;
goto V_176;
}
V_175 -> V_178 += V_87 ;
* V_172 += V_87 ;
if ( V_175 -> V_178 == V_175 -> V_111 ||
( ! V_165 && ( V_81 -> V_59 & V_180 ) ) ) {
if ( V_165 && ( V_81 -> V_59 & V_181 ) &&
V_81 -> V_177 == 1 ) {
F_5 ( 3 , L_95 ) ;
V_4 -> V_81 = V_81 ;
return F_94 ( V_4 ) ;
}
memset ( & V_81 -> V_48 , 0 , sizeof( V_81 -> V_48 ) ) ;
V_81 -> V_48 . type = V_4 -> type ;
V_81 -> V_48 . V_34 = V_4 -> V_34 ;
V_81 -> V_48 . V_17 = V_17 ;
V_81 -> V_48 . V_54 = V_175 -> V_178 ;
V_35 = F_57 ( V_4 , & V_81 -> V_48 ) ;
F_5 ( 5 , L_96 , V_35 ) ;
if ( V_35 )
goto V_176;
V_175 -> V_178 = 0 ;
V_175 -> V_170 = 1 ;
V_175 -> V_111 = V_4 -> V_30 [ 0 ] -> V_12 [ 0 ] . V_13 ;
V_81 -> V_182 += 1 ;
V_81 -> V_17 = ( V_17 + 1 ) % V_4 -> V_28 ;
if ( ! V_165 && ! V_4 -> V_86 ) {
V_35 = F_74 ( V_4 , V_4 -> type ) ;
if ( V_35 )
goto V_176;
}
}
if ( V_35 == 0 )
V_35 = V_87 ;
V_176:
V_4 -> V_81 = V_81 ;
return V_35 ;
}
T_2 F_101 ( struct V_3 * V_4 , char T_3 * V_171 , T_2 V_87 ,
T_4 * V_172 , int V_123 )
{
return F_97 ( V_4 , V_171 , V_87 , V_172 , V_123 , 1 ) ;
}
T_2 F_102 ( struct V_3 * V_4 , char T_3 * V_171 , T_2 V_87 ,
T_4 * V_172 , int V_123 )
{
return F_97 ( V_4 , V_171 , V_87 , V_172 , V_123 , 0 ) ;
}
static inline bool F_103 ( struct V_149 * V_183 , struct V_147 * V_147 )
{
return V_183 -> V_184 -> V_185 && V_183 -> V_184 -> V_185 != V_147 -> V_156 ;
}
int F_104 ( struct V_147 * V_147 , void * V_186 ,
struct V_83 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
int V_152 = F_29 ( V_183 -> V_184 , V_20 -> V_34 , V_20 -> type ) ;
if ( V_152 )
return V_152 ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
V_152 = F_30 ( V_183 -> V_184 , V_20 ) ;
if ( V_152 == 0 )
V_183 -> V_184 -> V_185 = V_20 -> V_87 ? V_147 -> V_156 : NULL ;
return V_152 ;
}
int F_105 ( struct V_147 * V_147 , void * V_186 ,
struct V_89 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
int V_152 = F_29 ( V_183 -> V_184 , V_20 -> V_34 , V_20 -> V_94 . type ) ;
V_20 -> V_17 = V_183 -> V_184 -> V_28 ;
if ( V_20 -> V_87 == 0 )
return V_152 != - V_82 ? V_152 : 0 ;
if ( V_152 )
return V_152 ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
V_152 = F_33 ( V_183 -> V_184 , V_20 ) ;
if ( V_152 == 0 )
V_183 -> V_184 -> V_185 = V_147 -> V_156 ;
return V_152 ;
}
int F_106 ( struct V_147 * V_147 , void * V_186 ,
struct V_47 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_56 ( V_183 -> V_184 , V_20 ) ;
}
int F_107 ( struct V_147 * V_147 , void * V_186 , struct V_47 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
return F_25 ( V_183 -> V_184 , V_20 ) ;
}
int F_108 ( struct V_147 * V_147 , void * V_186 , struct V_47 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_57 ( V_183 -> V_184 , V_20 ) ;
}
int F_109 ( struct V_147 * V_147 , void * V_186 , struct V_47 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_70 ( V_183 -> V_184 , V_20 , V_147 -> V_187 & V_188 ) ;
}
int F_110 ( struct V_147 * V_147 , void * V_186 , enum V_80 V_125 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_74 ( V_183 -> V_184 , V_125 ) ;
}
int F_111 ( struct V_147 * V_147 , void * V_186 , enum V_80 V_125 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_76 ( V_183 -> V_184 , V_125 ) ;
}
int F_112 ( struct V_147 * V_147 , void * V_186 , struct V_131 * V_20 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( F_103 ( V_183 , V_147 ) )
return - V_82 ;
return F_78 ( V_183 -> V_184 , V_20 ) ;
}
int F_113 ( struct V_147 * V_147 , struct V_136 * V_137 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
return F_80 ( V_183 -> V_184 , V_137 ) ;
}
int F_114 ( struct V_147 * V_147 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
if ( V_147 -> V_156 == V_183 -> V_184 -> V_185 ) {
F_93 ( V_183 -> V_184 ) ;
V_183 -> V_184 -> V_185 = NULL ;
}
return F_115 ( V_147 ) ;
}
T_5 F_116 ( struct V_147 * V_147 , char T_3 * V_175 ,
T_2 V_87 , T_4 * V_172 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
struct V_189 * V_190 = V_183 -> V_184 -> V_190 ? V_183 -> V_184 -> V_190 : V_183 -> V_190 ;
int V_109 = - V_82 ;
if ( V_190 && F_117 ( V_190 ) )
return - V_191 ;
if ( F_103 ( V_183 , V_147 ) )
goto exit;
V_109 = F_102 ( V_183 -> V_184 , V_175 , V_87 , V_172 ,
V_147 -> V_187 & V_188 ) ;
if ( V_183 -> V_184 -> V_81 )
V_183 -> V_184 -> V_185 = V_147 -> V_156 ;
exit:
if ( V_190 )
F_118 ( V_190 ) ;
return V_109 ;
}
T_5 F_119 ( struct V_147 * V_147 , char T_3 * V_175 ,
T_2 V_87 , T_4 * V_172 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
struct V_189 * V_190 = V_183 -> V_184 -> V_190 ? V_183 -> V_184 -> V_190 : V_183 -> V_190 ;
int V_109 = - V_82 ;
if ( V_190 && F_117 ( V_190 ) )
return - V_191 ;
if ( F_103 ( V_183 , V_147 ) )
goto exit;
V_109 = F_101 ( V_183 -> V_184 , V_175 , V_87 , V_172 ,
V_147 -> V_187 & V_188 ) ;
if ( V_183 -> V_184 -> V_81 )
V_183 -> V_184 -> V_185 = V_147 -> V_156 ;
exit:
if ( V_190 )
F_118 ( V_190 ) ;
return V_109 ;
}
unsigned int F_120 ( struct V_147 * V_147 , T_1 * V_148 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
struct V_3 * V_4 = V_183 -> V_184 ;
struct V_189 * V_190 = V_4 -> V_190 ? V_4 -> V_190 : V_183 -> V_190 ;
unsigned long V_151 = F_84 ( V_148 ) ;
unsigned V_152 ;
void * V_81 ;
bool V_192 = false ;
if ( V_4 -> V_28 == 0 && V_4 -> V_81 == NULL ) {
if ( ! F_45 ( V_4 -> type ) && ( V_4 -> V_71 & V_158 ) &&
( V_151 & ( V_159 | V_160 ) ) )
V_192 = true ;
else if ( F_45 ( V_4 -> type ) && ( V_4 -> V_71 & V_162 ) &&
( V_151 & ( V_163 | V_164 ) ) )
V_192 = true ;
}
F_90 ( V_192 && ! V_190 ) ;
if ( V_192 && V_190 && F_117 ( V_190 ) )
return V_161 ;
V_81 = V_4 -> V_81 ;
V_152 = F_82 ( V_183 -> V_184 , V_147 , V_148 ) ;
if ( V_192 && ! V_81 && V_4 -> V_81 )
V_4 -> V_185 = V_147 -> V_156 ;
if ( V_192 && V_190 )
F_118 ( V_190 ) ;
return V_152 ;
}
unsigned long F_121 ( struct V_147 * V_147 , unsigned long V_144 ,
unsigned long V_145 , unsigned long V_146 , unsigned long V_59 )
{
struct V_149 * V_183 = F_83 ( V_147 ) ;
return F_81 ( V_183 -> V_184 , V_144 , V_145 , V_146 , V_59 ) ;
}
void F_122 ( struct V_3 * V_193 )
{
F_118 ( V_193 -> V_190 ) ;
}
void F_123 ( struct V_3 * V_193 )
{
F_124 ( V_193 -> V_190 ) ;
}
