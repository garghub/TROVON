static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = ( V_1 -> V_3 * 1000000 )
/ ( V_4 * ( V_5 * 2 ) * 2 ) ;
F_2 ( V_1 , V_6 ,
F_3 ( V_5 )
| F_4 ( V_2 ) ) ;
F_2 ( V_1 , V_7 ,
F_5 ( 1 )
| F_6 ( V_8 )
| F_7 ( F_8 ( V_1 ) >> 16 ) ) ;
F_2 ( V_1 , V_9 ,
V_10
| V_11
| F_9 ( 3 )
| F_10 ( V_12 ) ) ;
}
void F_11 ( struct V_1 * V_1 )
{
struct V_13 * V_14 =
& V_1 -> V_15 -> V_16 [ V_17 ] ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
for ( V_19 = V_14 -> V_22 ; V_19 != NULL ; V_19 = V_19 -> V_23 ) {
if ( F_12 ( V_19 ) == NULL )
continue;
if ( F_12 ( V_19 ) == V_1 )
continue;
V_21 = F_12 ( V_19 ) ;
if ( ! V_21 -> V_24 )
continue;
F_13 ( V_19 ) ;
}
}
static int F_14 ( struct V_18 * V_19 ,
struct V_25 * V_26 )
{
return F_15 ( V_19 , F_16 ( V_26 ) ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
return F_18 ( V_19 ) ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_12 ( V_19 ) ;
struct V_20 * V_21 ;
V_21 = F_20 ( sizeof( * V_21 ) , V_27 ) ;
if ( V_21 == NULL )
goto V_28;
V_21 -> V_29 = F_21 ( V_1 -> V_30 ,
V_31 ,
& V_21 -> V_32 ) ;
if ( V_21 -> V_29 == NULL )
goto V_28;
F_22 ( & V_21 -> V_33 ) ;
V_21 -> V_1 = V_1 ;
V_19 -> V_34 -> V_35 = V_36 ;
F_12 ( V_19 ) = V_21 ;
return 0 ;
V_28:
F_23 ( V_21 ) ;
return - V_37 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
F_12 ( V_19 ) = V_21 -> V_1 ;
F_25 ( V_21 -> V_1 -> V_30 , V_31 ,
V_21 -> V_29 , V_21 -> V_32 ) ;
F_23 ( V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , int V_38 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_39 = 0 ;
F_27 ( & V_21 -> V_33 ) ;
switch ( V_38 ) {
case V_40 :
if ( V_21 -> V_24 == 0 ) {
if ( F_28 ( & V_1 -> V_41 ) == 1 )
F_29 ( V_1 , V_42 ) ;
V_21 -> V_24 = 1 ;
}
break;
case V_43 :
if ( V_21 -> V_24 ) {
if ( F_30 ( & V_1 -> V_41 ) == 0 )
F_31 ( V_1 , V_42 ) ;
V_21 -> V_24 = 0 ;
}
break;
default:
V_39 = - V_44 ;
}
F_32 ( & V_21 -> V_33 ) ;
return V_39 ;
}
static int F_33 ( struct V_18 * V_19 )
{
return 0 ;
}
static T_1 F_34 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_45 = F_35 ( V_1 , V_46 ) & 0x1f ;
return V_45 * V_47 ;
}
static int F_36 ( struct V_18 * V_19 , int V_48 ,
T_1 V_49 , void T_2 * V_50 ,
T_1 V_51 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_52 , V_53 ;
for ( V_53 = 0 ; V_53 < ( V_51 / V_47 ) ; V_53 ++ ) {
int V_54 = ( V_49 / V_47 ) + V_53 ;
V_52 = F_37 ( V_1 , 0 , V_21 -> V_32 ,
F_8 ( V_1 ) +
( V_54 * V_55 ) +
( V_19 -> V_56 * V_31 ) ,
V_31 , 0 , 0 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_38 ( V_50 + ( V_53 * V_31 ) ,
V_21 -> V_29 , V_31 ) ;
if ( V_52 )
return - V_57 ;
}
return 0 ;
}
static int F_39 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_51 = 1 ;
V_61 -> V_63 . integer . V_64 = 0 ;
V_61 -> V_63 . integer . V_65 = 15 ;
V_61 -> V_63 . integer . V_66 = 1 ;
return 0 ;
}
static int F_40 ( struct V_58 * V_59 ,
struct V_67 * V_63 )
{
struct V_1 * V_1 = F_41 ( V_59 ) ;
T_3 V_68 = V_63 -> V_69 . V_70 - 1 ;
V_63 -> V_63 . integer . V_63 [ 0 ] = F_42 ( V_1 , V_68 ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_59 ,
struct V_67 * V_63 )
{
struct V_1 * V_1 = F_41 ( V_59 ) ;
T_3 V_68 = V_63 -> V_69 . V_70 - 1 ;
T_3 V_71 ;
V_71 = F_42 ( V_1 , V_68 ) ;
if ( V_71 == V_63 -> V_63 . integer . V_63 [ 0 ] )
return 0 ;
F_44 ( V_1 , V_68 , V_63 -> V_63 . integer . V_63 [ 0 ] ) ;
return 1 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = V_1 -> V_72 ;
struct V_15 * V_74 ;
struct V_18 * V_19 ;
int V_39 ;
int V_53 ;
V_39 = F_46 ( V_73 , V_73 -> V_75 , 0 , 0 , V_1 -> V_76 ,
& V_74 ) ;
if ( V_39 < 0 )
return V_39 ;
F_47 ( V_74 , V_17 ,
& V_77 ) ;
F_48 ( V_74 ) = V_1 ;
V_74 -> V_78 = 0 ;
strcpy ( V_74 -> V_79 , V_73 -> V_80 ) ;
for ( V_53 = 0 , V_19 = V_74 -> V_16 [ V_17 ] . V_22 ;
V_19 ; V_19 = V_19 -> V_23 , V_53 ++ )
sprintf ( V_19 -> V_79 , L_1 , V_53 ) ;
V_39 = F_49 ( V_74 ,
V_81 ,
F_50 ( V_27 ) ,
V_82 , V_82 ) ;
if ( V_39 < 0 )
return V_39 ;
V_1 -> V_15 = V_74 ;
return 0 ;
}
int F_51 ( struct V_1 * V_1 )
{
static struct V_83 V_84 = { NULL } ;
struct V_72 * V_73 ;
struct V_85 V_86 ;
char V_79 [ 32 ] ;
int V_39 ;
F_52 ( & V_1 -> V_41 , 0 ) ;
sprintf ( V_79 , L_2 , V_1 -> V_87 -> V_88 ) ;
V_39 = F_53 ( & V_1 -> V_30 -> V_89 ,
V_90 , V_79 , V_91 , 0 ,
& V_1 -> V_72 ) ;
if ( V_39 < 0 )
return V_39 ;
V_73 = V_1 -> V_72 ;
strcpy ( V_73 -> V_75 , V_92 ) ;
strcpy ( V_73 -> V_80 , L_3 ) ;
sprintf ( V_73 -> V_93 , L_4 , V_73 -> V_80 ,
F_54 ( V_1 -> V_30 ) , V_1 -> V_30 -> V_94 ) ;
V_39 = F_55 ( V_73 , V_95 , V_1 , & V_84 ) ;
if ( V_39 < 0 )
goto V_96;
strcpy ( V_73 -> V_97 , L_5 ) ;
V_86 = V_98 ;
V_86 . V_51 = V_1 -> V_76 ;
V_39 = F_56 ( V_73 , F_57 ( & V_86 , V_1 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_45 ( V_1 ) ;
if ( V_39 < 0 )
goto V_96;
V_39 = F_58 ( V_73 ) ;
if ( V_39 < 0 )
goto V_96;
F_1 ( V_1 ) ;
F_59 ( & V_1 -> V_30 -> V_89 , L_6 , V_79 ) ;
return 0 ;
V_96:
F_60 ( V_73 ) ;
return V_39 ;
}
void F_61 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_72 )
return;
F_2 ( V_1 , V_9 , 0 ) ;
F_31 ( V_1 , V_42 ) ;
F_60 ( V_1 -> V_72 ) ;
V_1 -> V_72 = NULL ;
}
