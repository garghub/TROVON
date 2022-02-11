static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x000c0000 , F_3 ( V_2 ) ) ;
F_2 ( 0x00000000 , F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_3 , F_6 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , const char * V_4 )
{
F_8 ( & V_2 -> V_5 -> V_6 , L_1 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_7 = V_8 ;
while ( V_7 -- ) {
if ( F_10 ( F_6 ( V_2 ) ) & V_9 ) {
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
return;
}
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_10 ) ;
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
}
static void F_12 ( struct V_11 * V_12 , int V_13 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
T_1 V_15 = 0 ;
if ( V_13 == - 1 ) {
V_15 = V_14 ;
} else if ( V_14 != - 1 ) {
if ( V_2 -> V_16 . V_17 & V_18 )
V_13 >>= 1 ;
if ( V_2 -> V_19 ) {
V_15 = V_13 & 0x0FFF ;
V_15 |= ( V_14 & 0xff ) << 16 ;
V_15 |= ( ( V_14 >> 8 ) & 0xff ) << 24 ;
if ( V_2 -> V_20 == V_21 ) {
T_1 V_22 ;
V_22 = ( V_14 >> 16 ) & 0xff ;
F_2 ( V_22 , F_14 ( V_2 ) ) ;
}
} else {
V_15 = V_13 ;
V_15 |= ( V_14 & 0xff ) << 8 ;
V_15 |= ( ( V_14 >> 8 ) & 0xff ) << 16 ;
V_15 |= ( ( V_14 >> 16 ) & 0xff ) << 24 ;
}
}
F_2 ( V_15 , F_15 ( V_2 ) ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_7 = V_8 ;
while ( V_7 -- ) {
T_1 V_23 ;
V_23 = F_17 ( F_18 ( V_2 ) ) >> 16 ;
if ( V_23 & 0xFF )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_10 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_24 , V_7 = V_8 ;
while ( V_7 -- ) {
V_24 = ( F_17 ( F_18 ( V_2 ) ) >> 16 ) & 0xFF ;
if ( V_24 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_10 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_7 = V_8 ;
int V_26 [ 4 ] ;
void T_2 * V_27 [ 4 ] ;
int V_28 ;
T_1 V_29 , V_30 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
while ( V_7 -- ) {
V_30 = F_17 ( F_18 ( V_2 ) ) >> 24 ;
if ( V_30 & 0xFF )
return 0 ;
if ( F_17 ( F_21 ( V_2 ) ) & V_31 )
return 1 ;
F_11 ( 1 ) ;
if ( ! ( F_17 ( F_21 ( V_2 ) ) & V_32 ) )
continue;
V_27 [ 0 ] = F_22 ( V_2 ) ;
V_27 [ 1 ] = F_23 ( V_2 ) ;
V_27 [ 2 ] = F_24 ( V_2 ) ;
V_27 [ 3 ] = F_25 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
V_29 = F_17 ( V_27 [ V_28 ] ) ;
if ( V_29 != V_33 && ! V_26 [ V_28 ] ) {
T_3 V_34 ;
int V_35 ;
if ( V_2 -> V_19 )
V_35 = ( 512 * V_25 ) +
( V_29 >> 16 ) ;
else
V_35 = V_29 >> 16 ;
V_34 = V_2 -> V_36 [ V_35 ] ;
V_2 -> V_36 [ V_35 ] = V_34 ^ ( V_29 & 0xFF ) ;
V_26 [ V_28 ] = 1 ;
}
}
F_2 ( 0 , F_21 ( V_2 ) ) ;
}
F_7 ( V_2 , V_10 ) ;
return 1 ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_7 = V_8 ;
T_1 V_24 ;
while ( V_7 -- ) {
V_24 = ( F_17 ( F_18 ( V_2 ) ) >> 24 ) & 0xFF ;
if ( V_24 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_10 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_37 )
{
unsigned long V_29 ;
unsigned long * V_38 = ( unsigned long * ) & V_2 -> V_36 [ V_37 ] ;
F_9 ( V_2 ) ;
V_29 = F_17 ( F_28 ( V_2 ) ) ;
* V_38 = F_29 ( V_29 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_39 , int V_37 )
{
int V_28 , V_40 ;
unsigned long * V_38 = ( unsigned long * ) & V_2 -> V_36 [ V_37 ] ;
void * V_41 = ( void * ) F_31 ( V_2 ) ;
V_40 = ( V_39 + 3 ) / 4 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
F_16 ( V_2 ) ;
V_38 [ V_28 ] = F_17 ( V_41 ) ;
V_38 [ V_28 ] = F_32 ( V_38 [ V_28 ] ) ;
}
}
static int F_33 ( struct V_1 * V_2 , T_3 * V_42 , int V_43 )
{
int V_28 ;
unsigned long * V_44 = ( unsigned long * ) V_42 ;
void * V_41 = ( void * ) F_34 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
if ( F_20 ( V_2 , V_43 ) )
return 1 ;
V_44 [ V_28 ] = F_17 ( V_41 ) ;
V_44 [ V_28 ] = F_32 ( V_44 [ V_28 ] ) ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , int V_39 , int V_37 )
{
int V_28 , V_40 ;
unsigned long * V_29 = ( unsigned long * ) & V_2 -> V_36 [ V_37 ] ;
void * V_41 = ( void * ) F_31 ( V_2 ) ;
V_40 = ( V_39 + 3 ) / 4 ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
F_19 ( V_2 ) ;
F_2 ( F_36 ( V_29 [ V_28 ] ) , V_41 ) ;
}
}
static void F_37 ( struct V_11 * V_12 , T_1 V_45 , T_1 V_46 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
T_1 V_47 = V_2 -> V_48 & ~ V_49 ;
T_1 V_50 , V_51 = 0 ;
if ( V_2 -> V_19 )
V_47 |= V_52 ;
else
V_47 &= ~ V_52 ;
V_50 = V_53 | V_54 ;
switch ( V_45 ) {
case V_55 :
V_51 = V_2 -> V_56 ;
V_50 |= V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
V_51 = V_2 -> V_20 ;
V_50 |= V_61 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_47 |= V_49 ;
break;
case V_62 :
V_50 &= ~ V_54 ;
break;
case V_63 :
V_51 = V_2 -> V_20 ;
V_50 |= V_57 | V_61 | V_64 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_47 |= V_49 ;
break;
case V_65 :
V_47 &= ~ V_52 ;
V_50 |= V_61 ;
V_51 = V_66 ;
break;
case V_67 :
case V_68 :
V_47 &= ~ V_52 ;
V_50 &= ~ ( V_54 | V_69 ) ;
break;
default:
break;
}
V_50 |= V_51 ;
F_2 ( V_47 , F_38 ( V_2 ) ) ;
F_2 ( V_50 , F_39 ( V_2 ) ) ;
F_2 ( V_46 , F_40 ( V_2 ) ) ;
}
static int F_41 ( struct V_11 * V_12 , struct V_70 * V_16 ,
T_3 * V_38 , int V_71 )
{
int V_28 , V_72 = V_16 -> V_73 . V_30 ;
int V_74 = V_16 -> V_73 . V_75 ;
int V_76 = V_16 -> V_73 . V_77 ;
T_3 * V_78 = V_38 ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
for ( V_28 = 0 ; V_76 ; V_76 -- , V_28 += V_74 , V_78 += V_72 )
V_16 -> V_79 ( V_12 , V_78 , V_72 ) ;
for ( V_28 = 0 ; V_76 ; V_76 -- , V_28 += V_74 , V_78 += V_72 ) {
if ( V_2 -> V_80 [ V_28 ] )
V_12 -> V_81 . V_82 ++ ;
else
V_12 -> V_81 . V_83 += 0 ;
}
return 0 ;
}
static void F_42 ( struct V_11 * V_12 , struct V_70 * V_16 ,
const T_3 * V_38 )
{
int V_28 , V_72 = V_16 -> V_73 . V_30 ;
int V_74 = V_16 -> V_73 . V_75 ;
int V_76 = V_16 -> V_73 . V_77 ;
const T_3 * V_78 = V_38 ;
for ( V_28 = 0 ; V_76 ; V_76 -- , V_28 += V_74 , V_78 += V_72 )
V_16 -> V_84 ( V_12 , V_78 , V_72 ) ;
}
static void F_43 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_43 , V_85 ;
if ( V_2 -> V_19 )
V_85 = 4 ;
else
V_85 = 1 ;
F_2 ( F_17 ( F_38 ( V_2 ) ) | V_86 | V_87 ,
F_38 ( V_2 ) ) ;
F_37 ( V_12 , V_58 ,
( V_88 << 8 ) | V_58 ) ;
for ( V_43 = 0 ; V_43 < V_85 ; V_43 ++ ) {
int V_89 ;
F_1 ( V_2 ) ;
F_2 ( F_17 ( F_39 ( V_2 ) ) | 1 , F_39 ( V_2 ) ) ;
F_2 ( V_14 << 2 | V_43 , F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , 512 , 512 * V_43 ) ;
V_89 = F_33 ( V_2 ,
& V_2 -> V_36 [ V_12 -> V_90 + 16 * V_43 ] ,
V_43 ) ;
if ( V_89 )
V_2 -> V_80 [ V_43 ] = 1 ;
F_2 ( 0x0 , F_21 ( V_2 ) ) ;
F_9 ( V_2 ) ;
}
F_2 ( F_17 ( F_38 ( V_2 ) ) & ~ ( V_86 | V_87 ) ,
F_38 ( V_2 ) ) ;
}
static void F_44 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
F_37 ( V_12 , V_58 ,
( V_88 << 8 ) | V_58 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_19 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < 16 * 3 ; V_28 ++ )
V_2 -> V_36 [ V_28 ] = 0xFF ;
F_12 ( V_12 , 3 * 528 + 512 , V_14 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , 16 , 16 * 3 ) ;
F_9 ( V_2 ) ;
} else {
F_12 ( V_12 , 512 , V_14 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , 16 , 0 ) ;
F_9 ( V_2 ) ;
}
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_28 , V_14 = V_2 -> V_91 ;
int V_43 , V_85 ;
if ( V_2 -> V_19 )
V_85 = 4 ;
else
V_85 = 1 ;
F_2 ( F_17 ( F_38 ( V_2 ) ) | V_86 , F_38 ( V_2 ) ) ;
F_37 ( V_12 , V_63 ,
( V_63 << 8 ) | V_62 ) ;
for ( V_43 = 0 ; V_43 < V_85 ; V_43 ++ ) {
F_1 ( V_2 ) ;
F_2 ( F_17 ( F_39 ( V_2 ) ) | 1 , F_39 ( V_2 ) ) ;
F_2 ( V_14 << 2 | V_43 , F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_35 ( V_2 , 512 , 512 * V_43 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_26 ( V_2 ) ;
F_2 ( 0xFFFFFFFF , F_34 ( V_2 ) ) ;
}
F_9 ( V_2 ) ;
}
F_2 ( F_17 ( F_38 ( V_2 ) ) & ~ V_86 , F_38 ( V_2 ) ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_14 = V_2 -> V_91 ;
int V_43 , V_85 ;
if ( V_2 -> V_19 ) {
V_43 = 3 ;
V_85 = 4 ;
} else {
V_43 = 0 ;
V_85 = 1 ;
}
F_37 ( V_12 , V_63 ,
( V_63 << 8 ) | V_62 ) ;
for (; V_43 < V_85 ; V_43 ++ ) {
F_1 ( V_2 ) ;
F_12 ( V_12 , V_43 * 528 + 512 , V_14 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_35 ( V_2 , 16 , 16 * V_43 ) ;
F_9 ( V_2 ) ;
}
}
static void F_47 ( struct V_11 * V_12 , unsigned int V_92 ,
int V_13 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
T_1 V_93 = 0 ;
F_48 ( & V_2 -> V_5 -> V_6 ) ;
V_2 -> V_94 = 0 ;
if ( V_92 != V_63 )
V_2 -> V_35 = 0 ;
switch ( V_92 ) {
case V_95 :
case V_58 :
if ( V_2 -> V_96 ) {
F_43 ( V_12 , V_14 ) ;
break;
}
if ( V_2 -> V_19 )
F_37 ( V_12 , V_92 , ( V_88 << 8 )
| V_92 ) ;
else
F_37 ( V_12 , V_92 , V_92 ) ;
F_12 ( V_12 , 0 , V_14 ) ;
V_2 -> V_94 = V_12 -> V_90 + V_12 -> V_97 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_13 >>= 1 ;
V_2 -> V_35 += V_13 ;
goto V_98;
case V_59 :
if ( V_2 -> V_96 ) {
F_44 ( V_12 , V_14 ) ;
break;
}
if ( V_2 -> V_19 ) {
F_37 ( V_12 , V_92 , ( V_88 << 8 )
| V_58 ) ;
F_12 ( V_12 , V_12 -> V_90 , V_14 ) ;
} else {
F_37 ( V_12 , V_92 , V_92 ) ;
F_12 ( V_12 , 0 , V_14 ) ;
}
V_2 -> V_94 = V_12 -> V_97 ;
goto V_98;
case V_60 :
if ( V_2 -> V_96 )
break;
if ( V_2 -> V_19 )
F_37 ( V_12 , V_92 , ( V_99 << 8 )
| V_92 ) ;
else
F_37 ( V_12 , V_92 , V_92 ) ;
F_12 ( V_12 , V_13 , 0 ) ;
V_2 -> V_94 = V_12 -> V_90 + V_12 -> V_97 - V_13 ;
goto V_98;
case V_65 :
F_37 ( V_12 , V_92 , V_92 ) ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_13 <<= 1 ;
F_12 ( V_12 , V_13 , 0 ) ;
V_2 -> V_94 = 8 ;
F_2 ( V_2 -> V_94 , F_18 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , V_2 -> V_94 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_55 :
V_2 -> V_100 = V_14 ;
break;
case V_101 :
F_37 ( V_12 , V_55 ,
( V_92 << 8 ) | V_55 ) ;
F_12 ( V_12 , - 1 , V_2 -> V_100 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_62 :
if ( ! V_2 -> V_19 ) {
if ( V_13 >= V_12 -> V_90 ) {
V_13 -= V_12 -> V_90 ;
V_93 = V_59 ;
} else if ( V_13 < 256 ) {
V_93 = V_58 ;
} else {
V_13 -= 256 ;
V_93 = V_95 ;
}
}
V_2 -> V_102 = V_13 ;
V_2 -> V_91 = V_14 ;
V_2 -> V_103 = V_93 ;
break;
case V_63 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_19 ) {
F_37 ( V_12 , V_62 ,
V_2 -> V_103 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_96 ) {
if ( V_2 -> V_102 == V_12 -> V_90 )
F_46 ( V_12 ) ;
else if ( ! V_2 -> V_102 )
F_45 ( V_12 ) ;
else
F_49 ( V_104 L_2 ) ;
break;
}
F_37 ( V_12 , V_92 , ( V_92 << 8 ) | V_62 ) ;
F_12 ( V_12 , V_2 -> V_102 , V_2 -> V_91 ) ;
F_2 ( V_2 -> V_35 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_35 ( V_2 , V_2 -> V_35 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_67 :
F_37 ( V_12 , V_92 , V_92 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
V_2 -> V_94 = 1 ;
F_2 ( V_2 -> V_94 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_27 ( V_2 , 0 ) ;
break;
case V_68 :
F_37 ( V_12 , V_92 , V_92 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_105;
V_98:
F_2 ( V_2 -> V_94 , F_18 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , V_2 -> V_94 , 0 ) ;
F_9 ( V_2 ) ;
V_105:
F_50 ( & V_2 -> V_5 -> V_6 ) ;
return;
}
static void F_51 ( struct V_11 * V_12 , int V_106 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_89 ;
switch ( V_106 ) {
case - 1 :
V_2 -> V_48 &= ~ V_107 ;
F_48 ( & V_2 -> V_5 -> V_6 ) ;
F_2 ( V_2 -> V_48 , F_38 ( V_2 ) ) ;
if ( V_2 -> V_108 ) {
F_52 ( & V_2 -> V_109 ) ;
V_2 -> V_108 = 0 ;
}
F_50 ( & V_2 -> V_5 -> V_6 ) ;
break;
case 0 :
V_2 -> V_48 |= V_107 ;
if ( ! V_2 -> V_108 ) {
V_89 = F_53 ( & V_2 -> V_5 -> V_6 ,
& V_2 -> V_109 , 100 ) ;
if ( V_89 < 0 )
F_8 ( & V_2 -> V_5 -> V_6 ,
L_3 , V_89 ) ;
V_2 -> V_108 = 1 ;
}
if ( V_2 -> V_110 ) {
F_48 ( & V_2 -> V_5 -> V_6 ) ;
F_2 ( V_111 , F_54 ( V_2 ) ) ;
F_50 ( & V_2 -> V_5 -> V_6 ) ;
}
break;
default:
F_55 () ;
}
}
static void F_56 ( struct V_11 * V_12 , const T_3 * V_38 , int V_24 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_28 , V_35 = V_2 -> V_35 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
V_2 -> V_36 [ V_35 + V_28 ] = V_38 [ V_28 ] ;
V_2 -> V_35 += V_24 ;
}
static T_3 F_57 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_35 = V_2 -> V_35 ;
T_3 V_29 ;
V_29 = V_2 -> V_36 [ V_35 ] ;
V_2 -> V_35 ++ ;
return V_29 ;
}
static T_4 F_58 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_35 = V_2 -> V_35 ;
T_4 V_29 ;
T_4 * V_38 = ( T_4 * ) & V_2 -> V_36 [ V_35 ] ;
V_29 = * V_38 ;
V_2 -> V_35 += 2 ;
return V_29 ;
}
static void F_59 ( struct V_11 * V_12 , T_3 * V_38 , int V_24 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
V_38 [ V_28 ] = F_57 ( V_12 ) ;
}
static int F_60 ( struct V_11 * V_12 , const T_5 * V_38 , int V_24 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
if ( V_38 [ V_28 ] != F_57 ( V_12 ) )
return - V_112 ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_70 * V_16 = & V_2 -> V_16 ;
if ( V_12 -> V_90 == 512 ) {
V_2 -> V_19 = 0 ;
if ( V_16 -> V_113 > ( 32 << 20 ) ) {
V_2 -> V_20 = V_114 ;
V_2 -> V_56 = V_115 ;
} else if ( V_16 -> V_113 > ( 2 << 16 ) ) {
V_2 -> V_20 = V_115 ;
V_2 -> V_56 = V_116 ;
} else {
V_2 -> V_20 = V_116 ;
V_2 -> V_56 = V_66 ;
}
} else {
V_2 -> V_19 = 1 ;
if ( V_16 -> V_113 > ( 128 << 20 ) ) {
V_2 -> V_20 = V_21 ;
V_2 -> V_56 = V_115 ;
} else if ( V_16 -> V_113 > ( 8 << 16 ) ) {
V_2 -> V_20 = V_114 ;
V_2 -> V_56 = V_116 ;
} else {
V_2 -> V_20 = V_115 ;
V_2 -> V_56 = V_66 ;
}
}
if ( V_2 -> V_96 ) {
if ( V_12 -> V_90 == 512 ) {
V_16 -> V_73 . V_117 = & V_118 ;
V_16 -> V_119 = & V_120 ;
} else {
V_16 -> V_73 . V_117 = & V_121 ;
V_16 -> V_119 = & V_122 ;
}
V_16 -> V_73 . V_30 = 512 ;
V_16 -> V_73 . V_75 = 10 ;
V_16 -> V_73 . V_123 = 4 ;
V_16 -> V_73 . V_124 = F_41 ;
V_16 -> V_73 . V_125 = F_42 ;
V_16 -> V_73 . V_126 = V_127 ;
V_2 -> V_48 |= V_128 | V_129 | V_130 ;
} else {
V_16 -> V_73 . V_126 = V_131 ;
}
return 0 ;
}
static int T_6 F_62 ( struct V_132 * V_5 )
{
struct V_133 * V_134 ;
struct V_1 * V_2 ;
struct V_11 * V_135 ;
struct V_70 * V_136 ;
struct V_137 * V_138 ;
int V_89 = - V_139 ;
V_138 = V_5 -> V_6 . V_140 ;
if ( V_138 == NULL ) {
F_8 ( & V_5 -> V_6 , L_4 ) ;
return - V_141 ;
}
V_2 = F_63 ( sizeof( struct V_1 ) , V_142 ) ;
if ( ! V_2 ) {
F_8 ( & V_5 -> V_6 , L_5 ) ;
return - V_143 ;
}
V_134 = F_64 ( V_5 , V_144 , 0 ) ;
if ( ! V_134 ) {
F_8 ( & V_5 -> V_6 , L_6 ) ;
goto V_145;
}
V_2 -> V_146 = F_65 ( V_134 -> V_147 , F_66 ( V_134 ) ) ;
if ( V_2 -> V_146 == NULL ) {
F_8 ( & V_5 -> V_6 , L_7 ) ;
goto V_145;
}
F_67 ( V_5 , V_2 ) ;
V_135 = & V_2 -> V_12 ;
V_136 = & V_2 -> V_16 ;
V_135 -> V_148 = V_136 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_48 = V_138 -> V_47 ;
V_2 -> V_96 = V_138 -> V_149 ;
V_2 -> V_110 = V_138 -> V_150 ;
V_136 -> V_17 = V_151 ;
V_136 -> V_152 = 20 ;
V_136 -> V_153 = F_57 ;
V_136 -> V_84 = F_56 ;
V_136 -> V_79 = F_59 ;
V_136 -> V_154 = F_60 ;
V_136 -> V_155 = F_51 ;
V_136 -> V_156 = F_47 ;
if ( V_138 -> V_47 & V_49 ) {
V_136 -> V_17 |= V_18 ;
V_136 -> V_157 = F_58 ;
}
F_68 ( & V_5 -> V_6 ) ;
F_69 ( & V_5 -> V_6 ) ;
V_89 = F_70 ( V_135 , 1 , NULL ) ;
if ( V_89 )
goto V_158;
V_89 = F_61 ( V_135 ) ;
if ( V_89 )
goto V_158;
V_89 = F_71 ( V_135 ) ;
if ( V_89 )
goto V_158;
F_72 ( V_135 , V_138 -> V_159 , V_138 -> V_160 ) ;
return 0 ;
V_158:
F_73 ( & V_5 -> V_6 ) ;
V_145:
F_74 ( V_2 ) ;
return V_89 ;
}
static int T_7 F_75 ( struct V_132 * V_5 )
{
struct V_1 * V_2 = F_76 ( V_5 ) ;
F_77 ( & V_2 -> V_12 ) ;
F_73 ( & V_5 -> V_6 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int T_8 F_78 ( void )
{
return F_79 ( & V_161 , F_62 ) ;
}
static void T_9 F_80 ( void )
{
F_81 ( & V_161 ) ;
}
