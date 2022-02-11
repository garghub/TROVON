static void F_1 ( T_1 * V_1 , T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 , const T_1 * V_6 )
{
#define F_2 (*(((u32 *)alo)+INDEX_LOW))
#define F_3 (*(((u32 *)alo)+INDEX_HIGH))
#define F_4 (*(((u32 *)ahi)+INDEX_LOW))
#define F_5 (*(((u32 *)ahi)+INDEX_HIGH))
#define F_6 (*(((u32 *)kl)+INDEX_LOW))
#define F_7 (*(((u32 *)kl)+INDEX_HIGH))
#define F_8 (*(((u32 *)kh)+INDEX_LOW))
#define F_9 (*(((u32 *)kh)+INDEX_HIGH))
T_1 V_7 , V_8 , V_9 ;
T_2 V_10 ;
V_7 = F_10 ( F_5 , F_9 ) ;
V_7 += V_7 ;
V_7 += * ( T_1 * ) V_5 ;
V_7 += F_10 ( F_2 , F_8 ) ;
V_7 += F_10 ( F_3 , F_7 ) ;
V_7 += F_10 ( F_4 , F_6 ) ;
V_9 = ( T_2 ) ( V_7 ) ;
V_7 >>= 32 ;
V_7 += F_10 ( F_2 , F_9 ) ;
V_7 += F_10 ( F_3 , F_8 ) ;
V_7 += F_10 ( F_4 , F_7 ) ;
V_7 += F_10 ( F_5 , F_6 ) ;
V_9 |= ( ( T_1 ) ( ( T_2 ) V_7 & 0x7fffffff ) ) << 32 ;
V_7 >>= 31 ;
V_7 += ( T_1 ) ( ( ( T_2 * ) V_6 ) [ V_11 ] ) ;
V_7 += F_10 ( F_2 , F_6 ) ;
V_8 = F_10 ( F_3 , F_9 ) ;
V_8 += F_10 ( F_4 , F_8 ) ;
V_8 += F_10 ( F_5 , F_7 ) ;
V_8 += V_8 ;
V_7 += V_8 ;
V_10 = ( T_2 ) ( V_7 ) ;
V_7 >>= 32 ;
V_7 += ( T_1 ) ( ( ( T_2 * ) V_6 ) [ V_12 ] ) ;
V_7 += F_10 ( F_2 , F_7 ) ;
V_7 += F_10 ( F_3 , F_6 ) ;
V_8 = F_10 ( F_4 , F_9 ) ;
V_8 += F_10 ( F_5 , F_8 ) ;
V_8 += V_8 ;
V_7 += V_8 ;
* ( T_1 * ) ( V_2 ) = ( V_7 << 32 ) | V_10 ;
V_7 >>= 32 ;
* ( T_1 * ) ( V_1 ) = V_7 + V_9 ;
#undef F_2
#undef F_3
#undef F_4
#undef F_5
#undef F_6
#undef F_7
#undef F_8
#undef F_9
}
static void F_11 ( struct V_13 * V_14 )
{
V_14 -> V_15 [ 0 ] = V_14 -> V_16 [ 0 ] ;
V_14 -> V_15 [ 1 ] = V_14 -> V_16 [ 1 ] ;
V_14 -> V_17 = 0 ;
}
static T_1 F_12 ( T_1 V_18 , T_1 V_19 , T_1 F_7 , T_1 F_8 , T_1 V_20 )
{
T_1 V_21 , V_22 , V_9 , V_23 = 0 ;
V_9 = V_18 >> 63 ;
V_18 &= V_24 ;
F_13 ( V_18 , V_19 , V_20 , V_9 ) ;
V_9 = ( V_18 > V_24 ) + ( ( V_18 == V_24 ) && ( V_19 == V_25 ) ) ;
F_13 ( V_18 , V_19 , V_23 , V_9 ) ;
V_18 &= V_24 ;
V_9 = V_18 + ( V_19 >> 32 ) ;
V_9 += ( V_9 >> 32 ) ;
V_9 += ( T_2 ) V_9 > 0xfffffffeu ;
V_18 += ( V_9 >> 32 ) ;
V_19 += ( V_18 << 32 ) ;
V_18 += F_7 ;
V_18 += ( 0 - ( V_18 < F_7 ) ) & 257 ;
V_19 += F_8 ;
V_19 += ( 0 - ( V_19 < F_8 ) ) & 257 ;
F_14 ( V_21 , V_22 , V_18 , V_19 ) ;
V_9 = V_21 >> 56 ;
F_13 ( V_9 , V_22 , V_23 , V_21 ) ;
V_21 <<= 8 ;
F_13 ( V_9 , V_22 , V_23 , V_21 ) ;
V_9 += V_9 << 8 ;
V_22 += V_9 ;
V_22 += ( 0 - ( V_22 < V_9 ) ) & 257 ;
V_22 += ( 0 - ( V_22 > V_26 - 1 ) ) & 257 ;
return V_22 ;
}
static void F_15 ( const unsigned char * V_27 ,
unsigned int V_28 ,
struct V_13 * V_14 )
{
T_1 V_21 , V_22 , * V_29 ;
const T_1 * V_30 = ( T_1 * ) V_14 -> V_31 ;
int V_32 ;
T_1 V_33 , V_34 ;
T_1 V_35 = V_14 -> V_16 [ 0 ] ;
T_1 V_36 = V_14 -> V_16 [ 1 ] ;
if ( ! V_28 )
return;
F_16 ( V_28 % V_37 ) ;
V_29 = ( T_1 * ) V_27 ;
V_32 = V_28 / V_37 ;
V_33 = V_14 -> V_15 [ 0 ] ;
V_34 = V_14 -> V_15 [ 1 ] ;
if ( ! V_14 -> V_17 ) {
V_14 -> V_17 = 1 ;
F_17 ( V_29 , V_30 , V_37 / 8 , V_21 , V_22 ) ;
V_21 &= V_38 ;
F_13 ( V_33 , V_34 , V_21 , V_22 ) ;
V_29 += ( V_37 / sizeof( T_1 ) ) ;
V_32 -- ;
}
while ( V_32 -- ) {
F_17 ( V_29 , V_30 , V_37 / 8 , V_21 , V_22 ) ;
V_21 &= V_38 ;
F_18 ( V_33 , V_34 , V_35 , V_36 , V_21 , V_22 ) ;
V_29 += ( V_37 / sizeof( T_1 ) ) ;
}
V_14 -> V_15 [ 0 ] = V_33 ;
V_14 -> V_15 [ 1 ] = V_34 ;
}
static T_1 F_19 ( unsigned char V_27 [] , unsigned int V_28 ,
T_1 * V_39 , struct V_13 * V_14 )
{
T_1 V_21 , V_22 , * V_29 ;
const T_1 * V_30 = ( T_1 * ) V_14 -> V_31 ;
int V_32 , V_40 ;
T_1 V_33 , V_34 ;
T_1 V_35 = V_14 -> V_16 [ 0 ] ;
T_1 V_36 = V_14 -> V_16 [ 1 ] ;
V_29 = ( T_1 * ) V_27 ;
V_32 = V_28 / V_37 ;
V_40 = V_28 % V_37 ;
if ( V_14 -> V_17 ) {
V_33 = V_14 -> V_15 [ 0 ] ;
V_34 = V_14 -> V_15 [ 1 ] ;
} else if ( V_32 ) {
F_17 ( V_29 , V_30 , V_37 / 8 , V_33 , V_34 ) ;
V_33 &= V_38 ;
F_13 ( V_33 , V_34 , V_35 , V_36 ) ;
V_29 += ( V_37 / sizeof( T_1 ) ) ;
V_32 -- ;
} else if ( V_40 ) {
F_20 ( V_29 , V_30 , 2 * ( ( V_40 + 15 ) / 16 ) , V_33 , V_34 ) ;
V_33 &= V_38 ;
F_13 ( V_33 , V_34 , V_35 , V_36 ) ;
V_29 += ( V_37 / sizeof( T_1 ) ) ;
goto V_41;
} else {
V_33 = V_35 ; V_34 = V_36 ;
goto V_41;
}
while ( V_32 -- ) {
F_17 ( V_29 , V_30 , V_37 / 8 , V_21 , V_22 ) ;
V_21 &= V_38 ;
F_18 ( V_33 , V_34 , V_35 , V_36 , V_21 , V_22 ) ;
V_29 += ( V_37 / sizeof( T_1 ) ) ;
}
if ( V_40 ) {
F_20 ( V_29 , V_30 , 2 * ( ( V_40 + 15 ) / 16 ) , V_21 , V_22 ) ;
V_21 &= V_38 ;
F_18 ( V_33 , V_34 , V_35 , V_36 , V_21 , V_22 ) ;
}
V_41:
F_11 ( V_14 ) ;
V_40 *= 8 ;
return F_12 ( V_33 , V_34 , V_14 -> V_42 [ 0 ] , V_14 -> V_42 [ 1 ] , V_40 ) ;
}
static T_1 F_21 ( unsigned char V_27 [] , unsigned int V_28 ,
const unsigned char V_43 [ 16 ] , T_1 * V_39 ,
struct V_44 * V_14 )
{
T_1 * V_45 , * V_46 ;
T_1 V_7 , V_47 ;
int V_32 ;
V_45 = V_14 -> V_48 . V_49 ;
V_46 = V_14 -> V_48 . V_50 ;
V_32 = V_43 [ 15 ] & 1 ;
if ( ( * ( T_1 * ) ( V_43 + 8 ) != V_45 [ 1 ] ) || ( * ( T_1 * ) ( V_43 ) != V_45 [ 0 ] ) ) {
V_45 [ 0 ] = * ( T_1 * ) ( V_43 ) ;
V_45 [ 1 ] = * ( T_1 * ) ( V_43 + 8 ) ;
( ( unsigned char * ) V_45 ) [ 15 ] &= 0xFE ;
F_22 ( V_14 -> V_51 ,
( unsigned char * ) V_46 , ( unsigned char * ) V_45 ) ;
( ( unsigned char * ) V_45 ) [ 15 ] |= ( unsigned char ) ( 1 - V_32 ) ;
}
V_7 = F_23 ( V_46 + V_32 ) ;
V_47 = F_19 ( V_27 , V_28 , ( T_1 * ) 0 , & V_14 -> V_48 ) ;
return F_24 ( V_7 + V_47 ) ;
}
static int F_25 ( unsigned char V_52 [] , struct V_44 * V_14 )
{
T_1 V_53 [ 2 ] = { 0 } , V_54 [ 2 ] ;
unsigned V_32 ;
int V_55 = 0 ;
V_55 = F_26 ( V_14 -> V_51 , V_52 , V_56 ) ;
if ( V_55 )
return V_55 ;
( ( unsigned char * ) V_53 ) [ 0 ] = 0x80 ;
for ( V_32 = 0 ; V_32 < sizeof( V_14 -> V_48 . V_31 ) / 8 ; V_32 += 2 ) {
F_22 ( V_14 -> V_51 ,
( unsigned char * ) V_54 , ( unsigned char * ) V_53 ) ;
V_14 -> V_48 . V_31 [ V_32 ] = F_23 ( V_54 ) ;
V_14 -> V_48 . V_31 [ V_32 + 1 ] = F_23 ( V_54 + 1 ) ;
( ( unsigned char * ) V_53 ) [ 15 ] += 1 ;
}
( ( unsigned char * ) V_53 ) [ 0 ] = 0xC0 ;
V_53 [ 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < sizeof( V_14 -> V_48 . V_16 ) / 8 ; V_32 += 2 ) {
F_22 ( V_14 -> V_51 ,
( unsigned char * ) V_54 , ( unsigned char * ) V_53 ) ;
V_14 -> V_48 . V_15 [ V_32 ] =
V_14 -> V_48 . V_16 [ V_32 ] =
F_23 ( V_54 ) & V_57 ;
V_14 -> V_48 . V_15 [ V_32 + 1 ] =
V_14 -> V_48 . V_16 [ V_32 + 1 ] =
F_23 ( V_54 + 1 ) & V_57 ;
( ( unsigned char * ) V_53 ) [ 15 ] += 1 ;
}
( ( unsigned char * ) V_53 ) [ 0 ] = 0xE0 ;
V_53 [ 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < sizeof( V_14 -> V_48 . V_42 ) / 8 ; V_32 += 2 ) {
do {
F_22 ( V_14 -> V_51 ,
( unsigned char * ) V_54 , ( unsigned char * ) V_53 ) ;
V_14 -> V_48 . V_42 [ V_32 ] = F_23 ( V_54 ) ;
V_14 -> V_48 . V_42 [ V_32 + 1 ] = F_23 ( V_54 + 1 ) ;
( ( unsigned char * ) V_53 ) [ 15 ] += 1 ;
} while ( V_14 -> V_48 . V_42 [ V_32 ] >= V_26
|| V_14 -> V_48 . V_42 [ V_32 + 1 ] >= V_26 );
}
V_14 -> V_48 . V_49 [ 0 ] = ( T_1 ) - 1 ;
V_14 -> V_48 . V_49 [ 1 ] = ( T_1 ) 0 ;
V_14 -> V_48 . V_17 = 0 ;
return V_55 ;
}
static int F_27 ( struct V_58 * V_59 ,
const T_3 * V_60 , unsigned int V_61 )
{
struct V_44 * V_14 = F_28 ( V_59 ) ;
if ( V_61 != V_56 ) {
F_29 ( V_59 , V_62 ) ;
return - V_63 ;
}
return F_25 ( ( T_3 * ) V_60 , V_14 ) ;
}
static int F_30 ( struct V_64 * V_65 )
{
return 0 ;
}
static int F_31 ( struct V_64 * V_65 , const T_3 * V_7 ,
unsigned int V_20 )
{
struct V_58 * V_59 = V_65 -> V_66 ;
struct V_44 * V_14 = F_28 ( V_59 ) ;
int V_67 ;
int V_68 ;
V_67 = V_37 - V_14 -> V_69 > 0 ?
V_37 - V_14 -> V_69 : 0 ;
V_68 = V_20 < V_67 ? V_20 : V_67 ;
memcpy ( V_14 -> V_70 + V_14 -> V_69 , V_7 , V_68 ) ;
V_14 -> V_69 += V_68 ;
if ( V_20 < V_67 )
return 0 ;
F_15 ( V_14 -> V_70 , V_37 , & V_14 -> V_48 ) ;
V_14 -> V_69 = 0 ;
V_20 -= V_67 ;
V_7 += V_67 ;
if ( V_20 % V_37 ) {
memcpy ( V_14 -> V_70 , V_7 + V_20 - ( V_20 % V_37 ) ,
V_20 % V_37 ) ;
V_14 -> V_69 = V_20 % V_37 ;
}
F_15 ( V_7 , V_20 - V_20 % V_37 , & V_14 -> V_48 ) ;
return 0 ;
}
static int F_32 ( struct V_64 * V_65 , T_3 * V_54 )
{
struct V_58 * V_59 = V_65 -> V_66 ;
struct V_44 * V_14 = F_28 ( V_59 ) ;
T_4 V_71 ;
T_3 V_72 [ 16 ] = {} ;
if ( V_14 -> V_69 ) {
memset ( V_14 -> V_70 + V_14 -> V_69 , 0 ,
V_37 - V_14 -> V_69 ) ;
}
V_71 = F_21 ( V_14 -> V_70 , V_14 -> V_69 , V_72 , NULL , V_14 ) ;
memcpy ( V_54 , & V_71 , sizeof( T_4 ) ) ;
memset ( & V_71 , 0 , sizeof( T_4 ) ) ;
memset ( & V_14 -> V_48 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_69 = 0 ;
return 0 ;
}
static int F_33 ( struct V_73 * V_66 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 = ( void * ) V_66 -> V_78 ;
struct V_79 * V_80 = F_34 ( V_77 ) ;
struct V_44 * V_14 = F_35 ( V_66 ) ;
V_75 = F_36 ( V_80 ) ;
if ( F_37 ( V_75 ) )
return F_38 ( V_75 ) ;
V_14 -> V_51 = V_75 ;
return 0 ;
}
static void F_39 ( struct V_73 * V_66 )
{
struct V_44 * V_14 = F_35 ( V_66 ) ;
F_40 ( V_14 -> V_51 ) ;
}
static int F_41 ( struct V_81 * V_82 , struct V_83 * * V_84 )
{
struct V_85 * V_77 ;
struct V_86 * V_87 ;
int V_55 ;
V_55 = F_42 ( V_84 , V_88 ) ;
if ( V_55 )
return V_55 ;
V_87 = F_43 ( V_84 , V_89 ,
V_90 ) ;
if ( F_37 ( V_87 ) )
return F_38 ( V_87 ) ;
V_77 = F_44 ( L_1 , V_87 ) ;
V_55 = F_38 ( V_77 ) ;
if ( F_37 ( V_77 ) )
goto V_91;
V_55 = F_45 ( F_46 ( V_77 ) , V_87 ,
F_47 ( V_77 ) ,
V_90 ) ;
if ( V_55 )
goto V_92;
V_77 -> V_87 . V_93 . V_94 = V_87 -> V_94 ;
V_77 -> V_87 . V_93 . V_95 = V_87 -> V_95 ;
V_77 -> V_87 . V_93 . V_96 = V_87 -> V_96 ;
V_77 -> V_87 . V_97 = sizeof( T_4 ) ;
V_77 -> V_87 . V_93 . V_98 = sizeof( struct V_44 ) ;
V_77 -> V_87 . V_93 . V_99 = F_33 ;
V_77 -> V_87 . V_93 . V_100 = F_39 ;
V_77 -> V_87 . V_101 = F_30 ;
V_77 -> V_87 . V_102 = F_31 ;
V_77 -> V_87 . V_103 = F_32 ;
V_77 -> V_87 . V_104 = F_27 ;
V_55 = F_48 ( V_82 , V_77 ) ;
if ( V_55 ) {
V_92:
F_49 ( F_47 ( V_77 ) ) ;
}
V_91:
F_50 ( V_87 ) ;
return V_55 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_105 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_105 ) ;
}
