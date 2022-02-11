void F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
F_2 ( V_2 , ! F_3 ( & V_5 -> V_2 . V_6 )
|| V_5 -> V_7 != V_2 ,
L_1 , V_8 ) ;
V_5 -> V_7 = NULL ;
* V_4 = NULL ;
F_4 ( & V_5 -> V_2 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 = * V_4 ;
if ( ! V_5 )
return;
F_6 ( & V_5 -> V_2 ) ;
F_7 ( & V_5 -> V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_5 -> V_2 ) ;
F_4 ( & V_5 -> V_2 ) ;
}
bool F_9 ( struct V_1 * V_2 , struct V_3 * V_9 ,
struct V_3 * * V_4 )
{
if ( V_9 -> V_7 )
return false ;
F_2 ( V_2 , ! F_3 ( & V_9 -> V_2 . V_6 )
|| * V_4 ,
L_1 , V_8 ) ;
V_9 -> V_7 = V_2 ;
* V_4 = V_9 ;
F_6 ( & V_9 -> V_2 ) ;
return true ;
}
bool F_10 ( struct V_1 * V_2 , struct V_3 * V_9 ,
struct V_3 * * V_4 )
{
bool V_10 ;
F_7 ( & V_9 -> V_2 ) ;
V_10 = F_9 ( V_2 , V_9 , V_4 ) ;
F_8 ( & V_9 -> V_2 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_11 )
{
char * V_12 = V_11 ;
return strcmp ( V_12 , F_12 ( V_2 ) ) == 0 ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_5 )
{
struct V_13 * V_13 = F_14 ( V_2 -> V_14 ) ;
struct V_1 * V_15 = NULL ;
if ( F_15 ( V_2 ) )
V_15 = V_13 -> V_16 ;
else if ( F_16 ( V_2 ) )
V_15 = V_13 -> V_17 ;
if ( V_15 == V_2 || V_5 || V_2 -> V_18 )
return false ;
return true ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
F_5 ( V_2 , V_4 ) ;
if ( F_13 ( V_2 , * V_4 ) ) {
F_18 ( V_2 , V_19 ) ;
} else if ( F_15 ( V_2 ) ) {
struct V_20 * V_20 = F_19 ( V_2 ) ;
V_20 -> V_21 = 0 ;
F_20 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
} else if ( F_16 ( V_2 ) ) {
struct V_23 * V_23 = F_21 ( V_2 ) ;
F_20 ( V_23 -> V_22 ) ;
V_23 -> V_22 = NULL ;
V_23 -> V_24 = V_25 ;
}
}
T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , const char * V_26 ,
T_2 V_27 )
{
struct V_3 * V_5 ;
struct V_1 * V_28 ;
char * V_12 ;
if ( V_2 -> V_18 ) {
F_23 ( V_2 , L_2 , V_8 ) ;
return - V_29 ;
}
V_12 = F_24 ( V_26 , V_27 , V_30 ) ;
if ( ! V_12 )
return - V_31 ;
F_25 ( V_12 ) ;
if ( strncmp ( V_12 , L_3 , 9 ) == 0 || strcmp ( V_12 , L_4 ) == 0 )
;
else {
V_27 = - V_32 ;
goto V_33;
}
V_5 = * V_4 ;
if ( strcmp ( V_12 , L_4 ) == 0 ) {
F_17 ( V_2 , V_4 ) ;
goto V_33;
} else if ( V_5 ) {
F_23 ( V_2 , L_5 ,
F_12 ( & V_5 -> V_2 ) ) ;
V_27 = - V_29 ;
goto V_33;
}
V_28 = F_26 ( V_2 -> V_14 , V_12 , F_11 ) ;
if ( ! V_28 ) {
F_23 ( V_2 , L_6 , V_12 ,
F_12 ( V_2 -> V_14 ) ) ;
V_27 = - V_34 ;
goto V_33;
}
V_5 = F_27 ( V_28 ) ;
if ( F_28 ( V_5 ) < V_35 ) {
F_23 ( V_2 , L_7 , V_12 ) ;
V_27 = - V_36 ;
goto V_37;
}
F_29 ( ! F_30 ( V_2 ) ) ;
if ( ! F_10 ( V_2 , V_5 , V_4 ) ) {
F_23 ( V_2 , L_8 ,
F_12 ( & V_5 -> V_2 ) ) ;
V_27 = - V_29 ;
}
V_37:
F_4 ( & V_5 -> V_2 ) ;
V_33:
F_20 ( V_12 ) ;
return V_27 ;
}
T_3 F_31 ( struct V_38 * V_38 )
{
T_3 V_39 ;
T_4 V_40 ;
F_32 ( sizeof( struct V_41 ) != V_42 ) ;
F_32 ( sizeof( struct V_43 ) != V_42 ) ;
F_32 ( sizeof( struct V_38 ) != V_42 ) ;
V_40 = V_38 -> V_44 ;
V_38 -> V_44 = 0 ;
V_39 = F_33 ( V_38 , sizeof( * V_38 ) , 1 ) ;
V_38 -> V_44 = V_40 ;
return V_39 ;
}
