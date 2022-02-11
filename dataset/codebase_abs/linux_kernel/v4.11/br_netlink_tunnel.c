static T_1 F_1 ( void )
{
return F_2 ( 0 ) +
F_2 ( sizeof( V_1 ) ) +
F_2 ( sizeof( V_2 ) ) +
F_2 ( sizeof( V_2 ) ) ;
}
static bool F_3 ( struct V_3 * V_4 ,
struct V_3 * V_5 )
{
T_2 V_6 = F_4 ( V_4 -> V_7 . V_8 ) ;
T_2 V_9 = F_4 ( V_5 -> V_7 . V_8 ) ;
return ( F_5 ( V_6 ) - F_5 ( V_9 ) ) == 1 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_3 * V_12 , * V_13 = NULL , * V_14 = NULL ;
int V_15 = 0 ;
F_7 (v, &vg->vlan_list, vlist) {
if ( ! F_8 ( V_12 ) || ! V_12 -> V_7 . V_8 )
continue;
if ( ! V_13 ) {
goto V_16;
} else if ( ( V_12 -> V_17 - V_14 -> V_17 ) == 1 &&
F_3 ( V_12 , V_14 ) ) {
V_14 = V_12 ;
continue;
} else {
if ( ( V_14 -> V_17 - V_13 -> V_17 ) > 0 )
V_15 += 2 ;
else
V_15 += 1 ;
}
V_16:
V_13 = V_12 ;
V_14 = V_12 ;
}
if ( V_13 && V_14 ) {
if ( ( V_14 -> V_17 - V_13 -> V_17 ) > 0 )
V_15 += 2 ;
else
V_15 += 1 ;
}
return V_15 ;
}
int F_9 ( struct V_10 * V_11 )
{
int V_15 ;
if ( ! V_11 )
return 0 ;
F_10 () ;
V_15 = F_6 ( V_11 ) ;
F_11 () ;
return V_15 * F_1 () ;
}
static int F_12 ( struct V_18 * V_19 , V_2 V_17 ,
T_3 V_8 , V_2 V_20 )
{
T_2 V_21 = F_4 ( V_8 ) ;
struct V_22 * V_23 ;
V_23 = F_13 ( V_19 , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
if ( F_14 ( V_19 , V_26 ,
F_5 ( V_21 ) ) )
goto V_27;
if ( F_15 ( V_19 , V_28 ,
V_17 ) )
goto V_27;
if ( F_15 ( V_19 , V_29 ,
V_20 ) )
goto V_27;
F_16 ( V_19 , V_23 ) ;
return 0 ;
V_27:
F_17 ( V_19 , V_23 ) ;
return - V_25 ;
}
static int F_18 ( struct V_18 * V_19 ,
struct V_3 * V_13 ,
struct V_3 * V_14 )
{
int V_30 ;
if ( V_14 && ( V_14 -> V_17 - V_13 -> V_17 ) > 0 ) {
V_30 = F_12 ( V_19 , V_13 -> V_17 ,
V_13 -> V_7 . V_8 ,
V_31 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_12 ( V_19 , V_14 -> V_17 ,
V_14 -> V_7 . V_8 ,
V_32 ) ;
if ( V_30 )
return V_30 ;
} else {
V_30 = F_12 ( V_19 , V_13 -> V_17 ,
V_13 -> V_7 . V_8 ,
0 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
int F_19 ( struct V_18 * V_19 ,
struct V_10 * V_11 )
{
struct V_3 * V_13 = NULL ;
struct V_3 * V_14 = NULL ;
struct V_3 * V_12 ;
int V_30 ;
F_7 (v, &vg->vlan_list, vlist) {
if ( ! F_8 ( V_12 ) )
continue;
if ( ! V_12 -> V_7 . V_33 )
continue;
if ( ! V_13 ) {
goto V_16;
} else if ( ( V_12 -> V_17 - V_14 -> V_17 ) == 1 &&
F_3 ( V_12 , V_14 ) ) {
V_14 = V_12 ;
continue;
} else {
V_30 = F_18 ( V_19 , V_13 , V_14 ) ;
if ( V_30 )
return V_30 ;
}
V_16:
V_13 = V_12 ;
V_14 = V_12 ;
}
if ( V_13 ) {
V_30 = F_18 ( V_19 , V_13 , V_14 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_20 ( struct V_34 * V_35 , int V_36 ,
V_2 V_17 , V_1 V_37 )
{
int V_30 = 0 ;
if ( ! V_35 )
return - V_38 ;
switch ( V_36 ) {
case V_39 :
V_30 = F_21 ( V_35 , V_17 , V_37 ) ;
break;
case V_40 :
F_22 ( V_35 , V_17 ) ;
break;
}
return V_30 ;
}
int F_23 ( struct V_22 * V_41 ,
struct V_42 * V_7 )
{
struct V_22 * V_43 [ V_44 + 1 ] ;
V_1 V_37 ;
V_2 V_17 , V_20 = 0 ;
int V_30 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_30 = F_24 ( V_43 , V_44 ,
V_41 , V_45 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_43 [ V_26 ] ||
! V_43 [ V_28 ] )
return - V_38 ;
V_37 = F_25 ( V_43 [ V_26 ] ) ;
V_17 = F_26 ( V_43 [ V_28 ] ) ;
if ( V_17 >= V_46 )
return - V_47 ;
if ( V_43 [ V_29 ] )
V_20 = F_26 ( V_43 [ V_29 ] ) ;
V_7 -> V_48 = V_37 ;
V_7 -> V_17 = V_17 ;
V_7 -> V_20 = V_20 ;
return 0 ;
}
int F_27 ( struct V_49 * V_50 ,
struct V_34 * V_35 , int V_36 ,
struct V_42 * V_51 ,
struct V_42 * V_52 )
{
int V_30 ;
if ( V_51 -> V_20 & V_31 ) {
if ( V_52 -> V_20 & V_31 )
return - V_38 ;
memcpy ( V_52 , V_51 , sizeof( struct V_42 ) ) ;
} else if ( V_51 -> V_20 & V_32 ) {
int V_53 , V_12 ;
if ( ! ( V_52 -> V_20 & V_31 ) )
return - V_38 ;
if ( ( V_51 -> V_17 - V_52 -> V_17 ) !=
( V_51 -> V_48 - V_52 -> V_48 ) )
return - V_38 ;
V_53 = V_52 -> V_48 ;
for ( V_12 = V_52 -> V_17 ; V_12 <= V_51 -> V_17 ; V_12 ++ ) {
V_30 = F_20 ( V_35 , V_36 , V_12 , V_53 ) ;
if ( V_30 )
return V_30 ;
V_53 ++ ;
}
memset ( V_52 , 0 , sizeof( struct V_42 ) ) ;
memset ( V_51 , 0 , sizeof( struct V_42 ) ) ;
} else {
if ( V_52 -> V_20 )
return - V_38 ;
V_30 = F_20 ( V_35 , V_36 , V_51 -> V_17 ,
V_51 -> V_48 ) ;
if ( V_30 )
return V_30 ;
memset ( V_52 , 0 , sizeof( struct V_42 ) ) ;
memset ( V_51 , 0 , sizeof( struct V_42 ) ) ;
}
return 0 ;
}
