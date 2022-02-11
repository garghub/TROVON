static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * type = F_3 ( V_2 ) ;
T_1 V_9 = - V_10 ;
if ( V_7 -> V_11 )
V_9 = V_7 -> V_11 ( V_2 , type -> V_12 -> V_13 , V_5 ) ;
return V_9 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * type = F_3 ( V_2 ) ;
T_1 V_9 = - V_10 ;
if ( V_7 -> V_15 )
V_9 = V_7 -> V_15 ( & type -> V_2 , type -> V_12 -> V_13 , V_5 , V_14 ) ;
return V_9 ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_16 * V_13 ,
const char * V_5 , T_2 V_14 )
{
char * V_17 ;
T_3 V_18 ;
int V_9 ;
if ( ( V_14 < V_19 ) || ( V_14 > V_19 + 1 ) )
return - V_20 ;
V_17 = F_6 ( V_5 , V_14 , V_21 ) ;
if ( ! V_17 )
return - V_22 ;
V_9 = F_7 ( V_17 , & V_18 ) ;
F_8 ( V_17 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_9 ( V_2 , V_13 , V_18 ) ;
if ( V_9 )
return V_9 ;
return V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * type = F_3 ( V_2 ) ;
F_11 ( L_1 , V_2 -> V_23 ) ;
F_8 ( type ) ;
}
struct V_8 * F_12 ( struct V_24 * V_12 ,
struct V_25 * V_26 )
{
struct V_8 * type ;
int V_9 ;
if ( ! V_26 -> V_23 ) {
F_13 ( L_2 , V_27 ) ;
return F_14 ( - V_20 ) ;
}
type = F_15 ( sizeof( * type ) , V_21 ) ;
if ( ! type )
return F_14 ( - V_22 ) ;
type -> V_2 . V_28 = V_12 -> V_29 ;
V_9 = F_16 ( & type -> V_2 , & V_30 , NULL ,
L_3 , F_17 ( V_12 -> V_13 ) ,
V_26 -> V_23 ) ;
if ( V_9 ) {
F_8 ( type ) ;
return F_14 ( V_9 ) ;
}
V_9 = F_18 ( & type -> V_2 , & V_31 . V_7 ) ;
if ( V_9 )
goto V_32;
type -> V_33 = F_19 ( L_4 , & type -> V_2 ) ;
if ( ! type -> V_33 ) {
V_9 = - V_22 ;
goto V_34;
}
V_9 = F_20 ( & type -> V_2 ,
( const struct V_3 * * ) V_26 -> V_35 ) ;
if ( V_9 ) {
V_9 = - V_22 ;
goto V_36;
}
type -> V_26 = V_26 ;
type -> V_12 = V_12 ;
return type ;
V_36:
F_21 ( type -> V_33 ) ;
V_34:
F_22 ( & type -> V_2 , & V_31 . V_7 ) ;
V_32:
F_23 ( & type -> V_2 ) ;
F_21 ( & type -> V_2 ) ;
return F_14 ( V_9 ) ;
}
static void F_24 ( struct V_8 * type )
{
F_25 ( & type -> V_2 ,
( const struct V_3 * * ) type -> V_26 -> V_35 ) ;
F_21 ( type -> V_33 ) ;
F_22 ( & type -> V_2 , & V_31 . V_7 ) ;
F_23 ( & type -> V_2 ) ;
F_21 ( & type -> V_2 ) ;
}
static int F_26 ( struct V_24 * V_12 )
{
int V_37 ;
for ( V_37 = 0 ; V_12 -> V_38 -> V_39 [ V_37 ] ; V_37 ++ ) {
struct V_8 * type ;
type = F_12 ( V_12 ,
V_12 -> V_38 -> V_39 [ V_37 ] ) ;
if ( F_27 ( type ) ) {
struct V_8 * V_40 , * V_41 ;
F_28 (ltype, tmp, &parent->type_list,
next) {
F_29 ( & V_40 -> V_42 ) ;
F_24 ( V_40 ) ;
}
return F_30 ( type ) ;
}
F_31 ( & type -> V_42 , & V_12 -> V_43 ) ;
}
return 0 ;
}
void F_32 ( struct V_24 * V_12 )
{
struct V_8 * type , * V_41 ;
F_28 (type, tmp, &parent->type_list, next) {
F_29 ( & type -> V_42 ) ;
F_24 ( type ) ;
}
F_33 ( & V_12 -> V_13 -> V_2 , V_12 -> V_38 -> V_44 ) ;
F_34 ( V_12 -> V_29 ) ;
}
int F_35 ( struct V_24 * V_12 )
{
int V_9 ;
V_12 -> V_29 = F_36 ( L_5 ,
NULL , & V_12 -> V_13 -> V_2 ) ;
if ( ! V_12 -> V_29 )
return - V_22 ;
F_37 ( & V_12 -> V_43 ) ;
V_9 = F_38 ( & V_12 -> V_13 -> V_2 ,
V_12 -> V_38 -> V_44 ) ;
if ( V_9 )
goto V_45;
V_9 = F_26 ( V_12 ) ;
if ( V_9 )
F_33 ( & V_12 -> V_13 -> V_2 ,
V_12 -> V_38 -> V_44 ) ;
else
return V_9 ;
V_45:
F_34 ( V_12 -> V_29 ) ;
return V_9 ;
}
static T_1 F_39 ( struct V_16 * V_13 , struct V_46 * V_7 ,
const char * V_5 , T_2 V_14 )
{
unsigned long V_47 ;
if ( F_40 ( V_5 , 0 , & V_47 ) < 0 )
return - V_20 ;
if ( V_47 && F_41 ( V_13 , V_7 ) ) {
int V_9 ;
V_9 = F_42 ( V_13 , false ) ;
if ( V_9 ) {
F_43 ( V_13 , V_7 ) ;
return V_9 ;
}
}
return V_14 ;
}
int F_44 ( struct V_16 * V_13 , struct V_8 * type )
{
int V_9 ;
V_9 = F_20 ( & V_13 -> V_2 , V_48 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_45 ( type -> V_33 , & V_13 -> V_2 , F_46 ( V_13 ) ) ;
if ( V_9 )
goto V_49;
V_9 = F_45 ( & V_13 -> V_2 , & type -> V_2 , L_6 ) ;
if ( V_9 )
goto V_50;
return V_9 ;
V_50:
F_47 ( type -> V_33 , F_46 ( V_13 ) ) ;
V_49:
F_25 ( & V_13 -> V_2 , V_48 ) ;
return V_9 ;
}
void F_48 ( struct V_16 * V_13 , struct V_8 * type )
{
F_47 ( & V_13 -> V_2 , L_6 ) ;
F_47 ( type -> V_33 , F_46 ( V_13 ) ) ;
F_25 ( & V_13 -> V_2 , V_48 ) ;
}
