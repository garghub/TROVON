static T_1 F_1 ( const T_2 * V_1 , T_3 V_2 )
{
T_3 V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 1 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_3 % 2 )
V_4 += V_1 [ V_3 ] << 8 ;
else
V_4 += V_1 [ V_3 ] ;
}
V_4 = ~ V_4 ;
return V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
#define F_3 4
#define F_4 3
#define F_5 2
#define F_6 2000
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_13 , V_14 ;
T_1 V_4 , V_15 ;
F_8 ( & V_6 -> V_16 ) ;
if ( V_8 -> V_13 > ( V_17 - F_3 - F_5 ) ||
V_8 -> V_14 > ( V_17 - F_4 - F_5 ) ) {
F_9 ( & V_11 -> V_18 , L_1 ,
V_8 -> V_13 , V_8 -> V_14 ) ;
V_12 = - V_19 ;
goto exit;
}
V_9 -> V_1 [ 0 ] = F_3 + V_8 -> V_13 + F_5 - 1 ;
V_9 -> V_1 [ 1 ] = V_8 -> V_20 ;
V_9 -> V_1 [ 2 ] = V_8 -> V_21 ;
V_9 -> V_1 [ 3 ] = V_9 -> V_22 ++ ;
memcpy ( & V_9 -> V_1 [ F_3 ] , V_8 -> V_23 , V_8 -> V_13 ) ;
V_13 = F_3 + V_8 -> V_13 + F_5 ;
V_14 = F_4 + V_8 -> V_14 + F_5 ;
V_4 = F_1 ( V_9 -> V_1 , V_9 -> V_1 [ 0 ] - 1 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 1 ] = ( V_4 >> 8 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 0 ] = ( V_4 & 0xff ) ;
if ( V_8 -> V_21 == V_24 )
V_14 = 0 ;
V_12 = F_10 ( V_6 ,
V_9 -> V_1 , V_13 , V_9 -> V_1 , V_14 ) ;
if ( V_12 )
goto exit;
if ( V_8 -> V_21 == V_24 )
goto exit;
V_4 = F_1 ( V_9 -> V_1 , V_14 - 2 ) ;
V_15 = ( V_9 -> V_1 [ V_14 - 2 ] << 8 ) | V_9 -> V_1 [ V_14 - 1 ] ;
if ( V_15 != V_4 ) {
F_9 ( & V_11 -> V_18 , L_2 ,
V_8 -> V_21 , V_15 , V_4 ) ;
V_12 = - V_25 ;
goto exit;
}
if ( V_9 -> V_1 [ 2 ] ) {
if ( V_8 -> V_21 == V_26 || V_9 -> V_1 [ 2 ] == 1 ) {
V_12 = 1 ;
goto exit;
}
F_11 ( & V_11 -> V_18 , L_3 ,
V_8 -> V_21 , V_9 -> V_1 [ 2 ] ) ;
V_12 = - V_25 ;
goto exit;
}
if ( V_8 -> V_14 )
memcpy ( V_8 -> V_27 , & V_9 -> V_1 [ F_4 ] , V_8 -> V_14 ) ;
exit:
F_12 ( & V_6 -> V_16 ) ;
if ( V_12 < 0 )
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_13 ( struct V_5 * V_6 , T_4 V_28 , T_2 * V_29 , int V_2 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_2 V_23 [ V_30 ] ;
T_2 V_20 = ( V_28 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_31 , V_20 , 6 + V_2 , V_23 , 0 , NULL } ;
if ( 6 + V_2 > sizeof( V_23 ) ) {
F_14 ( & V_11 -> V_18 , L_5 , V_2 ) ;
return - V_32 ;
}
V_23 [ 0 ] = V_2 ;
V_23 [ 1 ] = 2 ;
V_23 [ 2 ] = 0 ;
V_23 [ 3 ] = 0 ;
V_23 [ 4 ] = ( V_28 >> 8 ) & 0xff ;
V_23 [ 5 ] = ( V_28 >> 0 ) & 0xff ;
memcpy ( & V_23 [ 6 ] , V_29 , V_2 ) ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_15 ( struct V_5 * V_6 , T_4 V_28 , T_2 * V_29 , int V_2 )
{
T_2 V_23 [] = { V_2 , 2 , 0 , 0 , ( V_28 >> 8 ) & 0xff , V_28 & 0xff } ;
T_2 V_20 = ( V_28 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_33 , V_20 , sizeof( V_23 ) , V_23 , V_2 , V_29 } ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_4 V_28 , T_2 V_29 )
{
return F_13 ( V_6 , V_28 , & V_29 , 1 ) ;
}
static int F_17 ( struct V_5 * V_6 , T_4 V_28 , T_2 * V_29 )
{
return F_15 ( V_6 , V_28 , V_29 , 1 ) ;
}
static int F_18 ( struct V_5 * V_6 , T_4 V_28 , T_2 V_29 ,
T_2 V_34 )
{
int V_12 ;
T_2 V_35 ;
if ( V_34 != 0xff ) {
V_12 = F_15 ( V_6 , V_28 , & V_35 , 1 ) ;
if ( V_12 )
return V_12 ;
V_29 &= V_34 ;
V_35 &= ~ V_34 ;
V_29 |= V_35 ;
}
return F_13 ( V_6 , V_28 , & V_29 , 1 ) ;
}
static int F_19 ( struct V_5 * V_6 , const char * type ,
T_2 V_36 , void * V_37 , struct V_38 * V_39 )
{
int V_12 , V_40 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_41 * V_42 ;
struct V_43 V_44 = {
. V_36 = V_36 ,
. V_37 = V_37 ,
} ;
F_20 ( V_44 . type , type , V_45 ) ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
if ( V_9 -> V_41 [ V_40 ] == NULL )
break;
}
F_11 ( & V_11 -> V_18 , L_6 , V_40 ) ;
if ( V_40 == V_46 ) {
F_9 ( & V_11 -> V_18 , L_7 ) ;
V_12 = - V_47 ;
goto V_48;
}
F_21 ( L_8 , V_44 . type ) ;
V_42 = F_22 ( V_39 , & V_44 ) ;
if ( V_42 == NULL || V_42 -> V_18 . V_49 == NULL ) {
V_12 = - V_47 ;
goto V_48;
}
if ( ! F_23 ( V_42 -> V_18 . V_49 -> V_50 ) ) {
F_24 ( V_42 ) ;
V_12 = - V_47 ;
goto V_48;
}
V_9 -> V_41 [ V_40 ] = V_42 ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static void F_25 ( struct V_5 * V_6 )
{
int V_40 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_41 * V_42 ;
V_40 = V_46 ;
while ( V_40 -- ) {
if ( V_9 -> V_41 [ V_40 ] != NULL )
break;
}
F_11 ( & V_11 -> V_18 , L_6 , V_40 ) ;
if ( V_40 == - 1 ) {
F_9 ( & V_11 -> V_18 , L_7 ) ;
goto V_48;
}
V_42 = V_9 -> V_41 [ V_40 ] ;
F_26 ( V_42 -> V_18 . V_49 -> V_50 ) ;
F_24 ( V_42 ) ;
V_9 -> V_41 [ V_40 ] = NULL ;
return;
V_48:
F_11 ( & V_11 -> V_18 , L_9 ) ;
}
static int F_27 ( struct V_38 * V_51 ,
struct V_52 V_53 [] , int V_40 )
{
struct V_5 * V_6 = F_28 ( V_51 ) ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_12 ;
if ( F_29 ( & V_6 -> V_54 ) < 0 )
return - V_55 ;
#define F_30 ( T_5 , T_6 ) \
(_num == 2 && !(_msg[0].flags & I2C_M_RD) && (_msg[1].flags & I2C_M_RD))
#define F_31 ( T_5 , T_6 ) \
(_num == 1 && !(_msg[0].flags & I2C_M_RD))
#define F_32 ( T_5 , T_6 ) \
(_num == 1 && (_msg[0].flags & I2C_M_RD))
if ( F_30 ( V_53 , V_40 ) ) {
if ( V_53 [ 0 ] . V_2 > 40 || V_53 [ 1 ] . V_2 > 40 ) {
V_12 = - V_32 ;
} else if ( ( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 0 ] ) ||
( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 1 ] ) ) {
T_4 V_28 = V_53 [ 0 ] . V_1 [ 0 ] << 16 | V_53 [ 0 ] . V_1 [ 1 ] << 8 |
V_53 [ 0 ] . V_1 [ 2 ] ;
if ( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 1 ] )
V_28 |= 0x100000 ;
V_12 = F_15 ( V_6 , V_28 , & V_53 [ 1 ] . V_1 [ 0 ] ,
V_53 [ 1 ] . V_2 ) ;
} else if ( V_9 -> V_57 ) {
memset ( V_53 [ 1 ] . V_1 , 0 , V_53 [ 1 ] . V_2 ) ;
V_12 = 0 ;
} else {
T_2 V_1 [ V_30 ] ;
struct V_7 V_8 = { V_58 , 0 , 5 + V_53 [ 0 ] . V_2 ,
V_1 , V_53 [ 1 ] . V_2 , V_53 [ 1 ] . V_1 } ;
if ( V_9 -> V_59 == 0x9306 ) {
V_8 . V_21 = V_60 ;
V_8 . V_13 = 3 + V_53 [ 0 ] . V_2 ;
}
V_8 . V_20 |= ( ( V_53 [ 0 ] . V_36 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_53 [ 1 ] . V_2 ;
if ( V_9 -> V_59 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_53 [ 0 ] . V_36 << 1 ;
memcpy ( & V_1 [ 3 ] , V_53 [ 0 ] . V_1 , V_53 [ 0 ] . V_2 ) ;
} else {
V_1 [ 1 ] = V_53 [ 0 ] . V_36 << 1 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
if ( V_53 [ 0 ] . V_2 > 2 ) {
V_1 [ 2 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_53 [ 0 ] . V_1 , V_53 [ 0 ] . V_2 ) ;
} else {
V_8 . V_13 = 5 ;
V_1 [ 2 ] = V_53 [ 0 ] . V_2 ;
if ( V_53 [ 0 ] . V_2 == 2 ) {
V_1 [ 3 ] = V_53 [ 0 ] . V_1 [ 0 ] ;
V_1 [ 4 ] = V_53 [ 0 ] . V_1 [ 1 ] ;
} else if ( V_53 [ 0 ] . V_2 == 1 ) {
V_1 [ 4 ] = V_53 [ 0 ] . V_1 [ 0 ] ;
}
}
}
V_12 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( F_31 ( V_53 , V_40 ) ) {
if ( V_53 [ 0 ] . V_2 > 40 ) {
V_12 = - V_32 ;
} else if ( ( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 0 ] ) ||
( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 1 ] ) ) {
T_4 V_28 = V_53 [ 0 ] . V_1 [ 0 ] << 16 | V_53 [ 0 ] . V_1 [ 1 ] << 8 |
V_53 [ 0 ] . V_1 [ 2 ] ;
if ( V_53 [ 0 ] . V_36 == V_9 -> V_56 [ 1 ] )
V_28 |= 0x100000 ;
V_12 = F_13 ( V_6 , V_28 , & V_53 [ 0 ] . V_1 [ 3 ] ,
V_53 [ 0 ] . V_2 - 3 ) ;
} else {
T_2 V_1 [ V_30 ] ;
struct V_7 V_8 = { V_61 , 0 , 5 + V_53 [ 0 ] . V_2 ,
V_1 , 0 , NULL } ;
if ( V_9 -> V_59 == 0x9306 ) {
V_8 . V_21 = V_62 ;
V_8 . V_13 = 3 + V_53 [ 0 ] . V_2 ;
}
V_8 . V_20 |= ( ( V_53 [ 0 ] . V_36 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_53 [ 0 ] . V_2 ;
if ( V_9 -> V_59 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_53 [ 0 ] . V_36 << 1 ;
memcpy ( & V_1 [ 3 ] , V_53 [ 0 ] . V_1 , V_53 [ 0 ] . V_2 ) ;
} else {
V_1 [ 1 ] = V_53 [ 0 ] . V_36 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_53 [ 0 ] . V_1 , V_53 [ 0 ] . V_2 ) ;
}
V_12 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( F_32 ( V_53 , V_40 ) ) {
if ( V_53 [ 0 ] . V_2 > 40 ) {
V_12 = - V_32 ;
} else if ( V_9 -> V_57 ) {
memset ( V_53 [ 0 ] . V_1 , 0 , V_53 [ 0 ] . V_2 ) ;
V_12 = 0 ;
} else {
T_2 V_1 [ 5 ] ;
struct V_7 V_8 = { V_58 , 0 , sizeof( V_1 ) ,
V_1 , V_53 [ 0 ] . V_2 , V_53 [ 0 ] . V_1 } ;
if ( V_9 -> V_59 == 0x9306 ) {
V_8 . V_21 = V_60 ;
V_8 . V_13 = 3 ;
}
V_8 . V_20 |= ( ( V_53 [ 0 ] . V_36 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_53 [ 0 ] . V_2 ;
if ( V_9 -> V_59 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_53 [ 0 ] . V_36 << 1 ;
} else {
V_1 [ 1 ] = V_53 [ 0 ] . V_36 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
}
V_12 = F_2 ( V_6 , & V_8 ) ;
}
} else {
V_12 = - V_32 ;
}
F_12 ( & V_6 -> V_54 ) ;
if ( V_12 < 0 )
return V_12 ;
else
return V_40 ;
}
static T_4 F_33 ( struct V_38 * V_39 )
{
return V_63 ;
}
static int F_34 ( struct V_5 * V_6 , const char * * V_64 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_3 , V_65 ;
unsigned int V_66 , V_67 ;
T_2 V_35 ;
T_2 V_23 [ 1 ] = { 1 } ;
T_2 V_27 [ 4 ] ;
struct V_7 V_8 = { V_68 , 0 , sizeof( V_23 ) , V_23 ,
sizeof( V_27 ) , V_27 } ;
V_12 = F_15 ( V_6 , 0x1222 , V_27 , 3 ) ;
if ( V_12 < 0 )
goto V_48;
V_9 -> V_69 = V_27 [ 0 ] ;
V_9 -> V_59 = V_27 [ 2 ] << 8 | V_27 [ 1 ] << 0 ;
V_12 = F_17 ( V_6 , 0x384f , & V_9 -> V_70 ) ;
if ( V_12 < 0 )
goto V_48;
F_35 ( & V_11 -> V_18 , L_10 ,
V_9 -> V_70 , V_9 -> V_69 , V_9 -> V_59 ) ;
if ( V_9 -> V_59 == 0x9135 ) {
if ( V_9 -> V_69 == 0x02 ) {
* V_64 = V_71 ;
V_66 = 0x00461d ;
} else {
* V_64 = V_72 ;
V_66 = 0x00461b ;
}
V_12 = F_17 ( V_6 , V_66 , & V_35 ) ;
if ( V_12 < 0 )
goto V_48;
if ( V_35 == 0x00 ) {
F_11 ( & V_11 -> V_18 , L_11 ) ;
V_9 -> V_73 = true ;
goto V_74;
}
V_67 = V_75 ;
} else if ( V_9 -> V_59 == 0x9306 ) {
* V_64 = V_76 ;
V_9 -> V_73 = true ;
goto V_74;
} else {
* V_64 = V_77 ;
V_67 = V_78 ;
}
for ( V_3 = 0 ; V_3 < 256 ; V_3 += 32 ) {
V_12 = F_15 ( V_6 , V_67 + V_3 , & V_9 -> V_79 [ V_3 ] , 32 ) ;
if ( V_12 < 0 )
goto V_48;
}
F_11 ( & V_11 -> V_18 , L_12 ) ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 += 16 )
F_11 ( & V_11 -> V_18 , L_13 , 16 , & V_9 -> V_79 [ V_3 ] ) ;
V_35 = V_9 -> V_79 [ V_80 ] ;
V_65 = 0 ;
switch ( V_35 ) {
case 0 :
break;
case 1 :
case 3 :
V_9 -> V_81 = true ;
break;
case 5 :
if ( V_9 -> V_59 != 0x9135 && V_9 -> V_59 != 0x9306 )
V_9 -> V_81 = true ;
else
V_65 = 1 ;
break;
default:
V_65 = 1 ;
}
F_11 ( & V_11 -> V_18 , L_14 , V_35 , V_9 -> V_81 ) ;
if ( V_65 )
F_35 ( & V_11 -> V_18 , L_15 , V_35 ) ;
V_74:
V_12 = F_2 ( V_6 , & V_8 ) ;
if ( V_12 < 0 )
goto V_48;
F_11 ( & V_11 -> V_18 , L_16 , 4 , V_27 ) ;
if ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] )
V_12 = V_82 ;
else
V_12 = V_83 ;
return V_12 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_36 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_3 , V_86 , V_2 ;
T_2 V_23 [ 1 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_87 = { V_24 , 0 , 0 , V_23 , 0 , NULL } ;
T_2 V_88 ;
T_1 V_89 , V_90 , V_91 ;
#define F_37 58
#define F_38 7
for ( V_3 = V_85 -> V_92 ; V_3 > F_38 ; ) {
V_88 = V_85 -> V_93 [ V_85 -> V_92 - V_3 + 0 ] ;
V_89 = V_85 -> V_93 [ V_85 -> V_92 - V_3 + 1 ] << 8 ;
V_89 |= V_85 -> V_93 [ V_85 -> V_92 - V_3 + 2 ] << 0 ;
V_90 = V_85 -> V_93 [ V_85 -> V_92 - V_3 + 3 ] << 8 ;
V_90 |= V_85 -> V_93 [ V_85 -> V_92 - V_3 + 4 ] << 0 ;
V_91 = V_85 -> V_93 [ V_85 -> V_92 - V_3 + 5 ] << 8 ;
V_91 |= V_85 -> V_93 [ V_85 -> V_92 - V_3 + 6 ] << 0 ;
F_11 ( & V_11 -> V_18 , L_17 ,
V_88 , V_89 , V_90 , V_91 ) ;
if ( ( ( V_88 != 1 ) && ( V_88 != 2 ) ) ||
( V_90 > V_3 ) ) {
F_11 ( & V_11 -> V_18 , L_18 ) ;
break;
}
V_8 . V_21 = V_94 ;
V_12 = F_2 ( V_6 , & V_8 ) ;
if ( V_12 < 0 )
goto V_48;
for ( V_86 = F_38 + V_90 ; V_86 > 0 ; V_86 -= F_37 ) {
V_2 = V_86 ;
if ( V_2 > F_37 )
V_2 = F_37 ;
V_87 . V_13 = V_2 ;
V_87 . V_23 = ( T_2 * ) & V_85 -> V_93 [ V_85 -> V_92 - V_3 +
F_38 + V_90 - V_86 ] ;
V_12 = F_2 ( V_6 , & V_87 ) ;
if ( V_12 < 0 )
goto V_48;
}
V_8 . V_21 = V_95 ;
V_12 = F_2 ( V_6 , & V_8 ) ;
if ( V_12 < 0 )
goto V_48;
V_3 -= V_90 + F_38 ;
F_11 ( & V_11 -> V_18 , L_19 , V_85 -> V_92 - V_3 ) ;
}
if ( V_3 )
F_14 ( & V_11 -> V_18 , L_18 ) ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_39 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_3 , V_96 ;
struct V_7 V_87 = { V_97 , 0 , 0 , NULL , 0 , NULL } ;
#define F_38 7
for ( V_3 = F_38 , V_96 = 0 ; V_3 <= V_85 -> V_92 ; V_3 ++ ) {
if ( V_3 == V_85 -> V_92 ||
( V_85 -> V_93 [ V_3 + 0 ] == 0x03 &&
( V_85 -> V_93 [ V_3 + 1 ] == 0x00 ||
V_85 -> V_93 [ V_3 + 1 ] == 0x01 ) &&
V_85 -> V_93 [ V_3 + 2 ] == 0x00 ) ) {
V_87 . V_13 = V_3 - V_96 ;
V_87 . V_23 = ( T_2 * ) & V_85 -> V_93 [ V_96 ] ;
V_96 = V_3 ;
V_12 = F_2 ( V_6 , & V_87 ) ;
if ( V_12 < 0 )
goto V_48;
F_11 ( & V_11 -> V_18 , L_20 , V_3 ) ;
}
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_40 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_12 ;
T_2 V_23 [ 1 ] ;
T_2 V_27 [ 4 ] ;
T_2 V_35 ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_98 = { V_68 , 0 , 1 , V_23 , 4 , V_27 } ;
F_11 ( & V_11 -> V_18 , L_21 ) ;
if ( V_9 -> V_81 ) {
V_12 = F_18 ( V_6 , 0x00d8b0 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d8b1 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d8af , 0x00 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
F_41 ( 10000 , 50000 ) ;
V_12 = F_18 ( V_6 , 0x00d8af , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_35 = V_9 -> V_79 [ V_99 ] ;
if ( ! V_35 )
V_35 = 0x1d << 1 ;
if ( ( V_9 -> V_59 == 0x9135 ) ||
( V_9 -> V_59 == 0x9306 ) ) {
V_12 = F_16 ( V_6 , 0x004bfb , V_35 ) ;
if ( V_12 < 0 )
goto V_48;
} else {
V_12 = F_16 ( V_6 , 0x00417f , V_35 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d81a , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
}
}
if ( V_85 -> V_93 [ 0 ] == 0x01 )
V_12 = F_36 ( V_6 , V_85 ) ;
else
V_12 = F_39 ( V_6 , V_85 ) ;
if ( V_12 < 0 )
goto V_48;
V_8 . V_21 = V_100 ;
V_12 = F_2 ( V_6 , & V_8 ) ;
if ( V_12 < 0 )
goto V_48;
V_23 [ 0 ] = 1 ;
V_12 = F_2 ( V_6 , & V_98 ) ;
if ( V_12 < 0 )
goto V_48;
if ( ! ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] ) ) {
F_9 ( & V_11 -> V_18 , L_22 ) ;
V_12 = - V_47 ;
goto V_48;
}
F_35 ( & V_11 -> V_18 , L_23 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] , V_27 [ 3 ] ) ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_12 , V_3 ;
T_2 V_35 ;
T_1 V_101 ;
V_9 -> V_56 [ 0 ] = 0x1c ;
V_9 -> V_56 [ 1 ] = 0x1d ;
V_9 -> V_102 [ 0 ] . V_103 = V_104 ;
V_9 -> V_102 [ 1 ] . V_103 = V_104 ;
V_9 -> V_102 [ 0 ] . V_105 = V_106 ;
V_9 -> V_102 [ 1 ] . V_105 = V_107 ;
if ( V_9 -> V_59 == 0x9135 ) {
V_9 -> V_102 [ 0 ] . V_108 = true ;
V_9 -> V_102 [ 1 ] . V_108 = true ;
if ( V_9 -> V_69 == 0x02 ) {
V_9 -> V_102 [ 0 ] . V_109 = V_110 ;
V_9 -> V_102 [ 1 ] . V_109 = V_110 ;
} else {
V_9 -> V_102 [ 0 ] . V_109 = V_111 ;
V_9 -> V_102 [ 1 ] . V_109 = V_111 ;
}
if ( V_9 -> V_73 ) {
V_9 -> V_112 = 0x05 ;
V_9 -> V_113 = 0x00 ;
goto V_114;
}
} else if ( V_9 -> V_59 == 0x9306 ) {
return 0 ;
}
V_9 -> V_112 = V_9 -> V_79 [ V_115 ] ;
V_9 -> V_113 = V_9 -> V_79 [ V_116 ] ;
if ( V_9 -> V_81 ) {
V_35 = V_9 -> V_79 [ V_99 ] ;
if ( V_35 )
V_9 -> V_56 [ 1 ] = V_35 >> 1 ;
F_11 ( & V_11 -> V_18 , L_24 ,
V_9 -> V_56 [ 1 ] ) ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_81 + 1 ; V_3 ++ ) {
unsigned int V_117 = 0 ;
V_35 = V_9 -> V_79 [ V_118 + V_117 ] ;
F_11 ( & V_11 -> V_18 , L_25 , V_3 , V_35 ) ;
if ( V_9 -> V_59 == 0x9135 ) {
if ( V_9 -> V_69 == 0x02 ) {
switch ( V_35 ) {
case V_110 :
case V_119 :
case V_120 :
V_9 -> V_102 [ V_3 ] . V_109 = V_35 ;
break;
}
} else {
switch ( V_35 ) {
case V_111 :
case V_121 :
case V_122 :
V_9 -> V_102 [ V_3 ] . V_109 = V_35 ;
break;
}
}
} else {
V_9 -> V_102 [ V_3 ] . V_109 = V_35 ;
}
if ( V_9 -> V_102 [ V_3 ] . V_109 != V_35 ) {
F_35 ( & V_11 -> V_18 , L_26 ,
V_3 , V_35 , V_9 -> V_102 [ V_3 ] . V_109 ) ;
}
switch ( V_9 -> V_102 [ V_3 ] . V_109 ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
V_9 -> V_102 [ V_3 ] . V_129 = 1 ;
break;
case V_111 :
case V_121 :
case V_122 :
case V_110 :
case V_119 :
case V_120 :
break;
default:
F_14 ( & V_11 -> V_18 , L_27 ,
V_35 ) ;
}
if ( V_3 == 1 )
switch ( V_9 -> V_102 [ V_3 ] . V_109 ) {
case V_128 :
case V_111 :
case V_121 :
case V_122 :
case V_110 :
case V_119 :
case V_120 :
case V_125 :
break;
default:
V_9 -> V_81 = false ;
F_35 ( & V_11 -> V_18 , L_28 ) ;
}
V_35 = V_9 -> V_79 [ V_130 + V_117 ] ;
V_101 = V_35 << 0 ;
V_35 = V_9 -> V_79 [ V_131 + V_117 ] ;
V_101 |= V_35 << 8 ;
F_11 ( & V_11 -> V_18 , L_29 , V_3 , V_101 ) ;
V_117 += 0x10 ;
}
V_114:
V_12 = F_17 ( V_6 , 0x00d800 , & V_35 ) ;
if ( V_12 < 0 )
goto V_48;
V_35 = ( V_35 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < F_43 ( V_9 -> V_102 ) ; V_3 ++ ) {
if ( V_9 -> V_59 == 0x9135 )
V_9 -> V_102 [ V_3 ] . clock = V_132 [ V_35 ] ;
else
V_9 -> V_102 [ V_3 ] . clock = V_133 [ V_35 ] ;
}
V_9 -> V_57 = false ;
if ( V_9 -> V_102 [ 0 ] . V_109 == V_125 &&
F_44 ( V_6 -> V_134 -> V_135 . V_136 ) == V_137 )
switch ( F_44 ( V_6 -> V_134 -> V_135 . V_138 ) ) {
case V_139 :
case V_140 :
F_35 ( & V_11 -> V_18 ,
L_30 ) ;
V_9 -> V_57 = true ;
break;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_45 ( struct V_5 * V_6 ,
int V_21 , int V_141 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
T_2 V_29 ;
F_11 ( & V_11 -> V_18 , L_31 , V_21 , V_141 ) ;
switch ( V_21 ) {
case V_142 :
if ( V_141 )
V_29 = 0x00 ;
else
V_29 = 0x01 ;
V_12 = F_18 ( V_6 , 0x00d8e7 , V_29 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
break;
case V_143 :
if ( V_141 )
V_29 = 0x01 ;
else
V_29 = 0x00 ;
V_12 = F_18 ( V_6 , 0x00d8eb , V_29 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
break;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_46 ( struct V_5 * V_6 ,
int V_21 , int V_141 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
switch ( V_21 ) {
case V_144 :
V_12 = F_18 ( V_6 , 0xd8eb , 1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ec , 1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ed , 1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8d0 , 1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8d1 , 1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
F_41 ( 10000 , 50000 ) ;
break;
case V_145 :
V_12 = F_16 ( V_6 , 0xd8e9 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0xd8e8 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0xd8e7 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
F_41 ( 10000 , 20000 ) ;
V_12 = F_16 ( V_6 , 0xd8e7 , 0 ) ;
if ( V_12 < 0 )
goto V_48;
F_41 ( 10000 , 20000 ) ;
break;
default:
V_12 = - V_19 ;
goto V_48;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_47 ( struct V_5 * V_6 , int V_21 , int V_141 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
switch ( V_9 -> V_102 [ 0 ] . V_109 ) {
case V_124 :
return F_46 ( V_6 , V_21 , V_141 ) ;
case V_123 :
return F_45 ( V_6 , V_21 , V_141 ) ;
default:
break;
}
return 0 ;
}
static int F_48 ( void * V_146 , int V_147 ,
int V_21 , int V_141 )
{
struct V_38 * V_51 = V_146 ;
struct V_5 * V_6 = F_28 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_32 ,
V_147 , V_21 , V_141 ) ;
switch ( V_147 ) {
case V_148 :
return F_47 ( V_6 , V_21 , V_141 ) ;
default:
break;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
return V_9 -> V_81 + 1 ;
}
static int F_50 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
if ( ! V_9 -> V_102 [ V_51 -> V_150 ] . V_109 ) {
V_12 = - V_47 ;
goto V_48;
}
V_9 -> V_102 [ V_51 -> V_150 ] . V_151 = & V_51 -> V_151 [ 0 ] ;
V_9 -> V_102 [ V_51 -> V_150 ] . V_152 = & V_9 -> V_152 ;
V_12 = F_19 ( V_6 , L_34 , V_9 -> V_56 [ V_51 -> V_150 ] ,
& V_9 -> V_102 [ V_51 -> V_150 ] , & V_6 -> V_153 ) ;
if ( V_12 )
goto V_48;
if ( V_51 -> V_151 [ 0 ] == NULL ) {
V_12 = - V_47 ;
goto V_48;
}
V_51 -> V_151 [ 0 ] -> V_152 . V_154 = NULL ;
V_51 -> V_151 [ 0 ] -> V_155 = F_48 ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_53 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
struct V_156 V_156 ;
struct V_38 * V_39 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_38 = & V_39 ;
V_156 . V_151 = & V_51 -> V_151 [ 0 ] ;
V_156 . V_105 = V_157 ;
V_9 -> V_102 [ V_51 -> V_150 ] . V_151 = & V_51 -> V_151 [ 0 ] ;
V_9 -> V_102 [ V_51 -> V_150 ] . V_152 = & V_9 -> V_152 ;
V_12 = F_19 ( V_6 , L_35 , 0x67 , & V_156 ,
& V_6 -> V_153 ) ;
if ( V_12 )
goto V_48;
if ( V_51 -> V_151 [ 0 ] == NULL ) {
V_12 = - V_47 ;
goto V_48;
}
V_9 -> V_158 = V_39 ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_54 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
if ( V_51 -> V_150 == 1 ) {
if ( V_9 -> V_41 [ 1 ] )
F_25 ( V_6 ) ;
} else if ( V_51 -> V_150 == 0 ) {
if ( V_9 -> V_41 [ 0 ] )
F_25 ( V_6 ) ;
}
return 0 ;
}
static int F_55 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
struct V_159 * V_151 ;
struct V_52 V_53 [ 1 ] ;
T_2 V_160 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
switch ( V_9 -> V_102 [ V_51 -> V_150 ] . V_109 ) {
case V_123 : {
struct V_161 V_162 = {
. V_159 = V_51 -> V_151 [ 0 ] ,
} ;
V_12 = F_18 ( V_6 , 0x00d8ec , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d8ed , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d8e8 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0x00d8e9 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_19 ( V_6 , L_36 , 0x60 , & V_162 ,
& V_6 -> V_153 ) ;
if ( V_12 )
goto V_48;
V_151 = V_51 -> V_151 [ 0 ] ;
break;
}
case V_124 :
V_151 = F_56 ( V_163 , V_51 -> V_151 [ 0 ] ,
& V_6 -> V_153 , & V_164 ) ;
break;
case V_125 :
if ( V_51 -> V_150 == 0 ) {
V_12 = F_16 ( V_6 , 0x00d8e0 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8e1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8df , 0 ) ;
if ( V_12 < 0 )
goto V_48;
F_57 ( 30 ) ;
V_12 = F_16 ( V_6 , 0x00d8df , 1 ) ;
if ( V_12 < 0 )
goto V_48;
F_57 ( 300 ) ;
V_12 = F_16 ( V_6 , 0x00d8c0 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8c1 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8bf , 0 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8b4 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8b5 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00d8b3 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
V_160 = 0x60 ;
} else {
V_160 = 0x60 | 0x80 ;
}
V_151 = F_56 ( V_165 , V_51 -> V_151 [ 0 ] , & V_6 -> V_153 ,
V_160 , & V_166 [ V_51 -> V_150 ] ) ;
break;
case V_126 :
V_151 = F_56 ( V_167 , V_51 -> V_151 [ 0 ] ,
& V_6 -> V_153 , & V_168 ) ;
break;
case V_127 : {
struct V_169 V_170 = {
. V_159 = V_51 -> V_151 [ 0 ] ,
} ;
V_12 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
F_41 ( 10000 , 50000 ) ;
V_12 = F_19 ( V_6 , L_37 , 0x56 , & V_170 ,
& V_6 -> V_153 ) ;
if ( V_12 )
goto V_48;
V_151 = V_51 -> V_151 [ 0 ] ;
break;
}
case V_128 :
if ( V_51 -> V_150 == 0 ) {
V_12 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
} else {
V_53 [ 0 ] . V_36 = 0x63 ;
V_53 [ 0 ] . V_171 = 0 ;
V_53 [ 0 ] . V_2 = 2 ;
V_53 [ 0 ] . V_1 = L_38 ;
V_12 = F_58 ( & V_6 -> V_153 , V_53 , 1 ) ;
if ( V_12 < 0 )
goto V_48;
}
F_41 ( 10000 , 50000 ) ;
V_151 = F_56 ( V_172 , V_51 -> V_151 [ 0 ] , & V_6 -> V_153 ,
& V_173 [ V_51 -> V_150 ] ) ;
break;
case V_111 :
case V_121 :
case V_122 :
case V_110 :
case V_119 :
case V_120 :
{
struct V_174 * V_175 ;
const char * V_64 ;
struct V_176 V_177 = {
. V_178 = V_9 -> V_102 [ V_51 -> V_150 ] . V_178 ,
. V_151 = V_51 -> V_151 [ 0 ] ,
} ;
switch ( V_9 -> V_102 [ V_51 -> V_150 ] . V_109 ) {
case V_111 :
case V_121 :
case V_122 :
V_64 = L_39 ;
break;
case V_110 :
case V_119 :
case V_120 :
V_64 = L_40 ;
break;
default:
V_12 = - V_47 ;
goto V_48;
}
if ( V_9 -> V_81 ) {
if ( V_51 -> V_150 == 0 )
V_177 . V_179 = V_180 ;
else
V_177 . V_179 = V_181 ;
} else {
V_177 . V_179 = V_182 ;
}
F_21 ( L_8 , L_41 ) ;
V_175 = F_59 ( & V_6 -> V_11 -> V_18 , V_64 ,
V_183 ,
& V_177 ,
sizeof( V_177 ) ) ;
if ( F_60 ( V_175 ) || ! V_175 -> V_18 . V_49 ) {
V_12 = - V_47 ;
goto V_48;
}
if ( ! F_23 ( V_175 -> V_18 . V_49 -> V_50 ) ) {
F_61 ( V_175 ) ;
V_12 = - V_47 ;
goto V_48;
}
V_9 -> V_184 [ V_51 -> V_150 ] = V_175 ;
V_151 = V_51 -> V_151 [ 0 ] ;
break;
}
default:
V_151 = NULL ;
}
if ( V_151 == NULL ) {
V_12 = - V_47 ;
goto V_48;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_62 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
struct V_185 V_185 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
V_12 = F_16 ( V_6 , 0x00f6a7 , 0x07 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_16 ( V_6 , 0x00f103 , 0x07 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8d4 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8d5 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8d3 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8b8 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8b9 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
V_12 = F_18 ( V_6 , 0xd8b7 , 0x00 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
F_57 ( 200 ) ;
V_12 = F_18 ( V_6 , 0xd8b7 , 0x01 , 0x01 ) ;
if ( V_12 < 0 )
goto V_48;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_185 . V_151 = V_51 -> V_151 [ 0 ] ;
V_185 . V_186 = 1 ;
V_12 = F_19 ( V_6 , L_42 , 0x63 ,
& V_185 , V_9 -> V_158 ) ;
if ( V_12 )
goto V_48;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_63 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
if ( V_51 -> V_150 == 1 ) {
if ( V_9 -> V_41 [ 3 ] )
F_25 ( V_6 ) ;
} else if ( V_51 -> V_150 == 0 ) {
if ( V_9 -> V_41 [ 1 ] )
F_25 ( V_6 ) ;
}
return 0 ;
}
static int F_64 ( struct V_149 * V_51 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
struct V_5 * V_6 = F_52 ( V_51 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_33 , V_51 -> V_150 ) ;
switch ( V_9 -> V_102 [ V_51 -> V_150 ] . V_109 ) {
case V_123 :
case V_127 :
if ( V_51 -> V_150 == 1 ) {
if ( V_9 -> V_41 [ 3 ] )
F_25 ( V_6 ) ;
} else if ( V_51 -> V_150 == 0 ) {
if ( V_9 -> V_41 [ 1 ] )
F_25 ( V_6 ) ;
}
break;
case V_111 :
case V_121 :
case V_122 :
case V_110 :
case V_119 :
case V_120 :
{
struct V_174 * V_175 ;
V_175 = V_9 -> V_184 [ V_51 -> V_150 ] ;
if ( V_175 ) {
F_26 ( V_175 -> V_18 . V_49 -> V_50 ) ;
F_61 ( V_175 ) ;
}
break;
}
}
return 0 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_3 ;
T_1 V_187 = ( V_6 -> V_134 -> V_188 == V_189 ? 5 : 87 ) * 188 / 4 ;
T_2 V_190 = ( V_6 -> V_134 -> V_188 == V_189 ? 64 : 512 ) / 4 ;
struct V_191 V_192 [] = {
{ 0x80f99d , 0x01 , 0x01 } ,
{ 0x80f9a4 , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd88 , ( V_187 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_187 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_190 , 0xff } ,
{ 0x00dd11 , V_9 -> V_81 << 6 , 0x40 } ,
{ 0x00dd8a , ( V_187 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_187 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_190 , 0xff } ,
{ 0x80f9a3 , V_9 -> V_81 , 0x01 } ,
{ 0x80f9cd , V_9 -> V_81 , 0x01 } ,
{ 0x80f99d , 0x00 , 0x01 } ,
{ 0x80f9a4 , 0x00 , 0x01 } ,
} ;
F_11 ( & V_11 -> V_18 , L_43 ,
V_6 -> V_134 -> V_188 , V_187 , V_190 ) ;
for ( V_3 = 0 ; V_3 < F_43 ( V_192 ) ; V_3 ++ ) {
V_12 = F_18 ( V_6 , V_192 [ V_3 ] . V_28 , V_192 [ V_3 ] . V_29 ,
V_192 [ V_3 ] . V_34 ) ;
if ( V_12 < 0 )
goto V_48;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 , V_3 ;
T_1 V_187 = ( V_6 -> V_134 -> V_188 == V_189 ? 5 : 816 ) * 188 / 4 ;
T_2 V_190 = ( V_6 -> V_134 -> V_188 == V_189 ? 64 : 512 ) / 4 ;
struct V_191 V_192 [] = {
{ 0x00da1a , 0x00 , 0x01 } ,
{ 0x00f41f , 0x04 , 0x04 } ,
{ 0x00da10 , 0x00 , 0x01 } ,
{ 0x00f41a , 0x01 , 0x01 } ,
{ 0x00da1d , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , V_9 -> V_81 << 6 , 0x40 } ,
{ 0x00dd88 , ( V_187 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_187 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_190 , 0xff } ,
{ 0x00dd8a , ( V_187 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_187 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_190 , 0xff } ,
{ 0x00da1d , 0x00 , 0x01 } ,
{ 0x00d833 , 0x01 , 0xff } ,
{ 0x00d830 , 0x00 , 0xff } ,
{ 0x00d831 , 0x01 , 0xff } ,
{ 0x00d832 , 0x00 , 0xff } ,
{ 0x00d8b0 , 0x01 , 0xff } ,
{ 0x00d8b1 , 0x01 , 0xff } ,
{ 0x00d8af , 0x00 , 0xff } ,
{ 0x00d8c4 , 0x01 , 0xff } ,
{ 0x00d8c5 , 0x01 , 0xff } ,
{ 0x00d8c3 , 0x00 , 0xff } ,
{ 0x00d8dc , 0x01 , 0xff } ,
{ 0x00d8dd , 0x01 , 0xff } ,
{ 0x00d8db , 0x00 , 0xff } ,
{ 0x00d8e4 , 0x01 , 0xff } ,
{ 0x00d8e5 , 0x01 , 0xff } ,
{ 0x00d8e3 , 0x00 , 0xff } ,
{ 0x00d8e8 , 0x01 , 0xff } ,
{ 0x00d8e9 , 0x01 , 0xff } ,
{ 0x00d8e7 , 0x00 , 0xff } ,
{ 0x00da58 , 0x00 , 0x01 } ,
{ 0x00da73 , 0x01 , 0xff } ,
{ 0x00da78 , 0x47 , 0xff } ,
{ 0x00da4c , 0x01 , 0xff } ,
{ 0x00da5a , 0x1f , 0xff } ,
} ;
F_11 ( & V_11 -> V_18 , L_43 ,
V_6 -> V_134 -> V_188 , V_187 , V_190 ) ;
for ( V_3 = 0 ; V_3 < F_43 ( V_192 ) ; V_3 ++ ) {
V_12 = F_18 ( V_6 , V_192 [ V_3 ] . V_28 ,
V_192 [ V_3 ] . V_29 , V_192 [ V_3 ] . V_34 ) ;
if ( V_12 < 0 )
goto V_48;
}
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_12 ;
enum V_193 V_194 ;
T_4 V_195 ;
T_2 V_1 [ 4 ] ;
struct V_7 V_8 = { V_26 , 0 , 0 , NULL , 4 , V_1 } ;
V_12 = F_2 ( V_6 , & V_8 ) ;
if ( V_12 == 1 )
return 0 ;
else if ( V_12 < 0 )
goto V_48;
if ( ( V_1 [ 2 ] + V_1 [ 3 ] ) == 0xff ) {
if ( ( V_1 [ 0 ] + V_1 [ 1 ] ) == 0xff ) {
V_195 = F_68 ( V_1 [ 0 ] , V_1 [ 2 ] ) ;
V_194 = V_196 ;
} else {
V_195 = F_69 ( V_1 [ 0 ] << 8 | V_1 [ 1 ] , V_1 [ 2 ] ) ;
V_194 = V_197 ;
}
} else {
V_195 = F_70 ( V_1 [ 0 ] << 24 | V_1 [ 1 ] << 16 |
V_1 [ 2 ] << 8 | V_1 [ 3 ] ) ;
V_194 = V_198 ;
}
F_11 ( & V_11 -> V_18 , L_13 , 4 , V_1 ) ;
F_71 ( V_6 -> V_199 , V_194 , V_195 , 0 ) ;
return 0 ;
V_48:
F_11 ( & V_11 -> V_18 , L_4 , V_12 ) ;
return V_12 ;
}
static int F_72 ( struct V_5 * V_6 , struct V_200 * V_201 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_44 ,
V_9 -> V_112 , V_9 -> V_113 ) ;
if ( V_9 -> V_112 == 0x05 ) {
switch ( V_9 -> V_113 ) {
case 0 :
default:
V_201 -> V_202 = V_203 |
V_204 | V_205 ;
break;
case 1 :
V_201 -> V_202 = V_206 ;
break;
}
V_201 -> V_207 = F_67 ;
V_201 -> V_208 = 500 ;
if ( ! V_201 -> V_209 )
V_201 -> V_209 = V_210 ;
}
return 0 ;
}
static int F_73 ( struct V_159 * V_151 , T_2 * V_211 ,
struct V_212 * V_213 )
{
struct V_5 * V_6 = F_74 ( V_151 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_11 ( & V_11 -> V_18 , L_45 , F_75 ( V_151 ) -> V_150 ) ;
if ( V_6 -> V_134 -> V_188 == V_189 )
V_213 -> V_214 . V_215 . V_216 = 5 * 188 ;
return 0 ;
}
static int F_76 ( struct V_149 * V_51 , int V_217 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
return V_9 -> V_152 . V_218 ( V_51 -> V_151 [ 0 ] , V_217 ) ;
}
static int F_77 ( struct V_149 * V_51 , int V_219 , T_1 V_220 ,
int V_217 )
{
struct V_9 * V_9 = F_51 ( V_51 ) ;
return V_9 -> V_152 . V_221 ( V_51 -> V_151 [ 0 ] , V_219 , V_220 , V_217 ) ;
}
static int F_78 ( struct V_10 * V_11 ,
const struct V_222 * V_150 )
{
struct V_223 * V_134 = F_79 ( V_11 ) ;
char V_224 [ sizeof( L_46 ) ] ;
memset ( V_224 , 0 , sizeof( V_224 ) ) ;
F_80 ( V_134 , V_134 -> V_135 . V_225 ,
V_224 , sizeof( V_224 ) ) ;
if ( ( F_44 ( V_134 -> V_135 . V_136 ) == V_226 ) &&
( F_44 ( V_134 -> V_135 . V_138 ) == 0x0099 ) ) {
if ( ! strcmp ( L_46 , V_224 ) ) {
F_11 ( & V_134 -> V_18 , L_47 ) ;
return - V_47 ;
}
}
return F_81 ( V_11 , V_150 ) ;
}
