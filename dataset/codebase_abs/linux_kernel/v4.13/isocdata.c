void F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
F_2 ( & V_2 -> V_7 , 1 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_3 = V_3 ;
memset ( V_2 -> V_9 + V_10 , V_3 , V_11 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
int V_4 , V_6 , V_12 ;
V_4 = V_2 -> V_4 ;
V_6 = V_2 -> V_6 ;
V_12 = V_4 - V_6 ;
if ( V_12 > 0 ) {
return V_12 - V_11 ;
} else if ( V_4 < V_11 ) {
return V_10 - V_6 ;
} else {
return V_12 + V_10 - V_11 ;
}
}
static inline int F_4 ( struct V_1 * V_2 )
{
if ( ! F_5 ( & V_2 -> V_7 ) ) {
F_6 ( & V_2 -> V_7 ) ;
F_7 ( V_13 , L_1 ,
V_14 ) ;
return - V_15 ;
}
F_7 ( V_13 ,
L_2 ,
V_14 , V_2 -> V_9 [ V_2 -> V_6 ] , V_2 -> V_8 ) ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
int V_6 = V_2 -> V_6 ;
F_6 ( & V_2 -> V_7 ) ;
return V_6 ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_9 , int V_16 )
{
int V_6 = V_2 -> V_6 ;
V_9 <<= V_2 -> V_8 ;
V_9 |= V_2 -> V_9 [ V_6 ] ;
V_16 += V_2 -> V_8 ;
while ( V_16 >= 8 ) {
V_2 -> V_9 [ V_6 ++ ] = V_9 & 0xff ;
V_6 %= V_10 ;
V_9 >>= 8 ;
V_16 -= 8 ;
}
V_2 -> V_8 = V_16 ;
V_2 -> V_9 [ V_6 ] = V_9 & 0xff ;
V_2 -> V_6 = V_6 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
int V_6 ;
F_9 ( V_2 , 0x7e7e , 8 ) ;
V_6 = V_2 -> V_6 ;
V_2 -> V_3 = V_2 -> V_9 [ V_6 ] ;
F_7 ( V_13 , L_3 , V_2 -> V_3 ) ;
V_2 -> V_9 [ V_6 ] &= ( 1 << V_2 -> V_8 ) - 1 ;
}
int F_11 ( struct V_1 * V_2 , int V_17 )
{
int V_4 , V_6 , V_18 , V_19 , V_20 ;
unsigned char V_21 ;
V_4 = V_2 -> V_5 ;
V_6 = V_2 -> V_6 ;
if ( F_12 ( V_4 == V_6 ) ) {
return V_4 < V_11 ?
V_10 : V_4 - V_11 ;
}
V_18 = V_4 + V_17 ;
F_7 ( V_22 , L_4 ,
V_14 , V_4 , V_6 , V_18 ) ;
#ifdef F_13
if ( F_14 ( V_17 < 0 || V_17 > V_11 ) ) {
F_15 ( L_5 , V_17 ) ;
return - V_23 ;
}
#endif
if ( V_4 < V_6 ) {
if ( V_18 >= V_6 ) {
if ( F_4 ( V_2 ) < 0 )
return - V_15 ;
V_6 = V_2 -> V_6 ;
if ( V_18 >= V_6 ) {
V_21 = V_2 -> V_9 [ V_6 ] ;
V_18 = V_6 + V_11 ;
F_7 ( V_22 ,
L_6 ,
V_14 , V_6 , V_18 , V_2 -> V_3 ) ;
if ( V_6 + V_11 < V_10 )
memset ( V_2 -> V_9 + V_6 , V_2 -> V_3 ,
V_11 ) ;
else {
memset ( V_2 -> V_9 + V_6 , V_2 -> V_3 ,
V_10 + V_11
- V_6 ) ;
V_18 = 0 ;
}
F_7 ( V_22 ,
L_7 ,
V_14 , V_21 , V_18 ) ;
V_2 -> V_9 [ V_18 ] = V_21 ;
V_2 -> V_6 = V_18 ;
}
F_8 ( V_2 ) ;
}
} else {
if ( V_18 >= V_10 ) {
V_19 = 0 ;
V_20 = V_10 ;
while ( V_20 < V_18 && V_19 < V_6 )
V_2 -> V_9 [ V_20 ++ ] = V_2 -> V_9 [ V_19 ++ ] ;
if ( V_20 <= V_18 ) {
memset ( V_2 -> V_9 + V_20 , V_2 -> V_3 ,
V_10 + V_11 - V_20 ) ;
}
V_18 = V_19 ;
}
}
V_2 -> V_5 = V_18 ;
return V_4 ;
}
static inline void F_16 ( enum V_24 V_25 , const char * V_26 ,
unsigned char * V_27 , int V_28 )
{
#ifdef F_13
unsigned char V_29 ;
static char V_30 [ 3 * 32 + 1 ] ;
int V_31 = 0 ;
if ( ! ( V_32 & V_25 ) )
return;
while ( V_28 -- > 0 ) {
if ( V_31 > sizeof( V_30 ) - 4 ) {
V_30 [ V_31 ] = '\0' ;
F_7 ( V_25 , L_8 , V_26 , V_30 ) ;
V_31 = 0 ;
}
V_29 = * V_27 ++ ;
V_30 [ V_31 ] = ( V_31 && ! ( V_31 % 12 ) ) ? '-' : ' ' ;
V_31 ++ ;
V_30 [ V_31 ++ ] = F_17 ( V_29 ) ;
V_30 [ V_31 ++ ] = F_18 ( V_29 ) ;
}
V_30 [ V_31 ] = '\0' ;
F_7 ( V_25 , L_8 , V_26 , V_30 ) ;
#endif
}
static inline int F_19 ( struct V_1 * V_2 , unsigned char V_33 ,
int V_34 )
{
T_2 V_35 ;
int V_36 , V_37 ;
V_35 = V_38 [ 256 * V_34 + V_33 ] ;
V_36 = ( V_35 >> 13 ) & 3 ;
V_37 = ( V_35 >> 10 ) & 7 ;
V_35 &= 0x3ff ;
F_9 ( V_2 , V_35 , 8 + V_36 ) ;
return V_37 ;
}
static inline int F_20 ( struct V_1 * V_2 ,
unsigned char * V_39 , int V_28 )
{
int V_34 ;
T_2 V_40 ;
int V_41 ;
unsigned char V_29 ;
if ( F_3 ( V_2 ) < V_28 + V_28 / 5 + 6 ||
F_4 ( V_2 ) < 0 ) {
F_7 ( V_13 , L_9 ,
V_14 , F_3 ( V_2 ) ) ;
return - V_42 ;
}
F_16 ( V_43 , L_10 , V_39 , V_28 ) ;
V_40 = V_44 ;
V_34 = 0 ;
while ( V_28 -- > 0 ) {
V_29 = * V_39 ++ ;
V_34 = F_19 ( V_2 , V_29 , V_34 ) ;
V_40 = F_21 ( V_40 , V_29 ) ;
}
V_40 ^= 0xffff ;
V_34 = F_19 ( V_2 , V_40 & 0x00ff , V_34 ) ;
V_34 = F_19 ( V_2 , ( V_40 >> 8 ) & 0x00ff , V_34 ) ;
F_10 ( V_2 ) ;
V_41 = F_8 ( V_2 ) ;
return V_41 ;
}
static inline int F_22 ( struct V_1 * V_2 ,
unsigned char * V_39 , int V_28 )
{
int V_6 ;
unsigned char V_29 ;
if ( F_14 ( V_28 <= 0 ) )
return V_2 -> V_6 ;
if ( F_3 ( V_2 ) < V_28 ||
F_4 ( V_2 ) < 0 ) {
F_7 ( V_13 , L_11 , V_28 ) ;
return - V_42 ;
}
F_7 ( V_22 , L_12 , V_28 ) ;
F_16 ( V_43 , L_10 , V_39 , V_28 ) ;
V_6 = V_2 -> V_6 ;
do {
V_29 = F_23 ( * V_39 ++ ) ;
V_2 -> V_9 [ V_6 ++ ] = V_29 ;
V_6 %= V_10 ;
} while ( -- V_28 > 0 );
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_29 ;
return F_8 ( V_2 ) ;
}
int F_24 ( struct V_45 * V_46 , unsigned char * V_39 , int V_47 )
{
int V_48 ;
switch ( V_46 -> V_49 ) {
case V_50 :
V_48 = F_20 ( V_46 -> V_51 . V_52 -> V_53 , V_39 , V_47 ) ;
F_7 ( V_13 , L_13 ,
V_14 , V_47 , V_48 ) ;
break;
default:
V_48 = F_22 ( V_46 -> V_51 . V_52 -> V_53 , V_39 , V_47 ) ;
F_7 ( V_13 , L_14 ,
V_14 , V_47 , V_48 ) ;
}
return V_48 ;
}
static inline void F_25 ( unsigned char V_29 , struct V_45 * V_46 )
{
V_46 -> V_54 = F_21 ( V_46 -> V_54 , V_29 ) ;
if ( V_46 -> V_55 == NULL )
return;
if ( V_46 -> V_55 -> V_47 >= V_46 -> V_56 ) {
F_26 ( V_46 -> V_57 -> V_58 , L_15 ) ;
V_46 -> V_51 . V_52 -> V_59 ++ ;
F_27 ( V_46 -> V_55 ) ;
V_46 -> V_55 = NULL ;
return;
}
F_28 ( V_46 -> V_55 , V_29 ) ;
}
static inline void F_29 ( struct V_45 * V_46 )
{
if ( V_46 -> V_55 != NULL )
F_30 ( V_46 -> V_55 , 0 ) ;
else
F_31 ( V_46 ) ;
V_46 -> V_54 = V_44 ;
}
static inline void F_32 ( struct V_45 * V_46 )
{
struct V_60 * V_57 = V_46 -> V_57 ;
struct V_61 * V_62 ;
unsigned int V_47 ;
if ( F_14 ( V_46 -> V_63 ) ) {
V_46 -> V_63 -- ;
F_29 ( V_46 ) ;
return;
}
V_62 = V_46 -> V_55 ;
if ( V_62 == NULL ) {
F_7 ( V_13 , L_16 , V_14 ) ;
F_33 ( V_46 ) ;
} else if ( V_62 -> V_47 < 2 ) {
F_34 ( V_57 -> V_58 , L_17 ,
V_62 -> V_47 ) ;
V_46 -> V_51 . V_52 -> V_64 ++ ;
F_27 ( V_62 ) ;
F_33 ( V_46 ) ;
} else if ( V_46 -> V_54 != V_65 ) {
F_34 ( V_57 -> V_58 , L_18 ) ;
V_46 -> V_51 . V_52 -> V_66 ++ ;
F_27 ( V_62 ) ;
F_33 ( V_46 ) ;
} else {
V_47 = V_62 -> V_47 ;
F_35 ( V_62 , V_47 -= 2 ) ;
F_7 ( V_13 , L_19 , V_14 , V_47 ) ;
F_16 ( V_43 ,
L_20 , V_62 -> V_9 , V_47 ) ;
V_46 -> V_51 . V_52 -> V_67 += V_47 ;
F_36 ( V_46 , V_62 ) ;
}
F_31 ( V_46 ) ;
V_46 -> V_54 = V_44 ;
}
static inline void F_37 ( struct V_45 * V_46 , unsigned V_68 )
{
if ( F_14 ( V_46 -> V_63 ) ) {
V_46 -> V_63 -- ;
F_29 ( V_46 ) ;
return;
}
F_34 ( V_46 -> V_57 -> V_58 , L_21 , V_68 ) ;
V_46 -> V_51 . V_52 -> V_69 ++ ;
F_33 ( V_46 ) ;
F_35 ( V_46 -> V_55 , 0 ) ;
V_46 -> V_54 = V_44 ;
}
static inline void F_38 ( unsigned char * V_19 , unsigned V_28 ,
struct V_45 * V_46 )
{
struct V_70 * V_71 = V_46 -> V_51 . V_52 ;
int V_72 ;
unsigned V_73 , V_74 , V_68 ;
V_72 = V_46 -> V_72 ;
V_73 = V_71 -> V_73 ;
V_74 = V_71 -> V_74 ;
V_68 = V_71 -> V_68 ;
while ( V_28 -- ) {
unsigned char V_29 = * V_19 ++ ;
unsigned char V_75 = V_76 [ V_29 ] ;
unsigned V_77 = V_75 & 0x0f ;
unsigned V_78 = ( V_75 >> 4 ) & 0x0f ;
V_73 += V_77 ;
if ( F_14 ( V_72 & V_79 ) ) {
if ( V_29 == V_80 ) {
V_72 &= ~ ( V_79 | V_81 ) ;
V_74 = 0 ;
V_68 = 0 ;
} else if ( V_73 == 6 && V_78 != 7 ) {
V_72 &= ~ ( V_79 | V_81 ) ;
V_74 = V_29 >> ( V_77 + 1 ) ;
V_68 = 7 - V_77 ;
if ( V_78 >= 8 ) {
V_68 -- ;
switch ( V_29 ) {
case 0xbe :
V_74 = 0x3f ;
break;
}
}
}
} else if ( F_12 ( V_73 < 5 && V_78 < 7 ) ) {
V_74 |= V_29 << V_68 ;
F_25 ( V_74 & 0xff , V_46 ) ;
V_72 |= V_81 ;
V_74 >>= 8 ;
} else if ( F_12 ( V_73 == 6 && V_68 == 7 - V_77 &&
V_78 + 1 == V_68 &&
! ( V_72 & V_81 ) ) ) {
} else if ( F_14 ( V_73 > 6 ) ) {
V_71 -> V_82 ++ ;
F_29 ( V_46 ) ;
V_72 |= V_79 ;
} else if ( V_73 == 6 ) {
if ( V_68 > 7 - V_77 ) {
F_37 ( V_46 , V_68 + V_77 - 7 ) ;
V_72 &= ~ V_81 ;
} else {
if ( V_68 < 7 - V_77 )
V_71 -> V_83 ++ ;
if ( V_72 & V_81 ) {
F_32 ( V_46 ) ;
V_72 &= ~ V_81 ;
}
}
if ( V_29 == V_80 ) {
V_71 -> V_84 ++ ;
V_68 = 0 ;
V_74 = 0 ;
} else if ( V_78 != 7 ) {
V_74 = V_29 >> ( V_77 + 1 ) ;
V_68 = 7 - V_77 ;
if ( V_78 >= 8 ) {
V_68 -- ;
switch ( V_29 ) {
case 0xbe :
V_74 = 0x3f ;
break;
}
}
} else {
V_71 -> V_82 ++ ;
V_72 |= V_79 ;
}
} else {
if ( V_29 == V_80 ) {
if ( V_73 == 5 )
V_71 -> V_83 ++ ;
if ( V_68 ) {
F_37 ( V_46 , V_68 ) ;
V_68 = 0 ;
V_74 = 0 ;
} else if ( V_72 & V_81 )
F_32 ( V_46 ) ;
V_72 &= ~ V_81 ;
} else if ( V_78 == 7 ) {
V_71 -> V_82 ++ ;
F_29 ( V_46 ) ;
V_72 |= V_79 ;
} else {
if ( V_78 < 7 ) {
unsigned char V_85 = ( 1 << V_77 ) - 1 ;
V_29 = ( V_29 & V_85 ) | ( ( V_29 & ~ V_85 ) >> 1 ) ;
V_74 |= V_29 << V_68 ;
V_68 += 7 ;
} else if ( V_73 < 5 ) {
switch ( V_29 ) {
case 0xbe :
V_29 = 0x7e ;
break;
}
V_74 |= V_29 << V_68 ;
V_68 += 7 ;
} else {
switch ( V_29 ) {
case 0x7d :
V_29 = 0x3f ;
break;
case 0xbe :
V_29 = 0x3f ;
break;
case 0x3e :
V_29 = 0x1f ;
break;
case 0x7c :
V_29 = 0x3e ;
break;
}
V_74 |= V_29 << V_68 ;
V_68 += 6 ;
}
if ( V_68 >= 8 ) {
V_68 -= 8 ;
F_25 ( V_74 & 0xff , V_46 ) ;
V_72 |= V_81 ;
V_74 >>= 8 ;
}
}
}
V_73 = V_78 & 7 ;
}
V_46 -> V_72 = V_72 ;
V_71 -> V_73 = V_73 ;
V_71 -> V_74 = V_74 ;
V_71 -> V_68 = V_68 ;
}
static inline void F_39 ( unsigned char * V_19 , unsigned V_28 ,
struct V_45 * V_46 )
{
struct V_61 * V_86 ;
int V_87 ;
unsigned char * V_20 ;
if ( F_14 ( V_46 -> V_63 ) ) {
V_46 -> V_63 -- ;
return;
}
V_86 = V_46 -> V_55 ;
if ( V_86 == NULL ) {
V_86 = F_31 ( V_46 ) ;
if ( V_86 == NULL )
return;
}
V_87 = V_46 -> V_56 - V_86 -> V_47 ;
while ( V_28 > 0 ) {
V_20 = F_40 ( V_86 , V_28 < V_87 ? V_28 : V_87 ) ;
while ( V_28 > 0 && V_87 > 0 ) {
* V_20 ++ = F_23 ( * V_19 ++ ) ;
V_28 -- ;
V_87 -- ;
}
if ( V_87 == 0 ) {
F_16 ( V_43 ,
L_20 , V_86 -> V_9 , V_86 -> V_47 ) ;
V_46 -> V_51 . V_52 -> V_67 += V_86 -> V_47 ;
F_36 ( V_46 , V_86 ) ;
V_86 = F_31 ( V_46 ) ;
if ( V_86 == NULL )
return;
V_87 = V_46 -> V_56 ;
}
}
}
void F_41 ( unsigned char * V_19 , unsigned V_28 ,
struct V_45 * V_46 )
{
switch ( V_46 -> V_49 ) {
case V_50 :
F_38 ( V_19 , V_28 , V_46 ) ;
break;
default:
F_39 ( V_19 , V_28 , V_46 ) ;
}
}
static void F_42 ( unsigned char * V_19 , int V_88 , struct V_89 * V_90 )
{
struct V_60 * V_57 = V_90 -> V_57 ;
unsigned V_91 = V_57 -> V_91 ;
unsigned char V_29 ;
while ( V_88 -- ) {
V_29 = * V_19 ++ ;
switch ( V_29 ) {
case '\n' :
if ( V_91 == 0 && V_57 -> V_92 [ 0 ] == '\r' ) {
V_57 -> V_92 [ 0 ] = 0 ;
break;
}
case '\r' :
if ( V_91 >= V_93 ) {
F_26 ( V_57 -> V_58 , L_22 ,
V_91 ) ;
V_91 = V_93 ;
}
V_57 -> V_91 = V_91 ;
F_43 ( V_94 , L_23 ,
V_91 , V_57 -> V_92 ) ;
F_44 ( V_57 ) ;
V_91 = 0 ;
V_57 -> V_92 [ 0 ] = V_29 ;
break;
default:
if ( V_91 < V_93 )
V_57 -> V_92 [ V_91 ] = V_29 ;
V_91 ++ ;
}
}
V_57 -> V_91 = V_91 ;
}
void F_45 ( struct V_89 * V_90 )
{
struct V_60 * V_57 = V_90 -> V_57 ;
unsigned V_95 , V_96 , V_88 ;
unsigned char * V_19 ;
V_96 = V_90 -> V_96 ;
while ( V_96 != ( V_95 = V_90 -> V_95 ) ) {
F_7 ( V_97 , L_24 , V_96 , V_95 ) ;
if ( V_96 > V_95 )
V_95 = V_98 ;
V_19 = V_90 -> V_9 + V_96 ;
V_88 = V_95 - V_96 ;
F_7 ( V_97 , L_25 , V_88 ) ;
if ( V_57 -> V_99 == V_100 ) {
F_43 ( V_101 , L_23 ,
V_88 , V_19 ) ;
F_46 ( V_90 -> V_57 , V_19 , V_88 ) ;
} else {
F_42 ( V_19 , V_88 , V_90 ) ;
}
V_96 += V_88 ;
if ( V_96 == V_98 )
V_96 = 0 ;
F_7 ( V_97 , L_26 , V_96 ) ;
V_90 -> V_96 = V_96 ;
}
}
int F_47 ( struct V_45 * V_46 , struct V_61 * V_86 )
{
int V_47 = V_86 -> V_47 ;
unsigned long V_102 ;
F_48 ( & V_46 -> V_57 -> V_103 , V_102 ) ;
if ( ! V_46 -> V_57 -> V_104 ) {
F_49 ( & V_46 -> V_57 -> V_103 , V_102 ) ;
return - V_105 ;
}
F_50 ( & V_46 -> V_106 , V_86 ) ;
F_7 ( V_13 , L_27 ,
V_14 , F_51 ( & V_46 -> V_106 ) ) ;
F_52 ( & V_46 -> V_51 . V_52 -> V_107 ) ;
F_49 ( & V_46 -> V_57 -> V_103 , V_102 ) ;
return V_47 ;
}
