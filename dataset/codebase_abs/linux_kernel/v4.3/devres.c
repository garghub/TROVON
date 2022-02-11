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
void * F_13 ( T_2 V_11 , T_1 V_4 , T_3 V_14 ,
const char * V_3 )
{
struct V_15 * V_16 ;
V_16 = F_14 ( V_11 , V_4 , V_14 | V_17 ) ;
if ( F_3 ( ! V_16 ) )
return NULL ;
F_1 ( & V_16 -> V_2 , V_3 , V_4 ) ;
return V_16 -> V_18 ;
}
void * F_15 ( T_2 V_11 , T_1 V_4 , T_3 V_14 )
{
struct V_15 * V_16 ;
V_16 = F_14 ( V_11 , V_4 , V_14 | V_17 ) ;
if ( F_3 ( ! V_16 ) )
return NULL ;
return V_16 -> V_18 ;
}
void F_16 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 ,
void (* F_17)( struct V_5 * , void * , void * ) ,
void * V_18 )
{
struct V_1 * V_2 ;
struct V_1 * V_21 ;
unsigned long V_22 ;
if ( ! F_17 )
return;
F_18 ( & V_6 -> V_23 , V_22 ) ;
F_19 (node, tmp,
&dev->devres_head, entry) {
struct V_15 * V_16 = F_8 ( V_2 , struct V_15 , V_2 ) ;
if ( V_2 -> V_11 != V_11 )
continue;
if ( V_19 && ! V_19 ( V_6 , V_16 -> V_18 , V_20 ) )
continue;
F_17 ( V_6 , V_16 -> V_18 , V_18 ) ;
}
F_20 ( & V_6 -> V_23 , V_22 ) ;
}
void F_21 ( void * V_9 )
{
if ( V_9 ) {
struct V_15 * V_16 = F_8 ( V_9 , struct V_15 , V_18 ) ;
F_10 ( ! F_11 ( & V_16 -> V_2 . V_12 ) ) ;
F_22 ( V_16 ) ;
}
}
void F_23 ( struct V_5 * V_6 , void * V_9 )
{
struct V_15 * V_16 = F_8 ( V_9 , struct V_15 , V_18 ) ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
F_9 ( V_6 , & V_16 -> V_2 ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
}
static struct V_15 * F_24 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 )
{
struct V_1 * V_2 ;
F_25 (node, &dev->devres_head, entry) {
struct V_15 * V_16 = F_8 ( V_2 , struct V_15 , V_2 ) ;
if ( V_2 -> V_11 != V_11 )
continue;
if ( V_19 && ! V_19 ( V_6 , V_16 -> V_18 , V_20 ) )
continue;
return V_16 ;
}
return NULL ;
}
void * F_26 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 )
{
struct V_15 * V_16 ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_16 = F_24 ( V_6 , V_11 , V_19 , V_20 ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
if ( V_16 )
return V_16 -> V_18 ;
return NULL ;
}
void * F_27 ( struct V_5 * V_6 , void * V_24 ,
T_4 V_19 , void * V_20 )
{
struct V_15 * V_25 = F_8 ( V_24 , struct V_15 , V_18 ) ;
struct V_15 * V_16 ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_16 = F_24 ( V_6 , V_25 -> V_2 . V_11 , V_19 , V_20 ) ;
if ( ! V_16 ) {
F_9 ( V_6 , & V_25 -> V_2 ) ;
V_16 = V_25 ;
V_24 = NULL ;
}
F_20 ( & V_6 -> V_23 , V_22 ) ;
F_21 ( V_24 ) ;
return V_16 -> V_18 ;
}
void * F_28 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 )
{
struct V_15 * V_16 ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_16 = F_24 ( V_6 , V_11 , V_19 , V_20 ) ;
if ( V_16 ) {
F_29 ( & V_16 -> V_2 . V_12 ) ;
F_2 ( V_6 , & V_16 -> V_2 , L_3 ) ;
}
F_20 ( & V_6 -> V_23 , V_22 ) ;
if ( V_16 )
return V_16 -> V_18 ;
return NULL ;
}
int F_30 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 )
{
void * V_9 ;
V_9 = F_28 ( V_6 , V_11 , V_19 , V_20 ) ;
if ( F_3 ( ! V_9 ) )
return - V_26 ;
F_21 ( V_9 ) ;
return 0 ;
}
int F_31 ( struct V_5 * V_6 , T_2 V_11 ,
T_4 V_19 , void * V_20 )
{
void * V_9 ;
V_9 = F_28 ( V_6 , V_11 , V_19 , V_20 ) ;
if ( F_3 ( ! V_9 ) )
return - V_26 ;
(* V_11)( V_6 , V_9 ) ;
F_21 ( V_9 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_27 * V_28 , struct V_27 * V_29 ,
struct V_27 * V_30 )
{
int V_31 = 0 , V_32 = 0 ;
struct V_27 * V_33 ;
V_33 = V_28 ;
while ( V_33 != V_29 ) {
struct V_1 * V_2 ;
struct V_10 * V_34 ;
V_2 = F_33 ( V_33 , struct V_1 , V_12 ) ;
V_33 = V_33 -> V_35 ;
V_34 = F_7 ( V_2 ) ;
if ( V_34 ) {
V_34 -> V_36 = 0 ;
V_32 ++ ;
} else {
if ( & V_2 -> V_12 == V_28 )
V_28 = V_28 -> V_35 ;
F_34 ( & V_2 -> V_12 , V_30 ) ;
V_31 ++ ;
}
}
if ( ! V_32 )
return V_31 ;
V_33 = V_28 ;
while ( V_33 != V_29 ) {
struct V_1 * V_2 ;
struct V_10 * V_34 ;
V_2 = F_33 ( V_33 , struct V_1 , V_12 ) ;
V_33 = V_33 -> V_35 ;
V_34 = F_7 ( V_2 ) ;
F_10 ( ! V_34 || F_11 ( & V_34 -> V_2 [ 0 ] . V_12 ) ) ;
V_34 -> V_36 ++ ;
if ( F_11 ( & V_34 -> V_2 [ 1 ] . V_12 ) )
V_34 -> V_36 ++ ;
F_10 ( V_34 -> V_36 <= 0 || V_34 -> V_36 > 2 ) ;
if ( V_34 -> V_36 == 2 ) {
F_34 ( & V_34 -> V_2 [ 0 ] . V_12 , V_30 ) ;
F_29 ( & V_34 -> V_2 [ 1 ] . V_12 ) ;
}
}
return V_31 ;
}
static int F_35 ( struct V_5 * V_6 , struct V_27 * V_28 ,
struct V_27 * V_29 , unsigned long V_22 )
__releases( &dev->devres_lock
int F_36 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
if ( F_37 ( V_6 -> V_13 . V_35 == NULL ) )
return - V_37 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
return F_35 ( V_6 , V_6 -> V_13 . V_35 , & V_6 -> V_13 ,
V_22 ) ;
}
void * F_38 ( struct V_5 * V_6 , void * V_38 , T_3 V_14 )
{
struct V_10 * V_34 ;
unsigned long V_22 ;
V_34 = F_39 ( sizeof( * V_34 ) , V_14 ) ;
if ( F_3 ( ! V_34 ) )
return NULL ;
V_34 -> V_2 [ 0 ] . V_11 = & F_5 ;
V_34 -> V_2 [ 1 ] . V_11 = & F_6 ;
F_40 ( & V_34 -> V_2 [ 0 ] . V_12 ) ;
F_40 ( & V_34 -> V_2 [ 1 ] . V_12 ) ;
F_1 ( & V_34 -> V_2 [ 0 ] , L_4 , 0 ) ;
F_1 ( & V_34 -> V_2 [ 1 ] , L_5 , 0 ) ;
V_34 -> V_38 = V_34 ;
if ( V_38 )
V_34 -> V_38 = V_38 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
F_9 ( V_6 , & V_34 -> V_2 [ 0 ] ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
return V_34 -> V_38 ;
}
static struct V_10 * F_41 ( struct V_5 * V_6 , void * V_38 )
{
struct V_1 * V_2 ;
F_25 (node, &dev->devres_head, entry) {
struct V_10 * V_34 ;
if ( V_2 -> V_11 != & F_5 )
continue;
V_34 = F_8 ( V_2 , struct V_10 , V_2 [ 0 ] ) ;
if ( V_38 ) {
if ( V_34 -> V_38 == V_38 )
return V_34 ;
} else if ( F_11 ( & V_34 -> V_2 [ 1 ] . V_12 ) )
return V_34 ;
}
return NULL ;
}
void F_42 ( struct V_5 * V_6 , void * V_38 )
{
struct V_10 * V_34 ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_34 = F_41 ( V_6 , V_38 ) ;
if ( V_34 )
F_9 ( V_6 , & V_34 -> V_2 [ 1 ] ) ;
else
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
}
void F_43 ( struct V_5 * V_6 , void * V_38 )
{
struct V_10 * V_34 ;
unsigned long V_22 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_34 = F_41 ( V_6 , V_38 ) ;
if ( V_34 ) {
F_29 ( & V_34 -> V_2 [ 0 ] . V_12 ) ;
F_29 ( & V_34 -> V_2 [ 1 ] . V_12 ) ;
F_2 ( V_6 , & V_34 -> V_2 [ 0 ] , L_3 ) ;
} else
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
F_22 ( V_34 ) ;
}
int F_44 ( struct V_5 * V_6 , void * V_38 )
{
struct V_10 * V_34 ;
unsigned long V_22 ;
int V_31 = 0 ;
F_18 ( & V_6 -> V_23 , V_22 ) ;
V_34 = F_41 ( V_6 , V_38 ) ;
if ( V_34 ) {
struct V_27 * V_28 = & V_34 -> V_2 [ 0 ] . V_12 ;
struct V_27 * V_29 = & V_6 -> V_13 ;
if ( ! F_11 ( & V_34 -> V_2 [ 1 ] . V_12 ) )
V_29 = V_34 -> V_2 [ 1 ] . V_12 . V_35 ;
V_31 = F_35 ( V_6 , V_28 , V_29 , V_22 ) ;
} else {
F_37 ( 1 ) ;
F_20 ( & V_6 -> V_23 , V_22 ) ;
}
return V_31 ;
}
static int F_45 ( struct V_5 * V_6 , void * V_9 , void * V_39 )
{
struct V_40 * V_15 = V_9 ;
struct V_40 * V_41 = V_39 ;
return V_15 -> V_42 == V_41 -> V_42 &&
V_15 -> V_18 == V_41 -> V_18 ;
}
static void F_46 ( struct V_5 * V_6 , void * V_9 )
{
struct V_40 * V_15 = V_9 ;
V_15 -> V_42 ( V_15 -> V_18 ) ;
}
int F_47 ( struct V_5 * V_6 , void (* V_42)( void * ) , void * V_18 )
{
struct V_40 * V_15 ;
V_15 = F_15 ( F_46 ,
sizeof( struct V_40 ) , V_43 ) ;
if ( ! V_15 )
return - V_44 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_42 = V_42 ;
F_23 ( V_6 , V_15 ) ;
return 0 ;
}
void F_48 ( struct V_5 * V_6 , void (* V_42)( void * ) , void * V_18 )
{
struct V_40 V_15 = {
. V_18 = V_18 ,
. V_42 = V_42 ,
} ;
F_37 ( F_30 ( V_6 , F_46 , F_45 ,
& V_15 ) ) ;
}
static void F_49 ( struct V_5 * V_6 , void * V_9 )
{
}
static int F_50 ( struct V_5 * V_6 , void * V_9 , void * V_18 )
{
return V_9 == V_18 ;
}
void * F_51 ( struct V_5 * V_6 , T_1 V_4 , T_3 V_14 )
{
struct V_15 * V_16 ;
V_16 = F_14 ( F_49 , V_4 , V_14 ) ;
if ( F_3 ( ! V_16 ) )
return NULL ;
F_1 ( & V_16 -> V_2 , L_6 , V_4 ) ;
F_23 ( V_6 , V_16 -> V_18 ) ;
return V_16 -> V_18 ;
}
char * F_52 ( struct V_5 * V_6 , const char * V_45 , T_3 V_14 )
{
T_1 V_4 ;
char * V_46 ;
if ( ! V_45 )
return NULL ;
V_4 = strlen ( V_45 ) + 1 ;
V_46 = F_51 ( V_6 , V_4 , V_14 ) ;
if ( V_46 )
memcpy ( V_46 , V_45 , V_4 ) ;
return V_46 ;
}
char * F_53 ( struct V_5 * V_6 , T_3 V_14 , const char * V_47 ,
T_5 V_48 )
{
unsigned int V_49 ;
char * V_39 ;
T_5 V_50 ;
F_54 ( V_50 , V_48 ) ;
V_49 = vsnprintf ( NULL , 0 , V_47 , V_50 ) ;
va_end ( V_50 ) ;
V_39 = F_51 ( V_6 , V_49 + 1 , V_14 ) ;
if ( ! V_39 )
return NULL ;
vsnprintf ( V_39 , V_49 + 1 , V_47 , V_48 ) ;
return V_39 ;
}
char * F_55 ( struct V_5 * V_6 , T_3 V_14 , const char * V_47 , ... )
{
T_5 V_48 ;
char * V_39 ;
va_start ( V_48 , V_47 ) ;
V_39 = F_53 ( V_6 , V_14 , V_47 , V_48 ) ;
va_end ( V_48 ) ;
return V_39 ;
}
void F_56 ( struct V_5 * V_6 , void * V_39 )
{
int V_51 ;
V_51 = F_30 ( V_6 , F_49 , F_50 , V_39 ) ;
F_37 ( V_51 ) ;
}
void * F_57 ( struct V_5 * V_6 , const void * V_52 , T_1 V_49 , T_3 V_14 )
{
void * V_39 ;
V_39 = F_51 ( V_6 , V_49 , V_14 ) ;
if ( V_39 )
memcpy ( V_39 , V_52 , V_49 ) ;
return V_39 ;
}
static int F_58 ( struct V_5 * V_6 , void * V_9 , void * V_39 )
{
struct V_53 * V_15 = V_9 ;
struct V_53 * V_41 = V_39 ;
return V_15 -> V_54 == V_41 -> V_54 ;
}
static void F_59 ( struct V_5 * V_6 , void * V_9 )
{
struct V_53 * V_15 = V_9 ;
F_60 ( V_15 -> V_54 , V_15 -> V_55 ) ;
}
unsigned long F_61 ( struct V_5 * V_6 ,
T_3 V_56 , unsigned int V_55 )
{
struct V_53 * V_15 ;
unsigned long V_54 ;
V_54 = F_62 ( V_56 , V_55 ) ;
if ( F_3 ( ! V_54 ) )
return 0 ;
V_15 = F_15 ( F_59 ,
sizeof( struct V_53 ) , V_43 ) ;
if ( F_3 ( ! V_15 ) ) {
F_60 ( V_54 , V_55 ) ;
return 0 ;
}
V_15 -> V_54 = V_54 ;
V_15 -> V_55 = V_55 ;
F_23 ( V_6 , V_15 ) ;
return V_54 ;
}
void F_63 ( struct V_5 * V_6 , unsigned long V_54 )
{
struct V_53 V_15 = { . V_54 = V_54 } ;
F_37 ( F_31 ( V_6 , F_59 , F_58 ,
& V_15 ) ) ;
}
