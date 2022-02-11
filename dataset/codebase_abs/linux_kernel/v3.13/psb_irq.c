static inline T_1
F_1 ( int V_1 )
{
if ( V_1 == 0 )
return V_2 ;
if ( V_1 == 1 )
return V_3 ;
if ( V_1 == 2 )
return V_4 ;
F_2 () ;
}
static inline T_1
F_3 ( int V_1 )
{
if ( V_1 == 0 )
return V_5 ;
if ( V_1 == 1 )
return V_6 ;
if ( V_1 == 2 )
return V_7 ;
F_2 () ;
}
static inline T_1
F_4 ( int V_1 )
{
if ( V_1 == 0 )
return V_8 ;
if ( V_1 == 1 )
return V_9 ;
if ( V_1 == 2 )
return V_10 ;
F_2 () ;
}
static inline T_1
F_5 ( int V_1 )
{
if ( V_1 == 0 )
return V_11 ;
if ( V_1 == 1 )
return V_12 ;
if ( V_1 == 2 )
return V_13 ;
F_2 () ;
}
void
F_6 ( struct V_14 * V_15 , int V_1 , T_1 V_16 )
{
if ( ( V_15 -> V_17 [ V_1 ] & V_16 ) != V_16 ) {
T_1 V_18 = F_1 ( V_1 ) ;
V_15 -> V_17 [ V_1 ] |= V_16 ;
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_20 = F_8 ( V_18 ) ;
V_20 |= ( V_16 | ( V_16 >> 16 ) ) ;
F_9 ( V_20 , V_18 ) ;
( void ) F_8 ( V_18 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
void
F_11 ( struct V_14 * V_15 , int V_1 , T_1 V_16 )
{
if ( ( V_15 -> V_17 [ V_1 ] & V_16 ) != 0 ) {
T_1 V_18 = F_1 ( V_1 ) ;
V_15 -> V_17 [ V_1 ] &= ~ V_16 ;
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_20 = F_8 ( V_18 ) ;
V_20 &= ~ V_16 ;
F_9 ( V_20 , V_18 ) ;
( void ) F_8 ( V_18 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
static void F_12 ( struct V_14 * V_15 , int V_1 )
{
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_21 = F_3 ( V_1 ) ;
V_15 -> V_22 |= V_21 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
static void F_13 ( struct V_14 * V_15 , int V_1 )
{
if ( V_15 -> V_17 [ V_1 ] == 0 ) {
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_21 = F_3 ( V_1 ) ;
V_15 -> V_22 &= ~ V_21 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
static void F_14 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_2 V_27 = 0 ;
T_2 V_28 = F_1 ( V_1 ) ;
T_2 V_29 = V_15 -> V_17 [ V_1 ] ;
T_2 V_30 = V_15 -> V_17 [ V_1 ] >> 16 ;
T_2 V_31 ;
T_2 V_32 = 0 ;
F_15 ( & V_15 -> V_33 ) ;
V_27 = F_8 ( V_28 ) ;
V_27 &= V_29 | V_30 ;
V_27 &= V_27 >> 16 ;
F_16 ( & V_15 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < 0xffff ; V_32 ++ ) {
F_9 ( F_8 ( V_28 ) , V_28 ) ;
V_31 = F_8 ( V_28 ) & V_30 ;
if ( V_31 == 0 )
break;
}
if ( V_31 )
F_17 ( V_19 -> V_19 ,
L_1 ,
V_34 , V_1 , F_8 ( V_28 ) ) ;
if ( V_27 & V_35 )
F_18 ( V_19 , V_1 ) ;
if ( V_27 & V_36 )
F_18 ( V_19 , V_1 ) ;
}
static void F_19 ( struct V_25 * V_19 , T_2 V_37 )
{
if ( V_37 & V_38 )
F_20 ( V_19 ) ;
if ( V_37 & V_8 )
F_14 ( V_19 , 0 ) ;
if ( V_37 & V_9 )
F_14 ( V_19 , 1 ) ;
}
T_3 F_21 ( T_4 )
{
struct V_25 * V_19 = V_39 ;
struct V_14 * V_15 = V_19 -> V_26 ;
T_2 V_37 , V_40 = 0 , V_41 = 0 , V_42 = 0 ;
int V_43 = 0 ;
F_15 ( & V_15 -> V_33 ) ;
V_37 = F_8 ( V_44 ) ;
if ( V_37 & ( V_45 | V_38 ) )
V_40 = 1 ;
if ( V_37 & V_46 )
V_41 = 1 ;
if ( V_37 & V_47 )
V_42 = 1 ;
V_37 &= V_15 -> V_22 ;
F_16 ( & V_15 -> V_33 ) ;
if ( V_40 && F_22 ( V_19 ) ) {
F_19 ( V_19 , V_37 ) ;
V_43 = 1 ;
}
if ( V_41 ) {
T_1 V_48 , V_49 ;
V_48 = F_23 ( V_50 ) ;
V_49 = F_23 ( V_51 ) ;
F_24 ( V_48 , V_52 ) ;
F_24 ( V_49 , V_53 ) ;
V_43 = 1 ;
}
if ( V_42 && V_15 -> V_54 -> V_55 ) {
V_43 = V_15 -> V_54 -> V_55 ( V_19 ) ;
F_25 ( V_56 , F_26 ( V_56 ) ) ;
}
F_9 ( V_37 , V_44 ) ;
( void ) F_8 ( V_44 ) ;
F_27 () ;
if ( ! V_43 )
return V_57 ;
return V_58 ;
}
void F_28 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
if ( F_22 ( V_19 ) )
F_9 ( 0xFFFFFFFF , V_60 ) ;
if ( V_19 -> V_61 [ 0 ] . V_62 )
V_15 -> V_22 |= V_8 ;
if ( V_19 -> V_61 [ 1 ] . V_62 )
V_15 -> V_22 |= V_9 ;
if ( V_15 -> V_54 -> V_55 )
V_15 -> V_22 |= V_47 ;
V_15 -> V_22 |= V_38 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
}
int F_31 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_9 ( 0xFFFFFFFF , V_60 ) ;
if ( V_19 -> V_61 [ 0 ] . V_62 )
F_6 ( V_15 , 0 , V_63 ) ;
else
F_11 ( V_15 , 0 , V_63 ) ;
if ( V_19 -> V_61 [ 1 ] . V_62 )
F_6 ( V_15 , 1 , V_63 ) ;
else
F_11 ( V_15 , 1 , V_63 ) ;
if ( V_19 -> V_61 [ 2 ] . V_62 )
F_6 ( V_15 , 2 , V_63 ) ;
else
F_11 ( V_15 , 2 , V_63 ) ;
if ( V_15 -> V_54 -> V_64 )
V_15 -> V_54 -> V_64 ( V_19 , true ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
return 0 ;
}
void F_32 ( struct V_25 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_59 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
if ( V_15 -> V_54 -> V_64 )
V_15 -> V_54 -> V_64 ( V_19 , false ) ;
F_9 ( 0xFFFFFFFF , V_60 ) ;
if ( V_19 -> V_61 [ 0 ] . V_62 )
F_11 ( V_15 , 0 , V_63 ) ;
if ( V_19 -> V_61 [ 1 ] . V_62 )
F_11 ( V_15 , 1 , V_63 ) ;
if ( V_19 -> V_61 [ 2 ] . V_62 )
F_11 ( V_15 , 2 , V_63 ) ;
V_15 -> V_22 &= V_46 |
V_65 |
V_66 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_33 () ;
F_9 ( F_8 ( V_44 ) , V_44 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
}
void F_34 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_67 ;
T_1 V_68 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 1 << 31 , V_69 ) ;
V_67 = F_8 ( V_69 ) ;
F_9 ( 1 << 31 , V_70 ) ;
V_67 = F_8 ( V_70 ) ;
F_9 ( 0x80010100 , V_71 ) ;
V_68 = F_8 ( V_71 ) ;
F_9 ( V_68 | V_72
| V_73 ,
V_71 ) ;
V_68 = F_8 ( V_71 ) ;
F_6 ( V_15 , 0 , V_74 ) ;
V_67 = F_8 ( V_70 ) ;
F_9 ( V_67 | V_75 ,
V_70 ) ;
V_68 = F_8 ( V_71 ) ;
F_9 ( V_68 | 0x80010100 | V_72 ,
V_71 ) ;
F_10 ( V_19 ) ;
}
}
int F_35 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
F_12 ( V_15 , 0 ) ;
F_34 ( V_19 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
return 0 ;
}
void F_36 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_67 ;
T_1 V_68 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 0x00000000 , V_70 ) ;
V_67 = F_8 ( V_70 ) ;
F_11 ( V_15 , 0 , V_74 ) ;
V_68 = F_8 ( V_71 ) ;
F_9 ( V_68 & ~ V_73 ,
V_71 ) ;
V_68 = F_8 ( V_71 ) ;
F_10 ( V_19 ) ;
}
}
int F_37 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
F_13 ( V_15 , 0 ) ;
F_36 ( V_19 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
return 0 ;
}
static int F_38 ( struct V_25 * V_19 ,
unsigned int * V_76 , T_5 * V_77 )
{
unsigned int V_78 ;
int V_79 = 0 ;
F_39 ( V_79 , V_19 -> V_61 . V_80 , 3 * V_81 ,
( ( ( V_78 = F_40 ( V_77 ) )
- * V_76 ) <= ( 1 << 23 ) ) ) ;
* V_76 = V_78 ;
return V_79 ;
}
int F_41 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_59 ;
T_2 V_82 = 0 ;
T_2 V_83 = F_5 ( V_1 ) ;
if ( F_42 ( V_19 ) )
return F_43 ( V_19 , V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_82 = F_26 ( V_83 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_82 & V_84 ) )
return - V_85 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
if ( V_1 == 0 )
V_15 -> V_22 |= V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 |= V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_6 ( V_15 , V_1 , V_63 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
return 0 ;
}
void F_44 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_59 ;
if ( F_42 ( V_19 ) )
F_45 ( V_19 , V_1 ) ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
if ( V_1 == 0 )
V_15 -> V_22 &= ~ V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 &= ~ V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_11 ( V_15 , V_1 , V_63 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
}
int F_43 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
T_2 V_82 = 0 ;
T_2 V_83 = F_5 ( V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_82 = F_26 ( V_83 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_82 & V_84 ) )
return - V_85 ;
F_29 ( & V_15 -> V_33 , V_59 ) ;
F_12 ( V_15 , V_1 ) ;
F_6 ( V_15 , V_1 , V_86 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
return 0 ;
}
void F_45 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_59 ;
if ( ! V_15 -> V_87 )
return;
F_29 ( & V_15 -> V_33 , V_59 ) ;
F_13 ( V_15 , V_1 ) ;
F_11 ( V_15 , V_1 , V_86 ) ;
F_30 ( & V_15 -> V_33 , V_59 ) ;
}
T_1 F_46 ( struct V_25 * V_19 , int V_1 )
{
T_2 V_88 = V_89 ;
T_2 V_90 = V_91 ;
T_2 V_83 = V_11 ;
T_2 V_82 = 0 ;
T_2 V_92 = 0 , V_93 = 0 , V_94 = 0 , V_95 = 0 ;
switch ( V_1 ) {
case 0 :
break;
case 1 :
V_88 = V_96 ;
V_90 = V_97 ;
V_83 = V_12 ;
break;
case 2 :
V_88 = V_98 ;
V_90 = V_99 ;
V_83 = V_13 ;
break;
default:
F_17 ( V_19 -> V_19 , L_2 , V_34 ) ;
return 0 ;
}
if ( ! F_7 ( V_19 , false ) )
return 0 ;
V_82 = F_26 ( V_83 ) ;
if ( ! ( V_82 & V_84 ) ) {
F_17 ( V_19 -> V_19 , L_3 ,
V_1 ) ;
goto V_100;
}
do {
V_92 = ( ( F_26 ( V_88 ) & V_101 ) >>
V_102 ) ;
V_94 = ( ( F_26 ( V_90 ) & V_103 ) >>
V_104 ) ;
V_93 = ( ( F_26 ( V_88 ) & V_101 ) >>
V_102 ) ;
} while ( V_92 != V_93 );
V_95 = ( V_92 << 8 ) | V_94 ;
V_100:
F_10 ( V_19 ) ;
return V_95 ;
}
