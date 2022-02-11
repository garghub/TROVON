static inline unsigned char F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( int V_1 , int V_3 )
{
F_4 ( V_2 + V_1 , V_3 ) ;
}
static inline unsigned short F_5 ( unsigned char V_1 )
{
unsigned short V_4 ;
V_5 -> V_6 = V_7 ;
F_6 ( V_8 ) ;
V_4 = V_5 -> V_9 ;
F_6 ( V_8 ) ;
return V_4 ;
}
static inline void F_7 ( unsigned short V_10 , unsigned char V_1 )
{
V_5 -> V_6 = V_1 ;
F_6 ( V_8 ) ;
V_5 -> V_9 = V_10 ;
F_6 ( V_8 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
F_9 ( L_1 ) ;
F_10 ( V_14 ,
F_11 ( F_12 ( V_15 ) ) ) ;
F_10 ( V_16 , V_17 | V_18 ) ;
F_6 ( 50 ) ;
F_10 ( V_16 , V_17 ) ;
F_12 ( V_19 ) ;
for( V_13 = V_20 + V_21 ; F_13 ( V_20 , V_13 ) ; )
F_14 () ;
F_9 ( L_2 ) ;
}
static T_1 F_15 ( int V_22 , void * V_23 )
{
unsigned short V_24 = V_5 -> V_24 ;
int V_25 = 0 ;
#ifdef F_16
V_5 -> V_24 &= ~ V_26 ;
#endif
if( V_24 & ~ V_27 ) {
if( V_24 & V_28 ) {
F_9 ( L_3 , V_29 -> V_30 ) ;
}
if( V_24 & V_31 ) {
F_9 ( L_4 , V_29 -> V_30 ) ;
}
V_25 = 1 ;
}
if( V_24 & ( V_32 | V_33 ) ) {
F_17 ( V_22 , V_23 ) ;
V_25 = 1 ;
}
return F_18 ( V_25 ) ;
}
static unsigned long F_19 ( void * V_34 , unsigned long V_35 , int V_36 )
{
void * V_37 ;
if( V_38 != NULL )
F_20 ( V_38 ) ;
#ifdef F_16
V_37 = ( void * ) F_21 ( ( unsigned long ) V_34 , V_35 ) ;
#else
V_37 = ( void * ) F_22 ( ( unsigned long ) V_34 , V_35 ) ;
#endif
V_38 = V_37 ;
V_39 = V_35 ;
#ifndef F_16
V_5 -> V_40 = 0 ;
F_7 ( V_41 , V_7 ) ;
V_5 -> V_24 &= ~ V_42 ;
V_5 -> V_24 |= V_42 ;
#endif
if( V_36 )
V_5 -> V_24 |= V_43 ;
else
V_5 -> V_24 &= ~ V_43 ;
#ifdef F_16
V_5 -> V_24 |= V_44 ;
V_5 -> V_45 = ( ( unsigned long ) V_37 >> 16 ) ;
V_5 -> V_46 = ( ( unsigned long ) V_37 & 0xffff ) ;
V_5 -> V_47 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_49 = 0 ;
V_5 -> V_40 = 0 ;
#else
V_5 -> V_40 = V_35 ;
F_7 ( V_41 , V_7 ) ;
V_5 -> V_24 &= ~ V_42 ;
V_5 -> V_24 |= V_42 ;
if( V_5 -> V_40 != V_35 ) {
F_9 ( L_5 ,
V_29 -> V_30 , V_5 -> V_40 ,
( unsigned int ) V_35 ) ;
F_23 ( V_50 , V_29 ) ;
}
V_51 -> V_52 = ( ( ( unsigned long ) ( V_37 ) & 0xff0000 ) >> 8 ) ;
V_51 -> V_53 = ( ( unsigned long ) ( V_37 ) & 0xffff ) ;
V_51 -> V_35 = V_35 / 2 ;
V_51 -> V_54 = V_55 ;
if( V_36 ) {
if( V_35 & 1 )
V_51 -> V_35 ++ ;
V_51 -> V_56 = V_57 ;
V_51 -> V_58 = V_59 ;
} else {
V_51 -> V_56 = V_60 ;
V_51 -> V_58 = V_61 ;
}
F_7 ( ( ( F_24 ( V_51 ) & 0xff0000 ) >> 8 ) ,
V_62 ) ;
F_7 ( ( F_24 ( V_51 ) & 0xffff ) , V_63 ) ;
F_7 ( 0xd , V_64 ) ;
F_7 ( V_65 , V_7 ) ;
#endif
return V_35 ;
}
static inline unsigned long F_25 ( struct V_11 * V_12 )
{
unsigned short V_66 ;
V_5 -> V_6 = 0x32 ;
F_6 ( V_8 ) ;
V_66 = V_5 -> V_9 ;
F_6 ( V_8 ) ;
V_66 *= 2 ;
return ( unsigned long ) V_66 ;
}
static inline unsigned long F_26 ( struct V_11 * V_12 )
{
return V_67 ;
}
static inline unsigned long F_27 ( unsigned long V_68 ,
struct V_69 * V_70 ,
int V_36 )
{
if ( V_70 -> V_71 -> V_72 == V_73 )
return V_68 ;
else
return 0 ;
}
static inline int F_28 ( unsigned long V_35 , unsigned char * V_34 )
{
#ifdef F_16
unsigned short V_24 ;
V_24 = V_5 -> V_24 ;
V_5 -> V_47 = ( V_39 >> 16 ) ;
V_5 -> V_48 = ( V_39 & 0xffff ) ;
V_5 -> V_49 = ( V_39 >> 16 ) ;
V_5 -> V_40 = ( V_39 & 0xffff ) ;
#else
F_7 ( V_74 , V_7 ) ;
#endif
return 0 ;
}
static int F_29 ( int V_36 )
{
unsigned short T_2 V_35 ;
unsigned short V_75 ;
int V_4 = 0 ;
V_76 = 0 ;
#ifdef F_16
V_5 -> V_24 &= ~ V_26 ;
V_75 = V_5 -> V_40 ;
if ( V_36 ) {
if ( ( V_75 > 0 ) && ( V_75 < V_39 ) )
V_75 ++ ;
}
V_67 = V_75 ;
if ( ( ! V_36 ) && ( V_5 -> V_24 & V_77 ) ) {
unsigned char * V_78 ;
V_78 = ( unsigned char * ) F_30 ( V_38 ) ;
V_78 += ( V_39 - V_75 ) ;
V_78 -- ;
switch ( V_5 -> V_24 & V_77 ) {
case V_79 :
* V_78 = ( V_5 -> V_80 & 0xff00 ) >> 8 ;
V_78 -- ;
case V_81 :
* V_78 = ( V_5 -> V_82 & 0x00ff ) ;
V_78 -- ;
case V_83 :
* V_78 = ( V_5 -> V_82 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_36 ) {
int V_84 = 20000 ;
while( 1 ) {
if( V_5 -> V_24 & V_85 )
break;
if( -- V_84 <= 0 ) {
F_9 ( L_6 ) ;
return 1 ;
}
F_6 ( 10 ) ;
}
}
V_35 = F_25 ( V_29 ) ;
V_75 = V_5 -> V_40 ;
V_67 = V_75 ;
if( ( ! V_36 ) && ( V_35 - V_75 ) == 2 ) {
unsigned short V_34 ;
unsigned char * V_78 ;
V_34 = V_5 -> V_86 ;
V_78 = ( unsigned char * ) F_31 ( V_38 ) ;
V_78 += ( V_39 - V_75 ) ;
V_78 [ - 2 ] = ( V_34 & 0xff00 ) >> 8 ;
V_78 [ - 1 ] = ( V_34 & 0xff ) ;
}
#endif
F_20 ( V_38 ) ;
V_38 = NULL ;
#ifdef F_16
V_5 -> V_45 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_40 = 0 ;
V_5 -> V_49 = 0 ;
V_5 -> V_24 &= ~ V_43 ;
#else
F_7 ( V_41 , V_7 ) ;
V_5 -> V_40 = 0 ;
V_5 -> V_24 &= ~ V_43 ;
V_5 -> V_24 &= ~ V_42 ;
V_5 -> V_24 |= V_42 ;
#endif
V_87 = NULL ;
return V_4 ;
}
static int T_3 F_32 ( struct V_88 * V_89 )
{
struct V_11 * V_12 ;
int error ;
struct V_90 * V_22 , * V_91 ;
unsigned char * V_92 ;
int V_93 = 0 ;
#ifdef F_16
int V_94 ;
#endif
if ( V_95 > 0 )
V_96 . V_97 = V_95 ;
if ( V_98 > 0 )
V_96 . V_99 = V_98 ;
if ( V_100 >= 0 )
V_96 . V_101 = V_100 ;
if ( V_102 >= 0 )
V_96 . V_103 = V_102 & 7 ;
#ifdef F_16
V_92 = NULL ;
for ( V_94 = 0 ; V_94 < 2 ; V_94 ++ ) {
unsigned char V_104 ;
V_22 = F_33 ( V_89 , V_105 , V_94 ) ;
V_91 = F_33 ( V_89 , V_106 , V_94 ) ;
if ( ! V_22 || ! V_91 )
break;
V_92 = F_34 ( V_91 -> V_107 , F_35 ( V_91 ) ,
V_108 ) ;
V_5 = (struct V_109 * ) ( V_92 + 8 ) ;
if ( F_36 ( ( unsigned long ) V_5 , & V_104 ) ) {
unsigned short V_110 ;
V_110 = V_5 -> V_24 ;
V_5 -> V_24 = 0 ;
F_6 ( V_8 ) ;
if ( V_5 -> V_24 == 0x1400 )
break;
V_5 -> V_24 = V_110 ;
}
F_37 ( V_92 ) ;
V_92 = NULL ;
}
if ( ! V_92 )
return - V_111 ;
#else
V_22 = F_33 ( V_89 , V_105 , 0 ) ;
V_91 = F_33 ( V_89 , V_106 , 0 ) ;
if ( ! V_22 || ! V_91 )
return - V_111 ;
V_92 = F_38 ( V_91 -> V_107 , F_35 ( V_91 ) ) ;
V_5 = (struct V_109 * ) ( V_92 + 8 ) ;
V_51 = F_39 ( sizeof( struct V_112 ) ) ;
if ( ! V_51 ) {
F_40 ( V_113 L_7 ) ;
F_37 ( V_92 ) ;
return - V_114 ;
}
#endif
V_2 = V_92 ;
V_12 = F_41 ( & V_96 ,
sizeof( struct V_115 ) ) ;
if ( ! V_12 ) {
error = - V_114 ;
goto V_116;
}
V_29 = V_12 ;
V_12 -> V_117 = ( unsigned long ) V_92 ;
V_12 -> V_22 = V_22 -> V_107 ;
#ifdef F_42
V_93 |= V_118 > 0 ? V_119 : 0 ;
#endif
F_43 ( V_12 , V_93 ) ;
error = F_44 ( V_12 -> V_22 , F_15 , 0 ,
L_8 , V_12 ) ;
if ( error ) {
#ifdef F_45
F_40 ( V_113 L_9 ,
V_12 -> V_30 , V_12 -> V_22 ) ;
goto V_120;
#else
F_46 ( V_113 L_10 ,
V_12 -> V_30 , V_12 -> V_22 ) ;
V_12 -> V_22 = V_121 ;
#endif
}
V_5 -> V_24 = 0 ;
F_6 ( V_8 ) ;
V_5 -> V_24 = V_122 | V_42 | V_123 ;
F_6 ( V_8 ) ;
V_5 -> V_40 = 0 ;
#ifdef F_16
V_5 -> V_49 = 0 ;
V_5 -> V_45 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_124 = V_125 | ( V_12 -> V_22 & 0xff ) ;
#endif
#ifdef F_47
F_8 ( V_12 ) ;
#endif
error = F_48 ( V_12 , NULL ) ;
if ( error )
goto V_126;
F_49 ( V_89 , V_12 ) ;
F_50 ( V_12 ) ;
return 0 ;
V_126:
if ( V_12 -> V_22 != V_121 )
F_51 ( V_12 -> V_22 , V_12 ) ;
V_120:
F_52 ( V_12 ) ;
F_53 ( V_12 ) ;
V_116:
if ( V_51 )
F_54 ( V_51 ) ;
F_37 ( V_2 ) ;
return error ;
}
static int T_4 F_55 ( struct V_88 * V_89 )
{
struct V_11 * V_12 = F_56 ( V_89 ) ;
F_57 ( V_12 ) ;
if ( V_12 -> V_22 != V_121 )
F_51 ( V_12 -> V_22 , V_12 ) ;
F_52 ( V_12 ) ;
F_53 ( V_12 ) ;
if ( V_51 )
F_54 ( V_51 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
