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
static int F_4 ( struct V_9 * V_10 , char * V_11 )
{
char * V_12 , * V_13 ;
T_1 args [ V_14 ] ;
char * V_15 ;
int V_16 = 0 ;
char * V_1 , * V_17 ;
int V_18 = 0 ;
V_10 -> V_19 = ~ 0 ;
V_10 -> V_20 = 0 ;
V_10 -> V_21 = V_8 ;
#ifdef F_5
V_10 -> V_22 = NULL ;
#endif
if ( ! V_11 )
return 0 ;
V_13 = F_6 ( V_11 , V_23 ) ;
if ( ! V_13 ) {
V_18 = - V_24 ;
goto V_25;
}
V_12 = V_13 ;
while ( ( V_15 = F_7 ( & V_12 , L_10 ) ) != NULL ) {
int V_26 , V_27 ;
if ( ! * V_15 )
continue;
V_26 = F_8 ( V_15 , V_28 , args ) ;
switch ( V_26 ) {
case V_29 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_11 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_20 = V_16 ;
#ifdef F_10
V_31 = V_16 ;
#endif
break;
case V_32 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_11 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_33 = F_11 ( F_12 () , V_16 ) ;
if ( ! F_13 ( V_10 -> V_33 ) ) {
F_2 ( V_30 ,
L_12 ) ;
V_18 = - V_3 ;
continue;
}
break;
case V_34 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_11 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_35 = F_14 ( F_12 () , V_16 ) ;
if ( ! F_15 ( V_10 -> V_35 ) ) {
F_2 ( V_30 ,
L_13 ) ;
V_18 = - V_3 ;
continue;
}
break;
case V_36 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_11 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_19 = V_16 ;
break;
case V_37 :
F_16 ( V_10 -> V_38 ) ;
V_10 -> V_38 = F_17 ( & args [ 0 ] ) ;
if ( ! V_10 -> V_38 ) {
V_18 = - V_24 ;
goto V_39;
}
break;
case V_40 :
F_16 ( V_10 -> V_41 ) ;
V_10 -> V_41 = F_17 ( & args [ 0 ] ) ;
if ( ! V_10 -> V_41 ) {
V_18 = - V_24 ;
goto V_39;
}
break;
case V_42 :
V_10 -> V_43 = 1 ;
break;
case V_44 :
V_10 -> V_21 = V_4 ;
break;
case V_45 :
V_10 -> V_21 = V_6 ;
break;
case V_46 :
V_10 -> V_21 = V_7 ;
break;
case V_47 :
#ifdef F_5
V_10 -> V_22 = F_17 ( & args [ 0 ] ) ;
#endif
break;
case V_48 :
V_1 = F_17 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_18 = - V_24 ;
F_2 ( V_30 ,
L_14 ) ;
goto V_39;
}
V_18 = F_1 ( V_1 ) ;
if ( V_18 == - V_3 ) {
F_16 ( V_1 ) ;
goto V_39;
}
V_10 -> V_21 = V_18 ;
F_16 ( V_1 ) ;
break;
case V_49 :
V_1 = F_17 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_18 = - V_24 ;
F_2 ( V_30 ,
L_15 ) ;
goto V_39;
}
V_10 -> V_50 &= ~ V_51 ;
if ( strcmp ( V_1 , L_16 ) == 0 )
V_10 -> V_50 |= V_52 ;
else if ( strcmp ( V_1 , L_17 ) == 0 )
V_10 -> V_50 |= V_53 ;
else if ( strcmp ( V_1 , L_18 ) == 0 ) {
V_10 -> V_50 |= V_54 ;
} else {
T_2 V_55 ;
V_10 -> V_50 |= V_56 ;
V_55 = F_18 ( V_1 , & V_17 , 10 ) ;
if ( * V_17 != '\0' ) {
V_18 = - V_3 ;
F_3 ( L_19 ,
V_1 ) ;
F_16 ( V_1 ) ;
goto V_39;
}
V_10 -> V_55 = F_11 ( F_12 () , V_55 ) ;
if ( ! F_13 ( V_10 -> V_55 ) ) {
V_18 = - V_3 ;
F_3 ( L_20 , V_1 ) ;
F_16 ( V_1 ) ;
goto V_39;
}
}
F_16 ( V_1 ) ;
break;
case V_57 :
#ifdef F_19
V_10 -> V_50 |= V_58 ;
#else
F_2 ( V_30 ,
L_21 ) ;
#endif
break;
default:
continue;
}
}
V_39:
F_16 ( V_13 ) ;
V_25:
return V_18 ;
}
struct V_59 * F_20 ( struct V_9 * V_10 ,
const char * V_60 , char * V_61 )
{
struct V_59 * V_62 ;
int V_63 = - V_24 ;
V_10 -> V_38 = F_6 ( V_64 , V_23 ) ;
if ( ! V_10 -> V_38 )
goto V_65;
V_10 -> V_41 = F_6 ( V_66 , V_23 ) ;
if ( ! V_10 -> V_41 )
goto V_65;
F_21 ( & V_10 -> V_67 ) ;
V_63 = F_22 ( & V_10 -> V_68 , L_22 ) ;
if ( V_63 )
goto V_65;
V_10 -> V_55 = V_69 ;
V_10 -> V_33 = V_70 ;
V_10 -> V_35 = V_71 ;
V_10 -> V_72 = F_23 ( V_60 , V_61 ) ;
if ( F_24 ( V_10 -> V_72 ) ) {
V_63 = F_25 ( V_10 -> V_72 ) ;
F_2 ( V_30 , L_23 ) ;
goto V_73;
}
V_10 -> V_50 = V_52 ;
if ( F_26 ( V_10 -> V_72 ) ) {
V_10 -> V_50 = V_54 ;
V_10 -> V_50 |= V_74 ;
} else if ( F_27 ( V_10 -> V_72 ) ) {
V_10 -> V_50 |= V_75 ;
}
V_63 = F_4 ( V_10 , V_61 ) ;
if ( V_63 < 0 )
goto V_76;
V_10 -> V_77 = V_10 -> V_72 -> V_78 - V_79 ;
if ( ! F_28 ( V_10 ) &&
( ( V_10 -> V_50 & V_51 ) == V_54 ) ) {
V_10 -> V_50 &= ~ V_51 ;
V_10 -> V_50 |= V_52 ;
}
if ( ! ( F_29 ( V_10 ) || F_28 ( V_10 ) ) &&
( ( V_10 -> V_50 & V_51 ) == V_52 ) ) {
V_10 -> V_50 &= ~ V_51 ;
V_10 -> V_50 |= V_53 ;
V_10 -> V_55 = V_69 ;
}
if ( ! F_28 ( V_10 ) ||
! ( ( V_10 -> V_50 & V_51 ) == V_54 ) ) {
V_10 -> V_50 &= ~ V_80 ;
}
V_62 = F_30 ( V_10 -> V_72 , NULL , V_10 -> V_38 , V_69 ,
V_10 -> V_41 ) ;
if ( F_24 ( V_62 ) ) {
V_63 = F_25 ( V_62 ) ;
F_2 ( V_30 , L_24 ) ;
goto V_76;
}
if ( ( V_10 -> V_50 & V_51 ) == V_56 )
V_62 -> V_55 = V_10 -> V_55 ;
else
V_62 -> V_55 = V_69 ;
#ifdef F_5
F_31 ( V_10 ) ;
#endif
F_32 ( & V_81 ) ;
F_33 ( & V_10 -> V_82 , & V_83 ) ;
F_34 ( & V_81 ) ;
return V_62 ;
V_76:
F_35 ( V_10 -> V_72 ) ;
V_73:
F_36 ( & V_10 -> V_68 ) ;
V_65:
F_16 ( V_10 -> V_38 ) ;
F_16 ( V_10 -> V_41 ) ;
return F_37 ( V_63 ) ;
}
void F_38 ( struct V_9 * V_10 )
{
if ( V_10 -> V_72 ) {
F_35 ( V_10 -> V_72 ) ;
V_10 -> V_72 = NULL ;
}
#ifdef F_5
if ( V_10 -> V_84 ) {
F_39 ( V_10 ) ;
F_16 ( V_10 -> V_22 ) ;
}
#endif
F_16 ( V_10 -> V_38 ) ;
F_16 ( V_10 -> V_41 ) ;
F_36 ( & V_10 -> V_68 ) ;
F_32 ( & V_81 ) ;
F_40 ( & V_10 -> V_82 ) ;
F_34 ( & V_81 ) ;
}
void F_41 ( struct V_9 * V_10 ) {
F_2 ( V_30 , L_25 , V_10 ) ;
F_42 ( V_10 -> V_72 ) ;
}
void F_43 ( struct V_9 * V_10 )
{
F_2 ( V_30 , L_26 , V_10 ) ;
F_44 ( V_10 -> V_72 ) ;
}
static T_3 F_45 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
T_3 V_90 = 0 , V_91 = 0 , V_92 = V_93 ;
struct V_9 * V_10 ;
F_32 ( & V_81 ) ;
F_46 (v9ses, &v9fs_sessionlist, slist) {
if ( V_10 -> V_22 ) {
V_90 = snprintf ( V_89 , V_92 , L_27 , V_10 -> V_22 ) ;
if ( V_90 < 0 ) {
V_91 = V_90 ;
break;
}
V_91 += V_90 ;
V_92 -= V_90 ;
}
}
F_34 ( & V_81 ) ;
return V_91 ;
}
static int T_4 F_47 ( void )
{
V_94 = F_48 ( L_22 , V_95 ) ;
if ( ! V_94 )
return - V_24 ;
if ( F_49 ( V_94 , & V_96 ) ) {
F_50 ( V_94 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_51 ( void )
{
F_52 ( V_94 , & V_96 ) ;
F_50 ( V_94 ) ;
}
static void F_53 ( void * V_97 )
{
struct V_98 * V_99 = (struct V_98 * ) V_97 ;
#ifdef F_5
V_99 -> V_84 = NULL ;
#endif
memset ( & V_99 -> V_100 , 0 , sizeof( V_99 -> V_100 ) ) ;
F_54 ( & V_99 -> V_101 ) ;
}
static int F_55 ( void )
{
V_102 = F_56 ( L_28 ,
sizeof( struct V_98 ) ,
0 , ( V_103 |
V_104 ) ,
F_53 ) ;
if ( ! V_102 )
return - V_24 ;
return 0 ;
}
static void F_57 ( void )
{
F_58 () ;
F_59 ( V_102 ) ;
}
static int F_60 ( void )
{
int V_18 ;
V_18 = F_55 () ;
if ( V_18 < 0 )
return V_18 ;
#ifdef F_5
V_18 = F_61 ( & V_105 ) ;
if ( V_18 < 0 )
F_57 () ;
#endif
return V_18 ;
}
static void F_62 ( void )
{
F_57 () ;
#ifdef F_5
F_63 ( & V_105 ) ;
#endif
}
static int T_4 F_64 ( void )
{
int V_106 ;
F_3 ( L_29 ) ;
V_106 = F_60 () ;
if ( V_106 < 0 ) {
F_65 ( L_30 ) ;
return V_106 ;
}
V_106 = F_47 () ;
if ( V_106 < 0 ) {
F_65 ( L_31 ) ;
goto V_107;
}
V_106 = F_66 ( & V_108 ) ;
if ( V_106 < 0 ) {
F_65 ( L_32 ) ;
goto V_109;
}
return 0 ;
V_109:
F_51 () ;
V_107:
F_62 () ;
return V_106 ;
}
static void T_5 F_67 ( void )
{
F_51 () ;
F_62 () ;
F_68 ( & V_108 ) ;
}
