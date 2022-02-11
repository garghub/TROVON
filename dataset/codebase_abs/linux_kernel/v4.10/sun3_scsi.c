static inline unsigned short F_1 ( unsigned char V_1 )
{
unsigned short V_2 ;
V_3 -> V_4 = V_5 ;
F_2 ( V_6 ) ;
V_2 = V_3 -> V_7 ;
F_2 ( V_6 ) ;
return V_2 ;
}
static inline void F_3 ( unsigned short V_8 , unsigned char V_1 )
{
V_3 -> V_4 = V_1 ;
F_2 ( V_6 ) ;
V_3 -> V_7 = V_8 ;
F_2 ( V_6 ) ;
}
static T_1 F_4 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
unsigned short V_13 = V_3 -> V_13 ;
int V_14 = 0 ;
#ifdef F_5
V_3 -> V_13 &= ~ V_15 ;
#endif
if( V_13 & ~ V_16 ) {
if ( V_13 & V_17 )
F_6 ( V_18 , V_12 , L_1 ) ;
if ( V_13 & V_19 )
F_6 ( V_18 , V_12 , L_2 ) ;
V_14 = 1 ;
}
if( V_13 & ( V_20 | V_21 ) ) {
F_7 ( V_9 , V_10 ) ;
V_14 = 1 ;
}
return F_8 ( V_14 ) ;
}
static int F_9 ( struct V_22 * V_23 ,
unsigned char * V_24 , int V_25 , int V_26 )
{
void * V_27 ;
if( V_28 != NULL )
F_10 ( V_28 ) ;
#ifdef F_5
V_27 = ( void * ) F_11 ( ( unsigned long ) V_24 , V_25 ) ;
#else
V_27 = ( void * ) F_12 ( ( unsigned long ) V_24 , V_25 ) ;
#endif
V_28 = V_27 ;
V_29 = V_25 ;
#ifndef F_5
V_3 -> V_30 = 0 ;
F_3 ( V_31 , V_5 ) ;
V_3 -> V_13 &= ~ V_32 ;
V_3 -> V_13 |= V_32 ;
#endif
if( V_26 )
V_3 -> V_13 |= V_33 ;
else
V_3 -> V_13 &= ~ V_33 ;
#ifdef F_5
V_3 -> V_13 |= V_34 ;
V_3 -> V_35 = ( ( unsigned long ) V_27 >> 16 ) ;
V_3 -> V_36 = ( ( unsigned long ) V_27 & 0xffff ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_39 = 0 ;
V_3 -> V_30 = 0 ;
#else
V_3 -> V_30 = V_25 ;
F_3 ( V_31 , V_5 ) ;
V_3 -> V_13 &= ~ V_32 ;
V_3 -> V_13 |= V_32 ;
if( V_3 -> V_30 != V_25 ) {
F_6 ( V_18 , V_23 -> V_40 ,
L_3 ,
V_3 -> V_30 , ( unsigned int ) V_25 ) ;
F_13 ( V_41 , V_23 -> V_40 ) ;
}
V_42 -> V_43 = ( ( ( unsigned long ) ( V_27 ) & 0xff0000 ) >> 8 ) ;
V_42 -> V_44 = ( ( unsigned long ) ( V_27 ) & 0xffff ) ;
V_42 -> V_25 = V_25 / 2 ;
V_42 -> V_45 = V_46 ;
if( V_26 ) {
if( V_25 & 1 )
V_42 -> V_25 ++ ;
V_42 -> V_47 = V_48 ;
V_42 -> V_49 = V_50 ;
} else {
V_42 -> V_47 = V_51 ;
V_42 -> V_49 = V_52 ;
}
F_3 ( ( ( F_14 ( V_42 ) & 0xff0000 ) >> 8 ) ,
V_53 ) ;
F_3 ( ( F_14 ( V_42 ) & 0xffff ) , V_54 ) ;
F_3 ( 0xd , V_55 ) ;
F_3 ( V_56 , V_5 ) ;
#endif
return V_25 ;
}
static int F_15 ( struct V_22 * V_23 ,
unsigned char * V_24 , int V_25 )
{
return V_25 ;
}
static inline int F_16 ( struct V_22 * V_23 ,
unsigned char * V_24 , int V_25 )
{
return F_9 ( V_23 , V_24 , V_25 , 0 ) ;
}
static inline int F_17 ( struct V_22 * V_23 ,
unsigned char * V_24 , int V_25 )
{
return F_9 ( V_23 , V_24 , V_25 , 1 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
return V_57 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_58 * V_59 )
{
int V_60 = V_59 -> V_61 . V_62 ;
if ( V_60 < V_63 || V_59 -> V_64 -> V_65 != V_66 )
return 0 ;
return V_60 ;
}
static inline int F_20 ( unsigned long V_25 , unsigned char * V_24 )
{
#ifdef F_5
unsigned short V_13 ;
V_13 = V_3 -> V_13 ;
V_3 -> V_37 = ( V_29 >> 16 ) ;
V_3 -> V_38 = ( V_29 & 0xffff ) ;
V_3 -> V_39 = ( V_29 >> 16 ) ;
V_3 -> V_30 = ( V_29 & 0xffff ) ;
#else
F_3 ( V_67 , V_5 ) ;
#endif
return 0 ;
}
static int F_21 ( int V_26 )
{
unsigned short T_2 V_25 ;
unsigned short V_68 ;
int V_2 = 0 ;
V_69 = 0 ;
#ifdef F_5
V_3 -> V_13 &= ~ V_15 ;
V_68 = V_3 -> V_30 ;
if ( V_26 ) {
if ( ( V_68 > 0 ) && ( V_68 < V_29 ) )
V_68 ++ ;
}
V_57 = V_68 ;
if ( ( ! V_26 ) && ( V_3 -> V_13 & V_70 ) ) {
unsigned char * V_71 ;
V_71 = ( unsigned char * ) F_22 ( V_28 ) ;
V_71 += ( V_29 - V_68 ) ;
V_71 -- ;
switch ( V_3 -> V_13 & V_70 ) {
case V_72 :
* V_71 = ( V_3 -> V_73 & 0xff00 ) >> 8 ;
V_71 -- ;
case V_74 :
* V_71 = ( V_3 -> V_75 & 0x00ff ) ;
V_71 -- ;
case V_76 :
* V_71 = ( V_3 -> V_75 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_26 ) {
int V_77 = 20000 ;
while( 1 ) {
if( V_3 -> V_13 & V_78 )
break;
if( -- V_77 <= 0 ) {
F_23 ( L_4 ) ;
return 1 ;
}
F_2 ( 10 ) ;
}
}
V_3 -> V_4 = 0x32 ;
F_2 ( V_6 ) ;
V_25 = 2 * V_3 -> V_7 ;
F_2 ( V_6 ) ;
V_68 = V_3 -> V_30 ;
V_57 = V_68 ;
if( ( ! V_26 ) && ( V_25 - V_68 ) == 2 ) {
unsigned short V_24 ;
unsigned char * V_71 ;
V_24 = V_3 -> V_79 ;
V_71 = ( unsigned char * ) F_24 ( V_28 ) ;
V_71 += ( V_29 - V_68 ) ;
V_71 [ - 2 ] = ( V_24 & 0xff00 ) >> 8 ;
V_71 [ - 1 ] = ( V_24 & 0xff ) ;
}
#endif
F_10 ( V_28 ) ;
V_28 = NULL ;
#ifdef F_5
V_3 -> V_35 = 0 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_30 = 0 ;
V_3 -> V_39 = 0 ;
V_3 -> V_13 &= ~ V_33 ;
#else
F_3 ( V_31 , V_5 ) ;
V_3 -> V_30 = 0 ;
V_3 -> V_13 &= ~ V_33 ;
V_3 -> V_13 &= ~ V_32 ;
V_3 -> V_13 |= V_32 ;
#endif
V_80 = NULL ;
return V_2 ;
}
static int T_3 F_25 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
struct V_22 * V_23 ;
int error ;
struct V_83 * V_9 , * V_84 ;
void T_4 * V_85 ;
int V_86 = 0 ;
#ifdef F_5
int V_87 ;
#endif
if ( V_88 > 0 )
V_89 . V_90 = V_88 ;
if ( V_91 > 0 )
V_89 . V_92 = V_91 ;
if ( V_93 >= 0 )
V_89 . V_94 = V_93 ;
if ( V_95 >= 0 )
V_89 . V_96 = V_95 & 7 ;
#ifdef F_5
V_85 = NULL ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
unsigned char V_97 ;
V_9 = F_26 ( V_82 , V_98 , V_87 ) ;
V_84 = F_26 ( V_82 , V_99 , V_87 ) ;
if ( ! V_9 || ! V_84 )
break;
V_85 = F_27 ( V_84 -> V_100 , F_28 ( V_84 ) ,
V_101 ) ;
V_3 = (struct V_102 * ) ( V_85 + 8 ) ;
if ( F_29 ( ( unsigned long ) V_3 , & V_97 ) ) {
unsigned short V_103 ;
V_103 = V_3 -> V_13 ;
V_3 -> V_13 = 0 ;
F_2 ( V_6 ) ;
if ( V_3 -> V_13 == 0x1400 )
break;
V_3 -> V_13 = V_103 ;
}
F_30 ( V_85 ) ;
V_85 = NULL ;
}
if ( ! V_85 )
return - V_104 ;
#else
V_9 = F_26 ( V_82 , V_98 , 0 ) ;
V_84 = F_26 ( V_82 , V_99 , 0 ) ;
if ( ! V_9 || ! V_84 )
return - V_104 ;
V_85 = F_31 ( V_84 -> V_100 , F_28 ( V_84 ) ) ;
V_3 = (struct V_102 * ) ( V_85 + 8 ) ;
V_42 = F_32 ( sizeof( struct V_105 ) ) ;
if ( ! V_42 ) {
F_33 ( V_106 L_5 ) ;
F_30 ( V_85 ) ;
return - V_107 ;
}
#endif
V_12 = F_34 ( & V_89 ,
sizeof( struct V_22 ) ) ;
if ( ! V_12 ) {
error = - V_107 ;
goto V_108;
}
V_12 -> V_9 = V_9 -> V_100 ;
V_23 = F_35 ( V_12 ) ;
V_23 -> V_109 = V_84 -> V_100 ;
V_23 -> V_110 = V_85 ;
error = F_36 ( V_12 , V_86 ) ;
if ( error )
goto V_111;
error = F_37 ( V_12 -> V_9 , F_4 , 0 ,
L_6 , V_12 ) ;
if ( error ) {
F_33 ( V_106 L_7 ,
V_12 -> V_112 , V_12 -> V_9 ) ;
goto V_113;
}
V_3 -> V_13 = 0 ;
F_2 ( V_6 ) ;
V_3 -> V_13 = V_114 | V_32 | V_115 ;
F_2 ( V_6 ) ;
V_3 -> V_30 = 0 ;
#ifdef F_5
V_3 -> V_39 = 0 ;
V_3 -> V_35 = 0 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_116 = V_117 | ( V_12 -> V_9 & 0xff ) ;
#endif
F_38 ( V_12 ) ;
error = F_39 ( V_12 , NULL ) ;
if ( error )
goto V_118;
F_40 ( V_82 , V_12 ) ;
F_41 ( V_12 ) ;
return 0 ;
V_118:
F_42 ( V_12 -> V_9 , V_12 ) ;
V_113:
F_43 ( V_12 ) ;
V_111:
F_44 ( V_12 ) ;
V_108:
if ( V_42 )
F_45 ( V_42 ) ;
F_30 ( V_85 ) ;
return error ;
}
static int T_5 F_46 ( struct V_81 * V_82 )
{
struct V_11 * V_12 = F_47 ( V_82 ) ;
struct V_22 * V_23 = F_35 ( V_12 ) ;
void T_4 * V_85 = V_23 -> V_110 ;
F_48 ( V_12 ) ;
F_42 ( V_12 -> V_9 , V_12 ) ;
F_43 ( V_12 ) ;
F_44 ( V_12 ) ;
if ( V_42 )
F_45 ( V_42 ) ;
F_30 ( V_85 ) ;
return 0 ;
}
