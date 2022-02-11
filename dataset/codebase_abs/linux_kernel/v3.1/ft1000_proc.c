int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
int V_10 ;
struct V_11 * V_12 ;
char * V_13 [] =
{ L_1 , L_2 , L_3 ,
L_4 , L_5 , L_6 , L_7 , L_7
} ;
char * signal [] = { L_7 , L_8 , L_9 , L_10 , L_11 } ;
int V_14 ;
int V_15 ;
struct V_16 V_17 ;
T_2 V_18 ;
V_8 = (struct V_7 * ) V_6 ;
V_12 = F_2 ( V_8 ) ;
if ( V_3 > 0 ) {
* V_5 = 1 ;
return 0 ;
}
if ( V_12 -> V_19 == V_20 ) {
if ( V_12 -> V_21 != 0xFF ) {
V_12 -> V_22 =
F_3 ( V_8 , V_23 ) ;
V_12 -> V_24 =
F_3 ( V_8 ,
V_25 ) ;
} else {
V_12 -> V_24 = 0xf ;
}
} else {
if ( V_12 -> V_21 != 0xFF ) {
V_12 -> V_22 =
F_4 ( F_5
( V_8 , V_26 ,
V_27 ) ) ;
V_12 -> V_24 =
F_4 ( F_5
( V_8 , V_28 ,
V_29 ) ) ;
} else {
V_12 -> V_24 = 0xf ;
}
}
V_10 = ( V_12 -> V_22 ) & 0xf ;
switch ( V_10 ) {
case 0x1 :
V_14 = 1 ;
break;
case 0x3 :
V_14 = 2 ;
break;
case 0x7 :
V_14 = 3 ;
break;
case 0xf :
V_14 = 4 ;
break;
default:
V_14 = 0 ;
}
V_10 = ( V_12 -> V_22 >> 8 ) & 0xf ;
switch ( V_10 ) {
case 0x1 :
V_15 = 1 ;
break;
case 0x3 :
V_15 = 2 ;
break;
case 0x7 :
V_15 = 3 ;
break;
case 0xf :
V_15 = 4 ;
break;
default:
V_15 = 0 ;
}
F_6 ( & V_17 ) ;
V_18 = ( V_17 . V_30 - V_12 -> V_31 ) ;
V_9 = 0 ;
F_7 ( V_9 , V_1 , L_12 ,
( ( V_18 / 3600 ) % 24 ) , ( ( V_18 / 60 ) % 60 ) , ( V_18 % 60 ) ) ;
F_7 ( V_9 , V_1 , L_13 , V_18 ) ;
F_7 ( V_9 , V_1 , L_14 ,
( V_12 -> V_19 ) ==
V_20 ? L_15 : L_16 ) ;
F_8 ( V_9 , V_1 , L_17 , V_32 , V_12 -> V_33 ) ;
F_8 ( V_9 , V_1 , L_18 , V_34 , V_12 -> V_35 ) ;
F_9 ( V_9 , V_1 , L_19 , V_36 , V_12 -> V_37 ) ;
F_8 ( V_9 , V_1 , L_20 , V_38 ,
V_12 -> V_39 ) ;
F_8 ( V_9 , V_1 , L_21 , V_40 ,
V_12 -> V_41 ) ;
F_9 ( V_9 , V_1 , L_22 , V_42 ,
V_12 -> V_43 ) ;
F_7 ( V_9 , V_1 , L_23 ,
( V_12 -> V_44 ) ? L_24 : L_25 ) ;
F_7 ( V_9 , V_1 , L_26 ,
V_13 [ ( ( V_12 -> V_24 ) & 0x7 ) ] ) ;
F_7 ( V_9 , V_1 , L_27 , V_12 -> V_45 . V_46 ) ;
F_7 ( V_9 , V_1 , L_28 , V_12 -> V_45 . V_47 ) ;
F_7 ( V_9 , V_1 , L_29 , V_12 -> V_45 . V_48 ) ;
F_7 ( V_9 , V_1 , L_30 , V_12 -> V_45 . V_49 ) ;
F_7 ( V_9 , V_1 , L_31 , signal [ V_14 ] ) ;
F_7 ( V_9 , V_1 , L_32 , signal [ V_15 ] ) ;
return V_9 ;
}
static int F_10 ( struct V_50 * V_51 , unsigned long V_52 ,
void * V_53 )
{
struct V_7 * V_8 = V_53 ;
struct V_11 * V_12 ;
V_12 = F_2 ( V_8 ) ;
switch ( V_52 ) {
case V_54 :
F_11 ( V_12 -> V_55 , V_12 -> V_56 ) ;
F_12 ( V_8 -> V_57 , 0644 , V_12 -> V_56 ,
F_1 , V_8 ) ;
snprintf ( V_12 -> V_55 , V_58 , L_33 , V_8 -> V_57 ) ;
break;
}
return V_59 ;
}
void F_13 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
V_12 = F_2 ( V_8 ) ;
V_12 -> V_56 = F_14 ( V_60 , V_61 . V_62 ) ;
F_12 ( V_8 -> V_57 , 0644 , V_12 -> V_56 ,
F_1 , V_8 ) ;
snprintf ( V_12 -> V_55 , V_58 , L_33 , V_8 -> V_57 ) ;
F_15 ( & V_63 ) ;
}
void F_16 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
V_12 = F_2 ( V_8 ) ;
F_11 ( V_8 -> V_57 , V_12 -> V_56 ) ;
F_11 ( V_60 , V_61 . V_62 ) ;
F_17 ( & V_63 ) ;
}
