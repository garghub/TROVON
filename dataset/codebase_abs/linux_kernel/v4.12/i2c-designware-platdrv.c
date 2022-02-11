static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static void F_3 ( struct V_4 * V_5 , char V_6 [] ,
T_2 * V_7 , T_2 * V_8 , T_1 * V_9 )
{
struct V_10 V_11 = { V_12 } ;
T_3 V_13 = F_4 ( & V_5 -> V_2 ) ;
union V_14 * V_15 ;
if ( F_5 ( V_16 ) )
return;
if ( F_6 ( F_7 ( V_13 , V_6 , NULL , & V_11 ) ) )
return;
V_15 = (union V_14 * ) V_11 . V_17 ;
if ( V_15 -> type == V_18 && V_15 -> V_19 . V_20 == 3 ) {
const union V_14 * V_21 = V_15 -> V_19 . V_22 ;
* V_7 = ( T_2 ) V_21 [ 0 ] . integer . V_23 ;
* V_8 = ( T_2 ) V_21 [ 1 ] . integer . V_23 ;
* V_9 = ( T_1 ) V_21 [ 2 ] . integer . V_23 ;
}
F_8 ( V_11 . V_17 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
T_1 V_24 = 0 , V_25 = 0 , V_26 = 0 , V_27 = 0 ;
T_3 V_13 = F_4 ( & V_5 -> V_2 ) ;
const struct V_28 * V_29 ;
struct V_30 * V_31 ;
const char * V_32 ;
V_2 -> V_33 . V_34 = - 1 ;
V_2 -> V_35 = 32 ;
V_2 -> V_36 = 32 ;
F_3 ( V_5 , L_1 , & V_2 -> V_37 , & V_2 -> V_38 , & V_24 ) ;
F_3 ( V_5 , L_2 , & V_2 -> V_39 , & V_2 -> V_40 , & V_25 ) ;
F_3 ( V_5 , L_3 , & V_2 -> V_41 , & V_2 -> V_42 , & V_26 ) ;
F_3 ( V_5 , L_4 , & V_2 -> V_43 , & V_2 -> V_44 , & V_27 ) ;
switch ( V_2 -> V_45 ) {
case 100000 :
V_2 -> V_46 = V_24 ;
break;
case 1000000 :
V_2 -> V_46 = V_25 ;
break;
case 3400000 :
V_2 -> V_46 = V_26 ;
break;
case 400000 :
default:
V_2 -> V_46 = V_27 ;
break;
}
V_29 = F_11 ( V_5 -> V_2 . V_47 -> V_48 , & V_5 -> V_2 ) ;
if ( V_29 && V_29 -> V_49 )
V_2 -> V_50 |= ( T_1 ) V_29 -> V_49 ;
if ( F_12 ( V_13 , & V_31 ) )
return - V_51 ;
V_32 = V_31 -> V_52 . V_53 ;
if ( ( V_2 -> V_50 & V_54 ) && ! strcmp ( V_32 , L_5 ) )
V_2 -> V_55 = true ;
return 0 ;
}
static inline int F_9 ( struct V_4 * V_5 )
{
return - V_51 ;
}
static int F_13 ( struct V_1 * V_56 , bool V_57 )
{
if ( F_14 ( V_56 -> V_3 ) )
return F_15 ( V_56 -> V_3 ) ;
if ( V_57 )
return F_16 ( V_56 -> V_3 ) ;
F_17 ( V_56 -> V_3 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_29 )
{
T_1 V_58 , V_35 , V_36 ;
V_58 = F_19 ( V_2 ) ;
V_35 = ( ( V_58 >> 16 ) & 0xff ) + 1 ;
V_36 = ( ( V_58 >> 8 ) & 0xff ) + 1 ;
if ( ! V_2 -> V_35 ) {
V_2 -> V_35 = V_35 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_33 . V_34 = V_29 ;
} else if ( V_35 >= 2 ) {
V_2 -> V_35 = F_20 ( T_1 , V_2 -> V_35 ,
V_35 ) ;
V_2 -> V_36 = F_20 ( T_1 , V_2 -> V_36 ,
V_36 ) ;
}
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = F_22 ( & V_5 -> V_2 ) ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_65 , V_66 ;
T_1 V_67 , V_68 = 0 ;
V_65 = F_23 ( V_5 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
V_2 = F_24 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_64 = F_25 ( V_5 , V_71 , 0 ) ;
V_2 -> V_72 = F_26 ( & V_5 -> V_2 , V_64 ) ;
if ( F_14 ( V_2 -> V_72 ) )
return F_15 ( V_2 -> V_72 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_65 = V_65 ;
F_27 ( V_5 , V_2 ) ;
V_2 -> V_73 = F_28 ( & V_5 -> V_2 , NULL ) ;
if ( F_14 ( V_2 -> V_73 ) ) {
if ( F_15 ( V_2 -> V_73 ) == - V_74 )
return - V_74 ;
} else {
F_29 ( V_2 -> V_73 ) ;
}
if ( V_60 ) {
V_2 -> V_45 = V_60 -> V_75 ;
} else {
F_30 ( & V_5 -> V_2 , L_6 ,
& V_68 ) ;
F_30 ( & V_5 -> V_2 , L_7 ,
& V_2 -> V_76 ) ;
F_30 ( & V_5 -> V_2 , L_8 ,
& V_2 -> V_77 ) ;
F_30 ( & V_5 -> V_2 , L_9 ,
& V_2 -> V_45 ) ;
}
V_67 = F_31 ( & V_5 -> V_2 ) ;
if ( V_67 && V_2 -> V_45 )
V_2 -> V_45 = F_32 ( V_2 -> V_45 , V_67 ) ;
else if ( V_67 || V_2 -> V_45 )
V_2 -> V_45 = F_33 ( V_2 -> V_45 , V_67 ) ;
else
V_2 -> V_45 = 400000 ;
if ( F_34 ( & V_5 -> V_2 ) )
F_9 ( V_5 ) ;
if ( V_2 -> V_45 != 100000 && V_2 -> V_45 != 400000
&& V_2 -> V_45 != 1000000 && V_2 -> V_45 != 3400000 ) {
F_35 ( & V_5 -> V_2 ,
L_10 ) ;
V_66 = - V_78 ;
goto V_79;
}
V_66 = F_36 ( V_2 ) ;
if ( V_66 )
goto V_79;
V_2 -> V_80 = V_81 | V_82 ;
V_2 -> V_83 = V_84 | V_85 |
V_86 ;
switch ( V_2 -> V_45 ) {
case 100000 :
V_2 -> V_83 |= V_87 ;
break;
case 3400000 :
V_2 -> V_83 |= V_88 ;
break;
default:
V_2 -> V_83 |= V_89 ;
}
V_2 -> V_3 = F_37 ( & V_5 -> V_2 , NULL ) ;
if ( ! F_13 ( V_2 , true ) ) {
V_2 -> V_90 = F_1 ;
if ( ! V_2 -> V_46 && V_68 )
V_2 -> V_46 = F_38 (
( V_91 ) V_2 -> V_90 ( V_2 ) * V_68 + 500000 ,
1000000 ) ;
}
F_18 ( V_2 , V_5 -> V_29 ) ;
V_62 = & V_2 -> V_33 ;
V_62 -> V_92 = V_93 ;
V_62 -> V_94 = V_95 ;
F_39 ( & V_62 -> V_2 , F_40 ( & V_5 -> V_2 ) ) ;
V_62 -> V_2 . V_96 = V_5 -> V_2 . V_96 ;
if ( V_2 -> V_55 ) {
F_41 ( & V_5 -> V_2 ) ;
} else {
F_42 ( & V_5 -> V_2 , 1000 ) ;
F_43 ( & V_5 -> V_2 ) ;
F_44 ( & V_5 -> V_2 ) ;
F_45 ( & V_5 -> V_2 ) ;
}
V_66 = F_46 ( V_2 ) ;
if ( V_66 )
goto V_97;
return V_66 ;
V_97:
if ( ! V_2 -> V_55 )
F_47 ( & V_5 -> V_2 ) ;
V_79:
if ( ! F_48 ( V_2 -> V_73 ) )
F_49 ( V_2 -> V_73 ) ;
return V_66 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_51 ( & V_5 -> V_2 ) ;
F_52 ( & V_2 -> V_33 ) ;
F_53 ( V_2 ) ;
F_54 ( & V_5 -> V_2 ) ;
F_55 ( & V_5 -> V_2 ) ;
if ( ! V_2 -> V_55 )
F_47 ( & V_5 -> V_2 ) ;
if ( ! F_48 ( V_2 -> V_73 ) )
F_49 ( V_2 -> V_73 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_98 * V_2 )
{
return F_58 ( V_2 ) ;
}
static void F_59 ( struct V_98 * V_2 )
{
if ( V_2 -> V_99 . V_100 )
F_60 ( V_2 ) ;
}
static int F_61 ( struct V_98 * V_2 )
{
struct V_4 * V_5 = F_62 ( V_2 ) ;
struct V_1 * V_56 = F_10 ( V_5 ) ;
F_53 ( V_56 ) ;
F_13 ( V_56 , false ) ;
return 0 ;
}
static int F_63 ( struct V_98 * V_2 )
{
struct V_4 * V_5 = F_62 ( V_2 ) ;
struct V_1 * V_56 = F_10 ( V_5 ) ;
F_13 ( V_56 , true ) ;
F_64 ( V_56 ) ;
return 0 ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_101 ) ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_101 ) ;
}
