static const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
const struct V_1 * V_6 = V_3 -> V_7 ;
while ( * V_6 -> V_8 ) {
if ( F_2 ( V_5 -> V_8 , V_6 -> V_8 ) ) {
int V_9 = 0 ;
for (; ; ) {
int V_10 ;
struct V_11 * V_12 ;
if ( V_9 == V_13 ||
! * V_6 -> V_14 [ V_9 ] . V_8 )
return V_6 ;
V_10 = 0 ;
F_3 (card, dev) {
if ( F_2 ( V_12 -> V_8 ,
V_6 -> V_14 [ V_9 ] . V_8 ) ) {
V_10 = 1 ;
break;
}
}
if ( ! V_10 )
break;
V_9 ++ ;
}
}
V_6 ++ ;
}
return NULL ;
}
static void F_4 ( struct V_11 * V_12 )
{
V_12 -> V_15 = NULL ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_16 ) ;
if ( ! V_12 -> V_5 || ! V_3 )
return;
if ( V_3 -> remove )
V_3 -> remove ( V_12 -> V_15 ) ;
V_3 -> V_17 . remove = & F_4 ;
F_7 ( V_12 -> V_15 ) ;
F_4 ( V_12 ) ;
}
static int F_8 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
const struct V_1 * V_8 ;
struct V_18 * V_19 ;
struct V_11 * V_12 ;
if ( ! V_3 -> V_20 )
return 0 ;
V_8 = F_1 ( V_3 , V_5 ) ;
if ( ! V_8 )
return 0 ;
V_19 = F_9 ( sizeof( * V_19 ) ) ;
if ( ! V_19 )
return 0 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_16 = V_3 ;
V_19 -> V_21 = V_22 ;
if ( V_3 -> V_20 ( V_19 , V_8 ) >= 0 )
return 1 ;
F_3 (card, dev) {
if ( V_12 -> V_15 == V_19 )
F_10 ( V_12 ) ;
}
F_7 ( V_19 ) ;
return 0 ;
}
static struct V_23 * F_11 ( struct V_4 * V_5 , char * V_8 )
{
struct V_23 * V_24 , * V_25 ;
V_24 = F_12 ( sizeof( struct V_23 ) , V_26 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_24 -> V_8 [ 1 ] = V_8 [ 1 ] ;
V_24 -> V_8 [ 2 ] = V_8 [ 2 ] ;
V_24 -> V_8 [ 3 ] = tolower ( V_8 [ 3 ] ) ;
V_24 -> V_8 [ 4 ] = tolower ( V_8 [ 4 ] ) ;
V_24 -> V_8 [ 5 ] = tolower ( V_8 [ 5 ] ) ;
V_24 -> V_8 [ 6 ] = tolower ( V_8 [ 6 ] ) ;
V_24 -> V_8 [ 7 ] = '\0' ;
V_24 -> V_27 = NULL ;
V_25 = V_5 -> V_8 ;
while ( V_25 && V_25 -> V_27 )
V_25 = V_25 -> V_27 ;
if ( V_25 )
V_25 -> V_27 = V_24 ;
else
V_5 -> V_8 = V_24 ;
return V_24 ;
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_23 * V_8 ;
struct V_23 * V_27 ;
V_8 = V_5 -> V_8 ;
while ( V_8 ) {
V_27 = V_8 -> V_27 ;
F_7 ( V_8 ) ;
V_8 = V_27 ;
}
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_15 ( V_29 ) ;
F_13 ( V_5 ) ;
F_7 ( V_5 ) ;
}
struct V_4 * F_16 ( struct V_30 * V_31 , int V_8 , char * V_32 )
{
struct V_4 * V_5 ;
struct V_23 * V_24 ;
V_5 = F_12 ( sizeof( struct V_4 ) , V_26 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_31 = V_31 ;
V_5 -> V_33 = V_8 ;
V_5 -> V_12 . V_34 = & V_5 -> V_31 -> V_12 ;
F_17 ( & V_5 -> V_12 , L_1 , V_5 -> V_31 -> V_33 , V_5 -> V_33 ) ;
V_5 -> V_12 . V_35 = F_18 ( 24 ) ;
V_5 -> V_12 . V_36 = & V_5 -> V_12 . V_35 ;
V_24 = F_11 ( V_5 , V_32 ) ;
if ( ! V_24 ) {
F_7 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
static T_1 F_19 ( struct V_28 * V_29 ,
struct V_37 * V_38 , char * V_39 )
{
char * V_40 = V_39 ;
struct V_4 * V_5 = F_15 ( V_29 ) ;
V_40 += sprintf ( V_40 , L_2 , V_5 -> V_41 ) ;
return ( V_40 - V_39 ) ;
}
static T_1 F_20 ( struct V_28 * V_29 ,
struct V_37 * V_38 , char * V_39 )
{
char * V_40 = V_39 ;
struct V_4 * V_5 = F_15 ( V_29 ) ;
struct V_23 * V_42 = V_5 -> V_8 ;
while ( V_42 ) {
V_40 += sprintf ( V_40 , L_2 , V_42 -> V_8 ) ;
V_42 = V_42 -> V_27 ;
}
return ( V_40 - V_39 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_43 = F_22 ( & V_5 -> V_12 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_22 ( & V_5 -> V_12 , & V_45 ) ;
if ( V_43 )
goto V_46;
return 0 ;
V_46:
F_23 ( & V_5 -> V_12 , & V_44 ) ;
return V_43 ;
}
int F_24 ( struct V_4 * V_5 )
{
int error ;
struct V_47 * V_42 , * V_48 ;
V_5 -> V_12 . V_49 = NULL ;
V_5 -> V_12 . V_50 = & F_14 ;
error = F_25 ( & V_5 -> V_12 ) ;
if ( error ) {
F_26 ( & V_5 -> V_12 , L_3 , error ) ;
return error ;
}
F_21 ( V_5 ) ;
F_27 ( & V_51 ) ;
F_28 ( & V_5 -> V_52 , & V_53 ) ;
F_28 ( & V_5 -> V_54 , & V_5 -> V_31 -> V_55 ) ;
F_29 ( & V_51 ) ;
F_30 (pos, &card->devices) {
struct V_11 * V_12 = F_31 ( V_42 ) ;
F_32 ( V_12 ) ;
}
F_33 (pos, temp, &pnp_card_drivers) {
struct V_2 * V_3 =
F_34 ( V_42 , struct V_2 ,
V_52 ) ;
F_8 ( V_5 , V_3 ) ;
}
return 0 ;
}
void F_35 ( struct V_4 * V_5 )
{
struct V_47 * V_42 , * V_48 ;
F_36 ( & V_5 -> V_12 ) ;
F_27 ( & V_51 ) ;
F_37 ( & V_5 -> V_52 ) ;
F_37 ( & V_5 -> V_54 ) ;
F_29 ( & V_51 ) ;
F_33 (pos, temp, &card->devices) {
struct V_11 * V_12 = F_31 ( V_42 ) ;
F_38 ( V_12 ) ;
}
}
int F_39 ( struct V_4 * V_5 , struct V_11 * V_12 )
{
V_12 -> V_12 . V_34 = & V_5 -> V_12 ;
V_12 -> V_15 = NULL ;
F_17 ( & V_12 -> V_12 , L_4 ,
V_12 -> V_31 -> V_33 , V_5 -> V_33 , V_12 -> V_33 ) ;
F_27 ( & V_51 ) ;
V_12 -> V_5 = V_5 ;
F_28 ( & V_12 -> V_56 , & V_5 -> V_57 ) ;
F_29 ( & V_51 ) ;
return 0 ;
}
void F_38 ( struct V_11 * V_12 )
{
F_27 ( & V_51 ) ;
V_12 -> V_5 = NULL ;
F_37 ( & V_12 -> V_56 ) ;
F_29 ( & V_51 ) ;
F_40 ( V_12 ) ;
}
struct V_11 * F_41 ( struct V_18 * V_19 ,
const char * V_8 , struct V_11 * V_58 )
{
struct V_47 * V_42 ;
struct V_11 * V_12 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
if ( ! V_19 || ! V_8 )
return NULL ;
V_5 = V_19 -> V_5 ;
V_3 = V_19 -> V_16 ;
if ( ! V_58 ) {
V_42 = V_5 -> V_57 . V_27 ;
} else {
if ( V_58 -> V_5 != V_5 )
return NULL ;
V_42 = V_58 -> V_56 . V_27 ;
}
while ( V_42 != & V_5 -> V_57 ) {
V_12 = F_31 ( V_42 ) ;
if ( ( ! V_12 -> V_15 ) && F_2 ( V_12 -> V_8 , V_8 ) )
goto V_10;
V_42 = V_42 -> V_27 ;
}
return NULL ;
V_10:
V_12 -> V_15 = V_19 ;
V_12 -> V_12 . V_16 = & V_3 -> V_17 . V_16 ;
if ( V_59 . V_20 ( & V_12 -> V_12 ) )
goto V_60;
if ( F_42 ( & V_12 -> V_12 ) )
goto V_60;
return V_12 ;
V_60:
V_12 -> V_12 . V_16 = NULL ;
V_12 -> V_15 = NULL ;
return NULL ;
}
void F_10 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = V_12 -> V_15 -> V_16 ;
V_3 -> V_17 . remove = & F_4 ;
F_43 ( & V_12 -> V_12 ) ;
V_3 -> V_17 . remove = & F_5 ;
}
static int F_44 ( struct V_11 * V_12 , T_2 V_61 )
{
struct V_18 * V_17 = V_12 -> V_15 ;
if ( V_17 -> V_21 . V_62 == V_61 . V_62 )
return 0 ;
V_17 -> V_21 = V_61 ;
return V_17 -> V_16 -> V_63 ( V_17 , V_61 ) ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_18 * V_17 = V_12 -> V_15 ;
if ( V_17 -> V_21 . V_62 == V_64 )
return 0 ;
V_17 -> V_21 = V_22 ;
V_17 -> V_16 -> V_65 ( V_17 ) ;
return 0 ;
}
int F_46 ( struct V_2 * V_3 )
{
int error ;
struct V_47 * V_42 , * V_48 ;
V_3 -> V_17 . V_41 = V_3 -> V_41 ;
V_3 -> V_17 . V_7 = NULL ;
V_3 -> V_17 . V_66 = V_3 -> V_66 ;
V_3 -> V_17 . V_20 = NULL ;
V_3 -> V_17 . remove = & F_5 ;
V_3 -> V_17 . V_63 = V_3 -> V_63 ? F_44 : NULL ;
V_3 -> V_17 . V_65 = V_3 -> V_65 ? F_45 : NULL ;
error = F_47 ( & V_3 -> V_17 ) ;
if ( error < 0 )
return error ;
F_27 ( & V_51 ) ;
F_28 ( & V_3 -> V_52 , & V_67 ) ;
F_29 ( & V_51 ) ;
F_33 (pos, temp, &pnp_cards) {
struct V_4 * V_5 =
F_34 ( V_42 , struct V_4 , V_52 ) ;
F_8 ( V_5 , V_3 ) ;
}
return 0 ;
}
void F_48 ( struct V_2 * V_3 )
{
F_27 ( & V_51 ) ;
F_37 ( & V_3 -> V_52 ) ;
F_29 ( & V_51 ) ;
F_49 ( & V_3 -> V_17 ) ;
}
