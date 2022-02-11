static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_11 = F_4 ( V_2 , & V_8 -> V_12 ) ;
unsigned long V_13 ;
if ( V_11 >= 3 )
return - V_14 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_8 -> V_16 . V_17 . V_18 [ 0 ] = ( V_10 -> V_19 [ V_11 ] >> 0 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 1 ] = ( V_10 -> V_19 [ V_11 ] >> 8 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 2 ] = ( V_10 -> V_19 [ V_11 ] >> 16 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 3 ] = ( V_10 -> V_19 [ V_11 ] >> 24 ) & 0xff ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_8 -> V_16 . V_17 . V_18 [ 0 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 1 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 2 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 3 ] = 0xff ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( V_10 -> V_20 -> V_21 == V_22 )
return F_9 ( V_4 , 1 , 49 , V_23 ) ;
else
return F_9 ( V_4 , 1 , 53 , V_24 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_25 ;
V_25 = ( V_2 -> V_26 ) & 0xff ;
if ( V_25 >= 24 ||
( V_10 -> V_20 -> V_21 == V_22 &&
V_25 >= 18 ) )
return - V_14 ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_29 . V_30 [ V_25 ] ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
unsigned int V_25 ;
V_31 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_31 >= 53 ||
( V_10 -> V_20 -> V_21 == V_22 &&
V_31 >= 49 ) )
return - V_14 ;
V_25 = ( V_2 -> V_26 ) & 0xff ;
if ( V_25 >= 24 ||
( V_10 -> V_20 -> V_21 == V_22 &&
V_25 >= 18 ) )
return - V_14 ;
if ( V_10 -> V_29 . V_30 [ V_25 ] == V_31 )
return 0 ;
V_10 -> V_29 . V_30 [ V_25 ] = V_31 ;
if ( V_10 -> V_20 -> V_21 == V_22 )
F_12 ( V_10 ,
V_32 [ V_25 ] , V_33 [ V_31 ] ) ;
else
F_12 ( V_10 ,
V_34 [ V_25 ] , V_35 [ V_31 ] ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_25 ;
V_25 = ( V_2 -> V_26 ) & 0xff ;
if ( V_25 >= 22 )
return - V_14 ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_29 . V_36 [ V_25 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
unsigned int V_25 ;
V_31 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_31 >= 53 ||
( V_10 -> V_20 -> V_21 == V_22 &&
V_31 >= 49 ) )
return - V_14 ;
V_25 = ( V_2 -> V_26 ) & 0xff ;
if ( V_25 >= 22 )
return - V_14 ;
if ( V_10 -> V_29 . V_36 [ V_25 ] == V_31 )
return 0 ;
V_10 -> V_29 . V_36 [ V_25 ] = V_31 ;
if ( V_10 -> V_20 -> V_21 == V_22 )
F_12 ( V_10 ,
V_37 [ V_25 ] , V_33 [ V_31 ] ) ;
else
F_12 ( V_10 ,
V_37 [ V_25 ] , V_35 [ V_31 ] ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_38 = V_2 -> V_26 & 0xff ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ( V_10 -> V_29 . V_39 & V_38 ) ? 1 : 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_38 = V_2 -> V_26 & 0xff ;
unsigned int V_31 , V_40 ;
V_31 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
V_40 = V_10 -> V_29 . V_39 ;
if ( V_31 == 1 )
V_40 = V_40 | V_38 ;
else
V_40 = V_40 & ~ V_38 ;
if ( V_40 != V_10 -> V_29 . V_39 ) {
F_17 ( V_10 , V_41 , V_40 ) ;
V_10 -> V_29 . V_39 = V_40 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_38 = V_2 -> V_26 & 0xff ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ( V_10 -> V_29 . V_42 & V_38 ) ? 1 : 0 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_38 = V_2 -> V_26 & 0xff ;
unsigned int V_31 , V_40 ;
V_31 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
V_40 = V_10 -> V_29 . V_42 ;
if ( V_31 == 1 )
V_40 = V_40 | V_38 ;
else
V_40 = V_40 & ~ V_38 ;
if ( V_40 != V_10 -> V_29 . V_42 ) {
F_17 ( V_10 , V_43 , V_40 ) ;
V_10 -> V_29 . V_42 = V_40 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_44 [ 4 ] = {
L_1 , L_2 , L_3 , L_4
} ;
return F_9 ( V_4 , 1 , 4 , V_44 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_29 . V_45 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
int V_46 = 0 ;
V_31 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_31 >= 4 )
return - V_14 ;
V_46 = ( V_10 -> V_29 . V_45 != V_31 ) ;
if ( V_46 ) {
V_10 -> V_29 . V_45 = V_31 ;
switch ( V_31 ) {
case 0 :
F_17 ( V_10 , V_47 , V_48 ) ;
F_17 ( V_10 , V_49 , V_50 ) ;
F_17 ( V_10 , V_51 ,
V_52 | V_53 ) ;
F_17 ( V_10 , V_54 ,
V_55 | V_56 ) ;
F_23 ( 10 ) ;
F_17 ( V_10 , V_47 , V_57 ) ;
break;
case 1 :
F_17 ( V_10 , V_47 , V_48 ) ;
F_17 ( V_10 , V_49 , V_58 ) ;
F_17 ( V_10 , V_51 ,
V_59 | V_53 ) ;
F_17 ( V_10 , V_54 ,
V_60 | V_56 ) ;
F_23 ( 10 ) ;
F_17 ( V_10 , V_47 , V_57 ) ;
break;
case 2 :
F_17 ( V_10 , V_47 , V_48 ) ;
F_17 ( V_10 , V_49 , V_58 ) ;
F_17 ( V_10 , V_51 ,
V_61 | V_53 ) ;
F_17 ( V_10 , V_54 ,
V_62 | V_56 ) ;
F_23 ( 10 ) ;
F_17 ( V_10 , V_47 , V_57 ) ;
break;
case 3 :
F_17 ( V_10 , V_47 , V_48 ) ;
F_17 ( V_10 , V_49 , V_58 ) ;
F_17 ( V_10 , V_51 ,
V_63 | V_53 ) ;
F_17 ( V_10 , V_54 , V_62 | V_56 ) ;
F_23 ( 10 ) ;
F_17 ( V_10 , V_47 , V_57 ) ;
break;
}
}
return V_46 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_44 [ 2 ] = {
L_3 , L_4
} ;
return F_9 ( V_4 , 1 , 2 , V_44 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_29 . V_64 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
T_1 V_65 ;
int V_46 = 0 ;
V_31 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_31 >= 2 )
return - V_14 ;
V_46 = ( V_10 -> V_29 . V_64 != V_31 ) ;
if ( V_46 ) {
V_10 -> V_29 . V_64 = V_31 ;
V_65 = ( V_10 -> V_29 . V_66 ? V_67 : 0 ) |
( V_10 -> V_29 . V_64 ? V_68 : 0 ) ;
F_17 ( V_10 , V_69 , V_65 ) ;
}
return V_46 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_44 [ 2 ] = {
L_3 , L_4
} ;
return F_9 ( V_4 , 1 , 2 , V_44 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_29 . V_66 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
T_1 V_65 ;
int V_46 = 0 ;
V_31 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_31 >= 2 )
return - V_14 ;
V_46 = ( V_10 -> V_29 . V_66 != V_31 ) ;
if ( V_46 ) {
V_10 -> V_29 . V_66 = V_31 ;
V_65 = ( V_10 -> V_29 . V_66 ? V_67 : 0 ) |
( V_10 -> V_29 . V_64 ? V_68 : 0 ) ;
F_17 ( V_10 , V_69 , V_65 ) ;
}
return V_46 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#if 0
static const char * const texts[4] = {
"Unknown1", "Unknown2", "Mic", "Line"
};
#endif
static const char * const V_44 [ 2 ] = {
L_5 , L_6
} ;
return F_9 ( V_4 , 1 , 2 , V_44 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_70 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_71 ;
unsigned int V_72 , V_73 ;
T_1 V_74 ;
int V_46 = 0 ;
unsigned long V_13 ;
T_1 V_75 ;
V_71 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_71 >= 2 )
return - V_14 ;
V_46 = ( V_10 -> V_70 != V_71 ) ;
if ( V_46 ) {
F_33 ( V_10 , V_76 , 0 ) ;
F_5 ( & V_10 -> V_77 , V_13 ) ;
V_74 = F_34 ( V_10 -> V_78 + V_79 ) ;
if ( V_71 == 0 )
F_35 ( V_74 | 0x4 , V_10 -> V_78 + V_79 ) ;
else
F_35 ( V_74 & ~ 0x4 , V_10 -> V_78 + V_79 ) ;
F_6 ( & V_10 -> V_77 , V_13 ) ;
V_72 = V_10 -> V_80 [ V_71 ] [ 0 ] ;
V_73 = V_10 -> V_80 [ V_10 -> V_70 ] [ 0 ] ;
if ( V_72 != V_73 )
F_33 ( V_10 , V_81 , ( ( V_72 ) & 0xff ) ) ;
V_72 = V_10 -> V_80 [ V_71 ] [ 1 ] ;
V_73 = V_10 -> V_80 [ V_10 -> V_70 ] [ 1 ] ;
if ( V_72 != V_73 )
F_33 ( V_10 , V_82 , ( ( V_72 ) & 0xff ) ) ;
V_75 = 1 << ( V_71 + 2 ) ;
F_33 ( V_10 , V_76 , V_75 ) ;
V_10 -> V_70 = V_71 ;
}
return V_46 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_83 ;
V_4 -> V_6 = 2 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = 255 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_71 ;
V_71 = V_2 -> V_26 ;
if ( V_71 >= 2 )
return - V_14 ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_10 -> V_80 [ V_71 ] [ 0 ] ;
V_8 -> V_16 . integer . V_16 [ 1 ] = V_10 -> V_80 [ V_71 ] [ 1 ] ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_73 ;
unsigned int V_72 ;
unsigned int V_71 ;
int V_46 = 0 ;
V_71 = V_2 -> V_26 ;
if ( V_71 >= 2 )
return - V_14 ;
V_73 = V_10 -> V_80 [ V_71 ] [ 0 ] ;
V_72 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_72 > 0xff )
return 0 ;
if ( V_73 != V_72 ) {
if ( V_10 -> V_70 == V_71 )
F_33 ( V_10 , V_81 , ( ( V_72 ) & 0xff ) ) ;
V_10 -> V_80 [ V_71 ] [ 0 ] = V_72 ;
V_46 = 1 ;
}
V_73 = V_10 -> V_80 [ V_71 ] [ 1 ] ;
V_72 = V_8 -> V_16 . integer . V_16 [ 1 ] ;
if ( V_72 > 0xff )
return 0 ;
if ( V_73 != V_72 ) {
if ( V_10 -> V_70 == V_71 )
F_33 ( V_10 , V_82 , ( ( V_72 ) & 0xff ) ) ;
V_10 -> V_80 [ V_71 ] [ 1 ] = V_72 ;
V_46 = 1 ;
}
return V_46 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_11 = F_4 ( V_2 , & V_8 -> V_12 ) ;
int V_46 ;
unsigned int V_31 ;
unsigned long V_13 ;
if ( V_11 >= 3 )
return - V_14 ;
V_31 = ( V_8 -> V_16 . V_17 . V_18 [ 0 ] << 0 ) |
( V_8 -> V_16 . V_17 . V_18 [ 1 ] << 8 ) |
( V_8 -> V_16 . V_17 . V_18 [ 2 ] << 16 ) |
( V_8 -> V_16 . V_17 . V_18 [ 3 ] << 24 ) ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_46 = V_31 != V_10 -> V_19 [ V_11 ] ;
if ( V_46 ) {
F_40 ( V_10 , V_86 + V_11 , 0 , V_31 ) ;
V_10 -> V_19 [ V_11 ] = V_31 ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static void F_41 ( struct V_9 * V_10 , int V_87 , unsigned char * V_88 )
{
if ( V_10 -> V_89 ) {
F_40 ( V_10 , V_90 , V_87 ,
F_42 ( V_88 ) ) ;
F_40 ( V_10 , V_91 , V_87 ,
F_43 ( V_88 ) ) ;
} else {
F_40 ( V_10 , V_92 , V_87 ,
F_44 ( V_88 ) ) ;
}
}
static void F_45 ( struct V_9 * V_10 , int V_87 , unsigned char * V_93 )
{
F_40 ( V_10 , V_94 , V_87 , V_93 [ 0 ] ) ;
F_40 ( V_10 , V_95 , V_87 , V_93 [ 1 ] ) ;
F_40 ( V_10 , V_96 , V_87 , V_93 [ 2 ] ) ;
F_40 ( V_10 , V_97 , V_87 , V_93 [ 3 ] ) ;
if ( V_10 -> V_89 ) {
unsigned int V_31 = ( ( unsigned int ) V_93 [ 4 ] << 24 ) |
( ( unsigned int ) V_93 [ 5 ] << 16 ) |
( ( unsigned int ) V_93 [ 6 ] << 8 ) |
( unsigned int ) V_93 [ 7 ] ;
F_40 ( V_10 , V_98 , V_87 , V_31 ) ;
}
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_83 ;
V_4 -> V_6 = V_10 -> V_89 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = V_10 -> V_89 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_87 , V_11 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
int V_38 = V_10 -> V_89 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_87 = 0 ; V_87 < 3 ; V_87 ++ )
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ ( V_87 * V_102 ) + V_11 ] =
V_100 -> V_103 [ V_87 ] [ V_11 ] & V_38 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_87 , V_11 , V_31 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
int V_38 = V_10 -> V_89 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_87 = 0 ; V_87 < 3 ; V_87 ++ )
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ ( V_87 * V_102 ) + V_11 ] & V_38 ;
if ( V_100 -> V_103 [ V_87 ] [ V_11 ] != V_31 ) {
V_100 -> V_103 [ V_87 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ 0 ] && V_100 -> V_104 -> V_105 [ 1 ] ) {
F_41 ( V_10 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 ,
& V_100 -> V_103 [ 1 ] [ 0 ] ) ;
F_41 ( V_10 , V_100 -> V_104 -> V_105 [ 1 ] -> V_106 ,
& V_100 -> V_103 [ 2 ] [ 0 ] ) ;
} else if ( V_100 -> V_104 -> V_105 [ 0 ] ) {
F_41 ( V_10 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 ,
& V_100 -> V_103 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_83 ;
V_4 -> V_6 = V_10 -> V_89 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = 255 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_102 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_100 -> V_107 [ V_11 / V_102 ] [ V_11 % V_102 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_102 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_100 -> V_107 [ V_11 / V_102 ] [ V_11 % V_102 ] != V_31 ) {
V_100 -> V_107 [ V_11 / V_102 ] [ V_11 % V_102 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ 0 ] && V_100 -> V_104 -> V_105 [ 1 ] ) {
F_45 ( V_10 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 ,
& V_100 -> V_107 [ 1 ] [ 0 ] ) ;
F_45 ( V_10 , V_100 -> V_104 -> V_105 [ 1 ] -> V_106 ,
& V_100 -> V_107 [ 2 ] [ 0 ] ) ;
} else if ( V_100 -> V_104 -> V_105 [ 0 ] ) {
F_45 ( V_10 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 ,
& V_100 -> V_107 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_83 ;
V_4 -> V_6 = 3 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = 0xffff ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
int V_11 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_100 -> V_108 [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_101 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_11 , V_31 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 0xffff ;
if ( V_100 -> V_108 [ V_11 ] != V_31 ) {
V_100 -> V_108 [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ 0 ] && V_100 -> V_104 -> V_105 [ 1 ] ) {
F_40 ( V_10 , V_109 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 , V_100 -> V_108 [ 1 ] ) ;
F_40 ( V_10 , V_109 , V_100 -> V_104 -> V_105 [ 1 ] -> V_106 , V_100 -> V_108 [ 2 ] ) ;
} else if ( V_100 -> V_104 -> V_105 [ 0 ] ) {
F_40 ( V_10 , V_109 , V_100 -> V_104 -> V_105 [ 0 ] -> V_106 , V_100 -> V_108 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_83 ;
V_4 -> V_6 = V_10 -> V_89 ? 8 : 4 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = V_10 -> V_89 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_110 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
int V_38 = V_10 -> V_89 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] =
V_100 -> V_103 [ 0 ] [ V_11 ] & V_38 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_111 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_99 * V_100 = & V_10 -> V_110 [ V_111 ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
int V_38 = V_10 -> V_89 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & V_38 ;
if ( V_100 -> V_103 [ 0 ] [ V_11 ] != V_31 ) {
V_100 -> V_103 [ 0 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ V_111 ] ) {
F_41 ( V_10 , V_100 -> V_104 -> V_105 [ V_111 ] -> V_106 ,
& V_100 -> V_103 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_83 ;
V_4 -> V_6 = V_10 -> V_89 ? 8 : 4 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = 255 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_110 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_100 -> V_107 [ 0 ] [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_111 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_99 * V_100 = & V_10 -> V_110 [ V_111 ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_102 = V_10 -> V_89 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_102 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_100 -> V_107 [ 0 ] [ V_11 ] != V_31 ) {
V_100 -> V_107 [ 0 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ V_111 ] ) {
F_45 ( V_10 , V_100 -> V_104 -> V_105 [ V_111 ] -> V_106 ,
& V_100 -> V_107 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_83 ;
V_4 -> V_6 = 1 ;
V_4 -> V_16 . integer . V_84 = 0 ;
V_4 -> V_16 . integer . V_85 = 0xffff ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_99 * V_100 =
& V_10 -> V_110 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_100 -> V_108 [ 0 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_111 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_99 * V_100 = & V_10 -> V_110 [ V_111 ] ;
int V_46 = 0 , V_31 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_31 = V_8 -> V_16 . integer . V_16 [ 0 ] & 0xffff ;
if ( V_100 -> V_108 [ 0 ] != V_31 ) {
V_100 -> V_108 [ 0 ] = V_31 ;
V_46 = 1 ;
}
if ( V_46 && V_100 -> V_104 ) {
if ( V_100 -> V_104 -> V_105 [ V_111 ] ) {
F_40 ( V_10 , V_109 , V_100 -> V_104 -> V_105 [ V_111 ] -> V_106 , V_100 -> V_108 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( V_10 -> V_89 )
V_8 -> V_16 . integer . V_16 [ 0 ] = F_34 ( V_10 -> V_78 + V_79 ) & V_112 ? 1 : 0 ;
else
V_8 -> V_16 . integer . V_16 [ 0 ] = F_34 ( V_10 -> V_78 + V_113 ) & V_114 ? 1 : 0 ;
if ( V_10 -> V_20 -> V_115 )
V_8 -> V_16 . integer . V_16 [ 0 ] =
! V_8 -> V_16 . integer . V_16 [ 0 ] ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_116 , V_31 , V_117 ;
int V_46 = 0 ;
V_117 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_10 -> V_20 -> V_115 )
V_117 = ! V_117 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
if ( V_10 -> V_20 -> V_118 ) {
} else if ( V_10 -> V_89 ) {
V_116 = F_34 ( V_10 -> V_78 + V_79 ) ;
V_31 = V_117 ? V_112 : 0 ;
V_46 = ( V_116 & V_112 ) != V_31 ;
if ( V_46 ) {
V_116 &= ~ V_112 ;
V_116 |= V_31 ;
F_35 ( V_116 | V_31 , V_10 -> V_78 + V_79 ) ;
}
}
V_116 = F_34 ( V_10 -> V_78 + V_113 ) ;
V_31 = V_117 ? V_114 : 0 ;
V_46 |= ( V_116 & V_114 ) != V_31 ;
if ( V_46 ) {
V_116 &= ~ V_114 ;
V_116 |= V_31 ;
F_35 ( V_116 | V_31 , V_10 -> V_78 + V_113 ) ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
V_31 = F_67 ( V_10 -> V_119 , V_120 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ! ! V_31 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
if ( V_8 -> V_16 . integer . V_16 [ 0 ] )
V_31 = 0x0f0f ;
else
V_31 = 0 ;
return F_69 ( V_10 -> V_119 , V_120 , V_31 ) ;
}
static void F_70 ( struct V_121 * V_119 )
{
struct V_9 * V_10 = V_119 -> V_122 ;
V_10 -> V_119 = NULL ;
}
static int F_71 ( struct V_123 * V_124 , const char * V_125 )
{
struct V_126 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
strcpy ( V_12 . V_125 , V_125 ) ;
V_12 . V_127 = V_128 ;
return F_72 ( V_124 , & V_12 ) ;
}
static struct V_1 * F_73 ( struct V_123 * V_124 , const char * V_125 )
{
struct V_126 V_129 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
strcpy ( V_129 . V_125 , V_125 ) ;
V_129 . V_127 = V_128 ;
return F_74 ( V_124 , & V_129 ) ;
}
static int F_75 ( struct V_123 * V_124 , const char * V_130 , const char * V_131 )
{
struct V_1 * V_132 = F_73 ( V_124 , V_130 ) ;
if ( V_132 ) {
strcpy ( V_132 -> V_12 . V_125 , V_131 ) ;
return 0 ;
}
return - V_133 ;
}
int F_76 ( struct V_9 * V_10 ,
int V_134 , int V_135 )
{
int V_136 , V_137 ;
struct V_1 * V_132 ;
struct V_123 * V_124 = V_10 -> V_124 ;
char * * V_138 ;
static char * V_139 [] = {
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
NULL
} ;
static char * V_140 [] = {
L_17 , L_12 ,
L_18 , L_14 ,
L_19 , L_16 ,
NULL
} ;
static char * V_141 [] = {
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_9 ,
L_10 ,
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
static char * V_142 [] = {
L_38 , L_21 ,
L_39 , L_23 ,
L_40 , L_36 ,
L_7 , L_41 ,
L_8 , L_42 ,
NULL
} ;
static char * V_143 [] = {
L_43 , L_44 ,
L_38 , L_45 ,
L_39 , L_23 ,
L_40 , L_46 ,
L_47 , L_48 ,
NULL
} ;
static char * V_144 [] = {
L_49 ,
L_44 ,
L_50 ,
L_48 ,
NULL
} ;
static char * V_145 [] = {
L_20 ,
L_21 ,
L_24 ,
L_25 ,
L_26 ,
L_49 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_51 ,
L_52 ,
NULL
} ;
static char * V_146 [] = {
L_22 , L_53 ,
L_23 , L_54 ,
L_39 , L_23 ,
L_55 , L_56 ,
L_57 , L_58 ,
L_59 , L_60 ,
L_61 , L_62 ,
L_35 , L_63 ,
L_36 , L_49 ,
L_64 , L_65 ,
L_66 , L_43 ,
L_67 , L_68 ,
L_69 , L_47 ,
L_70 , L_71 ,
L_72 , L_50 ,
L_33 , L_73 ,
L_34 , L_74 ,
L_7 , L_41 ,
L_8 , L_42 ,
NULL
} ;
if ( V_10 -> V_20 -> V_147 ) {
struct V_148 * V_149 ;
struct V_150 V_119 ;
static struct V_151 V_152 = {
. V_153 = V_154 ,
. V_155 = V_156 ,
} ;
if ( ( V_136 = V_148 ( V_10 -> V_124 , 0 , & V_152 , NULL , & V_149 ) ) < 0 )
return V_136 ;
V_149 -> V_157 = 1 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_122 = V_10 ;
V_119 . V_158 = F_70 ;
V_119 . V_159 = V_160 ;
if ( ( V_136 = F_77 ( V_149 , & V_119 , & V_10 -> V_119 ) ) < 0 ) {
if ( V_10 -> V_20 -> V_147 == 1 )
return V_136 ;
F_78 ( V_10 -> V_124 -> V_161 ,
L_75 ) ;
F_78 ( V_10 -> V_124 -> V_161 ,
L_76 ) ;
F_79 ( V_10 -> V_124 , V_149 ) ;
goto V_162;
}
if ( V_10 -> V_89 ) {
F_80 ( V_10 -> V_119 , V_163 , 0x0000 ) ;
F_80 ( V_10 -> V_119 , V_164 , 0x0000 ) ;
F_81 ( V_10 -> V_119 , V_165 ,
0x0200 , 0x0200 ) ;
if ( V_10 -> V_20 -> V_166 )
V_138 = V_145 ;
else
V_138 = V_141 ;
} else {
if ( V_10 -> V_119 -> V_12 == V_167 ) {
V_10 -> V_168 = 1 ;
F_40 ( V_10 , V_169 , 0 , V_170 | V_171 | V_172 | V_173 ) ;
F_80 ( V_10 -> V_119 , V_174 , 0x0202 ) ;
F_71 ( V_124 , L_77 ) ;
F_71 ( V_124 , L_78 ) ;
}
F_80 ( V_10 -> V_119 , V_175 , 0x0202 ) ;
F_80 ( V_10 -> V_119 , V_176 , 0x0202 ) ;
V_138 = V_139 ;
}
for (; * V_138 ; V_138 ++ )
F_71 ( V_124 , * V_138 ) ;
} else if ( V_10 -> V_20 -> V_118 ) {
V_138 = V_144 ;
for (; * V_138 ; V_138 ++ )
F_71 ( V_124 , * V_138 ) ;
} else {
V_162:
if ( V_10 -> V_20 -> V_177 )
strcpy ( V_10 -> V_124 -> V_178 , L_79 ) ;
else if ( V_10 -> V_89 )
strcpy ( V_10 -> V_124 -> V_178 , L_80 ) ;
else
strcpy ( V_10 -> V_124 -> V_178 , L_81 ) ;
}
if ( V_10 -> V_89 )
if ( V_10 -> V_20 -> V_166 )
V_138 = V_146 ;
else if ( V_10 -> V_20 -> V_118 )
V_138 = V_143 ;
else
V_138 = V_142 ;
else
V_138 = V_140 ;
for (; * V_138 ; V_138 += 2 )
F_75 ( V_124 , V_138 [ 0 ] , V_138 [ 1 ] ) ;
if ( V_10 -> V_20 -> V_179 == 0x80401102 ) {
F_71 ( V_124 , L_14 ) ;
F_71 ( V_124 , L_16 ) ;
F_71 ( V_124 , L_82 ) ;
F_71 ( V_124 , L_83 ) ;
}
if ( V_10 -> V_20 -> V_179 == 0x20071102 ) {
F_75 ( V_124 , L_52 , L_84 ) ;
F_75 ( V_124 , L_44 , L_52 ) ;
F_75 ( V_124 , L_85 , L_86 ) ;
F_75 ( V_124 , L_49 , L_87 ) ;
}
if ( ( V_132 = V_10 -> V_180 = F_82 ( & V_181 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_134 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = V_10 -> V_184 = F_82 ( & V_185 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_134 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = V_10 -> V_186 = F_82 ( & V_187 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_134 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = V_10 -> V_188 = F_82 ( & V_189 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_135 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = V_10 -> V_190 = F_82 ( & V_191 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_135 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = V_10 -> V_192 = F_82 ( & V_193 , V_10 ) ) == NULL )
return - V_182 ;
V_132 -> V_12 . V_183 = V_135 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
for ( V_137 = 0 ; V_137 < 32 ; V_137 ++ ) {
struct V_99 * V_100 ;
int V_194 ;
V_100 = & V_10 -> V_101 [ V_137 ] ;
V_100 -> V_104 = NULL ;
for ( V_194 = 0 ; V_194 < 4 ; V_194 ++ )
V_100 -> V_103 [ 0 ] [ V_194 ] =
V_100 -> V_103 [ 1 ] [ V_194 ] =
V_100 -> V_103 [ 2 ] [ V_194 ] = V_194 ;
memset ( & V_100 -> V_107 , 0 , sizeof( V_100 -> V_107 ) ) ;
V_100 -> V_107 [ 0 ] [ 0 ] = V_100 -> V_107 [ 0 ] [ 1 ] =
V_100 -> V_107 [ 1 ] [ 0 ] = V_100 -> V_107 [ 2 ] [ 1 ] = 255 ;
V_100 -> V_108 [ 0 ] = V_100 -> V_108 [ 1 ] = V_100 -> V_108 [ 2 ] = 0xffff ;
}
for ( V_137 = 0 ; V_137 < V_195 ; V_137 ++ ) {
struct V_99 * V_100 ;
int V_194 ;
V_100 = & V_10 -> V_110 [ V_137 ] ;
V_100 -> V_104 = NULL ;
V_100 -> V_103 [ 0 ] [ 0 ] = V_137 ;
V_100 -> V_103 [ 0 ] [ 1 ] = ( V_137 == 0 ) ? 1 : 0 ;
for ( V_194 = 0 ; V_194 < 2 ; V_194 ++ )
V_100 -> V_103 [ 0 ] [ 2 + V_194 ] = 13 + V_194 ;
if ( V_10 -> V_89 )
for ( V_194 = 0 ; V_194 < 4 ; V_194 ++ )
V_100 -> V_103 [ 0 ] [ 4 + V_194 ] = 60 + V_194 ;
memset ( & V_100 -> V_107 , 0 , sizeof( V_100 -> V_107 ) ) ;
V_100 -> V_107 [ 0 ] [ 0 ] = 255 ;
V_100 -> V_108 [ 0 ] = 0xffff ;
}
if ( ! V_10 -> V_20 -> V_177 ) {
if ( ( V_132 = F_82 ( & V_196 , V_10 ) ) == NULL )
return - V_182 ;
if ( ! V_10 -> V_89 )
V_132 -> V_12 . V_183 = V_10 -> V_197 -> V_183 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
if ( ( V_132 = F_82 ( & V_198 , V_10 ) ) == NULL )
return - V_182 ;
if ( ! V_10 -> V_89 )
V_132 -> V_12 . V_183 = V_10 -> V_197 -> V_183 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
}
if ( V_10 -> V_20 -> V_21 ) {
;
} else if ( V_10 -> V_89 ) {
if ( ( V_132 = F_82 ( & V_199 , V_10 ) ) == NULL )
return - V_182 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
#if 0
if ((kctl = snd_ctl_new1(&snd_audigy_spdif_output_rate, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
#endif
} else if ( ! V_10 -> V_20 -> V_177 ) {
if ( ( V_132 = F_82 ( & V_200 , V_10 ) ) == NULL )
return - V_182 ;
if ( ( V_136 = F_83 ( V_124 , V_132 ) ) )
return V_136 ;
}
if ( V_10 -> V_20 -> V_201 ) {
if ( ( V_136 = F_84 ( V_10 ) ) )
return V_136 ;
}
if ( V_10 -> V_20 -> V_21 == V_22 ) {
int V_202 ;
for ( V_202 = 0 ; V_202 < F_85 ( V_203 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_203 [ V_202 ] ,
V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_204 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_204 [ V_202 ] ,
V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_205 ) - 2 ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_205 [ V_202 ] , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_206 ) - 2 ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_206 [ V_202 ] , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
V_136 = F_83 ( V_124 ,
F_82 ( & V_207 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_83 ( V_124 ,
F_82 ( & V_208 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_83 ( V_124 ,
F_82 ( & V_209 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
} else if ( V_10 -> V_20 -> V_21 ) {
int V_202 ;
for ( V_202 = 0 ; V_202 < F_85 ( V_210 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_210 [ V_202 ] ,
V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_204 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_204 [ V_202 ] ,
V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_205 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_205 [ V_202 ] , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
for ( V_202 = 0 ; V_202 < F_85 ( V_206 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 ,
F_82 ( & V_206 [ V_202 ] , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
V_136 = F_83 ( V_124 ,
F_82 ( & V_207 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_83 ( V_124 ,
F_82 ( & V_208 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_83 ( V_124 ,
F_82 ( & V_209 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_10 -> V_20 -> V_118 ) {
int V_202 ;
V_136 = F_83 ( V_124 , F_82 ( & V_211 , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
for ( V_202 = 0 ; V_202 < F_85 ( V_212 ) ; V_202 ++ ) {
V_136 = F_83 ( V_124 , F_82 ( & V_212 [ V_202 ] , V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
}
if ( V_10 -> V_20 -> V_147 && V_10 -> V_89 ) {
V_136 = F_83 ( V_124 , F_82 ( & V_213 ,
V_10 ) ) ;
if ( V_136 < 0 )
return V_136 ;
}
return 0 ;
}
