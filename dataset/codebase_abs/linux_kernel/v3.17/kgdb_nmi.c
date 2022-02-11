static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
V_4 -> V_5 = true ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , const char * V_6 , T_1 V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_4 -> V_9 ( V_6 [ V_8 ] ) ;
}
static struct V_10 * F_3 ( struct V_1 * V_2 , int * V_11 )
{
* V_11 = V_2 -> V_12 ;
return V_13 ;
}
static void F_4 ( int V_14 )
{
struct V_15 * V_16 ;
char V_7 = V_14 ;
if ( ! V_17 || V_14 < 0 )
return;
V_16 = F_5 ( V_17 , struct V_15 , V_18 ) ;
F_6 ( & V_16 -> V_19 , & V_7 , 1 ) ;
}
static int F_7 ( void )
{
static int V_20 ;
int V_7 = - 1 ;
const char * V_21 = V_22 ;
T_2 V_23 = strlen ( V_21 ) ;
bool V_24 = 0 ;
V_7 = V_4 -> V_25 () ;
if ( V_7 == V_26 )
return V_7 ;
if ( ! V_27 && ( V_7 == '\r' || V_7 == '\n' ) ) {
return 1 ;
} else if ( V_7 == V_21 [ V_20 ] ) {
V_20 = ( V_20 + 1 ) % V_23 ;
if ( ! V_20 )
return 1 ;
V_24 = 1 ;
} else {
V_20 = 0 ;
}
if ( F_8 ( & V_28 ) ) {
F_4 ( V_7 ) ;
return 0 ;
}
if ( V_24 ) {
F_9 ( L_1 , V_7 ) ;
return 0 ;
}
F_9 ( L_2 ,
V_27 ? L_3 : L_4 ,
V_27 ? V_21 : L_5 , ( int ) V_23 , L_6 ) ;
while ( V_23 -- )
F_9 ( L_7 ) ;
return 0 ;
}
bool F_10 ( void )
{
if ( V_27 < 0 )
return 1 ;
while ( 1 ) {
int V_29 ;
V_29 = F_7 () ;
if ( V_29 == V_26 )
return 0 ;
else if ( V_29 == 1 )
break;
}
return 1 ;
}
static void F_11 ( unsigned long V_30 )
{
struct V_15 * V_16 = ( void * ) V_30 ;
char V_14 ;
V_16 -> V_31 . V_32 = V_33 + ( V_34 / 100 ) ;
F_12 ( & V_16 -> V_31 ) ;
if ( F_13 ( ! F_8 ( & V_28 ) ||
! F_14 ( & V_16 -> V_19 ) ) )
return;
while ( F_15 ( & V_16 -> V_19 , & V_14 , 1 ) )
F_16 ( & V_16 -> V_18 , V_14 , V_35 ) ;
F_17 ( & V_16 -> V_18 ) ;
}
static int F_18 ( struct V_36 * V_18 , struct V_37 * V_38 )
{
struct V_15 * V_16 =
F_5 ( V_18 , struct V_15 , V_18 ) ;
V_17 = V_18 ;
V_16 -> V_31 . V_32 = V_33 + ( V_34 / 100 ) ;
F_12 ( & V_16 -> V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_36 * V_18 )
{
struct V_15 * V_16 =
F_5 ( V_18 , struct V_15 , V_18 ) ;
F_20 ( & V_16 -> V_31 ) ;
V_17 = NULL ;
}
static int F_21 ( struct V_10 * V_39 , struct V_37 * V_38 )
{
struct V_15 * V_16 ;
int V_29 ;
V_16 = F_22 ( sizeof( * V_16 ) , V_40 ) ;
if ( ! V_16 )
return - V_41 ;
F_23 ( V_16 -> V_19 ) ;
F_24 ( & V_16 -> V_31 , F_11 , ( unsigned long ) V_16 ) ;
F_25 ( & V_16 -> V_18 ) ;
V_16 -> V_18 . V_42 = & V_43 ;
V_38 -> V_44 = V_16 ;
V_29 = F_26 ( & V_16 -> V_18 , V_39 , V_38 ) ;
if ( V_29 ) {
F_27 ( L_8 , V_45 , V_29 ) ;
goto V_46;
}
return 0 ;
V_46:
F_28 ( & V_16 -> V_18 ) ;
F_29 ( V_16 ) ;
return V_29 ;
}
static void F_30 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_44 ;
V_38 -> V_44 = NULL ;
F_28 ( & V_16 -> V_18 ) ;
F_29 ( V_16 ) ;
}
static int F_31 ( struct V_37 * V_38 , struct V_47 * V_47 )
{
struct V_15 * V_16 = V_38 -> V_44 ;
unsigned int V_48 = V_47 -> V_49 & V_50 ;
int V_29 ;
V_29 = F_32 ( & V_16 -> V_18 , V_38 , V_47 ) ;
if ( ! V_29 && ( V_48 == V_51 || V_48 == V_52 ) )
F_33 ( & V_28 ) ;
return V_29 ;
}
static void F_34 ( struct V_37 * V_38 , struct V_47 * V_47 )
{
struct V_15 * V_16 = V_38 -> V_44 ;
unsigned int V_48 = V_47 -> V_49 & V_50 ;
if ( V_48 == V_51 || V_48 == V_52 )
F_35 ( & V_28 ) ;
F_36 ( & V_16 -> V_18 , V_38 , V_47 ) ;
}
static void F_37 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_44 ;
F_38 ( & V_16 -> V_18 ) ;
}
static int F_39 ( struct V_37 * V_38 )
{
return 2048 ;
}
static int F_40 ( struct V_37 * V_38 , const T_3 * V_53 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_4 -> V_9 ( V_53 [ V_8 ] ) ;
return V_7 ;
}
int F_41 ( void )
{
int V_29 ;
if ( ! V_54 . V_55 )
return 0 ;
V_13 = F_42 ( 1 ) ;
if ( ! V_13 ) {
F_27 ( L_9 , V_45 ) ;
return - V_41 ;
}
V_13 -> V_56 = L_10 ;
V_13 -> V_57 = L_10 ;
V_13 -> V_58 = 1 ;
V_13 -> type = V_59 ;
V_13 -> V_60 = V_61 ;
V_13 -> V_62 = V_63 ;
V_13 -> V_64 = V_65 ;
F_43 ( & V_13 -> V_64 ,
V_66 , V_66 ) ;
F_44 ( V_13 , & V_67 ) ;
V_29 = F_45 ( V_13 ) ;
if ( V_29 ) {
F_27 ( L_11 , V_45 , V_29 ) ;
goto V_68;
}
F_46 ( & V_69 ) ;
V_54 . V_55 ( 1 ) ;
return 0 ;
V_68:
F_47 ( V_13 ) ;
return V_29 ;
}
int F_48 ( void )
{
int V_29 ;
if ( ! V_54 . V_55 )
return 0 ;
V_54 . V_55 ( 0 ) ;
V_29 = F_49 ( & V_69 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_50 ( V_13 ) ;
if ( V_29 )
return V_29 ;
F_47 ( V_13 ) ;
return 0 ;
}
