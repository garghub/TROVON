static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_4 )
{
F_6 ( V_2 -> V_3 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 & 0x20 ) {
F_8 ( V_2 -> V_3 ) ;
} else {
F_9 ( V_2 -> V_3 ) ;
}
V_4 &= ~ 0x20 ;
F_10 ( V_2 -> V_3 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_5 )
{
int V_6 ;
int V_7 = 0 ;
if ( V_5 ) {
while ( ! ( ( V_6 = F_1 ( V_2 ) ) & 8 ) ) {
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 > ( V_8 + 1000 ) )
return - 1 ;
}
} else {
while ( ( ( V_6 = F_1 ( V_2 ) ) & 8 ) ) {
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 ++ > ( V_8 + 1000 ) )
return - 1 ;
}
}
return V_6 ;
}
static unsigned int F_13 ( struct V_1 * V_2 , int V_5 )
{
unsigned int V_6 ;
int V_7 = 0 ;
do {
V_6 = F_3 ( V_2 ) ;
if ( V_7 ++ > V_8 )
F_12 ( 5 ) ;
if ( V_7 ++ > ( V_8 + 1000 ) )
return 0 ;
} while ( ( V_6 & 1 ) != V_5 );
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , int V_9 )
{
int V_10 , V_11 ;
int V_12 ;
F_5 ( V_2 , V_9 ) ;
F_7 ( V_2 , 6 ) ;
V_10 = F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0xe ) ;
V_11 = F_11 ( V_2 , 0 ) ;
V_12 = ( V_10 & 0xf0 ) | ( ( V_11 & 0xf0 ) >> 4 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_10 , V_11 ;
int V_12 ;
F_7 ( V_2 , 6 ) ;
V_10 = F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0xe ) ;
V_11 = F_11 ( V_2 , 0 ) ;
V_12 = ( V_10 & 0xf0 ) | ( ( V_11 & 0xf0 ) >> 4 ) ;
return V_12 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_13 , V_14 ;
int V_15 = 0 ;
int V_16 ;
if ( V_17 )
return 1 ;
V_14 = V_13 = F_1 ( V_2 ) & 0xf0 ;
for ( V_16 = 0 ; V_16 < 500 ; V_16 ++ ) {
V_13 = F_1 ( V_2 ) & 0xf0 ;
if ( V_13 != V_14 )
V_15 ++ ;
V_14 = V_13 ;
F_17 ( 2 ) ;
}
#if 0
printk(KERN_DEBUG "Debugging: QCam detection counter <30-200 counts as detected>: %d\n", count);
return 1;
#endif
if ( V_15 > 20 && V_15 < 400 ) {
return 1 ;
} else {
F_18 ( V_18 L_1 ,
V_2 -> V_3 -> V_19 ) ;
F_18 ( V_20 L_2 , V_15 ) ;
return 0 ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
int V_21 = V_2 -> V_22 ;
switch ( V_2 -> V_23 ) {
case 1 :
V_2 -> V_22 = 0 ;
break;
case 2 :
V_2 -> V_22 = 4 ;
break;
case 4 :
V_2 -> V_22 = 8 ;
break;
}
switch ( V_2 -> V_24 ) {
case 4 :
break;
case 6 :
V_2 -> V_22 += 2 ;
break;
}
switch ( V_2 -> V_25 & V_26 ) {
case V_27 :
V_2 -> V_22 += 1 ;
break;
case V_28 :
case V_29 :
break;
}
if ( V_2 -> V_22 != V_21 )
V_2 -> V_6 |= V_30 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_25 & V_31 ) {
case V_32 :
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_29 ;
break;
case V_33 :
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_27 ;
break;
case V_34 :
F_7 ( V_2 , 0x20 ) ;
F_5 ( V_2 , 0x75 ) ;
if ( F_3 ( V_2 ) != 0x75 )
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_27 ;
else
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_26 ) | V_29 ;
break;
}
F_7 ( V_2 , 0xb ) ;
F_21 ( 250 ) ;
F_7 ( V_2 , 0xe ) ;
F_19 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
int V_35 ;
F_20 ( V_2 ) ;
F_14 ( V_2 , 0xb ) ;
F_14 ( V_2 , V_2 -> V_36 ) ;
V_5 = V_2 -> V_37 / V_2 -> V_23 ;
F_14 ( V_2 , 0x11 ) ;
F_14 ( V_2 , V_5 ) ;
if ( ( V_2 -> V_25 & V_26 ) == V_29 && V_2 -> V_24 == 6 ) {
V_5 = V_2 -> V_38 ;
V_35 = V_2 -> V_23 * 4 ;
} else {
V_5 = V_2 -> V_38 * V_2 -> V_24 ;
V_35 = ( ( ( V_2 -> V_25 & V_26 ) == V_27 ) ? 24 : 8 ) *
V_2 -> V_23 ;
}
V_5 = F_23 ( V_5 , V_35 ) ;
F_14 ( V_2 , 0x13 ) ;
F_14 ( V_2 , V_5 ) ;
F_14 ( V_2 , 0xd ) ;
F_14 ( V_2 , V_2 -> V_39 ) ;
F_14 ( V_2 , 0xf ) ;
F_14 ( V_2 , V_2 -> V_40 / 2 ) ;
F_14 ( V_2 , 0x19 ) ;
F_14 ( V_2 , V_2 -> V_41 ) ;
F_14 ( V_2 , 0x1f ) ;
F_14 ( V_2 , V_2 -> V_42 ) ;
V_2 -> V_6 &= ( ~ V_30 ) ;
}
static inline int F_24 ( struct V_1 * V_2 , char V_43 [] )
{
int V_44 = 1 ;
unsigned int V_45 , V_46 ;
unsigned int V_47 , V_48 ;
static int V_49 ;
if ( V_43 == NULL ) {
V_49 = 0 ;
return 0 ;
}
switch ( V_2 -> V_25 & V_26 ) {
case V_27 :
F_7 ( V_2 , 0x26 ) ;
V_46 = ( F_13 ( V_2 , 1 ) >> 1 ) ;
V_45 = ( F_1 ( V_2 ) >> 3 ) & 0x1f ;
F_7 ( V_2 , 0x2e ) ;
V_48 = ( F_13 ( V_2 , 0 ) >> 1 ) ;
V_47 = ( F_1 ( V_2 ) >> 3 ) & 0x1f ;
switch ( V_2 -> V_24 ) {
case 4 :
V_43 [ 0 ] = V_46 & 0xf ;
V_43 [ 1 ] = ( ( V_46 & 0x70 ) >> 4 ) | ( ( V_45 & 1 ) << 3 ) ;
V_43 [ 2 ] = ( V_45 & 0x1e ) >> 1 ;
V_43 [ 3 ] = V_48 & 0xf ;
V_43 [ 4 ] = ( ( V_48 & 0x70 ) >> 4 ) | ( ( V_47 & 1 ) << 3 ) ;
V_43 [ 5 ] = ( V_47 & 0x1e ) >> 1 ;
V_44 = 6 ;
break;
case 6 :
V_43 [ 0 ] = V_46 & 0x3f ;
V_43 [ 1 ] = ( ( V_46 & 0x40 ) >> 6 ) | ( V_45 << 1 ) ;
V_43 [ 2 ] = V_48 & 0x3f ;
V_43 [ 3 ] = ( ( V_48 & 0x40 ) >> 6 ) | ( V_47 << 1 ) ;
V_44 = 4 ;
break;
}
break;
case V_29 :
F_7 ( V_2 , 6 ) ;
V_46 = ( F_11 ( V_2 , 1 ) & 0xf0 ) >> 4 ;
F_7 ( V_2 , 0xe ) ;
V_45 = ( F_11 ( V_2 , 0 ) & 0xf0 ) >> 4 ;
switch ( V_2 -> V_24 ) {
case 4 :
V_43 [ 0 ] = V_46 ;
V_43 [ 1 ] = V_45 ;
V_44 = 2 ;
break;
case 6 :
switch ( V_49 ) {
case 0 :
V_43 [ 0 ] = ( V_46 << 2 ) | ( ( V_45 & 0xc ) >> 2 ) ;
V_2 -> V_50 = ( V_45 & 3 ) << 4 ;
V_49 = 1 ;
V_44 = 1 ;
break;
case 1 :
V_43 [ 0 ] = V_46 | V_2 -> V_50 ;
V_2 -> V_50 = V_45 << 2 ;
V_49 = 2 ;
V_44 = 1 ;
break;
case 2 :
V_43 [ 0 ] = ( ( V_46 & 0xc ) >> 2 ) | V_2 -> V_50 ;
V_43 [ 1 ] = ( ( V_46 & 3 ) << 4 ) | V_45 ;
V_49 = 0 ;
V_44 = 2 ;
break;
}
break;
}
break;
}
return V_44 ;
}
static long F_25 ( struct V_1 * V_2 , char T_1 * V_51 , unsigned long V_52 )
{
int V_16 , V_53 , V_54 , V_55 ;
int V_56 ;
int V_57 , V_58 ;
int V_59 ;
int V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
char V_43 [ 6 ] ;
int V_63 = 8 - V_2 -> V_24 ;
char V_64 ;
if ( V_2 -> V_22 == - 1 )
return - V_65 ;
F_14 ( V_2 , 0x7 ) ;
F_14 ( V_2 , V_2 -> V_22 ) ;
if ( ( V_2 -> V_25 & V_26 ) == V_27 ) {
F_7 ( V_2 , 0x2e ) ;
F_7 ( V_2 , 0x26 ) ;
F_11 ( V_2 , 1 ) ;
F_7 ( V_2 , 0x2e ) ;
F_11 ( V_2 , 0 ) ;
}
V_64 = ( V_2 -> V_24 == 4 ) ? 16 : 63 ;
V_57 = V_2 -> V_37 / V_2 -> V_23 ;
V_60 = V_2 -> V_38 / V_2 -> V_23 ;
V_58 = V_2 -> V_38 * V_2 -> V_24 ;
V_59 = ( ( ( V_2 -> V_25 & V_26 ) == V_27 ) ? 24 : 8 ) *
V_2 -> V_23 ;
V_58 = F_23 ( V_58 , V_59 ) ;
for ( V_16 = 0 , V_55 = V_66 ; V_16 < V_57 ; V_16 ++ ) {
for ( V_61 = V_53 = 0 ; V_53 < V_58 ; V_53 ++ ) {
V_56 = F_24 ( V_2 , V_43 ) ;
for ( V_54 = 0 ; V_54 < V_56 && ( V_61 + V_54 ) < V_60 ; V_54 ++ ) {
int V_67 ;
if ( V_43 [ V_54 ] == 0 && V_64 == 16 ) {
V_43 [ V_54 ] = 16 ;
}
V_67 = V_16 * V_60 + V_61 + V_54 ;
if ( V_67 < V_52 ) {
V_62 ++ ;
F_26 ( ( V_64 - V_43 [ V_54 ] ) << V_63 , V_51 + V_67 ) ;
}
}
V_61 += V_56 ;
}
F_24 ( V_2 , NULL ) ;
if ( V_16 >= V_55 ) {
F_12 ( 5 ) ;
V_55 = V_16 + V_66 ;
}
}
if ( ( V_2 -> V_25 & V_26 ) == V_27 ) {
F_7 ( V_2 , 2 ) ;
F_7 ( V_2 , 6 ) ;
F_21 ( 3 ) ;
F_7 ( V_2 , 0xe ) ;
}
if ( V_62 < V_52 )
return V_62 ;
return V_52 ;
}
static int F_27 ( struct V_68 * V_68 , void * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
F_29 ( V_71 -> V_72 , V_1 -> V_73 . V_19 , sizeof( V_71 -> V_72 ) ) ;
F_29 ( V_71 -> V_74 , L_3 , sizeof( V_71 -> V_74 ) ) ;
F_29 ( V_71 -> V_75 , L_4 , sizeof( V_71 -> V_75 ) ) ;
V_71 -> V_76 = F_30 ( 0 , 0 , 2 ) ;
V_71 -> V_77 = V_78 | V_79 ;
return 0 ;
}
static int F_31 ( struct V_68 * V_68 , void * V_80 , struct V_81 * V_82 )
{
if ( V_82 -> V_83 > 0 )
return - V_84 ;
F_29 ( V_82 -> V_19 , L_5 , sizeof( V_82 -> V_19 ) ) ;
V_82 -> type = V_85 ;
V_82 -> V_86 = 0 ;
V_82 -> V_87 = 0 ;
V_82 -> V_88 = 0 ;
V_82 -> V_6 = 0 ;
return 0 ;
}
static int F_32 ( struct V_68 * V_68 , void * V_80 , unsigned int * V_89 )
{
* V_89 = 0 ;
return 0 ;
}
static int F_33 ( struct V_68 * V_68 , void * V_80 , unsigned int V_89 )
{
return ( V_89 > 0 ) ? - V_84 : 0 ;
}
static int F_34 ( struct V_68 * V_68 , void * V_69 ,
struct V_90 * V_91 )
{
switch ( V_91 -> V_92 ) {
case V_93 :
return F_35 ( V_91 , 0 , 255 , 1 , 180 ) ;
case V_94 :
return F_35 ( V_91 , 0 , 255 , 1 , 192 ) ;
case V_95 :
return F_35 ( V_91 , 0 , 255 , 1 , 105 ) ;
}
return - V_84 ;
}
static int F_36 ( struct V_68 * V_68 , void * V_69 ,
struct V_96 * V_97 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
int V_44 = 0 ;
switch ( V_97 -> V_92 ) {
case V_93 :
V_97 -> V_98 = V_1 -> V_36 ;
break;
case V_94 :
V_97 -> V_98 = V_1 -> V_41 ;
break;
case V_95 :
V_97 -> V_98 = V_1 -> V_42 ;
break;
default:
V_44 = - V_84 ;
break;
}
return V_44 ;
}
static int F_37 ( struct V_68 * V_68 , void * V_69 ,
struct V_96 * V_97 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
int V_44 = 0 ;
F_38 ( & V_1 -> V_99 ) ;
switch ( V_97 -> V_92 ) {
case V_93 :
V_1 -> V_36 = V_97 -> V_98 ;
break;
case V_94 :
V_1 -> V_41 = V_97 -> V_98 ;
break;
case V_95 :
V_1 -> V_42 = V_97 -> V_98 ;
break;
default:
V_44 = - V_84 ;
break;
}
if ( V_44 == 0 ) {
F_19 ( V_1 ) ;
V_1 -> V_6 |= V_30 ;
}
F_39 ( & V_1 -> V_99 ) ;
return V_44 ;
}
static int F_40 ( struct V_68 * V_68 , void * V_80 , struct V_100 * V_101 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
V_103 -> V_38 = V_1 -> V_38 / V_1 -> V_23 ;
V_103 -> V_37 = V_1 -> V_37 / V_1 -> V_23 ;
V_103 -> V_104 = ( V_1 -> V_24 == 4 ) ? V_105 : V_106 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_109 = V_1 -> V_38 ;
V_103 -> V_110 = V_1 -> V_38 * V_1 -> V_37 ;
V_103 -> V_111 = V_112 ;
return 0 ;
}
static int F_41 ( struct V_68 * V_68 , void * V_80 , struct V_100 * V_101 )
{
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
if ( V_103 -> V_37 <= 60 || V_103 -> V_38 <= 80 ) {
V_103 -> V_37 = 60 ;
V_103 -> V_38 = 80 ;
} else if ( V_103 -> V_37 <= 120 || V_103 -> V_38 <= 160 ) {
V_103 -> V_37 = 120 ;
V_103 -> V_38 = 160 ;
} else {
V_103 -> V_37 = 240 ;
V_103 -> V_38 = 320 ;
}
if ( V_103 -> V_104 != V_105 &&
V_103 -> V_104 != V_106 )
V_103 -> V_104 = V_105 ;
V_103 -> V_107 = V_108 ;
V_103 -> V_109 = V_103 -> V_38 ;
V_103 -> V_110 = V_103 -> V_38 * V_103 -> V_37 ;
V_103 -> V_111 = V_112 ;
return 0 ;
}
static int F_42 ( struct V_68 * V_68 , void * V_80 , struct V_100 * V_101 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
int V_44 = F_41 ( V_68 , V_80 , V_101 ) ;
if ( V_44 )
return V_44 ;
V_1 -> V_38 = 320 ;
V_1 -> V_37 = 240 ;
if ( V_103 -> V_37 == 60 )
V_1 -> V_23 = 4 ;
else if ( V_103 -> V_37 == 120 )
V_1 -> V_23 = 2 ;
else
V_1 -> V_23 = 1 ;
if ( V_103 -> V_104 == V_106 )
V_1 -> V_24 = 6 ;
else
V_1 -> V_24 = 4 ;
F_38 ( & V_1 -> V_99 ) ;
F_19 ( V_1 ) ;
V_1 -> V_6 |= V_30 ;
F_39 ( & V_1 -> V_99 ) ;
return 0 ;
}
static int F_43 ( struct V_68 * V_68 , void * V_80 , struct V_113 * V_101 )
{
static struct V_113 V_114 [] = {
{ 0 , 0 , 0 ,
L_6 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 0 , 0 , 0 ,
L_7 , V_106 ,
{ 0 , 0 , 0 , 0 }
} ,
} ;
enum V_115 type = V_101 -> type ;
if ( V_101 -> V_83 > 1 )
return - V_84 ;
* V_101 = V_114 [ V_101 -> V_83 ] ;
V_101 -> type = type ;
return 0 ;
}
static T_2 F_44 ( struct V_68 * V_68 , char T_1 * V_51 ,
T_3 V_15 , T_4 * V_116 )
{
struct V_1 * V_1 = F_28 ( V_68 ) ;
int V_52 ;
F_45 ( V_1 -> V_117 ) ;
F_38 ( & V_1 -> V_99 ) ;
F_20 ( V_1 ) ;
if ( V_1 -> V_6 & V_30 )
F_22 ( V_1 ) ;
V_52 = F_25 ( V_1 , V_51 , V_15 ) ;
F_39 ( & V_1 -> V_99 ) ;
F_46 ( V_1 -> V_117 ) ;
return V_52 ;
}
static struct V_1 * F_47 ( struct V_118 * V_119 )
{
struct V_1 * V_1 ;
struct V_120 * V_73 ;
V_1 = F_48 ( sizeof( struct V_1 ) , V_121 ) ;
if ( V_1 == NULL )
return NULL ;
V_73 = & V_1 -> V_73 ;
F_29 ( V_73 -> V_19 , L_8 , sizeof( V_73 -> V_19 ) ) ;
if ( F_49 ( NULL , V_73 ) < 0 ) {
F_50 ( V_73 , L_9 ) ;
return NULL ;
}
V_1 -> V_3 = V_119 ;
V_1 -> V_117 = F_51 ( V_119 , L_8 , NULL , NULL ,
NULL , 0 , NULL ) ;
if ( V_1 -> V_117 == NULL ) {
F_50 ( V_73 , L_10 , V_119 -> V_19 ) ;
F_52 ( V_1 ) ;
return NULL ;
}
F_29 ( V_1 -> V_122 . V_19 , L_11 , sizeof( V_1 -> V_122 . V_19 ) ) ;
V_1 -> V_122 . V_73 = V_73 ;
V_1 -> V_122 . V_123 = & V_124 ;
V_1 -> V_122 . V_125 = & V_126 ;
V_1 -> V_122 . V_127 = V_128 ;
F_53 ( & V_1 -> V_122 , V_1 ) ;
F_54 ( & V_1 -> V_99 ) ;
V_1 -> V_25 = ( V_34 | V_28 ) ;
V_1 -> V_38 = 320 ;
V_1 -> V_37 = 240 ;
V_1 -> V_24 = 4 ;
V_1 -> V_23 = 2 ;
V_1 -> V_41 = 192 ;
V_1 -> V_36 = 180 ;
V_1 -> V_42 = 105 ;
V_1 -> V_39 = 1 ;
V_1 -> V_40 = 14 ;
V_1 -> V_22 = - 1 ;
V_1 -> V_6 = V_30 ;
return V_1 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_98 ;
int V_15 = 0 ;
F_14 ( V_2 , 27 ) ;
F_14 ( V_2 , 0 ) ;
do {
F_14 ( V_2 , 33 ) ;
V_98 = F_15 ( V_2 ) ;
F_17 ( 1 ) ;
F_56 () ;
V_15 ++ ;
} while ( V_98 == 0xff && V_15 < 2048 );
V_2 -> V_42 = V_98 ;
return V_98 ;
}
static int F_57 ( struct V_118 * V_119 )
{
struct V_1 * V_1 ;
if ( V_129 == V_130 ) {
F_18 ( V_18 L_12 , V_130 ) ;
return - V_131 ;
}
V_1 = F_47 ( V_119 ) ;
if ( V_1 == NULL )
return - V_132 ;
F_45 ( V_1 -> V_117 ) ;
F_20 ( V_1 ) ;
if ( F_16 ( V_1 ) == 0 ) {
F_46 ( V_1 -> V_117 ) ;
F_58 ( V_1 -> V_117 ) ;
F_52 ( V_1 ) ;
return - V_132 ;
}
F_55 ( V_1 ) ;
F_46 ( V_1 -> V_117 ) ;
F_59 ( & V_1 -> V_73 , L_13 , V_1 -> V_3 -> V_19 ) ;
if ( F_60 ( & V_1 -> V_122 , V_133 , V_134 ) < 0 ) {
F_58 ( V_1 -> V_117 ) ;
F_52 ( V_1 ) ;
return - V_132 ;
}
V_135 [ V_129 ++ ] = V_1 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_1 )
{
F_62 ( & V_1 -> V_122 ) ;
F_58 ( V_1 -> V_117 ) ;
F_52 ( V_1 ) ;
}
static int F_63 ( struct V_118 * V_119 )
{
#ifdef F_64
int V_136 ;
if ( V_118 [ 0 ] && strncmp ( V_118 [ 0 ] , L_14 , 4 ) != 0 ) {
for ( V_136 = 0 ; V_136 < V_130 && V_118 [ V_136 ] ; V_136 ++ ) {
char * V_137 ;
unsigned long V_138 ;
V_138 = F_65 ( V_118 [ V_136 ] , & V_137 , 0 ) ;
if ( V_137 == V_118 [ V_136 ] ) {
F_18 ( V_18
L_15 ,
V_118 [ V_136 ] ) ;
continue;
}
if ( V_138 == V_119 -> V_139 )
return 1 ;
}
return 0 ;
}
#endif
return 1 ;
}
static void F_66 ( struct V_118 * V_119 )
{
if ( F_63 ( V_119 ) )
F_57 ( V_119 ) ;
}
static void F_67 ( struct V_118 * V_119 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_129 ; V_16 ++ ) {
struct V_1 * V_1 = V_135 [ V_16 ] ;
if ( V_1 && V_1 -> V_117 -> V_119 == V_119 ) {
V_135 [ V_16 ] = NULL ;
F_61 ( V_1 ) ;
}
}
}
static void T_5 F_68 ( void )
{
F_69 ( & V_140 ) ;
}
static int T_6 F_70 ( void )
{
#ifdef F_64
if ( V_8 > 5000 ) {
F_18 ( V_141 L_16 ) ;
V_8 = 5000 ;
}
if ( V_66 < 1 ) {
F_18 ( V_141 L_17 ) ;
V_66 = 1 ;
}
#endif
return F_71 ( & V_140 ) ;
}
