static struct V_1 * F_1 ( const char * V_2 )
{
int V_3 = 0 ;
while ( V_4 [ V_3 ] ) {
if ( F_2 ( V_2 , V_4 [ V_3 ] -> V_5 ) )
break;
V_3 ++ ;
}
return V_4 [ V_3 ] ;
}
static void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( V_9 -> V_10 )
V_7 -> V_11 -> V_12 ( V_9 -> V_10 ) ;
F_4 ( ( unsigned long ) V_9 -> V_13 , 1 ) ;
F_5 ( V_9 ) ;
}
static struct V_8 * F_6 ( struct V_6 * V_7 , T_1 V_14 )
{
struct V_8 * V_9 = F_7 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_10 = V_7 -> V_11 -> V_15 ( V_14 ) ;
V_9 -> V_13 = ( void * ) F_8 ( V_14 | V_16 , 1 ) ;
if ( ! V_9 -> V_10 || ! V_9 -> V_13 ) {
F_3 ( V_7 , V_9 ) ;
V_9 = NULL ;
}
return V_9 ;
}
static struct V_8 * F_9 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_8 * V_9 ;
while ( 1 ) {
F_10 ( & V_18 -> V_20 ) ;
if ( ! F_11 ( & V_18 -> V_21 ) ) {
V_9 = F_12 ( V_18 -> V_21 . V_22 ,
struct V_8 , V_23 ) ;
F_13 ( & V_9 -> V_23 ) ;
F_14 ( & V_18 -> V_20 ) ;
return V_9 ;
}
if ( V_18 -> V_24 >= V_18 -> V_25 ) {
F_14 ( & V_18 -> V_20 ) ;
F_15 ( V_18 -> V_26 , ! F_11 ( & V_18 -> V_21 ) ) ;
continue;
}
V_18 -> V_24 ++ ;
F_14 ( & V_18 -> V_20 ) ;
V_9 = F_6 ( V_7 , V_27 | V_28 |
V_29 ) ;
if ( ! V_9 ) {
F_10 ( & V_18 -> V_20 ) ;
V_18 -> V_24 -- ;
F_14 ( & V_18 -> V_20 ) ;
F_15 ( V_18 -> V_26 , ! F_11 ( & V_18 -> V_21 ) ) ;
continue;
}
break;
}
return V_9 ;
}
static void F_16 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
F_10 ( & V_18 -> V_20 ) ;
if ( V_18 -> V_24 <= V_18 -> V_25 ) {
F_17 ( & V_9 -> V_23 , & V_18 -> V_21 ) ;
F_14 ( & V_18 -> V_20 ) ;
F_18 ( & V_18 -> V_26 ) ;
return;
}
V_18 -> V_24 -- ;
F_14 ( & V_18 -> V_20 ) ;
F_3 ( V_7 , V_9 ) ;
}
static bool F_19 ( struct V_6 * V_7 , int V_30 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_8 * V_9 ;
F_10 ( & V_18 -> V_20 ) ;
V_18 -> V_25 = V_30 ;
while ( V_18 -> V_24 > V_30 && ! F_11 ( & V_18 -> V_21 ) ) {
V_9 = F_12 ( V_18 -> V_21 . V_22 ,
struct V_8 , V_23 ) ;
F_13 ( & V_9 -> V_23 ) ;
F_3 ( V_7 , V_9 ) ;
V_18 -> V_24 -- ;
}
F_14 ( & V_18 -> V_20 ) ;
return true ;
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_8 * V_9 ;
while ( ! F_11 ( & V_18 -> V_21 ) ) {
V_9 = F_12 ( V_18 -> V_21 . V_22 ,
struct V_8 , V_23 ) ;
F_13 ( & V_9 -> V_23 ) ;
F_3 ( V_7 , V_9 ) ;
}
F_5 ( V_18 ) ;
}
static int F_21 ( struct V_6 * V_7 , int V_25 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 ;
V_7 -> V_12 = F_20 ;
V_7 -> V_31 = F_9 ;
V_7 -> V_32 = F_16 ;
V_7 -> V_33 = F_19 ;
V_18 = F_7 ( sizeof( struct V_17 ) , V_34 ) ;
if ( ! V_18 )
return - V_35 ;
V_7 -> V_19 = V_18 ;
F_22 ( & V_18 -> V_20 ) ;
F_23 ( & V_18 -> V_21 ) ;
F_24 ( & V_18 -> V_26 ) ;
V_18 -> V_25 = V_25 ;
V_18 -> V_24 = 1 ;
V_9 = F_6 ( V_7 , V_34 ) ;
if ( ! V_9 ) {
F_5 ( V_18 ) ;
return - V_35 ;
}
F_17 ( & V_9 -> V_23 , & V_18 -> V_21 ) ;
return 0 ;
}
static struct V_8 * F_25 ( struct V_6 * V_7 )
{
struct V_36 * V_18 = V_7 -> V_19 ;
F_26 ( & V_18 -> V_20 ) ;
return V_18 -> V_9 ;
}
static void F_27 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_36 * V_18 = V_7 -> V_19 ;
F_28 ( & V_18 -> V_20 ) ;
}
static bool F_29 ( struct V_6 * V_7 , int V_30 )
{
return false ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_36 * V_18 = V_7 -> V_19 ;
F_3 ( V_7 , V_18 -> V_9 ) ;
F_5 ( V_18 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_36 * V_18 ;
V_7 -> V_12 = F_30 ;
V_7 -> V_31 = F_25 ;
V_7 -> V_32 = F_27 ;
V_7 -> V_33 = F_29 ;
V_18 = F_7 ( sizeof( struct V_36 ) , V_34 ) ;
if ( ! V_18 )
return - V_35 ;
V_7 -> V_19 = V_18 ;
F_32 ( & V_18 -> V_20 ) ;
V_18 -> V_9 = F_6 ( V_7 , V_34 ) ;
if ( ! V_18 -> V_9 ) {
F_5 ( V_18 ) ;
return - V_35 ;
}
return 0 ;
}
T_2 F_33 ( const char * V_7 , char * V_37 )
{
T_2 V_38 = 0 ;
int V_3 = 0 ;
while ( V_4 [ V_3 ] ) {
if ( ! strcmp ( V_7 , V_4 [ V_3 ] -> V_5 ) )
V_38 += F_34 ( V_37 + V_38 , V_39 - V_38 - 2 ,
L_1 , V_4 [ V_3 ] -> V_5 ) ;
else
V_38 += F_34 ( V_37 + V_38 , V_39 - V_38 - 2 ,
L_2 , V_4 [ V_3 ] -> V_5 ) ;
V_3 ++ ;
}
V_38 += F_34 ( V_37 + V_38 , V_39 - V_38 , L_3 ) ;
return V_38 ;
}
bool F_35 ( const char * V_7 )
{
return F_1 ( V_7 ) != NULL ;
}
bool F_36 ( struct V_6 * V_7 , int V_30 )
{
return V_7 -> V_33 ( V_7 , V_30 ) ;
}
struct V_8 * F_37 ( struct V_6 * V_7 )
{
return V_7 -> V_31 ( V_7 ) ;
}
void F_38 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> V_32 ( V_7 , V_9 ) ;
}
int F_39 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const unsigned char * V_40 , T_3 * V_41 )
{
return V_7 -> V_11 -> V_2 ( V_40 , V_9 -> V_13 , V_41 ,
V_9 -> V_10 ) ;
}
int F_40 ( struct V_6 * V_7 , const unsigned char * V_40 ,
T_3 V_42 , unsigned char * V_43 )
{
return V_7 -> V_11 -> V_44 ( V_40 , V_42 , V_43 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
V_7 -> V_12 ( V_7 ) ;
F_5 ( V_7 ) ;
}
struct V_6 * F_42 ( const char * V_2 , int V_25 )
{
struct V_6 * V_7 ;
struct V_1 * V_11 ;
int error ;
V_11 = F_1 ( V_2 ) ;
if ( ! V_11 )
return F_43 ( - V_45 ) ;
V_7 = F_44 ( sizeof( struct V_6 ) , V_34 ) ;
if ( ! V_7 )
return F_43 ( - V_35 ) ;
V_7 -> V_11 = V_11 ;
if ( V_25 > 1 )
error = F_21 ( V_7 , V_25 ) ;
else
error = F_31 ( V_7 ) ;
if ( error ) {
F_5 ( V_7 ) ;
return F_43 ( error ) ;
}
return V_7 ;
}
