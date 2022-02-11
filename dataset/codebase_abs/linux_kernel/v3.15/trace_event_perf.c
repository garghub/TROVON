static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 ) {
int V_6 = V_2 -> V_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_2 ( V_2 ) ) {
if ( F_3 () && ! F_4 ( V_7 ) )
return - V_8 ;
if ( ! V_4 -> V_9 . V_10 )
return - V_11 ;
if ( V_4 -> V_9 . V_12 & V_13 )
return - V_11 ;
}
if ( ! ( V_4 -> V_9 . V_12 & V_14 ) )
return 0 ;
if ( V_4 -> V_15 == V_16 ) {
if ( V_2 -> V_17 & V_18 )
return 0 ;
}
if ( F_3 () && ! F_4 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_19 T_1 * V_20 ;
int V_6 = - V_21 ;
int V_22 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_23 ++ > 0 )
return 0 ;
V_20 = F_6 ( struct V_19 ) ;
if ( ! V_20 )
goto V_24;
F_7 (cpu)
F_8 ( F_9 ( V_20 , V_22 ) ) ;
V_2 -> V_25 = V_20 ;
if ( ! V_26 ) {
char T_1 * V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_27 = ( char T_1 * ) F_6 ( V_30 ) ;
if ( ! V_27 )
goto V_24;
V_31 [ V_28 ] = V_27 ;
}
}
V_6 = V_2 -> V_32 -> V_33 ( V_2 , V_34 , NULL ) ;
if ( V_6 )
goto V_24;
V_26 ++ ;
return 0 ;
V_24:
if ( ! V_26 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
F_10 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = NULL ;
}
}
if ( ! -- V_2 -> V_23 ) {
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
return V_6 ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_28 ;
if ( -- V_2 -> V_23 > 0 )
goto V_35;
V_2 -> V_32 -> V_33 ( V_2 , V_36 , NULL ) ;
F_12 () ;
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
if ( ! -- V_26 ) {
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
F_10 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = NULL ;
}
}
V_35:
F_13 ( V_2 -> V_37 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_32 -> V_33 ( V_2 , V_38 , V_4 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_32 -> V_33 ( V_2 , V_39 , V_4 ) ;
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
T_2 V_40 = V_4 -> V_9 . V_41 ;
int V_6 = - V_11 ;
F_18 ( & V_42 ) ;
F_19 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_43 . type == V_40 &&
V_2 -> V_32 && V_2 -> V_32 -> V_33 &&
F_20 ( V_2 -> V_37 ) ) {
V_6 = F_16 ( V_2 , V_4 ) ;
if ( V_6 )
F_13 ( V_2 -> V_37 ) ;
break;
}
}
F_21 ( & V_42 ) ;
return V_6 ;
}
void F_22 ( struct V_3 * V_4 )
{
F_18 ( & V_42 ) ;
F_15 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( & V_42 ) ;
}
int F_23 ( struct V_3 * V_4 , int V_17 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 T_1 * V_44 ;
struct V_19 * V_20 ;
V_44 = V_2 -> V_25 ;
if ( F_24 ( ! V_44 ) )
return - V_11 ;
if ( ! ( V_17 & V_45 ) )
V_4 -> V_46 . V_47 = V_48 ;
V_20 = F_25 ( V_44 ) ;
F_26 ( & V_4 -> V_49 , V_20 ) ;
return V_2 -> V_32 -> V_33 ( V_2 , V_50 , V_4 ) ;
}
void F_27 ( struct V_3 * V_4 , int V_17 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_28 ( & V_4 -> V_49 ) ;
V_2 -> V_32 -> V_33 ( V_2 , V_51 , V_4 ) ;
}
T_3 void * F_29 ( int V_52 , unsigned short type ,
struct V_53 * V_54 , int * V_55 )
{
struct V_56 * V_57 ;
unsigned long V_17 ;
char * V_58 ;
int V_59 ;
F_30 ( V_60 % sizeof( unsigned long ) ) ;
if ( F_31 ( V_52 > V_60 ,
L_1 ) )
return NULL ;
V_59 = F_32 () ;
* V_55 = F_33 () ;
if ( * V_55 < 0 )
return NULL ;
V_58 = F_25 ( V_31 [ * V_55 ] ) ;
memset ( & V_58 [ V_52 - sizeof( T_2 ) ] , 0 , sizeof( T_2 ) ) ;
V_57 = (struct V_56 * ) V_58 ;
F_34 ( V_17 ) ;
F_35 ( V_57 , V_17 , V_59 ) ;
V_57 -> type = type ;
return V_58 ;
}
static void
F_36 ( unsigned long V_61 , unsigned long V_62 ,
struct V_63 * V_64 , struct V_53 * V_53 )
{
struct V_65 * V_57 ;
struct V_19 * V_66 ;
struct V_53 V_54 ;
int V_67 ;
V_66 = F_25 ( V_68 . V_25 ) ;
if ( F_37 ( V_66 ) )
return;
#define F_38 (ALIGN(sizeof(struct ftrace_entry) + sizeof(u32), \
sizeof(u64)) - sizeof(u32))
F_30 ( F_38 > V_60 ) ;
F_39 ( & V_54 ) ;
V_57 = F_29 ( F_38 , V_69 , NULL , & V_67 ) ;
if ( ! V_57 )
return;
V_57 -> V_61 = V_61 ;
V_57 -> V_62 = V_62 ;
F_40 ( V_57 , F_38 , V_67 , 0 ,
1 , & V_54 , V_66 , NULL ) ;
#undef F_38
}
static int F_41 ( struct V_3 * V_43 )
{
struct V_63 * V_64 = & V_43 -> V_63 ;
V_64 -> V_17 |= V_70 ;
V_64 -> V_71 = F_36 ;
return F_42 ( V_64 ) ;
}
static int F_43 ( struct V_3 * V_43 )
{
struct V_63 * V_64 = & V_43 -> V_63 ;
int V_6 = F_44 ( V_64 ) ;
F_45 ( V_64 ) ;
return V_6 ;
}
static void F_46 ( struct V_3 * V_43 )
{
F_47 ( & V_43 -> V_63 ) ;
}
static void F_48 ( struct V_3 * V_43 )
{
F_49 ( & V_43 -> V_63 ) ;
}
int F_50 ( struct V_1 * V_72 ,
enum V_73 type , void * V_74 )
{
switch ( type ) {
case V_75 :
case V_76 :
break;
case V_34 :
case V_36 :
return 0 ;
case V_38 :
return F_41 ( V_74 ) ;
case V_39 :
return F_43 ( V_74 ) ;
case V_50 :
F_46 ( V_74 ) ;
return 0 ;
case V_51 :
F_48 ( V_74 ) ;
return 0 ;
}
return - V_11 ;
}
