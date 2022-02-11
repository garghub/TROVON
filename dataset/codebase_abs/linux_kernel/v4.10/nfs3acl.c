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
if ( V_3 -> V_15 & ~ V_16 )
F_5 ( V_17 ) ;
V_4 -> V_15 = V_3 -> V_15 ;
if ( V_4 -> V_15 & ( V_18 | V_19 ) ) {
V_9 = F_7 ( V_10 , V_20 ) ;
if ( V_9 == NULL ) {
V_9 = F_8 ( V_10 -> V_21 , V_22 ) ;
}
if ( F_9 ( V_9 ) ) {
V_12 = F_10 ( F_11 ( V_9 ) ) ;
goto V_23;
}
V_4 -> V_24 = V_9 ;
}
if ( V_4 -> V_15 & ( V_25 | V_26 ) ) {
V_9 = F_7 ( V_10 , V_27 ) ;
if ( F_9 ( V_9 ) ) {
V_12 = F_10 ( F_11 ( V_9 ) ) ;
goto V_23;
}
V_4 -> V_28 = V_9 ;
}
F_5 ( 0 ) ;
V_23:
F_12 ( V_4 -> V_24 ) ;
F_12 ( V_4 -> V_28 ) ;
F_5 ( V_12 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
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
V_10 = F_6 ( V_11 -> V_14 ) ;
error = F_14 ( V_11 ) ;
if ( error )
goto V_33;
F_15 ( V_11 ) ;
error = F_16 ( V_10 , V_20 , V_3 -> V_24 ) ;
if ( error )
goto V_34;
error = F_16 ( V_10 , V_27 , V_3 -> V_28 ) ;
V_34:
F_17 ( V_11 ) ;
F_18 ( V_11 ) ;
V_33:
V_12 = F_10 ( error ) ;
V_32:
F_12 ( V_3 -> V_24 ) ;
F_12 ( V_3 -> V_28 ) ;
F_5 ( V_12 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_6 * args )
{
V_35 = F_20 ( V_35 , & args -> V_11 ) ;
if ( ! V_35 )
return 0 ;
args -> V_15 = F_21 ( * V_35 ) ; V_35 ++ ;
return F_22 ( V_2 , V_35 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_29 * args )
{
struct V_36 * V_37 = V_2 -> V_38 . V_37 ;
unsigned int V_39 ;
int V_40 ;
V_35 = F_20 ( V_35 , & args -> V_11 ) ;
if ( ! V_35 )
return 0 ;
args -> V_15 = F_21 ( * V_35 ++ ) ;
if ( args -> V_15 & ~ V_16 ||
! F_22 ( V_2 , V_35 ) )
return 0 ;
V_39 = ( char * ) V_35 - ( char * ) V_37 -> V_41 ;
V_40 = F_24 ( & V_2 -> V_38 , V_39 , NULL ,
( args -> V_15 & V_18 ) ?
& args -> V_24 : NULL ) ;
if ( V_40 > 0 )
V_40 = F_24 ( & V_2 -> V_38 , V_39 + V_40 , NULL ,
( args -> V_15 & V_25 ) ?
& args -> V_28 : NULL ) ;
return ( V_40 > 0 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_7 * V_4 )
{
struct V_42 * V_42 = V_4 -> V_11 . V_14 ;
V_35 = F_26 ( V_2 , V_35 , & V_4 -> V_11 ) ;
if ( V_4 -> V_43 == 0 && V_42 && F_27 ( V_42 ) ) {
struct V_10 * V_10 = F_6 ( V_42 ) ;
struct V_36 * V_37 = V_2 -> V_44 . V_37 ;
unsigned int V_39 ;
int V_40 ;
int V_45 ;
* V_35 ++ = F_28 ( V_4 -> V_15 ) ;
if ( ! F_29 ( V_2 , V_35 ) )
return 0 ;
V_39 = ( char * ) V_35 - ( char * ) V_37 -> V_41 ;
V_2 -> V_44 . V_46 = V_45 = F_30 (
( V_4 -> V_15 & V_18 ) ? V_4 -> V_24 : NULL ,
( V_4 -> V_15 & V_25 ) ? V_4 -> V_28 : NULL ) ;
while ( V_45 > 0 ) {
if ( ! * ( V_2 -> V_47 ++ ) )
return 0 ;
V_45 -= V_48 ;
}
V_40 = F_31 ( & V_2 -> V_44 , V_39 , V_10 ,
V_4 -> V_24 ,
V_4 -> V_15 & V_18 , 0 ) ;
if ( V_40 > 0 )
V_40 = F_31 ( & V_2 -> V_44 , V_39 + V_40 , V_10 ,
V_4 -> V_28 ,
V_4 -> V_15 & V_25 ,
V_49 ) ;
if ( V_40 <= 0 )
return 0 ;
} else
if ( ! F_29 ( V_2 , V_35 ) )
return 0 ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_30 * V_4 )
{
V_35 = F_26 ( V_2 , V_35 , & V_4 -> V_11 ) ;
return F_29 ( V_2 , V_35 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_7 * V_4 )
{
F_34 ( & V_4 -> V_11 ) ;
F_12 ( V_4 -> V_24 ) ;
F_12 ( V_4 -> V_28 ) ;
return 1 ;
}
