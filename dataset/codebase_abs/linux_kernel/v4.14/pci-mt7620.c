static inline void F_1 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( unsigned V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
static inline void F_5 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_4 + V_2 ) ;
}
static inline T_1 F_6 ( unsigned V_2 )
{
return F_4 ( V_4 + V_2 ) ;
}
static inline void F_7 ( T_1 V_5 , T_1 V_6 , unsigned V_2 )
{
T_1 V_1 = F_6 ( V_2 ) ;
V_1 &= ~ V_5 ;
V_1 |= V_6 ;
F_5 ( V_1 , V_2 ) ;
}
static int F_8 ( void )
{
unsigned long V_7 = 0x0 , V_8 = 0 ;
while ( 1 ) {
V_7 = F_6 ( V_9 ) ;
if ( V_7 & V_10 )
F_9 ( 100 ) ;
else
break;
if ( V_8 ++ > V_11 ) {
F_10 ( V_12 L_1 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_11 ( unsigned long V_13 , unsigned long V_1 )
{
F_8 () ;
F_5 ( V_14 | ( V_1 << V_15 ) | ( V_13 << V_16 ) ,
V_9 ) ;
F_9 ( 1 ) ;
F_8 () ;
}
static int F_12 ( struct V_17 * V_18 , unsigned int V_19 , int V_20 ,
int V_21 , T_1 * V_1 )
{
unsigned int V_22 = F_13 ( V_19 ) ;
T_2 V_23 = F_14 ( V_19 ) ;
T_1 V_24 ;
T_1 V_25 ;
T_1 V_26 = 0 ;
if ( V_18 )
V_26 = V_18 -> V_27 ;
V_24 = ( ( ( V_20 & 0xF00 ) >> 8 ) << 24 ) | ( V_26 << 16 ) | ( V_22 << 11 ) |
( V_23 << 8 ) | ( V_20 & 0xfc ) | 0x80000000 ;
F_1 ( V_24 , V_28 ) ;
V_25 = F_3 ( V_29 ) ;
switch ( V_21 ) {
case 1 :
* V_1 = ( V_25 >> ( ( V_20 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
* V_1 = ( V_25 >> ( ( V_20 & 3 ) << 3 ) ) & 0xffff ;
break;
case 4 :
* V_1 = V_25 ;
break;
}
return V_30 ;
}
static int F_15 ( struct V_17 * V_18 , unsigned int V_19 , int V_20 ,
int V_21 , T_1 V_1 )
{
unsigned int V_22 = F_13 ( V_19 ) ;
T_2 V_23 = F_14 ( V_19 ) ;
T_1 V_24 ;
T_1 V_25 ;
T_1 V_26 = 0 ;
if ( V_18 )
V_26 = V_18 -> V_27 ;
V_24 = ( ( ( V_20 & 0xF00 ) >> 8 ) << 24 ) | ( V_26 << 16 ) | ( V_22 << 11 ) |
( V_23 << 8 ) | ( V_20 & 0xfc ) | 0x80000000 ;
F_1 ( V_24 , V_28 ) ;
V_25 = F_3 ( V_29 ) ;
switch ( V_21 ) {
case 1 :
V_25 = ( V_25 & ~ ( 0xff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_1 << ( ( V_20 & 3 ) << 3 ) ) ;
break;
case 2 :
V_25 = ( V_25 & ~ ( 0xffff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_1 << ( ( V_20 & 3 ) << 3 ) ) ;
break;
case 4 :
V_25 = V_1 ;
break;
}
F_1 ( V_25 , V_29 ) ;
return V_30 ;
}
static int F_16 ( struct V_31 * V_32 )
{
F_11 ( 0x0 , 0x80 ) ;
F_11 ( 0x1 , 0x04 ) ;
F_11 ( 0x68 , 0xB4 ) ;
F_7 ( 0 , V_33 , V_34 ) ;
F_17 ( V_35 ) ;
F_18 ( V_36 , 0 , V_37 ) ;
F_18 ( V_38 , V_39 , V_40 ) ;
F_19 ( V_35 ) ;
F_18 ( 0 , V_36 , V_37 ) ;
F_9 ( 100 ) ;
if ( ! ( F_20 ( V_41 ) & V_39 ) ) {
F_21 ( & V_32 -> V_42 , L_2 ) ;
F_17 ( V_35 ) ;
F_18 ( V_36 , 0 , V_37 ) ;
return - 1 ;
}
F_18 ( V_43 | V_44 , V_38 | V_39 ,
V_40 ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_32 )
{
T_1 V_1 = 0 ;
F_18 ( F_23 ( 16 ) , 0 , V_45 ) ;
F_19 ( V_35 ) ;
F_18 ( 0 , V_36 , V_37 ) ;
F_9 ( 100 ) ;
F_7 ( ~ 0xff , 0x5 , V_46 ) ;
F_12 ( NULL , 0 , 0x70c , 4 , & V_1 ) ;
V_1 &= ~ ( 0xff ) << 8 ;
V_1 |= 0x50 << 8 ;
F_15 ( NULL , 0 , 0x70c , 4 , V_1 ) ;
F_12 ( NULL , 0 , 0x70c , 4 , & V_1 ) ;
F_21 ( & V_32 -> V_42 , L_3 , ( unsigned int ) V_1 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_47 * V_48 = F_25 ( V_32 ,
V_49 , 0 ) ;
struct V_47 * V_50 = F_25 ( V_32 ,
V_49 , 1 ) ;
T_1 V_1 = 0 ;
V_35 = F_26 ( & V_32 -> V_42 , L_4 ) ;
if ( F_27 ( V_35 ) )
return F_28 ( V_35 ) ;
V_3 = F_29 ( & V_32 -> V_42 , V_48 ) ;
if ( F_27 ( V_3 ) )
return F_28 ( V_3 ) ;
V_4 = F_29 ( & V_32 -> V_42 , V_50 ) ;
if ( F_27 ( V_4 ) )
return F_28 ( V_4 ) ;
V_51 . V_52 = 0 ;
V_51 . V_53 = ~ 0 ;
V_54 . V_52 = 0 ;
V_54 . V_53 = ~ 0 ;
switch ( V_55 ) {
case V_56 :
if ( F_16 ( V_32 ) )
return - 1 ;
break;
case V_57 :
if ( F_22 ( V_32 ) )
return - 1 ;
break;
default:
F_21 ( & V_32 -> V_42 , L_5 ) ;
return - 1 ;
}
F_9 ( 50 ) ;
F_7 ( V_33 , 0 , V_34 ) ;
F_9 ( 100 ) ;
if ( ( F_6 ( V_58 ) & V_59 ) == 0 ) {
F_17 ( V_35 ) ;
F_18 ( V_36 , 0 , V_37 ) ;
if ( V_55 == V_56 )
F_18 ( V_38 , V_39 , V_40 ) ;
F_21 ( & V_32 -> V_42 , L_6 ) ;
return - 1 ;
}
F_1 ( 0xffffffff , V_60 ) ;
F_1 ( V_61 , V_62 ) ;
F_5 ( 0x7FFF0001 , V_63 ) ;
F_5 ( V_64 , V_65 ) ;
F_5 ( 0x06040001 , V_66 ) ;
F_7 ( 0 , V_67 , V_68 ) ;
F_12 ( NULL , 0 , 4 , 4 , & V_1 ) ;
F_15 ( NULL , 0 , 4 , 4 , V_1 | 0x7 ) ;
F_30 ( & V_69 , V_32 -> V_42 . V_70 ) ;
F_31 ( & V_69 ) ;
return 0 ;
}
int F_32 ( const struct V_71 * V_42 , T_2 V_22 , T_2 V_72 )
{
T_3 V_73 ;
T_1 V_1 ;
int V_74 = 0 ;
if ( ( V_42 -> V_18 -> V_27 == 0 ) && ( V_22 == 0 ) ) {
F_5 ( 0x7FFF0001 , V_63 ) ;
F_15 ( V_42 -> V_18 , 0 , V_75 , 4 ,
V_64 ) ;
F_12 ( V_42 -> V_18 , 0 , V_75 , 4 , & V_1 ) ;
} else if ( ( V_42 -> V_18 -> V_27 == 1 ) && ( V_22 == 0x0 ) ) {
V_74 = V_76 ;
} else {
F_21 ( & V_42 -> V_42 , L_7 ,
V_42 -> V_18 -> V_27 , V_22 ) ;
return 0 ;
}
F_21 ( & V_42 -> V_42 , L_8 ,
V_42 -> V_18 -> V_27 , V_22 , V_74 ) ;
F_33 ( V_42 , V_77 , 0x14 ) ;
F_33 ( V_42 , V_78 , 0xff ) ;
F_34 ( V_42 , V_79 , & V_73 ) ;
V_73 = V_73 | V_80 | V_81 | V_82 ;
F_35 ( V_42 , V_79 , V_73 ) ;
F_33 ( V_42 , V_83 , V_42 -> V_74 ) ;
return V_74 ;
}
int F_36 ( struct V_71 * V_42 )
{
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_84 ) ;
}
