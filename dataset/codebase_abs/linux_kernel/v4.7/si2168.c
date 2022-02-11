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
int V_7 ;
struct V_3 V_4 ;
* V_19 = 0 ;
if ( ! V_6 -> V_24 ) {
V_7 = - V_25 ;
goto V_26;
}
switch ( V_22 -> V_27 ) {
case V_28 :
memcpy ( V_4 . args , L_3 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 13 ;
break;
case V_29 :
memcpy ( V_4 . args , L_4 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 9 ;
break;
case V_30 :
memcpy ( V_4 . args , L_5 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 14 ;
break;
default:
V_7 = - V_31 ;
goto V_26;
}
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
switch ( ( V_4 . args [ 2 ] >> 1 ) & 0x03 ) {
case 0x01 :
* V_19 = V_32 | V_33 ;
break;
case 0x03 :
* V_19 = V_32 | V_33 | V_34 |
V_35 | V_36 ;
break;
}
V_6 -> V_18 = * V_19 ;
if ( * V_19 & V_36 ) {
V_22 -> V_37 . V_38 = 1 ;
V_22 -> V_37 . V_39 [ 0 ] . V_40 = V_41 ;
V_22 -> V_37 . V_39 [ 0 ] . V_42 = V_4 . args [ 3 ] * 1000 / 4 ;
} else {
V_22 -> V_37 . V_38 = 1 ;
V_22 -> V_37 . V_39 [ 0 ] . V_40 = V_43 ;
}
F_9 ( & V_2 -> V_6 , L_6 ,
* V_19 , V_4 . V_13 , V_4 . args ) ;
return 0 ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_17 -> V_23 ;
int V_7 ;
struct V_3 V_4 ;
T_1 V_44 , V_27 ;
F_9 ( & V_2 -> V_6 ,
L_7 ,
V_22 -> V_27 , V_22 -> V_45 , V_22 -> V_46 ,
V_22 -> V_47 , V_22 -> V_48 , V_22 -> V_49 ,
V_22 -> V_50 ) ;
if ( ! V_6 -> V_24 ) {
V_7 = - V_25 ;
goto V_26;
}
switch ( V_22 -> V_27 ) {
case V_28 :
V_27 = 0x20 ;
break;
case V_29 :
V_27 = 0x30 ;
break;
case V_30 :
V_27 = 0x70 ;
break;
default:
V_7 = - V_31 ;
goto V_26;
}
if ( V_22 -> V_47 == 0 ) {
V_7 = - V_31 ;
goto V_26;
} else if ( V_22 -> V_47 <= 2000000 )
V_44 = 0x02 ;
else if ( V_22 -> V_47 <= 5000000 )
V_44 = 0x05 ;
else if ( V_22 -> V_47 <= 6000000 )
V_44 = 0x06 ;
else if ( V_22 -> V_47 <= 7000000 )
V_44 = 0x07 ;
else if ( V_22 -> V_47 <= 8000000 )
V_44 = 0x08 ;
else if ( V_22 -> V_47 <= 9000000 )
V_44 = 0x09 ;
else if ( V_22 -> V_47 <= 10000000 )
V_44 = 0x0a ;
else
V_44 = 0x0f ;
if ( V_17 -> V_51 . V_52 . V_53 ) {
V_7 = V_17 -> V_51 . V_52 . V_53 ( V_17 ) ;
if ( V_7 )
goto V_26;
}
memcpy ( V_4 . args , L_8 , 5 ) ;
V_4 . V_10 = 5 ;
V_4 . V_13 = 5 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
if ( V_22 -> V_27 == V_28 )
memcpy ( V_4 . args , L_9 , 6 ) ;
else if ( V_22 -> V_27 == V_29 )
memcpy ( V_4 . args , L_10 , 6 ) ;
else if ( V_22 -> V_27 == V_30 )
memcpy ( V_4 . args , L_11 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
if ( V_22 -> V_27 == V_30 ) {
V_4 . args [ 0 ] = 0x52 ;
V_4 . args [ 1 ] = V_22 -> V_50 & 0xff ;
V_4 . args [ 2 ] = V_22 -> V_50 == V_54 ? 0 : 1 ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
}
memcpy ( V_4 . args , L_12 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 12 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_13 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 3 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_14 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_16 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_17 , 6 ) ;
V_4 . args [ 4 ] = V_27 | V_44 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
if ( V_22 -> V_27 == V_29 ) {
memcpy ( V_4 . args , L_18 , 4 ) ;
V_4 . args [ 4 ] = ( ( V_22 -> V_48 / 1000 ) >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_22 -> V_48 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
}
memcpy ( V_4 . args , L_19 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . args [ 5 ] |= V_6 -> V_55 ? 0x00 : 0x10 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . args [ 5 ] |= V_6 -> V_55 ? 0x00 : 0x10 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_22 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_24 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
V_6 -> V_27 = V_22 -> V_27 ;
return 0 ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_38 , V_56 ;
const struct V_57 * V_58 ;
const char * V_59 ;
struct V_3 V_4 ;
unsigned int V_60 ;
F_9 ( & V_2 -> V_6 , L_25 ) ;
memcpy ( V_4 . args , L_26 , 13 ) ;
V_4 . V_10 = 13 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
if ( V_6 -> V_61 ) {
memcpy ( V_4 . args , L_27 , 8 ) ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_24 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
goto V_62;
}
memcpy ( V_4 . args , L_28 , 8 ) ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_29 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 13 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
V_60 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_15 ('A' << 24 | 68 << 16 | '2' << 8 | '0' << 0)
#define F_16 ('A' << 24 | 68 << 16 | '3' << 8 | '0' << 0)
#define F_17 ('B' << 24 | 68 << 16 | '4' << 8 | '0' << 0)
switch ( V_60 ) {
case F_15 :
V_59 = V_63 ;
break;
case F_16 :
V_59 = V_64 ;
break;
case F_17 :
V_59 = V_65 ;
break;
default:
F_18 ( & V_2 -> V_6 , L_30 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = - V_31 ;
goto V_26;
}
F_19 ( & V_2 -> V_6 , L_31 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] , V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = F_20 ( & V_58 , V_59 , & V_2 -> V_6 ) ;
if ( V_7 ) {
if ( V_60 == F_17 ) {
V_59 = V_66 ;
V_7 = F_20 ( & V_58 , V_59 , & V_2 -> V_6 ) ;
}
if ( V_7 == 0 ) {
F_21 ( & V_2 -> V_6 ,
L_32 ,
V_65 ) ;
} else {
F_18 ( & V_2 -> V_6 ,
L_33 ,
V_59 ) ;
goto V_67;
}
}
F_19 ( & V_2 -> V_6 , L_34 ,
V_59 ) ;
if ( ( V_58 -> V_68 % 17 == 0 ) && ( V_58 -> V_69 [ 0 ] > 5 ) ) {
for ( V_56 = V_58 -> V_68 ; V_56 > 0 ; V_56 -= 17 ) {
V_38 = V_58 -> V_69 [ V_58 -> V_68 - V_56 ] ;
if ( V_38 > V_70 ) {
V_7 = - V_31 ;
break;
}
memcpy ( V_4 . args , & V_58 -> V_69 [ ( V_58 -> V_68 - V_56 ) + 1 ] , V_38 ) ;
V_4 . V_10 = V_38 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
break;
}
} else if ( V_58 -> V_68 % 8 == 0 ) {
for ( V_56 = V_58 -> V_68 ; V_56 > 0 ; V_56 -= 8 ) {
V_38 = 8 ;
memcpy ( V_4 . args , & V_58 -> V_69 [ V_58 -> V_68 - V_56 ] , V_38 ) ;
V_4 . V_10 = V_38 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
break;
}
} else {
V_7 = - V_31 ;
}
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_35 , V_7 ) ;
goto V_67;
}
F_22 ( V_58 ) ;
memcpy ( V_4 . args , L_36 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
memcpy ( V_4 . args , L_37 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 10 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
F_19 ( & V_2 -> V_6 , L_38 ,
V_4 . args [ 6 ] , V_4 . args [ 7 ] , V_4 . args [ 8 ] ) ;
memcpy ( V_4 . args , L_39 , 6 ) ;
V_4 . args [ 4 ] |= V_6 -> V_71 ;
if ( V_6 -> V_72 )
V_4 . args [ 4 ] |= 0x40 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
V_6 -> V_61 = true ;
V_62:
V_6 -> V_24 = true ;
return 0 ;
V_67:
F_22 ( V_58 ) ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_23 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_25 ) ;
V_6 -> V_24 = false ;
memcpy ( V_4 . args , L_40 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_73 * V_74 )
{
V_74 -> V_75 = 900 ;
return 0 ;
}
static int F_25 ( struct V_76 * V_77 , T_2 V_78 )
{
struct V_1 * V_2 = F_26 ( V_77 ) ;
int V_7 ;
struct V_3 V_4 ;
memcpy ( V_4 . args , L_41 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_27 ( struct V_76 * V_77 , T_2 V_78 )
{
struct V_1 * V_2 = F_26 ( V_77 ) ;
int V_7 ;
struct V_3 V_4 ;
memcpy ( V_4 . args , L_42 , 3 ) ;
V_4 . V_10 = 3 ;
V_4 . V_13 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_79 * V_80 )
{
struct V_81 * V_82 = V_2 -> V_6 . V_83 ;
struct V_5 * V_6 ;
int V_7 ;
F_9 ( & V_2 -> V_6 , L_25 ) ;
V_6 = F_29 ( sizeof( * V_6 ) , V_84 ) ;
if ( ! V_6 ) {
V_7 = - V_85 ;
F_18 ( & V_2 -> V_6 , L_43 ) ;
goto V_26;
}
F_30 ( & V_6 -> V_9 ) ;
V_6 -> V_77 = F_31 ( V_2 -> V_86 , & V_2 -> V_6 ,
1 , 0 , V_87 ,
F_25 , F_27 ) ;
if ( ! V_6 -> V_77 ) {
V_7 = - V_85 ;
goto V_88;
}
V_6 -> V_77 -> V_89 = V_2 ;
V_7 = F_32 ( V_6 -> V_77 , 0 , 0 , 0 ) ;
if ( V_7 )
goto V_88;
memcpy ( & V_6 -> V_17 . V_51 , & V_90 , sizeof( struct V_91 ) ) ;
V_6 -> V_17 . V_20 = V_2 ;
* V_82 -> V_92 = V_6 -> V_77 -> V_86 [ 0 ] ;
* V_82 -> V_17 = & V_6 -> V_17 ;
V_6 -> V_71 = V_82 -> V_71 ;
V_6 -> V_55 = V_82 -> V_55 ;
V_6 -> V_72 = V_82 -> V_72 ;
V_6 -> V_61 = false ;
F_33 ( V_2 , V_6 ) ;
F_19 ( & V_2 -> V_6 , L_44 ) ;
return 0 ;
V_88:
F_34 ( V_6 ) ;
V_26:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_9 ( & V_2 -> V_6 , L_25 ) ;
F_36 ( V_6 -> V_77 ) ;
V_6 -> V_17 . V_51 . V_93 = NULL ;
V_6 -> V_17 . V_20 = NULL ;
F_34 ( V_6 ) ;
return 0 ;
}
