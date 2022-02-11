static void F_1 ( unsigned char * V_1 ,
unsigned char V_2 ,
T_1 V_3 , unsigned char V_4 )
{
V_1 [ 0 ] = 0 ;
V_1 [ 1 ] = V_2 ;
V_1 [ 2 ] = V_3 & 0xFF ;
V_1 [ 3 ] = ( V_3 >> 8 ) & 0xFF ;
V_1 [ 4 ] = ( V_3 >> 16 ) & 0xFF ;
V_1 [ 5 ] = 0xE0 | ( ( V_3 >> 24 ) & 0x0F ) ;
V_1 [ 6 ] = V_4 ;
}
static int F_2 ( struct V_5 * V_6 )
{
return ( (struct V_7 * ) V_6 -> V_8 ) -> V_9 ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned char V_10 ,
unsigned char V_11 ,
unsigned char * V_12 )
{
return F_4 ( V_6 ,
V_6 -> V_13 ,
V_10 | V_14 ,
0xC0 ,
( V_15 ) V_11 ,
0 ,
V_12 ,
1 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
unsigned char V_10 ,
unsigned char V_11 ,
unsigned char V_12 )
{
return F_4 ( V_6 ,
V_6 -> V_16 ,
V_10 | V_17 ,
0x40 ,
F_6 ( V_11 , V_12 ) ,
0 ,
NULL ,
0 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
void * V_1 ,
unsigned int V_18 ,
int V_19 )
{
if ( V_18 == 0 )
return V_20 ;
F_8 ( L_1 , V_18 ) ;
return F_9 ( V_6 , V_6 -> V_21 , V_1 , V_18 , V_19 , NULL ) ;
}
static int F_10 ( struct V_5 * V_6 ,
void * V_1 ,
unsigned int V_18 ,
int V_19 )
{
if ( V_18 == 0 )
return V_20 ;
F_8 ( L_2 , V_18 ) ;
return F_9 ( V_6 , V_6 -> V_22 , V_1 , V_18 , V_19 , NULL ) ;
}
static int F_11 ( struct V_5 * V_6 ,
unsigned char * V_23 ,
unsigned int V_18 )
{
return F_4 ( V_6 , V_6 -> V_16 ,
V_24 , 0x40 , 0 , 0 ,
V_23 , V_18 ) ;
}
static int F_12 ( struct V_5 * V_6 , unsigned char * V_25 )
{
int V_26 ;
V_26 = F_3 ( V_6 , V_27 , V_28 , V_25 ) ;
F_8 ( L_3 , ( unsigned short ) ( * V_25 ) ) ;
return V_26 ;
}
static int F_13 ( struct V_5 * V_6 )
{
unsigned char * V_29 = V_6 -> V_30 ;
int V_26 ;
V_26 = F_12 ( V_6 , V_29 ) ;
if ( V_26 != V_20 )
return V_31 ;
if ( * V_29 & 0x01 && * V_29 != 0x51 )
return V_31 ;
if ( * V_29 & 0x20 )
return V_31 ;
return V_32 ;
}
static int F_14 ( struct V_5 * V_6 ,
unsigned char V_33 ,
unsigned char V_34 ,
unsigned char V_35 ,
unsigned char V_36 ,
unsigned char V_37 ,
unsigned char V_38 )
{
unsigned char * V_39 = V_6 -> V_30 ;
V_39 [ 0 ] = 0x40 ;
V_39 [ 1 ] = V_40 ;
V_39 [ 2 ] = V_34 ;
V_39 [ 3 ] = V_33 ;
V_39 [ 4 ] = V_36 ;
V_39 [ 5 ] = V_35 ;
V_39 [ 6 ] = V_38 ;
V_39 [ 7 ] = V_37 ;
return F_11 ( V_6 , V_39 , 8 ) ;
}
static int F_15 ( struct V_5 * V_6 , int V_41 )
{
int V_42 ;
int V_43 ;
unsigned char * V_25 = V_6 -> V_30 ;
for ( V_42 = 0 ; V_42 < 1200 + V_41 * 60 ; V_42 ++ ) {
V_43 = F_12 ( V_6 , V_25 ) ;
if ( V_43 != V_20 )
return V_44 ;
if ( * V_25 & 0x01 ) {
V_43 = F_3 ( V_6 , V_27 , 0x10 , V_25 ) ;
return V_31 ;
}
if ( * V_25 & 0x20 )
return V_31 ;
if ( ( * V_25 & 0x80 ) == 0x00 ) {
F_8 ( L_4 , V_42 ) ;
return V_32 ;
}
if ( V_42 < 500 )
F_16 ( 10 ) ;
else if ( V_42 < 700 )
F_16 ( 50 ) ;
else if ( V_42 < 1200 )
F_16 ( 100 ) ;
else
F_16 ( 1000 ) ;
}
F_8 ( L_5 ,
V_41 ) ;
return V_31 ;
}
static int F_17 ( struct V_5 * V_6 ,
void * V_1 ,
unsigned short V_18 ,
int V_19 )
{
int V_43 ;
unsigned char * V_39 = V_6 -> V_30 ;
if ( ! V_18 )
return V_32 ;
V_39 [ 0 ] = 0xC0 ;
V_39 [ 1 ] = V_27 | V_45 ;
V_39 [ 2 ] = V_46 ;
V_39 [ 3 ] = 0 ;
V_39 [ 4 ] = 0 ;
V_39 [ 5 ] = 0 ;
V_39 [ 6 ] = F_18 ( V_18 ) ;
V_39 [ 7 ] = F_19 ( V_18 ) ;
V_43 = F_11 ( V_6 , V_39 , 8 ) ;
if ( V_43 != V_20 )
return V_44 ;
V_43 = F_7 ( V_6 , V_1 , V_18 , V_19 ) ;
return ( V_43 == V_20 ?
V_32 : V_44 ) ;
}
static int F_20 ( struct V_5 * V_6 ,
unsigned char V_10 ,
void * V_1 ,
unsigned short V_18 ,
int V_41 ,
int V_19 )
{
int V_43 ;
unsigned char * V_39 = V_6 -> V_30 ;
if ( ! V_18 )
return V_32 ;
V_39 [ 0 ] = 0x40 ;
V_39 [ 1 ] = V_10 | V_47 ;
V_39 [ 2 ] = V_46 ;
V_39 [ 3 ] = 0 ;
V_39 [ 4 ] = 0 ;
V_39 [ 5 ] = 0 ;
V_39 [ 6 ] = F_18 ( V_18 ) ;
V_39 [ 7 ] = F_19 ( V_18 ) ;
V_43 = F_11 ( V_6 , V_39 , 8 ) ;
if ( V_43 != V_20 )
return V_44 ;
V_43 = F_10 ( V_6 , V_1 , V_18 , V_19 ) ;
if ( V_43 != V_20 )
return V_44 ;
return F_15 ( V_6 , V_41 ) ;
}
static int F_21 ( struct V_5 * V_6 ,
unsigned char V_10 ,
unsigned char * V_48 ,
unsigned char * V_49 ,
unsigned short V_50 ,
unsigned char V_51 ,
unsigned char V_52 ,
unsigned char V_53 ,
unsigned char V_54 ,
int V_55 ,
void * V_1 ,
unsigned short V_18 ,
int V_19 ,
int V_41 )
{
int V_43 ;
unsigned int V_56 = ( V_55 == V_57 ) ?
V_6 -> V_21 : V_6 -> V_22 ;
unsigned char * V_39 = V_6 -> V_30 ;
int V_42 , V_58 ;
int V_59 ;
unsigned char * V_60 = V_6 -> V_30 ;
unsigned char * V_25 = V_6 -> V_30 ;
F_22 ( V_50 > V_61 / 2 ) ;
for ( V_42 = 0 ; V_42 < 20 ; V_42 ++ ) {
if ( V_42 == 0 ) {
V_59 = 16 ;
V_39 [ 0 ] = 0x40 ;
V_39 [ 1 ] = V_10 | V_62 ;
V_39 [ 2 ] = 0x07 ;
V_39 [ 3 ] = 0x17 ;
V_39 [ 4 ] = 0xFC ;
V_39 [ 5 ] = 0xE7 ;
V_39 [ 6 ] = F_18 ( V_50 * 2 ) ;
V_39 [ 7 ] = F_19 ( V_50 * 2 ) ;
} else
V_59 = 8 ;
V_39 [ V_59 - 8 ] = ( V_55 == V_63 ? 0x40 : 0xC0 ) ;
V_39 [ V_59 - 7 ] = V_10 |
( V_55 == V_63 ?
V_64 : V_65 ) ;
V_39 [ V_59 - 6 ] = V_51 ;
V_39 [ V_59 - 5 ] = V_52 ;
V_39 [ V_59 - 4 ] = V_53 ;
V_39 [ V_59 - 3 ] = V_54 ;
V_39 [ V_59 - 2 ] = F_18 ( V_18 ) ;
V_39 [ V_59 - 1 ] = F_19 ( V_18 ) ;
V_43 = F_11 ( V_6 , V_39 , V_59 ) ;
if ( V_43 != V_20 )
return V_44 ;
if ( V_42 == 0 ) {
for ( V_58 = 0 ; V_58 < V_50 ; V_58 ++ ) {
V_60 [ V_58 << 1 ] = V_48 [ V_58 ] ;
V_60 [ 1 + ( V_58 << 1 ) ] = V_49 [ V_58 ] ;
}
V_43 = F_10 ( V_6 , V_60 , V_50 * 2 , 0 ) ;
if ( V_43 != V_20 )
return V_44 ;
}
V_43 = F_9 ( V_6 ,
V_56 , V_1 , V_18 , V_19 , NULL ) ;
if ( V_43 == V_66 ||
V_43 == V_67 ) {
if ( V_55 == V_57 && V_42 == 0 ) {
if ( F_23 ( V_6 ,
V_6 -> V_22 ) < 0 )
return V_44 ;
}
V_43 = F_3 ( V_6 , V_27 ,
V_55 == V_63 ?
V_28 : V_68 ,
V_25 ) ;
if ( V_43 != V_20 )
return V_44 ;
if ( * V_25 & 0x01 )
return V_31 ;
if ( * V_25 & 0x20 )
return V_31 ;
F_8 ( L_6 ,
V_55 == V_63 ? L_7 : L_8 ) ;
} else if ( V_43 != V_20 )
return V_44 ;
else
return F_15 ( V_6 , V_41 ) ;
}
F_8 ( L_9 ,
V_55 == V_63 ? L_10 : L_11 ) ;
return V_31 ;
}
static int F_24 ( struct V_5 * V_6 ,
unsigned char * V_48 ,
unsigned char * V_49 ,
unsigned short V_50 )
{
int V_42 , V_43 ;
unsigned char * V_60 = V_6 -> V_30 ;
unsigned char * V_39 = V_6 -> V_30 ;
F_22 ( V_50 > V_61 / 2 ) ;
V_39 [ 0 ] = 0x40 ;
V_39 [ 1 ] = V_27 | V_62 ;
V_39 [ 2 ] = 0 ;
V_39 [ 3 ] = 0 ;
V_39 [ 4 ] = 0 ;
V_39 [ 5 ] = 0 ;
V_39 [ 6 ] = F_18 ( V_50 * 2 ) ;
V_39 [ 7 ] = F_19 ( V_50 * 2 ) ;
V_43 = F_11 ( V_6 , V_39 , 8 ) ;
if ( V_43 != V_20 )
return V_44 ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
V_60 [ V_42 << 1 ] = V_48 [ V_42 ] ;
V_60 [ 1 + ( V_42 << 1 ) ] = V_49 [ V_42 ] ;
}
V_43 = F_10 ( V_6 , V_60 , V_50 * 2 , 0 ) ;
if ( V_43 != V_20 )
return V_44 ;
if ( F_2 ( V_6 ) == V_69 )
return F_15 ( V_6 , 0 ) ;
else
return V_32 ;
}
static int F_25 ( struct V_5 * V_6 ,
void * V_70 ,
int V_18 ,
int V_19 )
{
int V_43 ;
unsigned char * V_39 = V_6 -> V_30 ;
V_39 [ 0 ] = 0xC0 ;
V_39 [ 1 ] = V_27 | V_65 ;
V_39 [ 2 ] = V_46 ;
V_39 [ 3 ] = V_28 ;
V_39 [ 4 ] = 0xFD ;
V_39 [ 5 ] = V_71 ;
V_39 [ 6 ] = F_18 ( V_18 ) ;
V_39 [ 7 ] = F_19 ( V_18 ) ;
V_43 = F_11 ( V_6 , V_39 , 8 ) ;
if ( V_43 != V_20 )
return V_31 ;
V_43 = F_7 ( V_6 , V_70 , V_18 , V_19 ) ;
if ( V_43 != V_20 )
return V_31 ;
return V_32 ;
}
static int F_26 ( struct V_5 * V_6 ,
void * V_70 ,
int V_18 ,
int V_19 )
{
int V_43 ;
unsigned char * V_39 = V_6 -> V_30 ;
V_39 [ 0 ] = 0x40 ;
V_39 [ 1 ] = V_27 | V_64 ;
V_39 [ 2 ] = V_46 ;
V_39 [ 3 ] = V_28 ;
V_39 [ 4 ] = 0xFD ;
V_39 [ 5 ] = V_71 ;
V_39 [ 6 ] = F_18 ( V_18 ) ;
V_39 [ 7 ] = F_19 ( V_18 ) ;
V_43 = F_11 ( V_6 , V_39 , 8 ) ;
if ( V_43 != V_20 )
return V_31 ;
V_43 = F_10 ( V_6 , V_70 , V_18 , V_19 ) ;
if ( V_43 != V_20 )
return V_31 ;
return V_32 ;
}
static int F_27 ( struct V_5 * V_6 , unsigned char * V_72 )
{
int V_43 ;
V_43 = F_4 ( V_6 ,
V_6 -> V_13 ,
V_73 ,
0xC0 ,
0 ,
0 ,
V_72 ,
V_74 ) ;
F_8 ( L_12 , ( unsigned short ) ( * V_72 ) ) ;
return V_43 ;
}
static int F_28 ( struct V_5 * V_6 ,
unsigned char V_75 ,
unsigned char V_72 )
{
return F_4 ( V_6 ,
V_6 -> V_16 ,
V_73 ,
0x40 ,
F_6 ( V_75 , V_72 ) ,
0 ,
NULL ,
V_76 ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_26 ;
V_26 = F_28 ( V_6 ,
V_77 | V_78 | V_79 ,
V_80 | V_81 ) ;
if ( V_26 != V_20 )
return V_44 ;
V_26 = F_28 ( V_6 ,
V_78 | V_79 ,
V_80 | V_81 ) ;
if ( V_26 != V_20 )
return V_44 ;
return V_32 ;
}
static int F_30 ( struct V_5 * V_6 )
{
int V_26 ;
V_26 = F_28 ( V_6 ,
V_82 | V_78 | V_79 ,
V_80 | V_81 ) ;
if ( V_26 != V_20 )
return V_44 ;
return V_32 ;
}
static int F_31 ( unsigned char * V_83 )
{
if ( * V_83 & V_84 ) {
F_8 ( L_13 ) ;
return V_85 ;
}
return V_86 ;
}
static int F_32 ( unsigned char * V_83 )
{
if ( * V_83 & V_87 ) {
F_8 ( L_14 ) ;
return V_88 ;
}
return V_89 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_7 * V_90 )
{
int V_26 ;
unsigned char * V_83 = V_6 -> V_30 ;
V_26 = F_27 ( V_6 , V_83 ) ;
if ( V_26 != V_20 )
return V_44 ;
V_26 = F_31 ( V_83 ) ;
if ( V_26 == V_85 ) {
V_90 -> V_91 = 0x02 ;
V_90 -> V_92 = 0x3A ;
V_90 -> V_93 = 0x00 ;
return V_31 ;
}
V_26 = F_32 ( V_83 ) ;
if ( V_26 == V_88 ) {
V_26 = F_29 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
V_26 = F_30 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_16 ( 50 ) ;
V_26 = F_27 ( V_6 , V_83 ) ;
if ( V_26 != V_20 )
return V_44 ;
V_90 -> V_91 = V_94 ;
V_90 -> V_92 = 0x28 ;
V_90 -> V_93 = 0x00 ;
return V_31 ;
}
return V_32 ;
}
static int F_34 ( struct V_5 * V_6 ,
struct V_7 * V_90 )
{
int V_26 ;
unsigned char V_25 ;
if ( ! V_6 || ! V_90 )
return V_44 ;
V_26 = F_29 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_16 ( 500 ) ;
V_26 = F_5 ( V_6 , V_27 , V_95 , 0xA1 ) ;
if ( V_26 != V_20 )
return V_44 ;
V_26 = F_12 ( V_6 , & V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
if ( V_25 == 0xA1 || ! ( V_25 & 0x01 ) ) {
F_8 ( L_15 ) ;
V_90 -> V_9 = V_69 ;
} else {
F_8 ( L_16 ) ;
V_90 -> V_9 = V_96 ;
}
return V_32 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_7 * V_90 ,
int V_9 )
{
if ( ! V_90 -> V_9 )
V_90 -> V_9 = V_9 ;
if ( ! V_90 -> V_9 )
F_34 ( V_6 , V_90 ) ;
switch ( V_90 -> V_9 ) {
default:
return V_44 ;
case V_69 :
V_6 -> V_97 = V_98 ;
break;
case V_96 :
V_6 -> V_97 = V_99 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_7 * V_90 )
{
unsigned char V_48 [ 3 ] = {
V_100 ,
V_101 ,
V_95 ,
} ;
unsigned char V_39 [ 3 ] = { 0x01 , 0xA0 , 0xEC } ;
unsigned char * V_29 ;
unsigned char V_25 ;
int V_26 ;
if ( ! V_6 || ! V_90 )
return V_44 ;
V_29 = F_37 ( 512 , V_102 ) ;
if ( ! V_29 )
return V_44 ;
V_26 = F_24 ( V_6 , V_48 , V_39 , 3 ) ;
if ( V_26 != V_20 ) {
F_8 ( L_17 ) ;
V_26 = V_44 ;
goto V_103;
}
if ( F_12 ( V_6 , & V_25 ) != V_20 ) {
V_26 = V_44 ;
goto V_103;
}
F_16 ( 100 ) ;
V_26 = F_17 ( V_6 , V_29 , 512 , 0 ) ;
if ( V_26 != V_32 )
goto V_103;
V_90 -> V_104 = ( ( T_1 ) ( V_29 [ 117 ] ) << 24 ) |
( ( T_1 ) ( V_29 [ 116 ] ) << 16 ) |
( ( T_1 ) ( V_29 [ 115 ] ) << 8 ) |
( ( T_1 ) ( V_29 [ 114 ] ) ) ;
V_26 = V_32 ;
V_103:
F_38 ( V_29 ) ;
return V_26 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_7 * V_90 ,
T_1 V_3 ,
T_1 V_104 )
{
unsigned char V_48 [ 7 ] = {
V_105 ,
V_100 ,
V_106 ,
V_107 ,
V_108 ,
V_101 ,
V_28 ,
} ;
unsigned char V_39 [ 7 ] ;
unsigned char * V_70 ;
unsigned char V_2 ;
unsigned int V_109 , V_110 ;
int V_18 , V_43 ;
unsigned int V_111 = 0 ;
struct V_112 * V_113 = NULL ;
V_43 = F_33 ( V_6 , V_90 ) ;
if ( V_43 != V_32 )
return V_43 ;
if ( V_3 > 0x0FFFFFFF )
return V_44 ;
V_109 = V_104 * V_90 -> V_114 ;
V_110 = F_40 ( V_109 , 65536u ) ;
V_70 = F_37 ( V_110 , V_102 ) ;
if ( V_70 == NULL )
return V_44 ;
do {
V_18 = F_40 ( V_109 , V_110 ) ;
V_2 = ( V_18 / V_90 -> V_114 ) & 0xff ;
F_1 ( V_39 , V_2 , V_3 , 0x20 ) ;
V_43 = F_24 ( V_6 , V_48 , V_39 , 7 ) ;
if ( V_43 != V_32 )
goto V_103;
V_43 = F_25 ( V_6 , V_70 , V_18 , 0 ) ;
if ( V_43 != V_32 )
goto V_103;
F_8 ( L_18 , V_18 ) ;
F_41 ( V_70 , V_18 , V_6 -> V_115 ,
& V_113 , & V_111 , V_116 ) ;
V_3 += V_2 ;
V_109 -= V_18 ;
} while ( V_109 > 0 );
F_38 ( V_70 ) ;
return V_32 ;
V_103:
F_38 ( V_70 ) ;
return V_44 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_7 * V_90 ,
T_1 V_3 ,
T_1 V_104 )
{
unsigned char V_48 [ 7 ] = {
V_105 ,
V_100 ,
V_106 ,
V_107 ,
V_108 ,
V_101 ,
V_28 ,
} ;
unsigned char V_39 [ 7 ] ;
unsigned char * V_70 ;
unsigned char V_2 ;
unsigned int V_109 , V_110 ;
int V_18 , V_43 ;
unsigned int V_111 = 0 ;
struct V_112 * V_113 = NULL ;
V_43 = F_33 ( V_6 , V_90 ) ;
if ( V_43 != V_32 )
return V_43 ;
if ( V_3 > 0x0FFFFFFF )
return V_44 ;
V_109 = V_104 * V_90 -> V_114 ;
V_110 = F_40 ( V_109 , 65536u ) ;
V_70 = F_37 ( V_110 , V_102 ) ;
if ( V_70 == NULL )
return V_44 ;
do {
V_18 = F_40 ( V_109 , V_110 ) ;
V_2 = ( V_18 / V_90 -> V_114 ) & 0xff ;
F_41 ( V_70 , V_18 , V_6 -> V_115 ,
& V_113 , & V_111 , V_117 ) ;
F_1 ( V_39 , V_2 , V_3 , 0x30 ) ;
V_43 = F_24 ( V_6 , V_48 , V_39 , 7 ) ;
if ( V_43 != V_32 )
goto V_103;
V_43 = F_26 ( V_6 , V_70 , V_18 , 0 ) ;
if ( V_43 != V_32 )
goto V_103;
V_3 += V_2 ;
V_109 -= V_18 ;
} while ( V_109 > 0 );
F_38 ( V_70 ) ;
return V_43 ;
V_103:
F_38 ( V_70 ) ;
return V_44 ;
}
static int F_43 ( struct V_5 * V_6 ,
unsigned char * V_48 ,
unsigned char * V_60 ,
struct V_118 * V_115 )
{
int V_43 = V_32 ;
unsigned char * V_70 ;
unsigned int V_18 ;
unsigned int V_3 ;
unsigned int V_111 = 0 ;
struct V_112 * V_113 = NULL ;
F_8 ( L_19 ,
V_115 -> V_119 ) ;
if ( F_44 ( V_115 ) < 0x10000 ) {
V_43 = F_21 ( V_6 , V_27 ,
V_48 , V_60 , 19 ,
V_46 , V_28 , 0xFD ,
( V_71 | V_120 ) ,
V_57 ,
F_45 ( V_115 ) ,
F_44 ( V_115 ) , F_46 ( V_115 ) , 1 ) ;
return V_43 ;
}
if ( V_60 [ 7 + 0 ] == V_121 ) {
V_18 = F_6 ( V_60 [ 7 + 9 ] , V_60 [ 7 + 8 ] ) ;
V_18 <<= 16 ;
V_18 |= V_60 [ 7 + 7 ] ;
F_8 ( L_20 , V_18 ) ;
V_115 -> V_119 = F_44 ( V_115 ) / V_18 ;
}
if ( ! V_115 -> V_119 ) {
V_115 -> V_119 = 2048 ;
F_8 ( L_21 ,
V_115 -> V_119 ) ;
}
V_18 = ( 65535 / V_115 -> V_119 ) * V_115 -> V_119 ;
F_8 ( L_22 , V_18 ) ;
V_18 = F_40 ( V_18 , F_44 ( V_115 ) ) ;
V_70 = F_37 ( V_18 , V_102 ) ;
if ( V_70 == NULL )
return V_31 ;
V_3 = F_6 ( V_60 [ 7 + 3 ] , V_60 [ 7 + 2 ] ) ;
V_3 <<= 16 ;
V_3 |= F_6 ( V_60 [ 7 + 5 ] , V_60 [ 7 + 4 ] ) ;
V_122 = 0 ;
while ( V_122 != F_44 ( V_115 ) ) {
if ( V_18 > F_44 ( V_115 ) - V_122 )
V_18 = F_44 ( V_115 ) - V_122 ;
V_60 [ 3 ] = V_18 & 0xFF ;
V_60 [ 4 ] = ( V_18 >> 8 ) & 0xFF ;
V_60 [ 7 + 2 ] = F_19 ( V_3 >> 16 ) ;
V_60 [ 7 + 3 ] = F_18 ( V_3 >> 16 ) ;
V_60 [ 7 + 4 ] = F_19 ( V_3 & 0xFFFF ) ;
V_60 [ 7 + 5 ] = F_18 ( V_3 & 0xFFFF ) ;
if ( V_60 [ 7 + 0 ] == V_121 )
V_60 [ 7 + 6 ] = 0 ;
V_60 [ 7 + 7 ] = F_19 ( V_18 / V_115 -> V_119 ) ;
V_60 [ 7 + 8 ] = F_18 ( V_18 / V_115 -> V_119 ) ;
V_43 = F_21 ( V_6 , V_27 ,
V_48 , V_60 , 19 ,
V_46 , V_28 , 0xFD ,
( V_71 | V_120 ) ,
V_57 ,
V_70 ,
V_18 , 0 , 1 ) ;
if ( V_43 != V_32 )
break;
F_41 ( V_70 , V_18 , V_115 ,
& V_113 , & V_111 , V_116 ) ;
V_122 += V_18 ;
V_3 += V_18 / V_115 -> V_119 ;
}
F_38 ( V_70 ) ;
return V_43 ;
}
static int F_47 ( struct V_5 * V_6 )
{
int V_123 ;
unsigned char * V_25 = V_6 -> V_30 ;
for ( V_123 = 0xA0 ; V_123 <= 0xB0 ; V_123 += 0x10 ) {
if ( F_5 ( V_6 , V_27 , V_101 , V_123 ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_28 , V_25 ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_101 , V_25 ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_107 , V_25 ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_108 , V_25 ) !=
V_20 )
return V_44 ;
if ( F_5 ( V_6 , V_27 , V_107 , 0x55 ) !=
V_20 )
return V_44 ;
if ( F_5 ( V_6 , V_27 , V_108 , 0xAA ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_107 , V_25 ) !=
V_20 )
return V_44 ;
if ( F_3 ( V_6 , V_27 , V_107 , V_25 ) !=
V_20 )
return V_44 ;
}
return V_32 ;
}
static int F_48 ( struct V_5 * V_6 , int V_9 )
{
int V_26 ;
struct V_7 * V_90 ;
unsigned char V_37 = V_108 ;
unsigned char V_38 = V_107 ;
unsigned char * V_25 = V_6 -> V_30 ;
V_6 -> V_8 = F_49 ( sizeof( struct V_7 ) , V_102 ) ;
if ( ! V_6 -> V_8 ) {
F_8 ( L_23 ) ;
return 1 ;
}
V_90 = (struct V_7 * ) ( V_6 -> V_8 ) ;
V_26 = F_28 ( V_6 ,
V_78 | V_79 ,
V_80 | V_81 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_24 ) ;
F_16 ( 2000 ) ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_8 ( L_25 ) ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_26 ) ;
V_26 = F_47 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_8 ( L_27 ) ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_28 ) ;
V_26 = F_30 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_8 ( L_29 ) ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_30 ) ;
F_16 ( 1400 ) ;
V_26 = F_27 ( V_6 , V_25 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_31 ) ;
V_26 = F_47 ( V_6 ) ;
if ( V_26 != V_32 )
return V_26 ;
F_8 ( L_32 ) ;
if ( F_35 ( V_6 , V_90 , V_9 ) )
return V_44 ;
F_8 ( L_33 ) ;
if ( F_2 ( V_6 ) == V_96 ) {
V_37 = 0x02 ;
V_38 = 0x00 ;
}
V_26 = F_14 ( V_6 , ( V_124 | V_125 | V_126 ) ,
0x00 , 0x88 , 0x08 , V_37 , V_38 ) ;
if ( V_26 != V_20 )
return V_44 ;
F_8 ( L_34 ) ;
return V_32 ;
}
static int V_98 ( struct V_118 * V_115 , struct V_5 * V_6 )
{
int V_43 ;
unsigned char * V_25 = V_6 -> V_30 ;
unsigned char V_48 [ 32 ] ;
unsigned char V_60 [ 32 ] ;
unsigned int V_18 ;
int V_42 ;
V_18 = F_44 ( V_115 ) ;
V_48 [ 0 ] = V_105 ;
V_48 [ 1 ] = V_100 ;
V_48 [ 2 ] = V_106 ;
V_48 [ 3 ] = V_107 ;
V_48 [ 4 ] = V_108 ;
V_48 [ 5 ] = V_101 ;
V_48 [ 6 ] = V_95 ;
V_60 [ 0 ] = 0x00 ;
V_60 [ 1 ] = 0x00 ;
V_60 [ 2 ] = 0x00 ;
V_60 [ 3 ] = V_18 & 0xFF ;
V_60 [ 4 ] = ( V_18 >> 8 ) & 0xFF ;
V_60 [ 5 ] = 0xB0 ;
V_60 [ 6 ] = 0xA0 ;
for ( V_42 = 7 ; V_42 < 19 ; V_42 ++ ) {
V_48 [ V_42 ] = 0x10 ;
V_60 [ V_42 ] = ( V_42 - 7 >= V_115 -> V_127 ) ? 0 : V_115 -> V_128 [ V_42 - 7 ] ;
}
V_43 = F_12 ( V_6 , V_25 ) ;
F_8 ( L_35 , * V_25 ) ;
if ( V_43 != V_20 )
return V_44 ;
if ( V_115 -> V_128 [ 0 ] == V_129 )
V_122 = 0 ;
if ( V_115 -> V_130 == V_63 ) {
V_43 = F_21 ( V_6 , V_27 ,
V_48 , V_60 , 19 ,
V_46 , V_28 , 0xFD ,
( V_71 | V_120 ) ,
V_63 ,
F_45 ( V_115 ) ,
V_18 , F_46 ( V_115 ) , 10 ) ;
if ( V_43 == V_32 ) {
V_122 += V_18 ;
F_8 ( L_36 , V_122 ) ;
}
return V_43 ;
} else if ( V_115 -> V_128 [ 0 ] == V_131 ||
V_115 -> V_128 [ 0 ] == V_121 ) {
return F_43 ( V_6 , V_48 , V_60 , V_115 ) ;
}
if ( V_18 > 0xFFFF ) {
F_8 ( L_37 ,
V_18 ) ;
return V_44 ;
}
V_43 = F_24 ( V_6 , V_48 , V_60 , 7 ) ;
if ( V_43 != V_32 )
return V_43 ;
V_43 = F_20 ( V_6 , V_27 , V_115 -> V_128 , 12 ,
V_115 -> V_128 [ 0 ] == V_132 ? 75 : 10 , 0 ) ;
if ( V_43 != V_32 )
return V_43 ;
if ( V_18 != 0 && ( V_115 -> V_130 == V_57 ) ) {
if ( F_3 ( V_6 , V_27 , V_107 , V_25 ) !=
V_20 ) {
return V_44 ;
}
if ( V_18 > 0xFF ) {
V_18 = * V_25 ;
if ( F_3 ( V_6 , V_27 , V_108 , V_25 ) !=
V_20 ) {
return V_44 ;
}
V_18 += ( ( unsigned int ) * V_25 ) << 8 ;
}
else
V_18 = * V_25 ;
V_43 = F_17 ( V_6 , F_45 ( V_115 ) , V_18 ,
F_46 ( V_115 ) ) ;
}
return V_43 ;
}
static int V_99 ( struct V_118 * V_115 , struct V_5 * V_6 )
{
int V_26 ;
struct V_7 * V_90 = (struct V_7 * ) ( V_6 -> V_8 ) ;
unsigned long V_133 , V_134 ;
unsigned char * V_135 = V_6 -> V_30 ;
static unsigned char V_136 [ 36 ] = {
0x00 , 0x80 , 0x00 , 0x01 , 0x1F , 0x00 , 0x00 , 0x00
} ;
if ( V_115 -> V_128 [ 0 ] == V_137 ) {
F_8 ( L_38 ) ;
memcpy ( V_135 , V_136 , sizeof( V_136 ) ) ;
F_50 ( V_6 , V_135 , 36 ) ;
return V_32 ;
}
if ( V_115 -> V_128 [ 0 ] == V_138 ) {
V_26 = F_33 ( V_6 , V_90 ) ;
if ( V_26 != V_32 )
return V_26 ;
V_26 = F_36 ( V_6 , V_90 ) ;
if ( V_26 != V_32 )
return V_26 ;
V_90 -> V_114 = 0x200 ;
F_8 ( L_39 ,
V_90 -> V_104 , V_90 -> V_114 ) ;
( ( V_139 * ) V_135 ) [ 0 ] = F_51 ( V_90 -> V_104 - 1 ) ;
( ( V_139 * ) V_135 ) [ 1 ] = F_51 ( V_90 -> V_114 ) ;
F_52 ( V_135 , 8 , V_115 ) ;
return V_32 ;
}
if ( V_115 -> V_128 [ 0 ] == V_140 ) {
F_8 ( L_40 ) ;
return V_44 ;
}
if ( V_115 -> V_128 [ 0 ] == V_131 ) {
V_133 = ( ( T_1 ) ( V_115 -> V_128 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 5 ] ) ) ;
V_134 = ( ( T_1 ) ( V_115 -> V_128 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 8 ] ) ) ;
F_8 ( L_41 , V_133 , V_134 ) ;
return F_39 ( V_6 , V_90 , V_133 , V_134 ) ;
}
if ( V_115 -> V_128 [ 0 ] == V_141 ) {
V_133 = ( ( T_1 ) ( V_115 -> V_128 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 5 ] ) ) ;
V_134 = ( ( T_1 ) ( V_115 -> V_128 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 9 ] ) ) ;
F_8 ( L_42 , V_133 , V_134 ) ;
return F_39 ( V_6 , V_90 , V_133 , V_134 ) ;
}
if ( V_115 -> V_128 [ 0 ] == V_142 ) {
V_133 = ( ( T_1 ) ( V_115 -> V_128 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 5 ] ) ) ;
V_134 = ( ( T_1 ) ( V_115 -> V_128 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 8 ] ) ) ;
F_8 ( L_43 , V_133 , V_134 ) ;
return F_42 ( V_6 , V_90 , V_133 , V_134 ) ;
}
if ( V_115 -> V_128 [ 0 ] == V_143 ) {
V_133 = ( ( T_1 ) ( V_115 -> V_128 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 5 ] ) ) ;
V_134 = ( ( T_1 ) ( V_115 -> V_128 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_115 -> V_128 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_115 -> V_128 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_115 -> V_128 [ 9 ] ) ) ;
F_8 ( L_44 , V_133 , V_134 ) ;
return F_42 ( V_6 , V_90 , V_133 , V_134 ) ;
}
if ( V_115 -> V_128 [ 0 ] == V_129 ) {
F_8 ( L_45 ) ;
V_26 = F_33 ( V_6 , V_90 ) ;
if ( V_26 != V_32 )
return V_26 ;
return F_13 ( V_6 ) ;
}
if ( V_115 -> V_128 [ 0 ] == V_144 ) {
F_8 ( L_46 ) ;
memset ( V_135 , 0 , 18 ) ;
V_135 [ 0 ] = 0xF0 ;
V_135 [ 2 ] = V_90 -> V_91 ;
V_135 [ 7 ] = 11 ;
V_135 [ 12 ] = V_90 -> V_92 ;
V_135 [ 13 ] = V_90 -> V_93 ;
F_52 ( V_135 , 18 , V_115 ) ;
return V_32 ;
}
if ( V_115 -> V_128 [ 0 ] == V_145 ) {
return V_32 ;
}
F_8 ( L_47 ,
V_115 -> V_128 [ 0 ] , V_115 -> V_128 [ 0 ] ) ;
V_90 -> V_91 = 0x05 ;
V_90 -> V_92 = 0x20 ;
V_90 -> V_93 = 0x00 ;
return V_31 ;
}
static int F_53 ( struct V_5 * V_6 )
{
return F_48 ( V_6 , V_69 ) ;
}
static int F_54 ( struct V_5 * V_6 )
{
return F_48 ( V_6 , V_96 ) ;
}
static int F_55 ( struct V_146 * V_147 ,
const struct V_148 * V_149 )
{
struct V_5 * V_6 ;
int V_43 ;
V_43 = F_56 ( & V_6 , V_147 , V_149 ,
( V_149 - V_150 ) + V_151 ) ;
if ( V_43 )
return V_43 ;
V_6 -> V_152 = L_48 ;
V_6 -> V_97 = V_99 ;
V_6 -> V_153 = V_154 ;
V_6 -> V_155 = 1 ;
V_43 = F_57 ( V_6 ) ;
return V_43 ;
}
