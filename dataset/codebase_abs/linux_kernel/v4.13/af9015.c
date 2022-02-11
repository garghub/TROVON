static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 8
#define F_3 2
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 , V_8 , V_9 ;
T_1 V_10 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
V_6 -> V_12 [ 0 ] = V_4 -> V_13 ;
V_6 -> V_12 [ 1 ] = V_6 -> V_14 ++ ;
V_6 -> V_12 [ 2 ] = V_4 -> V_15 << 1 ;
V_6 -> V_12 [ 3 ] = V_4 -> V_16 >> 8 ;
V_6 -> V_12 [ 4 ] = V_4 -> V_16 & 0xff ;
V_6 -> V_12 [ 5 ] = V_4 -> V_17 ;
V_6 -> V_12 [ 6 ] = V_4 -> V_18 ;
V_6 -> V_12 [ 7 ] = V_4 -> V_19 ;
switch ( V_4 -> V_13 ) {
case V_20 :
case V_21 :
case V_22 :
V_10 = 0 ;
break;
case V_23 :
V_10 = 0 ;
V_6 -> V_12 [ 2 ] |= 0x01 ;
case V_24 :
V_6 -> V_12 [ 0 ] = V_25 ;
break;
case V_26 :
if ( ( ( V_4 -> V_16 & 0xff00 ) == 0xff00 ) ||
( ( V_4 -> V_16 & 0xff00 ) == 0xae00 ) )
V_6 -> V_12 [ 0 ] = V_27 ;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_1 ,
V_33 , V_4 -> V_13 ) ;
V_7 = - V_34 ;
goto error;
}
if ( ( V_10 && ( V_4 -> V_19 > V_35 - F_2 ) ) ||
( ! V_10 && ( V_4 -> V_19 > V_35 - F_3 ) ) ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_2 ,
V_33 , V_4 -> V_13 , V_4 -> V_19 ) ;
V_7 = - V_36 ;
goto error;
}
V_8 = F_2 ;
V_9 = F_3 ;
if ( V_10 ) {
V_8 += V_4 -> V_19 ;
memcpy ( & V_6 -> V_12 [ F_2 ] , V_4 -> V_37 , V_4 -> V_19 ) ;
} else {
V_9 += V_4 -> V_19 ;
}
if ( V_4 -> V_13 == V_29 || V_4 -> V_13 == V_22 )
V_9 = 0 ;
V_7 = F_7 ( V_2 ,
V_6 -> V_12 , V_8 , V_6 -> V_12 , V_9 ) ;
if ( V_7 )
goto error;
if ( V_9 && V_6 -> V_12 [ 1 ] ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_3 ,
V_33 , V_6 -> V_12 [ 1 ] ) ;
V_7 = - V_34 ;
goto error;
}
if ( ! V_10 )
memcpy ( V_4 -> V_37 , & V_6 -> V_12 [ F_3 ] , V_4 -> V_19 ) ;
error:
F_8 ( & V_2 -> V_11 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 ,
T_1 V_39 )
{
struct V_3 V_4 = { V_26 , V_40 , V_16 , 0 , 0 , V_39 ,
V_38 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 , T_1 V_39 )
{
struct V_3 V_4 = { V_21 , V_40 , V_16 , 0 , 0 , V_39 ,
V_38 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_38 )
{
return F_9 ( V_2 , V_16 , & V_38 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 )
{
return F_10 ( V_2 , V_16 , V_38 , 1 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_16 , T_2 V_41 ,
T_1 V_38 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_3 V_4 = { V_24 , V_16 , V_41 , 1 , 1 , 1 , & V_38 } ;
if ( V_16 == V_6 -> V_42 [ 0 ] . V_15 ||
V_16 == V_6 -> V_42 [ 1 ] . V_15 )
V_4 . V_18 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_16 , T_2 V_41 ,
T_1 * V_38 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_3 V_4 = { V_23 , V_16 , V_41 , 0 , 1 , 1 , V_38 } ;
if ( V_16 == V_6 -> V_42 [ 0 ] . V_15 ||
V_16 == V_6 -> V_42 [ 1 ] . V_15 )
V_4 . V_18 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 , T_1 V_44 )
{
int V_7 ;
T_1 V_38 , V_45 = 0x01 ;
V_7 = F_12 ( V_2 , V_16 , & V_38 ) ;
if ( V_7 )
return V_7 ;
V_45 <<= V_43 ;
if ( V_44 ) {
V_38 |= V_45 ;
} else {
V_45 ^= 0xff ;
V_38 &= V_45 ;
}
return F_11 ( V_2 , V_16 , V_38 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 )
{
return F_15 ( V_2 , V_16 , V_43 , 1 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 )
{
return F_15 ( V_2 , V_16 , V_43 , 0 ) ;
}
static int F_18 ( struct V_46 * V_47 , struct V_48 V_49 [] ,
int V_50 )
{
struct V_1 * V_2 = F_19 ( V_47 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_2 V_16 ;
T_1 V_17 , V_18 ;
struct V_3 V_4 ;
if ( V_49 [ 0 ] . V_39 == 0 || V_49 [ 0 ] . V_51 & V_52 ) {
V_16 = 0x0000 ;
V_17 = 0 ;
V_18 = 0 ;
} else if ( V_49 [ 0 ] . V_39 == 1 ) {
V_16 = V_49 [ 0 ] . V_12 [ 0 ] ;
V_17 = 0 ;
V_18 = 1 ;
} else if ( V_49 [ 0 ] . V_39 == 2 ) {
V_16 = V_49 [ 0 ] . V_12 [ 0 ] << 8 | V_49 [ 0 ] . V_12 [ 1 ] << 0 ;
V_17 = 0 ;
V_18 = 2 ;
} else {
V_16 = V_49 [ 0 ] . V_12 [ 0 ] << 8 | V_49 [ 0 ] . V_12 [ 1 ] << 0 ;
V_17 = V_49 [ 0 ] . V_12 [ 2 ] ;
V_18 = 3 ;
}
if ( V_50 == 1 && ! ( V_49 [ 0 ] . V_51 & V_52 ) ) {
if ( V_49 [ 0 ] . V_39 > 21 ) {
V_7 = - V_53 ;
goto V_54;
}
if ( V_49 [ 0 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 )
V_4 . V_13 = V_26 ;
else
V_4 . V_13 = V_24 ;
V_4 . V_15 = V_49 [ 0 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ 0 ] . V_39 - V_18 ;
V_4 . V_37 = & V_49 [ 0 ] . V_12 [ V_18 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
} else if ( V_50 == 2 && ! ( V_49 [ 0 ] . V_51 & V_52 ) &&
( V_49 [ 1 ] . V_51 & V_52 ) ) {
if ( V_49 [ 0 ] . V_39 > 3 || V_49 [ 1 ] . V_39 > 61 ) {
V_7 = - V_53 ;
goto V_54;
}
if ( V_49 [ 0 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 )
V_4 . V_13 = V_21 ;
else
V_4 . V_13 = V_23 ;
V_4 . V_15 = V_49 [ 0 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ 1 ] . V_39 ;
V_4 . V_37 = & V_49 [ 1 ] . V_12 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
} else if ( V_50 == 1 && ( V_49 [ 0 ] . V_51 & V_52 ) ) {
if ( V_49 [ 0 ] . V_39 > 61 ) {
V_7 = - V_53 ;
goto V_54;
}
if ( V_49 [ 0 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 ) {
V_7 = - V_36 ;
goto V_54;
}
V_4 . V_13 = V_23 ;
V_4 . V_15 = V_49 [ 0 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ 0 ] . V_39 ;
V_4 . V_37 = & V_49 [ 0 ] . V_12 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
} else {
V_7 = - V_53 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_4 ,
V_55 , V_50 ) ;
}
if ( V_7 )
goto V_54;
return V_50 ;
V_54:
F_20 ( & V_2 -> V_31 -> V_32 , L_5 , V_55 , V_7 ) ;
return V_7 ;
}
static T_3 F_21 ( struct V_46 * V_56 )
{
return V_57 ;
}
static int F_22 ( struct V_1 * V_2 , const char * * V_58 )
{
int V_7 ;
T_1 V_59 ;
struct V_3 V_4 = { V_20 , 0 , 0 , 0 , 0 , 1 , & V_59 } ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
return V_7 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_6 , V_55 , V_59 ) ;
if ( V_59 == 0x02 )
V_7 = V_60 ;
else
V_7 = V_61 ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_64 , V_39 , V_65 , V_7 ;
struct V_3 V_4 = { V_29 , 0 , 0 , 0 , 0 , 0 , NULL } ;
T_2 V_66 = 0 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_7 , V_55 ) ;
for ( V_64 = 0 ; V_64 < V_63 -> V_67 ; V_64 ++ )
V_66 += V_63 -> V_37 [ V_64 ] ;
V_6 -> V_68 = V_63 -> V_67 ;
V_6 -> V_69 = V_66 ;
#define F_24 0x5100
#define F_25 55
for ( V_65 = V_63 -> V_67 ; V_65 > 0 ; V_65 -= F_25 ) {
V_39 = V_65 ;
if ( V_39 > F_25 )
V_39 = F_25 ;
V_4 . V_19 = V_39 ;
V_4 . V_37 = ( T_1 * ) & V_63 -> V_37 [ V_63 -> V_67 - V_65 ] ;
V_4 . V_16 = F_24 + V_63 -> V_67 - V_65 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_31 -> V_32 ,
L_8 ,
V_33 , V_7 ) ;
goto error;
}
}
V_4 . V_13 = V_30 ;
V_4 . V_19 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_9 ,
V_33 , V_7 ) ;
goto error;
}
error:
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 , V_64 ;
T_1 V_12 [ V_70 ] ;
struct V_3 V_4 = { V_23 , V_71 , 0 , 0 , 1 , 1 , NULL } ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
V_4 . V_16 = V_64 ;
V_4 . V_37 = & V_12 [ V_64 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 < 0 )
goto V_54;
}
for ( V_64 = 0 ; V_64 < V_70 / sizeof( T_3 ) ; V_64 ++ ) {
V_6 -> V_72 *= V_73 ;
V_6 -> V_72 += F_27 ( ( ( V_74 * ) V_12 ) [ V_64 ] ) ;
}
for ( V_64 = 0 ; V_64 < V_70 ; V_64 += 16 )
F_20 ( & V_2 -> V_31 -> V_32 , L_10 , V_55 , 16 , V_12 + V_64 ) ;
F_20 ( & V_2 -> V_31 -> V_32 , L_11 ,
V_55 , V_6 -> V_72 ) ;
return 0 ;
V_54:
F_6 ( & V_2 -> V_31 -> V_32 , L_12 , V_33 , V_7 ) ;
return V_7 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_38 , V_64 , V_75 = 0 ;
struct V_3 V_4 = { V_23 , V_71 , 0 , 0 , 1 , 1 , & V_38 } ;
F_20 ( & V_2 -> V_31 -> V_32 , L_7 , V_55 ) ;
V_4 . V_16 = V_76 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_7 )
break;
}
if ( V_7 )
goto error;
V_7 = F_26 ( V_2 ) ;
if ( V_7 )
goto error;
V_6 -> V_77 = V_38 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_13 , V_55 , V_38 ) ;
V_4 . V_16 = V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_79 = V_38 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_14 , V_55 , V_6 -> V_79 ) ;
if ( V_2 -> V_31 -> V_80 == V_81 )
V_6 -> V_79 = 0 ;
V_6 -> V_42 [ 0 ] . V_15 = V_40 ;
if ( V_6 -> V_79 ) {
V_4 . V_16 = V_82 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ 1 ] . V_15 = V_38 >> 1 ;
}
for ( V_64 = 0 ; V_64 < V_6 -> V_79 + 1 ; V_64 ++ ) {
if ( V_64 == 1 )
V_75 = V_83 ;
V_4 . V_16 = V_84 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_38 ) {
case 0 :
V_6 -> V_42 [ V_64 ] . clock = 28800000 ;
break;
case 1 :
V_6 -> V_42 [ V_64 ] . clock = 20480000 ;
break;
case 2 :
V_6 -> V_42 [ V_64 ] . clock = 28000000 ;
break;
case 3 :
V_6 -> V_42 [ V_64 ] . clock = 25000000 ;
break;
}
F_20 ( & V_2 -> V_31 -> V_32 , L_15 ,
V_55 , V_64 , V_38 ,
V_6 -> V_42 [ V_64 ] . clock ) ;
V_4 . V_16 = V_85 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ V_64 ] . V_86 = V_38 << 8 ;
V_4 . V_16 = V_87 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ V_64 ] . V_86 += V_38 ;
V_6 -> V_42 [ V_64 ] . V_86 *= 1000 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_16 , V_55 ,
V_64 , V_6 -> V_42 [ V_64 ] . V_86 ) ;
V_4 . V_16 = V_88 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_89 [ V_64 ] = V_38 << 8 ;
V_4 . V_16 = V_90 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_89 [ V_64 ] += V_38 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_17 , V_55 , V_64 ,
V_6 -> V_89 [ V_64 ] ) ;
V_4 . V_16 = V_91 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_38 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_6 -> V_42 [ V_64 ] . V_100 = 1 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_6 -> V_42 [ V_64 ] . V_100 = 0 ;
break;
case V_105 :
V_6 -> V_42 [ V_64 ] . V_106 [ 1 ] = V_107 ;
V_6 -> V_42 [ V_64 ] . V_100 = 1 ;
break;
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_18 \
L_19 ,
V_33 , V_38 ) ;
return - V_108 ;
}
V_6 -> V_42 [ V_64 ] . V_109 = V_38 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_20 ,
V_55 , V_64 , V_38 ) ;
}
error:
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_21 ,
V_33 , V_7 ) ;
if ( F_29 ( V_2 -> V_31 -> V_110 . V_111 ) == V_112 &&
( ( F_29 ( V_2 -> V_31 -> V_110 . V_113 ) ==
V_114 ) ||
( F_29 ( V_2 -> V_31 -> V_110 . V_113 ) ==
V_115 ) ) ) {
F_20 ( & V_2 -> V_31 -> V_32 ,
L_22 ,
V_55 ) ;
V_6 -> V_79 = 0 ;
V_6 -> V_42 [ 0 ] . V_86 = 4570000 ;
}
return V_7 ;
}
static int F_30 ( struct V_116 * V_117 , T_1 * V_118 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_31 ( V_117 ) ;
F_20 ( & V_2 -> V_31 -> V_32 , L_23 , V_55 , F_32 ( V_117 ) -> V_121 ) ;
if ( V_2 -> V_31 -> V_80 == V_81 )
V_120 -> V_122 . V_123 . V_124 = V_125 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
return V_6 -> V_79 + 1 ;
}
static int F_34 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_128 [ F_32 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_37 ( struct V_116 * V_117 ,
enum V_129 * V_130 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_131 [ F_32 ( V_117 ) -> V_121 ] ( V_117 , V_130 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_38 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_132 [ F_32 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_39 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_133 [ F_32 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_40 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_134 [ F_32 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_41 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_35 ( V_117 ) ;
if ( F_36 ( & V_6 -> V_126 ) )
return - V_127 ;
V_7 = V_6 -> V_135 [ F_32 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_8 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_136 [ 4 ] ;
T_1 V_38 , V_64 ;
struct V_3 V_4 = { V_28 , 0 , 0x5100 , 0 , 0 , sizeof( V_136 ) ,
V_136 } ;
F_20 ( & V_2 -> V_31 -> V_32 , L_7 , V_55 ) ;
V_136 [ 0 ] = V_6 -> V_68 >> 8 ;
V_136 [ 1 ] = V_6 -> V_68 & 0xff ;
V_136 [ 2 ] = V_6 -> V_69 >> 8 ;
V_136 [ 3 ] = V_6 -> V_69 & 0xff ;
V_7 = F_14 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0x98be , & V_38 ) ;
if ( V_7 )
goto error;
else
F_20 ( & V_2 -> V_31 -> V_32 , L_24 ,
V_55 , V_38 ) ;
if ( V_38 == 0x0c )
goto exit;
V_7 = F_11 ( V_2 , 0xd416 , 0x04 ) ;
if ( V_7 )
goto error;
F_43 ( 50 ) ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_25 ,
V_33 , V_7 ) ;
F_20 ( & V_2 -> V_31 -> V_32 , L_26 , V_55 ) ;
V_7 = F_11 ( V_2 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto error;
V_7 = F_13 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0xe205 , 1 ) ;
F_20 ( & V_2 -> V_31 -> V_32 , L_27 ,
V_55 , V_7 ) ;
if ( V_7 )
goto error;
for ( V_64 = 0 ; V_64 < 15 ; V_64 ++ ) {
F_43 ( 100 ) ;
V_7 = F_14 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0x98be , & V_38 ) ;
F_20 ( & V_2 -> V_31 -> V_32 , L_28 \
L_29 , V_55 , V_7 , V_38 ) ;
if ( V_7 )
goto error;
if ( V_38 == 0x0c || V_38 == 0x04 )
break;
}
if ( V_38 == 0x04 ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_30 ,
V_33 ) ;
V_7 = - V_137 ;
} else if ( V_38 != 0x0c ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_31 ,
V_33 ) ;
V_7 = - V_137 ;
}
error:
exit:
return V_7 ;
}
static int F_44 ( struct V_138 * V_47 )
{
int V_7 ;
struct V_5 * V_6 = F_45 ( V_47 ) ;
if ( V_47 -> V_121 == 0 ) {
V_6 -> V_42 [ 0 ] . V_139 = V_140 ;
memcpy ( V_6 -> V_42 [ 0 ] . V_141 , L_32 , 4 ) ;
V_6 -> V_42 [ 0 ] . V_106 [ 0 ] = V_142 ;
V_6 -> V_42 [ 0 ] . V_106 [ 3 ] = V_143 ;
} else if ( V_47 -> V_121 == 1 ) {
V_6 -> V_42 [ 1 ] . V_139 = V_144 ;
memcpy ( V_6 -> V_42 [ 1 ] . V_141 , L_32 , 4 ) ;
V_6 -> V_42 [ 1 ] . V_106 [ 0 ] = V_143 ;
V_6 -> V_42 [ 1 ] . V_106 [ 1 ] = V_107 ;
if ( V_6 -> V_79 ) {
F_43 ( 100 ) ;
V_7 = F_42 ( F_46 ( V_47 ) ) ;
if ( V_7 ) {
F_6 ( & F_46 ( V_47 ) -> V_31 -> V_32 ,
L_33 \
L_34 \
L_35 , V_33 ) ;
V_6 -> V_79 = 0 ;
return - V_108 ;
}
} else {
return - V_108 ;
}
}
V_47 -> V_117 [ 0 ] = F_47 ( V_145 ,
& V_6 -> V_42 [ V_47 -> V_121 ] , & F_46 ( V_47 ) -> V_146 ) ;
if ( V_47 -> V_117 [ 0 ] ) {
V_6 -> V_128 [ V_47 -> V_121 ] =
V_47 -> V_117 [ 0 ] -> V_147 . V_128 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_128 =
F_34 ;
V_6 -> V_131 [ V_47 -> V_121 ] =
V_47 -> V_117 [ 0 ] -> V_147 . V_131 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_131 =
F_37 ;
V_6 -> V_132 [ V_47 -> V_121 ] = V_47 -> V_117 [ 0 ] -> V_147 . V_132 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_132 = F_38 ;
V_6 -> V_133 [ V_47 -> V_121 ] = V_47 -> V_117 [ 0 ] -> V_147 . V_133 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_133 = F_39 ;
}
return V_47 -> V_117 [ 0 ] == NULL ? - V_108 : 0 ;
}
static int F_48 ( struct V_138 * V_47 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_7 , V_55 ) ;
switch ( V_6 -> V_42 [ V_47 -> V_121 ] . V_109 ) {
case V_93 :
case V_96 :
V_7 = F_47 ( V_148 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 , & V_149 ,
V_6 -> V_89 [ V_47 -> V_121 ] )
== NULL ? - V_108 : 0 ;
break;
case V_94 :
case V_98 :
V_7 = F_47 ( V_150 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
& V_151 ) == NULL ? - V_108 : 0 ;
break;
case V_97 :
V_7 = F_47 ( V_152 , V_47 -> V_117 [ 0 ] , 0x60 ,
& F_46 ( V_47 ) -> V_146 ,
& V_153 ) == NULL ? - V_108 : 0 ;
break;
case V_99 :
V_7 = F_47 ( V_154 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
& V_155 ) == NULL ? - V_108 : 0 ;
break;
case V_101 :
V_7 = F_47 ( V_156 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
& V_157 ) == NULL ? - V_108 : 0 ;
break;
case V_102 :
case V_103 :
V_7 = F_47 ( V_156 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
& V_158 ) == NULL ? - V_108 : 0 ;
break;
case V_92 :
V_7 = F_47 ( V_159 , V_47 -> V_117 [ 0 ] , 0x60 ,
& F_46 ( V_47 ) -> V_146 ,
V_160 ) == NULL ? - V_108 : 0 ;
break;
case V_105 :
V_7 = F_47 ( V_161 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
& V_162 ) == NULL ? - V_108 : 0 ;
break;
case V_104 :
V_7 = F_47 ( V_163 , V_47 -> V_117 [ 0 ] ,
& F_46 ( V_47 ) -> V_146 ,
0x60 , & V_164 ) == NULL ? - V_108 : 0 ;
break;
case V_95 :
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_36 ,
V_33 ,
V_6 -> V_42 [ V_47 -> V_121 ] . V_109 ) ;
V_7 = - V_108 ;
}
if ( V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_132 ) {
V_6 -> V_134 [ V_47 -> V_121 ] =
V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_132 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_132 = F_40 ;
}
if ( V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_133 ) {
V_6 -> V_135 [ V_47 -> V_121 ] =
V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_133 ;
V_47 -> V_117 [ 0 ] -> V_147 . V_165 . V_133 = F_41 ;
}
return V_7 ;
}
static int F_49 ( struct V_138 * V_47 , int V_166 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
int V_7 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_37 , V_55 , V_166 ) ;
if ( V_166 )
V_7 = F_16 ( V_2 , 0xd503 , 0 ) ;
else
V_7 = F_17 ( V_2 , 0xd503 , 0 ) ;
return V_7 ;
}
static int F_50 ( struct V_138 * V_47 , int V_167 , T_2 V_168 ,
int V_166 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
int V_7 ;
T_1 V_169 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_38 ,
V_55 , V_167 , V_168 , V_166 ) ;
V_7 = F_11 ( V_2 , 0xd505 , ( V_168 & 0xff ) ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xd506 , ( V_168 >> 8 ) ) ;
if ( V_7 )
goto error;
V_169 = ( ( V_167 & 0x1f ) | ( 1 << 5 ) ) ;
V_7 = F_11 ( V_2 , 0xd504 , V_169 ) ;
error:
return V_7 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_2 V_170 ;
T_1 V_171 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_39 , V_55 , V_2 -> V_31 -> V_80 ) ;
if ( V_2 -> V_31 -> V_80 == V_81 ) {
V_170 = V_125 / 4 ;
V_171 = V_172 / 4 ;
} else {
V_170 = V_173 / 4 ;
V_171 = V_174 / 4 ;
}
V_7 = F_16 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_16 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_17 ( V_2 , 0xdd13 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_17 ( V_2 , 0xdd13 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_11 ( V_2 , 0xdd88 , V_170 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd89 , V_170 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd8a , V_170 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd8b , V_170 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd0c , V_171 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd0d , V_171 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_17 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
}
if ( V_6 -> V_79 ) {
V_7 = F_16 ( V_2 , 0xd50b , 0 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xd520 , 4 ) ;
if ( V_7 )
goto error;
} else {
V_7 = F_17 ( V_2 , 0xd50b , 0 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xd520 , 4 ) ;
if ( V_7 )
goto error;
}
error:
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_40 ,
V_33 , V_7 ) ;
return V_7 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_7 , V_55 ) ;
F_53 ( & V_6 -> V_126 ) ;
V_7 = F_11 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_51 ( V_2 ) ;
if ( V_7 )
goto error;
error:
return V_7 ;
}
static char * F_54 ( unsigned int V_121 ,
const struct V_175 * V_176 )
{
for (; V_176 -> V_177 ; V_176 ++ )
if ( V_176 -> V_121 == V_121 )
return V_176 -> V_177 ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_12 [ 17 ] ;
V_7 = F_10 ( V_2 , 0x98d9 , V_12 , sizeof( V_12 ) ) ;
if ( V_7 )
goto error;
if ( V_12 [ 1 ] || V_12 [ 2 ] || V_12 [ 3 ] ) {
F_20 ( & V_2 -> V_31 -> V_32 , L_41 , V_55 ) ;
return V_7 ;
}
if ( ( V_6 -> V_178 != V_12 [ 6 ] || V_12 [ 0 ] ) &&
! memcmp ( & V_12 [ 12 ] , V_6 -> V_179 , 4 ) ) {
F_20 ( & V_2 -> V_31 -> V_32 , L_42 , V_55 ) ;
V_178 ( V_2 -> V_180 ) ;
V_6 -> V_178 = V_12 [ 6 ] ;
return V_7 ;
}
if ( V_12 [ 16 ] != 0xff && V_12 [ 0 ] != 0x01 ) {
enum V_181 V_182 ;
F_20 ( & V_2 -> V_31 -> V_32 , L_43 ,
V_55 , 4 , V_12 + 12 ) ;
V_7 = F_11 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
memcpy ( V_6 -> V_179 , & V_12 [ 12 ] , 4 ) ;
if ( V_12 [ 14 ] == ( T_1 ) ~ V_12 [ 15 ] ) {
if ( V_12 [ 12 ] == ( T_1 ) ~ V_12 [ 13 ] ) {
V_6 -> V_183 = F_56 ( V_12 [ 12 ] ,
V_12 [ 14 ] ) ;
V_182 = V_184 ;
} else {
V_6 -> V_183 = F_57 ( V_12 [ 12 ] << 8 |
V_12 [ 13 ] ,
V_12 [ 14 ] ) ;
V_182 = V_185 ;
}
} else {
V_6 -> V_183 = F_58 ( V_12 [ 12 ] << 24 |
V_12 [ 13 ] << 16 |
V_12 [ 14 ] << 8 |
V_12 [ 15 ] ) ;
V_182 = V_186 ;
}
F_59 ( V_2 -> V_180 , V_182 , V_6 -> V_183 , 0 ) ;
} else {
F_20 ( & V_2 -> V_31 -> V_32 , L_44 , V_55 ) ;
V_6 -> V_179 [ 2 ] = V_6 -> V_179 [ 3 ] ;
}
V_6 -> V_178 = V_12 [ 6 ] ;
V_6 -> V_187 = false ;
error:
if ( V_7 ) {
F_60 ( & V_2 -> V_31 -> V_32 , L_45 ,
V_33 , V_7 ) ;
if ( ! V_6 -> V_187 )
V_7 = 0 ;
V_6 -> V_187 = true ;
}
return V_7 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_2 V_190 = F_29 ( V_2 -> V_31 -> V_110 . V_111 ) ;
if ( V_6 -> V_77 == V_191 )
return 0 ;
if ( ! V_189 -> V_192 )
V_189 -> V_192 = F_54 ( V_193 ,
V_194 ) ;
if ( ! V_189 -> V_192 )
V_189 -> V_192 = F_54 ( V_6 -> V_72 ,
V_195 ) ;
if ( ! V_189 -> V_192 && V_190 == V_196 ) {
char V_197 [ 10 ] ;
memset ( V_197 , 0 , sizeof( V_197 ) ) ;
F_62 ( V_2 -> V_31 , V_2 -> V_31 -> V_110 . V_198 ,
V_197 , sizeof( V_197 ) ) ;
if ( ! strcmp ( L_46 , V_197 ) ) {
V_189 -> V_192 = F_54 (
V_199 ,
V_194 ) ;
}
}
if ( ! V_189 -> V_192 )
V_189 -> V_192 = V_200 ;
V_189 -> V_201 = V_202 | V_203 | V_204 ;
V_189 -> V_205 = F_55 ;
V_189 -> V_206 = 500 ;
return 0 ;
}
static int F_63 ( struct V_207 * V_208 ,
const struct V_209 * V_121 )
{
struct V_210 * V_31 = F_64 ( V_208 ) ;
char V_197 [ sizeof( L_47 ) ] ;
memset ( V_197 , 0 , sizeof( V_197 ) ) ;
F_62 ( V_31 , V_31 -> V_110 . V_198 ,
V_197 , sizeof( V_197 ) ) ;
if ( ( F_29 ( V_31 -> V_110 . V_111 ) == V_211 ) &&
( F_29 ( V_31 -> V_110 . V_113 ) == 0x0099 ) ) {
if ( ! strcmp ( L_47 , V_197 ) ) {
F_20 ( & V_31 -> V_32 , L_48 , V_55 ) ;
return - V_108 ;
}
}
return F_65 ( V_208 , V_121 ) ;
}
