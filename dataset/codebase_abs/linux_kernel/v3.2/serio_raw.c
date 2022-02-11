static int F_1 ( int V_1 , struct V_2 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_2 ( V_1 , V_2 , V_3 , & V_5 -> V_7 ) ;
}
static struct V_8 * F_3 ( int V_9 )
{
struct V_8 * V_8 ;
F_4 (serio_raw, &serio_raw_list, node) {
if ( V_8 -> V_10 . V_9 == V_9 )
return V_8 ;
}
return NULL ;
}
static int F_5 ( struct V_11 * V_11 , struct V_2 * V_2 )
{
struct V_8 * V_8 ;
struct V_4 * V_5 ;
int V_12 ;
V_12 = F_6 ( & V_13 ) ;
if ( V_12 )
return V_12 ;
V_8 = F_3 ( F_7 ( V_11 ) ) ;
if ( ! V_8 ) {
V_12 = - V_14 ;
goto V_15;
}
if ( V_8 -> V_16 ) {
V_12 = - V_14 ;
goto V_15;
}
V_5 = F_8 ( sizeof( struct V_4 ) , V_17 ) ;
if ( ! V_5 ) {
V_12 = - V_18 ;
goto V_15;
}
V_5 -> V_8 = V_8 ;
V_2 -> V_6 = V_5 ;
F_9 ( & V_8 -> V_19 ) ;
F_10 ( V_8 -> V_20 ) ;
F_11 ( & V_5 -> V_21 , & V_8 -> V_22 ) ;
F_12 ( V_8 -> V_20 ) ;
V_15:
F_13 ( & V_13 ) ;
return V_12 ;
}
static void F_14 ( struct V_19 * V_19 )
{
struct V_8 * V_8 =
F_15 ( V_19 , struct V_8 , V_19 ) ;
F_16 ( & V_8 -> V_20 -> V_10 ) ;
F_17 ( V_8 ) ;
}
static int F_18 ( struct V_11 * V_11 , struct V_2 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
F_10 ( V_8 -> V_20 ) ;
F_19 ( & V_5 -> V_21 ) ;
F_12 ( V_8 -> V_20 ) ;
F_17 ( V_5 ) ;
F_20 ( & V_8 -> V_19 , F_14 ) ;
return 0 ;
}
static bool F_21 ( struct V_8 * V_8 , char * V_23 )
{
bool V_24 ;
F_10 ( V_8 -> V_20 ) ;
V_24 = V_8 -> V_25 == V_8 -> V_26 ;
if ( ! V_24 ) {
* V_23 = V_8 -> V_27 [ V_8 -> V_26 ] ;
V_8 -> V_26 = ( V_8 -> V_26 + 1 ) % V_28 ;
}
F_12 ( V_8 -> V_20 ) ;
return ! V_24 ;
}
static T_1 F_22 ( struct V_2 * V_2 , char T_2 * V_29 ,
T_3 V_30 , T_4 * V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
char V_32 ( V_23 ) ;
T_1 V_12 = 0 ;
if ( V_8 -> V_16 )
return - V_14 ;
if ( V_8 -> V_25 == V_8 -> V_26 && ( V_2 -> V_33 & V_34 ) )
return - V_35 ;
V_12 = F_23 ( V_8 -> V_36 ,
V_8 -> V_25 != V_8 -> V_26 || V_8 -> V_16 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_16 )
return - V_14 ;
while ( V_12 < V_30 && F_21 ( V_8 , & V_23 ) ) {
if ( F_24 ( V_23 , V_29 ++ ) )
return - V_37 ;
V_12 ++ ;
}
return V_12 ;
}
static T_1 F_25 ( struct V_2 * V_2 , const char T_2 * V_29 ,
T_3 V_30 , T_4 * V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
T_1 V_38 = 0 ;
int V_12 ;
unsigned char V_23 ;
V_12 = F_6 ( & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_16 ) {
V_12 = - V_14 ;
goto V_15;
}
if ( V_30 > 32 )
V_30 = 32 ;
while ( V_30 -- ) {
if ( F_26 ( V_23 , V_29 ++ ) ) {
V_12 = - V_37 ;
goto V_15;
}
if ( F_27 ( V_8 -> V_20 , V_23 ) ) {
V_12 = - V_39 ;
goto V_15;
}
V_38 ++ ;
} ;
V_15:
F_13 ( & V_13 ) ;
return V_38 ;
}
static unsigned int F_28 ( struct V_2 * V_2 , T_5 * V_36 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
unsigned int V_40 ;
F_29 ( V_2 , & V_8 -> V_36 , V_36 ) ;
V_40 = V_8 -> V_16 ? V_41 | V_42 : V_43 | V_44 ;
if ( V_8 -> V_25 != V_8 -> V_26 )
return V_45 | V_46 ;
return 0 ;
}
static T_6 F_30 ( struct V_20 * V_20 , unsigned char V_47 ,
unsigned int V_48 )
{
struct V_8 * V_8 = F_31 ( V_20 ) ;
struct V_4 * V_5 ;
unsigned int V_25 = V_8 -> V_25 ;
V_8 -> V_27 [ V_25 ] = V_47 ;
V_25 = ( V_25 + 1 ) % V_28 ;
if ( F_32 ( V_25 != V_8 -> V_26 ) ) {
V_8 -> V_25 = V_25 ;
F_4 (client, &serio_raw->client_list, node)
F_33 ( & V_5 -> V_7 , V_49 , V_50 ) ;
F_34 ( & V_8 -> V_36 ) ;
}
return V_51 ;
}
static int F_35 ( struct V_20 * V_20 , struct V_52 * V_53 )
{
static T_7 V_54 = F_36 ( 0 ) ;
struct V_8 * V_8 ;
int V_55 ;
V_8 = F_8 ( sizeof( struct V_8 ) , V_17 ) ;
if ( ! V_8 ) {
F_37 ( & V_20 -> V_10 , L_1 ) ;
return - V_18 ;
}
snprintf ( V_8 -> V_56 , sizeof( V_8 -> V_56 ) ,
L_2 , ( long ) F_38 ( & V_54 ) - 1 ) ;
F_39 ( & V_8 -> V_19 ) ;
F_40 ( & V_8 -> V_22 ) ;
F_41 ( & V_8 -> V_36 ) ;
V_8 -> V_20 = V_20 ;
F_42 ( & V_20 -> V_10 ) ;
F_43 ( V_20 , V_8 ) ;
V_55 = F_44 ( V_20 , V_53 ) ;
if ( V_55 )
goto V_57;
V_55 = F_45 ( & V_13 ) ;
if ( V_55 )
goto V_58;
F_11 ( & V_8 -> V_21 , & V_59 ) ;
F_13 ( & V_13 ) ;
V_8 -> V_10 . V_9 = V_60 ;
V_8 -> V_10 . V_56 = V_8 -> V_56 ;
V_8 -> V_10 . V_61 = & V_20 -> V_10 ;
V_8 -> V_10 . V_62 = & V_63 ;
V_55 = F_46 ( & V_8 -> V_10 ) ;
if ( V_55 ) {
V_8 -> V_10 . V_9 = V_64 ;
V_55 = F_46 ( & V_8 -> V_10 ) ;
}
if ( V_55 ) {
F_47 ( & V_20 -> V_10 ,
L_3 ,
V_20 -> V_65 ) ;
goto V_66;
}
F_48 ( & V_20 -> V_10 , L_4 ,
V_20 -> V_65 , V_8 -> V_56 , V_8 -> V_10 . V_9 ) ;
return 0 ;
V_66:
F_49 ( & V_8 -> V_21 ) ;
V_58:
F_50 ( V_20 ) ;
V_57:
F_43 ( V_20 , NULL ) ;
F_20 ( & V_8 -> V_19 , F_14 ) ;
return V_55 ;
}
static int F_51 ( struct V_20 * V_20 )
{
struct V_8 * V_8 = F_31 ( V_20 ) ;
struct V_52 * V_53 = V_20 -> V_53 ;
if ( ! V_53 || ! V_8 ) {
F_37 ( & V_20 -> V_10 ,
L_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_52 ( struct V_8 * V_8 )
{
struct V_4 * V_5 ;
F_10 ( V_8 -> V_20 ) ;
F_4 (client, &serio_raw->client_list, node)
F_33 ( & V_5 -> V_7 , V_49 , V_67 ) ;
F_12 ( V_8 -> V_20 ) ;
F_34 ( & V_8 -> V_36 ) ;
}
static void F_53 ( struct V_20 * V_20 )
{
struct V_8 * V_8 = F_31 ( V_20 ) ;
F_54 ( & V_8 -> V_10 ) ;
F_55 ( & V_13 ) ;
V_8 -> V_16 = true ;
F_49 ( & V_8 -> V_21 ) ;
F_13 ( & V_13 ) ;
F_52 ( V_8 ) ;
F_50 ( V_20 ) ;
F_20 ( & V_8 -> V_19 , F_14 ) ;
F_43 ( V_20 , NULL ) ;
}
static int T_8 F_56 ( void )
{
return F_57 ( & V_68 ) ;
}
static void T_9 F_58 ( void )
{
F_59 ( & V_68 ) ;
}
