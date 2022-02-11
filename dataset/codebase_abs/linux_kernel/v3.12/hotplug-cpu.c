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
if ( ! F_21 ( F_20 () ) )
F_20 () -> V_19 = 1 ;
while ( F_5 ( V_4 ) == V_15 ) {
while ( ! F_22 () ) {
F_23 () ;
F_9 () ;
}
F_24 ( V_14 ) ;
}
F_9 () ;
if ( ! F_21 ( F_20 () ) )
F_20 () -> V_19 = 0 ;
F_20 () -> V_18 = 0 ;
if ( F_5 ( V_4 ) == V_20 ) {
F_25 ( V_13 ) ;
F_26 () ;
F_27 () ;
}
}
F_28 ( F_5 ( V_4 ) != V_21 ) ;
F_4 ( V_4 , V_21 ) ;
F_25 ( V_13 ) ;
F_8 () ;
F_29 () ;
for(; ; ) ;
}
static int F_30 ( void )
{
int V_4 = F_12 () ;
F_31 ( V_4 , false ) ;
V_22 -> V_23 -- ;
if ( V_4 == V_24 )
V_24 = F_32 ( V_25 ) ;
F_33 () ;
return 0 ;
}
static void F_34 ( unsigned int V_4 )
{
int V_26 ;
int V_27 = 1 ;
unsigned int V_28 = F_35 ( V_4 ) ;
if ( F_5 ( V_4 ) == V_15 ) {
V_27 = 1 ;
for ( V_26 = 0 ; V_26 < 5000 ; V_26 ++ ) {
if ( F_2 ( V_4 ) == V_15 ) {
V_27 = 0 ;
break;
}
F_36 ( 1 ) ;
}
} else if ( F_5 ( V_4 ) == V_21 ) {
for ( V_26 = 0 ; V_26 < 25 ; V_26 ++ ) {
V_27 = F_37 ( V_28 ) ;
if ( V_27 == V_29 ||
V_27 == V_30 )
break;
F_38 () ;
}
}
if ( V_27 != 0 ) {
F_11 ( L_5 ,
V_4 , V_28 , V_27 ) ;
}
V_31 [ V_4 ] . V_32 = 0 ;
}
static int F_39 ( struct V_33 * V_34 )
{
unsigned int V_4 ;
T_3 V_35 , V_36 ;
int V_37 = - V_38 , V_39 , V_40 , V_41 ;
const T_4 * V_42 ;
V_42 = F_40 ( V_34 , L_6 , & V_39 ) ;
if ( ! V_42 )
return 0 ;
F_41 ( & V_35 , V_43 ) ;
F_41 ( & V_36 , V_43 ) ;
V_40 = V_39 / sizeof( T_4 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_42 ( V_41 , V_36 ) ;
F_43 () ;
F_10 ( ! F_44 ( V_44 , V_45 ) ) ;
F_45 ( V_35 , V_45 , V_44 ) ;
if ( F_46 ( V_35 ) ) {
F_11 ( V_46 L_7
L_8 , V_34 -> V_47 ,
F_47 ( V_45 ) ) ;
goto V_48;
}
while ( ! F_46 ( V_36 ) )
if ( F_44 ( V_36 , V_35 ) )
break;
else
F_48 ( V_36 , V_36 , V_40 ) ;
if ( F_46 ( V_36 ) ) {
F_11 ( V_46 L_9
L_10 , V_34 -> V_49 ,
V_40 ) ;
goto V_48;
}
F_49 (cpu, tmp) {
F_10 ( F_50 ( V_4 ) ) ;
F_51 ( V_4 , true ) ;
F_52 ( V_4 , * V_42 ++ ) ;
}
V_37 = 0 ;
V_48:
F_53 () ;
F_54 ( V_35 ) ;
F_54 ( V_36 ) ;
return V_37 ;
}
static void F_55 ( struct V_33 * V_34 )
{
unsigned int V_4 ;
int V_39 , V_40 , V_41 ;
const T_4 * V_42 ;
V_42 = F_40 ( V_34 , L_6 , & V_39 ) ;
if ( ! V_42 )
return;
V_40 = V_39 / sizeof( T_4 ) ;
F_43 () ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
F_56 (cpu) {
if ( F_35 ( V_4 ) != V_42 [ V_41 ] )
continue;
F_10 ( F_57 ( V_4 ) ) ;
F_51 ( V_4 , false ) ;
F_52 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_50 )
F_11 ( V_51 L_11
L_12 , V_42 [ V_41 ] ) ;
}
F_53 () ;
}
static int F_58 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
int V_37 = 0 ;
switch ( V_54 ) {
case V_56 :
V_37 = F_39 ( V_55 ) ;
break;
case V_57 :
F_55 ( V_55 ) ;
break;
}
return F_59 ( V_37 ) ;
}
static int F_60 ( void )
{
memset ( V_58 , 0 , V_59 ) ;
return F_61 ( F_62 ( L_13 ) , 3 , 1 ,
NULL ,
V_60 ,
F_15 ( V_58 ) ,
V_59 ) ;
}
static int T_1 F_63 ( void )
{
struct V_33 * V_34 ;
const char * V_61 ;
int V_4 ;
int V_62 ;
F_64 (np, L_14 ) {
V_61 = F_40 ( V_34 , L_15 , NULL ) ;
if ( strstr ( V_61 , L_16 ) ) {
F_65 ( V_34 ) ;
F_11 ( V_63 L_17
L_18 ) ;
return 0 ;
}
}
V_10 . V_11 = F_62 ( L_19 ) ;
V_62 = F_62 ( L_20 ) ;
if ( V_10 . V_11 == V_12 ||
V_62 == V_12 ) {
F_11 ( V_63 L_21
L_22 ) ;
return 0 ;
}
V_16 . V_64 = F_17 ;
V_65 -> V_66 = F_30 ;
V_65 -> V_64 = F_34 ;
if ( F_66 ( V_67 ) ) {
F_67 ( & V_68 ) ;
F_43 () ;
if ( V_2 && F_60 () == 0 ) {
V_8 = V_15 ;
F_68 (cpu)
F_7 ( V_4 ) ;
}
F_53 () ;
}
return 0 ;
}
