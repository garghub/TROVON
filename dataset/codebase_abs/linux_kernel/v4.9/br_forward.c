static inline int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
return ( ( V_2 -> V_7 & V_8 ) || V_4 -> V_9 != V_2 -> V_9 ) &&
F_3 ( V_6 , V_4 ) && V_2 -> V_10 == V_11 &&
F_4 ( V_2 , V_4 ) ;
}
int F_5 ( struct V_12 * V_12 , struct V_13 * V_14 , struct V_3 * V_4 )
{
if ( ! F_6 ( V_4 -> V_9 , V_4 ) )
goto V_15;
F_7 ( V_4 , V_16 ) ;
F_8 ( V_4 ) ;
if ( V_4 -> V_17 == V_18 &&
( V_4 -> V_19 == F_9 ( V_20 ) ||
V_4 -> V_19 == F_9 ( V_21 ) ) ) {
int V_22 ;
if ( ! F_10 ( V_4 , V_4 -> V_19 , & V_22 ) )
goto V_15;
F_11 ( V_4 , V_22 ) ;
}
F_12 ( V_4 ) ;
return 0 ;
V_15:
F_13 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_12 * V_12 , struct V_13 * V_14 , struct V_3 * V_4 )
{
return F_15 ( V_23 , V_24 ,
V_12 , V_14 , V_4 , NULL , V_4 -> V_9 ,
F_5 ) ;
}
static void F_16 ( const struct V_1 * V_25 ,
struct V_3 * V_4 , bool V_26 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
struct V_12 * V_12 ;
int V_29 ;
V_6 = F_2 ( V_25 ) ;
V_4 = F_17 ( V_25 -> V_30 , V_6 , V_4 ) ;
if ( ! V_4 )
return;
V_28 = V_4 -> V_9 ;
V_4 -> V_9 = V_25 -> V_9 ;
if ( ! V_26 ) {
if ( F_18 ( V_4 ) ) {
F_13 ( V_4 ) ;
return;
}
V_29 = V_31 ;
F_19 ( V_4 ) ;
V_12 = F_20 ( V_28 ) ;
} else {
if ( F_21 ( F_22 ( V_25 -> V_30 -> V_9 ) ) ) {
if ( ! F_6 ( V_4 -> V_9 , V_4 ) ) {
F_13 ( V_4 ) ;
} else {
F_7 ( V_4 , V_16 ) ;
F_23 ( V_25 , V_4 ) ;
}
return;
}
V_29 = V_32 ;
V_12 = F_20 ( V_4 -> V_9 ) ;
V_28 = NULL ;
}
F_15 ( V_23 , V_29 ,
V_12 , NULL , V_4 , V_28 , V_4 -> V_9 ,
F_14 ) ;
}
static int F_24 ( const struct V_1 * V_33 ,
struct V_3 * V_4 , bool V_26 )
{
struct V_27 * V_9 = F_25 ( V_4 ) -> V_34 ;
V_4 = F_26 ( V_4 , V_35 ) ;
if ( ! V_4 ) {
V_9 -> V_36 . V_37 ++ ;
return - V_38 ;
}
F_16 ( V_33 , V_4 , V_26 ) ;
return 0 ;
}
void F_27 ( const struct V_1 * V_25 ,
struct V_3 * V_4 , bool V_39 , bool V_26 )
{
if ( V_25 && F_1 ( V_25 , V_4 ) ) {
if ( V_39 )
F_24 ( V_25 , V_4 , V_26 ) ;
else
F_16 ( V_25 , V_4 , V_26 ) ;
return;
}
if ( ! V_39 )
F_13 ( V_4 ) ;
}
static struct V_1 * F_28 (
struct V_1 * V_33 , struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_26 )
{
int V_40 ;
if ( ! F_1 ( V_2 , V_4 ) )
return V_33 ;
if ( ! V_33 )
goto V_41;
V_40 = F_24 ( V_33 , V_4 , V_26 ) ;
if ( V_40 )
return F_29 ( V_40 ) ;
V_41:
return V_2 ;
}
void F_30 ( struct V_42 * V_30 , struct V_3 * V_4 ,
enum V_43 V_44 , bool V_39 , bool V_26 )
{
T_1 V_45 = F_31 ( V_4 ) ;
struct V_1 * V_33 = NULL ;
struct V_1 * V_2 ;
F_32 (p, &br->port_list, list) {
if ( V_44 == V_46 && ! ( V_2 -> V_7 & V_47 ) )
continue;
if ( V_44 == V_48 &&
! ( V_2 -> V_7 & V_49 ) )
continue;
if ( V_2 -> V_7 & V_50 )
continue;
if ( ( V_2 -> V_7 & V_51 ) &&
F_25 ( V_4 ) -> V_52 )
continue;
V_33 = F_28 ( V_33 , V_2 , V_4 , V_26 ) ;
if ( F_33 ( V_33 ) )
goto V_41;
if ( V_33 == V_2 )
F_34 ( V_2 -> V_30 , V_2 , V_4 , V_45 ,
V_53 ) ;
}
if ( ! V_33 )
goto V_41;
if ( V_39 )
F_24 ( V_33 , V_4 , V_26 ) ;
else
F_16 ( V_33 , V_4 , V_26 ) ;
return;
V_41:
if ( ! V_39 )
F_13 ( V_4 ) ;
}
void F_35 ( struct V_54 * V_55 ,
struct V_3 * V_4 ,
bool V_39 , bool V_26 )
{
struct V_27 * V_9 = F_25 ( V_4 ) -> V_34 ;
T_1 V_45 = F_31 ( V_4 ) ;
struct V_42 * V_30 = F_36 ( V_9 ) ;
struct V_1 * V_33 = NULL ;
struct V_56 * V_2 ;
struct V_57 * V_58 ;
V_58 = F_37 ( F_38 ( & V_30 -> V_59 ) ) ;
V_2 = V_55 ? F_37 ( V_55 -> V_60 ) : NULL ;
while ( V_2 || V_58 ) {
struct V_1 * V_61 , * V_62 , * V_63 ;
V_62 = V_2 ? V_2 -> V_61 : NULL ;
V_63 = V_58 ? F_39 ( V_58 , struct V_1 , V_64 ) :
NULL ;
V_61 = ( unsigned long ) V_62 > ( unsigned long ) V_63 ?
V_62 : V_63 ;
V_33 = F_28 ( V_33 , V_61 , V_4 , V_26 ) ;
if ( F_33 ( V_33 ) )
goto V_41;
if ( V_33 == V_61 )
F_34 ( V_61 -> V_30 , V_61 , V_4 , V_45 ,
V_53 ) ;
if ( ( unsigned long ) V_62 >= ( unsigned long ) V_61 )
V_2 = F_37 ( V_2 -> V_65 ) ;
if ( ( unsigned long ) V_63 >= ( unsigned long ) V_61 )
V_58 = F_37 ( F_40 ( V_58 ) ) ;
}
if ( ! V_33 )
goto V_41;
if ( V_39 )
F_24 ( V_33 , V_4 , V_26 ) ;
else
F_16 ( V_33 , V_4 , V_26 ) ;
return;
V_41:
if ( ! V_39 )
F_13 ( V_4 ) ;
}
