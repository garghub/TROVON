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
static void F_75 ( struct V_14 * V_15 )
{
union V_44 V_45 ;
struct V_7 * V_8 ;
T_5 V_46 = F_76 ( V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_45 . T_4 = 0 ;
V_45 . V_47 . V_48 = 1 ;
V_45 . V_47 . V_49 = ( V_46 & V_50 ) != 0 ;
V_45 . V_47 . V_51 = ( V_46 & ( V_52 | V_53 ) ) != 0 ;
V_45 . V_47 . V_54 = 7 ;
V_45 . V_47 . V_55 = 3 ;
F_44 ( F_77 ( V_8 -> V_3 ) , V_45 . T_4 ) ;
}
static void F_78 ( struct V_14 * V_15 )
{
F_75 ( V_15 ) ;
F_55 ( V_15 ) ;
}
static void F_79 ( struct V_14 * V_15 )
{
F_75 ( V_15 ) ;
F_39 ( V_15 ) ;
}
static int F_80 ( struct V_14 * V_15 , unsigned int V_46 )
{
F_81 ( V_15 , V_46 ) ;
F_75 ( V_15 ) ;
if ( F_76 ( V_15 ) & V_50 )
F_82 ( V_15 , V_56 ) ;
else
F_82 ( V_15 , V_57 ) ;
return V_58 ;
}
static void F_83 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_77 ( V_8 -> V_3 ) , 0 ) ;
F_73 ( V_15 ) ;
}
static void F_84 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_77 ( V_8 -> V_3 ) , 0 ) ;
F_52 ( V_15 ) ;
}
static void F_85 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
T_4 V_21 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_3 ) ;
F_44 ( V_59 , V_21 ) ;
}
static void F_86 ( struct V_14 * V_15 )
{
int V_17 = F_17 () ;
T_6 V_60 ;
struct V_31 * V_21 = F_34 ( V_15 ) ;
if ( ! F_37 ( V_17 , V_21 ) )
return;
if ( F_35 ( V_21 ) > 1 ) {
F_87 ( & V_60 , V_21 ) ;
F_88 ( V_17 , & V_60 ) ;
} else {
F_89 ( & V_60 ) ;
F_90 ( F_38 ( V_35 ) , & V_60 ) ;
}
F_91 ( V_15 , & V_60 , false ) ;
}
static int F_92 ( struct V_14 * V_15 ,
const struct V_31 * V_61 , bool V_62 )
{
int V_17 ;
bool V_63 = ! F_93 ( V_15 ) && ! F_94 ( V_15 ) ;
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
static int F_95 ( struct V_14 * V_15 ,
const struct V_31 * V_61 ,
bool V_62 )
{
int V_17 ;
bool V_63 = ! F_93 ( V_15 ) && ! F_94 ( V_15 ) ;
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
static int F_96 ( struct V_14 * V_15 ,
const struct V_31 * V_61 ,
bool V_62 )
{
int V_17 ;
bool V_63 = ! F_93 ( V_15 ) && ! F_94 ( V_15 ) ;
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
static void F_97 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
unsigned long * V_36 ;
int V_18 = V_15 -> V_1 - V_65 ;
int V_17 = F_15 ( V_18 ) ;
T_3 * V_38 = & F_40 ( V_39 , V_17 ) ;
F_41 ( V_38 , V_37 ) ;
V_36 = & F_40 ( V_41 , V_17 ) ;
F_42 ( V_18 , V_36 ) ;
F_43 () ;
F_44 ( F_46 ( V_18 * 2 + 1 ) , * V_36 ) ;
F_47 ( V_38 , V_37 ) ;
}
static void F_98 ( struct V_14 * V_15 )
{
int V_18 = V_15 -> V_1 - V_65 ;
int V_17 = F_15 ( V_18 ) ;
F_56 ( V_18 , & F_40 ( V_41 , V_17 ) ) ;
F_44 ( F_58 ( V_18 * 2 + 1 ) , 1ull << V_18 ) ;
}
static bool F_99 ( unsigned int line , unsigned int V_2 )
{
bool V_66 = false ;
if ( line == 0 )
switch ( V_2 ) {
case 48 ... 49 :
case 50 :
case 52 ... 55 :
case 58 :
V_66 = true ;
break;
default:
break;
}
else
switch ( V_2 ) {
case 47 :
V_66 = true ;
break;
default:
break;
}
return V_66 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int type ;
unsigned int V_73 ;
unsigned int V_74 ;
if ( V_13 -> V_75 != V_68 )
return - V_64 ;
if ( V_70 < 2 )
return - V_64 ;
V_73 = V_69 [ 0 ] ;
if ( V_73 >= 16 )
return - V_64 ;
V_74 = V_69 [ 1 ] ;
switch ( V_74 ) {
case 1 :
type = V_76 ;
break;
case 2 :
type = V_53 ;
break;
case 4 :
type = V_77 ;
break;
case 8 :
type = V_52 ;
break;
default:
F_101 ( L_1 ,
V_68 -> V_78 ,
V_74 ) ;
type = V_52 ;
break;
}
* V_72 = type ;
* V_71 = V_73 ;
return 0 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int V_79 , V_2 ;
struct V_80 * V_81 = V_13 -> V_82 ;
V_79 = V_69 [ 0 ] ;
V_2 = V_69 [ 1 ] ;
if ( V_79 >= V_81 -> V_83 || V_2 > 63 )
return - V_64 ;
* V_71 = ( V_79 << 6 ) | V_2 ;
* V_72 = 0 ;
return 0 ;
}
static bool F_103 ( unsigned int V_84 )
{
if ( V_84 < ( 1ul << 8 * sizeof( V_11 [ 0 ] [ 0 ] ) ) )
return true ;
F_104 ( true , L_2 , V_84 ) ;
return false ;
}
static int F_105 ( struct V_12 * V_13 ,
unsigned int V_84 , T_7 V_85 )
{
int V_86 ;
unsigned int line = V_85 >> 6 ;
unsigned int V_2 = V_85 & 63 ;
struct V_80 * V_81 = V_13 -> V_82 ;
if ( ! F_103 ( V_84 ) )
return - V_64 ;
if ( line == 0 && V_2 >= 16 && V_2 < 32 )
return 0 ;
if ( line >= V_81 -> V_83 || V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
if ( line == 2 ) {
if ( F_99 ( line , V_2 ) )
V_86 = F_1 ( V_84 , line , V_2 , 0 ,
& V_87 ,
V_56 ) ;
else
V_86 = F_1 ( V_84 , line , V_2 , 0 ,
& V_88 ,
V_57 ) ;
} else {
if ( F_99 ( line , V_2 ) )
V_86 = F_1 ( V_84 , line , V_2 , 0 ,
V_89 ,
V_56 ) ;
else
V_86 = F_1 ( V_84 , line , V_2 , 0 ,
V_90 ,
V_57 ) ;
}
return V_86 ;
}
static int F_106 ( struct V_12 * V_13 ,
unsigned int V_84 , T_7 V_85 )
{
struct V_91 * V_92 = V_13 -> V_82 ;
unsigned int line , V_2 ;
int V_93 ;
if ( ! F_103 ( V_84 ) )
return - V_64 ;
line = ( V_85 + V_92 -> V_94 ) >> 6 ;
V_2 = ( V_85 + V_92 -> V_94 ) & 63 ;
if ( line > F_107 ( V_11 ) ||
V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
V_93 = F_1 ( V_84 , line , V_2 , V_85 ,
V_95 , V_57 ) ;
return V_93 ;
}
static void F_108 ( void )
{
const unsigned long V_96 = F_14 () ;
T_4 V_97 = F_109 ( F_72 ( V_96 * 2 ) ) ;
V_97 &= F_110 ( V_40 ) ;
if ( F_111 ( V_97 ) ) {
int V_2 = F_112 ( V_97 ) - 1 ;
int V_1 = V_11 [ 0 ] [ V_2 ] ;
if ( F_111 ( V_1 ) )
F_113 ( V_1 ) ;
else
F_114 () ;
} else {
F_114 () ;
}
}
static void F_115 ( void )
{
T_4 V_97 = F_109 ( V_43 ) ;
V_97 &= F_110 ( V_41 ) ;
if ( F_111 ( V_97 ) ) {
int V_2 = F_112 ( V_97 ) - 1 ;
int V_1 = V_11 [ 1 ] [ V_2 ] ;
if ( F_111 ( V_1 ) )
F_113 ( V_1 ) ;
else
F_114 () ;
} else {
F_114 () ;
}
}
static void F_116 ( void )
{
int V_18 = F_14 () ;
T_4 V_97 = F_109 ( F_64 ( V_18 ) ) ;
T_4 V_98 = F_109 ( F_117 ( V_18 ) ) ;
V_97 &= V_98 ;
if ( F_111 ( V_97 ) ) {
int V_2 = F_112 ( V_97 ) - 1 ;
int V_1 = V_11 [ 2 ] [ V_2 ] ;
if ( F_111 ( V_1 ) )
F_113 ( V_1 ) ;
else
F_114 () ;
} else {
F_114 () ;
}
}
static void F_118 ( void * V_20 )
{
F_22 ( V_99 ) ;
}
static void F_119 ( void )
{
F_19 ( V_99 ) ;
F_114 () ;
}
void F_120 ( T_8 V_100 )
{
V_101 = V_100 ;
V_102 = true ;
F_29 ( F_118 , NULL , 1 ) ;
}
static void F_121 ( void )
{
F_122 () ;
}
static void F_123 ( void )
{
int V_18 = F_14 () ;
F_124 ( V_40 , 0 ) ;
F_124 ( V_41 , 0 ) ;
F_43 () ;
F_125 ( F_49 ( & V_39 ) ) ;
F_44 ( F_45 ( ( V_18 * 2 ) ) , 0 ) ;
F_44 ( F_45 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_44 ( F_46 ( ( V_18 * 2 ) ) , 0 ) ;
F_44 ( F_46 ( ( V_18 * 2 + 1 ) ) , 0 ) ;
F_109 ( F_72 ( ( V_18 * 2 ) ) ) ;
}
static void F_126 ( void )
{
T_4 V_103 , V_104 ;
int V_18 = F_14 () ;
T_4 V_105 = F_127 ( V_18 ) ;
for ( V_103 = 0 ; V_103 <= 0x8000 ; V_103 += 0x1000 ) {
for ( V_104 = 0 ; V_104 <= 0x400 ; V_104 += 0x200 )
F_44 ( V_105 + V_103 + V_104 , 0 ) ;
}
F_109 ( F_128 ( V_18 ) ) ;
}
static void F_129 ( void )
{
F_123 () ;
F_121 () ;
F_22 ( V_106 | V_107 ) ;
if ( V_102 )
F_22 ( V_99 ) ;
else
F_19 ( V_99 ) ;
}
static void F_130 ( void )
{
F_126 () ;
F_121 () ;
F_22 ( V_106 | V_107 ) ;
if ( V_102 )
F_22 ( V_99 ) ;
else
F_19 ( V_99 ) ;
}
static int T_2 F_131 (
struct V_67 * V_108 , struct V_67 * V_109 )
{
unsigned int V_25 , V_93 ;
struct V_4 * V_5 ;
struct V_4 * V_110 ;
struct V_4 * V_111 ;
struct V_4 * V_112 ;
struct V_12 * V_113 = NULL ;
struct V_80 * V_81 ;
V_81 = F_2 ( sizeof( * V_81 ) , V_9 ) ;
if ( ! V_81 )
return - V_10 ;
F_123 () ;
V_114 = F_129 ;
V_115 = F_108 ;
V_116 = F_115 ;
if ( ( F_132 () || F_133 () )
&& ! F_134 ( V_117 ) ) {
V_101 = F_116 ;
V_81 -> V_83 = 3 ;
V_102 = true ;
} else {
V_101 = F_119 ;
V_81 -> V_83 = 2 ;
V_102 = false ;
}
if ( F_134 ( V_118 ) ||
F_134 ( V_119 ) ||
F_134 ( V_120 ) ||
F_132 () || F_133 () ) {
V_5 = & V_121 ;
V_110 = & V_122 ;
V_111 = & V_123 ;
V_112 = & V_124 ;
V_95 = & V_125 ;
} else {
V_5 = & V_126 ;
V_110 = & V_127 ;
V_111 = & V_128 ;
V_112 = & V_129 ;
V_95 = & V_130 ;
}
V_90 = V_5 ;
V_89 = V_110 ;
F_31 () ;
V_113 = F_135 (
V_108 , & V_131 , V_81 ) ;
F_136 ( V_113 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_132 , 0 , V_25 + 0 ) ;
if ( V_93 )
goto V_133;
}
V_93 = F_1 (
V_134 , 0 , 32 , 0 , V_111 , V_30 ) ;
if ( V_93 )
goto V_133;
V_93 = F_1 (
V_135 , 0 , 33 , 0 , V_111 , V_30 ) ;
if ( V_93 )
goto V_133;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_136 , 0 , V_25 + 36 ) ;
if ( V_93 )
goto V_133;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_137 , 0 , V_25 + 40 ) ;
if ( V_93 )
goto V_133;
}
V_93 = F_9 ( V_113 , V_138 , 0 , 45 ) ;
if ( V_93 )
goto V_133;
V_93 = F_9 ( V_113 , V_139 , 0 , 46 ) ;
if ( V_93 )
goto V_133;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_140 , 0 , V_25 + 52 ) ;
if ( V_93 )
goto V_133;
}
V_93 = F_9 ( V_113 , V_141 , 0 , 56 ) ;
if ( V_93 )
goto V_133;
V_93 = F_9 ( V_113 , V_142 , 0 , 59 ) ;
if ( V_93 )
goto V_133;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
V_93 = F_1 (
V_25 + V_65 , 1 , V_25 + 0 , 0 , V_112 ,
V_57 ) ;
if ( V_93 )
goto V_133;
}
V_93 = F_9 ( V_113 , V_143 , 1 , 17 ) ;
if ( V_93 )
goto V_133;
F_22 ( V_106 | V_107 ) ;
if ( V_102 )
F_22 ( V_99 ) ;
else
F_19 ( V_99 ) ;
return 0 ;
V_133:
return V_93 ;
}
static int T_2 F_137 (
struct V_67 * V_144 , struct V_67 * V_109 )
{
struct V_91 * V_92 ;
T_5 V_145 ;
unsigned int V_94 ;
int V_93 ;
V_93 = F_138 ( V_109 , L_3 , & V_145 ) ;
if ( V_93 )
return V_93 ;
if ( V_145 == 1 ) {
T_5 V_146 ;
V_93 = F_139 ( V_144 , L_4 , 0 , & V_146 ) ;
if ( V_93 ) {
F_140 ( L_5 ) ;
return V_93 ;
}
V_94 = V_146 ;
} else if ( V_145 == 2 ) {
T_5 V_147 , V_148 ;
V_93 = F_139 ( V_144 , L_4 , 0 , & V_147 ) ;
if ( V_93 ) {
F_140 ( L_5 ) ;
return V_93 ;
}
V_93 = F_139 ( V_144 , L_4 , 1 , & V_148 ) ;
if ( V_93 ) {
F_140 ( L_5 ) ;
return V_93 ;
}
V_94 = ( V_147 << 6 ) | V_148 ;
} else {
F_140 ( L_6 ,
V_145 ) ;
return - V_64 ;
}
V_92 = F_2 ( sizeof( * V_92 ) , V_9 ) ;
if ( V_92 ) {
V_92 -> V_94 = V_94 ;
F_141 (
V_144 , 16 , & V_149 , V_92 ) ;
} else {
F_140 ( L_7 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_142 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = V_15 -> V_1 - V_65 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_143 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_144 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_17 = F_33 ( V_15 ) ;
int V_18 = F_11 ( V_17 ) ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_143 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_145 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_143 ( V_18 ) +
( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_146 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
V_150 = F_147 ( V_18 ) +
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
V_150 = F_149 ( V_18 ) + ( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_150 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
V_21 = 1ull << ( V_8 -> V_2 ) ;
F_53 (cpu) {
T_4 V_150 = F_147 (
F_11 ( V_17 ) ) + ( 0x1000ull * V_8 -> line ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_151 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_134 ) ;
F_53 (cpu) {
T_4 V_150 = F_152 (
F_11 ( V_17 ) ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_153 ( struct V_14 * V_15 )
{
int V_17 ;
T_4 V_21 ;
V_21 = 1ull << ( V_15 -> V_1 - V_134 ) ;
F_53 (cpu) {
T_4 V_150 = F_154 (
F_11 ( V_17 ) ) ;
F_44 ( V_150 , V_21 ) ;
}
}
static void F_155 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_134 ) ;
V_150 = F_152 ( V_18 ) ;
F_44 ( V_150 , V_21 ) ;
}
static void F_156 ( struct V_14 * V_15 )
{
T_4 V_21 ;
T_4 V_150 ;
int V_18 = F_14 () ;
V_21 = 1ull << ( V_15 -> V_1 - V_134 ) ;
V_150 = F_154 ( V_18 ) ;
F_44 ( V_150 , V_21 ) ;
}
static int F_157 ( struct V_14 * V_15 ,
const struct V_31 * V_61 , bool V_62 )
{
int V_17 ;
bool V_63 = ! F_93 ( V_15 ) && ! F_94 ( V_15 ) ;
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
V_150 = F_143 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
} else {
V_150 = F_147 (
F_11 ( V_17 ) ) +
( 0x1000ull * V_8 -> line ) ;
}
F_44 ( V_150 , V_21 ) ;
}
return 0 ;
}
static void F_158 ( struct V_14 * V_15 )
{
F_75 ( V_15 ) ;
F_144 ( V_15 ) ;
}
static void F_159 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_15 ) ;
F_44 ( F_77 ( V_8 -> V_3 ) , 0 ) ;
F_150 ( V_15 ) ;
}
static int F_160 ( struct V_12 * V_13 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int V_79 , V_2 ;
V_79 = V_69 [ 0 ] ;
V_2 = V_69 [ 1 ] ;
* V_71 = ( V_79 << 6 ) | V_2 ;
* V_72 = 0 ;
return 0 ;
}
static bool F_161 ( unsigned int line , unsigned int V_2 )
{
bool V_66 = false ;
if ( line == 3 )
switch ( V_2 ) {
case 2 :
case 8 ... 11 :
case 48 :
V_66 = true ;
break;
default:
break;
}
else if ( line == 6 )
switch ( V_2 ) {
case 52 ... 53 :
case 8 ... 12 :
V_66 = true ;
break;
default:
break;
}
return V_66 ;
}
static int F_162 ( struct V_12 * V_13 ,
unsigned int V_84 , T_7 V_85 )
{
unsigned int line = V_85 >> 6 ;
unsigned int V_2 = V_85 & 63 ;
if ( ! F_103 ( V_84 ) )
return - V_64 ;
if ( line == 7 )
return 0 ;
if ( line > 7 || V_11 [ line ] [ V_2 ] != 0 )
return - V_64 ;
if ( F_161 ( line , V_2 ) )
F_1 ( V_84 , line , V_2 , 0 ,
& V_151 ,
V_56 ) ;
else
F_1 ( V_84 , line , V_2 , 0 ,
& V_152 ,
V_57 ) ;
return 0 ;
}
static void F_163 ( void )
{
int line ;
int V_2 ;
int V_1 ;
T_4 V_153 , V_154 , V_155 ;
const unsigned long V_96 = F_14 () ;
V_155 = F_109 ( F_128 ( V_96 ) ) & 0xfful ;
if ( F_164 ( ! V_155 ) )
goto V_156;
line = F_112 ( V_155 ) - 1 ;
V_153 = F_165 ( V_96 ) + ( 0x1000 * line ) ;
V_154 = F_109 ( V_153 ) ;
if ( F_164 ( ! V_154 ) )
goto V_156;
V_2 = F_112 ( V_154 ) - 1 ;
V_1 = V_11 [ line ] [ V_2 ] ;
if ( F_164 ( ! V_1 ) )
goto V_156;
F_113 ( V_1 ) ;
goto V_157;
V_156:
F_114 () ;
V_157:
if ( F_134 ( V_158 ) )
F_109 ( V_159 ) ;
else
F_109 ( F_166 ( V_96 ) ) ;
return;
}
static void F_167 ( void )
{
int line ;
const unsigned long V_96 = F_14 () ;
T_4 V_155 = F_109 ( F_168 ( V_96 ) ) >> 60 ;
if ( F_164 ( ! V_155 ) )
goto V_156;
line = F_112 ( V_155 ) - 1 ;
F_113 ( V_134 + line ) ;
goto V_157;
V_156:
F_114 () ;
V_157:
if ( F_134 ( V_158 ) )
F_109 ( V_159 ) ;
else
F_109 ( F_169 ( V_96 ) ) ;
return;
}
static int T_2 F_170 (
struct V_67 * V_108 , struct V_67 * V_109 )
{
unsigned int V_25 , V_93 ;
struct V_12 * V_113 = NULL ;
F_126 () ;
V_114 = F_130 ;
V_95 = & V_160 ;
V_115 = F_163 ;
V_116 = F_167 ;
V_101 = F_119 ;
F_31 () ;
V_113 = F_135 (
V_108 , & V_161 , NULL ) ;
F_136 ( V_113 ) ;
for ( V_25 = 0 ; V_25 < 64 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_132 , 0 , V_25 ) ;
if ( V_93 )
goto V_133;
}
for ( V_25 = 0 ; V_25 < 32 ; V_25 ++ ) {
V_93 = F_1 ( V_25 + V_65 , 1 , V_25 , 0 ,
& V_162 , V_57 ) ;
if ( V_93 )
goto V_133;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_140 , 3 , V_25 + 8 ) ;
if ( V_93 )
goto V_133;
}
V_93 = F_9 ( V_113 , V_141 , 3 , 44 ) ;
if ( V_93 )
goto V_133;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_136 , 4 , V_25 ) ;
if ( V_93 )
goto V_133;
}
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_93 = F_9 (
V_113 , V_25 + V_137 , 4 , V_25 + 8 ) ;
if ( V_93 )
goto V_133;
}
F_3 ( V_134 , & V_163 , V_30 ) ;
F_3 ( V_135 , & V_163 , V_30 ) ;
F_3 ( V_164 , & V_163 , V_30 ) ;
F_3 ( V_165 , & V_163 , V_30 ) ;
F_22 ( V_106 | V_107 ) ;
F_19 ( V_99 ) ;
return 0 ;
V_133:
return V_93 ;
}
static void F_171 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_166 ;
struct V_167 * V_8 = F_7 ( V_15 ) ;
struct V_168 * V_82 = V_8 -> V_82 ;
F_41 ( & V_82 -> V_38 , V_37 ) ;
V_166 = F_109 ( V_82 -> V_169 ) ;
V_166 |= 1ull << V_8 -> V_2 ;
F_44 ( V_82 -> V_169 , V_166 ) ;
F_47 ( & V_82 -> V_38 , V_37 ) ;
}
static void F_172 ( struct V_14 * V_15 )
{
unsigned long V_37 ;
T_4 V_166 ;
struct V_167 * V_8 = F_7 ( V_15 ) ;
struct V_168 * V_82 = V_8 -> V_82 ;
F_41 ( & V_82 -> V_38 , V_37 ) ;
V_166 = F_109 ( V_82 -> V_169 ) ;
V_166 &= ~ ( 1ull << V_8 -> V_2 ) ;
F_44 ( V_82 -> V_169 , V_166 ) ;
F_47 ( & V_82 -> V_38 , V_37 ) ;
}
static int F_173 ( struct V_14 * V_15 , unsigned int V_46 )
{
F_81 ( V_15 , V_46 ) ;
return V_58 ;
}
static int F_174 ( struct V_12 * V_13 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int type = 0 ;
if ( V_70 == 2 )
type = V_69 [ 1 ] ;
switch ( type ) {
case 0 :
case 4 :
* V_72 = V_77 ;
break;
case 1 :
* V_72 = V_76 ;
break;
default:
return - V_64 ;
}
* V_71 = V_69 [ 0 ] ;
return 0 ;
}
static int F_175 ( struct V_12 * V_13 ,
unsigned int V_84 , T_7 V_85 )
{
struct V_168 * V_82 = V_13 -> V_82 ;
struct V_167 * V_8 ;
if ( V_85 >= V_82 -> V_170 ) {
F_101 ( L_8 ,
V_13 -> V_75 -> V_78 , ( unsigned ) V_85 ) ;
return - V_64 ;
}
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
V_8 -> V_82 = V_82 ;
V_8 -> V_2 = V_85 ;
F_3 ( V_84 , & V_171 ,
V_172 ) ;
F_4 ( V_84 , V_8 ) ;
return 0 ;
}
static T_9 F_176 ( int V_173 , void * V_15 )
{
T_4 V_166 ;
T_4 V_174 ;
T_4 V_175 ;
int V_25 ;
int V_1 ;
struct V_12 * V_176 = V_15 ;
struct V_168 * V_82 = V_176 -> V_82 ;
V_166 = F_109 ( V_82 -> V_169 ) ;
V_174 = F_109 ( V_82 -> V_177 ) ;
V_175 = V_166 & V_174 ;
for ( V_25 = 0 ; V_25 < V_82 -> V_170 ; V_25 ++ ) {
if ( ( V_175 & 1ull << V_25 ) == 0 )
continue;
V_1 = F_177 ( V_176 , V_25 ) ;
if ( ! V_1 ) {
unsigned long V_37 ;
F_101 ( L_9 ,
V_25 , V_82 -> V_177 ) ;
F_41 ( & V_82 -> V_38 , V_37 ) ;
V_166 = F_109 ( V_82 -> V_169 ) ;
V_166 &= ~ ( 1ull << V_25 ) ;
F_44 ( V_82 -> V_169 , V_166 ) ;
F_44 ( V_82 -> V_177 , 1ull << V_25 ) ;
F_47 ( & V_82 -> V_38 , V_37 ) ;
} else {
struct V_178 * V_179 = F_178 ( V_1 ) ;
struct V_14 * V_14 = F_179 ( V_179 ) ;
if ( F_76 ( V_14 ) &
V_50 )
F_44 ( V_82 -> V_177 , 1ull << V_25 ) ;
F_180 ( V_179 ) ;
}
}
return V_180 ;
}
static int T_2 F_181 ( struct V_67 * V_108 ,
struct V_67 * V_109 )
{
const T_10 * V_181 ;
T_5 V_182 ;
struct V_168 * V_82 ;
int V_183 ;
int V_93 ;
struct V_12 * V_176 ;
V_183 = F_182 ( V_108 , 0 ) ;
if ( ! V_183 ) {
F_101 ( L_10 ,
V_108 -> V_78 ) ;
return - V_64 ;
}
V_82 = F_2 ( sizeof( * V_82 ) , V_9 ) ;
F_125 ( & V_82 -> V_38 ) ;
V_181 = F_183 ( V_108 , 0 , NULL , NULL ) ;
if ( ! V_181 ) {
F_101 ( L_11 , V_108 -> V_78 ) ;
return - V_64 ;
}
V_82 -> V_177 = ( T_4 ) F_184 (
F_185 ( V_108 , V_181 ) ) ;
V_181 = F_183 ( V_108 , 1 , NULL , NULL ) ;
if ( ! V_181 ) {
F_101 ( L_12 , V_108 -> V_78 ) ;
return - V_64 ;
}
V_82 -> V_169 = ( T_4 ) F_184 (
F_185 ( V_108 , V_181 ) ) ;
V_93 = F_138 ( V_108 , L_13 , & V_182 ) ;
if ( V_93 ) {
F_101 ( L_14 ,
V_108 -> V_78 ) ;
return V_93 ;
}
V_82 -> V_170 = V_182 ;
V_176 = F_141 ( V_108 , V_82 -> V_170 ,
& V_184 ,
V_82 ) ;
if ( ! V_176 ) {
F_101 ( L_15 ) ;
return - V_10 ;
}
F_44 ( V_82 -> V_169 , 0 ) ;
F_44 ( V_82 -> V_177 , ~ 0 ) ;
V_93 = F_186 ( V_183 , F_176 ,
V_185 , L_16 , V_176 ) ;
if ( V_93 ) {
F_101 ( L_17 , V_93 ) ;
return V_93 ;
}
F_187 ( L_18 ,
V_82 -> V_177 , V_82 -> V_170 ) ;
return 0 ;
}
void T_2 F_188 ( void )
{
#ifdef F_12
F_89 ( V_186 ) ;
F_90 ( F_17 () , V_186 ) ;
#endif
F_189 ( V_187 ) ;
}
T_11 void F_190 ( void )
{
unsigned long V_188 ;
unsigned long V_189 ;
while ( 1 ) {
V_188 = F_191 () ;
V_189 = F_192 () ;
V_188 &= V_189 ;
V_188 &= V_190 ;
if ( V_188 & V_107 )
V_115 () ;
else if ( V_188 & V_106 )
V_116 () ;
else if ( V_188 & V_99 )
V_101 () ;
else if ( V_188 )
F_113 ( F_193 ( V_188 ) - 9 + V_191 ) ;
else
break;
}
}
void F_194 ( void )
{
F_195 () ;
}
