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
F_39 ( V_14 -> V_36 , V_37 ) ;
else if ( type & ( V_23 | V_21 ) )
F_39 ( V_14 -> V_36 , V_38 ) ;
return 0 ;
}
static void F_40 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_41 ( & V_32 , V_7 ) ;
}
static void F_42 ( unsigned int V_36 , struct V_39 * V_40 )
{
struct V_16 * V_4 ;
int V_5 ;
int V_41 ;
int V_42 = 0 ;
struct V_43 * V_10 = F_43 ( V_40 ) ;
F_44 ( V_10 , V_40 ) ;
V_4 = F_45 ( V_36 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
int V_7 = F_5 ( V_4 -> V_4 , V_5 , 0 ) ;
unsigned long V_44 = F_3 ( F_46 ( V_7 ) ) &
F_3 ( F_47 ( V_7 ) ) ;
T_1 V_45 = F_3 ( F_37 ( V_7 ) ) ;
F_48 (pin, &sta, 8 ) {
F_1 ( 1 << V_41 , F_27 ( V_7 ) ) ;
if ( V_45 & ( 0x100 << V_41 ) ) {
V_42 = 1 ;
F_49 ( V_10 , V_40 ) ;
}
F_50 ( F_51 ( V_7 + V_41 ) ) ;
}
}
if ( ! V_42 )
F_49 ( V_10 , V_40 ) ;
}
static int F_52 ( struct V_46 * V_33 )
{
unsigned long V_18 ;
int V_47 ;
int V_48 ;
F_53 ( V_18 ) ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
struct V_16 * V_4 = & V_50 [ V_47 ] ;
for ( V_48 = 0 ; V_48 < F_54 ( V_4 -> V_51 ) ; V_48 ++ ) {
unsigned int V_7 = ( V_47 << 5 ) | ( V_48 << 3 ) ;
F_1 ( V_4 -> V_52 [ V_48 ] , F_55 ( V_7 ) ) ;
F_1 ( V_4 -> V_53 [ V_48 ] , F_19 ( V_7 ) ) ;
F_1 ( V_4 -> V_51 [ V_48 ] , F_18 ( V_7 ) ) ;
F_1 ( V_4 -> V_54 [ V_48 ] , F_37 ( V_7 ) ) ;
F_1 ( V_4 -> V_55 [ V_48 ] , F_47 ( V_7 ) ) ;
}
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_57 ( struct V_46 * V_33 )
{
unsigned long V_18 ;
int V_47 ;
int V_48 ;
F_53 ( V_18 ) ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
struct V_16 * V_4 = & V_50 [ V_47 ] ;
for ( V_48 = 0 ; V_48 < F_54 ( V_4 -> V_51 ) ; V_48 ++ ) {
unsigned int V_7 = ( V_47 << 5 ) | ( V_48 << 3 ) ;
V_4 -> V_52 [ V_48 ] = F_3 ( F_55 ( V_7 ) ) ;
V_4 -> V_53 [ V_48 ] = F_3 ( F_19 ( V_7 ) ) ;
V_4 -> V_51 [ V_48 ] = F_3 ( F_18 ( V_7 ) ) ;
V_4 -> V_55 [ V_48 ] = F_3 ( F_47 ( V_7 ) ) ;
V_4 -> V_54 [ V_48 ] = F_3 ( F_37 ( V_7 ) ) ;
F_1 ( V_4 -> V_56 [ V_48 ] ,
F_47 ( V_7 ) ) ;
}
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_58 ( struct V_13 * V_14 , unsigned int V_57 )
{
struct V_16 * V_4 = F_32 ( V_14 ) ;
int V_7 = V_14 -> V_15 ;
T_1 V_5 , V_6 , V_58 ;
V_5 = F_33 ( V_7 ) ;
V_6 = F_7 ( V_7 ) ;
V_58 = F_59 ( V_6 ) ;
if ( V_57 )
V_4 -> V_56 [ V_5 ] |= V_58 ;
else
V_4 -> V_56 [ V_5 ] &= ~ V_58 ;
return F_60 ( V_4 -> V_36 , V_57 ) ;
}
static int F_61 ( struct V_59 * V_60 )
{
const struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_16 * V_4 ;
int V_19 ;
int V_7 ;
int V_67 ;
int V_68 ;
V_33 = & V_60 -> V_33 ;
V_62 = F_62 ( V_69 , & V_60 -> V_33 ) ;
if ( ! V_62 ) {
F_35 ( & V_60 -> V_33 , L_2 ) ;
return - V_70 ;
}
V_64 = (struct V_63 * ) V_62 -> V_71 ;
V_72 = V_64 -> V_73 ;
V_74 = V_64 -> V_75 ;
for (; ; ) {
V_66 = F_63 ( V_60 , V_76 , V_49 ) ;
if ( ! V_66 )
break;
V_49 ++ ;
}
if ( ! V_49 ) {
F_35 ( & V_60 -> V_33 , L_3 ) ;
return - V_70 ;
}
V_32 . V_77 = V_49 * 32 ;
V_50 = F_64 ( & V_60 -> V_33 ,
V_49 * sizeof( * V_50 ) ,
V_78 ) ;
if ( ! V_50 ) {
F_35 ( & V_60 -> V_33 , L_4 ) ;
return - V_70 ;
}
V_12 = F_65 ( V_60 -> V_33 . V_79 ,
V_32 . V_77 ,
& V_80 , NULL ) ;
if ( ! V_12 )
return - V_70 ;
for ( V_67 = 0 ; V_67 < V_49 ; V_67 ++ ) {
V_66 = F_63 ( V_60 , V_76 , V_67 ) ;
if ( ! V_66 ) {
F_35 ( & V_60 -> V_33 , L_3 ) ;
return - V_70 ;
}
V_4 = & V_50 [ V_67 ] ;
V_4 -> V_4 = V_67 ;
V_4 -> V_36 = V_66 -> V_81 ;
}
V_66 = F_63 ( V_60 , V_82 , 0 ) ;
V_3 = F_66 ( & V_60 -> V_33 , V_66 ) ;
if ( F_67 ( V_3 ) )
return F_68 ( V_3 ) ;
for ( V_67 = 0 ; V_67 < V_49 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
int V_7 = F_5 ( V_67 , V_68 , 0 ) ;
F_1 ( 0x00 , F_47 ( V_7 ) ) ;
}
}
V_32 . V_79 = V_60 -> V_33 . V_79 ;
V_19 = F_69 ( & V_32 ) ;
if ( V_19 < 0 ) {
F_70 ( V_12 ) ;
return V_19 ;
}
for ( V_7 = 0 ; V_7 < V_32 . V_77 ; V_7 ++ ) {
int V_36 = F_71 ( V_12 , V_7 ) ;
V_4 = & V_50 [ F_72 ( V_7 ) ] ;
F_73 ( V_36 , & V_83 ) ;
F_74 ( V_36 , V_4 ) ;
F_75 ( V_36 , & V_84 ,
V_85 ) ;
F_76 ( V_36 , V_86 ) ;
}
for ( V_67 = 0 ; V_67 < V_49 ; V_67 ++ ) {
V_4 = & V_50 [ V_67 ] ;
F_77 ( V_4 -> V_36 , F_42 ) ;
F_78 ( V_4 -> V_36 , V_4 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
F_79 ( & V_4 -> V_34 [ V_68 ] ) ;
}
return 0 ;
}
static int T_2 F_80 ( void )
{
return F_81 ( & V_87 ) ;
}
static int F_82 ( struct V_88 * V_89 , void * V_90 )
{
int V_67 ;
int V_68 ;
for ( V_67 = 0 ; V_67 < V_49 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
int V_7 = F_5 ( V_67 , V_68 , 0 ) ;
F_83 ( V_89 ,
L_5 ,
V_67 , V_68 ,
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
static int F_84 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_85 ( V_92 , F_82 , & V_91 -> V_93 ) ;
}
static int T_2 F_86 ( void )
{
( void ) F_87 ( L_6 , V_94 ,
NULL , NULL , & V_95 ) ;
return 0 ;
}
