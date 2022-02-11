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
goto V_24;
}
if ( F_8 ( V_16 , V_25 , V_26 ) == NULL ) {
F_7 ( & V_2 -> V_6 , L_2 ,
V_25 , V_16 ) ;
goto V_24;
}
V_12 = F_9 ( V_16 ) ;
if ( V_12 == 0xFF )
goto V_27;
{
int V_28 ;
F_10 ( V_29 + V_30 + V_31 , V_16 + V_32 ) ;
V_28 = F_9 ( V_16 + 0x0d ) ;
F_10 ( 0xff , V_16 + 0x0d ) ;
F_10 ( V_29 + V_33 , V_16 + V_32 ) ;
F_9 ( V_16 + V_34 ) ;
if ( F_9 ( V_16 + V_34 ) != 0 ) {
F_10 ( V_12 , V_16 ) ;
F_10 ( V_28 , V_16 + 0x0d ) ;
goto V_27;
}
}
V_6 = F_11 () ;
if ( ! V_6 ) {
F_7 ( & V_2 -> V_6 , L_3 ) ;
goto V_27;
}
V_6 -> V_35 = & V_36 ;
V_20 = F_12 ( V_6 ) ;
V_20 -> V_37 = V_38 ;
F_13 ( V_6 , & V_2 -> V_6 ) ;
{
unsigned long V_39 = V_40 ;
F_10 ( F_9 ( V_16 + V_41 ) , V_16 + V_41 ) ;
while ( ( F_9 ( V_16 + V_42 ) & V_43 ) == 0 )
if ( V_40 - V_39 > 2 ) {
F_7 ( & V_2 -> V_6 ,
L_4 ) ;
goto V_44;
}
F_10 ( 0xff , V_16 + V_42 ) ;
}
{
struct { unsigned char V_45 , V_46 ; } V_47 [] = {
{ V_29 + V_33 + V_31 , V_32 } ,
{ 0x49 , V_48 } ,
{ 0x00 , V_49 } ,
{ 0x00 , V_50 } ,
{ 0x00 , V_51 } ,
{ 0xFF , V_42 } ,
{ V_52 , V_53 } ,
{ V_54 , V_55 } ,
{ 32 , V_49 } ,
{ 0x00 , V_50 } ,
{ 0x00 , V_56 } ,
{ 0x00 , V_57 } ,
{ V_58 + V_59 , V_32 } ,
} ;
for ( V_7 = 0 ; V_7 < F_14 ( V_47 ) ; V_7 ++ )
F_10 ( V_47 [ V_7 ] . V_45 , V_16 + V_47 [ V_7 ] . V_46 ) ;
}
if ( V_17 & V_60 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
( ( V_61 * ) V_8 ) [ V_7 ] = F_15 ( F_16 ( V_16 + V_62 ) ) ;
} else
for( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
V_8 [ V_7 ] = F_9 ( V_16 + V_62 ) ;
F_10 ( 0x49 , V_16 + V_48 ) ;
V_9 = V_63 ;
V_10 = V_17 & V_64 ? 0x60 : V_65 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_66 = V_16 ;
F_17 ( V_2 , V_6 ) ;
V_67 . V_68 = V_18 [ V_13 ] . V_68 ;
V_67 . V_69 = V_9 ;
V_67 . V_10 = V_10 ;
V_67 . V_70 = 1 ;
V_67 . V_71 = V_17 ;
if ( V_15 < V_72 ) {
if ( V_73 [ V_15 ] > 0 || ( V_74 [ V_15 ] & V_75 ) )
V_67 . V_71 |= V_75 ;
}
V_67 . V_76 = V_9 + V_77 ;
#ifdef F_18
V_67 . V_10 = V_67 . V_69 + F_18 ;
#endif
V_67 . V_78 = & V_79 ;
V_67 . V_80 = & V_81 ;
V_67 . V_82 = & V_83 ;
V_67 . V_84 = & V_85 ;
V_67 . V_86 = ( unsigned long ) V_2 ;
V_6 -> V_87 = & V_88 ;
F_19 ( V_6 , 0 ) ;
memcpy ( V_6 -> V_89 , V_8 , V_6 -> V_90 ) ;
V_7 = F_20 ( V_6 ) ;
if ( V_7 )
goto V_44;
F_21 ( V_6 , L_5 ,
V_18 [ V_13 ] . V_68 , V_16 , V_6 -> V_11 ,
V_6 -> V_89 ) ;
return 0 ;
V_44:
F_22 ( V_6 ) ;
V_27:
F_23 ( V_16 , V_25 ) ;
V_24:
F_24 ( V_2 ) ;
return - V_91 ;
}
static inline int F_25 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_66 ;
F_10 ( 0xC0 + V_29 , V_16 + V_92 ) ;
F_10 ( 0xC0 , V_16 + 0x01 ) ;
F_10 ( 0x40 , V_16 + 0x06 ) ;
F_10 ( 0x00 , V_16 + 0x01 ) ;
F_10 ( V_33 + V_29 , V_16 + V_92 ) ;
return 0 ;
}
static inline int F_26 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_66 ;
F_10 ( F_9 ( V_16 + 0x20 ) | 0x80 , V_16 + 0x20 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
if ( V_67 . V_71 & V_93 )
return F_25 ( V_6 ) ;
else if ( V_67 . V_71 & V_94 )
return F_26 ( V_6 ) ;
return - V_95 ;
}
static int F_28 ( struct V_5 * V_6 )
{
int V_96 = F_29 ( V_6 -> V_11 , V_97 , V_98 , V_6 -> V_68 , V_6 ) ;
if ( V_96 )
return V_96 ;
if ( V_67 . V_71 & V_75 )
F_27 ( V_6 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_32 ( V_6 ) ;
F_33 ( V_6 -> V_11 , V_6 ) ;
return 0 ;
}
static void V_79 ( struct V_5 * V_6 )
{
unsigned long V_39 = V_40 ;
struct V_19 * V_20 = F_12 ( V_6 ) ;
F_34 ( V_20 , V_99 , V_6 , L_6 ,
V_40 ) ;
F_10 ( F_9 ( V_100 + V_41 ) , V_100 + V_41 ) ;
V_67 . V_101 = 0 ;
V_67 . V_102 = 0 ;
while ( ( F_9 ( V_100 + V_42 ) & V_43 ) == 0 )
if ( V_40 - V_39 > 2 ) {
F_35 ( V_6 , L_7 ) ;
break;
}
F_10 ( V_43 , V_100 + V_42 ) ;
}
static void V_85 ( struct V_5 * V_6 , struct V_103 * V_104 , int V_105 )
{
long V_106 = V_6 -> V_66 ;
if ( V_67 . V_102 ) {
F_35 ( V_6 , L_8
L_9 ,
V_67 . V_102 , V_67 . V_107 ) ;
return;
}
V_67 . V_102 |= 0x01 ;
F_10 ( V_29 + V_33 + V_59 , V_106 + V_92 ) ;
F_10 ( sizeof( struct V_103 ) , V_106 + V_49 ) ;
F_10 ( 0 , V_106 + V_50 ) ;
F_10 ( 0 , V_106 + V_56 ) ;
F_10 ( V_105 , V_106 + V_57 ) ;
F_10 ( V_58 + V_59 , V_106 + V_92 ) ;
if ( V_67 . V_71 & V_108 ) {
F_36 ( V_100 + V_62 , V_104 , sizeof( struct V_103 ) >> 1 ) ;
} else {
* ( V_61 * ) V_104 = F_15 ( F_16 ( V_100 + V_62 ) ) ;
F_37 ( & V_104 -> V_109 ) ;
}
F_10 ( V_110 , V_106 + V_42 ) ;
V_67 . V_102 &= ~ 0x01 ;
}
static void V_81 ( struct V_5 * V_6 , int V_109 ,
struct V_111 * V_112 , int V_113 )
{
long V_106 = V_6 -> V_66 ;
char * V_114 = V_112 -> V_115 ;
if ( V_67 . V_102 ) {
F_35 ( V_6 , L_10
L_9 ,
V_67 . V_102 , V_67 . V_107 ) ;
return;
}
V_67 . V_102 |= 0x01 ;
if ( V_67 . V_71 & V_60 )
V_109 = ( V_109 + 3 ) & 0xFFFC ;
F_10 ( V_29 + V_33 + V_59 , V_106 + V_92 ) ;
F_10 ( V_109 & 0xff , V_106 + V_49 ) ;
F_10 ( V_109 >> 8 , V_106 + V_50 ) ;
F_10 ( V_113 & 0xff , V_106 + V_56 ) ;
F_10 ( V_113 >> 8 , V_106 + V_57 ) ;
F_10 ( V_58 + V_59 , V_106 + V_92 ) ;
if ( V_67 . V_71 & V_108 ) {
F_36 ( V_100 + V_62 , V_114 , V_109 >> 1 ) ;
if ( V_109 & 0x01 ) {
V_114 [ V_109 - 1 ] = F_9 ( V_100 + V_62 ) ;
}
} else {
F_38 ( V_100 + V_62 , V_114 , V_109 >> 2 ) ;
if ( V_109 & 3 ) {
V_114 += V_109 & ~ 3 ;
if ( V_109 & 2 ) {
T_1 * V_116 = ( T_1 * ) V_114 ;
* V_116 ++ = F_39 ( F_40 ( V_100 + V_62 ) ) ;
V_114 = ( char * ) V_116 ;
}
if ( V_109 & 1 )
* V_114 = F_9 ( V_100 + V_62 ) ;
}
}
F_10 ( V_110 , V_106 + V_42 ) ;
V_67 . V_102 &= ~ 0x01 ;
}
static void V_83 ( struct V_5 * V_6 , int V_109 ,
const unsigned char * V_114 , const int V_9 )
{
long V_106 = V_100 ;
unsigned long V_117 ;
if ( V_67 . V_71 & V_60 )
V_109 = ( V_109 + 3 ) & 0xFFFC ;
else
if ( V_109 & 0x01 )
V_109 ++ ;
if ( V_67 . V_102 ) {
F_35 ( V_6 , L_11
L_12 ,
V_67 . V_102 , V_67 . V_107 ) ;
return;
}
V_67 . V_102 |= 0x01 ;
F_10 ( V_33 + V_59 + V_29 , V_106 + V_92 ) ;
#ifdef F_41
F_10 ( 0x42 , V_106 + V_49 ) ;
F_10 ( 0x00 , V_106 + V_50 ) ;
F_10 ( 0x42 , V_106 + V_56 ) ;
F_10 ( 0x00 , V_106 + V_57 ) ;
F_10 ( V_58 + V_59 , V_106 + V_92 ) ;
#endif
F_10 ( V_110 , V_106 + V_42 ) ;
F_10 ( V_109 & 0xff , V_106 + V_49 ) ;
F_10 ( V_109 >> 8 , V_106 + V_50 ) ;
F_10 ( 0x00 , V_106 + V_56 ) ;
F_10 ( V_9 , V_106 + V_57 ) ;
F_10 ( V_118 + V_59 , V_106 + V_92 ) ;
if ( V_67 . V_71 & V_108 ) {
F_42 ( V_100 + V_62 , V_114 , V_109 >> 1 ) ;
} else {
F_43 ( V_100 + V_62 , V_114 , V_109 >> 2 ) ;
if ( V_109 & 3 ) {
V_114 += V_109 & ~ 3 ;
if ( V_109 & 2 ) {
T_1 * V_116 = ( T_1 * ) V_114 ;
F_44 ( F_45 ( * V_116 ++ ) , V_100 + V_62 ) ;
V_114 = ( char * ) V_116 ;
}
}
}
V_117 = V_40 ;
while ( ( F_9 ( V_106 + V_42 ) & V_110 ) == 0 )
if ( V_40 - V_117 > 2 ) {
F_46 ( V_6 , L_13 ) ;
V_79 ( V_6 ) ;
F_19 ( V_6 , 1 ) ;
break;
}
F_10 ( V_110 , V_106 + V_42 ) ;
V_67 . V_102 &= ~ 0x01 ;
}
static void F_47 ( struct V_5 * V_6 ,
struct V_119 * V_120 )
{
struct V_19 * V_121 = F_12 ( V_6 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_121 -> V_86 ;
F_48 ( V_120 -> V_122 , V_26 , sizeof( V_120 -> V_122 ) ) ;
F_48 ( V_120 -> V_22 , V_123 , sizeof( V_120 -> V_22 ) ) ;
F_48 ( V_120 -> V_124 , F_49 ( V_1 ) , sizeof( V_120 -> V_124 ) ) ;
}
static V_61 F_50 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_12 ( V_6 ) ;
return V_20 -> V_37 ;
}
static void F_51 ( struct V_5 * V_6 , V_61 V_125 )
{
struct V_19 * V_20 = F_12 ( V_6 ) ;
V_20 -> V_37 = V_125 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_53 ( V_2 ) ;
F_54 ( ! V_6 ) ;
F_55 ( V_6 ) ;
F_23 ( V_6 -> V_66 , V_25 ) ;
F_22 ( V_6 ) ;
F_24 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 , T_2 V_126 )
{
struct V_5 * V_6 = F_53 ( V_2 ) ;
F_57 ( V_6 ) ;
F_58 ( V_2 ) ;
F_24 ( V_2 ) ;
F_59 ( V_2 , F_60 ( V_2 , V_126 ) ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_53 ( V_2 ) ;
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
