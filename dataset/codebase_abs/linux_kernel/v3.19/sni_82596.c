static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> F_1 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_5 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_7 = ( T_2 ) ( V_5 ) | ( T_2 ) ( V_6 ) ;
if ( V_4 -> V_8 & V_9 ) {
F_5 ( V_7 & 0xffff , V_4 -> F_4 ) ;
F_6 () ;
F_7 ( 1 ) ;
F_5 ( V_7 >> 16 , V_4 -> F_4 ) ;
} else {
F_3 ( V_7 , V_4 -> F_4 ) ;
F_6 () ;
F_7 ( 1 ) ;
F_3 ( V_7 , V_4 -> F_4 ) ;
}
}
static int F_8 ( struct V_10 * V_2 )
{
struct V_1 * V_11 ;
struct V_3 * V_4 ;
struct V_12 * V_13 , * F_1 , * V_14 , * V_8 ;
int V_15 = - V_16 ;
void T_3 * V_17 ;
void T_3 * V_18 ;
T_4 T_3 * V_19 ;
V_13 = F_9 ( V_2 , V_20 , 0 ) ;
F_1 = F_9 ( V_2 , V_20 , 1 ) ;
V_8 = F_9 ( V_2 , 0 , 0 ) ;
V_14 = F_9 ( V_2 , V_20 , 2 ) ;
if ( ! V_13 || ! F_1 || ! V_8 || ! V_14 )
return - V_21 ;
V_17 = F_10 ( V_13 -> V_22 , 4 ) ;
if ( ! V_17 )
return - V_16 ;
V_18 = F_10 ( F_1 -> V_22 , 4 ) ;
if ( ! V_18 )
goto V_23;
F_11 ( V_24 L_1 , V_13 -> V_22 ) ;
V_11 = F_12 ( sizeof( struct V_3 ) ) ;
if ( ! V_11 )
goto V_25;
F_13 ( V_11 , & V_2 -> V_2 ) ;
F_14 ( V_2 , V_11 ) ;
V_11 -> V_26 = V_13 -> V_22 ;
V_11 -> V_27 = F_15 ( V_2 , 0 ) ;
V_19 = F_10 ( V_14 -> V_22 , 0x10 ) ;
if ( ! V_19 )
goto V_28;
V_11 -> V_29 [ 0 ] = F_16 ( V_19 + 0x0b ) ;
V_11 -> V_29 [ 1 ] = F_16 ( V_19 + 0x0a ) ;
V_11 -> V_29 [ 2 ] = F_16 ( V_19 + 0x09 ) ;
V_11 -> V_29 [ 3 ] = F_16 ( V_19 + 0x08 ) ;
V_11 -> V_29 [ 4 ] = F_16 ( V_19 + 0x07 ) ;
V_11 -> V_29 [ 5 ] = F_16 ( V_19 + 0x06 ) ;
F_17 ( V_19 ) ;
if ( ! V_11 -> V_27 ) {
F_11 ( V_30 L_2 ,
__FILE__ , V_11 -> V_26 ) ;
goto V_28;
}
V_4 = F_2 ( V_11 ) ;
V_4 -> V_8 = V_8 -> V_31 & V_32 ;
V_4 -> F_1 = V_18 ;
V_4 -> F_4 = V_17 ;
V_15 = F_18 ( V_11 ) ;
if ( V_15 == 0 )
return 0 ;
V_28:
F_19 ( V_11 ) ;
V_25:
F_17 ( V_18 ) ;
V_23:
F_17 ( V_17 ) ;
return V_15 ;
}
static int F_20 ( struct V_10 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_2 . V_34 , sizeof( struct V_3 ) ,
V_4 -> V_35 , V_4 -> V_36 ) ;
F_17 ( V_4 -> F_1 ) ;
F_17 ( V_4 -> F_4 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_24 ( void )
{
F_11 (KERN_INFO SNI_82596_DRIVER_VERSION L_3 ) ;
return F_25 ( & V_37 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_37 ) ;
}
