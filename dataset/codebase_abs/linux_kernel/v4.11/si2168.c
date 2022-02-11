static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
unsigned long V_8 ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_4 -> V_10 ) {
V_7 = F_4 ( V_2 , V_4 -> args , V_4 -> V_10 ) ;
if ( V_7 < 0 ) {
goto V_11;
} else if ( V_7 != V_4 -> V_10 ) {
V_7 = - V_12 ;
goto V_11;
}
}
if ( V_4 -> V_13 ) {
#define F_5 70
V_8 = V_14 + F_6 ( F_5 ) ;
while ( ! F_7 ( V_14 , V_8 ) ) {
V_7 = F_8 ( V_2 , V_4 -> args , V_4 -> V_13 ) ;
if ( V_7 < 0 ) {
goto V_11;
} else if ( V_7 != V_4 -> V_13 ) {
V_7 = - V_12 ;
goto V_11;
}
if ( ( V_4 -> args [ 0 ] >> 7 ) & 0x01 )
break;
}
F_9 ( & V_2 -> V_6 , L_1 ,
F_10 ( V_14 ) -
( F_10 ( V_8 ) - F_5 ) ) ;
if ( ( V_4 -> args [ 0 ] >> 6 ) & 0x01 ) {
V_7 = - V_12 ;
goto V_11;
}
if ( ! ( ( V_4 -> args [ 0 ] >> 7 ) & 0x01 ) ) {
V_7 = - V_15 ;
goto V_11;
}
}
F_11 ( & V_6 -> V_9 ) ;
return 0 ;
V_11:
F_11 ( & V_6 -> V_9 ) ;
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_16 * V_17 , enum V_18 * V_19 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_17 -> V_23 ;
int V_7 , V_24 ;
unsigned int V_25 , V_26 , V_27 ;
struct V_3 V_4 ;
* V_19 = 0 ;
if ( ! V_6 -> V_28 ) {
V_7 = - V_29 ;
goto V_30;
}
switch ( V_22 -> V_31 ) {
case V_32 :
memcpy ( V_4 . args , L_3 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 13 ;
break;
case V_33 :
memcpy ( V_4 . args , L_4 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 9 ;
break;
case V_34 :
memcpy ( V_4 . args , L_5 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 14 ;
break;
default:
V_7 = - V_35 ;
goto V_30;
}
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
switch ( ( V_4 . args [ 2 ] >> 1 ) & 0x03 ) {
case 0x01 :
* V_19 = V_36 | V_37 ;
break;
case 0x03 :
* V_19 = V_36 | V_37 | V_38 |
V_39 | V_40 ;
break;
}
V_6 -> V_18 = * V_19 ;
if ( * V_19 & V_40 ) {
V_22 -> V_41 . V_42 = 1 ;
V_22 -> V_41 . V_43 [ 0 ] . V_44 = V_45 ;
V_22 -> V_41 . V_43 [ 0 ] . V_46 = V_4 . args [ 3 ] * 1000 / 4 ;
} else {
V_22 -> V_41 . V_42 = 1 ;
V_22 -> V_41 . V_43 [ 0 ] . V_44 = V_47 ;
}
F_9 ( & V_2 -> V_6 , L_6 ,
* V_19 , V_4 . V_13 , V_4 . args ) ;
if ( * V_19 & V_38 ) {
memcpy ( V_4 . args , L_7 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_25 = F_13 ( 8 - V_4 . args [ 1 ] , 0 , 8 ) ;
for ( V_24 = 0 , V_26 = 1 ; V_24 < V_25 ; V_24 ++ )
V_26 = V_26 * 10 ;
V_26 = V_4 . args [ 2 ] * V_26 ;
V_27 = 100000000 ;
F_9 ( & V_2 -> V_6 ,
L_8 ,
V_26 , V_27 , V_4 . args [ 2 ] , V_4 . args [ 1 ] ) ;
V_22 -> V_48 . V_43 [ 0 ] . V_44 = V_49 ;
V_22 -> V_48 . V_43 [ 0 ] . V_50 += V_26 ;
V_22 -> V_51 . V_43 [ 0 ] . V_44 = V_49 ;
V_22 -> V_51 . V_43 [ 0 ] . V_50 += V_27 ;
} else {
V_22 -> V_48 . V_43 [ 0 ] . V_44 = V_47 ;
V_22 -> V_51 . V_43 [ 0 ] . V_44 = V_47 ;
}
if ( * V_19 & V_39 ) {
memcpy ( V_4 . args , L_9 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_26 = V_4 . args [ 2 ] << 8 | V_4 . args [ 1 ] << 0 ;
F_9 ( & V_2 -> V_6 , L_10 , V_26 ) ;
if ( V_26 == 0xffff )
V_26 = 0 ;
V_22 -> V_52 . V_43 [ 0 ] . V_44 = V_49 ;
V_22 -> V_52 . V_43 [ 0 ] . V_50 += V_26 ;
} else {
V_22 -> V_52 . V_43 [ 0 ] . V_44 = V_47 ;
}
return 0 ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_17 -> V_23 ;
int V_7 ;
struct V_3 V_4 ;
T_1 V_53 , V_31 ;
F_9 ( & V_2 -> V_6 ,
L_11 ,
V_22 -> V_31 , V_22 -> V_54 , V_22 -> V_55 ,
V_22 -> V_56 , V_22 -> V_57 , V_22 -> V_58 ,
V_22 -> V_59 ) ;
if ( ! V_6 -> V_28 ) {
V_7 = - V_29 ;
goto V_30;
}
switch ( V_22 -> V_31 ) {
case V_32 :
V_31 = 0x20 ;
break;
case V_33 :
V_31 = 0x30 ;
break;
case V_34 :
V_31 = 0x70 ;
break;
default:
V_7 = - V_35 ;
goto V_30;
}
if ( V_22 -> V_56 == 0 ) {
V_7 = - V_35 ;
goto V_30;
} else if ( V_22 -> V_56 <= 2000000 )
V_53 = 0x02 ;
else if ( V_22 -> V_56 <= 5000000 )
V_53 = 0x05 ;
else if ( V_22 -> V_56 <= 6000000 )
V_53 = 0x06 ;
else if ( V_22 -> V_56 <= 7000000 )
V_53 = 0x07 ;
else if ( V_22 -> V_56 <= 8000000 )
V_53 = 0x08 ;
else if ( V_22 -> V_56 <= 9000000 )
V_53 = 0x09 ;
else if ( V_22 -> V_56 <= 10000000 )
V_53 = 0x0a ;
else
V_53 = 0x0f ;
if ( V_17 -> V_60 . V_61 . V_62 ) {
V_7 = V_17 -> V_60 . V_61 . V_62 ( V_17 ) ;
if ( V_7 )
goto V_30;
}
memcpy ( V_4 . args , L_12 , 5 ) ;
V_4 . V_10 = 5 ;
V_4 . V_13 = 5 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
if ( V_22 -> V_31 == V_32 )
memcpy ( V_4 . args , L_13 , 6 ) ;
else if ( V_22 -> V_31 == V_33 )
memcpy ( V_4 . args , L_14 , 6 ) ;
else if ( V_22 -> V_31 == V_34 )
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
if ( V_22 -> V_31 == V_34 ) {
V_4 . args [ 0 ] = 0x52 ;
V_4 . args [ 1 ] = V_22 -> V_59 & 0xff ;
V_4 . args [ 2 ] = V_22 -> V_59 == V_63 ? 0 : 1 ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
}
memcpy ( V_4 . args , L_16 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 12 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_17 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_18 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_19 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . args [ 4 ] = V_31 | V_53 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
if ( V_22 -> V_31 == V_33 ) {
memcpy ( V_4 . args , L_22 , 4 ) ;
V_4 . args [ 4 ] = ( ( V_22 -> V_57 / 1000 ) >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_22 -> V_57 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
}
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_24 , 6 ) ;
V_4 . args [ 5 ] |= V_6 -> V_64 ? 0x00 : 0x10 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_25 , 6 ) ;
V_4 . args [ 5 ] |= V_6 -> V_64 ? 0x00 : 0x10 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_26 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_27 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_28 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_6 -> V_31 = V_22 -> V_31 ;
return 0 ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_17 -> V_23 ;
int V_7 , V_42 , V_65 ;
const struct V_66 * V_67 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_29 ) ;
memcpy ( V_4 . args , L_30 , 13 ) ;
V_4 . V_10 = 13 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
if ( V_6 -> V_68 ) {
memcpy ( V_4 . args , L_31 , 8 ) ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_28 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
goto V_68;
}
memcpy ( V_4 . args , L_32 , 8 ) ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_7 = F_16 ( & V_67 , V_6 -> V_69 , & V_2 -> V_6 ) ;
if ( V_7 ) {
if ( V_6 -> V_70 == V_71 ) {
V_6 -> V_69 = V_72 ;
V_7 = F_16 ( & V_67 , V_6 -> V_69 ,
& V_2 -> V_6 ) ;
}
if ( V_7 == 0 ) {
F_17 ( & V_2 -> V_6 ,
L_33 ,
V_73 ) ;
} else {
F_18 ( & V_2 -> V_6 ,
L_34 ,
V_6 -> V_69 ) ;
goto V_74;
}
}
F_19 ( & V_2 -> V_6 , L_35 ,
V_6 -> V_69 ) ;
if ( ( V_67 -> V_75 % 17 == 0 ) && ( V_67 -> V_76 [ 0 ] > 5 ) ) {
for ( V_65 = V_67 -> V_75 ; V_65 > 0 ; V_65 -= 17 ) {
V_42 = V_67 -> V_76 [ V_67 -> V_75 - V_65 ] ;
if ( V_42 > V_77 ) {
V_7 = - V_35 ;
break;
}
memcpy ( V_4 . args , & V_67 -> V_76 [ ( V_67 -> V_75 - V_65 ) + 1 ] , V_42 ) ;
V_4 . V_10 = V_42 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
break;
}
} else if ( V_67 -> V_75 % 8 == 0 ) {
for ( V_65 = V_67 -> V_75 ; V_65 > 0 ; V_65 -= 8 ) {
V_42 = 8 ;
memcpy ( V_4 . args , & V_67 -> V_76 [ V_67 -> V_75 - V_65 ] , V_42 ) ;
V_4 . V_10 = V_42 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
break;
}
} else {
V_7 = - V_35 ;
}
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_36 , V_7 ) ;
goto V_74;
}
F_20 ( V_67 ) ;
memcpy ( V_4 . args , L_37 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
memcpy ( V_4 . args , L_38 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 10 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_6 -> V_78 = ( V_4 . args [ 9 ] + '@' ) << 24 | ( V_4 . args [ 6 ] - '0' ) << 16 |
( V_4 . args [ 7 ] - '0' ) << 8 | ( V_4 . args [ 8 ] ) << 0 ;
F_19 ( & V_2 -> V_6 , L_39 ,
V_6 -> V_78 >> 24 & 0xff , V_6 -> V_78 >> 16 & 0xff ,
V_6 -> V_78 >> 8 & 0xff , V_6 -> V_78 >> 0 & 0xff ) ;
memcpy ( V_4 . args , L_40 , 6 ) ;
V_4 . args [ 4 ] |= V_6 -> V_79 ;
if ( V_6 -> V_80 )
V_4 . args [ 4 ] |= 0x40 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
V_6 -> V_68 = true ;
V_68:
V_22 -> V_41 . V_42 = 1 ;
V_22 -> V_41 . V_43 [ 0 ] . V_44 = V_47 ;
V_22 -> V_48 . V_42 = 1 ;
V_22 -> V_48 . V_43 [ 0 ] . V_44 = V_47 ;
V_22 -> V_51 . V_42 = 1 ;
V_22 -> V_51 . V_43 [ 0 ] . V_44 = V_47 ;
V_22 -> V_52 . V_42 = 1 ;
V_22 -> V_52 . V_43 [ 0 ] . V_44 = V_47 ;
V_6 -> V_28 = true ;
return 0 ;
V_74:
F_20 ( V_67 ) ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_29 ) ;
V_6 -> V_28 = false ;
if ( V_6 -> V_78 > ( 'B' << 24 | 4 << 16 | 0 << 8 | 11 << 0 ) )
V_6 -> V_68 = false ;
memcpy ( V_4 . args , L_41 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
return 0 ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_81 * V_82 )
{
V_82 -> V_83 = 900 ;
return 0 ;
}
static int F_23 ( struct V_84 * V_85 , T_2 V_86 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
int V_7 ;
struct V_3 V_4 ;
memcpy ( V_4 . args , L_42 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
return 0 ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_25 ( struct V_84 * V_85 , T_2 V_86 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
int V_7 ;
struct V_3 V_4 ;
memcpy ( V_4 . args , L_43 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_30;
return 0 ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_87 * V_88 )
{
struct V_89 * V_90 = V_2 -> V_6 . V_91 ;
struct V_5 * V_6 ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_29 ) ;
V_6 = F_27 ( sizeof( * V_6 ) , V_92 ) ;
if ( ! V_6 ) {
V_7 = - V_93 ;
F_18 ( & V_2 -> V_6 , L_44 ) ;
goto V_30;
}
F_28 ( V_2 , V_6 ) ;
F_29 ( & V_6 -> V_9 ) ;
memcpy ( V_4 . args , L_30 , 13 ) ;
V_4 . V_10 = 13 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_94;
memcpy ( V_4 . args , L_32 , 8 ) ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_94;
memcpy ( V_4 . args , L_45 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 13 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_94;
V_6 -> V_70 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 |
V_4 . args [ 3 ] << 8 | V_4 . args [ 4 ] << 0 ;
switch ( V_6 -> V_70 ) {
case V_95 :
V_6 -> V_69 = V_96 ;
break;
case V_97 :
V_6 -> V_69 = V_98 ;
break;
case V_71 :
V_6 -> V_69 = V_73 ;
break;
default:
F_9 ( & V_2 -> V_6 , L_46 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] , V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = - V_99 ;
goto V_94;
}
V_6 -> V_78 = ( V_4 . args [ 1 ] ) << 24 | ( V_4 . args [ 3 ] - '0' ) << 16 |
( V_4 . args [ 4 ] - '0' ) << 8 | ( V_4 . args [ 5 ] ) << 0 ;
V_6 -> V_85 = F_30 ( V_2 -> V_100 , & V_2 -> V_6 ,
1 , 0 , V_101 ,
F_23 , F_25 ) ;
if ( ! V_6 -> V_85 ) {
V_7 = - V_93 ;
goto V_94;
}
V_6 -> V_85 -> V_102 = V_2 ;
V_7 = F_31 ( V_6 -> V_85 , 0 , 0 , 0 ) ;
if ( V_7 )
goto V_94;
memcpy ( & V_6 -> V_17 . V_60 , & V_103 , sizeof( struct V_104 ) ) ;
V_6 -> V_17 . V_20 = V_2 ;
* V_90 -> V_105 = V_6 -> V_85 -> V_100 [ 0 ] ;
* V_90 -> V_17 = & V_6 -> V_17 ;
V_6 -> V_79 = V_90 -> V_79 ;
V_6 -> V_64 = V_90 -> V_64 ;
V_6 -> V_80 = V_90 -> V_80 ;
F_19 ( & V_2 -> V_6 , L_47 ,
V_6 -> V_78 >> 24 & 0xff , V_6 -> V_78 >> 16 & 0xff ,
V_6 -> V_78 >> 8 & 0xff ) ;
F_19 ( & V_2 -> V_6 , L_39 ,
V_6 -> V_78 >> 24 & 0xff , V_6 -> V_78 >> 16 & 0xff ,
V_6 -> V_78 >> 8 & 0xff , V_6 -> V_78 >> 0 & 0xff ) ;
return 0 ;
V_94:
F_32 ( V_6 ) ;
V_30:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_9 ( & V_2 -> V_6 , L_29 ) ;
F_34 ( V_6 -> V_85 ) ;
V_6 -> V_17 . V_60 . V_106 = NULL ;
V_6 -> V_17 . V_20 = NULL ;
F_32 ( V_6 ) ;
return 0 ;
}
