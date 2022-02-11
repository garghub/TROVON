static void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
int V_5 ;
if ( ! V_6 || F_2 ( & V_7 ) >= 0 )
return;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_8 -> V_9 ( V_3 [ V_5 ] ) ;
}
static struct V_10 * F_3 ( struct V_1 * V_2 , int * V_11 )
{
* V_11 = V_2 -> V_12 ;
return V_13 ;
}
static struct V_14 * F_4 ( struct V_15 * V_16 )
{
return F_5 ( V_16 , struct V_14 , V_16 ) ;
}
static void F_6 ( void )
{
F_7 ( F_8 () , 0 ) ;
}
static inline void F_6 ( void ) {}
static void F_9 ( int V_17 )
{
struct V_14 * V_18 ;
char V_4 = V_17 ;
if ( ! V_19 || V_17 < 0 )
return;
V_18 = F_4 ( V_19 ) ;
F_10 ( & V_18 -> V_20 , & V_4 , 1 ) ;
F_6 () ;
}
static int F_11 ( void )
{
static int V_21 ;
int V_4 = - 1 ;
const char * V_22 = V_23 ;
T_2 V_24 = strlen ( V_22 ) ;
bool V_25 = 0 ;
V_4 = V_8 -> V_26 () ;
if ( V_4 == V_27 )
return V_4 ;
if ( ! V_28 && ( V_4 == '\r' || V_4 == '\n' ) ) {
return 1 ;
} else if ( V_4 == V_22 [ V_21 ] ) {
V_21 = ( V_21 + 1 ) % V_24 ;
if ( ! V_21 )
return 1 ;
V_25 = 1 ;
} else {
V_21 = 0 ;
}
if ( V_6 ) {
F_9 ( V_4 ) ;
return 0 ;
}
if ( V_25 ) {
F_12 ( L_1 , V_4 ) ;
return 0 ;
}
F_12 ( L_2 ,
V_28 ? L_3 : L_4 ,
V_28 ? V_22 : L_5 , ( int ) V_24 , L_6 ) ;
while ( V_24 -- )
F_12 ( L_7 ) ;
return 0 ;
}
bool F_13 ( void )
{
if ( V_28 < 0 )
return 1 ;
while ( 1 ) {
int V_29 ;
V_29 = F_11 () ;
if ( V_29 == V_27 )
return 0 ;
else if ( V_29 == 1 )
break;
}
return 1 ;
}
static void F_14 ( unsigned long V_30 )
{
struct V_14 * V_18 = ( void * ) V_30 ;
struct V_31 * V_32 ;
char V_17 ;
F_15 ( & V_18 -> V_33 ) ;
if ( F_16 ( ! V_6 || ! F_17 ( & V_18 -> V_20 ) ) )
return;
V_32 = F_18 ( V_19 ) ;
if ( ! V_32 )
return;
while ( F_19 ( & V_18 -> V_20 , & V_17 , 1 ) )
F_20 ( V_18 -> V_16 . V_32 , V_17 , V_34 ) ;
F_21 ( V_18 -> V_16 . V_32 ) ;
F_22 ( V_32 ) ;
}
static int F_23 ( struct V_15 * V_16 , struct V_31 * V_32 )
{
struct V_14 * V_18 = V_32 -> V_35 ;
V_19 = V_16 ;
F_15 ( & V_18 -> V_33 ) ;
return 0 ;
}
static void F_24 ( struct V_15 * V_16 )
{
struct V_14 * V_18 = V_16 -> V_32 -> V_35 ;
F_25 ( & V_18 -> V_33 ) ;
V_19 = NULL ;
}
static int F_26 ( struct V_10 * V_36 , struct V_31 * V_32 )
{
struct V_14 * V_18 ;
int V_29 ;
V_18 = F_27 ( sizeof( * V_18 ) , V_37 ) ;
if ( ! V_18 )
return - V_38 ;
F_28 ( V_18 -> V_20 ) ;
F_29 ( & V_18 -> V_33 , F_14 , ( unsigned long ) V_18 ) ;
F_30 ( & V_18 -> V_16 ) ;
V_18 -> V_16 . V_39 = & V_40 ;
V_32 -> V_35 = V_18 ;
V_29 = F_31 ( & V_18 -> V_16 , V_36 , V_32 ) ;
if ( V_29 ) {
F_32 ( L_8 , V_41 , V_29 ) ;
goto V_42;
}
return 0 ;
V_42:
F_33 ( V_18 ) ;
return V_29 ;
}
static void F_34 ( struct V_31 * V_32 )
{
struct V_14 * V_18 = V_32 -> V_35 ;
V_32 -> V_35 = NULL ;
F_33 ( V_18 ) ;
}
static int F_35 ( struct V_31 * V_32 , struct V_43 * V_43 )
{
struct V_14 * V_18 = V_32 -> V_35 ;
return F_36 ( & V_18 -> V_16 , V_32 , V_43 ) ;
}
static void F_37 ( struct V_31 * V_32 , struct V_43 * V_43 )
{
struct V_14 * V_18 = V_32 -> V_35 ;
F_38 ( & V_18 -> V_16 , V_32 , V_43 ) ;
}
static void F_39 ( struct V_31 * V_32 )
{
struct V_14 * V_18 = V_32 -> V_35 ;
F_40 ( & V_18 -> V_16 ) ;
}
static int F_41 ( struct V_31 * V_32 )
{
return 2048 ;
}
static int F_42 ( struct V_31 * V_32 , const T_3 * V_44 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_8 -> V_9 ( V_44 [ V_5 ] ) ;
return V_4 ;
}
static int F_43 ( int V_45 , const char * V_46 [] )
{
V_6 = ! ( V_45 == 1 && ! strcmp ( V_46 [ 1 ] , L_9 ) ) ;
return 0 ;
}
int F_44 ( void )
{
int V_29 ;
if ( ! V_47 . V_48 )
return 0 ;
V_13 = F_45 ( 1 ) ;
if ( ! V_13 ) {
F_32 ( L_10 , V_41 ) ;
return - V_38 ;
}
V_13 -> V_49 = L_11 ;
V_13 -> V_50 = L_11 ;
V_13 -> V_51 = 1 ;
V_13 -> type = V_52 ;
V_13 -> V_53 = V_54 ;
V_13 -> V_55 = V_56 ;
V_13 -> V_57 = V_58 ;
F_46 ( & V_13 -> V_57 ,
V_59 , V_59 ) ;
F_47 ( V_13 , & V_60 ) ;
V_29 = F_48 ( V_13 ) ;
if ( V_29 ) {
F_32 ( L_12 , V_41 , V_29 ) ;
goto V_61;
}
V_29 = F_49 ( L_13 , F_43 , L_14 ,
L_15 , 0 ) ;
if ( V_29 ) {
F_32 ( L_16 , V_41 , V_29 ) ;
goto V_62;
}
F_50 ( & V_63 ) ;
V_47 . V_48 ( 1 ) ;
return 0 ;
V_62:
F_51 ( V_13 ) ;
V_61:
F_52 ( V_13 ) ;
return V_29 ;
}
int F_53 ( void )
{
int V_29 ;
if ( ! V_47 . V_48 )
return 0 ;
V_47 . V_48 ( 0 ) ;
F_54 ( L_13 ) ;
V_29 = F_55 ( & V_63 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_51 ( V_13 ) ;
if ( V_29 )
return V_29 ;
F_52 ( V_13 ) ;
return 0 ;
}
