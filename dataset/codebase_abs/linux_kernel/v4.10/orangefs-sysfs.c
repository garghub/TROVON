static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_3 ;
V_3 = F_2 ( V_4 , struct V_6 , V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_8 ;
return V_3 -> V_7 ( V_2 , V_3 , V_5 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_9 )
{
struct V_6 * V_3 ;
if ( ! strcmp ( V_2 -> V_10 , V_11 ) ||
! strcmp ( V_2 -> V_10 , V_12 ) )
return - V_13 ;
V_3 = F_2 ( V_4 , struct V_6 , V_4 ) ;
if ( ! V_3 -> V_14 )
return - V_8 ;
return V_3 -> V_14 ( V_2 , V_3 , V_5 , V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_6 * V_4 , char * V_5 )
{
int V_15 = - V_8 ;
F_5 ( V_16 , L_1 ,
V_2 -> V_10 ) ;
if ( ! strcmp ( V_2 -> V_10 , V_17 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_2 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_3 ,
V_19 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_4 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_3 ,
V_21 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_5 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_3 ,
V_22 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_6 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_3 ,
V_23 ) ;
goto V_20;
} else {
goto V_20;
}
} else if ( ! strcmp ( V_2 -> V_10 , V_12 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_7 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_8 ,
V_24 . V_25 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_9 ) ) {
V_15 = F_6 ( V_5 ,
V_18 ,
L_8 ,
V_24 . V_26 ) ;
goto V_20;
} else {
goto V_20;
}
}
V_20:
return V_15 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_6 * V_4 , const char * V_5 , T_2 V_27 )
{
int V_15 = 0 ;
F_5 ( V_16 ,
L_10 ,
V_4 -> V_4 . V_10 , V_5 ) ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_2 ) ) {
V_15 = F_8 ( V_5 , 0 , & V_19 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_4 ) ) {
V_15 = F_8 ( V_5 , 0 , & V_21 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_5 ) ) {
V_15 = F_8 ( V_5 , 0 , & V_22 ) ;
goto V_20;
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_6 ) ) {
V_15 = F_8 ( V_5 , 0 , & V_23 ) ;
goto V_20;
} else {
goto V_20;
}
V_20:
if ( V_15 )
V_15 = - V_28 ;
else
V_15 = V_27 ;
return V_15 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_6 * V_4 , char * V_5 )
{
struct V_29 * V_30 = NULL ;
int V_15 = 0 ;
char * V_31 = NULL ;
T_3 V_32 ;
F_5 ( V_16 ,
L_11 ,
V_2 -> V_10 ) ;
if ( strcmp ( V_2 -> V_10 , V_11 ) )
V_32 = V_33 ;
else
V_32 = V_34 ;
V_30 = F_10 ( V_32 ) ;
if ( ! V_30 )
return - V_35 ;
V_15 = F_11 () ;
if ( V_15 ) {
F_12 ( L_12 ,
V_36 ,
F_11 () ) ;
goto V_20;
}
if ( strcmp ( V_2 -> V_10 , V_11 ) )
V_30 -> V_37 . V_38 . V_39 . type = V_40 ;
if ( ! strcmp ( V_2 -> V_10 , V_17 ) ) {
if ( ! ( V_41 & V_42 ) &&
( ! strcmp ( V_4 -> V_4 . V_10 , L_13 ) ||
! strcmp ( V_4 -> V_4 . V_10 , L_14 ) ||
! strcmp ( V_4 -> V_4 . V_10 , L_15 ) ) ) {
V_15 = - V_28 ;
goto V_20;
}
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_16 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_44 ;
else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_17 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_45 ;
else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_18 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_46 ;
else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_13 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_47 ;
else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_14 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_48 ;
else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_15 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_49 ;
} else if ( ! strcmp ( V_2 -> V_10 , V_50 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_19 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_51 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_52 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_53 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_22 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_54 ;
} else if ( ! strcmp ( V_2 -> V_10 , V_55 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_23 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_56 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_57 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_58 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_22 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_59 ;
} else if ( ! strcmp ( V_2 -> V_10 , V_60 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_23 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_61 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_62 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_63 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_22 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_64 ;
} else if ( ! strcmp ( V_2 -> V_10 , V_65 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_19 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_66 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_67 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_68 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_22 ) )
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_69 ;
} else if ( ! strcmp ( V_2 -> V_10 , V_11 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , V_50 ) )
V_30 -> V_37 . V_38 . V_70 . type =
V_71 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , V_55 ) )
V_30 -> V_37 . V_38 . V_70 . type =
V_72 ;
if ( ! strcmp ( V_4 -> V_4 . V_10 , V_65 ) )
V_30 -> V_37 . V_38 . V_70 . type =
V_73 ;
} else {
F_13 ( L_24 ,
V_2 -> V_10 ) ;
V_15 = - V_28 ;
goto V_20;
}
if ( strcmp ( V_2 -> V_10 , V_11 ) )
V_31 = L_25 ;
else
V_31 = L_26 ;
V_15 = F_14 ( V_30 , V_31 , V_74 ) ;
V_20:
if ( ! V_15 ) {
if ( strcmp ( V_2 -> V_10 , V_11 ) ) {
if ( V_30 -> V_37 . V_38 . V_39 . V_43 ==
V_49 ) {
V_15 = F_6 ( V_5 , V_18 , L_27 ,
( int ) V_30 -> V_75 . V_76 . V_39 . V_77 .
V_78 [ 0 ] ,
( int ) V_30 -> V_75 . V_76 . V_39 . V_77 .
V_78 [ 1 ] ) ;
} else {
V_15 = F_6 ( V_5 , V_18 , L_3 ,
( int ) V_30 -> V_75 . V_76 . V_39 . V_77 . V_79 ) ;
}
} else {
V_15 = F_6 (
V_5 ,
V_18 ,
L_28 ,
V_30 -> V_75 . V_76 . V_70 . V_80 ) ;
}
}
F_15 ( V_30 ) ;
return V_15 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_6 * V_4 , const char * V_5 , T_2 V_27 )
{
struct V_29 * V_30 = NULL ;
int V_81 = 0 ;
int V_15 = 0 ;
F_5 ( V_16 ,
L_29 ,
V_2 -> V_10 ) ;
V_30 = F_10 ( V_33 ) ;
if ( ! V_30 )
return - V_28 ;
V_15 = F_11 () ;
if ( V_15 ) {
F_12 ( L_12 ,
V_36 ,
F_11 () ) ;
goto V_20;
}
if ( strcmp ( V_2 -> V_10 , V_17 ) ||
strcmp ( V_4 -> V_4 . V_10 , L_15 ) ) {
V_15 = F_8 ( V_5 , 0 , & V_81 ) ;
if ( V_15 )
goto V_20;
}
V_30 -> V_37 . V_38 . V_39 . type = V_82 ;
if ( ! strcmp ( V_2 -> V_10 , V_17 ) ) {
if ( ! ( V_41 & V_42 ) &&
( ! strcmp ( V_4 -> V_4 . V_10 , L_13 ) ||
! strcmp ( V_4 -> V_4 . V_10 , L_14 ) ||
! strcmp ( V_4 -> V_4 . V_10 , L_15 ) ) ) {
V_15 = - V_28 ;
goto V_20;
}
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_16 ) ) {
if ( V_81 > 0 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_44 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_17 ) ) {
if ( V_81 > 0 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_45 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_18 ) ) {
if ( ( V_81 == 0 ) || ( V_81 == 1 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_46 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_13 ) ) {
if ( ( V_81 >= 0 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_47 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_14 ) ) {
if ( ( V_81 >= 0 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_48 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_15 ) ) {
int V_83 , V_84 ;
V_15 = sscanf ( V_5 , L_30 , & V_83 , & V_84 ) ;
if ( V_15 < 2 ) {
V_15 = 0 ;
goto V_20;
}
if ( ( V_83 >= 0 ) && ( V_84 >= 0 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_49 ;
} else {
V_15 = 0 ;
goto V_20;
}
V_30 -> V_37 . V_38 . V_39 . V_77 . V_78 [ 0 ] = V_83 ;
V_30 -> V_37 . V_38 . V_39 . V_77 . V_78 [ 1 ] = V_84 ;
goto V_85;
}
} else if ( ! strcmp ( V_2 -> V_10 , V_50 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_52 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_53 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_22 ) ) {
if ( ( V_81 > - 1 ) && ( V_81 < 101 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_54 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_19 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_51 ;
} else {
V_15 = 0 ;
goto V_20;
}
}
} else if ( ! strcmp ( V_2 -> V_10 , V_55 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_57 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_58 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_22 ) ) {
if ( ( V_81 > - 1 ) && ( V_81 < 101 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_59 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_23 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_56 ;
} else {
V_15 = 0 ;
goto V_20;
}
}
} else if ( ! strcmp ( V_2 -> V_10 , V_60 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_62 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_63 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_22 ) ) {
if ( ( V_81 > - 1 ) && ( V_81 < 101 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_64 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_23 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_61 ;
} else {
V_15 = 0 ;
goto V_20;
}
}
} else if ( ! strcmp ( V_2 -> V_10 , V_65 ) ) {
if ( ! strcmp ( V_4 -> V_4 . V_10 , L_20 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_67 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_21 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_68 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 ,
L_22 ) ) {
if ( ( V_81 > - 1 ) && ( V_81 < 101 ) ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_69 ;
} else {
V_15 = 0 ;
goto V_20;
}
} else if ( ! strcmp ( V_4 -> V_4 . V_10 , L_19 ) ) {
if ( V_81 > - 1 ) {
V_30 -> V_37 . V_38 . V_39 . V_43 =
V_66 ;
} else {
V_15 = 0 ;
goto V_20;
}
}
} else {
F_13 ( L_31 ,
V_2 -> V_10 ) ;
V_15 = - V_28 ;
goto V_20;
}
V_30 -> V_37 . V_38 . V_39 . V_77 . V_79 = V_81 ;
V_85:
V_15 = F_14 ( V_30 , L_25 , V_74 ) ;
if ( V_15 < 0 ) {
F_13 ( L_32 ,
V_15 ) ;
V_15 = 0 ;
} else {
V_15 = V_27 ;
}
V_20:
F_15 ( V_30 ) ;
if ( V_15 == - V_35 || V_15 == 0 )
V_15 = - V_28 ;
return V_15 ;
}
int F_17 ( void )
{
int V_15 = - V_28 ;
F_5 ( V_16 , L_33 ) ;
V_86 = F_18 ( sizeof( * V_86 ) , V_87 ) ;
if ( ! V_86 )
goto V_20;
V_15 = F_19 ( V_86 ,
& V_88 ,
V_89 ,
V_17 ) ;
if ( V_15 )
goto V_90;
F_20 ( V_86 , V_91 ) ;
V_92 = F_18 ( sizeof( * V_92 ) , V_87 ) ;
if ( ! V_92 ) {
V_15 = - V_28 ;
goto V_90;
}
V_15 = F_19 ( V_92 ,
& V_93 ,
V_86 ,
V_50 ) ;
if ( V_15 )
goto V_94;
F_20 ( V_92 , V_91 ) ;
V_95 =
F_18 ( sizeof( * V_95 ) , V_87 ) ;
if ( ! V_95 ) {
V_15 = - V_28 ;
goto V_94;
}
V_15 = F_19 ( V_95 ,
& V_96 ,
V_86 ,
V_55 ) ;
if ( V_15 )
goto V_97;
F_20 ( V_95 , V_91 ) ;
V_98 =
F_18 ( sizeof( * V_98 ) , V_87 ) ;
if ( ! V_98 ) {
V_15 = - V_28 ;
goto V_97;
}
V_15 = F_19 ( V_98 ,
& V_99 ,
V_86 ,
V_60 ) ;
if ( V_15 )
goto V_100;
F_20 ( V_98 , V_91 ) ;
V_101 = F_18 ( sizeof( * V_101 ) , V_87 ) ;
if ( ! V_101 ) {
V_15 = - V_28 ;
goto V_100;
}
V_15 = F_19 ( V_101 ,
& V_102 ,
V_86 ,
V_65 ) ;
if ( V_15 )
goto V_103;
F_20 ( V_101 , V_91 ) ;
V_104 = F_18 ( sizeof( * V_104 ) , V_87 ) ;
if ( ! V_104 ) {
V_15 = - V_28 ;
goto V_103;
}
V_15 = F_19 ( V_104 ,
& V_105 ,
V_86 ,
L_34 ) ;
if ( V_15 )
goto V_106;
F_20 ( V_104 , V_91 ) ;
V_107 = F_18 ( sizeof( * V_107 ) , V_87 ) ;
if ( ! V_107 ) {
V_15 = - V_28 ;
goto V_106;
}
V_15 = F_19 ( V_107 ,
& V_108 ,
V_86 ,
V_12 ) ;
if ( V_15 )
goto V_109;
F_20 ( V_107 , V_91 ) ;
goto V_20;
V_109:
F_21 ( V_107 ) ;
V_106:
F_21 ( V_104 ) ;
V_103:
F_21 ( V_101 ) ;
V_100:
F_21 ( V_98 ) ;
V_97:
F_21 ( V_95 ) ;
V_94:
F_21 ( V_92 ) ;
V_90:
F_21 ( V_86 ) ;
V_20:
return V_15 ;
}
void F_22 ( void )
{
F_5 ( V_16 , L_35 ) ;
F_21 ( V_92 ) ;
F_21 ( V_95 ) ;
F_21 ( V_98 ) ;
F_21 ( V_101 ) ;
F_21 ( V_104 ) ;
F_21 ( V_107 ) ;
F_21 ( V_86 ) ;
}
