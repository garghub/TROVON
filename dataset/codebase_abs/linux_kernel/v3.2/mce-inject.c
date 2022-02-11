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
static int F_10 ( unsigned int V_14 , struct V_9 * V_11 )
{
int V_15 = F_11 () ;
struct V_1 * V_2 = & F_12 ( V_4 ) ;
if ( ! F_13 ( V_15 , V_16 ) )
return V_17 ;
F_14 ( V_15 , V_16 ) ;
if ( V_2 -> V_18 & V_19 )
F_8 ( V_2 , V_11 ) ;
else if ( V_2 -> V_20 )
F_4 ( V_2 ) ;
return V_21 ;
}
static int F_15 ( void )
{
struct V_1 * V_2 = & F_12 ( V_4 ) ;
int V_22 = F_16 ( V_2 -> V_18 ) ;
int V_23 = 0 ;
int V_15 = V_2 -> V_5 ;
if ( V_2 -> V_18 & V_19 ) {
F_17 ( V_24 L_1 , V_15 ) ;
switch ( V_22 ) {
case V_25 :
case V_26 :
F_8 ( V_2 , NULL ) ;
break;
default:
F_17 ( V_24 L_2 ) ;
V_23 = - V_27 ;
}
F_17 ( V_24 L_3 , V_15 ) ;
} else if ( V_2 -> V_20 ) {
F_17 ( V_24 L_4 , V_15 ) ;
F_4 ( V_2 ) ;
F_18 () ;
F_17 ( V_24 L_5 , V_15 ) ;
} else
V_2 -> V_6 = 0 ;
return V_23 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_22 = F_16 ( V_2 -> V_18 ) ;
F_1 ( V_2 ) ;
if ( V_22 == V_28 )
return;
#ifdef F_20
if ( V_2 -> V_18 & V_29 ) {
unsigned long V_30 ;
int V_15 ;
F_21 () ;
F_22 ( V_16 , V_31 ) ;
F_14 ( F_23 () , V_16 ) ;
F_24 (cpu) {
struct V_1 * V_32 = & F_2 ( V_4 , V_15 ) ;
if ( ! V_32 -> V_6 ||
F_16 ( V_32 -> V_18 ) != V_28 )
F_14 ( V_15 , V_16 ) ;
}
if ( ! F_25 ( V_16 ) )
V_33 -> V_34 ( V_16 , V_35 ) ;
V_30 = V_36 ;
while ( ! F_25 ( V_16 ) ) {
if ( ! F_26 ( V_36 , V_30 + 2 * V_37 ) ) {
F_17 ( V_38
L_6 ,
* F_27 ( V_16 ) ) ;
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
static T_2 F_31 ( struct V_39 * V_40 , const char T_3 * V_41 ,
T_4 V_42 , T_5 * V_43 )
{
struct V_1 V_2 ;
if ( ! F_32 ( V_44 ) )
return - V_45 ;
if ( ! F_33 ( V_46 ) || ! F_33 ( V_47 ) )
return - V_48 ;
if ( ( unsigned long ) V_42 > sizeof( struct V_1 ) )
V_42 = sizeof( struct V_1 ) ;
if ( F_34 ( & V_2 , V_41 , V_42 ) )
return - V_49 ;
if ( V_2 . V_5 >= F_35 () || ! F_36 ( V_2 . V_5 ) )
return - V_27 ;
F_37 ( 2 ) ;
F_19 ( & V_2 ) ;
return V_42 ;
}
static int F_38 ( void )
{
if ( ! F_39 ( & V_16 , V_50 ) )
return - V_51 ;
F_17 ( V_24 L_7 ) ;
F_40 ( F_31 ) ;
F_41 ( V_52 , F_10 , 0 ,
L_8 ) ;
return 0 ;
}
