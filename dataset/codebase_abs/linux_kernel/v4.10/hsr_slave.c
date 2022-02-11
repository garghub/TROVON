static T_1 F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! F_2 ( V_3 ) ) {
F_3 ( 1 , L_1 , V_7 ) ;
return V_8 ;
}
F_4 () ;
V_5 = F_5 ( V_3 -> V_9 ) ;
if ( F_6 ( V_5 -> V_10 , F_7 ( V_3 ) -> V_11 ) ) {
F_8 ( V_3 ) ;
goto V_12;
}
V_6 = F_7 ( V_3 ) -> V_13 ;
if ( V_6 != F_9 ( V_14 ) && V_6 != F_9 ( V_15 ) )
goto V_16;
F_10 ( V_3 , V_17 ) ;
F_11 ( V_3 , V_5 ) ;
V_12:
F_12 () ;
return V_18 ;
V_16:
F_12 () ;
return V_8 ;
}
bool F_13 ( const struct V_19 * V_9 )
{
return F_14 ( V_9 -> V_20 ) == F_1 ;
}
static int F_15 ( struct V_19 * V_9 )
{
if ( ( V_9 -> V_21 & V_22 ) || ( V_9 -> type != V_23 ) ||
( V_9 -> V_24 != V_25 ) ) {
F_16 ( V_9 , L_2 ) ;
return - V_26 ;
}
if ( F_17 ( V_9 ) ) {
F_16 ( V_9 , L_3 ) ;
return - V_26 ;
}
if ( F_13 ( V_9 ) ) {
F_16 ( V_9 , L_4 ) ;
return - V_26 ;
}
if ( V_9 -> V_27 & V_28 ) {
F_16 ( V_9 , L_5 ) ;
return - V_26 ;
}
if ( V_9 -> V_27 & V_29 ) {
F_16 ( V_9 , L_6 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_19 * V_9 , struct V_4 * V_5 )
{
int V_31 ;
F_19 ( V_9 ) ;
V_31 = F_20 ( V_9 , 1 ) ;
if ( V_31 )
goto V_32;
V_31 = F_21 ( V_9 , F_1 , V_5 ) ;
if ( V_31 )
goto V_33;
F_22 ( V_9 ) ;
return 0 ;
V_33:
F_20 ( V_9 , - 1 ) ;
V_32:
F_23 ( V_9 ) ;
return V_31 ;
}
int F_24 ( struct V_34 * V_10 , struct V_19 * V_9 ,
enum V_35 type )
{
struct V_4 * V_5 , * V_36 ;
int V_31 ;
if ( type != V_37 ) {
V_31 = F_15 ( V_9 ) ;
if ( V_31 )
return V_31 ;
}
V_5 = F_25 ( V_10 , type ) ;
if ( V_5 != NULL )
return - V_38 ;
V_5 = F_26 ( sizeof( * V_5 ) , V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
if ( type != V_37 ) {
V_31 = F_18 ( V_9 , V_5 ) ;
if ( V_31 )
goto V_41;
}
V_5 -> V_10 = V_10 ;
V_5 -> V_9 = V_9 ;
V_5 -> type = type ;
F_27 ( & V_5 -> V_42 , & V_10 -> V_43 ) ;
F_28 () ;
V_36 = F_25 ( V_10 , V_37 ) ;
F_29 ( V_36 -> V_9 ) ;
F_30 ( V_36 -> V_9 , F_31 ( V_10 ) ) ;
return 0 ;
V_41:
F_32 ( V_5 ) ;
return V_31 ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_34 * V_10 ;
struct V_4 * V_36 ;
V_10 = V_5 -> V_10 ;
V_36 = F_25 ( V_10 , V_37 ) ;
F_34 ( & V_5 -> V_42 ) ;
if ( V_5 != V_36 ) {
if ( V_36 != NULL ) {
F_29 ( V_36 -> V_9 ) ;
F_30 ( V_36 -> V_9 , F_31 ( V_10 ) ) ;
}
F_35 ( V_5 -> V_9 ) ;
F_20 ( V_5 -> V_9 , - 1 ) ;
}
F_28 () ;
if ( V_5 != V_36 )
F_23 ( V_5 -> V_9 ) ;
}
