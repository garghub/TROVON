static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , int V_5 , void * V_6 , int V_7 )
{
int V_8 ;
void * V_9 = NULL ;
if ( V_7 ) {
V_9 = F_2 ( V_7 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
memcpy ( V_9 , V_6 , V_7 ) ;
}
V_8 = F_3 ( V_2 -> V_12 , F_4 ( V_2 -> V_12 , 0 ) ,
V_3 ,
V_13 | V_14 | V_15 ,
V_4 ,
V_5 ,
V_9 , V_7 , V_16 ) ;
F_5 ( V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_6 , int V_7 )
{
int V_8 ;
void * V_9 = F_2 ( V_7 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_8 = F_3 ( V_2 -> V_12 , F_7 ( V_2 -> V_12 , 0 ) ,
V_3 ,
V_17 | V_14 | V_15 ,
V_4 ,
V_2 -> V_18 ,
V_9 , V_7 , V_19 ) ;
memcpy ( V_6 , V_9 , V_7 ) ;
F_5 ( V_9 ) ;
if ( V_8 < 0 )
F_8 ( L_1 ,
V_8 , V_3 , V_4 ) ;
return V_8 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
int V_5 , void * V_6 , int V_7 )
{
return F_1 ( V_2 ,
V_20 ,
V_21 ,
V_5 ,
V_6 , V_7 ) ;
}
int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_6 , int V_7 )
{
return F_1 ( V_2 ,
V_3 , V_4 , V_2 -> V_18 , V_6 , V_7 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_22 , int V_23 )
{
unsigned char V_6 [ 3 ] ;
int V_24 , V_25 ;
struct V_26 * V_27 ;
int V_28 [ 31 ] =
{
0 , 0 , 0 , 0 , 4 ,
5 , 5 , 7 , 7 , 10 ,
10 , 10 , 12 , 12 , 15 ,
15 , 15 , 15 , 20 , 20 ,
20 , 20 , 20 , 24 , 24 ,
24 , 24 , 24 , 24 , 24 ,
24
} ;
int V_29 [ 31 ] =
{ 0 , 0 , 0 , 0 , 0 ,
1 , 1 , 1 , 2 , 2 ,
3 , 3 , 4 , 4 , 4 ,
5 , 5 , 5 , 5 , 5 ,
6 , 6 , 6 , 6 , 7 ,
7 , 7 , 7 , 7 , 7 ,
7
} ;
if ( V_22 < 0 || V_22 > V_30 || V_23 < 4 || V_23 > 25 )
return - V_31 ;
V_23 = V_28 [ V_23 ] ;
V_25 = V_29 [ V_23 ] ;
V_27 = & V_32 [ V_22 ] [ V_25 ] ;
if ( V_27 -> V_33 == 0 )
return - V_31 ;
memcpy ( V_6 , V_27 -> V_34 , 3 ) ;
V_24 = F_9 ( V_2 , V_2 -> V_35 , V_6 , 3 ) ;
if ( V_24 < 0 ) {
F_12 ( L_2 , V_24 ) ;
return V_24 ;
}
if ( V_27 -> V_36 && V_2 -> V_37 == V_38 ) {
V_24 = F_13 ( V_2 , V_2 -> type , V_2 -> V_39 , V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_2 -> V_40 = 3 ;
memcpy ( V_2 -> V_41 , V_6 , 3 ) ;
V_2 -> V_42 = V_23 ;
V_2 -> V_43 = V_22 ;
V_2 -> V_44 = V_27 -> V_33 ;
V_2 -> V_45 = V_46 [ V_22 ] ;
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 3 ) / 2 ;
if ( V_27 -> V_36 ) {
if ( V_2 -> V_39 < 5 ) {
V_2 -> V_50 = 528 ;
V_2 -> V_47 /= 4 ;
}
else {
V_2 -> V_50 = 704 ;
V_2 -> V_47 /= 3 ;
}
}
else
V_2 -> V_50 = 0 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_22 , int V_23 , int V_51 , int V_52 )
{
unsigned char V_6 [ 13 ] ;
const struct V_53 * V_54 ;
int V_24 , V_25 ;
if ( V_22 >= V_55 || V_23 < 5 || V_23 > 30 || V_51 < 0 || V_51 > 3 )
return - V_31 ;
if ( V_22 == V_56 && V_23 > 15 )
return - V_31 ;
V_25 = ( V_23 / 5 ) - 1 ;
V_54 = NULL ;
while ( V_51 <= 3 ) {
V_54 = & V_57 [ V_22 ] [ V_25 ] [ V_51 ] ;
if ( V_54 -> V_33 != 0 )
break;
V_51 ++ ;
}
if ( V_54 == NULL || V_54 -> V_33 == 0 )
return - V_58 ;
memcpy ( V_6 , V_54 -> V_34 , 13 ) ;
if ( V_52 )
V_6 [ 0 ] |= 0x80 ;
V_24 = F_9 ( V_2 , V_2 -> V_35 , V_6 , 13 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_54 -> V_59 > 0 && V_2 -> V_37 == V_38 ) {
V_24 = F_15 ( V_2 , V_2 -> type , V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_2 -> V_40 = 13 ;
memcpy ( V_2 -> V_41 , V_6 , 13 ) ;
V_2 -> V_42 = V_23 ;
V_2 -> V_43 = V_22 ;
V_2 -> V_60 = V_52 ;
V_2 -> V_44 = V_54 -> V_33 ;
V_2 -> V_45 = V_46 [ V_22 ] ;
V_2 -> V_50 = V_54 -> V_59 ;
if ( V_54 -> V_59 > 0 )
V_2 -> V_47 = ( V_54 -> V_59 * V_2 -> V_45 . V_49 ) / 4 ;
else
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 12 ) / 8 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_22 , int V_23 , int V_51 , int V_52 )
{
const struct V_61 * V_54 = NULL ;
int V_25 , V_24 ;
unsigned char V_6 [ 12 ] ;
struct V_61 V_62 = { 6 , 773 , 1272 , { 0xAD , 0xF4 , 0x10 , 0x27 , 0xB6 , 0x24 , 0x96 , 0x02 , 0x30 , 0x05 , 0x03 , 0x80 } } ;
if ( V_22 >= V_55 || V_23 < 5 || V_23 > 30 || V_51 < 0 || V_51 > 3 )
return - V_31 ;
if ( V_22 == V_56 && V_23 > 15 )
return - V_31 ;
V_25 = ( V_23 / 5 ) - 1 ;
if ( V_22 == V_56 && V_23 == 5 && V_52 && V_2 -> V_37 != V_38 )
{
F_17 ( L_3 ) ;
V_54 = & V_62 ;
}
else
{
V_52 = 0 ;
while ( V_51 <= 3 ) {
V_54 = & V_63 [ V_22 ] [ V_25 ] [ V_51 ] ;
if ( V_54 -> V_33 != 0 )
break;
V_51 ++ ;
}
}
if ( V_54 == NULL || V_54 -> V_33 == 0 )
return - V_58 ;
F_18 ( L_4 , V_54 -> V_33 ) ;
memcpy ( V_6 , V_54 -> V_34 , 12 ) ;
if ( V_52 )
V_6 [ 0 ] |= 0x80 ;
V_24 = F_9 ( V_2 , 4 , V_6 , 12 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_54 -> V_59 > 0 && V_2 -> V_37 == V_38 ) {
V_24 = F_15 ( V_2 , V_2 -> type , V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_2 -> V_40 = 12 ;
memcpy ( V_2 -> V_41 , V_6 , 12 ) ;
V_2 -> V_42 = V_23 ;
V_2 -> V_43 = V_22 ;
V_2 -> V_60 = V_52 ;
V_2 -> V_44 = V_54 -> V_33 ;
V_2 -> V_45 = V_46 [ V_22 ] ;
V_2 -> V_50 = V_54 -> V_59 ;
if ( V_2 -> V_50 > 0 )
V_2 -> V_47 = ( V_2 -> V_50 * V_2 -> V_45 . V_49 ) / 4 ;
else
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 12 ) / 8 ;
F_18 ( L_5 ,
V_2 -> V_47 , V_2 -> V_42 , V_2 -> V_43 , V_2 -> V_60 , V_2 -> V_50 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , int V_64 , int V_65 , int V_23 , int V_51 , int V_52 )
{
int V_24 , V_22 ;
F_20 ( L_6 , V_64 , V_65 , V_23 , V_2 -> V_37 ) ;
V_22 = F_21 ( V_2 , V_64 , V_65 ) ;
if ( V_22 < 0 ) {
F_12 ( L_7 ) ;
return - V_66 ;
}
F_18 ( L_8 , V_22 ) ;
if ( F_22 ( V_2 -> type ) ) {
V_24 = F_11 ( V_2 , V_22 , V_23 ) ;
} else if ( F_23 ( V_2 -> type ) ) {
V_24 = F_16 ( V_2 , V_22 , V_23 , V_51 , V_52 ) ;
} else {
V_24 = F_14 ( V_2 , V_22 , V_23 , V_51 , V_52 ) ;
}
if ( V_24 < 0 ) {
F_8 ( L_9 , V_67 [ V_22 ] , V_23 , V_24 ) ;
return V_24 ;
}
V_2 -> V_68 . V_48 = V_64 ;
V_2 -> V_68 . V_49 = V_65 ;
V_2 -> V_69 = V_51 ;
V_2 -> V_70 = V_2 -> V_47 + V_2 -> V_71 + V_2 -> V_72 ;
F_24 ( V_2 ) ;
F_17 ( L_10 , V_64 , V_65 , V_46 [ V_22 ] . V_48 , V_46 [ V_22 ] . V_49 ) ;
return 0 ;
}
static unsigned int F_25 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_22 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
if ( V_32 [ V_22 ] [ V_73 ] . V_33 ) {
if ( V_5 -- == 0 ) return V_75 [ V_73 ] ;
}
}
return 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_22 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_76 ; V_73 ++ ) {
if ( V_63 [ V_22 ] [ V_73 ] [ 3 ] . V_33 ) {
if ( V_5 -- == 0 ) return V_77 [ V_73 ] ;
}
}
return 0 ;
}
static unsigned int F_27 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_22 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ ) {
if ( V_57 [ V_22 ] [ V_73 ] [ 3 ] . V_33 ) {
if ( V_5 -- == 0 ) return V_79 [ V_73 ] ;
}
}
return 0 ;
}
unsigned int F_28 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_22 )
{
unsigned int V_24 ;
if ( F_22 ( V_2 -> type ) ) {
V_24 = F_25 ( V_2 , V_5 , V_22 ) ;
} else if ( F_23 ( V_2 -> type ) ) {
V_24 = F_26 ( V_2 , V_5 , V_22 ) ;
} else {
V_24 = F_27 ( V_2 , V_5 , V_22 ) ;
}
return V_24 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_80 = 0 ;
switch ( V_2 -> V_37 ) {
case V_38 :
V_80 = 6 ;
break;
case V_81 :
case V_82 :
V_80 = 6 ;
break;
}
V_2 -> V_45 . V_22 = V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * V_80 / 4 ;
V_2 -> V_68 . V_22 = V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 * V_80 / 4 ;
V_2 -> V_83 . V_48 = ( ( V_2 -> V_68 . V_48 - V_2 -> V_45 . V_48 ) / 2 ) & 0xFFFC ;
V_2 -> V_83 . V_49 = ( ( V_2 -> V_68 . V_49 - V_2 -> V_45 . V_49 ) / 2 ) & 0xFFFE ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_84 )
{
int V_24 ;
T_1 V_6 ;
V_24 = F_6 ( V_2 , V_3 , V_4 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_84 = V_6 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_1 V_84 )
{
int V_24 ;
V_24 = F_10 ( V_2 , V_3 , V_4 , & V_84 , sizeof( V_84 ) ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_84 )
{
int V_24 ;
T_3 V_6 ;
V_24 = F_6 ( V_2 , V_3 , V_4 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_84 = V_6 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_84 )
{
int V_24 ;
T_1 V_6 [ 2 ] ;
V_24 = F_6 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_84 = ( V_6 [ 1 ] << 8 ) | V_6 [ 0 ] ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_84 )
{
int V_24 ;
T_1 V_6 [ 2 ] ;
V_6 [ 0 ] = V_84 & 0xff ;
V_6 [ 1 ] = V_84 >> 8 ;
V_24 = F_10 ( V_2 , V_3 , V_4 , V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_4 )
{
int V_24 ;
V_24 = F_10 ( V_2 , V_85 , V_4 , NULL , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 , int V_86 )
{
char V_6 ;
int V_87 ;
if ( ! V_2 -> V_88 )
return;
if ( V_2 -> type < 675 || ( V_2 -> type < 730 && V_2 -> V_39 < 6 ) )
return;
if ( V_86 )
V_6 = 0x00 ;
else
V_6 = 0xFF ;
V_87 = F_10 ( V_2 ,
V_85 , V_89 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_87 < 0 )
F_8 ( L_11 ,
V_86 ? L_12 : L_13 , V_87 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_90 )
{
unsigned char V_6 ;
V_6 = V_90 / 0x7f0 ;
return F_10 ( V_2 ,
V_91 , V_92 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_37 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_24 ;
V_24 = F_6 ( V_2 ,
V_93 , V_92 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_4 = V_6 * 0x7f0 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_94 )
{
unsigned char V_6 ;
V_6 = ( V_94 >> 10 ) ;
return F_10 ( V_2 ,
V_91 , V_95 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_39 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_24 ;
V_24 = F_6 ( V_2 ,
V_93 , V_95 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_4 = V_6 << 10 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_96 , int V_97 )
{
unsigned char V_6 [ 2 ] ;
int V_87 ;
if ( V_2 -> type < 730 )
return 0 ;
V_96 /= 100 ;
V_97 /= 100 ;
if ( V_96 < 0 )
V_96 = 0 ;
if ( V_96 > 0xff )
V_96 = 0xff ;
if ( V_97 < 0 )
V_97 = 0 ;
if ( V_97 > 0xff )
V_97 = 0xff ;
V_6 [ 0 ] = V_96 ;
V_6 [ 1 ] = V_97 ;
V_87 = F_10 ( V_2 ,
V_85 , V_98 , & V_6 , sizeof( V_6 ) ) ;
if ( V_87 < 0 )
F_8 ( L_14 , V_87 ) ;
return V_87 ;
}
static int F_41 ( struct V_1 * V_2 , int * V_96 , int * V_97 )
{
unsigned char V_6 [ 2 ] ;
int V_24 ;
if ( V_2 -> type < 730 ) {
* V_96 = - 1 ;
* V_97 = - 1 ;
return 0 ;
}
V_24 = F_6 ( V_2 ,
V_99 , V_98 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
* V_96 = V_6 [ 0 ] * 100 ;
* V_97 = V_6 [ 1 ] * 100 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_100 )
{
unsigned char V_6 ;
V_6 = V_100 & 0x03 ;
return F_10 ( V_2 ,
V_101 , V_102 , & V_6 , sizeof( V_6 ) ) ;
}
int F_43 ( struct V_1 * V_2 , int V_100 )
{
int V_24 ;
V_24 = F_42 ( V_2 , V_100 ) ;
if ( V_24 >= 0 ) {
V_2 -> V_103 = 0 ;
V_2 -> V_104 = 0 ;
}
return V_24 ;
}
static int F_44 ( struct V_1 * V_2 , int V_105 , int V_106 )
{
unsigned char V_6 [ 4 ] ;
V_105 = 64 * V_105 / 100 ;
V_106 = - 64 * V_106 / 100 ;
V_6 [ 0 ] = V_105 & 0xFF ;
V_6 [ 1 ] = ( V_105 >> 8 ) & 0xFF ;
V_6 [ 2 ] = V_106 & 0xFF ;
V_6 [ 3 ] = ( V_106 >> 8 ) & 0xFF ;
return F_10 ( V_2 ,
V_101 , V_107 , & V_6 , sizeof( V_6 ) ) ;
}
int F_45 ( struct V_1 * V_2 , int V_105 , int V_106 )
{
int V_24 ;
if ( V_105 < V_2 -> V_108 . V_109 ||
V_105 > V_2 -> V_108 . V_110 ||
V_106 < V_2 -> V_108 . V_111 ||
V_106 > V_2 -> V_108 . V_112 )
return - V_66 ;
V_105 -= V_2 -> V_103 ;
V_106 -= V_2 -> V_104 ;
if ( V_105 < - 36000 || V_105 > 36000 || V_106 < - 36000 || V_106 > 36000 )
return - V_66 ;
V_24 = F_44 ( V_2 , V_105 , V_106 ) ;
if ( V_24 >= 0 ) {
V_2 -> V_103 += V_105 ;
V_2 -> V_104 += V_106 ;
}
if ( V_24 == - V_113 )
V_24 = - V_66 ;
return V_24 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
int V_24 ;
unsigned char V_6 [ 5 ] ;
V_24 = F_6 ( V_2 ,
V_116 , V_117 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
V_115 -> V_115 = V_6 [ 0 ] & 0x7 ;
V_115 -> V_118 = ( V_6 [ 1 ] << 8 ) + V_6 [ 2 ] ;
V_115 -> V_119 = ( V_6 [ 3 ] << 8 ) + V_6 [ 4 ] ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int * V_120 )
{
unsigned char V_6 ;
int V_24 = - 1 , V_3 ;
if ( V_2 -> type < 675 )
V_3 = V_121 ;
else if ( V_2 -> type < 730 )
return - 1 ;
else
V_3 = V_122 ;
V_24 = F_6 ( V_2 ,
V_99 , V_3 , & V_6 , sizeof( V_6 ) ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_2 -> type < 675 )
* V_120 = V_6 | 0x100 ;
else
* V_120 = V_6 ;
return 0 ;
}
static int F_48 ( struct V_123 * V_124 )
{
return F_49 ( V_124 ) * 65535 / V_124 -> V_125 ;
}
static int F_50 ( struct V_123 * V_124 , int V_126 )
{
return F_51 ( V_124 , V_126 * V_124 -> V_125 / 65535 ) ;
}
long F_52 ( struct V_1 * V_2 , unsigned int V_127 , void * V_128 )
{
long V_24 = 0 ;
switch( V_127 ) {
case V_129 :
V_24 = F_34 ( V_2 , V_130 ) ;
break;
case V_131 :
V_24 = F_34 ( V_2 , V_132 ) ;
break;
case V_133 :
V_24 = F_34 ( V_2 , V_134 ) ;
break;
case V_135 :
{
F_53 (int, qual)
if ( F_54 ( & V_2 -> V_136 ) ) {
V_24 = - V_137 ;
break;
}
F_55 (qual)
if ( F_56 ( V_138 ) < 0 || F_56 ( V_138 ) > 3 )
V_24 = - V_31 ;
else
V_24 = F_19 ( V_2 , V_2 -> V_68 . V_48 , V_2 -> V_68 . V_49 , V_2 -> V_42 , F_56 ( V_138 ) , V_2 -> V_60 ) ;
break;
}
case V_139 :
{
F_53 (int, qual)
F_56 ( V_138 ) = V_2 -> V_69 ;
F_57 (qual)
break;
}
case V_140 :
{
F_53 (struct pwc_probe, probe)
strcpy ( F_56 ( V_141 ) . V_142 , V_2 -> V_143 . V_142 ) ;
F_56 ( V_141 ) . type = V_2 -> type ;
F_57 (probe)
break;
}
case V_144 :
{
F_53 (struct pwc_serial, serial)
strcpy ( F_56 ( V_145 ) . V_145 , V_2 -> V_145 ) ;
F_57 (serial)
break;
}
case V_146 :
{
F_53 (int, agc)
F_55 (agc)
V_24 = F_51 ( V_2 -> V_147 , F_56 ( V_148 ) < 0 ) ;
if ( V_24 == 0 && F_56 ( V_148 ) >= 0 )
V_24 = F_50 ( V_2 -> V_149 , F_56 ( V_148 ) ) ;
break;
}
case V_150 :
{
F_53 (int, agc)
if ( F_49 ( V_2 -> V_147 ) )
F_56 ( V_148 ) = - 1 ;
else
F_56 ( V_148 ) = F_48 ( V_2 -> V_149 ) ;
F_57 (agc)
break;
}
case V_151 :
{
F_53 (int, shutter)
F_55 (shutter)
V_24 = F_51 ( V_2 -> V_152 ,
F_56 ( V_153 ) >= 0 ) ;
if ( V_24 == 0 && F_56 ( V_153 ) >= 0 )
V_24 = F_50 ( V_2 -> V_154 , F_56 ( V_153 ) ) ;
break;
}
case V_155 :
{
F_53 (struct pwc_whitebalance, wb)
F_55 (wb)
V_24 = F_51 ( V_2 -> V_156 ,
F_56 ( V_157 ) . V_34 ) ;
if ( V_24 == 0 && F_56 ( V_157 ) . V_34 == V_158 )
V_24 = F_50 ( V_2 -> V_159 ,
F_56 ( V_157 ) . V_160 ) ;
if ( V_24 == 0 && F_56 ( V_157 ) . V_34 == V_158 )
V_24 = F_50 ( V_2 -> V_161 ,
F_56 ( V_157 ) . V_162 ) ;
break;
}
case V_163 :
{
F_53 (struct pwc_whitebalance, wb)
F_56 ( V_157 ) . V_34 = F_49 ( V_2 -> V_156 ) ;
F_56 ( V_157 ) . V_160 = F_56 ( V_157 ) . V_164 =
F_48 ( V_2 -> V_159 ) ;
F_56 ( V_157 ) . V_162 = F_56 ( V_157 ) . V_165 =
F_48 ( V_2 -> V_161 ) ;
F_57 (wb)
break;
}
case V_166 :
{
F_53 (struct pwc_wb_speed, wbs)
if ( F_56 ( V_167 ) . V_168 > 0 ) {
V_24 = F_36 ( V_2 , F_56 ( V_167 ) . V_168 ) ;
}
if ( F_56 ( V_167 ) . V_169 > 0 ) {
V_24 = F_38 ( V_2 , F_56 ( V_167 ) . V_169 ) ;
}
break;
}
case V_170 :
{
F_53 (struct pwc_wb_speed, wbs)
V_24 = F_37 ( V_2 , & F_56 ( V_167 ) . V_168 ) ;
if ( V_24 < 0 )
break;
V_24 = F_39 ( V_2 , & F_56 ( V_167 ) . V_169 ) ;
if ( V_24 < 0 )
break;
F_57 (wbs)
break;
}
case V_171 :
{
F_53 (struct pwc_leds, leds)
F_55 (leds)
V_24 = F_40 ( V_2 , F_56 ( V_172 ) . V_173 , F_56 ( V_172 ) . V_174 ) ;
break;
}
case V_175 :
{
F_53 (struct pwc_leds, leds)
V_24 = F_41 ( V_2 , & F_56 ( V_172 ) . V_173 , & F_56 ( V_172 ) . V_174 ) ;
F_57 (leds)
break;
}
case V_176 :
{
F_53 (int, contour)
F_55 (contour)
V_24 = F_51 ( V_2 -> V_177 , F_56 ( V_178 ) < 0 ) ;
if ( V_24 == 0 && F_56 ( V_178 ) >= 0 )
V_24 = F_50 ( V_2 -> V_178 , F_56 ( V_178 ) ) ;
break;
}
case V_179 :
{
F_53 (int, contour)
if ( F_49 ( V_2 -> V_177 ) )
F_56 ( V_178 ) = - 1 ;
else
F_56 ( V_178 ) = F_48 ( V_2 -> V_178 ) ;
F_57 (contour)
break;
}
case V_180 :
{
F_53 (int, backlight)
F_55 (backlight)
V_24 = F_51 ( V_2 -> V_181 , F_56 ( V_181 ) ) ;
break;
}
case V_182 :
{
F_53 (int, backlight)
F_56 ( V_181 ) = F_49 ( V_2 -> V_181 ) ;
F_57 (backlight)
break;
}
case V_183 :
{
F_53 (int, flicker)
F_55 (flicker)
V_24 = F_51 ( V_2 -> V_184 , F_56 ( V_184 ) ) ;
break;
}
case V_185 :
{
F_53 (int, flicker)
F_56 ( V_184 ) = F_49 ( V_2 -> V_184 ) ;
F_57 (flicker)
break;
}
case V_186 :
{
F_53 (int, dynnoise)
F_55 (dynnoise)
V_24 = F_51 ( V_2 -> V_187 , F_56 ( V_188 ) ) ;
break;
}
case V_189 :
{
F_53 (int, dynnoise)
F_56 ( V_188 ) = F_49 ( V_2 -> V_187 ) ;
F_57 ( V_188 ) ;
break;
}
case V_190 :
{
F_53 (struct pwc_imagesize, size)
F_56 ( V_22 ) . V_64 = V_2 -> V_45 . V_48 ;
F_56 ( V_22 ) . V_65 = V_2 -> V_45 . V_49 ;
F_57 (size)
break;
}
case V_191 :
{
if ( V_2 -> V_192 & V_193 )
{
F_53 (int, flags)
F_55 (flags)
V_24 = F_43 ( V_2 , F_56 ( V_100 ) ) ;
}
else
{
V_24 = - V_194 ;
}
break;
}
case V_195 :
{
if ( V_2 -> V_192 & V_193 )
{
F_53 (struct pwc_mpt_range, range)
F_56 ( V_196 ) = V_2 -> V_108 ;
F_57 (range)
}
else
{
V_24 = - V_194 ;
}
break;
}
case V_197 :
{
int V_198 , V_199 ;
if ( V_2 -> V_192 & V_193 )
{
F_53 (struct pwc_mpt_angles, angles)
F_55 (angles)
if ( F_56 ( V_200 ) . V_201 )
{
V_198 = F_56 ( V_200 ) . V_105 ;
V_199 = F_56 ( V_200 ) . V_106 ;
}
else
{
V_198 = V_2 -> V_103 + F_56 ( V_200 ) . V_105 ;
V_199 = V_2 -> V_104 + F_56 ( V_200 ) . V_106 ;
}
V_24 = F_45 ( V_2 , V_198 , V_199 ) ;
}
else
{
V_24 = - V_194 ;
}
break;
}
case V_202 :
{
if ( V_2 -> V_192 & V_193 )
{
F_53 (struct pwc_mpt_angles, angles)
F_56 ( V_200 ) . V_201 = 1 ;
F_56 ( V_200 ) . V_105 = V_2 -> V_103 ;
F_56 ( V_200 ) . V_106 = V_2 -> V_104 ;
F_57 (angles)
}
else
{
V_24 = - V_194 ;
}
break;
}
case V_203 :
{
if ( V_2 -> V_192 & V_193 )
{
F_53 (struct pwc_mpt_status, status)
V_24 = F_46 ( V_2 , F_58 ( V_115 ) ) ;
F_57 (status)
}
else
{
V_24 = - V_194 ;
}
break;
}
case V_204 :
{
F_53 ( struct V_205 , V_206 ) ;
F_56 ( V_206 ) . type = V_2 -> type ;
F_56 ( V_206 ) . V_39 = V_2 -> V_39 ;
F_56 ( V_206 ) . V_207 = V_2 -> V_40 ;
memcpy ( & F_56 ( V_206 ) . V_208 , V_2 -> V_41 , V_2 -> V_40 ) ;
F_56 ( V_206 ) . V_59 = V_2 -> V_50 ;
F_56 ( V_206 ) . V_47 = V_2 -> V_47 ;
F_57 (vcmd)
break;
}
default:
V_24 = - V_209 ;
break;
}
if ( V_24 > 0 )
return 0 ;
return V_24 ;
}
