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
F_13 ( V_7 , 0 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
F_13 ( V_7 , V_7 -> V_8 ) ;
if ( V_7 -> V_19 )
V_7 -> V_19 ( V_7 ) ;
V_7 -> V_17 &= ~ V_18 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_17 & V_20 )
F_12 ( V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_17 & V_20 )
F_14 ( V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_21 )
{
if ( ! F_18 ( V_2 ) )
return 0 ;
return ! strcmp ( F_18 ( V_2 ) , ( char * ) V_21 ) ;
}
static int F_19 ( const char * V_22 , char * V_23 ,
T_2 V_24 )
{
unsigned int V_25 = 0 ;
int V_11 = 0 ;
struct V_1 * V_2 ;
F_20 ( V_23 , V_22 , V_24 ) ;
while ( ( V_11 < V_24 ) &&
( V_2 = F_21 ( V_26 , NULL , V_23 , F_17 ) ) ) {
F_22 ( V_2 ) ;
V_11 = snprintf ( V_23 , V_24 , L_2 , V_22 , ++ V_25 ) ;
}
if ( V_11 >= V_24 )
return - V_27 ;
return V_25 ;
}
int F_23 ( struct V_1 * V_28 , struct V_6 * V_7 )
{
char V_23 [ 64 ] ;
int V_11 ;
V_11 = F_19 ( V_7 -> V_23 , V_23 , sizeof( V_23 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_7 -> V_2 = F_24 ( V_26 , V_28 , 0 ,
V_7 , V_7 -> V_29 , L_3 , V_23 ) ;
if ( F_25 ( V_7 -> V_2 ) )
return F_26 ( V_7 -> V_2 ) ;
if ( V_11 )
F_27 ( V_28 , L_4 ,
V_7 -> V_23 , F_18 ( V_7 -> V_2 ) ) ;
#ifdef F_28
F_29 ( & V_7 -> V_30 ) ;
#endif
F_30 ( & V_7 -> V_12 ) ;
F_31 ( & V_31 ) ;
F_32 ( & V_7 -> V_32 , & V_33 ) ;
F_33 ( & V_31 ) ;
if ( ! V_7 -> V_16 )
V_7 -> V_16 = V_34 ;
F_3 ( V_7 ) ;
F_34 ( V_7 ) ;
#ifdef F_28
F_35 ( V_7 ) ;
#endif
F_36 ( V_28 , L_5 ,
V_7 -> V_23 ) ;
return 0 ;
}
void F_37 ( struct V_6 * V_7 )
{
#ifdef F_28
F_31 ( & V_7 -> V_30 ) ;
if ( V_7 -> V_35 )
F_38 ( V_7 , NULL ) ;
F_33 ( & V_7 -> V_30 ) ;
#endif
F_39 ( V_7 ) ;
F_9 ( V_7 , V_15 ) ;
F_40 ( & V_7 -> V_36 ) ;
F_41 ( V_7 -> V_2 ) ;
F_31 ( & V_31 ) ;
F_42 ( & V_7 -> V_32 ) ;
F_33 ( & V_31 ) ;
F_43 ( & V_7 -> V_12 ) ;
}
static void F_44 ( struct V_1 * V_2 , void * V_37 )
{
F_37 ( * (struct V_6 * * ) V_37 ) ;
}
int F_45 ( struct V_1 * V_28 ,
struct V_6 * V_7 )
{
struct V_6 * * V_38 ;
int V_39 ;
V_38 = F_46 ( F_44 , sizeof( * V_38 ) , V_40 ) ;
if ( ! V_38 )
return - V_27 ;
V_39 = F_23 ( V_28 , V_7 ) ;
if ( V_39 ) {
F_47 ( V_38 ) ;
return V_39 ;
}
* V_38 = V_7 ;
F_48 ( V_28 , V_38 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , void * V_37 , void * V_21 )
{
struct V_7 * * V_41 = V_37 ;
if ( F_50 ( ! V_41 || ! * V_41 ) )
return 0 ;
return * V_41 == V_21 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_50 ( F_52 ( V_2 ,
F_44 ,
F_49 , V_7 ) ) ;
}
static int T_3 F_53 ( void )
{
V_26 = F_54 ( V_42 , L_6 ) ;
if ( F_25 ( V_26 ) )
return F_26 ( V_26 ) ;
V_26 -> V_43 = & V_44 ;
V_26 -> V_45 = V_46 ;
return 0 ;
}
static void T_4 F_55 ( void )
{
F_56 ( V_26 ) ;
}
