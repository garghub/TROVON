static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
return ( ( V_2 -> V_7 & V_8 ) || V_4 -> V_9 != V_2 -> V_9 ) &&
F_3 ( V_6 , V_4 ) && V_2 -> V_10 == V_11 ;
}
int F_4 ( struct V_12 * V_12 , struct V_13 * V_14 , struct V_3 * V_4 )
{
if ( ! F_5 ( V_4 -> V_9 , V_4 ) )
goto V_15;
F_6 ( V_4 , V_16 ) ;
F_7 ( V_4 ) ;
if ( V_4 -> V_17 == V_18 &&
( V_4 -> V_19 == F_8 ( V_20 ) ||
V_4 -> V_19 == F_8 ( V_21 ) ) ) {
int V_22 ;
if ( ! F_9 ( V_4 , V_4 -> V_19 , & V_22 ) )
goto V_15;
F_10 ( V_4 , V_22 ) ;
}
F_11 ( V_4 ) ;
return 0 ;
V_15:
F_12 ( V_4 ) ;
return 0 ;
}
int F_13 ( struct V_12 * V_12 , struct V_13 * V_14 , struct V_3 * V_4 )
{
return F_14 ( V_23 , V_24 ,
V_12 , V_14 , V_4 , NULL , V_4 -> V_9 ,
F_4 ) ;
}
static void F_15 ( const struct V_1 * V_25 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_25 ) ;
V_4 = F_16 ( V_25 -> V_26 , V_6 , V_4 ) ;
if ( ! V_4 )
return;
V_4 -> V_9 = V_25 -> V_9 ;
if ( F_17 ( F_18 ( V_25 -> V_26 -> V_9 ) ) ) {
if ( ! F_5 ( V_4 -> V_9 , V_4 ) )
F_12 ( V_4 ) ;
else {
F_6 ( V_4 , V_16 ) ;
F_19 ( V_25 , V_4 ) ;
}
return;
}
F_14 ( V_23 , V_27 ,
F_20 ( V_4 -> V_9 ) , NULL , V_4 , NULL , V_4 -> V_9 ,
F_13 ) ;
}
static void F_21 ( const struct V_1 * V_25 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_28 * V_29 ;
if ( F_22 ( V_4 ) ) {
F_12 ( V_4 ) ;
return;
}
V_6 = F_2 ( V_25 ) ;
V_4 = F_16 ( V_25 -> V_26 , V_6 , V_4 ) ;
if ( ! V_4 )
return;
V_29 = V_4 -> V_9 ;
V_4 -> V_9 = V_25 -> V_9 ;
F_23 ( V_4 ) ;
F_14 ( V_23 , V_30 ,
F_20 ( V_29 ) , NULL , V_4 , V_29 , V_4 -> V_9 ,
F_13 ) ;
}
void F_24 ( const struct V_1 * V_25 , struct V_3 * V_4 )
{
if ( V_25 && F_1 ( V_25 , V_4 ) ) {
F_15 ( V_25 , V_4 ) ;
return;
}
F_12 ( V_4 ) ;
}
void F_25 ( const struct V_1 * V_25 , struct V_3 * V_4 , struct V_3 * V_31 )
{
if ( V_25 && F_1 ( V_25 , V_4 ) ) {
if ( V_31 )
F_26 ( V_25 , V_4 , F_21 ) ;
else
F_21 ( V_25 , V_4 ) ;
return;
}
if ( ! V_31 )
F_12 ( V_4 ) ;
}
static int F_26 ( const struct V_1 * V_32 ,
struct V_3 * V_4 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_28 * V_9 = F_28 ( V_4 ) -> V_33 ;
V_4 = F_29 ( V_4 , V_34 ) ;
if ( ! V_4 ) {
V_9 -> V_35 . V_36 ++ ;
return - V_37 ;
}
F_27 ( V_32 , V_4 ) ;
return 0 ;
}
static struct V_1 * F_30 (
struct V_1 * V_32 , struct V_1 * V_2 ,
struct V_3 * V_4 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
int V_38 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_32 ;
if ( ! V_32 )
goto V_39;
V_38 = F_26 ( V_32 , V_4 , F_27 ) ;
if ( V_38 )
return F_31 ( V_38 ) ;
V_39:
return V_2 ;
}
static void F_32 ( struct V_40 * V_26 , struct V_3 * V_4 ,
struct V_3 * V_31 ,
void (* F_27)( const struct V_1 * V_2 ,
struct V_3 * V_4 ) ,
bool V_41 )
{
struct V_1 * V_2 ;
struct V_1 * V_32 ;
V_32 = NULL ;
F_33 (p, &br->port_list, list) {
if ( V_41 && ! ( V_2 -> V_7 & V_42 ) )
continue;
if ( V_2 -> V_7 & V_43 )
continue;
if ( ( V_2 -> V_7 & V_44 ) &&
F_28 ( V_4 ) -> V_45 )
continue;
V_32 = F_30 ( V_32 , V_2 , V_4 , F_27 ) ;
if ( F_34 ( V_32 ) )
goto V_39;
}
if ( ! V_32 )
goto V_39;
if ( V_31 )
F_26 ( V_32 , V_4 , F_27 ) ;
else
F_27 ( V_32 , V_4 ) ;
return;
V_39:
if ( ! V_31 )
F_12 ( V_4 ) ;
}
void F_35 ( struct V_40 * V_26 , struct V_3 * V_4 , bool V_41 )
{
F_32 ( V_26 , V_4 , NULL , F_15 , V_41 ) ;
}
void F_36 ( struct V_40 * V_26 , struct V_3 * V_4 ,
struct V_3 * V_46 , bool V_41 )
{
F_32 ( V_26 , V_4 , V_46 , F_21 , V_41 ) ;
}
static void F_37 ( struct V_47 * V_48 ,
struct V_3 * V_4 , struct V_3 * V_31 ,
void (* F_27)(
const struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_28 * V_9 = F_28 ( V_4 ) -> V_33 ;
struct V_40 * V_26 = F_38 ( V_9 ) ;
struct V_1 * V_32 = NULL ;
struct V_49 * V_2 ;
struct V_50 * V_51 ;
V_51 = F_39 ( F_40 ( & V_26 -> V_52 ) ) ;
V_2 = V_48 ? F_39 ( V_48 -> V_53 ) : NULL ;
while ( V_2 || V_51 ) {
struct V_1 * V_54 , * V_55 , * V_56 ;
V_55 = V_2 ? V_2 -> V_54 : NULL ;
V_56 = V_51 ? F_41 ( V_51 , struct V_1 , V_57 ) :
NULL ;
V_54 = ( unsigned long ) V_55 > ( unsigned long ) V_56 ?
V_55 : V_56 ;
V_32 = F_30 ( V_32 , V_54 , V_4 , F_27 ) ;
if ( F_34 ( V_32 ) )
goto V_39;
if ( ( unsigned long ) V_55 >= ( unsigned long ) V_54 )
V_2 = F_39 ( V_2 -> V_58 ) ;
if ( ( unsigned long ) V_56 >= ( unsigned long ) V_54 )
V_51 = F_39 ( F_42 ( V_51 ) ) ;
}
if ( ! V_32 )
goto V_39;
if ( V_31 )
F_26 ( V_32 , V_4 , F_27 ) ;
else
F_27 ( V_32 , V_4 ) ;
return;
V_39:
if ( ! V_31 )
F_12 ( V_4 ) ;
}
void F_43 ( struct V_47 * V_48 ,
struct V_3 * V_4 )
{
F_37 ( V_48 , V_4 , NULL , F_15 ) ;
}
void F_44 ( struct V_47 * V_48 ,
struct V_3 * V_4 , struct V_3 * V_46 )
{
F_37 ( V_48 , V_4 , V_46 , F_21 ) ;
}
