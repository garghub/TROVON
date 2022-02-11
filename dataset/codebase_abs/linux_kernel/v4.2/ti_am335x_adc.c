static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_7 )
{
T_1 V_8 ;
V_8 = ( ( 1 << V_7 -> V_9 ) - 1 ) ;
V_8 <<= V_10 - V_7 -> V_9 + 1 ;
return V_8 ;
}
static T_1 F_6 ( struct V_1 * V_7 ,
struct V_11 const * V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_7 ( V_7 -> V_14 ) ; V_13 ++ ) {
if ( V_12 -> V_15 == V_7 -> V_16 [ V_13 ] ) {
T_1 V_17 ;
V_17 = V_7 -> V_14 [ V_13 ] ;
return 1 << ( V_17 + 1 ) ;
}
}
F_8 ( 1 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_7 , int V_12 )
{
return 1 << V_7 -> V_14 [ V_12 ] ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_20 * V_21 = V_7 -> V_4 -> V_21 ;
unsigned int V_22 ;
int V_13 , V_23 = 0 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_9 ; V_13 ++ ) {
int V_12 ;
V_12 = V_7 -> V_16 [ V_13 ] ;
if ( V_7 -> V_24 [ V_13 ] > V_25 ) {
F_12 ( V_21 , L_1 ,
V_12 , V_25 ) ;
V_7 -> V_24 [ V_13 ] = V_25 ;
}
if ( V_7 -> V_24 [ V_13 ] )
V_22 =
F_13 ( F_14 ( V_7 -> V_24 [ V_13 ] ) - 1 ) |
V_26 ;
else
V_22 = V_26 ;
if ( F_15 ( V_19 ) )
V_22 |= V_27 ;
F_3 ( V_7 , F_16 ( V_23 ) ,
V_22 | F_17 ( V_12 ) ) ;
if ( V_7 -> V_28 [ V_13 ] > V_29 ) {
F_12 ( V_21 , L_2 ,
V_12 ) ;
V_7 -> V_28 [ V_13 ] = V_29 ;
}
if ( V_7 -> V_30 [ V_13 ] > 0xFF ) {
F_12 ( V_21 , L_3 ,
V_12 ) ;
V_7 -> V_30 [ V_13 ] = 0xFF ;
}
F_3 ( V_7 , F_18 ( V_23 ) ,
F_19 ( V_7 -> V_28 [ V_13 ] ) |
F_20 ( V_7 -> V_30 [ V_13 ] ) ) ;
V_7 -> V_14 [ V_13 ] = V_23 ;
V_23 ++ ;
}
}
static T_2 F_21 ( int V_31 , void * V_32 )
{
struct V_18 * V_19 = V_32 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_33 , V_34 ;
V_33 = F_1 ( V_7 , V_35 ) ;
if ( V_33 & V_36 ) {
V_34 = F_1 ( V_7 , V_37 ) ;
V_34 &= ~ ( V_38 ) ;
F_3 ( V_7 , V_37 , V_34 ) ;
F_3 ( V_7 , V_35 , V_36
| V_39 | V_40 ) ;
F_3 ( V_7 , V_37 , ( V_34 | V_38 ) ) ;
return V_41 ;
} else if ( V_33 & V_40 ) {
F_3 ( V_7 , V_42 , V_40 ) ;
return V_43 ;
}
return V_44 ;
}
static T_2 F_22 ( int V_31 , void * V_32 )
{
struct V_18 * V_19 = V_32 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_45 , V_46 , V_47 ;
T_3 * V_48 = V_7 -> V_48 ;
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 = V_45 + V_13 ) {
for ( V_13 = 0 ; V_13 < ( V_19 -> V_50 ) / 2 ; V_13 ++ ) {
V_47 = F_1 ( V_7 , V_51 ) ;
V_48 [ V_13 ] = V_47 & V_52 ;
}
F_23 ( V_19 , ( V_53 * ) V_48 ) ;
}
F_3 ( V_7 , V_35 , V_40 ) ;
F_3 ( V_7 , V_54 , V_40 ) ;
return V_41 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_46 , V_47 ;
F_3 ( V_7 , V_42 , ( V_40 |
V_36 |
V_39 ) ) ;
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ )
V_47 = F_1 ( V_7 , V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_55 = 0 ;
V_53 V_56 ;
F_10 ( V_19 ) ;
F_26 (bit, indio_dev->active_scan_mask, adc_dev->channels)
V_55 |= ( F_9 ( V_7 , V_56 ) << 1 ) ;
V_7 -> V_57 = V_55 ;
F_27 ( V_7 -> V_4 , V_55 ) ;
F_3 ( V_7 , V_35 , V_40
| V_36 | V_39 ) ;
F_3 ( V_7 , V_54 , V_40
| V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_46 , V_13 , V_47 ;
F_3 ( V_7 , V_42 , ( V_40 |
V_36 | V_39 ) ) ;
F_29 ( V_7 -> V_4 , V_7 -> V_57 ) ;
V_7 -> V_57 = 0 ;
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ )
V_47 = F_1 ( V_7 , V_51 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 )
{
F_10 ( V_19 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 ,
T_2 (* F_32)( int V_31 , void * V_58 ) ,
T_2 (* F_33)( int V_31 , void * V_58 ) ,
int V_31 ,
unsigned long V_59 ,
const struct V_60 * V_61 )
{
struct V_62 * V_63 ;
int V_64 ;
V_63 = F_34 () ;
if ( ! V_63 )
return - V_65 ;
F_35 ( V_19 , V_63 ) ;
V_64 = F_36 ( V_31 , F_33 , F_32 ,
V_59 , V_19 -> V_66 , V_19 ) ;
if ( V_64 )
goto V_67;
V_19 -> V_61 = V_61 ;
V_19 -> V_68 |= V_69 ;
return 0 ;
V_67:
F_37 ( V_19 -> V_63 ) ;
return V_64 ;
}
static void F_38 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
F_39 ( V_7 -> V_4 -> V_31 , V_19 ) ;
F_37 ( V_19 -> V_63 ) ;
}
static int F_40 ( struct V_18 * V_19 , int V_9 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_11 * V_70 ;
struct V_11 * V_12 ;
int V_13 ;
V_19 -> V_71 = V_9 ;
V_70 = F_41 ( V_9 ,
sizeof( struct V_11 ) , V_72 ) ;
if ( V_70 == NULL )
return - V_65 ;
V_12 = V_70 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ , V_12 ++ ) {
V_12 -> type = V_73 ;
V_12 -> V_74 = 1 ;
V_12 -> V_15 = V_7 -> V_16 [ V_13 ] ;
V_12 -> V_75 = F_42 ( V_76 ) ;
V_12 -> V_77 = V_78 [ V_12 -> V_15 ] ;
V_12 -> V_79 = V_13 ;
V_12 -> V_80 . V_81 = 'u' ;
V_12 -> V_80 . V_82 = 12 ;
V_12 -> V_80 . V_83 = 16 ;
}
V_19 -> V_9 = V_70 ;
return 0 ;
}
static void F_43 ( struct V_18 * V_19 )
{
F_44 ( V_19 -> V_9 ) ;
}
static int F_45 ( struct V_18 * V_19 ,
struct V_11 const * V_12 ,
int * V_6 , int * V_84 , long V_85 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_86 ;
unsigned int V_46 , V_47 , V_87 ;
bool V_88 = false ;
T_1 V_8 ;
unsigned long V_89 ;
if ( F_15 ( V_19 ) )
return - V_90 ;
V_8 = F_6 ( V_7 , V_12 ) ;
if ( ! V_8 )
return - V_91 ;
V_46 = F_1 ( V_7 , V_49 ) ;
while ( V_46 -- )
F_1 ( V_7 , V_51 ) ;
F_46 ( V_7 -> V_4 , V_8 ) ;
V_89 = V_92 + F_47
( V_93 * V_7 -> V_9 ) ;
while ( 1 ) {
V_46 = F_1 ( V_7 , V_49 ) ;
if ( V_46 )
break;
if ( F_48 ( V_92 , V_89 ) ) {
F_49 ( V_7 -> V_4 ) ;
return - V_94 ;
}
}
V_86 = V_7 -> V_14 [ V_12 -> V_79 ] ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ ) {
V_47 = F_1 ( V_7 , V_51 ) ;
V_87 = V_47 & V_95 ;
V_87 = V_87 >> 0x10 ;
if ( V_87 == V_86 ) {
V_47 = V_47 & V_52 ;
V_88 = true ;
* V_6 = ( T_3 ) V_47 ;
}
}
F_49 ( V_7 -> V_4 ) ;
if ( V_88 == false )
return - V_90 ;
return V_96 ;
}
static int F_50 ( struct V_97 * V_98 ,
struct V_1 * V_7 )
{
struct V_99 * V_100 = V_98 -> V_21 . V_101 ;
struct V_102 * V_103 ;
const T_4 * V_104 ;
int V_9 = 0 ;
T_1 V_6 ;
F_51 (node, L_4 , prop, cur, val) {
V_7 -> V_16 [ V_9 ] = V_6 ;
V_7 -> V_28 [ V_9 ] = V_105 ;
V_7 -> V_30 [ V_9 ] = V_106 ;
V_7 -> V_24 [ V_9 ] = 16 ;
V_9 ++ ;
}
F_52 ( V_100 , L_5 ,
V_7 -> V_24 , V_9 ) ;
F_52 ( V_100 , L_6 ,
V_7 -> V_28 , V_9 ) ;
F_52 ( V_100 , L_7 ,
V_7 -> V_30 , V_9 ) ;
V_7 -> V_9 = V_9 ;
return 0 ;
}
static int F_53 ( struct V_97 * V_98 )
{
struct V_18 * V_19 ;
struct V_1 * V_7 ;
struct V_99 * V_100 = V_98 -> V_21 . V_101 ;
int V_107 ;
if ( ! V_100 ) {
F_54 ( & V_98 -> V_21 , L_8 ) ;
return - V_91 ;
}
V_19 = F_55 ( & V_98 -> V_21 ,
sizeof( struct V_1 ) ) ;
if ( V_19 == NULL ) {
F_54 ( & V_98 -> V_21 , L_9 ) ;
return - V_65 ;
}
V_7 = F_11 ( V_19 ) ;
V_7 -> V_4 = F_56 ( V_98 ) ;
F_50 ( V_98 , V_7 ) ;
V_19 -> V_21 . V_108 = & V_98 -> V_21 ;
V_19 -> V_66 = F_57 ( & V_98 -> V_21 ) ;
V_19 -> V_68 = V_109 ;
V_19 -> V_110 = & V_111 ;
F_10 ( V_19 ) ;
F_3 ( V_7 , V_112 , V_113 ) ;
V_107 = F_40 ( V_19 , V_7 -> V_9 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_31 ( V_19 ,
& F_22 ,
& F_21 ,
V_7 -> V_4 -> V_31 ,
V_114 ,
& V_115 ) ;
if ( V_107 )
goto V_116;
V_107 = F_58 ( V_19 ) ;
if ( V_107 )
goto V_117;
F_59 ( V_98 , V_19 ) ;
return 0 ;
V_117:
F_38 ( V_19 ) ;
V_116:
F_43 ( V_19 ) ;
return V_107 ;
}
static int F_60 ( struct V_97 * V_98 )
{
struct V_18 * V_19 = F_61 ( V_98 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
T_1 V_8 ;
F_62 ( V_19 ) ;
F_38 ( V_19 ) ;
F_43 ( V_19 ) ;
V_8 = F_5 ( V_7 ) ;
F_29 ( V_7 -> V_4 , V_8 ) ;
return 0 ;
}
static int F_63 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_64 ( V_21 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_118 * V_119 ;
unsigned int V_120 ;
V_119 = F_56 ( F_65 ( V_21 ) ) ;
if ( ! F_66 ( V_119 -> V_21 ) ) {
V_120 = F_1 ( V_7 , V_37 ) ;
V_120 &= ~ ( V_38 ) ;
F_3 ( V_7 , V_37 , ( V_120 |
V_121 ) ) ;
}
return 0 ;
}
static int F_67 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_64 ( V_21 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_122 ;
V_122 = F_1 ( V_7 , V_37 ) ;
V_122 &= ~ ( V_121 ) ;
F_3 ( V_7 , V_37 , V_122 ) ;
F_10 ( V_19 ) ;
F_27 ( V_7 -> V_4 ,
V_7 -> V_57 ) ;
return 0 ;
}
