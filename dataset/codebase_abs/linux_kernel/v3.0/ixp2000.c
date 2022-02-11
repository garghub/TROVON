static inline unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long (* F_2)( unsigned long ) =
( unsigned long (*) ( unsigned long ) ) V_2 -> V_4 ;
return ( F_2 ? F_2 ( V_3 ) : V_3 ) ;
}
static inline unsigned long F_3 ( unsigned long V_5 )
{
if ( V_6 ) {
return ( V_5 ^ 3 ) ;
}
return V_5 ;
}
static T_1 F_4 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_7 ;
V_7 . V_8 [ 0 ] = * ( ( V_9 * ) ( V_2 -> V_10 + F_1 ( V_2 , V_3 ) ) ) ;
return V_7 ;
}
static void F_5 ( struct V_1 * V_2 , void * V_11 ,
unsigned long V_12 , T_2 V_13 )
{
V_12 = F_1 ( V_2 , V_12 ) ;
while( V_13 -- )
* ( V_14 * ) V_11 ++ = * ( V_14 * ) ( V_2 -> V_10 + V_12 ++ ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_15 , unsigned long V_3 )
{
* ( V_14 * ) ( F_3 ( V_2 -> V_10 +
F_1 ( V_2 , V_3 ) ) ) = V_15 . V_8 [ 0 ] ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_11 ,
const void * V_12 , T_2 V_13 )
{
V_11 = F_1 ( V_2 , V_11 ) ;
while( V_13 -- ) {
unsigned long V_16 = F_3 ( V_2 -> V_10 + V_11 ++ ) ;
* ( V_14 * ) ( V_16 ) = * ( V_14 * ) ( V_12 ++ ) ;
}
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_18 . V_21 ;
struct V_22 * V_23 = F_9 ( V_18 ) ;
F_10 ( V_18 , NULL ) ;
if( ! V_23 )
return 0 ;
if ( V_23 -> V_24 ) {
F_11 ( V_23 -> V_24 ) ;
F_12 ( V_23 -> V_24 ) ;
}
if ( V_23 -> V_2 . V_10 )
F_13 ( ( void * ) V_23 -> V_2 . V_10 ) ;
F_14 ( V_23 -> V_25 ) ;
if ( V_23 -> V_26 ) {
F_15 ( V_23 -> V_26 ) ;
F_14 ( V_23 -> V_26 ) ;
}
if ( V_20 -> exit )
V_20 -> exit () ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
static const char * V_27 [] = { L_1 , L_2 , NULL } ;
struct V_28 * V_29 = V_18 -> V_18 . V_21 ;
struct V_19 * V_20 ;
struct V_22 * V_23 ;
unsigned long V_30 ;
int V_31 = - 1 ;
if ( ! V_29 )
return - V_32 ;
V_20 = V_29 -> V_21 ;
if ( ! V_20 )
return - V_32 ;
V_30 = V_18 -> V_33 -> V_34 - V_18 -> V_33 -> V_35 + 1 ;
F_17 ( & V_18 -> V_18 , L_3 ,
V_29 -> V_36 , ( ( V_37 ) V_30 >> 20 ) ) ;
if ( V_20 -> V_38 != 1 ) {
F_18 ( & V_18 -> V_18 , L_4 ,
V_20 -> V_38 * 8 ) ;
return - V_39 ;
}
V_23 = F_19 ( sizeof( struct V_22 ) , V_40 ) ;
if( ! V_23 ) {
V_31 = - V_41 ;
goto Error;
}
F_10 ( V_18 , V_23 ) ;
V_23 -> V_2 . V_42 = V_43 ;
V_23 -> V_2 . V_44 = V_29 -> V_36 * V_30 ;
V_23 -> V_2 . V_45 = 1 ;
V_23 -> V_2 . V_4 = ( unsigned long ) V_29 -> V_46 ;
V_23 -> V_2 . V_47 = F_20 ( & V_18 -> V_18 ) ;
V_23 -> V_2 . V_48 = F_4 ;
V_23 -> V_2 . V_49 = F_6 ;
V_23 -> V_2 . V_50 = F_5 ;
V_23 -> V_2 . V_51 = F_7 ;
V_23 -> V_26 = F_21 ( V_18 -> V_33 -> V_35 ,
V_18 -> V_33 -> V_34 - V_18 -> V_33 -> V_35 + 1 ,
F_20 ( & V_18 -> V_18 ) ) ;
if ( ! V_23 -> V_26 ) {
F_18 ( & V_18 -> V_18 , L_5 ) ;
V_31 = - V_41 ;
goto Error;
}
V_23 -> V_2 . V_10 = ( unsigned long ) F_22 ( V_18 -> V_33 -> V_35 ,
V_18 -> V_33 -> V_34 - V_18 -> V_33 -> V_35 + 1 ) ;
if ( ! V_23 -> V_2 . V_10 ) {
F_18 ( & V_18 -> V_18 , L_6 ) ;
V_31 = - V_39 ;
goto Error;
}
#if F_23 ( V_52 )
V_6 = F_24 () ;
F_17 ( & V_18 -> V_18 , L_7 ,
V_6 ? L_8 : L_9 ) ;
#endif
V_23 -> V_24 = F_25 ( V_20 -> V_53 , & V_23 -> V_2 ) ;
if ( ! V_23 -> V_24 ) {
F_18 ( & V_18 -> V_18 , L_10 ) ;
V_31 = - V_54 ;
goto Error;
}
V_23 -> V_24 -> V_55 = V_56 ;
V_31 = F_26 ( V_23 -> V_24 , V_27 , & V_23 -> V_25 , 0 ) ;
if ( V_31 > 0 ) {
V_31 = F_27 ( V_23 -> V_24 , V_23 -> V_25 , V_31 ) ;
if( V_31 )
F_18 ( & V_18 -> V_18 , L_11 ) ;
}
if ( V_31 )
goto Error;
return 0 ;
Error:
F_8 ( V_18 ) ;
return V_31 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_57 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_57 ) ;
}
