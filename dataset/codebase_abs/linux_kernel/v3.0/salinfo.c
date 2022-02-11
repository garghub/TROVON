static void
F_1 ( struct V_1 * V_2 )
{
( void ) ( F_2 ( & V_2 -> V_3 ) ? : 0 ) ;
F_3 ( & V_2 -> V_3 ) ;
}
static void
F_4 ( void * V_4 )
{
struct V_5 * V_6 = V_4 ;
V_6 -> V_7 = F_5 ( V_6 -> V_8 , V_6 -> V_9 , V_6 -> V_10 ) ;
}
static void
F_6 ( struct V_1 * V_2 , int V_11 )
{
memcpy ( V_2 -> V_12 + V_11 , V_2 -> V_12 + V_11 + 1 ,
( F_7 ( V_2 -> V_12 ) - ( V_11 + 1 ) ) * sizeof( V_2 -> V_12 [ 0 ] ) ) ;
memset ( V_2 -> V_12 + F_7 ( V_2 -> V_12 ) - 1 , 0 ,
sizeof( V_2 -> V_12 [ 0 ] ) ) ;
}
void
F_8 ( int type , T_1 * V_13 , T_2 V_14 , int V_15 )
{
struct V_1 * V_2 = V_1 + type ;
struct V_16 * V_12 ;
unsigned long V_17 = 0 ;
int V_18 ;
int V_19 = F_7 ( V_2 -> V_12 ) ;
F_9 ( type >= F_7 ( V_20 ) ) ;
if ( V_15 )
F_10 ( & V_21 , V_17 ) ;
if ( V_13 ) {
for ( V_18 = 0 , V_12 = V_2 -> V_12 ; V_18 < V_19 ; ++ V_18 , ++ V_12 ) {
if ( ! V_12 -> V_13 )
break;
}
if ( V_18 == V_19 ) {
if ( ! V_2 -> V_22 ) {
F_6 ( V_2 , 0 ) ;
V_12 = V_2 -> V_12 + V_19 - 1 ;
} else
V_12 = NULL ;
}
if ( V_12 ) {
V_12 -> V_23 = F_11 () ;
V_12 -> V_24 = ( ( V_25 * ) V_13 ) -> V_24 ;
V_12 -> V_14 = V_14 ;
V_12 -> V_13 = V_13 ;
}
}
F_12 ( F_11 () , V_2 -> V_26 ) ;
if ( V_15 ) {
F_1 ( V_2 ) ;
F_13 ( & V_21 , V_17 ) ;
}
}
static void
F_14 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
if ( ! V_2 -> V_27 )
return;
if ( ! F_15 ( V_2 -> V_26 ) ) {
F_10 ( & V_21 , V_17 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_21 , V_17 ) ;
}
}
static void
F_16 ( unsigned long V_28 )
{
F_17 () ;
F_14 ( V_1 + V_29 ) ;
F_14 ( V_1 + V_30 ) ;
V_31 . V_32 = V_33 + V_34 ;
F_18 ( & V_31 ) ;
}
static int
F_19 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
if ( ! F_20 ( V_37 ) )
return - V_38 ;
return 0 ;
}
static T_3
F_21 ( struct V_36 * V_36 , char T_4 * V_13 , T_5 V_39 , T_6 * V_40 )
{
struct V_35 * V_35 = V_36 -> V_41 . V_42 -> V_43 ;
struct V_44 * V_45 = F_22 ( V_35 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
char V_46 [ 32 ] ;
T_5 V_14 ;
int V_18 , V_47 , V_23 = - 1 ;
V_48:
if ( F_15 ( V_2 -> V_26 ) && F_2 ( & V_2 -> V_3 ) ) {
if ( V_36 -> V_49 & V_50 )
return - V_51 ;
if ( F_23 ( & V_2 -> V_3 ) )
return - V_52 ;
}
V_47 = V_2 -> V_53 ;
for ( V_18 = 0 ; V_18 < V_54 ; V_18 ++ ) {
if ( F_24 ( V_47 , V_2 -> V_26 ) ) {
if ( ! F_25 ( V_47 ) ) {
F_26 ( V_47 , V_2 -> V_26 ) ;
continue;
}
V_23 = V_47 ;
break;
}
if ( ++ V_47 == V_54 )
V_47 = 0 ;
}
if ( V_23 == - 1 )
goto V_48;
F_17 () ;
V_2 -> V_53 = V_23 ;
if ( ++ V_2 -> V_53 == V_54 )
V_2 -> V_53 = 0 ;
snprintf ( V_46 , sizeof( V_46 ) , L_1 , V_23 ) ;
V_14 = strlen ( V_46 ) ;
if ( V_14 > V_39 )
V_14 = V_39 ;
if ( F_27 ( V_13 , V_46 , V_14 ) )
return - V_55 ;
return V_14 ;
}
static int
F_28 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_44 * V_45 = F_22 ( V_35 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
if ( ! F_20 ( V_37 ) )
return - V_38 ;
F_29 ( & V_56 ) ;
if ( V_2 -> V_27 ) {
F_30 ( & V_56 ) ;
return - V_57 ;
}
V_2 -> V_27 = 1 ;
F_30 ( & V_56 ) ;
if ( V_2 -> V_58 == V_59 &&
! ( V_2 -> V_60 = F_31 ( F_32 ( V_2 -> type ) ) ) ) {
V_2 -> V_27 = 0 ;
return - V_61 ;
}
return 0 ;
}
static int
F_33 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_44 * V_45 = F_22 ( V_35 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
if ( V_2 -> V_58 == V_59 ) {
F_34 ( V_2 -> V_60 ) ;
F_34 ( V_2 -> V_9 ) ;
V_2 -> V_60 = NULL ;
V_2 -> V_9 = NULL ;
}
F_29 ( & V_56 ) ;
V_2 -> V_27 = 0 ;
F_30 ( & V_56 ) ;
return 0 ;
}
static void
F_35 ( int V_23 , void (* F_36)( void * ) , void * V_28 )
{
T_7 V_62 = V_63 -> V_64 ;
F_37 ( V_63 , F_38 ( V_23 ) ) ;
(* F_36)( V_28 ) ;
F_37 ( V_63 , & V_62 ) ;
}
static void
F_39 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
V_25 * V_65 ;
V_2 -> V_66 = F_40 ( V_2 -> type , ( T_2 * ) V_2 -> V_60 ) ;
V_65 = ( V_25 * ) ( V_2 -> V_60 ) ;
if ( V_65 -> V_67 == V_68 )
F_41 ( V_2 -> type ) ;
}
static void
F_42 ( int V_23 , struct V_1 * V_2 )
{
struct V_16 * V_12 ;
unsigned long V_17 ;
int V_18 ;
int V_19 = F_7 ( V_2 -> V_12 ) ;
V_2 -> V_22 = 0 ;
F_10 ( & V_21 , V_17 ) ;
V_48:
for ( V_18 = 0 , V_12 = V_2 -> V_12 ; V_18 < V_19 ; ++ V_18 , ++ V_12 ) {
if ( V_12 -> V_13 && V_12 -> V_23 == V_23 ) {
V_25 * V_65 = ( V_25 * ) ( V_12 -> V_13 ) ;
V_2 -> V_66 = V_12 -> V_14 ;
memcpy ( V_2 -> V_60 , V_65 , V_2 -> V_66 ) ;
F_43 () ;
if ( V_65 -> V_24 == V_12 -> V_24 ) {
V_2 -> V_22 = V_18 + 1 ;
break;
}
F_6 ( V_2 , V_18 ) ;
goto V_48;
}
}
F_13 ( & V_21 , V_17 ) ;
if ( ! V_2 -> V_22 )
F_35 ( V_23 , F_39 , V_2 ) ;
if ( ! V_2 -> V_66 ) {
V_2 -> V_58 = V_59 ;
F_26 ( V_23 , V_2 -> V_26 ) ;
} else {
V_2 -> V_58 = V_69 ;
}
}
static T_3
F_44 ( struct V_36 * V_36 , char T_4 * V_13 , T_5 V_39 , T_6 * V_40 )
{
struct V_35 * V_35 = V_36 -> V_41 . V_42 -> V_43 ;
struct V_44 * V_45 = F_22 ( V_35 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
T_1 * V_70 ;
T_2 V_71 ;
if ( V_2 -> V_58 == V_69 ) {
V_70 = V_2 -> V_60 ;
V_71 = V_2 -> V_66 ;
} else if ( V_2 -> V_58 == V_72 ) {
V_70 = V_2 -> V_9 ;
V_71 = V_2 -> V_10 ;
} else {
V_70 = NULL ;
V_71 = 0 ;
}
return F_45 ( V_13 , V_39 , V_40 , V_70 , V_71 ) ;
}
static void
F_46 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_41 ( V_2 -> type ) ;
}
static int
F_47 ( struct V_1 * V_2 , int V_23 )
{
V_25 * V_65 ;
unsigned long V_17 ;
F_10 ( & V_21 , V_17 ) ;
V_2 -> V_58 = V_59 ;
if ( ! F_24 ( V_23 , V_2 -> V_26 ) ) {
F_13 ( & V_21 , V_17 ) ;
return 0 ;
}
F_26 ( V_23 , V_2 -> V_26 ) ;
if ( V_2 -> V_22 ) {
F_6 ( V_2 , V_2 -> V_22 - 1 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( & V_21 , V_17 ) ;
V_65 = ( V_25 * ) ( V_2 -> V_60 ) ;
if ( V_65 -> V_67 != V_68 )
F_35 ( V_23 , F_46 , V_2 ) ;
F_42 ( V_23 , V_2 ) ;
if ( V_2 -> V_58 == V_69 ) {
F_10 ( & V_21 , V_17 ) ;
F_12 ( V_23 , V_2 -> V_26 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_21 , V_17 ) ;
}
return 0 ;
}
static T_3
F_48 ( struct V_36 * V_36 , const char T_4 * V_13 , T_5 V_39 , T_6 * V_40 )
{
struct V_35 * V_35 = V_36 -> V_41 . V_42 -> V_43 ;
struct V_44 * V_45 = F_22 ( V_35 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
char V_46 [ 32 ] ;
T_5 V_14 ;
T_8 V_73 ;
int V_23 ;
V_14 = sizeof( V_46 ) ;
if ( V_39 < V_14 )
V_14 = V_39 ;
if ( F_49 ( V_46 , V_13 , V_14 ) )
return - V_55 ;
if ( sscanf ( V_46 , L_2 , & V_23 ) == 1 ) {
F_42 ( V_23 , V_2 ) ;
} else if ( sscanf ( V_46 , L_3 , & V_23 ) == 1 ) {
int V_7 ;
if ( ( V_7 = F_47 ( V_2 , V_23 ) ) )
V_39 = V_7 ;
} else if ( sscanf ( V_46 , L_4 , & V_23 , & V_73 ) == 2 ) {
if ( V_2 -> V_58 != V_69 && V_2 -> V_58 != V_72 )
return - V_74 ;
if ( V_73 > V_2 -> V_66 - sizeof( V_75 ) )
return - V_74 ;
V_2 -> V_58 = V_72 ;
if ( F_5 ) {
struct V_5 V_6 = {
. V_8 = V_2 -> V_60 + V_73 ,
. V_9 = & V_2 -> V_9 ,
. V_10 = & V_2 -> V_10
} ;
F_35 ( V_23 , F_4 , & V_6 ) ;
if ( V_6 . V_7 )
V_39 = V_6 . V_7 ;
} else
V_2 -> V_10 = 0 ;
} else
return - V_74 ;
return V_39 ;
}
static int T_9
F_50 ( struct V_76 * V_77 , unsigned long V_78 , void * V_79 )
{
unsigned int V_18 , V_23 = ( unsigned long ) V_79 ;
unsigned long V_17 ;
struct V_1 * V_2 ;
switch ( V_78 ) {
case V_80 :
case V_81 :
F_10 ( & V_21 , V_17 ) ;
for ( V_18 = 0 , V_2 = V_1 ;
V_18 < F_7 ( V_1 ) ;
++ V_18 , ++ V_2 ) {
F_12 ( V_23 , V_2 -> V_26 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_21 , V_17 ) ;
break;
case V_82 :
case V_83 :
F_10 ( & V_21 , V_17 ) ;
for ( V_18 = 0 , V_2 = V_1 ;
V_18 < F_7 ( V_1 ) ;
++ V_18 , ++ V_2 ) {
struct V_16 * V_12 ;
int V_84 ;
for ( V_84 = F_7 ( V_2 -> V_12 ) - 1 , V_12 = V_2 -> V_12 + V_84 ;
V_84 >= 0 ;
-- V_84 , -- V_12 ) {
if ( V_12 -> V_13 && V_12 -> V_23 == V_23 ) {
F_6 ( V_2 , V_84 ) ;
}
}
F_26 ( V_23 , V_2 -> V_26 ) ;
}
F_13 ( & V_21 , V_17 ) ;
break;
}
return V_85 ;
}
static int T_10
F_51 ( void )
{
struct V_44 * V_86 ;
struct V_44 * * V_87 = V_88 ;
struct V_44 * V_89 , * V_45 ;
struct V_1 * V_2 ;
int V_18 , V_84 ;
V_86 = F_52 ( L_5 , NULL ) ;
if ( ! V_86 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_90 ; V_18 ++ ) {
* V_87 ++ = F_53 ( V_91 [ V_18 ] . V_92 , 0 , V_86 ,
V_93 , ( void * ) V_91 [ V_18 ] . V_94 ) ;
}
for ( V_18 = 0 ; V_18 < F_7 ( V_20 ) ; V_18 ++ ) {
V_2 = V_1 + V_18 ;
V_2 -> type = V_18 ;
F_54 ( & V_2 -> V_3 , 1 ) ;
V_89 = F_52 ( V_20 [ V_18 ] , V_86 ) ;
if ( ! V_89 )
continue;
V_45 = F_55 ( L_6 , V_95 , V_89 ,
& V_96 , V_2 ) ;
if ( ! V_45 )
continue;
* V_87 ++ = V_45 ;
V_45 = F_55 ( L_7 , V_95 | V_97 , V_89 ,
& V_98 , V_2 ) ;
if ( ! V_45 )
continue;
* V_87 ++ = V_45 ;
F_56 (j)
F_12 ( V_84 , V_2 -> V_26 ) ;
* V_87 ++ = V_89 ;
}
* V_87 ++ = V_86 ;
F_57 ( & V_31 ) ;
V_31 . V_32 = V_33 + V_34 ;
V_31 . V_99 = & F_16 ;
F_18 ( & V_31 ) ;
F_58 ( & V_100 ) ;
return 0 ;
}
static int
V_93 ( char * V_101 , char * * V_102 , T_11 V_103 , int V_39 , int * V_104 , void * V_2 )
{
int V_105 = 0 ;
V_105 = sprintf ( V_101 , ( V_106 & ( unsigned long ) V_2 ) ? L_8 : L_9 ) ;
if ( V_105 <= V_103 + V_39 ) * V_104 = 1 ;
* V_102 = V_101 + V_103 ;
V_105 -= V_103 ;
if ( V_105 > V_39 ) V_105 = V_39 ;
if ( V_105 < 0 ) V_105 = 0 ;
return V_105 ;
}
