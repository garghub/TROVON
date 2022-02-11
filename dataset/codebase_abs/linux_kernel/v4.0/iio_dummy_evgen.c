static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 =
F_3 ( V_4 , struct V_5 , V_4 ) ;
V_6 -> V_7 [ V_2 -> V_8 - V_6 -> V_9 ] = false ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 =
F_3 ( V_4 , struct V_5 , V_4 ) ;
V_6 -> V_7 [ V_2 -> V_8 - V_6 -> V_9 ] = true ;
}
static int F_5 ( void )
{
int V_10 , V_11 ;
V_12 = F_6 ( sizeof( * V_12 ) , V_13 ) ;
if ( V_12 == NULL )
return - V_14 ;
V_12 -> V_9 = F_7 ( - 1 , 0 , V_15 , 0 ) ;
if ( V_12 -> V_9 < 0 ) {
V_10 = V_12 -> V_9 ;
F_8 ( V_12 ) ;
return V_10 ;
}
V_12 -> V_4 . V_16 = V_17 ;
V_12 -> V_4 . V_18 = & F_1 ;
V_12 -> V_4 . V_19 = & F_4 ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
F_9 ( V_12 -> V_9 + V_11 , & V_12 -> V_4 ) ;
F_10 ( V_12 -> V_9 + V_11 , & V_20 ) ;
F_11 ( V_12 -> V_9 + V_11 ,
V_21 | V_22 ,
V_23 ) ;
}
F_12 ( & V_12 -> V_24 ) ;
return 0 ;
}
int F_13 ( void )
{
int V_11 , V_10 = 0 ;
if ( V_12 == NULL )
return - V_25 ;
F_14 ( & V_12 -> V_24 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ )
if ( ! V_12 -> V_26 [ V_11 ] ) {
V_10 = V_12 -> V_9 + V_11 ;
V_12 -> V_26 [ V_11 ] = true ;
break;
}
F_15 ( & V_12 -> V_24 ) ;
if ( V_11 == V_15 )
return - V_14 ;
return V_10 ;
}
int F_16 ( int V_8 )
{
F_14 ( & V_12 -> V_24 ) ;
V_12 -> V_26 [ V_8 - V_12 -> V_9 ] = false ;
F_15 ( & V_12 -> V_24 ) ;
return 0 ;
}
struct V_27 * F_17 ( int V_8 )
{
return & V_12 -> V_28 [ V_8 - V_12 -> V_9 ] ;
}
static void F_18 ( void )
{
F_19 ( V_12 -> V_9 , V_15 ) ;
F_8 ( V_12 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
F_18 () ;
}
static T_1 F_21 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
struct V_35 * V_36 = F_22 ( V_32 ) ;
unsigned long V_37 ;
int V_10 ;
V_10 = F_23 ( V_33 , 10 , & V_37 ) ;
if ( V_10 )
return V_10 ;
V_12 -> V_28 [ V_36 -> V_38 ] . V_39 = V_36 -> V_38 ;
V_12 -> V_28 [ V_36 -> V_38 ] . V_40 = V_37 ;
if ( V_12 -> V_7 [ V_36 -> V_38 ] )
F_24 ( V_12 -> V_9 + V_36 -> V_38 ) ;
return V_34 ;
}
static T_3 int F_25 ( void )
{
int V_10 = F_5 () ;
if ( V_10 < 0 )
return V_10 ;
F_26 ( & V_41 ) ;
F_27 ( & V_41 , L_1 ) ;
return F_28 ( & V_41 ) ;
}
static T_4 void F_29 ( void )
{
F_30 ( & V_41 ) ;
}
