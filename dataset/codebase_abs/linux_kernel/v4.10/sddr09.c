static inline char * F_1 ( int V_1 ) {
switch( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
default:
return L_5 ;
}
}
static struct V_6 *
F_2 ( unsigned char V_7 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] . V_10 == V_7 )
return & ( V_9 [ V_8 ] ) ;
return NULL ;
}
static void F_4 ( void ) {
int V_8 , V_11 , V_12 ;
V_13 [ 0 ] = 0 ;
for ( V_8 = 1 ; V_8 < 256 ; V_8 ++ )
V_13 [ V_8 ] = ( V_13 [ V_8 & ( V_8 - 1 ) ] ^ 1 ) ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ ) {
V_12 = 0 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( V_8 & ( 1 << V_11 ) ) {
if ( ( V_11 & 1 ) == 0 )
V_12 ^= 0x04 ;
if ( ( V_11 & 2 ) == 0 )
V_12 ^= 0x10 ;
if ( ( V_11 & 4 ) == 0 )
V_12 ^= 0x40 ;
}
}
V_14 [ V_8 ] = ~ ( V_12 ^ ( V_12 << 1 ) ^ ( V_13 [ V_8 ] ? 0xa8 : 0 ) ) ;
}
}
static void F_5 ( unsigned char * V_15 , unsigned char * V_16 ) {
int V_8 , V_11 , V_12 ;
unsigned char V_17 = 0 , V_18 , V_19 [ 8 ] = { 0 } ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ ) {
V_17 ^= V_15 [ V_8 ] ;
V_18 = V_13 [ V_15 [ V_8 ] ] ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
if ( ( V_8 & ( 1 << V_11 ) ) == 0 )
V_19 [ V_11 ] ^= V_18 ;
}
V_12 = ( V_19 [ 3 ] << 6 ) + ( V_19 [ 2 ] << 4 ) + ( V_19 [ 1 ] << 2 ) + V_19 [ 0 ] ;
V_16 [ 0 ] = ~ ( V_12 ^ ( V_12 << 1 ) ^ ( V_13 [ V_17 ] ? 0xaa : 0 ) ) ;
V_12 = ( V_19 [ 7 ] << 6 ) + ( V_19 [ 6 ] << 4 ) + ( V_19 [ 5 ] << 2 ) + V_19 [ 4 ] ;
V_16 [ 1 ] = ~ ( V_12 ^ ( V_12 << 1 ) ^ ( V_13 [ V_17 ] ? 0xaa : 0 ) ) ;
V_16 [ 2 ] = V_14 [ V_17 ] ;
}
static int F_6 ( unsigned char * V_15 , unsigned char * V_16 ) {
return ( V_15 [ 0 ] == V_16 [ 0 ] && V_15 [ 1 ] == V_16 [ 1 ] && V_15 [ 2 ] == V_16 [ 2 ] ) ;
}
static void F_7 ( unsigned char * V_15 , unsigned char * V_16 ) {
memcpy ( V_15 , V_16 , 3 ) ;
}
static int
F_8 ( struct V_20 * V_21 ,
unsigned char V_22 ,
unsigned char V_23 ,
unsigned char * V_24 ,
unsigned int V_25 ) {
unsigned int V_26 ;
unsigned char V_27 = ( 0x41 | V_23 ) ;
int V_28 ;
if ( V_23 == V_29 )
V_26 = V_21 -> V_30 ;
else
V_26 = V_21 -> V_31 ;
V_28 = F_9 ( V_21 , V_26 , V_22 , V_27 ,
0 , 0 , V_24 , V_25 ) ;
switch ( V_28 ) {
case V_32 : return 0 ;
case V_33 : return - V_34 ;
default: return - V_35 ;
}
}
static int
F_10 ( struct V_20 * V_21 ,
unsigned char * V_36 ,
unsigned int V_37 ) {
return F_8 ( V_21 , 0 , V_38 , V_36 , V_37 ) ;
}
static int
F_11 ( struct V_20 * V_21 , unsigned char * V_39 , int V_40 ) {
unsigned char * V_36 = V_21 -> V_41 ;
int V_42 ;
memset ( V_36 , 0 , 12 ) ;
V_36 [ 0 ] = 0x03 ;
V_36 [ 1 ] = V_43 ;
V_36 [ 4 ] = V_40 ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_12 ( V_21 , V_21 -> V_44 ,
V_39 , V_40 , NULL ) ;
return ( V_42 == V_32 ? 0 : - V_35 ) ;
}
static int
F_13 ( struct V_20 * V_21 , int V_45 , unsigned long V_46 ,
int V_47 , int V_48 , unsigned char * V_49 ,
int V_50 ) {
unsigned char * V_36 = V_21 -> V_41 ;
int V_42 ;
V_36 [ 0 ] = 0xE8 ;
V_36 [ 1 ] = V_43 | V_45 ;
V_36 [ 2 ] = F_14 ( V_46 >> 16 ) ;
V_36 [ 3 ] = F_15 ( V_46 >> 16 ) ;
V_36 [ 4 ] = F_14 ( V_46 & 0xFFFF ) ;
V_36 [ 5 ] = F_15 ( V_46 & 0xFFFF ) ;
V_36 [ 6 ] = 0 ;
V_36 [ 7 ] = 0 ;
V_36 [ 8 ] = 0 ;
V_36 [ 9 ] = 0 ;
V_36 [ 10 ] = F_14 ( V_47 ) ;
V_36 [ 11 ] = F_15 ( V_47 ) ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_6 ,
V_45 , V_42 ) ;
return V_42 ;
}
V_42 = F_17 ( V_21 , V_21 -> V_44 ,
V_49 , V_48 , V_50 , NULL ) ;
if ( V_42 != V_32 ) {
F_16 ( V_21 , L_7 ,
V_45 , V_42 ) ;
return - V_35 ;
}
return 0 ;
}
static int
F_18 ( struct V_20 * V_21 , unsigned long V_46 ,
int V_47 , int V_51 , unsigned char * V_49 , int V_50 ) {
int V_48 = V_47 << V_51 ;
return F_13 ( V_21 , 0 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int
F_19 ( struct V_20 * V_21 , unsigned long V_46 ,
int V_52 , int V_53 , unsigned char * V_49 , int V_50 ) {
int V_48 = ( V_52 << V_53 ) ;
return F_13 ( V_21 , 1 , V_46 , V_52 , V_48 ,
V_49 , V_50 ) ;
}
static int
F_20 ( struct V_20 * V_21 , unsigned long V_46 ,
int V_47 , int V_51 , unsigned char * V_49 , int V_50 ) {
int V_48 = ( V_47 << V_51 ) + ( V_47 << V_54 ) ;
F_16 ( V_21 , L_8 , V_47 , V_48 ) ;
return F_13 ( V_21 , 2 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int
F_21 ( struct V_20 * V_21 , unsigned long V_55 ) {
unsigned char * V_36 = V_21 -> V_41 ;
int V_42 ;
F_16 ( V_21 , L_9 , V_55 ) ;
memset ( V_36 , 0 , 12 ) ;
V_36 [ 0 ] = 0xEA ;
V_36 [ 1 ] = V_43 ;
V_36 [ 6 ] = F_14 ( V_55 >> 16 ) ;
V_36 [ 7 ] = F_15 ( V_55 >> 16 ) ;
V_36 [ 8 ] = F_14 ( V_55 & 0xFFFF ) ;
V_36 [ 9 ] = F_15 ( V_55 & 0xFFFF ) ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 )
F_16 ( V_21 , L_10 ,
V_42 ) ;
return V_42 ;
}
static int
F_22 ( struct V_20 * V_21 ,
unsigned long V_56 , unsigned long V_55 ,
int V_47 , int V_48 , unsigned char * V_49 , int V_50 ) {
unsigned char * V_36 = V_21 -> V_41 ;
int V_42 ;
V_36 [ 0 ] = 0xE9 ;
V_36 [ 1 ] = V_43 ;
V_36 [ 2 ] = F_14 ( V_56 >> 16 ) ;
V_36 [ 3 ] = F_15 ( V_56 >> 16 ) ;
V_36 [ 4 ] = F_14 ( V_56 & 0xFFFF ) ;
V_36 [ 5 ] = F_15 ( V_56 & 0xFFFF ) ;
V_36 [ 6 ] = F_14 ( V_55 >> 16 ) ;
V_36 [ 7 ] = F_15 ( V_55 >> 16 ) ;
V_36 [ 8 ] = F_14 ( V_55 & 0xFFFF ) ;
V_36 [ 9 ] = F_15 ( V_55 & 0xFFFF ) ;
V_36 [ 10 ] = F_14 ( V_47 ) ;
V_36 [ 11 ] = F_15 ( V_47 ) ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_11 ,
V_42 ) ;
return V_42 ;
}
V_42 = F_17 ( V_21 , V_21 -> V_57 ,
V_49 , V_48 , V_50 , NULL ) ;
if ( V_42 != V_32 ) {
F_16 ( V_21 , L_12 ,
V_42 ) ;
return - V_35 ;
}
return 0 ;
}
static int
F_23 ( struct V_20 * V_21 , unsigned long V_58 ,
int V_47 , int V_51 , unsigned char * V_49 ,
int V_50 ) {
int V_48 = ( V_47 << V_51 ) + ( V_47 << V_54 ) ;
return F_22 ( V_21 , V_58 , V_58 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int
F_24 ( struct V_20 * V_21 , unsigned char * V_59 ) {
unsigned char * V_36 = V_21 -> V_41 ;
unsigned char * V_15 = V_21 -> V_41 ;
int V_42 ;
F_16 ( V_21 , L_13 ) ;
memset ( V_36 , 0 , 12 ) ;
V_36 [ 0 ] = 0xEC ;
V_36 [ 1 ] = V_43 ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_12 ( V_21 , V_21 -> V_44 ,
V_15 , 64 , NULL ) ;
* V_59 = V_15 [ 0 ] ;
return ( V_42 == V_32 ? 0 : - V_35 ) ;
}
static int
F_25 ( struct V_20 * V_21 ,
unsigned long V_58 ,
unsigned int V_60 ) {
struct V_61 * V_62 = (struct V_61 * ) V_21 -> V_63 ;
unsigned char * V_64 ;
unsigned int V_65 , V_66 , V_67 ;
unsigned int V_68 , V_69 ;
unsigned int V_70 , V_71 ;
struct V_72 * V_73 ;
int V_42 ;
V_65 = V_58 >> V_62 -> V_74 ;
V_68 = ( V_58 & V_62 -> V_75 ) ;
V_66 = V_62 -> V_76 >> ( V_62 -> V_51 + V_62 -> V_74 ) ;
if ( V_65 >= V_66 )
return - V_35 ;
V_70 = F_26 ( V_60 , ( unsigned int ) V_62 -> V_77 ) * V_62 -> V_78 ;
V_64 = F_27 ( V_70 , V_79 ) ;
if ( ! V_64 )
return - V_80 ;
V_42 = 0 ;
V_71 = 0 ;
V_73 = NULL ;
while ( V_60 > 0 ) {
V_69 = F_26 ( V_60 , V_62 -> V_77 - V_68 ) ;
V_70 = V_69 << V_62 -> V_51 ;
if ( V_65 >= V_66 ) {
F_16 ( V_21 , L_14 ,
V_65 , V_66 ) ;
V_42 = - V_35 ;
break;
}
V_67 = V_62 -> V_81 [ V_65 ] ;
if ( V_67 == UNDEF ) {
F_16 ( V_21 , L_15 ,
V_69 , V_65 , V_68 ) ;
memset ( V_64 , 0 , V_70 ) ;
} else {
F_16 ( V_21 , L_16 ,
V_69 , V_67 , V_65 , V_68 ) ;
V_58 = ( ( V_67 << V_62 -> V_74 ) + V_68 ) <<
V_62 -> V_51 ;
V_42 = F_18 ( V_21 , V_58 >> 1 ,
V_69 , V_62 -> V_51 , V_64 , 0 ) ;
if ( V_42 )
break;
}
F_28 ( V_64 , V_70 , V_21 -> V_82 ,
& V_73 , & V_71 , V_83 ) ;
V_68 = 0 ;
V_65 ++ ;
V_60 -= V_69 ;
}
F_29 ( V_64 ) ;
return V_42 ;
}
static unsigned int
F_30 ( struct V_61 * V_62 , unsigned int V_65 ) {
static unsigned int V_84 = 1 ;
int V_85 , V_86 , V_8 ;
V_85 = ( V_65 / 1000 ) << 10 ;
V_86 = V_62 -> V_76 >> ( V_62 -> V_74 + V_62 -> V_51 ) ;
V_86 -= V_85 ;
if ( V_86 > 1024 )
V_86 = 1024 ;
for ( V_8 = V_84 + 1 ; V_8 < V_86 ; V_8 ++ ) {
if ( V_62 -> V_87 [ V_85 + V_8 ] == UNDEF ) {
V_84 = V_8 ;
return V_85 + V_8 ;
}
}
for ( V_8 = 0 ; V_8 <= V_84 ; V_8 ++ ) {
if ( V_62 -> V_87 [ V_85 + V_8 ] == UNDEF ) {
V_84 = V_8 ;
return V_85 + V_8 ;
}
}
return 0 ;
}
static int
F_31 ( struct V_20 * V_21 , unsigned int V_65 ,
unsigned int V_68 , unsigned int V_69 ,
unsigned char * V_88 , unsigned char * V_89 ) {
struct V_61 * V_62 = (struct V_61 * ) V_21 -> V_63 ;
unsigned long V_58 ;
unsigned int V_67 , V_90 ;
unsigned int V_91 ;
unsigned char * V_92 , * V_93 , * V_94 ;
unsigned char V_16 [ 3 ] ;
int V_8 , V_42 , V_95 ;
V_90 = ( ( V_65 % 1000 ) << 1 ) | 0x1000 ;
if ( V_13 [ F_14 ( V_90 ) ^ F_15 ( V_90 ) ] )
V_90 ^= 1 ;
V_67 = V_62 -> V_81 [ V_65 ] ;
V_95 = 0 ;
if ( V_67 == UNDEF ) {
V_67 = F_30 ( V_62 , V_65 ) ;
if ( ! V_67 ) {
F_32 ( V_96
L_17 ) ;
return - V_97 ;
}
V_62 -> V_87 [ V_67 ] = V_65 ;
V_62 -> V_81 [ V_65 ] = V_67 ;
V_95 = 1 ;
}
if ( V_67 == 1 ) {
F_32 ( V_96 L_18 ) ;
return 0 ;
}
V_91 = ( 1 << V_62 -> V_51 ) + ( 1 << V_54 ) ;
V_58 = ( V_67 << ( V_62 -> V_51 + V_62 -> V_74 ) ) ;
V_42 = F_20 ( V_21 , V_58 >> 1 , V_62 -> V_77 ,
V_62 -> V_51 , V_89 , 0 ) ;
if ( V_42 )
return V_42 ;
for ( V_8 = 0 ; V_8 < V_62 -> V_77 ; V_8 ++ ) {
V_92 = V_89 + V_8 * V_91 ;
V_93 = V_92 + V_62 -> V_78 ;
F_5 ( V_92 , V_16 ) ;
if ( ! F_6 ( V_93 + 13 , V_16 ) ) {
F_16 ( V_21 , L_19 ,
V_8 , V_67 ) ;
F_7 ( V_93 + 13 , V_16 ) ;
}
F_5 ( V_92 + ( V_62 -> V_78 / 2 ) , V_16 ) ;
if ( ! F_6 ( V_93 + 8 , V_16 ) ) {
F_16 ( V_21 , L_20 ,
V_8 , V_67 ) ;
F_7 ( V_93 + 8 , V_16 ) ;
}
V_93 [ 6 ] = V_93 [ 11 ] = F_14 ( V_90 ) ;
V_93 [ 7 ] = V_93 [ 12 ] = F_15 ( V_90 ) ;
}
V_94 = V_88 ;
for ( V_8 = V_68 ; V_8 < V_68 + V_69 ; V_8 ++ ) {
V_92 = V_89 + V_8 * V_91 ;
V_93 = V_92 + V_62 -> V_78 ;
memcpy ( V_92 , V_94 , V_62 -> V_78 ) ;
V_94 += V_62 -> V_78 ;
F_5 ( V_92 , V_16 ) ;
F_7 ( V_93 + 13 , V_16 ) ;
F_5 ( V_92 + ( V_62 -> V_78 / 2 ) , V_16 ) ;
F_7 ( V_93 + 8 , V_16 ) ;
}
F_16 ( V_21 , L_21 , V_67 , V_65 ) ;
V_42 = F_23 ( V_21 , V_58 >> 1 , V_62 -> V_77 ,
V_62 -> V_51 , V_89 , 0 ) ;
F_16 ( V_21 , L_22 , V_42 ) ;
#if 0
{
unsigned char status = 0;
int result2 = sddr09_read_status(us, &status);
if (result2)
usb_stor_dbg(us, "cannot read status\n");
else if (status != 0xc0)
usb_stor_dbg(us, "status after write: 0x%x\n", status);
}
#endif
#if 0
{
int result2 = sddr09_test_unit_ready(us);
}
#endif
return V_42 ;
}
static int
F_33 ( struct V_20 * V_21 ,
unsigned long V_58 ,
unsigned int V_60 ) {
struct V_61 * V_62 = (struct V_61 * ) V_21 -> V_63 ;
unsigned int V_65 , V_66 , V_68 , V_69 ;
unsigned int V_91 , V_98 ;
unsigned char * V_89 ;
unsigned char * V_64 ;
unsigned int V_70 , V_71 ;
struct V_72 * V_73 ;
int V_42 ;
V_65 = V_58 >> V_62 -> V_74 ;
V_68 = ( V_58 & V_62 -> V_75 ) ;
V_66 = V_62 -> V_76 >> ( V_62 -> V_51 + V_62 -> V_74 ) ;
if ( V_65 >= V_66 )
return - V_35 ;
V_91 = ( 1 << V_62 -> V_51 ) + ( 1 << V_54 ) ;
V_98 = ( V_91 << V_62 -> V_74 ) ;
V_89 = F_27 ( V_98 , V_79 ) ;
if ( ! V_89 )
return - V_80 ;
V_70 = F_26 ( V_60 , ( unsigned int ) V_62 -> V_77 ) * V_62 -> V_78 ;
V_64 = F_27 ( V_70 , V_79 ) ;
if ( ! V_64 ) {
F_29 ( V_89 ) ;
return - V_80 ;
}
V_42 = 0 ;
V_71 = 0 ;
V_73 = NULL ;
while ( V_60 > 0 ) {
V_69 = F_26 ( V_60 , V_62 -> V_77 - V_68 ) ;
V_70 = ( V_69 << V_62 -> V_51 ) ;
if ( V_65 >= V_66 ) {
F_16 ( V_21 , L_14 ,
V_65 , V_66 ) ;
V_42 = - V_35 ;
break;
}
F_28 ( V_64 , V_70 , V_21 -> V_82 ,
& V_73 , & V_71 , V_99 ) ;
V_42 = F_31 ( V_21 , V_65 , V_68 , V_69 ,
V_64 , V_89 ) ;
if ( V_42 )
break;
V_68 = 0 ;
V_65 ++ ;
V_60 -= V_69 ;
}
F_29 ( V_64 ) ;
F_29 ( V_89 ) ;
return V_42 ;
}
static int
F_34 ( struct V_20 * V_21 ,
unsigned long V_58 ,
unsigned int V_100 ,
unsigned char * V_101 ,
int V_50 ) {
F_16 ( V_21 , L_23 ,
V_58 , V_100 ) ;
return F_19 ( V_21 , V_58 , V_100 ,
V_54 , V_101 , V_50 ) ;
}
static int
F_35 ( struct V_20 * V_21 , unsigned char * V_102 ) {
unsigned char * V_36 = V_21 -> V_41 ;
unsigned char * V_101 = V_21 -> V_41 ;
int V_42 , V_8 ;
memset ( V_36 , 0 , 12 ) ;
V_36 [ 0 ] = 0xED ;
V_36 [ 1 ] = V_43 ;
V_42 = F_10 ( V_21 , V_36 , 12 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_12 ( V_21 , V_21 -> V_44 ,
V_101 , 64 , NULL ) ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
V_102 [ V_8 ] = V_101 [ V_8 ] ;
return ( V_42 == V_32 ? 0 : - V_35 ) ;
}
static int
F_36 ( struct V_20 * V_21 , struct V_61 * V_62 ) {
int V_42 ;
unsigned char V_59 ;
const char * V_103 ;
V_42 = F_24 ( V_21 , & V_59 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_24 ) ;
return V_42 ;
}
if ( ( V_59 & 0x80 ) == 0 ) {
V_62 -> V_104 |= V_105 ;
V_103 = L_25 ;
} else {
V_103 = L_26 ;
}
F_16 ( V_21 , L_27 , V_59 , V_103 ,
V_59 & 0x40 ? L_28 : L_26 ,
V_59 & V_43 ? L_29 : L_26 ,
V_59 & 0x01 ? L_30 : L_26 ) ;
return 0 ;
}
static struct V_6 *
F_37 ( struct V_20 * V_21 , unsigned char V_104 ) {
struct V_6 * V_106 ;
unsigned char V_102 [ 4 ] ;
char V_107 [ 256 ] ;
int V_42 ;
F_16 ( V_21 , L_31 ) ;
V_42 = F_35 ( V_21 , V_102 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_32 , V_42 ) ;
F_32 ( V_96 L_33 ) ;
return NULL ;
}
sprintf ( V_107 , L_34 , V_102 ) ;
sprintf ( V_107 + strlen ( V_107 ) ,
L_35 ,
F_1 ( V_102 [ 0 ] ) ) ;
V_106 = F_2 ( V_102 [ 1 ] ) ;
if ( V_106 ) {
sprintf ( V_107 + strlen ( V_107 ) ,
L_36 , 1 << ( V_106 -> V_108 - 20 ) ) ;
} else {
sprintf ( V_107 + strlen ( V_107 ) ,
L_37 ) ;
}
if ( V_102 [ 2 ] == 0xa5 ) {
sprintf ( V_107 + strlen ( V_107 ) ,
L_38 ) ;
}
if ( V_102 [ 3 ] == 0xc0 ) {
sprintf ( V_107 + strlen ( V_107 ) ,
L_39 ) ;
}
if ( V_104 & V_105 )
sprintf ( V_107 + strlen ( V_107 ) ,
L_40 ) ;
F_32 ( V_96 L_41 , V_107 ) ;
return V_106 ;
}
static int
F_38 ( struct V_20 * V_21 ) {
struct V_61 * V_62 = (struct V_61 * ) V_21 -> V_63 ;
int V_109 , V_110 , V_111 ;
int V_8 , V_11 , V_42 ;
unsigned char * V_64 , * V_112 , * V_88 ;
unsigned int V_65 , V_113 ;
if ( ! V_62 -> V_76 )
return - 1 ;
V_109 = V_62 -> V_76 >> ( V_62 -> V_74 + V_62 -> V_51 ) ;
#define F_39 65536
V_111 = F_26 ( V_109 , F_39 >> V_54 ) ;
V_110 = ( V_111 << V_54 ) ;
V_64 = F_27 ( V_110 , V_79 ) ;
if ( ! V_64 ) {
V_42 = - 1 ;
goto V_114;
}
V_112 = V_64 + V_110 ;
#undef F_39
F_29 ( V_62 -> V_81 ) ;
F_29 ( V_62 -> V_87 ) ;
V_62 -> V_81 = F_27 ( V_109 * sizeof( int ) , V_79 ) ;
V_62 -> V_87 = F_27 ( V_109 * sizeof( int ) , V_79 ) ;
if ( V_62 -> V_81 == NULL || V_62 -> V_87 == NULL ) {
F_32 ( V_96 L_42 ) ;
V_42 = - 1 ;
goto V_114;
}
for ( V_8 = 0 ; V_8 < V_109 ; V_8 ++ )
V_62 -> V_81 [ V_8 ] = V_62 -> V_87 [ V_8 ] = UNDEF ;
V_88 = V_112 ;
for ( V_8 = 0 ; V_8 < V_109 ; V_8 ++ ) {
V_88 += ( 1 << V_54 ) ;
if ( V_88 >= V_112 ) {
unsigned long V_58 ;
V_58 = V_8 << ( V_62 -> V_51 + V_62 -> V_74 ) ;
V_42 = F_34 (
V_21 , V_58 >> 1 ,
F_26 ( V_111 , V_109 - V_8 ) ,
V_64 , 0 ) ;
if ( V_42 ) {
V_42 = - 1 ;
goto V_114;
}
V_88 = V_64 ;
}
if ( V_8 == 0 || V_8 == 1 ) {
V_62 -> V_87 [ V_8 ] = V_115 ;
continue;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
if ( V_88 [ V_11 ] != 0 )
goto V_116;
V_62 -> V_87 [ V_8 ] = V_115 ;
F_32 ( V_96 L_43 ,
V_8 ) ;
continue;
V_116:
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
if ( V_88 [ V_11 ] != 0xff )
goto V_117;
continue;
V_117:
if ( V_11 < 6 ) {
F_32 ( V_96
L_44
L_45
L_46 ,
V_8 , V_88 [ 0 ] , V_88 [ 1 ] , V_88 [ 2 ] , V_88 [ 3 ] ,
V_88 [ 4 ] , V_88 [ 5 ] ) ;
V_62 -> V_87 [ V_8 ] = V_115 ;
continue;
}
if ( ( V_88 [ 6 ] >> 4 ) != 0x01 ) {
F_32 ( V_96
L_47
L_48 ,
V_8 , V_88 [ 6 ] , V_88 [ 7 ] , V_88 [ 11 ] , V_88 [ 12 ] ) ;
V_62 -> V_87 [ V_8 ] = V_115 ;
continue;
}
if ( V_13 [ V_88 [ 6 ] ^ V_88 [ 7 ] ] ) {
F_32 ( V_96
L_49
L_50 , V_8 , V_88 [ 6 ] , V_88 [ 7 ] ) ;
V_62 -> V_87 [ V_8 ] = V_115 ;
continue;
}
V_65 = F_40 ( V_88 [ 7 ] , V_88 [ 6 ] ) ;
V_65 = ( V_65 & 0x07FF ) >> 1 ;
if ( V_65 >= 1000 ) {
F_32 ( V_96
L_51 ,
V_65 , V_8 ) ;
goto V_118;
}
V_65 += 1000 * ( V_8 / 0x400 ) ;
if ( V_62 -> V_81 [ V_65 ] != UNDEF ) {
F_32 ( V_96
L_52 ,
V_65 , V_62 -> V_81 [ V_65 ] , V_8 ) ;
goto V_118;
}
V_62 -> V_87 [ V_8 ] = V_65 ;
V_62 -> V_81 [ V_65 ] = V_8 ;
continue;
V_118:
if ( V_119 ) {
unsigned long V_58 ;
V_58 = ( V_8 << ( V_62 -> V_51 + V_62 -> V_74 ) ) ;
F_21 ( V_21 , V_58 >> 1 ) ;
V_62 -> V_87 [ V_8 ] = UNDEF ;
} else
V_62 -> V_87 [ V_8 ] = V_115 ;
}
V_113 = 0 ;
for ( V_8 = 0 ; V_8 < V_109 ; V_8 += 1024 ) {
int V_120 = 0 ;
for ( V_11 = 0 ; V_11 < 1024 && V_8 + V_11 < V_109 ; V_11 ++ ) {
if ( V_62 -> V_87 [ V_8 + V_11 ] != V_115 ) {
if ( V_120 >= 1000 )
V_62 -> V_87 [ V_8 + V_11 ] = V_121 ;
else
V_120 ++ ;
}
}
V_113 += V_120 ;
}
V_62 -> V_113 = V_113 ;
F_16 ( V_21 , L_53 , V_113 ) ;
V_42 = 0 ;
V_114:
if ( V_42 != 0 ) {
F_29 ( V_62 -> V_81 ) ;
F_29 ( V_62 -> V_87 ) ;
V_62 -> V_81 = NULL ;
V_62 -> V_87 = NULL ;
}
F_29 ( V_64 ) ;
return V_42 ;
}
static void
F_41 ( void * V_63 ) {
struct V_61 * V_62 = (struct V_61 * ) V_63 ;
if ( ! V_62 )
return;
F_29 ( V_62 -> V_81 ) ;
F_29 ( V_62 -> V_87 ) ;
}
static int
F_42 ( struct V_20 * V_21 ) {
int V_42 ;
if ( V_21 -> V_122 -> V_123 -> V_124 . V_125 != 1 ) {
F_16 ( V_21 , L_54 ,
V_21 -> V_122 -> V_123 -> V_124 . V_125 ) ;
return - V_126 ;
}
V_42 = F_43 ( V_21 -> V_122 ) ;
F_16 ( V_21 , L_55 , V_42 ) ;
if ( V_42 == - V_34 ) {
F_16 ( V_21 , L_56 ) ;
} else if ( V_42 != 0 ) {
F_16 ( V_21 , L_57 ) ;
return - V_126 ;
}
V_21 -> V_63 = F_44 ( sizeof( struct V_61 ) , V_79 ) ;
if ( ! V_21 -> V_63 )
return - V_80 ;
V_21 -> V_127 = F_41 ;
F_4 () ;
return 0 ;
}
static int
F_45 ( struct V_20 * V_21 ) {
int V_42 ;
unsigned char * V_15 = V_21 -> V_41 ;
V_42 = F_42 ( V_21 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_8 ( V_21 , 0x01 , V_29 , V_15 , 2 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_58 ) ;
return V_42 ;
}
F_16 ( V_21 , L_59 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
V_42 = F_8 ( V_21 , 0x08 , V_29 , V_15 , 2 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_60 ) ;
return V_42 ;
}
F_16 ( V_21 , L_59 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
V_42 = F_11 ( V_21 , V_15 , 18 ) ;
if ( V_42 == 0 && V_15 [ 2 ] != 0 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < 18 ; V_11 ++ )
F_32 ( L_61 , V_15 [ V_11 ] ) ;
F_32 ( L_62 ) ;
}
return 0 ;
}
static int F_46 ( struct V_128 * V_82 , struct V_20 * V_21 )
{
int V_129 ;
F_16 ( V_21 , L_63 , ( V_130 ) V_82 -> V_131 -> V_132 ) ;
switch ( V_82 -> V_131 -> V_132 ) {
case 0 :
V_129 = F_47 ( V_82 , V_21 ) ;
break;
case 1 :
V_82 -> V_131 -> V_132 = 0 ;
V_129 = F_48 ( V_82 , V_21 ) ;
V_82 -> V_131 -> V_132 = 1 ;
break;
default:
F_16 ( V_21 , L_64 , ( V_130 ) V_82 -> V_131 -> V_132 ) ;
V_129 = V_133 ;
break;
}
return V_129 ;
}
static int F_48 ( struct V_128 * V_82 , struct V_20 * V_21 )
{
static unsigned char V_134 = 0 , V_135 = 0 ;
static unsigned char V_136 = 0 ;
int V_42 , V_8 ;
unsigned char * V_88 = V_21 -> V_41 ;
unsigned long V_76 ;
unsigned int V_68 , V_69 ;
struct V_61 * V_62 ;
static unsigned char V_137 [ 8 ] = {
0x00 , 0x80 , 0x00 , 0x02 , 0x1F , 0x00 , 0x00 , 0x00
} ;
static unsigned char V_138 [ 19 ] = {
0x00 , 0x0F , 0x00 , 0x0 , 0x0 , 0x0 , 0x00 ,
0x01 , 0x0A ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
V_62 = (struct V_61 * ) V_21 -> V_63 ;
if ( V_82 -> V_139 [ 0 ] == V_140 && V_136 ) {
memset ( V_88 , 0 , 18 ) ;
V_88 [ 0 ] = 0x70 ;
V_88 [ 2 ] = V_134 ;
V_88 [ 7 ] = 11 ;
V_88 [ 12 ] = V_135 ;
F_49 ( V_88 , 18 , V_82 ) ;
V_134 = V_135 = V_136 = 0 ;
return V_141 ;
}
V_136 = 1 ;
if ( V_82 -> V_139 [ 0 ] == V_142 ) {
memcpy ( V_88 , V_137 , 8 ) ;
F_50 ( V_21 , V_88 , 36 ) ;
return V_141 ;
}
if ( V_82 -> V_139 [ 0 ] == V_143 ) {
struct V_6 * V_106 ;
F_36 ( V_21 , V_62 ) ;
V_106 = F_37 ( V_21 , V_62 -> V_104 ) ;
if ( ! V_106 ) {
V_144:
V_134 = 0x02 ;
V_135 = 0x3a ;
return V_145 ;
}
V_62 -> V_76 = ( 1 << V_106 -> V_108 ) ;
V_62 -> V_51 = V_106 -> V_51 ;
V_62 -> V_78 = ( 1 << V_62 -> V_51 ) ;
V_62 -> V_74 = V_106 -> V_74 ;
V_62 -> V_77 = ( 1 << V_62 -> V_74 ) ;
V_62 -> V_75 = V_62 -> V_77 - 1 ;
if ( F_38 ( V_21 ) ) {
goto V_144;
}
V_76 = ( V_62 -> V_113 << V_62 -> V_74 ) - 1 ;
( ( V_146 * ) V_88 ) [ 0 ] = F_51 ( V_76 ) ;
( ( V_146 * ) V_88 ) [ 1 ] = F_51 ( V_62 -> V_78 ) ;
F_49 ( V_88 , 8 , V_82 ) ;
return V_141 ;
}
if ( V_82 -> V_139 [ 0 ] == V_147 ) {
int V_148 = ( V_82 -> V_139 [ 2 ] & 0x3F ) ;
if ( V_148 == 0x01 || V_148 == 0x3F ) {
F_16 ( V_21 , L_65 ,
V_148 ) ;
memcpy ( V_88 , V_138 , sizeof( V_138 ) ) ;
( ( V_149 * ) V_88 ) [ 0 ] = F_52 ( sizeof( V_138 ) - 2 ) ;
V_88 [ 3 ] = ( V_62 -> V_104 & V_105 ) ? 0x80 : 0 ;
F_49 ( V_88 , sizeof( V_138 ) , V_82 ) ;
return V_141 ;
}
V_134 = 0x05 ;
V_135 = 0x24 ;
return V_145 ;
}
if ( V_82 -> V_139 [ 0 ] == V_150 )
return V_141 ;
V_136 = 0 ;
if ( V_82 -> V_139 [ 0 ] == V_151 ) {
V_68 = F_40 ( V_82 -> V_139 [ 3 ] , V_82 -> V_139 [ 2 ] ) ;
V_68 <<= 16 ;
V_68 |= F_40 ( V_82 -> V_139 [ 5 ] , V_82 -> V_139 [ 4 ] ) ;
V_69 = F_40 ( V_82 -> V_139 [ 8 ] , V_82 -> V_139 [ 7 ] ) ;
F_16 ( V_21 , L_66 ,
V_68 , V_69 ) ;
V_42 = F_25 ( V_21 , V_68 , V_69 ) ;
return ( V_42 == 0 ? V_141 :
V_133 ) ;
}
if ( V_82 -> V_139 [ 0 ] == V_152 ) {
V_68 = F_40 ( V_82 -> V_139 [ 3 ] , V_82 -> V_139 [ 2 ] ) ;
V_68 <<= 16 ;
V_68 |= F_40 ( V_82 -> V_139 [ 5 ] , V_82 -> V_139 [ 4 ] ) ;
V_69 = F_40 ( V_82 -> V_139 [ 8 ] , V_82 -> V_139 [ 7 ] ) ;
F_16 ( V_21 , L_67 ,
V_68 , V_69 ) ;
V_42 = F_33 ( V_21 , V_68 , V_69 ) ;
return ( V_42 == 0 ? V_141 :
V_133 ) ;
}
if ( V_82 -> V_139 [ 0 ] != V_153 &&
V_82 -> V_139 [ 0 ] != V_140 ) {
V_134 = 0x05 ;
V_135 = 0x20 ;
V_136 = 1 ;
return V_145 ;
}
for (; V_82 -> V_154 < 12 ; V_82 -> V_154 ++ )
V_82 -> V_139 [ V_82 -> V_154 ] = 0 ;
V_82 -> V_139 [ 1 ] = V_43 ;
V_88 [ 0 ] = 0 ;
for ( V_8 = 0 ; V_8 < 12 ; V_8 ++ )
sprintf ( V_88 + strlen ( V_88 ) , L_68 , V_82 -> V_139 [ V_8 ] ) ;
F_16 ( V_21 , L_69 , V_88 ) ;
V_42 = F_10 ( V_21 , V_82 -> V_139 , 12 ) ;
if ( V_42 ) {
F_16 ( V_21 , L_70 ,
V_42 ) ;
return V_133 ;
}
if ( F_53 ( V_82 ) == 0 )
return V_141 ;
if ( V_82 -> V_155 == V_156 ||
V_82 -> V_155 == V_157 ) {
unsigned int V_26 = ( V_82 -> V_155 == V_156 )
? V_21 -> V_57 : V_21 -> V_44 ;
F_16 ( V_21 , L_71 ,
( V_82 -> V_155 == V_156 ) ?
L_72 : L_73 ,
F_53 ( V_82 ) ) ;
V_42 = F_54 ( V_21 , V_26 , V_82 ) ;
return ( V_42 == V_32 ?
V_141 : V_133 ) ;
}
return V_141 ;
}
static int
F_55 ( struct V_20 * V_21 ) {
return F_42 ( V_21 ) ;
}
static int F_56 ( struct V_158 * V_159 ,
const struct V_160 * V_7 )
{
struct V_20 * V_21 ;
int V_42 ;
V_42 = F_57 ( & V_21 , V_159 , V_7 ,
( V_7 - V_161 ) + V_162 ,
& V_163 ) ;
if ( V_42 )
return V_42 ;
if ( V_21 -> V_164 == V_165 ) {
V_21 -> V_166 = L_74 ;
V_21 -> V_167 = F_46 ;
V_21 -> V_168 = V_169 ;
V_21 -> V_170 = 1 ;
} else {
V_21 -> V_166 = L_75 ;
V_21 -> V_167 = F_48 ;
V_21 -> V_168 = V_169 ;
V_21 -> V_170 = 0 ;
}
V_42 = F_58 ( V_21 ) ;
return V_42 ;
}
