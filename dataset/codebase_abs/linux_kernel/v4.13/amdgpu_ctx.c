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
if ( V_22 == & V_2 -> V_28 . V_29 . V_22 )
continue;
V_7 = F_6 ( & V_22 -> V_25 , & V_4 -> V_16 [ V_5 ] . V_30 ,
V_24 , V_11 ) ;
if ( V_7 )
goto V_31;
}
V_7 = F_7 ( V_2 , & V_4 -> V_32 ) ;
if ( V_7 )
goto V_31;
return 0 ;
V_31:
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_8 ( & V_2 -> V_16 [ V_6 ] -> V_25 ,
& V_4 -> V_16 [ V_6 ] . V_30 ) ;
F_9 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
return V_7 ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned V_5 , V_6 ;
if ( ! V_2 )
return;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 )
for ( V_6 = 0 ; V_6 < V_11 ; ++ V_6 )
F_11 ( V_4 -> V_16 [ V_5 ] . V_10 [ V_6 ] ) ;
F_9 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_20 ; V_5 ++ )
F_8 ( & V_2 -> V_16 [ V_5 ] -> V_25 ,
& V_4 -> V_16 [ V_5 ] . V_30 ) ;
F_12 ( V_2 , & V_4 -> V_32 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
T_1 * V_35 )
{
struct V_36 * V_37 = & V_34 -> V_38 ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
F_15 ( & V_37 -> V_39 ) ;
V_7 = F_16 ( & V_37 -> V_40 , V_4 , 1 , 0 , V_14 ) ;
if ( V_7 < 0 ) {
F_17 ( & V_37 -> V_39 ) ;
F_9 ( V_4 ) ;
return V_7 ;
}
* V_35 = ( T_1 ) V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 ) {
F_18 ( & V_37 -> V_40 , * V_35 ) ;
* V_35 = 0 ;
F_9 ( V_4 ) ;
}
F_17 ( & V_37 -> V_39 ) ;
return V_7 ;
}
static void F_19 ( struct V_41 * V_42 )
{
struct V_3 * V_4 ;
V_4 = F_20 ( V_42 , struct V_3 , V_8 ) ;
F_10 ( V_4 ) ;
F_9 ( V_4 ) ;
}
static int F_21 ( struct V_33 * V_34 , T_1 V_35 )
{
struct V_36 * V_37 = & V_34 -> V_38 ;
struct V_3 * V_4 ;
F_15 ( & V_37 -> V_39 ) ;
V_4 = F_18 ( & V_37 -> V_40 , V_35 ) ;
if ( V_4 )
F_22 ( & V_4 -> V_8 , F_19 ) ;
F_17 ( & V_37 -> V_39 ) ;
return V_4 ? 0 : - V_43 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_35 ,
union V_44 * V_45 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
unsigned V_18 ;
if ( ! V_34 )
return - V_43 ;
V_37 = & V_34 -> V_38 ;
F_15 ( & V_37 -> V_39 ) ;
V_4 = F_24 ( & V_37 -> V_40 , V_35 ) ;
if ( ! V_4 ) {
F_17 ( & V_37 -> V_39 ) ;
return - V_43 ;
}
V_45 -> V_46 . V_47 = 0x0 ;
V_45 -> V_46 . V_48 = 0x0 ;
V_18 = F_5 ( & V_2 -> V_19 ) ;
if ( V_4 -> V_18 == V_18 )
V_45 -> V_46 . V_49 = V_50 ;
else
V_45 -> V_46 . V_49 = V_51 ;
V_4 -> V_18 = V_18 ;
F_17 ( & V_37 -> V_39 ) ;
return 0 ;
}
int F_25 ( struct V_52 * V_53 , void * V_54 ,
struct V_55 * V_56 )
{
int V_7 ;
T_1 V_35 ;
union V_57 * args = V_54 ;
struct V_1 * V_2 = V_53 -> V_58 ;
struct V_33 * V_34 = V_56 -> V_59 ;
V_7 = 0 ;
V_35 = args -> V_60 . V_61 ;
switch ( args -> V_60 . V_62 ) {
case V_63 :
V_7 = F_13 ( V_2 , V_34 , & V_35 ) ;
args -> V_45 . V_64 . V_61 = V_35 ;
break;
case V_65 :
V_7 = F_21 ( V_34 , V_35 ) ;
break;
case V_66 :
V_7 = F_23 ( V_2 , V_34 , V_35 , & args -> V_45 ) ;
break;
default:
return - V_43 ;
}
return V_7 ;
}
struct V_3 * F_26 ( struct V_33 * V_34 , T_1 V_35 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
if ( ! V_34 )
return NULL ;
V_37 = & V_34 -> V_38 ;
F_15 ( & V_37 -> V_39 ) ;
V_4 = F_24 ( & V_37 -> V_40 , V_35 ) ;
if ( V_4 )
F_27 ( & V_4 -> V_8 ) ;
F_17 ( & V_37 -> V_39 ) ;
return V_4 ;
}
int F_28 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return - V_43 ;
F_22 ( & V_4 -> V_8 , F_19 ) ;
return 0 ;
}
T_2 F_29 ( struct V_3 * V_4 , struct V_21 * V_22 ,
struct V_13 * V_67 )
{
struct V_68 * V_69 = & V_4 -> V_16 [ V_22 -> V_70 ] ;
T_2 V_71 = V_69 -> V_17 ;
unsigned V_70 = 0 ;
struct V_13 * V_72 = NULL ;
V_70 = V_71 & ( V_11 - 1 ) ;
V_72 = V_69 -> V_10 [ V_70 ] ;
if ( V_72 ) {
signed long V_7 ;
V_7 = F_30 ( V_72 , false , V_73 ) ;
if ( V_7 < 0 )
F_31 ( L_1 , V_7 ) ;
}
F_32 ( V_67 ) ;
F_33 ( & V_4 -> V_9 ) ;
V_69 -> V_10 [ V_70 ] = V_67 ;
V_69 -> V_17 ++ ;
F_34 ( & V_4 -> V_9 ) ;
F_11 ( V_72 ) ;
return V_71 ;
}
struct V_13 * F_35 ( struct V_3 * V_4 ,
struct V_21 * V_22 , T_2 V_71 )
{
struct V_68 * V_69 = & V_4 -> V_16 [ V_22 -> V_70 ] ;
struct V_13 * V_67 ;
F_33 ( & V_4 -> V_9 ) ;
if ( V_71 == ~ 0ull )
V_71 = V_4 -> V_16 [ V_22 -> V_70 ] . V_17 - 1 ;
if ( V_71 >= V_69 -> V_17 ) {
F_34 ( & V_4 -> V_9 ) ;
return F_36 ( - V_43 ) ;
}
if ( V_71 + V_11 < V_69 -> V_17 ) {
F_34 ( & V_4 -> V_9 ) ;
return NULL ;
}
V_67 = F_32 ( V_69 -> V_10 [ V_71 & ( V_11 - 1 ) ] ) ;
F_34 ( & V_4 -> V_9 ) ;
return V_67 ;
}
void F_37 ( struct V_36 * V_37 )
{
F_38 ( & V_37 -> V_39 ) ;
F_39 ( & V_37 -> V_40 ) ;
}
void F_40 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_74 * V_75 ;
T_1 V_35 ;
V_75 = & V_37 -> V_40 ;
F_41 (idp, ctx, id) {
if ( F_22 ( & V_4 -> V_8 , F_19 ) != 1 )
F_31 ( L_2 , V_4 ) ;
}
F_42 ( & V_37 -> V_40 ) ;
F_43 ( & V_37 -> V_39 ) ;
}
