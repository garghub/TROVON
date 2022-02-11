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
V_9 -> V_32 = F_11 ( F_12 () , V_15 ) ;
if ( ! F_13 ( V_9 -> V_32 ) ) {
F_2 ( V_29 ,
L_10 ) ;
V_17 = - V_3 ;
continue;
}
break;
case V_33 :
V_26 = F_9 ( & args [ 0 ] , & V_15 ) ;
if ( V_26 < 0 ) {
F_2 ( V_29 ,
L_9 ) ;
V_17 = V_26 ;
continue;
}
V_9 -> V_34 = F_14 ( F_12 () , V_15 ) ;
if ( ! F_15 ( V_9 -> V_34 ) ) {
F_2 ( V_29 ,
L_11 ) ;
V_17 = - V_3 ;
continue;
}
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
F_16 ( V_9 -> V_37 ) ;
V_9 -> V_37 = F_17 ( & args [ 0 ] ) ;
if ( ! V_9 -> V_37 ) {
V_17 = - V_23 ;
goto V_38;
}
break;
case V_39 :
F_16 ( V_9 -> V_40 ) ;
V_9 -> V_40 = F_17 ( & args [ 0 ] ) ;
if ( ! V_9 -> V_40 ) {
V_17 = - V_23 ;
goto V_38;
}
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
V_9 -> V_21 = F_17 ( & args [ 0 ] ) ;
#endif
break;
case V_46 :
V_1 = F_17 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_12 ) ;
goto V_38;
}
V_17 = F_1 ( V_1 ) ;
if ( V_17 == - V_3 ) {
F_16 ( V_1 ) ;
goto V_38;
}
V_9 -> V_20 = V_17 ;
F_16 ( V_1 ) ;
break;
case V_47 :
V_1 = F_17 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_13 ) ;
goto V_38;
}
V_9 -> V_48 &= ~ V_49 ;
if ( strcmp ( V_1 , L_14 ) == 0 )
V_9 -> V_48 |= V_50 ;
else if ( strcmp ( V_1 , L_15 ) == 0 )
V_9 -> V_48 |= V_51 ;
else if ( strcmp ( V_1 , L_16 ) == 0 ) {
V_9 -> V_48 |= V_52 ;
} else {
T_2 V_53 ;
V_9 -> V_48 |= V_54 ;
V_53 = F_18 ( V_1 , & V_16 , 10 ) ;
if ( * V_16 != '\0' ) {
V_17 = - V_3 ;
F_3 ( L_17 ,
V_1 ) ;
F_16 ( V_1 ) ;
goto V_38;
}
V_9 -> V_53 = F_11 ( F_12 () , V_53 ) ;
if ( ! F_13 ( V_9 -> V_53 ) ) {
V_17 = - V_3 ;
F_3 ( L_18 , V_1 ) ;
F_16 ( V_1 ) ;
goto V_38;
}
}
F_16 ( V_1 ) ;
break;
case V_55 :
#ifdef F_19
V_9 -> V_48 |= V_56 ;
#else
F_2 ( V_29 ,
L_19 ) ;
#endif
break;
default:
continue;
}
}
V_38:
F_16 ( V_12 ) ;
V_24:
return V_17 ;
}
struct V_57 * F_20 ( struct V_8 * V_9 ,
const char * V_58 , char * V_59 )
{
int V_60 = - V_3 ;
struct V_57 * V_61 ;
int V_62 ;
V_9 -> V_37 = F_6 ( V_63 , V_22 ) ;
if ( ! V_9 -> V_37 )
return F_21 ( - V_23 ) ;
V_9 -> V_40 = F_6 ( V_64 , V_22 ) ;
if ( ! V_9 -> V_40 ) {
F_16 ( V_9 -> V_37 ) ;
return F_21 ( - V_23 ) ;
}
F_22 ( & V_9 -> V_65 ) ;
V_62 = F_23 ( & V_9 -> V_66 , L_20 , V_67 ) ;
if ( V_62 ) {
F_16 ( V_9 -> V_40 ) ;
F_16 ( V_9 -> V_37 ) ;
return F_21 ( V_62 ) ;
}
F_24 ( & V_68 ) ;
F_25 ( & V_9 -> V_69 , & V_70 ) ;
F_26 ( & V_68 ) ;
V_9 -> V_53 = V_71 ;
V_9 -> V_32 = V_72 ;
V_9 -> V_34 = V_73 ;
V_9 -> V_74 = F_27 ( V_58 , V_59 ) ;
if ( F_28 ( V_9 -> V_74 ) ) {
V_60 = F_29 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
F_2 ( V_29 , L_21 ) ;
goto error;
}
V_9 -> V_48 = V_50 ;
if ( F_30 ( V_9 -> V_74 ) ) {
V_9 -> V_48 = V_52 ;
V_9 -> V_48 |= V_75 ;
} else if ( F_31 ( V_9 -> V_74 ) ) {
V_9 -> V_48 |= V_76 ;
}
V_62 = F_4 ( V_9 , V_59 ) ;
if ( V_62 < 0 ) {
V_60 = V_62 ;
goto error;
}
V_9 -> V_77 = V_9 -> V_74 -> V_78 - V_79 ;
if ( ! F_32 ( V_9 ) &&
( ( V_9 -> V_48 & V_49 ) == V_52 ) ) {
V_9 -> V_48 &= ~ V_49 ;
V_9 -> V_48 |= V_50 ;
}
if ( ! ( F_33 ( V_9 ) || F_32 ( V_9 ) ) &&
( ( V_9 -> V_48 & V_49 ) == V_50 ) ) {
V_9 -> V_48 &= ~ V_49 ;
V_9 -> V_48 |= V_51 ;
V_9 -> V_53 = V_71 ;
}
if ( ! F_32 ( V_9 ) ||
! ( ( V_9 -> V_48 & V_49 ) == V_52 ) ) {
V_9 -> V_48 &= ~ V_80 ;
}
V_61 = F_34 ( V_9 -> V_74 , NULL , V_9 -> V_37 , V_71 ,
V_9 -> V_40 ) ;
if ( F_28 ( V_61 ) ) {
V_60 = F_29 ( V_61 ) ;
V_61 = NULL ;
F_2 ( V_29 , L_22 ) ;
goto error;
}
if ( ( V_9 -> V_48 & V_49 ) == V_54 )
V_61 -> V_53 = V_9 -> V_53 ;
else
V_61 -> V_53 = V_71 ;
#ifdef F_5
F_35 ( V_9 ) ;
#endif
return V_61 ;
error:
F_36 ( & V_9 -> V_66 ) ;
return F_21 ( V_60 ) ;
}
void F_37 ( struct V_8 * V_9 )
{
if ( V_9 -> V_74 ) {
F_38 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
}
#ifdef F_5
if ( V_9 -> V_81 ) {
F_39 ( V_9 ) ;
F_16 ( V_9 -> V_21 ) ;
}
#endif
F_16 ( V_9 -> V_37 ) ;
F_16 ( V_9 -> V_40 ) ;
F_36 ( & V_9 -> V_66 ) ;
F_24 ( & V_68 ) ;
F_40 ( & V_9 -> V_69 ) ;
F_26 ( & V_68 ) ;
}
void F_41 ( struct V_8 * V_9 ) {
F_2 ( V_29 , L_23 , V_9 ) ;
F_42 ( V_9 -> V_74 ) ;
}
void F_43 ( struct V_8 * V_9 )
{
F_2 ( V_29 , L_24 , V_9 ) ;
F_44 ( V_9 -> V_74 ) ;
}
static T_3 F_45 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
T_3 V_87 = 0 , V_88 = 0 , V_89 = V_90 ;
struct V_8 * V_9 ;
F_24 ( & V_68 ) ;
F_46 (v9ses, &v9fs_sessionlist, slist) {
if ( V_9 -> V_21 ) {
V_87 = snprintf ( V_86 , V_89 , L_25 , V_9 -> V_21 ) ;
if ( V_87 < 0 ) {
V_88 = V_87 ;
break;
}
V_88 += V_87 ;
V_89 -= V_87 ;
}
}
F_26 ( & V_68 ) ;
return V_88 ;
}
static int F_47 ( void )
{
V_91 = F_48 ( L_20 , V_92 ) ;
if ( ! V_91 )
return - V_23 ;
if ( F_49 ( V_91 , & V_93 ) ) {
F_50 ( V_91 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_51 ( void )
{
F_52 ( V_91 , & V_93 ) ;
F_50 ( V_91 ) ;
}
static void F_53 ( void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
#ifdef F_5
V_96 -> V_81 = NULL ;
#endif
memset ( & V_96 -> V_97 , 0 , sizeof( V_96 -> V_97 ) ) ;
F_54 ( & V_96 -> V_98 ) ;
}
static int F_55 ( void )
{
V_99 = F_56 ( L_26 ,
sizeof( struct V_95 ) ,
0 , ( V_100 |
V_101 ) ,
F_53 ) ;
if ( ! V_99 )
return - V_23 ;
return 0 ;
}
static void F_57 ( void )
{
F_58 () ;
F_59 ( V_99 ) ;
}
static int F_60 ( void )
{
int V_17 ;
V_17 = F_55 () ;
if ( V_17 < 0 )
return V_17 ;
#ifdef F_5
V_17 = F_61 ( & V_102 ) ;
if ( V_17 < 0 )
F_57 () ;
#endif
return V_17 ;
}
static void F_62 ( void )
{
F_57 () ;
#ifdef F_5
F_63 ( & V_102 ) ;
#endif
}
static int T_4 F_64 ( void )
{
int V_103 ;
F_3 ( L_27 ) ;
V_103 = F_60 () ;
if ( V_103 < 0 ) {
F_65 ( L_28 ) ;
return V_103 ;
}
V_103 = F_47 () ;
if ( V_103 < 0 ) {
F_65 ( L_29 ) ;
goto V_104;
}
V_103 = F_66 ( & V_105 ) ;
if ( V_103 < 0 ) {
F_65 ( L_30 ) ;
goto V_106;
}
return 0 ;
V_106:
F_51 () ;
V_104:
F_62 () ;
return V_103 ;
}
static void T_5 F_67 ( void )
{
F_51 () ;
F_62 () ;
F_68 ( & V_105 ) ;
}
