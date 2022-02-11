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
F_3 ( L_1 , F_4 ( & V_3 -> V_11 ) ) ;
V_11 = F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_6 ( V_2 , & V_4 -> V_11 , 0 , V_13 ) ;
if ( V_12 )
F_7 ( V_12 ) ;
V_10 = F_8 ( V_11 -> V_14 ) ;
if ( V_3 -> V_15 & ~ ( V_16 | V_17 | V_18 | V_19 ) )
F_7 ( V_20 ) ;
V_4 -> V_15 = V_3 -> V_15 ;
V_12 = F_9 ( V_11 , & V_4 -> V_21 ) ;
if ( V_12 )
goto V_22;
if ( V_4 -> V_15 & ( V_16 | V_17 ) ) {
V_9 = F_10 ( V_10 , V_23 ) ;
if ( V_9 == NULL ) {
V_9 = F_11 ( V_10 -> V_24 , V_25 ) ;
}
if ( F_12 ( V_9 ) ) {
V_12 = F_13 ( F_14 ( V_9 ) ) ;
goto V_22;
}
V_4 -> V_26 = V_9 ;
}
if ( V_4 -> V_15 & ( V_18 | V_19 ) ) {
V_9 = F_10 ( V_10 , V_27 ) ;
if ( F_12 ( V_9 ) ) {
V_12 = F_13 ( F_14 ( V_9 ) ) ;
goto V_22;
}
V_4 -> V_28 = V_9 ;
}
F_7 ( 0 ) ;
V_22:
F_15 ( V_4 -> V_26 ) ;
F_15 ( V_4 -> V_28 ) ;
F_7 ( V_12 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_29 * V_3 ,
struct V_30 * V_4 )
{
struct V_10 * V_10 ;
T_2 * V_11 ;
T_1 V_12 = 0 ;
int error ;
F_3 ( L_2 , F_4 ( & V_3 -> V_11 ) ) ;
V_11 = F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_6 ( V_2 , & V_4 -> V_11 , 0 , V_31 ) ;
if ( V_12 )
goto V_32;
V_10 = F_8 ( V_11 -> V_14 ) ;
if ( ! F_17 ( V_10 ) || ! V_10 -> V_33 -> V_34 ) {
error = - V_35 ;
goto V_36;
}
error = F_18 ( V_11 ) ;
if ( error )
goto V_36;
error = V_10 -> V_33 -> V_34 ( V_10 , V_3 -> V_26 , V_23 ) ;
if ( error )
goto V_37;
error = V_10 -> V_33 -> V_34 ( V_10 , V_3 -> V_28 ,
V_27 ) ;
if ( error )
goto V_37;
F_19 ( V_11 ) ;
V_12 = F_9 ( V_11 , & V_4 -> V_21 ) ;
V_32:
F_15 ( V_3 -> V_26 ) ;
F_15 ( V_3 -> V_28 ) ;
return V_12 ;
V_37:
F_19 ( V_11 ) ;
V_36:
V_12 = F_13 ( error ) ;
goto V_32;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_38 * V_3 , struct V_30 * V_4 )
{
T_1 V_12 ;
F_3 ( L_3 , F_4 ( & V_3 -> V_11 ) ) ;
F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_6 ( V_2 , & V_4 -> V_11 , 0 , V_13 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( & V_4 -> V_11 , & V_4 -> V_21 ) ;
return V_12 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_39 * V_3 ,
struct V_40 * V_4 )
{
T_1 V_12 ;
F_3 ( L_4 ,
F_4 ( & V_3 -> V_11 ) ,
V_3 -> V_41 ) ;
F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_4 -> V_41 = V_3 -> V_41 ;
V_12 = F_22 ( V_2 , & V_4 -> V_11 , & V_4 -> V_41 , NULL ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( & V_4 -> V_11 , & V_4 -> V_21 ) ;
return V_12 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_6 * V_3 )
{
V_42 = F_24 ( V_42 , & V_3 -> V_11 ) ;
if ( ! V_42 )
return 0 ;
V_3 -> V_15 = F_25 ( * V_42 ) ; V_42 ++ ;
return F_26 ( V_2 , V_42 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_29 * V_3 )
{
struct V_43 * V_44 = V_2 -> V_45 . V_44 ;
unsigned int V_46 ;
int V_47 ;
V_42 = F_24 ( V_42 , & V_3 -> V_11 ) ;
if ( ! V_42 )
return 0 ;
V_3 -> V_15 = F_25 ( * V_42 ++ ) ;
if ( V_3 -> V_15 & ~ ( V_16 | V_17 | V_18 | V_19 ) ||
! F_26 ( V_2 , V_42 ) )
return 0 ;
V_46 = ( char * ) V_42 - ( char * ) V_44 -> V_48 ;
V_47 = F_28 ( & V_2 -> V_45 , V_46 , NULL ,
( V_3 -> V_15 & V_16 ) ?
& V_3 -> V_26 : NULL ) ;
if ( V_47 > 0 )
V_47 = F_28 ( & V_2 -> V_45 , V_46 + V_47 , NULL ,
( V_3 -> V_15 & V_18 ) ?
& V_3 -> V_28 : NULL ) ;
return ( V_47 > 0 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_38 * V_3 )
{
V_42 = F_24 ( V_42 , & V_3 -> V_11 ) ;
if ( ! V_42 )
return 0 ;
return F_26 ( V_2 , V_42 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_39 * V_3 )
{
V_42 = F_24 ( V_42 , & V_3 -> V_11 ) ;
if ( ! V_42 )
return 0 ;
V_3 -> V_41 = F_25 ( * V_42 ++ ) ;
return F_26 ( V_2 , V_42 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_42 , void * V_49 )
{
return F_32 ( V_2 , V_42 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_7 * V_4 )
{
struct V_50 * V_50 = V_4 -> V_11 . V_14 ;
struct V_10 * V_10 ;
struct V_43 * V_44 = V_2 -> V_51 . V_44 ;
unsigned int V_46 ;
int V_47 ;
int V_52 ;
if ( V_50 == NULL || F_34 ( V_50 ) )
return 0 ;
V_10 = F_8 ( V_50 ) ;
V_42 = F_35 ( V_2 , V_42 , & V_4 -> V_11 , & V_4 -> V_21 ) ;
* V_42 ++ = F_36 ( V_4 -> V_15 ) ;
if ( ! F_32 ( V_2 , V_42 ) )
return 0 ;
V_46 = ( char * ) V_42 - ( char * ) V_44 -> V_48 ;
V_2 -> V_51 . V_53 = V_52 = F_37 (
( V_4 -> V_15 & V_16 ) ? V_4 -> V_26 : NULL ,
( V_4 -> V_15 & V_18 ) ? V_4 -> V_28 : NULL ) ;
while ( V_52 > 0 ) {
if ( ! * ( V_2 -> V_54 ++ ) )
return 0 ;
V_52 -= V_55 ;
}
V_47 = F_38 ( & V_2 -> V_51 , V_46 , V_10 ,
V_4 -> V_26 ,
V_4 -> V_15 & V_16 , 0 ) ;
if ( V_47 > 0 )
V_47 = F_38 ( & V_2 -> V_51 , V_46 + V_47 , V_10 ,
V_4 -> V_28 ,
V_4 -> V_15 & V_18 ,
V_56 ) ;
if ( V_47 <= 0 )
return 0 ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_30 * V_4 )
{
V_42 = F_35 ( V_2 , V_42 , & V_4 -> V_11 , & V_4 -> V_21 ) ;
return F_32 ( V_2 , V_42 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_40 * V_4 )
{
V_42 = F_35 ( V_2 , V_42 , & V_4 -> V_11 , & V_4 -> V_21 ) ;
* V_42 ++ = F_36 ( V_4 -> V_41 ) ;
return F_32 ( V_2 , V_42 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_7 * V_4 )
{
F_42 ( & V_4 -> V_11 ) ;
F_15 ( V_4 -> V_26 ) ;
F_15 ( V_4 -> V_28 ) ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_30 * V_4 )
{
F_42 ( & V_4 -> V_11 ) ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 * V_42 ,
struct V_40 * V_4 )
{
F_42 ( & V_4 -> V_11 ) ;
return 1 ;
}
