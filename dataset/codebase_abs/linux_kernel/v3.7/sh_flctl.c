static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 | V_4 | V_5 , F_3 ( V_2 ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_6 , F_6 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , const char * V_7 )
{
F_8 ( & V_2 -> V_8 -> V_9 , L_1 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
if ( F_10 ( F_6 ( V_2 ) ) & V_12 ) {
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
return;
}
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
F_5 ( 0x0 , F_6 ( V_2 ) ) ;
}
static void F_12 ( struct V_14 * V_15 , int V_16 , int V_17 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_18 = 0 ;
if ( V_16 == - 1 ) {
V_18 = V_17 ;
} else if ( V_17 != - 1 ) {
if ( V_2 -> V_19 . V_20 & V_21 )
V_16 >>= 1 ;
if ( V_2 -> V_22 ) {
V_18 = V_16 & 0x0FFF ;
V_18 |= ( V_17 & 0xff ) << 16 ;
V_18 |= ( ( V_17 >> 8 ) & 0xff ) << 24 ;
if ( V_2 -> V_23 == V_24 ) {
T_1 V_25 ;
V_25 = ( V_17 >> 16 ) & 0xff ;
F_2 ( V_25 , F_14 ( V_2 ) ) ;
}
} else {
V_18 = V_16 ;
V_18 |= ( V_17 & 0xff ) << 8 ;
V_18 |= ( ( V_17 >> 8 ) & 0xff ) << 16 ;
V_18 |= ( ( V_17 >> 16 ) & 0xff ) << 24 ;
}
}
F_2 ( V_18 , F_15 ( V_2 ) ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
while ( V_10 -- ) {
T_1 V_26 ;
V_26 = F_17 ( F_18 ( V_2 ) ) >> 16 ;
if ( V_26 & 0xFF )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_27 , V_10 = V_11 ;
while ( V_10 -- ) {
V_27 = ( F_17 ( F_18 ( V_2 ) ) >> 16 ) & 0xFF ;
if ( V_27 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static enum V_28 F_20
( struct V_1 * V_2 , int V_29 )
{
T_1 V_10 = V_11 ;
void T_2 * V_30 [ 4 ] ;
int V_31 ;
int V_32 = V_33 ;
T_1 V_34 , V_35 ;
while ( V_10 -- ) {
V_35 = F_17 ( F_18 ( V_2 ) ) >> 24 ;
if ( ( V_35 & 0xFF ) == 4 )
return V_32 ;
if ( ! ( F_17 ( F_21 ( V_2 ) ) & V_36 ) ) {
F_11 ( 1 ) ;
continue;
}
if ( F_17 ( F_21 ( V_2 ) ) & V_37 ) {
for ( V_31 = 0 ; V_31 < 512 ; V_31 ++ ) {
if ( V_2 -> V_38 [ V_31 ] != 0xff ) {
V_32 = V_39 ;
break;
}
}
if ( V_32 == V_33 )
F_22 ( & V_2 -> V_8 -> V_9 ,
L_2 ,
V_29 ) ;
F_2 ( 0 , F_21 ( V_2 ) ) ;
continue;
}
V_30 [ 0 ] = F_23 ( V_2 ) ;
V_30 [ 1 ] = F_24 ( V_2 ) ;
V_30 [ 2 ] = F_25 ( V_2 ) ;
V_30 [ 3 ] = F_26 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
T_3 V_40 ;
int V_41 ;
V_34 = F_17 ( V_30 [ V_31 ] ) ;
if ( V_2 -> V_22 )
V_41 = ( 512 * V_29 ) +
( V_34 >> 16 ) ;
else
V_41 = V_34 >> 16 ;
V_40 = V_2 -> V_38 [ V_41 ] ;
V_2 -> V_38 [ V_41 ] = V_40 ^ ( V_34 & 0xFF ) ;
}
V_32 = V_42 ;
F_2 ( 0 , F_21 ( V_2 ) ) ;
}
F_7 ( V_2 , V_13 ) ;
return V_43 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 ;
T_1 V_27 ;
while ( V_10 -- ) {
V_27 = ( F_17 ( F_18 ( V_2 ) ) >> 24 ) & 0xFF ;
if ( V_27 >= 4 )
return;
F_11 ( 1 ) ;
}
F_7 ( V_2 , V_13 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_34 ;
unsigned long * V_45 = ( unsigned long * ) & V_2 -> V_38 [ V_44 ] ;
F_9 ( V_2 ) ;
V_34 = F_17 ( F_29 ( V_2 ) ) ;
* V_45 = F_30 ( V_34 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_46 , int V_44 )
{
int V_31 , V_47 ;
unsigned long * V_45 = ( unsigned long * ) & V_2 -> V_38 [ V_44 ] ;
V_47 = ( V_46 + 3 ) / 4 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
F_16 ( V_2 ) ;
V_45 [ V_31 ] = F_17 ( F_32 ( V_2 ) ) ;
V_45 [ V_31 ] = F_33 ( V_45 [ V_31 ] ) ;
}
}
static enum V_28 F_34
( struct V_1 * V_2 , T_3 * V_48 , int V_49 )
{
int V_31 ;
enum V_28 V_50 ;
unsigned long * V_51 = ( unsigned long * ) V_48 ;
V_50 = F_20 ( V_2 , V_49 ) ;
if ( V_50 != V_39 ) {
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_51 [ V_31 ] = F_17 ( F_35 ( V_2 ) ) ;
V_51 [ V_31 ] = F_33 ( V_51 [ V_31 ] ) ;
}
}
return V_50 ;
}
static void F_36 ( struct V_1 * V_2 , int V_46 , int V_44 )
{
int V_31 , V_47 ;
unsigned long * V_34 = ( unsigned long * ) & V_2 -> V_38 [ V_44 ] ;
void * V_52 = ( void * ) F_32 ( V_2 ) ;
V_47 = ( V_46 + 3 ) / 4 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
F_19 ( V_2 ) ;
F_2 ( F_37 ( V_34 [ V_31 ] ) , V_52 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , int V_46 , int V_44 )
{
int V_31 , V_47 ;
unsigned long * V_34 = ( unsigned long * ) & V_2 -> V_38 [ V_44 ] ;
V_47 = ( V_46 + 3 ) / 4 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
F_27 ( V_2 ) ;
F_2 ( F_37 ( V_34 [ V_31 ] ) , F_35 ( V_2 ) ) ;
}
}
static void F_39 ( struct V_14 * V_15 , T_1 V_53 , T_1 V_54 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_55 = V_2 -> V_56 & ~ V_57 ;
T_1 V_58 , V_59 = 0 ;
if ( V_2 -> V_22 )
V_55 |= V_60 ;
else
V_55 &= ~ V_60 ;
V_58 = V_61 | V_62 ;
switch ( V_53 ) {
case V_63 :
V_59 = V_2 -> V_64 ;
V_58 |= V_65 ;
break;
case V_66 :
case V_67 :
case V_68 :
V_59 = V_2 -> V_23 ;
V_58 |= V_69 ;
if ( V_2 -> V_19 . V_20 & V_21 )
V_55 |= V_57 ;
break;
case V_70 :
V_58 &= ~ V_62 ;
break;
case V_71 :
V_59 = V_2 -> V_23 ;
V_58 |= V_65 | V_69 | V_72 ;
if ( V_2 -> V_19 . V_20 & V_21 )
V_55 |= V_57 ;
break;
case V_73 :
V_55 &= ~ V_60 ;
V_58 |= V_69 ;
V_59 = V_74 ;
break;
case V_75 :
case V_76 :
V_55 &= ~ V_60 ;
V_58 &= ~ ( V_62 | V_77 ) ;
break;
default:
break;
}
V_58 |= V_59 ;
F_2 ( V_55 , F_40 ( V_2 ) ) ;
F_2 ( V_58 , F_41 ( V_2 ) ) ;
F_2 ( V_54 , F_42 ( V_2 ) ) ;
}
static int F_43 ( struct V_14 * V_15 , struct V_78 * V_19 ,
T_3 * V_45 , int V_79 , int V_80 )
{
V_19 -> V_81 ( V_15 , V_45 , V_15 -> V_82 ) ;
if ( V_79 )
V_19 -> V_81 ( V_15 , V_19 -> V_83 , V_15 -> V_84 ) ;
return 0 ;
}
static int F_44 ( struct V_14 * V_15 , struct V_78 * V_19 ,
const T_3 * V_45 , int V_79 )
{
V_19 -> V_85 ( V_15 , V_45 , V_15 -> V_82 ) ;
V_19 -> V_85 ( V_15 , V_19 -> V_83 , V_15 -> V_84 ) ;
return 0 ;
}
static void F_45 ( struct V_14 * V_15 , int V_17 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_49 , V_86 ;
enum V_28 V_87 ;
V_86 = V_2 -> V_22 ? 4 : 1 ;
F_39 ( V_15 , V_66 ,
( V_88 << 8 ) | V_66 ) ;
F_2 ( F_17 ( F_40 ( V_2 ) ) | V_89 | V_90 ,
F_40 ( V_2 ) ) ;
F_2 ( F_17 ( F_41 ( V_2 ) ) | V_86 , F_41 ( V_2 ) ) ;
F_2 ( V_17 << 2 , F_15 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_86 ; V_49 ++ ) {
F_31 ( V_2 , 512 , 512 * V_49 ) ;
V_87 = F_34 ( V_2 ,
& V_2 -> V_38 [ V_15 -> V_82 + 16 * V_49 ] ,
V_49 ) ;
switch ( V_87 ) {
case V_42 :
F_46 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_17 ) ;
V_2 -> V_15 . V_91 . V_92 ++ ;
break;
case V_39 :
F_47 ( & V_2 -> V_8 -> V_9 ,
L_4 ,
V_17 ) ;
V_2 -> V_15 . V_91 . V_93 ++ ;
break;
default:
;
}
}
F_9 ( V_2 ) ;
F_2 ( F_17 ( F_40 ( V_2 ) ) & ~ ( V_89 | V_90 ) ,
F_40 ( V_2 ) ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_17 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_86 = V_2 -> V_22 ? 4 : 1 ;
int V_31 ;
F_39 ( V_15 , V_66 ,
( V_88 << 8 ) | V_66 ) ;
F_1 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_86 ; V_31 ++ ) {
F_12 ( V_15 , ( 512 + 16 ) * V_31 + 512 , V_17 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_31 ( V_2 , 16 , 16 * V_31 ) ;
F_9 ( V_2 ) ;
}
}
static void F_49 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_17 = V_2 -> V_94 ;
int V_49 , V_86 ;
V_86 = V_2 -> V_22 ? 4 : 1 ;
F_39 ( V_15 , V_71 ,
( V_71 << 8 ) | V_70 ) ;
F_1 ( V_2 ) ;
F_2 ( F_17 ( F_40 ( V_2 ) ) | V_89 , F_40 ( V_2 ) ) ;
F_2 ( F_17 ( F_41 ( V_2 ) ) | V_86 , F_41 ( V_2 ) ) ;
F_2 ( V_17 << 2 , F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_86 ; V_49 ++ ) {
F_36 ( V_2 , 512 , 512 * V_49 ) ;
F_38 ( V_2 , 16 , V_15 -> V_82 + 16 * V_49 ) ;
}
F_9 ( V_2 ) ;
F_2 ( F_17 ( F_40 ( V_2 ) ) & ~ V_89 , F_40 ( V_2 ) ) ;
}
static void F_50 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_17 = V_2 -> V_94 ;
int V_49 , V_86 ;
V_86 = V_2 -> V_22 ? 4 : 1 ;
F_39 ( V_15 , V_71 ,
( V_71 << 8 ) | V_70 ) ;
for ( V_49 = 0 ; V_49 < V_86 ; V_49 ++ ) {
F_1 ( V_2 ) ;
F_12 ( V_15 , V_49 * 528 + 512 , V_17 ) ;
F_2 ( 16 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_36 ( V_2 , 16 , 16 * V_49 ) ;
F_9 ( V_2 ) ;
}
}
static void F_51 ( struct V_14 * V_15 , unsigned int V_95 ,
int V_16 , int V_17 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_96 = 0 ;
F_52 ( & V_2 -> V_8 -> V_9 ) ;
V_2 -> V_97 = 0 ;
if ( V_95 != V_71 )
V_2 -> V_41 = 0 ;
switch ( V_95 ) {
case V_98 :
case V_66 :
if ( V_2 -> V_99 ) {
F_45 ( V_15 , V_17 ) ;
break;
}
if ( V_2 -> V_22 )
F_39 ( V_15 , V_95 , ( V_88 << 8 )
| V_95 ) ;
else
F_39 ( V_15 , V_95 , V_95 ) ;
F_12 ( V_15 , 0 , V_17 ) ;
V_2 -> V_97 = V_15 -> V_82 + V_15 -> V_84 ;
if ( V_2 -> V_19 . V_20 & V_21 )
V_16 >>= 1 ;
V_2 -> V_41 += V_16 ;
goto V_100;
case V_67 :
if ( V_2 -> V_99 ) {
F_48 ( V_15 , V_17 ) ;
break;
}
if ( V_2 -> V_22 ) {
F_39 ( V_15 , V_95 , ( V_88 << 8 )
| V_66 ) ;
F_12 ( V_15 , V_15 -> V_82 , V_17 ) ;
} else {
F_39 ( V_15 , V_95 , V_95 ) ;
F_12 ( V_15 , 0 , V_17 ) ;
}
V_2 -> V_97 = V_15 -> V_84 ;
goto V_100;
case V_68 :
if ( V_2 -> V_99 )
break;
if ( V_2 -> V_22 )
F_39 ( V_15 , V_95 , ( V_101 << 8 )
| V_95 ) ;
else
F_39 ( V_15 , V_95 , V_95 ) ;
F_12 ( V_15 , V_16 , 0 ) ;
V_2 -> V_97 = V_15 -> V_82 + V_15 -> V_84 - V_16 ;
goto V_100;
case V_73 :
F_39 ( V_15 , V_95 , V_95 ) ;
if ( V_2 -> V_19 . V_20 & V_21 )
V_16 <<= 1 ;
F_12 ( V_15 , V_16 , 0 ) ;
V_2 -> V_97 = 8 ;
F_2 ( V_2 -> V_97 , F_18 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_31 ( V_2 , V_2 -> V_97 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_63 :
V_2 -> V_102 = V_17 ;
break;
case V_103 :
F_39 ( V_15 , V_63 ,
( V_95 << 8 ) | V_63 ) ;
F_12 ( V_15 , - 1 , V_2 -> V_102 ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_70 :
if ( ! V_2 -> V_22 ) {
if ( V_16 >= V_15 -> V_82 ) {
V_16 -= V_15 -> V_82 ;
V_96 = V_67 ;
} else if ( V_16 < 256 ) {
V_96 = V_66 ;
} else {
V_16 -= 256 ;
V_96 = V_98 ;
}
}
V_2 -> V_104 = V_16 ;
V_2 -> V_94 = V_17 ;
V_2 -> V_105 = V_96 ;
break;
case V_71 :
F_1 ( V_2 ) ;
if ( ! V_2 -> V_22 ) {
F_39 ( V_15 , V_70 ,
V_2 -> V_105 ) ;
F_12 ( V_15 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
}
if ( V_2 -> V_99 ) {
if ( V_2 -> V_104 == V_15 -> V_82 )
F_50 ( V_15 ) ;
else if ( ! V_2 -> V_104 )
F_49 ( V_15 ) ;
else
F_53 ( V_106 L_5 ) ;
break;
}
F_39 ( V_15 , V_95 , ( V_95 << 8 ) | V_70 ) ;
F_12 ( V_15 , V_2 -> V_104 , V_2 -> V_94 ) ;
F_2 ( V_2 -> V_41 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_36 ( V_2 , V_2 -> V_41 , 0 ) ;
F_9 ( V_2 ) ;
break;
case V_75 :
F_39 ( V_15 , V_95 , V_95 ) ;
F_12 ( V_15 , - 1 , - 1 ) ;
V_2 -> V_97 = 1 ;
F_2 ( V_2 -> V_97 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_28 ( V_2 , 0 ) ;
break;
case V_76 :
F_39 ( V_15 , V_95 , V_95 ) ;
F_12 ( V_15 , - 1 , - 1 ) ;
F_2 ( 0 , F_18 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
default:
break;
}
goto V_107;
V_100:
F_2 ( V_2 -> V_97 , F_18 ( V_2 ) ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_31 ( V_2 , V_2 -> V_97 , 0 ) ;
F_9 ( V_2 ) ;
V_107:
F_54 ( & V_2 -> V_8 -> V_9 ) ;
return;
}
static void F_55 ( struct V_14 * V_15 , int V_108 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_109 ;
switch ( V_108 ) {
case - 1 :
V_2 -> V_56 &= ~ V_110 ;
F_52 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_2 -> V_56 , F_40 ( V_2 ) ) ;
if ( V_2 -> V_111 ) {
F_56 ( & V_2 -> V_112 ) ;
V_2 -> V_111 = 0 ;
}
F_54 ( & V_2 -> V_8 -> V_9 ) ;
break;
case 0 :
V_2 -> V_56 |= V_110 ;
if ( ! V_2 -> V_111 ) {
V_109 = F_57 ( & V_2 -> V_8 -> V_9 ,
& V_2 -> V_112 , 100 ) ;
if ( V_109 < 0 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_6 , V_109 ) ;
V_2 -> V_111 = 1 ;
}
if ( V_2 -> V_113 ) {
F_52 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( V_114 , F_58 ( V_2 ) ) ;
F_54 ( & V_2 -> V_8 -> V_9 ) ;
}
break;
default:
F_59 () ;
}
}
static void F_60 ( struct V_14 * V_15 , const T_3 * V_45 , int V_27 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_41 = V_2 -> V_41 ;
memcpy ( & V_2 -> V_38 [ V_41 ] , V_45 , V_27 ) ;
V_2 -> V_41 += V_27 ;
}
static T_3 F_61 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_41 = V_2 -> V_41 ;
T_3 V_34 ;
V_34 = V_2 -> V_38 [ V_41 ] ;
V_2 -> V_41 ++ ;
return V_34 ;
}
static T_4 F_62 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_41 = V_2 -> V_41 ;
T_4 V_34 ;
T_4 * V_45 = ( T_4 * ) & V_2 -> V_38 [ V_41 ] ;
V_34 = * V_45 ;
V_2 -> V_41 += 2 ;
return V_34 ;
}
static void F_63 ( struct V_14 * V_15 , T_3 * V_45 , int V_27 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
int V_41 = V_2 -> V_41 ;
memcpy ( V_45 , & V_2 -> V_38 [ V_41 ] , V_27 ) ;
V_2 -> V_41 += V_27 ;
}
static int F_64 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_78 * V_19 = & V_2 -> V_19 ;
if ( V_15 -> V_82 == 512 ) {
V_2 -> V_22 = 0 ;
if ( V_19 -> V_115 > ( 32 << 20 ) ) {
V_2 -> V_23 = V_116 ;
V_2 -> V_64 = V_117 ;
} else if ( V_19 -> V_115 > ( 2 << 16 ) ) {
V_2 -> V_23 = V_117 ;
V_2 -> V_64 = V_118 ;
} else {
V_2 -> V_23 = V_118 ;
V_2 -> V_64 = V_74 ;
}
} else {
V_2 -> V_22 = 1 ;
if ( V_19 -> V_115 > ( 128 << 20 ) ) {
V_2 -> V_23 = V_24 ;
V_2 -> V_64 = V_117 ;
} else if ( V_19 -> V_115 > ( 8 << 16 ) ) {
V_2 -> V_23 = V_116 ;
V_2 -> V_64 = V_118 ;
} else {
V_2 -> V_23 = V_117 ;
V_2 -> V_64 = V_74 ;
}
}
if ( V_2 -> V_99 ) {
if ( V_15 -> V_82 == 512 ) {
V_19 -> V_119 . V_120 = & V_121 ;
V_19 -> V_122 = & V_123 ;
} else {
V_19 -> V_119 . V_120 = & V_124 ;
V_19 -> V_122 = & V_125 ;
}
V_19 -> V_119 . V_35 = 512 ;
V_19 -> V_119 . V_126 = 10 ;
V_19 -> V_119 . V_127 = 4 ;
V_19 -> V_119 . V_128 = F_43 ;
V_19 -> V_119 . V_129 = F_44 ;
V_19 -> V_119 . V_130 = V_131 ;
V_2 -> V_56 |= V_132 ;
} else {
V_19 -> V_119 . V_130 = V_133 ;
}
return 0 ;
}
static T_5 F_65 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
F_8 ( & V_2 -> V_8 -> V_9 , L_7 , F_17 ( F_3 ( V_2 ) ) ) ;
F_2 ( V_2 -> V_3 , F_3 ( V_2 ) ) ;
return V_136 ;
}
static int T_6 F_66 ( struct V_137 * V_8 )
{
struct V_138 * V_50 ;
struct V_1 * V_2 ;
struct V_14 * V_139 ;
struct V_78 * V_140 ;
struct V_141 * V_142 ;
int V_109 = - V_143 ;
int V_134 ;
V_142 = V_8 -> V_9 . V_144 ;
if ( V_142 == NULL ) {
F_8 ( & V_8 -> V_9 , L_8 ) ;
return - V_145 ;
}
V_2 = F_67 ( sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_2 ) {
F_8 ( & V_8 -> V_9 , L_9 ) ;
return - V_147 ;
}
V_50 = F_68 ( V_8 , V_148 , 0 ) ;
if ( ! V_50 ) {
F_8 ( & V_8 -> V_9 , L_10 ) ;
goto V_149;
}
V_2 -> V_150 = F_69 ( V_50 -> V_151 , F_70 ( V_50 ) ) ;
if ( V_2 -> V_150 == NULL ) {
F_8 ( & V_8 -> V_9 , L_11 ) ;
goto V_149;
}
V_134 = F_71 ( V_8 , 0 ) ;
if ( V_134 < 0 ) {
F_8 ( & V_8 -> V_9 , L_12 ) ;
goto V_152;
}
V_109 = F_72 ( V_134 , F_65 , V_153 , L_13 , V_2 ) ;
if ( V_109 ) {
F_8 ( & V_8 -> V_9 , L_14 ) ;
goto V_152;
}
F_73 ( V_8 , V_2 ) ;
V_139 = & V_2 -> V_15 ;
V_140 = & V_2 -> V_19 ;
V_139 -> V_154 = V_140 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_99 = V_142 -> V_155 ;
V_2 -> V_113 = V_142 -> V_156 ;
V_2 -> V_56 = V_142 -> V_55 ;
V_2 -> V_3 = V_2 -> V_99 ? ( V_157 | V_158 ) : V_157 ;
V_140 -> V_159 = 20 ;
V_140 -> V_160 = F_61 ;
V_140 -> V_85 = F_60 ;
V_140 -> V_81 = F_63 ;
V_140 -> V_161 = F_55 ;
V_140 -> V_162 = F_51 ;
if ( V_142 -> V_55 & V_57 ) {
V_140 -> V_20 |= V_21 ;
V_140 -> V_163 = F_62 ;
}
F_74 ( & V_8 -> V_9 ) ;
F_75 ( & V_8 -> V_9 ) ;
V_109 = F_76 ( V_139 , 1 , NULL ) ;
if ( V_109 )
goto V_164;
V_109 = F_64 ( V_139 ) ;
if ( V_109 )
goto V_164;
V_109 = F_77 ( V_139 ) ;
if ( V_109 )
goto V_164;
F_78 ( V_139 , V_142 -> V_165 , V_142 -> V_166 ) ;
return 0 ;
V_164:
F_79 ( & V_8 -> V_9 ) ;
F_80 ( V_134 , V_2 ) ;
V_152:
F_81 ( V_2 -> V_150 ) ;
V_149:
F_82 ( V_2 ) ;
return V_109 ;
}
static int T_7 F_83 ( struct V_137 * V_8 )
{
struct V_1 * V_2 = F_84 ( V_8 ) ;
F_85 ( & V_2 -> V_15 ) ;
F_79 ( & V_8 -> V_9 ) ;
F_80 ( F_71 ( V_8 , 0 ) , V_2 ) ;
F_81 ( V_2 -> V_150 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int T_8 F_86 ( void )
{
return F_87 ( & V_167 , F_66 ) ;
}
static void T_9 F_88 ( void )
{
F_89 ( & V_167 ) ;
}
