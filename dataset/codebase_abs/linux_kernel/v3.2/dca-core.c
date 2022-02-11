static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
while ( V_6 -> V_7 )
V_6 = V_6 -> V_7 ;
return V_6 ;
}
static struct V_8 * F_3 ( struct V_1 * V_9 )
{
struct V_8 * V_10 ;
V_10 = F_4 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return NULL ;
F_5 ( & V_10 -> V_12 ) ;
V_10 -> V_13 = V_9 ;
return V_10 ;
}
static void F_6 ( struct V_8 * V_10 )
{
F_7 ( & V_10 -> V_14 ) ;
F_8 ( V_10 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return ( ( V_5 -> V_15 == V_16 ) &&
( ( V_5 -> V_2 == V_17 ) ||
( V_5 -> V_2 == V_18 ) ||
( V_5 -> V_2 == V_19 ) ||
( V_5 -> V_2 == V_20 ) ||
( V_5 -> V_2 == V_21 ) ||
( V_5 -> V_2 == V_22 ) ||
( V_5 -> V_2 == V_23 ) ||
( V_5 -> V_2 == V_24 ) ) ) ;
}
static void F_10 ( void )
{
struct V_25 * V_26 , * V_27 ;
struct V_28 V_29 ;
struct V_8 * V_10 ;
unsigned long V_30 ;
F_11 ( & V_31 ,
V_32 , NULL ) ;
F_5 ( & V_29 ) ;
F_12 ( & V_33 , V_30 ) ;
if ( F_13 ( & V_34 ) ) {
F_14 ( & V_33 , V_30 ) ;
return;
}
V_10 = F_15 ( & V_34 , struct V_8 , V_14 ) ;
F_16 (dca, _dca, &domain->dca_providers, node)
F_17 ( & V_26 -> V_14 , & V_29 ) ;
F_6 ( V_10 ) ;
F_14 ( & V_33 , V_30 ) ;
F_16 (dca, _dca, &unregistered_providers, node) {
F_18 ( V_26 ) ;
F_7 ( & V_26 -> V_14 ) ;
}
}
static struct V_8 * F_19 ( struct V_1 * V_9 )
{
struct V_8 * V_10 ;
F_20 (domain, &dca_domains, node)
if ( V_10 -> V_13 == V_9 )
return V_10 ;
return NULL ;
}
static struct V_8 * F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_8 * V_10 ;
V_9 = F_1 ( V_3 ) ;
V_10 = F_19 ( V_9 ) ;
if ( ! V_10 ) {
if ( F_9 ( V_3 ) && ! F_13 ( & V_34 ) )
V_35 = 1 ;
}
return V_10 ;
}
static struct V_25 * F_22 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_1 * V_9 ;
struct V_8 * V_10 ;
if ( V_3 ) {
V_9 = F_1 ( V_3 ) ;
V_10 = F_19 ( V_9 ) ;
if ( ! V_10 )
return NULL ;
} else {
if ( ! F_13 ( & V_34 ) )
V_10 = F_15 ( & V_34 ,
struct V_8 ,
V_14 ) ;
else
return NULL ;
}
F_20 (dca, &domain->dca_providers, node)
if ( ( ! V_3 ) || ( V_26 -> V_36 -> V_37 ( V_26 , V_3 ) ) )
return V_26 ;
return NULL ;
}
int F_23 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
int V_38 , V_39 = - V_40 ;
unsigned long V_30 ;
struct V_1 * V_13 ;
struct V_8 * V_10 ;
if ( ! V_3 )
return - V_41 ;
F_12 ( & V_33 , V_30 ) ;
V_26 = F_22 ( V_3 ) ;
if ( V_26 ) {
F_14 ( & V_33 , V_30 ) ;
return - V_42 ;
}
V_13 = F_1 ( V_3 ) ;
V_10 = F_19 ( V_13 ) ;
if ( ! V_10 ) {
F_14 ( & V_33 , V_30 ) ;
return - V_40 ;
}
F_20 (dca, &domain->dca_providers, node) {
V_39 = V_26 -> V_36 -> V_43 ( V_26 , V_3 ) ;
if ( V_39 >= 0 )
break;
}
F_14 ( & V_33 , V_30 ) ;
if ( V_39 < 0 )
return V_39 ;
V_38 = F_24 ( V_26 , V_3 , V_39 ) ;
if ( V_38 ) {
F_12 ( & V_33 , V_30 ) ;
if ( V_26 == F_22 ( V_3 ) )
V_26 -> V_36 -> V_44 ( V_26 , V_3 ) ;
F_14 ( & V_33 , V_30 ) ;
return V_38 ;
}
return 0 ;
}
int F_25 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
int V_39 ;
unsigned long V_30 ;
if ( ! V_3 )
return - V_41 ;
F_12 ( & V_33 , V_30 ) ;
V_26 = F_22 ( V_3 ) ;
if ( ! V_26 ) {
F_14 ( & V_33 , V_30 ) ;
return - V_40 ;
}
V_39 = V_26 -> V_36 -> V_44 ( V_26 , V_3 ) ;
F_14 ( & V_33 , V_30 ) ;
if ( V_39 < 0 )
return V_39 ;
F_26 ( V_26 , V_39 ) ;
return 0 ;
}
T_1 F_27 ( struct V_2 * V_3 , int V_45 )
{
struct V_25 * V_26 ;
T_1 V_46 ;
unsigned long V_30 ;
F_12 ( & V_33 , V_30 ) ;
V_26 = F_22 ( V_3 ) ;
if ( ! V_26 ) {
F_14 ( & V_33 , V_30 ) ;
return - V_40 ;
}
V_46 = V_26 -> V_36 -> V_47 ( V_26 , V_3 , V_45 ) ;
F_14 ( & V_33 , V_30 ) ;
return V_46 ;
}
T_1 F_28 ( struct V_2 * V_3 , int V_45 )
{
if ( ! V_3 )
return - V_41 ;
return F_27 ( V_3 , V_45 ) ;
}
T_1 F_29 ( int V_45 )
{
struct V_2 * V_3 = NULL ;
return F_27 ( V_3 , V_45 ) ;
}
struct V_25 * F_30 ( struct V_48 * V_36 , int V_49 )
{
struct V_25 * V_26 ;
int V_50 ;
V_50 = ( sizeof( * V_26 ) + V_49 ) ;
V_26 = F_4 ( V_50 , V_51 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_36 = V_36 ;
return V_26 ;
}
void F_31 ( struct V_25 * V_26 )
{
F_8 ( V_26 ) ;
}
int F_32 ( struct V_25 * V_26 , struct V_2 * V_3 )
{
int V_38 ;
unsigned long V_30 ;
struct V_8 * V_10 , * V_52 = NULL ;
F_12 ( & V_33 , V_30 ) ;
if ( V_35 ) {
F_14 ( & V_33 , V_30 ) ;
return - V_40 ;
}
F_14 ( & V_33 , V_30 ) ;
V_38 = F_33 ( V_26 , V_3 ) ;
if ( V_38 )
return V_38 ;
F_12 ( & V_33 , V_30 ) ;
V_10 = F_21 ( V_3 ) ;
if ( ! V_10 ) {
struct V_1 * V_9 ;
if ( V_35 ) {
F_14 ( & V_33 , V_30 ) ;
F_18 ( V_26 ) ;
F_10 () ;
return - V_40 ;
}
F_14 ( & V_33 , V_30 ) ;
V_9 = F_1 ( V_3 ) ;
V_52 = F_3 ( V_9 ) ;
if ( ! V_52 )
return - V_40 ;
F_12 ( & V_33 , V_30 ) ;
V_10 = F_21 ( V_3 ) ;
if ( ! V_10 ) {
V_10 = V_52 ;
V_52 = NULL ;
F_34 ( & V_10 -> V_14 , & V_34 ) ;
}
}
F_34 ( & V_26 -> V_14 , & V_10 -> V_12 ) ;
F_14 ( & V_33 , V_30 ) ;
F_11 ( & V_31 ,
V_53 , NULL ) ;
F_8 ( V_52 ) ;
return 0 ;
}
void F_35 ( struct V_25 * V_26 , struct V_2 * V_3 )
{
unsigned long V_30 ;
struct V_1 * V_13 ;
struct V_8 * V_10 ;
F_11 ( & V_31 ,
V_32 , NULL ) ;
F_12 ( & V_33 , V_30 ) ;
F_7 ( & V_26 -> V_14 ) ;
V_13 = F_1 ( V_3 ) ;
V_10 = F_19 ( V_13 ) ;
if ( F_13 ( & V_10 -> V_12 ) )
F_6 ( V_10 ) ;
F_14 ( & V_33 , V_30 ) ;
F_18 ( V_26 ) ;
}
void F_36 ( struct V_54 * V_55 )
{
F_37 ( & V_31 , V_55 ) ;
}
void F_38 ( struct V_54 * V_55 )
{
F_39 ( & V_31 , V_55 ) ;
}
static int T_2 F_40 ( void )
{
F_41 ( L_1 , V_56 ) ;
return F_42 () ;
}
static void T_3 F_43 ( void )
{
F_44 () ;
}
