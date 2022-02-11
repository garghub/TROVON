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
void F_12 ( struct V_6 * V_7 )
{
V_7 -> V_17 |= V_18 ;
V_7 -> V_19 ( V_7 , 0 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
V_7 -> V_19 ( V_7 , V_7 -> V_8 ) ;
if ( V_7 -> V_20 )
V_7 -> V_20 ( V_7 ) ;
V_7 -> V_17 &= ~ V_18 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_17 & V_21 )
F_12 ( V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_17 & V_21 )
F_13 ( V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_22 )
{
if ( ! F_17 ( V_2 ) )
return 0 ;
return ! strcmp ( F_17 ( V_2 ) , ( char * ) V_22 ) ;
}
static int F_18 ( const char * V_23 , char * V_24 ,
T_2 V_25 )
{
unsigned int V_26 = 0 ;
int V_11 = 0 ;
struct V_1 * V_2 ;
F_19 ( V_24 , V_23 , V_25 ) ;
while ( ( V_11 < V_25 ) &&
( V_2 = F_20 ( V_27 , NULL , V_24 , F_16 ) ) ) {
F_21 ( V_2 ) ;
V_11 = snprintf ( V_24 , V_25 , L_2 , V_23 , ++ V_26 ) ;
}
if ( V_11 >= V_25 )
return - V_28 ;
return V_26 ;
}
int F_22 ( struct V_1 * V_29 , struct V_6 * V_7 )
{
char V_24 [ 64 ] ;
int V_11 ;
V_11 = F_18 ( V_7 -> V_24 , V_24 , sizeof( V_24 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_7 -> V_2 = F_23 ( V_27 , V_29 , 0 ,
V_7 , V_7 -> V_30 , L_3 , V_24 ) ;
if ( F_24 ( V_7 -> V_2 ) )
return F_25 ( V_7 -> V_2 ) ;
if ( V_11 )
F_26 ( V_29 , L_4 ,
V_7 -> V_24 , F_17 ( V_7 -> V_2 ) ) ;
#ifdef F_27
F_28 ( & V_7 -> V_31 ) ;
#endif
F_29 ( & V_7 -> V_12 ) ;
F_30 ( & V_32 ) ;
F_31 ( & V_7 -> V_33 , & V_34 ) ;
F_32 ( & V_32 ) ;
if ( ! V_7 -> V_16 )
V_7 -> V_16 = V_35 ;
V_7 -> V_17 |= V_36 ;
F_3 ( V_7 ) ;
F_33 ( V_7 ) ;
#ifdef F_27
F_34 ( V_7 ) ;
#endif
F_35 ( V_29 , L_5 ,
V_7 -> V_24 ) ;
return 0 ;
}
void F_36 ( struct V_6 * V_7 )
{
#ifdef F_27
F_30 ( & V_7 -> V_31 ) ;
if ( V_7 -> V_37 )
F_37 ( V_7 , NULL ) ;
F_32 ( & V_7 -> V_31 ) ;
#endif
F_38 ( & V_7 -> V_38 ) ;
F_39 ( V_7 ) ;
F_9 ( V_7 , V_15 ) ;
F_40 ( V_7 -> V_2 ) ;
F_30 ( & V_32 ) ;
F_41 ( & V_7 -> V_33 ) ;
F_32 ( & V_32 ) ;
F_42 ( & V_7 -> V_12 ) ;
}
static void F_43 ( struct V_1 * V_2 , void * V_39 )
{
F_36 ( * (struct V_6 * * ) V_39 ) ;
}
int F_44 ( struct V_1 * V_29 ,
struct V_6 * V_7 )
{
struct V_6 * * V_40 ;
int V_41 ;
V_40 = F_45 ( F_43 , sizeof( * V_40 ) , V_42 ) ;
if ( ! V_40 )
return - V_28 ;
V_41 = F_22 ( V_29 , V_7 ) ;
if ( V_41 ) {
F_46 ( V_40 ) ;
return V_41 ;
}
* V_40 = V_7 ;
F_47 ( V_29 , V_40 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_39 , void * V_22 )
{
struct V_7 * * V_43 = V_39 ;
if ( F_49 ( ! V_43 || ! * V_43 ) )
return 0 ;
return * V_43 == V_22 ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_49 ( F_51 ( V_2 ,
F_43 ,
F_48 , V_7 ) ) ;
}
static int T_3 F_52 ( void )
{
V_27 = F_53 ( V_44 , L_6 ) ;
if ( F_24 ( V_27 ) )
return F_25 ( V_27 ) ;
V_27 -> V_45 = & V_46 ;
V_27 -> V_47 = V_48 ;
return 0 ;
}
static void T_4 F_54 ( void )
{
F_55 ( V_27 ) ;
}
