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
V_6 -> V_11 = 2800000 ;
break;
case 2 :
V_6 -> V_11 = 3100000 ;
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
static int F_9 ( struct V_1 * V_2 ,
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
V_6 -> V_11 = ( V_66 ) F_10 ( V_48 ) * 9760L / 32 ;
break;
case V_67 :
case V_68 :
V_7 = F_2 ( V_69 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_10 ( V_48 ) * 15625L / 120 ;
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
V_6 -> V_11 = ( V_66 ) F_10 ( V_48 ) * 100 / 256 ;
break;
case V_80 :
V_7 = F_2 ( V_81 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( int ) F_10 ( V_48 ) * 100 / 256 ;
break;
case V_82 :
V_7 = F_2 ( V_83 , NULL , 0 , ( void * ) & V_48 , 2 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_11 = ( V_66 ) F_10 ( V_48 ) * 6250 / 15 ;
break;
case V_84 :
V_7 = F_2 ( V_85 , NULL , 0 , ( void * ) & V_49 , 8 ) ;
if ( V_7 )
return V_7 ;
sprintf ( V_86 , L_4 , ( long long ) F_11 ( V_49 ) ) ;
V_6 -> V_39 = V_86 ;
break;
default:
V_7 = - V_13 ;
break;
}
return V_7 ;
}
static T_4 F_12 ( struct V_87 * V_88 , struct V_89 * V_90 ,
struct V_91 * V_92 , char * V_93 , T_5 V_94 , T_6 V_95 )
{
T_1 V_14 ;
int V_7 ;
int V_96 ;
if ( V_94 >= V_97 )
return 0 ;
if ( V_94 + V_95 > V_97 )
V_95 = V_97 - V_94 ;
for ( V_96 = 0 ; V_96 < V_95 ; V_96 ++ ) {
V_14 = V_98 + V_94 + V_96 ;
V_7 = F_2 ( V_38 , & V_14 , 1 , & V_93 [ V_96 ] , 1 ) ;
if ( V_7 ) {
F_13 ( L_5
L_6 ,
V_14 , V_7 ) ;
return - V_36 ;
}
}
return V_95 ;
}
static T_4 F_14 ( struct V_99 * V_100 ,
struct V_101 * V_92 , char * V_93 )
{
T_1 V_14 ;
T_4 V_7 ;
V_7 = F_2 ( V_25 , NULL , 0 , & V_14 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_93 , L_7 , V_14 ) ;
}
static int F_15 ( struct V_102 * V_103 ,
T_7 V_104 )
{
if ( F_16 ( V_105 . V_100 ) )
F_17 ( V_106 ) ;
else
F_18 ( V_106 ) ;
if ( F_16 ( V_107 . V_100 ) )
F_17 ( V_108 | V_109
| V_110 ) ;
else
F_18 ( V_108 | V_109
| V_110 ) ;
return 0 ;
}
static int T_8 F_19 ( struct V_102 * V_103 )
{
int V_7 ;
T_1 V_8 ;
if ( V_15 . V_16 < 0x44 ) {
F_20 ( V_111 L_8
L_9 , V_15 . V_16 ) ;
return - V_112 ;
}
V_7 = F_2 ( V_10 , NULL , 0 , & V_8 , 1 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_21 ( & V_103 -> V_100 , & V_105 ) ;
if ( V_7 )
return V_7 ;
if ( F_22 ( F_23 ( 0xd0 ) ) ) {
V_107 . V_113 = V_114 ;
V_107 . V_115 = F_24 ( V_114 ) ;
} else {
V_107 . V_113 = V_116 ;
V_107 . V_115 = F_24 ( V_116 ) ;
}
V_7 = F_21 ( & V_103 -> V_100 , & V_107 ) ;
if ( V_7 )
goto V_117;
V_7 = F_25 ( V_107 . V_100 , & V_118 ) ;
if ( V_7 )
goto V_119;
V_7 = F_26 ( V_107 . V_100 , & V_120 ) ;
if ( V_7 )
goto V_121;
if ( F_27 () ) {
F_28 ( V_105 . V_100 , true ) ;
F_28 ( V_107 . V_100 , true ) ;
}
return 0 ;
V_121:
F_29 ( V_107 . V_100 , & V_118 ) ;
V_119:
F_30 ( & V_107 ) ;
V_117:
F_30 ( & V_105 ) ;
return V_7 ;
}
static int T_9 F_31 ( struct V_102 * V_103 )
{
F_32 ( V_107 . V_100 , & V_120 ) ;
F_29 ( V_107 . V_100 , & V_118 ) ;
F_30 ( & V_107 ) ;
F_30 ( & V_105 ) ;
return 0 ;
}
