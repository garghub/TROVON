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
struct V_58 * V_59 ,
int V_26 )
{
if ( V_59 -> V_60 -> V_61 == V_62 )
return V_57 ;
else
return 0 ;
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
F_7 ( V_63 , V_7 ) ;
#endif
return 0 ;
}
static int F_22 ( int V_26 )
{
unsigned short T_2 V_25 ;
unsigned short V_64 ;
int V_4 = 0 ;
V_65 = 0 ;
#ifdef F_9
V_5 -> V_15 &= ~ V_17 ;
V_64 = V_5 -> V_30 ;
if ( V_26 ) {
if ( ( V_64 > 0 ) && ( V_64 < V_29 ) )
V_64 ++ ;
}
V_56 = V_64 ;
if ( ( ! V_26 ) && ( V_5 -> V_15 & V_66 ) ) {
unsigned char * V_67 ;
V_67 = ( unsigned char * ) F_23 ( V_28 ) ;
V_67 += ( V_29 - V_64 ) ;
V_67 -- ;
switch ( V_5 -> V_15 & V_66 ) {
case V_68 :
* V_67 = ( V_5 -> V_69 & 0xff00 ) >> 8 ;
V_67 -- ;
case V_70 :
* V_67 = ( V_5 -> V_71 & 0x00ff ) ;
V_67 -- ;
case V_72 :
* V_67 = ( V_5 -> V_71 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_26 ) {
int V_73 = 20000 ;
while( 1 ) {
if( V_5 -> V_15 & V_74 )
break;
if( -- V_73 <= 0 ) {
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
V_64 = V_5 -> V_30 ;
V_56 = V_64 ;
if( ( ! V_26 ) && ( V_25 - V_64 ) == 2 ) {
unsigned short V_24 ;
unsigned char * V_67 ;
V_24 = V_5 -> V_75 ;
V_67 = ( unsigned char * ) F_25 ( V_28 ) ;
V_67 += ( V_29 - V_64 ) ;
V_67 [ - 2 ] = ( V_24 & 0xff00 ) >> 8 ;
V_67 [ - 1 ] = ( V_24 & 0xff ) ;
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
V_76 = NULL ;
return V_4 ;
}
static int T_3 F_26 ( struct V_77 * V_78 )
{
struct V_13 * V_14 ;
int error ;
struct V_79 * V_11 , * V_80 ;
unsigned char * V_81 ;
int V_82 = 0 ;
#ifdef F_9
int V_83 ;
#endif
if ( V_84 > 0 )
V_85 . V_86 = V_84 ;
if ( V_87 > 0 )
V_85 . V_88 = V_87 ;
if ( V_89 >= 0 )
V_85 . V_90 = V_89 ;
if ( V_91 >= 0 )
V_85 . V_92 = V_91 & 7 ;
#ifdef F_9
V_81 = NULL ;
for ( V_83 = 0 ; V_83 < 2 ; V_83 ++ ) {
unsigned char V_93 ;
V_11 = F_27 ( V_78 , V_94 , V_83 ) ;
V_80 = F_27 ( V_78 , V_95 , V_83 ) ;
if ( ! V_11 || ! V_80 )
break;
V_81 = F_28 ( V_80 -> V_96 , F_29 ( V_80 ) ,
V_97 ) ;
V_5 = (struct V_98 * ) ( V_81 + 8 ) ;
if ( F_30 ( ( unsigned long ) V_5 , & V_93 ) ) {
unsigned short V_99 ;
V_99 = V_5 -> V_15 ;
V_5 -> V_15 = 0 ;
F_6 ( V_8 ) ;
if ( V_5 -> V_15 == 0x1400 )
break;
V_5 -> V_15 = V_99 ;
}
F_31 ( V_81 ) ;
V_81 = NULL ;
}
if ( ! V_81 )
return - V_100 ;
#else
V_11 = F_27 ( V_78 , V_94 , 0 ) ;
V_80 = F_27 ( V_78 , V_95 , 0 ) ;
if ( ! V_11 || ! V_80 )
return - V_100 ;
V_81 = F_32 ( V_80 -> V_96 , F_29 ( V_80 ) ) ;
V_5 = (struct V_98 * ) ( V_81 + 8 ) ;
V_41 = F_33 ( sizeof( struct V_101 ) ) ;
if ( ! V_41 ) {
F_34 ( V_102 L_5 ) ;
F_31 ( V_81 ) ;
return - V_103 ;
}
#endif
V_2 = V_81 ;
V_14 = F_35 ( & V_85 ,
sizeof( struct V_104 ) ) ;
if ( ! V_14 ) {
error = - V_103 ;
goto V_105;
}
V_14 -> V_106 = ( unsigned long ) V_81 ;
V_14 -> V_11 = V_11 -> V_96 ;
#ifdef F_36
V_82 |= V_107 > 0 ? V_108 : 0 ;
#endif
error = F_37 ( V_14 , V_82 ) ;
if ( error )
goto V_109;
error = F_38 ( V_14 -> V_11 , F_8 , 0 ,
L_6 , V_14 ) ;
if ( error ) {
#ifdef F_39
F_34 ( V_102 L_7 ,
V_14 -> V_110 , V_14 -> V_11 ) ;
goto V_111;
#else
F_40 ( V_102 L_8 ,
V_14 -> V_110 , V_14 -> V_11 ) ;
V_14 -> V_11 = V_112 ;
#endif
}
V_5 -> V_15 = 0 ;
F_6 ( V_8 ) ;
V_5 -> V_15 = V_113 | V_32 | V_114 ;
F_6 ( V_8 ) ;
V_5 -> V_30 = 0 ;
#ifdef F_9
V_5 -> V_39 = 0 ;
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_38 = 0 ;
V_5 -> V_115 = V_116 | ( V_14 -> V_11 & 0xff ) ;
#endif
F_41 ( V_14 ) ;
error = F_42 ( V_14 , NULL ) ;
if ( error )
goto V_117;
F_43 ( V_78 , V_14 ) ;
F_44 ( V_14 ) ;
return 0 ;
V_117:
if ( V_14 -> V_11 != V_112 )
F_45 ( V_14 -> V_11 , V_14 ) ;
V_111:
F_46 ( V_14 ) ;
V_109:
F_47 ( V_14 ) ;
V_105:
if ( V_41 )
F_48 ( V_41 ) ;
F_31 ( V_2 ) ;
return error ;
}
static int T_4 F_49 ( struct V_77 * V_78 )
{
struct V_13 * V_14 = F_50 ( V_78 ) ;
F_51 ( V_14 ) ;
if ( V_14 -> V_11 != V_112 )
F_45 ( V_14 -> V_11 , V_14 ) ;
F_46 ( V_14 ) ;
F_47 ( V_14 ) ;
if ( V_41 )
F_48 ( V_41 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
