static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
void * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
V_6 = F_2 ( V_5 , V_7 , V_9 , V_5 -> V_10 [ V_7 ] ,
V_3 [ V_7 ] ) ;
if ( F_3 ( V_6 ) )
goto free;
V_2 -> V_11 [ V_7 ] . V_6 = V_6 ;
V_2 -> V_12 [ V_7 ] . V_13 = V_3 [ V_7 ] ;
}
return 0 ;
free:
for (; V_7 > 0 ; -- V_7 )
F_2 ( V_5 , V_7 , V_14 , V_2 -> V_11 [ V_7 - 1 ] . V_6 ) ;
return - V_15 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
F_2 ( V_5 , V_7 , V_14 , V_2 -> V_11 [ V_7 ] . V_6 ) ;
V_2 -> V_11 [ V_7 ] . V_6 = NULL ;
F_5 ( 3 , L_1 ,
V_7 , V_2 -> V_16 . V_17 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
void * V_6 = V_2 -> V_11 [ V_7 ] . V_6 ;
if ( V_6 ) {
F_2 ( V_5 , V_7 , V_18 , V_6 ) ;
V_2 -> V_11 [ V_7 ] . V_6 = NULL ;
}
}
}
static void F_7 ( struct V_4 * V_5 )
{
unsigned int V_19 , V_7 ;
struct V_1 * V_2 ;
unsigned long V_20 = 0 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
V_2 = V_5 -> V_22 [ V_19 ] ;
if ( ! V_2 )
continue;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
V_2 -> V_12 [ V_7 ] . V_23 . V_24 = V_20 ;
F_5 ( 3 , L_2 ,
V_19 , V_7 , V_20 ) ;
V_20 += V_2 -> V_12 [ V_7 ] . V_13 ;
V_20 = F_8 ( V_20 ) ;
}
}
}
static int F_9 ( struct V_4 * V_5 , enum V_25 V_26 ,
unsigned int V_21 , unsigned int V_8 ,
unsigned long V_3 [] )
{
unsigned int V_19 ;
struct V_1 * V_2 ;
int V_27 ;
for ( V_19 = 0 ; V_19 < V_21 ; ++ V_19 ) {
V_2 = F_10 ( V_5 -> V_28 , V_29 ) ;
if ( ! V_2 ) {
F_5 ( 1 , L_3 ) ;
break;
}
if ( F_11 ( V_5 -> type ) )
V_2 -> V_16 . V_13 = V_8 ;
V_2 -> V_30 = V_31 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_16 . V_17 = V_19 ;
V_2 -> V_16 . type = V_5 -> type ;
V_2 -> V_16 . V_26 = V_26 ;
if ( V_26 == V_32 ) {
V_27 = F_1 ( V_2 , V_3 ) ;
if ( V_27 ) {
F_5 ( 1 , L_4
L_5 , V_19 ) ;
F_12 ( V_2 ) ;
break;
}
V_27 = F_13 ( V_5 , V_33 , V_2 ) ;
if ( V_27 ) {
F_5 ( 1 , L_6
L_7 , V_19 , V_2 ) ;
F_4 ( V_2 ) ;
F_12 ( V_2 ) ;
break;
}
}
V_5 -> V_22 [ V_19 ] = V_2 ;
}
V_5 -> V_21 = V_19 ;
F_7 ( V_5 ) ;
F_5 ( 1 , L_8 ,
V_5 -> V_21 , V_8 ) ;
return V_19 ;
}
static void F_14 ( struct V_4 * V_5 )
{
unsigned int V_19 ;
struct V_1 * V_2 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
V_2 = V_5 -> V_22 [ V_19 ] ;
if ( ! V_2 )
continue;
if ( V_5 -> V_26 == V_32 )
F_4 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
}
static void F_15 ( struct V_4 * V_5 )
{
unsigned int V_19 ;
if ( V_5 -> V_34 -> V_35 ) {
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
if ( NULL == V_5 -> V_22 [ V_19 ] )
continue;
V_5 -> V_34 -> V_35 ( V_5 -> V_22 [ V_19 ] ) ;
}
}
F_14 ( V_5 ) ;
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
F_12 ( V_5 -> V_22 [ V_19 ] ) ;
V_5 -> V_22 [ V_19 ] = NULL ;
}
V_5 -> V_21 = 0 ;
V_5 -> V_26 = 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
if ( NULL == V_37 -> V_23 . V_11 ) {
F_5 ( 1 , L_9
L_10 ) ;
return - V_38 ;
}
if ( V_37 -> V_13 < V_2 -> V_8 || V_37 -> V_13 > V_39 ) {
F_5 ( 1 , L_11
L_12 , V_2 -> V_8 , V_37 -> V_13 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
int V_27 = 0 ;
memcpy ( V_37 , & V_2 -> V_16 , F_18 ( struct V_36 , V_23 ) ) ;
V_37 -> V_40 = V_2 -> V_16 . V_40 ;
V_37 -> V_41 = V_2 -> V_16 . V_41 ;
if ( F_11 ( V_5 -> type ) ) {
V_27 = F_16 ( V_2 , V_37 ) ;
if ( V_27 )
return V_27 ;
memcpy ( V_37 -> V_23 . V_11 , V_2 -> V_12 ,
V_37 -> V_13 * sizeof( struct V_42 ) ) ;
} else {
V_37 -> V_13 = V_2 -> V_12 [ 0 ] . V_13 ;
V_37 -> V_43 = V_2 -> V_12 [ 0 ] . V_43 ;
if ( V_5 -> V_26 == V_32 )
V_37 -> V_23 . V_44 = V_2 -> V_12 [ 0 ] . V_23 . V_24 ;
else if ( V_5 -> V_26 == V_45 )
V_37 -> V_23 . V_46 = V_2 -> V_12 [ 0 ] . V_23 . V_46 ;
}
V_37 -> V_47 &= ~ V_48 ;
switch ( V_2 -> V_30 ) {
case V_49 :
case V_50 :
V_37 -> V_47 |= V_51 ;
break;
case V_52 :
V_37 -> V_47 |= V_53 ;
case V_54 :
V_37 -> V_47 |= V_55 ;
break;
case V_31 :
break;
}
if ( V_2 -> V_56 == V_2 -> V_8 )
V_37 -> V_47 |= V_57 ;
return V_27 ;
}
int F_19 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_1 * V_2 ;
if ( V_37 -> type != V_5 -> type ) {
F_5 ( 1 , L_13 ) ;
return - V_38 ;
}
if ( V_37 -> V_17 >= V_5 -> V_21 ) {
F_5 ( 1 , L_14 ) ;
return - V_38 ;
}
V_2 = V_5 -> V_22 [ V_37 -> V_17 ] ;
return F_17 ( V_2 , V_37 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_58 & V_59 ) || ! V_5 -> V_60 -> V_61 ||
! V_5 -> V_60 -> V_18 )
return - V_38 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_58 & V_62 ) || ! V_5 -> V_60 -> V_9 ||
! V_5 -> V_60 -> V_14 || ! V_5 -> V_60 -> V_63 )
return - V_38 ;
return 0 ;
}
static bool F_22 ( struct V_4 * V_5 )
{
unsigned int V_19 , V_7 ;
struct V_1 * V_2 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
V_2 = V_5 -> V_22 [ V_19 ] ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
if ( F_2 ( V_5 , V_7 , V_64 ,
V_2 -> V_11 [ V_7 ] . V_6 ) > 1 )
return true ;
}
}
return false ;
}
int F_23 ( struct V_4 * V_5 , struct V_65 * V_66 )
{
unsigned int V_21 , V_8 ;
unsigned long V_3 [ V_39 ] ;
int V_27 = 0 ;
if ( V_5 -> V_67 ) {
F_5 ( 1 , L_15 ) ;
return - V_68 ;
}
if ( V_66 -> V_26 != V_32
&& V_66 -> V_26 != V_45 ) {
F_5 ( 1 , L_16 ) ;
return - V_38 ;
}
if ( V_66 -> type != V_5 -> type ) {
F_5 ( 1 , L_17 ) ;
return - V_38 ;
}
if ( V_5 -> V_69 ) {
F_5 ( 1 , L_18 ) ;
return - V_68 ;
}
if ( V_66 -> V_26 == V_32 && F_21 ( V_5 ) ) {
F_5 ( 1 , L_19 ) ;
return - V_38 ;
}
if ( V_66 -> V_26 == V_45 && F_20 ( V_5 ) ) {
F_5 ( 1 , L_20 ) ;
return - V_38 ;
}
if ( V_66 -> V_70 == 0 || V_5 -> V_21 != 0 || V_5 -> V_26 != V_66 -> V_26 ) {
if ( V_5 -> V_26 == V_32 && F_22 ( V_5 ) ) {
F_5 ( 1 , L_21 ) ;
return - V_68 ;
}
F_15 ( V_5 ) ;
if ( V_66 -> V_70 == 0 )
return 0 ;
}
V_21 = F_24 (unsigned int, req->count, VIDEO_MAX_FRAME) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
memset ( V_5 -> V_10 , 0 , sizeof( V_5 -> V_10 ) ) ;
V_5 -> V_26 = V_66 -> V_26 ;
V_27 = F_13 ( V_5 , V_71 , V_5 , & V_21 , & V_8 ,
V_3 , V_5 -> V_10 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_9 ( V_5 , V_66 -> V_26 , V_21 , V_8 ,
V_3 ) ;
if ( V_27 == 0 ) {
F_5 ( 1 , L_22 ) ;
return - V_15 ;
}
if ( V_27 < V_21 ) {
unsigned int V_72 ;
V_72 = V_21 = V_27 ;
V_27 = F_13 ( V_5 , V_71 , V_5 , & V_21 , & V_8 ,
V_3 , V_5 -> V_10 ) ;
if ( V_27 )
goto V_73;
if ( V_72 < V_21 ) {
V_27 = - V_15 ;
goto V_73;
}
V_27 = V_21 ;
}
V_66 -> V_70 = V_27 ;
return 0 ;
V_73:
F_15 ( V_5 ) ;
return V_27 ;
}
void * F_25 ( struct V_1 * V_2 , unsigned int V_74 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
if ( V_74 > V_2 -> V_8 )
return NULL ;
return F_2 ( V_5 , V_74 , V_75 , V_2 -> V_11 [ V_74 ] . V_6 ) ;
}
void * F_26 ( struct V_1 * V_2 , unsigned int V_74 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
if ( V_74 > V_2 -> V_8 )
return NULL ;
return F_2 ( V_5 , V_74 , V_76 , V_2 -> V_11 [ V_74 ] . V_6 ) ;
}
void F_27 ( struct V_1 * V_2 , enum V_77 V_30 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
unsigned long V_47 ;
if ( V_2 -> V_30 != V_50 )
return;
if ( V_30 != V_54 && V_30 != V_52 )
return;
F_5 ( 4 , L_23 ,
V_2 -> V_16 . V_17 , V_2 -> V_30 ) ;
F_28 ( & V_5 -> V_78 , V_47 ) ;
V_2 -> V_30 = V_30 ;
F_29 ( & V_2 -> V_79 , & V_5 -> V_80 ) ;
F_30 ( & V_5 -> V_81 ) ;
F_31 ( & V_5 -> V_78 , V_47 ) ;
F_32 ( & V_5 -> V_82 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_42 * V_12 )
{
unsigned int V_7 ;
int V_27 ;
if ( F_11 ( V_37 -> type ) ) {
V_27 = F_16 ( V_2 , V_37 ) ;
if ( V_27 )
return V_27 ;
if ( F_34 ( V_37 -> type ) ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
V_12 [ V_7 ] . V_43 =
V_37 -> V_23 . V_11 [ V_7 ] . V_43 ;
V_12 [ V_7 ] . V_83 =
V_37 -> V_23 . V_11 [ V_7 ] . V_83 ;
}
}
if ( V_37 -> V_26 == V_45 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
V_12 [ V_7 ] . V_23 . V_46 =
V_37 -> V_23 . V_11 [ V_7 ] . V_23 . V_46 ;
V_12 [ V_7 ] . V_13 =
V_37 -> V_23 . V_11 [ V_7 ] . V_13 ;
}
}
} else {
if ( F_34 ( V_37 -> type ) )
V_12 [ 0 ] . V_43 = V_37 -> V_43 ;
if ( V_37 -> V_26 == V_45 ) {
V_12 [ 0 ] . V_23 . V_46 = V_37 -> V_23 . V_46 ;
V_12 [ 0 ] . V_13 = V_37 -> V_13 ;
}
}
V_2 -> V_16 . V_84 = V_37 -> V_84 ;
V_2 -> V_16 . V_85 = V_37 -> V_85 ;
V_2 -> V_16 . V_40 = V_37 -> V_40 ;
V_2 -> V_16 . V_47 = V_37 -> V_47 & ~ V_48 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_42 V_11 [ V_39 ] ;
struct V_4 * V_5 = V_2 -> V_4 ;
void * V_6 ;
unsigned int V_7 ;
int V_27 ;
int V_86 = ! F_34 ( V_5 -> type ) ;
V_27 = F_33 ( V_2 , V_37 , V_11 ) ;
if ( V_27 )
return V_27 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
if ( V_2 -> V_12 [ V_7 ] . V_23 . V_46 == V_11 [ V_7 ] . V_23 . V_46
&& V_2 -> V_12 [ V_7 ] . V_13 == V_11 [ V_7 ] . V_13 )
continue;
F_5 ( 3 , L_24
L_25 , V_7 ) ;
if ( V_2 -> V_11 [ V_7 ] . V_6 )
F_2 ( V_5 , V_7 , V_18 ,
V_2 -> V_11 [ V_7 ] . V_6 ) ;
V_2 -> V_11 [ V_7 ] . V_6 = NULL ;
if ( V_5 -> V_60 -> V_61 ) {
V_6 = V_5 -> V_60 -> V_61 ( V_5 -> V_10 [ V_7 ] ,
V_11 [ V_7 ] . V_23 . V_46 ,
V_11 [ V_7 ] . V_13 ,
V_86 ) ;
if ( F_36 ( V_6 ) ) {
F_5 ( 1 , L_26
L_27 , V_7 ) ;
V_27 = F_37 ( V_6 ) ;
goto V_87;
}
V_2 -> V_11 [ V_7 ] . V_6 = V_6 ;
}
}
V_27 = F_13 ( V_5 , V_33 , V_2 ) ;
if ( V_27 ) {
F_5 ( 1 , L_28 ) ;
goto V_87;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 )
V_2 -> V_12 [ V_7 ] = V_11 [ V_7 ] ;
return 0 ;
V_87:
for (; V_7 > 0 ; -- V_7 ) {
F_2 ( V_5 , V_7 , V_18 ,
V_2 -> V_11 [ V_7 - 1 ] . V_6 ) ;
V_2 -> V_11 [ V_7 - 1 ] . V_6 = NULL ;
}
return V_27 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
return F_33 ( V_2 , V_37 , V_2 -> V_12 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
V_2 -> V_30 = V_50 ;
F_40 ( & V_5 -> V_81 ) ;
V_5 -> V_34 -> V_88 ( V_2 ) ;
}
int F_41 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_5 -> V_67 ) {
F_5 ( 1 , L_29 ) ;
return - V_68 ;
}
if ( V_37 -> type != V_5 -> type ) {
F_5 ( 1 , L_30 ) ;
return - V_38 ;
}
if ( V_37 -> V_17 >= V_5 -> V_21 ) {
F_5 ( 1 , L_31 ) ;
return - V_38 ;
}
V_2 = V_5 -> V_22 [ V_37 -> V_17 ] ;
if ( NULL == V_2 ) {
F_5 ( 1 , L_32 ) ;
return - V_38 ;
}
if ( V_37 -> V_26 != V_5 -> V_26 ) {
F_5 ( 1 , L_33 ) ;
return - V_38 ;
}
if ( V_2 -> V_30 != V_31 ) {
F_5 ( 1 , L_34 ) ;
return - V_38 ;
}
if ( V_5 -> V_26 == V_32 )
V_27 = F_38 ( V_2 , V_37 ) ;
else if ( V_5 -> V_26 == V_45 )
V_27 = F_35 ( V_2 , V_37 ) ;
else {
F_42 ( 1 , L_35 ) ;
return - V_38 ;
}
if ( V_27 )
return V_27 ;
V_27 = F_13 ( V_5 , V_89 , V_2 ) ;
if ( V_27 ) {
F_5 ( 1 , L_36 ) ;
return V_27 ;
}
F_29 ( & V_2 -> V_90 , & V_5 -> V_91 ) ;
V_2 -> V_30 = V_49 ;
if ( V_5 -> V_69 )
F_39 ( V_2 ) ;
F_5 ( 1 , L_37 , V_2 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 , int V_92 )
{
for (; ; ) {
int V_27 ;
if ( ! V_5 -> V_69 ) {
F_5 ( 1 , L_38 ) ;
return - V_38 ;
}
if ( ! F_44 ( & V_5 -> V_80 ) ) {
break;
}
if ( V_92 ) {
F_5 ( 1 , L_39
L_40 ) ;
return - V_93 ;
}
F_13 ( V_5 , V_94 , V_5 ) ;
F_5 ( 3 , L_41 ) ;
V_27 = F_45 ( V_5 -> V_82 ,
! F_44 ( & V_5 -> V_80 ) || ! V_5 -> V_69 ) ;
F_13 ( V_5 , V_95 , V_5 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_1 * * V_2 ,
int V_92 )
{
unsigned long V_47 ;
int V_27 ;
V_27 = F_43 ( V_5 , V_92 ) ;
if ( V_27 )
return V_27 ;
F_28 ( & V_5 -> V_78 , V_47 ) ;
* V_2 = F_47 ( & V_5 -> V_80 , struct V_1 , V_79 ) ;
F_48 ( & ( * V_2 ) -> V_79 ) ;
F_31 ( & V_5 -> V_78 , V_47 ) ;
return 0 ;
}
int F_49 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_69 ) {
F_5 ( 1 , L_38 ) ;
return - V_38 ;
}
F_50 ( V_5 -> V_82 , ! F_51 ( & V_5 -> V_81 ) ) ;
return 0 ;
}
int F_52 ( struct V_4 * V_5 , struct V_36 * V_37 , bool V_92 )
{
struct V_1 * V_2 = NULL ;
int V_27 ;
if ( V_5 -> V_67 ) {
F_5 ( 1 , L_42 ) ;
return - V_68 ;
}
if ( V_37 -> type != V_5 -> type ) {
F_5 ( 1 , L_43 ) ;
return - V_38 ;
}
V_27 = F_46 ( V_5 , & V_2 , V_92 ) ;
if ( V_27 < 0 ) {
F_5 ( 1 , L_44 ) ;
return V_27 ;
}
V_27 = F_13 ( V_5 , V_96 , V_2 ) ;
if ( V_27 ) {
F_5 ( 1 , L_45 ) ;
return V_27 ;
}
switch ( V_2 -> V_30 ) {
case V_54 :
F_5 ( 3 , L_46 ) ;
break;
case V_52 :
F_5 ( 3 , L_47 ) ;
break;
default:
F_5 ( 1 , L_48 ) ;
return - V_38 ;
}
F_17 ( V_2 , V_37 ) ;
F_48 ( & V_2 -> V_90 ) ;
F_5 ( 1 , L_49 ,
V_2 -> V_16 . V_17 , V_2 -> V_30 ) ;
V_2 -> V_30 = V_31 ;
return 0 ;
}
int F_53 ( struct V_4 * V_5 , enum V_97 type )
{
struct V_1 * V_2 ;
int V_27 ;
if ( V_5 -> V_67 ) {
F_5 ( 1 , L_50 ) ;
return - V_68 ;
}
if ( type != V_5 -> type ) {
F_5 ( 1 , L_51 ) ;
return - V_38 ;
}
if ( V_5 -> V_69 ) {
F_5 ( 1 , L_52 ) ;
return - V_68 ;
}
if ( F_34 ( V_5 -> type ) ) {
if ( F_44 ( & V_5 -> V_91 ) ) {
F_5 ( 1 , L_53 ) ;
return - V_38 ;
}
}
V_27 = F_13 ( V_5 , V_98 , V_5 ) ;
if ( V_27 ) {
F_5 ( 1 , L_54 ) ;
return V_27 ;
}
V_5 -> V_69 = 1 ;
F_54 (vb, &q->queued_list, queued_entry)
F_39 ( V_2 ) ;
F_5 ( 3 , L_55 ) ;
return 0 ;
}
static void F_55 ( struct V_4 * V_5 )
{
unsigned int V_99 ;
if ( V_5 -> V_69 )
F_13 ( V_5 , V_100 , V_5 ) ;
V_5 -> V_69 = 0 ;
F_56 ( & V_5 -> V_91 ) ;
F_56 ( & V_5 -> V_80 ) ;
F_57 ( & V_5 -> V_81 , 0 ) ;
F_58 ( & V_5 -> V_82 ) ;
for ( V_99 = 0 ; V_99 < V_5 -> V_21 ; ++ V_99 )
V_5 -> V_22 [ V_99 ] -> V_30 = V_31 ;
}
int F_59 ( struct V_4 * V_5 , enum V_97 type )
{
if ( V_5 -> V_67 ) {
F_5 ( 1 , L_56 ) ;
return - V_68 ;
}
if ( type != V_5 -> type ) {
F_5 ( 1 , L_57 ) ;
return - V_38 ;
}
if ( ! V_5 -> V_69 ) {
F_5 ( 1 , L_58 ) ;
return - V_38 ;
}
F_55 ( V_5 ) ;
F_5 ( 3 , L_59 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 , unsigned long V_20 ,
unsigned int * V_101 , unsigned int * V_102 )
{
struct V_1 * V_2 ;
unsigned int V_19 , V_7 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_21 ; ++ V_19 ) {
V_2 = V_5 -> V_22 [ V_19 ] ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
if ( V_2 -> V_12 [ V_7 ] . V_23 . V_24 == V_20 ) {
* V_101 = V_19 ;
* V_102 = V_7 ;
return 0 ;
}
}
}
return - V_38 ;
}
int F_61 ( struct V_4 * V_5 , struct V_103 * V_104 )
{
unsigned long V_20 = V_104 -> V_105 << V_106 ;
struct V_107 * V_108 ;
struct V_1 * V_2 ;
unsigned int V_19 , V_7 ;
int V_27 ;
if ( V_5 -> V_26 != V_32 ) {
F_5 ( 1 , L_60 ) ;
return - V_38 ;
}
if ( ! ( V_104 -> V_109 & V_110 ) ) {
F_5 ( 1 , L_61 ) ;
return - V_38 ;
}
if ( F_34 ( V_5 -> type ) ) {
if ( ! ( V_104 -> V_109 & V_111 ) ) {
F_5 ( 1 , L_62 ) ;
return - V_38 ;
}
} else {
if ( ! ( V_104 -> V_109 & V_112 ) ) {
F_5 ( 1 , L_63 ) ;
return - V_38 ;
}
}
V_27 = F_60 ( V_5 , V_20 , & V_19 , & V_7 ) ;
if ( V_27 )
return V_27 ;
V_2 = V_5 -> V_22 [ V_19 ] ;
V_108 = & V_2 -> V_11 [ V_7 ] ;
V_27 = V_5 -> V_60 -> V_63 ( V_108 -> V_6 , V_104 ) ;
if ( V_27 )
return V_27 ;
V_108 -> V_113 = 1 ;
V_2 -> V_56 ++ ;
F_5 ( 3 , L_64 , V_19 , V_7 ) ;
return 0 ;
}
unsigned int F_62 ( struct V_4 * V_5 , struct V_114 * V_114 , T_1 * V_115 )
{
unsigned long V_47 ;
unsigned int V_27 ;
struct V_1 * V_2 = NULL ;
if ( V_5 -> V_21 == 0 && V_5 -> V_67 == NULL ) {
if ( ! F_34 ( V_5 -> type ) && ( V_5 -> V_58 & V_116 ) ) {
V_27 = F_63 ( V_5 , 1 ) ;
if ( V_27 )
return V_117 ;
}
if ( F_34 ( V_5 -> type ) && ( V_5 -> V_58 & V_118 ) ) {
V_27 = F_63 ( V_5 , 0 ) ;
if ( V_27 )
return V_117 ;
return V_119 | V_120 ;
}
}
if ( F_44 ( & V_5 -> V_91 ) )
return V_117 ;
F_64 ( V_114 , & V_5 -> V_82 , V_115 ) ;
F_28 ( & V_5 -> V_78 , V_47 ) ;
if ( ! F_44 ( & V_5 -> V_80 ) )
V_2 = F_47 ( & V_5 -> V_80 , struct V_1 ,
V_79 ) ;
F_31 ( & V_5 -> V_78 , V_47 ) ;
if ( V_2 && ( V_2 -> V_30 == V_54
|| V_2 -> V_30 == V_52 ) ) {
return ( F_34 ( V_5 -> type ) ) ? V_119 | V_120 :
V_121 | V_122 ;
}
return 0 ;
}
int F_65 ( struct V_4 * V_5 )
{
F_66 ( ! V_5 ) ;
F_66 ( ! V_5 -> V_34 ) ;
F_66 ( ! V_5 -> V_60 ) ;
F_66 ( ! V_5 -> type ) ;
F_66 ( ! V_5 -> V_58 ) ;
F_66 ( ! V_5 -> V_34 -> V_71 ) ;
F_66 ( ! V_5 -> V_34 -> V_88 ) ;
F_56 ( & V_5 -> V_91 ) ;
F_56 ( & V_5 -> V_80 ) ;
F_67 ( & V_5 -> V_78 ) ;
F_68 ( & V_5 -> V_82 ) ;
if ( V_5 -> V_28 == 0 )
V_5 -> V_28 = sizeof( struct V_1 ) ;
return 0 ;
}
void F_69 ( struct V_4 * V_5 )
{
F_70 ( V_5 ) ;
F_55 ( V_5 ) ;
F_15 ( V_5 ) ;
}
static int F_63 ( struct V_4 * V_5 , int V_123 )
{
struct V_124 * V_67 ;
int V_99 , V_27 ;
unsigned int V_70 = 0 ;
if ( ( V_123 && ! ( V_5 -> V_58 & V_116 ) ) ||
( ! V_123 && ! ( V_5 -> V_58 & V_118 ) ) )
F_71 () ;
if ( ! V_5 -> V_60 -> V_75 )
return - V_68 ;
if ( V_5 -> V_69 || V_5 -> V_21 > 0 )
return - V_68 ;
V_70 = 1 ;
F_5 ( 3 , L_65 ,
( V_123 ) ? L_66 : L_67 , V_70 , V_5 -> V_125 ) ;
V_67 = F_10 ( sizeof( struct V_124 ) , V_29 ) ;
if ( V_67 == NULL )
return - V_15 ;
V_67 -> V_47 = V_5 -> V_125 ;
V_67 -> V_66 . V_70 = V_70 ;
V_67 -> V_66 . V_26 = V_32 ;
V_67 -> V_66 . type = V_5 -> type ;
V_27 = F_23 ( V_5 , & V_67 -> V_66 ) ;
if ( V_27 )
goto V_126;
if ( V_5 -> V_22 [ 0 ] -> V_8 != 1 ) {
V_67 -> V_66 . V_70 = 0 ;
V_27 = - V_68 ;
goto V_127;
}
for ( V_99 = 0 ; V_99 < V_5 -> V_21 ; V_99 ++ ) {
V_67 -> V_22 [ V_99 ] . V_75 = F_25 ( V_5 -> V_22 [ V_99 ] , 0 ) ;
if ( V_67 -> V_22 [ V_99 ] . V_75 == NULL )
goto V_127;
V_67 -> V_22 [ V_99 ] . V_128 = F_72 ( V_5 -> V_22 [ V_99 ] , 0 ) ;
}
if ( V_123 ) {
for ( V_99 = 0 ; V_99 < V_5 -> V_21 ; V_99 ++ ) {
struct V_36 * V_37 = & V_67 -> V_37 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> type = V_5 -> type ;
V_37 -> V_26 = V_5 -> V_26 ;
V_37 -> V_17 = V_99 ;
V_27 = F_41 ( V_5 , V_37 ) ;
if ( V_27 )
goto V_127;
V_67 -> V_22 [ V_99 ] . V_129 = 1 ;
}
V_27 = F_53 ( V_5 , V_5 -> type ) ;
if ( V_27 )
goto V_127;
}
V_5 -> V_67 = V_67 ;
return V_27 ;
V_127:
F_23 ( V_5 , & V_67 -> V_66 ) ;
V_126:
F_12 ( V_67 ) ;
return V_27 ;
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_124 * V_67 = V_5 -> V_67 ;
if ( V_67 ) {
V_5 -> V_67 = NULL ;
F_59 ( V_5 , V_5 -> type ) ;
V_67 -> V_66 . V_70 = 0 ;
F_23 ( V_5 , & V_67 -> V_66 ) ;
F_12 ( V_67 ) ;
F_5 ( 3 , L_68 ) ;
}
return 0 ;
}
static T_2 F_73 ( struct V_4 * V_5 , char T_3 * V_130 , T_2 V_70 ,
T_4 * V_131 , int V_132 , int V_123 )
{
struct V_124 * V_67 ;
struct V_133 * V_134 ;
int V_27 , V_17 ;
F_5 ( 3 , L_69 ,
V_123 ? L_66 : L_67 , ( long ) * V_131 , V_70 ,
V_132 ? L_70 : L_71 ) ;
if ( ! V_130 )
return - V_38 ;
if ( ! V_5 -> V_67 ) {
V_27 = F_63 ( V_5 , V_123 ) ;
F_5 ( 3 , L_72 , V_27 ) ;
if ( V_27 )
return V_27 ;
}
V_67 = V_5 -> V_67 ;
V_5 -> V_67 = NULL ;
V_17 = V_67 -> V_17 ;
V_134 = & V_67 -> V_22 [ V_17 ] ;
if ( V_134 -> V_129 ) {
struct V_1 * V_2 ;
memset ( & V_67 -> V_37 , 0 , sizeof( V_67 -> V_37 ) ) ;
V_67 -> V_37 . type = V_5 -> type ;
V_67 -> V_37 . V_26 = V_5 -> V_26 ;
V_67 -> V_37 . V_17 = V_17 ;
V_27 = F_52 ( V_5 , & V_67 -> V_37 , V_132 ) ;
F_5 ( 5 , L_73 , V_27 ) ;
if ( V_27 )
goto V_135;
V_67 -> V_136 += 1 ;
V_2 = V_5 -> V_22 [ V_17 ] ;
V_134 -> V_128 = F_74 ( V_2 , 0 ) ;
V_134 -> V_129 = 0 ;
}
if ( V_134 -> V_137 + V_70 > V_134 -> V_128 ) {
V_70 = V_134 -> V_128 - V_134 -> V_137 ;
F_5 ( 5 , L_74 , V_70 ) ;
}
F_5 ( 3 , L_75 ,
V_70 , V_17 , V_134 -> V_137 ) ;
if ( V_123 )
V_27 = F_75 ( V_130 , V_134 -> V_75 + V_134 -> V_137 , V_70 ) ;
else
V_27 = F_76 ( V_134 -> V_75 + V_134 -> V_137 , V_130 , V_70 ) ;
if ( V_27 ) {
F_5 ( 3 , L_76 ) ;
V_27 = - V_138 ;
goto V_135;
}
V_134 -> V_137 += V_70 ;
* V_131 += V_70 ;
if ( V_134 -> V_137 == V_134 -> V_128 ||
( ! V_123 && ( V_67 -> V_47 & V_139 ) ) ) {
if ( V_123 && ( V_67 -> V_47 & V_140 ) &&
V_67 -> V_136 == 1 ) {
F_5 ( 3 , L_77 ) ;
V_5 -> V_67 = V_67 ;
return F_70 ( V_5 ) ;
}
memset ( & V_67 -> V_37 , 0 , sizeof( V_67 -> V_37 ) ) ;
V_67 -> V_37 . type = V_5 -> type ;
V_67 -> V_37 . V_26 = V_5 -> V_26 ;
V_67 -> V_37 . V_17 = V_17 ;
V_67 -> V_37 . V_43 = V_134 -> V_137 ;
V_27 = F_41 ( V_5 , & V_67 -> V_37 ) ;
F_5 ( 5 , L_78 , V_27 ) ;
if ( V_27 )
goto V_135;
V_134 -> V_137 = 0 ;
V_134 -> V_129 = 1 ;
V_134 -> V_128 = V_5 -> V_22 [ 0 ] -> V_12 [ 0 ] . V_13 ;
V_67 -> V_141 += 1 ;
V_67 -> V_17 = ( V_17 + 1 ) % V_5 -> V_21 ;
if ( ! V_123 && ! V_5 -> V_69 ) {
V_27 = F_53 ( V_5 , V_5 -> type ) ;
if ( V_27 )
goto V_135;
}
}
if ( V_27 == 0 )
V_27 = V_70 ;
V_135:
V_5 -> V_67 = V_67 ;
return V_27 ;
}
T_2 F_77 ( struct V_4 * V_5 , char T_3 * V_130 , T_2 V_70 ,
T_4 * V_131 , int V_92 )
{
return F_73 ( V_5 , V_130 , V_70 , V_131 , V_92 , 1 ) ;
}
T_2 F_78 ( struct V_4 * V_5 , char T_3 * V_130 , T_2 V_70 ,
T_4 * V_131 , int V_92 )
{
return F_73 ( V_5 , V_130 , V_70 , V_131 , V_92 , 0 ) ;
}
