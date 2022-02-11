static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 ( V_2 ) &&
F_3 () && ! F_4 ( V_5 ) )
return - V_6 ;
if ( ! ( V_4 -> V_7 . V_8 & V_9 ) )
return 0 ;
if ( V_4 -> V_10 == V_11 ) {
if ( V_2 -> V_12 & V_13 )
return 0 ;
}
if ( F_5 () && ! F_4 ( V_5 ) )
return - V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_14 T_1 * V_15 ;
int V_16 = - V_17 ;
int V_18 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_19 ++ > 0 )
return 0 ;
V_15 = F_7 ( struct V_14 ) ;
if ( ! V_15 )
goto V_20;
F_8 (cpu)
F_9 ( F_10 ( V_15 , V_18 ) ) ;
V_2 -> V_21 = V_15 ;
if ( ! V_22 ) {
char T_1 * V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_23 = ( char T_1 * ) F_7 ( V_26 ) ;
if ( ! V_23 )
goto V_20;
V_27 [ V_24 ] = V_23 ;
}
}
V_16 = V_2 -> V_28 -> V_29 ( V_2 , V_30 , NULL ) ;
if ( V_16 )
goto V_20;
V_22 ++ ;
return 0 ;
V_20:
if ( ! V_22 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_11 ( V_27 [ V_24 ] ) ;
V_27 [ V_24 ] = NULL ;
}
}
if ( ! -- V_2 -> V_19 ) {
F_11 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
return V_16 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_24 ;
if ( -- V_2 -> V_19 > 0 )
goto V_31;
V_2 -> V_28 -> V_29 ( V_2 , V_32 , NULL ) ;
F_13 () ;
F_11 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
if ( ! -- V_22 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_11 ( V_27 [ V_24 ] ) ;
V_27 [ V_24 ] = NULL ;
}
}
V_31:
F_14 ( V_2 -> V_33 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_28 -> V_29 ( V_2 , V_34 , V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_28 -> V_29 ( V_2 , V_35 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_2 , V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_15 ( V_4 ) ;
if ( V_16 ) {
F_12 ( V_4 ) ;
return V_16 ;
}
return 0 ;
}
int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_36 = V_4 -> V_7 . V_37 ;
int V_16 = - V_38 ;
F_19 ( & V_39 ) ;
F_20 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_40 . type == V_36 &&
V_2 -> V_28 && V_2 -> V_28 -> V_29 &&
F_21 ( V_2 -> V_33 ) ) {
V_16 = F_17 ( V_2 , V_4 ) ;
if ( V_16 )
F_14 ( V_2 -> V_33 ) ;
break;
}
}
F_22 ( & V_39 ) ;
return V_16 ;
}
void F_23 ( struct V_3 * V_4 )
{
F_19 ( & V_39 ) ;
F_16 ( V_4 ) ;
F_12 ( V_4 ) ;
F_22 ( & V_39 ) ;
}
int F_24 ( struct V_3 * V_4 , int V_12 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 T_1 * V_41 ;
struct V_14 * V_15 ;
V_41 = V_2 -> V_21 ;
if ( F_25 ( ! V_41 ) )
return - V_38 ;
if ( ! ( V_12 & V_42 ) )
V_4 -> V_43 . V_44 = V_45 ;
V_15 = F_26 ( V_41 ) ;
F_27 ( & V_4 -> V_46 , V_15 ) ;
return V_2 -> V_28 -> V_29 ( V_2 , V_47 , V_4 ) ;
}
void F_28 ( struct V_3 * V_4 , int V_12 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_29 ( & V_4 -> V_46 ) ;
V_2 -> V_28 -> V_29 ( V_2 , V_48 , V_4 ) ;
}
T_2 void * F_30 ( int V_49 , unsigned short type ,
struct V_50 * V_51 , int * V_52 )
{
struct V_53 * V_54 ;
unsigned long V_12 ;
char * V_55 ;
int V_56 ;
F_31 ( V_57 % sizeof( unsigned long ) ) ;
if ( F_32 ( V_49 > V_57 ,
L_1 ) )
return NULL ;
V_56 = F_33 () ;
* V_52 = F_34 () ;
if ( * V_52 < 0 )
return NULL ;
V_55 = F_26 ( V_27 [ * V_52 ] ) ;
memset ( & V_55 [ V_49 - sizeof( V_58 ) ] , 0 , sizeof( V_58 ) ) ;
V_54 = (struct V_53 * ) V_55 ;
F_35 ( V_12 ) ;
F_36 ( V_54 , V_12 , V_56 ) ;
V_54 -> type = type ;
return V_55 ;
}
static void
F_37 ( unsigned long V_59 , unsigned long V_60 ,
struct V_61 * V_62 , struct V_50 * V_50 )
{
struct V_63 * V_54 ;
struct V_14 * V_64 ;
struct V_50 V_51 ;
int V_65 ;
V_64 = F_26 ( V_66 . V_21 ) ;
if ( F_38 ( V_64 ) )
return;
#define F_39 (ALIGN(sizeof(struct ftrace_entry) + sizeof(u32), \
sizeof(u64)) - sizeof(u32))
F_31 ( F_39 > V_57 ) ;
F_40 ( & V_51 ) ;
V_54 = F_30 ( F_39 , V_67 , NULL , & V_65 ) ;
if ( ! V_54 )
return;
V_54 -> V_59 = V_59 ;
V_54 -> V_60 = V_60 ;
F_41 ( V_54 , F_39 , V_65 , 0 ,
1 , & V_51 , V_64 , NULL ) ;
#undef F_39
}
static int F_42 ( struct V_3 * V_40 )
{
struct V_61 * V_62 = & V_40 -> V_61 ;
V_62 -> V_12 |= V_68 ;
V_62 -> V_69 = F_37 ;
return F_43 ( V_62 ) ;
}
static int F_44 ( struct V_3 * V_40 )
{
struct V_61 * V_62 = & V_40 -> V_61 ;
int V_16 = F_45 ( V_62 ) ;
F_46 ( V_62 ) ;
return V_16 ;
}
static void F_47 ( struct V_3 * V_40 )
{
F_48 ( & V_40 -> V_61 ) ;
}
static void F_49 ( struct V_3 * V_40 )
{
F_50 ( & V_40 -> V_61 ) ;
}
int F_51 ( struct V_1 * V_70 ,
enum V_71 type , void * V_72 )
{
switch ( type ) {
case V_73 :
case V_74 :
break;
case V_30 :
case V_32 :
return 0 ;
case V_34 :
return F_42 ( V_72 ) ;
case V_35 :
return F_44 ( V_72 ) ;
case V_47 :
F_47 ( V_72 ) ;
return 0 ;
case V_48 :
F_49 ( V_72 ) ;
return 0 ;
}
return - V_38 ;
}
