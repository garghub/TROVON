static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_8 == V_4 -> V_9 )
return V_4 -> V_7 [ V_5 ] . V_10 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_12 , int V_13 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = 0 , V_9 , V_16 = V_17 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_10 < V_16 &&
V_4 -> V_7 [ V_5 ] . V_10 >= V_12 &&
V_4 -> V_7 [ V_5 ] . V_10 <= V_13 ) {
V_15 = V_4 -> V_7 [ V_5 ] . V_8 ;
V_16 = V_4 -> V_7 [ V_5 ] . V_10 ;
if ( V_14 )
* V_14 = V_5 ;
}
if ( V_16 == V_17 )
return - V_11 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_18 ; V_5 ++ ) {
V_9 = ( V_15 & ( 1 << V_5 ) ) >> V_5 ;
F_4 ( V_4 -> V_8 [ V_5 ] . V_19 , V_9 ) ;
}
V_4 -> V_9 = V_15 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_14 >= V_4 -> V_6 )
return - V_11 ;
return V_4 -> V_7 [ V_14 ] . V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_20 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = 0 , V_9 , V_16 = 0 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_10 > V_16 &&
V_4 -> V_7 [ V_5 ] . V_10 >= V_20 &&
V_4 -> V_7 [ V_5 ] . V_10 <= V_21 ) {
V_15 = V_4 -> V_7 [ V_5 ] . V_8 ;
V_16 = V_4 -> V_7 [ V_5 ] . V_10 ;
}
if ( V_16 == 0 )
return - V_11 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_18 ; V_5 ++ ) {
V_9 = ( V_15 & ( 1 << V_5 ) ) >> V_5 ;
F_4 ( V_4 -> V_8 [ V_5 ] . V_19 , V_9 ) ;
}
V_4 -> V_9 = V_15 ;
return 0 ;
}
static struct V_22 *
F_7 ( struct V_23 * V_2 , struct V_24 * V_25 )
{
struct V_22 * V_26 ;
const char * V_27 ;
int V_28 , V_19 , V_29 ;
int V_30 ;
V_26 = F_8 ( V_2 ,
sizeof( struct V_22 ) ,
V_31 ) ;
if ( ! V_26 )
return F_9 ( - V_32 ) ;
V_26 -> V_33 = F_10 ( V_2 , V_25 ) ;
if ( ! V_26 -> V_33 )
return F_9 ( - V_11 ) ;
V_26 -> V_34 = V_26 -> V_33 -> V_35 . V_36 ;
if ( F_11 ( V_25 , L_1 ) )
V_26 -> V_37 = true ;
if ( F_11 ( V_25 , L_2 ) )
V_26 -> V_38 = true ;
F_12 ( V_25 , L_3 , & V_26 -> V_39 ) ;
V_26 -> V_40 = F_13 ( V_25 , L_4 , 0 ) ;
V_26 -> V_18 = F_14 ( V_25 ) ;
V_26 -> V_8 = F_8 ( V_2 ,
sizeof( struct V_19 ) * V_26 -> V_18 ,
V_31 ) ;
if ( ! V_26 -> V_8 )
return F_9 ( - V_32 ) ;
V_28 = F_15 ( V_25 , L_5 ) ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 > 0 && V_28 != V_26 -> V_18 ) {
F_16 ( V_2 , L_6 ) ;
V_28 = 0 ;
}
for ( V_29 = 0 ; V_29 < V_26 -> V_18 ; V_29 ++ ) {
V_19 = F_13 ( V_25 , L_7 , V_29 ) ;
if ( V_19 < 0 )
break;
V_26 -> V_8 [ V_29 ] . V_19 = V_19 ;
if ( V_28 > 0 ) {
F_17 ( V_25 , L_5 , V_29 , & V_30 ) ;
if ( V_30 )
V_26 -> V_8 [ V_29 ] . V_41 = V_42 ;
}
}
V_28 = F_15 ( V_25 , L_8 ) ;
if ( V_28 < 0 ) {
F_18 ( V_2 , L_9 ) ;
return F_9 ( - V_11 ) ;
}
V_26 -> V_7 = F_8 ( V_2 ,
sizeof( struct V_43 )
* ( V_28 / 2 ) ,
V_31 ) ;
if ( ! V_26 -> V_7 )
return F_9 ( - V_32 ) ;
for ( V_29 = 0 ; V_29 < V_28 / 2 ; V_29 ++ ) {
F_17 ( V_25 , L_8 , V_29 * 2 ,
& V_26 -> V_7 [ V_29 ] . V_10 ) ;
F_17 ( V_25 , L_8 , V_29 * 2 + 1 ,
& V_26 -> V_7 [ V_29 ] . V_8 ) ;
}
V_26 -> V_6 = V_29 ;
V_26 -> type = V_44 ;
V_30 = F_19 ( V_25 , L_10 , & V_27 ) ;
if ( V_30 >= 0 ) {
if ( ! strncmp ( L_11 , V_27 , 7 ) )
V_26 -> type = V_44 ;
else if ( ! strncmp ( L_12 , V_27 , 7 ) )
V_26 -> type = V_45 ;
else
F_16 ( V_2 , L_13 ,
V_27 ) ;
}
return V_26 ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_22 * V_26 = F_21 ( & V_47 -> V_2 ) ;
struct V_24 * V_25 = V_47 -> V_2 . V_48 ;
struct V_3 * V_49 ;
struct V_50 V_51 = { } ;
int V_5 , V_30 , V_9 ;
if ( V_25 ) {
V_26 = F_7 ( & V_47 -> V_2 , V_25 ) ;
if ( F_22 ( V_26 ) )
return F_23 ( V_26 ) ;
}
V_49 = F_8 ( & V_47 -> V_2 , sizeof( struct V_3 ) ,
V_31 ) ;
if ( V_49 == NULL )
return - V_32 ;
V_49 -> V_52 . V_36 = F_24 ( V_26 -> V_34 , V_31 ) ;
if ( V_49 -> V_52 . V_36 == NULL ) {
F_18 ( & V_47 -> V_2 , L_14 ) ;
V_30 = - V_32 ;
goto V_53;
}
V_49 -> V_8 = F_25 ( V_26 -> V_8 ,
V_26 -> V_18 * sizeof( struct V_19 ) ,
V_31 ) ;
if ( V_49 -> V_8 == NULL ) {
F_18 ( & V_47 -> V_2 , L_15 ) ;
V_30 = - V_32 ;
goto V_54;
}
V_49 -> V_7 = F_25 ( V_26 -> V_7 ,
V_26 -> V_6 *
sizeof( struct V_43 ) ,
V_31 ) ;
if ( V_49 -> V_7 == NULL ) {
F_18 ( & V_47 -> V_2 , L_16 ) ;
V_30 = - V_32 ;
goto V_55;
}
V_49 -> V_6 = V_26 -> V_6 ;
V_49 -> V_52 . V_56 = V_57 ;
V_49 -> V_52 . V_58 = V_26 -> V_39 ;
switch ( V_26 -> type ) {
case V_44 :
V_49 -> V_52 . type = V_44 ;
V_49 -> V_52 . V_59 = & V_60 ;
V_49 -> V_52 . V_61 = V_26 -> V_6 ;
break;
case V_45 :
V_49 -> V_52 . type = V_45 ;
V_49 -> V_52 . V_59 = & V_62 ;
break;
default:
F_18 ( & V_47 -> V_2 , L_17 ) ;
V_30 = - V_11 ;
goto V_55;
}
V_49 -> V_18 = V_26 -> V_18 ;
V_30 = F_26 ( V_49 -> V_8 , V_49 -> V_18 ) ;
if ( V_30 ) {
F_18 ( & V_47 -> V_2 ,
L_18 , V_30 ) ;
goto V_63;
}
V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_18 ; V_5 ++ ) {
if ( V_26 -> V_8 [ V_5 ] . V_41 & V_42 )
V_9 |= ( 1 << V_5 ) ;
}
V_49 -> V_9 = V_9 ;
V_51 . V_2 = & V_47 -> V_2 ;
V_51 . V_33 = V_26 -> V_33 ;
V_51 . V_64 = V_49 ;
V_51 . V_48 = V_25 ;
if ( V_26 -> V_40 >= 0 )
V_51 . V_65 = V_26 -> V_40 ;
V_51 . V_66 = ! V_26 -> V_37 ;
if ( V_26 -> V_38 ) {
if ( V_26 -> V_37 )
V_51 . V_67 |= V_42 ;
else
V_51 . V_67 |= V_68 ;
} else {
if ( V_26 -> V_37 )
V_51 . V_67 |= V_68 ;
else
V_51 . V_67 |= V_42 ;
}
V_49 -> V_2 = F_27 ( & V_49 -> V_52 , & V_51 ) ;
if ( F_22 ( V_49 -> V_2 ) ) {
V_30 = F_23 ( V_49 -> V_2 ) ;
F_18 ( & V_47 -> V_2 , L_19 , V_30 ) ;
goto V_69;
}
F_28 ( V_47 , V_49 ) ;
return 0 ;
V_69:
F_29 ( V_49 -> V_8 , V_49 -> V_18 ) ;
V_63:
F_30 ( V_49 -> V_7 ) ;
V_55:
F_30 ( V_49 -> V_8 ) ;
V_54:
F_30 ( V_49 -> V_52 . V_36 ) ;
V_53:
return V_30 ;
}
static int F_31 ( struct V_46 * V_47 )
{
struct V_3 * V_49 = F_32 ( V_47 ) ;
F_33 ( V_49 -> V_2 ) ;
F_29 ( V_49 -> V_8 , V_49 -> V_18 ) ;
F_30 ( V_49 -> V_7 ) ;
F_30 ( V_49 -> V_8 ) ;
F_30 ( V_49 -> V_52 . V_36 ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_70 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_70 ) ;
}
