static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
static void F_2 ( void )
{
char V_3 [ sizeof( V_4 -> V_5 ) ] ;
F_3 ( L_1 ,
F_4 ( V_3 , V_4 ) ) ;
}
static void F_5 ( void )
{
char V_3 [ sizeof( V_4 -> V_5 ) ] ;
F_3 ( L_2 ,
F_4 ( V_3 , V_4 ) ) ;
}
static int F_6 ( T_2 V_6 , unsigned * V_7 )
{
T_3 V_8 ;
if ( F_7 ( V_8 , & V_6 -> V_8 ) )
return - V_9 ;
switch ( V_8 ) {
case V_10 :
F_2 () ;
* V_7 = V_11 ;
break;
case V_12 :
F_5 () ;
case V_13 :
* V_7 = V_14 ;
break;
default:
if ( F_8 ( ( V_15 ) V_16 , & V_6 -> V_8 ) )
return - V_9 ;
return - V_17 ;
}
return 0 ;
}
static inline int F_9 ( T_4 V_18 , T_5 * V_19 ,
T_5 * V_20 , T_5 * V_21 )
{
int V_22 ;
if ( V_18 && ( V_18 != F_10 ( V_4 ) ) ) {
struct V_23 * V_24 ;
F_11 () ;
V_24 = F_12 ( V_18 ) ;
if ( ! V_24 )
V_22 = - V_25 ;
else
V_22 = F_13 ( V_24 , V_19 , V_20 , V_21 ) ;
F_14 () ;
} else
V_22 = F_13 ( V_4 , V_19 , V_20 , V_21 ) ;
return V_22 ;
}
bool F_15 ( struct V_23 * V_26 ,
struct V_27 * V_28 , int V_29 )
{
int V_22 ;
F_11 () ;
V_22 = F_16 ( F_17 ( V_26 ) , V_28 , V_29 ) ;
F_14 () ;
return ( V_22 == 0 ) ;
}
bool F_18 ( struct V_23 * V_26 , int V_29 )
{
return F_15 ( V_26 , & V_30 , V_29 ) ;
}
bool F_19 ( struct V_23 * V_26 ,
struct V_27 * V_28 , int V_29 )
{
int V_22 ;
F_11 () ;
V_22 = F_20 ( F_17 ( V_26 ) , V_28 , V_29 ) ;
F_14 () ;
return ( V_22 == 0 ) ;
}
bool F_21 ( struct V_23 * V_26 , int V_29 )
{
return F_19 ( V_26 , & V_30 , V_29 ) ;
}
bool F_22 ( struct V_27 * V_28 , int V_29 )
{
if ( F_23 ( ! F_24 ( V_29 ) ) ) {
F_25 ( L_3 , V_29 ) ;
F_26 () ;
}
if ( F_16 ( F_27 () , V_28 , V_29 ) == 0 ) {
V_4 -> V_31 |= V_32 ;
return true ;
}
return false ;
}
bool F_28 ( int V_29 )
{
return F_22 ( & V_30 , V_29 ) ;
}
bool F_29 ( const struct V_33 * V_33 , struct V_27 * V_28 ,
int V_29 )
{
if ( F_30 ( ! F_24 ( V_29 ) ) )
return false ;
if ( F_16 ( V_33 -> V_34 , V_28 , V_29 ) == 0 )
return true ;
return false ;
}
bool F_31 ( const struct V_35 * V_35 , int V_29 )
{
struct V_27 * V_28 = F_32 () ;
return F_22 ( V_28 , V_29 ) && F_33 ( V_28 , V_35 -> V_36 ) &&
F_34 ( V_28 , V_35 -> V_37 ) ;
}
