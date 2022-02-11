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
goto V_29;
}
return 0 ;
V_29:
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_7 ( & V_2 -> V_16 [ V_6 ] -> V_25 ,
& V_4 -> V_16 [ V_6 ] . V_28 ) ;
F_8 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
return V_7 ;
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
struct V_30 * V_31 ,
T_1 * V_32 )
{
struct V_33 * V_34 = & V_31 -> V_35 ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
F_13 ( & V_34 -> V_36 ) ;
V_7 = F_14 ( & V_34 -> V_37 , V_4 , 1 , 0 , V_14 ) ;
if ( V_7 < 0 ) {
F_15 ( & V_34 -> V_36 ) ;
F_8 ( V_4 ) ;
return V_7 ;
}
* V_32 = ( T_1 ) V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 ) {
F_16 ( & V_34 -> V_37 , * V_32 ) ;
* V_32 = 0 ;
F_8 ( V_4 ) ;
}
F_15 ( & V_34 -> V_36 ) ;
return V_7 ;
}
static void F_17 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
V_4 = F_18 ( V_39 , struct V_3 , V_8 ) ;
F_9 ( V_4 ) ;
F_8 ( V_4 ) ;
}
static int F_19 ( struct V_30 * V_31 , T_1 V_32 )
{
struct V_33 * V_34 = & V_31 -> V_35 ;
struct V_3 * V_4 ;
F_13 ( & V_34 -> V_36 ) ;
V_4 = F_20 ( & V_34 -> V_37 , V_32 ) ;
if ( V_4 ) {
F_16 ( & V_34 -> V_37 , V_32 ) ;
F_21 ( & V_4 -> V_8 , F_17 ) ;
F_15 ( & V_34 -> V_36 ) ;
return 0 ;
}
F_15 ( & V_34 -> V_36 ) ;
return - V_40 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_30 * V_31 , T_1 V_32 ,
union V_41 * V_42 )
{
struct V_3 * V_4 ;
struct V_33 * V_34 ;
unsigned V_18 ;
if ( ! V_31 )
return - V_40 ;
V_34 = & V_31 -> V_35 ;
F_13 ( & V_34 -> V_36 ) ;
V_4 = F_20 ( & V_34 -> V_37 , V_32 ) ;
if ( ! V_4 ) {
F_15 ( & V_34 -> V_36 ) ;
return - V_40 ;
}
V_42 -> V_43 . V_44 = 0x0 ;
V_42 -> V_43 . V_45 = 0x0 ;
V_18 = F_5 ( & V_2 -> V_19 ) ;
if ( V_4 -> V_18 == V_18 )
V_42 -> V_43 . V_46 = V_47 ;
else
V_42 -> V_43 . V_46 = V_48 ;
V_4 -> V_18 = V_18 ;
F_15 ( & V_34 -> V_36 ) ;
return 0 ;
}
int F_23 ( struct V_49 * V_50 , void * V_51 ,
struct V_52 * V_53 )
{
int V_7 ;
T_1 V_32 ;
union V_54 * args = V_51 ;
struct V_1 * V_2 = V_50 -> V_55 ;
struct V_30 * V_31 = V_53 -> V_56 ;
V_7 = 0 ;
V_32 = args -> V_57 . V_58 ;
switch ( args -> V_57 . V_59 ) {
case V_60 :
V_7 = F_11 ( V_2 , V_31 , & V_32 ) ;
args -> V_42 . V_61 . V_58 = V_32 ;
break;
case V_62 :
V_7 = F_19 ( V_31 , V_32 ) ;
break;
case V_63 :
V_7 = F_22 ( V_2 , V_31 , V_32 , & args -> V_42 ) ;
break;
default:
return - V_40 ;
}
return V_7 ;
}
struct V_3 * F_24 ( struct V_30 * V_31 , T_1 V_32 )
{
struct V_3 * V_4 ;
struct V_33 * V_34 ;
if ( ! V_31 )
return NULL ;
V_34 = & V_31 -> V_35 ;
F_13 ( & V_34 -> V_36 ) ;
V_4 = F_20 ( & V_34 -> V_37 , V_32 ) ;
if ( V_4 )
F_25 ( & V_4 -> V_8 ) ;
F_15 ( & V_34 -> V_36 ) ;
return V_4 ;
}
int F_26 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_40 ;
F_21 ( & V_4 -> V_8 , F_17 ) ;
return 0 ;
}
T_2 F_27 ( struct V_3 * V_4 , struct V_21 * V_22 ,
struct V_13 * V_64 )
{
struct V_65 * V_66 = & V_4 -> V_16 [ V_22 -> V_67 ] ;
T_2 V_68 = V_66 -> V_17 ;
unsigned V_67 = 0 ;
struct V_13 * V_69 = NULL ;
V_67 = V_68 & ( V_11 - 1 ) ;
V_69 = V_66 -> V_10 [ V_67 ] ;
if ( V_69 ) {
signed long V_7 ;
V_7 = F_28 ( V_69 , false , V_70 ) ;
if ( V_7 < 0 )
F_29 ( L_1 , V_7 ) ;
}
F_30 ( V_64 ) ;
F_31 ( & V_4 -> V_9 ) ;
V_66 -> V_10 [ V_67 ] = V_64 ;
V_66 -> V_17 ++ ;
F_32 ( & V_4 -> V_9 ) ;
F_10 ( V_69 ) ;
return V_68 ;
}
struct V_13 * F_33 ( struct V_3 * V_4 ,
struct V_21 * V_22 , T_2 V_68 )
{
struct V_65 * V_66 = & V_4 -> V_16 [ V_22 -> V_67 ] ;
struct V_13 * V_64 ;
F_31 ( & V_4 -> V_9 ) ;
if ( V_68 >= V_66 -> V_17 ) {
F_32 ( & V_4 -> V_9 ) ;
return F_34 ( - V_40 ) ;
}
if ( V_68 + V_11 < V_66 -> V_17 ) {
F_32 ( & V_4 -> V_9 ) ;
return NULL ;
}
V_64 = F_30 ( V_66 -> V_10 [ V_68 & ( V_11 - 1 ) ] ) ;
F_32 ( & V_4 -> V_9 ) ;
return V_64 ;
}
void F_35 ( struct V_33 * V_34 )
{
F_36 ( & V_34 -> V_36 ) ;
F_37 ( & V_34 -> V_37 ) ;
}
void F_38 ( struct V_33 * V_34 )
{
struct V_3 * V_4 ;
struct V_71 * V_72 ;
T_1 V_32 ;
V_72 = & V_34 -> V_37 ;
F_39 (idp, ctx, id) {
if ( F_21 ( & V_4 -> V_8 , F_17 ) != 1 )
F_29 ( L_2 , V_4 ) ;
}
F_40 ( & V_34 -> V_37 ) ;
F_41 ( & V_34 -> V_36 ) ;
}
