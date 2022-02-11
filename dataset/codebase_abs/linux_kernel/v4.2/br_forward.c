static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return ( ( V_2 -> V_5 & V_6 ) || V_4 -> V_7 != V_2 -> V_7 ) &&
F_2 ( V_2 -> V_8 , F_3 ( V_2 ) , V_4 ) &&
V_2 -> V_9 == V_10 ;
}
int F_4 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
if ( ! F_5 ( V_4 -> V_7 , V_4 ) )
goto V_13;
F_6 ( V_4 , V_14 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
if ( V_4 -> V_15 == V_16 &&
( V_4 -> V_17 == F_9 ( V_18 ) ||
V_4 -> V_17 == F_9 ( V_19 ) ) ) {
int V_20 ;
if ( ! F_10 ( V_4 , V_4 -> V_17 , & V_20 ) )
goto V_13;
F_11 ( V_4 , V_20 ) ;
}
F_12 ( V_4 ) ;
return 0 ;
V_13:
F_13 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
return F_15 ( V_21 , V_22 , V_12 , V_4 ,
NULL , V_4 -> V_7 ,
F_4 ) ;
}
static void F_16 ( const struct V_1 * V_23 , struct V_3 * V_4 )
{
V_4 = F_17 ( V_23 -> V_8 , F_3 ( V_23 ) , V_4 ) ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_23 -> V_7 ;
if ( F_18 ( F_19 ( V_23 -> V_8 -> V_7 ) ) ) {
if ( ! F_5 ( V_4 -> V_7 , V_4 ) )
F_13 ( V_4 ) ;
else {
F_6 ( V_4 , V_14 ) ;
F_20 ( V_23 , V_4 ) ;
}
return;
}
F_15 ( V_21 , V_24 , NULL , V_4 ,
NULL , V_4 -> V_7 ,
F_14 ) ;
}
static void F_21 ( const struct V_1 * V_23 , struct V_3 * V_4 )
{
struct V_25 * V_26 ;
if ( F_22 ( V_4 ) ) {
F_13 ( V_4 ) ;
return;
}
V_4 = F_17 ( V_23 -> V_8 , F_3 ( V_23 ) , V_4 ) ;
if ( ! V_4 )
return;
V_26 = V_4 -> V_7 ;
V_4 -> V_7 = V_23 -> V_7 ;
F_23 ( V_4 ) ;
F_15 ( V_21 , V_27 , NULL , V_4 ,
V_26 , V_4 -> V_7 ,
F_14 ) ;
}
void F_24 ( const struct V_1 * V_23 , struct V_3 * V_4 )
{
if ( V_23 && F_1 ( V_23 , V_4 ) ) {
F_16 ( V_23 , V_4 ) ;
return;
}
F_13 ( V_4 ) ;
}
void F_25 ( const struct V_1 * V_23 , struct V_3 * V_4 , struct V_3 * V_28 )
{
if ( F_1 ( V_23 , V_4 ) ) {
if ( V_28 )
F_26 ( V_23 , V_4 , F_21 ) ;
else
F_21 ( V_23 , V_4 ) ;
return;
}
if ( ! V_28 )
F_13 ( V_4 ) ;
}
static int F_26 ( const struct V_1 * V_29 ,
struct V_3 * V_4 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_25 * V_7 = F_28 ( V_4 ) -> V_30 ;
V_4 = F_29 ( V_4 , V_31 ) ;
if ( ! V_4 ) {
V_7 -> V_32 . V_33 ++ ;
return - V_34 ;
}
F_27 ( V_29 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_30 (
struct V_1 * V_29 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_35 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_29 ;
if ( ! V_29 )
goto V_36;
V_35 = F_26 ( V_29 , V_4 , F_27 ) ;
if ( V_35 )
return F_31 ( V_35 ) ;
V_36:
return V_2 ;
}
static void F_32 ( struct V_37 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_28 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) ,
bool V_38 )
{
struct V_1 * V_2 ;
struct V_1 * V_29 ;
V_29 = NULL ;
F_33 (p, &br->port_list, list) {
if ( V_38 && ! ( V_2 -> V_5 & V_39 ) )
continue;
if ( V_2 -> V_5 & V_40 )
continue;
if ( ( V_2 -> V_5 & V_41 ) &&
F_28 ( V_4 ) -> V_42 )
continue;
V_29 = F_30 ( V_29 , V_2 , V_4 , F_27 ) ;
if ( F_34 ( V_29 ) )
goto V_36;
}
if ( ! V_29 )
goto V_36;
if ( V_28 )
F_26 ( V_29 , V_4 , F_27 ) ;
else
F_27 ( V_29 , V_4 ) ;
return;
V_36:
if ( ! V_28 )
F_13 ( V_4 ) ;
}
void F_35 ( struct V_37 * V_8 , struct V_3 * V_4 , bool V_38 )
{
F_32 ( V_8 , V_4 , NULL , F_16 , V_38 ) ;
}
void F_36 ( struct V_37 * V_8 , struct V_3 * V_4 ,
struct V_3 * V_43 , bool V_38 )
{
F_32 ( V_8 , V_4 , V_43 , F_21 , V_38 ) ;
}
static void F_37 ( struct V_44 * V_45 ,
struct V_3 * V_4 , struct V_3 * V_28 ,
void (* F_27)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_25 * V_7 = F_28 ( V_4 ) -> V_30 ;
struct V_37 * V_8 = F_38 ( V_7 ) ;
struct V_1 * V_29 = NULL ;
struct V_46 * V_2 ;
struct V_47 * V_48 ;
V_48 = F_39 ( F_40 ( & V_8 -> V_49 ) ) ;
V_2 = V_45 ? F_39 ( V_45 -> V_50 ) : NULL ;
while ( V_2 || V_48 ) {
struct V_1 * V_51 , * V_52 , * V_53 ;
V_52 = V_2 ? V_2 -> V_51 : NULL ;
V_53 = V_48 ? F_41 ( V_48 , struct V_1 , V_54 ) :
NULL ;
V_51 = ( unsigned long ) V_52 > ( unsigned long ) V_53 ?
V_52 : V_53 ;
V_29 = F_30 ( V_29 , V_51 , V_4 , F_27 ) ;
if ( F_34 ( V_29 ) )
goto V_36;
if ( ( unsigned long ) V_52 >= ( unsigned long ) V_51 )
V_2 = F_39 ( V_2 -> V_55 ) ;
if ( ( unsigned long ) V_53 >= ( unsigned long ) V_51 )
V_48 = F_39 ( F_42 ( V_48 ) ) ;
}
if ( ! V_29 )
goto V_36;
if ( V_28 )
F_26 ( V_29 , V_4 , F_27 ) ;
else
F_27 ( V_29 , V_4 ) ;
return;
V_36:
if ( ! V_28 )
F_13 ( V_4 ) ;
}
void F_43 ( struct V_44 * V_45 ,
struct V_3 * V_4 )
{
F_37 ( V_45 , V_4 , NULL , F_16 ) ;
}
void F_44 ( struct V_44 * V_45 ,
struct V_3 * V_4 , struct V_3 * V_43 )
{
F_37 ( V_45 , V_4 , V_43 , F_21 ) ;
}
