static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ! V_4 -> V_7 )
return false ;
F_2 (port, &usbport_data->ports, list) {
if ( V_4 -> V_7 == V_6 -> V_8 &&
V_4 -> V_9 == V_6 -> V_9 )
return V_6 -> V_10 ;
}
return false ;
}
static int F_3 ( struct V_3 * V_4 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
if ( F_1 ( V_2 , V_4 ) )
V_2 -> V_12 ++ ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_12 = 0 ;
F_5 ( V_2 , F_3 ) ;
F_6 ( V_14 , V_2 -> V_12 ? V_15 : V_16 ) ;
}
static T_1 F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_5 * V_6 = F_8 ( V_20 ,
struct V_5 ,
V_20 ) ;
return sprintf ( V_21 , L_1 , V_6 -> V_10 ) + 1 ;
}
static T_1 F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_2 V_22 )
{
struct V_5 * V_6 = F_8 ( V_20 ,
struct V_5 ,
V_20 ) ;
if ( ! strcmp ( V_21 , L_2 ) || ! strcmp ( V_21 , L_3 ) )
V_6 -> V_10 = 0 ;
else if ( ! strcmp ( V_21 , L_4 ) || ! strcmp ( V_21 , L_5 ) )
V_6 -> V_10 = 1 ;
else
return - V_23 ;
F_4 ( V_6 -> V_11 ) ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_24 , int V_9 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_5 * V_6 ;
T_2 V_25 ;
int V_26 ;
V_6 = F_11 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 ) {
V_26 = - V_28 ;
goto V_29;
}
V_6 -> V_11 = V_2 ;
V_6 -> V_8 = V_4 ;
V_6 -> V_9 = V_9 ;
V_25 = strlen ( V_24 ) + 8 ;
V_6 -> V_30 = F_11 ( V_25 , V_27 ) ;
if ( ! V_6 -> V_30 ) {
V_26 = - V_28 ;
goto V_31;
}
snprintf ( V_6 -> V_30 , V_25 , L_6 , V_24 , V_9 ) ;
V_6 -> V_20 . V_20 . V_32 = V_6 -> V_30 ;
V_6 -> V_20 . V_20 . V_33 = V_34 | V_35 ;
V_6 -> V_20 . V_36 = F_7 ;
V_6 -> V_20 . V_37 = F_9 ;
V_26 = F_12 ( & V_14 -> V_18 -> V_38 , & V_6 -> V_20 . V_20 ,
V_39 . V_32 ) ;
if ( V_26 )
goto V_40;
F_13 ( & V_6 -> V_41 , & V_2 -> V_42 ) ;
return 0 ;
V_40:
F_14 ( V_6 -> V_30 ) ;
V_31:
F_14 ( V_6 ) ;
V_29:
return V_26 ;
}
static int F_15 ( struct V_3 * V_4 ,
void * V_11 )
{
struct V_1 * V_2 = V_11 ;
int V_43 ;
for ( V_43 = 1 ; V_43 <= V_4 -> V_44 ; V_43 ++ )
F_10 ( V_2 , V_4 ,
F_16 ( & V_4 -> V_18 ) , V_43 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_18 ( & V_6 -> V_41 ) ;
F_19 ( & V_14 -> V_18 -> V_38 , & V_6 -> V_20 . V_20 ,
V_39 . V_32 ) ;
F_14 ( V_6 -> V_30 ) ;
F_14 ( V_6 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_45 ;
F_21 (port, tmp, &usbport_data->ports, list) {
if ( V_6 -> V_8 == V_4 )
F_17 ( V_2 , V_6 ) ;
}
}
static int F_22 ( struct V_46 * V_47 , unsigned long V_48 ,
void * V_11 )
{
struct V_1 * V_2 =
F_8 ( V_47 , struct V_1 , V_47 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_3 * V_4 = V_11 ;
bool V_10 ;
V_10 = F_1 ( V_2 , V_4 ) ;
switch ( V_48 ) {
case V_49 :
F_15 ( V_4 , V_2 ) ;
if ( V_10 && V_2 -> V_12 ++ == 0 )
F_6 ( V_14 , V_15 ) ;
return V_50 ;
case V_51 :
F_20 ( V_2 , V_4 ) ;
if ( V_10 && -- V_2 -> V_12 == 0 )
F_6 ( V_14 , V_16 ) ;
return V_50 ;
}
return V_52 ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return;
V_2 -> V_14 = V_14 ;
F_24 ( & V_2 -> V_42 ) ;
V_26 = F_25 ( & V_14 -> V_18 -> V_38 , & V_39 ) ;
if ( V_26 )
goto V_53;
F_5 ( V_2 , F_15 ) ;
V_2 -> V_47 . V_54 = F_22 ,
V_14 -> V_55 = V_2 ;
F_26 ( & V_2 -> V_47 ) ;
V_14 -> V_56 = true ;
return;
V_53:
F_14 ( V_2 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_55 ;
struct V_5 * V_6 , * V_45 ;
if ( ! V_14 -> V_56 )
return;
F_21 (port, tmp, &usbport_data->ports, list) {
F_17 ( V_2 , V_6 ) ;
}
F_28 ( & V_2 -> V_47 ) ;
F_29 ( & V_14 -> V_18 -> V_38 , & V_39 ) ;
F_14 ( V_2 ) ;
V_14 -> V_56 = false ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_57 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_57 ) ;
}
