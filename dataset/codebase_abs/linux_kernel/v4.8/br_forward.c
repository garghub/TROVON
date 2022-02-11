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
static void F_15 ( const struct V_1 * V_25 ,
struct V_3 * V_4 , bool V_26 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
struct V_12 * V_12 ;
int V_29 ;
V_6 = F_2 ( V_25 ) ;
V_4 = F_16 ( V_25 -> V_30 , V_6 , V_4 ) ;
if ( ! V_4 )
return;
V_28 = V_4 -> V_9 ;
V_4 -> V_9 = V_25 -> V_9 ;
if ( ! V_26 ) {
if ( F_17 ( V_4 ) ) {
F_12 ( V_4 ) ;
return;
}
V_29 = V_31 ;
F_18 ( V_4 ) ;
V_12 = F_19 ( V_28 ) ;
} else {
if ( F_20 ( F_21 ( V_25 -> V_30 -> V_9 ) ) ) {
if ( ! F_5 ( V_4 -> V_9 , V_4 ) ) {
F_12 ( V_4 ) ;
} else {
F_6 ( V_4 , V_16 ) ;
F_22 ( V_25 , V_4 ) ;
}
return;
}
V_29 = V_32 ;
V_12 = F_19 ( V_4 -> V_9 ) ;
V_28 = NULL ;
}
F_14 ( V_23 , V_29 ,
V_12 , NULL , V_4 , V_28 , V_4 -> V_9 ,
F_13 ) ;
}
static int F_23 ( const struct V_1 * V_33 ,
struct V_3 * V_4 , bool V_26 )
{
struct V_27 * V_9 = F_24 ( V_4 ) -> V_34 ;
V_4 = F_25 ( V_4 , V_35 ) ;
if ( ! V_4 ) {
V_9 -> V_36 . V_37 ++ ;
return - V_38 ;
}
F_15 ( V_33 , V_4 , V_26 ) ;
return 0 ;
}
void F_26 ( const struct V_1 * V_25 ,
struct V_3 * V_4 , bool V_39 , bool V_26 )
{
if ( V_25 && F_1 ( V_25 , V_4 ) ) {
if ( V_39 )
F_23 ( V_25 , V_4 , V_26 ) ;
else
F_15 ( V_25 , V_4 , V_26 ) ;
return;
}
if ( ! V_39 )
F_12 ( V_4 ) ;
}
static struct V_1 * F_27 (
struct V_1 * V_33 , struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_26 )
{
int V_40 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_33 ;
if ( ! V_33 )
goto V_41;
V_40 = F_23 ( V_33 , V_4 , V_26 ) ;
if ( V_40 )
return F_28 ( V_40 ) ;
V_41:
return V_2 ;
}
void F_29 ( struct V_42 * V_30 , struct V_3 * V_4 ,
bool V_43 , bool V_39 , bool V_26 )
{
T_1 V_44 = F_30 ( V_4 ) ;
struct V_1 * V_33 = NULL ;
struct V_1 * V_2 ;
F_31 (p, &br->port_list, list) {
if ( V_43 && ! ( V_2 -> V_7 & V_45 ) )
continue;
if ( V_2 -> V_7 & V_46 )
continue;
if ( ( V_2 -> V_7 & V_47 ) &&
F_24 ( V_4 ) -> V_48 )
continue;
V_33 = F_27 ( V_33 , V_2 , V_4 , V_26 ) ;
if ( F_32 ( V_33 ) )
goto V_41;
if ( V_33 == V_2 )
F_33 ( V_2 -> V_30 , V_2 , V_4 , V_44 ,
V_49 ) ;
}
if ( ! V_33 )
goto V_41;
if ( V_39 )
F_23 ( V_33 , V_4 , V_26 ) ;
else
F_15 ( V_33 , V_4 , V_26 ) ;
return;
V_41:
if ( ! V_39 )
F_12 ( V_4 ) ;
}
void F_34 ( struct V_50 * V_51 ,
struct V_3 * V_4 ,
bool V_39 , bool V_26 )
{
struct V_27 * V_9 = F_24 ( V_4 ) -> V_34 ;
T_1 V_44 = F_30 ( V_4 ) ;
struct V_42 * V_30 = F_35 ( V_9 ) ;
struct V_1 * V_33 = NULL ;
struct V_52 * V_2 ;
struct V_53 * V_54 ;
V_54 = F_36 ( F_37 ( & V_30 -> V_55 ) ) ;
V_2 = V_51 ? F_36 ( V_51 -> V_56 ) : NULL ;
while ( V_2 || V_54 ) {
struct V_1 * V_57 , * V_58 , * V_59 ;
V_58 = V_2 ? V_2 -> V_57 : NULL ;
V_59 = V_54 ? F_38 ( V_54 , struct V_1 , V_60 ) :
NULL ;
V_57 = ( unsigned long ) V_58 > ( unsigned long ) V_59 ?
V_58 : V_59 ;
V_33 = F_27 ( V_33 , V_57 , V_4 , V_26 ) ;
if ( F_32 ( V_33 ) )
goto V_41;
if ( V_33 == V_57 )
F_33 ( V_57 -> V_30 , V_57 , V_4 , V_44 ,
V_49 ) ;
if ( ( unsigned long ) V_58 >= ( unsigned long ) V_57 )
V_2 = F_36 ( V_2 -> V_61 ) ;
if ( ( unsigned long ) V_59 >= ( unsigned long ) V_57 )
V_54 = F_36 ( F_39 ( V_54 ) ) ;
}
if ( ! V_33 )
goto V_41;
if ( V_39 )
F_23 ( V_33 , V_4 , V_26 ) ;
else
F_15 ( V_33 , V_4 , V_26 ) ;
return;
V_41:
if ( ! V_39 )
F_12 ( V_4 ) ;
}
