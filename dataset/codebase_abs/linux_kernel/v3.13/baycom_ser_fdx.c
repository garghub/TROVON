static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
unsigned long V_3 = V_4 ;
V_2 -> V_5 . V_6 ++ ;
if ( F_3 ( V_3 , V_2 -> V_5 . V_7 + V_8 ) ) {
V_2 -> V_5 . V_7 = V_3 ;
V_2 -> V_5 . V_9 = V_2 -> V_5 . V_6 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_10 = V_2 -> V_5 . V_11 ;
V_2 -> V_5 . V_11 = 0 ;
}
#endif
}
static inline void F_4 ( struct V_12 * V_13 ,
unsigned int V_14 )
{
F_5 ( 0x81 , F_6 ( V_13 -> V_15 ) ) ;
F_5 ( V_14 , F_7 ( V_13 -> V_15 ) ) ;
F_5 ( V_14 >> 8 , F_8 ( V_13 -> V_15 ) ) ;
F_5 ( 0x01 , F_6 ( V_13 -> V_15 ) ) ;
F_5 ( 0x00 , F_9 ( V_13 -> V_15 ) ) ;
}
static T_1 void F_10 ( struct V_12 * V_13 , struct V_1 * V_2 , struct V_16 * V_17 , unsigned char V_18 )
{
int V_19 ;
int V_20 = V_2 -> V_21 >> 3 ;
int V_22 = V_2 -> V_21 >> 2 ;
int V_23 = V_2 -> V_21 >> 1 ;
V_19 = 1000000 + V_17 -> V_24 - V_2 -> V_25 . V_26 . V_27 ;
while ( V_19 >= 500000 )
V_19 -= 1000000 ;
while ( V_19 >= V_23 ) {
V_19 -= V_2 -> V_21 ;
V_2 -> V_25 . V_26 . V_27 += V_2 -> V_21 ;
V_2 -> V_25 . V_26 . V_28 -- ;
if ( V_2 -> V_25 . V_29 & 1 ) {
F_11 ( & V_2 -> V_30 , ( V_2 -> V_25 . V_29 >> 1 ) ^ 0xffff ) ;
V_2 -> V_25 . V_29 = 0x10000 ;
}
V_2 -> V_25 . V_29 >>= 1 ;
}
if ( V_2 -> V_25 . V_26 . V_28 <= 0 ) {
if ( ! V_2 -> V_31 )
F_12 ( & V_2 -> V_30 , ( V_2 -> V_25 . V_26 . V_32 +
V_2 -> V_25 . V_26 . V_33 +
V_2 -> V_25 . V_26 . V_34 ) < 0 ) ;
V_2 -> V_25 . V_26 . V_34 = V_2 -> V_25 . V_26 . V_33 ;
V_2 -> V_25 . V_26 . V_33 = V_2 -> V_25 . V_26 . V_32 ;
V_2 -> V_25 . V_26 . V_32 = 2 ;
V_2 -> V_25 . V_26 . V_28 += 120 ;
}
if ( V_2 -> V_25 . V_26 . V_35 != V_18 ) {
V_2 -> V_25 . V_26 . V_35 = V_18 ;
V_2 -> V_25 . V_29 |= 0x10000 ;
if ( V_19 > 0 )
V_2 -> V_25 . V_26 . V_27 += V_20 ;
else
V_2 -> V_25 . V_26 . V_27 += 1000000 - V_20 ;
if ( abs ( V_19 ) > V_22 )
V_2 -> V_25 . V_26 . V_32 += 4 ;
else
V_2 -> V_25 . V_26 . V_32 -- ;
#ifdef F_2
V_2 -> V_5 . V_11 = V_19 ;
#endif
}
while ( V_2 -> V_25 . V_26 . V_27 >= 1000000 )
V_2 -> V_25 . V_26 . V_27 -= 1000000 ;
}
static T_2 F_13 ( int V_36 , void * V_37 )
{
struct V_12 * V_13 = (struct V_12 * ) V_37 ;
struct V_1 * V_2 = F_14 ( V_13 ) ;
struct V_16 V_17 ;
unsigned char V_38 , V_39 ;
unsigned int V_40 = 0 ;
if ( ! V_2 || V_2 -> V_30 . V_41 != V_42 )
return V_43 ;
if ( ( V_38 = F_15 ( F_16 ( V_13 -> V_15 ) ) ) & 1 )
return V_43 ;
F_17 ( & V_17 ) ;
V_39 = F_15 ( F_18 ( V_13 -> V_15 ) ) ;
if ( ( V_39 & 8 ) && V_2 -> V_31 )
F_12 ( & V_2 -> V_30 , ! ( ( V_39 ^ V_2 -> V_31 ) & 0x80 ) ) ;
do {
switch ( V_38 & 6 ) {
case 6 :
F_15 ( F_19 ( V_13 -> V_15 ) ) ;
break;
case 4 :
F_15 ( F_20 ( V_13 -> V_15 ) ) ;
break;
case 2 :
F_5 ( 0x00 , F_9 ( V_13 -> V_15 ) ) ;
F_1 ( V_2 ) ;
V_40 ++ ;
if ( V_2 -> V_25 . V_44 )
F_5 ( 0x0e | ( ! ! V_2 -> V_25 . V_26 . V_45 ) , F_21 ( V_13 -> V_15 ) ) ;
else
F_5 ( 0x0d , F_21 ( V_13 -> V_15 ) ) ;
break;
default:
V_39 = F_15 ( F_18 ( V_13 -> V_15 ) ) ;
if ( ( V_39 & 8 ) && V_2 -> V_31 )
F_12 ( & V_2 -> V_30 , ! ( ( V_39 ^ V_2 -> V_31 ) & 0x80 ) ) ;
break;
}
V_38 = F_15 ( F_16 ( V_13 -> V_15 ) ) ;
} while ( ! ( V_38 & 1 ) );
F_10 ( V_13 , V_2 , & V_17 , V_39 & 0x10 ) ;
if ( V_2 -> V_25 . V_44 && V_40 ) {
if ( V_2 -> V_25 . V_26 . V_46 <= 1 ) {
V_2 -> V_25 . V_26 . V_46 = 0x10000 | F_22 ( & V_2 -> V_30 ) ;
if ( ! F_23 ( & V_2 -> V_30 ) ) {
F_4 ( V_13 , 115200 / 100 / 8 ) ;
V_2 -> V_25 . V_44 = 0 ;
goto V_47;
}
}
V_2 -> V_25 . V_26 . V_45 = ! ( V_2 -> V_25 . V_26 . V_45 ^ ( V_2 -> V_25 . V_26 . V_46 & 1 ) ) ;
V_2 -> V_25 . V_26 . V_46 >>= 1 ;
}
V_47:
F_24 () ;
if ( ! V_2 -> V_25 . V_44 && V_40 ) {
F_25 ( V_13 , & V_2 -> V_30 ) ;
if ( F_23 ( & V_2 -> V_30 ) ) {
F_4 ( V_13 , V_2 -> V_48 ) ;
V_2 -> V_25 . V_26 . V_46 = 1 ;
V_2 -> V_25 . V_44 = 1 ;
}
}
F_26 ( V_13 , & V_2 -> V_30 ) ;
F_27 ( V_13 , & V_2 -> V_30 ) ;
F_28 () ;
return V_49 ;
}
static enum V_50 F_29 ( unsigned int V_51 )
{
unsigned char V_52 , V_53 , V_54 ;
enum V_50 V_55 ;
enum V_50 V_56 [] =
{ V_57 , V_58 , V_59 , V_60 } ;
V_52 = F_15 ( F_21 ( V_51 ) ) ;
F_5 ( V_52 | 0x10 , F_21 ( V_51 ) ) ;
V_53 = F_15 ( F_18 ( V_51 ) ) ;
F_5 ( 0x1a , F_21 ( V_51 ) ) ;
V_54 = F_15 ( F_18 ( V_51 ) ) & 0xf0 ;
F_5 ( V_52 , F_21 ( V_51 ) ) ;
F_5 ( V_53 , F_18 ( V_51 ) ) ;
if ( V_54 != 0x90 )
return V_58 ;
F_15 ( F_20 ( V_51 ) ) ;
F_15 ( F_20 ( V_51 ) ) ;
F_5 ( 0x01 , F_30 ( V_51 ) ) ;
V_55 = V_56 [ ( F_15 ( F_16 ( V_51 ) ) >> 6 ) & 3 ] ;
if ( V_55 == V_57 ) {
F_5 ( 0x5a , F_31 ( V_51 ) ) ;
V_52 = F_15 ( F_31 ( V_51 ) ) ;
F_5 ( 0xa5 , F_31 ( V_51 ) ) ;
V_53 = F_15 ( F_31 ( V_51 ) ) ;
if ( ( V_52 != 0x5a ) || ( V_53 != 0xa5 ) )
V_55 = V_61 ;
}
return V_55 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
enum V_50 V_55 ;
if ( ! V_13 || ! V_2 )
return - V_62 ;
if ( ! V_13 -> V_15 || V_13 -> V_15 > 0xffff - V_63 ||
V_13 -> V_36 < 2 || V_13 -> V_36 > V_64 ) {
F_33 ( V_65 L_1
L_2 ,
0xffff - V_63 , V_64 ) ;
return - V_62 ;
}
if ( V_2 -> V_66 < 300 || V_2 -> V_66 > 4800 ) {
F_33 ( V_65 L_3
L_4 ) ;
return - V_67 ;
}
if ( ! F_34 ( V_13 -> V_15 , V_63 , L_5 ) ) {
F_33 ( V_68 L_6 ,
V_13 -> V_15 ) ;
return - V_69 ;
}
memset ( & V_2 -> V_25 , 0 , sizeof( V_2 -> V_25 ) ) ;
V_2 -> V_30 . V_70 . V_71 = V_2 -> V_66 ;
V_2 -> V_21 = 1000000 / V_2 -> V_66 ;
V_2 -> V_48 = ( 115200 / 8 ) / V_2 -> V_66 ;
if ( ( V_55 = F_29 ( V_13 -> V_15 ) ) == V_58 ) {
F_35 ( V_13 -> V_15 , V_63 ) ;
return - V_72 ;
}
F_5 ( 0 , F_30 ( V_13 -> V_15 ) ) ;
F_5 ( 0x0d , F_21 ( V_13 -> V_15 ) ) ;
F_5 ( 0 , F_36 ( V_13 -> V_15 ) ) ;
if ( F_37 ( V_13 -> V_36 , F_13 , V_73 ,
L_5 , V_13 ) ) {
F_35 ( V_13 -> V_15 , V_63 ) ;
return - V_74 ;
}
F_4 ( V_13 , 115200 / 100 / 8 ) ;
F_5 ( 0x0a , F_36 ( V_13 -> V_15 ) ) ;
F_5 ( 0x00 , F_9 ( V_13 -> V_15 ) ) ;
F_12 ( & V_2 -> V_30 , 0 ) ;
F_33 ( V_65 L_7 ,
V_75 , V_13 -> V_15 , V_13 -> V_36 , V_2 -> V_66 , V_76 [ V_55 ] ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
if ( ! V_13 || ! V_2 )
return - V_67 ;
F_5 ( 0 , F_36 ( V_13 -> V_15 ) ) ;
F_5 ( 1 , F_21 ( V_13 -> V_15 ) ) ;
F_39 ( V_13 -> V_36 , V_13 ) ;
F_35 ( V_13 -> V_15 , V_63 ) ;
F_33 ( V_65 L_8 ,
V_75 , V_13 -> V_15 , V_13 -> V_36 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const char * V_77 )
{
unsigned int V_66 ;
if ( ! strncmp ( V_77 , L_9 , 3 ) ) {
V_66 = F_41 ( V_77 + 3 , NULL , 10 ) ;
if ( V_66 >= 3 && V_66 <= 48 )
V_2 -> V_66 = V_66 * 100 ;
}
if ( strchr ( V_77 , '*' ) )
V_2 -> V_31 = 0 ;
else if ( strchr ( V_77 , '+' ) )
V_2 -> V_31 = - 1 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
static int F_42 ( struct V_12 * V_13 , struct V_78 * V_79 ,
struct V_80 * V_81 , int V_82 )
{
struct V_1 * V_2 ;
struct F_42 V_83 ;
if ( ! V_13 )
return - V_67 ;
V_2 = F_14 ( V_13 ) ;
F_43 ( V_2 -> V_30 . V_41 != V_42 ) ;
if ( V_82 != V_84 )
return - V_85 ;
switch ( V_81 -> V_82 ) {
default:
break;
case V_86 :
sprintf ( V_81 -> V_87 . V_88 , L_10 , V_2 -> V_66 / 100 ) ;
if ( V_2 -> V_31 <= 0 )
strcat ( V_81 -> V_87 . V_88 , ( ! V_2 -> V_31 ) ? L_11 : L_12 ) ;
if ( F_44 ( V_79 -> V_89 , V_81 , sizeof( struct V_80 ) ) )
return - V_90 ;
return 0 ;
case V_91 :
if ( F_45 ( V_13 ) || ! F_46 ( V_92 ) )
return - V_69 ;
V_81 -> V_87 . V_88 [ sizeof( V_81 -> V_87 . V_88 ) - 1 ] = '\0' ;
return F_40 ( V_2 , V_81 -> V_87 . V_88 ) ;
case V_93 :
strcpy ( V_81 -> V_87 . V_88 , L_13 ) ;
if ( F_44 ( V_79 -> V_89 , V_81 , sizeof( struct V_80 ) ) )
return - V_90 ;
return 0 ;
case V_94 :
return V_95 | V_96 ;
}
if ( F_47 ( & V_83 , V_79 -> V_89 , sizeof( V_83 ) ) )
return - V_90 ;
switch ( V_83 . V_82 ) {
default:
return - V_85 ;
#ifdef F_2
case V_97 :
V_83 . V_87 . V_98 . V_99 = V_2 -> V_30 . V_100 ;
V_83 . V_87 . V_98 . V_101 = V_2 -> V_5 . V_9 ;
V_83 . V_87 . V_98 . V_102 = V_2 -> V_5 . V_10 ;
break;
#endif
}
if ( F_44 ( V_79 -> V_89 , & V_83 , sizeof( V_83 ) ) )
return - V_90 ;
return 0 ;
}
static int T_3 F_48 ( void )
{
int V_103 , V_104 = 0 ;
char V_105 = 1 ;
F_33 ( V_106 ) ;
for ( V_103 = 0 ; V_103 < V_107 ; V_103 ++ ) {
struct V_12 * V_13 ;
struct V_1 * V_2 ;
char V_108 [ V_109 ] ;
sprintf ( V_108 , L_14 , V_103 ) ;
if ( ! V_110 [ V_103 ] )
V_105 = 0 ;
if ( ! V_105 )
V_51 [ V_103 ] = V_36 [ V_103 ] = 0 ;
V_13 = F_49 ( & V_111 ,
sizeof( struct V_1 ) ,
V_108 , V_51 [ V_103 ] , V_36 [ V_103 ] , 0 ) ;
if ( F_50 ( V_13 ) )
break;
V_2 = F_14 ( V_13 ) ;
if ( V_105 && F_40 ( V_2 , V_110 [ V_103 ] ) )
V_105 = 0 ;
V_2 -> V_66 = V_66 [ V_103 ] ;
V_104 ++ ;
V_112 [ V_103 ] = V_13 ;
}
if ( ! V_104 )
return - V_62 ;
return 0 ;
}
static void T_4 F_51 ( void )
{
int V_103 ;
for( V_103 = 0 ; V_103 < V_107 ; V_103 ++ ) {
struct V_12 * V_13 = V_112 [ V_103 ] ;
if ( V_13 )
F_52 ( V_13 ) ;
}
}
static int T_3 F_53 ( char * V_113 )
{
static unsigned V_114 ;
int V_115 [ 4 ] ;
if ( V_114 >= V_107 )
return 0 ;
V_113 = F_54 ( V_113 , 4 , V_115 ) ;
if ( V_115 [ 0 ] < 2 )
return 0 ;
V_110 [ V_114 ] = V_113 ;
V_51 [ V_114 ] = V_115 [ 1 ] ;
V_36 [ V_114 ] = V_115 [ 2 ] ;
if ( V_115 [ 0 ] >= 3 )
V_66 [ V_114 ] = V_115 [ 3 ] ;
V_114 ++ ;
return 1 ;
}
