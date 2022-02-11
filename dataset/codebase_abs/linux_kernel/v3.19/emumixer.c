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
static int F_25 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_27 . V_28 [ 0 ] = V_10 -> V_64 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_65 ;
unsigned int V_66 , V_67 ;
T_1 V_68 ;
int V_46 = 0 ;
unsigned long V_13 ;
T_1 V_69 ;
V_65 = V_8 -> V_16 . V_27 . V_28 [ 0 ] ;
if ( V_65 >= 2 )
return - V_14 ;
V_46 = ( V_10 -> V_64 != V_65 ) ;
if ( V_46 ) {
F_27 ( V_10 , V_70 , 0 ) ;
F_5 ( & V_10 -> V_71 , V_13 ) ;
V_68 = F_28 ( V_10 -> V_72 + V_73 ) ;
if ( V_65 == 0 )
F_29 ( V_68 | 0x4 , V_10 -> V_72 + V_73 ) ;
else
F_29 ( V_68 & ~ 0x4 , V_10 -> V_72 + V_73 ) ;
F_6 ( & V_10 -> V_71 , V_13 ) ;
V_66 = V_10 -> V_74 [ V_65 ] [ 0 ] ;
V_67 = V_10 -> V_74 [ V_10 -> V_64 ] [ 0 ] ;
if ( V_66 != V_67 )
F_27 ( V_10 , V_75 , ( ( V_66 ) & 0xff ) ) ;
V_66 = V_10 -> V_74 [ V_65 ] [ 1 ] ;
V_67 = V_10 -> V_74 [ V_10 -> V_64 ] [ 1 ] ;
if ( V_66 != V_67 )
F_27 ( V_10 , V_76 , ( ( V_66 ) & 0xff ) ) ;
V_69 = 1 << ( V_65 + 2 ) ;
F_27 ( V_10 , V_70 , V_69 ) ;
V_10 -> V_64 = V_65 ;
}
return V_46 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_77 ;
V_4 -> V_6 = 2 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = 255 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_65 ;
V_65 = V_2 -> V_26 ;
if ( V_65 >= 2 )
return - V_14 ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_10 -> V_74 [ V_65 ] [ 0 ] ;
V_8 -> V_16 . integer . V_16 [ 1 ] = V_10 -> V_74 [ V_65 ] [ 1 ] ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_67 ;
unsigned int V_66 ;
unsigned int V_65 ;
int V_46 = 0 ;
V_65 = V_2 -> V_26 ;
if ( V_65 >= 2 )
return - V_14 ;
V_67 = V_10 -> V_74 [ V_65 ] [ 0 ] ;
V_66 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_66 > 0xff )
return 0 ;
if ( V_67 != V_66 ) {
if ( V_10 -> V_64 == V_65 )
F_27 ( V_10 , V_75 , ( ( V_66 ) & 0xff ) ) ;
V_10 -> V_74 [ V_65 ] [ 0 ] = V_66 ;
V_46 = 1 ;
}
V_67 = V_10 -> V_74 [ V_65 ] [ 1 ] ;
V_66 = V_8 -> V_16 . integer . V_16 [ 1 ] ;
if ( V_66 > 0xff )
return 0 ;
if ( V_67 != V_66 ) {
if ( V_10 -> V_64 == V_65 )
F_27 ( V_10 , V_76 , ( ( V_66 ) & 0xff ) ) ;
V_10 -> V_74 [ V_65 ] [ 1 ] = V_66 ;
V_46 = 1 ;
}
return V_46 ;
}
static int F_33 ( struct V_1 * V_2 ,
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
F_34 ( V_10 , V_80 + V_11 , 0 , V_31 ) ;
V_10 -> V_19 [ V_11 ] = V_31 ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static void F_35 ( struct V_9 * V_10 , int V_81 , unsigned char * V_82 )
{
if ( V_10 -> V_83 ) {
F_34 ( V_10 , V_84 , V_81 ,
F_36 ( V_82 ) ) ;
F_34 ( V_10 , V_85 , V_81 ,
F_37 ( V_82 ) ) ;
} else {
F_34 ( V_10 , V_86 , V_81 ,
F_38 ( V_82 ) ) ;
}
}
static void F_39 ( struct V_9 * V_10 , int V_81 , unsigned char * V_87 )
{
F_34 ( V_10 , V_88 , V_81 , V_87 [ 0 ] ) ;
F_34 ( V_10 , V_89 , V_81 , V_87 [ 1 ] ) ;
F_34 ( V_10 , V_90 , V_81 , V_87 [ 2 ] ) ;
F_34 ( V_10 , V_91 , V_81 , V_87 [ 3 ] ) ;
if ( V_10 -> V_83 ) {
unsigned int V_31 = ( ( unsigned int ) V_87 [ 4 ] << 24 ) |
( ( unsigned int ) V_87 [ 5 ] << 16 ) |
( ( unsigned int ) V_87 [ 6 ] << 8 ) |
( unsigned int ) V_87 [ 7 ] ;
F_34 ( V_10 , V_92 , V_81 , V_31 ) ;
}
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_77 ;
V_4 -> V_6 = V_10 -> V_83 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = V_10 -> V_83 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_81 , V_11 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
int V_38 = V_10 -> V_83 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_81 = 0 ; V_81 < 3 ; V_81 ++ )
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ ( V_81 * V_96 ) + V_11 ] =
V_94 -> V_97 [ V_81 ] [ V_11 ] & V_38 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_81 , V_11 , V_31 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
int V_38 = V_10 -> V_83 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_81 = 0 ; V_81 < 3 ; V_81 ++ )
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ ( V_81 * V_96 ) + V_11 ] & V_38 ;
if ( V_94 -> V_97 [ V_81 ] [ V_11 ] != V_31 ) {
V_94 -> V_97 [ V_81 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ 0 ] && V_94 -> V_98 -> V_99 [ 1 ] ) {
F_35 ( V_10 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 ,
& V_94 -> V_97 [ 1 ] [ 0 ] ) ;
F_35 ( V_10 , V_94 -> V_98 -> V_99 [ 1 ] -> V_100 ,
& V_94 -> V_97 [ 2 ] [ 0 ] ) ;
} else if ( V_94 -> V_98 -> V_99 [ 0 ] ) {
F_35 ( V_10 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 ,
& V_94 -> V_97 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_77 ;
V_4 -> V_6 = V_10 -> V_83 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = 255 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_96 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_94 -> V_101 [ V_11 / V_96 ] [ V_11 % V_96 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_96 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_94 -> V_101 [ V_11 / V_96 ] [ V_11 % V_96 ] != V_31 ) {
V_94 -> V_101 [ V_11 / V_96 ] [ V_11 % V_96 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ 0 ] && V_94 -> V_98 -> V_99 [ 1 ] ) {
F_39 ( V_10 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 ,
& V_94 -> V_101 [ 1 ] [ 0 ] ) ;
F_39 ( V_10 , V_94 -> V_98 -> V_99 [ 1 ] -> V_100 ,
& V_94 -> V_101 [ 2 ] [ 0 ] ) ;
} else if ( V_94 -> V_98 -> V_99 [ 0 ] ) {
F_39 ( V_10 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 ,
& V_94 -> V_101 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_77 ;
V_4 -> V_6 = 3 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = 0xffff ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
int V_11 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_94 -> V_102 [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_95 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_46 = 0 , V_11 , V_31 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 0xffff ;
if ( V_94 -> V_102 [ V_11 ] != V_31 ) {
V_94 -> V_102 [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ 0 ] && V_94 -> V_98 -> V_99 [ 1 ] ) {
F_34 ( V_10 , V_103 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 , V_94 -> V_102 [ 1 ] ) ;
F_34 ( V_10 , V_103 , V_94 -> V_98 -> V_99 [ 1 ] -> V_100 , V_94 -> V_102 [ 2 ] ) ;
} else if ( V_94 -> V_98 -> V_99 [ 0 ] ) {
F_34 ( V_10 , V_103 , V_94 -> V_98 -> V_99 [ 0 ] -> V_100 , V_94 -> V_102 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_77 ;
V_4 -> V_6 = V_10 -> V_83 ? 8 : 4 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = V_10 -> V_83 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_104 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
int V_38 = V_10 -> V_83 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] =
V_94 -> V_97 [ 0 ] [ V_11 ] & V_38 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_105 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_93 * V_94 = & V_10 -> V_104 [ V_105 ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
int V_38 = V_10 -> V_83 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & V_38 ;
if ( V_94 -> V_97 [ 0 ] [ V_11 ] != V_31 ) {
V_94 -> V_97 [ 0 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ V_105 ] ) {
F_35 ( V_10 , V_94 -> V_98 -> V_99 [ V_105 ] -> V_100 ,
& V_94 -> V_97 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_77 ;
V_4 -> V_6 = V_10 -> V_83 ? 8 : 4 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = 255 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_104 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_94 -> V_101 [ 0 ] [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_105 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_93 * V_94 = & V_10 -> V_104 [ V_105 ] ;
int V_46 = 0 , V_11 , V_31 ;
int V_96 = V_10 -> V_83 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
V_31 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_94 -> V_101 [ 0 ] [ V_11 ] != V_31 ) {
V_94 -> V_101 [ 0 ] [ V_11 ] = V_31 ;
V_46 = 1 ;
}
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ V_105 ] ) {
F_39 ( V_10 , V_94 -> V_98 -> V_99 [ V_105 ] -> V_100 ,
& V_94 -> V_101 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_77 ;
V_4 -> V_6 = 1 ;
V_4 -> V_16 . integer . V_78 = 0 ;
V_4 -> V_16 . integer . V_79 = 0xffff ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_93 * V_94 =
& V_10 -> V_104 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_94 -> V_102 [ 0 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_105 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_93 * V_94 = & V_10 -> V_104 [ V_105 ] ;
int V_46 = 0 , V_31 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_31 = V_8 -> V_16 . integer . V_16 [ 0 ] & 0xffff ;
if ( V_94 -> V_102 [ 0 ] != V_31 ) {
V_94 -> V_102 [ 0 ] = V_31 ;
V_46 = 1 ;
}
if ( V_46 && V_94 -> V_98 ) {
if ( V_94 -> V_98 -> V_99 [ V_105 ] ) {
F_34 ( V_10 , V_103 , V_94 -> V_98 -> V_99 [ V_105 ] -> V_100 , V_94 -> V_102 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( V_10 -> V_83 )
V_8 -> V_16 . integer . V_16 [ 0 ] = F_28 ( V_10 -> V_72 + V_73 ) & V_106 ? 1 : 0 ;
else
V_8 -> V_16 . integer . V_16 [ 0 ] = F_28 ( V_10 -> V_72 + V_107 ) & V_108 ? 1 : 0 ;
if ( V_10 -> V_20 -> V_109 )
V_8 -> V_16 . integer . V_16 [ 0 ] =
! V_8 -> V_16 . integer . V_16 [ 0 ] ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_110 , V_31 , V_111 ;
int V_46 = 0 ;
V_111 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_10 -> V_20 -> V_109 )
V_111 = ! V_111 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
if ( V_10 -> V_20 -> V_112 ) {
} else if ( V_10 -> V_83 ) {
V_110 = F_28 ( V_10 -> V_72 + V_73 ) ;
V_31 = V_111 ? V_106 : 0 ;
V_46 = ( V_110 & V_106 ) != V_31 ;
if ( V_46 ) {
V_110 &= ~ V_106 ;
V_110 |= V_31 ;
F_29 ( V_110 | V_31 , V_10 -> V_72 + V_73 ) ;
}
}
V_110 = F_28 ( V_10 -> V_72 + V_107 ) ;
V_31 = V_111 ? V_108 : 0 ;
V_46 |= ( V_110 & V_108 ) != V_31 ;
if ( V_46 ) {
V_110 &= ~ V_108 ;
V_110 |= V_31 ;
F_29 ( V_110 | V_31 , V_10 -> V_72 + V_107 ) ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_46 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
V_31 = F_61 ( V_10 -> V_113 , V_114 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ! ! V_31 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_31 ;
if ( V_8 -> V_16 . integer . V_16 [ 0 ] )
V_31 = 0x0f0f ;
else
V_31 = 0 ;
return F_63 ( V_10 -> V_113 , V_114 , V_31 ) ;
}
static void F_64 ( struct V_115 * V_113 )
{
struct V_9 * V_10 = V_113 -> V_116 ;
V_10 -> V_113 = NULL ;
}
static int F_65 ( struct V_117 * V_118 , const char * V_119 )
{
struct V_120 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
strcpy ( V_12 . V_119 , V_119 ) ;
V_12 . V_121 = V_122 ;
return F_66 ( V_118 , & V_12 ) ;
}
static struct V_1 * F_67 ( struct V_117 * V_118 , const char * V_119 )
{
struct V_120 V_123 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
strcpy ( V_123 . V_119 , V_119 ) ;
V_123 . V_121 = V_122 ;
return F_68 ( V_118 , & V_123 ) ;
}
static int F_69 ( struct V_117 * V_118 , const char * V_124 , const char * V_125 )
{
struct V_1 * V_126 = F_67 ( V_118 , V_124 ) ;
if ( V_126 ) {
strcpy ( V_126 -> V_12 . V_119 , V_125 ) ;
return 0 ;
}
return - V_127 ;
}
int F_70 ( struct V_9 * V_10 ,
int V_128 , int V_129 )
{
int V_130 , V_131 ;
struct V_1 * V_126 ;
struct V_117 * V_118 = V_10 -> V_118 ;
char * * V_132 ;
static char * V_133 [] = {
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
static char * V_134 [] = {
L_17 , L_12 ,
L_18 , L_14 ,
L_19 , L_16 ,
NULL
} ;
static char * V_135 [] = {
L_20 ,
L_21 ,
L_7 ,
L_8 ,
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
NULL
} ;
static char * V_136 [] = {
L_32 , L_21 ,
L_33 , L_23 ,
L_34 , L_31 ,
NULL
} ;
static char * V_137 [] = {
L_35 , L_36 ,
L_32 , L_37 ,
L_33 , L_23 ,
L_34 , L_38 ,
L_39 , L_40 ,
NULL
} ;
static char * V_138 [] = {
L_41 ,
L_36 ,
L_42 ,
L_40 ,
NULL
} ;
static char * V_139 [] = {
L_20 ,
L_21 ,
L_7 ,
L_8 ,
L_24 ,
L_25 ,
L_26 ,
L_41 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
NULL
} ;
static char * V_140 [] = {
L_22 , L_50 ,
L_23 , L_51 ,
L_33 , L_23 ,
L_52 , L_53 ,
L_54 , L_55 ,
L_56 , L_57 ,
L_58 , L_59 ,
L_30 , L_60 ,
L_31 , L_41 ,
L_61 , L_62 ,
L_63 , L_35 ,
L_64 , L_65 ,
L_66 , L_39 ,
L_67 , L_68 ,
L_69 , L_42 ,
L_28 , L_70 ,
L_29 , L_71 ,
NULL
} ;
if ( V_10 -> V_20 -> V_141 ) {
struct V_142 * V_143 ;
struct V_144 V_113 ;
static struct V_145 V_146 = {
. V_147 = V_148 ,
. V_149 = V_150 ,
} ;
if ( ( V_130 = V_142 ( V_10 -> V_118 , 0 , & V_146 , NULL , & V_143 ) ) < 0 )
return V_130 ;
V_143 -> V_151 = 1 ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_116 = V_10 ;
V_113 . V_152 = F_64 ;
V_113 . V_153 = V_154 ;
if ( ( V_130 = F_71 ( V_143 , & V_113 , & V_10 -> V_113 ) ) < 0 ) {
if ( V_10 -> V_20 -> V_141 == 1 )
return V_130 ;
F_72 ( V_10 -> V_118 -> V_155 ,
L_72 ) ;
F_72 ( V_10 -> V_118 -> V_155 ,
L_73 ) ;
F_73 ( V_10 -> V_118 , V_143 ) ;
goto V_156;
}
if ( V_10 -> V_83 ) {
F_74 ( V_10 -> V_113 , V_157 , 0x0000 ) ;
F_74 ( V_10 -> V_113 , V_158 , 0x0000 ) ;
if ( V_10 -> V_20 -> V_159 )
V_132 = V_139 ;
else
V_132 = V_135 ;
} else {
if ( V_10 -> V_113 -> V_12 == V_160 ) {
V_10 -> V_161 = 1 ;
F_34 ( V_10 , V_162 , 0 , V_163 | V_164 | V_165 | V_166 ) ;
F_74 ( V_10 -> V_113 , V_167 , 0x0202 ) ;
F_65 ( V_118 , L_74 ) ;
F_65 ( V_118 , L_75 ) ;
}
F_74 ( V_10 -> V_113 , V_168 , 0x0202 ) ;
F_74 ( V_10 -> V_113 , V_169 , 0x0202 ) ;
V_132 = V_133 ;
}
for (; * V_132 ; V_132 ++ )
F_65 ( V_118 , * V_132 ) ;
} else if ( V_10 -> V_20 -> V_112 ) {
V_132 = V_138 ;
for (; * V_132 ; V_132 ++ )
F_65 ( V_118 , * V_132 ) ;
} else {
V_156:
if ( V_10 -> V_20 -> V_170 )
strcpy ( V_10 -> V_118 -> V_171 , L_76 ) ;
else if ( V_10 -> V_83 )
strcpy ( V_10 -> V_118 -> V_171 , L_77 ) ;
else
strcpy ( V_10 -> V_118 -> V_171 , L_78 ) ;
}
if ( V_10 -> V_83 )
if ( V_10 -> V_20 -> V_159 )
V_132 = V_140 ;
else if ( V_10 -> V_20 -> V_112 )
V_132 = V_137 ;
else
V_132 = V_136 ;
else
V_132 = V_134 ;
for (; * V_132 ; V_132 += 2 )
F_69 ( V_118 , V_132 [ 0 ] , V_132 [ 1 ] ) ;
if ( V_10 -> V_20 -> V_172 == 0x80401102 ) {
F_65 ( V_118 , L_14 ) ;
F_65 ( V_118 , L_16 ) ;
F_65 ( V_118 , L_79 ) ;
F_65 ( V_118 , L_80 ) ;
}
if ( V_10 -> V_20 -> V_172 == 0x20071102 ) {
F_69 ( V_118 , L_49 , L_81 ) ;
F_69 ( V_118 , L_36 , L_49 ) ;
F_69 ( V_118 , L_82 , L_83 ) ;
F_69 ( V_118 , L_41 , L_84 ) ;
F_65 ( V_118 , L_43 ) ;
F_65 ( V_118 , L_44 ) ;
F_65 ( V_118 , L_45 ) ;
F_65 ( V_118 , L_46 ) ;
F_65 ( V_118 , L_47 ) ;
}
if ( ( V_126 = V_10 -> V_173 = F_75 ( & V_174 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_128 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = V_10 -> V_177 = F_75 ( & V_178 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_128 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = V_10 -> V_179 = F_75 ( & V_180 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_128 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = V_10 -> V_181 = F_75 ( & V_182 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_129 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = V_10 -> V_183 = F_75 ( & V_184 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_129 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = V_10 -> V_185 = F_75 ( & V_186 , V_10 ) ) == NULL )
return - V_175 ;
V_126 -> V_12 . V_176 = V_129 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
for ( V_131 = 0 ; V_131 < 32 ; V_131 ++ ) {
struct V_93 * V_94 ;
int V_187 ;
V_94 = & V_10 -> V_95 [ V_131 ] ;
V_94 -> V_98 = NULL ;
for ( V_187 = 0 ; V_187 < 4 ; V_187 ++ )
V_94 -> V_97 [ 0 ] [ V_187 ] =
V_94 -> V_97 [ 1 ] [ V_187 ] =
V_94 -> V_97 [ 2 ] [ V_187 ] = V_187 ;
memset ( & V_94 -> V_101 , 0 , sizeof( V_94 -> V_101 ) ) ;
V_94 -> V_101 [ 0 ] [ 0 ] = V_94 -> V_101 [ 0 ] [ 1 ] =
V_94 -> V_101 [ 1 ] [ 0 ] = V_94 -> V_101 [ 2 ] [ 1 ] = 255 ;
V_94 -> V_102 [ 0 ] = V_94 -> V_102 [ 1 ] = V_94 -> V_102 [ 2 ] = 0xffff ;
}
for ( V_131 = 0 ; V_131 < V_188 ; V_131 ++ ) {
struct V_93 * V_94 ;
int V_187 ;
V_94 = & V_10 -> V_104 [ V_131 ] ;
V_94 -> V_98 = NULL ;
V_94 -> V_97 [ 0 ] [ 0 ] = V_131 ;
V_94 -> V_97 [ 0 ] [ 1 ] = ( V_131 == 0 ) ? 1 : 0 ;
for ( V_187 = 0 ; V_187 < 2 ; V_187 ++ )
V_94 -> V_97 [ 0 ] [ 2 + V_187 ] = 13 + V_187 ;
if ( V_10 -> V_83 )
for ( V_187 = 0 ; V_187 < 4 ; V_187 ++ )
V_94 -> V_97 [ 0 ] [ 4 + V_187 ] = 60 + V_187 ;
memset ( & V_94 -> V_101 , 0 , sizeof( V_94 -> V_101 ) ) ;
V_94 -> V_101 [ 0 ] [ 0 ] = 255 ;
V_94 -> V_102 [ 0 ] = 0xffff ;
}
if ( ! V_10 -> V_20 -> V_170 ) {
if ( ( V_126 = F_75 ( & V_189 , V_10 ) ) == NULL )
return - V_175 ;
if ( ! V_10 -> V_83 )
V_126 -> V_12 . V_176 = V_10 -> V_190 -> V_176 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
if ( ( V_126 = F_75 ( & V_191 , V_10 ) ) == NULL )
return - V_175 ;
if ( ! V_10 -> V_83 )
V_126 -> V_12 . V_176 = V_10 -> V_190 -> V_176 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
}
if ( V_10 -> V_20 -> V_21 ) {
;
} else if ( V_10 -> V_83 ) {
if ( ( V_126 = F_75 ( & V_192 , V_10 ) ) == NULL )
return - V_175 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
#if 0
if ((kctl = snd_ctl_new1(&snd_audigy_spdif_output_rate, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
#endif
} else if ( ! V_10 -> V_20 -> V_170 ) {
if ( ( V_126 = F_75 ( & V_193 , V_10 ) ) == NULL )
return - V_175 ;
if ( ( V_130 = F_76 ( V_118 , V_126 ) ) )
return V_130 ;
}
if ( V_10 -> V_20 -> V_194 ) {
if ( ( V_130 = F_77 ( V_10 ) ) )
return V_130 ;
}
if ( V_10 -> V_20 -> V_21 == V_22 ) {
int V_195 ;
for ( V_195 = 0 ; V_195 < F_78 ( V_196 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_196 [ V_195 ] ,
V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_197 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_197 [ V_195 ] ,
V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_198 ) - 2 ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_198 [ V_195 ] , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_199 ) - 2 ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_199 [ V_195 ] , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
V_130 = F_76 ( V_118 ,
F_75 ( & V_200 , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
} else if ( V_10 -> V_20 -> V_21 ) {
int V_195 ;
for ( V_195 = 0 ; V_195 < F_78 ( V_201 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_201 [ V_195 ] ,
V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_197 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_197 [ V_195 ] ,
V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_198 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_198 [ V_195 ] , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
for ( V_195 = 0 ; V_195 < F_78 ( V_199 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 ,
F_75 ( & V_199 [ V_195 ] , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
V_130 = F_76 ( V_118 ,
F_75 ( & V_200 , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_10 -> V_20 -> V_112 ) {
int V_195 ;
V_130 = F_76 ( V_118 , F_75 ( & V_202 , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
for ( V_195 = 0 ; V_195 < F_78 ( V_203 ) ; V_195 ++ ) {
V_130 = F_76 ( V_118 , F_75 ( & V_203 [ V_195 ] , V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
}
if ( V_10 -> V_20 -> V_141 && V_10 -> V_83 ) {
V_130 = F_76 ( V_118 , F_75 ( & V_204 ,
V_10 ) ) ;
if ( V_130 < 0 )
return V_130 ;
}
return 0 ;
}
