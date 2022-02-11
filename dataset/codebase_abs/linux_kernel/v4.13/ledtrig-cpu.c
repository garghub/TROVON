void F_1 ( enum V_1 V_2 )
{
struct V_3 * V_4 = F_2 ( & V_5 ) ;
bool V_6 = V_4 -> V_6 ;
switch ( V_2 ) {
case V_7 :
case V_8 :
V_6 = true ;
break;
case V_9 :
case V_10 :
case V_11 :
V_6 = false ;
break;
default:
break;
}
if ( V_6 != V_4 -> V_6 ) {
unsigned int V_12 ;
unsigned int V_13 ;
V_4 -> V_6 = V_6 ;
F_3 ( V_6 ? 1 : - 1 , & V_14 ) ;
V_12 = F_4 ( & V_14 ) ;
V_13 = F_5 () ;
F_6 ( V_4 -> V_15 ,
V_6 ? V_16 : V_17 ) ;
F_6 ( V_18 ,
F_7 ( V_16 * V_12 , V_13 ) ) ;
}
}
static int F_8 ( void )
{
F_1 ( V_10 ) ;
return 0 ;
}
static void F_9 ( void )
{
F_1 ( V_8 ) ;
}
static void F_10 ( void )
{
F_1 ( V_11 ) ;
}
static int F_11 ( unsigned int V_19 )
{
F_1 ( V_8 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_19 )
{
F_1 ( V_10 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
int V_19 ;
int V_20 ;
F_14 ( V_21 > 9999 ) ;
F_15 ( L_1 , & V_18 ) ;
F_16 (cpu) {
struct V_3 * V_4 = & F_17 ( V_5 , V_19 ) ;
snprintf ( V_4 -> V_22 , V_23 , L_2 , V_19 ) ;
F_15 ( V_4 -> V_22 , & V_4 -> V_15 ) ;
}
F_18 ( & V_24 ) ;
V_20 = F_19 ( V_25 , L_3 ,
F_11 , F_12 ) ;
if ( V_20 < 0 )
F_20 ( L_4 ,
V_20 ) ;
F_21 ( L_5 ) ;
return 0 ;
}
