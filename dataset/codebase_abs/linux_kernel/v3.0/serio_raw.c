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
int V_12 = 0 ;
V_12 = F_6 ( & V_13 ) ;
if ( V_12 )
return V_12 ;
V_8 = F_3 ( F_7 ( V_11 ) ) ;
if ( ! V_8 ) {
V_12 = - V_14 ;
goto V_15;
}
if ( ! V_8 -> V_16 ) {
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
V_8 -> V_19 ++ ;
F_9 ( & V_5 -> V_20 , & V_8 -> V_5 ) ;
V_15:
F_10 ( & V_13 ) ;
return V_12 ;
}
static int F_11 ( struct V_8 * V_8 )
{
if ( -- V_8 -> V_19 == 0 ) {
F_12 ( & V_8 -> V_10 ) ;
F_13 ( & V_8 -> V_20 ) ;
F_14 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static int F_15 ( struct V_11 * V_11 , struct V_2 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
F_16 ( & V_13 ) ;
F_11 ( V_8 ) ;
F_10 ( & V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_8 , char * V_21 )
{
unsigned long V_22 ;
int V_23 ;
F_18 ( & V_8 -> V_16 -> V_24 , V_22 ) ;
V_23 = V_8 -> V_25 == V_8 -> V_26 ;
if ( ! V_23 ) {
* V_21 = V_8 -> V_27 [ V_8 -> V_26 ] ;
V_8 -> V_26 = ( V_8 -> V_26 + 1 ) % V_28 ;
}
F_19 ( & V_8 -> V_16 -> V_24 , V_22 ) ;
return ! V_23 ;
}
static T_1 F_20 ( struct V_2 * V_2 , char T_2 * V_29 , T_3 V_30 , T_4 * V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 = V_5 -> V_8 ;
char V_32 ( V_21 ) ;
T_1 V_12 = 0 ;
if ( ! V_8 -> V_16 )
return - V_14 ;
if ( V_8 -> V_25 == V_8 -> V_26 && ( V_2 -> V_33 & V_34 ) )
return - V_35 ;
V_12 = F_21 ( V_5 -> V_8 -> V_36 ,
V_8 -> V_25 != V_8 -> V_26 || ! V_8 -> V_16 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_8 -> V_16 )
return - V_14 ;
while ( V_12 < V_30 && F_17 ( V_8 , & V_21 ) ) {
if ( F_22 ( V_21 , V_29 ++ ) )
return - V_37 ;
V_12 ++ ;
}
return V_12 ;
}
static T_1 F_23 ( struct V_2 * V_2 , const char T_2 * V_29 , T_3 V_30 , T_4 * V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_38 = 0 ;
int V_12 ;
unsigned char V_21 ;
V_12 = F_6 ( & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_5 -> V_8 -> V_16 ) {
V_12 = - V_14 ;
goto V_15;
}
if ( V_30 > 32 )
V_30 = 32 ;
while ( V_30 -- ) {
if ( F_24 ( V_21 , V_29 ++ ) ) {
V_12 = - V_37 ;
goto V_15;
}
if ( F_25 ( V_5 -> V_8 -> V_16 , V_21 ) ) {
V_12 = - V_39 ;
goto V_15;
}
V_38 ++ ;
} ;
V_15:
F_10 ( & V_13 ) ;
return V_38 ;
}
static unsigned int F_26 ( struct V_2 * V_2 , T_5 * V_36 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_27 ( V_2 , & V_5 -> V_8 -> V_36 , V_36 ) ;
if ( V_5 -> V_8 -> V_25 != V_5 -> V_8 -> V_26 )
return V_40 | V_41 ;
return 0 ;
}
static T_6 F_28 ( struct V_16 * V_16 , unsigned char V_42 ,
unsigned int V_43 )
{
struct V_8 * V_8 = F_29 ( V_16 ) ;
struct V_4 * V_5 ;
unsigned int V_25 = V_8 -> V_25 ;
V_8 -> V_27 [ V_25 ] = V_42 ;
V_25 = ( V_25 + 1 ) % V_28 ;
if ( F_30 ( V_25 != V_8 -> V_26 ) ) {
V_8 -> V_25 = V_25 ;
F_4 (list, &serio_raw->list, node)
F_31 ( & V_5 -> V_7 , V_44 , V_45 ) ;
F_32 ( & V_8 -> V_36 ) ;
}
return V_46 ;
}
static int F_33 ( struct V_16 * V_16 , struct V_47 * V_48 )
{
struct V_8 * V_8 ;
int V_49 ;
if ( ! ( V_8 = F_8 ( sizeof( struct V_8 ) , V_17 ) ) ) {
F_34 ( V_50 L_1 ) ;
return - V_18 ;
}
F_16 ( & V_13 ) ;
snprintf ( V_8 -> V_51 , sizeof( V_8 -> V_51 ) , L_2 , V_52 ++ ) ;
V_8 -> V_19 = 1 ;
V_8 -> V_16 = V_16 ;
F_35 ( & V_8 -> V_5 ) ;
F_36 ( & V_8 -> V_36 ) ;
F_37 ( V_16 , V_8 ) ;
V_49 = F_38 ( V_16 , V_48 ) ;
if ( V_49 )
goto V_53;
F_9 ( & V_8 -> V_20 , & V_4 ) ;
V_8 -> V_10 . V_9 = V_54 ;
V_8 -> V_10 . V_51 = V_8 -> V_51 ;
V_8 -> V_10 . V_55 = & V_16 -> V_10 ;
V_8 -> V_10 . V_56 = & V_57 ;
V_49 = F_39 ( & V_8 -> V_10 ) ;
if ( V_49 ) {
V_8 -> V_10 . V_9 = V_58 ;
V_49 = F_39 ( & V_8 -> V_10 ) ;
}
if ( V_49 ) {
F_34 ( V_59 L_3 ,
V_16 -> V_60 ) ;
goto V_61;
}
F_34 ( V_59 L_4 ,
V_16 -> V_60 , V_8 -> V_51 , V_8 -> V_10 . V_9 ) ;
goto V_15;
V_61:
F_40 ( V_16 ) ;
F_13 ( & V_8 -> V_20 ) ;
V_53:
F_37 ( V_16 , NULL ) ;
F_14 ( V_8 ) ;
V_15:
F_10 ( & V_13 ) ;
return V_49 ;
}
static int F_41 ( struct V_16 * V_16 )
{
struct V_8 * V_8 = F_29 ( V_16 ) ;
struct V_47 * V_48 = V_16 -> V_48 ;
if ( ! V_48 || ! V_8 ) {
F_34 ( V_62 L_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_42 ( struct V_16 * V_16 )
{
struct V_8 * V_8 ;
F_16 ( & V_13 ) ;
V_8 = F_29 ( V_16 ) ;
F_40 ( V_16 ) ;
F_37 ( V_16 , NULL ) ;
V_8 -> V_16 = NULL ;
if ( ! F_11 ( V_8 ) )
F_32 ( & V_8 -> V_36 ) ;
F_10 ( & V_13 ) ;
}
static int T_7 F_43 ( void )
{
return F_44 ( & V_63 ) ;
}
static void T_8 F_45 ( void )
{
F_46 ( & V_63 ) ;
}
