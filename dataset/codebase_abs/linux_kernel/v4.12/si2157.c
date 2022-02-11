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
#define F_5 80
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
static int F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_17 -> V_21 ;
int V_7 , V_22 , V_23 ;
struct V_3 V_4 ;
const struct V_24 * V_25 ;
const char * V_26 ;
unsigned int V_27 , V_28 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
memcpy ( V_4 . args , L_4 , 4 ) ;
V_4 . V_10 = 4 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_27 = V_4 . args [ 2 ] << 0 | V_4 . args [ 3 ] << 8 ;
F_9 ( & V_2 -> V_6 , L_5 , V_27 ) ;
if ( V_27 == V_6 -> V_30 / 1000 )
goto V_31;
if ( V_6 -> V_32 == V_33 ) {
memcpy ( V_4 . args , L_6 , 9 ) ;
V_4 . V_10 = 9 ;
} else if ( V_6 -> V_32 == V_34 ) {
memcpy ( V_4 . args , L_7 , 10 ) ;
V_4 . V_10 = 10 ;
} else {
memcpy ( V_4 . args , L_8 , 15 ) ;
V_4 . V_10 = 15 ;
}
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_6 -> V_32 == V_34 ) {
memcpy ( V_4 . args , L_9 , 7 ) ;
V_4 . V_10 = 7 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
}
memcpy ( V_4 . args , L_10 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 13 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_28 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_13 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define F_14 ('A' << 24 | 48 << 16 | '2' << 8 | '0' << 0)
#define F_15 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
#define F_16 ('A' << 24 | 47 << 16 | '3' << 8 | '0' << 0)
#define F_17 ('A' << 24 | 46 << 16 | '1' << 8 | '0' << 0)
#define F_18 ('A' << 24 | 41 << 16 | '1' << 8 | '0' << 0)
switch ( V_28 ) {
case F_13 :
case F_14 :
V_26 = V_35 ;
break;
case F_18 :
V_26 = V_36 ;
break;
case F_15 :
case F_16 :
case F_17 :
V_26 = NULL ;
break;
default:
F_19 ( & V_2 -> V_6 , L_11 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = - V_37 ;
goto V_29;
}
F_20 ( & V_2 -> V_6 , L_12 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] , V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
if ( V_26 == NULL )
goto V_38;
V_7 = F_21 ( & V_25 , V_26 , & V_2 -> V_6 ) ;
if ( V_7 ) {
F_19 ( & V_2 -> V_6 , L_13 ,
V_26 ) ;
goto V_29;
}
if ( V_25 -> V_39 % 17 != 0 ) {
F_19 ( & V_2 -> V_6 , L_14 ,
V_26 ) ;
V_7 = - V_37 ;
goto V_40;
}
F_20 ( & V_2 -> V_6 , L_15 ,
V_26 ) ;
for ( V_23 = V_25 -> V_39 ; V_23 > 0 ; V_23 -= 17 ) {
V_22 = V_25 -> V_41 [ V_25 -> V_39 - V_23 ] ;
if ( V_22 > V_42 ) {
F_19 ( & V_2 -> V_6 , L_16 ) ;
V_7 = - V_37 ;
goto V_40;
}
memcpy ( V_4 . args , & V_25 -> V_41 [ ( V_25 -> V_39 - V_23 ) + 1 ] , V_22 ) ;
V_4 . V_10 = V_22 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_19 ( & V_2 -> V_6 , L_17 ,
V_7 ) ;
goto V_40;
}
}
F_22 ( V_25 ) ;
V_38:
memcpy ( V_4 . args , L_18 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_19 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 10 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
F_20 ( & V_2 -> V_6 , L_20 ,
V_4 . args [ 6 ] , V_4 . args [ 7 ] , V_4 . args [ 8 ] ) ;
V_31:
V_20 -> V_43 . V_22 = 1 ;
V_20 -> V_43 . V_44 [ 0 ] . V_45 = V_46 ;
F_23 ( & V_6 -> V_47 , F_6 ( 1000 ) ) ;
V_6 -> V_48 = true ;
return 0 ;
V_40:
F_22 ( V_25 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_24 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
V_6 -> V_48 = false ;
F_25 ( & V_6 -> V_47 ) ;
memcpy ( V_4 . args , L_21 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
return 0 ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_26 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_17 -> V_21 ;
int V_7 ;
struct V_3 V_4 ;
T_1 V_49 , V_50 ;
T_2 V_30 = 5000000 ;
F_9 ( & V_2 -> V_6 ,
L_22 ,
V_20 -> V_50 , V_20 -> V_51 , V_20 -> V_52 ) ;
if ( ! V_6 -> V_48 ) {
V_7 = - V_53 ;
goto V_29;
}
if ( V_20 -> V_52 <= 6000000 )
V_49 = 0x06 ;
else if ( V_20 -> V_52 <= 7000000 )
V_49 = 0x07 ;
else if ( V_20 -> V_52 <= 8000000 )
V_49 = 0x08 ;
else
V_49 = 0x0f ;
switch ( V_20 -> V_50 ) {
case V_54 :
V_50 = 0x00 ;
V_30 = 3250000 ;
break;
case V_55 :
V_50 = 0x10 ;
V_30 = 4000000 ;
break;
case V_56 :
case V_57 :
V_50 = 0x20 ;
break;
case V_58 :
V_50 = 0x30 ;
break;
default:
V_7 = - V_37 ;
goto V_29;
}
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . args [ 4 ] = V_50 | V_49 ;
if ( V_6 -> V_59 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_6 -> V_32 == V_33 )
memcpy ( V_4 . args , L_24 , 6 ) ;
else
memcpy ( V_4 . args , L_25 , 6 ) ;
V_4 . args [ 4 ] = V_6 -> V_60 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_30 != V_6 -> V_30 ) {
memcpy ( V_4 . args , L_26 , 4 ) ;
V_4 . args [ 4 ] = ( V_30 / 1000 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_30 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_6 -> V_30 = V_30 ;
}
memcpy ( V_4 . args , L_27 , 8 ) ;
V_4 . args [ 4 ] = ( V_20 -> V_51 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_20 -> V_51 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_20 -> V_51 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_20 -> V_51 >> 24 ) & 0xff ;
V_4 . V_10 = 8 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
return 0 ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_27 ( struct V_16 * V_17 , T_2 * V_51 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_51 = V_6 -> V_30 ;
return 0 ;
}
static void F_28 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = F_29 ( V_62 , struct V_5 , V_47 . V_62 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_21 ;
struct V_3 V_4 ;
int V_7 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
memcpy ( V_4 . args , L_28 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 12 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_20 -> V_43 . V_44 [ 0 ] . V_45 = V_63 ;
V_20 -> V_43 . V_44 [ 0 ] . V_64 = ( V_65 ) V_4 . args [ 3 ] * 1000 ;
F_23 ( & V_6 -> V_47 , F_6 ( 2000 ) ) ;
return;
V_29:
V_20 -> V_43 . V_44 [ 0 ] . V_45 = V_46 ;
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = V_2 -> V_6 . V_70 ;
struct V_16 * V_17 = V_69 -> V_17 ;
struct V_5 * V_6 ;
struct V_3 V_4 ;
int V_7 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_71 ) ;
if ( ! V_6 ) {
V_7 = - V_72 ;
F_19 ( & V_2 -> V_6 , L_29 ) ;
goto V_29;
}
F_32 ( V_2 , V_6 ) ;
V_6 -> V_17 = V_69 -> V_17 ;
V_6 -> V_59 = V_69 -> V_59 ;
V_6 -> V_60 = V_69 -> V_60 ;
V_6 -> V_32 = ( T_1 ) V_67 -> V_73 ;
V_6 -> V_30 = 5000000 ;
F_33 ( & V_6 -> V_9 ) ;
F_34 ( & V_6 -> V_47 , F_28 ) ;
V_4 . V_10 = 0 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_74;
memcpy ( & V_17 -> V_75 . V_76 , & V_77 , sizeof( struct V_78 ) ) ;
V_17 -> V_18 = V_2 ;
#ifdef F_35
if ( V_69 -> V_79 ) {
V_6 -> V_79 = V_69 -> V_79 ;
V_6 -> V_80 . V_81 = V_82 ;
V_6 -> V_80 . V_83 = V_84 ;
V_6 -> V_85 [ V_86 ] . V_87 = V_88 ;
V_6 -> V_85 [ V_89 ] . V_87 = V_90 ;
V_6 -> V_85 [ V_91 ] . V_87 = V_90 ;
V_7 = F_36 ( & V_6 -> V_80 , V_92 ,
& V_6 -> V_85 [ 0 ] ) ;
if ( V_7 )
goto V_74;
V_7 = F_37 ( V_69 -> V_79 , & V_6 -> V_80 ) ;
if ( V_7 ) {
F_38 ( & V_6 -> V_80 ) ;
goto V_74;
}
}
#endif
F_20 ( & V_2 -> V_6 , L_30 ,
V_6 -> V_32 == V_34 ? L_31 :
V_6 -> V_32 == V_33 ?
L_32 : L_33 ) ;
return 0 ;
V_74:
F_39 ( V_6 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
F_25 ( & V_6 -> V_47 ) ;
#ifdef F_41
if ( V_6 -> V_79 )
F_42 ( & V_6 -> V_80 ) ;
#endif
memset ( & V_17 -> V_75 . V_76 , 0 , sizeof( struct V_78 ) ) ;
V_17 -> V_18 = NULL ;
F_39 ( V_6 ) ;
return 0 ;
}
