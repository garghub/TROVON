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
return - V_14 ;
V_20 . V_29 = ( V_20 . V_29 + 1 ) % V_20 . V_30 ;
error = F_19 ( V_2 , V_18 , & V_20 , V_20 . V_29 , V_27 ) ;
if ( error )
return error ;
V_20 . V_31 ++ ;
F_23 () ;
error = F_24 ( V_2 , V_18 , & V_20 , V_29 ) ;
if ( error )
return error ;
error = F_24 ( V_2 , V_18 , & V_20 , V_31 ) ;
if ( error )
return error ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
int V_32 ;
unsigned long V_33 ;
if ( V_2 -> V_34 ) {
F_26 ( & V_2 -> V_35 , V_33 ) ;
V_32 = F_22 ( V_2 , V_18 , V_27 ) ;
F_27 ( & V_2 -> V_35 , V_33 ) ;
} else {
V_32 = F_22 ( V_2 , V_18 , V_27 ) ;
}
return V_32 ;
}
bool
F_28 ( struct V_1 * V_2 , T_6 V_18 )
{
unsigned long V_33 = 0 ;
struct V_19 V_20 ;
bool V_32 = false ;
if ( V_2 -> V_34 )
F_26 ( & V_2 -> V_35 , V_33 ) ;
if ( F_17 ( V_2 , V_18 , & V_20 ) )
V_32 = true ;
if ( V_20 . V_28 == V_20 . V_29 )
V_32 = true ;
if ( V_2 -> V_34 )
F_27 ( & V_2 -> V_35 , V_33 ) ;
return V_32 ;
}
static int
F_29 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
struct V_19 V_20 ;
int error ;
error = F_17 ( V_2 , V_18 , & V_20 ) ;
if ( error )
return error ;
V_20 . V_28 = ( V_20 . V_28 + 1 ) % V_20 . V_30 ;
if ( V_20 . V_28 == V_20 . V_29 ) {
V_20 . V_36 ++ ;
F_14 ( V_2 ,
F_18 ( & V_2 -> V_9 , V_18 ) +
F_30 ( struct V_19 ,
V_36 ) ,
& V_20 . V_36 ,
sizeof( V_20 . V_36 ) ) ;
return - V_14 ;
}
error = F_21 ( V_2 , V_18 , & V_20 , V_20 . V_28 , V_27 ) ;
if ( error )
return error ;
V_20 . V_37 ++ ;
F_23 () ;
error = F_24 ( V_2 , V_18 , & V_20 , V_28 ) ;
if ( error )
return error ;
error = F_24 ( V_2 , V_18 , & V_20 , V_37 ) ;
if ( error )
return error ;
return 0 ;
}
static struct V_1 *
F_31 ( T_1 V_5 , unsigned long V_38 ,
T_7 V_39 , T_3 V_7 , bool V_34 )
{
struct V_1 * V_2 ;
int V_40 ;
T_4 V_41 = sizeof( struct V_16 ) ;
if ( V_5 == 0 )
return NULL ;
V_2 = F_32 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_34 = V_34 ;
F_33 ( & V_2 -> V_42 ) ;
F_33 ( & V_2 -> V_35 ) ;
V_2 -> V_4 = F_34 ( V_5 , V_41 , V_43 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_35 ( V_7 , V_44 ) ) {
goto V_45;
}
}
V_2 -> V_3 = F_36 ( V_5 , V_41 , V_46 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_5 , V_41 ) ;
goto V_45;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_41 ;
V_40 = F_13 ( V_2 , 0 , & V_2 -> V_9 ,
sizeof( struct V_16 ) ) ;
if ( V_40 )
goto V_45;
if ( V_38 == 0 )
V_38 = ( T_2 ) V_2 -> V_9 . V_41 ;
if ( F_35 ( V_7 , V_47 ) == 0 )
V_7 = V_2 -> V_9 . V_48 ;
F_2 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = F_34 ( V_2 -> V_5 ,
V_38 , V_43 ) ;
if ( ! V_2 -> V_4 ) {
if ( F_35 ( V_7 , V_44 ) ) {
goto V_45;
}
}
V_2 -> V_3 = F_36 ( V_2 -> V_5 , V_38 ,
V_46 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_2 -> V_5 , V_38 ) ;
goto V_45;
}
V_2 -> V_6 = V_38 ;
V_2 -> V_7 = V_7 ;
return V_2 ;
V_45:
F_1 ( V_2 ) ;
return NULL ;
}
struct V_1 *
F_37 ( T_1 V_5 , unsigned long V_38 ,
T_7 V_39 , T_3 V_7 )
{
return F_31 ( V_5 , V_38 , V_39 , V_7 ,
false ) ;
}
struct V_1 *
F_38 ( T_1 V_5 , unsigned long V_38 ,
T_7 V_39 , T_3 V_7 )
{
return F_31 ( V_5 , V_38 , V_39 , V_7 ,
true ) ;
}
int
F_39 ( struct V_1 * V_2 , T_6 V_18 , void * V_27 )
{
int V_32 ;
unsigned long V_33 ;
if ( V_2 -> V_34 ) {
F_26 ( & V_2 -> V_42 , V_33 ) ;
V_32 = F_29 ( V_2 , V_18 , V_27 ) ;
F_27 ( & V_2 -> V_42 , V_33 ) ;
} else {
V_32 = F_29 ( V_2 , V_18 , V_27 ) ;
}
return V_32 ;
}
