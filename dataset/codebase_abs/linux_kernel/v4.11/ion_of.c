static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_6 [ V_7 ] . V_8 ; V_7 ++ ) {
if ( F_2 ( V_2 , V_6 [ V_7 ] . V_9 ) )
break;
}
if ( ! V_6 [ V_7 ] . V_8 )
return - V_10 ;
V_4 -> V_11 = V_6 [ V_7 ] . V_12 ;
V_4 -> type = V_6 [ V_7 ] . type ;
V_4 -> V_8 = V_6 [ V_7 ] . V_8 ;
V_4 -> V_13 = V_6 [ V_7 ] . V_13 ;
F_3 ( L_1 , V_14 ,
V_4 -> V_11 , V_4 -> type , V_4 -> V_8 , V_4 -> V_13 ) ;
return 0 ;
}
static int F_4 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_17 = 0 ;
switch ( V_4 -> type ) {
case V_18 :
case V_19 :
if ( V_4 -> V_20 && V_4 -> V_21 )
return 0 ;
V_17 = F_5 ( V_4 -> V_22 ) ;
break;
default:
break;
}
return V_17 ;
}
struct V_23 * F_6 ( struct V_15 * V_24 ,
struct V_5 * V_6 )
{
int V_25 , V_17 ;
const struct V_1 * V_26 = V_24 -> V_27 . V_28 ;
struct V_1 * V_29 ;
struct V_3 * V_30 ;
struct V_23 * V_31 ;
int V_7 = 0 ;
V_25 = F_7 ( V_26 ) ;
if ( ! V_25 )
return F_8 ( - V_32 ) ;
V_30 = F_9 ( & V_24 -> V_27 ,
sizeof( struct V_3 ) * V_25 ,
V_33 ) ;
if ( ! V_30 )
return F_8 ( - V_34 ) ;
V_31 = F_9 ( & V_24 -> V_27 , sizeof( struct V_23 ) ,
V_33 ) ;
if ( ! V_31 )
return F_8 ( - V_34 ) ;
F_10 (dt_node, node) {
struct V_15 * V_35 ;
V_17 = F_1 ( V_29 , & V_30 [ V_7 ] , V_6 ) ;
if ( V_17 )
return F_8 ( V_17 ) ;
V_35 = F_11 ( V_29 , V_30 [ V_7 ] . V_8 ,
& V_24 -> V_27 ) ;
if ( ! V_35 )
return F_8 ( - V_34 ) ;
V_35 -> V_27 . V_36 = & V_30 [ V_7 ] ;
V_30 [ V_7 ] . V_22 = & V_35 -> V_27 ;
V_17 = F_4 ( V_24 , V_29 , & V_30 [ V_7 ] ) ;
if ( V_17 )
goto V_37;
V_7 ++ ;
}
V_31 -> V_30 = V_30 ;
V_31 -> V_38 = V_25 ;
return V_31 ;
V_37:
for ( ; V_7 >= 0 ; V_7 -- )
if ( V_30 [ V_7 ] . V_22 )
F_12 ( F_13 ( V_30 [ V_7 ] . V_22 ) ) ;
return F_8 ( V_17 ) ;
}
void F_14 ( struct V_23 * V_31 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_31 -> V_38 ; V_7 ++ )
if ( V_31 -> V_30 [ V_7 ] . V_22 )
F_12 ( F_13 (
V_31 -> V_30 [ V_7 ] . V_22 ) ) ;
}
static int F_15 ( struct V_39 * V_40 , struct V_41 * V_27 )
{
struct V_15 * V_24 = F_13 ( V_27 ) ;
struct V_3 * V_4 = V_24 -> V_27 . V_36 ;
V_4 -> V_20 = V_40 -> V_20 ;
V_4 -> V_20 = V_40 -> V_21 ;
F_16 ( L_2 , V_14 ,
V_4 -> V_8 , & V_40 -> V_20 , & V_40 -> V_21 , V_27 ) ;
return 0 ;
}
static void F_17 ( struct V_39 * V_40 ,
struct V_41 * V_27 )
{
}
static int T_1 F_18 ( struct V_39 * V_40 )
{
T_2 V_21 = V_40 -> V_21 ;
V_21 = V_21 / 1024 ;
F_3 ( L_3 ,
& V_40 -> V_20 , & V_21 ) ;
V_40 -> V_42 = & V_43 ;
return 0 ;
}
