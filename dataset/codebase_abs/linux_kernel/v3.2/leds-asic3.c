static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
const struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_6 -> V_7 . V_8 ) ;
T_1 V_13 ;
unsigned int V_14 ;
V_13 = ( V_4 == V_15 ) ? 0 : ( V_16 | 0x4 ) ;
V_14 = V_17 [ V_10 -> V_18 ] ;
F_5 ( V_12 , ( V_14 + V_19 ) , 32 ) ;
F_5 ( V_12 , ( V_14 + V_20 ) , 32 ) ;
F_5 ( V_12 , ( V_14 + V_21 ) , 0 ) ;
F_5 ( V_12 , ( V_14 + V_22 ) , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long * V_23 ,
unsigned long * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
const struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_6 -> V_7 . V_8 ) ;
T_1 V_25 ;
T_1 V_26 ;
unsigned int V_14 ;
if ( * V_23 > V_27 || * V_24 > V_27 )
return - V_28 ;
if ( * V_23 == 0 && * V_24 == 0 ) {
V_25 = F_7 ( 500 ) ;
V_26 = F_7 ( 500 ) ;
} else {
V_25 = F_7 ( * V_23 ) ;
V_26 = F_7 ( * V_24 ) ;
if ( ( V_25 + V_26 ) > V_29 )
return - V_28 ;
}
V_14 = V_17 [ V_10 -> V_18 ] ;
F_5 ( V_12 , ( V_14 + V_19 ) , ( V_25 + V_26 ) ) ;
F_5 ( V_12 , ( V_14 + V_20 ) , V_25 ) ;
F_5 ( V_12 , ( V_14 + V_21 ) , 0 ) ;
F_5 ( V_12 , ( V_14 + V_22 ) , ( V_16 | 0x4 ) ) ;
* V_23 = F_8 ( V_25 ) ;
* V_24 = F_8 ( V_26 ) ;
return 0 ;
}
static int T_2 F_9 ( struct V_5 * V_6 )
{
struct V_30 * V_31 = V_6 -> V_7 . V_32 ;
int V_33 ;
V_33 = F_10 ( V_6 ) ;
if ( V_33 < 0 )
goto V_34;
V_31 -> V_2 = F_11 ( sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_31 -> V_2 ) {
V_33 = - V_36 ;
goto V_37;
}
V_31 -> V_2 -> V_38 = V_31 -> V_38 ;
V_31 -> V_2 -> V_39 = V_40 ;
V_31 -> V_2 -> F_1 = F_1 ;
V_31 -> V_2 -> F_6 = F_6 ;
V_31 -> V_2 -> V_41 = V_31 -> V_41 ;
V_33 = F_12 ( & V_6 -> V_7 , V_31 -> V_2 ) ;
if ( V_33 < 0 )
goto V_42;
return 0 ;
V_42:
F_13 ( V_31 -> V_2 ) ;
V_37:
( void ) F_14 ( V_6 ) ;
V_34:
return V_33 ;
}
static int T_3 F_15 ( struct V_5 * V_6 )
{
struct V_30 * V_31 = V_6 -> V_7 . V_32 ;
F_16 ( V_31 -> V_2 ) ;
F_13 ( V_31 -> V_2 ) ;
return F_14 ( V_6 ) ;
}
static int F_17 ( struct V_43 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
const struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_33 ;
V_33 = 0 ;
if ( V_10 -> V_44 )
V_33 = (* V_10 -> V_44 )( V_6 ) ;
return V_33 ;
}
static int F_18 ( struct V_43 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
const struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_33 ;
V_33 = 0 ;
if ( V_10 -> V_45 )
V_33 = (* V_10 -> V_45 )( V_6 ) ;
return V_33 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_46 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_46 ) ;
}
