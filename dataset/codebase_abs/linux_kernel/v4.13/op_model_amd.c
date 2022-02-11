static unsigned int F_1 ( void )
{
static unsigned int V_1 = 0xF00D ;
unsigned int V_2 ;
V_2 = ( ( V_1 >> 0 ) ^
( V_1 >> 2 ) ^
( V_1 >> 3 ) ^
( V_1 >> 5 ) ) & 0x0001 ;
V_1 = ( V_1 >> 1 ) | ( V_2 << 15 ) ;
return V_1 ;
}
static inline T_1 F_2 ( T_1 V_3 )
{
unsigned int V_4 = F_1 () ;
if ( ! ( V_5 & V_6 ) )
V_3 += ( V_7 ) ( V_4 >> 4 ) ;
else
V_3 |= ( T_1 ) ( V_4 & V_8 ) << 32 ;
return V_3 ;
}
static inline void
F_3 ( struct V_9 * const V_10 ,
struct V_11 const * const V_12 )
{
T_1 V_3 , V_13 ;
struct V_14 V_15 ;
if ( ! V_5 )
return;
if ( V_16 . V_17 ) {
F_4 ( V_18 , V_13 ) ;
if ( V_13 & V_19 ) {
F_4 ( V_20 , V_3 ) ;
F_5 ( & V_15 , V_10 , V_3 ,
V_21 , V_22 ) ;
F_6 ( & V_15 , V_3 ) ;
F_6 ( & V_15 , V_13 ) ;
F_4 ( V_23 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
F_7 ( & V_15 ) ;
V_13 &= ~ ( V_19 | V_24 ) ;
V_13 |= V_25 ;
F_8 ( V_18 , V_13 ) ;
}
}
if ( V_16 . V_26 ) {
F_4 ( V_27 , V_13 ) ;
if ( V_13 & V_28 ) {
F_4 ( V_29 , V_3 ) ;
F_5 ( & V_15 , V_10 , V_3 , V_30 ,
V_31 . V_32 ) ;
F_6 ( & V_15 , V_3 ) ;
F_4 ( V_33 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
F_4 ( V_34 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
F_4 ( V_35 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
F_4 ( V_36 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
F_4 ( V_37 , V_3 ) ;
F_6 ( & V_15 , V_3 ) ;
if ( V_31 . V_38 ) {
F_4 ( V_39 , V_3 ) ;
F_9 ( & V_15 , ( unsigned long ) V_3 ) ;
}
F_7 ( & V_15 ) ;
V_13 = F_2 ( V_31 . V_40 ) ;
F_8 ( V_27 , V_13 ) ;
}
}
}
static inline void F_10 ( void )
{
T_1 V_3 ;
if ( ! V_5 )
return;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( V_16 . V_17 ) {
V_3 = V_16 . V_41 >> 4 ;
V_3 = F_11 ( V_3 , V_42 ) ;
V_16 . V_41 = V_3 << 4 ;
V_3 |= V_16 . V_43 ? V_44 : 0 ;
V_3 |= V_25 ;
F_8 ( V_18 , V_3 ) ;
}
if ( V_16 . V_26 ) {
V_3 = V_16 . V_45 >> 4 ;
if ( ! ( V_5 & V_6 ) ) {
V_3 = F_12 ( V_3 , 0x0081ULL , 0xFF80ULL ) ;
V_16 . V_45 = V_3 << 4 ;
} else {
V_3 += V_46 ;
if ( V_5 & V_47 )
V_3 = F_11 ( V_3 , V_48 ) ;
else
V_3 = F_11 ( V_3 , V_49 ) ;
V_16 . V_45 =
( V_3 - V_46 ) << 4 ;
}
V_3 = ( ( V_3 & ~ V_49 ) << 4 ) | ( V_3 & V_49 ) ;
V_3 |= V_16 . V_50 ? V_51 : 0 ;
V_3 |= V_52 ;
V_31 . V_40 = V_3 ;
V_31 . V_32 = V_53 ;
if ( V_16 . V_38 ) {
V_31 . V_38 = 1 ;
V_31 . V_32 ++ ;
}
V_3 = F_2 ( V_31 . V_40 ) ;
F_8 ( V_27 , V_3 ) ;
}
}
static void F_13 ( void )
{
if ( ! V_5 )
return;
if ( V_16 . V_17 )
F_8 ( V_18 , 0 ) ;
if ( V_16 . V_26 )
F_8 ( V_27 , 0 ) ;
}
static void F_14 ( struct V_54 const * V_55 ,
struct V_11 const * const V_12 )
{
T_1 V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
int V_58 = F_15 ( V_56 ) ;
if ( ! V_59 [ V_58 ] )
continue;
F_4 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
V_3 &= V_55 -> V_62 ;
V_3 |= F_16 ( V_55 , & V_63 [ V_58 ] ) ;
F_8 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
}
}
static void F_17 ( struct V_11 const * const V_12 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
if ( ! V_12 -> V_64 [ V_56 ] . V_61 )
continue;
F_18 ( V_65 + V_56 ) ;
F_19 ( V_66 + V_56 ) ;
}
}
static int F_20 ( struct V_11 * const V_12 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
if ( ! F_21 ( V_65 + V_56 ) )
goto V_67;
if ( ! F_22 ( V_66 + V_56 ) ) {
F_18 ( V_65 + V_56 ) ;
goto V_67;
}
if ( V_57 == V_68 ) {
V_12 -> V_64 [ V_56 ] . V_61 = V_69 + ( V_56 << 1 ) ;
V_12 -> V_60 [ V_56 ] . V_61 = V_70 + ( V_56 << 1 ) ;
} else {
V_12 -> V_60 [ V_56 ] . V_61 = V_66 + V_56 ;
V_12 -> V_64 [ V_56 ] . V_61 = V_65 + V_56 ;
}
continue;
V_67:
if ( ! V_63 [ V_56 ] . V_71 )
continue;
F_23 ( V_56 ) ;
F_17 ( V_12 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_24 ( struct V_54 const * V_55 ,
struct V_11 const * const V_12 )
{
T_1 V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_73 ; ++ V_56 ) {
if ( V_63 [ V_56 ] . V_71
&& V_12 -> V_64 [ F_25 ( V_56 ) ] . V_61 )
V_59 [ V_56 ] = V_63 [ V_56 ] . V_74 ;
else
V_59 [ V_56 ] = 0 ;
}
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
if ( ! V_12 -> V_60 [ V_56 ] . V_61 )
continue;
F_4 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
if ( V_3 & V_75 )
F_26 ( V_56 ) ;
V_3 &= V_55 -> V_62 ;
F_8 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
F_8 ( V_12 -> V_64 [ V_56 ] . V_61 , - 1LL ) ;
}
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
int V_58 = F_15 ( V_56 ) ;
if ( ! V_59 [ V_58 ] )
continue;
F_8 ( V_12 -> V_64 [ V_56 ] . V_61 , - ( T_1 ) V_59 [ V_58 ] ) ;
F_4 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
V_3 &= V_55 -> V_62 ;
V_3 |= F_16 ( V_55 , & V_63 [ V_58 ] ) ;
F_8 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
}
}
static int F_27 ( struct V_9 * const V_10 ,
struct V_11 const * const V_12 )
{
T_1 V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
int V_58 = F_15 ( V_56 ) ;
if ( ! V_59 [ V_58 ] )
continue;
F_4 ( V_12 -> V_64 [ V_56 ] . V_61 , V_3 ) ;
if ( V_3 & V_76 )
continue;
F_28 ( V_10 , V_58 ) ;
F_8 ( V_12 -> V_64 [ V_56 ] . V_61 , - ( T_1 ) V_59 [ V_58 ] ) ;
}
F_3 ( V_10 , V_12 ) ;
return 1 ;
}
static void F_29 ( struct V_11 const * const V_12 )
{
T_1 V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
if ( ! V_59 [ F_15 ( V_56 ) ] )
continue;
F_4 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
V_3 |= V_75 ;
F_8 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
}
F_10 () ;
}
static void F_30 ( struct V_11 const * const V_12 )
{
T_1 V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; ++ V_56 ) {
if ( ! V_59 [ F_15 ( V_56 ) ] )
continue;
F_4 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
V_3 &= ~ V_75 ;
F_8 ( V_12 -> V_60 [ V_56 ] . V_61 , V_3 ) ;
}
F_13 () ;
}
static void F_31 ( void )
{
V_5 = F_32 () ;
if ( ! V_5 )
return;
F_33 ( V_77 L_1 , V_5 ) ;
}
static int F_34 ( struct V_78 * V_79 )
{
struct V_78 * V_80 ;
int V_81 = 0 ;
if ( V_82 )
V_81 = V_82 ( V_79 ) ;
if ( V_81 )
return V_81 ;
if ( ! V_5 )
return V_81 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_41 = 250000 ;
V_16 . V_45 = 250000 ;
if ( V_5 & V_83 ) {
V_80 = F_35 ( V_79 , L_2 ) ;
F_36 ( V_80 , L_3 ,
& V_16 . V_17 ) ;
F_36 ( V_80 , L_4 ,
& V_16 . V_41 ) ;
F_36 ( V_80 , L_5 ,
& V_16 . V_43 ) ;
}
if ( V_5 & V_84 ) {
V_80 = F_35 ( V_79 , L_6 ) ;
F_36 ( V_80 , L_3 ,
& V_16 . V_26 ) ;
F_36 ( V_80 , L_4 ,
& V_16 . V_45 ) ;
if ( V_5 & V_85 )
F_36 ( V_80 , L_7 ,
& V_16 . V_50 ) ;
if ( V_5 & V_86 )
F_36 ( V_80 , L_8 ,
& V_16 . V_38 ) ;
}
return 0 ;
}
static int F_37 ( struct V_87 * V_88 )
{
F_31 () ;
V_82 = V_88 -> V_89 ;
V_88 -> V_89 = F_34 ;
if ( V_90 . V_91 == 0x15 ) {
V_57 = V_68 ;
} else {
V_57 = V_92 ;
}
V_93 . V_57 = V_57 ;
V_93 . V_94 = V_57 ;
V_93 . V_95 = F_38 ( V_57 , V_96 ) ;
return 0 ;
}
