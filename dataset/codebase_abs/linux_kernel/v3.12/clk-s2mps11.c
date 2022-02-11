static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 -> V_7 ,
V_8 ,
V_4 -> V_9 , V_4 -> V_9 ) ;
if ( ! V_5 )
V_4 -> V_10 = true ;
return V_5 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_4 ( V_4 -> V_6 -> V_7 , V_8 ,
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
return NULL ;
V_18 = F_10 ( V_6 -> V_16 -> V_20 , L_1 ) ;
if ( ! V_18 ) {
F_11 ( & V_14 -> V_16 , L_2 ) ;
return F_12 ( - V_21 ) ;
}
V_22 = F_13 ( & V_14 -> V_16 , sizeof( struct V_23 * ) *
V_24 , V_25 ) ;
if ( ! V_22 )
return F_12 ( - V_26 ) ;
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
int V_19 , V_5 = 0 ;
T_1 V_30 ;
V_29 = F_13 ( & V_14 -> V_16 , sizeof( * V_1 ) *
V_24 , V_25 ) ;
if ( ! V_29 )
return - V_26 ;
V_1 = V_29 ;
V_18 = F_8 ( V_14 ) ;
if ( F_16 ( V_18 ) )
return F_17 ( V_18 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ , V_1 ++ ) {
V_1 -> V_6 = V_6 ;
V_1 -> V_3 . V_31 = & V_27 [ V_19 ] ;
V_1 -> V_9 = 1 << V_19 ;
V_5 = F_18 ( V_1 -> V_6 -> V_7 ,
V_8 , & V_30 ) ;
if ( V_5 < 0 )
goto V_32;
V_1 -> V_10 = V_30 & V_1 -> V_9 ;
V_1 -> V_23 = F_19 ( & V_14 -> V_16 ,
& V_1 -> V_3 ) ;
if ( F_16 ( V_1 -> V_23 ) ) {
F_11 ( & V_14 -> V_16 , L_4 ,
F_20 ( V_1 ) ) ;
V_5 = F_17 ( V_1 -> V_23 ) ;
goto V_32;
}
V_1 -> V_33 = F_13 ( & V_14 -> V_16 ,
sizeof( struct V_34 ) , V_25 ) ;
if ( ! V_1 -> V_33 ) {
V_5 = - V_26 ;
goto V_35;
}
V_1 -> V_33 -> V_36 = F_20 ( V_1 ) ;
V_1 -> V_33 -> V_23 = V_1 -> V_23 ;
F_21 ( V_1 -> V_33 ) ;
}
if ( V_22 ) {
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
V_22 [ V_19 ] = V_29 [ V_19 ] . V_23 ;
V_37 . V_38 = V_22 ;
V_37 . V_39 = V_24 ;
F_22 ( V_18 , V_40 , & V_37 ) ;
}
F_23 ( V_14 , V_29 ) ;
return V_5 ;
V_35:
F_24 ( & V_14 -> V_16 , V_1 -> V_23 ) ;
V_32:
while ( V_1 > V_29 ) {
if ( V_1 -> V_33 ) {
F_25 ( V_1 -> V_33 ) ;
F_24 ( & V_14 -> V_16 , V_1 -> V_23 ) ;
}
V_1 -- ;
}
return V_5 ;
}
static int F_26 ( struct V_13 * V_14 )
{
struct V_1 * V_29 = F_27 ( V_14 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
F_25 ( V_29 [ V_19 ] . V_33 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_41 ) ;
}
