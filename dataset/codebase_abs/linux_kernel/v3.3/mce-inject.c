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
static void F_15 ( void * V_22 )
{
int V_15 = F_11 () ;
struct V_1 * V_2 = & F_12 ( V_4 ) ;
if ( F_13 ( V_15 , V_16 ) &&
V_2 -> V_18 & V_19 ) {
F_14 ( V_15 , V_16 ) ;
F_8 ( V_2 , NULL ) ;
}
}
static int F_16 ( void )
{
struct V_1 * V_2 = & F_12 ( V_4 ) ;
int V_23 = F_17 ( V_2 -> V_18 ) ;
int V_24 = 0 ;
int V_15 = V_2 -> V_5 ;
if ( V_2 -> V_18 & V_19 ) {
F_18 ( V_25 L_1 , V_15 ) ;
switch ( V_23 ) {
case V_26 :
case V_27 :
F_8 ( V_2 , NULL ) ;
break;
default:
F_18 ( V_25 L_2 ) ;
V_24 = - V_28 ;
}
F_18 ( V_25 L_3 , V_15 ) ;
} else if ( V_2 -> V_20 ) {
F_18 ( V_25 L_4 , V_15 ) ;
F_4 ( V_2 ) ;
F_19 () ;
F_18 ( V_25 L_5 , V_15 ) ;
} else
V_2 -> V_6 = 0 ;
return V_24 ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_23 = F_17 ( V_2 -> V_18 ) ;
F_1 ( V_2 ) ;
if ( V_23 == V_29 )
return;
#ifdef F_21
if ( V_2 -> V_18 & ( V_30 | V_31 ) ) {
unsigned long V_32 ;
int V_15 ;
F_22 () ;
F_23 ( V_16 , V_33 ) ;
F_14 ( F_24 () , V_16 ) ;
F_25 (cpu) {
struct V_1 * V_34 = & F_2 ( V_4 , V_15 ) ;
if ( ! V_34 -> V_6 ||
F_17 ( V_34 -> V_18 ) != V_29 )
F_14 ( V_15 , V_16 ) ;
}
if ( ! F_26 ( V_16 ) ) {
if ( V_2 -> V_18 & V_30 ) {
F_27 () ;
F_28 ( V_16 ,
F_15 , NULL , 0 ) ;
F_29 () ;
} else if ( V_2 -> V_18 & V_31 )
V_35 -> V_36 ( V_16 ,
V_37 ) ;
}
V_32 = V_38 ;
while ( ! F_26 ( V_16 ) ) {
if ( ! F_30 ( V_38 , V_32 + 2 * V_39 ) ) {
F_18 ( V_40
L_6 ,
* F_31 ( V_16 ) ) ;
break;
}
F_32 () ;
}
F_16 () ;
F_33 () ;
F_34 () ;
} else
#endif
F_16 () ;
}
static T_2 F_35 ( struct V_41 * V_42 , const char T_3 * V_43 ,
T_4 V_44 , T_5 * V_45 )
{
struct V_1 V_2 ;
if ( ! F_36 ( V_46 ) )
return - V_47 ;
if ( ! F_37 ( V_48 ) || ! F_37 ( V_49 ) )
return - V_50 ;
if ( ( unsigned long ) V_44 > sizeof( struct V_1 ) )
V_44 = sizeof( struct V_1 ) ;
if ( F_38 ( & V_2 , V_43 , V_44 ) )
return - V_51 ;
if ( V_2 . V_5 >= F_39 () || ! F_40 ( V_2 . V_5 ) )
return - V_28 ;
F_41 ( 2 ) ;
F_20 ( & V_2 ) ;
return V_44 ;
}
static int F_42 ( void )
{
if ( ! F_43 ( & V_16 , V_52 ) )
return - V_53 ;
F_18 ( V_25 L_7 ) ;
F_44 ( F_35 ) ;
F_45 ( V_54 , F_10 , 0 ,
L_8 ) ;
return 0 ;
}
