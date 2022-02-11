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
V_22 = F_15 ( V_16 -> V_23 ) ;
if ( ! V_20 ) {
F_16 ( L_1 ) ;
return - V_24 ;
}
if ( V_22 )
memcpy ( V_20 -> V_23 , V_22 -> V_23 ,
V_22 -> V_25 *
sizeof( V_22 -> V_23 [ 0 ] ) ) ;
V_20 -> V_25 = V_17 ;
F_17 ( V_16 -> V_23 , V_20 ) ;
if ( V_22 )
F_18 ( V_22 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
int V_27 = 0 ;
T_1 V_28 ;
struct V_19 * V_29 ;
V_28 = F_9 ( & V_13 ) + 1 ;
V_29 = F_15 ( V_16 -> V_23 ) ;
if ( ! V_29 || V_29 -> V_25 < V_28 )
V_27 = F_13 ( V_16 , V_28 ) ;
return V_27 ;
}
static struct F_3 * F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_30 ;
int V_27 = - V_31 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_21 ) ;
if ( ! V_30 )
return F_21 ( - V_24 ) ;
if ( V_3 -> V_32 && F_1 ( V_3 -> V_32 ) -> V_8 )
goto V_33;
V_27 = F_4 ( & V_30 -> V_8 ) ;
if ( V_27 < 0 ) {
F_16 ( L_2 ) ;
goto V_33;
}
return & V_30 -> V_5 ;
V_33:
F_22 ( V_30 ) ;
return F_21 ( V_27 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_30 ;
struct V_15 * V_16 ;
struct V_19 * V_29 ;
V_30 = F_1 ( V_3 ) ;
F_24 () ;
F_25 (&init_net, dev) {
V_29 = F_15 ( V_16 -> V_23 ) ;
if ( V_29 && V_30 -> V_8 < V_29 -> V_25 )
V_29 -> V_23 [ V_30 -> V_8 ] = 0 ;
}
F_26 () ;
F_11 ( V_30 -> V_8 ) ;
F_22 ( V_30 ) ;
}
static T_3 F_27 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
return ( T_3 ) F_1 ( V_3 ) -> V_8 ;
}
static int F_28 ( struct V_2 * V_36 , struct V_34 * V_35 ,
struct V_37 * V_38 )
{
struct V_15 * V_16 ;
T_1 V_8 = F_1 ( V_36 ) -> V_8 ;
T_1 V_39 ;
struct V_19 * V_29 ;
F_29 () ;
F_30 (&init_net, dev) {
V_29 = F_31 ( V_16 -> V_23 ) ;
V_39 = ( V_29 && V_8 < V_29 -> V_25 ) ? V_29 -> V_23 [ V_8 ] : 0 ;
V_38 -> V_40 ( V_38 , V_16 -> V_41 , V_39 ) ;
}
F_32 () ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_42 )
{
char * V_43 = F_34 ( V_42 , V_21 ) ;
int V_27 = - V_31 ;
T_1 V_8 = F_1 ( V_3 ) -> V_8 ;
unsigned long V_39 ;
char * V_44 ;
struct V_15 * V_16 ;
struct V_19 * V_29 ;
if ( ! V_43 )
return - V_24 ;
if ( strlen ( V_43 ) < 3 )
goto V_45;
V_44 = strstr ( V_43 , L_3 ) ;
if ( ! V_44 )
goto V_45;
* V_44 = '\0' ;
V_44 ++ ;
if ( * V_44 == '\0' )
goto V_45;
V_27 = F_35 ( V_44 , 10 , & V_39 ) ;
if ( V_27 < 0 )
goto V_45;
V_27 = - V_46 ;
V_16 = F_36 ( & V_47 , V_43 ) ;
if ( ! V_16 )
goto V_45;
F_24 () ;
V_27 = F_19 ( V_16 ) ;
if ( V_27 < 0 )
goto V_48;
V_29 = F_15 ( V_16 -> V_23 ) ;
if ( V_29 )
V_29 -> V_23 [ V_8 ] = V_39 ;
V_48:
F_26 () ;
F_37 ( V_16 ) ;
V_45:
F_22 ( V_43 ) ;
return V_27 ;
}
static int F_38 ( const void * V_49 , struct V_50 * V_50 , unsigned V_51 )
{
int V_52 ;
struct V_53 * V_54 = F_39 ( V_50 , & V_52 ) ;
if ( V_54 )
V_54 -> V_55 -> V_56 = ( T_1 ) ( unsigned long ) V_49 ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_59 * V_60 ;
void * V_49 ;
F_41 (p, cgrp, tset) {
F_42 ( V_60 ) ;
V_49 = ( void * ) ( unsigned long ) F_43 ( V_60 ) ;
F_44 ( V_60 -> V_61 , 0 , F_38 , V_49 ) ;
F_45 ( V_60 ) ;
}
}
static int F_46 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
struct V_15 * V_16 = V_65 ;
struct V_19 * V_66 ;
switch ( V_64 ) {
case V_67 :
V_66 = F_15 ( V_16 -> V_23 ) ;
F_47 ( V_16 -> V_23 , NULL ) ;
if ( V_66 )
F_18 ( V_66 , V_26 ) ;
break;
}
return V_68 ;
}
static int T_4 F_48 ( void )
{
int V_27 ;
V_27 = F_49 ( & V_69 ) ;
if ( V_27 )
goto V_33;
F_50 ( & V_70 ) ;
V_33:
return V_27 ;
}
static void T_5 F_51 ( void )
{
struct V_19 * V_66 ;
struct V_15 * V_16 ;
F_52 ( & V_70 ) ;
F_53 ( & V_69 ) ;
F_24 () ;
F_25 (&init_net, dev) {
V_66 = F_15 ( V_16 -> V_23 ) ;
F_47 ( V_16 -> V_23 , NULL ) ;
if ( V_66 )
F_18 ( V_66 , V_26 ) ;
}
F_26 () ;
}
