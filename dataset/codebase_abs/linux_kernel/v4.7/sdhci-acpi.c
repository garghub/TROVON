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
{ V_12 , 6 , 0x37 } ,
{}
} ;
return F_8 ( V_11 ) ;
}
static void F_9 ( struct V_13 * V_14 )
{
T_2 V_15 = 0 ;
if ( ! F_7 () )
return;
if ( F_10 ( V_16 , V_17 , V_18 ,
& V_15 ) ) {
F_11 ( V_14 , L_1 , V_19 ) ;
return;
}
if ( ! ( V_15 & V_20 ) )
return;
V_15 &= ~ V_20 ;
if ( F_12 ( V_16 , V_21 , V_18 ,
V_15 ) ) {
F_11 ( V_14 , L_2 , V_19 ) ;
return;
}
F_13 ( V_14 , L_3 , V_19 ) ;
}
static bool F_14 ( struct V_13 * V_14 )
{
if ( ! F_7 () )
return false ;
if ( ! F_15 () )
return true ;
F_9 ( V_14 ) ;
return false ;
}
static inline void F_9 ( struct V_13 * V_14 )
{
}
static inline bool F_14 ( struct V_13 * V_14 )
{
return false ;
}
static int F_16 ( struct V_22 * V_23 )
{
int V_24 = F_17 ( V_23 ) ;
struct V_6 * V_7 = F_18 ( V_23 ) ;
unsigned long V_5 ;
int V_25 = 0 ;
if ( ! V_24 )
return 0 ;
F_19 ( & V_7 -> V_26 , V_5 ) ;
if ( V_7 -> V_5 & V_27 )
goto V_28;
V_25 = ! ! ( F_20 ( V_7 , V_29 ) & V_30 ) ;
V_28:
F_21 ( & V_7 -> V_26 , V_5 ) ;
return V_25 ;
}
static int F_22 ( struct V_31 * V_32 ,
const char * V_33 , const char * V_34 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_33 && V_34 && ! strcmp ( V_33 , L_4 ) && ! strcmp ( V_34 , L_5 ) &&
F_20 ( V_7 , V_35 ) == 0x446cc8b2 &&
F_20 ( V_7 , V_36 ) == 0x00000807 )
V_7 -> V_37 = 1000 ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 ,
const char * V_33 , const char * V_34 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
const char * V_33 , const char * V_34 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 || ! V_2 -> V_4 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_33 && ! strcmp ( V_33 , L_6 ) ) {
V_7 -> V_38 . V_39 = F_16 ;
V_7 -> V_23 -> V_40 |= V_41 ;
}
return 0 ;
}
static const struct V_42 * F_26 ( const char * V_33 ,
const char * V_34 )
{
const struct V_43 * V_44 ;
for ( V_44 = V_45 ; V_44 -> V_33 ; V_44 ++ ) {
if ( strcmp ( V_44 -> V_33 , V_33 ) )
continue;
if ( ! V_44 -> V_34 )
return V_44 -> V_4 ;
if ( V_34 && ! strcmp ( V_44 -> V_34 , V_34 ) )
return V_44 -> V_4 ;
}
return NULL ;
}
static int F_27 ( struct V_31 * V_32 )
{
struct V_13 * V_14 = & V_32 -> V_14 ;
T_3 V_46 = F_28 ( V_14 ) ;
struct V_47 * V_13 , * V_48 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_49 * V_50 ;
T_4 V_51 ;
const char * V_33 ;
const char * V_34 ;
int V_52 ;
if ( F_29 ( V_46 , & V_13 ) )
return - V_53 ;
F_30 ( V_13 ) ;
F_31 (child, &device->children, node)
F_30 ( V_48 ) ;
if ( F_32 ( V_13 ) || ! V_13 -> V_54 . V_55 )
return - V_53 ;
if ( F_14 ( V_14 ) )
return - V_56 ;
V_33 = F_33 ( V_13 ) ;
V_34 = V_13 -> V_57 . V_58 ;
V_50 = F_34 ( V_32 , V_59 , 0 ) ;
if ( ! V_50 )
return - V_60 ;
V_51 = F_35 ( V_50 ) ;
if ( V_51 < 0x100 )
F_11 ( V_14 , L_7 ) ;
if ( ! F_36 ( V_14 , V_50 -> V_61 , V_51 , F_37 ( V_14 ) ) )
return - V_60 ;
V_7 = F_38 ( V_14 , sizeof( struct V_1 ) ) ;
if ( F_39 ( V_7 ) )
return F_40 ( V_7 ) ;
V_2 = F_41 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = F_26 ( V_33 , V_34 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_62 = F_1 ( V_2 , V_63 ) ;
F_42 ( V_32 , V_2 ) ;
V_7 -> V_64 = L_8 ;
V_7 -> V_65 = & V_66 ;
V_7 -> V_67 = F_43 ( V_32 , 0 ) ;
V_7 -> V_68 = F_44 ( V_14 , V_50 -> V_61 ,
F_35 ( V_50 ) ) ;
if ( V_7 -> V_68 == NULL ) {
V_52 = - V_60 ;
goto V_69;
}
if ( V_2 -> V_4 ) {
if ( V_2 -> V_4 -> V_70 ) {
V_52 = V_2 -> V_4 -> V_70 ( V_32 , V_33 , V_34 ) ;
if ( V_52 )
goto V_69;
}
if ( V_2 -> V_4 -> V_71 ) {
V_7 -> V_65 = V_2 -> V_4 -> V_71 -> V_65 ;
V_7 -> V_72 |= V_2 -> V_4 -> V_71 -> V_72 ;
V_7 -> V_73 |= V_2 -> V_4 -> V_71 -> V_73 ;
V_7 -> V_23 -> V_40 |= V_2 -> V_4 -> V_71 -> V_40 ;
V_7 -> V_23 -> V_74 |= V_2 -> V_4 -> V_71 -> V_74 ;
V_7 -> V_23 -> V_75 |= V_2 -> V_4 -> V_71 -> V_75 ;
}
V_7 -> V_72 |= V_2 -> V_4 -> V_72 ;
V_7 -> V_73 |= V_2 -> V_4 -> V_73 ;
V_7 -> V_23 -> V_40 |= V_2 -> V_4 -> V_40 ;
V_7 -> V_23 -> V_74 |= V_2 -> V_4 -> V_74 ;
V_7 -> V_23 -> V_75 |= V_2 -> V_4 -> V_75 ;
}
V_7 -> V_23 -> V_74 |= V_76 ;
if ( F_1 ( V_2 , V_77 ) ) {
bool V_78 = F_1 ( V_2 , V_79 ) ;
if ( F_45 ( V_7 -> V_23 , NULL , 0 , V_78 , 0 , NULL ) ) {
F_46 ( V_14 , L_9 ) ;
V_2 -> V_62 = false ;
}
}
V_52 = F_47 ( V_7 ) ;
if ( V_52 )
goto V_69;
if ( V_2 -> V_62 ) {
F_48 ( V_14 ) ;
F_49 ( V_14 , 1 ) ;
F_50 ( V_14 , 50 ) ;
F_51 ( V_14 ) ;
F_52 ( V_14 ) ;
}
F_53 ( V_14 ) ;
return 0 ;
V_69:
F_54 ( V_2 -> V_7 ) ;
return V_52 ;
}
static int F_55 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
struct V_13 * V_14 = & V_32 -> V_14 ;
int V_80 ;
if ( V_2 -> V_62 ) {
F_56 ( V_14 ) ;
F_57 ( V_14 ) ;
F_58 ( V_14 ) ;
}
if ( V_2 -> V_4 && V_2 -> V_4 -> V_81 )
V_2 -> V_4 -> V_81 ( V_32 ) ;
V_80 = ( F_20 ( V_2 -> V_7 , V_82 ) == ~ 0 ) ;
F_59 ( V_2 -> V_7 , V_80 ) ;
F_54 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_61 ( V_14 ) ;
return F_62 ( V_2 -> V_7 ) ;
}
static int F_63 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_61 ( V_14 ) ;
F_9 ( & V_2 -> V_32 -> V_14 ) ;
return F_64 ( V_2 -> V_7 ) ;
}
static int F_65 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_61 ( V_14 ) ;
return F_66 ( V_2 -> V_7 ) ;
}
static int F_67 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_61 ( V_14 ) ;
F_9 ( & V_2 -> V_32 -> V_14 ) ;
return F_68 ( V_2 -> V_7 ) ;
}
