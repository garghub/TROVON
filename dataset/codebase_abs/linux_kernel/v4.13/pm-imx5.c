static void F_1 ( enum V_1 V_2 )
{
T_1 V_3 , V_4 , V_5 ;
T_1 V_6 , V_7 ;
int V_8 = 0 ;
V_3 = F_2 ( V_9 + V_10 ) &
~ ( V_11 ) ;
V_5 = F_2 ( V_12 + V_13 ) &
~ ( V_14 ) ;
V_4 = F_2 ( V_15 + V_16 ) &
~ ( V_17 ) ;
V_6 = F_2 ( V_15 + V_18 ) &
~ ( V_17 ) ;
V_7 = F_2 ( V_15 + V_19 ) &
~ ( V_17 ) ;
switch ( V_2 ) {
case V_20 :
break;
case V_21 :
V_5 |= 0x1 << V_22 ;
break;
case V_23 :
case V_24 :
V_3 |= V_11
| V_25 ;
if ( V_2 == V_23 ) {
V_5 |= 0x1 << V_22 ;
V_5 &= ~ V_26 ;
V_5 &= ~ V_27 ;
V_8 = 0 ;
} else {
V_5 |= 0x2 << V_22 ;
V_5 |= 0x3 << V_28 ;
V_5 |= V_26 ;
V_5 |= V_27 ;
V_8 = 1 ;
}
V_4 |= V_17 ;
break;
case V_29 :
V_5 |= 0x2 << V_22 ;
break;
default:
F_3 ( V_30 L_1 , V_2 ) ;
return;
}
F_4 ( V_3 , V_9 + V_10 ) ;
F_4 ( V_5 , V_12 + V_13 ) ;
F_4 ( V_4 , V_15 + V_16 ) ;
F_4 ( V_4 , V_15 + V_31 ) ;
if ( V_8 ) {
V_6 |= V_17 ;
V_7 |= V_17 ;
F_4 ( V_6 , V_15 + V_18 ) ;
F_4 ( V_7 , V_15 + V_19 ) ;
}
}
static int F_5 ( T_2 V_32 )
{
switch ( V_32 ) {
case V_33 :
F_1 ( V_24 ) ;
break;
case V_34 :
break;
default:
return - V_35 ;
}
if ( V_32 == V_33 ) {
F_6 () ;
F_7 () ;
F_4 ( 0 , V_15 + V_18 ) ;
F_4 ( 0 , V_15 + V_19 ) ;
if ( V_36 )
V_36 ( V_37 ) ;
else
F_8 () ;
} else {
F_8 () ;
}
F_1 ( V_38 ) ;
return 0 ;
}
static int F_9 ( T_2 V_32 )
{
return ( V_32 > V_39 && V_32 <= V_40 ) ;
}
static inline int F_10 ( void )
{
int V_41 = F_11 () ;
if ( F_12 ( ! V_41 ) )
F_8 () ;
return V_41 ;
}
static void F_13 ( void )
{
F_10 () ;
}
static int T_3 F_14 (
T_4 V_42 ,
void T_5 * * V_43 ,
T_6 * V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
unsigned long V_51 ;
void T_5 * V_52 ;
T_6 V_53 ;
int V_41 = 0 ;
V_46 = F_15 ( NULL , NULL , L_2 ) ;
if ( ! V_46 ) {
F_16 ( L_3 , V_54 ) ;
return - V_55 ;
}
V_48 = F_17 ( V_46 ) ;
if ( ! V_48 ) {
F_16 ( L_4 , V_54 ) ;
V_41 = - V_55 ;
goto V_56;
}
V_50 = F_18 ( & V_48 -> V_57 , NULL ) ;
if ( ! V_50 ) {
F_16 ( L_5 , V_54 ) ;
V_41 = - V_55 ;
goto V_56;
}
V_51 = F_19 ( V_50 , V_42 ) ;
if ( ! V_51 ) {
F_16 ( L_6 , V_54 ) ;
V_41 = - V_58 ;
goto V_56;
}
V_53 = F_20 ( V_50 , V_51 ) ;
V_52 = F_21 ( V_53 , V_42 , false ) ;
if ( V_44 )
* V_44 = V_53 ;
if ( V_43 )
* V_43 = V_52 ;
V_56:
F_22 ( V_46 ) ;
return V_41 ;
}
static int T_3 F_23 ( const struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_41 ;
void (* F_24)( void T_5 * ) = V_60 -> F_24 ;
if ( ! F_24 )
return 0 ;
if ( ! V_60 -> V_63 || ! * V_60 -> V_63 )
return - V_35 ;
V_41 = F_14 (
* V_60 -> V_63 + sizeof( * V_62 ) ,
& V_37 , NULL ) ;
if ( V_41 )
return V_41 ;
V_62 = V_37 ;
V_62 -> V_64 = V_60 -> V_65 ;
memcpy ( V_62 -> V_66 , V_60 -> V_67 ,
sizeof( * V_62 -> V_66 ) * V_60 -> V_65 ) ;
V_62 -> V_68 = F_25 ( V_60 -> V_69 , V_70 ) ;
if ( ! V_62 -> V_68 ) {
V_41 = - V_58 ;
goto V_71;
}
V_62 -> V_72 = F_25 ( V_60 -> V_73 , V_70 ) ;
if ( ! V_62 -> V_72 ) {
V_41 = - V_58 ;
goto V_74;
}
V_36 = F_26 (
V_37 + sizeof( * V_62 ) ,
F_24 ,
* V_60 -> V_63 ) ;
return 0 ;
V_74:
F_27 ( V_62 -> V_68 ) ;
V_71:
return V_41 ;
}
static int T_3 F_28 ( const struct V_59 * V_75 )
{
int V_41 ;
struct V_76 * V_77 = F_29 ( NULL , L_7 ) ;
if ( F_30 ( V_77 ) )
return F_31 ( V_77 ) ;
V_41 = F_32 ( V_77 ) ;
if ( V_41 )
return V_41 ;
V_78 = F_13 ;
V_12 = F_25 ( V_75 -> V_79 , V_70 ) ;
V_9 = F_25 ( V_75 -> V_80 , V_70 ) ;
V_15 = F_25 ( V_75 -> V_81 , V_70 ) ;
F_33 ( ! V_12 || ! V_9 || ! V_15 ) ;
F_1 ( V_38 ) ;
V_41 = F_34 () ;
if ( V_41 )
F_16 ( L_8 , V_54 , V_41 ) ;
V_41 = F_23 ( V_75 ) ;
if ( V_41 )
F_16 ( L_9 ,
V_54 , V_41 ) ;
F_35 ( & V_82 ) ;
return 0 ;
}
void T_3 F_36 ( void )
{
if ( F_37 ( V_83 ) )
F_28 ( & V_84 ) ;
}
void T_3 F_38 ( void )
{
if ( F_37 ( V_85 ) )
F_28 ( & V_86 ) ;
}
