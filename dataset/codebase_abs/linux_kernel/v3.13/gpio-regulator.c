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
struct V_27 * V_28 ;
const char * V_29 ;
int V_30 , V_19 , V_31 ;
int V_32 ;
V_26 = F_8 ( V_2 ,
sizeof( struct V_22 ) ,
V_33 ) ;
if ( ! V_26 )
return F_9 ( - V_34 ) ;
V_26 -> V_35 = F_10 ( V_2 , V_25 ) ;
if ( ! V_26 -> V_35 )
return F_9 ( - V_11 ) ;
V_26 -> V_36 = V_26 -> V_35 -> V_37 . V_38 ;
if ( F_11 ( V_25 , L_1 ) )
V_26 -> V_39 = true ;
if ( F_11 ( V_25 , L_2 ) )
V_26 -> V_40 = true ;
F_12 ( V_25 , L_3 , & V_26 -> V_41 ) ;
V_26 -> V_42 = F_13 ( V_25 , L_4 , 0 ) ;
V_26 -> V_18 = F_14 ( V_25 ) ;
V_26 -> V_8 = F_8 ( V_2 ,
sizeof( struct V_19 ) * V_26 -> V_18 ,
V_33 ) ;
if ( ! V_26 -> V_8 )
return F_9 ( - V_34 ) ;
for ( V_31 = 0 ; V_31 < V_26 -> V_18 ; V_31 ++ ) {
V_19 = F_13 ( V_25 , L_5 , V_31 ) ;
if ( V_19 < 0 )
break;
V_26 -> V_8 [ V_31 ] . V_19 = V_19 ;
}
V_28 = F_15 ( V_25 , L_6 , NULL ) ;
if ( ! V_28 ) {
F_16 ( V_2 , L_7 ) ;
return F_9 ( - V_11 ) ;
}
V_30 = V_28 -> V_43 / sizeof( int ) ;
V_26 -> V_7 = F_8 ( V_2 ,
sizeof( struct V_44 )
* ( V_30 / 2 ) ,
V_33 ) ;
if ( ! V_26 -> V_7 )
return F_9 ( - V_34 ) ;
for ( V_31 = 0 ; V_31 < V_30 / 2 ; V_31 ++ ) {
V_26 -> V_7 [ V_31 ] . V_10 =
F_17 ( ( int * ) V_28 -> V_10 + ( V_31 * 2 ) ) ;
V_26 -> V_7 [ V_31 ] . V_8 =
F_17 ( ( int * ) V_28 -> V_10 + ( V_31 * 2 + 1 ) ) ;
}
V_26 -> V_6 = V_31 ;
V_32 = F_18 ( V_25 , L_8 , & V_29 ) ;
if ( V_32 < 0 ) {
F_16 ( V_2 , L_9 ) ;
return F_9 ( - V_11 ) ;
}
if ( ! strncmp ( L_10 , V_29 , 7 ) )
V_26 -> type = V_45 ;
else if ( ! strncmp ( L_11 , V_29 , 7 ) )
V_26 -> type = V_46 ;
return V_26 ;
}
static int F_19 ( struct V_47 * V_48 )
{
struct V_22 * V_26 = F_20 ( & V_48 -> V_2 ) ;
struct V_24 * V_25 = V_48 -> V_2 . V_49 ;
struct V_3 * V_50 ;
struct V_51 V_52 = { } ;
int V_5 , V_32 , V_9 ;
if ( V_25 ) {
V_26 = F_7 ( & V_48 -> V_2 , V_25 ) ;
if ( F_21 ( V_26 ) )
return F_22 ( V_26 ) ;
}
V_50 = F_8 ( & V_48 -> V_2 , sizeof( struct V_3 ) ,
V_33 ) ;
if ( V_50 == NULL ) {
F_16 ( & V_48 -> V_2 , L_12 ) ;
return - V_34 ;
}
V_50 -> V_53 . V_38 = F_23 ( V_26 -> V_36 , V_33 ) ;
if ( V_50 -> V_53 . V_38 == NULL ) {
F_16 ( & V_48 -> V_2 , L_13 ) ;
V_32 = - V_34 ;
goto V_54;
}
V_50 -> V_8 = F_24 ( V_26 -> V_8 ,
V_26 -> V_18 * sizeof( struct V_19 ) ,
V_33 ) ;
if ( V_50 -> V_8 == NULL ) {
F_16 ( & V_48 -> V_2 , L_14 ) ;
V_32 = - V_34 ;
goto V_55;
}
V_50 -> V_7 = F_24 ( V_26 -> V_7 ,
V_26 -> V_6 *
sizeof( struct V_44 ) ,
V_33 ) ;
if ( V_50 -> V_7 == NULL ) {
F_16 ( & V_48 -> V_2 , L_15 ) ;
V_32 = - V_34 ;
goto V_56;
}
V_50 -> V_6 = V_26 -> V_6 ;
V_50 -> V_53 . V_57 = V_58 ;
V_50 -> V_53 . V_59 = V_26 -> V_41 ;
switch ( V_26 -> type ) {
case V_45 :
V_50 -> V_53 . type = V_45 ;
V_50 -> V_53 . V_60 = & V_61 ;
V_50 -> V_53 . V_62 = V_26 -> V_6 ;
break;
case V_46 :
V_50 -> V_53 . type = V_46 ;
V_50 -> V_53 . V_60 = & V_63 ;
break;
default:
F_16 ( & V_48 -> V_2 , L_16 ) ;
V_32 = - V_11 ;
goto V_56;
}
V_50 -> V_18 = V_26 -> V_18 ;
V_32 = F_25 ( V_50 -> V_8 , V_50 -> V_18 ) ;
if ( V_32 ) {
F_16 ( & V_48 -> V_2 ,
L_17 , V_32 ) ;
goto V_64;
}
V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_50 -> V_18 ; V_5 ++ ) {
if ( V_26 -> V_8 [ V_5 ] . V_65 & V_66 )
V_9 |= ( 1 << V_5 ) ;
}
V_50 -> V_9 = V_9 ;
V_52 . V_2 = & V_48 -> V_2 ;
V_52 . V_35 = V_26 -> V_35 ;
V_52 . V_67 = V_50 ;
V_52 . V_49 = V_25 ;
if ( V_26 -> V_42 >= 0 )
V_52 . V_68 = V_26 -> V_42 ;
V_52 . V_69 = ! V_26 -> V_39 ;
if ( V_26 -> V_40 ) {
if ( V_26 -> V_39 )
V_52 . V_70 |= V_66 ;
else
V_52 . V_70 |= V_71 ;
} else {
if ( V_26 -> V_39 )
V_52 . V_70 |= V_71 ;
else
V_52 . V_70 |= V_66 ;
}
V_50 -> V_2 = F_26 ( & V_50 -> V_53 , & V_52 ) ;
if ( F_21 ( V_50 -> V_2 ) ) {
V_32 = F_22 ( V_50 -> V_2 ) ;
F_16 ( & V_48 -> V_2 , L_18 , V_32 ) ;
goto V_72;
}
F_27 ( V_48 , V_50 ) ;
return 0 ;
V_72:
F_28 ( V_50 -> V_8 , V_50 -> V_18 ) ;
V_64:
F_29 ( V_50 -> V_7 ) ;
V_56:
F_29 ( V_50 -> V_8 ) ;
V_55:
F_29 ( V_50 -> V_53 . V_38 ) ;
V_54:
return V_32 ;
}
static int F_30 ( struct V_47 * V_48 )
{
struct V_3 * V_50 = F_31 ( V_48 ) ;
F_32 ( V_50 -> V_2 ) ;
F_28 ( V_50 -> V_8 , V_50 -> V_18 ) ;
F_29 ( V_50 -> V_7 ) ;
F_29 ( V_50 -> V_8 ) ;
F_29 ( V_50 -> V_53 . V_38 ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
return F_34 ( & V_73 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_73 ) ;
}
