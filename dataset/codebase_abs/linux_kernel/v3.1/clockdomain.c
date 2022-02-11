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
if ( ! F_4 ( V_3 -> V_8 ) )
return - V_7 ;
V_6 = F_5 ( V_3 -> V_6 . V_2 ) ;
if ( ! V_6 ) {
F_6 ( L_1 ,
V_3 -> V_2 , V_3 -> V_6 . V_2 ) ;
return - V_7 ;
}
V_3 -> V_6 . V_9 = V_6 ;
if ( F_1 ( V_3 -> V_2 ) )
return - V_10 ;
F_7 ( & V_3 -> V_11 , & V_12 ) ;
F_8 ( V_6 , V_3 ) ;
F_9 ( & V_3 -> V_13 ) ;
F_10 ( L_2 , V_3 -> V_2 ) ;
return 0 ;
}
static struct V_14 * F_11 ( struct V_1 * V_3 ,
struct V_14 * V_15 )
{
struct V_14 * V_16 ;
if ( ! V_3 || ! V_15 || ! F_4 ( V_3 -> V_8 ) )
return F_12 ( - V_7 ) ;
for ( V_16 = V_15 ; V_16 -> V_17 ; V_16 ++ ) {
if ( ! F_4 ( V_16 -> V_8 ) )
continue;
if ( ! V_16 -> V_3 && V_16 -> V_17 )
V_16 -> V_3 = F_1 ( V_16 -> V_17 ) ;
if ( V_16 -> V_3 == V_3 )
break;
}
if ( ! V_16 -> V_17 )
return F_12 ( - V_18 ) ;
return V_16 ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_3 ;
if ( ! V_20 )
return;
if ( ! F_4 ( V_20 -> V_8 ) )
return;
V_3 = F_14 ( V_20 -> V_3 . V_2 ) ;
if ( ! V_3 ) {
F_6 ( L_3 ,
V_20 -> V_3 . V_2 ) ;
V_3 = F_12 ( - V_18 ) ;
}
V_20 -> V_3 . V_9 = V_3 ;
}
void F_15 ( struct V_1 * V_3 )
{
struct V_19 * V_20 ;
if ( ! V_21 || V_3 -> V_22 & V_23 )
return;
for ( V_20 = V_21 ; V_20 -> V_3 . V_9 ; V_20 ++ ) {
if ( F_16 ( V_20 -> V_3 . V_9 ) )
continue;
if ( ! F_4 ( V_20 -> V_8 ) )
continue;
F_10 ( L_4
L_5 , V_20 -> V_3 . V_9 -> V_2 ,
V_3 -> V_2 ) ;
F_17 ( V_3 , V_20 -> V_3 . V_9 ) ;
F_18 ( V_3 , V_20 -> V_3 . V_9 ) ;
}
}
void F_19 ( struct V_1 * V_3 )
{
struct V_19 * V_20 ;
if ( ! V_21 || V_3 -> V_22 & V_23 )
return;
for ( V_20 = V_21 ; V_20 -> V_3 . V_9 ; V_20 ++ ) {
if ( F_16 ( V_20 -> V_3 . V_9 ) )
continue;
if ( ! F_4 ( V_20 -> V_8 ) )
continue;
F_10 ( L_6
L_5 , V_20 -> V_3 . V_9 -> V_2 ,
V_3 -> V_2 ) ;
F_20 ( V_3 , V_20 -> V_3 . V_9 ) ;
F_21 ( V_3 , V_20 -> V_3 . V_9 ) ;
}
}
static void F_22 ( struct V_1 * V_3 ,
struct V_14 * V_24 )
{
struct V_14 * V_16 ;
for ( V_16 = V_24 ; V_16 && V_16 -> V_17 ; V_16 ++ ) {
if ( ! F_4 ( V_16 -> V_8 ) )
continue;
if ( V_16 -> V_3 )
continue;
V_16 -> V_3 = F_1 ( V_16 -> V_17 ) ;
F_23 ( ! V_16 -> V_3 , L_7 ,
V_3 -> V_2 , V_16 -> V_17 ) ;
}
}
void F_24 ( struct V_1 * * V_25 ,
struct V_19 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * * V_29 = NULL ;
struct V_1 * V_3 ;
struct V_19 * V_20 = NULL ;
if ( ! V_28 )
F_23 ( 1 , L_8 ) ;
else
V_30 = V_28 ;
if ( V_25 )
for ( V_29 = V_25 ; * V_29 ; V_29 ++ )
F_3 ( * V_29 ) ;
V_21 = V_26 ;
if ( V_21 )
for ( V_20 = V_21 ; V_20 -> V_3 . V_9 ; V_20 ++ )
F_13 ( V_20 ) ;
F_2 (clkdm, &clkdm_list, node) {
if ( V_3 -> V_22 & V_31 )
F_25 ( V_3 ) ;
else if ( V_3 -> V_22 & V_32 )
F_26 ( V_3 ) ;
F_22 ( V_3 , V_3 -> V_33 ) ;
F_27 ( V_3 ) ;
F_22 ( V_3 , V_3 -> V_34 ) ;
F_28 ( V_3 ) ;
}
}
struct V_1 * F_14 ( const char * V_2 )
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
int F_29 ( int (* F_30)( struct V_1 * V_3 , void * V_35 ) ,
void * V_35 )
{
struct V_1 * V_3 ;
int V_36 = 0 ;
if ( ! F_30 )
return - V_7 ;
F_2 (clkdm, &clkdm_list, node) {
V_36 = (* F_30)( V_3 , V_35 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
struct V_5 * F_31 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return NULL ;
return V_3 -> V_6 . V_9 ;
}
int F_18 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_33 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_18 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_9
L_10 , V_37 -> V_2 , V_38 -> V_2 ) ;
return V_36 ;
}
if ( F_33 ( & V_16 -> V_39 ) == 1 ) {
F_10 ( L_11
L_12 , V_37 -> V_2 , V_38 -> V_2 ) ;
V_36 = V_30 -> F_18 ( V_37 , V_38 ) ;
}
return V_36 ;
}
int F_21 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_33 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_21 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_9
L_10 , V_37 -> V_2 , V_38 -> V_2 ) ;
return V_36 ;
}
if ( F_34 ( & V_16 -> V_39 ) == 0 ) {
F_10 ( L_13
L_14 , V_37 -> V_2 , V_38 -> V_2 ) ;
V_36 = V_30 -> F_21 ( V_37 , V_38 ) ;
}
return V_36 ;
}
int F_35 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_33 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_35 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_9
L_10 , V_37 -> V_2 , V_38 -> V_2 ) ;
return V_36 ;
}
return V_30 -> F_35 ( V_37 , V_38 ) ;
}
int F_27 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_7 ;
if ( ! V_30 || ! V_30 -> F_27 )
return - V_7 ;
return V_30 -> F_27 ( V_3 ) ;
}
int F_17 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_34 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_17 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_15
L_16 , V_37 -> V_2 ,
V_38 -> V_2 ) ;
return V_36 ;
}
if ( F_33 ( & V_16 -> V_40 ) == 1 ) {
F_10 ( L_17
L_18 , V_37 -> V_2 , V_38 -> V_2 ) ;
V_36 = V_30 -> F_17 ( V_37 , V_38 ) ;
}
return V_36 ;
}
int F_20 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_34 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_20 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_15
L_16 , V_37 -> V_2 ,
V_38 -> V_2 ) ;
return V_36 ;
}
if ( F_34 ( & V_16 -> V_40 ) == 0 ) {
F_10 ( L_19
L_20 , V_37 -> V_2 ,
V_38 -> V_2 ) ;
V_36 = V_30 -> F_20 ( V_37 , V_38 ) ;
}
return V_36 ;
}
int F_36 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_14 * V_16 ;
int V_36 = 0 ;
if ( ! V_37 || ! V_38 )
return - V_7 ;
V_16 = F_11 ( V_38 , V_37 -> V_34 ) ;
if ( F_16 ( V_16 ) )
V_36 = F_32 ( V_16 ) ;
if ( ! V_30 || ! V_30 -> F_36 )
V_36 = - V_7 ;
if ( V_36 ) {
F_10 ( L_15
L_16 , V_37 -> V_2 ,
V_38 -> V_2 ) ;
return V_36 ;
}
return V_30 -> F_36 ( V_37 , V_38 ) ;
}
int F_28 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_7 ;
if ( ! V_30 || ! V_30 -> F_28 )
return - V_7 ;
return V_30 -> F_28 ( V_3 ) ;
}
int F_37 ( struct V_1 * V_3 )
{
int V_36 ;
unsigned long V_22 ;
if ( ! V_3 )
return - V_7 ;
if ( ! ( V_3 -> V_22 & V_41 ) ) {
F_10 ( L_21
L_22 , V_3 -> V_2 ) ;
return - V_7 ;
}
if ( ! V_30 || ! V_30 -> F_37 )
return - V_7 ;
F_10 ( L_23 , V_3 -> V_2 ) ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_3 -> V_42 &= ~ V_43 ;
V_36 = V_30 -> F_37 ( V_3 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
return V_36 ;
}
int F_25 ( struct V_1 * V_3 )
{
int V_36 ;
unsigned long V_22 ;
if ( ! V_3 )
return - V_7 ;
if ( ! ( V_3 -> V_22 & V_31 ) ) {
F_10 ( L_21
L_24 , V_3 -> V_2 ) ;
return - V_7 ;
}
if ( ! V_30 || ! V_30 -> F_25 )
return - V_7 ;
F_10 ( L_25 , V_3 -> V_2 ) ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_3 -> V_42 &= ~ V_43 ;
V_36 = V_30 -> F_25 ( V_3 ) ;
V_36 |= F_40 ( V_3 -> V_6 . V_9 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
return V_36 ;
}
void F_41 ( struct V_1 * V_3 )
{
unsigned long V_22 ;
if ( ! V_3 )
return;
if ( ! ( V_3 -> V_22 & V_44 ) ) {
F_10 ( L_26
L_27 , V_3 -> V_2 ) ;
return;
}
if ( ! V_30 || ! V_30 -> F_41 )
return;
F_10 ( L_28 ,
V_3 -> V_2 ) ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_3 -> V_42 |= V_43 ;
V_30 -> F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
}
void F_26 ( struct V_1 * V_3 )
{
unsigned long V_22 ;
if ( ! V_3 )
return;
if ( ! ( V_3 -> V_22 & V_32 ) ) {
F_10 ( L_29
L_30 , V_3 -> V_2 ) ;
return;
}
if ( ! V_30 || ! V_30 -> F_26 )
return;
F_10 ( L_31 ,
V_3 -> V_2 ) ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_3 -> V_42 &= ~ V_43 ;
V_30 -> F_26 ( V_3 ) ;
F_40 ( V_3 -> V_6 . V_9 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
}
bool F_43 ( struct V_1 * V_3 )
{
bool V_36 ;
unsigned long V_22 ;
if ( ! V_3 )
return false ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_36 = ( V_3 -> V_42 & V_43 ) ? true : false ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
return V_36 ;
}
static int F_44 ( struct V_1 * V_3 )
{
unsigned long V_22 ;
if ( ! V_3 || ! V_30 || ! V_30 -> V_45 )
return - V_7 ;
if ( ( F_33 ( & V_3 -> V_46 ) > 1 ) && V_21 )
return 0 ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_30 -> V_45 ( V_3 ) ;
F_45 ( V_3 -> V_6 . V_9 ) ;
F_42 ( V_3 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
F_10 ( L_32 , V_3 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_3 )
{
unsigned long V_22 ;
if ( ! V_3 || ! V_30 || ! V_30 -> V_47 )
return - V_7 ;
if ( F_47 ( & V_3 -> V_46 ) == 0 ) {
F_48 ( 1 ) ;
return - V_48 ;
}
if ( F_34 ( & V_3 -> V_46 ) > 0 )
return 0 ;
F_38 ( & V_3 -> V_13 , V_22 ) ;
V_30 -> V_47 ( V_3 ) ;
F_42 ( V_3 ) ;
F_39 ( & V_3 -> V_13 , V_22 ) ;
F_10 ( L_33 , V_3 -> V_2 ) ;
return 0 ;
}
int V_45 ( struct V_1 * V_3 , struct V_49 * V_49 )
{
if ( ! V_49 )
return - V_7 ;
return F_44 ( V_3 ) ;
}
int V_47 ( struct V_1 * V_3 , struct V_49 * V_49 )
{
if ( ! V_49 )
return - V_7 ;
return F_46 ( V_3 ) ;
}
int F_49 ( struct V_1 * V_3 , struct V_50 * V_51 )
{
if ( F_50 () || F_51 () )
return 0 ;
if ( ! V_51 )
return - V_7 ;
return F_44 ( V_3 ) ;
}
int F_52 ( struct V_1 * V_3 , struct V_50 * V_51 )
{
if ( F_50 () || F_51 () )
return 0 ;
if ( ! V_51 )
return - V_7 ;
return F_46 ( V_3 ) ;
}
