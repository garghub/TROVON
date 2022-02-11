static inline void F_1 ( void )
{
if ( V_1 ) {
V_2 = V_1 ;
V_1 = NULL ;
}
F_2 ( V_3 . V_4 ) ;
}
static inline void F_3 ( void )
{
if ( V_2 )
V_1 = V_2 ;
}
static T_1 F_4 ( const T_2 T_3 * V_5 , T_4 V_6 ,
T_2 V_7 [] , T_1 * V_8 , T_1 V_9 )
{
T_1 V_10 , V_11 ;
if ( ! V_3 . V_12 . V_13 ) {
void * V_14 = & V_7 [ * V_8 ] ;
V_10 = F_5 (unsigned long, userCount, frameLeft) & ~ 1 ;
V_11 = V_10 ;
if ( F_6 ( V_14 , V_5 , V_10 ) )
return - V_15 ;
} else {
T_2 * V_16 = & V_7 [ * V_8 >> 1 ] ;
T_2 * V_17 = V_16 + V_18 ;
V_10 = F_5 (unsigned long, userCount, frameLeft) >> 1 & ~ 1 ;
V_11 = V_10 * 2 ;
while ( V_10 > 0 ) {
if ( F_7 ( * V_16 ++ , V_5 ++ )
|| F_7 ( * V_17 ++ , V_5 ++ ) )
return - V_15 ;
V_10 -- ;
}
}
* V_8 += V_11 ;
return V_11 ;
}
static inline void F_8 ( void )
{
V_19 . V_20 [ 0 ] . V_21 = V_19 . V_20 [ 1 ] . V_21 = 0 ;
V_19 . V_20 [ 2 ] . V_21 = V_19 . V_20 [ 3 ] . V_21 = 0 ;
V_19 . V_22 = V_23 ;
F_3 () ;
}
static void * F_9 ( unsigned int V_24 , T_5 V_25 )
{
return F_10 ( ( long ) V_24 , L_1 ) ;
}
static void F_11 ( void * V_26 , unsigned int V_24 )
{
F_12 ( V_26 ) ;
}
static int T_6 F_13 ( void )
{
F_8 () ;
if ( F_14 ( V_27 , V_28 , 0 , L_2 ,
V_28 ) )
return 0 ;
return 1 ;
}
static void F_15 ( void )
{
F_8 () ;
F_16 ( V_27 , V_28 ) ;
}
static void F_17 ( void )
{
F_8 () ;
}
static void F_18 ( void )
{
int V_29 , V_30 ;
F_17 () ;
if ( V_3 . V_12 . V_31 )
V_29 = V_32 / V_3 . V_12 . V_31 - 1 ;
else
V_29 = V_33 ;
V_3 . V_34 = V_3 . V_12 ;
V_3 . V_35 = & V_36 ;
if ( V_29 < V_33 ) {
V_29 = V_33 ;
} else if ( V_29 > 65535 ) {
V_29 = 65535 ;
}
V_3 . V_34 . V_31 = V_32 / ( V_29 + 1 ) ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ )
V_19 . V_20 [ V_30 ] . V_37 = V_29 ;
V_38 = V_29 ;
}
static int F_19 ( int V_39 )
{
int V_24 ;
switch ( V_39 ) {
case V_40 :
return V_3 . V_12 . V_39 ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_24 = 8 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_24 = 16 ;
break;
default:
V_24 = 8 ;
V_39 = V_44 ;
}
V_3 . V_12 . V_39 = V_39 ;
V_3 . V_12 . V_24 = V_24 ;
if ( V_3 . V_49 == V_50 ) {
V_3 . V_51 . V_39 = V_39 ;
V_3 . V_51 . V_24 = V_3 . V_12 . V_24 ;
}
F_18 () ;
return V_39 ;
}
static int F_20 ( int V_52 )
{
V_3 . V_53 = F_21 ( V_52 & 0xff ) ;
V_19 . V_20 [ 0 ] . V_21 = V_3 . V_53 ;
V_3 . V_54 = F_21 ( ( V_52 & 0xff00 ) >> 8 ) ;
V_19 . V_20 [ 1 ] . V_21 = V_3 . V_54 ;
if ( V_3 . V_34 . V_24 == 16 ) {
if ( V_3 . V_53 == 64 && V_3 . V_54 == 64 ) {
V_19 . V_20 [ 2 ] . V_21 = 1 ;
V_19 . V_20 [ 3 ] . V_21 = 1 ;
} else {
V_19 . V_20 [ 2 ] . V_21 = 0 ;
V_19 . V_20 [ 3 ] . V_21 = 0 ;
}
}
return F_22 ( V_3 . V_53 ) |
( F_22 ( V_3 . V_54 ) << 8 ) ;
}
static int F_2 ( int V_4 )
{
V_3 . V_4 = V_4 ;
if ( V_4 < 50 )
V_55 . V_56 &= ~ 0x02 ;
else
V_55 . V_56 |= 0x02 ;
return V_4 ;
}
static void F_23 ( int V_57 )
{
T_2 * V_58 , * V_59 , * V_60 , * V_61 , * V_62 ;
T_7 V_24 ;
V_58 = V_63 . V_64 [ V_63 . V_65 ] ;
V_24 = ( V_63 . V_10 == V_57 ? V_63 . V_66
: V_63 . V_67 ) >> 1 ;
if ( V_3 . V_34 . V_13 ) {
V_59 = V_58 ;
V_60 = V_58 + V_18 ;
V_24 >>= 1 ;
} else {
V_59 = V_58 ;
V_60 = V_58 ;
}
F_1 () ;
V_19 . V_20 [ 0 ] . V_21 = V_3 . V_53 ;
V_19 . V_20 [ 1 ] . V_21 = V_3 . V_54 ;
if ( V_3 . V_34 . V_24 == 8 ) {
V_19 . V_20 [ 0 ] . V_68 = ( V_69 * ) F_24 ( V_59 ) ;
V_19 . V_20 [ 0 ] . V_70 = V_24 ;
V_19 . V_20 [ 1 ] . V_68 = ( V_69 * ) F_24 ( V_60 ) ;
V_19 . V_20 [ 1 ] . V_70 = V_24 ;
V_19 . V_22 = V_71 ;
} else {
V_24 >>= 1 ;
V_19 . V_20 [ 0 ] . V_68 = ( V_69 * ) F_24 ( V_59 ) ;
V_19 . V_20 [ 0 ] . V_70 = V_24 ;
V_19 . V_20 [ 1 ] . V_68 = ( V_69 * ) F_24 ( V_60 ) ;
V_19 . V_20 [ 1 ] . V_70 = V_24 ;
if ( V_3 . V_53 == 64 && V_3 . V_54 == 64 ) {
V_62 = V_59 + V_72 ;
V_61 = V_60 + V_72 ;
V_19 . V_20 [ 2 ] . V_21 = 1 ;
V_19 . V_20 [ 3 ] . V_21 = 1 ;
V_19 . V_20 [ 2 ] . V_68 = ( V_69 * ) F_24 ( V_61 ) ;
V_19 . V_20 [ 2 ] . V_70 = V_24 ;
V_19 . V_20 [ 3 ] . V_68 = ( V_69 * ) F_24 ( V_62 ) ;
V_19 . V_20 [ 3 ] . V_70 = V_24 ;
V_19 . V_22 = V_73 ;
} else {
V_19 . V_20 [ 2 ] . V_21 = 0 ;
V_19 . V_20 [ 3 ] . V_21 = 0 ;
V_19 . V_22 = V_71 ;
}
}
V_63 . V_65 = ( V_63 . V_65 + 1 ) % V_63 . V_74 ;
V_63 . V_75 |= V_76 ;
}
static void F_25 ( void )
{
int V_77 = 1 ;
V_19 . V_78 = V_79 ;
if ( V_63 . V_75 & V_76 ) {
V_19 . V_78 = V_80 | V_79 ;
return;
}
if ( V_63 . V_75 & V_81 )
V_77 = 2 ;
if ( V_63 . V_10 < V_77 ) {
V_19 . V_78 = V_80 | V_79 ;
return;
}
if ( V_63 . V_10 <= V_77 &&
V_63 . V_66 < V_63 . V_67 && ! V_63 . V_82 ) {
V_19 . V_78 = V_80 | V_79 ;
return;
}
F_23 ( V_77 ) ;
V_19 . V_78 = V_80 | V_79 ;
}
static T_8 V_28 ( int V_83 , void * V_84 )
{
int V_77 = 1 ;
V_19 . V_78 = V_79 ;
if ( ! V_63 . V_75 ) {
F_26 ( V_63 . V_85 ) ;
return V_86 ;
}
if ( V_63 . V_75 & V_81 ) {
V_63 . V_10 -- ;
F_26 ( V_63 . V_87 ) ;
}
if ( V_63 . V_75 & V_76 )
V_77 = 2 ;
V_63 . V_75 = ( V_63 . V_75 << 1 ) & V_88 ;
if ( ! V_63 . V_75 )
F_8 () ;
V_19 . V_78 = V_80 | V_79 ;
if ( V_63 . V_10 >= V_77 )
F_25 () ;
if ( ! V_63 . V_75 )
F_26 ( V_63 . V_85 ) ;
return V_86 ;
}
static void T_6 F_27 ( void )
{
V_3 . V_53 = 64 ;
V_3 . V_54 = 64 ;
V_19 . V_20 [ 0 ] . V_21 = V_3 . V_53 ;
V_19 . V_20 [ 3 ] . V_21 = 1 ;
V_19 . V_20 [ 1 ] . V_21 = V_3 . V_54 ;
V_19 . V_20 [ 2 ] . V_21 = 1 ;
V_3 . V_4 = 50 ;
}
static int F_28 ( T_9 V_89 , T_7 V_90 )
{
int V_91 ;
switch ( V_89 ) {
case V_92 :
return F_29 ( V_90 , V_93 | V_94 ) ;
case V_95 :
return F_29 ( V_90 , 0 ) ;
case V_96 :
return F_29 ( V_90 , V_93 ) ;
case V_97 :
return F_29 ( V_90 ,
F_22 ( V_3 . V_53 ) |
F_22 ( V_3 . V_54 ) << 8 ) ;
case V_98 :
F_30 ( V_90 , V_91 ) ;
return F_29 ( V_90 , F_31 ( V_91 ) ) ;
case V_99 :
return F_29 ( V_90 , V_3 . V_4 ) ;
case V_100 :
F_30 ( V_90 , V_91 ) ;
return F_29 ( V_90 , F_32 ( V_91 ) ) ;
}
return - V_101 ;
}
static int F_33 ( void )
{
V_18 = V_63 . V_67 >> 1 ;
V_72 = V_18 >> 1 ;
return 0 ;
}
static int F_34 ( char * V_102 , T_4 V_103 )
{
int V_104 = 0 ;
V_104 += sprintf ( V_102 + V_104 , L_3 ,
V_3 . V_53 ) ;
V_104 += sprintf ( V_102 + V_104 , L_4 ,
V_3 . V_54 ) ;
if ( V_104 >= V_103 ) {
F_35 ( V_105 L_5 ) ;
V_104 = V_103 ;
}
return V_104 ;
}
static int T_6 F_36 ( struct V_106 * V_107 )
{
V_3 . V_108 = V_109 ;
V_3 . V_108 . V_110 = V_111 ;
V_3 . V_108 . V_112 = V_113 ;
return F_37 () ;
}
static int T_10 F_38 ( struct V_106 * V_107 )
{
F_39 () ;
return 0 ;
}
