static T_1
F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return V_5 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_6 * V_3 , struct V_7 * V_4 )
{
struct V_8 * V_9 ;
struct V_10 * V_10 ;
T_2 * V_11 ;
T_1 V_12 = 0 ;
V_11 = F_3 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_4 ( V_2 , & V_4 -> V_11 , 0 , V_13 ) ;
if ( V_12 )
F_5 ( V_12 ) ;
V_10 = V_11 -> V_14 -> V_15 ;
if ( V_3 -> V_16 & ~ ( V_17 | V_18 | V_19 | V_20 ) )
F_5 ( V_21 ) ;
V_4 -> V_16 = V_3 -> V_16 ;
if ( V_4 -> V_16 & ( V_17 | V_18 ) ) {
V_9 = F_6 ( V_10 , V_22 ) ;
if ( V_9 == NULL ) {
V_9 = F_7 ( V_10 -> V_23 , V_24 ) ;
}
if ( F_8 ( V_9 ) ) {
V_12 = F_9 ( F_10 ( V_9 ) ) ;
goto V_25;
}
V_4 -> V_26 = V_9 ;
}
if ( V_4 -> V_16 & ( V_19 | V_20 ) ) {
V_9 = F_6 ( V_10 , V_27 ) ;
if ( F_8 ( V_9 ) ) {
V_12 = F_9 ( F_10 ( V_9 ) ) ;
goto V_25;
}
V_4 -> V_28 = V_9 ;
}
F_5 ( 0 ) ;
V_25:
F_11 ( V_4 -> V_26 ) ;
F_11 ( V_4 -> V_28 ) ;
F_5 ( V_12 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_29 * V_3 ,
struct V_30 * V_4 )
{
struct V_10 * V_10 ;
T_2 * V_11 ;
T_1 V_12 = 0 ;
int error ;
V_11 = F_3 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_4 ( V_2 , & V_4 -> V_11 , 0 , V_31 ) ;
if ( V_12 )
goto V_32;
V_10 = V_11 -> V_14 -> V_15 ;
if ( ! F_13 ( V_10 ) || ! V_10 -> V_33 -> V_34 ) {
error = - V_35 ;
goto V_36;
}
error = F_14 ( V_11 ) ;
if ( error )
goto V_36;
error = V_10 -> V_33 -> V_34 ( V_10 , V_3 -> V_26 , V_22 ) ;
if ( error )
goto V_37;
error = V_10 -> V_33 -> V_34 ( V_10 , V_3 -> V_28 ,
V_27 ) ;
V_37:
F_15 ( V_11 ) ;
V_36:
V_12 = F_9 ( error ) ;
V_32:
F_11 ( V_3 -> V_26 ) ;
F_11 ( V_3 -> V_28 ) ;
F_5 ( V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_38 ,
struct V_6 * args )
{
V_38 = F_17 ( V_38 , & args -> V_11 ) ;
if ( ! V_38 )
return 0 ;
args -> V_16 = F_18 ( * V_38 ) ; V_38 ++ ;
return F_19 ( V_2 , V_38 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 * V_38 ,
struct V_29 * args )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
unsigned int V_42 ;
int V_43 ;
V_38 = F_17 ( V_38 , & args -> V_11 ) ;
if ( ! V_38 )
return 0 ;
args -> V_16 = F_18 ( * V_38 ++ ) ;
if ( args -> V_16 & ~ ( V_17 | V_18 | V_19 | V_20 ) ||
! F_19 ( V_2 , V_38 ) )
return 0 ;
V_42 = ( char * ) V_38 - ( char * ) V_40 -> V_44 ;
V_43 = F_21 ( & V_2 -> V_41 , V_42 , NULL ,
( args -> V_16 & V_17 ) ?
& args -> V_26 : NULL ) ;
if ( V_43 > 0 )
V_43 = F_21 ( & V_2 -> V_41 , V_42 + V_43 , NULL ,
( args -> V_16 & V_19 ) ?
& args -> V_28 : NULL ) ;
return ( V_43 > 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_38 ,
struct V_7 * V_4 )
{
struct V_45 * V_45 = V_4 -> V_11 . V_14 ;
V_38 = F_23 ( V_2 , V_38 , & V_4 -> V_11 ) ;
if ( V_4 -> V_46 == 0 && V_45 && V_45 -> V_15 ) {
struct V_10 * V_10 = V_45 -> V_15 ;
struct V_39 * V_40 = V_2 -> V_47 . V_40 ;
unsigned int V_42 ;
int V_43 ;
int V_48 ;
* V_38 ++ = F_24 ( V_4 -> V_16 ) ;
if ( ! F_25 ( V_2 , V_38 ) )
return 0 ;
V_42 = ( char * ) V_38 - ( char * ) V_40 -> V_44 ;
V_2 -> V_47 . V_49 = V_48 = F_26 (
( V_4 -> V_16 & V_17 ) ? V_4 -> V_26 : NULL ,
( V_4 -> V_16 & V_19 ) ? V_4 -> V_28 : NULL ) ;
while ( V_48 > 0 ) {
if ( ! * ( V_2 -> V_50 ++ ) )
return 0 ;
V_48 -= V_51 ;
}
V_43 = F_27 ( & V_2 -> V_47 , V_42 , V_10 ,
V_4 -> V_26 ,
V_4 -> V_16 & V_17 , 0 ) ;
if ( V_43 > 0 )
V_43 = F_27 ( & V_2 -> V_47 , V_42 + V_43 , V_10 ,
V_4 -> V_28 ,
V_4 -> V_16 & V_19 ,
V_52 ) ;
if ( V_43 <= 0 )
return 0 ;
} else
if ( ! F_25 ( V_2 , V_38 ) )
return 0 ;
return 1 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_38 ,
struct V_30 * V_4 )
{
V_38 = F_23 ( V_2 , V_38 , & V_4 -> V_11 ) ;
return F_25 ( V_2 , V_38 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_38 ,
struct V_7 * V_4 )
{
F_30 ( & V_4 -> V_11 ) ;
F_11 ( V_4 -> V_26 ) ;
F_11 ( V_4 -> V_28 ) ;
return 1 ;
}
