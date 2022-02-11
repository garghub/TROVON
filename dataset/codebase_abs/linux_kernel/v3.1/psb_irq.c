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
void F_12 ( struct V_14 * V_15 , int V_1 )
{
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_21 = F_3 ( V_1 ) ;
V_15 -> V_22 |= V_21 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
void F_13 ( struct V_14 * V_15 , int V_1 )
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
static void F_14 ( struct V_25 * V_19 , T_2 V_1 )
{
F_15 ( V_19 , V_1 ) ;
}
static void F_16 ( struct V_25 * V_19 , T_2 V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_2 V_27 = 0 ;
T_2 V_28 = F_1 ( V_1 ) ;
T_2 V_29 = V_15 -> V_17 [ V_1 ] ;
T_2 V_30 = V_15 -> V_17 [ V_1 ] >> 16 ;
T_2 V_31 = 0 ;
F_17 ( & V_15 -> V_32 ) ;
V_27 = F_8 ( V_28 ) ;
V_27 &= V_29 | V_30 ;
V_27 &= V_27 >> 16 ;
F_18 ( & V_15 -> V_32 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
F_9 ( F_8 ( V_28 ) , V_28 ) ;
( void ) F_8 ( V_28 ) ;
if ( ( F_8 ( V_28 ) & V_30 ) == 0 )
break;
}
if ( V_31 == V_33 )
F_19 ( V_19 -> V_19 ,
L_1 ,
V_34 , F_8 ( V_28 ) ) ;
if ( V_27 & V_35 )
F_14 ( V_19 , V_1 ) ;
if ( V_27 & V_36 )
F_15 ( V_19 , V_1 ) ;
}
static void F_20 ( struct V_25 * V_19 , T_2 V_37 )
{
if ( V_37 & V_5 )
F_16 ( V_19 , 0 ) ;
}
T_3 F_21 ( T_4 )
{
struct V_25 * V_19 = (struct V_25 * ) V_38 ;
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_2 V_37 , V_39 = 0 , V_40 = 0 ;
int V_41 = 0 ;
F_17 ( & V_15 -> V_32 ) ;
V_37 = F_8 ( V_42 ) ;
if ( V_37 & V_43 )
V_39 = 1 ;
if ( V_37 & V_44 )
V_40 = 1 ;
V_37 &= V_15 -> V_22 ;
F_18 ( & V_15 -> V_32 ) ;
if ( V_39 && F_22 ( V_19 ) ) {
F_20 ( V_19 , V_37 ) ;
V_41 = 1 ;
}
if ( V_40 ) {
T_1 V_45 , V_46 ;
V_45 = F_23 ( V_47 ) ;
V_46 = F_23 ( V_48 ) ;
F_24 ( V_45 , V_49 ) ;
F_24 ( V_46 , V_50 ) ;
V_41 = 1 ;
}
F_9 ( V_37 , V_42 ) ;
( void ) F_8 ( V_42 ) ;
F_25 () ;
if ( ! V_41 )
return V_51 ;
return V_52 ;
}
void F_26 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
if ( F_22 ( V_19 ) )
F_9 ( 0xFFFFFFFF , V_54 ) ;
if ( V_19 -> V_55 [ 0 ] )
V_15 -> V_22 |= V_5 ;
if ( V_19 -> V_55 [ 1 ] )
V_15 -> V_22 |= V_6 ;
if ( V_19 -> V_55 [ 2 ] )
V_15 -> V_22 |= V_7 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
}
int F_29 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
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
F_28 ( & V_15 -> V_32 , V_53 ) ;
return 0 ;
}
void F_30 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
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
F_31 () ;
F_9 ( F_8 ( V_42 ) , V_42 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
}
void F_32 ( struct V_25 * V_19 )
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
int F_33 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
F_12 ( V_15 , 0 ) ;
F_32 ( V_19 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
return 0 ;
}
void F_34 ( struct V_25 * V_19 )
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
int F_35 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_53 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
F_13 ( V_15 , 0 ) ;
F_34 ( V_19 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_19 ,
unsigned int * V_68 , T_5 * V_69 )
{
unsigned int V_70 ;
int V_71 = 0 ;
F_37 ( V_71 , V_19 -> V_72 , 3 * V_73 ,
( ( ( V_70 = F_38 ( V_69 ) )
- * V_68 ) <= ( 1 << 23 ) ) ) ;
* V_68 = V_70 ;
return V_71 ;
}
int F_39 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_53 ;
T_2 V_74 = 0 ;
T_2 V_75 = F_5 ( V_1 ) ;
#if F_40 ( V_76 )
if ( F_41 ( V_19 ) && ! F_42 ( V_19 ) )
return F_43 ( V_19 , V_1 ) ;
#endif
if ( F_7 ( V_19 , false ) ) {
V_74 = F_44 ( V_75 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_74 & V_77 ) )
return - V_78 ;
F_27 ( & V_15 -> V_32 , V_53 ) ;
F_12 ( V_15 , V_1 ) ;
F_6 ( V_15 , V_1 , V_56 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
return 0 ;
}
void F_45 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_53 ;
#if F_40 ( V_76 )
if ( F_41 ( V_19 ) && ! F_42 ( V_19 ) )
F_46 ( V_19 , V_1 ) ;
#endif
F_27 ( & V_15 -> V_32 , V_53 ) ;
F_13 ( V_15 , V_1 ) ;
F_11 ( V_15 , V_1 , V_56 ) ;
F_28 ( & V_15 -> V_32 , V_53 ) ;
}
int F_43 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
T_2 V_74 = 0 ;
T_2 V_75 = F_5 ( V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_74 = F_44 ( V_75 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_74 & V_77 ) )
return - V_78 ;
F_27 ( & V_15 -> V_32 , V_79 ) ;
F_12 ( V_15 , V_1 ) ;
F_6 ( V_15 , V_1 , V_80 ) ;
F_28 ( & V_15 -> V_32 , V_79 ) ;
return 0 ;
}
void F_46 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
F_27 ( & V_15 -> V_32 , V_79 ) ;
F_13 ( V_15 , V_1 ) ;
F_11 ( V_15 , V_1 , V_80 ) ;
F_28 ( & V_15 -> V_32 , V_79 ) ;
}
T_1 F_47 ( struct V_25 * V_19 , int V_1 )
{
T_2 V_81 = V_82 ;
T_2 V_83 = V_84 ;
T_2 V_75 = V_11 ;
T_2 V_74 = 0 ;
T_2 V_85 = 0 , V_86 = 0 , V_87 = 0 , V_88 = 0 ;
switch ( V_1 ) {
case 0 :
break;
case 1 :
V_81 = V_89 ;
V_83 = V_90 ;
V_75 = V_12 ;
break;
case 2 :
V_81 = V_91 ;
V_83 = V_92 ;
V_75 = V_13 ;
break;
default:
F_19 ( V_19 -> V_19 , L_2 , V_34 ) ;
return 0 ;
}
if ( ! F_7 ( V_19 , false ) )
return 0 ;
V_74 = F_44 ( V_75 ) ;
if ( ! ( V_74 & V_77 ) ) {
F_19 ( V_19 -> V_19 , L_3 ,
V_1 ) ;
goto V_93;
}
do {
V_85 = ( ( F_44 ( V_81 ) & V_94 ) >>
V_95 ) ;
V_87 = ( ( F_44 ( V_83 ) & V_96 ) >>
V_97 ) ;
V_86 = ( ( F_44 ( V_81 ) & V_94 ) >>
V_95 ) ;
} while ( V_85 != V_86 );
V_88 = ( V_85 << 8 ) | V_87 ;
V_93:
F_10 ( V_19 ) ;
return V_88 ;
}
