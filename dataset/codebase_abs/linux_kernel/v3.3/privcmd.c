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
void T_1 * V_16 )
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
V_30 -> V_43 ) ;
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
if ( ! F_20 () )
return - V_49 ;
if ( F_2 ( & V_45 , V_1 , sizeof( V_45 ) ) )
return - V_5 ;
V_33 = F_8 ( & V_13 ,
V_45 . V_50 , sizeof( struct V_27 ) ,
V_45 . V_51 ) ;
if ( V_33 || F_21 ( & V_13 ) )
goto V_52;
F_22 ( & V_47 -> V_53 ) ;
{
struct V_10 * V_10 = F_23 ( & V_13 ,
struct V_10 , V_23 ) ;
struct V_27 * V_28 = F_10 ( V_10 ) ;
V_32 = F_24 ( V_47 , V_28 -> V_37 ) ;
V_33 = - V_38 ;
if ( ! V_32 || ( V_28 -> V_37 != V_32 -> V_54 ) ||
! F_25 ( V_32 ) )
goto V_55;
}
V_25 . V_37 = V_32 -> V_54 ;
V_25 . V_32 = V_32 ;
V_25 . V_43 = V_45 . V_56 ;
V_33 = F_12 ( V_45 . V_50 , sizeof( struct V_27 ) ,
& V_13 ,
F_16 , & V_25 ) ;
V_55:
F_26 ( & V_47 -> V_53 ) ;
V_52:
F_4 ( & V_13 ) ;
return V_33 ;
}
static int F_27 ( void * V_16 , void * V_25 )
{
T_3 * V_57 = V_16 ;
struct V_58 * V_30 = V_25 ;
if ( F_17 ( V_30 -> V_32 , V_30 -> V_37 & V_40 , * V_57 , 1 ,
V_30 -> V_32 -> V_42 , V_30 -> V_43 ) < 0 ) {
* V_57 |= 0xf0000000U ;
V_30 -> V_59 ++ ;
}
V_30 -> V_37 += V_19 ;
return 0 ;
}
static int F_28 ( void * V_16 , void * V_25 )
{
T_3 * V_57 = V_16 ;
struct V_58 * V_30 = V_25 ;
return F_29 ( * V_57 , V_30 -> V_60 ++ ) ;
}
static long F_30 ( void T_1 * V_1 )
{
int V_4 ;
struct V_61 V_62 ;
struct V_46 * V_47 = V_48 -> V_47 ;
struct V_31 * V_32 ;
unsigned long V_63 ;
F_19 ( V_13 ) ;
struct V_58 V_25 ;
if ( ! F_20 () )
return - V_49 ;
if ( F_2 ( & V_62 , V_1 , sizeof( V_62 ) ) )
return - V_5 ;
V_63 = V_62 . V_50 ;
if ( ( V_62 . V_50 <= 0 ) || ( V_63 > ( V_35 >> V_36 ) ) )
return - V_38 ;
V_4 = F_8 ( & V_13 , V_62 . V_50 , sizeof( T_3 ) ,
V_62 . V_64 ) ;
if ( V_4 || F_21 ( & V_13 ) )
goto V_52;
F_22 ( & V_47 -> V_53 ) ;
V_32 = F_24 ( V_47 , V_62 . V_65 ) ;
V_4 = - V_38 ;
if ( ! V_32 ||
V_32 -> V_66 != & V_67 ||
( V_62 . V_65 != V_32 -> V_54 ) ||
( ( V_62 . V_65 + ( V_63 << V_36 ) ) != V_32 -> V_39 ) ||
! F_25 ( V_32 ) ) {
F_26 ( & V_47 -> V_53 ) ;
goto V_52;
}
V_25 . V_43 = V_62 . V_56 ;
V_25 . V_32 = V_32 ;
V_25 . V_37 = V_62 . V_65 ;
V_25 . V_59 = 0 ;
V_4 = F_12 ( V_62 . V_50 , sizeof( T_3 ) ,
& V_13 , F_27 , & V_25 ) ;
F_26 ( & V_47 -> V_53 ) ;
if ( V_25 . V_59 > 0 ) {
V_25 . V_60 = V_62 . V_64 ;
V_4 = F_12 ( V_62 . V_50 , sizeof( T_3 ) ,
& V_13 ,
F_28 , & V_25 ) ;
}
V_52:
F_4 ( & V_13 ) ;
return V_4 ;
}
static long F_31 ( struct V_68 * V_68 ,
unsigned int V_69 , unsigned long V_16 )
{
int V_4 = - V_70 ;
void T_1 * V_1 = ( void T_1 * ) V_16 ;
switch ( V_69 ) {
case V_71 :
V_4 = F_1 ( V_1 ) ;
break;
case V_72 :
V_4 = F_18 ( V_1 ) ;
break;
case V_73 :
V_4 = F_30 ( V_1 ) ;
break;
default:
V_4 = - V_38 ;
break;
}
return V_4 ;
}
static int F_32 ( struct V_31 * V_32 , struct V_74 * V_75 )
{
F_33 ( V_76 L_1 ,
V_32 , V_32 -> V_54 , V_32 -> V_39 ,
V_75 -> V_77 , V_75 -> V_78 ) ;
return V_79 ;
}
static int V_44 ( struct V_68 * V_68 , struct V_31 * V_32 )
{
if ( F_34 ( V_80 ) )
return - V_70 ;
V_32 -> V_81 |= V_82 | V_83 | V_84 | V_85 ;
V_32 -> V_66 = & V_67 ;
V_32 -> V_86 = NULL ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
return ( F_35 ( & V_32 -> V_86 , ( void * ) 1 ) == NULL ) ;
}
static int T_4 F_36 ( void )
{
int V_59 ;
if ( ! F_37 () )
return - V_87 ;
V_59 = F_38 ( & V_88 ) ;
if ( V_59 != 0 ) {
F_33 ( V_89 L_2 ) ;
return V_59 ;
}
return 0 ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_88 ) ;
}
