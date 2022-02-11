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
V_10 = F_6 ( V_11 -> V_14 ) ;
if ( V_3 -> V_15 & ~ ( V_16 | V_17 | V_18 | V_19 ) )
F_5 ( V_20 ) ;
V_4 -> V_15 = V_3 -> V_15 ;
if ( V_4 -> V_15 & ( V_16 | V_17 ) ) {
V_9 = F_7 ( V_10 , V_21 ) ;
if ( V_9 == NULL ) {
V_9 = F_8 ( V_10 -> V_22 , V_23 ) ;
}
if ( F_9 ( V_9 ) ) {
V_12 = F_10 ( F_11 ( V_9 ) ) ;
goto V_24;
}
V_4 -> V_25 = V_9 ;
}
if ( V_4 -> V_15 & ( V_18 | V_19 ) ) {
V_9 = F_7 ( V_10 , V_26 ) ;
if ( F_9 ( V_9 ) ) {
V_12 = F_10 ( F_11 ( V_9 ) ) ;
goto V_24;
}
V_4 -> V_27 = V_9 ;
}
F_5 ( 0 ) ;
V_24:
F_12 ( V_4 -> V_25 ) ;
F_12 ( V_4 -> V_27 ) ;
F_5 ( V_12 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_28 * V_3 ,
struct V_29 * V_4 )
{
struct V_10 * V_10 ;
T_2 * V_11 ;
T_1 V_12 = 0 ;
int error ;
V_11 = F_3 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_4 ( V_2 , & V_4 -> V_11 , 0 , V_30 ) ;
if ( V_12 )
goto V_31;
V_10 = F_6 ( V_11 -> V_14 ) ;
if ( ! F_14 ( V_10 ) || ! V_10 -> V_32 -> V_33 ) {
error = - V_34 ;
goto V_35;
}
error = F_15 ( V_11 ) ;
if ( error )
goto V_35;
error = V_10 -> V_32 -> V_33 ( V_10 , V_3 -> V_25 , V_21 ) ;
if ( error )
goto V_36;
error = V_10 -> V_32 -> V_33 ( V_10 , V_3 -> V_27 ,
V_26 ) ;
V_36:
F_16 ( V_11 ) ;
V_35:
V_12 = F_10 ( error ) ;
V_31:
F_12 ( V_3 -> V_25 ) ;
F_12 ( V_3 -> V_27 ) ;
F_5 ( V_12 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 * V_37 ,
struct V_6 * args )
{
V_37 = F_18 ( V_37 , & args -> V_11 ) ;
if ( ! V_37 )
return 0 ;
args -> V_15 = F_19 ( * V_37 ) ; V_37 ++ ;
return F_20 ( V_2 , V_37 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_37 ,
struct V_28 * args )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
unsigned int V_41 ;
int V_42 ;
V_37 = F_18 ( V_37 , & args -> V_11 ) ;
if ( ! V_37 )
return 0 ;
args -> V_15 = F_19 ( * V_37 ++ ) ;
if ( args -> V_15 & ~ ( V_16 | V_17 | V_18 | V_19 ) ||
! F_20 ( V_2 , V_37 ) )
return 0 ;
V_41 = ( char * ) V_37 - ( char * ) V_39 -> V_43 ;
V_42 = F_22 ( & V_2 -> V_40 , V_41 , NULL ,
( args -> V_15 & V_16 ) ?
& args -> V_25 : NULL ) ;
if ( V_42 > 0 )
V_42 = F_22 ( & V_2 -> V_40 , V_41 + V_42 , NULL ,
( args -> V_15 & V_18 ) ?
& args -> V_27 : NULL ) ;
return ( V_42 > 0 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 * V_37 ,
struct V_7 * V_4 )
{
struct V_44 * V_44 = V_4 -> V_11 . V_14 ;
V_37 = F_24 ( V_2 , V_37 , & V_4 -> V_11 ) ;
if ( V_4 -> V_45 == 0 && V_44 && F_25 ( V_44 ) ) {
struct V_10 * V_10 = F_6 ( V_44 ) ;
struct V_38 * V_39 = V_2 -> V_46 . V_39 ;
unsigned int V_41 ;
int V_42 ;
int V_47 ;
* V_37 ++ = F_26 ( V_4 -> V_15 ) ;
if ( ! F_27 ( V_2 , V_37 ) )
return 0 ;
V_41 = ( char * ) V_37 - ( char * ) V_39 -> V_43 ;
V_2 -> V_46 . V_48 = V_47 = F_28 (
( V_4 -> V_15 & V_16 ) ? V_4 -> V_25 : NULL ,
( V_4 -> V_15 & V_18 ) ? V_4 -> V_27 : NULL ) ;
while ( V_47 > 0 ) {
if ( ! * ( V_2 -> V_49 ++ ) )
return 0 ;
V_47 -= V_50 ;
}
V_42 = F_29 ( & V_2 -> V_46 , V_41 , V_10 ,
V_4 -> V_25 ,
V_4 -> V_15 & V_16 , 0 ) ;
if ( V_42 > 0 )
V_42 = F_29 ( & V_2 -> V_46 , V_41 + V_42 , V_10 ,
V_4 -> V_27 ,
V_4 -> V_15 & V_18 ,
V_51 ) ;
if ( V_42 <= 0 )
return 0 ;
} else
if ( ! F_27 ( V_2 , V_37 ) )
return 0 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_37 ,
struct V_29 * V_4 )
{
V_37 = F_24 ( V_2 , V_37 , & V_4 -> V_11 ) ;
return F_27 ( V_2 , V_37 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_37 ,
struct V_7 * V_4 )
{
F_32 ( & V_4 -> V_11 ) ;
F_12 ( V_4 -> V_25 ) ;
F_12 ( V_4 -> V_27 ) ;
return 1 ;
}
