static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
F_2 () ;
F_3 ( L_1 ) ;
F_4 () ;
F_5 (cpu) {
V_5 = F_6 ( V_3 ) ;
F_7 ( & V_5 -> V_6 , V_7 ) ;
}
F_8 () ;
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
F_10 () ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = (struct V_10 * ) ( V_9 + 1 ) ;
switch ( V_11 -> V_12 ) {
case V_13 :
F_12 ( & V_14 ) ;
break;
case V_15 :
F_12 ( & V_16 ) ;
break;
}
}
static int F_13 ( char * V_17 , T_2 V_18 )
{
static F_14 ( V_19 ) ;
struct V_20 * V_21 ;
int V_22 , V_23 ;
if ( V_18 > V_24 )
return - V_25 ;
V_21 = (struct V_20 * ) F_15 ( V_26 | V_27 ) ;
if ( ! V_21 )
return - V_28 ;
V_21 -> V_29 . V_30 = sizeof( struct V_20 ) ;
V_21 -> V_31 . V_29 . V_30 = sizeof( struct V_32 ) ;
V_21 -> V_31 . V_29 . type = V_33 ;
V_21 -> V_31 . V_34 . V_12 = V_35 ;
memcpy ( V_21 -> V_31 . V_17 , V_17 , V_18 ) ;
if ( ! ( V_36 . V_37 & V_38 ) )
F_16 ( L_2
L_3 ) ;
F_17 ( & V_19 ) ;
V_22 = F_18 ( V_39 , V_21 ) ;
F_19 ( & V_19 ) ;
if ( V_22 )
goto V_40;
V_23 = V_21 -> V_29 . V_41 ;
if ( V_23 != 0x0020 ) {
F_20 ( L_4
L_5 , V_23 ) ;
V_22 = - V_42 ;
}
V_40:
F_21 ( ( unsigned long ) V_21 ) ;
return V_22 ;
}
static T_3 F_22 ( struct V_43 * V_44 , struct V_45 * V_6 ,
struct V_46 * V_47 ,
char * V_48 , T_4 V_49 , T_2 V_50 )
{
int V_22 ;
V_22 = F_13 ( V_48 , V_50 ) ;
return V_22 ? : V_50 ;
}
static int T_5 F_23 ( void )
{
#ifdef F_24
struct V_51 * V_52 ;
int V_22 ;
V_52 = F_25 ( L_6 , NULL , V_53 ) ;
if ( ! V_52 )
return - V_28 ;
V_22 = F_26 ( & V_52 -> V_6 , & V_54 ) ;
if ( V_22 ) {
F_27 ( V_52 ) ;
return V_22 ;
}
#endif
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_22 ;
F_29 ( & V_16 , F_1 ) ;
F_29 ( & V_14 , F_9 ) ;
V_22 = F_30 ( & V_36 ) ;
if ( V_22 )
return V_22 ;
return F_23 () ;
}
