static int F_1 ( T_1 V_1 , T_2 * V_2 )
{
int V_3 ;
int V_4 = V_5 ;
char V_6 [ V_7 ] ;
while ( F_2 ( V_1 ) && ! F_3 ( V_1 ) ) {
V_3 = F_4 ( V_1 , V_6 , V_7 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( L_1 ) ;
goto V_8;
}
if ( V_3 == 0 ) {
goto V_8;
}
if ( fwrite ( V_6 , 1 , V_3 , V_2 ) != ( V_9 ) V_3 ) {
F_5 ( L_2 ) ;
V_4 = V_10 ;
goto V_8;
}
fflush ( V_2 ) ;
}
while ( F_2 ( V_1 ) && ! F_3 ( V_1 ) ) {
V_3 = F_4 ( V_1 , V_6 , V_7 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( L_1 ) ;
goto V_8;
}
if ( fwrite ( V_6 , 1 , V_3 , V_11 ) != ( V_9 ) V_3 ) {
F_5 ( L_3 ) ;
break;
}
}
V_8:
if ( F_6 ( V_1 ) != V_12 ) {
F_5 ( L_4 ) ;
V_4 = V_10 ;
}
return V_4 ;
}
static char * F_7 ( const T_3 V_13 )
{
T_4 * V_14 = F_8 () ;
char * V_15 = F_9 ( V_14 , V_13 ) ;
F_10 ( V_14 , V_16 ) ;
return V_15 ;
}
static T_1 F_11 ( T_5 V_17 , const char * V_18 , const T_6 V_19 , const char * V_20 ,
const char * V_21 , const T_7 V_22 )
{
T_8 * V_23 ;
T_1 V_1 ;
char * V_24 = NULL ;
char * V_25 = NULL ;
char * V_26 = NULL ;
unsigned int V_13 = 22 ;
if ( ! V_20 )
V_20 = L_5 ;
V_1 = F_12 ( V_17 ) ;
if ( ! V_1 ) {
F_5 ( L_6 ) ;
return NULL ;
}
if ( F_13 ( V_1 ) != V_12 ) {
F_5 ( L_7 ) ;
F_14 ( V_1 ) ;
return NULL ;
}
F_15 ( V_17 , & V_13 ) ;
if ( V_18 && * V_18 ) {
V_23 = F_16 ( V_18 ) ;
F_17 ( L_8 ) ;
} else {
V_24 = F_18 ( V_20 ) ;
V_25 = F_18 ( V_21 ? V_21 : L_9 ) ;
if ( V_22 > 0 )
V_26 = F_19 ( L_10 , V_22 ) ;
V_23 = F_19 ( L_11 , V_19 ? L_12 : L_9 , V_24 ,
V_26 ? V_26 : L_9 , V_25 ) ;
}
F_17 ( L_13 , V_23 ) ;
if ( F_20 ( V_1 , V_23 ) != V_12 ) {
F_5 ( L_14 ) ;
F_21 ( V_1 ) ;
F_14 ( V_1 ) ;
V_1 = NULL ;
}
V_16 ( V_24 ) ;
V_16 ( V_25 ) ;
V_16 ( V_23 ) ;
if ( V_26 )
V_16 ( V_26 ) ;
return V_1 ;
}
static int F_22 ( const char * V_27 , const unsigned int V_28 , const char * V_29 , const char * V_30 ,
const char * V_31 , const char * V_32 , const char * V_20 , const char * V_21 , const char * V_18 ,
const T_6 V_19 , const T_7 V_22 , const char * V_33 )
{
T_5 V_17 = NULL ;
T_1 V_1 = NULL ;
T_2 * V_2 = stdout ;
int V_4 = V_10 ;
char * V_34 = NULL ;
if ( F_23 ( V_33 , L_15 ) ) {
V_2 = fopen ( V_33 , L_16 ) ;
if ( V_2 == NULL ) {
F_5 ( L_17 , V_33 , F_24 ( V_35 ) ) ;
return V_10 ;
}
}
V_17 = F_25 ( V_27 , V_28 , V_29 , V_30 , V_31 , V_32 , & V_34 ) ;
if ( ! V_17 ) {
F_5 ( L_18 , V_34 ) ;
goto V_36;
}
V_1 = F_11 ( V_17 , V_18 , V_19 , V_20 , V_21 , V_22 ) ;
if ( ! V_1 ) {
F_5 ( L_19 ) ;
goto V_36;
}
if ( F_1 ( V_1 , V_2 ) != V_5 ) {
F_5 ( L_20 ) ;
V_4 = V_10 ;
goto V_36;
}
V_4 = V_5 ;
V_36:
if ( V_34 )
F_5 ( L_21 , V_34 ) ;
V_16 ( V_34 ) ;
F_26 ( & V_17 , & V_1 ) ;
if ( F_23 ( V_33 , L_15 ) )
fclose ( V_2 ) ;
return V_4 ;
}
static char * F_9 ( T_4 * V_14 , const unsigned int V_13 )
{
T_9 * V_15 = F_27 ( NULL ) ;
T_4 * V_37 ;
if ( ! V_14 ) {
F_28 ( V_15 , L_22 , V_13 ) ;
} else {
F_28 ( V_15 , L_23 , ( char * ) V_14 -> V_38 ) ;
V_37 = F_29 ( V_14 ) ;
while ( V_37 ) {
F_28 ( V_15 , L_24 , ( char * ) V_37 -> V_38 ) ;
V_37 = F_29 ( V_37 ) ;
}
F_28 ( V_15 , L_25 , V_13 ) ;
}
return F_30 ( V_15 , FALSE ) ;
}
static int F_31 ( char * V_39 , unsigned int V_13 )
{
unsigned V_40 = 0 ;
char * V_41 ;
if ( ! V_39 ) {
F_5 ( L_26 ) ;
return V_10 ;
}
if ( F_23 ( V_39 , V_42 ) ) {
F_5 ( L_27 , V_42 ) ;
return V_10 ;
}
V_41 = F_7 ( V_13 ) ;
printf ( L_28
L_29
L_30 , V_40 ++ ) ;
printf ( L_31
L_32
L_33 , V_40 ++ ) ;
printf ( L_34
L_35
L_36 , V_40 ++ , F_32 () ) ;
printf ( L_37
L_38
L_39 , V_40 ++ ) ;
printf ( L_40
L_41 ,
V_40 ++ ) ;
printf ( L_42
L_43 ,
V_40 ++ ) ;
printf ( L_44
L_45
L_46 , V_40 ++ ) ;
printf ( L_47
L_48 , V_40 ++ ) ;
printf ( L_49
L_50 , V_40 ++ ) ;
printf ( L_51
L_52 , V_40 ++ ) ;
if ( V_41 )
printf ( L_53 , V_41 ) ;
printf ( L_54 ) ;
printf ( L_55
L_56 ,
V_40 ++ ) ;
V_16 ( V_41 ) ;
return V_5 ;
}
static char * F_33 ( const char * V_43 , const char * V_44 )
{
if ( ! V_43 && V_44 )
return F_16 ( V_44 ) ;
if ( ! V_44 && V_43 )
return F_16 ( V_43 ) ;
if ( ! V_44 && ! V_43 )
return NULL ;
return F_19 ( L_57 , V_43 , V_44 ) ;
}
int main ( int V_45 , char * * V_46 )
{
int V_47 ;
int V_48 = 0 ;
int V_49 ;
char * V_50 = NULL ;
T_3 V_13 = 22 ;
char * V_51 = NULL ;
char * V_52 = NULL ;
char * V_53 = NULL ;
char * V_54 = NULL ;
char * V_31 = NULL ;
char * V_32 = NULL ;
char * V_44 = NULL ;
T_7 V_22 = 0 ;
int V_4 = V_10 ;
T_10 * V_55 = F_34 ( T_10 , 1 ) ;
char * V_56 ;
char * V_57 = NULL ;
T_6 V_19 = FALSE ;
#ifdef F_35
T_11 V_58 ;
F_36 () ;
#endif
V_56 = F_37 ( L_58 ) ;
F_38 ( V_55 , V_46 [ 0 ] , V_59 , V_60 ,
V_61 , V_56 ) ;
V_16 ( V_56 ) ;
F_39 ( V_55 , V_42 , L_59 , 147 , L_60 ) ;
V_57 = F_19 (
L_61
L_62
L_63
L_64
L_65
L_66 , V_46 [ 0 ] , V_46 [ 0 ] , V_42 , V_46 [ 0 ] ,
V_42 , V_46 [ 0 ] , V_42 ) ;
F_40 ( V_55 , V_57 ) ;
V_16 ( V_57 ) ;
F_41 ( V_55 , L_67 , L_68 ) ;
F_41 ( V_55 , L_69 , L_70 ) ;
F_41 ( V_55 , L_71 , L_72 ) ;
F_41 ( V_55 , L_73 , L_74 ) ;
F_41 ( V_55 , L_75 , L_76 ) ;
F_41 ( V_55 , L_77 , L_78 ) ;
F_41 ( V_55 , L_79 , L_80 ) ;
F_41 ( V_55 , L_81 , L_82 ) ;
F_41 ( V_55 , L_83 , L_84 ) ;
F_41 ( V_55 , L_85 , L_86 ) ;
F_41 ( V_55 , L_87 , L_88 ) ;
F_41 ( V_55 , L_89 , L_90
L_91 ) ;
F_41 ( V_55 , L_92 , L_93 ) ;
V_62 = 0 ;
V_63 = 0 ;
if ( V_45 == 1 ) {
F_42 ( V_55 ) ;
goto V_8;
}
while ( ( V_47 = F_43 ( V_45 , V_46 , L_94 , V_64 , & V_48 ) ) != - 1 ) {
switch ( V_47 ) {
case V_65 :
F_42 ( V_55 ) ;
V_4 = V_5 ;
goto V_8;
case V_66 :
printf ( L_95 , V_55 -> V_67 ) ;
V_4 = V_5 ;
goto V_8;
case V_68 :
V_16 ( V_50 ) ;
V_50 = F_16 ( V_69 ) ;
break;
case V_70 :
if ( ! F_44 ( V_69 , NULL , & V_13 ) || V_13 == 0 ) {
F_5 ( L_96 , V_69 ) ;
goto V_8;
}
break;
case V_71 :
V_16 ( V_51 ) ;
V_51 = F_16 ( V_69 ) ;
break;
case V_72 :
V_16 ( V_52 ) ;
V_52 = F_16 ( V_69 ) ;
memset ( V_69 , 'X' , strlen ( V_69 ) ) ;
break;
case V_73 :
V_16 ( V_31 ) ;
V_31 = F_16 ( V_69 ) ;
break;
case V_74 :
V_16 ( V_32 ) ;
V_32 = F_16 ( V_69 ) ;
memset ( V_69 , 'X' , strlen ( V_69 ) ) ;
break;
case V_75 :
V_16 ( V_53 ) ;
V_53 = F_16 ( V_69 ) ;
break;
case V_76 :
V_16 ( V_54 ) ;
V_54 = F_16 ( V_69 ) ;
break;
case V_77 :
V_19 = TRUE ;
break;
case V_78 :
V_16 ( V_44 ) ;
V_44 = F_16 ( V_69 ) ;
break;
case V_79 :
if ( ! F_45 ( V_69 , NULL , & V_22 ) ) {
F_5 ( L_97 , V_69 ) ;
goto V_8;
}
break;
case ':' :
F_5 ( L_98 , V_46 [ V_63 - 1 ] ) ;
break;
default:
if ( ! F_46 ( V_55 , V_47 - V_80 , V_69 ) ) {
F_5 ( L_99 , V_46 [ V_63 - 1 ] ) ;
goto V_8;
}
}
}
for ( V_49 = 0 ; V_49 < V_45 ; V_49 ++ )
F_17 ( L_21 , V_46 [ V_49 ] ) ;
if ( V_63 != V_45 ) {
F_5 ( L_100 , V_46 [ V_63 ] ) ;
goto V_8;
}
if ( F_47 ( V_55 ) ) {
V_4 = V_5 ;
goto V_8;
}
if ( V_55 -> V_81 ) {
V_4 = F_31 ( V_55 -> V_39 , V_13 ) ;
goto V_8;
}
#ifdef F_35
V_47 = F_48 ( F_49 ( 1 , 1 ) , & V_58 ) ;
if ( V_47 != 0 ) {
F_5 ( L_101 , V_47 ) ;
goto V_8;
}
#endif
if ( V_55 -> V_82 ) {
char * V_15 ;
if ( ! V_50 ) {
F_5 ( L_102 ) ;
goto V_8;
}
V_15 = F_33 ( V_55 -> V_83 , V_44 ) ;
V_4 = F_22 ( V_50 , V_13 , V_51 ,
V_52 , V_31 , V_32 , V_53 ,
V_15 , V_54 , V_19 , V_22 , V_55 -> V_33 ) ;
V_16 ( V_15 ) ;
} else {
F_17 ( L_103 ) ;
V_4 = V_10 ;
}
V_8:
V_16 ( V_50 ) ;
V_16 ( V_51 ) ;
V_16 ( V_52 ) ;
V_16 ( V_53 ) ;
V_16 ( V_54 ) ;
V_16 ( V_31 ) ;
V_16 ( V_32 ) ;
V_16 ( V_44 ) ;
F_50 ( & V_55 ) ;
return V_4 ;
}
int T_12
F_51 ( struct V_84 * V_85 ,
struct V_84 * V_86 ,
char * V_87 ,
int V_88 )
{
return main ( V_89 , V_90 ) ;
}
