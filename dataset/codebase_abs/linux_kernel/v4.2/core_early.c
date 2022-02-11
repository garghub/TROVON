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
bool F_5 ( struct V_7 * V_8 , const char * V_9 )
{
#ifdef F_6
struct V_10 * V_11 ;
for ( V_11 = V_12 ; V_11 != V_13 ; V_11 ++ ) {
if ( ! strcmp ( V_9 , V_11 -> V_9 ) ) {
V_8 -> V_14 = V_11 -> V_14 ;
V_8 -> V_15 = V_11 -> V_15 ;
return true ;
}
}
#endif
return false ;
}
void T_1 F_7 ( void )
{
int V_16 ;
unsigned int V_17 ;
if ( F_1 () )
return;
if ( ! F_8 () )
return;
V_16 = F_9 () ;
V_17 = F_10 () ;
switch ( V_16 ) {
case V_18 :
if ( V_17 >= 6 )
F_11 () ;
break;
case V_19 :
if ( V_17 >= 0x10 )
F_12 ( V_17 ) ;
break;
default:
break;
}
}
static bool F_13 ( void )
{
#ifdef F_2
return * ( ( bool * ) F_3 ( & V_6 ) ) ;
#else
return V_6 ;
#endif
}
void F_14 ( void )
{
int V_16 , V_17 ;
if ( F_13 () )
return;
if ( ! F_8 () )
return;
V_16 = F_9 () ;
V_17 = F_10 () ;
switch ( V_16 ) {
case V_18 :
if ( V_17 >= 6 )
F_15 () ;
break;
case V_19 :
if ( V_17 >= 0x10 )
F_16 () ;
break;
default:
break;
}
}
int T_1 F_17 ( void )
{
struct V_20 * V_21 = & V_22 ;
switch ( V_21 -> F_9 ) {
case V_18 :
if ( V_21 -> V_23 >= 6 )
F_18 () ;
break;
case V_19 :
if ( V_21 -> V_23 >= 0x10 )
F_19 () ;
break;
default:
break;
}
return 0 ;
}
void F_20 ( void )
{
int V_16 , V_17 ;
V_16 = F_9 () ;
V_17 = F_10 () ;
switch ( V_16 ) {
case V_18 :
if ( V_17 >= 6 )
F_21 () ;
break;
case V_19 :
if ( V_17 >= 0x10 )
F_22 () ;
break;
default:
break;
}
}
