int F_1 ( void )
{
return F_2 ( V_1 ) -> V_2 ;
}
void * F_3 ( struct V_3 * V_4 )
{
return F_2 ( V_4 ) -> V_5 ;
}
static int F_4 ( void * V_6 )
{
struct V_7 * V_8 = V_6 ;
int (* F_5)( void * V_5 ) = V_8 -> F_5 ;
void * V_5 = V_8 -> V_5 ;
struct F_4 V_9 ;
int V_10 ;
V_9 . V_2 = 0 ;
V_9 . V_5 = V_5 ;
F_6 ( & V_9 . V_11 ) ;
V_1 -> V_12 = & V_9 . V_11 ;
F_7 ( V_13 ) ;
V_8 -> V_14 = V_1 ;
F_8 ( & V_8 -> V_15 ) ;
F_9 () ;
V_10 = - V_16 ;
if ( ! V_9 . V_2 )
V_10 = F_5 ( V_5 ) ;
F_10 ( V_10 ) ;
}
int F_11 ( struct V_3 * V_17 )
{
#ifdef F_12
if ( V_17 == V_18 )
return V_17 -> V_19 ;
#endif
return F_13 () ;
}
static void F_14 ( struct V_7 * V_8 )
{
int V_20 ;
#ifdef F_12
V_1 -> V_19 = V_8 -> V_21 ;
#endif
V_20 = F_15 ( F_4 , V_8 , V_22 | V_23 | V_24 ) ;
if ( V_20 < 0 ) {
V_8 -> V_14 = F_16 ( V_20 ) ;
F_8 ( & V_8 -> V_15 ) ;
}
}
struct V_3 * F_17 ( int (* F_5)( void * V_5 ) ,
void * V_5 ,
int V_21 ,
const char V_25 [] ,
... )
{
struct V_7 V_8 ;
V_8 . F_5 = F_5 ;
V_8 . V_5 = V_5 ;
V_8 . V_21 = V_21 ;
F_6 ( & V_8 . V_15 ) ;
F_18 ( & V_26 ) ;
F_19 ( & V_8 . V_27 , & V_28 ) ;
F_20 ( & V_26 ) ;
F_21 ( V_18 ) ;
F_22 ( & V_8 . V_15 ) ;
if ( ! F_23 ( V_8 . V_14 ) ) {
static const struct V_29 V_30 = { . V_31 = 0 } ;
T_1 args ;
va_start ( args , V_25 ) ;
vsnprintf ( V_8 . V_14 -> V_32 , sizeof( V_8 . V_14 -> V_32 ) ,
V_25 , args ) ;
va_end ( args ) ;
F_24 ( V_8 . V_14 , V_33 , & V_30 ) ;
F_25 ( V_8 . V_14 , V_34 ) ;
}
return V_8 . V_14 ;
}
void F_26 ( struct V_3 * V_35 , unsigned int V_36 )
{
if ( ! F_27 ( V_35 , V_13 ) ) {
F_28 ( 1 ) ;
return;
}
F_29 ( V_35 , F_30 ( V_36 ) ) ;
V_35 -> V_37 |= V_38 ;
}
int F_31 ( struct V_3 * V_39 )
{
struct F_4 * F_4 ;
int V_10 ;
F_32 ( V_39 ) ;
F_33 ( V_39 ) ;
F_4 = F_2 ( V_39 ) ;
F_34 () ;
if ( V_39 -> V_12 != NULL ) {
F_4 -> V_2 = 1 ;
F_21 ( V_39 ) ;
F_22 ( & F_4 -> V_11 ) ;
}
V_10 = V_39 -> V_40 ;
F_35 ( V_39 ) ;
F_36 ( V_10 ) ;
return V_10 ;
}
int F_37 ( void * V_41 )
{
struct V_3 * V_17 = V_1 ;
F_38 ( V_17 , L_1 ) ;
F_39 ( V_17 ) ;
F_25 ( V_17 , V_34 ) ;
F_40 ( V_42 [ V_43 ] ) ;
V_1 -> V_37 |= V_44 | V_45 ;
for (; ; ) {
F_41 ( V_46 ) ;
if ( F_42 ( & V_28 ) )
F_9 () ;
F_7 ( V_47 ) ;
F_18 ( & V_26 ) ;
while ( ! F_42 ( & V_28 ) ) {
struct V_7 * V_8 ;
V_8 = F_43 ( V_28 . V_48 ,
struct V_7 , V_27 ) ;
F_44 ( & V_8 -> V_27 ) ;
F_20 ( & V_26 ) ;
F_14 ( V_8 ) ;
F_18 ( & V_26 ) ;
}
F_20 ( & V_26 ) ;
}
return 0 ;
}
void F_45 ( struct V_49 * V_50 ,
const char * V_51 ,
struct V_52 * V_53 )
{
F_46 ( & V_50 -> V_54 ) ;
F_47 ( & V_50 -> V_54 , V_53 , V_51 ) ;
F_48 ( & V_50 -> V_55 ) ;
V_50 -> V_4 = NULL ;
}
int F_49 ( void * V_56 )
{
struct V_49 * V_50 = V_56 ;
struct V_57 * V_58 ;
F_28 ( V_50 -> V_4 ) ;
V_50 -> V_4 = V_1 ;
V_59:
F_41 ( V_46 ) ;
if ( F_1 () ) {
F_7 ( V_47 ) ;
F_50 ( & V_50 -> V_54 ) ;
V_50 -> V_4 = NULL ;
F_51 ( & V_50 -> V_54 ) ;
return 0 ;
}
V_58 = NULL ;
F_50 ( & V_50 -> V_54 ) ;
if ( ! F_42 ( & V_50 -> V_55 ) ) {
V_58 = F_52 ( & V_50 -> V_55 ,
struct V_57 , V_21 ) ;
F_44 ( & V_58 -> V_21 ) ;
}
F_51 ( & V_50 -> V_54 ) ;
if ( V_58 ) {
F_7 ( V_47 ) ;
V_58 -> V_60 ( V_58 ) ;
F_53 () ;
V_58 -> V_61 = V_58 -> V_62 ;
F_54 () ;
if ( F_55 ( & V_58 -> V_63 ) )
F_56 ( & V_58 -> V_15 ) ;
} else if ( ! F_57 ( V_1 ) )
F_9 () ;
F_58 () ;
goto V_59;
}
bool F_59 ( struct V_49 * V_50 ,
struct V_57 * V_58 )
{
bool V_10 = false ;
unsigned long V_37 ;
F_60 ( & V_50 -> V_54 , V_37 ) ;
if ( F_42 ( & V_58 -> V_21 ) ) {
F_19 ( & V_58 -> V_21 , & V_50 -> V_55 ) ;
V_58 -> V_62 ++ ;
if ( F_61 ( V_50 -> V_4 ) )
F_21 ( V_50 -> V_4 ) ;
V_10 = true ;
}
F_62 ( & V_50 -> V_54 , V_37 ) ;
return V_10 ;
}
void F_63 ( struct V_57 * V_58 )
{
int V_64 = V_58 -> V_62 ;
F_64 ( & V_58 -> V_63 ) ;
F_65 () ;
F_66 ( V_58 -> V_15 , V_64 - V_58 -> V_61 <= 0 ) ;
F_67 ( & V_58 -> V_63 ) ;
F_68 () ;
}
static void F_69 ( struct V_57 * V_58 )
{
struct V_65 * V_66 =
F_70 ( V_58 , struct V_65 , V_58 ) ;
F_8 ( & V_66 -> V_15 ) ;
}
void F_71 ( struct V_49 * V_50 )
{
struct V_65 V_66 = {
F_72 ( V_66 . V_58 , F_69 ) ,
F_73 ( V_66 . V_15 ) ,
} ;
F_59 ( V_50 , & V_66 . V_58 ) ;
F_22 ( & V_66 . V_15 ) ;
}
