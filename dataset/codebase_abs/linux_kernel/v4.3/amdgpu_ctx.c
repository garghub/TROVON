int F_1 ( struct V_1 * V_2 , bool V_3 ,
struct V_4 * V_5 )
{
unsigned V_6 , V_7 ;
int V_8 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_2 = V_2 ;
F_2 ( & V_5 -> V_9 ) ;
F_3 ( & V_5 -> V_10 ) ;
for ( V_6 = 0 ; V_6 < V_11 ; ++ V_6 )
V_5 -> V_12 [ V_6 ] . V_13 = 1 ;
if ( V_14 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_15 ; V_6 ++ ) {
struct V_16 * V_17 ;
if ( V_3 )
V_17 = & V_2 -> V_12 [ V_6 ] -> V_18 . V_19 ;
else
V_17 = & V_2 -> V_12 [ V_6 ] -> V_18 . V_20 ;
V_8 = F_4 ( & V_2 -> V_12 [ V_6 ] -> V_18 ,
& V_5 -> V_12 [ V_6 ] . V_21 ,
V_17 , V_22 ) ;
if ( V_8 )
break;
}
if ( V_6 < V_2 -> V_15 ) {
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_5 ( & V_2 -> V_12 [ V_7 ] -> V_18 ,
& V_5 -> V_12 [ V_7 ] . V_21 ) ;
F_6 ( V_5 ) ;
return V_8 ;
}
}
return 0 ;
}
void F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_11 ; ++ V_6 )
for ( V_7 = 0 ; V_7 < V_23 ; ++ V_7 )
F_8 ( V_5 -> V_12 [ V_6 ] . V_24 [ V_7 ] ) ;
if ( V_14 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_15 ; V_6 ++ )
F_5 ( & V_2 -> V_12 [ V_6 ] -> V_18 ,
& V_5 -> V_12 [ V_6 ] . V_21 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
T_1 * V_27 )
{
struct V_28 * V_29 = & V_26 -> V_30 ;
struct V_4 * V_5 ;
int V_8 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
F_11 ( & V_29 -> V_33 ) ;
V_8 = F_12 ( & V_29 -> V_34 , V_5 , 1 , 0 , V_31 ) ;
if ( V_8 < 0 ) {
F_13 ( & V_29 -> V_33 ) ;
F_6 ( V_5 ) ;
return V_8 ;
}
* V_27 = ( T_1 ) V_8 ;
V_8 = F_1 ( V_2 , false , V_5 ) ;
F_13 ( & V_29 -> V_33 ) ;
return V_8 ;
}
static void F_14 ( struct V_35 * V_36 )
{
struct V_4 * V_5 ;
V_5 = F_15 ( V_36 , struct V_4 , V_9 ) ;
F_7 ( V_5 ) ;
F_6 ( V_5 ) ;
}
static int F_16 ( struct V_25 * V_26 , T_1 V_27 )
{
struct V_28 * V_29 = & V_26 -> V_30 ;
struct V_4 * V_5 ;
F_11 ( & V_29 -> V_33 ) ;
V_5 = F_17 ( & V_29 -> V_34 , V_27 ) ;
if ( V_5 ) {
F_18 ( & V_29 -> V_34 , V_27 ) ;
F_19 ( & V_5 -> V_9 , F_14 ) ;
F_13 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_13 ( & V_29 -> V_33 ) ;
return - V_37 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 , T_1 V_27 ,
union V_38 * V_39 )
{
struct V_4 * V_5 ;
struct V_28 * V_29 ;
unsigned V_40 ;
if ( ! V_26 )
return - V_37 ;
V_29 = & V_26 -> V_30 ;
F_11 ( & V_29 -> V_33 ) ;
V_5 = F_17 ( & V_29 -> V_34 , V_27 ) ;
if ( ! V_5 ) {
F_13 ( & V_29 -> V_33 ) ;
return - V_37 ;
}
V_39 -> V_41 . V_42 = 0x0 ;
V_39 -> V_41 . V_43 = 0x0 ;
V_40 = F_21 ( & V_2 -> V_44 ) ;
if ( V_5 -> V_40 == V_40 )
V_39 -> V_41 . V_45 = V_46 ;
else
V_39 -> V_41 . V_45 = V_47 ;
V_5 -> V_40 = V_40 ;
F_13 ( & V_29 -> V_33 ) ;
return 0 ;
}
int F_22 ( struct V_48 * V_49 , void * V_50 ,
struct V_51 * V_52 )
{
int V_8 ;
T_1 V_27 ;
union V_53 * args = V_50 ;
struct V_1 * V_2 = V_49 -> V_54 ;
struct V_25 * V_26 = V_52 -> V_55 ;
V_8 = 0 ;
V_27 = args -> V_56 . V_57 ;
switch ( args -> V_56 . V_58 ) {
case V_59 :
V_8 = F_9 ( V_2 , V_26 , & V_27 ) ;
args -> V_39 . V_60 . V_57 = V_27 ;
break;
case V_61 :
V_8 = F_16 ( V_26 , V_27 ) ;
break;
case V_62 :
V_8 = F_20 ( V_2 , V_26 , V_27 , & args -> V_39 ) ;
break;
default:
return - V_37 ;
}
return V_8 ;
}
struct V_4 * F_23 ( struct V_25 * V_26 , T_1 V_27 )
{
struct V_4 * V_5 ;
struct V_28 * V_29 ;
if ( ! V_26 )
return NULL ;
V_29 = & V_26 -> V_30 ;
F_11 ( & V_29 -> V_33 ) ;
V_5 = F_17 ( & V_29 -> V_34 , V_27 ) ;
if ( V_5 )
F_24 ( & V_5 -> V_9 ) ;
F_13 ( & V_29 -> V_33 ) ;
return V_5 ;
}
int F_25 ( struct V_4 * V_5 )
{
if ( V_5 == NULL )
return - V_37 ;
F_19 ( & V_5 -> V_9 , F_14 ) ;
return 0 ;
}
T_2 F_26 ( struct V_4 * V_5 , struct V_63 * V_64 ,
struct V_65 * V_65 )
{
struct V_66 * V_67 = & V_5 -> V_12 [ V_64 -> V_68 ] ;
T_2 V_69 = V_67 -> V_13 ;
unsigned V_68 = 0 ;
struct V_65 * V_70 = NULL ;
V_68 = V_69 % V_23 ;
V_70 = V_67 -> V_24 [ V_68 ] ;
if ( V_70 ) {
signed long V_8 ;
V_8 = F_27 ( V_70 , false , V_71 ) ;
if ( V_8 < 0 )
F_28 ( L_1 , V_8 ) ;
}
F_29 ( V_65 ) ;
F_30 ( & V_5 -> V_10 ) ;
V_67 -> V_24 [ V_68 ] = V_65 ;
V_67 -> V_13 ++ ;
F_31 ( & V_5 -> V_10 ) ;
F_8 ( V_70 ) ;
return V_69 ;
}
struct V_65 * F_32 ( struct V_4 * V_5 ,
struct V_63 * V_64 , T_2 V_69 )
{
struct V_66 * V_67 = & V_5 -> V_12 [ V_64 -> V_68 ] ;
struct V_65 * V_65 ;
F_30 ( & V_5 -> V_10 ) ;
if ( V_69 >= V_67 -> V_13 ) {
F_31 ( & V_5 -> V_10 ) ;
return F_33 ( - V_37 ) ;
}
if ( V_69 + V_23 < V_67 -> V_13 ) {
F_31 ( & V_5 -> V_10 ) ;
return NULL ;
}
V_65 = F_29 ( V_67 -> V_24 [ V_69 % V_23 ] ) ;
F_31 ( & V_5 -> V_10 ) ;
return V_65 ;
}
void F_34 ( struct V_28 * V_29 )
{
F_35 ( & V_29 -> V_33 ) ;
F_36 ( & V_29 -> V_34 ) ;
}
void F_37 ( struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_72 * V_73 ;
T_1 V_27 ;
V_73 = & V_29 -> V_34 ;
F_38 (idp, ctx, id) {
if ( F_19 ( & V_5 -> V_9 , F_14 ) != 1 )
F_28 ( L_2 , V_5 ) ;
}
F_39 ( & V_29 -> V_34 ) ;
F_40 ( & V_29 -> V_33 ) ;
}
