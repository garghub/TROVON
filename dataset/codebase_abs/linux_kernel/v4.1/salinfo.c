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
F_12 ( F_11 () , & V_2 -> V_26 ) ;
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
if ( ! F_15 ( & V_2 -> V_26 ) ) {
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
struct V_1 * V_2 = F_22 ( F_23 ( V_36 ) ) ;
char V_41 [ 32 ] ;
T_5 V_14 ;
int V_18 , V_42 , V_23 = - 1 ;
V_43:
if ( F_15 ( & V_2 -> V_26 ) && F_2 ( & V_2 -> V_3 ) ) {
if ( V_36 -> V_44 & V_45 )
return - V_46 ;
if ( F_24 ( & V_2 -> V_3 ) )
return - V_47 ;
}
V_42 = V_2 -> V_48 ;
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ ) {
if ( F_25 ( V_42 , & V_2 -> V_26 ) ) {
if ( ! F_26 ( V_42 ) ) {
F_27 ( V_42 , & V_2 -> V_26 ) ;
continue;
}
V_23 = V_42 ;
break;
}
if ( ++ V_42 == V_49 )
V_42 = 0 ;
}
if ( V_23 == - 1 )
goto V_43;
F_17 () ;
V_2 -> V_48 = V_23 ;
if ( ++ V_2 -> V_48 == V_49 )
V_2 -> V_48 = 0 ;
snprintf ( V_41 , sizeof( V_41 ) , L_1 , V_23 ) ;
V_14 = strlen ( V_41 ) ;
if ( V_14 > V_39 )
V_14 = V_39 ;
if ( F_28 ( V_13 , V_41 , V_14 ) )
return - V_50 ;
return V_14 ;
}
static int
F_29 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
if ( ! F_20 ( V_37 ) )
return - V_38 ;
F_30 ( & V_51 ) ;
if ( V_2 -> V_27 ) {
F_31 ( & V_51 ) ;
return - V_52 ;
}
V_2 -> V_27 = 1 ;
F_31 ( & V_51 ) ;
if ( V_2 -> V_53 == V_54 &&
! ( V_2 -> V_55 = F_32 ( F_33 ( V_2 -> type ) ) ) ) {
V_2 -> V_27 = 0 ;
return - V_56 ;
}
return 0 ;
}
static int
F_34 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
if ( V_2 -> V_53 == V_54 ) {
F_35 ( V_2 -> V_55 ) ;
F_35 ( V_2 -> V_9 ) ;
V_2 -> V_55 = NULL ;
V_2 -> V_9 = NULL ;
}
F_30 ( & V_51 ) ;
V_2 -> V_27 = 0 ;
F_31 ( & V_51 ) ;
return 0 ;
}
static void
F_36 ( int V_23 , void (* F_37)( void * ) , void * V_28 )
{
T_7 V_57 = V_58 -> V_59 ;
F_38 ( V_58 , F_39 ( V_23 ) ) ;
(* F_37)( V_28 ) ;
F_38 ( V_58 , & V_57 ) ;
}
static void
F_40 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
V_25 * V_60 ;
V_2 -> V_61 = F_41 ( V_2 -> type , ( T_2 * ) V_2 -> V_55 ) ;
V_60 = ( V_25 * ) ( V_2 -> V_55 ) ;
if ( V_60 -> V_62 == V_63 )
F_42 ( V_2 -> type ) ;
}
static void
F_43 ( int V_23 , struct V_1 * V_2 )
{
struct V_16 * V_12 ;
unsigned long V_17 ;
int V_18 ;
int V_19 = F_7 ( V_2 -> V_12 ) ;
V_2 -> V_22 = 0 ;
F_10 ( & V_21 , V_17 ) ;
V_43:
for ( V_18 = 0 , V_12 = V_2 -> V_12 ; V_18 < V_19 ; ++ V_18 , ++ V_12 ) {
if ( V_12 -> V_13 && V_12 -> V_23 == V_23 ) {
V_25 * V_60 = ( V_25 * ) ( V_12 -> V_13 ) ;
V_2 -> V_61 = V_12 -> V_14 ;
memcpy ( V_2 -> V_55 , V_60 , V_2 -> V_61 ) ;
F_44 () ;
if ( V_60 -> V_24 == V_12 -> V_24 ) {
V_2 -> V_22 = V_18 + 1 ;
break;
}
F_6 ( V_2 , V_18 ) ;
goto V_43;
}
}
F_13 ( & V_21 , V_17 ) ;
if ( ! V_2 -> V_22 )
F_36 ( V_23 , F_40 , V_2 ) ;
if ( ! V_2 -> V_61 ) {
V_2 -> V_53 = V_54 ;
F_27 ( V_23 , & V_2 -> V_26 ) ;
} else {
V_2 -> V_53 = V_64 ;
}
}
static T_3
F_45 ( struct V_36 * V_36 , char T_4 * V_13 , T_5 V_39 , T_6 * V_40 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_36 ) ) ;
T_1 * V_65 ;
T_2 V_66 ;
if ( V_2 -> V_53 == V_64 ) {
V_65 = V_2 -> V_55 ;
V_66 = V_2 -> V_61 ;
} else if ( V_2 -> V_53 == V_67 ) {
V_65 = V_2 -> V_9 ;
V_66 = V_2 -> V_10 ;
} else {
V_65 = NULL ;
V_66 = 0 ;
}
return F_46 ( V_13 , V_39 , V_40 , V_65 , V_66 ) ;
}
static void
F_47 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_42 ( V_2 -> type ) ;
}
static int
F_48 ( struct V_1 * V_2 , int V_23 )
{
V_25 * V_60 ;
unsigned long V_17 ;
F_10 ( & V_21 , V_17 ) ;
V_2 -> V_53 = V_54 ;
if ( ! F_25 ( V_23 , & V_2 -> V_26 ) ) {
F_13 ( & V_21 , V_17 ) ;
return 0 ;
}
F_27 ( V_23 , & V_2 -> V_26 ) ;
if ( V_2 -> V_22 ) {
F_6 ( V_2 , V_2 -> V_22 - 1 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( & V_21 , V_17 ) ;
V_60 = ( V_25 * ) ( V_2 -> V_55 ) ;
if ( V_60 -> V_62 != V_63 )
F_36 ( V_23 , F_47 , V_2 ) ;
F_43 ( V_23 , V_2 ) ;
if ( V_2 -> V_53 == V_64 ) {
F_10 ( & V_21 , V_17 ) ;
F_12 ( V_23 , & V_2 -> V_26 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_21 , V_17 ) ;
}
return 0 ;
}
static T_3
F_49 ( struct V_36 * V_36 , const char T_4 * V_13 , T_5 V_39 , T_6 * V_40 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_36 ) ) ;
char V_41 [ 32 ] ;
T_5 V_14 ;
T_8 V_68 ;
int V_23 ;
V_14 = sizeof( V_41 ) ;
if ( V_39 < V_14 )
V_14 = V_39 ;
if ( F_50 ( V_41 , V_13 , V_14 ) )
return - V_50 ;
if ( sscanf ( V_41 , L_2 , & V_23 ) == 1 ) {
F_43 ( V_23 , V_2 ) ;
} else if ( sscanf ( V_41 , L_3 , & V_23 ) == 1 ) {
int V_7 ;
if ( ( V_7 = F_48 ( V_2 , V_23 ) ) )
V_39 = V_7 ;
} else if ( sscanf ( V_41 , L_4 , & V_23 , & V_68 ) == 2 ) {
if ( V_2 -> V_53 != V_64 && V_2 -> V_53 != V_67 )
return - V_69 ;
if ( V_68 > V_2 -> V_61 - sizeof( V_70 ) )
return - V_69 ;
V_2 -> V_53 = V_67 ;
if ( F_5 ) {
struct V_5 V_6 = {
. V_8 = V_2 -> V_55 + V_68 ,
. V_9 = & V_2 -> V_9 ,
. V_10 = & V_2 -> V_10
} ;
F_36 ( V_23 , F_4 , & V_6 ) ;
if ( V_6 . V_7 )
V_39 = V_6 . V_7 ;
} else
V_2 -> V_10 = 0 ;
} else
return - V_69 ;
return V_39 ;
}
static int
F_51 ( struct V_71 * V_72 , unsigned long V_73 , void * V_74 )
{
unsigned int V_18 , V_23 = ( unsigned long ) V_74 ;
unsigned long V_17 ;
struct V_1 * V_2 ;
switch ( V_73 ) {
case V_75 :
case V_76 :
F_10 ( & V_21 , V_17 ) ;
for ( V_18 = 0 , V_2 = V_1 ;
V_18 < F_7 ( V_1 ) ;
++ V_18 , ++ V_2 ) {
F_12 ( V_23 , & V_2 -> V_26 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_21 , V_17 ) ;
break;
case V_77 :
case V_78 :
F_10 ( & V_21 , V_17 ) ;
for ( V_18 = 0 , V_2 = V_1 ;
V_18 < F_7 ( V_1 ) ;
++ V_18 , ++ V_2 ) {
struct V_16 * V_12 ;
int V_79 ;
for ( V_79 = F_7 ( V_2 -> V_12 ) - 1 , V_12 = V_2 -> V_12 + V_79 ;
V_79 >= 0 ;
-- V_79 , -- V_12 ) {
if ( V_12 -> V_13 && V_12 -> V_23 == V_23 ) {
F_6 ( V_2 , V_79 ) ;
}
}
F_27 ( V_23 , & V_2 -> V_26 ) ;
}
F_13 ( & V_21 , V_17 ) ;
break;
}
return V_80 ;
}
static int T_9
F_52 ( void )
{
struct V_81 * V_82 ;
struct V_81 * * V_83 = V_84 ;
struct V_81 * V_85 , * V_86 ;
struct V_1 * V_2 ;
int V_18 , V_79 ;
V_82 = F_53 ( L_5 , NULL ) ;
if ( ! V_82 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_87 ; V_18 ++ ) {
* V_83 ++ = F_54 ( V_88 [ V_18 ] . V_89 , 0 , V_82 ,
& V_90 ,
( void * ) V_88 [ V_18 ] . V_91 ) ;
}
F_55 () ;
for ( V_18 = 0 ; V_18 < F_7 ( V_20 ) ; V_18 ++ ) {
V_2 = V_1 + V_18 ;
V_2 -> type = V_18 ;
F_56 ( & V_2 -> V_3 , 1 ) ;
V_85 = F_53 ( V_20 [ V_18 ] , V_82 ) ;
if ( ! V_85 )
continue;
V_86 = F_54 ( L_6 , V_92 , V_85 ,
& V_93 , V_2 ) ;
if ( ! V_86 )
continue;
* V_83 ++ = V_86 ;
V_86 = F_54 ( L_7 , V_92 | V_94 , V_85 ,
& V_95 , V_2 ) ;
if ( ! V_86 )
continue;
* V_83 ++ = V_86 ;
F_57 (j)
F_12 ( V_79 , & V_2 -> V_26 ) ;
* V_83 ++ = V_85 ;
}
* V_83 ++ = V_82 ;
F_58 ( & V_31 ) ;
V_31 . V_32 = V_33 + V_34 ;
V_31 . V_96 = & F_16 ;
F_18 ( & V_31 ) ;
F_59 ( & V_97 ) ;
F_60 () ;
return 0 ;
}
static int F_61 ( struct V_98 * V_99 , void * V_100 )
{
unsigned long V_2 = ( unsigned long ) V_100 ;
F_62 ( V_99 , ( V_101 & V_2 ) ? L_8 : L_9 ) ;
return 0 ;
}
static int F_63 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_64 ( V_36 , F_61 , F_22 ( V_35 ) ) ;
}
