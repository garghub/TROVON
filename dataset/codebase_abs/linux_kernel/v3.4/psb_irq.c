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
if ( V_37 & V_8 )
F_14 ( V_19 , 0 ) ;
if ( V_37 & V_9 )
F_14 ( V_19 , 1 ) ;
}
T_3 F_20 ( T_4 )
{
struct V_25 * V_19 = (struct V_25 * ) V_38 ;
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_2 V_37 , V_39 = 0 , V_40 = 0 ;
int V_41 = 0 ;
F_15 ( & V_15 -> V_33 ) ;
V_37 = F_8 ( V_42 ) ;
if ( V_37 & V_43 )
V_39 = 1 ;
if ( V_37 & V_44 )
V_40 = 1 ;
V_37 &= V_15 -> V_22 ;
F_16 ( & V_15 -> V_33 ) ;
if ( V_39 && F_21 ( V_19 ) ) {
F_19 ( V_19 , V_37 ) ;
V_41 = 1 ;
}
if ( V_40 ) {
T_1 V_45 , V_46 ;
V_45 = F_22 ( V_47 ) ;
V_46 = F_22 ( V_48 ) ;
F_23 ( V_45 , V_49 ) ;
F_23 ( V_46 , V_50 ) ;
V_41 = 1 ;
}
F_9 ( V_37 , V_42 ) ;
( void ) F_8 ( V_42 ) ;
F_24 () ;
if ( ! V_41 )
return V_51 ;
return V_52 ;
}
void F_25 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
if ( F_21 ( V_19 ) )
F_9 ( 0xFFFFFFFF , V_54 ) ;
if ( V_19 -> V_55 [ 0 ] )
V_15 -> V_22 |= V_8 ;
if ( V_19 -> V_55 [ 1 ] )
V_15 -> V_22 |= V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
}
int F_28 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_9 ( 0xFFFFFFFF , V_54 ) ;
if ( V_19 -> V_55 [ 0 ] )
F_6 ( V_15 , 0 , V_56 ) ;
else
F_11 ( V_15 , 0 , V_56 ) ;
if ( V_19 -> V_55 [ 1 ] )
F_6 ( V_15 , 1 , V_56 ) ;
else
F_11 ( V_15 , 1 , V_56 ) ;
if ( V_19 -> V_55 [ 2 ] )
F_6 ( V_15 , 2 , V_56 ) ;
else
F_11 ( V_15 , 2 , V_56 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
return 0 ;
}
void F_29 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_9 ( 0xFFFFFFFF , V_54 ) ;
if ( V_19 -> V_55 [ 0 ] )
F_11 ( V_15 , 0 , V_56 ) ;
if ( V_19 -> V_55 [ 1 ] )
F_11 ( V_15 , 1 , V_56 ) ;
if ( V_19 -> V_55 [ 2 ] )
F_11 ( V_15 , 2 , V_56 ) ;
V_15 -> V_22 &= V_44 |
V_57 |
V_58 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_30 () ;
F_9 ( F_8 ( V_42 ) , V_42 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
}
void F_31 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_59 ;
T_1 V_60 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 1 << 31 , V_61 ) ;
V_59 = F_8 ( V_61 ) ;
F_9 ( 1 << 31 , V_62 ) ;
V_59 = F_8 ( V_62 ) ;
F_9 ( 0x80010100 , V_63 ) ;
V_60 = F_8 ( V_63 ) ;
F_9 ( V_60 | V_64
| V_65 ,
V_63 ) ;
V_60 = F_8 ( V_63 ) ;
F_6 ( V_15 , 0 , V_66 ) ;
V_59 = F_8 ( V_62 ) ;
F_9 ( V_59 | V_67 ,
V_62 ) ;
V_60 = F_8 ( V_63 ) ;
F_9 ( V_60 | 0x80010100 | V_64 ,
V_63 ) ;
F_10 ( V_19 ) ;
}
}
int F_32 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_12 ( V_15 , 0 ) ;
F_31 ( V_19 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
return 0 ;
}
void F_33 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_59 ;
T_1 V_60 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 0x00000000 , V_62 ) ;
V_59 = F_8 ( V_62 ) ;
F_11 ( V_15 , 0 , V_66 ) ;
V_60 = F_8 ( V_63 ) ;
F_9 ( V_60 & ! ( V_65 ) ,
V_63 ) ;
V_60 = F_8 ( V_63 ) ;
F_10 ( V_19 ) ;
}
}
int F_34 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_13 ( V_15 , 0 ) ;
F_33 ( V_19 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_19 ,
unsigned int * V_68 , T_5 * V_69 )
{
unsigned int V_70 ;
int V_71 = 0 ;
F_36 ( V_71 , V_19 -> V_72 , 3 * V_73 ,
( ( ( V_70 = F_37 ( V_69 ) )
- * V_68 ) <= ( 1 << 23 ) ) ) ;
* V_68 = V_70 ;
return V_71 ;
}
int F_38 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_53 ;
T_2 V_74 = 0 ;
T_2 V_75 = F_5 ( V_1 ) ;
if ( F_39 ( V_19 ) )
return F_40 ( V_19 , V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_74 = F_41 ( V_75 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_74 & V_76 ) )
return - V_77 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
if ( V_1 == 0 )
V_15 -> V_22 |= V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 |= V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_6 ( V_15 , V_1 , V_56 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
return 0 ;
}
void F_42 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_53 ;
if ( F_39 ( V_19 ) )
F_43 ( V_19 , V_1 ) ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
if ( V_1 == 0 )
V_15 -> V_22 &= ~ V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 &= ~ V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_11 ( V_15 , V_1 , V_56 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
}
int F_40 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
T_2 V_74 = 0 ;
T_2 V_75 = F_5 ( V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_74 = F_41 ( V_75 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_74 & V_76 ) )
return - V_77 ;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_12 ( V_15 , V_1 ) ;
F_6 ( V_15 , V_1 , V_78 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
return 0 ;
}
void F_43 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
if ( ! V_15 -> V_79 )
return;
F_26 ( & V_15 -> V_33 , V_53 ) ;
F_13 ( V_15 , V_1 ) ;
F_11 ( V_15 , V_1 , V_78 ) ;
F_27 ( & V_15 -> V_33 , V_53 ) ;
}
T_1 F_44 ( struct V_25 * V_19 , int V_1 )
{
T_2 V_80 = V_81 ;
T_2 V_82 = V_83 ;
T_2 V_75 = V_11 ;
T_2 V_74 = 0 ;
T_2 V_84 = 0 , V_85 = 0 , V_86 = 0 , V_87 = 0 ;
switch ( V_1 ) {
case 0 :
break;
case 1 :
V_80 = V_88 ;
V_82 = V_89 ;
V_75 = V_12 ;
break;
case 2 :
V_80 = V_90 ;
V_82 = V_91 ;
V_75 = V_13 ;
break;
default:
F_17 ( V_19 -> V_19 , L_2 , V_34 ) ;
return 0 ;
}
if ( ! F_7 ( V_19 , false ) )
return 0 ;
V_74 = F_41 ( V_75 ) ;
if ( ! ( V_74 & V_76 ) ) {
F_17 ( V_19 -> V_19 , L_3 ,
V_1 ) ;
goto V_92;
}
do {
V_84 = ( ( F_41 ( V_80 ) & V_93 ) >>
V_94 ) ;
V_86 = ( ( F_41 ( V_82 ) & V_95 ) >>
V_96 ) ;
V_85 = ( ( F_41 ( V_80 ) & V_93 ) >>
V_94 ) ;
} while ( V_84 != V_85 );
V_87 = ( V_84 << 8 ) | V_86 ;
V_92:
F_10 ( V_19 ) ;
return V_87 ;
}
