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
V_14 -> V_15 ( V_14 ,
V_2 -> V_12 ? V_16 : V_17 ) ;
}
static T_1 F_6 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_5 * V_6 = F_7 ( V_21 ,
struct V_5 ,
V_21 ) ;
return sprintf ( V_22 , L_1 , V_6 -> V_10 ) + 1 ;
}
static T_1 F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 , T_2 V_23 )
{
struct V_5 * V_6 = F_7 ( V_21 ,
struct V_5 ,
V_21 ) ;
if ( ! strcmp ( V_22 , L_2 ) || ! strcmp ( V_22 , L_3 ) )
V_6 -> V_10 = 0 ;
else if ( ! strcmp ( V_22 , L_4 ) || ! strcmp ( V_22 , L_5 ) )
V_6 -> V_10 = 1 ;
else
return - V_24 ;
F_4 ( V_6 -> V_11 ) ;
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_25 , int V_9 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_5 * V_6 ;
T_2 V_26 ;
int V_27 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 ) {
V_27 = - V_29 ;
goto V_30;
}
V_6 -> V_11 = V_2 ;
V_6 -> V_8 = V_4 ;
V_6 -> V_9 = V_9 ;
V_26 = strlen ( V_25 ) + 8 ;
V_6 -> V_31 = F_10 ( V_26 , V_28 ) ;
if ( ! V_6 -> V_31 ) {
V_27 = - V_29 ;
goto V_32;
}
snprintf ( V_6 -> V_31 , V_26 , L_6 , V_25 , V_9 ) ;
V_6 -> V_21 . V_21 . V_33 = V_6 -> V_31 ;
V_6 -> V_21 . V_21 . V_34 = V_35 | V_36 ;
V_6 -> V_21 . V_37 = F_6 ;
V_6 -> V_21 . V_38 = F_8 ;
V_27 = F_11 ( & V_14 -> V_19 -> V_39 , & V_6 -> V_21 . V_21 ,
V_40 . V_33 ) ;
if ( V_27 )
goto V_41;
F_12 ( & V_6 -> V_42 , & V_2 -> V_43 ) ;
return 0 ;
V_41:
F_13 ( V_6 -> V_31 ) ;
V_32:
F_13 ( V_6 ) ;
V_30:
return V_27 ;
}
static int F_14 ( struct V_3 * V_4 ,
void * V_11 )
{
struct V_1 * V_2 = V_11 ;
int V_44 ;
for ( V_44 = 1 ; V_44 <= V_4 -> V_45 ; V_44 ++ )
F_9 ( V_2 , V_4 ,
F_15 ( & V_4 -> V_19 ) , V_44 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_17 ( & V_6 -> V_42 ) ;
F_18 ( & V_14 -> V_19 -> V_39 , & V_6 -> V_21 . V_21 ,
V_40 . V_33 ) ;
F_13 ( V_6 -> V_31 ) ;
F_13 ( V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_46 ;
F_20 (port, tmp, &usbport_data->ports, list) {
if ( V_6 -> V_8 == V_4 )
F_16 ( V_2 , V_6 ) ;
}
}
static int F_21 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_11 )
{
struct V_1 * V_2 =
F_7 ( V_48 , struct V_1 , V_48 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_3 * V_4 = V_11 ;
bool V_10 ;
V_10 = F_1 ( V_2 , V_4 ) ;
switch ( V_49 ) {
case V_50 :
F_14 ( V_4 , V_2 ) ;
if ( V_10 && V_2 -> V_12 ++ == 0 )
V_14 -> V_15 ( V_14 , V_16 ) ;
return V_51 ;
case V_52 :
F_19 ( V_2 , V_4 ) ;
if ( V_10 && -- V_2 -> V_12 == 0 )
V_14 -> V_15 ( V_14 , V_17 ) ;
return V_51 ;
}
return V_53 ;
}
static void F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return;
V_2 -> V_14 = V_14 ;
F_23 ( & V_2 -> V_43 ) ;
V_27 = F_24 ( & V_14 -> V_19 -> V_39 , & V_40 ) ;
if ( V_27 )
goto V_54;
F_5 ( V_2 , F_14 ) ;
V_2 -> V_48 . V_55 = F_21 ,
V_14 -> V_56 = V_2 ;
F_25 ( & V_2 -> V_48 ) ;
V_14 -> V_57 = true ;
return;
V_54:
F_13 ( V_2 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_56 ;
struct V_5 * V_6 , * V_46 ;
if ( ! V_14 -> V_57 )
return;
F_20 (port, tmp, &usbport_data->ports, list) {
F_16 ( V_2 , V_6 ) ;
}
F_27 ( & V_2 -> V_48 ) ;
F_28 ( & V_14 -> V_19 -> V_39 , & V_40 ) ;
F_13 ( V_2 ) ;
V_14 -> V_57 = false ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_58 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_58 ) ;
}
