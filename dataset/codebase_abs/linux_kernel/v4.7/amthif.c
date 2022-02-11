void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 ;
if ( F_3 ( V_12 ) )
return 0 ;
V_2 -> V_5 = V_6 ;
F_4 ( V_12 , V_2 ) ;
V_14 = F_5 ( V_12 ) ;
if ( V_14 < 0 ) {
F_6 ( V_2 -> V_2 , L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_7 ( V_12 , V_10 , NULL ) ;
return V_14 ;
}
int F_8 ( struct V_1 * V_2 , struct V_15 * V_15 ,
char T_1 * V_16 , T_2 V_17 , T_3 * V_18 )
{
struct V_11 * V_12 = V_15 -> V_19 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
F_9 ( V_2 -> V_2 , L_2 ) ;
V_21 = F_10 ( V_12 , V_15 ) ;
if ( V_21 == NULL && V_15 -> V_24 & V_25 )
return - V_26 ;
F_9 ( V_2 -> V_2 , L_3 ) ;
while ( V_21 == NULL ) {
F_11 ( & V_2 -> V_27 ) ;
V_23 = F_12 ( V_12 -> V_28 ,
! F_13 ( & V_12 -> V_29 ) ||
! F_3 ( V_12 ) ) ;
F_14 ( & V_2 -> V_27 ) ;
if ( V_23 )
return - V_30 ;
if ( ! F_3 ( V_12 ) ) {
V_22 = - V_31 ;
goto V_32;
}
V_21 = F_10 ( V_12 , V_15 ) ;
}
if ( V_21 -> V_33 ) {
V_22 = V_21 -> V_33 ;
F_9 ( V_2 -> V_2 , L_4 , V_22 ) ;
goto free;
}
F_9 ( V_2 -> V_2 , L_5 ) ;
if ( V_21 -> V_34 >= * V_18 && V_17 >= ( V_21 -> V_34 - * V_18 ) )
F_15 ( & V_21 -> V_35 ) ;
else if ( V_21 -> V_34 <= * V_18 ) {
F_15 ( & V_21 -> V_35 ) ;
V_22 = 0 ;
goto free;
}
F_9 ( V_2 -> V_2 , L_6 ,
V_21 -> V_36 . V_37 , V_21 -> V_34 ) ;
V_17 = F_16 ( T_2 , V_17 , ( V_21 -> V_34 - * V_18 ) ) ;
if ( F_17 ( V_16 , V_21 -> V_36 . V_38 + * V_18 , V_17 ) ) {
F_9 ( V_2 -> V_2 , L_7 ) ;
V_22 = - V_39 ;
} else {
V_22 = V_17 ;
if ( ( * V_18 + V_17 ) < V_21 -> V_34 ) {
* V_18 += V_17 ;
goto V_32;
}
}
free:
F_9 ( V_2 -> V_2 , L_8 ) ;
* V_18 = 0 ;
F_18 ( V_21 ) ;
V_32:
return V_22 ;
}
static int F_19 ( struct V_11 * V_12 , const struct V_15 * V_15 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_20 * V_21 ;
int V_22 ;
V_21 = F_20 ( V_12 , V_40 , V_15 ) ;
if ( ! V_21 ) {
V_22 = - V_41 ;
goto V_42;
}
V_22 = F_21 ( V_21 , F_22 ( V_12 ) ) ;
if ( V_22 )
goto V_42;
F_23 ( & V_21 -> V_35 , & V_2 -> V_43 . V_35 ) ;
V_2 -> V_5 = V_44 ;
V_2 -> V_45 = V_21 -> V_46 ;
V_2 -> V_3 = V_21 ;
return 0 ;
V_42:
F_18 ( V_21 ) ;
return V_22 ;
}
static int F_24 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_14 ;
if ( ! V_12 -> V_2 || ! V_21 )
return - V_47 ;
V_2 = V_12 -> V_2 ;
V_2 -> V_5 = V_48 ;
V_2 -> V_3 = V_21 ;
V_2 -> V_45 = V_21 -> V_46 ;
V_2 -> V_4 = false ;
V_14 = F_25 ( V_12 , V_21 , false ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_21 -> V_49 )
V_21 -> V_33 = F_19 ( V_12 , V_21 -> V_46 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_20 * V_21 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_45 = NULL ;
F_9 ( V_2 -> V_2 , L_9 ) ;
V_21 = F_27 ( & V_2 -> V_50 . V_35 ,
F_28 ( * V_21 ) , V_35 ) ;
if ( ! V_21 )
return 0 ;
F_15 ( & V_21 -> V_35 ) ;
return F_24 ( V_12 , V_21 ) ;
}
int F_29 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_23 ( & V_21 -> V_35 , & V_2 -> V_50 . V_35 ) ;
if ( V_2 -> V_5 > V_6 &&
V_2 -> V_5 < V_51 )
return 0 ;
return F_26 ( V_2 ) ;
}
unsigned int F_30 ( struct V_1 * V_2 ,
struct V_15 * V_15 , T_4 * V_52 )
{
unsigned int V_53 = 0 ;
F_31 ( V_15 , & V_2 -> V_13 . V_28 , V_52 ) ;
if ( V_2 -> V_5 == V_51 &&
V_2 -> V_45 == V_15 ) {
V_53 |= V_54 | V_55 ;
F_26 ( V_2 ) ;
}
return V_53 ;
}
int F_32 ( struct V_11 * V_12 , struct V_20 * V_21 ,
struct V_20 * V_56 )
{
int V_14 ;
V_14 = F_33 ( V_12 , V_21 , V_56 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_49 )
V_21 -> V_33 = F_19 ( V_12 , V_21 -> V_46 ) ;
return 0 ;
}
int F_34 ( struct V_11 * V_12 ,
struct V_57 * V_58 ,
struct V_20 * V_56 )
{
struct V_1 * V_2 ;
int V_14 ;
V_2 = V_12 -> V_2 ;
if ( V_2 -> V_5 != V_44 ) {
F_35 ( V_2 , V_58 ) ;
return 0 ;
}
V_14 = F_36 ( V_12 , V_58 , V_56 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_58 -> V_59 )
return 0 ;
F_9 ( V_2 -> V_2 , L_10 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_7 = 0 ;
return 0 ;
}
void F_37 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_21 -> V_60 == V_61 ) {
if ( ! V_21 -> V_33 ) {
V_2 -> V_7 = V_62 ;
F_18 ( V_21 ) ;
return;
}
F_23 ( & V_21 -> V_35 , & V_12 -> V_29 ) ;
F_38 ( & V_12 -> V_28 ) ;
return;
}
if ( ! V_2 -> V_4 ) {
V_2 -> V_5 = V_51 ;
V_2 -> V_7 = 0 ;
F_23 ( & V_21 -> V_35 , & V_12 -> V_29 ) ;
F_9 ( V_2 -> V_2 , L_11 ) ;
} else {
F_26 ( V_2 ) ;
}
F_9 ( V_2 -> V_2 , L_12 ) ;
F_38 ( & V_12 -> V_28 ) ;
}
static bool F_39 ( struct V_1 * V_2 ,
const struct V_15 * V_15 , struct V_63 * V_64 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_20 * V_21 , * V_65 ;
bool V_66 = false ;
F_40 (cb, next, mei_cb_list, list) {
if ( V_15 == V_21 -> V_46 ) {
if ( V_2 -> V_3 == V_21 ) {
V_2 -> V_3 = NULL ;
F_41 ( V_2 , V_12 ) ;
}
F_18 ( V_21 ) ;
V_66 = true ;
}
}
return V_66 ;
}
static bool F_42 ( struct V_1 * V_2 , const struct V_15 * V_15 )
{
bool V_66 = false ;
struct V_11 * V_12 = & V_2 -> V_13 ;
F_39 ( V_2 , V_15 , & V_2 -> V_50 . V_35 ) ;
if ( F_39 ( V_2 , V_15 , & V_12 -> V_29 ) )
V_66 = true ;
F_39 ( V_2 , V_15 , & V_2 -> V_67 . V_35 ) ;
if ( F_39 ( V_2 , V_15 , & V_2 -> V_43 . V_35 ) )
V_66 = true ;
if ( F_39 ( V_2 , V_15 , & V_2 -> V_68 . V_35 ) )
V_66 = true ;
if ( F_39 ( V_2 , V_15 , & V_2 -> V_69 . V_35 ) )
V_66 = true ;
if ( V_2 -> V_3 && ! V_66 ) {
if ( V_2 -> V_3 -> V_46 == V_15 ) {
F_18 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_66 = true ;
}
}
return V_66 ;
}
int F_43 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
if ( V_2 -> V_8 > 0 )
V_2 -> V_8 -- ;
if ( V_2 -> V_45 == V_15 &&
V_2 -> V_5 != V_6 ) {
F_9 ( V_2 -> V_2 , L_13 ,
V_2 -> V_5 ) ;
V_2 -> V_4 = true ;
if ( V_2 -> V_5 == V_51 ) {
F_9 ( V_2 -> V_2 , L_14 ) ;
F_26 ( V_2 ) ;
}
}
if ( F_42 ( V_2 , V_15 ) )
V_2 -> V_5 = V_6 ;
return 0 ;
}
