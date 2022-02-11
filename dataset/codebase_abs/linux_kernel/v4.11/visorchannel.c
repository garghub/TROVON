void
F_1 ( struct V_1 * V_2 )
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
T_1
F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ;
}
T_2
F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
char *
F_7 ( T_3 * V_7 , char * V_8 )
{
sprintf ( V_8 , L_1 , V_7 ) ;
return V_8 ;
}
char *
F_8 ( struct V_1 * V_2 , char * V_8 )
{
return F_7 ( & V_2 -> V_7 , V_8 ) ;
}
char *
F_9 ( struct V_1 * V_2 , char * V_8 )
{
return F_7 ( & V_2 -> V_9 . V_10 , V_8 ) ;
}
T_1
F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_9 . V_11 ;
}
int
F_11 ( struct V_1 * V_2 ,
T_1 V_11 )
{
V_2 -> V_9 . V_11 = V_11 ;
return 0 ;
}
T_3
F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
int
F_13 ( struct V_1 * V_2 , T_2 V_12 ,
void * V_13 , T_2 V_6 )
{
if ( V_12 + V_6 > V_2 -> V_6 )
return - V_14 ;
memcpy ( V_13 , V_2 -> V_3 + V_12 , V_6 ) ;
return 0 ;
}
int
F_14 ( struct V_1 * V_2 , T_2 V_12 ,
void * V_13 , T_2 V_6 )
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
void T_5 *
F_16 ( struct V_1 * V_2 )
{
return ( void T_5 * ) & V_2 -> V_9 ;
}
static int
F_17 ( struct V_1 * V_2 , T_6 V_18 ,
struct V_19 * V_20 )
{
if ( V_2 -> V_9 . V_21 < sizeof( struct V_16 ) )
return - V_22 ;
return F_13 ( V_2 ,
F_18 ( & V_2 -> V_9 , V_18 ) ,
V_20 , sizeof( struct V_19 ) ) ;
}
static inline int
F_19 ( struct V_1 * V_2 , T_6 V_18 ,
struct V_19 * V_20 , T_6 V_23 , void * V_24 )
{
int V_25 = F_20 ( & V_2 -> V_9 , V_18 ,
V_20 , V_23 ) ;
return F_13 ( V_2 , V_25 ,
V_24 , V_20 -> V_26 ) ;
}
static inline int
F_21 ( struct V_1 * V_2 , T_6 V_18 ,
struct V_19 * V_20 , T_6 V_23 , void * V_24 )
{
int V_25 = F_20 ( & V_2 -> V_9 , V_18 ,
V_20 , V_23 ) ;
return F_14 ( V_2 , V_25 ,
V_24 , V_20 -> V_26 ) ;
}
static int
F_22 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
struct V_19 V_20 ;
int error ;
error = F_17 ( V_2 , V_18 , & V_20 ) ;
if ( error )
return error ;
if ( V_20 . V_28 == V_20 . V_29 )
return - V_30 ;
V_20 . V_29 = ( V_20 . V_29 + 1 ) % V_20 . V_31 ;
error = F_19 ( V_2 , V_18 , & V_20 , V_20 . V_29 , V_27 ) ;
if ( error )
return error ;
V_20 . V_32 ++ ;
F_23 () ;
error = F_24 ( V_2 , V_18 , & V_20 , V_29 ) ;
if ( error )
return error ;
error = F_24 ( V_2 , V_18 , & V_20 , V_32 ) ;
if ( error )
return error ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
int V_33 ;
unsigned long V_34 ;
if ( V_2 -> V_35 ) {
F_26 ( & V_2 -> V_36 , V_34 ) ;
V_33 = F_22 ( V_2 , V_18 , V_27 ) ;
F_27 ( & V_2 -> V_36 , V_34 ) ;
} else {
V_33 = F_22 ( V_2 , V_18 , V_27 ) ;
}
return V_33 ;
}
static bool
F_28 ( struct V_1 * V_2 , T_6 V_18 )
{
struct V_19 V_20 ;
if ( F_17 ( V_2 , V_18 , & V_20 ) )
return true ;
return ( V_20 . V_28 == V_20 . V_29 ) ;
}
bool
F_29 ( struct V_1 * V_2 , T_6 V_18 )
{
bool V_33 ;
unsigned long V_34 ;
if ( ! V_2 -> V_35 )
return F_28 ( V_2 , V_18 ) ;
F_26 ( & V_2 -> V_36 , V_34 ) ;
V_33 = F_28 ( V_2 , V_18 ) ;
F_27 ( & V_2 -> V_36 , V_34 ) ;
return V_33 ;
}
static int
F_30 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
struct V_19 V_20 ;
int error ;
error = F_17 ( V_2 , V_18 , & V_20 ) ;
if ( error )
return error ;
V_20 . V_28 = ( V_20 . V_28 + 1 ) % V_20 . V_31 ;
if ( V_20 . V_28 == V_20 . V_29 ) {
V_20 . V_37 ++ ;
F_14 ( V_2 ,
F_18 ( & V_2 -> V_9 , V_18 ) +
F_31 ( struct V_19 ,
V_37 ) ,
& V_20 . V_37 ,
sizeof( V_20 . V_37 ) ) ;
return - V_14 ;
}
error = F_21 ( V_2 , V_18 , & V_20 , V_20 . V_28 , V_27 ) ;
if ( error )
return error ;
V_20 . V_38 ++ ;
F_23 () ;
error = F_24 ( V_2 , V_18 , & V_20 , V_28 ) ;
if ( error )
return error ;
error = F_24 ( V_2 , V_18 , & V_20 , V_38 ) ;
if ( error )
return error ;
return 0 ;
}
static struct V_1 *
F_32 ( T_1 V_5 , unsigned long V_39 ,
T_7 V_40 , T_3 V_7 , bool V_35 )
{
struct V_1 * V_2 ;
int V_41 ;
T_4 V_42 = sizeof( struct V_16 ) ;
if ( V_5 == 0 )
return NULL ;
V_2 = F_33 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_35 = V_35 ;
F_34 ( & V_2 -> V_43 ) ;
F_34 ( & V_2 -> V_36 ) ;
V_2 -> V_4 = F_35 ( V_5 , V_42 , V_44 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_36 ( V_7 , V_45 ) ) {
goto V_46;
}
}
V_2 -> V_3 = F_37 ( V_5 , V_42 , V_47 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_5 , V_42 ) ;
goto V_46;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_42 ;
V_41 = F_13 ( V_2 , 0 , & V_2 -> V_9 ,
sizeof( struct V_16 ) ) ;
if ( V_41 )
goto V_46;
if ( V_39 == 0 )
V_39 = ( T_2 ) V_2 -> V_9 . V_42 ;
if ( F_36 ( V_7 , V_48 ) == 0 )
V_7 = V_2 -> V_9 . V_49 ;
F_2 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = F_35 ( V_2 -> V_5 ,
V_39 , V_44 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_36 ( V_7 , V_45 ) ) {
goto V_46;
}
}
V_2 -> V_3 = F_37 ( V_2 -> V_5 , V_39 ,
V_47 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_2 -> V_5 , V_39 ) ;
goto V_46;
}
V_2 -> V_6 = V_39 ;
V_2 -> V_7 = V_7 ;
return V_2 ;
V_46:
F_1 ( V_2 ) ;
return NULL ;
}
struct V_1 *
F_38 ( T_1 V_5 , unsigned long V_39 ,
T_7 V_40 , T_3 V_7 )
{
return F_32 ( V_5 , V_39 , V_40 , V_7 ,
false ) ;
}
struct V_1 *
F_39 ( T_1 V_5 , unsigned long V_39 ,
T_7 V_40 , T_3 V_7 )
{
return F_32 ( V_5 , V_39 , V_40 , V_7 ,
true ) ;
}
int
F_40 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
int V_33 ;
unsigned long V_34 ;
if ( V_2 -> V_35 ) {
F_26 ( & V_2 -> V_43 , V_34 ) ;
V_33 = F_30 ( V_2 , V_18 , V_27 ) ;
F_27 ( & V_2 -> V_43 , V_34 ) ;
} else {
V_33 = F_30 ( V_2 , V_18 , V_27 ) ;
}
return V_33 ;
}
