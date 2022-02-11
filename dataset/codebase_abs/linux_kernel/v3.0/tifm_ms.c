static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = 0 ;
while ( V_2 -> V_9 && V_4 ) {
V_3 [ V_8 ++ ] = V_2 -> V_10 & 0xff ;
V_2 -> V_10 >>= 8 ;
V_4 -- ;
V_2 -> V_9 -- ;
}
if ( ! V_4 )
return V_8 ;
while ( ! ( V_11 & F_2 ( V_6 -> V_12 + V_13 ) ) ) {
if ( V_4 < 4 )
break;
* ( unsigned int * ) ( V_3 + V_8 ) = F_3 ( V_6 -> V_12
+ V_14 ) ;
V_4 -= 4 ;
V_8 += 4 ;
}
if ( V_4
&& ! ( V_11 & F_2 ( V_6 -> V_12 + V_13 ) ) ) {
V_2 -> V_10 = F_2 ( V_6 -> V_12 + V_14 ) ;
for ( V_2 -> V_9 = 4 ; V_2 -> V_9 ; -- V_2 -> V_9 ) {
V_3 [ V_8 ++ ] = V_2 -> V_10 & 0xff ;
V_2 -> V_10 >>= 8 ;
V_4 -- ;
if ( ! V_4 )
break;
}
}
return V_8 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned char * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = 0 ;
if ( V_2 -> V_9 ) {
while ( V_2 -> V_9 < 4 && V_4 ) {
V_2 -> V_10 |= V_3 [ V_8 ++ ] << ( V_2 -> V_9 * 8 ) ;
V_2 -> V_9 ++ ;
V_4 -- ;
}
}
if ( V_2 -> V_9 == 4
&& ! ( V_15 & F_2 ( V_6 -> V_12 + V_13 ) ) ) {
F_5 ( V_16 | F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
F_5 ( V_2 -> V_10 , V_6 -> V_12 + V_14 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
} else if ( V_2 -> V_9 ) {
return V_8 ;
}
if ( ! V_4 )
return V_8 ;
while ( ! ( V_15 & F_2 ( V_6 -> V_12 + V_13 ) ) ) {
if ( V_4 < 4 )
break;
F_5 ( V_16 | F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
F_6 ( * ( unsigned int * ) ( V_3 + V_8 ) ,
V_6 -> V_12 + V_14 ) ;
V_4 -= 4 ;
V_8 += 4 ;
}
switch ( V_4 ) {
case 3 :
V_2 -> V_10 |= V_3 [ V_8 + 2 ] << 16 ;
V_2 -> V_9 ++ ;
case 2 :
V_2 -> V_10 |= V_3 [ V_8 + 1 ] << 8 ;
V_2 -> V_9 ++ ;
case 1 :
V_2 -> V_10 |= V_3 [ V_8 ] ;
V_2 -> V_9 ++ ;
}
V_8 += V_2 -> V_9 ;
return V_8 ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_4 ;
unsigned int V_8 ;
unsigned int V_18 , V_19 ;
unsigned char * V_3 ;
struct V_20 * V_21 ;
unsigned long V_22 = 0 ;
if ( V_2 -> V_23 -> V_24 ) {
V_4 = V_2 -> V_23 -> V_25 . V_4 - V_2 -> V_26 ;
V_8 = V_2 -> V_23 -> V_25 . V_27 + V_2 -> V_26 ;
} else {
V_4 = V_2 -> V_23 -> V_28 - V_2 -> V_26 ;
V_8 = 0 ;
}
F_8 ( & V_6 -> V_7 , L_1 , V_4 ,
V_2 -> V_26 ) ;
while ( V_4 ) {
unsigned int V_29 ( V_30 ) ;
if ( V_2 -> V_23 -> V_24 ) {
V_21 = F_9 ( F_10 ( & V_2 -> V_23 -> V_25 ) ,
V_8 >> V_31 ) ;
V_30 = F_11 ( V_8 ) ;
V_19 = V_32 - V_30 ;
V_19 = F_12 ( V_19 , V_4 ) ;
F_13 ( V_22 ) ;
V_3 = F_14 ( V_21 , V_33 ) + V_30 ;
} else {
V_3 = V_2 -> V_23 -> V_34 + V_2 -> V_26 ;
V_19 = V_2 -> V_23 -> V_28 - V_2 -> V_26 ;
}
V_18 = V_2 -> V_23 -> V_35 == V_36
? F_4 ( V_2 , V_3 , V_19 )
: F_1 ( V_2 , V_3 , V_19 ) ;
if ( V_2 -> V_23 -> V_24 ) {
F_15 ( V_3 - V_30 , V_33 ) ;
F_16 ( V_22 ) ;
}
if ( ! V_18 )
break;
V_2 -> V_26 += V_18 ;
V_4 -= V_18 ;
V_8 += V_18 ;
}
F_8 ( & V_6 -> V_7 , L_2 , V_4 ) ;
if ( ! V_4 && ( V_2 -> V_23 -> V_35 == V_36 ) ) {
if ( V_2 -> V_9 ) {
F_5 ( V_16
| F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
F_5 ( V_2 -> V_10 , V_6 -> V_12 + V_14 ) ;
}
F_5 ( V_16
| F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
F_5 ( 0 , V_6 -> V_12 + V_14 ) ;
} else {
F_2 ( V_6 -> V_12 + V_14 ) ;
}
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char * V_34 ;
unsigned int V_28 , V_37 , V_38 ;
V_2 -> V_39 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_39 = 0 ;
V_34 = V_2 -> V_23 -> V_34 ;
V_2 -> V_40 = ! V_41 ;
if ( V_2 -> V_23 -> V_24 ) {
V_28 = V_2 -> V_23 -> V_25 . V_4 ;
if ( ! F_18 ( V_28 ) )
V_2 -> V_40 = 0 ;
} else {
V_28 = V_2 -> V_23 -> V_28 ;
V_2 -> V_40 = 0 ;
}
F_5 ( V_42 ,
V_6 -> V_12 + V_43 ) ;
F_5 ( V_44 ,
V_6 -> V_12 + V_45 ) ;
if ( V_2 -> V_40 ) {
if ( 1 != F_19 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_35 == V_46
? V_47
: V_48 ) ) {
V_2 -> V_23 -> error = - V_49 ;
return V_2 -> V_23 -> error ;
}
V_28 = F_20 ( & V_2 -> V_23 -> V_25 ) ;
F_5 ( F_21 ( V_28 ) - 2 ,
V_6 -> V_12 + V_50 ) ;
F_5 ( V_51 ,
V_6 -> V_12 + V_52 ) ;
V_38 = V_53 | ( 1 << 8 ) ;
if ( V_2 -> V_23 -> V_35 == V_36 )
V_38 |= V_54 ;
F_5 ( V_51 ,
V_6 -> V_12 + V_52 ) ;
F_5 ( F_22 ( & V_2 -> V_23 -> V_25 ) ,
V_6 -> V_12 + V_55 ) ;
F_5 ( V_38 , V_6 -> V_12 + V_56 ) ;
} else {
F_5 ( V_2 -> V_57 | V_58 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( V_59 ,
V_6 -> V_12 + V_52 ) ;
}
F_23 ( & V_2 -> V_60 , V_61 + V_2 -> V_62 ) ;
F_5 ( V_63 | F_2 ( V_6 -> V_12 + V_64 ) ,
V_6 -> V_12 + V_64 ) ;
V_2 -> V_23 -> error = 0 ;
V_38 = F_2 ( V_6 -> V_12 + V_17 ) ;
V_38 |= V_65 ;
if ( V_2 -> V_40 )
V_38 |= V_66 ;
else
V_38 &= ~ V_66 ;
F_5 ( V_38 , V_6 -> V_12 + V_17 ) ;
V_37 = ( V_2 -> V_23 -> V_67 & 0xf ) << 12 ;
V_37 |= V_28 ;
F_5 ( V_37 , V_6 -> V_12 + V_68 ) ;
F_8 ( & V_6 -> V_7 , L_3 , V_37 , V_38 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_69 * V_70 = F_25 ( V_6 ) ;
int V_71 ;
F_26 ( & V_2 -> V_60 ) ;
V_2 -> V_23 -> V_72 = F_2 ( V_6 -> V_12 + V_13 ) & 0xff ;
V_2 -> V_23 -> V_72 = ( V_2 -> V_23 -> V_72 & 1 )
| ( ( V_2 -> V_23 -> V_72 << 4 ) & 0xe0 ) ;
F_5 ( V_42 ,
V_6 -> V_12 + V_43 ) ;
F_5 ( V_73 , V_6 -> V_12 + V_56 ) ;
if ( V_2 -> V_40 ) {
F_27 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_35 == V_46
? V_47
: V_48 ) ;
}
F_5 ( ( ~ V_63 ) & F_2 ( V_6 -> V_12 + V_64 ) ,
V_6 -> V_12 + V_64 ) ;
F_8 ( & V_6 -> V_7 , L_4 ) ;
do {
V_71 = F_28 ( V_70 , & V_2 -> V_23 ) ;
} while ( ! V_71 && F_17 ( V_2 ) );
}
static int F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_23 -> error ) {
if ( ! ( V_2 -> V_39 & V_74 ) )
return 1 ;
if ( ! ( V_2 -> V_39 & V_75 ) )
return 1 ;
if ( V_2 -> V_23 -> V_76
&& ! ( V_2 -> V_39 & V_77 ) )
return 1 ;
}
return 0 ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned int V_78 = 0 , V_79 = 0 ;
int V_71 = 1 ;
F_31 ( & V_6 -> V_80 ) ;
V_2 = F_32 ( (struct V_69 * ) F_25 ( V_6 ) ) ;
V_78 = F_2 ( V_6 -> V_12 + V_81 ) ;
V_79 = F_2 ( V_6 -> V_12 + V_13 ) ;
F_8 ( & V_6 -> V_7 ,
L_5 ,
V_78 , V_79 , V_2 -> V_39 ) ;
if ( V_2 -> V_23 ) {
if ( V_2 -> V_40 && ( V_78 & 1 ) ) {
V_2 -> V_39 |= V_75 ;
V_71 = F_29 ( V_2 ) ;
}
if ( ! V_2 -> V_40 && ( V_78 & V_59 ) ) {
if ( ! F_7 ( V_2 ) ) {
V_2 -> V_39 |= V_75 ;
V_71 = F_29 ( V_2 ) ;
}
}
}
F_5 ( V_78 , V_6 -> V_12 + V_81 ) ;
if ( ! V_71 )
F_24 ( V_2 ) ;
F_33 ( & V_6 -> V_80 ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned int V_79 = 0 ;
int V_71 = 1 ;
F_31 ( & V_6 -> V_80 ) ;
V_2 = F_32 ( (struct V_69 * ) F_25 ( V_6 ) ) ;
V_79 = F_2 ( V_6 -> V_12 + V_13 ) ;
F_8 ( & V_6 -> V_7 , L_6 ,
V_79 , V_2 -> V_39 ) ;
if ( V_2 -> V_23 ) {
if ( V_79 & V_82 )
V_2 -> V_23 -> error = - V_83 ;
else if ( V_79 & V_84 )
V_2 -> V_23 -> error = - V_85 ;
if ( V_79 & V_86 )
V_2 -> V_39 |= V_74 ;
if ( V_79 & V_87 )
V_2 -> V_39 |= V_77 ;
V_71 = F_29 ( V_2 ) ;
}
F_5 ( V_65 | F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
if ( ! V_71 )
F_24 ( V_2 ) ;
F_33 ( & V_6 -> V_80 ) ;
return;
}
static void F_35 ( unsigned long V_34 )
{
struct V_69 * V_70 = (struct V_69 * ) V_34 ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_22 ;
int V_71 ;
F_36 ( & V_6 -> V_80 , V_22 ) ;
if ( ! V_2 -> V_23 ) {
if ( V_2 -> V_88 ) {
do {
V_71 = F_28 ( V_70 , & V_2 -> V_23 ) ;
if ( ! V_71 )
V_2 -> V_23 -> error = - V_83 ;
} while ( ! V_71 );
F_37 ( & V_6 -> V_80 , V_22 ) ;
return;
}
do {
V_71 = F_28 ( V_70 , & V_2 -> V_23 ) ;
} while ( ! V_71 && F_17 ( V_2 ) );
}
F_37 ( & V_6 -> V_80 , V_22 ) ;
}
static void F_38 ( struct V_69 * V_70 )
{
return;
}
static void F_39 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
F_40 ( & V_2 -> V_89 ) ;
}
static int F_41 ( struct V_69 * V_70 ,
enum V_90 V_91 ,
int V_92 )
{
struct V_1 * V_2 = F_32 ( V_70 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_91 ) {
case V_93 :
if ( V_92 == V_94 ) {
V_2 -> V_57 = V_95 | V_96 ;
F_5 ( V_97 , V_6 -> V_12 + V_17 ) ;
F_5 ( V_98 | V_65 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( 0xffffffff , V_6 -> V_12 + V_13 ) ;
} else if ( V_92 == V_99 ) {
F_5 ( V_98 | V_65 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( 0xffffffff , V_6 -> V_12 + V_13 ) ;
} else
return - V_100 ;
break;
case V_101 :
if ( V_92 == V_102 ) {
V_2 -> V_57 = V_95 | V_96 ;
F_5 ( ( ~ V_103 )
& F_2 ( V_6 -> V_12 + V_64 ) ,
V_6 -> V_12 + V_64 ) ;
} else if ( V_92 == V_104 ) {
V_2 -> V_57 = 0 ;
F_5 ( V_103
| F_2 ( V_6 -> V_12 + V_64 ) ,
V_6 -> V_12 + V_64 ) ;
} else
return - V_100 ;
break;
} ;
return 0 ;
}
static void F_42 ( unsigned long V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_8 ( & V_2 -> V_7 -> V_7 , L_7 ,
F_2 ( V_2 -> V_7 -> V_12 + V_13 ) ) ;
F_43 ( V_105
L_8
L_9 ,
F_44 ( & V_2 -> V_7 -> V_7 ) , V_2 -> V_23 ? V_2 -> V_23 -> V_67 : 0 ,
V_2 -> V_39 ) ;
F_45 ( V_2 -> V_7 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
int V_71 = - V_106 ;
if ( ! ( V_107
& F_2 ( V_6 -> V_12 + V_108 ) ) ) {
F_43 ( V_109 L_10 ,
F_44 ( & V_6 -> V_7 ) ) ;
return V_71 ;
}
V_70 = F_47 ( sizeof( struct V_1 ) , & V_6 -> V_7 ) ;
if ( ! V_70 )
return - V_49 ;
V_2 = F_32 ( V_70 ) ;
F_48 ( V_6 , V_70 ) ;
V_2 -> V_7 = V_6 ;
V_2 -> V_62 = F_49 ( 1000 ) ;
F_50 ( & V_2 -> V_60 , F_42 , ( unsigned long ) V_2 ) ;
F_51 ( & V_2 -> V_89 , F_35 , ( unsigned long ) V_70 ) ;
V_70 -> V_110 = F_39 ;
V_70 -> V_111 = F_41 ;
V_6 -> V_112 = F_34 ;
V_6 -> V_113 = F_30 ;
if ( F_52 ( V_6 ) )
V_70 -> V_114 |= V_115 ;
V_71 = F_53 ( V_70 ) ;
if ( ! V_71 )
return 0 ;
F_54 ( V_70 ) ;
return V_71 ;
}
static void F_55 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_25 ( V_6 ) ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
int V_71 = 0 ;
unsigned long V_22 ;
V_70 -> V_110 = F_38 ;
F_56 ( & V_2 -> V_89 ) ;
F_36 ( & V_6 -> V_80 , V_22 ) ;
V_2 -> V_88 = 1 ;
if ( V_2 -> V_23 ) {
F_26 ( & V_2 -> V_60 ) ;
F_5 ( V_42 ,
V_6 -> V_12 + V_43 ) ;
F_5 ( V_73 , V_6 -> V_12 + V_56 ) ;
if ( V_2 -> V_40 )
F_27 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_35 == V_46
? V_48
: V_47 ) ;
V_2 -> V_23 -> error = - V_83 ;
do {
V_71 = F_28 ( V_70 , & V_2 -> V_23 ) ;
if ( ! V_71 )
V_2 -> V_23 -> error = - V_83 ;
} while ( ! V_71 );
}
F_37 ( & V_6 -> V_80 , V_22 ) ;
F_57 ( V_70 ) ;
F_54 ( V_70 ) ;
}
static int F_58 ( struct V_5 * V_6 , T_1 V_116 )
{
struct V_69 * V_70 = F_25 ( V_6 ) ;
F_59 ( V_70 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_25 ( V_6 ) ;
F_61 ( V_70 ) ;
return 0 ;
}
static int T_2 F_62 ( void )
{
return F_63 ( & V_117 ) ;
}
static void T_3 F_64 ( void )
{
F_65 ( & V_117 ) ;
}
