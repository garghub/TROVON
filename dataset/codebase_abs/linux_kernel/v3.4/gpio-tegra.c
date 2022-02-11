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
void F_8 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 1 ) ;
}
void F_10 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 0 ) ;
}
static void F_11 ( struct V_9 * V_10 , unsigned V_11 , int V_8 )
{
F_6 ( F_12 ( V_11 ) , V_11 , V_8 ) ;
}
static int F_13 ( struct V_9 * V_10 , unsigned V_11 )
{
return ( F_3 ( F_14 ( V_11 ) ) >> F_7 ( V_11 ) ) & 0x1 ;
}
static int F_15 ( struct V_9 * V_10 , unsigned V_11 )
{
F_6 ( F_16 ( V_11 ) , V_11 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned V_11 ,
int V_8 )
{
F_11 ( V_10 , V_11 , V_8 ) ;
F_6 ( F_16 ( V_11 ) , V_11 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , unsigned V_11 )
{
return F_19 ( V_12 , V_11 ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_1 ( 1 << F_7 ( V_7 ) , F_21 ( V_7 ) ) ;
}
static void F_22 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_6 ( F_23 ( V_7 ) , V_7 , 0 ) ;
}
static void F_24 ( struct V_13 * V_14 )
{
int V_7 = V_14 -> V_15 ;
F_6 ( F_23 ( V_7 ) , V_7 , 1 ) ;
}
static int F_25 ( struct V_13 * V_14 , unsigned int type )
{
int V_7 = V_14 -> V_15 ;
struct V_16 * V_4 = F_26 ( V_14 ) ;
int V_5 = F_27 ( V_7 ) ;
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
F_28 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
V_1 = F_3 ( F_29 ( V_7 ) ) ;
V_1 &= ~ ( V_32 << F_7 ( V_7 ) ) ;
V_1 |= V_17 << F_7 ( V_7 ) ;
F_1 ( V_1 , F_29 ( V_7 ) ) ;
F_30 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
if ( type & ( V_28 | V_26 ) )
F_31 ( V_14 -> V_33 , V_34 ) ;
else if ( type & ( V_22 | V_20 ) )
F_31 ( V_14 -> V_33 , V_35 ) ;
return 0 ;
}
static void F_32 ( unsigned int V_33 , struct V_36 * V_37 )
{
struct V_16 * V_4 ;
int V_5 ;
int V_38 ;
int V_39 = 0 ;
struct V_40 * V_10 = F_33 ( V_37 ) ;
F_34 ( V_10 , V_37 ) ;
V_4 = F_35 ( V_33 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
int V_7 = F_5 ( V_4 -> V_4 , V_5 , 0 ) ;
unsigned long V_41 = F_3 ( F_36 ( V_7 ) ) &
F_3 ( F_37 ( V_7 ) ) ;
T_1 V_42 = F_3 ( F_29 ( V_7 ) ) ;
F_38 (pin, &sta, 8 ) {
F_1 ( 1 << V_38 , F_21 ( V_7 ) ) ;
if ( V_42 & ( 0x100 << V_38 ) ) {
V_39 = 1 ;
F_39 ( V_10 , V_37 ) ;
}
F_40 ( F_41 ( V_7 + V_38 ) ) ;
}
}
if ( ! V_39 )
F_39 ( V_10 , V_37 ) ;
}
void F_42 ( void )
{
unsigned long V_18 ;
int V_43 ;
int V_44 ;
F_43 ( V_18 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_16 * V_4 = & V_46 [ V_43 ] ;
for ( V_44 = 0 ; V_44 < F_44 ( V_4 -> V_47 ) ; V_44 ++ ) {
unsigned int V_7 = ( V_43 << 5 ) | ( V_44 << 3 ) ;
F_1 ( V_4 -> V_48 [ V_44 ] , F_45 ( V_7 ) ) ;
F_1 ( V_4 -> V_49 [ V_44 ] , F_46 ( V_7 ) ) ;
F_1 ( V_4 -> V_47 [ V_44 ] , F_47 ( V_7 ) ) ;
F_1 ( V_4 -> V_50 [ V_44 ] , F_29 ( V_7 ) ) ;
F_1 ( V_4 -> V_51 [ V_44 ] , F_37 ( V_7 ) ) ;
}
}
F_48 ( V_18 ) ;
}
void F_49 ( void )
{
unsigned long V_18 ;
int V_43 ;
int V_44 ;
F_43 ( V_18 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_16 * V_4 = & V_46 [ V_43 ] ;
for ( V_44 = 0 ; V_44 < F_44 ( V_4 -> V_47 ) ; V_44 ++ ) {
unsigned int V_7 = ( V_43 << 5 ) | ( V_44 << 3 ) ;
V_4 -> V_48 [ V_44 ] = F_3 ( F_45 ( V_7 ) ) ;
V_4 -> V_49 [ V_44 ] = F_3 ( F_46 ( V_7 ) ) ;
V_4 -> V_47 [ V_44 ] = F_3 ( F_47 ( V_7 ) ) ;
V_4 -> V_51 [ V_44 ] = F_3 ( F_37 ( V_7 ) ) ;
V_4 -> V_50 [ V_44 ] = F_3 ( F_29 ( V_7 ) ) ;
}
}
F_48 ( V_18 ) ;
}
static int F_50 ( struct V_13 * V_14 , unsigned int V_52 )
{
struct V_16 * V_4 = F_26 ( V_14 ) ;
return F_51 ( V_4 -> V_33 , V_52 ) ;
}
static int T_2 F_52 ( struct V_53 * V_54 )
{
const struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_59 ;
struct V_60 * V_61 ;
struct V_16 * V_4 ;
int V_7 ;
int V_62 ;
int V_63 ;
V_56 = F_53 ( V_64 , & V_54 -> V_65 ) ;
if ( V_56 )
V_58 = (struct V_57 * ) V_56 -> V_66 ;
else
V_58 = & V_67 ;
V_68 = V_58 -> V_69 ;
V_70 = V_58 -> V_71 ;
for (; ; ) {
V_61 = F_54 ( V_54 , V_72 , V_45 ) ;
if ( ! V_61 )
break;
V_45 ++ ;
}
if ( ! V_45 ) {
F_55 ( & V_54 -> V_65 , L_1 ) ;
return - V_73 ;
}
V_74 . V_75 = V_45 * 32 ;
V_46 = F_56 ( & V_54 -> V_65 ,
V_45 * sizeof( * V_46 ) ,
V_76 ) ;
if ( ! V_46 ) {
F_55 ( & V_54 -> V_65 , L_2 ) ;
return - V_73 ;
}
V_59 = F_57 ( - 1 , 0 , V_74 . V_75 , 0 ) ;
if ( V_59 < 0 ) {
F_55 ( & V_54 -> V_65 , L_3 ) ;
return - V_73 ;
}
V_12 = F_58 ( V_54 -> V_65 . V_77 ,
V_74 . V_75 , V_59 , 0 ,
& V_78 , NULL ) ;
for ( V_62 = 0 ; V_62 < V_45 ; V_62 ++ ) {
V_61 = F_54 ( V_54 , V_72 , V_62 ) ;
if ( ! V_61 ) {
F_55 ( & V_54 -> V_65 , L_1 ) ;
return - V_73 ;
}
V_4 = & V_46 [ V_62 ] ;
V_4 -> V_4 = V_62 ;
V_4 -> V_33 = V_61 -> V_79 ;
}
V_61 = F_54 ( V_54 , V_80 , 0 ) ;
if ( ! V_61 ) {
F_55 ( & V_54 -> V_65 , L_4 ) ;
return - V_73 ;
}
V_3 = F_59 ( & V_54 -> V_65 , V_61 ) ;
if ( ! V_3 ) {
F_55 ( & V_54 -> V_65 , L_5 ) ;
return - V_73 ;
}
for ( V_62 = 0 ; V_62 < V_45 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
int V_7 = F_5 ( V_62 , V_63 , 0 ) ;
F_1 ( 0x00 , F_37 ( V_7 ) ) ;
}
}
#ifdef F_60
V_74 . V_77 = V_54 -> V_65 . V_77 ;
#endif
F_61 ( & V_74 ) ;
for ( V_7 = 0 ; V_7 < V_74 . V_75 ; V_7 ++ ) {
int V_33 = F_19 ( V_12 , V_7 ) ;
V_4 = & V_46 [ F_62 ( V_7 ) ] ;
F_63 ( V_33 , & V_81 ) ;
F_64 ( V_33 , V_4 ) ;
F_65 ( V_33 , & V_82 ,
V_83 ) ;
F_66 ( V_33 , V_84 ) ;
}
for ( V_62 = 0 ; V_62 < V_45 ; V_62 ++ ) {
V_4 = & V_46 [ V_62 ] ;
F_67 ( V_4 -> V_33 , F_32 ) ;
F_68 ( V_4 -> V_33 , V_4 ) ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ )
F_69 ( & V_4 -> V_31 [ V_63 ] ) ;
}
return 0 ;
}
static int T_3 F_70 ( void )
{
return F_71 ( & V_85 ) ;
}
void F_72 ( struct V_86 * V_87 , int V_88 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_88 ; V_62 ++ ) {
int V_7 = V_87 [ V_62 ] . V_7 ;
if ( V_87 [ V_62 ] . V_52 )
F_8 ( V_7 ) ;
else
F_10 ( V_7 ) ;
}
}
static int F_73 ( struct V_89 * V_90 , void * V_91 )
{
int V_62 ;
int V_63 ;
for ( V_62 = 0 ; V_62 < V_45 ; V_62 ++ ) {
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
int V_7 = F_5 ( V_62 , V_63 , 0 ) ;
F_74 ( V_90 ,
L_6 ,
V_62 , V_63 ,
F_3 ( F_45 ( V_7 ) ) ,
F_3 ( F_47 ( V_7 ) ) ,
F_3 ( F_46 ( V_7 ) ) ,
F_3 ( F_14 ( V_7 ) ) ,
F_3 ( F_36 ( V_7 ) ) ,
F_3 ( F_37 ( V_7 ) ) ,
F_3 ( F_29 ( V_7 ) ) ) ;
}
}
return 0 ;
}
static int F_75 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_76 ( V_93 , F_73 , & V_92 -> V_94 ) ;
}
static int T_3 F_77 ( void )
{
( void ) F_78 ( L_7 , V_95 ,
NULL , NULL , & V_96 ) ;
return 0 ;
}
