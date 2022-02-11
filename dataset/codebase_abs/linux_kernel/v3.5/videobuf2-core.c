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
static int F_20 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_30 ;
memcpy ( V_42 , & V_2 -> V_16 , F_21 ( struct V_41 , V_26 ) ) ;
V_42 -> V_46 = V_2 -> V_16 . V_46 ;
V_42 -> V_47 = V_2 -> V_16 . V_47 ;
if ( F_11 ( V_4 -> type ) ) {
V_30 = F_17 ( V_2 , V_42 ) ;
if ( V_30 )
return V_30 ;
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
return 0 ;
}
int F_22 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_13 ) ;
return - V_43 ;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_14 ) ;
return - V_43 ;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
return F_20 ( V_2 , V_42 ) ;
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
int F_25 ( struct V_3 * V_4 , struct V_70 * V_71 )
{
unsigned int V_22 , V_72 , V_7 = 0 ;
int V_30 = 0 ;
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_15 ) ;
return - V_74 ;
}
if ( V_71 -> V_29 != V_35
&& V_71 -> V_29 != V_50 ) {
F_5 ( 1 , L_16 ) ;
return - V_43 ;
}
if ( V_71 -> type != V_4 -> type ) {
F_5 ( 1 , L_17 ) ;
return - V_43 ;
}
if ( V_4 -> V_75 ) {
F_5 ( 1 , L_18 ) ;
return - V_74 ;
}
if ( V_71 -> V_29 == V_35 && F_24 ( V_4 ) ) {
F_5 ( 1 , L_19 ) ;
return - V_43 ;
}
if ( V_71 -> V_29 == V_50 && F_23 ( V_4 ) ) {
F_5 ( 1 , L_20 ) ;
return - V_43 ;
}
if ( V_71 -> V_76 == 0 || V_4 -> V_22 != 0 || V_4 -> V_29 != V_71 -> V_29 ) {
if ( V_4 -> V_29 == V_35 && F_19 ( V_4 ) ) {
F_5 ( 1 , L_21 ) ;
return - V_74 ;
}
F_15 ( V_4 , V_4 -> V_22 ) ;
if ( V_71 -> V_76 == 0 )
return 0 ;
}
V_22 = F_26 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_29 = V_71 -> V_29 ;
V_30 = F_13 ( V_4 , V_77 , V_4 , NULL , & V_22 , & V_7 ,
V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( V_4 , V_71 -> V_29 , V_22 , V_7 ) ;
if ( V_30 == 0 ) {
F_5 ( 1 , L_22 ) ;
return - V_15 ;
}
V_72 = V_30 ;
if ( V_72 < V_22 ) {
V_22 = V_72 ;
V_30 = F_13 ( V_4 , V_77 , V_4 , NULL , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_30 && V_72 < V_22 )
V_30 = - V_15 ;
}
V_4 -> V_22 = V_72 ;
if ( V_30 < 0 ) {
F_15 ( V_4 , V_72 ) ;
return V_30 ;
}
V_71 -> V_76 = V_72 ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
unsigned int V_7 = 0 , V_22 , V_72 ;
int V_30 = 0 ;
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_23 , V_80 ) ;
return - V_74 ;
}
if ( V_79 -> V_29 != V_35
&& V_79 -> V_29 != V_50 ) {
F_5 ( 1 , L_24 , V_80 ) ;
return - V_43 ;
}
if ( V_79 -> V_81 . type != V_4 -> type ) {
F_5 ( 1 , L_25 , V_80 ) ;
return - V_43 ;
}
if ( V_79 -> V_29 == V_35 && F_24 ( V_4 ) ) {
F_5 ( 1 , L_26 , V_80 ) ;
return - V_43 ;
}
if ( V_79 -> V_29 == V_50 && F_23 ( V_4 ) ) {
F_5 ( 1 , L_27 , V_80 ) ;
return - V_43 ;
}
if ( V_4 -> V_22 == V_82 ) {
F_5 ( 1 , L_28 ,
V_80 ) ;
return - V_83 ;
}
V_79 -> V_17 = V_4 -> V_22 ;
if ( ! V_4 -> V_22 ) {
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> V_29 = V_79 -> V_29 ;
}
V_22 = F_28 ( V_79 -> V_76 , V_82 - V_4 -> V_22 ) ;
V_30 = F_13 ( V_4 , V_77 , V_4 , & V_79 -> V_81 , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( V_4 , V_79 -> V_29 , V_22 ,
V_7 ) ;
if ( V_30 < 0 ) {
F_5 ( 1 , L_29 , V_30 ) ;
return V_30 ;
}
V_72 = V_30 ;
if ( V_30 < V_22 ) {
V_22 = V_30 ;
V_30 = F_13 ( V_4 , V_77 , V_4 , & V_79 -> V_81 , & V_22 ,
& V_7 , V_4 -> V_10 , V_4 -> V_9 ) ;
if ( ! V_30 && V_72 < V_22 )
V_30 = - V_15 ;
}
V_4 -> V_22 += V_72 ;
if ( V_30 < 0 ) {
F_15 ( V_4 , V_72 ) ;
return V_30 ;
}
V_79 -> V_76 = V_72 ;
return 0 ;
}
void * F_29 ( struct V_1 * V_2 , unsigned int V_84 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_84 > V_2 -> V_7 || ! V_2 -> V_11 [ V_84 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_85 , V_2 -> V_11 [ V_84 ] . V_5 ) ;
}
void * F_30 ( struct V_1 * V_2 , unsigned int V_84 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
if ( V_84 > V_2 -> V_7 || ! V_2 -> V_11 [ V_84 ] . V_5 )
return NULL ;
return F_2 ( V_4 , V_86 , V_2 -> V_11 [ V_84 ] . V_5 ) ;
}
void F_31 ( struct V_1 * V_2 , enum V_87 V_33 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
unsigned long V_52 ;
if ( V_2 -> V_33 != V_55 )
return;
if ( V_33 != V_59 && V_33 != V_57 )
return;
F_5 ( 4 , L_30 ,
V_2 -> V_16 . V_17 , V_2 -> V_33 ) ;
F_32 ( & V_4 -> V_88 , V_52 ) ;
V_2 -> V_33 = V_33 ;
F_33 ( & V_2 -> V_89 , & V_4 -> V_90 ) ;
F_34 ( & V_4 -> V_91 ) ;
F_35 ( & V_4 -> V_88 , V_52 ) ;
F_36 ( & V_4 -> V_92 ) ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_41 * V_42 ,
struct V_23 * V_12 )
{
unsigned int V_6 ;
int V_30 ;
if ( F_11 ( V_42 -> type ) ) {
V_30 = F_17 ( V_2 , V_42 ) ;
if ( V_30 )
return V_30 ;
if ( F_38 ( V_42 -> type ) ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
V_12 [ V_6 ] . V_48 =
V_42 -> V_26 . V_11 [ V_6 ] . V_48 ;
V_12 [ V_6 ] . V_93 =
V_42 -> V_26 . V_11 [ V_6 ] . V_93 ;
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
if ( F_38 ( V_42 -> type ) )
V_12 [ 0 ] . V_48 = V_42 -> V_48 ;
if ( V_42 -> V_29 == V_50 ) {
V_12 [ 0 ] . V_26 . V_51 = V_42 -> V_26 . V_51 ;
V_12 [ 0 ] . V_13 = V_42 -> V_13 ;
}
}
V_2 -> V_16 . V_94 = V_42 -> V_94 ;
V_2 -> V_16 . V_95 = V_42 -> V_95 ;
V_2 -> V_16 . V_46 = V_42 -> V_46 ;
V_2 -> V_16 . V_52 = V_42 -> V_52 & ~ V_53 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_23 V_11 [ V_44 ] ;
struct V_3 * V_4 = V_2 -> V_3 ;
void * V_5 ;
unsigned int V_6 ;
int V_30 ;
int V_96 = ! F_38 ( V_4 -> type ) ;
V_30 = F_37 ( V_2 , V_42 , V_11 ) ;
if ( V_30 )
return V_30 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_6 ] . V_26 . V_51 &&
V_2 -> V_12 [ V_6 ] . V_26 . V_51 == V_11 [ V_6 ] . V_26 . V_51
&& V_2 -> V_12 [ V_6 ] . V_13 == V_11 [ V_6 ] . V_13 )
continue;
F_5 ( 3 , L_31
L_32 , V_6 ) ;
if ( V_11 [ V_6 ] . V_13 < V_4 -> V_10 [ V_6 ] ) {
V_30 = - V_43 ;
goto V_97;
}
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_26 . V_51 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
V_5 = F_2 ( V_4 , V_67 , V_4 -> V_9 [ V_6 ] ,
V_11 [ V_6 ] . V_26 . V_51 ,
V_11 [ V_6 ] . V_13 , V_96 ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( 1 , L_33
L_34 , V_6 ) ;
V_30 = V_5 ? F_40 ( V_5 ) : - V_43 ;
goto V_97;
}
V_2 -> V_11 [ V_6 ] . V_5 = V_5 ;
}
V_30 = F_13 ( V_4 , V_36 , V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_35 ) ;
goto V_97;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 )
V_2 -> V_12 [ V_6 ] = V_11 [ V_6 ] ;
return 0 ;
V_97:
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; ++ V_6 ) {
if ( V_2 -> V_11 [ V_6 ] . V_5 )
F_2 ( V_4 , V_18 , V_2 -> V_11 [ V_6 ] . V_5 ) ;
V_2 -> V_11 [ V_6 ] . V_5 = NULL ;
V_2 -> V_12 [ V_6 ] . V_26 . V_51 = 0 ;
V_2 -> V_12 [ V_6 ] . V_13 = 0 ;
}
return V_30 ;
}
static int F_41 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
return F_37 ( V_2 , V_42 , V_2 -> V_12 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
V_2 -> V_33 = V_55 ;
F_43 ( & V_4 -> V_91 ) ;
V_4 -> V_38 -> V_98 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_30 ;
switch ( V_4 -> V_29 ) {
case V_35 :
V_30 = F_41 ( V_2 , V_42 ) ;
break;
case V_50 :
V_30 = F_39 ( V_2 , V_42 ) ;
break;
default:
F_45 ( 1 , L_36 ) ;
V_30 = - V_43 ;
}
if ( ! V_30 )
V_30 = F_13 ( V_4 , V_99 , V_2 ) ;
if ( V_30 )
F_5 ( 1 , L_37 , V_30 ) ;
else
V_2 -> V_33 = V_61 ;
return V_30 ;
}
int F_46 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
int V_30 ;
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_23 , V_80 ) ;
return - V_74 ;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_38 , V_80 ) ;
return - V_43 ;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_39 , V_80 ) ;
return - V_43 ;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_40 , V_80 ) ;
return - V_43 ;
}
if ( V_42 -> V_29 != V_4 -> V_29 ) {
F_5 ( 1 , L_41 , V_80 ) ;
return - V_43 ;
}
if ( V_2 -> V_33 != V_34 ) {
F_5 ( 1 , L_42 , V_80 , V_2 -> V_33 ) ;
return - V_43 ;
}
V_30 = F_44 ( V_2 , V_42 ) ;
if ( V_30 < 0 )
return V_30 ;
F_20 ( V_2 , V_42 ) ;
return 0 ;
}
int F_47 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_100 * V_101 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
if ( V_4 -> V_29 == V_50 ) {
V_101 = & V_102 -> V_103 -> V_101 ;
F_13 ( V_4 , V_104 , V_4 ) ;
F_48 ( V_101 ) ;
F_13 ( V_4 , V_105 , V_4 ) ;
}
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_43 ) ;
V_30 = - V_74 ;
goto V_106;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_44 ) ;
V_30 = - V_43 ;
goto V_106;
}
if ( V_42 -> V_17 >= V_4 -> V_22 ) {
F_5 ( 1 , L_45 ) ;
V_30 = - V_43 ;
goto V_106;
}
V_2 = V_4 -> V_25 [ V_42 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_46 ) ;
V_30 = - V_43 ;
goto V_106;
}
if ( V_42 -> V_29 != V_4 -> V_29 ) {
F_5 ( 1 , L_47 ) ;
V_30 = - V_43 ;
goto V_106;
}
switch ( V_2 -> V_33 ) {
case V_34 :
V_30 = F_44 ( V_2 , V_42 ) ;
if ( V_30 )
goto V_106;
case V_61 :
break;
default:
F_5 ( 1 , L_48 ) ;
V_30 = - V_43 ;
goto V_106;
}
F_33 ( & V_2 -> V_107 , & V_4 -> V_40 ) ;
V_2 -> V_33 = V_54 ;
if ( V_4 -> V_75 )
F_42 ( V_2 ) ;
F_20 ( V_2 , V_42 ) ;
F_5 ( 1 , L_49 , V_2 -> V_16 . V_17 ) ;
V_106:
if ( V_101 )
F_49 ( V_101 ) ;
return V_30 ;
}
static int F_50 ( struct V_3 * V_4 , int V_108 )
{
for (; ; ) {
int V_30 ;
if ( ! V_4 -> V_75 ) {
F_5 ( 1 , L_50 ) ;
return - V_43 ;
}
if ( ! F_51 ( & V_4 -> V_90 ) ) {
break;
}
if ( V_108 ) {
F_5 ( 1 , L_51
L_52 ) ;
return - V_109 ;
}
F_13 ( V_4 , V_104 , V_4 ) ;
F_5 ( 3 , L_53 ) ;
V_30 = F_52 ( V_4 -> V_92 ,
! F_51 ( & V_4 -> V_90 ) || ! V_4 -> V_75 ) ;
F_13 ( V_4 , V_105 , V_4 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_53 ( struct V_3 * V_4 , struct V_1 * * V_2 ,
int V_108 )
{
unsigned long V_52 ;
int V_30 ;
V_30 = F_50 ( V_4 , V_108 ) ;
if ( V_30 )
return V_30 ;
F_32 ( & V_4 -> V_88 , V_52 ) ;
* V_2 = F_54 ( & V_4 -> V_90 , struct V_1 , V_89 ) ;
F_55 ( & ( * V_2 ) -> V_89 ) ;
F_35 ( & V_4 -> V_88 , V_52 ) ;
return 0 ;
}
int F_56 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_75 ) {
F_5 ( 1 , L_50 ) ;
return - V_43 ;
}
F_57 ( V_4 -> V_92 , ! F_58 ( & V_4 -> V_91 ) ) ;
return 0 ;
}
int F_59 ( struct V_3 * V_4 , struct V_41 * V_42 , bool V_108 )
{
struct V_1 * V_2 = NULL ;
int V_30 ;
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_54 ) ;
return - V_74 ;
}
if ( V_42 -> type != V_4 -> type ) {
F_5 ( 1 , L_55 ) ;
return - V_43 ;
}
V_30 = F_53 ( V_4 , & V_2 , V_108 ) ;
if ( V_30 < 0 ) {
F_5 ( 1 , L_56 ) ;
return V_30 ;
}
V_30 = F_13 ( V_4 , V_110 , V_2 ) ;
if ( V_30 ) {
F_5 ( 1 , L_57 ) ;
return V_30 ;
}
switch ( V_2 -> V_33 ) {
case V_59 :
F_5 ( 3 , L_58 ) ;
break;
case V_57 :
F_5 ( 3 , L_59 ) ;
break;
default:
F_5 ( 1 , L_60 ) ;
return - V_43 ;
}
F_20 ( V_2 , V_42 ) ;
F_55 ( & V_2 -> V_107 ) ;
F_5 ( 1 , L_61 ,
V_2 -> V_16 . V_17 , V_2 -> V_33 ) ;
V_2 -> V_33 = V_34 ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
{
unsigned int V_111 ;
if ( V_4 -> V_75 )
F_13 ( V_4 , V_112 , V_4 ) ;
V_4 -> V_75 = 0 ;
F_16 ( & V_4 -> V_40 ) ;
F_16 ( & V_4 -> V_90 ) ;
F_61 ( & V_4 -> V_91 , 0 ) ;
F_62 ( & V_4 -> V_92 ) ;
for ( V_111 = 0 ; V_111 < V_4 -> V_22 ; ++ V_111 )
V_4 -> V_25 [ V_111 ] -> V_33 = V_34 ;
}
int F_63 ( struct V_3 * V_4 , enum V_113 type )
{
struct V_1 * V_2 ;
int V_30 ;
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_62 ) ;
return - V_74 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_63 ) ;
return - V_43 ;
}
if ( V_4 -> V_75 ) {
F_5 ( 1 , L_64 ) ;
return - V_74 ;
}
F_64 (vb, &q->queued_list, queued_entry)
F_42 ( V_2 ) ;
V_30 = F_13 ( V_4 , V_114 , V_4 , F_58 ( & V_4 -> V_91 ) ) ;
if ( V_30 ) {
F_5 ( 1 , L_65 ) ;
F_60 ( V_4 ) ;
return V_30 ;
}
V_4 -> V_75 = 1 ;
F_5 ( 3 , L_66 ) ;
return 0 ;
}
int F_65 ( struct V_3 * V_4 , enum V_113 type )
{
if ( V_4 -> V_73 ) {
F_5 ( 1 , L_67 ) ;
return - V_74 ;
}
if ( type != V_4 -> type ) {
F_5 ( 1 , L_68 ) ;
return - V_43 ;
}
if ( ! V_4 -> V_75 ) {
F_5 ( 1 , L_69 ) ;
return - V_43 ;
}
F_60 ( V_4 ) ;
F_5 ( 3 , L_70 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 , unsigned long V_21 ,
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
int F_67 ( struct V_3 * V_4 , struct V_117 * V_118 )
{
unsigned long V_21 = V_118 -> V_119 << V_120 ;
struct V_1 * V_2 ;
unsigned int V_20 , V_6 ;
int V_30 ;
if ( V_4 -> V_29 != V_35 ) {
F_5 ( 1 , L_71 ) ;
return - V_43 ;
}
if ( ! ( V_118 -> V_121 & V_122 ) ) {
F_5 ( 1 , L_72 ) ;
return - V_43 ;
}
if ( F_38 ( V_4 -> type ) ) {
if ( ! ( V_118 -> V_121 & V_123 ) ) {
F_5 ( 1 , L_73 ) ;
return - V_43 ;
}
} else {
if ( ! ( V_118 -> V_121 & V_124 ) ) {
F_5 ( 1 , L_74 ) ;
return - V_43 ;
}
}
V_30 = F_66 ( V_4 , V_21 , & V_20 , & V_6 ) ;
if ( V_30 )
return V_30 ;
V_2 = V_4 -> V_25 [ V_20 ] ;
V_30 = F_2 ( V_4 , V_69 , V_2 -> V_11 [ V_6 ] . V_5 , V_118 ) ;
if ( V_30 )
return V_30 ;
F_5 ( 3 , L_75 , V_20 , V_6 ) ;
return 0 ;
}
unsigned long F_68 ( struct V_3 * V_4 ,
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
F_5 ( 1 , L_71 ) ;
return - V_43 ;
}
V_30 = F_66 ( V_4 , V_21 , & V_20 , & V_6 ) ;
if ( V_30 )
return V_30 ;
V_2 = V_4 -> V_25 [ V_20 ] ;
return ( unsigned long ) F_29 ( V_2 , V_6 ) ;
}
unsigned int F_69 ( struct V_3 * V_4 , struct V_128 * V_128 , T_1 * V_129 )
{
struct V_130 * V_131 = F_70 ( V_128 ) ;
unsigned long V_132 = F_71 ( V_129 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_133 = 0 ;
unsigned long V_52 ;
if ( F_72 ( V_134 , & V_131 -> V_52 ) ) {
struct V_135 * V_136 = V_128 -> V_137 ;
if ( F_73 ( V_136 ) )
V_133 = V_138 ;
else if ( V_132 & V_138 )
F_74 ( V_128 , & V_136 -> V_129 , V_129 ) ;
}
if ( V_4 -> V_22 == 0 && V_4 -> V_73 == NULL ) {
if ( ! F_38 ( V_4 -> type ) && ( V_4 -> V_64 & V_139 ) &&
( V_132 & ( V_140 | V_141 ) ) ) {
if ( F_75 ( V_4 , 1 ) )
return V_133 | V_142 ;
}
if ( F_38 ( V_4 -> type ) && ( V_4 -> V_64 & V_143 ) &&
( V_132 & ( V_144 | V_145 ) ) ) {
if ( F_75 ( V_4 , 0 ) )
return V_133 | V_142 ;
return V_133 | V_144 | V_145 ;
}
}
if ( F_51 ( & V_4 -> V_40 ) )
return V_133 | V_142 ;
F_74 ( V_128 , & V_4 -> V_92 , V_129 ) ;
F_32 ( & V_4 -> V_88 , V_52 ) ;
if ( ! F_51 ( & V_4 -> V_90 ) )
V_2 = F_54 ( & V_4 -> V_90 , struct V_1 ,
V_89 ) ;
F_35 ( & V_4 -> V_88 , V_52 ) ;
if ( V_2 && ( V_2 -> V_33 == V_59
|| V_2 -> V_33 == V_57 ) ) {
return ( F_38 ( V_4 -> type ) ) ?
V_133 | V_144 | V_145 :
V_133 | V_140 | V_141 ;
}
return V_133 ;
}
int F_76 ( struct V_3 * V_4 )
{
F_77 ( ! V_4 ) ;
F_77 ( ! V_4 -> V_38 ) ;
F_77 ( ! V_4 -> V_66 ) ;
F_77 ( ! V_4 -> type ) ;
F_77 ( ! V_4 -> V_64 ) ;
F_77 ( ! V_4 -> V_38 -> V_77 ) ;
F_77 ( ! V_4 -> V_38 -> V_98 ) ;
F_16 ( & V_4 -> V_40 ) ;
F_16 ( & V_4 -> V_90 ) ;
F_78 ( & V_4 -> V_88 ) ;
F_79 ( & V_4 -> V_92 ) ;
if ( V_4 -> V_31 == 0 )
V_4 -> V_31 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_80 ( struct V_3 * V_4 )
{
F_81 ( V_4 ) ;
F_60 ( V_4 ) ;
F_15 ( V_4 , V_4 -> V_22 ) ;
}
static int F_75 ( struct V_3 * V_4 , int V_146 )
{
struct V_147 * V_73 ;
int V_111 , V_30 ;
unsigned int V_76 = 0 ;
if ( ( V_146 && ! ( V_4 -> V_64 & V_139 ) ) ||
( ! V_146 && ! ( V_4 -> V_64 & V_143 ) ) )
F_82 () ;
if ( ! V_4 -> V_66 -> V_85 )
return - V_74 ;
if ( V_4 -> V_75 || V_4 -> V_22 > 0 )
return - V_74 ;
V_76 = 1 ;
F_5 ( 3 , L_76 ,
( V_146 ) ? L_77 : L_78 , V_76 , V_4 -> V_148 ) ;
V_73 = F_10 ( sizeof( struct V_147 ) , V_32 ) ;
if ( V_73 == NULL )
return - V_15 ;
V_73 -> V_52 = V_4 -> V_148 ;
V_73 -> V_71 . V_76 = V_76 ;
V_73 -> V_71 . V_29 = V_35 ;
V_73 -> V_71 . type = V_4 -> type ;
V_30 = F_25 ( V_4 , & V_73 -> V_71 ) ;
if ( V_30 )
goto V_149;
if ( V_4 -> V_25 [ 0 ] -> V_7 != 1 ) {
V_30 = - V_74 ;
goto V_150;
}
for ( V_111 = 0 ; V_111 < V_4 -> V_22 ; V_111 ++ ) {
V_73 -> V_25 [ V_111 ] . V_85 = F_29 ( V_4 -> V_25 [ V_111 ] , 0 ) ;
if ( V_73 -> V_25 [ V_111 ] . V_85 == NULL )
goto V_150;
V_73 -> V_25 [ V_111 ] . V_151 = F_83 ( V_4 -> V_25 [ V_111 ] , 0 ) ;
}
if ( V_146 ) {
for ( V_111 = 0 ; V_111 < V_4 -> V_22 ; V_111 ++ ) {
struct V_41 * V_42 = & V_73 -> V_42 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> type = V_4 -> type ;
V_42 -> V_29 = V_4 -> V_29 ;
V_42 -> V_17 = V_111 ;
V_30 = F_47 ( V_4 , V_42 ) ;
if ( V_30 )
goto V_150;
V_73 -> V_25 [ V_111 ] . V_152 = 1 ;
}
V_30 = F_63 ( V_4 , V_4 -> type ) ;
if ( V_30 )
goto V_150;
}
V_4 -> V_73 = V_73 ;
return V_30 ;
V_150:
V_73 -> V_71 . V_76 = 0 ;
F_25 ( V_4 , & V_73 -> V_71 ) ;
V_149:
F_12 ( V_73 ) ;
return V_30 ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_147 * V_73 = V_4 -> V_73 ;
if ( V_73 ) {
V_4 -> V_73 = NULL ;
F_65 ( V_4 , V_4 -> type ) ;
V_73 -> V_71 . V_76 = 0 ;
F_25 ( V_4 , & V_73 -> V_71 ) ;
F_12 ( V_73 ) ;
F_5 ( 3 , L_79 ) ;
}
return 0 ;
}
static T_2 F_84 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_76 ,
T_4 * V_154 , int V_155 , int V_146 )
{
struct V_147 * V_73 ;
struct V_156 * V_157 ;
int V_30 , V_17 ;
F_5 ( 3 , L_80 ,
V_146 ? L_77 : L_78 , ( long ) * V_154 , V_76 ,
V_155 ? L_81 : L_82 ) ;
if ( ! V_153 )
return - V_43 ;
if ( ! V_4 -> V_73 ) {
V_30 = F_75 ( V_4 , V_146 ) ;
F_5 ( 3 , L_83 , V_30 ) ;
if ( V_30 )
return V_30 ;
}
V_73 = V_4 -> V_73 ;
V_4 -> V_73 = NULL ;
V_17 = V_73 -> V_17 ;
V_157 = & V_73 -> V_25 [ V_17 ] ;
if ( V_157 -> V_152 ) {
struct V_1 * V_2 ;
memset ( & V_73 -> V_42 , 0 , sizeof( V_73 -> V_42 ) ) ;
V_73 -> V_42 . type = V_4 -> type ;
V_73 -> V_42 . V_29 = V_4 -> V_29 ;
V_73 -> V_42 . V_17 = V_17 ;
V_30 = F_59 ( V_4 , & V_73 -> V_42 , V_155 ) ;
F_5 ( 5 , L_84 , V_30 ) ;
if ( V_30 )
goto V_158;
V_73 -> V_159 += 1 ;
V_2 = V_4 -> V_25 [ V_17 ] ;
V_157 -> V_151 = F_85 ( V_2 , 0 ) ;
V_157 -> V_152 = 0 ;
}
if ( V_157 -> V_160 + V_76 > V_157 -> V_151 ) {
V_76 = V_157 -> V_151 - V_157 -> V_160 ;
F_5 ( 5 , L_85 , V_76 ) ;
}
F_5 ( 3 , L_86 ,
V_76 , V_17 , V_157 -> V_160 ) ;
if ( V_146 )
V_30 = F_86 ( V_153 , V_157 -> V_85 + V_157 -> V_160 , V_76 ) ;
else
V_30 = F_87 ( V_157 -> V_85 + V_157 -> V_160 , V_153 , V_76 ) ;
if ( V_30 ) {
F_5 ( 3 , L_87 ) ;
V_30 = - V_161 ;
goto V_158;
}
V_157 -> V_160 += V_76 ;
* V_154 += V_76 ;
if ( V_157 -> V_160 == V_157 -> V_151 ||
( ! V_146 && ( V_73 -> V_52 & V_162 ) ) ) {
if ( V_146 && ( V_73 -> V_52 & V_163 ) &&
V_73 -> V_159 == 1 ) {
F_5 ( 3 , L_88 ) ;
V_4 -> V_73 = V_73 ;
return F_81 ( V_4 ) ;
}
memset ( & V_73 -> V_42 , 0 , sizeof( V_73 -> V_42 ) ) ;
V_73 -> V_42 . type = V_4 -> type ;
V_73 -> V_42 . V_29 = V_4 -> V_29 ;
V_73 -> V_42 . V_17 = V_17 ;
V_73 -> V_42 . V_48 = V_157 -> V_160 ;
V_30 = F_47 ( V_4 , & V_73 -> V_42 ) ;
F_5 ( 5 , L_89 , V_30 ) ;
if ( V_30 )
goto V_158;
V_157 -> V_160 = 0 ;
V_157 -> V_152 = 1 ;
V_157 -> V_151 = V_4 -> V_25 [ 0 ] -> V_12 [ 0 ] . V_13 ;
V_73 -> V_164 += 1 ;
V_73 -> V_17 = ( V_17 + 1 ) % V_4 -> V_22 ;
if ( ! V_146 && ! V_4 -> V_75 ) {
V_30 = F_63 ( V_4 , V_4 -> type ) ;
if ( V_30 )
goto V_158;
}
}
if ( V_30 == 0 )
V_30 = V_76 ;
V_158:
V_4 -> V_73 = V_73 ;
return V_30 ;
}
T_2 F_88 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_76 ,
T_4 * V_154 , int V_108 )
{
return F_84 ( V_4 , V_153 , V_76 , V_154 , V_108 , 1 ) ;
}
T_2 F_89 ( struct V_3 * V_4 , char T_3 * V_153 , T_2 V_76 ,
T_4 * V_154 , int V_108 )
{
return F_84 ( V_4 , V_153 , V_76 , V_154 , V_108 , 0 ) ;
}
