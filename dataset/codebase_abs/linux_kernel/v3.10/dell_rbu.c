static void F_1 ( void )
{
F_2 ( & V_1 . V_2 ) ;
V_3 . V_4 = 0 ;
V_3 . V_5 = 0 ;
V_3 . V_6 = 0 ;
V_3 . V_7 = 0 ;
}
static int F_3 ( void * V_8 , T_1 V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
int V_13 = 0 ;
unsigned int V_14 = 0 ;
void * * V_15 = NULL ;
void * V_16 = NULL ;
unsigned int V_17 = 0 ;
F_4 ( L_1 ) ;
if ( ! V_3 . V_6 ) {
F_4 ( L_2 ) ;
V_13 = - V_18 ;
goto V_19;
}
F_5 ( & V_3 . V_20 ) ;
V_11 = F_6 ( sizeof ( struct V_10 ) , V_21 ) ;
if ( ! V_11 ) {
F_7 ( V_22
L_3
L_4 , V_23 ) ;
V_13 = - V_24 ;
F_8 ( & V_3 . V_20 ) ;
goto V_19;
}
V_12 = F_9 ( V_9 ) ;
V_14 = F_10 (
( unsigned int ) ( V_25 / V_3 . V_6 ) ,
( unsigned int ) 1 ) ;
V_15 = F_6 ( V_14 * sizeof( void * ) ,
V_21 ) ;
if ( ! V_15 ) {
F_7 ( V_22
L_5
L_6 ,
V_23 ) ;
V_13 = - V_24 ;
F_8 ( & V_3 . V_20 ) ;
goto V_26;
}
while ( ! V_16 ) {
V_16 = ( unsigned char * )
F_11 ( V_21 , V_12 ) ;
if ( ! V_16 ) {
F_7 ( V_22
L_3
L_4 , V_23 ) ;
V_13 = - V_24 ;
F_8 ( & V_3 . V_20 ) ;
goto V_27;
}
if ( ( unsigned long ) F_12 ( V_16 )
< V_25 ) {
F_4 ( L_7 ,
( unsigned long ) F_12 (
V_16 ) ,
V_25 ) ;
V_15 [ V_17 ++ ] = V_16 ;
V_16 = NULL ;
}
}
F_8 ( & V_3 . V_20 ) ;
V_11 -> V_8 = V_16 ;
F_4 ( L_8 ,
( unsigned long ) F_12 ( V_11 -> V_8 ) ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_12 = V_12 ;
++ V_3 . V_5 ;
F_2 ( & V_11 -> V_2 ) ;
F_13 ( & V_11 -> V_2 , & V_1 . V_2 ) ;
memcpy ( V_11 -> V_8 , V_8 , V_9 ) ;
F_4 ( L_9 ) ;
V_27:
for (; V_17 > 0 ; V_17 -- ) {
F_4 ( L_10 ,
( unsigned long ) F_12 (
V_15 [ V_17 - 1 ] ) ) ;
F_14 ( ( unsigned long ) V_15 [ V_17 - 1 ] ,
V_12 ) ;
}
F_15 ( V_15 ) ;
V_26:
if ( V_13 )
F_15 ( V_11 ) ;
V_19:
return V_13 ;
}
static int F_16 ( const T_2 * V_8 , T_1 V_9 )
{
int V_28 = 0 ;
int V_29 = 0 ;
int V_30 ;
T_2 * V_31 ;
T_2 * V_32 = ( T_2 * ) V_8 + V_9 ;
F_4 ( L_11 , V_9 ) ;
if ( ! V_3 . V_6 ) {
F_7 ( V_22
L_12 ) ;
return - V_33 ;
}
V_31 = ( T_2 * ) V_8 ;
while ( ! V_29 ) {
if ( ( V_31 + V_3 . V_6 ) < V_32 )
V_30 = V_3 . V_6 ;
else {
V_30 = V_32 - V_31 ;
V_29 = 1 ;
}
if ( ( V_28 = F_3 ( V_31 , V_30 ) ) )
return V_28 ;
F_4 ( L_13 , V_31 , ( V_32 - V_31 ) ) ;
V_31 += V_30 ;
}
V_3 . V_7 = V_9 ;
return V_28 ;
}
static int F_17 ( char * V_8 , struct V_34 * V_35 ,
int V_9 , int V_36 , int * V_37 )
{
void * V_38 ;
struct V_10 * V_11 = NULL ;
int V_39 = 0 ;
int V_40 = 0 ;
V_11 = F_18 ( V_35 , struct V_10 , V_2 ) ;
* V_37 += V_11 -> V_9 ;
if ( * V_37 > V_36 ) {
V_40 = V_11 -> V_9 - ( * V_37 - V_36 ) ;
V_38 = ( T_2 * ) V_11 -> V_8 + V_40 ;
if ( V_9 > ( * V_37 - V_36 ) )
V_39 = ( * V_37 - V_36 ) ;
else
V_39 = V_9 ;
memcpy ( V_8 , V_38 , V_39 ) ;
}
return V_39 ;
}
static int F_19 ( char * V_8 , T_1 * V_41 )
{
struct V_34 * V_35 ;
int V_42 = 0 ;
int V_39 = 0 ;
int V_36 = 0 ;
int V_43 = 0 ;
char * V_44 = V_8 ;
if ( 0 == V_3 . V_5 )
return - V_24 ;
V_43 = * V_41 ;
V_36 = V_3 . V_4 ;
V_35 = ( & V_1 . V_2 ) -> V_45 ;
while ( ! F_20 ( V_35 ) ) {
V_39 = F_17 ( V_44 , V_35 ,
V_43 , V_36 , & V_42 ) ;
V_43 -= V_39 ;
V_36 += V_39 ;
V_44 += V_39 ;
if ( V_43 == 0 )
break;
V_35 = V_35 -> V_45 ;
}
* V_41 = V_36 - V_3 . V_4 ;
V_3 . V_4 = V_36 ;
return 0 ;
}
static void F_21 ( void )
{
struct V_34 * V_35 ;
struct V_34 * V_46 ;
struct V_10 * V_11 ;
V_35 = ( & V_1 . V_2 ) -> V_45 ;
while ( ! F_20 ( V_35 ) ) {
V_11 =
F_18 ( V_35 , struct V_10 , V_2 ) ;
V_46 = V_35 -> V_45 ;
F_22 ( V_35 ) ;
V_35 = V_46 ;
memset ( V_11 -> V_8 , 0 , V_3 . V_6 ) ;
F_14 ( ( unsigned long ) V_11 -> V_8 ,
V_11 -> V_12 ) ;
F_15 ( V_11 ) ;
}
V_3 . V_4 = 0 ;
V_3 . V_5 = 0 ;
V_3 . V_7 = 0 ;
}
static void F_23 ( void )
{
if ( ! V_3 . V_47 )
return;
memset ( V_3 . V_47 , 0 ,
V_3 . V_48 ) ;
if ( V_3 . V_49 == 1 )
F_24 ( NULL , V_3 . V_50 ,
V_3 . V_47 , V_51 ) ;
else
F_14 ( ( unsigned long ) V_3 . V_47 ,
V_3 . V_52 ) ;
V_3 . V_52 = - 1 ;
V_3 . V_47 = NULL ;
V_3 . V_48 = 0 ;
V_3 . V_50 = 0 ;
V_3 . V_49 = 0 ;
}
static int F_25 ( unsigned long V_53 )
{
unsigned char * V_47 = NULL ;
unsigned long V_28 ;
unsigned long V_54 ;
int V_12 ;
int V_49 = 0 ;
if ( V_3 . V_48 >= V_53 ) {
if ( ( V_53 != 0 ) && ( V_3 . V_47 == NULL ) ) {
F_7 ( V_55 L_14
L_15 , V_23 ) ;
return - V_18 ;
}
return 0 ;
}
F_23 () ;
F_5 ( & V_3 . V_20 ) ;
V_12 = F_9 ( V_53 ) ;
V_47 =
( unsigned char * ) F_11 ( V_21 , V_12 ) ;
V_54 =
( unsigned long ) F_12 ( V_47 ) ;
if ( V_54 > V_56 ) {
F_14 ( ( unsigned long ) V_47 , V_12 ) ;
V_12 = - 1 ;
V_47 = F_26 ( NULL , V_53 ,
& V_51 , V_21 ) ;
V_49 = 1 ;
}
F_8 ( & V_3 . V_20 ) ;
if ( V_47 != NULL ) {
V_3 . V_47 = V_47 ;
V_3 . V_48 = V_53 ;
V_3 . V_50 =
V_3 . V_48 ;
V_3 . V_52 = V_12 ;
V_3 . V_49 = V_49 ;
V_28 = 0 ;
} else {
F_4 ( L_16
L_17 , V_53 ) ;
V_28 = - V_24 ;
}
return V_28 ;
}
static T_3 F_27 ( char * V_57 , T_4 V_58 , T_1 V_59 )
{
int V_13 ;
T_1 V_60 ;
T_1 V_61 ;
char * V_62 = V_57 ;
if ( V_3 . V_5 == 0 ) {
F_4 ( L_18 ) ;
V_13 = - V_24 ;
goto V_63;
}
if ( V_58 > V_3 . V_7 ) {
V_13 = 0 ;
F_7 ( V_22 L_19
L_20 ) ;
goto V_63;
}
V_60 = V_3 . V_7 - V_58 ;
V_61 = F_28 ( V_60 , V_59 ) ;
if ( ( V_13 = F_19 ( V_62 , & V_61 ) ) < 0 )
goto V_63;
if ( ( V_58 + V_59 ) > V_3 . V_7 ) {
V_3 . V_4 = 0 ;
V_13 = V_60 ;
} else
V_13 = V_59 ;
V_63:
return V_13 ;
}
static T_3 F_29 ( char * V_57 , T_4 V_58 , T_1 V_59 )
{
if ( ( V_3 . V_47 == NULL ) ||
( V_3 . V_50 == 0 ) ) {
F_4 ( L_21
L_22 ,
V_3 . V_47 ,
V_3 . V_50 ) ;
return - V_24 ;
}
return F_30 ( V_57 , V_59 , & V_58 ,
V_3 . V_47 , V_3 . V_50 ) ;
}
static T_3 F_31 ( struct V_64 * V_65 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
char * V_57 , T_4 V_58 , T_1 V_59 )
{
T_3 V_70 = 0 ;
F_8 ( & V_3 . V_20 ) ;
if ( ! strcmp ( V_71 , L_23 ) )
V_70 = F_29 ( V_57 , V_58 , V_59 ) ;
else if ( ! strcmp ( V_71 , L_24 ) )
V_70 = F_27 ( V_57 , V_58 , V_59 ) ;
else
F_4 ( L_25 ) ;
F_5 ( & V_3 . V_20 ) ;
return V_70 ;
}
static void F_32 ( const struct V_72 * V_73 , void * V_74 )
{
V_3 . V_75 = 0 ;
if ( ! V_73 )
return;
if ( ! V_73 -> V_53 )
goto V_76;
F_8 ( & V_3 . V_20 ) ;
if ( ! strcmp ( V_71 , L_23 ) ) {
if ( ! F_25 ( V_73 -> V_53 ) )
memcpy ( V_3 . V_47 ,
V_73 -> V_8 , V_73 -> V_53 ) ;
} else if ( ! strcmp ( V_71 , L_24 ) ) {
F_21 () ;
if ( F_16 ( V_73 -> V_8 , V_73 -> V_53 ) )
F_21 () ;
} else
F_4 ( L_26 ) ;
F_5 ( & V_3 . V_20 ) ;
V_76:
F_33 ( V_73 ) ;
}
static T_3 F_34 ( struct V_64 * V_65 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
char * V_57 , T_4 V_58 , T_1 V_59 )
{
int V_53 = 0 ;
if ( ! V_58 )
V_53 = F_35 ( V_57 , V_59 , L_27 , V_71 ) ;
return V_53 ;
}
static T_3 F_36 ( struct V_64 * V_65 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
char * V_57 , T_4 V_58 , T_1 V_59 )
{
int V_28 = V_59 ;
int V_77 = 0 ;
int V_78 ;
F_8 ( & V_3 . V_20 ) ;
for ( V_78 = 0 ; V_78 < V_59 ; ++ V_78 )
if ( V_57 [ V_78 ] == '\n' || V_57 [ V_78 ] == ' ' ) {
V_57 [ V_78 ] = '\0' ;
break;
}
if ( V_78 == V_59 )
V_57 [ V_59 ] = '\0' ;
if ( strstr ( V_57 , L_23 ) )
strcpy ( V_71 , L_23 ) ;
else if ( strstr ( V_57 , L_24 ) )
strcpy ( V_71 , L_24 ) ;
else if ( strstr ( V_57 , L_28 ) ) {
if ( ! V_3 . V_75 ) {
F_5 ( & V_3 . V_20 ) ;
V_77 = F_37 ( V_79 ,
V_80 , L_29 ,
& V_81 -> V_82 , V_21 , & V_74 ,
F_32 ) ;
if ( V_77 ) {
F_7 ( V_55
L_30
L_31 , V_23 , V_28 ) ;
V_28 = - V_33 ;
} else
V_3 . V_75 = 1 ;
F_8 ( & V_3 . V_20 ) ;
}
} else {
F_7 ( V_22 L_32 ) ;
F_5 ( & V_3 . V_20 ) ;
return - V_18 ;
}
F_21 () ;
F_23 () ;
F_5 ( & V_3 . V_20 ) ;
return V_28 ;
}
static T_3 F_38 ( struct V_64 * V_65 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
char * V_57 , T_4 V_58 , T_1 V_59 )
{
int V_53 = 0 ;
if ( ! V_58 ) {
F_8 ( & V_3 . V_20 ) ;
V_53 = F_35 ( V_57 , V_59 , L_33 , V_3 . V_6 ) ;
F_5 ( & V_3 . V_20 ) ;
}
return V_53 ;
}
static T_3 F_39 ( struct V_64 * V_65 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
char * V_57 , T_4 V_58 , T_1 V_59 )
{
unsigned long V_31 ;
F_8 ( & V_3 . V_20 ) ;
F_21 () ;
sscanf ( V_57 , L_34 , & V_31 ) ;
if ( V_31 < 0xffffffff )
V_3 . V_6 = V_31 ;
F_5 ( & V_3 . V_20 ) ;
return V_59 ;
}
static int T_5 F_40 ( void )
{
int V_28 ;
F_41 ( & V_3 . V_20 ) ;
F_1 () ;
V_81 = F_42 ( L_29 , - 1 , NULL , 0 ) ;
if ( F_43 ( V_81 ) ) {
F_7 ( V_55
L_35
L_36 , V_23 ) ;
return F_44 ( V_81 ) ;
}
V_28 = F_45 ( & V_81 -> V_82 . V_67 , & V_83 ) ;
if ( V_28 )
goto V_84;
V_28 = F_45 ( & V_81 -> V_82 . V_67 , & V_85 ) ;
if ( V_28 )
goto V_86;
V_28 = F_45 ( & V_81 -> V_82 . V_67 ,
& V_87 ) ;
if ( V_28 )
goto V_88;
V_3 . V_75 = 0 ;
return 0 ;
V_88:
F_46 ( & V_81 -> V_82 . V_67 , & V_85 ) ;
V_86:
F_46 ( & V_81 -> V_82 . V_67 , & V_83 ) ;
V_84:
F_47 ( V_81 ) ;
return V_28 ;
}
static T_6 void F_48 ( void )
{
F_8 ( & V_3 . V_20 ) ;
F_21 () ;
F_23 () ;
F_5 ( & V_3 . V_20 ) ;
F_47 ( V_81 ) ;
}
