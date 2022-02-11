static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 = F_3 ( V_2 ) ;
if ( V_7 == V_8 )
V_3 = 0x1 ;
else
V_3 = 0x1 << V_9 ;
V_6 = F_4 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_2 -> V_11 -> V_13 , V_3 ) ;
if ( V_6 )
return V_6 ;
V_5 -> V_14 [ V_7 ] = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_3 ;
int V_6 , V_7 = F_3 ( V_2 ) ;
if ( V_7 >= V_16 )
return 0 ;
switch ( V_15 ) {
case V_17 :
V_3 = 0x2 << V_18 ;
break;
case V_19 :
V_3 = 0x3 << V_18 ;
break;
default:
F_6 ( L_1 ,
V_2 -> V_11 -> V_20 , V_15 ) ;
return - V_21 ;
}
V_6 = F_4 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_2 -> V_11 -> V_13 , V_3 ) ;
if ( V_6 )
return V_6 ;
V_5 -> V_14 [ V_7 ] = V_3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_15 ) {
case V_22 :
V_3 = 0x1 << V_18 ;
break;
case V_17 :
V_3 = 0x2 << V_18 ;
break;
case V_19 :
V_3 = 0x3 << V_18 ;
break;
default:
F_6 ( L_1 ,
V_2 -> V_11 -> V_20 , V_15 ) ;
return - V_21 ;
}
V_6 = F_4 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_2 -> V_11 -> V_13 , V_3 ) ;
if ( V_6 )
return V_6 ;
V_5 -> V_14 [ F_3 ( V_2 ) ] = V_3 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_2 -> V_11 -> V_13 ,
V_5 -> V_14 [ F_3 ( V_2 ) ] ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_23 )
{
unsigned int V_24 = V_25 ;
switch ( V_23 ) {
case 1 ... 13750 :
V_24 = V_26 ;
break;
case 13751 ... 27500 :
V_24 = V_27 ;
break;
case 27501 ... 55000 :
V_24 = V_28 ;
break;
case 55001 ... 100000 :
break;
default:
F_6 ( L_2 ,
V_2 -> V_11 -> V_20 , V_23 ) ;
}
return F_4 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_29 , V_24 << 6 ) ;
}
static int F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = F_11 ( V_31 -> V_36 . V_37 ) ;
struct V_38 * V_39 , * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 = { } ;
unsigned int V_45 ;
V_39 = V_35 -> V_36 -> V_46 ;
V_40 = F_12 ( V_39 , L_3 ) ;
if ( ! V_40 ) {
F_13 ( & V_31 -> V_36 , L_4 ) ;
return - V_21 ;
}
V_33 -> V_47 = F_14 ( V_48 ) ;
V_42 = F_15 ( & V_31 -> V_36 , sizeof( * V_42 ) *
V_33 -> V_47 , V_49 ) ;
if ( ! V_42 ) {
F_16 ( V_40 ) ;
return - V_50 ;
}
for ( V_45 = 0 ; V_45 < V_33 -> V_47 ; V_45 ++ ) {
V_44 . V_20 = V_48 [ V_45 ] . V_20 ;
V_44 . V_51 = NULL ;
V_44 . V_46 = NULL ;
V_43 ( & V_31 -> V_36 , V_40 , & V_44 , 1 ) ;
V_42 [ V_45 ] . V_52 = V_44 . V_51 ;
V_42 [ V_45 ] . V_46 = V_44 . V_46 ;
}
V_33 -> V_48 = V_42 ;
F_16 ( V_40 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
return 0 ;
}
static int F_17 ( struct V_30 * V_31 )
{
struct V_34 * V_35 = F_11 ( V_31 -> V_36 . V_37 ) ;
struct V_32 * V_33 = F_18 ( V_35 -> V_36 ) ;
struct V_4 * V_5 ;
int V_45 , V_6 = 0 ;
struct V_53 V_54 = { } ;
F_19 ( & V_31 -> V_36 , L_5 , V_55 ) ;
if ( ! V_33 ) {
F_13 ( & V_31 -> V_36 , L_6 ) ;
return - V_56 ;
}
if ( V_35 -> V_36 -> V_46 ) {
V_6 = F_10 ( V_31 , V_33 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_33 -> V_47 != V_57 ) {
F_13 ( & V_31 -> V_36 ,
L_7 ) ;
return - V_21 ;
}
V_5 = F_15 ( & V_31 -> V_36 , sizeof( struct V_4 ) ,
V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_54 . V_36 = & V_31 -> V_36 ;
V_54 . V_10 = V_35 -> V_10 ;
V_54 . V_58 = V_5 ;
F_20 ( V_31 , V_5 ) ;
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
struct V_1 * V_2 ;
V_54 . V_51 = V_33 -> V_48 [ V_45 ] . V_52 ;
V_54 . V_46 = V_33 -> V_48 [ V_45 ] . V_46 ;
V_5 -> V_14 [ V_45 ] = V_48 [ V_45 ] . V_13 ;
V_2 = F_21 ( & V_31 -> V_36 ,
& V_48 [ V_45 ] , & V_54 ) ;
if ( F_22 ( V_2 ) ) {
F_13 ( & V_31 -> V_36 ,
L_8 , V_45 ) ;
return F_23 ( V_2 ) ;
}
}
return 0 ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_59 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_59 ) ;
}
