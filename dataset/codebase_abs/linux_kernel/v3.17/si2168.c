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
static int F_11 ( struct V_18 * V_19 , T_1 * V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_22 * V_23 = & V_19 -> V_24 ;
int V_5 ;
struct V_3 V_4 ;
* V_20 = 0 ;
if ( ! V_2 -> V_25 ) {
V_5 = - V_26 ;
goto V_17;
}
switch ( V_23 -> V_27 ) {
case V_28 :
memcpy ( V_4 . args , L_3 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 13 ;
break;
case V_29 :
memcpy ( V_4 . args , L_4 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 9 ;
break;
case V_30 :
memcpy ( V_4 . args , L_5 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 14 ;
break;
default:
V_5 = - V_31 ;
goto V_17;
}
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
switch ( ( V_4 . args [ 2 ] >> 1 ) & 0x03 ) {
case 0x01 :
* V_20 = V_32 | V_33 ;
break;
case 0x03 :
* V_20 = V_32 | V_33 | V_34 |
V_35 | V_36 ;
break;
}
V_2 -> V_37 = * V_20 ;
if ( * V_20 & V_36 ) {
V_23 -> V_38 . V_39 = 1 ;
V_23 -> V_38 . V_40 [ 0 ] . V_41 = V_42 ;
V_23 -> V_38 . V_40 [ 0 ] . V_43 = V_4 . args [ 3 ] * 1000 / 4 ;
} else {
V_23 -> V_38 . V_39 = 1 ;
V_23 -> V_38 . V_40 [ 0 ] . V_41 = V_44 ;
}
F_8 ( & V_2 -> V_9 -> V_14 , L_6 ,
V_15 , * V_20 , V_4 . V_12 , V_4 . args ) ;
return 0 ;
V_17:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_22 * V_23 = & V_19 -> V_24 ;
int V_5 ;
struct V_3 V_4 ;
T_2 V_45 , V_27 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_7 ,
V_15 , V_23 -> V_27 , V_23 -> V_46 ,
V_23 -> V_47 , V_23 -> V_48 , V_23 -> V_49 ,
V_23 -> V_50 ) ;
if ( ! V_2 -> V_25 ) {
V_5 = - V_26 ;
goto V_17;
}
switch ( V_23 -> V_27 ) {
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
V_5 = - V_31 ;
goto V_17;
}
if ( V_23 -> V_48 <= 5000000 )
V_45 = 0x05 ;
else if ( V_23 -> V_48 <= 6000000 )
V_45 = 0x06 ;
else if ( V_23 -> V_48 <= 7000000 )
V_45 = 0x07 ;
else if ( V_23 -> V_48 <= 8000000 )
V_45 = 0x08 ;
else if ( V_23 -> V_48 <= 9000000 )
V_45 = 0x09 ;
else if ( V_23 -> V_48 <= 10000000 )
V_45 = 0x0a ;
else
V_45 = 0x0f ;
if ( V_19 -> V_51 . V_52 . V_53 ) {
V_5 = V_19 -> V_51 . V_52 . V_53 ( V_19 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_4 . args , L_8 , 5 ) ;
V_4 . V_8 = 5 ;
V_4 . V_12 = 5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
if ( V_23 -> V_27 == V_28 )
memcpy ( V_4 . args , L_9 , 6 ) ;
else if ( V_23 -> V_27 == V_29 )
memcpy ( V_4 . args , L_10 , 6 ) ;
else if ( V_23 -> V_27 == V_30 )
memcpy ( V_4 . args , L_11 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_12 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 12 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_13 , 3 ) ;
V_4 . V_8 = 3 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_14 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_16 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_17 , 6 ) ;
V_4 . args [ 4 ] = V_27 | V_45 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
if ( V_23 -> V_27 == V_29 ) {
memcpy ( V_4 . args , L_18 , 4 ) ;
V_4 . args [ 4 ] = ( V_23 -> V_49 / 1000 ) & 0xff ;
V_4 . args [ 5 ] = ( ( V_23 -> V_49 / 1000 ) >> 8 ) & 0xff ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_4 . args , L_19 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_22 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_24 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 4 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_25 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_2 -> V_27 = V_23 -> V_27 ;
return 0 ;
V_17:
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_5 , V_39 , V_54 ;
const struct V_55 * V_56 = NULL ;
T_2 * V_57 ;
const unsigned int V_58 = 8 ;
struct V_3 V_4 ;
unsigned int V_59 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_26 , V_15 ) ;
memcpy ( V_4 . args , L_27 , 13 ) ;
V_4 . V_8 = 13 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_28 , 8 ) ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_29 , 1 ) ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_59 = V_4 . args [ 1 ] << 24 | V_4 . args [ 2 ] << 16 | V_4 . args [ 3 ] << 8 |
V_4 . args [ 4 ] << 0 ;
#define F_14 ('A' << 24 | 68 << 16 | '2' << 8 | '0' << 0)
#define F_15 ('A' << 24 | 68 << 16 | '3' << 8 | '0' << 0)
#define F_16 ('B' << 24 | 68 << 16 | '4' << 8 | '0' << 0)
switch ( V_59 ) {
case F_14 :
V_57 = V_60 ;
break;
case F_15 :
V_57 = V_61 ;
break;
case F_16 :
V_57 = V_62 ;
break;
default:
F_17 ( & V_2 -> V_9 -> V_14 ,
L_30 ,
V_63 , V_4 . args [ 2 ] , V_4 . args [ 1 ] ,
V_4 . args [ 3 ] , V_4 . args [ 4 ] ) ;
V_5 = - V_31 ;
goto V_17;
}
F_18 ( & V_2 -> V_9 -> V_14 , L_31 ,
V_63 , V_64 . V_65 . V_66 ) ;
V_5 = F_19 ( & V_56 , V_57 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
if ( V_59 == F_16 ) {
V_57 = V_67 ;
V_5 = F_19 ( & V_56 , V_57 , & V_2 -> V_9 -> V_14 ) ;
}
if ( V_5 == 0 ) {
F_20 ( & V_2 -> V_9 -> V_14 ,
L_32 ,
V_63 , V_62 ) ;
} else {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_33 ,
V_63 , V_57 ) ;
goto V_17;
}
}
F_18 ( & V_2 -> V_9 -> V_14 , L_34 ,
V_63 , V_57 ) ;
for ( V_54 = V_56 -> V_68 ; V_54 > 0 ; V_54 -= V_58 ) {
V_39 = V_54 ;
if ( V_39 > V_58 )
V_39 = V_58 ;
memcpy ( V_4 . args , & V_56 -> V_69 [ V_56 -> V_68 - V_54 ] , V_39 ) ;
V_4 . V_8 = V_39 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_17 ( & V_2 -> V_9 -> V_14 ,
L_35 ,
V_63 , V_5 ) ;
goto V_17;
}
}
F_21 ( V_56 ) ;
V_56 = NULL ;
memcpy ( V_4 . args , L_36 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
F_18 ( & V_2 -> V_9 -> V_14 , L_37 ,
V_63 , V_64 . V_65 . V_66 ) ;
V_2 -> V_25 = true ;
return 0 ;
V_17:
if ( V_56 )
F_21 ( V_56 ) ;
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_26 , V_15 ) ;
V_2 -> V_25 = false ;
memcpy ( V_4 . args , L_38 , 1 ) ;
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
static int F_23 ( struct V_18 * V_19 ,
struct V_70 * V_2 )
{
V_2 -> V_71 = 900 ;
return 0 ;
}
static int F_24 ( struct V_72 * V_73 , void * V_74 , T_3 V_75 )
{
struct V_1 * V_2 = V_74 ;
int V_5 ;
struct V_76 V_77 = {
. V_78 = V_2 -> V_9 -> V_78 ,
. V_79 = 0 ,
. V_39 = 3 ,
. V_80 = L_39 ,
} ;
F_2 ( & V_2 -> V_7 ) ;
V_5 = F_25 ( V_2 -> V_9 -> V_81 , & V_77 , 1 ) ;
if ( V_5 != 1 ) {
F_26 ( & V_2 -> V_9 -> V_14 , L_40 ,
V_63 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
static int F_27 ( struct V_72 * V_73 , void * V_74 , T_3 V_75 )
{
struct V_1 * V_2 = V_74 ;
int V_5 ;
struct V_76 V_82 = {
. V_78 = V_2 -> V_9 -> V_78 ,
. V_79 = 0 ,
. V_39 = 3 ,
. V_80 = L_41 ,
} ;
V_5 = F_25 ( V_2 -> V_9 -> V_81 , & V_82 , 1 ) ;
if ( V_5 != 1 ) {
F_26 ( & V_2 -> V_9 -> V_14 , L_40 ,
V_63 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
F_10 ( & V_2 -> V_7 ) ;
return V_5 ;
}
static int F_28 ( struct V_83 * V_9 ,
const struct V_84 * V_85 )
{
struct V_86 * V_87 = V_9 -> V_14 . V_88 ;
struct V_1 * V_2 ;
int V_5 ;
F_8 ( & V_9 -> V_14 , L_26 , V_15 ) ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 ) {
V_5 = - V_90 ;
F_17 ( & V_9 -> V_14 , L_42 , V_63 ) ;
goto V_17;
}
V_2 -> V_9 = V_9 ;
F_30 ( & V_2 -> V_7 ) ;
V_2 -> V_81 = F_31 ( V_9 -> V_81 , & V_9 -> V_14 , V_2 ,
0 , 0 , 0 , F_24 , F_27 ) ;
if ( V_2 -> V_81 == NULL ) {
V_5 = - V_91 ;
goto V_17;
}
memcpy ( & V_2 -> V_19 . V_51 , & V_64 , sizeof( struct V_92 ) ) ;
V_2 -> V_19 . V_21 = V_2 ;
* V_87 -> V_72 = V_2 -> V_81 ;
* V_87 -> V_19 = & V_2 -> V_19 ;
F_32 ( V_9 , V_2 ) ;
F_18 ( & V_2 -> V_9 -> V_14 ,
L_43 ,
V_63 ) ;
return 0 ;
V_17:
F_33 ( V_2 ) ;
F_8 ( & V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_34 ( struct V_83 * V_9 )
{
struct V_1 * V_2 = F_35 ( V_9 ) ;
F_8 ( & V_9 -> V_14 , L_26 , V_15 ) ;
F_36 ( V_2 -> V_81 ) ;
V_2 -> V_19 . V_51 . V_93 = NULL ;
V_2 -> V_19 . V_21 = NULL ;
F_33 ( V_2 ) ;
return 0 ;
}
