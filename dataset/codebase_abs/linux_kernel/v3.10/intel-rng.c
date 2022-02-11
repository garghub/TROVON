static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline T_1 F_3 ( void T_2 * V_1 ,
T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
return F_1 ( V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 )
{
void T_2 * V_1 = ( void T_2 * ) V_5 -> V_7 ;
int V_8 , V_9 ;
for ( V_9 = 0 ; V_9 < 20 ; V_9 ++ ) {
V_8 = ! ! ( F_2 ( V_1 + V_10 ) &
V_11 ) ;
if ( V_8 || ! V_6 )
break;
F_6 ( 10 ) ;
}
return V_8 ;
}
static int F_7 ( struct V_4 * V_5 , T_3 * V_8 )
{
void T_2 * V_1 = ( void T_2 * ) V_5 -> V_7 ;
* V_8 = F_2 ( V_1 + V_12 ) ;
return 1 ;
}
static int F_8 ( struct V_4 * V_5 )
{
void T_2 * V_1 = ( void T_2 * ) V_5 -> V_7 ;
T_1 V_3 ;
int V_13 = - V_14 ;
V_3 = F_1 ( V_1 ) ;
if ( ( V_3 & V_15 ) == 0 )
V_3 = F_3 ( V_1 , V_3 | V_15 ) ;
if ( ( V_3 & V_15 ) == 0 ) {
F_9 (KERN_ERR PFX L_1 ) ;
goto V_16;
}
V_13 = 0 ;
V_16:
return V_13 ;
}
static void F_10 ( struct V_4 * V_5 )
{
void T_2 * V_1 = ( void T_2 * ) V_5 -> V_7 ;
T_1 V_3 ;
V_3 = F_1 ( V_1 ) ;
if ( V_3 & V_15 )
F_3 ( V_1 , V_3 & ~ V_15 ) ;
else
F_9 (KERN_WARNING PFX L_2 ) ;
}
static int T_4 F_11 ( void * V_17 )
{
struct V_18 * V_18 = V_17 ;
T_1 V_19 , V_20 ;
if ( ! ( V_18 -> V_21 & V_22 ) )
F_12 ( V_18 -> V_23 ,
V_18 -> V_24 ,
V_18 -> V_21 |
V_22 ) ;
if ( ! ( V_18 -> V_25 & V_26 ) )
F_12 ( V_18 -> V_23 ,
V_18 -> V_27 ,
V_18 -> V_25 |
V_26 ) ;
F_4 ( V_28 , V_18 -> V_1 ) ;
F_4 ( V_29 , V_18 -> V_1 ) ;
V_19 = F_2 ( V_18 -> V_1 + V_30 ) ;
V_20 = F_2 ( V_18 -> V_1 + V_31 ) ;
F_4 ( V_28 , V_18 -> V_1 ) ;
if ( ! ( V_18 -> V_25 &
( V_32 | V_26 ) ) )
F_12 ( V_18 -> V_23 ,
V_18 -> V_27 ,
V_18 -> V_25 ) ;
if ( ! ( V_18 -> V_21 & V_22 ) )
F_12 ( V_18 -> V_23 ,
V_18 -> V_24 ,
V_18 -> V_21 ) ;
if ( V_19 != V_33 ||
( V_20 != V_34 &&
V_20 != V_35 ) ) {
F_9 (KERN_NOTICE PFX L_3 ) ;
return - V_36 ;
}
return 0 ;
}
static int T_4 F_13 ( struct V_18 * V_18 ,
struct V_37 * V_23 )
{
V_18 -> V_25 = 0xff ;
V_18 -> V_21 = 0xff ;
V_18 -> V_23 = V_23 ;
if ( V_23 -> V_38 < 0x2640 ) {
V_18 -> V_24 = V_39 ;
V_18 -> V_27 = V_40 ;
} else {
V_18 -> V_24 = V_41 ;
V_18 -> V_27 = V_42 ;
}
F_14 ( V_23 , V_18 -> V_24 ,
& V_18 -> V_21 ) ;
F_14 ( V_23 , V_18 -> V_27 ,
& V_18 -> V_25 ) ;
if ( ( V_18 -> V_25 &
( V_32 | V_26 ) )
== V_32 ) {
static T_5 char V_43 [] =
V_44
V_45 L_4
V_45 L_5
V_45 L_6
V_45 L_7 ;
if ( V_46 )
return - V_36 ;
F_9 ( V_43 ) ;
return - V_47 ;
}
V_18 -> V_1 = F_15 ( V_48 , V_49 ) ;
if ( V_18 -> V_1 == NULL )
return - V_47 ;
return 0 ;
}
static int T_4 F_16 ( void )
{
int V_13 = - V_36 ;
int V_9 ;
struct V_37 * V_23 = NULL ;
void T_2 * V_1 = V_1 ;
T_1 V_3 ;
struct V_18 * V_18 ;
for ( V_9 = 0 ; ! V_23 && V_50 [ V_9 ] . V_51 ; ++ V_9 )
V_23 = F_17 ( V_50 [ V_9 ] . V_51 , V_50 [ V_9 ] . V_38 ,
NULL ) ;
if ( ! V_23 )
goto V_16;
if ( V_46 < 0 ) {
F_18 ( V_23 ) ;
goto V_52;
}
V_18 = F_19 ( sizeof( * V_18 ) , V_53 ) ;
if ( ! V_18 ) {
F_18 ( V_23 ) ;
goto V_16;
}
V_13 = F_13 ( V_18 , V_23 ) ;
if ( V_13 ) {
F_18 ( V_23 ) ;
F_20 ( V_18 ) ;
if ( V_13 == - V_36 )
goto V_52;
goto V_16;
}
V_13 = F_21 ( F_11 , V_18 , NULL ) ;
F_18 ( V_23 ) ;
F_22 ( V_18 -> V_1 ) ;
F_20 ( V_18 ) ;
if ( V_13 )
goto V_16;
V_52:
V_13 = - V_54 ;
V_1 = F_23 ( V_55 , V_56 ) ;
if ( ! V_1 )
goto V_16;
V_57 . V_7 = ( unsigned long ) V_1 ;
V_13 = - V_36 ;
V_3 = F_1 ( V_1 ) ;
if ( ( V_3 & V_58 ) == 0 ) {
F_22 ( V_1 ) ;
goto V_16;
}
F_9 ( V_59 L_8 ) ;
V_13 = F_24 ( & V_57 ) ;
if ( V_13 ) {
F_9 (KERN_ERR PFX L_9 ,
err) ;
F_22 ( V_1 ) ;
}
V_16:
return V_13 ;
}
static void T_6 F_25 ( void )
{
void T_2 * V_1 = ( void T_2 * ) V_57 . V_7 ;
F_26 ( & V_57 ) ;
F_22 ( V_1 ) ;
}
