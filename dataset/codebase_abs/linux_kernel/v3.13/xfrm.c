static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 &&
( V_2 -> V_3 == V_4 ) &&
( V_2 -> V_5 == V_6 ) ) ;
}
static inline int F_2 ( struct V_7 * V_8 )
{
return F_1 ( V_8 -> V_9 ) ;
}
static int F_3 ( struct V_1 * * V_10 ,
struct V_11 * V_12 )
{
int V_13 ;
const struct V_14 * V_15 = F_4 () ;
struct V_1 * V_2 = NULL ;
T_1 V_16 ;
if ( V_10 == NULL || V_12 == NULL ||
V_12 -> V_3 != V_4 ||
V_12 -> V_5 != V_6 )
return - V_17 ;
V_16 = V_12 -> V_18 ;
if ( V_16 >= V_19 )
return - V_20 ;
V_2 = F_5 ( sizeof( * V_2 ) + V_16 + 1 , V_21 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_18 = V_16 ;
memcpy ( V_2 -> V_22 , & V_12 [ 1 ] , V_16 ) ;
V_2 -> V_22 [ V_16 ] = '\0' ;
V_13 = F_6 ( V_2 -> V_22 , V_16 , & V_2 -> V_23 ) ;
if ( V_13 )
goto V_24;
V_13 = F_7 ( V_15 -> V_25 , V_2 -> V_23 ,
V_26 , V_27 , NULL ) ;
if ( V_13 )
goto V_24;
* V_10 = V_2 ;
F_8 ( & V_28 ) ;
return 0 ;
V_24:
F_9 ( V_2 ) ;
return V_13 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_11 ( & V_28 ) ;
F_9 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 = F_4 () ;
if ( ! V_2 )
return 0 ;
return F_7 ( V_15 -> V_25 , V_2 -> V_23 ,
V_26 , V_27 ,
NULL ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_29 , T_2 V_30 )
{
int V_13 ;
if ( ! V_2 )
return 0 ;
if ( ! F_1 ( V_2 ) )
return - V_17 ;
V_13 = F_7 ( V_29 , V_2 -> V_23 ,
V_26 , V_31 , NULL ) ;
return ( V_13 == - V_32 ? - V_33 : V_13 ) ;
}
int F_14 ( struct V_7 * V_8 ,
struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
T_1 V_38 ;
if ( ! V_35 -> V_9 )
if ( V_8 -> V_9 )
return 0 ;
else
return 1 ;
else
if ( ! V_8 -> V_9 )
return 0 ;
else
if ( ! F_2 ( V_8 ) )
return 0 ;
V_38 = V_8 -> V_9 -> V_23 ;
if ( V_37 -> V_39 != V_38 )
return 0 ;
return ( F_7 ( V_37 -> V_39 , V_38 ,
V_26 , V_40 ,
NULL ) ? 0 : 1 ) ;
}
static T_1 F_15 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_16 ( V_42 ) ;
struct V_7 * V_8 ;
if ( V_44 == NULL )
return V_45 ;
V_8 = V_44 -> V_46 ;
if ( V_8 == NULL || ! F_2 ( V_8 ) )
return V_45 ;
return V_8 -> V_9 -> V_23 ;
}
static int F_17 ( struct V_41 * V_42 ,
T_1 * V_25 , int V_47 )
{
T_1 V_48 = V_45 ;
struct V_49 * V_50 = V_42 -> V_50 ;
if ( V_50 ) {
int V_51 ;
for ( V_51 = V_50 -> V_52 - 1 ; V_51 >= 0 ; V_51 -- ) {
struct V_7 * V_8 = V_50 -> V_53 [ V_51 ] ;
if ( F_2 ( V_8 ) ) {
struct V_1 * V_2 = V_8 -> V_9 ;
if ( V_48 == V_45 ) {
V_48 = V_2 -> V_23 ;
if ( ! V_47 )
goto V_54;
} else if ( V_48 != V_2 -> V_23 ) {
* V_25 = V_45 ;
return - V_17 ;
}
}
}
}
V_54:
* V_25 = V_48 ;
return 0 ;
}
int F_18 ( struct V_41 * V_42 , T_1 * V_25 , int V_47 )
{
if ( V_42 == NULL ) {
* V_25 = V_45 ;
return 0 ;
}
return F_17 ( V_42 , V_25 , V_47 ) ;
}
int F_19 ( struct V_41 * V_42 , T_1 * V_25 )
{
int V_13 ;
V_13 = F_17 ( V_42 , V_25 , 0 ) ;
if ( V_13 == 0 && * V_25 == V_45 )
* V_25 = F_15 ( V_42 ) ;
return V_13 ;
}
int F_20 ( struct V_1 * * V_10 ,
struct V_11 * V_12 )
{
return F_3 ( V_10 , V_12 ) ;
}
int F_21 ( struct V_1 * V_55 ,
struct V_1 * * V_56 )
{
struct V_1 * V_57 ;
if ( ! V_55 )
return 0 ;
V_57 = F_22 ( V_55 , sizeof( * V_55 ) + V_55 -> V_18 ,
V_58 ) ;
if ( ! V_57 )
return - V_20 ;
F_8 ( & V_28 ) ;
* V_56 = V_57 ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
return F_12 ( V_2 ) ;
}
int F_25 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
return F_3 ( & V_8 -> V_9 , V_12 ) ;
}
int F_26 ( struct V_7 * V_8 ,
struct V_1 * V_59 , T_1 V_60 )
{
int V_13 ;
struct V_1 * V_2 ;
char * V_22 = NULL ;
int V_16 ;
if ( ! V_59 )
return 0 ;
if ( V_60 == 0 )
return - V_17 ;
V_13 = F_27 ( V_60 , & V_22 , & V_16 ) ;
if ( V_13 )
return V_13 ;
V_2 = F_5 ( sizeof( * V_2 ) + V_16 , V_58 ) ;
if ( ! V_2 ) {
V_13 = - V_20 ;
goto V_54;
}
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_23 = V_60 ;
V_2 -> V_18 = V_16 ;
memcpy ( V_2 -> V_22 , V_22 , V_16 ) ;
V_8 -> V_9 = V_2 ;
F_8 ( & V_28 ) ;
V_54:
F_9 ( V_22 ) ;
return V_13 ;
}
void F_28 ( struct V_7 * V_8 )
{
F_10 ( V_8 -> V_9 ) ;
}
int F_29 ( struct V_7 * V_8 )
{
return F_12 ( V_8 -> V_9 ) ;
}
int F_30 ( T_1 V_61 , struct V_41 * V_42 ,
struct V_62 * V_63 )
{
int V_51 ;
struct V_49 * V_50 = V_42 -> V_50 ;
T_1 V_64 = V_65 ;
if ( V_50 ) {
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; V_51 ++ ) {
struct V_7 * V_8 = V_50 -> V_53 [ V_51 ] ;
if ( V_8 && F_2 ( V_8 ) ) {
struct V_1 * V_2 = V_8 -> V_9 ;
V_64 = V_2 -> V_23 ;
break;
}
}
}
return F_7 ( V_61 , V_64 ,
V_26 , V_66 , V_63 ) ;
}
int F_31 ( T_1 V_61 , struct V_41 * V_42 ,
struct V_62 * V_63 , T_2 V_67 )
{
struct V_43 * V_44 ;
switch ( V_67 ) {
case V_68 :
case V_69 :
case V_70 :
return 0 ;
default:
break;
}
V_44 = F_16 ( V_42 ) ;
if ( V_44 ) {
struct V_43 * V_71 ;
for ( V_71 = V_44 ; V_71 != NULL ; V_71 = V_71 -> V_72 ) {
struct V_7 * V_8 = V_71 -> V_46 ;
if ( V_8 && F_2 ( V_8 ) )
return 0 ;
}
}
return F_7 ( V_61 , V_65 ,
V_26 , V_40 , V_63 ) ;
}
