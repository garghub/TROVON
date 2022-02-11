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
static void F_12 ( unsigned long V_17 )
{
struct V_6 * V_7 = ( void * ) V_17 ;
unsigned long V_8 ;
unsigned long V_18 ;
if ( ! V_7 -> V_19 || ! V_7 -> V_20 ) {
F_13 ( V_7 , V_15 ) ;
return;
}
if ( V_7 -> V_21 & V_22 ) {
V_7 -> V_21 &= ~ V_22 ;
return;
}
V_8 = F_14 ( V_7 ) ;
if ( ! V_8 ) {
if ( V_7 -> V_23 ) {
V_7 -> V_24 =
V_7 -> V_23 ;
V_7 -> V_23 = 0 ;
}
V_8 = V_7 -> V_24 ;
V_18 = V_7 -> V_19 ;
} else {
V_7 -> V_24 = V_8 ;
V_8 = V_15 ;
V_18 = V_7 -> V_20 ;
}
F_13 ( V_7 , V_8 ) ;
if ( V_7 -> V_21 & V_25 ) {
if ( V_7 -> V_21 & V_26 ) {
if ( V_8 )
V_7 -> V_21 |= V_22 ;
} else {
if ( ! V_8 )
V_7 -> V_21 |= V_22 ;
}
}
F_15 ( & V_7 -> V_27 , V_28 + F_16 ( V_18 ) ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_6 * V_7 =
F_18 ( V_30 , struct V_6 , V_31 ) ;
F_19 ( V_7 ) ;
F_13 ( V_7 , V_7 -> V_23 ) ;
}
void F_20 ( struct V_6 * V_7 )
{
V_7 -> V_21 |= V_32 ;
V_7 -> V_33 ( V_7 , 0 ) ;
}
void F_21 ( struct V_6 * V_7 )
{
V_7 -> V_33 ( V_7 , V_7 -> V_8 ) ;
if ( V_7 -> V_34 )
V_7 -> V_34 ( V_7 ) ;
V_7 -> V_21 &= ~ V_32 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_21 & V_35 )
F_20 ( V_7 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_21 & V_35 )
F_21 ( V_7 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , const void * V_17 )
{
if ( ! F_25 ( V_2 ) )
return 0 ;
return ! strcmp ( F_25 ( V_2 ) , ( char * ) V_17 ) ;
}
static int F_26 ( const char * V_36 , char * V_37 ,
T_2 V_38 )
{
unsigned int V_39 = 0 ;
int V_11 = 0 ;
struct V_1 * V_2 ;
F_27 ( V_37 , V_36 , V_38 ) ;
while ( ( V_11 < V_38 ) &&
( V_2 = F_28 ( V_40 , NULL , V_37 , F_24 ) ) ) {
F_29 ( V_2 ) ;
V_11 = snprintf ( V_37 , V_38 , L_2 , V_36 , ++ V_39 ) ;
}
if ( V_11 >= V_38 )
return - V_41 ;
return V_39 ;
}
int F_30 ( struct V_1 * V_42 , struct V_6 * V_7 )
{
char V_37 [ 64 ] ;
int V_11 ;
V_11 = F_26 ( V_7 -> V_37 , V_37 , sizeof( V_37 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_7 -> V_2 = F_31 ( V_40 , V_42 , 0 ,
V_7 , V_7 -> V_43 , L_3 , V_37 ) ;
if ( F_32 ( V_7 -> V_2 ) )
return F_33 ( V_7 -> V_2 ) ;
if ( V_11 )
F_34 ( V_42 , L_4 ,
V_7 -> V_37 , F_25 ( V_7 -> V_2 ) ) ;
#ifdef F_35
F_36 ( & V_7 -> V_44 ) ;
#endif
F_37 ( & V_7 -> V_12 ) ;
F_38 ( & V_45 ) ;
F_39 ( & V_7 -> V_46 , & V_47 ) ;
F_40 ( & V_45 ) ;
if ( ! V_7 -> V_16 )
V_7 -> V_16 = V_48 ;
V_7 -> V_21 |= V_49 ;
F_3 ( V_7 ) ;
F_41 ( & V_7 -> V_31 , F_17 ) ;
F_42 ( & V_7 -> V_27 , F_12 ,
( unsigned long ) V_7 ) ;
#ifdef F_35
F_43 ( V_7 ) ;
#endif
F_44 ( V_42 , L_5 ,
V_7 -> V_37 ) ;
return 0 ;
}
void F_45 ( struct V_6 * V_7 )
{
#ifdef F_35
F_38 ( & V_7 -> V_44 ) ;
if ( V_7 -> V_50 )
F_46 ( V_7 , NULL ) ;
F_40 ( & V_7 -> V_44 ) ;
#endif
F_47 ( & V_7 -> V_31 ) ;
F_19 ( V_7 ) ;
F_9 ( V_7 , V_15 ) ;
F_48 ( V_7 -> V_2 ) ;
F_38 ( & V_45 ) ;
F_49 ( & V_7 -> V_46 ) ;
F_40 ( & V_45 ) ;
F_50 ( & V_7 -> V_12 ) ;
}
static void F_51 ( struct V_1 * V_2 , void * V_51 )
{
F_45 ( * (struct V_6 * * ) V_51 ) ;
}
int F_52 ( struct V_1 * V_42 ,
struct V_6 * V_7 )
{
struct V_6 * * V_52 ;
int V_53 ;
V_52 = F_53 ( F_51 , sizeof( * V_52 ) , V_54 ) ;
if ( ! V_52 )
return - V_41 ;
V_53 = F_30 ( V_42 , V_7 ) ;
if ( V_53 ) {
F_54 ( V_52 ) ;
return V_53 ;
}
* V_52 = V_7 ;
F_55 ( V_42 , V_52 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , void * V_51 , void * V_17 )
{
struct V_7 * * V_55 = V_51 ;
if ( F_57 ( ! V_55 || ! * V_55 ) )
return 0 ;
return * V_55 == V_17 ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_57 ( F_59 ( V_2 ,
F_51 ,
F_56 , V_7 ) ) ;
}
static int T_3 F_60 ( void )
{
V_40 = F_61 ( V_56 , L_6 ) ;
if ( F_32 ( V_40 ) )
return F_33 ( V_40 ) ;
V_40 -> V_57 = & V_58 ;
V_40 -> V_59 = V_60 ;
return 0 ;
}
static void T_4 F_62 ( void )
{
F_63 ( V_40 ) ;
}
