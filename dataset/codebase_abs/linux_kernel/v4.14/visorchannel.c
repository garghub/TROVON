void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_3 ) {
F_2 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
}
F_4 ( V_2 ) ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ;
}
T_2 F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
char * F_7 ( const T_3 * V_7 , char * V_8 )
{
sprintf ( V_8 , L_1 , V_7 ) ;
return V_8 ;
}
char * F_8 ( struct V_1 * V_2 , char * V_8 )
{
return F_7 ( & V_2 -> V_7 , V_8 ) ;
}
char * F_9 ( struct V_1 * V_2 , char * V_8 )
{
return F_7 ( & V_2 -> V_9 . V_10 , V_8 ) ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_9 . V_11 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_11 )
{
V_2 -> V_9 . V_11 = V_11 ;
return 0 ;
}
const T_3 * F_12 ( struct V_1 * V_2 )
{
return & V_2 -> V_7 ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_12 , void * V_13 ,
T_2 V_6 )
{
if ( V_12 + V_6 > V_2 -> V_6 )
return - V_14 ;
memcpy ( V_13 , V_2 -> V_3 + V_12 , V_6 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_12 , void * V_13 ,
T_2 V_6 )
{
T_4 V_15 = sizeof( struct V_16 ) ;
T_4 V_17 ;
if ( V_12 + V_6 > V_2 -> V_6 )
return - V_14 ;
if ( V_12 < V_15 ) {
V_17 = F_15 ( V_15 - V_12 , V_6 ) ;
memcpy ( ( ( char * ) ( & V_2 -> V_9 ) ) + V_12 ,
V_13 , V_17 ) ;
}
memcpy ( V_2 -> V_3 + V_12 , V_13 , V_6 ) ;
return 0 ;
}
void * F_16 ( struct V_1 * V_2 )
{
return & V_2 -> V_9 ;
}
static int F_17 ( struct V_16 * V_9 , int V_18 )
{
return ( ( V_9 ) -> V_19 +
( ( V_18 ) * sizeof( struct V_20 ) ) ) ;
}
static int F_18 ( struct V_16 * V_9 , int V_18 ,
struct V_20 * V_21 , int V_22 )
{
return ( F_17 ( V_9 , V_18 ) + V_21 -> V_23 +
( V_22 * V_21 -> V_24 ) ) ;
}
static int F_19 ( struct V_1 * V_2 , T_5 V_25 ,
struct V_20 * V_21 )
{
if ( V_2 -> V_9 . V_19 < sizeof( struct V_16 ) )
return - V_26 ;
return F_13 ( V_2 ,
F_17 ( & V_2 -> V_9 , V_25 ) ,
V_21 , sizeof( struct V_20 ) ) ;
}
static int F_20 ( struct V_1 * V_2 , T_5 V_25 ,
struct V_20 * V_21 , T_5 V_22 ,
void * V_27 )
{
int V_28 = F_18 ( & V_2 -> V_9 , V_25 ,
V_21 , V_22 ) ;
return F_13 ( V_2 , V_28 ,
V_27 , V_21 -> V_24 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_5 V_25 ,
struct V_20 * V_21 , T_5 V_22 ,
void * V_27 )
{
int V_28 = F_18 ( & V_2 -> V_9 , V_25 ,
V_21 , V_22 ) ;
return F_14 ( V_2 , V_28 ,
V_27 , V_21 -> V_24 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_5 V_25 ,
void * V_29 )
{
struct V_20 V_21 ;
int error ;
error = F_19 ( V_2 , V_25 , & V_21 ) ;
if ( error )
return error ;
if ( V_21 . V_30 == V_21 . V_31 )
return - V_32 ;
V_21 . V_31 = ( V_21 . V_31 + 1 ) % V_21 . V_33 ;
error = F_20 ( V_2 , V_25 , & V_21 , V_21 . V_31 , V_29 ) ;
if ( error )
return error ;
V_21 . V_34 ++ ;
F_23 () ;
error = F_24 ( V_2 , V_25 , & V_21 , V_31 ) ;
if ( error )
return error ;
error = F_24 ( V_2 , V_25 , & V_21 , V_34 ) ;
if ( error )
return error ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_5 V_25 ,
void * V_29 )
{
int V_35 ;
unsigned long V_36 ;
if ( V_2 -> V_37 ) {
F_26 ( & V_2 -> V_38 , V_36 ) ;
V_35 = F_22 ( V_2 , V_25 , V_29 ) ;
F_27 ( & V_2 -> V_38 , V_36 ) ;
} else {
V_35 = F_22 ( V_2 , V_25 , V_29 ) ;
}
return V_35 ;
}
static bool F_28 ( struct V_1 * V_2 , T_5 V_25 )
{
struct V_20 V_21 ;
if ( F_19 ( V_2 , V_25 , & V_21 ) )
return true ;
return ( V_21 . V_30 == V_21 . V_31 ) ;
}
bool F_29 ( struct V_1 * V_2 , T_5 V_25 )
{
bool V_35 ;
unsigned long V_36 ;
if ( ! V_2 -> V_37 )
return F_28 ( V_2 , V_25 ) ;
F_26 ( & V_2 -> V_38 , V_36 ) ;
V_35 = F_28 ( V_2 , V_25 ) ;
F_27 ( & V_2 -> V_38 , V_36 ) ;
return V_35 ;
}
static int F_30 ( struct V_1 * V_2 , T_5 V_25 ,
void * V_29 )
{
struct V_20 V_21 ;
int V_39 ;
V_39 = F_19 ( V_2 , V_25 , & V_21 ) ;
if ( V_39 )
return V_39 ;
V_21 . V_30 = ( V_21 . V_30 + 1 ) % V_21 . V_33 ;
if ( V_21 . V_30 == V_21 . V_31 ) {
V_21 . V_40 ++ ;
V_39 = F_24 ( V_2 , V_25 , & V_21 , V_40 ) ;
if ( V_39 )
return V_39 ;
return - V_14 ;
}
V_39 = F_21 ( V_2 , V_25 , & V_21 , V_21 . V_30 , V_29 ) ;
if ( V_39 )
return V_39 ;
V_21 . V_41 ++ ;
F_23 () ;
V_39 = F_24 ( V_2 , V_25 , & V_21 , V_30 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_24 ( V_2 , V_25 , & V_21 , V_41 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
static struct V_1 * F_31 ( T_1 V_5 , T_6 V_42 ,
const T_3 * V_7 ,
bool V_37 )
{
struct V_1 * V_2 ;
int V_39 ;
T_4 V_43 = sizeof( struct V_16 ) ;
if ( V_5 == 0 )
return NULL ;
V_2 = F_32 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_37 = V_37 ;
F_33 ( & V_2 -> V_44 ) ;
F_33 ( & V_2 -> V_38 ) ;
V_2 -> V_4 = F_34 ( V_5 , V_43 , V_45 ) ;
if ( ! V_2 -> V_4 && ! F_35 ( V_7 , & V_46 ) )
goto V_47;
V_2 -> V_3 = F_36 ( V_5 , V_43 , V_48 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_5 , V_43 ) ;
goto V_47;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_43 ;
V_39 = F_13 ( V_2 , 0 , & V_2 -> V_9 , V_43 ) ;
if ( V_39 )
goto V_47;
V_43 = ( T_2 ) V_2 -> V_9 . V_43 ;
F_2 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = F_34 ( V_2 -> V_5 , V_43 ,
V_45 ) ;
if ( ! V_2 -> V_4 && ! F_35 ( V_7 , & V_46 ) )
goto V_47;
V_2 -> V_3 = F_36 ( V_2 -> V_5 , V_43 , V_48 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_2 -> V_5 , V_43 ) ;
goto V_47;
}
V_2 -> V_6 = V_43 ;
F_37 ( & V_2 -> V_7 , V_7 ) ;
return V_2 ;
V_47:
F_1 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_38 ( T_1 V_5 , T_6 V_42 ,
const T_3 * V_7 )
{
return F_31 ( V_5 , V_42 , V_7 , false ) ;
}
struct V_1 * F_39 ( T_1 V_5 , T_6 V_42 ,
const T_3 * V_7 )
{
return F_31 ( V_5 , V_42 , V_7 , true ) ;
}
int F_40 ( struct V_1 * V_2 , T_5 V_25 ,
void * V_29 )
{
int V_35 ;
unsigned long V_36 ;
if ( V_2 -> V_37 ) {
F_26 ( & V_2 -> V_44 , V_36 ) ;
V_35 = F_30 ( V_2 , V_25 , V_29 ) ;
F_27 ( & V_2 -> V_44 , V_36 ) ;
} else {
V_35 = F_30 ( V_2 , V_25 , V_29 ) ;
}
return V_35 ;
}
