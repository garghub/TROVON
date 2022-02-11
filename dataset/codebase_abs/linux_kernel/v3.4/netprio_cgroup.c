static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static int F_4 ( T_1 * V_6 )
{
unsigned long V_7 ;
T_1 V_8 ;
F_5 ( & V_9 , V_7 ) ;
V_8 = F_6 ( V_10 , sizeof( unsigned long ) * V_11 ) ;
if ( V_8 == sizeof( unsigned long ) * V_11 ) {
F_7 ( & V_9 , V_7 ) ;
return - V_12 ;
}
F_8 ( V_8 , V_10 ) ;
F_7 ( & V_9 , V_7 ) ;
F_9 ( & V_13 , V_8 ) ;
* V_6 = V_8 ;
return 0 ;
}
static void F_10 ( T_1 V_14 )
{
unsigned long V_7 ;
F_5 ( & V_9 , V_7 ) ;
F_11 ( V_14 , V_10 ) ;
F_7 ( & V_9 , V_7 ) ;
}
static void F_12 ( struct V_15 * V_16 , T_1 V_17 )
{
T_2 V_18 = sizeof( struct V_19 ) +
( ( sizeof( T_1 ) * V_17 ) ) ;
struct V_19 * V_20 = F_13 ( V_18 , V_21 ) ;
struct V_19 * V_22 ;
int V_23 ;
V_22 = F_14 ( V_16 -> V_24 ) ;
if ( ! V_20 ) {
F_15 ( V_25 L_1 ) ;
return;
}
for ( V_23 = 0 ;
V_22 && ( V_23 < V_22 -> V_26 ) ;
V_23 ++ )
V_20 -> V_24 [ V_23 ] = V_22 -> V_24 [ V_23 ] ;
V_20 -> V_26 = V_17 ;
F_16 ( V_16 -> V_24 , V_20 ) ;
if ( V_22 )
F_17 ( V_22 , V_27 ) ;
}
static void F_18 ( void )
{
struct V_15 * V_16 ;
T_1 V_28 = F_19 ( & V_13 ) + 1 ;
struct V_19 * V_29 ;
F_20 () ;
F_21 (&init_net, dev) {
V_29 = F_14 ( V_16 -> V_24 ) ;
if ( ( ! V_29 ) ||
( V_29 -> V_26 < V_28 ) )
F_12 ( V_16 , V_28 ) ;
}
F_22 () ;
}
static struct F_3 * F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_30 ;
int V_31 ;
V_30 = F_13 ( sizeof( * V_30 ) , V_21 ) ;
if ( ! V_30 )
return F_24 ( - V_32 ) ;
if ( V_3 -> V_33 && F_1 ( V_3 -> V_33 ) -> V_8 ) {
F_25 ( V_30 ) ;
return F_24 ( - V_34 ) ;
}
V_31 = F_4 ( & V_30 -> V_8 ) ;
if ( V_31 != 0 ) {
F_15 ( V_25 L_2 ) ;
F_25 ( V_30 ) ;
return F_24 ( V_31 ) ;
}
return & V_30 -> V_5 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_30 ;
struct V_15 * V_16 ;
struct V_19 * V_29 ;
V_30 = F_1 ( V_3 ) ;
F_20 () ;
F_21 (&init_net, dev) {
V_29 = F_14 ( V_16 -> V_24 ) ;
if ( V_29 )
V_29 -> V_24 [ V_30 -> V_8 ] = 0 ;
}
F_22 () ;
F_10 ( V_30 -> V_8 ) ;
F_25 ( V_30 ) ;
}
static T_3 F_27 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
return ( T_3 ) F_1 ( V_3 ) -> V_8 ;
}
static int F_28 ( struct V_2 * V_37 , struct V_35 * V_36 ,
struct V_38 * V_39 )
{
struct V_15 * V_16 ;
T_1 V_8 = F_1 ( V_37 ) -> V_8 ;
T_1 V_40 ;
struct V_19 * V_29 ;
F_29 () ;
F_30 (&init_net, dev) {
V_29 = F_31 ( V_16 -> V_24 ) ;
V_40 = V_29 ? V_29 -> V_24 [ V_8 ] : 0 ;
V_39 -> V_41 ( V_39 , V_16 -> V_42 , V_40 ) ;
}
F_32 () ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_35 * V_36 ,
const char * V_43 )
{
char * V_44 = F_34 ( V_43 , V_21 ) ;
int V_31 = - V_34 ;
T_1 V_8 = F_1 ( V_3 ) -> V_8 ;
unsigned long V_40 ;
char * V_45 ;
struct V_15 * V_16 ;
struct V_19 * V_29 ;
if ( ! V_44 )
return - V_32 ;
if ( strlen ( V_44 ) < 3 )
goto V_46;
V_45 = strstr ( V_44 , L_3 ) ;
if ( ! V_45 )
goto V_46;
* V_45 = '\0' ;
V_45 ++ ;
if ( * V_45 == '\0' )
goto V_46;
V_31 = F_35 ( V_45 , 10 , & V_40 ) ;
if ( V_31 < 0 )
goto V_46;
V_31 = - V_47 ;
V_16 = F_36 ( & V_48 , V_44 ) ;
if ( ! V_16 )
goto V_46;
F_18 () ;
V_31 = 0 ;
F_29 () ;
V_29 = F_31 ( V_16 -> V_24 ) ;
if ( V_29 )
V_29 -> V_24 [ V_8 ] = V_40 ;
F_32 () ;
F_37 ( V_16 ) ;
V_46:
F_25 ( V_44 ) ;
return V_31 ;
}
static int F_38 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
return F_39 ( V_3 , V_50 , V_51 , F_40 ( V_51 ) ) ;
}
static int F_41 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
struct V_15 * V_16 = V_55 ;
struct V_19 * V_56 ;
switch ( V_54 ) {
case V_57 :
V_56 = F_14 ( V_16 -> V_24 ) ;
F_42 ( V_16 -> V_24 , NULL ) ;
if ( V_56 )
F_17 ( V_56 , V_27 ) ;
break;
}
return V_58 ;
}
static int T_4 F_43 ( void )
{
int V_31 ;
V_31 = F_44 ( & V_59 ) ;
if ( V_31 )
goto V_60;
#ifndef F_45
F_46 () ;
V_4 = V_59 . V_61 ;
#endif
F_47 ( & V_62 ) ;
V_60:
return V_31 ;
}
static void T_5 F_48 ( void )
{
struct V_19 * V_56 ;
struct V_15 * V_16 ;
F_49 ( & V_62 ) ;
F_50 ( & V_59 ) ;
#ifndef F_45
V_4 = - 1 ;
F_51 () ;
#endif
F_20 () ;
F_21 (&init_net, dev) {
V_56 = F_14 ( V_16 -> V_24 ) ;
F_42 ( V_16 -> V_24 , NULL ) ;
if ( V_56 )
F_17 ( V_56 , V_27 ) ;
}
F_22 () ;
}
