static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 -> V_6 ,
V_4 -> V_7 ,
V_4 -> V_8 , V_4 -> V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 -> V_6 , V_4 -> V_7 ,
V_4 -> V_8 , ~ V_4 -> V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
int V_9 ;
T_1 V_10 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_9 = F_7 ( V_4 -> V_5 -> V_6 ,
V_4 -> V_7 , & V_10 ) ;
if ( V_9 < 0 )
return - V_11 ;
return V_10 & V_4 -> V_8 ;
}
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_12 )
{
return 32768 ;
}
static struct V_13 * F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_5 = F_10 ( V_15 -> V_19 . V_20 ) ;
struct V_13 * V_21 ;
int V_22 ;
if ( ! V_5 -> V_19 -> V_23 )
return F_11 ( - V_11 ) ;
V_21 = F_12 ( V_5 -> V_19 -> V_23 , L_1 ) ;
if ( ! V_21 ) {
F_13 ( & V_15 -> V_19 , L_2 ) ;
return F_11 ( - V_11 ) ;
}
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ )
F_14 ( V_21 , L_3 , V_22 ,
& V_17 [ V_22 ] . V_25 ) ;
return V_21 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_18 * V_5 = F_10 ( V_15 -> V_19 . V_20 ) ;
struct V_1 * V_26 ;
struct V_27 * V_28 ;
unsigned int V_29 ;
int V_22 , V_9 = 0 ;
enum V_30 V_31 = F_16 ( V_15 ) -> V_32 ;
V_26 = F_17 ( & V_15 -> V_19 , V_24 ,
sizeof( * V_26 ) , V_33 ) ;
if ( ! V_26 )
return - V_34 ;
V_28 = F_18 ( & V_15 -> V_19 , sizeof( * V_28 ) +
sizeof( * V_28 -> V_35 ) * V_24 ,
V_33 ) ;
if ( ! V_28 )
return - V_34 ;
switch ( V_31 ) {
case V_36 :
V_29 = V_37 ;
break;
case V_38 :
V_29 = V_39 ;
break;
case V_40 :
V_29 = V_41 ;
break;
case V_42 :
V_29 = V_43 ;
break;
default:
F_13 ( & V_15 -> V_19 , L_4 ) ;
return - V_11 ;
}
V_26 -> V_21 = F_9 ( V_15 , V_44 ) ;
if ( F_19 ( V_26 -> V_21 ) )
return F_20 ( V_26 -> V_21 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( V_22 == V_45 && V_31 == V_40 )
continue;
V_26 [ V_22 ] . V_5 = V_5 ;
V_26 [ V_22 ] . V_3 . V_46 = & V_44 [ V_22 ] ;
V_26 [ V_22 ] . V_8 = 1 << V_22 ;
V_26 [ V_22 ] . V_7 = V_29 ;
V_26 [ V_22 ] . V_47 = F_21 ( & V_15 -> V_19 ,
& V_26 [ V_22 ] . V_3 ) ;
if ( F_19 ( V_26 [ V_22 ] . V_47 ) ) {
F_13 ( & V_15 -> V_19 , L_5 ,
V_44 [ V_22 ] . V_25 ) ;
V_9 = F_20 ( V_26 [ V_22 ] . V_47 ) ;
goto V_48;
}
V_26 [ V_22 ] . V_49 = F_22 ( & V_26 [ V_22 ] . V_3 ,
V_44 [ V_22 ] . V_25 , NULL ) ;
if ( ! V_26 [ V_22 ] . V_49 ) {
V_9 = - V_34 ;
goto V_48;
}
V_28 -> V_35 [ V_22 ] = & V_26 [ V_22 ] . V_3 ;
}
V_28 -> V_50 = V_24 ;
F_23 ( V_26 -> V_21 , V_51 ,
V_28 ) ;
F_24 ( V_15 , V_26 ) ;
return V_9 ;
V_48:
while ( -- V_22 >= 0 )
F_25 ( V_26 [ V_22 ] . V_49 ) ;
return V_9 ;
}
static int F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_26 = F_27 ( V_15 ) ;
int V_22 ;
F_28 ( V_26 [ 0 ] . V_21 ) ;
F_29 ( V_26 [ 0 ] . V_21 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( ! V_26 [ V_22 ] . V_49 )
continue;
F_25 ( V_26 [ V_22 ] . V_49 ) ;
}
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_52 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_52 ) ;
}
