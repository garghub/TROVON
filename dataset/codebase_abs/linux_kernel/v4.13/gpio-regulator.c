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
F_7 ( struct V_23 * V_2 , struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
struct V_22 * V_28 ;
const char * V_29 ;
int V_30 , V_19 , V_31 ;
int V_32 ;
V_28 = F_8 ( V_2 ,
sizeof( struct V_22 ) ,
V_33 ) ;
if ( ! V_28 )
return F_9 ( - V_34 ) ;
V_28 -> V_35 = F_10 ( V_2 , V_25 , V_27 ) ;
if ( ! V_28 -> V_35 )
return F_9 ( - V_11 ) ;
V_28 -> V_36 = V_28 -> V_35 -> V_37 . V_38 ;
if ( F_11 ( V_25 , L_1 ) )
V_28 -> V_39 = true ;
if ( F_11 ( V_25 , L_2 ) )
V_28 -> V_40 = true ;
F_12 ( V_25 , L_3 , & V_28 -> V_41 ) ;
V_28 -> V_42 = F_13 ( V_25 , L_4 , 0 ) ;
if ( V_28 -> V_42 < 0 && V_28 -> V_42 != - V_43 )
return F_9 ( V_28 -> V_42 ) ;
V_32 = F_14 ( V_25 ) ;
if ( ( V_32 < 0 ) && ( V_32 != - V_43 ) )
return F_9 ( V_32 ) ;
if ( V_32 > 0 ) {
V_28 -> V_18 = V_32 ;
V_28 -> V_8 = F_8 ( V_2 ,
sizeof( struct V_19 ) * V_28 -> V_18 ,
V_33 ) ;
if ( ! V_28 -> V_8 )
return F_9 ( - V_34 ) ;
V_30 = F_15 ( V_25 , L_5 ) ;
if ( V_30 < 0 )
V_30 = 0 ;
if ( V_30 > 0 && V_30 != V_28 -> V_18 ) {
F_16 ( V_2 , L_6 ) ;
V_30 = 0 ;
}
for ( V_31 = 0 ; V_31 < V_28 -> V_18 ; V_31 ++ ) {
V_19 = F_13 ( V_25 , L_7 , V_31 ) ;
if ( V_19 < 0 ) {
if ( V_19 != - V_43 )
return F_9 ( V_19 ) ;
break;
}
V_28 -> V_8 [ V_31 ] . V_19 = V_19 ;
if ( V_30 > 0 ) {
F_17 ( V_25 , L_5 ,
V_31 , & V_32 ) ;
if ( V_32 )
V_28 -> V_8 [ V_31 ] . V_44 =
V_45 ;
}
}
}
V_30 = F_15 ( V_25 , L_8 ) ;
if ( V_30 < 0 ) {
F_18 ( V_2 , L_9 ) ;
return F_9 ( - V_11 ) ;
}
V_28 -> V_7 = F_8 ( V_2 ,
sizeof( struct V_46 )
* ( V_30 / 2 ) ,
V_33 ) ;
if ( ! V_28 -> V_7 )
return F_9 ( - V_34 ) ;
for ( V_31 = 0 ; V_31 < V_30 / 2 ; V_31 ++ ) {
F_17 ( V_25 , L_8 , V_31 * 2 ,
& V_28 -> V_7 [ V_31 ] . V_10 ) ;
F_17 ( V_25 , L_8 , V_31 * 2 + 1 ,
& V_28 -> V_7 [ V_31 ] . V_8 ) ;
}
V_28 -> V_6 = V_31 ;
V_28 -> type = V_47 ;
V_32 = F_19 ( V_25 , L_10 , & V_29 ) ;
if ( V_32 >= 0 ) {
if ( ! strncmp ( L_11 , V_29 , 7 ) )
V_28 -> type = V_47 ;
else if ( ! strncmp ( L_12 , V_29 , 7 ) )
V_28 -> type = V_48 ;
else
F_16 ( V_2 , L_13 ,
V_29 ) ;
}
return V_28 ;
}
static int F_20 ( struct V_49 * V_50 )
{
struct V_22 * V_28 = F_21 ( & V_50 -> V_2 ) ;
struct V_24 * V_25 = V_50 -> V_2 . V_51 ;
struct V_3 * V_52 ;
struct V_53 V_54 = { } ;
int V_5 , V_32 , V_9 ;
V_52 = F_8 ( & V_50 -> V_2 , sizeof( struct V_3 ) ,
V_33 ) ;
if ( V_52 == NULL )
return - V_34 ;
if ( V_25 ) {
V_28 = F_7 ( & V_50 -> V_2 , V_25 ,
& V_52 -> V_27 ) ;
if ( F_22 ( V_28 ) )
return F_23 ( V_28 ) ;
}
V_52 -> V_27 . V_38 = F_24 ( V_28 -> V_36 , V_33 ) ;
if ( V_52 -> V_27 . V_38 == NULL ) {
F_18 ( & V_50 -> V_2 , L_14 ) ;
V_32 = - V_34 ;
goto V_55;
}
if ( V_28 -> V_18 != 0 ) {
V_52 -> V_8 = F_25 ( V_28 -> V_8 ,
V_28 -> V_18 * sizeof( struct V_19 ) ,
V_33 ) ;
if ( V_52 -> V_8 == NULL ) {
F_18 ( & V_50 -> V_2 , L_15 ) ;
V_32 = - V_34 ;
goto V_56;
}
V_52 -> V_18 = V_28 -> V_18 ;
V_32 = F_26 ( V_52 -> V_8 , V_52 -> V_18 ) ;
if ( V_32 ) {
if ( V_32 != - V_57 )
F_18 ( & V_50 -> V_2 ,
L_16 ,
V_32 ) ;
goto V_58;
}
}
V_52 -> V_7 = F_25 ( V_28 -> V_7 ,
V_28 -> V_6 *
sizeof( struct V_46 ) ,
V_33 ) ;
if ( V_52 -> V_7 == NULL ) {
F_18 ( & V_50 -> V_2 , L_17 ) ;
V_32 = - V_34 ;
goto V_59;
}
V_52 -> V_6 = V_28 -> V_6 ;
V_52 -> V_27 . V_60 = V_61 ;
V_52 -> V_27 . V_62 = V_28 -> V_41 ;
switch ( V_28 -> type ) {
case V_47 :
V_52 -> V_27 . type = V_47 ;
V_52 -> V_27 . V_63 = & V_64 ;
V_52 -> V_27 . V_65 = V_28 -> V_6 ;
break;
case V_48 :
V_52 -> V_27 . type = V_48 ;
V_52 -> V_27 . V_63 = & V_66 ;
break;
default:
F_18 ( & V_50 -> V_2 , L_18 ) ;
V_32 = - V_11 ;
goto V_59;
}
V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_52 -> V_18 ; V_5 ++ ) {
if ( V_28 -> V_8 [ V_5 ] . V_44 & V_45 )
V_9 |= ( 1 << V_5 ) ;
}
V_52 -> V_9 = V_9 ;
V_54 . V_2 = & V_50 -> V_2 ;
V_54 . V_35 = V_28 -> V_35 ;
V_54 . V_67 = V_52 ;
V_54 . V_51 = V_25 ;
if ( F_27 ( V_28 -> V_42 ) ) {
V_54 . V_68 = V_28 -> V_42 ;
V_54 . V_69 = true ;
}
V_54 . V_70 = ! V_28 -> V_39 ;
if ( V_28 -> V_40 ) {
if ( V_28 -> V_39 )
V_54 . V_71 |= V_45 ;
else
V_54 . V_71 |= V_72 ;
} else {
if ( V_28 -> V_39 )
V_54 . V_71 |= V_72 ;
else
V_54 . V_71 |= V_45 ;
}
V_52 -> V_2 = F_28 ( & V_52 -> V_27 , & V_54 ) ;
if ( F_22 ( V_52 -> V_2 ) ) {
V_32 = F_23 ( V_52 -> V_2 ) ;
F_18 ( & V_50 -> V_2 , L_19 , V_32 ) ;
goto V_73;
}
F_29 ( V_50 , V_52 ) ;
return 0 ;
V_73:
F_30 ( V_52 -> V_8 , V_52 -> V_18 ) ;
V_58:
F_31 ( V_52 -> V_7 ) ;
V_59:
F_31 ( V_52 -> V_8 ) ;
V_56:
F_31 ( V_52 -> V_27 . V_38 ) ;
V_55:
return V_32 ;
}
static int F_32 ( struct V_49 * V_50 )
{
struct V_3 * V_52 = F_33 ( V_50 ) ;
F_34 ( V_52 -> V_2 ) ;
F_30 ( V_52 -> V_8 , V_52 -> V_18 ) ;
F_31 ( V_52 -> V_7 ) ;
F_31 ( V_52 -> V_8 ) ;
F_31 ( V_52 -> V_27 . V_38 ) ;
return 0 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_74 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_74 ) ;
}
