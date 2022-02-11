int
F_1 ( unsigned long V_1 , T_1 * V_2 )
{
const unsigned short int V_3 [ 2 ] [ 13 ] =
{
{ 0 , 31 , 59 , 90 , 120 , 151 , 181 , 212 , 243 , 273 , 304 , 334 , 365 } ,
{ 0 , 31 , 60 , 91 , 121 , 152 , 182 , 213 , 244 , 274 , 305 , 335 , 366 }
} ;
long int V_4 , V_5 , V_6 ;
const unsigned short int * V_7 ;
V_4 = V_1 / V_8 ;
V_5 = V_1 % V_8 ;
while ( V_5 < 0 ) {
V_5 += V_8 ;
-- V_4 ;
}
while ( V_5 >= V_8 ) {
V_5 -= V_8 ;
++ V_4 ;
}
V_2 -> V_9 = V_5 / V_10 ;
V_5 %= V_10 ;
V_2 -> V_11 = V_5 / 60 ;
V_2 -> V_12 = V_5 % 60 ;
V_6 = 1970 ;
# define DIV ( T_2 , T_3 ) ((a) / (b) - ((a) % (b) < 0))
# define F_2 ( V_6 ) (DIV (y, 4) - DIV (y, 100) + DIV (y, 400))
# define F_3 ( T_4 ) \
((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
while ( V_4 < 0 || V_4 >= ( F_3 ( V_6 ) ? 366 : 365 ) ) {
long int V_13 = V_6 + V_4 / 365 - ( V_4 % 365 < 0 ) ;
V_4 -= ( ( V_13 - V_6 ) * 365 + F_2 ( V_13 - 1 )
- F_2 ( V_6 - 1 ) ) ;
V_6 = V_13 ;
}
V_2 -> T_4 = V_6 ;
V_7 = V_3 [ F_3 ( V_6 ) ] ;
for ( V_6 = 11 ; V_4 < ( long int ) V_7 [ V_6 ] ; -- V_6 )
continue;
V_4 -= V_7 [ V_6 ] ;
V_2 -> V_14 = V_6 + 1 ;
V_2 -> V_15 = V_4 + 1 ;
return 1 ;
}
static T_5
F_4 ( T_1 * V_16 , T_6 * V_17 )
{
#if F_5 ( V_18 ) || F_5 ( V_19 )
struct {
int V_20 ;
int V_21 ;
} V_22 ;
F_6 ( ( unsigned long ) & V_22 , 0 , 0 , 0 , V_23 ) ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
F_1 ( V_22 . V_20 , V_16 ) ;
if ( V_17 )
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
#else
# error Not implemented yet...
#endif
return V_24 ;
}
static void
F_7 ( int V_25 , T_5 V_26 , unsigned long V_27 , T_7 * V_28 )
{
#if F_5 ( V_18 ) || F_5 ( V_19 )
F_6 ( V_26 , 0 , 0 , 0 , V_29 ) ;
#else
# error Not implemented yet...
#endif
}
static T_5
F_8 ( void )
{
return V_30 ;
}
static struct V_31
F_9 ( long V_32 , unsigned long V_33 , unsigned long V_34 ,
unsigned long V_35 , unsigned long V_36 , unsigned long V_37 ,
unsigned long V_38 , unsigned long V_39 )
{
long V_40 = 0 ;
long V_41 = 0 ;
long V_42 = 0 ;
long V_26 ;
V_26 = 0 ;
if ( V_32 == V_43 ) {
switch ( V_33 ) {
case V_44 :
V_40 = 200000000 ;
break;
case V_45 :
V_40 = 700000000 ;
break;
case V_46 :
V_40 = 1 ;
break;
default:
V_26 = - 1 ;
break;
}
} else if ( V_32 == V_47 ) {
;
} else if ( V_32 == V_48 ) {
;
} else if ( V_32 == V_49 ) {
;
} else if ( V_32 == V_50 ) {
;
} else if ( V_32 == V_51 ) {
;
} else if ( V_32 == V_52 ) {
;
} else if ( V_32 == V_53 ) {
;
} else if ( V_32 == V_54 ) {
;
#ifdef F_10
} else if ( V_32 == V_55 ) {
F_11 ( F_12 ( V_33 ) , 0xCF8 ) ;
if ( V_34 == 1 )
V_40 = F_13 ( 0xCFC + ( ( F_14 ( V_33 ) & 3 ) ) ) ;
else if ( V_34 == 2 )
V_40 = F_15 ( 0xCFC + ( ( F_14 ( V_33 ) & 2 ) ) ) ;
else
V_40 = F_16 ( 0xCFC ) ;
V_26 = V_56 ;
} else if ( V_32 == V_57 ) {
F_11 ( F_12 ( V_33 ) , 0xCF8 ) ;
if ( V_34 == 1 )
F_17 ( V_35 , 0xCFC + ( ( F_14 ( V_33 ) & 3 ) ) ) ;
else if ( V_34 == 2 )
F_18 ( V_35 , 0xCFC + ( ( F_14 ( V_33 ) & 2 ) ) ) ;
else
F_11 ( V_35 , 0xCFC ) ;
V_26 = V_56 ;
#endif
} else if ( V_32 == V_58 ) {
;
} else {
V_26 = - 1 ;
}
return ( (struct V_31 ) { V_26 , V_40 , V_41 , V_42 } ) ;
}
struct V_59 *
F_19 ( const char * args , int V_60 )
{
T_8 * V_61 ;
T_9 * V_62 ;
T_10 * V_63 ;
struct V_64 * V_65 ;
T_11 * V_66 , * V_67 ;
unsigned long * V_68 , * V_69 ;
struct V_70 * V_71 ;
struct V_59 * V_72 ;
unsigned char V_73 = 0 ;
char * V_74 , * V_75 ;
int V_76 = 0 ;
# define F_20 ( T_12 , T_13 , T_14 , T_15 ) \
do { \
md = efi_memmap + i++; \
md->type = typ; \
md->pad = 0; \
md->phys_addr = start; \
md->virt_addr = 0; \
md->num_pages = (end - start) >> 12; \
md->attribute = attr; \
} while (0)
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_68 = ( unsigned long * ) & V_78 ;
V_69 = ( unsigned long * ) & F_9 ;
V_74 = V_77 ;
V_61 = ( void * ) V_74 ; V_74 += sizeof( * V_61 ) ;
V_62 = ( void * ) V_74 ; V_74 += sizeof( * V_62 ) ;
V_63 = ( void * ) V_74 ; V_74 += sizeof( * V_63 ) ;
V_65 = ( void * ) V_74 ; V_74 += sizeof( * V_65 ) ;
V_71 = ( void * ) V_74 ; V_74 += sizeof( * V_71 ) ;
V_66 = ( void * ) V_74 ; V_74 += V_79 * sizeof( * V_66 ) ;
V_72 = ( void * ) V_74 ; V_74 += sizeof( * V_72 ) ;
V_75 = ( void * ) V_74 ;
if ( args ) {
if ( V_60 >= 1024 )
V_60 = 1023 ;
memcpy ( V_75 , args , V_60 ) ;
} else {
V_60 = 0 ;
}
V_75 [ V_60 ] = '\0' ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_80 . V_81 = V_82 ;
V_61 -> V_80 . V_83 = ( ( 1 << 16 ) | 00 ) ;
V_61 -> V_80 . V_84 = sizeof( V_61 -> V_80 ) ;
V_61 -> V_85 = F_21 ( L_1 ) ;
V_61 -> V_86 = 1 ;
V_61 -> V_87 = ( void * ) F_21 ( V_62 ) ;
V_61 -> V_88 = 1 ;
V_61 -> V_89 = F_21 ( V_63 ) ;
V_62 -> V_80 . V_81 = V_90 ;
V_62 -> V_80 . V_83 = V_91 ;
V_62 -> V_80 . V_84 = sizeof( V_62 -> V_80 ) ;
V_62 -> V_92 = F_21 ( & F_4 ) ;
V_62 -> V_93 = F_21 ( & F_8 ) ;
V_62 -> V_94 = F_21 ( & F_8 ) ;
V_62 -> V_95 = F_21 ( & F_8 ) ;
V_62 -> V_96 = F_21 ( & F_8 ) ;
V_62 -> V_97 = F_21 ( & F_8 ) ;
V_62 -> V_98 = F_21 ( & F_8 ) ;
V_62 -> V_99 = F_21 ( & F_8 ) ;
V_62 -> V_100 = F_21 ( & F_8 ) ;
V_62 -> V_101 = F_21 ( & F_7 ) ;
V_63 -> V_102 = V_103 ;
V_63 -> V_104 = F_21 ( V_65 ) ;
memcpy ( V_65 -> V_81 , L_2 , 4 ) ;
V_65 -> V_105 = sizeof( * V_65 ) ;
V_65 -> V_106 = 1 ;
V_65 -> V_107 = 0 ;
V_65 -> V_108 = 1 ;
#ifdef V_19
strcpy ( V_65 -> V_109 , L_3 ) ;
strcpy ( V_65 -> V_110 , L_4 ) ;
#endif
#ifdef V_18
strcpy ( V_65 -> V_109 , L_5 ) ;
strcpy ( V_65 -> V_110 , L_6 ) ;
#endif
V_71 -> type = V_111 ;
V_71 -> V_112 = F_21 ( V_68 [ 0 ] ) ;
V_71 -> V_113 = F_21 ( V_69 [ 0 ] ) ;
V_71 -> V_114 = F_21 ( V_69 [ 1 ] ) ;
for ( V_74 = ( char * ) V_65 ; V_74 < ( char * ) V_66 ; ++ V_74 )
V_73 += * V_74 ;
V_65 -> V_73 = - V_73 ;
#if V_115
F_20 ( V_116 , V_117 , 0 * V_118 , 1 * V_118 ) ;
F_20 ( V_119 , V_117 , 1 * V_118 , 2 * V_118 ) ;
F_20 ( V_120 , V_117 , 2 * V_118 , 130 * V_118 ) ;
F_20 ( V_120 , V_117 , 4096 * V_118 , 4128 * V_118 ) ;
#else
F_20 ( 4 , 0x9 , 0x0000000000000000 , 0x0000000000001000 ) ;
F_20 ( 7 , 0x9 , 0x0000000000001000 , 0x000000000008a000 ) ;
F_20 ( 4 , 0x9 , 0x000000000008a000 , 0x00000000000a0000 ) ;
F_20 ( 5 , 0x8000000000000009 , 0x00000000000c0000 , 0x0000000000100000 ) ;
F_20 ( 7 , 0x9 , 0x0000000000100000 , 0x0000000004400000 ) ;
F_20 ( 2 , 0x9 , 0x0000000004400000 , 0x0000000004be5000 ) ;
F_20 ( 7 , 0x9 , 0x0000000004be5000 , 0x000000007f77e000 ) ;
F_20 ( 6 , 0x8000000000000009 , 0x000000007f77e000 , 0x000000007fb94000 ) ;
F_20 ( 6 , 0x8000000000000009 , 0x000000007fb94000 , 0x000000007fb95000 ) ;
F_20 ( 6 , 0x8000000000000009 , 0x000000007fb95000 , 0x000000007fc00000 ) ;
F_20 ( 13 , 0x8000000000000009 , 0x000000007fc00000 , 0x000000007fc3a000 ) ;
F_20 ( 7 , 0x9 , 0x000000007fc3a000 , 0x000000007fea0000 ) ;
F_20 ( 5 , 0x8000000000000009 , 0x000000007fea0000 , 0x000000007fea8000 ) ;
F_20 ( 7 , 0x9 , 0x000000007fea8000 , 0x000000007feab000 ) ;
F_20 ( 5 , 0x8000000000000009 , 0x000000007feab000 , 0x000000007ffff000 ) ;
F_20 ( 7 , 0x9 , 0x00000000ff400000 , 0x0000000104000000 ) ;
#endif
V_72 -> V_61 = F_21 ( & V_77 ) ;
V_72 -> V_66 = F_21 ( V_66 ) ;
V_72 -> V_121 = V_79 * sizeof( T_11 ) ;
V_72 -> V_122 = sizeof( T_11 ) ;
V_72 -> V_123 = 1 ;
V_72 -> V_124 = F_21 ( V_75 ) ;
V_72 -> V_125 . V_126 = 80 ;
V_72 -> V_125 . V_127 = 25 ;
V_72 -> V_125 . V_128 = 0 ;
V_72 -> V_125 . V_129 = 24 ;
V_72 -> V_130 = 0 ;
return V_72 ;
}
