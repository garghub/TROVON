static void F_1 ( char * V_1 , char * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_1 [ V_3 ] == '\0' )
break;
V_2 [ V_3 ] = toupper ( V_1 [ V_3 ] ) ;
}
for (; V_3 < 8 ; V_3 ++ )
V_2 [ V_3 ] = ' ' ;
F_2 ( V_2 , 8 ) ;
}
static inline unsigned long F_3 ( struct V_4 * V_5 )
{
return * ( V_6 * ) & V_5 -> V_7 . V_8 ;
}
static inline unsigned long F_4 ( struct V_4 * V_5 )
{
return * ( V_6 * ) & V_5 -> V_7 . V_8 [ 4 ] ;
}
static inline T_1 F_5 ( struct V_4 * V_5 , T_1 V_9 )
{
return * ( ( T_1 * ) F_3 ( V_5 ) + V_5 -> V_10 + V_9 ) ;
}
static inline V_6 F_6 ( struct V_4 * V_5 )
{
return F_4 ( V_5 ) - F_3 ( V_5 ) + 1 ;
}
static inline V_6 F_7 ( struct V_4 * V_5 )
{
return * ( ( V_6 * ) ( F_3 ( V_5 ) + V_5 -> V_10 + 4 ) ) ;
}
static inline V_6 F_8 ( struct V_4 * V_5 )
{
return * ( ( V_6 * ) ( F_3 ( V_5 ) + V_5 -> V_10 + 8 ) ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
if ( ( F_8 ( V_5 ) <= F_7 ( V_5 ) ) ||
( F_7 ( V_5 ) < V_11 ) ||
( F_8 ( V_5 ) > V_12 ) ||
( F_5 ( V_5 , 0 ) == 0 ) ||
( F_6 ( V_5 ) % 12 != 0 ) ||
( F_4 ( V_5 ) <= F_3 ( V_5 ) ) ||
( F_4 ( V_5 ) > V_12 ) ||
( F_3 ( V_5 ) < V_11 ) ||
( ( F_5 ( V_5 , 1 ) == 0 ) && ( F_5 ( V_5 , 2 ) == 0 ) ) )
return - V_13 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_11 ( V_15 -> V_17 , & V_5 -> V_7 ,
V_18 , NULL , 0 ) ;
F_12 ( & V_15 -> V_19 ) ;
if ( F_13 ( ! V_5 -> V_20 ) ) {
V_5 -> V_21 = 0 ;
V_5 -> V_10 = 0 ;
V_15 -> V_22 = ( V_15 -> V_22 + 1 ) %
V_23 ;
F_12 ( & V_15 -> V_24 ) ;
} else
V_5 -> V_25 = 1 ;
if ( V_16 ) {
F_14 ( L_1 , V_16 ) ;
return - V_26 ;
}
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
F_16 ( V_15 -> V_27 [ V_3 ] ) ;
F_16 ( V_15 ) ;
}
static struct V_14 * F_17 ( void )
{
int V_3 ;
struct V_14 * V_15 ;
V_15 = F_18 ( sizeof( struct V_14 ) , V_28 ) ;
if ( ! V_15 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
V_15 -> V_27 [ V_3 ] = F_18 ( sizeof( struct V_4 ) ,
V_28 ) ;
if ( ! V_15 -> V_27 [ V_3 ] ) {
F_15 ( V_15 ) ;
return NULL ;
}
}
return V_15 ;
}
static inline void F_19 ( struct V_4 * V_5 )
{
if ( F_13 ( ( F_6 ( V_5 ) - V_5 -> V_10 ) == 12 ) )
return;
V_5 -> V_10 += 12 ;
V_5 -> V_21 = 0 ;
}
static struct V_4 * F_20 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
if ( ! F_21 ( & V_15 -> V_24 ) )
return NULL ;
V_5 = V_15 -> V_27 [ V_15 -> V_22 ] ;
if ( F_22 ( V_5 -> V_25 ) ) {
V_5 -> V_25 = 0 ;
V_5 -> V_20 = 0 ;
V_5 -> V_21 = 0 ;
V_5 -> V_10 = 0 ;
V_15 -> V_22 = ( V_15 -> V_22 + 1 ) %
V_23 ;
F_12 ( & V_15 -> V_24 ) ;
return F_23 ( - V_29 ) ;
}
return V_5 ;
}
static void F_24 ( struct V_30 * V_17 , T_1 * V_31 )
{
struct V_14 * V_15 = V_17 -> V_32 ;
F_25 ( & V_15 -> V_33 , 1 ) ;
F_26 ( & V_34 ) ;
}
static void F_27 ( struct V_30 * V_17 , T_1 * V_31 )
{
struct V_14 * V_15 = V_17 -> V_32 ;
F_14 ( L_2 ,
V_31 [ 0 ] ) ;
F_28 ( V_17 , NULL ) ;
F_25 ( & V_15 -> V_35 , 1 ) ;
F_26 ( & V_34 ) ;
F_29 ( & V_36 ) ;
}
static void F_30 ( struct V_30 * V_17 ,
struct V_37 * V_7 )
{
struct V_14 * V_15 = V_17 -> V_32 ;
memcpy ( & V_15 -> V_27 [ V_15 -> V_38 ] -> V_7 ,
V_7 , sizeof( * V_7 ) ) ;
if ( F_31 ( & V_15 -> V_19 ) == V_23 ) {
F_32 ( L_3 ) ;
V_15 -> V_27 [ V_15 -> V_38 ] -> V_20 = 1 ;
}
V_15 -> V_38 = ( V_15 -> V_38 + 1 ) % V_23 ;
F_33 ( & V_15 -> V_24 ) ;
F_29 ( & V_36 ) ;
}
static int F_34 ( struct V_39 * V_39 , struct V_40 * V_41 )
{
struct V_14 * V_15 ;
int V_16 ;
V_16 = - V_42 ;
if ( F_35 ( V_43 , & V_44 ) )
goto V_45;
V_16 = - V_46 ;
V_15 = F_17 () ;
if ( ! V_15 )
goto V_47;
V_15 -> V_17 = F_36 ( V_23 , V_18 , V_28 ) ;
if ( ! V_15 -> V_17 )
goto V_48;
V_16 = F_37 ( V_15 -> V_17 , & V_49 ,
V_50 , NULL , V_51 , V_15 ) ;
if ( V_16 ) {
F_14 ( L_4
L_5 , V_16 ) ;
V_16 = - V_26 ;
goto V_52;
}
F_38 ( V_34 ,
F_21 ( & V_15 -> V_33 ) ||
F_21 ( & V_15 -> V_35 ) ) ;
if ( F_21 ( & V_15 -> V_35 ) ) {
F_25 ( & V_15 -> V_35 , 0 ) ;
F_25 ( & V_15 -> V_33 , 0 ) ;
V_16 = - V_26 ;
goto V_52;
}
V_41 -> V_53 = V_15 ;
F_39 ( V_54 , V_15 ) ;
return F_40 ( V_39 , V_41 ) ;
V_52:
F_41 ( V_15 -> V_17 ) ;
V_48:
F_15 ( V_15 ) ;
V_47:
F_42 ( V_43 , & V_44 ) ;
V_45:
return V_16 ;
}
static int F_43 ( struct V_39 * V_39 , struct V_40 * V_41 )
{
int V_16 , V_3 ;
struct V_14 * V_15 = V_41 -> V_53 ;
if ( V_15 -> V_17 ) {
V_16 = F_28 ( V_15 -> V_17 , V_55 ) ;
if ( V_16 )
F_32 ( L_6 ,
V_16 ) ;
F_41 ( V_15 -> V_17 ) ;
}
F_25 ( & V_15 -> V_35 , 0 ) ;
F_25 ( & V_15 -> V_33 , 0 ) ;
F_25 ( & V_15 -> V_24 , 0 ) ;
F_25 ( & V_15 -> V_19 , 0 ) ;
V_15 -> V_38 = 0 ;
V_15 -> V_22 = 0 ;
F_39 ( V_54 , NULL ) ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
F_16 ( V_15 -> V_27 [ V_3 ] ) ;
F_16 ( V_15 ) ;
F_42 ( V_43 , & V_44 ) ;
return 0 ;
}
static T_2 F_44 ( struct V_40 * V_41 , char T_3 * V_56 ,
T_4 V_57 , T_5 * V_58 )
{
struct V_14 * V_15 = V_41 -> V_53 ;
struct V_4 * V_5 ;
int V_59 ;
V_6 V_60 ;
V_5 = F_20 ( V_15 ) ;
if ( F_45 ( V_5 ) )
return F_46 ( V_5 ) ;
if ( ! V_5 ) {
if ( V_41 -> V_61 & V_62 )
return - V_63 ;
V_59 = F_47 ( V_36 ,
F_21 ( & V_15 -> V_24 ) ||
F_21 ( & V_15 -> V_35 ) ) ;
if ( V_59 )
return V_59 ;
if ( F_22 ( F_21 ( & V_15 -> V_35 ) ) )
return - V_26 ;
V_5 = V_15 -> V_27 [ V_15 -> V_22 ] ;
}
if ( ! V_5 -> V_21 )
V_5 -> V_21 = F_3 ( V_5 ) + V_5 -> V_10 ;
if ( F_9 ( V_5 ) )
goto V_64;
V_60 = F_3 ( V_5 ) + V_5 -> V_10 ;
if ( ( V_5 -> V_21 >= V_60 ) && ( V_5 -> V_21 < V_60 + 12 ) ) {
V_57 = F_48 ( V_57 , ( T_4 ) V_60 + 12 - V_5 -> V_21 ) ;
V_59 = F_49 ( V_56 , ( void * ) ( unsigned long ) V_5 -> V_21 ,
V_57 ) ;
if ( V_59 )
return - V_65 ;
V_5 -> V_21 += V_57 ;
if ( V_5 -> V_21 == V_60 + 12 )
V_5 -> V_21 = F_7 ( V_5 ) ;
goto V_66;
}
if ( V_5 -> V_21 <= F_8 ( V_5 ) ) {
V_57 = F_48 ( V_57 , ( T_4 ) F_8 ( V_5 ) - V_5 -> V_21
+ 1 ) ;
V_59 = F_49 ( V_56 , ( void * ) ( unsigned long ) V_5 -> V_21 ,
V_57 ) ;
if ( V_59 )
return - V_65 ;
V_5 -> V_21 += V_57 ;
if ( V_5 -> V_21 > F_8 ( V_5 ) )
F_19 ( V_5 ) ;
goto V_66;
}
V_64:
V_59 = F_10 ( V_5 , V_15 ) ;
return V_59 ;
V_66:
* V_58 += V_57 ;
return V_57 ;
}
static unsigned int F_50 ( struct V_40 * V_41 , struct V_67 * V_68 )
{
struct V_14 * V_15 = V_41 -> V_53 ;
F_51 ( V_41 , & V_36 , V_68 ) ;
if ( F_22 ( F_21 ( & V_15 -> V_35 ) ) )
return V_69 ;
if ( F_21 ( & V_15 -> V_24 ) )
return V_70 | V_71 ;
return 0 ;
}
static int F_52 ( struct V_72 * V_73 )
{
struct V_14 * V_15 = F_53 ( V_73 ) ;
int V_16 ;
if ( ! V_15 )
return 0 ;
if ( V_15 -> V_17 ) {
V_16 = F_28 ( V_15 -> V_17 , V_55 ) ;
if ( V_16 )
F_32 ( L_6 ,
V_16 ) ;
F_41 ( V_15 -> V_17 ) ;
}
F_25 ( & V_15 -> V_35 , 0 ) ;
F_25 ( & V_15 -> V_33 , 0 ) ;
F_25 ( & V_15 -> V_24 , 0 ) ;
F_25 ( & V_15 -> V_19 , 0 ) ;
V_15 -> V_38 = 0 ;
V_15 -> V_22 = 0 ;
V_15 -> V_17 = NULL ;
return 0 ;
}
static int F_54 ( struct V_72 * V_73 )
{
struct V_14 * V_15 = F_53 ( V_73 ) ;
int V_16 ;
if ( ! V_15 )
return 0 ;
V_16 = - V_46 ;
V_15 -> V_17 = F_36 ( V_23 , V_18 , V_28 ) ;
if ( ! V_15 -> V_17 )
goto V_45;
V_16 = F_37 ( V_15 -> V_17 , & V_49 ,
V_50 , NULL , V_51 , V_15 ) ;
if ( V_16 ) {
F_14 ( L_4
L_5 , V_16 ) ;
goto V_52;
}
F_38 ( V_34 ,
F_21 ( & V_15 -> V_33 ) ||
F_21 ( & V_15 -> V_35 ) ) ;
if ( F_21 ( & V_15 -> V_35 ) )
goto V_52;
return 0 ;
V_52:
V_16 = - V_26 ;
F_41 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
V_45:
F_25 ( & V_15 -> V_35 , 1 ) ;
return V_16 ;
}
static int F_55 ( struct V_72 * V_73 )
{
int V_16 ;
F_56 ( V_74 ) ;
V_16 = F_57 ( V_74 , V_75 ,
& V_11 , & V_12 ) ;
if ( V_16 < 0 ) {
F_58 ( V_16 , V_74 ) ;
F_59 ( L_7 ) ;
}
return F_54 ( V_73 ) ;
}
static int T_6 F_60 ( void )
{
int V_16 ;
if ( ! V_76 ) {
F_14 ( L_8
L_9 ) ;
return - V_77 ;
}
V_16 = F_61 ( & V_49 , 1 ) ;
if ( V_16 ) {
F_14 ( L_10
L_11 ) ;
return V_16 ;
}
V_16 = F_62 ( & V_78 ) ;
if ( V_16 )
goto V_79;
V_54 = F_18 ( sizeof( struct V_72 ) , V_28 ) ;
if ( ! V_54 ) {
V_16 = - V_46 ;
goto V_80;
}
F_63 ( V_54 , L_12 ) ;
V_54 -> V_81 = & V_82 ;
V_54 -> V_83 = V_84 ;
V_54 -> V_85 = & V_78 ;
V_54 -> V_86 = ( void ( * ) ( struct V_72 * ) ) F_16 ;
V_16 = F_64 ( V_54 ) ;
if ( V_16 ) {
F_65 ( V_54 ) ;
goto V_80;
}
V_16 = F_66 ( V_74 ) ;
if ( V_16 < 0 ) {
F_58 ( V_16 , V_74 ) ;
goto V_87;
}
if ( V_16 != V_88 ) {
F_14 ( L_13
L_14 , V_74 ) ;
V_16 = - V_13 ;
goto V_87;
}
V_16 = F_57 ( V_74 , V_75 ,
& V_11 , & V_12 ) ;
if ( V_16 < 0 ) {
F_58 ( V_16 , V_74 ) ;
V_16 = - V_13 ;
goto V_87;
}
F_1 ( V_74 , & V_51 [ 8 ] ) ;
V_16 = F_67 ( & V_89 ) ;
if ( V_16 < 0 )
goto V_45;
return 0 ;
V_45:
F_56 ( V_74 ) ;
V_87:
F_68 ( V_54 ) ;
V_80:
F_69 ( & V_78 ) ;
V_79:
F_70 ( & V_49 , 1 ) ;
return V_16 ;
}
static void T_7 F_71 ( void )
{
F_56 ( V_74 ) ;
F_72 ( & V_89 ) ;
F_68 ( V_54 ) ;
F_69 ( & V_78 ) ;
F_70 ( & V_49 , 1 ) ;
return;
}
