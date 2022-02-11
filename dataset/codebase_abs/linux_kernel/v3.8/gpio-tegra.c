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
switch ( type & V_19 ) {
case V_20 :
V_17 = V_21 ;
break;
case V_22 :
V_17 = V_23 ;
break;
case V_24 :
V_17 = V_25 ;
break;
case V_26 :
V_17 = V_27 ;
break;
case V_28 :
V_17 = V_29 ;
break;
default:
return - V_30 ;
}
F_34 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
V_1 = F_3 ( F_35 ( V_7 ) ) ;
V_1 &= ~ ( V_32 << F_7 ( V_7 ) ) ;
V_1 |= V_17 << F_7 ( V_7 ) ;
F_1 ( V_1 , F_35 ( V_7 ) ) ;
F_36 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
F_6 ( F_22 ( V_7 ) , V_7 , 0 ) ;
F_8 ( V_7 ) ;
if ( type & ( V_28 | V_26 ) )
F_37 ( V_14 -> V_33 , V_34 ) ;
else if ( type & ( V_22 | V_20 ) )
F_37 ( V_14 -> V_33 , V_35 ) ;
return 0 ;
}
static void F_38 ( unsigned int V_33 , struct V_36 * V_37 )
{
struct V_16 * V_4 ;
int V_5 ;
int V_38 ;
int V_39 = 0 ;
struct V_40 * V_10 = F_39 ( V_37 ) ;
F_40 ( V_10 , V_37 ) ;
V_4 = F_41 ( V_33 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
int V_7 = F_5 ( V_4 -> V_4 , V_5 , 0 ) ;
unsigned long V_41 = F_3 ( F_42 ( V_7 ) ) &
F_3 ( F_43 ( V_7 ) ) ;
T_1 V_42 = F_3 ( F_35 ( V_7 ) ) ;
F_44 (pin, &sta, 8 ) {
F_1 ( 1 << V_38 , F_27 ( V_7 ) ) ;
if ( V_42 & ( 0x100 << V_38 ) ) {
V_39 = 1 ;
F_45 ( V_10 , V_37 ) ;
}
F_46 ( F_47 ( V_7 + V_38 ) ) ;
}
}
if ( ! V_39 )
F_45 ( V_10 , V_37 ) ;
}
static int F_48 ( struct V_43 * V_44 )
{
unsigned long V_18 ;
int V_45 ;
int V_46 ;
F_49 ( V_18 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
struct V_16 * V_4 = & V_48 [ V_45 ] ;
for ( V_46 = 0 ; V_46 < F_50 ( V_4 -> V_49 ) ; V_46 ++ ) {
unsigned int V_7 = ( V_45 << 5 ) | ( V_46 << 3 ) ;
F_1 ( V_4 -> V_50 [ V_46 ] , F_51 ( V_7 ) ) ;
F_1 ( V_4 -> V_51 [ V_46 ] , F_19 ( V_7 ) ) ;
F_1 ( V_4 -> V_49 [ V_46 ] , F_18 ( V_7 ) ) ;
F_1 ( V_4 -> V_52 [ V_46 ] , F_35 ( V_7 ) ) ;
F_1 ( V_4 -> V_53 [ V_46 ] , F_43 ( V_7 ) ) ;
}
}
F_52 ( V_18 ) ;
return 0 ;
}
static int F_53 ( struct V_43 * V_44 )
{
unsigned long V_18 ;
int V_45 ;
int V_46 ;
F_49 ( V_18 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
struct V_16 * V_4 = & V_48 [ V_45 ] ;
for ( V_46 = 0 ; V_46 < F_50 ( V_4 -> V_49 ) ; V_46 ++ ) {
unsigned int V_7 = ( V_45 << 5 ) | ( V_46 << 3 ) ;
V_4 -> V_50 [ V_46 ] = F_3 ( F_51 ( V_7 ) ) ;
V_4 -> V_51 [ V_46 ] = F_3 ( F_19 ( V_7 ) ) ;
V_4 -> V_49 [ V_46 ] = F_3 ( F_18 ( V_7 ) ) ;
V_4 -> V_53 [ V_46 ] = F_3 ( F_43 ( V_7 ) ) ;
V_4 -> V_52 [ V_46 ] = F_3 ( F_35 ( V_7 ) ) ;
}
}
F_52 ( V_18 ) ;
return 0 ;
}
static int F_54 ( struct V_13 * V_14 , unsigned int V_54 )
{
struct V_16 * V_4 = F_32 ( V_14 ) ;
return F_55 ( V_4 -> V_33 , V_54 ) ;
}
static int F_56 ( struct V_55 * V_56 )
{
const struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_16 * V_4 ;
int V_7 ;
int V_63 ;
int V_64 ;
V_58 = F_57 ( V_65 , & V_56 -> V_44 ) ;
if ( V_58 )
V_60 = (struct V_59 * ) V_58 -> V_66 ;
else
V_60 = & V_67 ;
V_68 = V_60 -> V_69 ;
V_70 = V_60 -> V_71 ;
for (; ; ) {
V_62 = F_58 ( V_56 , V_72 , V_47 ) ;
if ( ! V_62 )
break;
V_47 ++ ;
}
if ( ! V_47 ) {
F_59 ( & V_56 -> V_44 , L_1 ) ;
return - V_73 ;
}
V_74 . V_75 = V_47 * 32 ;
V_48 = F_60 ( & V_56 -> V_44 ,
V_47 * sizeof( * V_48 ) ,
V_76 ) ;
if ( ! V_48 ) {
F_59 ( & V_56 -> V_44 , L_2 ) ;
return - V_73 ;
}
V_12 = F_61 ( V_56 -> V_44 . V_77 ,
V_74 . V_75 ,
& V_78 , NULL ) ;
if ( ! V_12 )
return - V_73 ;
for ( V_63 = 0 ; V_63 < V_47 ; V_63 ++ ) {
V_62 = F_58 ( V_56 , V_72 , V_63 ) ;
if ( ! V_62 ) {
F_59 ( & V_56 -> V_44 , L_1 ) ;
return - V_73 ;
}
V_4 = & V_48 [ V_63 ] ;
V_4 -> V_4 = V_63 ;
V_4 -> V_33 = V_62 -> V_79 ;
}
V_62 = F_58 ( V_56 , V_80 , 0 ) ;
if ( ! V_62 ) {
F_59 ( & V_56 -> V_44 , L_3 ) ;
return - V_73 ;
}
V_3 = F_62 ( & V_56 -> V_44 , V_62 ) ;
if ( ! V_3 ) {
F_59 ( & V_56 -> V_44 , L_4 ) ;
return - V_73 ;
}
for ( V_63 = 0 ; V_63 < V_47 ; V_63 ++ ) {
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
int V_7 = F_5 ( V_63 , V_64 , 0 ) ;
F_1 ( 0x00 , F_43 ( V_7 ) ) ;
}
}
#ifdef F_63
V_74 . V_77 = V_56 -> V_44 . V_77 ;
#endif
F_64 ( & V_74 ) ;
for ( V_7 = 0 ; V_7 < V_74 . V_75 ; V_7 ++ ) {
int V_33 = F_65 ( V_12 , V_7 ) ;
V_4 = & V_48 [ F_66 ( V_7 ) ] ;
F_67 ( V_33 , & V_81 ) ;
F_68 ( V_33 , V_4 ) ;
F_69 ( V_33 , & V_82 ,
V_83 ) ;
F_70 ( V_33 , V_84 ) ;
}
for ( V_63 = 0 ; V_63 < V_47 ; V_63 ++ ) {
V_4 = & V_48 [ V_63 ] ;
F_71 ( V_4 -> V_33 , F_38 ) ;
F_72 ( V_4 -> V_33 , V_4 ) ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ )
F_73 ( & V_4 -> V_31 [ V_64 ] ) ;
}
return 0 ;
}
static int T_2 F_74 ( void )
{
return F_75 ( & V_85 ) ;
}
static int F_76 ( struct V_86 * V_87 , void * V_88 )
{
int V_63 ;
int V_64 ;
for ( V_63 = 0 ; V_63 < V_47 ; V_63 ++ ) {
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
int V_7 = F_5 ( V_63 , V_64 , 0 ) ;
F_77 ( V_87 ,
L_5 ,
V_63 , V_64 ,
F_3 ( F_51 ( V_7 ) ) ,
F_3 ( F_18 ( V_7 ) ) ,
F_3 ( F_19 ( V_7 ) ) ,
F_3 ( F_20 ( V_7 ) ) ,
F_3 ( F_42 ( V_7 ) ) ,
F_3 ( F_43 ( V_7 ) ) ,
F_3 ( F_35 ( V_7 ) ) ) ;
}
}
return 0 ;
}
static int F_78 ( struct V_89 * V_89 , struct V_90 * V_90 )
{
return F_79 ( V_90 , F_76 , & V_89 -> V_91 ) ;
}
static int T_2 F_80 ( void )
{
( void ) F_81 ( L_6 , V_92 ,
NULL , NULL , & V_93 ) ;
return 0 ;
}
