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
static void F_7 ( struct V_3 * V_4 , unsigned int V_19 )
{
unsigned int V_20 , V_6 ;
struct V_1 * V_2 ;
unsigned long V_21 ;
if ( V_4 -> V_22 ) {
struct V_23 * V_24 ;
V_2 = V_4 -> V_25 [ V_4 -> V_22 - 1 ] ;
V_24 = & V_2 -> V_12 [ V_2 -> V_7 - 1 ] ;
V_21 = F_8 ( V_24 -> V_26 . V_27 + V_24 -> V_13 ) ;
} else {
V_21 = 0 ;
}
for ( V_20 = V_4 -> V_22 ; V_20 < V_4 -> V_22 + V_19 ; ++ V_20 ) {
V_2 = V_4 -> V_25 [ V_20 ] ;
if ( ! V_2 )
continue;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_2 -> V_12 [ V_6 ] . V_13 = V_4 -> V_10 [ V_6 ] ;
V_2 -> V_12 [ V_6 ] . V_26 . V_27 = V_21 ;
F_5 ( 3 , L_2 ,
V_20 , V_6 , V_21 ) ;
V_21 += V_2 -> V_12 [ V_6 ] . V_13 ;
V_21 = F_8 ( V_21 ) ;
}
}
}
static int F_9 ( struct V_3 * V_4 , enum V_28 V_29 ,
unsigned int V_22 , unsigned int V_7 )
{
unsigned int V_20 ;
struct V_1 * V_2 ;
int V_30 ;
for ( V_20 = 0 ; V_20 < V_22 ; ++ V_20 ) {
V_2 = F_10 ( V_4 -> V_31 , V_32 ) ;
if ( ! V_2 ) {
F_5 ( 1 , L_3 ) ;
break;
}
if ( F_11 ( V_4 -> type ) )
V_2 -> V_16 . V_13 = V_7 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_16 . V_17 = V_4 -> V_22 + V_20 ;
V_2 -> V_16 . type = V_4 -> type ;
V_2 -> V_16 . V_29 = V_29 ;
if ( V_29 == V_35 ) {
V_30 = F_1 ( V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_4
L_5 , V_20 ) ;
F_12 ( V_2 ) ;
break;
}
V_30 = F_13 ( V_4 , V_36 , V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_6
L_7 , V_20 , V_2 ) ;
F_4 ( V_2 ) ;
F_12 ( V_2 ) ;
break;
}
}
V_4 -> V_25 [ V_4 -> V_22 + V_20 ] = V_2 ;
}
F_7 ( V_4 , V_20 ) ;
F_5 ( 1 , L_8 ,
V_20 , V_7 ) ;
return V_20 ;
}
static void F_14 ( struct V_3 * V_4 , unsigned int V_37 )
{
unsigned int V_20 ;
struct V_1 * V_2 ;
for ( V_20 = V_4 -> V_22 - V_37 ; V_20 < V_4 -> V_22 ;
++ V_20 ) {
V_2 = V_4 -> V_25 [ V_20 ] ;
if ( ! V_2 )
continue;
if ( V_4 -> V_29 == V_35 )
F_4 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
}
static void F_15 ( struct V_3 * V_4 , unsigned int V_37 )
{
unsigned int V_20 ;
if ( V_4 -> V_38 -> V_39 ) {
for ( V_20 = V_4 -> V_22 - V_37 ; V_20 < V_4 -> V_22 ;
++ V_20 ) {
if ( NULL == V_4 -> V_25 [ V_20 ] )
continue;
V_4 -> V_38 -> V_39 ( V_4 -> V_25 [ V_20 ] ) ;
}
}
F_14 ( V_4 , V_37 ) ;
for ( V_20 = V_4 -> V_22 - V_37 ; V_20 < V_4 -> V_22 ;
++ V_20 ) {
F_12 ( V_4 -> V_25 [ V_20 ] ) ;
V_4 -> V_25 [ V_20 ] = NULL ;
}
V_4 -> V_22 -= V_37 ;
if ( ! V_4 -> V_22 )
V_4 -> V_29 = 0 ;
F_16 ( & V_4 -> V_40 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
if ( ! F_11 ( V_42 -> type ) )
return 0 ;
if ( NULL == V_42 -> V_26 . V_11 ) {
F_5 ( 1 , L_9
L_10 ) ;
return - V_43 ;
}
if ( V_42 -> V_13 < V_2 -> V_7 || V_42 -> V_13 > V_44 ) {
F_5 ( 1 , L_11
L_12 , V_2 -> V_7 , V_42 -> V_13 ) ;
return - V_43 ;
}
return 0 ;
}
static bool F_18 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
void * V_5 = V_2 -> V_11 [ V_6 ] . V_5 ;
if ( V_5 && F_2 ( V_4 , V_45 , V_5 ) > 1 )
return true ;
}
return false ;
}
static bool F_19 ( struct V_3 * V_4 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_22 ; ++ V_20 ) {
if ( F_18 ( V_4 , V_4 -> V_25 [ V_20 ] ) )
return true ;
}
return false ;
}
static void F_20 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
memcpy ( V_42 , & V_2 -> V_16 , F_21 ( struct V_41 , V_26 ) ) ;
V_42 -> V_46 = V_2 -> V_16 . V_46 ;
V_42 -> V_47 = V_2 -> V_16 . V_47 ;
if ( F_11 ( V_4 -> type ) ) {
V_42 -> V_13 = V_2 -> V_7 ;
memcpy ( V_42 -> V_26 . V_11 , V_2 -> V_12 ,
V_42 -> V_13 * sizeof( struct V_23 ) ) ;
} else {
V_42 -> V_13 = V_2 -> V_12 [ 0 ] . V_13 ;
V_42 -> V_48 = V_2 -> V_12 [ 0 ] . V_48 ;
if ( V_4 -> V_29 == V_35 )
V_42 -> V_26 . V_49 = V_2 -> V_12 [ 0 ] . V_26 . V_27 ;
else if ( V_4 -> V_29 == V_50 )
V_42 -> V_26 . V_51 = V_2 -> V_12 [ 0 ] . V_26 . V_51 ;
}
V_42 -> V_52 &= ~ V_53 ;
switch ( V_2 -> V_33 ) {
case V_54 :
case V_55 :
V_42 -> V_52 |= V_56 ;
break;
case V_57 :
V_42 -> V_52 |= V_58 ;
case V_59 :
V_42 -> V_52 |= V_60 ;
break;
case V_61 :
V_42 -> V_52 |= V_62 ;
break;
case V_34 :
break;
}
if ( F_18 ( V_4 , V_2 ) )
V_42 -> V_52 |= V_63 ;
}
int F_22 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
int V_30 ;
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_13 ) ;
return - V_43 ;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_14 ) ;
return - V_43 ;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
V_30 = F_17 ( V_2 , V_42 ) ;
if ( ! V_30 )
F_20 ( V_2 , V_42 ) ;
return V_30 ;
}
static int F_23 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_64 & V_65 ) || ! V_4 -> V_66 -> V_67 ||
! V_4 -> V_66 -> V_18 )
return - V_43 ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_64 & V_68 ) || ! V_4 -> V_66 -> V_8 ||
! V_4 -> V_66 -> V_14 || ! V_4 -> V_66 -> V_69 )
return - V_43 ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
enum V_28 V_29 , enum V_70 type )
{
if ( V_29 != V_35 && V_29 != V_50 ) {
F_5 ( 1 , L_15 ) ;
return - V_43 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_16 ) ;
return - V_43 ;
}
if ( V_29 == V_35 && F_24 ( V_4 ) ) {
F_5 ( 1 , L_17 ) ;
return - V_43 ;
}
if ( V_29 == V_50 && F_23 ( V_4 ) ) {
F_5 ( 1 , L_18 ) ;
return - V_43 ;
}
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_19 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , struct V_73 * V_74 )
{
unsigned int V_22 , V_75 , V_7 = 0 ;
int V_30 ;
if ( V_4 -> V_76 ) {
F_5 ( 1 , L_20 ) ;
return - V_72 ;
}
if ( V_74 -> V_77 == 0 || V_4 -> V_22 != 0 || V_4 -> V_29 != V_74 -> V_29 ) {
if ( V_4 -> V_29 == V_35 && F_19 ( V_4 ) ) {
F_5 ( 1 , L_21 ) ;
return - V_72 ;
}
F_15 ( V_4 , V_4 -> V_22 ) ;
if ( V_74 -> V_77 == 0 )
return 0 ;
}
V_22 = F_27 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_29 = V_74 -> V_29 ;
V_30 = F_13 ( V_4 , V_78 , V_4 , NULL , & V_22 , & V_7 ,
V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( V_4 , V_74 -> V_29 , V_22 , V_7 ) ;
if ( V_30 == 0 ) {
F_5 ( 1 , L_22 ) ;
return - V_15 ;
}
V_75 = V_30 ;
if ( V_75 < V_22 ) {
V_22 = V_75 ;
V_30 = F_13 ( V_4 , V_78 , V_4 , NULL , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_30 && V_75 < V_22 )
V_30 = - V_15 ;
}
V_4 -> V_22 = V_75 ;
if ( V_30 < 0 ) {
F_15 ( V_4 , V_75 ) ;
return V_30 ;
}
V_74 -> V_77 = V_75 ;
return 0 ;
}
int F_28 ( struct V_3 * V_4 , struct V_73 * V_74 )
{
int V_30 = F_25 ( V_4 , V_74 -> V_29 , V_74 -> type ) ;
return V_30 ? V_30 : F_26 ( V_4 , V_74 ) ;
}
static int F_29 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
unsigned int V_7 = 0 , V_22 , V_75 ;
int V_30 ;
if ( V_4 -> V_22 == V_81 ) {
F_5 ( 1 , L_23 ,
V_82 ) ;
return - V_83 ;
}
if ( ! V_4 -> V_22 ) {
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_29 = V_80 -> V_29 ;
}
V_22 = F_30 ( V_80 -> V_77 , V_81 - V_4 -> V_22 ) ;
V_30 = F_13 ( V_4 , V_78 , V_4 , & V_80 -> V_84 , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( V_4 , V_80 -> V_29 , V_22 ,
V_7 ) ;
if ( V_30 == 0 ) {
F_5 ( 1 , L_22 ) ;
return - V_15 ;
}
V_75 = V_30 ;
if ( V_30 < V_22 ) {
V_22 = V_30 ;
V_30 = F_13 ( V_4 , V_78 , V_4 , & V_80 -> V_84 , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_30 && V_75 < V_22 )
V_30 = - V_15 ;
}
V_4 -> V_22 += V_75 ;
if ( V_30 < 0 ) {
F_15 ( V_4 , V_75 ) ;
return - V_15 ;
}
V_80 -> V_77 = V_75 ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
int V_30 = F_25 ( V_4 , V_80 -> V_29 , V_80 -> V_84 . type ) ;
V_80 -> V_17 = V_4 -> V_22 ;
if ( V_80 -> V_77 == 0 )
return V_30 != - V_72 ? V_30 : 0 ;
return V_30 ? V_30 : F_29 ( V_4 , V_80 ) ;
}
void * F_32 ( struct V_1 * V_2 , unsigned int V_85 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_85 > V_2 -> V_7 || ! V_2 -> V_11 [ V_85 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_86 , V_2 -> V_11 [ V_85 ] . V_5 ) ;
}
void * F_33 ( struct V_1 * V_2 , unsigned int V_85 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_85 > V_2 -> V_7 || ! V_2 -> V_11 [ V_85 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_87 , V_2 -> V_11 [ V_85 ] . V_5 ) ;
}
void F_34 ( struct V_1 * V_2 , enum V_88 V_33 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_52 ;
if ( V_2 -> V_33 != V_55 )
return;
if ( V_33 != V_59 && V_33 != V_57 )
return;
F_5 ( 4 , L_24 ,
V_2 -> V_16 . V_17 , V_2 -> V_33 ) ;
F_35 ( & V_4 -> V_89 , V_52 ) ;
V_2 -> V_33 = V_33 ;
F_36 ( & V_2 -> V_90 , & V_4 -> V_91 ) ;
F_37 ( & V_4 -> V_92 ) ;
F_38 ( & V_4 -> V_89 , V_52 ) ;
F_39 ( & V_4 -> V_93 ) ;
}
static void F_40 ( struct V_1 * V_2 , const struct V_41 * V_42 ,
struct V_23 * V_12 )
{
unsigned int V_6 ;
if ( F_11 ( V_42 -> type ) ) {
if ( F_41 ( V_42 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_48 =
V_42 -> V_26 . V_11 [ V_6 ] . V_48 ;
V_12 [ V_6 ] . V_94 =
V_42 -> V_26 . V_11 [ V_6 ] . V_94 ;
}
}
if ( V_42 -> V_29 == V_50 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_26 . V_51 =
V_42 -> V_26 . V_11 [ V_6 ] . V_26 . V_51 ;
V_12 [ V_6 ] . V_13 =
V_42 -> V_26 . V_11 [ V_6 ] . V_13 ;
}
}
} else {
if ( F_41 ( V_42 -> type ) )
V_12 [ 0 ] . V_48 = V_42 -> V_48 ;
if ( V_42 -> V_29 == V_50 ) {
V_12 [ 0 ] . V_26 . V_51 = V_42 -> V_26 . V_51 ;
V_12 [ 0 ] . V_13 = V_42 -> V_13 ;
}
}
V_2 -> V_16 . V_95 = V_42 -> V_95 ;
V_2 -> V_16 . V_96 = V_42 -> V_96 ;
V_2 -> V_16 . V_52 = V_42 -> V_52 & ~ V_53 ;
}
static int F_42 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_23 V_11 [ V_44 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_30 ;
int V_97 = ! F_41 ( V_4 -> type ) ;
F_40 ( V_2 , V_42 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_6 ] . V_26 . V_51 &&
V_2 -> V_12 [ V_6 ] . V_26 . V_51 == V_11 [ V_6 ] . V_26 . V_51
&& V_2 -> V_12 [ V_6 ] . V_13 == V_11 [ V_6 ] . V_13 )
continue;
F_5 ( 3 , L_25
L_26 , V_6 ) ;
if ( V_11 [ V_6 ] . V_13 < V_4 -> V_10 [ V_6 ] ) {
V_30 = - V_43 ;
goto V_98;
}
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_26 . V_51 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
V_5 = F_2 ( V_4 , V_67 , V_4 -> V_9 [ V_6 ] ,
V_11 [ V_6 ] . V_26 . V_51 ,
V_11 [ V_6 ] . V_13 , V_97 ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( 1 , L_27
L_28 , V_6 ) ;
V_30 = V_5 ? F_43 ( V_5 ) : - V_43 ;
goto V_98;
}
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
V_30 = F_13 ( V_4 , V_36 , V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_29 ) ;
goto V_98;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_12 [ V_6 ] = V_11 [ V_6 ] ;
return 0 ;
V_98:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_26 . V_51 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
}
return V_30 ;
}
static int F_44 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
F_40 ( V_2 , V_42 , V_2 -> V_12 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
V_2 -> V_33 = V_55 ;
F_46 ( & V_4 -> V_92 ) ;
V_4 -> V_38 -> V_99 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_30 ;
switch ( V_4 -> V_29 ) {
case V_35 :
V_30 = F_44 ( V_2 , V_42 ) ;
break;
case V_50 :
V_30 = F_42 ( V_2 , V_42 ) ;
break;
default:
F_48 ( 1 , L_30 ) ;
V_30 = - V_43 ;
}
if ( ! V_30 )
V_30 = F_13 ( V_4 , V_100 , V_2 ) ;
if ( V_30 )
F_5 ( 1 , L_31 , V_30 ) ;
else
V_2 -> V_33 = V_61 ;
return V_30 ;
}
int F_49 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
int V_30 ;
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_32 , V_82 ) ;
return - V_72 ;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_33 , V_82 ) ;
return - V_43 ;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_34 , V_82 ) ;
return - V_43 ;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_35 , V_82 ) ;
return - V_43 ;
}
if ( V_42 -> V_29 != V_4 -> V_29 ) {
F_5 ( 1 , L_36 , V_82 ) ;
return - V_43 ;
}
if ( V_2 -> V_33 != V_34 ) {
F_5 ( 1 , L_37 , V_82 , V_2 -> V_33 ) ;
return - V_43 ;
}
V_30 = F_17 ( V_2 , V_42 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_47 ( V_2 , V_42 ) ;
if ( V_30 < 0 )
return V_30 ;
F_20 ( V_2 , V_42 ) ;
return 0 ;
}
int F_50 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_101 * V_102 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
if ( V_4 -> V_29 == V_50 ) {
V_102 = & V_103 -> V_104 -> V_102 ;
F_13 ( V_4 , V_105 , V_4 ) ;
F_51 ( V_102 ) ;
F_13 ( V_4 , V_106 , V_4 ) ;
}
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_38 ) ;
V_30 = - V_72 ;
goto V_107;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_39 ) ;
V_30 = - V_43 ;
goto V_107;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_40 ) ;
V_30 = - V_43 ;
goto V_107;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_41 ) ;
V_30 = - V_43 ;
goto V_107;
}
if ( V_42 -> V_29 != V_4 -> V_29 ) {
F_5 ( 1 , L_42 ) ;
V_30 = - V_43 ;
goto V_107;
}
V_30 = F_17 ( V_2 , V_42 ) ;
if ( V_30 )
goto V_107;
switch ( V_2 -> V_33 ) {
case V_34 :
V_30 = F_47 ( V_2 , V_42 ) ;
if ( V_30 )
goto V_107;
case V_61 :
break;
default:
F_5 ( 1 , L_43 ) ;
V_30 = - V_43 ;
goto V_107;
}
F_36 ( & V_2 -> V_108 , & V_4 -> V_40 ) ;
V_2 -> V_33 = V_54 ;
if ( V_4 -> V_76 )
F_45 ( V_2 ) ;
F_20 ( V_2 , V_42 ) ;
F_5 ( 1 , L_44 , V_2 -> V_16 . V_17 ) ;
V_107:
if ( V_102 )
F_52 ( V_102 ) ;
return V_30 ;
}
static int F_53 ( struct V_3 * V_4 , int V_109 )
{
for (; ; ) {
int V_30 ;
if ( ! V_4 -> V_76 ) {
F_5 ( 1 , L_45 ) ;
return - V_43 ;
}
if ( ! F_54 ( & V_4 -> V_91 ) ) {
break;
}
if ( V_109 ) {
F_5 ( 1 , L_46
L_47 ) ;
return - V_110 ;
}
F_13 ( V_4 , V_105 , V_4 ) ;
F_5 ( 3 , L_48 ) ;
V_30 = F_55 ( V_4 -> V_93 ,
! F_54 ( & V_4 -> V_91 ) || ! V_4 -> V_76 ) ;
F_13 ( V_4 , V_106 , V_4 ) ;
if ( V_30 ) {
F_5 ( 1 , L_49 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_56 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
struct V_41 * V_42 , int V_109 )
{
unsigned long V_52 ;
int V_30 ;
V_30 = F_53 ( V_4 , V_109 ) ;
if ( V_30 )
return V_30 ;
F_35 ( & V_4 -> V_89 , V_52 ) ;
* V_2 = F_57 ( & V_4 -> V_91 , struct V_1 , V_90 ) ;
V_30 = F_17 ( * V_2 , V_42 ) ;
if ( ! V_30 )
F_58 ( & ( * V_2 ) -> V_90 ) ;
F_38 ( & V_4 -> V_89 , V_52 ) ;
return V_30 ;
}
int F_59 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_76 ) {
F_5 ( 1 , L_45 ) ;
return - V_43 ;
}
F_60 ( V_4 -> V_93 , ! F_61 ( & V_4 -> V_92 ) ) ;
return 0 ;
}
int F_62 ( struct V_3 * V_4 , struct V_41 * V_42 , bool V_109 )
{
struct V_1 * V_2 = NULL ;
int V_30 ;
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_50 ) ;
return - V_72 ;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_51 ) ;
return - V_43 ;
}
V_30 = F_56 ( V_4 , & V_2 , V_42 , V_109 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_13 ( V_4 , V_111 , V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_52 ) ;
return V_30 ;
}
switch ( V_2 -> V_33 ) {
case V_59 :
F_5 ( 3 , L_53 ) ;
break;
case V_57 :
F_5 ( 3 , L_54 ) ;
break;
default:
F_5 ( 1 , L_55 ) ;
return - V_43 ;
}
F_20 ( V_2 , V_42 ) ;
F_58 ( & V_2 -> V_108 ) ;
F_5 ( 1 , L_56 ,
V_2 -> V_16 . V_17 , V_2 -> V_33 ) ;
V_2 -> V_33 = V_34 ;
return 0 ;
}
static void F_63 ( struct V_3 * V_4 )
{
unsigned int V_112 ;
if ( V_4 -> V_76 )
F_13 ( V_4 , V_113 , V_4 ) ;
V_4 -> V_76 = 0 ;
F_16 ( & V_4 -> V_40 ) ;
F_16 ( & V_4 -> V_91 ) ;
F_64 ( & V_4 -> V_92 , 0 ) ;
F_65 ( & V_4 -> V_93 ) ;
for ( V_112 = 0 ; V_112 < V_4 -> V_22 ; ++ V_112 )
V_4 -> V_25 [ V_112 ] -> V_33 = V_34 ;
}
int F_66 ( struct V_3 * V_4 , enum V_70 type )
{
struct V_1 * V_2 ;
int V_30 ;
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_57 ) ;
return - V_72 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_58 ) ;
return - V_43 ;
}
if ( V_4 -> V_76 ) {
F_5 ( 1 , L_59 ) ;
return - V_72 ;
}
F_67 (vb, &q->queued_list, queued_entry)
F_45 ( V_2 ) ;
V_30 = F_13 ( V_4 , V_114 , V_4 , F_61 ( & V_4 -> V_92 ) ) ;
if ( V_30 ) {
F_5 ( 1 , L_60 ) ;
F_63 ( V_4 ) ;
return V_30 ;
}
V_4 -> V_76 = 1 ;
F_5 ( 3 , L_61 ) ;
return 0 ;
}
int F_68 ( struct V_3 * V_4 , enum V_70 type )
{
if ( V_4 -> V_71 ) {
F_5 ( 1 , L_62 ) ;
return - V_72 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_63 ) ;
return - V_43 ;
}
if ( ! V_4 -> V_76 ) {
F_5 ( 1 , L_64 ) ;
return - V_43 ;
}
F_63 ( V_4 ) ;
F_5 ( 3 , L_65 ) ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 , unsigned long V_21 ,
unsigned int * V_115 , unsigned int * V_116 )
{
struct V_1 * V_2 ;
unsigned int V_20 , V_6 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_22 ; ++ V_20 ) {
V_2 = V_4 -> V_25 [ V_20 ] ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_6 ] . V_26 . V_27 == V_21 ) {
* V_115 = V_20 ;
* V_116 = V_6 ;
return 0 ;
}
}
}
return - V_43 ;
}
int F_70 ( struct V_3 * V_4 , struct V_117 * V_118 )
{
unsigned long V_21 = V_118 -> V_119 << V_120 ;
struct V_1 * V_2 ;
unsigned int V_20 , V_6 ;
int V_30 ;
if ( V_4 -> V_29 != V_35 ) {
F_5 ( 1 , L_66 ) ;
return - V_43 ;
}
if ( ! ( V_118 -> V_121 & V_122 ) ) {
F_5 ( 1 , L_67 ) ;
return - V_43 ;
}
if ( F_41 ( V_4 -> type ) ) {
if ( ! ( V_118 -> V_121 & V_123 ) ) {
F_5 ( 1 , L_68 ) ;
return - V_43 ;
}
} else {
if ( ! ( V_118 -> V_121 & V_124 ) ) {
F_5 ( 1 , L_69 ) ;
return - V_43 ;
}
}
V_30 = F_69 ( V_4 , V_21 , & V_20 , & V_6 ) ;
if ( V_30 )
return V_30 ;
V_2 = V_4 -> V_25 [ V_20 ] ;
V_30 = F_2 ( V_4 , V_69 , V_2 -> V_11 [ V_6 ] . V_5 , V_118 ) ;
if ( V_30 )
return V_30 ;
F_5 ( 3 , L_70 , V_20 , V_6 ) ;
return 0 ;
}
unsigned long F_71 ( struct V_3 * V_4 ,
unsigned long V_125 ,
unsigned long V_126 ,
unsigned long V_127 ,
unsigned long V_52 )
{
unsigned long V_21 = V_127 << V_120 ;
struct V_1 * V_2 ;
unsigned int V_20 , V_6 ;
int V_30 ;
if ( V_4 -> V_29 != V_35 ) {
F_5 ( 1 , L_66 ) ;
return - V_43 ;
}
V_30 = F_69 ( V_4 , V_21 , & V_20 , & V_6 ) ;
if ( V_30 )
return V_30 ;
V_2 = V_4 -> V_25 [ V_20 ] ;
return ( unsigned long ) F_32 ( V_2 , V_6 ) ;
}
unsigned int F_72 ( struct V_3 * V_4 , struct V_128 * V_128 , T_1 * V_129 )
{
struct V_130 * V_131 = F_73 ( V_128 ) ;
unsigned long V_132 = F_74 ( V_129 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_133 = 0 ;
unsigned long V_52 ;
if ( F_75 ( V_134 , & V_131 -> V_52 ) ) {
struct V_135 * V_136 = V_128 -> V_137 ;
if ( F_76 ( V_136 ) )
V_133 = V_138 ;
else if ( V_132 & V_138 )
F_77 ( V_128 , & V_136 -> V_129 , V_129 ) ;
}
if ( V_4 -> V_22 == 0 && V_4 -> V_71 == NULL ) {
if ( ! F_41 ( V_4 -> type ) && ( V_4 -> V_64 & V_139 ) &&
( V_132 & ( V_140 | V_141 ) ) ) {
if ( F_78 ( V_4 , 1 ) )
return V_133 | V_142 ;
}
if ( F_41 ( V_4 -> type ) && ( V_4 -> V_64 & V_143 ) &&
( V_132 & ( V_144 | V_145 ) ) ) {
if ( F_78 ( V_4 , 0 ) )
return V_133 | V_142 ;
return V_133 | V_144 | V_145 ;
}
}
if ( F_54 ( & V_4 -> V_40 ) )
return V_133 | V_142 ;
F_77 ( V_128 , & V_4 -> V_93 , V_129 ) ;
F_35 ( & V_4 -> V_89 , V_52 ) ;
if ( ! F_54 ( & V_4 -> V_91 ) )
V_2 = F_57 ( & V_4 -> V_91 , struct V_1 ,
V_90 ) ;
F_38 ( & V_4 -> V_89 , V_52 ) ;
if ( V_2 && ( V_2 -> V_33 == V_59
|| V_2 -> V_33 == V_57 ) ) {
return ( F_41 ( V_4 -> type ) ) ?
V_133 | V_144 | V_145 :
V_133 | V_140 | V_141 ;
}
return V_133 ;
}
int F_79 ( struct V_3 * V_4 )
{
if ( F_80 ( ! V_4 ) ||
F_80 ( ! V_4 -> V_38 ) ||
F_80 ( ! V_4 -> V_66 ) ||
F_80 ( ! V_4 -> type ) ||
F_80 ( ! V_4 -> V_64 ) ||
F_80 ( ! V_4 -> V_38 -> V_78 ) ||
F_80 ( ! V_4 -> V_38 -> V_99 ) )
return - V_43 ;
F_16 ( & V_4 -> V_40 ) ;
F_16 ( & V_4 -> V_91 ) ;
F_81 ( & V_4 -> V_89 ) ;
F_82 ( & V_4 -> V_93 ) ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_83 ( struct V_3 * V_4 )
{
F_84 ( V_4 ) ;
F_63 ( V_4 ) ;
F_15 ( V_4 , V_4 -> V_22 ) ;
}
static int F_78 ( struct V_3 * V_4 , int V_146 )
{
struct V_147 * V_71 ;
int V_112 , V_30 ;
unsigned int V_77 = 0 ;
if ( ( V_146 && ! ( V_4 -> V_64 & V_139 ) ) ||
( ! V_146 && ! ( V_4 -> V_64 & V_143 ) ) )
F_85 () ;
if ( ! V_4 -> V_66 -> V_86 )
return - V_72 ;
if ( V_4 -> V_76 || V_4 -> V_22 > 0 )
return - V_72 ;
V_77 = 1 ;
F_5 ( 3 , L_71 ,
( V_146 ) ? L_72 : L_73 , V_77 , V_4 -> V_148 ) ;
V_71 = F_10 ( sizeof( struct V_147 ) , V_32 ) ;
if ( V_71 == NULL )
return - V_15 ;
V_71 -> V_52 = V_4 -> V_148 ;
V_71 -> V_74 . V_77 = V_77 ;
V_71 -> V_74 . V_29 = V_35 ;
V_71 -> V_74 . type = V_4 -> type ;
V_30 = F_28 ( V_4 , & V_71 -> V_74 ) ;
if ( V_30 )
goto V_149;
if ( V_4 -> V_25 [ 0 ] -> V_7 != 1 ) {
V_30 = - V_72 ;
goto V_150;
}
for ( V_112 = 0 ; V_112 < V_4 -> V_22 ; V_112 ++ ) {
V_71 -> V_25 [ V_112 ] . V_86 = F_32 ( V_4 -> V_25 [ V_112 ] , 0 ) ;
if ( V_71 -> V_25 [ V_112 ] . V_86 == NULL )
goto V_150;
V_71 -> V_25 [ V_112 ] . V_151 = F_86 ( V_4 -> V_25 [ V_112 ] , 0 ) ;
}
if ( V_146 ) {
for ( V_112 = 0 ; V_112 < V_4 -> V_22 ; V_112 ++ ) {
struct V_41 * V_42 = & V_71 -> V_42 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> type = V_4 -> type ;
V_42 -> V_29 = V_4 -> V_29 ;
V_42 -> V_17 = V_112 ;
V_30 = F_50 ( V_4 , V_42 ) ;
if ( V_30 )
goto V_150;
V_71 -> V_25 [ V_112 ] . V_152 = 1 ;
}
V_30 = F_66 ( V_4 , V_4 -> type ) ;
if ( V_30 )
goto V_150;
}
V_4 -> V_71 = V_71 ;
return V_30 ;
V_150:
V_71 -> V_74 . V_77 = 0 ;
F_28 ( V_4 , & V_71 -> V_74 ) ;
V_149:
F_12 ( V_71 ) ;
return V_30 ;
}
static int F_84 ( struct V_3 * V_4 )
{
struct V_147 * V_71 = V_4 -> V_71 ;
if ( V_71 ) {
V_4 -> V_71 = NULL ;
F_68 ( V_4 , V_4 -> type ) ;
V_71 -> V_74 . V_77 = 0 ;
F_28 ( V_4 , & V_71 -> V_74 ) ;
F_12 ( V_71 ) ;
F_5 ( 3 , L_74 ) ;
}
return 0 ;
}
static T_2 F_87 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_77 ,
T_4 * V_154 , int V_155 , int V_146 )
{
struct V_147 * V_71 ;
struct V_156 * V_157 ;
int V_30 , V_17 ;
F_5 ( 3 , L_75 ,
V_146 ? L_72 : L_73 , ( long ) * V_154 , V_77 ,
V_155 ? L_76 : L_77 ) ;
if ( ! V_153 )
return - V_43 ;
if ( ! V_4 -> V_71 ) {
V_30 = F_78 ( V_4 , V_146 ) ;
F_5 ( 3 , L_78 , V_30 ) ;
if ( V_30 )
return V_30 ;
}
V_71 = V_4 -> V_71 ;
V_4 -> V_71 = NULL ;
V_17 = V_71 -> V_17 ;
V_157 = & V_71 -> V_25 [ V_17 ] ;
if ( V_157 -> V_152 ) {
struct V_1 * V_2 ;
memset ( & V_71 -> V_42 , 0 , sizeof( V_71 -> V_42 ) ) ;
V_71 -> V_42 . type = V_4 -> type ;
V_71 -> V_42 . V_29 = V_4 -> V_29 ;
V_71 -> V_42 . V_17 = V_17 ;
V_30 = F_62 ( V_4 , & V_71 -> V_42 , V_155 ) ;
F_5 ( 5 , L_79 , V_30 ) ;
if ( V_30 )
goto V_158;
V_71 -> V_159 += 1 ;
V_2 = V_4 -> V_25 [ V_17 ] ;
V_157 -> V_151 = F_88 ( V_2 , 0 ) ;
V_157 -> V_152 = 0 ;
}
if ( V_157 -> V_160 + V_77 > V_157 -> V_151 ) {
V_77 = V_157 -> V_151 - V_157 -> V_160 ;
F_5 ( 5 , L_80 , V_77 ) ;
}
F_5 ( 3 , L_81 ,
V_77 , V_17 , V_157 -> V_160 ) ;
if ( V_146 )
V_30 = F_89 ( V_153 , V_157 -> V_86 + V_157 -> V_160 , V_77 ) ;
else
V_30 = F_90 ( V_157 -> V_86 + V_157 -> V_160 , V_153 , V_77 ) ;
if ( V_30 ) {
F_5 ( 3 , L_82 ) ;
V_30 = - V_161 ;
goto V_158;
}
V_157 -> V_160 += V_77 ;
* V_154 += V_77 ;
if ( V_157 -> V_160 == V_157 -> V_151 ||
( ! V_146 && ( V_71 -> V_52 & V_162 ) ) ) {
if ( V_146 && ( V_71 -> V_52 & V_163 ) &&
V_71 -> V_159 == 1 ) {
F_5 ( 3 , L_83 ) ;
V_4 -> V_71 = V_71 ;
return F_84 ( V_4 ) ;
}
memset ( & V_71 -> V_42 , 0 , sizeof( V_71 -> V_42 ) ) ;
V_71 -> V_42 . type = V_4 -> type ;
V_71 -> V_42 . V_29 = V_4 -> V_29 ;
V_71 -> V_42 . V_17 = V_17 ;
V_71 -> V_42 . V_48 = V_157 -> V_160 ;
V_30 = F_50 ( V_4 , & V_71 -> V_42 ) ;
F_5 ( 5 , L_84 , V_30 ) ;
if ( V_30 )
goto V_158;
V_157 -> V_160 = 0 ;
V_157 -> V_152 = 1 ;
V_157 -> V_151 = V_4 -> V_25 [ 0 ] -> V_12 [ 0 ] . V_13 ;
V_71 -> V_164 += 1 ;
V_71 -> V_17 = ( V_17 + 1 ) % V_4 -> V_22 ;
if ( ! V_146 && ! V_4 -> V_76 ) {
V_30 = F_66 ( V_4 , V_4 -> type ) ;
if ( V_30 )
goto V_158;
}
}
if ( V_30 == 0 )
V_30 = V_77 ;
V_158:
V_4 -> V_71 = V_71 ;
return V_30 ;
}
T_2 F_91 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_77 ,
T_4 * V_154 , int V_109 )
{
return F_87 ( V_4 , V_153 , V_77 , V_154 , V_109 , 1 ) ;
}
T_2 F_92 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_77 ,
T_4 * V_154 , int V_109 )
{
return F_87 ( V_4 , V_153 , V_77 , V_154 , V_109 , 0 ) ;
}
static inline bool F_93 ( struct V_130 * V_165 , struct V_128 * V_128 )
{
return V_165 -> V_166 -> V_167 && V_165 -> V_166 -> V_167 != V_128 -> V_137 ;
}
int F_94 ( struct V_128 * V_128 , void * V_168 ,
struct V_73 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
int V_133 = F_25 ( V_165 -> V_166 , V_24 -> V_29 , V_24 -> type ) ;
if ( V_133 )
return V_133 ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
V_133 = F_26 ( V_165 -> V_166 , V_24 ) ;
if ( V_133 == 0 )
V_165 -> V_166 -> V_167 = V_24 -> V_77 ? V_128 -> V_137 : NULL ;
return V_133 ;
}
int F_95 ( struct V_128 * V_128 , void * V_168 ,
struct V_79 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
int V_133 = F_25 ( V_165 -> V_166 , V_24 -> V_29 , V_24 -> V_84 . type ) ;
V_24 -> V_17 = V_165 -> V_166 -> V_22 ;
if ( V_24 -> V_77 == 0 )
return V_133 != - V_72 ? V_133 : 0 ;
if ( V_133 )
return V_133 ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
V_133 = F_29 ( V_165 -> V_166 , V_24 ) ;
if ( V_133 == 0 )
V_165 -> V_166 -> V_167 = V_128 -> V_137 ;
return V_133 ;
}
int F_96 ( struct V_128 * V_128 , void * V_168 ,
struct V_41 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
return F_49 ( V_165 -> V_166 , V_24 ) ;
}
int F_97 ( struct V_128 * V_128 , void * V_168 , struct V_41 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
return F_22 ( V_165 -> V_166 , V_24 ) ;
}
int F_98 ( struct V_128 * V_128 , void * V_168 , struct V_41 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
return F_50 ( V_165 -> V_166 , V_24 ) ;
}
int F_99 ( struct V_128 * V_128 , void * V_168 , struct V_41 * V_24 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
return F_62 ( V_165 -> V_166 , V_24 , V_128 -> V_169 & V_170 ) ;
}
int F_100 ( struct V_128 * V_128 , void * V_168 , enum V_70 V_112 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
return F_66 ( V_165 -> V_166 , V_112 ) ;
}
int F_101 ( struct V_128 * V_128 , void * V_168 , enum V_70 V_112 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( F_93 ( V_165 , V_128 ) )
return - V_72 ;
return F_68 ( V_165 -> V_166 , V_112 ) ;
}
int F_102 ( struct V_128 * V_128 , struct V_117 * V_118 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
return F_70 ( V_165 -> V_166 , V_118 ) ;
}
int F_103 ( struct V_128 * V_128 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
if ( V_128 -> V_137 == V_165 -> V_166 -> V_167 ) {
F_83 ( V_165 -> V_166 ) ;
V_165 -> V_166 -> V_167 = NULL ;
}
return F_104 ( V_128 ) ;
}
T_5 F_105 ( struct V_128 * V_128 , char T_3 * V_157 ,
T_2 V_77 , T_4 * V_154 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
struct V_171 * V_172 = V_165 -> V_166 -> V_172 ? V_165 -> V_166 -> V_172 : V_165 -> V_172 ;
int V_98 = - V_72 ;
if ( V_172 && F_106 ( V_172 ) )
return - V_173 ;
if ( F_93 ( V_165 , V_128 ) )
goto exit;
V_98 = F_92 ( V_165 -> V_166 , V_157 , V_77 , V_154 ,
V_128 -> V_169 & V_170 ) ;
if ( V_165 -> V_166 -> V_71 )
V_165 -> V_166 -> V_167 = V_128 -> V_137 ;
exit:
if ( V_172 )
F_107 ( V_172 ) ;
return V_98 ;
}
T_5 F_108 ( struct V_128 * V_128 , char T_3 * V_157 ,
T_2 V_77 , T_4 * V_154 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
struct V_171 * V_172 = V_165 -> V_166 -> V_172 ? V_165 -> V_166 -> V_172 : V_165 -> V_172 ;
int V_98 = - V_72 ;
if ( V_172 && F_106 ( V_172 ) )
return - V_173 ;
if ( F_93 ( V_165 , V_128 ) )
goto exit;
V_98 = F_91 ( V_165 -> V_166 , V_157 , V_77 , V_154 ,
V_128 -> V_169 & V_170 ) ;
if ( V_165 -> V_166 -> V_71 )
V_165 -> V_166 -> V_167 = V_128 -> V_137 ;
exit:
if ( V_172 )
F_107 ( V_172 ) ;
return V_98 ;
}
unsigned int F_109 ( struct V_128 * V_128 , T_1 * V_129 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
struct V_3 * V_4 = V_165 -> V_166 ;
struct V_171 * V_172 = V_4 -> V_172 ? V_4 -> V_172 : V_165 -> V_172 ;
unsigned long V_132 = F_74 ( V_129 ) ;
unsigned V_133 ;
void * V_71 ;
bool V_174 = false ;
if ( V_4 -> V_22 == 0 && V_4 -> V_71 == NULL ) {
if ( ! F_41 ( V_4 -> type ) && ( V_4 -> V_64 & V_139 ) &&
( V_132 & ( V_140 | V_141 ) ) )
V_174 = true ;
else if ( F_41 ( V_4 -> type ) && ( V_4 -> V_64 & V_143 ) &&
( V_132 & ( V_144 | V_145 ) ) )
V_174 = true ;
}
F_80 ( V_174 && ! V_172 ) ;
if ( V_174 && V_172 && F_106 ( V_172 ) )
return V_142 ;
V_71 = V_4 -> V_71 ;
V_133 = F_72 ( V_165 -> V_166 , V_128 , V_129 ) ;
if ( V_174 && ! V_71 && V_4 -> V_71 )
V_4 -> V_167 = V_128 -> V_137 ;
if ( V_174 && V_172 )
F_107 ( V_172 ) ;
return V_133 ;
}
unsigned long F_110 ( struct V_128 * V_128 , unsigned long V_125 ,
unsigned long V_126 , unsigned long V_127 , unsigned long V_52 )
{
struct V_130 * V_165 = F_73 ( V_128 ) ;
return F_71 ( V_165 -> V_166 , V_125 , V_126 , V_127 , V_52 ) ;
}
void F_111 ( struct V_3 * V_175 )
{
F_107 ( V_175 -> V_172 ) ;
}
void F_112 ( struct V_3 * V_175 )
{
F_113 ( V_175 -> V_172 ) ;
}
