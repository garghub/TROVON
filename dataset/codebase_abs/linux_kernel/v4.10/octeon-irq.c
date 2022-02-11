static int F_1 ( int V_1 , int line , int V_2 , int V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
F_3 ( V_1 , V_5 , V_6 ) ;
V_8 -> line = line ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
F_4 ( V_1 , V_8 ) ;
V_11 [ line ] [ V_2 ] = V_1 ;
return 0 ;
}
static void F_5 ( struct V_12 * V_13 , unsigned int V_1 )
{
struct V_14 * V_15 = F_6 ( V_1 ) ;
struct V_7 * V_8 = F_7 ( V_15 ) ;
F_4 ( V_1 , NULL ) ;
F_8 ( V_8 ) ;
}
static int F_9 ( struct V_12 * V_16 ,
int V_1 , int line , int V_2 )
{
return F_10 ( V_16 , V_1 , line << 6 | V_2 ) ;
}
static int F_11 ( int V_17 )
{
#ifdef F_12
return F_13 ( V_17 ) ;
#else
return F_14 () ;
#endif
}
static int F_15 ( int V_18 )
{
#ifdef F_12
return F_16 ( V_18 ) ;
#else
return F_17 () ;
#endif
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
unsigned int V_2 = V_8 -> V_2 ;
F_19 ( 0x100 << V_2 ) ;
if ( V_2 < 2 )
F_20 ( 0x100 << V_2 ) ;
}
static void F_21 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
F_22 ( 0x100 << V_8 -> V_2 ) ;
}
static void F_23 ( void * V_20 )
{
struct V_14 * V_15 = V_20 ;
struct V_19 * V_8 = F_7 ( V_15 ) ;
unsigned int V_21 = 0x100 << V_8 -> V_2 ;
if ( V_8 -> V_22 )
F_22 ( V_21 ) ;
else
F_19 ( V_21 ) ;
}
static void F_24 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
V_8 -> V_22 = false ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
V_8 -> V_22 = true ;
}
static void F_26 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
F_27 ( & V_8 -> V_23 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_19 * V_8 = F_7 ( V_15 ) ;
if ( V_8 -> V_22 != V_8 -> V_24 ) {
F_29 ( F_23 , V_15 , 1 ) ;
V_8 -> V_24 = V_8 -> V_22 ;
}
F_30 ( & V_8 -> V_23 ) ;
}
static void T_2 F_31 ( void )
{
int V_25 ;
int V_1 ;
struct V_19 * V_8 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_8 = & V_27 [ V_25 ] ;
V_8 -> V_24 = false ;
V_8 -> V_22 = false ;
V_8 -> V_2 = V_25 ;
F_32 ( & V_8 -> V_23 ) ;
V_1 = V_28 + V_25 ;
F_4 ( V_1 , V_8 ) ;
F_3 ( V_1 , & V_29 ,
V_30 ) ;
}
}
static int F_33 ( struct V_14 * V_15 )
{
#ifdef F_12
int V_17 ;
struct V_31 * V_21 = F_34 ( V_15 ) ;
int V_32 = F_35 ( V_21 ) ;
struct V_7 * V_8 = F_7 ( V_15 ) ;
if ( V_32 > 1 ) {
V_17 = V_8 -> V_33 ;
for (; ; ) {
V_17 = F_36 ( V_17 , V_21 ) ;
if ( V_17 >= V_34 ) {
V_17 = - 1 ;
continue;
} else if ( F_37 ( V_17 , V_35 ) ) {
break;
}
}
} else if ( V_32 == 1 ) {
V_17 = F_38 ( V_21 ) ;
} else {
V_17 = F_17 () ;
}
V_8 -> V_33 = V_17 ;
return V_17 ;
#else
return F_17 () ;
#endif
}
static void F_39 ( struct V_14 * V_15 )
{
int V_17 = F_33 ( V_15 ) ;
int V_18 = F_11 ( V_17 ) ;
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = & F_40 ( V_39 , V_17 ) ;
V_8 = F_7 ( V_15 ) ;
F_41 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = & F_40 ( V_40 , V_17 ) ;
F_42 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_45 ( V_18 * 2 ) , * V_36 ) ;
} else {
V_36 = & F_40 ( V_41 , V_17 ) ;
F_42 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
}
F_47 ( V_38 , V_37 ) ;
}
static void F_48 ( struct V_14 * V_15 )
{
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = F_49 ( & V_39 ) ;
V_8 = F_7 ( V_15 ) ;
F_41 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = F_49 ( & V_40 ) ;
F_42 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_45 ( F_14 () * 2 ) , * V_36 ) ;
} else {
V_36 = F_49 ( & V_41 ) ;
F_42 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_46 ( F_14 () * 2 + 1 ) , * V_36 ) ;
}
F_47 ( V_38 , V_37 ) ;
}
static void F_50 ( struct V_14 * V_15 )
{
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = F_49 ( & V_39 ) ;
V_8 = F_7 ( V_15 ) ;
F_41 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = F_49 ( & V_40 ) ;
F_51 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_45 ( F_14 () * 2 ) , * V_36 ) ;
} else {
V_36 = F_49 ( & V_41 ) ;
F_51 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
F_44 ( F_46 ( F_14 () * 2 + 1 ) , * V_36 ) ;
}
F_47 ( V_38 , V_37 ) ;
}
static void F_52 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_17 ;
struct V_7 * V_8 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
F_53 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_40 ( V_39 , V_17 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_40 ( V_40 , V_17 ) ;
else
V_36 = & F_40 ( V_41 , V_17 ) ;
F_41 ( V_38 , V_37 ) ;
F_51 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
if ( V_8 -> line == 0 )
F_44 ( F_45 ( V_18 * 2 ) , * V_36 ) ;
else
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_47 ( V_38 , V_37 ) ;
}
}
static void F_54 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_17 ;
struct V_7 * V_8 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
F_53 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_40 ( V_39 , V_17 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_40 ( V_40 , V_17 ) ;
else
V_36 = & F_40 ( V_41 , V_17 ) ;
F_41 ( V_38 , V_37 ) ;
F_42 ( V_8 -> V_2 , V_36 ) ;
F_43 () ;
if ( V_8 -> line == 0 )
F_44 ( F_45 ( V_18 * 2 ) , * V_36 ) ;
else
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_47 ( V_38 , V_37 ) ;
}
}
static void F_55 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_56 ( V_8 -> V_2 , & F_40 ( V_40 , V_17 ) ) ;
F_44 ( F_57 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_56 ( V_8 -> V_2 , & F_40 ( V_41 , V_17 ) ) ;
F_44 ( F_58 ( V_42 ) , V_21 ) ;
}
}
static void F_59 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_44 ( F_60 ( V_42 ) , V_21 ) ;
}
static void F_61 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_44 ( F_62 ( V_42 ) , V_21 ) ;
}
static void F_63 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_44 ( F_64 ( V_42 ) , V_21 ) ;
}
static void F_65 ( struct V_14 * V_15 )
{
int V_17 ;
struct V_7 * V_8 ;
T_4 V_21 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_53 (cpu) {
int V_18 = F_11 ( V_17 ) ;
F_44 ( F_62 ( V_18 ) , V_21 ) ;
}
}
static void F_66 ( struct V_14 * V_15 )
{
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_14 () * 2 ;
F_56 ( V_8 -> V_2 , F_49 ( & V_40 ) ) ;
F_44 ( F_57 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_14 () * 2 + 1 ;
F_56 ( V_8 -> V_2 , F_49 ( & V_41 ) ) ;
F_44 ( F_58 ( V_42 ) , V_21 ) ;
}
}
static void F_67 ( struct V_14 * V_15 )
{
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_14 () * 2 ;
F_68 ( V_8 -> V_2 , F_49 ( & V_40 ) ) ;
F_44 ( F_69 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_14 () * 2 + 1 ;
F_68 ( V_8 -> V_2 , F_49 ( & V_41 ) ) ;
F_44 ( F_70 ( V_42 ) , V_21 ) ;
}
}
static void F_71 ( struct V_14 * V_15 )
{
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_14 () * 2 ;
F_44 ( F_72 ( V_42 ) , V_21 ) ;
} else {
F_44 ( V_43 , V_21 ) ;
}
}
static void F_73 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
F_53 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_68 ( V_8 -> V_2 ,
& F_40 ( V_40 , V_17 ) ) ;
F_44 ( F_69 ( V_42 ) , V_21 ) ;
}
} else {
F_53 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_68 ( V_8 -> V_2 ,
& F_40 ( V_41 , V_17 ) ) ;
F_44 ( F_70 ( V_42 ) , V_21 ) ;
}
}
}
static void F_74 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
F_53 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_56 ( V_8 -> V_2 ,
& F_40 ( V_40 , V_17 ) ) ;
F_44 ( F_57 ( V_42 ) , V_21 ) ;
}
} else {
F_53 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_56 ( V_8 -> V_2 ,
& F_40 ( V_41 , V_17 ) ) ;
F_44 ( F_58 ( V_42 ) , V_21 ) ;
}
}
}
static int F_75 ( struct V_14 * V_15 , unsigned int V_44 )
{
F_76 ( V_15 , V_44 ) ;
if ( V_44 & V_45 )
F_77 ( V_15 , V_46 ) ;
else
F_77 ( V_15 , V_47 ) ;
return V_48 ;
}
static void F_78 ( struct V_14 * V_15 )
{
union V_49 V_50 ;
struct V_7 * V_8 ;
T_5 V_44 = F_79 ( V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_50 . T_4 = 0 ;
V_50 . V_51 . V_52 = 1 ;
V_50 . V_51 . V_53 = ( V_44 & V_45 ) != 0 ;
V_50 . V_51 . V_54 = ( V_44 & ( V_55 | V_56 ) ) != 0 ;
V_50 . V_51 . V_57 = 7 ;
V_50 . V_51 . V_58 = 3 ;
F_44 ( F_80 ( V_8 -> V_3 ) , V_50 . T_4 ) ;
}
static void F_81 ( struct V_14 * V_15 )
{
F_78 ( V_15 ) ;
F_55 ( V_15 ) ;
}
static void F_82 ( struct V_14 * V_15 )
{
F_78 ( V_15 ) ;
F_39 ( V_15 ) ;
}
static int F_83 ( struct V_14 * V_15 , unsigned int V_44 )
{
F_76 ( V_15 , V_44 ) ;
F_78 ( V_15 ) ;
if ( V_44 & V_45 )
F_77 ( V_15 , V_46 ) ;
else
F_77 ( V_15 , V_47 ) ;
return V_48 ;
}
static void F_84 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_80 ( V_8 -> V_3 ) , 0 ) ;
F_73 ( V_15 ) ;
}
static void F_85 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_80 ( V_8 -> V_3 ) , 0 ) ;
F_52 ( V_15 ) ;
}
static void F_86 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
T_4 V_21 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_3 ) ;
F_44 ( V_59 , V_21 ) ;
}
static void F_87 ( struct V_14 * V_15 )
{
int V_17 = F_17 () ;
T_6 V_60 ;
struct V_31 * V_21 = F_34 ( V_15 ) ;
if ( ! F_37 ( V_17 , V_21 ) )
return;
if ( F_35 ( V_21 ) > 1 ) {
F_88 ( & V_60 , V_21 ) ;
F_89 ( V_17 , & V_60 ) ;
} else {
F_90 ( & V_60 ) ;
F_91 ( F_38 ( V_35 ) , & V_60 ) ;
}
F_92 ( V_15 , & V_60 , false ) ;
}
static int F_93 ( struct V_14 * V_15 ,
const struct V_31 * V_61 , bool V_62 )
{
int V_17 ;
bool V_63 = ! F_94 ( V_15 ) && ! F_95 ( V_15 ) ;
unsigned long V_37 ;
struct V_7 * V_8 ;
unsigned long * V_36 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
if ( F_35 ( V_61 ) != 1 )
return - V_64 ;
if ( ! V_63 )
return 0 ;
F_53 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_40 ( V_39 , V_17 ) ;
F_41 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_40 ( V_40 , V_17 ) ;
else
V_36 = & F_40 ( V_41 , V_17 ) ;
if ( F_37 ( V_17 , V_61 ) && V_63 ) {
V_63 = 0 ;
F_42 ( V_8 -> V_2 , V_36 ) ;
} else {
F_51 ( V_8 -> V_2 , V_36 ) ;
}
F_43 () ;
if ( V_8 -> line == 0 )
F_44 ( F_45 ( V_18 * 2 ) , * V_36 ) ;
else
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_47 ( V_38 , V_37 ) ;
}
return 0 ;
}
static int F_96 ( struct V_14 * V_15 ,
const struct V_31 * V_61 ,
bool V_62 )
{
int V_17 ;
bool V_63 = ! F_94 ( V_15 ) && ! F_95 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_63 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
if ( V_8 -> line == 0 ) {
F_53 (cpu) {
unsigned long * V_36 = & F_40 ( V_40 , V_17 ) ;
int V_42 = F_11 ( V_17 ) * 2 ;
if ( F_37 ( V_17 , V_61 ) && V_63 ) {
V_63 = false ;
F_56 ( V_8 -> V_2 , V_36 ) ;
F_44 ( F_57 ( V_42 ) , V_21 ) ;
} else {
F_68 ( V_8 -> V_2 , V_36 ) ;
F_44 ( F_69 ( V_42 ) , V_21 ) ;
}
}
} else {
F_53 (cpu) {
unsigned long * V_36 = & F_40 ( V_41 , V_17 ) ;
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
if ( F_37 ( V_17 , V_61 ) && V_63 ) {
V_63 = false ;
F_56 ( V_8 -> V_2 , V_36 ) ;
F_44 ( F_58 ( V_42 ) , V_21 ) ;
} else {
F_68 ( V_8 -> V_2 , V_36 ) ;
F_44 ( F_70 ( V_42 ) , V_21 ) ;
}
}
}
return 0 ;
}
static int F_97 ( struct V_14 * V_15 ,
const struct V_31 * V_61 ,
bool V_62 )
{
int V_17 ;
bool V_63 = ! F_94 ( V_15 ) && ! F_95 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_63 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
F_53 (cpu) {
int V_42 = F_11 ( V_17 ) ;
if ( F_37 ( V_17 , V_61 ) && V_63 ) {
V_63 = false ;
F_44 ( F_60 ( V_42 ) , V_21 ) ;
} else {
F_44 ( F_62 ( V_42 ) , V_21 ) ;
}
}
return 0 ;
}
static unsigned int F_98 ( struct V_14 * V_15 )
{
V_15 -> V_5 -> V_65 ( V_15 ) ;
V_15 -> V_5 -> V_66 ( V_15 ) ;
return 0 ;
}
static void F_99 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_18 = V_15 -> V_1 - V_67 ;
int V_17 = F_15 ( V_18 ) ;
T_3 * V_38 = & F_40 ( V_39 , V_17 ) ;
F_41 ( V_38 , V_37 ) ;
V_36 = & F_40 ( V_41 , V_17 ) ;
F_42 ( V_18 , V_36 ) ;
F_43 () ;
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_47 ( V_38 , V_37 ) ;
}
static void F_100 ( struct V_14 * V_15 )
{
int V_18 = V_15 -> V_1 - V_67 ;
int V_17 = F_15 ( V_18 ) ;
F_56 ( V_18 , & F_40 ( V_41 , V_17 ) ) ;
F_44 ( F_58 ( V_18 * 2 + 1 ) , 1ull << V_18 ) ;
}
static bool F_101 ( unsigned int line , unsigned int V_2 )
{
bool V_68 = false ;
if ( line == 0 )
switch ( V_2 ) {
case 48 ... 49 :
case 50 :
case 52 ... 55 :
case 58 :
V_68 = true ;
break;
default:
break;
}
else
switch ( V_2 ) {
case 47 :
V_68 = true ;
break;
default:
break;
}
return V_68 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_69 * V_70 ,
const T_5 * V_71 ,
unsigned int V_72 ,
unsigned long * V_73 ,
unsigned int * V_74 )
{
unsigned int type ;
unsigned int V_75 ;
unsigned int V_76 ;
if ( F_103 ( V_13 ) != V_70 )
return - V_64 ;
if ( V_72 < 2 )
return - V_64 ;
V_75 = V_71 [ 0 ] ;
if ( V_75 >= 16 )
return - V_64 ;
V_76 = V_71 [ 1 ] ;
switch ( V_76 ) {
case 1 :
type = V_77 ;
break;
case 2 :
type = V_56 ;
break;
case 4 :
type = V_78 ;
break;
case 8 :
type = V_55 ;
break;
default:
F_104 ( L_1 ,
V_70 -> V_79 ,
V_76 ) ;
type = V_55 ;
break;
}
* V_74 = type ;
* V_73 = V_75 ;
return 0 ;
}
static int F_105 ( struct V_12 * V_13 ,
struct V_69 * V_70 ,
const T_5 * V_71 ,
unsigned int V_72 ,
unsigned long * V_73 ,
unsigned int * V_74 )
{
unsigned int V_80 , V_2 ;
struct V_81 * V_82 = V_13 -> V_83 ;
V_80 = V_71 [ 0 ] ;
V_2 = V_71 [ 1 ] ;
if ( V_80 >= V_82 -> V_84 || V_2 > 63 )
return - V_64 ;
* V_73 = ( V_80 << 6 ) | V_2 ;
* V_74 = 0 ;
return 0 ;
}
static int F_106 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
int V_87 ;
unsigned int line = V_86 >> 6 ;
unsigned int V_2 = V_86 & 63 ;
struct V_81 * V_82 = V_13 -> V_83 ;
if ( line >= V_82 -> V_84 || V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
if ( line == 2 ) {
if ( F_101 ( line , V_2 ) )
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
& V_88 ,
V_46 ) ;
else
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
& V_89 ,
V_47 ) ;
} else {
if ( F_101 ( line , V_2 ) )
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
V_90 ,
V_46 ) ;
else
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
V_91 ,
V_47 ) ;
}
return V_87 ;
}
static int F_107 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
struct V_92 * V_93 = V_13 -> V_83 ;
unsigned int line , V_2 ;
int V_94 ;
line = ( V_86 + V_93 -> V_95 ) >> 6 ;
V_2 = ( V_86 + V_93 -> V_95 ) & 63 ;
if ( line >= F_108 ( V_11 ) ||
V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
V_94 = F_1 ( V_85 , line , V_2 , V_86 ,
V_96 , V_47 ) ;
return V_94 ;
}
static void F_109 ( void )
{
const unsigned long V_97 = F_14 () ;
T_4 V_98 = F_110 ( F_72 ( V_97 * 2 ) ) ;
V_98 &= F_111 ( V_40 ) ;
if ( F_112 ( V_98 ) ) {
int V_2 = F_113 ( V_98 ) - 1 ;
int V_1 = V_11 [ 0 ] [ V_2 ] ;
if ( F_112 ( V_1 ) )
F_114 ( V_1 ) ;
else
F_115 () ;
} else {
F_115 () ;
}
}
static void F_116 ( void )
{
T_4 V_98 = F_110 ( V_43 ) ;
V_98 &= F_111 ( V_41 ) ;
if ( F_112 ( V_98 ) ) {
int V_2 = F_113 ( V_98 ) - 1 ;
int V_1 = V_11 [ 1 ] [ V_2 ] ;
if ( F_112 ( V_1 ) )
F_114 ( V_1 ) ;
else
F_115 () ;
} else {
F_115 () ;
}
}
static void F_117 ( void )
{
int V_18 = F_14 () ;
T_4 V_98 = F_110 ( F_64 ( V_18 ) ) ;
T_4 V_99 = F_110 ( F_118 ( V_18 ) ) ;
V_98 &= V_99 ;
if ( F_112 ( V_98 ) ) {
int V_2 = F_113 ( V_98 ) - 1 ;
int V_1 = V_11 [ 2 ] [ V_2 ] ;
if ( F_112 ( V_1 ) )
F_114 ( V_1 ) ;
else
F_115 () ;
} else {
F_115 () ;
}
}
static void F_119 ( void * V_20 )
{
F_22 ( V_100 ) ;
}
static void F_120 ( void )
{
F_19 ( V_100 ) ;
F_115 () ;
}
void F_121 ( T_8 V_101 )
{
V_102 = V_101 ;
V_103 = true ;
F_29 ( F_119 , NULL , 1 ) ;
}
static void F_122 ( void )
{
F_123 () ;
}
static void F_124 ( void )
{
int V_18 = F_14 () ;
F_125 ( V_40 , 0 ) ;
F_125 ( V_41 , 0 ) ;
F_43 () ;
F_126 ( F_49 ( & V_39 ) ) ;
F_44 ( F_45 ( ( V_18 * 2 ) ) , 0 ) ;
F_44 ( F_45 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_44 ( F_46 ( ( V_18 * 2 ) ) , 0 ) ;
F_44 ( F_46 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_110 ( F_72 ( ( V_18 * 2 ) ) ) ;
}
static void F_127 ( void )
{
T_4 V_104 , V_105 ;
int V_18 = F_14 () ;
T_4 V_106 = F_128 ( V_18 ) ;
for ( V_104 = 0 ; V_104 <= 0x8000 ; V_104 += 0x1000 ) {
for ( V_105 = 0 ; V_105 <= 0x400 ; V_105 += 0x200 )
F_44 ( V_106 + V_104 + V_105 , 0 ) ;
}
F_110 ( F_129 ( V_18 ) ) ;
}
static void F_130 ( void )
{
F_124 () ;
F_122 () ;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
}
static void F_131 ( void )
{
F_127 () ;
F_122 () ;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
}
static int T_2 F_132 (
struct V_69 * V_109 , struct V_69 * V_110 )
{
unsigned int V_25 , V_94 ;
struct V_4 * V_5 ;
struct V_4 * V_111 ;
struct V_4 * V_112 ;
struct V_4 * V_113 ;
struct V_12 * V_114 = NULL ;
struct V_81 * V_82 ;
V_82 = F_2 ( sizeof( * V_82 ) , V_9 ) ;
if ( ! V_82 )
return - V_10 ;
F_124 () ;
V_115 = F_130 ;
V_116 = F_109 ;
V_117 = F_116 ;
if ( ( F_133 () || F_134 () )
&& ! F_135 ( V_118 ) ) {
V_102 = F_117 ;
V_82 -> V_84 = 3 ;
V_103 = true ;
} else {
V_102 = F_120 ;
V_82 -> V_84 = 2 ;
V_103 = false ;
}
if ( F_135 ( V_119 ) ||
F_135 ( V_120 ) ||
F_135 ( V_121 ) ||
F_133 () || F_134 () ) {
V_5 = & V_122 ;
V_111 = & V_123 ;
V_112 = & V_124 ;
V_113 = & V_125 ;
V_96 = & V_126 ;
} else {
V_5 = & V_127 ;
V_111 = & V_128 ;
V_112 = & V_129 ;
V_113 = & V_130 ;
V_96 = & V_131 ;
}
V_91 = V_5 ;
V_90 = V_111 ;
F_31 () ;
V_114 = F_136 (
V_109 , & V_132 , V_82 ) ;
F_137 ( V_114 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_133 , 0 , V_25 + 0 ) ;
if ( V_94 )
goto V_134;
}
V_94 = F_1 (
V_135 , 0 , 32 , 0 , V_112 , V_30 ) ;
if ( V_94 )
goto V_134;
V_94 = F_1 (
V_136 , 0 , 33 , 0 , V_112 , V_30 ) ;
if ( V_94 )
goto V_134;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_137 , 0 , V_25 + 36 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_138 , 0 , V_25 + 40 ) ;
if ( V_94 )
goto V_134;
}
V_94 = F_9 ( V_114 , V_139 , 0 , 45 ) ;
if ( V_94 )
goto V_134;
V_94 = F_9 ( V_114 , V_140 , 0 , 46 ) ;
if ( V_94 )
goto V_134;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_141 , 0 , V_25 + 52 ) ;
if ( V_94 )
goto V_134;
}
V_94 = F_9 ( V_114 , V_142 , 0 , 59 ) ;
if ( V_94 )
goto V_134;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_94 = F_1 (
V_25 + V_67 , 1 , V_25 + 0 , 0 , V_113 ,
V_47 ) ;
if ( V_94 )
goto V_134;
}
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
return 0 ;
V_134:
return V_94 ;
}
static int T_2 F_138 (
struct V_69 * V_143 , struct V_69 * V_110 )
{
struct V_92 * V_93 ;
T_5 V_144 ;
unsigned int V_95 ;
int V_94 ;
V_94 = F_139 ( V_110 , L_2 , & V_144 ) ;
if ( V_94 )
return V_94 ;
if ( V_144 == 1 ) {
T_5 V_145 ;
V_94 = F_140 ( V_143 , L_3 , 0 , & V_145 ) ;
if ( V_94 ) {
F_141 ( L_4 ) ;
return V_94 ;
}
V_95 = V_145 ;
} else if ( V_144 == 2 ) {
T_5 V_146 , V_147 ;
V_94 = F_140 ( V_143 , L_3 , 0 , & V_146 ) ;
if ( V_94 ) {
F_141 ( L_4 ) ;
return V_94 ;
}
V_94 = F_140 ( V_143 , L_3 , 1 , & V_147 ) ;
if ( V_94 ) {
F_141 ( L_4 ) ;
return V_94 ;
}
V_95 = ( V_146 << 6 ) | V_147 ;
} else {
F_141 ( L_5 ,
V_144 ) ;
return - V_64 ;
}
V_93 = F_2 ( sizeof( * V_93 ) , V_9 ) ;
if ( V_93 ) {
V_93 -> V_95 = V_95 ;
F_142 (
V_143 , 16 , & V_148 , V_93 ) ;
} else {
F_141 ( L_6 ) ;
return - V_10 ;
}
F_143 ( V_143 , V_149 ) ;
return 0 ;
}
static void F_144 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = V_15 -> V_1 - V_67 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_146 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_17 = F_33 ( V_15 ) ;
int V_18 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_147 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_148 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_149 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_150 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_151 ( V_18 ) + ( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_152 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_53 (cpu) {
T_4 V_150 = F_149 (
F_11 ( V_17 ) ) + ( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_153 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
F_53 (cpu) {
T_4 V_150 = F_154 (
F_11 ( V_17 ) ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_155 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
F_53 (cpu) {
T_4 V_150 = F_156 (
F_11 ( V_17 ) ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_157 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
V_150 = F_154 ( V_18 ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_158 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
V_150 = F_156 ( V_18 ) ;
F_44 ( V_150 , V_21 ) ;
}
static int F_159 ( struct V_14 * V_15 ,
const struct V_31 * V_61 , bool V_62 )
{
int V_17 ;
bool V_63 = ! F_94 ( V_15 ) && ! F_95 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_63 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
F_53 (cpu) {
T_4 V_150 ;
if ( F_37 ( V_17 , V_61 ) && V_63 ) {
V_63 = false ;
V_150 = F_145 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
} else {
V_150 = F_149 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
}
F_44 ( V_150 , V_21 ) ;
}
return 0 ;
}
static void F_160 ( struct V_14 * V_15 )
{
F_78 ( V_15 ) ;
F_146 ( V_15 ) ;
}
static void F_161 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_80 ( V_8 -> V_3 ) , 0 ) ;
F_152 ( V_15 ) ;
}
static int F_162 ( struct V_12 * V_13 ,
struct V_69 * V_70 ,
const T_5 * V_71 ,
unsigned int V_72 ,
unsigned long * V_73 ,
unsigned int * V_74 )
{
unsigned int V_80 , V_2 ;
V_80 = V_71 [ 0 ] ;
V_2 = V_71 [ 1 ] ;
* V_73 = ( V_80 << 6 ) | V_2 ;
* V_74 = 0 ;
return 0 ;
}
static bool F_163 ( unsigned int line , unsigned int V_2 )
{
bool V_68 = false ;
if ( line == 3 )
switch ( V_2 ) {
case 2 :
case 8 ... 11 :
case 48 :
V_68 = true ;
break;
default:
break;
}
else if ( line == 6 )
switch ( V_2 ) {
case 52 ... 53 :
case 8 ... 12 :
V_68 = true ;
break;
default:
break;
}
return V_68 ;
}
static int F_164 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
unsigned int line = V_86 >> 6 ;
unsigned int V_2 = V_86 & 63 ;
if ( line == 7 )
return 0 ;
if ( line > 7 || V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
if ( F_163 ( line , V_2 ) )
F_1 ( V_85 , line , V_2 , 0 ,
& V_151 ,
V_46 ) ;
else
F_1 ( V_85 , line , V_2 , 0 ,
& V_152 ,
V_47 ) ;
return 0 ;
}
static void F_165 ( void )
{
int line ;
int V_2 ;
int V_1 ;
T_4 V_153 , V_154 , V_155 ;
const unsigned long V_97 = F_14 () ;
V_155 = F_110 ( F_129 ( V_97 ) ) & 0xfful ;
if ( F_166 ( ! V_155 ) )
goto V_156;
line = F_113 ( V_155 ) - 1 ;
V_153 = F_167 ( V_97 ) + ( 0x1000 * line ) ;
V_154 = F_110 ( V_153 ) ;
if ( F_166 ( ! V_154 ) )
goto V_156;
V_2 = F_113 ( V_154 ) - 1 ;
V_1 = V_11 [ line ] [ V_2 ] ;
if ( F_166 ( ! V_1 ) )
goto V_156;
F_114 ( V_1 ) ;
goto V_157;
V_156:
F_115 () ;
V_157:
if ( F_135 ( V_158 ) )
F_110 ( V_159 ) ;
else
F_110 ( F_168 ( V_97 ) ) ;
return;
}
static void F_169 ( void )
{
int line ;
const unsigned long V_97 = F_14 () ;
T_4 V_155 = F_110 ( F_170 ( V_97 ) ) >> 60 ;
if ( F_166 ( ! V_155 ) )
goto V_156;
line = F_113 ( V_155 ) - 1 ;
F_114 ( V_135 + line ) ;
goto V_157;
V_156:
F_115 () ;
V_157:
if ( F_135 ( V_158 ) )
F_110 ( V_159 ) ;
else
F_110 ( F_171 ( V_97 ) ) ;
return;
}
static int T_2 F_172 (
struct V_69 * V_109 , struct V_69 * V_110 )
{
unsigned int V_25 , V_94 ;
struct V_12 * V_114 = NULL ;
F_127 () ;
V_115 = F_131 ;
V_96 = & V_160 ;
V_116 = F_165 ;
V_117 = F_169 ;
V_102 = F_120 ;
F_31 () ;
V_114 = F_136 (
V_109 , & V_161 , NULL ) ;
F_137 ( V_114 ) ;
for ( V_25 = 0 ; V_25 < 64 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_133 , 0 , V_25 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 32 ; V_25 ++ ) {
V_94 = F_1 ( V_25 + V_67 , 1 , V_25 , 0 ,
& V_162 , V_47 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_141 , 3 , V_25 + 8 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_137 , 4 , V_25 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_138 , 4 , V_25 + 8 ) ;
if ( V_94 )
goto V_134;
}
F_3 ( V_135 , & V_163 , V_30 ) ;
F_3 ( V_136 , & V_163 , V_30 ) ;
F_3 ( V_164 , & V_163 , V_30 ) ;
F_3 ( V_165 , & V_163 , V_30 ) ;
F_22 ( V_107 | V_108 ) ;
F_19 ( V_100 ) ;
return 0 ;
V_134:
return V_94 ;
}
static void F_173 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_166 ;
struct V_167 * V_8 = F_7 ( V_15 ) ;
struct V_168 * V_83 = V_8 -> V_83 ;
F_41 ( & V_83 -> V_38 , V_37 ) ;
V_166 = F_110 ( V_83 -> V_169 ) ;
V_166 |= 1ull << V_8 -> V_2 ;
F_44 ( V_83 -> V_169 , V_166 ) ;
F_47 ( & V_83 -> V_38 , V_37 ) ;
}
static void F_174 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_166 ;
struct V_167 * V_8 = F_7 ( V_15 ) ;
struct V_168 * V_83 = V_8 -> V_83 ;
F_41 ( & V_83 -> V_38 , V_37 ) ;
V_166 = F_110 ( V_83 -> V_169 ) ;
V_166 &= ~ ( 1ull << V_8 -> V_2 ) ;
F_44 ( V_83 -> V_169 , V_166 ) ;
F_47 ( & V_83 -> V_38 , V_37 ) ;
}
static int F_175 ( struct V_14 * V_15 , unsigned int V_44 )
{
F_76 ( V_15 , V_44 ) ;
return V_48 ;
}
static int F_176 ( struct V_12 * V_13 ,
struct V_69 * V_70 ,
const T_5 * V_71 ,
unsigned int V_72 ,
unsigned long * V_73 ,
unsigned int * V_74 )
{
unsigned int type = 0 ;
if ( V_72 == 2 )
type = V_71 [ 1 ] ;
switch ( type ) {
case 0 :
case 4 :
* V_74 = V_78 ;
break;
case 1 :
* V_74 = V_77 ;
break;
default:
return - V_64 ;
}
* V_73 = V_71 [ 0 ] ;
return 0 ;
}
static int F_177 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
struct V_168 * V_83 = V_13 -> V_83 ;
struct V_167 * V_8 ;
if ( V_86 >= V_83 -> V_170 ) {
F_104 ( L_7 ,
F_103 ( V_13 ) -> V_79 , ( unsigned ) V_86 ) ;
return - V_64 ;
}
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
V_8 -> V_83 = V_83 ;
V_8 -> V_2 = V_86 ;
F_3 ( V_85 , & V_171 ,
V_172 ) ;
F_4 ( V_85 , V_8 ) ;
return 0 ;
}
static T_9 F_178 ( int V_173 , void * V_15 )
{
T_4 V_166 ;
T_4 V_174 ;
T_4 V_175 ;
int V_25 ;
int V_1 ;
struct V_12 * V_176 = V_15 ;
struct V_168 * V_83 = V_176 -> V_83 ;
V_166 = F_110 ( V_83 -> V_169 ) ;
V_174 = F_110 ( V_83 -> V_177 ) ;
V_175 = V_166 & V_174 ;
for ( V_25 = 0 ; V_25 < V_83 -> V_170 ; V_25 ++ ) {
if ( ( V_175 & 1ull << V_25 ) == 0 )
continue;
V_1 = F_179 ( V_176 , V_25 ) ;
if ( ! V_1 ) {
unsigned long V_37 ;
F_104 ( L_8 ,
V_25 , V_83 -> V_177 ) ;
F_41 ( & V_83 -> V_38 , V_37 ) ;
V_166 = F_110 ( V_83 -> V_169 ) ;
V_166 &= ~ ( 1ull << V_25 ) ;
F_44 ( V_83 -> V_169 , V_166 ) ;
F_44 ( V_83 -> V_177 , 1ull << V_25 ) ;
F_47 ( & V_83 -> V_38 , V_37 ) ;
} else {
struct V_178 * V_179 = F_180 ( V_1 ) ;
struct V_14 * V_14 = F_181 ( V_179 ) ;
if ( F_79 ( V_14 ) &
V_45 )
F_44 ( V_83 -> V_177 , 1ull << V_25 ) ;
F_182 ( V_179 ) ;
}
}
return V_180 ;
}
static int T_2 F_183 ( struct V_69 * V_109 ,
struct V_69 * V_110 )
{
const T_10 * V_181 ;
T_5 V_182 ;
struct V_168 * V_83 ;
int V_183 ;
int V_94 ;
struct V_12 * V_176 ;
V_183 = F_184 ( V_109 , 0 ) ;
if ( ! V_183 ) {
F_104 ( L_9 ,
V_109 -> V_79 ) ;
return - V_64 ;
}
V_83 = F_2 ( sizeof( * V_83 ) , V_9 ) ;
F_126 ( & V_83 -> V_38 ) ;
V_181 = F_185 ( V_109 , 0 , NULL , NULL ) ;
if ( ! V_181 ) {
F_104 ( L_10 , V_109 -> V_79 ) ;
return - V_64 ;
}
V_83 -> V_177 = ( T_4 ) F_186 (
F_187 ( V_109 , V_181 ) ) ;
V_181 = F_185 ( V_109 , 1 , NULL , NULL ) ;
if ( ! V_181 ) {
F_104 ( L_11 , V_109 -> V_79 ) ;
return - V_64 ;
}
V_83 -> V_169 = ( T_4 ) F_186 (
F_187 ( V_109 , V_181 ) ) ;
V_94 = F_139 ( V_109 , L_12 , & V_182 ) ;
if ( V_94 ) {
F_104 ( L_13 ,
V_109 -> V_79 ) ;
return V_94 ;
}
V_83 -> V_170 = V_182 ;
V_176 = F_142 ( V_109 , V_83 -> V_170 ,
& V_184 ,
V_83 ) ;
if ( ! V_176 ) {
F_104 ( L_14 ) ;
return - V_10 ;
}
F_44 ( V_83 -> V_169 , 0 ) ;
F_44 ( V_83 -> V_177 , ~ 0 ) ;
V_94 = F_188 ( V_183 , F_178 ,
V_185 , L_15 , V_176 ) ;
if ( V_94 ) {
F_104 ( L_16 , V_94 ) ;
return V_94 ;
}
F_189 ( L_17 ,
V_83 -> V_177 , V_83 -> V_170 ) ;
return 0 ;
}
int F_190 ( struct V_12 * V_13 ,
struct V_69 * V_70 ,
const T_5 * V_71 ,
unsigned int V_72 ,
unsigned long * V_73 ,
unsigned int * V_74 )
{
struct V_186 * V_187 = V_13 -> V_83 ;
unsigned int V_188 , type , V_189 ;
union V_190 V_191 ;
if ( V_72 < 2 )
return - V_64 ;
V_188 = V_71 [ 0 ] ;
type = V_71 [ 1 ] ;
if ( V_188 >= ( 1 << 20 ) )
return - V_64 ;
V_189 = V_188 >> 12 ;
switch ( V_189 ) {
case 0x04 :
return - V_64 ;
default:
break;
}
V_191 . T_4 = F_110 ( V_187 -> V_192 + F_191 ( V_188 ) ) ;
if ( ! V_191 . V_51 . V_193 )
return - V_64 ;
switch ( type ) {
case 4 :
* V_74 = V_78 ;
break;
case 0 :
case 1 :
* V_74 = V_77 ;
break;
default:
return - V_64 ;
}
* V_73 = V_188 ;
return 0 ;
}
void F_192 ( struct V_14 * V_15 )
{
int V_17 ;
union V_190 V_194 ;
union V_195 V_196 ;
T_4 V_197 ;
struct V_7 * V_8 ;
V_17 = F_33 ( V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
F_44 ( V_8 -> V_192 + F_193 ( V_8 -> V_198 ) , V_196 . T_4 ) ;
V_197 = V_8 -> V_192 + F_191 ( V_8 -> V_198 ) ;
V_194 . T_4 = 0 ;
V_194 . V_51 . V_166 = 1 ;
V_194 . V_51 . V_199 = F_40 ( V_200 , V_17 ) ;
F_44 ( V_197 , V_194 . T_4 ) ;
F_110 ( V_197 ) ;
}
void F_194 ( struct V_14 * V_15 )
{
T_4 V_197 ;
union V_195 V_196 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
V_197 = V_8 -> V_192 + F_191 ( V_8 -> V_198 ) ;
F_44 ( V_8 -> V_192 + F_193 ( V_8 -> V_198 ) , V_196 . T_4 ) ;
F_44 ( V_197 , 0 ) ;
F_110 ( V_197 ) ;
}
void F_195 ( struct V_14 * V_15 )
{
T_4 V_201 ;
union V_195 V_196 ;
struct V_7 * V_8 ;
T_5 V_202 = F_79 ( V_15 ) ;
if ( ! ( V_202 & V_45 ) )
return;
V_8 = F_7 ( V_15 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_174 = 1 ;
V_201 = V_8 -> V_192 + F_193 ( V_8 -> V_198 ) ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
}
void F_196 ( struct V_14 * V_15 )
{
union V_195 V_196 ;
T_4 V_201 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
V_201 = V_8 -> V_192 + F_193 ( V_8 -> V_198 ) ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
}
void F_197 ( struct V_14 * V_15 )
{
union V_195 V_196 ;
T_4 V_201 ;
struct V_7 * V_8 ;
T_5 V_202 = F_79 ( V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
if ( V_202 & V_45 )
V_196 . V_51 . V_174 = 1 ;
V_201 = V_8 -> V_192 + F_193 ( V_8 -> V_198 ) ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
}
int F_198 ( struct V_14 * V_15 ,
const struct V_31 * V_61 , bool V_62 )
{
union V_190 V_194 ;
union V_195 V_196 ;
T_4 V_197 ;
int V_17 ;
bool V_63 = ! F_94 ( V_15 ) && ! F_95 ( V_15 ) ;
struct V_7 * V_8 = F_7 ( V_15 ) ;
if ( ! F_199 ( V_61 , F_200 ( V_8 -> V_109 ) ) )
return - V_64 ;
if ( ! V_63 )
return V_48 ;
V_8 = F_7 ( V_15 ) ;
V_17 = F_38 ( V_61 ) ;
if ( V_17 >= V_34 )
V_17 = F_17 () ;
V_8 -> V_33 = V_17 ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
F_44 ( V_8 -> V_192 + F_193 ( V_8 -> V_198 ) , V_196 . T_4 ) ;
V_197 = V_8 -> V_192 + F_191 ( V_8 -> V_198 ) ;
V_194 . T_4 = 0 ;
V_194 . V_51 . V_166 = 1 ;
V_194 . V_51 . V_199 = F_40 ( V_200 , V_17 ) ;
F_44 ( V_197 , V_194 . T_4 ) ;
F_110 ( V_197 ) ;
return V_48 ;
}
int F_201 ( struct V_12 * V_13 , unsigned int V_85 ,
T_7 V_86 , struct V_4 * V_5 )
{
struct V_186 * V_187 = V_13 -> V_83 ;
struct V_7 * V_8 = F_202 ( sizeof( * V_8 ) , V_9 ,
V_187 -> V_70 ) ;
if ( ! V_8 )
return - V_10 ;
V_8 -> V_198 = V_86 ;
V_8 -> V_33 = - 1 ;
V_8 -> V_192 = V_187 -> V_192 ;
V_8 -> V_109 = V_187 -> V_70 ;
F_3 ( V_85 , V_5 , V_46 ) ;
F_4 ( V_85 , V_8 ) ;
return 0 ;
}
static int F_203 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
return F_201 ( V_13 , V_85 , V_86 , & V_203 ) ;
}
static void F_204 ( void )
{
union V_204 V_205 ;
struct V_186 * V_187 ;
T_4 V_192 ;
V_187 = F_111 ( V_186 ) ;
V_192 = V_187 -> V_192 ;
V_205 . T_4 = F_110 ( V_192 + F_205 ( 3 * F_206 () ) ) ;
if ( F_112 ( V_205 . V_51 . V_206 ) ) {
T_7 V_198 = V_205 . V_51 . V_198 ;
T_7 V_86 ;
struct V_12 * V_16 ;
int V_207 = V_198 >> 12 ;
int V_208 ;
V_16 = V_187 -> V_16 [ V_207 ] ;
if ( V_187 -> V_209 [ V_207 ] )
V_86 = V_187 -> V_209 [ V_207 ] ( V_16 , V_198 ) ;
else
V_86 = V_198 ;
V_208 = F_207 ( V_16 , V_86 , NULL ) ;
if ( V_208 < 0 ) {
union V_195 V_196 ;
T_4 V_201 = V_192 + F_193 ( V_198 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
F_115 () ;
}
} else {
F_115 () ;
}
}
static unsigned int F_208 ( int V_210 )
{
return 0x04000 + V_211 * V_210 ;
}
static unsigned int F_209 ( int V_210 , unsigned int V_212 )
{
return F_208 ( V_210 ) + V_212 ;
}
static unsigned int F_210 ( int V_17 , unsigned int V_212 )
{
int V_213 = F_11 ( V_17 ) & 0x3f ;
return F_209 ( V_213 , V_212 ) ;
}
static void F_211 ( void )
{
union V_204 V_205 ;
struct V_186 * V_187 ;
T_4 V_192 ;
int V_210 = F_206 () ;
V_187 = F_111 ( V_186 ) ;
V_192 = V_187 -> V_192 ;
V_205 . T_4 = F_110 ( V_192 + F_205 ( 1 + 3 * V_210 ) ) ;
if ( F_112 ( V_205 . V_51 . V_206 ) ) {
T_7 V_198 = V_205 . V_51 . V_198 ;
int V_212 = V_198 - F_208 ( V_210 ) ;
if ( F_112 ( V_212 >= 0 && V_212 < V_211 ) ) {
F_114 ( V_212 + V_135 ) ;
} else {
union V_195 V_196 ;
T_4 V_201 = V_192 + F_193 ( V_198 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_166 = 1 ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
F_115 () ;
}
} else {
F_115 () ;
}
}
void F_212 ( int V_17 , unsigned int V_212 )
{
struct V_186 * V_187 ;
unsigned int V_198 ;
union V_214 V_215 ;
T_4 V_216 ;
if ( F_213 ( V_212 >= V_211 ) )
return;
V_198 = F_210 ( V_17 , V_212 ) ;
V_187 = F_40 ( V_186 , V_17 ) ;
V_216 = V_187 -> V_192 + F_214 ( V_198 ) ;
V_215 . T_4 = 0 ;
V_215 . V_51 . V_174 = 1 ;
F_44 ( V_216 , V_215 . T_4 ) ;
F_110 ( V_216 ) ;
}
static void F_215 ( struct V_14 * V_15 , int V_17 , bool V_166 )
{
struct V_186 * V_187 ;
unsigned int V_198 ;
T_4 V_197 , V_201 ;
union V_190 V_194 ;
unsigned int V_212 = V_15 -> V_1 - V_135 ;
V_198 = F_210 ( V_17 , V_212 ) ;
V_187 = F_40 ( V_186 , V_17 ) ;
V_201 = V_187 -> V_192 + F_193 ( V_198 ) ;
V_197 = V_187 -> V_192 + F_191 ( V_198 ) ;
V_194 . T_4 = 0 ;
V_194 . V_51 . V_166 = 1 ;
F_44 ( V_201 , V_194 . T_4 ) ;
F_44 ( V_197 , 0 ) ;
if ( V_166 ) {
unsigned int V_199 = F_40 ( V_217 , V_17 ) ;
V_194 . T_4 = 0 ;
V_194 . V_51 . V_166 = 1 ;
V_194 . V_51 . V_199 = V_199 ;
F_44 ( V_197 , V_194 . T_4 ) ;
}
F_110 ( V_197 ) ;
}
static void F_216 ( struct V_14 * V_15 )
{
int V_17 ;
unsigned int V_212 = V_15 -> V_1 - V_135 ;
F_217 ( V_212 >= V_211 ) ;
F_53 (cpu)
F_215 ( V_15 , V_17 , true ) ;
}
static void F_218 ( struct V_14 * V_15 )
{
int V_17 ;
unsigned int V_212 = V_15 -> V_1 - V_135 ;
F_217 ( V_212 >= V_211 ) ;
F_53 (cpu)
F_215 ( V_15 , V_17 , false ) ;
}
static void F_219 ( struct V_14 * V_15 )
{
struct V_186 * V_187 ;
unsigned int V_198 ;
T_4 V_201 ;
union V_195 V_196 ;
unsigned int V_212 = V_15 -> V_1 - V_135 ;
V_198 = F_209 ( F_206 () , V_212 ) ;
V_196 . T_4 = 0 ;
V_196 . V_51 . V_174 = 1 ;
V_187 = F_111 ( V_186 ) ;
V_201 = V_187 -> V_192 + F_193 ( V_198 ) ;
F_44 ( V_201 , V_196 . T_4 ) ;
F_110 ( V_201 ) ;
}
static void F_220 ( struct V_14 * V_15 )
{
F_215 ( V_15 , F_17 () , true ) ;
}
static void F_221 ( struct V_14 * V_15 )
{
F_215 ( V_15 , F_17 () , false ) ;
}
static int F_222 ( struct V_186 * V_187 )
{
T_4 V_218 = V_187 -> V_192 ;
int V_219 , V_220 , V_221 ;
int V_222 ;
int V_210 = F_206 () ;
int V_25 ;
F_125 ( V_186 , V_187 ) ;
V_219 = V_210 * 4 + 1 ;
V_220 = V_210 * 4 + 2 ;
V_221 = V_210 * 4 + 3 ;
V_222 = V_210 * 4 + 4 ;
F_125 ( V_200 , V_219 ) ;
F_125 ( V_217 , V_220 ) ;
F_44 ( V_218 + F_223 ( V_219 ) , 0 ) ;
F_44 ( V_218 + F_224 ( V_219 , 0 ) , 1ull << V_210 ) ;
F_44 ( V_218 + F_225 ( V_219 ) , 0 ) ;
F_44 ( V_218 + F_223 ( V_220 ) , 1 ) ;
F_44 ( V_218 + F_224 ( V_220 , 0 ) , 1ull << V_210 ) ;
F_44 ( V_218 + F_225 ( V_220 ) , 0 ) ;
F_44 ( V_218 + F_223 ( V_221 ) , 2 ) ;
F_44 ( V_218 + F_224 ( V_221 , 0 ) , 0 ) ;
F_44 ( V_218 + F_225 ( V_221 ) , 0 ) ;
F_44 ( V_218 + F_223 ( V_222 ) , 0 ) ;
F_44 ( V_218 + F_224 ( V_222 , 0 ) , 0 ) ;
F_44 ( V_218 + F_225 ( V_222 ) , 0 ) ;
for ( V_25 = 0 ; V_25 < V_211 ; V_25 ++ ) {
unsigned int V_198 = F_209 ( V_210 , V_25 ) ;
F_44 ( V_218 + F_193 ( V_198 ) , 2 ) ;
F_44 ( V_218 + F_191 ( V_198 ) , 0 ) ;
}
return 0 ;
}
static void F_226 ( void )
{
struct V_186 * V_187 ;
V_187 = V_223 [ F_227 () ] ;
F_222 ( V_187 ) ;
F_123 () ;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
}
static int T_2 F_228 ( struct V_69 * V_109 ,
struct V_69 * V_110 )
{
int V_25 ;
int V_70 ;
struct V_12 * V_16 ;
struct V_186 * V_187 ;
const T_10 * V_224 ;
T_4 V_225 ;
union V_226 V_227 ;
V_70 = 0 ;
V_187 = F_202 ( sizeof( * V_187 ) , V_9 , V_70 ) ;
if ( ! V_187 )
return - V_10 ;
V_224 = F_185 ( V_109 , 0 , NULL , NULL ) ;
if ( F_217 ( ! V_224 ) )
return - V_64 ;
V_225 = F_187 ( V_109 , V_224 ) ;
V_225 = ( T_4 ) F_186 ( V_225 ) ;
V_187 -> V_192 = V_225 ;
V_187 -> V_70 = V_70 ;
V_227 . T_4 = F_110 ( V_225 + V_228 ) ;
V_115 = F_226 ;
V_116 = F_204 ;
V_117 = F_211 ;
V_102 = F_120 ;
if ( V_70 == F_227 () ) {
F_31 () ;
V_25 = F_229 ( V_135 , 8 , V_70 ) ;
F_217 ( V_25 < 0 ) ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
F_3 ( V_25 + V_135 ,
& V_229 , V_30 ) ;
}
V_16 = F_136 ( V_109 , & V_230 ,
V_187 ) ;
for ( V_25 = 0 ; V_25 < V_231 ; V_25 ++ )
V_187 -> V_16 [ V_25 ] = V_16 ;
V_223 [ V_70 ] = V_187 ;
if ( V_70 == F_227 () ) {
F_222 ( V_187 ) ;
if ( V_70 == 0 )
F_137 ( V_16 ) ;
V_103 = false ;
F_22 ( V_108 | V_107 ) ;
F_19 ( V_100 ) ;
}
return 0 ;
}
void T_2 F_230 ( void )
{
#ifdef F_12
F_90 ( V_232 ) ;
F_91 ( F_17 () , V_232 ) ;
#endif
F_231 ( V_233 ) ;
}
T_11 void F_232 ( void )
{
unsigned long V_234 ;
unsigned long V_235 ;
while ( 1 ) {
V_234 = F_233 () ;
V_235 = F_234 () ;
V_234 &= V_235 ;
V_234 &= V_236 ;
if ( V_234 & V_108 )
V_116 () ;
else if ( V_234 & V_107 )
V_117 () ;
else if ( V_234 & V_100 )
V_102 () ;
else if ( V_234 )
F_114 ( F_235 ( V_234 ) - 9 + V_237 ) ;
else
break;
}
}
void F_236 ( void )
{
F_237 () ;
}
