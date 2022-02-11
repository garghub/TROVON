static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( & V_4 -> V_2 , L_1 ) ;
V_5 = F_3 ( V_2 -> V_6 , 0x00 , 0x01 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x06 , 0x00 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x7a , 0x96 ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_2 -> V_6 , 0x7e , L_2 , 2 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x82 , 0x00 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x24 , 0x05 ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_2 -> V_6 , 0x87 , L_3 , 2 ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_2 -> V_6 , 0x9f , L_4 , 2 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x2d , 0x1f ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_2 -> V_6 , 0x70 , L_5 , 2 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x1a , 0x17 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x1f , 0x1a ) ;
if ( V_5 )
goto V_7;
V_2 -> V_8 = true ;
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( & V_4 -> V_2 , L_1 ) ;
V_2 -> V_8 = false ;
V_5 = F_3 ( V_2 -> V_6 , 0x00 , 0x00 ) ;
if ( V_5 )
goto V_7;
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
T_1 V_14 ;
T_2 V_15 [ 5 ] , V_16 [ 4 ] , V_17 [ 4 ] ;
if ( ! V_2 -> V_8 ) {
F_2 ( & V_4 -> V_2 , L_7 ) ;
return 0 ;
}
V_5 = F_3 ( V_2 -> V_6 , 0x1a , 0x00 ) ;
if ( V_5 )
goto V_7;
for ( V_9 = 0 ; V_9 < F_7 ( V_18 ) ; V_9 ++ ) {
if ( V_2 -> V_19 <= V_18 [ V_9 ] . V_20 )
break;
}
if ( V_9 == F_7 ( V_18 ) ) {
V_5 = - V_21 ;
goto V_7;
}
#define F_8 dev->clk
V_13 = V_18 [ V_9 ] . V_13 ;
V_14 = ( T_1 ) V_2 -> V_19 * V_13 ;
V_10 = F_9 ( V_14 , F_8 , & V_11 ) ;
V_12 = F_10 ( ( T_1 ) V_11 * 0x10000 , F_8 ) ;
F_2 ( & V_4 -> V_2 ,
L_8 ,
V_2 -> V_19 , V_2 -> V_22 , V_14 , F_8 , V_10 , V_11 ,
V_12 , V_13 ) ;
V_15 [ 0 ] = V_10 ;
V_15 [ 1 ] = ( V_12 >> 0 ) & 0xff ;
V_15 [ 2 ] = ( V_12 >> 8 ) & 0xff ;
V_15 [ 3 ] = 0x00 ;
V_15 [ 4 ] = V_18 [ V_9 ] . V_23 ;
V_5 = F_4 ( V_2 -> V_6 , 0x09 , V_15 , 5 ) ;
if ( V_5 )
goto V_7;
for ( V_9 = 0 ; V_9 < F_7 ( V_24 ) ; V_9 ++ ) {
if ( V_2 -> V_19 <= V_24 [ V_9 ] . V_20 )
break;
}
if ( V_9 == F_7 ( V_24 ) ) {
V_5 = - V_21 ;
goto V_7;
}
V_5 = F_3 ( V_2 -> V_6 , 0x10 , V_24 [ V_9 ] . V_25 ) ;
if ( V_5 )
goto V_7;
for ( V_9 = 0 ; V_9 < F_7 ( V_26 ) ; V_9 ++ ) {
if ( V_2 -> V_22 <= V_26 [ V_9 ] . V_20 )
break;
}
if ( V_9 == F_7 ( V_26 ) ) {
V_5 = - V_21 ;
goto V_7;
}
V_15 [ 0 ] = V_26 [ V_9 ] . V_27 ;
V_15 [ 1 ] = V_26 [ V_9 ] . V_28 ;
V_5 = F_4 ( V_2 -> V_6 , 0x11 , V_15 , 2 ) ;
if ( V_5 )
goto V_7;
for ( V_9 = 0 ; V_9 < F_7 ( V_29 ) ; V_9 ++ ) {
if ( V_2 -> V_19 <= V_29 [ V_9 ] . V_20 )
break;
}
if ( V_9 == F_7 ( V_29 ) ) {
V_5 = - V_21 ;
goto V_7;
}
V_5 = F_3 ( V_2 -> V_6 , 0x07 , V_29 [ V_9 ] . V_30 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x78 , V_29 [ V_9 ] . V_31 ) ;
if ( V_5 )
goto V_7;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
if ( V_9 == 0 )
V_5 = F_4 ( V_2 -> V_6 , 0x15 , L_9 , 3 ) ;
else if ( V_9 == 1 )
V_5 = F_4 ( V_2 -> V_6 , 0x15 , L_10 , 2 ) ;
else if ( V_9 == 2 )
V_5 = F_4 ( V_2 -> V_6 , 0x15 , L_11 , 1 ) ;
else
V_5 = F_4 ( V_2 -> V_6 , 0x16 , L_12 , 1 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x29 , 0x01 ) ;
if ( V_5 )
goto V_7;
V_5 = F_11 ( V_2 -> V_6 , 0x2a , V_15 , 3 ) ;
if ( V_5 )
goto V_7;
V_16 [ V_9 ] = ( ( ( V_15 [ 2 ] >> 0 ) & 0x3 ) << 6 ) | ( V_15 [ 0 ] & 0x3f ) ;
V_17 [ V_9 ] = ( ( ( V_15 [ 2 ] >> 4 ) & 0x3 ) << 6 ) | ( V_15 [ 1 ] & 0x3f ) ;
}
F_12 ( V_17 [ 2 ] , V_17 [ 3 ] ) ;
F_12 ( V_16 [ 2 ] , V_16 [ 3 ] ) ;
V_5 = F_4 ( V_2 -> V_6 , 0x50 , V_17 , 4 ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_2 -> V_6 , 0x60 , V_16 , 4 ) ;
if ( V_5 )
goto V_7;
V_5 = F_3 ( V_2 -> V_6 , 0x1a , 0x17 ) ;
if ( V_5 )
goto V_7;
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static inline struct V_1 * F_13 ( struct V_32 * V_33 )
{
return F_14 ( V_33 , struct V_1 , V_33 ) ;
}
static int F_15 ( struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( & V_4 -> V_2 , L_13 , V_34 ) ;
if ( V_34 )
V_5 = F_1 ( V_2 ) ;
else
V_5 = F_5 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return F_6 ( V_2 ) ;
}
static int F_16 ( struct V_32 * V_33 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_2 , L_14 , V_36 -> V_37 ) ;
F_17 ( V_36 -> V_38 , L_15 , sizeof( V_36 -> V_38 ) ) ;
V_36 -> type = V_39 ;
V_36 -> V_40 = V_41 | V_42 ;
V_36 -> V_43 = V_44 [ 0 ] . V_43 ;
V_36 -> V_45 = V_44 [ 1 ] . V_45 ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 , const struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_2 , L_14 , V_36 -> V_37 ) ;
return 0 ;
}
static int F_19 ( struct V_32 * V_33 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_2 , L_16 , V_47 -> V_48 ) ;
V_47 -> V_49 = V_2 -> V_19 ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 ,
const struct V_46 * V_47 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_2 , L_17 ,
V_47 -> V_48 , V_47 -> type , V_47 -> V_49 ) ;
V_2 -> V_19 = F_21 (unsigned int, f->frequency,
bands[0].rangelow, bands[1].rangehigh) ;
return F_6 ( V_2 ) ;
}
static int F_22 ( struct V_32 * V_33 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_13 ( V_33 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_2 , L_18 ,
V_51 -> V_48 , V_51 -> type , V_51 -> V_37 ) ;
if ( V_51 -> V_37 >= F_7 ( V_44 ) )
return - V_21 ;
V_51 -> V_40 = V_44 [ V_51 -> V_37 ] . V_40 ;
V_51 -> V_43 = V_44 [ V_51 -> V_37 ] . V_43 ;
V_51 -> V_45 = V_44 [ V_51 -> V_37 ] . V_45 ;
return 0 ;
}
static int F_23 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_2 V_55 ;
F_2 ( & V_4 -> V_2 , L_19 ,
V_2 -> V_56 -> V_57 . V_25 , V_2 -> V_56 -> V_25 ,
V_2 -> V_58 -> V_57 . V_25 , V_2 -> V_58 -> V_25 ) ;
if ( V_2 -> V_56 -> V_25 && V_2 -> V_59 -> V_57 . V_25 )
V_55 = 0x17 ;
else if ( V_2 -> V_56 -> V_25 )
V_55 = 0x19 ;
else if ( V_2 -> V_59 -> V_57 . V_25 )
V_55 = 0x16 ;
else
V_55 = 0x10 ;
V_5 = F_3 ( V_2 -> V_6 , 0x1a , V_55 ) ;
if ( V_5 )
goto V_7;
if ( V_2 -> V_56 -> V_25 == false ) {
V_5 = F_3 ( V_2 -> V_6 , 0x14 , V_2 -> V_58 -> V_25 ) ;
if ( V_5 )
goto V_7;
}
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_24 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_2 V_55 ;
F_2 ( & V_4 -> V_2 , L_20 ,
V_2 -> V_60 -> V_57 . V_25 , V_2 -> V_60 -> V_25 ,
V_2 -> V_61 -> V_57 . V_25 , V_2 -> V_61 -> V_25 ) ;
if ( V_2 -> V_60 -> V_25 )
V_55 = 0x15 ;
else
V_55 = 0x14 ;
V_5 = F_3 ( V_2 -> V_6 , 0x20 , V_55 ) ;
if ( V_5 )
goto V_7;
if ( V_2 -> V_60 -> V_25 == false ) {
V_5 = F_3 ( V_2 -> V_6 , 0x15 , V_2 -> V_61 -> V_25 ) ;
if ( V_5 )
goto V_7;
}
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_25 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_2 V_15 [ 2 ] ;
T_2 V_55 ;
F_2 ( & V_4 -> V_2 , L_21 ,
V_2 -> V_59 -> V_57 . V_25 , V_2 -> V_59 -> V_25 ,
V_2 -> V_62 -> V_57 . V_25 , V_2 -> V_62 -> V_25 ) ;
if ( V_2 -> V_59 -> V_25 && V_2 -> V_56 -> V_57 . V_25 )
V_55 = 0x17 ;
else if ( V_2 -> V_56 -> V_57 . V_25 )
V_55 = 0x19 ;
else if ( V_2 -> V_59 -> V_25 )
V_55 = 0x16 ;
else
V_55 = 0x10 ;
V_5 = F_3 ( V_2 -> V_6 , 0x1a , V_55 ) ;
if ( V_5 )
goto V_7;
if ( V_2 -> V_59 -> V_25 == false ) {
V_15 [ 0 ] = V_63 [ V_2 -> V_62 -> V_25 ] . V_64 ;
V_15 [ 1 ] = V_63 [ V_2 -> V_62 -> V_25 ] . V_65 ;
V_5 = F_4 ( V_2 -> V_6 , 0x16 , V_15 , 2 ) ;
if ( V_5 )
goto V_7;
}
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_26 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
unsigned int V_66 ;
V_5 = F_27 ( V_2 -> V_6 , 0x07 , & V_66 ) ;
if ( V_5 )
goto V_7;
V_2 -> V_67 -> V_25 = ( V_66 & 0x01 ) ;
return 0 ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_28 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_14 ( V_69 -> V_70 , struct V_1 , V_71 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( ! V_2 -> V_8 )
return 0 ;
switch ( V_69 -> V_72 ) {
case V_73 :
V_5 = F_26 ( V_2 -> V_53 ) ;
break;
default:
F_2 ( & V_4 -> V_2 , L_22 ,
V_69 -> V_72 , V_69 -> V_38 ) ;
V_5 = - V_21 ;
}
return V_5 ;
}
static int F_29 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_14 ( V_69 -> V_70 , struct V_1 , V_71 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( ! V_2 -> V_8 )
return 0 ;
switch ( V_69 -> V_72 ) {
case V_74 :
case V_75 :
V_2 -> V_22 = V_2 -> V_76 -> V_25 ;
V_5 = F_6 ( V_2 ) ;
break;
case V_77 :
case V_78 :
V_5 = F_23 ( V_2 -> V_53 ) ;
break;
case V_79 :
case V_80 :
V_5 = F_24 ( V_2 -> V_53 ) ;
break;
case V_81 :
case V_82 :
V_5 = F_25 ( V_2 -> V_53 ) ;
break;
default:
F_2 ( & V_4 -> V_2 , L_22 ,
V_69 -> V_72 , V_69 -> V_38 ) ;
V_5 = - V_21 ;
}
return V_5 ;
}
static int F_30 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_83 * V_84 = & V_53 -> V_85 ;
V_2 -> V_19 = V_84 -> V_49 ;
V_2 -> V_22 = V_84 -> V_86 ;
return F_6 ( V_2 ) ;
}
static int F_31 ( struct V_52 * V_53 )
{
return F_1 ( V_53 -> V_54 ) ;
}
static int F_32 ( struct V_52 * V_53 )
{
return F_5 ( V_53 -> V_54 ) ;
}
static int F_33 ( struct V_52 * V_53 , T_3 * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 ,
const struct V_87 * V_72 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 = V_4 -> V_2 . V_90 ;
struct V_52 * V_53 = V_89 -> V_53 ;
int V_5 ;
unsigned int V_66 ;
static const struct V_91 V_91 = {
. V_92 = 8 ,
. V_93 = 8 ,
} ;
V_2 = F_35 ( sizeof( * V_2 ) , V_94 ) ;
if ( ! V_2 ) {
V_5 = - V_95 ;
goto V_7;
}
V_2 -> V_96 = V_89 -> clock ;
V_2 -> V_4 = V_4 ;
V_2 -> V_53 = V_89 -> V_53 ;
V_2 -> V_6 = F_36 ( V_4 , & V_91 ) ;
if ( F_37 ( V_2 -> V_6 ) ) {
V_5 = F_38 ( V_2 -> V_6 ) ;
goto V_97;
}
V_5 = F_27 ( V_2 -> V_6 , 0x02 , & V_66 ) ;
if ( V_5 )
goto V_97;
F_2 ( & V_4 -> V_2 , L_23 , V_66 ) ;
if ( V_66 != 0x40 ) {
V_5 = - V_98 ;
goto V_97;
}
V_5 = F_3 ( V_2 -> V_6 , 0x00 , 0x00 ) ;
if ( V_5 )
goto V_97;
#if F_39 ( V_99 )
F_40 ( & V_2 -> V_71 , 9 ) ;
V_2 -> V_100 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_74 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_76 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_75 , 4300000 , 11000000 , 100000 , 4300000 ) ;
F_42 ( 2 , & V_2 -> V_100 , 0 , false ) ;
V_2 -> V_56 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_77 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_58 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_78 , 0 , 15 , 1 , 10 ) ;
F_42 ( 2 , & V_2 -> V_56 , 0 , false ) ;
V_2 -> V_60 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_79 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_61 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_80 , 0 , 1 , 1 , 1 ) ;
F_42 ( 2 , & V_2 -> V_60 , 0 , false ) ;
V_2 -> V_59 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_81 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_62 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_82 , 0 , 54 , 1 , 0 ) ;
F_42 ( 2 , & V_2 -> V_59 , 0 , false ) ;
V_2 -> V_67 = F_41 ( & V_2 -> V_71 , & V_101 ,
V_73 , 0 , 1 , 1 , 0 ) ;
if ( V_2 -> V_71 . error ) {
V_5 = V_2 -> V_71 . error ;
F_43 ( & V_4 -> V_2 , L_24 ) ;
F_44 ( & V_2 -> V_71 ) ;
goto V_97;
}
V_2 -> V_33 . V_102 = & V_2 -> V_71 ;
V_2 -> V_19 = V_44 [ 0 ] . V_43 ;
V_2 -> V_22 = V_2 -> V_76 -> V_25 ;
F_45 ( & V_2 -> V_33 , V_4 , & V_103 ) ;
#endif
V_53 -> V_54 = V_2 ;
memcpy ( & V_53 -> V_104 . V_105 , & V_106 ,
sizeof( V_53 -> V_104 . V_105 ) ) ;
F_46 ( & V_2 -> V_33 , V_4 ) ;
F_47 ( V_4 , & V_2 -> V_33 ) ;
F_48 ( & V_4 -> V_2 , L_25 ) ;
return 0 ;
V_97:
F_49 ( V_2 ) ;
V_7:
F_2 ( & V_4 -> V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = F_51 ( V_4 ) ;
struct V_1 * V_2 = F_14 ( V_33 , struct V_1 , V_33 ) ;
F_2 ( & V_4 -> V_2 , L_1 ) ;
#if F_39 ( V_99 )
F_44 ( & V_2 -> V_71 ) ;
#endif
F_49 ( V_2 ) ;
return 0 ;
}
