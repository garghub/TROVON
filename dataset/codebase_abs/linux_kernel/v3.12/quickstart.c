static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 ;
if ( F_2 ( & V_9 ) )
return snprintf ( V_5 , V_10 , L_1 ) ;
F_3 (b, &buttons, list) {
V_6 += snprintf ( V_5 + V_6 , V_10 - V_6 , L_2 ,
V_8 -> V_11 , V_8 -> V_12 ) ;
if ( V_6 >= V_10 ) {
V_6 = V_10 ;
break;
}
}
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_5 ( V_5 , V_10 , L_3 ,
( V_13 ? V_13 -> V_12 : L_1 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
if ( V_6 < 2 )
return - V_14 ;
if ( strncasecmp ( V_5 , L_1 , 4 ) != 0 )
return - V_14 ;
V_13 = NULL ;
return V_6 ;
}
static struct V_7 * F_7 ( void )
{
struct V_7 * V_8 ;
V_8 = F_8 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_9 ( & V_8 -> V_16 , & V_9 ) ;
return V_8 ;
}
static void F_10 ( struct V_7 * V_17 )
{
if ( ! V_17 )
return;
F_11 ( & V_17 -> V_16 ) ;
F_12 ( V_17 -> V_12 ) ;
F_12 ( V_17 ) ;
}
static void F_13 ( void )
{
struct V_7 * V_8 , * V_18 ;
F_14 (b, n, &buttons, list)
F_10 ( V_8 ) ;
}
static void F_15 ( T_3 V_19 , T_4 V_20 , void * V_17 )
{
struct V_21 * V_22 = V_17 ;
if ( ! V_22 )
return;
switch ( V_20 ) {
case V_23 :
V_13 = V_22 -> V_24 ;
break;
case V_25 :
F_16 ( V_26 , V_22 -> V_24 -> V_11 , 1 ) ;
F_17 ( V_26 ) ;
F_16 ( V_26 , V_22 -> V_24 -> V_11 , 0 ) ;
F_17 ( V_26 ) ;
break;
default:
F_18 ( L_4 , V_20 ) ;
break;
}
}
static int F_19 ( struct V_21 * V_22 )
{
T_5 V_27 ;
struct V_28 V_29 = { V_30 , NULL } ;
int V_31 = 0 ;
V_27 = F_20 ( V_22 -> V_1 -> V_19 , L_5 , NULL ,
& V_29 ) ;
if ( F_21 ( V_27 ) ) {
F_18 ( L_6 , V_22 -> V_24 -> V_12 ) ;
return - V_14 ;
}
switch ( V_29 . V_32 ) {
case 1 :
V_22 -> V_24 -> V_11 = * ( V_33 * ) V_29 . V_34 ;
break;
case 2 :
V_22 -> V_24 -> V_11 = * ( V_35 * ) V_29 . V_34 ;
break;
case 4 :
V_22 -> V_24 -> V_11 = * ( V_36 * ) V_29 . V_34 ;
break;
case 8 :
V_22 -> V_24 -> V_11 = * ( V_37 * ) V_29 . V_34 ;
break;
default:
F_18 ( L_7 ,
V_22 -> V_24 -> V_12 ,
( unsigned long ) V_29 . V_32 ) ;
V_31 = - V_14 ;
break;
}
F_12 ( V_29 . V_34 ) ;
return V_31 ;
}
static int F_22 ( struct V_21 * V_22 )
{
char * V_38 = F_23 ( V_22 -> V_1 ) ;
char * V_12 ;
V_12 = F_24 ( strlen ( V_38 ) + 1 , V_15 ) ;
if ( ! V_12 )
return - V_39 ;
V_22 -> V_24 = F_7 () ;
if ( ! V_22 -> V_24 ) {
F_12 ( V_12 ) ;
return - V_39 ;
}
V_22 -> V_24 -> V_12 = V_12 ;
strcpy ( V_22 -> V_24 -> V_12 , V_38 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_1 )
{
int V_31 ;
T_5 V_27 ;
struct V_21 * V_22 ;
if ( ! V_1 )
return - V_14 ;
V_22 = F_8 ( sizeof( * V_22 ) , V_15 ) ;
if ( ! V_22 )
return - V_39 ;
V_22 -> V_1 = V_1 ;
strcpy ( F_26 ( V_1 ) , V_41 ) ;
strcpy ( F_27 ( V_1 ) , V_42 ) ;
V_1 -> V_43 = V_22 ;
V_31 = F_22 ( V_22 ) ;
if ( V_31 < 0 )
goto V_44;
V_27 = F_28 ( V_1 -> V_19 , V_45 ,
F_15 ,
V_22 ) ;
if ( F_21 ( V_27 ) ) {
F_18 ( L_8 ) ;
V_31 = - V_46 ;
goto V_47;
}
V_31 = F_19 ( V_22 ) ;
if ( V_31 < 0 )
goto V_48;
return 0 ;
V_48:
F_29 ( V_1 -> V_19 , V_45 ,
F_15 ) ;
V_47:
F_10 ( V_22 -> V_24 ) ;
V_44:
F_12 ( V_22 ) ;
return V_31 ;
}
static int F_30 ( struct V_40 * V_1 )
{
T_5 V_27 ;
struct V_21 * V_22 ;
if ( ! V_1 )
return - V_14 ;
V_22 = F_31 ( V_1 ) ;
if ( ! V_22 )
return - V_14 ;
V_27 = F_29 ( V_1 -> V_19 , V_45 ,
F_15 ) ;
if ( F_21 ( V_27 ) )
F_18 ( L_9 ) ;
F_12 ( V_22 ) ;
return 0 ;
}
static void F_32 ( void )
{
F_33 ( V_26 ) ;
F_34 ( & V_49 -> V_2 , & V_50 ) ;
F_34 ( & V_49 -> V_2 , & V_51 ) ;
F_35 ( V_49 ) ;
F_36 ( & V_52 ) ;
F_37 ( & V_53 ) ;
F_13 () ;
}
static int T_6 F_38 ( void )
{
struct V_7 * V_8 ;
int V_31 ;
V_26 = F_39 () ;
if ( ! V_26 )
return - V_39 ;
V_26 -> V_12 = L_10 ;
V_26 -> V_11 . V_54 = V_55 ;
F_3 (b, &buttons, list) {
F_40 ( V_56 , V_26 -> V_57 ) ;
F_40 ( V_8 -> V_11 , V_26 -> V_58 ) ;
}
V_31 = F_41 ( V_26 ) ;
if ( V_31 ) {
F_42 ( V_26 ) ;
return V_31 ;
}
return 0 ;
}
static int T_6 F_43 ( void )
{
int V_31 ;
if ( V_59 )
return - V_46 ;
V_31 = F_44 ( & V_53 ) ;
if ( V_31 )
return V_31 ;
if ( F_2 ( & V_9 ) ) {
V_31 = - V_46 ;
goto V_60;
}
V_31 = F_45 ( & V_52 ) ;
if ( V_31 )
goto V_60;
V_49 = F_46 ( V_61 , - 1 ) ;
if ( ! V_49 ) {
V_31 = - V_39 ;
goto V_62;
}
V_31 = F_47 ( V_49 ) ;
if ( V_31 )
goto V_63;
V_31 = F_48 ( & V_49 -> V_2 , & V_50 ) ;
if ( V_31 )
goto V_64;
V_31 = F_48 ( & V_49 -> V_2 , & V_51 ) ;
if ( V_31 )
goto V_65;
V_31 = F_38 () ;
if ( V_31 )
goto V_66;
F_49 ( L_11 , V_67 ) ;
return 0 ;
V_66:
F_34 ( & V_49 -> V_2 , & V_51 ) ;
V_65:
F_34 ( & V_49 -> V_2 , & V_50 ) ;
V_64:
F_50 ( V_49 ) ;
V_63:
F_51 ( V_49 ) ;
V_62:
F_36 ( & V_52 ) ;
V_60:
F_37 ( & V_53 ) ;
return V_31 ;
}
