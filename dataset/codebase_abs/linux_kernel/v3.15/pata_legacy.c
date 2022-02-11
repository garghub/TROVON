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
V_44 = F_25 ( V_46 . V_44 , 2 , 16 ) & 0x0F ;
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
V_63 = ( F_28 ( 0xAC ) & 0xC0 ) >> 6 ;
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
if ( V_69 -> type == V_73 )
F_9 ( V_71 , V_69 -> V_71 + 2 * V_26 -> V_30 ) ;
else
F_9 ( V_71 , V_69 -> V_71 + 2 * V_25 -> V_74 ) ;
if ( V_69 -> type != V_75 && V_26 -> V_49 != V_50 )
F_9 ( 0x5F , ( V_69 -> V_71 & 0xFFF0 ) + 3 ) ;
}
static unsigned int F_37 ( struct V_66 * V_67 )
{
struct V_24 * V_25 = V_67 -> V_25 ;
struct V_14 * V_26 = V_67 -> V_16 ;
struct V_68 * V_69 = V_25 -> V_64 -> V_65 ;
if ( V_69 -> clock [ V_26 -> V_30 ] != V_69 -> V_76 ) {
if ( V_26 -> V_17 ) {
V_69 -> V_76 = V_69 -> clock [ V_26 -> V_30 ] ;
F_9 ( V_69 -> clock [ V_26 -> V_30 ] , V_69 -> V_71 +
2 * V_25 -> V_74 ) ;
}
}
return F_35 ( V_67 ) ;
}
static unsigned int F_38 ( struct V_14 * V_26 , unsigned char * V_31 ,
unsigned int V_32 , int V_33 )
{
struct V_24 * V_25 = V_26 -> V_13 -> V_25 ;
int V_34 = V_32 & 3 ;
if ( F_13 ( V_26 -> V_35 ) && ( V_34 == 0 || V_34 == 3 )
&& ( V_25 -> V_36 & V_37 ) ) {
if ( V_33 == V_77 )
F_16 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
else
F_15 ( V_25 -> V_38 . V_41 , V_31 , V_32 >> 2 ) ;
if ( F_17 ( V_34 ) ) {
T_2 V_42 ;
if ( V_33 == V_77 ) {
memcpy ( & V_42 , V_31 + V_32 - V_34 , V_34 ) ;
F_20 ( F_21 ( V_42 ) , V_25 -> V_38 . V_41 ) ;
} else {
V_42 = F_18 ( F_19 ( V_25 -> V_38 . V_41 ) ) ;
memcpy ( V_31 + V_32 - V_34 , & V_42 , V_34 ) ;
}
}
return ( V_32 + 3 ) & ~ 3 ;
} else
return F_39 ( V_26 , V_31 , V_32 , V_33 ) ;
}
static int F_40 ( struct V_78 * V_16 ,
struct V_5 * V_6 , struct V_68 * V_79 )
{
if ( F_41 ( & V_16 -> V_16 , V_6 -> V_4 , 4 , L_3 ) == NULL )
return - V_80 ;
V_79 -> V_71 = V_6 -> V_4 ;
return 0 ;
}
static void F_42 ( unsigned long V_1 , T_1 V_52 , T_1 V_81 )
{
unsigned long V_22 ;
F_43 ( & V_82 , V_22 ) ;
F_9 ( V_52 , V_1 + 0x01 ) ;
F_9 ( V_81 , V_1 + 0x02 ) ;
F_44 ( & V_82 , V_22 ) ;
}
static T_1 F_45 ( unsigned long V_1 , T_1 V_52 )
{
T_1 V_81 ;
unsigned long V_22 ;
F_43 ( & V_82 , V_22 ) ;
F_9 ( V_52 , V_1 + 0x01 ) ;
V_81 = F_8 ( V_1 + 0x02 ) ;
F_44 ( & V_82 , V_22 ) ;
return V_81 ;
}
static void F_46 ( struct V_24 * V_25 , struct V_14 * V_26 )
{
struct V_45 V_46 ;
struct V_68 * V_83 = V_25 -> V_64 -> V_65 ;
int V_43 , V_70 ;
T_1 V_52 ;
int V_71 = 0x88 + ( V_25 -> V_74 * 4 ) + ( V_26 -> V_30 * 2 ) ;
V_52 = F_45 ( V_83 -> V_71 , 0x81 ) ;
if ( V_52 & 0x40 )
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 20000 , 1000 ) ;
else
F_24 ( V_26 , V_26 -> V_17 , & V_46 , 30303 , 1000 ) ;
V_43 = ( F_25 ( V_46 . V_43 , 3 , 17 ) - 1 ) & 0x0F ;
V_70 = ( F_25 ( V_46 . V_44 , 1 , 15 ) + 1 ) & 0x0F ;
V_71 = ( V_43 << 4 ) | V_70 ;
F_42 ( V_83 -> V_71 , V_71 , V_52 ) ;
V_52 = 0x35 ;
if ( V_26 -> V_49 != V_50 )
V_52 |= 0x08 ;
if ( ! F_47 ( V_26 ) )
V_52 |= 0x02 ;
V_52 |= ( F_25 ( V_46 . V_54 , 0 , 3 ) << 6 ) ;
F_42 ( V_83 -> V_71 , V_71 + 1 , V_52 ) ;
}
static int F_48 ( struct V_78 * V_16 ,
struct V_5 * V_6 , struct V_68 * V_79 )
{
if ( F_41 ( & V_16 -> V_16 , V_6 -> V_4 , 4 , L_4 ) == NULL )
return - V_80 ;
V_79 -> V_71 = V_6 -> V_4 ;
return 0 ;
}
static T_3 int F_49 ( struct V_5 * V_84 )
{
int V_85 = 1 << V_84 -> V_86 ;
if ( V_87 && ( V_84 -> V_1 == 0x1F0 || V_84 -> V_1 == 0x170 ) ) {
T_1 V_52 = F_45 ( V_87 , 0x81 ) ;
V_52 |= 0x80 ;
F_42 ( V_87 , 0x81 , V_52 ) ;
V_52 = F_45 ( V_87 , 0x83 ) ;
V_52 |= 0xF0 ;
F_42 ( V_87 , 0x83 , V_52 ) ;
V_52 = F_45 ( V_87 , 0x85 ) ;
V_52 |= 0xF0 ;
F_42 ( V_87 , 0x85 , V_52 ) ;
V_52 = F_45 ( V_87 , 0x81 ) ;
if ( V_52 & V_85 )
return V_88 ;
}
if ( V_84 -> V_1 == 0x1F0 ) {
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
F_2 ( V_89 L_5
L_6 ) ;
F_11 ( 100 ) ;
F_8 ( 0x1F5 ) ;
F_10 ( V_22 ) ;
return V_90 ;
} else {
F_9 ( 0x55 , 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
F_8 ( 0x1F2 ) ;
if ( F_8 ( 0x1F2 ) == 0x00 )
F_2 ( V_89 L_7
L_8 ) ;
F_10 ( V_22 ) ;
return V_91 ;
}
}
if ( V_92 & V_85 )
return V_93 ;
if ( V_94 & V_85 )
return V_95 ;
if ( V_96 & V_85 )
return V_97 ;
if ( V_98 & V_85 )
return V_99 ;
if ( V_100 & V_85 )
return V_101 ;
return V_91 ;
}
static T_3 int F_50 ( struct V_5 * V_84 )
{
struct V_102 * V_3 = & V_103 [ V_84 -> type ] ;
int V_104 = V_3 -> V_105 ;
unsigned long V_106 = V_84 -> V_1 ;
T_4 V_85 = ( 1 << V_84 -> V_86 ) ;
struct V_107 * V_108 = V_3 -> V_108 ;
struct V_68 * V_79 = & V_68 [ V_84 -> V_86 ] ;
struct V_109 * V_64 = NULL ;
struct V_24 * V_25 ;
struct V_78 * V_110 ;
struct V_14 * V_16 ;
void T_5 * V_111 , * V_112 ;
T_4 V_113 = ( V_114 & V_85 ) ? 0 : V_115 ;
int V_116 ;
V_113 |= V_3 -> V_22 ;
V_110 = F_51 ( V_117 , V_84 -> V_86 , NULL , 0 ) ;
if ( F_52 ( V_110 ) )
return F_53 ( V_110 ) ;
V_116 = - V_80 ;
if ( F_41 ( & V_110 -> V_16 , V_106 , 8 , L_9 ) == NULL ||
F_41 ( & V_110 -> V_16 , V_106 + 0x0206 , 1 ,
L_9 ) == NULL )
goto V_118;
V_116 = - V_119 ;
V_111 = F_54 ( & V_110 -> V_16 , V_106 , 8 ) ;
V_112 = F_54 ( & V_110 -> V_16 , V_106 + 0x0206 , 1 ) ;
if ( ! V_111 || ! V_112 )
goto V_118;
V_79 -> type = V_84 -> type ;
if ( V_3 -> V_54 )
if ( V_3 -> V_54 ( V_110 , V_84 , V_79 ) < 0 )
goto V_118;
V_64 = F_55 ( & V_110 -> V_16 , 1 ) ;
if ( ! V_64 )
goto V_118;
V_25 = V_64 -> V_120 [ 0 ] ;
V_25 -> V_108 = V_108 ;
V_25 -> V_105 = V_104 ;
V_25 -> V_22 |= V_121 | V_113 ;
V_25 -> V_36 |= V_3 -> V_36 ;
V_25 -> V_38 . V_122 = V_111 ;
V_25 -> V_38 . V_123 = V_112 ;
V_25 -> V_38 . V_124 = V_112 ;
F_56 ( & V_25 -> V_38 ) ;
V_25 -> V_64 -> V_65 = V_79 ;
F_57 ( V_25 , L_10 , V_106 , V_106 + 0x0206 ) ;
V_116 = F_58 ( V_64 , V_84 -> V_2 , V_125 , 0 ,
& V_126 ) ;
if ( V_116 )
goto V_118;
F_59 () ;
V_79 -> V_127 = V_110 ;
V_116 = - V_128 ;
F_4 (dev, &ap->link, ALL) {
if ( ! F_60 ( V_16 ) ) {
V_129 [ V_84 -> V_86 ] = V_64 ;
V_79 -> V_127 = V_110 ;
return 0 ;
}
}
F_61 ( V_64 ) ;
V_118:
F_62 ( V_110 ) ;
return V_116 ;
}
static void T_3 F_63 ( struct V_130 * V_131 , int * V_132 ,
int * V_133 )
{
if ( V_131 -> V_134 == 0x1078 && V_131 -> V_135 == 0x0000 ) {
* V_132 = * V_133 = 1 ;
return;
}
if ( V_131 -> V_134 == 0x1078 && V_131 -> V_135 == 0x0002 ) {
* V_132 = * V_133 = 1 ;
return;
}
if ( V_131 -> V_134 == 0x8086 && V_131 -> V_135 == 0x1234 ) {
T_6 V_53 ;
F_64 ( V_131 , 0x6C , & V_53 ) ;
if ( V_53 & 0x8000 ) {
if ( V_53 & 0x4000 )
* V_133 = 1 ;
else
* V_132 = 1 ;
}
return;
}
}
static T_3 void F_65 ( void )
{
static const char * V_136 [ 4 ] = {
L_11 , L_12 ,
L_13 , L_14
} ;
T_1 V_137 = 1 ;
T_1 V_138 = ( F_28 ( 0x30 ) & 0xC0 ) >> 6 ;
V_98 = 3 ;
F_2 (KERN_INFO DRV_NAME L_15 ,
optis[ctrl]) ;
if ( V_138 == 3 )
V_137 = ( F_28 ( 0x3F ) & 0x20 ) ? 2 : 1 ;
V_138 = F_28 ( 0xAC ) ;
if ( V_138 & 8 ) {
if ( V_137 == 2 ) {
F_1 ( 0x1F0 , 14 , V_99 , 0 ) ;
F_1 ( 0x170 , 15 , V_99 , 0 ) ;
}
if ( V_138 & 4 )
F_1 ( 0x170 , 15 , V_99 , 0 ) ;
else
F_1 ( 0x1F0 , 14 , V_99 , 0 ) ;
} else
F_1 ( 0x1F0 , 14 , V_99 , 0 ) ;
}
static T_3 void F_66 ( T_1 V_53 , T_1 V_139 , unsigned long V_1 )
{
static const unsigned long V_140 [ 2 ] = { 0x170 , 0x1F0 } ;
if ( ( V_53 & 0xF0 ) == 0xC0 ) {
if ( V_53 & 8 )
return;
F_1 ( V_140 [ V_53 & 0x01 ] , 14 + ( V_53 & 0x01 ) ,
V_75 , V_1 ) ;
}
if ( ( ( V_53 & 0xF0 ) == 0xA0 ) || ( V_53 & 0xF0 ) == 0x50 ) {
if ( ! F_67 ( V_1 + 2 , 2 , L_16 ) ) {
F_68 ( V_1 , 2 ) ;
return;
}
V_139 = F_8 ( V_1 + 3 ) ;
if ( V_139 & 1 )
F_1 ( V_140 [ V_53 & 0x01 ] , 14 + ( V_53 & 0x01 ) ,
V_73 , V_1 ) ;
else {
F_1 ( 0x1F0 , 14 , V_141 , V_1 ) ;
F_1 ( 0x170 , 15 , V_141 , V_1 + 2 ) ;
}
F_68 ( V_1 + 2 , 2 ) ;
}
}
static T_3 void F_69 ( void )
{
unsigned long V_22 ;
static const unsigned long V_142 [ 2 ] = { 0x30 , 0xB0 } ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
unsigned long V_1 = V_142 [ V_8 ] ;
T_1 V_53 , V_139 ;
if ( F_67 ( V_1 , 2 , L_16 ) ) {
F_7 ( V_22 ) ;
V_53 = F_8 ( V_1 ) ;
F_11 ( 1 ) ;
F_9 ( 0x19 , V_1 ) ;
F_11 ( 1 ) ;
V_139 = F_8 ( V_1 ) ;
F_11 ( 1 ) ;
F_9 ( V_53 , V_1 ) ;
F_11 ( 1 ) ;
F_10 ( V_22 ) ;
if ( V_139 == 0x19 ) {
F_68 ( V_1 , 2 ) ;
continue;
}
V_53 = F_8 ( V_1 + 1 ) ;
F_11 ( 1 ) ;
if ( ( V_53 & 2 ) >> 1 == V_8 )
F_66 ( V_53 , V_139 , V_1 ) ;
F_68 ( V_1 , 2 ) ;
}
}
}
static T_3 int F_70 ( void )
{
int V_8 ;
int V_143 = 0 ;
int V_132 = 0 ;
int V_133 = 0 ;
int V_144 = 0 ;
struct V_5 * V_145 = & V_7 [ 0 ] ;
int V_86 = 0 ;
struct V_130 * V_131 = NULL ;
F_71 (p) {
int V_53 ;
for ( V_53 = 0 ; V_53 < 6 ; V_53 ++ ) {
if ( F_72 ( V_131 , V_53 ) == 0x1f0 )
V_132 = 1 ;
if ( F_72 ( V_131 , V_53 ) == 0x170 )
V_133 = 1 ;
}
F_63 ( V_131 , & V_132 , & V_133 ) ;
V_144 = 1 ;
}
if ( V_87 == 1 )
V_87 = 0x130 ;
if ( V_132 == 0 || V_146 )
F_1 ( 0x1F0 , 14 , V_147 , 0 ) ;
if ( V_133 == 0 || V_146 )
F_1 ( 0x170 , 15 , V_147 , 0 ) ;
if ( V_148 || ! V_144 ) {
F_1 ( 0x1E8 , 11 , V_147 , 0 ) ;
F_1 ( 0x168 , 10 , V_147 , 0 ) ;
F_1 ( 0x1E0 , 8 , V_147 , 0 ) ;
F_1 ( 0x160 , 12 , V_147 , 0 ) ;
}
if ( V_98 )
F_65 () ;
if ( V_149 )
F_69 () ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ , V_145 ++ ) {
if ( V_145 -> V_1 == 0 )
continue;
if ( V_145 -> type == V_147 )
V_145 -> type = F_49 ( V_145 ) ;
V_145 -> V_86 = V_86 ++ ;
if ( F_50 ( V_145 ) == 0 )
V_143 ++ ;
}
if ( V_143 != 0 )
return 0 ;
return - V_128 ;
}
static T_7 void F_73 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_150 ; V_8 ++ ) {
struct V_68 * V_79 = & V_68 [ V_8 ] ;
F_61 ( V_129 [ V_8 ] ) ;
F_62 ( V_79 -> V_127 ) ;
}
}
