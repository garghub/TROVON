void F_1 ( struct V_1 * V_2 ,
void * V_3 , void (* F_2)( void const * ) ,
struct V_4 * V_5 )
{
V_5 -> V_3 = V_3 ;
V_5 -> F_2 = F_2 ;
F_3 ( & V_5 -> V_6 , & V_2 -> V_7 ) ;
}
static struct V_4 *
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_5 ( & V_2 -> V_7 ) )
return NULL ;
V_5 = F_6 ( & V_2 -> V_7 ,
struct V_4 , V_6 ) ;
F_7 ( & V_5 -> V_6 ) ;
return V_5 ;
}
void * F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_4 ( V_2 ) ;
F_9 ( ! V_5 ) ;
return V_5 -> V_3 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_4 ( V_2 ) ) )
V_5 -> F_2 ( V_5 -> V_3 ) ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_14 ( ! F_5 ( & V_2 -> V_7 ) , L_1 ,
V_9 -> V_10 ) ;
F_12 ( V_2 ) ;
}
static struct V_11 * F_15 ( void )
{
struct V_11 * V_12 ;
F_16 ( & V_13 ) ;
if ( F_5 ( & V_14 ) ) {
V_12 = NULL ;
goto V_15;
}
V_12 = F_6 ( & V_14 ,
struct V_11 , V_6 ) ;
F_7 ( & V_12 -> V_6 ) ;
V_15:
F_17 ( & V_13 ) ;
return V_12 ;
}
void F_18 ( void )
{
struct V_11 * V_12 ;
F_19 () ;
while ( ( V_12 = F_15 () ) ) {
V_12 -> V_16 ( V_12 -> V_9 , V_12 -> V_3 ) ;
F_20 ( V_12 -> V_9 ) ;
F_21 ( V_12 ) ;
}
}
static void F_22 ( struct V_17 * V_18 )
{
F_23 () ;
F_18 () ;
F_24 () ;
}
static int F_25 ( struct V_8 * V_9 ,
const void * V_3 , T_1 V_19 ,
T_2 * V_16 )
{
struct V_11 * V_12 ;
V_12 = F_26 ( sizeof( * V_12 ) + V_19 , V_20 ) ;
if ( ! V_12 )
return - V_21 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_16 = V_16 ;
memcpy ( V_12 -> V_3 , V_3 , V_19 ) ;
F_27 ( V_9 ) ;
F_16 ( & V_13 ) ;
F_3 ( & V_12 -> V_6 , & V_14 ) ;
F_17 ( & V_13 ) ;
F_28 ( & V_22 ) ;
return 0 ;
}
int F_29 ( struct V_8 * V_9 , struct V_23 * V_24 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
struct V_23 V_30 = {
. V_31 = V_32
} ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> F_29 )
return V_26 -> F_29 ( V_9 , V_24 ) ;
if ( V_24 -> V_35 & V_36 )
return V_33 ;
F_30 (dev, lower_dev, iter) {
V_33 = F_29 ( V_27 , V_24 ) ;
if ( V_33 )
break;
if ( V_30 . V_31 == V_32 )
V_30 = * V_24 ;
else if ( memcmp ( & V_30 , V_24 , sizeof( * V_24 ) ) )
return - V_37 ;
}
return V_33 ;
}
static int F_31 ( struct V_8 * V_9 ,
const struct V_23 * V_24 ,
struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_38 ) {
V_33 = V_26 -> V_38 ( V_9 , V_24 , V_2 ) ;
goto V_39;
}
if ( V_24 -> V_35 & V_36 )
goto V_39;
F_30 (dev, lower_dev, iter) {
V_33 = F_31 ( V_27 , V_24 , V_2 ) ;
if ( V_33 )
break;
}
V_39:
if ( V_33 == - V_34 && V_24 -> V_35 & V_40 )
V_33 = 0 ;
return V_33 ;
}
static int F_32 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
struct V_1 V_2 ;
int V_33 ;
F_10 ( & V_2 ) ;
V_2 . V_41 = true ;
V_33 = F_31 ( V_9 , V_24 , & V_2 ) ;
if ( V_33 ) {
if ( V_33 != - V_34 )
F_12 ( & V_2 ) ;
return V_33 ;
}
V_2 . V_41 = false ;
V_33 = F_31 ( V_9 , V_24 , & V_2 ) ;
F_14 ( V_33 , L_2 ,
V_9 -> V_10 , V_24 -> V_31 ) ;
F_13 ( V_9 , & V_2 ) ;
return V_33 ;
}
static void F_33 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_23 * V_24 = V_3 ;
int V_33 ;
V_33 = F_32 ( V_9 , V_24 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_3 ,
V_33 , V_24 -> V_31 ) ;
if ( V_24 -> V_42 )
V_24 -> V_42 ( V_9 , V_33 , V_24 -> V_43 ) ;
}
static int F_35 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
return F_25 ( V_9 , V_24 , sizeof( * V_24 ) ,
F_33 ) ;
}
int V_38 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
if ( V_24 -> V_35 & V_44 )
return F_35 ( V_9 , V_24 ) ;
F_19 () ;
return F_32 ( V_9 , V_24 ) ;
}
static T_1 F_36 ( const struct V_45 * V_46 )
{
switch ( V_46 -> V_31 ) {
case V_47 :
return sizeof( struct V_48 ) ;
case V_49 :
return sizeof( struct V_50 ) ;
default:
F_37 () ;
}
return 0 ;
}
static int F_38 ( struct V_8 * V_9 ,
const struct V_45 * V_46 ,
struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_51 )
return V_26 -> V_51 ( V_9 , V_46 , V_2 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_38 ( V_27 , V_46 , V_2 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_39 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
struct V_1 V_2 ;
int V_33 ;
F_19 () ;
F_10 ( & V_2 ) ;
V_2 . V_41 = true ;
V_33 = F_38 ( V_9 , V_46 , & V_2 ) ;
if ( V_33 ) {
if ( V_33 != - V_34 )
F_12 ( & V_2 ) ;
return V_33 ;
}
V_2 . V_41 = false ;
V_33 = F_38 ( V_9 , V_46 , & V_2 ) ;
F_14 ( V_33 , L_4 , V_9 -> V_10 , V_46 -> V_31 ) ;
F_13 ( V_9 , & V_2 ) ;
return V_33 ;
}
static void F_40 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_45 * V_46 = V_3 ;
int V_33 ;
V_33 = F_39 ( V_9 , V_46 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_5 ,
V_33 , V_46 -> V_31 ) ;
if ( V_46 -> V_42 )
V_46 -> V_42 ( V_9 , V_33 , V_46 -> V_43 ) ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
return F_25 ( V_9 , V_46 , F_36 ( V_46 ) ,
F_40 ) ;
}
int V_51 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_35 & V_44 )
return F_41 ( V_9 , V_46 ) ;
F_19 () ;
return F_39 ( V_9 , V_46 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
const struct V_25 * V_26 = V_9 -> V_25 ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
int V_33 = - V_34 ;
if ( V_26 && V_26 -> V_52 )
return V_26 -> V_52 ( V_9 , V_46 ) ;
F_30 (dev, lower_dev, iter) {
V_33 = F_42 ( V_27 , V_46 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static void F_43 ( struct V_8 * V_9 ,
const void * V_3 )
{
const struct V_45 * V_46 = V_3 ;
int V_33 ;
V_33 = F_42 ( V_9 , V_46 ) ;
if ( V_33 && V_33 != - V_34 )
F_34 ( V_9 , L_6 ,
V_33 , V_46 -> V_31 ) ;
if ( V_46 -> V_42 )
V_46 -> V_42 ( V_9 , V_33 , V_46 -> V_43 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
return F_25 ( V_9 , V_46 , F_36 ( V_46 ) ,
F_43 ) ;
}
int V_52 ( struct V_8 * V_9 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_35 & V_44 )
return F_44 ( V_9 , V_46 ) ;
F_19 () ;
return F_42 ( V_9 , V_46 ) ;
}
int F_45 ( struct V_53 * V_54 )
{
return F_46 ( & V_55 , V_54 ) ;
}
int F_47 ( struct V_53 * V_54 )
{
return F_48 ( & V_55 , V_54 ) ;
}
int F_49 ( unsigned long V_56 , struct V_8 * V_9 ,
struct V_57 * V_58 )
{
V_58 -> V_9 = V_9 ;
return F_50 ( & V_55 , V_56 , V_58 ) ;
}
bool F_51 ( struct V_8 * V_59 ,
struct V_8 * V_60 )
{
struct V_23 V_61 = {
. V_62 = V_59 ,
. V_31 = V_63 ,
} ;
struct V_23 V_64 = {
. V_62 = V_60 ,
. V_31 = V_63 ,
} ;
if ( F_29 ( V_59 , & V_61 ) ||
F_29 ( V_60 , & V_64 ) )
return false ;
return F_52 ( & V_61 . V_65 . V_66 , & V_64 . V_65 . V_66 ) ;
}
