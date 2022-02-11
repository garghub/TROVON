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
F_11 ( V_9 -> V_37 ) ;
V_9 -> V_37 = F_12 ( & args [ 0 ] ) ;
if ( ! V_9 -> V_37 ) {
V_17 = - V_23 ;
goto V_38;
}
break;
case V_39 :
F_11 ( V_9 -> V_40 ) ;
V_9 -> V_40 = F_12 ( & args [ 0 ] ) ;
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
V_9 -> V_21 = F_12 ( & args [ 0 ] ) ;
#endif
break;
case V_46 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_10 ) ;
goto V_38;
}
V_17 = F_1 ( V_1 ) ;
if ( V_17 == - V_3 ) {
F_11 ( V_1 ) ;
goto V_38;
}
V_9 -> V_20 = V_17 ;
F_11 ( V_1 ) ;
break;
case V_47 :
V_1 = F_12 ( & args [ 0 ] ) ;
if ( ! V_1 ) {
V_17 = - V_23 ;
F_2 ( V_29 ,
L_11 ) ;
goto V_38;
}
V_9 -> V_48 &= ~ V_49 ;
if ( strcmp ( V_1 , L_12 ) == 0 )
V_9 -> V_48 |= V_50 ;
else if ( strcmp ( V_1 , L_13 ) == 0 )
V_9 -> V_48 |= V_51 ;
else if ( strcmp ( V_1 , L_14 ) == 0 ) {
V_9 -> V_48 |= V_52 ;
} else {
V_9 -> V_48 |= V_53 ;
V_9 -> V_54 = F_13 ( V_1 , & V_16 , 10 ) ;
if ( * V_16 != '\0' ) {
V_17 = - V_3 ;
F_3 ( L_15 ,
V_1 ) ;
F_11 ( V_1 ) ;
goto V_38;
}
}
F_11 ( V_1 ) ;
break;
case V_55 :
#ifdef F_14
V_9 -> V_48 |= V_56 ;
#else
F_2 ( V_29 ,
L_16 ) ;
#endif
break;
default:
continue;
}
}
V_38:
F_11 ( V_12 ) ;
V_24:
return V_17 ;
}
struct V_57 * F_15 ( struct V_8 * V_9 ,
const char * V_58 , char * V_59 )
{
int V_60 = - V_3 ;
struct V_57 * V_61 ;
int V_62 ;
V_9 -> V_37 = F_6 ( V_63 , V_22 ) ;
if ( ! V_9 -> V_37 )
return F_16 ( - V_23 ) ;
V_9 -> V_40 = F_6 ( V_64 , V_22 ) ;
if ( ! V_9 -> V_40 ) {
F_11 ( V_9 -> V_37 ) ;
return F_16 ( - V_23 ) ;
}
F_17 ( & V_9 -> V_65 ) ;
V_62 = F_18 ( & V_9 -> V_66 , L_17 , V_67 ) ;
if ( V_62 ) {
F_11 ( V_9 -> V_40 ) ;
F_11 ( V_9 -> V_37 ) ;
return F_16 ( V_62 ) ;
}
F_19 ( & V_68 ) ;
F_20 ( & V_9 -> V_69 , & V_70 ) ;
F_21 ( & V_68 ) ;
V_9 -> V_54 = ~ 0 ;
V_9 -> V_32 = V_71 ;
V_9 -> V_34 = V_72 ;
V_9 -> V_73 = F_22 ( V_58 , V_59 ) ;
if ( F_23 ( V_9 -> V_73 ) ) {
V_60 = F_24 ( V_9 -> V_73 ) ;
V_9 -> V_73 = NULL ;
F_2 ( V_29 , L_18 ) ;
goto error;
}
V_9 -> V_48 = V_50 ;
if ( F_25 ( V_9 -> V_73 ) ) {
V_9 -> V_48 = V_52 ;
V_9 -> V_48 |= V_74 ;
} else if ( F_26 ( V_9 -> V_73 ) ) {
V_9 -> V_48 |= V_75 ;
}
V_62 = F_4 ( V_9 , V_59 ) ;
if ( V_62 < 0 ) {
V_60 = V_62 ;
goto error;
}
V_9 -> V_76 = V_9 -> V_73 -> V_77 - V_78 ;
if ( ! F_27 ( V_9 ) &&
( ( V_9 -> V_48 & V_49 ) == V_52 ) ) {
V_9 -> V_48 &= ~ V_49 ;
V_9 -> V_48 |= V_50 ;
}
if ( ! ( F_28 ( V_9 ) || F_27 ( V_9 ) ) &&
( ( V_9 -> V_48 & V_49 ) == V_50 ) ) {
V_9 -> V_48 &= ~ V_49 ;
V_9 -> V_48 |= V_51 ;
V_9 -> V_54 = ~ 0 ;
}
if ( ! F_27 ( V_9 ) ||
! ( ( V_9 -> V_48 & V_49 ) == V_52 ) ) {
V_9 -> V_48 &= ~ V_79 ;
}
V_61 = F_29 ( V_9 -> V_73 , NULL , V_9 -> V_37 , ~ 0 ,
V_9 -> V_40 ) ;
if ( F_23 ( V_61 ) ) {
V_60 = F_24 ( V_61 ) ;
V_61 = NULL ;
F_2 ( V_29 , L_19 ) ;
goto error;
}
if ( ( V_9 -> V_48 & V_49 ) == V_53 )
V_61 -> V_54 = V_9 -> V_54 ;
else
V_61 -> V_54 = ~ 0 ;
#ifdef F_5
F_30 ( V_9 ) ;
#endif
return V_61 ;
error:
F_31 ( & V_9 -> V_66 ) ;
return F_16 ( V_60 ) ;
}
void F_32 ( struct V_8 * V_9 )
{
if ( V_9 -> V_73 ) {
F_33 ( V_9 -> V_73 ) ;
V_9 -> V_73 = NULL ;
}
#ifdef F_5
if ( V_9 -> V_80 ) {
F_34 ( V_9 ) ;
F_11 ( V_9 -> V_21 ) ;
}
#endif
F_11 ( V_9 -> V_37 ) ;
F_11 ( V_9 -> V_40 ) ;
F_31 ( & V_9 -> V_66 ) ;
F_19 ( & V_68 ) ;
F_35 ( & V_9 -> V_69 ) ;
F_21 ( & V_68 ) ;
}
void F_36 ( struct V_8 * V_9 ) {
F_2 ( V_29 , L_20 , V_9 ) ;
F_37 ( V_9 -> V_73 ) ;
}
void F_38 ( struct V_8 * V_9 )
{
F_2 ( V_29 , L_21 , V_9 ) ;
F_39 ( V_9 -> V_73 ) ;
}
static T_2 F_40 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
T_2 V_86 = 0 , V_87 = 0 , V_88 = V_89 ;
struct V_8 * V_9 ;
F_19 ( & V_68 ) ;
F_41 (v9ses, &v9fs_sessionlist, slist) {
if ( V_9 -> V_21 ) {
V_86 = snprintf ( V_85 , V_88 , L_22 , V_9 -> V_21 ) ;
if ( V_86 < 0 ) {
V_87 = V_86 ;
break;
}
V_87 += V_86 ;
V_88 -= V_86 ;
}
}
F_21 ( & V_68 ) ;
return V_87 ;
}
static int F_42 ( void )
{
V_90 = F_43 ( L_17 , V_91 ) ;
if ( ! V_90 )
return - V_23 ;
if ( F_44 ( V_90 , & V_92 ) ) {
F_45 ( V_90 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_46 ( void )
{
F_47 ( V_90 , & V_92 ) ;
F_45 ( V_90 ) ;
}
static void F_48 ( void * V_93 )
{
struct V_94 * V_95 = (struct V_94 * ) V_93 ;
#ifdef F_5
V_95 -> V_80 = NULL ;
#endif
memset ( & V_95 -> V_96 , 0 , sizeof( V_95 -> V_96 ) ) ;
F_49 ( & V_95 -> V_97 ) ;
}
static int F_50 ( void )
{
V_98 = F_51 ( L_23 ,
sizeof( struct V_94 ) ,
0 , ( V_99 |
V_100 ) ,
F_48 ) ;
if ( ! V_98 )
return - V_23 ;
return 0 ;
}
static void F_52 ( void )
{
F_53 () ;
F_54 ( V_98 ) ;
}
static int F_55 ( void )
{
int V_17 ;
V_17 = F_50 () ;
if ( V_17 < 0 )
return V_17 ;
#ifdef F_5
return F_56 ( & V_101 ) ;
#else
return V_17 ;
#endif
}
static void F_57 ( void )
{
F_52 () ;
#ifdef F_5
F_58 ( & V_101 ) ;
#endif
}
static int T_3 F_59 ( void )
{
int V_102 ;
F_3 ( L_24 ) ;
V_102 = F_55 () ;
if ( V_102 < 0 ) {
F_60 ( L_25 ) ;
return V_102 ;
}
V_102 = F_42 () ;
if ( V_102 < 0 ) {
F_60 ( L_26 ) ;
goto V_103;
}
V_102 = F_61 ( & V_104 ) ;
if ( V_102 < 0 ) {
F_60 ( L_27 ) ;
goto V_105;
}
return 0 ;
V_105:
F_46 () ;
V_103:
F_57 () ;
return V_102 ;
}
static void T_4 F_62 ( void )
{
F_46 () ;
F_57 () ;
F_63 ( & V_104 ) ;
}
