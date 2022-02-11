static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static struct V_5 * F_2 ( struct V_5 * V_6 ,
unsigned long V_7 )
{
if ( V_6 ) {
if ( F_3 ( V_8 ,
F_4 () ,
V_7 , V_6 ) < 0 ) {
F_5 ( V_9 L_1
L_2 ,
V_7 ) ;
return NULL ;
}
}
return V_6 ;
}
static void F_6 ( struct V_5 * V_6 )
{
if ( V_6 && V_6 -> V_10 )
F_7 ( V_6 ) ;
}
static inline void F_8 ( unsigned V_11 , enum V_12 V_13 ,
unsigned char V_14 )
{
F_9 ( V_13 , F_10 ( V_11 ) ) ;
F_9 ( V_14 , F_11 ( V_11 ) ) ;
}
static void F_12 ( struct V_1 * V_15 , enum V_12 V_13 ,
unsigned char V_14 )
{
unsigned long V_16 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
F_8 ( V_15 -> V_11 , V_13 , V_14 ) ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
}
static inline unsigned char F_15 ( unsigned V_11 ,
enum V_12 V_13 )
{
F_9 ( V_13 , F_10 ( V_11 ) ) ;
return F_16 ( F_11 ( V_11 ) ) ;
}
static inline void F_17 ( unsigned V_11 )
{
F_9 ( 0x0 , F_18 ( V_11 ) ) ;
}
static inline void F_19 ( unsigned V_11 )
{
F_9 ( 0x3 , F_18 ( V_11 ) ) ;
}
static inline int F_20 ( unsigned V_11 )
{
int V_18 = - 1 ;
if ( ( F_16 ( F_18 ( V_11 ) ) & V_19 ) != 0 )
V_18 = F_16 ( F_21 ( V_11 ) ) ;
return V_18 ;
}
static int F_22 ( unsigned V_11 , unsigned V_20 )
{
int V_18 ;
while ( ( ( V_18 = F_20 ( V_11 ) ) < 0 ) && ( V_20 != 0 ) ) {
F_23 ( 100 ) ;
-- V_20 ;
}
return V_18 ;
}
static inline int F_24 ( unsigned V_11 , unsigned char V_18 )
{
if ( ( F_16 ( F_18 ( V_11 ) ) & V_21 ) != 0 ) {
F_9 ( V_18 , F_21 ( V_11 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_25 ( unsigned V_11 , unsigned char V_18 ,
unsigned V_20 )
{
int V_22 ;
while ( ! ( V_22 = F_24 ( V_11 , V_18 ) ) && ( V_20 != 0 ) ) {
F_23 ( 100 ) ;
-- V_20 ;
}
return V_22 ;
}
static inline int F_26 ( const struct V_23 * V_24 )
{
return ( ( F_16 ( F_27 ( V_24 ) ) & 0xc0 ) == 0x80 ) ;
}
static inline void F_28 ( const struct V_23 * V_24 )
{
F_9 ( 0 , F_29 ( V_24 ) ) ;
}
static void F_30 ( unsigned V_11 )
{
unsigned char V_14 = F_15 ( V_11 , V_25 ) ;
F_8 ( V_11 , V_25 , ( V_14 & 0xcf ) | 0x10 ) ;
F_8 ( V_11 , V_26 , 0x80 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
F_32 ( V_27 -> V_28 ) ;
F_32 ( V_27 -> V_29 ) ;
F_33 ( V_27 -> V_30 -> V_31 ) ;
}
static void F_34 ( unsigned V_11 , enum V_12 V_13 )
{
F_8 ( V_11 , V_13 ,
F_15 ( V_11 , V_13 ) | 0x01 ) ;
F_8 ( V_11 , V_13 ,
F_15 ( V_11 , V_13 ) & 0xfe ) ;
}
static int F_35 ( unsigned V_11 , enum V_12 V_13 ,
unsigned V_20 )
{
while ( ! ( F_15 ( V_11 , V_13 ) & 0x01 ) && ( V_20 != 0 ) ) {
F_23 ( 100 ) ;
-- V_20 ;
}
return F_15 ( V_11 , V_13 ) & 0x01 ;
}
static int F_36 ( struct V_1 * V_15 , unsigned V_20 )
{
unsigned long V_32 = V_33 + F_37 ( V_20 ) ;
do {
unsigned long V_16 ;
int V_34 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
V_34 = F_20 ( V_15 -> V_11 ) ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
if ( V_34 == 0xfe || V_34 == 0xff )
return 1 ;
F_38 ( 10 ) ;
} while ( F_39 ( V_33 , V_32 ) );
return 0 ;
}
static int F_40 ( struct V_1 * V_15 , unsigned V_20 )
{
unsigned long V_32 = V_33 + F_37 ( V_20 ) ;
do {
unsigned long V_16 ;
int V_34 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
V_34 = F_20 ( V_15 -> V_11 ) ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
if ( V_34 == 0xfe )
return 1 ;
F_38 ( 10 ) ;
} while ( F_39 ( V_33 , V_32 ) );
return 0 ;
}
static int F_41 ( struct V_1 * V_15 , const unsigned char * V_18 ,
T_1 V_7 )
{
unsigned long V_16 ;
struct V_5 V_35 ;
int V_36 ;
unsigned char V_14 ;
if ( ! F_2 ( & V_35 , F_42 ( 32 * 1024 ) ) )
return - V_37 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
V_14 = F_15 ( V_15 -> V_11 , V_25 ) ;
F_8 ( V_15 -> V_11 , V_25 , V_14 & 0x3f ) ;
V_14 = ( V_15 -> V_30 -> V_31 << 4 ) | V_38 ;
F_8 ( V_15 -> V_11 , V_39 , V_14 ) ;
F_8 ( V_15 -> V_11 , V_40 , 0x20 ) ;
V_14 = F_15 ( V_15 -> V_11 , V_25 ) ;
F_8 ( V_15 -> V_11 , V_25 , V_14 | 0x80 ) ;
while ( V_7 != 0 ) {
unsigned long V_41 ;
V_41 = F_43 ( V_7 , V_35 . V_42 ) ;
memcpy ( V_35 . V_10 , V_18 , V_41 ) ;
V_18 += V_41 ;
V_7 -= V_41 ;
F_44 ( V_15 -> V_30 -> V_31 , V_35 . V_43 , V_41 , V_44 ) ;
F_34 ( V_15 -> V_11 , V_39 ) ;
if ( ! F_35 ( V_15 -> V_11 , V_39 , 5000 ) ) {
F_14 ( & V_15 -> V_17 , V_16 ) ;
F_5 ( V_9
L_3 ) ;
V_36 = - V_45 ;
goto V_46;
}
}
F_17 ( V_15 -> V_11 ) ;
F_9 ( 0x0 , V_15 -> V_11 ) ;
V_14 = F_15 ( V_15 -> V_11 , V_25 ) ;
F_8 ( V_15 -> V_11 , V_25 , V_14 | 0x40 ) ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
V_36 = 0 ;
if ( ! F_36 ( V_15 , 5000 ) ) {
F_5 ( V_9 L_4
L_5 ) ;
V_36 = - V_45 ;
} else if ( ! F_40 ( V_15 , 5000 ) ) {
F_5 ( V_9
L_6 ) ;
V_36 = - V_45 ;
}
V_46:
F_12 ( V_15 , V_39 , ( V_15 -> V_47 == V_48 ? 0x40 : 0x70 ) ) ;
F_6 ( & V_35 ) ;
return V_36 ;
}
static int F_45 ( struct V_2 * V_49 )
{
struct V_1 * V_27 = F_1 ( V_49 ) ;
unsigned long V_16 ;
const struct V_50 * V_51 = NULL ;
int V_18 = 0 ;
int V_36 ;
V_36 = F_46 ( & V_51 , L_7 , V_49 -> V_52 ) ;
if ( V_36 < 0 ) {
F_5 ( V_9 L_8 ) ;
return V_36 ;
}
V_36 = F_41 ( V_27 , V_51 -> V_18 , V_51 -> V_7 ) ;
F_47 ( V_51 ) ;
F_13 ( & V_27 -> V_17 , V_16 ) ;
if ( V_36 == 0 )
V_18 = F_22 ( V_27 -> V_11 , 100 ) ;
if ( V_18 & 0x10 )
F_8 ( V_27 -> V_11 , V_53 , 0x2f ) ;
F_14 ( & V_27 -> V_17 , V_16 ) ;
V_18 &= 0xf ;
if ( V_36 == 0 && V_18 > 7 ) {
F_5 ( V_9
L_9 ) ;
V_36 = - V_45 ;
}
return ( V_36 == 0 ) ? V_18 : V_36 ;
}
static int F_48 ( struct V_2 * V_49 , int V_54 )
{
struct V_1 * V_27 = F_1 ( V_49 ) ;
const struct V_50 * V_51 = NULL ;
char V_55 [ 14 ] ;
int V_22 ;
snprintf ( V_55 , sizeof( V_55 ) , L_10 , V_54 ) ;
V_22 = F_46 ( & V_51 , V_55 , V_49 -> V_52 ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_11 ,
V_54 ) ;
return V_22 ;
}
V_22 = F_41 ( V_27 , V_51 -> V_18 , V_51 -> V_7 ) ;
if ( V_22 == 0 )
F_5 ( V_56 L_12 ,
V_51 -> V_7 >> 10 ) ;
F_47 ( V_51 ) ;
return V_22 ;
}
static int F_49 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
V_60 -> type = V_61 ;
V_60 -> V_62 = 1 ;
V_60 -> V_63 . integer . F_43 = 0 ;
V_60 -> V_63 . integer . V_64 = 127 ;
return 0 ;
}
static int F_50 ( struct V_57 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 * V_30 = F_51 ( V_65 ) ;
struct V_2 * V_49 = V_30 -> V_49 ;
register struct V_1 * V_15 = F_1 ( V_49 ) ;
unsigned long V_16 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
V_67 -> V_63 . integer . V_63 [ 0 ] = V_15 -> V_69 ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_52 ( struct V_57 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 * V_30 = F_51 ( V_65 ) ;
struct V_2 * V_49 = V_30 -> V_49 ;
struct V_1 * V_15 = F_1 ( V_49 ) ;
unsigned long V_16 ;
int V_70 ;
unsigned char V_71 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
V_71 = V_67 -> V_63 . integer . V_63 [ 0 ] & 127 ;
F_17 ( V_15 -> V_11 ) ;
if ( V_15 -> V_69 == V_71 ) {
V_70 = 0 ;
goto V_72;
}
V_70 = F_25 ( V_15 -> V_11 , V_73 , 100 )
&& F_25 ( V_15 -> V_11 , V_71 , 100 )
&& F_25 ( V_15 -> V_11 , V_74 , 100 )
&& F_25 ( V_15 -> V_11 , V_71 , 100 ) ;
V_15 -> V_69 = V_71 ;
V_72:
F_19 ( V_15 -> V_11 ) ;
F_14 ( & V_15 -> V_17 , V_16 ) ;
return V_70 ;
}
static unsigned F_53 ( int V_75 , int V_76 )
{
static const int V_77 [] = { 9 , 5 , 7 , 10 } ;
static const int V_78 [] = { 9 , 7 , 5 , 15 } ;
unsigned V_79 ;
if ( V_75 == V_80 ) {
for ( V_79 = 0 ; V_79 < F_54 ( V_78 ) ; ++ V_79 )
if ( V_76 == V_78 [ V_79 ] )
return V_79 ;
} else {
for ( V_79 = 0 ; V_79 < F_54 ( V_77 ) ; ++ V_79 )
if ( V_76 == V_77 [ V_79 ] )
return V_79 ;
}
return V_81 ;
}
static int F_55 ( struct V_1 * V_15 , long V_82 )
{
unsigned long V_16 ;
unsigned V_83 ;
int V_84 = 0 ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
if ( ( F_16 ( F_18 ( V_15 -> V_11 ) ) & 0x78 ) != 0 )
goto V_85;
V_83 = F_16 ( F_10 ( V_15 -> V_11 ) ) & 0xf0 ;
if ( ( V_83 & 0x80 ) != 0 )
goto V_85;
if ( V_83 == 0 )
V_15 -> V_47 = V_86 ;
else if ( ( V_83 & 0x60 ) != 0 )
V_15 -> V_47 = V_48 ;
else
goto V_85;
F_9 ( 0xfa , F_10 ( V_15 -> V_11 ) ) ;
if ( ( F_16 ( F_10 ( V_15 -> V_11 ) ) & 0x9f ) != 0x0a )
goto V_85;
F_9 ( 0xfe , F_10 ( V_15 -> V_11 ) ) ;
if ( ( F_16 ( F_10 ( V_15 -> V_11 ) ) & 0x9f ) != 0x0e )
goto V_85;
F_9 ( 0xfe , F_10 ( V_15 -> V_11 ) ) ;
V_83 = F_16 ( F_11 ( V_15 -> V_11 ) ) ;
if ( V_15 -> type != V_87 && ( V_83 & 0x9f ) != 0x0e )
goto V_85;
if ( V_15 -> V_47 == V_48 )
F_30 ( V_15 -> V_11 ) ;
if ( V_15 -> type == V_87 )
V_82 += 4 ;
V_83 = F_15 ( V_15 -> V_11 , V_25 ) ;
F_8 ( V_15 -> V_11 , V_25 , V_83 | 0xc0 ) ;
for ( V_83 = 0 ; V_83 < 500 ; V_83 ++ ) {
if ( ( F_16 ( V_82 ) & 0x80 ) == 0 )
break;
F_14 ( & V_15 -> V_17 , V_16 ) ;
F_38 ( 1 ) ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
}
if ( ( F_16 ( V_82 ) & 0x80 ) != 0 )
goto V_85;
if ( F_16 ( V_82 + 2 ) == 0xff )
goto V_85;
V_83 = F_15 ( V_15 -> V_11 , V_25 ) & 0x3f ;
F_8 ( V_15 -> V_11 , V_25 , V_83 ) ;
if ( ( F_16 ( V_82 ) & 0x80 ) != 0 )
V_15 -> type = V_80 ;
V_83 = F_15 ( V_15 -> V_11 , V_25 ) ;
F_8 ( V_15 -> V_11 , V_25 , V_83 | 0xc0 ) ;
for ( V_83 = 0 ; V_83 < 500 ; V_83 ++ ) {
if ( ( F_16 ( V_82 ) & 0x80 ) == 0 )
break;
F_14 ( & V_15 -> V_17 , V_16 ) ;
F_38 ( 1 ) ;
F_13 ( & V_15 -> V_17 , V_16 ) ;
}
V_84 = 1 ;
V_85:
F_14 ( & V_15 -> V_17 , V_16 ) ;
return V_84 ;
}
static int F_56 ( struct V_23 * V_24 )
{
if ( ! F_26 ( V_24 ) ) {
F_5 ( V_9 L_13
L_14 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_49 , int V_89 ,
unsigned long V_90 , int V_76 )
{
struct V_1 * V_27 = F_1 ( V_49 ) ;
struct V_91 * V_92 ;
int V_22 ;
V_22 = F_58 ( V_49 , V_89 , V_93 , V_90 ,
V_94 , V_76 , & V_92 ) ;
if ( V_22 == 0 ) {
struct V_23 * V_24 = V_92 -> V_4 ;
V_24 -> V_95 = F_56 ;
V_24 -> V_96 = F_56 ;
V_24 -> V_4 = V_27 ;
F_28 ( V_24 ) ;
}
return V_22 ;
}
static int F_59 ( struct V_2 * V_49 , unsigned V_90 ,
int V_76 , int V_31 , int V_97 )
{
register struct V_1 * V_27 = F_1 ( V_49 ) ;
struct V_68 * V_30 ;
int V_22 ;
int V_98 = V_99 ;
switch ( V_27 -> type ) {
case V_80 :
case V_100 :
if ( V_27 -> V_47 != V_48 )
V_98 = V_101 ;
break;
case V_87 :
V_90 += 4 ;
break;
default:
break;
}
V_22 = F_60 ( V_49 , V_90 , - 1 , V_76 , V_31 , V_97 ,
V_98 , V_102 , & V_30 ) ;
if ( ! V_22 ) {
unsigned long V_16 ;
if ( V_27 -> type != V_87 ) {
F_61 ( V_30 ) ;
F_13 ( & V_30 -> V_103 , V_16 ) ;
F_62 ( V_30 , V_104 , 0x20 ) ;
F_14 ( & V_30 -> V_103 , V_16 ) ;
F_63 ( V_30 ) ;
}
V_22 = F_64 ( V_30 , 0 ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_15
L_16 ) ;
goto V_105;
}
V_22 = F_65 ( V_30 ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_17
L_16 ) ;
goto V_105;
}
if ( V_30 -> V_106 != V_101 ) {
V_22 = F_66 ( V_30 , 0 ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_18
L_16 ) ;
goto V_105;
}
}
if ( V_27 -> type != V_87 ) {
V_22 = F_67 ( V_49 ,
F_68 ( & V_107 , V_30 ) ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_19
L_20 ) ;
goto V_105;
}
}
V_27 -> V_30 = V_30 ;
}
V_105:
return V_22 ;
}
static int F_69 ( int V_52 , struct V_2 * V_49 )
{
struct V_1 * V_27 = F_1 ( V_49 ) ;
unsigned V_108 ;
unsigned V_109 ;
unsigned V_110 ;
struct V_111 * V_28 ;
struct V_111 * V_29 ;
unsigned long V_16 ;
int V_22 ;
int V_14 ;
const char * V_55 ;
V_28 = F_70 ( V_90 [ V_52 ] , 8 , L_21 ) ;
if ( ! V_28 ) {
F_5 ( V_9
L_22 , V_90 [ V_52 ] ) ;
return - V_112 ;
}
V_29 = NULL ;
if ( V_27 -> type == V_87 ) {
V_29 = F_70 ( V_113 [ V_52 ] , 4 , L_21 ) ;
if ( ! V_29 ) {
F_5 ( V_9 L_22 ,
V_113 [ V_52 ] ) ;
V_22 = - V_112 ;
goto V_114;
}
}
V_22 = F_71 ( V_35 [ V_52 ] , L_21 ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_23 , V_35 [ V_52 ] ) ;
goto V_114;
}
F_72 ( & V_27 -> V_17 ) ;
V_27 -> V_28 = V_28 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_11 = V_90 [ V_52 ] ;
if ( ! F_55 ( V_27 , V_113 [ V_52 ] ) ) {
F_73 ( V_9 L_24 ,
V_27 -> V_11 ) ;
V_22 = - V_88 ;
goto V_46;
}
switch ( V_27 -> type ) {
case V_80 :
V_55 = L_25 ;
break;
case V_100 :
V_55 = L_26 ;
break;
case V_115 :
V_55 = L_27 ;
break;
case V_87 :
V_55 = L_28 ;
break;
default:
V_55 = L_29 ;
break;
}
F_73 ( V_56 L_30 ,
V_55 , V_27 -> V_11 , V_76 [ V_52 ] , V_35 [ V_52 ] ) ;
V_109 = F_53 ( V_27 -> type , V_76 [ V_52 ] ) ;
if ( V_109 == V_81 ) {
F_5 ( V_9 L_31 , V_76 [ V_52 ] ) ;
V_22 = - V_116 ;
goto V_46;
}
V_110 = F_53 ( V_27 -> type , V_117 [ V_52 ] ) ;
if ( V_110 == V_81 ) {
F_5 ( V_9 L_31 , V_117 [ V_52 ] ) ;
V_22 = - V_116 ;
goto V_46;
}
F_13 ( & V_27 -> V_17 , V_16 ) ;
F_8 ( V_27 -> V_11 , V_53 , 0x2e ) ;
F_8 ( V_27 -> V_11 , V_118 , 0x00 ) ;
F_8 ( V_27 -> V_11 , V_119 , 0x50 ) ;
V_108 = ( V_27 -> V_47 == V_48 ? 0x40 : 0x70 ) ;
F_8 ( V_27 -> V_11 , V_39 , V_108 ) ;
F_8 ( V_27 -> V_11 , V_40 , 0x20 ) ;
V_110 |= V_110 << 2 ;
V_14 = F_15 ( V_27 -> V_11 , V_25 ) & 0xF7 ;
if ( V_120 [ V_52 ] )
V_14 |= 8 ;
F_8 ( V_27 -> V_11 , V_25 , V_14 | 0x10 ) ;
F_8 ( V_27 -> V_11 , V_121 , 0xf0 | V_110 ) ;
F_8 ( V_27 -> V_11 ,
V_26 , 0x09 | V_38
| ( V_35 [ V_52 ] << 4 ) | ( V_109 << 1 ) ) ;
F_8 ( V_27 -> V_11 , V_122 , 0x80 ) ;
F_14 ( & V_27 -> V_17 , V_16 ) ;
V_22 = F_59 ( V_49 , V_113 [ V_52 ] , V_76 [ V_52 ] ,
V_35 [ V_52 ] , V_97 [ V_52 ] ) ;
if ( V_22 < 0 ) {
F_5 ( V_9
L_32 ,
V_113 [ V_52 ] , V_76 [ V_52 ] ) ;
goto V_46;
}
strcpy ( V_49 -> V_123 , L_21 ) ;
strcpy ( V_49 -> V_124 , V_55 ) ;
snprintf ( V_49 -> V_125 , sizeof( V_49 -> V_125 ) ,
L_33 ,
V_55 , V_27 -> V_30 -> V_90 , V_27 -> V_30 -> V_76 ,
V_27 -> V_30 -> V_31 , V_27 -> V_30 -> V_97 ) ;
#define F_74 0
if ( V_27 -> type != V_87 ) {
V_22 = F_45 ( V_49 ) ;
if ( V_22 >= 0 )
V_22 = F_48 ( V_49 , V_22 ) ;
if ( V_22 == 0 ) {
V_22 = F_57 ( V_49 , F_74 , V_90 [ V_52 ] ,
V_117 [ V_52 ] ) ;
if ( V_22 < 0 ) {
F_5 ( V_9 L_34
L_35 ,
V_90 [ V_52 ] ) ;
goto V_46;
}
F_13 ( & V_27 -> V_17 , V_16 ) ;
V_27 -> V_69 = 0 ;
F_25 ( V_27 -> V_11 ,
V_73 , 100 ) ;
F_25 ( V_27 -> V_11 ,
V_27 -> V_69 , 100 ) ;
F_25 ( V_27 -> V_11 ,
V_74 , 100 ) ;
F_25 ( V_27 -> V_11 ,
V_27 -> V_69 , 100 ) ;
F_25 ( V_27 -> V_11 ,
V_126 , 100 ) ;
F_25 ( V_27 -> V_11 ,
0 , 100 ) ;
F_25 ( V_27 -> V_11 , V_127 , 100 ) ;
F_19 ( V_27 -> V_11 ) ;
F_14 ( & V_27 -> V_17 , V_16 ) ;
}
}
V_49 -> V_128 = F_31 ;
return 0 ;
V_46:
F_33 ( V_35 [ V_52 ] ) ;
V_114:
F_32 ( V_29 ) ;
F_32 ( V_28 ) ;
return V_22 ;
}
static int F_75 ( struct V_129 * V_130 , unsigned int V_131 )
{
if ( V_90 [ V_131 ] == V_132 )
return 0 ;
if ( V_76 [ V_131 ] == V_133 ||
V_117 [ V_131 ] == V_133 ||
V_35 [ V_131 ] == V_134 ) {
F_73 ( V_56
L_36
L_37 ) ;
return 0 ;
}
return 1 ;
}
static int F_76 ( struct V_129 * V_130 , unsigned int V_52 )
{
struct V_2 * V_49 ;
struct V_1 * V_27 ;
int V_36 ;
V_36 = F_77 ( V_130 , V_135 [ V_52 ] , V_136 [ V_52 ] , V_137 ,
sizeof( struct V_1 ) , & V_49 ) ;
if ( V_36 < 0 )
return V_36 ;
V_27 = F_1 ( V_49 ) ;
V_27 -> type = V_100 ;
V_35 [ V_52 ] &= 0x03 ;
V_36 = F_69 ( V_52 , V_49 ) ;
if ( V_36 < 0 )
goto V_138;
V_36 = F_78 ( V_49 ) ;
if ( V_36 < 0 ) {
F_5 ( V_9 L_38 ) ;
goto V_138;
}
F_79 ( V_130 , V_49 ) ;
return 0 ;
V_138:
F_80 ( V_49 ) ;
return V_36 ;
}
static int F_81 ( struct V_129 * V_139 , unsigned int V_52 )
{
F_80 ( F_82 ( V_139 ) ) ;
return 0 ;
}
static inline int F_83 ( int V_131 )
{
while ( V_131 < V_140 && V_90 [ V_131 ] != V_132 )
++ V_131 ;
return V_131 ;
}
static int F_84 ( struct V_141 * V_142 ,
const struct V_143 * V_144 )
{
static int V_145 = 0 ;
struct V_146 * V_52 ;
struct V_2 * V_49 ;
struct V_1 * V_27 ;
int V_36 ;
V_145 = F_83 ( V_145 ) ;
if ( V_145 >= V_140 )
return - V_147 ;
V_52 = F_85 ( V_142 , V_144 -> V_148 [ 0 ] . V_136 , NULL ) ;
if ( ! V_52 )
return - V_88 ;
if ( ! F_86 ( V_52 ) ) {
if ( F_87 ( V_52 ) < 0 ) {
F_5 ( V_56 L_39 ) ;
return - V_112 ;
}
}
V_36 = F_77 ( & V_142 -> V_49 -> V_52 ,
V_135 [ V_145 ] , V_136 [ V_145 ] , V_137 ,
sizeof( struct V_1 ) , & V_49 ) ;
if ( V_36 < 0 )
return V_36 ;
V_27 = F_1 ( V_49 ) ;
if ( ! strncmp ( L_40 , V_144 -> V_136 , 7 ) )
V_27 -> type = V_87 ;
else
V_27 -> type = V_115 ;
V_90 [ V_145 ] = F_88 ( V_52 , 0 ) ;
V_76 [ V_145 ] = F_89 ( V_52 , 0 ) ;
V_117 [ V_145 ] = F_89 ( V_52 , 1 ) ;
V_35 [ V_145 ] = F_90 ( V_52 , 0 ) & 0x03 ;
if ( V_27 -> type == V_115 ) {
V_97 [ V_145 ] = V_35 [ V_145 ] ;
V_113 [ V_145 ] = F_91 ( V_90 [ V_145 ] ) ;
} else {
V_113 [ V_145 ] = F_88 ( V_52 , 1 ) ;
V_97 [ V_145 ] = F_90 ( V_52 , 1 ) ;
}
V_36 = F_69 ( V_145 , V_49 ) ;
if ( V_36 < 0 )
goto V_138;
V_36 = F_78 ( V_49 ) ;
if ( V_36 < 0 ) {
F_5 ( V_9 L_38 ) ;
goto V_138;
}
F_92 ( V_142 , V_49 ) ;
++ V_145 ;
return 0 ;
V_138:
F_80 ( V_49 ) ;
return V_36 ;
}
static void F_93 ( struct V_141 * V_142 )
{
F_80 ( F_94 ( V_142 ) ) ;
F_92 ( V_142 , NULL ) ;
}
static int T_2 F_95 ( void )
{
int V_22 ;
V_22 = F_96 ( & V_149 , V_140 ) ;
#ifdef F_97
if ( ! V_22 )
V_150 = 1 ;
V_22 = F_98 ( & V_151 ) ;
if ( ! V_22 )
V_152 = 1 ;
if ( V_150 )
V_22 = 0 ;
#endif
return V_22 ;
}
static void T_3 F_99 ( void )
{
#ifdef F_97
if ( V_152 )
F_100 ( & V_151 ) ;
if ( V_150 )
#endif
F_101 ( & V_149 ) ;
}
