static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_5 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 . V_7 , V_8 L_1 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
F_5 ( V_10 , F_6 ( F_7 ( V_11 ) , V_2 -> V_4 . V_5 ) ) ;
if ( V_2 -> V_12 != V_2 -> V_4 . V_13 ) {
F_8 ( V_2 -> V_12 ) ;
F_9 ( V_2 -> V_12 ) ;
}
V_2 -> V_12 = NULL ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_14 ) {
int V_15 = - V_16 ;
int V_17 = 0 ;
V_18:
V_15 = V_2 -> V_4 . V_14 ( V_2 -> V_4 . V_19 , V_2 -> V_12 ) ;
if ( V_15 == 0 ) {
V_17 ++ ;
goto V_18;
}
if ( V_15 == - V_20 )
F_11 ( V_2 -> V_21 ) ;
return V_17 ? 0 : V_15 ;
}
return 0 ;
}
static int F_12 ( void * V_1 )
{
struct V_1 * V_2 = V_1 ;
F_4 ( V_2 -> V_4 . V_7 , V_8 L_2 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
do {
if ( V_2 -> V_22 ) {
if ( V_2 -> V_23 ) {
F_13 ( V_24 ) ;
F_14 ( V_2 -> V_23 ) ;
}
if ( F_15 () )
break;
if ( ! F_10 ( V_2 ) )
F_16 ( & V_2 -> V_12 -> V_25 ) ;
} else {
F_13 ( V_24 ) ;
F_17 () ;
}
} while ( ! F_15 () );
F_4 ( V_2 -> V_4 . V_7 , V_8 L_3 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_26 = - V_27 ;
struct V_28 * V_4 = & V_2 -> V_4 ;
struct V_29 * V_29 ;
V_29 = F_19 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
goto V_31;
if ( V_4 -> V_32 ) {
F_20 ( V_29 , V_4 -> V_32 ) ;
V_29 -> V_33 = V_4 -> V_33 ;
} else {
F_20 ( V_29 , & V_34 ) ;
V_29 -> V_33 = V_35 ;
}
V_26 = F_21 ( & V_29 -> V_36 , L_4 , V_4 -> V_5 ) ;
if ( V_26 )
goto V_31;
V_26 = F_22 ( V_29 , F_6 ( F_7 ( V_11 ) , V_4 -> V_5 ) , 1 ) ;
if ( V_26 ) {
F_23 ( & V_29 -> V_36 ) ;
goto V_31;
}
V_2 -> V_29 = V_29 ;
return 0 ;
V_31:
F_9 ( V_29 ) ;
return V_26 ;
}
int F_24 ( struct V_28 * V_4 )
{
struct V_1 * V_2 ;
int V_5 ;
int V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
int V_40 ;
if ( ! V_4 ) {
F_25 ( V_41 L_5
L_6 ) ;
V_40 = - V_42 ;
goto V_43;
}
if ( ! V_4 -> V_7 ) {
F_25 ( V_41 L_7 , V_44 ) ;
V_40 = - V_45 ;
goto V_43;
}
if ( V_46 <= V_4 -> V_5 ) {
F_26 ( V_4 -> V_7 , L_5
L_8 ,
V_46 - 1 , V_4 -> V_5 ) ;
V_40 = - V_42 ;
goto V_43;
}
if ( 1 > V_4 -> V_47 || ( V_48 * 8 ) < V_4 -> V_47 ) {
F_26 ( V_4 -> V_7 , L_5
L_9
L_10 ,
V_4 -> V_5 , V_48 * 8 ) ;
V_40 = - V_42 ;
goto V_43;
}
F_4 ( V_4 -> V_7 , L_11 ,
V_4 -> V_49 ) ;
if ( V_4 -> V_49 ) {
if ( 2 > V_4 -> V_49 || V_50 < V_4 -> V_49 ) {
F_26 ( V_4 -> V_7 , L_5
L_12 , V_50 ) ;
V_40 = - V_42 ;
goto V_43;
}
if ( ! V_4 -> V_14 ) {
F_26 ( V_4 -> V_7 , L_5
L_13
L_14 ) ;
V_40 = - V_42 ;
goto V_43;
}
} else if ( ! ( V_4 -> V_32 && V_4 -> V_32 -> V_51 ) && ! V_4 -> V_13 ) {
F_26 ( V_4 -> V_7 , L_5
L_15 ) ;
V_40 = - V_42 ;
goto V_43;
} else if ( ! V_4 -> V_13 ) {
if ( ! ( V_4 -> V_32 && V_4 -> V_32 -> V_51 && V_4 -> V_32 -> V_52 &&
V_4 -> V_32 -> V_53 ) ) {
F_26 ( V_4 -> V_7 , L_5
L_16 ) ;
V_40 = - V_42 ;
goto V_43;
}
}
F_27 ( & V_54 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 < 0 ) {
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ )
if ( ! V_55 [ V_5 ] )
break;
if ( V_46 == V_5 ) {
F_26 ( V_4 -> V_7 , L_5
L_17 ) ;
V_40 = - V_27 ;
goto V_56;
}
} else if ( V_55 [ V_5 ] ) {
F_26 ( V_4 -> V_7 , L_5
L_18 , V_5 ) ;
V_40 = - V_57 ;
goto V_56;
}
V_2 = F_19 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_2 ) {
V_40 = - V_27 ;
goto V_56;
}
F_1 ( V_2 ) ;
V_55 [ V_5 ] = V_2 ;
V_4 -> V_5 = V_5 ;
if ( V_4 -> V_49 ) {
V_2 -> V_23 = V_50 / V_4 -> V_49 ;
} else {
V_2 -> V_23 = 0 ;
}
V_4 -> V_9 [ sizeof( V_4 -> V_9 ) - 1 ] = '\0' ;
V_37 = F_28 ( V_4 -> V_47 ) +
( V_4 -> V_47 % 8 ? 1 : 0 ) ;
V_39 = V_4 -> V_39 ? V_4 -> V_39 : V_48 / V_37 ;
V_38 = V_4 -> V_38 ? V_4 -> V_38 : V_37 ;
if ( V_4 -> V_13 ) {
V_2 -> V_12 = V_4 -> V_13 ;
} else {
V_2 -> V_12 = F_29 ( sizeof( struct V_58 ) , V_30 ) ;
if ( ! V_2 -> V_12 ) {
V_40 = - V_27 ;
goto V_56;
}
V_40 = F_30 ( V_2 -> V_12 , V_38 , V_39 ) ;
if ( V_40 ) {
F_9 ( V_2 -> V_12 ) ;
goto V_56;
}
}
V_2 -> V_38 = V_2 -> V_12 -> V_38 ;
if ( V_4 -> V_59 == 0 )
V_4 -> V_59 = V_60 ;
V_2 -> V_4 = * V_4 ;
F_31 ( V_10 , V_2 -> V_4 . V_7 ,
F_6 ( F_7 ( V_11 ) , V_2 -> V_4 . V_5 ) , NULL ,
L_19 , V_2 -> V_4 . V_5 ) ;
if ( V_4 -> V_49 ) {
V_2 -> V_21 = F_32 ( F_12 , ( void * ) V_2 , L_20 ) ;
if ( F_33 ( V_2 -> V_21 ) ) {
F_26 ( V_4 -> V_7 , L_5
L_21 ,
V_4 -> V_5 ) ;
V_40 = - V_61 ;
goto V_62;
}
}
V_40 = F_18 ( V_2 ) ;
if ( V_40 )
goto V_62;
V_2 -> V_63 = 1 ;
F_34 ( & V_54 ) ;
F_35 ( V_2 -> V_4 . V_7 , L_22 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
return V_5 ;
V_62:
F_5 ( V_10 , F_6 ( F_7 ( V_11 ) , V_2 -> V_4 . V_5 ) ) ;
V_56:
F_34 ( & V_54 ) ;
V_43:
return V_40 ;
}
int F_36 ( int V_5 )
{
struct V_1 * V_2 ;
struct V_29 * V_29 ;
if ( V_5 < 0 || V_5 >= V_46 ) {
F_25 ( V_41 L_23
L_24 , V_44 , V_5 , V_46 - 1 ) ;
return - V_42 ;
}
V_2 = V_55 [ V_5 ] ;
if ( ! V_2 ) {
F_25 ( V_41 L_25
L_26 , V_44 , V_5 ) ;
return - V_64 ;
}
V_29 = V_2 -> V_29 ;
F_27 ( & V_54 ) ;
if ( V_2 -> V_4 . V_5 != V_5 ) {
F_25 ( V_41 L_27
L_28 , V_44 , V_5 ) ;
F_34 ( & V_54 ) ;
return - V_64 ;
}
if ( V_2 -> V_21 )
F_11 ( V_2 -> V_21 ) ;
F_4 ( V_2 -> V_4 . V_7 , L_29 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
V_2 -> V_63 = 0 ;
if ( V_2 -> V_22 ) {
F_4 ( V_2 -> V_4 . V_7 , V_8 L_30 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
F_16 ( & V_2 -> V_12 -> V_25 ) ;
F_27 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_65 ( V_2 -> V_4 . V_19 ) ;
F_37 ( V_29 -> V_33 ) ;
F_34 ( & V_2 -> V_3 ) ;
} else {
F_3 ( V_2 ) ;
F_38 ( V_29 ) ;
F_9 ( V_29 ) ;
F_9 ( V_2 ) ;
V_55 [ V_5 ] = NULL ;
}
F_34 ( & V_54 ) ;
return 0 ;
}
int F_39 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
struct V_1 * V_2 ;
struct V_29 * V_29 ;
int V_26 = 0 ;
if ( F_40 ( V_66 ) >= V_46 ) {
F_25 ( V_68 L_31 ,
F_40 ( V_66 ) ) ;
return - V_20 ;
}
if ( F_41 ( & V_54 ) )
return - V_69 ;
V_2 = V_55 [ F_40 ( V_66 ) ] ;
if ( ! V_2 ) {
V_26 = - V_20 ;
goto error;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_32 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
if ( V_2 -> V_4 . V_5 == V_6 ) {
V_26 = - V_20 ;
goto error;
}
if ( V_2 -> V_22 ) {
V_26 = - V_57 ;
goto error;
}
V_29 = V_2 -> V_29 ;
if ( F_42 ( V_29 -> V_33 ) ) {
V_2 -> V_22 ++ ;
V_26 = V_2 -> V_4 . V_70 ( V_2 -> V_4 . V_19 ) ;
if ( V_26 ) {
F_37 ( V_29 -> V_33 ) ;
V_2 -> V_22 -- ;
} else {
F_43 ( V_2 -> V_12 ) ;
}
if ( V_2 -> V_21 )
F_44 ( V_2 -> V_21 ) ;
}
error:
if ( V_2 )
F_4 ( V_2 -> V_4 . V_7 , V_8 L_33 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 , V_26 ) ;
F_34 ( & V_54 ) ;
F_45 ( V_66 , V_67 ) ;
return V_26 ;
}
int F_46 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
struct V_1 * V_2 = V_55 [ F_40 ( V_66 ) ] ;
struct V_29 * V_29 ;
if ( ! V_2 ) {
F_25 ( V_41 L_34 , V_44 ) ;
return - V_45 ;
}
V_29 = V_2 -> V_29 ;
F_4 ( V_2 -> V_4 . V_7 , V_8 L_35 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
F_47 ( F_48 ( & V_54 ) ) ;
V_2 -> V_22 -- ;
if ( V_2 -> V_63 ) {
V_2 -> V_4 . V_65 ( V_2 -> V_4 . V_19 ) ;
F_37 ( V_29 -> V_33 ) ;
} else {
F_3 ( V_2 ) ;
F_38 ( V_29 ) ;
V_55 [ V_2 -> V_4 . V_5 ] = NULL ;
F_9 ( V_29 ) ;
F_9 ( V_2 ) ;
}
F_34 ( & V_54 ) ;
return 0 ;
}
unsigned int F_49 ( struct V_67 * V_67 , T_1 * V_71 )
{
struct V_1 * V_2 = V_55 [ F_40 ( V_67 -> V_72 -> V_73 ) ] ;
unsigned int V_74 ;
if ( ! V_2 ) {
F_25 ( V_41 L_34 , V_44 ) ;
return V_75 ;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_36 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
if ( ! V_2 -> V_63 )
return V_75 ;
F_50 ( V_67 , & V_2 -> V_12 -> V_25 , V_71 ) ;
if ( V_2 -> V_12 )
if ( F_51 ( V_2 -> V_12 ) )
V_74 = 0 ;
else
V_74 = V_76 | V_77 ;
else
V_74 = V_75 ;
F_4 ( V_2 -> V_4 . V_7 , V_8 L_37 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 , V_74 ) ;
return V_74 ;
}
long F_52 ( struct V_67 * V_67 , unsigned int V_78 , unsigned long V_79 )
{
T_2 V_80 ;
int V_81 = 0 ;
struct V_1 * V_2 = V_55 [ F_40 ( V_67 -> V_72 -> V_73 ) ] ;
if ( ! V_2 ) {
F_25 ( V_41 L_38 , V_44 ) ;
return - V_20 ;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_39 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 , V_78 ) ;
if ( V_2 -> V_4 . V_5 == V_6 || ! V_2 -> V_63 ) {
F_4 ( V_2 -> V_4 . V_7 , V_8 L_40 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
return - V_20 ;
}
F_27 ( & V_2 -> V_3 ) ;
switch ( V_78 ) {
case V_82 :
V_81 = F_53 ( V_2 -> V_4 . V_59 , ( T_2 * ) V_79 ) ;
break;
case V_83 :
if ( ! ( V_2 -> V_4 . V_59 & V_84 ) ) {
V_81 = - V_85 ;
break;
}
V_81 = F_53 ( F_54
( V_2 -> V_4 . V_59 & V_84 ) ,
( T_2 * ) V_79 ) ;
break;
case V_86 :
if ( ! ( V_2 -> V_4 . V_59 & V_84 ) ) {
V_81 = - V_85 ;
break;
}
V_81 = F_55 ( V_80 , ( T_2 * ) V_79 ) ;
if ( ! V_81 && ! ( F_56 ( V_80 ) & V_2 -> V_4 . V_59 ) )
V_81 = - V_45 ;
break;
case V_87 :
V_81 = F_53 ( V_2 -> V_4 . V_47 , ( T_2 * ) V_79 ) ;
break;
case V_88 :
if ( ! ( V_2 -> V_4 . V_59 & V_89 ) ||
V_2 -> V_4 . V_90 == 0 ) {
V_81 = - V_85 ;
break;
}
V_81 = F_53 ( V_2 -> V_4 . V_90 , ( T_2 * ) V_79 ) ;
break;
case V_91 :
if ( ! ( V_2 -> V_4 . V_59 & V_89 ) ||
V_2 -> V_4 . V_92 == 0 ) {
V_81 = - V_85 ;
break;
}
V_81 = F_53 ( V_2 -> V_4 . V_92 , ( T_2 * ) V_79 ) ;
break;
default:
V_81 = - V_45 ;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_41 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 , V_81 ) ;
F_34 ( & V_2 -> V_3 ) ;
return V_81 ;
}
T_3 F_57 ( struct V_67 * V_67 ,
char T_4 * V_93 ,
T_5 V_94 ,
T_6 * V_95 )
{
struct V_1 * V_2 = V_55 [ F_40 ( V_67 -> V_72 -> V_73 ) ] ;
unsigned char * V_12 ;
int V_74 = 0 , V_96 = 0 ;
F_58 ( V_71 , V_97 ) ;
if ( ! V_2 ) {
F_25 ( V_41 L_34 , V_44 ) ;
return - V_20 ;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_42 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
V_12 = F_19 ( V_2 -> V_38 , V_30 ) ;
if ( ! V_12 )
return - V_27 ;
if ( F_41 ( & V_2 -> V_3 ) ) {
V_74 = - V_69 ;
goto V_98;
}
if ( ! V_2 -> V_63 ) {
V_74 = - V_20 ;
goto V_99;
}
if ( V_94 % V_2 -> V_38 ) {
V_74 = - V_45 ;
goto V_99;
}
F_59 ( & V_2 -> V_12 -> V_25 , & V_71 ) ;
F_13 ( V_24 ) ;
while ( V_96 < V_94 && V_74 == 0 ) {
if ( F_51 ( V_2 -> V_12 ) ) {
if ( V_96 )
break;
if ( V_67 -> V_100 & V_101 ) {
V_74 = - V_102 ;
break;
}
if ( F_60 ( V_97 ) ) {
V_74 = - V_69 ;
break;
}
F_34 ( & V_2 -> V_3 ) ;
F_17 () ;
F_13 ( V_24 ) ;
if ( F_41 ( & V_2 -> V_3 ) ) {
V_74 = - V_69 ;
F_61 ( & V_2 -> V_12 -> V_25 , & V_71 ) ;
F_13 ( V_103 ) ;
goto V_98;
}
if ( ! V_2 -> V_63 ) {
V_74 = - V_20 ;
break;
}
} else {
F_62 ( V_2 -> V_12 , V_12 ) ;
V_74 = F_63 ( ( void * ) V_93 + V_96 , V_12 ,
V_2 -> V_12 -> V_38 ) ;
if ( ! V_74 )
V_96 += V_2 -> V_12 -> V_38 ;
else
V_74 = - V_104 ;
}
}
F_61 ( & V_2 -> V_12 -> V_25 , & V_71 ) ;
F_13 ( V_103 ) ;
V_99:
F_34 ( & V_2 -> V_3 ) ;
V_98:
F_9 ( V_12 ) ;
F_4 ( V_2 -> V_4 . V_7 , V_8 L_43 ,
V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 , V_74 ? L_44 : L_45 , V_74 ) ;
return V_74 ? V_74 : V_96 ;
}
void * F_64 ( struct V_67 * V_67 )
{
void * V_19 = NULL ;
if ( V_67 && V_67 -> V_72 && V_67 -> V_72 -> V_73 &&
V_67 -> V_72 -> V_73 -> V_105 ) {
struct V_1 * V_2 ;
V_2 = V_55 [ F_40 ( V_67 -> V_72 -> V_73 ) ] ;
V_19 = V_2 -> V_4 . V_19 ;
}
return V_19 ;
}
T_3 F_65 ( struct V_67 * V_67 , const char T_4 * V_93 ,
T_5 V_94 , T_6 * V_95 )
{
struct V_1 * V_2 = V_55 [ F_40 ( V_67 -> V_72 -> V_73 ) ] ;
if ( ! V_2 ) {
F_25 ( V_41 L_34 , V_44 ) ;
return - V_20 ;
}
F_4 ( V_2 -> V_4 . V_7 , V_8 L_46 , V_2 -> V_4 . V_9 , V_2 -> V_4 . V_5 ) ;
if ( ! V_2 -> V_63 )
return - V_20 ;
return - V_45 ;
}
static int T_7 F_66 ( void )
{
int V_26 ;
V_10 = F_67 ( V_35 , L_47 ) ;
if ( F_33 ( V_10 ) ) {
V_26 = F_68 ( V_10 ) ;
F_25 ( V_41 L_48 ) ;
goto error;
}
V_26 = F_69 ( & V_11 , 0 , V_46 ,
V_106 ) ;
if ( V_26 ) {
F_70 ( V_10 ) ;
F_25 ( V_41 L_49 ) ;
goto error;
}
F_25 ( V_107 L_50
L_51 , F_7 ( V_11 ) ) ;
error:
return V_26 ;
}
static void T_8 F_71 ( void )
{
F_70 ( V_10 ) ;
F_72 ( V_11 , V_46 ) ;
F_25 ( V_107 L_52 ) ;
}
