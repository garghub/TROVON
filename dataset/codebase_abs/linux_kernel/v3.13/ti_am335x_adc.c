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
static T_1 F_6 ( struct V_1 * V_7 , int V_11 )
{
return 1 << V_7 -> V_12 [ V_11 ] ;
}
static void F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
unsigned int V_15 ;
int V_16 , V_17 ;
V_17 = V_10 - V_7 -> V_9 ;
if ( F_9 ( V_14 ) )
V_15 = V_18 | V_19
| V_20 ;
else
V_15 = V_18 | V_19 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_9 ; V_16 ++ ) {
int V_11 ;
V_11 = V_7 -> V_21 [ V_16 ] ;
F_3 ( V_7 , F_10 ( V_17 ) ,
V_15 | F_11 ( V_11 ) ) ;
F_3 ( V_7 , F_12 ( V_17 ) ,
V_22 ) ;
V_7 -> V_12 [ V_16 ] = V_17 ;
V_17 ++ ;
}
}
static T_2 F_13 ( int V_23 , void * V_24 )
{
struct V_13 * V_14 = V_24 ;
struct V_1 * V_7 = F_8 ( V_14 ) ;
unsigned int V_25 , V_26 ;
V_25 = F_1 ( V_7 , V_27 ) ;
if ( V_25 & V_28 ) {
V_26 = F_1 ( V_7 , V_29 ) ;
V_26 &= ~ ( V_30 ) ;
F_3 ( V_7 , V_29 , V_26 ) ;
F_3 ( V_7 , V_27 , V_28
| V_31 | V_32 ) ;
F_3 ( V_7 , V_29 , ( V_26 | V_30 ) ) ;
return V_33 ;
} else if ( V_25 & V_32 ) {
F_3 ( V_7 , V_34 , V_32 ) ;
return V_35 ;
}
return V_36 ;
}
static T_2 F_14 ( int V_23 , void * V_24 )
{
struct V_13 * V_14 = V_24 ;
struct V_1 * V_7 = F_8 ( V_14 ) ;
int V_16 , V_37 , V_38 , V_39 ;
T_3 * V_40 = V_7 -> V_40 ;
V_38 = F_1 ( V_7 , V_41 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 = V_37 + V_16 ) {
for ( V_16 = 0 ; V_16 < ( V_14 -> V_42 ) / 2 ; V_16 ++ ) {
V_39 = F_1 ( V_7 , V_43 ) ;
V_40 [ V_16 ] = V_39 & V_44 ;
}
F_15 ( V_14 , ( V_45 * ) V_40 ) ;
}
F_3 ( V_7 , V_27 , V_32 ) ;
F_3 ( V_7 , V_46 , V_32 ) ;
return V_33 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
int V_16 , V_38 , V_39 ;
F_3 ( V_7 , V_34 , ( V_32 |
V_28 |
V_31 ) ) ;
V_38 = F_1 ( V_7 , V_41 ) ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ )
V_39 = F_1 ( V_7 , V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
struct V_47 * V_48 = V_14 -> V_48 ;
unsigned int V_49 = 0 ;
V_45 V_50 ;
F_7 ( V_14 ) ;
F_18 (bit, buffer->scan_mask, adc_dev->channels)
V_49 |= ( F_6 ( V_7 , V_50 ) << 1 ) ;
V_7 -> V_51 = V_49 ;
F_19 ( V_7 -> V_4 , V_49 ) ;
F_3 ( V_7 , V_27 , V_32
| V_28 | V_31 ) ;
F_3 ( V_7 , V_46 , V_32
| V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
int V_38 , V_16 , V_39 ;
F_3 ( V_7 , V_34 , ( V_32 |
V_28 | V_31 ) ) ;
F_21 ( V_7 -> V_4 , V_7 -> V_51 ) ;
V_38 = F_1 ( V_7 , V_41 ) ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ )
V_39 = F_1 ( V_7 , V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
F_7 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 ,
T_2 (* F_24)( int V_23 , void * V_52 ) ,
T_2 (* F_25)( int V_23 , void * V_52 ) ,
int V_23 ,
unsigned long V_53 ,
const struct V_54 * V_55 )
{
struct V_47 * V_48 ;
int V_56 ;
V_48 = F_26 ( V_14 ) ;
if ( ! V_48 )
return - V_57 ;
F_27 ( V_14 , V_48 ) ;
V_56 = F_28 ( V_23 , F_25 , F_24 ,
V_53 , V_14 -> V_58 , V_14 ) ;
if ( V_56 )
goto V_59;
V_14 -> V_55 = V_55 ;
V_14 -> V_60 |= V_61 ;
V_56 = F_29 ( V_14 ,
V_14 -> V_9 ,
V_14 -> V_62 ) ;
if ( V_56 )
goto V_63;
return 0 ;
V_63:
F_30 ( V_23 , V_14 ) ;
V_59:
F_31 ( V_14 -> V_48 ) ;
return V_56 ;
}
static void F_32 ( struct V_13 * V_14 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
F_30 ( V_7 -> V_4 -> V_23 , V_14 ) ;
F_31 ( V_14 -> V_48 ) ;
F_33 ( V_14 ) ;
}
static int F_34 ( struct V_13 * V_14 , int V_9 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
struct V_64 * V_65 ;
struct V_64 * V_11 ;
int V_16 ;
V_14 -> V_62 = V_9 ;
V_65 = F_35 ( V_9 ,
sizeof( struct V_64 ) , V_66 ) ;
if ( V_65 == NULL )
return - V_57 ;
V_11 = V_65 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ , V_11 ++ ) {
V_11 -> type = V_67 ;
V_11 -> V_68 = 1 ;
V_11 -> V_69 = V_7 -> V_21 [ V_16 ] ;
V_11 -> V_70 = F_36 ( V_71 ) ;
V_11 -> V_72 = V_73 [ V_11 -> V_69 ] ;
V_11 -> V_74 = V_16 ;
V_11 -> V_75 . V_76 = 'u' ;
V_11 -> V_75 . V_77 = 12 ;
V_11 -> V_75 . V_78 = 16 ;
}
V_14 -> V_9 = V_65 ;
return 0 ;
}
static void F_37 ( struct V_13 * V_14 )
{
F_38 ( V_14 -> V_9 ) ;
}
static int F_39 ( struct V_13 * V_14 ,
struct V_64 const * V_11 ,
int * V_6 , int * V_79 , long V_80 )
{
struct V_1 * V_7 = F_8 ( V_14 ) ;
int V_16 , V_81 ;
unsigned int V_38 , V_39 , V_82 ;
bool V_83 = false ;
T_1 V_8 ;
unsigned long V_84 = V_85 + F_40
( V_86 * V_7 -> V_9 ) ;
if ( F_9 ( V_14 ) )
return - V_87 ;
V_8 = F_5 ( V_7 ) ;
F_19 ( V_7 -> V_4 , V_8 ) ;
while ( F_1 ( V_7 , V_88 ) & V_89 ) {
if ( F_41 ( V_85 , V_84 ) )
return - V_90 ;
}
V_81 = V_11 -> V_69 + V_91 ;
V_38 = F_1 ( V_7 , V_41 ) ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
V_39 = F_1 ( V_7 , V_43 ) ;
V_82 = V_39 & V_92 ;
V_82 = V_82 >> 0x10 ;
if ( V_82 == V_81 ) {
V_39 = V_39 & V_44 ;
V_83 = true ;
* V_6 = ( T_3 ) V_39 ;
}
}
if ( V_83 == false )
return - V_87 ;
return V_93 ;
}
static int F_42 ( struct V_94 * V_95 )
{
struct V_13 * V_14 ;
struct V_1 * V_7 ;
struct V_96 * V_97 = V_95 -> V_98 . V_99 ;
struct V_100 * V_101 ;
const T_4 * V_102 ;
int V_103 ;
T_1 V_6 ;
int V_9 = 0 ;
if ( ! V_97 ) {
F_43 ( & V_95 -> V_98 , L_1 ) ;
return - V_104 ;
}
V_14 = F_44 ( & V_95 -> V_98 ,
sizeof( struct V_1 ) ) ;
if ( V_14 == NULL ) {
F_43 ( & V_95 -> V_98 , L_2 ) ;
return - V_57 ;
}
V_7 = F_8 ( V_14 ) ;
V_7 -> V_4 = F_45 ( V_95 ) ;
F_46 (node, L_3 , prop, cur, val) {
V_7 -> V_21 [ V_9 ] = V_6 ;
V_9 ++ ;
}
V_7 -> V_9 = V_9 ;
V_14 -> V_98 . V_105 = & V_95 -> V_98 ;
V_14 -> V_58 = F_47 ( & V_95 -> V_98 ) ;
V_14 -> V_60 = V_106 ;
V_14 -> V_107 = & V_108 ;
F_7 ( V_14 ) ;
F_3 ( V_7 , V_109 , V_110 ) ;
V_103 = F_34 ( V_14 , V_7 -> V_9 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_23 ( V_14 ,
& F_14 ,
& F_13 ,
V_7 -> V_4 -> V_23 ,
V_111 ,
& V_112 ) ;
if ( V_103 )
goto V_113;
V_103 = F_48 ( V_14 ) ;
if ( V_103 )
goto V_114;
F_49 ( V_95 , V_14 ) ;
return 0 ;
V_114:
F_32 ( V_14 ) ;
V_113:
F_37 ( V_14 ) ;
return V_103 ;
}
static int F_50 ( struct V_94 * V_95 )
{
struct V_13 * V_14 = F_51 ( V_95 ) ;
struct V_1 * V_7 = F_8 ( V_14 ) ;
T_1 V_8 ;
F_52 ( V_14 ) ;
F_32 ( V_14 ) ;
F_37 ( V_14 ) ;
V_8 = F_5 ( V_7 ) ;
F_21 ( V_7 -> V_4 , V_8 ) ;
return 0 ;
}
static int F_53 ( struct V_115 * V_98 )
{
struct V_13 * V_14 = F_54 ( V_98 ) ;
struct V_1 * V_7 = F_8 ( V_14 ) ;
struct V_116 * V_117 ;
unsigned int V_118 ;
V_117 = F_45 ( F_55 ( V_98 ) ) ;
if ( ! F_56 ( V_117 -> V_98 ) ) {
V_118 = F_1 ( V_7 , V_29 ) ;
V_118 &= ~ ( V_30 ) ;
F_3 ( V_7 , V_29 , ( V_118 |
V_119 ) ) ;
}
return 0 ;
}
static int F_57 ( struct V_115 * V_98 )
{
struct V_13 * V_14 = F_54 ( V_98 ) ;
struct V_1 * V_7 = F_8 ( V_14 ) ;
unsigned int V_120 ;
V_120 = F_1 ( V_7 , V_29 ) ;
V_120 &= ~ ( V_119 ) ;
F_3 ( V_7 , V_29 , V_120 ) ;
F_7 ( V_14 ) ;
return 0 ;
}
