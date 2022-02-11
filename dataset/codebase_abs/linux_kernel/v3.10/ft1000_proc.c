static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
static const char * V_4 [] = {
L_1 , L_2 , L_3 ,
L_4 , L_5 , L_6 , L_7 , L_7
} ;
static const char * signal [] = { L_7 , L_8 , L_9 , L_10 , L_11 } ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
int V_11 ;
int V_12 ;
struct V_13 V_14 ;
T_1 V_15 ;
if ( V_9 -> V_16 == V_17 ) {
if ( V_9 -> V_18 != 0xFF ) {
V_9 -> V_19 =
F_3 ( V_6 , V_20 ) ;
V_9 -> V_21 =
F_3 ( V_6 , V_22 ) ;
} else {
V_9 -> V_21 = 0xf ;
}
} else {
if ( V_9 -> V_18 != 0xFF ) {
V_9 -> V_19 =
F_4 ( F_5 (
V_6 , V_23 ,
V_24 ) ) ;
V_9 -> V_21 =
F_4 ( F_5 (
V_6 , V_25 ,
V_26 ) ) ;
} else {
V_9 -> V_21 = 0xf ;
}
}
V_10 = ( V_9 -> V_19 ) & 0xf ;
switch ( V_10 ) {
case 0x1 :
V_11 = 1 ;
break;
case 0x3 :
V_11 = 2 ;
break;
case 0x7 :
V_11 = 3 ;
break;
case 0xf :
V_11 = 4 ;
break;
default:
V_11 = 0 ;
}
V_10 = ( V_9 -> V_19 >> 8 ) & 0xf ;
switch ( V_10 ) {
case 0x1 :
V_12 = 1 ;
break;
case 0x3 :
V_12 = 2 ;
break;
case 0x7 :
V_12 = 3 ;
break;
case 0xf :
V_12 = 4 ;
break;
default:
V_12 = 0 ;
}
F_6 ( & V_14 ) ;
V_15 = V_14 . V_27 - V_9 -> V_28 ;
F_7 ( V_2 , L_12 ,
( ( V_15 / 3600 ) % 24 ) , ( ( V_15 / 60 ) % 60 ) , ( V_15 % 60 ) ) ;
F_7 ( V_2 , L_13 , V_15 ) ;
F_7 ( V_2 , L_14 ,
V_9 -> V_16 ==
V_17 ? L_15 : L_16 ) ;
F_8 ( V_2 , L_17 , V_29 , V_9 -> V_30 ) ;
F_8 ( V_2 , L_18 , V_31 , V_9 -> V_32 ) ;
F_9 ( V_2 , L_19 , V_33 , V_9 -> V_34 ) ;
F_8 ( V_2 , L_20 , V_35 , V_9 -> V_36 ) ;
F_8 ( V_2 , L_21 , V_37 , V_9 -> V_38 ) ;
F_9 ( V_2 , L_22 , V_39 , V_9 -> V_40 ) ;
F_7 ( V_2 , L_23 ,
( V_9 -> V_41 ) ? L_24 : L_25 ) ;
F_7 ( V_2 , L_26 , V_4 [ V_9 -> V_21 & 0x7 ] ) ;
F_7 ( V_2 , L_27 , V_9 -> V_42 . V_43 ) ;
F_7 ( V_2 , L_28 , V_9 -> V_42 . V_44 ) ;
F_7 ( V_2 , L_29 , V_9 -> V_42 . V_45 ) ;
F_7 ( V_2 , L_30 , V_9 -> V_42 . V_46 ) ;
F_7 ( V_2 , L_31 , signal [ V_11 ] ) ;
F_7 ( V_2 , L_32 , signal [ V_12 ] ) ;
return 0 ;
}
static int F_10 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
return F_11 ( V_48 , F_1 , F_12 ( V_47 ) ) ;
}
static int F_13 ( struct V_49 * V_50 , unsigned long V_51 ,
void * V_52 )
{
struct V_5 * V_6 = V_52 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_6 ) ;
switch ( V_51 ) {
case V_53 :
F_14 ( V_9 -> V_54 , V_9 -> V_55 ) ;
F_15 ( V_6 -> V_56 , 0644 , V_9 -> V_55 ,
& V_57 , V_6 ) ;
snprintf ( V_9 -> V_54 , V_58 , L_33 , V_6 -> V_56 ) ;
break;
}
return V_59 ;
}
void F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_6 ) ;
V_9 -> V_55 = F_17 ( V_60 , V_61 . V_62 ) ;
F_15 ( V_6 -> V_56 , 0644 , V_9 -> V_55 ,
& V_57 , V_6 ) ;
snprintf ( V_9 -> V_54 , V_58 , L_33 , V_6 -> V_56 ) ;
F_18 ( & V_63 ) ;
}
void F_19 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_6 ) ;
F_14 ( V_6 -> V_56 , V_9 -> V_55 ) ;
F_14 ( V_60 , V_61 . V_62 ) ;
F_20 ( & V_63 ) ;
}
