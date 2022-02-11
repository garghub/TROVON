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
} else {
memcpy ( V_4 . args , L_7 , 15 ) ;
V_4 . V_10 = 15 ;
}
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_8 , 1 ) ;
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
switch ( V_28 ) {
case F_13 :
case F_14 :
V_26 = V_34 ;
break;
case F_15 :
case F_16 :
case F_17 :
V_26 = NULL ;
break;
default:
F_18 ( & V_2 -> V_6 , L_9 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = - V_35 ;
goto V_29;
}
F_19 ( & V_2 -> V_6 , L_10 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] , V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
if ( V_26 == NULL )
goto V_36;
V_7 = F_20 ( & V_25 , V_26 , & V_2 -> V_6 ) ;
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_11 ,
V_26 ) ;
goto V_29;
}
if ( V_25 -> V_37 % 17 != 0 ) {
F_18 ( & V_2 -> V_6 , L_12 ,
V_26 ) ;
V_7 = - V_35 ;
goto V_38;
}
F_19 ( & V_2 -> V_6 , L_13 ,
V_26 ) ;
for ( V_23 = V_25 -> V_37 ; V_23 > 0 ; V_23 -= 17 ) {
V_22 = V_25 -> V_39 [ V_25 -> V_37 - V_23 ] ;
if ( V_22 > V_40 ) {
F_18 ( & V_2 -> V_6 , L_14 ) ;
V_7 = - V_35 ;
goto V_38;
}
memcpy ( V_4 . args , & V_25 -> V_39 [ ( V_25 -> V_37 - V_23 ) + 1 ] , V_22 ) ;
V_4 . V_10 = V_22 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_15 ,
V_7 ) ;
goto V_38;
}
}
F_21 ( V_25 ) ;
V_36:
memcpy ( V_4 . args , L_16 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_17 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 10 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
F_19 ( & V_2 -> V_6 , L_18 ,
V_4 . args [ 6 ] , V_4 . args [ 7 ] , V_4 . args [ 8 ] ) ;
V_31:
V_20 -> V_41 . V_22 = 1 ;
V_20 -> V_41 . V_42 [ 0 ] . V_43 = V_44 ;
F_22 ( & V_6 -> V_45 , F_6 ( 1000 ) ) ;
V_6 -> V_46 = true ;
return 0 ;
V_38:
F_21 ( V_25 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_23 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
V_6 -> V_46 = false ;
F_24 ( & V_6 -> V_45 ) ;
memcpy ( V_4 . args , L_19 , 2 ) ;
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
static int F_25 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_20 = & V_17 -> V_21 ;
int V_7 ;
struct V_3 V_4 ;
T_1 V_47 , V_48 ;
T_2 V_30 = 5000000 ;
F_9 ( & V_2 -> V_6 ,
L_20 ,
V_20 -> V_48 , V_20 -> V_49 , V_20 -> V_50 ) ;
if ( ! V_6 -> V_46 ) {
V_7 = - V_51 ;
goto V_29;
}
if ( V_20 -> V_50 <= 6000000 )
V_47 = 0x06 ;
else if ( V_20 -> V_50 <= 7000000 )
V_47 = 0x07 ;
else if ( V_20 -> V_50 <= 8000000 )
V_47 = 0x08 ;
else
V_47 = 0x0f ;
switch ( V_20 -> V_48 ) {
case V_52 :
V_48 = 0x00 ;
V_30 = 3250000 ;
break;
case V_53 :
V_48 = 0x10 ;
V_30 = 4000000 ;
break;
case V_54 :
case V_55 :
V_48 = 0x20 ;
break;
case V_56 :
V_48 = 0x30 ;
break;
default:
V_7 = - V_35 ;
goto V_29;
}
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . args [ 4 ] = V_48 | V_47 ;
if ( V_6 -> V_57 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_6 -> V_32 == V_33 )
memcpy ( V_4 . args , L_22 , 6 ) ;
else
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . args [ 4 ] = V_6 -> V_58 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_30 != V_6 -> V_30 ) {
memcpy ( V_4 . args , L_24 , 4 ) ;
V_4 . args [ 4 ] = ( V_30 / 1000 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_30 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_6 -> V_30 = V_30 ;
}
memcpy ( V_4 . args , L_25 , 8 ) ;
V_4 . args [ 4 ] = ( V_20 -> V_49 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_20 -> V_49 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_20 -> V_49 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_20 -> V_49 >> 24 ) & 0xff ;
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
static int F_26 ( struct V_16 * V_17 , T_2 * V_49 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_49 = V_6 -> V_30 ;
return 0 ;
}
static void F_27 ( struct V_59 * V_60 )
{
struct V_5 * V_6 = F_28 ( V_60 , struct V_5 , V_45 . V_60 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_21 ;
struct V_3 V_4 ;
int V_7 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
memcpy ( V_4 . args , L_26 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 12 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_20 -> V_41 . V_42 [ 0 ] . V_43 = V_61 ;
V_20 -> V_41 . V_42 [ 0 ] . V_62 = ( V_63 ) V_4 . args [ 3 ] * 1000 ;
F_22 ( & V_6 -> V_45 , F_6 ( 2000 ) ) ;
return;
V_29:
V_20 -> V_41 . V_42 [ 0 ] . V_43 = V_44 ;
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
struct V_66 * V_67 = V_2 -> V_6 . V_68 ;
struct V_16 * V_17 = V_67 -> V_17 ;
struct V_5 * V_6 ;
struct V_3 V_4 ;
int V_7 ;
V_6 = F_30 ( sizeof( * V_6 ) , V_69 ) ;
if ( ! V_6 ) {
V_7 = - V_70 ;
F_18 ( & V_2 -> V_6 , L_27 ) ;
goto V_29;
}
F_31 ( V_2 , V_6 ) ;
V_6 -> V_17 = V_67 -> V_17 ;
V_6 -> V_57 = V_67 -> V_57 ;
V_6 -> V_58 = V_67 -> V_58 ;
V_6 -> V_32 = ( T_1 ) V_65 -> V_71 ;
V_6 -> V_30 = 5000000 ;
F_32 ( & V_6 -> V_9 ) ;
F_33 ( & V_6 -> V_45 , F_27 ) ;
V_4 . V_10 = 0 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_72;
memcpy ( & V_17 -> V_73 . V_74 , & V_75 , sizeof( struct V_76 ) ) ;
V_17 -> V_18 = V_2 ;
#ifdef F_34
if ( V_67 -> V_77 ) {
V_6 -> V_77 = V_67 -> V_77 ;
V_6 -> V_78 . V_79 = V_80 ;
V_6 -> V_78 . V_81 = V_82 ;
V_6 -> V_83 [ V_84 ] . V_85 = V_86 ;
V_6 -> V_83 [ V_87 ] . V_85 = V_88 ;
V_6 -> V_83 [ V_89 ] . V_85 = V_88 ;
V_7 = F_35 ( & V_6 -> V_78 , V_90 ,
& V_6 -> V_83 [ 0 ] ) ;
if ( V_7 )
goto V_72;
V_7 = F_36 ( V_67 -> V_77 , & V_6 -> V_78 ) ;
if ( V_7 ) {
F_37 ( & V_6 -> V_78 ) ;
goto V_72;
}
}
#endif
F_19 ( & V_2 -> V_6 , L_28 ,
V_6 -> V_32 == V_33 ?
L_29 : L_30 ) ;
return 0 ;
V_72:
F_38 ( V_6 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
F_24 ( & V_6 -> V_45 ) ;
#ifdef F_40
if ( V_6 -> V_77 )
F_41 ( & V_6 -> V_78 ) ;
#endif
memset ( & V_17 -> V_73 . V_74 , 0 , sizeof( struct V_76 ) ) ;
V_17 -> V_18 = NULL ;
F_38 ( V_6 ) ;
return 0 ;
}
