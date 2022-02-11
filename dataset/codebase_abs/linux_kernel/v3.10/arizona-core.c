int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 ) {
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
V_2 = F_3 ( V_1 -> V_8 ) ;
if ( V_2 != 0 )
goto V_9;
break;
}
V_2 = F_4 ( V_1 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
}
V_9:
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_6 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
F_7 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 ) {
F_4 ( V_1 -> V_10 , V_11 ,
V_12 , 0 ) ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
F_8 ( V_1 -> V_8 ) ;
break;
}
}
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static T_1 F_9 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
F_10 ( V_1 -> V_8 , L_1 ) ;
return V_15 ;
}
static T_1 F_11 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_10 , V_17 ,
& V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_2 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 & V_19 )
F_10 ( V_1 -> V_8 , L_3 ) ;
if ( V_16 & V_20 )
F_10 ( V_1 -> V_8 , L_4 ) ;
if ( V_16 & V_21 )
F_10 ( V_1 -> V_8 , L_5 ) ;
if ( V_16 & V_22 )
F_10 ( V_1 -> V_8 , L_6 ) ;
if ( V_16 & V_23 )
F_10 ( V_1 -> V_8 , L_7 ) ;
if ( V_16 & V_24 )
F_10 ( V_1 -> V_8 , L_8 ) ;
if ( V_16 & V_25 )
F_10 ( V_1 -> V_8 , L_9 ) ;
if ( V_16 & V_26 )
F_10 ( V_1 -> V_8 , L_10 ) ;
if ( V_16 & V_27 )
F_10 ( V_1 -> V_8 , L_11 ) ;
if ( V_16 & V_28 )
F_10 ( V_1 -> V_8 , L_12 ) ;
return V_15 ;
}
static T_1 F_13 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 [ 2 ] ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_10 , V_29 ,
& V_16 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_13 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 [ 0 ] & V_30 )
F_10 ( V_1 -> V_8 , L_14 ) ;
if ( V_16 [ 0 ] & V_31 )
F_10 ( V_1 -> V_8 , L_15 ) ;
if ( V_16 [ 0 ] & V_32 )
F_10 ( V_1 -> V_8 , L_16 ) ;
if ( V_16 [ 0 ] & V_33 )
F_10 ( V_1 -> V_8 , L_17 ) ;
if ( V_16 [ 0 ] & V_34 )
F_10 ( V_1 -> V_8 , L_18 ) ;
if ( V_16 [ 0 ] & V_35 )
F_10 ( V_1 -> V_8 , L_19 ) ;
if ( V_16 [ 0 ] & V_36 )
F_10 ( V_1 -> V_8 , L_20 ) ;
if ( V_16 [ 0 ] & V_37 )
F_10 ( V_1 -> V_8 , L_21 ) ;
if ( V_16 [ 0 ] & V_38 )
F_10 ( V_1 -> V_8 , L_22 ) ;
if ( V_16 [ 0 ] & V_39 )
F_10 ( V_1 -> V_8 , L_23 ) ;
if ( V_16 [ 1 ] & V_40 )
F_10 ( V_1 -> V_8 , L_24 ) ;
if ( V_16 [ 1 ] & V_41 )
F_10 ( V_1 -> V_8 , L_25 ) ;
if ( V_16 [ 1 ] & V_42 )
F_10 ( V_1 -> V_8 , L_26 ) ;
if ( V_16 [ 1 ] & V_43 )
F_10 ( V_1 -> V_8 , L_27 ) ;
if ( V_16 [ 1 ] & V_44 )
F_10 ( V_1 -> V_8 , L_28 ) ;
if ( V_16 [ 1 ] & V_45 )
F_10 ( V_1 -> V_8 , L_29 ) ;
if ( V_16 [ 1 ] & V_46 )
F_10 ( V_1 -> V_8 , L_30 ) ;
if ( V_16 [ 1 ] & V_47 )
F_10 ( V_1 -> V_8 , L_31 ) ;
if ( V_16 [ 1 ] & V_48 )
F_10 ( V_1 -> V_8 , L_32 ) ;
if ( V_16 [ 1 ] & V_49 )
F_10 ( V_1 -> V_8 , L_33 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_1 ,
int V_50 , unsigned int V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
unsigned int V_16 = 0 ;
int V_2 , V_54 ;
for ( V_54 = 0 ; V_54 < V_50 ; V_54 ++ ) {
V_2 = F_12 ( V_1 -> V_10 , V_51 , & V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_34 ,
V_51 , V_2 ) ;
continue;
}
if ( ( V_16 & V_52 ) == V_53 )
return 0 ;
F_16 ( 1 ) ;
}
F_10 ( V_1 -> V_8 , L_35 , V_51 , V_16 ) ;
return - V_55 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_15 ( V_1 , 5 , V_56 ,
V_57 , V_57 ) ;
if ( ! V_2 )
F_18 ( V_1 -> V_10 , V_58 ,
V_57 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_2 ;
}
static int F_20 ( struct V_1 * V_1 )
{
unsigned int V_59 , V_60 ;
int V_2 , V_61 ;
F_21 ( V_1 -> V_10 , true ) ;
V_2 = F_12 ( V_1 -> V_10 , V_62 , & V_59 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_36 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_10 , V_63 , & V_60 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_37 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_62 ,
V_64 | V_65 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_38 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_15 ( V_1 , 25 , V_56 ,
V_66 ,
V_66 ) ;
if ( V_2 != 0 ) {
V_2 = - V_55 ;
goto V_67;
}
V_2 = F_18 ( V_1 -> V_10 , V_63 , 0x0144 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_39 , V_2 ) ;
goto V_67;
}
V_2 = F_18 ( V_1 -> V_10 , V_68 ,
V_69 | V_70 | 160 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_40 ,
V_2 ) ;
goto V_71;
}
V_2 = F_15 ( V_1 , 5 , V_72 ,
V_73 , 0 ) ;
if ( V_2 != 0 ) {
F_18 ( V_1 -> V_10 , V_68 ,
V_74 ) ;
V_2 = - V_55 ;
}
V_71:
V_61 = F_18 ( V_1 -> V_10 , V_63 , V_60 ) ;
if ( V_61 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_41 ,
V_61 ) ;
}
V_67:
V_61 = F_18 ( V_1 -> V_10 , V_62 , V_59 ) ;
if ( V_61 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_42 ,
V_61 ) ;
}
F_21 ( V_1 -> V_10 , false ) ;
if ( V_2 != 0 )
return V_2 ;
else
return V_61 ;
}
static int F_22 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_23 ( V_8 ) ;
int V_2 ;
F_24 ( V_1 -> V_8 , L_43 ) ;
V_2 = F_25 ( V_1 -> V_76 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_44 , V_2 ) ;
return V_2 ;
}
F_26 ( V_1 -> V_10 , false ) ;
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_27 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_45 ,
V_2 ) ;
goto V_61;
}
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_46 ,
V_2 ) ;
goto V_61;
}
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
goto V_61;
}
break;
}
V_2 = F_28 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_47 ) ;
goto V_61;
}
return 0 ;
V_61:
F_26 ( V_1 -> V_10 , true ) ;
F_29 ( V_1 -> V_76 ) ;
return V_2 ;
}
static int F_30 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_23 ( V_8 ) ;
F_24 ( V_1 -> V_8 , L_48 ) ;
F_29 ( V_1 -> V_76 ) ;
F_26 ( V_1 -> V_10 , true ) ;
F_31 ( V_1 -> V_10 ) ;
return 0 ;
}
static int F_32 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_23 ( V_8 ) ;
F_24 ( V_1 -> V_8 , L_49 ) ;
F_33 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_23 ( V_8 ) ;
F_24 ( V_1 -> V_8 , L_50 ) ;
F_35 ( V_1 -> V_13 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_1 )
{
struct V_75 * V_8 = V_1 -> V_8 ;
const char * V_78 ;
unsigned int V_51 , V_16 ;
int (* F_37)( struct V_1 * ) = NULL ;
int V_2 , V_54 ;
F_38 ( V_1 -> V_8 , V_1 ) ;
F_39 ( & V_1 -> V_3 ) ;
if ( F_40 ( V_1 -> V_8 ) )
memcpy ( & V_1 -> V_5 , F_40 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
F_26 ( V_1 -> V_10 , true ) ;
switch ( V_1 -> type ) {
case V_77 :
case V_79 :
for ( V_54 = 0 ; V_54 < F_41 ( V_80 ) ; V_54 ++ )
V_1 -> V_81 [ V_54 ] . V_82
= V_80 [ V_54 ] ;
V_1 -> V_83 = F_41 ( V_80 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_51 ,
V_1 -> type ) ;
return - V_84 ;
}
V_2 = F_42 ( V_1 -> V_8 , - 1 , V_85 ,
F_41 ( V_85 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_52 , V_2 ) ;
return V_2 ;
}
V_2 = F_43 ( V_8 , V_1 -> V_83 ,
V_1 -> V_81 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_53 ,
V_2 ) ;
goto V_86;
}
V_1 -> V_76 = F_44 ( V_1 -> V_8 , L_54 ) ;
if ( F_45 ( V_1 -> V_76 ) ) {
V_2 = F_46 ( V_1 -> V_76 ) ;
F_10 ( V_8 , L_55 , V_2 ) ;
goto V_86;
}
if ( V_1 -> V_5 . V_87 ) {
V_2 = F_47 ( V_1 -> V_5 . V_87 ,
V_88 | V_89 ,
L_56 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_57 , V_2 ) ;
goto V_86;
}
}
V_2 = F_48 ( V_1 -> V_83 ,
V_1 -> V_81 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_58 ,
V_2 ) ;
goto V_86;
}
V_2 = F_25 ( V_1 -> V_76 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_44 , V_2 ) ;
goto V_90;
}
if ( V_1 -> V_5 . V_87 ) {
F_49 ( V_1 -> V_5 . V_87 , 1 ) ;
F_16 ( 1 ) ;
}
F_26 ( V_1 -> V_10 , false ) ;
V_2 = F_12 ( V_1 -> V_10 , V_91 , & V_51 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_59 , V_2 ) ;
goto V_92;
}
V_2 = F_12 ( V_1 -> V_10 , V_93 ,
& V_1 -> V_94 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_60 , V_2 ) ;
goto V_92;
}
V_1 -> V_94 &= V_95 ;
switch ( V_51 ) {
#ifdef F_50
case 0x5102 :
V_78 = L_61 ;
if ( V_1 -> type != V_77 ) {
F_10 ( V_1 -> V_8 , L_62 ,
V_1 -> type ) ;
V_1 -> type = V_77 ;
}
F_37 = F_27 ;
V_1 -> V_94 &= 0x7 ;
break;
#endif
#ifdef F_51
case 0x5110 :
V_78 = L_63 ;
if ( V_1 -> type != V_79 ) {
F_10 ( V_1 -> V_8 , L_64 ,
V_1 -> type ) ;
V_1 -> type = V_79 ;
}
F_37 = V_96 ;
break;
#endif
default:
F_10 ( V_1 -> V_8 , L_65 , V_51 ) ;
goto V_92;
}
F_52 ( V_8 , L_66 , V_78 , V_1 -> V_94 + 'A' ) ;
if ( ! V_1 -> V_5 . V_87 ) {
F_31 ( V_1 -> V_10 ) ;
V_2 = F_18 ( V_1 -> V_10 , V_91 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_67 , V_2 ) ;
goto V_92;
}
F_16 ( 1 ) ;
V_2 = F_28 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_68 , V_2 ) ;
goto V_92;
}
}
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_12 ( V_1 -> V_10 , 0x19 , & V_16 ) ;
if ( V_2 != 0 )
F_10 ( V_8 ,
L_69 ,
V_2 ) ;
else if ( V_16 & 0x01 )
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_70 , V_2 ) ;
goto V_92;
}
break;
}
if ( F_37 ) {
V_2 = F_37 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_45 ,
V_2 ) ;
goto V_92;
}
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_46 ,
V_2 ) ;
goto V_92;
}
break;
default:
break;
}
}
for ( V_54 = 0 ; V_54 < F_41 ( V_1 -> V_5 . V_97 ) ; V_54 ++ ) {
if ( ! V_1 -> V_5 . V_97 [ V_54 ] )
continue;
F_18 ( V_1 -> V_10 , V_98 + V_54 ,
V_1 -> V_5 . V_97 [ V_54 ] ) ;
}
F_53 ( V_1 -> V_8 , 100 ) ;
F_54 ( V_1 -> V_8 ) ;
F_55 ( V_1 -> V_8 ) ;
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_99 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_99 :
F_4 ( V_1 -> V_10 , V_11 ,
V_100 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_101 :
F_4 ( V_1 -> V_10 , V_11 ,
V_100 , 2 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_71 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_84 ;
goto V_92;
}
for ( V_54 = 0 ; V_54 < V_102 ; V_54 ++ ) {
if ( ! V_1 -> V_5 . V_103 [ V_54 ] . V_104 &&
! V_1 -> V_5 . V_103 [ V_54 ] . V_105 )
continue;
if ( ! V_1 -> V_5 . V_103 [ V_54 ] . V_104 )
V_1 -> V_5 . V_103 [ V_54 ] . V_104 = 2800 ;
V_16 = ( V_1 -> V_5 . V_103 [ V_54 ] . V_104 - 1500 ) / 100 ;
V_16 <<= V_106 ;
if ( V_1 -> V_5 . V_103 [ V_54 ] . V_107 )
V_16 |= V_108 ;
if ( V_1 -> V_5 . V_103 [ V_54 ] . V_109 )
V_16 |= V_110 ;
if ( V_1 -> V_5 . V_103 [ V_54 ] . V_111 )
V_16 |= V_112 ;
if ( V_1 -> V_5 . V_103 [ V_54 ] . V_105 )
V_16 |= V_113 ;
F_4 ( V_1 -> V_10 ,
V_114 + V_54 ,
V_115 |
V_110 |
V_113 |
V_112 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_116 ; V_54 ++ ) {
V_16 = V_1 -> V_5 . V_117 [ V_54 ]
<< V_118 ;
V_16 |= V_1 -> V_5 . V_119 [ V_54 ] << V_120 ;
F_4 ( V_1 -> V_10 ,
V_121 + ( V_54 * 8 ) ,
V_122 |
V_123 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_124 ; V_54 ++ ) {
if ( V_1 -> V_5 . V_125 [ V_54 ] )
V_16 = V_126 ;
else
V_16 = 0 ;
F_4 ( V_1 -> V_10 ,
V_127 + ( V_54 * 8 ) ,
V_126 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_128 ; V_54 ++ ) {
if ( V_1 -> V_5 . V_129 [ V_54 ] )
F_4 ( V_1 -> V_10 ,
V_130 + ( V_54 * 2 ) ,
V_131 |
V_132 ,
V_1 -> V_5 . V_129 [ V_54 ] ) ;
if ( V_1 -> V_5 . V_133 [ V_54 ] )
F_4 ( V_1 -> V_10 ,
V_134 + ( V_54 * 2 ) ,
V_135 ,
V_1 -> V_5 . V_133 [ V_54 ] ) ;
}
V_2 = F_56 ( V_1 ) ;
if ( V_2 != 0 )
goto V_92;
F_57 ( V_1 , V_136 , L_72 ,
F_9 , V_1 ) ;
F_57 ( V_1 , V_137 , L_73 ,
F_13 , V_1 ) ;
F_57 ( V_1 , V_138 , L_74 ,
F_11 , V_1 ) ;
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_42 ( V_1 -> V_8 , - 1 , V_139 ,
F_41 ( V_139 ) , NULL , 0 , NULL ) ;
break;
case V_79 :
V_2 = F_42 ( V_1 -> V_8 , - 1 , V_140 ,
F_41 ( V_140 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_75 , V_2 ) ;
goto V_141;
}
#ifdef F_58
F_29 ( V_1 -> V_76 ) ;
#endif
return 0 ;
V_141:
F_59 ( V_1 ) ;
V_92:
if ( V_1 -> V_5 . V_87 ) {
F_49 ( V_1 -> V_5 . V_87 , 0 ) ;
F_60 ( V_1 -> V_5 . V_87 ) ;
}
F_29 ( V_1 -> V_76 ) ;
V_90:
F_61 ( V_1 -> V_83 ,
V_1 -> V_81 ) ;
V_86:
F_62 ( V_8 ) ;
return V_2 ;
}
int F_63 ( struct V_1 * V_1 )
{
F_62 ( V_1 -> V_8 ) ;
F_64 ( V_1 , V_138 , V_1 ) ;
F_64 ( V_1 , V_137 , V_1 ) ;
F_64 ( V_1 , V_136 , V_1 ) ;
F_65 ( V_1 -> V_8 ) ;
F_59 ( V_1 ) ;
return 0 ;
}
