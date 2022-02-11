static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_5 , V_6 ;
int V_7 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_2 = V_2 ;
F_2 ( & V_4 -> V_8 ) ;
F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = F_4 ( V_11 * V_12 ,
sizeof( struct V_13 * ) , V_14 ) ;
if ( ! V_4 -> V_10 )
return - V_15 ;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 ) {
V_4 -> V_16 [ V_5 ] . V_17 = 1 ;
V_4 -> V_16 [ V_5 ] . V_10 = & V_4 -> V_10 [ V_11 * V_5 ] ;
}
V_4 -> V_18 = F_5 ( & V_2 -> V_19 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_20 ; V_5 ++ ) {
struct V_21 * V_22 = V_2 -> V_16 [ V_5 ] ;
struct V_23 * V_24 ;
V_24 = & V_22 -> V_25 . V_26 [ V_27 ] ;
V_7 = F_6 ( & V_22 -> V_25 , & V_4 -> V_16 [ V_5 ] . V_28 ,
V_24 , V_11 ) ;
if ( V_7 )
break;
}
if ( V_5 < V_2 -> V_20 ) {
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_7 ( & V_2 -> V_16 [ V_6 ] -> V_25 ,
& V_4 -> V_16 [ V_6 ] . V_28 ) ;
F_8 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
return V_7 ;
}
return 0 ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned V_5 , V_6 ;
if ( ! V_2 )
return;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 )
for ( V_6 = 0 ; V_6 < V_11 ; ++ V_6 )
F_10 ( V_4 -> V_16 [ V_5 ] . V_10 [ V_6 ] ) ;
F_8 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_20 ; V_5 ++ )
F_7 ( & V_2 -> V_16 [ V_5 ] -> V_25 ,
& V_4 -> V_16 [ V_5 ] . V_28 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
T_1 * V_31 )
{
struct V_32 * V_33 = & V_30 -> V_34 ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
F_13 ( & V_33 -> V_35 ) ;
V_7 = F_14 ( & V_33 -> V_36 , V_4 , 1 , 0 , V_14 ) ;
if ( V_7 < 0 ) {
F_15 ( & V_33 -> V_35 ) ;
F_8 ( V_4 ) ;
return V_7 ;
}
* V_31 = ( T_1 ) V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 ) {
F_16 ( & V_33 -> V_36 , * V_31 ) ;
* V_31 = 0 ;
F_8 ( V_4 ) ;
}
F_15 ( & V_33 -> V_35 ) ;
return V_7 ;
}
static void F_17 ( struct V_37 * V_38 )
{
struct V_3 * V_4 ;
V_4 = F_18 ( V_38 , struct V_3 , V_8 ) ;
F_9 ( V_4 ) ;
F_8 ( V_4 ) ;
}
static int F_19 ( struct V_29 * V_30 , T_1 V_31 )
{
struct V_32 * V_33 = & V_30 -> V_34 ;
struct V_3 * V_4 ;
F_13 ( & V_33 -> V_35 ) ;
V_4 = F_20 ( & V_33 -> V_36 , V_31 ) ;
if ( V_4 ) {
F_16 ( & V_33 -> V_36 , V_31 ) ;
F_21 ( & V_4 -> V_8 , F_17 ) ;
F_15 ( & V_33 -> V_35 ) ;
return 0 ;
}
F_15 ( & V_33 -> V_35 ) ;
return - V_39 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_29 * V_30 , T_1 V_31 ,
union V_40 * V_41 )
{
struct V_3 * V_4 ;
struct V_32 * V_33 ;
unsigned V_18 ;
if ( ! V_30 )
return - V_39 ;
V_33 = & V_30 -> V_34 ;
F_13 ( & V_33 -> V_35 ) ;
V_4 = F_20 ( & V_33 -> V_36 , V_31 ) ;
if ( ! V_4 ) {
F_15 ( & V_33 -> V_35 ) ;
return - V_39 ;
}
V_41 -> V_42 . V_43 = 0x0 ;
V_41 -> V_42 . V_44 = 0x0 ;
V_18 = F_5 ( & V_2 -> V_19 ) ;
if ( V_4 -> V_18 == V_18 )
V_41 -> V_42 . V_45 = V_46 ;
else
V_41 -> V_42 . V_45 = V_47 ;
V_4 -> V_18 = V_18 ;
F_15 ( & V_33 -> V_35 ) ;
return 0 ;
}
int F_23 ( struct V_48 * V_49 , void * V_50 ,
struct V_51 * V_52 )
{
int V_7 ;
T_1 V_31 ;
union V_53 * args = V_50 ;
struct V_1 * V_2 = V_49 -> V_54 ;
struct V_29 * V_30 = V_52 -> V_55 ;
V_7 = 0 ;
V_31 = args -> V_56 . V_57 ;
switch ( args -> V_56 . V_58 ) {
case V_59 :
V_7 = F_11 ( V_2 , V_30 , & V_31 ) ;
args -> V_41 . V_60 . V_57 = V_31 ;
break;
case V_61 :
V_7 = F_19 ( V_30 , V_31 ) ;
break;
case V_62 :
V_7 = F_22 ( V_2 , V_30 , V_31 , & args -> V_41 ) ;
break;
default:
return - V_39 ;
}
return V_7 ;
}
struct V_3 * F_24 ( struct V_29 * V_30 , T_1 V_31 )
{
struct V_3 * V_4 ;
struct V_32 * V_33 ;
if ( ! V_30 )
return NULL ;
V_33 = & V_30 -> V_34 ;
F_13 ( & V_33 -> V_35 ) ;
V_4 = F_20 ( & V_33 -> V_36 , V_31 ) ;
if ( V_4 )
F_25 ( & V_4 -> V_8 ) ;
F_15 ( & V_33 -> V_35 ) ;
return V_4 ;
}
int F_26 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_39 ;
F_21 ( & V_4 -> V_8 , F_17 ) ;
return 0 ;
}
T_2 F_27 ( struct V_3 * V_4 , struct V_21 * V_22 ,
struct V_13 * V_13 )
{
struct V_63 * V_64 = & V_4 -> V_16 [ V_22 -> V_65 ] ;
T_2 V_66 = V_64 -> V_17 ;
unsigned V_65 = 0 ;
struct V_13 * V_67 = NULL ;
V_65 = V_66 & ( V_11 - 1 ) ;
V_67 = V_64 -> V_10 [ V_65 ] ;
if ( V_67 ) {
signed long V_7 ;
V_7 = F_28 ( V_67 , false , V_68 ) ;
if ( V_7 < 0 )
F_29 ( L_1 , V_7 ) ;
}
F_30 ( V_13 ) ;
F_31 ( & V_4 -> V_9 ) ;
V_64 -> V_10 [ V_65 ] = V_13 ;
V_64 -> V_17 ++ ;
F_32 ( & V_4 -> V_9 ) ;
F_10 ( V_67 ) ;
return V_66 ;
}
struct V_13 * F_33 ( struct V_3 * V_4 ,
struct V_21 * V_22 , T_2 V_66 )
{
struct V_63 * V_64 = & V_4 -> V_16 [ V_22 -> V_65 ] ;
struct V_13 * V_13 ;
F_31 ( & V_4 -> V_9 ) ;
if ( V_66 >= V_64 -> V_17 ) {
F_32 ( & V_4 -> V_9 ) ;
return F_34 ( - V_39 ) ;
}
if ( V_66 + V_11 < V_64 -> V_17 ) {
F_32 ( & V_4 -> V_9 ) ;
return NULL ;
}
V_13 = F_30 ( V_64 -> V_10 [ V_66 & ( V_11 - 1 ) ] ) ;
F_32 ( & V_4 -> V_9 ) ;
return V_13 ;
}
void F_35 ( struct V_32 * V_33 )
{
F_36 ( & V_33 -> V_35 ) ;
F_37 ( & V_33 -> V_36 ) ;
}
void F_38 ( struct V_32 * V_33 )
{
struct V_3 * V_4 ;
struct V_69 * V_70 ;
T_1 V_31 ;
V_70 = & V_33 -> V_36 ;
F_39 (idp, ctx, id) {
if ( F_21 ( & V_4 -> V_8 , F_17 ) != 1 )
F_29 ( L_2 , V_4 ) ;
}
F_40 ( & V_33 -> V_36 ) ;
F_41 ( & V_33 -> V_35 ) ;
}
