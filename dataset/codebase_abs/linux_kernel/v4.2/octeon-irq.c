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
int V_31 = F_34 ( V_15 -> V_32 ) ;
struct V_7 * V_8 = F_7 ( V_15 ) ;
if ( V_31 > 1 ) {
V_17 = V_8 -> V_33 ;
for (; ; ) {
V_17 = F_35 ( V_17 , V_15 -> V_32 ) ;
if ( V_17 >= V_34 ) {
V_17 = - 1 ;
continue;
} else if ( F_36 ( V_17 , V_35 ) ) {
break;
}
}
} else if ( V_31 == 1 ) {
V_17 = F_37 ( V_15 -> V_32 ) ;
} else {
V_17 = F_17 () ;
}
V_8 -> V_33 = V_17 ;
return V_17 ;
#else
return F_17 () ;
#endif
}
static void F_38 ( struct V_14 * V_15 )
{
int V_17 = F_33 ( V_15 ) ;
int V_18 = F_11 ( V_17 ) ;
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = & F_39 ( V_39 , V_17 ) ;
V_8 = F_7 ( V_15 ) ;
F_40 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = & F_39 ( V_40 , V_17 ) ;
F_41 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_44 ( V_18 * 2 ) , * V_36 ) ;
} else {
V_36 = & F_39 ( V_41 , V_17 ) ;
F_41 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_45 ( V_18 * 2 + 1 ) , * V_36 ) ;
}
F_46 ( V_38 , V_37 ) ;
}
static void F_47 ( struct V_14 * V_15 )
{
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = F_48 ( & V_39 ) ;
V_8 = F_7 ( V_15 ) ;
F_40 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = F_48 ( & V_40 ) ;
F_41 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_44 ( F_14 () * 2 ) , * V_36 ) ;
} else {
V_36 = F_48 ( & V_41 ) ;
F_41 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_45 ( F_14 () * 2 + 1 ) , * V_36 ) ;
}
F_46 ( V_38 , V_37 ) ;
}
static void F_49 ( struct V_14 * V_15 )
{
unsigned long * V_36 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
T_3 * V_38 = F_48 ( & V_39 ) ;
V_8 = F_7 ( V_15 ) ;
F_40 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 ) {
V_36 = F_48 ( & V_40 ) ;
F_50 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_44 ( F_14 () * 2 ) , * V_36 ) ;
} else {
V_36 = F_48 ( & V_41 ) ;
F_50 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
F_43 ( F_45 ( F_14 () * 2 + 1 ) , * V_36 ) ;
}
F_46 ( V_38 , V_37 ) ;
}
static void F_51 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_17 ;
struct V_7 * V_8 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
F_52 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_39 ( V_39 , V_17 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_39 ( V_40 , V_17 ) ;
else
V_36 = & F_39 ( V_41 , V_17 ) ;
F_40 ( V_38 , V_37 ) ;
F_50 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
if ( V_8 -> line == 0 )
F_43 ( F_44 ( V_18 * 2 ) , * V_36 ) ;
else
F_43 ( F_45 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_46 ( V_38 , V_37 ) ;
}
}
static void F_53 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_17 ;
struct V_7 * V_8 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
F_52 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_39 ( V_39 , V_17 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_39 ( V_40 , V_17 ) ;
else
V_36 = & F_39 ( V_41 , V_17 ) ;
F_40 ( V_38 , V_37 ) ;
F_41 ( V_8 -> V_2 , V_36 ) ;
F_42 () ;
if ( V_8 -> line == 0 )
F_43 ( F_44 ( V_18 * 2 ) , * V_36 ) ;
else
F_43 ( F_45 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_46 ( V_38 , V_37 ) ;
}
}
static void F_54 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_55 ( V_8 -> V_2 , & F_39 ( V_40 , V_17 ) ) ;
F_43 ( F_56 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_55 ( V_8 -> V_2 , & F_39 ( V_41 , V_17 ) ) ;
F_43 ( F_57 ( V_42 ) , V_21 ) ;
}
}
static void F_58 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_43 ( F_59 ( V_42 ) , V_21 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_43 ( F_61 ( V_42 ) , V_21 ) ;
}
static void F_62 ( struct V_14 * V_15 )
{
T_4 V_21 ;
int V_17 = F_33 ( V_15 ) ;
int V_42 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_43 ( F_63 ( V_42 ) , V_21 ) ;
}
static void F_64 ( struct V_14 * V_15 )
{
int V_17 ;
struct V_7 * V_8 ;
T_4 V_21 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_52 (cpu) {
int V_18 = F_11 ( V_17 ) ;
F_43 ( F_61 ( V_18 ) , V_21 ) ;
}
}
static void F_65 ( struct V_14 * V_15 )
{
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_14 () * 2 ;
F_55 ( V_8 -> V_2 , F_48 ( & V_40 ) ) ;
F_43 ( F_56 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_14 () * 2 + 1 ;
F_55 ( V_8 -> V_2 , F_48 ( & V_41 ) ) ;
F_43 ( F_57 ( V_42 ) , V_21 ) ;
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
F_67 ( V_8 -> V_2 , F_48 ( & V_40 ) ) ;
F_43 ( F_68 ( V_42 ) , V_21 ) ;
} else {
int V_42 = F_14 () * 2 + 1 ;
F_67 ( V_8 -> V_2 , F_48 ( & V_41 ) ) ;
F_43 ( F_69 ( V_42 ) , V_21 ) ;
}
}
static void F_70 ( struct V_14 * V_15 )
{
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
int V_42 = F_14 () * 2 ;
F_43 ( F_71 ( V_42 ) , V_21 ) ;
} else {
F_43 ( V_43 , V_21 ) ;
}
}
static void F_72 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
if ( V_8 -> line == 0 ) {
F_52 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_67 ( V_8 -> V_2 ,
& F_39 ( V_40 , V_17 ) ) ;
F_43 ( F_68 ( V_42 ) , V_21 ) ;
}
} else {
F_52 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_67 ( V_8 -> V_2 ,
& F_39 ( V_41 , V_17 ) ) ;
F_43 ( F_69 ( V_42 ) , V_21 ) ;
}
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
F_52 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 ;
F_55 ( V_8 -> V_2 ,
& F_39 ( V_40 , V_17 ) ) ;
F_43 ( F_56 ( V_42 ) , V_21 ) ;
}
} else {
F_52 (cpu) {
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
F_55 ( V_8 -> V_2 ,
& F_39 ( V_41 , V_17 ) ) ;
F_43 ( F_57 ( V_42 ) , V_21 ) ;
}
}
}
static void F_74 ( struct V_14 * V_15 )
{
union V_44 V_45 ;
struct V_7 * V_8 ;
T_5 V_46 = F_75 ( V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_45 . T_4 = 0 ;
V_45 . V_47 . V_48 = 1 ;
V_45 . V_47 . V_49 = ( V_46 & V_50 ) != 0 ;
V_45 . V_47 . V_51 = ( V_46 & ( V_52 | V_53 ) ) != 0 ;
V_45 . V_47 . V_54 = 7 ;
V_45 . V_47 . V_55 = 3 ;
F_43 ( F_76 ( V_8 -> V_3 ) , V_45 . T_4 ) ;
}
static void F_77 ( struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
F_54 ( V_15 ) ;
}
static void F_78 ( struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
F_38 ( V_15 ) ;
}
static int F_79 ( struct V_14 * V_15 , unsigned int V_46 )
{
F_80 ( V_15 , V_46 ) ;
F_74 ( V_15 ) ;
return V_56 ;
}
static void F_81 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_43 ( F_76 ( V_8 -> V_3 ) , 0 ) ;
F_72 ( V_15 ) ;
}
static void F_82 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_43 ( F_76 ( V_8 -> V_3 ) , 0 ) ;
F_51 ( V_15 ) ;
}
static void F_83 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
T_4 V_21 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_3 ) ;
F_43 ( V_57 , V_21 ) ;
}
static void F_84 ( unsigned int V_1 , struct V_58 * V_59 )
{
struct V_14 * V_15 = F_85 ( V_59 ) ;
if ( F_75 ( V_15 ) & V_50 )
F_86 ( V_1 , V_59 ) ;
else
F_87 ( V_1 , V_59 ) ;
}
static void F_88 ( struct V_14 * V_15 )
{
int V_17 = F_17 () ;
T_6 V_60 ;
if ( ! F_36 ( V_17 , V_15 -> V_32 ) )
return;
if ( F_34 ( V_15 -> V_32 ) > 1 ) {
F_89 ( & V_60 , V_15 -> V_32 ) ;
F_90 ( V_17 , & V_60 ) ;
} else {
F_91 ( & V_60 ) ;
F_92 ( F_37 ( V_35 ) , & V_60 ) ;
}
F_93 ( V_15 , & V_60 , false ) ;
}
static int F_94 ( struct V_14 * V_15 ,
const struct V_61 * V_62 , bool V_63 )
{
int V_17 ;
bool V_64 = ! F_95 ( V_15 ) && ! F_96 ( V_15 ) ;
unsigned long V_37 ;
struct V_7 * V_8 ;
unsigned long * V_36 ;
T_3 * V_38 ;
V_8 = F_7 ( V_15 ) ;
if ( F_34 ( V_62 ) != 1 )
return - V_65 ;
if ( ! V_64 )
return 0 ;
F_52 (cpu) {
int V_18 = F_11 ( V_17 ) ;
V_38 = & F_39 ( V_39 , V_17 ) ;
F_40 ( V_38 , V_37 ) ;
if ( V_8 -> line == 0 )
V_36 = & F_39 ( V_40 , V_17 ) ;
else
V_36 = & F_39 ( V_41 , V_17 ) ;
if ( F_36 ( V_17 , V_62 ) && V_64 ) {
V_64 = 0 ;
F_41 ( V_8 -> V_2 , V_36 ) ;
} else {
F_50 ( V_8 -> V_2 , V_36 ) ;
}
F_42 () ;
if ( V_8 -> line == 0 )
F_43 ( F_44 ( V_18 * 2 ) , * V_36 ) ;
else
F_43 ( F_45 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_46 ( V_38 , V_37 ) ;
}
return 0 ;
}
static int F_97 ( struct V_14 * V_15 ,
const struct V_61 * V_62 ,
bool V_63 )
{
int V_17 ;
bool V_64 = ! F_95 ( V_15 ) && ! F_96 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_64 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
if ( V_8 -> line == 0 ) {
F_52 (cpu) {
unsigned long * V_36 = & F_39 ( V_40 , V_17 ) ;
int V_42 = F_11 ( V_17 ) * 2 ;
if ( F_36 ( V_17 , V_62 ) && V_64 ) {
V_64 = false ;
F_55 ( V_8 -> V_2 , V_36 ) ;
F_43 ( F_56 ( V_42 ) , V_21 ) ;
} else {
F_67 ( V_8 -> V_2 , V_36 ) ;
F_43 ( F_68 ( V_42 ) , V_21 ) ;
}
}
} else {
F_52 (cpu) {
unsigned long * V_36 = & F_39 ( V_41 , V_17 ) ;
int V_42 = F_11 ( V_17 ) * 2 + 1 ;
if ( F_36 ( V_17 , V_62 ) && V_64 ) {
V_64 = false ;
F_55 ( V_8 -> V_2 , V_36 ) ;
F_43 ( F_57 ( V_42 ) , V_21 ) ;
} else {
F_67 ( V_8 -> V_2 , V_36 ) ;
F_43 ( F_69 ( V_42 ) , V_21 ) ;
}
}
}
return 0 ;
}
static int F_98 ( struct V_14 * V_15 ,
const struct V_61 * V_62 ,
bool V_63 )
{
int V_17 ;
bool V_64 = ! F_95 ( V_15 ) && ! F_96 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_64 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
F_52 (cpu) {
int V_42 = F_11 ( V_17 ) ;
if ( F_36 ( V_17 , V_62 ) && V_64 ) {
V_64 = false ;
F_43 ( F_59 ( V_42 ) , V_21 ) ;
} else {
F_43 ( F_61 ( V_42 ) , V_21 ) ;
}
}
return 0 ;
}
static void F_99 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_18 = V_15 -> V_1 - V_66 ;
int V_17 = F_15 ( V_18 ) ;
T_3 * V_38 = & F_39 ( V_39 , V_17 ) ;
F_40 ( V_38 , V_37 ) ;
V_36 = & F_39 ( V_41 , V_17 ) ;
F_41 ( V_18 , V_36 ) ;
F_42 () ;
F_43 ( F_45 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_46 ( V_38 , V_37 ) ;
}
static void F_100 ( struct V_14 * V_15 )
{
int V_18 = V_15 -> V_1 - V_66 ;
int V_17 = F_15 ( V_18 ) ;
F_55 ( V_18 , & F_39 ( V_41 , V_17 ) ) ;
F_43 ( F_57 ( V_18 * 2 + 1 ) , 1ull << V_18 ) ;
}
static bool F_101 ( unsigned int line , unsigned int V_2 )
{
bool V_67 = false ;
if ( line == 0 )
switch ( V_2 ) {
case 48 ... 49 :
case 50 :
case 52 ... 55 :
case 58 :
V_67 = true ;
break;
default:
break;
}
else
switch ( V_2 ) {
case 47 :
V_67 = true ;
break;
default:
break;
}
return V_67 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_68 * V_69 ,
const T_5 * V_70 ,
unsigned int V_71 ,
unsigned long * V_72 ,
unsigned int * V_73 )
{
unsigned int type ;
unsigned int V_74 ;
unsigned int V_75 ;
if ( V_13 -> V_76 != V_69 )
return - V_65 ;
if ( V_71 < 2 )
return - V_65 ;
V_74 = V_70 [ 0 ] ;
if ( V_74 >= 16 )
return - V_65 ;
V_75 = V_70 [ 1 ] ;
switch ( V_75 ) {
case 1 :
type = V_77 ;
break;
case 2 :
type = V_53 ;
break;
case 4 :
type = V_78 ;
break;
case 8 :
type = V_52 ;
break;
default:
F_103 ( L_1 ,
V_69 -> V_79 ,
V_75 ) ;
type = V_52 ;
break;
}
* V_73 = type ;
* V_72 = V_74 ;
return 0 ;
}
static int F_104 ( struct V_12 * V_13 ,
struct V_68 * V_69 ,
const T_5 * V_70 ,
unsigned int V_71 ,
unsigned long * V_72 ,
unsigned int * V_73 )
{
unsigned int V_80 , V_2 ;
struct V_81 * V_82 = V_13 -> V_83 ;
V_80 = V_70 [ 0 ] ;
V_2 = V_70 [ 1 ] ;
if ( V_80 >= V_82 -> V_84 || V_2 > 63 )
return - V_65 ;
* V_72 = ( V_80 << 6 ) | V_2 ;
* V_73 = 0 ;
return 0 ;
}
static bool F_105 ( unsigned int V_85 )
{
if ( V_85 < ( 1ul << 8 * sizeof( V_11 [ 0 ] [ 0 ] ) ) )
return true ;
F_106 ( true , L_2 , V_85 ) ;
return false ;
}
static int F_107 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
int V_87 ;
unsigned int line = V_86 >> 6 ;
unsigned int V_2 = V_86 & 63 ;
struct V_81 * V_82 = V_13 -> V_83 ;
if ( ! F_105 ( V_85 ) )
return - V_65 ;
if ( line == 0 && V_2 >= 16 && V_2 < 32 )
return 0 ;
if ( line >= V_82 -> V_84 || V_11 [ line ] [ V_2 ] != 0 )
return - V_65 ;
if ( line == 2 ) {
if ( F_101 ( line , V_2 ) )
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
& V_88 ,
F_86 ) ;
else
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
& V_89 ,
F_87 ) ;
} else {
if ( F_101 ( line , V_2 ) )
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
V_90 ,
F_86 ) ;
else
V_87 = F_1 ( V_85 , line , V_2 , 0 ,
V_91 ,
F_87 ) ;
}
return V_87 ;
}
static int F_108 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
struct V_92 * V_93 = V_13 -> V_83 ;
unsigned int line , V_2 ;
int V_94 ;
if ( ! F_105 ( V_85 ) )
return - V_65 ;
line = ( V_86 + V_93 -> V_95 ) >> 6 ;
V_2 = ( V_86 + V_93 -> V_95 ) & 63 ;
if ( line > F_109 ( V_11 ) ||
V_11 [ line ] [ V_2 ] != 0 )
return - V_65 ;
V_94 = F_1 ( V_85 , line , V_2 , V_86 ,
V_96 , F_84 ) ;
return V_94 ;
}
static void F_110 ( void )
{
const unsigned long V_97 = F_14 () ;
T_4 V_98 = F_111 ( F_71 ( V_97 * 2 ) ) ;
V_98 &= F_112 ( V_40 ) ;
if ( F_113 ( V_98 ) ) {
int V_2 = F_114 ( V_98 ) - 1 ;
int V_1 = V_11 [ 0 ] [ V_2 ] ;
if ( F_113 ( V_1 ) )
F_115 ( V_1 ) ;
else
F_116 () ;
} else {
F_116 () ;
}
}
static void F_117 ( void )
{
T_4 V_98 = F_111 ( V_43 ) ;
V_98 &= F_112 ( V_41 ) ;
if ( F_113 ( V_98 ) ) {
int V_2 = F_114 ( V_98 ) - 1 ;
int V_1 = V_11 [ 1 ] [ V_2 ] ;
if ( F_113 ( V_1 ) )
F_115 ( V_1 ) ;
else
F_116 () ;
} else {
F_116 () ;
}
}
static void F_118 ( void )
{
int V_18 = F_14 () ;
T_4 V_98 = F_111 ( F_63 ( V_18 ) ) ;
T_4 V_99 = F_111 ( F_119 ( V_18 ) ) ;
V_98 &= V_99 ;
if ( F_113 ( V_98 ) ) {
int V_2 = F_114 ( V_98 ) - 1 ;
int V_1 = V_11 [ 2 ] [ V_2 ] ;
if ( F_113 ( V_1 ) )
F_115 ( V_1 ) ;
else
F_116 () ;
} else {
F_116 () ;
}
}
static void F_120 ( void * V_20 )
{
F_22 ( V_100 ) ;
}
static void F_121 ( void )
{
F_19 ( V_100 ) ;
F_116 () ;
}
void F_122 ( T_8 V_101 )
{
V_102 = V_101 ;
V_103 = true ;
F_29 ( F_120 , NULL , 1 ) ;
}
static void F_123 ( void )
{
F_124 () ;
}
static void F_125 ( void )
{
int V_18 = F_14 () ;
F_126 ( V_40 , 0 ) ;
F_126 ( V_41 , 0 ) ;
F_42 () ;
F_127 ( F_48 ( & V_39 ) ) ;
F_43 ( F_44 ( ( V_18 * 2 ) ) , 0 ) ;
F_43 ( F_44 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_43 ( F_45 ( ( V_18 * 2 ) ) , 0 ) ;
F_43 ( F_45 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_111 ( F_71 ( ( V_18 * 2 ) ) ) ;
}
static void F_128 ( void )
{
T_4 V_104 , V_105 ;
int V_18 = F_14 () ;
T_4 V_106 = F_129 ( V_18 ) ;
for ( V_104 = 0 ; V_104 <= 0x8000 ; V_104 += 0x1000 ) {
for ( V_105 = 0 ; V_105 <= 0x400 ; V_105 += 0x200 )
F_43 ( V_106 + V_104 + V_105 , 0 ) ;
}
F_111 ( F_130 ( V_18 ) ) ;
}
static void F_131 ( void )
{
F_125 () ;
F_123 () ;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
}
static void F_132 ( void )
{
F_128 () ;
F_123 () ;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
}
static int T_2 F_133 (
struct V_68 * V_109 , struct V_68 * V_110 )
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
F_125 () ;
V_115 = F_131 ;
V_116 = F_110 ;
V_117 = F_117 ;
if ( ( F_134 () || F_135 () )
&& ! F_136 ( V_118 ) ) {
V_102 = F_118 ;
V_82 -> V_84 = 3 ;
V_103 = true ;
} else {
V_102 = F_121 ;
V_82 -> V_84 = 2 ;
V_103 = false ;
}
if ( F_136 ( V_119 ) ||
F_136 ( V_120 ) ||
F_136 ( V_121 ) ||
F_134 () || F_135 () ) {
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
V_114 = F_137 (
V_109 , & V_132 , V_82 ) ;
F_138 ( V_114 ) ;
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
V_94 = F_9 ( V_114 , V_142 , 0 , 56 ) ;
if ( V_94 )
goto V_134;
V_94 = F_9 ( V_114 , V_143 , 0 , 59 ) ;
if ( V_94 )
goto V_134;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_94 = F_1 (
V_25 + V_66 , 1 , V_25 + 0 , 0 , V_113 ,
F_87 ) ;
if ( V_94 )
goto V_134;
}
V_94 = F_9 ( V_114 , V_144 , 1 , 17 ) ;
if ( V_94 )
goto V_134;
F_22 ( V_107 | V_108 ) ;
if ( V_103 )
F_22 ( V_100 ) ;
else
F_19 ( V_100 ) ;
return 0 ;
V_134:
return V_94 ;
}
static int T_2 F_139 (
struct V_68 * V_145 , struct V_68 * V_110 )
{
struct V_92 * V_93 ;
T_5 V_146 ;
unsigned int V_95 ;
int V_94 ;
V_94 = F_140 ( V_110 , L_3 , & V_146 ) ;
if ( V_94 )
return V_94 ;
if ( V_146 == 1 ) {
T_5 V_147 ;
V_94 = F_141 ( V_145 , L_4 , 0 , & V_147 ) ;
if ( V_94 ) {
F_142 ( L_5 ) ;
return V_94 ;
}
V_95 = V_147 ;
} else if ( V_146 == 2 ) {
T_5 V_148 , V_149 ;
V_94 = F_141 ( V_145 , L_4 , 0 , & V_148 ) ;
if ( V_94 ) {
F_142 ( L_5 ) ;
return V_94 ;
}
V_94 = F_141 ( V_145 , L_4 , 1 , & V_149 ) ;
if ( V_94 ) {
F_142 ( L_5 ) ;
return V_94 ;
}
V_95 = ( V_148 << 6 ) | V_149 ;
} else {
F_142 ( L_6 ,
V_146 ) ;
return - V_65 ;
}
V_93 = F_2 ( sizeof( * V_93 ) , V_9 ) ;
if ( V_93 ) {
V_93 -> V_95 = V_95 ;
F_143 (
V_145 , 16 , & V_150 , V_93 ) ;
} else {
F_142 ( L_7 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_144 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = V_15 -> V_1 - V_66 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_151 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_146 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_17 = F_33 ( V_15 ) ;
int V_18 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_151 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_147 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_151 = F_145 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_148 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_151 = F_149 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_150 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_151 = F_151 ( V_18 ) + ( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_152 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_52 (cpu) {
T_4 V_151 = F_149 (
F_11 ( V_17 ) ) + ( 0x1000ull * V_8 -> line ) ;
F_43 ( V_151 , V_21 ) ;
}
}
static void F_153 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
F_52 (cpu) {
T_4 V_151 = F_154 (
F_11 ( V_17 ) ) ;
F_43 ( V_151 , V_21 ) ;
}
}
static void F_155 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
F_52 (cpu) {
T_4 V_151 = F_156 (
F_11 ( V_17 ) ) ;
F_43 ( V_151 , V_21 ) ;
}
}
static void F_157 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
V_151 = F_154 ( V_18 ) ;
F_43 ( V_151 , V_21 ) ;
}
static void F_158 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_151 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_135 ) ;
V_151 = F_156 ( V_18 ) ;
F_43 ( V_151 , V_21 ) ;
}
static int F_159 ( struct V_14 * V_15 ,
const struct V_61 * V_62 , bool V_63 )
{
int V_17 ;
bool V_64 = ! F_95 ( V_15 ) && ! F_96 ( V_15 ) ;
T_4 V_21 ;
struct V_7 * V_8 ;
if ( ! V_64 )
return 0 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << V_8 -> V_2 ;
F_52 (cpu) {
T_4 V_151 ;
if ( F_36 ( V_17 , V_62 ) && V_64 ) {
V_64 = false ;
V_151 = F_145 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
} else {
V_151 = F_149 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
}
F_43 ( V_151 , V_21 ) ;
}
return 0 ;
}
static void F_160 ( struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
F_146 ( V_15 ) ;
}
static void F_161 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_43 ( F_76 ( V_8 -> V_3 ) , 0 ) ;
F_152 ( V_15 ) ;
}
static int F_162 ( struct V_12 * V_13 ,
struct V_68 * V_69 ,
const T_5 * V_70 ,
unsigned int V_71 ,
unsigned long * V_72 ,
unsigned int * V_73 )
{
unsigned int V_80 , V_2 ;
V_80 = V_70 [ 0 ] ;
V_2 = V_70 [ 1 ] ;
* V_72 = ( V_80 << 6 ) | V_2 ;
* V_73 = 0 ;
return 0 ;
}
static bool F_163 ( unsigned int line , unsigned int V_2 )
{
bool V_67 = false ;
if ( line == 3 )
switch ( V_2 ) {
case 2 :
case 8 ... 11 :
case 48 :
V_67 = true ;
break;
default:
break;
}
else if ( line == 6 )
switch ( V_2 ) {
case 52 ... 53 :
case 8 ... 12 :
V_67 = true ;
break;
default:
break;
}
return V_67 ;
}
static int F_164 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
unsigned int line = V_86 >> 6 ;
unsigned int V_2 = V_86 & 63 ;
if ( ! F_105 ( V_85 ) )
return - V_65 ;
if ( line == 7 )
return 0 ;
if ( line > 7 || V_11 [ line ] [ V_2 ] != 0 )
return - V_65 ;
if ( F_163 ( line , V_2 ) )
F_1 ( V_85 , line , V_2 , 0 ,
& V_152 ,
F_86 ) ;
else
F_1 ( V_85 , line , V_2 , 0 ,
& V_153 ,
F_87 ) ;
return 0 ;
}
static void F_165 ( void )
{
int line ;
int V_2 ;
int V_1 ;
T_4 V_154 , V_155 , V_156 ;
const unsigned long V_97 = F_14 () ;
V_156 = F_111 ( F_130 ( V_97 ) ) & 0xfful ;
if ( F_166 ( ! V_156 ) )
goto V_157;
line = F_114 ( V_156 ) - 1 ;
V_154 = F_167 ( V_97 ) + ( 0x1000 * line ) ;
V_155 = F_111 ( V_154 ) ;
if ( F_166 ( ! V_155 ) )
goto V_157;
V_2 = F_114 ( V_155 ) - 1 ;
V_1 = V_11 [ line ] [ V_2 ] ;
if ( F_166 ( ! V_1 ) )
goto V_157;
F_115 ( V_1 ) ;
goto V_158;
V_157:
F_116 () ;
V_158:
if ( F_136 ( V_159 ) )
F_111 ( V_160 ) ;
else
F_111 ( F_168 ( V_97 ) ) ;
return;
}
static void F_169 ( void )
{
int line ;
const unsigned long V_97 = F_14 () ;
T_4 V_156 = F_111 ( F_170 ( V_97 ) ) >> 60 ;
if ( F_166 ( ! V_156 ) )
goto V_157;
line = F_114 ( V_156 ) - 1 ;
F_115 ( V_135 + line ) ;
goto V_158;
V_157:
F_116 () ;
V_158:
if ( F_136 ( V_159 ) )
F_111 ( V_160 ) ;
else
F_111 ( F_171 ( V_97 ) ) ;
return;
}
static int T_2 F_172 (
struct V_68 * V_109 , struct V_68 * V_110 )
{
unsigned int V_25 , V_94 ;
struct V_12 * V_114 = NULL ;
F_128 () ;
V_115 = F_132 ;
V_96 = & V_161 ;
V_116 = F_165 ;
V_117 = F_169 ;
V_102 = F_121 ;
F_31 () ;
V_114 = F_137 (
V_109 , & V_162 , NULL ) ;
F_138 ( V_114 ) ;
for ( V_25 = 0 ; V_25 < 64 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_133 , 0 , V_25 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 32 ; V_25 ++ ) {
V_94 = F_1 ( V_25 + V_66 , 1 , V_25 , 0 ,
& V_163 , F_87 ) ;
if ( V_94 )
goto V_134;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_94 = F_9 (
V_114 , V_25 + V_141 , 3 , V_25 + 8 ) ;
if ( V_94 )
goto V_134;
}
V_94 = F_9 ( V_114 , V_142 , 3 , 44 ) ;
if ( V_94 )
goto V_134;
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
F_3 ( V_135 , & V_164 , V_30 ) ;
F_3 ( V_136 , & V_164 , V_30 ) ;
F_3 ( V_165 , & V_164 , V_30 ) ;
F_3 ( V_166 , & V_164 , V_30 ) ;
F_22 ( V_107 | V_108 ) ;
F_19 ( V_100 ) ;
return 0 ;
V_134:
return V_94 ;
}
static void F_173 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_167 ;
struct V_168 * V_8 = F_7 ( V_15 ) ;
struct V_169 * V_83 = V_8 -> V_83 ;
F_40 ( & V_83 -> V_38 , V_37 ) ;
V_167 = F_111 ( V_83 -> V_170 ) ;
V_167 |= 1ull << V_8 -> V_2 ;
F_43 ( V_83 -> V_170 , V_167 ) ;
F_46 ( & V_83 -> V_38 , V_37 ) ;
}
static void F_174 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_167 ;
struct V_168 * V_8 = F_7 ( V_15 ) ;
struct V_169 * V_83 = V_8 -> V_83 ;
F_40 ( & V_83 -> V_38 , V_37 ) ;
V_167 = F_111 ( V_83 -> V_170 ) ;
V_167 &= ~ ( 1ull << V_8 -> V_2 ) ;
F_43 ( V_83 -> V_170 , V_167 ) ;
F_46 ( & V_83 -> V_38 , V_37 ) ;
}
static int F_175 ( struct V_14 * V_15 , unsigned int V_46 )
{
F_80 ( V_15 , V_46 ) ;
return V_56 ;
}
static int F_176 ( struct V_12 * V_13 ,
struct V_68 * V_69 ,
const T_5 * V_70 ,
unsigned int V_71 ,
unsigned long * V_72 ,
unsigned int * V_73 )
{
unsigned int type = 0 ;
if ( V_71 == 2 )
type = V_70 [ 1 ] ;
switch ( type ) {
case 0 :
case 4 :
* V_73 = V_78 ;
break;
case 1 :
* V_73 = V_77 ;
break;
default:
return - V_65 ;
}
* V_72 = V_70 [ 0 ] ;
return 0 ;
}
static int F_177 ( struct V_12 * V_13 ,
unsigned int V_85 , T_7 V_86 )
{
struct V_169 * V_83 = V_13 -> V_83 ;
struct V_168 * V_8 ;
if ( V_86 >= V_83 -> V_171 ) {
F_103 ( L_8 ,
V_13 -> V_76 -> V_79 , ( unsigned ) V_86 ) ;
return - V_65 ;
}
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
V_8 -> V_83 = V_83 ;
V_8 -> V_2 = V_86 ;
F_3 ( V_85 , & V_172 ,
V_173 ) ;
F_4 ( V_85 , V_8 ) ;
return 0 ;
}
static T_9 F_178 ( int V_174 , void * V_15 )
{
T_4 V_167 ;
T_4 V_175 ;
T_4 V_176 ;
int V_25 ;
int V_1 ;
struct V_12 * V_177 = V_15 ;
struct V_169 * V_83 = V_177 -> V_83 ;
V_167 = F_111 ( V_83 -> V_170 ) ;
V_175 = F_111 ( V_83 -> V_178 ) ;
V_176 = V_167 & V_175 ;
for ( V_25 = 0 ; V_25 < V_83 -> V_171 ; V_25 ++ ) {
if ( ( V_176 & 1ull << V_25 ) == 0 )
continue;
V_1 = F_179 ( V_177 , V_25 ) ;
if ( ! V_1 ) {
unsigned long V_37 ;
F_103 ( L_9 ,
V_25 , V_83 -> V_178 ) ;
F_40 ( & V_83 -> V_38 , V_37 ) ;
V_167 = F_111 ( V_83 -> V_170 ) ;
V_167 &= ~ ( 1ull << V_25 ) ;
F_43 ( V_83 -> V_170 , V_167 ) ;
F_43 ( V_83 -> V_178 , 1ull << V_25 ) ;
F_46 ( & V_83 -> V_38 , V_37 ) ;
} else {
struct V_58 * V_59 = F_180 ( V_1 ) ;
struct V_14 * V_14 = F_85 ( V_59 ) ;
if ( F_75 ( V_14 ) &
V_50 )
F_43 ( V_83 -> V_178 , 1ull << V_25 ) ;
F_181 ( V_1 , V_59 ) ;
}
}
return V_179 ;
}
static int T_2 F_182 ( struct V_68 * V_109 ,
struct V_68 * V_110 )
{
const T_10 * V_180 ;
T_5 V_181 ;
struct V_169 * V_83 ;
int V_182 ;
int V_94 ;
struct V_12 * V_177 ;
V_182 = F_183 ( V_109 , 0 ) ;
if ( ! V_182 ) {
F_103 ( L_10 ,
V_109 -> V_79 ) ;
return - V_65 ;
}
V_83 = F_2 ( sizeof( * V_83 ) , V_9 ) ;
F_127 ( & V_83 -> V_38 ) ;
V_180 = F_184 ( V_109 , 0 , NULL , NULL ) ;
if ( ! V_180 ) {
F_103 ( L_11 , V_109 -> V_79 ) ;
return - V_65 ;
}
V_83 -> V_178 = ( T_4 ) F_185 (
F_186 ( V_109 , V_180 ) ) ;
V_180 = F_184 ( V_109 , 1 , NULL , NULL ) ;
if ( ! V_180 ) {
F_103 ( L_12 , V_109 -> V_79 ) ;
return - V_65 ;
}
V_83 -> V_170 = ( T_4 ) F_185 (
F_186 ( V_109 , V_180 ) ) ;
V_94 = F_140 ( V_109 , L_13 , & V_181 ) ;
if ( V_94 ) {
F_103 ( L_14 ,
V_109 -> V_79 ) ;
return V_94 ;
}
V_83 -> V_171 = V_181 ;
V_177 = F_143 ( V_109 , V_83 -> V_171 ,
& V_183 ,
V_83 ) ;
if ( ! V_177 ) {
F_103 ( L_15 ) ;
return - V_10 ;
}
F_43 ( V_83 -> V_170 , 0 ) ;
F_43 ( V_83 -> V_178 , ~ 0 ) ;
V_94 = F_187 ( V_182 , F_178 ,
V_184 , L_16 , V_177 ) ;
if ( V_94 ) {
F_103 ( L_17 , V_94 ) ;
return V_94 ;
}
F_188 ( L_18 ,
V_83 -> V_178 , V_83 -> V_171 ) ;
return 0 ;
}
void T_2 F_189 ( void )
{
#ifdef F_12
F_91 ( V_185 ) ;
F_92 ( F_17 () , V_185 ) ;
#endif
F_190 ( V_186 ) ;
}
T_11 void F_191 ( void )
{
unsigned long V_187 ;
unsigned long V_188 ;
while ( 1 ) {
V_187 = F_192 () ;
V_188 = F_193 () ;
V_187 &= V_188 ;
V_187 &= V_189 ;
if ( V_187 & V_108 )
V_116 () ;
else if ( V_187 & V_107 )
V_117 () ;
else if ( V_187 & V_100 )
V_102 () ;
else if ( V_187 )
F_115 ( F_194 ( V_187 ) - 9 + V_190 ) ;
else
break;
}
}
void F_195 ( void )
{
F_196 () ;
}
