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
memcpy ( V_4 . args , L_4 , 15 ) ;
V_4 . V_8 = 15 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_5 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_25 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_12 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define F_13 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
#define F_14 ('A' << 24 | 47 << 16 | '3' << 8 | '0' << 0)
switch ( V_25 ) {
case F_12 :
V_24 = V_28 ;
break;
case F_13 :
case F_14 :
goto V_29;
break;
default:
F_15 ( & V_2 -> V_9 -> V_14 ,
L_6 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_5 = - V_30 ;
goto V_16;
}
F_16 ( & V_2 -> V_9 -> V_14 , L_7 ,
V_31 . V_32 . V_33 ) ;
V_5 = F_17 ( & V_23 , V_24 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
F_15 ( & V_2 -> V_9 -> V_14 , L_8 ,
V_24 ) ;
goto V_16;
}
if ( V_23 -> V_34 % 17 != 0 ) {
F_15 ( & V_2 -> V_9 -> V_14 , L_9 ,
V_24 ) ;
V_5 = - V_30 ;
goto V_16;
}
F_16 ( & V_2 -> V_9 -> V_14 , L_10 ,
V_24 ) ;
for ( V_21 = V_23 -> V_34 ; V_21 > 0 ; V_21 -= 17 ) {
V_20 = V_23 -> V_35 [ V_23 -> V_34 - V_21 ] ;
memcpy ( V_4 . args , & V_23 -> V_35 [ ( V_23 -> V_34 - V_21 ) + 1 ] , V_20 ) ;
V_4 . V_8 = V_20 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_15 ( & V_2 -> V_9 -> V_14 ,
L_11 ,
V_5 ) ;
goto V_16;
}
}
F_18 ( V_23 ) ;
V_23 = NULL ;
V_29:
memcpy ( V_4 . args , L_12 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_2 -> V_26 = true ;
V_27:
V_2 -> V_36 = true ;
return 0 ;
V_16:
if ( V_23 )
F_18 ( V_23 ) ;
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_19 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_3 ) ;
V_2 -> V_36 = false ;
memcpy ( V_4 . args , L_13 , 2 ) ;
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
static int F_20 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_37 * V_38 = & V_18 -> V_39 ;
int V_5 ;
struct V_3 V_4 ;
T_1 V_40 , V_41 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_14 ,
V_38 -> V_41 , V_38 -> V_42 ,
V_38 -> V_43 ) ;
if ( ! V_2 -> V_36 ) {
V_5 = - V_44 ;
goto V_16;
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
case V_47 :
V_41 = 0x20 ;
break;
case V_48 :
V_41 = 0x30 ;
break;
default:
V_5 = - V_30 ;
goto V_16;
}
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . args [ 4 ] = V_41 | V_40 ;
if ( V_2 -> V_49 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_16 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_17 , 8 ) ;
V_4 . args [ 4 ] = ( V_38 -> V_42 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_38 -> V_42 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_38 -> V_42 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_38 -> V_42 >> 24 ) & 0xff ;
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
static int F_21 ( struct V_17 * V_18 , T_2 * V_42 )
{
* V_42 = 5000000 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_9 ,
const struct V_51 * V_52 )
{
struct V_53 * V_54 = V_9 -> V_14 . V_55 ;
struct V_17 * V_18 = V_54 -> V_18 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_56 ) ;
if ( ! V_2 ) {
V_5 = - V_57 ;
F_15 ( & V_9 -> V_14 , L_18 ) ;
goto V_16;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_18 = V_54 -> V_18 ;
V_2 -> V_49 = V_54 -> V_49 ;
V_2 -> V_26 = false ;
F_24 ( & V_2 -> V_7 ) ;
V_4 . V_8 = 0 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_18 -> V_19 = V_2 ;
memcpy ( & V_18 -> V_58 . V_59 , & V_31 ,
sizeof( struct V_60 ) ) ;
F_25 ( V_9 , V_2 ) ;
F_16 ( & V_2 -> V_9 -> V_14 ,
L_19 ) ;
return 0 ;
V_16:
F_8 ( & V_9 -> V_14 , L_2 , V_5 ) ;
F_26 ( V_2 ) ;
return V_5 ;
}
static int F_27 ( struct V_50 * V_9 )
{
struct V_1 * V_2 = F_28 ( V_9 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_8 ( & V_9 -> V_14 , L_3 ) ;
memset ( & V_18 -> V_58 . V_59 , 0 , sizeof( struct V_60 ) ) ;
V_18 -> V_19 = NULL ;
F_26 ( V_2 ) ;
return 0 ;
}
