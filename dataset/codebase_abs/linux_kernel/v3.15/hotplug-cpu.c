static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 = 0 ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 = 1 ;
else
return 0 ;
return 1 ;
}
enum V_3 F_2 ( int V_4 )
{
return F_3 ( V_5 , V_4 ) ;
}
void F_4 ( int V_4 , enum V_3 V_6 )
{
F_3 ( V_5 , V_4 ) = V_6 ;
}
enum V_3 F_5 ( int V_4 )
{
return F_3 ( V_7 , V_4 ) ;
}
void F_6 ( int V_4 , enum V_3 V_6 )
{
F_3 ( V_7 , V_4 ) = V_6 ;
}
void F_7 ( int V_4 )
{
F_3 ( V_7 , V_4 ) = V_8 ;
}
static void F_8 ( void )
{
static struct V_9 args = {
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & args . args [ 0 ] ,
} ;
args . V_13 = F_9 ( V_14 ) ;
F_10 () ;
F_11 ( V_14 == V_15 ) ;
F_12 ( L_3 ,
F_13 () , F_14 () ) ;
F_15 ( F_16 ( & args ) ) ;
F_17 ( L_4 ) ;
}
static void F_18 ( void )
{
unsigned int V_4 = F_13 () ;
unsigned int V_16 = F_14 () ;
T_2 V_17 = 0 ;
F_10 () ;
F_19 () ;
F_20 () ;
if ( F_5 ( V_4 ) == V_18 ) {
F_4 ( V_4 , V_18 ) ;
if ( V_19 . V_20 )
V_19 . V_20 () ;
V_17 = 2 ;
F_21 () -> V_21 = 1 ;
if ( ! F_22 ( F_21 () ) )
F_21 () -> V_22 = 1 ;
while ( F_5 ( V_4 ) == V_18 ) {
while ( ! F_23 () ) {
F_24 () ;
F_10 () ;
}
F_25 ( V_17 ) ;
}
F_10 () ;
if ( ! F_22 ( F_21 () ) )
F_21 () -> V_22 = 0 ;
F_21 () -> V_21 = 0 ;
if ( F_5 ( V_4 ) == V_23 ) {
F_26 ( V_16 ) ;
F_27 () ;
F_28 () ;
}
}
F_29 ( F_5 ( V_4 ) != V_24 ) ;
F_4 ( V_4 , V_24 ) ;
F_26 ( V_16 ) ;
F_8 () ;
F_30 () ;
for(; ; ) ;
}
static int F_31 ( void )
{
int V_4 = F_13 () ;
F_32 ( V_4 , false ) ;
V_25 -> V_26 -- ;
if ( V_4 == V_27 )
V_27 = F_33 ( V_28 ) ;
F_34 () ;
return 0 ;
}
static void F_35 ( unsigned int V_4 )
{
int V_29 ;
int V_30 = 1 ;
unsigned int V_31 = F_36 ( V_4 ) ;
if ( F_5 ( V_4 ) == V_18 ) {
V_30 = 1 ;
for ( V_29 = 0 ; V_29 < 5000 ; V_29 ++ ) {
if ( F_2 ( V_4 ) == V_18 ) {
V_30 = 0 ;
break;
}
F_37 ( 1 ) ;
}
} else if ( F_5 ( V_4 ) == V_24 ) {
for ( V_29 = 0 ; V_29 < 25 ; V_29 ++ ) {
V_30 = F_38 ( V_31 ) ;
if ( V_30 == V_32 ||
V_30 == V_33 )
break;
F_39 () ;
}
}
if ( V_30 != 0 ) {
F_12 ( L_5 ,
V_4 , V_31 , V_30 ) ;
}
V_34 [ V_4 ] . V_35 = 0 ;
}
static int F_40 ( struct V_36 * V_37 )
{
unsigned int V_4 ;
T_3 V_38 , V_39 ;
int V_40 = - V_41 , V_42 , V_43 , V_44 ;
const T_4 * V_45 ;
V_45 = F_41 ( V_37 , L_6 , & V_42 ) ;
if ( ! V_45 )
return 0 ;
F_42 ( & V_38 , V_46 ) ;
F_42 ( & V_39 , V_46 ) ;
V_43 = V_42 / sizeof( T_4 ) ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
F_43 ( V_44 , V_39 ) ;
F_44 () ;
F_11 ( ! F_45 ( V_47 , V_48 ) ) ;
F_46 ( V_38 , V_48 , V_47 ) ;
if ( F_47 ( V_38 ) ) {
F_12 ( V_49 L_7
L_8 , V_37 -> V_50 ,
F_48 ( V_48 ) ) ;
goto V_51;
}
while ( ! F_47 ( V_39 ) )
if ( F_45 ( V_39 , V_38 ) )
break;
else
F_49 ( V_39 , V_39 , V_43 ) ;
if ( F_47 ( V_39 ) ) {
F_12 ( V_49 L_9
L_10 , V_37 -> V_52 ,
V_43 ) ;
goto V_51;
}
F_50 (cpu, tmp) {
F_11 ( F_51 ( V_4 ) ) ;
F_52 ( V_4 , true ) ;
F_53 ( V_4 , * V_45 ++ ) ;
}
V_40 = 0 ;
V_51:
F_54 () ;
F_55 ( V_38 ) ;
F_55 ( V_39 ) ;
return V_40 ;
}
static void F_56 ( struct V_36 * V_37 )
{
unsigned int V_4 ;
int V_42 , V_43 , V_44 ;
const T_4 * V_45 ;
V_45 = F_41 ( V_37 , L_6 , & V_42 ) ;
if ( ! V_45 )
return;
V_43 = V_42 / sizeof( T_4 ) ;
F_44 () ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
F_57 (cpu) {
if ( F_36 ( V_4 ) != V_45 [ V_44 ] )
continue;
F_11 ( F_58 ( V_4 ) ) ;
F_52 ( V_4 , false ) ;
F_53 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_53 )
F_12 ( V_54 L_11
L_12 , V_45 [ V_44 ] ) ;
}
F_54 () ;
}
static int F_59 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
int V_40 = 0 ;
switch ( V_57 ) {
case V_59 :
V_40 = F_40 ( V_58 ) ;
break;
case V_60 :
F_56 ( V_58 ) ;
break;
}
return F_60 ( V_40 ) ;
}
static int F_61 ( void )
{
memset ( V_61 , 0 , V_62 ) ;
return F_62 ( F_63 ( L_13 ) , 3 , 1 ,
NULL ,
V_63 ,
F_16 ( V_61 ) ,
V_62 ) ;
}
static int T_1 F_64 ( void )
{
struct V_36 * V_37 ;
const char * V_64 ;
int V_4 ;
int V_65 ;
F_65 (np, L_14 ) {
V_64 = F_41 ( V_37 , L_15 , NULL ) ;
if ( strstr ( V_64 , L_16 ) ) {
F_66 ( V_37 ) ;
F_12 ( V_66 L_17
L_18 ) ;
return 0 ;
}
}
V_14 = F_63 ( L_19 ) ;
V_65 = F_63 ( L_20 ) ;
if ( V_14 == V_15 ||
V_65 == V_15 ) {
F_12 ( V_66 L_21
L_22 ) ;
return 0 ;
}
V_19 . V_67 = F_18 ;
V_68 -> V_69 = F_31 ;
V_68 -> V_67 = F_35 ;
if ( F_67 ( V_70 ) ) {
F_68 ( & V_71 ) ;
F_44 () ;
if ( V_2 && F_61 () == 0 ) {
V_8 = V_18 ;
F_69 (cpu)
F_7 ( V_4 ) ;
}
F_54 () ;
}
return 0 ;
}
