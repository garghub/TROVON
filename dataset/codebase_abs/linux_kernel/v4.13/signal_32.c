static inline int F_1 ( T_1 T_2 * V_1 , T_3 * V_2 )
{
T_1 V_3 ;
switch ( V_4 ) {
case 4 : V_3 . V_5 [ 6 ] = V_2 -> V_5 [ 3 ] & 0xffffffffull ;
V_3 . V_5 [ 7 ] = V_2 -> V_5 [ 3 ] >> 32 ;
case 3 : V_3 . V_5 [ 4 ] = V_2 -> V_5 [ 2 ] & 0xffffffffull ;
V_3 . V_5 [ 5 ] = V_2 -> V_5 [ 2 ] >> 32 ;
case 2 : V_3 . V_5 [ 2 ] = V_2 -> V_5 [ 1 ] & 0xffffffffull ;
V_3 . V_5 [ 3 ] = V_2 -> V_5 [ 1 ] >> 32 ;
case 1 : V_3 . V_5 [ 0 ] = V_2 -> V_5 [ 0 ] & 0xffffffffull ;
V_3 . V_5 [ 1 ] = V_2 -> V_5 [ 0 ] >> 32 ;
}
return F_2 ( V_1 , & V_3 , sizeof( * V_1 ) ) ;
}
static inline int F_3 ( T_3 * V_2 ,
const T_1 T_2 * V_1 )
{
T_1 V_6 ;
if ( F_4 ( & V_6 , V_1 , sizeof( * V_1 ) ) )
return - V_7 ;
switch ( V_4 ) {
case 4 : V_2 -> V_5 [ 3 ] = V_6 . V_5 [ 6 ] | ( ( ( long ) V_6 . V_5 [ 7 ] ) << 32 ) ;
case 3 : V_2 -> V_5 [ 2 ] = V_6 . V_5 [ 4 ] | ( ( ( long ) V_6 . V_5 [ 5 ] ) << 32 ) ;
case 2 : V_2 -> V_5 [ 1 ] = V_6 . V_5 [ 2 ] | ( ( ( long ) V_6 . V_5 [ 3 ] ) << 32 ) ;
case 1 : V_2 -> V_5 [ 0 ] = V_6 . V_5 [ 0 ] | ( ( ( long ) V_6 . V_5 [ 1 ] ) << 32 ) ;
}
return 0 ;
}
static inline int F_5 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_11 )
{
T_4 * V_12 = ( T_4 * ) V_9 ;
int V_13 ;
F_6 ( ! F_7 ( V_9 ) ) ;
for ( V_13 = 0 ; V_13 <= V_14 ; V_13 ++ ) {
if ( V_13 == 14 && ! F_7 ( V_9 ) )
V_13 = 32 ;
if ( F_8 ( ( unsigned int ) V_12 [ V_13 ] , & V_11 -> V_15 [ V_13 ] ) )
return - V_7 ;
}
return 0 ;
}
static inline int F_9 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_16 )
{
T_4 * V_12 = ( T_4 * ) V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 <= V_14 ; V_13 ++ ) {
if ( ( V_13 == V_17 ) || ( V_13 == V_18 ) )
continue;
if ( F_10 ( V_12 [ V_13 ] , & V_16 -> V_15 [ V_13 ] ) )
return - V_7 ;
}
return 0 ;
}
static inline int F_1 ( T_3 T_2 * V_1 , T_3 * V_2 )
{
return F_2 ( V_1 , V_2 , sizeof( * V_1 ) ) ;
}
static inline int F_3 ( T_3 * V_2 , const T_3 T_2 * V_1 )
{
return F_4 ( V_2 , V_1 , sizeof( * V_1 ) ) ;
}
static inline int F_5 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_11 )
{
F_6 ( ! F_7 ( V_9 ) ) ;
return F_11 ( & V_11 -> V_15 , V_9 , V_19 ) ;
}
static inline int F_9 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_16 )
{
if ( F_12 ( V_9 , & V_16 -> V_15 ,
V_17 * sizeof( V_20 ) ) )
return - V_7 ;
if ( F_12 ( & V_9 -> V_21 , & V_16 -> V_15 [ V_22 ] ,
V_19 - V_22 * sizeof( V_20 ) ) )
return - V_7 ;
return 0 ;
}
unsigned long F_13 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
T_5 V_26 [ V_27 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < ( V_27 - 1 ) ; V_13 ++ )
V_26 [ V_13 ] = V_25 -> V_28 . V_29 ( V_13 ) ;
V_26 [ V_13 ] = V_25 -> V_28 . V_30 . V_31 ;
return F_11 ( V_23 , V_26 , V_27 * sizeof( double ) ) ;
}
unsigned long F_14 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
T_5 V_26 [ V_27 ] ;
int V_13 ;
if ( F_12 ( V_26 , V_32 , V_27 * sizeof( double ) ) )
return 1 ;
for ( V_13 = 0 ; V_13 < ( V_27 - 1 ) ; V_13 ++ )
V_25 -> V_28 . V_29 ( V_13 ) = V_26 [ V_13 ] ;
V_25 -> V_28 . V_30 . V_31 = V_26 [ V_13 ] ;
return 0 ;
}
unsigned long F_15 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
T_5 V_26 [ V_33 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
V_26 [ V_13 ] = V_25 -> V_28 . V_30 . V_34 [ V_13 ] [ V_35 ] ;
return F_11 ( V_23 , V_26 , V_33 * sizeof( double ) ) ;
}
unsigned long F_16 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
T_5 V_26 [ V_33 ] ;
int V_13 ;
if ( F_12 ( V_26 , V_32 , V_33 * sizeof( double ) ) )
return 1 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
V_25 -> V_28 . V_30 . V_34 [ V_13 ] [ V_35 ] = V_26 [ V_13 ] ;
return 0 ;
}
unsigned long F_17 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
T_5 V_26 [ V_27 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < ( V_27 - 1 ) ; V_13 ++ )
V_26 [ V_13 ] = V_25 -> V_28 . V_36 ( V_13 ) ;
V_26 [ V_13 ] = V_25 -> V_28 . V_37 . V_31 ;
return F_11 ( V_23 , V_26 , V_27 * sizeof( double ) ) ;
}
unsigned long F_18 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
T_5 V_26 [ V_27 ] ;
int V_13 ;
if ( F_12 ( V_26 , V_32 , V_27 * sizeof( double ) ) )
return 1 ;
for ( V_13 = 0 ; V_13 < ( V_27 - 1 ) ; V_13 ++ )
V_25 -> V_28 . V_36 ( V_13 ) = V_26 [ V_13 ] ;
V_25 -> V_28 . V_37 . V_31 = V_26 [ V_13 ] ;
return 0 ;
}
unsigned long F_19 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
T_5 V_26 [ V_33 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
V_26 [ V_13 ] = V_25 -> V_28 . V_37 . V_34 [ V_13 ] [ V_35 ] ;
return F_11 ( V_23 , V_26 , V_33 * sizeof( double ) ) ;
}
unsigned long F_20 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
T_5 V_26 [ V_33 ] ;
int V_13 ;
if ( F_12 ( V_26 , V_32 , V_33 * sizeof( double ) ) )
return 1 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
V_25 -> V_28 . V_37 . V_34 [ V_13 ] [ V_35 ] = V_26 [ V_13 ] ;
return 0 ;
}
inline unsigned long F_13 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
return F_11 ( V_23 , V_25 -> V_28 . V_30 . V_34 ,
V_27 * sizeof( double ) ) ;
}
inline unsigned long F_14 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
return F_12 ( V_25 -> V_28 . V_30 . V_34 , V_32 ,
V_27 * sizeof( double ) ) ;
}
inline unsigned long F_17 ( void T_2 * V_23 ,
struct V_24 * V_25 )
{
return F_11 ( V_23 , V_25 -> V_28 . V_37 . V_34 ,
V_27 * sizeof( double ) ) ;
}
inline unsigned long F_18 ( struct V_24 * V_25 ,
void T_2 * V_32 )
{
return F_12 ( V_25 -> V_28 . V_37 . V_34 , V_32 ,
V_27 * sizeof( double ) ) ;
}
static int F_21 ( struct V_8 * V_9 , struct V_10 T_2 * V_11 ,
struct V_10 T_2 * V_38 , int V_39 ,
int V_40 )
{
unsigned long V_41 = V_9 -> V_41 ;
F_22 ( V_42 ) ;
if ( F_5 ( V_9 , V_11 ) )
return 1 ;
#ifdef F_23
if ( V_42 -> V_28 . V_43 ) {
F_24 ( V_42 ) ;
if ( F_11 ( & V_11 -> V_44 , & V_42 -> V_28 . V_45 ,
V_46 * sizeof( V_47 ) ) )
return 1 ;
V_41 |= V_48 ;
}
if ( F_25 ( V_49 ) )
V_42 -> V_28 . V_50 = F_26 ( V_51 ) ;
if ( F_8 ( V_42 -> V_28 . V_50 , ( V_52 T_2 * ) & V_11 -> V_44 [ 32 ] ) )
return 1 ;
#endif
if ( F_13 ( & V_11 -> V_53 , V_42 ) )
return 1 ;
V_41 &= ~ V_54 ;
#ifdef F_27
if ( V_42 -> V_28 . V_55 && V_40 ) {
F_28 ( V_42 ) ;
if ( F_15 ( & V_11 -> V_56 , V_42 ) )
return 1 ;
V_41 |= V_54 ;
}
#endif
#ifdef F_29
if ( V_42 -> V_28 . V_57 ) {
F_30 ( V_42 ) ;
if ( F_11 ( & V_11 -> V_44 , V_42 -> V_28 . V_58 ,
V_59 * sizeof( V_52 ) ) )
return 1 ;
V_41 |= V_60 ;
}
if ( F_8 ( V_42 -> V_28 . V_61 , ( V_52 T_2 * ) & V_11 -> V_44 + V_59 ) )
return 1 ;
#endif
if ( F_8 ( V_41 , & V_11 -> V_15 [ V_17 ] ) )
return 1 ;
if ( V_38 && F_8 ( 0 , & V_38 -> V_15 [ V_17 ] ) )
return 1 ;
if ( V_39 ) {
if ( F_8 ( 0x38000000UL + V_39 , & V_11 -> V_62 [ 0 ] )
|| F_8 ( 0x44000002UL , & V_11 -> V_62 [ 1 ] ) )
return 1 ;
F_31 ( ( unsigned long ) & V_11 -> V_62 [ 0 ] ,
( unsigned long ) & V_11 -> V_62 [ 2 ] ) ;
}
return 0 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_11 ,
struct V_10 T_2 * V_38 , int V_39 )
{
unsigned long V_41 = V_9 -> V_41 ;
V_9 -> V_41 &= ~ V_63 ;
if ( F_5 ( & V_42 -> V_28 . V_64 , V_11 )
|| F_5 ( V_9 , V_38 ) )
return 1 ;
if ( F_8 ( ( V_41 >> 32 ) , & V_38 -> V_15 [ V_17 ] ) )
return 1 ;
#ifdef F_23
if ( V_42 -> V_28 . V_43 ) {
if ( F_11 ( & V_11 -> V_44 , & V_42 -> V_28 . V_65 ,
V_46 * sizeof( V_47 ) ) )
return 1 ;
if ( V_41 & V_48 ) {
if ( F_11 ( & V_38 -> V_44 ,
& V_42 -> V_28 . V_45 ,
V_46 * sizeof( V_47 ) ) )
return 1 ;
} else {
if ( F_11 ( & V_38 -> V_44 ,
& V_42 -> V_28 . V_65 ,
V_46 * sizeof( V_47 ) ) )
return 1 ;
}
V_41 |= V_48 ;
}
if ( F_25 ( V_49 ) )
V_42 -> V_28 . V_66 = F_26 ( V_51 ) ;
if ( F_8 ( V_42 -> V_28 . V_66 ,
( V_52 T_2 * ) & V_11 -> V_44 [ 32 ] ) )
return 1 ;
if ( V_41 & V_48 ) {
if ( F_8 ( V_42 -> V_28 . V_50 ,
( V_52 T_2 * ) & V_38 -> V_44 [ 32 ] ) )
return 1 ;
} else {
if ( F_8 ( V_42 -> V_28 . V_66 ,
( V_52 T_2 * ) & V_38 -> V_44 [ 32 ] ) )
return 1 ;
}
#endif
if ( F_17 ( & V_11 -> V_53 , V_42 ) )
return 1 ;
if ( V_41 & V_67 ) {
if ( F_13 ( & V_38 -> V_53 , V_42 ) )
return 1 ;
} else {
if ( F_17 ( & V_38 -> V_53 , V_42 ) )
return 1 ;
}
#ifdef F_27
if ( V_42 -> V_28 . V_55 ) {
if ( F_19 ( & V_11 -> V_56 , V_42 ) )
return 1 ;
if ( V_41 & V_54 ) {
if ( F_15 ( & V_38 -> V_56 ,
V_42 ) )
return 1 ;
} else {
if ( F_19 ( & V_38 -> V_56 , V_42 ) )
return 1 ;
}
V_41 |= V_54 ;
}
#endif
#ifdef F_29
if ( V_42 -> V_28 . V_57 ) {
F_30 ( V_42 ) ;
if ( F_11 ( & V_11 -> V_44 , V_42 -> V_28 . V_58 ,
V_59 * sizeof( V_52 ) ) )
return 1 ;
V_41 |= V_60 ;
}
if ( F_8 ( V_42 -> V_28 . V_61 , ( V_52 T_2 * ) & V_11 -> V_44 + V_59 ) )
return 1 ;
#endif
if ( F_8 ( V_41 , & V_11 -> V_15 [ V_17 ] ) )
return 1 ;
if ( V_39 ) {
if ( F_8 ( 0x38000000UL + V_39 , & V_11 -> V_62 [ 0 ] )
|| F_8 ( 0x44000002UL , & V_11 -> V_62 [ 1 ] ) )
return 1 ;
F_31 ( ( unsigned long ) & V_11 -> V_62 [ 0 ] ,
( unsigned long ) & V_11 -> V_62 [ 2 ] ) ;
}
return 0 ;
}
static long F_33 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_16 , int V_5 )
{
long V_68 ;
unsigned int V_69 = 0 ;
unsigned long V_41 ;
#ifdef F_27
int V_13 ;
#endif
if ( ! V_5 )
V_69 = ( unsigned int ) V_9 -> V_70 [ 2 ] ;
V_68 = F_9 ( V_9 , V_16 ) ;
V_9 -> V_71 = 0 ;
V_68 |= F_10 ( V_41 , & V_16 -> V_15 [ V_17 ] ) ;
if ( ! V_5 )
V_9 -> V_70 [ 2 ] = ( unsigned long ) V_69 ;
if ( V_68 )
return 1 ;
if ( V_5 )
V_9 -> V_41 = ( V_9 -> V_41 & ~ V_72 ) | ( V_41 & V_72 ) ;
#ifdef F_23
V_9 -> V_41 &= ~ V_48 ;
if ( V_41 & V_48 ) {
if ( F_12 ( & V_42 -> V_28 . V_45 , & V_16 -> V_44 ,
sizeof( V_16 -> V_44 ) ) )
return 1 ;
V_42 -> V_28 . V_43 = true ;
} else if ( V_42 -> V_28 . V_43 )
memset ( & V_42 -> V_28 . V_45 , 0 ,
V_46 * sizeof( V_47 ) ) ;
if ( F_10 ( V_42 -> V_28 . V_50 , ( V_52 T_2 * ) & V_16 -> V_44 [ 32 ] ) )
return 1 ;
if ( F_25 ( V_49 ) )
F_34 ( V_51 , V_42 -> V_28 . V_50 ) ;
#endif
if ( F_14 ( V_42 , & V_16 -> V_53 ) )
return 1 ;
#ifdef F_27
V_9 -> V_41 &= ~ V_54 ;
if ( V_41 & V_54 ) {
if ( F_16 ( V_42 , & V_16 -> V_56 ) )
return 1 ;
V_42 -> V_28 . V_55 = true ;
} else if ( V_42 -> V_28 . V_55 )
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ )
V_42 -> V_28 . V_30 . V_34 [ V_13 ] [ V_35 ] = 0 ;
#endif
V_9 -> V_41 &= ~ ( V_67 | V_73 | V_74 ) ;
#ifdef F_29
V_9 -> V_41 &= ~ V_60 ;
if ( V_41 & V_60 ) {
if ( F_12 ( V_42 -> V_28 . V_58 , & V_16 -> V_44 ,
V_59 * sizeof( V_52 ) ) )
return 1 ;
V_42 -> V_28 . V_57 = true ;
} else if ( V_42 -> V_28 . V_57 )
memset ( V_42 -> V_28 . V_58 , 0 , V_59 * sizeof( V_52 ) ) ;
if ( F_10 ( V_42 -> V_28 . V_61 , ( V_52 T_2 * ) & V_16 -> V_44 + V_59 ) )
return 1 ;
#endif
return 0 ;
}
static long F_35 ( struct V_8 * V_9 ,
struct V_10 T_2 * V_16 ,
struct V_10 T_2 * V_75 )
{
long V_68 ;
unsigned long V_41 , V_76 ;
#ifdef F_27
int V_13 ;
#endif
V_68 = F_9 ( V_9 , V_75 ) ;
V_68 |= F_9 ( & V_42 -> V_28 . V_64 , V_16 ) ;
V_68 |= F_10 ( V_42 -> V_28 . V_77 , & V_16 -> V_15 [ V_78 ] ) ;
V_68 |= F_10 ( V_41 , & V_16 -> V_15 [ V_17 ] ) ;
if ( V_68 )
return 1 ;
V_9 -> V_41 = ( V_9 -> V_41 & ~ V_72 ) | ( V_41 & V_72 ) ;
#ifdef F_23
V_9 -> V_41 &= ~ V_48 ;
if ( V_41 & V_48 ) {
if ( F_12 ( & V_42 -> V_28 . V_65 , & V_16 -> V_44 ,
sizeof( V_16 -> V_44 ) ) ||
F_12 ( & V_42 -> V_28 . V_45 ,
& V_75 -> V_44 ,
sizeof( V_16 -> V_44 ) ) )
return 1 ;
V_42 -> V_28 . V_43 = true ;
} else if ( V_42 -> V_28 . V_43 ) {
memset ( & V_42 -> V_28 . V_45 , 0 ,
V_46 * sizeof( V_47 ) ) ;
memset ( & V_42 -> V_28 . V_65 , 0 ,
V_46 * sizeof( V_47 ) ) ;
}
if ( F_10 ( V_42 -> V_28 . V_66 ,
( V_52 T_2 * ) & V_16 -> V_44 [ 32 ] ) ||
F_10 ( V_42 -> V_28 . V_50 ,
( V_52 T_2 * ) & V_75 -> V_44 [ 32 ] ) )
return 1 ;
if ( F_25 ( V_49 ) )
F_34 ( V_51 , V_42 -> V_28 . V_66 ) ;
#endif
V_9 -> V_41 &= ~ ( V_67 | V_73 | V_74 ) ;
if ( F_14 ( V_42 , & V_16 -> V_53 ) ||
F_18 ( V_42 , & V_75 -> V_53 ) )
return 1 ;
#ifdef F_27
V_9 -> V_41 &= ~ V_54 ;
if ( V_41 & V_54 ) {
if ( F_16 ( V_42 , & V_75 -> V_56 ) ||
F_20 ( V_42 , & V_16 -> V_56 ) )
return 1 ;
V_42 -> V_28 . V_55 = true ;
} else if ( V_42 -> V_28 . V_55 )
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
V_42 -> V_28 . V_30 . V_34 [ V_13 ] [ V_35 ] = 0 ;
V_42 -> V_28 . V_37 . V_34 [ V_13 ] [ V_35 ] = 0 ;
}
#endif
#ifdef F_29
V_9 -> V_41 &= ~ V_60 ;
if ( V_41 & V_60 ) {
if ( F_12 ( V_42 -> V_28 . V_58 , & V_16 -> V_44 ,
V_59 * sizeof( V_52 ) ) )
return 1 ;
V_42 -> V_28 . V_57 = true ;
} else if ( V_42 -> V_28 . V_57 )
memset ( V_42 -> V_28 . V_58 , 0 , V_59 * sizeof( V_52 ) ) ;
if ( F_10 ( V_42 -> V_28 . V_61 , ( V_52 T_2 * ) & V_16 -> V_44
+ V_59 ) )
return 1 ;
#endif
if ( F_10 ( V_76 , & V_75 -> V_15 [ V_17 ] ) )
return 1 ;
V_76 <<= 32 ;
if ( F_36 ( V_76 ) )
return 1 ;
V_9 -> V_41 = ( V_9 -> V_41 & ~ V_63 ) | ( V_76 & V_63 ) ;
F_37 () ;
V_42 -> V_28 . V_79 |= V_80 ;
F_38 ( & V_42 -> V_28 , V_41 ) ;
F_39 ( V_41 & ( V_67 | V_48 ) ) ;
if ( V_41 & V_67 ) {
F_40 ( & V_42 -> V_28 . V_30 ) ;
V_9 -> V_41 |= ( V_67 | V_42 -> V_28 . V_81 ) ;
}
#ifdef F_23
if ( V_41 & V_48 ) {
F_41 ( & V_42 -> V_28 . V_45 ) ;
V_9 -> V_41 |= V_48 ;
}
#endif
return 0 ;
}
int F_42 ( struct V_82 T_2 * V_83 , const T_6 * V_84 )
{
int V_68 ;
if ( ! F_43 ( V_85 , V_83 , sizeof( * V_83 ) ) )
return - V_7 ;
V_68 = F_8 ( V_84 -> V_86 , & V_83 -> V_86 ) ;
V_68 |= F_8 ( V_84 -> V_87 , & V_83 -> V_87 ) ;
V_68 |= F_8 ( ( short ) V_84 -> V_88 , & V_83 -> V_88 ) ;
if ( V_84 -> V_88 < 0 )
V_68 |= F_11 ( & V_83 -> V_89 . V_90 , & V_84 -> V_89 . V_90 ,
V_91 ) ;
else switch( V_84 -> V_88 >> 16 ) {
case V_92 >> 16 :
V_68 |= F_8 ( V_84 -> V_93 , & V_83 -> V_93 ) ;
V_68 |= F_8 ( V_84 -> V_94 , & V_83 -> V_94 ) ;
V_68 |= F_8 ( V_84 -> V_95 , & V_83 -> V_95 ) ;
V_68 |= F_8 ( V_84 -> V_96 , & V_83 -> V_96 ) ;
V_68 |= F_8 ( V_84 -> V_97 , & V_83 -> V_97 ) ;
break;
case V_98 >> 16 :
V_68 |= F_8 ( ( unsigned int ) ( unsigned long ) V_84 -> V_99 ,
& V_83 -> V_99 ) ;
break;
case V_100 >> 16 :
V_68 |= F_8 ( V_84 -> V_101 , & V_83 -> V_101 ) ;
V_68 |= F_8 ( V_84 -> V_102 , & V_83 -> V_102 ) ;
break;
case V_103 >> 16 :
V_68 |= F_8 ( V_84 -> V_104 , & V_83 -> V_104 ) ;
V_68 |= F_8 ( V_84 -> V_105 , & V_83 -> V_105 ) ;
V_68 |= F_8 ( V_84 -> V_106 , & V_83 -> V_106 ) ;
break;
case V_107 >> 16 :
V_68 |= F_8 ( F_44 ( V_84 -> V_108 ) , & V_83 -> V_108 ) ;
V_68 |= F_8 ( V_84 -> V_109 , & V_83 -> V_109 ) ;
V_68 |= F_8 ( V_84 -> V_110 , & V_83 -> V_110 ) ;
break;
case V_111 >> 16 :
case V_112 >> 16 :
V_68 |= F_8 ( V_84 -> V_106 , & V_83 -> V_106 ) ;
case V_113 >> 16 :
default:
V_68 |= F_8 ( V_84 -> V_93 , & V_83 -> V_93 ) ;
V_68 |= F_8 ( V_84 -> V_94 , & V_83 -> V_94 ) ;
break;
}
return V_68 ;
}
int F_45 ( T_6 * V_23 , struct V_82 T_2 * V_32 )
{
if ( F_4 ( V_23 , V_32 , 3 * sizeof( int ) ) ||
F_4 ( V_23 -> V_89 . V_90 ,
V_32 -> V_89 . V_90 , V_91 ) )
return - V_7 ;
return 0 ;
}
int F_46 ( struct V_114 * V_115 , T_3 * V_116 ,
struct V_24 * V_117 )
{
struct V_118 T_2 * V_119 ;
struct V_10 T_2 * V_11 ;
struct V_10 T_2 * V_38 = NULL ;
void T_2 * V_120 ;
unsigned long V_121 = 0 ;
int V_39 ;
unsigned long V_62 ;
struct V_8 * V_9 = V_117 -> V_28 . V_9 ;
F_47 ( V_117 != V_42 ) ;
V_119 = F_48 ( V_115 , F_49 ( V_117 ) , sizeof( * V_119 ) , 1 ) ;
V_120 = V_119 ;
if ( F_50 ( V_119 == NULL ) )
goto V_122;
if ( F_51 ( & V_119 -> V_123 , & V_115 -> V_123 )
|| F_8 ( 0 , & V_119 -> V_124 . V_125 )
|| F_52 ( & V_119 -> V_124 . V_126 , V_9 -> V_70 [ 1 ] )
|| F_8 ( F_53 ( & V_119 -> V_124 . V_127 ) ,
& V_119 -> V_124 . V_128 )
|| F_1 ( & V_119 -> V_124 . V_129 , V_116 ) )
goto V_122;
V_11 = & V_119 -> V_124 . V_127 ;
V_120 = V_11 ;
if ( V_130 && V_117 -> V_131 -> V_132 . V_133 ) {
V_39 = 0 ;
V_62 = V_117 -> V_131 -> V_132 . V_133 + V_130 ;
} else {
V_39 = V_134 ;
V_62 = ( unsigned long ) V_11 -> V_62 ;
}
#ifdef F_54
V_38 = & V_119 -> V_135 . V_127 ;
if ( F_55 ( V_9 -> V_41 ) ) {
if ( F_8 ( ( unsigned long ) & V_119 -> V_135 ,
& V_119 -> V_124 . V_136 ) ||
F_8 ( ( unsigned long ) V_38 ,
& V_119 -> V_135 . V_128 ) )
goto V_122;
if ( F_32 ( V_9 , V_11 , V_38 , V_39 ) )
goto V_122;
}
else
#endif
{
if ( F_8 ( 0 , & V_119 -> V_124 . V_136 ) )
goto V_122;
if ( F_21 ( V_9 , V_11 , V_38 , V_39 , 1 ) )
goto V_122;
}
V_9 -> V_137 = V_62 ;
V_117 -> V_28 . V_30 . V_31 = 0 ;
V_121 = ( ( unsigned long ) V_119 ) - ( V_138 + 16 ) ;
V_120 = ( void T_2 * ) V_9 -> V_70 [ 1 ] ;
if ( F_56 ( V_9 -> V_70 [ 1 ] , ( V_52 T_2 * ) V_121 ) )
goto V_122;
V_9 -> V_70 [ 1 ] = V_121 ;
V_9 -> V_70 [ 3 ] = V_115 -> V_5 ;
V_9 -> V_70 [ 4 ] = ( unsigned long ) & V_119 -> V_123 ;
V_9 -> V_70 [ 5 ] = ( unsigned long ) & V_119 -> V_124 ;
V_9 -> V_70 [ 6 ] = ( unsigned long ) V_119 ;
V_9 -> V_139 = ( unsigned long ) V_115 -> V_140 . V_141 . V_142 ;
V_9 -> V_41 &= ~ V_72 ;
V_9 -> V_41 |= ( V_143 & V_72 ) ;
return 0 ;
V_122:
if ( V_144 )
F_57 ( V_145
L_1
L_2 ,
V_117 -> V_146 , V_117 -> V_147 ,
V_120 , V_9 -> V_139 , V_9 -> V_137 ) ;
return 1 ;
}
static int F_58 ( struct V_148 T_2 * V_149 , struct V_8 * V_9 , int V_5 )
{
T_3 V_2 ;
struct V_10 T_2 * V_150 ;
if ( F_3 ( & V_2 , & V_149 -> V_129 ) )
return - V_7 ;
#ifdef F_59
{
V_52 V_151 ;
if ( F_10 ( V_151 , & V_149 -> V_128 ) )
return - V_7 ;
V_150 = (struct V_10 T_2 * ) ( T_5 ) V_151 ;
}
#else
if ( F_10 ( V_150 , & V_149 -> V_128 ) )
return - V_7 ;
if ( ! F_43 ( V_152 , V_150 , sizeof( * V_150 ) ) )
return - V_7 ;
#endif
F_60 ( & V_2 ) ;
if ( F_33 ( V_9 , V_150 , V_5 ) )
return - V_7 ;
return 0 ;
}
static int F_61 ( struct V_148 T_2 * V_149 ,
struct V_148 T_2 * V_153 ,
struct V_8 * V_9 )
{
T_3 V_2 ;
struct V_10 T_2 * V_150 ;
struct V_10 T_2 * V_154 ;
V_52 V_151 ;
V_52 V_155 ;
if ( F_3 ( & V_2 , & V_149 -> V_129 ) )
return - V_7 ;
if ( F_10 ( V_151 , & V_149 -> V_128 ) ||
F_10 ( V_155 , & V_153 -> V_128 ) )
return - V_7 ;
V_150 = (struct V_10 T_2 * ) ( T_5 ) V_151 ;
V_154 = (struct V_10 T_2 * ) ( T_5 ) V_155 ;
F_60 ( & V_2 ) ;
if ( F_35 ( V_9 , V_150 , V_154 ) )
return - V_7 ;
return 0 ;
}
long F_62 ( struct V_148 T_2 * V_156 ,
struct V_148 T_2 * V_157 ,
int V_158 , int V_159 , int V_160 , int V_161 , struct V_8 * V_9 )
{
unsigned char V_162 ;
int V_40 = 0 ;
#ifdef F_59
unsigned long V_163 = 0 ;
if ( V_157 ) {
struct V_10 T_2 * V_150 ;
V_52 V_151 ;
if ( F_10 ( V_151 , & V_157 -> V_128 ) )
return - V_7 ;
V_150 = (struct V_10 T_2 * ) ( T_5 ) V_151 ;
if ( F_10 ( V_163 , & V_150 -> V_15 [ V_17 ] ) )
return - V_7 ;
}
if ( V_158 < V_164 )
return - V_165 ;
if ( ( V_158 < sizeof( struct V_148 ) ) &&
( V_163 & V_54 ) )
return - V_165 ;
if ( V_158 >= sizeof( struct V_148 ) )
V_40 = 1 ;
#else
if ( V_158 < sizeof( struct V_148 ) )
return - V_165 ;
#endif
if ( V_156 != NULL ) {
struct V_10 T_2 * V_166 ;
V_166 = (struct V_10 T_2 * )
( ( unsigned long ) & V_156 -> V_127 & ~ 0xfUL ) ;
if ( ! F_43 ( V_85 , V_156 , V_158 )
|| F_21 ( V_9 , V_166 , NULL , 0 , V_40 )
|| F_1 ( & V_156 -> V_129 , & V_42 -> V_167 )
|| F_8 ( F_53 ( V_166 ) , & V_156 -> V_128 ) )
return - V_7 ;
}
if ( V_157 == NULL )
return 0 ;
if ( ! F_43 ( V_152 , V_157 , V_158 )
|| F_10 ( V_162 , ( V_168 T_2 * ) V_157 )
|| F_10 ( V_162 , ( V_168 T_2 * ) V_157 + V_158 - 1 ) )
return - V_7 ;
if ( F_58 ( V_157 , V_9 , 0 ) )
F_63 ( V_169 ) ;
F_64 ( V_170 ) ;
return 0 ;
}
long F_65 ( int V_171 , int V_172 , int V_173 , int V_159 , int V_160 , int V_161 ,
struct V_8 * V_9 )
{
struct V_118 T_2 * V_119 ;
#ifdef F_54
struct V_148 T_2 * V_135 ;
unsigned long V_76 ;
unsigned long V_162 ;
int V_174 = 0 ;
#endif
V_42 -> V_175 . V_176 = V_177 ;
V_119 = (struct V_118 T_2 * )
( V_9 -> V_70 [ 1 ] + V_138 + 16 ) ;
if ( ! F_43 ( V_152 , V_119 , sizeof( * V_119 ) ) )
goto V_178;
#ifdef F_54
if ( F_66 ( F_67 () ) )
F_68 ( 0 ) ;
if ( F_10 ( V_162 , & V_119 -> V_124 . V_136 ) )
goto V_178;
V_135 = (struct V_148 T_2 * ) ( V_179 ) V_162 ;
if ( V_135 ) {
V_52 V_151 ;
struct V_10 T_2 * V_150 ;
if ( F_10 ( V_151 , & V_135 -> V_128 ) )
return - V_7 ;
V_150 = (struct V_10 T_2 * ) ( T_5 ) V_151 ;
if ( F_10 ( V_76 , & V_150 -> V_15 [ V_17 ] ) )
goto V_178;
if ( F_55 ( V_76 << 32 ) ) {
V_174 = 1 ;
if ( F_61 ( & V_119 -> V_124 , V_135 , V_9 ) )
goto V_178;
}
}
if ( ! V_174 )
#endif
if ( F_58 ( & V_119 -> V_124 , V_9 , 1 ) )
goto V_178;
#ifdef F_59
if ( F_69 ( & V_119 -> V_124 . V_126 ) )
goto V_178;
#else
if ( F_70 ( & V_119 -> V_124 . V_126 ) )
goto V_178;
#endif
F_64 ( V_170 ) ;
return 0 ;
V_178:
if ( V_144 )
F_57 ( V_145
L_3
L_2 ,
V_42 -> V_146 , V_42 -> V_147 ,
V_119 , V_9 -> V_139 , V_9 -> V_137 ) ;
F_71 ( V_169 , V_42 ) ;
return 0 ;
}
int F_72 ( struct V_148 T_2 * V_180 ,
int V_181 , struct V_182 T_2 * V_183 ,
int V_159 , int V_160 , int V_161 ,
struct V_8 * V_9 )
{
struct V_182 V_184 ;
int V_13 ;
unsigned char V_162 ;
unsigned long V_163 = V_9 -> V_41 ;
#ifdef F_73
unsigned long V_185 = V_42 -> V_28 . V_186 . V_187 ;
#endif
for ( V_13 = 0 ; V_13 < V_181 ; V_13 ++ ) {
if ( F_4 ( & V_184 , V_183 + V_13 , sizeof( V_184 ) ) )
return - V_7 ;
switch ( V_184 . V_188 ) {
case V_189 :
#ifdef F_73
if ( V_184 . V_190 ) {
V_163 |= V_191 ;
V_185 |= ( V_192 | V_193 ) ;
} else {
V_185 &= ~ V_193 ;
if ( ! F_74 ( V_185 ,
V_42 -> V_28 . V_186 . V_194 ) ) {
V_163 &= ~ V_191 ;
V_185 &= ~ V_192 ;
}
}
#else
if ( V_184 . V_190 )
V_163 |= V_195 ;
else
V_163 &= ~ V_195 ;
#endif
break;
case V_196 :
#ifdef F_73
return - V_165 ;
#else
if ( V_184 . V_190 )
V_163 |= V_197 ;
else
V_163 &= ~ V_197 ;
#endif
break;
default:
return - V_165 ;
}
}
V_9 -> V_41 = V_163 ;
#ifdef F_73
V_42 -> V_28 . V_186 . V_187 = V_185 ;
#endif
if ( ! F_43 ( V_152 , V_180 , sizeof( * V_180 ) )
|| F_10 ( V_162 , ( V_168 T_2 * ) V_180 )
|| F_10 ( V_162 , ( V_168 T_2 * ) ( V_180 + 1 ) - 1 ) )
return - V_7 ;
if ( F_58 ( V_180 , V_9 , 1 ) ) {
if ( V_144 )
F_57 ( V_145 L_4
L_5
L_6 ,
V_42 -> V_146 , V_42 -> V_147 ,
V_180 , V_9 -> V_139 , V_9 -> V_137 ) ;
F_71 ( V_169 , V_42 ) ;
goto V_198;
}
F_70 ( & V_180 -> V_126 ) ;
F_64 ( V_170 ) ;
V_198:
return 0 ;
}
int F_75 ( struct V_114 * V_115 , T_3 * V_116 ,
struct V_24 * V_117 )
{
struct V_199 T_2 * V_200 ;
struct V_201 T_2 * V_11 ;
struct V_10 T_2 * V_202 = NULL ;
unsigned long V_121 = 0 ;
int V_39 ;
unsigned long V_62 ;
struct V_8 * V_9 = V_117 -> V_28 . V_9 ;
F_47 ( V_117 != V_42 ) ;
V_11 = F_48 ( V_115 , F_49 ( V_117 ) , sizeof( * V_11 ) , 1 ) ;
if ( F_50 ( V_11 == NULL ) )
goto V_122;
V_200 = (struct V_199 T_2 * ) & V_11 -> V_203 ;
#if V_204 != 64
#error "Please adjust handle_signal()"
#endif
if ( F_8 ( F_53 ( V_115 -> V_140 . V_141 . V_142 ) , & V_200 -> V_205 )
|| F_8 ( V_116 -> V_5 [ 0 ] , & V_200 -> V_206 )
#ifdef F_59
|| F_8 ( ( V_116 -> V_5 [ 0 ] >> 32 ) , & V_200 -> V_207 [ 3 ] )
#else
|| F_8 ( V_116 -> V_5 [ 1 ] , & V_200 -> V_207 [ 3 ] )
#endif
|| F_8 ( F_53 ( & V_11 -> V_166 ) , & V_200 -> V_9 )
|| F_8 ( V_115 -> V_5 , & V_200 -> signal ) )
goto V_122;
if ( V_208 && V_117 -> V_131 -> V_132 . V_133 ) {
V_39 = 0 ;
V_62 = V_117 -> V_131 -> V_132 . V_133 + V_208 ;
} else {
V_39 = V_209 ;
V_62 = ( unsigned long ) V_11 -> V_166 . V_62 ;
}
#ifdef F_54
V_202 = & V_11 -> V_210 ;
if ( F_55 ( V_9 -> V_41 ) ) {
if ( F_32 ( V_9 , & V_11 -> V_166 , & V_11 -> V_210 ,
V_39 ) )
goto V_122;
}
else
#endif
{
if ( F_21 ( V_9 , & V_11 -> V_166 , V_202 , V_39 , 1 ) )
goto V_122;
}
V_9 -> V_137 = V_62 ;
V_117 -> V_28 . V_30 . V_31 = 0 ;
V_121 = ( ( unsigned long ) V_11 ) - V_138 ;
if ( F_56 ( V_9 -> V_70 [ 1 ] , ( V_52 T_2 * ) V_121 ) )
goto V_122;
V_9 -> V_70 [ 1 ] = V_121 ;
V_9 -> V_70 [ 3 ] = V_115 -> V_5 ;
V_9 -> V_70 [ 4 ] = ( unsigned long ) V_200 ;
V_9 -> V_139 = ( unsigned long ) ( unsigned long ) V_115 -> V_140 . V_141 . V_142 ;
V_9 -> V_41 &= ~ V_72 ;
return 0 ;
V_122:
if ( V_144 )
F_57 ( V_145
L_7
L_2 ,
V_117 -> V_146 , V_117 -> V_147 ,
V_11 , V_9 -> V_139 , V_9 -> V_137 ) ;
return 1 ;
}
long F_76 ( int V_171 , int V_172 , int V_173 , int V_159 , int V_160 , int V_161 ,
struct V_8 * V_9 )
{
struct V_201 T_2 * V_211 ;
struct V_199 T_2 * V_200 ;
struct V_199 V_212 ;
struct V_10 T_2 * V_16 ;
void T_2 * V_120 ;
T_3 V_2 ;
#ifdef F_54
struct V_10 T_2 * V_150 , * V_154 ;
unsigned long V_76 ;
#endif
V_42 -> V_175 . V_176 = V_177 ;
V_211 = (struct V_201 T_2 * ) ( V_9 -> V_70 [ 1 ] + V_138 ) ;
V_200 = & V_211 -> V_203 ;
V_120 = V_200 ;
if ( F_4 ( & V_212 , V_200 , sizeof( V_212 ) ) )
goto V_122;
#ifdef F_59
V_2 . V_5 [ 0 ] = V_212 . V_206 + ( ( long ) ( V_212 . V_207 [ 3 ] ) << 32 ) ;
#else
V_2 . V_5 [ 0 ] = V_212 . V_206 ;
V_2 . V_5 [ 1 ] = V_212 . V_207 [ 3 ] ;
#endif
F_60 ( & V_2 ) ;
#ifdef F_54
V_150 = (struct V_10 T_2 * ) & V_211 -> V_166 ;
V_154 = (struct V_10 T_2 * ) & V_211 -> V_210 ;
if ( F_10 ( V_76 , & V_154 -> V_15 [ V_17 ] ) )
goto V_122;
if ( F_55 ( V_76 << 32 ) ) {
if ( ! F_25 ( V_213 ) )
goto V_122;
if ( F_35 ( V_9 , V_150 , V_154 ) )
goto V_122;
} else
#endif
{
V_16 = (struct V_10 T_2 * ) F_77 ( V_212 . V_9 ) ;
V_120 = V_16 ;
if ( ! F_43 ( V_152 , V_16 , sizeof( * V_16 ) )
|| F_33 ( V_9 , V_16 , 1 ) )
goto V_122;
}
F_64 ( V_170 ) ;
return 0 ;
V_122:
if ( V_144 )
F_57 ( V_145
L_8
L_2 ,
V_42 -> V_146 , V_42 -> V_147 ,
V_120 , V_9 -> V_139 , V_9 -> V_137 ) ;
F_71 ( V_169 , V_42 ) ;
return 0 ;
}
