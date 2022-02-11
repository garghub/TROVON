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
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_56 = V_57 | V_58 ;
V_2 -> V_59 = V_60 | V_61 |
V_62 ;
V_2 -> V_63 = V_64 ;
switch ( V_2 -> V_45 ) {
case 100000 :
V_2 -> V_59 |= V_65 ;
break;
case 3400000 :
V_2 -> V_59 |= V_66 ;
break;
default:
V_2 -> V_59 |= V_67 ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_56 = V_68 | V_58 ;
V_2 -> V_69 = V_70 |
V_62 | V_71 ;
V_2 -> V_63 = V_72 ;
switch ( V_2 -> V_45 ) {
case 100000 :
V_2 -> V_69 |= V_65 ;
break;
case 3400000 :
V_2 -> V_69 |= V_66 ;
break;
default:
V_2 -> V_69 |= V_67 ;
}
}
static int F_15 ( struct V_1 * V_73 , bool V_74 )
{
if ( F_16 ( V_73 -> V_3 ) )
return F_17 ( V_73 -> V_3 ) ;
if ( V_74 )
return F_18 ( V_73 -> V_3 ) ;
F_19 ( V_73 -> V_3 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_29 )
{
T_1 V_75 , V_35 , V_36 ;
V_75 = F_21 ( V_2 ) ;
V_35 = ( ( V_75 >> 16 ) & 0xff ) + 1 ;
V_36 = ( ( V_75 >> 8 ) & 0xff ) + 1 ;
if ( ! V_2 -> V_35 ) {
V_2 -> V_35 = V_35 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_33 . V_34 = V_29 ;
} else if ( V_35 >= 2 ) {
V_2 -> V_35 = F_22 ( T_1 , V_2 -> V_35 ,
V_35 ) ;
V_2 -> V_36 = F_22 ( T_1 , V_2 -> V_36 ,
V_36 ) ;
}
}
static int F_23 ( struct V_4 * V_5 )
{
struct V_76 * V_77 = F_24 ( & V_5 -> V_2 ) ;
struct V_78 * V_79 ;
struct V_1 * V_2 ;
T_1 V_80 , V_81 = 0 ;
struct V_82 * V_83 ;
int V_84 , V_85 , V_86 ;
const int V_87 [] = { 0 , 100000 , 400000 , 1000000 , 3400000 } ;
V_85 = F_25 ( V_5 , 0 ) ;
if ( V_85 < 0 )
return V_85 ;
V_2 = F_26 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_83 = F_27 ( V_5 , V_90 , 0 ) ;
V_2 -> V_91 = F_28 ( & V_5 -> V_2 , V_83 ) ;
if ( F_16 ( V_2 -> V_91 ) )
return F_17 ( V_2 -> V_91 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_85 = V_85 ;
F_29 ( V_5 , V_2 ) ;
V_2 -> V_92 = F_30 ( & V_5 -> V_2 , NULL ) ;
if ( F_16 ( V_2 -> V_92 ) ) {
if ( F_17 ( V_2 -> V_92 ) == - V_93 )
return - V_93 ;
} else {
F_31 ( V_2 -> V_92 ) ;
}
if ( V_77 ) {
V_2 -> V_45 = V_77 -> V_94 ;
} else {
F_32 ( & V_5 -> V_2 , L_6 ,
& V_81 ) ;
F_32 ( & V_5 -> V_2 , L_7 ,
& V_2 -> V_95 ) ;
F_32 ( & V_5 -> V_2 , L_8 ,
& V_2 -> V_96 ) ;
F_32 ( & V_5 -> V_2 , L_9 ,
& V_2 -> V_45 ) ;
}
V_80 = F_33 ( & V_5 -> V_2 ) ;
for ( V_84 = 1 ; V_84 < F_34 ( V_87 ) ; V_84 ++ ) {
if ( V_80 < V_87 [ V_84 ] )
break;
}
V_80 = V_87 [ V_84 - 1 ] ;
if ( V_80 && V_2 -> V_45 )
V_2 -> V_45 = F_35 ( V_2 -> V_45 , V_80 ) ;
else if ( V_80 || V_2 -> V_45 )
V_2 -> V_45 = F_36 ( V_2 -> V_45 , V_80 ) ;
else
V_2 -> V_45 = 400000 ;
if ( F_37 ( & V_5 -> V_2 ) )
F_9 ( V_5 ) ;
if ( V_2 -> V_45 != 100000 && V_2 -> V_45 != 400000
&& V_2 -> V_45 != 1000000 && V_2 -> V_45 != 3400000 ) {
F_38 ( & V_5 -> V_2 ,
L_10 ,
V_2 -> V_45 ) ;
V_86 = - V_97 ;
goto V_98;
}
V_86 = F_39 ( V_2 ) ;
if ( V_86 )
goto V_98;
if ( F_40 ( & V_5 -> V_2 ) )
F_14 ( V_2 ) ;
else
F_13 ( V_2 ) ;
V_2 -> V_3 = F_41 ( & V_5 -> V_2 , NULL ) ;
if ( ! F_15 ( V_2 , true ) ) {
V_2 -> V_99 = F_1 ;
if ( ! V_2 -> V_46 && V_81 )
V_2 -> V_46 = F_42 (
( V_100 ) V_2 -> V_99 ( V_2 ) * V_81 + 500000 ,
1000000 ) ;
}
F_20 ( V_2 , V_5 -> V_29 ) ;
V_79 = & V_2 -> V_33 ;
V_79 -> V_101 = V_102 ;
V_79 -> V_103 = V_104 ;
F_43 ( & V_79 -> V_2 , F_44 ( & V_5 -> V_2 ) ) ;
V_79 -> V_2 . V_105 = V_5 -> V_2 . V_105 ;
if ( V_2 -> V_55 ) {
F_45 ( & V_5 -> V_2 ) ;
} else {
F_46 ( & V_5 -> V_2 , 1000 ) ;
F_47 ( & V_5 -> V_2 ) ;
F_48 ( & V_5 -> V_2 ) ;
F_49 ( & V_5 -> V_2 ) ;
}
if ( V_2 -> V_63 == V_72 )
V_86 = F_50 ( V_2 ) ;
else
V_86 = F_51 ( V_2 ) ;
if ( V_86 )
goto V_106;
return V_86 ;
V_106:
if ( ! V_2 -> V_55 )
F_52 ( & V_5 -> V_2 ) ;
V_98:
if ( ! F_53 ( V_2 -> V_92 ) )
F_54 ( V_2 -> V_92 ) ;
return V_86 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_56 ( & V_5 -> V_2 ) ;
F_57 ( & V_2 -> V_33 ) ;
V_2 -> V_107 ( V_2 ) ;
F_58 ( & V_5 -> V_2 ) ;
F_59 ( & V_5 -> V_2 ) ;
if ( ! V_2 -> V_55 )
F_52 ( & V_5 -> V_2 ) ;
if ( ! F_53 ( V_2 -> V_92 ) )
F_54 ( V_2 -> V_92 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_108 * V_2 )
{
return F_62 ( V_2 ) ;
}
static void F_63 ( struct V_108 * V_2 )
{
if ( V_2 -> V_109 . V_110 )
F_64 ( V_2 ) ;
}
static int F_65 ( struct V_108 * V_2 )
{
struct V_4 * V_5 = F_66 ( V_2 ) ;
struct V_1 * V_73 = F_10 ( V_5 ) ;
V_73 -> V_107 ( V_73 ) ;
F_15 ( V_73 , false ) ;
return 0 ;
}
static int F_67 ( struct V_108 * V_2 )
{
struct V_4 * V_5 = F_66 ( V_2 ) ;
struct V_1 * V_73 = F_10 ( V_5 ) ;
F_15 ( V_73 , true ) ;
V_73 -> V_111 ( V_73 ) ;
return 0 ;
}
static int F_68 ( struct V_108 * V_2 )
{
F_69 ( V_2 ) ;
return F_65 ( V_2 ) ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_112 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_112 ) ;
}
