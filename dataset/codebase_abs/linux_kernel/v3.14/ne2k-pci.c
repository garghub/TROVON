static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
unsigned char V_8 [ 32 ] ;
int V_9 , V_10 ;
int V_11 , V_12 , V_13 = V_4 -> V_14 ;
static unsigned int V_15 ;
long V_16 ;
int V_17 = V_18 [ V_13 ] . V_17 ;
struct V_19 * V_20 ;
#ifndef F_2
static int V_21 ;
if ( ! V_21 ++ )
F_3 ( V_22 ) ;
#endif
V_15 ++ ;
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_16 = F_5 ( V_2 , 0 ) ;
V_11 = V_2 -> V_11 ;
if ( ! V_16 || ( ( F_6 ( V_2 , 0 ) & V_23 ) == 0 ) ) {
F_7 ( & V_2 -> V_6 , L_1 ) ;
return - V_24 ;
}
if ( F_8 ( V_16 , V_25 , V_26 ) == NULL ) {
F_7 ( & V_2 -> V_6 , L_2 ,
V_25 , V_16 ) ;
return - V_27 ;
}
V_12 = F_9 ( V_16 ) ;
if ( V_12 == 0xFF )
goto V_28;
{
int V_29 ;
F_10 ( V_30 + V_31 + V_32 , V_16 + V_33 ) ;
V_29 = F_9 ( V_16 + 0x0d ) ;
F_10 ( 0xff , V_16 + 0x0d ) ;
F_10 ( V_30 + V_34 , V_16 + V_33 ) ;
F_9 ( V_16 + V_35 ) ;
if ( F_9 ( V_16 + V_35 ) != 0 ) {
F_10 ( V_12 , V_16 ) ;
F_10 ( V_29 , V_16 + 0x0d ) ;
goto V_28;
}
}
V_6 = F_11 () ;
if ( ! V_6 ) {
F_7 ( & V_2 -> V_6 , L_3 ) ;
goto V_28;
}
V_6 -> V_36 = & V_37 ;
V_20 = F_12 ( V_6 ) ;
V_20 -> V_38 = V_39 ;
F_13 ( V_6 , & V_2 -> V_6 ) ;
{
unsigned long V_40 = V_41 ;
F_10 ( F_9 ( V_16 + V_42 ) , V_16 + V_42 ) ;
while ( ( F_9 ( V_16 + V_43 ) & V_44 ) == 0 )
if ( V_41 - V_40 > 2 ) {
F_7 ( & V_2 -> V_6 ,
L_4 ) ;
goto V_45;
}
F_10 ( 0xff , V_16 + V_43 ) ;
}
{
struct { unsigned char V_46 , V_47 ; } V_48 [] = {
{ V_30 + V_34 + V_32 , V_33 } ,
{ 0x49 , V_49 } ,
{ 0x00 , V_50 } ,
{ 0x00 , V_51 } ,
{ 0x00 , V_52 } ,
{ 0xFF , V_43 } ,
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ 32 , V_50 } ,
{ 0x00 , V_51 } ,
{ 0x00 , V_57 } ,
{ 0x00 , V_58 } ,
{ V_59 + V_60 , V_33 } ,
} ;
for ( V_7 = 0 ; V_7 < F_14 ( V_48 ) ; V_7 ++ )
F_10 ( V_48 [ V_7 ] . V_46 , V_16 + V_48 [ V_7 ] . V_47 ) ;
}
if ( V_17 & V_61 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
( ( V_62 * ) V_8 ) [ V_7 ] = F_15 ( F_16 ( V_16 + V_63 ) ) ;
} else
for( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
V_8 [ V_7 ] = F_9 ( V_16 + V_63 ) ;
F_10 ( 0x49 , V_16 + V_49 ) ;
V_9 = V_64 ;
V_10 = V_17 & V_65 ? 0x60 : V_66 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_67 = V_16 ;
F_17 ( V_2 , V_6 ) ;
V_68 . V_69 = V_18 [ V_13 ] . V_69 ;
V_68 . V_70 = V_9 ;
V_68 . V_10 = V_10 ;
V_68 . V_71 = 1 ;
V_68 . V_72 = V_17 ;
if ( V_15 < V_73 ) {
if ( V_74 [ V_15 ] > 0 || ( V_75 [ V_15 ] & V_76 ) )
V_68 . V_72 |= V_76 ;
}
V_68 . V_77 = V_9 + V_78 ;
#ifdef F_18
V_68 . V_10 = V_68 . V_70 + F_18 ;
#endif
V_68 . V_79 = & V_80 ;
V_68 . V_81 = & V_82 ;
V_68 . V_83 = & V_84 ;
V_68 . V_85 = & V_86 ;
V_68 . V_87 = ( unsigned long ) V_2 ;
V_6 -> V_88 = & V_89 ;
F_19 ( V_6 , 0 ) ;
memcpy ( V_6 -> V_90 , V_8 , V_6 -> V_91 ) ;
V_7 = F_20 ( V_6 ) ;
if ( V_7 )
goto V_45;
F_21 ( V_6 , L_5 ,
V_18 [ V_13 ] . V_69 , V_16 , V_6 -> V_11 ,
V_6 -> V_90 ) ;
return 0 ;
V_45:
F_22 ( V_6 ) ;
V_28:
F_23 ( V_16 , V_25 ) ;
return - V_24 ;
}
static inline int F_24 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_67 ;
F_10 ( 0xC0 + V_30 , V_16 + V_92 ) ;
F_10 ( 0xC0 , V_16 + 0x01 ) ;
F_10 ( 0x40 , V_16 + 0x06 ) ;
F_10 ( 0x00 , V_16 + 0x01 ) ;
F_10 ( V_34 + V_30 , V_16 + V_92 ) ;
return 0 ;
}
static inline int F_25 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_67 ;
F_10 ( F_9 ( V_16 + 0x20 ) | 0x80 , V_16 + 0x20 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
if ( V_68 . V_72 & V_93 )
return F_24 ( V_6 ) ;
else if ( V_68 . V_72 & V_94 )
return F_25 ( V_6 ) ;
return - V_95 ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_96 = F_28 ( V_6 -> V_11 , V_97 , V_98 , V_6 -> V_69 , V_6 ) ;
if ( V_96 )
return V_96 ;
if ( V_68 . V_72 & V_76 )
F_26 ( V_6 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
F_31 ( V_6 ) ;
F_32 ( V_6 -> V_11 , V_6 ) ;
return 0 ;
}
static void V_80 ( struct V_5 * V_6 )
{
unsigned long V_40 = V_41 ;
struct V_19 * V_20 = F_12 ( V_6 ) ;
F_33 ( V_20 , V_99 , V_6 , L_6 ,
V_41 ) ;
F_10 ( F_9 ( V_100 + V_42 ) , V_100 + V_42 ) ;
V_68 . V_101 = 0 ;
V_68 . V_102 = 0 ;
while ( ( F_9 ( V_100 + V_43 ) & V_44 ) == 0 )
if ( V_41 - V_40 > 2 ) {
F_34 ( V_6 , L_7 ) ;
break;
}
F_10 ( V_44 , V_100 + V_43 ) ;
}
static void V_86 ( struct V_5 * V_6 , struct V_103 * V_104 , int V_105 )
{
long V_106 = V_6 -> V_67 ;
if ( V_68 . V_102 ) {
F_34 ( V_6 , L_8
L_9 ,
V_68 . V_102 , V_68 . V_107 ) ;
return;
}
V_68 . V_102 |= 0x01 ;
F_10 ( V_30 + V_34 + V_60 , V_106 + V_92 ) ;
F_10 ( sizeof( struct V_103 ) , V_106 + V_50 ) ;
F_10 ( 0 , V_106 + V_51 ) ;
F_10 ( 0 , V_106 + V_57 ) ;
F_10 ( V_105 , V_106 + V_58 ) ;
F_10 ( V_59 + V_60 , V_106 + V_92 ) ;
if ( V_68 . V_72 & V_108 ) {
F_35 ( V_100 + V_63 , V_104 , sizeof( struct V_103 ) >> 1 ) ;
} else {
* ( V_62 * ) V_104 = F_15 ( F_16 ( V_100 + V_63 ) ) ;
F_36 ( & V_104 -> V_109 ) ;
}
F_10 ( V_110 , V_106 + V_43 ) ;
V_68 . V_102 &= ~ 0x01 ;
}
static void V_82 ( struct V_5 * V_6 , int V_109 ,
struct V_111 * V_112 , int V_113 )
{
long V_106 = V_6 -> V_67 ;
char * V_114 = V_112 -> V_115 ;
if ( V_68 . V_102 ) {
F_34 ( V_6 , L_10
L_9 ,
V_68 . V_102 , V_68 . V_107 ) ;
return;
}
V_68 . V_102 |= 0x01 ;
if ( V_68 . V_72 & V_61 )
V_109 = ( V_109 + 3 ) & 0xFFFC ;
F_10 ( V_30 + V_34 + V_60 , V_106 + V_92 ) ;
F_10 ( V_109 & 0xff , V_106 + V_50 ) ;
F_10 ( V_109 >> 8 , V_106 + V_51 ) ;
F_10 ( V_113 & 0xff , V_106 + V_57 ) ;
F_10 ( V_113 >> 8 , V_106 + V_58 ) ;
F_10 ( V_59 + V_60 , V_106 + V_92 ) ;
if ( V_68 . V_72 & V_108 ) {
F_35 ( V_100 + V_63 , V_114 , V_109 >> 1 ) ;
if ( V_109 & 0x01 ) {
V_114 [ V_109 - 1 ] = F_9 ( V_100 + V_63 ) ;
}
} else {
F_37 ( V_100 + V_63 , V_114 , V_109 >> 2 ) ;
if ( V_109 & 3 ) {
V_114 += V_109 & ~ 3 ;
if ( V_109 & 2 ) {
T_1 * V_116 = ( T_1 * ) V_114 ;
* V_116 ++ = F_38 ( F_39 ( V_100 + V_63 ) ) ;
V_114 = ( char * ) V_116 ;
}
if ( V_109 & 1 )
* V_114 = F_9 ( V_100 + V_63 ) ;
}
}
F_10 ( V_110 , V_106 + V_43 ) ;
V_68 . V_102 &= ~ 0x01 ;
}
static void V_84 ( struct V_5 * V_6 , int V_109 ,
const unsigned char * V_114 , const int V_9 )
{
long V_106 = V_100 ;
unsigned long V_117 ;
if ( V_68 . V_72 & V_61 )
V_109 = ( V_109 + 3 ) & 0xFFFC ;
else
if ( V_109 & 0x01 )
V_109 ++ ;
if ( V_68 . V_102 ) {
F_34 ( V_6 , L_11
L_12 ,
V_68 . V_102 , V_68 . V_107 ) ;
return;
}
V_68 . V_102 |= 0x01 ;
F_10 ( V_34 + V_60 + V_30 , V_106 + V_92 ) ;
#ifdef F_40
F_10 ( 0x42 , V_106 + V_50 ) ;
F_10 ( 0x00 , V_106 + V_51 ) ;
F_10 ( 0x42 , V_106 + V_57 ) ;
F_10 ( 0x00 , V_106 + V_58 ) ;
F_10 ( V_59 + V_60 , V_106 + V_92 ) ;
#endif
F_10 ( V_110 , V_106 + V_43 ) ;
F_10 ( V_109 & 0xff , V_106 + V_50 ) ;
F_10 ( V_109 >> 8 , V_106 + V_51 ) ;
F_10 ( 0x00 , V_106 + V_57 ) ;
F_10 ( V_9 , V_106 + V_58 ) ;
F_10 ( V_118 + V_60 , V_106 + V_92 ) ;
if ( V_68 . V_72 & V_108 ) {
F_41 ( V_100 + V_63 , V_114 , V_109 >> 1 ) ;
} else {
F_42 ( V_100 + V_63 , V_114 , V_109 >> 2 ) ;
if ( V_109 & 3 ) {
V_114 += V_109 & ~ 3 ;
if ( V_109 & 2 ) {
T_1 * V_116 = ( T_1 * ) V_114 ;
F_43 ( F_44 ( * V_116 ++ ) , V_100 + V_63 ) ;
V_114 = ( char * ) V_116 ;
}
}
}
V_117 = V_41 ;
while ( ( F_9 ( V_106 + V_43 ) & V_110 ) == 0 )
if ( V_41 - V_117 > 2 ) {
F_45 ( V_6 , L_13 ) ;
V_80 ( V_6 ) ;
F_19 ( V_6 , 1 ) ;
break;
}
F_10 ( V_110 , V_106 + V_43 ) ;
V_68 . V_102 &= ~ 0x01 ;
}
static void F_46 ( struct V_5 * V_6 ,
struct V_119 * V_120 )
{
struct V_19 * V_121 = F_12 ( V_6 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_121 -> V_87 ;
F_47 ( V_120 -> V_122 , V_26 , sizeof( V_120 -> V_122 ) ) ;
F_47 ( V_120 -> V_22 , V_123 , sizeof( V_120 -> V_22 ) ) ;
F_47 ( V_120 -> V_124 , F_48 ( V_1 ) , sizeof( V_120 -> V_124 ) ) ;
}
static V_62 F_49 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_12 ( V_6 ) ;
return V_20 -> V_38 ;
}
static void F_50 ( struct V_5 * V_6 , V_62 V_125 )
{
struct V_19 * V_20 = F_12 ( V_6 ) ;
V_20 -> V_38 = V_125 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_52 ( V_2 ) ;
F_53 ( ! V_6 ) ;
F_54 ( V_6 ) ;
F_23 ( V_6 -> V_67 , V_25 ) ;
F_22 ( V_6 ) ;
F_55 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 , T_2 V_126 )
{
struct V_5 * V_6 = F_52 ( V_2 ) ;
F_57 ( V_6 ) ;
F_58 ( V_2 ) ;
F_55 ( V_2 ) ;
F_59 ( V_2 , F_60 ( V_2 , V_126 ) ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_52 ( V_2 ) ;
int V_127 ;
F_59 ( V_2 , V_128 ) ;
F_62 ( V_2 ) ;
V_127 = F_4 ( V_2 ) ;
if ( V_127 )
return V_127 ;
F_19 ( V_6 , 1 ) ;
F_63 ( V_6 ) ;
return 0 ;
}
static int T_3 F_64 ( void )
{
#ifdef F_2
F_3 ( V_22 ) ;
#endif
return F_65 ( & V_129 ) ;
}
static void T_4 F_66 ( void )
{
F_67 ( & V_129 ) ;
}
