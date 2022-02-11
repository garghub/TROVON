static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_8 ) &&
* V_4 >= 56 && V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( ( ( V_6 -> V_7 & V_9 ) && * V_4 == 148 ) ||
( ( V_6 -> V_7 & V_10 ) && * V_4 == 149 ) ) &&
V_3 [ 83 ] == 0x75 ) {
F_3 ( V_2 , L_2 ) ;
memcpy ( ( void * ) & V_3 [ 83 ] , ( void * ) & V_11 ,
sizeof( V_11 ) ) ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & ( V_9 | V_10 ) ) &&
V_14 [ 0 ] == 0x01 && V_15 == 49 ) {
F_5 ( V_14 [ 41 ] , V_14 [ 42 ] ) ;
F_5 ( V_14 [ 43 ] , V_14 [ 44 ] ) ;
F_5 ( V_14 [ 45 ] , V_14 [ 46 ] ) ;
F_5 ( V_14 [ 47 ] , V_14 [ 48 ] ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_16 , T_1 * V_17 ,
T_2 V_18 , unsigned char V_19 )
{
struct V_20 * V_21 = F_7 ( V_16 -> V_22 . V_23 ) ;
struct V_24 * V_22 = F_8 ( V_21 ) ;
struct V_25 * V_26 = V_21 -> V_27 ;
int V_28 = V_17 [ 0 ] ;
int V_29 ;
if ( V_19 == V_30 ) {
V_17 ++ ;
V_18 -- ;
}
V_29 = F_9 ( V_22 , F_10 ( V_22 , 0 ) ,
V_31 ,
V_32 | V_33 | V_34 ,
( ( V_19 + 1 ) << 8 ) | V_28 ,
V_26 -> V_35 . V_36 , V_17 , V_18 ,
V_37 ) ;
if ( V_29 > 0 && V_19 == V_30 )
V_29 ++ ;
return V_29 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_7 ( V_2 -> V_22 . V_23 ) ;
struct V_24 * V_22 = F_8 ( V_21 ) ;
T_3 V_38 = V_21 -> V_27 -> V_35 . V_36 ;
int V_29 ;
char * V_17 = F_12 ( 18 , V_39 ) ;
if ( ! V_17 )
return - V_40 ;
V_29 = F_9 ( V_22 , F_13 ( V_22 , 0 ) ,
V_41 ,
V_42 | V_33 |
V_34 ,
( 3 << 8 ) | 0xf2 , V_38 , V_17 , 17 ,
V_43 ) ;
if ( V_29 < 0 )
F_14 ( V_2 , L_3 ) ;
F_15 ( V_17 ) ;
return V_29 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_17 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_44 ( V_2 , V_17 , sizeof( V_17 ) , V_45 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_46 * V_47 )
{
int V_29 ;
unsigned long V_7 = V_47 -> V_48 ;
struct V_5 * V_6 ;
V_6 = F_18 ( sizeof( * V_6 ) , V_39 ) ;
if ( V_6 == NULL ) {
F_14 ( V_2 , L_4 ) ;
return - V_40 ;
}
V_6 -> V_7 = V_7 ;
F_19 ( V_2 , V_6 ) ;
V_29 = F_20 ( V_2 ) ;
if ( V_29 ) {
F_14 ( V_2 , L_5 ) ;
goto V_49;
}
V_29 = F_21 ( V_2 , V_50 |
V_51 ) ;
if ( V_29 ) {
F_14 ( V_2 , L_6 ) ;
goto V_49;
}
if ( V_6 -> V_7 & V_9 ) {
V_2 -> V_44 = F_6 ;
V_29 = F_11 ( V_2 ) ;
}
else if ( V_6 -> V_7 & V_10 )
V_29 = F_16 ( V_2 ) ;
else
V_29 = 0 ;
if ( V_29 < 0 )
goto V_52;
return 0 ;
V_52:
F_22 ( V_2 ) ;
V_49:
F_15 ( V_6 ) ;
return V_29 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_15 ( F_2 ( V_2 ) ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_53 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_53 ) ;
}
