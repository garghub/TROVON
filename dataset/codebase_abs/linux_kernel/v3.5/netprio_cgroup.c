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
if ( F_9 ( & V_13 ) < V_8 )
F_10 ( & V_13 , V_8 ) ;
F_7 ( & V_9 , V_7 ) ;
* V_6 = V_8 ;
return 0 ;
}
static void F_11 ( T_1 V_14 )
{
unsigned long V_7 ;
F_5 ( & V_9 , V_7 ) ;
F_12 ( V_14 , V_10 ) ;
F_7 ( & V_9 , V_7 ) ;
}
static int F_13 ( struct V_15 * V_16 , T_1 V_17 )
{
T_2 V_18 = sizeof( struct V_19 ) +
( ( sizeof( T_1 ) * V_17 ) ) ;
struct V_19 * V_20 = F_14 ( V_18 , V_21 ) ;
struct V_19 * V_22 ;
int V_23 ;
V_22 = F_15 ( V_16 -> V_24 ) ;
if ( ! V_20 ) {
F_16 ( L_1 ) ;
return - V_25 ;
}
for ( V_23 = 0 ;
V_22 && ( V_23 < V_22 -> V_26 ) ;
V_23 ++ )
V_20 -> V_24 [ V_23 ] = V_22 -> V_24 [ V_23 ] ;
V_20 -> V_26 = V_17 ;
F_17 ( V_16 -> V_24 , V_20 ) ;
if ( V_22 )
F_18 ( V_22 , V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
int V_28 = 0 ;
T_1 V_29 ;
struct V_19 * V_30 ;
F_20 () ;
V_29 = F_9 ( & V_13 ) + 1 ;
V_30 = F_15 ( V_16 -> V_24 ) ;
if ( ! V_30 || V_30 -> V_26 < V_29 )
V_28 = F_13 ( V_16 , V_29 ) ;
F_21 () ;
return V_28 ;
}
static int F_22 ( void )
{
int V_28 = 0 ;
struct V_15 * V_16 ;
T_1 V_29 ;
struct V_19 * V_30 ;
F_20 () ;
V_29 = F_9 ( & V_13 ) + 1 ;
F_23 (&init_net, dev) {
V_30 = F_15 ( V_16 -> V_24 ) ;
if ( V_30 && V_30 -> V_26 < V_29 ) {
V_28 = F_13 ( V_16 , V_29 ) ;
if ( V_28 < 0 )
break;
}
}
F_21 () ;
return V_28 ;
}
static struct F_3 * F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_31 ;
int V_28 = - V_32 ;
V_31 = F_14 ( sizeof( * V_31 ) , V_21 ) ;
if ( ! V_31 )
return F_25 ( - V_25 ) ;
if ( V_3 -> V_33 && F_1 ( V_3 -> V_33 ) -> V_8 )
goto V_34;
V_28 = F_4 ( & V_31 -> V_8 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 ) ;
goto V_34;
}
V_28 = F_22 () ;
if ( V_28 < 0 ) {
F_11 ( V_31 -> V_8 ) ;
goto V_34;
}
return & V_31 -> V_5 ;
V_34:
F_26 ( V_31 ) ;
return F_25 ( V_28 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_31 ;
struct V_15 * V_16 ;
struct V_19 * V_30 ;
V_31 = F_1 ( V_3 ) ;
F_20 () ;
F_23 (&init_net, dev) {
V_30 = F_15 ( V_16 -> V_24 ) ;
if ( V_30 && V_31 -> V_8 < V_30 -> V_26 )
V_30 -> V_24 [ V_31 -> V_8 ] = 0 ;
}
F_21 () ;
F_11 ( V_31 -> V_8 ) ;
F_26 ( V_31 ) ;
}
static T_3 F_28 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
return ( T_3 ) F_1 ( V_3 ) -> V_8 ;
}
static int F_29 ( struct V_2 * V_37 , struct V_35 * V_36 ,
struct V_38 * V_39 )
{
struct V_15 * V_16 ;
T_1 V_8 = F_1 ( V_37 ) -> V_8 ;
T_1 V_40 ;
struct V_19 * V_30 ;
F_30 () ;
F_31 (&init_net, dev) {
V_30 = F_32 ( V_16 -> V_24 ) ;
V_40 = ( V_30 && V_8 < V_30 -> V_26 ) ? V_30 -> V_24 [ V_8 ] : 0 ;
V_39 -> V_41 ( V_39 , V_16 -> V_42 , V_40 ) ;
}
F_33 () ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_35 * V_36 ,
const char * V_43 )
{
char * V_44 = F_35 ( V_43 , V_21 ) ;
int V_28 = - V_32 ;
T_1 V_8 = F_1 ( V_3 ) -> V_8 ;
unsigned long V_40 ;
char * V_45 ;
struct V_15 * V_16 ;
struct V_19 * V_30 ;
if ( ! V_44 )
return - V_25 ;
if ( strlen ( V_44 ) < 3 )
goto V_46;
V_45 = strstr ( V_44 , L_3 ) ;
if ( ! V_45 )
goto V_46;
* V_45 = '\0' ;
V_45 ++ ;
if ( * V_45 == '\0' )
goto V_46;
V_28 = F_36 ( V_45 , 10 , & V_40 ) ;
if ( V_28 < 0 )
goto V_46;
V_28 = - V_47 ;
V_16 = F_37 ( & V_48 , V_44 ) ;
if ( ! V_16 )
goto V_46;
V_28 = F_19 ( V_16 ) ;
if ( V_28 < 0 )
goto V_49;
F_30 () ;
V_30 = F_32 ( V_16 -> V_24 ) ;
if ( V_30 )
V_30 -> V_24 [ V_8 ] = V_40 ;
F_33 () ;
V_49:
F_38 ( V_16 ) ;
V_46:
F_26 ( V_44 ) ;
return V_28 ;
}
static int F_39 ( struct V_50 * V_51 ,
unsigned long V_52 , void * V_53 )
{
struct V_15 * V_16 = V_53 ;
struct V_19 * V_54 ;
switch ( V_52 ) {
case V_55 :
V_54 = F_15 ( V_16 -> V_24 ) ;
F_40 ( V_16 -> V_24 , NULL ) ;
if ( V_54 )
F_18 ( V_54 , V_27 ) ;
break;
}
return V_56 ;
}
static int T_4 F_41 ( void )
{
int V_28 ;
V_28 = F_42 ( & V_57 ) ;
if ( V_28 )
goto V_34;
#ifndef F_43
F_44 () ;
V_4 = V_57 . V_58 ;
#endif
F_45 ( & V_59 ) ;
V_34:
return V_28 ;
}
static void T_5 F_46 ( void )
{
struct V_19 * V_54 ;
struct V_15 * V_16 ;
F_47 ( & V_59 ) ;
F_48 ( & V_57 ) ;
#ifndef F_43
V_4 = - 1 ;
F_49 () ;
#endif
F_20 () ;
F_23 (&init_net, dev) {
V_54 = F_15 ( V_16 -> V_24 ) ;
F_40 ( V_16 -> V_24 , NULL ) ;
if ( V_54 )
F_18 ( V_54 , V_27 ) ;
}
F_21 () ;
}
