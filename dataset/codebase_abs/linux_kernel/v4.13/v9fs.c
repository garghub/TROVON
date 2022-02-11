static int F_1 ( char * V_1 )
{
int V_2 = - V_3 ;
if ( ! strcmp ( V_1 , L_1 ) ) {
V_2 = V_4 ;
F_2 ( V_5 , L_2 ) ;
} else if ( ! strcmp ( V_1 , L_3 ) ) {
V_2 = V_6 ;
F_2 ( V_5 , L_4 ) ;
} else if ( ! strcmp ( V_1 , L_5 ) ) {
V_2 = V_7 ;
F_2 ( V_5 , L_6 ) ;
} else if ( ! strcmp ( V_1 , L_7 ) ) {
V_2 = V_8 ;
F_2 ( V_5 , L_8 ) ;
} else
F_3 ( L_9 , V_1 ) ;
return V_2 ;
}
int F_4 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 -> V_16 ;
if ( V_14 -> V_17 )
F_5 ( V_10 , L_10 , V_14 -> V_17 ) ;
if ( ! F_6 ( V_14 -> V_18 , V_19 ) )
F_5 ( V_10 , L_11 ,
F_7 ( & V_20 , V_14 -> V_18 ) ) ;
if ( ! F_8 ( V_14 -> V_21 , V_22 ) )
F_5 ( V_10 , L_12 ,
F_9 ( & V_20 , V_14 -> V_21 ) ) ;
if ( V_14 -> V_23 != ~ 0 )
F_5 ( V_10 , L_13 , V_14 -> V_23 ) ;
if ( strcmp ( V_14 -> V_24 , V_25 ) != 0 )
F_5 ( V_10 , L_14 , V_14 -> V_24 ) ;
if ( strcmp ( V_14 -> V_26 , V_27 ) != 0 )
F_5 ( V_10 , L_15 , V_14 -> V_26 ) ;
if ( V_14 -> V_28 )
F_10 ( V_10 , L_16 ) ;
if ( V_14 -> V_29 )
F_5 ( V_10 , L_17 , V_30 [ V_14 -> V_29 ] ) ;
#ifdef F_11
if ( V_14 -> V_31 && V_14 -> V_29 == V_6 )
F_5 ( V_10 , L_18 , V_14 -> V_31 ) ;
#endif
switch ( V_14 -> V_32 & V_33 ) {
case V_34 :
F_10 ( V_10 , L_19 ) ;
break;
case V_35 :
F_10 ( V_10 , L_20 ) ;
break;
case V_36 :
F_10 ( V_10 , L_21 ) ;
break;
case V_37 :
F_5 ( V_10 , L_22 ,
F_7 ( & V_20 , V_14 -> V_38 ) ) ;
break;
}
if ( V_14 -> V_32 & V_39 )
F_10 ( V_10 , L_23 ) ;
return F_12 ( V_10 , V_14 -> V_40 ) ;
}
static int F_13 ( struct V_13 * V_14 , char * V_41 )
{
char * V_42 , * V_43 ;
T_1 args [ V_44 ] ;
char * V_45 ;
int V_46 = 0 ;
char * V_1 , * V_47 ;
int V_48 = 0 ;
V_14 -> V_23 = ~ 0 ;
V_14 -> V_17 = 0 ;
V_14 -> V_29 = V_8 ;
#ifdef F_11
V_14 -> V_31 = NULL ;
#endif
if ( ! V_41 )
return 0 ;
V_43 = F_14 ( V_41 , V_49 ) ;
if ( ! V_43 ) {
V_48 = - V_50 ;
goto V_51;
}
V_42 = V_43 ;
while ( ( V_45 = F_15 ( & V_42 , L_24 ) ) != NULL ) {
int V_52 , V_53 ;
if ( ! * V_45 )
continue;
V_52 = F_16 ( V_45 , V_54 , args ) ;
switch ( V_52 ) {
case V_55 :
V_53 = F_17 ( & args [ 0 ] , & V_46 ) ;
if ( V_53 < 0 ) {
F_2 ( V_56 ,
L_25 ) ;
V_48 = V_53 ;
continue;
}
V_14 -> V_17 = V_46 ;
#ifdef F_18
V_57 = V_46 ;
#endif
break;
case V_58 :
V_53 = F_17 ( & args [ 0 ] , & V_46 ) ;
if ( V_53 < 0 ) {
F_2 ( V_56 ,
L_25 ) ;
V_48 = V_53 ;
continue;
}
V_14 -> V_18 = F_19 ( F_20 () , V_46 ) ;
if ( ! F_21 ( V_14 -> V_18 ) ) {
F_2 ( V_56 ,
L_26 ) ;
V_48 = - V_3 ;
continue;
}
break;
case V_59 :
V_53 = F_17 ( & args [ 0 ] , & V_46 ) ;
if ( V_53 < 0 ) {
F_2 ( V_56 ,
L_25 ) ;
V_48 = V_53 ;
continue;
}
V_14 -> V_21 = F_22 ( F_20 () , V_46 ) ;
if ( ! F_23 ( V_14 -> V_21 ) ) {
F_2 ( V_56 ,
L_27 ) ;
V_48 = - V_3 ;
continue;
}
break;
case V_60 :
V_53 = F_17 ( & args [ 0 ] , & V_46 ) ;
if ( V_53 < 0 ) {
F_2 ( V_56 ,
L_25 ) ;
V_48 = V_53 ;
continue;
}
V_14 -> V_23 = V_46 ;
break;
case V_61 :
F_24 ( V_14 -> V_24 ) ;
V_14 -> V_24 = F_25 ( & args [ 0 ] ) ;
if ( ! V_14 -> V_24 ) {
V_48 = - V_50 ;
goto V_62;
}
break;
case V_63 :
F_24 ( V_14 -> V_26 ) ;
V_14 -> V_26 = F_25 ( & args [ 0 ] ) ;
if ( ! V_14 -> V_26 ) {
V_48 = - V_50 ;
goto V_62;
}
break;
case V_64 :
V_14 -> V_28 = 1 ;
break;
case V_65 :
V_14 -> V_29 = V_4 ;
break;
case V_66 :
V_14 -> V_29 = V_6 ;
break;
case V_67 :
V_14 -> V_29 = V_7 ;
break;
case V_68 :
#ifdef F_11
F_24 ( V_14 -> V_31 ) ;
V_14 -> V_31 = F_25 ( & args [ 0 ] ) ;
#endif
break;
case V_69 :
V_1 = F_25 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_48 = - V_50 ;
F_2 ( V_56 ,
L_28 ) ;
goto V_62;
}
V_48 = F_1 ( V_1 ) ;
if ( V_48 == - V_3 ) {
F_24 ( V_1 ) ;
goto V_62;
}
V_14 -> V_29 = V_48 ;
F_24 ( V_1 ) ;
break;
case V_70 :
V_1 = F_25 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_48 = - V_50 ;
F_2 ( V_56 ,
L_29 ) ;
goto V_62;
}
V_14 -> V_32 &= ~ V_33 ;
if ( strcmp ( V_1 , L_30 ) == 0 )
V_14 -> V_32 |= V_34 ;
else if ( strcmp ( V_1 , L_31 ) == 0 )
V_14 -> V_32 |= V_35 ;
else if ( strcmp ( V_1 , L_32 ) == 0 ) {
V_14 -> V_32 |= V_36 ;
} else {
T_2 V_38 ;
V_14 -> V_32 |= V_37 ;
V_38 = F_26 ( V_1 , & V_47 , 10 ) ;
if ( * V_47 != '\0' ) {
V_48 = - V_3 ;
F_3 ( L_33 ,
V_1 ) ;
F_24 ( V_1 ) ;
goto V_62;
}
V_14 -> V_38 = F_19 ( F_20 () , V_38 ) ;
if ( ! F_21 ( V_14 -> V_38 ) ) {
V_48 = - V_3 ;
F_3 ( L_34 , V_1 ) ;
F_24 ( V_1 ) ;
goto V_62;
}
}
F_24 ( V_1 ) ;
break;
case V_71 :
#ifdef F_27
V_14 -> V_32 |= V_39 ;
#else
F_2 ( V_56 ,
L_35 ) ;
#endif
break;
default:
continue;
}
}
V_62:
F_24 ( V_43 ) ;
V_51:
return V_48 ;
}
struct V_72 * F_28 ( struct V_13 * V_14 ,
const char * V_73 , char * V_74 )
{
struct V_72 * V_75 ;
int V_76 = - V_50 ;
V_14 -> V_24 = F_14 ( V_25 , V_49 ) ;
if ( ! V_14 -> V_24 )
goto V_77;
V_14 -> V_26 = F_14 ( V_27 , V_49 ) ;
if ( ! V_14 -> V_26 )
goto V_77;
F_29 ( & V_14 -> V_78 ) ;
V_14 -> V_38 = V_79 ;
V_14 -> V_18 = V_19 ;
V_14 -> V_21 = V_22 ;
V_14 -> V_40 = F_30 ( V_73 , V_74 ) ;
if ( F_31 ( V_14 -> V_40 ) ) {
V_76 = F_32 ( V_14 -> V_40 ) ;
F_2 ( V_56 , L_36 ) ;
goto V_77;
}
V_14 -> V_32 = V_34 ;
if ( F_33 ( V_14 -> V_40 ) ) {
V_14 -> V_32 = V_36 ;
V_14 -> V_32 |= V_80 ;
} else if ( F_34 ( V_14 -> V_40 ) ) {
V_14 -> V_32 |= V_81 ;
}
V_76 = F_13 ( V_14 , V_74 ) ;
if ( V_76 < 0 )
goto V_82;
V_14 -> V_83 = V_14 -> V_40 -> V_84 - V_85 ;
if ( ! F_35 ( V_14 ) &&
( ( V_14 -> V_32 & V_33 ) == V_36 ) ) {
V_14 -> V_32 &= ~ V_33 ;
V_14 -> V_32 |= V_34 ;
}
if ( ! ( F_36 ( V_14 ) || F_35 ( V_14 ) ) &&
( ( V_14 -> V_32 & V_33 ) == V_34 ) ) {
V_14 -> V_32 &= ~ V_33 ;
V_14 -> V_32 |= V_35 ;
V_14 -> V_38 = V_79 ;
}
if ( ! F_35 ( V_14 ) ||
! ( ( V_14 -> V_32 & V_33 ) == V_36 ) ) {
V_14 -> V_32 &= ~ V_86 ;
}
V_75 = F_37 ( V_14 -> V_40 , NULL , V_14 -> V_24 , V_79 ,
V_14 -> V_26 ) ;
if ( F_31 ( V_75 ) ) {
V_76 = F_32 ( V_75 ) ;
F_2 ( V_56 , L_37 ) ;
goto V_82;
}
if ( ( V_14 -> V_32 & V_33 ) == V_37 )
V_75 -> V_38 = V_14 -> V_38 ;
else
V_75 -> V_38 = V_79 ;
#ifdef F_11
F_38 ( V_14 ) ;
#endif
F_39 ( & V_87 ) ;
F_40 ( & V_14 -> V_88 , & V_89 ) ;
F_41 ( & V_87 ) ;
return V_75 ;
V_82:
F_42 ( V_14 -> V_40 ) ;
V_77:
F_24 ( V_14 -> V_24 ) ;
F_24 ( V_14 -> V_26 ) ;
return F_43 ( V_76 ) ;
}
void F_44 ( struct V_13 * V_14 )
{
if ( V_14 -> V_40 ) {
F_42 ( V_14 -> V_40 ) ;
V_14 -> V_40 = NULL ;
}
#ifdef F_11
if ( V_14 -> V_90 ) {
F_45 ( V_14 ) ;
F_24 ( V_14 -> V_31 ) ;
}
#endif
F_24 ( V_14 -> V_24 ) ;
F_24 ( V_14 -> V_26 ) ;
F_39 ( & V_87 ) ;
F_46 ( & V_14 -> V_88 ) ;
F_41 ( & V_87 ) ;
}
void F_47 ( struct V_13 * V_14 ) {
F_2 ( V_56 , L_38 , V_14 ) ;
F_48 ( V_14 -> V_40 ) ;
}
void F_49 ( struct V_13 * V_14 )
{
F_2 ( V_56 , L_39 , V_14 ) ;
F_50 ( V_14 -> V_40 ) ;
}
static T_3 F_51 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
T_3 V_96 = 0 , V_97 = 0 , V_98 = V_99 ;
struct V_13 * V_14 ;
F_39 ( & V_87 ) ;
F_52 (v9ses, &v9fs_sessionlist, slist) {
if ( V_14 -> V_31 ) {
V_96 = snprintf ( V_95 , V_98 , L_40 , V_14 -> V_31 ) ;
if ( V_96 < 0 ) {
V_97 = V_96 ;
break;
}
V_97 += V_96 ;
V_98 -= V_96 ;
}
}
F_41 ( & V_87 ) ;
return V_97 ;
}
static int T_4 F_53 ( void )
{
V_100 = F_54 ( L_41 , V_101 ) ;
if ( ! V_100 )
return - V_50 ;
if ( F_55 ( V_100 , & V_102 ) ) {
F_56 ( V_100 ) ;
return - V_50 ;
}
return 0 ;
}
static void F_57 ( void )
{
F_58 ( V_100 , & V_102 ) ;
F_56 ( V_100 ) ;
}
static void F_59 ( void * V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_103 ;
#ifdef F_11
V_105 -> V_90 = NULL ;
#endif
memset ( & V_105 -> V_106 , 0 , sizeof( V_105 -> V_106 ) ) ;
F_60 ( & V_105 -> V_107 ) ;
}
static int F_61 ( void )
{
V_108 = F_62 ( L_42 ,
sizeof( struct V_104 ) ,
0 , ( V_109 |
V_110 | V_111 ) ,
F_59 ) ;
if ( ! V_108 )
return - V_50 ;
return 0 ;
}
static void F_63 ( void )
{
F_64 () ;
F_65 ( V_108 ) ;
}
static int F_66 ( void )
{
int V_48 ;
V_48 = F_61 () ;
if ( V_48 < 0 )
return V_48 ;
#ifdef F_11
V_48 = F_67 ( & V_112 ) ;
if ( V_48 < 0 )
F_63 () ;
#endif
return V_48 ;
}
static void F_68 ( void )
{
F_63 () ;
#ifdef F_11
F_69 ( & V_112 ) ;
#endif
}
static int T_4 F_70 ( void )
{
int V_113 ;
F_3 ( L_43 ) ;
V_113 = F_66 () ;
if ( V_113 < 0 ) {
F_71 ( L_44 ) ;
return V_113 ;
}
V_113 = F_53 () ;
if ( V_113 < 0 ) {
F_71 ( L_45 ) ;
goto V_114;
}
V_113 = F_72 ( & V_115 ) ;
if ( V_113 < 0 ) {
F_71 ( L_46 ) ;
goto V_116;
}
return 0 ;
V_116:
F_57 () ;
V_114:
F_68 () ;
return V_113 ;
}
static void T_5 F_73 ( void )
{
F_57 () ;
F_68 () ;
F_74 ( & V_115 ) ;
}
