static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 () ;
F_3 ( V_6 ) ;
while ( ! F_4 () ) {
F_5 () ;
F_6 () ;
}
F_7 () ;
F_8 ( V_6 ) ;
F_9 () ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_11 () ;
return V_5 ;
}
static int F_12 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
int V_11 = ( unsigned long ) V_10 ;
struct V_1 * V_2 =
F_13 ( V_12 , V_11 ) ;
if ( V_2 && F_14 () ) {
switch ( V_9 ) {
case V_13 :
case V_14 :
F_15 () ;
F_16 ( V_2 ) ;
F_17 () ;
break;
case V_15 :
case V_16 :
F_15 () ;
F_18 ( V_2 ) ;
F_17 () ;
break;
default:
return V_17 ;
}
}
return V_18 ;
}
static int F_19 ( void )
{
int V_19 ;
struct V_3 * V_4 = & V_20 ;
V_4 -> V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_22 ; ++ V_19 ) {
if ( V_23 [ V_19 ] . V_24 == NULL )
continue;
V_4 -> V_25 [ V_4 -> V_21 ] =
V_23 [ V_19 ] ;
V_4 -> V_21 += 1 ;
}
return 0 ;
}
static int F_20 ( void )
{
if ( V_26 != V_27 )
return - V_28 ;
if ( F_21 ( V_29 ) ) {
V_23 = V_30 ;
V_22 = F_22 ( V_30 ) ;
} else
return - V_28 ;
return 0 ;
}
static int T_1 F_23 ( void )
{
int V_31 ;
V_31 = F_20 () ;
if ( V_31 )
return V_31 ;
F_19 () ;
V_31 = F_24 ( & V_20 , NULL ) ;
if ( V_31 ) {
F_25 ( V_32 L_1 ) ;
return V_31 ;
}
F_26 ( & V_33 ) ;
F_25 ( V_32 L_2 ) ;
return 0 ;
}
