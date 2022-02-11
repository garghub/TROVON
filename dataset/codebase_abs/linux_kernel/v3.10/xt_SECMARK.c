static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( V_7 -> V_9 != V_9 ) ;
switch ( V_9 ) {
case V_10 :
V_5 = V_7 -> V_11 ;
break;
default:
F_3 () ;
}
V_2 -> V_5 = V_5 ;
return V_12 ;
}
static int F_4 ( struct V_6 * V_7 )
{
int V_13 ;
V_7 -> V_14 [ V_15 - 1 ] = '\0' ;
V_7 -> V_11 = 0 ;
V_13 = F_5 ( V_7 -> V_14 , strlen ( V_7 -> V_14 ) ,
& V_7 -> V_11 ) ;
if ( V_13 ) {
if ( V_13 == - V_16 )
F_6 ( L_1 , V_7 -> V_14 ) ;
return V_13 ;
}
if ( ! V_7 -> V_11 ) {
F_6 ( L_2 , V_7 -> V_14 ) ;
return - V_17 ;
}
V_13 = F_7 ( V_7 -> V_11 ) ;
if ( V_13 ) {
F_6 ( L_3 ) ;
return V_13 ;
}
F_8 () ;
return 0 ;
}
static int F_9 ( const struct V_18 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_13 ;
if ( strcmp ( V_4 -> V_19 , L_4 ) != 0 &&
strcmp ( V_4 -> V_19 , L_5 ) != 0 ) {
F_6 ( L_6
L_7 , V_4 -> V_19 ) ;
return - V_16 ;
}
if ( V_9 && V_9 != V_7 -> V_9 ) {
F_6 ( L_8
L_9 , V_9 , V_7 -> V_9 ) ;
return - V_16 ;
}
switch ( V_7 -> V_9 ) {
case V_10 :
break;
default:
F_6 ( L_10 , V_7 -> V_9 ) ;
return - V_16 ;
}
V_13 = F_4 ( V_7 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_9 )
V_9 = V_7 -> V_9 ;
return 0 ;
}
static void F_10 ( const struct V_20 * V_4 )
{
switch ( V_9 ) {
case V_10 :
F_11 () ;
}
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_21 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_21 ) ;
}
