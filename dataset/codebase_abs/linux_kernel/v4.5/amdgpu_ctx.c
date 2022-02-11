int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
struct V_5 * V_6 )
{
unsigned V_7 , V_8 ;
int V_9 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_2 = V_2 ;
F_2 ( & V_6 -> V_10 ) ;
F_3 ( & V_6 -> V_11 ) ;
V_6 -> V_12 = F_4 ( sizeof( struct V_13 * ) * V_14 *
V_15 , V_16 ) ;
if ( ! V_6 -> V_12 )
return - V_17 ;
for ( V_7 = 0 ; V_7 < V_15 ; ++ V_7 ) {
V_6 -> V_18 [ V_7 ] . V_19 = 1 ;
V_6 -> V_18 [ V_7 ] . V_12 = ( void * ) V_6 -> V_12 + sizeof( struct V_13 * ) *
V_14 * V_7 ;
}
if ( V_20 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_21 ; V_7 ++ ) {
struct V_22 * V_23 ;
if ( V_4 >= V_24 ) {
F_5 ( V_6 -> V_12 ) ;
return - V_25 ;
}
V_23 = & V_2 -> V_18 [ V_7 ] -> V_26 . V_27 [ V_4 ] ;
V_9 = F_6 ( & V_2 -> V_18 [ V_7 ] -> V_26 ,
& V_6 -> V_18 [ V_7 ] . V_28 ,
V_23 , V_14 ) ;
if ( V_9 )
break;
}
if ( V_7 < V_2 -> V_21 ) {
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_7 ( & V_2 -> V_18 [ V_8 ] -> V_26 ,
& V_6 -> V_18 [ V_8 ] . V_28 ) ;
F_5 ( V_6 -> V_12 ) ;
return V_9 ;
}
}
return 0 ;
}
void F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned V_7 , V_8 ;
if ( ! V_2 )
return;
for ( V_7 = 0 ; V_7 < V_15 ; ++ V_7 )
for ( V_8 = 0 ; V_8 < V_14 ; ++ V_8 )
F_9 ( V_6 -> V_18 [ V_7 ] . V_12 [ V_8 ] ) ;
F_5 ( V_6 -> V_12 ) ;
if ( V_20 ) {
for ( V_7 = 0 ; V_7 < V_2 -> V_21 ; V_7 ++ )
F_7 ( & V_2 -> V_18 [ V_7 ] -> V_26 ,
& V_6 -> V_18 [ V_7 ] . V_28 ) ;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
T_1 * V_31 )
{
struct V_32 * V_33 = & V_30 -> V_34 ;
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_11 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
F_12 ( & V_33 -> V_35 ) ;
V_9 = F_13 ( & V_33 -> V_36 , V_6 , 1 , 0 , V_16 ) ;
if ( V_9 < 0 ) {
F_14 ( & V_33 -> V_35 ) ;
F_5 ( V_6 ) ;
return V_9 ;
}
* V_31 = ( T_1 ) V_9 ;
V_9 = F_1 ( V_2 , V_37 , V_6 ) ;
if ( V_9 ) {
F_15 ( & V_33 -> V_36 , * V_31 ) ;
* V_31 = 0 ;
F_5 ( V_6 ) ;
}
F_14 ( & V_33 -> V_35 ) ;
return V_9 ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_5 * V_6 ;
V_6 = F_17 ( V_39 , struct V_5 , V_10 ) ;
F_8 ( V_6 ) ;
F_5 ( V_6 ) ;
}
static int F_18 ( struct V_29 * V_30 , T_1 V_31 )
{
struct V_32 * V_33 = & V_30 -> V_34 ;
struct V_5 * V_6 ;
F_12 ( & V_33 -> V_35 ) ;
V_6 = F_19 ( & V_33 -> V_36 , V_31 ) ;
if ( V_6 ) {
F_15 ( & V_33 -> V_36 , V_31 ) ;
F_20 ( & V_6 -> V_10 , F_16 ) ;
F_14 ( & V_33 -> V_35 ) ;
return 0 ;
}
F_14 ( & V_33 -> V_35 ) ;
return - V_25 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_29 * V_30 , T_1 V_31 ,
union V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
unsigned V_42 ;
if ( ! V_30 )
return - V_25 ;
V_33 = & V_30 -> V_34 ;
F_12 ( & V_33 -> V_35 ) ;
V_6 = F_19 ( & V_33 -> V_36 , V_31 ) ;
if ( ! V_6 ) {
F_14 ( & V_33 -> V_35 ) ;
return - V_25 ;
}
V_41 -> V_43 . V_44 = 0x0 ;
V_41 -> V_43 . V_45 = 0x0 ;
V_42 = F_22 ( & V_2 -> V_46 ) ;
if ( V_6 -> V_42 == V_42 )
V_41 -> V_43 . V_47 = V_48 ;
else
V_41 -> V_43 . V_47 = V_49 ;
V_6 -> V_42 = V_42 ;
F_14 ( & V_33 -> V_35 ) ;
return 0 ;
}
int F_23 ( struct V_50 * V_51 , void * V_52 ,
struct V_53 * V_54 )
{
int V_9 ;
T_1 V_31 ;
union V_55 * args = V_52 ;
struct V_1 * V_2 = V_51 -> V_56 ;
struct V_29 * V_30 = V_54 -> V_57 ;
V_9 = 0 ;
V_31 = args -> V_58 . V_59 ;
switch ( args -> V_58 . V_60 ) {
case V_61 :
V_9 = F_10 ( V_2 , V_30 , & V_31 ) ;
args -> V_41 . V_62 . V_59 = V_31 ;
break;
case V_63 :
V_9 = F_18 ( V_30 , V_31 ) ;
break;
case V_64 :
V_9 = F_21 ( V_2 , V_30 , V_31 , & args -> V_41 ) ;
break;
default:
return - V_25 ;
}
return V_9 ;
}
struct V_5 * F_24 ( struct V_29 * V_30 , T_1 V_31 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
if ( ! V_30 )
return NULL ;
V_33 = & V_30 -> V_34 ;
F_12 ( & V_33 -> V_35 ) ;
V_6 = F_19 ( & V_33 -> V_36 , V_31 ) ;
if ( V_6 )
F_25 ( & V_6 -> V_10 ) ;
F_14 ( & V_33 -> V_35 ) ;
return V_6 ;
}
int F_26 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return - V_25 ;
F_20 ( & V_6 -> V_10 , F_16 ) ;
return 0 ;
}
T_2 F_27 ( struct V_5 * V_6 , struct V_65 * V_66 ,
struct V_13 * V_13 )
{
struct V_67 * V_68 = & V_6 -> V_18 [ V_66 -> V_69 ] ;
T_2 V_70 = V_68 -> V_19 ;
unsigned V_69 = 0 ;
struct V_13 * V_71 = NULL ;
V_69 = V_70 & ( V_14 - 1 ) ;
V_71 = V_68 -> V_12 [ V_69 ] ;
if ( V_71 ) {
signed long V_9 ;
V_9 = F_28 ( V_71 , false , V_72 ) ;
if ( V_9 < 0 )
F_29 ( L_1 , V_9 ) ;
}
F_30 ( V_13 ) ;
F_31 ( & V_6 -> V_11 ) ;
V_68 -> V_12 [ V_69 ] = V_13 ;
V_68 -> V_19 ++ ;
F_32 ( & V_6 -> V_11 ) ;
F_9 ( V_71 ) ;
return V_70 ;
}
struct V_13 * F_33 ( struct V_5 * V_6 ,
struct V_65 * V_66 , T_2 V_70 )
{
struct V_67 * V_68 = & V_6 -> V_18 [ V_66 -> V_69 ] ;
struct V_13 * V_13 ;
F_31 ( & V_6 -> V_11 ) ;
if ( V_70 >= V_68 -> V_19 ) {
F_32 ( & V_6 -> V_11 ) ;
return F_34 ( - V_25 ) ;
}
if ( V_70 + V_14 < V_68 -> V_19 ) {
F_32 ( & V_6 -> V_11 ) ;
return NULL ;
}
V_13 = F_30 ( V_68 -> V_12 [ V_70 & ( V_14 - 1 ) ] ) ;
F_32 ( & V_6 -> V_11 ) ;
return V_13 ;
}
void F_35 ( struct V_32 * V_33 )
{
F_36 ( & V_33 -> V_35 ) ;
F_37 ( & V_33 -> V_36 ) ;
}
void F_38 ( struct V_32 * V_33 )
{
struct V_5 * V_6 ;
struct V_73 * V_74 ;
T_1 V_31 ;
V_74 = & V_33 -> V_36 ;
F_39 (idp, ctx, id) {
if ( F_20 ( & V_6 -> V_10 , F_16 ) != 1 )
F_29 ( L_2 , V_6 ) ;
}
F_40 ( & V_33 -> V_36 ) ;
F_41 ( & V_33 -> V_35 ) ;
}
