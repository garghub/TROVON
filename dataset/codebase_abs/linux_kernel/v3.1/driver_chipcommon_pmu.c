static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
F_2 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
F_2 ( V_2 , V_7 ) ;
V_6 = F_2 ( V_2 , V_8 ) ;
V_6 &= V_4 ;
V_6 |= V_5 ;
F_3 ( V_2 , V_8 , V_6 ) ;
F_2 ( V_2 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
switch ( V_10 -> V_12 . V_13 ) {
case 0x4313 :
case 0x4331 :
case 43224 :
case 43225 :
break;
default:
F_5 ( L_1 ,
V_10 -> V_12 . V_13 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
T_1 V_14 = 0 , V_15 = 0 ;
switch ( V_10 -> V_12 . V_13 ) {
case 0x4313 :
V_14 = 0x200D ;
V_15 = 0xFFFF ;
break;
case 43224 :
case 43225 :
break;
default:
F_5 ( L_2 ,
V_10 -> V_12 . V_13 ) ;
}
if ( V_14 )
F_3 ( V_2 , V_16 , V_14 ) ;
if ( V_15 )
F_3 ( V_2 , V_17 , V_15 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
switch ( V_10 -> V_12 . V_13 ) {
case 0x4313 :
case 0x4331 :
case 43224 :
case 43225 :
break;
default:
F_5 ( L_3
L_4 , V_10 -> V_12 . V_13 ) ;
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
switch ( V_10 -> V_12 . V_13 ) {
case 0x4313 :
F_1 ( V_2 , 0 , ~ 0 , 0x7 ) ;
break;
case 0x4331 :
F_5 ( L_5 ) ;
break;
case 43224 :
if ( V_10 -> V_12 . V_18 == 0 ) {
F_5 ( L_6
L_7 ) ;
F_1 ( V_2 , 0 , ~ 0 , 0x00F000F0 ) ;
} else {
F_1 ( V_2 , 0 , ~ 0 , 0xF0 ) ;
}
break;
case 43225 :
break;
default:
F_5 ( L_8 ,
V_10 -> V_12 . V_13 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_19 ;
V_19 = F_2 ( V_2 , V_20 ) ;
V_2 -> V_21 . V_18 = ( V_19 & V_22 ) ;
F_10 ( L_9 , V_2 -> V_21 . V_18 ,
V_19 ) ;
if ( V_2 -> V_21 . V_18 == 1 )
F_11 ( V_2 , V_23 ,
~ V_24 ) ;
else
F_12 ( V_2 , V_23 ,
V_24 ) ;
if ( V_2 -> V_11 -> V_13 . V_13 == 0x4329 && V_2 -> V_11 -> V_13 . V_18 == 2 )
F_5 ( L_10 ) ;
F_4 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
