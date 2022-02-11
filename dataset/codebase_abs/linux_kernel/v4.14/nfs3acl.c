static T_1
F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
T_2 * V_13 ;
T_1 V_14 = 0 ;
V_13 = F_3 ( & V_8 -> V_13 , & V_5 -> V_13 ) ;
V_14 = F_4 ( V_2 , & V_8 -> V_13 , 0 , V_15 ) ;
if ( V_14 )
F_5 ( V_14 ) ;
V_12 = F_6 ( V_13 -> V_16 ) ;
if ( V_5 -> V_17 & ~ V_18 )
F_5 ( V_19 ) ;
V_8 -> V_17 = V_5 -> V_17 ;
if ( V_8 -> V_17 & ( V_20 | V_21 ) ) {
V_11 = F_7 ( V_12 , V_22 ) ;
if ( V_11 == NULL ) {
V_11 = F_8 ( V_12 -> V_23 , V_24 ) ;
}
if ( F_9 ( V_11 ) ) {
V_14 = F_10 ( F_11 ( V_11 ) ) ;
goto V_25;
}
V_8 -> V_26 = V_11 ;
}
if ( V_8 -> V_17 & ( V_27 | V_28 ) ) {
V_11 = F_7 ( V_12 , V_29 ) ;
if ( F_9 ( V_11 ) ) {
V_14 = F_10 ( F_11 ( V_11 ) ) ;
goto V_25;
}
V_8 -> V_30 = V_11 ;
}
F_5 ( 0 ) ;
V_25:
F_12 ( V_8 -> V_26 ) ;
F_12 ( V_8 -> V_30 ) ;
F_5 ( V_14 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_31 * V_5 = V_2 -> V_6 ;
struct V_32 * V_8 = V_2 -> V_9 ;
struct V_12 * V_12 ;
T_2 * V_13 ;
T_1 V_14 = 0 ;
int error ;
V_13 = F_3 ( & V_8 -> V_13 , & V_5 -> V_13 ) ;
V_14 = F_4 ( V_2 , & V_8 -> V_13 , 0 , V_33 ) ;
if ( V_14 )
goto V_34;
V_12 = F_6 ( V_13 -> V_16 ) ;
error = F_14 ( V_13 ) ;
if ( error )
goto V_35;
F_15 ( V_13 ) ;
error = F_16 ( V_12 , V_22 , V_5 -> V_26 ) ;
if ( error )
goto V_36;
error = F_16 ( V_12 , V_29 , V_5 -> V_30 ) ;
V_36:
F_17 ( V_13 ) ;
F_18 ( V_13 ) ;
V_35:
V_14 = F_10 ( error ) ;
V_34:
F_12 ( V_5 -> V_26 ) ;
F_12 ( V_5 -> V_30 ) ;
F_5 ( V_14 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_37 )
{
struct V_4 * args = V_2 -> V_6 ;
V_37 = F_20 ( V_37 , & args -> V_13 ) ;
if ( ! V_37 )
return 0 ;
args -> V_17 = F_21 ( * V_37 ) ; V_37 ++ ;
return F_22 ( V_2 , V_37 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 * V_37 )
{
struct V_31 * args = V_2 -> V_6 ;
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
unsigned int V_41 ;
int V_42 ;
V_37 = F_20 ( V_37 , & args -> V_13 ) ;
if ( ! V_37 )
return 0 ;
args -> V_17 = F_21 ( * V_37 ++ ) ;
if ( args -> V_17 & ~ V_18 ||
! F_22 ( V_2 , V_37 ) )
return 0 ;
V_41 = ( char * ) V_37 - ( char * ) V_39 -> V_43 ;
V_42 = F_24 ( & V_2 -> V_40 , V_41 , NULL ,
( args -> V_17 & V_20 ) ?
& args -> V_26 : NULL ) ;
if ( V_42 > 0 )
V_42 = F_24 ( & V_2 -> V_40 , V_41 + V_42 , NULL ,
( args -> V_17 & V_27 ) ?
& args -> V_30 : NULL ) ;
return ( V_42 > 0 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_37 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_44 * V_44 = V_8 -> V_13 . V_16 ;
V_37 = F_26 ( V_2 , V_37 , & V_8 -> V_13 ) ;
if ( V_8 -> V_45 == 0 && V_44 && F_27 ( V_44 ) ) {
struct V_12 * V_12 = F_6 ( V_44 ) ;
struct V_38 * V_39 = V_2 -> V_46 . V_39 ;
unsigned int V_41 ;
int V_42 ;
int V_47 ;
* V_37 ++ = F_28 ( V_8 -> V_17 ) ;
if ( ! F_29 ( V_2 , V_37 ) )
return 0 ;
V_41 = ( char * ) V_37 - ( char * ) V_39 -> V_43 ;
V_2 -> V_46 . V_48 = V_47 = F_30 (
( V_8 -> V_17 & V_20 ) ? V_8 -> V_26 : NULL ,
( V_8 -> V_17 & V_27 ) ? V_8 -> V_30 : NULL ) ;
while ( V_47 > 0 ) {
if ( ! * ( V_2 -> V_49 ++ ) )
return 0 ;
V_47 -= V_50 ;
}
V_42 = F_31 ( & V_2 -> V_46 , V_41 , V_12 ,
V_8 -> V_26 ,
V_8 -> V_17 & V_20 , 0 ) ;
if ( V_42 > 0 )
V_42 = F_31 ( & V_2 -> V_46 , V_41 + V_42 , V_12 ,
V_8 -> V_30 ,
V_8 -> V_17 & V_27 ,
V_51 ) ;
if ( V_42 <= 0 )
return 0 ;
} else
if ( ! F_29 ( V_2 , V_37 ) )
return 0 ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_37 )
{
struct V_32 * V_8 = V_2 -> V_9 ;
V_37 = F_26 ( V_2 , V_37 , & V_8 -> V_13 ) ;
return F_29 ( V_2 , V_37 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_34 ( & V_8 -> V_13 ) ;
F_12 ( V_8 -> V_26 ) ;
F_12 ( V_8 -> V_30 ) ;
}
