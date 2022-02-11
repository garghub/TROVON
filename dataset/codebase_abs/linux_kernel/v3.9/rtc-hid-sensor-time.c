static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , void * V_4 )
{
unsigned long V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_3 ( & V_7 -> V_8 , V_5 ) ;
V_7 -> V_9 = V_7 -> V_10 ;
F_4 ( & V_7 -> V_8 , V_5 ) ;
F_5 ( & V_7 -> V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , T_1 V_12 ,
char * V_13 , void * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_14 * V_10 = & V_7 -> V_10 ;
switch ( V_3 ) {
case V_15 :
V_10 -> V_16 = * ( V_17 * ) V_13 ;
if ( V_10 -> V_16 < 70 )
V_10 -> V_16 += 100 ;
break;
case V_18 :
V_10 -> V_19 = * ( V_17 * ) V_13 - 1 ;
break;
case V_20 :
V_10 -> V_21 = * ( V_17 * ) V_13 ;
break;
case V_22 :
V_10 -> V_23 = * ( V_17 * ) V_13 ;
break;
case V_24 :
V_10 -> V_25 = * ( V_17 * ) V_13 ;
break;
case V_26 :
V_10 -> V_27 = * ( V_17 * ) V_13 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static const char * F_7 ( T_2 V_29 )
{
static const char V_30 [] = L_1 ;
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
if ( V_33 [ V_31 ] == V_29 )
return V_34 [ V_31 ] ;
}
return V_30 ;
}
static int F_8 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
unsigned V_3 ,
struct V_6 * V_7 )
{
int V_37 , V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 )
if ( F_9 ( V_2 ,
V_38 , V_3 ,
V_33 [ V_31 ] ,
& V_7 -> V_39 [ V_31 ] ) < 0 )
return - V_28 ;
V_37 = V_7 -> V_39 [ 0 ] . V_37 ;
if ( V_37 < 0 ) {
F_10 ( & V_36 -> V_40 , L_2 ) ;
return - V_28 ;
}
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
if ( V_7 -> V_39 [ V_31 ] . V_37 != V_37 ) {
F_10 ( & V_36 -> V_40 ,
L_3 ) ;
return - V_28 ;
}
if ( V_7 -> V_39 [ V_31 ] . V_41 != 1 ) {
F_10 ( & V_36 -> V_40 ,
L_4 ,
F_7 (
V_7 -> V_39 [ V_31 ] . V_29 ) ) ;
return - V_28 ;
}
if ( V_7 -> V_39 [ V_31 ] . V_42 !=
V_43 &&
! ( V_7 -> V_39 [ V_31 ] . V_29 ==
V_26 &&
V_7 -> V_39 [ V_31 ] . V_42 ==
V_44 ) ) {
F_10 ( & V_36 -> V_40 ,
L_5 ,
F_7 (
V_7 -> V_39 [ V_31 ] . V_29 ) ) ;
return - V_28 ;
}
if ( V_7 -> V_39 [ V_31 ] . V_45 ) {
F_10 ( & V_36 -> V_40 ,
L_6 ,
F_7 (
V_7 -> V_39 [ V_31 ] . V_29 ) ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_11 ( struct V_46 * V_40 , struct V_14 * V_47 )
{
unsigned long V_5 ;
struct V_6 * V_7 =
F_2 ( F_12 ( V_40 ) ) ;
int V_48 ;
F_13 ( V_7 -> V_11 ) ;
F_14 ( V_7 -> V_49 . V_2 ,
V_50 , V_33 [ 0 ] ,
V_7 -> V_39 [ 0 ] . V_37 ) ;
V_48 = F_15 (
& V_7 -> V_11 , V_51 * 6 ) ;
if ( V_48 > 0 ) {
F_3 ( & V_7 -> V_8 , V_5 ) ;
* V_47 = V_7 -> V_9 ;
F_4 ( & V_7 -> V_8 , V_5 ) ;
return 0 ;
}
if ( ! V_48 )
return - V_52 ;
return V_48 ;
}
static int F_16 ( struct V_35 * V_36 )
{
int V_48 = 0 ;
struct V_1 * V_2 = V_36 -> V_40 . V_53 ;
struct V_6 * V_7 = F_17 ( & V_36 -> V_40 ,
sizeof( struct V_6 ) , V_54 ) ;
if ( V_7 == NULL )
return - V_55 ;
F_18 ( V_36 , V_7 ) ;
F_19 ( & V_7 -> V_8 ) ;
F_20 ( & V_7 -> V_11 ) ;
V_7 -> V_49 . V_2 = V_2 ;
V_7 -> V_49 . V_36 = V_36 ;
V_48 = F_21 ( V_2 ,
V_50 ,
& V_7 -> V_49 ) ;
if ( V_48 ) {
F_10 ( & V_36 -> V_40 , L_7 ) ;
return V_48 ;
}
V_48 = F_8 ( V_36 , V_2 , V_50 ,
V_7 ) ;
if ( V_48 ) {
F_10 ( & V_36 -> V_40 , L_8 ) ;
return V_48 ;
}
V_7 -> V_56 . V_57 = F_1 ;
V_7 -> V_56 . V_58 = F_6 ;
V_7 -> V_56 . V_36 = V_36 ;
V_48 = F_22 ( V_2 , V_50 ,
& V_7 -> V_56 ) ;
if ( V_48 < 0 ) {
F_10 ( & V_36 -> V_40 , L_9 ) ;
return V_48 ;
}
V_7 -> V_59 = F_23 ( L_10 ,
& V_36 -> V_40 , & V_60 , V_61 ) ;
if ( F_24 ( V_7 -> V_59 ) ) {
F_10 ( & V_36 -> V_40 , L_11 ) ;
return F_25 ( V_7 -> V_59 ) ;
}
return V_48 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_40 . V_53 ;
struct V_6 * V_7 = F_2 ( V_36 ) ;
F_27 ( V_7 -> V_59 ) ;
F_28 ( V_2 , V_50 ) ;
return 0 ;
}
