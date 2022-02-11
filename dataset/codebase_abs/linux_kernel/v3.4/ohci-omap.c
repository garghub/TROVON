static inline int F_1 ( unsigned V_1 , unsigned V_2 )
{
return 0 ;
}
static void F_2 ( int V_3 )
{
if ( V_3 ) {
F_3 ( V_4 ) ;
F_3 ( V_5 ) ;
F_4 ( 100 ) ;
} else {
F_5 ( V_5 ) ;
F_5 ( V_4 ) ;
}
}
static int F_6 ( int V_3 )
{
if ( V_3 ) {
if ( F_7 () && F_8 () )
F_9 ( F_10 ( V_6 )
| ( ( 1 << 5 ) | ( 1 << 3 ) ) ,
V_6 ) ;
else if ( F_11 () )
F_1 ( V_7 , V_8 ) ;
} else {
if ( F_7 () && F_8 () )
F_9 ( F_10 ( V_6 )
& ~ ( ( 1 << 5 ) | ( 1 << 3 ) ) ,
V_6 ) ;
else if ( F_11 () )
F_1 ( V_7 , V_9 ) ;
}
return 0 ;
}
static int F_12 ( int V_3 )
{
if ( V_3 ) {
F_13 ( ( 1 << 1 ) | ( 1 << 0 ) , V_10 ) ;
F_4 ( 200 ) ;
} else {
F_13 ( 0 , V_10 ) ;
}
return 0 ;
}
static int F_14 ( void )
{
unsigned int V_11 ;
unsigned long V_12 , V_13 ;
F_13 ( ( F_15 ( V_14 ) & 0xfffffff8 ) | 0x4 ,
V_14 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
V_12 = V_11 * 0x00100000 + V_16 ;
V_13 = V_11 * 0x00100000 + V_17 ;
F_13 ( ( V_12 & 0x0fffffff ) >> 22 , V_18 ) ;
F_13 ( ( ( V_12 & 0x003ffc00 ) >> 6 ) | 0xc ,
V_19 ) ;
F_13 ( V_13 >> 16 , V_20 ) ;
F_13 ( ( V_13 & 0x0000fc00 ) | 0x300 , V_21 ) ;
F_13 ( V_11 << 4 , V_22 ) ;
F_13 ( 0x1 , V_23 ) ;
}
F_13 ( F_15 ( V_10 ) | ( 1 << 3 ) , V_10 ) ;
F_4 ( 200 ) ;
return 0 ;
}
static void F_16 ( struct V_24 * V_25 )
{
const unsigned V_26 = F_17 ( V_25 ) -> V_27 . V_28 - 1 ;
unsigned long V_29 ;
T_1 V_30 ;
F_18 ( V_25 -> V_31 -> V_32 ) ;
F_19 ( V_29 ) ;
V_25 -> V_31 -> V_33 = V_34 ;
F_20 ( V_35 , & V_25 -> V_36 -> V_37 . V_38 [ V_26 ] ) ;
V_30 = F_15 ( V_39 ) ;
V_30 &= ~ V_40 ;
F_13 ( V_30 , V_39 ) ;
F_21 ( V_29 ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_24 * V_25 = F_23 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_27 . V_45 -> V_46 ;
int V_47 = ( V_44 -> V_32 != 0 ) ;
int V_48 ;
F_24 ( V_42 -> V_27 . V_45 , L_1 ) ;
if ( V_44 -> V_32 ) {
F_17 ( V_25 ) -> V_27 . V_28 = V_44 -> V_32 ;
F_17 ( V_25 ) -> V_49 = 8 ;
}
V_47 = V_47
|| F_25 () || F_26 () ;
if ( F_27 () )
F_28 () ;
#ifdef F_29
if ( V_47 ) {
V_25 -> V_31 = F_30 () ;
if ( V_25 -> V_31 ) {
int V_50 = F_31 ( V_25 -> V_31 -> V_32 ,
& F_17 ( V_25 ) -> V_27 ) ;
F_24 ( V_42 -> V_27 . V_45 , L_2 ,
V_25 -> V_31 -> V_51 , V_50 ) ;
if ( V_50 ) {
if ( V_25 -> V_31 )
F_32 ( V_25 -> V_31 -> V_52 ) ;
return V_50 ;
}
} else {
F_33 ( V_42 -> V_27 . V_45 , L_3 ) ;
return - V_53 ;
}
V_25 -> F_16 = F_16 ;
}
#endif
F_2 ( 1 ) ;
if ( F_34 () ) {
F_12 ( 1 ) ;
F_14 () ;
}
if ( ( V_48 = F_35 ( V_25 ) ) < 0 )
return V_48 ;
if ( F_11 () || F_7 () ) {
T_1 V_54 = F_36 ( V_25 ) ;
V_54 &= ~ V_55 ;
if ( F_11 () ) {
F_17 ( V_25 ) -> V_49 = 250 ;
V_54 &= ~ V_56 ;
F_37 ( V_57 ) ;
F_38 ( 9 , L_4 ) ;
F_39 ( 9 ) ;
F_37 ( V_58 ) ;
}
F_40 ( V_25 , V_54 , & V_25 -> V_36 -> V_37 . V_59 ) ;
V_25 -> V_29 &= ~ V_60 ;
} else if ( F_41 () ) {
F_17 ( V_25 ) -> V_49 = 0 ;
}
F_6 ( 1 ) ;
return 0 ;
}
static void F_42 ( struct V_41 * V_42 )
{
F_24 ( V_42 -> V_27 . V_45 , L_5 ) ;
F_43 ( V_42 ) ;
F_2 ( 0 ) ;
}
static int F_44 ( const struct V_61 * V_62 ,
struct V_63 * V_64 )
{
int V_65 , V_66 ;
struct V_41 * V_42 = 0 ;
struct V_24 * V_25 ;
if ( V_64 -> V_67 != 2 ) {
F_45 ( V_68 L_6 ,
V_64 -> V_67 ) ;
return - V_53 ;
}
if ( V_64 -> V_69 [ 0 ] . V_29 != V_70
|| V_64 -> V_69 [ 1 ] . V_29 != V_71 ) {
F_45 ( V_68 L_7 ) ;
return - V_53 ;
}
V_5 = F_46 ( & V_64 -> V_52 , L_8 ) ;
if ( F_47 ( V_5 ) )
return F_48 ( V_5 ) ;
if ( ! F_34 () )
V_4 = F_46 ( & V_64 -> V_52 , L_9 ) ;
else
V_4 = F_46 ( & V_64 -> V_52 , L_10 ) ;
if ( F_47 ( V_4 ) ) {
F_49 ( V_5 ) ;
return F_48 ( V_4 ) ;
}
V_42 = F_50 ( V_62 , & V_64 -> V_52 , F_51 ( & V_64 -> V_52 ) ) ;
if ( ! V_42 ) {
V_65 = - V_72 ;
goto V_73;
}
V_42 -> V_74 = V_64 -> V_69 [ 0 ] . V_75 ;
V_42 -> V_76 = V_64 -> V_69 [ 0 ] . V_77 - V_64 -> V_69 [ 0 ] . V_75 + 1 ;
if ( ! F_52 ( V_42 -> V_74 , V_42 -> V_76 , V_78 ) ) {
F_24 ( & V_64 -> V_52 , L_11 ) ;
V_65 = - V_79 ;
goto V_80;
}
V_42 -> V_36 = F_53 ( V_42 -> V_74 , V_42 -> V_76 ) ;
if ( ! V_42 -> V_36 ) {
F_33 ( & V_64 -> V_52 , L_12 ) ;
V_65 = - V_72 ;
goto V_81;
}
V_25 = F_23 ( V_42 ) ;
F_54 ( V_25 ) ;
V_82 = 0 ;
V_83 = 1 ;
V_66 = F_55 ( V_64 , 0 ) ;
if ( V_66 < 0 ) {
V_65 = - V_84 ;
goto V_85;
}
V_65 = F_56 ( V_42 , V_66 , 0 ) ;
if ( V_65 )
goto V_85;
V_82 = 1 ;
if ( ! V_83 )
F_2 ( 0 ) ;
return 0 ;
V_85:
F_57 ( V_42 -> V_36 ) ;
V_81:
F_58 ( V_42 -> V_74 , V_42 -> V_76 ) ;
V_80:
F_59 ( V_42 ) ;
V_73:
F_49 ( V_4 ) ;
F_49 ( V_5 ) ;
return V_65 ;
}
static inline void
F_60 ( struct V_41 * V_42 , struct V_63 * V_64 )
{
struct V_24 * V_25 = F_23 ( V_42 ) ;
F_61 ( V_42 ) ;
if ( V_25 -> V_31 ) {
( void ) F_31 ( V_25 -> V_31 -> V_32 , 0 ) ;
F_32 ( V_25 -> V_31 -> V_52 ) ;
}
if ( F_11 () )
F_62 ( 9 ) ;
F_57 ( V_42 -> V_36 ) ;
F_58 ( V_42 -> V_74 , V_42 -> V_76 ) ;
F_59 ( V_42 ) ;
F_49 ( V_4 ) ;
F_49 ( V_5 ) ;
}
static int
F_63 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_24 * V_25 = F_23 ( V_42 ) ;
int V_48 ;
if ( ! V_83 )
return 0 ;
V_44 = V_42 -> V_27 . V_45 -> V_46 ;
if ( V_44 -> V_32 || V_44 -> V_86 ) {
V_25 -> V_87 = V_88 ;
F_20 ( V_88 , & V_25 -> V_36 -> V_89 ) ;
}
if ( ( V_48 = F_64 ( V_25 ) ) < 0 ) {
F_33 ( V_42 -> V_27 . V_45 , L_13 ) ;
F_43 ( V_42 ) ;
return V_48 ;
}
return 0 ;
}
static int F_65 ( struct V_63 * V_52 )
{
return F_44 ( & V_90 , V_52 ) ;
}
static int F_66 ( struct V_63 * V_52 )
{
struct V_41 * V_42 = F_67 ( V_52 ) ;
F_60 ( V_42 , V_52 ) ;
F_68 ( V_52 , NULL ) ;
return 0 ;
}
static int F_69 ( struct V_63 * V_52 , T_2 V_91 )
{
struct V_24 * V_25 = F_23 ( F_67 ( V_52 ) ) ;
if ( F_70 ( V_92 , V_25 -> V_93 ) )
F_71 ( 5 ) ;
V_25 -> V_93 = V_92 ;
F_2 ( 0 ) ;
return 0 ;
}
static int F_72 ( struct V_63 * V_52 )
{
struct V_41 * V_42 = F_67 ( V_52 ) ;
struct V_24 * V_25 = F_23 ( V_42 ) ;
if ( F_70 ( V_92 , V_25 -> V_93 ) )
F_71 ( 5 ) ;
V_25 -> V_93 = V_92 ;
F_2 ( 1 ) ;
F_73 ( V_42 ) ;
return 0 ;
}
