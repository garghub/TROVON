bool F_1 ( void )
{
return F_2 ( V_1 , & F_3 ( V_2 ) -> V_3 ) ;
}
bool F_4 ( void )
{
return F_2 ( V_4 , & F_3 ( V_2 ) -> V_3 ) ;
}
bool F_5 ( bool * V_5 )
{
bool V_6 = false ;
F_6 () ;
if ( F_7 ( F_8 ( V_2 ) ) )
V_6 = F_9 ( true ) ;
if ( V_5 )
* V_5 = V_6 ;
return F_1 () ;
}
void * F_10 ( struct V_7 * V_8 )
{
return F_3 ( V_8 ) -> V_9 ;
}
static void F_11 ( struct V_10 * V_11 )
{
F_12 ( V_12 ) ;
while ( F_2 ( V_4 , & V_11 -> V_3 ) ) {
if ( ! F_13 ( V_13 , & V_11 -> V_3 ) )
F_14 ( & V_11 -> V_14 ) ;
F_15 () ;
F_12 ( V_12 ) ;
}
F_16 ( V_13 , & V_11 -> V_3 ) ;
F_12 ( V_15 ) ;
}
void F_17 ( void )
{
F_11 ( F_3 ( V_2 ) ) ;
}
static int V_10 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
int (* F_18)( void * V_9 ) = V_18 -> F_18 ;
void * V_9 = V_18 -> V_9 ;
struct V_10 V_11 ;
int V_19 ;
V_11 . V_3 = 0 ;
V_11 . V_9 = V_9 ;
F_19 ( & V_11 . V_20 ) ;
F_19 ( & V_11 . V_14 ) ;
V_2 -> V_21 = & V_11 . V_20 ;
F_12 ( V_22 ) ;
V_18 -> V_23 = V_2 ;
F_14 ( & V_18 -> V_24 ) ;
F_15 () ;
V_19 = - V_25 ;
if ( ! F_2 ( V_1 , & V_11 . V_3 ) ) {
F_11 ( & V_11 ) ;
V_19 = F_18 ( V_9 ) ;
}
F_20 ( V_19 ) ;
}
int F_21 ( struct V_7 * V_26 )
{
#ifdef F_22
if ( V_26 == V_27 )
return V_26 -> V_28 ;
#endif
return F_23 () ;
}
static void F_24 ( struct V_17 * V_18 )
{
int V_29 ;
#ifdef F_22
V_2 -> V_28 = V_18 -> V_30 ;
#endif
V_29 = F_25 ( V_10 , V_18 , V_31 | V_32 | V_33 ) ;
if ( V_29 < 0 ) {
V_18 -> V_23 = F_26 ( V_29 ) ;
F_14 ( & V_18 -> V_24 ) ;
}
}
struct V_7 * F_27 ( int (* F_18)( void * V_9 ) ,
void * V_9 , int V_30 ,
const char V_34 [] ,
... )
{
struct V_17 V_18 ;
V_18 . F_18 = F_18 ;
V_18 . V_9 = V_9 ;
V_18 . V_30 = V_30 ;
F_19 ( & V_18 . V_24 ) ;
F_28 ( & V_35 ) ;
F_29 ( & V_18 . V_36 , & V_37 ) ;
F_30 ( & V_35 ) ;
F_31 ( V_27 ) ;
F_32 ( & V_18 . V_24 ) ;
if ( ! F_33 ( V_18 . V_23 ) ) {
static const struct V_38 V_39 = { . V_40 = 0 } ;
T_1 args ;
va_start ( args , V_34 ) ;
vsnprintf ( V_18 . V_23 -> V_41 , sizeof( V_18 . V_23 -> V_41 ) ,
V_34 , args ) ;
va_end ( args ) ;
F_34 ( V_18 . V_23 , V_42 , & V_39 ) ;
F_35 ( V_18 . V_23 , V_43 ) ;
}
return V_18 . V_23 ;
}
static void F_36 ( struct V_7 * V_44 , unsigned int V_45 )
{
F_37 ( V_44 , F_38 ( V_45 ) ) ;
V_44 -> V_3 |= V_46 ;
}
void F_39 ( struct V_7 * V_44 , unsigned int V_45 )
{
if ( ! F_40 ( V_44 , V_22 ) ) {
F_41 ( 1 ) ;
return;
}
F_36 ( V_44 , V_45 ) ;
}
struct V_7 * F_42 ( int (* F_18)( void * V_9 ) ,
void * V_9 , unsigned int V_45 ,
const char * V_34 )
{
struct V_7 * V_44 ;
V_44 = F_27 ( F_18 , V_9 , F_43 ( V_45 ) , V_34 ,
V_45 ) ;
if ( F_33 ( V_44 ) )
return V_44 ;
F_44 ( V_47 , & F_3 ( V_44 ) -> V_3 ) ;
F_3 ( V_44 ) -> V_45 = V_45 ;
F_45 ( V_44 ) ;
return V_44 ;
}
static struct V_10 * F_46 ( struct V_7 * V_48 )
{
struct V_10 * V_10 ;
F_47 ( V_48 ) ;
V_10 = F_3 ( V_48 ) ;
F_48 () ;
if ( V_48 -> V_21 != NULL )
return V_10 ;
return NULL ;
}
void F_49 ( struct V_7 * V_48 )
{
struct V_10 * V_10 = F_46 ( V_48 ) ;
if ( V_10 ) {
F_16 ( V_4 , & V_10 -> V_3 ) ;
if ( F_50 ( V_13 , & V_10 -> V_3 ) ) {
if ( F_2 ( V_47 , & V_10 -> V_3 ) )
F_36 ( V_48 , V_10 -> V_45 ) ;
F_31 ( V_48 ) ;
}
}
F_51 ( V_48 ) ;
}
int F_45 ( struct V_7 * V_48 )
{
struct V_10 * V_10 = F_46 ( V_48 ) ;
int V_19 = - V_49 ;
if ( V_10 ) {
if ( ! F_2 ( V_13 , & V_10 -> V_3 ) ) {
F_44 ( V_4 , & V_10 -> V_3 ) ;
if ( V_48 != V_2 ) {
F_31 ( V_48 ) ;
F_32 ( & V_10 -> V_14 ) ;
}
}
V_19 = 0 ;
}
F_51 ( V_48 ) ;
return V_19 ;
}
int F_52 ( struct V_7 * V_48 )
{
struct V_10 * V_10 = F_46 ( V_48 ) ;
int V_19 ;
F_53 ( V_48 ) ;
if ( V_10 ) {
F_44 ( V_1 , & V_10 -> V_3 ) ;
F_16 ( V_4 , & V_10 -> V_3 ) ;
F_31 ( V_48 ) ;
F_32 ( & V_10 -> V_20 ) ;
}
V_19 = V_48 -> V_50 ;
F_51 ( V_48 ) ;
F_54 ( V_19 ) ;
return V_19 ;
}
int F_55 ( void * V_51 )
{
struct V_7 * V_26 = V_2 ;
F_56 ( V_26 , L_1 ) ;
F_57 ( V_26 ) ;
F_35 ( V_26 , V_43 ) ;
F_58 ( V_52 [ V_53 ] ) ;
V_2 -> V_3 |= V_54 ;
for (; ; ) {
F_59 ( V_12 ) ;
if ( F_60 ( & V_37 ) )
F_15 () ;
F_12 ( V_15 ) ;
F_28 ( & V_35 ) ;
while ( ! F_60 ( & V_37 ) ) {
struct V_17 * V_18 ;
V_18 = F_61 ( V_37 . V_55 ,
struct V_17 , V_36 ) ;
F_62 ( & V_18 -> V_36 ) ;
F_30 ( & V_35 ) ;
F_24 ( V_18 ) ;
F_28 ( & V_35 ) ;
}
F_30 ( & V_35 ) ;
}
return 0 ;
}
void F_63 ( struct V_56 * V_57 ,
const char * V_58 ,
struct V_59 * V_60 )
{
F_64 ( & V_57 -> V_61 ) ;
F_65 ( & V_57 -> V_61 , V_60 , V_58 ) ;
F_66 ( & V_57 -> V_62 ) ;
V_57 -> V_8 = NULL ;
}
int F_67 ( void * V_63 )
{
struct V_56 * V_57 = V_63 ;
struct V_64 * V_65 ;
F_41 ( V_57 -> V_8 ) ;
V_57 -> V_8 = V_2 ;
V_66:
F_59 ( V_12 ) ;
if ( F_1 () ) {
F_12 ( V_15 ) ;
F_68 ( & V_57 -> V_61 ) ;
V_57 -> V_8 = NULL ;
F_69 ( & V_57 -> V_61 ) ;
return 0 ;
}
V_65 = NULL ;
F_68 ( & V_57 -> V_61 ) ;
if ( ! F_60 ( & V_57 -> V_62 ) ) {
V_65 = F_70 ( & V_57 -> V_62 ,
struct V_64 , V_30 ) ;
F_62 ( & V_65 -> V_30 ) ;
}
V_57 -> V_67 = V_65 ;
F_69 ( & V_57 -> V_61 ) ;
if ( V_65 ) {
F_12 ( V_15 ) ;
V_65 -> V_68 ( V_65 ) ;
} else if ( ! F_8 ( V_2 ) )
F_15 () ;
F_71 () ;
goto V_66;
}
static void F_72 ( struct V_56 * V_57 ,
struct V_64 * V_65 ,
struct V_69 * V_70 )
{
F_73 ( & V_57 -> V_61 ) ;
F_29 ( & V_65 -> V_30 , V_70 ) ;
V_65 -> V_57 = V_57 ;
if ( F_74 ( V_57 -> V_8 ) )
F_31 ( V_57 -> V_8 ) ;
}
bool F_75 ( struct V_56 * V_57 ,
struct V_64 * V_65 )
{
bool V_19 = false ;
unsigned long V_3 ;
F_76 ( & V_57 -> V_61 , V_3 ) ;
if ( F_60 ( & V_65 -> V_30 ) ) {
F_72 ( V_57 , V_65 , & V_57 -> V_62 ) ;
V_19 = true ;
}
F_77 ( & V_57 -> V_61 , V_3 ) ;
return V_19 ;
}
static void F_78 ( struct V_64 * V_65 )
{
struct V_71 * V_72 =
F_79 ( V_65 , struct V_71 , V_65 ) ;
F_14 ( & V_72 -> V_24 ) ;
}
void F_80 ( struct V_64 * V_65 )
{
struct V_71 V_72 = {
F_81 ( V_72 . V_65 , F_78 ) ,
F_82 ( V_72 . V_24 ) ,
} ;
struct V_56 * V_57 ;
bool V_73 = false ;
V_74:
V_57 = V_65 -> V_57 ;
if ( ! V_57 )
return;
F_68 ( & V_57 -> V_61 ) ;
if ( V_65 -> V_57 != V_57 ) {
F_69 ( & V_57 -> V_61 ) ;
goto V_74;
}
if ( ! F_60 ( & V_65 -> V_30 ) )
F_72 ( V_57 , & V_72 . V_65 , V_65 -> V_30 . V_55 ) ;
else if ( V_57 -> V_67 == V_65 )
F_72 ( V_57 , & V_72 . V_65 , V_57 -> V_62 . V_55 ) ;
else
V_73 = true ;
F_69 ( & V_57 -> V_61 ) ;
if ( ! V_73 )
F_32 ( & V_72 . V_24 ) ;
}
void F_83 ( struct V_56 * V_57 )
{
struct V_71 V_72 = {
F_81 ( V_72 . V_65 , F_78 ) ,
F_82 ( V_72 . V_24 ) ,
} ;
F_75 ( V_57 , & V_72 . V_65 ) ;
F_32 ( & V_72 . V_24 ) ;
}
