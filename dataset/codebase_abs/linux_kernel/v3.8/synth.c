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
F_9 ( V_14 ) ;
V_20 = V_19 -> V_26 . V_27 . V_28 ;
F_10 ( V_14 ) ;
V_15 = V_29 + V_20 ;
while ( ! F_11 () ) {
F_9 ( V_14 ) ;
if ( V_30 . V_31 ) {
V_30 . V_31 = 0 ;
F_10 ( V_14 ) ;
V_2 -> V_32 ( V_2 ) ;
continue;
}
if ( F_12 () ) {
F_10 ( V_14 ) ;
break;
}
V_13 = F_13 () ;
F_14 ( V_33 ) ;
V_22 = V_18 -> V_26 . V_27 . V_28 ;
F_10 ( V_14 ) ;
if ( V_13 == '\n' )
V_13 = V_2 -> V_34 ;
if ( ! F_15 ( V_13 ) ) {
F_16 ( F_17 ( V_22 ) ) ;
continue;
}
if ( ( V_29 >= V_15 ) && ( V_13 == V_35 ) ) {
F_9 ( V_14 ) ;
V_20 = V_19 -> V_26 . V_27 . V_28 ;
V_21 = V_17 -> V_26 . V_27 . V_28 ;
V_22 = V_18 -> V_26 . V_27 . V_28 ;
F_10 ( V_14 ) ;
if ( F_15 ( V_2 -> V_34 ) )
F_16 (
F_17 ( V_21 ) ) ;
else
F_16 (
F_17 ( V_22 ) ) ;
V_15 = V_29 + V_20 ;
}
F_14 ( V_36 ) ;
F_9 ( V_14 ) ;
F_18 () ;
F_10 ( V_14 ) ;
}
F_15 ( V_2 -> V_34 ) ;
}
const char * F_19 ( struct V_1 * V_2 , const char * V_37 )
{
T_1 V_13 ;
while ( ( V_13 = * V_37 ) ) {
if ( V_13 == '\n' )
V_13 = V_2 -> V_34 ;
if ( F_20 () )
F_21 ( V_13 , V_30 . V_38 ) ;
else
return V_37 ;
V_37 ++ ;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_39 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
V_2 -> V_12 = 1 ;
return 1 ;
}
int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
return 1 ;
if ( ! V_2 -> V_12 && F_20 () > 0 ) {
V_2 -> V_12 = 1 ;
F_25 ( L_4 , V_2 -> V_40 ) ;
return 2 ;
}
F_5 ( L_5 , V_2 -> V_9 ) ;
return 0 ;
}
static void F_26 ( T_2 V_41 )
{
F_27 ( & V_42 ) ;
}
void F_28 ( void )
{
struct V_16 * V_43 ;
if ( ! V_2 -> V_12 ) {
F_29 () ;
return;
}
V_43 = F_8 ( V_44 ) ;
if ( ! F_30 ( & V_45 ) )
F_31 ( & V_45 , V_29 +
F_17 ( V_43 -> V_26 . V_27 . V_28 ) ) ;
}
void F_32 ( void )
{
V_30 . V_31 = 1 ;
F_29 () ;
if ( V_2 -> V_12 ) {
if ( V_46 ) {
F_25 ( L_4 , V_47 ) ;
V_46 = 0 ;
}
}
F_27 ( & V_42 ) ;
F_33 ( V_48 ) ;
}
void F_34 ( const char * V_49 , T_3 V_50 )
{
while ( V_50 -- )
F_35 ( * V_49 ++ ) ;
F_28 () ;
}
void F_25 ( const char * V_51 , ... )
{
T_4 args ;
unsigned char V_49 [ 160 ] , * V_52 ;
int V_53 ;
va_start ( args , V_51 ) ;
V_53 = vsnprintf ( V_49 , sizeof( V_49 ) , V_51 , args ) ;
va_end ( args ) ;
if ( V_53 > sizeof( V_49 ) - 1 )
V_53 = sizeof( V_49 ) - 1 ;
V_52 = V_49 ;
while ( V_53 -- )
F_35 ( * V_52 ++ ) ;
F_28 () ;
}
void F_36 ( int V_54 )
{
static int V_55 = 1 ;
if ( V_55 )
V_55 = 0 ;
else
V_2 -> V_56 () ;
V_57 = 0 ;
V_58 = V_54 ;
}
int F_37 ( void )
{
if ( V_2 -> V_56 != NULL )
return 1 ;
return 0 ;
}
void F_38 ( int V_59 )
{
int V_60 ;
if ( V_2 -> V_12 ) {
if ( V_59 == 0 ) {
V_2 -> V_61 . V_62 ++ ;
V_57 ++ ;
if ( V_2 -> V_61 . V_62 >
V_2 -> V_61 . V_63 )
V_2 -> V_61 . V_62 =
V_2 -> V_61 . V_64 ;
}
V_60 = V_2 -> V_61 . V_62 * 10 + V_59 ;
F_25 ( V_2 -> V_61 . V_65 , V_60 , V_60 ) ;
}
}
void F_39 ( int * V_66 , int * V_67 )
{
int V_68 = V_2 -> V_56 () ;
if ( V_68 ) {
V_58 = V_68 % 10 ;
if ( ( V_68 / 10 ) <= V_2 -> V_61 . V_62 )
V_57 = V_2 -> V_61 . V_62 - ( V_68 / 10 ) ;
else
V_57 = V_2 -> V_61 . V_62
- V_2 -> V_61 . V_64
+ V_2 -> V_61 . V_63 - ( V_68 / 10 ) + 1 ;
}
* V_67 = V_58 ;
* V_66 = V_57 ;
}
int F_40 ( unsigned long V_69 , unsigned long V_27 )
{
struct V_70 * V_71 = & V_72 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_74 = V_2 -> V_74 ;
V_73 . V_69 = V_69 ;
V_73 . V_75 = V_69 + V_27 - 1 ;
V_73 . V_14 = V_76 ;
return F_41 ( V_71 , & V_73 ) ;
}
int F_42 ( unsigned long V_69 , unsigned long V_27 )
{
return F_43 ( & V_73 ) ;
}
int F_44 ( char * V_77 )
{
int V_78 ;
int V_79 = 0 ;
struct V_1 * V_2 = NULL ;
if ( V_77 == NULL )
return 0 ;
if ( strcmp ( V_77 , L_6 ) == 0 ) {
F_45 ( & V_80 ) ;
F_46 () ;
F_47 ( & V_80 ) ;
return 0 ;
}
F_45 ( & V_80 ) ;
for ( V_78 = 0 ; V_78 < V_81 && V_82 [ V_78 ] != NULL ; V_78 ++ )
if ( strcmp ( V_82 [ V_78 ] -> V_74 , V_77 ) == 0 )
V_2 = V_82 [ V_78 ] ;
if ( V_2 )
V_79 = F_48 ( V_2 ) ;
else
V_79 = - V_10 ;
F_47 ( & V_80 ) ;
return V_79 ;
}
static int F_48 ( struct V_1 * V_83 )
{
struct V_16 * V_84 ;
F_46 () ;
if ( V_83 -> V_85 != V_86 )
return - V_87 ;
V_2 = V_83 ;
V_2 -> V_12 = 0 ;
F_5 ( L_7 ) ;
if ( V_2 -> V_88 ( V_2 ) < 0 ) {
F_5 ( L_8 , V_83 -> V_74 ) ;
V_2 = NULL ;
return - V_10 ;
}
V_89 [ 0 ] . V_26 . V_27 . V_28 =
V_89 [ 0 ] . V_26 . V_27 . V_90 = V_2 -> V_91 ;
V_89 [ 1 ] . V_26 . V_27 . V_28 =
V_89 [ 1 ] . V_26 . V_27 . V_90 = V_2 -> V_92 ;
V_89 [ 2 ] . V_26 . V_27 . V_28 =
V_89 [ 2 ] . V_26 . V_27 . V_90 = V_2 -> V_29 ;
V_89 [ 3 ] . V_26 . V_27 . V_28 =
V_89 [ 3 ] . V_26 . V_27 . V_90 = V_2 -> V_93 ;
F_25 ( L_4 , V_2 -> V_40 ) ;
for ( V_84 = V_2 -> V_94 ;
( V_84 -> V_95 >= 0 ) && ( V_84 -> V_95 < V_96 ) ; V_84 ++ )
F_49 ( V_84 ) ;
if ( ! V_97 )
F_25 ( L_9 , V_2 -> V_9 ) ;
if ( V_2 -> V_98 . V_74
&& F_50 ( V_99 , & ( V_2 -> V_98 ) ) < 0 )
return - V_100 ;
V_101 = V_2 -> V_14 ;
F_27 ( & V_42 ) ;
if ( V_48 )
F_33 ( V_48 ) ;
return 0 ;
}
void F_46 ( void )
{
struct V_16 * V_84 ;
unsigned long V_14 ;
if ( V_2 == NULL )
return;
F_9 ( V_14 ) ;
F_6 ( L_10 , V_2 -> V_74 ) ;
V_2 -> V_12 = 0 ;
F_51 ( & V_45 ) ;
F_10 ( V_14 ) ;
if ( V_2 -> V_98 . V_74 )
F_52 ( V_99 , & ( V_2 -> V_98 ) ) ;
for ( V_84 = V_2 -> V_94 ; V_84 -> V_95 != V_96 ; V_84 ++ )
F_53 ( V_84 -> V_95 ) ;
F_54 () ;
V_2 -> V_102 () ;
V_2 = NULL ;
}
int F_55 ( struct V_1 * V_83 )
{
int V_78 ;
int V_103 = 0 ;
F_45 ( & V_80 ) ;
for ( V_78 = 0 ; V_78 < V_81 && V_82 [ V_78 ] != NULL ; V_78 ++ )
if ( V_83 == V_82 [ V_78 ] ) {
F_47 ( & V_80 ) ;
return 0 ;
}
if ( V_78 == V_81 ) {
F_5 ( L_11 ) ;
F_47 ( & V_80 ) ;
return - 1 ;
}
V_82 [ V_78 ++ ] = V_83 ;
V_82 [ V_78 ] = NULL ;
if ( V_83 -> V_104 )
V_103 = F_48 ( V_83 ) ;
F_47 ( & V_80 ) ;
return V_103 ;
}
void F_56 ( struct V_1 * V_83 )
{
int V_78 ;
F_45 ( & V_80 ) ;
if ( V_2 == V_83 )
F_46 () ;
for ( V_78 = 0 ; V_82 [ V_78 ] != NULL ; V_78 ++ ) {
if ( V_83 == V_82 [ V_78 ] )
break;
}
for ( ; V_82 [ V_78 ] != NULL ; V_78 ++ )
V_82 [ V_78 ] = V_82 [ V_78 + 1 ] ;
V_105 = 0 ;
F_47 ( & V_80 ) ;
}
