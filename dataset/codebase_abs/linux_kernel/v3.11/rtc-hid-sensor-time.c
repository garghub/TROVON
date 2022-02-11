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
static T_1 F_6 ( T_2 V_12 , char * V_13 )
{
switch ( V_12 ) {
case 1 :
return * ( V_14 * ) V_13 ;
case 2 :
return * ( V_15 * ) V_13 ;
case 4 :
return * ( T_1 * ) V_13 ;
default:
return ( T_1 ) ( ~ 0U ) ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , T_2 V_12 ,
char * V_13 , void * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_16 * V_10 = & V_7 -> V_10 ;
switch ( V_3 ) {
case V_17 :
if ( V_12 == 1 ) {
V_10 -> V_18 = * ( V_14 * ) V_13 ;
if ( V_10 -> V_18 < 70 )
V_10 -> V_18 += 100 ;
} else
V_10 -> V_18 =
( int ) F_6 ( V_12 , V_13 ) - 1900 ;
break;
case V_19 :
V_10 -> V_20 = ( int ) F_6 ( V_12 , V_13 ) - 1 ;
break;
case V_21 :
V_10 -> V_22 = ( int ) F_6 ( V_12 , V_13 ) ;
break;
case V_23 :
V_10 -> V_24 = ( int ) F_6 ( V_12 , V_13 ) ;
break;
case V_25 :
V_10 -> V_26 = ( int ) F_6 ( V_12 , V_13 ) ;
break;
case V_27 :
V_10 -> V_28 = ( int ) F_6 ( V_12 , V_13 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static const char * F_8 ( T_1 V_30 )
{
static const char V_31 [] = L_1 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
if ( V_34 [ V_32 ] == V_30 )
return V_35 [ V_32 ] ;
}
return V_31 ;
}
static int F_9 ( struct V_36 * V_37 ,
struct V_1 * V_2 ,
unsigned V_3 ,
struct V_6 * V_7 )
{
int V_38 , V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 )
if ( F_10 ( V_2 ,
V_39 , V_3 ,
V_34 [ V_32 ] ,
& V_7 -> V_40 [ V_32 ] ) < 0 )
return - V_29 ;
V_38 = V_7 -> V_40 [ 0 ] . V_38 ;
if ( V_38 < 0 ) {
F_11 ( & V_37 -> V_41 , L_2 ) ;
return - V_29 ;
}
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
if ( V_7 -> V_40 [ V_32 ] . V_38 != V_38 ) {
F_11 ( & V_37 -> V_41 ,
L_3 ) ;
return - V_29 ;
}
if ( V_7 -> V_40 [ V_32 ] . V_42 == 3 ||
V_7 -> V_40 [ V_32 ] . V_42 > 4 ) {
F_11 ( & V_37 -> V_41 ,
L_4 ,
F_8 (
V_7 -> V_40 [ V_32 ] . V_30 ) ) ;
return - V_29 ;
}
if ( V_7 -> V_40 [ V_32 ] . V_43 !=
V_44 &&
! ( V_7 -> V_40 [ V_32 ] . V_30 ==
V_27 &&
V_7 -> V_40 [ V_32 ] . V_43 ==
V_45 ) ) {
F_11 ( & V_37 -> V_41 ,
L_5 ,
F_8 (
V_7 -> V_40 [ V_32 ] . V_30 ) ) ;
return - V_29 ;
}
if ( V_7 -> V_40 [ V_32 ] . V_46 ) {
F_11 ( & V_37 -> V_41 ,
L_6 ,
F_8 (
V_7 -> V_40 [ V_32 ] . V_30 ) ) ;
return - V_29 ;
}
}
return 0 ;
}
static int F_12 ( struct V_47 * V_41 , struct V_16 * V_48 )
{
unsigned long V_5 ;
struct V_6 * V_7 =
F_2 ( F_13 ( V_41 ) ) ;
int V_49 ;
F_14 ( V_7 -> V_11 ) ;
F_15 ( V_7 -> V_50 . V_2 ,
V_51 , V_34 [ 0 ] ,
V_7 -> V_40 [ 0 ] . V_38 ) ;
V_49 = F_16 (
& V_7 -> V_11 , V_52 * 6 ) ;
if ( V_49 > 0 ) {
F_3 ( & V_7 -> V_8 , V_5 ) ;
* V_48 = V_7 -> V_9 ;
F_4 ( & V_7 -> V_8 , V_5 ) ;
return 0 ;
}
if ( ! V_49 )
return - V_53 ;
return V_49 ;
}
static int F_17 ( struct V_36 * V_37 )
{
int V_49 = 0 ;
struct V_1 * V_2 = V_37 -> V_41 . V_54 ;
struct V_6 * V_7 = F_18 ( & V_37 -> V_41 ,
sizeof( struct V_6 ) , V_55 ) ;
if ( V_7 == NULL )
return - V_56 ;
F_19 ( V_37 , V_7 ) ;
F_20 ( & V_7 -> V_8 ) ;
F_21 ( & V_7 -> V_11 ) ;
V_7 -> V_50 . V_2 = V_2 ;
V_7 -> V_50 . V_37 = V_37 ;
V_49 = F_22 ( V_2 ,
V_51 ,
& V_7 -> V_50 ) ;
if ( V_49 ) {
F_11 ( & V_37 -> V_41 , L_7 ) ;
return V_49 ;
}
V_49 = F_9 ( V_37 , V_2 , V_51 ,
V_7 ) ;
if ( V_49 ) {
F_11 ( & V_37 -> V_41 , L_8 ) ;
return V_49 ;
}
V_7 -> V_57 . V_58 = F_1 ;
V_7 -> V_57 . V_59 = F_7 ;
V_7 -> V_57 . V_37 = V_37 ;
V_49 = F_23 ( V_2 , V_51 ,
& V_7 -> V_57 ) ;
if ( V_49 < 0 ) {
F_11 ( & V_37 -> V_41 , L_9 ) ;
return V_49 ;
}
V_7 -> V_60 = F_24 ( & V_37 -> V_41 ,
L_10 , & V_61 ,
V_62 ) ;
if ( F_25 ( V_7 -> V_60 ) ) {
F_11 ( & V_37 -> V_41 , L_11 ) ;
return F_26 ( V_7 -> V_60 ) ;
}
return V_49 ;
}
static int F_27 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_41 . V_54 ;
F_28 ( V_2 , V_51 ) ;
return 0 ;
}
