static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
int V_7 = 0 ;
T_1 V_8 ;
switch ( V_4 ) {
case V_9 :
V_7 = F_2 ( V_10 , NULL , 0 , & V_8 , 1 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ! ! ( V_8 & V_12 ) ;
break;
default:
V_7 = - V_13 ;
break;
}
return V_7 ;
}
static int F_3 ( union V_5 * V_6 , T_1 V_14 )
{
if ( V_15 . V_16 > 0x44 ) {
if ( V_14 & ( V_17 | V_18 ) )
V_6 -> V_11 = V_19 ;
else if ( V_14 & V_20 )
V_6 -> V_11 = V_21 ;
else if ( V_14 & V_22 )
V_6 -> V_11 = V_23 ;
else
V_6 -> V_11 = V_24 ;
} else {
if ( ! ( V_14 & V_12 ) )
V_6 -> V_11 = V_21 ;
else if ( V_14 & V_22 )
V_6 -> V_11 = V_23 ;
else
V_6 -> V_11 = V_19 ;
}
return 0 ;
}
static int F_4 ( union V_5 * V_6 )
{
T_1 V_14 ;
int V_7 ;
V_7 = F_2 ( V_25 , NULL , 0 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
switch ( V_14 ) {
case 0 :
V_6 -> V_11 = V_26 ;
break;
case V_27 :
V_6 -> V_11 = V_28 ;
break;
case V_29 :
V_6 -> V_11 = V_30 ;
break;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_6 -> V_11 = V_35 ;
break;
default:
V_7 = - V_36 ;
}
return V_7 ;
}
static int F_5 ( union V_5 * V_6 )
{
T_1 V_14 ;
int V_7 ;
V_14 = V_37 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
switch ( V_14 >> 4 ) {
case 1 :
V_6 -> V_39 = L_1 ;
break;
case 2 :
V_6 -> V_39 = L_2 ;
break;
default:
V_6 -> V_39 = L_3 ;
break;
}
return V_7 ;
}
static int F_6 ( union V_5 * V_6 )
{
T_1 V_14 ;
int V_7 ;
V_14 = V_37 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
switch ( V_14 & 0xf ) {
case 1 :
V_6 -> V_11 = V_40 ;
break;
case 2 :
V_6 -> V_11 = V_41 ;
break;
default:
V_6 -> V_11 = V_42 ;
break;
}
return V_7 ;
}
static int F_7 ( union V_5 * V_6 )
{
T_1 V_14 ;
union V_5 V_43 ;
int V_7 , V_44 ;
V_7 = F_6 ( & V_43 ) ;
if ( V_7 )
return V_7 ;
V_14 = V_37 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
V_44 = V_14 >> 4 ;
switch ( V_43 . V_11 ) {
case V_40 :
switch ( V_44 ) {
case 1 :
V_6 -> V_11 = 3000000 * .8 ;
break;
default:
return - V_36 ;
}
break;
case V_41 :
switch ( V_44 ) {
case 1 :
case 2 :
V_6 -> V_11 = 2800000 ;
break;
default:
return - V_36 ;
}
break;
default:
return - V_36 ;
}
return V_7 ;
}
static int F_8 ( union V_5 * V_6 )
{
T_1 V_45 ;
union V_5 V_46 ;
int V_7 ;
V_7 = F_2 ( V_47 , NULL , 0 , & V_45 , 1 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( & V_46 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = V_45 * ( V_46 . V_11 / 100 ) ;
return 0 ;
}
static int F_9 ( union V_5 * V_6 )
{
T_1 V_14 ;
union V_5 V_43 ;
int V_44 ;
int V_7 ;
V_7 = F_6 ( & V_43 ) ;
if ( V_7 )
return V_7 ;
V_14 = V_37 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
V_44 = V_14 >> 4 ;
switch ( V_43 . V_11 ) {
case V_40 :
switch ( V_44 ) {
case 1 :
V_6 -> V_11 = 6000000 ;
break;
default:
return - V_36 ;
}
break;
case V_41 :
switch ( V_44 ) {
case 1 :
V_6 -> V_11 = 6400000 ;
break;
case 2 :
V_6 -> V_11 = 6500000 ;
break;
default:
return - V_36 ;
}
break;
default:
return - V_36 ;
}
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
int V_7 = 0 ;
T_2 V_48 ;
T_1 V_14 ;
T_3 V_49 ;
V_7 = F_2 ( V_10 , NULL , 0 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_14 & ( V_50 | V_18 ) ) &&
V_4 != V_51 )
return - V_52 ;
switch ( V_4 ) {
case V_53 :
V_7 = F_3 ( V_6 , V_14 ) ;
if ( V_7 )
return V_7 ;
break;
case V_54 :
if ( V_14 & V_18 )
V_6 -> V_11 = V_55 ;
else if ( V_14 & V_17 )
V_6 -> V_11 = V_56 ;
else
V_6 -> V_11 = V_57 ;
break;
case V_51 :
V_6 -> V_11 = ! ! ( V_14 & ( V_50 |
V_18 ) ) ;
break;
case V_58 :
if ( V_14 & V_59 )
V_6 -> V_11 = V_60 ;
else {
V_7 = F_4 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
break;
case V_61 :
V_7 = F_5 ( V_6 ) ;
if ( V_7 )
return V_7 ;
break;
case V_62 :
V_7 = F_6 ( V_6 ) ;
if ( V_7 )
return V_7 ;
break;
case V_63 :
case V_64 :
V_7 = F_2 ( V_65 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_11 ( V_48 ) * 9760L / 32 ;
break;
case V_67 :
case V_68 :
V_7 = F_2 ( V_69 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_11 ( V_48 ) * 15625L / 120 ;
break;
case V_70 :
V_7 = F_2 ( V_47 , NULL , 0 , & V_14 , 1 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = V_14 ;
break;
case V_71 :
if ( V_14 & V_22 )
V_6 -> V_11 = V_72 ;
else if ( V_14 & V_73 )
V_6 -> V_11 = V_74 ;
else
V_6 -> V_11 = V_75 ;
break;
case V_76 :
V_7 = F_7 ( V_6 ) ;
if ( V_7 )
return V_7 ;
break;
case V_77 :
V_7 = F_8 ( V_6 ) ;
if ( V_7 )
return V_7 ;
break;
case V_78 :
V_7 = F_2 ( V_79 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_11 ( V_48 ) * 100 / 256 ;
break;
case V_80 :
V_7 = F_2 ( V_81 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( int ) F_11 ( V_48 ) * 100 / 256 ;
break;
case V_82 :
V_7 = F_2 ( V_83 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_11 ( V_48 ) * 6250 / 15 ;
break;
case V_84 :
V_7 = F_2 ( V_85 , NULL , 0 , ( void * ) & V_49 , 8 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_86 , L_4 , ( long long ) F_12 ( V_49 ) ) ;
V_6 -> V_39 = V_86 ;
break;
case V_87 :
V_7 = F_9 ( V_6 ) ;
if ( V_7 )
return V_7 ;
break;
default:
V_7 = - V_13 ;
break;
}
return V_7 ;
}
static T_4 F_13 ( struct V_88 * V_89 , struct V_90 * V_91 ,
struct V_92 * V_93 , char * V_94 , T_5 V_95 , T_6 V_96 )
{
T_1 V_14 ;
int V_7 ;
int V_97 ;
if ( V_95 >= V_98 )
return 0 ;
if ( V_95 + V_96 > V_98 )
V_96 = V_98 - V_95 ;
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ ) {
V_14 = V_99 + V_95 + V_97 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_94 [ V_97 ] , 1 ) ;
if ( V_7 ) {
F_14 ( L_5
L_6 ,
V_14 , V_7 ) ;
return - V_36 ;
}
}
return V_96 ;
}
static T_4 F_15 ( struct V_100 * V_101 ,
struct V_102 * V_93 , char * V_94 )
{
T_1 V_14 ;
T_4 V_7 ;
V_7 = F_2 ( V_25 , NULL , 0 , & V_14 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_94 , L_7 , V_14 ) ;
}
static int F_16 ( struct V_103 * V_104 ,
T_7 V_105 )
{
if ( F_17 ( V_106 . V_101 ) )
F_18 ( V_107 ) ;
else
F_19 ( V_107 ) ;
if ( F_17 ( V_108 . V_101 ) )
F_18 ( V_109 | V_110
| V_111 ) ;
else
F_19 ( V_109 | V_110
| V_111 ) ;
return 0 ;
}
static int T_8 F_20 ( struct V_103 * V_104 )
{
int V_7 ;
T_1 V_8 ;
if ( V_15 . V_16 < 0x44 ) {
F_21 ( V_112 L_8
L_9 , V_15 . V_16 ) ;
return - V_113 ;
}
V_7 = F_2 ( V_10 , NULL , 0 , & V_8 , 1 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_22 ( & V_104 -> V_101 , & V_106 ) ;
if ( V_7 )
return V_7 ;
if ( F_23 ( F_24 ( 0xd0 ) ) ) {
V_108 . V_114 = V_115 ;
V_108 . V_116 = F_25 ( V_115 ) ;
} else {
V_108 . V_114 = V_117 ;
V_108 . V_116 = F_25 ( V_117 ) ;
}
V_7 = F_22 ( & V_104 -> V_101 , & V_108 ) ;
if ( V_7 )
goto V_118;
V_7 = F_26 ( V_108 . V_101 , & V_119 ) ;
if ( V_7 )
goto V_120;
V_7 = F_27 ( V_108 . V_101 , & V_121 ) ;
if ( V_7 )
goto V_122;
if ( F_28 () ) {
F_29 ( V_106 . V_101 , true ) ;
F_29 ( V_108 . V_101 , true ) ;
}
return 0 ;
V_122:
F_30 ( V_108 . V_101 , & V_119 ) ;
V_120:
F_31 ( & V_108 ) ;
V_118:
F_31 ( & V_106 ) ;
return V_7 ;
}
static int T_9 F_32 ( struct V_103 * V_104 )
{
F_33 ( V_108 . V_101 , & V_121 ) ;
F_30 ( V_108 . V_101 , & V_119 ) ;
F_31 ( & V_108 ) ;
F_31 ( & V_106 ) ;
return 0 ;
}
