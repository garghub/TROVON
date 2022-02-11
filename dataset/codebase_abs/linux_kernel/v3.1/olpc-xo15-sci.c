static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( L_1 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_3 ) ;
}
}
static void F_5 ( void )
{
struct V_1 * V_2 = F_2 ( L_2 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_3 ) ;
}
}
static void F_6 ( void )
{
T_1 V_4 ;
int V_5 ;
do {
V_5 = F_7 ( & V_4 ) ;
if ( V_5 || ! V_4 )
break;
F_8 ( V_6 L_3 , V_4 ) ;
switch ( V_4 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
F_1 () ;
break;
case V_11 :
F_5 () ;
break;
}
} while ( V_4 );
if ( V_5 )
F_9 ( V_6 L_4 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
F_6 () ;
}
static T_2 F_11 ( T_3 V_14 , T_2 V_15 , void * V_16 )
{
F_12 ( & V_17 ) ;
return V_18 | V_19 ;
}
static int F_13 ( struct V_20 * V_21 )
{
unsigned long long V_22 ;
T_4 V_23 ;
if ( ! V_21 )
return - V_24 ;
strcpy ( F_14 ( V_21 ) , V_25 ) ;
strcpy ( F_15 ( V_21 ) , V_26 ) ;
V_23 = F_16 ( V_21 -> V_27 , L_5 , NULL , & V_22 ) ;
if ( F_17 ( V_23 ) )
return - V_24 ;
V_28 = V_22 ;
V_23 = F_18 ( NULL , V_28 ,
V_29 ,
F_11 , V_21 ) ;
if ( F_17 ( V_23 ) )
return - V_30 ;
F_19 ( & V_21 -> V_3 , L_6 , V_28 ) ;
F_6 () ;
F_20 ( V_31 ) ;
F_21 ( NULL , V_28 ) ;
if ( V_21 -> V_32 . V_33 . V_34 )
F_22 ( & V_21 -> V_3 , true ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 , int type )
{
F_24 ( NULL , V_28 ) ;
F_25 ( NULL , V_28 , F_11 ) ;
F_26 ( & V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
F_20 ( V_31 ) ;
F_1 () ;
F_5 () ;
return 0 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_35 ) ;
}
