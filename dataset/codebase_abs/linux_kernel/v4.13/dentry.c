static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_9 V_10 ;
struct V_6 * V_11 = NULL ;
int error ;
int V_12 = 0 ;
if ( V_2 & V_13 )
return - V_14 ;
V_3 = F_2 ( V_1 ) ;
V_5 = F_3 ( F_4 ( V_3 ) ) ;
V_7 = F_5 ( F_4 ( V_3 ) ) ;
V_8 = F_4 ( V_1 ) ;
if ( V_8 ) {
if ( F_6 ( V_8 ) )
goto V_15;
V_11 = F_5 ( V_8 ) ;
}
if ( V_5 -> V_16 . V_17 -> V_18 == NULL )
goto V_19;
V_12 = ( F_7 ( V_7 -> V_20 ) != NULL ) ;
if ( ! V_12 ) {
error = F_8 ( V_7 -> V_20 , V_21 , 0 , & V_10 ) ;
if ( error )
goto V_22;
}
error = F_9 ( F_4 ( V_3 ) , & V_1 -> V_23 , V_11 ) ;
switch ( error ) {
case 0 :
if ( ! V_8 )
goto V_24;
break;
case - V_25 :
if ( ! V_8 )
goto V_26;
goto V_24;
default:
goto V_27;
}
V_26:
if ( ! V_12 )
F_10 ( & V_10 ) ;
V_19:
F_11 ( V_3 ) ;
return 1 ;
V_24:
if ( ! V_12 )
F_10 ( & V_10 ) ;
V_15:
F_11 ( V_3 ) ;
return 0 ;
V_27:
F_10 ( & V_10 ) ;
V_22:
F_11 ( V_3 ) ;
return 0 ;
}
static int F_12 ( const struct V_1 * V_1 , struct V_28 * V_29 )
{
V_29 -> V_30 = F_13 ( V_29 -> V_31 , V_29 -> V_32 ) ;
return 0 ;
}
static int F_14 ( const struct V_1 * V_1 )
{
struct V_6 * V_33 ;
if ( F_15 ( V_1 ) )
return 0 ;
V_33 = F_5 ( F_4 ( V_1 ) ) ;
if ( ! F_16 ( & V_33 -> V_34 ) )
return 0 ;
if ( F_17 ( V_35 , & V_33 -> V_34 . V_36 -> V_37 ) )
return 1 ;
return 0 ;
}
