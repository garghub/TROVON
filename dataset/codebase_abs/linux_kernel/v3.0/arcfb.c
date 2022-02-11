static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned char V_4 )
{
unsigned char V_5 = V_2 -> V_6 [ V_3 ] ;
F_2 ( V_5 | V_7 | V_8 , V_2 -> V_9 ) ;
F_2 ( V_4 , V_2 -> V_10 ) ;
F_3 ( V_11 ) ;
F_2 ( V_5 | V_12 | V_8 , V_2 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned char V_4 )
{
F_2 ( V_4 , V_2 -> V_9 ) ;
F_3 ( V_11 ) ;
}
static unsigned char F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned char V_4 )
{
unsigned char V_5 = V_2 -> V_6 [ V_3 ] ;
F_2 ( V_5 | V_7 | V_14 , V_2 -> V_9 ) ;
F_2 ( V_4 , V_2 -> V_10 ) ;
F_3 ( V_11 ) ;
F_2 ( V_5 | V_12 | V_14 , V_2 -> V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned char V_15 )
{
F_1 ( V_2 , V_3 , V_16 | V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned char V_15 )
{
F_1 ( V_2 , V_3 , V_17 | V_15 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned char V_18 )
{
F_1 ( V_2 , V_3 , V_19 | V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 <= 8 ; V_20 ++ ) {
F_9 ( V_2 , V_3 , V_20 ) ;
F_10 ( V_2 , V_3 , 0 ) ;
for ( V_21 = 0 ; V_21 < 64 ; V_21 ++ ) {
F_7 ( V_2 , V_3 ,
( unsigned char ) V_22 ) ;
}
}
}
static int F_12 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
F_13 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_27 = F_15 ( & V_2 -> V_26 ) ;
if ( ! V_27 )
return - V_28 ;
F_16 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 ,
struct V_23 * V_24 )
{
int V_20 ;
struct V_1 * V_2 = V_24 -> V_2 ;
if ( ( V_30 -> V_31 & V_32 ) && ( V_30 -> V_33 < 64 )
&& ( V_24 -> V_30 . V_34 <= 64 ) ) {
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
F_8 ( V_2 , V_20 , V_30 -> V_33 ) ;
}
V_24 -> V_30 . V_33 = V_30 -> V_33 ;
return 0 ;
}
return - V_28 ;
}
static T_1 F_18 ( int V_36 , void * V_37 )
{
struct V_23 * V_24 = V_37 ;
unsigned char V_38 ;
struct V_1 * V_2 = V_24 -> V_2 ;
V_38 = F_5 ( V_2 ) ;
if ( ! ( V_38 & V_39 ) )
return V_40 ;
F_4 ( V_2 , V_41 ) ;
F_19 ( & V_2 -> V_42 ) ;
if ( F_20 ( & V_43 ) ) {
F_21 ( & V_43 ) ;
}
F_22 ( & V_2 -> V_42 ) ;
return V_44 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_45 ,
unsigned int V_46 , unsigned int V_47 , unsigned int V_48 )
{
unsigned char * V_49 ;
unsigned int V_50 , V_51 , V_3 , V_52 ;
int V_20 ;
unsigned char V_53 ;
unsigned char V_54 , V_55 ;
V_50 = V_46 >> 6 ;
V_51 = V_45 >> 6 ;
V_3 = ( V_50 + ( V_51 * V_35 ) ) ;
F_9 ( V_2 , V_3 , V_45 / 8 ) ;
V_52 = V_2 -> V_24 -> V_30 . V_56 / 8 ;
V_49 = ( unsigned char V_57 * ) V_2 -> V_24 -> V_58 + ( V_46 / 8 ) +
( V_45 * V_52 ) ;
F_10 ( V_2 , V_3 , V_46 ) ;
V_54 = 1 ;
V_55 = 0 ;
while ( V_46 <= V_47 ) {
V_53 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
if ( V_20 > V_55 ) {
V_53 |= ( * ( V_49 + ( V_20 * V_52 ) ) & V_54 )
<< ( V_20 - V_55 ) ;
} else {
V_53 |= ( * ( V_49 + ( V_20 * V_52 ) ) & V_54 )
>> ( V_55 - V_20 ) ;
}
}
F_7 ( V_2 , V_3 , V_53 ) ;
V_46 ++ ;
if ( V_54 == 0x80 ) {
V_54 = 1 ;
V_49 ++ ;
V_55 = 0 ;
} else {
V_54 <<= 1 ;
V_55 ++ ;
}
}
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_59 ,
unsigned int V_60 , unsigned int V_46 , unsigned int V_47 )
{
unsigned int V_48 , V_45 , V_61 ;
V_48 = ( V_60 - V_59 ) + 1 ;
V_45 = V_59 ;
V_61 = V_59 + 7 ;
while ( V_48 > 0 ) {
V_48 -= 8 ;
F_23 ( V_2 , V_45 , V_46 , V_47 , 8 ) ;
V_45 = V_61 + 1 ;
V_61 = V_45 + 7 ;
}
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_46 ,
unsigned int V_47 , unsigned int V_59 , unsigned int V_62 )
{
unsigned int V_48 , V_45 , V_61 ;
V_48 = V_62 ;
V_45 = F_26 ( V_59 ) ;
V_61 = F_27 ( V_45 + V_48 - 1 , F_28 ( V_45 ) ) ;
while ( V_48 > 0 ) {
V_48 -= ( ( V_61 - V_45 ) + 1 ) ;
F_24 ( V_2 , V_45 , V_61 , V_46 , V_47 ) ;
V_45 = V_61 + 1 ;
V_61 = F_27 ( V_45 + V_48 - 1 , F_28 ( V_45 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_63 ,
unsigned int V_64 , unsigned int V_65 , unsigned int V_62 )
{
unsigned int V_46 , V_47 , V_48 , V_15 ;
V_15 = F_26 ( V_64 ) ;
V_62 += V_64 - V_15 ;
V_62 = F_30 ( V_62 ) ;
V_48 = V_65 ;
V_46 = V_63 ;
V_47 = F_27 ( V_46 + V_65 - 1 , F_28 ( V_46 ) ) ;
while ( V_48 > 0 ) {
F_25 ( V_2 , V_46 , V_47 , V_15 , V_62 ) ;
V_48 -= ( ( V_47 - V_46 ) + 1 ) ;
V_46 = V_47 + 1 ;
V_47 = F_27 ( V_46 + V_48 - 1 , F_28 ( V_46 ) ) ;
}
}
static void F_31 ( struct V_23 * V_24 ,
const struct V_66 * V_67 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
F_32 ( V_24 , V_67 ) ;
F_29 ( V_2 , V_67 -> V_63 , V_67 -> V_64 , V_67 -> V_68 , V_67 -> V_69 ) ;
}
static void F_33 ( struct V_23 * V_24 ,
const struct V_70 * V_71 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
F_34 ( V_24 , V_71 ) ;
F_29 ( V_2 , V_71 -> V_63 , V_71 -> V_64 , V_71 -> V_68 , V_71 -> V_69 ) ;
}
static void F_35 ( struct V_23 * V_24 , const struct V_72 * V_73 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
F_36 ( V_24 , V_73 ) ;
F_29 ( V_2 , V_73 -> V_63 , V_73 -> V_64 , V_73 -> V_68 ,
V_73 -> V_69 ) ;
}
static int F_37 ( struct V_23 * V_24 ,
unsigned int V_74 , unsigned long V_75 )
{
void T_2 * V_76 = ( void T_2 * ) V_75 ;
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_77 ;
switch ( V_74 ) {
case V_78 :
{
F_38 ( V_79 ) ;
if ( ! V_2 -> V_80 )
return - V_28 ;
F_39 ( & V_2 -> V_42 , V_77 ) ;
F_40 ( & V_43 , & V_79 ,
V_81 ) ;
F_41 ( & V_2 -> V_42 , V_77 ) ;
F_42 () ;
F_43 ( & V_43 , & V_79 ) ;
}
case V_82 :
{
unsigned char V_83 ;
V_83 = F_5 ( V_24 -> V_2 ) ;
if ( F_44 ( V_76 , & V_83 , sizeof( V_83 ) ) )
return - V_84 ;
return 0 ;
}
default:
return - V_28 ;
}
}
static T_3 F_45 ( struct V_23 * V_24 , const char T_2 * V_85 ,
T_4 V_27 , T_5 * V_86 )
{
unsigned long V_87 ;
int V_88 = - V_28 ;
unsigned int V_89 , V_18 , V_15 , V_65 , V_62 , V_90 , V_91 , V_92 , V_93 ;
struct V_1 * V_2 ;
unsigned int V_56 ;
V_87 = * V_86 ;
V_2 = V_24 -> V_2 ;
V_56 = V_24 -> V_30 . V_56 ;
V_89 = ( V_56 * V_24 -> V_30 . V_34 ) / 8 ;
if ( V_87 > V_89 )
return - V_94 ;
V_88 = 0 ;
if ( ( V_27 + V_87 ) > V_89 ) {
V_27 = V_89 - V_87 ;
V_88 = - V_94 ;
}
if ( V_27 ) {
char * V_95 ;
V_95 = ( char V_57 * ) V_24 -> V_58 ;
V_27 -= F_46 ( V_95 + V_87 , V_85 , V_27 ) ;
* V_86 += V_27 ;
V_88 = - V_84 ;
}
V_90 = V_87 * 8 ;
V_91 = F_47 ( V_90 , V_56 ) ;
V_92 = F_48 ( ( V_90 + ( V_27 * 8 ) ) , V_56 ) ;
V_93 = V_92 - V_91 ;
V_18 = V_91 % V_56 ;
V_15 = V_91 / V_56 ;
V_65 = V_56 ;
V_62 = V_93 / V_56 ;
F_29 ( V_2 , V_18 , V_15 , V_65 , V_62 ) ;
if ( V_27 )
return V_27 ;
return V_88 ;
}
static int T_6 F_49 ( struct V_96 * V_97 )
{
struct V_23 * V_24 ;
int V_98 = - V_99 ;
int V_100 ;
unsigned char * V_101 ;
struct V_1 * V_2 ;
int V_20 ;
V_100 = ( ( ( 64 * 64 ) * V_35 ) * V_102 ) / 8 ;
V_101 = F_50 ( V_100 ) ;
if ( ! V_101 )
return V_98 ;
V_24 = F_51 ( sizeof( struct V_1 ) , & V_97 -> V_97 ) ;
if ( ! V_24 )
goto V_88;
V_24 -> V_58 = ( char V_103 * ) V_101 ;
V_24 -> V_104 = & V_105 ;
V_24 -> V_30 = V_106 ;
V_24 -> V_107 = V_108 ;
V_2 = V_24 -> V_2 ;
V_2 -> V_24 = V_24 ;
if ( ! V_10 || ! V_9 || ! V_13 ) {
F_52 ( V_109 L_1 ) ;
goto V_110;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 [ 0 ] = 0x00 ;
V_2 -> V_6 [ 1 ] = 0x06 ;
V_24 -> V_77 = V_111 ;
F_53 ( & V_2 -> V_42 ) ;
V_98 = F_54 ( V_24 ) ;
if ( V_98 < 0 )
goto V_110;
F_55 ( V_97 , V_24 ) ;
if ( V_80 ) {
V_2 -> V_80 = V_80 ;
if ( F_56 ( V_2 -> V_80 , & F_18 , V_112 ,
L_2 , V_24 ) ) {
F_52 ( V_113
L_3 , V_2 -> V_80 ) ;
goto V_110;
}
}
F_52 ( V_113
L_4 ,
V_24 -> V_114 , V_100 >> 10 ) ;
for ( V_20 = 0 ; V_20 < V_35 * V_102 ; V_20 ++ ) {
F_1 ( V_2 , V_20 , V_115 ) ;
F_8 ( V_2 , V_20 , 0 ) ;
F_9 ( V_2 , V_20 , 0 ) ;
F_10 ( V_2 , V_20 , 0 ) ;
F_1 ( V_2 , V_20 , V_116 ) ;
}
if ( ! V_117 ) {
for ( V_20 = 0 ; V_20 < V_35 * V_102 ; V_20 ++ ) {
F_52 ( V_113 L_5 ,
V_24 -> V_114 , V_20 ) ;
F_8 ( V_2 , V_20 , 0 ) ;
F_11 ( V_2 , V_20 ) ;
}
}
return 0 ;
V_110:
F_57 ( V_24 ) ;
V_88:
F_58 ( V_101 ) ;
return V_98 ;
}
static int T_7 F_59 ( struct V_96 * V_97 )
{
struct V_23 * V_24 = F_60 ( V_97 ) ;
if ( V_24 ) {
F_61 ( V_24 ) ;
F_58 ( ( void V_57 * ) V_24 -> V_58 ) ;
F_57 ( V_24 ) ;
}
return 0 ;
}
static int T_8 F_62 ( void )
{
int V_118 ;
if ( ! V_119 )
return - V_120 ;
V_118 = F_63 ( & V_121 ) ;
if ( ! V_118 ) {
V_122 = F_64 ( L_2 , 0 ) ;
if ( V_122 ) {
V_118 = F_65 ( V_122 ) ;
} else {
V_118 = - V_99 ;
}
if ( V_118 ) {
F_66 ( V_122 ) ;
F_67 ( & V_121 ) ;
}
}
return V_118 ;
}
static void T_9 F_68 ( void )
{
F_69 ( V_122 ) ;
F_67 ( & V_121 ) ;
}
