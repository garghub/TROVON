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
T_1 V_47 = F_17 ( F_38 ( V_2 ) ) & ~ V_48 ;
T_1 V_49 , V_50 = 0 ;
if ( V_2 -> V_19 )
V_47 |= V_51 ;
else
V_47 &= ~ V_51 ;
V_49 = V_52 | V_53 ;
switch ( V_45 ) {
case V_54 :
V_50 = V_2 -> V_55 ;
V_49 |= V_56 ;
break;
case V_57 :
case V_58 :
V_50 = V_2 -> V_20 ;
V_49 |= V_59 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_47 |= V_48 ;
break;
case V_60 :
V_49 &= ~ V_53 ;
break;
case V_61 :
V_50 = V_2 -> V_20 ;
V_49 |= V_56 | V_59 | V_62 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_47 |= V_48 ;
break;
case V_63 :
V_47 &= ~ V_51 ;
V_50 = V_64 ;
break;
case V_65 :
case V_66 :
V_47 &= ~ V_51 ;
V_49 &= ~ ( V_53 | V_67 ) ;
break;
default:
break;
}
V_49 |= V_50 ;
F_2 ( V_47 , F_38 ( V_2 ) ) ;
F_2 ( V_49 , F_39 ( V_2 ) ) ;
F_2 ( V_46 , F_40 ( V_2 ) ) ;
}
static int F_41 ( struct V_11 * V_12 , struct V_68 * V_16 ,
T_3 * V_38 , int V_69 )
{
int V_28 , V_70 = V_16 -> V_71 . V_30 ;
int V_72 = V_16 -> V_71 . V_73 ;
int V_74 = V_16 -> V_71 . V_75 ;
T_3 * V_76 = V_38 ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
for ( V_28 = 0 ; V_74 ; V_74 -- , V_28 += V_72 , V_76 += V_70 )
V_16 -> V_77 ( V_12 , V_76 , V_70 ) ;
for ( V_28 = 0 ; V_74 ; V_74 -- , V_28 += V_72 , V_76 += V_70 ) {
if ( V_2 -> V_78 [ V_28 ] )
V_12 -> V_79 . V_80 ++ ;
else
V_12 -> V_79 . V_81 += 0 ;
}
return 0 ;
}
static void F_42 ( struct V_11 * V_12 , struct V_68 * V_16 ,
const T_3 * V_38 )
{
int V_28 , V_70 = V_16 -> V_71 . V_30 ;
int V_72 = V_16 -> V_71 . V_73 ;
int V_74 = V_16 -> V_71 . V_75 ;
const T_3 * V_76 = V_38 ;
for ( V_28 = 0 ; V_74 ; V_74 -- , V_28 += V_72 , V_76 += V_70 )
V_16 -> V_82 ( V_12 , V_76 , V_70 ) ;
}
static void F_43 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_43 , V_83 ;
if ( V_2 -> V_19 )
V_83 = 4 ;
else
V_83 = 1 ;
F_2 ( F_17 ( F_38 ( V_2 ) ) | V_84 | V_85 ,
F_38 ( V_2 ) ) ;
F_37 ( V_12 , V_57 ,
( V_86 << 8 ) | V_57 ) ;
for ( V_43 = 0 ; V_43 < V_83 ; V_43 ++ ) {
int V_87 ;
F_1 ( V_2 ) ;
F_2 ( F_17 ( F_39 ( V_2 ) ) | 1 , F_39 ( V_2 ) ) ;
F_2 ( V_14 << 2 | V_43 , F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , 512 , 512 * V_43 ) ;
V_87 = F_33 ( V_2 ,
& V_2 -> V_36 [ V_12 -> V_88 + 16 * V_43 ] ,
V_43 ) ;
if ( V_87 )
V_2 -> V_78 [ V_43 ] = 1 ;
F_2 ( 0x0 , F_21 ( V_2 ) ) ;
F_9 ( V_2 ) ;
}
F_2 ( F_17 ( F_38 ( V_2 ) ) & ~ ( V_84 | V_85 ) ,
F_38 ( V_2 ) ) ;
}
static void F_44 ( struct V_11 * V_12 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
F_37 ( V_12 , V_57 ,
( V_86 << 8 ) | V_57 ) ;
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
int V_28 , V_14 = V_2 -> V_89 ;
int V_43 , V_83 ;
if ( V_2 -> V_19 )
V_83 = 4 ;
else
V_83 = 1 ;
F_2 ( F_17 ( F_38 ( V_2 ) ) | V_84 , F_38 ( V_2 ) ) ;
F_37 ( V_12 , V_61 ,
( V_61 << 8 ) | V_60 ) ;
for ( V_43 = 0 ; V_43 < V_83 ; V_43 ++ ) {
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
F_2 ( F_17 ( F_38 ( V_2 ) ) & ~ V_84 , F_38 ( V_2 ) ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_14 = V_2 -> V_89 ;
int V_43 , V_83 ;
if ( V_2 -> V_19 ) {
V_43 = 3 ;
V_83 = 4 ;
} else {
V_43 = 0 ;
V_83 = 1 ;
}
F_37 ( V_12 , V_61 ,
( V_61 << 8 ) | V_60 ) ;
for (; V_43 < V_83 ; V_43 ++ ) {
F_1 ( V_2 ) ;
F_12 ( V_12 , V_43 * 528 + 512 , V_14 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_35 ( V_2 , 16 , 16 * V_43 ) ;
F_9 ( V_2 ) ;
}
}
static void F_47 ( struct V_11 * V_12 , unsigned int V_90 ,
int V_13 , int V_14 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
T_1 V_91 = 0 ;
V_2 -> V_92 = 0 ;
if ( V_90 != V_61 )
V_2 -> V_35 = 0 ;
switch ( V_90 ) {
case V_93 :
case V_57 :
if ( V_2 -> V_94 ) {
F_43 ( V_12 , V_14 ) ;
break;
}
F_1 ( V_2 ) ;
if ( V_2 -> V_19 )
F_37 ( V_12 , V_90 , ( V_86 << 8 )
| V_90 ) ;
else
F_37 ( V_12 , V_90 , V_90 ) ;
F_12 ( V_12 , 0 , V_14 ) ;
V_2 -> V_92 = V_12 -> V_88 + V_12 -> V_95 ;
if ( V_2 -> V_16 . V_17 & V_18 )
V_13 >>= 1 ;
V_2 -> V_35 += V_13 ;
goto V_96;
case V_58 :
if ( V_2 -> V_94 ) {
F_44 ( V_12 , V_14 ) ;
break;
}
F_1 ( V_2 ) ;
if ( V_2 -> V_19 ) {
F_37 ( V_12 , V_90 , ( V_86 << 8 )
| V_57 ) ;
F_12 ( V_12 , V_12 -> V_88 , V_14 ) ;
} else {
F_37 ( V_12 , V_90 , V_90 ) ;
F_12 ( V_12 , 0 , V_14 ) ;
}
V_2 -> V_92 = V_12 -> V_95 ;
goto V_96;
case V_63 :
F_1 ( V_2 ) ;
F_37 ( V_12 , V_90 , V_90 ) ;
F_12 ( V_12 , 0 , 0 ) ;
V_2 -> V_92 = 4 ;
F_2 ( V_2 -> V_92 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_27 ( V_2 , 0 ) ;
break;
case V_54 :
V_2 -> V_97 = V_14 ;
break;
case V_98 :
F_37 ( V_12 , V_54 ,
( V_90 << 8 ) | V_54 ) ;
F_12 ( V_12 , - 1 , V_2 -> V_97 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_60 :
if ( ! V_2 -> V_19 ) {
if ( V_13 >= V_12 -> V_88 ) {
V_13 -= V_12 -> V_88 ;
V_91 = V_58 ;
} else if ( V_13 < 256 ) {
V_91 = V_57 ;
} else {
V_13 -= 256 ;
V_91 = V_93 ;
}
}
V_2 -> V_99 = V_13 ;
V_2 -> V_89 = V_14 ;
V_2 -> V_100 = V_91 ;
break;
case V_61 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_19 ) {
F_37 ( V_12 , V_60 ,
V_2 -> V_100 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_94 ) {
if ( V_2 -> V_99 == V_12 -> V_88 )
F_46 ( V_12 ) ;
else if ( ! V_2 -> V_99 )
F_45 ( V_12 ) ;
else
F_48 ( V_101 L_2 ) ;
break;
}
F_37 ( V_12 , V_90 , ( V_90 << 8 ) | V_60 ) ;
F_12 ( V_12 , V_2 -> V_99 , V_2 -> V_89 ) ;
F_2 ( V_2 -> V_35 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_35 ( V_2 , V_2 -> V_35 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_65 :
F_37 ( V_12 , V_90 , V_90 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
V_2 -> V_92 = 1 ;
F_2 ( V_2 -> V_92 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_27 ( V_2 , 0 ) ;
break;
case V_66 :
F_37 ( V_12 , V_90 , V_90 ) ;
F_12 ( V_12 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
return;
V_96:
F_2 ( V_2 -> V_92 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_30 ( V_2 , V_2 -> V_92 , 0 ) ;
F_9 ( V_2 ) ;
return;
}
static void F_49 ( struct V_11 * V_12 , int V_102 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
T_1 V_47 = F_17 ( F_38 ( V_2 ) ) ;
switch ( V_102 ) {
case - 1 :
V_47 &= ~ V_103 ;
F_2 ( V_47 , F_38 ( V_2 ) ) ;
break;
case 0 :
V_47 |= V_103 ;
F_2 ( V_47 , F_38 ( V_2 ) ) ;
break;
default:
F_50 () ;
}
}
static void F_51 ( struct V_11 * V_12 , const T_3 * V_38 , int V_24 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_28 , V_35 = V_2 -> V_35 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
V_2 -> V_36 [ V_35 + V_28 ] = V_38 [ V_28 ] ;
V_2 -> V_35 += V_24 ;
}
static T_3 F_52 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_35 = V_2 -> V_35 ;
T_3 V_29 ;
V_29 = V_2 -> V_36 [ V_35 ] ;
V_2 -> V_35 ++ ;
return V_29 ;
}
static T_4 F_53 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
int V_35 = V_2 -> V_35 ;
T_4 V_29 ;
T_4 * V_38 = ( T_4 * ) & V_2 -> V_36 [ V_35 ] ;
V_29 = * V_38 ;
V_2 -> V_35 += 2 ;
return V_29 ;
}
static void F_54 ( struct V_11 * V_12 , T_3 * V_38 , int V_24 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
V_38 [ V_28 ] = F_52 ( V_12 ) ;
}
static int F_55 ( struct V_11 * V_12 , const T_5 * V_38 , int V_24 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ )
if ( V_38 [ V_28 ] != F_52 ( V_12 ) )
return - V_104 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , unsigned long V_23 )
{
F_2 ( V_23 , F_38 ( V_2 ) ) ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_68 * V_16 = & V_2 -> V_16 ;
if ( V_12 -> V_88 == 512 ) {
V_2 -> V_19 = 0 ;
if ( V_16 -> V_105 > ( 32 << 20 ) ) {
V_2 -> V_20 = V_106 ;
V_2 -> V_55 = V_107 ;
} else if ( V_16 -> V_105 > ( 2 << 16 ) ) {
V_2 -> V_20 = V_107 ;
V_2 -> V_55 = V_108 ;
} else {
V_2 -> V_20 = V_108 ;
V_2 -> V_55 = V_64 ;
}
} else {
V_2 -> V_19 = 1 ;
if ( V_16 -> V_105 > ( 128 << 20 ) ) {
V_2 -> V_20 = V_21 ;
V_2 -> V_55 = V_107 ;
} else if ( V_16 -> V_105 > ( 8 << 16 ) ) {
V_2 -> V_20 = V_106 ;
V_2 -> V_55 = V_108 ;
} else {
V_2 -> V_20 = V_107 ;
V_2 -> V_55 = V_64 ;
}
}
if ( V_2 -> V_94 ) {
if ( V_12 -> V_88 == 512 ) {
V_16 -> V_71 . V_109 = & V_110 ;
V_16 -> V_111 = & V_112 ;
} else {
V_16 -> V_71 . V_109 = & V_113 ;
V_16 -> V_111 = & V_114 ;
}
V_16 -> V_71 . V_30 = 512 ;
V_16 -> V_71 . V_73 = 10 ;
V_16 -> V_71 . V_115 = F_41 ;
V_16 -> V_71 . V_116 = F_42 ;
V_16 -> V_71 . V_117 = V_118 ;
F_2 ( F_17 ( F_38 ( V_2 ) ) | V_119 | V_120 | V_121 ,
F_38 ( V_2 ) ) ;
} else {
V_16 -> V_71 . V_117 = V_122 ;
}
return 0 ;
}
static int T_6 F_58 ( struct V_123 * V_5 )
{
struct V_124 * V_125 ;
struct V_1 * V_2 ;
struct V_11 * V_126 ;
struct V_68 * V_127 ;
struct V_128 * V_129 ;
int V_87 = - V_130 ;
V_129 = V_5 -> V_6 . V_131 ;
if ( V_129 == NULL ) {
F_8 ( & V_5 -> V_6 , L_3 ) ;
return - V_132 ;
}
V_2 = F_59 ( sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_2 ) {
F_8 ( & V_5 -> V_6 , L_4 ) ;
return - V_134 ;
}
V_125 = F_60 ( V_5 , V_135 , 0 ) ;
if ( ! V_125 ) {
F_8 ( & V_5 -> V_6 , L_5 ) ;
goto V_136;
}
V_2 -> V_137 = F_61 ( V_125 -> V_138 , F_62 ( V_125 ) ) ;
if ( V_2 -> V_137 == NULL ) {
F_8 ( & V_5 -> V_6 , L_6 ) ;
goto V_136;
}
F_63 ( V_5 , V_2 ) ;
V_126 = & V_2 -> V_12 ;
V_127 = & V_2 -> V_16 ;
V_126 -> V_139 = V_127 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_94 = V_129 -> V_140 ;
F_56 ( V_2 , V_129 -> V_47 ) ;
V_127 -> V_17 = V_141 ;
V_127 -> V_142 = 20 ;
V_127 -> V_143 = F_52 ;
V_127 -> V_82 = F_51 ;
V_127 -> V_77 = F_54 ;
V_127 -> V_144 = F_55 ;
V_127 -> V_145 = F_49 ;
V_127 -> V_146 = F_47 ;
if ( V_129 -> V_47 & V_48 ) {
V_127 -> V_17 |= V_18 ;
V_127 -> V_147 = F_53 ;
}
V_87 = F_64 ( V_126 , 1 , NULL ) ;
if ( V_87 )
goto V_136;
V_87 = F_57 ( V_126 ) ;
if ( V_87 )
goto V_136;
V_87 = F_65 ( V_126 ) ;
if ( V_87 )
goto V_136;
F_66 ( V_126 , V_129 -> V_148 , V_129 -> V_149 ) ;
return 0 ;
V_136:
F_67 ( V_2 ) ;
return V_87 ;
}
static int T_7 F_68 ( struct V_123 * V_5 )
{
struct V_1 * V_2 = F_69 ( V_5 ) ;
F_70 ( & V_2 -> V_12 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int T_8 F_71 ( void )
{
return F_72 ( & V_150 , F_58 ) ;
}
static void T_9 F_73 ( void )
{
F_74 ( & V_150 ) ;
}
