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
V_10 = V_11 -> V_14 -> V_15 ;
if ( V_3 -> V_16 & ~ ( V_17 | V_18 | V_19 | V_20 ) )
F_7 ( V_21 ) ;
V_4 -> V_16 = V_3 -> V_16 ;
V_12 = F_8 ( V_11 , & V_4 -> V_22 ) ;
if ( V_12 )
goto V_23;
if ( V_4 -> V_16 & ( V_17 | V_18 ) ) {
V_9 = F_9 ( V_10 , V_24 ) ;
if ( F_10 ( V_9 ) ) {
V_12 = F_11 ( F_12 ( V_9 ) ) ;
goto V_23;
}
if ( V_9 == NULL ) {
V_9 = F_13 ( V_10 -> V_25 , V_26 ) ;
}
V_4 -> V_27 = V_9 ;
}
if ( V_4 -> V_16 & ( V_19 | V_20 ) ) {
V_9 = F_9 ( V_10 , V_28 ) ;
if ( F_10 ( V_9 ) ) {
V_12 = F_11 ( F_12 ( V_9 ) ) ;
goto V_23;
}
V_4 -> V_29 = V_9 ;
}
F_7 ( 0 ) ;
V_23:
F_14 ( V_4 -> V_27 ) ;
F_14 ( V_4 -> V_29 ) ;
F_7 ( V_12 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_30 * V_3 ,
struct V_31 * V_4 )
{
struct V_10 * V_10 ;
T_2 * V_11 ;
T_1 V_12 = 0 ;
int error ;
F_3 ( L_2 , F_4 ( & V_3 -> V_11 ) ) ;
V_11 = F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_6 ( V_2 , & V_4 -> V_11 , 0 , V_32 ) ;
if ( V_12 )
goto V_33;
V_10 = V_11 -> V_14 -> V_15 ;
if ( ! F_16 ( V_10 ) || ! V_10 -> V_34 -> V_35 ) {
error = - V_36 ;
goto V_37;
}
error = F_17 ( V_11 ) ;
if ( error )
goto V_37;
error = V_10 -> V_34 -> V_35 ( V_10 , V_3 -> V_27 , V_24 ) ;
if ( error )
goto V_38;
error = V_10 -> V_34 -> V_35 ( V_10 , V_3 -> V_29 ,
V_28 ) ;
if ( error )
goto V_38;
F_18 ( V_11 ) ;
V_12 = F_8 ( V_11 , & V_4 -> V_22 ) ;
V_33:
F_14 ( V_3 -> V_27 ) ;
F_14 ( V_3 -> V_29 ) ;
return V_12 ;
V_38:
F_18 ( V_11 ) ;
V_37:
V_12 = F_11 ( error ) ;
goto V_33;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_39 * V_3 , struct V_31 * V_4 )
{
T_1 V_12 ;
F_3 ( L_3 , F_4 ( & V_3 -> V_11 ) ) ;
F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_12 = F_6 ( V_2 , & V_4 -> V_11 , 0 , V_13 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( & V_4 -> V_11 , & V_4 -> V_22 ) ;
return V_12 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_40 * V_3 ,
struct V_41 * V_4 )
{
T_1 V_12 ;
F_3 ( L_4 ,
F_4 ( & V_3 -> V_11 ) ,
V_3 -> V_42 ) ;
F_5 ( & V_4 -> V_11 , & V_3 -> V_11 ) ;
V_4 -> V_42 = V_3 -> V_42 ;
V_12 = F_21 ( V_2 , & V_4 -> V_11 , & V_4 -> V_42 , NULL ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( & V_4 -> V_11 , & V_4 -> V_22 ) ;
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_6 * V_3 )
{
V_43 = F_23 ( V_43 , & V_3 -> V_11 ) ;
if ( ! V_43 )
return 0 ;
V_3 -> V_16 = F_24 ( * V_43 ) ; V_43 ++ ;
return F_25 ( V_2 , V_43 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_30 * V_3 )
{
struct V_44 * V_45 = V_2 -> V_46 . V_45 ;
unsigned int V_47 ;
int V_48 ;
V_43 = F_23 ( V_43 , & V_3 -> V_11 ) ;
if ( ! V_43 )
return 0 ;
V_3 -> V_16 = F_24 ( * V_43 ++ ) ;
if ( V_3 -> V_16 & ~ ( V_17 | V_18 | V_19 | V_20 ) ||
! F_25 ( V_2 , V_43 ) )
return 0 ;
V_47 = ( char * ) V_43 - ( char * ) V_45 -> V_49 ;
V_48 = F_27 ( & V_2 -> V_46 , V_47 , NULL ,
( V_3 -> V_16 & V_17 ) ?
& V_3 -> V_27 : NULL ) ;
if ( V_48 > 0 )
V_48 = F_27 ( & V_2 -> V_46 , V_47 + V_48 , NULL ,
( V_3 -> V_16 & V_19 ) ?
& V_3 -> V_29 : NULL ) ;
return ( V_48 > 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_39 * V_3 )
{
V_43 = F_23 ( V_43 , & V_3 -> V_11 ) ;
if ( ! V_43 )
return 0 ;
return F_25 ( V_2 , V_43 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_40 * V_3 )
{
V_43 = F_23 ( V_43 , & V_3 -> V_11 ) ;
if ( ! V_43 )
return 0 ;
V_3 -> V_42 = F_24 ( * V_43 ++ ) ;
return F_25 ( V_2 , V_43 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_43 , void * V_50 )
{
return F_31 ( V_2 , V_43 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_7 * V_4 )
{
struct V_51 * V_51 = V_4 -> V_11 . V_14 ;
struct V_10 * V_10 ;
struct V_44 * V_45 = V_2 -> V_52 . V_45 ;
unsigned int V_47 ;
int V_48 ;
int V_53 ;
if ( V_51 == NULL || V_51 -> V_15 == NULL )
return 0 ;
V_10 = V_51 -> V_15 ;
V_43 = F_33 ( V_2 , V_43 , & V_4 -> V_11 , & V_4 -> V_22 ) ;
* V_43 ++ = F_34 ( V_4 -> V_16 ) ;
if ( ! F_31 ( V_2 , V_43 ) )
return 0 ;
V_47 = ( char * ) V_43 - ( char * ) V_45 -> V_49 ;
V_2 -> V_52 . V_54 = V_53 = F_35 (
( V_4 -> V_16 & V_17 ) ? V_4 -> V_27 : NULL ,
( V_4 -> V_16 & V_19 ) ? V_4 -> V_29 : NULL ) ;
while ( V_53 > 0 ) {
if ( ! * ( V_2 -> V_55 ++ ) )
return 0 ;
V_53 -= V_56 ;
}
V_48 = F_36 ( & V_2 -> V_52 , V_47 , V_10 ,
V_4 -> V_27 ,
V_4 -> V_16 & V_17 , 0 ) ;
if ( V_48 > 0 )
V_48 = F_36 ( & V_2 -> V_52 , V_47 + V_48 , V_10 ,
V_4 -> V_29 ,
V_4 -> V_16 & V_19 ,
V_57 ) ;
if ( V_48 <= 0 )
return 0 ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_31 * V_4 )
{
V_43 = F_33 ( V_2 , V_43 , & V_4 -> V_11 , & V_4 -> V_22 ) ;
return F_31 ( V_2 , V_43 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_41 * V_4 )
{
V_43 = F_33 ( V_2 , V_43 , & V_4 -> V_11 , & V_4 -> V_22 ) ;
* V_43 ++ = F_34 ( V_4 -> V_42 ) ;
return F_31 ( V_2 , V_43 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_7 * V_4 )
{
F_40 ( & V_4 -> V_11 ) ;
F_14 ( V_4 -> V_27 ) ;
F_14 ( V_4 -> V_29 ) ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_31 * V_4 )
{
F_40 ( & V_4 -> V_11 ) ;
return 1 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 * V_43 ,
struct V_41 * V_4 )
{
F_40 ( & V_4 -> V_11 ) ;
return 1 ;
}
