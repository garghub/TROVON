static int F_1 ( const struct V_1 * V_2 ,
const char * V_3 , int V_4 )
{
int V_5 ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
. V_10 = V_4 ,
. V_3 = ( char * ) V_3 ,
} ;
V_5 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
return ( V_5 == 1 ) ? V_4 : V_5 ;
}
static int F_3 ( const struct V_1 * V_2 ,
char * V_3 , int V_4 )
{
int V_5 ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 ,
. V_9 = V_12 ,
. V_10 = V_4 ,
. V_3 = V_3 ,
} ;
V_5 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
return ( V_5 == 1 ) ? V_4 : V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_5 ;
unsigned long V_15 ;
if ( V_14 -> V_16 ) {
V_5 = F_1 ( V_2 , V_14 -> args ,
V_14 -> V_16 ) ;
if ( V_5 < 0 ) {
goto V_17;
} else if ( V_5 != V_14 -> V_16 ) {
V_5 = - V_18 ;
goto V_17;
}
}
if ( V_14 -> V_19 ) {
#define F_5 70
V_15 = V_20 + F_6 ( F_5 ) ;
while ( ! F_7 ( V_20 , V_15 ) ) {
V_5 = F_3 ( V_2 , V_14 -> args ,
V_14 -> V_19 ) ;
if ( V_5 < 0 ) {
goto V_17;
} else if ( V_5 != V_14 -> V_19 ) {
V_5 = - V_18 ;
goto V_17;
}
if ( ( V_14 -> args [ 0 ] >> 7 ) & 0x01 )
break;
}
F_8 ( & V_2 -> V_21 , L_1 ,
F_9 ( V_20 ) -
( F_9 ( V_15 ) - F_5 ) ) ;
if ( ( V_14 -> args [ 0 ] >> 6 ) & 0x01 ) {
V_5 = - V_18 ;
goto V_17;
}
if ( ! ( ( V_14 -> args [ 0 ] >> 7 ) & 0x01 ) ) {
V_5 = - V_22 ;
goto V_17;
}
}
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_5 ;
F_11 ( V_2 -> V_11 ) ;
V_5 = F_4 ( V_2 , V_14 ) ;
F_12 ( V_2 -> V_11 ) ;
return V_5 ;
}
static int F_13 ( struct V_23 * V_24 , enum V_25 * V_26 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_21 = F_14 ( V_2 ) ;
struct V_29 * V_30 = & V_24 -> V_31 ;
int V_5 ;
struct V_13 V_14 ;
* V_26 = 0 ;
if ( ! V_21 -> V_32 ) {
V_5 = - V_33 ;
goto V_17;
}
switch ( V_30 -> V_34 ) {
case V_35 :
memcpy ( V_14 . args , L_3 , 2 ) ;
V_14 . V_16 = 2 ;
V_14 . V_19 = 13 ;
break;
case V_36 :
memcpy ( V_14 . args , L_4 , 2 ) ;
V_14 . V_16 = 2 ;
V_14 . V_19 = 9 ;
break;
case V_37 :
memcpy ( V_14 . args , L_5 , 2 ) ;
V_14 . V_16 = 2 ;
V_14 . V_19 = 14 ;
break;
default:
V_5 = - V_38 ;
goto V_17;
}
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
switch ( ( V_14 . args [ 2 ] >> 1 ) & 0x03 ) {
case 0x01 :
* V_26 = V_39 | V_40 ;
break;
case 0x03 :
* V_26 = V_39 | V_40 | V_41 |
V_42 | V_43 ;
break;
}
V_21 -> V_25 = * V_26 ;
if ( * V_26 & V_43 ) {
V_30 -> V_44 . V_10 = 1 ;
V_30 -> V_44 . V_45 [ 0 ] . V_46 = V_47 ;
V_30 -> V_44 . V_45 [ 0 ] . V_48 = V_14 . args [ 3 ] * 1000 / 4 ;
} else {
V_30 -> V_44 . V_10 = 1 ;
V_30 -> V_44 . V_45 [ 0 ] . V_46 = V_49 ;
}
F_8 ( & V_2 -> V_21 , L_6 ,
* V_26 , V_14 . V_19 , V_14 . args ) ;
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_21 = F_14 ( V_2 ) ;
struct V_29 * V_30 = & V_24 -> V_31 ;
int V_5 ;
struct V_13 V_14 ;
T_1 V_50 , V_34 ;
F_8 ( & V_2 -> V_21 ,
L_7 ,
V_30 -> V_34 , V_30 -> V_51 , V_30 -> V_52 ,
V_30 -> V_53 , V_30 -> V_54 , V_30 -> V_55 ,
V_30 -> V_56 ) ;
if ( ! V_21 -> V_32 ) {
V_5 = - V_33 ;
goto V_17;
}
switch ( V_30 -> V_34 ) {
case V_35 :
V_34 = 0x20 ;
break;
case V_36 :
V_34 = 0x30 ;
break;
case V_37 :
V_34 = 0x70 ;
break;
default:
V_5 = - V_38 ;
goto V_17;
}
if ( V_30 -> V_53 == 0 ) {
V_5 = - V_38 ;
goto V_17;
} else if ( V_30 -> V_53 <= 2000000 )
V_50 = 0x02 ;
else if ( V_30 -> V_53 <= 5000000 )
V_50 = 0x05 ;
else if ( V_30 -> V_53 <= 6000000 )
V_50 = 0x06 ;
else if ( V_30 -> V_53 <= 7000000 )
V_50 = 0x07 ;
else if ( V_30 -> V_53 <= 8000000 )
V_50 = 0x08 ;
else if ( V_30 -> V_53 <= 9000000 )
V_50 = 0x09 ;
else if ( V_30 -> V_53 <= 10000000 )
V_50 = 0x0a ;
else
V_50 = 0x0f ;
if ( V_24 -> V_57 . V_58 . V_59 ) {
V_5 = V_24 -> V_57 . V_58 . V_59 ( V_24 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_14 . args , L_8 , 5 ) ;
V_14 . V_16 = 5 ;
V_14 . V_19 = 5 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
if ( V_30 -> V_34 == V_35 )
memcpy ( V_14 . args , L_9 , 6 ) ;
else if ( V_30 -> V_34 == V_36 )
memcpy ( V_14 . args , L_10 , 6 ) ;
else if ( V_30 -> V_34 == V_37 )
memcpy ( V_14 . args , L_11 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 3 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
if ( V_30 -> V_34 == V_37 ) {
V_14 . args [ 0 ] = 0x52 ;
V_14 . args [ 1 ] = V_30 -> V_56 & 0xff ;
V_14 . args [ 2 ] = V_30 -> V_56 == V_60 ? 0 : 1 ;
V_14 . V_16 = 3 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_14 . args , L_12 , 2 ) ;
V_14 . V_16 = 2 ;
V_14 . V_19 = 12 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_13 , 3 ) ;
V_14 . V_16 = 3 ;
V_14 . V_19 = 3 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_14 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_15 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_16 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_17 , 6 ) ;
V_14 . args [ 4 ] = V_34 | V_50 ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
if ( V_30 -> V_34 == V_36 ) {
memcpy ( V_14 . args , L_18 , 4 ) ;
V_14 . args [ 4 ] = ( ( V_30 -> V_54 / 1000 ) >> 0 ) & 0xff ;
V_14 . args [ 5 ] = ( ( V_30 -> V_54 / 1000 ) >> 8 ) & 0xff ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_14 . args , L_19 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_20 , 6 ) ;
V_14 . args [ 5 ] |= V_21 -> V_61 ? 0x00 : 0x10 ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_21 , 6 ) ;
V_14 . args [ 5 ] |= V_21 -> V_61 ? 0x00 : 0x10 ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_22 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_23 , 6 ) ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_24 , 1 ) ;
V_14 . V_16 = 1 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
V_21 -> V_34 = V_30 -> V_34 ;
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_21 = F_14 ( V_2 ) ;
int V_5 , V_10 , V_62 ;
const struct V_63 * V_64 ;
const char * V_65 ;
struct V_13 V_14 ;
unsigned int V_66 ;
F_8 ( & V_2 -> V_21 , L_25 ) ;
memcpy ( V_14 . args , L_26 , 13 ) ;
V_14 . V_16 = 13 ;
V_14 . V_19 = 0 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
if ( V_21 -> V_67 ) {
memcpy ( V_14 . args , L_27 , 8 ) ;
V_14 . V_16 = 8 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_24 , 1 ) ;
V_14 . V_16 = 1 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
goto V_68;
}
memcpy ( V_14 . args , L_28 , 8 ) ;
V_14 . V_16 = 8 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_29 , 1 ) ;
V_14 . V_16 = 1 ;
V_14 . V_19 = 13 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
V_66 = V_14 . args [ 1 ] << 24 | V_14 . args [ 2 ] << 16 | V_14 . args [ 3 ] << 8 |
V_14 . args [ 4 ] << 0 ;
#define F_17 ('A' << 24 | 68 << 16 | '2' << 8 | '0' << 0)
#define F_18 ('A' << 24 | 68 << 16 | '3' << 8 | '0' << 0)
#define F_19 ('B' << 24 | 68 << 16 | '4' << 8 | '0' << 0)
switch ( V_66 ) {
case F_17 :
V_65 = V_69 ;
break;
case F_18 :
V_65 = V_70 ;
break;
case F_19 :
V_65 = V_71 ;
break;
default:
F_20 ( & V_2 -> V_21 , L_30 ,
V_14 . args [ 2 ] , V_14 . args [ 1 ] ,
V_14 . args [ 3 ] , V_14 . args [ 4 ] ) ;
V_5 = - V_38 ;
goto V_17;
}
F_21 ( & V_2 -> V_21 , L_31 ,
V_14 . args [ 2 ] , V_14 . args [ 1 ] , V_14 . args [ 3 ] , V_14 . args [ 4 ] ) ;
V_5 = F_22 ( & V_64 , V_65 , & V_2 -> V_21 ) ;
if ( V_5 ) {
if ( V_66 == F_19 ) {
V_65 = V_72 ;
V_5 = F_22 ( & V_64 , V_65 , & V_2 -> V_21 ) ;
}
if ( V_5 == 0 ) {
F_23 ( & V_2 -> V_21 ,
L_32 ,
V_71 ) ;
} else {
F_20 ( & V_2 -> V_21 ,
L_33 ,
V_65 ) ;
goto V_73;
}
}
F_21 ( & V_2 -> V_21 , L_34 ,
V_65 ) ;
if ( ( V_64 -> V_74 % 17 == 0 ) && ( V_64 -> V_75 [ 0 ] > 5 ) ) {
for ( V_62 = V_64 -> V_74 ; V_62 > 0 ; V_62 -= 17 ) {
V_10 = V_64 -> V_75 [ V_64 -> V_74 - V_62 ] ;
if ( V_10 > V_76 ) {
V_5 = - V_38 ;
break;
}
memcpy ( V_14 . args , & V_64 -> V_75 [ ( V_64 -> V_74 - V_62 ) + 1 ] , V_10 ) ;
V_14 . V_16 = V_10 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
break;
}
} else if ( V_64 -> V_74 % 8 == 0 ) {
for ( V_62 = V_64 -> V_74 ; V_62 > 0 ; V_62 -= 8 ) {
V_10 = 8 ;
memcpy ( V_14 . args , & V_64 -> V_75 [ V_64 -> V_74 - V_62 ] , V_10 ) ;
V_14 . V_16 = V_10 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
break;
}
} else {
V_5 = - V_38 ;
}
if ( V_5 ) {
F_20 ( & V_2 -> V_21 , L_35 , V_5 ) ;
goto V_73;
}
F_24 ( V_64 ) ;
memcpy ( V_14 . args , L_36 , 2 ) ;
V_14 . V_16 = 2 ;
V_14 . V_19 = 1 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_14 . args , L_37 , 1 ) ;
V_14 . V_16 = 1 ;
V_14 . V_19 = 10 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
F_21 ( & V_2 -> V_21 , L_38 ,
V_14 . args [ 6 ] , V_14 . args [ 7 ] , V_14 . args [ 8 ] ) ;
memcpy ( V_14 . args , L_39 , 6 ) ;
V_14 . args [ 4 ] |= V_21 -> V_77 ;
if ( V_21 -> V_78 )
V_14 . args [ 4 ] |= 0x40 ;
V_14 . V_16 = 6 ;
V_14 . V_19 = 4 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
V_21 -> V_67 = true ;
V_68:
V_21 -> V_32 = true ;
return 0 ;
V_73:
F_24 ( V_64 ) ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_21 = F_14 ( V_2 ) ;
int V_5 ;
struct V_13 V_14 ;
F_8 ( & V_2 -> V_21 , L_25 ) ;
V_21 -> V_32 = false ;
memcpy ( V_14 . args , L_40 , 1 ) ;
V_14 . V_16 = 1 ;
V_14 . V_19 = 0 ;
V_5 = F_10 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_79 * V_80 )
{
V_80 -> V_81 = 900 ;
return 0 ;
}
static int F_27 ( struct V_82 * V_83 , void * V_84 , T_2 V_85 )
{
struct V_1 * V_2 = V_84 ;
int V_5 ;
struct V_13 V_14 ;
memcpy ( V_14 . args , L_41 , 3 ) ;
V_14 . V_16 = 3 ;
V_14 . V_19 = 0 ;
V_5 = F_4 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_28 ( struct V_82 * V_83 , void * V_84 , T_2 V_85 )
{
struct V_1 * V_2 = V_84 ;
int V_5 ;
struct V_13 V_14 ;
memcpy ( V_14 . args , L_42 , 3 ) ;
V_14 . V_16 = 3 ;
V_14 . V_19 = 0 ;
V_5 = F_4 ( V_2 , & V_14 ) ;
if ( V_5 )
goto V_17;
return 0 ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_86 * V_87 )
{
struct V_88 * V_89 = V_2 -> V_21 . V_90 ;
struct V_28 * V_21 ;
int V_5 ;
F_8 ( & V_2 -> V_21 , L_25 ) ;
V_21 = F_30 ( sizeof( * V_21 ) , V_91 ) ;
if ( ! V_21 ) {
V_5 = - V_92 ;
F_20 ( & V_2 -> V_21 , L_43 ) ;
goto V_17;
}
V_21 -> V_11 = F_31 ( V_2 -> V_11 , & V_2 -> V_21 ,
V_2 , 0 , 0 , 0 , F_27 , F_28 ) ;
if ( V_21 -> V_11 == NULL ) {
V_5 = - V_93 ;
goto V_94;
}
memcpy ( & V_21 -> V_24 . V_57 , & V_95 , sizeof( struct V_96 ) ) ;
V_21 -> V_24 . V_27 = V_2 ;
* V_89 -> V_82 = V_21 -> V_11 ;
* V_89 -> V_24 = & V_21 -> V_24 ;
V_21 -> V_77 = V_89 -> V_77 ;
V_21 -> V_61 = V_89 -> V_61 ;
V_21 -> V_78 = V_89 -> V_78 ;
V_21 -> V_67 = false ;
F_32 ( V_2 , V_21 ) ;
F_21 ( & V_2 -> V_21 , L_44 ) ;
return 0 ;
V_94:
F_33 ( V_21 ) ;
V_17:
F_8 ( & V_2 -> V_21 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_28 * V_21 = F_14 ( V_2 ) ;
F_8 ( & V_2 -> V_21 , L_25 ) ;
F_35 ( V_21 -> V_11 ) ;
V_21 -> V_24 . V_57 . V_97 = NULL ;
V_21 -> V_24 . V_27 = NULL ;
F_33 ( V_21 ) ;
return 0 ;
}
