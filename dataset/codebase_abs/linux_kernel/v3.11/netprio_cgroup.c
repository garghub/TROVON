static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_9 * V_10 , * V_11 ;
T_2 V_12 , V_13 ;
V_10 = F_5 ( V_7 -> V_14 ) ;
if ( V_10 && V_10 -> V_15 > V_8 )
return 0 ;
V_12 = V_16 ;
while ( true ) {
V_13 = ( V_12 - F_6 ( struct V_9 , V_14 ) ) /
sizeof( V_11 -> V_14 [ 0 ] ) ;
if ( V_13 > V_8 )
break;
V_12 *= 2 ;
if ( F_7 ( V_12 < V_16 ) )
return - V_17 ;
}
V_11 = F_8 ( V_12 , V_18 ) ;
if ( ! V_11 )
return - V_19 ;
if ( V_10 )
memcpy ( V_11 -> V_14 , V_10 -> V_14 ,
V_10 -> V_15 * sizeof( V_10 -> V_14 [ 0 ] ) ) ;
V_11 -> V_15 = V_13 ;
F_9 ( V_7 -> V_14 , V_11 ) ;
if ( V_10 )
F_10 ( V_10 , V_20 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_9 * V_21 = F_12 ( V_7 -> V_14 ) ;
if ( V_21 && V_3 -> V_22 < V_21 -> V_15 )
return V_21 -> V_14 [ V_3 -> V_22 ] ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_23 )
{
struct V_9 * V_21 ;
int V_24 ;
V_21 = F_5 ( V_7 -> V_14 ) ;
if ( ! V_23 && ( ! V_21 || V_21 -> V_15 <= V_3 -> V_22 ) )
return 0 ;
V_24 = F_4 ( V_7 , V_3 -> V_22 ) ;
if ( V_24 )
return V_24 ;
V_21 = F_5 ( V_7 -> V_14 ) ;
V_21 -> V_14 [ V_3 -> V_22 ] = V_23 ;
return 0 ;
}
static struct F_3 * F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_25 ;
V_25 = F_8 ( sizeof( * V_25 ) , V_18 ) ;
if ( ! V_25 )
return F_15 ( - V_19 ) ;
return & V_25 -> V_5 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_2 * V_26 = V_3 -> V_26 ;
struct V_6 * V_7 ;
int V_24 = 0 ;
if ( ! V_26 )
return 0 ;
F_17 () ;
F_18 (&init_net, dev) {
T_1 V_23 = F_11 ( V_26 , V_7 ) ;
V_24 = F_13 ( V_3 , V_7 , V_23 ) ;
if ( V_24 )
break;
}
F_19 () ;
return V_24 ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_21 ( F_1 ( V_3 ) ) ;
}
static T_3 F_22 ( struct V_2 * V_3 , struct V_27 * V_28 )
{
return V_3 -> V_22 ;
}
static int F_23 ( struct V_2 * V_29 , struct V_27 * V_28 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
F_24 () ;
F_25 (&init_net, dev)
V_31 -> V_32 ( V_31 , V_7 -> V_33 , F_11 ( V_29 , V_7 ) ) ;
F_26 () ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_27 * V_28 ,
const char * V_34 )
{
char V_35 [ V_36 + 1 ] ;
struct V_6 * V_7 ;
T_1 V_23 ;
int V_24 ;
if ( sscanf ( V_34 , L_1 F_28 ( V_36 ) L_2 , V_35 , & V_23 ) != 2 )
return - V_37 ;
V_7 = F_29 ( & V_38 , V_35 ) ;
if ( ! V_7 )
return - V_39 ;
F_17 () ;
V_24 = F_13 ( V_3 , V_7 , V_23 ) ;
F_19 () ;
F_30 ( V_7 ) ;
return V_24 ;
}
static int F_31 ( const void * V_40 , struct V_41 * V_41 , unsigned V_42 )
{
int V_43 ;
struct V_44 * V_45 = F_32 ( V_41 , & V_43 ) ;
if ( V_45 )
V_45 -> V_46 -> V_47 = ( T_1 ) ( unsigned long ) V_40 ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 , struct V_48 * V_49 )
{
struct V_50 * V_51 ;
void * V_40 ;
F_34 (p, cgrp, tset) {
F_35 ( V_51 ) ;
V_40 = ( void * ) ( unsigned long ) F_36 ( V_51 ) ;
F_37 ( V_51 -> V_52 , 0 , F_31 , V_40 ) ;
F_38 ( V_51 ) ;
}
}
static int F_39 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_6 * V_7 = F_40 ( V_56 ) ;
struct V_9 * V_10 ;
switch ( V_55 ) {
case V_57 :
V_10 = F_5 ( V_7 -> V_14 ) ;
F_41 ( V_7 -> V_14 , NULL ) ;
if ( V_10 )
F_10 ( V_10 , V_20 ) ;
break;
}
return V_58 ;
}
static int T_4 F_42 ( void )
{
int V_24 ;
V_24 = F_43 ( & V_59 ) ;
if ( V_24 )
goto V_60;
F_44 ( & V_61 ) ;
V_60:
return V_24 ;
}
static void T_5 F_45 ( void )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
F_46 ( & V_61 ) ;
F_47 ( & V_59 ) ;
F_17 () ;
F_18 (&init_net, dev) {
V_10 = F_5 ( V_7 -> V_14 ) ;
F_41 ( V_7 -> V_14 , NULL ) ;
if ( V_10 )
F_10 ( V_10 , V_20 ) ;
}
F_19 () ;
}
