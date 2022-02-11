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
int V_10 , V_11 , V_12 ;
T_1 V_4 , V_13 ;
F_8 ( & V_6 -> V_14 ) ;
if ( V_8 -> V_11 > ( V_15 - F_3 - F_5 ) ||
V_8 -> V_12 > ( V_15 - F_4 - F_5 ) ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_1 ,
V_18 , V_8 -> V_11 , V_8 -> V_12 ) ;
V_10 = - V_19 ;
goto exit;
}
V_9 -> V_1 [ 0 ] = F_3 + V_8 -> V_11 + F_5 - 1 ;
V_9 -> V_1 [ 1 ] = V_8 -> V_20 ;
V_9 -> V_1 [ 2 ] = V_8 -> V_21 ;
V_9 -> V_1 [ 3 ] = V_9 -> V_22 ++ ;
memcpy ( & V_9 -> V_1 [ F_3 ] , V_8 -> V_23 , V_8 -> V_11 ) ;
V_11 = F_3 + V_8 -> V_11 + F_5 ;
V_12 = F_4 + V_8 -> V_12 + F_5 ;
V_4 = F_1 ( V_9 -> V_1 , V_9 -> V_1 [ 0 ] - 1 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 1 ] = ( V_4 >> 8 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 0 ] = ( V_4 & 0xff ) ;
if ( V_8 -> V_21 == V_24 )
V_12 = 0 ;
V_10 = F_10 ( V_6 ,
V_9 -> V_1 , V_11 , V_9 -> V_1 , V_12 ) ;
if ( V_10 )
goto exit;
if ( V_8 -> V_21 == V_24 )
goto exit;
V_4 = F_1 ( V_9 -> V_1 , V_12 - 2 ) ;
V_13 = ( V_9 -> V_1 [ V_12 - 2 ] << 8 ) | V_9 -> V_1 [ V_12 - 1 ] ;
if ( V_13 != V_4 ) {
F_9 ( & V_6 -> V_16 -> V_17 ,
L_2 ,
V_18 , V_8 -> V_21 , V_13 ,
V_4 ) ;
V_10 = - V_25 ;
goto exit;
}
if ( V_9 -> V_1 [ 2 ] ) {
if ( V_8 -> V_21 == V_26 || V_9 -> V_1 [ 2 ] == 1 ) {
V_10 = 1 ;
goto exit;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_3 ,
V_27 , V_8 -> V_21 , V_9 -> V_1 [ 2 ] ) ;
V_10 = - V_25 ;
goto exit;
}
if ( V_8 -> V_12 )
memcpy ( V_8 -> V_28 , & V_9 -> V_1 [ F_4 ] , V_8 -> V_12 ) ;
exit:
F_12 ( & V_6 -> V_14 ) ;
if ( V_10 < 0 )
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_13 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 , int V_2 )
{
T_2 V_23 [ V_31 ] ;
T_2 V_20 = ( V_29 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_32 , V_20 , 6 + V_2 , V_23 , 0 , NULL } ;
if ( 6 + V_2 > sizeof( V_23 ) ) {
F_14 ( & V_6 -> V_16 -> V_17 , L_5 ,
V_18 , V_2 ) ;
return - V_33 ;
}
V_23 [ 0 ] = V_2 ;
V_23 [ 1 ] = 2 ;
V_23 [ 2 ] = 0 ;
V_23 [ 3 ] = 0 ;
V_23 [ 4 ] = ( V_29 >> 8 ) & 0xff ;
V_23 [ 5 ] = ( V_29 >> 0 ) & 0xff ;
memcpy ( & V_23 [ 6 ] , V_30 , V_2 ) ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_15 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 , int V_2 )
{
T_2 V_23 [] = { V_2 , 2 , 0 , 0 , ( V_29 >> 8 ) & 0xff , V_29 & 0xff } ;
T_2 V_20 = ( V_29 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_34 , V_20 , sizeof( V_23 ) , V_23 , V_2 , V_30 } ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_4 V_29 , T_2 V_30 )
{
return F_13 ( V_6 , V_29 , & V_30 , 1 ) ;
}
static int F_17 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 )
{
return F_15 ( V_6 , V_29 , V_30 , 1 ) ;
}
static int F_18 ( struct V_5 * V_6 , T_4 V_29 , T_2 V_30 ,
T_2 V_35 )
{
int V_10 ;
T_2 V_36 ;
if ( V_35 != 0xff ) {
V_10 = F_15 ( V_6 , V_29 , & V_36 , 1 ) ;
if ( V_10 )
return V_10 ;
V_30 &= V_35 ;
V_36 &= ~ V_35 ;
V_30 |= V_36 ;
}
return F_13 ( V_6 , V_29 , & V_30 , 1 ) ;
}
static int F_19 ( struct V_5 * V_6 , const char * type ,
T_2 V_37 , void * V_38 , struct V_39 * V_40 )
{
int V_10 , V_41 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_42 * V_43 ;
struct V_44 V_45 = {
. V_37 = V_37 ,
. V_38 = V_38 ,
} ;
F_20 ( V_45 . type , type , V_46 ) ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
if ( V_9 -> V_42 [ V_41 ] == NULL )
break;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_6 , V_27 , V_41 ) ;
if ( V_41 == V_47 ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_7 ,
V_18 ) ;
V_10 = - V_48 ;
goto V_49;
}
F_21 ( L_8 , V_45 . type ) ;
V_43 = F_22 ( V_40 , & V_45 ) ;
if ( V_43 == NULL || V_43 -> V_17 . V_50 == NULL ) {
V_10 = - V_48 ;
goto V_49;
}
if ( ! F_23 ( V_43 -> V_17 . V_50 -> V_51 ) ) {
F_24 ( V_43 ) ;
V_10 = - V_48 ;
goto V_49;
}
V_9 -> V_42 [ V_41 ] = V_43 ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static void F_25 ( struct V_5 * V_6 )
{
int V_41 ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
struct V_42 * V_43 ;
V_41 = V_47 ;
while ( V_41 -- ) {
if ( V_9 -> V_42 [ V_41 ] != NULL )
break;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_6 , V_27 , V_41 ) ;
if ( V_41 == - 1 ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_7 ,
V_18 ) ;
goto V_49;
}
V_43 = V_9 -> V_42 [ V_41 ] ;
F_26 ( V_43 -> V_17 . V_50 -> V_51 ) ;
F_24 ( V_43 ) ;
V_9 -> V_42 [ V_41 ] = NULL ;
return;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_9 , V_27 ) ;
}
static int F_27 ( struct V_39 * V_52 ,
struct V_53 V_54 [] , int V_41 )
{
struct V_5 * V_6 = F_28 ( V_52 ) ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
if ( F_29 ( & V_6 -> V_55 ) < 0 )
return - V_56 ;
#define F_30 ( T_5 , T_6 ) \
(_num == 2 && !(_msg[0].flags & I2C_M_RD) && (_msg[1].flags & I2C_M_RD))
#define F_31 ( T_5 , T_6 ) \
(_num == 1 && !(_msg[0].flags & I2C_M_RD))
#define F_32 ( T_5 , T_6 ) \
(_num == 1 && (_msg[0].flags & I2C_M_RD))
if ( F_30 ( V_54 , V_41 ) ) {
if ( V_54 [ 0 ] . V_2 > 40 || V_54 [ 1 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else if ( ( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 0 ] ) ||
( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 1 ] ) ||
( V_9 -> V_58 == 0x9135 ) ) {
T_4 V_29 = V_54 [ 0 ] . V_1 [ 0 ] << 16 | V_54 [ 0 ] . V_1 [ 1 ] << 8 |
V_54 [ 0 ] . V_1 [ 2 ] ;
if ( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 1 ] ||
V_54 [ 0 ] . V_37 == ( V_9 -> V_57 [ 1 ] >> 1 ) )
V_29 |= 0x100000 ;
V_10 = F_15 ( V_6 , V_29 , & V_54 [ 1 ] . V_1 [ 0 ] ,
V_54 [ 1 ] . V_2 ) ;
} else {
T_2 V_1 [ V_31 ] ;
struct V_7 V_8 = { V_59 , 0 , 5 + V_54 [ 0 ] . V_2 ,
V_1 , V_54 [ 1 ] . V_2 , V_54 [ 1 ] . V_1 } ;
if ( V_9 -> V_58 == 0x9306 ) {
V_8 . V_21 = V_60 ;
V_8 . V_11 = 3 + V_54 [ 0 ] . V_2 ;
}
V_8 . V_20 |= ( ( V_54 [ 0 ] . V_37 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_54 [ 1 ] . V_2 ;
if ( V_9 -> V_58 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_54 [ 0 ] . V_37 << 1 ;
memcpy ( & V_1 [ 3 ] , V_54 [ 0 ] . V_1 , V_54 [ 0 ] . V_2 ) ;
} else {
V_1 [ 1 ] = V_54 [ 0 ] . V_37 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_54 [ 0 ] . V_1 , V_54 [ 0 ] . V_2 ) ;
}
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( F_31 ( V_54 , V_41 ) ) {
if ( V_54 [ 0 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else if ( ( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 0 ] ) ||
( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 1 ] ) ||
( V_9 -> V_58 == 0x9135 ) ) {
T_4 V_29 = V_54 [ 0 ] . V_1 [ 0 ] << 16 | V_54 [ 0 ] . V_1 [ 1 ] << 8 |
V_54 [ 0 ] . V_1 [ 2 ] ;
if ( V_54 [ 0 ] . V_37 == V_9 -> V_57 [ 1 ] ||
V_54 [ 0 ] . V_37 == ( V_9 -> V_57 [ 1 ] >> 1 ) )
V_29 |= 0x100000 ;
V_10 = F_13 ( V_6 , V_29 , & V_54 [ 0 ] . V_1 [ 3 ] ,
V_54 [ 0 ] . V_2 - 3 ) ;
} else {
T_2 V_1 [ V_31 ] ;
struct V_7 V_8 = { V_61 , 0 , 5 + V_54 [ 0 ] . V_2 ,
V_1 , 0 , NULL } ;
if ( V_9 -> V_58 == 0x9306 ) {
V_8 . V_21 = V_62 ;
V_8 . V_11 = 3 + V_54 [ 0 ] . V_2 ;
}
V_8 . V_20 |= ( ( V_54 [ 0 ] . V_37 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_54 [ 0 ] . V_2 ;
if ( V_9 -> V_58 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_54 [ 0 ] . V_37 << 1 ;
memcpy ( & V_1 [ 3 ] , V_54 [ 0 ] . V_1 , V_54 [ 0 ] . V_2 ) ;
} else {
V_1 [ 1 ] = V_54 [ 0 ] . V_37 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_54 [ 0 ] . V_1 , V_54 [ 0 ] . V_2 ) ;
}
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( F_32 ( V_54 , V_41 ) ) {
if ( V_54 [ 0 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else {
T_2 V_1 [ 5 ] ;
struct V_7 V_8 = { V_59 , 0 , sizeof( V_1 ) ,
V_1 , V_54 [ 0 ] . V_2 , V_54 [ 0 ] . V_1 } ;
if ( V_9 -> V_58 == 0x9306 ) {
V_8 . V_21 = V_60 ;
V_8 . V_11 = 3 ;
}
V_8 . V_20 |= ( ( V_54 [ 0 ] . V_37 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_54 [ 0 ] . V_2 ;
if ( V_9 -> V_58 == 0x9306 ) {
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_54 [ 0 ] . V_37 << 1 ;
} else {
V_1 [ 1 ] = V_54 [ 0 ] . V_37 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
}
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else {
V_10 = - V_33 ;
}
F_12 ( & V_6 -> V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_41 ;
}
static T_4 F_33 ( struct V_39 * V_40 )
{
return V_63 ;
}
static int F_34 ( struct V_5 * V_6 , const char * * V_64 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_23 [ 1 ] = { 1 } ;
T_2 V_28 [ 4 ] ;
struct V_7 V_8 = { V_65 , 0 , sizeof( V_23 ) , V_23 ,
sizeof( V_28 ) , V_28 } ;
V_10 = F_15 ( V_6 , 0x1222 , V_28 , 3 ) ;
if ( V_10 < 0 )
goto V_49;
V_9 -> V_66 = V_28 [ 0 ] ;
V_9 -> V_58 = V_28 [ 2 ] << 8 | V_28 [ 1 ] << 0 ;
V_10 = F_17 ( V_6 , 0x384f , & V_9 -> V_67 ) ;
if ( V_10 < 0 )
goto V_49;
F_35 ( & V_6 -> V_16 -> V_17 ,
L_10 ,
V_18 , V_9 -> V_67 ,
V_9 -> V_66 , V_9 -> V_58 ) ;
if ( V_9 -> V_58 == 0x9135 ) {
if ( V_9 -> V_66 == 0x02 )
* V_64 = V_68 ;
else
* V_64 = V_69 ;
V_9 -> V_70 = V_71 ;
} else if ( V_9 -> V_58 == 0x9306 ) {
* V_64 = V_72 ;
V_9 -> V_70 = V_71 ;
} else {
* V_64 = V_73 ;
V_9 -> V_70 = V_74 ;
}
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_49;
F_11 ( & V_6 -> V_16 -> V_17 , L_11 , V_27 , 4 , V_28 ) ;
if ( V_28 [ 0 ] || V_28 [ 1 ] || V_28 [ 2 ] || V_28 [ 3 ] )
V_10 = V_75 ;
else
V_10 = V_76 ;
return V_10 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_36 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
int V_10 , V_3 , V_79 , V_2 ;
T_2 V_23 [ 1 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_80 = { V_24 , 0 , 0 , V_23 , 0 , NULL } ;
T_2 V_81 ;
T_1 V_82 , V_83 , V_84 ;
#define F_37 58
#define F_38 7
for ( V_3 = V_78 -> V_85 ; V_3 > F_38 ; ) {
V_81 = V_78 -> V_86 [ V_78 -> V_85 - V_3 + 0 ] ;
V_82 = V_78 -> V_86 [ V_78 -> V_85 - V_3 + 1 ] << 8 ;
V_82 |= V_78 -> V_86 [ V_78 -> V_85 - V_3 + 2 ] << 0 ;
V_83 = V_78 -> V_86 [ V_78 -> V_85 - V_3 + 3 ] << 8 ;
V_83 |= V_78 -> V_86 [ V_78 -> V_85 - V_3 + 4 ] << 0 ;
V_84 = V_78 -> V_86 [ V_78 -> V_85 - V_3 + 5 ] << 8 ;
V_84 |= V_78 -> V_86 [ V_78 -> V_85 - V_3 + 6 ] << 0 ;
F_11 ( & V_6 -> V_16 -> V_17 ,
L_12 ,
V_27 , V_81 , V_82 , V_83 ,
V_84 ) ;
if ( ( ( V_81 != 1 ) && ( V_81 != 2 ) ) ||
( V_83 > V_3 ) ) {
F_11 ( & V_6 -> V_16 -> V_17 , L_13 , V_27 ) ;
break;
}
V_8 . V_21 = V_87 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_49;
for ( V_79 = F_38 + V_83 ; V_79 > 0 ; V_79 -= F_37 ) {
V_2 = V_79 ;
if ( V_2 > F_37 )
V_2 = F_37 ;
V_80 . V_11 = V_2 ;
V_80 . V_23 = ( T_2 * ) & V_78 -> V_86 [ V_78 -> V_85 - V_3 +
F_38 + V_83 - V_79 ] ;
V_10 = F_2 ( V_6 , & V_80 ) ;
if ( V_10 < 0 )
goto V_49;
}
V_8 . V_21 = V_88 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_49;
V_3 -= V_83 + F_38 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_14 ,
V_27 , V_78 -> V_85 - V_3 ) ;
}
if ( V_3 )
F_14 ( & V_6 -> V_16 -> V_17 , L_13 , V_18 ) ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_39 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
int V_10 , V_3 , V_89 ;
struct V_7 V_80 = { V_90 , 0 , 0 , NULL , 0 , NULL } ;
#define F_38 7
for ( V_3 = F_38 , V_89 = 0 ; V_3 <= V_78 -> V_85 ; V_3 ++ ) {
if ( V_3 == V_78 -> V_85 ||
( V_78 -> V_86 [ V_3 + 0 ] == 0x03 &&
( V_78 -> V_86 [ V_3 + 1 ] == 0x00 ||
V_78 -> V_86 [ V_3 + 1 ] == 0x01 ) &&
V_78 -> V_86 [ V_3 + 2 ] == 0x00 ) ) {
V_80 . V_11 = V_3 - V_89 ;
V_80 . V_23 = ( T_2 * ) & V_78 -> V_86 [ V_89 ] ;
V_89 = V_3 ;
V_10 = F_2 ( V_6 , & V_80 ) ;
if ( V_10 < 0 )
goto V_49;
F_11 ( & V_6 -> V_16 -> V_17 , L_15 ,
V_27 , V_3 ) ;
}
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_40 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_23 [ 1 ] ;
T_2 V_28 [ 4 ] ;
T_2 V_36 ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_91 = { V_65 , 0 , 1 , V_23 , 4 , V_28 } ;
F_11 ( & V_6 -> V_16 -> V_17 , L_16 , V_27 ) ;
V_10 = F_17 ( V_6 , V_9 -> V_70 + V_92 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
if ( V_36 == 1 || V_36 == 3 || V_36 == 5 ) {
V_10 = F_18 ( V_6 , 0x00d8b0 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d8b1 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d8af , 0x00 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
F_41 ( 10000 , 50000 ) ;
V_10 = F_18 ( V_6 , 0x00d8af , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_17 ( V_6 ,
V_9 -> V_70 + V_93 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_49;
if ( ! V_36 )
V_36 = 0x3a ;
if ( ( V_9 -> V_58 == 0x9135 ) ||
( V_9 -> V_58 == 0x9306 ) ) {
V_10 = F_16 ( V_6 , 0x004bfb , V_36 ) ;
if ( V_10 < 0 )
goto V_49;
} else {
V_10 = F_16 ( V_6 , 0x00417f , V_36 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d81a , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
}
}
if ( V_78 -> V_86 [ 0 ] == 0x01 )
V_10 = F_36 ( V_6 , V_78 ) ;
else
V_10 = F_39 ( V_6 , V_78 ) ;
if ( V_10 < 0 )
goto V_49;
V_8 . V_21 = V_94 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_49;
V_23 [ 0 ] = 1 ;
V_10 = F_2 ( V_6 , & V_91 ) ;
if ( V_10 < 0 )
goto V_49;
if ( ! ( V_28 [ 0 ] || V_28 [ 1 ] || V_28 [ 2 ] || V_28 [ 3 ] ) ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_17 ,
V_18 ) ;
V_10 = - V_48 ;
goto V_49;
}
F_35 ( & V_6 -> V_16 -> V_17 , L_18 ,
V_18 , V_28 [ 0 ] , V_28 [ 1 ] , V_28 [ 2 ] , V_28 [ 3 ] ) ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_3 ;
T_2 V_36 ;
T_1 V_95 , V_37 ;
V_9 -> V_57 [ 0 ] = 0x38 ;
V_9 -> V_57 [ 1 ] = 0x3a ;
V_9 -> V_96 [ 0 ] . V_97 = V_98 ;
V_9 -> V_96 [ 1 ] . V_97 = V_98 ;
V_9 -> V_96 [ 0 ] . V_99 = V_100 ;
V_9 -> V_96 [ 1 ] . V_99 = V_101 ;
if ( V_9 -> V_58 == 0x9135 ) {
V_9 -> V_96 [ 0 ] . V_102 = true ;
V_9 -> V_96 [ 1 ] . V_102 = true ;
if ( V_9 -> V_66 == 0x02 ) {
V_9 -> V_96 [ 0 ] . V_103 = V_104 ;
V_9 -> V_96 [ 1 ] . V_103 = V_104 ;
V_95 = 0x00461d ;
} else {
V_9 -> V_96 [ 0 ] . V_103 = V_105 ;
V_9 -> V_96 [ 1 ] . V_103 = V_105 ;
V_95 = 0x00461b ;
}
V_10 = F_17 ( V_6 , V_95 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
if ( V_36 == 0x00 ) {
F_11 ( & V_6 -> V_16 -> V_17 , L_19 , V_27 ) ;
goto V_106;
}
} else if ( V_9 -> V_58 == 0x9306 ) {
return 0 ;
}
V_10 = F_17 ( V_6 , V_9 -> V_70 + V_92 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
if ( V_36 == 1 || V_36 == 3 || V_36 == 5 )
V_9 -> V_107 = true ;
F_11 ( & V_6 -> V_16 -> V_17 , L_20 , V_27 ,
V_36 , V_9 -> V_107 ) ;
if ( V_9 -> V_107 ) {
V_10 = F_17 ( V_6 ,
V_9 -> V_70 + V_93 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_49;
if ( V_36 )
V_9 -> V_57 [ 1 ] = V_36 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_21 ,
V_27 , V_36 ) ;
}
V_37 = V_9 -> V_70 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_107 + 1 ; V_3 ++ ) {
V_10 = F_17 ( V_6 , V_37 + V_108 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
F_11 ( & V_6 -> V_16 -> V_17 , L_22 ,
V_27 , V_3 , V_36 ) ;
if ( V_9 -> V_58 == 0x9135 ) {
if ( V_9 -> V_66 == 0x02 ) {
switch ( V_36 ) {
case V_104 :
case V_109 :
case V_110 :
V_9 -> V_96 [ V_3 ] . V_103 = V_36 ;
break;
}
} else {
switch ( V_36 ) {
case V_105 :
case V_111 :
case V_112 :
V_9 -> V_96 [ V_3 ] . V_103 = V_36 ;
break;
}
}
} else {
V_9 -> V_96 [ V_3 ] . V_103 = V_36 ;
}
if ( V_9 -> V_96 [ V_3 ] . V_103 != V_36 ) {
F_35 ( & V_6 -> V_16 -> V_17 ,
L_23 ,
V_18 , V_3 , V_36 ,
V_9 -> V_96 [ V_3 ] . V_103 ) ;
}
switch ( V_9 -> V_96 [ V_3 ] . V_103 ) {
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_9 -> V_96 [ V_3 ] . V_119 = 1 ;
break;
case V_105 :
case V_111 :
case V_112 :
case V_104 :
case V_109 :
case V_110 :
break;
default:
F_14 ( & V_6 -> V_16 -> V_17 ,
L_24 ,
V_18 , V_36 ) ;
}
if ( V_3 == 1 )
switch ( V_9 -> V_96 [ V_3 ] . V_103 ) {
case V_118 :
case V_105 :
case V_111 :
case V_112 :
case V_104 :
case V_109 :
case V_110 :
case V_115 :
break;
default:
V_9 -> V_107 = false ;
F_35 ( & V_6 -> V_16 -> V_17 ,
L_25 ,
V_18 ) ;
}
V_10 = F_17 ( V_6 , V_37 + V_120 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
V_95 = V_36 ;
V_10 = F_17 ( V_6 , V_37 + V_121 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
V_95 |= V_36 << 8 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_26 , V_27 , V_3 , V_95 ) ;
V_37 += 0x10 ;
}
V_106:
V_10 = F_17 ( V_6 , 0x00d800 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
V_36 = ( V_36 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < F_43 ( V_9 -> V_96 ) ; V_3 ++ ) {
if ( V_9 -> V_58 == 0x9135 )
V_9 -> V_96 [ V_3 ] . clock = V_122 [ V_36 ] ;
else
V_9 -> V_96 [ V_3 ] . clock = V_123 [ V_36 ] ;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_44 ( struct V_5 * V_6 ,
int V_21 , int V_124 )
{
int V_10 ;
T_2 V_30 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_27 , V_27 , V_21 , V_124 ) ;
switch ( V_21 ) {
case V_125 :
if ( V_124 )
V_30 = 0x00 ;
else
V_30 = 0x01 ;
V_10 = F_18 ( V_6 , 0x00d8e7 , V_30 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
break;
case V_126 :
if ( V_124 )
V_30 = 0x01 ;
else
V_30 = 0x00 ;
V_10 = F_18 ( V_6 , 0x00d8eb , V_30 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
break;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_45 ( struct V_5 * V_6 ,
int V_21 , int V_124 )
{
int V_10 ;
switch ( V_21 ) {
case V_127 :
V_10 = F_18 ( V_6 , 0xd8eb , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ec , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ed , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8d0 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8d1 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
F_41 ( 10000 , 50000 ) ;
break;
case V_128 :
V_10 = F_16 ( V_6 , 0xd8e9 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0xd8e8 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0xd8e7 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
F_41 ( 10000 , 20000 ) ;
V_10 = F_16 ( V_6 , 0xd8e7 , 0 ) ;
if ( V_10 < 0 )
goto V_49;
F_41 ( 10000 , 20000 ) ;
break;
default:
V_10 = - V_19 ;
goto V_49;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_46 ( struct V_5 * V_6 , int V_21 , int V_124 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
switch ( V_9 -> V_96 [ 0 ] . V_103 ) {
case V_114 :
return F_45 ( V_6 , V_21 , V_124 ) ;
case V_113 :
return F_44 ( V_6 , V_21 , V_124 ) ;
default:
break;
}
return 0 ;
}
static int F_47 ( void * V_129 , int V_130 ,
int V_21 , int V_124 )
{
struct V_39 * V_52 = V_129 ;
struct V_5 * V_6 = F_28 ( V_52 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_28 ,
V_27 , V_130 , V_21 , V_124 ) ;
switch ( V_130 ) {
case V_131 :
return F_46 ( V_6 , V_21 , V_124 ) ;
default:
break;
}
return 0 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
return V_9 -> V_107 + 1 ;
}
static int F_49 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
int V_10 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_52 -> V_133 ) ;
if ( ! V_9 -> V_96 [ V_52 -> V_133 ] . V_103 ) {
V_10 = - V_48 ;
goto V_49;
}
V_9 -> V_96 [ V_52 -> V_133 ] . V_134 = & V_52 -> V_134 [ 0 ] ;
V_9 -> V_96 [ V_52 -> V_133 ] . V_135 = & V_9 -> V_135 ;
V_10 = F_19 ( V_6 , L_30 , V_9 -> V_57 [ V_52 -> V_133 ] ,
& V_9 -> V_96 [ V_52 -> V_133 ] , & V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
if ( V_52 -> V_134 [ 0 ] == NULL ) {
V_10 = - V_48 ;
goto V_49;
}
V_52 -> V_134 [ 0 ] -> V_135 . V_137 = NULL ;
V_52 -> V_134 [ 0 ] -> V_138 = F_47 ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_52 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
int V_10 ;
struct V_139 V_139 ;
struct V_39 * V_40 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_31 , V_52 -> V_133 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_39 = & V_40 ;
V_139 . V_134 = & V_52 -> V_134 [ 0 ] ;
V_139 . V_99 = V_140 ;
V_9 -> V_96 [ V_52 -> V_133 ] . V_134 = & V_52 -> V_134 [ 0 ] ;
V_9 -> V_96 [ V_52 -> V_133 ] . V_135 = & V_9 -> V_135 ;
V_10 = F_19 ( V_6 , L_32 , 0x67 , & V_139 ,
& V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
if ( V_52 -> V_134 [ 0 ] == NULL ) {
V_10 = - V_48 ;
goto V_49;
}
V_9 -> V_141 = V_40 ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_53 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
int V_142 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_52 -> V_133 ) ;
switch ( V_9 -> V_96 [ V_52 -> V_133 ] . V_103 ) {
case V_105 :
case V_111 :
case V_112 :
case V_104 :
case V_109 :
case V_110 :
V_142 = 2 ;
break;
default:
V_142 = 1 ;
}
if ( V_52 -> V_133 == 1 ) {
if ( V_9 -> V_42 [ V_142 ] )
F_25 ( V_6 ) ;
} else if ( V_52 -> V_133 == 0 ) {
if ( V_9 -> V_42 [ 0 ] )
F_25 ( V_6 ) ;
}
return 0 ;
}
static int F_54 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
int V_10 ;
struct V_143 * V_134 ;
struct V_53 V_54 [ 1 ] ;
T_2 V_144 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_52 -> V_133 ) ;
switch ( V_9 -> V_96 [ V_52 -> V_133 ] . V_103 ) {
case V_113 : {
struct V_145 V_146 = {
. V_143 = V_52 -> V_134 [ 0 ] ,
} ;
V_10 = F_18 ( V_6 , 0x00d8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d8e8 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0x00d8e9 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_19 ( V_6 , L_33 , 0x60 , & V_146 ,
& V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
V_134 = V_52 -> V_134 [ 0 ] ;
break;
}
case V_114 :
V_134 = F_55 ( V_147 , V_52 -> V_134 [ 0 ] ,
& V_6 -> V_136 , & V_148 ) ;
break;
case V_115 :
if ( V_52 -> V_133 == 0 ) {
V_10 = F_16 ( V_6 , 0x00d8e0 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8e1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8df , 0 ) ;
if ( V_10 < 0 )
goto V_49;
F_56 ( 30 ) ;
V_10 = F_16 ( V_6 , 0x00d8df , 1 ) ;
if ( V_10 < 0 )
goto V_49;
F_56 ( 300 ) ;
V_10 = F_16 ( V_6 , 0x00d8c0 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8c1 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8bf , 0 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8b4 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8b5 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00d8b3 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
V_144 = 0x60 ;
} else {
V_144 = 0x60 | 0x80 ;
}
V_134 = F_55 ( V_149 , V_52 -> V_134 [ 0 ] , & V_6 -> V_136 ,
V_144 , & V_150 [ V_52 -> V_133 ] ) ;
break;
case V_116 :
V_134 = F_55 ( V_151 , V_52 -> V_134 [ 0 ] ,
& V_6 -> V_136 , & V_152 ) ;
break;
case V_117 : {
struct V_153 V_154 = {
. V_143 = V_52 -> V_134 [ 0 ] ,
} ;
V_10 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
F_41 ( 10000 , 50000 ) ;
V_10 = F_19 ( V_6 , L_34 , 0x56 , & V_154 ,
& V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
V_134 = V_52 -> V_134 [ 0 ] ;
break;
}
case V_118 :
if ( V_52 -> V_133 == 0 ) {
V_10 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
} else {
V_54 [ 0 ] . V_37 = 0x63 ;
V_54 [ 0 ] . V_155 = 0 ;
V_54 [ 0 ] . V_2 = 2 ;
V_54 [ 0 ] . V_1 = L_35 ;
V_10 = F_57 ( & V_6 -> V_136 , V_54 , 1 ) ;
if ( V_10 < 0 )
goto V_49;
}
F_41 ( 10000 , 50000 ) ;
V_134 = F_55 ( V_156 , V_52 -> V_134 [ 0 ] , & V_6 -> V_136 ,
& V_157 [ V_52 -> V_133 ] ) ;
break;
case V_105 :
case V_111 :
case V_112 :
{
struct V_158 V_158 = {
. V_134 = V_52 -> V_134 [ 0 ] ,
. V_159 = 1 ,
} ;
if ( V_9 -> V_107 ) {
if ( V_52 -> V_133 == 0 )
V_158 . V_160 = V_161 ;
else
V_158 . V_160 = V_162 ;
}
V_10 = F_19 ( V_6 , L_36 ,
V_9 -> V_57 [ V_52 -> V_133 ] >> 1 ,
& V_158 , & V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
V_134 = V_52 -> V_134 [ 0 ] ;
break;
}
case V_104 :
case V_109 :
case V_110 :
{
struct V_158 V_158 = {
. V_134 = V_52 -> V_134 [ 0 ] ,
. V_159 = 2 ,
} ;
if ( V_9 -> V_107 ) {
if ( V_52 -> V_133 == 0 )
V_158 . V_160 = V_161 ;
else
V_158 . V_160 = V_162 ;
}
V_10 = F_19 ( V_6 , L_36 ,
V_9 -> V_57 [ V_52 -> V_133 ] >> 1 ,
& V_158 , & V_6 -> V_136 ) ;
if ( V_10 )
goto V_49;
V_134 = V_52 -> V_134 [ 0 ] ;
break;
}
default:
V_134 = NULL ;
}
if ( V_134 == NULL ) {
V_10 = - V_48 ;
goto V_49;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_58 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
int V_10 ;
struct V_163 V_163 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_52 -> V_133 ) ;
V_10 = F_16 ( V_6 , 0x00f6a7 , 0x07 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_16 ( V_6 , 0x00f103 , 0x07 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8d4 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8d5 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8d3 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8b8 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8b9 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_18 ( V_6 , 0xd8b7 , 0x00 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
F_56 ( 200 ) ;
V_10 = F_18 ( V_6 , 0xd8b7 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_49;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_134 = V_52 -> V_134 [ 0 ] ;
V_163 . V_164 = 1 ;
V_10 = F_19 ( V_6 , L_37 , 0x63 ,
& V_163 , V_9 -> V_141 ) ;
if ( V_10 )
goto V_49;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_59 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_31 , V_52 -> V_133 ) ;
if ( V_52 -> V_133 == 1 ) {
if ( V_9 -> V_42 [ 3 ] )
F_25 ( V_6 ) ;
} else if ( V_52 -> V_133 == 0 ) {
if ( V_9 -> V_42 [ 1 ] )
F_25 ( V_6 ) ;
}
return 0 ;
}
static int F_60 ( struct V_132 * V_52 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
struct V_5 * V_6 = F_51 ( V_52 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_52 -> V_133 ) ;
switch ( V_9 -> V_96 [ V_52 -> V_133 ] . V_103 ) {
case V_113 :
case V_117 :
case V_105 :
case V_111 :
case V_112 :
case V_104 :
case V_109 :
case V_110 :
if ( V_52 -> V_133 == 1 ) {
if ( V_9 -> V_42 [ 3 ] )
F_25 ( V_6 ) ;
} else if ( V_52 -> V_133 == 0 ) {
if ( V_9 -> V_42 [ 1 ] )
F_25 ( V_6 ) ;
}
}
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_3 ;
T_1 V_165 = ( V_6 -> V_16 -> V_166 == V_167 ? 5 : 87 ) * 188 / 4 ;
T_2 V_168 = ( V_6 -> V_16 -> V_166 == V_167 ? 64 : 512 ) / 4 ;
struct V_169 V_170 [] = {
{ 0x80f99d , 0x01 , 0x01 } ,
{ 0x80f9a4 , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd88 , ( V_165 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_165 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_168 , 0xff } ,
{ 0x00dd11 , V_9 -> V_107 << 6 , 0x40 } ,
{ 0x00dd8a , ( V_165 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_165 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_168 , 0xff } ,
{ 0x80f9a3 , V_9 -> V_107 , 0x01 } ,
{ 0x80f9cd , V_9 -> V_107 , 0x01 } ,
{ 0x80f99d , 0x00 , 0x01 } ,
{ 0x80f9a4 , 0x00 , 0x01 } ,
} ;
F_11 ( & V_6 -> V_16 -> V_17 ,
L_38 ,
V_27 , V_6 -> V_16 -> V_166 , V_165 , V_168 ) ;
for ( V_3 = 0 ; V_3 < F_43 ( V_170 ) ; V_3 ++ ) {
V_10 = F_18 ( V_6 , V_170 [ V_3 ] . V_29 , V_170 [ V_3 ] . V_30 ,
V_170 [ V_3 ] . V_35 ) ;
if ( V_10 < 0 )
goto V_49;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_3 ;
T_1 V_165 = ( V_6 -> V_16 -> V_166 == V_167 ? 5 : 816 ) * 188 / 4 ;
T_2 V_168 = ( V_6 -> V_16 -> V_166 == V_167 ? 64 : 512 ) / 4 ;
struct V_169 V_170 [] = {
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
{ 0x00dd11 , V_9 -> V_107 << 6 , 0x40 } ,
{ 0x00dd88 , ( V_165 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_165 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_168 , 0xff } ,
{ 0x00dd8a , ( V_165 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_165 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_168 , 0xff } ,
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
F_11 ( & V_6 -> V_16 -> V_17 ,
L_38 ,
V_27 , V_6 -> V_16 -> V_166 , V_165 , V_168 ) ;
for ( V_3 = 0 ; V_3 < F_43 ( V_170 ) ; V_3 ++ ) {
V_10 = F_18 ( V_6 , V_170 [ V_3 ] . V_29 ,
V_170 [ V_3 ] . V_30 , V_170 [ V_3 ] . V_35 ) ;
if ( V_10 < 0 )
goto V_49;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_63 ( struct V_5 * V_6 )
{
int V_10 ;
T_4 V_171 ;
T_2 V_1 [ 4 ] ;
struct V_7 V_8 = { V_26 , 0 , 0 , NULL , 4 , V_1 } ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 == 1 )
return 0 ;
else if ( V_10 < 0 )
goto V_49;
if ( ( V_1 [ 2 ] + V_1 [ 3 ] ) == 0xff ) {
if ( ( V_1 [ 0 ] + V_1 [ 1 ] ) == 0xff ) {
V_171 = F_64 ( V_1 [ 0 ] , V_1 [ 2 ] ) ;
} else {
V_171 = F_65 ( V_1 [ 0 ] << 8 | V_1 [ 1 ] , V_1 [ 2 ] ) ;
}
} else {
V_171 = F_66 ( V_1 [ 0 ] << 24 | V_1 [ 1 ] << 16 |
V_1 [ 2 ] << 8 | V_1 [ 3 ] ) ;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_39 , V_27 , 4 , V_1 ) ;
F_67 ( V_6 -> V_172 , V_173 , V_171 , 0 ) ;
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_68 ( struct V_5 * V_6 , struct V_174 * V_175 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_36 ;
V_10 = F_17 ( V_6 , V_9 -> V_70 + V_176 , & V_36 ) ;
if ( V_10 < 0 )
goto V_49;
F_11 ( & V_6 -> V_16 -> V_17 , L_40 , V_27 , V_36 ) ;
if ( V_36 == 5 ) {
V_10 = F_17 ( V_6 , V_9 -> V_70 + V_177 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_49;
F_11 ( & V_6 -> V_16 -> V_17 , L_41 , V_27 , V_36 ) ;
switch ( V_36 ) {
case 0 :
default:
V_175 -> V_178 = V_179 ;
break;
case 1 :
V_175 -> V_178 = V_180 ;
break;
}
V_175 -> V_181 = F_63 ;
V_175 -> V_182 = 500 ;
if ( ! V_175 -> V_183 )
V_175 -> V_183 = V_184 ;
}
return 0 ;
V_49:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_69 ( struct V_143 * V_134 , T_2 * V_185 ,
struct V_186 * V_187 )
{
struct V_5 * V_6 = F_70 ( V_134 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_42 , V_27 , F_71 ( V_134 ) -> V_133 ) ;
if ( V_6 -> V_16 -> V_166 == V_167 )
V_187 -> V_188 . V_189 . V_190 = 5 * 188 ;
return 0 ;
}
static int F_72 ( struct V_132 * V_52 , int V_191 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
return V_9 -> V_135 . V_192 ( V_52 -> V_134 [ 0 ] , V_191 ) ;
}
static int F_73 ( struct V_132 * V_52 , int V_193 , T_1 V_194 ,
int V_191 )
{
struct V_9 * V_9 = F_50 ( V_52 ) ;
return V_9 -> V_135 . V_195 ( V_52 -> V_134 [ 0 ] , V_193 , V_194 , V_191 ) ;
}
static int F_74 ( struct V_196 * V_197 ,
const struct V_198 * V_133 )
{
struct V_199 * V_16 = F_75 ( V_197 ) ;
char V_200 [ sizeof( L_43 ) ] ;
memset ( V_200 , 0 , sizeof( V_200 ) ) ;
F_76 ( V_16 , V_16 -> V_201 . V_202 ,
V_200 , sizeof( V_200 ) ) ;
if ( ( F_77 ( V_16 -> V_201 . V_203 ) == V_204 ) &&
( F_77 ( V_16 -> V_201 . V_205 ) == 0x0099 ) ) {
if ( ! strcmp ( L_43 , V_200 ) ) {
F_11 ( & V_16 -> V_17 , L_44 , V_27 ) ;
return - V_48 ;
}
}
return F_78 ( V_197 , V_133 ) ;
}
