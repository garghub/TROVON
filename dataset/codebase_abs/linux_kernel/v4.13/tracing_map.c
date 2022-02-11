void F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 , & V_2 -> V_5 [ V_3 ] . V_6 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( T_1 ) F_4 ( & V_2 -> V_5 [ V_3 ] . V_6 ) ;
}
int F_5 ( void * V_7 , void * V_8 )
{
char * V_9 = V_7 ;
char * V_10 = V_8 ;
return strcmp ( V_9 , V_10 ) ;
}
int F_6 ( void * V_7 , void * V_8 )
{
return 0 ;
}
static int F_7 ( void * V_7 , void * V_8 )
{
T_1 V_9 = F_4 ( ( V_11 * ) V_7 ) ;
T_1 V_10 = F_4 ( ( V_11 * ) V_8 ) ;
return ( V_9 > V_10 ) ? 1 : ( ( V_9 < V_10 ) ? - 1 : 0 ) ;
}
T_2 F_8 ( int V_12 ,
int V_13 )
{
T_2 V_14 = F_6 ;
switch ( V_12 ) {
case 8 :
if ( V_13 )
V_14 = V_15 ;
else
V_14 = V_16 ;
break;
case 4 :
if ( V_13 )
V_14 = V_17 ;
else
V_14 = V_18 ;
break;
case 2 :
if ( V_13 )
V_14 = V_19 ;
else
V_14 = V_20 ;
break;
case 1 :
if ( V_13 )
V_14 = V_21 ;
else
V_14 = V_22 ;
break;
}
return V_14 ;
}
static int F_9 ( struct V_23 * V_24 ,
T_2 V_25 )
{
int V_26 = - V_27 ;
if ( V_24 -> V_28 < V_29 ) {
V_26 = V_24 -> V_28 ;
V_24 -> V_5 [ V_24 -> V_28 ++ ] . V_25 = V_25 ;
}
return V_26 ;
}
int F_10 ( struct V_23 * V_24 )
{
return F_9 ( V_24 , F_7 ) ;
}
int F_11 ( struct V_23 * V_24 ,
unsigned int V_30 ,
T_2 V_25 )
{
int V_31 = F_9 ( V_24 , V_25 ) ;
if ( V_31 < 0 )
return V_31 ;
V_24 -> V_5 [ V_31 ] . V_30 = V_30 ;
V_24 -> V_32 [ V_24 -> V_33 ++ ] = V_31 ;
return V_31 ;
}
void F_12 ( struct V_34 * V_9 )
{
unsigned int V_3 ;
if ( ! V_9 -> V_35 )
return;
for ( V_3 = 0 ; V_3 < V_9 -> V_36 ; V_3 ++ )
memset ( V_9 -> V_35 [ V_3 ] , 0 , V_37 ) ;
}
void F_13 ( struct V_34 * V_9 )
{
unsigned int V_3 ;
if ( ! V_9 )
return;
if ( ! V_9 -> V_35 )
goto free;
for ( V_3 = 0 ; V_3 < V_9 -> V_36 ; V_3 ++ ) {
if ( ! V_9 -> V_35 [ V_3 ] )
break;
F_14 ( ( unsigned long ) V_9 -> V_35 [ V_3 ] ) ;
}
F_15 ( V_9 -> V_35 ) ;
free:
F_15 ( V_9 ) ;
}
struct V_34 * F_16 ( unsigned int V_38 ,
unsigned int V_39 )
{
struct V_34 * V_9 ;
unsigned int V_3 ;
V_9 = F_17 ( sizeof( * V_9 ) , V_40 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_41 = F_18 ( F_19 ( V_39 ) - 1 ) ;
V_9 -> V_42 = V_37 / ( 1 << V_9 -> V_41 ) ;
V_9 -> V_36 = V_38 / V_9 -> V_42 ;
if ( ! V_9 -> V_36 )
V_9 -> V_36 = 1 ;
V_9 -> V_43 = F_18 ( V_9 -> V_42 ) - 1 ;
V_9 -> V_44 = ( 1 << V_9 -> V_43 ) - 1 ;
V_9 -> V_35 = F_20 ( V_9 -> V_36 , sizeof( void * ) , V_40 ) ;
if ( ! V_9 -> V_35 )
goto free;
for ( V_3 = 0 ; V_3 < V_9 -> V_36 ; V_3 ++ ) {
V_9 -> V_35 [ V_3 ] = ( void * ) F_21 ( V_40 ) ;
if ( ! V_9 -> V_35 [ V_3 ] )
goto free;
}
V_45:
return V_9 ;
free:
F_13 ( V_9 ) ;
V_9 = NULL ;
goto V_45;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_24 -> V_28 ; V_3 ++ )
if ( V_2 -> V_5 [ V_3 ] . V_25 == F_7 )
F_23 ( & V_2 -> V_5 [ V_3 ] . V_6 , 0 ) ;
if ( V_2 -> V_24 -> V_46 && V_2 -> V_24 -> V_46 -> V_47 )
V_2 -> V_24 -> V_46 -> V_47 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_22 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_24 -> V_28 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_25 = V_2 -> V_24 -> V_5 [ V_3 ] . V_25 ;
if ( V_2 -> V_5 [ V_3 ] . V_25 != F_7 )
V_2 -> V_5 [ V_3 ] . V_30 = V_2 -> V_24 -> V_5 [ V_3 ] . V_30 ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_24 -> V_46 && V_2 -> V_24 -> V_46 -> V_48 )
V_2 -> V_24 -> V_46 -> V_48 ( V_2 ) ;
F_15 ( V_2 -> V_5 ) ;
F_15 ( V_2 -> V_49 ) ;
F_15 ( V_2 ) ;
}
static struct V_1 * F_26 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_50 = 0 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return F_27 ( - V_51 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_49 = F_17 ( V_24 -> V_52 , V_40 ) ;
if ( ! V_2 -> V_49 ) {
V_50 = - V_51 ;
goto free;
}
V_2 -> V_5 = F_20 ( V_24 -> V_28 , sizeof( * V_2 -> V_5 ) , V_40 ) ;
if ( ! V_2 -> V_5 ) {
V_50 = - V_51 ;
goto free;
}
F_24 ( V_2 ) ;
if ( V_24 -> V_46 && V_24 -> V_46 -> V_53 ) {
V_50 = V_24 -> V_46 -> V_53 ( V_2 ) ;
if ( V_50 )
goto free;
}
return V_2 ;
free:
F_25 ( V_2 ) ;
return F_27 ( V_50 ) ;
}
static struct V_1 * F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = NULL ;
int V_31 ;
V_31 = F_29 ( & V_24 -> V_54 ) ;
if ( V_31 < V_24 -> V_55 ) {
V_2 = * ( F_30 ( V_24 -> V_56 , V_31 ) ) ;
if ( V_24 -> V_46 && V_24 -> V_46 -> V_57 )
V_24 -> V_46 -> V_57 ( V_2 ) ;
}
return V_2 ;
}
static void F_31 ( struct V_23 * V_24 )
{
unsigned int V_3 ;
if ( ! V_24 -> V_56 )
return;
for ( V_3 = 0 ; V_3 < V_24 -> V_55 ; V_3 ++ ) {
F_25 ( * ( F_30 ( V_24 -> V_56 , V_3 ) ) ) ;
* ( F_30 ( V_24 -> V_56 , V_3 ) ) = NULL ;
}
F_13 ( V_24 -> V_56 ) ;
V_24 -> V_56 = NULL ;
}
static int F_32 ( struct V_23 * V_24 )
{
unsigned int V_3 ;
V_24 -> V_56 = F_16 ( V_24 -> V_55 ,
sizeof( struct V_1 * ) ) ;
if ( ! V_24 -> V_56 )
return - V_51 ;
for ( V_3 = 0 ; V_3 < V_24 -> V_55 ; V_3 ++ ) {
* ( F_30 ( V_24 -> V_56 , V_3 ) ) = F_26 ( V_24 ) ;
if ( F_33 ( * ( F_30 ( V_24 -> V_56 , V_3 ) ) ) ) {
* ( F_30 ( V_24 -> V_56 , V_3 ) ) = NULL ;
F_31 ( V_24 ) ;
return - V_51 ;
}
}
return 0 ;
}
static inline bool F_34 ( void * V_49 , void * V_58 , unsigned V_52 )
{
bool V_59 = true ;
if ( memcmp ( V_49 , V_58 , V_52 ) )
V_59 = false ;
return V_59 ;
}
static inline struct V_1 *
F_35 ( struct V_23 * V_24 , void * V_49 , bool V_60 )
{
T_3 V_31 , V_61 , V_58 ;
struct V_62 * V_63 ;
V_61 = F_36 ( V_49 , V_24 -> V_52 , 0 ) ;
if ( V_61 == 0 )
V_61 = 1 ;
V_31 = V_61 >> ( 32 - ( V_24 -> V_64 + 1 ) ) ;
while ( 1 ) {
V_31 &= ( V_24 -> V_65 - 1 ) ;
V_63 = F_37 ( V_24 -> V_24 , V_31 ) ;
V_58 = V_63 -> V_49 ;
if ( V_58 && V_58 == V_61 && V_63 -> V_66 &&
F_34 ( V_49 , V_63 -> V_66 -> V_49 , V_24 -> V_52 ) ) {
F_38 ( & V_24 -> V_67 ) ;
return V_63 -> V_66 ;
}
if ( ! V_58 ) {
if ( V_60 )
break;
if ( ! F_39 ( & V_63 -> V_49 , 0 , V_61 ) ) {
struct V_1 * V_2 ;
V_2 = F_28 ( V_24 ) ;
if ( ! V_2 ) {
F_38 ( & V_24 -> V_68 ) ;
V_63 -> V_49 = 0 ;
break;
}
memcpy ( V_2 -> V_49 , V_49 , V_24 -> V_52 ) ;
V_63 -> V_66 = V_2 ;
F_38 ( & V_24 -> V_67 ) ;
return V_63 -> V_66 ;
}
}
V_31 ++ ;
}
return NULL ;
}
struct V_1 * F_40 ( struct V_23 * V_24 , void * V_49 )
{
return F_35 ( V_24 , V_49 , false ) ;
}
struct V_1 * F_41 ( struct V_23 * V_24 , void * V_49 )
{
return F_35 ( V_24 , V_49 , true ) ;
}
void F_42 ( struct V_23 * V_24 )
{
if ( ! V_24 )
return;
F_31 ( V_24 ) ;
F_13 ( V_24 -> V_24 ) ;
F_15 ( V_24 ) ;
}
void F_43 ( struct V_23 * V_24 )
{
unsigned int V_3 ;
F_44 ( & V_24 -> V_54 , - 1 ) ;
F_23 ( & V_24 -> V_67 , 0 ) ;
F_23 ( & V_24 -> V_68 , 0 ) ;
F_12 ( V_24 -> V_24 ) ;
for ( V_3 = 0 ; V_3 < V_24 -> V_55 ; V_3 ++ )
F_22 ( * ( F_30 ( V_24 -> V_56 , V_3 ) ) ) ;
}
static void F_45 ( struct V_23 * V_24 ,
struct V_69 * V_70 )
{
V_24 -> V_70 = * V_70 ;
}
struct V_23 * F_46 ( unsigned int V_64 ,
unsigned int V_52 ,
const struct V_71 * V_46 ,
void * V_72 )
{
struct V_23 * V_24 ;
unsigned int V_3 ;
if ( V_64 < V_73 ||
V_64 > V_74 )
return F_27 ( - V_27 ) ;
V_24 = F_17 ( sizeof( * V_24 ) , V_40 ) ;
if ( ! V_24 )
return F_27 ( - V_51 ) ;
V_24 -> V_64 = V_64 ;
V_24 -> V_55 = ( 1 << V_64 ) ;
F_44 ( & V_24 -> V_54 , - 1 ) ;
V_24 -> V_65 = ( 1 << ( V_64 + 1 ) ) ;
V_24 -> V_46 = V_46 ;
V_24 -> V_72 = V_72 ;
V_24 -> V_24 = F_16 ( V_24 -> V_65 ,
sizeof( struct V_62 ) ) ;
if ( ! V_24 -> V_24 )
goto free;
V_24 -> V_52 = V_52 ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
V_24 -> V_32 [ V_3 ] = - 1 ;
V_45:
return V_24 ;
free:
F_42 ( V_24 ) ;
V_24 = F_27 ( - V_51 ) ;
goto V_45;
}
int F_47 ( struct V_23 * V_24 )
{
int V_50 ;
if ( V_24 -> V_28 < 2 )
return - V_27 ;
V_50 = F_32 ( V_24 ) ;
if ( V_50 )
return V_50 ;
F_43 ( V_24 ) ;
return V_50 ;
}
static int F_48 ( const struct V_76 * * V_9 ,
const struct V_76 * * V_10 )
{
int V_26 = 0 ;
if ( memcmp ( ( * V_9 ) -> V_49 , ( * V_10 ) -> V_49 , ( * V_9 ) -> V_2 -> V_24 -> V_52 ) )
V_26 = 1 ;
return V_26 ;
}
static int F_49 ( const struct V_76 * * V_9 ,
const struct V_76 * * V_10 )
{
const struct V_1 * V_77 , * V_78 ;
struct V_69 * V_70 ;
struct V_79 * V_80 ;
T_2 V_25 ;
void * V_7 , * V_8 ;
int V_26 = 0 ;
V_77 = ( * V_9 ) -> V_2 ;
V_78 = ( * V_10 ) -> V_2 ;
V_70 = & V_77 -> V_24 -> V_70 ;
V_80 = & V_77 -> V_5 [ V_70 -> V_81 ] ;
V_25 = V_80 -> V_25 ;
V_7 = & V_77 -> V_5 [ V_70 -> V_81 ] . V_6 ;
V_8 = & V_78 -> V_5 [ V_70 -> V_81 ] . V_6 ;
V_26 = V_25 ( V_7 , V_8 ) ;
if ( V_70 -> V_82 )
V_26 = - V_26 ;
return V_26 ;
}
static int F_50 ( const struct V_76 * * V_9 ,
const struct V_76 * * V_10 )
{
const struct V_1 * V_77 , * V_78 ;
struct V_69 * V_70 ;
struct V_79 * V_80 ;
T_2 V_25 ;
void * V_7 , * V_8 ;
int V_26 = 0 ;
V_77 = ( * V_9 ) -> V_2 ;
V_78 = ( * V_10 ) -> V_2 ;
V_70 = & V_77 -> V_24 -> V_70 ;
V_80 = & V_77 -> V_5 [ V_70 -> V_81 ] ;
V_25 = V_80 -> V_25 ;
V_7 = V_77 -> V_49 + V_80 -> V_30 ;
V_8 = V_78 -> V_49 + V_80 -> V_30 ;
V_26 = V_25 ( V_7 , V_8 ) ;
if ( V_70 -> V_82 )
V_26 = - V_26 ;
return V_26 ;
}
static void F_51 ( struct V_76 * V_63 )
{
if ( ! V_63 )
return;
if ( V_63 -> V_83 )
F_25 ( V_63 -> V_2 ) ;
F_15 ( V_63 ) ;
}
void F_52 ( struct V_76 * * V_84 ,
unsigned int V_85 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ )
F_51 ( V_84 [ V_3 ] ) ;
F_53 ( V_84 ) ;
}
static struct V_76 *
F_54 ( void * V_49 , struct V_1 * V_2 )
{
struct V_76 * V_86 ;
V_86 = F_17 ( sizeof( * V_86 ) , V_40 ) ;
if ( ! V_86 )
return NULL ;
V_86 -> V_49 = V_49 ;
V_86 -> V_2 = V_2 ;
return V_86 ;
}
static struct V_1 * F_55 ( struct V_1 * V_2 )
{
struct V_1 * V_87 ;
unsigned int V_3 ;
V_87 = F_26 ( V_2 -> V_24 ) ;
if ( F_33 ( V_87 ) )
return NULL ;
if ( V_2 -> V_24 -> V_46 && V_2 -> V_24 -> V_46 -> V_88 )
V_2 -> V_24 -> V_46 -> V_88 ( V_87 , V_2 ) ;
V_87 -> V_72 = V_2 -> V_72 ;
memcpy ( V_87 -> V_49 , V_2 -> V_49 , V_2 -> V_24 -> V_52 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_24 -> V_28 ; V_3 ++ ) {
F_23 ( & V_87 -> V_5 [ V_3 ] . V_6 ,
F_4 ( & V_2 -> V_5 [ V_3 ] . V_6 ) ) ;
V_87 -> V_5 [ V_3 ] . V_25 = V_2 -> V_5 [ V_3 ] . V_25 ;
}
return V_87 ;
}
static int F_56 ( struct V_76 * * V_89 ,
unsigned int V_90 , unsigned int V_91 )
{
struct V_1 * V_92 , * V_2 ;
bool V_93 = ( V_90 - V_91 ) == 1 ;
int V_3 ;
if ( V_93 ) {
V_2 = V_89 [ V_90 ] -> V_2 ;
V_92 = F_55 ( V_2 ) ;
if ( ! V_92 )
return - V_51 ;
V_89 [ V_90 ] -> V_2 = V_92 ;
V_89 [ V_90 ] -> V_83 = true ;
} else
V_92 = V_89 [ V_90 ] -> V_2 ;
V_2 = V_89 [ V_91 ] -> V_2 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_24 -> V_28 ; V_3 ++ )
F_2 ( F_4 ( & V_2 -> V_5 [ V_3 ] . V_6 ) ,
& V_92 -> V_5 [ V_3 ] . V_6 ) ;
V_89 [ V_91 ] -> V_91 = true ;
return 0 ;
}
static int F_57 ( struct V_76 * * V_89 ,
int V_85 , unsigned int V_52 )
{
unsigned int V_94 = 0 , V_95 = 0 ;
int V_50 , V_3 , V_96 ;
void * V_49 ;
if ( V_85 < 2 )
return V_95 ;
F_58 ( V_89 , V_85 , sizeof( struct V_76 * ) ,
( int ( * ) ( const void * , const void * ) ) F_48 , NULL ) ;
V_49 = V_89 [ 0 ] -> V_49 ;
for ( V_3 = 1 ; V_3 < V_85 ; V_3 ++ ) {
if ( ! memcmp ( V_89 [ V_3 ] -> V_49 , V_49 , V_52 ) ) {
V_94 ++ ; V_95 ++ ;
V_50 = F_56 ( V_89 , V_3 - V_94 , V_3 ) ;
if ( V_50 )
return V_50 ;
continue;
}
V_49 = V_89 [ V_3 ] -> V_49 ;
V_94 = 0 ;
}
if ( ! V_95 )
return V_95 ;
for ( V_3 = 0 , V_96 = 0 ; V_3 < V_85 ; V_3 ++ ) {
if ( ! V_89 [ V_3 ] -> V_91 ) {
V_89 [ V_96 ] = V_89 [ V_3 ] ;
if ( V_96 ++ != V_3 )
V_89 [ V_3 ] = NULL ;
} else {
F_51 ( V_89 [ V_3 ] ) ;
V_89 [ V_3 ] = NULL ;
}
}
return V_95 ;
}
static bool F_59 ( struct V_23 * V_24 , unsigned int V_81 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_24 -> V_33 ; V_3 ++ )
if ( V_24 -> V_32 [ V_3 ] == V_81 )
return true ;
return false ;
}
static void F_60 ( struct V_23 * V_24 ,
const struct V_76 * * V_84 ,
unsigned int V_85 ,
struct V_69 * V_97 ,
struct V_69 * V_98 )
{
int (* F_61)( const struct V_76 * * ,
const struct V_76 * * );
int (* F_62)( const struct V_76 * * ,
const struct V_76 * * );
unsigned V_3 , V_99 = 0 , V_100 = 1 ;
if ( F_59 ( V_24 , V_97 -> V_81 ) )
F_61 = F_50 ;
else
F_61 = F_49 ;
if ( F_59 ( V_24 , V_98 -> V_81 ) )
F_62 = F_50 ;
else
F_62 = F_49 ;
for ( V_3 = 0 ; V_3 < V_85 - 1 ; V_3 ++ ) {
const struct V_76 * * V_9 = & V_84 [ V_3 ] ;
const struct V_76 * * V_10 = & V_84 [ V_3 + 1 ] ;
if ( F_61 ( V_9 , V_10 ) == 0 ) {
V_100 ++ ;
if ( V_3 < V_85 - 2 )
continue;
}
if ( V_100 < 2 ) {
V_99 = V_3 + 1 ;
V_100 = 1 ;
continue;
}
F_45 ( V_24 , V_98 ) ;
F_58 ( & V_84 [ V_99 ] , V_100 ,
sizeof( struct V_76 * ) ,
( int ( * ) ( const void * , const void * ) ) F_62 , NULL ) ;
F_45 ( V_24 , V_97 ) ;
V_99 = V_3 + 1 ;
V_100 = 1 ;
}
}
int F_63 ( struct V_23 * V_24 ,
struct V_69 * V_101 ,
unsigned int V_102 ,
struct V_76 * * * V_89 )
{
int (* F_64)( const struct V_76 * * ,
const struct V_76 * * );
struct V_76 * V_86 , * * V_84 ;
int V_3 , V_85 , V_26 ;
V_84 = F_65 ( V_24 -> V_55 * sizeof( V_86 ) ) ;
if ( ! V_84 )
return - V_51 ;
for ( V_3 = 0 , V_85 = 0 ; V_3 < V_24 -> V_65 ; V_3 ++ ) {
struct V_62 * V_63 ;
V_63 = F_37 ( V_24 -> V_24 , V_3 ) ;
if ( ! V_63 -> V_49 || ! V_63 -> V_66 )
continue;
V_84 [ V_85 ] = F_54 ( V_63 -> V_66 -> V_49 ,
V_63 -> V_66 ) ;
if ( ! V_84 [ V_85 ++ ] ) {
V_26 = - V_51 ;
goto free;
}
}
if ( V_85 == 0 ) {
V_26 = 0 ;
goto free;
}
if ( V_85 == 1 ) {
* V_89 = V_84 ;
return 1 ;
}
V_26 = F_57 ( V_84 , V_85 , V_24 -> V_52 ) ;
if ( V_26 < 0 )
goto free;
V_85 -= V_26 ;
if ( F_59 ( V_24 , V_101 [ 0 ] . V_81 ) )
F_64 = F_50 ;
else
F_64 = F_49 ;
F_45 ( V_24 , & V_101 [ 0 ] ) ;
F_58 ( V_84 , V_85 , sizeof( struct V_76 * ) ,
( int ( * ) ( const void * , const void * ) ) F_64 , NULL ) ;
if ( V_102 > 1 )
F_60 ( V_24 ,
( const struct V_76 * * ) V_84 ,
V_85 ,
& V_101 [ 0 ] ,
& V_101 [ 1 ] ) ;
* V_89 = V_84 ;
return V_85 ;
free:
F_52 ( V_84 , V_85 ) ;
return V_26 ;
}
