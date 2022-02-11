static T_1 F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
struct V_4 * V_5 ;
if ( ! F_2 ( V_3 ) ) {
F_3 ( 1 , L_1 , V_6 ) ;
return V_7 ;
}
F_4 () ;
V_5 = F_5 ( V_3 -> V_8 ) ;
if ( F_6 ( V_5 -> V_9 , F_7 ( V_3 ) -> V_10 ) ) {
F_8 ( V_3 ) ;
goto V_11;
}
if ( F_7 ( V_3 ) -> V_12 != F_9 ( V_13 ) )
goto V_14;
F_10 ( V_3 , V_15 ) ;
F_11 ( V_3 , V_5 ) ;
V_11:
F_12 () ;
return V_16 ;
V_14:
F_12 () ;
return V_7 ;
}
bool F_13 ( const struct V_17 * V_8 )
{
return F_14 ( V_8 -> V_18 ) == F_1 ;
}
static int F_15 ( struct V_17 * V_8 )
{
if ( ( V_8 -> V_19 & V_20 ) || ( V_8 -> type != V_21 ) ||
( V_8 -> V_22 != V_23 ) ) {
F_16 ( V_8 , L_2 ) ;
return - V_24 ;
}
if ( F_17 ( V_8 ) ) {
F_16 ( V_8 , L_3 ) ;
return - V_24 ;
}
if ( F_13 ( V_8 ) ) {
F_16 ( V_8 , L_4 ) ;
return - V_24 ;
}
if ( V_8 -> V_25 & V_26 ) {
F_16 ( V_8 , L_5 ) ;
return - V_24 ;
}
if ( V_8 -> V_25 & V_27 ) {
F_16 ( V_8 , L_6 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_8 , struct V_4 * V_5 )
{
int V_29 ;
F_19 ( V_8 ) ;
V_29 = F_20 ( V_8 , 1 ) ;
if ( V_29 )
goto V_30;
V_29 = F_21 ( V_8 , F_1 , V_5 ) ;
if ( V_29 )
goto V_31;
F_22 ( V_8 ) ;
return 0 ;
V_31:
F_20 ( V_8 , - 1 ) ;
V_30:
F_23 ( V_8 ) ;
return V_29 ;
}
int F_24 ( struct V_32 * V_9 , struct V_17 * V_8 ,
enum V_33 type )
{
struct V_4 * V_5 , * V_34 ;
int V_29 ;
if ( type != V_35 ) {
V_29 = F_15 ( V_8 ) ;
if ( V_29 )
return V_29 ;
}
V_5 = F_25 ( V_9 , type ) ;
if ( V_5 != NULL )
return - V_36 ;
V_5 = F_26 ( sizeof( * V_5 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
if ( type != V_35 ) {
V_29 = F_18 ( V_8 , V_5 ) ;
if ( V_29 )
goto V_39;
}
V_5 -> V_9 = V_9 ;
V_5 -> V_8 = V_8 ;
V_5 -> type = type ;
F_27 ( & V_5 -> V_40 , & V_9 -> V_41 ) ;
F_28 () ;
V_34 = F_25 ( V_9 , V_35 ) ;
F_29 ( V_34 -> V_8 ) ;
F_30 ( V_34 -> V_8 , F_31 ( V_9 ) ) ;
return 0 ;
V_39:
F_32 ( V_5 ) ;
return V_29 ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_32 * V_9 ;
struct V_4 * V_34 ;
V_9 = V_5 -> V_9 ;
V_34 = F_25 ( V_9 , V_35 ) ;
F_34 ( & V_5 -> V_40 ) ;
if ( V_5 != V_34 ) {
F_29 ( V_34 -> V_8 ) ;
F_30 ( V_34 -> V_8 , F_31 ( V_9 ) ) ;
F_35 ( V_5 -> V_8 ) ;
F_20 ( V_5 -> V_8 , - 1 ) ;
}
F_28 () ;
F_23 ( V_5 -> V_8 ) ;
}
