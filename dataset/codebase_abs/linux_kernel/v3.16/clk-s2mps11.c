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
static struct V_12 * F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_6 = F_9 ( V_14 -> V_18 . V_19 ) ;
struct V_12 * V_20 ;
int V_21 ;
if ( ! V_6 -> V_18 -> V_22 )
return F_10 ( - V_23 ) ;
V_20 = F_11 ( V_6 -> V_18 -> V_22 , L_1 ) ;
if ( ! V_20 ) {
F_12 ( & V_14 -> V_18 , L_2 ) ;
return F_10 ( - V_23 ) ;
}
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( ! V_16 [ V_21 ] . V_25 )
continue;
F_13 ( V_20 , L_3 , V_21 ,
& V_16 [ V_21 ] . V_25 ) ;
}
return V_20 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_17 * V_6 = F_9 ( V_14 -> V_18 . V_19 ) ;
struct V_1 * V_26 , * V_1 ;
unsigned int V_27 ;
struct V_15 * V_16 ;
int V_21 , V_5 = 0 ;
T_1 V_28 ;
V_26 = F_15 ( & V_14 -> V_18 , sizeof( * V_1 ) *
V_24 , V_29 ) ;
if ( ! V_26 )
return - V_30 ;
V_1 = V_26 ;
V_31 = F_15 ( & V_14 -> V_18 , sizeof( struct V_32 * ) *
V_24 , V_29 ) ;
if ( ! V_31 )
return - V_30 ;
switch( F_16 ( V_14 ) -> V_33 ) {
case V_34 :
V_27 = V_35 ;
V_16 = V_36 ;
break;
case V_37 :
V_27 = V_38 ;
V_16 = V_39 ;
break;
case V_40 :
V_27 = V_41 ;
V_16 = V_36 ;
break;
default:
F_12 ( & V_14 -> V_18 , L_4 ) ;
return - V_23 ;
} ;
V_26 -> V_20 = F_8 ( V_14 , V_16 ) ;
if ( F_17 ( V_26 -> V_20 ) )
return F_18 ( V_26 -> V_20 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ , V_1 ++ ) {
if ( ! V_16 [ V_21 ] . V_25 )
continue;
V_1 -> V_6 = V_6 ;
V_1 -> V_3 . V_42 = & V_16 [ V_21 ] ;
V_1 -> V_9 = 1 << V_21 ;
V_1 -> V_8 = V_27 ;
V_5 = F_19 ( V_1 -> V_6 -> V_7 ,
V_1 -> V_8 , & V_28 ) ;
if ( V_5 < 0 )
goto V_43;
V_1 -> V_10 = V_28 & V_1 -> V_9 ;
V_1 -> V_32 = F_20 ( & V_14 -> V_18 ,
& V_1 -> V_3 ) ;
if ( F_17 ( V_1 -> V_32 ) ) {
F_12 ( & V_14 -> V_18 , L_5 ,
F_21 ( V_1 ) ) ;
V_5 = F_18 ( V_1 -> V_32 ) ;
goto V_43;
}
V_1 -> V_44 = F_22 ( V_1 -> V_32 ,
F_21 ( V_1 ) , NULL ) ;
if ( ! V_1 -> V_44 ) {
V_5 = - V_30 ;
goto V_45;
}
F_23 ( V_1 -> V_44 ) ;
}
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( ! V_16 [ V_21 ] . V_25 )
continue;
V_31 [ V_21 ] = V_26 [ V_21 ] . V_32 ;
}
V_46 . V_47 = V_31 ;
V_46 . V_48 = V_24 ;
F_24 ( V_26 -> V_20 , V_49 ,
& V_46 ) ;
F_25 ( V_14 , V_26 ) ;
return V_5 ;
V_45:
F_26 ( & V_14 -> V_18 , V_1 -> V_32 ) ;
V_43:
while ( V_1 > V_26 ) {
if ( V_1 -> V_44 ) {
F_27 ( V_1 -> V_44 ) ;
F_26 ( & V_14 -> V_18 , V_1 -> V_32 ) ;
}
V_1 -- ;
}
return V_5 ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_26 = F_29 ( V_14 ) ;
int V_21 ;
F_30 ( V_26 [ 0 ] . V_20 ) ;
F_31 ( V_26 [ 0 ] . V_20 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( ! V_26 [ V_21 ] . V_44 )
continue;
F_27 ( V_26 [ V_21 ] . V_44 ) ;
}
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_50 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_50 ) ;
}
