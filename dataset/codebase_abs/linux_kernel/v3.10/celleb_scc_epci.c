static inline T_1 F_1 (
struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static inline T_1 F_2 (
struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
static inline void F_3 (
struct V_1 * V_2 )
{
T_1 V_5 ;
T_1 V_6 ;
V_5 = F_1 ( V_2 ) ;
V_6 = V_5 + V_7 ;
F_4 ( V_6 , F_5 ( V_6 ) | ( V_8 << 16 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_9 )
{
T_1 V_6 ;
T_1 V_5 ;
T_2 V_10 ;
F_7 () ;
V_5 = F_1 ( V_2 ) ;
V_6 = V_5 + V_7 ;
V_10 = F_5 ( V_6 ) ;
if ( V_10 & ( V_8 << 16 ) ) {
F_4 ( V_6 ,
( V_10 & 0xffff ) | ( V_8 << 16 ) ) ;
V_6 = V_5 + V_11 ;
F_4 ( V_6 , V_12 ) ;
V_6 = V_5 + V_13 ;
V_10 = F_5 ( V_6 ) & 0xffff ;
V_10 |= V_14 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_15 ;
F_4 ( V_6 , V_16 ) ;
return V_17 ;
}
return V_18 ;
}
static T_1 F_8 ( struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned int V_21 , int V_22 )
{
T_1 V_9 ;
if ( V_20 != V_2 -> V_20 )
V_9 = F_2 ( V_2 ) +
( ( ( V_20 -> V_23 & 0xff ) << 16 )
| ( ( V_21 & 0xff ) << 8 )
| ( V_22 & 0xff )
| 0x01000000 ) ;
else
V_9 = F_2 ( V_2 ) +
( ( ( V_21 & 0xff ) << 8 ) | ( V_22 & 0xff ) ) ;
F_9 ( L_1 , V_9 ) ;
return V_9 ;
}
static int F_10 ( struct V_19 * V_20 ,
unsigned int V_21 , int V_22 , int V_24 , T_2 * V_10 )
{
T_1 V_5 ;
T_1 V_9 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
F_12 ( V_22 % V_24 ) ;
if ( ! F_2 ( V_2 ) )
return V_17 ;
if ( V_20 -> V_23 == V_2 -> V_25 && V_21 == 0 ) {
V_5 = F_1 ( V_2 ) ;
V_9 = V_5 + V_22 ;
switch ( V_24 ) {
case 1 :
* V_10 = F_13 ( V_9 ) ;
break;
case 2 :
* V_10 = F_14 ( V_9 ) ;
break;
case 4 :
* V_10 = F_5 ( V_9 ) ;
break;
default:
return V_17 ;
}
} else {
F_3 ( V_2 ) ;
V_9 = F_8 ( V_20 , V_2 , V_21 , V_22 ) ;
switch ( V_24 ) {
case 1 :
* V_10 = F_13 ( V_9 ) ;
break;
case 2 :
* V_10 = F_15 ( V_9 ) ;
break;
case 4 :
* V_10 = F_16 ( V_9 ) ;
break;
default:
return V_17 ;
}
}
F_9 ( L_2
L_3 ,
V_9 , V_21 , V_22 , V_24 , * V_10 ) ;
return F_6 ( V_2 , NULL ) ;
}
static int F_17 ( struct V_19 * V_20 ,
unsigned int V_21 , int V_22 , int V_24 , T_2 V_10 )
{
T_1 V_5 ;
T_1 V_9 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
F_12 ( V_22 % V_24 ) ;
if ( ! F_2 ( V_2 ) )
return V_17 ;
if ( V_20 -> V_23 == V_2 -> V_25 && V_21 == 0 ) {
V_5 = F_1 ( V_2 ) ;
V_9 = V_5 + V_22 ;
switch ( V_24 ) {
case 1 :
F_18 ( V_9 , V_10 ) ;
break;
case 2 :
F_19 ( V_9 , V_10 ) ;
break;
case 4 :
F_4 ( V_9 , V_10 ) ;
break;
default:
return V_17 ;
}
} else {
F_3 ( V_2 ) ;
V_9 = F_8 ( V_20 , V_2 , V_21 , V_22 ) ;
switch ( V_24 ) {
case 1 :
F_18 ( V_9 , V_10 ) ;
break;
case 2 :
F_20 ( V_9 , V_10 ) ;
break;
case 4 :
F_21 ( V_9 , V_10 ) ;
break;
default:
return V_17 ;
}
}
return F_6 ( V_2 , V_9 ) ;
}
static int T_3 F_22 ( struct V_1 * V_2 )
{
T_2 V_10 ;
T_1 V_6 ;
T_1 V_5 ;
int V_26 = 0 ;
V_5 = F_1 ( V_2 ) ;
V_6 = V_5 + V_27 ;
V_10 = F_5 ( V_6 ) ;
if ( V_10 == 0x00030101 )
V_26 = 1 ;
else {
V_10 &= ~ ( V_28 | V_29 ) ;
F_4 ( V_6 , V_10 ) ;
V_10 = F_5 ( V_6 ) ;
V_10 |= ( V_30 | V_31 ) ;
F_4 ( V_6 , V_10 ) ;
V_10 = F_5 ( V_6 ) ;
V_10 |= V_28 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_32 ;
V_10 = F_5 ( V_6 ) ;
V_10 &= ~ V_33 ;
V_10 |= V_34 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_35 ;
F_4 ( V_6 , 0x0f1f001f ) ;
V_6 = V_5 + V_32 ;
V_10 = F_5 ( V_6 ) ;
V_10 |= V_36 ;
F_4 ( V_6 , V_10 ) ;
V_10 = F_5 ( V_6 ) ;
V_10 |= V_37 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_27 ;
V_10 = F_5 ( V_6 ) ;
V_10 |= ( V_28 | V_29 ) ;
F_4 ( V_6 , V_10 ) ;
}
V_6 = V_5 + V_38 ;
F_4 ( V_6 , 0x013f011f ) ;
V_6 = V_5 + V_39 ;
V_10 = V_40 | V_41 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_11 ;
F_4 ( V_6 , 0xffffffff ) ;
V_6 = V_5 + V_15 ;
F_4 ( V_6 , 0xffffffff ) ;
V_6 = V_5 + V_13 ;
V_10 = F_5 ( V_6 ) ;
V_10 &= ~ ( V_42 | V_43 ) ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_7 ;
V_10 = V_44 | V_45 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_46 ;
V_10 = 0x00550155 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_47 ;
V_10 = F_5 ( V_6 ) ;
V_10 |= V_48 ;
F_4 ( V_6 , V_10 ) ;
V_6 = V_5 + V_49 ;
F_4 ( V_6 , 0x80000008 ) ;
V_6 = V_5 + V_50 ;
F_4 ( V_6 , 0x40000008 ) ;
V_6 = V_5 + V_51 ;
F_4 ( V_6 , 0x80000000 ) ;
V_6 = V_5 + V_52 ;
F_4 ( V_6 , 0xe0000000 ) ;
V_6 = V_5 + V_53 ;
F_4 ( V_6 , 0x80000000 ) ;
if ( ! V_26 ) {
V_6 = V_5 + V_32 ;
V_10 = F_5 ( V_6 ) ;
V_10 |= V_54 ;
F_4 ( V_6 , V_10 ) ;
}
return 0 ;
}
static int T_3 F_23 ( struct V_55 * V_56 ,
struct V_1 * V_2 )
{
struct V_57 V_58 ;
F_9 ( L_4 ) ;
if ( F_24 ( V_56 , 0 , & V_58 ) )
goto error;
V_2 -> V_3 = F_25 ( V_58 . V_59 , F_26 ( & V_58 ) ) ;
if ( ! V_2 -> V_3 )
goto error;
F_9 ( L_5 ,
V_58 . V_59 , ( unsigned long ) V_2 -> V_3 , F_26 ( & V_58 ) ) ;
if ( F_24 ( V_56 , 2 , & V_58 ) )
goto error;
V_2 -> V_4 = F_25 ( V_58 . V_59 , F_26 ( & V_58 ) ) ;
if ( ! V_2 -> V_4 )
goto error;
F_9 ( L_6 ,
V_58 . V_59 , ( unsigned long ) V_2 -> V_4 , F_26 ( & V_58 ) ) ;
V_2 -> V_60 = & V_61 ;
F_22 ( V_2 ) ;
return 0 ;
error:
if ( V_2 -> V_3 )
F_27 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
return 1 ;
}
