static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 . type != V_2 -> V_4 . type )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_6 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
}
static T_1 int F_4 ( void )
{
if ( ! V_7 )
return - V_8 ;
F_5 ( & V_3 , L_1 , - 1 ) ;
F_6 ( V_9 L_2 , V_7 ) ;
return 0 ;
}
static T_1 int F_4 ( void ) { return 0 ; }
static T_1 T_2 F_7 ( void )
{
T_2 V_10 ;
unsigned int V_11 ;
if ( ! F_8 ( V_12 ) )
return 0 ;
V_11 = F_9 ( 0x80000000 ) ;
if ( V_11 < V_13 )
return V_14 ;
V_10 = F_9 ( V_13 ) ;
if ( ! ( V_10 & V_15 ) )
return V_14 ;
return V_10 ;
}
T_2 F_10 ( void )
{
return V_7 ;
}
static inline int F_11 ( int V_16 )
{
return ! F_12 ( V_16 , 0 , V_17 , 1 ) ;
}
static inline int F_13 ( int V_16 )
{
return ! F_12 ( V_16 , 0 , 0 , 1 ) ;
}
static inline int F_14 ( void )
{
int V_16 ;
T_3 V_18 ;
int V_19 = 0 ;
F_15 () ;
F_16 ( V_20 , V_18 ) ;
V_16 = V_18 & V_21 ;
if ( ! ( V_18 & V_22 ) ) {
F_17 ( V_23 L_3 ,
F_18 () , V_16 , V_20 , V_18 ) ;
goto V_24;
}
if ( ! F_11 ( V_16 ) ) {
F_17 ( V_23 L_4 ,
F_18 () , V_16 , V_20 , V_18 ) ;
goto V_24;
}
V_19 = 1 ;
V_24:
F_19 () ;
return V_19 ;
}
static int F_20 ( int V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
T_2 V_29 = 0 ;
V_28 = 0 ;
V_27 = NULL ;
do {
V_27 = F_21 ( V_30 ,
V_31 ,
V_27 ) ;
if ( ! V_27 )
break;
++ V_28 ;
F_22 ( V_27 , V_32 , V_25
| V_22 ) ;
F_23 ( V_27 , V_32 , & V_29 ) ;
if ( V_29 != ( V_25 | V_22 ) ) {
F_24 ( V_27 ) ;
F_6 ( V_33 L_5
L_6 , V_29 ) ;
return - V_34 ;
}
} while ( 1 );
if ( ! V_28 ) {
F_6 ( V_33 L_7 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_25 ( void )
{
int V_16 ;
int V_35 ;
F_15 () ;
for ( V_16 = 1 ; V_16 < V_36 ; V_16 ++ ) {
if ( F_11 ( V_16 ) )
break;
}
F_19 () ;
if ( V_16 == V_36 ) {
F_6 ( V_33 L_8 ) ;
return - V_37 ;
}
V_35 = F_20 ( V_16 ) ;
if ( V_35 )
goto V_24;
if ( ! F_14 () ) {
V_35 = - V_38 ;
goto V_24;
}
F_26 ( L_9 , V_16 ) ;
return 0 ;
V_24:
F_15 () ;
F_13 ( V_16 ) ;
F_19 () ;
return V_35 ;
}
static inline int F_27 ( void )
{
T_3 V_18 ;
F_16 ( V_20 , V_18 ) ;
if ( ! ( V_18 & V_22 ) )
return - V_34 ;
return V_18 & V_21 ;
}
static void F_28 ( void * V_39 )
{
int V_16 ;
V_16 = F_27 () ;
if ( V_16 < 0 )
goto V_40;
if ( ! F_12 ( V_16 , 0 , V_17 , 0 ) )
return;
V_40:
F_29 ( L_10 ,
F_18 () ) ;
}
static void F_30 ( void * V_39 )
{
int V_16 ;
V_16 = F_27 () ;
if ( V_16 >= 0 )
F_12 ( V_16 , 0 , V_41 , 1 ) ;
}
static int T_4
F_31 ( struct V_42 * V_43 , unsigned long V_44 , void * V_45 )
{
switch ( V_44 & ~ V_46 ) {
case V_47 :
F_28 ( NULL ) ;
break;
case V_48 :
F_30 ( NULL ) ;
break;
default:
break;
}
return V_49 ;
}
static T_1 int F_32 ( void )
{
T_2 V_10 ;
int V_35 = - V_34 ;
V_10 = F_7 () ;
if ( ! V_10 )
return - V_8 ;
if ( V_50 . V_51 == 0x10 )
F_25 () ;
if ( ! F_14 () )
goto V_24;
F_33 () ;
V_7 = V_10 ;
F_34 () ;
F_35 ( F_31 ) ;
F_36 ( F_28 , NULL , 1 ) ;
F_37 () ;
V_35 = F_4 () ;
V_24:
if ( V_35 )
F_17 ( L_11 , V_35 ) ;
return V_35 ;
}
