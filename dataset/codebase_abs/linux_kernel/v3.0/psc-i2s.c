static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
int V_7 ;
V_7 = - V_8 ;
V_6 = V_5 -> V_9 ;
V_6 &= ~ ( V_10 | V_11 ) ;
switch ( V_3 & V_12 ) {
case V_13 :
V_6 |= V_10 ;
break;
case V_14 :
break;
case V_15 :
V_6 |= V_11 ;
break;
default:
goto V_16;
}
V_6 &= ~ ( V_17 | V_18 ) ;
switch ( V_3 & V_19 ) {
case V_20 :
V_6 |= V_17 | V_18 ;
break;
case V_21 :
V_6 |= V_17 ;
break;
case V_22 :
V_6 |= V_18 ;
break;
case V_23 :
break;
default:
goto V_16;
}
switch ( V_3 & V_24 ) {
case V_25 :
V_6 |= V_26 ;
break;
case V_27 :
V_6 &= ~ V_26 ;
break;
default:
goto V_16;
}
V_5 -> V_9 = V_6 ;
V_7 = 0 ;
V_16:
return V_7 ;
}
static int F_3 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_1 * V_32 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
int V_33 ;
unsigned long V_34 ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( V_34 & ( V_35 | V_36 ) ) {
V_33 = F_4 ( F_6 ( V_5 ) ) ;
if ( ( F_7 ( V_33 ) != V_31 -> V_37 ) ||
( F_8 ( V_31 ) != V_5 -> V_38 ) )
return - V_8 ;
} else {
V_5 -> V_9 &= ~ ( 0x1f << 4 ) ;
V_5 -> V_9 |= F_9 ( V_31 -> V_37 ) ;
V_5 -> V_38 = F_8 ( V_31 ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
unsigned long V_39 ;
F_11 ( V_40 , F_12 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & V_41 ) && V_39 )
V_39 -- ;
if ( ! V_39 )
goto V_42;
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_13 () ;
F_11 ( V_5 -> V_9 | V_43 , F_6 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & V_44 ) && V_39 )
V_39 -- ;
if ( V_39 )
return 0 ;
V_42:
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_11 ( V_45 , F_12 ( V_5 ) ) ;
F_13 () ;
return - V_46 ;
}
static int F_14 ( struct V_4 * V_5 , int V_47 )
{
unsigned long V_39 , V_34 ;
int V_7 ;
V_7 = 0 ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( ! ( V_34 & ( V_35 | V_36 ) ) ) {
V_7 = F_10 ( V_5 ) ;
if ( V_7 )
goto V_16;
}
F_11 ( F_15 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
F_11 ( F_17 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ! ( F_4 ( F_5 ( V_5 ) ) & F_18 ( V_47 ) ) && V_39 )
V_39 -- ;
if ( ! V_39 ) {
F_11 ( F_19 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_7 = - V_46 ;
}
V_16:
return V_7 ;
}
static int F_20 ( struct V_4 * V_5 , int V_47 )
{
unsigned long V_39 , V_34 ;
F_11 ( F_19 ( V_47 ) , F_16 ( V_5 ) ) ;
F_13 () ;
V_39 = 1000000 ;
while ( ( F_4 ( F_5 ( V_5 ) ) & F_18 ( V_47 ) ) && V_39 )
V_39 -- ;
V_34 = F_4 ( F_5 ( V_5 ) ) ;
if ( ! ( V_34 & ( V_35 | V_36 ) ) ) {
F_11 ( 0 , F_6 ( V_5 ) ) ;
F_13 () ;
F_11 ( V_45 , F_12 ( V_5 ) ) ;
F_13 () ;
}
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int V_48 ,
struct V_1 * V_32 )
{
struct V_4 * V_5 = F_2 ( V_32 ) ;
int V_7 , V_47 = F_22 ( V_29 ) ;
switch ( V_48 ) {
case V_49 :
case V_50 :
V_7 = F_14 ( V_5 , V_47 ) ;
break;
case V_51 :
case V_52 :
V_7 = F_20 ( V_5 , V_47 ) ;
break;
default:
V_7 = - V_8 ;
}
return V_7 ;
}
static int T_1 F_23 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
unsigned long V_57 ;
int V_7 ;
struct V_4 * V_58 ;
V_58 = F_24 ( sizeof( struct V_4 ) , V_59 ) ;
if ( ! V_58 )
return - V_60 ;
V_56 = F_25 ( V_54 , V_61 , 0 ) ;
if ( ! V_56 ) {
V_7 = - V_62 ;
goto V_63;
}
V_7 = - V_64 ;
if ( ! F_26 ( V_56 -> V_65 , F_27 ( V_56 ) , V_54 -> V_66 ) )
goto V_63;
V_58 -> V_67 = F_28 ( V_56 -> V_65 , F_27 ( V_56 ) ) ;
if ( ! V_58 -> V_67 )
goto V_68;
V_57 = F_4 ( F_29 ( V_58 ) ) & V_69 ;
F_11 ( V_70 , F_12 ( V_58 ) ) ;
F_13 () ;
F_11 ( V_71 | V_57 , F_29 ( V_58 ) ) ;
F_11 ( 0 , F_6 ( V_58 ) ) ;
F_13 () ;
V_58 -> V_9 |= V_72 | V_73 ;
memcpy ( & V_58 -> V_74 , & V_75 ,
sizeof( struct V_76 ) ) ;
V_58 -> V_74 . V_66 = F_30 ( & V_54 -> V_77 ) ;
F_31 ( V_54 , V_58 ) ;
V_7 = F_32 ( & V_54 -> V_77 , & V_58 -> V_74 ) ;
if ( V_7 )
goto V_68;
V_58 -> V_78 = F_33 ( V_54 ) ;
if ( V_58 -> V_78 )
return 0 ;
F_34 ( & V_54 -> V_77 ) ;
V_68:
F_35 ( V_56 -> V_65 , F_27 ( V_56 ) ) ;
V_63:
F_36 ( V_58 ) ;
return V_7 ;
}
static int T_2 F_37 ( struct V_53 * V_54 )
{
struct V_4 * V_58 = F_38 ( V_54 ) ;
struct V_55 * V_56 = F_25 ( V_54 , V_61 , 0 ) ;
if ( V_58 -> V_78 )
F_39 ( V_58 -> V_78 ) ;
F_34 ( & V_54 -> V_77 ) ;
F_11 ( 0 , F_6 ( V_58 ) ) ;
F_13 () ;
F_11 ( V_70 , F_12 ( V_58 ) ) ;
F_13 () ;
F_40 ( V_58 -> V_67 ) ;
F_35 ( V_56 -> V_65 , F_27 ( V_56 ) ) ;
F_36 ( V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_79 * V_77 )
{
struct V_4 * V_58 = F_42 ( V_77 ) ;
V_58 -> V_80 [ 0 ] = F_4 ( F_29 ( V_58 ) ) ;
F_11 ( 0 , F_6 ( V_58 ) ) ;
F_13 () ;
F_11 ( V_70 , F_12 ( V_58 ) ) ;
F_13 () ;
return 0 ;
}
static int F_43 ( struct V_79 * V_77 )
{
struct V_4 * V_58 = F_42 ( V_77 ) ;
F_11 ( V_70 , F_12 ( V_58 ) ) ;
F_13 () ;
F_11 ( 0 , F_29 ( V_58 ) ) ;
F_13 () ;
F_11 ( V_58 -> V_80 [ 0 ] , F_29 ( V_58 ) ) ;
F_13 () ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_81 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_81 ) ;
}
