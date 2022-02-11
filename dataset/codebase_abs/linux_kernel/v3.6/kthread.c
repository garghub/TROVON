int F_1 ( void )
{
return F_2 ( V_1 ) -> V_2 ;
}
bool F_3 ( bool * V_3 )
{
bool V_4 = false ;
F_4 () ;
if ( F_5 ( F_6 ( V_1 ) ) )
V_4 = F_7 ( true ) ;
if ( V_3 )
* V_3 = V_4 ;
return F_1 () ;
}
void * F_8 ( struct V_5 * V_6 )
{
return F_2 ( V_6 ) -> V_7 ;
}
static int F_9 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
int (* F_10)( void * V_7 ) = V_10 -> F_10 ;
void * V_7 = V_10 -> V_7 ;
struct F_9 V_11 ;
int V_12 ;
V_11 . V_2 = 0 ;
V_11 . V_7 = V_7 ;
F_11 ( & V_11 . V_13 ) ;
V_1 -> V_14 = & V_11 . V_13 ;
F_12 ( V_15 ) ;
V_10 -> V_16 = V_1 ;
F_13 ( & V_10 -> V_17 ) ;
F_14 () ;
V_12 = - V_18 ;
if ( ! V_11 . V_2 )
V_12 = F_10 ( V_7 ) ;
F_15 ( V_12 ) ;
}
int F_16 ( struct V_5 * V_19 )
{
#ifdef F_17
if ( V_19 == V_20 )
return V_19 -> V_21 ;
#endif
return F_18 () ;
}
static void F_19 ( struct V_9 * V_10 )
{
int V_22 ;
#ifdef F_17
V_1 -> V_21 = V_10 -> V_23 ;
#endif
V_22 = F_20 ( F_9 , V_10 , V_24 | V_25 | V_26 ) ;
if ( V_22 < 0 ) {
V_10 -> V_16 = F_21 ( V_22 ) ;
F_13 ( & V_10 -> V_17 ) ;
}
}
struct V_5 * F_22 ( int (* F_10)( void * V_7 ) ,
void * V_7 ,
int V_23 ,
const char V_27 [] ,
... )
{
struct V_9 V_10 ;
V_10 . F_10 = F_10 ;
V_10 . V_7 = V_7 ;
V_10 . V_23 = V_23 ;
F_11 ( & V_10 . V_17 ) ;
F_23 ( & V_28 ) ;
F_24 ( & V_10 . V_29 , & V_30 ) ;
F_25 ( & V_28 ) ;
F_26 ( V_20 ) ;
F_27 ( & V_10 . V_17 ) ;
if ( ! F_28 ( V_10 . V_16 ) ) {
static const struct V_31 V_32 = { . V_33 = 0 } ;
T_1 args ;
va_start ( args , V_27 ) ;
vsnprintf ( V_10 . V_16 -> V_34 , sizeof( V_10 . V_16 -> V_34 ) ,
V_27 , args ) ;
va_end ( args ) ;
F_29 ( V_10 . V_16 , V_35 , & V_32 ) ;
F_30 ( V_10 . V_16 , V_36 ) ;
}
return V_10 . V_16 ;
}
void F_31 ( struct V_5 * V_37 , unsigned int V_38 )
{
if ( ! F_32 ( V_37 , V_15 ) ) {
F_33 ( 1 ) ;
return;
}
F_34 ( V_37 , F_35 ( V_38 ) ) ;
V_37 -> V_39 |= V_40 ;
}
int F_36 ( struct V_5 * V_41 )
{
struct F_9 * F_9 ;
int V_12 ;
F_37 ( V_41 ) ;
F_38 ( V_41 ) ;
F_9 = F_2 ( V_41 ) ;
F_39 () ;
if ( V_41 -> V_14 != NULL ) {
F_9 -> V_2 = 1 ;
F_26 ( V_41 ) ;
F_27 ( & F_9 -> V_13 ) ;
}
V_12 = V_41 -> V_42 ;
F_40 ( V_41 ) ;
F_41 ( V_12 ) ;
return V_12 ;
}
int F_42 ( void * V_43 )
{
struct V_5 * V_19 = V_1 ;
F_43 ( V_19 , L_1 ) ;
F_44 ( V_19 ) ;
F_30 ( V_19 , V_36 ) ;
F_45 ( V_44 [ V_45 ] ) ;
V_1 -> V_39 |= V_46 ;
for (; ; ) {
F_46 ( V_47 ) ;
if ( F_47 ( & V_30 ) )
F_14 () ;
F_12 ( V_48 ) ;
F_23 ( & V_28 ) ;
while ( ! F_47 ( & V_30 ) ) {
struct V_9 * V_10 ;
V_10 = F_48 ( V_30 . V_49 ,
struct V_9 , V_29 ) ;
F_49 ( & V_10 -> V_29 ) ;
F_25 ( & V_28 ) ;
F_19 ( V_10 ) ;
F_23 ( & V_28 ) ;
}
F_25 ( & V_28 ) ;
}
return 0 ;
}
void F_50 ( struct V_50 * V_51 ,
const char * V_52 ,
struct V_53 * V_54 )
{
F_51 ( & V_51 -> V_55 ) ;
F_52 ( & V_51 -> V_55 , V_54 , V_52 ) ;
F_53 ( & V_51 -> V_56 ) ;
V_51 -> V_6 = NULL ;
}
int F_54 ( void * V_57 )
{
struct V_50 * V_51 = V_57 ;
struct V_58 * V_59 ;
F_33 ( V_51 -> V_6 ) ;
V_51 -> V_6 = V_1 ;
V_60:
F_46 ( V_47 ) ;
if ( F_1 () ) {
F_12 ( V_48 ) ;
F_55 ( & V_51 -> V_55 ) ;
V_51 -> V_6 = NULL ;
F_56 ( & V_51 -> V_55 ) ;
return 0 ;
}
V_59 = NULL ;
F_55 ( & V_51 -> V_55 ) ;
if ( ! F_47 ( & V_51 -> V_56 ) ) {
V_59 = F_57 ( & V_51 -> V_56 ,
struct V_58 , V_23 ) ;
F_49 ( & V_59 -> V_23 ) ;
}
V_51 -> V_61 = V_59 ;
F_56 ( & V_51 -> V_55 ) ;
if ( V_59 ) {
F_12 ( V_48 ) ;
V_59 -> V_62 ( V_59 ) ;
} else if ( ! F_6 ( V_1 ) )
F_14 () ;
F_58 () ;
goto V_60;
}
static void F_59 ( struct V_50 * V_51 ,
struct V_58 * V_59 ,
struct V_63 * V_64 )
{
F_60 ( & V_51 -> V_55 ) ;
F_24 ( & V_59 -> V_23 , V_64 ) ;
V_59 -> V_51 = V_51 ;
if ( F_61 ( V_51 -> V_6 ) )
F_26 ( V_51 -> V_6 ) ;
}
bool F_62 ( struct V_50 * V_51 ,
struct V_58 * V_59 )
{
bool V_12 = false ;
unsigned long V_39 ;
F_63 ( & V_51 -> V_55 , V_39 ) ;
if ( F_47 ( & V_59 -> V_23 ) ) {
F_59 ( V_51 , V_59 , & V_51 -> V_56 ) ;
V_12 = true ;
}
F_64 ( & V_51 -> V_55 , V_39 ) ;
return V_12 ;
}
static void F_65 ( struct V_58 * V_59 )
{
struct V_65 * V_66 =
F_66 ( V_59 , struct V_65 , V_59 ) ;
F_13 ( & V_66 -> V_17 ) ;
}
void F_67 ( struct V_58 * V_59 )
{
struct V_65 V_66 = {
F_68 ( V_66 . V_59 , F_65 ) ,
F_69 ( V_66 . V_17 ) ,
} ;
struct V_50 * V_51 ;
bool V_67 = false ;
V_68:
V_51 = V_59 -> V_51 ;
if ( ! V_51 )
return;
F_55 ( & V_51 -> V_55 ) ;
if ( V_59 -> V_51 != V_51 ) {
F_56 ( & V_51 -> V_55 ) ;
goto V_68;
}
if ( ! F_47 ( & V_59 -> V_23 ) )
F_59 ( V_51 , & V_66 . V_59 , V_59 -> V_23 . V_49 ) ;
else if ( V_51 -> V_61 == V_59 )
F_59 ( V_51 , & V_66 . V_59 , V_51 -> V_56 . V_49 ) ;
else
V_67 = true ;
F_56 ( & V_51 -> V_55 ) ;
if ( ! V_67 )
F_27 ( & V_66 . V_17 ) ;
}
void F_70 ( struct V_50 * V_51 )
{
struct V_65 V_66 = {
F_68 ( V_66 . V_59 , F_65 ) ,
F_69 ( V_66 . V_17 ) ,
} ;
F_62 ( V_51 , & V_66 . V_59 ) ;
F_27 ( & V_66 . V_17 ) ;
}
