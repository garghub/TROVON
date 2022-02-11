void
F_1 ( void )
{
void * V_1 ;
unsigned long V_2 , V_3 , V_4 ;
int V_5 = F_2 () ;
struct V_6 * V_7 = & F_3 ( V_6 , V_5 ) ;
T_1 * V_8 = ( T_1 * ) & ( V_7 -> V_9 ) ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_10 = V_11 -> V_12 ;
F_4 ( V_8 ) ;
V_2 = V_8 [ 43 ] ;
V_4 = ( V_2 >> 7 ) & 0x7f ;
V_3 = V_2 & 0x7f ;
V_8 [ 46 ] = ( unsigned long ) F_5 ( ( unsigned long * ) V_8 [ 46 ] ,
V_3 - V_4 ) ;
V_1 = ( V_13 * ) F_6 ( V_14 , V_5 ) ;
if ( ! V_1 )
return;
V_1 = F_7 ( V_1 , V_15 , V_16 , V_7 ,
sizeof( * V_7 ) ) ;
F_8 ( V_1 ) ;
}
static int
F_9 ( void )
{
int V_17 = F_10 () - 1 ;
int V_18 = 1000 ;
while( V_18 -- > 0 ) {
if ( F_11 ( & V_19 ) == V_17 )
return 0 ;
F_12 ( 1000 ) ;
}
return 1 ;
}
void
F_13 ( struct V_20 * V_21 )
{
F_14 () ;
#ifdef F_15
F_16 () ;
F_17 () ;
if ( F_18 ( & V_22 ) != 1 )
F_19 ( V_23 , NULL ) ;
F_20 () ;
if ( F_9 () ) {
F_21 () ;
F_9 () ;
}
#endif
}
static void
F_22 ( void )
{
F_23 () ;
F_16 () ;
F_14 () ;
F_24 ( V_24 ) ;
}
void
V_23 ( struct V_25 * V_26 , void * V_27 )
{
int V_28 ;
F_16 () ;
V_28 = F_2 () ;
F_1 () ;
V_11 -> V_29 . V_30 = ( V_31 ) V_26 -> V_32 - 16 ;
F_17 () ;
F_25 ( & V_19 ) ;
V_33 [ V_28 ] = 1 ;
F_26 () ;
for (; ; )
F_27 () ;
}
static int
F_28 ( struct V_34 * V_35 , unsigned long V_36 , void * V_37 )
{
struct V_38 * V_39 ;
struct V_40 * args = V_37 ;
if ( F_11 ( & V_22 ) ) {
switch ( V_36 ) {
case V_41 :
if ( ! V_42 )
break;
case V_43 :
case V_44 :
case V_45 :
F_19 ( V_23 , NULL ) ;
break;
}
}
if ( ! V_46 && ! V_47 )
return V_48 ;
if ( ! V_24 ) {
if ( V_36 == V_41 )
F_29 ( V_49
L_1 ,
V_50 ) ;
return V_48 ;
}
if ( V_36 != V_41 &&
V_36 != V_51 &&
V_36 != V_52 )
return V_48 ;
V_39 = (struct V_38 * ) args -> V_53 ;
switch ( V_36 ) {
case V_51 :
if ( V_46 && ( V_39 -> V_54 -> V_55 != 1 ) ) {
if ( F_18 ( & V_22 ) != 1 )
V_42 = 1 ;
}
break;
case V_41 :
if ( V_46 && ( V_39 -> V_54 -> V_55 != 1 ) )
F_22 () ;
break;
case V_52 :
if ( V_47 && ! ( * ( V_39 -> V_37 ) ) ) {
if ( F_18 ( & V_22 ) == 1 )
F_22 () ;
}
break;
}
return V_48 ;
}
static int
F_30 ( void )
{
static struct V_34 V_56 = {
. V_57 = F_28 ,
. V_58 = 1 ,
} ;
int V_59 ;
if( ( V_59 = F_31 ( & V_56 ) ) != 0 )
return V_59 ;
#ifdef F_32
F_33 ( V_60 ) ;
#endif
return 0 ;
}
