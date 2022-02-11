static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 ++ ;
V_2 -> V_4 = V_5 - 1 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_13 ;
}
static int F_2 ( struct V_1 * V_2 )
{
unsigned int V_14 ;
if ( V_2 -> V_9 >= V_2 -> V_12 )
{
if ( V_2 -> V_9 >= V_15 || V_2 -> V_8 >= V_15 )
{
V_2 -> V_9 -= ( V_2 -> V_9 >> 2 ) ;
V_2 -> V_8 -= ( V_2 -> V_8 >> 2 ) ;
}
V_2 -> V_12 = V_2 -> V_9 + V_13 ;
if ( V_2 -> V_4 >= V_2 -> V_16 )
{
V_14 = V_2 -> V_9 << V_17 ;
if ( V_2 -> V_8 != 0 )
{
V_14 /= V_2 -> V_8 ;
}
if ( V_14 < V_2 -> V_11 || V_14 < 1 * V_18 )
{
F_1 ( V_2 ) ;
return 1 ;
}
V_2 -> V_11 = V_14 ;
}
}
return 0 ;
}
static void F_3 ( void * V_19 , struct V_20 * V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
V_21 -> V_22 = V_2 -> V_23 ;
V_21 -> V_24 = V_2 -> V_25 ;
V_21 -> V_26 = V_2 -> V_26 ;
V_21 -> V_27 = V_2 -> V_28 ;
V_21 -> V_29 = V_2 -> V_30 ;
V_21 -> V_31 = V_2 -> V_10 ;
V_21 -> V_9 = V_2 -> V_9 ;
V_21 -> V_8 = V_2 -> V_8 ;
}
static void F_4 ( void * V_19 , unsigned char V_32 , unsigned char V_33 ,
unsigned char * V_34 , unsigned V_35 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
F_1 ( V_2 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_3 = 0 ;
}
static void F_5 ( void * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
if ( V_2 ) {
F_6 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
F_6 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
F_7 ( V_2 ) ;
}
}
static void * F_8 ( struct V_41 * V_34 )
{
int V_42 ;
unsigned int V_43 , V_44 , V_16 ;
struct V_1 * V_2 ;
int V_45 ;
static unsigned int V_46 [] [ 2 ] = {
{ 5003 , 4 } , { 5003 , 4 } , { 5003 , 4 } , { 5003 , 4 } ,
{ 9001 , 5 } , { 18013 , 6 } , { 35023 , 7 } , { 69001 , 8 }
} ;
if ( V_34 -> V_47 != 1 || V_34 -> V_48 != V_49
|| F_9 ( V_34 -> V_50 [ 0 ] ) != V_51 )
return NULL ;
V_42 = F_10 ( V_34 -> V_50 [ 0 ] ) ;
if ( V_42 < 9 || V_42 > 15 )
return NULL ;
V_43 = V_46 [ V_42 - 9 ] [ 0 ] ;
V_44 = V_46 [ V_42 - 9 ] [ 1 ] ;
V_16 = F_11 ( V_42 ) ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_53 = V_34 -> V_54 & V_55 ;
V_45 = V_2 -> V_53 ? 0 : 1 ;
V_2 -> V_39 = F_13 ( V_43 * sizeof( struct V_56 ) ) ;
if ( ! V_2 -> V_39 ) {
F_5 ( V_2 ) ;
return NULL ;
}
if ( ! V_45 )
V_2 -> V_40 = NULL ;
else {
V_2 -> V_40 = F_13 ( ( V_16 + 1 ) * sizeof( V_2 -> V_40 [ 0 ] ) ) ;
if ( ! V_2 -> V_40 ) {
F_5 ( V_2 ) ;
return ( NULL ) ;
}
}
V_2 -> V_57 = sizeof( struct V_1 ) + ( sizeof( struct V_56 ) * V_43 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_58 = V_42 ;
return ( void * ) V_2 ;
}
static int F_14 ( void * V_19 , struct V_41 * V_34 , int V_59 , int V_60 )
{
struct V_1 * V_2 = V_19 ;
int V_61 ;
int V_45 ;
if ( ! V_19 || ! V_34 ) {
F_15 ( V_62 L_1 , V_59 , ( long ) V_19 , ( long ) V_34 ) ;
return 0 ;
}
V_45 = V_2 -> V_53 ? 0 : 1 ;
if ( V_34 -> V_47 != 1 || V_34 -> V_48 != V_49
|| ( F_9 ( V_34 -> V_50 [ 0 ] ) != V_51 )
|| ( F_10 ( V_34 -> V_50 [ 0 ] ) != V_2 -> V_58 )
|| ( V_45 && V_2 -> V_40 == NULL ) ) {
F_15 ( V_62 L_2 , V_34 -> V_47 , V_34 -> V_48 , V_34 -> V_50 [ 0 ] , V_45 , ( unsigned long ) V_2 -> V_40 ) ;
return 0 ;
}
if ( V_45 )
for ( V_61 = V_63 ; V_61 >= 0 ; V_61 -- )
V_2 -> V_40 [ V_61 ] = 1 ;
V_61 = V_2 -> V_43 ;
while ( V_61 -- != 0 ) {
V_2 -> V_39 [ V_61 ] . V_64 = V_65 ;
V_2 -> V_39 [ V_61 ] . V_66 = 0 ;
}
V_2 -> V_59 = V_59 ;
V_2 -> V_67 = 0 ;
V_2 -> V_60 = 1 ;
F_4 ( V_2 , 0 , 0 , NULL , 0 , NULL ) ;
return 1 ;
}
static unsigned short * F_16 ( struct V_1 * V_2 , int V_68 )
{
if ( ( unsigned int ) V_68 > ( unsigned int ) V_2 -> V_16 ) {
F_15 ( V_69 L_3 , V_68 ) ;
V_68 = 0 ;
}
return F_17 ( V_2 , V_68 ) ;
}
static struct V_56 * F_18 ( struct V_1 * V_2 , int V_68 )
{
if ( ( unsigned int ) V_68 >= ( unsigned int ) V_2 -> V_43 ) {
F_15 ( V_69 L_4 , V_68 ) ;
V_68 = 0 ;
}
return F_19 ( V_2 , V_68 ) ;
}
static int F_20 ( void * V_19 , struct V_70 * V_71 , struct V_70 * V_72 , int V_73 )
{
struct V_1 * V_2 ;
int V_44 ;
unsigned int V_4 ;
unsigned int V_6 ;
unsigned int V_74 ;
unsigned long V_75 ;
int V_76 ;
unsigned long V_77 ;
struct V_56 * V_78 ;
unsigned char V_79 ;
int V_80 , V_81 , V_82 , V_83 ;
unsigned char * V_84 = V_71 -> V_34 ;
int V_85 = V_71 -> V_35 ;
#define F_21 ( V_76 ) \
{ \
bitno -= n_bits; \
accm |= ((ent) << bitno); \
do { \
if (skb_out && skb_tailroom(skb_out) > 0) \
*(skb_put(skb_out, 1)) = (unsigned char)(accm >> 24); \
accm <<= 8; \
bitno += 8; \
} while (bitno <= 24); \
}
F_15 ( V_69 L_5 , V_73 ) ;
V_76 = V_73 ;
if ( V_73 < 0x21 || V_73 > 0xf9 || ! ( V_73 & 0x1 ) )
return 0 ;
V_2 = (struct V_1 * ) V_19 ;
V_44 = V_2 -> V_44 ;
V_4 = V_2 -> V_4 ;
V_6 = V_2 -> V_6 ;
V_74 = 32 ;
V_75 = 0 ;
V_83 = F_11 ( V_6 ) ;
if ( V_72 && F_22 ( V_72 ) >= 2 ) {
char * V_86 = F_23 ( V_72 , 2 ) ;
V_86 [ 0 ] = V_2 -> V_38 >> 8 ;
V_86 [ 1 ] = V_2 -> V_38 ;
}
V_82 = ++ V_85 ;
while ( -- V_82 > 0 ) {
V_79 = * V_84 ++ ;
V_77 = F_24 ( V_76 , V_79 ) ;
V_80 = F_25 ( V_76 , V_79 , V_44 ) ;
V_78 = F_18 ( V_2 , V_80 ) ;
if ( V_78 -> V_64 >= V_4 )
goto V_87;
if ( V_78 -> V_77 == V_77 ) {
V_76 = V_78 -> V_64 + 1 ;
continue;
}
V_81 = ( V_80 == 0 ) ? 1 : V_80 ;
do {
V_80 += V_81 ;
if ( V_80 >= V_2 -> V_43 )
V_80 -= V_2 -> V_43 ;
V_78 = F_18 ( V_2 , V_80 ) ;
if ( V_78 -> V_64 >= V_4 )
goto V_87;
} while ( V_78 -> V_77 != V_77 );
V_76 = V_78 -> V_64 + 1 ;
continue;
V_87:
F_21 ( V_76 ) ;
if ( V_4 < V_2 -> V_16 ) {
struct V_56 * V_88 ;
struct V_56 * V_89 ;
int V_61 ;
if ( V_4 >= V_83 ) {
V_2 -> V_6 = ++ V_6 ;
V_83 = F_11 ( V_6 ) ;
}
V_88 = F_18 ( V_2 , V_4 + 1 ) ;
V_61 = V_88 -> V_66 ;
V_89 = F_18 ( V_2 , V_61 ) ;
if ( V_89 -> V_64 == V_4 )
V_89 -> V_64 = V_65 ;
V_88 -> V_66 = V_80 ;
V_78 -> V_64 = V_4 ;
V_78 -> V_77 = V_77 ;
V_2 -> V_4 = ++ V_4 ;
if ( V_2 -> V_40 ) {
unsigned short * V_90 = F_16 ( V_2 , V_4 ) ;
unsigned short * V_91 = F_16 ( V_2 , V_76 ) ;
* V_90 = * V_91 + 1 ;
}
}
V_76 = V_79 ;
}
F_21 ( V_76 ) ;
if ( V_72 )
V_2 -> V_8 += V_72 -> V_35 ;
V_2 -> V_23 += V_85 ;
V_2 -> V_9 += V_85 ;
++ V_2 -> V_25 ;
++ V_2 -> V_38 ;
if ( V_74 < 32 )
++ V_2 -> V_8 ;
if ( F_2 ( V_2 ) )
F_21 ( V_92 ) ;
if ( V_74 < 32 && V_72 && F_22 ( V_72 ) > 0 )
* ( F_23 ( V_72 , 1 ) ) = ( unsigned char ) ( ( V_75 | ( 0xff << ( V_74 - 8 ) ) ) >> 24 ) ;
if ( V_4 >= V_83 && V_4 < V_2 -> V_16 )
V_2 -> V_6 ++ ;
if ( ! V_72 || ( V_72 && V_72 -> V_35 >= V_71 -> V_35 ) ) {
++ V_2 -> V_10 ;
V_2 -> V_30 += V_85 ;
return 0 ;
}
++ V_2 -> V_28 ;
V_2 -> V_26 += V_72 -> V_35 ;
return V_72 -> V_35 ;
#undef F_21
}
static void F_26 ( void * V_19 , struct V_70 * V_71 , int V_73 )
{
F_20 ( V_19 , V_71 , NULL , V_73 ) ;
}
static int F_27 ( void * V_19 , struct V_70 * V_71 , struct V_70 * V_72 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
unsigned long V_75 ;
unsigned int V_74 ;
unsigned int V_6 ;
unsigned int V_93 ;
struct V_56 * V_78 ;
int V_94 ;
unsigned int V_95 ;
unsigned int V_96 ;
unsigned int V_97 ;
unsigned char * V_98 , * V_99 ;
int V_82 ;
int V_100 ;
int V_101 ;
V_2 = (struct V_1 * ) V_19 ;
V_4 = V_2 -> V_4 ;
V_75 = 0 ;
V_74 = 32 ;
V_6 = V_2 -> V_6 ;
V_93 = 32 - V_6 ;
F_15 ( V_69 L_6 ) ;
if ( ! V_71 || ! V_72 ) {
F_15 ( V_62 L_7 ) ;
return V_102 ;
}
if ( ( V_98 = F_28 ( V_71 , 2 ) ) == NULL ) {
return V_102 ;
}
V_98 -= 2 ;
V_94 = ( V_98 [ 0 ] << 8 ) + V_98 [ 1 ] ;
V_82 = V_71 -> V_35 ;
V_99 = V_71 -> V_34 ;
if ( V_94 != V_2 -> V_38 ) {
if ( V_2 -> V_60 ) {
F_15 ( V_69 L_8 ,
V_2 -> V_59 , V_94 , V_2 -> V_38 - 1 ) ;
}
return V_102 ;
}
++ V_2 -> V_38 ;
V_2 -> V_8 += V_82 ;
if ( F_22 ( V_72 ) > 0 )
* ( F_23 ( V_72 , 1 ) ) = 0 ;
else
return V_103 ;
V_96 = V_92 ;
for (; ; ) {
if ( V_82 -- <= 0 ) {
V_2 -> V_9 += ( V_72 -> V_35 - 1 ) ;
break;
}
V_74 -= 8 ;
V_75 |= * V_99 ++ << V_74 ;
if ( V_93 < V_74 )
continue;
V_95 = V_75 >> V_93 ;
V_75 <<= V_6 ;
V_74 += V_6 ;
if ( V_95 == V_92 ) {
if ( V_82 > 0 ) {
if ( V_2 -> V_60 )
F_15 ( V_69 L_9 , V_2 -> V_59 ) ;
return V_104 ;
}
F_1 ( V_2 ) ;
break;
}
if ( ( V_95 > V_4 + 2 ) || ( V_95 > V_2 -> V_16 )
|| ( V_95 > V_4 && V_96 == V_92 ) ) {
if ( V_2 -> V_60 ) {
F_15 ( V_69 L_10 ,
V_2 -> V_59 , V_95 , V_96 ) ;
F_15 ( V_69 L_11 ,
V_4 , V_72 -> V_35 , V_2 -> V_38 ) ;
}
return V_104 ;
}
if ( V_95 > V_4 ) {
V_97 = V_96 ;
V_101 = 1 ;
} else {
V_97 = V_95 ;
V_101 = 0 ;
}
V_100 = * ( F_16 ( V_2 , V_97 ) ) ;
if ( F_22 ( V_72 ) < V_100 + V_101 ) {
if ( V_2 -> V_60 ) {
F_15 ( V_69 L_12 , V_2 -> V_59 ) ;
#ifdef F_29
F_15 ( V_69 L_13 ,
V_82 , V_97 , V_100 , V_72 -> V_35 ) ;
#endif
}
return V_104 ;
}
V_98 = F_23 ( V_72 , V_100 ) ;
V_98 += V_100 ;
while ( V_97 > V_63 ) {
struct V_56 * V_88 = F_18 ( V_2 , V_97 ) ;
V_78 = F_18 ( V_2 , V_88 -> V_66 ) ;
#ifdef F_29
if ( -- V_100 <= 0 || V_78 -> V_64 != V_97 - 1 ) {
if ( V_100 <= 0 ) {
F_15 ( V_62 L_14 , V_2 -> V_59 ) ;
F_15 ( V_62 L_15 , V_95 , V_97 , V_88 -> V_66 , V_4 ) ;
} else {
if ( V_78 -> V_64 != V_97 - 1 ) {
F_15 ( V_62 L_16 , V_2 -> V_59 , V_95 , V_97 ) ;
F_15 ( V_62 L_17 , V_96 , V_88 -> V_66 , V_78 -> V_64 ) ;
}
}
return V_104 ;
}
#endif
{
T_1 V_77 = V_78 -> V_77 ;
* -- V_98 = ( V_77 >> 16 ) & 0xff ;
V_97 = V_77 & 0xffff ;
}
}
* -- V_98 = V_97 ;
#ifdef F_29
if ( -- V_100 != 0 )
F_15 ( V_62 L_18 , V_2 -> V_59 , V_100 , V_95 , V_4 ) ;
#endif
if ( V_101 )
* ( F_23 ( V_72 , 1 ) ) = V_97 ;
if ( V_96 != V_92 && V_4 < V_2 -> V_16 ) {
struct V_56 * V_88 , * V_89 ;
T_2 * V_105 , * V_106 ;
unsigned long V_77 ;
int V_80 , V_81 , V_61 ;
V_77 = F_24 ( V_96 , V_97 ) ;
V_80 = F_25 ( V_96 , V_97 , V_2 -> V_44 ) ;
V_78 = F_18 ( V_2 , V_80 ) ;
if ( V_78 -> V_64 < V_4 ) {
V_81 = ( V_80 == 0 ) ? 1 : V_80 ;
do {
V_80 += V_81 ;
if ( V_80 >= V_2 -> V_43 )
V_80 -= V_2 -> V_43 ;
V_78 = F_18 ( V_2 , V_80 ) ;
} while ( V_78 -> V_64 < V_4 );
}
V_88 = F_18 ( V_2 , V_4 + 1 ) ;
V_61 = V_88 -> V_66 ;
V_89 = F_18 ( V_2 , V_61 ) ;
if ( V_89 -> V_64 == V_4 )
V_89 -> V_64 = V_65 ;
V_88 -> V_66 = V_80 ;
V_78 -> V_64 = V_4 ;
V_78 -> V_77 = V_77 ;
V_2 -> V_4 = ++ V_4 ;
V_105 = F_16 ( V_2 , V_4 ) ;
V_106 = F_16 ( V_2 , V_96 ) ;
* V_105 = * V_106 + 1 ;
if ( V_4 >= F_11 ( V_6 ) && V_4 < V_2 -> V_16 ) {
V_2 -> V_6 = ++ V_6 ;
V_93 = 32 - V_6 ;
}
}
V_96 = V_95 ;
}
++ V_2 -> V_28 ;
++ V_2 -> V_25 ;
V_2 -> V_26 += V_71 -> V_35 - V_107 ;
V_2 -> V_23 += V_72 -> V_35 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_60 )
F_15 ( V_69 L_19 ,
V_2 -> V_59 , V_2 -> V_38 - 1 ) ;
}
return V_72 -> V_35 ;
}
static int T_3 F_30 ( void )
{
int V_108 = F_31 ( & V_109 ) ;
if ( V_108 == 0 )
F_15 ( V_110 L_20 ) ;
return V_108 ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_109 ) ;
}
