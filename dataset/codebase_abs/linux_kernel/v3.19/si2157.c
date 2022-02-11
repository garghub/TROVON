static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_4 -> V_8 ) {
V_5 = F_3 ( V_2 -> V_9 , V_4 -> args , V_4 -> V_8 ) ;
if ( V_5 < 0 ) {
goto V_10;
} else if ( V_5 != V_4 -> V_8 ) {
V_5 = - V_11 ;
goto V_10;
}
}
if ( V_4 -> V_12 ) {
#define F_4 80
V_6 = V_13 + F_5 ( F_4 ) ;
while ( ! F_6 ( V_13 , V_6 ) ) {
V_5 = F_7 ( V_2 -> V_9 , V_4 -> args , V_4 -> V_12 ) ;
if ( V_5 < 0 ) {
goto V_10;
} else if ( V_5 != V_4 -> V_12 ) {
V_5 = - V_11 ;
goto V_10;
}
if ( ( V_4 -> args [ 0 ] >> 7 ) & 0x01 )
break;
}
F_8 ( & V_2 -> V_9 -> V_14 , L_1 ,
F_9 ( V_13 ) -
( F_9 ( V_6 ) - F_4 ) ) ;
if ( ! ( ( V_4 -> args [ 0 ] >> 7 ) & 0x01 ) ) {
V_5 = - V_15 ;
goto V_10;
}
}
V_5 = 0 ;
V_10:
F_10 ( & V_2 -> V_7 ) ;
if ( V_5 )
goto V_16;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_5 , V_20 , V_21 ;
struct V_3 V_4 ;
const struct V_22 * V_23 = NULL ;
T_1 * V_24 ;
unsigned int V_25 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_3 ) ;
if ( V_2 -> V_26 )
goto V_27;
if ( V_2 -> V_28 == V_29 ) {
memcpy ( V_4 . args , L_4 , 9 ) ;
V_4 . V_8 = 9 ;
} else {
memcpy ( V_4 . args , L_5 , 15 ) ;
V_4 . V_8 = 15 ;
}
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_6 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_25 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_12 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define F_13 ('A' << 24 | 48 << 16 | '2' << 8 | '0' << 0)
#define F_14 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
#define F_15 ('A' << 24 | 47 << 16 | '3' << 8 | '0' << 0)
#define F_16 ('A' << 24 | 46 << 16 | '1' << 8 | '0' << 0)
switch ( V_25 ) {
case F_12 :
case F_13 :
V_24 = V_30 ;
break;
case F_14 :
case F_15 :
case F_16 :
goto V_31;
default:
F_17 ( & V_2 -> V_9 -> V_14 ,
L_7 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_5 = - V_32 ;
goto V_16;
}
F_18 ( & V_2 -> V_9 -> V_14 , L_8 ,
V_33 . V_34 . V_35 ) ;
V_5 = F_19 ( & V_23 , V_24 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
F_17 ( & V_2 -> V_9 -> V_14 , L_9 ,
V_24 ) ;
goto V_16;
}
if ( V_23 -> V_36 % 17 != 0 ) {
F_17 ( & V_2 -> V_9 -> V_14 , L_10 ,
V_24 ) ;
V_5 = - V_32 ;
goto V_37;
}
F_18 ( & V_2 -> V_9 -> V_14 , L_11 ,
V_24 ) ;
for ( V_21 = V_23 -> V_36 ; V_21 > 0 ; V_21 -= 17 ) {
V_20 = V_23 -> V_38 [ V_23 -> V_36 - V_21 ] ;
memcpy ( V_4 . args , & V_23 -> V_38 [ ( V_23 -> V_36 - V_21 ) + 1 ] , V_20 ) ;
V_4 . V_8 = V_20 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_12 ,
V_5 ) ;
goto V_37;
}
}
F_20 ( V_23 ) ;
V_23 = NULL ;
V_31:
memcpy ( V_4 . args , L_13 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_2 -> V_26 = true ;
V_27:
V_2 -> V_39 = true ;
return 0 ;
V_37:
F_20 ( V_23 ) ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_3 ) ;
V_2 -> V_39 = false ;
memcpy ( V_4 . args , L_14 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_40 * V_41 = & V_18 -> V_42 ;
int V_5 ;
struct V_3 V_4 ;
T_1 V_43 , V_44 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_15 ,
V_41 -> V_44 , V_41 -> V_45 ,
V_41 -> V_46 ) ;
if ( ! V_2 -> V_39 ) {
V_5 = - V_47 ;
goto V_16;
}
if ( V_41 -> V_46 <= 6000000 )
V_43 = 0x06 ;
else if ( V_41 -> V_46 <= 7000000 )
V_43 = 0x07 ;
else if ( V_41 -> V_46 <= 8000000 )
V_43 = 0x08 ;
else
V_43 = 0x0f ;
switch ( V_41 -> V_44 ) {
case V_48 :
V_44 = 0x00 ;
break;
case V_49 :
V_44 = 0x10 ;
break;
case V_50 :
case V_51 :
V_44 = 0x20 ;
break;
case V_52 :
V_44 = 0x30 ;
break;
default:
V_5 = - V_32 ;
goto V_16;
}
memcpy ( V_4 . args , L_16 , 6 ) ;
V_4 . args [ 4 ] = V_44 | V_43 ;
if ( V_2 -> V_53 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
if ( V_2 -> V_28 == V_29 )
memcpy ( V_4 . args , L_17 , 6 ) ;
else
memcpy ( V_4 . args , L_18 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_19 , 8 ) ;
V_4 . args [ 4 ] = ( V_41 -> V_45 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_41 -> V_45 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_41 -> V_45 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_41 -> V_45 >> 24 ) & 0xff ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_23 ( struct V_17 * V_18 , T_2 * V_45 )
{
* V_45 = 5000000 ;
return 0 ;
}
static int F_24 ( struct V_54 * V_9 ,
const struct V_55 * V_56 )
{
struct V_57 * V_58 = V_9 -> V_14 . V_59 ;
struct V_17 * V_18 = V_58 -> V_18 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 ) {
V_5 = - V_61 ;
F_17 ( & V_9 -> V_14 , L_20 ) ;
goto V_16;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_18 = V_58 -> V_18 ;
V_2 -> V_53 = V_58 -> V_53 ;
V_2 -> V_26 = false ;
V_2 -> V_28 = ( T_1 ) V_56 -> V_62 ;
F_26 ( & V_2 -> V_7 ) ;
V_4 . V_8 = 0 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_18 -> V_19 = V_2 ;
memcpy ( & V_18 -> V_63 . V_64 , & V_33 ,
sizeof( struct V_65 ) ) ;
F_27 ( V_9 , V_2 ) ;
F_18 ( & V_2 -> V_9 -> V_14 ,
L_21 ,
V_2 -> V_28 == V_29 ?
L_22 : L_23 ) ;
return 0 ;
V_16:
F_8 ( & V_9 -> V_14 , L_2 , V_5 ) ;
F_28 ( V_2 ) ;
return V_5 ;
}
static int F_29 ( struct V_54 * V_9 )
{
struct V_1 * V_2 = F_30 ( V_9 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_8 ( & V_9 -> V_14 , L_3 ) ;
memset ( & V_18 -> V_63 . V_64 , 0 , sizeof( struct V_65 ) ) ;
V_18 -> V_19 = NULL ;
F_28 ( V_2 ) ;
return 0 ;
}
