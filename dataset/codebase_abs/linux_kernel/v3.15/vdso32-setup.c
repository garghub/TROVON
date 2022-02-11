static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
if ( V_2 > 1 )
F_3 ( L_1 ) ;
return 1 ;
}
void F_4 ( void )
{
F_5 ( V_3 , ( V_4 ) V_5 ) ;
F_5 ( V_6 , 0ULL ) ;
F_5 ( V_7 , ( V_4 ) V_8 ) ;
F_6 ( V_9 , V_10 ) ;
}
void F_7 ( void )
{
int V_11 = F_8 () ;
struct V_12 * V_13 = & F_9 ( V_14 , V_11 ) ;
if ( ! F_10 ( V_15 ) ) {
F_11 () ;
return;
}
V_13 -> V_16 . V_17 = V_5 ;
V_13 -> V_16 . V_18 = sizeof( struct V_12 ) + ( unsigned long ) V_13 ;
F_12 ( V_3 , V_5 , 0 ) ;
F_12 ( V_6 , V_13 -> V_16 . V_18 , 0 ) ;
F_12 ( V_7 , ( unsigned long ) V_8 , 0 ) ;
F_11 () ;
}
int T_1 F_13 ( void )
{
char * V_19 , * V_20 ;
int V_21 , V_22 ;
#ifdef F_14
if ( F_15 () ) {
V_19 = V_23 ;
V_20 = V_24 ;
V_25 = V_26 ;
} else
#endif
if ( F_16 () ) {
V_19 = V_27 ;
V_20 = V_28 ;
V_25 = V_29 ;
} else {
V_19 = V_30 ;
V_20 = V_31 ;
V_25 = V_32 ;
}
V_21 = ( ( V_20 - V_19 ) + V_33 - 1 ) / V_33 ;
V_34 = V_21 << V_35 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
V_25 [ V_22 ] = F_17 ( V_19 + V_22 * V_33 ) ;
F_18 ( V_19 , V_34 ) ;
return 0 ;
}
int F_19 ( struct V_36 * V_37 , int V_38 )
{
struct V_39 * V_40 = V_41 -> V_40 ;
unsigned long V_42 ;
int V_43 = 0 ;
struct V_44 * V_45 ;
static struct V_46 * V_47 [] = { NULL } ;
#ifdef F_20
if ( F_21 ( V_48 ) )
return F_22 ( V_37 , V_38 ) ;
#endif
if ( V_2 != 1 )
return 0 ;
F_23 ( & V_40 -> V_49 ) ;
V_42 = F_24 ( NULL , 0 , V_34 + F_25 ( V_50 ) , 0 , 0 ) ;
if ( F_26 ( V_42 ) ) {
V_43 = V_42 ;
goto V_51;
}
V_42 += F_25 ( V_50 ) ;
V_41 -> V_40 -> V_52 . V_53 = ( void * ) V_42 ;
V_43 = F_27 ( V_40 ,
V_42 ,
V_34 ,
V_54 | V_55 |
V_56 | V_57 | V_58 ,
V_25 ) ;
if ( V_43 )
goto V_51;
V_45 = F_28 ( V_40 ,
V_42 - F_25 ( V_50 ) ,
F_25 ( V_50 ) ,
V_54 ,
V_47 ) ;
if ( F_29 ( V_45 ) ) {
V_43 = F_30 ( V_45 ) ;
goto V_51;
}
V_43 = F_31 ( V_45 ,
V_42 - F_25 ( V_59 ) ,
F_32 ( & V_60 ) >> V_35 ,
V_33 ,
V_61 ) ;
if ( V_43 )
goto V_51;
#ifdef F_33
if ( V_62 ) {
V_43 = F_34 ( V_45 ,
V_42 - F_25 ( V_63 ) ,
V_62 >> V_35 ,
V_33 ,
F_35 ( V_61 ) ) ;
if ( V_43 )
goto V_51;
}
#endif
F_36 () -> V_64 =
F_37 ( V_42 , V_65 ) ;
V_51:
if ( V_43 )
V_41 -> V_40 -> V_52 . V_53 = NULL ;
F_38 ( & V_40 -> V_49 ) ;
return V_43 ;
}
static T_1 int F_39 ( void )
{
F_40 ( V_66 ) ;
return 0 ;
}
const char * F_41 ( struct V_44 * V_45 )
{
if ( V_45 -> V_67 && V_45 -> V_68 == ( long ) V_45 -> V_67 -> V_52 . V_53 )
return L_2 ;
return NULL ;
}
struct V_44 * F_42 ( struct V_39 * V_40 )
{
return NULL ;
}
int F_43 ( struct V_39 * V_40 , unsigned long V_42 )
{
return 0 ;
}
int F_44 ( unsigned long V_42 )
{
return 0 ;
}
