static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( V_2 -> V_4 == NULL ) {
V_2 -> V_4 = F_2 ( V_3 ) ;
if ( V_2 -> V_4 == NULL )
return - V_5 ;
F_3 ( V_3 ) ;
F_4 ( & V_2 -> V_4 -> V_6 -> V_7 ) ;
F_4 ( & V_2 -> V_4 -> V_8 ) ;
F_5 ( & V_2 -> V_4 -> V_9 ) ;
F_6 ( & V_2 -> V_4 -> V_8 ) ;
F_6 ( & V_2 -> V_4 -> V_6 -> V_7 ) ;
}
return 0 ;
}
struct V_10 * F_7 ( struct V_1 * V_2 , struct V_11 * V_12 ,
const char * V_13 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
struct V_16 V_17 ;
struct V_10 * V_18 ;
struct V_3 * V_3 ;
void * V_19 = F_9 ( V_13 , V_20 ) ;
int error ;
if ( ! V_19 )
return F_10 ( - V_5 ) ;
V_17 . V_21 = F_11 () ;
if ( V_17 . V_21 == NULL ) {
F_12 ( V_19 ) ;
return F_10 ( - V_5 ) ;
}
error = V_15 -> V_22 -> V_23 -> V_24 ( V_15 , V_12 , & V_17 ) ;
if ( error < 0 ) {
F_13 ( L_1 , - error ) ;
V_18 = F_10 ( error ) ;
goto V_25;
}
V_3 = F_14 ( V_2 , V_12 , V_17 . V_21 ) ;
if ( F_15 ( V_3 ) ) {
F_13 ( L_2 ) ;
V_18 = F_16 ( V_3 ) ;
goto V_25;
}
error = F_1 ( V_2 , V_3 ) ;
if ( error != 0 ) {
V_18 = F_10 ( error ) ;
goto V_25;
}
V_18 = F_17 ( V_3 ) ;
if ( F_15 ( V_18 ) ) {
F_13 ( L_3 ) ;
goto V_25;
}
F_18 ( V_18 , V_3 ) ;
F_4 ( & V_18 -> V_8 ) ;
if ( F_19 ( V_18 ) && ! ( V_18 -> V_26 & V_27 ) ) {
V_18 -> V_28 = V_19 ;
V_19 = NULL ;
}
F_6 ( & V_18 -> V_8 ) ;
V_25:
F_12 ( V_19 ) ;
F_20 ( V_17 . V_21 ) ;
return V_18 ;
}
