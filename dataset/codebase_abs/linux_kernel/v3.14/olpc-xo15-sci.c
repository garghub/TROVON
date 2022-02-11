static int F_1 ( bool V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( NULL , L_1 , V_1 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( V_3 L_2 ) ;
return 1 ;
}
V_4 = V_1 ;
return 0 ;
}
static T_2
F_5 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_3 , V_4 ) ;
}
static T_2 F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_10 )
{
unsigned int V_11 ;
if ( sscanf ( V_9 , L_4 , & V_11 ) != 1 )
return - V_12 ;
F_1 ( ! ! V_11 ) ;
return V_10 ;
}
static void F_7 ( void )
{
struct V_13 * V_14 = F_8 ( L_5 ) ;
if ( V_14 ) {
F_9 ( V_14 ) ;
F_10 ( V_14 -> V_15 ) ;
}
}
static void F_11 ( void )
{
struct V_13 * V_14 = F_8 ( L_6 ) ;
if ( V_14 ) {
F_9 ( V_14 ) ;
F_10 ( V_14 -> V_15 ) ;
}
}
static void F_12 ( void )
{
T_4 V_16 ;
int V_17 ;
do {
V_17 = F_13 ( & V_16 ) ;
if ( V_17 || ! V_16 )
break;
F_14 ( V_3 L_7 , V_16 ) ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
F_7 () ;
break;
case V_22 :
F_11 () ;
break;
}
} while ( V_16 );
if ( V_17 )
F_15 ( V_3 L_8 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
F_12 () ;
}
static T_5 F_17 ( T_6 V_25 , T_5 V_26 , void * V_27 )
{
F_18 ( & V_28 ) ;
return V_29 | V_30 ;
}
static int F_19 ( struct V_31 * V_32 )
{
unsigned long long V_33 ;
T_1 V_2 ;
int V_17 ;
if ( ! V_32 )
return - V_12 ;
strcpy ( F_20 ( V_32 ) , V_34 ) ;
strcpy ( F_21 ( V_32 ) , V_35 ) ;
V_2 = F_22 ( V_32 -> V_36 , L_9 , NULL , & V_33 ) ;
if ( F_3 ( V_2 ) )
return - V_12 ;
V_37 = V_33 ;
V_2 = F_23 ( NULL , V_37 ,
V_38 ,
F_17 , V_32 ) ;
if ( F_3 ( V_2 ) )
return - V_39 ;
F_24 ( & V_32 -> V_15 , L_10 , V_37 ) ;
V_17 = F_25 ( & V_32 -> V_15 . V_40 , & V_41 . V_8 ) ;
if ( V_17 )
goto V_42;
F_12 () ;
F_26 ( V_43 ) ;
F_27 ( NULL , V_37 ) ;
if ( V_32 -> V_44 . V_45 . V_46 )
F_28 ( & V_32 -> V_15 , true ) ;
return 0 ;
V_42:
F_29 ( NULL , V_37 , F_17 ) ;
F_30 ( & V_28 ) ;
return V_17 ;
}
static int F_31 ( struct V_31 * V_32 )
{
F_32 ( NULL , V_37 ) ;
F_29 ( NULL , V_37 , F_17 ) ;
F_30 ( & V_28 ) ;
F_33 ( & V_32 -> V_15 . V_40 , & V_41 . V_8 ) ;
return 0 ;
}
static int F_34 ( struct V_32 * V_15 )
{
F_26 ( V_43 ) ;
F_7 () ;
F_11 () ;
return 0 ;
}
static int T_7 F_35 ( void )
{
return F_36 ( & V_47 ) ;
}
