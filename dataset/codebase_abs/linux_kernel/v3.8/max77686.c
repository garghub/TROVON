static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_6 -> V_7 == V_8 )
V_3 = 0x1 ;
else
V_3 = 0x1 << V_9 ;
V_5 -> V_10 [ V_2 -> V_6 -> V_7 ] = V_3 ;
return F_3 ( V_2 -> V_11 , V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_13 ,
V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_3 ;
if ( V_2 -> V_6 -> V_7 >= V_15 )
return 0 ;
switch ( V_14 ) {
case V_16 :
V_3 = 0x2 << V_17 ;
break;
case V_18 :
V_3 = 0x3 << V_17 ;
break;
default:
F_5 ( L_1 ,
V_2 -> V_6 -> V_19 , V_14 ) ;
return - V_20 ;
}
V_5 -> V_10 [ V_2 -> V_6 -> V_7 ] = V_3 ;
return F_3 ( V_2 -> V_11 , V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_13 ,
V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_14 ) {
case V_21 :
V_3 = 0x1 << V_17 ;
break;
case V_16 :
V_3 = 0x2 << V_17 ;
break;
case V_18 :
V_3 = 0x3 << V_17 ;
break;
default:
F_5 ( L_1 ,
V_2 -> V_6 -> V_19 , V_14 ) ;
return - V_20 ;
}
V_5 -> V_10 [ V_2 -> V_6 -> V_7 ] = V_3 ;
return F_3 ( V_2 -> V_11 , V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_13 ,
V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_2 -> V_11 , V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_13 ,
V_5 -> V_10 [ V_2 -> V_6 -> V_7 ] ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_22 )
{
unsigned int V_23 = V_24 ;
switch ( V_22 ) {
case 1 ... 13750 :
V_23 = V_25 ;
break;
case 13751 ... 27500 :
V_23 = V_26 ;
break;
case 27501 ... 55000 :
V_23 = V_27 ;
break;
case 55001 ... 100000 :
break;
default:
F_5 ( L_2 ,
V_2 -> V_6 -> V_19 , V_22 ) ;
}
return F_3 ( V_2 -> V_11 , V_2 -> V_6 -> V_12 ,
V_28 , V_23 << 6 ) ;
}
static int F_9 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = F_10 ( V_30 -> V_35 . V_36 ) ;
struct V_37 * V_38 , * V_39 ;
struct V_40 * V_41 ;
struct V_42 V_43 ;
unsigned int V_44 ;
V_38 = V_34 -> V_35 -> V_45 ;
V_39 = F_11 ( V_38 , L_3 ) ;
if ( ! V_39 ) {
F_12 ( & V_30 -> V_35 , L_4 ) ;
return - V_20 ;
}
V_32 -> V_46 = F_13 ( V_47 ) ;
V_41 = F_14 ( & V_30 -> V_35 , sizeof( * V_41 ) *
V_32 -> V_46 , V_48 ) ;
if ( ! V_41 ) {
F_12 ( & V_30 -> V_35 ,
L_5 ) ;
return - V_49 ;
}
for ( V_44 = 0 ; V_44 < V_32 -> V_46 ; V_44 ++ ) {
V_43 . V_19 = V_47 [ V_44 ] . V_19 ;
V_43 . V_50 = NULL ;
V_43 . V_45 = NULL ;
V_42 ( & V_30 -> V_35 , V_39 , & V_43 , 1 ) ;
V_41 [ V_44 ] . V_51 = V_43 . V_50 ;
V_41 [ V_44 ] . V_45 = V_43 . V_45 ;
}
V_32 -> V_47 = V_41 ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_33 * V_34 = F_10 ( V_30 -> V_35 . V_36 ) ;
struct V_31 * V_32 = F_16 ( V_34 -> V_35 ) ;
struct V_4 * V_5 ;
int V_44 , V_52 = 0 ;
struct V_53 V_54 = { } ;
F_17 ( & V_30 -> V_35 , L_6 , V_55 ) ;
if ( ! V_32 ) {
F_12 ( & V_30 -> V_35 , L_7 ) ;
return - V_56 ;
}
if ( V_34 -> V_35 -> V_45 ) {
V_52 = F_9 ( V_30 , V_32 ) ;
if ( V_52 )
return V_52 ;
}
if ( V_32 -> V_46 != V_57 ) {
F_12 ( & V_30 -> V_35 ,
L_8 ) ;
return - V_20 ;
}
V_5 = F_14 ( & V_30 -> V_35 , sizeof( struct V_4 ) ,
V_48 ) ;
if ( ! V_5 )
return - V_49 ;
V_54 . V_35 = & V_30 -> V_35 ;
V_54 . V_11 = V_34 -> V_11 ;
V_54 . V_58 = V_5 ;
F_18 ( V_30 , V_5 ) ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
V_54 . V_50 = V_32 -> V_47 [ V_44 ] . V_51 ;
V_54 . V_45 = V_32 -> V_47 [ V_44 ] . V_45 ;
V_5 -> V_10 [ V_44 ] = V_47 [ V_44 ] . V_13 ;
V_5 -> V_2 [ V_44 ] = F_19 ( & V_47 [ V_44 ] , & V_54 ) ;
if ( F_20 ( V_5 -> V_2 [ V_44 ] ) ) {
V_52 = F_21 ( V_5 -> V_2 [ V_44 ] ) ;
F_12 ( & V_30 -> V_35 ,
L_9 , V_44 ) ;
V_5 -> V_2 [ V_44 ] = NULL ;
goto V_59;
}
}
return 0 ;
V_59:
while ( -- V_44 >= 0 )
F_22 ( V_5 -> V_2 [ V_44 ] ) ;
return V_52 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_24 ( V_30 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ )
F_22 ( V_5 -> V_2 [ V_44 ] ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_60 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_60 ) ;
}
