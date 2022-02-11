static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( ( V_2 -> V_5 & V_6 ) || V_4 -> V_7 != V_2 -> V_7 ) &&
F_2 ( V_2 -> V_8 , F_3 ( V_2 ) , V_4 ) &&
V_2 -> V_9 == V_10 ;
}
int F_4 ( struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) ||
! F_6 ( V_4 -> V_7 , V_4 ) ) {
F_7 ( V_4 ) ;
} else {
F_8 ( V_4 , V_11 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
return 0 ;
}
int F_11 ( struct V_3 * V_4 )
{
return F_12 ( V_12 , V_13 , V_4 , NULL , V_4 -> V_7 ,
F_4 ) ;
}
static void F_13 ( const struct V_1 * V_14 , struct V_3 * V_4 )
{
V_4 = F_14 ( V_14 -> V_8 , F_3 ( V_14 ) , V_4 ) ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_14 -> V_7 ;
if ( F_15 ( F_16 ( V_14 -> V_8 -> V_7 ) ) ) {
if ( ! F_6 ( V_4 -> V_7 , V_4 ) )
F_7 ( V_4 ) ;
else {
F_8 ( V_4 , V_11 ) ;
F_17 ( V_14 , V_4 ) ;
}
return;
}
F_12 ( V_12 , V_15 , V_4 , NULL , V_4 -> V_7 ,
F_11 ) ;
}
static void F_18 ( const struct V_1 * V_14 , struct V_3 * V_4 )
{
struct V_16 * V_17 ;
if ( F_19 ( V_4 ) ) {
F_7 ( V_4 ) ;
return;
}
V_4 = F_14 ( V_14 -> V_8 , F_3 ( V_14 ) , V_4 ) ;
if ( ! V_4 )
return;
V_17 = V_4 -> V_7 ;
V_4 -> V_7 = V_14 -> V_7 ;
F_20 ( V_4 ) ;
F_12 ( V_12 , V_18 , V_4 , V_17 , V_4 -> V_7 ,
F_11 ) ;
}
void F_21 ( const struct V_1 * V_14 , struct V_3 * V_4 )
{
if ( V_14 && F_1 ( V_14 , V_4 ) ) {
F_13 ( V_14 , V_4 ) ;
return;
}
F_7 ( V_4 ) ;
}
void F_22 ( const struct V_1 * V_14 , struct V_3 * V_4 , struct V_3 * V_19 )
{
if ( F_1 ( V_14 , V_4 ) ) {
if ( V_19 )
F_23 ( V_14 , V_4 , F_18 ) ;
else
F_18 ( V_14 , V_4 ) ;
return;
}
if ( ! V_19 )
F_7 ( V_4 ) ;
}
static int F_23 ( const struct V_1 * V_20 ,
struct V_3 * V_4 ,
void (* F_24)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_16 * V_7 = F_25 ( V_4 ) -> V_21 ;
V_4 = F_26 ( V_4 , V_22 ) ;
if ( ! V_4 ) {
V_7 -> V_23 . V_24 ++ ;
return - V_25 ;
}
F_24 ( V_20 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_27 (
struct V_1 * V_20 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_24)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_26 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_20 ;
if ( ! V_20 )
goto V_27;
V_26 = F_23 ( V_20 , V_4 , F_24 ) ;
if ( V_26 )
return F_28 ( V_26 ) ;
V_27:
return V_2 ;
}
static void F_29 ( struct V_28 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_19 ,
void (* F_24)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) ,
bool V_29 )
{
struct V_1 * V_2 ;
struct V_1 * V_20 ;
V_20 = NULL ;
F_30 (p, &br->port_list, list) {
if ( V_29 && ! ( V_2 -> V_5 & V_30 ) )
continue;
if ( V_2 -> V_5 & V_31 )
continue;
V_20 = F_27 ( V_20 , V_2 , V_4 , F_24 ) ;
if ( F_31 ( V_20 ) )
goto V_27;
}
if ( ! V_20 )
goto V_27;
if ( V_19 )
F_23 ( V_20 , V_4 , F_24 ) ;
else
F_24 ( V_20 , V_4 ) ;
return;
V_27:
if ( ! V_19 )
F_7 ( V_4 ) ;
}
void F_32 ( struct V_28 * V_8 , struct V_3 * V_4 , bool V_29 )
{
F_29 ( V_8 , V_4 , NULL , F_13 , V_29 ) ;
}
void F_33 ( struct V_28 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_32 , bool V_29 )
{
F_29 ( V_8 , V_4 , V_32 , F_18 , V_29 ) ;
}
static void F_34 ( struct V_33 * V_34 ,
struct V_3 * V_4 , struct V_3 * V_19 ,
void (* F_24)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_16 * V_7 = F_25 ( V_4 ) -> V_21 ;
struct V_28 * V_8 = F_35 ( V_7 ) ;
struct V_1 * V_20 = NULL ;
struct V_35 * V_2 ;
struct V_36 * V_37 ;
V_37 = F_36 ( F_37 ( & V_8 -> V_38 ) ) ;
V_2 = V_34 ? F_36 ( V_34 -> V_39 ) : NULL ;
while ( V_2 || V_37 ) {
struct V_1 * V_40 , * V_41 , * V_42 ;
V_41 = V_2 ? V_2 -> V_40 : NULL ;
V_42 = V_37 ? F_38 ( V_37 , struct V_1 , V_43 ) :
NULL ;
V_40 = ( unsigned long ) V_41 > ( unsigned long ) V_42 ?
V_41 : V_42 ;
V_20 = F_27 ( V_20 , V_40 , V_4 , F_24 ) ;
if ( F_31 ( V_20 ) )
goto V_27;
if ( ( unsigned long ) V_41 >= ( unsigned long ) V_40 )
V_2 = F_36 ( V_2 -> V_44 ) ;
if ( ( unsigned long ) V_42 >= ( unsigned long ) V_40 )
V_37 = F_36 ( F_39 ( V_37 ) ) ;
}
if ( ! V_20 )
goto V_27;
if ( V_19 )
F_23 ( V_20 , V_4 , F_24 ) ;
else
F_24 ( V_20 , V_4 ) ;
return;
V_27:
if ( ! V_19 )
F_7 ( V_4 ) ;
}
void F_40 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
F_34 ( V_34 , V_4 , NULL , F_13 ) ;
}
void F_41 ( struct V_33 * V_34 ,
struct V_3 * V_4 , struct V_3 * V_32 )
{
F_34 ( V_34 , V_4 , V_32 , F_18 ) ;
}
