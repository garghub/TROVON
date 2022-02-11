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
} else
F_3 ( L_7 , V_1 ) ;
return V_2 ;
}
static int F_4 ( struct V_8 * V_9 , char * V_10 )
{
char * V_11 , * V_12 ;
T_1 args [ V_13 ] ;
char * V_14 ;
int V_15 = 0 ;
char * V_1 , * V_16 ;
int V_17 = 0 ;
V_9 -> V_18 = ~ 0 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_7 ;
#ifdef F_5
V_9 -> V_21 = NULL ;
#endif
if ( ! V_10 )
return 0 ;
V_12 = F_6 ( V_10 , V_22 ) ;
if ( ! V_12 ) {
V_17 = - V_23 ;
goto V_24;
}
V_11 = V_12 ;
while ( ( V_14 = F_7 ( & V_11 , L_8 ) ) != NULL ) {
int V_25 , V_26 ;
if ( ! * V_14 )
continue;
V_25 = F_8 ( V_14 , V_27 , args ) ;
switch ( V_25 ) {
case V_28 :
V_26 = F_9 ( & args [ 0 ] , & V_15 ) ;
if ( V_26 < 0 ) {
F_2 ( V_29 ,
L_9 ) ;
V_17 = V_26 ;
continue;
}
V_9 -> V_19 = V_15 ;
#ifdef F_10
V_30 = V_15 ;
#endif
break;
case V_31 :
V_26 = F_9 ( & args [ 0 ] , & V_15 ) ;
if ( V_26 < 0 ) {
F_2 ( V_29 ,
L_9 ) ;
V_17 = V_26 ;
continue;
}
V_9 -> V_32 = V_15 ;
break;
case V_33 :
V_26 = F_9 ( & args [ 0 ] , & V_15 ) ;
if ( V_26 < 0 ) {
F_2 ( V_29 ,
L_9 ) ;
V_17 = V_26 ;
continue;
}
V_9 -> V_34 = V_15 ;
break;
case V_35 :
V_26 = F_9 ( & args [ 0 ] , & V_15 ) ;
if ( V_26 < 0 ) {
F_2 ( V_29 ,
L_9 ) ;
V_17 = V_26 ;
continue;
}
V_9 -> V_18 = V_15 ;
break;
case V_36 :
F_11 ( V_9 -> V_37 , & args [ 0 ] , V_38 ) ;
break;
case V_39 :
F_11 ( V_9 -> V_40 , & args [ 0 ] , V_38 ) ;
break;
case V_41 :
V_9 -> V_42 = 1 ;
break;
case V_43 :
V_9 -> V_20 = V_4 ;
break;
case V_44 :
V_9 -> V_20 = V_6 ;
break;
case V_45 :
#ifdef F_5
V_9 -> V_21 = F_12 ( & args [ 0 ] ) ;
#endif
break;
case V_46 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_10 ) ;
goto V_47;
}
V_17 = F_1 ( V_1 ) ;
if ( V_17 == - V_3 ) {
F_13 ( V_1 ) ;
goto V_47;
}
V_9 -> V_20 = V_17 ;
F_13 ( V_1 ) ;
break;
case V_48 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_11 ) ;
goto V_47;
}
V_9 -> V_49 &= ~ V_50 ;
if ( strcmp ( V_1 , L_12 ) == 0 )
V_9 -> V_49 |= V_51 ;
else if ( strcmp ( V_1 , L_13 ) == 0 )
V_9 -> V_49 |= V_52 ;
else if ( strcmp ( V_1 , L_14 ) == 0 ) {
V_9 -> V_49 |= V_53 ;
} else {
V_9 -> V_49 |= V_54 ;
V_9 -> V_55 = F_14 ( V_1 , & V_16 , 10 ) ;
if ( * V_16 != '\0' ) {
V_17 = - V_3 ;
F_3 ( L_15 ,
V_1 ) ;
F_13 ( V_1 ) ;
goto V_47;
}
}
F_13 ( V_1 ) ;
break;
case V_56 :
#ifdef F_15
V_9 -> V_49 |= V_57 ;
#else
F_2 ( V_29 ,
L_16 ) ;
#endif
break;
default:
continue;
}
}
V_47:
F_13 ( V_12 ) ;
V_24:
return V_17 ;
}
struct V_58 * F_16 ( struct V_8 * V_9 ,
const char * V_59 , char * V_60 )
{
int V_61 = - V_3 ;
struct V_58 * V_62 ;
int V_63 ;
V_9 -> V_37 = F_17 () ;
if ( ! V_9 -> V_37 )
return F_18 ( - V_23 ) ;
V_9 -> V_40 = F_17 () ;
if ( ! V_9 -> V_40 ) {
F_19 ( V_9 -> V_37 ) ;
return F_18 ( - V_23 ) ;
}
F_20 ( & V_9 -> V_64 ) ;
V_63 = F_21 ( & V_9 -> V_65 , L_17 , V_66 ) ;
if ( V_63 ) {
F_19 ( V_9 -> V_40 ) ;
F_19 ( V_9 -> V_37 ) ;
return F_18 ( V_63 ) ;
}
F_22 ( & V_67 ) ;
F_23 ( & V_9 -> V_68 , & V_69 ) ;
F_24 ( & V_67 ) ;
strcpy ( V_9 -> V_37 , V_70 ) ;
strcpy ( V_9 -> V_40 , V_71 ) ;
V_9 -> V_55 = ~ 0 ;
V_9 -> V_32 = V_72 ;
V_9 -> V_34 = V_73 ;
V_9 -> V_74 = F_25 ( V_59 , V_60 ) ;
if ( F_26 ( V_9 -> V_74 ) ) {
V_61 = F_27 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
F_2 ( V_29 , L_18 ) ;
goto error;
}
V_9 -> V_49 = V_51 ;
if ( F_28 ( V_9 -> V_74 ) ) {
V_9 -> V_49 = V_53 ;
V_9 -> V_49 |= V_75 ;
} else if ( F_29 ( V_9 -> V_74 ) ) {
V_9 -> V_49 |= V_76 ;
}
V_63 = F_4 ( V_9 , V_60 ) ;
if ( V_63 < 0 ) {
V_61 = V_63 ;
goto error;
}
V_9 -> V_77 = V_9 -> V_74 -> V_78 - V_79 ;
if ( ! F_30 ( V_9 ) &&
( ( V_9 -> V_49 & V_50 ) == V_53 ) ) {
V_9 -> V_49 &= ~ V_50 ;
V_9 -> V_49 |= V_51 ;
}
if ( ! ( F_31 ( V_9 ) || F_30 ( V_9 ) ) &&
( ( V_9 -> V_49 & V_50 ) == V_51 ) ) {
V_9 -> V_49 &= ~ V_50 ;
V_9 -> V_49 |= V_52 ;
V_9 -> V_55 = ~ 0 ;
}
if ( ! F_30 ( V_9 ) ||
! ( ( V_9 -> V_49 & V_50 ) == V_53 ) ) {
V_9 -> V_49 &= ~ V_80 ;
}
V_62 = F_32 ( V_9 -> V_74 , NULL , V_9 -> V_37 , ~ 0 ,
V_9 -> V_40 ) ;
if ( F_26 ( V_62 ) ) {
V_61 = F_27 ( V_62 ) ;
V_62 = NULL ;
F_2 ( V_29 , L_19 ) ;
goto error;
}
if ( ( V_9 -> V_49 & V_50 ) == V_54 )
V_62 -> V_55 = V_9 -> V_55 ;
else
V_62 -> V_55 = ~ 0 ;
#ifdef F_5
F_33 ( V_9 ) ;
#endif
return V_62 ;
error:
F_34 ( & V_9 -> V_65 ) ;
return F_18 ( V_61 ) ;
}
void F_35 ( struct V_8 * V_9 )
{
if ( V_9 -> V_74 ) {
F_36 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
}
#ifdef F_5
if ( V_9 -> V_81 ) {
F_37 ( V_9 ) ;
F_13 ( V_9 -> V_21 ) ;
}
#endif
F_19 ( V_9 -> V_37 ) ;
F_19 ( V_9 -> V_40 ) ;
F_34 ( & V_9 -> V_65 ) ;
F_22 ( & V_67 ) ;
F_38 ( & V_9 -> V_68 ) ;
F_24 ( & V_67 ) ;
}
void F_39 ( struct V_8 * V_9 ) {
F_2 ( V_29 , L_20 , V_9 ) ;
F_40 ( V_9 -> V_74 ) ;
}
void F_41 ( struct V_8 * V_9 )
{
F_2 ( V_29 , L_21 , V_9 ) ;
F_42 ( V_9 -> V_74 ) ;
}
static T_2 F_43 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
T_2 V_87 = 0 , V_88 = 0 , V_89 = V_90 ;
struct V_8 * V_9 ;
F_22 ( & V_67 ) ;
F_44 (v9ses, &v9fs_sessionlist, slist) {
if ( V_9 -> V_21 ) {
V_87 = snprintf ( V_86 , V_89 , L_22 , V_9 -> V_21 ) ;
if ( V_87 < 0 ) {
V_88 = V_87 ;
break;
}
V_88 += V_87 ;
V_89 -= V_87 ;
}
}
F_24 ( & V_67 ) ;
return V_88 ;
}
static int F_45 ( void )
{
V_91 = F_46 ( L_17 , V_92 ) ;
if ( ! V_91 )
return - V_23 ;
if ( F_47 ( V_91 , & V_93 ) ) {
F_48 ( V_91 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_49 ( void )
{
F_50 ( V_91 , & V_93 ) ;
F_48 ( V_91 ) ;
}
static void F_51 ( void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
#ifdef F_5
V_96 -> V_81 = NULL ;
#endif
memset ( & V_96 -> V_97 , 0 , sizeof( V_96 -> V_97 ) ) ;
F_52 ( & V_96 -> V_98 ) ;
}
static int F_53 ( void )
{
V_99 = F_54 ( L_23 ,
sizeof( struct V_95 ) ,
0 , ( V_100 |
V_101 ) ,
F_51 ) ;
if ( ! V_99 )
return - V_23 ;
return 0 ;
}
static void F_55 ( void )
{
F_56 ( V_99 ) ;
}
static int F_57 ( void )
{
int V_17 ;
V_17 = F_53 () ;
if ( V_17 < 0 )
return V_17 ;
#ifdef F_5
return F_58 ( & V_102 ) ;
#else
return V_17 ;
#endif
}
static void F_59 ( void )
{
F_55 () ;
#ifdef F_5
F_60 ( & V_102 ) ;
#endif
}
static int T_3 F_61 ( void )
{
int V_103 ;
F_3 ( L_24 ) ;
V_103 = F_62 ( & V_104 ) ;
if ( V_103 < 0 ) {
F_63 ( L_25 ) ;
return V_103 ;
}
V_103 = F_57 () ;
if ( V_103 < 0 ) {
F_63 ( L_26 ) ;
goto V_105;
}
V_103 = F_45 () ;
if ( V_103 < 0 ) {
F_63 ( L_27 ) ;
goto V_106;
}
return 0 ;
V_106:
F_49 () ;
V_105:
F_64 ( & V_104 ) ;
return V_103 ;
}
static void T_4 F_65 ( void )
{
F_49 () ;
F_59 () ;
F_64 ( & V_104 ) ;
}
