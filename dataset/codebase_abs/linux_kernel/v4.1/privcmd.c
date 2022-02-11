static long F_1 ( void T_1 * V_1 )
{
struct V_2 V_3 ;
long V_4 ;
if ( F_2 ( & V_3 , V_1 , sizeof( V_3 ) ) )
return - V_5 ;
F_3 () ;
V_4 = F_4 ( V_3 . V_6 ,
V_3 . V_7 [ 0 ] , V_3 . V_7 [ 1 ] ,
V_3 . V_7 [ 2 ] , V_3 . V_7 [ 3 ] ,
V_3 . V_7 [ 4 ] ) ;
F_5 () ;
return V_4 ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 , * V_12 ;
F_7 (p, n, pages, lru)
F_8 ( V_11 ) ;
F_9 ( V_9 ) ;
}
static int F_10 ( struct V_8 * V_13 ,
unsigned V_14 , T_2 V_15 ,
const void T_1 * V_16 )
{
unsigned V_17 ;
void * V_18 ;
int V_4 ;
if ( V_15 > V_19 )
return 0 ;
V_17 = V_19 ;
V_18 = NULL ;
while ( V_14 -- ) {
if ( V_17 > V_19 - V_15 ) {
struct V_10 * V_10 = F_11 ( V_20 ) ;
V_4 = - V_21 ;
if ( V_10 == NULL )
goto V_22;
V_18 = F_12 ( V_10 ) ;
F_13 ( & V_10 -> V_23 , V_13 ) ;
V_17 = 0 ;
}
V_4 = - V_5 ;
if ( F_2 ( V_18 + V_17 , V_16 , V_15 ) )
goto V_22;
V_16 += V_15 ;
V_17 += V_15 ;
}
V_4 = 0 ;
V_22:
return V_4 ;
}
static int F_14 ( unsigned V_14 , T_2 V_15 ,
struct V_8 * V_24 ,
int (* F_15)( void * V_16 , void * V_25 ) ,
void * V_25 )
{
void * V_18 ;
unsigned V_17 ;
int V_4 = 0 ;
F_16 ( V_15 > V_19 ) ;
V_17 = V_19 ;
V_18 = NULL ;
while ( V_14 -- ) {
if ( V_17 > V_19 - V_15 ) {
struct V_10 * V_10 ;
V_24 = V_24 -> V_26 ;
V_10 = F_17 ( V_24 , struct V_10 , V_23 ) ;
V_18 = F_12 ( V_10 ) ;
V_17 = 0 ;
}
V_4 = (* F_15)( V_18 + V_17 , V_25 ) ;
if ( V_4 )
break;
V_17 += V_15 ;
}
return V_4 ;
}
static int F_18 ( unsigned V_14 , T_2 V_15 ,
struct V_8 * V_24 ,
int (* F_15)( void * V_16 , int V_27 , void * V_25 ) ,
void * V_25 )
{
void * V_18 ;
unsigned V_17 ;
int V_4 = 0 ;
F_16 ( V_15 > V_19 ) ;
V_17 = V_19 ;
while ( V_14 ) {
int V_27 = ( V_19 / V_15 ) ;
struct V_10 * V_10 ;
if ( V_27 > V_14 )
V_27 = V_14 ;
V_24 = V_24 -> V_26 ;
V_10 = F_17 ( V_24 , struct V_10 , V_23 ) ;
V_18 = F_12 ( V_10 ) ;
V_4 = (* F_15)( V_18 , V_27 , V_25 ) ;
if ( V_4 )
break;
V_14 -= V_27 ;
}
return V_4 ;
}
static int F_19 ( void * V_16 , void * V_25 )
{
struct V_28 * V_29 = V_16 ;
struct V_30 * V_31 = V_25 ;
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 ;
if ( ( V_29 -> V_35 > ( V_36 >> V_37 ) ) ||
( ( unsigned long ) ( V_29 -> V_35 << V_37 ) >= - V_31 -> V_38 ) )
return - V_39 ;
if ( ( V_29 -> V_38 != V_31 -> V_38 ) ||
( ( V_29 -> V_38 + ( V_29 -> V_35 << V_37 ) ) > V_33 -> V_40 ) )
return - V_39 ;
V_34 = F_20 ( V_33 ,
V_29 -> V_38 & V_41 ,
V_29 -> V_42 , V_29 -> V_35 ,
V_33 -> V_43 ,
V_31 -> V_44 , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
V_31 -> V_38 += V_29 -> V_35 << V_37 ;
return 0 ;
}
static long F_21 ( void T_1 * V_1 )
{
struct V_45 V_46 ;
struct V_47 * V_48 = V_49 -> V_48 ;
struct V_32 * V_33 ;
int V_34 ;
F_22 ( V_13 ) ;
struct V_30 V_25 ;
if ( F_23 ( V_50 ) )
return - V_51 ;
if ( F_2 ( & V_46 , V_1 , sizeof( V_46 ) ) )
return - V_5 ;
V_34 = F_10 ( & V_13 ,
V_46 . V_52 , sizeof( struct V_28 ) ,
V_46 . V_53 ) ;
if ( V_34 || F_24 ( & V_13 ) )
goto V_54;
F_25 ( & V_48 -> V_55 ) ;
{
struct V_10 * V_10 = F_26 ( & V_13 ,
struct V_10 , V_23 ) ;
struct V_28 * V_29 = F_12 ( V_10 ) ;
V_33 = F_27 ( V_48 , V_29 -> V_38 ) ;
V_34 = - V_39 ;
if ( ! V_33 || ( V_29 -> V_38 != V_33 -> V_56 ) || V_33 -> V_57 )
goto V_58;
V_33 -> V_57 = V_59 ;
}
V_25 . V_38 = V_33 -> V_56 ;
V_25 . V_33 = V_33 ;
V_25 . V_44 = V_46 . V_60 ;
V_34 = F_14 ( V_46 . V_52 , sizeof( struct V_28 ) ,
& V_13 ,
F_19 , & V_25 ) ;
V_58:
F_28 ( & V_48 -> V_55 ) ;
V_54:
F_6 ( & V_13 ) ;
return V_34 ;
}
static int F_29 ( void * V_16 , int V_27 , void * V_25 )
{
T_3 * V_61 = V_16 ;
struct V_62 * V_31 = V_25 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_10 * * V_9 = V_33 -> V_57 ;
struct V_10 * * V_63 = NULL ;
int V_4 ;
if ( F_23 ( V_50 ) )
V_63 = & V_9 [ V_31 -> V_64 ] ;
F_16 ( V_27 < 0 ) ;
V_4 = F_30 ( V_31 -> V_33 , V_31 -> V_38 & V_41 , V_61 , V_27 ,
( int * ) V_61 , V_31 -> V_33 -> V_43 ,
V_31 -> V_44 , V_63 ) ;
if ( V_4 != V_27 ) {
if ( V_4 == - V_65 )
V_31 -> V_66 = - V_65 ;
else {
if ( V_31 -> V_66 == 0 )
V_31 -> V_66 = 1 ;
}
}
V_31 -> V_38 += V_19 * V_27 ;
V_31 -> V_64 += V_27 ;
return 0 ;
}
static int F_31 ( int V_67 , struct V_62 * V_31 )
{
int V_4 ;
if ( V_31 -> V_68 == 1 ) {
if ( V_67 ) {
T_3 V_42 ;
V_4 = F_32 ( V_42 , V_31 -> V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
V_42 |= ( V_67 == - V_65 ) ?
V_70 :
V_71 ;
return F_33 ( V_42 , V_31 -> V_69 ++ ) ;
} else
V_31 -> V_69 ++ ;
} else {
if ( V_67 )
return F_33 ( V_67 , V_31 -> V_72 ++ ) ;
else
V_31 -> V_72 ++ ;
}
return 0 ;
}
static int F_34 ( void * V_16 , int V_27 , void * V_25 )
{
struct V_62 * V_31 = V_25 ;
int * V_73 = V_16 ;
int V_74 ;
int V_4 ;
for ( V_74 = 0 ; V_74 < V_27 ; V_74 ++ ) {
V_4 = F_31 ( V_73 [ V_74 ] , V_31 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_35 ( struct V_32 * V_33 , int V_75 )
{
int V_34 ;
struct V_10 * * V_9 ;
V_9 = F_36 ( V_75 , sizeof( V_9 [ 0 ] ) , V_20 ) ;
if ( V_9 == NULL )
return - V_21 ;
V_34 = F_37 ( V_75 , V_9 , 0 ) ;
if ( V_34 != 0 ) {
F_38 ( L_1 , V_76 ,
V_75 , V_34 ) ;
F_39 ( V_9 ) ;
return - V_21 ;
}
F_16 ( V_33 -> V_57 != NULL ) ;
V_33 -> V_57 = V_9 ;
return 0 ;
}
static long F_40 ( void T_1 * V_1 , int V_68 )
{
int V_4 ;
struct V_77 V_78 ;
struct V_47 * V_48 = V_49 -> V_48 ;
struct V_32 * V_33 ;
unsigned long V_79 ;
F_22 ( V_13 ) ;
struct V_62 V_25 ;
switch ( V_68 ) {
case 1 :
if ( F_2 ( & V_78 , V_1 , sizeof( struct V_80 ) ) )
return - V_5 ;
V_78 . V_67 = NULL ;
if ( ! F_41 ( V_81 , V_78 . V_82 , V_78 . V_52 * sizeof( * V_78 . V_82 ) ) )
return - V_5 ;
break;
case 2 :
if ( F_2 ( & V_78 , V_1 , sizeof( struct V_77 ) ) )
return - V_5 ;
if ( ! F_41 ( V_81 , V_78 . V_67 , V_78 . V_52 * ( sizeof( * V_78 . V_67 ) ) ) )
return - V_5 ;
break;
default:
return - V_39 ;
}
V_79 = V_78 . V_52 ;
if ( ( V_78 . V_52 <= 0 ) || ( V_79 > ( V_36 >> V_37 ) ) )
return - V_39 ;
V_4 = F_10 ( & V_13 , V_78 . V_52 , sizeof( T_3 ) , V_78 . V_82 ) ;
if ( V_4 )
goto V_54;
if ( F_24 ( & V_13 ) ) {
V_4 = - V_39 ;
goto V_54;
}
if ( V_68 == 2 ) {
if ( F_42 ( V_78 . V_67 , sizeof( int ) * V_78 . V_52 ) ) {
V_4 = - V_5 ;
goto V_54;
}
}
F_25 ( & V_48 -> V_55 ) ;
V_33 = F_27 ( V_48 , V_78 . V_83 ) ;
if ( ! V_33 ||
V_33 -> V_84 != & V_85 ) {
V_4 = - V_39 ;
goto V_86;
}
if ( V_33 -> V_57 == NULL ) {
if ( V_78 . V_83 != V_33 -> V_56 ||
V_78 . V_83 + ( V_79 << V_37 ) != V_33 -> V_40 ) {
V_4 = - V_39 ;
goto V_86;
}
if ( F_23 ( V_50 ) ) {
V_4 = F_35 ( V_33 , V_78 . V_52 ) ;
if ( V_4 < 0 )
goto V_86;
} else
V_33 -> V_57 = V_59 ;
} else {
if ( V_78 . V_83 < V_33 -> V_56 ||
V_78 . V_83 + ( V_79 << V_37 ) > V_33 -> V_40 ) {
V_4 = - V_39 ;
goto V_86;
}
if ( F_43 ( V_33 , V_78 . V_83 , V_79 ) ) {
V_4 = - V_39 ;
goto V_86;
}
}
V_25 . V_44 = V_78 . V_60 ;
V_25 . V_33 = V_33 ;
V_25 . V_38 = V_78 . V_83 ;
V_25 . V_64 = 0 ;
V_25 . V_66 = 0 ;
V_25 . V_68 = V_68 ;
F_16 ( F_18 ( V_78 . V_52 , sizeof( T_3 ) ,
& V_13 , F_29 , & V_25 ) ) ;
F_28 ( & V_48 -> V_55 ) ;
if ( V_25 . V_66 ) {
V_25 . V_69 = ( T_3 * ) V_78 . V_82 ;
V_25 . V_72 = V_78 . V_67 ;
V_4 = F_18 ( V_78 . V_52 , sizeof( T_3 ) ,
& V_13 , F_34 , & V_25 ) ;
} else
V_4 = 0 ;
if ( ( V_4 == 0 ) && ( V_25 . V_66 == - V_65 ) )
V_4 = - V_65 ;
V_54:
F_6 ( & V_13 ) ;
return V_4 ;
V_86:
F_28 ( & V_48 -> V_55 ) ;
goto V_54;
}
static long F_44 ( struct V_87 * V_87 ,
unsigned int V_88 , unsigned long V_16 )
{
int V_4 = - V_51 ;
void T_1 * V_1 = ( void T_1 * ) V_16 ;
switch ( V_88 ) {
case V_89 :
V_4 = F_1 ( V_1 ) ;
break;
case V_90 :
V_4 = F_21 ( V_1 ) ;
break;
case V_91 :
V_4 = F_40 ( V_1 , 1 ) ;
break;
case V_92 :
V_4 = F_40 ( V_1 , 2 ) ;
break;
default:
V_4 = - V_39 ;
break;
}
return V_4 ;
}
static void F_45 ( struct V_32 * V_33 )
{
struct V_10 * * V_9 = V_33 -> V_57 ;
int V_75 = ( V_33 -> V_40 - V_33 -> V_56 ) >> V_37 ;
int V_34 ;
if ( ! F_23 ( V_50 ) || ! V_75 || ! V_9 )
return;
V_34 = F_46 ( V_33 , V_75 , V_9 ) ;
if ( V_34 == 0 )
F_47 ( V_75 , V_9 ) ;
else
F_48 ( L_2 ,
V_75 , V_34 ) ;
F_39 ( V_9 ) ;
}
static int F_49 ( struct V_32 * V_33 , struct V_93 * V_94 )
{
F_50 ( V_95 L_3 ,
V_33 , V_33 -> V_56 , V_33 -> V_40 ,
V_94 -> V_96 , V_94 -> V_97 ) ;
return V_98 ;
}
static int V_45 ( struct V_87 * V_87 , struct V_32 * V_33 )
{
V_33 -> V_99 |= V_100 | V_101 | V_102 |
V_103 | V_104 ;
V_33 -> V_84 = & V_85 ;
V_33 -> V_57 = NULL ;
return 0 ;
}
static int F_51 ( T_4 * V_105 , struct V_10 * V_106 ,
unsigned long V_83 , void * V_16 )
{
return F_52 ( * V_105 ) ? 0 : - V_107 ;
}
static int F_43 (
struct V_32 * V_33 ,
unsigned long V_83 ,
unsigned long V_79 )
{
return F_53 ( V_33 -> V_108 , V_83 , V_79 << V_37 ,
F_51 , NULL ) != 0 ;
}
static int T_5 F_54 ( void )
{
int V_67 ;
if ( ! F_55 () )
return - V_109 ;
V_67 = F_56 ( & V_110 ) ;
if ( V_67 != 0 ) {
F_57 ( L_4 ) ;
return V_67 ;
}
return 0 ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_110 ) ;
}
