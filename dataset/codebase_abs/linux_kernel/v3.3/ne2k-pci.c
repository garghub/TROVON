static int T_1 F_1 ( struct V_1 * V_2 ,
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
#ifndef F_2
static int V_19 ;
if ( ! V_19 ++ )
F_3 ( V_20 ) ;
#endif
V_15 ++ ;
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_16 = F_5 ( V_2 , 0 ) ;
V_11 = V_2 -> V_11 ;
if ( ! V_16 || ( ( F_6 ( V_2 , 0 ) & V_21 ) == 0 ) ) {
F_7 ( & V_2 -> V_6 , L_1 ) ;
return - V_22 ;
}
if ( F_8 ( V_16 , V_23 , V_24 ) == NULL ) {
F_7 ( & V_2 -> V_6 , L_2 ,
V_23 , V_16 ) ;
return - V_25 ;
}
V_12 = F_9 ( V_16 ) ;
if ( V_12 == 0xFF )
goto V_26;
{
int V_27 ;
F_10 ( V_28 + V_29 + V_30 , V_16 + V_31 ) ;
V_27 = F_9 ( V_16 + 0x0d ) ;
F_10 ( 0xff , V_16 + 0x0d ) ;
F_10 ( V_28 + V_32 , V_16 + V_31 ) ;
F_9 ( V_16 + V_33 ) ;
if ( F_9 ( V_16 + V_33 ) != 0 ) {
F_10 ( V_12 , V_16 ) ;
F_10 ( V_27 , V_16 + 0x0d ) ;
goto V_26;
}
}
V_6 = F_11 () ;
if ( ! V_6 ) {
F_7 ( & V_2 -> V_6 , L_3 ) ;
goto V_26;
}
V_6 -> V_34 = & V_35 ;
F_12 ( V_6 , & V_2 -> V_6 ) ;
{
unsigned long V_36 = V_37 ;
F_10 ( F_9 ( V_16 + V_38 ) , V_16 + V_38 ) ;
while ( ( F_9 ( V_16 + V_39 ) & V_40 ) == 0 )
if ( V_37 - V_36 > 2 ) {
F_7 ( & V_2 -> V_6 ,
L_4 ) ;
goto V_41;
}
F_10 ( 0xff , V_16 + V_39 ) ;
}
{
struct { unsigned char V_42 , V_43 ; } V_44 [] = {
{ V_28 + V_32 + V_30 , V_31 } ,
{ 0x49 , V_45 } ,
{ 0x00 , V_46 } ,
{ 0x00 , V_47 } ,
{ 0x00 , V_48 } ,
{ 0xFF , V_39 } ,
{ V_49 , V_50 } ,
{ V_51 , V_52 } ,
{ 32 , V_46 } ,
{ 0x00 , V_47 } ,
{ 0x00 , V_53 } ,
{ 0x00 , V_54 } ,
{ V_55 + V_56 , V_31 } ,
} ;
for ( V_7 = 0 ; V_7 < F_13 ( V_44 ) ; V_7 ++ )
F_10 ( V_44 [ V_7 ] . V_42 , V_16 + V_44 [ V_7 ] . V_43 ) ;
}
if ( V_17 & V_57 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
( ( V_58 * ) V_8 ) [ V_7 ] = F_14 ( F_15 ( V_16 + V_59 ) ) ;
} else
for( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
V_8 [ V_7 ] = F_9 ( V_16 + V_59 ) ;
F_10 ( 0x49 , V_16 + V_45 ) ;
V_9 = V_60 ;
V_10 = V_17 & V_61 ? 0x60 : V_62 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_63 = V_16 ;
F_16 ( V_2 , V_6 ) ;
V_64 . V_65 = V_18 [ V_13 ] . V_65 ;
V_64 . V_66 = V_9 ;
V_64 . V_10 = V_10 ;
V_64 . V_67 = 1 ;
V_64 . V_68 = V_17 ;
if ( V_15 < V_69 ) {
if ( V_70 [ V_15 ] > 0 || ( V_71 [ V_15 ] & V_72 ) )
V_64 . V_68 |= V_72 ;
}
V_64 . V_73 = V_9 + V_74 ;
#ifdef F_17
V_64 . V_10 = V_64 . V_66 + F_17 ;
#endif
V_64 . V_75 = & V_76 ;
V_64 . V_77 = & V_78 ;
V_64 . V_79 = & V_80 ;
V_64 . V_81 = & V_82 ;
V_64 . V_83 = ( unsigned long ) V_2 ;
V_6 -> V_84 = & V_85 ;
F_18 ( V_6 , 0 ) ;
memcpy ( V_6 -> V_86 , V_8 , V_6 -> V_87 ) ;
memcpy ( V_6 -> V_88 , V_6 -> V_86 , V_6 -> V_87 ) ;
V_7 = F_19 ( V_6 ) ;
if ( V_7 )
goto V_41;
F_3 ( L_5 ,
V_6 -> V_65 , V_18 [ V_13 ] . V_65 , V_16 , V_6 -> V_11 ,
V_6 -> V_86 ) ;
return 0 ;
V_41:
F_20 ( V_6 ) ;
V_26:
F_21 ( V_16 , V_23 ) ;
F_16 ( V_2 , NULL ) ;
return - V_22 ;
}
static inline int F_22 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_63 ;
F_10 ( 0xC0 + V_28 , V_16 + V_89 ) ;
F_10 ( 0xC0 , V_16 + 0x01 ) ;
F_10 ( 0x40 , V_16 + 0x06 ) ;
F_10 ( 0x00 , V_16 + 0x01 ) ;
F_10 ( V_32 + V_28 , V_16 + V_89 ) ;
return 0 ;
}
static inline int F_23 ( struct V_5 * V_6 )
{
long V_16 = V_6 -> V_63 ;
F_10 ( F_9 ( V_16 + 0x20 ) | 0x80 , V_16 + 0x20 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
if ( V_64 . V_68 & V_90 )
return F_22 ( V_6 ) ;
else if ( V_64 . V_68 & V_91 )
return F_23 ( V_6 ) ;
return - V_92 ;
}
static int F_25 ( struct V_5 * V_6 )
{
int V_93 = F_26 ( V_6 -> V_11 , V_94 , V_95 , V_6 -> V_65 , V_6 ) ;
if ( V_93 )
return V_93 ;
if ( V_64 . V_68 & V_72 )
F_24 ( V_6 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_30 ( V_6 -> V_11 , V_6 ) ;
return 0 ;
}
static void V_76 ( struct V_5 * V_6 )
{
unsigned long V_36 = V_37 ;
if ( V_96 > 1 ) F_3 ( L_6 ,
V_6 -> V_65 , V_37 ) ;
F_10 ( F_9 ( V_97 + V_38 ) , V_97 + V_38 ) ;
V_64 . V_98 = 0 ;
V_64 . V_99 = 0 ;
while ( ( F_9 ( V_97 + V_39 ) & V_40 ) == 0 )
if ( V_37 - V_36 > 2 ) {
F_3 ( L_7 , V_6 -> V_65 ) ;
break;
}
F_10 ( V_40 , V_97 + V_39 ) ;
}
static void V_82 ( struct V_5 * V_6 , struct V_100 * V_101 , int V_102 )
{
long V_103 = V_6 -> V_63 ;
if ( V_64 . V_99 ) {
F_3 ( L_8
L_9 ,
V_6 -> V_65 , V_64 . V_99 , V_64 . V_104 ) ;
return;
}
V_64 . V_99 |= 0x01 ;
F_10 ( V_28 + V_32 + V_56 , V_103 + V_89 ) ;
F_10 ( sizeof( struct V_100 ) , V_103 + V_46 ) ;
F_10 ( 0 , V_103 + V_47 ) ;
F_10 ( 0 , V_103 + V_53 ) ;
F_10 ( V_102 , V_103 + V_54 ) ;
F_10 ( V_55 + V_56 , V_103 + V_89 ) ;
if ( V_64 . V_68 & V_105 ) {
F_31 ( V_97 + V_59 , V_101 , sizeof( struct V_100 ) >> 1 ) ;
} else {
* ( V_58 * ) V_101 = F_14 ( F_15 ( V_97 + V_59 ) ) ;
F_32 ( & V_101 -> V_106 ) ;
}
F_10 ( V_107 , V_103 + V_39 ) ;
V_64 . V_99 &= ~ 0x01 ;
}
static void V_78 ( struct V_5 * V_6 , int V_106 ,
struct V_108 * V_109 , int V_110 )
{
long V_103 = V_6 -> V_63 ;
char * V_111 = V_109 -> V_112 ;
if ( V_64 . V_99 ) {
F_3 ( L_10
L_9 ,
V_6 -> V_65 , V_64 . V_99 , V_64 . V_104 ) ;
return;
}
V_64 . V_99 |= 0x01 ;
if ( V_64 . V_68 & V_57 )
V_106 = ( V_106 + 3 ) & 0xFFFC ;
F_10 ( V_28 + V_32 + V_56 , V_103 + V_89 ) ;
F_10 ( V_106 & 0xff , V_103 + V_46 ) ;
F_10 ( V_106 >> 8 , V_103 + V_47 ) ;
F_10 ( V_110 & 0xff , V_103 + V_53 ) ;
F_10 ( V_110 >> 8 , V_103 + V_54 ) ;
F_10 ( V_55 + V_56 , V_103 + V_89 ) ;
if ( V_64 . V_68 & V_105 ) {
F_31 ( V_97 + V_59 , V_111 , V_106 >> 1 ) ;
if ( V_106 & 0x01 ) {
V_111 [ V_106 - 1 ] = F_9 ( V_97 + V_59 ) ;
}
} else {
F_33 ( V_97 + V_59 , V_111 , V_106 >> 2 ) ;
if ( V_106 & 3 ) {
V_111 += V_106 & ~ 3 ;
if ( V_106 & 2 ) {
T_2 * V_113 = ( T_2 * ) V_111 ;
* V_113 ++ = F_34 ( F_35 ( V_97 + V_59 ) ) ;
V_111 = ( char * ) V_113 ;
}
if ( V_106 & 1 )
* V_111 = F_9 ( V_97 + V_59 ) ;
}
}
F_10 ( V_107 , V_103 + V_39 ) ;
V_64 . V_99 &= ~ 0x01 ;
}
static void V_80 ( struct V_5 * V_6 , int V_106 ,
const unsigned char * V_111 , const int V_9 )
{
long V_103 = V_97 ;
unsigned long V_114 ;
if ( V_64 . V_68 & V_57 )
V_106 = ( V_106 + 3 ) & 0xFFFC ;
else
if ( V_106 & 0x01 )
V_106 ++ ;
if ( V_64 . V_99 ) {
F_3 ( L_11
L_12 ,
V_6 -> V_65 , V_64 . V_99 , V_64 . V_104 ) ;
return;
}
V_64 . V_99 |= 0x01 ;
F_10 ( V_32 + V_56 + V_28 , V_103 + V_89 ) ;
#ifdef F_36
F_10 ( 0x42 , V_103 + V_46 ) ;
F_10 ( 0x00 , V_103 + V_47 ) ;
F_10 ( 0x42 , V_103 + V_53 ) ;
F_10 ( 0x00 , V_103 + V_54 ) ;
F_10 ( V_55 + V_56 , V_103 + V_89 ) ;
#endif
F_10 ( V_107 , V_103 + V_39 ) ;
F_10 ( V_106 & 0xff , V_103 + V_46 ) ;
F_10 ( V_106 >> 8 , V_103 + V_47 ) ;
F_10 ( 0x00 , V_103 + V_53 ) ;
F_10 ( V_9 , V_103 + V_54 ) ;
F_10 ( V_115 + V_56 , V_103 + V_89 ) ;
if ( V_64 . V_68 & V_105 ) {
F_37 ( V_97 + V_59 , V_111 , V_106 >> 1 ) ;
} else {
F_38 ( V_97 + V_59 , V_111 , V_106 >> 2 ) ;
if ( V_106 & 3 ) {
V_111 += V_106 & ~ 3 ;
if ( V_106 & 2 ) {
T_2 * V_113 = ( T_2 * ) V_111 ;
F_39 ( F_40 ( * V_113 ++ ) , V_97 + V_59 ) ;
V_111 = ( char * ) V_113 ;
}
}
}
V_114 = V_37 ;
while ( ( F_9 ( V_103 + V_39 ) & V_107 ) == 0 )
if ( V_37 - V_114 > 2 ) {
F_3 ( V_116 L_13 , V_6 -> V_65 ) ;
V_76 ( V_6 ) ;
F_18 ( V_6 , 1 ) ;
break;
}
F_10 ( V_107 , V_103 + V_39 ) ;
V_64 . V_99 &= ~ 0x01 ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 = F_42 ( V_6 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_120 -> V_83 ;
F_43 ( V_118 -> V_121 , V_24 , sizeof( V_118 -> V_121 ) ) ;
F_43 ( V_118 -> V_20 , V_122 , sizeof( V_118 -> V_20 ) ) ;
F_43 ( V_118 -> V_123 , F_44 ( V_1 ) , sizeof( V_118 -> V_123 ) ) ;
}
static void T_3 F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_46 ( V_2 ) ;
F_47 ( ! V_6 ) ;
F_48 ( V_6 ) ;
F_21 ( V_6 -> V_63 , V_23 ) ;
F_20 ( V_6 ) ;
F_49 ( V_2 ) ;
F_16 ( V_2 , NULL ) ;
}
static int F_50 ( struct V_1 * V_2 , T_4 V_124 )
{
struct V_5 * V_6 = F_46 ( V_2 ) ;
F_51 ( V_6 ) ;
F_52 ( V_2 ) ;
F_49 ( V_2 ) ;
F_53 ( V_2 , F_54 ( V_2 , V_124 ) ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_46 ( V_2 ) ;
int V_125 ;
F_53 ( V_2 , 0 ) ;
F_56 ( V_2 ) ;
V_125 = F_4 ( V_2 ) ;
if ( V_125 )
return V_125 ;
F_18 ( V_6 , 1 ) ;
F_57 ( V_6 ) ;
return 0 ;
}
static int T_5 F_58 ( void )
{
#ifdef F_2
F_3 ( V_20 ) ;
#endif
return F_59 ( & V_126 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_126 ) ;
}
