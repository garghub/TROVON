static void F_1 ( void )
{
F_2 ( V_1 + V_2 ) ;
}
static T_1 F_3 ( int V_3 , void * V_4 )
{
unsigned int V_5 ;
unsigned long V_6 ;
int V_7 ;
F_4 ( V_6 ) ;
V_5 = F_5 () ;
F_6 ( 0x100 << V_2 ) ;
F_7 () ;
F_8 ( V_5 ) ;
F_9 ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
F_10 ( & V_9 [ V_7 ] . V_10 ) ;
F_10 ( & V_9 [ V_7 ] . V_11 ) ;
}
return V_12 ;
}
static void T_2 F_11 ( void )
{
int V_7 ;
F_12 ( L_1 , V_13 -> V_14 , V_13 -> V_15 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_16 * V_17 = & V_13 -> V_18 [ V_7 ] ;
F_12 ( L_2 ,
V_17 -> V_19 , V_17 -> V_20 , V_17 -> V_21 ) ;
F_12 ( L_3 ,
V_17 -> V_22 , V_17 -> V_23 ) ;
F_12 ( L_4 ,
V_17 -> V_24 , V_17 -> V_25 ) ;
F_12 ( L_5 , V_17 -> V_26 ) ;
F_12 ( L_6 , V_17 -> V_27 ) ;
}
}
static int F_13 ( struct V_28 * V_29 )
{
if ( V_29 -> V_14 != V_30 ) {
F_12 ( V_31 L_7 ,
V_29 , V_29 -> V_14 ) ;
return - V_32 ;
}
V_13 = V_29 ;
return 0 ;
}
static void F_14 ( int V_33 )
{
int V_7 ;
V_34 = 0 ;
V_13 = NULL ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
F_15 ( & V_9 [ V_7 ] . V_10 ) ;
}
static void F_16 ( int V_33 )
{
int V_7 ;
V_34 = 1 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
F_15 ( & V_9 [ V_7 ] . V_10 ) ;
}
int F_17 ( int V_35 , int V_36 )
{
struct V_28 * * V_37 ;
struct V_16 * V_17 ;
enum V_38 V_15 ;
int V_39 = 0 ;
if ( V_35 >= V_8 ) {
F_12 ( V_40 L_8 ) ;
return - V_41 ;
}
if ( F_18 ( & V_9 [ V_35 ] . V_42 ) > 1 ) {
F_12 ( V_40 L_9 ,
V_35 ) ;
V_39 = - V_43 ;
goto V_44;
}
if ( V_13 == NULL ) {
if( ( V_37 = F_19 ( V_45 ) ) == NULL ) {
if ( V_36 ) {
V_39 = F_20 (
V_9 [ V_35 ] . V_10 ,
( V_37 = F_19 ( V_45 ) ) ) ;
if ( V_39 )
goto V_44;
} else {
F_12 ( V_40 L_10
L_11 ) ;
V_39 = - V_41 ;
goto V_44;
}
}
F_21 () ;
if ( * V_37 == NULL ) {
if ( V_36 ) {
F_22 ( V_46 ) ;
for (; ; ) {
F_23 (
& V_9 [ V_35 ] . V_10 ,
& V_46 , V_47 ) ;
F_21 () ;
if ( * V_37 != NULL )
break;
if ( ! F_24 ( V_48 ) ) {
F_25 () ;
continue;
}
V_39 = - V_49 ;
goto V_44;
}
F_26 ( & V_9 [ V_35 ] . V_10 , & V_46 ) ;
} else {
F_27 ( L_12
L_13 ) ;
V_39 = - V_41 ;
goto V_44;
}
}
if ( ( unsigned int ) * V_37 < V_50 ) {
F_12 ( V_51 L_14
L_15 ,
( int ) * V_37 ) ;
V_39 = - V_41 ;
goto V_44;
}
if ( ( V_39 = F_13 ( * V_37 ) ) < 0 )
goto V_52;
}
V_17 = & V_13 -> V_18 [ V_35 ] ;
V_15 = F_28 ( & V_17 -> V_20 , V_53 ) ;
if ( V_15 == V_53 ) {
V_39 = - V_43 ;
goto V_44;
}
V_44:
F_29 () ;
F_30 ( & V_9 [ V_35 ] . V_42 ) ;
F_29 () ;
V_52:
return V_39 ;
}
int F_31 ( int V_35 )
{
if ( V_13 == NULL ) {
F_27 ( L_16 ) ;
return 0 ;
}
V_13 -> V_18 [ V_35 ] . V_20 = V_54 ;
return 0 ;
}
unsigned int F_32 ( int V_35 , int V_36 )
{
struct V_16 * V_17 ;
if ( V_13 == NULL )
return 0 ;
V_17 = & V_13 -> V_18 [ V_35 ] ;
if ( V_17 -> V_24 == V_17 -> V_25 ) {
if ( V_36 ) {
int V_39 = F_20 (
V_9 [ V_35 ] . V_10 ,
( V_17 -> V_24 != V_17 -> V_25 ) ||
V_34 ) ;
if ( V_39 )
return V_39 ;
if ( V_34 )
return 0 ;
} else
return 0 ;
}
return ( V_17 -> V_25 + V_17 -> V_21 - V_17 -> V_24 )
% V_17 -> V_21 ;
}
static inline int F_33 ( int V_55 , int V_56 , int V_57 )
{
if ( V_55 == V_56 ) {
return V_57 - 1 ;
}
return ( ( V_55 + V_57 - V_56 ) % V_57 ) - 1 ;
}
unsigned int F_34 ( int V_35 )
{
struct V_16 * V_17 = & V_13 -> V_18 [ V_35 ] ;
return F_33 ( V_17 -> V_22 , V_17 -> V_23 ,
V_17 -> V_21 ) ;
}
T_3 F_35 ( int V_35 , void T_4 * V_58 , T_5 V_59 )
{
T_5 V_25 , V_60 = 0L ;
struct V_16 * V_61 ;
unsigned long V_62 ;
if ( V_13 == NULL )
return - V_41 ;
V_61 = & V_13 -> V_18 [ V_35 ] ;
F_36 ( & V_9 [ V_35 ] . V_63 ) ;
F_21 () ;
V_25 = V_61 -> V_25 ;
V_59 = F_37 ( V_59 ,
( T_5 ) ( V_25 + V_61 -> V_21 - V_61 -> V_24 )
% V_61 -> V_21 ) ;
V_60 = F_37 ( V_59 , ( T_5 ) V_61 -> V_21 - V_61 -> V_24 ) ;
V_62 = F_38 ( V_58 , V_61 -> V_27 + V_61 -> V_24 , V_60 ) ;
if ( V_62 )
goto V_64;
if ( V_59 - V_60 )
V_62 = F_38 ( V_58 + V_60 , V_61 -> V_27 , V_59 - V_60 ) ;
V_64:
V_59 -= V_62 ;
F_39 () ;
V_61 -> V_24 = ( V_61 -> V_24 + V_59 ) % V_61 -> V_21 ;
F_39 () ;
F_40 ( & V_9 [ V_35 ] . V_63 ) ;
return V_59 ;
}
T_3 F_41 ( int V_35 , const void T_4 * V_65 , T_5 V_59 )
{
struct V_16 * V_66 ;
unsigned long V_62 ;
T_5 V_22 ;
T_5 V_60 ;
if ( V_13 == NULL )
return ( - V_41 ) ;
V_66 = & V_13 -> V_18 [ V_35 ] ;
F_36 ( & V_9 [ V_35 ] . V_63 ) ;
F_21 () ;
V_22 = V_66 -> V_22 ;
V_59 = F_37 ( V_59 , ( T_5 ) F_33 ( V_22 , V_66 -> V_23 ,
V_66 -> V_21 ) ) ;
V_60 = F_37 ( V_59 , ( T_5 ) V_66 -> V_21 - V_66 -> V_23 ) ;
V_62 = F_42 ( V_66 -> V_26 + V_66 -> V_23 , V_65 , V_60 ) ;
if ( V_62 )
goto V_64;
if ( V_59 - V_60 ) {
V_62 = F_42 ( V_66 -> V_26 , V_65 + V_60 , V_59 - V_60 ) ;
}
V_64:
V_59 -= V_62 ;
F_39 () ;
V_66 -> V_23 = ( V_66 -> V_23 + V_59 ) % V_66 -> V_21 ;
F_39 () ;
F_40 ( & V_9 [ V_35 ] . V_63 ) ;
return V_59 ;
}
static int F_43 ( struct V_67 * V_67 , struct V_68 * V_69 )
{
return F_17 ( F_44 ( V_67 ) , ( V_69 -> V_70 & V_71 ) ? 0 : 1 ) ;
}
static int F_45 ( struct V_67 * V_67 , struct V_68 * V_69 )
{
return F_31 ( F_44 ( V_67 ) ) ;
}
static unsigned int F_46 ( struct V_68 * V_68 , T_6 * V_46 )
{
int V_72 = F_44 ( F_47 ( V_68 ) ) ;
unsigned int V_73 = 0 ;
F_48 ( V_68 , & V_9 [ V_72 ] . V_11 , V_46 ) ;
F_48 ( V_68 , & V_9 [ V_72 ] . V_10 , V_46 ) ;
if ( V_13 == NULL )
return 0 ;
if ( F_32 ( V_72 , 0 ) )
V_73 |= V_74 | V_75 ;
if ( F_34 ( V_72 ) )
V_73 |= V_76 | V_77 ;
return V_73 ;
}
static T_3 F_49 ( struct V_68 * V_68 , char T_4 * V_65 , T_5 V_59 ,
T_7 * V_78 )
{
int V_72 = F_44 ( F_47 ( V_68 ) ) ;
if ( ! F_32 ( V_72 , ( V_68 -> V_70 & V_71 ) ? 0 : 1 ) ) {
return 0 ;
}
return F_35 ( V_72 , V_65 , V_59 ) ;
}
static T_3 F_50 ( struct V_68 * V_68 , const char T_4 * V_65 ,
T_5 V_59 , T_7 * V_78 )
{
int V_72 = F_44 ( F_47 ( V_68 ) ) ;
if ( ! F_34 ( V_72 ) ) {
int V_39 ;
if ( V_68 -> V_70 & V_71 )
return - V_79 ;
V_39 = F_20 ( V_9 [ V_72 ] . V_11 ,
F_34 ( V_72 ) ) ;
if ( V_39 )
return V_39 ;
}
return F_41 ( V_72 , V_65 , V_59 ) ;
}
static int T_8 F_51 ( void )
{
struct V_80 * V_81 ;
int V_7 , V_82 ;
if ( ! V_83 ) {
F_12 ( L_17 ) ;
return - V_84 ;
}
if ( V_45 == 0 ) {
F_12 ( V_51 L_18
L_19
L_20 ) ;
return - V_84 ;
}
V_85 = F_52 ( 0 , V_86 , & V_87 ) ;
if ( V_85 < 0 ) {
F_12 ( V_88 ) ;
return V_85 ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
F_53 ( & V_9 [ V_7 ] . V_11 ) ;
F_53 ( & V_9 [ V_7 ] . V_10 ) ;
F_54 ( & V_9 [ V_7 ] . V_42 , 0 ) ;
F_55 ( & V_9 [ V_7 ] . V_63 ) ;
V_81 = F_56 ( V_89 , NULL , F_57 ( V_85 , V_7 ) , NULL ,
L_21 , V_86 , V_7 ) ;
if ( F_58 ( V_81 ) ) {
V_82 = F_59 ( V_81 ) ;
goto V_90;
}
}
V_91 . V_92 = F_14 ;
V_91 . V_93 = F_16 ;
F_60 ( V_45 , & V_91 ) ;
if ( V_94 )
F_61 ( V_2 , F_1 ) ;
else {
F_27 ( L_22 ) ;
V_82 = - V_84 ;
goto V_90;
}
V_95 . V_4 = V_13 ;
F_62 ( V_96 , & V_95 ) ;
return 0 ;
V_90:
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
F_63 ( V_89 , F_57 ( V_85 , V_7 ) ) ;
return V_82 ;
}
static void T_9 F_64 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
F_63 ( V_89 , F_57 ( V_85 , V_7 ) ) ;
F_65 ( V_85 , V_86 ) ;
}
