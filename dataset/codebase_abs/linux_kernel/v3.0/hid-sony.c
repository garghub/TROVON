static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_8 ) &&
* V_4 >= 56 && V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_9 , T_1 * V_10 ,
T_2 V_11 , unsigned char V_12 )
{
struct V_13 * V_14 = F_5 ( V_9 -> V_15 . V_16 ) ;
struct V_17 * V_15 = F_6 ( V_14 ) ;
struct V_18 * V_19 = V_14 -> V_20 ;
int V_21 = V_10 [ 0 ] ;
int V_22 ;
if ( V_12 == V_23 ) {
V_10 ++ ;
V_11 -- ;
}
V_22 = F_7 ( V_15 , F_8 ( V_15 , 0 ) ,
V_24 ,
V_25 | V_26 | V_27 ,
( ( V_12 + 1 ) << 8 ) | V_21 ,
V_19 -> V_28 . V_29 , V_10 , V_11 ,
V_30 ) ;
if ( V_22 > 0 && V_12 == V_23 )
V_22 ++ ;
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 -> V_15 . V_16 ) ;
struct V_17 * V_15 = F_6 ( V_14 ) ;
T_3 V_31 = V_14 -> V_20 -> V_28 . V_29 ;
int V_22 ;
char * V_10 = F_10 ( 18 , V_32 ) ;
if ( ! V_10 )
return - V_33 ;
V_22 = F_7 ( V_15 , F_11 ( V_15 , 0 ) ,
V_34 ,
V_35 | V_26 |
V_27 ,
( 3 << 8 ) | 0xf2 , V_31 , V_10 , 17 ,
V_36 ) ;
if ( V_22 < 0 )
F_12 ( V_2 , L_2 ) ;
F_13 ( V_10 ) ;
return V_22 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned char V_10 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_37 ( V_2 , V_10 , sizeof( V_10 ) , V_38 ) ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_39 * V_40 )
{
int V_22 ;
unsigned long V_7 = V_40 -> V_41 ;
struct V_5 * V_6 ;
V_6 = F_16 ( sizeof( * V_6 ) , V_32 ) ;
if ( V_6 == NULL ) {
F_12 ( V_2 , L_3 ) ;
return - V_33 ;
}
V_6 -> V_7 = V_7 ;
F_17 ( V_2 , V_6 ) ;
V_22 = F_18 ( V_2 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_4 ) ;
goto V_42;
}
V_22 = F_19 ( V_2 , V_43 |
V_44 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_5 ) ;
goto V_42;
}
if ( V_6 -> V_7 & V_45 ) {
V_2 -> V_37 = F_4 ;
V_22 = F_9 ( V_2 ) ;
}
else if ( V_6 -> V_7 & V_46 )
V_22 = F_14 ( V_2 ) ;
else
V_22 = 0 ;
if ( V_22 < 0 )
goto V_47;
return 0 ;
V_47:
F_20 ( V_2 ) ;
V_42:
F_13 ( V_6 ) ;
return V_22 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_13 ( F_2 ( V_2 ) ) ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_48 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_48 ) ;
}
