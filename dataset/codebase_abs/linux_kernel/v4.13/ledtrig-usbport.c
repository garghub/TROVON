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
static bool F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_24 )
{
struct V_17 * V_18 = V_2 -> V_14 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_28 args ;
struct V_25 * V_29 ;
int V_12 , V_30 ;
if ( ! V_26 )
return false ;
V_29 = F_11 ( V_4 -> V_18 . V_27 , V_24 ) ;
if ( ! V_29 )
return false ;
V_12 = F_12 ( V_26 , L_6 ,
L_7 ) ;
if ( V_12 < 0 ) {
F_13 ( V_18 , L_8 ,
V_26 -> V_31 ) ;
return false ;
}
for ( V_30 = 0 ; V_30 < V_12 ; V_30 ++ ) {
int V_32 ;
V_32 = F_14 ( V_26 , L_6 ,
L_7 , V_30 ,
& args ) ;
if ( V_32 ) {
F_15 ( V_18 , L_9 ,
V_30 , V_32 ) ;
continue;
}
F_16 ( args . V_33 ) ;
if ( args . V_33 == V_29 )
return true ;
}
return false ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_34 , int V_9 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_5 * V_6 ;
T_2 V_35 ;
int V_32 ;
V_6 = F_18 ( sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 ) {
V_32 = - V_37 ;
goto V_38;
}
V_6 -> V_11 = V_2 ;
V_6 -> V_8 = V_4 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_10 = F_10 ( V_2 , V_4 ,
V_9 ) ;
V_35 = strlen ( V_34 ) + 8 ;
V_6 -> V_39 = F_18 ( V_35 , V_36 ) ;
if ( ! V_6 -> V_39 ) {
V_32 = - V_37 ;
goto V_40;
}
snprintf ( V_6 -> V_39 , V_35 , L_10 , V_34 , V_9 ) ;
V_6 -> V_20 . V_20 . V_41 = V_6 -> V_39 ;
V_6 -> V_20 . V_20 . V_42 = V_43 | V_44 ;
V_6 -> V_20 . V_45 = F_7 ;
V_6 -> V_20 . V_46 = F_9 ;
V_32 = F_19 ( & V_14 -> V_18 -> V_47 , & V_6 -> V_20 . V_20 ,
V_48 . V_41 ) ;
if ( V_32 )
goto V_49;
F_20 ( & V_6 -> V_50 , & V_2 -> V_51 ) ;
return 0 ;
V_49:
F_21 ( V_6 -> V_39 ) ;
V_40:
F_21 ( V_6 ) ;
V_38:
return V_32 ;
}
static int F_22 ( struct V_3 * V_4 ,
void * V_11 )
{
struct V_1 * V_2 = V_11 ;
int V_30 ;
for ( V_30 = 1 ; V_30 <= V_4 -> V_52 ; V_30 ++ )
F_17 ( V_2 , V_4 ,
F_23 ( & V_4 -> V_18 ) , V_30 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_25 ( & V_6 -> V_50 ) ;
F_26 ( & V_14 -> V_18 -> V_47 , & V_6 -> V_20 . V_20 ,
V_48 . V_41 ) ;
F_21 ( V_6 -> V_39 ) ;
F_21 ( V_6 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_53 ;
F_28 (port, tmp, &usbport_data->ports, list) {
if ( V_6 -> V_8 == V_4 )
F_24 ( V_2 , V_6 ) ;
}
}
static int F_29 ( struct V_54 * V_55 , unsigned long V_56 ,
void * V_11 )
{
struct V_1 * V_2 =
F_8 ( V_55 , struct V_1 , V_55 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_3 * V_4 = V_11 ;
bool V_10 ;
V_10 = F_1 ( V_2 , V_4 ) ;
switch ( V_56 ) {
case V_57 :
F_22 ( V_4 , V_2 ) ;
if ( V_10 && V_2 -> V_12 ++ == 0 )
F_6 ( V_14 , V_15 ) ;
return V_58 ;
case V_59 :
F_27 ( V_2 , V_4 ) ;
if ( V_10 && -- V_2 -> V_12 == 0 )
F_6 ( V_14 , V_16 ) ;
return V_58 ;
}
return V_60 ;
}
static void F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return;
V_2 -> V_14 = V_14 ;
F_31 ( & V_2 -> V_51 ) ;
V_32 = F_32 ( & V_14 -> V_18 -> V_47 , & V_48 ) ;
if ( V_32 )
goto V_61;
F_5 ( V_2 , F_22 ) ;
F_4 ( V_2 ) ;
V_2 -> V_55 . V_62 = F_29 ,
V_14 -> V_63 = V_2 ;
F_33 ( & V_2 -> V_55 ) ;
V_14 -> V_64 = true ;
return;
V_61:
F_21 ( V_2 ) ;
}
static void F_34 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_63 ;
struct V_5 * V_6 , * V_53 ;
if ( ! V_14 -> V_64 )
return;
F_28 (port, tmp, &usbport_data->ports, list) {
F_24 ( V_2 , V_6 ) ;
}
F_35 ( & V_2 -> V_55 ) ;
F_36 ( & V_14 -> V_18 -> V_47 , & V_48 ) ;
F_21 ( V_2 ) ;
V_14 -> V_64 = false ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_65 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_65 ) ;
}
