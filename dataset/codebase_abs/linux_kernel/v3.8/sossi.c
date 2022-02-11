static inline T_1 F_1 ( int V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline T_2 F_3 ( int V_1 )
{
return F_4 ( V_2 . V_3 + V_1 ) ;
}
static inline T_3 F_5 ( int V_1 )
{
return F_6 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_7 ( int V_1 , T_1 V_4 )
{
F_8 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static inline void F_9 ( int V_1 , T_2 V_4 )
{
F_10 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static inline void F_11 ( int V_1 , T_3 V_4 )
{
F_12 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static void F_13 ( int V_1 , T_1 V_5 )
{
F_7 ( V_1 , F_1 ( V_1 ) | V_5 ) ;
}
static void F_14 ( int V_1 , T_1 V_5 )
{
F_7 ( V_1 , F_1 ( V_1 ) & ~ V_5 ) ;
}
static T_1 F_15 ( T_1 V_6 , int div )
{
T_1 V_7 = F_16 ( V_2 . V_8 ) * div ;
return ( V_7 + V_6 - 1 ) / V_7 ;
}
static int F_17 ( struct V_9 * V_10 )
{
T_1 V_11 , V_12 ;
int V_13 , V_14 , V_15 , V_16 ;
int div = V_10 -> V_17 ;
V_13 = F_15 ( V_10 -> V_18 , div ) ;
if ( V_13 > 1 )
return - 1 ;
V_14 = F_15 ( V_10 -> V_19 , div ) ;
if ( V_14 <= V_13 )
V_14 = V_13 + 1 ;
V_11 = V_14 - V_13 ;
if ( V_11 > 0x10 )
return - 1 ;
V_15 = F_15 ( V_10 -> V_20 , div ) ;
if ( V_15 <= V_14 )
V_15 = V_14 + 1 ;
V_12 = V_15 - V_11 ;
if ( V_12 < 3 )
V_12 = 3 ;
if ( V_12 > 0x40 )
return - 1 ;
V_16 = F_15 ( V_10 -> V_21 , div ) ;
if ( V_16 < V_14 )
V_16 ++ ;
if ( V_16 - V_14 > 1 )
return - 1 ;
V_10 -> V_22 [ 0 ] = V_11 - 1 ;
V_10 -> V_22 [ 1 ] = V_12 - 1 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_1 V_11 , V_12 ;
int V_23 , V_24 , V_25 ;
int div = V_10 -> V_17 ;
V_23 = F_15 ( V_10 -> V_26 , div ) ;
if ( V_23 > 1 )
return - 1 ;
V_24 = F_15 ( V_10 -> V_27 , div ) ;
if ( V_24 <= V_23 )
V_24 = V_23 + 1 ;
V_11 = V_24 - V_23 ;
if ( V_11 > 0x10 )
return - 1 ;
V_25 = F_15 ( V_10 -> V_28 , div ) ;
if ( V_25 <= V_24 )
V_25 = V_24 + 1 ;
V_12 = V_25 - V_11 ;
if ( V_12 < 3 )
V_12 = 3 ;
if ( V_12 > 0x40 )
return - 1 ;
V_10 -> V_22 [ 2 ] = V_11 - 1 ;
V_10 -> V_22 [ 3 ] = V_12 - 1 ;
return 0 ;
}
static void F_19 ( int div , int V_11 , int V_12 )
{
T_1 V_29 ;
#ifdef F_20
F_21 ( V_2 . V_30 -> V_31 , L_1 ,
V_11 + 1 , V_12 + 1 , div ) ;
#endif
F_22 ( V_2 . V_32 , V_2 . V_8 / div ) ;
F_23 ( V_2 . V_32 ) ;
V_29 = F_1 ( V_33 ) ;
V_29 &= ~ ( ( 0x0f << 20 ) | ( 0x3f << 24 ) ) ;
V_29 |= ( V_11 << 20 ) | ( V_12 << 24 ) ;
F_7 ( V_33 , V_29 ) ;
F_24 ( V_2 . V_32 ) ;
}
static void F_25 ( int V_34 , int V_35 )
{
T_1 V_29 ;
V_29 = F_1 ( V_36 ) ;
V_29 &= ~ 0x3ff ;
V_29 |= ( ( V_34 - 1 ) << 5 ) | ( ( V_35 - 1 ) & 0x1f ) ;
F_7 ( V_36 , V_29 ) ;
}
static void F_26 ( int V_37 , unsigned line )
{
T_1 V_29 ;
V_29 = F_1 ( V_38 ) ;
V_29 &= ~ ( ( ( 1 << 11 ) - 1 ) << 15 ) ;
V_29 |= line << 15 ;
V_29 &= ~ ( 0x3 << 26 ) ;
V_29 |= V_37 << 26 ;
F_7 ( V_38 , V_29 ) ;
if ( V_37 )
F_13 ( V_39 , 1 << 6 ) ;
else
F_14 ( V_39 , 1 << 6 ) ;
}
static inline void F_27 ( int V_40 )
{
if ( V_40 != V_2 . V_41 ) {
V_2 . V_41 = V_40 ;
F_19 ( V_2 . V_17 ,
V_2 . V_42 [ V_40 ] , V_2 . V_43 [ V_40 ] ) ;
}
}
static void F_28 ( void )
{
F_14 ( V_39 , 1 << 4 ) ;
F_14 ( V_33 , 1 << 30 ) ;
}
static void F_29 ( void )
{
F_13 ( V_39 , 1 << 4 ) ;
F_13 ( V_33 , 1 << 30 ) ;
}
static void F_30 ( void )
{
while ( ! ( F_1 ( V_39 ) & ( 1 << 3 ) ) ) ;
}
static void F_31 ( const void * V_44 , unsigned int V_45 )
{
while ( V_45 >= 4 ) {
F_7 ( V_46 , * ( const T_1 * ) V_44 ) ;
V_45 -= 4 ;
V_44 += 4 ;
}
while ( V_45 >= 2 ) {
F_9 ( V_46 , * ( const T_2 * ) V_44 ) ;
V_45 -= 2 ;
V_44 += 2 ;
}
while ( V_45 ) {
F_11 ( V_46 , * ( const T_3 * ) V_44 ) ;
V_45 -- ;
V_44 ++ ;
}
}
static void F_32 ( unsigned int V_45 )
{
unsigned long V_47 = V_45 / ( V_2 . V_35 / 8 ) ;
F_33 ( ( V_47 - 1 ) & ~ 0x3ffff ) ;
F_14 ( V_33 , 0x3ffff ) ;
F_13 ( V_33 , ( V_47 - 1 ) & 0x3ffff ) ;
}
static int F_34 ( struct V_9 * V_10 )
{
int V_48 = 0 ;
int div = V_10 -> V_17 ;
V_10 -> V_49 = 0 ;
if ( div <= 0 || div > 8 )
return - 1 ;
if ( ( V_48 = F_17 ( V_10 ) ) < 0 )
return V_48 ;
if ( ( V_48 = F_18 ( V_10 ) ) < 0 )
return V_48 ;
V_10 -> V_22 [ 4 ] = div ;
V_10 -> V_49 = 1 ;
return 0 ;
}
static void F_35 ( const struct V_9 * V_10 )
{
F_33 ( ! V_10 -> V_49 ) ;
V_2 . V_42 [ V_50 ] = V_10 -> V_22 [ 0 ] ;
V_2 . V_43 [ V_50 ] = V_10 -> V_22 [ 1 ] ;
V_2 . V_42 [ V_51 ] = V_10 -> V_22 [ 2 ] ;
V_2 . V_43 [ V_51 ] = V_10 -> V_22 [ 3 ] ;
V_2 . V_17 = V_10 -> V_22 [ 4 ] ;
}
static void F_36 ( T_1 * V_7 , T_1 * V_52 )
{
* V_7 = F_16 ( V_2 . V_8 ) ;
* V_52 = 8 ;
}
static void F_37 ( int V_53 )
{
int V_34 , V_35 ;
switch ( V_53 ) {
case 8 :
V_34 = 4 ;
V_35 = 8 ;
break;
case 16 :
V_34 = 2 ;
V_35 = 16 ;
break;
default:
F_38 () ;
return;
}
V_2 . V_35 = V_35 ;
V_2 . V_34 = V_34 ;
}
static int F_39 ( unsigned V_54 ,
unsigned V_55 , unsigned V_56 ,
int V_57 , int V_58 , int div )
{
int V_59 , V_60 ;
T_1 V_29 ;
if ( V_54 != 1 || div < 1 || div > 8 )
return - V_61 ;
V_59 = F_15 ( V_55 , div ) ;
V_60 = F_15 ( V_56 , div ) ;
if ( V_60 < 8 || V_60 <= V_59 || V_60 >= ( 1 << 12 ) )
return - V_62 ;
V_60 /= 8 ;
V_60 -- ;
if ( V_59 > 8 )
V_59 = 8 ;
if ( V_59 )
V_59 -- ;
F_21 ( V_2 . V_30 -> V_31 ,
L_2 ,
V_59 , V_60 , V_57 , V_58 ) ;
F_23 ( V_2 . V_32 ) ;
V_29 = F_1 ( V_38 ) ;
V_29 &= ~ ( ( 1 << 15 ) - 1 ) ;
V_29 |= V_60 << 3 ;
V_29 |= V_59 ;
if ( V_57 )
V_29 |= 1 << 29 ;
else
V_29 &= ~ ( 1 << 29 ) ;
if ( V_58 )
V_29 |= 1 << 28 ;
else
V_29 &= ~ ( 1 << 28 ) ;
F_7 ( V_38 , V_29 ) ;
F_24 ( V_2 . V_32 ) ;
return 0 ;
}
static int F_40 ( int V_63 , unsigned line )
{
int V_37 ;
F_21 ( V_2 . V_30 -> V_31 , L_3 , V_63 , line ) ;
if ( line >= 1 << 11 )
return - V_61 ;
if ( V_63 ) {
if ( line )
V_37 = 2 ;
else
V_37 = 3 ;
} else
V_37 = 0 ;
V_2 . V_64 = line ;
V_2 . V_65 = V_37 ;
return 0 ;
}
static void F_41 ( const void * V_44 , unsigned int V_45 )
{
F_23 ( V_2 . V_32 ) ;
F_27 ( V_51 ) ;
F_25 ( V_2 . V_34 , V_2 . V_35 ) ;
F_14 ( V_33 , 1 << 18 ) ;
F_32 ( V_45 ) ;
F_28 () ;
F_31 ( V_44 , V_45 ) ;
F_29 () ;
F_30 () ;
F_24 ( V_2 . V_32 ) ;
}
static void F_42 ( const void * V_44 , unsigned int V_45 )
{
F_23 ( V_2 . V_32 ) ;
F_27 ( V_51 ) ;
F_25 ( V_2 . V_34 , V_2 . V_35 ) ;
F_13 ( V_33 , 1 << 18 ) ;
F_32 ( V_45 ) ;
F_28 () ;
F_31 ( V_44 , V_45 ) ;
F_29 () ;
F_30 () ;
F_24 ( V_2 . V_32 ) ;
}
static void F_43 ( int V_66 , int V_67 ,
void (F_44)( void * V_44 ) , void * V_44 )
{
F_33 ( F_44 == NULL ) ;
V_2 . V_68 = F_44 ;
V_2 . V_69 = V_44 ;
F_23 ( V_2 . V_32 ) ;
F_27 ( V_51 ) ;
F_25 ( V_2 . V_34 , V_2 . V_35 ) ;
F_26 ( V_2 . V_65 , V_2 . V_64 ) ;
F_13 ( V_33 , 1 << 18 ) ;
F_32 ( V_66 * V_67 * V_2 . V_35 / 8 ) ;
F_28 () ;
if ( V_2 . V_65 ) {
unsigned long V_70 ;
F_45 ( & V_2 . V_71 , V_70 ) ;
V_2 . V_72 ++ ;
F_46 ( & V_2 . V_71 , V_70 ) ;
} else
F_47 () ;
}
static void F_48 ( void * V_44 )
{
F_49 () ;
F_29 () ;
F_24 ( V_2 . V_32 ) ;
V_2 . V_68 ( V_2 . V_69 ) ;
}
static void F_50 ( void * V_44 , unsigned int V_45 )
{
F_23 ( V_2 . V_32 ) ;
F_27 ( V_50 ) ;
F_25 ( V_2 . V_34 , V_2 . V_35 ) ;
F_13 ( V_33 , 1 << 18 ) ;
F_32 ( V_45 ) ;
F_28 () ;
while ( V_45 >= 4 ) {
* ( T_1 * ) V_44 = F_1 ( V_46 ) ;
V_45 -= 4 ;
V_44 += 4 ;
}
while ( V_45 >= 2 ) {
* ( T_2 * ) V_44 = F_3 ( V_46 ) ;
V_45 -= 2 ;
V_44 += 2 ;
}
while ( V_45 ) {
* ( T_3 * ) V_44 = F_5 ( V_46 ) ;
V_45 -- ;
V_44 ++ ;
}
F_29 () ;
F_24 ( V_2 . V_32 ) ;
}
static T_4 F_51 ( int V_73 , void * V_44 )
{
unsigned long V_70 ;
F_45 ( & V_2 . V_71 , V_70 ) ;
if ( V_2 . V_72 ) {
V_2 . V_72 -- ;
F_47 () ;
}
F_46 ( & V_2 . V_71 , V_70 ) ;
return V_74 ;
}
static int F_52 ( struct V_75 * V_30 )
{
T_1 V_29 , V_76 ;
struct V_77 * V_32 ;
struct V_77 * V_78 ;
int V_48 ;
V_2 . V_3 = F_53 ( V_79 , V_80 ) ;
if ( ! V_2 . V_3 ) {
F_54 ( V_30 -> V_31 , L_4 ) ;
return - V_81 ;
}
V_2 . V_30 = V_30 ;
F_55 ( & V_2 . V_71 ) ;
V_78 = F_56 ( V_30 -> V_31 , L_5 ) ;
if ( F_57 ( V_78 ) ) {
F_54 ( V_30 -> V_31 , L_6 ) ;
return F_58 ( V_78 ) ;
}
V_2 . V_8 = F_59 ( V_78 ) ;
F_60 ( V_78 ) ;
V_32 = F_56 ( V_30 -> V_31 , L_7 ) ;
if ( F_57 ( V_32 ) ) {
F_54 ( V_30 -> V_31 , L_8 ) ;
return F_58 ( V_32 ) ;
}
V_2 . V_32 = V_32 ;
V_29 = F_61 ( V_82 ) ;
V_29 |= V_83 ;
F_62 ( V_29 , V_82 ) ;
V_29 &= ~ V_83 ;
F_62 ( V_29 , V_82 ) ;
F_23 ( V_2 . V_32 ) ;
V_29 = F_61 ( V_84 ) ;
V_29 &= ~ ( 1 << 8 ) ;
F_62 ( V_29 , V_84 ) ;
V_29 = F_1 ( V_39 ) ;
V_29 |= ( 1 << 0 ) | ( 1 << 1 ) ;
F_7 ( V_39 , V_29 ) ;
V_29 &= ~ ( 1 << 1 ) ;
F_7 ( V_39 , V_29 ) ;
F_7 ( V_85 , 0 ) ;
V_29 = F_1 ( V_85 ) ;
V_76 = F_1 ( V_85 ) ;
if ( V_29 != 0x55555555 || V_76 != 0xaaaaaaaa ) {
F_54 ( V_30 -> V_31 ,
L_9 , V_29 , V_76 ) ;
V_48 = - V_86 ;
goto V_87;
}
if ( ( V_48 = F_63 ( F_48 , NULL ) ) < 0 ) {
F_54 ( V_30 -> V_31 , L_10 ) ;
V_48 = - V_86 ;
goto V_87;
}
V_29 = F_1 ( V_85 ) ;
V_29 = F_1 ( V_85 ) ;
F_64 ( V_30 -> V_31 , L_11 ,
V_29 >> 16 , V_29 & 0xffff ) ;
V_29 = F_1 ( V_33 ) ;
V_29 |= ( 1 << 19 ) ;
V_29 &= ~ ( 1 << 31 ) ;
F_7 ( V_33 , V_29 ) ;
if ( ( V_48 = F_65 ( V_88 , F_51 ,
V_89 ,
L_12 , V_2 . V_30 -> V_31 ) ) < 0 ) {
F_54 ( V_2 . V_30 -> V_31 , L_13 ) ;
goto V_87;
}
F_24 ( V_2 . V_32 ) ;
return 0 ;
V_87:
F_24 ( V_2 . V_32 ) ;
F_60 ( V_2 . V_32 ) ;
return V_48 ;
}
static void F_66 ( void )
{
F_67 () ;
F_60 ( V_2 . V_32 ) ;
F_68 ( V_2 . V_3 ) ;
}
