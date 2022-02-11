int T_1 F_1 ( T_2 V_1 , int V_2 , int V_3 )
{
unsigned long V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 ;
static int V_7 = 0 ;
T_3 * V_8 ;
int V_9 ;
V_10 = 1 ;
F_3 ( L_1 ) ;
if ( ! V_7 )
V_11 . V_12 = ~ 0UL ;
V_6 = & V_13 [ V_7 ] ;
V_6 -> V_14 . V_15 = & V_16 ;
V_6 -> V_14 . V_17 = & V_6 -> V_18 ;
V_6 -> V_14 . V_19 = & V_6 -> V_20 ;
V_6 -> V_14 . V_21 = V_7 ;
V_6 -> V_18 . V_22 = L_2 ;
V_6 -> V_14 . V_23 = V_4 ;
V_6 -> V_18 . V_24 = 0 ;
V_6 -> V_18 . V_12 = ~ 0UL ;
V_6 -> V_18 . V_25 = V_26 ;
V_6 -> V_20 . V_22 = L_3 ;
V_6 -> V_14 . V_27 = V_4 ;
V_6 -> V_20 . V_24 = 0UL ;
V_6 -> V_20 . V_12 = ~ 0UL ;
V_6 -> V_20 . V_25 = V_28 ;
V_6 -> V_29 = F_4 () ;
V_6 -> V_2 = V_2 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_30 = ( V_31 ) V_3 << 60 | V_32 ;
V_8 = ( T_3 * ) F_5 ( V_1 , V_2 ) ;
V_8 -> V_33 = V_34 ;
V_8 -> V_35 = 0x0 ;
V_8 -> V_36 |= V_37 |
V_38 ;
#ifdef F_6
V_8 -> V_36 &= ~ V_39 ;
#else
V_8 -> V_36 |= V_39 ;
#endif
V_8 -> V_40 = 0x8000 | ( V_3 << 16 ) ;
V_8 -> V_41 = 0x01800090 ;
V_8 -> V_42 = ( V_3 << 20 ) ;
V_8 -> V_43 = 0 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_8 -> V_44 [ V_9 ] . V_45 |= V_46 ;
V_6 -> V_47 [ V_9 ] = - 1 ;
}
V_8 -> V_48 ;
V_6 -> V_49 = V_8 ;
F_7 ( & V_6 -> V_14 ) ;
V_7 ++ ;
return 0 ;
}
int T_4 F_8 ( const struct V_50 * V_51 , T_5 V_9 , T_5 V_52 )
{
return 0 ;
}
static inline struct V_50 * F_9 ( struct V_50 * V_51 )
{
while ( V_51 -> V_53 -> V_54 ) {
V_51 = V_51 -> V_53 -> V_55 ;
}
return V_51 ;
}
int F_10 ( struct V_50 * V_51 )
{
struct V_5 * V_6 = F_11 ( V_51 -> V_53 ) ;
struct V_50 * V_56 = F_9 ( V_51 ) ;
int V_9 = F_12 ( V_56 -> V_57 ) ;
int V_58 ;
V_58 = V_6 -> V_47 [ V_9 ] ;
if ( V_58 == - 1 ) {
V_58 = F_13 ( V_6 ) ;
if ( V_58 < 0 )
return V_58 ;
V_6 -> V_47 [ V_9 ] = V_58 ;
}
V_59 [ V_58 ] = V_6 ;
V_60 [ V_58 ] = V_9 ;
V_51 -> V_58 = V_58 ;
return 0 ;
}
static inline void F_14 ( struct V_50 * V_51 )
{
struct V_5 * V_6 = F_11 ( V_51 -> V_53 ) ;
T_3 * V_8 = V_6 -> V_49 ;
int V_9 = F_12 ( V_51 -> V_57 ) ;
V_8 -> V_44 [ V_9 ] . V_45 &= ~ V_46 ;
V_8 -> V_61 . V_62 ;
}
static inline void F_15 ( struct V_50 * V_51 )
{
struct V_5 * V_6 = F_11 ( V_51 -> V_53 ) ;
T_3 * V_8 = V_6 -> V_49 ;
int V_9 = F_12 ( V_51 -> V_57 ) ;
V_8 -> V_44 [ V_9 ] . V_45 |= V_46 ;
V_8 -> V_61 . V_62 ;
}
static void T_6 F_16 ( struct V_50 * V_63 )
{
F_14 ( V_63 ) ;
}
int F_17 ( struct V_64 * V_53 )
{
struct V_5 * V_6 = F_11 ( V_53 ) ;
return V_6 -> V_1 ;
}
