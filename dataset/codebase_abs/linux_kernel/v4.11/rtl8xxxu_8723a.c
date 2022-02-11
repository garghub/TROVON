static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
if ( V_4 -> V_7 != F_2 ( 0x8129 ) )
return - V_8 ;
F_3 ( V_2 -> V_9 , V_4 -> V_9 ) ;
memcpy ( V_2 -> V_10 ,
V_4 -> V_10 ,
sizeof( V_4 -> V_10 ) ) ;
memcpy ( V_2 -> V_11 ,
V_4 -> V_11 ,
sizeof( V_4 -> V_11 ) ) ;
memcpy ( V_2 -> V_12 ,
V_4 -> V_12 ,
sizeof( V_4 -> V_12 ) ) ;
memcpy ( V_2 -> V_13 ,
V_4 -> V_13 ,
sizeof( V_4 -> V_13 ) ) ;
memcpy ( V_2 -> V_14 ,
V_4 -> V_14 ,
sizeof( V_4 -> V_14 ) ) ;
memcpy ( V_2 -> V_15 ,
V_4 -> V_15 ,
sizeof( V_4 -> V_15 ) ) ;
memcpy ( V_2 -> V_16 ,
V_4 -> V_16 ,
sizeof( V_4 -> V_16 ) ) ;
memcpy ( V_2 -> V_17 ,
V_4 -> V_17 ,
sizeof( V_4 -> V_17 ) ) ;
if ( V_2 -> V_5 . V_6 . V_18 >= 0x01 ) {
V_2 -> V_19 = 1 ;
V_2 -> V_20 = V_2 -> V_5 . V_6 . V_21 & 0x3f ;
}
V_2 -> V_22 = & V_23 ;
F_4 ( & V_2 -> V_24 -> V_25 , L_1 ,
V_4 -> V_26 ) ;
F_4 ( & V_2 -> V_24 -> V_25 , L_2 ,
V_4 -> V_27 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
char * V_28 ;
int V_29 ;
switch ( V_2 -> V_30 ) {
case 0 :
V_28 = L_3 ;
break;
case 1 :
if ( V_2 -> V_31 )
V_28 = L_4 ;
else
V_28 = L_5 ;
break;
default:
return - V_8 ;
}
V_29 = F_6 ( V_2 , V_28 ) ;
return V_29 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_8 ( V_2 , V_32 , V_33 ) ;
F_9 ( V_2 , V_34 , 0x0381808d ) ;
F_9 ( V_2 , V_35 , 0xf0ffff83 ) ;
F_9 ( V_2 , V_35 , 0xf0ffff82 ) ;
F_9 ( V_2 , V_35 , 0xf0ffff83 ) ;
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_36 ;
T_2 V_37 ;
int V_38 , V_29 = 0 ;
V_36 = F_11 ( V_2 , V_39 ) ;
V_36 |= V_40 ;
F_12 ( V_2 , V_39 , V_36 ) ;
V_36 = F_11 ( V_2 , 0x0067 ) ;
V_36 &= ~ F_13 ( 4 ) ;
F_12 ( V_2 , 0x0067 , V_36 ) ;
F_14 ( 1 ) ;
V_36 = F_11 ( V_2 , V_41 ) ;
V_36 &= ~ V_42 ;
F_12 ( V_2 , V_41 , V_36 ) ;
V_36 = F_11 ( V_2 , V_43 + 1 ) ;
V_36 &= ~ F_13 ( 2 ) ;
F_12 ( V_2 , V_43 + 1 , V_36 ) ;
for ( V_38 = V_44 ; V_38 ; V_38 -- ) {
V_37 = F_15 ( V_2 , V_43 ) ;
if ( V_37 & F_13 ( 17 ) )
break;
F_16 ( 10 ) ;
}
if ( ! V_38 ) {
V_29 = - V_45 ;
goto exit;
}
V_36 = F_11 ( V_2 , V_43 + 2 ) ;
V_36 |= F_13 ( 0 ) ;
F_12 ( V_2 , V_43 + 2 , V_36 ) ;
V_36 = F_11 ( V_2 , V_43 + 1 ) ;
V_36 &= ~ F_13 ( 7 ) ;
F_12 ( V_2 , V_43 + 1 , V_36 ) ;
V_36 = F_11 ( V_2 , V_43 + 1 ) ;
V_36 &= ~ ( F_13 ( 3 ) | F_13 ( 4 ) ) ;
F_12 ( V_2 , V_43 + 1 , V_36 ) ;
V_37 = F_15 ( V_2 , V_43 ) ;
V_37 |= V_46 ;
F_9 ( V_2 , V_43 , V_37 ) ;
for ( V_38 = V_44 ; V_38 ; V_38 -- ) {
V_37 = F_15 ( V_2 , V_43 ) ;
if ( ( V_37 & V_46 ) == 0 ) {
V_29 = 0 ;
break;
}
F_16 ( 10 ) ;
}
if ( ! V_38 ) {
V_29 = - V_45 ;
goto exit;
}
V_36 = F_11 ( V_2 , V_47 ) ;
V_36 |= V_48 ;
V_36 &= ~ V_48 ;
F_12 ( V_2 , V_47 , V_36 ) ;
exit:
return V_29 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_36 ;
T_3 V_49 ;
T_2 V_37 ;
int V_29 ;
F_12 ( V_2 , V_50 , 0x0 ) ;
F_18 ( V_2 ) ;
V_29 = F_10 ( V_2 ) ;
if ( V_29 )
goto exit;
V_36 = F_11 ( V_2 , V_43 + 2 ) ;
V_36 |= F_13 ( 3 ) ;
F_12 ( V_2 , V_43 + 2 , V_36 ) ;
V_49 = F_19 ( V_2 , V_51 ) ;
V_49 |= ( V_52 | V_53 |
V_54 | V_55 |
V_56 | V_57 |
V_58 | V_59 |
V_60 | V_61 ) ;
F_20 ( V_2 , V_51 , V_49 ) ;
V_37 = F_15 ( V_2 , V_62 ) ;
V_37 &= ~ ( F_13 ( 28 ) | F_13 ( 29 ) | F_13 ( 30 ) ) ;
V_37 |= ( 0x06 << 28 ) ;
F_9 ( V_2 , V_62 , V_37 ) ;
exit:
return V_29 ;
}
