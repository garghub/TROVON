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
if ( ! V_5 )
V_4 -> V_10 = true ;
return V_5 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 , ~ V_4 -> V_9 ) ;
if ( ! V_5 )
V_4 -> V_10 = false ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_4 -> V_10 ;
}
static unsigned long F_7 ( struct V_2 * V_3 ,
unsigned long V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_10 )
return 32768 ;
else
return 0 ;
}
static struct V_12 * F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_6 = F_9 ( V_14 -> V_16 . V_17 ) ;
struct V_12 * V_18 ;
int V_19 ;
if ( ! V_6 -> V_16 -> V_20 )
return F_10 ( - V_21 ) ;
V_18 = F_11 ( V_6 -> V_16 -> V_20 , L_1 ) ;
if ( ! V_18 ) {
F_12 ( & V_14 -> V_16 , L_2 ) ;
return F_10 ( - V_21 ) ;
}
V_22 = F_13 ( & V_14 -> V_16 , sizeof( struct V_23 * ) *
V_24 , V_25 ) ;
if ( ! V_22 )
return F_10 ( - V_26 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
F_14 ( V_18 , L_3 , V_19 ,
& V_27 [ V_19 ] . V_28 ) ;
return V_18 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_6 = F_9 ( V_14 -> V_16 . V_17 ) ;
struct V_1 * V_29 , * V_1 ;
struct V_12 * V_18 = NULL ;
unsigned int V_30 ;
int V_19 , V_5 = 0 ;
T_1 V_31 ;
V_29 = F_13 ( & V_14 -> V_16 , sizeof( * V_1 ) *
V_24 , V_25 ) ;
if ( ! V_29 )
return - V_26 ;
V_1 = V_29 ;
V_18 = F_8 ( V_14 ) ;
if ( F_16 ( V_18 ) )
return F_17 ( V_18 ) ;
switch( F_18 ( V_14 ) -> V_32 ) {
case V_33 :
V_30 = V_34 ;
break;
case V_35 :
V_30 = V_36 ;
break;
default:
F_12 ( & V_14 -> V_16 , L_4 ) ;
return - V_21 ;
} ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ , V_1 ++ ) {
V_1 -> V_6 = V_6 ;
V_1 -> V_3 . V_37 = & V_27 [ V_19 ] ;
V_1 -> V_9 = 1 << V_19 ;
V_1 -> V_8 = V_30 ;
V_5 = F_19 ( V_1 -> V_6 -> V_7 ,
V_1 -> V_8 , & V_31 ) ;
if ( V_5 < 0 )
goto V_38;
V_1 -> V_10 = V_31 & V_1 -> V_9 ;
V_1 -> V_23 = F_20 ( & V_14 -> V_16 ,
& V_1 -> V_3 ) ;
if ( F_16 ( V_1 -> V_23 ) ) {
F_12 ( & V_14 -> V_16 , L_5 ,
F_21 ( V_1 ) ) ;
V_5 = F_17 ( V_1 -> V_23 ) ;
goto V_38;
}
V_1 -> V_39 = F_13 ( & V_14 -> V_16 ,
sizeof( struct V_40 ) , V_25 ) ;
if ( ! V_1 -> V_39 ) {
V_5 = - V_26 ;
goto V_41;
}
V_1 -> V_39 -> V_42 = F_21 ( V_1 ) ;
V_1 -> V_39 -> V_23 = V_1 -> V_23 ;
F_22 ( V_1 -> V_39 ) ;
}
if ( V_22 ) {
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
V_22 [ V_19 ] = V_29 [ V_19 ] . V_23 ;
V_43 . V_44 = V_22 ;
V_43 . V_45 = V_24 ;
F_23 ( V_18 , V_46 , & V_43 ) ;
}
F_24 ( V_14 , V_29 ) ;
return V_5 ;
V_41:
F_25 ( & V_14 -> V_16 , V_1 -> V_23 ) ;
V_38:
while ( V_1 > V_29 ) {
if ( V_1 -> V_39 ) {
F_26 ( V_1 -> V_39 ) ;
F_25 ( & V_14 -> V_16 , V_1 -> V_23 ) ;
}
V_1 -- ;
}
return V_5 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_29 = F_28 ( V_14 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
F_26 ( V_29 [ V_19 ] . V_39 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_47 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_47 ) ;
}
