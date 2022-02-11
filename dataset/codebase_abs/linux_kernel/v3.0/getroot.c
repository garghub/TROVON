static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( V_2 -> V_4 == NULL ) {
V_2 -> V_4 = F_2 ( V_3 ) ;
if ( V_2 -> V_4 == NULL ) {
F_3 ( V_3 ) ;
return - V_5 ;
}
F_4 ( V_3 ) ;
F_5 ( & V_2 -> V_4 -> V_6 -> V_7 ) ;
F_5 ( & V_2 -> V_4 -> V_8 ) ;
F_6 ( & V_2 -> V_4 -> V_9 ) ;
F_7 ( & V_2 -> V_4 -> V_8 ) ;
F_7 ( & V_2 -> V_4 -> V_6 -> V_7 ) ;
}
return 0 ;
}
struct V_10 * F_8 ( struct V_1 * V_2 , struct V_11 * V_12 ,
const char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_16 V_17 ;
struct V_10 * V_18 ;
struct V_3 * V_3 ;
void * V_19 = F_10 ( V_13 , V_20 ) ;
int error ;
if ( ! V_19 )
return F_11 ( - V_5 ) ;
V_17 . V_21 = F_12 () ;
if ( V_17 . V_21 == NULL ) {
F_13 ( V_19 ) ;
return F_11 ( - V_5 ) ;
}
error = V_15 -> V_22 -> V_23 -> V_24 ( V_15 , V_12 , & V_17 ) ;
if ( error < 0 ) {
F_14 ( L_1 , - error ) ;
V_18 = F_11 ( error ) ;
goto V_25;
}
V_3 = F_15 ( V_2 , V_12 , V_17 . V_21 ) ;
if ( F_16 ( V_3 ) ) {
F_14 ( L_2 ) ;
V_18 = F_17 ( V_3 ) ;
goto V_25;
}
error = F_1 ( V_2 , V_3 ) ;
if ( error != 0 ) {
V_18 = F_11 ( error ) ;
goto V_25;
}
V_18 = F_18 ( V_3 ) ;
if ( F_16 ( V_18 ) ) {
F_14 ( L_3 ) ;
goto V_25;
}
F_19 ( V_18 , V_3 ) ;
F_5 ( & V_18 -> V_8 ) ;
if ( F_20 ( V_18 ) && ! ( V_18 -> V_26 & V_27 ) ) {
V_18 -> V_28 = V_19 ;
V_19 = NULL ;
}
F_7 ( & V_18 -> V_8 ) ;
V_25:
if ( V_19 )
F_13 ( V_19 ) ;
F_21 ( V_17 . V_21 ) ;
return V_18 ;
}
int F_22 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
struct V_16 V_17 ;
int V_18 = - V_5 ;
F_14 ( L_4 ) ;
V_17 . V_21 = F_12 () ;
if ( V_17 . V_21 == NULL )
goto V_25;
V_18 = V_15 -> V_22 -> V_23 -> V_24 ( V_15 , V_12 , & V_17 ) ;
if ( V_18 < 0 ) {
F_14 ( L_5 , - V_18 ) ;
goto V_25;
}
if ( ! ( V_17 . V_21 -> V_29 & V_30 )
|| ! F_23 ( V_17 . V_21 -> V_31 ) ) {
F_24 ( V_32 L_6
L_7 ) ;
V_18 = - V_33 ;
goto V_25;
}
if ( V_17 . V_21 -> V_29 & V_34 ) {
F_24 ( V_32 L_6
L_8 ) ;
V_18 = - V_35 ;
goto V_25;
}
memcpy ( & V_15 -> V_36 , & V_17 . V_21 -> V_36 , sizeof( V_15 -> V_36 ) ) ;
V_25:
F_21 ( V_17 . V_21 ) ;
F_14 ( L_9 , V_18 ) ;
return V_18 ;
}
struct V_10 * F_25 ( struct V_1 * V_2 , struct V_11 * V_12 ,
const char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_37 * V_21 = NULL ;
struct V_10 * V_18 ;
struct V_3 * V_3 ;
void * V_19 = F_10 ( V_13 , V_20 ) ;
int error ;
F_14 ( L_10 ) ;
if ( ! V_19 )
return F_11 ( - V_5 ) ;
error = F_26 ( V_15 , V_12 ) ;
if ( error < 0 ) {
F_14 ( L_11 ,
- error ) ;
F_13 ( V_19 ) ;
return F_11 ( error ) ;
}
V_21 = F_12 () ;
if ( V_21 == NULL ) {
F_13 ( V_19 ) ;
return F_11 ( - V_5 ) ;
}
error = V_15 -> V_22 -> V_23 -> V_38 ( V_15 , V_12 , V_21 ) ;
if ( error < 0 ) {
F_14 ( L_1 , - error ) ;
V_18 = F_11 ( error ) ;
goto V_25;
}
if ( V_21 -> V_29 & V_39 &&
! F_27 ( & V_15 -> V_36 , & V_21 -> V_36 ) )
memcpy ( & V_15 -> V_36 , & V_21 -> V_36 , sizeof( V_15 -> V_36 ) ) ;
V_3 = F_15 ( V_2 , V_12 , V_21 ) ;
if ( F_16 ( V_3 ) ) {
F_14 ( L_2 ) ;
V_18 = F_17 ( V_3 ) ;
goto V_25;
}
error = F_1 ( V_2 , V_3 ) ;
if ( error != 0 ) {
V_18 = F_11 ( error ) ;
goto V_25;
}
V_18 = F_18 ( V_3 ) ;
if ( F_16 ( V_18 ) ) {
F_14 ( L_3 ) ;
goto V_25;
}
F_19 ( V_18 , V_3 ) ;
F_5 ( & V_18 -> V_8 ) ;
if ( F_20 ( V_18 ) && ! ( V_18 -> V_26 & V_27 ) ) {
V_18 -> V_28 = V_19 ;
V_19 = NULL ;
}
F_7 ( & V_18 -> V_8 ) ;
V_25:
if ( V_19 )
F_13 ( V_19 ) ;
F_21 ( V_21 ) ;
F_14 ( L_12 ) ;
return V_18 ;
}
