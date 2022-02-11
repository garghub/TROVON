int T_1 F_1 ( void )
{
F_2 ( V_1 ,
V_1 + V_2 ) ;
switch ( F_3 ( F_4 ( V_3 ) ) ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
F_5 ( L_1 , F_6 () ) ;
return 0 ;
}
return - V_10 ;
}
static int F_7 ( const struct V_11 * V_12 , T_2 V_13 , T_2 V_14 )
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
int T_1 F_8 ( void )
{
return F_9 ( & V_19 ) ;
}
static T_3 F_10 ( int V_20 , void * V_21 )
{
void (* F_11)( struct V_22 * , unsigned long );
F_11 = F_12 ( V_23 ) ;
F_11 ( V_21 , F_13 ( 500 ) ) ;
F_14 ( V_23 ) ;
return V_24 ;
}
static int F_15 ( void * V_22 , int V_25 )
{
int V_26 = 0 , V_20 ;
if ( F_3 ( F_4 ( V_3 ) ) == V_6 )
V_20 = V_27 ;
else
V_20 = V_28 ;
if ( V_25 ) {
F_16 ( V_20 , V_29 ) ;
V_26 = F_17 ( V_20 , F_10 , 0 ,
L_2 , V_22 ) ;
} else
F_18 ( V_20 , V_22 ) ;
return V_26 ;
}
static int F_19 ( void * V_22 , int V_25 )
{
int V_26 = 0 , V_20 ;
if ( F_3 ( F_4 ( V_3 ) ) == V_6 )
V_20 = V_30 ;
else
V_20 = V_31 ;
if ( V_25 ) {
F_16 ( V_20 , V_29 ) ;
V_26 = F_17 ( V_20 , F_10 , 0 ,
L_3 , V_22 ) ;
} else
F_18 ( V_20 , V_22 ) ;
return V_26 ;
}
static int F_20 ( void * V_22 )
{
return ( F_4 ( V_32 ) & V_33 ) ? 0 : 1 ;
}
static int F_21 ( void * V_22 )
{
return ! F_22 ( 19 ) ;
}
static void F_23 ( void * V_22 , int V_34 )
{
int V_35 ;
if ( F_3 ( F_4 ( V_3 ) ) == V_6 )
V_35 = V_36 ;
else
V_35 = V_37 ;
if ( V_34 ) {
F_24 ( V_38 , 0 , V_35 ) ;
F_25 ( 400 ) ;
} else
F_24 ( V_38 , V_35 , 0 ) ;
}
static void F_26 ( struct V_39 * V_40 , enum V_41 V_42 )
{
if ( V_42 != V_43 )
F_24 ( V_44 , V_45 , 0 ) ;
else
F_24 ( V_44 , 0 , V_45 ) ;
}
static int F_27 ( void * V_22 )
{
return ( F_4 ( V_38 ) & V_46 ) ? 1 : 0 ;
}
static int F_28 ( void * V_22 )
{
return ! F_22 ( 20 ) ;
}
static void F_29 ( void * V_22 , int V_34 )
{
int V_35 ;
if ( F_3 ( F_4 ( V_3 ) ) == V_6 )
V_35 = V_47 ;
else
V_35 = V_48 ;
if ( V_34 ) {
F_24 ( V_38 , 0 , V_35 ) ;
F_25 ( 400 ) ;
} else
F_24 ( V_38 , V_35 , 0 ) ;
}
static void F_30 ( struct V_39 * V_40 , enum V_41 V_42 )
{
if ( V_42 != V_43 )
F_24 ( V_44 , V_49 , 0 ) ;
else
F_24 ( V_44 , 0 , V_49 ) ;
}
static void F_31 ( int V_50 )
{
unsigned short V_51 = V_52 | V_53 ;
switch ( V_50 ) {
case V_54 :
F_24 ( V_55 , V_51 , V_56 ) ;
break;
case V_57 :
F_24 ( V_55 , V_51 , V_58 ) ;
break;
case V_59 :
F_24 ( V_55 , V_51 , V_58 |
V_53 ) ;
break;
}
}
int T_1 F_32 ( void )
{
int V_60 = F_3 ( F_4 ( V_3 ) ) ;
int V_61 , V_62 , V_63 , V_64 , V_65 , V_66 , V_67 = 32 , V_68 = 1 ;
unsigned long V_69 ;
struct V_70 * V_71 , * V_72 ;
if ( V_60 == V_5 ) {
V_61 = V_73 ;
V_62 = V_74 ;
V_63 = V_75 ;
V_64 = V_76 ;
V_65 = V_77 ;
V_66 = V_78 ;
} else if ( V_60 == V_6 ) {
V_61 = V_79 ;
V_62 = V_80 ;
V_63 = V_81 ;
V_64 = V_82 ;
V_65 = V_83 ;
V_66 = V_84 ;
F_33 ( 19 , L_2 ) ;
F_33 ( 20 , L_3 ) ;
F_34 ( 19 ) ;
F_34 ( 20 ) ;
V_69 = F_35 ( V_85 ) ;
V_69 |= ( 1 << 0 ) ;
F_36 ( V_69 , V_85 ) ;
F_37 ( V_86 ,
F_38 ( V_86 ) ) ;
V_72 = F_39 ( NULL , L_4 ) ;
V_71 = F_39 ( NULL , L_5 ) ;
if ( ! F_40 ( V_71 ) && ! F_40 ( V_72 ) ) {
F_41 ( V_71 , V_72 ) ;
F_42 ( V_71 , F_43 ( V_72 ) ) ;
}
if ( ! F_40 ( V_71 ) )
F_44 ( V_71 ) ;
if ( ! F_40 ( V_72 ) )
F_44 ( V_72 ) ;
F_45 ( V_87 , F_38 ( V_87 ) ) ;
F_9 ( & V_88 ) ;
} else if ( V_60 == V_4 ) {
V_61 = V_89 ;
V_62 = V_90 ;
V_63 = V_91 ;
V_64 = V_92 ;
V_65 = V_93 ;
V_66 = V_94 ;
F_45 ( V_95 , F_38 ( V_95 ) ) ;
} else if ( ( V_60 == V_7 ) ||
( V_60 == V_8 ) ) {
V_61 = V_96 ;
V_63 = V_97 ;
V_65 = V_98 ;
V_68 = 0 ;
V_67 = 64 ;
F_16 ( V_99 , V_100 ) ;
F_16 ( V_101 , V_100 ) ;
} else if ( V_60 == V_9 ) {
V_61 = V_102 ;
V_63 = V_103 ;
V_65 = V_104 ;
V_68 = 0 ;
V_67 = 64 ;
F_16 ( V_105 , V_100 ) ;
F_16 ( V_106 , V_100 ) ;
F_16 ( V_107 , V_100 ) ;
F_45 ( V_87 , F_38 ( V_87 ) ) ;
} else
return 0 ;
F_16 ( V_63 , V_29 ) ;
F_16 ( V_61 , V_100 ) ;
F_16 ( V_65 , V_100 ) ;
F_46 (
V_108 ,
V_108 + 0x000400000 - 1 ,
V_109 ,
V_109 + 0x000400000 - 1 ,
V_110 ,
V_110 + 0x000010000 - 1 ,
V_61 , V_63 , 0 , 0 , 0 ) ;
if ( V_68 ) {
F_16 ( V_64 , V_29 ) ;
F_16 ( V_62 , V_100 ) ;
F_16 ( V_66 , V_100 ) ;
F_46 (
V_108 + 0x004000000 ,
V_108 + 0x004400000 - 1 ,
V_109 + 0x004000000 ,
V_109 + 0x004400000 - 1 ,
V_110 + 0x004000000 ,
V_110 + 0x004010000 - 1 ,
V_62 , V_64 , 0 , 0 , 1 ) ;
}
F_45 ( V_111 , F_38 ( V_111 ) ) ;
F_47 ( V_67 << 20 , 4 , V_112 ) ;
return 0 ;
}
