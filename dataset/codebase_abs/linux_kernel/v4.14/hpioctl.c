static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
if ( ( V_2 -> V_6 >= V_7 )
&& ( V_2 -> V_8 != V_9 ) )
V_4 -> error = V_10 ;
else
F_2 ( V_2 , V_4 , V_5 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , V_11 ) ;
}
int F_4 ( struct V_5 * V_5 )
{
struct V_1 V_12 ;
struct V_3 V_13 ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_14 ) ;
F_2 ( & V_12 , & V_13 , V_5 ) ;
return 0 ;
}
long F_6 ( struct V_5 * V_5 , unsigned int V_15 , unsigned long V_16 )
{
struct V_17 T_1 * V_18 ;
void T_1 * V_19 ;
void T_1 * V_20 ;
union V_21 * V_12 ;
union V_22 * V_13 ;
T_2 V_23 ;
T_2 V_24 ;
T_3 V_25 ;
int V_26 = 0 ;
if ( V_15 != V_27 )
return - V_28 ;
V_12 = F_7 ( sizeof( * V_12 ) , V_29 ) ;
V_13 = F_8 ( sizeof( * V_13 ) , V_29 ) ;
if ( ! V_12 || ! V_13 ) {
V_26 = - V_30 ;
goto V_31;
}
V_18 = (struct V_17 T_1 * ) V_16 ;
if ( F_9 ( V_19 , & V_18 -> V_2 )
|| F_9 ( V_20 , & V_18 -> V_4 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( F_9 ( V_23 , ( T_2 T_1 * ) V_19 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( V_23 > sizeof( * V_12 ) )
V_23 = sizeof( * V_12 ) ;
V_25 = F_10 ( V_12 , V_19 , V_23 ) ;
if ( V_25 ) {
F_11 ( ERROR , L_1 , V_25 ) ;
V_26 = - V_32 ;
goto V_31;
}
V_12 -> V_33 . V_34 = V_23 ;
if ( F_9 ( V_24 , ( T_2 T_1 * ) V_20 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( V_24 < sizeof( struct V_35 ) ) {
F_11 ( V_36 , L_2 , V_24 ) ;
V_26 = - V_32 ;
goto V_31;
}
V_24 = F_12 ( V_37 , V_24 , sizeof( * V_13 ) ) ;
switch ( V_12 -> V_33 . V_38 ) {
case V_39 :
case V_40 :
V_13 -> V_33 . V_34 = sizeof( V_13 -> V_33 ) ;
V_13 -> V_33 . error = V_41 ;
V_13 -> V_33 . V_38 = V_12 -> V_33 . V_38 ;
V_25 = F_13 ( V_20 , V_13 , V_13 -> V_33 . V_34 ) ;
if ( V_25 )
V_26 = - V_32 ;
else
V_26 = 0 ;
goto V_31;
}
V_13 -> V_33 . V_34 = V_24 ;
if ( V_12 -> V_33 . V_8 == V_9 ) {
F_1 ( & V_12 -> V_42 , & V_13 -> V_43 , V_5 ) ;
} else {
T_2 T_1 * V_44 = NULL ;
T_3 V_34 = 0 ;
int V_45 = - 1 ;
struct V_46 * V_47 = NULL ;
if ( V_12 -> V_33 . V_6 < F_14 ( V_48 ) )
V_47 = & V_48 [ V_12 -> V_33 . V_6 ] ;
if ( ! V_47 || ! V_47 -> V_49 || ! V_47 -> V_49 -> type ) {
F_15 ( & V_13 -> V_43 , V_12 -> V_33 . V_8 ,
V_12 -> V_33 . V_38 , V_50 ) ;
V_25 =
F_13 ( V_20 , V_13 , sizeof( V_13 -> V_33 ) ) ;
if ( V_25 )
V_26 = - V_32 ;
else
V_26 = 0 ;
goto V_31;
}
if ( F_16 ( & V_47 -> V_51 ) ) {
V_26 = - V_52 ;
goto V_31;
}
switch ( V_12 -> V_33 . V_38 ) {
case V_53 :
case V_54 : {
V_44 = ( T_2 T_1 * ) V_12 -> V_42 . V_55 . V_56 . V_55 . V_57 . V_58 ;
V_34 = V_12 -> V_42 . V_55 . V_56 . V_55 . V_57 . V_59 ;
if ( V_47 -> V_60 < V_34 ) {
F_11 ( V_61 ,
L_3
L_4 ,
V_12 -> V_33 . V_6 ,
V_47 -> V_60 , V_34 ) ;
if ( V_47 -> V_62 ) {
V_47 -> V_60 = 0 ;
F_17 ( V_47 -> V_62 ) ;
}
V_47 -> V_62 = F_18 ( V_34 ) ;
if ( V_47 -> V_62 )
V_47 -> V_60 = V_34 ;
else {
F_11 ( ERROR ,
L_5
L_6 ,
V_34 ) ;
F_19 ( & V_47 -> V_51 ) ;
V_26 = - V_28 ;
goto V_31;
}
}
V_12 -> V_42 . V_55 . V_56 . V_55 . V_57 . V_58 = V_47 -> V_62 ;
if ( V_12 -> V_33 . V_38 == V_54 )
V_45 = 1 ;
else
V_45 = 0 ;
break;
}
default:
V_34 = 0 ;
break;
}
if ( V_34 && ( V_45 == 0 ) ) {
V_25 =
F_10 ( V_47 -> V_62 , V_44 , V_34 ) ;
if ( V_25 )
F_11 ( V_36 ,
L_7
L_8 , V_25 ,
V_34 ) ;
}
F_1 ( & V_12 -> V_42 , & V_13 -> V_43 , V_5 ) ;
if ( V_34 && ( V_45 == 1 ) ) {
V_25 =
F_13 ( V_44 , V_47 -> V_62 , V_34 ) ;
if ( V_25 )
F_11 ( V_36 ,
L_7 L_9 ,
V_25 , V_34 ) ;
}
F_19 ( & V_47 -> V_51 ) ;
}
if ( ! V_13 -> V_33 . V_34 ) {
F_11 ( ERROR , L_10 ) ;
V_26 = - V_32 ;
goto V_31;
}
if ( V_13 -> V_33 . V_34 > V_24 ) {
F_11 ( ERROR , L_11 , V_13 -> V_33 . V_34 ,
V_24 ) ;
V_13 -> V_33 . error = V_63 ;
V_13 -> V_33 . V_64 = V_13 -> V_33 . V_34 ;
V_13 -> V_33 . V_34 = sizeof( V_13 -> V_33 ) ;
}
V_25 = F_13 ( V_20 , V_13 , V_13 -> V_33 . V_34 ) ;
if ( V_25 ) {
F_11 ( ERROR , L_1 , V_25 ) ;
V_26 = - V_32 ;
goto V_31;
}
V_31:
F_20 ( V_12 ) ;
F_20 ( V_13 ) ;
return V_26 ;
}
static T_4 F_21 ( int V_65 , void * V_66 )
{
struct V_46 * V_67 = V_66 ;
int V_68 ;
if ( ! V_67 -> V_49 -> V_69 ) {
F_22 ( L_12 , V_67 -> V_49 -> type ,
V_67 -> V_49 -> V_70 ) ;
return V_71 ;
}
V_68 = V_67 -> V_49 -> V_69 ( V_67 -> V_49 , 0 ) ;
if ( ! V_68 )
return V_71 ;
V_72 ++ ;
if ( V_67 -> V_73 )
V_67 -> V_73 ( V_67 ) ;
return V_74 ;
}
int F_23 ( struct V_75 * V_75 ,
const struct V_76 * V_77 )
{
int V_78 , V_79 , V_80 = 0 , V_81 = 0 ;
int V_6 ;
unsigned int V_82 ;
struct V_1 V_12 ;
struct V_3 V_13 ;
struct V_46 V_49 ;
struct V_83 V_84 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_24 ( V_85 , & V_75 -> V_86 ,
L_13 , V_75 -> V_87 ,
V_75 -> V_88 , V_75 -> V_89 ,
V_75 -> V_90 , V_75 -> V_91 ) ;
if ( F_25 ( V_75 ) < 0 ) {
F_26 ( & V_75 -> V_86 ,
L_14 ) ;
return - V_92 ;
}
F_27 ( V_75 ) ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_39 ) ;
F_15 ( & V_13 , V_9 , V_39 ,
V_93 ) ;
V_12 . V_6 = V_94 ;
V_79 = V_95 ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
F_11 ( V_96 , L_15 , V_78 ,
& V_75 -> V_97 [ V_78 ] ) ;
if ( F_28 ( V_75 , V_78 ) & V_98 ) {
V_82 = F_29 ( V_75 , V_78 ) ;
V_84 . V_99 [ V_78 ] =
F_30 ( F_31 ( V_75 , V_78 ) ,
V_82 ) ;
if ( ! V_84 . V_99 [ V_78 ] ) {
F_11 ( ERROR ,
L_16 ) ;
goto V_26;
}
}
}
V_84 . V_75 = V_75 ;
V_12 . V_55 . V_100 . V_97 . V_101 = V_102 ;
V_12 . V_55 . V_100 . V_97 . V_103 . V_84 = & V_84 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error )
goto V_26;
V_6 = V_13 . V_55 . V_100 . V_6 ;
V_49 . V_49 = F_32 ( V_6 ) ;
if ( V_104 ) {
V_49 . V_62 = F_18 ( V_104 ) ;
if ( ! V_49 . V_62 ) {
F_11 ( ERROR ,
L_5
L_17 ,
V_104 ) ;
goto V_26;
}
}
F_5 ( & V_12 , & V_13 , V_105 ,
V_106 ) ;
V_12 . V_6 = V_49 . V_49 -> V_70 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error ) {
F_11 ( ERROR , L_18 ) ;
goto V_26;
}
F_5 ( & V_12 , & V_13 , V_105 ,
V_107 ) ;
V_12 . V_6 = V_49 . V_49 -> V_70 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( ! V_13 . error
&& V_13 . V_55 . V_108 . V_109 . V_110 == V_111 )
V_80 = 1 ;
else
F_33 ( & V_75 -> V_86 ,
L_19 ,
V_49 . V_49 -> V_70 ) ;
F_5 ( & V_12 , & V_13 , V_105 ,
V_112 ) ;
V_12 . V_6 = V_49 . V_49 -> V_70 ;
V_12 . V_55 . V_108 . V_113 . V_114 = V_115 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error || ! V_13 . V_55 . V_108 . V_116 . V_117 ) {
F_33 ( & V_75 -> V_86 ,
L_20 ,
V_49 . V_49 -> V_70 ) ;
} else {
V_81 = 1 ;
}
V_48 [ V_6 ] = V_49 ;
F_34 ( & V_48 [ V_6 ] . V_51 ) ;
F_35 ( V_75 , & V_48 [ V_6 ] ) ;
if ( V_80 && V_81 ) {
if ( ! V_49 . V_49 -> V_69 ) {
F_26 ( & V_75 -> V_86 ,
L_21 ,
V_49 . V_49 -> V_70 ) ;
goto V_26;
}
F_5 ( & V_12 , & V_13 , V_105 ,
V_118 ) ;
V_12 . V_6 = V_49 . V_49 -> V_70 ;
V_12 . V_55 . V_108 . V_113 . V_114 = V_119 ;
V_12 . V_55 . V_108 . V_113 . V_117 = 0 ;
V_12 . V_55 . V_108 . V_113 . V_120 = 0 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error ) {
F_11 ( ERROR ,
L_22 ) ;
goto V_26;
}
if ( F_36 ( V_75 -> V_65 , F_21 , V_121 ,
L_23 , & V_48 [ V_6 ] ) ) {
F_26 ( & V_75 -> V_86 , L_24 ,
V_75 -> V_65 ) ;
goto V_26;
}
V_48 [ V_6 ] . V_122 = 1 ;
F_33 ( & V_75 -> V_86 , L_25 , V_75 -> V_65 ) ;
V_48 [ V_6 ] . V_65 = V_75 -> V_65 ;
} else {
F_33 ( & V_75 -> V_86 , L_26 ) ;
}
F_33 ( & V_75 -> V_86 , L_27 ,
V_49 . V_49 -> type , V_6 ) ;
return 0 ;
V_26:
for ( V_78 = 0 ; V_78 < V_95 ; V_78 ++ ) {
if ( V_84 . V_99 [ V_78 ] ) {
F_37 ( V_84 . V_99 [ V_78 ] ) ;
V_84 . V_99 [ V_78 ] = NULL ;
}
}
if ( V_49 . V_62 ) {
V_49 . V_60 = 0 ;
F_17 ( V_49 . V_62 ) ;
}
F_11 ( ERROR , L_28 ) ;
return - V_123 ;
}
void F_38 ( struct V_75 * V_75 )
{
int V_78 ;
struct V_1 V_12 ;
struct V_3 V_13 ;
struct V_46 * V_47 ;
struct V_83 V_84 ;
V_47 = F_39 ( V_75 ) ;
V_84 = V_47 -> V_49 -> V_84 ;
F_5 ( & V_12 , & V_13 , V_105 ,
V_118 ) ;
V_12 . V_6 = V_47 -> V_49 -> V_70 ;
V_12 . V_55 . V_108 . V_113 . V_114 = V_119 ;
V_12 . V_55 . V_108 . V_113 . V_117 = 0 ;
V_12 . V_55 . V_108 . V_113 . V_120 = 0 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
F_5 ( & V_12 , & V_13 , V_105 ,
V_40 ) ;
V_12 . V_6 = V_47 -> V_49 -> V_70 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
for ( V_78 = 0 ; V_78 < V_95 ; ++ V_78 )
F_37 ( V_84 . V_99 [ V_78 ] ) ;
if ( V_47 -> V_65 )
F_40 ( V_47 -> V_65 , V_47 ) ;
F_17 ( V_47 -> V_62 ) ;
if ( 1 )
F_33 ( & V_75 -> V_86 ,
L_29 ,
V_75 -> V_87 , V_75 -> V_88 ,
V_75 -> V_89 , V_75 -> V_90 ,
V_75 -> V_91 , V_47 -> V_49 -> V_70 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
void T_5 F_41 ( void )
{
struct V_1 V_12 ;
struct V_3 V_13 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
F_42 ( V_124 L_30 V_125 L_31 ) ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_126 ) ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
}
void F_43 ( void )
{
struct V_1 V_12 ;
struct V_3 V_13 ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_127 ) ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
}
