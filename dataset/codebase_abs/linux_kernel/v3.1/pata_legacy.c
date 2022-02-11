static int F_1 ( unsigned long V_1 , unsigned int V_2 ,
enum V_3 type , unsigned long V_4 )
{
struct V_5 * V_6 = & V_7 [ 0 ] ;
int V_8 ;
struct V_5 * free = NULL ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( V_6 -> V_1 == 0 && free == NULL )
free = V_6 ;
if ( V_6 -> V_1 == V_1 || V_10 [ V_8 ] == V_1 ) {
free = V_6 ;
break;
}
V_6 ++ ;
}
if ( free == NULL ) {
F_2 ( V_11 L_1 ) ;
return - 1 ;
}
free -> V_1 = V_1 ;
free -> V_2 = V_2 ;
free -> type = type ;
free -> V_4 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_12 * V_13 , struct V_14 * * V_15 )
{
struct V_14 * V_16 ;
F_4 (dev, link, ENABLED) {
F_5 ( V_16 , L_2 ) ;
V_16 -> V_17 = V_18 ;
V_16 -> V_19 = V_18 ;
V_16 -> V_20 = V_21 ;
V_16 -> V_22 |= V_23 ;
}
return 0 ;
}
static void F_6 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
int V_27 = 5 ;
int V_28 = V_26 -> V_17 - V_18 ;
T_1 V_29 ;
unsigned long V_22 ;
F_7 ( V_22 ) ;
do {
F_8 ( 0x1F5 ) ;
F_9 ( F_8 ( 0x1F2 ) | 0x80 , 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x3F6 ) ;
F_8 ( 0x3F6 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
}
while ( ( F_8 ( 0x1F2 ) & 0x80 ) && -- V_27 );
F_10 ( V_22 ) ;
F_9 ( F_8 ( 0x1F4 ) & 0x07 , 0x1F4 ) ;
V_29 = F_8 ( 0x1F3 ) ;
V_29 &= 0x07 << ( 3 * V_26 -> V_30 ) ;
if ( V_28 )
V_29 |= ( 1 + 3 * V_28 ) << ( 3 * V_26 -> V_30 ) ;
F_11 ( 100 ) ;
F_9 ( F_8 ( 0x1F2 ) | 0x01 , 0x1F2 ) ;
F_11 ( 100 ) ;
F_8 ( 0x1F5 ) ;
}
static unsigned int F_12 ( struct V_14 * V_16 ,
unsigned char * V_31 , unsigned int V_32 , int V_33 )
{
int V_34 = V_32 & 3 ;
struct V_24 * V_25 = V_16 -> V_13 -> V_25 ;
if ( F_13 ( V_16 -> V_35 ) && ( V_34 == 0 || V_34 == 3 )
&& ( V_25 -> V_36 & V_37 ) ) {
unsigned long V_22 ;
F_7 ( V_22 ) ;
F_14 ( V_25 -> V_38 . V_39 ) ;
F_14 ( V_25 -> V_38 . V_39 ) ;
F_14 ( V_25 -> V_38 . V_39 ) ;
if ( V_33 == V_40 )
F_15 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
else
F_16 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
if ( F_17 ( V_34 ) ) {
T_2 V_42 ;
if ( V_33 == V_40 ) {
V_42 = F_18 ( F_19 ( V_25 -> V_38 . V_41 ) ) ;
memcpy ( V_31 + V_32 - V_34 , & V_42 , V_34 ) ;
} else {
memcpy ( & V_42 , V_31 + V_32 - V_34 , V_34 ) ;
F_20 ( F_21 ( V_42 ) , V_25 -> V_38 . V_41 ) ;
}
V_32 += 4 - V_34 ;
}
F_10 ( V_22 ) ;
} else
V_32 = F_22 ( V_16 , V_31 , V_32 , V_33 ) ;
return V_32 ;
}
static void F_23 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
T_1 V_43 , V_44 ;
struct V_45 V_46 ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 20000 , 1000 ) ;
V_43 = F_25 ( V_46 . V_43 , 2 , 15 ) ;
V_44 = F_25 ( V_46 . V_44 , 4 , 15 ) ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_26 ( V_44 << 4 | V_43 , V_25 -> V_38 . V_47 ) ;
F_14 ( V_25 -> V_38 . V_48 ) ;
}
static void F_27 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
T_1 V_43 , V_44 ;
struct V_45 V_46 ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 20000 , 1000 ) ;
V_43 = F_25 ( V_46 . V_43 , 2 , 15 ) ;
V_44 = F_25 ( V_46 . V_44 , 2 , 16 ) ;
V_44 &= 0x15 ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_8 ( 0x3E6 ) ;
F_26 ( V_44 << 4 | V_43 , V_25 -> V_38 . V_47 ) ;
if ( V_26 -> V_49 != V_50 ) {
T_1 V_51 = F_8 ( 0x3E6 ) ;
if ( V_51 & 0x24 ) {
V_51 &= ~ 0x24 ;
F_9 ( V_51 , 0x3E6 ) ;
}
}
F_14 ( V_25 -> V_38 . V_48 ) ;
}
static T_1 F_28 ( T_1 V_52 )
{
unsigned long V_22 ;
T_1 V_53 ;
F_7 ( V_22 ) ;
F_9 ( V_52 , 0x22 ) ;
V_53 = F_8 ( 0x24 ) ;
F_10 ( V_22 ) ;
return V_53 ;
}
static void F_29 ( struct V_24 * V_25 ,
struct V_14 * V_26 )
{
T_1 V_43 , V_44 , V_54 ;
struct V_45 V_46 ;
struct V_14 * V_55 = F_30 ( V_26 ) ;
int clock ;
int V_56 [ 4 ] = { 50000 , 40000 , 33000 , 25000 } ;
T_1 V_57 ;
F_31 ( V_25 -> V_38 . V_58 ) ;
F_31 ( V_25 -> V_38 . V_58 ) ;
F_26 ( 3 , V_25 -> V_38 . V_39 ) ;
clock = 1000000000 / V_56 [ F_14 ( V_25 -> V_38 . V_59 ) & 0x03 ] ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , clock , 1000 ) ;
if ( V_55 ) {
struct V_45 V_60 ;
F_24 ( V_55 , V_55 -> V_17 , & V_60 , clock , 1000 ) ;
F_32 ( & V_46 , & V_60 , & V_46 , V_61 ) ;
}
V_43 = F_25 ( V_46 . V_43 , 2 , 17 ) - 2 ;
V_44 = F_25 ( V_46 . V_44 , 1 , 16 ) - 1 ;
V_54 = F_25 ( V_46 . V_54 , 1 , 4 ) - 1 ;
V_57 = F_14 ( V_25 -> V_38 . V_62 ) ;
V_57 &= 0x7F ;
V_57 |= ( V_26 -> V_30 << 7 ) ;
F_26 ( V_57 , V_25 -> V_38 . V_62 ) ;
F_26 ( V_43 << 4 | V_44 , V_25 -> V_38 . V_58 ) ;
V_57 = F_14 ( V_25 -> V_38 . V_47 ) ;
V_57 &= 0xC0 ;
V_57 |= V_26 -> V_30 ;
V_57 |= ( V_54 << 4 ) | 0x04 ;
F_26 ( V_57 , V_25 -> V_38 . V_47 ) ;
F_26 ( V_43 << 4 | V_44 , V_25 -> V_38 . V_41 ) ;
V_57 = F_14 ( V_25 -> V_38 . V_62 ) ;
V_57 &= 0x73 ;
V_57 |= 0x84 ;
F_26 ( V_57 , V_25 -> V_38 . V_62 ) ;
F_26 ( 0x83 , V_25 -> V_38 . V_39 ) ;
}
static void F_33 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
T_1 V_43 , V_44 , V_54 ;
struct V_45 V_46 ;
struct V_14 * V_55 = F_30 ( V_26 ) ;
int clock ;
int V_56 [ 4 ] = { 50000 , 40000 , 33000 , 25000 } ;
T_1 V_57 ;
T_1 V_63 ;
V_63 = F_28 ( 0xAC ) & 0xC0 ;
F_31 ( V_25 -> V_38 . V_58 ) ;
F_31 ( V_25 -> V_38 . V_58 ) ;
F_26 ( 3 , V_25 -> V_38 . V_39 ) ;
clock = 1000000000 / V_56 [ V_63 ] ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , clock , 1000 ) ;
if ( V_55 ) {
struct V_45 V_60 ;
F_24 ( V_55 , V_55 -> V_17 , & V_60 , clock , 1000 ) ;
F_32 ( & V_46 , & V_60 , & V_46 , V_61 ) ;
}
V_43 = F_25 ( V_46 . V_43 , 2 , 17 ) - 2 ;
V_44 = F_25 ( V_46 . V_44 , 1 , 16 ) - 1 ;
V_54 = F_25 ( V_46 . V_54 , 1 , 4 ) - 1 ;
V_57 = F_14 ( V_25 -> V_38 . V_62 ) ;
V_57 &= 0x7F ;
V_57 |= ( V_26 -> V_30 << 7 ) ;
F_26 ( V_57 , V_25 -> V_38 . V_62 ) ;
F_26 ( V_43 << 4 | V_44 , V_25 -> V_38 . V_58 ) ;
V_57 = F_14 ( V_25 -> V_38 . V_47 ) ;
V_57 &= 0xC0 ;
V_57 |= V_26 -> V_30 ;
V_57 |= ( V_54 << 4 ) | 0x04 ;
F_26 ( V_57 , V_25 -> V_38 . V_47 ) ;
F_26 ( V_43 << 4 | V_44 , V_25 -> V_38 . V_41 ) ;
V_57 = F_14 ( V_25 -> V_38 . V_62 ) ;
V_57 &= 0x73 ;
V_57 |= 0x84 ;
F_26 ( V_57 , V_25 -> V_38 . V_62 ) ;
F_26 ( 0x83 , V_25 -> V_38 . V_39 ) ;
V_25 -> V_64 -> V_65 = V_25 ;
}
static unsigned int F_34 ( struct V_66 * V_67 )
{
struct V_24 * V_25 = V_67 -> V_25 ;
struct V_14 * V_26 = V_67 -> V_16 ;
if ( V_25 -> V_64 -> V_65 != V_25 -> V_64
&& V_25 -> V_64 -> V_65 != NULL )
F_33 ( V_25 , V_26 ) ;
return F_35 ( V_67 ) ;
}
static void F_36 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
struct V_45 V_46 ;
struct V_68 * V_69 = V_25 -> V_64 -> V_65 ;
int V_43 , V_70 ;
T_1 V_71 ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 30303 , 1000 ) ;
if ( V_69 -> V_72 ) {
V_43 = 8 - F_25 ( V_46 . V_43 , 1 , 8 ) ;
V_70 = 18 - F_25 ( V_46 . V_44 , 3 , 18 ) ;
} else {
V_43 = 9 - F_25 ( V_46 . V_43 , 2 , 9 ) ;
V_70 = 15 - F_25 ( V_46 . V_44 , 0 , 15 ) ;
}
V_71 = ( V_70 << 4 ) | V_43 | 0x08 ;
V_69 -> clock [ V_26 -> V_30 ] = V_71 ;
F_9 ( V_71 , V_69 -> V_71 ) ;
}
static void F_37 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
struct V_45 V_46 ;
struct V_68 * V_69 = V_25 -> V_64 -> V_65 ;
int V_43 , V_70 ;
T_1 V_71 ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 30303 , 1000 ) ;
if ( V_69 -> V_72 ) {
V_43 = 8 - F_25 ( V_46 . V_43 , 1 , 8 ) ;
V_70 = 18 - F_25 ( V_46 . V_44 , 3 , 18 ) ;
} else {
V_43 = 9 - F_25 ( V_46 . V_43 , 2 , 9 ) ;
V_70 = 15 - F_25 ( V_46 . V_44 , 0 , 15 ) ;
}
V_71 = ( V_70 << 4 ) | V_43 | 0x08 ;
V_69 -> clock [ V_26 -> V_30 ] = V_71 ;
F_9 ( V_71 , V_69 -> V_71 + 2 * V_25 -> V_73 ) ;
if ( V_26 -> V_49 != V_50 )
F_9 ( 0x5F , ( V_69 -> V_71 & 0xFFF0 ) + 3 ) ;
}
static void F_38 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
struct V_45 V_46 ;
struct V_68 * V_69 = V_25 -> V_64 -> V_65 ;
int V_43 , V_70 ;
T_1 V_71 ;
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 30303 , 1000 ) ;
if ( V_69 -> V_72 ) {
V_43 = 8 - F_25 ( V_46 . V_43 , 1 , 8 ) ;
V_70 = 18 - F_25 ( V_46 . V_44 , 3 , 18 ) ;
} else {
V_43 = 9 - F_25 ( V_46 . V_43 , 2 , 9 ) ;
V_70 = 15 - F_25 ( V_46 . V_44 , 0 , 15 ) ;
}
V_71 = ( V_70 << 4 ) | V_43 | 0x08 ;
V_69 -> clock [ V_26 -> V_30 ] = V_71 ;
F_9 ( V_71 , V_69 -> V_71 + 2 * V_26 -> V_30 ) ;
if ( V_26 -> V_49 != V_50 )
F_9 ( 0x5F , ( V_69 -> V_71 & 0xFFF0 ) + 3 ) ;
}
static unsigned int F_39 ( struct V_66 * V_67 )
{
struct V_24 * V_25 = V_67 -> V_25 ;
struct V_14 * V_26 = V_67 -> V_16 ;
struct V_68 * V_69 = V_25 -> V_64 -> V_65 ;
if ( V_69 -> clock [ V_26 -> V_30 ] != V_69 -> V_74 ) {
if ( V_26 -> V_17 ) {
V_69 -> V_74 = V_69 -> clock [ V_26 -> V_30 ] ;
F_9 ( V_69 -> clock [ V_26 -> V_30 ] , V_69 -> V_71 +
2 * V_25 -> V_73 ) ;
}
}
return F_35 ( V_67 ) ;
}
static unsigned int F_40 ( struct V_14 * V_26 , unsigned char * V_31 ,
unsigned int V_32 , int V_33 )
{
struct V_24 * V_25 = V_26 -> V_13 -> V_25 ;
int V_34 = V_32 & 3 ;
if ( F_13 ( V_26 -> V_35 ) && ( V_34 == 0 || V_34 == 3 )
&& ( V_25 -> V_36 & V_37 ) ) {
if ( V_33 == V_75 )
F_16 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
else
F_15 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
if ( F_17 ( V_34 ) ) {
T_2 V_42 ;
if ( V_33 == V_75 ) {
memcpy ( & V_42 , V_31 + V_32 - V_34 , V_34 ) ;
F_20 ( F_21 ( V_42 ) , V_25 -> V_38 . V_41 ) ;
} else {
V_42 = F_18 ( F_19 ( V_25 -> V_38 . V_41 ) ) ;
memcpy ( V_31 + V_32 - V_34 , & V_42 , V_34 ) ;
}
}
return ( V_32 + 3 ) & ~ 3 ;
} else
return F_41 ( V_26 , V_31 , V_32 , V_33 ) ;
}
static int F_42 ( struct V_76 * V_16 ,
struct V_5 * V_6 , struct V_68 * V_77 )
{
if ( F_43 ( & V_16 -> V_16 , V_6 -> V_4 , 4 , L_3 ) == NULL )
return - V_78 ;
V_77 -> V_71 = V_6 -> V_4 ;
return 0 ;
}
static void F_44 ( unsigned long V_1 , T_1 V_52 , T_1 V_79 )
{
unsigned long V_22 ;
F_45 ( & V_80 , V_22 ) ;
F_9 ( V_52 , V_1 + 0x01 ) ;
F_9 ( V_79 , V_1 + 0x02 ) ;
F_46 ( & V_80 , V_22 ) ;
}
static T_1 F_47 ( unsigned long V_1 , T_1 V_52 )
{
T_1 V_79 ;
unsigned long V_22 ;
F_45 ( & V_80 , V_22 ) ;
F_9 ( V_52 , V_1 + 0x01 ) ;
V_79 = F_8 ( V_1 + 0x02 ) ;
F_46 ( & V_80 , V_22 ) ;
return V_79 ;
}
static void F_48 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
struct V_45 V_46 ;
struct V_68 * V_81 = V_25 -> V_64 -> V_65 ;
int V_43 , V_70 ;
T_1 V_52 ;
int V_71 = 0x88 + ( V_25 -> V_73 * 4 ) + ( V_26 -> V_30 * 2 ) ;
V_52 = F_47 ( V_81 -> V_71 , 0x81 ) ;
if ( V_52 & 0x40 )
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 20000 , 1000 ) ;
else
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 30303 , 1000 ) ;
V_43 = ( F_25 ( V_46 . V_43 , 3 , 17 ) - 1 ) & 0x0F ;
V_70 = ( F_25 ( V_46 . V_44 , 1 , 15 ) + 1 ) & 0x0F ;
V_71 = ( V_43 << 4 ) | V_70 ;
F_44 ( V_81 -> V_71 , V_71 , V_52 ) ;
V_52 = 0x35 ;
if ( V_26 -> V_49 != V_50 )
V_52 |= 0x08 ;
if ( ! F_49 ( V_26 ) )
V_52 |= 0x02 ;
V_52 |= ( F_25 ( V_46 . V_54 , 0 , 3 ) << 6 ) ;
F_44 ( V_81 -> V_71 , V_71 + 1 , V_52 ) ;
}
static int F_50 ( struct V_76 * V_16 ,
struct V_5 * V_6 , struct V_68 * V_77 )
{
if ( F_43 ( & V_16 -> V_16 , V_6 -> V_4 , 4 , L_4 ) == NULL )
return - V_78 ;
V_77 -> V_71 = V_6 -> V_4 ;
return 0 ;
}
static T_3 int F_51 ( struct V_5 * V_82 )
{
int V_83 = 1 << V_82 -> V_84 ;
if ( V_85 && ( V_82 -> V_1 == 0x1F0 || V_82 -> V_1 == 0x170 ) ) {
T_1 V_52 = F_47 ( V_85 , 0x81 ) ;
V_52 |= 0x80 ;
F_44 ( V_85 , 0x81 , V_52 ) ;
V_52 = F_47 ( V_85 , 0x83 ) ;
V_52 |= 0xF0 ;
F_44 ( V_85 , 0x83 , V_52 ) ;
V_52 = F_47 ( V_85 , 0x85 ) ;
V_52 |= 0xF0 ;
F_44 ( V_85 , 0x85 , V_52 ) ;
V_52 = F_47 ( V_85 , 0x81 ) ;
if ( V_52 & V_83 )
return V_86 ;
}
if ( V_82 -> V_1 == 0x1F0 ) {
unsigned long V_22 ;
F_7 ( V_22 ) ;
F_9 ( F_8 ( 0x1F2 ) | 0x80 , 0x1F2 ) ;
F_8 ( 0x1F5 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x3F6 ) ;
F_8 ( 0x3F6 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
if ( ( F_8 ( 0x1F2 ) & 0x80 ) == 0 ) {
F_2 ( V_87 L_5
L_6 ) ;
F_11 ( 100 ) ;
F_8 ( 0x1F5 ) ;
F_10 ( V_22 ) ;
return V_88 ;
} else {
F_9 ( 0x55 , 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
if ( F_8 ( 0x1F2 ) == 0x00 )
F_2 ( V_87 L_7
L_8 ) ;
F_10 ( V_22 ) ;
return V_89 ;
}
F_10 ( V_22 ) ;
}
if ( V_90 & V_83 )
return V_91 ;
if ( V_92 & V_83 )
return V_93 ;
if ( V_94 & V_83 )
return V_95 ;
if ( V_96 & V_83 )
return V_97 ;
if ( V_98 & V_83 )
return V_99 ;
return V_89 ;
}
static T_3 int F_52 ( struct V_5 * V_82 )
{
struct V_100 * V_3 = & V_101 [ V_82 -> type ] ;
int V_102 = V_3 -> V_103 ;
unsigned long V_104 = V_82 -> V_1 ;
T_4 V_83 = ( 1 << V_82 -> V_84 ) ;
struct V_105 * V_106 = V_3 -> V_106 ;
struct V_68 * V_77 = & V_68 [ V_82 -> V_84 ] ;
struct V_107 * V_64 = NULL ;
struct V_24 * V_25 ;
struct V_76 * V_108 ;
struct V_14 * V_16 ;
void T_5 * V_109 , * V_110 ;
T_4 V_111 = ( V_112 & V_83 ) ? 0 : V_113 ;
int V_114 ;
V_111 |= V_3 -> V_22 ;
V_108 = F_53 ( V_115 , V_82 -> V_84 , NULL , 0 ) ;
if ( F_54 ( V_108 ) )
return F_55 ( V_108 ) ;
V_114 = - V_78 ;
if ( F_43 ( & V_108 -> V_16 , V_104 , 8 , L_9 ) == NULL ||
F_43 ( & V_108 -> V_16 , V_104 + 0x0206 , 1 ,
L_9 ) == NULL )
goto V_116;
V_114 = - V_117 ;
V_109 = F_56 ( & V_108 -> V_16 , V_104 , 8 ) ;
V_110 = F_56 ( & V_108 -> V_16 , V_104 + 0x0206 , 1 ) ;
if ( ! V_109 || ! V_110 )
goto V_116;
if ( V_3 -> V_54 )
if ( V_3 -> V_54 ( V_108 , V_82 , V_77 ) < 0 )
goto V_116;
V_64 = F_57 ( & V_108 -> V_16 , 1 ) ;
if ( ! V_64 )
goto V_116;
V_25 = V_64 -> V_118 [ 0 ] ;
V_25 -> V_106 = V_106 ;
V_25 -> V_103 = V_102 ;
V_25 -> V_22 |= V_119 | V_111 ;
V_25 -> V_36 |= V_3 -> V_36 ;
V_25 -> V_38 . V_120 = V_109 ;
V_25 -> V_38 . V_121 = V_110 ;
V_25 -> V_38 . V_122 = V_110 ;
F_58 ( & V_25 -> V_38 ) ;
V_25 -> V_64 -> V_65 = V_77 ;
F_59 ( V_25 , L_10 , V_104 , V_104 + 0x0206 ) ;
V_114 = F_60 ( V_64 , V_82 -> V_2 , V_123 , 0 ,
& V_124 ) ;
if ( V_114 )
goto V_116;
F_61 () ;
V_77 -> V_125 = V_108 ;
V_114 = - V_126 ;
F_4 (dev, &ap->link, ALL) {
if ( ! F_62 ( V_16 ) ) {
V_127 [ V_82 -> V_84 ] = V_64 ;
V_77 -> V_125 = V_108 ;
return 0 ;
}
}
F_63 ( V_64 ) ;
V_116:
F_64 ( V_108 ) ;
return V_114 ;
}
static void T_3 F_65 ( struct V_128 * V_129 , int * V_130 ,
int * V_131 )
{
if ( V_129 -> V_132 == 0x1078 && V_129 -> V_133 == 0x0000 ) {
* V_130 = * V_131 = 1 ;
return;
}
if ( V_129 -> V_132 == 0x1078 && V_129 -> V_133 == 0x0002 ) {
* V_130 = * V_131 = 1 ;
return;
}
if ( V_129 -> V_132 == 0x8086 && V_129 -> V_133 == 0x1234 ) {
T_6 V_53 ;
F_66 ( V_129 , 0x6C , & V_53 ) ;
if ( V_53 & 0x8000 ) {
if ( V_53 & 0x4000 )
* V_131 = 1 ;
else
* V_130 = 1 ;
}
return;
}
}
static T_3 void F_67 ( void )
{
static const char * V_134 [ 4 ] = {
L_11 , L_12 ,
L_13 , L_14
} ;
T_1 V_135 = 1 ;
T_1 V_136 = ( F_28 ( 0x30 ) & 0xC0 ) >> 6 ;
V_96 = 3 ;
F_2 (KERN_INFO DRV_NAME L_15 ,
optis[ctrl]) ;
if ( V_136 == 3 )
V_135 = ( F_28 ( 0x3F ) & 0x20 ) ? 2 : 1 ;
V_136 = F_28 ( 0xAC ) ;
if ( V_136 & 8 ) {
if ( V_135 == 2 ) {
F_1 ( 0x1F0 , 14 , V_97 , 0 ) ;
F_1 ( 0x170 , 15 , V_97 , 0 ) ;
}
if ( V_136 & 4 )
F_1 ( 0x170 , 15 , V_97 , 0 ) ;
else
F_1 ( 0x1F0 , 14 , V_97 , 0 ) ;
} else
F_1 ( 0x1F0 , 14 , V_97 , 0 ) ;
}
static T_3 void F_68 ( T_1 V_53 , T_1 V_137 , unsigned long V_1 )
{
static const unsigned long V_138 [ 2 ] = { 0x170 , 0x1F0 } ;
if ( ( V_53 & 0xF0 ) == 0xC0 ) {
if ( V_53 & 8 )
return;
F_1 ( V_138 [ V_53 & 0x01 ] , 14 + ( V_53 & 0x01 ) ,
V_139 , V_1 ) ;
}
if ( ( ( V_53 & 0xF0 ) == 0xA0 ) || ( V_53 & 0xF0 ) == 0x50 ) {
if ( ! F_69 ( V_1 + 2 , 2 , L_16 ) ) {
F_70 ( V_1 , 2 ) ;
return;
}
V_137 = F_8 ( V_1 + 3 ) ;
if ( V_137 & 1 )
F_1 ( V_138 [ V_53 & 0x01 ] , 14 + ( V_53 & 0x01 ) ,
V_140 , V_1 ) ;
else {
F_1 ( 0x1F0 , 14 , V_141 , V_1 ) ;
F_1 ( 0x170 , 15 , V_141 , V_1 + 2 ) ;
}
F_70 ( V_1 + 2 , 2 ) ;
}
}
static T_3 void F_71 ( void )
{
unsigned long V_22 ;
static const unsigned long V_142 [ 2 ] = { 0x30 , 0xB0 } ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
unsigned long V_1 = V_142 [ V_8 ] ;
T_1 V_53 , V_137 ;
if ( F_69 ( V_1 , 2 , L_16 ) ) {
F_7 ( V_22 ) ;
V_53 = F_8 ( V_1 ) ;
F_11 ( 1 ) ;
F_9 ( 0x19 , V_1 ) ;
F_11 ( 1 ) ;
V_137 = F_8 ( V_1 ) ;
F_11 ( 1 ) ;
F_9 ( V_53 , V_1 ) ;
F_11 ( 1 ) ;
F_10 ( V_22 ) ;
if ( V_137 == 0x19 ) {
F_70 ( V_1 , 2 ) ;
continue;
}
V_53 = F_8 ( V_1 + 1 ) ;
F_11 ( 1 ) ;
if ( ( V_53 & 2 ) >> 1 == V_8 )
F_68 ( V_53 , V_137 , V_1 ) ;
F_70 ( V_1 , 2 ) ;
}
}
}
static T_3 int F_72 ( void )
{
int V_8 ;
int V_143 = 0 ;
int V_130 = 0 ;
int V_131 = 0 ;
int V_144 = 0 ;
struct V_5 * V_145 = & V_7 [ 0 ] ;
int V_84 = 0 ;
struct V_128 * V_129 = NULL ;
F_73 (p) {
int V_53 ;
for ( V_53 = 0 ; V_53 < 6 ; V_53 ++ ) {
if ( F_74 ( V_129 , V_53 ) == 0x1f0 )
V_130 = 1 ;
if ( F_74 ( V_129 , V_53 ) == 0x170 )
V_131 = 1 ;
}
F_65 ( V_129 , & V_130 , & V_131 ) ;
V_144 = 1 ;
}
if ( V_85 == 1 )
V_85 = 0x130 ;
if ( V_130 == 0 || V_146 )
F_1 ( 0x1F0 , 14 , V_147 , 0 ) ;
if ( V_131 == 0 || V_146 )
F_1 ( 0x170 , 15 , V_147 , 0 ) ;
if ( V_148 || ! V_144 ) {
F_1 ( 0x1E8 , 11 , V_147 , 0 ) ;
F_1 ( 0x168 , 10 , V_147 , 0 ) ;
F_1 ( 0x1E0 , 8 , V_147 , 0 ) ;
F_1 ( 0x160 , 12 , V_147 , 0 ) ;
}
if ( V_96 )
F_67 () ;
if ( V_149 )
F_71 () ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ , V_145 ++ ) {
if ( V_145 -> V_1 == 0 )
continue;
if ( V_145 -> type == V_147 )
V_145 -> type = F_51 ( V_145 ) ;
V_145 -> V_84 = V_84 ++ ;
if ( F_52 ( V_145 ) == 0 )
V_143 ++ ;
}
if ( V_143 != 0 )
return 0 ;
return - V_126 ;
}
static T_7 void F_75 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_150 ; V_8 ++ ) {
struct V_68 * V_77 = & V_68 [ V_8 ] ;
F_63 ( V_127 [ V_8 ] ) ;
F_64 ( V_77 -> V_125 ) ;
}
}
