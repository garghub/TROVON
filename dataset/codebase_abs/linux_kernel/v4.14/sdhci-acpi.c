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
static bool F_9 ( void )
{
static const struct V_10 V_14 [] = {
{ V_12 , 6 , V_15 } ,
{}
} ;
return F_8 ( V_14 ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
T_2 V_18 = 0 ;
if ( ! F_7 () )
return;
if ( F_11 ( V_19 , V_20 , V_21 ,
& V_18 ) ) {
F_12 ( V_17 , L_1 , V_22 ) ;
return;
}
if ( ! ( V_18 & V_23 ) )
return;
V_18 &= ~ V_23 ;
if ( F_13 ( V_19 , V_24 , V_21 ,
V_18 ) ) {
F_12 ( V_17 , L_2 , V_22 ) ;
return;
}
F_14 ( V_17 , L_3 , V_22 ) ;
}
static bool F_15 ( struct V_16 * V_17 )
{
if ( ! F_7 () )
return false ;
if ( ! F_16 () )
return true ;
F_10 ( V_17 ) ;
return false ;
}
static bool F_17 ( unsigned int V_25 , unsigned int V_16 ,
unsigned int V_4 , unsigned int V_26 )
{
struct V_27 * V_17 , * V_28 , * V_29 = NULL ;
while ( 1 ) {
V_17 = F_18 ( V_25 , V_16 , V_29 ) ;
F_19 ( V_29 ) ;
if ( ! V_17 )
break;
V_28 = F_20 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_17 ) && F_22 ( V_17 -> V_30 ) == V_4 &&
V_28 && F_22 ( V_28 -> V_30 ) == V_26 &&
! F_20 ( V_28 ) ) {
F_19 ( V_17 ) ;
return true ;
}
V_29 = V_17 ;
}
return false ;
}
static inline bool F_23 ( const char * V_31 ,
const char * V_32 )
{
return F_9 () &&
! strcmp ( V_31 , L_4 ) &&
! strcmp ( V_32 , L_5 ) &&
F_17 ( 0x14e4 , 0x43ec , 0 , 28 ) ;
}
static inline void F_10 ( struct V_16 * V_17 )
{
}
static inline bool F_15 ( struct V_16 * V_17 )
{
return false ;
}
static inline bool F_23 ( const char * V_31 ,
const char * V_32 )
{
return false ;
}
static int F_24 ( struct V_33 * V_34 )
{
int V_35 = F_25 ( V_34 ) ;
struct V_6 * V_7 = F_26 ( V_34 ) ;
unsigned long V_5 ;
int V_36 = 0 ;
if ( ! V_35 )
return 0 ;
F_27 ( & V_7 -> V_37 , V_5 ) ;
if ( V_7 -> V_5 & V_38 )
goto V_39;
V_36 = ! ! ( F_28 ( V_7 , V_40 ) & V_41 ) ;
V_39:
F_29 ( & V_7 -> V_37 , V_5 ) ;
return V_36 ;
}
static int F_30 ( struct V_42 * V_43 ,
const char * V_31 , const char * V_32 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_31 && V_32 && ! strcmp ( V_31 , L_4 ) && ! strcmp ( V_32 , L_6 ) &&
F_28 ( V_7 , V_44 ) == 0x446cc8b2 &&
F_28 ( V_7 , V_45 ) == 0x00000807 )
V_7 -> V_46 = 1000 ;
return 0 ;
}
static int F_32 ( struct V_42 * V_43 ,
const char * V_31 , const char * V_32 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
if ( ! V_2 || ! V_2 -> V_7 )
return 0 ;
return 0 ;
}
static int F_33 ( struct V_42 * V_43 ,
const char * V_31 , const char * V_32 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_6 * V_7 ;
if ( ! V_2 || ! V_2 -> V_7 || ! V_2 -> V_4 )
return 0 ;
V_7 = V_2 -> V_7 ;
if ( V_31 && ! strcmp ( V_31 , L_7 ) )
V_7 -> V_47 . V_48 = F_24 ;
return 0 ;
}
static const struct V_49 * F_34 ( const char * V_31 ,
const char * V_32 )
{
const struct V_50 * V_51 ;
for ( V_51 = V_52 ; V_51 -> V_31 ; V_51 ++ ) {
if ( strcmp ( V_51 -> V_31 , V_31 ) )
continue;
if ( ! V_51 -> V_32 )
return V_51 -> V_4 ;
if ( V_32 && ! strcmp ( V_51 -> V_32 , V_32 ) )
return V_51 -> V_4 ;
}
return NULL ;
}
static int F_35 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = & V_43 -> V_17 ;
struct V_53 * V_16 , * V_54 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_55 * V_56 ;
T_3 V_57 ;
const char * V_31 ;
const char * V_32 ;
int V_58 ;
V_16 = F_21 ( V_17 ) ;
if ( ! V_16 )
return - V_59 ;
V_31 = F_36 ( V_16 ) ;
V_32 = V_16 -> V_60 . V_61 ;
F_37 ( V_16 ) ;
if ( ! F_23 ( V_31 , V_32 ) ) {
F_38 (child, &device->children, node)
if ( V_54 -> V_62 . V_63 && V_54 -> V_62 . V_64 )
F_37 ( V_54 ) ;
}
if ( F_15 ( V_17 ) )
return - V_65 ;
V_56 = F_39 ( V_43 , V_66 , 0 ) ;
if ( ! V_56 )
return - V_67 ;
V_57 = F_40 ( V_56 ) ;
if ( V_57 < 0x100 )
F_12 ( V_17 , L_8 ) ;
if ( ! F_41 ( V_17 , V_56 -> V_68 , V_57 , F_42 ( V_17 ) ) )
return - V_67 ;
V_7 = F_43 ( V_17 , sizeof( struct V_1 ) ) ;
if ( F_44 ( V_7 ) )
return F_45 ( V_7 ) ;
V_2 = F_46 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = F_34 ( V_31 , V_32 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_69 = F_1 ( V_2 , V_70 ) ;
F_47 ( V_43 , V_2 ) ;
V_7 -> V_71 = L_9 ;
V_7 -> V_72 = & V_73 ;
V_7 -> V_74 = F_48 ( V_43 , 0 ) ;
V_7 -> V_75 = F_49 ( V_17 , V_56 -> V_68 ,
F_40 ( V_56 ) ) ;
if ( V_7 -> V_75 == NULL ) {
V_58 = - V_67 ;
goto V_76;
}
if ( V_2 -> V_4 ) {
if ( V_2 -> V_4 -> V_77 ) {
V_58 = V_2 -> V_4 -> V_77 ( V_43 , V_31 , V_32 ) ;
if ( V_58 )
goto V_76;
}
if ( V_2 -> V_4 -> V_78 ) {
V_7 -> V_72 = V_2 -> V_4 -> V_78 -> V_72 ;
V_7 -> V_79 |= V_2 -> V_4 -> V_78 -> V_79 ;
V_7 -> V_80 |= V_2 -> V_4 -> V_78 -> V_80 ;
V_7 -> V_34 -> V_81 |= V_2 -> V_4 -> V_78 -> V_81 ;
V_7 -> V_34 -> V_82 |= V_2 -> V_4 -> V_78 -> V_82 ;
V_7 -> V_34 -> V_83 |= V_2 -> V_4 -> V_78 -> V_83 ;
}
V_7 -> V_79 |= V_2 -> V_4 -> V_79 ;
V_7 -> V_80 |= V_2 -> V_4 -> V_80 ;
V_7 -> V_34 -> V_81 |= V_2 -> V_4 -> V_81 ;
V_7 -> V_34 -> V_82 |= V_2 -> V_4 -> V_82 ;
V_7 -> V_34 -> V_83 |= V_2 -> V_4 -> V_83 ;
}
V_7 -> V_34 -> V_82 |= V_84 ;
if ( F_1 ( V_2 , V_85 ) ) {
bool V_86 = F_1 ( V_2 , V_87 ) ;
V_58 = F_50 ( V_7 -> V_34 , NULL , 0 , V_86 , 0 , NULL ) ;
if ( V_58 ) {
if ( V_58 == - V_65 )
goto V_76;
F_51 ( V_17 , L_10 ) ;
V_2 -> V_69 = false ;
}
}
V_58 = F_52 ( V_7 ) ;
if ( V_58 )
goto V_76;
if ( V_2 -> V_69 ) {
F_53 ( V_17 ) ;
F_54 ( V_17 , 1 ) ;
F_55 ( V_17 , 50 ) ;
F_56 ( V_17 ) ;
F_57 ( V_17 ) ;
}
F_58 ( V_17 ) ;
return 0 ;
V_76:
F_59 ( V_2 -> V_7 ) ;
return V_58 ;
}
static int F_60 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_16 * V_17 = & V_43 -> V_17 ;
int V_88 ;
if ( V_2 -> V_69 ) {
F_61 ( V_17 ) ;
F_62 ( V_17 ) ;
F_63 ( V_17 ) ;
}
if ( V_2 -> V_4 && V_2 -> V_4 -> V_89 )
V_2 -> V_4 -> V_89 ( V_43 ) ;
V_88 = ( F_28 ( V_2 -> V_7 , V_90 ) == ~ 0 ) ;
F_64 ( V_2 -> V_7 , V_88 ) ;
F_59 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_66 ( V_17 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_91 != V_92 )
F_67 ( V_7 -> V_34 ) ;
return F_68 ( V_7 ) ;
}
static int F_69 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_66 ( V_17 ) ;
F_10 ( & V_2 -> V_43 -> V_17 ) ;
return F_70 ( V_2 -> V_7 ) ;
}
static int F_71 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_66 ( V_17 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_91 != V_92 )
F_67 ( V_7 -> V_34 ) ;
return F_72 ( V_7 ) ;
}
static int F_73 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_66 ( V_17 ) ;
F_10 ( & V_2 -> V_43 -> V_17 ) ;
return F_74 ( V_2 -> V_7 ) ;
}
