static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 ) {
int V_6 = V_2 -> V_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_2 ( V_2 ) &&
F_3 () && ! F_4 ( V_7 ) )
return - V_8 ;
if ( ! ( V_4 -> V_9 . V_10 & V_11 ) )
return 0 ;
if ( V_4 -> V_12 == V_13 ) {
if ( V_2 -> V_14 & V_15 )
return 0 ;
}
if ( F_3 () && ! F_4 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_16 T_1 * V_17 ;
int V_6 = - V_18 ;
int V_19 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_20 ++ > 0 )
return 0 ;
V_17 = F_6 ( struct V_16 ) ;
if ( ! V_17 )
goto V_21;
F_7 (cpu)
F_8 ( F_9 ( V_17 , V_19 ) ) ;
V_2 -> V_22 = V_17 ;
if ( ! V_23 ) {
char T_1 * V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_24 = ( char T_1 * ) F_6 ( V_27 ) ;
if ( ! V_24 )
goto V_21;
V_28 [ V_25 ] = V_24 ;
}
}
V_6 = V_2 -> V_29 -> V_30 ( V_2 , V_31 , NULL ) ;
if ( V_6 )
goto V_21;
V_23 ++ ;
return 0 ;
V_21:
if ( ! V_23 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
F_10 ( V_28 [ V_25 ] ) ;
V_28 [ V_25 ] = NULL ;
}
}
if ( ! -- V_2 -> V_20 ) {
F_10 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
return V_6 ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_25 ;
if ( -- V_2 -> V_20 > 0 )
goto V_32;
V_2 -> V_29 -> V_30 ( V_2 , V_33 , NULL ) ;
F_12 () ;
F_10 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
if ( ! -- V_23 ) {
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
F_10 ( V_28 [ V_25 ] ) ;
V_28 [ V_25 ] = NULL ;
}
}
V_32:
F_13 ( V_2 -> V_34 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_29 -> V_30 ( V_2 , V_35 , V_4 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_29 -> V_30 ( V_2 , V_36 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_14 ( V_4 ) ;
if ( V_6 ) {
F_11 ( V_4 ) ;
return V_6 ;
}
return 0 ;
}
int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
T_2 V_37 = V_4 -> V_9 . V_38 ;
int V_6 = - V_39 ;
F_18 ( & V_40 ) ;
F_19 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_41 . type == V_37 &&
V_2 -> V_29 && V_2 -> V_29 -> V_30 &&
F_20 ( V_2 -> V_34 ) ) {
V_6 = F_16 ( V_2 , V_4 ) ;
if ( V_6 )
F_13 ( V_2 -> V_34 ) ;
break;
}
}
F_21 ( & V_40 ) ;
return V_6 ;
}
void F_22 ( struct V_3 * V_4 )
{
F_18 ( & V_40 ) ;
F_15 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( & V_40 ) ;
}
int F_23 ( struct V_3 * V_4 , int V_14 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_16 T_1 * V_42 ;
struct V_16 * V_17 ;
V_42 = V_2 -> V_22 ;
if ( F_24 ( ! V_42 ) )
return - V_39 ;
if ( ! ( V_14 & V_43 ) )
V_4 -> V_44 . V_45 = V_46 ;
V_17 = F_25 ( V_42 ) ;
F_26 ( & V_4 -> V_47 , V_17 ) ;
return V_2 -> V_29 -> V_30 ( V_2 , V_48 , V_4 ) ;
}
void F_27 ( struct V_3 * V_4 , int V_14 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_28 ( & V_4 -> V_47 ) ;
V_2 -> V_29 -> V_30 ( V_2 , V_49 , V_4 ) ;
}
T_3 void * F_29 ( int V_50 , unsigned short type ,
struct V_51 * V_52 , int * V_53 )
{
struct V_54 * V_55 ;
unsigned long V_14 ;
char * V_56 ;
int V_57 ;
F_30 ( V_58 % sizeof( unsigned long ) ) ;
if ( F_31 ( V_50 > V_58 ,
L_1 ) )
return NULL ;
V_57 = F_32 () ;
* V_53 = F_33 () ;
if ( * V_53 < 0 )
return NULL ;
V_56 = F_25 ( V_28 [ * V_53 ] ) ;
memset ( & V_56 [ V_50 - sizeof( T_2 ) ] , 0 , sizeof( T_2 ) ) ;
V_55 = (struct V_54 * ) V_56 ;
F_34 ( V_14 ) ;
F_35 ( V_55 , V_14 , V_57 ) ;
V_55 -> type = type ;
return V_56 ;
}
static void
F_36 ( unsigned long V_59 , unsigned long V_60 ,
struct V_61 * V_62 , struct V_51 * V_51 )
{
struct V_63 * V_55 ;
struct V_16 * V_64 ;
struct V_51 V_52 ;
int V_65 ;
V_64 = F_25 ( V_66 . V_22 ) ;
if ( F_37 ( V_64 ) )
return;
#define F_38 (ALIGN(sizeof(struct ftrace_entry) + sizeof(u32), \
sizeof(u64)) - sizeof(u32))
F_30 ( F_38 > V_58 ) ;
F_39 ( & V_52 ) ;
V_55 = F_29 ( F_38 , V_67 , NULL , & V_65 ) ;
if ( ! V_55 )
return;
V_55 -> V_59 = V_59 ;
V_55 -> V_60 = V_60 ;
F_40 ( V_55 , F_38 , V_65 , 0 ,
1 , & V_52 , V_64 , NULL ) ;
#undef F_38
}
static int F_41 ( struct V_3 * V_41 )
{
struct V_61 * V_62 = & V_41 -> V_61 ;
V_62 -> V_14 |= V_68 ;
V_62 -> V_69 = F_36 ;
return F_42 ( V_62 ) ;
}
static int F_43 ( struct V_3 * V_41 )
{
struct V_61 * V_62 = & V_41 -> V_61 ;
int V_6 = F_44 ( V_62 ) ;
F_45 ( V_62 ) ;
return V_6 ;
}
static void F_46 ( struct V_3 * V_41 )
{
F_47 ( & V_41 -> V_61 ) ;
}
static void F_48 ( struct V_3 * V_41 )
{
F_49 ( & V_41 -> V_61 ) ;
}
int F_50 ( struct V_1 * V_70 ,
enum V_71 type , void * V_72 )
{
switch ( type ) {
case V_73 :
case V_74 :
break;
case V_31 :
case V_33 :
return 0 ;
case V_35 :
return F_41 ( V_72 ) ;
case V_36 :
return F_43 ( V_72 ) ;
case V_48 :
F_46 ( V_72 ) ;
return 0 ;
case V_49 :
F_48 ( V_72 ) ;
return 0 ;
}
return - V_39 ;
}
