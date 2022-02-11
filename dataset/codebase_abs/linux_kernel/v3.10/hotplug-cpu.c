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
struct V_9 * args = & V_10 ;
F_9 () ;
F_10 ( args -> V_11 == V_12 ) ;
F_11 ( L_3 ,
F_12 () , F_13 () ) ;
F_14 ( F_15 ( args ) ) ;
F_16 ( L_4 ) ;
}
static void F_17 ( void )
{
unsigned int V_4 = F_12 () ;
unsigned int V_13 = F_13 () ;
T_2 V_14 = 0 ;
F_9 () ;
F_18 () ;
F_19 () ;
if ( F_5 ( V_4 ) == V_15 ) {
F_4 ( V_4 , V_15 ) ;
if ( V_16 . V_17 )
V_16 . V_17 () ;
V_14 = 2 ;
F_20 () -> V_18 = 1 ;
if ( ! F_20 () -> V_19 )
F_20 () -> V_20 = 1 ;
while ( F_5 ( V_4 ) == V_15 ) {
while ( ! F_21 () ) {
F_22 () ;
F_9 () ;
}
F_23 ( V_14 ) ;
}
F_9 () ;
if ( ! F_20 () -> V_19 )
F_20 () -> V_20 = 0 ;
F_20 () -> V_18 = 0 ;
if ( F_5 ( V_4 ) == V_21 ) {
F_24 ( V_13 ) ;
F_25 () ;
F_26 () ;
}
}
F_27 ( F_5 ( V_4 ) != V_22 ) ;
F_4 ( V_4 , V_22 ) ;
F_24 ( V_13 ) ;
F_8 () ;
F_28 () ;
for(; ; ) ;
}
static int F_29 ( void )
{
int V_4 = F_12 () ;
F_30 ( V_4 , false ) ;
V_23 -> V_24 -- ;
if ( V_4 == V_25 )
V_25 = F_31 ( V_26 ) ;
F_32 () ;
return 0 ;
}
static void F_33 ( unsigned int V_4 )
{
int V_27 ;
int V_28 = 1 ;
unsigned int V_29 = F_34 ( V_4 ) ;
if ( F_5 ( V_4 ) == V_15 ) {
V_28 = 1 ;
for ( V_27 = 0 ; V_27 < 5000 ; V_27 ++ ) {
if ( F_2 ( V_4 ) == V_15 ) {
V_28 = 0 ;
break;
}
F_35 ( 1 ) ;
}
} else if ( F_5 ( V_4 ) == V_22 ) {
for ( V_27 = 0 ; V_27 < 25 ; V_27 ++ ) {
V_28 = F_36 ( V_29 ) ;
if ( V_28 == V_30 ||
V_28 == V_31 )
break;
F_37 () ;
}
}
if ( V_28 != 0 ) {
F_11 ( L_5 ,
V_4 , V_29 , V_28 ) ;
}
V_32 [ V_4 ] . V_33 = 0 ;
}
static int F_38 ( struct V_34 * V_35 )
{
unsigned int V_4 ;
T_3 V_36 , V_37 ;
int V_38 = - V_39 , V_40 , V_41 , V_42 ;
const T_4 * V_43 ;
V_43 = F_39 ( V_35 , L_6 , & V_40 ) ;
if ( ! V_43 )
return 0 ;
F_40 ( & V_36 , V_44 ) ;
F_40 ( & V_37 , V_44 ) ;
V_41 = V_40 / sizeof( T_4 ) ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
F_41 ( V_42 , V_37 ) ;
F_42 () ;
F_10 ( ! F_43 ( V_45 , V_46 ) ) ;
F_44 ( V_36 , V_46 , V_45 ) ;
if ( F_45 ( V_36 ) ) {
F_11 ( V_47 L_7
L_8 , V_35 -> V_48 ,
F_46 ( V_46 ) ) ;
goto V_49;
}
while ( ! F_45 ( V_37 ) )
if ( F_43 ( V_37 , V_36 ) )
break;
else
F_47 ( V_37 , V_37 , V_41 ) ;
if ( F_45 ( V_37 ) ) {
F_11 ( V_47 L_9
L_10 , V_35 -> V_50 ,
V_41 ) ;
goto V_49;
}
F_48 (cpu, tmp) {
F_10 ( F_49 ( V_4 ) ) ;
F_50 ( V_4 , true ) ;
F_51 ( V_4 , * V_43 ++ ) ;
}
V_38 = 0 ;
V_49:
F_52 () ;
F_53 ( V_36 ) ;
F_53 ( V_37 ) ;
return V_38 ;
}
static void F_54 ( struct V_34 * V_35 )
{
unsigned int V_4 ;
int V_40 , V_41 , V_42 ;
const T_4 * V_43 ;
V_43 = F_39 ( V_35 , L_6 , & V_40 ) ;
if ( ! V_43 )
return;
V_41 = V_40 / sizeof( T_4 ) ;
F_42 () ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
F_55 (cpu) {
if ( F_34 ( V_4 ) != V_43 [ V_42 ] )
continue;
F_10 ( F_56 ( V_4 ) ) ;
F_50 ( V_4 , false ) ;
F_51 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_51 )
F_11 ( V_52 L_11
L_12 , V_43 [ V_42 ] ) ;
}
F_52 () ;
}
static int F_57 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
int V_38 = 0 ;
switch ( V_55 ) {
case V_57 :
V_38 = F_38 ( V_56 ) ;
break;
case V_58 :
F_54 ( V_56 ) ;
break;
}
return F_58 ( V_38 ) ;
}
static int F_59 ( void )
{
memset ( V_59 , 0 , V_60 ) ;
return F_60 ( F_61 ( L_13 ) , 3 , 1 ,
NULL ,
V_61 ,
F_15 ( V_59 ) ,
V_60 ) ;
}
static int T_1 F_62 ( void )
{
struct V_34 * V_35 ;
const char * V_62 ;
int V_4 ;
int V_63 ;
F_63 (np, L_14 ) {
V_62 = F_39 ( V_35 , L_15 , NULL ) ;
if ( strstr ( V_62 , L_16 ) ) {
F_64 ( V_35 ) ;
F_11 ( V_64 L_17
L_18 ) ;
return 0 ;
}
}
V_10 . V_11 = F_61 ( L_19 ) ;
V_63 = F_61 ( L_20 ) ;
if ( V_10 . V_11 == V_12 ||
V_63 == V_12 ) {
F_11 ( V_64 L_21
L_22 ) ;
return 0 ;
}
V_16 . V_65 = F_17 ;
V_66 -> V_67 = F_29 ;
V_66 -> V_65 = F_33 ;
if ( F_65 ( V_68 ) ) {
F_66 ( & V_69 ) ;
F_42 () ;
if ( V_2 && F_59 () == 0 ) {
V_8 = V_15 ;
F_67 (cpu)
F_7 ( V_4 ) ;
}
F_52 () ;
}
return 0 ;
}
