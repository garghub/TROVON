static T_1
F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return V_5 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_6 * V_3 , struct V_7 * V_4 )
{
T_2 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 = 0 ;
F_3 ( L_1 , F_4 ( & V_3 -> V_8 ) ) ;
V_8 = F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_6 ( V_2 , & V_4 -> V_8 , 0 , V_12 ) ;
if ( V_11 )
F_7 ( V_11 ) ;
if ( V_3 -> V_13 & ~ ( V_14 | V_15 | V_16 | V_17 ) )
F_7 ( V_18 ) ;
V_4 -> V_13 = V_3 -> V_13 ;
V_11 = F_8 ( V_8 , & V_4 -> V_19 ) ;
if ( V_11 )
goto V_20;
if ( V_4 -> V_13 & ( V_14 | V_15 ) ) {
V_10 = F_9 ( V_8 , V_21 ) ;
if ( F_10 ( V_10 ) ) {
int V_22 = F_11 ( V_10 ) ;
if ( V_22 == - V_23 || V_22 == - V_24 )
V_10 = NULL ;
else {
V_11 = F_12 ( V_22 ) ;
goto V_20;
}
}
if ( V_10 == NULL ) {
struct V_25 * V_25 = V_8 -> V_26 -> V_27 ;
V_10 = F_13 ( V_25 -> V_28 , V_29 ) ;
}
V_4 -> V_30 = V_10 ;
}
if ( V_4 -> V_13 & ( V_16 | V_17 ) ) {
V_10 = F_9 ( V_8 , V_31 ) ;
if ( F_10 ( V_10 ) ) {
int V_22 = F_11 ( V_10 ) ;
if ( V_22 == - V_23 || V_22 == - V_24 )
V_10 = NULL ;
else {
V_11 = F_12 ( V_22 ) ;
goto V_20;
}
}
V_4 -> V_32 = V_10 ;
}
F_7 ( 0 ) ;
V_20:
F_14 ( V_4 -> V_30 ) ;
F_14 ( V_4 -> V_32 ) ;
F_7 ( V_11 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_33 * V_3 ,
struct V_34 * V_4 )
{
T_2 * V_8 ;
T_1 V_11 = 0 ;
F_3 ( L_2 , F_4 ( & V_3 -> V_8 ) ) ;
V_8 = F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_6 ( V_2 , & V_4 -> V_8 , 0 , V_35 ) ;
if ( ! V_11 ) {
V_11 = F_12 ( F_16 (
V_8 , V_21 , V_3 -> V_30 ) ) ;
}
if ( ! V_11 ) {
V_11 = F_12 ( F_16 (
V_8 , V_31 , V_3 -> V_32 ) ) ;
}
if ( ! V_11 ) {
V_11 = F_8 ( V_8 , & V_4 -> V_19 ) ;
}
F_14 ( V_3 -> V_30 ) ;
F_14 ( V_3 -> V_32 ) ;
return V_11 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_36 * V_3 , struct V_34 * V_4 )
{
T_1 V_11 ;
F_3 ( L_3 , F_4 ( & V_3 -> V_8 ) ) ;
F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_6 ( V_2 , & V_4 -> V_8 , 0 , V_12 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( & V_4 -> V_8 , & V_4 -> V_19 ) ;
return V_11 ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_37 * V_3 ,
struct V_38 * V_4 )
{
T_1 V_11 ;
F_3 ( L_4 ,
F_4 ( & V_3 -> V_8 ) ,
V_3 -> V_39 ) ;
F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_4 -> V_39 = V_3 -> V_39 ;
V_11 = F_19 ( V_2 , & V_4 -> V_8 , & V_4 -> V_39 , NULL ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( & V_4 -> V_8 , & V_4 -> V_19 ) ;
return V_11 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_6 * V_3 )
{
if ( ! ( V_40 = F_21 ( V_40 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_13 = F_22 ( * V_40 ) ; V_40 ++ ;
return F_23 ( V_2 , V_40 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_33 * V_3 )
{
struct V_41 * V_42 = V_2 -> V_43 . V_42 ;
unsigned int V_44 ;
int V_45 ;
if ( ! ( V_40 = F_21 ( V_40 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_13 = F_22 ( * V_40 ++ ) ;
if ( V_3 -> V_13 & ~ ( V_14 | V_15 | V_16 | V_17 ) ||
! F_23 ( V_2 , V_40 ) )
return 0 ;
V_44 = ( char * ) V_40 - ( char * ) V_42 -> V_46 ;
V_45 = F_25 ( & V_2 -> V_43 , V_44 , NULL ,
( V_3 -> V_13 & V_14 ) ?
& V_3 -> V_30 : NULL ) ;
if ( V_45 > 0 )
V_45 = F_25 ( & V_2 -> V_43 , V_44 + V_45 , NULL ,
( V_3 -> V_13 & V_16 ) ?
& V_3 -> V_32 : NULL ) ;
return ( V_45 > 0 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_36 * V_3 )
{
if ( ! ( V_40 = F_21 ( V_40 , & V_3 -> V_8 ) ) )
return 0 ;
return F_23 ( V_2 , V_40 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_37 * V_3 )
{
if ( ! ( V_40 = F_21 ( V_40 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_39 = F_22 ( * V_40 ++ ) ;
return F_23 ( V_2 , V_40 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_40 , void * V_47 )
{
return F_29 ( V_2 , V_40 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_7 * V_4 )
{
struct V_48 * V_48 = V_4 -> V_8 . V_26 ;
struct V_25 * V_25 ;
struct V_41 * V_42 = V_2 -> V_49 . V_42 ;
unsigned int V_44 ;
int V_45 ;
int V_50 ;
if ( V_48 == NULL || V_48 -> V_27 == NULL )
return 0 ;
V_25 = V_48 -> V_27 ;
V_40 = F_31 ( V_2 , V_40 , & V_4 -> V_8 , & V_4 -> V_19 ) ;
* V_40 ++ = F_32 ( V_4 -> V_13 ) ;
if ( ! F_29 ( V_2 , V_40 ) )
return 0 ;
V_44 = ( char * ) V_40 - ( char * ) V_42 -> V_46 ;
V_2 -> V_49 . V_51 = V_50 = F_33 (
( V_4 -> V_13 & V_14 ) ? V_4 -> V_30 : NULL ,
( V_4 -> V_13 & V_16 ) ? V_4 -> V_32 : NULL ) ;
while ( V_50 > 0 ) {
if ( ! * ( V_2 -> V_52 ++ ) )
return 0 ;
V_50 -= V_53 ;
}
V_45 = F_34 ( & V_2 -> V_49 , V_44 , V_25 ,
V_4 -> V_30 ,
V_4 -> V_13 & V_14 , 0 ) ;
if ( V_45 > 0 )
V_45 = F_34 ( & V_2 -> V_49 , V_44 + V_45 , V_25 ,
V_4 -> V_32 ,
V_4 -> V_13 & V_16 ,
V_54 ) ;
if ( V_45 <= 0 )
return 0 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_34 * V_4 )
{
V_40 = F_31 ( V_2 , V_40 , & V_4 -> V_8 , & V_4 -> V_19 ) ;
return F_29 ( V_2 , V_40 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_38 * V_4 )
{
V_40 = F_31 ( V_2 , V_40 , & V_4 -> V_8 , & V_4 -> V_19 ) ;
* V_40 ++ = F_32 ( V_4 -> V_39 ) ;
return F_29 ( V_2 , V_40 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_7 * V_4 )
{
F_38 ( & V_4 -> V_8 ) ;
F_14 ( V_4 -> V_30 ) ;
F_14 ( V_4 -> V_32 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_34 * V_4 )
{
F_38 ( & V_4 -> V_8 ) ;
return 1 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_40 ,
struct V_38 * V_4 )
{
F_38 ( & V_4 -> V_8 ) ;
return 1 ;
}
