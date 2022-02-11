static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 , * V_4 ;
if ( ! V_2 )
return NULL ;
V_3 = NULL ;
F_2 (temp_clkdm, &clkdm_list, node) {
if ( ! strcmp ( V_2 , V_4 -> V_2 ) ) {
V_3 = V_4 ;
break;
}
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_3 )
{
struct V_5 * V_6 ;
if ( ! V_3 || ! V_3 -> V_2 )
return - V_7 ;
V_6 = F_4 ( V_3 -> V_6 . V_2 ) ;
if ( ! V_6 ) {
F_5 ( L_1 ,
V_3 -> V_2 , V_3 -> V_6 . V_2 ) ;
return - V_7 ;
}
V_3 -> V_6 . V_8 = V_6 ;
if ( F_1 ( V_3 -> V_2 ) )
return - V_9 ;
F_6 ( & V_3 -> V_10 , & V_11 ) ;
F_7 ( V_6 , V_3 ) ;
F_8 ( L_2 , V_3 -> V_2 ) ;
return 0 ;
}
static struct V_12 * F_9 ( struct V_1 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_14 ;
if ( ! V_3 || ! V_13 )
return F_10 ( - V_7 ) ;
for ( V_14 = V_13 ; V_14 -> V_15 ; V_14 ++ ) {
if ( ! V_14 -> V_3 && V_14 -> V_15 )
V_14 -> V_3 = F_1 ( V_14 -> V_15 ) ;
if ( V_14 -> V_3 == V_3 )
break;
}
if ( ! V_14 -> V_15 )
return F_10 ( - V_16 ) ;
return V_14 ;
}
static void F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_3 ;
if ( ! V_18 )
return;
V_3 = F_12 ( V_18 -> V_3 . V_2 ) ;
if ( ! V_3 ) {
F_5 ( L_3 ,
V_18 -> V_3 . V_2 ) ;
V_3 = F_10 ( - V_16 ) ;
}
V_18 -> V_3 . V_8 = V_3 ;
}
static void F_13 ( struct V_1 * V_3 ,
struct V_12 * V_19 )
{
struct V_12 * V_14 ;
for ( V_14 = V_19 ; V_14 && V_14 -> V_15 ; V_14 ++ ) {
if ( V_14 -> V_3 )
continue;
V_14 -> V_3 = F_1 ( V_14 -> V_15 ) ;
F_14 ( ! V_14 -> V_3 , L_4 ,
V_3 -> V_2 , V_14 -> V_15 ) ;
}
}
static int F_15 ( struct V_1 * V_20 ,
struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_25 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_5 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
V_14 -> V_26 ++ ;
if ( V_14 -> V_26 == 1 ) {
F_8 ( L_6 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
V_22 = V_24 -> V_25 ( V_20 , V_21 ) ;
}
return V_22 ;
}
static int F_18 ( struct V_1 * V_20 ,
struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_27 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_5 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
V_14 -> V_26 -- ;
if ( V_14 -> V_26 == 0 ) {
F_8 ( L_7 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
V_22 = V_24 -> V_27 ( V_20 , V_21 ) ;
}
return V_22 ;
}
static int F_19 ( struct V_1 * V_20 ,
struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_28 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_29 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_8 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
V_14 -> V_30 ++ ;
if ( V_14 -> V_30 == 1 ) {
F_8 ( L_9 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
V_22 = V_24 -> V_29 ( V_20 , V_21 ) ;
}
return V_22 ;
}
static int F_20 ( struct V_1 * V_20 ,
struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_28 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_31 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_8 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
V_14 -> V_30 -- ;
if ( V_14 -> V_30 == 0 ) {
F_8 ( L_10 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
V_22 = V_24 -> V_31 ( V_20 , V_21 ) ;
}
return V_22 ;
}
int F_21 ( struct V_32 * V_33 )
{
if ( ! V_33 )
return - V_7 ;
if ( V_24 )
return - V_9 ;
V_24 = V_33 ;
return 0 ;
}
int F_22 ( struct V_1 * * V_34 )
{
struct V_1 * * V_35 = NULL ;
if ( ! V_24 )
return - V_36 ;
if ( ! V_34 )
return - V_7 ;
for ( V_35 = V_34 ; * V_35 ; V_35 ++ )
F_3 ( * V_35 ) ;
return 0 ;
}
int F_23 ( struct V_17 * V_37 )
{
struct V_17 * V_38 = NULL ;
if ( F_24 ( & V_11 ) )
return - V_36 ;
if ( ! V_37 )
return - V_7 ;
if ( V_39 )
return - V_9 ;
V_39 = V_37 ;
for ( V_38 = V_39 ; V_38 -> V_3 . V_8 ; V_38 ++ )
F_11 ( V_38 ) ;
return 0 ;
}
int F_25 ( void )
{
struct V_1 * V_3 ;
if ( F_24 ( & V_11 ) )
return - V_36 ;
F_2 (clkdm, &clkdm_list, node) {
F_26 ( V_3 ) ;
F_13 ( V_3 , V_3 -> V_23 ) ;
F_27 ( V_3 ) ;
F_13 ( V_3 , V_3 -> V_28 ) ;
F_28 ( V_3 ) ;
}
return 0 ;
}
struct V_1 * F_12 ( const char * V_2 )
{
struct V_1 * V_3 , * V_4 ;
if ( ! V_2 )
return NULL ;
V_3 = NULL ;
F_2 (temp_clkdm, &clkdm_list, node) {
if ( ! strcmp ( V_2 , V_4 -> V_2 ) ) {
V_3 = V_4 ;
break;
}
}
return V_3 ;
}
int F_29 ( int (* F_30)( struct V_1 * V_3 , void * V_40 ) ,
void * V_40 )
{
struct V_1 * V_3 ;
int V_22 = 0 ;
if ( ! F_30 )
return - V_7 ;
F_2 (clkdm, &clkdm_list, node) {
V_22 = (* F_30)( V_3 , V_40 ) ;
if ( V_22 )
break;
}
return V_22 ;
}
struct V_5 * F_31 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return NULL ;
return V_3 -> V_6 . V_8 ;
}
int V_25 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_32 ( V_14 -> V_3 -> V_6 . V_8 ) ;
V_22 = F_15 ( V_20 , V_21 ) ;
F_33 ( V_14 -> V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int V_27 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_32 ( V_14 -> V_3 -> V_6 . V_8 ) ;
V_22 = F_18 ( V_20 , V_21 ) ;
F_33 ( V_14 -> V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int F_34 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> F_34 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_5 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
return V_24 -> F_34 ( V_20 , V_21 ) ;
}
int F_27 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_7 ;
if ( ! V_24 || ! V_24 -> F_27 )
return - V_7 ;
return V_24 -> F_27 ( V_3 ) ;
}
int V_29 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_32 ( V_14 -> V_3 -> V_6 . V_8 ) ;
V_22 = F_19 ( V_20 , V_21 ) ;
F_33 ( V_14 -> V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int V_31 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_23 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_32 ( V_14 -> V_3 -> V_6 . V_8 ) ;
V_22 = F_20 ( V_20 , V_21 ) ;
F_33 ( V_14 -> V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int F_35 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
struct V_12 * V_14 ;
int V_22 = 0 ;
if ( ! V_20 || ! V_21 )
return - V_7 ;
V_14 = F_9 ( V_21 , V_20 -> V_28 ) ;
if ( F_16 ( V_14 ) )
V_22 = F_17 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> F_35 )
V_22 = - V_7 ;
if ( V_22 ) {
F_8 ( L_8 ,
V_20 -> V_2 , V_21 -> V_2 ) ;
return V_22 ;
}
return V_24 -> F_35 ( V_20 , V_21 ) ;
}
int F_28 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_7 ;
if ( ! V_24 || ! V_24 -> F_28 )
return - V_7 ;
return V_24 -> F_28 ( V_3 ) ;
}
int F_36 ( struct V_1 * V_3 )
{
int V_22 ;
if ( ! V_3 )
return - V_7 ;
if ( ! ( V_3 -> V_41 & V_42 ) ) {
F_8 ( L_11 ,
V_3 -> V_2 ) ;
return - V_7 ;
}
if ( ! V_24 || ! V_24 -> V_43 )
return - V_7 ;
F_8 ( L_12 , V_3 -> V_2 ) ;
V_3 -> V_44 &= ~ V_45 ;
V_22 = V_24 -> V_43 ( V_3 ) ;
V_22 |= F_37 ( V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int V_43 ( struct V_1 * V_3 )
{
int V_22 ;
F_32 ( V_3 -> V_6 . V_8 ) ;
V_22 = F_36 ( V_3 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int F_38 ( struct V_1 * V_3 )
{
int V_22 ;
if ( ! V_3 )
return - V_7 ;
if ( ! ( V_3 -> V_41 & V_46 ) ) {
F_8 ( L_13 ,
V_3 -> V_2 ) ;
return - V_7 ;
}
if ( ! V_24 || ! V_24 -> V_47 )
return - V_7 ;
F_8 ( L_14 , V_3 -> V_2 ) ;
V_3 -> V_44 &= ~ V_45 ;
V_22 = V_24 -> V_47 ( V_3 ) ;
V_22 |= F_37 ( V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
int V_47 ( struct V_1 * V_3 )
{
int V_22 ;
F_32 ( V_3 -> V_6 . V_8 ) ;
V_22 = F_38 ( V_3 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
return V_22 ;
}
void F_39 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
if ( ! F_40 ( ! V_3 -> V_48 ) )
V_3 -> V_48 -- ;
if ( V_3 -> V_48 )
return;
if ( ! V_3 -> V_49 && ( V_3 -> V_41 & V_42 ) )
F_36 ( V_3 ) ;
if ( ! ( V_3 -> V_41 & V_50 ) )
return;
if ( V_3 -> V_41 & V_51 )
return;
if ( ! V_24 || ! V_24 -> V_52 )
return;
F_8 ( L_15 ,
V_3 -> V_2 ) ;
V_3 -> V_44 |= V_45 ;
V_24 -> V_52 ( V_3 ) ;
F_37 ( V_3 -> V_6 . V_8 ) ;
}
void V_52 ( struct V_1 * V_3 )
{
F_32 ( V_3 -> V_6 . V_8 ) ;
F_39 ( V_3 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
}
void F_41 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_48 ++ )
return;
if ( V_3 -> V_41 & V_46 )
F_38 ( V_3 ) ;
if ( ! ( V_3 -> V_41 & V_53 ) )
return;
if ( V_3 -> V_41 & V_51 )
return;
if ( ! V_24 || ! V_24 -> F_26 )
return;
F_8 ( L_16 ,
V_3 -> V_2 ) ;
V_3 -> V_44 &= ~ V_45 ;
V_24 -> F_26 ( V_3 ) ;
F_37 ( V_3 -> V_6 . V_8 ) ;
}
void F_26 ( struct V_1 * V_3 )
{
F_32 ( V_3 -> V_6 . V_8 ) ;
F_41 ( V_3 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
}
bool F_42 ( struct V_1 * V_3 )
{
bool V_22 ;
if ( ! V_3 )
return false ;
V_22 = ( V_3 -> V_44 & V_45 ) ? true : false ;
return V_22 ;
}
bool F_43 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return false ;
return ( V_3 -> V_41 & V_51 ) ? true : false ;
}
void F_44 ( struct V_1 * V_3 )
{
struct V_17 * V_18 ;
if ( ! V_39 || V_3 -> V_41 & V_54 )
return;
for ( V_18 = V_39 ; V_18 -> V_3 . V_8 ; V_18 ++ ) {
if ( F_16 ( V_18 -> V_3 . V_8 ) )
continue;
F_8 ( L_17 ,
V_3 -> V_2 , V_18 -> V_3 . V_8 -> V_2 ) ;
F_19 ( V_3 , V_18 -> V_3 . V_8 ) ;
F_15 ( V_3 , V_18 -> V_3 . V_8 ) ;
}
}
void F_45 ( struct V_1 * V_3 )
{
struct V_17 * V_18 ;
if ( ! V_39 || V_3 -> V_41 & V_54 )
return;
for ( V_18 = V_39 ; V_18 -> V_3 . V_8 ; V_18 ++ ) {
if ( F_16 ( V_18 -> V_3 . V_8 ) )
continue;
F_8 ( L_18 ,
V_3 -> V_2 , V_18 -> V_3 . V_8 -> V_2 ) ;
F_20 ( V_3 , V_18 -> V_3 . V_8 ) ;
F_18 ( V_3 , V_18 -> V_3 . V_8 ) ;
}
}
static int F_46 ( struct V_1 * V_3 )
{
if ( ! V_3 || ! V_24 || ! V_24 -> V_55 )
return - V_7 ;
F_32 ( V_3 -> V_6 . V_8 ) ;
V_3 -> V_49 ++ ;
if ( V_3 -> V_49 > 1 && V_39 ) {
F_33 ( V_3 -> V_6 . V_8 ) ;
return 0 ;
}
V_24 -> V_55 ( V_3 ) ;
F_37 ( V_3 -> V_6 . V_8 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
F_8 ( L_19 , V_3 -> V_2 ) ;
return 0 ;
}
int V_55 ( struct V_1 * V_3 , struct V_56 * V_56 )
{
if ( ! V_56 )
return - V_7 ;
return F_46 ( V_3 ) ;
}
int F_47 ( struct V_1 * V_3 , struct V_56 * V_56 )
{
if ( ! V_3 || ! V_56 || ! V_24 || ! V_24 -> F_47 )
return - V_7 ;
F_32 ( V_3 -> V_6 . V_8 ) ;
if ( ( F_48 ( V_56 ) == 0 ) && V_3 -> V_49 == 0 )
goto V_57;
if ( V_3 -> V_49 == 0 ) {
F_33 ( V_3 -> V_6 . V_8 ) ;
F_40 ( 1 ) ;
return - V_58 ;
}
V_3 -> V_49 -- ;
if ( V_3 -> V_49 > 0 ) {
F_33 ( V_3 -> V_6 . V_8 ) ;
return 0 ;
}
V_24 -> F_47 ( V_3 ) ;
F_37 ( V_3 -> V_6 . V_8 ) ;
F_8 ( L_20 , V_3 -> V_2 ) ;
V_57:
F_33 ( V_3 -> V_6 . V_8 ) ;
return 0 ;
}
T_1 F_49 ( struct V_1 * V_3 )
{
if ( V_24 -> F_49 )
return V_24 -> F_49 ( V_3 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_3 , struct V_59 * V_60 )
{
if ( F_51 () || F_52 () )
return 0 ;
if ( ! V_60 )
return - V_7 ;
return F_46 ( V_3 ) ;
}
int F_53 ( struct V_1 * V_3 , struct V_59 * V_60 )
{
if ( F_51 () || F_52 () )
return 0 ;
if ( ! V_3 || ! V_60 || ! V_24 || ! V_24 -> F_47 )
return - V_7 ;
F_32 ( V_3 -> V_6 . V_8 ) ;
if ( V_3 -> V_49 == 0 ) {
F_33 ( V_3 -> V_6 . V_8 ) ;
F_40 ( 1 ) ;
return - V_58 ;
}
V_3 -> V_49 -- ;
if ( V_3 -> V_49 > 0 ) {
F_33 ( V_3 -> V_6 . V_8 ) ;
return 0 ;
}
V_24 -> F_47 ( V_3 ) ;
F_37 ( V_3 -> V_6 . V_8 ) ;
F_33 ( V_3 -> V_6 . V_8 ) ;
F_8 ( L_20 , V_3 -> V_2 ) ;
return 0 ;
}
