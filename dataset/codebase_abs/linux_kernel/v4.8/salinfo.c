static void
F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 = F_2 ( V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 ) ;
}
static void
F_3 ( struct V_8 * V_9 , int V_10 )
{
memcpy ( V_9 -> V_11 + V_10 , V_9 -> V_11 + V_10 + 1 ,
( F_4 ( V_9 -> V_11 ) - ( V_10 + 1 ) ) * sizeof( V_9 -> V_11 [ 0 ] ) ) ;
memset ( V_9 -> V_11 + F_4 ( V_9 -> V_11 ) - 1 , 0 ,
sizeof( V_9 -> V_11 [ 0 ] ) ) ;
}
void
F_5 ( int type , T_1 * V_12 , T_2 V_13 , int V_14 )
{
struct V_8 * V_9 = V_8 + type ;
struct V_15 * V_11 ;
unsigned long V_16 = 0 ;
int V_17 ;
int V_18 = F_4 ( V_9 -> V_11 ) ;
F_6 ( type >= F_4 ( V_19 ) ) ;
if ( V_14 )
F_7 ( & V_20 , V_16 ) ;
if ( V_12 ) {
for ( V_17 = 0 , V_11 = V_9 -> V_11 ; V_17 < V_18 ; ++ V_17 , ++ V_11 ) {
if ( ! V_11 -> V_12 )
break;
}
if ( V_17 == V_18 ) {
if ( ! V_9 -> V_21 ) {
F_3 ( V_9 , 0 ) ;
V_11 = V_9 -> V_11 + V_18 - 1 ;
} else
V_11 = NULL ;
}
if ( V_11 ) {
V_11 -> V_22 = F_8 () ;
V_11 -> V_23 = ( ( V_24 * ) V_12 ) -> V_23 ;
V_11 -> V_13 = V_13 ;
V_11 -> V_12 = V_12 ;
}
}
F_9 ( F_8 () , & V_9 -> V_25 ) ;
if ( V_14 ) {
F_10 ( & V_9 -> V_26 ) ;
F_11 ( & V_20 , V_16 ) ;
}
}
static void
F_12 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_27 )
return;
if ( ! F_13 ( & V_9 -> V_25 ) )
F_10 ( & V_9 -> V_26 ) ;
}
static void
F_14 ( unsigned long V_28 )
{
F_15 () ;
F_12 ( V_8 + V_29 ) ;
F_12 ( V_8 + V_30 ) ;
V_31 . V_32 = V_33 + V_34 ;
F_16 ( & V_31 ) ;
}
static int
F_17 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
if ( ! F_18 ( V_37 ) )
return - V_38 ;
return 0 ;
}
static T_3
F_19 ( struct V_36 * V_36 , char T_4 * V_12 , T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = F_20 ( F_21 ( V_36 ) ) ;
char V_41 [ 32 ] ;
T_5 V_13 ;
int V_17 , V_42 , V_22 = - 1 ;
V_43:
if ( F_13 ( & V_9 -> V_25 ) ) {
if ( V_36 -> V_44 & V_45 )
return - V_46 ;
if ( F_22 ( V_9 -> V_26 ,
! F_13 ( & V_9 -> V_25 ) ) )
return - V_47 ;
}
V_42 = V_9 -> V_48 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) {
if ( F_23 ( V_42 , & V_9 -> V_25 ) ) {
if ( ! F_24 ( V_42 ) ) {
F_25 ( V_42 , & V_9 -> V_25 ) ;
continue;
}
V_22 = V_42 ;
break;
}
if ( ++ V_42 == V_49 )
V_42 = 0 ;
}
if ( V_22 == - 1 )
goto V_43;
F_15 () ;
V_9 -> V_48 = V_22 ;
if ( ++ V_9 -> V_48 == V_49 )
V_9 -> V_48 = 0 ;
snprintf ( V_41 , sizeof( V_41 ) , L_1 , V_22 ) ;
V_13 = strlen ( V_41 ) ;
if ( V_13 > V_39 )
V_13 = V_39 ;
if ( F_26 ( V_12 , V_41 , V_13 ) )
return - V_50 ;
return V_13 ;
}
static int
F_27 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_8 * V_9 = F_20 ( V_35 ) ;
if ( ! F_18 ( V_37 ) )
return - V_38 ;
F_28 ( & V_51 ) ;
if ( V_9 -> V_27 ) {
F_29 ( & V_51 ) ;
return - V_52 ;
}
V_9 -> V_27 = 1 ;
F_29 ( & V_51 ) ;
if ( V_9 -> V_53 == V_54 &&
! ( V_9 -> V_55 = F_30 ( F_31 ( V_9 -> type ) ) ) ) {
V_9 -> V_27 = 0 ;
return - V_56 ;
}
return 0 ;
}
static int
F_32 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_8 * V_9 = F_20 ( V_35 ) ;
if ( V_9 -> V_53 == V_54 ) {
F_33 ( V_9 -> V_55 ) ;
F_33 ( V_9 -> V_6 ) ;
V_9 -> V_55 = NULL ;
V_9 -> V_6 = NULL ;
}
F_28 ( & V_51 ) ;
V_9 -> V_27 = 0 ;
F_29 ( & V_51 ) ;
return 0 ;
}
static void
F_34 ( int V_22 , void (* F_35)( void * ) , void * V_28 )
{
T_7 V_57 = V_58 -> V_59 ;
F_36 ( V_58 , F_37 ( V_22 ) ) ;
(* F_35)( V_28 ) ;
F_36 ( V_58 , & V_57 ) ;
}
static void
F_38 ( void * V_1 )
{
struct V_8 * V_9 = V_1 ;
V_24 * V_60 ;
V_9 -> V_61 = F_39 ( V_9 -> type , ( T_2 * ) V_9 -> V_55 ) ;
V_60 = ( V_24 * ) ( V_9 -> V_55 ) ;
if ( V_60 -> V_62 == V_63 )
F_40 ( V_9 -> type ) ;
}
static void
F_41 ( int V_22 , struct V_8 * V_9 )
{
struct V_15 * V_11 ;
unsigned long V_16 ;
int V_17 ;
int V_18 = F_4 ( V_9 -> V_11 ) ;
V_9 -> V_21 = 0 ;
F_7 ( & V_20 , V_16 ) ;
V_43:
for ( V_17 = 0 , V_11 = V_9 -> V_11 ; V_17 < V_18 ; ++ V_17 , ++ V_11 ) {
if ( V_11 -> V_12 && V_11 -> V_22 == V_22 ) {
V_24 * V_60 = ( V_24 * ) ( V_11 -> V_12 ) ;
V_9 -> V_61 = V_11 -> V_13 ;
memcpy ( V_9 -> V_55 , V_60 , V_9 -> V_61 ) ;
F_42 () ;
if ( V_60 -> V_23 == V_11 -> V_23 ) {
V_9 -> V_21 = V_17 + 1 ;
break;
}
F_3 ( V_9 , V_17 ) ;
goto V_43;
}
}
F_11 ( & V_20 , V_16 ) ;
if ( ! V_9 -> V_21 )
F_34 ( V_22 , F_38 , V_9 ) ;
if ( ! V_9 -> V_61 ) {
V_9 -> V_53 = V_54 ;
F_25 ( V_22 , & V_9 -> V_25 ) ;
} else {
V_9 -> V_53 = V_64 ;
}
}
static T_3
F_43 ( struct V_36 * V_36 , char T_4 * V_12 , T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = F_20 ( F_21 ( V_36 ) ) ;
T_1 * V_65 ;
T_2 V_66 ;
if ( V_9 -> V_53 == V_64 ) {
V_65 = V_9 -> V_55 ;
V_66 = V_9 -> V_61 ;
} else if ( V_9 -> V_53 == V_67 ) {
V_65 = V_9 -> V_6 ;
V_66 = V_9 -> V_7 ;
} else {
V_65 = NULL ;
V_66 = 0 ;
}
return F_44 ( V_12 , V_39 , V_40 , V_65 , V_66 ) ;
}
static void
F_45 ( void * V_1 )
{
struct V_8 * V_9 = V_1 ;
F_40 ( V_9 -> type ) ;
}
static int
F_46 ( struct V_8 * V_9 , int V_22 )
{
V_24 * V_60 ;
unsigned long V_16 ;
F_7 ( & V_20 , V_16 ) ;
V_9 -> V_53 = V_54 ;
if ( ! F_23 ( V_22 , & V_9 -> V_25 ) ) {
F_11 ( & V_20 , V_16 ) ;
return 0 ;
}
F_25 ( V_22 , & V_9 -> V_25 ) ;
if ( V_9 -> V_21 ) {
F_3 ( V_9 , V_9 -> V_21 - 1 ) ;
V_9 -> V_21 = 0 ;
}
F_11 ( & V_20 , V_16 ) ;
V_60 = ( V_24 * ) ( V_9 -> V_55 ) ;
if ( V_60 -> V_62 != V_63 )
F_34 ( V_22 , F_45 , V_9 ) ;
F_41 ( V_22 , V_9 ) ;
if ( V_9 -> V_53 == V_64 ) {
F_7 ( & V_20 , V_16 ) ;
F_9 ( V_22 , & V_9 -> V_25 ) ;
F_10 ( & V_9 -> V_26 ) ;
F_11 ( & V_20 , V_16 ) ;
}
return 0 ;
}
static T_3
F_47 ( struct V_36 * V_36 , const char T_4 * V_12 , T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = F_20 ( F_21 ( V_36 ) ) ;
char V_41 [ 32 ] ;
T_5 V_13 ;
T_8 V_68 ;
int V_22 ;
V_13 = sizeof( V_41 ) ;
if ( V_39 < V_13 )
V_13 = V_39 ;
if ( F_48 ( V_41 , V_12 , V_13 ) )
return - V_50 ;
if ( sscanf ( V_41 , L_2 , & V_22 ) == 1 ) {
F_41 ( V_22 , V_9 ) ;
} else if ( sscanf ( V_41 , L_3 , & V_22 ) == 1 ) {
int V_4 ;
if ( ( V_4 = F_46 ( V_9 , V_22 ) ) )
V_39 = V_4 ;
} else if ( sscanf ( V_41 , L_4 , & V_22 , & V_68 ) == 2 ) {
if ( V_9 -> V_53 != V_64 && V_9 -> V_53 != V_67 )
return - V_69 ;
if ( V_68 > V_9 -> V_61 - sizeof( V_70 ) )
return - V_69 ;
V_9 -> V_53 = V_67 ;
if ( F_2 ) {
struct V_2 V_3 = {
. V_5 = V_9 -> V_55 + V_68 ,
. V_6 = & V_9 -> V_6 ,
. V_7 = & V_9 -> V_7
} ;
F_34 ( V_22 , F_1 , & V_3 ) ;
if ( V_3 . V_4 )
V_39 = V_3 . V_4 ;
} else
V_9 -> V_7 = 0 ;
} else
return - V_69 ;
return V_39 ;
}
static int
F_49 ( struct V_71 * V_72 , unsigned long V_73 , void * V_74 )
{
unsigned int V_17 , V_22 = ( unsigned long ) V_74 ;
unsigned long V_16 ;
struct V_8 * V_9 ;
switch ( V_73 ) {
case V_75 :
case V_76 :
F_7 ( & V_20 , V_16 ) ;
for ( V_17 = 0 , V_9 = V_8 ;
V_17 < F_4 ( V_8 ) ;
++ V_17 , ++ V_9 ) {
F_9 ( V_22 , & V_9 -> V_25 ) ;
F_10 ( & V_9 -> V_26 ) ;
}
F_11 ( & V_20 , V_16 ) ;
break;
case V_77 :
case V_78 :
F_7 ( & V_20 , V_16 ) ;
for ( V_17 = 0 , V_9 = V_8 ;
V_17 < F_4 ( V_8 ) ;
++ V_17 , ++ V_9 ) {
struct V_15 * V_11 ;
int V_79 ;
for ( V_79 = F_4 ( V_9 -> V_11 ) - 1 , V_11 = V_9 -> V_11 + V_79 ;
V_79 >= 0 ;
-- V_79 , -- V_11 ) {
if ( V_11 -> V_12 && V_11 -> V_22 == V_22 ) {
F_3 ( V_9 , V_79 ) ;
}
}
F_25 ( V_22 , & V_9 -> V_25 ) ;
}
F_11 ( & V_20 , V_16 ) ;
break;
}
return V_80 ;
}
static int T_9
F_50 ( void )
{
struct V_81 * V_82 ;
struct V_81 * * V_83 = V_84 ;
struct V_81 * V_85 , * V_86 ;
struct V_8 * V_9 ;
int V_17 , V_79 ;
V_82 = F_51 ( L_5 , NULL ) ;
if ( ! V_82 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_87 ; V_17 ++ ) {
* V_83 ++ = F_52 ( V_88 [ V_17 ] . V_89 , 0 , V_82 ,
& V_90 ,
( void * ) V_88 [ V_17 ] . V_91 ) ;
}
F_53 () ;
for ( V_17 = 0 ; V_17 < F_4 ( V_19 ) ; V_17 ++ ) {
V_9 = V_8 + V_17 ;
V_9 -> type = V_17 ;
F_54 ( & V_9 -> V_26 ) ;
V_85 = F_51 ( V_19 [ V_17 ] , V_82 ) ;
if ( ! V_85 )
continue;
V_86 = F_52 ( L_6 , V_92 , V_85 ,
& V_93 , V_9 ) ;
if ( ! V_86 )
continue;
* V_83 ++ = V_86 ;
V_86 = F_52 ( L_7 , V_92 | V_94 , V_85 ,
& V_95 , V_9 ) ;
if ( ! V_86 )
continue;
* V_83 ++ = V_86 ;
F_55 (j)
F_9 ( V_79 , & V_9 -> V_25 ) ;
* V_83 ++ = V_85 ;
}
* V_83 ++ = V_82 ;
F_56 ( & V_31 ) ;
V_31 . V_32 = V_33 + V_34 ;
V_31 . V_96 = & F_14 ;
F_16 ( & V_31 ) ;
F_57 ( & V_97 ) ;
F_58 () ;
return 0 ;
}
static int F_59 ( struct V_98 * V_99 , void * V_100 )
{
unsigned long V_9 = ( unsigned long ) V_100 ;
F_60 ( V_99 , ( V_101 & V_9 ) ? L_8 : L_9 ) ;
return 0 ;
}
static int F_61 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_62 ( V_36 , F_59 , F_20 ( V_35 ) ) ;
}
