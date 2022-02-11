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
T_3 V_24 ;
int V_25 = 0 ;
if ( V_15 != V_26 )
return - V_27 ;
V_12 = F_7 ( sizeof( * V_12 ) , V_28 ) ;
V_13 = F_7 ( sizeof( * V_13 ) , V_28 ) ;
if ( ! V_12 || ! V_13 ) {
V_25 = - V_29 ;
goto V_30;
}
V_18 = (struct V_17 T_1 * ) V_16 ;
if ( F_8 ( V_19 , & V_18 -> V_2 )
|| F_8 ( V_20 , & V_18 -> V_4 ) ) {
V_25 = - V_31 ;
goto V_30;
}
if ( F_8 ( V_12 -> V_32 . V_33 , ( T_2 T_1 * ) V_19 ) ) {
V_25 = - V_31 ;
goto V_30;
}
if ( V_12 -> V_32 . V_33 > sizeof( * V_12 ) )
V_12 -> V_32 . V_33 = sizeof( * V_12 ) ;
V_24 = F_9 ( V_12 , V_19 , V_12 -> V_32 . V_33 ) ;
if ( V_24 ) {
F_10 ( ERROR , L_1 , V_24 ) ;
V_25 = - V_31 ;
goto V_30;
}
if ( F_8 ( V_23 , ( T_2 T_1 * ) V_20 ) ) {
V_25 = - V_31 ;
goto V_30;
}
if ( V_23 < sizeof( struct V_34 ) ) {
F_10 ( V_35 , L_2 , V_23 ) ;
V_25 = - V_31 ;
goto V_30;
}
switch ( V_12 -> V_32 . V_36 ) {
case V_37 :
case V_38 :
V_13 -> V_32 . V_33 = sizeof( V_13 -> V_32 ) ;
V_13 -> V_32 . error = V_39 ;
V_13 -> V_32 . V_36 = V_12 -> V_32 . V_36 ;
V_24 = F_11 ( V_20 , V_13 , V_13 -> V_32 . V_33 ) ;
if ( V_24 )
V_25 = - V_31 ;
else
V_25 = 0 ;
goto V_30;
}
V_13 -> V_32 . V_33 = V_23 ;
if ( V_12 -> V_32 . V_8 == V_9 ) {
F_1 ( & V_12 -> V_40 , & V_13 -> V_41 , V_5 ) ;
} else {
T_2 T_1 * V_42 = NULL ;
T_3 V_33 = 0 ;
int V_43 = - 1 ;
struct V_44 * V_45 = NULL ;
if ( V_12 -> V_32 . V_6 < F_12 ( V_46 ) )
V_45 = & V_46 [ V_12 -> V_32 . V_6 ] ;
if ( ! V_45 || ! V_45 -> V_47 || ! V_45 -> V_47 -> type ) {
F_13 ( & V_13 -> V_41 , V_12 -> V_32 . V_8 ,
V_12 -> V_32 . V_36 , V_48 ) ;
V_24 =
F_11 ( V_20 , V_13 , sizeof( V_13 -> V_32 ) ) ;
if ( V_24 )
V_25 = - V_31 ;
else
V_25 = 0 ;
goto V_30;
}
if ( F_14 ( & V_45 -> V_49 ) ) {
V_25 = - V_50 ;
goto V_30;
}
switch ( V_12 -> V_32 . V_36 ) {
case V_51 :
case V_52 : {
V_42 = ( T_2 T_1 * ) V_12 -> V_40 . V_53 . V_54 . V_53 . V_55 . V_56 ;
V_33 = V_12 -> V_40 . V_53 . V_54 . V_53 . V_55 . V_57 ;
if ( V_45 -> V_58 < V_33 ) {
F_10 ( V_59 ,
L_3
L_4 ,
V_12 -> V_32 . V_6 ,
V_45 -> V_58 , V_33 ) ;
if ( V_45 -> V_60 ) {
V_45 -> V_58 = 0 ;
F_15 ( V_45 -> V_60 ) ;
}
V_45 -> V_60 = F_16 ( V_33 ) ;
if ( V_45 -> V_60 )
V_45 -> V_58 = V_33 ;
else {
F_10 ( ERROR ,
L_5
L_6 ,
V_33 ) ;
F_17 ( & V_45 -> V_49 ) ;
V_25 = - V_27 ;
goto V_30;
}
}
V_12 -> V_40 . V_53 . V_54 . V_53 . V_55 . V_56 = V_45 -> V_60 ;
if ( V_12 -> V_32 . V_36 == V_52 )
V_43 = 1 ;
else
V_43 = 0 ;
break;
}
default:
V_33 = 0 ;
break;
}
if ( V_33 && ( V_43 == 0 ) ) {
V_24 =
F_9 ( V_45 -> V_60 , V_42 , V_33 ) ;
if ( V_24 )
F_10 ( V_35 ,
L_7
L_8 , V_24 ,
V_33 ) ;
}
F_1 ( & V_12 -> V_40 , & V_13 -> V_41 , V_5 ) ;
if ( V_33 && ( V_43 == 1 ) ) {
V_24 =
F_11 ( V_42 , V_45 -> V_60 , V_33 ) ;
if ( V_24 )
F_10 ( V_35 ,
L_7 L_9 ,
V_24 , V_33 ) ;
}
F_17 ( & V_45 -> V_49 ) ;
}
if ( ! V_13 -> V_32 . V_33 ) {
F_10 ( ERROR , L_10 ) ;
V_25 = - V_31 ;
goto V_30;
}
if ( V_13 -> V_32 . V_33 > V_23 ) {
F_10 ( ERROR , L_11 , V_13 -> V_32 . V_33 ,
V_23 ) ;
V_13 -> V_32 . error = V_61 ;
V_13 -> V_32 . V_62 = V_13 -> V_32 . V_33 ;
V_13 -> V_32 . V_33 = sizeof( V_13 -> V_32 ) ;
}
V_24 = F_11 ( V_20 , V_13 , V_13 -> V_32 . V_33 ) ;
if ( V_24 ) {
F_10 ( ERROR , L_1 , V_24 ) ;
V_25 = - V_31 ;
goto V_30;
}
V_30:
F_18 ( V_12 ) ;
F_18 ( V_13 ) ;
return V_25 ;
}
int F_19 ( struct V_63 * V_63 ,
const struct V_64 * V_65 )
{
int V_66 , V_67 ;
int V_6 ;
unsigned int V_68 ;
struct V_1 V_12 ;
struct V_3 V_13 ;
struct V_44 V_47 ;
struct V_69 V_70 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
F_20 ( V_71 , & V_63 -> V_72 ,
L_12 , V_63 -> V_73 ,
V_63 -> V_74 , V_63 -> V_75 ,
V_63 -> V_76 , V_63 -> V_77 ) ;
if ( F_21 ( V_63 ) < 0 ) {
F_22 ( & V_63 -> V_72 ,
L_13 ) ;
return - V_78 ;
}
F_23 ( V_63 ) ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_37 ) ;
F_13 ( & V_13 , V_9 , V_37 ,
V_79 ) ;
V_12 . V_6 = V_80 ;
V_67 = V_81 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
F_10 ( V_82 , L_14 , V_66 ,
& V_63 -> V_83 [ V_66 ] ) ;
if ( F_24 ( V_63 , V_66 ) & V_84 ) {
V_68 = F_25 ( V_63 , V_66 ) ;
V_70 . V_85 [ V_66 ] =
F_26 ( F_27 ( V_63 , V_66 ) ,
V_68 ) ;
if ( ! V_70 . V_85 [ V_66 ] ) {
F_10 ( ERROR ,
L_15 ) ;
goto V_25;
}
}
}
V_70 . V_63 = V_63 ;
V_12 . V_53 . V_86 . V_83 . V_87 = V_88 ;
V_12 . V_53 . V_86 . V_83 . V_89 . V_70 = & V_70 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error )
goto V_25;
V_6 = V_13 . V_53 . V_86 . V_6 ;
V_47 . V_47 = F_28 ( V_6 ) ;
if ( V_90 ) {
V_47 . V_60 = F_16 ( V_90 ) ;
if ( ! V_47 . V_60 ) {
F_10 ( ERROR ,
L_5
L_16 ,
V_90 ) ;
goto V_25;
}
}
F_5 ( & V_12 , & V_13 , V_91 ,
V_92 ) ;
V_12 . V_6 = V_47 . V_47 -> V_93 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
if ( V_13 . error )
goto V_25;
V_46 [ V_6 ] = V_47 ;
F_29 ( & V_46 [ V_6 ] . V_49 ) ;
F_30 ( V_63 , & V_46 [ V_6 ] ) ;
F_31 ( & V_63 -> V_72 , L_17 ,
V_47 . V_47 -> type , V_6 ) ;
return 0 ;
V_25:
for ( V_66 = 0 ; V_66 < V_81 ; V_66 ++ ) {
if ( V_70 . V_85 [ V_66 ] ) {
F_32 ( V_70 . V_85 [ V_66 ] ) ;
V_70 . V_85 [ V_66 ] = NULL ;
}
}
if ( V_47 . V_60 ) {
V_47 . V_58 = 0 ;
F_15 ( V_47 . V_60 ) ;
}
F_10 ( ERROR , L_18 ) ;
return - V_94 ;
}
void F_33 ( struct V_63 * V_63 )
{
int V_66 ;
struct V_1 V_12 ;
struct V_3 V_13 ;
struct V_44 * V_45 ;
struct V_69 V_70 ;
V_45 = F_34 ( V_63 ) ;
V_70 = V_45 -> V_47 -> V_70 ;
F_5 ( & V_12 , & V_13 , V_91 ,
V_38 ) ;
V_12 . V_6 = V_45 -> V_47 -> V_93 ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
for ( V_66 = 0 ; V_66 < V_81 ; V_66 ++ ) {
if ( V_70 . V_85 [ V_66 ] )
F_32 ( V_70 . V_85 [ V_66 ] ) ;
}
if ( V_45 -> V_60 )
F_15 ( V_45 -> V_60 ) ;
if ( 1 )
F_31 ( & V_63 -> V_72 ,
L_19 ,
V_63 -> V_73 , V_63 -> V_74 ,
V_63 -> V_75 , V_63 -> V_76 ,
V_63 -> V_77 , V_45 -> V_47 -> V_93 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
}
void T_4 F_35 ( void )
{
struct V_1 V_12 ;
struct V_3 V_13 ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
F_36 ( V_95 L_20 V_96 L_21 ) ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_97 ) ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
}
void F_37 ( void )
{
struct V_1 V_12 ;
struct V_3 V_13 ;
F_5 ( & V_12 , & V_13 , V_9 ,
V_98 ) ;
F_2 ( & V_12 , & V_13 , V_11 ) ;
}
