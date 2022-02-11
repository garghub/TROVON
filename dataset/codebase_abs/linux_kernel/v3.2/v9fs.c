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
F_3 ( V_8 L_7 , V_1 ) ;
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
V_10 -> V_21 = V_7 ;
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
while ( ( V_15 = F_7 ( & V_12 , L_8 ) ) != NULL ) {
int V_26 , V_27 ;
if ( ! * V_15 )
continue;
V_26 = F_8 ( V_15 , V_28 , args ) ;
switch ( V_26 ) {
case V_29 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_9 ) ;
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
L_9 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_33 = V_16 ;
break;
case V_34 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_9 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_35 = V_16 ;
break;
case V_36 :
V_27 = F_9 ( & args [ 0 ] , & V_16 ) ;
if ( V_27 < 0 ) {
F_2 ( V_30 ,
L_9 ) ;
V_18 = V_27 ;
continue;
}
V_10 -> V_19 = V_16 ;
break;
case V_37 :
F_11 ( V_10 -> V_38 , & args [ 0 ] , V_39 ) ;
break;
case V_40 :
F_11 ( V_10 -> V_41 , & args [ 0 ] , V_39 ) ;
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
#ifdef F_5
V_10 -> V_22 = F_12 ( & args [ 0 ] ) ;
#endif
break;
case V_47 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_18 = - V_24 ;
F_2 ( V_30 ,
L_10 ) ;
goto V_48;
}
V_18 = F_1 ( V_1 ) ;
if ( V_18 == - V_3 ) {
F_13 ( V_1 ) ;
goto V_48;
}
V_10 -> V_21 = V_18 ;
F_13 ( V_1 ) ;
break;
case V_49 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_18 = - V_24 ;
F_2 ( V_30 ,
L_11 ) ;
goto V_48;
}
V_10 -> V_50 &= ~ V_51 ;
if ( strcmp ( V_1 , L_12 ) == 0 )
V_10 -> V_50 |= V_52 ;
else if ( strcmp ( V_1 , L_13 ) == 0 )
V_10 -> V_50 |= V_53 ;
else if ( strcmp ( V_1 , L_14 ) == 0 ) {
V_10 -> V_50 |= V_54 ;
} else {
V_10 -> V_50 |= V_55 ;
V_10 -> V_56 = F_14 ( V_1 , & V_17 , 10 ) ;
if ( * V_17 != '\0' ) {
V_18 = - V_3 ;
F_3 ( V_8 L_15
L_16 , V_1 ) ;
F_13 ( V_1 ) ;
goto V_48;
}
}
F_13 ( V_1 ) ;
break;
case V_57 :
#ifdef F_15
V_10 -> V_50 |= V_58 ;
#else
F_2 ( V_30 ,
L_17
L_18 ) ;
#endif
break;
default:
continue;
}
}
V_48:
F_13 ( V_13 ) ;
V_25:
return V_18 ;
}
struct V_59 * F_16 ( struct V_9 * V_10 ,
const char * V_60 , char * V_61 )
{
int V_62 = - V_3 ;
struct V_59 * V_63 ;
int V_64 ;
V_10 -> V_38 = F_17 () ;
if ( ! V_10 -> V_38 )
return F_18 ( - V_24 ) ;
V_10 -> V_41 = F_17 () ;
if ( ! V_10 -> V_41 ) {
F_19 ( V_10 -> V_38 ) ;
return F_18 ( - V_24 ) ;
}
F_20 ( & V_10 -> V_65 ) ;
V_64 = F_21 ( & V_10 -> V_66 , L_19 , V_67 ) ;
if ( V_64 ) {
F_19 ( V_10 -> V_41 ) ;
F_19 ( V_10 -> V_38 ) ;
return F_18 ( V_64 ) ;
}
F_22 ( & V_68 ) ;
F_23 ( & V_10 -> V_69 , & V_70 ) ;
F_24 ( & V_68 ) ;
strcpy ( V_10 -> V_38 , V_71 ) ;
strcpy ( V_10 -> V_41 , V_72 ) ;
V_10 -> V_56 = ~ 0 ;
V_10 -> V_33 = V_73 ;
V_10 -> V_35 = V_74 ;
V_10 -> V_75 = F_25 ( V_60 , V_61 ) ;
if ( F_26 ( V_10 -> V_75 ) ) {
V_62 = F_27 ( V_10 -> V_75 ) ;
V_10 -> V_75 = NULL ;
F_2 ( V_30 , L_20 ) ;
goto error;
}
V_10 -> V_50 = V_52 ;
if ( F_28 ( V_10 -> V_75 ) ) {
V_10 -> V_50 = V_54 ;
V_10 -> V_50 |= V_76 ;
} else if ( F_29 ( V_10 -> V_75 ) ) {
V_10 -> V_50 |= V_77 ;
}
V_64 = F_4 ( V_10 , V_61 ) ;
if ( V_64 < 0 ) {
V_62 = V_64 ;
goto error;
}
V_10 -> V_78 = V_10 -> V_75 -> V_79 - V_80 ;
if ( ! F_30 ( V_10 ) &&
( ( V_10 -> V_50 & V_51 ) == V_54 ) ) {
V_10 -> V_50 &= ~ V_51 ;
V_10 -> V_50 |= V_52 ;
}
if ( ! ( F_31 ( V_10 ) || F_30 ( V_10 ) ) &&
( ( V_10 -> V_50 & V_51 ) == V_52 ) ) {
V_10 -> V_50 &= ~ V_51 ;
V_10 -> V_50 |= V_53 ;
V_10 -> V_56 = ~ 0 ;
}
if ( ! F_30 ( V_10 ) ||
! ( ( V_10 -> V_50 & V_51 ) == V_54 ) ) {
V_10 -> V_50 &= ~ V_81 ;
}
V_63 = F_32 ( V_10 -> V_75 , NULL , V_10 -> V_38 , ~ 0 ,
V_10 -> V_41 ) ;
if ( F_26 ( V_63 ) ) {
V_62 = F_27 ( V_63 ) ;
V_63 = NULL ;
F_2 ( V_30 , L_21 ) ;
goto error;
}
if ( ( V_10 -> V_50 & V_51 ) == V_55 )
V_63 -> V_56 = V_10 -> V_56 ;
else
V_63 -> V_56 = ~ 0 ;
#ifdef F_5
F_33 ( V_10 ) ;
#endif
return V_63 ;
error:
F_34 ( & V_10 -> V_66 ) ;
return F_18 ( V_62 ) ;
}
void F_35 ( struct V_9 * V_10 )
{
if ( V_10 -> V_75 ) {
F_36 ( V_10 -> V_75 ) ;
V_10 -> V_75 = NULL ;
}
#ifdef F_5
if ( V_10 -> V_82 ) {
F_37 ( V_10 ) ;
F_13 ( V_10 -> V_22 ) ;
}
#endif
F_19 ( V_10 -> V_38 ) ;
F_19 ( V_10 -> V_41 ) ;
F_34 ( & V_10 -> V_66 ) ;
F_22 ( & V_68 ) ;
F_38 ( & V_10 -> V_69 ) ;
F_24 ( & V_68 ) ;
}
void F_39 ( struct V_9 * V_10 ) {
F_2 ( V_30 , L_22 , V_10 ) ;
F_40 ( V_10 -> V_75 ) ;
}
void F_41 ( struct V_9 * V_10 )
{
F_2 ( V_30 , L_23 , V_10 ) ;
F_42 ( V_10 -> V_75 ) ;
}
static T_2 F_43 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 )
{
T_2 V_88 = 0 , V_89 = 0 , V_90 = V_91 ;
struct V_9 * V_10 ;
F_22 ( & V_68 ) ;
F_44 (v9ses, &v9fs_sessionlist, slist) {
if ( V_10 -> V_22 ) {
V_88 = snprintf ( V_87 , V_90 , L_24 , V_10 -> V_22 ) ;
if ( V_88 < 0 ) {
V_89 = V_88 ;
break;
}
V_89 += V_88 ;
V_90 -= V_88 ;
}
}
F_24 ( & V_68 ) ;
return V_89 ;
}
static int F_45 ( void )
{
V_92 = F_46 ( L_19 , V_93 ) ;
if ( ! V_92 )
return - V_24 ;
if ( F_47 ( V_92 , & V_94 ) ) {
F_48 ( V_92 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_49 ( void )
{
F_50 ( V_92 , & V_94 ) ;
F_48 ( V_92 ) ;
}
static void F_51 ( void * V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
#ifdef F_5
V_97 -> V_82 = NULL ;
#endif
memset ( & V_97 -> V_98 , 0 , sizeof( V_97 -> V_98 ) ) ;
F_52 ( & V_97 -> V_99 ) ;
}
static int F_53 ( void )
{
V_100 = F_54 ( L_25 ,
sizeof( struct V_96 ) ,
0 , ( V_101 |
V_102 ) ,
F_51 ) ;
if ( ! V_100 )
return - V_24 ;
return 0 ;
}
static void F_55 ( void )
{
F_56 ( V_100 ) ;
}
static int F_57 ( void )
{
int V_18 ;
V_18 = F_53 () ;
if ( V_18 < 0 )
return V_18 ;
#ifdef F_5
return F_58 ( & V_103 ) ;
#else
return V_18 ;
#endif
}
static void F_59 ( void )
{
F_55 () ;
#ifdef F_5
F_60 ( & V_103 ) ;
#endif
}
static int T_3 F_61 ( void )
{
int V_104 ;
F_3 ( V_8 L_26 ) ;
V_104 = F_62 ( & V_105 ) ;
if ( V_104 < 0 ) {
F_3 ( V_106 L_27 ) ;
return V_104 ;
}
V_104 = F_57 () ;
if ( V_104 < 0 ) {
F_3 ( V_106 L_28 ) ;
goto V_107;
}
V_104 = F_45 () ;
if ( V_104 < 0 ) {
F_3 ( V_106 L_29 ) ;
goto V_108;
}
return 0 ;
V_108:
F_49 () ;
V_107:
F_63 ( & V_105 ) ;
return V_104 ;
}
static void T_4 F_64 ( void )
{
F_49 () ;
F_59 () ;
F_63 ( & V_105 ) ;
}
