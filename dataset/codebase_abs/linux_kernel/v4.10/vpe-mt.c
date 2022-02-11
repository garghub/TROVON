int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
F_2 ( V_3 ) ;
V_4 = F_3 () ;
if ( ! ( V_4 & V_11 ) ) {
F_4 ( L_1 ) ;
F_5 ( V_3 ) ;
return - 1 ;
}
V_5 = F_6 () ;
V_8 = F_7 () ;
if ( F_8 ( & V_2 -> V_9 ) ) {
F_9 ( V_8 ) ;
F_10 ( V_5 ) ;
F_5 ( V_3 ) ;
F_4 ( L_2 ,
V_2 -> V_12 ) ;
return - V_13 ;
}
V_10 = F_11 ( & V_2 -> V_9 , struct V_9 , V_9 ) ;
F_12 ( V_14 ) ;
F_13 ( V_10 -> V_15 ) ;
if ( ( F_14 () & V_16 ) ||
! ( F_15 () & V_17 ) ) {
F_9 ( V_8 ) ;
F_10 ( V_5 ) ;
F_5 ( V_3 ) ;
F_4 ( L_3 ,
V_10 -> V_15 ) ;
return - V_13 ;
}
F_16 ( ( unsigned long ) V_2 -> V_18 ) ;
F_17 ( ( unsigned long ) 0 ) ;
V_4 = F_14 () ;
V_4 = ( V_4 & ~ ( V_19 | V_20 ) ) | V_16 ;
F_18 ( V_4 ) ;
F_19 ( F_15 () & ~ V_17 ) ;
F_20 ( 6 , V_2 -> V_21 ) ;
F_20 ( 7 , V_22 ) ;
F_21 ( ( F_22 () & ~ V_23 ) | 1 ) ;
F_23 ( F_24 () & ~ ( V_24 ) ) ;
F_25 () ;
F_23 ( ( F_24 () & ~ ( V_25 ) )
| ( V_10 -> V_15 << V_26 ) ) ;
F_25 () ;
F_23 ( F_24 () | V_24 ) ;
F_26 ( 0 ) ;
F_27 ( 0 ) ;
F_28 ( V_14 ) ;
#ifdef F_29
F_9 ( V_8 ) ;
#else
F_9 ( V_27 ) ;
#endif
F_10 ( V_5 ) ;
F_5 ( V_3 ) ;
F_30 (notifier, &v->notify, list)
V_7 -> V_28 ( V_29 ) ;
return 0 ;
}
void F_31 ( struct V_9 * V_9 )
{
unsigned long V_3 ;
unsigned int V_30 , V_31 ;
int V_32 ;
F_2 ( V_3 ) ;
V_30 = F_6 () ;
V_31 = F_7 () ;
F_12 ( V_14 ) ;
F_13 ( V_9 -> V_15 ) ;
V_32 = F_14 () ;
V_32 &= ~ ( V_16 | V_19 ) ;
V_32 |= V_20 ;
F_18 ( V_32 ) ;
F_19 ( V_17 ) ;
F_32 () ;
F_28 ( V_14 ) ;
F_9 ( V_31 ) ;
F_10 ( V_30 ) ;
F_5 ( V_3 ) ;
}
void * F_33 ( void )
{
int V_33 ;
struct V_1 * V_2 ;
for ( V_33 = 1 ; V_33 < V_34 ; V_33 ++ ) {
V_2 = F_34 ( V_33 ) ;
if ( V_2 != NULL ) {
V_2 -> V_35 = V_36 ;
return V_2 ;
}
}
return NULL ;
}
int F_35 ( void * V_1 , unsigned long V_28 )
{
struct V_1 * V_2 = V_1 ;
V_2 -> V_18 = V_28 ;
return F_1 ( V_2 ) ;
}
int F_36 ( void * V_1 )
{
struct V_1 * V_2 = V_1 ;
struct V_9 * V_10 ;
unsigned int V_37 ;
V_37 = F_7 () ;
V_10 = F_37 ( V_2 -> V_9 . V_38 , struct V_9 , V_9 ) ;
if ( V_10 != NULL ) {
F_13 ( V_10 -> V_15 ) ;
F_23 ( F_24 () & ~ V_24 ) ;
}
F_9 ( V_37 ) ;
return 0 ;
}
int F_38 ( void * V_1 )
{
struct V_1 * V_2 = V_1 ;
struct V_9 * V_10 ;
unsigned int V_37 ;
V_10 = F_37 ( V_2 -> V_9 . V_38 , struct V_9 , V_9 ) ;
if ( V_10 == NULL )
return - V_13 ;
V_37 = F_7 () ;
F_12 ( V_14 ) ;
F_13 ( V_10 -> V_15 ) ;
F_23 ( F_24 () & ~ V_24 ) ;
F_19 ( V_17 ) ;
F_32 () ;
F_18 ( F_14 () & ~ V_16 ) ;
V_2 -> V_35 = V_39 ;
F_28 ( V_14 ) ;
F_9 ( V_37 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_44 , T_2 V_45 )
{
struct V_1 * V_1 = F_34 ( F_40 () ) ;
struct V_6 * V_7 ;
F_30 (notifier, &vpe->notify, list)
V_7 -> V_46 ( F_40 () ) ;
F_41 ( V_1 -> V_47 ) ;
F_31 ( F_42 ( F_40 () ) ) ;
F_36 ( V_1 ) ;
F_38 ( V_1 ) ;
return V_45 ;
}
static T_1 F_43 ( struct V_40 * V_48 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_1 = F_34 ( F_40 () ) ;
return sprintf ( V_44 , L_4 , V_1 -> V_21 ) ;
}
static T_1 F_44 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_44 , T_2 V_45 )
{
struct V_1 * V_1 = F_34 ( F_40 () ) ;
unsigned long V_49 ;
int V_50 ;
V_50 = F_45 ( V_44 , 0 , & V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_49 == 0 || V_49 > ( V_51 - F_40 () ) )
return - V_52 ;
V_1 -> V_21 = V_49 ;
return V_45 ;
}
static void F_46 ( struct V_40 * V_48 )
{
F_47 ( V_48 ) ;
}
int T_3 F_48 ( void )
{
unsigned int V_30 , V_31 ;
unsigned long V_3 , V_4 ;
struct V_1 * V_2 = NULL ;
struct V_9 * V_10 ;
int V_9 , V_53 ;
if ( ! V_54 ) {
F_4 ( L_5 ) ;
return - V_55 ;
}
if ( V_56 == 0 ) {
F_4 ( L_6
L_7 ) ;
return - V_55 ;
}
if ( F_40 () == 0 ) {
F_4 ( L_8
L_9 ) ;
return - V_55 ;
}
V_57 = F_49 ( 0 , V_58 , & V_59 ) ;
if ( V_57 < 0 ) {
F_4 ( L_10 ) ;
return V_57 ;
}
V_53 = F_50 ( & V_60 ) ;
if ( V_53 ) {
F_51 ( L_11 ) ;
goto V_61;
}
F_52 ( & V_62 ) ;
V_62 . V_63 = & V_60 ,
V_62 . V_64 = NULL ,
F_53 ( & V_62 , L_12 ) ;
V_62 . V_65 = F_54 ( V_57 , V_29 ) ;
V_53 = F_55 ( & V_62 ) ;
if ( V_53 ) {
F_51 ( L_13 ) ;
goto V_66;
}
F_2 ( V_3 ) ;
V_30 = F_6 () ;
V_31 = F_7 () ;
F_12 ( V_14 ) ;
V_4 = F_56 () ;
V_51 = ( V_4 & V_67 ) + 1 ;
V_68 = ( ( V_4 & V_69 ) >> V_70 ) + 1 ;
for ( V_9 = F_40 () ; V_9 < V_51 ; V_9 ++ ) {
F_28 ( V_14 ) ;
F_9 ( V_31 ) ;
F_10 ( V_30 ) ;
F_5 ( V_3 ) ;
V_10 = F_57 ( V_9 ) ;
if ( ! V_10 ) {
V_53 = - V_71 ;
goto V_72;
}
F_2 ( V_3 ) ;
V_30 = F_6 () ;
V_31 = F_7 () ;
F_12 ( V_14 ) ;
if ( V_9 < V_51 ) {
F_13 ( V_9 ) ;
V_2 = F_58 ( V_9 ) ;
if ( V_2 == NULL ) {
F_4 ( L_14 ) ;
goto V_73;
}
V_2 -> V_21 = V_51 - F_40 () ;
F_59 ( & V_10 -> V_9 , & V_2 -> V_9 ) ;
if ( V_9 >= F_40 () ) {
unsigned long V_32 = F_24 () ;
V_32 &= ~ V_24 ;
V_32 |= V_11 ;
F_23 ( V_32 ) ;
}
F_60 ( F_61 () &
~ V_74 ) ;
if ( V_9 >= V_56 ) {
F_62 ( F_63 () ) ;
}
}
V_10 -> V_75 = V_2 ;
if ( V_9 >= F_40 () ) {
unsigned long V_32 ;
F_13 ( V_9 ) ;
V_32 = F_22 () ;
if ( V_32 & V_23 ) {
F_21 ( V_32 & ~ V_23 ) ;
V_10 -> V_75 = F_34 ( 0 ) ;
}
F_19 ( V_17 ) ;
F_32 () ;
V_32 = F_14 () ;
V_32 &= ~ ( V_16 | V_19 ) ;
V_32 |= V_20 ;
F_18 ( V_32 ) ;
}
}
V_73:
F_28 ( V_14 ) ;
F_9 ( V_31 ) ;
F_10 ( V_30 ) ;
F_5 ( V_3 ) ;
return 0 ;
V_72:
F_64 ( & V_62 ) ;
V_66:
F_65 ( & V_60 ) ;
V_61:
F_66 ( V_57 , V_58 ) ;
return V_53 ;
}
void T_4 F_67 ( void )
{
struct V_1 * V_2 , * V_76 ;
F_64 ( & V_62 ) ;
F_65 ( & V_60 ) ;
F_66 ( V_57 , V_58 ) ;
F_68 (v, n, &vpecontrol.vpe_list, list) {
if ( V_2 -> V_35 != V_39 )
F_69 ( V_2 ) ;
}
}
