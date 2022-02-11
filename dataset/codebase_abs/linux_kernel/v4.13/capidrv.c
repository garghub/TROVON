static inline T_1 F_1 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
return 0 ;
case V_6 :
default:
return 0 ;
case V_7 :
return 1 ;
case V_8 :
case V_9 :
case V_10 :
return 2 ;
case V_11 :
return 4 ;
case V_12 :
return 8 ;
}
}
static inline T_1 F_2 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
default:
return 0 ;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_12 :
return 1 ;
case V_11 :
return 4 ;
}
}
static inline T_1 F_3 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_12 :
default:
return 0 ;
case V_11 :
return 4 ;
}
}
static T_2 F_4 ( T_3 V_13 )
{
static unsigned char V_14 [ 9 ] ;
V_14 [ 0 ] = 8 ;
V_14 [ 1 ] = V_13 & 0xff ; V_14 [ 2 ] = ( V_13 >> 8 ) & 0xff ;
V_14 [ 3 ] = 8 ; V_14 [ 4 ] = 0 ;
V_14 [ 5 ] = 0 ; V_14 [ 6 ] = 0 ;
V_14 [ 7 ] = 0 ; V_14 [ 8 ] = 0 ;
return V_14 ;
}
static T_2 F_5 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
default:
return NULL ;
case V_8 :
return F_4 ( 9600 ) ;
case V_9 :
return F_4 ( 19200 ) ;
case V_10 :
return F_4 ( 38400 ) ;
}
}
static inline T_3 F_6 ( T_4 V_15 , T_4 V_16 )
{
static const T_4 V_17 [ 17 ] [ 5 ] =
{
{ 0 , 0 , 0 , 0 , 0 } ,
{ 16 , 16 , 4 , 26 , 16 } ,
{ 17 , 17 , 17 , 4 , 4 } ,
{ 2 , 2 , 2 , 2 , 2 } ,
{ 18 , 18 , 18 , 18 , 18 } ,
{ 2 , 2 , 2 , 2 , 2 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
{ 2 , 2 , 2 , 2 , 2 } ,
{ 2 , 2 , 2 , 2 , 2 } ,
{ 21 , 21 , 21 , 21 , 21 } ,
{ 19 , 19 , 19 , 19 , 19 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
{ 22 , 22 , 22 , 22 , 22 } ,
{ 27 , 27 , 27 , 28 , 27 }
} ;
if ( V_15 > 16 )
V_15 = 0 ;
if ( V_16 > 4 )
V_16 = 0 ;
return ( T_3 ) V_17 [ V_15 ] [ V_16 ] ;
}
static inline T_4 F_7 ( T_3 V_18 )
{
static const T_4 V_19 [ 32 ] =
{ 7 , 1 , 7 , 7 , 1 , 1 , 7 , 7 ,
7 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ,
1 , 2 , 4 , 10 , 9 , 9 , 15 , 7 ,
7 , 7 , 1 , 16 , 16 , 0 , 0 , 0 } ;
if ( V_18 > 31 )
V_18 = 0 ;
return V_19 [ V_18 ] ;
}
static inline T_4 F_8 ( T_3 V_18 )
{
static const T_4 V_19 [ 32 ] =
{ 0 , 0 , 0 , 0 , 2 , 3 , 0 , 0 ,
0 , 3 , 0 , 0 , 0 , 0 , 0 , 0 ,
1 , 2 , 0 , 0 , 9 , 0 , 0 , 0 ,
0 , 0 , 3 , 2 , 3 , 0 , 0 , 0 } ;
if ( V_18 > 31 )
V_18 = 0 ;
return V_19 [ V_18 ] ;
}
static inline T_5 * F_9 ( int V_20 )
{
unsigned long V_21 ;
T_5 * V_22 ;
F_10 ( & V_23 , V_21 ) ;
for ( V_22 = V_24 . V_25 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_27 == V_20 )
break;
F_11 ( & V_23 , V_21 ) ;
return V_22 ;
}
static T_5 * F_12 ( T_1 V_28 )
{
unsigned long V_21 ;
T_5 * V_22 = V_24 . V_25 ;
F_10 ( & V_23 , V_21 ) ;
for ( V_22 = V_24 . V_25 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_29 == V_28 )
break;
F_11 ( & V_23 , V_21 ) ;
return V_22 ;
}
static T_6 * F_13 ( T_5 * V_30 , int V_31 )
{
T_6 * V_32 ;
V_32 = F_14 ( sizeof( T_6 ) , V_33 ) ;
if ( V_32 == NULL )
return NULL ;
V_32 -> V_34 = V_35 ;
V_32 -> V_36 = 0 ;
V_32 -> V_37 = 0 ;
V_32 -> V_31 = V_31 ;
V_32 -> V_26 = V_30 -> V_38 ;
V_30 -> V_38 = V_32 ;
V_30 -> V_39 [ V_31 ] . V_32 = V_32 ;
return V_32 ;
}
static T_6 * F_15 ( T_5 * V_30 , T_1 V_36 )
{
T_6 * V_22 ;
for ( V_22 = V_30 -> V_38 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_36 == V_36 )
return V_22 ;
return NULL ;
}
static T_6 * F_16 ( T_5 * V_30 , T_3 V_37 )
{
T_6 * V_22 ;
for ( V_22 = V_30 -> V_38 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_37 == V_37 )
return V_22 ;
return NULL ;
}
static T_6 * F_17 ( T_5 * V_30 , T_1 V_40 )
{
T_6 * V_22 ;
for ( V_22 = V_30 -> V_38 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_36 == ( V_40 & 0xffff ) )
return V_22 ;
return NULL ;
}
static void F_18 ( T_5 * V_30 , T_6 * V_32 )
{
T_6 * * V_41 ;
for ( V_41 = & V_30 -> V_38 ; * V_41 ; V_41 = & ( * V_41 ) -> V_26 ) {
if ( * V_41 == V_32 ) {
* V_41 = ( * V_41 ) -> V_26 ;
V_30 -> V_39 [ V_32 -> V_31 ] . V_32 = NULL ;
V_30 -> V_39 [ V_32 -> V_31 ] . V_42 = 0 ;
V_30 -> V_39 [ V_32 -> V_31 ] . V_43 = 0 ;
F_19 ( V_32 ) ;
return;
}
}
F_20 ( V_44 L_1 ,
V_30 -> V_29 , V_32 , V_32 -> V_36 ) ;
}
static inline T_7 * F_21 ( T_5 * V_30 ,
T_6 * V_32 ,
T_1 V_40 )
{
T_7 * V_45 ;
V_45 = F_14 ( sizeof( T_7 ) , V_33 ) ;
if ( V_45 == NULL )
return NULL ;
V_45 -> V_40 = V_40 ;
V_45 -> V_34 = V_46 ;
V_45 -> V_32 = V_32 ;
V_45 -> V_31 = V_32 -> V_31 ;
V_45 -> V_47 = 0 ;
V_45 -> V_26 = V_32 -> V_48 ;
V_32 -> V_48 = V_45 ;
V_30 -> V_39 [ V_32 -> V_31 ] . V_45 = V_45 ;
return V_45 ;
}
static inline T_7 * F_22 ( T_5 * V_30 , T_1 V_40 )
{
T_6 * V_32 ;
T_7 * V_22 ;
if ( ( V_32 = F_17 ( V_30 , V_40 ) ) == NULL )
return NULL ;
for ( V_22 = V_32 -> V_48 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_40 == V_40 )
return V_22 ;
return NULL ;
}
static inline T_7 * F_23 ( T_5 * V_30 ,
T_1 V_40 , T_3 V_37 )
{
T_6 * V_32 ;
T_7 * V_22 ;
if ( ( V_32 = F_17 ( V_30 , V_40 ) ) == NULL )
return NULL ;
for ( V_22 = V_32 -> V_48 ; V_22 ; V_22 = V_22 -> V_26 )
if ( V_22 -> V_37 == V_37 )
return V_22 ;
return NULL ;
}
static void F_24 ( T_5 * V_30 , struct T_7 * V_45 )
{
struct T_7 * * V_41 ;
for ( V_41 = & ( V_45 -> V_32 -> V_48 ) ; * V_41 ; V_41 = & ( * V_41 ) -> V_26 ) {
if ( * V_41 == V_45 ) {
* V_41 = ( * V_41 ) -> V_26 ;
break;
}
}
V_30 -> V_39 [ V_45 -> V_31 ] . V_45 = NULL ;
F_19 ( V_45 ) ;
}
static int F_25 ( struct T_7 * V_45 ,
T_3 V_47 , int V_49 )
{
struct V_50 * V_51 , * * V_41 ;
V_51 = F_26 ( sizeof( struct V_50 ) , V_33 ) ;
if ( ! V_51 ) {
F_20 ( V_44 L_2 ) ;
return - 1 ;
}
V_51 -> V_26 = NULL ;
V_51 -> V_47 = V_47 ;
V_51 -> V_49 = V_49 ;
for ( V_41 = & V_45 -> V_52 ; * V_41 ; V_41 = & ( * V_41 ) -> V_26 ) ;
* V_41 = V_51 ;
return 0 ;
}
static int F_27 ( struct T_7 * V_45 , T_3 V_47 )
{
struct V_50 * * V_41 , * V_22 ;
int V_49 ;
for ( V_41 = & V_45 -> V_52 ; * V_41 ; V_41 = & ( * V_41 ) -> V_26 ) {
if ( ( * V_41 ) -> V_47 == V_47 ) {
V_22 = * V_41 ;
V_49 = V_22 -> V_49 ;
* V_41 = ( * V_41 ) -> V_26 ;
F_19 ( V_22 ) ;
return V_49 ;
}
}
return - 1 ;
}
static void F_28 ( T_5 * V_30 , T_8 * V_53 )
{
struct V_54 * V_55 ;
T_9 V_49 ;
if ( F_29 ( V_53 , V_53 -> V_14 ) ) {
F_20 ( V_44 L_3 ) ;
return;
}
V_49 = F_30 ( V_53 -> V_14 ) ;
V_55 = F_31 ( V_49 , V_33 ) ;
if ( ! V_55 ) {
F_20 ( V_44 L_4 ) ;
return;
}
F_32 ( V_55 , V_53 -> V_14 , V_49 ) ;
if ( F_33 ( & V_24 . V_56 , V_55 ) != V_57 )
F_34 ( V_55 ) ;
}
static void F_35 ( T_5 * V_30 , int V_58 )
{
struct V_59 * V_22 = V_60 ;
while ( V_22 -> V_58 ) {
if ( V_30 -> V_34 == V_22 -> V_61 && V_22 -> V_58 == V_58 ) {
if ( V_62 )
F_20 ( V_63 L_5 ,
V_30 -> V_29 , V_30 -> V_34 , V_22 -> V_64 ) ;
V_30 -> V_34 = V_22 -> V_64 ;
return;
}
V_22 ++ ;
}
F_20 ( V_44 L_6 ,
V_30 -> V_29 , V_30 -> V_34 , V_58 ) ;
}
static void F_36 ( T_5 * V_30 , T_6 * V_36 )
{
T_10 V_65 ;
V_30 -> V_39 [ V_36 -> V_31 ] . V_28 = NULL ;
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_36 -> V_31 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
F_18 ( V_30 , V_36 ) ;
}
static void F_37 ( T_5 * V_30 , T_6 * V_36 , int V_58 )
{
struct V_72 * V_22 = V_73 ;
while ( V_22 -> V_58 ) {
if ( V_36 -> V_34 == V_22 -> V_61 && V_22 -> V_58 == V_58 ) {
if ( V_62 )
F_20 ( V_63 L_7 ,
V_30 -> V_29 , V_36 -> V_36 , V_36 -> V_34 , V_22 -> V_64 ) ;
V_36 -> V_34 = V_22 -> V_64 ;
if ( V_22 -> V_74 )
V_22 -> V_74 ( V_30 , V_36 ) ;
return;
}
V_22 ++ ;
}
F_20 ( V_44 L_8 ,
V_30 -> V_29 , V_36 -> V_36 , V_36 -> V_34 , V_58 ) ;
}
static void F_38 ( T_5 * V_30 , T_7 * V_40 )
{
T_10 V_65 ;
F_39 ( & V_53 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_40 -> V_32 -> V_36 ,
NULL ,
NULL ,
NULL ,
NULL
) ;
F_37 ( V_30 , V_40 -> V_32 , V_76 ) ;
F_28 ( V_30 , & V_53 ) ;
V_65 . V_66 = V_77 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_40 -> V_31 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
F_24 ( V_30 , V_40 ) ;
}
static void F_40 ( T_5 * V_30 , T_7 * V_40 , int V_58 )
{
struct V_78 * V_22 = V_79 ;
while ( V_22 -> V_58 ) {
if ( V_40 -> V_34 == V_22 -> V_61 && V_22 -> V_58 == V_58 ) {
if ( V_62 )
F_20 ( V_63 L_9 ,
V_30 -> V_29 , V_40 -> V_40 , V_40 -> V_34 , V_22 -> V_64 ) ;
if ( V_22 -> V_64 == V_80 ) {
V_40 -> V_34 = V_40 -> V_81 ;
V_40 -> V_81 = V_22 -> V_61 ;
} else {
V_40 -> V_81 = V_22 -> V_61 ;
V_40 -> V_34 = V_22 -> V_64 ;
}
if ( V_22 -> V_74 )
V_22 -> V_74 ( V_30 , V_40 ) ;
return;
}
V_22 ++ ;
}
F_20 ( V_44 L_10 ,
V_30 -> V_29 , V_40 -> V_40 , V_40 -> V_34 , V_58 ) ;
}
static inline int F_41 ( T_5 * V_30 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_30 -> V_83 ; V_82 ++ ) {
if ( V_30 -> V_39 [ V_82 ] . V_32 == NULL ) {
V_30 -> V_39 [ V_82 ] . V_42 = 0 ;
return V_82 ;
}
}
return - 1 ;
}
static char * F_42 ( T_3 V_84 )
{
#ifndef F_43
return L_11 ;
#else
switch ( V_84 ) {
case 0x0001 :
return L_12 ;
case 0x0002 :
return L_13 ;
case 0x0003 :
return L_14 ;
case 0x1001 :
return L_15 ;
case 0x1002 :
return L_16 ;
case 0x1003 :
return L_17 ;
case 0x1004 :
return L_18 ;
case 0x1005 :
return L_19 ;
case 0x1006 :
return L_20 ;
case 0x1007 :
return L_21 ;
case 0x1008 :
return L_22 ;
case 0x1009 :
return L_23 ;
case 0x100A :
return L_24 ;
case 0x100B :
return L_25 ;
case 0x1101 :
return L_26 ;
case 0x1102 :
return L_27 ;
case 0x1103 :
return L_28 ;
case 0x1104 :
return L_29 ;
case 0x1105 :
return L_30 ;
case 0x1106 :
return L_31 ;
case 0x1107 :
return L_32 ;
case 0x1108 :
return L_33 ;
case 0x1109 :
return L_23 ;
case 0x110A :
return L_24 ;
case 0x110B :
return L_25 ;
case 0x2001 :
return L_34 ;
case 0x2002 :
return L_35 ;
case 0x2003 :
return L_36 ;
case 0x2004 :
return L_37 ;
case 0x2005 :
return L_38 ;
case 0x2006 :
return L_39 ;
case 0x2007 :
return L_40 ;
case 0x3001 :
return L_41 ;
case 0x3002 :
return L_42 ;
case 0x3003 :
return L_43 ;
case 0x3004 :
return L_44 ;
case 0x3005 :
return L_45 ;
case 0x3006 :
return L_46 ;
case 0x3007 :
return L_47 ;
case 0x3008 :
return L_48 ;
case 0x3009 :
return L_49 ;
case 0x300A :
return L_50 ;
case 0x300B :
return L_51 ;
case 0x300C :
return L_52 ;
case 0x300D :
return L_53 ;
case 0x3301 :
return L_54 ;
case 0x3302 :
return L_55 ;
case 0x3303 :
return L_56 ;
case 0x3304 :
return L_57 ;
case 0x3311 :
return L_58 ;
case 0x3312 :
return L_59 ;
case 0x3313 :
return L_60 ;
case 0x3314 :
return L_61 ;
case 0x3315 :
return L_62 ;
case 0x3316 :
return L_63 ;
case 0x3317 :
return L_64 ;
case 0x3318 :
return L_65 ;
case 0x3319 :
return L_66 ;
case 0x3481 : return L_67 ;
case 0x3482 : return L_68 ;
case 0x3483 : return L_69 ;
case 0x3486 : return L_70 ;
case 0x3487 :
return L_71 ;
case 0x3490 : return L_72 ;
case 0x3491 : return L_73 ;
case 0x3492 : return L_74 ;
case 0x3493 : return L_75 ;
case 0x3495 : return L_76 ;
case 0x3496 : return L_77 ;
case 0x349A : return L_78 ;
case 0x349B : return L_79 ;
case 0x349C : return L_80 ;
case 0x349D : return L_81 ;
case 0x349E : return L_82 ;
case 0x349F : return L_83 ;
case 0x34A2 : return L_84 ;
case 0x34A6 : return L_85 ;
case 0x34A9 : return L_86 ;
case 0x34AA : return L_87 ;
case 0x34AB : return L_88 ;
case 0x34AC : return L_89 ;
case 0x34AF : return L_90 ;
case 0x34B1 : return L_91 ;
case 0x34B2 : return L_92 ;
case 0x34B9 : return L_93 ;
case 0x34BA : return L_94 ;
case 0x34BF : return L_95 ;
case 0x34C1 : return L_96 ;
case 0x34C2 : return L_97 ;
case 0x34C5 : return L_98 ;
case 0x34C6 : return L_99 ;
case 0x34CF : return L_100 ;
case 0x34D1 : return L_101 ;
case 0x34D2 : return L_102 ;
case 0x34D3 : return L_103 ;
case 0x34D4 : return L_104 ;
case 0x34D5 : return L_105 ;
case 0x34D6 : return L_106 ;
case 0x34D8 : return L_107 ;
case 0x34DB : return L_108 ;
case 0x34DF : return L_109 ;
case 0x34E0 : return L_110 ;
case 0x34E1 : return L_111 ;
case 0x34E2 : return L_112 ;
case 0x34E3 : return L_113 ;
case 0x34E4 : return L_114 ;
case 0x34E5 : return L_115 ;
case 0x34E6 : return L_116 ;
case 0x34EF : return L_117 ;
case 0x34FF : return L_118 ;
default: return L_119 ;
}
#endif
}
static void F_44 ( T_8 * V_53 )
{
T_5 * V_30 = F_12 ( V_53 -> V_85 . V_86 & 0x7f ) ;
if ( ! V_30 ) {
F_20 ( V_44 L_120 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 & 0x7f ) ;
return;
}
switch ( F_46 ( V_53 -> V_87 , V_53 -> V_88 ) ) {
case V_89 :
if ( V_62 )
F_20 ( V_63 L_121 ,
V_30 -> V_29 , V_53 -> V_90 , F_42 ( V_53 -> V_90 ) , V_30 -> V_91 ) ;
if ( V_53 -> V_90 ) {
F_35 ( V_30 , V_92 ) ;
} else if ( V_30 -> V_91 == 0 ) {
F_35 ( V_30 , V_93 ) ;
} else {
F_35 ( V_30 , V_94 ) ;
}
break;
case V_95 :
if ( V_53 -> V_96 == 0x214D5641
&& V_53 -> V_97 == 0
&& V_53 -> V_98 == 1 ) {
T_4 * V_99 = V_53 -> V_100 + 3 ;
T_3 V_49 = V_53 -> V_100 [ 0 ] ;
T_3 V_101 ;
int V_102 ;
if ( V_49 == 255 ) {
V_49 = ( V_53 -> V_100 [ 1 ] | ( V_53 -> V_100 [ 2 ] << 8 ) ) ;
V_99 += 2 ;
}
V_49 -= 2 ;
V_101 = ( ( * ( V_99 - 1 ) ) << 8 ) | * ( V_99 - 2 ) ;
if ( V_101 & 0x300 )
V_102 = ( V_101 & 0x200 ) ? 0 : 1 ;
else V_102 = ( V_101 & 0x800 ) ? 0 : 1 ;
if ( V_101 & 0x0C00 ) {
if ( ( V_101 & 0xff ) == 0x80 ) {
F_47 ( V_30 , V_102 , 1 , V_99 , V_49 ) ;
break;
}
} else if ( ( V_101 & 0xff ) < 0x80 ) {
F_47 ( V_30 , V_102 , 0 , V_99 , V_49 ) ;
break;
}
F_20 ( V_103 L_122 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 , V_101 ) ;
break;
}
goto V_104;
case V_105 :
if ( V_53 -> V_96 == 0x214D5641 ) {
char * V_106 = NULL ;
switch ( V_53 -> V_97 ) {
case 0 : break;
case 1 : V_106 = L_123 ; break;
case 2 : V_106 = L_124 ; break;
default: V_106 = L_125 ; break;
}
if ( V_106 )
F_20 ( V_103 L_126 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 ,
V_53 -> V_98 , V_106 ) ;
break;
}
goto V_104;
case V_107 :
goto V_104;
case V_108 :
goto V_104;
case V_109 :
goto V_104;
case V_110 :
goto V_104;
default:
F_20 ( V_44 L_127 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 ) ;
}
return;
V_104:
F_20 ( V_103 L_128 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 ) ;
}
static void F_48 ( T_5 * V_30 , T_8 * V_53 )
{
T_6 * V_32 ;
T_11 * V_111 ;
T_10 V_65 ;
int V_31 ;
if ( ( V_31 = F_41 ( V_30 ) ) == - 1 ) {
F_20 ( V_44 L_129 , V_30 -> V_29 ) ;
return;
}
V_111 = & V_30 -> V_39 [ V_31 ] ;
if ( ( V_32 = F_13 ( V_30 , V_31 ) ) == NULL ) {
F_20 ( V_44 L_130 , V_30 -> V_29 ) ;
return;
}
V_111 -> V_43 = 1 ;
V_32 -> V_36 = V_53 -> V_85 . V_112 ;
F_37 ( V_30 , V_32 , V_113 ) ;
V_65 . V_66 = V_114 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_31 ;
memset ( & V_65 . V_115 . V_116 , 0 , sizeof( V_65 . V_115 . V_116 ) ) ;
strncpy ( V_65 . V_115 . V_116 . V_117 ,
V_53 -> V_118 + 3 ,
V_53 -> V_118 [ 0 ] - 2 ) ;
strncpy ( V_65 . V_115 . V_116 . V_119 ,
V_53 -> V_120 + 2 ,
V_53 -> V_120 [ 0 ] - 1 ) ;
V_65 . V_115 . V_116 . V_15 = F_7 ( V_53 -> V_121 ) ;
V_65 . V_115 . V_116 . V_16 = F_8 ( V_53 -> V_121 ) ;
V_65 . V_115 . V_116 . V_122 = V_53 -> V_118 [ 1 ] ;
V_65 . V_115 . V_116 . V_123 = V_53 -> V_118 [ 2 ] ;
F_20 ( V_103 L_131 ,
V_30 -> V_29 ,
V_65 . V_115 . V_116 . V_117 ,
V_65 . V_115 . V_116 . V_15 ,
V_65 . V_115 . V_116 . V_16 ,
V_65 . V_115 . V_116 . V_119 ) ;
if ( V_65 . V_115 . V_116 . V_15 == 1 && V_65 . V_115 . V_116 . V_16 != 0 ) {
F_20 ( V_103 L_132 ,
V_30 -> V_29 ,
V_65 . V_115 . V_116 . V_16 ) ;
V_65 . V_115 . V_116 . V_16 = 0 ;
}
switch ( V_30 -> V_70 . V_71 ( & V_65 ) ) {
case 0 :
case 3 :
F_49 ( V_53 ) ;
V_53 -> V_124 = 1 ;
F_37 ( V_30 , V_32 , V_125 ) ;
F_28 ( V_30 , V_53 ) ;
F_20 ( V_103 L_133 ,
V_30 -> V_29 ,
V_65 . V_115 . V_116 . V_117 ,
V_65 . V_115 . V_116 . V_15 ,
V_65 . V_115 . V_116 . V_16 ,
V_65 . V_115 . V_116 . V_119 ) ;
break;
case 1 :
if ( V_32 -> V_34 == V_126 ) {
F_20 ( V_103 L_134 ,
V_30 -> V_29 ,
V_65 . V_115 . V_116 . V_117 ,
V_65 . V_115 . V_116 . V_15 ,
V_65 . V_115 . V_116 . V_16 ,
V_65 . V_115 . V_116 . V_119 ) ;
F_50 ( V_53 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_32 -> V_36 ,
NULL ,
NULL ,
NULL ,
NULL
) ;
V_32 -> V_37 = V_53 -> V_127 ;
F_28 ( V_30 , V_53 ) ;
} else {
F_20 ( V_103 L_135 ,
V_30 -> V_29 ,
V_65 . V_115 . V_116 . V_117 ,
V_65 . V_115 . V_116 . V_15 ,
V_65 . V_115 . V_116 . V_16 ,
V_65 . V_115 . V_116 . V_119 ) ;
}
break;
case 2 :
F_49 ( V_53 ) ;
V_53 -> V_124 = 2 ;
F_37 ( V_30 , V_32 , V_125 ) ;
F_28 ( V_30 , V_53 ) ;
break;
default:
F_49 ( V_53 ) ;
V_53 -> V_124 = 8 ;
F_37 ( V_30 , V_32 , V_125 ) ;
F_28 ( V_30 , V_53 ) ;
break;
}
return;
}
static void F_51 ( T_8 * V_53 )
{
T_5 * V_30 = F_12 ( V_53 -> V_85 . V_86 & 0x7f ) ;
T_6 * V_32 ;
T_10 V_65 ;
T_12 * V_128 ;
if ( ! V_30 ) {
F_20 ( V_44 L_120 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 & 0x7f ) ;
return;
}
switch ( F_46 ( V_53 -> V_87 , V_53 -> V_88 ) ) {
case V_129 :
if ( V_53 -> V_130 ) {
F_20 ( V_103 L_136 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_130 , F_42 ( V_53 -> V_130 ) , V_53 -> V_85 . V_112 ) ;
}
if ( ! ( V_32 = F_15 ( V_30 , V_53 -> V_85 . V_112 ) ) ) {
F_49 ( V_53 ) ;
F_28 ( V_30 , V_53 ) ;
goto V_131;
}
V_30 -> V_39 [ V_32 -> V_31 ] . V_42 = 1 ;
F_37 ( V_30 , V_32 , V_132 ) ;
F_49 ( V_53 ) ;
F_37 ( V_30 , V_32 , V_133 ) ;
F_28 ( V_30 , V_53 ) ;
break;
case V_134 :
if ( V_53 -> V_90 ) {
F_20 ( V_103 L_137 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ,
V_53 -> V_85 . V_112 ) ;
}
if ( ! ( V_32 = F_15 ( V_30 , V_53 -> V_85 . V_112 ) ) )
goto V_131;
V_30 -> V_39 [ V_32 -> V_31 ] . V_42 = 1 ;
break;
case V_135 :
if ( V_53 -> V_90 ) {
F_20 ( V_103 L_137 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ,
V_53 -> V_85 . V_112 ) ;
}
break;
case V_136 :
F_48 ( V_30 , V_53 ) ;
break;
case V_137 :
if ( V_53 -> V_90 ) {
F_20 ( V_103 L_137 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ,
V_53 -> V_85 . V_112 ) ;
}
if ( ! ( V_32 = F_16 ( V_30 , V_53 -> V_127 ) ) )
goto V_131;
V_32 -> V_36 = V_53 -> V_85 . V_112 ;
if ( V_53 -> V_90 ) {
F_37 ( V_30 , V_32 , V_138 ) ;
} else {
F_37 ( V_30 , V_32 , V_139 ) ;
}
break;
case V_140 :
if ( ! ( V_32 = F_15 ( V_30 , V_53 -> V_85 . V_112 ) ) )
goto V_131;
if ( V_30 -> V_39 [ V_32 -> V_31 ] . V_43 ) {
F_49 ( V_53 ) ;
F_37 ( V_30 , V_32 , V_141 ) ;
F_28 ( V_30 , V_53 ) ;
} else {
T_7 * V_45 ;
F_49 ( V_53 ) ;
F_28 ( V_30 , V_53 ) ;
V_45 = F_21 ( V_30 , V_32 , V_53 -> V_85 . V_112 ) ;
if ( ! V_45 ) {
F_20 ( V_44 L_138 , V_30 -> V_29 ) ;
break;
}
F_52 ( V_53 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_32 -> V_36 ,
NULL
) ;
V_45 -> V_37 = V_53 -> V_127 ;
F_37 ( V_30 , V_32 ,
V_141 ) ;
F_40 ( V_30 , V_45 , V_142 ) ;
F_28 ( V_30 , V_53 ) ;
V_65 . V_66 = V_143 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_32 -> V_31 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
}
break;
case V_109 :
if ( ! ( V_32 = F_15 ( V_30 , V_53 -> V_85 . V_112 ) ) )
goto V_131;
if ( V_53 -> V_144 == 0x4000 ) {
if ( V_53 -> V_145 [ 0 ] == 4 ) {
V_65 . V_66 = V_146 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_32 -> V_31 ;
sprintf ( V_65 . V_115 . V_147 , L_139 ,
( unsigned long )
( ( T_1 ) V_53 -> V_145 [ 1 ]
| ( ( T_1 ) ( V_53 -> V_145 [ 2 ] ) << 8 )
| ( ( T_1 ) ( V_53 -> V_145 [ 3 ] ) << 16 )
| ( ( T_1 ) ( V_53 -> V_145 [ 4 ] ) << 24 ) ) ) ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
break;
}
}
V_128 = F_53 ( V_53 ) ;
if ( V_128 ) {
F_20 ( V_148 L_140 ,
V_30 -> V_29 , V_128 -> V_14 ) ;
F_54 ( V_128 ) ;
} else
F_20 ( V_148 L_141 ,
V_30 -> V_29 , V_53 -> V_144 ) ;
break;
case V_149 :
goto V_104;
case V_150 :
goto V_104;
case V_107 :
goto V_104;
case V_108 :
goto V_104;
case V_110 :
goto V_104;
default:
F_20 ( V_44 L_142 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_112 ) ;
}
return;
V_104:
F_20 ( V_103 L_143 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_112 ) ;
return;
V_131:
F_20 ( V_44 L_144 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_112 ) ;
return;
}
static void F_55 ( T_8 * V_53 )
{
T_5 * V_30 = F_12 ( V_53 -> V_85 . V_86 & 0x7f ) ;
T_6 * V_32 ;
T_7 * V_45 ;
T_10 V_65 ;
int V_49 ;
if ( ! V_30 ) {
F_20 ( V_44 L_120 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 & 0x7f ) ;
return;
}
switch ( F_46 ( V_53 -> V_87 , V_53 -> V_88 ) ) {
case V_151 :
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) )
goto V_131;
F_49 ( V_53 ) ;
F_40 ( V_30 , V_45 , V_153 ) ;
F_28 ( V_30 , V_53 ) ;
V_65 . V_66 = V_154 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_45 -> V_31 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
F_20 ( V_103 L_145 ,
V_30 -> V_29 , V_45 -> V_31 , V_45 -> V_40 ) ;
break;
case V_155 :
goto V_104;
case V_156 :
V_32 = F_17 ( V_30 , V_53 -> V_85 . V_152 ) ;
if ( V_32 ) {
V_45 = F_21 ( V_30 , V_32 , V_53 -> V_85 . V_152 ) ;
if ( V_45 ) {
F_40 ( V_30 , V_45 , V_157 ) ;
F_56 ( V_53 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_45 -> V_40 ,
0 ,
NULL
) ;
F_40 ( V_30 , V_45 , V_158 ) ;
F_28 ( V_30 , V_53 ) ;
break;
}
F_20 ( V_44 L_138 , V_30 -> V_29 ) ;
} else {
F_20 ( V_44 L_146 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_152 ) ;
}
F_56 ( V_53 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_53 -> V_85 . V_152 ,
2 ,
NULL
) ;
F_28 ( V_30 , V_53 ) ;
break;
case V_159 :
if ( ! ( V_45 = F_23 ( V_30 ,
V_53 -> V_85 . V_152 ,
V_53 -> V_127 ) ) )
goto V_131;
V_45 -> V_40 = V_53 -> V_85 . V_152 ;
if ( V_53 -> V_90 ) {
F_20 ( V_103 L_147 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ,
V_53 -> V_85 . V_152 ) ;
}
if ( V_53 -> V_90 )
F_40 ( V_30 , V_45 , V_160 ) ;
else
F_40 ( V_30 , V_45 , V_161 ) ;
break;
case V_162 :
F_49 ( V_53 ) ;
F_28 ( V_30 , V_53 ) ;
break;
case V_163 :
goto V_104;
case V_164 :
if ( V_53 -> V_90 ) {
F_20 ( V_148 L_148 ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ) ;
}
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) )
goto V_131;
V_49 = F_27 ( V_45 , V_53 -> V_165 ) ;
if ( V_49 < 0 )
break;
V_65 . V_66 = V_166 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_45 -> V_31 ;
V_65 . V_115 . V_167 = V_49 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
break;
case V_168 :
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) )
goto V_131;
V_30 -> V_39 [ V_45 -> V_31 ] . V_42 = 1 ;
F_40 ( V_30 , V_45 , V_169 ) ;
F_49 ( V_53 ) ;
F_40 ( V_30 , V_45 , V_170 ) ;
F_28 ( V_30 , V_53 ) ;
break;
case V_171 :
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) )
goto V_131;
if ( V_53 -> V_90 ) {
F_20 ( V_103 L_147 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_90 , F_42 ( V_53 -> V_90 ) ,
V_53 -> V_85 . V_152 ) ;
F_40 ( V_30 , V_45 , V_172 ) ;
}
break;
case V_173 :
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) )
goto V_131;
F_40 ( V_30 , V_45 , V_174 ) ;
F_49 ( V_53 ) ;
F_28 ( V_30 , V_53 ) ;
break;
case V_175 :
goto V_104;
case V_107 :
goto V_104;
case V_108 :
goto V_104;
default:
F_20 ( V_44 L_149 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_152 ) ;
}
return;
V_104:
F_20 ( V_103 L_150 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_152 ) ;
return;
V_131:
F_20 ( V_44 L_151 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_152 ) ;
}
static void F_57 ( T_8 * V_53 , struct V_54 * V_55 )
{
T_5 * V_30 = F_12 ( V_53 -> V_85 . V_86 & 0x7f ) ;
T_7 * V_45 ;
if ( ! V_30 ) {
F_20 ( V_44 L_120 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_86 & 0x7f ) ;
F_34 ( V_55 ) ;
return;
}
if ( ! ( V_45 = F_22 ( V_30 , V_53 -> V_85 . V_152 ) ) ) {
F_20 ( V_44 L_151 ,
V_30 -> V_29 ,
F_45 ( V_53 -> V_87 , V_53 -> V_88 ) ,
V_53 -> V_85 . V_152 ) ;
F_34 ( V_55 ) ;
return;
}
( void ) F_58 ( V_55 , F_30 ( V_55 -> V_99 ) ) ;
V_30 -> V_70 . V_176 ( V_30 -> V_27 , V_45 -> V_31 , V_55 ) ;
F_49 ( V_53 ) ;
F_28 ( V_30 , V_53 ) ;
}
static void F_59 ( struct V_177 * V_56 , struct V_54 * V_55 )
{
if ( F_60 ( & V_178 , V_55 -> V_99 ) ) {
F_20 ( V_44 L_152 ,
V_56 -> V_75 ) ;
F_34 ( V_55 ) ;
return;
}
if ( V_62 > 3 ) {
T_12 * V_128 = F_53 ( & V_178 ) ;
if ( V_128 ) {
F_20 ( V_63 L_153 , V_179 ,
V_56 -> V_75 , V_128 -> V_14 ) ;
F_54 ( V_128 ) ;
} else
F_20 ( V_63 L_154 ,
V_179 , V_56 -> V_75 ,
F_45 ( V_178 . V_87 , V_178 . V_88 ) ) ;
}
if ( V_178 . V_87 == V_180
&& V_178 . V_88 == V_181 ) {
F_57 ( & V_178 , V_55 ) ;
return;
}
if ( ( V_178 . V_85 . V_86 & 0xffffff00 ) == 0 )
F_44 ( & V_178 ) ;
else if ( ( V_178 . V_85 . V_112 & 0xffff0000 ) == 0 )
F_51 ( & V_178 ) ;
else
F_55 ( & V_178 ) ;
F_34 ( V_55 ) ;
}
static void F_47 ( T_5 * V_30 ,
int V_182 , int V_183 , T_4 * V_99 , T_3 V_49 )
{
T_4 * V_22 , * V_184 ;
T_10 V_65 ;
if ( ! V_49 ) {
F_20 ( V_63 L_155 ,
V_30 -> V_29 , V_49 ) ;
return;
}
if ( V_183 ) {
F_61 ( V_30 , 'D' ) ;
F_61 ( V_30 , '2' ) ;
F_61 ( V_30 , V_182 ? '>' : '<' ) ;
F_61 ( V_30 , ':' ) ;
} else {
F_61 ( V_30 , 'D' ) ;
F_61 ( V_30 , '3' ) ;
F_61 ( V_30 , V_182 ? '>' : '<' ) ;
F_61 ( V_30 , ':' ) ;
}
for ( V_22 = V_99 , V_184 = V_99 + V_49 ; V_22 < V_184 ; V_22 ++ ) {
F_61 ( V_30 , ' ' ) ;
F_61 ( V_30 , F_62 ( * V_22 ) ) ;
F_61 ( V_30 , F_63 ( * V_22 ) ) ;
}
F_61 ( V_30 , '\n' ) ;
V_65 . V_66 = V_185 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_49 * 3 + 5 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
}
static int F_64 ( T_10 * V_186 , T_5 * V_30 )
{
switch ( V_186 -> V_69 ) {
case 1 :
V_62 = ( int ) ( * ( ( unsigned int * ) V_186 -> V_115 . V_147 ) ) ;
F_20 ( V_63 L_156 ,
V_30 -> V_29 , V_62 ) ;
return 0 ;
default:
F_20 ( V_63 L_157 ,
V_30 -> V_29 , V_186 -> V_69 ) ;
return - V_187 ;
}
return - V_187 ;
}
static int F_65 ( char * V_188 , unsigned long * V_189 , int * V_190 )
{
unsigned long V_191 = 0 ;
int V_192 = ! 0 ;
char * V_106 ;
int V_82 ;
if ( strncmp ( V_188 , L_158 , 3 ) != 0 )
return 1 ;
V_106 = V_188 + 3 ;
while ( * V_106 && * V_106 == ' ' ) V_106 ++ ;
if ( ! * V_106 ) return - 2 ;
if ( * V_106 == 'p' || * V_106 == 'P' ) {
V_192 = 0 ;
V_106 ++ ;
}
if ( * V_106 == 'a' || * V_106 == 'A' ) {
V_192 = ! 0 ;
V_106 ++ ;
}
while ( * V_106 ) {
int V_193 = 0 ;
int V_194 = 0 ;
char * V_195 ;
V_193 = F_66 ( V_106 , & V_195 , 10 ) ;
if ( V_106 == V_195 )
return - 3 ;
V_106 = V_195 ;
if ( V_193 <= 0 || V_193 > 30 ) return - 4 ;
if ( * V_106 == 0 || * V_106 == ',' || * V_106 == ' ' ) {
V_191 |= ( 1 << V_193 ) ;
V_193 = 0 ;
if ( * V_106 ) V_106 ++ ;
continue;
}
if ( * V_106 != '-' ) return - 5 ;
V_106 ++ ;
V_194 = F_66 ( V_106 , & V_195 , 10 ) ;
if ( V_106 == V_195 )
return - 3 ;
V_106 = V_195 ;
if ( V_194 <= 0 || V_194 > 30 ) return - 4 ;
if ( * V_106 == 0 || * V_106 == ',' || * V_106 == ' ' ) {
if ( V_193 > V_194 )
for ( V_82 = V_194 ; V_82 <= V_193 ; V_82 ++ )
V_191 |= ( 1 << V_82 ) ;
else
for ( V_82 = V_193 ; V_82 <= V_194 ; V_82 ++ )
V_191 |= ( 1 << V_82 ) ;
V_193 = V_194 = 0 ;
if ( * V_106 ) V_106 ++ ;
continue;
}
return - 6 ;
}
if ( V_190 ) * V_190 = V_192 ;
if ( V_189 ) * V_189 = V_191 ;
return 0 ;
}
static int F_67 ( char * V_188 , T_4 V_196 [ 1 + 2 + 2 + 31 ] )
{
unsigned long V_191 ;
int V_192 ;
int V_197 , V_82 ;
V_197 = F_65 ( V_188 , & V_191 , & V_192 ) ;
if ( V_197 ) return V_197 ;
V_196 [ 0 ] = 2 + 2 + 31 ;
V_196 [ 1 ] = 3 ; V_196 [ 2 ] = 0 ;
if ( V_192 ) {
V_196 [ 3 ] = 0 ; V_196 [ 4 ] = 0 ;
} else {
V_196 [ 3 ] = 1 ; V_196 [ 4 ] = 0 ;
}
V_196 [ 5 ] = 0 ;
for ( V_82 = 1 ; V_82 <= 30 ; V_82 ++ )
V_196 [ 5 + V_82 ] = ( V_191 & ( 1 << V_82 ) ) ? 0xff : 0 ;
return 0 ;
}
static int F_68 ( T_10 * V_186 , T_5 * V_30 )
{
T_10 V_65 ;
struct T_11 * V_111 ;
struct T_6 * V_32 ;
T_4 V_196 [ 1 + 2 + 2 + 31 ] ;
int V_197 , V_198 = 0 ;
if ( V_186 -> V_66 == V_199 )
return F_64 ( V_186 , V_30 ) ;
switch ( V_186 -> V_66 ) {
case V_200 : {
T_4 V_201 [ V_202 + 3 ] ;
T_4 V_203 [ V_202 + 2 ] ;
if ( V_62 )
F_20 ( V_63 L_159 ,
V_30 -> V_29 ,
V_186 -> V_69 ,
V_186 -> V_115 . V_116 . V_117 ,
V_186 -> V_115 . V_116 . V_15 ,
V_186 -> V_115 . V_116 . V_16 ,
V_186 -> V_115 . V_116 . V_119 ) ;
V_111 = & V_30 -> V_39 [ V_186 -> V_69 % V_30 -> V_83 ] ;
if ( V_111 -> V_32 ) {
F_20 ( V_44 L_160 ,
V_30 -> V_29 ,
V_186 -> V_69 ,
V_186 -> V_115 . V_116 . V_117 ,
V_186 -> V_115 . V_116 . V_15 ,
V_186 -> V_115 . V_116 . V_16 ,
V_186 -> V_115 . V_116 . V_119 ,
V_111 -> V_32 -> V_36 ) ;
return 0 ;
}
V_111 -> V_15 = V_186 -> V_115 . V_116 . V_15 ;
V_111 -> V_16 = V_186 -> V_115 . V_116 . V_16 ;
strncpy ( V_111 -> V_147 , V_186 -> V_115 . V_116 . V_117 , sizeof( V_111 -> V_147 ) ) ;
strncpy ( V_111 -> V_204 , V_186 -> V_115 . V_116 . V_119 , sizeof( V_111 -> V_204 ) ) ;
V_197 = F_67 ( V_111 -> V_147 , V_196 ) ;
V_198 = ( V_197 == 0 ) ;
if ( V_197 < 0 )
F_20 ( V_44 L_161 , V_30 -> V_29 , V_111 -> V_147 ) ;
if ( V_198 ) {
V_201 [ 0 ] = 0 ;
V_203 [ 0 ] = 0 ;
if ( V_62 )
F_20 ( V_63 L_162 , V_30 -> V_29 ) ;
} else {
V_201 [ 0 ] = strlen ( V_111 -> V_204 ) + 2 ;
V_201 [ 1 ] = 0 ;
V_201 [ 2 ] = 0x80 ;
strncpy ( V_201 + 3 , V_111 -> V_204 , V_202 ) ;
V_203 [ 0 ] = strlen ( V_111 -> V_147 ) + 1 ;
V_203 [ 1 ] = 0x80 ;
strncpy ( V_203 + 2 , V_111 -> V_147 , V_202 ) ;
}
F_69 ( & V_205 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_30 -> V_29 ,
F_6 ( V_111 -> V_15 , V_111 -> V_16 ) ,
V_203 ,
V_201 ,
NULL ,
NULL ,
F_1 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_2 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_3 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_5 ( V_111 -> V_1 , V_111 -> V_2 ) ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
V_198 ? V_196 : NULL ,
NULL ,
NULL ,
NULL
) ;
if ( ( V_32 = F_13 ( V_30 , ( V_186 -> V_69 % V_30 -> V_83 ) ) ) == NULL ) {
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = ( V_186 -> V_69 % V_30 -> V_83 ) ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
return - 1 ;
}
V_32 -> V_37 = V_205 . V_127 ;
V_32 -> V_206 = V_198 ;
F_37 ( V_30 , V_32 , V_207 ) ;
F_28 ( V_30 , & V_205 ) ;
return 0 ;
}
case V_208 :
V_111 = & V_30 -> V_39 [ V_186 -> V_69 % V_30 -> V_83 ] ;
if ( V_62 )
F_20 ( V_63 L_163 ,
V_30 -> V_29 ,
V_186 -> V_69 , V_111 -> V_1 , V_111 -> V_2 ) ;
F_70 ( & V_205 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_111 -> V_32 -> V_36 ,
0 ,
F_1 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_2 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_3 ( V_111 -> V_1 , V_111 -> V_2 ) ,
F_5 ( V_111 -> V_1 , V_111 -> V_2 ) ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL
) ;
if ( F_29 ( & V_205 , V_205 . V_14 ) ) {
F_20 ( V_44 L_164 ,
V_30 -> V_29 ) ;
return - V_187 ;
}
F_37 ( V_30 , V_111 -> V_32 , V_209 ) ;
F_28 ( V_30 , & V_205 ) ;
return 0 ;
case V_210 :
if ( V_62 )
F_20 ( V_63 L_165 ,
V_30 -> V_29 ,
V_186 -> V_69 ) ;
return - V_211 ;
case V_212 :
if ( V_62 )
F_20 ( V_63 L_166 ,
V_30 -> V_29 ,
V_186 -> V_69 ) ;
V_111 = & V_30 -> V_39 [ V_186 -> V_69 % V_30 -> V_83 ] ;
if ( V_111 -> V_42 ) {
if ( V_62 )
F_20 ( V_63 L_167 ,
V_30 -> V_29 ,
V_186 -> V_69 ) ;
return 0 ;
}
if ( V_111 -> V_45 ) {
V_111 -> V_42 = 1 ;
F_71 ( & V_205 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_111 -> V_45 -> V_40 ,
NULL
) ;
F_40 ( V_30 , V_111 -> V_45 , V_213 ) ;
F_28 ( V_30 , & V_205 ) ;
return 0 ;
} else if ( V_111 -> V_32 ) {
if ( V_111 -> V_32 -> V_34 == V_126 ) {
V_111 -> V_42 = 1 ;
return 0 ;
} else if ( V_111 -> V_32 -> V_36 ) {
V_111 -> V_42 = 1 ;
F_39 ( & V_205 ,
V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_111 -> V_32 -> V_36 ,
NULL ,
NULL ,
NULL ,
NULL
) ;
F_37 ( V_30 , V_111 -> V_32 , V_76 ) ;
F_28 ( V_30 , & V_205 ) ;
return 0 ;
} else {
F_20 ( V_44 L_168 ,
V_30 -> V_29 ,
V_186 -> V_69 ) ;
return - V_187 ;
}
}
F_20 ( V_44 L_169 ,
V_30 -> V_29 ,
V_186 -> V_69 ) ;
return - V_187 ;
case V_214 :
if ( V_62 )
F_20 ( V_63 L_170 ,
V_30 -> V_29 ,
( V_186 -> V_69 & 0xff ) , ( V_186 -> V_69 >> 8 ) ) ;
V_111 = & V_30 -> V_39 [ ( V_186 -> V_69 & 0xff ) % V_30 -> V_83 ] ;
V_111 -> V_1 = ( V_186 -> V_69 >> 8 ) ;
return 0 ;
case V_215 :
if ( V_62 )
F_20 ( V_63 L_171 ,
V_30 -> V_29 ,
( V_186 -> V_69 & 0xff ) , ( V_186 -> V_69 >> 8 ) ) ;
V_111 = & V_30 -> V_39 [ ( V_186 -> V_69 & 0xff ) % V_30 -> V_83 ] ;
V_111 -> V_2 = ( V_186 -> V_69 >> 8 ) ;
return 0 ;
case V_216 :
if ( V_62 )
F_20 ( V_63 L_172 ,
V_30 -> V_29 ,
V_186 -> V_115 . V_147 , V_186 -> V_69 ) ;
V_111 = & V_30 -> V_39 [ V_186 -> V_69 % V_30 -> V_83 ] ;
strncpy ( V_111 -> V_217 , V_186 -> V_115 . V_147 , V_202 ) ;
return 0 ;
case V_218 :
if ( V_62 )
F_20 ( V_63 L_173 ,
V_30 -> V_29 , V_186 -> V_69 ) ;
V_111 = & V_30 -> V_39 [ V_186 -> V_69 % V_30 -> V_83 ] ;
V_111 -> V_217 [ 0 ] = 0 ;
return 0 ;
default:
F_20 ( V_44 L_174 ,
V_30 -> V_29 , V_186 -> V_66 ) ;
return - V_187 ;
}
return 0 ;
}
static int F_72 ( T_10 * V_186 )
{
T_5 * V_30 = F_9 ( V_186 -> V_68 ) ;
if ( V_30 )
return F_68 ( V_186 , V_30 ) ;
F_20 ( V_44
L_175 ,
V_186 -> V_66 , V_186 -> V_68 ) ;
return - V_219 ;
}
static int F_73 ( int V_220 , int V_221 , int V_222 , struct V_54 * V_55 )
{
T_5 * V_30 = F_9 ( V_220 ) ;
T_11 * V_111 ;
T_7 * V_45 ;
int V_49 = V_55 -> V_49 ;
int V_223 ;
T_3 V_224 ;
T_3 V_47 ;
T_1 V_99 ;
if ( ! V_30 ) {
F_20 ( V_44 L_176 ,
V_220 ) ;
return 0 ;
}
if ( V_62 > 4 )
F_20 ( V_63 L_177 ,
V_30 -> V_29 , V_49 , V_55 , V_222 ) ;
V_111 = & V_30 -> V_39 [ V_221 % V_30 -> V_83 ] ;
V_45 = V_111 -> V_45 ;
if ( ! V_45 || V_45 -> V_34 != V_225 ) {
F_20 ( V_44 L_178 ,
V_30 -> V_29 , V_30 -> V_226 , V_221 ) ;
return 0 ;
}
V_47 = V_45 -> V_47 ;
#ifdef F_74
V_99 = 0 ;
#else
V_99 = ( unsigned long ) V_55 -> V_99 ;
#endif
F_75 ( & V_227 , V_24 . V_56 . V_75 , V_30 -> V_37 ++ ,
V_45 -> V_40 ,
V_99 ,
V_55 -> V_49 ,
V_47 ,
0
) ;
if ( F_25 ( V_45 , V_47 , V_222 ? ( int ) V_55 -> V_49 : - 1 ) < 0 )
return 0 ;
if ( F_29 ( & V_227 , V_227 . V_14 ) ) {
F_20 ( V_44 L_179 ,
V_30 -> V_29 ) ;
return - V_187 ;
}
V_223 = F_30 ( V_227 . V_14 ) ;
if ( F_76 ( V_55 ) < V_223 ) {
struct V_54 * V_228 = F_77 ( V_55 , V_223 ) ;
if ( ! V_228 ) {
F_20 ( V_44 L_180 ,
V_30 -> V_29 ) ;
( void ) F_27 ( V_45 , V_47 ) ;
return 0 ;
}
F_20 ( V_63 L_181 ,
V_30 -> V_29 , F_76 ( V_55 ) , V_223 ) ;
memcpy ( F_78 ( V_228 , V_223 ) , V_227 . V_14 , V_223 ) ;
V_224 = F_33 ( & V_24 . V_56 , V_228 ) ;
if ( V_224 == V_57 ) {
F_79 ( V_55 ) ;
V_45 -> V_47 ++ ;
return V_49 ;
}
if ( V_62 > 3 )
F_20 ( V_63 L_182 ,
V_30 -> V_29 , V_224 , F_42 ( V_224 ) ) ;
( void ) F_27 ( V_45 , V_47 ) ;
F_79 ( V_228 ) ;
return V_224 == V_229 ? 0 : - 1 ;
} else {
memcpy ( F_78 ( V_55 , V_223 ) , V_227 . V_14 , V_223 ) ;
V_224 = F_33 ( & V_24 . V_56 , V_55 ) ;
if ( V_224 == V_57 ) {
V_45 -> V_47 ++ ;
return V_49 ;
}
if ( V_62 > 3 )
F_20 ( V_63 L_182 ,
V_30 -> V_29 , V_224 , F_42 ( V_224 ) ) ;
F_58 ( V_55 , V_223 ) ;
( void ) F_27 ( V_45 , V_47 ) ;
return V_224 == V_229 ? 0 : - 1 ;
}
}
static int F_80 ( T_4 T_13 * V_14 , int V_49 , int V_220 , int V_221 )
{
T_5 * V_30 = F_9 ( V_220 ) ;
int V_230 ;
T_4 T_13 * V_22 ;
if ( ! V_30 ) {
F_20 ( V_44 L_183 ,
V_220 ) ;
return - V_219 ;
}
for ( V_22 = V_14 , V_230 = 0 ; V_230 < V_49 ; V_22 ++ , V_230 ++ ) {
if ( F_81 ( * V_30 -> V_231 ++ , V_22 ) )
return - V_232 ;
if ( V_30 -> V_231 > V_30 -> V_233 )
V_30 -> V_231 = V_30 -> V_234 ;
}
return V_230 ;
}
static void F_82 ( T_5 * V_30 )
{
T_4 V_235 [ V_236 ] ;
T_14 V_237 ;
T_3 V_28 = V_30 -> V_29 ;
T_3 V_224 ;
T_3 V_238 [ 3 ] ;
V_224 = F_83 ( V_28 , V_235 ) ;
if ( V_224 != V_57 ) {
F_20 ( V_44 L_184 ,
V_30 -> V_226 , V_224 ) ;
return;
}
if ( strstr ( V_235 , L_185 ) == NULL ) {
F_20 ( V_44 L_186 ,
V_30 -> V_226 , V_235 ) ;
return;
}
V_224 = F_84 ( V_28 , & V_237 ) ;
if ( V_224 != V_57 ) {
F_20 ( V_44 L_187 ,
V_30 -> V_226 , V_224 ) ;
return;
}
V_238 [ 0 ] = ( V_237 . V_239 >> 4 ) & 0x0f ;
V_238 [ 1 ] = ( V_237 . V_239 << 4 ) & 0xf0 ;
V_238 [ 1 ] |= ( V_237 . V_240 >> 4 ) & 0x0f ;
V_238 [ 2 ] |= V_237 . V_240 & 0x0f ;
if ( V_238 [ 0 ] > 3 || ( V_238 [ 0 ] == 3 && V_238 [ 1 ] > 5 ) ) {
F_20 ( V_103 L_188 , V_30 -> V_226 ) ;
F_85 ( & V_205 , V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_28 ,
0x214D5641 ,
0 ,
1 ,
( T_2 ) L_189 ) ;
} else {
F_20 ( V_103 L_190 , V_30 -> V_226 ) ;
F_85 ( & V_205 , V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_28 ,
0x214D5641 ,
0 ,
1 ,
( T_2 ) L_191 ) ;
}
F_28 ( V_30 , & V_205 ) ;
}
static void F_86 ( T_5 * V_30 )
{
F_87 ( & V_205 , V_24 . V_56 . V_75 ,
V_30 -> V_37 ++ ,
V_30 -> V_29 ,
1 << 6 ,
V_30 -> V_91 ,
V_30 -> V_241 ,
NULL , NULL ) ;
F_35 ( V_30 , V_242 ) ;
F_28 ( V_30 , & V_205 ) ;
}
static void F_88 ( unsigned long V_243 )
{
T_5 * V_30 = ( T_5 * ) V_243 ;
if ( V_30 -> V_34 != V_244 && V_30 -> V_34 != V_245 )
F_20 ( V_44 L_192 , V_30 -> V_226 ) ;
F_86 ( V_30 ) ;
F_89 ( & V_30 -> V_246 , V_247 + 60 * V_248 ) ;
}
static int F_90 ( T_3 V_28 , struct V_249 * V_250 )
{
T_5 * V_30 ;
unsigned long V_21 ;
T_10 V_65 ;
char V_220 [ 20 ] ;
int V_82 ;
sprintf ( V_220 , L_193 , V_28 ) ;
if ( ! F_91 ( V_251 ) ) {
F_20 ( V_148 L_194 , V_220 ) ;
return - 1 ;
}
if ( ! ( V_30 = F_14 ( sizeof( T_5 ) , V_33 ) ) ) {
F_20 ( V_148
L_195 , V_220 ) ;
return - 1 ;
}
V_30 -> V_252 = V_251 ;
F_92 ( & V_30 -> V_246 , F_88 , ( unsigned long ) V_30 ) ;
strcpy ( V_30 -> V_226 , V_220 ) ;
V_30 -> V_29 = V_28 ;
V_30 -> V_83 = V_250 -> V_253 ;
V_30 -> V_39 = F_26 ( sizeof( T_11 ) * V_30 -> V_83 , V_33 ) ;
if ( ! V_30 -> V_39 ) {
F_20 ( V_148
L_196 , V_220 ) ;
F_93 ( V_30 -> V_252 ) ;
F_19 ( V_30 ) ;
return - 1 ;
}
V_30 -> V_70 . V_254 = V_250 -> V_253 ;
V_30 -> V_70 . V_255 = 2048 ;
V_30 -> V_70 . V_66 = F_72 ;
V_30 -> V_70 . V_256 = F_73 ;
V_30 -> V_70 . V_257 = NULL ;
V_30 -> V_70 . V_258 = F_80 ;
V_30 -> V_70 . V_259 =
V_260 |
V_261 |
V_262 |
V_263 |
V_264 |
V_265 |
V_266 ;
if ( V_250 -> V_267 & ( 1 << 2 ) )
V_30 -> V_70 . V_259 |=
V_268 |
V_269 |
V_270 ;
if ( V_250 -> V_267 & ( 1 << 8 ) )
V_30 -> V_70 . V_259 |= V_271 ;
V_30 -> V_70 . V_272 = 22 ;
strncpy ( V_30 -> V_70 . V_220 , V_220 , sizeof( V_30 -> V_70 . V_220 ) - 1 ) ;
V_30 -> V_231 = V_30 -> V_234 ;
V_30 -> V_273 = V_30 -> V_234 ;
V_30 -> V_233 = V_30 -> V_234 + sizeof( V_30 -> V_234 ) - 1 ;
if ( ! F_94 ( & V_30 -> V_70 ) ) {
F_20 ( V_44 L_197 , V_220 ) ;
F_19 ( V_30 -> V_39 ) ;
F_93 ( V_30 -> V_252 ) ;
F_19 ( V_30 ) ;
return - 1 ;
}
V_30 -> V_27 = V_30 -> V_70 . V_254 ;
memset ( V_30 -> V_39 , 0 , sizeof( T_11 ) * V_30 -> V_83 ) ;
for ( V_82 = 0 ; V_82 < V_30 -> V_83 ; V_82 ++ ) {
V_30 -> V_39 [ V_82 ] . V_28 = V_30 ;
}
F_10 ( & V_23 , V_21 ) ;
V_30 -> V_26 = V_24 . V_25 ;
V_24 . V_25 = V_30 ;
V_24 . V_274 ++ ;
F_11 ( & V_23 , V_21 ) ;
V_65 . V_66 = V_275 ;
V_65 . V_68 = V_30 -> V_27 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
V_30 -> V_91 = 0x1FFF03FF ;
V_30 -> V_241 = 0 ;
F_86 ( V_30 ) ;
F_89 ( & V_30 -> V_246 , V_247 + 60 * V_248 ) ;
F_20 ( V_103 L_198 ,
V_30 -> V_226 , V_30 -> V_83 ) ;
F_82 ( V_30 ) ;
return 0 ;
}
static int F_95 ( T_3 V_28 )
{
T_5 * * V_41 , * V_30 ;
unsigned long V_21 ;
T_10 V_65 ;
F_10 ( & V_23 , V_21 ) ;
for ( V_30 = V_24 . V_25 ; V_30 ; V_30 = V_30 -> V_26 ) {
if ( V_30 -> V_29 == V_28 )
break;
}
if ( ! V_30 ) {
F_11 ( & V_23 , V_21 ) ;
F_20 ( V_44 L_199 , V_28 ) ;
return - 1 ;
}
F_11 ( & V_23 , V_21 ) ;
F_96 ( & V_30 -> V_246 ) ;
if ( V_62 )
F_20 ( V_63 L_200 ,
V_30 -> V_29 , V_30 -> V_27 ) ;
V_65 . V_66 = V_276 ;
V_65 . V_68 = V_30 -> V_27 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
while ( V_30 -> V_83 ) {
V_65 . V_66 = V_277 ;
V_65 . V_68 = V_30 -> V_27 ;
V_65 . V_69 = V_30 -> V_83 - 1 ;
V_65 . V_115 . V_147 [ 0 ] = 0 ;
if ( V_62 )
F_20 ( V_63 L_201 ,
V_30 -> V_29 , V_30 -> V_27 , V_65 . V_69 ) ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
if ( V_30 -> V_39 [ V_30 -> V_83 - 1 ] . V_45 )
F_24 ( V_30 , V_30 -> V_39 [ V_30 -> V_83 - 1 ] . V_45 ) ;
if ( V_30 -> V_39 [ V_30 -> V_83 - 1 ] . V_32 )
F_18 ( V_30 , V_30 -> V_39 [ V_30 -> V_83 - 1 ] . V_32 ) ;
if ( V_30 -> V_38 )
F_20 ( V_44 L_202 ) ;
V_30 -> V_83 -- ;
}
F_19 ( V_30 -> V_39 ) ;
V_30 -> V_39 = NULL ;
if ( V_62 )
F_20 ( V_63 L_203 ,
V_30 -> V_29 , V_30 -> V_27 ) ;
V_65 . V_66 = V_278 ;
V_65 . V_68 = V_30 -> V_27 ;
V_30 -> V_70 . V_71 ( & V_65 ) ;
if ( V_62 )
F_20 ( V_63 L_204 ,
V_30 -> V_29 , V_30 -> V_27 ) ;
F_10 ( & V_23 , V_21 ) ;
for ( V_41 = & V_24 . V_25 ; * V_41 ; V_41 = & ( * V_41 ) -> V_26 ) {
if ( * V_41 == V_30 ) {
* V_41 = ( * V_41 ) -> V_26 ;
V_30 -> V_26 = NULL ;
V_24 . V_274 -- ;
break;
}
}
F_11 ( & V_23 , V_21 ) ;
F_93 ( V_30 -> V_252 ) ;
F_20 ( V_103 L_205 , V_30 -> V_226 ) ;
F_19 ( V_30 ) ;
return 0 ;
}
static int
F_97 ( struct V_279 * V_280 , unsigned long V_281 , void * V_282 )
{
V_249 V_283 ;
T_1 V_28 = ( long ) V_282 ;
switch ( V_281 ) {
case V_284 :
F_20 ( V_103 L_206 , V_28 ) ;
if ( F_98 ( V_28 , & V_283 ) == V_57 )
( void ) F_90 ( V_28 , & V_283 ) ;
break;
case V_285 :
F_20 ( V_103 L_207 , V_28 ) ;
( void ) F_95 ( V_28 ) ;
break;
}
return V_286 ;
}
static int F_99 ( struct V_287 * V_288 , void * V_282 )
{
F_100 ( V_288 , L_208 ,
V_24 . V_56 . V_289 ,
V_24 . V_56 . V_290 ,
V_24 . V_56 . V_291 ,
V_24 . V_56 . V_292 ) ;
return 0 ;
}
static int F_101 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_102 ( V_294 , F_99 , NULL ) ;
}
static void T_15 F_103 ( void )
{
F_104 ( L_209 , 0 , NULL , & V_295 ) ;
}
static void T_16 F_105 ( void )
{
F_106 ( L_209 , NULL ) ;
}
static int T_15 F_107 ( void )
{
V_249 V_283 ;
T_1 V_274 , V_28 ;
T_3 V_224 ;
V_24 . V_56 . V_296 . V_297 = - 2 ;
V_24 . V_56 . V_296 . V_298 = 16 ;
V_24 . V_56 . V_296 . V_299 = 2048 ;
V_24 . V_56 . V_300 = F_59 ;
V_224 = F_108 ( & V_24 . V_56 ) ;
if ( V_224 ) {
return - V_301 ;
}
F_109 ( & V_302 ) ;
V_224 = F_98 ( 0 , & V_283 ) ;
if ( V_224 != V_57 ) {
F_110 ( & V_302 ) ;
F_111 ( & V_24 . V_56 ) ;
return - V_301 ;
}
V_274 = V_283 . V_303 ;
for ( V_28 = 1 ; V_28 <= V_274 ; V_28 ++ ) {
V_224 = F_98 ( V_28 , & V_283 ) ;
if ( V_224 != V_57 )
continue;
( void ) F_90 ( V_28 , & V_283 ) ;
}
F_103 () ;
return 0 ;
}
static void T_16 F_112 ( void )
{
F_110 ( & V_302 ) ;
F_111 ( & V_24 . V_56 ) ;
F_105 () ;
}
