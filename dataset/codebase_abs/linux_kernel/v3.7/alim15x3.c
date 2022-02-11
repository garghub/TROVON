static void F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 -> V_6 ) ;
int V_7 = 0x54 + V_1 -> V_8 ;
T_3 V_9 ;
int V_10 = 4 * ( V_2 -> V_11 & 1 ) ;
F_3 ( V_5 , V_7 , & V_9 ) ;
V_9 &= ~ ( 0x0F << V_10 ) ;
V_9 |= ( V_3 << V_10 ) ;
F_4 ( V_5 , V_7 , V_9 ) ;
}
static void F_5 ( T_1 * V_1 , T_2 * V_2 ,
struct V_12 * V_13 , T_3 V_14 )
{
struct V_4 * V_6 = F_2 ( V_1 -> V_6 ) ;
int V_15 = V_1 -> V_8 ? 0x5c : 0x58 ;
int V_16 = 0x56 + V_1 -> V_8 ;
T_3 V_17 = V_2 -> V_11 & 1 , V_18 ;
int V_10 = 4 * V_17 ;
F_3 ( V_6 , V_16 , & V_18 ) ;
V_18 &= ~ ( 0x0F << V_10 ) ;
V_18 |= V_14 << V_10 ;
F_4 ( V_6 , V_16 , V_18 ) ;
if ( V_13 == NULL )
return;
V_13 -> V_19 = F_6 ( V_13 -> V_19 , 1 , 8 ) & 7 ;
V_13 -> V_20 = F_6 ( V_13 -> V_20 , 1 , 8 ) & 7 ;
V_13 -> V_21 = F_6 ( V_13 -> V_21 , 1 , 16 ) & 15 ;
V_13 -> V_22 = F_6 ( V_13 -> V_22 , 1 , 8 ) & 7 ;
V_13 -> V_23 = F_6 ( V_13 -> V_23 , 1 , 16 ) & 15 ;
F_4 ( V_6 , V_15 , V_13 -> V_19 ) ;
F_4 ( V_6 , V_15 + 1 , ( V_13 -> V_20 << 4 ) | V_13 -> V_21 ) ;
F_4 ( V_6 , V_15 + V_17 + 2 ,
( V_13 -> V_22 << 4 ) | V_13 -> V_23 ) ;
}
static void F_7 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_24 = F_8 ( V_2 ) ;
int V_25 = V_26 ? V_26 : 33 ;
unsigned long V_27 = 1000000 / V_25 ;
struct V_12 V_13 ;
F_9 ( V_2 , V_2 -> V_28 , & V_13 , V_27 , 1 ) ;
if ( V_24 ) {
struct V_12 V_29 ;
F_9 ( V_24 , V_24 -> V_28 , & V_29 , V_27 , 1 ) ;
F_10 ( & V_29 , & V_13 , & V_13 ,
V_30 | V_31 ) ;
if ( V_24 -> V_32 ) {
F_9 ( V_24 , V_24 -> V_32 , & V_29 , V_27 , 1 ) ;
F_10 ( & V_29 , & V_13 , & V_13 ,
V_30 | V_31 ) ;
}
}
F_1 ( V_1 , V_2 , ( V_2 -> V_33 == V_34 ) ? 0x05 : 0x00 ) ;
F_5 ( V_1 , V_2 , & V_13 , 0 ) ;
}
static T_3 F_11 ( T_2 * V_2 )
{
if ( V_35 > 0x20 && V_35 < 0xC2 ) {
if ( V_2 -> V_33 != V_34 )
return 0 ;
if ( V_36 &&
strstr ( ( char * ) & V_2 -> V_37 [ V_38 ] , L_1 ) )
return 0 ;
}
return V_2 -> V_1 -> V_39 ;
}
static void F_12 ( T_1 * V_1 , T_2 * V_2 )
{
static T_3 V_40 [ 7 ] = { 0xC , 0xB , 0xA , 0x9 , 0x8 , 0xF , 0xD } ;
struct V_4 * V_6 = F_2 ( V_1 -> V_6 ) ;
T_2 * V_24 = F_8 ( V_2 ) ;
int V_25 = V_26 ? V_26 : 33 ;
unsigned long V_27 = 1000000 / V_25 ;
const T_3 V_41 = V_2 -> V_32 ;
T_3 V_42 = 0x00 ;
struct V_12 V_13 ;
if ( V_41 < V_43 ) {
F_9 ( V_2 , V_2 -> V_32 , & V_13 , V_27 , 1 ) ;
if ( V_24 ) {
struct V_12 V_29 ;
F_9 ( V_24 , V_24 -> V_28 , & V_29 , V_27 , 1 ) ;
F_10 ( & V_29 , & V_13 , & V_13 ,
V_30 | V_31 ) ;
if ( V_24 -> V_32 ) {
F_9 ( V_24 , V_24 -> V_32 ,
& V_29 , V_27 , 1 ) ;
F_10 ( & V_29 , & V_13 , & V_13 ,
V_30 | V_31 ) ;
}
}
F_5 ( V_1 , V_2 , & V_13 , 0 ) ;
} else {
F_5 ( V_1 , V_2 , NULL ,
V_40 [ V_41 - V_43 ] ) ;
if ( V_41 >= V_44 ) {
F_3 ( V_6 , 0x4b , & V_42 ) ;
V_42 |= 1 ;
F_4 ( V_6 , 0x4b , V_42 ) ;
}
}
}
static int F_13 ( T_2 * V_2 , struct V_45 * V_46 )
{
if ( V_35 < 0xC2 && V_2 -> V_33 != V_34 ) {
if ( V_46 -> V_47 & V_48 )
return 1 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_6 )
{
unsigned long V_49 ;
T_3 V_42 ;
struct V_4 * V_50 = F_15 ( V_6 -> V_51 , F_16 ( 0 , 0 ) ) ;
V_35 = V_6 -> V_52 ;
V_53 = F_17 ( V_54 , V_55 , NULL ) ;
F_18 ( V_49 ) ;
if ( V_35 < 0xC2 ) {
F_3 ( V_6 , 0x4b , & V_42 ) ;
F_4 ( V_6 , 0x4b , V_42 & 0x7F ) ;
if ( V_35 >= 0x20 && V_53 ) {
F_3 ( V_53 , 0x5e , & V_42 ) ;
V_36 = ( ( V_42 & 0x1e ) == 0x12 ) ? 1 : 0 ;
}
goto V_56;
}
F_3 ( V_6 , 0x4b , & V_42 ) ;
F_4 ( V_6 , 0x4b , V_42 | 0x08 ) ;
if ( V_50 && V_50 -> V_57 != V_54 )
goto V_56;
if ( V_35 < 0xC5 && V_53 )
{
F_3 ( V_53 , 0x79 , & V_42 ) ;
if ( V_35 == 0xC2 ) {
F_4 ( V_53 , 0x79 , V_42 | 0x04 ) ;
} else if ( V_35 >= 0xC3 ) {
F_4 ( V_53 , 0x79 , V_42 | 0x02 ) ;
}
}
V_56:
if ( V_35 >= 0x20 ) {
F_3 ( V_6 , 0x53 , & V_42 ) ;
if ( V_35 <= 0x20 )
V_42 = ( V_42 & ( ~ 0x02 ) ) | 0x01 ;
else if ( V_35 == 0xc7 || V_35 == 0xc8 )
V_42 |= 0x03 ;
else
V_42 |= 0x01 ;
F_4 ( V_6 , 0x53 , V_42 ) ;
}
F_19 ( V_50 ) ;
F_19 ( V_53 ) ;
F_20 ( V_49 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
if ( V_5 -> V_58 == 0x10CF &&
V_5 -> V_59 == 0x10AF )
return 1 ;
if ( V_5 -> V_58 == 0x1071 &&
V_5 -> V_59 == 0x8317 )
return 1 ;
if ( F_22 ( V_60 ) )
return 1 ;
return 0 ;
}
static T_3 F_23 ( T_1 * V_1 )
{
struct V_4 * V_6 = F_2 ( V_1 -> V_6 ) ;
T_3 V_61 = V_62 , V_42 ;
if ( V_35 >= 0xC2 ) {
if ( F_21 ( V_6 ) )
V_61 = V_63 ;
else {
F_3 ( V_6 , 0x4a , & V_42 ) ;
if ( ( V_42 & ( 1 << V_1 -> V_8 ) ) == 0 )
V_61 = V_64 ;
}
}
return V_61 ;
}
static void T_4 F_24 ( T_1 * V_1 )
{
T_3 V_65 , V_66 ;
T_5 V_67 [] = { - 1 , 9 , 3 , 10 , 4 , 5 , 7 , 6 ,
1 , 11 , 0 , 12 , 0 , 14 , 0 , 15 } ;
int V_68 = - 1 ;
if ( V_53 ) {
F_3 ( V_53 , 0x58 , & V_65 ) ;
V_65 = V_65 & 0x03 ;
if ( ( V_1 -> V_8 && V_65 == 0x03 ) ||
( ! V_1 -> V_8 && ! V_65 ) ) {
F_3 ( V_53 , 0x44 , & V_66 ) ;
V_66 = V_66 & 0x0f ;
V_68 = V_67 [ V_66 ] ;
} else if ( V_1 -> V_8 && ! ( V_65 & 0x01 ) ) {
F_3 ( V_53 , 0x75 , & V_66 ) ;
V_66 = V_66 & 0x0f ;
V_68 = V_67 [ V_66 ] ;
}
if( V_68 >= 0 )
V_1 -> V_68 = V_68 ;
}
}
static int T_4 F_25 ( T_1 * V_1 ,
const struct V_69 * V_70 )
{
struct V_4 * V_6 = F_2 ( V_1 -> V_6 ) ;
unsigned long V_71 = F_26 ( V_1 , V_70 ) ;
if ( V_71 == 0 )
return - 1 ;
V_1 -> V_72 = V_71 ;
if ( F_27 ( V_1 , V_70 ) < 0 )
return - 1 ;
if ( F_28 ( V_6 , V_70 -> V_73 ) < 0 )
return - 1 ;
if ( ! V_1 -> V_8 )
F_29 ( F_30 ( V_71 + 2 ) & 0x60 , V_71 + 2 ) ;
F_31 ( V_74 L_2 ,
V_1 -> V_73 , V_71 , V_71 + 7 ) ;
if ( F_32 ( V_1 ) )
return - 1 ;
return 0 ;
}
static int T_4 F_33 ( struct V_4 * V_6 , const struct V_75 * V_37 )
{
struct V_69 V_70 = V_76 ;
T_3 V_77 = V_6 -> V_52 , V_78 = V_37 -> V_79 ;
if ( V_77 <= 0xC4 )
V_70 . V_80 |= V_81 ;
if ( V_77 >= 0x20 ) {
if ( V_77 == 0x20 )
V_70 . V_80 |= V_82 ;
if ( V_77 < 0xC2 )
V_70 . V_83 = V_84 ;
else if ( V_77 == 0xC2 || V_77 == 0xC3 )
V_70 . V_83 = V_85 ;
else if ( V_77 == 0xC4 )
V_70 . V_83 = V_86 ;
else
V_70 . V_83 = V_87 ;
V_70 . V_88 = & V_89 ;
} else {
V_70 . V_80 |= V_90 ;
V_70 . V_91 = V_70 . V_92 = 0 ;
}
if ( V_78 == 0 )
V_70 . V_80 |= V_93 ;
return F_34 ( V_6 , & V_70 , NULL ) ;
}
static int T_6 F_35 ( void )
{
return F_36 ( & V_94 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_94 ) ;
}
