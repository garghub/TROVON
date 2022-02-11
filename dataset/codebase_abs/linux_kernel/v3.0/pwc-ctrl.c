static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , int V_5 , void * V_6 , int V_7 , int V_8 )
{
int V_9 ;
void * V_10 = NULL ;
if ( V_7 ) {
V_10 = F_2 ( V_7 , V_11 ) ;
if ( V_10 == NULL )
return - V_12 ;
memcpy ( V_10 , V_6 , V_7 ) ;
}
V_9 = F_3 ( V_2 -> V_13 , F_4 ( V_2 -> V_13 , 0 ) ,
V_3 ,
V_14 | V_15 | V_16 ,
V_4 ,
V_5 ,
V_10 , V_7 , V_8 ) ;
F_5 ( V_10 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_6 , int V_7 )
{
int V_9 ;
void * V_10 = F_2 ( V_7 , V_11 ) ;
if ( V_10 == NULL )
return - V_12 ;
V_9 = F_3 ( V_2 -> V_13 , F_7 ( V_2 -> V_13 , 0 ) ,
V_3 ,
V_17 | V_15 | V_16 ,
V_4 ,
V_2 -> V_18 ,
V_10 , V_7 , 500 ) ;
memcpy ( V_6 , V_10 , V_7 ) ;
F_5 ( V_10 ) ;
return V_9 ;
}
static inline int F_8 ( struct V_1 * V_2 ,
int V_5 , void * V_6 , int V_7 )
{
return F_1 ( V_2 ,
V_19 ,
V_20 ,
V_5 ,
V_6 , V_7 , 1000 ) ;
}
static inline int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_6 , int V_7 )
{
return F_1 ( V_2 ,
V_3 , V_4 , V_2 -> V_18 , V_6 , V_7 , 500 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_21 , int V_22 )
{
unsigned char V_6 [ 3 ] ;
int V_23 , V_24 ;
struct V_25 * V_26 ;
int V_27 [ 31 ] =
{
0 , 0 , 0 , 0 , 4 ,
5 , 5 , 7 , 7 , 10 ,
10 , 10 , 12 , 12 , 15 ,
15 , 15 , 15 , 20 , 20 ,
20 , 20 , 20 , 24 , 24 ,
24 , 24 , 24 , 24 , 24 ,
24
} ;
int V_28 [ 31 ] =
{ 0 , 0 , 0 , 0 , 0 ,
1 , 1 , 1 , 2 , 2 ,
3 , 3 , 4 , 4 , 4 ,
5 , 5 , 5 , 5 , 5 ,
6 , 6 , 6 , 6 , 7 ,
7 , 7 , 7 , 7 , 7 ,
7
} ;
if ( V_21 < 0 || V_21 > V_29 || V_22 < 4 || V_22 > 25 )
return - V_30 ;
V_22 = V_27 [ V_22 ] ;
V_24 = V_28 [ V_22 ] ;
V_26 = & V_31 [ V_21 ] [ V_24 ] ;
if ( V_26 -> V_32 == 0 )
return - V_30 ;
memcpy ( V_6 , V_26 -> V_33 , 3 ) ;
V_23 = F_8 ( V_2 , V_2 -> V_34 , V_6 , 3 ) ;
if ( V_23 < 0 ) {
F_11 ( L_1 , V_23 ) ;
return V_23 ;
}
if ( V_26 -> V_35 && V_2 -> V_36 == V_37 )
F_12 ( V_2 -> type , V_2 -> V_38 , V_6 , V_2 -> V_39 ) ;
V_2 -> V_40 = 3 ;
memcpy ( V_2 -> V_41 , V_6 , 3 ) ;
V_2 -> V_42 = V_22 ;
V_2 -> V_43 = V_21 ;
V_2 -> V_44 = V_26 -> V_32 ;
V_2 -> V_45 = V_46 [ V_21 ] ;
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 3 ) / 2 ;
if ( V_26 -> V_35 ) {
if ( V_2 -> V_38 < 5 ) {
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
static int F_13 ( struct V_1 * V_2 , int V_21 , int V_22 , int V_51 , int V_52 )
{
unsigned char V_6 [ 13 ] ;
const struct V_53 * V_54 ;
int V_23 , V_24 ;
if ( V_21 >= V_55 || V_22 < 5 || V_22 > 30 || V_51 < 0 || V_51 > 3 )
return - V_30 ;
if ( V_21 == V_56 && V_22 > 15 )
return - V_30 ;
V_24 = ( V_22 / 5 ) - 1 ;
V_54 = NULL ;
while ( V_51 <= 3 ) {
V_54 = & V_57 [ V_21 ] [ V_24 ] [ V_51 ] ;
if ( V_54 -> V_32 != 0 )
break;
V_51 ++ ;
}
if ( V_54 == NULL || V_54 -> V_32 == 0 )
return - V_58 ;
memcpy ( V_6 , V_54 -> V_33 , 13 ) ;
if ( V_52 )
V_6 [ 0 ] |= 0x80 ;
V_23 = F_8 ( V_2 , V_2 -> V_34 , V_6 , 13 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_54 -> V_59 > 0 && V_2 -> V_36 == V_37 )
F_14 ( V_2 , V_2 -> type , V_6 ) ;
V_2 -> V_40 = 13 ;
memcpy ( V_2 -> V_41 , V_6 , 13 ) ;
V_2 -> V_42 = V_22 ;
V_2 -> V_43 = V_21 ;
V_2 -> V_60 = V_52 ;
V_2 -> V_44 = V_54 -> V_32 ;
V_2 -> V_45 = V_46 [ V_21 ] ;
V_2 -> V_50 = V_54 -> V_59 ;
if ( V_54 -> V_59 > 0 )
V_2 -> V_47 = ( V_54 -> V_59 * V_2 -> V_45 . V_49 ) / 4 ;
else
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 12 ) / 8 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_21 , int V_22 , int V_51 , int V_52 )
{
const struct V_61 * V_54 = NULL ;
int V_24 , V_23 ;
unsigned char V_6 [ 12 ] ;
struct V_61 V_62 = { 6 , 773 , 1272 , { 0xAD , 0xF4 , 0x10 , 0x27 , 0xB6 , 0x24 , 0x96 , 0x02 , 0x30 , 0x05 , 0x03 , 0x80 } } ;
if ( V_21 >= V_55 || V_22 < 5 || V_22 > 30 || V_51 < 0 || V_51 > 3 )
return - V_30 ;
if ( V_21 == V_56 && V_22 > 15 )
return - V_30 ;
V_24 = ( V_22 / 5 ) - 1 ;
if ( V_21 == V_56 && V_22 == 5 && V_52 && V_2 -> V_36 != V_37 )
{
F_16 ( L_2 ) ;
V_54 = & V_62 ;
}
else
{
V_52 = 0 ;
while ( V_51 <= 3 ) {
V_54 = & V_63 [ V_21 ] [ V_24 ] [ V_51 ] ;
if ( V_54 -> V_32 != 0 )
break;
V_51 ++ ;
}
}
if ( V_54 == NULL || V_54 -> V_32 == 0 )
return - V_58 ;
F_17 ( L_3 , V_54 -> V_32 ) ;
memcpy ( V_6 , V_54 -> V_33 , 12 ) ;
if ( V_52 )
V_6 [ 0 ] |= 0x80 ;
V_23 = F_8 ( V_2 , 4 , V_6 , 12 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_54 -> V_59 > 0 && V_2 -> V_36 == V_37 )
F_14 ( V_2 , V_2 -> type , V_6 ) ;
V_2 -> V_40 = 12 ;
memcpy ( V_2 -> V_41 , V_6 , 12 ) ;
V_2 -> V_42 = V_22 ;
V_2 -> V_43 = V_21 ;
V_2 -> V_60 = V_52 ;
V_2 -> V_44 = V_54 -> V_32 ;
V_2 -> V_45 = V_46 [ V_21 ] ;
V_2 -> V_50 = V_54 -> V_59 ;
if ( V_2 -> V_50 > 0 )
V_2 -> V_47 = ( V_2 -> V_50 * V_2 -> V_45 . V_49 ) / 4 ;
else
V_2 -> V_47 = ( V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * 12 ) / 8 ;
F_17 ( L_4 ,
V_2 -> V_47 , V_2 -> V_42 , V_2 -> V_43 , V_2 -> V_60 , V_2 -> V_50 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , int V_64 , int V_65 , int V_22 , int V_51 , int V_52 )
{
int V_23 , V_21 ;
F_19 ( L_5 , V_64 , V_65 , V_22 , V_2 -> V_36 ) ;
V_21 = F_20 ( V_2 , V_64 , V_65 ) ;
if ( V_21 < 0 ) {
F_11 ( L_6 ) ;
return - V_66 ;
}
F_17 ( L_7 , V_21 ) ;
if ( F_21 ( V_2 -> type ) ) {
V_23 = F_10 ( V_2 , V_21 , V_22 ) ;
} else if ( F_22 ( V_2 -> type ) ) {
V_23 = F_15 ( V_2 , V_21 , V_22 , V_51 , V_52 ) ;
} else {
V_23 = F_13 ( V_2 , V_21 , V_22 , V_51 , V_52 ) ;
}
if ( V_23 < 0 ) {
F_23 ( L_8 , V_67 [ V_21 ] , V_22 , V_23 ) ;
return V_23 ;
}
V_2 -> V_68 . V_48 = V_64 ;
V_2 -> V_68 . V_49 = V_65 ;
V_2 -> V_69 = V_2 -> V_47 + V_2 -> V_70 + V_2 -> V_71 ;
F_24 ( V_2 ) ;
F_16 ( L_9 , V_64 , V_65 , V_46 [ V_21 ] . V_48 , V_46 [ V_21 ] . V_49 ) ;
return 0 ;
}
static unsigned int F_25 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_21 )
{
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( V_31 [ V_21 ] [ V_72 ] . V_32 ) {
if ( V_5 -- == 0 ) return V_74 [ V_72 ] ;
}
}
return 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_21 )
{
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < V_75 ; V_72 ++ ) {
if ( V_63 [ V_21 ] [ V_72 ] [ 3 ] . V_32 ) {
if ( V_5 -- == 0 ) return V_76 [ V_72 ] ;
}
}
return 0 ;
}
static unsigned int F_27 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_21 )
{
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < V_77 ; V_72 ++ ) {
if ( V_57 [ V_21 ] [ V_72 ] [ 3 ] . V_32 ) {
if ( V_5 -- == 0 ) return V_78 [ V_72 ] ;
}
}
return 0 ;
}
unsigned int F_28 ( struct V_1 * V_2 , unsigned int V_5 , unsigned int V_21 )
{
unsigned int V_23 ;
if ( F_21 ( V_2 -> type ) ) {
V_23 = F_25 ( V_2 , V_5 , V_21 ) ;
} else if ( F_22 ( V_2 -> type ) ) {
V_23 = F_26 ( V_2 , V_5 , V_21 ) ;
} else {
V_23 = F_27 ( V_2 , V_5 , V_21 ) ;
}
return V_23 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_72 , V_79 = 0 ;
switch ( V_2 -> V_36 ) {
case V_37 :
V_79 = 6 ;
break;
case V_80 :
case V_81 :
V_79 = 6 ;
break;
}
V_2 -> V_45 . V_21 = V_2 -> V_45 . V_48 * V_2 -> V_45 . V_49 * V_79 / 4 ;
V_2 -> V_68 . V_21 = V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 * V_79 / 4 ;
V_2 -> V_82 . V_48 = ( ( V_2 -> V_68 . V_48 - V_2 -> V_45 . V_48 ) / 2 ) & 0xFFFC ;
V_2 -> V_82 . V_49 = ( ( V_2 -> V_68 . V_49 - V_2 -> V_45 . V_49 ) / 2 ) & 0xFFFE ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
unsigned char * V_84 = V_2 -> V_85 + V_2 -> V_86 [ V_72 ] . V_82 ;
memset ( V_84 , V_87 , V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 ) ;
V_84 += V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 ;
memset ( V_84 , V_88 , V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 / 4 ) ;
V_84 += V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 / 4 ;
memset ( V_84 , V_89 , V_2 -> V_68 . V_48 * V_2 -> V_68 . V_49 / 4 ) ;
}
}
int F_29 ( struct V_1 * V_2 )
{
char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_90 , V_91 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return V_6 ;
}
int F_30 ( struct V_1 * V_2 , int V_4 )
{
char V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = ( V_4 >> 9 ) & 0x7f ;
return F_9 ( V_2 ,
V_92 , V_91 , & V_6 , sizeof( V_6 ) ) ;
}
int F_31 ( struct V_1 * V_2 )
{
char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_90 , V_93 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return V_6 ;
}
int F_32 ( struct V_1 * V_2 , int V_4 )
{
char V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = ( V_4 >> 10 ) & 0x3f ;
return F_9 ( V_2 ,
V_92 , V_93 , & V_6 , sizeof( V_6 ) ) ;
}
int F_33 ( struct V_1 * V_2 )
{
char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_90 , V_94 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return V_6 ;
}
int F_34 ( struct V_1 * V_2 , int V_4 )
{
char V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = ( V_4 >> 11 ) & 0x1f ;
return F_9 ( V_2 ,
V_92 , V_94 , & V_6 , sizeof( V_6 ) ) ;
}
int F_35 ( struct V_1 * V_2 , int * V_4 )
{
char V_6 ;
int V_23 , V_95 ;
if ( V_2 -> type < 675 )
return - V_30 ;
if ( V_2 -> type < 730 )
V_95 = V_96 ;
else
V_95 = V_97 ;
V_23 = F_6 ( V_2 ,
V_98 , V_95 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = ( signed ) V_6 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , int V_4 )
{
char V_6 ;
int V_95 ;
if ( V_2 -> type < 675 )
return - V_30 ;
if ( V_4 < - 100 )
V_4 = - 100 ;
if ( V_4 > 100 )
V_4 = 100 ;
if ( V_2 -> type < 730 )
V_95 = V_96 ;
else
V_95 = V_97 ;
return F_9 ( V_2 ,
V_99 , V_95 , & V_6 , sizeof( V_6 ) ) ;
}
int F_37 ( struct V_1 * V_2 , int V_33 , int V_4 )
{
char V_6 ;
int V_23 ;
if ( V_33 )
V_6 = 0x0 ;
else
V_6 = 0xff ;
V_23 = F_9 ( V_2 ,
V_92 , V_100 , & V_6 , sizeof( V_6 ) ) ;
if ( ! V_33 && V_23 >= 0 ) {
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = ( V_4 >> 10 ) & 0x3F ;
V_23 = F_9 ( V_2 ,
V_92 , V_101 , & V_6 , sizeof( V_6 ) ) ;
}
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_90 , V_100 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_6 != 0 ) {
V_23 = F_6 ( V_2 ,
V_90 , V_101 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_6 > 0x3F )
V_6 = 0x3F ;
* V_4 = ( V_6 << 10 ) ;
}
else {
V_23 = F_6 ( V_2 ,
V_102 , V_103 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_6 > 0x9F )
V_6 = 0x9F ;
* V_4 = - ( 48 + V_6 * 409 ) ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 , int V_33 , int V_4 )
{
char V_6 [ 2 ] ;
int V_104 , V_23 ;
if ( V_33 )
V_6 [ 0 ] = 0x0 ;
else
V_6 [ 0 ] = 0xff ;
V_23 = F_9 ( V_2 ,
V_92 , V_105 , & V_6 , 1 ) ;
if ( ! V_33 && V_23 >= 0 ) {
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
if ( F_40 ( V_2 -> type ) ) {
V_104 = ( V_4 / 100 ) ;
V_6 [ 1 ] = V_104 >> 8 ;
V_6 [ 0 ] = V_104 & 0xff ;
} else if ( F_22 ( V_2 -> type ) ) {
V_6 [ 1 ] = 0 ;
V_6 [ 0 ] = V_4 >> 8 ;
}
V_23 = F_9 ( V_2 ,
V_92 , V_106 ,
& V_6 , sizeof( V_6 ) ) ;
}
return V_23 ;
}
int F_41 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 [ 2 ] ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_102 , V_107 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 [ 0 ] + ( V_6 [ 1 ] << 8 ) ;
if ( F_40 ( V_2 -> type ) ) {
* V_4 *= 256 / 656 ;
} else if ( F_22 ( V_2 -> type ) ) {
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 , int V_108 )
{
char V_6 ;
if ( V_2 -> type < 675 || ( V_2 -> type < 730 && V_2 -> V_38 < 6 ) )
return 0 ;
if ( V_108 )
V_6 = 0x00 ;
else
V_6 = 0xFF ;
return F_9 ( V_2 ,
V_109 , V_110 ,
& V_6 , sizeof( V_6 ) ) ;
}
int F_43 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ,
V_109 , V_111 , NULL , 0 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ,
V_109 , V_112 , NULL , 0 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ,
V_109 , V_113 , NULL , 0 ) ;
}
int F_46 ( struct V_1 * V_2 , int V_33 )
{
char V_6 ;
int V_23 ;
if ( V_33 < 0 )
V_33 = 0 ;
if ( V_33 > 4 )
V_33 = 4 ;
V_6 = V_33 & 0x07 ;
V_23 = F_9 ( V_2 ,
V_99 , V_114 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_98 , V_114 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return V_6 ;
}
int F_48 ( struct V_1 * V_2 , int V_4 )
{
unsigned char V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = V_4 >> 8 ;
return F_9 ( V_2 ,
V_99 , V_115 ,
& V_6 , sizeof( V_6 ) ) ;
}
int F_49 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_98 , V_115 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 << 8 ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , int V_4 )
{
unsigned char V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
V_6 = V_4 >> 8 ;
return F_9 ( V_2 ,
V_99 , V_116 ,
& V_6 , sizeof( V_6 ) ) ;
}
int F_51 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_98 , V_116 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 << 8 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_102 , V_117 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 << 8 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_102 , V_118 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 << 8 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int V_104 )
{
unsigned char V_6 ;
V_6 = V_104 / 0x7f0 ;
return F_9 ( V_2 ,
V_99 , V_119 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_55 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_98 , V_119 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 * 0x7f0 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_120 )
{
unsigned char V_6 ;
V_6 = ( V_120 >> 10 ) ;
return F_9 ( V_2 ,
V_99 , V_121 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_57 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_98 , V_121 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_4 = V_6 << 10 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , int V_122 , int V_123 )
{
unsigned char V_6 [ 2 ] ;
if ( V_2 -> type < 730 )
return 0 ;
V_122 /= 100 ;
V_123 /= 100 ;
if ( V_122 < 0 )
V_122 = 0 ;
if ( V_122 > 0xff )
V_122 = 0xff ;
if ( V_123 < 0 )
V_123 = 0 ;
if ( V_123 > 0xff )
V_123 = 0xff ;
V_6 [ 0 ] = V_122 ;
V_6 [ 1 ] = V_123 ;
return F_9 ( V_2 ,
V_109 , V_124 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_59 ( struct V_1 * V_2 , int * V_122 , int * V_123 )
{
unsigned char V_6 [ 2 ] ;
int V_23 ;
if ( V_2 -> type < 730 ) {
* V_122 = - 1 ;
* V_123 = - 1 ;
return 0 ;
}
V_23 = F_6 ( V_2 ,
V_102 , V_124 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_122 = V_6 [ 0 ] * 100 ;
* V_123 = V_6 [ 1 ] * 100 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , int V_125 )
{
unsigned char V_6 ;
int V_23 ;
if ( V_125 < 0 )
V_6 = 0xff ;
else
V_6 = 0x0 ;
V_23 = F_9 ( V_2 ,
V_92 , V_126 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_125 < 0 )
return 0 ;
if ( V_125 > 0xffff )
V_125 = 0xffff ;
V_6 = ( V_125 >> 10 ) ;
V_23 = F_9 ( V_2 ,
V_92 , V_127 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , int * V_125 )
{
unsigned char V_6 ;
int V_23 ;
V_23 = F_6 ( V_2 ,
V_90 , V_126 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_6 == 0 ) {
V_23 = F_6 ( V_2 ,
V_90 , V_127 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_125 = V_6 << 10 ;
}
else
* V_125 = - 1 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 , int V_128 )
{
unsigned char V_6 ;
if ( V_128 )
V_6 = 0xff ;
else
V_6 = 0x0 ;
return F_9 ( V_2 ,
V_92 , V_129 ,
& V_6 , sizeof( V_6 ) ) ;
}
int F_63 ( struct V_1 * V_2 , int * V_128 )
{
int V_23 ;
unsigned char V_6 ;
V_23 = F_6 ( V_2 ,
V_90 , V_129 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_128 = ! ! V_6 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , int V_130 )
{
unsigned char V_6 ;
if ( V_130 )
V_6 = 0xff ;
else
V_6 = 0x0 ;
return F_9 ( V_2 ,
V_99 , V_131 , & V_6 , sizeof( V_6 ) ) ;
}
int F_65 ( struct V_1 * V_2 , int * V_130 )
{
int V_23 ;
unsigned char V_6 ;
V_23 = F_6 ( V_2 ,
V_98 , V_131 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_130 = ! ! V_6 ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , int V_132 )
{
unsigned char V_6 ;
if ( V_132 )
V_6 = 0xff ;
else
V_6 = 0x0 ;
return F_9 ( V_2 ,
V_92 , V_133 , & V_6 , sizeof( V_6 ) ) ;
}
int F_67 ( struct V_1 * V_2 , int * V_132 )
{
int V_23 ;
unsigned char V_6 ;
V_23 = F_6 ( V_2 ,
V_90 , V_133 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_132 = ! ! V_6 ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , int V_134 )
{
unsigned char V_6 ;
if ( V_134 < 0 )
V_134 = 0 ;
if ( V_134 > 3 )
V_134 = 3 ;
V_6 = V_134 ;
return F_9 ( V_2 ,
V_92 , V_135 ,
& V_6 , sizeof( V_6 ) ) ;
}
int F_69 ( struct V_1 * V_2 , int * V_134 )
{
int V_23 ;
unsigned char V_6 ;
V_23 = F_6 ( V_2 ,
V_90 , V_135 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
* V_134 = V_6 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int V_136 )
{
unsigned char V_6 ;
V_6 = V_136 & 0x03 ;
return F_9 ( V_2 ,
V_137 , V_138 , & V_6 , sizeof( V_6 ) ) ;
}
int F_71 ( struct V_1 * V_2 , int V_136 )
{
int V_23 ;
V_23 = F_70 ( V_2 , V_136 ) ;
if ( V_23 >= 0 ) {
V_2 -> V_139 = 0 ;
V_2 -> V_140 = 0 ;
}
return V_23 ;
}
static int F_72 ( struct V_1 * V_2 , int V_141 , int V_142 )
{
unsigned char V_6 [ 4 ] ;
V_141 = 64 * V_141 / 100 ;
V_142 = - 64 * V_142 / 100 ;
V_6 [ 0 ] = V_141 & 0xFF ;
V_6 [ 1 ] = ( V_141 >> 8 ) & 0xFF ;
V_6 [ 2 ] = V_142 & 0xFF ;
V_6 [ 3 ] = ( V_142 >> 8 ) & 0xFF ;
return F_9 ( V_2 ,
V_137 , V_143 , & V_6 , sizeof( V_6 ) ) ;
}
int F_73 ( struct V_1 * V_2 , int V_141 , int V_142 )
{
int V_23 ;
if ( V_141 < V_2 -> V_144 . V_145 ||
V_141 > V_2 -> V_144 . V_146 ||
V_142 < V_2 -> V_144 . V_147 ||
V_142 > V_2 -> V_144 . V_148 )
return - V_66 ;
V_141 -= V_2 -> V_139 ;
V_142 -= V_2 -> V_140 ;
if ( V_141 < - 36000 || V_141 > 36000 || V_142 < - 36000 || V_142 > 36000 )
return - V_66 ;
V_23 = F_72 ( V_2 , V_141 , V_142 ) ;
if ( V_23 >= 0 ) {
V_2 -> V_139 += V_141 ;
V_2 -> V_140 += V_142 ;
}
if ( V_23 == - V_149 )
V_23 = - V_66 ;
return V_23 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
int V_23 ;
unsigned char V_6 [ 5 ] ;
V_23 = F_6 ( V_2 ,
V_152 , V_153 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_151 -> V_151 = V_6 [ 0 ] & 0x7 ;
V_151 -> V_154 = ( V_6 [ 1 ] << 8 ) + V_6 [ 2 ] ;
V_151 -> V_155 = ( V_6 [ 3 ] << 8 ) + V_6 [ 4 ] ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , int * V_156 )
{
unsigned char V_6 ;
int V_23 = - 1 , V_3 ;
if ( V_2 -> type < 675 )
V_3 = V_157 ;
else if ( V_2 -> type < 730 )
return - 1 ;
else
V_3 = V_158 ;
V_23 = F_6 ( V_2 ,
V_102 , V_3 , & V_6 , sizeof( V_6 ) ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_2 -> type < 675 )
* V_156 = V_6 | 0x100 ;
else
* V_156 = V_6 ;
return 0 ;
}
long F_76 ( struct V_1 * V_2 , unsigned int V_159 , void * V_160 )
{
long V_23 = 0 ;
switch( V_159 ) {
case V_161 :
{
if ( F_43 ( V_2 ) )
V_23 = - V_30 ;
break;
}
case V_162 :
{
if ( F_44 ( V_2 ) )
V_23 = - V_30 ;
break;
}
case V_163 :
{
if ( F_45 ( V_2 ) )
V_23 = - V_30 ;
break;
}
case V_164 :
{
F_77 (int, qual)
if ( V_2 -> V_165 ) {
V_23 = - V_166 ;
break;
}
F_78 (qual)
if ( F_79 ( V_167 ) < 0 || F_79 ( V_167 ) > 3 )
V_23 = - V_30 ;
else
V_23 = F_18 ( V_2 , V_2 -> V_68 . V_48 , V_2 -> V_68 . V_49 , V_2 -> V_42 , F_79 ( V_167 ) , V_2 -> V_60 ) ;
if ( V_23 >= 0 )
V_2 -> V_168 = F_79 ( V_167 ) ;
break;
}
case V_169 :
{
F_77 (int, qual)
F_79 ( V_167 ) = V_2 -> V_168 ;
F_80 (qual)
break;
}
case V_170 :
{
F_77 (struct pwc_probe, probe)
strcpy ( F_79 ( V_171 ) . V_172 , V_2 -> V_173 . V_172 ) ;
F_79 ( V_171 ) . type = V_2 -> type ;
F_80 (probe)
break;
}
case V_174 :
{
F_77 (struct pwc_serial, serial)
strcpy ( F_79 ( V_175 ) . V_175 , V_2 -> V_175 ) ;
F_80 (serial)
break;
}
case V_176 :
{
F_77 (int, agc)
F_78 (agc)
if ( F_37 ( V_2 , F_79 ( V_177 ) < 0 ? 1 : 0 , F_79 ( V_177 ) ) )
V_23 = - V_30 ;
break;
}
case V_178 :
{
F_77 (int, agc)
if ( F_38 ( V_2 , F_81 ( V_177 ) ) )
V_23 = - V_30 ;
F_80 (agc)
break;
}
case V_179 :
{
F_77 (int, shutter_speed)
F_78 (shutter_speed)
V_23 = F_39 ( V_2 , F_79 ( V_180 ) < 0 ? 1 : 0 , F_79 ( V_180 ) ) ;
break;
}
case V_181 :
{
F_77 (struct pwc_whitebalance, wb)
F_78 (wb)
V_23 = F_46 ( V_2 , F_79 ( V_182 ) . V_33 ) ;
if ( V_23 >= 0 && F_79 ( V_182 ) . V_33 == V_183 ) {
F_48 ( V_2 , F_79 ( V_182 ) . V_184 ) ;
F_50 ( V_2 , F_79 ( V_182 ) . V_185 ) ;
}
break;
}
case V_186 :
{
F_77 (struct pwc_whitebalance, wb)
memset ( F_81 ( V_182 ) , 0 , sizeof( struct V_187 ) ) ;
F_79 ( V_182 ) . V_33 = F_47 ( V_2 ) ;
if ( F_79 ( V_182 ) . V_33 < 0 )
V_23 = - V_30 ;
else {
if ( F_79 ( V_182 ) . V_33 == V_183 ) {
V_23 = F_49 ( V_2 , & F_79 ( V_182 ) . V_184 ) ;
if ( V_23 < 0 )
break;
V_23 = F_51 ( V_2 , & F_79 ( V_182 ) . V_185 ) ;
if ( V_23 < 0 )
break;
}
if ( F_79 ( V_182 ) . V_33 == V_188 ) {
V_23 = F_52 ( V_2 , & F_79 ( V_182 ) . V_189 ) ;
if ( V_23 < 0 )
break;
V_23 = F_53 ( V_2 , & F_79 ( V_182 ) . V_190 ) ;
if ( V_23 < 0 )
break;
}
}
F_80 (wb)
break;
}
case V_191 :
{
F_77 (struct pwc_wb_speed, wbs)
if ( F_79 ( V_192 ) . V_193 > 0 ) {
V_23 = F_54 ( V_2 , F_79 ( V_192 ) . V_193 ) ;
}
if ( F_79 ( V_192 ) . V_194 > 0 ) {
V_23 = F_56 ( V_2 , F_79 ( V_192 ) . V_194 ) ;
}
break;
}
case V_195 :
{
F_77 (struct pwc_wb_speed, wbs)
V_23 = F_55 ( V_2 , & F_79 ( V_192 ) . V_193 ) ;
if ( V_23 < 0 )
break;
V_23 = F_57 ( V_2 , & F_79 ( V_192 ) . V_194 ) ;
if ( V_23 < 0 )
break;
F_80 (wbs)
break;
}
case V_196 :
{
F_77 (struct pwc_leds, leds)
F_78 (leds)
V_23 = F_58 ( V_2 , F_79 ( V_197 ) . V_198 , F_79 ( V_197 ) . V_199 ) ;
break;
}
case V_200 :
{
F_77 (struct pwc_leds, leds)
V_23 = F_59 ( V_2 , & F_79 ( V_197 ) . V_198 , & F_79 ( V_197 ) . V_199 ) ;
F_80 (leds)
break;
}
case V_201 :
{
F_77 (int, contour)
F_78 (contour)
V_23 = F_60 ( V_2 , F_79 ( V_125 ) ) ;
break;
}
case V_202 :
{
F_77 (int, contour)
V_23 = F_61 ( V_2 , F_81 ( V_125 ) ) ;
F_80 (contour)
break;
}
case V_203 :
{
F_77 (int, backlight)
F_78 (backlight)
V_23 = F_62 ( V_2 , F_79 ( V_128 ) ) ;
break;
}
case V_204 :
{
F_77 (int, backlight)
V_23 = F_63 ( V_2 , F_81 ( V_128 ) ) ;
F_80 (backlight)
break;
}
case V_205 :
{
F_77 (int, flicker)
F_78 (flicker)
V_23 = F_66 ( V_2 , F_79 ( V_132 ) ) ;
break;
}
case V_206 :
{
F_77 (int, flicker)
V_23 = F_67 ( V_2 , F_81 ( V_132 ) ) ;
F_80 (flicker)
break;
}
case V_207 :
{
F_77 (int, dynnoise)
F_78 (dynnoise)
V_23 = F_68 ( V_2 , F_79 ( V_208 ) ) ;
break;
}
case V_209 :
{
F_77 (int, dynnoise)
V_23 = F_69 ( V_2 , F_81 ( V_208 ) ) ;
F_80 ( V_208 ) ;
break;
}
case V_210 :
{
F_77 (struct pwc_imagesize, size)
F_79 ( V_21 ) . V_64 = V_2 -> V_45 . V_48 ;
F_79 ( V_21 ) . V_65 = V_2 -> V_45 . V_49 ;
F_80 (size)
break;
}
case V_211 :
{
if ( V_2 -> V_212 & V_213 )
{
F_77 (int, flags)
F_78 (flags)
V_23 = F_71 ( V_2 , F_79 ( V_136 ) ) ;
}
else
{
V_23 = - V_214 ;
}
break;
}
case V_215 :
{
if ( V_2 -> V_212 & V_213 )
{
F_77 (struct pwc_mpt_range, range)
F_79 ( V_216 ) = V_2 -> V_144 ;
F_80 (range)
}
else
{
V_23 = - V_214 ;
}
break;
}
case V_217 :
{
int V_218 , V_219 ;
if ( V_2 -> V_212 & V_213 )
{
F_77 (struct pwc_mpt_angles, angles)
F_78 (angles)
if ( F_79 ( V_220 ) . V_221 )
{
V_218 = F_79 ( V_220 ) . V_141 ;
V_219 = F_79 ( V_220 ) . V_142 ;
}
else
{
V_218 = V_2 -> V_139 + F_79 ( V_220 ) . V_141 ;
V_219 = V_2 -> V_140 + F_79 ( V_220 ) . V_142 ;
}
V_23 = F_73 ( V_2 , V_218 , V_219 ) ;
}
else
{
V_23 = - V_214 ;
}
break;
}
case V_222 :
{
if ( V_2 -> V_212 & V_213 )
{
F_77 (struct pwc_mpt_angles, angles)
F_79 ( V_220 ) . V_221 = 1 ;
F_79 ( V_220 ) . V_141 = V_2 -> V_139 ;
F_79 ( V_220 ) . V_142 = V_2 -> V_140 ;
F_80 (angles)
}
else
{
V_23 = - V_214 ;
}
break;
}
case V_223 :
{
if ( V_2 -> V_212 & V_213 )
{
F_77 (struct pwc_mpt_status, status)
V_23 = F_74 ( V_2 , F_81 ( V_151 ) ) ;
F_80 (status)
}
else
{
V_23 = - V_214 ;
}
break;
}
case V_224 :
{
F_77 ( struct V_225 , V_226 ) ;
F_79 ( V_226 ) . type = V_2 -> type ;
F_79 ( V_226 ) . V_38 = V_2 -> V_38 ;
F_79 ( V_226 ) . V_227 = V_2 -> V_40 ;
memcpy ( & F_79 ( V_226 ) . V_228 , V_2 -> V_41 , V_2 -> V_40 ) ;
F_79 ( V_226 ) . V_59 = V_2 -> V_50 ;
F_79 ( V_226 ) . V_47 = V_2 -> V_47 ;
F_80 (vcmd)
break;
}
default:
V_23 = - V_229 ;
break;
}
if ( V_23 > 0 )
return 0 ;
return V_23 ;
}
