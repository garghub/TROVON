static int
F_1 ( struct V_1 * V_2 )
{
struct F_1 * V_3 = F_2 ( V_2 , F_3 ( * V_3 ) , V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
return V_5 -> V_6 ( & V_3 -> V_7 , V_3 -> V_8 , V_2 -> V_9 , V_2 -> V_8 ) ;
}
int
F_4 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_6 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
return 0 ;
}
}
return - V_11 ;
}
int
F_7 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_8 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
return 0 ;
}
}
return - V_11 ;
}
int
F_9 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_10 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
F_11 ( V_5 -> V_3 [ V_10 ] ) ;
V_5 -> V_3 [ V_10 ] = NULL ;
return 0 ;
}
}
return - V_11 ;
}
int
F_12 ( struct V_12 * V_13 ,
struct V_14 * V_15 , void * V_9 , T_1 V_8 )
{
struct V_4 * V_5 = V_13 -> V_5 ;
struct F_1 * V_3 ;
union {
struct V_16 V_17 ;
} * V_18 = V_9 ;
T_2 V_10 , V_19 ;
int V_20 = - V_21 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_5 -> V_3 ) ; V_10 ++ ) {
if ( ! V_5 -> V_3 [ V_10 ] )
break;
}
if ( V_10 == F_5 ( V_5 -> V_3 ) )
return - V_22 ;
V_3 = F_13 ( sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 )
return - V_24 ;
F_14 ( V_13 , L_1 , V_8 ) ;
if ( ! ( V_20 = F_15 ( V_20 , & V_9 , & V_8 , V_18 -> V_17 , 0 , 0 , true ) ) ) {
F_14 ( V_13 , L_2
L_3 , V_18 -> V_17 . V_25 ,
V_18 -> V_17 . V_19 , V_18 -> V_17 . V_26 , V_18 -> V_17 . V_27 ) ;
V_3 -> V_25 = V_18 -> V_17 . V_25 ;
V_3 -> V_8 = sizeof( V_3 -> V_7 . V_17 ) ;
V_3 -> V_7 . V_17 . V_25 = V_18 -> V_17 . V_25 ;
V_3 -> V_7 . V_17 . V_26 = V_18 -> V_17 . V_26 ;
V_3 -> V_7 . V_17 . V_27 = V_18 -> V_17 . V_27 ;
V_19 = V_18 -> V_17 . V_19 ;
}
if ( V_20 == 0 ) {
V_20 = F_16 ( V_13 , V_15 , F_1 ,
false , V_9 , V_8 , V_19 , & V_3 -> V_2 ) ;
if ( V_20 == 0 ) {
V_5 -> V_3 [ V_10 ] = V_3 ;
V_3 -> V_5 = V_5 ;
return V_10 ;
}
}
F_11 ( V_3 ) ;
return V_20 ;
}
static int
F_17 ( struct V_12 * V_13 , void * V_9 , T_1 V_8 )
{
union {
struct V_28 V_17 ;
} * args = V_9 ;
int V_20 = - V_21 ;
F_14 ( V_13 , L_4 , V_8 ) ;
if ( ! ( V_20 = F_15 ( V_20 , & V_9 , & V_8 , args -> V_17 , 0 , 0 , true ) ) ) {
F_14 ( V_13 , L_5 ,
args -> V_17 . V_25 , args -> V_17 . V_29 ) ;
if ( V_8 == sizeof( args -> V_17 . V_30 [ 0 ] ) * args -> V_17 . V_29 ) {
V_20 = F_18 ( args -> V_17 . V_30 , args -> V_17 . V_29 ) ;
if ( V_20 >= 0 ) {
args -> V_17 . V_29 = V_20 ;
V_20 = 0 ;
}
} else {
V_20 = - V_31 ;
}
}
return V_20 ;
}
static int
F_19 ( struct V_12 * V_13 , T_1 V_32 , void * V_9 , T_1 V_8 )
{
switch ( V_32 ) {
case V_33 :
return F_17 ( V_13 , V_9 , V_8 ) ;
default:
break;
}
return - V_31 ;
}
static int
F_20 ( const struct V_34 * V_35 ,
void * V_9 , T_1 V_8 , struct V_12 * * V_36 )
{
return V_35 -> V_37 . V_38 ( V_35 , V_9 , V_8 , V_36 ) ;
}
static int
F_21 ( struct V_12 * V_13 , int V_10 ,
struct V_34 * V_35 )
{
const struct V_39 * V_40 ;
switch ( V_10 ) {
case 0 : V_40 = & V_41 ; break;
default:
return - V_31 ;
}
V_35 -> V_38 = F_20 ;
V_35 -> V_37 = * V_40 ;
return 0 ;
}
void
F_22 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
if ( ! F_23 ( & V_13 -> V_42 ) )
F_24 ( & V_13 -> V_42 , & V_5 -> V_43 ) ;
}
bool
F_25 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_44 * * V_45 = & V_5 -> V_43 . V_44 ;
struct V_44 * V_46 = NULL ;
while ( * V_45 ) {
struct V_12 * V_47 =
F_2 ( * V_45 , F_3 ( * V_47 ) , V_42 ) ;
V_46 = * V_45 ;
if ( V_13 -> V_13 < V_47 -> V_13 )
V_45 = & V_46 -> V_48 ;
else
if ( V_13 -> V_13 > V_47 -> V_13 )
V_45 = & V_46 -> V_49 ;
else
return false ;
}
F_26 ( & V_13 -> V_42 , V_46 , V_45 ) ;
F_27 ( & V_13 -> V_42 , & V_5 -> V_43 ) ;
return true ;
}
struct V_12 *
F_28 ( struct V_4 * V_5 , T_3 V_50 )
{
struct V_44 * V_42 = V_5 -> V_43 . V_44 ;
while ( V_42 ) {
struct V_12 * V_13 =
F_2 ( V_42 , F_3 ( * V_13 ) , V_42 ) ;
if ( V_50 < V_13 -> V_13 )
V_42 = V_42 -> V_48 ;
else
if ( V_50 > V_13 -> V_13 )
V_42 = V_42 -> V_49 ;
else
return V_13 ;
}
return NULL ;
}
int
F_29 ( struct V_4 * V_5 , bool V_51 )
{
struct V_12 * V_13 = & V_5 -> V_13 ;
const char * V_52 [ 2 ] = { L_6 , L_7 } ;
int V_53 ;
F_30 ( V_13 , L_8 , V_52 [ V_51 ] ) ;
for ( V_53 = 0 ; V_53 < F_5 ( V_5 -> V_3 ) ; V_53 ++ )
F_4 ( V_5 , V_53 ) ;
return F_31 ( & V_5 -> V_13 , V_51 ) ;
}
int
F_32 ( struct V_4 * V_5 )
{
return F_33 ( & V_5 -> V_13 ) ;
}
void
F_34 ( struct V_4 * * V_54 )
{
struct V_4 * V_5 = * V_54 ;
int V_53 ;
if ( V_5 ) {
F_29 ( V_5 , false ) ;
for ( V_53 = 0 ; V_53 < F_5 ( V_5 -> V_3 ) ; V_53 ++ )
F_9 ( V_5 , V_53 ) ;
F_35 ( & V_5 -> V_13 ) ;
F_11 ( * V_54 ) ;
* V_54 = NULL ;
}
}
int
F_36 ( const char * V_52 , T_3 V_30 , const char * V_55 ,
const char * V_56 , struct V_4 * * V_54 )
{
struct V_34 V_35 = {} ;
struct V_4 * V_5 ;
if ( ! ( V_5 = * V_54 = F_13 ( sizeof( * V_5 ) , V_23 ) ) )
return - V_24 ;
V_35 . V_5 = V_5 ;
F_37 ( & V_57 , & V_35 , & V_5 -> V_13 ) ;
snprintf ( V_5 -> V_52 , sizeof( V_5 -> V_52 ) , L_9 , V_52 ) ;
V_5 -> V_30 = V_30 ;
V_5 -> V_58 = F_38 ( V_56 , L_10 ) ;
V_5 -> V_43 = V_59 ;
V_5 -> V_60 = V_59 ;
return 0 ;
}
