static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 ) {
int V_6 = V_2 -> V_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_4 -> V_7 )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 () && ! F_4 ( V_8 ) )
return - V_9 ;
if ( ! F_5 ( V_4 ) )
return 0 ;
if ( ! V_4 -> V_10 . V_11 )
return - V_12 ;
if ( V_4 -> V_10 . V_13 & V_14 )
return - V_12 ;
}
if ( ! ( V_4 -> V_10 . V_13 & V_15 ) )
return 0 ;
if ( V_4 -> V_16 == V_17 ) {
if ( V_2 -> V_18 & V_19 )
return 0 ;
}
if ( F_3 () && ! F_4 ( V_8 ) )
return - V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_20 T_1 * V_21 ;
int V_6 = - V_22 ;
int V_23 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_24 ++ > 0 )
return 0 ;
V_21 = F_7 ( struct V_20 ) ;
if ( ! V_21 )
goto V_25;
F_8 (cpu)
F_9 ( F_10 ( V_21 , V_23 ) ) ;
V_2 -> V_26 = V_21 ;
if ( ! V_27 ) {
char T_1 * V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 = ( char T_1 * ) F_7 ( V_31 ) ;
if ( ! V_28 )
goto V_25;
V_32 [ V_29 ] = V_28 ;
}
}
V_6 = V_2 -> V_33 -> V_34 ( V_2 , V_35 , NULL ) ;
if ( V_6 )
goto V_25;
V_27 ++ ;
return 0 ;
V_25:
if ( ! V_27 ) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
F_11 ( V_32 [ V_29 ] ) ;
V_32 [ V_29 ] = NULL ;
}
}
if ( ! -- V_2 -> V_24 ) {
F_11 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
return V_6 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_29 ;
if ( -- V_2 -> V_24 > 0 )
goto V_36;
V_2 -> V_33 -> V_34 ( V_2 , V_37 , NULL ) ;
F_13 () ;
F_11 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
if ( ! -- V_27 ) {
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
F_11 ( V_32 [ V_29 ] ) ;
V_32 [ V_29 ] = NULL ;
}
}
V_36:
F_14 ( V_2 -> V_38 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_39 , V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_33 -> V_34 ( V_2 , V_40 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( V_4 ) ;
if ( V_6 ) {
F_12 ( V_4 ) ;
return V_6 ;
}
return 0 ;
}
int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
T_2 V_41 = V_4 -> V_10 . V_42 ;
int V_6 = - V_12 ;
F_19 ( & V_43 ) ;
F_20 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_44 . type == V_41 &&
V_2 -> V_33 && V_2 -> V_33 -> V_34 &&
F_21 ( V_2 -> V_38 ) ) {
V_6 = F_17 ( V_2 , V_4 ) ;
if ( V_6 )
F_14 ( V_2 -> V_38 ) ;
break;
}
}
F_22 ( & V_43 ) ;
return V_6 ;
}
void F_23 ( struct V_3 * V_4 )
{
F_19 ( & V_43 ) ;
F_16 ( V_4 ) ;
F_12 ( V_4 ) ;
F_22 ( & V_43 ) ;
}
int F_24 ( struct V_3 * V_4 , int V_18 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 T_1 * V_45 ;
struct V_20 * V_21 ;
V_45 = V_2 -> V_26 ;
if ( F_25 ( ! V_45 ) )
return - V_12 ;
if ( ! ( V_18 & V_46 ) )
V_4 -> V_47 . V_48 = V_49 ;
V_21 = F_26 ( V_45 ) ;
F_27 ( & V_4 -> V_50 , V_21 ) ;
return V_2 -> V_33 -> V_34 ( V_2 , V_51 , V_4 ) ;
}
void F_28 ( struct V_3 * V_4 , int V_18 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_29 ( & V_4 -> V_50 ) ;
V_2 -> V_33 -> V_34 ( V_2 , V_52 , V_4 ) ;
}
void * F_30 ( int V_53 , struct V_54 * * V_55 , int * V_56 )
{
char * V_57 ;
int V_58 ;
F_31 ( V_59 % sizeof( unsigned long ) ) ;
if ( F_32 ( V_53 > V_59 ,
L_1 ) )
return NULL ;
* V_56 = V_58 = F_33 () ;
if ( V_58 < 0 )
return NULL ;
if ( V_55 )
* V_55 = F_26 ( & V_60 [ V_58 ] ) ;
V_57 = F_26 ( V_32 [ V_58 ] ) ;
memset ( & V_57 [ V_53 - sizeof( T_2 ) ] , 0 , sizeof( T_2 ) ) ;
return V_57 ;
}
void F_34 ( void * V_61 , T_3 type )
{
struct V_62 * V_63 = V_61 ;
int V_64 = F_35 () ;
unsigned long V_18 ;
F_36 ( V_18 ) ;
F_37 ( V_63 , V_18 , V_64 ) ;
V_63 -> type = type ;
}
static void
F_38 ( unsigned long V_65 , unsigned long V_66 ,
struct V_67 * V_68 , struct V_54 * V_54 )
{
struct V_3 * V_44 ;
struct V_69 * V_63 ;
struct V_20 * V_70 ;
struct V_54 V_55 ;
int V_58 ;
V_70 = F_26 ( V_71 . V_26 ) ;
if ( F_39 ( V_70 ) )
return;
#define F_40 (ALIGN(sizeof(struct ftrace_entry) + sizeof(u32), \
sizeof(u64)) - sizeof(u32))
F_31 ( F_40 > V_59 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
F_41 ( & V_55 ) ;
V_63 = F_30 ( F_40 , NULL , & V_58 ) ;
if ( ! V_63 )
return;
V_63 -> V_65 = V_65 ;
V_63 -> V_66 = V_66 ;
V_44 = F_42 ( V_68 , struct V_3 , V_67 ) ;
F_43 ( V_63 , F_40 , V_58 , V_72 ,
1 , & V_55 , V_70 , NULL , V_44 ) ;
#undef F_40
}
static int F_44 ( struct V_3 * V_44 )
{
struct V_67 * V_68 = & V_44 -> V_67 ;
V_68 -> V_18 |= V_73 | V_74 ;
V_68 -> V_75 = F_38 ;
return F_45 ( V_68 ) ;
}
static int F_46 ( struct V_3 * V_44 )
{
struct V_67 * V_68 = & V_44 -> V_67 ;
int V_6 = F_47 ( V_68 ) ;
F_48 ( V_68 ) ;
return V_6 ;
}
static void F_49 ( struct V_3 * V_44 )
{
F_50 ( & V_44 -> V_67 ) ;
}
static void F_51 ( struct V_3 * V_44 )
{
F_52 ( & V_44 -> V_67 ) ;
}
int F_53 ( struct V_1 * V_76 ,
enum V_77 type , void * V_78 )
{
switch ( type ) {
case V_79 :
case V_80 :
break;
case V_35 :
case V_37 :
return 0 ;
case V_39 :
return F_44 ( V_78 ) ;
case V_40 :
return F_46 ( V_78 ) ;
case V_51 :
F_49 ( V_78 ) ;
return 0 ;
case V_52 :
F_51 ( V_78 ) ;
return 0 ;
}
return - V_12 ;
}
