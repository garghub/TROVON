static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( ( ( V_2 -> V_5 & V_6 ) || V_4 -> V_7 != V_2 -> V_7 ) &&
V_2 -> V_8 == V_9 ) ;
}
static inline unsigned int F_2 ( const struct V_3 * V_4 )
{
return V_4 -> V_10 - ( V_4 -> V_11 == F_3 ( V_12 ) ? V_13 : 0 ) ;
}
int F_4 ( struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) ||
( F_2 ( V_4 ) > V_4 -> V_7 -> V_14 && ! F_6 ( V_4 ) ) ) {
F_7 ( V_4 ) ;
} else {
F_8 ( V_4 , V_15 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
return 0 ;
}
int F_11 ( struct V_3 * V_4 )
{
return F_12 ( V_16 , V_17 , V_4 , NULL , V_4 -> V_7 ,
F_4 ) ;
}
static void F_13 ( const struct V_1 * V_18 , struct V_3 * V_4 )
{
V_4 -> V_7 = V_18 -> V_7 ;
if ( F_14 ( F_15 ( V_18 -> V_7 ) ) ) {
if ( F_2 ( V_4 ) > V_4 -> V_7 -> V_14 && ! F_6 ( V_4 ) )
F_7 ( V_4 ) ;
else {
F_8 ( V_4 , V_15 ) ;
F_16 ( V_18 , V_4 ) ;
}
return;
}
F_12 ( V_16 , V_19 , V_4 , NULL , V_4 -> V_7 ,
F_11 ) ;
}
static void F_17 ( const struct V_1 * V_18 , struct V_3 * V_4 )
{
struct V_20 * V_21 ;
if ( F_18 ( V_4 ) ) {
F_7 ( V_4 ) ;
return;
}
V_21 = V_4 -> V_7 ;
V_4 -> V_7 = V_18 -> V_7 ;
F_19 ( V_4 ) ;
F_12 ( V_16 , V_22 , V_4 , V_21 , V_4 -> V_7 ,
F_11 ) ;
}
void F_20 ( const struct V_1 * V_18 , struct V_3 * V_4 )
{
if ( V_18 && F_1 ( V_18 , V_4 ) ) {
F_13 ( V_18 , V_4 ) ;
return;
}
F_7 ( V_4 ) ;
}
void F_21 ( const struct V_1 * V_18 , struct V_3 * V_4 , struct V_3 * V_23 )
{
if ( F_1 ( V_18 , V_4 ) ) {
if ( V_23 )
F_22 ( V_18 , V_4 , F_17 ) ;
else
F_17 ( V_18 , V_4 ) ;
return;
}
if ( ! V_23 )
F_7 ( V_4 ) ;
}
static int F_22 ( const struct V_1 * V_24 ,
struct V_3 * V_4 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_20 * V_7 = F_24 ( V_4 ) -> V_25 ;
V_4 = F_25 ( V_4 , V_26 ) ;
if ( ! V_4 ) {
V_7 -> V_27 . V_28 ++ ;
return - V_29 ;
}
F_23 ( V_24 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_26 (
struct V_1 * V_24 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_30 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_24 ;
if ( ! V_24 )
goto V_31;
V_30 = F_22 ( V_24 , V_4 , F_23 ) ;
if ( V_30 )
return F_27 ( V_30 ) ;
V_31:
return V_2 ;
}
static void F_28 ( struct V_32 * V_33 , struct V_3 * V_4 ,
struct V_3 * V_23 ,
void (* F_23)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_1 * V_2 ;
struct V_1 * V_24 ;
V_24 = NULL ;
F_29 (p, &br->port_list, list) {
V_24 = F_26 ( V_24 , V_2 , V_4 , F_23 ) ;
if ( F_30 ( V_24 ) )
goto V_31;
}
if ( ! V_24 )
goto V_31;
if ( V_23 )
F_22 ( V_24 , V_4 , F_23 ) ;
else
F_23 ( V_24 , V_4 ) ;
return;
V_31:
if ( ! V_23 )
F_7 ( V_4 ) ;
}
void F_31 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
F_28 ( V_33 , V_4 , NULL , F_13 ) ;
}
void F_32 ( struct V_32 * V_33 , struct V_3 * V_4 ,
struct V_3 * V_34 )
{
F_28 ( V_33 , V_4 , V_34 , F_17 ) ;
}
static void F_33 ( struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_3 * V_23 ,
void (* F_23)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_20 * V_7 = F_24 ( V_4 ) -> V_25 ;
struct V_32 * V_33 = F_34 ( V_7 ) ;
struct V_1 * V_24 = NULL ;
struct V_37 * V_2 ;
struct V_38 * V_39 ;
V_39 = F_35 ( F_36 ( & V_33 -> V_40 ) ) ;
V_2 = V_36 ? F_35 ( V_36 -> V_41 ) : NULL ;
while ( V_2 || V_39 ) {
struct V_1 * V_42 , * V_43 , * V_44 ;
V_43 = V_2 ? V_2 -> V_42 : NULL ;
V_44 = V_39 ? F_37 ( V_39 , struct V_1 , V_45 ) :
NULL ;
V_42 = ( unsigned long ) V_43 > ( unsigned long ) V_44 ?
V_43 : V_44 ;
V_24 = F_26 ( V_24 , V_42 , V_4 , F_23 ) ;
if ( F_30 ( V_24 ) )
goto V_31;
if ( ( unsigned long ) V_43 >= ( unsigned long ) V_42 )
V_2 = F_35 ( V_2 -> V_46 ) ;
if ( ( unsigned long ) V_44 >= ( unsigned long ) V_42 )
V_39 = F_35 ( F_38 ( V_39 ) ) ;
}
if ( ! V_24 )
goto V_31;
if ( V_23 )
F_22 ( V_24 , V_4 , F_23 ) ;
else
F_23 ( V_24 , V_4 ) ;
return;
V_31:
if ( ! V_23 )
F_7 ( V_4 ) ;
}
void F_39 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
F_33 ( V_36 , V_4 , NULL , F_13 ) ;
}
void F_40 ( struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_3 * V_34 )
{
F_33 ( V_36 , V_4 , V_34 , F_17 ) ;
}
