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
int V_20 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_5 -> V_3 ) ; V_10 ++ ) {
if ( ! V_5 -> V_3 [ V_10 ] )
break;
}
if ( V_10 == F_5 ( V_5 -> V_3 ) )
return - V_21 ;
V_3 = F_13 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return - V_23 ;
F_14 ( V_13 , L_1 , V_8 ) ;
if ( F_15 ( V_18 -> V_17 , 0 , 0 , true ) ) {
F_14 ( V_13 , L_2
L_3 , V_18 -> V_17 . V_24 ,
V_18 -> V_17 . V_19 , V_18 -> V_17 . V_25 , V_18 -> V_17 . V_26 ) ;
V_3 -> V_24 = V_18 -> V_17 . V_24 ;
V_3 -> V_8 = sizeof( V_3 -> V_7 . V_17 ) ;
V_3 -> V_7 . V_17 . V_24 = V_18 -> V_17 . V_24 ;
V_3 -> V_7 . V_17 . V_25 = V_18 -> V_17 . V_25 ;
V_3 -> V_7 . V_17 . V_26 = V_18 -> V_17 . V_26 ;
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
struct V_27 V_17 ;
} * args = V_9 ;
int V_20 ;
F_14 ( V_13 , L_4 , V_8 ) ;
if ( F_15 ( args -> V_17 , 0 , 0 , true ) ) {
F_14 ( V_13 , L_5 ,
args -> V_17 . V_24 , args -> V_17 . V_28 ) ;
if ( V_8 == sizeof( args -> V_17 . V_29 [ 0 ] ) * args -> V_17 . V_28 ) {
V_20 = F_18 ( args -> V_17 . V_29 , args -> V_17 . V_28 ) ;
if ( V_20 >= 0 ) {
args -> V_17 . V_28 = V_20 ;
V_20 = 0 ;
}
} else {
V_20 = - V_30 ;
}
}
return V_20 ;
}
static int
F_19 ( struct V_12 * V_13 , T_1 V_31 , void * V_9 , T_1 V_8 )
{
switch ( V_31 ) {
case V_32 :
return F_17 ( V_13 , V_9 , V_8 ) ;
default:
break;
}
return - V_30 ;
}
static int
F_20 ( const struct V_33 * V_34 ,
void * V_9 , T_1 V_8 , struct V_12 * * V_35 )
{
return V_34 -> V_36 . V_37 ( V_34 , V_9 , V_8 , V_35 ) ;
}
static int
F_21 ( struct V_12 * V_13 , int V_10 ,
struct V_33 * V_34 )
{
const struct V_38 * V_39 ;
switch ( V_10 ) {
case 0 : V_39 = & V_40 ; break;
default:
return - V_30 ;
}
V_34 -> V_37 = F_20 ;
V_34 -> V_36 = * V_39 ;
return 0 ;
}
void
F_22 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
if ( ! F_23 ( & V_13 -> V_41 ) )
F_24 ( & V_13 -> V_41 , & V_5 -> V_42 ) ;
}
bool
F_25 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_43 * * V_44 = & V_5 -> V_42 . V_43 ;
struct V_43 * V_45 = NULL ;
while ( * V_44 ) {
struct V_12 * V_46 =
F_2 ( * V_44 , F_3 ( * V_46 ) , V_41 ) ;
V_45 = * V_44 ;
if ( V_13 -> V_13 < V_46 -> V_13 )
V_44 = & V_45 -> V_47 ;
else
if ( V_13 -> V_13 > V_46 -> V_13 )
V_44 = & V_45 -> V_48 ;
else
return false ;
}
F_26 ( & V_13 -> V_41 , V_45 , V_44 ) ;
F_27 ( & V_13 -> V_41 , & V_5 -> V_42 ) ;
return true ;
}
struct V_12 *
F_28 ( struct V_4 * V_5 , T_3 V_49 )
{
struct V_43 * V_41 = V_5 -> V_42 . V_43 ;
while ( V_41 ) {
struct V_12 * V_13 =
F_2 ( V_41 , F_3 ( * V_13 ) , V_41 ) ;
if ( V_49 < V_13 -> V_13 )
V_41 = V_41 -> V_47 ;
else
if ( V_49 > V_13 -> V_13 )
V_41 = V_41 -> V_48 ;
else
return V_13 ;
}
return NULL ;
}
int
F_29 ( struct V_4 * V_5 , bool V_50 )
{
struct V_12 * V_13 = & V_5 -> V_13 ;
const char * V_51 [ 2 ] = { L_6 , L_7 } ;
int V_52 ;
F_30 ( V_13 , L_8 , V_51 [ V_50 ] ) ;
for ( V_52 = 0 ; V_52 < F_5 ( V_5 -> V_3 ) ; V_52 ++ )
F_4 ( V_5 , V_52 ) ;
return F_31 ( & V_5 -> V_13 , V_50 ) ;
}
int
F_32 ( struct V_4 * V_5 )
{
return F_33 ( & V_5 -> V_13 ) ;
}
void
F_34 ( struct V_4 * * V_53 )
{
struct V_4 * V_5 = * V_53 ;
int V_52 ;
if ( V_5 ) {
F_29 ( V_5 , false ) ;
for ( V_52 = 0 ; V_52 < F_5 ( V_5 -> V_3 ) ; V_52 ++ )
F_9 ( V_5 , V_52 ) ;
F_35 ( & V_5 -> V_13 ) ;
F_11 ( * V_53 ) ;
* V_53 = NULL ;
}
}
int
F_36 ( const char * V_51 , T_3 V_29 , const char * V_54 ,
const char * V_55 , struct V_4 * * V_53 )
{
struct V_33 V_34 = {} ;
struct V_4 * V_5 ;
if ( ! ( V_5 = * V_53 = F_13 ( sizeof( * V_5 ) , V_22 ) ) )
return - V_23 ;
V_34 . V_5 = V_5 ;
F_37 ( & V_56 , & V_34 , & V_5 -> V_13 ) ;
snprintf ( V_5 -> V_51 , sizeof( V_5 -> V_51 ) , L_9 , V_51 ) ;
V_5 -> V_29 = V_29 ;
V_5 -> V_57 = F_38 ( V_55 , L_10 ) ;
V_5 -> V_42 = V_58 ;
V_5 -> V_59 = V_58 ;
return 0 ;
}
