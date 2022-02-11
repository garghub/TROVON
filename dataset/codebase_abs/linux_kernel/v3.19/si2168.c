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
#define F_4 50
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
static int F_11 ( struct V_17 * V_18 , T_1 * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_18 -> V_23 ;
int V_5 ;
struct V_3 V_4 ;
* V_19 = 0 ;
if ( ! V_2 -> V_24 ) {
V_5 = - V_25 ;
goto V_16;
}
switch ( V_22 -> V_26 ) {
case V_27 :
memcpy ( V_4 . args , L_3 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 13 ;
break;
case V_28 :
memcpy ( V_4 . args , L_4 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 9 ;
break;
case V_29 :
memcpy ( V_4 . args , L_5 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 14 ;
break;
default:
V_5 = - V_30 ;
goto V_16;
}
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
switch ( ( V_4 . args [ 2 ] >> 1 ) & 0x03 ) {
case 0x01 :
* V_19 = V_31 | V_32 ;
break;
case 0x03 :
* V_19 = V_31 | V_32 | V_33 |
V_34 | V_35 ;
break;
}
V_2 -> V_36 = * V_19 ;
if ( * V_19 & V_35 ) {
V_22 -> V_37 . V_38 = 1 ;
V_22 -> V_37 . V_39 [ 0 ] . V_40 = V_41 ;
V_22 -> V_37 . V_39 [ 0 ] . V_42 = V_4 . args [ 3 ] * 1000 / 4 ;
} else {
V_22 -> V_37 . V_38 = 1 ;
V_22 -> V_37 . V_39 [ 0 ] . V_40 = V_43 ;
}
F_8 ( & V_2 -> V_9 -> V_14 , L_6 ,
* V_19 , V_4 . V_12 , V_4 . args ) ;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_18 -> V_23 ;
int V_5 ;
struct V_3 V_4 ;
T_2 V_44 , V_26 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_7 ,
V_22 -> V_26 , V_22 -> V_45 ,
V_22 -> V_46 , V_22 -> V_47 , V_22 -> V_48 ,
V_22 -> V_49 , V_22 -> V_50 ) ;
if ( ! V_2 -> V_24 ) {
V_5 = - V_25 ;
goto V_16;
}
switch ( V_22 -> V_26 ) {
case V_27 :
V_26 = 0x20 ;
break;
case V_28 :
V_26 = 0x30 ;
break;
case V_29 :
V_26 = 0x70 ;
break;
default:
V_5 = - V_30 ;
goto V_16;
}
if ( V_22 -> V_47 <= 5000000 )
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
if ( V_18 -> V_51 . V_52 . V_53 ) {
V_5 = V_18 -> V_51 . V_52 . V_53 ( V_18 ) ;
if ( V_5 )
goto V_16;
}
memcpy ( V_4 . args , L_8 , 5 ) ;
V_4 . V_8 = 5 ;
V_4 . V_12 = 5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
if ( V_22 -> V_26 == V_27 )
memcpy ( V_4 . args , L_9 , 6 ) ;
else if ( V_22 -> V_26 == V_28 )
memcpy ( V_4 . args , L_10 , 6 ) ;
else if ( V_22 -> V_26 == V_29 )
memcpy ( V_4 . args , L_11 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
if ( V_22 -> V_26 == V_29 ) {
V_4 . args [ 0 ] = 0x52 ;
V_4 . args [ 1 ] = V_22 -> V_50 & 0xff ;
V_4 . args [ 2 ] = V_22 -> V_50 == V_54 ? 0 : 1 ;
V_4 . V_8 = 3 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
}
memcpy ( V_4 . args , L_12 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 12 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_13 , 3 ) ;
V_4 . V_8 = 3 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_14 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_15 , 6 ) ;
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
memcpy ( V_4 . args , L_17 , 6 ) ;
V_4 . args [ 4 ] = V_26 | V_44 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
if ( V_22 -> V_26 == V_28 ) {
memcpy ( V_4 . args , L_18 , 4 ) ;
V_4 . args [ 4 ] = ( V_22 -> V_48 / 1000 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_22 -> V_48 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
}
memcpy ( V_4 . args , L_19 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . args [ 5 ] |= V_2 -> V_55 ? 0x00 : 0x10 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . args [ 5 ] |= V_2 -> V_55 ? 0x00 : 0x10 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_22 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_24 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_2 -> V_26 = V_22 -> V_26 ;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_5 , V_38 , V_56 ;
const struct V_57 * V_58 = NULL ;
T_2 * V_59 ;
const unsigned int V_60 = 8 ;
struct V_3 V_4 ;
unsigned int V_61 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_25 ) ;
memcpy ( V_4 . args , L_26 , 13 ) ;
V_4 . V_8 = 13 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
if ( V_2 -> V_62 ) {
memcpy ( V_4 . args , L_27 , 8 ) ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_24 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
goto V_63;
}
memcpy ( V_4 . args , L_28 , 8 ) ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_29 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_61 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_14 ('A' << 24 | 68 << 16 | '2' << 8 | '0' << 0)
#define F_15 ('A' << 24 | 68 << 16 | '3' << 8 | '0' << 0)
#define F_16 ('B' << 24 | 68 << 16 | '4' << 8 | '0' << 0)
switch ( V_61 ) {
case F_14 :
V_59 = V_64 ;
break;
case F_15 :
V_59 = V_65 ;
break;
case F_16 :
V_59 = V_66 ;
break;
default:
F_17 ( & V_2 -> V_9 -> V_14 ,
L_30 ,
V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_5 = - V_30 ;
goto V_16;
}
F_18 ( & V_2 -> V_9 -> V_14 , L_31 ,
V_67 . V_68 . V_69 ) ;
V_5 = F_19 ( & V_58 , V_59 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
if ( V_61 == F_16 ) {
V_59 = V_70 ;
V_5 = F_19 ( & V_58 , V_59 , & V_2 -> V_9 -> V_14 ) ;
}
if ( V_5 == 0 ) {
F_20 ( & V_2 -> V_9 -> V_14 ,
L_32 ,
V_66 ) ;
} else {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_33 ,
V_59 ) ;
goto V_71;
}
}
F_18 ( & V_2 -> V_9 -> V_14 , L_34 ,
V_59 ) ;
if ( ( V_58 -> V_72 % 17 == 0 ) && ( V_58 -> V_73 [ 0 ] > 5 ) ) {
for ( V_56 = V_58 -> V_72 ; V_56 > 0 ; V_56 -= 17 ) {
V_38 = V_58 -> V_73 [ V_58 -> V_72 - V_56 ] ;
memcpy ( V_4 . args , & V_58 -> V_73 [ ( V_58 -> V_72 - V_56 ) + 1 ] , V_38 ) ;
V_4 . V_8 = V_38 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_35 ,
V_5 ) ;
goto V_71;
}
}
} else {
for ( V_56 = V_58 -> V_72 ; V_56 > 0 ; V_56 -= V_60 ) {
V_38 = V_56 ;
if ( V_38 > V_60 )
V_38 = V_60 ;
memcpy ( V_4 . args , & V_58 -> V_73 [ V_58 -> V_72 - V_56 ] , V_38 ) ;
V_4 . V_8 = V_38 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_35 ,
V_5 ) ;
goto V_71;
}
}
}
F_21 ( V_58 ) ;
V_58 = NULL ;
memcpy ( V_4 . args , L_36 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
memcpy ( V_4 . args , L_37 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 10 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
F_8 ( & V_2 -> V_9 -> V_14 , L_38 ,
V_4 . args [ 6 ] , V_4 . args [ 7 ] , V_4 . args [ 8 ] ) ;
memcpy ( V_4 . args , L_39 , 6 ) ;
V_4 . args [ 4 ] |= V_2 -> V_74 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
V_2 -> V_62 = true ;
F_18 ( & V_2 -> V_9 -> V_14 , L_40 ,
V_67 . V_68 . V_69 ) ;
V_63:
V_2 -> V_24 = true ;
return 0 ;
V_71:
F_21 ( V_58 ) ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_25 ) ;
V_2 -> V_24 = false ;
memcpy ( V_4 . args , L_41 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_16;
return 0 ;
V_16:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_23 ( struct V_17 * V_18 ,
struct V_75 * V_2 )
{
V_2 -> V_76 = 900 ;
return 0 ;
}
static int F_24 ( struct V_77 * V_78 , void * V_79 , T_3 V_80 )
{
struct V_1 * V_2 = V_79 ;
int V_5 ;
struct V_81 V_82 = {
. V_83 = V_2 -> V_9 -> V_83 ,
. V_84 = 0 ,
. V_38 = 3 ,
. V_85 = L_42 ,
} ;
F_2 ( & V_2 -> V_7 ) ;
V_5 = F_25 ( V_2 -> V_9 -> V_86 , & V_82 , 1 ) ;
if ( V_5 != 1 ) {
F_26 ( & V_2 -> V_9 -> V_14 , L_43 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
static int F_27 ( struct V_77 * V_78 , void * V_79 , T_3 V_80 )
{
struct V_1 * V_2 = V_79 ;
int V_5 ;
struct V_81 V_87 = {
. V_83 = V_2 -> V_9 -> V_83 ,
. V_84 = 0 ,
. V_38 = 3 ,
. V_85 = L_44 ,
} ;
V_5 = F_25 ( V_2 -> V_9 -> V_86 , & V_87 , 1 ) ;
if ( V_5 != 1 ) {
F_26 ( & V_2 -> V_9 -> V_14 , L_43 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
F_10 ( & V_2 -> V_7 ) ;
return V_5 ;
}
static int F_28 ( struct V_88 * V_9 ,
const struct V_89 * V_90 )
{
struct V_91 * V_92 = V_9 -> V_14 . V_93 ;
struct V_1 * V_2 ;
int V_5 ;
F_8 ( & V_9 -> V_14 , L_25 ) ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_94 ) ;
if ( ! V_2 ) {
V_5 = - V_95 ;
F_17 ( & V_9 -> V_14 , L_45 ) ;
goto V_16;
}
V_2 -> V_9 = V_9 ;
F_30 ( & V_2 -> V_7 ) ;
V_2 -> V_86 = F_31 ( V_9 -> V_86 , & V_9 -> V_14 , V_2 ,
0 , 0 , 0 , F_24 , F_27 ) ;
if ( V_2 -> V_86 == NULL ) {
V_5 = - V_96 ;
goto V_16;
}
memcpy ( & V_2 -> V_18 . V_51 , & V_67 , sizeof( struct V_97 ) ) ;
V_2 -> V_18 . V_20 = V_2 ;
* V_92 -> V_77 = V_2 -> V_86 ;
* V_92 -> V_18 = & V_2 -> V_18 ;
V_2 -> V_74 = V_92 -> V_74 ;
V_2 -> V_55 = V_92 -> V_55 ;
V_2 -> V_62 = false ;
F_32 ( V_9 , V_2 ) ;
F_18 ( & V_2 -> V_9 -> V_14 ,
L_46 ) ;
return 0 ;
V_16:
F_33 ( V_2 ) ;
F_8 ( & V_9 -> V_14 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_34 ( struct V_88 * V_9 )
{
struct V_1 * V_2 = F_35 ( V_9 ) ;
F_8 ( & V_9 -> V_14 , L_25 ) ;
F_36 ( V_2 -> V_86 ) ;
V_2 -> V_18 . V_51 . V_98 = NULL ;
V_2 -> V_18 . V_20 = NULL ;
F_33 ( V_2 ) ;
return 0 ;
}
