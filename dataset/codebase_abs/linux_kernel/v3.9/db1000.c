static const char * F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
default:
return L_6 ;
}
}
const char * F_4 ( void )
{
return F_1 () ;
}
void T_1 F_5 ( void )
{
F_6 ( V_8 ,
V_8 + V_9 ) ;
F_7 ( V_10 L_7 , F_1 () ) ;
}
static int F_8 ( const struct V_11 * V_12 , T_2 V_13 , T_2 V_14 )
{
if ( ( V_13 < 12 ) || ( V_13 > 13 ) || V_14 == 0 )
return - 1 ;
if ( V_13 == 12 )
return ( V_14 == 1 ) ? V_15 : 0xff ;
if ( V_13 == 13 ) {
switch ( V_14 ) {
case 1 : return V_15 ;
case 2 : return V_16 ;
case 3 : return V_17 ;
case 4 : return V_18 ;
}
}
return - 1 ;
}
static int T_1 F_9 ( void )
{
int V_19 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_19 == V_3 ) || ( V_19 == V_5 ) ||
( V_19 == V_6 ) )
return F_10 ( & V_20 ) ;
return 0 ;
}
static T_3 F_11 ( int V_21 , void * V_22 )
{
void (* F_12)( struct V_23 * , unsigned long );
F_12 = F_13 ( V_24 ) ;
F_12 ( V_22 , F_14 ( 500 ) ) ;
F_15 ( V_24 ) ;
return V_25 ;
}
static int F_16 ( void * V_23 , int V_26 )
{
int V_27 = 0 , V_21 ;
if ( F_2 ( F_3 ( V_1 ) ) == V_4 )
V_21 = V_28 ;
else
V_21 = V_29 ;
if ( V_26 ) {
F_17 ( V_21 , V_30 ) ;
V_27 = F_18 ( V_21 , F_11 , 0 ,
L_8 , V_23 ) ;
} else
F_19 ( V_21 , V_23 ) ;
return V_27 ;
}
static int F_20 ( void * V_23 , int V_26 )
{
int V_27 = 0 , V_21 ;
if ( F_2 ( F_3 ( V_1 ) ) == V_4 )
V_21 = V_31 ;
else
V_21 = V_32 ;
if ( V_26 ) {
F_17 ( V_21 , V_30 ) ;
V_27 = F_18 ( V_21 , F_11 , 0 ,
L_9 , V_23 ) ;
} else
F_19 ( V_21 , V_23 ) ;
return V_27 ;
}
static int F_21 ( void * V_23 )
{
return ( F_3 ( V_33 ) & V_34 ) ? 0 : 1 ;
}
static int F_22 ( void * V_23 )
{
return ! F_23 ( 19 ) ;
}
static void F_24 ( void * V_23 , int V_35 )
{
int V_36 ;
if ( F_2 ( F_3 ( V_1 ) ) == V_4 )
V_36 = V_37 ;
else
V_36 = V_38 ;
if ( V_35 ) {
F_25 ( V_39 , 0 , V_36 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_39 , V_36 , 0 ) ;
}
static void F_27 ( struct V_40 * V_41 , enum V_42 V_43 )
{
if ( V_43 != V_44 )
F_25 ( V_45 , V_46 , 0 ) ;
else
F_25 ( V_45 , 0 , V_46 ) ;
}
static int F_28 ( void * V_23 )
{
return ( F_3 ( V_39 ) & V_47 ) ? 1 : 0 ;
}
static int F_29 ( void * V_23 )
{
return ! F_23 ( 20 ) ;
}
static void F_30 ( void * V_23 , int V_35 )
{
int V_36 ;
if ( F_2 ( F_3 ( V_1 ) ) == V_4 )
V_36 = V_48 ;
else
V_36 = V_49 ;
if ( V_35 ) {
F_25 ( V_39 , 0 , V_36 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_39 , V_36 , 0 ) ;
}
static void F_31 ( struct V_40 * V_41 , enum V_42 V_43 )
{
if ( V_43 != V_44 )
F_25 ( V_45 , V_50 , 0 ) ;
else
F_25 ( V_45 , 0 , V_50 ) ;
}
static void F_32 ( int V_51 )
{
unsigned short V_52 = V_53 | V_54 ;
switch ( V_51 ) {
case V_55 :
F_25 ( V_56 , V_52 , V_57 ) ;
break;
case V_58 :
F_25 ( V_56 , V_52 , V_59 ) ;
break;
case V_60 :
F_25 ( V_56 , V_52 , V_59 |
V_54 ) ;
break;
}
}
static int T_1 F_33 ( void )
{
int V_61 = F_2 ( F_3 ( V_1 ) ) ;
int V_62 , V_63 , V_64 , V_65 , V_66 , V_67 , V_68 = 32 , V_69 = 1 ;
unsigned long V_70 ;
if ( V_61 == V_3 ) {
V_62 = V_71 ;
V_63 = V_72 ;
V_64 = V_73 ;
V_65 = V_74 ;
V_66 = V_75 ;
V_67 = V_76 ;
} else if ( V_61 == V_4 ) {
V_62 = V_77 ;
V_63 = V_78 ;
V_64 = V_79 ;
V_65 = V_80 ;
V_66 = V_81 ;
V_67 = V_82 ;
F_34 ( 19 ) ;
F_34 ( 20 ) ;
F_34 ( 21 ) ;
F_34 ( 207 ) ;
F_35 ( 208 , 0 ) ;
F_35 ( 209 , 1 ) ;
F_35 ( 210 , 1 ) ;
V_70 = F_36 ( ( void V_83 * ) V_84 ) ;
V_70 |= ( 1 << 0 ) ;
F_37 ( V_70 , ( void V_83 * ) V_84 ) ;
F_38 () ;
F_39 ( V_85 ,
F_40 ( V_85 ) ) ;
F_41 ( V_86 , F_40 ( V_86 ) ) ;
F_10 ( & V_87 ) ;
} else if ( V_61 == V_2 ) {
V_62 = V_88 ;
V_63 = V_89 ;
V_64 = V_90 ;
V_65 = V_91 ;
V_66 = V_92 ;
V_67 = V_93 ;
F_41 ( V_94 , F_40 ( V_94 ) ) ;
} else if ( ( V_61 == V_5 ) ||
( V_61 == V_6 ) ) {
V_62 = V_95 ;
V_64 = V_96 ;
V_66 = V_97 ;
V_69 = 0 ;
V_68 = 64 ;
F_17 ( V_98 , V_99 ) ;
F_17 ( V_100 , V_99 ) ;
} else if ( V_61 == V_7 ) {
V_62 = V_101 ;
V_64 = V_102 ;
V_66 = V_103 ;
V_69 = 0 ;
V_68 = 64 ;
F_17 ( V_104 , V_99 ) ;
F_17 ( V_105 , V_99 ) ;
F_17 ( V_106 , V_99 ) ;
F_41 ( V_86 , F_40 ( V_86 ) ) ;
} else
return 0 ;
F_17 ( V_64 , V_30 ) ;
F_17 ( V_62 , V_99 ) ;
F_17 ( V_66 , V_99 ) ;
F_42 (
V_107 ,
V_107 + 0x000400000 - 1 ,
V_108 ,
V_108 + 0x000400000 - 1 ,
V_109 ,
V_109 + 0x000010000 - 1 ,
V_62 , V_64 , 0 , 0 , 0 ) ;
if ( V_69 ) {
F_17 ( V_65 , V_30 ) ;
F_17 ( V_63 , V_99 ) ;
F_17 ( V_67 , V_99 ) ;
F_42 (
V_107 + 0x004000000 ,
V_107 + 0x004400000 - 1 ,
V_108 + 0x004000000 ,
V_108 + 0x004400000 - 1 ,
V_109 + 0x004000000 ,
V_109 + 0x004010000 - 1 ,
V_63 , V_65 , 0 , 0 , 1 ) ;
}
F_41 ( V_110 , F_40 ( V_110 ) ) ;
F_43 ( V_68 << 20 , 4 , V_111 ) ;
return 0 ;
}
