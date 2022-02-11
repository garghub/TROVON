static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
char * V_4 , * V_5 ;
T_1 args [ V_6 ] ;
char * V_7 ;
int V_8 = 0 ;
char * V_9 , * V_10 ;
int V_11 = 0 ;
V_2 -> V_12 = ~ 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
#ifdef F_2
V_2 -> V_15 = NULL ;
#endif
if ( ! V_3 )
return 0 ;
V_5 = F_3 ( V_3 , V_16 ) ;
if ( ! V_5 ) {
V_11 = - V_17 ;
goto V_18;
}
V_4 = V_5 ;
while ( ( V_7 = F_4 ( & V_4 , L_1 ) ) != NULL ) {
int V_19 ;
if ( ! * V_7 )
continue;
V_19 = F_5 ( V_7 , V_20 , args ) ;
if ( V_19 < V_21 ) {
int V_22 = F_6 ( & args [ 0 ] , & V_8 ) ;
if ( V_22 < 0 ) {
F_7 ( V_23 ,
L_2 ) ;
V_11 = V_22 ;
continue;
}
}
switch ( V_19 ) {
case V_24 :
V_2 -> V_13 = V_8 ;
#ifdef F_8
V_25 = V_8 ;
#endif
break;
case V_26 :
V_2 -> V_27 = V_8 ;
break;
case V_28 :
V_2 -> V_29 = V_8 ;
break;
case V_30 :
V_2 -> V_12 = V_8 ;
break;
case V_21 :
F_9 ( V_2 -> V_31 , & args [ 0 ] , V_32 ) ;
break;
case V_33 :
F_9 ( V_2 -> V_34 , & args [ 0 ] , V_32 ) ;
break;
case V_35 :
V_2 -> V_36 = 1 ;
break;
case V_37 :
V_2 -> V_14 = V_38 ;
break;
case V_39 :
V_2 -> V_14 = V_40 ;
break;
case V_41 :
#ifdef F_2
V_2 -> V_15 = F_10 ( & args [ 0 ] ) ;
#endif
break;
case V_42 :
V_9 = F_10 ( & args [ 0 ] ) ;
if ( ! V_9 ) {
V_11 = - V_17 ;
F_7 ( V_23 ,
L_3 ) ;
goto V_43;
}
if ( strcmp ( V_9 , L_4 ) == 0 )
V_2 -> V_14 = V_38 ;
else if ( strcmp ( V_9 , L_5 ) == 0 )
V_2 -> V_14 = V_40 ;
else
V_2 -> V_14 = V_44 ;
F_11 ( V_9 ) ;
break;
case V_45 :
V_9 = F_10 ( & args [ 0 ] ) ;
if ( ! V_9 ) {
V_11 = - V_17 ;
F_7 ( V_23 ,
L_6 ) ;
goto V_43;
}
V_2 -> V_46 &= ~ V_47 ;
if ( strcmp ( V_9 , L_7 ) == 0 )
V_2 -> V_46 |= V_48 ;
else if ( strcmp ( V_9 , L_8 ) == 0 )
V_2 -> V_46 |= V_49 ;
else if ( strcmp ( V_9 , L_9 ) == 0 ) {
V_2 -> V_46 |= V_50 ;
} else {
V_2 -> V_46 |= V_51 ;
V_2 -> V_52 = F_12 ( V_9 , & V_10 , 10 ) ;
if ( * V_10 != '\0' )
V_2 -> V_52 = ~ 0 ;
}
F_11 ( V_9 ) ;
break;
case V_53 :
#ifdef F_13
V_2 -> V_46 |= V_54 ;
#else
F_7 ( V_23 ,
L_10
L_11 ) ;
#endif
break;
default:
continue;
}
}
V_43:
F_11 ( V_5 ) ;
V_18:
return V_11 ;
}
struct V_55 * F_14 ( struct V_1 * V_2 ,
const char * V_56 , char * V_57 )
{
int V_58 = - V_59 ;
struct V_55 * V_60 ;
int V_61 ;
V_2 -> V_31 = F_15 () ;
if ( ! V_2 -> V_31 )
return F_16 ( - V_17 ) ;
V_2 -> V_34 = F_15 () ;
if ( ! V_2 -> V_34 ) {
F_17 ( V_2 -> V_31 ) ;
return F_16 ( - V_17 ) ;
}
F_18 ( & V_2 -> V_62 ) ;
V_61 = F_19 ( & V_2 -> V_63 , L_12 , V_64 ) ;
if ( V_61 ) {
F_17 ( V_2 -> V_34 ) ;
F_17 ( V_2 -> V_31 ) ;
return F_16 ( V_61 ) ;
}
F_20 ( & V_65 ) ;
F_21 ( & V_2 -> V_66 , & V_67 ) ;
F_22 ( & V_65 ) ;
strcpy ( V_2 -> V_31 , V_68 ) ;
strcpy ( V_2 -> V_34 , V_69 ) ;
V_2 -> V_52 = ~ 0 ;
V_2 -> V_27 = V_70 ;
V_2 -> V_29 = V_71 ;
V_2 -> V_72 = F_23 ( V_56 , V_57 ) ;
if ( F_24 ( V_2 -> V_72 ) ) {
V_58 = F_25 ( V_2 -> V_72 ) ;
V_2 -> V_72 = NULL ;
F_7 ( V_23 , L_13 ) ;
goto error;
}
V_2 -> V_46 = V_48 ;
if ( F_26 ( V_2 -> V_72 ) ) {
V_2 -> V_46 = V_50 ;
V_2 -> V_46 |= V_73 ;
} else if ( F_27 ( V_2 -> V_72 ) ) {
V_2 -> V_46 |= V_74 ;
}
V_61 = F_1 ( V_2 , V_57 ) ;
if ( V_61 < 0 ) {
V_58 = V_61 ;
goto error;
}
V_2 -> V_75 = V_2 -> V_72 -> V_76 - V_77 ;
if ( ! F_28 ( V_2 ) &&
( ( V_2 -> V_46 & V_47 ) == V_50 ) ) {
V_2 -> V_46 &= ~ V_47 ;
V_2 -> V_46 |= V_48 ;
}
if ( ! ( F_29 ( V_2 ) || F_28 ( V_2 ) ) &&
( ( V_2 -> V_46 & V_47 ) == V_48 ) ) {
V_2 -> V_46 &= ~ V_47 ;
V_2 -> V_46 |= V_49 ;
V_2 -> V_52 = ~ 0 ;
}
if ( ! F_28 ( V_2 ) ||
! ( ( V_2 -> V_46 & V_47 ) == V_50 ) ) {
V_2 -> V_46 &= ~ V_78 ;
}
V_60 = F_30 ( V_2 -> V_72 , NULL , V_2 -> V_31 , ~ 0 ,
V_2 -> V_34 ) ;
if ( F_24 ( V_60 ) ) {
V_58 = F_25 ( V_60 ) ;
V_60 = NULL ;
F_7 ( V_23 , L_14 ) ;
goto error;
}
if ( ( V_2 -> V_46 & V_47 ) == V_51 )
V_60 -> V_52 = V_2 -> V_52 ;
else
V_60 -> V_52 = ~ 0 ;
#ifdef F_2
F_31 ( V_2 ) ;
#endif
return V_60 ;
error:
F_32 ( & V_2 -> V_63 ) ;
return F_16 ( V_58 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_72 ) {
F_34 ( V_2 -> V_72 ) ;
V_2 -> V_72 = NULL ;
}
#ifdef F_2
if ( V_2 -> V_79 ) {
F_35 ( V_2 ) ;
F_11 ( V_2 -> V_15 ) ;
}
#endif
F_17 ( V_2 -> V_31 ) ;
F_17 ( V_2 -> V_34 ) ;
F_32 ( & V_2 -> V_63 ) ;
F_20 ( & V_65 ) ;
F_36 ( & V_2 -> V_66 ) ;
F_22 ( & V_65 ) ;
}
void F_37 ( struct V_1 * V_2 ) {
F_7 ( V_23 , L_15 , V_2 ) ;
F_38 ( V_2 -> V_72 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_7 ( V_23 , L_16 , V_2 ) ;
F_40 ( V_2 -> V_72 ) ;
}
static T_2 F_41 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
char * V_84 )
{
T_2 V_85 = 0 , V_86 = 0 , V_87 = V_88 ;
struct V_1 * V_2 ;
F_20 ( & V_65 ) ;
F_42 (v9ses, &v9fs_sessionlist, slist) {
if ( V_2 -> V_15 ) {
V_85 = snprintf ( V_84 , V_87 , L_17 , V_2 -> V_15 ) ;
if ( V_85 < 0 ) {
V_86 = V_85 ;
break;
}
V_86 += V_85 ;
V_87 -= V_85 ;
}
}
F_22 ( & V_65 ) ;
return V_86 ;
}
static int F_43 ( void )
{
V_89 = F_44 ( L_12 , V_90 ) ;
if ( ! V_89 )
return - V_17 ;
if ( F_45 ( V_89 , & V_91 ) ) {
F_46 ( V_89 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_47 ( void )
{
F_48 ( V_89 , & V_91 ) ;
F_46 ( V_89 ) ;
}
static void F_49 ( void * V_92 )
{
struct V_93 * V_94 = (struct V_93 * ) V_92 ;
#ifdef F_2
V_94 -> V_79 = NULL ;
V_94 -> V_95 = NULL ;
#endif
F_50 ( & V_94 -> V_96 ) ;
}
static int F_51 ( void )
{
V_97 = F_52 ( L_18 ,
sizeof( struct V_93 ) ,
0 , ( V_98 |
V_99 ) ,
F_49 ) ;
if ( ! V_97 )
return - V_17 ;
return 0 ;
}
static void F_53 ( void )
{
F_54 ( V_97 ) ;
}
static int F_55 ( void )
{
int V_11 ;
V_11 = F_51 () ;
if ( V_11 < 0 )
return V_11 ;
#ifdef F_2
return F_56 ( & V_100 ) ;
#else
return V_11 ;
#endif
}
static void F_57 ( void )
{
F_53 () ;
#ifdef F_2
F_58 ( & V_100 ) ;
#endif
}
static int T_3 F_59 ( void )
{
int V_101 ;
F_60 ( V_102 L_19 ) ;
V_101 = F_61 ( & V_103 ) ;
if ( V_101 < 0 ) {
F_60 ( V_104 L_20 ) ;
return V_101 ;
}
V_101 = F_55 () ;
if ( V_101 < 0 ) {
F_60 ( V_104 L_21 ) ;
goto V_105;
}
V_101 = F_43 () ;
if ( V_101 < 0 ) {
F_60 ( V_104 L_22 ) ;
goto V_106;
}
return 0 ;
V_106:
F_47 () ;
V_105:
F_62 ( & V_103 ) ;
return V_101 ;
}
static void T_4 F_63 ( void )
{
F_47 () ;
F_57 () ;
F_62 ( & V_103 ) ;
}
