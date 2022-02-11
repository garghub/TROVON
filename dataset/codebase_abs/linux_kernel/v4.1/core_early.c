static bool T_1 F_1 ( void )
{
#ifdef F_2
const char * V_1 = ( const char * ) F_3 ( V_2 ) ;
const char * V_3 = L_1 ;
const char * V_4 = ( const char * ) F_3 ( V_3 ) ;
bool * V_5 = ( bool * ) F_3 ( & V_6 ) ;
#else
const char * V_1 = V_2 ;
const char * V_4 = L_1 ;
bool * V_5 = & V_6 ;
#endif
if ( F_4 ( V_1 , V_4 ) )
* V_5 = true ;
return * V_5 ;
}
void T_1 F_5 ( void )
{
int V_7 , V_8 ;
if ( F_1 () )
return;
if ( ! F_6 () )
return;
V_7 = F_7 () ;
V_8 = F_8 () ;
switch ( V_7 ) {
case V_9 :
if ( V_8 >= 6 )
F_9 () ;
break;
case V_10 :
if ( V_8 >= 0x10 )
F_10 () ;
break;
default:
break;
}
}
static bool F_11 ( void )
{
#ifdef F_2
return * ( ( bool * ) F_3 ( & V_6 ) ) ;
#else
return V_6 ;
#endif
}
void F_12 ( void )
{
int V_7 , V_8 ;
if ( F_11 () )
return;
if ( ! F_6 () )
return;
V_7 = F_7 () ;
V_8 = F_8 () ;
switch ( V_7 ) {
case V_9 :
if ( V_8 >= 6 )
F_13 () ;
break;
case V_10 :
if ( V_8 >= 0x10 )
F_14 () ;
break;
default:
break;
}
}
int T_1 F_15 ( void )
{
struct V_11 * V_12 = & V_13 ;
switch ( V_12 -> F_7 ) {
case V_9 :
if ( V_12 -> V_14 >= 6 )
F_16 () ;
break;
case V_10 :
if ( V_12 -> V_14 >= 0x10 )
F_17 () ;
break;
default:
break;
}
return 0 ;
}
void F_18 ( void )
{
int V_7 , V_8 ;
V_7 = F_7 () ;
V_8 = F_8 () ;
switch ( V_7 ) {
case V_9 :
if ( V_8 >= 6 )
F_19 () ;
break;
case V_10 :
if ( V_8 >= 0x10 )
F_20 () ;
break;
default:
break;
}
}
