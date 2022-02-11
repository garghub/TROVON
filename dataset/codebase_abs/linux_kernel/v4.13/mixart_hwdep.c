static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 ,
T_1 V_5 , unsigned long V_6 )
{
unsigned long V_7 = V_8 + ( V_6 * V_9 / 100 ) ;
T_1 V_10 ;
do {
F_2 () ;
V_10 = F_3 ( F_4 ( V_2 , V_3 ) ) ;
if( V_4 ) {
if( V_10 == V_5 ) return 0 ;
}
else {
if( V_10 != V_5 ) return 0 ;
}
} while ( F_5 ( V_7 , V_8 ) );
return - V_11 ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
char V_14 [ 4 ] = { 0x7f , 'E' , 'L' , 'F' } ;
struct V_15 * V_16 ;
int V_17 ;
V_16 = (struct V_15 * ) V_13 -> V_18 ;
for( V_17 = 0 ; V_17 < 4 ; V_17 ++ )
if ( V_14 [ V_17 ] != V_16 -> V_19 [ V_17 ] )
return - V_20 ;
if( V_16 -> V_21 != 0 ) {
struct V_22 V_23 ;
for( V_17 = 0 ; V_17 < F_7 ( V_16 -> V_24 ) ; V_17 ++ ) {
T_1 V_25 = F_8 ( V_16 -> V_21 ) + ( T_1 ) ( V_17 * F_7 ( V_16 -> V_26 ) ) ;
memcpy ( & V_23 , V_13 -> V_18 + V_25 , sizeof( V_23 ) ) ;
if( V_23 . V_27 != 0 ) {
if( V_23 . V_28 != 0 ) {
F_9 ( F_4 ( V_2 , F_8 ( V_23 . V_29 ) ) ,
V_13 -> V_18 + F_8 ( V_23 . V_30 ) ,
F_8 ( V_23 . V_28 ) ) ;
}
}
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_31 ;
int V_32 ;
struct V_33 V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_36 = F_11 ( sizeof( * V_36 ) , V_41 ) ;
V_38 = F_11 ( sizeof( * V_38 ) , V_41 ) ;
V_40 = F_11 ( sizeof( * V_40 ) , V_41 ) ;
if ( ! V_36 || ! V_38 || ! V_40 ) {
V_32 = - V_42 ;
goto V_43;
}
V_38 -> V_44 = V_45 ;
V_38 -> V_46 = V_47 ;
V_38 -> V_48 = V_49 ;
V_34 . V_50 = V_51 ;
V_34 . V_52 = (struct V_53 ) { 0 , 0 } ;
V_34 . V_18 = NULL ;
V_34 . V_54 = 0 ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( * V_36 ) , V_36 ) ;
if( ( V_32 < 0 ) || ( V_36 -> V_55 ) || ( V_36 -> V_56 > V_57 ) ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_1 ) ;
V_32 = - V_20 ;
goto V_43;
}
for( V_31 = 0 ; V_31 < V_36 -> V_56 ; V_31 ++ ) {
struct V_60 * V_61 ;
if( V_31 < V_62 ) {
V_61 = & V_2 -> V_63 [ V_31 / 2 ] -> V_64 ;
} else {
V_61 = & V_2 -> V_63 [ ( V_31 - V_62 ) / 2 ] -> V_65 ;
}
if( V_31 & 1 ) {
V_61 -> V_66 = V_36 -> V_52 [ V_31 ] ;
} else {
V_61 -> V_67 = V_36 -> V_52 [ V_31 ] ;
}
V_34 . V_50 = V_68 ;
V_34 . V_52 = V_36 -> V_52 [ V_31 ] ;
V_34 . V_18 = V_38 ;
V_34 . V_54 = sizeof( * V_38 ) ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( * V_40 ) , V_40 ) ;
if( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_2 ) ;
goto V_43;
}
}
V_34 . V_50 = V_69 ;
V_34 . V_52 = (struct V_53 ) { 0 , 0 } ;
V_34 . V_18 = NULL ;
V_34 . V_54 = 0 ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( * V_36 ) , V_36 ) ;
if( ( V_32 < 0 ) || ( V_36 -> V_55 ) || ( V_36 -> V_56 > V_57 ) ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_3 ) ;
V_32 = - V_20 ;
goto V_43;
}
for( V_31 = 0 ; V_31 < V_36 -> V_56 ; V_31 ++ ) {
struct V_60 * V_61 ;
if( V_31 < V_62 ) {
V_61 = & V_2 -> V_63 [ V_31 / 2 ] -> V_70 ;
} else {
V_61 = & V_2 -> V_63 [ ( V_31 - V_62 ) / 2 ] -> V_71 ;
}
if( V_31 & 1 ) {
V_61 -> V_66 = V_36 -> V_52 [ V_31 ] ;
} else {
V_61 -> V_67 = V_36 -> V_52 [ V_31 ] ;
}
V_34 . V_50 = V_68 ;
V_34 . V_52 = V_36 -> V_52 [ V_31 ] ;
V_34 . V_18 = V_38 ;
V_34 . V_54 = sizeof( * V_38 ) ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( * V_40 ) , V_40 ) ;
if( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_2 ) ;
goto V_43;
}
}
V_32 = 0 ;
V_43:
F_14 ( V_36 ) ;
F_14 ( V_38 ) ;
F_14 ( V_40 ) ;
return V_32 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_31 ;
int V_32 ;
struct V_33 V_34 ;
struct V_53 V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
V_72 . V_77 = 0 ;
V_72 . V_78 = V_79 | 0 ;
V_34 . V_50 = V_80 ;
V_34 . V_52 = V_72 ;
V_34 . V_18 = & V_72 ;
V_34 . V_54 = sizeof( V_72 ) ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( V_74 ) , & V_74 ) ;
if( ( V_32 < 0 ) || ( V_74 . V_55 != 0 ) ) {
F_16 ( & V_2 -> V_58 -> V_59 ,
L_4 ,
V_74 . V_55 ) ;
return - V_20 ;
}
V_2 -> V_81 = V_74 . V_52 ;
V_34 . V_50 = V_82 ;
V_34 . V_52 = (struct V_53 ) { 0 , 0 } ;
V_34 . V_18 = & V_74 . V_52 ;
V_34 . V_54 = sizeof( V_74 . V_52 ) ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( V_76 ) , & V_76 ) ;
if( ( V_32 < 0 ) || ( V_76 . V_55 != 0 ) ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_5 ,
V_32 , V_76 . V_55 ) ;
return - V_20 ;
}
if ( V_76 . V_83 < V_84 * 2 )
return - V_20 ;
for( V_31 = 0 ; V_31 < V_2 -> V_85 ; V_31 ++ ) {
V_2 -> V_63 [ V_31 ] -> V_86 = V_76 . V_52 [ V_31 ] ;
V_2 -> V_63 [ V_31 ] -> V_87 = V_76 . V_52 [ V_76 . V_83 / 2 + V_31 ] ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_31 ;
int V_32 ;
struct V_33 V_34 ;
if( ( V_32 = F_10 ( V_2 ) ) < 0 ) return V_32 ;
if( ( V_32 = F_15 ( V_2 ) ) < 0 ) return V_32 ;
V_34 . V_50 = V_88 ;
V_34 . V_52 = (struct V_53 ) { 0 , 0 } ;
V_34 . V_18 = NULL ;
V_34 . V_54 = 0 ;
V_32 = F_12 ( V_2 , & V_34 , sizeof( V_31 ) , & V_31 ) ;
if( ( V_32 < 0 ) || ( V_31 != 0 ) ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_6 ) ;
return V_32 == 0 ? - V_20 : V_32 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_89 , const struct V_12 * V_13 )
{
int V_32 , V_90 ;
T_1 V_91 , V_92 , V_93 ;
T_1 V_94 ;
V_91 = F_3 ( F_4 ( V_2 , V_95 ) ) ;
V_92 = F_3 ( F_4 ( V_2 , V_96 ) ) ;
V_93 = F_3 ( F_4 ( V_2 , V_97 ) ) ;
if ( V_91 == 5 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_7 ) ;
return - V_98 ;
}
switch ( V_89 ) {
case V_99 :
if ( V_91 == 4 ) {
F_16 ( & V_2 -> V_58 -> V_59 , L_8 ) ;
return 0 ;
}
if ( V_91 != 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_9 ,
V_91 ) ;
return - V_100 ;
}
if ( ( ( T_1 * ) ( V_13 -> V_18 ) ) [ 0 ] == 0xffffffff )
return - V_20 ;
if ( V_13 -> V_54 % 4 )
return - V_20 ;
F_19 ( 1 , F_4 ( V_2 , V_95 ) ) ;
F_19 ( V_101 , F_4 ( V_2 , V_102 ) ) ;
F_19 ( V_13 -> V_54 , F_4 ( V_2 , V_103 ) ) ;
F_9 ( F_4 ( V_2 , V_101 ) , V_13 -> V_18 , V_13 -> V_54 ) ;
F_19 ( 2 , F_4 ( V_2 , V_95 ) ) ;
return 0 ;
case V_104 :
if ( V_92 == 4 ) {
F_16 ( & V_2 -> V_58 -> V_59 , L_10 ) ;
return 0 ;
}
if ( V_92 != 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_11 ,
V_92 ) ;
return - V_100 ;
}
V_32 = F_1 ( V_2 , V_95 , 1 , 4 , 500 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_12
L_13 ) ;
return V_32 ;
}
F_19 ( 0 , F_4 ( V_2 , V_105 ) ) ;
F_19 ( 0 , F_4 ( V_2 , V_106 ) ) ;
F_19 ( 1 , F_4 ( V_2 , V_96 ) ) ;
V_32 = F_6 ( V_2 , V_13 ) ;
if ( V_32 < 0 ) return V_32 ;
F_19 ( 2 , F_4 ( V_2 , V_96 ) ) ;
V_32 = F_1 ( V_2 , V_96 , 1 , 4 , 300 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_14 ) ;
return V_32 ;
}
F_19 ( ( T_1 ) V_2 -> V_107 . V_108 , F_4 ( V_2 , V_106 ) ) ;
return 0 ;
case V_109 :
default:
if ( V_92 != 4 || V_91 != 4 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_15
L_16 ) ;
return - V_100 ;
}
V_32 = F_1 ( V_2 , V_110 , 0 , 0 , 30 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_17 ) ;
return V_32 ;
}
V_2 -> V_111 = ( V_112 & F_3 ( F_4 ( V_2 , V_113 ) ) ) ;
if ( V_2 -> V_111 == V_114 )
break;
if ( V_2 -> V_111 != V_115 )
return - V_20 ;
if ( V_93 != 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_18 ,
V_93 ) ;
return - V_100 ;
}
if ( ( ( T_1 * ) ( V_13 -> V_18 ) ) [ 0 ] == 0xffffffff )
return - V_20 ;
if ( V_13 -> V_54 % 4 )
return - V_20 ;
F_19 ( V_13 -> V_54 , F_4 ( V_2 , V_116 ) ) ;
F_19 ( 1 , F_4 ( V_2 , V_97 ) ) ;
V_32 = F_1 ( V_2 , V_97 , 1 , 2 , 30 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_19 ) ;
return V_32 ;
}
V_94 = F_3 ( F_4 ( V_2 , V_117 ) ) ;
if ( ! V_94 )
return - V_20 ;
F_9 ( F_4 ( V_2 , V_94 ) , V_13 -> V_18 , V_13 -> V_54 ) ;
F_19 ( 4 , F_4 ( V_2 , V_97 ) ) ;
break;
}
V_32 = F_1 ( V_2 , V_97 , 1 , 3 , 300 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_20 ) ;
return V_32 ;
}
F_20 ( V_2 ) ;
V_32 = F_17 ( V_2 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_58 -> V_59 , L_21 ) ;
return V_32 ;
}
for ( V_90 = 0 ; V_90 < V_2 -> V_85 ; V_90 ++ ) {
struct V_118 * V_63 = V_2 -> V_63 [ V_90 ] ;
if ( ( V_32 = F_21 ( V_63 ) ) < 0 )
return V_32 ;
if ( V_90 == 0 ) {
if ( ( V_32 = F_22 ( V_63 -> V_2 ) ) < 0 )
return V_32 ;
}
if ( ( V_32 = F_23 ( V_63 -> V_119 ) ) < 0 )
return V_32 ;
}
F_16 ( & V_2 -> V_58 -> V_59 ,
L_22 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
static char * V_120 [ 3 ] = {
L_23 , L_24 , L_25
} ;
char V_121 [ 32 ] ;
const struct V_12 * V_122 ;
int V_17 , V_32 ;
for ( V_17 = 0 ; V_17 < 3 ; V_17 ++ ) {
sprintf ( V_121 , L_26 , V_120 [ V_17 ] ) ;
if ( F_25 ( & V_122 , V_121 , & V_2 -> V_58 -> V_59 ) ) {
F_13 ( & V_2 -> V_58 -> V_59 ,
L_27 , V_121 ) ;
return - V_123 ;
}
V_32 = F_18 ( V_2 , V_17 , V_122 ) ;
F_26 ( V_122 ) ;
if ( V_32 < 0 )
return V_32 ;
V_2 -> V_124 |= 1 << V_17 ;
}
return 0 ;
}
