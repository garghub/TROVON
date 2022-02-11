static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
int V_6 = V_2 -> V_7 ;
if ( ( V_6 >= V_8 || V_6 < 0 )
&& ( V_2 -> V_9 != V_10 ) )
V_4 -> error = V_11 ;
else
F_2 ( V_2 , V_4 , V_5 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , V_12 ) ;
}
int F_4 ( struct V_5 * V_5 )
{
struct V_1 V_13 ;
struct V_3 V_14 ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_15 ) ;
F_2 ( & V_13 , & V_14 , V_5 ) ;
return 0 ;
}
long F_6 ( struct V_5 * V_5 , unsigned int V_16 , unsigned long V_17 )
{
struct V_18 T_1 * V_19 ;
void T_1 * V_20 ;
void T_1 * V_21 ;
union V_22 * V_13 ;
union V_23 * V_14 ;
T_2 V_24 ;
T_3 V_25 ;
int V_26 = 0 ;
if ( V_16 != V_27 )
return - V_28 ;
V_13 = F_7 ( sizeof( * V_13 ) , V_29 ) ;
V_14 = F_7 ( sizeof( * V_14 ) , V_29 ) ;
if ( ! V_13 || ! V_14 ) {
V_26 = - V_30 ;
goto V_31;
}
V_19 = (struct V_18 T_1 * ) V_17 ;
if ( F_8 ( V_20 , & V_19 -> V_2 )
|| F_8 ( V_21 , & V_19 -> V_4 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( F_8 ( V_13 -> V_33 . V_34 , ( T_2 T_1 * ) V_20 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( V_13 -> V_33 . V_34 > sizeof( * V_13 ) )
V_13 -> V_33 . V_34 = sizeof( * V_13 ) ;
V_25 = F_9 ( V_13 , V_20 , V_13 -> V_33 . V_34 ) ;
if ( V_25 ) {
F_10 ( ERROR , L_1 , V_25 ) ;
V_26 = - V_32 ;
goto V_31;
}
if ( F_8 ( V_24 , ( T_2 T_1 * ) V_21 ) ) {
V_26 = - V_32 ;
goto V_31;
}
if ( V_24 < sizeof( struct V_35 ) ) {
F_10 ( V_36 , L_2 , V_24 ) ;
V_26 = - V_32 ;
goto V_31;
}
switch ( V_13 -> V_33 . V_37 ) {
case V_38 :
case V_39 :
V_14 -> V_33 . V_34 = sizeof( V_14 -> V_33 ) ;
V_14 -> V_33 . error = V_40 ;
V_14 -> V_33 . V_37 = V_13 -> V_33 . V_37 ;
V_25 = F_11 ( V_21 , V_14 , V_14 -> V_33 . V_34 ) ;
if ( V_25 )
V_26 = - V_32 ;
else
V_26 = 0 ;
goto V_31;
}
V_14 -> V_33 . V_34 = V_24 ;
if ( V_13 -> V_33 . V_9 == V_10 ) {
F_1 ( & V_13 -> V_41 , & V_14 -> V_42 , V_5 ) ;
} else {
T_2 T_1 * V_43 = NULL ;
T_3 V_34 = 0 ;
T_3 V_44 ;
int V_45 = - 1 ;
struct V_46 * V_47 ;
if ( V_13 -> V_33 . V_7 < V_8 ) {
V_47 = & V_48 [ V_13 -> V_33 . V_7 ] ;
V_44 = V_47 -> type ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
F_12 ( & V_14 -> V_42 , V_13 -> V_33 . V_9 ,
V_13 -> V_33 . V_37 , V_49 ) ;
V_25 =
F_11 ( V_21 , V_14 , sizeof( V_14 -> V_33 ) ) ;
if ( V_25 )
V_26 = - V_32 ;
else
V_26 = 0 ;
goto V_31;
}
if ( F_13 ( & V_47 -> V_50 ) ) {
V_26 = - V_51 ;
goto V_31;
}
switch ( V_13 -> V_33 . V_37 ) {
case V_52 :
case V_53 : {
V_43 = ( T_2 T_1 * ) V_13 -> V_41 . V_54 . V_55 . V_54 . V_56 . V_57 ;
V_34 = V_13 -> V_41 . V_54 . V_55 . V_54 . V_56 . V_58 ;
if ( V_47 -> V_59 < V_34 ) {
F_10 ( V_60 ,
L_3
L_4 ,
V_13 -> V_33 . V_7 ,
V_47 -> V_59 , V_34 ) ;
if ( V_47 -> V_61 ) {
V_47 -> V_59 = 0 ;
F_14 ( V_47 -> V_61 ) ;
}
V_47 -> V_61 = F_15 ( V_34 ) ;
if ( V_47 -> V_61 )
V_47 -> V_59 = V_34 ;
else {
F_10 ( ERROR ,
L_5
L_6 ,
V_34 ) ;
F_16 ( & V_47 -> V_50 ) ;
V_26 = - V_28 ;
goto V_31;
}
}
V_13 -> V_41 . V_54 . V_55 . V_54 . V_56 . V_57 = V_47 -> V_61 ;
if ( V_13 -> V_33 . V_37 == V_53 )
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
F_9 ( V_47 -> V_61 , V_43 , V_34 ) ;
if ( V_25 )
F_10 ( V_36 ,
L_7
L_8 , V_25 ,
V_34 ) ;
}
F_1 ( & V_13 -> V_41 , & V_14 -> V_42 , V_5 ) ;
if ( V_34 && ( V_45 == 1 ) ) {
V_25 =
F_11 ( V_43 , V_47 -> V_61 , V_34 ) ;
if ( V_25 )
F_10 ( V_36 ,
L_7 L_9 ,
V_25 , V_34 ) ;
}
F_16 ( & V_47 -> V_50 ) ;
}
if ( ! V_14 -> V_33 . V_34 ) {
F_10 ( ERROR , L_10 ) ;
V_26 = - V_32 ;
goto V_31;
}
if ( V_14 -> V_33 . V_34 > V_24 ) {
F_10 ( ERROR , L_11 , V_14 -> V_33 . V_34 ,
V_24 ) ;
V_14 -> V_33 . error = V_62 ;
V_14 -> V_33 . V_63 = V_14 -> V_33 . V_34 ;
V_14 -> V_33 . V_34 = sizeof( V_14 -> V_33 ) ;
}
V_25 = F_11 ( V_21 , V_14 , V_14 -> V_33 . V_34 ) ;
if ( V_25 ) {
F_10 ( ERROR , L_1 , V_25 ) ;
V_26 = - V_32 ;
goto V_31;
}
V_31:
F_17 ( V_13 ) ;
F_17 ( V_14 ) ;
return V_26 ;
}
int T_4 F_18 ( struct V_64 * V_64 ,
const struct V_65 * V_66 )
{
int V_67 , V_68 ;
unsigned int V_69 ;
struct V_1 V_13 ;
struct V_3 V_14 ;
struct V_46 V_6 ;
struct V_70 V_71 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_19 ( V_72 , & V_64 -> V_73 ,
L_12 , V_64 -> V_74 ,
V_64 -> V_75 , V_64 -> V_76 ,
V_64 -> V_77 , V_64 -> V_78 ) ;
if ( F_20 ( V_64 ) < 0 ) {
F_19 ( V_79 , & V_64 -> V_73 ,
L_13 ) ;
return - V_80 ;
}
F_21 ( V_64 ) ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_38 ) ;
F_12 ( & V_14 , V_10 , V_38 ,
V_81 ) ;
V_13 . V_7 = V_82 ;
V_6 . V_71 = V_64 ;
V_68 = V_83 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
F_10 ( V_84 , L_14 , V_67 ,
& V_64 -> V_85 [ V_67 ] ) ;
if ( F_22 ( V_64 , V_67 ) & V_86 ) {
V_69 = F_23 ( V_64 , V_67 ) ;
V_6 . V_87 [ V_67 ] =
F_24 ( F_25 ( V_64 , V_67 ) ,
V_69 ) ;
if ( ! V_6 . V_87 [ V_67 ] ) {
F_10 ( ERROR ,
L_15 ) ;
goto V_26;
}
}
V_71 . V_88 [ V_67 ] = V_6 . V_87 [ V_67 ] ;
}
V_71 . V_64 = V_64 ;
V_13 . V_54 . V_89 . V_85 . V_90 = V_91 ;
V_13 . V_54 . V_89 . V_85 . V_92 . V_71 = & V_71 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
if ( V_14 . error )
goto V_26;
if ( V_93 ) {
V_6 . V_61 = F_15 ( V_93 ) ;
if ( ! V_6 . V_61 ) {
F_10 ( ERROR ,
L_5
L_16 ,
V_93 ) ;
goto V_26;
}
}
V_6 . V_94 = V_14 . V_54 . V_89 . V_7 ;
V_6 . type = V_14 . V_54 . V_89 . V_95 ;
F_5 ( & V_13 , & V_14 , V_96 ,
V_97 ) ;
V_13 . V_7 = V_6 . V_94 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
if ( V_14 . error )
goto V_26;
V_6 . V_98 = NULL ;
V_48 [ V_6 . V_94 ] = V_6 ;
F_26 ( & V_48 [ V_6 . V_94 ] . V_50 ) ;
F_27 ( V_64 , & V_48 [ V_6 . V_94 ] ) ;
F_19 ( V_99 , & V_64 -> V_73 ,
L_17 , V_6 . type ,
V_6 . V_94 ) ;
return 0 ;
V_26:
for ( V_67 = 0 ; V_67 < V_83 ; V_67 ++ ) {
if ( V_6 . V_87 [ V_67 ] ) {
F_28 ( V_6 . V_87 [ V_67 ] ) ;
V_6 . V_87 [ V_67 ] = NULL ;
}
}
if ( V_6 . V_61 ) {
V_6 . V_59 = 0 ;
F_14 ( V_6 . V_61 ) ;
}
F_10 ( ERROR , L_18 ) ;
return - V_100 ;
}
void T_5 F_29 ( struct V_64 * V_64 )
{
int V_67 ;
struct V_1 V_13 ;
struct V_3 V_14 ;
struct V_46 * V_47 ;
V_47 = F_30 ( V_64 ) ;
F_5 ( & V_13 , & V_14 , V_96 ,
V_39 ) ;
V_13 . V_7 = V_47 -> V_94 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
for ( V_67 = 0 ; V_67 < V_83 ; V_67 ++ ) {
if ( V_47 -> V_87 [ V_67 ] ) {
F_28 ( V_47 -> V_87 [ V_67 ] ) ;
V_47 -> V_87 [ V_67 ] = NULL ;
}
}
if ( V_47 -> V_61 )
F_14 ( V_47 -> V_61 ) ;
F_27 ( V_64 , NULL ) ;
if ( 1 )
F_19 ( V_99 , & V_64 -> V_73 ,
L_19 L_20 ,
V_64 -> V_74 , V_64 -> V_75 ,
V_64 -> V_76 , V_64 -> V_77 ,
V_64 -> V_78 , V_47 -> V_94 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
void T_6 F_31 ( void )
{
struct V_1 V_13 ;
struct V_3 V_14 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
F_32 ( V_99 L_21 V_101 L_22 ) ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_102 ) ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
}
void F_33 ( void )
{
struct V_1 V_13 ;
struct V_3 V_14 ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_103 ) ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
}
