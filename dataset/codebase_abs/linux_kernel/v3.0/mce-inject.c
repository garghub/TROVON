static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = & F_2 ( V_4 , V_2 -> V_5 ) ;
V_3 -> V_6 = 0 ;
F_3 () ;
V_2 -> V_6 = 0 ;
V_3 -> V_5 = V_2 -> V_5 ;
F_3 () ;
memcpy ( V_3 , V_2 , sizeof( struct V_1 ) ) ;
F_3 () ;
V_3 -> V_6 = 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
T_1 V_8 ;
memset ( & V_8 , 0xff , sizeof( T_1 ) ) ;
F_5 ( V_7 ) ;
F_6 ( 0 , & V_8 ) ;
F_7 ( V_7 ) ;
V_2 -> V_6 = 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_9 V_11 ;
unsigned long V_7 ;
if ( ! V_10 ) {
memset ( & V_11 , 0 , sizeof( struct V_9 ) ) ;
V_11 . V_12 = V_2 -> V_12 ;
V_11 . V_13 = V_2 -> V_13 ;
V_10 = & V_11 ;
}
F_5 ( V_7 ) ;
F_9 ( V_10 , 0 ) ;
F_7 ( V_7 ) ;
V_2 -> V_6 = 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
struct V_18 * args = (struct V_18 * ) V_17 ;
int V_19 = F_11 () ;
struct V_1 * V_2 = & F_12 ( V_4 ) ;
if ( V_16 != V_20 || ! F_13 ( V_19 , V_21 ) )
return V_22 ;
F_14 ( V_19 , V_21 ) ;
if ( V_2 -> V_23 & V_24 )
F_8 ( V_2 , args -> V_11 ) ;
else if ( V_2 -> V_25 )
F_4 ( V_2 ) ;
return V_26 ;
}
static int F_15 ( void )
{
struct V_1 * V_2 = & F_12 ( V_4 ) ;
int V_27 = F_16 ( V_2 -> V_23 ) ;
int V_28 = 0 ;
int V_19 = V_2 -> V_5 ;
if ( V_2 -> V_23 & V_24 ) {
F_17 ( V_29 L_1 , V_19 ) ;
switch ( V_27 ) {
case V_30 :
case V_31 :
F_8 ( V_2 , NULL ) ;
break;
default:
F_17 ( V_29 L_2 ) ;
V_28 = - V_32 ;
}
F_17 ( V_29 L_3 , V_19 ) ;
} else if ( V_2 -> V_25 ) {
F_17 ( V_29 L_4 , V_19 ) ;
F_4 ( V_2 ) ;
F_18 () ;
F_17 ( V_29 L_5 , V_19 ) ;
} else
V_2 -> V_6 = 0 ;
return V_28 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_27 = F_16 ( V_2 -> V_23 ) ;
F_1 ( V_2 ) ;
if ( V_27 == V_33 )
return;
#ifdef F_20
if ( V_2 -> V_23 & V_34 ) {
unsigned long V_35 ;
int V_19 ;
F_21 () ;
F_22 ( V_21 , V_36 ) ;
F_14 ( F_23 () , V_21 ) ;
F_24 (cpu) {
struct V_1 * V_37 = & F_2 ( V_4 , V_19 ) ;
if ( ! V_37 -> V_6 ||
F_16 ( V_37 -> V_23 ) != V_33 )
F_14 ( V_19 , V_21 ) ;
}
if ( ! F_25 ( V_21 ) )
V_38 -> V_39 ( V_21 , V_40 ) ;
V_35 = V_41 ;
while ( ! F_25 ( V_21 ) ) {
if ( ! F_26 ( V_41 , V_35 + 2 * V_42 ) ) {
F_17 ( V_43
L_6 ,
* F_27 ( V_21 ) ) ;
break;
}
F_28 () ;
}
F_15 () ;
F_29 () ;
F_30 () ;
} else
#endif
F_15 () ;
}
static T_2 F_31 ( struct V_44 * V_45 , const char T_3 * V_46 ,
T_4 V_47 , T_5 * V_48 )
{
struct V_1 V_2 ;
if ( ! F_32 ( V_49 ) )
return - V_50 ;
if ( ! F_33 ( V_51 ) || ! F_33 ( V_52 ) )
return - V_53 ;
if ( ( unsigned long ) V_47 > sizeof( struct V_1 ) )
V_47 = sizeof( struct V_1 ) ;
if ( F_34 ( & V_2 , V_46 , V_47 ) )
return - V_54 ;
if ( V_2 . V_5 >= F_35 () || ! F_36 ( V_2 . V_5 ) )
return - V_32 ;
F_37 ( 2 ) ;
F_19 ( & V_2 ) ;
return V_47 ;
}
static int F_38 ( void )
{
if ( ! F_39 ( & V_21 , V_55 ) )
return - V_56 ;
F_17 ( V_29 L_7 ) ;
V_57 . V_58 = F_31 ;
F_40 ( & V_59 ) ;
return 0 ;
}
