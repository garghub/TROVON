static long
F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
return F_2 ( V_3 -> V_4 , V_3 -> V_5 , V_3 -> V_6 ) ;
}
static void
F_3 ( struct V_7 * V_8 , int V_9 )
{
memcpy ( V_8 -> V_10 + V_9 , V_8 -> V_10 + V_9 + 1 ,
( F_4 ( V_8 -> V_10 ) - ( V_9 + 1 ) ) * sizeof( V_8 -> V_10 [ 0 ] ) ) ;
memset ( V_8 -> V_10 + F_4 ( V_8 -> V_10 ) - 1 , 0 ,
sizeof( V_8 -> V_10 [ 0 ] ) ) ;
}
void
F_5 ( int type , T_1 * V_11 , T_2 V_12 , int V_13 )
{
struct V_7 * V_8 = V_7 + type ;
struct V_14 * V_10 ;
unsigned long V_15 = 0 ;
int V_16 ;
int V_17 = F_4 ( V_8 -> V_10 ) ;
F_6 ( type >= F_4 ( V_18 ) ) ;
if ( V_13 )
F_7 ( & V_19 , V_15 ) ;
if ( V_11 ) {
for ( V_16 = 0 , V_10 = V_8 -> V_10 ; V_16 < V_17 ; ++ V_16 , ++ V_10 ) {
if ( ! V_10 -> V_11 )
break;
}
if ( V_16 == V_17 ) {
if ( ! V_8 -> V_20 ) {
F_3 ( V_8 , 0 ) ;
V_10 = V_8 -> V_10 + V_17 - 1 ;
} else
V_10 = NULL ;
}
if ( V_10 ) {
V_10 -> V_21 = F_8 () ;
V_10 -> V_22 = ( ( V_23 * ) V_11 ) -> V_22 ;
V_10 -> V_12 = V_12 ;
V_10 -> V_11 = V_11 ;
}
}
F_9 ( F_8 () , & V_8 -> V_24 ) ;
if ( V_13 ) {
F_10 ( & V_8 -> V_25 ) ;
F_11 ( & V_19 , V_15 ) ;
}
}
static void
F_12 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_26 )
return;
if ( ! F_13 ( & V_8 -> V_24 ) )
F_10 ( & V_8 -> V_25 ) ;
}
static void
F_14 ( unsigned long V_27 )
{
F_15 () ;
F_12 ( V_7 + V_28 ) ;
F_12 ( V_7 + V_29 ) ;
V_30 . V_31 = V_32 + V_33 ;
F_16 ( & V_30 ) ;
}
static int
F_17 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
if ( ! F_18 ( V_36 ) )
return - V_37 ;
return 0 ;
}
static T_3
F_19 ( struct V_35 * V_35 , char T_4 * V_11 , T_5 V_38 , T_6 * V_39 )
{
struct V_7 * V_8 = F_20 ( F_21 ( V_35 ) ) ;
char V_40 [ 32 ] ;
T_5 V_12 ;
int V_16 , V_41 , V_21 = - 1 ;
V_42:
if ( F_13 ( & V_8 -> V_24 ) ) {
if ( V_35 -> V_43 & V_44 )
return - V_45 ;
if ( F_22 ( V_8 -> V_25 ,
! F_13 ( & V_8 -> V_24 ) ) )
return - V_46 ;
}
V_41 = V_8 -> V_47 ;
for ( V_16 = 0 ; V_16 < V_48 ; V_16 ++ ) {
if ( F_23 ( V_41 , & V_8 -> V_24 ) ) {
if ( ! F_24 ( V_41 ) ) {
F_25 ( V_41 , & V_8 -> V_24 ) ;
continue;
}
V_21 = V_41 ;
break;
}
if ( ++ V_41 == V_48 )
V_41 = 0 ;
}
if ( V_21 == - 1 )
goto V_42;
F_15 () ;
V_8 -> V_47 = V_21 ;
if ( ++ V_8 -> V_47 == V_48 )
V_8 -> V_47 = 0 ;
snprintf ( V_40 , sizeof( V_40 ) , L_1 , V_21 ) ;
V_12 = strlen ( V_40 ) ;
if ( V_12 > V_38 )
V_12 = V_38 ;
if ( F_26 ( V_11 , V_40 , V_12 ) )
return - V_49 ;
return V_12 ;
}
static int
F_27 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
struct V_7 * V_8 = F_20 ( V_34 ) ;
if ( ! F_18 ( V_36 ) )
return - V_37 ;
F_28 ( & V_50 ) ;
if ( V_8 -> V_26 ) {
F_29 ( & V_50 ) ;
return - V_51 ;
}
V_8 -> V_26 = 1 ;
F_29 ( & V_50 ) ;
if ( V_8 -> V_52 == V_53 &&
! ( V_8 -> V_54 = F_30 ( F_31 ( V_8 -> type ) ) ) ) {
V_8 -> V_26 = 0 ;
return - V_55 ;
}
return 0 ;
}
static int
F_32 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
struct V_7 * V_8 = F_20 ( V_34 ) ;
if ( V_8 -> V_52 == V_53 ) {
F_33 ( V_8 -> V_54 ) ;
F_33 ( V_8 -> V_5 ) ;
V_8 -> V_54 = NULL ;
V_8 -> V_5 = NULL ;
}
F_28 ( & V_50 ) ;
V_8 -> V_26 = 0 ;
F_29 ( & V_50 ) ;
return 0 ;
}
static long
F_34 ( void * V_1 )
{
struct V_7 * V_8 = V_1 ;
V_23 * V_56 ;
V_8 -> V_57 = F_35 ( V_8 -> type , ( T_2 * ) V_8 -> V_54 ) ;
V_56 = ( V_23 * ) ( V_8 -> V_54 ) ;
if ( V_56 -> V_58 == V_59 )
F_36 ( V_8 -> type ) ;
return 0 ;
}
static void
F_37 ( int V_21 , struct V_7 * V_8 )
{
struct V_14 * V_10 ;
unsigned long V_15 ;
int V_16 ;
int V_17 = F_4 ( V_8 -> V_10 ) ;
V_8 -> V_20 = 0 ;
F_7 ( & V_19 , V_15 ) ;
V_42:
for ( V_16 = 0 , V_10 = V_8 -> V_10 ; V_16 < V_17 ; ++ V_16 , ++ V_10 ) {
if ( V_10 -> V_11 && V_10 -> V_21 == V_21 ) {
V_23 * V_56 = ( V_23 * ) ( V_10 -> V_11 ) ;
V_8 -> V_57 = V_10 -> V_12 ;
memcpy ( V_8 -> V_54 , V_56 , V_8 -> V_57 ) ;
F_38 () ;
if ( V_56 -> V_22 == V_10 -> V_22 ) {
V_8 -> V_20 = V_16 + 1 ;
break;
}
F_3 ( V_8 , V_16 ) ;
goto V_42;
}
}
F_11 ( & V_19 , V_15 ) ;
if ( ! V_8 -> V_20 )
F_39 ( V_21 , F_34 , V_8 ) ;
if ( ! V_8 -> V_57 ) {
V_8 -> V_52 = V_53 ;
F_25 ( V_21 , & V_8 -> V_24 ) ;
} else {
V_8 -> V_52 = V_60 ;
}
}
static T_3
F_40 ( struct V_35 * V_35 , char T_4 * V_11 , T_5 V_38 , T_6 * V_39 )
{
struct V_7 * V_8 = F_20 ( F_21 ( V_35 ) ) ;
T_1 * V_61 ;
T_2 V_62 ;
if ( V_8 -> V_52 == V_60 ) {
V_61 = V_8 -> V_54 ;
V_62 = V_8 -> V_57 ;
} else if ( V_8 -> V_52 == V_63 ) {
V_61 = V_8 -> V_5 ;
V_62 = V_8 -> V_6 ;
} else {
V_61 = NULL ;
V_62 = 0 ;
}
return F_41 ( V_11 , V_38 , V_39 , V_61 , V_62 ) ;
}
static long
F_42 ( void * V_1 )
{
struct V_7 * V_8 = V_1 ;
F_36 ( V_8 -> type ) ;
return 0 ;
}
static int
F_43 ( struct V_7 * V_8 , int V_21 )
{
V_23 * V_56 ;
unsigned long V_15 ;
F_7 ( & V_19 , V_15 ) ;
V_8 -> V_52 = V_53 ;
if ( ! F_23 ( V_21 , & V_8 -> V_24 ) ) {
F_11 ( & V_19 , V_15 ) ;
return 0 ;
}
F_25 ( V_21 , & V_8 -> V_24 ) ;
if ( V_8 -> V_20 ) {
F_3 ( V_8 , V_8 -> V_20 - 1 ) ;
V_8 -> V_20 = 0 ;
}
F_11 ( & V_19 , V_15 ) ;
V_56 = ( V_23 * ) ( V_8 -> V_54 ) ;
if ( V_56 -> V_58 != V_59 )
F_39 ( V_21 , F_42 , V_8 ) ;
F_37 ( V_21 , V_8 ) ;
if ( V_8 -> V_52 == V_60 ) {
F_7 ( & V_19 , V_15 ) ;
F_9 ( V_21 , & V_8 -> V_24 ) ;
F_10 ( & V_8 -> V_25 ) ;
F_11 ( & V_19 , V_15 ) ;
}
return 0 ;
}
static T_3
F_44 ( struct V_35 * V_35 , const char T_4 * V_11 , T_5 V_38 , T_6 * V_39 )
{
struct V_7 * V_8 = F_20 ( F_21 ( V_35 ) ) ;
char V_40 [ 32 ] ;
T_5 V_12 ;
T_7 V_64 ;
int V_21 ;
V_12 = sizeof( V_40 ) ;
if ( V_38 < V_12 )
V_12 = V_38 ;
if ( F_45 ( V_40 , V_11 , V_12 ) )
return - V_49 ;
if ( sscanf ( V_40 , L_2 , & V_21 ) == 1 ) {
F_37 ( V_21 , V_8 ) ;
} else if ( sscanf ( V_40 , L_3 , & V_21 ) == 1 ) {
int V_65 ;
if ( ( V_65 = F_43 ( V_8 , V_21 ) ) )
V_38 = V_65 ;
} else if ( sscanf ( V_40 , L_4 , & V_21 , & V_64 ) == 2 ) {
if ( V_8 -> V_52 != V_60 && V_8 -> V_52 != V_63 )
return - V_66 ;
if ( V_64 > V_8 -> V_57 - sizeof( V_67 ) )
return - V_66 ;
V_8 -> V_52 = V_63 ;
if ( F_2 ) {
struct V_2 V_3 = {
. V_4 = V_8 -> V_54 + V_64 ,
. V_5 = & V_8 -> V_5 ,
. V_6 = & V_8 -> V_6
} ;
V_38 = F_39 ( V_21 , F_1 ,
& V_3 ) ;
} else
V_8 -> V_6 = 0 ;
} else
return - V_66 ;
return V_38 ;
}
static int F_46 ( unsigned int V_21 )
{
unsigned int V_16 , V_68 = F_4 ( V_7 ) ;
struct V_7 * V_8 ;
F_47 ( & V_19 ) ;
for ( V_16 = 0 , V_8 = V_7 ; V_16 < V_68 ; ++ V_16 , ++ V_8 ) {
F_9 ( V_21 , & V_8 -> V_24 ) ;
F_10 ( & V_8 -> V_25 ) ;
}
F_48 ( & V_19 ) ;
return 0 ;
}
static int F_49 ( unsigned int V_21 )
{
unsigned int V_16 , V_68 = F_4 ( V_7 ) ;
struct V_7 * V_8 ;
F_47 ( & V_19 ) ;
for ( V_16 = 0 , V_8 = V_7 ; V_16 < V_68 ; ++ V_16 , ++ V_8 ) {
struct V_14 * V_10 ;
int V_69 = F_4 ( V_8 -> V_10 ) - 1 ;
for ( V_10 = V_8 -> V_10 + V_69 ; V_69 >= 0 ;
-- V_69 , -- V_10 ) {
if ( V_10 -> V_11 && V_10 -> V_21 == V_21 )
F_3 ( V_8 , V_69 ) ;
}
F_25 ( V_21 , & V_8 -> V_24 ) ;
}
F_48 ( & V_19 ) ;
return 0 ;
}
static int T_8
F_50 ( void )
{
struct V_70 * V_71 ;
struct V_70 * * V_72 = V_73 ;
struct V_70 * V_74 , * V_75 ;
struct V_7 * V_8 ;
int V_16 ;
V_71 = F_51 ( L_5 , NULL ) ;
if ( ! V_71 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_76 ; V_16 ++ ) {
* V_72 ++ = F_52 ( V_77 [ V_16 ] . V_78 , 0 , V_71 ,
& V_79 ,
( void * ) V_77 [ V_16 ] . V_80 ) ;
}
for ( V_16 = 0 ; V_16 < F_4 ( V_18 ) ; V_16 ++ ) {
V_8 = V_7 + V_16 ;
V_8 -> type = V_16 ;
F_53 ( & V_8 -> V_25 ) ;
V_74 = F_51 ( V_18 [ V_16 ] , V_71 ) ;
if ( ! V_74 )
continue;
V_75 = F_52 ( L_6 , V_81 , V_74 ,
& V_82 , V_8 ) ;
if ( ! V_75 )
continue;
* V_72 ++ = V_75 ;
V_75 = F_52 ( L_7 , V_81 | V_83 , V_74 ,
& V_84 , V_8 ) ;
if ( ! V_75 )
continue;
* V_72 ++ = V_75 ;
* V_72 ++ = V_74 ;
}
* V_72 ++ = V_71 ;
F_54 ( & V_30 ) ;
V_30 . V_31 = V_32 + V_33 ;
V_30 . V_85 = & F_14 ;
F_16 ( & V_30 ) ;
V_16 = F_55 ( V_86 , L_8 ,
F_46 , F_49 ) ;
F_56 ( V_16 < 0 ) ;
return 0 ;
}
static int F_57 ( struct V_87 * V_88 , void * V_89 )
{
unsigned long V_8 = ( unsigned long ) V_89 ;
F_58 ( V_88 , ( V_90 & V_8 ) ? L_9 : L_10 ) ;
return 0 ;
}
static int F_59 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_60 ( V_35 , F_57 , F_20 ( V_34 ) ) ;
}
