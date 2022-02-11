static T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static void F_3 ( T_1 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline T_1 F_5 ( unsigned int V_4 , unsigned int V_5 ,
unsigned int V_6 , unsigned int V_7 )
{
return ( ( V_4 << 16 ) | ( V_5 << 11 ) | ( V_6 << 8 ) | ( V_7 & 0xfc ) |
0x80000000 ) ;
}
static int F_6 ( struct V_8 * V_4 , unsigned int V_9 ,
int V_7 , int V_10 , T_1 * V_3 )
{
unsigned long V_11 ;
T_1 V_12 ;
T_1 V_13 ;
V_12 = F_5 ( V_4 -> V_14 , F_7 ( V_9 ) ,
F_8 ( V_9 ) , V_7 ) ;
F_9 ( & V_15 , V_11 ) ;
F_3 ( V_12 , V_16 ) ;
V_13 = F_1 ( V_17 ) ;
F_10 ( & V_15 , V_11 ) ;
switch ( V_10 ) {
case 1 :
* V_3 = ( V_13 >> ( ( V_7 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
* V_3 = ( V_13 >> ( ( V_7 & 3 ) << 3 ) ) & 0xffff ;
break;
case 4 :
* V_3 = V_13 ;
break;
}
return V_18 ;
}
static int F_11 ( struct V_8 * V_4 , unsigned int V_9 ,
int V_7 , int V_10 , T_1 V_3 )
{
unsigned long V_11 ;
T_1 V_12 ;
T_1 V_13 ;
V_12 = F_5 ( V_4 -> V_14 , F_7 ( V_9 ) ,
F_8 ( V_9 ) , V_7 ) ;
F_9 ( & V_15 , V_11 ) ;
F_3 ( V_12 , V_16 ) ;
V_13 = F_1 ( V_17 ) ;
switch ( V_10 ) {
case 1 :
V_13 = ( V_13 & ~ ( 0xff << ( ( V_7 & 3 ) << 3 ) ) ) |
( V_3 << ( ( V_7 & 3 ) << 3 ) ) ;
break;
case 2 :
V_13 = ( V_13 & ~ ( 0xffff << ( ( V_7 & 3 ) << 3 ) ) ) |
( V_3 << ( ( V_7 & 3 ) << 3 ) ) ;
break;
case 4 :
V_13 = V_3 ;
break;
}
F_3 ( V_13 , V_17 ) ;
F_10 ( & V_15 , V_11 ) ;
return V_18 ;
}
static inline T_1 F_12 ( unsigned long V_1 )
{
unsigned long V_11 ;
T_1 V_12 ;
T_1 V_19 ;
V_12 = F_5 ( 0 , 0 , 0 , V_1 ) ;
F_9 ( & V_15 , V_11 ) ;
F_3 ( V_12 , V_16 ) ;
V_19 = F_1 ( V_17 ) ;
F_10 ( & V_15 , V_11 ) ;
return V_19 ;
}
static inline void F_13 ( unsigned long V_1 , T_1 V_3 )
{
unsigned long V_11 ;
T_1 V_12 ;
V_12 = F_5 ( 0 , 0 , 0 , V_1 ) ;
F_9 ( & V_15 , V_11 ) ;
F_3 ( V_12 , V_16 ) ;
F_3 ( V_3 , V_17 ) ;
F_10 ( & V_15 , V_11 ) ;
}
int T_2 F_14 ( const struct V_20 * V_21 , T_3 V_5 , T_3 V_22 )
{
T_4 V_23 ;
int V_24 = - 1 ;
if ( V_21 -> V_4 -> V_14 != 0 )
return V_24 ;
switch ( F_7 ( V_21 -> V_9 ) ) {
case 0x00 :
F_13 ( V_25 , 0x08000000 ) ;
( void ) F_12 ( V_25 ) ;
break;
case 0x11 :
V_24 = V_26 ;
break;
default:
F_15 ( L_1 ,
__FILE__ , V_27 , __LINE__ ) ;
F_16 () ;
break;
}
F_17 ( (struct V_20 * ) V_21 ,
V_28 , 0x14 ) ;
F_17 ( (struct V_20 * ) V_21 , V_29 , 0xFF ) ;
F_18 ( (struct V_20 * ) V_21 , V_30 , & V_23 ) ;
V_23 |= V_31 | V_32 | V_33 |
V_34 | V_35 |
V_36 | V_37 | V_38 ;
F_19 ( (struct V_20 * ) V_21 , V_30 , V_23 ) ;
F_17 ( (struct V_20 * ) V_21 , V_39 ,
V_21 -> V_24 ) ;
return V_24 ;
}
static int F_20 ( struct V_40 * V_41 )
{
void T_5 * V_42 ;
int V_43 ;
V_2 = F_21 ( V_44 , V_45 ) ;
V_42 = F_22 ( V_46 , V_47 ) ;
V_48 . V_42 = ( unsigned long ) V_42 ;
F_23 ( ( unsigned long ) V_42 ) ;
V_49 . V_50 = V_46 ;
V_49 . V_51 = V_46 + V_47 - 1 ;
F_3 ( 0 , V_52 ) ;
for ( V_43 = 0 ; V_43 < 0xfffff ; V_43 ++ )
;
F_3 ( 0x79 , V_53 ) ;
F_3 ( 0x07FF0001 , V_54 ) ;
F_3 ( V_55 , V_56 ) ;
F_3 ( V_46 , V_57 ) ;
F_3 ( 0x08000000 , V_58 ) ;
F_3 ( 0x08021814 , V_59 ) ;
F_3 ( 0x00800001 , V_60 ) ;
F_3 ( 0x28801814 , V_61 ) ;
F_3 ( 0x000c0000 , V_62 ) ;
F_13 ( V_25 , 0x08000000 ) ;
( void ) F_12 ( V_25 ) ;
F_24 ( & V_48 ) ;
return 0 ;
}
int F_25 ( struct V_20 * V_21 )
{
return 0 ;
}
int T_2 F_26 ( void )
{
int V_19 = F_27 ( & V_63 ) ;
if ( V_19 )
F_28 ( L_2 ) ;
return V_19 ;
}
