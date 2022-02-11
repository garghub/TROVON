static int F_1 ( struct V_1 T_1 * V_2 , struct V_1 * * V_3 )
{
unsigned int V_4 ;
if ( ! V_2 || ! V_3 )
return - V_5 ;
if ( F_2 ( V_4 , & V_2 -> V_6 ) )
return - V_5 ;
if ( V_4 == 0 )
return - V_7 ;
if ( V_4 > V_8 )
V_4 = V_8 ;
if ( ! ( * V_3 = F_3 ( sizeof( int ) + V_4 + 1 , V_9 ) ) )
return - V_10 ;
if ( F_4 ( & ( * V_3 ) -> V_11 ,
& V_2 -> V_11 , V_4 ) ) {
F_5 ( * V_3 ) ;
return - V_5 ;
}
return V_4 ;
}
static int F_6 ( struct V_1 T_1 * V_2 , struct V_1 * * V_3 )
{
int V_12 , V_4 ;
char V_13 ;
if ( ! V_2 || ! V_3 )
return - V_5 ;
if ( ! ( * V_3 = F_3 ( sizeof( int ) + V_8 + 1 , V_9 ) ) )
return - V_10 ;
( * V_3 ) -> V_6 = 0 ;
V_12 = V_4 = 0 ;
while ( ( V_12 < 2 ) && ( V_4 < V_8 ) ) {
if ( F_2 ( V_13 , & V_2 -> V_11 [ V_4 ] ) ) {
F_5 ( * V_3 ) ;
return - V_5 ;
}
if ( V_13 == '\0' )
V_12 ++ ;
( * V_3 ) -> V_11 [ V_4 ++ ] = V_13 ;
}
if ( ! V_12 ) {
F_5 ( * V_3 ) ;
return - V_7 ;
}
return V_4 ;
}
static int F_7 ( void T_1 * V_2 , struct V_1 * V_14 , int V_15 )
{
if ( F_8 ( V_2 , V_14 , V_15 ) )
return - V_5 ;
return 0 ;
}
static int F_9 ( void T_1 * V_16 , struct V_17 * V_18 , struct V_1 * V_19 , int V_4 )
{
const void * V_20 ;
int V_15 ;
if ( ! V_18 ||
! ( V_20 = F_10 ( V_18 , V_19 -> V_11 , & V_15 ) ) ||
V_15 <= 0 || V_15 > V_4 )
return F_7 ( V_16 , V_19 , sizeof( int ) ) ;
memcpy ( V_19 -> V_11 , V_20 , V_15 ) ;
V_19 -> V_11 [ V_15 ] = '\0' ;
V_19 -> V_6 = V_15 ;
return F_7 ( V_16 , V_19 , sizeof( int ) + V_4 ) ;
}
static int F_11 ( void T_1 * V_16 , struct V_17 * V_18 , struct V_1 * V_19 , int V_4 )
{
struct V_21 * V_22 ;
int V_15 ;
if ( ! V_18 )
return F_7 ( V_16 , V_19 , sizeof( int ) ) ;
if ( V_19 -> V_11 [ 0 ] == '\0' ) {
V_22 = V_18 -> V_23 ;
if ( ! V_22 )
return F_7 ( V_16 , V_19 , sizeof( int ) ) ;
V_15 = strlen ( V_22 -> V_24 ) ;
} else {
V_22 = F_12 ( V_18 , V_19 -> V_11 , NULL ) ;
if ( ! V_22 ||
! V_22 -> V_25 ||
( V_15 = strlen ( V_22 -> V_25 -> V_24 ) ) + 1 > V_4 )
return F_7 ( V_16 , V_19 , sizeof( int ) ) ;
V_22 = V_22 -> V_25 ;
}
memcpy ( V_19 -> V_11 , V_22 -> V_24 , V_15 ) ;
V_19 -> V_11 [ V_15 ] = '\0' ;
V_19 -> V_6 = ++ V_15 ;
return F_7 ( V_16 , V_19 , sizeof( int ) + V_4 ) ;
}
static int F_13 ( struct V_17 * V_18 , struct V_1 * V_19 , int V_4 )
{
char * V_26 = V_19 -> V_11 + strlen ( V_19 -> V_11 ) + 1 ;
int V_15 = V_19 -> V_11 + V_4 - V_26 ;
return F_14 ( V_27 , V_19 -> V_11 , V_26 , V_15 ) ;
}
static int F_15 ( void T_1 * V_16 , unsigned int V_28 , struct V_17 * V_18 , struct V_1 * V_19 , int V_4 , T_2 * V_29 )
{
T_3 V_30 ;
F_16 ( sizeof( T_3 ) != sizeof( int ) ) ;
if ( V_4 < sizeof( T_3 ) )
return - V_7 ;
V_30 = * ( ( int * ) V_19 -> V_11 ) ;
if ( V_30 ) {
V_18 = F_17 ( V_30 ) ;
if ( ! V_18 )
return - V_7 ;
switch ( V_28 ) {
case V_31 :
V_18 = V_18 -> V_32 ;
break;
case V_33 :
V_18 = V_18 -> V_34 ;
break;
case V_35 :
default:
break;
} ;
} else {
if ( V_28 != V_31 )
return - V_7 ;
V_18 = F_18 ( L_1 ) ;
}
V_30 = 0 ;
if ( V_18 )
V_30 = V_18 -> T_3 ;
V_29 -> V_36 = V_18 ;
* ( ( int * ) V_19 -> V_11 ) = V_30 ;
V_19 -> V_6 = sizeof( T_3 ) ;
return F_7 ( V_16 , V_19 , V_4 + sizeof( int ) ) ;
}
static int F_19 ( void T_1 * V_16 , struct V_17 * V_18 , struct V_1 * V_19 , int V_4 , T_2 * V_29 )
{
int V_37 = - V_7 ;
if ( V_4 >= 2 * sizeof( int ) ) {
#ifdef F_20
struct V_38 * V_39 ;
struct V_17 * V_18 ;
V_39 = F_21 ( ( ( int * ) V_19 -> V_11 ) [ 0 ] ,
( ( int * ) V_19 -> V_11 ) [ 1 ] ) ;
V_18 = F_22 ( V_39 ) ;
V_29 -> V_36 = V_18 ;
* ( ( int * ) V_19 -> V_11 ) = V_18 -> T_3 ;
V_19 -> V_6 = sizeof( int ) ;
V_37 = F_7 ( V_16 , V_19 , V_4 + sizeof( int ) ) ;
F_23 ( V_39 ) ;
#endif
}
return V_37 ;
}
static int F_24 ( void T_1 * V_16 , struct V_17 * V_18 , struct V_1 * V_19 , int V_4 , T_2 * V_29 )
{
T_3 V_30 = 0 ;
V_18 = F_18 ( V_19 -> V_11 ) ;
if ( V_18 )
V_30 = V_18 -> T_3 ;
V_29 -> V_36 = V_18 ;
* ( ( int * ) V_19 -> V_11 ) = V_30 ;
V_19 -> V_6 = sizeof( int ) ;
return F_7 ( V_16 , V_19 , V_4 + sizeof( int ) ) ;
}
static int F_25 ( void T_1 * V_16 , struct V_1 * V_19 , int V_4 )
{
char * V_26 = V_40 ;
int V_15 = strlen ( V_26 ) ;
if ( V_15 > V_4 )
return - V_7 ;
strcpy ( V_19 -> V_11 , V_26 ) ;
V_19 -> V_6 = V_15 ;
return F_7 ( V_16 , V_19 , V_4 + sizeof( int ) ) ;
}
static long F_26 ( struct V_41 * V_41 ,
unsigned int V_28 , unsigned long V_42 ,
struct V_17 * V_18 )
{
T_2 * V_29 = V_41 -> V_43 ;
struct V_1 * V_14 = NULL ;
int V_4 , error = 0 ;
static int V_44 ;
void T_1 * V_16 = ( void T_1 * ) V_42 ;
if ( V_28 == V_45 )
V_4 = F_6 ( V_16 , & V_14 ) ;
else
V_4 = F_1 ( V_16 , & V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
F_27 ( & V_46 ) ;
switch ( V_28 ) {
case V_47 :
case V_48 :
error = F_9 ( V_16 , V_18 , V_14 , V_4 ) ;
break;
case V_49 :
case V_50 :
error = F_11 ( V_16 , V_18 , V_14 , V_4 ) ;
break;
case V_45 :
case V_51 :
error = F_13 ( V_18 , V_14 , V_4 ) ;
break;
case V_31 :
case V_33 :
case V_35 :
error = F_15 ( V_16 , V_28 , V_18 , V_14 , V_4 , V_29 ) ;
break;
case V_52 :
error = F_19 ( V_16 , V_18 , V_14 , V_4 , V_29 ) ;
break;
case V_53 :
error = F_24 ( V_16 , V_18 , V_14 , V_4 , V_29 ) ;
break;
case V_54 :
error = F_25 ( V_16 , V_14 , V_4 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
if ( V_44 ++ < 10 )
F_28 ( V_58 L_2 ) ;
error = - V_7 ;
break;
default:
if ( V_44 ++ < 10 )
F_28 ( V_58 L_3 , V_28 , V_42 ) ;
error = - V_7 ;
break;
}
F_5 ( V_14 ) ;
F_29 ( & V_46 ) ;
return error ;
}
static struct V_17 * F_30 ( T_3 V_12 , T_2 * V_29 )
{
struct V_17 * V_18 = F_17 ( V_12 ) ;
if ( V_18 )
V_29 -> V_59 = V_18 ;
return V_18 ;
}
static int F_31 ( char T_1 * V_60 , T_4 V_15 , char * * V_61 )
{
char * V_62 ;
if ( ( V_63 ) V_15 < 0 || ( V_63 ) ( V_15 + 1 ) < 0 )
return - V_7 ;
V_62 = F_32 ( V_15 + 1 , V_9 ) ;
if ( ! V_62 )
return - V_10 ;
if ( F_4 ( V_62 , V_60 , V_15 ) ) {
F_5 ( V_62 ) ;
return - V_5 ;
}
V_62 [ V_15 ] = '\0' ;
* V_61 = V_62 ;
return 0 ;
}
static int F_33 ( void T_1 * V_16 , T_2 * V_29 )
{
struct V_64 V_19 ;
struct V_17 * V_18 ;
char * V_65 ;
const void * V_20 ;
int V_37 , V_15 ;
if ( F_4 ( & V_19 , V_16 , sizeof( V_19 ) ) )
return - V_5 ;
V_18 = F_30 ( V_19 . V_66 , V_29 ) ;
V_37 = F_31 ( V_19 . V_67 , V_19 . V_68 , & V_65 ) ;
if ( V_37 )
return V_37 ;
V_20 = F_10 ( V_18 , V_65 , & V_15 ) ;
V_37 = 0 ;
if ( ! V_20 || V_15 > V_19 . V_69 ) {
V_37 = - V_7 ;
} else {
V_19 . V_69 = V_15 ;
if ( F_8 ( V_16 , & V_19 , sizeof( V_19 ) ) ||
F_8 ( V_19 . V_70 , V_20 , V_15 ) )
V_37 = - V_5 ;
}
F_5 ( V_65 ) ;
return V_37 ;
}
static int F_34 ( void T_1 * V_16 , T_2 * V_29 )
{
struct V_64 V_19 ;
struct V_17 * V_18 ;
struct V_21 * V_22 ;
char * V_65 ;
int V_37 , V_15 ;
if ( F_4 ( & V_19 , V_16 , sizeof( V_19 ) ) )
return - V_5 ;
V_18 = F_30 ( V_19 . V_66 , V_29 ) ;
if ( ! V_18 )
return - V_7 ;
V_37 = F_31 ( V_19 . V_67 , V_19 . V_68 , & V_65 ) ;
if ( V_37 )
return V_37 ;
if ( V_65 [ 0 ] == '\0' ) {
V_22 = V_18 -> V_23 ;
} else {
V_22 = F_12 ( V_18 , V_65 , NULL ) ;
if ( V_22 )
V_22 = V_22 -> V_25 ;
}
F_5 ( V_65 ) ;
if ( ! V_22 )
V_15 = 0 ;
else
V_15 = V_22 -> V_71 ;
if ( V_15 > V_19 . V_69 )
V_15 = V_19 . V_69 ;
if ( F_8 ( V_16 , & V_19 , sizeof( V_19 ) ) )
return - V_5 ;
if ( V_15 &&
F_8 ( V_19 . V_70 , V_22 -> V_72 , V_15 ) )
return - V_5 ;
return 0 ;
}
static int F_35 ( void T_1 * V_16 , T_2 * V_29 )
{
struct V_64 V_19 ;
struct V_17 * V_18 ;
char * V_65 , * V_62 ;
int V_37 ;
if ( F_4 ( & V_19 , V_16 , sizeof( V_19 ) ) )
return - V_5 ;
V_18 = F_30 ( V_19 . V_66 , V_29 ) ;
if ( ! V_18 )
return - V_7 ;
V_37 = F_31 ( V_19 . V_67 , V_19 . V_68 , & V_65 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_31 ( V_19 . V_70 , V_19 . V_69 , & V_62 ) ;
if ( V_37 ) {
F_5 ( V_65 ) ;
return V_37 ;
}
V_37 = F_14 ( V_18 , V_65 , V_62 , V_19 . V_69 ) ;
F_5 ( V_65 ) ;
F_5 ( V_62 ) ;
return V_37 ;
}
static int F_36 ( unsigned int V_28 , void T_1 * V_16 )
{
struct V_17 * V_18 ;
T_3 V_73 ;
F_16 ( sizeof( T_3 ) != sizeof( int ) ) ;
if ( F_4 ( & V_73 , V_16 , sizeof( T_3 ) ) )
return - V_5 ;
if ( V_73 == 0 ) {
if ( V_28 != V_74 )
return - V_7 ;
V_18 = F_18 ( L_1 ) ;
} else {
V_18 = F_17 ( V_73 ) ;
V_73 = 0 ;
if ( V_18 ) {
if ( V_28 == V_74 )
V_18 = V_18 -> V_32 ;
else
V_18 = V_18 -> V_34 ;
}
}
if ( V_18 )
V_73 = V_18 -> T_3 ;
if ( F_8 ( V_16 , & V_73 , sizeof( T_3 ) ) )
return - V_5 ;
return 0 ;
}
static int F_37 ( struct V_41 * V_41 ,
unsigned int V_28 , unsigned long V_42 )
{
T_2 * V_29 = V_41 -> V_43 ;
void T_1 * V_16 = ( void T_1 * ) V_42 ;
int V_37 ;
F_27 ( & V_46 ) ;
switch ( V_28 ) {
case V_75 :
V_37 = F_33 ( V_16 , V_29 ) ;
break;
case V_76 :
V_37 = F_34 ( V_16 , V_29 ) ;
break;
case V_77 :
V_37 = F_35 ( V_16 , V_29 ) ;
break;
case V_78 :
F_16 ( sizeof( T_3 ) != sizeof( int ) ) ;
V_37 = 0 ;
if ( F_8 ( V_16 , & V_27 -> T_3 , sizeof( T_3 ) ) )
V_37 = - V_5 ;
break;
case V_74 :
case V_79 :
V_37 = F_36 ( V_28 , V_16 ) ;
break;
default:
V_37 = - V_7 ;
break;
} ;
F_29 ( & V_46 ) ;
return V_37 ;
}
static long F_38 ( struct V_41 * V_41 ,
unsigned int V_28 , unsigned long V_42 )
{
T_2 * V_29 = V_41 -> V_43 ;
switch ( V_28 ) {
case V_47 :
case V_49 :
if ( ( V_41 -> V_80 & V_81 ) == 0 )
return - V_82 ;
return F_26 ( V_41 , V_28 , V_42 ,
V_27 ) ;
case V_45 :
case V_51 :
if ( ( V_41 -> V_80 & V_83 ) == 0 )
return - V_82 ;
return F_26 ( V_41 , V_28 , V_42 ,
V_27 ) ;
case V_31 :
case V_33 :
case V_48 :
case V_50 :
if ( ( V_41 -> V_80 & V_81 ) == 0 )
return - V_82 ;
return F_26 ( V_41 , V_28 , V_42 ,
V_29 -> V_36 ) ;
case V_55 :
case V_56 :
case V_57 :
case V_54 :
case V_35 :
case V_52 :
case V_53 :
if ( ( V_41 -> V_80 & V_81 ) == 0 )
return - V_82 ;
return F_26 ( V_41 , V_28 , V_42 , NULL ) ;
case V_75 :
case V_76 :
case V_78 :
case V_74 :
case V_79 :
if ( ( V_41 -> V_80 & V_81 ) == 0 )
return - V_84 ;
return F_37 ( V_41 , V_28 , V_42 ) ;
case V_77 :
if ( ( V_41 -> V_80 & V_83 ) == 0 )
return - V_84 ;
return F_37 ( V_41 , V_28 , V_42 ) ;
default:
return - V_7 ;
} ;
}
static long F_39 ( struct V_41 * V_41 , unsigned int V_28 ,
unsigned long V_42 )
{
long V_85 = - V_86 ;
switch ( V_28 ) {
case V_47 :
case V_45 :
case V_49 :
case V_51 :
case V_31 :
case V_33 :
case V_48 :
case V_50 :
case V_55 :
case V_56 :
case V_57 :
case V_54 :
case V_35 :
case V_52 :
case V_53 :
V_85 = F_38 ( V_41 , V_28 , V_42 ) ;
break;
}
return V_85 ;
}
static int F_40 ( struct V_87 * V_87 , struct V_41 * V_41 )
{
T_2 * V_29 ;
V_29 = F_32 ( sizeof( T_2 ) , V_9 ) ;
if ( ! V_29 )
return - V_10 ;
F_27 ( & V_46 ) ;
V_29 -> V_36 = F_18 ( L_1 ) ;
V_29 -> V_59 = V_29 -> V_36 ;
V_41 -> V_43 = ( void * ) V_29 ;
F_29 ( & V_46 ) ;
return 0 ;
}
static int F_41 ( struct V_87 * V_87 , struct V_41 * V_41 )
{
F_5 ( V_41 -> V_43 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
struct V_17 * V_18 ;
int V_37 ;
V_37 = F_43 ( & V_88 ) ;
if ( V_37 )
return V_37 ;
V_18 = F_18 ( L_1 ) ;
V_18 = V_18 -> V_34 ;
while ( V_18 ) {
if ( ! strcmp ( V_18 -> V_24 , L_4 ) )
break;
V_18 = V_18 -> V_32 ;
}
V_27 = V_18 ;
if ( ! V_27 ) {
F_44 ( & V_88 ) ;
return - V_89 ;
}
return 0 ;
}
static void T_6 F_45 ( void )
{
F_44 ( & V_88 ) ;
}
