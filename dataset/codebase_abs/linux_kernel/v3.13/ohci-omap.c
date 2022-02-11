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
struct V_26 * V_27 = F_17 ( V_25 ) ;
const unsigned V_28 = V_27 -> V_29 . V_30 - 1 ;
unsigned long V_31 ;
T_1 V_32 ;
F_18 ( V_27 -> V_33 -> V_34 ) ;
F_19 ( V_31 ) ;
V_27 -> V_33 -> V_35 = V_36 ;
F_20 ( V_37 , & V_25 -> V_38 -> V_39 . V_40 [ V_28 ] ) ;
V_32 = F_15 ( V_41 ) ;
V_32 &= ~ V_42 ;
F_13 ( V_32 , V_41 ) ;
F_21 ( V_31 ) ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_24 * V_25 = F_23 ( V_27 ) ;
struct V_43 * V_44 = F_24 ( V_27 -> V_29 . V_45 ) ;
int V_46 = ( V_44 -> V_34 != 0 ) ;
int V_47 ;
F_25 ( V_27 -> V_29 . V_45 , L_1 ) ;
if ( V_44 -> V_34 ) {
V_27 -> V_29 . V_30 = V_44 -> V_34 ;
V_27 -> V_48 = 8 ;
}
V_46 = V_46
|| F_26 () || F_27 () ;
if ( V_44 -> V_49 )
V_44 -> V_49 () ;
#ifdef F_28
if ( V_46 ) {
V_27 -> V_33 = F_29 ( V_50 ) ;
if ( ! F_30 ( V_27 -> V_33 ) ) {
int V_51 = F_31 ( V_27 -> V_33 -> V_34 ,
& F_17 ( V_25 ) -> V_29 ) ;
F_25 ( V_27 -> V_29 . V_45 , L_2 ,
V_27 -> V_33 -> V_52 , V_51 ) ;
if ( V_51 ) {
F_32 ( V_27 -> V_33 ) ;
return V_51 ;
}
} else {
F_33 ( V_27 -> V_29 . V_45 , L_3 ) ;
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
V_47 = F_35 ( V_27 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_44 -> V_34 || V_44 -> V_54 ) {
V_25 -> V_55 = V_56 ;
F_20 ( V_56 , & V_25 -> V_38 -> V_57 ) ;
}
if ( F_11 () || F_7 () ) {
T_1 V_58 = F_36 ( V_25 ) ;
V_58 &= ~ V_59 ;
if ( F_11 () ) {
F_17 ( V_25 ) -> V_48 = 250 ;
V_58 &= ~ V_60 ;
F_37 ( V_61 ) ;
F_38 ( 9 , L_4 ) ;
F_39 ( 9 ) ;
F_37 ( V_62 ) ;
}
F_40 ( V_25 , V_58 , & V_25 -> V_38 -> V_39 . V_63 ) ;
V_25 -> V_31 &= ~ V_64 ;
} else if ( F_41 () ) {
F_17 ( V_25 ) -> V_48 = 0 ;
}
F_6 ( 1 ) ;
return 0 ;
}
static int F_42 ( const struct V_65 * V_66 ,
struct V_67 * V_68 )
{
int V_69 , V_70 ;
struct V_26 * V_27 = 0 ;
if ( V_68 -> V_71 != 2 ) {
F_43 ( V_72 L_5 ,
V_68 -> V_71 ) ;
return - V_53 ;
}
if ( V_68 -> V_73 [ 0 ] . V_31 != V_74
|| V_68 -> V_73 [ 1 ] . V_31 != V_75 ) {
F_43 ( V_72 L_6 ) ;
return - V_53 ;
}
V_5 = F_44 ( & V_68 -> V_76 , L_7 ) ;
if ( F_45 ( V_5 ) )
return F_46 ( V_5 ) ;
if ( ! F_34 () )
V_4 = F_44 ( & V_68 -> V_76 , L_8 ) ;
else
V_4 = F_44 ( & V_68 -> V_76 , L_9 ) ;
if ( F_45 ( V_4 ) ) {
F_47 ( V_5 ) ;
return F_46 ( V_4 ) ;
}
V_27 = F_48 ( V_66 , & V_68 -> V_76 , F_49 ( & V_68 -> V_76 ) ) ;
if ( ! V_27 ) {
V_69 = - V_77 ;
goto V_78;
}
V_27 -> V_79 = V_68 -> V_73 [ 0 ] . V_80 ;
V_27 -> V_81 = V_68 -> V_73 [ 0 ] . V_82 - V_68 -> V_73 [ 0 ] . V_80 + 1 ;
if ( ! F_50 ( V_27 -> V_79 , V_27 -> V_81 , V_83 ) ) {
F_25 ( & V_68 -> V_76 , L_10 ) ;
V_69 = - V_84 ;
goto V_85;
}
V_27 -> V_38 = F_51 ( V_27 -> V_79 , V_27 -> V_81 ) ;
if ( ! V_27 -> V_38 ) {
F_33 ( & V_68 -> V_76 , L_11 ) ;
V_69 = - V_77 ;
goto V_86;
}
V_70 = F_52 ( V_68 , 0 ) ;
if ( V_70 < 0 ) {
V_69 = - V_87 ;
goto V_88;
}
V_69 = F_53 ( V_27 , V_70 , 0 ) ;
if ( V_69 )
goto V_88;
return 0 ;
V_88:
F_54 ( V_27 -> V_38 ) ;
V_86:
F_55 ( V_27 -> V_79 , V_27 -> V_81 ) ;
V_85:
F_56 ( V_27 ) ;
V_78:
F_47 ( V_4 ) ;
F_47 ( V_5 ) ;
return V_69 ;
}
static inline void
F_57 ( struct V_26 * V_27 , struct V_67 * V_68 )
{
F_25 ( V_27 -> V_29 . V_45 , L_12 ) ;
F_58 ( V_27 ) ;
F_2 ( 0 ) ;
if ( ! F_30 ( V_27 -> V_33 ) ) {
( void ) F_31 ( V_27 -> V_33 -> V_34 , 0 ) ;
F_32 ( V_27 -> V_33 ) ;
}
if ( F_11 () )
F_59 ( 9 ) ;
F_54 ( V_27 -> V_38 ) ;
F_55 ( V_27 -> V_79 , V_27 -> V_81 ) ;
F_56 ( V_27 ) ;
F_47 ( V_4 ) ;
F_47 ( V_5 ) ;
}
static int F_60 ( struct V_67 * V_76 )
{
return F_42 ( & V_89 , V_76 ) ;
}
static int F_61 ( struct V_67 * V_76 )
{
struct V_26 * V_27 = F_62 ( V_76 ) ;
F_57 ( V_27 , V_76 ) ;
return 0 ;
}
static int F_63 ( struct V_67 * V_68 , T_2 V_90 )
{
struct V_26 * V_27 = F_62 ( V_68 ) ;
struct V_24 * V_25 = F_23 ( V_27 ) ;
bool V_91 = F_64 ( & V_68 -> V_76 ) ;
int V_47 ;
if ( F_65 ( V_92 , V_25 -> V_93 ) )
F_66 ( 5 ) ;
V_25 -> V_93 = V_92 ;
V_47 = F_67 ( V_27 , V_91 ) ;
if ( V_47 )
return V_47 ;
F_2 ( 0 ) ;
return V_47 ;
}
static int F_68 ( struct V_67 * V_76 )
{
struct V_26 * V_27 = F_62 ( V_76 ) ;
struct V_24 * V_25 = F_23 ( V_27 ) ;
if ( F_65 ( V_92 , V_25 -> V_93 ) )
F_66 ( 5 ) ;
V_25 -> V_93 = V_92 ;
F_2 ( 1 ) ;
F_69 ( V_27 , false ) ;
return 0 ;
}
static int T_3 F_70 ( void )
{
if ( F_71 () )
return - V_53 ;
F_72 ( L_13 V_94 L_14 , V_83 ) ;
F_73 ( & V_89 , & V_95 ) ;
return F_74 ( & V_96 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_96 ) ;
}
