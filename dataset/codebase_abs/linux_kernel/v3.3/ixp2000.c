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
if ( V_23 -> V_25 ) {
F_14 ( V_23 -> V_25 ) ;
F_15 ( V_23 -> V_25 ) ;
}
if ( V_20 -> exit )
V_20 -> exit () ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
static const char * V_26 [] = { L_1 , L_2 , NULL } ;
struct V_27 * V_28 = V_18 -> V_18 . V_21 ;
struct V_19 * V_20 ;
struct V_22 * V_23 ;
unsigned long V_29 ;
int V_30 = - 1 ;
if ( ! V_28 )
return - V_31 ;
V_20 = V_28 -> V_21 ;
if ( ! V_20 )
return - V_31 ;
V_29 = F_17 ( V_18 -> V_32 ) ;
F_18 ( & V_18 -> V_18 , L_3 ,
V_28 -> V_33 , ( ( V_34 ) V_29 >> 20 ) ) ;
if ( V_20 -> V_35 != 1 ) {
F_19 ( & V_18 -> V_18 , L_4 ,
V_20 -> V_35 * 8 ) ;
return - V_36 ;
}
V_23 = F_20 ( sizeof( struct V_22 ) , V_37 ) ;
if( ! V_23 ) {
V_30 = - V_38 ;
goto Error;
}
F_10 ( V_18 , V_23 ) ;
V_23 -> V_2 . V_39 = V_40 ;
V_23 -> V_2 . V_41 = V_28 -> V_33 * V_29 ;
V_23 -> V_2 . V_42 = 1 ;
V_23 -> V_2 . V_4 = ( unsigned long ) V_28 -> V_43 ;
V_23 -> V_2 . V_44 = F_21 ( & V_18 -> V_18 ) ;
V_23 -> V_2 . V_45 = F_4 ;
V_23 -> V_2 . V_46 = F_6 ;
V_23 -> V_2 . V_47 = F_5 ;
V_23 -> V_2 . V_48 = F_7 ;
V_23 -> V_25 = F_22 ( V_18 -> V_32 -> V_49 ,
F_17 ( V_18 -> V_32 ) ,
F_21 ( & V_18 -> V_18 ) ) ;
if ( ! V_23 -> V_25 ) {
F_19 ( & V_18 -> V_18 , L_5 ) ;
V_30 = - V_38 ;
goto Error;
}
V_23 -> V_2 . V_10 =
( unsigned long ) F_23 ( V_18 -> V_32 -> V_49 ,
F_17 ( V_18 -> V_32 ) ) ;
if ( ! V_23 -> V_2 . V_10 ) {
F_19 ( & V_18 -> V_18 , L_6 ) ;
V_30 = - V_36 ;
goto Error;
}
#if F_24 ( V_50 )
V_6 = F_25 () ;
F_18 ( & V_18 -> V_18 , L_7 ,
V_6 ? L_8 : L_9 ) ;
#endif
V_23 -> V_24 = F_26 ( V_20 -> V_51 , & V_23 -> V_2 ) ;
if ( ! V_23 -> V_24 ) {
F_19 ( & V_18 -> V_18 , L_10 ) ;
V_30 = - V_52 ;
goto Error;
}
V_23 -> V_24 -> V_53 = V_54 ;
V_30 = F_27 ( V_23 -> V_24 , V_26 , 0 , NULL , 0 ) ;
if ( V_30 )
goto Error;
return 0 ;
Error:
F_8 ( V_18 ) ;
return V_30 ;
}
