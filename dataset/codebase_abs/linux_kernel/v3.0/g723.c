static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = V_3 / ( V_4 * ( V_5 * 2 ) * 2 ) ;
F_2 ( V_1 , V_6 ,
F_3 ( V_5 ) |
F_4 ( V_2 ) ) ;
F_2 ( V_1 , V_7 ,
F_5 ( V_8 ) |
F_6 ( V_9 ) |
F_7 ( F_8 ( V_1 ) >> 16 ) ) ;
F_2 ( V_1 , V_10 ,
V_11 | V_12 |
F_9 ( 3 ) | F_10 ( V_13 ) ) ;
}
void F_11 ( struct V_1 * V_1 )
{
struct V_14 * V_15 =
& V_1 -> V_16 -> V_17 [ V_18 ] ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
F_2 ( V_1 , V_23 , V_24 ) ;
for ( V_20 = V_15 -> V_25 ; V_20 != NULL ; V_20 = V_20 -> V_26 ) {
if ( F_12 ( V_20 ) == NULL )
continue;
if ( F_12 ( V_20 ) == V_1 )
continue;
V_22 = F_12 ( V_20 ) ;
if ( ! V_22 -> V_27 )
continue;
F_13 ( V_20 ) ;
}
}
static int F_14 ( struct V_19 * V_20 ,
struct V_28 * V_29 )
{
return F_15 ( V_20 , F_16 ( V_29 ) ) ;
}
static int F_17 ( struct V_19 * V_20 )
{
return F_18 ( V_20 ) ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_12 ( V_20 ) ;
struct V_21 * V_22 ;
V_22 = F_20 ( sizeof( * V_22 ) , V_30 ) ;
if ( V_22 == NULL )
return - V_31 ;
F_21 ( & V_22 -> V_32 ) ;
V_22 -> V_1 = V_1 ;
V_20 -> V_33 -> V_34 = V_35 ;
F_12 ( V_20 ) = V_22 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_12 ( V_20 ) ;
F_12 ( V_20 ) = V_22 -> V_1 ;
F_23 ( V_22 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 , int V_36 )
{
struct V_21 * V_22 = F_12 ( V_20 ) ;
struct V_1 * V_1 = V_22 -> V_1 ;
int V_37 = 0 ;
F_25 ( & V_22 -> V_32 ) ;
switch ( V_36 ) {
case V_38 :
if ( V_22 -> V_27 == 0 ) {
if ( F_26 ( & V_1 -> V_39 ) == 1 )
F_27 ( V_1 , V_24 ) ;
V_22 -> V_27 = 1 ;
}
break;
case V_40 :
if ( V_22 -> V_27 ) {
if ( F_28 ( & V_1 -> V_39 ) == 0 )
F_29 ( V_1 , V_24 ) ;
V_22 -> V_27 = 0 ;
}
break;
default:
V_37 = - V_41 ;
}
F_30 ( & V_22 -> V_32 ) ;
return V_37 ;
}
static int F_31 ( struct V_19 * V_20 )
{
return 0 ;
}
static T_1 F_32 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_12 ( V_20 ) ;
struct V_1 * V_1 = V_22 -> V_1 ;
T_1 V_42 = F_33 ( V_1 , V_43 ) & 0x1f ;
return V_42 * V_44 ;
}
static int F_34 ( struct V_19 * V_20 , int V_45 ,
T_1 V_46 , void T_2 * V_47 ,
T_1 V_48 )
{
struct V_21 * V_22 = F_12 ( V_20 ) ;
struct V_1 * V_1 = V_22 -> V_1 ;
int V_49 , V_50 ;
for ( V_50 = 0 ; V_50 < ( V_48 / V_44 ) ; V_50 ++ ) {
int V_51 = ( V_46 / V_44 ) + V_50 ;
V_49 = F_35 ( V_1 , V_52 , 0 ,
V_22 -> V_53 ,
F_8 ( V_1 ) +
( V_51 * V_54 ) +
( V_20 -> V_55 * V_56 ) ,
V_56 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_36 ( V_47 + ( V_50 * V_56 ) ,
V_22 -> V_53 , V_56 ) ;
if ( V_49 )
return - V_57 ;
}
return 0 ;
}
static int F_37 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_48 = 1 ;
V_61 -> V_63 . integer . V_64 = 0 ;
V_61 -> V_63 . integer . V_65 = 15 ;
V_61 -> V_63 . integer . V_66 = 1 ;
return 0 ;
}
static int F_38 ( struct V_58 * V_59 ,
struct V_67 * V_63 )
{
struct V_1 * V_1 = F_39 ( V_59 ) ;
T_3 V_68 = V_63 -> V_69 . V_70 - 1 ;
V_63 -> V_63 . integer . V_63 [ 0 ] = F_40 ( V_1 , V_68 ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_59 ,
struct V_67 * V_63 )
{
struct V_1 * V_1 = F_39 ( V_59 ) ;
T_3 V_68 = V_63 -> V_69 . V_70 - 1 ;
T_3 V_71 ;
V_71 = F_40 ( V_1 , V_68 ) ;
if ( V_71 == V_63 -> V_63 . integer . V_63 [ 0 ] )
return 0 ;
F_42 ( V_1 , V_68 , V_63 -> V_63 . integer . V_63 [ 0 ] ) ;
return 1 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = V_1 -> V_72 ;
struct V_16 * V_74 ;
struct V_19 * V_20 ;
int V_37 ;
int V_50 ;
V_37 = F_44 ( V_73 , V_73 -> V_75 , 0 , 0 , V_1 -> V_76 ,
& V_74 ) ;
if ( V_37 < 0 )
return V_37 ;
F_45 ( V_74 , V_18 ,
& V_77 ) ;
F_46 ( V_74 ) = V_1 ;
V_74 -> V_78 = 0 ;
strcpy ( V_74 -> V_79 , V_73 -> V_80 ) ;
for ( V_50 = 0 , V_20 = V_74 -> V_17 [ V_18 ] . V_25 ;
V_20 ; V_20 = V_20 -> V_26 , V_50 ++ )
sprintf ( V_20 -> V_79 , L_1 , V_50 ) ;
V_37 = F_47 ( V_74 ,
V_81 ,
F_48 ( V_30 ) ,
V_82 , V_82 ) ;
if ( V_37 < 0 )
return V_37 ;
V_1 -> V_16 = V_74 ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
static struct V_83 V_84 = { NULL } ;
struct V_72 * V_73 ;
struct V_85 V_86 ;
char V_79 [ 32 ] ;
int V_37 ;
F_50 ( & V_1 -> V_39 , 0 ) ;
sprintf ( V_79 , L_2 , V_1 -> V_87 -> V_88 ) ;
V_37 = F_51 ( V_89 , V_79 , V_90 , 0 ,
& V_1 -> V_72 ) ;
if ( V_37 < 0 )
return V_37 ;
V_73 = V_1 -> V_72 ;
strcpy ( V_73 -> V_75 , V_91 ) ;
strcpy ( V_73 -> V_80 , L_3 ) ;
sprintf ( V_73 -> V_92 , L_4 , V_73 -> V_80 ,
F_52 ( V_1 -> V_93 ) , V_1 -> V_93 -> V_94 ) ;
F_53 ( V_73 , & V_1 -> V_93 -> V_95 ) ;
V_37 = F_54 ( V_73 , V_96 , V_1 , & V_84 ) ;
if ( V_37 < 0 )
goto V_97;
strcpy ( V_73 -> V_98 , L_5 ) ;
V_86 = V_99 ;
V_86 . V_48 = V_1 -> V_76 ;
V_37 = F_55 ( V_73 , F_56 ( & V_86 , V_1 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_43 ( V_1 ) ;
if ( V_37 < 0 )
goto V_97;
V_37 = F_57 ( V_73 ) ;
if ( V_37 < 0 )
goto V_97;
F_1 ( V_1 ) ;
F_58 ( & V_1 -> V_93 -> V_95 , L_6 , V_79 ) ;
return 0 ;
V_97:
F_59 ( V_73 ) ;
return V_37 ;
}
void F_60 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_10 , 0 ) ;
F_29 ( V_1 , V_24 ) ;
F_59 ( V_1 -> V_72 ) ;
}
