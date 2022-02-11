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
if ( V_60 < V_63 || F_20 ( V_59 -> V_64 ) )
return 0 ;
return V_60 ;
}
static inline int F_21 ( unsigned long V_25 , unsigned char * V_24 )
{
#ifdef F_5
unsigned short V_13 ;
V_13 = V_3 -> V_13 ;
V_3 -> V_37 = ( V_29 >> 16 ) ;
V_3 -> V_38 = ( V_29 & 0xffff ) ;
V_3 -> V_39 = ( V_29 >> 16 ) ;
V_3 -> V_30 = ( V_29 & 0xffff ) ;
#else
F_3 ( V_65 , V_5 ) ;
#endif
return 0 ;
}
static int F_22 ( int V_26 )
{
unsigned short T_2 V_25 ;
unsigned short V_66 ;
int V_2 = 0 ;
V_67 = 0 ;
#ifdef F_5
V_3 -> V_13 &= ~ V_15 ;
V_66 = V_3 -> V_30 ;
if ( V_26 ) {
if ( ( V_66 > 0 ) && ( V_66 < V_29 ) )
V_66 ++ ;
}
V_57 = V_66 ;
if ( ( ! V_26 ) && ( V_3 -> V_13 & V_68 ) ) {
unsigned char * V_69 ;
V_69 = ( unsigned char * ) F_23 ( V_28 ) ;
V_69 += ( V_29 - V_66 ) ;
V_69 -- ;
switch ( V_3 -> V_13 & V_68 ) {
case V_70 :
* V_69 = ( V_3 -> V_71 & 0xff00 ) >> 8 ;
V_69 -- ;
case V_72 :
* V_69 = ( V_3 -> V_73 & 0x00ff ) ;
V_69 -- ;
case V_74 :
* V_69 = ( V_3 -> V_73 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_26 ) {
int V_75 = 20000 ;
while( 1 ) {
if( V_3 -> V_13 & V_76 )
break;
if( -- V_75 <= 0 ) {
F_24 ( L_4 ) ;
return 1 ;
}
F_2 ( 10 ) ;
}
}
V_3 -> V_4 = 0x32 ;
F_2 ( V_6 ) ;
V_25 = 2 * V_3 -> V_7 ;
F_2 ( V_6 ) ;
V_66 = V_3 -> V_30 ;
V_57 = V_66 ;
if( ( ! V_26 ) && ( V_25 - V_66 ) == 2 ) {
unsigned short V_24 ;
unsigned char * V_69 ;
V_24 = V_3 -> V_77 ;
V_69 = ( unsigned char * ) F_25 ( V_28 ) ;
V_69 += ( V_29 - V_66 ) ;
V_69 [ - 2 ] = ( V_24 & 0xff00 ) >> 8 ;
V_69 [ - 1 ] = ( V_24 & 0xff ) ;
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
V_78 = NULL ;
return V_2 ;
}
static int T_3 F_26 ( struct V_79 * V_80 )
{
struct V_11 * V_12 ;
struct V_22 * V_23 ;
int error ;
struct V_81 * V_9 , * V_82 ;
void T_4 * V_83 ;
int V_84 = 0 ;
#ifdef F_5
int V_85 ;
#endif
if ( V_86 > 0 )
V_87 . V_88 = V_86 ;
if ( V_89 > 0 )
V_87 . V_90 = V_89 ;
if ( V_91 >= 0 )
V_87 . V_92 = V_91 ;
if ( V_93 >= 0 )
V_87 . V_94 = V_93 & 7 ;
#ifdef F_5
V_83 = NULL ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
unsigned char V_95 ;
V_9 = F_27 ( V_80 , V_96 , V_85 ) ;
V_82 = F_27 ( V_80 , V_97 , V_85 ) ;
if ( ! V_9 || ! V_82 )
break;
V_83 = F_28 ( V_82 -> V_98 , F_29 ( V_82 ) ,
V_99 ) ;
V_3 = (struct V_100 * ) ( V_83 + 8 ) ;
if ( F_30 ( ( unsigned long ) V_3 , & V_95 ) ) {
unsigned short V_101 ;
V_101 = V_3 -> V_13 ;
V_3 -> V_13 = 0 ;
F_2 ( V_6 ) ;
if ( V_3 -> V_13 == 0x1400 )
break;
V_3 -> V_13 = V_101 ;
}
F_31 ( V_83 ) ;
V_83 = NULL ;
}
if ( ! V_83 )
return - V_102 ;
#else
V_9 = F_27 ( V_80 , V_96 , 0 ) ;
V_82 = F_27 ( V_80 , V_97 , 0 ) ;
if ( ! V_9 || ! V_82 )
return - V_102 ;
V_83 = F_32 ( V_82 -> V_98 , F_29 ( V_82 ) ) ;
V_3 = (struct V_100 * ) ( V_83 + 8 ) ;
V_42 = F_33 ( sizeof( struct V_103 ) ) ;
if ( ! V_42 ) {
F_34 ( V_104 L_5 ) ;
F_31 ( V_83 ) ;
return - V_105 ;
}
#endif
V_12 = F_35 ( & V_87 ,
sizeof( struct V_22 ) ) ;
if ( ! V_12 ) {
error = - V_105 ;
goto V_106;
}
V_12 -> V_9 = V_9 -> V_98 ;
V_23 = F_36 ( V_12 ) ;
V_23 -> V_107 = V_82 -> V_98 ;
V_23 -> V_108 = V_83 ;
error = F_37 ( V_12 , V_84 ) ;
if ( error )
goto V_109;
error = F_38 ( V_12 -> V_9 , F_4 , 0 ,
L_6 , V_12 ) ;
if ( error ) {
F_34 ( V_104 L_7 ,
V_12 -> V_110 , V_12 -> V_9 ) ;
goto V_111;
}
V_3 -> V_13 = 0 ;
F_2 ( V_6 ) ;
V_3 -> V_13 = V_112 | V_32 | V_113 ;
F_2 ( V_6 ) ;
V_3 -> V_30 = 0 ;
#ifdef F_5
V_3 -> V_39 = 0 ;
V_3 -> V_35 = 0 ;
V_3 -> V_36 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_114 = V_115 | ( V_12 -> V_9 & 0xff ) ;
#endif
F_39 ( V_12 ) ;
error = F_40 ( V_12 , NULL ) ;
if ( error )
goto V_116;
F_41 ( V_80 , V_12 ) ;
F_42 ( V_12 ) ;
return 0 ;
V_116:
F_43 ( V_12 -> V_9 , V_12 ) ;
V_111:
F_44 ( V_12 ) ;
V_109:
F_45 ( V_12 ) ;
V_106:
if ( V_42 )
F_46 ( V_42 ) ;
F_31 ( V_83 ) ;
return error ;
}
static int T_5 F_47 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = F_48 ( V_80 ) ;
struct V_22 * V_23 = F_36 ( V_12 ) ;
void T_4 * V_83 = V_23 -> V_108 ;
F_49 ( V_12 ) ;
F_43 ( V_12 -> V_9 , V_12 ) ;
F_44 ( V_12 ) ;
F_45 ( V_12 ) ;
if ( V_42 )
F_46 ( V_42 ) ;
F_31 ( V_83 ) ;
return 0 ;
}
