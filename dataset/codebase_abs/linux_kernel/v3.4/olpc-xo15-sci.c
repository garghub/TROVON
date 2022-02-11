static int F_1 ( bool V_1 )
{
struct V_2 V_3 ;
union V_4 V_5 ;
T_1 V_6 ;
V_3 . V_7 = 1 ;
V_3 . V_8 = & V_5 ;
V_5 . type = V_9 ;
V_5 . integer . V_10 = V_1 ;
V_6 = F_2 ( NULL , L_1 , & V_3 , NULL ) ;
if ( F_3 ( V_6 ) ) {
F_4 ( V_11 L_2 ) ;
return 1 ;
}
V_12 = V_1 ;
return 0 ;
}
static T_2
F_5 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
return sprintf ( V_17 , L_3 , V_12 ) ;
}
static T_2 F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_3 V_18 )
{
unsigned int V_19 ;
if ( sscanf ( V_17 , L_4 , & V_19 ) != 1 )
return - V_20 ;
F_1 ( ! ! V_19 ) ;
return V_18 ;
}
static void F_7 ( void )
{
struct V_21 * V_22 = F_8 ( L_5 ) ;
if ( V_22 ) {
F_9 ( V_22 ) ;
F_10 ( V_22 -> V_23 ) ;
}
}
static void F_11 ( void )
{
struct V_21 * V_22 = F_8 ( L_6 ) ;
if ( V_22 ) {
F_9 ( V_22 ) ;
F_10 ( V_22 -> V_23 ) ;
}
}
static void F_12 ( void )
{
T_4 V_24 ;
int V_25 ;
do {
V_25 = F_13 ( & V_24 ) ;
if ( V_25 || ! V_24 )
break;
F_14 ( V_11 L_7 , V_24 ) ;
switch ( V_24 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_7 () ;
break;
case V_30 :
F_11 () ;
break;
}
} while ( V_24 );
if ( V_25 )
F_15 ( V_11 L_8 ) ;
}
static void F_16 ( struct V_31 * V_32 )
{
F_12 () ;
}
static T_5 F_17 ( T_6 V_33 , T_5 V_34 , void * V_35 )
{
F_18 ( & V_36 ) ;
return V_37 | V_38 ;
}
static int F_19 ( struct V_39 * V_40 )
{
unsigned long long V_41 ;
T_1 V_6 ;
int V_25 ;
if ( ! V_40 )
return - V_20 ;
strcpy ( F_20 ( V_40 ) , V_42 ) ;
strcpy ( F_21 ( V_40 ) , V_43 ) ;
V_6 = F_22 ( V_40 -> V_44 , L_9 , NULL , & V_41 ) ;
if ( F_3 ( V_6 ) )
return - V_20 ;
V_45 = V_41 ;
V_6 = F_23 ( NULL , V_45 ,
V_46 ,
F_17 , V_40 ) ;
if ( F_3 ( V_6 ) )
return - V_47 ;
F_24 ( & V_40 -> V_23 , L_10 , V_45 ) ;
V_25 = F_25 ( & V_40 -> V_23 . V_48 , & V_49 . V_16 ) ;
if ( V_25 )
goto V_50;
F_12 () ;
F_26 ( V_51 ) ;
F_27 ( NULL , V_45 ) ;
if ( V_40 -> V_52 . V_53 . V_54 )
F_28 ( & V_40 -> V_23 , true ) ;
return 0 ;
V_50:
F_29 ( NULL , V_45 , F_17 ) ;
F_30 ( & V_36 ) ;
return V_25 ;
}
static int F_31 ( struct V_39 * V_40 , int type )
{
F_32 ( NULL , V_45 ) ;
F_29 ( NULL , V_45 , F_17 ) ;
F_30 ( & V_36 ) ;
F_33 ( & V_40 -> V_23 . V_48 , & V_49 . V_16 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 )
{
F_26 ( V_51 ) ;
F_7 () ;
F_11 () ;
return 0 ;
}
static int T_7 F_35 ( void )
{
return F_36 ( & V_55 ) ;
}
