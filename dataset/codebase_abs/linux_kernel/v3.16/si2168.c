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
V_4 . args [ 0 ] = 0xa0 ;
V_4 . args [ 1 ] = 0x01 ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 13 ;
break;
case V_29 :
V_4 . args [ 0 ] = 0x90 ;
V_4 . args [ 1 ] = 0x01 ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 9 ;
break;
case V_30 :
V_4 . args [ 0 ] = 0x50 ;
V_4 . args [ 1 ] = 0x01 ;
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
F_8 ( & V_2 -> V_9 -> V_14 , L_3 ,
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
T_2 V_38 , V_27 ;
F_8 ( & V_2 -> V_9 -> V_14 ,
L_4 ,
V_15 , V_23 -> V_27 , V_23 -> V_39 ,
V_23 -> V_40 , V_23 -> V_41 , V_23 -> V_42 ,
V_23 -> V_43 ) ;
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
if ( V_23 -> V_41 <= 5000000 )
V_38 = 0x05 ;
else if ( V_23 -> V_41 <= 6000000 )
V_38 = 0x06 ;
else if ( V_23 -> V_41 <= 7000000 )
V_38 = 0x07 ;
else if ( V_23 -> V_41 <= 8000000 )
V_38 = 0x08 ;
else if ( V_23 -> V_41 <= 9000000 )
V_38 = 0x09 ;
else if ( V_23 -> V_41 <= 10000000 )
V_38 = 0x0a ;
else
V_38 = 0x0f ;
if ( V_19 -> V_44 . V_45 . V_46 ) {
V_5 = V_19 -> V_44 . V_45 . V_46 ( V_19 ) ;
if ( V_5 )
goto V_17;
}
memcpy ( V_4 . args , L_5 , 5 ) ;
V_4 . V_8 = 5 ;
V_4 . V_12 = 5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
if ( V_23 -> V_27 == V_28 )
memcpy ( V_4 . args , L_6 , 6 ) ;
else if ( V_23 -> V_27 == V_29 )
memcpy ( V_4 . args , L_7 , 6 ) ;
else if ( V_23 -> V_27 == V_30 )
memcpy ( V_4 . args , L_8 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_9 , 2 ) ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 12 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_10 , 3 ) ;
V_4 . V_8 = 3 ;
V_4 . V_12 = 3 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_11 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_12 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_13 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_14 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_15 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_16 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_17 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_18 , 6 ) ;
V_4 . args [ 4 ] = V_27 | V_38 ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_19 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_20 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_21 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_22 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_23 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_24 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_25 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_26 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_27 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_28 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_29 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_30 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_31 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_32 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_33 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
memcpy ( V_4 . args , L_34 , 6 ) ;
V_4 . V_8 = 6 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0x85 ;
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
int V_5 , V_47 , V_48 ;
const struct V_49 * V_50 = NULL ;
T_2 * V_51 = V_52 ;
const unsigned int V_53 = 8 ;
struct V_3 V_4 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_35 , V_15 ) ;
V_4 . args [ 0 ] = 0x13 ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0xc0 ;
V_4 . args [ 1 ] = 0x12 ;
V_4 . args [ 2 ] = 0x00 ;
V_4 . args [ 3 ] = 0x0c ;
V_4 . args [ 4 ] = 0x00 ;
V_4 . args [ 5 ] = 0x0d ;
V_4 . args [ 6 ] = 0x16 ;
V_4 . args [ 7 ] = 0x00 ;
V_4 . args [ 8 ] = 0x00 ;
V_4 . args [ 9 ] = 0x00 ;
V_4 . args [ 10 ] = 0x00 ;
V_4 . args [ 11 ] = 0x00 ;
V_4 . args [ 12 ] = 0x00 ;
V_4 . V_8 = 13 ;
V_4 . V_12 = 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0xc0 ;
V_4 . args [ 1 ] = 0x06 ;
V_4 . args [ 2 ] = 0x01 ;
V_4 . args [ 3 ] = 0x0f ;
V_4 . args [ 4 ] = 0x00 ;
V_4 . args [ 5 ] = 0x20 ;
V_4 . args [ 6 ] = 0x20 ;
V_4 . args [ 7 ] = 0x01 ;
V_4 . V_8 = 8 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_4 . args [ 0 ] = 0x02 ;
V_4 . V_8 = 1 ;
V_4 . V_12 = 13 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
F_14 ( & V_2 -> V_9 -> V_14 , L_36 ,
V_54 , V_55 . V_56 . V_57 ) ;
V_5 = F_15 ( & V_50 , V_51 , & V_2 -> V_9 -> V_14 ) ;
if ( V_5 ) {
F_16 ( & V_2 -> V_9 -> V_14 , L_37 ,
V_54 , V_51 ) ;
goto V_17;
}
F_14 ( & V_2 -> V_9 -> V_14 , L_38 ,
V_54 , V_51 ) ;
for ( V_48 = V_50 -> V_58 ; V_48 > 0 ; V_48 -= V_53 ) {
V_47 = V_48 ;
if ( V_47 > V_53 )
V_47 = V_53 ;
memcpy ( V_4 . args , & V_50 -> V_59 [ V_50 -> V_58 - V_48 ] , V_47 ) ;
V_4 . V_8 = V_47 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 ) {
F_16 ( & V_2 -> V_9 -> V_14 ,
L_39 ,
V_54 , V_5 ) ;
goto V_17;
}
}
F_17 ( V_50 ) ;
V_50 = NULL ;
V_4 . args [ 0 ] = 0x01 ;
V_4 . args [ 1 ] = 0x01 ;
V_4 . V_8 = 2 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
F_14 ( & V_2 -> V_9 -> V_14 , L_40 ,
V_54 , V_55 . V_56 . V_57 ) ;
V_2 -> V_25 = true ;
return 0 ;
V_17:
if ( V_50 )
F_17 ( V_50 ) ;
F_8 ( & V_2 -> V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
F_8 ( & V_2 -> V_9 -> V_14 , L_35 , V_15 ) ;
V_2 -> V_25 = false ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 ,
struct V_60 * V_2 )
{
V_2 -> V_61 = 900 ;
return 0 ;
}
static int F_20 ( struct V_62 * V_63 , void * V_64 , T_3 V_65 )
{
struct V_1 * V_2 = V_64 ;
int V_5 ;
struct V_66 V_67 = {
. V_68 = V_2 -> V_9 -> V_68 ,
. V_69 = 0 ,
. V_47 = 3 ,
. V_70 = L_41 ,
} ;
F_2 ( & V_2 -> V_7 ) ;
V_5 = F_21 ( V_2 -> V_9 -> V_71 , & V_67 , 1 ) ;
if ( V_5 != 1 ) {
F_22 ( & V_2 -> V_9 -> V_14 , L_42 ,
V_54 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
static int F_23 ( struct V_62 * V_63 , void * V_64 , T_3 V_65 )
{
struct V_1 * V_2 = V_64 ;
int V_5 ;
struct V_66 V_72 = {
. V_68 = V_2 -> V_9 -> V_68 ,
. V_69 = 0 ,
. V_47 = 3 ,
. V_70 = L_43 ,
} ;
V_5 = F_21 ( V_2 -> V_9 -> V_71 , & V_72 , 1 ) ;
if ( V_5 != 1 ) {
F_22 ( & V_2 -> V_9 -> V_14 , L_42 ,
V_54 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_11 ;
} else {
V_5 = 0 ;
}
F_10 ( & V_2 -> V_7 ) ;
return V_5 ;
}
static int F_24 ( struct V_73 * V_9 ,
const struct V_74 * V_75 )
{
struct V_76 * V_77 = V_9 -> V_14 . V_78 ;
struct V_1 * V_2 ;
int V_5 ;
struct V_3 V_4 ;
F_8 ( & V_9 -> V_14 , L_35 , V_15 ) ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_2 ) {
V_5 = - V_80 ;
F_16 ( & V_9 -> V_14 , L_44 , V_54 ) ;
goto V_17;
}
V_2 -> V_9 = V_9 ;
F_26 ( & V_2 -> V_7 ) ;
V_4 . V_8 = 0 ;
V_4 . V_12 = 1 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_17;
V_2 -> V_71 = F_27 ( V_9 -> V_71 , & V_9 -> V_14 , V_2 ,
0 , 0 , 0 , F_20 , F_23 ) ;
if ( V_2 -> V_71 == NULL )
goto V_17;
memcpy ( & V_2 -> V_19 . V_44 , & V_55 , sizeof( struct V_81 ) ) ;
V_2 -> V_19 . V_21 = V_2 ;
* V_77 -> V_62 = V_2 -> V_71 ;
* V_77 -> V_19 = & V_2 -> V_19 ;
F_28 ( V_9 , V_2 ) ;
F_14 ( & V_2 -> V_9 -> V_14 ,
L_45 ,
V_54 ) ;
return 0 ;
V_17:
F_29 ( V_2 ) ;
F_8 ( & V_9 -> V_14 , L_2 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_30 ( struct V_73 * V_9 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
F_8 ( & V_9 -> V_14 , L_35 , V_15 ) ;
F_32 ( V_2 -> V_71 ) ;
V_2 -> V_19 . V_44 . V_82 = NULL ;
V_2 -> V_19 . V_21 = NULL ;
F_29 ( V_2 ) ;
return 0 ;
}
