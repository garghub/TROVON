static const char * F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
default:
return L_4 ;
}
}
const char * F_4 ( void )
{
return F_1 () ;
}
void T_1 F_5 ( void )
{
F_6 ( V_5 ,
V_5 + V_6 ) ;
F_7 ( V_7 L_5 , F_1 () ) ;
}
static int F_8 ( const struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
if ( ( V_10 < 12 ) || ( V_10 > 13 ) || V_11 == 0 )
return - 1 ;
if ( V_10 == 12 )
return ( V_11 == 1 ) ? V_12 : 0xff ;
if ( V_10 == 13 ) {
switch ( V_11 ) {
case 1 : return V_12 ;
case 2 : return V_13 ;
case 3 : return V_14 ;
case 4 : return V_15 ;
}
}
return - 1 ;
}
static int T_1 F_9 ( void )
{
if ( F_2 ( F_3 ( V_1 ) ) == V_3 )
return F_10 ( & V_16 ) ;
return 0 ;
}
static T_3 F_11 ( int V_17 , void * V_18 )
{
void (* F_12)( struct V_19 * , unsigned long );
F_12 = F_13 ( V_20 ) ;
F_12 ( V_18 , F_14 ( 500 ) ) ;
F_15 ( V_20 ) ;
return V_21 ;
}
static int F_16 ( void * V_19 , int V_22 )
{
int V_23 = 0 ;
if ( V_22 ) {
F_17 ( V_24 , V_25 ) ;
V_23 = F_18 ( V_24 , F_11 , 0 ,
L_6 , V_19 ) ;
} else
F_19 ( V_24 , V_19 ) ;
return V_23 ;
}
static int F_20 ( void * V_19 , int V_22 )
{
int V_23 = 0 ;
if ( V_22 ) {
F_17 ( V_26 , V_25 ) ;
V_23 = F_18 ( V_26 , F_11 , 0 ,
L_7 , V_19 ) ;
} else
F_19 ( V_26 , V_19 ) ;
return V_23 ;
}
static int F_21 ( void * V_19 )
{
return ( F_3 ( V_27 ) & V_28 ) ? 0 : 1 ;
}
static int F_22 ( void * V_19 )
{
return ! F_23 ( 19 ) ;
}
static void F_24 ( void * V_19 , int V_29 )
{
if ( V_29 ) {
F_25 ( V_30 , 0 , V_31 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_30 , V_31 , 0 ) ;
}
static void F_27 ( struct V_32 * V_33 , enum V_34 V_35 )
{
if ( V_35 != V_36 )
F_25 ( V_37 , V_38 , 0 ) ;
else
F_25 ( V_37 , 0 , V_38 ) ;
}
static int F_28 ( void * V_19 )
{
return ( F_3 ( V_30 ) & V_39 ) ? 1 : 0 ;
}
static int F_29 ( void * V_19 )
{
return ! F_23 ( 20 ) ;
}
static void F_30 ( void * V_19 , int V_29 )
{
if ( V_29 ) {
F_25 ( V_30 , 0 , V_40 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_30 , V_40 , 0 ) ;
}
static void F_31 ( struct V_32 * V_33 , enum V_34 V_35 )
{
if ( V_35 != V_36 )
F_25 ( V_37 , V_41 , 0 ) ;
else
F_25 ( V_37 , 0 , V_41 ) ;
}
static void F_32 ( int V_42 )
{
unsigned short V_43 = V_44 | V_45 ;
switch ( V_42 ) {
case V_46 :
F_25 ( V_47 , V_43 , V_48 ) ;
break;
case V_49 :
F_25 ( V_47 , V_43 , V_50 ) ;
break;
case V_51 :
F_25 ( V_47 , V_43 , V_50 |
V_45 ) ;
break;
}
}
static int T_1 F_33 ( void )
{
int V_52 = F_2 ( F_3 ( V_1 ) ) ;
int V_53 , V_54 , V_55 , V_56 , V_57 , V_58 ;
unsigned long V_59 ;
if ( V_52 == V_3 ) {
V_53 = V_60 ;
V_54 = V_61 ;
V_55 = V_62 ;
V_56 = V_63 ;
V_57 = V_64 ;
V_58 = V_65 ;
} else if ( V_52 == V_4 ) {
V_53 = V_66 ;
V_54 = V_67 ;
V_55 = V_68 ;
V_56 = V_69 ;
V_57 = V_70 ;
V_58 = V_71 ;
F_34 ( 19 ) ;
F_34 ( 20 ) ;
F_34 ( 21 ) ;
F_34 ( 207 ) ;
F_35 ( 208 , 0 ) ;
F_35 ( 209 , 1 ) ;
F_35 ( 210 , 1 ) ;
V_59 = F_36 ( ( void V_72 * ) V_73 ) ;
V_59 |= ( 1 << 0 ) ;
F_37 ( V_59 , ( void V_72 * ) V_73 ) ;
F_38 () ;
F_39 ( V_74 ,
F_40 ( V_74 ) ) ;
F_41 ( V_75 , F_40 ( V_75 ) ) ;
} else if ( V_52 == V_2 ) {
V_53 = V_76 ;
V_54 = V_77 ;
V_55 = V_78 ;
V_56 = V_79 ;
V_57 = V_80 ;
V_58 = V_81 ;
F_41 ( V_82 , F_40 ( V_82 ) ) ;
} else
return 0 ;
F_17 ( V_55 , V_25 ) ;
F_17 ( V_56 , V_25 ) ;
F_17 ( V_53 , V_83 ) ;
F_17 ( V_54 , V_83 ) ;
F_17 ( V_57 , V_83 ) ;
F_17 ( V_58 , V_83 ) ;
F_42 (
V_84 ,
V_84 + 0x000400000 - 1 ,
V_85 ,
V_85 + 0x000400000 - 1 ,
V_86 ,
V_86 + 0x000010000 - 1 ,
V_53 , V_55 , 0 , 0 , 0 ) ;
F_42 (
V_84 + 0x004000000 ,
V_84 + 0x004400000 - 1 ,
V_85 + 0x004000000 ,
V_85 + 0x004400000 - 1 ,
V_86 + 0x004000000 ,
V_86 + 0x004010000 - 1 ,
V_54 , V_56 , 0 , 0 , 1 ) ;
F_41 ( V_87 , F_40 ( V_87 ) ) ;
F_43 ( 32 << 20 , 4 , V_88 ) ;
return 0 ;
}
