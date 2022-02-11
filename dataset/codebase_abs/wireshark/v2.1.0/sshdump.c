static void F_1 ( T_1 V_1 , int V_2 )
{
int V_3 ;
char V_4 [ V_5 ] ;
do {
V_3 = F_2 ( V_1 , V_4 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_4 , V_3 ) != V_3 ) {
F_4 ( L_1 , F_5 ( V_6 ) ) ;
return;
}
} while( V_3 > 0 );
do {
V_3 = F_2 ( V_1 , V_4 , V_5 , 1 ) ;
if ( F_3 ( V_7 , V_4 , V_3 ) != V_3 ) {
return;
}
} while( V_3 > 0 );
if ( F_6 ( V_1 ) != V_8 )
return;
}
static char * F_7 ( const unsigned int V_9 )
{
T_2 * V_10 = F_8 () ;
char * V_11 = F_9 ( V_10 , V_9 ) ;
F_10 ( V_10 , V_12 ) ;
return V_11 ;
}
static T_1 F_11 ( T_3 V_13 , const char * V_14 , const char * V_15 , const char * V_16 ,
unsigned long int V_17 )
{
T_4 * V_18 ;
T_1 V_1 ;
char * V_19 ;
char * V_20 ;
char * V_21 ;
char * V_22 ;
char * V_23 = NULL ;
unsigned int V_9 = 22 ;
if ( ! V_14 )
V_14 = V_24 ;
if ( ! V_15 )
V_15 = L_2 ;
V_1 = F_12 ( V_13 ) ;
if ( ! V_1 )
return NULL ;
if ( F_13 ( V_1 ) != V_8 ) {
F_14 ( V_1 ) ;
return NULL ;
}
F_15 ( V_13 , & V_9 ) ;
V_19 = F_16 ( V_14 ) ;
V_20 = F_16 ( V_15 ) ;
V_21 = F_7 ( V_9 ) ;
if ( ! V_16 )
V_16 = V_21 ;
V_22 = F_16 ( V_16 ) ;
if ( V_17 > 0 )
V_23 = F_17 ( L_3 , V_17 ) ;
V_18 = F_17 ( L_4 , V_19 , V_20 , V_22 ,
V_23 ? V_23 : L_5 ) ;
F_18 ( L_6 , V_18 ) ;
if ( F_19 ( V_1 , V_18 ) != V_8 ) {
F_20 ( V_1 ) ;
F_14 ( V_1 ) ;
V_1 = NULL ;
}
V_12 ( V_19 ) ;
V_12 ( V_20 ) ;
V_12 ( V_21 ) ;
V_12 ( V_22 ) ;
V_12 ( V_18 ) ;
if ( V_23 )
V_12 ( V_23 ) ;
return V_1 ;
}
static int F_21 ( const char * V_25 , const unsigned int V_26 , const char * V_27 , const char * V_28 ,
const char * V_29 , const char * V_30 , const char * V_15 , const char * V_16 , const char * V_14 ,
const unsigned long int V_17 , const char * V_31 )
{
T_3 V_13 = NULL ;
T_1 V_1 = NULL ;
int V_2 = V_32 ;
int V_33 = V_34 ;
char * V_35 = NULL ;
if ( F_22 ( V_31 , L_7 ) ) {
V_2 = F_23 ( V_31 , V_36 , 0640 ) ;
if ( V_2 == - 1 ) {
V_2 = F_23 ( V_31 , V_36 | V_37 , 0640 ) ;
if ( V_2 == - 1 ) {
F_4 ( L_8 , F_5 ( V_6 ) ) ;
return V_34 ;
}
}
}
V_13 = F_24 ( V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , & V_35 ) ;
if ( ! V_13 ) {
F_4 ( L_9 , V_35 ) ;
goto V_38;
}
V_1 = F_11 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
if ( ! V_1 )
goto V_38;
F_1 ( V_1 , V_2 ) ;
V_33 = V_39 ;
V_38:
if ( V_35 )
F_4 ( L_10 , V_35 ) ;
V_12 ( V_35 ) ;
F_25 ( & V_13 , & V_1 ) ;
if ( F_22 ( V_31 , L_7 ) )
F_26 ( V_2 ) ;
return V_33 ;
}
static void F_27 ( const char * V_40 )
{
printf ( L_11 ) ;
printf ( L_12 ) ;
printf ( L_13 , V_40 ) ;
printf ( L_14 , V_40 ) ;
printf ( L_15 , V_40 ) ;
printf ( L_16
L_17
L_18 , V_40 ) ;
printf ( L_19 ) ;
printf ( L_20 ) ;
printf ( L_21 ) ;
printf ( L_22 ) ;
printf ( L_23 ) ;
printf ( L_24 ) ;
printf ( L_25 ) ;
printf ( L_26 ) ;
printf ( L_27 ) ;
printf ( L_28 ) ;
printf ( L_29 ) ;
printf ( L_30 ) ;
printf ( L_31 ) ;
printf ( L_32 ) ;
printf ( L_33 ) ;
printf ( L_34 ) ;
printf ( L_35 ) ;
printf ( L_36 ) ;
printf ( L_37 , V_24 ) ;
printf ( L_38 ) ;
}
static char * F_9 ( T_2 * V_10 , const unsigned int V_9 )
{
T_5 * V_11 = F_28 ( NULL ) ;
T_2 * V_41 ;
if ( ! V_10 ) {
F_29 ( V_11 , L_39 , V_9 ) ;
} else {
F_29 ( V_11 , L_40 , ( char * ) V_10 -> V_42 ) ;
V_41 = F_30 ( V_10 ) ;
while ( V_41 ) {
F_29 ( V_11 , L_41 , ( char * ) V_41 -> V_42 ) ;
V_41 = F_30 ( V_41 ) ;
}
F_29 ( V_11 , L_42 , V_9 ) ;
}
return F_31 ( V_11 , FALSE ) ;
}
static int F_32 ( char * V_43 , unsigned int V_9 )
{
unsigned V_44 = 0 ;
char * V_45 ;
if ( ! V_43 ) {
F_4 ( L_43 ) ;
return V_34 ;
}
if ( F_22 ( V_43 , V_46 ) ) {
F_4 ( L_44 , V_46 ) ;
return V_34 ;
}
V_45 = F_7 ( V_9 ) ;
printf ( L_45
L_46
L_47 , V_44 ++ ) ;
printf ( L_48
L_49
L_50 , V_44 ++ ) ;
printf ( L_51
L_52
L_53 , V_44 ++ , F_33 () ) ;
printf ( L_54
L_55
L_56 , V_44 ++ ) ;
printf ( L_57
L_58 ,
V_44 ++ ) ;
printf ( L_59
L_60 ,
V_44 ++ ) ;
printf ( L_61
L_62
L_63 , V_44 ++ ) ;
printf ( L_64
L_65
L_66 , V_44 ++ , V_24 ) ;
printf ( L_67
L_68 , V_44 ++ ) ;
if ( V_45 )
printf ( L_69 , V_45 ) ;
printf ( L_70 ) ;
printf ( L_71
L_72 ,
V_44 ++ ) ;
V_12 ( V_45 ) ;
return V_39 ;
}
static char * F_34 ( const char * V_47 , const char * V_48 )
{
if ( ! V_47 && V_48 )
return F_35 ( V_48 ) ;
if ( ! V_48 && V_47 )
return F_35 ( V_47 ) ;
if ( ! V_48 && ! V_47 )
return NULL ;
return F_17 ( L_73 , V_47 , V_48 ) ;
}
int main ( int V_49 , char * * V_50 )
{
int V_51 ;
int V_52 = 0 ;
int V_53 ;
char * V_54 = NULL ;
unsigned int V_9 = 22 ;
char * V_55 = NULL ;
char * V_56 = NULL ;
char * V_57 = NULL ;
char * V_58 = NULL ;
char * V_29 = NULL ;
char * V_30 = NULL ;
char * V_48 = NULL ;
unsigned long int V_17 = 0 ;
int V_33 = V_34 ;
T_6 * V_59 = F_36 ( T_6 , 1 ) ;
#ifdef F_37
T_7 V_60 ;
F_38 () ;
#endif
F_39 ( V_59 , V_61 , V_62 , V_63 , NULL ) ;
F_40 ( V_59 , V_46 , L_74 , 147 , L_75 ) ;
V_64 = 0 ;
V_65 = 0 ;
if ( V_49 == 1 ) {
F_27 ( V_50 [ 0 ] ) ;
goto V_66;
}
for ( V_53 = 0 ; V_53 < V_49 ; V_53 ++ ) {
F_18 ( L_76 , V_50 [ V_53 ] ) ;
}
F_18 ( L_70 ) ;
while ( ( V_51 = F_41 ( V_49 , V_50 , L_77 , V_67 , & V_52 ) ) != - 1 ) {
switch ( V_51 ) {
case V_68 :
F_27 ( V_50 [ 0 ] ) ;
V_33 = V_39 ;
goto V_66;
case V_69 :
V_70 = TRUE ;
break;
case V_71 :
printf ( L_78 , V_61 , V_62 , V_63 ) ;
V_33 = V_39 ;
goto V_66;
case V_72 :
V_12 ( V_54 ) ;
V_54 = F_35 ( V_73 ) ;
break;
case V_74 :
V_9 = ( unsigned int ) strtoul ( V_73 , NULL , 10 ) ;
if ( V_9 > 65535 || V_9 == 0 ) {
F_4 ( L_79 , V_73 ) ;
goto V_66;
}
break;
case V_75 :
V_12 ( V_55 ) ;
V_55 = F_35 ( V_73 ) ;
break;
case V_76 :
V_12 ( V_56 ) ;
V_56 = F_35 ( V_73 ) ;
memset ( V_73 , 'X' , strlen ( V_73 ) ) ;
break;
case V_77 :
V_12 ( V_29 ) ;
V_29 = F_35 ( V_73 ) ;
break;
case V_78 :
V_12 ( V_30 ) ;
V_30 = F_35 ( V_73 ) ;
memset ( V_73 , 'X' , strlen ( V_73 ) ) ;
break;
case V_79 :
V_12 ( V_57 ) ;
V_57 = F_35 ( V_73 ) ;
break;
case V_80 :
V_12 ( V_58 ) ;
V_58 = F_35 ( V_73 ) ;
break;
case V_81 :
V_12 ( V_48 ) ;
V_48 = F_35 ( V_73 ) ;
break;
case V_82 :
V_17 = strtoul ( V_73 , NULL , 10 ) ;
break;
case ':' :
F_4 ( L_80 , V_50 [ V_65 - 1 ] ) ;
break;
default:
if ( ! F_42 ( V_59 , V_51 - V_83 , V_73 ) ) {
F_4 ( L_81 , V_50 [ V_65 - 1 ] ) ;
goto V_66;
}
}
}
if ( V_65 != V_49 ) {
F_4 ( L_82 , V_50 [ V_65 ] ) ;
goto V_66;
}
if ( F_43 ( V_59 ) ) {
V_33 = V_39 ;
goto V_66;
}
if ( V_59 -> V_84 ) {
V_33 = F_32 ( V_59 -> V_43 , V_9 ) ;
goto V_66;
}
#ifdef F_37
V_51 = F_44 ( F_45 ( 1 , 1 ) , & V_60 ) ;
if ( V_51 != 0 ) {
if ( V_70 )
F_4 ( L_83 , V_51 ) ;
goto V_66;
}
#endif
if ( V_59 -> V_85 ) {
char * V_11 ;
if ( ! V_54 ) {
F_4 ( L_84 ) ;
goto V_66;
}
V_11 = F_34 ( V_59 -> V_86 , V_48 ) ;
V_33 = F_21 ( V_54 , V_9 , V_55 ,
V_56 , V_29 , V_30 , V_57 ,
V_11 , V_58 , V_17 , V_59 -> V_31 ) ;
V_12 ( V_11 ) ;
} else {
F_18 ( L_85 ) ;
V_33 = V_34 ;
}
V_66:
V_12 ( V_54 ) ;
V_12 ( V_55 ) ;
V_12 ( V_56 ) ;
V_12 ( V_57 ) ;
V_12 ( V_58 ) ;
V_12 ( V_29 ) ;
V_12 ( V_30 ) ;
V_12 ( V_48 ) ;
F_46 ( & V_59 ) ;
return V_33 ;
}
int T_8 F_47 ( T_9 V_87 , T_9 V_88 ,
T_10 V_89 , int V_90 ) {
return main ( V_91 , V_92 ) ;
}
