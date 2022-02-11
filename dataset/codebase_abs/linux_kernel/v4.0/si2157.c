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
int V_7 , V_19 , V_20 ;
struct V_3 V_4 ;
const struct V_21 * V_22 ;
const char * V_23 ;
unsigned int V_24 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
if ( V_6 -> V_25 )
goto V_26;
if ( V_6 -> V_27 == V_28 ) {
memcpy ( V_4 . args , L_4 , 9 ) ;
V_4 . V_10 = 9 ;
} else {
memcpy ( V_4 . args , L_5 , 15 ) ;
V_4 . V_10 = 15 ;
}
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_6 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 13 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
V_24 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_13 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define F_14 ('A' << 24 | 48 << 16 | '2' << 8 | '0' << 0)
#define F_15 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
#define F_16 ('A' << 24 | 47 << 16 | '3' << 8 | '0' << 0)
#define F_17 ('A' << 24 | 46 << 16 | '1' << 8 | '0' << 0)
switch ( V_24 ) {
case F_13 :
case F_14 :
V_23 = V_30 ;
break;
case F_15 :
case F_16 :
case F_17 :
V_23 = NULL ;
break;
default:
F_18 ( & V_2 -> V_6 , L_7 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_7 = - V_31 ;
goto V_29;
}
F_19 ( & V_2 -> V_6 , L_8 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] , V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
if ( V_23 == NULL )
goto V_32;
V_7 = F_20 ( & V_22 , V_23 , & V_2 -> V_6 ) ;
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_9 ,
V_23 ) ;
goto V_29;
}
if ( V_22 -> V_33 % 17 != 0 ) {
F_18 ( & V_2 -> V_6 , L_10 ,
V_23 ) ;
V_7 = - V_31 ;
goto V_34;
}
F_19 ( & V_2 -> V_6 , L_11 ,
V_23 ) ;
for ( V_20 = V_22 -> V_33 ; V_20 > 0 ; V_20 -= 17 ) {
V_19 = V_22 -> V_35 [ V_22 -> V_33 - V_20 ] ;
memcpy ( V_4 . args , & V_22 -> V_35 [ ( V_22 -> V_33 - V_20 ) + 1 ] , V_19 ) ;
V_4 . V_10 = V_19 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_18 ( & V_2 -> V_6 , L_12 ,
V_7 ) ;
goto V_34;
}
}
F_21 ( V_22 ) ;
V_32:
memcpy ( V_4 . args , L_13 , 2 ) ;
V_4 . V_10 = 2 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_14 , 1 ) ;
V_4 . V_10 = 1 ;
V_4 . V_13 = 10 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
F_19 ( & V_2 -> V_6 , L_15 ,
V_4 . args [ 6 ] , V_4 . args [ 7 ] , V_4 . args [ 8 ] ) ;
V_6 -> V_25 = true ;
V_26:
V_6 -> V_36 = true ;
return 0 ;
V_34:
F_21 ( V_22 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_3 V_4 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
V_6 -> V_36 = false ;
memcpy ( V_4 . args , L_16 , 2 ) ;
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
static int F_23 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = & V_17 -> V_39 ;
int V_7 ;
struct V_3 V_4 ;
T_1 V_40 , V_41 ;
F_9 ( & V_2 -> V_6 ,
L_17 ,
V_38 -> V_41 , V_38 -> V_42 , V_38 -> V_43 ) ;
if ( ! V_6 -> V_36 ) {
V_7 = - V_44 ;
goto V_29;
}
if ( V_38 -> V_43 <= 6000000 )
V_40 = 0x06 ;
else if ( V_38 -> V_43 <= 7000000 )
V_40 = 0x07 ;
else if ( V_38 -> V_43 <= 8000000 )
V_40 = 0x08 ;
else
V_40 = 0x0f ;
switch ( V_38 -> V_41 ) {
case V_45 :
V_41 = 0x00 ;
break;
case V_46 :
V_41 = 0x10 ;
break;
case V_47 :
case V_48 :
V_41 = 0x20 ;
break;
case V_49 :
V_41 = 0x30 ;
break;
default:
V_7 = - V_31 ;
goto V_29;
}
memcpy ( V_4 . args , L_18 , 6 ) ;
V_4 . args [ 4 ] = V_41 | V_40 ;
if ( V_6 -> V_50 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
if ( V_6 -> V_27 == V_28 )
memcpy ( V_4 . args , L_19 , 6 ) ;
else
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . V_10 = 6 ;
V_4 . V_13 = 4 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_29;
memcpy ( V_4 . args , L_21 , 8 ) ;
V_4 . args [ 4 ] = ( V_38 -> V_42 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_38 -> V_42 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_38 -> V_42 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_38 -> V_42 >> 24 ) & 0xff ;
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
static int F_24 ( struct V_16 * V_17 , T_2 * V_42 )
{
* V_42 = 5000000 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_51 * V_52 )
{
struct V_53 * V_54 = V_2 -> V_6 . V_55 ;
struct V_16 * V_17 = V_54 -> V_17 ;
struct V_5 * V_6 ;
struct V_3 V_4 ;
int V_7 ;
V_6 = F_26 ( sizeof( * V_6 ) , V_56 ) ;
if ( ! V_6 ) {
V_7 = - V_57 ;
F_18 ( & V_2 -> V_6 , L_22 ) ;
goto V_29;
}
F_27 ( V_2 , V_6 ) ;
V_6 -> V_17 = V_54 -> V_17 ;
V_6 -> V_50 = V_54 -> V_50 ;
V_6 -> V_25 = false ;
V_6 -> V_27 = ( T_1 ) V_52 -> V_58 ;
F_28 ( & V_6 -> V_9 ) ;
V_4 . V_10 = 0 ;
V_4 . V_13 = 1 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto V_59;
memcpy ( & V_17 -> V_60 . V_61 , & V_62 , sizeof( struct V_63 ) ) ;
V_17 -> V_18 = V_2 ;
F_19 ( & V_2 -> V_6 , L_23 ,
V_6 -> V_27 == V_28 ?
L_24 : L_25 ) ;
return 0 ;
V_59:
F_29 ( V_6 ) ;
V_29:
F_9 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
F_9 ( & V_2 -> V_6 , L_3 ) ;
memset ( & V_17 -> V_60 . V_61 , 0 , sizeof( struct V_63 ) ) ;
V_17 -> V_18 = NULL ;
F_29 ( V_6 ) ;
return 0 ;
}
