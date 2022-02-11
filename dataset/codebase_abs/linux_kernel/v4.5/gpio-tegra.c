static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
static int F_5 ( int V_4 , int V_5 , int V_6 )
{
return ( V_4 << 5 ) | ( ( V_5 & 0x3 ) << 3 ) | ( V_6 & 0x7 ) ;
}
static void F_6 ( T_1 V_2 , int V_7 , int V_8 )
{
T_1 V_1 ;
V_1 = 0x100 << F_7 ( V_7 ) ;
if ( V_8 )
V_1 |= 1 << F_7 ( V_7 ) ;
F_1 ( V_1 , V_2 ) ;
}
static void F_8 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 1 ) ;
}
static void F_10 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 0 ) ;
}
static int F_11 ( struct V_9 * V_10 , unsigned V_11 )
{
return F_12 ( V_11 ) ;
}
static void F_13 ( struct V_9 * V_10 , unsigned V_11 )
{
F_14 ( V_11 ) ;
F_10 ( V_11 ) ;
}
static void F_15 ( struct V_9 * V_10 , unsigned V_11 , int V_8 )
{
F_6 ( F_16 ( V_11 ) , V_11 , V_8 ) ;
}
static int F_17 ( struct V_9 * V_10 , unsigned V_11 )
{
if ( ( F_3 ( F_18 ( V_11 ) ) >> F_7 ( V_11 ) ) & 1 )
return ( F_3 ( F_19 ( V_11 ) ) >>
F_7 ( V_11 ) ) & 0x1 ;
return ( F_3 ( F_20 ( V_11 ) ) >> F_7 ( V_11 ) ) & 0x1 ;
}
static int F_21 ( struct V_9 * V_10 , unsigned V_11 )
{
F_6 ( F_22 ( V_11 ) , V_11 , 0 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 , unsigned V_11 ,
int V_8 )
{
F_15 ( V_10 , V_11 , V_8 ) ;
F_6 ( F_22 ( V_11 ) , V_11 , 1 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 , unsigned V_11 )
{
return F_25 ( V_12 , V_11 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_1 ( 1 << F_7 ( V_7 ) , F_27 ( V_7 ) ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_6 ( F_29 ( V_7 ) , V_7 , 0 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_6 ( F_29 ( V_7 ) , V_7 , 1 ) ;
}
static int F_31 ( struct V_13 * V_14 , unsigned int type )
{
int V_7 = V_14 -> V_15 ;
struct V_16 * V_4 = F_32 ( V_14 ) ;
int V_5 = F_33 ( V_7 ) ;
int V_17 ;
int V_1 ;
unsigned long V_18 ;
int V_19 ;
switch ( type & V_20 ) {
case V_21 :
V_17 = V_22 ;
break;
case V_23 :
V_17 = V_24 ;
break;
case V_25 :
V_17 = V_26 ;
break;
case V_27 :
V_17 = V_28 ;
break;
case V_29 :
V_17 = V_30 ;
break;
default:
return - V_31 ;
}
V_19 = F_34 ( & V_32 , V_7 ) ;
if ( V_19 ) {
F_35 ( V_33 , L_1 , V_7 ) ;
return V_19 ;
}
F_36 ( & V_4 -> V_34 [ V_5 ] , V_18 ) ;
V_1 = F_3 ( F_37 ( V_7 ) ) ;
V_1 &= ~ ( V_35 << F_7 ( V_7 ) ) ;
V_1 |= V_17 << F_7 ( V_7 ) ;
F_1 ( V_1 , F_37 ( V_7 ) ) ;
F_38 ( & V_4 -> V_34 [ V_5 ] , V_18 ) ;
F_6 ( F_22 ( V_7 ) , V_7 , 0 ) ;
F_8 ( V_7 ) ;
if ( type & ( V_29 | V_27 ) )
F_39 ( V_14 , V_36 ) ;
else if ( type & ( V_23 | V_21 ) )
F_39 ( V_14 , V_37 ) ;
return 0 ;
}
static void F_40 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_41 ( & V_32 , V_7 ) ;
}
static void F_42 ( struct V_38 * V_39 )
{
int V_5 ;
int V_40 ;
int V_41 = 0 ;
struct V_42 * V_10 = F_43 ( V_39 ) ;
struct V_16 * V_4 = F_44 ( V_39 ) ;
F_45 ( V_10 , V_39 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
int V_7 = F_5 ( V_4 -> V_4 , V_5 , 0 ) ;
unsigned long V_43 = F_3 ( F_46 ( V_7 ) ) &
F_3 ( F_47 ( V_7 ) ) ;
T_1 V_44 = F_3 ( F_37 ( V_7 ) ) ;
F_48 (pin, &sta, 8 ) {
F_1 ( 1 << V_40 , F_27 ( V_7 ) ) ;
if ( V_44 & ( 0x100 << V_40 ) ) {
V_41 = 1 ;
F_49 ( V_10 , V_39 ) ;
}
F_50 ( F_51 ( V_7 + V_40 ) ) ;
}
}
if ( ! V_41 )
F_49 ( V_10 , V_39 ) ;
}
static int F_52 ( struct V_45 * V_33 )
{
unsigned long V_18 ;
int V_46 ;
int V_47 ;
F_53 ( V_18 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
struct V_16 * V_4 = & V_49 [ V_46 ] ;
for ( V_47 = 0 ; V_47 < F_54 ( V_4 -> V_50 ) ; V_47 ++ ) {
unsigned int V_7 = ( V_46 << 5 ) | ( V_47 << 3 ) ;
F_1 ( V_4 -> V_51 [ V_47 ] , F_55 ( V_7 ) ) ;
F_1 ( V_4 -> V_52 [ V_47 ] , F_19 ( V_7 ) ) ;
F_1 ( V_4 -> V_50 [ V_47 ] , F_18 ( V_7 ) ) ;
F_1 ( V_4 -> V_53 [ V_47 ] , F_37 ( V_7 ) ) ;
F_1 ( V_4 -> V_54 [ V_47 ] , F_47 ( V_7 ) ) ;
}
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_57 ( struct V_45 * V_33 )
{
unsigned long V_18 ;
int V_46 ;
int V_47 ;
F_53 ( V_18 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
struct V_16 * V_4 = & V_49 [ V_46 ] ;
for ( V_47 = 0 ; V_47 < F_54 ( V_4 -> V_50 ) ; V_47 ++ ) {
unsigned int V_7 = ( V_46 << 5 ) | ( V_47 << 3 ) ;
V_4 -> V_51 [ V_47 ] = F_3 ( F_55 ( V_7 ) ) ;
V_4 -> V_52 [ V_47 ] = F_3 ( F_19 ( V_7 ) ) ;
V_4 -> V_50 [ V_47 ] = F_3 ( F_18 ( V_7 ) ) ;
V_4 -> V_54 [ V_47 ] = F_3 ( F_47 ( V_7 ) ) ;
V_4 -> V_53 [ V_47 ] = F_3 ( F_37 ( V_7 ) ) ;
F_1 ( V_4 -> V_55 [ V_47 ] ,
F_47 ( V_7 ) ) ;
}
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_58 ( struct V_13 * V_14 , unsigned int V_56 )
{
struct V_16 * V_4 = F_32 ( V_14 ) ;
int V_7 = V_14 -> V_15 ;
T_1 V_5 , V_6 , V_57 ;
V_5 = F_33 ( V_7 ) ;
V_6 = F_7 ( V_7 ) ;
V_57 = F_59 ( V_6 ) ;
if ( V_56 )
V_4 -> V_55 [ V_5 ] |= V_57 ;
else
V_4 -> V_55 [ V_5 ] &= ~ V_57 ;
return F_60 ( V_4 -> V_58 , V_56 ) ;
}
static int F_61 ( struct V_59 * V_60 , void * V_61 )
{
int V_62 ;
int V_63 ;
for ( V_62 = 0 ; V_62 < V_48 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
int V_7 = F_5 ( V_62 , V_63 , 0 ) ;
F_62 ( V_60 ,
L_2 ,
V_62 , V_63 ,
F_3 ( F_55 ( V_7 ) ) ,
F_3 ( F_18 ( V_7 ) ) ,
F_3 ( F_19 ( V_7 ) ) ,
F_3 ( F_20 ( V_7 ) ) ,
F_3 ( F_46 ( V_7 ) ) ,
F_3 ( F_47 ( V_7 ) ) ,
F_3 ( F_37 ( V_7 ) ) ) ;
}
}
return 0 ;
}
static int F_63 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_64 ( V_65 , F_61 , & V_64 -> V_66 ) ;
}
static void F_65 ( void )
{
( void ) F_66 ( L_3 , V_67 ,
NULL , NULL , & V_68 ) ;
}
static inline void F_65 ( void )
{
}
static int F_67 ( struct V_69 * V_70 )
{
const struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_16 * V_4 ;
int V_19 ;
int V_7 ;
int V_62 ;
int V_63 ;
V_33 = & V_70 -> V_33 ;
V_72 = F_68 ( V_77 , & V_70 -> V_33 ) ;
if ( ! V_72 ) {
F_35 ( & V_70 -> V_33 , L_4 ) ;
return - V_78 ;
}
V_74 = (struct V_73 * ) V_72 -> V_79 ;
V_80 = V_74 -> V_81 ;
V_82 = V_74 -> V_83 ;
for (; ; ) {
V_76 = F_69 ( V_70 , V_84 , V_48 ) ;
if ( ! V_76 )
break;
V_48 ++ ;
}
if ( ! V_48 ) {
F_35 ( & V_70 -> V_33 , L_5 ) ;
return - V_78 ;
}
V_32 . V_85 = V_48 * 32 ;
V_49 = F_70 ( & V_70 -> V_33 ,
V_48 * sizeof( * V_49 ) ,
V_86 ) ;
if ( ! V_49 )
return - V_78 ;
V_12 = F_71 ( V_70 -> V_33 . V_87 ,
V_32 . V_85 ,
& V_88 , NULL ) ;
if ( ! V_12 )
return - V_78 ;
for ( V_62 = 0 ; V_62 < V_48 ; V_62 ++ ) {
V_76 = F_69 ( V_70 , V_84 , V_62 ) ;
if ( ! V_76 ) {
F_35 ( & V_70 -> V_33 , L_5 ) ;
return - V_78 ;
}
V_4 = & V_49 [ V_62 ] ;
V_4 -> V_4 = V_62 ;
V_4 -> V_58 = V_76 -> V_89 ;
}
V_76 = F_69 ( V_70 , V_90 , 0 ) ;
V_3 = F_72 ( & V_70 -> V_33 , V_76 ) ;
if ( F_73 ( V_3 ) )
return F_74 ( V_3 ) ;
for ( V_62 = 0 ; V_62 < V_48 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
int V_7 = F_5 ( V_62 , V_63 , 0 ) ;
F_1 ( 0x00 , F_47 ( V_7 ) ) ;
}
}
V_32 . V_87 = V_70 -> V_33 . V_87 ;
V_19 = F_75 ( & V_32 , NULL ) ;
if ( V_19 < 0 ) {
F_76 ( V_12 ) ;
return V_19 ;
}
for ( V_7 = 0 ; V_7 < V_32 . V_85 ; V_7 ++ ) {
int V_58 = F_77 ( V_12 , V_7 ) ;
V_4 = & V_49 [ F_78 ( V_7 ) ] ;
F_79 ( V_58 , & V_91 ) ;
F_80 ( V_58 , V_4 ) ;
F_81 ( V_58 , & V_92 ,
V_93 ) ;
}
for ( V_62 = 0 ; V_62 < V_48 ; V_62 ++ ) {
V_4 = & V_49 [ V_62 ] ;
F_82 ( V_4 -> V_58 ,
F_42 , V_4 ) ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ )
F_83 ( & V_4 -> V_34 [ V_63 ] ) ;
}
F_65 () ;
return 0 ;
}
static int T_2 F_84 ( void )
{
return F_85 ( & V_94 ) ;
}
