static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( F_3 ( ( void T_2 * ) ( ( unsigned long ) V_1 ^ 0x2 ) ) ) ;
}
static inline void F_4 ( T_1 V_2 , void T_2 * V_1 )
{
F_5 ( F_6 ( V_2 ) , ( void T_2 * ) ( ( unsigned long ) V_1 ^ 0x2 ) ) ;
}
static inline T_1 F_1 ( const void T_2 * V_1 )
{
return F_3 ( V_1 ) ;
}
static inline void F_4 ( T_1 V_2 , void T_2 * V_1 )
{
F_5 ( V_2 , V_1 ) ;
}
static T_3 F_7 ( struct V_3 * V_4 , unsigned long V_5 )
{
T_3 V_6 ;
V_6 . V_7 [ 0 ] = F_1 ( V_4 -> V_8 + V_5 ) ;
return V_6 ;
}
static void F_8 ( struct V_3 * V_4 , void * V_9 ,
unsigned long V_10 , T_4 V_11 )
{
T_5 * V_12 = ( T_5 * ) V_9 ;
void T_2 * V_13 = V_4 -> V_8 + V_10 ;
if ( V_11 <= 0 )
return;
if ( V_10 & 1 ) {
* V_12 ++ = F_9 ( F_1 ( V_13 - 1 ) ) ;
V_13 ++ ;
-- V_11 ;
}
while ( V_11 >= 2 ) {
T_1 V_14 = F_1 ( V_13 ) ;
* V_12 ++ = F_10 ( V_14 ) ;
* V_12 ++ = F_9 ( V_14 ) ;
V_13 += 2 ;
V_11 -= 2 ;
}
if ( V_11 > 0 )
* V_12 ++ = F_10 ( F_1 ( V_13 ) ) ;
}
static void F_11 ( struct V_3 * V_4 , T_3 V_2 , unsigned long V_15 )
{
if ( ! ( V_15 & 1 ) )
F_4 ( V_2 . V_7 [ 0 ] , V_4 -> V_8 + V_15 ) ;
}
static void F_12 ( struct V_3 * V_4 , T_3 V_2 , unsigned long V_15 )
{
F_4 ( V_2 . V_7 [ 0 ] , V_4 -> V_8 + V_15 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_17 . V_20 ;
struct V_21 * V_22 = F_14 ( V_17 ) ;
F_15 ( V_17 , NULL ) ;
if( ! V_22 )
return 0 ;
if ( V_22 -> V_23 ) {
F_16 ( V_22 -> V_23 ) ;
F_17 ( V_22 -> V_23 ) ;
}
if ( V_22 -> V_4 . V_8 )
F_18 ( V_22 -> V_4 . V_8 ) ;
if ( V_22 -> V_24 ) {
F_19 ( V_22 -> V_24 ) ;
F_20 ( V_22 -> V_24 ) ;
}
if ( V_19 -> exit )
V_19 -> exit () ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_17 . V_20 ;
struct V_21 * V_22 ;
int V_25 = - 1 ;
if ( ! V_19 )
return - V_26 ;
if ( V_19 -> V_27 ) {
V_25 = V_19 -> V_27 () ;
if ( V_25 )
return V_25 ;
}
V_22 = F_22 ( sizeof( struct V_21 ) , V_28 ) ;
if( ! V_22 ) {
V_25 = - V_29 ;
goto Error;
}
F_15 ( V_17 , V_22 ) ;
V_22 -> V_4 . V_30 = V_31 ;
V_22 -> V_4 . V_32 = F_23 ( V_17 -> V_33 ) ;
V_22 -> V_4 . V_34 = 2 ;
V_22 -> V_4 . V_35 = F_24 ( & V_17 -> V_17 ) ;
V_22 -> V_4 . V_36 = F_7 ;
V_22 -> V_4 . V_37 = F_11 ;
V_22 -> V_4 . V_38 = F_8 ;
V_22 -> V_24 = F_25 ( V_17 -> V_33 -> V_39 ,
F_23 ( V_17 -> V_33 ) ,
L_1 ) ;
if ( ! V_22 -> V_24 ) {
F_26 ( V_40 L_2 ) ;
V_25 = - V_29 ;
goto Error;
}
V_22 -> V_4 . V_8 = F_27 ( V_17 -> V_33 -> V_39 ,
F_23 ( V_17 -> V_33 ) ) ;
if ( ! V_22 -> V_4 . V_8 ) {
F_26 ( V_40 L_3 ) ;
V_25 = - V_41 ;
goto Error;
}
V_22 -> V_23 = F_28 ( V_19 -> V_42 , & V_22 -> V_4 ) ;
if ( ! V_22 -> V_23 ) {
F_26 ( V_40 L_4 ) ;
V_25 = - V_43 ;
goto Error;
}
V_22 -> V_23 -> V_44 = V_45 ;
V_22 -> V_4 . V_37 = F_12 ;
V_25 = F_29 ( V_22 -> V_23 , V_46 , V_17 -> V_33 -> V_39 ,
V_19 -> V_47 , V_19 -> V_48 ) ;
if ( V_25 ) {
F_26 ( V_40 L_5 ) ;
goto Error;
}
return 0 ;
Error:
F_13 ( V_17 ) ;
return V_25 ;
}
