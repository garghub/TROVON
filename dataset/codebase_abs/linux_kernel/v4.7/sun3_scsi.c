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
static T_1 F_8 ( int V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
unsigned short V_15 = V_5 -> V_15 ;
int V_16 = 0 ;
#ifdef F_9
V_5 -> V_15 &= ~ V_17 ;
#endif
if( V_15 & ~ V_18 ) {
if ( V_15 & V_19 )
F_10 ( V_20 , V_14 , L_1 ) ;
if ( V_15 & V_21 )
F_10 ( V_20 , V_14 , L_2 ) ;
V_16 = 1 ;
}
if( V_15 & ( V_22 | V_23 ) ) {
F_11 ( V_11 , V_12 ) ;
V_16 = 1 ;
}
return F_12 ( V_16 ) ;
}
static unsigned long F_13 ( struct V_13 * V_14 ,
void * V_24 , unsigned long V_25 , int V_26 )
{
void * V_27 ;
if( V_28 != NULL )
F_14 ( V_28 ) ;
#ifdef F_9
V_27 = ( void * ) F_15 ( ( unsigned long ) V_24 , V_25 ) ;
#else
V_27 = ( void * ) F_16 ( ( unsigned long ) V_24 , V_25 ) ;
#endif
V_28 = V_27 ;
V_29 = V_25 ;
#ifndef F_9
V_5 -> V_30 = 0 ;
F_7 ( V_31 , V_7 ) ;
V_5 -> V_15 &= ~ V_32 ;
V_5 -> V_15 |= V_32 ;
#endif
if( V_26 )
V_5 -> V_15 |= V_33 ;
else
V_5 -> V_15 &= ~ V_33 ;
#ifdef F_9
V_5 -> V_15 |= V_34 ;
V_5 -> V_35 = ( ( unsigned long ) V_27 >> 16 ) ;
V_5 -> V_36 = ( ( unsigned long ) V_27 & 0xffff ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_38 = 0 ;
V_5 -> V_39 = 0 ;
V_5 -> V_30 = 0 ;
#else
V_5 -> V_30 = V_25 ;
F_7 ( V_31 , V_7 ) ;
V_5 -> V_15 &= ~ V_32 ;
V_5 -> V_15 |= V_32 ;
if( V_5 -> V_30 != V_25 ) {
F_10 ( V_20 , V_14 , L_3 ,
V_5 -> V_30 , ( unsigned int ) V_25 ) ;
F_17 ( V_40 , V_14 ) ;
}
V_41 -> V_42 = ( ( ( unsigned long ) ( V_27 ) & 0xff0000 ) >> 8 ) ;
V_41 -> V_43 = ( ( unsigned long ) ( V_27 ) & 0xffff ) ;
V_41 -> V_25 = V_25 / 2 ;
V_41 -> V_44 = V_45 ;
if( V_26 ) {
if( V_25 & 1 )
V_41 -> V_25 ++ ;
V_41 -> V_46 = V_47 ;
V_41 -> V_48 = V_49 ;
} else {
V_41 -> V_46 = V_50 ;
V_41 -> V_48 = V_51 ;
}
F_7 ( ( ( F_18 ( V_41 ) & 0xff0000 ) >> 8 ) ,
V_52 ) ;
F_7 ( ( F_18 ( V_41 ) & 0xffff ) , V_53 ) ;
F_7 ( 0xd , V_54 ) ;
F_7 ( V_55 , V_7 ) ;
#endif
return V_25 ;
}
static inline unsigned long F_19 ( struct V_13 * V_14 )
{
return V_56 ;
}
static inline unsigned long F_20 ( unsigned long V_57 ,
struct V_58 * V_59 )
{
if ( V_57 < V_60 || V_59 -> V_61 -> V_62 != V_63 )
return 0 ;
return V_57 ;
}
static inline int F_21 ( unsigned long V_25 , unsigned char * V_24 )
{
#ifdef F_9
unsigned short V_15 ;
V_15 = V_5 -> V_15 ;
V_5 -> V_37 = ( V_29 >> 16 ) ;
V_5 -> V_38 = ( V_29 & 0xffff ) ;
V_5 -> V_39 = ( V_29 >> 16 ) ;
V_5 -> V_30 = ( V_29 & 0xffff ) ;
#else
F_7 ( V_64 , V_7 ) ;
#endif
return 0 ;
}
static int F_22 ( int V_26 )
{
unsigned short T_2 V_25 ;
unsigned short V_65 ;
int V_4 = 0 ;
V_66 = 0 ;
#ifdef F_9
V_5 -> V_15 &= ~ V_17 ;
V_65 = V_5 -> V_30 ;
if ( V_26 ) {
if ( ( V_65 > 0 ) && ( V_65 < V_29 ) )
V_65 ++ ;
}
V_56 = V_65 ;
if ( ( ! V_26 ) && ( V_5 -> V_15 & V_67 ) ) {
unsigned char * V_68 ;
V_68 = ( unsigned char * ) F_23 ( V_28 ) ;
V_68 += ( V_29 - V_65 ) ;
V_68 -- ;
switch ( V_5 -> V_15 & V_67 ) {
case V_69 :
* V_68 = ( V_5 -> V_70 & 0xff00 ) >> 8 ;
V_68 -- ;
case V_71 :
* V_68 = ( V_5 -> V_72 & 0x00ff ) ;
V_68 -- ;
case V_73 :
* V_68 = ( V_5 -> V_72 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_26 ) {
int V_74 = 20000 ;
while( 1 ) {
if( V_5 -> V_15 & V_75 )
break;
if( -- V_74 <= 0 ) {
F_24 ( L_4 ) ;
return 1 ;
}
F_6 ( 10 ) ;
}
}
V_5 -> V_6 = 0x32 ;
F_6 ( V_8 ) ;
V_25 = 2 * V_5 -> V_9 ;
F_6 ( V_8 ) ;
V_65 = V_5 -> V_30 ;
V_56 = V_65 ;
if( ( ! V_26 ) && ( V_25 - V_65 ) == 2 ) {
unsigned short V_24 ;
unsigned char * V_68 ;
V_24 = V_5 -> V_76 ;
V_68 = ( unsigned char * ) F_25 ( V_28 ) ;
V_68 += ( V_29 - V_65 ) ;
V_68 [ - 2 ] = ( V_24 & 0xff00 ) >> 8 ;
V_68 [ - 1 ] = ( V_24 & 0xff ) ;
}
#endif
F_14 ( V_28 ) ;
V_28 = NULL ;
#ifdef F_9
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_38 = 0 ;
V_5 -> V_30 = 0 ;
V_5 -> V_39 = 0 ;
V_5 -> V_15 &= ~ V_33 ;
#else
F_7 ( V_31 , V_7 ) ;
V_5 -> V_30 = 0 ;
V_5 -> V_15 &= ~ V_33 ;
V_5 -> V_15 &= ~ V_32 ;
V_5 -> V_15 |= V_32 ;
#endif
V_77 = NULL ;
return V_4 ;
}
static int T_3 F_26 ( struct V_78 * V_79 )
{
struct V_13 * V_14 ;
int error ;
struct V_80 * V_11 , * V_81 ;
unsigned char * V_82 ;
int V_83 = 0 ;
#ifdef F_9
int V_84 ;
#endif
if ( V_85 > 0 )
V_86 . V_87 = V_85 ;
if ( V_88 > 0 )
V_86 . V_89 = V_88 ;
if ( V_90 >= 0 )
V_86 . V_91 = V_90 ;
if ( V_92 >= 0 )
V_86 . V_93 = V_92 & 7 ;
#ifdef F_9
V_82 = NULL ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
unsigned char V_94 ;
V_11 = F_27 ( V_79 , V_95 , V_84 ) ;
V_81 = F_27 ( V_79 , V_96 , V_84 ) ;
if ( ! V_11 || ! V_81 )
break;
V_82 = F_28 ( V_81 -> V_97 , F_29 ( V_81 ) ,
V_98 ) ;
V_5 = (struct V_99 * ) ( V_82 + 8 ) ;
if ( F_30 ( ( unsigned long ) V_5 , & V_94 ) ) {
unsigned short V_100 ;
V_100 = V_5 -> V_15 ;
V_5 -> V_15 = 0 ;
F_6 ( V_8 ) ;
if ( V_5 -> V_15 == 0x1400 )
break;
V_5 -> V_15 = V_100 ;
}
F_31 ( V_82 ) ;
V_82 = NULL ;
}
if ( ! V_82 )
return - V_101 ;
#else
V_11 = F_27 ( V_79 , V_95 , 0 ) ;
V_81 = F_27 ( V_79 , V_96 , 0 ) ;
if ( ! V_11 || ! V_81 )
return - V_101 ;
V_82 = F_32 ( V_81 -> V_97 , F_29 ( V_81 ) ) ;
V_5 = (struct V_99 * ) ( V_82 + 8 ) ;
V_41 = F_33 ( sizeof( struct V_102 ) ) ;
if ( ! V_41 ) {
F_34 ( V_103 L_5 ) ;
F_31 ( V_82 ) ;
return - V_104 ;
}
#endif
V_2 = V_82 ;
V_14 = F_35 ( & V_86 ,
sizeof( struct V_105 ) ) ;
if ( ! V_14 ) {
error = - V_104 ;
goto V_106;
}
V_14 -> V_107 = ( unsigned long ) V_82 ;
V_14 -> V_11 = V_11 -> V_97 ;
error = F_36 ( V_14 , V_83 ) ;
if ( error )
goto V_108;
error = F_37 ( V_14 -> V_11 , F_8 , 0 ,
L_6 , V_14 ) ;
if ( error ) {
F_34 ( V_103 L_7 ,
V_14 -> V_109 , V_14 -> V_11 ) ;
goto V_110;
}
V_5 -> V_15 = 0 ;
F_6 ( V_8 ) ;
V_5 -> V_15 = V_111 | V_32 | V_112 ;
F_6 ( V_8 ) ;
V_5 -> V_30 = 0 ;
#ifdef F_9
V_5 -> V_39 = 0 ;
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_38 = 0 ;
V_5 -> V_113 = V_114 | ( V_14 -> V_11 & 0xff ) ;
#endif
F_38 ( V_14 ) ;
error = F_39 ( V_14 , NULL ) ;
if ( error )
goto V_115;
F_40 ( V_79 , V_14 ) ;
F_41 ( V_14 ) ;
return 0 ;
V_115:
F_42 ( V_14 -> V_11 , V_14 ) ;
V_110:
F_43 ( V_14 ) ;
V_108:
F_44 ( V_14 ) ;
V_106:
if ( V_41 )
F_45 ( V_41 ) ;
F_31 ( V_2 ) ;
return error ;
}
static int T_4 F_46 ( struct V_78 * V_79 )
{
struct V_13 * V_14 = F_47 ( V_79 ) ;
F_48 ( V_14 ) ;
F_42 ( V_14 -> V_11 , V_14 ) ;
F_43 ( V_14 ) ;
F_44 ( V_14 ) ;
if ( V_41 )
F_45 ( V_41 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
