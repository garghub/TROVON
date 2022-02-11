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
F_9 ( V_16 L_1 ) ;
goto V_17;
}
V_13 = 0 ;
V_17:
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
F_11 ( V_16 L_2 ) ;
}
static int T_4 F_12 ( void * V_18 )
{
struct V_19 * V_19 = V_18 ;
T_1 V_20 , V_21 ;
if ( ! ( V_19 -> V_22 & V_23 ) )
F_13 ( V_19 -> V_24 ,
V_19 -> V_25 ,
V_19 -> V_22 |
V_23 ) ;
if ( ! ( V_19 -> V_26 & V_27 ) )
F_13 ( V_19 -> V_24 ,
V_19 -> V_28 ,
V_19 -> V_26 |
V_27 ) ;
F_4 ( V_29 , V_19 -> V_1 ) ;
F_4 ( V_30 , V_19 -> V_1 ) ;
V_20 = F_2 ( V_19 -> V_1 + V_31 ) ;
V_21 = F_2 ( V_19 -> V_1 + V_32 ) ;
F_4 ( V_29 , V_19 -> V_1 ) ;
if ( ! ( V_19 -> V_26 &
( V_33 | V_27 ) ) )
F_13 ( V_19 -> V_24 ,
V_19 -> V_28 ,
V_19 -> V_26 ) ;
if ( ! ( V_19 -> V_22 & V_23 ) )
F_13 ( V_19 -> V_24 ,
V_19 -> V_25 ,
V_19 -> V_22 ) ;
if ( V_20 != V_34 ||
( V_21 != V_35 &&
V_21 != V_36 ) ) {
F_14 ( V_16 L_3 ) ;
return - V_37 ;
}
return 0 ;
}
static int T_4 F_15 ( struct V_19 * V_19 ,
struct V_38 * V_24 )
{
V_19 -> V_26 = 0xff ;
V_19 -> V_22 = 0xff ;
V_19 -> V_24 = V_24 ;
if ( V_24 -> V_39 < 0x2640 ) {
V_19 -> V_25 = V_40 ;
V_19 -> V_28 = V_41 ;
} else {
V_19 -> V_25 = V_42 ;
V_19 -> V_28 = V_43 ;
}
F_16 ( V_24 , V_19 -> V_25 ,
& V_19 -> V_22 ) ;
F_16 ( V_24 , V_19 -> V_28 ,
& V_19 -> V_26 ) ;
if ( ( V_19 -> V_26 &
( V_33 | V_27 ) )
== V_33 ) {
static T_5 char V_44 [] =
V_16 L_4
V_16 L_5
V_16 L_6
V_16 L_7 ;
if ( V_45 )
return - V_37 ;
F_11 ( L_8 , V_44 ) ;
return - V_46 ;
}
V_19 -> V_1 = F_17 ( V_47 , V_48 ) ;
if ( V_19 -> V_1 == NULL )
return - V_46 ;
return 0 ;
}
static int T_4 F_18 ( void )
{
int V_13 = - V_37 ;
int V_9 ;
struct V_38 * V_24 = NULL ;
void T_2 * V_1 = V_1 ;
T_1 V_3 ;
struct V_19 * V_19 ;
for ( V_9 = 0 ; ! V_24 && V_49 [ V_9 ] . V_50 ; ++ V_9 )
V_24 = F_19 ( V_49 [ V_9 ] . V_50 , V_49 [ V_9 ] . V_39 ,
NULL ) ;
if ( ! V_24 )
goto V_17;
if ( V_45 < 0 ) {
F_20 ( V_24 ) ;
goto V_51;
}
V_19 = F_21 ( sizeof( * V_19 ) , V_52 ) ;
if ( ! V_19 ) {
F_20 ( V_24 ) ;
goto V_17;
}
V_13 = F_15 ( V_19 , V_24 ) ;
if ( V_13 ) {
F_20 ( V_24 ) ;
F_22 ( V_19 ) ;
if ( V_13 == - V_37 )
goto V_51;
goto V_17;
}
V_13 = F_23 ( F_12 , V_19 , NULL ) ;
F_20 ( V_24 ) ;
F_24 ( V_19 -> V_1 ) ;
F_22 ( V_19 ) ;
if ( V_13 )
goto V_17;
V_51:
V_13 = - V_53 ;
V_1 = F_25 ( V_54 , V_55 ) ;
if ( ! V_1 )
goto V_17;
V_56 . V_7 = ( unsigned long ) V_1 ;
V_13 = - V_37 ;
V_3 = F_1 ( V_1 ) ;
if ( ( V_3 & V_57 ) == 0 ) {
F_24 ( V_1 ) ;
goto V_17;
}
F_26 ( L_9 ) ;
V_13 = F_27 ( & V_56 ) ;
if ( V_13 ) {
F_9 ( V_16 L_10 ,
V_13 ) ;
F_24 ( V_1 ) ;
}
V_17:
return V_13 ;
}
static void T_6 F_28 ( void )
{
void T_2 * V_1 = ( void T_2 * ) V_56 . V_7 ;
F_29 ( & V_56 ) ;
F_24 ( V_1 ) ;
}
