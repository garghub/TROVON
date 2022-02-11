static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_5 = V_6 ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 , struct V_1 , V_9 ) ;
F_5 ( V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != V_2 -> V_4 . V_12 ) {
F_6 ( V_2 -> V_11 ) ;
F_7 ( V_2 -> V_11 ) ;
}
F_8 ( & V_13 ) ;
V_14 [ V_2 -> V_4 . V_5 ] = NULL ;
F_9 ( & V_13 ) ;
F_7 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_15 ;
int V_16 = - 1 ;
if ( ! V_2 -> V_4 . V_17 )
return 0 ;
do {
V_16 ++ ;
V_15 = V_2 -> V_4 . V_17 ( V_2 -> V_4 . V_18 , V_2 -> V_11 ) ;
} while ( ! V_15 );
if ( V_15 == - V_19 )
F_11 ( V_2 -> V_20 ) ;
return V_16 ? 0 : V_15 ;
}
static int F_12 ( void * V_1 )
{
struct V_1 * V_2 = V_1 ;
do {
if ( V_2 -> V_21 ) {
if ( V_2 -> V_22 ) {
F_13 ( V_23 ) ;
F_14 ( V_2 -> V_22 ) ;
}
if ( F_15 () )
break;
if ( ! F_10 ( V_2 ) )
F_16 ( & V_2 -> V_11 -> V_24 ) ;
} else {
F_13 ( V_23 ) ;
F_17 () ;
}
} while ( ! F_15 () );
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_25 * V_4 = & V_2 -> V_4 ;
struct V_26 * V_26 ;
int V_27 ;
V_26 = & V_2 -> V_26 ;
if ( V_4 -> V_28 ) {
F_19 ( V_26 , V_4 -> V_28 ) ;
V_26 -> V_29 = V_4 -> V_29 ;
} else {
F_19 ( V_26 , & V_30 ) ;
V_26 -> V_29 = V_31 ;
}
V_27 = F_20 ( & V_26 -> V_32 , L_1 , V_4 -> V_5 ) ;
if ( V_27 )
return V_27 ;
V_26 -> V_32 . V_10 = & V_2 -> V_9 . V_32 ;
return F_21 ( V_26 , V_2 -> V_9 . V_33 , 1 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
struct V_25 * V_4 = & V_2 -> V_4 ;
F_8 ( & V_13 ) ;
V_35 = F_23 ( V_4 -> V_38 ) +
( V_4 -> V_38 % 8 ? 1 : 0 ) ;
V_37 = V_4 -> V_37 ? V_4 -> V_37 : V_39 / V_35 ;
V_36 = V_4 -> V_36 ? V_4 -> V_36 : V_35 ;
if ( V_4 -> V_12 ) {
V_2 -> V_11 = V_4 -> V_12 ;
} else {
V_2 -> V_11 = F_24 ( sizeof( struct V_40 ) , V_41 ) ;
if ( ! V_2 -> V_11 ) {
V_34 = - V_42 ;
goto V_43;
}
V_34 = F_25 ( V_2 -> V_11 , V_36 , V_37 ) ;
if ( V_34 ) {
F_7 ( V_2 -> V_11 ) ;
goto V_43;
}
}
V_2 -> V_36 = V_2 -> V_11 -> V_36 ;
V_43:
F_9 ( & V_13 ) ;
return V_34 ;
}
static int F_26 ( struct V_25 * V_4 )
{
struct V_1 * V_2 ;
int V_5 ;
int V_34 ;
if ( ! V_4 ) {
F_27 ( L_2 ) ;
return - V_44 ;
}
if ( ! V_4 -> V_9 ) {
F_27 ( L_3 ) ;
return - V_45 ;
}
if ( V_4 -> V_5 >= V_46 ) {
F_28 ( V_4 -> V_9 , L_4 ,
V_46 - 1 ) ;
return - V_44 ;
}
if ( V_4 -> V_38 < 1 || V_4 -> V_38 > ( V_39 * 8 ) ) {
F_28 ( V_4 -> V_9 , L_5 ,
V_39 * 8 ) ;
return - V_44 ;
}
if ( V_4 -> V_47 ) {
if ( 2 > V_4 -> V_47 || V_48 < V_4 -> V_47 ) {
F_28 ( V_4 -> V_9 , L_6 ,
V_4 -> V_47 ) ;
return - V_44 ;
}
if ( ! V_4 -> V_17 ) {
F_28 ( V_4 -> V_9 , L_7 ) ;
return - V_44 ;
}
} else if ( ! V_4 -> V_12 && ! ( V_4 -> V_28 && V_4 -> V_28 -> V_49 &&
V_4 -> V_28 -> V_50 && V_4 -> V_28 -> V_51 ) ) {
F_28 ( V_4 -> V_9 , L_8 ) ;
return - V_44 ;
}
F_8 ( & V_13 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 < 0 ) {
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ )
if ( ! V_14 [ V_5 ] )
break;
if ( V_5 == V_46 ) {
F_28 ( V_4 -> V_9 , L_9 ) ;
V_34 = - V_42 ;
goto V_52;
}
} else if ( V_14 [ V_5 ] ) {
F_28 ( V_4 -> V_9 , L_10 , V_5 ) ;
V_34 = - V_53 ;
goto V_52;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
V_34 = - V_42 ;
goto V_52;
}
F_1 ( V_2 ) ;
V_14 [ V_5 ] = V_2 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_54 [ sizeof( V_4 -> V_54 ) - 1 ] = '\0' ;
if ( V_4 -> V_55 == 0 )
V_4 -> V_55 = V_56 ;
V_2 -> V_4 = * V_4 ;
V_2 -> V_9 . V_33 = F_30 ( F_31 ( V_57 ) , V_2 -> V_4 . V_5 ) ;
V_2 -> V_9 . V_58 = V_59 ;
V_2 -> V_9 . V_10 = V_4 -> V_9 ;
V_2 -> V_9 . V_60 = F_3 ;
F_32 ( & V_2 -> V_9 , L_1 , V_2 -> V_4 . V_5 ) ;
F_33 ( & V_2 -> V_9 ) ;
if ( V_4 -> V_47 ) {
V_2 -> V_22 = V_48 / V_4 -> V_47 ;
V_2 -> V_20 = F_34 ( F_12 , ( void * ) V_2 , L_11 ) ;
if ( F_35 ( V_2 -> V_20 ) ) {
F_28 ( V_4 -> V_9 , L_12 ,
V_4 -> V_5 ) ;
V_34 = - V_61 ;
goto V_62;
}
} else {
V_2 -> V_22 = 0 ;
}
V_34 = F_18 ( V_2 ) ;
if ( V_34 )
goto V_62;
V_2 -> V_63 = 1 ;
V_34 = F_36 ( & V_2 -> V_9 ) ;
if ( V_34 )
goto V_64;
F_9 ( & V_13 ) ;
F_37 ( V_2 -> V_9 . V_10 ) ;
F_38 ( V_2 -> V_4 . V_9 , L_13 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
return V_5 ;
V_64:
F_39 ( & V_2 -> V_26 ) ;
V_62:
F_5 ( & V_2 -> V_9 ) ;
V_52:
F_9 ( & V_13 ) ;
return V_34 ;
}
int F_40 ( struct V_25 * V_4 )
{
int V_5 , V_34 = 0 ;
V_5 = F_26 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_41 ( V_4 -> V_55 ) ) {
V_34 = F_22 ( V_14 [ V_5 ] ) ;
if ( V_34 )
F_42 ( V_5 ) ;
}
return V_34 ? V_34 : V_5 ;
}
int F_42 ( int V_5 )
{
struct V_1 * V_2 ;
if ( V_5 < 0 || V_5 >= V_46 ) {
F_27 ( L_14 ,
V_5 , V_46 - 1 ) ;
return - V_44 ;
}
V_2 = V_14 [ V_5 ] ;
if ( ! V_2 ) {
F_27 ( L_15 ) ;
return - V_65 ;
}
F_8 ( & V_13 ) ;
if ( V_2 -> V_4 . V_5 != V_5 ) {
F_28 ( V_2 -> V_4 . V_9 , L_16 ,
V_5 ) ;
F_9 ( & V_13 ) ;
return - V_65 ;
}
if ( V_2 -> V_20 )
F_11 ( V_2 -> V_20 ) ;
F_43 ( V_2 -> V_4 . V_9 , L_17 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
V_2 -> V_63 = 0 ;
if ( V_2 -> V_21 ) {
F_43 ( V_2 -> V_4 . V_9 , V_66 L_18 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
F_16 ( & V_2 -> V_11 -> V_24 ) ;
}
F_8 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 . V_67 )
V_2 -> V_4 . V_67 ( V_2 -> V_4 . V_18 ) ;
F_9 ( & V_2 -> V_3 ) ;
F_9 ( & V_13 ) ;
F_44 ( & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_9 ) ;
return 0 ;
}
int F_45 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( F_46 ( V_68 ) >= V_46 ) {
F_27 ( L_19 , F_46 ( V_68 ) ) ;
return - V_19 ;
}
if ( F_47 ( & V_13 ) )
return - V_70 ;
V_2 = V_14 [ F_46 ( V_68 ) ] ;
F_9 ( & V_13 ) ;
if ( ! V_2 ) {
V_27 = - V_19 ;
goto error;
}
F_43 ( V_2 -> V_4 . V_9 , V_66 L_20 , V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
if ( V_2 -> V_4 . V_5 == V_6 ) {
V_27 = - V_19 ;
goto error;
}
if ( V_2 -> V_21 ) {
V_27 = - V_53 ;
goto error;
}
if ( V_2 -> V_4 . V_71 ) {
V_27 = F_48 ( V_2 -> V_4 . V_71 ) ;
if ( V_27 )
goto error;
}
V_2 -> V_21 ++ ;
if ( V_2 -> V_4 . V_72 )
V_27 = V_2 -> V_4 . V_72 ( V_2 -> V_4 . V_18 ) ;
if ( V_27 ) {
V_2 -> V_21 -- ;
} else {
if ( V_2 -> V_11 )
F_49 ( V_2 -> V_11 ) ;
if ( V_2 -> V_20 )
F_50 ( V_2 -> V_20 ) ;
}
error:
F_51 ( V_68 , V_69 ) ;
return V_27 ;
}
int F_52 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_1 * V_2 = V_14 [ F_46 ( V_68 ) ] ;
int V_73 ;
if ( ! V_2 ) {
F_27 ( L_21 ) ;
return - V_45 ;
}
V_73 = F_53 ( & V_13 ) ;
F_54 ( V_73 ) ;
F_55 ( V_2 -> V_4 . V_71 ) ;
V_2 -> V_21 -- ;
if ( V_2 -> V_4 . V_67 )
V_2 -> V_4 . V_67 ( V_2 -> V_4 . V_18 ) ;
if ( ! V_73 )
F_9 ( & V_13 ) ;
return 0 ;
}
unsigned int F_56 ( struct V_69 * V_69 , T_1 * V_74 )
{
struct V_1 * V_2 = V_14 [ F_46 ( F_57 ( V_69 ) ) ] ;
unsigned int V_73 ;
if ( ! V_2 ) {
F_27 ( L_21 ) ;
return V_75 ;
}
if ( ! V_2 -> V_63 )
return V_75 ;
if ( V_2 -> V_11 ) {
F_58 ( V_69 , & V_2 -> V_11 -> V_24 , V_74 ) ;
if ( F_59 ( V_2 -> V_11 ) )
V_73 = 0 ;
else
V_73 = V_76 | V_77 ;
} else
V_73 = V_75 ;
F_43 ( V_2 -> V_4 . V_9 , V_66 L_22 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 , V_73 ) ;
return V_73 ;
}
long F_60 ( struct V_69 * V_69 , unsigned int V_78 , unsigned long V_79 )
{
T_2 V_80 ;
int V_81 = 0 ;
struct V_1 * V_2 = V_14 [ F_46 ( F_57 ( V_69 ) ) ] ;
if ( ! V_2 ) {
F_27 ( L_23 ) ;
return - V_19 ;
}
F_43 ( V_2 -> V_4 . V_9 , V_66 L_24 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 , V_78 ) ;
if ( V_2 -> V_4 . V_5 == V_6 || ! V_2 -> V_63 ) {
F_28 ( V_2 -> V_4 . V_9 , V_66 L_25 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
return - V_19 ;
}
F_8 ( & V_2 -> V_3 ) ;
switch ( V_78 ) {
case V_82 :
V_81 = F_61 ( V_2 -> V_4 . V_55 , ( T_2 V_83 * ) V_79 ) ;
break;
case V_84 :
if ( ! F_41 ( V_2 -> V_4 . V_55 ) ) {
V_81 = - V_85 ;
break;
}
V_81 = F_61 ( F_62
( V_2 -> V_4 . V_55 & V_86 ) ,
( T_2 V_83 * ) V_79 ) ;
break;
case V_87 :
if ( ! F_41 ( V_2 -> V_4 . V_55 ) ) {
V_81 = - V_85 ;
break;
}
V_81 = F_63 ( V_80 , ( T_2 V_83 * ) V_79 ) ;
if ( ! V_81 && ! ( F_64 ( V_80 ) & V_2 -> V_4 . V_55 ) )
V_81 = - V_45 ;
break;
case V_88 :
V_81 = F_61 ( V_2 -> V_4 . V_38 , ( T_2 V_83 * ) V_79 ) ;
break;
case V_89 :
if ( ! ( V_2 -> V_4 . V_55 & V_90 ) ||
V_2 -> V_4 . V_91 == 0 ) {
V_81 = - V_85 ;
break;
}
V_81 = F_61 ( V_2 -> V_4 . V_91 , ( T_2 V_83 * ) V_79 ) ;
break;
case V_92 :
if ( ! ( V_2 -> V_4 . V_55 & V_90 ) ||
V_2 -> V_4 . V_93 == 0 ) {
V_81 = - V_85 ;
break;
}
V_81 = F_61 ( V_2 -> V_4 . V_93 , ( T_2 V_83 * ) V_79 ) ;
break;
default:
V_81 = - V_85 ;
}
F_9 ( & V_2 -> V_3 ) ;
return V_81 ;
}
T_3 F_65 ( struct V_69 * V_69 ,
char V_83 * V_94 ,
T_4 V_95 ,
T_5 * V_96 )
{
struct V_1 * V_2 = V_14 [ F_46 ( F_57 ( V_69 ) ) ] ;
unsigned char * V_11 ;
int V_73 = 0 , V_97 = 0 ;
F_66 ( V_74 , V_98 ) ;
if ( ! V_2 ) {
F_27 ( L_21 ) ;
return - V_19 ;
}
if ( ! F_41 ( V_2 -> V_4 . V_55 ) )
return - V_45 ;
F_43 ( V_2 -> V_4 . V_9 , V_66 L_26 , V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
V_11 = F_29 ( V_2 -> V_36 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
if ( F_47 ( & V_2 -> V_3 ) ) {
V_73 = - V_70 ;
goto V_99;
}
if ( ! V_2 -> V_63 ) {
V_73 = - V_19 ;
goto V_100;
}
if ( V_95 % V_2 -> V_36 ) {
V_73 = - V_45 ;
goto V_100;
}
F_67 ( & V_2 -> V_11 -> V_24 , & V_74 ) ;
while ( V_97 < V_95 && V_73 == 0 ) {
if ( F_59 ( V_2 -> V_11 ) ) {
if ( V_97 )
break;
if ( V_69 -> V_101 & V_102 ) {
V_73 = - V_103 ;
break;
}
if ( F_68 ( V_98 ) ) {
V_73 = - V_70 ;
break;
}
F_9 ( & V_2 -> V_3 ) ;
F_13 ( V_23 ) ;
F_17 () ;
F_13 ( V_104 ) ;
if ( F_47 ( & V_2 -> V_3 ) ) {
V_73 = - V_70 ;
F_69 ( & V_2 -> V_11 -> V_24 , & V_74 ) ;
goto V_99;
}
if ( ! V_2 -> V_63 ) {
V_73 = - V_19 ;
goto V_100;
}
} else {
F_70 ( V_2 -> V_11 , V_11 ) ;
V_73 = F_71 ( ( void V_83 * ) V_94 + V_97 , V_11 ,
V_2 -> V_11 -> V_36 ) ;
if ( ! V_73 )
V_97 += V_2 -> V_11 -> V_36 ;
else
V_73 = - V_105 ;
}
}
F_69 ( & V_2 -> V_11 -> V_24 , & V_74 ) ;
V_100:
F_9 ( & V_2 -> V_3 ) ;
V_99:
F_7 ( V_11 ) ;
return V_73 ? V_73 : V_97 ;
}
void * F_72 ( struct V_69 * V_69 )
{
return V_14 [ F_46 ( F_57 ( V_69 ) ) ] -> V_4 . V_18 ;
}
T_3 F_73 ( struct V_69 * V_69 , const char V_83 * V_94 ,
T_4 V_95 , T_5 * V_96 )
{
struct V_1 * V_2 = V_14 [ F_46 ( F_57 ( V_69 ) ) ] ;
if ( ! V_2 ) {
F_27 ( L_21 ) ;
return - V_19 ;
}
if ( ! V_2 -> V_63 )
return - V_19 ;
return - V_45 ;
}
static int T_6 F_74 ( void )
{
int V_27 ;
V_59 = F_75 ( V_31 , L_27 ) ;
if ( F_35 ( V_59 ) ) {
F_27 ( L_28 ) ;
return F_76 ( V_59 ) ;
}
V_27 = F_77 ( & V_57 , 0 , V_46 ,
V_106 ) ;
if ( V_27 ) {
F_78 ( V_59 ) ;
F_27 ( L_29 ) ;
return V_27 ;
}
F_79 ( L_30 ,
F_31 ( V_57 ) ) ;
return 0 ;
}
static void T_7 F_80 ( void )
{
F_78 ( V_59 ) ;
F_81 ( V_57 , V_46 ) ;
F_79 ( L_31 ) ;
}
