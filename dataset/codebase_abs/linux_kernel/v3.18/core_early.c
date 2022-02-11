static int F_1 ( void )
{
T_1 V_1 = 0x00000000 ;
T_1 V_2 , V_3 = 0 , V_4 ;
F_2 ( & V_1 , & V_2 , & V_3 , & V_4 ) ;
if ( F_3 ( V_5 , V_6 , V_7 , V_2 , V_3 , V_4 ) )
return V_8 ;
if ( F_3 ( V_9 , V_10 , V_11 , V_2 , V_3 , V_4 ) )
return V_12 ;
return V_13 ;
}
static int F_4 ( void )
{
T_1 V_1 = 0x00000001 ;
T_1 V_2 , V_3 = 0 , V_4 ;
int V_14 ;
F_2 ( & V_1 , & V_2 , & V_3 , & V_4 ) ;
V_14 = ( V_1 >> 8 ) & 0xf ;
if ( V_14 == 15 )
V_14 += ( V_1 >> 20 ) & 0xff ;
return V_14 ;
}
static bool T_2 F_5 ( void )
{
#ifdef F_6
const char * V_15 = ( const char * ) F_7 ( V_16 ) ;
const char * V_17 = L_1 ;
const char * V_18 = ( const char * ) F_7 ( V_17 ) ;
bool * V_19 = ( bool * ) F_7 ( & V_20 ) ;
#else
const char * V_15 = V_16 ;
const char * V_18 = L_1 ;
bool * V_19 = & V_20 ;
#endif
if ( F_8 ( V_15 , V_18 ) )
* V_19 = true ;
return * V_19 ;
}
void T_2 F_9 ( void )
{
int V_21 , V_14 ;
if ( F_5 () )
return;
if ( ! F_10 () )
return;
V_21 = F_1 () ;
V_14 = F_4 () ;
switch ( V_21 ) {
case V_8 :
if ( V_14 >= 6 )
F_11 () ;
break;
case V_12 :
if ( V_14 >= 0x10 )
F_12 () ;
break;
default:
break;
}
}
static bool F_13 ( void )
{
#ifdef F_6
return * ( ( bool * ) F_7 ( & V_20 ) ) ;
#else
return V_20 ;
#endif
}
void F_14 ( void )
{
int V_21 , V_14 ;
if ( F_13 () )
return;
if ( ! F_10 () )
return;
V_21 = F_1 () ;
V_14 = F_4 () ;
switch ( V_21 ) {
case V_8 :
if ( V_14 >= 6 )
F_15 () ;
break;
case V_12 :
if ( V_14 >= 0x10 )
F_16 () ;
break;
default:
break;
}
}
int T_2 F_17 ( void )
{
struct V_22 * V_23 = & V_24 ;
switch ( V_23 -> F_1 ) {
case V_8 :
if ( V_23 -> V_14 >= 6 )
F_18 () ;
break;
case V_12 :
if ( V_23 -> V_14 >= 0x10 )
F_19 () ;
break;
default:
break;
}
return 0 ;
}
