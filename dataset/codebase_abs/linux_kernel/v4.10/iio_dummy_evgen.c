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
static void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_3 ( V_11 , struct V_12 , V_11 ) ;
F_6 ( F_7 ( V_13 -> V_8 ) ) ;
}
static int F_8 ( void )
{
int V_14 , V_15 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_16 -> V_9 = F_10 ( - 1 , 0 , V_19 , 0 ) ;
if ( V_16 -> V_9 < 0 ) {
V_14 = V_16 -> V_9 ;
F_11 ( V_16 ) ;
return V_14 ;
}
V_16 -> V_4 . V_20 = V_21 ;
V_16 -> V_4 . V_22 = & F_1 ;
V_16 -> V_4 . V_23 = & F_4 ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
F_12 ( V_16 -> V_9 + V_15 , & V_16 -> V_4 ) ;
F_13 ( V_16 -> V_9 + V_15 , & F_6 ) ;
F_14 ( V_16 -> V_9 + V_15 ,
V_24 | V_25 ,
V_26 ) ;
}
F_15 ( & V_16 -> V_27 . V_11 , F_5 ) ;
F_16 ( & V_16 -> V_28 ) ;
return 0 ;
}
int F_17 ( void )
{
int V_15 , V_14 = 0 ;
if ( ! V_16 )
return - V_29 ;
F_18 ( & V_16 -> V_28 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
if ( ! V_16 -> V_30 [ V_15 ] ) {
V_14 = V_16 -> V_9 + V_15 ;
V_16 -> V_30 [ V_15 ] = true ;
break;
}
F_19 ( & V_16 -> V_28 ) ;
if ( V_15 == V_19 )
return - V_18 ;
return V_14 ;
}
void F_20 ( int V_8 )
{
F_18 ( & V_16 -> V_28 ) ;
V_16 -> V_30 [ V_8 - V_16 -> V_9 ] = false ;
F_19 ( & V_16 -> V_28 ) ;
}
struct V_31 * F_21 ( int V_8 )
{
return & V_16 -> V_32 [ V_8 - V_16 -> V_9 ] ;
}
static void F_22 ( void )
{
F_23 ( V_16 -> V_9 , V_19 ) ;
F_11 ( V_16 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
F_22 () ;
}
static T_1 F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_38 )
{
struct V_39 * V_40 = F_26 ( V_36 ) ;
unsigned long V_41 ;
int V_14 ;
V_14 = F_27 ( V_37 , 10 , & V_41 ) ;
if ( V_14 )
return V_14 ;
V_16 -> V_32 [ V_40 -> V_42 ] . V_43 = V_40 -> V_42 ;
V_16 -> V_32 [ V_40 -> V_42 ] . V_44 = V_41 ;
V_16 -> V_27 . V_8 = V_16 -> V_9 + V_40 -> V_42 ;
if ( V_16 -> V_7 [ V_40 -> V_42 ] )
F_28 ( & V_16 -> V_27 . V_11 ) ;
return V_38 ;
}
static T_3 int F_29 ( void )
{
int V_14 = F_8 () ;
if ( V_14 < 0 )
return V_14 ;
F_30 ( & V_45 ) ;
F_31 ( & V_45 , L_1 ) ;
return F_32 ( & V_45 ) ;
}
static T_4 void F_33 ( void )
{
F_34 ( & V_45 ) ;
}
