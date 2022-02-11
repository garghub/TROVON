static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( ( V_2 -> V_5 & V_6 ) || V_4 -> V_7 != V_2 -> V_7 ) &&
F_2 ( V_2 -> V_8 , F_3 ( V_2 ) , V_4 ) &&
V_2 -> V_9 == V_10 ;
}
static inline unsigned int F_4 ( const struct V_3 * V_4 )
{
return V_4 -> V_11 - ( V_4 -> V_12 == F_5 ( V_13 ) ? V_14 : 0 ) ;
}
int F_6 ( struct V_3 * V_4 )
{
if ( F_7 ( V_4 ) ||
( F_4 ( V_4 ) > V_4 -> V_7 -> V_15 && ! F_8 ( V_4 ) ) ) {
F_9 ( V_4 ) ;
} else {
F_10 ( V_4 , V_16 ) ;
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
}
return 0 ;
}
int F_13 ( struct V_3 * V_4 )
{
return F_14 ( V_17 , V_18 , V_4 , NULL , V_4 -> V_7 ,
F_6 ) ;
}
static void F_15 ( const struct V_1 * V_19 , struct V_3 * V_4 )
{
V_4 = F_16 ( V_19 -> V_8 , F_3 ( V_19 ) , V_4 ) ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_19 -> V_7 ;
if ( F_17 ( F_18 ( V_19 -> V_8 -> V_7 ) ) ) {
if ( F_4 ( V_4 ) > V_4 -> V_7 -> V_15 && ! F_8 ( V_4 ) )
F_9 ( V_4 ) ;
else {
F_10 ( V_4 , V_16 ) ;
F_19 ( V_19 , V_4 ) ;
}
return;
}
F_14 ( V_17 , V_20 , V_4 , NULL , V_4 -> V_7 ,
F_13 ) ;
}
static void F_20 ( const struct V_1 * V_19 , struct V_3 * V_4 )
{
struct V_21 * V_22 ;
if ( F_21 ( V_4 ) ) {
F_9 ( V_4 ) ;
return;
}
V_4 = F_16 ( V_19 -> V_8 , F_3 ( V_19 ) , V_4 ) ;
if ( ! V_4 )
return;
V_22 = V_4 -> V_7 ;
V_4 -> V_7 = V_19 -> V_7 ;
F_22 ( V_4 ) ;
F_14 ( V_17 , V_23 , V_4 , V_22 , V_4 -> V_7 ,
F_13 ) ;
}
void F_23 ( const struct V_1 * V_19 , struct V_3 * V_4 )
{
if ( V_19 && F_1 ( V_19 , V_4 ) ) {
F_15 ( V_19 , V_4 ) ;
return;
}
F_9 ( V_4 ) ;
}
void F_24 ( const struct V_1 * V_19 , struct V_3 * V_4 , struct V_3 * V_24 )
{
if ( F_1 ( V_19 , V_4 ) ) {
if ( V_24 )
F_25 ( V_19 , V_4 , F_20 ) ;
else
F_20 ( V_19 , V_4 ) ;
return;
}
if ( ! V_24 )
F_9 ( V_4 ) ;
}
static int F_25 ( const struct V_1 * V_25 ,
struct V_3 * V_4 ,
void (* F_26)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_21 * V_7 = F_27 ( V_4 ) -> V_26 ;
V_4 = F_28 ( V_4 , V_27 ) ;
if ( ! V_4 ) {
V_7 -> V_28 . V_29 ++ ;
return - V_30 ;
}
F_26 ( V_25 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_29 (
struct V_1 * V_25 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_26)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_31 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_25 ;
if ( ! V_25 )
goto V_32;
V_31 = F_25 ( V_25 , V_4 , F_26 ) ;
if ( V_31 )
return F_30 ( V_31 ) ;
V_32:
return V_2 ;
}
static void F_31 ( struct V_33 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_24 ,
void (* F_26)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) ,
bool V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_25 ;
V_25 = NULL ;
F_32 (p, &br->port_list, list) {
if ( V_34 && ! ( V_2 -> V_5 & V_35 ) )
continue;
V_25 = F_29 ( V_25 , V_2 , V_4 , F_26 ) ;
if ( F_33 ( V_25 ) )
goto V_32;
}
if ( ! V_25 )
goto V_32;
if ( V_24 )
F_25 ( V_25 , V_4 , F_26 ) ;
else
F_26 ( V_25 , V_4 ) ;
return;
V_32:
if ( ! V_24 )
F_9 ( V_4 ) ;
}
void F_34 ( struct V_33 * V_8 , struct V_3 * V_4 , bool V_34 )
{
F_31 ( V_8 , V_4 , NULL , F_15 , V_34 ) ;
}
void F_35 ( struct V_33 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_36 , bool V_34 )
{
F_31 ( V_8 , V_4 , V_36 , F_20 , V_34 ) ;
}
static void F_36 ( struct V_37 * V_38 ,
struct V_3 * V_4 , struct V_3 * V_24 ,
void (* F_26)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_21 * V_7 = F_27 ( V_4 ) -> V_26 ;
struct V_33 * V_8 = F_37 ( V_7 ) ;
struct V_1 * V_25 = NULL ;
struct V_39 * V_2 ;
struct V_40 * V_41 ;
V_41 = F_38 ( F_39 ( & V_8 -> V_42 ) ) ;
V_2 = V_38 ? F_38 ( V_38 -> V_43 ) : NULL ;
while ( V_2 || V_41 ) {
struct V_1 * V_44 , * V_45 , * V_46 ;
V_45 = V_2 ? V_2 -> V_44 : NULL ;
V_46 = V_41 ? F_40 ( V_41 , struct V_1 , V_47 ) :
NULL ;
V_44 = ( unsigned long ) V_45 > ( unsigned long ) V_46 ?
V_45 : V_46 ;
V_25 = F_29 ( V_25 , V_44 , V_4 , F_26 ) ;
if ( F_33 ( V_25 ) )
goto V_32;
if ( ( unsigned long ) V_45 >= ( unsigned long ) V_44 )
V_2 = F_38 ( V_2 -> V_48 ) ;
if ( ( unsigned long ) V_46 >= ( unsigned long ) V_44 )
V_41 = F_38 ( F_41 ( V_41 ) ) ;
}
if ( ! V_25 )
goto V_32;
if ( V_24 )
F_25 ( V_25 , V_4 , F_26 ) ;
else
F_26 ( V_25 , V_4 ) ;
return;
V_32:
if ( ! V_24 )
F_9 ( V_4 ) ;
}
void F_42 ( struct V_37 * V_38 ,
struct V_3 * V_4 )
{
F_36 ( V_38 , V_4 , NULL , F_15 ) ;
}
void F_43 ( struct V_37 * V_38 ,
struct V_3 * V_4 , struct V_3 * V_36 )
{
F_36 ( V_38 , V_4 , V_36 , F_20 ) ;
}
