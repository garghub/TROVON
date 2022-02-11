static void F_1 ( int V_1 , int line , int V_2 , int V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
union V_7 V_8 ;
F_2 ( V_1 , V_5 , V_6 ) ;
V_8 . V_9 = 0 ;
V_8 . V_10 . line = line ;
V_8 . V_10 . V_2 = V_2 ;
V_8 . V_10 . V_3 = V_3 ;
F_3 ( V_1 , V_8 . V_11 ) ;
V_12 [ line ] [ V_2 ] = V_1 ;
}
static void F_4 ( struct V_13 * V_14 ,
int V_1 , int line , int V_2 )
{
F_5 ( V_14 , V_1 , line << 6 | V_2 ) ;
}
static int F_6 ( int V_15 )
{
#ifdef F_7
return F_8 ( V_15 ) ;
#else
return F_9 () ;
#endif
}
static int F_10 ( int V_16 )
{
#ifdef F_7
return F_11 ( V_16 ) ;
#else
return F_12 () ;
#endif
}
static void F_13 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
unsigned int V_2 = V_8 -> V_2 ;
F_15 ( 0x100 << V_2 ) ;
if ( V_2 < 2 )
F_16 ( 0x100 << V_2 ) ;
}
static void F_17 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
F_18 ( 0x100 << V_8 -> V_2 ) ;
}
static void F_19 ( void * V_20 )
{
struct V_17 * V_18 = V_20 ;
struct V_19 * V_8 = F_14 ( V_18 ) ;
unsigned int V_21 = 0x100 << V_8 -> V_2 ;
if ( V_8 -> V_22 )
F_18 ( V_21 ) ;
else
F_15 ( V_21 ) ;
}
static void F_20 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
V_8 -> V_22 = false ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
V_8 -> V_22 = true ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
F_23 ( & V_8 -> V_23 ) ;
}
static void F_24 ( struct V_17 * V_18 )
{
struct V_19 * V_8 = F_14 ( V_18 ) ;
if ( V_8 -> V_22 != V_8 -> V_24 ) {
F_25 ( F_19 , V_18 , 1 ) ;
V_8 -> V_24 = V_8 -> V_22 ;
}
F_26 ( & V_8 -> V_23 ) ;
}
static void T_2 F_27 ( void )
{
int V_25 ;
int V_1 ;
struct V_19 * V_8 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_8 = & V_27 [ V_25 ] ;
V_8 -> V_24 = false ;
V_8 -> V_22 = false ;
V_8 -> V_2 = V_25 ;
F_28 ( & V_8 -> V_23 ) ;
V_1 = V_28 + V_25 ;
F_3 ( V_1 , V_8 ) ;
F_2 ( V_1 , & V_29 ,
V_30 ) ;
}
}
static int F_29 ( struct V_17 * V_18 )
{
#ifdef F_7
int V_15 ;
int V_31 = F_30 ( V_18 -> V_32 ) ;
if ( V_31 > 1 ) {
V_15 = F_12 () ;
for (; ; ) {
V_15 = F_31 ( V_15 , V_18 -> V_32 ) ;
if ( V_15 >= V_33 ) {
V_15 = - 1 ;
continue;
} else if ( F_32 ( V_15 , V_34 ) ) {
break;
}
}
} else if ( V_31 == 1 ) {
V_15 = F_33 ( V_18 -> V_32 ) ;
} else {
V_15 = F_12 () ;
}
return V_15 ;
#else
return F_12 () ;
#endif
}
static void F_34 ( struct V_17 * V_18 )
{
int V_15 = F_29 ( V_18 ) ;
int V_16 = F_6 ( V_15 ) ;
unsigned long * V_35 ;
unsigned long V_36 ;
union V_7 V_8 ;
T_3 * V_37 = & F_35 ( V_38 , V_15 ) ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_36 ( V_37 , V_36 ) ;
if ( V_8 . V_10 . line == 0 ) {
V_35 = & F_35 ( V_39 , V_15 ) ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_40 ( V_16 * 2 ) , * V_35 ) ;
} else {
V_35 = & F_35 ( V_40 , V_15 ) ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_41 ( V_16 * 2 + 1 ) , * V_35 ) ;
}
F_42 ( V_37 , V_36 ) ;
}
static void F_43 ( struct V_17 * V_18 )
{
unsigned long * V_35 ;
unsigned long V_36 ;
union V_7 V_8 ;
T_3 * V_37 = & F_44 ( V_38 ) ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_36 ( V_37 , V_36 ) ;
if ( V_8 . V_10 . line == 0 ) {
V_35 = & F_44 ( V_39 ) ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_40 ( F_9 () * 2 ) , * V_35 ) ;
} else {
V_35 = & F_44 ( V_40 ) ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_41 ( F_9 () * 2 + 1 ) , * V_35 ) ;
}
F_42 ( V_37 , V_36 ) ;
}
static void F_45 ( struct V_17 * V_18 )
{
unsigned long * V_35 ;
unsigned long V_36 ;
union V_7 V_8 ;
T_3 * V_37 = & F_44 ( V_38 ) ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_36 ( V_37 , V_36 ) ;
if ( V_8 . V_10 . line == 0 ) {
V_35 = & F_44 ( V_39 ) ;
F_46 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_40 ( F_9 () * 2 ) , * V_35 ) ;
} else {
V_35 = & F_44 ( V_40 ) ;
F_46 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
F_39 ( F_41 ( F_9 () * 2 + 1 ) , * V_35 ) ;
}
F_42 ( V_37 , V_36 ) ;
}
static void F_47 ( struct V_17 * V_18 )
{
unsigned long V_36 ;
unsigned long * V_35 ;
int V_15 ;
union V_7 V_8 ;
T_3 * V_37 ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_48 (cpu) {
int V_16 = F_6 ( V_15 ) ;
V_37 = & F_35 ( V_38 , V_15 ) ;
if ( V_8 . V_10 . line == 0 )
V_35 = & F_35 ( V_39 , V_15 ) ;
else
V_35 = & F_35 ( V_40 , V_15 ) ;
F_36 ( V_37 , V_36 ) ;
F_46 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
if ( V_8 . V_10 . line == 0 )
F_39 ( F_40 ( V_16 * 2 ) , * V_35 ) ;
else
F_39 ( F_41 ( V_16 * 2 + 1 ) , * V_35 ) ;
F_42 ( V_37 , V_36 ) ;
}
}
static void F_49 ( struct V_17 * V_18 )
{
unsigned long V_36 ;
unsigned long * V_35 ;
int V_15 ;
union V_7 V_8 ;
T_3 * V_37 ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_48 (cpu) {
int V_16 = F_6 ( V_15 ) ;
V_37 = & F_35 ( V_38 , V_15 ) ;
if ( V_8 . V_10 . line == 0 )
V_35 = & F_35 ( V_39 , V_15 ) ;
else
V_35 = & F_35 ( V_40 , V_15 ) ;
F_36 ( V_37 , V_36 ) ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
F_38 () ;
if ( V_8 . V_10 . line == 0 )
F_39 ( F_40 ( V_16 * 2 ) , * V_35 ) ;
else
F_39 ( F_41 ( V_16 * 2 + 1 ) , * V_35 ) ;
F_42 ( V_37 , V_36 ) ;
}
}
static void F_50 ( struct V_17 * V_18 )
{
T_4 V_21 ;
int V_15 = F_29 ( V_18 ) ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
int V_41 = F_6 ( V_15 ) * 2 ;
F_51 ( V_8 . V_10 . V_2 , & F_35 ( V_39 , V_15 ) ) ;
F_39 ( F_52 ( V_41 ) , V_21 ) ;
} else {
int V_41 = F_6 ( V_15 ) * 2 + 1 ;
F_51 ( V_8 . V_10 . V_2 , & F_35 ( V_40 , V_15 ) ) ;
F_39 ( F_53 ( V_41 ) , V_21 ) ;
}
}
static void F_54 ( struct V_17 * V_18 )
{
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
int V_41 = F_9 () * 2 ;
F_51 ( V_8 . V_10 . V_2 , & F_44 ( V_39 ) ) ;
F_39 ( F_52 ( V_41 ) , V_21 ) ;
} else {
int V_41 = F_9 () * 2 + 1 ;
F_51 ( V_8 . V_10 . V_2 , & F_44 ( V_40 ) ) ;
F_39 ( F_53 ( V_41 ) , V_21 ) ;
}
}
static void F_55 ( struct V_17 * V_18 )
{
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
int V_41 = F_9 () * 2 ;
F_56 ( V_8 . V_10 . V_2 , & F_44 ( V_39 ) ) ;
F_39 ( F_57 ( V_41 ) , V_21 ) ;
} else {
int V_41 = F_9 () * 2 + 1 ;
F_56 ( V_8 . V_10 . V_2 , & F_44 ( V_40 ) ) ;
F_39 ( F_58 ( V_41 ) , V_21 ) ;
}
}
static void F_59 ( struct V_17 * V_18 )
{
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
int V_41 = F_9 () * 2 ;
F_39 ( F_60 ( V_41 ) , V_21 ) ;
} else {
F_39 ( V_42 , V_21 ) ;
}
}
static void F_61 ( struct V_17 * V_18 )
{
int V_15 ;
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
F_48 (cpu) {
int V_41 = F_6 ( V_15 ) * 2 ;
F_56 ( V_8 . V_10 . V_2 , & F_35 ( V_39 , V_15 ) ) ;
F_39 ( F_57 ( V_41 ) , V_21 ) ;
}
} else {
F_48 (cpu) {
int V_41 = F_6 ( V_15 ) * 2 + 1 ;
F_56 ( V_8 . V_10 . V_2 , & F_35 ( V_40 , V_15 ) ) ;
F_39 ( F_58 ( V_41 ) , V_21 ) ;
}
}
}
static void F_62 ( struct V_17 * V_18 )
{
int V_15 ;
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
if ( V_8 . V_10 . line == 0 ) {
F_48 (cpu) {
int V_41 = F_6 ( V_15 ) * 2 ;
F_51 ( V_8 . V_10 . V_2 , & F_35 ( V_39 , V_15 ) ) ;
F_39 ( F_52 ( V_41 ) , V_21 ) ;
}
} else {
F_48 (cpu) {
int V_41 = F_6 ( V_15 ) * 2 + 1 ;
F_51 ( V_8 . V_10 . V_2 , & F_35 ( V_40 , V_15 ) ) ;
F_39 ( F_53 ( V_41 ) , V_21 ) ;
}
}
}
static void F_63 ( struct V_17 * V_18 )
{
union V_43 V_44 ;
union V_7 V_8 ;
T_5 V_45 = F_64 ( V_18 ) ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_44 . T_4 = 0 ;
V_44 . V_10 . V_46 = 1 ;
V_44 . V_10 . V_47 = ( V_45 & V_48 ) != 0 ;
V_44 . V_10 . V_49 = ( V_45 & ( V_50 | V_51 ) ) != 0 ;
V_44 . V_10 . V_52 = 7 ;
V_44 . V_10 . V_53 = 3 ;
F_39 ( F_65 ( V_8 . V_10 . V_3 ) , V_44 . T_4 ) ;
}
static void F_66 ( struct V_17 * V_18 )
{
F_63 ( V_18 ) ;
F_50 ( V_18 ) ;
}
static void F_67 ( struct V_17 * V_18 )
{
F_63 ( V_18 ) ;
F_34 ( V_18 ) ;
}
static int F_68 ( struct V_17 * V_18 , unsigned int V_45 )
{
F_69 ( V_18 , V_45 ) ;
F_63 ( V_18 ) ;
return V_54 ;
}
static void F_70 ( struct V_17 * V_18 )
{
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_39 ( F_65 ( V_8 . V_10 . V_3 ) , 0 ) ;
F_61 ( V_18 ) ;
}
static void F_71 ( struct V_17 * V_18 )
{
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_39 ( F_65 ( V_8 . V_10 . V_3 ) , 0 ) ;
F_47 ( V_18 ) ;
}
static void F_72 ( struct V_17 * V_18 )
{
union V_7 V_8 ;
T_4 V_21 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_3 ) ;
F_39 ( V_55 , V_21 ) ;
}
static void F_73 ( unsigned int V_1 , struct V_56 * V_57 )
{
if ( F_74 ( V_1 ) & V_48 )
F_75 ( V_1 , V_57 ) ;
else
F_76 ( V_1 , V_57 ) ;
}
static void F_77 ( struct V_17 * V_18 )
{
int V_15 = F_12 () ;
T_6 V_58 ;
if ( ! F_32 ( V_15 , V_18 -> V_32 ) )
return;
if ( F_30 ( V_18 -> V_32 ) > 1 ) {
F_78 ( & V_58 , V_18 -> V_32 ) ;
F_79 ( V_15 , & V_58 ) ;
} else {
F_80 ( & V_58 ) ;
F_81 ( F_33 ( V_34 ) , & V_58 ) ;
}
F_82 ( V_18 , & V_58 ) ;
}
static int F_83 ( struct V_17 * V_18 ,
const struct V_59 * V_60 , bool V_61 )
{
int V_15 ;
bool V_62 = ! F_84 ( V_18 ) && ! F_85 ( V_18 ) ;
unsigned long V_36 ;
union V_7 V_8 ;
unsigned long * V_35 ;
T_3 * V_37 ;
V_8 . V_11 = F_14 ( V_18 ) ;
if ( F_30 ( V_60 ) != 1 )
return - V_63 ;
if ( ! V_62 )
return 0 ;
F_48 (cpu) {
int V_16 = F_6 ( V_15 ) ;
V_37 = & F_35 ( V_38 , V_15 ) ;
F_36 ( V_37 , V_36 ) ;
if ( V_8 . V_10 . line == 0 )
V_35 = & F_35 ( V_39 , V_15 ) ;
else
V_35 = & F_35 ( V_40 , V_15 ) ;
if ( F_32 ( V_15 , V_60 ) && V_62 ) {
V_62 = 0 ;
F_37 ( V_8 . V_10 . V_2 , V_35 ) ;
} else {
F_46 ( V_8 . V_10 . V_2 , V_35 ) ;
}
F_38 () ;
if ( V_8 . V_10 . line == 0 )
F_39 ( F_40 ( V_16 * 2 ) , * V_35 ) ;
else
F_39 ( F_41 ( V_16 * 2 + 1 ) , * V_35 ) ;
F_42 ( V_37 , V_36 ) ;
}
return 0 ;
}
static int F_86 ( struct V_17 * V_18 ,
const struct V_59 * V_60 ,
bool V_61 )
{
int V_15 ;
bool V_62 = ! F_84 ( V_18 ) && ! F_85 ( V_18 ) ;
T_4 V_21 ;
union V_7 V_8 ;
if ( ! V_62 )
return 0 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << V_8 . V_10 . V_2 ;
if ( V_8 . V_10 . line == 0 ) {
F_48 (cpu) {
unsigned long * V_35 = & F_35 ( V_39 , V_15 ) ;
int V_41 = F_6 ( V_15 ) * 2 ;
if ( F_32 ( V_15 , V_60 ) && V_62 ) {
V_62 = false ;
F_51 ( V_8 . V_10 . V_2 , V_35 ) ;
F_39 ( F_52 ( V_41 ) , V_21 ) ;
} else {
F_56 ( V_8 . V_10 . V_2 , V_35 ) ;
F_39 ( F_57 ( V_41 ) , V_21 ) ;
}
}
} else {
F_48 (cpu) {
unsigned long * V_35 = & F_35 ( V_40 , V_15 ) ;
int V_41 = F_6 ( V_15 ) * 2 + 1 ;
if ( F_32 ( V_15 , V_60 ) && V_62 ) {
V_62 = false ;
F_51 ( V_8 . V_10 . V_2 , V_35 ) ;
F_39 ( F_53 ( V_41 ) , V_21 ) ;
} else {
F_56 ( V_8 . V_10 . V_2 , V_35 ) ;
F_39 ( F_58 ( V_41 ) , V_21 ) ;
}
}
}
return 0 ;
}
static void F_87 ( struct V_17 * V_18 )
{
unsigned long V_36 ;
unsigned long * V_35 ;
int V_16 = V_18 -> V_1 - V_64 ;
int V_15 = F_10 ( V_16 ) ;
T_3 * V_37 = & F_35 ( V_38 , V_15 ) ;
F_36 ( V_37 , V_36 ) ;
V_35 = & F_35 ( V_40 , V_15 ) ;
F_37 ( V_16 , V_35 ) ;
F_38 () ;
F_39 ( F_41 ( V_16 * 2 + 1 ) , * V_35 ) ;
F_42 ( V_37 , V_36 ) ;
}
static void F_88 ( struct V_17 * V_18 )
{
int V_16 = V_18 -> V_1 - V_64 ;
int V_15 = F_10 ( V_16 ) ;
F_51 ( V_16 , & F_35 ( V_40 , V_15 ) ) ;
F_39 ( F_53 ( V_16 * 2 + 1 ) , 1ull << V_16 ) ;
}
static bool F_89 ( unsigned int line , unsigned int V_2 )
{
bool V_65 = false ;
if ( line == 0 )
switch ( V_2 ) {
case 48 ... 49 :
case 50 :
case 52 ... 55 :
case 58 :
V_65 = true ;
break;
default:
break;
}
else
switch ( V_2 ) {
case 47 :
V_65 = true ;
break;
default:
break;
}
return V_65 ;
}
static int F_90 ( struct V_13 * V_66 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int type ;
unsigned int V_73 ;
unsigned int V_74 ;
if ( V_66 -> V_75 != V_68 )
return - V_63 ;
if ( V_70 < 2 )
return - V_63 ;
V_73 = V_69 [ 0 ] ;
if ( V_73 >= 16 )
return - V_63 ;
V_74 = V_69 [ 1 ] ;
switch ( V_74 ) {
case 1 :
type = V_76 ;
break;
case 2 :
type = V_51 ;
break;
case 4 :
type = V_77 ;
break;
case 8 :
type = V_50 ;
break;
default:
F_91 ( L_1 ,
V_68 -> V_78 ,
V_74 ) ;
type = V_50 ;
break;
}
* V_72 = type ;
* V_71 = V_73 ;
return 0 ;
}
static int F_92 ( struct V_13 * V_66 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int V_79 , V_2 ;
V_79 = V_69 [ 0 ] ;
V_2 = V_69 [ 1 ] ;
if ( V_79 > 1 || V_2 > 63 )
return - V_63 ;
if ( V_79 == 0 && V_2 >= 16 && V_2 < 32 )
return - V_63 ;
* V_71 = ( V_79 << 6 ) | V_2 ;
* V_72 = 0 ;
return 0 ;
}
static bool F_93 ( unsigned int V_80 )
{
if ( V_80 < ( 1ul << 8 * sizeof( V_12 [ 0 ] [ 0 ] ) ) )
return true ;
F_94 ( true , L_2 , V_80 ) ;
return false ;
}
static int F_95 ( struct V_13 * V_66 ,
unsigned int V_80 , T_7 V_81 )
{
unsigned int line = V_81 >> 6 ;
unsigned int V_2 = V_81 & 63 ;
if ( ! F_93 ( V_80 ) )
return - V_63 ;
if ( line > 1 || V_12 [ line ] [ V_2 ] != 0 )
return - V_63 ;
if ( F_89 ( line , V_2 ) )
F_1 ( V_80 , line , V_2 , 0 ,
V_82 ,
F_75 ) ;
else
F_1 ( V_80 , line , V_2 , 0 ,
V_82 ,
F_76 ) ;
return 0 ;
}
static int F_96 ( struct V_13 * V_66 ,
unsigned int V_80 , T_7 V_81 ,
int V_83 , struct V_4 * V_5 )
{
struct V_84 * V_85 = V_66 -> V_86 ;
unsigned int line , V_2 ;
if ( ! F_93 ( V_80 ) )
return - V_63 ;
line = ( V_81 + V_85 -> V_87 ) >> 6 ;
V_2 = ( V_81 + V_85 -> V_87 ) & 63 ;
if ( line > V_83 || V_12 [ line ] [ V_2 ] != 0 )
return - V_63 ;
F_1 ( V_80 , line , V_2 , V_81 ,
V_5 , F_73 ) ;
return 0 ;
}
static int F_97 ( struct V_13 * V_66 ,
unsigned int V_80 , T_7 V_81 )
{
return F_96 ( V_66 , V_80 , V_81 , 1 , V_88 ) ;
}
static void F_98 ( void )
{
const unsigned long V_89 = F_9 () ;
T_4 V_90 = F_99 ( F_60 ( V_89 * 2 ) ) ;
V_90 &= F_44 ( V_39 ) ;
if ( F_100 ( V_90 ) ) {
int V_2 = F_101 ( V_90 ) - 1 ;
int V_1 = V_12 [ 0 ] [ V_2 ] ;
if ( F_100 ( V_1 ) )
F_102 ( V_1 ) ;
else
F_103 () ;
} else {
F_103 () ;
}
}
static void F_104 ( void )
{
T_4 V_90 = F_99 ( V_42 ) ;
V_90 &= F_44 ( V_40 ) ;
if ( F_100 ( V_90 ) ) {
int V_2 = F_101 ( V_90 ) - 1 ;
int V_1 = V_12 [ 1 ] [ V_2 ] ;
if ( F_100 ( V_1 ) )
F_102 ( V_1 ) ;
else
F_103 () ;
} else {
F_103 () ;
}
}
static void F_105 ( void * V_20 )
{
F_18 ( V_91 ) ;
}
static void F_106 ( void )
{
F_15 ( V_91 ) ;
F_103 () ;
}
void F_107 ( T_8 V_92 )
{
V_93 = V_92 ;
V_94 = true ;
F_25 ( F_105 , NULL , 1 ) ;
}
static void F_108 ( void )
{
F_109 () ;
}
static void F_110 ( void )
{
int V_16 = F_9 () ;
F_44 ( V_39 ) = 0 ;
F_44 ( V_40 ) = 0 ;
F_38 () ;
F_111 ( & F_44 ( V_38 ) ) ;
F_39 ( F_40 ( ( V_16 * 2 ) ) , 0 ) ;
F_39 ( F_40 ( ( V_16 * 2 + 1 ) ) , 0 ) ;
F_39 ( F_41 ( ( V_16 * 2 ) ) , 0 ) ;
F_39 ( F_41 ( ( V_16 * 2 + 1 ) ) , 0 ) ;
F_99 ( F_60 ( ( V_16 * 2 ) ) ) ;
}
static void F_112 ( void )
{
T_4 V_95 , V_96 ;
int V_16 = F_9 () ;
T_4 V_97 = F_113 ( V_16 ) ;
for ( V_95 = 0 ; V_95 <= 0x8000 ; V_95 += 0x1000 ) {
for ( V_96 = 0 ; V_96 <= 0x400 ; V_96 += 0x200 )
F_39 ( V_97 + V_95 + V_96 , 0 ) ;
}
F_99 ( F_114 ( V_16 ) ) ;
}
static void F_115 ( void )
{
F_110 () ;
F_108 () ;
F_18 ( V_98 | V_99 ) ;
F_15 ( V_91 ) ;
}
static void F_116 ( void )
{
F_112 () ;
F_108 () ;
F_18 ( V_98 | V_99 ) ;
if ( V_94 )
F_18 ( V_91 ) ;
else
F_15 ( V_91 ) ;
}
static void T_2 F_117 ( void )
{
unsigned int V_25 ;
struct V_4 * V_5 ;
struct V_4 * V_100 ;
struct V_4 * V_101 ;
struct V_67 * V_102 ;
struct V_67 * V_103 ;
struct V_13 * V_104 = NULL ;
F_110 () ;
V_105 = F_115 ;
V_106 = F_98 ;
V_107 = F_104 ;
if ( F_118 ( V_108 ) ||
F_118 ( V_109 ) ||
F_118 ( V_110 ) ||
F_118 ( V_111 ) ) {
V_5 = & V_112 ;
V_100 = & V_113 ;
V_101 = & V_114 ;
V_88 = & V_115 ;
} else {
V_5 = & V_116 ;
V_100 = & V_117 ;
V_101 = & V_118 ;
V_88 = & V_119 ;
}
V_82 = V_5 ;
V_93 = F_106 ;
F_27 () ;
V_102 = F_119 ( NULL , NULL , L_3 ) ;
if ( V_102 ) {
struct V_84 * V_85 ;
V_85 = F_120 ( sizeof( * V_85 ) , V_120 ) ;
if ( V_85 ) {
V_85 -> V_87 = 16 ;
F_121 ( V_102 , 16 , & V_121 , V_85 ) ;
F_122 ( V_102 ) ;
} else
F_123 ( L_4 ) ;
} else
F_123 ( L_5 ) ;
V_103 = F_119 ( NULL , NULL , L_6 ) ;
if ( V_103 ) {
V_104 = F_124 ( V_103 , & V_122 , NULL ) ;
F_125 ( V_104 ) ;
F_122 ( V_103 ) ;
} else
F_126 ( L_7 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_123 , 0 , V_25 + 0 ) ;
F_1 ( V_124 , 0 , 32 , 0 , V_100 , V_30 ) ;
F_1 ( V_125 , 0 , 33 , 0 , V_100 , V_30 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_126 , 0 , V_25 + 36 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_127 , 0 , V_25 + 40 ) ;
F_4 ( V_104 , V_128 , 0 , 46 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_129 , 0 , V_25 + 52 ) ;
F_4 ( V_104 , V_130 , 0 , 56 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
F_1 ( V_25 + V_64 , 1 , V_25 + 0 , 0 , V_101 , F_76 ) ;
F_4 ( V_104 , V_131 , 1 , 17 ) ;
F_18 ( V_98 | V_99 ) ;
F_15 ( V_91 ) ;
}
static void F_127 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = V_18 -> V_1 - V_64 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
V_132 = F_128 ( V_16 ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_129 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_15 = F_29 ( V_18 ) ;
int V_16 = F_6 ( V_15 ) ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
V_132 = F_128 ( V_16 ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_130 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = F_9 () ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
V_132 = F_128 ( V_16 ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_131 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = F_9 () ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
V_132 = F_132 ( V_16 ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_133 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = F_9 () ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
V_132 = F_134 ( V_16 ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_135 ( struct V_17 * V_18 )
{
int V_15 ;
T_4 V_21 ;
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << ( V_8 . V_10 . V_2 ) ;
F_48 (cpu) {
T_4 V_132 = F_132 ( F_6 ( V_15 ) ) + ( 0x1000ull * V_8 . V_10 . line ) ;
F_39 ( V_132 , V_21 ) ;
}
}
static void F_136 ( struct V_17 * V_18 )
{
int V_15 ;
T_4 V_21 ;
V_21 = 1ull << ( V_18 -> V_1 - V_124 ) ;
F_48 (cpu) {
T_4 V_132 = F_137 ( F_6 ( V_15 ) ) ;
F_39 ( V_132 , V_21 ) ;
}
}
static void F_138 ( struct V_17 * V_18 )
{
int V_15 ;
T_4 V_21 ;
V_21 = 1ull << ( V_18 -> V_1 - V_124 ) ;
F_48 (cpu) {
T_4 V_132 = F_139 ( F_6 ( V_15 ) ) ;
F_39 ( V_132 , V_21 ) ;
}
}
static void F_140 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = F_9 () ;
V_21 = 1ull << ( V_18 -> V_1 - V_124 ) ;
V_132 = F_137 ( V_16 ) ;
F_39 ( V_132 , V_21 ) ;
}
static void F_141 ( struct V_17 * V_18 )
{
T_4 V_21 ;
T_4 V_132 ;
int V_16 = F_9 () ;
V_21 = 1ull << ( V_18 -> V_1 - V_124 ) ;
V_132 = F_139 ( V_16 ) ;
F_39 ( V_132 , V_21 ) ;
}
static int F_142 ( struct V_17 * V_18 ,
const struct V_59 * V_60 , bool V_61 )
{
int V_15 ;
bool V_62 = ! F_84 ( V_18 ) && ! F_85 ( V_18 ) ;
T_4 V_21 ;
union V_7 V_8 ;
if ( ! V_62 )
return 0 ;
V_8 . V_11 = F_14 ( V_18 ) ;
V_21 = 1ull << V_8 . V_10 . V_2 ;
F_48 (cpu) {
T_4 V_132 ;
if ( F_32 ( V_15 , V_60 ) && V_62 ) {
V_62 = false ;
V_132 = F_128 ( F_6 ( V_15 ) ) + ( 0x1000ull * V_8 . V_10 . line ) ;
} else {
V_132 = F_132 ( F_6 ( V_15 ) ) + ( 0x1000ull * V_8 . V_10 . line ) ;
}
F_39 ( V_132 , V_21 ) ;
}
return 0 ;
}
static void F_143 ( struct V_17 * V_18 )
{
F_63 ( V_18 ) ;
F_129 ( V_18 ) ;
}
static void F_144 ( struct V_17 * V_18 )
{
union V_7 V_8 ;
V_8 . V_11 = F_14 ( V_18 ) ;
F_39 ( F_65 ( V_8 . V_10 . V_3 ) , 0 ) ;
F_135 ( V_18 ) ;
}
static int F_145 ( struct V_13 * V_66 ,
struct V_67 * V_68 ,
const T_5 * V_69 ,
unsigned int V_70 ,
unsigned long * V_71 ,
unsigned int * V_72 )
{
unsigned int V_79 , V_2 ;
V_79 = V_69 [ 0 ] ;
V_2 = V_69 [ 1 ] ;
if ( V_79 > 6 || V_2 > 63 )
return - V_63 ;
* V_71 = ( V_79 << 6 ) | V_2 ;
* V_72 = 0 ;
return 0 ;
}
static bool F_146 ( unsigned int line , unsigned int V_2 )
{
bool V_65 = false ;
if ( line == 3 )
switch ( V_2 ) {
case 2 :
case 8 ... 11 :
case 48 :
V_65 = true ;
break;
default:
break;
}
else if ( line == 6 )
switch ( V_2 ) {
case 52 ... 53 :
case 8 ... 12 :
V_65 = true ;
break;
default:
break;
}
return V_65 ;
}
static int F_147 ( struct V_13 * V_66 ,
unsigned int V_80 , T_7 V_81 )
{
unsigned int line = V_81 >> 6 ;
unsigned int V_2 = V_81 & 63 ;
if ( ! F_93 ( V_80 ) )
return - V_63 ;
if ( line > 6 || V_12 [ line ] [ V_2 ] != 0 )
return - V_63 ;
if ( F_146 ( line , V_2 ) )
F_1 ( V_80 , line , V_2 , 0 ,
& V_133 ,
F_75 ) ;
else
F_1 ( V_80 , line , V_2 , 0 ,
& V_133 ,
F_76 ) ;
return 0 ;
}
static int F_148 ( struct V_13 * V_66 ,
unsigned int V_80 , T_7 V_81 )
{
return F_96 ( V_66 , V_80 , V_81 , 7 , & V_134 ) ;
}
static void F_149 ( void )
{
int line ;
int V_2 ;
int V_1 ;
T_4 V_135 , V_136 , V_137 ;
const unsigned long V_89 = F_9 () ;
V_137 = F_99 ( F_114 ( V_89 ) ) & 0xfful ;
if ( F_150 ( ! V_137 ) )
goto V_138;
line = F_101 ( V_137 ) - 1 ;
V_135 = F_151 ( V_89 ) + ( 0x1000 * line ) ;
V_136 = F_99 ( V_135 ) ;
if ( F_150 ( ! V_136 ) )
goto V_138;
V_2 = F_101 ( V_136 ) - 1 ;
V_1 = V_12 [ line ] [ V_2 ] ;
if ( F_150 ( ! V_1 ) )
goto V_138;
F_102 ( V_1 ) ;
goto V_139;
V_138:
F_103 () ;
V_139:
if ( F_118 ( V_140 ) )
F_99 ( V_141 ) ;
else
F_99 ( F_152 ( V_89 ) ) ;
return;
}
static void F_153 ( void )
{
int line ;
const unsigned long V_89 = F_9 () ;
T_4 V_137 = F_99 ( F_154 ( V_89 ) ) >> 60 ;
if ( F_150 ( ! V_137 ) )
goto V_138;
line = F_101 ( V_137 ) - 1 ;
F_102 ( V_124 + line ) ;
goto V_139;
V_138:
F_103 () ;
V_139:
if ( F_118 ( V_140 ) )
F_99 ( V_141 ) ;
else
F_99 ( F_155 ( V_89 ) ) ;
return;
}
static void T_2 F_156 ( void )
{
unsigned int V_25 ;
struct V_67 * V_102 ;
struct V_67 * V_103 ;
struct V_13 * V_104 = NULL ;
F_112 () ;
V_105 = F_116 ;
V_106 = F_149 ;
V_107 = F_153 ;
V_93 = F_106 ;
F_27 () ;
V_102 = F_119 ( NULL , NULL , L_3 ) ;
if ( V_102 ) {
struct V_84 * V_85 ;
V_85 = F_120 ( sizeof( * V_85 ) , V_120 ) ;
if ( V_85 ) {
V_85 -> V_87 = 7 << 6 ;
F_121 ( V_102 , 16 , & V_142 , V_85 ) ;
F_122 ( V_102 ) ;
} else
F_123 ( L_4 ) ;
} else
F_123 ( L_5 ) ;
V_103 = F_119 ( NULL , NULL , L_8 ) ;
if ( V_103 ) {
V_104 = F_124 ( V_103 , & V_143 , NULL ) ;
F_125 ( V_104 ) ;
F_122 ( V_103 ) ;
} else
F_126 ( L_9 ) ;
for ( V_25 = 0 ; V_25 < 64 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_123 , 0 , V_25 ) ;
for ( V_25 = 0 ; V_25 < 32 ; V_25 ++ )
F_1 ( V_25 + V_64 , 1 , V_25 , 0 ,
& V_144 , F_76 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_129 , 3 , V_25 + 8 ) ;
F_4 ( V_104 , V_130 , 3 , 44 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_126 , 4 , V_25 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ )
F_4 ( V_104 , V_25 + V_127 , 4 , V_25 + 8 ) ;
F_2 ( V_124 , & V_145 , V_30 ) ;
F_2 ( V_125 , & V_145 , V_30 ) ;
F_2 ( V_146 , & V_145 , V_30 ) ;
F_2 ( V_147 , & V_145 , V_30 ) ;
F_18 ( V_98 | V_99 ) ;
F_15 ( V_91 ) ;
}
void T_2 F_157 ( void )
{
#ifdef F_7
F_80 ( V_148 ) ;
F_81 ( F_12 () , V_148 ) ;
#endif
if ( F_118 ( V_140 ) )
F_156 () ;
else
F_117 () ;
}
T_9 void F_158 ( void )
{
unsigned long V_149 ;
unsigned long V_150 ;
while ( 1 ) {
V_149 = F_159 () ;
V_150 = F_160 () ;
V_149 &= V_150 ;
V_149 &= V_151 ;
if ( F_150 ( V_149 & V_99 ) )
V_106 () ;
else if ( F_150 ( V_149 & V_98 ) )
V_107 () ;
else if ( F_150 ( V_149 & V_91 ) )
V_93 () ;
else if ( F_100 ( V_149 ) )
F_102 ( F_161 ( V_149 ) - 9 + V_152 ) ;
else
break;
}
}
void F_162 ( void )
{
F_163 () ;
}
