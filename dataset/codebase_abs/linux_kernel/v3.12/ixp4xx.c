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
struct V_18 * V_19 = F_14 ( & V_17 -> V_17 ) ;
struct V_20 * V_21 = F_15 ( V_17 ) ;
if( ! V_21 )
return 0 ;
if ( V_21 -> V_22 ) {
F_16 ( V_21 -> V_22 ) ;
F_17 ( V_21 -> V_22 ) ;
}
if ( V_21 -> V_4 . V_8 )
F_18 ( V_21 -> V_4 . V_8 ) ;
if ( V_21 -> V_23 ) {
F_19 ( V_21 -> V_23 ) ;
F_20 ( V_21 -> V_23 ) ;
}
if ( V_19 -> exit )
V_19 -> exit () ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_14 ( & V_17 -> V_17 ) ;
struct V_20 * V_21 ;
struct V_24 V_25 = {
. V_26 = V_17 -> V_27 -> V_28 ,
} ;
int V_29 = - 1 ;
if ( ! V_19 )
return - V_30 ;
if ( V_19 -> V_31 ) {
V_29 = V_19 -> V_31 () ;
if ( V_29 )
return V_29 ;
}
V_21 = F_22 ( sizeof( struct V_20 ) , V_32 ) ;
if( ! V_21 ) {
V_29 = - V_33 ;
goto Error;
}
F_23 ( V_17 , V_21 ) ;
V_21 -> V_4 . V_34 = V_35 ;
V_21 -> V_4 . V_36 = F_24 ( V_17 -> V_27 ) ;
V_21 -> V_4 . V_37 = 2 ;
V_21 -> V_4 . V_38 = F_25 ( & V_17 -> V_17 ) ;
V_21 -> V_4 . V_39 = F_7 ;
V_21 -> V_4 . V_40 = F_11 ;
V_21 -> V_4 . V_41 = F_8 ;
V_21 -> V_23 = F_26 ( V_17 -> V_27 -> V_28 ,
F_24 ( V_17 -> V_27 ) ,
L_1 ) ;
if ( ! V_21 -> V_23 ) {
F_27 ( V_42 L_2 ) ;
V_29 = - V_33 ;
goto Error;
}
V_21 -> V_4 . V_8 = F_28 ( V_17 -> V_27 -> V_28 ,
F_24 ( V_17 -> V_27 ) ) ;
if ( ! V_21 -> V_4 . V_8 ) {
F_27 ( V_42 L_3 ) ;
V_29 = - V_43 ;
goto Error;
}
V_21 -> V_22 = F_29 ( V_19 -> V_44 , & V_21 -> V_4 ) ;
if ( ! V_21 -> V_22 ) {
F_27 ( V_42 L_4 ) ;
V_29 = - V_45 ;
goto Error;
}
V_21 -> V_22 -> V_46 = V_47 ;
V_21 -> V_4 . V_40 = F_12 ;
V_29 = F_30 ( V_21 -> V_22 , V_48 , & V_25 ,
V_19 -> V_49 , V_19 -> V_50 ) ;
if ( V_29 ) {
F_27 ( V_42 L_5 ) ;
goto Error;
}
return 0 ;
Error:
F_13 ( V_17 ) ;
return V_29 ;
}
