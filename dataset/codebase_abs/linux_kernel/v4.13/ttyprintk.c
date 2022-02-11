static void F_1 ( void )
{
if ( V_1 > 0 ) {
V_2 [ V_1 ] = '\0' ;
F_2 ( L_1 , V_2 ) ;
V_1 = 0 ;
}
}
static int F_3 ( const unsigned char * V_3 , int V_4 )
{
int V_5 = V_1 ;
if ( V_3 == NULL ) {
F_1 () ;
return V_5 ;
}
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
if ( V_1 >= V_6 ) {
V_2 [ V_1 ++ ] = '\\' ;
F_1 () ;
}
switch ( V_3 [ V_5 ] ) {
case '\r' :
F_1 () ;
if ( ( V_5 + 1 ) < V_4 && V_3 [ V_5 + 1 ] == '\n' )
V_5 ++ ;
break;
case '\n' :
F_1 () ;
break;
default:
V_2 [ V_1 ++ ] = V_3 [ V_5 ] ;
break;
}
}
return V_4 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_8 -> V_11 = & V_12 ;
return F_5 ( & V_12 . V_13 , V_8 , V_10 ) ;
}
static void F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_14 * V_15 = V_8 -> V_11 ;
F_7 ( & V_15 -> V_16 ) ;
F_3 ( NULL , 0 ) ;
F_8 ( & V_15 -> V_16 ) ;
F_9 ( & V_15 -> V_13 , V_8 , V_10 ) ;
}
static int F_10 ( struct V_7 * V_8 ,
const unsigned char * V_3 , int V_4 )
{
struct V_14 * V_15 = V_8 -> V_11 ;
int V_17 ;
F_7 ( & V_15 -> V_16 ) ;
V_17 = F_3 ( V_3 , V_4 ) ;
F_8 ( & V_15 -> V_16 ) ;
return V_17 ;
}
static int F_11 ( struct V_7 * V_8 )
{
return V_18 ;
}
static int F_12 ( struct V_7 * V_8 ,
unsigned int V_19 , unsigned long V_20 )
{
struct V_14 * V_15 = V_8 -> V_11 ;
if ( ! V_15 )
return - V_21 ;
switch ( V_19 ) {
case V_22 :
return - V_23 ;
default:
return - V_24 ;
}
return 0 ;
}
static int T_1 F_13 ( void )
{
int V_17 = - V_25 ;
F_14 ( & V_12 . V_16 ) ;
V_26 = F_15 ( 1 ,
V_27 |
V_28 |
V_29 ) ;
if ( F_16 ( V_26 ) )
return F_17 ( V_26 ) ;
F_18 ( & V_12 . V_13 ) ;
V_12 . V_13 . V_30 = & V_31 ;
V_26 -> V_32 = L_2 ;
V_26 -> V_33 = L_2 ;
V_26 -> V_34 = V_35 ;
V_26 -> V_36 = 3 ;
V_26 -> type = V_37 ;
V_26 -> V_38 = V_39 ;
V_26 -> V_38 . V_40 = V_41 | V_42 | V_43 | V_44 ;
F_19 ( V_26 , & V_45 ) ;
F_20 ( & V_12 . V_13 , V_26 , 0 ) ;
V_17 = F_21 ( V_26 ) ;
if ( V_17 < 0 ) {
F_22 ( V_46 L_3 ) ;
goto error;
}
return 0 ;
error:
F_23 ( V_26 ) ;
F_24 ( & V_12 . V_13 ) ;
return V_17 ;
}
static void T_2 F_25 ( void )
{
F_26 ( V_26 ) ;
F_23 ( V_26 ) ;
F_24 ( & V_12 . V_13 ) ;
}
