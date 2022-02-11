static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_4 ) {
F_2 ( V_2 , V_5 , 0 , 0xf ) ;
F_2 ( V_2 , V_6 , 0 , 0x0b000000 ) ;
V_3 = F_3 ( V_2 , V_7 , 0 ) & ~ 0x1000 ;
F_2 ( V_2 , V_7 , 0 , V_3 ) ;
V_3 = F_4 ( V_2 -> V_8 + V_9 ) & ~ 0x101 ;
F_5 ( V_3 , V_2 -> V_8 + V_9 ) ;
} else {
F_2 ( V_2 , V_5 , 0 , 0xf ) ;
F_2 ( V_2 , V_6 , 0 , 0x000f0000 ) ;
V_3 = F_3 ( V_2 , V_7 , 0 ) | 0x1000 ;
F_2 ( V_2 , V_7 , 0 , V_3 ) ;
V_3 = F_4 ( V_2 -> V_8 + V_9 ) | 0x101 ;
F_5 ( V_3 , V_2 -> V_8 + V_9 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_10 ;
unsigned int V_11 , V_12 ;
V_11 = ( V_3 << 28 ) | ( V_3 << 24 ) | ( V_3 << 20 ) | ( V_3 << 16 ) ;
V_12 = F_3 ( V_2 , V_13 , 0 ) & 0xffff ;
F_2 ( V_2 , V_13 , 0 , V_11 | V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_14 )
{
unsigned int V_15 , V_16 ;
T_1 V_11 ;
F_8 ( V_2 , V_17 , 0 ) ;
V_15 = V_2 -> V_18 [ V_3 ] [ 0 ] ;
V_16 = V_2 -> V_18 [ V_2 -> V_19 ] [ 0 ] ;
if ( V_14 || V_15 != V_16 )
F_8 ( V_2 , V_20 , V_15 & 0xff ) ;
V_15 = V_2 -> V_18 [ V_3 ] [ 1 ] ;
V_16 = V_2 -> V_18 [ V_2 -> V_19 ] [ 1 ] ;
if ( V_14 || V_15 != V_16 )
F_8 ( V_2 , V_21 , V_15 & 0xff ) ;
V_11 = 1 << V_3 ;
F_8 ( V_2 , V_17 , V_11 ) ;
V_2 -> V_19 = V_3 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_22 ;
if ( V_2 -> V_23 ) {
V_22 = F_4 ( V_2 -> V_8 + V_9 ) & ~ 0x400 ;
V_22 = V_22 | 0x400 ;
F_5 ( V_22 , V_2 -> V_8 + V_9 ) ;
} else {
V_22 = F_4 ( V_2 -> V_8 + V_9 ) & ~ 0x400 ;
F_5 ( V_22 , V_2 -> V_8 + V_9 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_24 )
{
F_2 ( V_2 , V_25 + V_24 , 0 , V_2 -> V_26 [ V_24 ] ) ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_4 ;
return 0 ;
}
static int F_13 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_3 ;
int V_32 = 0 ;
V_3 = ! ! V_30 -> V_31 . integer . V_31 [ 0 ] ;
V_32 = ( V_2 -> V_4 != V_3 ) ;
if ( V_32 ) {
V_2 -> V_4 = V_3 ;
F_1 ( V_2 ) ;
}
return V_32 ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static const char * const V_35 [ 6 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6
} ;
return F_15 ( V_34 , 1 , 6 , V_35 ) ;
}
static int F_16 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_36 . V_37 [ 0 ] = V_2 -> V_10 ;
return 0 ;
}
static int F_17 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_3 ;
int V_32 = 0 ;
V_3 = V_30 -> V_31 . V_36 . V_37 [ 0 ] ;
if ( V_3 >= 6 )
return - V_38 ;
V_32 = ( V_2 -> V_10 != V_3 ) ;
if ( V_32 ) {
V_2 -> V_10 = V_3 ;
F_6 ( V_2 ) ;
}
return V_32 ;
}
static int F_18 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static const char * const V_35 [ 4 ] = {
L_7 , L_8 , L_9 , L_10
} ;
return F_15 ( V_34 , 1 , 4 , V_35 ) ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_36 . V_37 [ 0 ] = V_2 -> V_19 ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_39 ;
int V_32 = 0 ;
V_39 = V_30 -> V_31 . V_36 . V_37 [ 0 ] ;
if ( V_39 >= 4 )
return - V_38 ;
V_32 = ( V_2 -> V_19 != V_39 ) ;
if ( V_32 ) {
F_7 ( V_2 , V_39 , 0 ) ;
}
return V_32 ;
}
static int F_21 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static const char * const V_35 [ 2 ] = { L_11 , L_9 } ;
return F_15 ( V_34 , 1 , 2 , V_35 ) ;
}
static int F_22 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static const char * const V_35 [ 2 ] = { L_9 , L_12 } ;
return F_15 ( V_34 , 1 , 2 , V_35 ) ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_36 . V_37 [ 0 ] = V_2 -> V_23 ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_3 ;
int V_32 = 0 ;
V_3 = V_30 -> V_31 . V_36 . V_37 [ 0 ] ;
if ( V_3 > 1 )
return - V_38 ;
V_32 = ( V_2 -> V_23 != V_3 ) ;
if ( V_32 ) {
V_2 -> V_23 = V_3 ;
F_9 ( V_2 ) ;
}
return V_32 ;
}
static int F_25 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_40 ;
V_34 -> V_41 = 1 ;
return 0 ;
}
static void F_26 ( unsigned char * V_42 , unsigned int V_43 )
{
V_42 [ 0 ] = ( V_43 >> 0 ) & 0xff ;
V_42 [ 1 ] = ( V_43 >> 8 ) & 0xff ;
V_42 [ 2 ] = ( V_43 >> 16 ) & 0xff ;
V_42 [ 3 ] = ( V_43 >> 24 ) & 0xff ;
}
static int F_27 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_28 ( V_28 , & V_30 -> V_44 ) ;
F_26 ( V_30 -> V_31 . V_45 . V_42 ,
V_2 -> V_46 [ V_24 ] ) ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_28 ( V_28 , & V_30 -> V_44 ) ;
F_26 ( V_30 -> V_31 . V_45 . V_42 ,
V_2 -> V_26 [ V_24 ] ) ;
return 0 ;
}
static int F_30 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . V_45 . V_42 [ 0 ] = 0xff ;
V_30 -> V_31 . V_45 . V_42 [ 1 ] = 0xff ;
V_30 -> V_31 . V_45 . V_42 [ 2 ] = 0xff ;
V_30 -> V_31 . V_45 . V_42 [ 3 ] = 0xff ;
return 0 ;
}
static unsigned int F_31 ( unsigned char * V_42 )
{
return ( ( unsigned int ) V_42 [ 0 ] << 0 ) |
( ( unsigned int ) V_42 [ 1 ] << 8 ) |
( ( unsigned int ) V_42 [ 2 ] << 16 ) |
( ( unsigned int ) V_42 [ 3 ] << 24 ) ;
}
static int F_32 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_28 ( V_28 , & V_30 -> V_44 ) ;
unsigned int V_3 ;
V_3 = F_31 ( V_30 -> V_31 . V_45 . V_42 ) ;
if ( V_3 != V_2 -> V_46 [ V_24 ] ) {
V_2 -> V_46 [ V_24 ] = V_3 ;
V_2 -> V_26 [ V_24 ] = V_3 ;
F_10 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_28 ( V_28 , & V_30 -> V_44 ) ;
unsigned int V_3 ;
V_3 = F_31 ( V_30 -> V_31 . V_45 . V_42 ) ;
if ( V_3 != V_2 -> V_26 [ V_24 ] ) {
V_2 -> V_26 [ V_24 ] = V_3 ;
F_10 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_34 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_47 ;
V_34 -> V_41 = 2 ;
V_34 -> V_31 . integer . V_48 = 0 ;
V_34 -> V_31 . integer . V_49 = 255 ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_31 ;
int V_50 , V_51 ;
V_50 = ( V_28 -> V_52 >> 8 ) & 0xff ;
V_51 = V_28 -> V_52 & 0xff ;
V_31 = F_3 ( V_2 , V_51 , V_50 ) ;
V_30 -> V_31 . integer . V_31 [ 0 ] = 0xff - ( ( V_31 >> 24 ) & 0xff ) ;
V_30 -> V_31 . integer . V_31 [ 1 ] = 0xff - ( ( V_31 >> 16 ) & 0xff ) ;
return 0 ;
}
static int F_36 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_53 , V_54 ;
int V_50 , V_51 ;
V_50 = ( V_28 -> V_52 >> 8 ) & 0xff ;
V_51 = V_28 -> V_52 & 0xff ;
V_53 = F_3 ( V_2 , V_51 , V_50 ) ;
V_54 = ( ( 0xff - V_30 -> V_31 . integer . V_31 [ 0 ] ) << 24 ) |
( ( 0xff - V_30 -> V_31 . integer . V_31 [ 1 ] ) << 16 ) ;
V_54 |= ( ( 0xff - V_30 -> V_31 . integer . V_31 [ 0 ] ) << 8 ) |
( ( 0xff - V_30 -> V_31 . integer . V_31 [ 1 ] ) ) ;
if ( V_53 == V_54 )
return 0 ;
F_2 ( V_2 , V_51 , V_50 , V_54 ) ;
return 1 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_47 ;
V_34 -> V_41 = 2 ;
V_34 -> V_31 . integer . V_48 = 0 ;
V_34 -> V_31 . integer . V_49 = 255 ;
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
int V_39 ;
V_39 = V_28 -> V_52 ;
V_30 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_18 [ V_39 ] [ 0 ] ;
V_30 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_18 [ V_39 ] [ 1 ] ;
return 0 ;
}
static int F_39 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_16 ;
unsigned int V_15 ;
int V_39 ;
int V_32 = 0 ;
V_39 = V_28 -> V_52 ;
V_16 = V_2 -> V_18 [ V_39 ] [ 0 ] ;
V_15 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
if ( V_15 > 0xff )
return - V_38 ;
if ( V_16 != V_15 ) {
if ( V_2 -> V_19 == V_39 )
F_8 ( V_2 , V_20 , ( ( V_15 ) & 0xff ) ) ;
V_2 -> V_18 [ V_39 ] [ 0 ] = V_30 -> V_31 . integer . V_31 [ 0 ] ;
V_32 = 1 ;
}
V_16 = V_2 -> V_18 [ V_39 ] [ 1 ] ;
V_15 = V_30 -> V_31 . integer . V_31 [ 1 ] ;
if ( V_15 > 0xff )
return - V_38 ;
if ( V_16 != V_15 ) {
if ( V_2 -> V_19 == V_39 )
F_8 ( V_2 , V_21 , ( ( V_15 ) & 0xff ) ) ;
V_2 -> V_18 [ V_39 ] [ 1 ] = V_30 -> V_31 . integer . V_31 [ 1 ] ;
V_32 = 1 ;
}
return V_32 ;
}
static int F_40 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_51 = V_28 -> V_52 >> V_55 ;
unsigned int V_56 = V_28 -> V_52 & V_57 ;
V_30 -> V_31 . integer . V_31 [ 0 ] = ! ( V_2 -> V_58 [ V_51 ] & V_56 ) ;
return 0 ;
}
static int F_41 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_51 = V_28 -> V_52 >> V_55 ;
unsigned int V_56 = V_28 -> V_52 & V_57 ;
int V_59 ;
V_59 = V_2 -> V_58 [ V_51 ] & V_56 ;
if ( V_30 -> V_31 . integer . V_31 [ 0 ] ) {
if ( ! V_59 )
return 0 ;
V_2 -> V_58 [ V_51 ] &= ~ V_56 ;
} else {
if ( V_59 )
return 0 ;
V_2 -> V_58 [ V_51 ] |= V_56 ;
}
V_59 = F_42 ( V_2 , V_2 -> V_58 [ V_51 ] ) ;
return V_59 ? - V_38 : 1 ;
}
static struct V_60
F_43 ( struct V_61 * V_62 ,
int V_50 )
{
struct V_60 V_63 = { 0 } ;
int V_51 , V_56 ;
int V_64 ;
V_63 . V_65 = V_66 ;
V_63 . V_67 = V_68 ;
V_63 . V_69 = V_70 ;
V_63 . V_71 = F_40 ;
V_63 . V_72 = F_41 ;
switch ( V_50 ) {
case V_73 :
V_63 . V_74 = L_13 ;
V_64 = ( V_62 -> V_75 & 0xf000 ) >> ( 4 * 3 ) ;
break;
case V_76 :
V_63 . V_74 = L_14 ;
V_64 = ( V_62 -> V_75 & 0x0f00 ) >> ( 4 * 2 ) ;
break;
case V_77 :
V_63 . V_74 = L_15 ;
V_64 = ( V_62 -> V_75 & 0x00f0 ) >> ( 4 * 1 ) ;
break;
case V_78 :
V_63 . V_74 = L_16 ;
V_64 = ( V_62 -> V_75 & 0x000f ) >> ( 4 * 0 ) ;
break;
default:
V_63 . V_74 = NULL ;
V_64 = 0 ;
}
V_51 = V_79 [ V_64 ] ;
V_56 = V_80 [ V_64 ] ;
V_63 . V_52 = ( V_51 << V_55 ) | V_56 ;
return V_63 ;
}
static int F_44 ( struct V_81 * V_82 , const char * V_74 )
{
struct V_83 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
strcpy ( V_44 . V_74 , V_74 ) ;
V_44 . V_65 = V_66 ;
return F_45 ( V_82 , & V_44 ) ;
}
static struct V_27 * F_46 ( struct V_81 * V_82 , const char * V_74 )
{
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
strcpy ( V_84 . V_74 , V_74 ) ;
V_84 . V_65 = V_66 ;
return F_47 ( V_82 , & V_84 ) ;
}
static int F_48 ( struct V_81 * V_82 , const char * V_85 , const char * V_86 )
{
struct V_27 * V_87 = F_46 ( V_82 , V_85 ) ;
if ( V_87 ) {
strcpy ( V_87 -> V_44 . V_74 , V_86 ) ;
return 0 ;
}
return - V_88 ;
}
static void F_49 ( struct V_81 * V_82 ,
struct V_27 * V_89 , char * * V_90 )
{
for (; * V_90 ; V_90 ++ ) {
struct V_27 * V_91 = F_46 ( V_82 , * V_90 ) ;
if ( V_91 )
F_50 ( V_89 , V_91 ) ;
}
}
int F_51 ( struct V_1 * V_2 )
{
int V_92 ;
struct V_81 * V_82 = V_2 -> V_82 ;
char * * V_93 ;
struct V_27 * V_94 ;
static char * V_95 [] = {
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
NULL
} ;
static char * V_96 [] = {
L_38 , L_33 ,
L_39 , L_34 ,
L_40 , L_41 ,
L_42 , L_43 ,
L_44 , L_45 ,
L_46 , L_47 ,
L_48 , L_49 ,
L_50 , L_51 ,
L_52 , L_53 ,
L_54 , L_55 ,
NULL
} ;
#if 1
for ( V_93 = V_95 ; * V_93 ; V_93 ++ )
F_44 ( V_82 , * V_93 ) ;
for ( V_93 = V_96 ; * V_93 ; V_93 += 2 )
F_48 ( V_82 , V_93 [ 0 ] , V_93 [ 1 ] ) ;
#endif
F_52 ( V_2 , V_97 ) ;
if ( V_2 -> V_62 -> V_98 == 1 ) {
F_52 ( V_2 , V_99 ) ;
if ( V_2 -> V_62 -> V_100 == 1 )
V_92 = F_53 ( V_82 , F_54 ( & V_101 , V_2 ) ) ;
else
V_92 = F_53 ( V_82 , F_54 ( & V_102 , V_2 ) ) ;
if ( V_92 < 0 )
return V_92 ;
}
if ( V_2 -> V_62 -> V_75 ) {
int V_103 ;
for ( V_103 = 0 ; ; V_103 ++ ) {
struct V_60 V_104 ;
V_104 = F_43 ( V_2 -> V_62 , V_103 ) ;
if ( ! V_104 . V_74 )
break;
V_92 = F_53 ( V_82 , F_54 ( & V_104 , V_2 ) ) ;
if ( V_92 < 0 )
return V_92 ;
}
}
V_94 = F_55 ( L_39 ,
V_105 ) ;
if ( ! V_94 )
return - V_106 ;
V_92 = F_53 ( V_82 , V_94 ) ;
if ( V_92 < 0 )
return V_92 ;
F_49 ( V_82 , V_94 , V_107 ) ;
if ( V_2 -> V_62 -> V_75 ) {
V_94 = F_55 ( L_38 ,
NULL ) ;
if ( ! V_94 )
return - V_106 ;
V_92 = F_53 ( V_82 , V_94 ) ;
if ( V_92 < 0 )
return V_92 ;
F_49 ( V_82 , V_94 , V_108 ) ;
}
strcpy ( V_82 -> V_109 , L_56 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_110 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_111 ; V_103 ++ )
V_110 -> V_112 [ V_103 ] =
F_3 ( V_110 , V_113 [ V_103 ] . V_51 ,
V_113 [ V_103 ] . V_50 ) ;
}
void F_57 ( struct V_1 * V_110 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_111 ; V_103 ++ )
F_2 ( V_110 , V_113 [ V_103 ] . V_51 ,
V_113 [ V_103 ] . V_50 ,
V_110 -> V_112 [ V_103 ] ) ;
F_1 ( V_110 ) ;
F_6 ( V_110 ) ;
F_7 ( V_110 , V_110 -> V_19 , 1 ) ;
for ( V_103 = 0 ; V_103 < 4 ; V_103 ++ )
F_10 ( V_110 , V_103 ) ;
if ( V_110 -> V_62 -> V_98 )
F_9 ( V_110 ) ;
}
