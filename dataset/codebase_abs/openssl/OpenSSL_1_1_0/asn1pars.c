int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
T_3 * V_7 = NULL ;
F_2 ( V_8 ) * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
char * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
unsigned char * V_15 = NULL ;
char * V_16 = NULL , * V_17 = NULL , * V_18 ;
const unsigned char * V_19 ;
int V_20 = 0 , V_21 = 0 , V_22 = 0 , V_23 = 0 , V_24 = V_25 ;
int V_26 = 0 , V_27 = 1 , V_28 , V_29 ;
long V_30 , V_31 ;
unsigned char * V_32 ;
unsigned int V_33 = 0 ;
T_4 V_34 ;
V_18 = F_3 ( V_1 , V_2 , V_35 ) ;
if ( ( V_9 = F_4 () ) == NULL ) {
F_5 ( V_36 , L_1 , V_18 ) ;
goto V_37;
}
while ( ( V_34 = F_6 () ) != V_38 ) {
switch ( V_34 ) {
case V_38 :
case V_39 :
V_40:
F_5 ( V_36 , L_2 , V_18 ) ;
goto V_37;
case V_41 :
F_7 ( V_35 ) ;
V_27 = 0 ;
goto V_37;
case V_42 :
if ( ! F_8 ( F_9 () , V_43 , & V_24 ) )
goto V_40;
break;
case V_44 :
V_12 = F_9 () ;
break;
case V_45 :
V_14 = F_9 () ;
break;
case V_46 :
V_20 = 1 ;
break;
case V_47 :
V_21 = 1 ;
break;
case V_48 :
V_13 = F_9 () ;
break;
case V_49 :
V_26 = strtol ( F_9 () , NULL , 0 ) ;
break;
case V_50 :
V_33 = atoi ( F_9 () ) ;
break;
case V_51 :
V_22 = - 1 ;
break;
case V_52 :
V_22 = atoi ( F_9 () ) ;
break;
case V_53 :
F_10 ( V_9 , F_9 () ) ;
break;
case V_54 :
V_10 = F_9 () ;
break;
case V_55 :
V_11 = F_9 () ;
break;
case V_56 :
V_23 = 1 ;
V_24 = V_25 ;
break;
}
}
V_1 = F_11 () ;
if ( V_1 != 0 )
goto V_40;
if ( V_13 != NULL ) {
V_4 = F_12 ( V_13 , 'r' , V_57 ) ;
if ( V_4 == NULL )
goto V_37;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
}
if ( ( V_4 = F_12 ( V_12 , 'r' , V_24 ) ) == NULL )
goto V_37;
if ( V_14 && ( V_6 = F_12 ( V_14 , 'w' , V_58 ) ) == NULL )
goto V_37;
if ( V_23 ) {
if ( F_15 ( V_4 , & V_16 , & V_17 , & V_15 , & V_30 ) !=
1 ) {
F_5 ( V_36 , L_3 ) ;
F_16 ( V_36 ) ;
goto V_37;
}
} else {
if ( ( V_7 = F_17 () ) == NULL )
goto V_37;
if ( ! F_18 ( V_7 , V_59 * 8 ) )
goto V_37;
if ( V_10 || V_11 ) {
V_30 = F_19 ( V_10 , V_11 , V_7 ) ;
if ( V_30 < 0 ) {
F_16 ( V_36 ) ;
goto V_37;
}
}
else {
if ( V_24 == V_25 ) {
T_2 * V_60 ;
if ( ( V_5 = F_20 ( F_21 () ) ) == NULL )
goto V_37;
F_22 ( V_5 , V_4 ) ;
V_60 = V_4 ;
V_4 = V_5 ;
V_5 = V_60 ;
}
V_30 = 0 ;
for (; ; ) {
if ( ! F_18 ( V_7 , ( int ) V_30 + V_59 ) )
goto V_37;
V_28 = F_23 ( V_4 , & ( V_7 -> V_61 [ V_30 ] ) , V_59 ) ;
if ( V_28 <= 0 )
break;
V_30 += V_28 ;
}
}
V_15 = ( unsigned char * ) V_7 -> V_61 ;
}
if ( F_24 ( V_9 ) ) {
V_32 = V_15 ;
V_31 = V_30 ;
for ( V_28 = 0 ; V_28 < F_24 ( V_9 ) ; V_28 ++ ) {
T_1 * V_62 ;
int V_63 ;
V_29 = atoi ( F_25 ( V_9 , V_28 ) ) ;
if ( V_29 == 0 ) {
F_5 ( V_36 , L_4 ,
F_25 ( V_9 , V_28 ) ) ;
continue;
}
V_32 += V_29 ;
V_31 -= V_29 ;
V_62 = V_3 ;
V_19 = V_32 ;
V_3 = F_26 ( NULL , & V_19 , V_31 ) ;
F_27 ( V_62 ) ;
if ( ! V_3 ) {
F_5 ( V_36 , L_5 ) ;
F_16 ( V_36 ) ;
goto V_37;
}
V_63 = F_28 ( V_3 ) ;
if ( ( V_63 == V_64 )
|| ( V_63 == V_65 )
|| ( V_63 == V_66 ) ) {
F_5 ( V_36 , L_6 , F_29 ( V_63 ) ) ;
F_16 ( V_36 ) ;
goto V_37;
}
V_32 = V_3 -> V_67 . V_68 -> V_61 ;
V_31 = V_3 -> V_67 . V_68 -> V_33 ;
}
V_15 = V_32 ;
V_30 = V_31 ;
}
if ( V_26 >= V_30 ) {
F_5 ( V_36 , L_7 ) ;
goto V_37;
}
V_30 -= V_26 ;
if ( ( V_33 == 0 ) || ( ( long ) V_33 > V_30 ) )
V_33 = ( unsigned int ) V_30 ;
if ( V_6 ) {
if ( F_30 ( V_6 , V_15 + V_26 , V_33 ) != ( int ) V_33 ) {
F_5 ( V_36 , L_8 ) ;
F_16 ( V_36 ) ;
goto V_37;
}
}
if ( ! V_21 &&
! F_31 ( V_69 , & ( V_15 [ V_26 ] ) , V_33 ,
V_20 , V_22 ) ) {
F_16 ( V_36 ) ;
goto V_37;
}
V_27 = 0 ;
V_37:
F_14 ( V_6 ) ;
F_14 ( V_4 ) ;
F_14 ( V_5 ) ;
if ( V_27 != 0 )
F_16 ( V_36 ) ;
F_32 ( V_7 ) ;
F_33 ( V_16 ) ;
F_33 ( V_17 ) ;
if ( V_23 )
F_33 ( V_15 ) ;
F_27 ( V_3 ) ;
F_34 ( V_9 ) ;
return ( V_27 ) ;
}
static int F_19 ( char * V_10 , const char * V_11 , T_3 * V_7 )
{
T_5 * V_70 = NULL ;
int V_71 ;
unsigned char * V_72 ;
T_1 * V_73 = NULL ;
if ( V_11 ) {
if ( ( V_70 = F_35 ( V_11 ) ) == NULL )
goto V_74;
if ( ! V_10 )
V_10 = F_36 ( V_70 , L_9 , L_10 ) ;
if ( ! V_10 ) {
F_5 ( V_36 , L_11 , V_11 ) ;
goto V_74;
}
}
V_73 = F_37 ( V_10 , V_70 ) ;
F_38 ( V_70 ) ;
V_70 = NULL ;
if ( ! V_73 )
return - 1 ;
V_71 = F_39 ( V_73 , NULL ) ;
if ( V_71 <= 0 )
goto V_74;
if ( ! F_18 ( V_7 , V_71 ) )
goto V_74;
V_72 = ( unsigned char * ) V_7 -> V_61 ;
F_39 ( V_73 , & V_72 ) ;
F_27 ( V_73 ) ;
return V_71 ;
V_74:
F_38 ( V_70 ) ;
F_27 ( V_73 ) ;
return - 1 ;
}
