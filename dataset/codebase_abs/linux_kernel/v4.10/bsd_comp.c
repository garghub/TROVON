static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 ++ ;
V_2 -> V_4 = V_5 - 1 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = V_12 ;
}
static int F_2 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
if ( V_2 -> V_9 >= V_2 -> V_11 )
{
if ( V_2 -> V_9 >= V_14 || V_2 -> V_8 >= V_14 )
{
V_2 -> V_9 -= ( V_2 -> V_9 >> 2 ) ;
V_2 -> V_8 -= ( V_2 -> V_8 >> 2 ) ;
}
V_2 -> V_11 = V_2 -> V_9 + V_12 ;
if ( V_2 -> V_4 >= V_2 -> V_15 )
{
V_13 = V_2 -> V_9 << V_16 ;
if ( V_2 -> V_8 != 0 )
{
V_13 /= V_2 -> V_8 ;
}
if ( V_13 < V_2 -> V_10 || V_13 < 1 * V_17 )
{
F_1 ( V_2 ) ;
return 1 ;
}
V_2 -> V_10 = V_13 ;
}
}
return 0 ;
}
static void F_3 ( void * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
V_20 -> V_21 = V_2 -> V_22 ;
V_20 -> V_23 = V_2 -> V_24 ;
V_20 -> V_25 = V_2 -> V_25 ;
V_20 -> V_26 = V_2 -> V_27 ;
V_20 -> V_28 = V_2 -> V_29 ;
V_20 -> V_30 = V_2 -> V_31 ;
V_20 -> V_9 = V_2 -> V_9 ;
V_20 -> V_8 = V_2 -> V_8 ;
}
static void F_4 ( void * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_1 ( V_2 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_3 = 0 ;
}
static void F_5 ( void * V_18 )
{
struct V_1 * V_2 = V_18 ;
if ( ! V_2 )
return;
F_6 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
F_6 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
F_7 ( V_2 ) ;
}
static void * F_8 ( unsigned char * V_35 , int V_36 , int V_37 )
{
int V_38 ;
unsigned int V_39 , V_40 , V_15 ;
struct V_1 * V_2 ;
if ( V_36 != 3 || V_35 [ 0 ] != V_41 || V_35 [ 1 ] != 3
|| F_9 ( V_35 [ 2 ] ) != V_42 )
{
return NULL ;
}
V_38 = F_10 ( V_35 [ 2 ] ) ;
switch ( V_38 )
{
case 9 :
case 10 :
case 11 :
case 12 :
V_39 = 5003 ;
V_40 = 4 ;
break;
case 13 :
V_39 = 9001 ;
V_40 = 5 ;
break;
case 14 :
V_39 = 18013 ;
V_40 = 6 ;
break;
case 15 :
V_39 = 35023 ;
V_40 = 7 ;
break;
case 16 :
default:
return NULL ;
}
V_15 = F_11 ( V_38 ) ;
V_2 = F_12 ( sizeof ( struct V_1 ) ,
V_43 ) ;
if ( ! V_2 )
{
return NULL ;
}
V_2 -> V_33 = F_13 ( V_39 * sizeof( struct V_44 ) ) ;
if ( ! V_2 -> V_33 )
{
F_5 ( V_2 ) ;
return NULL ;
}
if ( ! V_37 )
{
V_2 -> V_34 = NULL ;
}
else
{
V_2 -> V_34 = F_13 ( ( V_15 + 1 ) * sizeof( V_2 -> V_34 [ 0 ] ) ) ;
if ( ! V_2 -> V_34 )
{
F_5 ( V_2 ) ;
return NULL ;
}
}
V_2 -> V_45 = sizeof ( struct V_1 ) +
( sizeof ( struct V_44 ) * V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_46 = V_38 ;
return ( void * ) V_2 ;
}
static void * F_14 ( unsigned char * V_35 , int V_36 )
{
return F_8 ( V_35 , V_36 , 0 ) ;
}
static void * F_15 ( unsigned char * V_35 , int V_36 )
{
return F_8 ( V_35 , V_36 , 1 ) ;
}
static int F_16 ( void * V_18 , unsigned char * V_35 ,
int V_36 , int V_47 , int V_48 , int V_37 )
{
struct V_1 * V_2 = V_18 ;
int V_49 ;
if ( ( V_36 != 3 ) || ( V_35 [ 0 ] != V_41 ) || ( V_35 [ 1 ] != 3 )
|| ( F_9 ( V_35 [ 2 ] ) != V_42 )
|| ( F_10 ( V_35 [ 2 ] ) != V_2 -> V_46 )
|| ( V_37 && V_2 -> V_34 == NULL ) )
{
return 0 ;
}
if ( V_37 )
{
V_49 = V_50 ;
do
{
V_2 -> V_34 [ V_49 ] = 1 ;
}
while ( V_49 -- > 0 );
}
V_49 = V_2 -> V_39 ;
while ( V_49 -- != 0 )
{
V_2 -> V_33 [ V_49 ] . V_51 = V_52 ;
V_2 -> V_33 [ V_49 ] . V_53 = 0 ;
}
V_2 -> V_47 = V_47 ;
V_2 -> V_54 = 0 ;
#ifndef F_17
if ( V_48 )
#endif
V_2 -> V_48 = 1 ;
F_4 ( V_2 ) ;
return 1 ;
}
static int F_18 ( void * V_18 , unsigned char * V_35 ,
int V_36 , int V_47 , int V_55 , int V_48 )
{
return F_16 ( V_18 , V_35 , V_36 , V_47 , V_48 , 0 ) ;
}
static int F_19 ( void * V_18 , unsigned char * V_35 ,
int V_36 , int V_47 , int V_55 , int V_54 ,
int V_48 )
{
return F_16 ( V_18 , V_35 , V_36 , V_47 , V_48 , 1 ) ;
}
static unsigned short * F_20 ( struct V_1 * V_2 , int V_56 )
{
if ( ( unsigned int ) V_56 > ( unsigned int ) V_2 -> V_15 )
{
F_21 ( L_1 , V_56 ) ;
V_56 = 0 ;
}
return F_22 ( V_2 , V_56 ) ;
}
static struct V_44 * F_23 ( struct V_1 * V_2 , int V_56 )
{
if ( ( unsigned int ) V_56 >= ( unsigned int ) V_2 -> V_39 )
{
F_21 ( L_2 , V_56 ) ;
V_56 = 0 ;
}
return F_24 ( V_2 , V_56 ) ;
}
static int F_25 ( void * V_18 , unsigned char * V_57 , unsigned char * V_58 ,
int V_59 , int V_60 )
{
struct V_1 * V_2 ;
int V_40 ;
unsigned int V_4 ;
unsigned int V_6 ;
unsigned int V_61 ;
unsigned long V_62 ;
int V_63 ;
unsigned long V_64 ;
struct V_44 * V_65 ;
unsigned char V_66 ;
int V_67 ;
int V_68 ;
int V_69 ;
int V_70 ;
unsigned char * V_71 ;
int V_72 ;
#define F_26 ( T_1 ) \
{ \
++olen; \
if (wptr) \
{ \
*wptr++ = (unsigned char) (v); \
if (olen >= osize) \
{ \
wptr = NULL; \
} \
} \
}
#define F_27 ( V_63 ) \
{ \
bitno -= n_bits; \
accm |= ((ent) << bitno); \
do \
{ \
PUTBYTE(accm >> 24); \
accm <<= 8; \
bitno += 8; \
} \
while (bitno <= 24); \
}
V_63 = F_28 ( V_57 ) ;
if ( V_63 < 0x21 || V_63 > 0xf9 )
{
return 0 ;
}
V_2 = (struct V_1 * ) V_18 ;
V_40 = V_2 -> V_40 ;
V_4 = V_2 -> V_4 ;
V_6 = V_2 -> V_6 ;
V_61 = 32 ;
V_62 = 0 ;
V_70 = F_11 ( V_6 ) ;
V_71 = V_58 ;
V_72 = V_73 + V_74 ;
if ( V_60 > V_59 )
{
V_60 = V_59 ;
}
if ( V_71 )
{
* V_71 ++ = F_29 ( V_57 ) ;
* V_71 ++ = F_30 ( V_57 ) ;
* V_71 ++ = 0 ;
* V_71 ++ = V_75 ;
* V_71 ++ = V_2 -> V_32 >> 8 ;
* V_71 ++ = V_2 -> V_32 ;
}
V_57 += V_73 ;
V_59 -= V_73 ;
V_69 = ++ V_59 ;
while ( -- V_69 > 0 )
{
V_66 = * V_57 ++ ;
V_64 = F_31 ( V_63 , V_66 ) ;
V_67 = F_32 ( V_63 , V_66 , V_40 ) ;
V_65 = F_23 ( V_2 , V_67 ) ;
if ( V_65 -> V_51 >= V_4 )
{
goto V_76;
}
if ( V_65 -> V_77 . V_64 == V_64 )
{
V_63 = V_65 -> V_51 + 1 ;
continue;
}
V_68 = ( V_67 == 0 ) ? 1 : V_67 ;
do
{
V_67 += V_68 ;
if ( V_67 >= V_2 -> V_39 )
{
V_67 -= V_2 -> V_39 ;
}
V_65 = F_23 ( V_2 , V_67 ) ;
if ( V_65 -> V_51 >= V_4 )
{
goto V_76;
}
}
while ( V_65 -> V_77 . V_64 != V_64 );
V_63 = V_65 -> V_51 + 1 ;
continue;
V_76:
F_27 ( V_63 ) ;
if ( V_4 < V_2 -> V_15 )
{
struct V_44 * V_78 ;
struct V_44 * V_79 ;
int V_49 ;
if ( V_4 >= V_70 )
{
V_2 -> V_6 = ++ V_6 ;
V_70 = F_11 ( V_6 ) ;
}
V_78 = F_23 ( V_2 , V_4 + 1 ) ;
V_49 = V_78 -> V_53 ;
V_79 = F_23 ( V_2 , V_49 ) ;
if ( V_79 -> V_51 == V_4 )
{
V_79 -> V_51 = V_52 ;
}
V_78 -> V_53 = V_67 ;
V_65 -> V_51 = V_4 ;
V_65 -> V_77 . V_64 = V_64 ;
V_2 -> V_4 = ++ V_4 ;
if ( V_2 -> V_34 )
{
unsigned short * V_80 = F_20 ( V_2 , V_4 ) ;
unsigned short * V_81 = F_20 ( V_2 , V_63 ) ;
* V_80 = * V_81 + 1 ;
}
}
V_63 = V_66 ;
}
F_27 ( V_63 ) ;
V_2 -> V_8 += V_72 - V_73 - V_74 ;
V_2 -> V_22 += V_59 ;
V_2 -> V_9 += V_59 ;
++ V_2 -> V_24 ;
++ V_2 -> V_32 ;
if ( V_61 < 32 )
{
++ V_2 -> V_8 ;
}
if ( F_2 ( V_2 ) )
{
F_27 ( V_82 ) ;
}
if ( V_61 != 32 )
{
F_26 ( ( V_62 | ( 0xff << ( V_61 - 8 ) ) ) >> 24 ) ;
}
if ( V_4 >= V_70 && V_4 < V_2 -> V_15 )
{
V_2 -> V_6 ++ ;
}
if ( V_71 == NULL )
{
++ V_2 -> V_31 ;
V_2 -> V_29 += V_59 ;
V_72 = 0 ;
}
else
{
++ V_2 -> V_27 ;
V_2 -> V_25 += V_72 ;
}
return V_72 ;
#undef F_27
#undef F_26
}
static void F_33 ( void * V_18 , unsigned char * V_83 , int V_84 )
{
( void ) F_25 ( V_18 , V_83 , ( char * ) 0 , V_84 , 0 ) ;
}
static int F_34 ( void * V_18 , unsigned char * V_83 , int V_59 ,
unsigned char * V_58 , int V_60 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
unsigned long V_62 ;
unsigned int V_61 ;
unsigned int V_6 ;
unsigned int V_85 ;
struct V_44 * V_65 ;
int V_86 ;
int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
unsigned int V_90 ;
unsigned char * V_91 ;
unsigned char * V_71 ;
int V_92 ;
int V_93 ;
int V_69 ;
int V_94 ;
int V_95 ;
V_2 = (struct V_1 * ) V_18 ;
V_4 = V_2 -> V_4 ;
V_62 = 0 ;
V_61 = 32 ;
V_6 = V_2 -> V_6 ;
V_85 = 32 - V_6 ;
V_92 = F_29 ( V_83 ) ;
V_93 = F_30 ( V_83 ) ;
V_87 = ( V_83 [ 4 ] << 8 ) + V_83 [ 5 ] ;
V_83 += ( V_73 + 2 ) ;
V_69 = V_59 - ( V_73 + 2 ) ;
if ( V_87 != V_2 -> V_32 )
{
if ( V_2 -> V_48 )
{
F_21 ( L_3 ,
V_2 -> V_47 , V_87 , V_2 -> V_32 - 1 ) ;
}
return V_96 ;
}
++ V_2 -> V_32 ;
V_2 -> V_8 += V_69 ;
V_71 = V_58 ;
* V_71 ++ = V_92 ;
* V_71 ++ = V_93 ;
* V_71 ++ = 0 ;
V_89 = V_82 ;
V_86 = 3 ;
for (; ; )
{
if ( V_69 -- <= 0 )
{
V_2 -> V_9 += ( V_86 - 3 ) ;
break;
}
V_61 -= 8 ;
V_62 |= * V_83 ++ << V_61 ;
if ( V_85 < V_61 )
{
continue;
}
V_88 = V_62 >> V_85 ;
V_62 <<= V_6 ;
V_61 += V_6 ;
if ( V_88 == V_82 )
{
if ( V_69 > 0 )
{
if ( V_2 -> V_48 )
{
F_21 ( L_4 , V_2 -> V_47 ) ;
}
return V_97 ;
}
F_1 ( V_2 ) ;
break;
}
if ( ( V_88 > V_4 + 2 ) || ( V_88 > V_2 -> V_15 )
|| ( V_88 > V_4 && V_89 == V_82 ) )
{
if ( V_2 -> V_48 )
{
F_21 ( L_5 ,
V_2 -> V_47 , V_88 , V_89 ) ;
F_21 ( L_6 ,
V_4 , V_86 , V_2 -> V_32 ) ;
}
return V_97 ;
}
if ( V_88 > V_4 )
{
V_90 = V_89 ;
V_95 = 1 ;
}
else
{
V_90 = V_88 ;
V_95 = 0 ;
}
V_94 = * ( F_20 ( V_2 , V_90 ) ) ;
V_86 += V_94 + V_95 ;
if ( V_86 > V_60 )
{
if ( V_2 -> V_48 )
{
F_21 ( L_7 , V_2 -> V_47 ) ;
#ifdef F_17
F_21 ( L_8 ,
V_69 , V_90 , V_94 , V_86 ) ;
#endif
}
return V_97 ;
}
V_71 += V_94 ;
V_91 = V_71 ;
while ( V_90 > V_50 )
{
struct V_44 * V_78 = F_23 ( V_2 , V_90 ) ;
V_65 = F_23 ( V_2 , V_78 -> V_53 ) ;
#ifdef F_17
if ( -- V_94 <= 0 || V_65 -> V_51 != V_90 - 1 )
{
if ( V_94 <= 0 )
{
F_21 ( L_9 , V_2 -> V_47 ) ;
F_21 ( L_10 ,
V_88 , V_90 , V_78 -> V_53 , V_4 ) ;
}
else
{
if ( V_65 -> V_51 != V_90 - 1 )
{
F_21 ( L_11
L_12 ,
V_2 -> V_47 , V_88 , V_90 ) ;
F_21 ( L_13 ,
V_89 , V_78 -> V_53 , V_65 -> V_51 ) ;
}
}
return V_97 ;
}
#endif
* -- V_91 = V_65 -> V_77 . V_98 . V_99 ;
V_90 = V_65 -> V_77 . V_98 . V_100 ;
}
* -- V_91 = V_90 ;
#ifdef F_17
if ( -- V_94 != 0 )
{
F_21 ( L_14 ,
V_2 -> V_47 , V_94 , V_88 , V_4 ) ;
}
#endif
if ( V_95 )
{
* V_71 ++ = V_90 ;
}
if ( V_89 != V_82 && V_4 < V_2 -> V_15 )
{
struct V_44 * V_78 , * V_79 ;
unsigned short * V_101 , * V_102 ;
unsigned long V_64 ;
int V_67 , V_68 , V_49 ;
V_64 = F_31 ( V_89 , V_90 ) ;
V_67 = F_32 ( V_89 , V_90 , V_2 -> V_40 ) ;
V_65 = F_23 ( V_2 , V_67 ) ;
if ( V_65 -> V_51 < V_4 )
{
V_68 = ( V_67 == 0 ) ? 1 : V_67 ;
do
{
V_67 += V_68 ;
if ( V_67 >= V_2 -> V_39 )
{
V_67 -= V_2 -> V_39 ;
}
V_65 = F_23 ( V_2 , V_67 ) ;
}
while ( V_65 -> V_51 < V_4 );
}
V_78 = F_23 ( V_2 , V_4 + 1 ) ;
V_49 = V_78 -> V_53 ;
V_79 = F_23 ( V_2 , V_49 ) ;
if ( V_79 -> V_51 == V_4 )
{
V_79 -> V_51 = V_52 ;
}
V_78 -> V_53 = V_67 ;
V_65 -> V_51 = V_4 ;
V_65 -> V_77 . V_64 = V_64 ;
V_2 -> V_4 = ++ V_4 ;
V_101 = F_20 ( V_2 , V_4 ) ;
V_102 = F_20 ( V_2 , V_89 ) ;
* V_101 = * V_102 + 1 ;
if ( V_4 >= F_11 ( V_6 ) && V_4 < V_2 -> V_15 )
{
V_2 -> V_6 = ++ V_6 ;
V_85 = 32 - V_6 ;
}
}
V_89 = V_88 ;
}
++ V_2 -> V_27 ;
++ V_2 -> V_24 ;
V_2 -> V_25 += V_59 - V_74 - V_73 ;
V_2 -> V_22 += V_86 ;
if ( F_2 ( V_2 ) )
{
if ( V_2 -> V_48 )
{
F_21 ( L_15 ,
V_2 -> V_47 , V_2 -> V_32 - 1 ) ;
}
}
return V_86 ;
}
static int T_2 F_35 ( void )
{
int V_103 = F_36 ( & V_104 ) ;
if ( V_103 == 0 )
F_21 ( V_105 L_16 ) ;
return V_103 ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_104 ) ;
}
