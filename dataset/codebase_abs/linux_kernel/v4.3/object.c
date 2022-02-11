int
F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_1 V_5 )
{
if ( F_2 ( V_2 -> V_6 -> V_3 ) )
return V_2 -> V_6 -> V_3 ( V_2 , V_3 , V_4 , V_5 ) ;
return - V_7 ;
}
int
F_3 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_8 * * V_9 )
{
if ( F_2 ( V_2 -> V_6 -> V_10 ) )
return V_2 -> V_6 -> V_10 ( V_2 , V_3 , V_9 ) ;
return - V_7 ;
}
int
F_4 ( struct V_1 * V_2 , T_2 * V_11 , T_1 * V_5 )
{
if ( F_2 ( V_2 -> V_6 -> V_12 ) )
return V_2 -> V_6 -> V_12 ( V_2 , V_11 , V_5 ) ;
return - V_7 ;
}
int
F_5 ( struct V_1 * V_2 , T_2 V_11 , T_3 * V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_13 ) )
return V_2 -> V_6 -> V_13 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_6 ( struct V_1 * V_2 , T_2 V_11 , T_4 * V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_14 ) )
return V_2 -> V_6 -> V_14 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_7 ( struct V_1 * V_2 , T_2 V_11 , T_1 * V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_15 ) )
return V_2 -> V_6 -> V_15 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_8 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_16 ) )
return V_2 -> V_6 -> V_16 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_9 ( struct V_1 * V_2 , T_2 V_11 , T_4 V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_17 ) )
return V_2 -> V_6 -> V_17 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_10 ( struct V_1 * V_2 , T_2 V_11 , T_1 V_4 )
{
if ( F_2 ( V_2 -> V_6 -> V_18 ) )
return V_2 -> V_6 -> V_18 ( V_2 , V_11 , V_4 ) ;
return - V_7 ;
}
int
F_11 ( struct V_1 * V_2 , struct V_19 * V_20 ,
int V_21 , struct V_19 * * V_22 )
{
if ( V_2 -> V_6 -> V_23 )
return V_2 -> V_6 -> V_23 ( V_2 , V_20 , V_21 , V_22 ) ;
return - V_7 ;
}
int
F_12 ( struct V_1 * V_2 , bool V_24 )
{
const char * V_25 = V_24 ? L_1 : L_2 ;
struct V_1 * V_26 ;
T_5 time ;
int V_27 ;
F_13 ( V_2 , L_3 , V_25 ) ;
time = F_14 ( F_15 () ) ;
F_16 (child, &object->tree, head) {
V_27 = F_12 ( V_26 , V_24 ) ;
if ( V_27 && V_24 )
goto V_28;
}
F_13 ( V_2 , L_4 , V_25 ) ;
if ( V_2 -> V_6 -> V_29 ) {
V_27 = V_2 -> V_6 -> V_29 ( V_2 , V_24 ) ;
if ( V_27 ) {
F_17 ( V_2 , L_5 , V_25 , V_27 ) ;
if ( V_24 )
goto V_30;
}
}
time = F_14 ( F_15 () ) - time ;
F_13 ( V_2 , L_6 , V_25 , time ) ;
return 0 ;
V_30:
if ( V_2 -> V_6 -> V_31 ) {
int V_32 = V_2 -> V_6 -> V_31 ( V_2 ) ;
if ( V_32 )
F_18 ( V_2 , L_7 , V_32 ) ;
}
V_28:
F_19 (child, &object->tree, head) {
F_20 ( V_26 ) ;
}
return V_27 ;
}
int
F_20 ( struct V_1 * V_2 )
{
struct V_1 * V_26 ;
T_5 time ;
int V_27 ;
F_13 ( V_2 , L_8 ) ;
time = F_14 ( F_15 () ) ;
if ( V_2 -> V_6 -> V_31 ) {
V_27 = V_2 -> V_6 -> V_31 ( V_2 ) ;
if ( V_27 )
goto V_30;
}
F_13 ( V_2 , L_9 ) ;
F_16 (child, &object->tree, head) {
V_27 = F_20 ( V_26 ) ;
if ( V_27 )
goto V_28;
}
time = F_14 ( F_15 () ) - time ;
F_13 ( V_2 , L_10 , time ) ;
return 0 ;
V_28:
F_19 (child, &object->tree, head)
F_12 ( V_26 , false ) ;
V_30:
F_17 ( V_2 , L_11 , V_27 ) ;
if ( V_2 -> V_6 -> V_29 )
V_2 -> V_6 -> V_29 ( V_2 , false ) ;
return V_27 ;
}
void *
F_21 ( struct V_1 * V_2 )
{
struct V_1 * V_26 , * V_33 ;
void * V_4 = V_2 ;
T_5 time ;
F_13 ( V_2 , L_12 ) ;
time = F_14 ( F_15 () ) ;
F_22 (child, ctemp, &object->tree, head) {
F_23 ( & V_26 ) ;
}
F_13 ( V_2 , L_13 ) ;
if ( V_2 -> V_6 -> V_34 )
V_4 = V_2 -> V_6 -> V_34 ( V_2 ) ;
F_24 ( & V_2 -> V_35 ) ;
time = F_14 ( F_15 () ) - time ;
F_13 ( V_2 , L_14 , time ) ;
return V_4 ;
}
void
F_23 ( struct V_1 * * V_36 )
{
struct V_1 * V_2 = * V_36 ;
if ( V_2 && ! F_25 ( ! V_2 -> V_6 ) ) {
* V_36 = F_21 ( V_2 ) ;
F_26 ( V_2 -> V_37 , V_2 ) ;
F_27 ( & V_2 -> V_38 ) ;
F_28 ( * V_36 ) ;
* V_36 = NULL ;
}
}
void
F_29 ( const struct V_39 * V_6 ,
const struct V_40 * V_41 , struct V_1 * V_2 )
{
V_2 -> V_6 = V_6 ;
V_2 -> V_37 = V_41 -> V_37 ;
V_2 -> V_35 = F_30 ( V_41 -> V_35 ) ;
V_2 -> V_41 = V_41 -> V_42 . V_41 ;
V_2 -> V_43 = V_41 -> V_43 ;
F_31 ( & V_2 -> V_38 ) ;
F_31 ( & V_2 -> V_44 ) ;
F_32 ( & V_2 -> V_45 ) ;
F_25 ( V_41 -> V_35 && ! V_2 -> V_35 ) ;
}
int
F_33 ( const struct V_39 * V_6 ,
const struct V_40 * V_41 , void * V_4 , T_1 V_5 ,
struct V_1 * * V_36 )
{
if ( V_5 == 0 ) {
if ( ! ( * V_36 = F_34 ( sizeof( * * V_36 ) , V_46 ) ) )
return - V_47 ;
F_29 ( V_6 , V_41 , * V_36 ) ;
return 0 ;
}
return - V_48 ;
}
int
F_35 ( const struct V_40 * V_41 , void * V_4 , T_1 V_5 ,
struct V_1 * * V_36 )
{
const struct V_39 * V_6 =
V_41 -> V_42 . V_6 ? V_41 -> V_42 . V_6 : & V_39 ;
return F_33 ( V_6 , V_41 , V_4 , V_5 , V_36 ) ;
}
