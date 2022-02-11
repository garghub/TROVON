static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = V_8 -> V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_4 -> V_9 . integer . V_9 [ 0 ] == V_8 -> V_10 )
return 0 ;
switch ( V_4 -> V_9 . integer . V_9 [ 0 ] ) {
case 0 :
F_5 ( V_8 -> V_11 , 0 ) ;
F_5 ( V_8 -> V_12 , 0 ) ;
break;
case 1 :
F_5 ( V_8 -> V_11 , 1 ) ;
F_5 ( V_8 -> V_12 , 0 ) ;
break;
case 2 :
F_5 ( V_8 -> V_11 , 0 ) ;
F_5 ( V_8 -> V_12 , 1 ) ;
break;
case 3 :
F_5 ( V_8 -> V_11 , 1 ) ;
F_5 ( V_8 -> V_12 , 1 ) ;
break;
default:
F_6 ( V_6 -> V_13 , L_1 , V_14 ) ;
}
V_8 -> V_10 = V_4 -> V_9 . integer . V_9 [ 0 ] ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
int V_17 ;
V_17 = F_8 ( V_16 -> V_18 , 0 ,
V_19 ,
& V_20 ) ;
if ( V_17 < 0 ) {
F_9 ( V_16 -> V_21 -> V_6 -> V_13 ,
L_2 ,
V_14 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_16 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_28 ;
struct V_27 * V_29 = V_25 -> V_29 ;
unsigned int V_30 ;
unsigned int V_31 = F_11 ( V_23 ) ;
unsigned int V_32 = V_31 > 192000 ? 2 : 4 ;
unsigned int V_33 = 64 ;
V_30 = V_31 * V_33 * V_32 ;
F_12 ( V_28 , 0 , V_30 , V_34 ) ;
F_12 ( V_29 , 0 , V_30 , V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = & V_38 ;
int V_39 ;
int V_40 ;
struct V_41 * V_42 , * V_43 , * V_44 ;
struct V_7 * V_8 =
F_14 ( & V_37 -> V_13 , sizeof( struct V_7 ) ,
V_45 ) ;
struct V_46 * V_13 = & V_37 -> V_13 ;
if ( ! V_8 )
return - V_47 ;
V_42 = F_15 ( V_37 -> V_13 . V_48 ,
L_3 , 0 ) ;
if ( ! V_42 ) {
F_9 ( & V_37 -> V_13 , L_4 ) ;
return - V_49 ;
}
for ( V_40 = 0 ; V_40 < V_6 -> V_50 ; V_40 ++ ) {
if ( V_51 [ V_40 ] . V_52 )
continue;
V_51 [ V_40 ] . V_53 = V_42 ;
}
V_6 -> V_13 = V_13 ;
V_43 = F_15 ( V_37 -> V_13 . V_48 ,
L_5 , 0 ) ;
if ( ! V_43 ) {
F_9 ( & V_37 -> V_13 ,
L_6 ) ;
return - V_49 ;
}
for ( V_40 = 0 ; V_40 < V_6 -> V_50 ; V_40 ++ ) {
if ( V_51 [ V_40 ] . V_54 )
continue;
V_51 [ V_40 ] . V_55 = V_43 ;
}
V_44 = F_15 ( V_37 -> V_13 . V_48 ,
L_7 , 0 ) ;
if ( ! V_44 ) {
F_9 ( & V_37 -> V_13 ,
L_8 ) ;
return - V_49 ;
}
V_51 [ V_56 ] . V_55
= V_44 ;
V_39 = F_16 ( V_6 , L_9 ) ;
if ( V_39 ) {
F_9 ( & V_37 -> V_13 , L_10 , V_39 ) ;
return V_39 ;
}
V_8 -> V_11 =
F_17 ( V_13 -> V_48 , L_11 , 0 ) ;
if ( F_18 ( V_8 -> V_11 ) ) {
V_39 = F_19 ( V_13 , V_8 -> V_11 ,
L_12 ) ;
if ( V_39 )
F_6 ( & V_37 -> V_13 , L_13 ,
V_14 , V_39 ) ;
F_20 ( V_8 -> V_11 , 0 ) ;
}
V_8 -> V_12 =
F_17 ( V_13 -> V_48 , L_14 , 0 ) ;
if ( F_18 ( V_8 -> V_12 ) ) {
V_39 = F_19 ( V_13 , V_8 -> V_12 ,
L_15 ) ;
if ( V_39 )
F_6 ( & V_37 -> V_13 , L_16 ,
V_14 , V_39 ) ;
F_20 ( V_8 -> V_12 , 0 ) ;
}
F_21 ( V_6 , V_8 ) ;
V_39 = F_22 ( & V_37 -> V_13 , V_6 ) ;
if ( V_39 )
F_9 ( & V_37 -> V_13 , L_17 ,
V_14 , V_39 ) ;
return V_39 ;
}
