static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 ;
if ( V_5 != 0xff ) {
V_6 = F_2 ( V_2 -> V_8 , V_3 , & V_7 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_5 ;
V_7 &= ~ V_5 ;
V_4 |= V_7 ;
}
return F_3 ( V_2 -> V_8 , V_3 , & V_4 , 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
int V_6 , V_13 ;
unsigned int V_14 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_5 ( & V_2 -> V_17 ) ;
V_6 = F_3 ( V_2 -> V_8 , 0x00 , V_10 -> args , V_10 -> V_18 ) ;
if ( V_6 )
goto V_19;
V_6 = F_6 ( V_2 -> V_8 , 0x1f , 1 ) ;
if ( V_6 )
goto V_19;
for ( V_13 = 1000 , V_14 = 1 ; V_13 && V_14 ; V_13 -- ) {
V_6 = F_7 ( V_2 -> V_8 , 0x1f , & V_14 ) ;
if ( V_6 )
goto V_19;
F_8 ( 200 , 5000 ) ;
}
F_9 ( & V_2 -> V_17 ) ;
F_10 ( & V_12 -> V_2 , L_1 , V_13 ) ;
if ( V_13 == 0 ) {
V_6 = - V_20 ;
goto error;
}
return V_6 ;
V_19:
F_9 ( & V_2 -> V_17 ) ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_11 ( struct V_21 * V_22 ,
enum V_23 V_23 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 ;
T_1 V_25 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_10 ( & V_12 -> V_2 , L_3 , V_23 ) ;
switch ( V_23 ) {
case V_26 :
V_25 = 1 ;
break;
case V_27 :
V_25 = 0 ;
break;
default:
F_10 ( & V_12 -> V_2 , L_4 ) ;
V_6 = - V_28 ;
goto error;
}
V_10 . args [ 0 ] = V_29 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 0x00 ;
V_10 . args [ 3 ] = 0x00 ;
V_10 . args [ 4 ] = V_25 ;
V_10 . V_18 = 5 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_21 * V_22 ,
enum V_30 V_30 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 ;
T_1 V_31 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_10 ( & V_12 -> V_2 , L_5 , V_30 ) ;
switch ( V_30 ) {
case V_32 :
V_31 = 0 ;
break;
case V_33 :
V_31 = 1 ;
break;
case V_34 :
V_31 = 0 ;
break;
default:
F_10 ( & V_12 -> V_2 , L_6 ) ;
V_6 = - V_28 ;
goto error;
}
V_10 . args [ 0 ] = V_35 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = V_31 ;
V_10 . V_18 = 3 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 , V_13 ;
unsigned int V_14 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_10 ( & V_12 -> V_2 , L_7 , V_37 -> V_38 ) ;
if ( V_37 -> V_38 < 3 || V_37 -> V_38 > 6 ) {
V_6 = - V_28 ;
goto error;
}
for ( V_13 = 500 , V_14 = 0 ; V_13 && ! V_14 ; V_13 -- ) {
V_6 = F_7 ( V_2 -> V_8 , 0x47 , & V_14 ) ;
if ( V_6 )
goto error;
V_14 = ( V_14 >> 0 ) & 1 ;
F_8 ( 10000 , 20000 ) ;
}
F_10 ( & V_12 -> V_2 , L_1 , V_13 ) ;
if ( V_13 == 0 ) {
V_6 = - V_20 ;
goto error;
}
V_6 = F_14 ( V_2 -> V_8 , 0x47 , 0x01 , 0x00 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_39 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 0 ;
V_10 . args [ 3 ] = 0 ;
V_10 . args [ 4 ] = 2 ;
V_10 . args [ 5 ] = 0 ;
V_10 . args [ 6 ] = V_37 -> V_38 ;
memcpy ( & V_10 . args [ 7 ] , V_37 -> V_40 , V_37 -> V_38 ) ;
V_10 . V_18 = 7 + V_37 -> V_38 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_21 * V_22 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 , V_13 ;
unsigned int V_14 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_10 ( & V_12 -> V_2 , L_8 ) ;
for ( V_13 = 500 , V_14 = 0 ; V_13 && ! V_14 ; V_13 -- ) {
V_6 = F_7 ( V_2 -> V_8 , 0x47 , & V_14 ) ;
if ( V_6 )
goto error;
V_14 = ( V_14 >> 1 ) & 1 ;
F_8 ( 10000 , 20000 ) ;
}
F_10 ( & V_12 -> V_2 , L_1 , V_13 ) ;
if ( V_13 == 0 ) {
V_6 = - V_20 ;
goto error;
}
V_6 = F_7 ( V_2 -> V_8 , 0x46 , & V_14 ) ;
if ( V_6 )
goto error;
V_42 -> V_38 = V_14 & 0x1f ;
if ( V_42 -> V_38 > sizeof( V_42 -> V_40 ) )
V_42 -> V_38 = sizeof( V_42 -> V_40 ) ;
V_10 . args [ 0 ] = V_43 ;
V_10 . args [ 1 ] = 0 ;
V_10 . V_18 = 2 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_6 = F_2 ( V_2 -> V_8 , V_10 . V_18 , V_42 -> V_40 ,
V_42 -> V_38 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_21 * V_22 ,
enum V_44 V_44 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 , V_13 ;
unsigned int V_14 ;
T_1 V_45 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
F_10 ( & V_12 -> V_2 , L_9 , V_44 ) ;
switch ( V_44 ) {
case V_46 :
V_45 = 0 ;
break;
case V_47 :
V_45 = 1 ;
break;
default:
F_10 ( & V_12 -> V_2 , L_10 ) ;
V_6 = - V_28 ;
goto error;
}
for ( V_13 = 500 , V_14 = 0 ; V_13 && ! V_14 ; V_13 -- ) {
V_6 = F_7 ( V_2 -> V_8 , 0x47 , & V_14 ) ;
if ( V_6 )
goto error;
V_14 = ( V_14 >> 0 ) & 1 ;
F_8 ( 10000 , 20000 ) ;
}
F_10 ( & V_12 -> V_2 , L_1 , V_13 ) ;
if ( V_13 == 0 ) {
V_6 = - V_20 ;
goto error;
}
V_6 = F_14 ( V_2 -> V_8 , 0x47 , 0x01 , 0x00 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_48 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = V_45 ;
V_10 . V_18 = 3 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_21 * V_22 , enum V_49 * V_50 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_51 * V_52 = & V_22 -> V_53 ;
struct V_9 V_10 ;
int V_6 ;
unsigned int V_14 ;
T_1 V_54 [ 8 ] ;
* V_50 = 0 ;
if ( ! V_2 -> V_15 ) {
V_6 = 0 ;
goto error;
}
V_6 = F_7 ( V_2 -> V_8 , 0x39 , & V_14 ) ;
if ( V_6 )
goto error;
if ( V_14 & 0x02 )
* V_50 |= V_55 | V_56 ;
if ( V_14 & 0x04 )
* V_50 |= V_57 ;
if ( V_14 & 0x08 )
* V_50 |= V_58 | V_59 ;
V_2 -> V_49 = * V_50 ;
if ( V_2 -> V_49 & V_55 ) {
V_10 . args [ 0 ] = V_60 ;
V_10 . args [ 1 ] = 0 ;
V_10 . V_18 = 2 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_6 = F_7 ( V_2 -> V_8 , 0x50 , & V_14 ) ;
if ( V_6 )
goto error;
V_52 -> V_61 . V_62 [ 0 ] . V_63 = V_64 ;
V_52 -> V_61 . V_62 [ 0 ] . V_65 = ( int ) ( V_14 - 256 ) * 1000 ;
} else {
V_52 -> V_61 . V_62 [ 0 ] . V_63 = V_66 ;
}
if ( V_2 -> V_49 & V_57 ) {
V_6 = F_2 ( V_2 -> V_8 , 0x3a , V_54 , 2 ) ;
if ( V_6 )
goto error;
V_52 -> V_67 . V_62 [ 0 ] . V_63 = V_64 ;
V_52 -> V_67 . V_62 [ 0 ] . V_65 = ( V_54 [ 0 ] << 8 | V_54 [ 1 ] << 0 ) * 100 ;
} else {
V_52 -> V_67 . V_62 [ 0 ] . V_63 = V_66 ;
}
if ( V_2 -> V_49 & V_59 ) {
T_1 V_68 , V_3 , V_18 ;
switch ( V_2 -> V_68 ) {
case V_69 :
V_3 = 0x4c ;
V_18 = 8 ;
V_68 = 1 ;
break;
case V_70 :
V_3 = 0x4d ;
V_18 = 4 ;
V_68 = 0 ;
break;
default:
V_6 = - V_28 ;
goto error;
}
V_6 = F_7 ( V_2 -> V_8 , V_3 , & V_14 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_71 == V_14 ) {
F_10 ( & V_12 -> V_2 , L_11 , V_14 ) ;
V_6 = 0 ;
goto error;
} else {
V_2 -> V_71 = V_14 ;
}
V_10 . args [ 0 ] = V_72 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = V_68 ;
V_10 . V_18 = 3 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_6 = F_2 ( V_2 -> V_8 , V_10 . V_18 , V_54 , V_18 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_68 == V_69 ) {
V_2 -> V_73 = V_54 [ 0 ] << 24 | V_54 [ 1 ] << 16 |
V_54 [ 2 ] << 8 | V_54 [ 3 ] << 0 ;
V_2 -> V_74 += V_54 [ 0 ] << 24 | V_54 [ 1 ] << 16 |
V_54 [ 2 ] << 8 | V_54 [ 3 ] << 0 ;
V_52 -> V_74 . V_62 [ 0 ] . V_63 = V_75 ;
V_52 -> V_74 . V_62 [ 0 ] . V_76 = V_2 -> V_74 ;
V_2 -> V_77 += V_54 [ 4 ] << 8 | V_54 [ 5 ] << 0 ;
V_52 -> V_77 . V_62 [ 0 ] . V_63 = V_75 ;
V_52 -> V_77 . V_62 [ 0 ] . V_76 = V_2 -> V_77 ;
} else {
V_2 -> V_73 = V_54 [ 0 ] << 8 | V_54 [ 1 ] << 0 ;
V_2 -> V_74 += V_54 [ 0 ] << 8 | V_54 [ 1 ] << 0 ;
V_52 -> V_74 . V_62 [ 0 ] . V_63 = V_75 ;
V_52 -> V_74 . V_62 [ 0 ] . V_76 = V_2 -> V_74 ;
V_52 -> V_77 . V_62 [ 0 ] . V_63 = V_66 ;
}
} else {
V_52 -> V_74 . V_62 [ 0 ] . V_63 = V_66 ;
V_52 -> V_77 . V_62 [ 0 ] . V_63 = V_66 ;
}
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_21 * V_22 , T_2 * V_78 )
{
struct V_51 * V_52 = & V_22 -> V_53 ;
if ( V_52 -> V_67 . V_62 [ 0 ] . V_63 == V_64 )
* V_78 = F_19 ( V_52 -> V_67 . V_62 [ 0 ] . V_65 , 100 ) ;
else
* V_78 = 0 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , T_2 * V_61 )
{
struct V_51 * V_52 = & V_22 -> V_53 ;
unsigned int V_14 ;
if ( V_52 -> V_61 . V_62 [ 0 ] . V_63 == V_64 ) {
V_14 = F_19 ( V_52 -> V_61 . V_62 [ 0 ] . V_65 , 1000 ) + 256 ;
V_14 = F_21 ( V_14 , 181U , 236U ) ;
* V_61 = ( V_14 - 181 ) * 0xffff / ( 236 - 181 ) ;
} else {
* V_61 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_3 * V_79 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_79 = V_2 -> V_73 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 , T_3 * V_80 )
{
struct V_51 * V_52 = & V_22 -> V_53 ;
if ( V_52 -> V_77 . V_62 [ 0 ] . V_63 == V_75 )
* V_80 = V_52 -> V_77 . V_62 [ 0 ] . V_76 ;
else
* V_80 = 0 ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
struct V_51 * V_52 = & V_22 -> V_53 ;
int V_6 , V_13 ;
T_1 V_81 , V_82 , V_83 , V_84 , div ;
enum V_85 V_86 ;
F_10 ( & V_12 -> V_2 ,
L_12 ,
V_52 -> V_68 , V_52 -> V_86 , V_52 -> V_87 , V_52 -> V_88 ,
V_52 -> V_84 , V_52 -> V_83 , V_52 -> V_82 ) ;
V_2 -> V_68 = V_89 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
switch ( V_52 -> V_84 ) {
case V_90 :
V_84 = 1 ;
break;
case V_91 :
V_84 = 0 ;
break;
case V_92 :
V_84 = 3 ;
break;
default:
F_10 ( & V_12 -> V_2 , L_13 ) ;
V_6 = - V_28 ;
goto error;
}
switch ( V_52 -> V_68 ) {
case V_69 :
V_86 = V_93 ;
V_82 = 0 ;
V_83 = 2 ;
break;
case V_70 :
V_86 = V_52 -> V_86 ;
switch ( V_52 -> V_82 ) {
case V_94 :
V_82 = 2 ;
break;
case V_95 :
V_82 = 1 ;
break;
case V_96 :
V_82 = 0 ;
break;
case V_97 :
default:
F_10 ( & V_12 -> V_2 , L_14 ) ;
V_6 = - V_28 ;
goto error;
}
switch ( V_52 -> V_83 ) {
case V_98 :
V_83 = 0 ;
break;
case V_99 :
V_83 = 1 ;
break;
case V_100 :
V_83 = 2 ;
break;
default:
F_10 ( & V_12 -> V_2 , L_15 ) ;
V_6 = - V_28 ;
goto error;
}
break;
default:
F_10 ( & V_12 -> V_2 , L_16 ) ;
V_6 = - V_28 ;
goto error;
}
for ( V_13 = 0 , V_81 = 0xff ; V_13 < F_25 ( V_101 ) ; V_13 ++ ) {
if ( V_52 -> V_68 == V_101 [ V_13 ] . V_68 &&
V_86 == V_101 [ V_13 ] . V_86 &&
V_52 -> V_102 == V_101 [ V_13 ] . V_103 ) {
V_81 = V_101 [ V_13 ] . V_4 ;
F_10 ( & V_12 -> V_2 , L_17 , V_81 ) ;
break;
}
}
if ( V_81 == 0xff ) {
F_10 ( & V_12 -> V_2 , L_18 ) ;
V_6 = - V_28 ;
goto error;
}
if ( V_52 -> V_88 <= 5000000 )
div = 14 ;
else
div = 4 ;
V_6 = F_6 ( V_2 -> V_8 , 0x81 , div ) ;
if ( V_6 )
goto error;
V_6 = F_6 ( V_2 -> V_8 , 0xe3 , div ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_104 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = V_81 ;
V_10 . args [ 3 ] = ( V_52 -> V_87 >> 16 ) & 0xff ;
V_10 . args [ 4 ] = ( V_52 -> V_87 >> 8 ) & 0xff ;
V_10 . args [ 5 ] = ( V_52 -> V_87 >> 0 ) & 0xff ;
V_10 . args [ 6 ] = ( ( V_52 -> V_88 / 1000 ) >> 8 ) & 0xff ;
V_10 . args [ 7 ] = ( ( V_52 -> V_88 / 1000 ) >> 0 ) & 0xff ;
V_10 . args [ 8 ] = ( V_105 . V_106 . V_107 >> 8 ) & 0xff ;
V_10 . args [ 9 ] = ( V_105 . V_106 . V_107 >> 0 ) & 0xff ;
V_10 . args [ 10 ] = V_82 ;
V_10 . args [ 11 ] = V_84 ;
V_10 . args [ 12 ] = V_83 ;
V_10 . args [ 13 ] = 0x00 ;
V_10 . args [ 14 ] = 0x00 ;
V_10 . V_18 = 15 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_2 -> V_68 = V_52 -> V_68 ;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_51 * V_52 = & V_22 -> V_53 ;
int V_6 , V_13 ;
T_1 V_54 [ 5 ] , V_7 ;
if ( ! V_2 -> V_15 || ! ( V_2 -> V_49 & V_59 ) ) {
V_6 = 0 ;
goto error;
}
V_6 = F_2 ( V_2 -> V_8 , 0x30 , V_54 , 5 ) ;
if ( V_6 )
goto error;
V_7 = V_54 [ 0 ] & 0x3f ;
for ( V_13 = 0 ; V_13 < F_25 ( V_101 ) ; V_13 ++ ) {
if ( V_7 == V_101 [ V_13 ] . V_4 ) {
V_52 -> V_86 = V_101 [ V_13 ] . V_86 ;
V_52 -> V_102 = V_101 [ V_13 ] . V_103 ;
V_52 -> V_68 = V_101 [ V_13 ] . V_68 ;
}
}
switch ( ( V_54 [ 1 ] >> 0 ) & 0x01 ) {
case 0 :
V_52 -> V_84 = V_91 ;
break;
case 1 :
V_52 -> V_84 = V_90 ;
break;
}
switch ( ( V_54 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_52 -> V_83 = V_98 ;
break;
case 1 :
V_52 -> V_83 = V_99 ;
break;
}
V_52 -> V_87 = ( V_54 [ 2 ] << 16 ) | ( V_54 [ 3 ] << 8 ) | ( V_54 [ 4 ] << 0 ) ;
V_6 = F_2 ( V_2 -> V_8 , 0x52 , V_54 , 3 ) ;
if ( V_6 )
goto error;
V_52 -> V_88 = ( ( V_54 [ 0 ] << 16 ) | ( V_54 [ 1 ] << 8 ) | ( V_54 [ 2 ] << 0 ) ) * 1000 ;
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_51 * V_52 = & V_22 -> V_53 ;
struct V_9 V_10 ;
int V_6 , V_13 , V_18 , V_108 , V_109 ;
unsigned int V_14 ;
const struct V_110 * V_111 ;
T_1 * V_112 = V_113 ;
T_1 V_7 , V_54 [ 4 ] ;
struct V_114 V_115 [] = {
{ 0xcd , 0x00 , 0x07 } ,
{ 0x80 , 0x00 , 0x02 } ,
{ 0xcd , 0x00 , 0xc0 } ,
{ 0xce , 0x00 , 0x1b } ,
{ 0x9d , 0x00 , 0x01 } ,
{ 0x9d , 0x00 , 0x02 } ,
{ 0x9e , 0x00 , 0x01 } ,
{ 0x87 , 0x00 , 0x80 } ,
{ 0xce , 0x00 , 0x08 } ,
{ 0xce , 0x00 , 0x10 } ,
} ;
struct V_114 V_116 [] = {
{ 0xf1 , 0x70 , 0xff } ,
{ 0x88 , V_2 -> V_117 , 0x3f } ,
{ 0x89 , 0x00 , 0x10 } ,
{ 0x89 , 0x10 , 0x10 } ,
{ 0xc0 , 0x01 , 0x01 } ,
{ 0xc0 , 0x00 , 0x01 } ,
{ 0xe0 , 0xff , 0xff } ,
{ 0xe0 , 0x00 , 0xff } ,
{ 0x96 , 0x1e , 0x7e } ,
{ 0x8b , 0x08 , 0x08 } ,
{ 0x8b , 0x00 , 0x08 } ,
{ 0x8f , 0x1a , 0x7e } ,
{ 0x8c , 0x68 , 0xff } ,
{ 0x8d , 0x08 , 0xff } ,
{ 0x8e , 0x4c , 0xff } ,
{ 0x8f , 0x01 , 0x01 } ,
{ 0x8b , 0x04 , 0x04 } ,
{ 0x8b , 0x00 , 0x04 } ,
{ 0x87 , 0x05 , 0x07 } ,
{ 0x80 , 0x00 , 0x20 } ,
{ 0xc8 , 0x01 , 0xff } ,
{ 0xb4 , 0x47 , 0xff } ,
{ 0xb5 , 0x9c , 0xff } ,
{ 0xb6 , 0x7d , 0xff } ,
{ 0xba , 0x00 , 0x03 } ,
{ 0xb7 , 0x47 , 0xff } ,
{ 0xb8 , 0x9c , 0xff } ,
{ 0xb9 , 0x7d , 0xff } ,
{ 0xba , 0x00 , 0x0c } ,
{ 0xc8 , 0x00 , 0xff } ,
{ 0xcd , 0x00 , 0x04 } ,
{ 0xcd , 0x00 , 0x20 } ,
{ 0xe8 , 0x02 , 0xff } ,
{ 0xcf , 0x20 , 0xff } ,
{ 0x9b , 0xd7 , 0xff } ,
{ 0x9a , 0x01 , 0x03 } ,
{ 0xa8 , 0x05 , 0x0f } ,
{ 0xa8 , 0x65 , 0xf0 } ,
{ 0xa6 , 0xa0 , 0xf0 } ,
{ 0x9d , 0x50 , 0xfc } ,
{ 0x9e , 0x20 , 0xe0 } ,
{ 0xa3 , 0x1c , 0x7c } ,
{ 0xd5 , 0x03 , 0x03 } ,
} ;
if ( V_2 -> V_15 ) {
for ( V_13 = 0 ; V_13 < F_25 ( V_115 ) ; V_13 ++ ) {
V_6 = F_1 ( V_2 , V_115 [ V_13 ] . V_3 ,
V_115 [ V_13 ] . V_4 , V_115 [ V_13 ] . V_5 ) ;
if ( V_6 )
goto error;
}
V_10 . args [ 0 ] = V_118 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 0 ;
V_10 . V_18 = 3 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
} else {
V_6 = F_28 ( & V_111 , V_112 , & V_12 -> V_2 ) ;
if ( V_6 ) {
F_29 ( & V_12 -> V_2 ,
L_19 ,
V_112 , V_6 ) ;
goto error;
}
for ( V_13 = 0 ; V_13 < F_25 ( V_116 ) ; V_13 ++ ) {
V_6 = F_1 ( V_2 , V_116 [ V_13 ] . V_3 ,
V_116 [ V_13 ] . V_4 , V_116 [ V_13 ] . V_5 ) ;
if ( V_6 )
goto V_119;
}
V_6 = F_6 ( V_2 -> V_8 , 0xe0 , 0x7f ) ;
if ( V_6 )
goto V_119;
V_6 = F_6 ( V_2 -> V_8 , 0xf7 , 0x81 ) ;
if ( V_6 )
goto V_119;
V_6 = F_6 ( V_2 -> V_8 , 0xf8 , 0x00 ) ;
if ( V_6 )
goto V_119;
V_6 = F_6 ( V_2 -> V_8 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_119;
F_30 ( & V_12 -> V_2 ,
L_20 ,
V_105 . V_106 . V_120 ) ;
F_30 ( & V_12 -> V_2 , L_21 ,
V_112 ) ;
V_109 = V_111 -> V_121 - 1 ;
for ( V_108 = V_109 ; V_108 > 0 ;
V_108 -= ( V_2 -> V_122 - 1 ) ) {
V_18 = V_108 ;
if ( V_18 > ( V_2 -> V_122 - 1 ) )
V_18 = ( V_2 -> V_122 - 1 ) ;
V_6 = F_3 ( V_2 -> V_8 , 0xfa ,
( T_1 * ) & V_111 -> V_123 [ V_109 - V_108 ] , V_18 ) ;
if ( V_6 ) {
F_29 ( & V_12 -> V_2 ,
L_22 , V_6 ) ;
goto V_119;
}
}
F_31 ( V_111 ) ;
V_6 = F_6 ( V_2 -> V_8 , 0xf7 , 0x0c ) ;
if ( V_6 )
goto error;
V_6 = F_6 ( V_2 -> V_8 , 0xe0 , 0x00 ) ;
if ( V_6 )
goto error;
F_32 ( 250 ) ;
V_6 = F_7 ( V_2 -> V_8 , 0x51 , & V_14 ) ;
if ( V_6 )
goto error;
if ( V_14 ) {
F_30 ( & V_12 -> V_2 , L_23 ) ;
V_6 = - V_16 ;
goto error;
} else {
V_2 -> V_15 = true ;
}
V_10 . args [ 0 ] = V_124 ;
V_10 . V_18 = 1 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_6 = F_2 ( V_2 -> V_8 , V_10 . V_18 , V_54 , 4 ) ;
if ( V_6 )
goto error;
F_30 ( & V_12 -> V_2 , L_24 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ) ;
F_30 ( & V_12 -> V_2 , L_25 ,
V_105 . V_106 . V_120 ) ;
V_6 = F_2 ( V_2 -> V_8 , 0x81 , V_54 , 2 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_125 ;
V_10 . args [ 1 ] = ( ( V_2 -> V_126 / 1000 ) >> 8 ) & 0xff ;
V_10 . args [ 2 ] = ( ( V_2 -> V_126 / 1000 ) >> 0 ) & 0xff ;
V_10 . args [ 3 ] = V_54 [ 0 ] ;
V_10 . args [ 4 ] = V_54 [ 1 ] ;
V_10 . args [ 5 ] = V_2 -> V_117 ;
V_10 . args [ 6 ] = V_2 -> V_127 ;
V_10 . args [ 7 ] = 0x00 ;
V_10 . V_18 = 8 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_128 )
V_7 = V_2 -> V_128 ;
else
V_7 = 0x14 ;
V_10 . args [ 0 ] = V_129 ;
V_10 . args [ 1 ] = 0x00 ;
V_10 . args [ 2 ] = 0x00 ;
V_10 . args [ 3 ] = 0x00 ;
V_10 . args [ 4 ] = 0x00 ;
V_10 . args [ 5 ] = V_7 ;
V_10 . args [ 6 ] = 0x00 ;
V_10 . args [ 7 ] = 0x03 ;
V_10 . args [ 8 ] = 0x02 ;
V_10 . args [ 9 ] = 0x02 ;
V_10 . args [ 10 ] = 0x00 ;
V_10 . args [ 11 ] = 0x00 ;
V_10 . args [ 12 ] = 0x00 ;
V_10 . args [ 13 ] = 0x00 ;
V_10 . args [ 14 ] = 0x00 ;
V_10 . V_18 = 15 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_130 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = V_2 -> V_131 ;
V_10 . args [ 3 ] = 0x00 ;
V_10 . args [ 4 ] = 0x04 ;
V_10 . args [ 5 ] = 0x00 ;
V_10 . V_18 = 6 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_6 = F_14 ( V_2 -> V_8 , 0xf0 , 0x01 , 0x01 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_132 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 150 ;
V_10 . args [ 3 ] = 3 ;
V_10 . args [ 4 ] = 22 ;
V_10 . args [ 5 ] = 1 ;
V_10 . args [ 6 ] = 1 ;
V_10 . args [ 7 ] = 30 ;
V_10 . args [ 8 ] = 30 ;
V_10 . args [ 9 ] = 30 ;
V_10 . args [ 10 ] = 30 ;
V_10 . V_18 = 11 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
V_10 . args [ 0 ] = V_133 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 14 ;
V_10 . args [ 3 ] = 14 ;
V_10 . V_18 = 4 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
}
V_52 -> V_61 . V_18 = 1 ;
V_52 -> V_61 . V_62 [ 0 ] . V_63 = V_66 ;
V_52 -> V_67 . V_18 = 1 ;
V_52 -> V_67 . V_62 [ 0 ] . V_63 = V_66 ;
V_52 -> V_74 . V_18 = 1 ;
V_52 -> V_74 . V_62 [ 0 ] . V_63 = V_66 ;
V_52 -> V_77 . V_18 = 1 ;
V_52 -> V_77 . V_62 [ 0 ] . V_63 = V_66 ;
return V_6 ;
V_119:
F_31 ( V_111 ) ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_33 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_9 V_10 ;
int V_6 , V_13 ;
struct V_114 V_115 [] = {
{ 0xcd , 0x07 , 0x07 } ,
{ 0x80 , 0x02 , 0x02 } ,
{ 0xcd , 0xc0 , 0xc0 } ,
{ 0xce , 0x1b , 0x1b } ,
{ 0x9d , 0x01 , 0x01 } ,
{ 0x9d , 0x02 , 0x02 } ,
{ 0x9e , 0x01 , 0x01 } ,
{ 0x87 , 0x80 , 0x80 } ,
{ 0xce , 0x08 , 0x08 } ,
{ 0xce , 0x10 , 0x10 } ,
} ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto error;
}
V_10 . args [ 0 ] = V_118 ;
V_10 . args [ 1 ] = 0 ;
V_10 . args [ 2 ] = 1 ;
V_10 . V_18 = 3 ;
V_6 = F_4 ( V_2 , & V_10 ) ;
if ( V_6 )
goto error;
for ( V_13 = 0 ; V_13 < F_25 ( V_115 ) ; V_13 ++ ) {
V_6 = F_1 ( V_2 , V_115 [ V_13 ] . V_3 , V_115 [ V_13 ] . V_4 ,
V_115 [ V_13 ] . V_5 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
error:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_134 * V_135 )
{
V_135 -> V_136 = 8000 ;
V_135 -> V_137 = 0 ;
V_135 -> V_138 = 0 ;
return 0 ;
}
static struct V_21 * F_35 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_36 ( V_12 ) ;
F_10 ( & V_12 -> V_2 , L_8 ) ;
return & V_2 -> V_22 ;
}
static int F_37 ( struct V_11 * V_12 ,
const struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_141 * V_142 = V_12 -> V_2 . V_143 ;
int V_6 ;
unsigned int V_14 ;
static const struct V_144 V_144 = {
. V_145 = 8 ,
. V_146 = 8 ,
} ;
V_2 = F_38 ( sizeof( * V_2 ) , V_147 ) ;
if ( ! V_2 ) {
V_6 = - V_148 ;
goto V_149;
}
V_2 -> V_12 = V_12 ;
F_39 ( & V_2 -> V_17 ) ;
V_2 -> V_126 = V_142 -> V_126 ;
V_2 -> V_122 = V_142 -> V_122 ;
V_2 -> V_131 = V_142 -> V_131 ;
V_2 -> V_127 = V_142 -> V_127 ;
V_2 -> V_117 = V_142 -> V_117 ;
V_2 -> V_128 = V_142 -> V_128 ;
V_2 -> V_8 = F_40 ( V_12 , & V_144 ) ;
if ( F_41 ( V_2 -> V_8 ) ) {
V_6 = F_42 ( V_2 -> V_8 ) ;
goto V_150;
}
V_6 = F_7 ( V_2 -> V_8 , 0xff , & V_14 ) ;
if ( V_6 )
goto V_150;
if ( V_14 != 0x0f ) {
V_6 = - V_151 ;
goto V_150;
}
V_6 = F_7 ( V_2 -> V_8 , 0xdd , & V_14 ) ;
if ( V_6 )
goto V_150;
if ( V_14 != 0x00 ) {
V_6 = - V_151 ;
goto V_150;
}
V_6 = F_7 ( V_2 -> V_8 , 0xfe , & V_14 ) ;
if ( V_6 )
goto V_150;
if ( V_14 != 0x01 ) {
V_6 = - V_151 ;
goto V_150;
}
memcpy ( & V_2 -> V_22 . V_152 , & V_105 , sizeof( struct V_153 ) ) ;
V_2 -> V_22 . V_24 = V_2 ;
F_43 ( V_12 , V_2 ) ;
V_142 -> V_154 = F_35 ;
F_30 ( & V_12 -> V_2 , L_26 ) ;
return 0 ;
V_150:
F_44 ( V_2 ) ;
V_149:
F_10 ( & V_12 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_36 ( V_12 ) ;
F_10 ( & V_12 -> V_2 , L_8 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
