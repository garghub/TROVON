static inline bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 && ( V_2 -> V_4 -> V_5 & V_3 ) ;
}
static void F_2 ( struct V_6 * V_7 )
{
T_1 V_8 ;
V_8 = F_3 ( V_7 , V_9 ) ;
V_8 |= 0x10 ;
F_4 ( V_7 , V_8 , V_9 ) ;
F_5 ( 9 ) ;
V_8 &= ~ 0x10 ;
F_4 ( V_7 , V_8 , V_9 ) ;
F_6 ( 300 , 1000 ) ;
}
static bool F_7 ( void )
{
static const struct V_10 V_11 [] = {
{ V_12 , 6 , V_13 } ,
{}
} ;
return F_8 ( V_11 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
T_2 V_16 = 0 ;
if ( ! F_7 () )
return;
if ( F_10 ( V_17 , V_18 , V_19 ,
& V_16 ) ) {
F_11 ( V_15 , L_1 , V_20 ) ;
return;
}
if ( ! ( V_16 & V_21 ) )
return;
V_16 &= ~ V_21 ;
if ( F_12 ( V_17 , V_22 , V_19 ,
V_16 ) ) {
F_11 ( V_15 , L_2 , V_20 ) ;
return;
}
F_13 ( V_15 , L_3 , V_20 ) ;
}
static bool F_14 ( struct V_14 * V_15 )
{
if ( ! F_7 () )
return false ;
if ( ! F_15 () )
return true ;
F_9 ( V_15 ) ;
return false ;
}
static inline void F_9 ( struct V_14 * V_15 )
{
}
static inline bool F_14 ( struct V_14 * V_15 )
{
return false ;
}
static int F_16 ( struct V_23 * V_24 )
{
int V_25 = F_17 ( V_24 ) ;
struct V_6 * V_7 = F_18 ( V_24 ) ;
unsigned long V_5 ;
int V_26 = 0 ;
if ( ! V_25 )
return 0 ;
F_19 ( & V_7 -> V_27 , V_5 ) ;
if ( V_7 -> V_5 & V_28 )
goto V_29;
V_26 = ! ! ( F_20 ( V_7 , V_30 ) & V_31 ) ;
V_29:
F_21 ( & V_7 -> V_27 , V_5 ) ;
return V_26 ;
}
static int F_22 ( struct V_32 * V_33 ,
const char * V_34 , const char * V_35 )
{
struct V_1 * V_2 = F_23 ( V_33 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_34 && V_35 && ! strcmp ( V_34 , L_4 ) && ! strcmp ( V_35 , L_5 ) &&
F_20 ( V_7 , V_36 ) == 0x446cc8b2 &&
F_20 ( V_7 , V_37 ) == 0x00000807 )
V_7 -> V_38 = 1000 ;
return 0 ;
}
static int F_24 ( struct V_32 * V_33 ,
const char * V_34 , const char * V_35 )
{
struct V_1 * V_2 = F_23 ( V_33 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 ,
const char * V_34 , const char * V_35 )
{
struct V_1 * V_2 = F_23 ( V_33 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 || ! V_2 -> V_4 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_34 && ! strcmp ( V_34 , L_6 ) ) {
V_7 -> V_39 . V_40 = F_16 ;
V_7 -> V_24 -> V_41 |= V_42 ;
}
return 0 ;
}
static const struct V_43 * F_26 ( const char * V_34 ,
const char * V_35 )
{
const struct V_44 * V_45 ;
for ( V_45 = V_46 ; V_45 -> V_34 ; V_45 ++ ) {
if ( strcmp ( V_45 -> V_34 , V_34 ) )
continue;
if ( ! V_45 -> V_35 )
return V_45 -> V_4 ;
if ( V_35 && ! strcmp ( V_45 -> V_35 , V_35 ) )
return V_45 -> V_4 ;
}
return NULL ;
}
static int F_27 ( struct V_32 * V_33 )
{
struct V_14 * V_15 = & V_33 -> V_15 ;
T_3 V_47 = F_28 ( V_15 ) ;
struct V_48 * V_14 , * V_49 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_50 * V_51 ;
T_4 V_52 ;
const char * V_34 ;
const char * V_35 ;
int V_53 ;
if ( F_29 ( V_47 , & V_14 ) )
return - V_54 ;
F_30 ( V_14 ) ;
F_31 (child, &device->children, node)
if ( V_49 -> V_55 . V_56 && V_49 -> V_55 . V_57 )
F_30 ( V_49 ) ;
if ( F_32 ( V_14 ) || ! V_14 -> V_55 . V_56 )
return - V_54 ;
if ( F_14 ( V_15 ) )
return - V_58 ;
V_34 = F_33 ( V_14 ) ;
V_35 = V_14 -> V_59 . V_60 ;
V_51 = F_34 ( V_33 , V_61 , 0 ) ;
if ( ! V_51 )
return - V_62 ;
V_52 = F_35 ( V_51 ) ;
if ( V_52 < 0x100 )
F_11 ( V_15 , L_7 ) ;
if ( ! F_36 ( V_15 , V_51 -> V_63 , V_52 , F_37 ( V_15 ) ) )
return - V_62 ;
V_7 = F_38 ( V_15 , sizeof( struct V_1 ) ) ;
if ( F_39 ( V_7 ) )
return F_40 ( V_7 ) ;
V_2 = F_41 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = F_26 ( V_34 , V_35 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_64 = F_1 ( V_2 , V_65 ) ;
F_42 ( V_33 , V_2 ) ;
V_7 -> V_66 = L_8 ;
V_7 -> V_67 = & V_68 ;
V_7 -> V_69 = F_43 ( V_33 , 0 ) ;
V_7 -> V_70 = F_44 ( V_15 , V_51 -> V_63 ,
F_35 ( V_51 ) ) ;
if ( V_7 -> V_70 == NULL ) {
V_53 = - V_62 ;
goto V_71;
}
if ( V_2 -> V_4 ) {
if ( V_2 -> V_4 -> V_72 ) {
V_53 = V_2 -> V_4 -> V_72 ( V_33 , V_34 , V_35 ) ;
if ( V_53 )
goto V_71;
}
if ( V_2 -> V_4 -> V_73 ) {
V_7 -> V_67 = V_2 -> V_4 -> V_73 -> V_67 ;
V_7 -> V_74 |= V_2 -> V_4 -> V_73 -> V_74 ;
V_7 -> V_75 |= V_2 -> V_4 -> V_73 -> V_75 ;
V_7 -> V_24 -> V_41 |= V_2 -> V_4 -> V_73 -> V_41 ;
V_7 -> V_24 -> V_76 |= V_2 -> V_4 -> V_73 -> V_76 ;
V_7 -> V_24 -> V_77 |= V_2 -> V_4 -> V_73 -> V_77 ;
}
V_7 -> V_74 |= V_2 -> V_4 -> V_74 ;
V_7 -> V_75 |= V_2 -> V_4 -> V_75 ;
V_7 -> V_24 -> V_41 |= V_2 -> V_4 -> V_41 ;
V_7 -> V_24 -> V_76 |= V_2 -> V_4 -> V_76 ;
V_7 -> V_24 -> V_77 |= V_2 -> V_4 -> V_77 ;
}
V_7 -> V_24 -> V_76 |= V_78 ;
if ( F_1 ( V_2 , V_79 ) ) {
bool V_80 = F_1 ( V_2 , V_81 ) ;
V_53 = F_45 ( V_7 -> V_24 , NULL , 0 , V_80 , 0 , NULL ) ;
if ( V_53 ) {
if ( V_53 == - V_58 )
goto V_71;
F_46 ( V_15 , L_9 ) ;
V_2 -> V_64 = false ;
}
}
V_53 = F_47 ( V_7 ) ;
if ( V_53 )
goto V_71;
if ( V_2 -> V_64 ) {
F_48 ( V_15 ) ;
F_49 ( V_15 , 1 ) ;
F_50 ( V_15 , 50 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
}
F_53 ( V_15 ) ;
return 0 ;
V_71:
F_54 ( V_2 -> V_7 ) ;
return V_53 ;
}
static int F_55 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_23 ( V_33 ) ;
struct V_14 * V_15 = & V_33 -> V_15 ;
int V_82 ;
if ( V_2 -> V_64 ) {
F_56 ( V_15 ) ;
F_57 ( V_15 ) ;
F_58 ( V_15 ) ;
}
if ( V_2 -> V_4 && V_2 -> V_4 -> V_83 )
V_2 -> V_4 -> V_83 ( V_33 ) ;
V_82 = ( F_20 ( V_2 -> V_7 , V_84 ) == ~ 0 ) ;
F_59 ( V_2 -> V_7 , V_82 ) ;
F_54 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_61 ( V_15 ) ;
return F_62 ( V_2 -> V_7 ) ;
}
static int F_63 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_61 ( V_15 ) ;
F_9 ( & V_2 -> V_33 -> V_15 ) ;
return F_64 ( V_2 -> V_7 ) ;
}
static int F_65 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_61 ( V_15 ) ;
return F_66 ( V_2 -> V_7 ) ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_61 ( V_15 ) ;
F_9 ( & V_2 -> V_33 -> V_15 ) ;
return F_68 ( V_2 -> V_7 ) ;
}
