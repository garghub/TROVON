static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 -> V_7 ,
V_4 -> V_8 ,
V_4 -> V_9 , V_4 -> V_9 ) ;
return V_5 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 , ~ V_4 -> V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
int V_5 ;
T_1 V_10 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_5 = F_7 ( V_4 -> V_6 -> V_7 ,
V_4 -> V_8 , & V_10 ) ;
if ( V_5 < 0 )
return - V_11 ;
return V_10 & V_4 -> V_9 ;
}
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_12 )
{
return 32768 ;
}
static struct V_13 * F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_6 = F_10 ( V_15 -> V_19 . V_20 ) ;
struct V_13 * V_21 ;
int V_22 ;
if ( ! V_6 -> V_19 -> V_23 )
return F_11 ( - V_11 ) ;
V_21 = F_12 ( V_6 -> V_19 -> V_23 , L_1 ) ;
if ( ! V_21 ) {
F_13 ( & V_15 -> V_19 , L_2 ) ;
return F_11 ( - V_11 ) ;
}
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( ! V_17 [ V_22 ] . V_25 )
continue;
F_14 ( V_21 , L_3 , V_22 ,
& V_17 [ V_22 ] . V_25 ) ;
}
return V_21 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_18 * V_6 = F_10 ( V_15 -> V_19 . V_20 ) ;
struct V_1 * V_26 , * V_1 ;
unsigned int V_27 ;
struct V_16 * V_17 ;
int V_22 , V_5 = 0 ;
V_26 = F_16 ( & V_15 -> V_19 , sizeof( * V_1 ) *
V_24 , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
V_1 = V_26 ;
V_30 = F_16 ( & V_15 -> V_19 , sizeof( struct V_31 * ) *
V_24 , V_28 ) ;
if ( ! V_30 )
return - V_29 ;
switch( F_17 ( V_15 ) -> V_32 ) {
case V_33 :
V_27 = V_34 ;
V_17 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
V_17 = V_38 ;
break;
case V_39 :
V_27 = V_40 ;
V_17 = V_41 ;
break;
case V_42 :
V_27 = V_43 ;
V_17 = V_35 ;
break;
default:
F_13 ( & V_15 -> V_19 , L_4 ) ;
return - V_11 ;
}
V_26 -> V_21 = F_9 ( V_15 , V_17 ) ;
if ( F_18 ( V_26 -> V_21 ) )
return F_19 ( V_26 -> V_21 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ , V_1 ++ ) {
if ( ! V_17 [ V_22 ] . V_25 )
continue;
V_1 -> V_6 = V_6 ;
V_1 -> V_3 . V_44 = & V_17 [ V_22 ] ;
V_1 -> V_9 = 1 << V_22 ;
V_1 -> V_8 = V_27 ;
V_1 -> V_31 = F_20 ( & V_15 -> V_19 ,
& V_1 -> V_3 ) ;
if ( F_18 ( V_1 -> V_31 ) ) {
F_13 ( & V_15 -> V_19 , L_5 ,
F_21 ( V_1 ) ) ;
V_5 = F_19 ( V_1 -> V_31 ) ;
goto V_45;
}
V_1 -> V_46 = F_22 ( V_1 -> V_31 ,
F_21 ( V_1 ) , NULL ) ;
if ( ! V_1 -> V_46 ) {
V_5 = - V_29 ;
goto V_47;
}
}
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( ! V_17 [ V_22 ] . V_25 )
continue;
V_30 [ V_22 ] = V_26 [ V_22 ] . V_31 ;
}
V_48 . V_49 = V_30 ;
V_48 . V_50 = V_24 ;
F_23 ( V_26 -> V_21 , V_51 ,
& V_48 ) ;
F_24 ( V_15 , V_26 ) ;
return V_5 ;
V_47:
F_25 ( & V_15 -> V_19 , V_1 -> V_31 ) ;
V_45:
while ( V_1 > V_26 ) {
if ( V_1 -> V_46 ) {
F_26 ( V_1 -> V_46 ) ;
F_25 ( & V_15 -> V_19 , V_1 -> V_31 ) ;
}
V_1 -- ;
}
return V_5 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_26 = F_28 ( V_15 ) ;
int V_22 ;
F_29 ( V_26 [ 0 ] . V_21 ) ;
F_30 ( V_26 [ 0 ] . V_21 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( ! V_26 [ V_22 ] . V_46 )
continue;
F_26 ( V_26 [ V_22 ] . V_46 ) ;
}
return 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_52 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_52 ) ;
}
