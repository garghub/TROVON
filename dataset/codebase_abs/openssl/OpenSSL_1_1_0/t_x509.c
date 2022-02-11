int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_2 ( T_1 * V_1 , T_2 * V_2 , unsigned long V_5 ,
unsigned long V_6 )
{
T_3 * V_7 ;
int V_8 ;
if ( ( V_7 = F_3 ( F_4 () ) ) == NULL ) {
F_5 ( V_9 , V_10 ) ;
return ( 0 ) ;
}
F_6 ( V_7 , V_1 , V_11 ) ;
V_8 = F_7 ( V_7 , V_2 , V_5 , V_6 ) ;
F_8 ( V_7 ) ;
return ( V_8 ) ;
}
int F_9 ( T_3 * V_12 , T_2 * V_2 )
{
return F_7 ( V_12 , V_2 , V_3 , V_4 ) ;
}
int F_7 ( T_3 * V_12 , T_2 * V_2 , unsigned long V_13 ,
unsigned long V_6 )
{
long V_14 ;
int V_8 = 0 , V_15 ;
char * V_16 = NULL , V_17 = ' ' ;
int V_18 = 0 ;
T_4 * V_19 ;
T_5 * V_20 = NULL ;
const char * V_21 ;
if ( ( V_13 & V_22 ) == V_23 ) {
V_17 = '\n' ;
V_18 = 12 ;
}
if ( V_13 == V_4 )
V_18 = 16 ;
if ( ! ( V_6 & V_24 ) ) {
if ( F_10 ( V_12 , L_1 , 13 ) <= 0 )
goto V_25;
if ( F_10 ( V_12 , L_2 , 10 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_26 ) ) {
V_14 = F_11 ( V_2 ) ;
if ( F_12 ( V_12 , L_3 , L_4 , V_14 + 1 , V_14 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_27 ) ) {
if ( F_10 ( V_12 , L_5 , 22 ) <= 0 )
goto V_25;
V_19 = F_13 ( V_2 ) ;
if ( V_19 -> V_28 <= ( int ) sizeof( long ) ) {
F_14 () ;
V_14 = F_15 ( V_19 ) ;
F_16 () ;
} else {
V_14 = - 1 ;
}
if ( V_14 != - 1 ) {
if ( V_19 -> type == V_29 ) {
V_14 = - V_14 ;
V_21 = L_6 ;
} else
V_21 = L_4 ;
if ( F_12 ( V_12 , L_7 , V_21 , V_14 , V_21 , V_14 ) <= 0 )
goto V_25;
} else {
V_21 = ( V_19 -> type == V_29 ) ? L_8 : L_4 ;
if ( F_12 ( V_12 , L_9 , L_4 , V_21 ) <= 0 )
goto V_25;
for ( V_15 = 0 ; V_15 < V_19 -> V_28 ; V_15 ++ ) {
if ( F_12 ( V_12 , L_10 , V_19 -> V_30 [ V_15 ] ,
( ( V_15 + 1 == V_19 -> V_28 ) ? '\n' : ':' ) ) <= 0 )
goto V_25;
}
}
}
if ( ! ( V_6 & V_31 ) ) {
const T_6 * V_32 = F_17 ( V_2 ) ;
if ( F_18 ( V_12 , V_32 , NULL ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_33 ) ) {
if ( F_12 ( V_12 , L_11 , V_17 ) <= 0 )
goto V_25;
if ( F_19 ( V_12 , F_20 ( V_2 ) , V_18 , V_13 )
< 0 )
goto V_25;
if ( F_10 ( V_12 , L_12 , 1 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_34 ) ) {
if ( F_10 ( V_12 , L_13 , 17 ) <= 0 )
goto V_25;
if ( F_10 ( V_12 , L_14 , 24 ) <= 0 )
goto V_25;
if ( ! F_21 ( V_12 , F_22 ( V_2 ) ) )
goto V_25;
if ( F_10 ( V_12 , L_15 , 25 ) <= 0 )
goto V_25;
if ( ! F_21 ( V_12 , F_23 ( V_2 ) ) )
goto V_25;
if ( F_10 ( V_12 , L_12 , 1 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_35 ) ) {
if ( F_12 ( V_12 , L_16 , V_17 ) <= 0 )
goto V_25;
if ( F_19
( V_12 , F_24 ( V_2 ) , V_18 , V_13 ) < 0 )
goto V_25;
if ( F_10 ( V_12 , L_12 , 1 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_36 ) ) {
T_7 * V_37 = F_25 ( V_2 ) ;
T_8 * V_38 ;
F_26 ( & V_38 , NULL , NULL , NULL , V_37 ) ;
if ( F_10 ( V_12 , L_17 , 33 ) <= 0 )
goto V_25;
if ( F_12 ( V_12 , L_18 , L_4 ) <= 0 )
goto V_25;
if ( F_27 ( V_12 , V_38 ) <= 0 )
goto V_25;
if ( F_28 ( V_12 , L_12 ) <= 0 )
goto V_25;
V_20 = F_29 ( V_2 ) ;
if ( V_20 == NULL ) {
F_12 ( V_12 , L_19 , L_4 ) ;
F_30 ( V_12 ) ;
} else {
F_31 ( V_12 , V_20 , 16 , NULL ) ;
}
}
if ( ! ( V_6 & V_39 ) ) {
const T_9 * V_40 , * V_41 ;
F_32 ( V_2 , & V_40 , & V_41 ) ;
if ( V_40 != NULL ) {
if ( F_12 ( V_12 , L_20 , L_4 ) <= 0 )
goto V_25;
if ( ! F_33 ( V_12 , V_40 , 12 ) )
goto V_25;
}
if ( V_41 != NULL ) {
if ( F_12 ( V_12 , L_21 , L_4 ) <= 0 )
goto V_25;
if ( ! F_33 ( V_12 , V_41 , 12 ) )
goto V_25;
}
}
if ( ! ( V_6 & V_42 ) )
F_34 ( V_12 , L_22 ,
F_35 ( V_2 ) , V_6 , 8 ) ;
if ( ! ( V_6 & V_43 ) ) {
const T_6 * V_44 ;
const T_9 * V_45 ;
F_36 ( & V_45 , & V_44 , V_2 ) ;
if ( F_18 ( V_12 , V_44 , V_45 ) <= 0 )
goto V_25;
}
if ( ! ( V_6 & V_46 ) ) {
if ( ! F_37 ( V_12 , V_2 , 0 ) )
goto V_25;
}
V_8 = 1 ;
V_25:
F_38 ( V_16 ) ;
return ( V_8 ) ;
}
int F_39 ( T_3 * V_12 , T_2 * V_2 )
{
unsigned char * V_47 = NULL ;
unsigned char * V_48 ;
int V_49 ;
int V_15 ;
unsigned char V_50 [ V_51 ] ;
T_9 * V_52 ;
T_10 * V_53 ;
if ( F_12 ( V_12 , L_23 ) <= 0 )
goto V_25;
V_53 = F_24 ( V_2 ) ;
V_49 = F_40 ( V_53 , NULL ) ;
if ( ( V_47 = V_48 = F_41 ( V_49 ) ) == NULL )
goto V_25;
F_40 ( V_53 , & V_48 ) ;
if ( ! F_42 ( V_47 , V_49 , V_50 , NULL , F_43 () , NULL ) )
goto V_25;
for ( V_15 = 0 ; V_15 < V_51 ; V_15 ++ ) {
if ( F_12 ( V_12 , L_24 , V_50 [ V_15 ] ) <= 0 )
goto V_25;
}
F_38 ( V_47 ) ;
V_47 = NULL ;
if ( F_12 ( V_12 , L_25 ) <= 0 )
goto V_25;
V_52 = F_44 ( V_2 ) ;
if ( V_52 == NULL )
goto V_25;
if ( ! F_42 ( F_45 ( V_52 ) ,
F_46 ( V_52 ) , V_50 , NULL , F_43 () ,
NULL ) )
goto V_25;
for ( V_15 = 0 ; V_15 < V_51 ; V_15 ++ ) {
if ( F_12 ( V_12 , L_24 , V_50 [ V_15 ] ) <= 0 )
goto V_25;
}
F_12 ( V_12 , L_12 ) ;
return ( 1 ) ;
V_25:
F_38 ( V_47 ) ;
return ( 0 ) ;
}
int F_33 ( T_3 * V_12 , const T_11 * V_45 , int V_54 )
{
const unsigned char * V_55 ;
int V_15 , V_56 ;
V_56 = V_45 -> V_28 ;
V_55 = V_45 -> V_30 ;
for ( V_15 = 0 ; V_15 < V_56 ; V_15 ++ ) {
if ( ( V_15 % 18 ) == 0 ) {
if ( F_10 ( V_12 , L_12 , 1 ) <= 0 )
return 0 ;
if ( F_47 ( V_12 , V_54 , V_54 ) <= 0 )
return 0 ;
}
if ( F_12 ( V_12 , L_26 , V_55 [ V_15 ] , ( ( V_15 + 1 ) == V_56 ) ? L_4 : L_27 ) <= 0 )
return 0 ;
}
if ( F_10 ( V_12 , L_12 , 1 ) != 1 )
return 0 ;
return 1 ;
}
int F_18 ( T_3 * V_12 , const T_6 * V_57 ,
const T_11 * V_45 )
{
int V_58 ;
if ( F_28 ( V_12 , L_28 ) <= 0 )
return 0 ;
if ( F_27 ( V_12 , V_57 -> V_59 ) <= 0 )
return 0 ;
V_58 = F_48 ( V_57 -> V_59 ) ;
if ( V_58 != V_60 ) {
int V_61 , V_62 ;
const T_12 * V_63 ;
if ( F_49 ( V_58 , & V_62 , & V_61 ) ) {
V_63 = F_50 ( NULL , V_61 ) ;
if ( V_63 && V_63 -> V_64 )
return V_63 -> V_64 ( V_12 , V_57 , V_45 , 9 , 0 ) ;
}
}
if ( V_45 )
return F_33 ( V_12 , V_45 , 9 ) ;
else if ( F_28 ( V_12 , L_12 ) <= 0 )
return 0 ;
return 1 ;
}
int F_37 ( T_3 * V_65 , T_2 * V_2 , int V_54 )
{
char V_66 [ 80 ] , V_67 ;
F_51 ( T_8 ) * V_68 , * V_69 ;
const unsigned char * V_70 , * V_71 ;
int V_72 ;
int V_15 ;
if ( F_52 ( V_2 ) == 0 )
return 1 ;
V_68 = F_53 ( V_2 ) ;
V_69 = F_54 ( V_2 ) ;
if ( V_68 ) {
V_67 = 1 ;
F_12 ( V_65 , L_29 , V_54 , L_4 , V_54 + 2 , L_4 ) ;
for ( V_15 = 0 ; V_15 < F_55 ( V_68 ) ; V_15 ++ ) {
if ( ! V_67 )
F_28 ( V_65 , L_30 ) ;
else
V_67 = 0 ;
F_56 ( V_66 , sizeof V_66 ,
F_57 ( V_68 , V_15 ) , 0 ) ;
F_28 ( V_65 , V_66 ) ;
}
F_28 ( V_65 , L_12 ) ;
} else
F_12 ( V_65 , L_31 , V_54 , L_4 ) ;
if ( V_69 ) {
V_67 = 1 ;
F_12 ( V_65 , L_32 , V_54 , L_4 , V_54 + 2 , L_4 ) ;
for ( V_15 = 0 ; V_15 < F_55 ( V_69 ) ; V_15 ++ ) {
if ( ! V_67 )
F_28 ( V_65 , L_30 ) ;
else
V_67 = 0 ;
F_56 ( V_66 , sizeof V_66 ,
F_57 ( V_69 , V_15 ) , 0 ) ;
F_28 ( V_65 , V_66 ) ;
}
F_28 ( V_65 , L_12 ) ;
} else
F_12 ( V_65 , L_33 , V_54 , L_4 ) ;
V_70 = F_58 ( V_2 , NULL ) ;
if ( V_70 )
F_12 ( V_65 , L_34 , V_54 , L_4 , V_70 ) ;
V_71 = F_59 ( V_2 , & V_72 ) ;
if ( V_71 ) {
F_12 ( V_65 , L_35 , V_54 , L_4 ) ;
for ( V_15 = 0 ; V_15 < V_72 ; V_15 ++ )
F_12 ( V_65 , L_36 , V_15 ? L_27 : L_4 , V_71 [ V_15 ] ) ;
F_10 ( V_65 , L_12 , 1 ) ;
}
return 1 ;
}
