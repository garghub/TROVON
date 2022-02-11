static long F_1 ( void T_1 * V_1 )
{
struct V_2 V_3 ;
long V_4 ;
if ( F_2 ( & V_3 , V_1 , sizeof( V_3 ) ) )
return - V_5 ;
V_4 = F_3 ( V_3 . V_6 ,
V_3 . V_7 [ 0 ] , V_3 . V_7 [ 1 ] ,
V_3 . V_7 [ 2 ] , V_3 . V_7 [ 3 ] ,
V_3 . V_7 [ 4 ] ) ;
return V_4 ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 , * V_12 ;
F_5 (p, n, pages, lru)
F_6 ( V_11 ) ;
F_7 ( V_9 ) ;
}
static int F_8 ( struct V_8 * V_13 ,
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
struct V_10 * V_10 = F_9 ( V_20 ) ;
V_4 = - V_21 ;
if ( V_10 == NULL )
goto V_22;
V_18 = F_10 ( V_10 ) ;
F_11 ( & V_10 -> V_23 , V_13 ) ;
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
static int F_12 ( unsigned V_14 , T_2 V_15 ,
struct V_8 * V_24 ,
int (* F_13)( void * V_16 , void * V_25 ) ,
void * V_25 )
{
void * V_18 ;
unsigned V_17 ;
int V_4 = 0 ;
F_14 ( V_15 > V_19 ) ;
V_17 = V_19 ;
V_18 = NULL ;
while ( V_14 -- ) {
if ( V_17 > V_19 - V_15 ) {
struct V_10 * V_10 ;
V_24 = V_24 -> V_26 ;
V_10 = F_15 ( V_24 , struct V_10 , V_23 ) ;
V_18 = F_10 ( V_10 ) ;
V_17 = 0 ;
}
V_4 = (* F_13)( V_18 + V_17 , V_25 ) ;
if ( V_4 )
break;
V_17 += V_15 ;
}
return V_4 ;
}
static int F_16 ( void * V_16 , void * V_25 )
{
struct V_27 * V_28 = V_16 ;
struct V_29 * V_30 = V_25 ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_33 ;
if ( ( V_28 -> V_34 > ( V_35 >> V_36 ) ) ||
( ( unsigned long ) ( V_28 -> V_34 << V_36 ) >= - V_30 -> V_37 ) )
return - V_38 ;
if ( ( V_28 -> V_37 != V_30 -> V_37 ) ||
( ( V_28 -> V_37 + ( V_28 -> V_34 << V_36 ) ) > V_32 -> V_39 ) )
return - V_38 ;
V_33 = F_17 ( V_32 ,
V_28 -> V_37 & V_40 ,
V_28 -> V_41 , V_28 -> V_34 ,
V_32 -> V_42 ,
V_30 -> V_43 , NULL ) ;
if ( V_33 < 0 )
return V_33 ;
V_30 -> V_37 += V_28 -> V_34 << V_36 ;
return 0 ;
}
static long F_18 ( void T_1 * V_1 )
{
struct V_44 V_45 ;
struct V_46 * V_47 = V_48 -> V_47 ;
struct V_31 * V_32 ;
int V_33 ;
F_19 ( V_13 ) ;
struct V_29 V_25 ;
if ( F_20 ( V_49 ) )
return - V_50 ;
if ( F_2 ( & V_45 , V_1 , sizeof( V_45 ) ) )
return - V_5 ;
V_33 = F_8 ( & V_13 ,
V_45 . V_51 , sizeof( struct V_27 ) ,
V_45 . V_52 ) ;
if ( V_33 || F_21 ( & V_13 ) )
goto V_53;
F_22 ( & V_47 -> V_54 ) ;
{
struct V_10 * V_10 = F_23 ( & V_13 ,
struct V_10 , V_23 ) ;
struct V_27 * V_28 = F_10 ( V_10 ) ;
V_32 = F_24 ( V_47 , V_28 -> V_37 ) ;
V_33 = - V_38 ;
if ( ! V_32 || ( V_28 -> V_37 != V_32 -> V_55 ) ||
! F_25 ( V_32 ) )
goto V_56;
}
V_25 . V_37 = V_32 -> V_55 ;
V_25 . V_32 = V_32 ;
V_25 . V_43 = V_45 . V_57 ;
V_33 = F_12 ( V_45 . V_51 , sizeof( struct V_27 ) ,
& V_13 ,
F_16 , & V_25 ) ;
V_56:
F_26 ( & V_47 -> V_54 ) ;
V_53:
F_4 ( & V_13 ) ;
return V_33 ;
}
static int F_27 ( void * V_16 , void * V_25 )
{
T_3 * V_58 = V_16 ;
struct V_59 * V_30 = V_25 ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_10 * * V_9 = V_32 -> V_60 ;
struct V_10 * V_61 = NULL ;
int V_4 ;
if ( F_20 ( V_49 ) )
V_61 = V_9 [ V_30 -> V_62 ++ ] ;
V_4 = F_17 ( V_30 -> V_32 , V_30 -> V_37 & V_40 , * V_58 , 1 ,
V_30 -> V_32 -> V_42 , V_30 -> V_43 ,
& V_61 ) ;
if ( V_30 -> V_63 == 1 ) {
if ( V_4 < 0 ) {
* V_58 |= ( V_4 == - V_64 ) ?
V_65 :
V_66 ;
}
} else {
* ( ( int * ) V_58 ) = V_4 ;
}
if ( V_4 < 0 ) {
if ( V_4 == - V_64 )
V_30 -> V_67 = - V_64 ;
else {
if ( V_30 -> V_67 == 0 )
V_30 -> V_67 = 1 ;
}
}
V_30 -> V_37 += V_19 ;
return 0 ;
}
static int F_28 ( void * V_16 , void * V_25 )
{
struct V_59 * V_30 = V_25 ;
if ( V_30 -> V_63 == 1 ) {
T_3 V_58 = * ( ( T_3 * ) V_16 ) ;
if ( V_58 & V_66 )
return F_29 ( V_58 , V_30 -> V_68 ++ ) ;
else
V_30 -> V_68 ++ ;
} else {
int V_69 = * ( ( int * ) V_16 ) ;
if ( V_69 )
return F_29 ( V_69 , V_30 -> V_70 ++ ) ;
else
V_30 -> V_70 ++ ;
}
return 0 ;
}
static int F_30 ( struct V_31 * V_32 , int V_71 )
{
int V_33 ;
struct V_10 * * V_9 ;
V_9 = F_31 ( V_71 , sizeof( V_9 [ 0 ] ) , V_20 ) ;
if ( V_9 == NULL )
return - V_21 ;
V_33 = F_32 ( V_71 , V_9 , 0 ) ;
if ( V_33 != 0 ) {
F_33 ( L_1 , V_72 ,
V_71 , V_33 ) ;
F_34 ( V_9 ) ;
return - V_21 ;
}
F_14 ( V_32 -> V_60 != V_73 ) ;
V_32 -> V_60 = V_9 ;
return 0 ;
}
static long F_35 ( void T_1 * V_1 , int V_63 )
{
int V_4 ;
struct V_74 V_75 ;
struct V_46 * V_47 = V_48 -> V_47 ;
struct V_31 * V_32 ;
unsigned long V_76 ;
F_19 ( V_13 ) ;
struct V_59 V_25 ;
switch ( V_63 ) {
case 1 :
if ( F_2 ( & V_75 , V_1 , sizeof( struct V_77 ) ) )
return - V_5 ;
V_75 . V_69 = NULL ;
if ( ! F_36 ( V_78 , V_75 . V_79 , V_75 . V_51 * sizeof( * V_75 . V_79 ) ) )
return - V_5 ;
break;
case 2 :
if ( F_2 ( & V_75 , V_1 , sizeof( struct V_74 ) ) )
return - V_5 ;
if ( ! F_36 ( V_78 , V_75 . V_69 , V_75 . V_51 * ( sizeof( * V_75 . V_69 ) ) ) )
return - V_5 ;
break;
default:
return - V_38 ;
}
V_76 = V_75 . V_51 ;
if ( ( V_75 . V_51 <= 0 ) || ( V_76 > ( V_35 >> V_36 ) ) )
return - V_38 ;
V_4 = F_8 ( & V_13 , V_75 . V_51 , sizeof( T_3 ) , V_75 . V_79 ) ;
if ( V_4 )
goto V_53;
if ( F_21 ( & V_13 ) ) {
V_4 = - V_38 ;
goto V_53;
}
if ( V_63 == 2 ) {
if ( F_37 ( V_75 . V_69 , sizeof( int ) * V_75 . V_51 ) ) {
V_4 = - V_5 ;
goto V_53;
}
}
F_22 ( & V_47 -> V_54 ) ;
V_32 = F_24 ( V_47 , V_75 . V_80 ) ;
if ( ! V_32 ||
V_32 -> V_81 != & V_82 ||
( V_75 . V_80 != V_32 -> V_55 ) ||
( ( V_75 . V_80 + ( V_76 << V_36 ) ) != V_32 -> V_39 ) ||
! F_25 ( V_32 ) ) {
F_26 ( & V_47 -> V_54 ) ;
V_4 = - V_38 ;
goto V_53;
}
if ( F_20 ( V_49 ) ) {
V_4 = F_30 ( V_32 , V_75 . V_51 ) ;
if ( V_4 < 0 ) {
F_26 ( & V_47 -> V_54 ) ;
goto V_53;
}
}
V_25 . V_43 = V_75 . V_57 ;
V_25 . V_32 = V_32 ;
V_25 . V_37 = V_75 . V_80 ;
V_25 . V_62 = 0 ;
V_25 . V_67 = 0 ;
V_25 . V_63 = V_63 ;
F_14 ( F_12 ( V_75 . V_51 , sizeof( T_3 ) ,
& V_13 , F_27 , & V_25 ) ) ;
F_26 ( & V_47 -> V_54 ) ;
if ( V_25 . V_67 ) {
V_25 . V_68 = ( T_3 * ) V_75 . V_79 ;
V_25 . V_70 = V_75 . V_69 ;
V_4 = F_12 ( V_75 . V_51 , sizeof( T_3 ) ,
& V_13 , F_28 , & V_25 ) ;
} else
V_4 = 0 ;
if ( ( V_4 == 0 ) && ( V_25 . V_67 == - V_64 ) )
V_4 = - V_64 ;
V_53:
F_4 ( & V_13 ) ;
return V_4 ;
}
static long F_38 ( struct V_83 * V_83 ,
unsigned int V_84 , unsigned long V_16 )
{
int V_4 = - V_50 ;
void T_1 * V_1 = ( void T_1 * ) V_16 ;
switch ( V_84 ) {
case V_85 :
V_4 = F_1 ( V_1 ) ;
break;
case V_86 :
V_4 = F_18 ( V_1 ) ;
break;
case V_87 :
V_4 = F_35 ( V_1 , 1 ) ;
break;
case V_88 :
V_4 = F_35 ( V_1 , 2 ) ;
break;
default:
V_4 = - V_38 ;
break;
}
return V_4 ;
}
static void F_39 ( struct V_31 * V_32 )
{
struct V_10 * * V_9 = V_32 -> V_60 ;
int V_71 = ( V_32 -> V_39 - V_32 -> V_55 ) >> V_36 ;
if ( ! F_20 ( V_49 ) || ! V_71 || ! V_9 )
return;
F_40 ( V_32 , V_71 , V_9 ) ;
F_41 ( V_71 , V_9 ) ;
F_34 ( V_9 ) ;
}
static int F_42 ( struct V_31 * V_32 , struct V_89 * V_90 )
{
F_43 ( V_91 L_2 ,
V_32 , V_32 -> V_55 , V_32 -> V_39 ,
V_90 -> V_92 , V_90 -> V_93 ) ;
return V_94 ;
}
static int V_44 ( struct V_83 * V_83 , struct V_31 * V_32 )
{
V_32 -> V_95 |= V_96 | V_97 | V_98 |
V_99 | V_100 ;
V_32 -> V_81 = & V_82 ;
V_32 -> V_60 = NULL ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
return ! F_44 ( & V_32 -> V_60 , NULL , V_73 ) ;
}
static int T_4 F_45 ( void )
{
int V_69 ;
if ( ! F_46 () )
return - V_101 ;
V_69 = F_47 ( & V_102 ) ;
if ( V_69 != 0 ) {
F_48 ( L_3 ) ;
return V_69 ;
}
return 0 ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_102 ) ;
}
