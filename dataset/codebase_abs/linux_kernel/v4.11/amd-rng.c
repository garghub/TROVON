static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
T_2 * V_6 = V_3 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_8 ;
T_1 V_9 = 0 ;
int V_10 = V_4 / 4 + 1 ;
while ( V_9 < V_4 ) {
if ( F_2 ( V_8 -> V_11 + V_12 ) == 0 ) {
if ( V_5 ) {
F_3 ( 128 , 196 ) ;
if ( V_10 -- == 0 )
return V_9 ;
} else {
return 0 ;
}
} else {
* V_6 = F_2 ( V_8 -> V_11 + V_13 ) ;
V_6 ++ ;
V_9 += 4 ;
}
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_8 ;
T_3 V_14 ;
F_5 ( V_8 -> V_15 , 0x40 , & V_14 ) ;
V_14 |= F_6 ( 7 ) ;
F_7 ( V_8 -> V_15 , 0x40 , V_14 ) ;
F_5 ( V_8 -> V_15 , 0x41 , & V_14 ) ;
V_14 |= F_6 ( 7 ) ;
F_7 ( V_8 -> V_15 , 0x41 , V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_8 ;
T_3 V_14 ;
F_5 ( V_8 -> V_15 , 0x40 , & V_14 ) ;
V_14 &= ~ F_6 ( 7 ) ;
F_7 ( V_8 -> V_15 , 0x40 , V_14 ) ;
}
static int T_4 F_9 ( void )
{
int V_16 = - V_17 ;
struct V_18 * V_19 = NULL ;
const struct V_20 * V_21 ;
T_2 V_22 ;
struct V_7 * V_8 ;
F_10 (pdev) {
V_21 = F_11 ( V_23 , V_19 ) ;
if ( V_21 )
goto V_24;
}
return - V_17 ;
V_24:
V_16 = F_12 ( V_19 , 0x58 , & V_22 ) ;
if ( V_16 )
return V_16 ;
V_22 &= 0x0000FF00 ;
if ( V_22 == 0 )
return - V_25 ;
V_8 = F_13 ( sizeof( * V_8 ) , V_26 ) ;
if ( ! V_8 )
return - V_27 ;
if ( ! F_14 ( V_22 + V_28 , V_29 , V_30 ) ) {
F_15 ( & V_19 -> V_31 , V_30 L_1 ,
V_22 + 0xF0 ) ;
V_16 = - V_32 ;
goto V_33;
}
V_8 -> V_11 = F_16 ( V_22 + V_28 , V_29 ) ;
if ( ! V_8 -> V_11 ) {
F_17 ( V_30 L_2 ) ;
V_16 = - V_34 ;
goto V_35;
}
V_36 . V_8 = ( unsigned long ) V_8 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_15 = V_19 ;
F_18 ( V_30 L_3 ) ;
V_16 = F_19 ( & V_36 ) ;
if ( V_16 ) {
F_17 ( V_30 L_4 , V_16 ) ;
goto V_37;
}
return 0 ;
V_37:
F_20 ( V_8 -> V_11 ) ;
V_35:
F_21 ( V_22 + V_28 , V_29 ) ;
V_33:
F_22 ( V_8 ) ;
return V_16 ;
}
static void T_5 F_23 ( void )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_36 . V_8 ;
F_24 ( & V_36 ) ;
F_20 ( V_8 -> V_11 ) ;
F_21 ( V_8 -> V_22 + V_28 , V_29 ) ;
F_22 ( V_8 ) ;
}
