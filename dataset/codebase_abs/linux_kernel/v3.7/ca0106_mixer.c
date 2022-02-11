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
static char * V_35 [ 6 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6
} ;
V_34 -> type = V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_31 . V_38 . V_39 = 6 ;
if ( V_34 -> V_31 . V_38 . V_40 > 5 )
V_34 -> V_31 . V_38 . V_40 = 5 ;
strcpy ( V_34 -> V_31 . V_38 . V_41 , V_35 [ V_34 -> V_31 . V_38 . V_40 ] ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_38 . V_40 [ 0 ] = V_2 -> V_10 ;
return 0 ;
}
static int F_16 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_3 ;
int V_32 = 0 ;
V_3 = V_30 -> V_31 . V_38 . V_40 [ 0 ] ;
if ( V_3 >= 6 )
return - V_42 ;
V_32 = ( V_2 -> V_10 != V_3 ) ;
if ( V_32 ) {
V_2 -> V_10 = V_3 ;
F_6 ( V_2 ) ;
}
return V_32 ;
}
static int F_17 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static char * V_35 [ 6 ] = {
L_7 , L_8 , L_9 , L_10
} ;
V_34 -> type = V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_31 . V_38 . V_39 = 4 ;
if ( V_34 -> V_31 . V_38 . V_40 > 3 )
V_34 -> V_31 . V_38 . V_40 = 3 ;
strcpy ( V_34 -> V_31 . V_38 . V_41 , V_35 [ V_34 -> V_31 . V_38 . V_40 ] ) ;
return 0 ;
}
static int F_18 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_38 . V_40 [ 0 ] = V_2 -> V_19 ;
return 0 ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_43 ;
int V_32 = 0 ;
V_43 = V_30 -> V_31 . V_38 . V_40 [ 0 ] ;
if ( V_43 >= 4 )
return - V_42 ;
V_32 = ( V_2 -> V_19 != V_43 ) ;
if ( V_32 ) {
F_7 ( V_2 , V_43 , 0 ) ;
}
return V_32 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static char * V_35 [ 2 ] = { L_11 , L_9 } ;
V_34 -> type = V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_31 . V_38 . V_39 = 2 ;
if ( V_34 -> V_31 . V_38 . V_40 > 1 )
V_34 -> V_31 . V_38 . V_40 = 1 ;
strcpy ( V_34 -> V_31 . V_38 . V_41 , V_35 [ V_34 -> V_31 . V_38 . V_40 ] ) ;
return 0 ;
}
static int F_21 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
static char * V_35 [ 2 ] = { L_9 , L_12 } ;
V_34 -> type = V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_31 . V_38 . V_39 = 2 ;
if ( V_34 -> V_31 . V_38 . V_40 > 1 )
V_34 -> V_31 . V_38 . V_40 = 1 ;
strcpy ( V_34 -> V_31 . V_38 . V_41 , V_35 [ V_34 -> V_31 . V_38 . V_40 ] ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
V_30 -> V_31 . V_38 . V_40 [ 0 ] = V_2 -> V_23 ;
return 0 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_3 ;
int V_32 = 0 ;
V_3 = V_30 -> V_31 . V_38 . V_40 [ 0 ] ;
if ( V_3 > 1 )
return - V_42 ;
V_32 = ( V_2 -> V_23 != V_3 ) ;
if ( V_32 ) {
V_2 -> V_23 = V_3 ;
F_9 ( V_2 ) ;
}
return V_32 ;
}
static int F_24 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_44 ;
V_34 -> V_37 = 1 ;
return 0 ;
}
static void F_25 ( unsigned char * V_45 , unsigned int V_46 )
{
V_45 [ 0 ] = ( V_46 >> 0 ) & 0xff ;
V_45 [ 1 ] = ( V_46 >> 8 ) & 0xff ;
V_45 [ 2 ] = ( V_46 >> 16 ) & 0xff ;
V_45 [ 3 ] = ( V_46 >> 24 ) & 0xff ;
}
static int F_26 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_27 ( V_28 , & V_30 -> V_47 ) ;
F_25 ( V_30 -> V_31 . V_48 . V_45 ,
V_2 -> V_49 [ V_24 ] ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_27 ( V_28 , & V_30 -> V_47 ) ;
F_25 ( V_30 -> V_31 . V_48 . V_45 ,
V_2 -> V_26 [ V_24 ] ) ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
V_30 -> V_31 . V_48 . V_45 [ 0 ] = 0xff ;
V_30 -> V_31 . V_48 . V_45 [ 1 ] = 0xff ;
V_30 -> V_31 . V_48 . V_45 [ 2 ] = 0xff ;
V_30 -> V_31 . V_48 . V_45 [ 3 ] = 0xff ;
return 0 ;
}
static unsigned int F_30 ( unsigned char * V_45 )
{
return ( ( unsigned int ) V_45 [ 0 ] << 0 ) |
( ( unsigned int ) V_45 [ 1 ] << 8 ) |
( ( unsigned int ) V_45 [ 2 ] << 16 ) |
( ( unsigned int ) V_45 [ 3 ] << 24 ) ;
}
static int F_31 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_27 ( V_28 , & V_30 -> V_47 ) ;
unsigned int V_3 ;
V_3 = F_30 ( V_30 -> V_31 . V_48 . V_45 ) ;
if ( V_3 != V_2 -> V_49 [ V_24 ] ) {
V_2 -> V_49 [ V_24 ] = V_3 ;
V_2 -> V_26 [ V_24 ] = V_3 ;
F_10 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_32 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_24 = F_27 ( V_28 , & V_30 -> V_47 ) ;
unsigned int V_3 ;
V_3 = F_30 ( V_30 -> V_31 . V_48 . V_45 ) ;
if ( V_3 != V_2 -> V_26 [ V_24 ] ) {
V_2 -> V_26 [ V_24 ] = V_3 ;
F_10 ( V_2 , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_50 ;
V_34 -> V_37 = 2 ;
V_34 -> V_31 . integer . V_51 = 0 ;
V_34 -> V_31 . integer . V_52 = 255 ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_31 ;
int V_53 , V_54 ;
V_53 = ( V_28 -> V_55 >> 8 ) & 0xff ;
V_54 = V_28 -> V_55 & 0xff ;
V_31 = F_3 ( V_2 , V_54 , V_53 ) ;
V_30 -> V_31 . integer . V_31 [ 0 ] = 0xff - ( ( V_31 >> 24 ) & 0xff ) ;
V_30 -> V_31 . integer . V_31 [ 1 ] = 0xff - ( ( V_31 >> 16 ) & 0xff ) ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_56 , V_57 ;
int V_53 , V_54 ;
V_53 = ( V_28 -> V_55 >> 8 ) & 0xff ;
V_54 = V_28 -> V_55 & 0xff ;
V_56 = F_3 ( V_2 , V_54 , V_53 ) ;
V_57 = ( ( 0xff - V_30 -> V_31 . integer . V_31 [ 0 ] ) << 24 ) |
( ( 0xff - V_30 -> V_31 . integer . V_31 [ 1 ] ) << 16 ) ;
V_57 |= ( ( 0xff - V_30 -> V_31 . integer . V_31 [ 0 ] ) << 8 ) |
( ( 0xff - V_30 -> V_31 . integer . V_31 [ 1 ] ) ) ;
if ( V_56 == V_57 )
return 0 ;
F_2 ( V_2 , V_54 , V_53 , V_57 ) ;
return 1 ;
}
static int F_36 ( struct V_27 * V_28 ,
struct V_33 * V_34 )
{
V_34 -> type = V_50 ;
V_34 -> V_37 = 2 ;
V_34 -> V_31 . integer . V_51 = 0 ;
V_34 -> V_31 . integer . V_52 = 255 ;
return 0 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
int V_43 ;
V_43 = V_28 -> V_55 ;
V_30 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_18 [ V_43 ] [ 0 ] ;
V_30 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_18 [ V_43 ] [ 1 ] ;
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_16 ;
unsigned int V_15 ;
int V_43 ;
int V_32 = 0 ;
V_43 = V_28 -> V_55 ;
V_16 = V_2 -> V_18 [ V_43 ] [ 0 ] ;
V_15 = V_30 -> V_31 . integer . V_31 [ 0 ] ;
if ( V_15 > 0xff )
return - V_42 ;
if ( V_16 != V_15 ) {
if ( V_2 -> V_19 == V_43 )
F_8 ( V_2 , V_20 , ( ( V_15 ) & 0xff ) ) ;
V_2 -> V_18 [ V_43 ] [ 0 ] = V_30 -> V_31 . integer . V_31 [ 0 ] ;
V_32 = 1 ;
}
V_16 = V_2 -> V_18 [ V_43 ] [ 1 ] ;
V_15 = V_30 -> V_31 . integer . V_31 [ 1 ] ;
if ( V_15 > 0xff )
return - V_42 ;
if ( V_16 != V_15 ) {
if ( V_2 -> V_19 == V_43 )
F_8 ( V_2 , V_21 , ( ( V_15 ) & 0xff ) ) ;
V_2 -> V_18 [ V_43 ] [ 1 ] = V_30 -> V_31 . integer . V_31 [ 1 ] ;
V_32 = 1 ;
}
return V_32 ;
}
static int F_39 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_54 = V_28 -> V_55 >> V_58 ;
unsigned int V_59 = V_28 -> V_55 & V_60 ;
V_30 -> V_31 . integer . V_31 [ 0 ] = ! ( V_2 -> V_61 [ V_54 ] & V_59 ) ;
return 0 ;
}
static int F_40 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
unsigned int V_54 = V_28 -> V_55 >> V_58 ;
unsigned int V_59 = V_28 -> V_55 & V_60 ;
int V_62 ;
V_62 = V_2 -> V_61 [ V_54 ] & V_59 ;
if ( V_30 -> V_31 . integer . V_31 [ 0 ] ) {
if ( ! V_62 )
return 0 ;
V_2 -> V_61 [ V_54 ] &= ~ V_59 ;
} else {
if ( V_62 )
return 0 ;
V_2 -> V_61 [ V_54 ] |= V_59 ;
}
V_62 = F_41 ( V_2 , V_2 -> V_61 [ V_54 ] ) ;
return V_62 ? - V_42 : 1 ;
}
static struct V_63 T_2
F_42 ( struct V_64 * V_65 ,
int V_53 )
{
struct V_63 V_66 = { 0 } ;
int V_54 , V_59 ;
int V_67 ;
V_66 . V_68 = V_69 ;
V_66 . V_70 = V_71 ;
V_66 . V_72 = V_73 ;
V_66 . V_74 = F_39 ;
V_66 . V_75 = F_40 ;
switch ( V_53 ) {
case V_76 :
V_66 . V_41 = L_13 ;
V_67 = ( V_65 -> V_77 & 0xf000 ) >> ( 4 * 3 ) ;
break;
case V_78 :
V_66 . V_41 = L_14 ;
V_67 = ( V_65 -> V_77 & 0x0f00 ) >> ( 4 * 2 ) ;
break;
case V_79 :
V_66 . V_41 = L_15 ;
V_67 = ( V_65 -> V_77 & 0x00f0 ) >> ( 4 * 1 ) ;
break;
case V_80 :
V_66 . V_41 = L_16 ;
V_67 = ( V_65 -> V_77 & 0x000f ) >> ( 4 * 0 ) ;
break;
default:
V_66 . V_41 = NULL ;
V_67 = 0 ;
}
V_54 = V_81 [ V_67 ] ;
V_59 = V_82 [ V_67 ] ;
V_66 . V_55 = ( V_54 << V_58 ) | V_59 ;
return V_66 ;
}
static int T_2 F_43 ( struct V_83 * V_84 , const char * V_41 )
{
struct V_85 V_47 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
strcpy ( V_47 . V_41 , V_41 ) ;
V_47 . V_68 = V_69 ;
return F_44 ( V_84 , & V_47 ) ;
}
static struct V_27 T_2 * F_45 ( struct V_83 * V_84 , const char * V_41 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
strcpy ( V_86 . V_41 , V_41 ) ;
V_86 . V_68 = V_69 ;
return F_46 ( V_84 , & V_86 ) ;
}
static int T_2 F_47 ( struct V_83 * V_84 , const char * V_87 , const char * V_88 )
{
struct V_27 * V_89 = F_45 ( V_84 , V_87 ) ;
if ( V_89 ) {
strcpy ( V_89 -> V_47 . V_41 , V_88 ) ;
return 0 ;
}
return - V_90 ;
}
static void T_2 F_48 ( struct V_83 * V_84 ,
struct V_27 * V_91 , char * * V_92 )
{
for (; * V_92 ; V_92 ++ ) {
struct V_27 * V_93 = F_45 ( V_84 , * V_92 ) ;
if ( V_93 )
F_49 ( V_91 , V_93 ) ;
}
}
int T_2 F_50 ( struct V_1 * V_2 )
{
int V_94 ;
struct V_83 * V_84 = V_2 -> V_84 ;
char * * V_95 ;
struct V_27 * V_96 ;
static char * V_97 [] = {
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
static char * V_98 [] = {
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
for ( V_95 = V_97 ; * V_95 ; V_95 ++ )
F_43 ( V_84 , * V_95 ) ;
for ( V_95 = V_98 ; * V_95 ; V_95 += 2 )
F_47 ( V_84 , V_95 [ 0 ] , V_95 [ 1 ] ) ;
#endif
F_51 ( V_2 , V_99 ) ;
if ( V_2 -> V_65 -> V_100 == 1 ) {
F_51 ( V_2 , V_101 ) ;
if ( V_2 -> V_65 -> V_102 == 1 )
V_94 = F_52 ( V_84 , F_53 ( & V_103 , V_2 ) ) ;
else
V_94 = F_52 ( V_84 , F_53 ( & V_104 , V_2 ) ) ;
if ( V_94 < 0 )
return V_94 ;
}
if ( V_2 -> V_65 -> V_77 ) {
int V_105 ;
for ( V_105 = 0 ; ; V_105 ++ ) {
struct V_63 V_106 ;
V_106 = F_42 ( V_2 -> V_65 , V_105 ) ;
if ( ! V_106 . V_41 )
break;
V_94 = F_52 ( V_84 , F_53 ( & V_106 , V_2 ) ) ;
if ( V_94 < 0 )
return V_94 ;
}
}
V_96 = F_54 ( L_39 ,
V_107 ) ;
if ( ! V_96 )
return - V_108 ;
V_94 = F_52 ( V_84 , V_96 ) ;
if ( V_94 < 0 )
return V_94 ;
F_48 ( V_84 , V_96 , V_109 ) ;
if ( V_2 -> V_65 -> V_77 ) {
V_96 = F_54 ( L_38 ,
NULL ) ;
if ( ! V_96 )
return - V_108 ;
V_94 = F_52 ( V_84 , V_96 ) ;
if ( V_94 < 0 )
return V_94 ;
F_48 ( V_84 , V_96 , V_110 ) ;
}
strcpy ( V_84 -> V_111 , L_56 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_112 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_113 ; V_105 ++ )
V_112 -> V_114 [ V_105 ] =
F_3 ( V_112 , V_115 [ V_105 ] . V_54 ,
V_115 [ V_105 ] . V_53 ) ;
}
void F_56 ( struct V_1 * V_112 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_113 ; V_105 ++ )
F_2 ( V_112 , V_115 [ V_105 ] . V_54 ,
V_115 [ V_105 ] . V_53 ,
V_112 -> V_114 [ V_105 ] ) ;
F_1 ( V_112 ) ;
F_6 ( V_112 ) ;
F_7 ( V_112 , V_112 -> V_19 , 1 ) ;
for ( V_105 = 0 ; V_105 < 4 ; V_105 ++ )
F_10 ( V_112 , V_105 ) ;
if ( V_112 -> V_65 -> V_100 )
F_9 ( V_112 ) ;
}
