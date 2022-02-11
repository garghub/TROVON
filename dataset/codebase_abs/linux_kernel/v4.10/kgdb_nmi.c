static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
V_4 . V_5 ( 1 ) ;
V_6 -> V_7 = true ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , const char * V_8 , T_1 V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_6 -> V_11 ( V_8 [ V_10 ] ) ;
}
static struct V_12 * F_3 ( struct V_1 * V_2 , int * V_13 )
{
* V_13 = V_2 -> V_14 ;
return V_15 ;
}
static void F_4 ( int V_16 )
{
struct V_17 * V_18 ;
char V_9 = V_16 ;
if ( ! V_19 || V_16 < 0 )
return;
V_18 = F_5 ( V_19 , struct V_17 , V_20 ) ;
F_6 ( & V_18 -> V_21 , & V_9 , 1 ) ;
}
static int F_7 ( void )
{
static int V_22 ;
int V_9 = - 1 ;
const char * V_23 = V_24 ;
T_2 V_25 = strlen ( V_23 ) ;
bool V_26 = 0 ;
V_9 = V_6 -> V_27 () ;
if ( V_9 == V_28 )
return V_9 ;
if ( ! V_29 && ( V_9 == '\r' || V_9 == '\n' ) ) {
return 1 ;
} else if ( V_9 == V_23 [ V_22 ] ) {
V_22 = ( V_22 + 1 ) % V_25 ;
if ( ! V_22 )
return 1 ;
V_26 = 1 ;
} else {
V_22 = 0 ;
}
if ( F_8 ( & V_30 ) ) {
F_4 ( V_9 ) ;
return 0 ;
}
if ( V_26 ) {
F_9 ( L_1 , V_9 ) ;
return 0 ;
}
F_9 ( L_2 ,
V_29 ? L_3 : L_4 ,
V_29 ? V_23 : L_5 , ( int ) V_25 , L_6 ) ;
while ( V_25 -- )
F_9 ( L_7 ) ;
return 0 ;
}
bool F_10 ( void )
{
if ( V_29 < 0 )
return true ;
while ( 1 ) {
int V_31 ;
V_31 = F_7 () ;
if ( V_31 == V_28 )
return false ;
else if ( V_31 == 1 )
break;
}
return true ;
}
static void F_11 ( unsigned long V_32 )
{
struct V_17 * V_18 = ( void * ) V_32 ;
char V_16 ;
V_18 -> V_33 . V_34 = V_35 + ( V_36 / 100 ) ;
F_12 ( & V_18 -> V_33 ) ;
if ( F_13 ( ! F_8 ( & V_30 ) ||
! F_14 ( & V_18 -> V_21 ) ) )
return;
while ( F_15 ( & V_18 -> V_21 , & V_16 , 1 ) )
F_16 ( & V_18 -> V_20 , V_16 , V_37 ) ;
F_17 ( & V_18 -> V_20 ) ;
}
static int F_18 ( struct V_38 * V_20 , struct V_39 * V_40 )
{
struct V_17 * V_18 =
F_5 ( V_20 , struct V_17 , V_20 ) ;
V_19 = V_20 ;
V_18 -> V_33 . V_34 = V_35 + ( V_36 / 100 ) ;
F_12 ( & V_18 -> V_33 ) ;
return 0 ;
}
static void F_19 ( struct V_38 * V_20 )
{
struct V_17 * V_18 =
F_5 ( V_20 , struct V_17 , V_20 ) ;
F_20 ( & V_18 -> V_33 ) ;
V_19 = NULL ;
}
static int F_21 ( struct V_12 * V_41 , struct V_39 * V_40 )
{
struct V_17 * V_18 ;
int V_31 ;
V_18 = F_22 ( sizeof( * V_18 ) , V_42 ) ;
if ( ! V_18 )
return - V_43 ;
F_23 ( V_18 -> V_21 ) ;
F_24 ( & V_18 -> V_33 , F_11 , ( unsigned long ) V_18 ) ;
F_25 ( & V_18 -> V_20 ) ;
V_18 -> V_20 . V_44 = & V_45 ;
V_40 -> V_46 = V_18 ;
V_31 = F_26 ( & V_18 -> V_20 , V_41 , V_40 ) ;
if ( V_31 ) {
F_27 ( L_8 , V_47 , V_31 ) ;
goto V_48;
}
return 0 ;
V_48:
F_28 ( & V_18 -> V_20 ) ;
F_29 ( V_18 ) ;
return V_31 ;
}
static void F_30 ( struct V_39 * V_40 )
{
struct V_17 * V_18 = V_40 -> V_46 ;
V_40 -> V_46 = NULL ;
F_28 ( & V_18 -> V_20 ) ;
F_29 ( V_18 ) ;
}
static int F_31 ( struct V_39 * V_40 , struct V_49 * V_49 )
{
struct V_17 * V_18 = V_40 -> V_46 ;
unsigned int V_50 = V_49 -> V_51 & V_52 ;
int V_31 ;
V_31 = F_32 ( & V_18 -> V_20 , V_40 , V_49 ) ;
if ( ! V_31 && ( V_50 == V_53 || V_50 == V_54 ) )
F_33 ( & V_30 ) ;
return V_31 ;
}
static void F_34 ( struct V_39 * V_40 , struct V_49 * V_49 )
{
struct V_17 * V_18 = V_40 -> V_46 ;
unsigned int V_50 = V_49 -> V_51 & V_52 ;
if ( V_50 == V_53 || V_50 == V_54 )
F_35 ( & V_30 ) ;
F_36 ( & V_18 -> V_20 , V_40 , V_49 ) ;
}
static void F_37 ( struct V_39 * V_40 )
{
struct V_17 * V_18 = V_40 -> V_46 ;
F_38 ( & V_18 -> V_20 ) ;
}
static int F_39 ( struct V_39 * V_40 )
{
return 2048 ;
}
static int F_40 ( struct V_39 * V_40 , const T_3 * V_55 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_6 -> V_11 ( V_55 [ V_10 ] ) ;
return V_9 ;
}
int F_41 ( void )
{
int V_31 ;
if ( ! V_4 . V_5 )
return 0 ;
V_15 = F_42 ( 1 ) ;
if ( ! V_15 ) {
F_27 ( L_9 , V_47 ) ;
return - V_43 ;
}
V_15 -> V_56 = L_10 ;
V_15 -> V_57 = L_10 ;
V_15 -> V_58 = 1 ;
V_15 -> type = V_59 ;
V_15 -> V_60 = V_61 ;
V_15 -> V_62 = V_63 ;
V_15 -> V_64 = V_65 ;
F_43 ( & V_15 -> V_64 ,
V_66 , V_66 ) ;
F_44 ( V_15 , & V_67 ) ;
V_31 = F_45 ( V_15 ) ;
if ( V_31 ) {
F_27 ( L_11 , V_47 , V_31 ) ;
goto V_68;
}
F_46 ( & V_69 ) ;
return 0 ;
V_68:
F_47 ( V_15 ) ;
return V_31 ;
}
int F_48 ( void )
{
int V_31 ;
if ( ! V_4 . V_5 )
return 0 ;
V_4 . V_5 ( 0 ) ;
V_31 = F_49 ( & V_69 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_50 ( V_15 ) ;
if ( V_31 )
return V_31 ;
F_47 ( V_15 ) ;
return 0 ;
}
