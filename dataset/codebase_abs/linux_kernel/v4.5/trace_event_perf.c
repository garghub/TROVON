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
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_20 T_1 * V_21 ;
int V_6 = - V_22 ;
int V_23 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_24 ++ > 0 )
return 0 ;
V_21 = F_6 ( struct V_20 ) ;
if ( ! V_21 )
goto V_25;
F_7 (cpu)
F_8 ( F_9 ( V_21 , V_23 ) ) ;
V_2 -> V_26 = V_21 ;
if ( ! V_27 ) {
char T_1 * V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 = ( char T_1 * ) F_6 ( V_31 ) ;
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
F_10 ( V_32 [ V_29 ] ) ;
V_32 [ V_29 ] = NULL ;
}
}
if ( ! -- V_2 -> V_24 ) {
F_10 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
return V_6 ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_29 ;
if ( -- V_2 -> V_24 > 0 )
goto V_36;
V_2 -> V_33 -> V_34 ( V_2 , V_37 , NULL ) ;
F_12 () ;
F_10 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
if ( ! -- V_27 ) {
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
F_10 ( V_32 [ V_29 ] ) ;
V_32 [ V_29 ] = NULL ;
}
}
V_36:
F_13 ( V_2 -> V_38 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_39 , V_4 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_33 -> V_34 ( V_2 , V_40 , V_4 ) ;
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
T_2 V_41 = V_4 -> V_10 . V_42 ;
int V_6 = - V_12 ;
F_18 ( & V_43 ) ;
F_19 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_44 . type == V_41 &&
V_2 -> V_33 && V_2 -> V_33 -> V_34 &&
F_20 ( V_2 -> V_38 ) ) {
V_6 = F_16 ( V_2 , V_4 ) ;
if ( V_6 )
F_13 ( V_2 -> V_38 ) ;
break;
}
}
F_21 ( & V_43 ) ;
return V_6 ;
}
void F_22 ( struct V_3 * V_4 )
{
F_18 ( & V_43 ) ;
F_15 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( & V_43 ) ;
}
int F_23 ( struct V_3 * V_4 , int V_18 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 T_1 * V_45 ;
struct V_20 * V_21 ;
V_45 = V_2 -> V_26 ;
if ( F_24 ( ! V_45 ) )
return - V_12 ;
if ( ! ( V_18 & V_46 ) )
V_4 -> V_47 . V_48 = V_49 ;
V_21 = F_25 ( V_45 ) ;
F_26 ( & V_4 -> V_50 , V_21 ) ;
return V_2 -> V_33 -> V_34 ( V_2 , V_51 , V_4 ) ;
}
void F_27 ( struct V_3 * V_4 , int V_18 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_28 ( & V_4 -> V_50 ) ;
V_2 -> V_33 -> V_34 ( V_2 , V_52 , V_4 ) ;
}
void * F_29 ( int V_53 , unsigned short type ,
struct V_54 * * V_55 , int * V_56 )
{
struct V_57 * V_58 ;
unsigned long V_18 ;
char * V_59 ;
int V_60 ;
F_30 ( V_61 % sizeof( unsigned long ) ) ;
if ( F_31 ( V_53 > V_61 ,
L_1 ) )
return NULL ;
V_60 = F_32 () ;
* V_56 = F_33 () ;
if ( * V_56 < 0 )
return NULL ;
if ( V_55 )
* V_55 = F_25 ( & V_62 [ * V_56 ] ) ;
V_59 = F_25 ( V_32 [ * V_56 ] ) ;
memset ( & V_59 [ V_53 - sizeof( T_2 ) ] , 0 , sizeof( T_2 ) ) ;
V_58 = (struct V_57 * ) V_59 ;
F_34 ( V_18 ) ;
F_35 ( V_58 , V_18 , V_60 ) ;
V_58 -> type = type ;
return V_59 ;
}
static void
F_36 ( unsigned long V_63 , unsigned long V_64 ,
struct V_65 * V_66 , struct V_54 * V_54 )
{
struct V_67 * V_58 ;
struct V_20 * V_68 ;
struct V_54 V_55 ;
int V_69 ;
V_68 = F_25 ( V_70 . V_26 ) ;
if ( F_37 ( V_68 ) )
return;
#define F_38 (ALIGN(sizeof(struct ftrace_entry) + sizeof(u32), \
sizeof(u64)) - sizeof(u32))
F_30 ( F_38 > V_61 ) ;
F_39 ( & V_55 ) ;
V_58 = F_29 ( F_38 , V_71 , NULL , & V_69 ) ;
if ( ! V_58 )
return;
V_58 -> V_63 = V_63 ;
V_58 -> V_64 = V_64 ;
F_40 ( V_58 , F_38 , V_69 , 0 ,
1 , & V_55 , V_68 , NULL ) ;
#undef F_38
}
static int F_41 ( struct V_3 * V_44 )
{
struct V_65 * V_66 = & V_44 -> V_65 ;
V_66 -> V_18 |= V_72 | V_73 ;
V_66 -> V_74 = F_36 ;
return F_42 ( V_66 ) ;
}
static int F_43 ( struct V_3 * V_44 )
{
struct V_65 * V_66 = & V_44 -> V_65 ;
int V_6 = F_44 ( V_66 ) ;
F_45 ( V_66 ) ;
return V_6 ;
}
static void F_46 ( struct V_3 * V_44 )
{
F_47 ( & V_44 -> V_65 ) ;
}
static void F_48 ( struct V_3 * V_44 )
{
F_49 ( & V_44 -> V_65 ) ;
}
int F_50 ( struct V_1 * V_75 ,
enum V_76 type , void * V_77 )
{
switch ( type ) {
case V_78 :
case V_79 :
break;
case V_35 :
case V_37 :
return 0 ;
case V_39 :
return F_41 ( V_77 ) ;
case V_40 :
return F_43 ( V_77 ) ;
case V_51 :
F_46 ( V_77 ) ;
return 0 ;
case V_52 :
F_48 ( V_77 ) ;
return 0 ;
}
return - V_12 ;
}
