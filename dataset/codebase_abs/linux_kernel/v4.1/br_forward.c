static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( ( V_2 -> V_5 & V_6 ) || V_4 -> V_7 != V_2 -> V_7 ) &&
F_2 ( V_2 -> V_8 , F_3 ( V_2 ) , V_4 ) &&
V_2 -> V_9 == V_10 ;
}
int F_4 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
if ( ! F_5 ( V_4 -> V_7 , V_4 ) ) {
F_6 ( V_4 ) ;
} else {
F_7 ( V_4 , V_13 ) ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
}
return 0 ;
}
int F_10 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
return F_11 ( V_14 , V_15 , V_12 , V_4 ,
NULL , V_4 -> V_7 ,
F_4 ) ;
}
static void F_12 ( const struct V_1 * V_16 , struct V_3 * V_4 )
{
V_4 = F_13 ( V_16 -> V_8 , F_3 ( V_16 ) , V_4 ) ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_16 -> V_7 ;
if ( F_14 ( F_15 ( V_16 -> V_8 -> V_7 ) ) ) {
if ( ! F_5 ( V_4 -> V_7 , V_4 ) )
F_6 ( V_4 ) ;
else {
F_7 ( V_4 , V_13 ) ;
F_16 ( V_16 , V_4 ) ;
}
return;
}
F_11 ( V_14 , V_17 , NULL , V_4 ,
NULL , V_4 -> V_7 ,
F_10 ) ;
}
static void F_17 ( const struct V_1 * V_16 , struct V_3 * V_4 )
{
struct V_18 * V_19 ;
if ( F_18 ( V_4 ) ) {
F_6 ( V_4 ) ;
return;
}
V_4 = F_13 ( V_16 -> V_8 , F_3 ( V_16 ) , V_4 ) ;
if ( ! V_4 )
return;
V_19 = V_4 -> V_7 ;
V_4 -> V_7 = V_16 -> V_7 ;
F_19 ( V_4 ) ;
F_11 ( V_14 , V_20 , NULL , V_4 ,
V_19 , V_4 -> V_7 ,
F_10 ) ;
}
void F_20 ( const struct V_1 * V_16 , struct V_3 * V_4 )
{
if ( V_16 && F_1 ( V_16 , V_4 ) ) {
F_12 ( V_16 , V_4 ) ;
return;
}
F_6 ( V_4 ) ;
}
void F_21 ( const struct V_1 * V_16 , struct V_3 * V_4 , struct V_3 * V_21 )
{
if ( F_1 ( V_16 , V_4 ) ) {
if ( V_21 )
F_22 ( V_16 , V_4 , F_17 ) ;
else
F_17 ( V_16 , V_4 ) ;
return;
}
if ( ! V_21 )
F_6 ( V_4 ) ;
}
static int F_22 ( const struct V_1 * V_22 ,
struct V_3 * V_4 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_18 * V_7 = F_24 ( V_4 ) -> V_23 ;
V_4 = F_25 ( V_4 , V_24 ) ;
if ( ! V_4 ) {
V_7 -> V_25 . V_26 ++ ;
return - V_27 ;
}
F_23 ( V_22 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_26 (
struct V_1 * V_22 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_28 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_22 ;
if ( ! V_22 )
goto V_29;
V_28 = F_22 ( V_22 , V_4 , F_23 ) ;
if ( V_28 )
return F_27 ( V_28 ) ;
V_29:
return V_2 ;
}
static void F_28 ( struct V_30 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_21 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) ,
bool V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_22 ;
V_22 = NULL ;
F_29 (p, &br->port_list, list) {
if ( V_31 && ! ( V_2 -> V_5 & V_32 ) )
continue;
if ( V_2 -> V_5 & V_33 )
continue;
if ( ( V_2 -> V_5 & V_34 ) &&
F_24 ( V_4 ) -> V_35 )
continue;
V_22 = F_26 ( V_22 , V_2 , V_4 , F_23 ) ;
if ( F_30 ( V_22 ) )
goto V_29;
}
if ( ! V_22 )
goto V_29;
if ( V_21 )
F_22 ( V_22 , V_4 , F_23 ) ;
else
F_23 ( V_22 , V_4 ) ;
return;
V_29:
if ( ! V_21 )
F_6 ( V_4 ) ;
}
void F_31 ( struct V_30 * V_8 , struct V_3 * V_4 , bool V_31 )
{
F_28 ( V_8 , V_4 , NULL , F_12 , V_31 ) ;
}
void F_32 ( struct V_30 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_36 , bool V_31 )
{
F_28 ( V_8 , V_4 , V_36 , F_17 , V_31 ) ;
}
static void F_33 ( struct V_37 * V_38 ,
struct V_3 * V_4 , struct V_3 * V_21 ,
void (* F_23)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_18 * V_7 = F_24 ( V_4 ) -> V_23 ;
struct V_30 * V_8 = F_34 ( V_7 ) ;
struct V_1 * V_22 = NULL ;
struct V_39 * V_2 ;
struct V_40 * V_41 ;
V_41 = F_35 ( F_36 ( & V_8 -> V_42 ) ) ;
V_2 = V_38 ? F_35 ( V_38 -> V_43 ) : NULL ;
while ( V_2 || V_41 ) {
struct V_1 * V_44 , * V_45 , * V_46 ;
V_45 = V_2 ? V_2 -> V_44 : NULL ;
V_46 = V_41 ? F_37 ( V_41 , struct V_1 , V_47 ) :
NULL ;
V_44 = ( unsigned long ) V_45 > ( unsigned long ) V_46 ?
V_45 : V_46 ;
V_22 = F_26 ( V_22 , V_44 , V_4 , F_23 ) ;
if ( F_30 ( V_22 ) )
goto V_29;
if ( ( unsigned long ) V_45 >= ( unsigned long ) V_44 )
V_2 = F_35 ( V_2 -> V_48 ) ;
if ( ( unsigned long ) V_46 >= ( unsigned long ) V_44 )
V_41 = F_35 ( F_38 ( V_41 ) ) ;
}
if ( ! V_22 )
goto V_29;
if ( V_21 )
F_22 ( V_22 , V_4 , F_23 ) ;
else
F_23 ( V_22 , V_4 ) ;
return;
V_29:
if ( ! V_21 )
F_6 ( V_4 ) ;
}
void F_39 ( struct V_37 * V_38 ,
struct V_3 * V_4 )
{
F_33 ( V_38 , V_4 , NULL , F_12 ) ;
}
void F_40 ( struct V_37 * V_38 ,
struct V_3 * V_4 , struct V_3 * V_36 )
{
F_33 ( V_38 , V_4 , V_36 , F_17 ) ;
}
