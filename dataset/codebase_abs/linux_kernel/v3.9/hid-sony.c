static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & V_8 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( ( ( V_6 -> V_7 & V_9 ) && * V_4 == 148 ) ||
( ( V_6 -> V_7 & V_10 ) && * V_4 == 149 ) ) &&
V_3 [ 83 ] == 0x75 ) {
F_3 ( V_2 , L_2 ) ;
memcpy ( ( void * ) & V_3 [ 83 ] , ( void * ) & V_11 ,
sizeof( V_11 ) ) ;
} else if ( V_6 -> V_7 & V_9 &&
* V_4 > sizeof( V_12 ) ) {
F_3 ( V_2 , L_3 ,
* V_4 , ( int ) sizeof( V_12 ) ) ;
* V_4 = sizeof( V_12 ) ;
memcpy ( V_3 , & V_12 , * V_4 ) ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_13 * V_14 ,
T_1 * V_15 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_7 & ( V_9 | V_10 ) ) &&
V_15 [ 0 ] == 0x01 && V_16 == 49 ) {
F_5 ( V_15 [ 41 ] , V_15 [ 42 ] ) ;
F_5 ( V_15 [ 43 ] , V_15 [ 44 ] ) ;
F_5 ( V_15 [ 45 ] , V_15 [ 46 ] ) ;
F_5 ( V_15 [ 47 ] , V_15 [ 48 ] ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_17 , T_1 * V_18 ,
T_2 V_19 , unsigned char V_20 )
{
struct V_21 * V_22 = F_7 ( V_17 -> V_23 . V_24 ) ;
struct V_25 * V_23 = F_8 ( V_22 ) ;
struct V_26 * V_27 = V_22 -> V_28 ;
int V_29 = V_18 [ 0 ] ;
int V_30 ;
if ( V_20 == V_31 ) {
V_18 ++ ;
V_19 -- ;
}
V_30 = F_9 ( V_23 , F_10 ( V_23 , 0 ) ,
V_32 ,
V_33 | V_34 | V_35 ,
( ( V_20 + 1 ) << 8 ) | V_29 ,
V_27 -> V_36 . V_37 , V_18 , V_19 ,
V_38 ) ;
if ( V_30 > 0 && V_20 == V_31 )
V_30 ++ ;
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_7 ( V_2 -> V_23 . V_24 ) ;
struct V_25 * V_23 = F_8 ( V_22 ) ;
T_3 V_39 = V_22 -> V_28 -> V_36 . V_37 ;
int V_30 ;
char * V_18 = F_12 ( 18 , V_40 ) ;
if ( ! V_18 )
return - V_41 ;
V_30 = F_9 ( V_23 , F_13 ( V_23 , 0 ) ,
V_42 ,
V_43 | V_34 |
V_35 ,
( 3 << 8 ) | 0xf2 , V_39 , V_18 , 17 ,
V_44 ) ;
if ( V_30 < 0 )
F_14 ( V_2 , L_4 ) ;
F_15 ( V_18 ) ;
return V_30 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_18 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_45 ( V_2 , V_18 , sizeof( V_18 ) , V_46 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
int V_30 ;
unsigned long V_7 = V_48 -> V_49 ;
struct V_5 * V_6 ;
V_6 = F_18 ( sizeof( * V_6 ) , V_40 ) ;
if ( V_6 == NULL ) {
F_14 ( V_2 , L_5 ) ;
return - V_41 ;
}
V_6 -> V_7 = V_7 ;
F_19 ( V_2 , V_6 ) ;
V_30 = F_20 ( V_2 ) ;
if ( V_30 ) {
F_14 ( V_2 , L_6 ) ;
goto V_50;
}
V_30 = F_21 ( V_2 , V_51 |
V_52 ) ;
if ( V_30 ) {
F_14 ( V_2 , L_7 ) ;
goto V_50;
}
if ( V_6 -> V_7 & V_9 ) {
V_2 -> V_45 = F_6 ;
V_30 = F_11 ( V_2 ) ;
}
else if ( V_6 -> V_7 & V_10 )
V_30 = F_16 ( V_2 ) ;
else
V_30 = 0 ;
if ( V_30 < 0 )
goto V_53;
return 0 ;
V_53:
F_22 ( V_2 ) ;
V_50:
F_15 ( V_6 ) ;
return V_30 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_15 ( F_2 ( V_2 ) ) ;
}
