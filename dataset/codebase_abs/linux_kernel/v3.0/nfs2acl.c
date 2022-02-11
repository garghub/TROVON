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
if ( V_4 -> V_13 & ( V_14 | V_15 ) ) {
V_10 = F_8 ( V_8 , V_19 ) ;
if ( F_9 ( V_10 ) ) {
int V_20 = F_10 ( V_10 ) ;
if ( V_20 == - V_21 || V_20 == - V_22 )
V_10 = NULL ;
else {
V_11 = F_11 ( V_20 ) ;
goto V_23;
}
}
if ( V_10 == NULL ) {
struct V_24 * V_24 = V_8 -> V_25 -> V_26 ;
V_10 = F_12 ( V_24 -> V_27 , V_28 ) ;
}
V_4 -> V_29 = V_10 ;
}
if ( V_4 -> V_13 & ( V_16 | V_17 ) ) {
V_10 = F_8 ( V_8 , V_30 ) ;
if ( F_9 ( V_10 ) ) {
int V_20 = F_10 ( V_10 ) ;
if ( V_20 == - V_21 || V_20 == - V_22 )
V_10 = NULL ;
else {
V_11 = F_11 ( V_20 ) ;
goto V_23;
}
}
V_4 -> V_31 = V_10 ;
}
F_7 ( 0 ) ;
V_23:
F_13 ( V_4 -> V_29 ) ;
F_13 ( V_4 -> V_31 ) ;
F_7 ( V_11 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_32 * V_3 ,
struct V_33 * V_4 )
{
T_2 * V_8 ;
T_1 V_11 = 0 ;
F_3 ( L_2 , F_4 ( & V_3 -> V_8 ) ) ;
V_8 = F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_6 ( V_2 , & V_4 -> V_8 , 0 , V_34 ) ;
if ( ! V_11 ) {
V_11 = F_11 ( F_15 (
V_8 , V_19 , V_3 -> V_29 ) ) ;
}
if ( ! V_11 ) {
V_11 = F_11 ( F_15 (
V_8 , V_30 , V_3 -> V_31 ) ) ;
}
F_13 ( V_3 -> V_29 ) ;
F_13 ( V_3 -> V_31 ) ;
return V_11 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_35 * V_3 , struct V_33 * V_4 )
{
F_3 ( L_3 , F_4 ( & V_3 -> V_8 ) ) ;
F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
return F_6 ( V_2 , & V_4 -> V_8 , 0 , V_12 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_36 * V_3 ,
struct V_37 * V_4 )
{
T_1 V_11 ;
F_3 ( L_4 ,
F_4 ( & V_3 -> V_8 ) ,
V_3 -> V_38 ) ;
F_5 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_4 -> V_38 = V_3 -> V_38 ;
V_11 = F_18 ( V_2 , & V_4 -> V_8 , & V_4 -> V_38 , NULL ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_6 * V_3 )
{
if ( ! ( V_39 = F_20 ( V_39 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_13 = F_21 ( * V_39 ) ; V_39 ++ ;
return F_22 ( V_2 , V_39 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_32 * V_3 )
{
struct V_40 * V_41 = V_2 -> V_42 . V_41 ;
unsigned int V_43 ;
int V_44 ;
if ( ! ( V_39 = F_20 ( V_39 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_13 = F_21 ( * V_39 ++ ) ;
if ( V_3 -> V_13 & ~ ( V_14 | V_15 | V_16 | V_17 ) ||
! F_22 ( V_2 , V_39 ) )
return 0 ;
V_43 = ( char * ) V_39 - ( char * ) V_41 -> V_45 ;
V_44 = F_24 ( & V_2 -> V_42 , V_43 , NULL ,
( V_3 -> V_13 & V_14 ) ?
& V_3 -> V_29 : NULL ) ;
if ( V_44 > 0 )
V_44 = F_24 ( & V_2 -> V_42 , V_43 + V_44 , NULL ,
( V_3 -> V_13 & V_16 ) ?
& V_3 -> V_31 : NULL ) ;
return ( V_44 > 0 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_35 * V_3 )
{
if ( ! ( V_39 = F_20 ( V_39 , & V_3 -> V_8 ) ) )
return 0 ;
return F_22 ( V_2 , V_39 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_36 * V_3 )
{
if ( ! ( V_39 = F_20 ( V_39 , & V_3 -> V_8 ) ) )
return 0 ;
V_3 -> V_38 = F_21 ( * V_39 ++ ) ;
return F_22 ( V_2 , V_39 ) ;
}
int
F_27 ( struct V_1 * V_2 , T_1 * V_39 , void * V_46 )
{
return F_28 ( V_2 , V_39 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_7 * V_4 )
{
struct V_47 * V_47 = V_4 -> V_8 . V_25 ;
struct V_24 * V_24 ;
struct V_40 * V_41 = V_2 -> V_48 . V_41 ;
unsigned int V_43 ;
int V_44 ;
int V_49 ;
if ( V_47 == NULL || V_47 -> V_26 == NULL )
return 0 ;
V_24 = V_47 -> V_26 ;
V_39 = F_30 ( V_2 , V_39 , & V_4 -> V_8 ) ;
* V_39 ++ = F_31 ( V_4 -> V_13 ) ;
if ( ! F_28 ( V_2 , V_39 ) )
return 0 ;
V_43 = ( char * ) V_39 - ( char * ) V_41 -> V_45 ;
V_2 -> V_48 . V_50 = V_49 = F_32 (
( V_4 -> V_13 & V_14 ) ? V_4 -> V_29 : NULL ,
( V_4 -> V_13 & V_16 ) ? V_4 -> V_31 : NULL ) ;
while ( V_49 > 0 ) {
if ( ! V_2 -> V_51 [ V_2 -> V_52 ++ ] )
return 0 ;
V_49 -= V_53 ;
}
V_44 = F_33 ( & V_2 -> V_48 , V_43 , V_24 ,
V_4 -> V_29 ,
V_4 -> V_13 & V_14 , 0 ) ;
if ( V_44 > 0 )
V_44 = F_33 ( & V_2 -> V_48 , V_43 + V_44 , V_24 ,
V_4 -> V_31 ,
V_4 -> V_13 & V_16 ,
V_54 ) ;
if ( V_44 <= 0 )
return 0 ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_33 * V_4 )
{
V_39 = F_30 ( V_2 , V_39 , & V_4 -> V_8 ) ;
return F_28 ( V_2 , V_39 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_37 * V_4 )
{
V_39 = F_30 ( V_2 , V_39 , & V_4 -> V_8 ) ;
* V_39 ++ = F_31 ( V_4 -> V_38 ) ;
return F_28 ( V_2 , V_39 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_7 * V_4 )
{
F_37 ( & V_4 -> V_8 ) ;
F_13 ( V_4 -> V_29 ) ;
F_13 ( V_4 -> V_31 ) ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_33 * V_4 )
{
F_37 ( & V_4 -> V_8 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_39 ,
struct V_37 * V_4 )
{
F_37 ( & V_4 -> V_8 ) ;
return 1 ;
}
