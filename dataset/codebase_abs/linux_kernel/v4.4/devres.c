static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
}
static void F_2 ( struct V_5 * V_6 , struct V_1 * V_2 ,
const char * V_7 )
{
if ( F_3 ( V_8 ) )
F_4 ( V_6 , L_1 ,
V_7 , V_2 , V_2 -> V_3 , ( unsigned long ) V_2 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 , void * V_9 )
{
}
static void F_6 ( struct V_5 * V_6 , void * V_9 )
{
}
static struct V_10 * F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & F_5 )
return F_8 ( V_2 , struct V_10 , V_2 [ 0 ] ) ;
if ( V_2 -> V_11 == & F_6 )
return F_8 ( V_2 , struct V_10 , V_2 [ 1 ] ) ;
return NULL ;
}
void F_9 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
F_2 ( V_6 , V_2 , L_2 ) ;
F_10 ( ! F_11 ( & V_2 -> V_12 ) ) ;
F_12 ( & V_2 -> V_12 , & V_6 -> V_13 ) ;
}
void * F_13 ( T_2 V_11 , T_1 V_4 , T_3 V_14 , int V_15 ,
const char * V_3 )
{
struct V_16 * V_17 ;
V_17 = F_14 ( V_11 , V_4 , V_14 | V_18 , V_15 ) ;
if ( F_3 ( ! V_17 ) )
return NULL ;
F_1 ( & V_17 -> V_2 , V_3 , V_4 ) ;
return V_17 -> V_19 ;
}
void * F_15 ( T_2 V_11 , T_1 V_4 , T_3 V_14 , int V_15 )
{
struct V_16 * V_17 ;
V_17 = F_14 ( V_11 , V_4 , V_14 | V_18 , V_15 ) ;
if ( F_3 ( ! V_17 ) )
return NULL ;
return V_17 -> V_19 ;
}
void F_16 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 ,
void (* F_17)( struct V_5 * , void * , void * ) ,
void * V_19 )
{
struct V_1 * V_2 ;
struct V_1 * V_22 ;
unsigned long V_23 ;
if ( ! F_17 )
return;
F_18 ( & V_6 -> V_24 , V_23 ) ;
F_19 (node, tmp,
&dev->devres_head, entry) {
struct V_16 * V_17 = F_8 ( V_2 , struct V_16 , V_2 ) ;
if ( V_2 -> V_11 != V_11 )
continue;
if ( V_20 && ! V_20 ( V_6 , V_17 -> V_19 , V_21 ) )
continue;
F_17 ( V_6 , V_17 -> V_19 , V_19 ) ;
}
F_20 ( & V_6 -> V_24 , V_23 ) ;
}
void F_21 ( void * V_9 )
{
if ( V_9 ) {
struct V_16 * V_17 = F_8 ( V_9 , struct V_16 , V_19 ) ;
F_10 ( ! F_11 ( & V_17 -> V_2 . V_12 ) ) ;
F_22 ( V_17 ) ;
}
}
void F_23 ( struct V_5 * V_6 , void * V_9 )
{
struct V_16 * V_17 = F_8 ( V_9 , struct V_16 , V_19 ) ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
F_9 ( V_6 , & V_17 -> V_2 ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
}
static struct V_16 * F_24 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 )
{
struct V_1 * V_2 ;
F_25 (node, &dev->devres_head, entry) {
struct V_16 * V_17 = F_8 ( V_2 , struct V_16 , V_2 ) ;
if ( V_2 -> V_11 != V_11 )
continue;
if ( V_20 && ! V_20 ( V_6 , V_17 -> V_19 , V_21 ) )
continue;
return V_17 ;
}
return NULL ;
}
void * F_26 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 )
{
struct V_16 * V_17 ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_17 = F_24 ( V_6 , V_11 , V_20 , V_21 ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
if ( V_17 )
return V_17 -> V_19 ;
return NULL ;
}
void * F_27 ( struct V_5 * V_6 , void * V_25 ,
T_4 V_20 , void * V_21 )
{
struct V_16 * V_26 = F_8 ( V_25 , struct V_16 , V_19 ) ;
struct V_16 * V_17 ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_17 = F_24 ( V_6 , V_26 -> V_2 . V_11 , V_20 , V_21 ) ;
if ( ! V_17 ) {
F_9 ( V_6 , & V_26 -> V_2 ) ;
V_17 = V_26 ;
V_25 = NULL ;
}
F_20 ( & V_6 -> V_24 , V_23 ) ;
F_21 ( V_25 ) ;
return V_17 -> V_19 ;
}
void * F_28 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 )
{
struct V_16 * V_17 ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_17 = F_24 ( V_6 , V_11 , V_20 , V_21 ) ;
if ( V_17 ) {
F_29 ( & V_17 -> V_2 . V_12 ) ;
F_2 ( V_6 , & V_17 -> V_2 , L_3 ) ;
}
F_20 ( & V_6 -> V_24 , V_23 ) ;
if ( V_17 )
return V_17 -> V_19 ;
return NULL ;
}
int F_30 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 )
{
void * V_9 ;
V_9 = F_28 ( V_6 , V_11 , V_20 , V_21 ) ;
if ( F_3 ( ! V_9 ) )
return - V_27 ;
F_21 ( V_9 ) ;
return 0 ;
}
int F_31 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_20 , void * V_21 )
{
void * V_9 ;
V_9 = F_28 ( V_6 , V_11 , V_20 , V_21 ) ;
if ( F_3 ( ! V_9 ) )
return - V_27 ;
(* V_11)( V_6 , V_9 ) ;
F_21 ( V_9 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_28 * V_29 , struct V_28 * V_30 ,
struct V_28 * V_31 )
{
int V_32 = 0 , V_33 = 0 ;
struct V_28 * V_34 ;
V_34 = V_29 ;
while ( V_34 != V_30 ) {
struct V_1 * V_2 ;
struct V_10 * V_35 ;
V_2 = F_33 ( V_34 , struct V_1 , V_12 ) ;
V_34 = V_34 -> V_36 ;
V_35 = F_7 ( V_2 ) ;
if ( V_35 ) {
V_35 -> V_37 = 0 ;
V_33 ++ ;
} else {
if ( & V_2 -> V_12 == V_29 )
V_29 = V_29 -> V_36 ;
F_34 ( & V_2 -> V_12 , V_31 ) ;
V_32 ++ ;
}
}
if ( ! V_33 )
return V_32 ;
V_34 = V_29 ;
while ( V_34 != V_30 ) {
struct V_1 * V_2 ;
struct V_10 * V_35 ;
V_2 = F_33 ( V_34 , struct V_1 , V_12 ) ;
V_34 = V_34 -> V_36 ;
V_35 = F_7 ( V_2 ) ;
F_10 ( ! V_35 || F_11 ( & V_35 -> V_2 [ 0 ] . V_12 ) ) ;
V_35 -> V_37 ++ ;
if ( F_11 ( & V_35 -> V_2 [ 1 ] . V_12 ) )
V_35 -> V_37 ++ ;
F_10 ( V_35 -> V_37 <= 0 || V_35 -> V_37 > 2 ) ;
if ( V_35 -> V_37 == 2 ) {
F_34 ( & V_35 -> V_2 [ 0 ] . V_12 , V_31 ) ;
F_29 ( & V_35 -> V_2 [ 1 ] . V_12 ) ;
}
}
return V_32 ;
}
static int F_35 ( struct V_5 * V_6 , struct V_28 * V_29 ,
struct V_28 * V_30 , unsigned long V_23 )
__releases( &dev->devres_lock
int F_36 ( struct V_5 * V_6 )
{
unsigned long V_23 ;
if ( F_37 ( V_6 -> V_13 . V_36 == NULL ) )
return - V_38 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
return F_35 ( V_6 , V_6 -> V_13 . V_36 , & V_6 -> V_13 ,
V_23 ) ;
}
void * F_38 ( struct V_5 * V_6 , void * V_39 , T_3 V_14 )
{
struct V_10 * V_35 ;
unsigned long V_23 ;
V_35 = F_39 ( sizeof( * V_35 ) , V_14 ) ;
if ( F_3 ( ! V_35 ) )
return NULL ;
V_35 -> V_2 [ 0 ] . V_11 = & F_5 ;
V_35 -> V_2 [ 1 ] . V_11 = & F_6 ;
F_40 ( & V_35 -> V_2 [ 0 ] . V_12 ) ;
F_40 ( & V_35 -> V_2 [ 1 ] . V_12 ) ;
F_1 ( & V_35 -> V_2 [ 0 ] , L_4 , 0 ) ;
F_1 ( & V_35 -> V_2 [ 1 ] , L_5 , 0 ) ;
V_35 -> V_39 = V_35 ;
if ( V_39 )
V_35 -> V_39 = V_39 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
F_9 ( V_6 , & V_35 -> V_2 [ 0 ] ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
return V_35 -> V_39 ;
}
static struct V_10 * F_41 ( struct V_5 * V_6 , void * V_39 )
{
struct V_1 * V_2 ;
F_25 (node, &dev->devres_head, entry) {
struct V_10 * V_35 ;
if ( V_2 -> V_11 != & F_5 )
continue;
V_35 = F_8 ( V_2 , struct V_10 , V_2 [ 0 ] ) ;
if ( V_39 ) {
if ( V_35 -> V_39 == V_39 )
return V_35 ;
} else if ( F_11 ( & V_35 -> V_2 [ 1 ] . V_12 ) )
return V_35 ;
}
return NULL ;
}
void F_42 ( struct V_5 * V_6 , void * V_39 )
{
struct V_10 * V_35 ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_35 = F_41 ( V_6 , V_39 ) ;
if ( V_35 )
F_9 ( V_6 , & V_35 -> V_2 [ 1 ] ) ;
else
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
}
void F_43 ( struct V_5 * V_6 , void * V_39 )
{
struct V_10 * V_35 ;
unsigned long V_23 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_35 = F_41 ( V_6 , V_39 ) ;
if ( V_35 ) {
F_29 ( & V_35 -> V_2 [ 0 ] . V_12 ) ;
F_29 ( & V_35 -> V_2 [ 1 ] . V_12 ) ;
F_2 ( V_6 , & V_35 -> V_2 [ 0 ] , L_3 ) ;
} else
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
F_22 ( V_35 ) ;
}
int F_44 ( struct V_5 * V_6 , void * V_39 )
{
struct V_10 * V_35 ;
unsigned long V_23 ;
int V_32 = 0 ;
F_18 ( & V_6 -> V_24 , V_23 ) ;
V_35 = F_41 ( V_6 , V_39 ) ;
if ( V_35 ) {
struct V_28 * V_29 = & V_35 -> V_2 [ 0 ] . V_12 ;
struct V_28 * V_30 = & V_6 -> V_13 ;
if ( ! F_11 ( & V_35 -> V_2 [ 1 ] . V_12 ) )
V_30 = V_35 -> V_2 [ 1 ] . V_12 . V_36 ;
V_32 = F_35 ( V_6 , V_29 , V_30 , V_23 ) ;
} else {
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_24 , V_23 ) ;
}
return V_32 ;
}
static int F_45 ( struct V_5 * V_6 , void * V_9 , void * V_40 )
{
struct V_41 * V_16 = V_9 ;
struct V_41 * V_42 = V_40 ;
return V_16 -> V_43 == V_42 -> V_43 &&
V_16 -> V_19 == V_42 -> V_19 ;
}
static void F_46 ( struct V_5 * V_6 , void * V_9 )
{
struct V_41 * V_16 = V_9 ;
V_16 -> V_43 ( V_16 -> V_19 ) ;
}
int F_47 ( struct V_5 * V_6 , void (* V_43)( void * ) , void * V_19 )
{
struct V_41 * V_16 ;
V_16 = F_48 ( F_46 ,
sizeof( struct V_41 ) , V_44 ) ;
if ( ! V_16 )
return - V_45 ;
V_16 -> V_19 = V_19 ;
V_16 -> V_43 = V_43 ;
F_23 ( V_6 , V_16 ) ;
return 0 ;
}
void F_49 ( struct V_5 * V_6 , void (* V_43)( void * ) , void * V_19 )
{
struct V_41 V_16 = {
. V_19 = V_19 ,
. V_43 = V_43 ,
} ;
F_37 ( F_30 ( V_6 , F_46 , F_45 ,
& V_16 ) ) ;
}
static void F_50 ( struct V_5 * V_6 , void * V_9 )
{
}
static int F_51 ( struct V_5 * V_6 , void * V_9 , void * V_19 )
{
return V_9 == V_19 ;
}
void * F_52 ( struct V_5 * V_6 , T_1 V_4 , T_3 V_14 )
{
struct V_16 * V_17 ;
V_17 = F_14 ( F_50 , V_4 , V_14 , F_53 ( V_6 ) ) ;
if ( F_3 ( ! V_17 ) )
return NULL ;
F_1 ( & V_17 -> V_2 , L_6 , V_4 ) ;
F_23 ( V_6 , V_17 -> V_19 ) ;
return V_17 -> V_19 ;
}
char * F_54 ( struct V_5 * V_6 , const char * V_46 , T_3 V_14 )
{
T_1 V_4 ;
char * V_47 ;
if ( ! V_46 )
return NULL ;
V_4 = strlen ( V_46 ) + 1 ;
V_47 = F_52 ( V_6 , V_4 , V_14 ) ;
if ( V_47 )
memcpy ( V_47 , V_46 , V_4 ) ;
return V_47 ;
}
char * F_55 ( struct V_5 * V_6 , T_3 V_14 , const char * V_48 ,
T_5 V_49 )
{
unsigned int V_50 ;
char * V_40 ;
T_5 V_51 ;
F_56 ( V_51 , V_49 ) ;
V_50 = vsnprintf ( NULL , 0 , V_48 , V_51 ) ;
va_end ( V_51 ) ;
V_40 = F_52 ( V_6 , V_50 + 1 , V_14 ) ;
if ( ! V_40 )
return NULL ;
vsnprintf ( V_40 , V_50 + 1 , V_48 , V_49 ) ;
return V_40 ;
}
char * F_57 ( struct V_5 * V_6 , T_3 V_14 , const char * V_48 , ... )
{
T_5 V_49 ;
char * V_40 ;
va_start ( V_49 , V_48 ) ;
V_40 = F_55 ( V_6 , V_14 , V_48 , V_49 ) ;
va_end ( V_49 ) ;
return V_40 ;
}
void F_58 ( struct V_5 * V_6 , void * V_40 )
{
int V_52 ;
V_52 = F_30 ( V_6 , F_50 , F_51 , V_40 ) ;
F_37 ( V_52 ) ;
}
void * F_59 ( struct V_5 * V_6 , const void * V_53 , T_1 V_50 , T_3 V_14 )
{
void * V_40 ;
V_40 = F_52 ( V_6 , V_50 , V_14 ) ;
if ( V_40 )
memcpy ( V_40 , V_53 , V_50 ) ;
return V_40 ;
}
static int F_60 ( struct V_5 * V_6 , void * V_9 , void * V_40 )
{
struct V_54 * V_16 = V_9 ;
struct V_54 * V_42 = V_40 ;
return V_16 -> V_55 == V_42 -> V_55 ;
}
static void F_61 ( struct V_5 * V_6 , void * V_9 )
{
struct V_54 * V_16 = V_9 ;
F_62 ( V_16 -> V_55 , V_16 -> V_56 ) ;
}
unsigned long F_63 ( struct V_5 * V_6 ,
T_3 V_57 , unsigned int V_56 )
{
struct V_54 * V_16 ;
unsigned long V_55 ;
V_55 = F_64 ( V_57 , V_56 ) ;
if ( F_3 ( ! V_55 ) )
return 0 ;
V_16 = F_48 ( F_61 ,
sizeof( struct V_54 ) , V_44 ) ;
if ( F_3 ( ! V_16 ) ) {
F_62 ( V_55 , V_56 ) ;
return 0 ;
}
V_16 -> V_55 = V_55 ;
V_16 -> V_56 = V_56 ;
F_23 ( V_6 , V_16 ) ;
return V_55 ;
}
void F_65 ( struct V_5 * V_6 , unsigned long V_55 )
{
struct V_54 V_16 = { . V_55 = V_55 } ;
F_37 ( F_31 ( V_6 , F_61 , F_60 ,
& V_16 ) ) ;
}
