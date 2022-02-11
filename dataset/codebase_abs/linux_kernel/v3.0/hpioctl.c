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
struct V_26 * V_27 = NULL ;
int V_28 = 0 ;
if ( V_16 != V_29 )
return - V_30 ;
V_13 = F_7 ( sizeof( * V_13 ) , V_31 ) ;
V_14 = F_7 ( sizeof( * V_14 ) , V_31 ) ;
if ( ! V_13 || ! V_14 ) {
V_28 = - V_32 ;
goto V_33;
}
V_19 = (struct V_18 T_1 * ) V_17 ;
if ( F_8 ( V_20 , & V_19 -> V_2 )
|| F_8 ( V_21 , & V_19 -> V_4 ) ) {
V_28 = - V_34 ;
goto V_33;
}
if ( F_8 ( V_13 -> V_35 . V_36 , ( T_2 T_1 * ) V_20 ) ) {
V_28 = - V_34 ;
goto V_33;
}
if ( V_13 -> V_35 . V_36 > sizeof( * V_13 ) )
V_13 -> V_35 . V_36 = sizeof( * V_13 ) ;
V_25 = F_9 ( V_13 , V_20 , V_13 -> V_35 . V_36 ) ;
if ( V_25 ) {
F_10 ( ERROR , L_1 , V_25 ) ;
V_28 = - V_34 ;
goto V_33;
}
if ( F_8 ( V_24 , ( T_2 T_1 * ) V_21 ) ) {
V_28 = - V_34 ;
goto V_33;
}
if ( V_24 < sizeof( struct V_37 ) ) {
F_10 ( V_38 , L_2 , V_24 ) ;
V_28 = - V_34 ;
goto V_33;
}
if ( V_13 -> V_35 . V_7 >= V_8 ) {
V_28 = - V_30 ;
goto V_33;
}
switch ( V_13 -> V_35 . V_39 ) {
case V_40 :
case V_41 :
V_14 -> V_35 . V_36 = sizeof( V_14 -> V_35 ) ;
V_14 -> V_35 . error = V_42 ;
V_14 -> V_35 . V_39 = V_13 -> V_35 . V_39 ;
V_25 = F_11 ( V_21 , V_14 , V_14 -> V_35 . V_36 ) ;
if ( V_25 )
V_28 = - V_34 ;
else
V_28 = 0 ;
goto V_33;
}
V_14 -> V_35 . V_36 = V_24 ;
if ( V_13 -> V_35 . V_9 == V_10 ) {
F_1 ( & V_13 -> V_43 , & V_14 -> V_44 , V_5 ) ;
} else {
T_2 T_1 * V_45 = NULL ;
T_3 V_36 = 0 ;
int V_46 = - 1 ;
T_3 V_6 = V_13 -> V_35 . V_7 ;
V_27 = & V_47 [ V_6 ] ;
if ( ( V_6 > V_8 ) || ( ! V_27 -> type ) ) {
F_12 ( & V_14 -> V_44 , V_48 ,
V_49 ,
V_50 ) ;
V_25 =
F_11 ( V_21 , V_14 , sizeof( V_14 -> V_35 ) ) ;
if ( V_25 )
V_28 = - V_34 ;
else
V_28 = 0 ;
goto V_33;
}
if ( F_13 ( & V_47 [ V_6 ] . V_51 ) ) {
V_28 = - V_52 ;
goto V_33;
}
switch ( V_13 -> V_35 . V_39 ) {
case V_53 :
case V_54 : {
V_45 = ( T_2 T_1 * ) V_13 -> V_43 . V_55 . V_56 . V_55 . V_57 . V_58 ;
V_36 = V_13 -> V_43 . V_55 . V_56 . V_55 . V_57 . V_59 ;
if ( V_27 -> V_60 < V_36 ) {
F_10 ( V_61 ,
L_3
L_4 ,
V_13 -> V_35 . V_7 ,
V_27 -> V_60 , V_36 ) ;
if ( V_27 -> V_62 ) {
V_27 -> V_60 = 0 ;
F_14 ( V_27 -> V_62 ) ;
}
V_27 -> V_62 = F_15 ( V_36 ) ;
if ( V_27 -> V_62 )
V_27 -> V_60 = V_36 ;
else {
F_10 ( ERROR ,
L_5
L_6 ,
V_36 ) ;
F_16 ( & V_47
[ V_6 ] . V_51 ) ;
V_28 = - V_30 ;
goto V_33;
}
}
V_13 -> V_43 . V_55 . V_56 . V_55 . V_57 . V_58 = V_27 -> V_62 ;
if ( V_13 -> V_35 . V_39 == V_54 )
V_46 = 1 ;
else
V_46 = 0 ;
break;
}
default:
V_36 = 0 ;
break;
}
if ( V_36 && ( V_46 == 0 ) ) {
V_25 =
F_9 ( V_27 -> V_62 , V_45 , V_36 ) ;
if ( V_25 )
F_10 ( V_38 ,
L_7
L_8 , V_25 ,
V_36 ) ;
}
F_1 ( & V_13 -> V_43 , & V_14 -> V_44 , V_5 ) ;
if ( V_36 && ( V_46 == 1 ) ) {
V_25 =
F_11 ( V_45 , V_27 -> V_62 , V_36 ) ;
if ( V_25 )
F_10 ( V_38 ,
L_7 L_9 ,
V_25 , V_36 ) ;
}
F_16 ( & V_47 [ V_6 ] . V_51 ) ;
}
if ( ! V_14 -> V_35 . V_36 ) {
F_10 ( ERROR , L_10 ) ;
V_28 = - V_34 ;
goto V_33;
}
if ( V_14 -> V_35 . V_36 > V_24 ) {
F_10 ( ERROR , L_11 , V_14 -> V_35 . V_36 ,
V_24 ) ;
V_14 -> V_35 . error = V_63 ;
V_14 -> V_35 . V_64 = V_14 -> V_35 . V_36 ;
V_14 -> V_35 . V_36 = sizeof( V_14 -> V_35 ) ;
}
V_25 = F_11 ( V_21 , V_14 , V_14 -> V_35 . V_36 ) ;
if ( V_25 ) {
F_10 ( ERROR , L_1 , V_25 ) ;
V_28 = - V_34 ;
goto V_33;
}
V_33:
F_17 ( V_13 ) ;
F_17 ( V_14 ) ;
return V_28 ;
}
int T_4 F_18 ( struct V_65 * V_65 ,
const struct V_66 * V_67 )
{
int V_68 , V_69 ;
unsigned int V_70 ;
struct V_1 V_13 ;
struct V_3 V_14 ;
struct V_26 V_6 ;
struct V_71 V_72 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_19 ( V_73 , & V_65 -> V_74 ,
L_12 , V_65 -> V_75 ,
V_65 -> V_76 , V_65 -> V_77 ,
V_65 -> V_78 , V_65 -> V_79 ) ;
if ( F_20 ( V_65 ) < 0 ) {
F_19 ( V_80 , & V_65 -> V_74 ,
L_13 ) ;
return - V_81 ;
}
F_21 ( V_65 ) ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_40 ) ;
F_12 ( & V_14 , V_10 , V_40 ,
V_82 ) ;
V_13 . V_7 = V_83 ;
V_6 . V_72 = V_65 ;
V_69 = V_84 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
F_10 ( V_85 , L_14 , V_68 ,
& V_65 -> V_86 [ V_68 ] ) ;
if ( F_22 ( V_65 , V_68 ) & V_87 ) {
V_70 = F_23 ( V_65 , V_68 ) ;
V_6 . V_88 [ V_68 ] =
F_24 ( F_25 ( V_65 , V_68 ) ,
V_70 ) ;
if ( ! V_6 . V_88 [ V_68 ] ) {
F_10 ( ERROR ,
L_15 ) ;
goto V_28;
}
}
V_72 . V_89 [ V_68 ] = V_6 . V_88 [ V_68 ] ;
}
V_72 . V_65 = V_65 ;
V_13 . V_55 . V_90 . V_86 . V_91 = V_92 ;
V_13 . V_55 . V_90 . V_86 . V_93 . V_72 = & V_72 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
if ( V_14 . error )
goto V_28;
if ( V_94 ) {
V_6 . V_62 = F_15 ( V_94 ) ;
if ( ! V_6 . V_62 ) {
F_10 ( ERROR ,
L_5
L_16 ,
V_94 ) ;
goto V_28;
}
}
V_6 . V_95 = V_14 . V_55 . V_90 . V_7 ;
V_6 . type = V_14 . V_55 . V_90 . V_96 ;
F_5 ( & V_13 , & V_14 , V_48 ,
V_49 ) ;
V_13 . V_7 = V_6 . V_95 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
if ( V_14 . error )
goto V_28;
V_6 . V_97 = NULL ;
V_47 [ V_6 . V_95 ] = V_6 ;
F_26 ( & V_47 [ V_6 . V_95 ] . V_51 ) ;
F_27 ( V_65 , & V_47 [ V_6 . V_95 ] ) ;
F_19 ( V_98 , & V_65 -> V_74 ,
L_17 , V_6 . type ,
V_6 . V_95 ) ;
return 0 ;
V_28:
for ( V_68 = 0 ; V_68 < V_84 ; V_68 ++ ) {
if ( V_6 . V_88 [ V_68 ] ) {
F_28 ( V_6 . V_88 [ V_68 ] ) ;
V_6 . V_88 [ V_68 ] = NULL ;
}
}
if ( V_6 . V_62 ) {
V_6 . V_60 = 0 ;
F_14 ( V_6 . V_62 ) ;
}
F_10 ( ERROR , L_18 ) ;
return - V_99 ;
}
void T_5 F_29 ( struct V_65 * V_65 )
{
int V_68 ;
struct V_1 V_13 ;
struct V_3 V_14 ;
struct V_26 * V_27 ;
V_27 = F_30 ( V_65 ) ;
F_5 ( & V_13 , & V_14 , V_48 ,
V_41 ) ;
V_13 . V_7 = V_27 -> V_95 ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
for ( V_68 = 0 ; V_68 < V_84 ; V_68 ++ ) {
if ( V_27 -> V_88 [ V_68 ] ) {
F_28 ( V_27 -> V_88 [ V_68 ] ) ;
V_27 -> V_88 [ V_68 ] = NULL ;
}
}
if ( V_27 -> V_62 )
F_14 ( V_27 -> V_62 ) ;
F_27 ( V_65 , NULL ) ;
if ( 1 )
F_19 ( V_98 , & V_65 -> V_74 ,
L_19 L_20 ,
V_65 -> V_75 , V_65 -> V_76 ,
V_65 -> V_77 , V_65 -> V_78 ,
V_65 -> V_79 , V_27 -> V_95 ) ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
}
void T_6 F_31 ( void )
{
struct V_1 V_13 ;
struct V_3 V_14 ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
F_32 ( V_98 L_21 V_100 L_22 ) ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_101 ) ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
}
void F_33 ( void )
{
struct V_1 V_13 ;
struct V_3 V_14 ;
F_5 ( & V_13 , & V_14 , V_10 ,
V_102 ) ;
F_2 ( & V_13 , & V_14 , V_12 ) ;
}
