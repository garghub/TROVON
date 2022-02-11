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
unsigned int V_20 ;
int V_13 , V_21 ;
V_21 = V_10 - V_7 -> V_9 ;
if ( F_12 ( V_19 ) )
V_20 = V_22 | V_23
| V_24 ;
else
V_20 = V_22 | V_23 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_9 ; V_13 ++ ) {
int V_12 ;
V_12 = V_7 -> V_16 [ V_13 ] ;
F_3 ( V_7 , F_13 ( V_21 ) ,
V_20 | F_14 ( V_12 ) ) ;
F_3 ( V_7 , F_15 ( V_21 ) ,
V_25 ) ;
V_7 -> V_14 [ V_13 ] = V_21 ;
V_21 ++ ;
}
}
static T_2 F_16 ( int V_26 , void * V_27 )
{
struct V_18 * V_19 = V_27 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_28 , V_29 ;
V_28 = F_1 ( V_7 , V_30 ) ;
if ( V_28 & V_31 ) {
V_29 = F_1 ( V_7 , V_32 ) ;
V_29 &= ~ ( V_33 ) ;
F_3 ( V_7 , V_32 , V_29 ) ;
F_3 ( V_7 , V_30 , V_31
| V_34 | V_35 ) ;
F_3 ( V_7 , V_32 , ( V_29 | V_33 ) ) ;
return V_36 ;
} else if ( V_28 & V_35 ) {
F_3 ( V_7 , V_37 , V_35 ) ;
return V_38 ;
}
return V_39 ;
}
static T_2 F_17 ( int V_26 , void * V_27 )
{
struct V_18 * V_19 = V_27 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_40 , V_41 , V_42 ;
T_3 * V_43 = V_7 -> V_43 ;
V_41 = F_1 ( V_7 , V_44 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 = V_40 + V_13 ) {
for ( V_13 = 0 ; V_13 < ( V_19 -> V_45 ) / 2 ; V_13 ++ ) {
V_42 = F_1 ( V_7 , V_46 ) ;
V_43 [ V_13 ] = V_42 & V_47 ;
}
F_18 ( V_19 , ( V_48 * ) V_43 ) ;
}
F_3 ( V_7 , V_30 , V_35 ) ;
F_3 ( V_7 , V_49 , V_35 ) ;
return V_36 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_41 , V_42 ;
F_3 ( V_7 , V_37 , ( V_35 |
V_31 |
V_34 ) ) ;
V_41 = F_1 ( V_7 , V_44 ) ;
for ( V_13 = 0 ; V_13 < V_41 ; V_13 ++ )
V_42 = F_1 ( V_7 , V_46 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_50 * V_51 = V_19 -> V_51 ;
unsigned int V_52 = 0 ;
V_48 V_53 ;
F_10 ( V_19 ) ;
F_21 (bit, buffer->scan_mask, adc_dev->channels)
V_52 |= ( F_9 ( V_7 , V_53 ) << 1 ) ;
V_7 -> V_54 = V_52 ;
F_22 ( V_7 -> V_4 , V_52 ) ;
F_3 ( V_7 , V_30 , V_35
| V_31 | V_34 ) ;
F_3 ( V_7 , V_49 , V_35
| V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_41 , V_13 , V_42 ;
F_3 ( V_7 , V_37 , ( V_35 |
V_31 | V_34 ) ) ;
F_24 ( V_7 -> V_4 , V_7 -> V_54 ) ;
V_7 -> V_54 = 0 ;
V_41 = F_1 ( V_7 , V_44 ) ;
for ( V_13 = 0 ; V_13 < V_41 ; V_13 ++ )
V_42 = F_1 ( V_7 , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 )
{
F_10 ( V_19 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
T_2 (* F_27)( int V_26 , void * V_55 ) ,
T_2 (* F_28)( int V_26 , void * V_55 ) ,
int V_26 ,
unsigned long V_56 ,
const struct V_57 * V_58 )
{
struct V_50 * V_51 ;
int V_59 ;
V_51 = F_29 ( V_19 ) ;
if ( ! V_51 )
return - V_60 ;
F_30 ( V_19 , V_51 ) ;
V_59 = F_31 ( V_26 , F_28 , F_27 ,
V_56 , V_19 -> V_61 , V_19 ) ;
if ( V_59 )
goto V_62;
V_19 -> V_58 = V_58 ;
V_19 -> V_63 |= V_64 ;
V_59 = F_32 ( V_19 ,
V_19 -> V_9 ,
V_19 -> V_65 ) ;
if ( V_59 )
goto V_66;
return 0 ;
V_66:
F_33 ( V_26 , V_19 ) ;
V_62:
F_34 ( V_19 -> V_51 ) ;
return V_59 ;
}
static void F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
F_33 ( V_7 -> V_4 -> V_26 , V_19 ) ;
F_34 ( V_19 -> V_51 ) ;
F_36 ( V_19 ) ;
}
static int F_37 ( struct V_18 * V_19 , int V_9 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_11 * V_67 ;
struct V_11 * V_12 ;
int V_13 ;
V_19 -> V_65 = V_9 ;
V_67 = F_38 ( V_9 ,
sizeof( struct V_11 ) , V_68 ) ;
if ( V_67 == NULL )
return - V_60 ;
V_12 = V_67 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ , V_12 ++ ) {
V_12 -> type = V_69 ;
V_12 -> V_70 = 1 ;
V_12 -> V_15 = V_7 -> V_16 [ V_13 ] ;
V_12 -> V_71 = F_39 ( V_72 ) ;
V_12 -> V_73 = V_74 [ V_12 -> V_15 ] ;
V_12 -> V_75 = V_13 ;
V_12 -> V_76 . V_77 = 'u' ;
V_12 -> V_76 . V_78 = 12 ;
V_12 -> V_76 . V_79 = 16 ;
}
V_19 -> V_9 = V_67 ;
return 0 ;
}
static void F_40 ( struct V_18 * V_19 )
{
F_41 ( V_19 -> V_9 ) ;
}
static int F_42 ( struct V_18 * V_19 ,
struct V_11 const * V_12 ,
int * V_6 , int * V_80 , long V_81 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_82 ;
unsigned int V_41 , V_42 , V_83 ;
bool V_84 = false ;
T_1 V_8 ;
unsigned long V_85 ;
if ( F_12 ( V_19 ) )
return - V_86 ;
V_8 = F_6 ( V_7 , V_12 ) ;
if ( ! V_8 )
return - V_87 ;
V_41 = F_1 ( V_7 , V_44 ) ;
while ( V_41 -- )
F_1 ( V_7 , V_46 ) ;
F_43 ( V_7 -> V_4 , V_8 ) ;
V_85 = V_88 + F_44
( V_89 * V_7 -> V_9 ) ;
while ( 1 ) {
V_41 = F_1 ( V_7 , V_44 ) ;
if ( V_41 )
break;
if ( F_45 ( V_88 , V_85 ) ) {
F_46 ( V_7 -> V_4 ) ;
return - V_90 ;
}
}
V_82 = V_7 -> V_14 [ V_12 -> V_75 ] ;
for ( V_13 = 0 ; V_13 < V_41 ; V_13 ++ ) {
V_42 = F_1 ( V_7 , V_46 ) ;
V_83 = V_42 & V_91 ;
V_83 = V_83 >> 0x10 ;
if ( V_83 == V_82 ) {
V_42 = V_42 & V_47 ;
V_84 = true ;
* V_6 = ( T_3 ) V_42 ;
}
}
F_46 ( V_7 -> V_4 ) ;
if ( V_84 == false )
return - V_86 ;
return V_92 ;
}
static int F_47 ( struct V_93 * V_94 )
{
struct V_18 * V_19 ;
struct V_1 * V_7 ;
struct V_95 * V_96 = V_94 -> V_97 . V_98 ;
struct V_99 * V_100 ;
const T_4 * V_101 ;
int V_102 ;
T_1 V_6 ;
int V_9 = 0 ;
if ( ! V_96 ) {
F_48 ( & V_94 -> V_97 , L_1 ) ;
return - V_87 ;
}
V_19 = F_49 ( & V_94 -> V_97 ,
sizeof( struct V_1 ) ) ;
if ( V_19 == NULL ) {
F_48 ( & V_94 -> V_97 , L_2 ) ;
return - V_60 ;
}
V_7 = F_11 ( V_19 ) ;
V_7 -> V_4 = F_50 ( V_94 ) ;
F_51 (node, L_3 , prop, cur, val) {
V_7 -> V_16 [ V_9 ] = V_6 ;
V_9 ++ ;
}
V_7 -> V_9 = V_9 ;
V_19 -> V_97 . V_103 = & V_94 -> V_97 ;
V_19 -> V_61 = F_52 ( & V_94 -> V_97 ) ;
V_19 -> V_63 = V_104 ;
V_19 -> V_105 = & V_106 ;
F_10 ( V_19 ) ;
F_3 ( V_7 , V_107 , V_108 ) ;
V_102 = F_37 ( V_19 , V_7 -> V_9 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_26 ( V_19 ,
& F_17 ,
& F_16 ,
V_7 -> V_4 -> V_26 ,
V_109 ,
& V_110 ) ;
if ( V_102 )
goto V_111;
V_102 = F_53 ( V_19 ) ;
if ( V_102 )
goto V_112;
F_54 ( V_94 , V_19 ) ;
return 0 ;
V_112:
F_35 ( V_19 ) ;
V_111:
F_40 ( V_19 ) ;
return V_102 ;
}
static int F_55 ( struct V_93 * V_94 )
{
struct V_18 * V_19 = F_56 ( V_94 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
T_1 V_8 ;
F_57 ( V_19 ) ;
F_35 ( V_19 ) ;
F_40 ( V_19 ) ;
V_8 = F_5 ( V_7 ) ;
F_24 ( V_7 -> V_4 , V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_113 * V_97 )
{
struct V_18 * V_19 = F_59 ( V_97 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_114 * V_115 ;
unsigned int V_116 ;
V_115 = F_50 ( F_60 ( V_97 ) ) ;
if ( ! F_61 ( V_115 -> V_97 ) ) {
V_116 = F_1 ( V_7 , V_32 ) ;
V_116 &= ~ ( V_33 ) ;
F_3 ( V_7 , V_32 , ( V_116 |
V_117 ) ) ;
}
return 0 ;
}
static int F_62 ( struct V_113 * V_97 )
{
struct V_18 * V_19 = F_59 ( V_97 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_118 ;
V_118 = F_1 ( V_7 , V_32 ) ;
V_118 &= ~ ( V_117 ) ;
F_3 ( V_7 , V_32 , V_118 ) ;
F_10 ( V_19 ) ;
F_22 ( V_7 -> V_4 ,
V_7 -> V_54 ) ;
return 0 ;
}
