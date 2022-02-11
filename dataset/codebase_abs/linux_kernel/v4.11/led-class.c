static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_10 ;
T_1 V_11 ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 ) ) {
V_11 = - V_13 ;
goto V_14;
}
V_11 = F_7 ( V_5 , 10 , & V_10 ) ;
if ( V_11 )
goto V_14;
if ( V_10 == V_15 )
F_8 ( V_7 ) ;
F_9 ( V_7 , V_10 ) ;
V_11 = V_9 ;
V_14:
F_10 ( & V_7 -> V_12 ) ;
return V_11 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_16 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_17 == - 1 )
return - V_18 ;
return sprintf ( V_5 , L_1 , V_7 -> V_17 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_11 ;
V_11 = F_14 ( V_2 , & V_19 ) ;
if ( V_11 ) {
F_15 ( V_2 , L_2 ) ;
return V_11 ;
}
V_7 -> V_20 =
F_16 ( V_2 -> V_21 . V_22 , L_3 ) ;
if ( ! V_7 -> V_20 ) {
F_15 ( V_2 , L_4 ) ;
F_17 ( V_2 , & V_19 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
F_19 ( V_7 -> V_20 ) ;
F_17 ( V_7 -> V_2 , & V_19 ) ;
}
void F_20 ( struct V_6 * V_7 ,
enum V_24 V_8 )
{
if ( F_21 ( ! V_7 -> V_20 ) )
return;
V_7 -> V_17 = V_8 ;
F_22 ( V_7 -> V_20 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
}
void F_23 ( struct V_6 * V_7 )
{
V_7 -> V_25 |= V_26 ;
F_24 ( V_7 , 0 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
F_24 ( V_7 , V_7 -> V_8 ) ;
if ( V_7 -> V_27 )
V_7 -> V_27 ( V_7 ) ;
V_7 -> V_25 &= ~ V_26 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_25 & V_28 )
F_23 ( V_7 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_25 & V_28 )
F_25 ( V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const void * V_29 )
{
if ( ! F_29 ( V_2 ) )
return 0 ;
return ! strcmp ( F_29 ( V_2 ) , ( char * ) V_29 ) ;
}
static int F_30 ( const char * V_30 , char * V_31 ,
T_2 V_32 )
{
unsigned int V_33 = 0 ;
int V_11 = 0 ;
struct V_1 * V_2 ;
F_31 ( V_31 , V_30 , V_32 ) ;
while ( ( V_11 < V_32 ) &&
( V_2 = F_32 ( V_34 , NULL , V_31 , F_28 ) ) ) {
F_33 ( V_2 ) ;
V_11 = snprintf ( V_31 , V_32 , L_5 , V_30 , ++ V_33 ) ;
}
if ( V_11 >= V_32 )
return - V_35 ;
return V_33 ;
}
int F_34 ( struct V_1 * V_36 , struct V_6 * V_7 )
{
char V_31 [ V_37 ] ;
int V_11 ;
V_11 = F_30 ( V_7 -> V_31 , V_31 , sizeof( V_31 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_7 -> V_2 = F_35 ( V_34 , V_36 , 0 ,
V_7 , V_7 -> V_38 , L_6 , V_31 ) ;
if ( F_36 ( V_7 -> V_2 ) )
return F_37 ( V_7 -> V_2 ) ;
if ( V_11 )
F_38 ( V_36 , L_7 ,
V_7 -> V_31 , F_29 ( V_7 -> V_2 ) ) ;
if ( V_7 -> V_25 & V_39 ) {
V_11 = F_13 ( V_7 ) ;
if ( V_11 ) {
F_39 ( V_7 -> V_2 ) ;
return V_11 ;
}
}
V_7 -> V_40 = 0 ;
#ifdef F_40
F_41 ( & V_7 -> V_41 ) ;
#endif
#ifdef F_42
V_7 -> V_17 = - 1 ;
#endif
F_43 ( & V_7 -> V_12 ) ;
F_44 ( & V_42 ) ;
F_45 ( & V_7 -> V_43 , & V_44 ) ;
F_46 ( & V_42 ) ;
if ( ! V_7 -> V_16 )
V_7 -> V_16 = V_45 ;
F_3 ( V_7 ) ;
F_47 ( V_7 ) ;
#ifdef F_40
F_48 ( V_7 ) ;
#endif
F_49 ( V_36 , L_8 ,
V_7 -> V_31 ) ;
return 0 ;
}
void F_50 ( struct V_6 * V_7 )
{
#ifdef F_40
F_44 ( & V_7 -> V_41 ) ;
if ( V_7 -> V_46 )
F_51 ( V_7 , NULL ) ;
F_46 ( & V_7 -> V_41 ) ;
#endif
V_7 -> V_25 |= V_47 ;
F_52 ( V_7 ) ;
F_9 ( V_7 , V_15 ) ;
F_53 ( & V_7 -> V_48 ) ;
if ( V_7 -> V_25 & V_39 )
F_18 ( V_7 ) ;
F_39 ( V_7 -> V_2 ) ;
F_44 ( & V_42 ) ;
F_54 ( & V_7 -> V_43 ) ;
F_46 ( & V_42 ) ;
F_55 ( & V_7 -> V_12 ) ;
}
static void F_56 ( struct V_1 * V_2 , void * V_49 )
{
F_50 ( * (struct V_6 * * ) V_49 ) ;
}
int F_57 ( struct V_1 * V_36 ,
struct V_6 * V_7 )
{
struct V_6 * * V_50 ;
int V_51 ;
V_50 = F_58 ( F_56 , sizeof( * V_50 ) , V_52 ) ;
if ( ! V_50 )
return - V_35 ;
V_51 = F_34 ( V_36 , V_7 ) ;
if ( V_51 ) {
F_59 ( V_50 ) ;
return V_51 ;
}
* V_50 = V_7 ;
F_60 ( V_36 , V_50 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_49 , void * V_29 )
{
struct V_7 * * V_53 = V_49 ;
if ( F_21 ( ! V_53 || ! * V_53 ) )
return 0 ;
return * V_53 == V_29 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_21 ( F_63 ( V_2 ,
F_56 ,
F_61 , V_7 ) ) ;
}
static int T_3 F_64 ( void )
{
V_34 = F_65 ( V_54 , L_9 ) ;
if ( F_36 ( V_34 ) )
return F_37 ( V_34 ) ;
V_34 -> V_55 = & V_56 ;
V_34 -> V_57 = V_58 ;
return 0 ;
}
static void T_4 F_66 ( void )
{
F_67 ( V_34 ) ;
}
