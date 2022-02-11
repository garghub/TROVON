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
V_15 ,
F_9 ( V_13 ) -
( F_9 ( V_6 ) - F_4 ) ) ;
if ( ! ( ( V_4 -> args [ 0 ] >> 7 ) & 0x01 ) ) {
V_5 = - V_16 ;
goto V_10;
}
}
V_5 = 0 ;
V_10:
F_10 ( & V_2 -> V_7 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 , V_21 , V_22 ;
struct V_3 V_4 ;
const struct V_23 * V_24 = NULL ;
T_1 * V_25 ;
unsigned int V_26 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_3 , V_15 ) ;
memcpy ( V_4 . args , L_4 , 15 ) ;
V_4 . V_8 = 15 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_5 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_26 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_12 ('A' << 24 | 58 << 16 | '2' << 8 | '0' << 0)
#define F_13 ('A' << 24 | 57 << 16 | '3' << 8 | '0' << 0)
switch ( V_26 ) {
case F_12 :
V_25 = V_27 ;
break;
case F_13 :
goto V_28;
break;
default:
F_14 ( & V_2 -> V_9 -> V_14 ,
L_6 ,
V_29 , V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_5 = - V_30 ;
goto V_17;
}
F_15 ( & V_2 -> V_9 -> V_14 , L_7 ,
V_29 , V_31 . V_32 . V_33 ) ;
V_5 = F_16 ( & V_24 , V_25 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
F_14 ( & V_2 -> V_9 -> V_14 , L_8 ,
V_29 , V_25 ) ;
goto V_17;
}
if ( V_24 -> V_34 % 17 != 0 ) {
F_14 ( & V_2 -> V_9 -> V_14 , L_9 ,
V_29 , V_25 ) ;
V_5 = - V_30 ;
goto V_17;
}
F_15 ( & V_2 -> V_9 -> V_14 , L_10 ,
V_29 , V_25 ) ;
for ( V_22 = V_24 -> V_34 ; V_22 > 0 ; V_22 -= 17 ) {
V_21 = V_24 -> V_35 [ V_24 -> V_34 - V_22 ] ;
memcpy ( V_4 . args , & V_24 -> V_35 [ ( V_24 -> V_34 - V_22 ) + 1 ] , V_21 ) ;
V_4 . V_8 = V_21 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_14 ( & V_2 -> V_9 -> V_14 ,
L_11 ,
V_29 , V_5 ) ;
goto V_17;
}
}
F_17 ( V_24 ) ;
V_24 = NULL ;
V_28:
memcpy ( V_4 . args , L_12 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_2 -> V_36 = true ;
return 0 ;
V_17:
if ( V_24 )
F_17 ( V_24 ) ;
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_3 , V_15 ) ;
V_2 -> V_36 = false ;
memcpy ( V_4 . args , L_13 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_37 * V_38 = & V_19 -> V_39 ;
int V_5 ;
struct V_3 V_4 ;
T_1 V_40 , V_41 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_14 ,
V_15 , V_38 -> V_41 , V_38 -> V_42 ,
V_38 -> V_43 ) ;
if ( ! V_2 -> V_36 ) {
V_5 = - V_44 ;
goto V_17;
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
case V_46 :
V_41 = 0x20 ;
break;
case V_47 :
V_41 = 0x30 ;
break;
default:
V_5 = - V_30 ;
goto V_17;
}
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . args [ 4 ] = V_41 | V_40 ;
if ( V_2 -> V_48 )
V_4 . args [ 5 ] = 0x01 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_16 , 8 ) ;
V_4 . args [ 4 ] = ( V_38 -> V_42 >> 0 ) & 0xff ;
V_4 . args [ 5 ] = ( V_38 -> V_42 >> 8 ) & 0xff ;
V_4 . args [ 6 ] = ( V_38 -> V_42 >> 16 ) & 0xff ;
V_4 . args [ 7 ] = ( V_38 -> V_42 >> 24 ) & 0xff ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_20 ( struct V_18 * V_19 , T_2 * V_42 )
{
* V_42 = 5000000 ;
return 0 ;
}
static int F_21 ( struct V_49 * V_9 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_9 -> V_14 . V_54 ;
struct V_18 * V_19 = V_53 -> V_19 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_55 ) ;
if ( ! V_2 ) {
V_5 = - V_56 ;
F_14 ( & V_9 -> V_14 , L_17 , V_29 ) ;
goto V_17;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_19 = V_53 -> V_19 ;
V_2 -> V_48 = V_53 -> V_48 ;
F_23 ( & V_2 -> V_7 ) ;
V_4 . V_8 = 0 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_19 -> V_20 = V_2 ;
memcpy ( & V_19 -> V_57 . V_58 , & V_31 ,
sizeof( struct V_59 ) ) ;
F_24 ( V_9 , V_2 ) ;
F_15 ( & V_2 -> V_9 -> V_14 ,
L_18 ,
V_29 ) ;
return 0 ;
V_17:
F_8 ( & V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
F_25 ( V_2 ) ;
return V_5 ;
}
static int F_26 ( struct V_49 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_8 ( & V_9 -> V_14 , L_3 , V_15 ) ;
memset ( & V_19 -> V_57 . V_58 , 0 , sizeof( struct V_59 ) ) ;
V_19 -> V_20 = NULL ;
F_25 ( V_2 ) ;
return 0 ;
}
