static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static T_1
F_3 ( T_2 V_3 , T_2 V_4 )
{
const char * V_5 = ( const char * ) V_3 ;
const char * V_6 = ( const char * ) V_4 ;
return strcmp ( V_5 , V_6 ) == 0 ;
}
static T_3
F_4 ( T_2 V_7 )
{
const char * V_8 = ( const char * ) V_7 ;
T_3 V_9 = 0 , V_10 ;
for ( V_10 = 0 ; V_8 [ V_10 ] ; V_10 ++ )
V_9 += V_8 [ V_10 ] ;
return V_9 ;
}
void
F_5 ( const char * V_11 , int V_12 , int V_13 , T_4 V_14 ,
T_4 V_15 , const T_5 * V_16 )
{
char * V_8 = F_6 ( V_11 ) ;
T_6 * V_17 = ( T_6 * ) F_7 ( sizeof( * V_17 ) ) ;
V_17 -> V_12 = F_8 ( V_12 ) ;
V_17 -> V_13 = V_13 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_16 = V_16 ;
F_9 ( V_18 , V_8 , V_17 ) ;
F_10 ( V_8 , V_14 , V_12 , V_16 ) ;
}
T_6 *
F_11 ( const char * V_19 )
{
T_6 * V_17 ;
if( ! V_19 ) {
return NULL ;
}
V_17 = ( T_6 * ) F_12 ( V_18 , V_19 ) ;
return V_17 ;
}
static int
F_13 ( T_7 * V_20 , T_8 * V_21 , T_9 * V_22 ,
T_10 V_23 )
{
T_11 * volatile V_24 ;
T_9 * volatile V_25 ;
volatile int V_26 = 0 ;
T_12 * volatile V_27 ;
T_6 * V_28 ;
T_4 V_14 ;
T_13 * V_29 ;
T_7 * V_30 ;
int V_31 , V_32 , V_33 ;
volatile int V_34 ;
T_14 V_35 ;
T_10 V_36 , V_37 ;
T_15 V_38 ;
T_16 V_39 ;
const char * V_11 ;
T_17 * V_40 = NULL ;
T_18 * V_41 ;
T_7 * volatile V_42 = NULL ;
T_19 V_43 ;
void * V_44 ;
V_32 = 0 ;
V_34 = 0 ;
F_14 ( & V_43 , V_45 , TRUE , V_21 ) ;
V_21 -> V_46 = FALSE ;
V_29 = F_15 ( V_21 ) ;
V_27 = ( T_12 * ) F_16 ( V_29 , V_47 ) ;
if ( ! V_27 ) {
V_27 = F_17 ( F_18 () , T_12 ) ;
V_27 -> V_11 = NULL ;
V_27 -> V_48 = FALSE ;
V_27 -> V_49 = F_19 ( F_18 () ) ;
F_20 ( V_29 , V_47 , V_27 ) ;
}
V_24 = F_21 (
V_22 , V_47 , V_20 , V_34 , - 1 , V_50 ) ;
V_25 = F_22 ( V_24 , V_51 ) ;
V_44 = V_21 -> V_52 ;
F_23 {
V_42 = V_20 ;
if( ( ! V_21 -> V_53 -> V_54 . V_55 )
&& ( V_27 -> V_48 )
&& ( V_56 ) ) {
V_41 = ( T_18 * ) F_24 ( V_27 -> V_49 , V_27 -> V_57 ) ;
if( ! V_41 ) {
goto V_58;
}
F_25 ( V_27 -> V_49 , V_21 -> V_53 -> V_59 , V_41 ) ;
V_40 = F_26 ( & V_1 ,
V_20 , 0 , V_21 , V_41 -> V_57 , NULL ,
V_27 -> V_60 ,
F_27 ( V_20 ) , TRUE ) ;
V_27 -> V_60 += F_27 ( V_20 ) ;
if( ! V_40 ) {
goto V_58;
}
V_27 -> V_48 = FALSE ;
V_41 -> V_61 = V_21 -> V_53 -> V_59 ;
V_42 = F_28 ( V_20 , V_40 -> V_62 ) ;
F_29 ( V_21 , V_42 , L_1 ) ;
}
if( ( V_21 -> V_53 -> V_54 . V_55 )
&& ( V_56 ) ) {
V_41 = ( T_18 * ) F_24 ( V_27 -> V_49 , V_21 -> V_53 -> V_59 ) ;
if( V_41 ) {
V_40 = F_30 ( & V_1 ,
V_21 , V_41 -> V_57 , NULL ) ;
if( V_40 && ( V_40 -> V_54 & V_63 ) ) {
if( V_21 -> V_53 -> V_59 == V_41 -> V_61 ) {
T_11 * V_64 ;
V_42 = F_28 ( V_20 , V_40 -> V_62 ) ;
F_29 ( V_21 , V_42 , L_1 ) ;
F_31 ( V_40 , & V_65 , V_22 , V_21 , V_20 , & V_64 ) ;
} else {
T_11 * V_66 ;
V_66 = F_32 ( V_22 , V_67 , V_20 , 0 , 0 , V_41 -> V_61 ) ;
F_33 ( V_66 ) ;
goto V_58;
}
}
}
}
V_34 = F_34 ( V_42 , V_34 , & V_35 , & V_36 , & V_38 ) ;
V_34 = F_35 ( V_42 , V_34 , & V_39 , & V_37 ) ;
if ( ! ( V_35 == V_68 && V_36 && V_38 == 0 ) ) {
if ( ( F_36 ( V_42 , V_32 ) > 7 ) && ( F_37 ( V_42 , V_32 , L_2 , 7 ) == 0 ) ) {
V_26 = F_38 ( V_69 ,
F_39 ( V_42 , V_32 ) ,
V_21 , V_25 ) ;
goto V_58;
}
if ( ( F_36 ( V_42 , V_32 ) > 16 ) &&
( ( F_40 ( V_42 , V_32 , L_3 , 4 ) == 0 ) ) ) {
V_26 = F_38 ( V_70 ,
F_39 ( V_42 , V_32 ) ,
V_21 , V_25 ) ;
V_21 -> V_46 = TRUE ;
goto V_58;
}
if ( ( F_36 ( V_42 , V_32 ) == 16 ) &&
( ( F_40 ( V_42 , V_32 , L_3 , 4 ) == 0 ) ) ) {
if( V_23 ) {
V_26 = F_38 ( V_71 ,
F_39 ( V_42 , V_32 ) ,
V_21 , V_25 ) ;
}
else if( V_21 -> V_72 ) {
V_26 = F_38 ( V_73 ,
F_39 ( V_21 -> V_72 , 0 ) ,
V_21 , V_25 ) ;
V_21 -> V_46 = TRUE ;
}
goto V_58;
}
if ( ( F_36 ( V_42 , V_32 ) > 2 ) &&
( ( F_40 ( V_42 , V_32 , L_4 , 2 ) == 0 ) ||
( F_40 ( V_42 , V_32 , L_5 , 2 ) == 0 ) ) ) {
V_26 = F_38 ( V_74 ,
F_39 ( V_42 , V_32 ) ,
V_21 , V_25 ) ;
goto V_58;
}
V_28 = ( T_6 * ) F_41 ( V_21 -> V_53 , V_47 , 0 ) ;
if ( ! V_28 && ! V_21 -> V_53 -> V_54 . V_55 )
{
V_28 = V_27 -> V_11 ;
if ( V_27 -> V_11 )
F_42 ( V_21 -> V_53 , V_47 , 0 , V_27 -> V_11 ) ;
}
if ( ! V_28 )
{
F_43 ( V_25 , V_42 , V_32 , 0 ,
L_6 ,
V_35 , V_36 , V_38 ) ;
V_26 = F_27 ( V_42 ) ;
goto V_58;
} else {
T_7 * V_75 ;
V_75 = F_39 ( V_42 , V_32 ) ;
if ( V_23 )
V_14 = V_28 -> V_15 ;
else
V_14 = V_28 -> V_14 ;
V_31 = F_38 ( V_14 , V_75 , V_21 , V_25 ) ;
if ( V_31 == 0 )
V_26 = F_27 ( V_42 ) ;
else
V_26 = V_32 + V_31 ;
goto V_58;
}
}
V_33 = V_34 ;
V_34 = F_44 ( FALSE , & V_43 , V_25 , V_42 , V_34 , V_76 , & V_11 ) ;
V_28 = F_11 ( V_11 ) ;
if( ( ! V_21 -> V_53 -> V_54 . V_55 )
&& ( V_28 )
&& ( F_27 ( V_42 ) == F_45 ( V_42 ) )
&& ( V_39 > ( T_16 ) F_36 ( V_42 , V_33 ) )
&& ( V_56 ) ) {
V_41 = F_17 ( F_18 () , T_18 ) ;
V_41 -> V_57 = V_21 -> V_53 -> V_59 ;
V_41 -> V_61 = 0 ;
F_25 ( V_27 -> V_49 , V_21 -> V_53 -> V_59 , V_41 ) ;
F_26 ( & V_1 ,
V_42 , 0 , V_21 , V_21 -> V_53 -> V_59 , NULL ,
0 , F_27 ( V_42 ) , TRUE ) ;
F_46 ( & V_1 ,
V_21 , V_21 -> V_53 -> V_59 , NULL , V_39 + V_33 ) ;
V_27 -> V_48 = TRUE ;
V_27 -> V_57 = V_21 -> V_53 -> V_59 ;
V_27 -> V_60 = F_27 ( V_42 ) ;
goto V_58;
}
if ( ( V_28 == NULL ) ||
! F_47 ( V_28 -> V_12 ) ) {
F_43 ( V_25 , V_42 , V_33 , - 1 ,
L_7 ) ;
V_26 = F_27 ( V_42 ) ;
goto V_58;
}
if( ! V_27 -> V_11 ) {
V_27 -> V_11 = V_28 ;
}
if ( V_23 ) {
V_14 = V_28 -> V_15 ;
if ( V_14 != NULL ) {
V_30 = F_39 ( V_42 , V_34 ) ;
V_31 = F_38 ( V_14 , V_30 , V_21 ,
V_25 ) ;
if ( V_31 == 0 )
V_26 = F_27 ( V_42 ) ;
else
V_26 = V_34 + V_31 ;
} else {
F_43 ( V_25 , V_42 , V_34 , - 1 ,
L_8 ) ;
V_26 = F_27 ( V_42 ) ;
}
} else {
V_14 = V_28 -> V_14 ;
if ( V_14 != NULL ) {
V_30 = F_39 ( V_42 , V_34 ) ;
V_31 = F_38 ( V_14 , V_30 , V_21 ,
V_25 ) ;
if ( V_31 == 0 )
V_26 = F_27 ( V_42 ) ;
else
V_26 = V_34 + V_31 ;
} else {
F_43 ( V_25 , V_42 , V_34 , - 1 ,
L_9 ) ;
V_26 = F_27 ( V_42 ) ;
}
}
V_58:
;
} F_48 {
V_21 -> V_52 = V_44 ;
F_49 ( V_42 , V_21 , V_22 , V_77 , V_78 ) ;
} V_79 ;
F_50 ( V_24 , V_26 ) ;
return V_26 ;
}
static void
F_51 ( T_7 * V_20 , T_8 * V_21 , T_9 * V_22 )
{
F_13 ( V_20 , V_21 , V_22 , FALSE ) ;
}
static int
F_52 ( T_7 * V_20 , T_8 * V_21 , T_9 * V_22 , void * T_20 V_80 )
{
return F_13 ( V_20 , V_21 , V_22 , TRUE ) ;
}
void
F_53 ( void )
{
static T_21 V_81 [] = {
{ & V_76 ,
{ L_10 , L_11 , V_82 , V_83 ,
NULL , 0 , L_12 , V_84 } } ,
{ & V_85 ,
{ L_13 , L_14 , V_86 , V_83 ,
NULL , 0x0 , NULL , V_84 } } ,
{ & V_87 ,
{ L_15 , L_16 , V_88 , V_83 ,
NULL , 0x0 , NULL , V_84 } } ,
{ & V_89 ,
{ L_17 , L_18 , V_90 , V_83 ,
NULL , 0x0 , L_19 , V_84 } } ,
{ & V_91 ,
{ L_20 , L_21 , V_90 , V_83 ,
NULL , 0x0 , L_22 , V_84 } } ,
{ & V_92 ,
{ L_23 , L_24 , V_90 , V_83 ,
NULL , 0x0 , L_25 , V_84 } } ,
{ & V_93 ,
{ L_26 , L_27 , V_90 , V_83 ,
NULL , 0x0 , L_28 , V_84 } } ,
{ & V_94 ,
{ L_29 , L_30 , V_86 , V_83 ,
NULL , 0x0 , L_31 , V_84 } } ,
{ & V_95 ,
{ L_32 , L_33 , V_96 , V_97 ,
NULL , 0x0 , NULL , V_84 } } ,
{ & V_67 ,
{ L_34 , L_35 , V_86 , V_83 ,
NULL , 0x0 , L_36 , V_84 } } ,
{ & V_98 ,
{ L_37 , L_38 , V_96 , V_97 ,
NULL , 0x0 , L_39 , V_84 } } ,
} ;
static T_1 * V_13 [] = {
& V_51 ,
& V_99 ,
& V_100 ,
} ;
T_22 * V_101 ;
V_47 = F_54 (
L_40 ,
L_41 , L_42 ) ;
V_101 = F_55 ( V_47 , NULL ) ;
F_56 ( V_101 , L_43 ,
L_44 ,
L_45 ,
& V_56 ) ;
F_57 ( V_47 , V_81 , F_58 ( V_81 ) ) ;
F_59 ( V_13 , F_58 ( V_13 ) ) ;
F_60 ( L_46 , F_51 , V_47 ) ;
F_61 ( L_47 , F_52 , V_47 ) ;
V_18 = F_62 ( F_4 , F_3 ) ;
F_63 ( F_1 ) ;
}
static int
F_64 ( T_7 * V_20 , int V_34 , T_8 * V_21 ,
T_9 * V_22 , T_23 * T_24 V_80 )
{
T_7 * V_102 ;
V_102 = F_39 ( V_20 , V_34 ) ;
F_51 ( V_102 , V_21 , V_22 ) ;
return F_36 ( V_20 , V_34 ) ;
}
int
F_65 ( T_7 * V_20 , int V_34 , T_8 * V_21 ,
T_9 * V_22 , T_23 * T_24 V_80 )
{
T_7 * V_102 ;
V_102 = F_39 ( V_20 , V_34 ) ;
return F_52 ( V_102 , V_21 , V_22 , NULL ) ;
}
T_7 *
F_66 ( T_7 * V_103 , T_7 * V_102 ,
int V_34 V_80 , T_8 * V_21 ,
T_25 * T_26 V_80 )
{
T_7 * V_104 ;
if( ( ! V_102 ) || ( ! V_103 ) ) {
return NULL ;
}
V_21 -> V_105 = V_106 ;
V_21 -> V_107 = NULL ;
V_21 -> V_72 = V_103 ;
V_21 -> V_108 = NULL ;
F_51 ( V_102 , V_21 , NULL ) ;
V_104 = V_21 -> V_108 ;
V_21 -> V_105 = 0 ;
V_21 -> V_107 = NULL ;
V_21 -> V_72 = NULL ;
V_21 -> V_108 = NULL ;
return V_104 ;
}
void
F_67 ( void )
{
T_4 V_109 ;
V_69 = F_68 ( L_48 ) ;
V_70 = F_68 ( L_49 ) ;
V_71 = F_68 ( L_50 ) ;
V_73 = F_68 ( L_51 ) ;
V_74 = F_68 ( L_52 ) ;
F_69 ( V_110 ,
V_111 ,
& V_112 ) ;
F_69 ( V_113 ,
V_111 ,
& V_112 ) ;
F_69 ( V_114 ,
V_111 ,
& V_112 ) ;
V_109 = F_68 ( L_46 ) ;
F_70 ( L_53 , L_54 , V_109 ) ;
}
