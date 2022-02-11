static int F_1 ( T_1 V_1 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 < V_4 [ V_2 ] . V_5 . V_6 ) {
if ( V_4 [ V_2 ] . V_5 . V_6 == 0x08000000 ) {
return - V_7 ;
}
return - V_8 ;
}
if ( V_1 == V_4 [ V_2 ] . V_5 . V_6 ) {
return V_2 ;
}
}
return - V_7 ;
}
static inline int * F_2 ( struct V_9 * V_10 , unsigned int V_11 )
{
return ( int * ) ( ( char * ) V_10 + V_4 [ V_11 ] . V_12 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
* F_2 ( V_10 , V_2 ) = V_4 [ V_2 ] . V_5 . V_13 ;
}
}
static int F_4 ( struct V_9 * V_10 , int V_14 )
{
unsigned long V_15 ;
int V_16 ;
F_5 ( V_15 ) ;
F_6 ( V_10 , 0x87 , V_14 ) ;
V_16 = F_7 ( V_10 , 0x88 ) ;
F_8 ( V_15 ) ;
return V_16 ;
}
static void F_9 ( struct V_9 * V_10 , int V_14 , int V_16 )
{
unsigned long V_15 ;
F_5 ( V_15 ) ;
F_6 ( V_10 , 0x87 , V_14 ) ;
F_6 ( V_10 , 0x88 , V_16 ) ;
F_8 ( V_15 ) ;
}
static void F_10 ( struct V_9 * V_10 , int V_14 , int V_16 )
{
unsigned long V_15 ;
F_5 ( V_15 ) ;
F_6 ( V_10 , 0x87 , V_14 ) ;
F_6 ( V_10 , 0x88 , V_16 >> 2 ) ;
F_6 ( V_10 , 0x87 , V_14 + 1 ) ;
F_6 ( V_10 , 0x88 , V_16 & 3 ) ;
F_8 ( V_15 ) ;
}
static void F_11 ( const struct V_9 * V_10 , int * V_17 ,
int * V_18 )
{
const int V_19 = V_10 -> V_20 . V_21 . V_22 + V_23 ;
const int V_24 = V_10 -> V_20 . V_21 . V_25 ;
* V_17 = F_12 ( V_19 - V_24 , V_23 ) ;
* V_18 = F_13 ( V_19 + V_24 , V_26 ) ;
}
static int F_14 ( void * V_27 , struct V_28 * V_29 ) {
int V_2 ;
V_2 = F_1 ( V_29 -> V_6 ) ;
if ( V_2 >= 0 ) {
* V_29 = V_4 [ V_2 ] . V_5 ;
return 0 ;
}
if ( V_2 == - V_8 ) {
static const struct V_28 V_30 =
{ . V_15 = V_31 } ;
V_2 = V_29 -> V_6 ;
* V_29 = V_30 ;
V_29 -> V_6 = V_2 ;
sprintf ( V_29 -> V_32 , L_1 , V_2 ) ;
return 0 ;
}
return - V_7 ;
}
static int F_15 ( void * V_27 , struct V_33 * V_29 ) {
int V_2 ;
struct V_9 * V_10 = V_27 ;
V_2 = F_1 ( V_29 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
if ( V_29 -> V_34 == * F_2 ( V_10 , V_2 ) ) return 0 ;
if ( V_29 -> V_34 > V_4 [ V_2 ] . V_5 . V_35 ) return - V_7 ;
if ( V_29 -> V_34 < V_4 [ V_2 ] . V_5 . V_36 ) return - V_7 ;
* F_2 ( V_10 , V_2 ) = V_29 -> V_34 ;
switch ( V_29 -> V_6 ) {
case V_37 :
case V_38 :
{
int V_39 , V_40 ;
F_11 ( V_10 , & V_39 , & V_40 ) ;
F_10 ( V_10 , 0x0e , V_39 ) ;
F_10 ( V_10 , 0x1e , V_40 ) ;
}
break;
case V_41 :
F_9 ( V_10 , 0x20 , V_29 -> V_34 ) ;
F_9 ( V_10 , 0x22 , V_29 -> V_34 ) ;
break;
case V_42 :
F_9 ( V_10 , 0x25 , V_29 -> V_34 ) ;
break;
case V_43 :
{
unsigned char V_16 = F_4 ( V_10 , 0x05 ) ;
if ( V_29 -> V_34 ) V_16 |= 0x02 ;
else V_16 &= ~ 0x02 ;
F_9 ( V_10 , 0x05 , V_16 ) ;
}
break;
}
return 0 ;
}
static int F_16 ( void * V_27 , struct V_33 * V_29 ) {
int V_2 ;
struct V_9 * V_10 = V_27 ;
V_2 = F_1 ( V_29 -> V_6 ) ;
if ( V_2 < 0 ) return - V_7 ;
V_29 -> V_34 = * F_2 ( V_10 , V_2 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 , struct V_44 * V_45 ,
struct V_46 * V_47 , const struct V_48 * V_49 )
{
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
T_2 V_53 ;
T_2 V_54 ;
T_2 V_55 ;
unsigned int V_56 ;
unsigned long long V_57 ;
int V_58 ;
int V_59 ;
V_45 -> V_60 [ 0x80 ] = 0x03 ;
V_55 = ( ( V_47 -> V_61 << 1 ) + 3 ) & ~ 3 ;
if ( V_55 >= 2048 ) {
V_55 = 2044 ;
}
V_57 = 1000000000ULL * V_55 ;
F_18 ( V_57 , V_49 -> V_62 ) ;
F_19 ( V_63 L_2 , ( unsigned int ) V_57 ) ;
V_58 = F_20 ( V_10 , V_57 , V_64 ) ;
V_47 -> V_58 = V_58 ;
V_47 -> V_56 = F_21 ( V_10 , V_58 ) ;
F_19 ( V_63 L_3 , V_58 ) ;
V_56 = 1000000000U / V_47 -> V_56 ;
F_19 ( V_63 L_4 , V_56 ) ;
V_57 = V_49 -> V_50 ;
F_18 ( V_57 , V_47 -> V_56 ) ;
V_50 = V_57 ;
F_19 ( V_63 L_5 , V_50 ) ;
V_45 -> V_60 [ 0 ] = V_57 >> 24 ;
V_45 -> V_60 [ 1 ] = V_57 >> 16 ;
V_45 -> V_60 [ 2 ] = V_57 >> 8 ;
V_45 -> V_60 [ 3 ] = V_57 >> 0 ;
V_53 = ( ( ( V_49 -> V_65 + V_56 ) / V_56 ) ) & ~ 1 ;
V_54 = ( ( ( V_49 -> V_66 + V_56 ) / V_56 ) ) & ~ 1 ;
V_52 = ( ( ( V_49 -> V_67 + V_56 ) / V_56 ) ) & ~ 1 ;
V_51 = V_55 + V_54 + V_52 + V_53 ;
V_59 = V_51 & 0x0F ;
F_19 ( V_63 L_6 , V_55 , V_54 , V_52 , V_53 , V_51 ) ;
if ( V_59 ) {
V_54 -= V_59 ;
V_51 -= V_59 ;
if ( V_59 <= 2 ) {
} else if ( V_59 < 10 ) {
V_54 += 4 ;
V_51 += 4 ;
} else {
V_54 += 16 ;
V_51 += 16 ;
}
}
V_45 -> V_60 [ 0x08 ] = V_52 ;
V_45 -> V_60 [ 0x09 ] = ( V_49 -> V_68 + V_56 - 1 ) / V_56 ;
V_45 -> V_60 [ 0x0A ] = V_53 ;
V_45 -> V_60 [ 0x2C ] = V_54 ;
V_45 -> V_60 [ 0x31 ] = V_55 / 8 ;
V_45 -> V_60 [ 0x32 ] = V_55 & 7 ;
F_19 ( V_63 L_7 , V_55 , V_54 , V_52 , V_53 , V_51 ) ;
V_45 -> V_60 [ 0x84 ] = 1 ;
V_45 -> V_60 [ 0x85 ] = 0 ;
V_55 = V_55 >> 1 ;
V_51 = V_51 >> 1 ;
F_19 ( V_63 L_8 , V_51 , V_55 ) ;
V_47 -> V_69 = 1 ;
V_47 -> V_61 = V_55 & ~ 7 ;
V_47 -> V_70 = V_47 -> V_61 + 8 ;
V_47 -> V_71 = ( V_51 & ~ 7 ) - 8 ;
V_47 -> V_72 = V_51 ;
{
int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
V_74 = V_47 -> V_77 ;
V_75 = V_47 -> V_78 ;
V_76 = V_47 -> V_79 ;
if ( V_74 < V_49 -> V_80 ) {
unsigned int V_81 = V_49 -> V_80 - V_74 ;
V_75 += V_81 >> 1 ;
} else if ( V_74 > V_49 -> V_80 ) {
V_76 = V_49 -> V_80 - 4 ;
V_75 = V_49 -> V_80 ;
}
V_73 = ( V_49 -> V_80 - V_75 ) >> 1 ;
V_45 -> V_60 [ 0x17 ] = V_49 -> V_80 / 4 ;
V_45 -> V_60 [ 0x18 ] = V_49 -> V_80 & 3 ;
V_45 -> V_60 [ 0x33 ] = V_73 - 1 ;
V_45 -> V_60 [ 0x82 ] = V_73 ;
V_45 -> V_60 [ 0x83 ] = V_73 >> 8 ;
V_47 -> V_79 = V_76 ;
V_47 -> V_82 = V_49 -> V_80 - 2 ;
V_47 -> V_78 = V_49 -> V_80 ;
V_47 -> V_77 = V_49 -> V_80 ;
}
}
static void F_22 ( int V_83 , struct V_44 * V_84 , const struct V_48 * * V_49 ) {
static const struct V_48 V_85 = {
. V_62 = 52148148 ,
. V_66 = 1407407 ,
. V_67 = 4666667 ,
. V_65 = 5777778 ,
. V_50 = 19042247534182ULL ,
. V_68 = 2518518 ,
. V_80 = 625 ,
} ;
static const struct V_48 V_86 = {
. V_62 = 52888889 ,
. V_66 = 1333333 ,
. V_67 = 4666667 ,
. V_65 = 4666667 ,
. V_50 = 15374030659475ULL ,
. V_68 = 2418418 ,
. V_80 = 525 ,
} ;
static const struct V_44 V_87 = { {
0x2A , 0x09 , 0x8A , 0xCB ,
0x00 ,
0x00 ,
0xF9 ,
0x00 ,
0x7E ,
0x44 ,
0x9C ,
0x2E ,
0x21 ,
0x00 ,
0x3C , 0x03 ,
0x3C , 0x03 ,
0x1A ,
0x2A ,
0x1C , 0x3D , 0x14 ,
0x9C , 0x01 ,
0x00 ,
0xFE ,
0x7E ,
0x60 ,
0x05 ,
0xAD , 0x03 ,
0xA5 ,
0x07 ,
0xA5 ,
0x00 ,
0x00 ,
0x00 ,
0x08 ,
0x04 ,
0x00 ,
0x1A ,
0x55 , 0x01 ,
0x26 ,
0x07 , 0x7E ,
0x02 , 0x54 ,
0xB0 , 0x00 ,
0x14 ,
0x49 ,
0x00 ,
0x00 ,
0xA3 ,
0xC8 ,
0x22 ,
0x02 ,
0x22 ,
0x3F , 0x03 ,
0x00 ,
0x00 ,
} } ;
static struct V_44 V_88 = { {
0x21 , 0xF0 , 0x7C , 0x1F ,
0x00 ,
0x00 ,
0xF9 ,
0x00 ,
0x7E ,
0x43 ,
0x7E ,
0x3D ,
0x00 ,
0x00 ,
0x41 , 0x00 ,
0x3C , 0x00 ,
0x17 ,
0x21 ,
0x1B , 0x1B , 0x24 ,
0x83 , 0x01 ,
0x00 ,
0x0F ,
0x0F ,
0x60 ,
0x05 ,
0xC0 , 0x02 ,
0x9C ,
0x04 ,
0x9C ,
0x01 ,
0x02 ,
0x00 ,
0x0A ,
0x05 ,
0x00 ,
0x10 ,
0xFF , 0x03 ,
0x24 ,
0x0F , 0x78 ,
0x00 , 0x00 ,
0xB2 , 0x04 ,
0x14 ,
0x02 ,
0x00 ,
0x00 ,
0xA3 ,
0xC8 ,
0x15 ,
0x05 ,
0x3B ,
0x3C , 0x00 ,
0x00 ,
0x00 ,
} } ;
if ( V_83 == V_89 ) {
* V_84 = V_87 ;
* V_49 = & V_85 ;
} else {
* V_84 = V_88 ;
* V_49 = & V_86 ;
}
return;
}
static void F_23 ( struct V_9 * V_10 ,
const struct V_44 * V_90 )
{
int V_2 ;
F_24 ( 0x80 ) ;
F_24 ( 0x82 ) ; F_24 ( 0x83 ) ;
F_24 ( 0x84 ) ; F_24 ( 0x85 ) ;
F_9 ( V_10 , 0x3E , 0x01 ) ;
for ( V_2 = 0 ; V_2 < 0x3E ; V_2 ++ ) {
F_24 ( V_2 ) ;
}
F_9 ( V_10 , 0x3E , 0x00 ) ;
}
static int F_25 ( void * V_27 , struct V_46 * V_47 ) {
struct V_9 * V_10 = V_27 ;
F_19 ( V_63 L_9 , V_10 -> V_91 [ 1 ] . V_92 ) ;
if ( V_47 -> V_93 == V_94 &&
V_10 -> V_91 [ 1 ] . V_92 != V_95 ) {
const struct V_48 * V_49 ;
F_22 ( V_10 -> V_91 [ 1 ] . V_92 , & V_10 -> V_96 . V_97 , & V_49 ) ;
{
int V_39 , V_40 ;
F_11 ( V_10 , & V_39 , & V_40 ) ;
V_10 -> V_96 . V_97 . V_60 [ 0x0E ] = V_39 >> 2 ;
V_10 -> V_96 . V_97 . V_60 [ 0x0F ] = V_39 & 3 ;
V_10 -> V_96 . V_97 . V_60 [ 0x1E ] = V_40 >> 2 ;
V_10 -> V_96 . V_97 . V_60 [ 0x1F ] = V_40 & 3 ;
V_10 -> V_96 . V_97 . V_60 [ 0x20 ] =
V_10 -> V_96 . V_97 . V_60 [ 0x22 ] = V_10 -> V_20 . V_21 . V_98 ;
V_10 -> V_96 . V_97 . V_60 [ 0x25 ] = V_10 -> V_20 . V_21 . V_99 ;
if ( V_10 -> V_20 . V_21 . V_100 ) {
V_10 -> V_96 . V_97 . V_60 [ 0x05 ] |= 0x02 ;
}
}
F_17 ( V_10 , & V_10 -> V_96 . V_97 , V_47 , V_49 ) ;
} else if ( V_47 -> V_58 < 0 ) {
V_47 -> V_58 = F_20 ( V_10 , V_47 -> V_56 , ( V_47 -> V_93 == V_101 ) ? V_102 : V_64 ) ;
V_47 -> V_56 = F_21 ( V_10 , V_47 -> V_58 ) ;
}
F_19 ( V_63 L_10 , V_47 -> V_56 ) ;
return 0 ;
}
static int F_26 ( void * V_27 ) {
struct V_9 * V_10 = V_27 ;
if ( V_10 -> V_91 [ 1 ] . V_92 != V_95 ) {
F_23 ( V_10 , & V_10 -> V_96 . V_97 ) ;
}
return 0 ;
}
static int F_27 ( void * V_27 , T_2 V_103 ) {
switch ( V_103 ) {
case V_89 :
case V_104 :
case V_95 :
return 0 ;
}
return - V_7 ;
}
static int F_28 ( void * V_27 , struct V_46 * V_47 ) {
struct V_9 * V_10 = V_27 ;
if ( V_47 -> V_58 < 0 ) {
V_47 -> V_58 = F_20 ( V_10 , V_47 -> V_56 , ( V_47 -> V_93 == V_101 ) ? V_102 : V_64 ) ;
V_47 -> V_56 = F_21 ( V_10 , V_47 -> V_58 ) ;
}
return 0 ;
}
void F_29 ( struct V_9 * V_10 )
{
if ( V_10 -> V_105 . V_106 ) {
F_30 ( & V_10 -> V_20 . V_107 ) ;
F_3 ( V_10 ) ;
V_10 -> V_91 [ 1 ] . V_108 = V_10 -> V_91 [ 1 ] . V_109 ;
V_10 -> V_91 [ 1 ] . V_84 = V_10 ;
V_10 -> V_91 [ 1 ] . V_110 = & V_111 ;
V_10 -> V_91 [ 1 ] . V_92 = V_95 ;
V_10 -> V_91 [ 2 ] . V_108 = V_10 -> V_91 [ 2 ] . V_109 ;
V_10 -> V_91 [ 2 ] . V_84 = V_10 ;
V_10 -> V_91 [ 2 ] . V_110 = & V_112 ;
V_10 -> V_91 [ 2 ] . V_92 = V_95 ;
F_31 ( & V_10 -> V_20 . V_107 ) ;
}
}
void F_32 ( struct V_9 * V_10 )
{
if ( V_10 -> V_105 . V_106 ) {
F_30 ( & V_10 -> V_20 . V_107 ) ;
V_10 -> V_91 [ 1 ] . V_108 = V_113 ;
V_10 -> V_91 [ 1 ] . V_110 = NULL ;
V_10 -> V_91 [ 1 ] . V_84 = NULL ;
V_10 -> V_91 [ 1 ] . V_92 = V_95 ;
V_10 -> V_91 [ 2 ] . V_108 = V_113 ;
V_10 -> V_91 [ 2 ] . V_110 = NULL ;
V_10 -> V_91 [ 2 ] . V_84 = NULL ;
V_10 -> V_91 [ 2 ] . V_92 = V_95 ;
F_31 ( & V_10 -> V_20 . V_107 ) ;
}
}
