struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 ,
const struct V_5 * V_6 )
{
struct V_1 * V_7 ;
if ( V_4 ) {
struct V_8 * V_9 = V_3 -> V_10 . V_8 ;
while ( V_9 ) {
V_7 = F_2 ( V_9 , F_3 ( * V_7 ) , V_9 ) ;
if ( V_4 < V_7 -> V_7 )
V_9 = V_9 -> V_11 ;
else
if ( V_4 > V_7 -> V_7 )
V_9 = V_9 -> V_12 ;
else
goto V_13;
}
return F_4 ( - V_14 ) ;
} else {
V_7 = & V_3 -> V_7 ;
}
V_13:
if ( F_5 ( V_6 && V_7 -> V_6 != V_6 ) )
return F_4 ( - V_15 ) ;
return V_7 ;
}
void
F_6 ( struct V_1 * V_7 )
{
if ( ! F_7 ( & V_7 -> V_9 ) )
F_8 ( & V_7 -> V_9 , & V_7 -> V_3 -> V_10 ) ;
}
bool
F_9 ( struct V_1 * V_7 )
{
struct V_8 * * V_16 = & V_7 -> V_3 -> V_10 . V_8 ;
struct V_8 * V_17 = NULL ;
while ( * V_16 ) {
struct V_1 * V_18 = F_2 ( * V_16 , F_3 ( * V_18 ) , V_9 ) ;
V_17 = * V_16 ;
if ( V_7 -> V_7 < V_18 -> V_7 )
V_16 = & V_17 -> V_11 ;
else
if ( V_7 -> V_7 > V_18 -> V_7 )
V_16 = & V_17 -> V_12 ;
else
return false ;
}
F_10 ( & V_7 -> V_9 , V_17 , V_16 ) ;
F_11 ( & V_7 -> V_9 , & V_7 -> V_3 -> V_10 ) ;
return true ;
}
int
F_12 ( struct V_1 * V_7 , T_2 V_19 , void * V_20 , T_2 V_21 )
{
if ( F_13 ( V_7 -> V_6 -> V_19 ) )
return V_7 -> V_6 -> V_19 ( V_7 , V_19 , V_20 , V_21 ) ;
return - V_22 ;
}
int
F_14 ( struct V_1 * V_7 , T_2 V_19 ,
struct V_23 * * V_24 )
{
if ( F_13 ( V_7 -> V_6 -> V_25 ) )
return V_7 -> V_6 -> V_25 ( V_7 , V_19 , V_24 ) ;
return - V_22 ;
}
int
F_15 ( struct V_1 * V_7 , T_1 * V_26 , T_2 * V_21 )
{
if ( F_13 ( V_7 -> V_6 -> V_27 ) )
return V_7 -> V_6 -> V_27 ( V_7 , V_26 , V_21 ) ;
return - V_22 ;
}
int
F_16 ( struct V_1 * V_7 , T_1 V_26 , T_3 * V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_28 ) )
return V_7 -> V_6 -> V_28 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_17 ( struct V_1 * V_7 , T_1 V_26 , T_4 * V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_29 ) )
return V_7 -> V_6 -> V_29 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_18 ( struct V_1 * V_7 , T_1 V_26 , T_2 * V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_30 ) )
return V_7 -> V_6 -> V_30 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_19 ( struct V_1 * V_7 , T_1 V_26 , T_3 V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_31 ) )
return V_7 -> V_6 -> V_31 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_20 ( struct V_1 * V_7 , T_1 V_26 , T_4 V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_32 ) )
return V_7 -> V_6 -> V_32 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_21 ( struct V_1 * V_7 , T_1 V_26 , T_2 V_20 )
{
if ( F_13 ( V_7 -> V_6 -> V_33 ) )
return V_7 -> V_6 -> V_33 ( V_7 , V_26 , V_20 ) ;
return - V_22 ;
}
int
F_22 ( struct V_1 * V_7 , struct V_34 * V_35 ,
int V_36 , struct V_34 * * V_37 )
{
if ( V_7 -> V_6 -> V_38 )
return V_7 -> V_6 -> V_38 ( V_7 , V_35 , V_36 , V_37 ) ;
return - V_22 ;
}
int
F_23 ( struct V_1 * V_7 , bool V_39 )
{
const char * V_40 = V_39 ? L_1 : L_2 ;
struct V_1 * V_41 ;
T_5 time ;
int V_42 ;
F_24 ( V_7 , L_3 , V_40 ) ;
time = F_25 ( F_26 () ) ;
F_27 (child, &object->tree, head) {
V_42 = F_23 ( V_41 , V_39 ) ;
if ( V_42 && V_39 )
goto V_43;
}
F_24 ( V_7 , L_4 , V_40 ) ;
if ( V_7 -> V_6 -> V_44 ) {
V_42 = V_7 -> V_6 -> V_44 ( V_7 , V_39 ) ;
if ( V_42 ) {
F_28 ( V_7 , L_5 , V_40 , V_42 ) ;
if ( V_39 )
goto V_45;
}
}
time = F_25 ( F_26 () ) - time ;
F_24 ( V_7 , L_6 , V_40 , time ) ;
return 0 ;
V_45:
if ( V_7 -> V_6 -> V_46 ) {
int V_47 = V_7 -> V_6 -> V_46 ( V_7 ) ;
if ( V_47 )
F_29 ( V_7 , L_7 , V_47 ) ;
}
V_43:
F_30 (child, &object->tree, head) {
F_31 ( V_41 ) ;
}
return V_42 ;
}
int
F_31 ( struct V_1 * V_7 )
{
struct V_1 * V_41 ;
T_5 time ;
int V_42 ;
F_24 ( V_7 , L_8 ) ;
time = F_25 ( F_26 () ) ;
if ( V_7 -> V_6 -> V_46 ) {
V_42 = V_7 -> V_6 -> V_46 ( V_7 ) ;
if ( V_42 )
goto V_45;
}
F_24 ( V_7 , L_9 ) ;
F_27 (child, &object->tree, head) {
V_42 = F_31 ( V_41 ) ;
if ( V_42 )
goto V_43;
}
time = F_25 ( F_26 () ) - time ;
F_24 ( V_7 , L_10 , time ) ;
return 0 ;
V_43:
F_30 (child, &object->tree, head)
F_23 ( V_41 , false ) ;
V_45:
F_28 ( V_7 , L_11 , V_42 ) ;
if ( V_7 -> V_6 -> V_44 )
V_7 -> V_6 -> V_44 ( V_7 , false ) ;
return V_42 ;
}
void *
F_32 ( struct V_1 * V_7 )
{
struct V_1 * V_41 , * V_48 ;
void * V_20 = V_7 ;
T_5 time ;
F_24 ( V_7 , L_12 ) ;
time = F_25 ( F_26 () ) ;
F_33 (child, ctemp, &object->tree, head) {
F_34 ( & V_41 ) ;
}
F_24 ( V_7 , L_13 ) ;
if ( V_7 -> V_6 -> V_49 )
V_20 = V_7 -> V_6 -> V_49 ( V_7 ) ;
F_35 ( & V_7 -> V_50 ) ;
time = F_25 ( F_26 () ) - time ;
F_24 ( V_7 , L_14 , time ) ;
return V_20 ;
}
void
F_34 ( struct V_1 * * V_51 )
{
struct V_1 * V_7 = * V_51 ;
if ( V_7 && ! F_36 ( ! V_7 -> V_6 ) ) {
* V_51 = F_32 ( V_7 ) ;
F_6 ( V_7 ) ;
F_37 ( & V_7 -> V_52 ) ;
F_38 ( * V_51 ) ;
* V_51 = NULL ;
}
}
void
F_39 ( const struct V_5 * V_6 ,
const struct V_53 * V_54 , struct V_1 * V_7 )
{
V_7 -> V_6 = V_6 ;
V_7 -> V_3 = V_54 -> V_3 ;
V_7 -> V_50 = F_40 ( V_54 -> V_50 ) ;
V_7 -> V_54 = V_54 -> V_55 . V_54 ;
V_7 -> V_4 = V_54 -> V_4 ;
V_7 -> V_56 = V_54 -> V_56 ;
V_7 -> V_57 = V_54 -> V_57 ;
V_7 -> V_7 = V_54 -> V_7 ;
F_41 ( & V_7 -> V_52 ) ;
F_41 ( & V_7 -> V_58 ) ;
F_42 ( & V_7 -> V_9 ) ;
F_36 ( F_43 ( V_7 -> V_50 ) ) ;
}
int
F_44 ( const struct V_5 * V_6 ,
const struct V_53 * V_54 , void * V_20 , T_2 V_21 ,
struct V_1 * * V_51 )
{
if ( V_21 == 0 ) {
if ( ! ( * V_51 = F_45 ( sizeof( * * V_51 ) , V_59 ) ) )
return - V_60 ;
F_39 ( V_6 , V_54 , * V_51 ) ;
return 0 ;
}
return - V_61 ;
}
int
F_46 ( const struct V_53 * V_54 , void * V_20 , T_2 V_21 ,
struct V_1 * * V_51 )
{
const struct V_5 * V_6 =
V_54 -> V_55 . V_6 ? V_54 -> V_55 . V_6 : & V_5 ;
return F_44 ( V_6 , V_54 , V_20 , V_21 , V_51 ) ;
}
