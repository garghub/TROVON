static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 -> V_4 ) ;
if ( F_5 ( V_6 ) )
return F_2 ( V_6 ) ;
return NULL ;
}
bool F_6 ( void )
{
return F_7 ( V_7 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_8 ( void )
{
return F_7 ( V_10 , & F_1 ( V_8 ) -> V_9 ) ;
}
bool F_9 ( bool * V_11 )
{
bool V_12 = false ;
F_10 () ;
if ( F_11 ( F_12 ( V_8 ) ) )
V_12 = F_13 ( true ) ;
if ( V_11 )
* V_11 = V_12 ;
return F_6 () ;
}
void * F_14 ( struct V_2 * V_13 )
{
return F_1 ( V_13 ) -> V_14 ;
}
void * F_15 ( struct V_2 * V_13 )
{
struct V_1 * V_1 = F_1 ( V_13 ) ;
void * V_14 = NULL ;
F_16 ( & V_14 , & V_1 -> V_14 , sizeof( V_14 ) ) ;
return V_14 ;
}
static void F_17 ( struct V_1 * V_15 )
{
F_18 ( V_16 ) ;
while ( F_7 ( V_10 , & V_15 -> V_9 ) ) {
if ( ! F_19 ( V_17 , & V_15 -> V_9 ) )
F_20 ( & V_15 -> V_18 ) ;
F_21 () ;
F_18 ( V_16 ) ;
}
F_22 ( V_17 , & V_15 -> V_9 ) ;
F_18 ( V_19 ) ;
}
void F_23 ( void )
{
F_17 ( F_1 ( V_8 ) ) ;
}
static int V_1 ( void * V_20 )
{
struct V_21 * V_22 = V_20 ;
int (* F_24)( void * V_14 ) = V_22 -> F_24 ;
void * V_14 = V_22 -> V_14 ;
struct V_1 V_15 ;
int V_23 ;
V_15 . V_9 = 0 ;
V_15 . V_14 = V_14 ;
F_25 ( & V_15 . V_24 ) ;
F_25 ( & V_15 . V_18 ) ;
V_8 -> V_4 = & V_15 . V_24 ;
F_18 ( V_25 ) ;
V_22 -> V_26 = V_8 ;
F_20 ( & V_22 -> V_27 ) ;
F_21 () ;
V_23 = - V_28 ;
if ( ! F_7 ( V_7 , & V_15 . V_9 ) ) {
F_17 ( & V_15 ) ;
V_23 = F_24 ( V_14 ) ;
}
F_26 ( V_23 ) ;
}
int F_27 ( struct V_2 * V_29 )
{
#ifdef F_28
if ( V_29 == V_30 )
return V_29 -> V_31 ;
#endif
return F_29 () ;
}
static void F_30 ( struct V_21 * V_22 )
{
int V_32 ;
#ifdef F_28
V_8 -> V_31 = V_22 -> V_33 ;
#endif
V_32 = F_31 ( V_1 , V_22 , V_34 | V_35 | V_36 ) ;
if ( V_32 < 0 ) {
V_22 -> V_26 = F_32 ( V_32 ) ;
F_20 ( & V_22 -> V_27 ) ;
}
}
struct V_2 * F_33 ( int (* F_24)( void * V_14 ) ,
void * V_14 , int V_33 ,
const char V_37 [] ,
... )
{
struct V_21 V_22 ;
V_22 . F_24 = F_24 ;
V_22 . V_14 = V_14 ;
V_22 . V_33 = V_33 ;
F_25 ( & V_22 . V_27 ) ;
F_34 ( & V_38 ) ;
F_35 ( & V_22 . V_39 , & V_40 ) ;
F_36 ( & V_38 ) ;
F_37 ( V_30 ) ;
F_38 ( & V_22 . V_27 ) ;
if ( ! F_39 ( V_22 . V_26 ) ) {
static const struct V_41 V_42 = { . V_43 = 0 } ;
T_1 args ;
va_start ( args , V_37 ) ;
vsnprintf ( V_22 . V_26 -> V_44 , sizeof( V_22 . V_26 -> V_44 ) ,
V_37 , args ) ;
va_end ( args ) ;
F_40 ( V_22 . V_26 , V_45 , & V_42 ) ;
F_41 ( V_22 . V_26 , V_46 ) ;
}
return V_22 . V_26 ;
}
static void F_42 ( struct V_2 * V_47 , unsigned int V_48 , long V_49 )
{
if ( ! F_43 ( V_47 , V_49 ) ) {
F_44 ( 1 ) ;
return;
}
F_45 ( V_47 , F_46 ( V_48 ) ) ;
V_47 -> V_9 |= V_50 ;
}
void F_47 ( struct V_2 * V_47 , unsigned int V_48 )
{
F_42 ( V_47 , V_48 , V_25 ) ;
}
struct V_2 * F_48 ( int (* F_24)( void * V_14 ) ,
void * V_14 , unsigned int V_48 ,
const char * V_37 )
{
struct V_2 * V_47 ;
V_47 = F_33 ( F_24 , V_14 , F_49 ( V_48 ) , V_37 ,
V_48 ) ;
if ( F_39 ( V_47 ) )
return V_47 ;
F_50 ( V_51 , & F_1 ( V_47 ) -> V_9 ) ;
F_1 ( V_47 ) -> V_48 = V_48 ;
F_51 ( V_47 ) ;
return V_47 ;
}
static void F_52 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_22 ( V_10 , & V_1 -> V_9 ) ;
if ( F_53 ( V_17 , & V_1 -> V_9 ) ) {
if ( F_7 ( V_51 , & V_1 -> V_9 ) )
F_42 ( V_3 , V_1 -> V_48 , V_16 ) ;
F_54 ( V_3 , V_16 ) ;
}
}
void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
if ( V_1 )
F_52 ( V_3 , V_1 ) ;
}
int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_3 ( V_3 ) ;
int V_23 = - V_52 ;
if ( V_1 ) {
if ( ! F_7 ( V_17 , & V_1 -> V_9 ) ) {
F_50 ( V_10 , & V_1 -> V_9 ) ;
if ( V_3 != V_8 ) {
F_37 ( V_3 ) ;
F_38 ( & V_1 -> V_18 ) ;
}
}
V_23 = 0 ;
}
return V_23 ;
}
int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_23 ;
F_57 ( V_3 ) ;
F_58 ( V_3 ) ;
V_1 = F_3 ( V_3 ) ;
if ( V_1 ) {
F_50 ( V_7 , & V_1 -> V_9 ) ;
F_52 ( V_3 , V_1 ) ;
F_37 ( V_3 ) ;
F_38 ( & V_1 -> V_24 ) ;
}
V_23 = V_3 -> V_53 ;
F_59 ( V_3 ) ;
F_60 ( V_23 ) ;
return V_23 ;
}
int F_61 ( void * V_54 )
{
struct V_2 * V_29 = V_8 ;
F_62 ( V_29 , L_1 ) ;
F_63 ( V_29 ) ;
F_41 ( V_29 , V_46 ) ;
F_64 ( V_55 [ V_56 ] ) ;
V_8 -> V_9 |= V_57 ;
for (; ; ) {
F_65 ( V_58 ) ;
if ( F_66 ( & V_40 ) )
F_21 () ;
F_18 ( V_19 ) ;
F_34 ( & V_38 ) ;
while ( ! F_66 ( & V_40 ) ) {
struct V_21 * V_22 ;
V_22 = F_67 ( V_40 . V_59 ,
struct V_21 , V_39 ) ;
F_68 ( & V_22 -> V_39 ) ;
F_36 ( & V_38 ) ;
F_30 ( V_22 ) ;
F_34 ( & V_38 ) ;
}
F_36 ( & V_38 ) ;
}
return 0 ;
}
void F_69 ( struct V_60 * V_61 ,
const char * V_62 ,
struct V_63 * V_64 )
{
F_70 ( & V_61 -> V_65 ) ;
F_71 ( & V_61 -> V_65 , V_64 , V_62 ) ;
F_72 ( & V_61 -> V_66 ) ;
V_61 -> V_13 = NULL ;
}
int F_73 ( void * V_67 )
{
struct V_60 * V_61 = V_67 ;
struct V_68 * V_69 ;
F_44 ( V_61 -> V_13 ) ;
V_61 -> V_13 = V_8 ;
V_70:
F_65 ( V_58 ) ;
if ( F_6 () ) {
F_18 ( V_19 ) ;
F_74 ( & V_61 -> V_65 ) ;
V_61 -> V_13 = NULL ;
F_75 ( & V_61 -> V_65 ) ;
return 0 ;
}
V_69 = NULL ;
F_74 ( & V_61 -> V_65 ) ;
if ( ! F_66 ( & V_61 -> V_66 ) ) {
V_69 = F_76 ( & V_61 -> V_66 ,
struct V_68 , V_33 ) ;
F_68 ( & V_69 -> V_33 ) ;
}
V_61 -> V_71 = V_69 ;
F_75 ( & V_61 -> V_65 ) ;
if ( V_69 ) {
F_18 ( V_19 ) ;
V_69 -> V_72 ( V_69 ) ;
} else if ( ! F_12 ( V_8 ) )
F_21 () ;
F_77 () ;
goto V_70;
}
static void F_78 ( struct V_60 * V_61 ,
struct V_68 * V_69 ,
struct V_73 * V_74 )
{
F_79 ( & V_61 -> V_65 ) ;
F_35 ( & V_69 -> V_33 , V_74 ) ;
V_69 -> V_61 = V_61 ;
if ( F_5 ( V_61 -> V_13 ) )
F_37 ( V_61 -> V_13 ) ;
}
bool F_80 ( struct V_60 * V_61 ,
struct V_68 * V_69 )
{
bool V_23 = false ;
unsigned long V_9 ;
F_81 ( & V_61 -> V_65 , V_9 ) ;
if ( F_66 ( & V_69 -> V_33 ) ) {
F_78 ( V_61 , V_69 , & V_61 -> V_66 ) ;
V_23 = true ;
}
F_82 ( & V_61 -> V_65 , V_9 ) ;
return V_23 ;
}
static void F_83 ( struct V_68 * V_69 )
{
struct V_75 * V_76 =
F_84 ( V_69 , struct V_75 , V_69 ) ;
F_20 ( & V_76 -> V_27 ) ;
}
void F_85 ( struct V_68 * V_69 )
{
struct V_75 V_76 = {
F_86 ( V_76 . V_69 , F_83 ) ,
F_87 ( V_76 . V_27 ) ,
} ;
struct V_60 * V_61 ;
bool V_77 = false ;
V_78:
V_61 = V_69 -> V_61 ;
if ( ! V_61 )
return;
F_74 ( & V_61 -> V_65 ) ;
if ( V_69 -> V_61 != V_61 ) {
F_75 ( & V_61 -> V_65 ) ;
goto V_78;
}
if ( ! F_66 ( & V_69 -> V_33 ) )
F_78 ( V_61 , & V_76 . V_69 , V_69 -> V_33 . V_59 ) ;
else if ( V_61 -> V_71 == V_69 )
F_78 ( V_61 , & V_76 . V_69 , V_61 -> V_66 . V_59 ) ;
else
V_77 = true ;
F_75 ( & V_61 -> V_65 ) ;
if ( ! V_77 )
F_38 ( & V_76 . V_27 ) ;
}
void F_88 ( struct V_60 * V_61 )
{
struct V_75 V_76 = {
F_86 ( V_76 . V_69 , F_83 ) ,
F_87 ( V_76 . V_27 ) ,
} ;
F_80 ( V_61 , & V_76 . V_69 ) ;
F_38 ( & V_76 . V_27 ) ;
}
