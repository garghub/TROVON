int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
int V_5 = 0 ;
if ( ( V_2 -> V_4 >= V_6 ) && ( V_2 -> V_4 <= V_7 ) ) {
V_4 = F_2 ( V_2 -> V_4 ) ;
if ( V_4 == NULL ) {
V_5 = - 1 ;
} else {
F_3 ( 0 , V_4 -> V_8 ) ;
F_4 ( 1 ) ;
F_3 ( '\r' , V_4 -> V_8 ) ;
}
} else {
V_5 = - 1 ;
F_5 ( L_1 , V_2 -> V_4 ) ;
}
if ( V_5 ) {
F_6 ( L_2 , V_2 -> V_9 ) ;
return - V_10 ;
}
F_6 ( L_3 ,
V_2 -> V_9 , V_2 -> V_4 , V_2 -> V_11 ) ;
V_2 -> V_12 = 1 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
struct V_16 * V_17 ;
struct V_16 * V_18 ;
struct V_16 * V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
V_19 = F_8 ( V_23 ) ;
V_18 = F_8 ( V_24 ) ;
V_17 = F_8 ( V_25 ) ;
F_9 ( & V_26 . V_27 , V_14 ) ;
V_20 = V_19 -> V_28 . V_29 . V_30 ;
F_10 ( & V_26 . V_27 , V_14 ) ;
V_15 = V_31 + V_20 ;
while ( ! F_11 () ) {
F_9 ( & V_26 . V_27 , V_14 ) ;
if ( V_26 . V_32 ) {
V_26 . V_32 = 0 ;
F_10 ( & V_26 . V_27 , V_14 ) ;
V_2 -> V_33 ( V_2 ) ;
continue;
}
if ( F_12 () ) {
F_10 ( & V_26 . V_27 , V_14 ) ;
break;
}
V_13 = F_13 () ;
F_14 ( V_34 ) ;
V_22 = V_18 -> V_28 . V_29 . V_30 ;
F_10 ( & V_26 . V_27 , V_14 ) ;
if ( V_13 == '\n' )
V_13 = V_2 -> V_35 ;
if ( ! F_15 ( V_13 ) ) {
F_16 ( F_17 ( V_22 ) ) ;
continue;
}
if ( F_18 ( V_31 , V_15 ) && ( V_13 == V_36 ) ) {
F_9 ( & V_26 . V_27 , V_14 ) ;
V_20 = V_19 -> V_28 . V_29 . V_30 ;
V_21 = V_17 -> V_28 . V_29 . V_30 ;
V_22 = V_18 -> V_28 . V_29 . V_30 ;
F_10 ( & V_26 . V_27 , V_14 ) ;
if ( F_15 ( V_2 -> V_35 ) )
F_16 (
F_17 ( V_21 ) ) ;
else
F_16 (
F_17 ( V_22 ) ) ;
V_15 = V_31 + V_20 ;
}
F_14 ( V_37 ) ;
F_9 ( & V_26 . V_27 , V_14 ) ;
F_19 () ;
F_10 ( & V_26 . V_27 , V_14 ) ;
}
F_15 ( V_2 -> V_35 ) ;
}
const char * F_20 ( struct V_1 * V_2 , const char * V_38 )
{
T_1 V_13 ;
while ( ( V_13 = * V_38 ) ) {
if ( V_13 == '\n' )
V_13 = V_2 -> V_35 ;
if ( F_21 () )
F_22 ( V_13 , V_26 . V_39 ) ;
else
return V_38 ;
V_38 ++ ;
}
return NULL ;
}
void F_23 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_40 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
V_2 -> V_12 = 1 ;
return 1 ;
}
int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
return 1 ;
if ( ! V_2 -> V_12 && F_21 () > 0 ) {
V_2 -> V_12 = 1 ;
F_26 ( L_4 , V_2 -> V_41 ) ;
return 2 ;
}
F_5 ( L_5 , V_2 -> V_9 ) ;
return 0 ;
}
static void F_27 ( T_2 V_42 )
{
F_28 ( & V_43 ) ;
}
void F_29 ( void )
{
struct V_16 * V_44 ;
if ( ! V_2 -> V_12 ) {
F_30 () ;
return;
}
V_44 = F_8 ( V_45 ) ;
if ( ! F_31 ( & V_46 ) )
F_32 ( & V_46 , V_31 +
F_17 ( V_44 -> V_28 . V_29 . V_30 ) ) ;
}
void F_33 ( void )
{
if ( ! V_2 )
return;
V_26 . V_32 = 1 ;
F_30 () ;
if ( V_2 -> V_12 ) {
if ( V_47 ) {
F_26 ( L_4 , V_48 ) ;
V_47 = 0 ;
}
}
F_28 ( & V_43 ) ;
F_34 ( V_49 ) ;
}
void F_35 ( const char * V_50 , T_3 V_51 )
{
while ( V_51 -- )
F_36 ( * V_50 ++ ) ;
F_29 () ;
}
void F_26 ( const char * V_52 , ... )
{
T_4 args ;
unsigned char V_50 [ 160 ] , * V_53 ;
int V_54 ;
va_start ( args , V_52 ) ;
V_54 = vsnprintf ( V_50 , sizeof( V_50 ) , V_52 , args ) ;
va_end ( args ) ;
if ( V_54 > sizeof( V_50 ) - 1 )
V_54 = sizeof( V_50 ) - 1 ;
V_53 = V_50 ;
while ( V_54 -- )
F_36 ( * V_53 ++ ) ;
F_29 () ;
}
void F_37 ( int V_55 )
{
static int V_56 = 1 ;
if ( V_56 )
V_56 = 0 ;
else
V_2 -> V_57 () ;
V_58 = 0 ;
V_59 = V_55 ;
}
int F_38 ( void )
{
if ( V_2 -> V_57 != NULL )
return 1 ;
return 0 ;
}
void F_39 ( int V_60 )
{
int V_61 ;
if ( V_2 -> V_12 ) {
if ( V_60 == 0 ) {
V_2 -> V_62 . V_63 ++ ;
V_58 ++ ;
if ( V_2 -> V_62 . V_63 >
V_2 -> V_62 . V_64 )
V_2 -> V_62 . V_63 =
V_2 -> V_62 . V_65 ;
}
V_61 = V_2 -> V_62 . V_63 * 10 + V_60 ;
F_26 ( V_2 -> V_62 . V_66 , V_61 , V_61 ) ;
}
}
void F_40 ( int * V_67 , int * V_68 )
{
int V_69 = V_2 -> V_57 () ;
if ( V_69 ) {
V_59 = V_69 % 10 ;
if ( ( V_69 / 10 ) <= V_2 -> V_62 . V_63 )
V_58 = V_2 -> V_62 . V_63 - ( V_69 / 10 ) ;
else
V_58 = V_2 -> V_62 . V_63
- V_2 -> V_62 . V_65
+ V_2 -> V_62 . V_64 - ( V_69 / 10 ) + 1 ;
}
* V_68 = V_59 ;
* V_67 = V_58 ;
}
int F_41 ( unsigned long V_70 , unsigned long V_29 )
{
struct V_71 * V_72 = & V_73 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_75 = V_2 -> V_75 ;
V_74 . V_70 = V_70 ;
V_74 . V_76 = V_70 + V_29 - 1 ;
V_74 . V_14 = V_77 ;
return F_42 ( V_72 , & V_74 ) ;
}
int F_43 ( unsigned long V_70 , unsigned long V_29 )
{
return F_44 ( & V_74 ) ;
}
int F_45 ( char * V_78 )
{
int V_79 ;
int V_80 = 0 ;
struct V_1 * V_2 = NULL ;
if ( V_78 == NULL )
return 0 ;
if ( strcmp ( V_78 , L_6 ) == 0 ) {
F_46 ( & V_81 ) ;
F_47 () ;
F_48 ( & V_81 ) ;
return 0 ;
}
F_46 ( & V_81 ) ;
for ( V_79 = 0 ; V_79 < V_82 && V_83 [ V_79 ] != NULL ; V_79 ++ )
if ( strcmp ( V_83 [ V_79 ] -> V_75 , V_78 ) == 0 )
V_2 = V_83 [ V_79 ] ;
if ( V_2 )
V_80 = F_49 ( V_2 ) ;
else
V_80 = - V_10 ;
F_48 ( & V_81 ) ;
return V_80 ;
}
static int F_49 ( struct V_1 * V_84 )
{
struct V_16 * V_85 ;
F_47 () ;
if ( V_84 -> V_86 != V_87 )
return - V_88 ;
V_2 = V_84 ;
V_2 -> V_12 = 0 ;
F_5 ( L_7 ) ;
if ( V_2 -> V_89 ( V_2 ) < 0 ) {
F_5 ( L_8 , V_84 -> V_75 ) ;
V_2 = NULL ;
return - V_10 ;
}
V_90 [ 0 ] . V_28 . V_29 . V_30 =
V_90 [ 0 ] . V_28 . V_29 . V_91 = V_2 -> V_92 ;
V_90 [ 1 ] . V_28 . V_29 . V_30 =
V_90 [ 1 ] . V_28 . V_29 . V_91 = V_2 -> V_93 ;
V_90 [ 2 ] . V_28 . V_29 . V_30 =
V_90 [ 2 ] . V_28 . V_29 . V_91 = V_2 -> V_31 ;
V_90 [ 3 ] . V_28 . V_29 . V_30 =
V_90 [ 3 ] . V_28 . V_29 . V_91 = V_2 -> V_94 ;
F_26 ( L_4 , V_2 -> V_41 ) ;
for ( V_85 = V_2 -> V_95 ;
( V_85 -> V_96 >= 0 ) && ( V_85 -> V_96 < V_97 ) ; V_85 ++ )
F_50 ( V_85 ) ;
if ( ! V_98 )
F_26 ( L_9 , V_2 -> V_9 ) ;
if ( V_2 -> V_99 . V_75
&& F_51 ( V_100 , & ( V_2 -> V_99 ) ) < 0 )
return - V_101 ;
V_102 = V_2 -> V_14 ;
F_28 ( & V_43 ) ;
if ( V_49 )
F_34 ( V_49 ) ;
return 0 ;
}
void F_47 ( void )
{
struct V_16 * V_85 ;
unsigned long V_14 ;
if ( V_2 == NULL )
return;
F_9 ( & V_26 . V_27 , V_14 ) ;
F_6 ( L_10 , V_2 -> V_75 ) ;
V_2 -> V_12 = 0 ;
F_52 ( & V_46 ) ;
F_10 ( & V_26 . V_27 , V_14 ) ;
if ( V_2 -> V_99 . V_75 )
F_53 ( V_100 , & ( V_2 -> V_99 ) ) ;
for ( V_85 = V_2 -> V_95 ; V_85 -> V_96 != V_97 ; V_85 ++ )
F_54 ( V_85 -> V_96 ) ;
F_55 () ;
V_2 -> V_103 () ;
V_2 = NULL ;
}
int F_56 ( struct V_1 * V_84 )
{
int V_79 ;
int V_104 = 0 ;
F_46 ( & V_81 ) ;
for ( V_79 = 0 ; V_79 < V_82 && V_83 [ V_79 ] != NULL ; V_79 ++ )
if ( V_84 == V_83 [ V_79 ] ) {
F_48 ( & V_81 ) ;
return 0 ;
}
if ( V_79 == V_82 ) {
F_5 ( L_11 ) ;
F_48 ( & V_81 ) ;
return - 1 ;
}
V_83 [ V_79 ++ ] = V_84 ;
V_83 [ V_79 ] = NULL ;
if ( V_84 -> V_105 )
V_104 = F_49 ( V_84 ) ;
F_48 ( & V_81 ) ;
return V_104 ;
}
void F_57 ( struct V_1 * V_84 )
{
int V_79 ;
F_46 ( & V_81 ) ;
if ( V_2 == V_84 )
F_47 () ;
for ( V_79 = 0 ; V_83 [ V_79 ] != NULL ; V_79 ++ ) {
if ( V_84 == V_83 [ V_79 ] )
break;
}
for ( ; V_83 [ V_79 ] != NULL ; V_79 ++ )
V_83 [ V_79 ] = V_83 [ V_79 + 1 ] ;
V_106 = 0 ;
F_48 ( & V_81 ) ;
}
