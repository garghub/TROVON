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
V_3 = F_14 ( V_21 ) + V_30 ;
} else {
V_3 = V_2 -> V_23 -> V_33 + V_2 -> V_26 ;
V_19 = V_2 -> V_23 -> V_28 - V_2 -> V_26 ;
}
V_18 = V_2 -> V_23 -> V_34 == V_35
? F_4 ( V_2 , V_3 , V_19 )
: F_1 ( V_2 , V_3 , V_19 ) ;
if ( V_2 -> V_23 -> V_24 ) {
F_15 ( V_3 - V_30 ) ;
F_16 ( V_22 ) ;
}
if ( ! V_18 )
break;
V_2 -> V_26 += V_18 ;
V_4 -= V_18 ;
V_8 += V_18 ;
}
F_8 ( & V_6 -> V_7 , L_2 , V_4 ) ;
if ( ! V_4 && ( V_2 -> V_23 -> V_34 == V_35 ) ) {
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
unsigned char * V_33 ;
unsigned int V_28 , V_36 , V_37 ;
V_2 -> V_38 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_38 = 0 ;
V_33 = V_2 -> V_23 -> V_33 ;
V_2 -> V_39 = ! V_40 ;
if ( V_2 -> V_23 -> V_24 ) {
V_28 = V_2 -> V_23 -> V_25 . V_4 ;
if ( ! F_18 ( V_28 ) )
V_2 -> V_39 = 0 ;
} else {
V_28 = V_2 -> V_23 -> V_28 ;
V_2 -> V_39 = 0 ;
}
F_5 ( V_41 ,
V_6 -> V_12 + V_42 ) ;
F_5 ( V_43 ,
V_6 -> V_12 + V_44 ) ;
if ( V_2 -> V_39 ) {
if ( 1 != F_19 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_34 == V_45
? V_46
: V_47 ) ) {
V_2 -> V_23 -> error = - V_48 ;
return V_2 -> V_23 -> error ;
}
V_28 = F_20 ( & V_2 -> V_23 -> V_25 ) ;
F_5 ( F_21 ( V_28 ) - 2 ,
V_6 -> V_12 + V_49 ) ;
F_5 ( V_50 ,
V_6 -> V_12 + V_51 ) ;
V_37 = V_52 | ( 1 << 8 ) ;
if ( V_2 -> V_23 -> V_34 == V_35 )
V_37 |= V_53 ;
F_5 ( V_50 ,
V_6 -> V_12 + V_51 ) ;
F_5 ( F_22 ( & V_2 -> V_23 -> V_25 ) ,
V_6 -> V_12 + V_54 ) ;
F_5 ( V_37 , V_6 -> V_12 + V_55 ) ;
} else {
F_5 ( V_2 -> V_56 | V_57 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( V_58 ,
V_6 -> V_12 + V_51 ) ;
}
F_23 ( & V_2 -> V_59 , V_60 + V_2 -> V_61 ) ;
F_5 ( V_62 | F_2 ( V_6 -> V_12 + V_63 ) ,
V_6 -> V_12 + V_63 ) ;
V_2 -> V_23 -> error = 0 ;
V_37 = F_2 ( V_6 -> V_12 + V_17 ) ;
V_37 |= V_64 ;
if ( V_2 -> V_39 )
V_37 |= V_65 ;
else
V_37 &= ~ V_65 ;
F_5 ( V_37 , V_6 -> V_12 + V_17 ) ;
V_36 = ( V_2 -> V_23 -> V_66 & 0xf ) << 12 ;
V_36 |= V_28 ;
F_5 ( V_36 , V_6 -> V_12 + V_67 ) ;
F_8 ( & V_6 -> V_7 , L_3 , V_36 , V_37 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_68 * V_69 = F_25 ( V_6 ) ;
int V_70 ;
F_26 ( & V_2 -> V_59 ) ;
V_2 -> V_23 -> V_71 = F_2 ( V_6 -> V_12 + V_13 ) & 0xff ;
V_2 -> V_23 -> V_71 = ( V_2 -> V_23 -> V_71 & 1 )
| ( ( V_2 -> V_23 -> V_71 << 4 ) & 0xe0 ) ;
F_5 ( V_41 ,
V_6 -> V_12 + V_42 ) ;
F_5 ( V_72 , V_6 -> V_12 + V_55 ) ;
if ( V_2 -> V_39 ) {
F_27 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_34 == V_45
? V_46
: V_47 ) ;
}
F_5 ( ( ~ V_62 ) & F_2 ( V_6 -> V_12 + V_63 ) ,
V_6 -> V_12 + V_63 ) ;
F_8 ( & V_6 -> V_7 , L_4 ) ;
do {
V_70 = F_28 ( V_69 , & V_2 -> V_23 ) ;
} while ( ! V_70 && F_17 ( V_2 ) );
}
static int F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_23 -> error ) {
if ( ! ( V_2 -> V_38 & V_73 ) )
return 1 ;
if ( ! ( V_2 -> V_38 & V_74 ) )
return 1 ;
if ( V_2 -> V_23 -> V_75
&& ! ( V_2 -> V_38 & V_76 ) )
return 1 ;
}
return 0 ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned int V_77 = 0 , V_78 = 0 ;
int V_70 = 1 ;
F_31 ( & V_6 -> V_79 ) ;
V_2 = F_32 ( (struct V_68 * ) F_25 ( V_6 ) ) ;
V_77 = F_2 ( V_6 -> V_12 + V_80 ) ;
V_78 = F_2 ( V_6 -> V_12 + V_13 ) ;
F_8 ( & V_6 -> V_7 ,
L_5 ,
V_77 , V_78 , V_2 -> V_38 ) ;
if ( V_2 -> V_23 ) {
if ( V_2 -> V_39 && ( V_77 & 1 ) ) {
V_2 -> V_38 |= V_74 ;
V_70 = F_29 ( V_2 ) ;
}
if ( ! V_2 -> V_39 && ( V_77 & V_58 ) ) {
if ( ! F_7 ( V_2 ) ) {
V_2 -> V_38 |= V_74 ;
V_70 = F_29 ( V_2 ) ;
}
}
}
F_5 ( V_77 , V_6 -> V_12 + V_80 ) ;
if ( ! V_70 )
F_24 ( V_2 ) ;
F_33 ( & V_6 -> V_79 ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned int V_78 = 0 ;
int V_70 = 1 ;
F_31 ( & V_6 -> V_79 ) ;
V_2 = F_32 ( (struct V_68 * ) F_25 ( V_6 ) ) ;
V_78 = F_2 ( V_6 -> V_12 + V_13 ) ;
F_8 ( & V_6 -> V_7 , L_6 ,
V_78 , V_2 -> V_38 ) ;
if ( V_2 -> V_23 ) {
if ( V_78 & V_81 )
V_2 -> V_23 -> error = - V_82 ;
else if ( V_78 & V_83 )
V_2 -> V_23 -> error = - V_84 ;
if ( V_78 & V_85 )
V_2 -> V_38 |= V_73 ;
if ( V_78 & V_86 )
V_2 -> V_38 |= V_76 ;
V_70 = F_29 ( V_2 ) ;
}
F_5 ( V_64 | F_2 ( V_6 -> V_12 + V_17 ) ,
V_6 -> V_12 + V_17 ) ;
if ( ! V_70 )
F_24 ( V_2 ) ;
F_33 ( & V_6 -> V_79 ) ;
return;
}
static void F_35 ( unsigned long V_33 )
{
struct V_68 * V_69 = (struct V_68 * ) V_33 ;
struct V_1 * V_2 = F_32 ( V_69 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_22 ;
int V_70 ;
F_36 ( & V_6 -> V_79 , V_22 ) ;
if ( ! V_2 -> V_23 ) {
if ( V_2 -> V_87 ) {
do {
V_70 = F_28 ( V_69 , & V_2 -> V_23 ) ;
if ( ! V_70 )
V_2 -> V_23 -> error = - V_82 ;
} while ( ! V_70 );
F_37 ( & V_6 -> V_79 , V_22 ) ;
return;
}
do {
V_70 = F_28 ( V_69 , & V_2 -> V_23 ) ;
} while ( ! V_70 && F_17 ( V_2 ) );
}
F_37 ( & V_6 -> V_79 , V_22 ) ;
}
static void F_38 ( struct V_68 * V_69 )
{
return;
}
static void F_39 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_32 ( V_69 ) ;
F_40 ( & V_2 -> V_88 ) ;
}
static int F_41 ( struct V_68 * V_69 ,
enum V_89 V_90 ,
int V_91 )
{
struct V_1 * V_2 = F_32 ( V_69 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_90 ) {
case V_92 :
if ( V_91 == V_93 ) {
V_2 -> V_56 = V_94 | V_95 ;
F_5 ( V_96 , V_6 -> V_12 + V_17 ) ;
F_5 ( V_97 | V_64 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( 0xffffffff , V_6 -> V_12 + V_13 ) ;
} else if ( V_91 == V_98 ) {
F_5 ( V_97 | V_64 ,
V_6 -> V_12 + V_17 ) ;
F_5 ( 0xffffffff , V_6 -> V_12 + V_13 ) ;
} else
return - V_99 ;
break;
case V_100 :
if ( V_91 == V_101 ) {
V_2 -> V_56 = V_94 | V_95 ;
F_5 ( ( ~ V_102 )
& F_2 ( V_6 -> V_12 + V_63 ) ,
V_6 -> V_12 + V_63 ) ;
} else if ( V_91 == V_103 ) {
V_2 -> V_56 = 0 ;
F_5 ( V_102
| F_2 ( V_6 -> V_12 + V_63 ) ,
V_6 -> V_12 + V_63 ) ;
} else
return - V_99 ;
break;
} ;
return 0 ;
}
static void F_42 ( unsigned long V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_8 ( & V_2 -> V_7 -> V_7 , L_7 ,
F_2 ( V_2 -> V_7 -> V_12 + V_13 ) ) ;
F_43 ( V_104
L_8
L_9 ,
F_44 ( & V_2 -> V_7 -> V_7 ) , V_2 -> V_23 ? V_2 -> V_23 -> V_66 : 0 ,
V_2 -> V_38 ) ;
F_45 ( V_2 -> V_7 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_68 * V_69 ;
struct V_1 * V_2 ;
int V_70 = - V_105 ;
if ( ! ( V_106
& F_2 ( V_6 -> V_12 + V_107 ) ) ) {
F_43 ( V_108 L_10 ,
F_44 ( & V_6 -> V_7 ) ) ;
return V_70 ;
}
V_69 = F_47 ( sizeof( struct V_1 ) , & V_6 -> V_7 ) ;
if ( ! V_69 )
return - V_48 ;
V_2 = F_32 ( V_69 ) ;
F_48 ( V_6 , V_69 ) ;
V_2 -> V_7 = V_6 ;
V_2 -> V_61 = F_49 ( 1000 ) ;
F_50 ( & V_2 -> V_59 , F_42 , ( unsigned long ) V_2 ) ;
F_51 ( & V_2 -> V_88 , F_35 , ( unsigned long ) V_69 ) ;
V_69 -> V_109 = F_39 ;
V_69 -> V_110 = F_41 ;
V_6 -> V_111 = F_34 ;
V_6 -> V_112 = F_30 ;
if ( F_52 ( V_6 ) )
V_69 -> V_113 |= V_114 ;
V_70 = F_53 ( V_69 ) ;
if ( ! V_70 )
return 0 ;
F_54 ( V_69 ) ;
return V_70 ;
}
static void F_55 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = F_25 ( V_6 ) ;
struct V_1 * V_2 = F_32 ( V_69 ) ;
int V_70 = 0 ;
unsigned long V_22 ;
V_69 -> V_109 = F_38 ;
F_56 ( & V_2 -> V_88 ) ;
F_36 ( & V_6 -> V_79 , V_22 ) ;
V_2 -> V_87 = 1 ;
if ( V_2 -> V_23 ) {
F_26 ( & V_2 -> V_59 ) ;
F_5 ( V_41 ,
V_6 -> V_12 + V_42 ) ;
F_5 ( V_72 , V_6 -> V_12 + V_55 ) ;
if ( V_2 -> V_39 )
F_27 ( V_6 , & V_2 -> V_23 -> V_25 , 1 ,
V_2 -> V_23 -> V_34 == V_45
? V_47
: V_46 ) ;
V_2 -> V_23 -> error = - V_82 ;
do {
V_70 = F_28 ( V_69 , & V_2 -> V_23 ) ;
if ( ! V_70 )
V_2 -> V_23 -> error = - V_82 ;
} while ( ! V_70 );
}
F_37 ( & V_6 -> V_79 , V_22 ) ;
F_57 ( V_69 ) ;
F_54 ( V_69 ) ;
}
static int F_58 ( struct V_5 * V_6 , T_1 V_115 )
{
struct V_68 * V_69 = F_25 ( V_6 ) ;
F_59 ( V_69 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = F_25 ( V_6 ) ;
F_61 ( V_69 ) ;
return 0 ;
}
static int T_2 F_62 ( void )
{
return F_63 ( & V_116 ) ;
}
static void T_3 F_64 ( void )
{
F_65 ( & V_116 ) ;
}
