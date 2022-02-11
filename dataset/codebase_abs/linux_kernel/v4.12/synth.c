void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
struct V_6 * V_7 ;
struct V_6 * V_8 ;
struct V_6 * V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
V_9 = F_2 ( V_13 ) ;
V_8 = F_2 ( V_14 ) ;
V_7 = F_2 ( V_15 ) ;
F_3 ( & V_16 . V_17 , V_4 ) ;
V_10 = V_9 -> V_18 . V_19 . V_20 ;
F_4 ( & V_16 . V_17 , V_4 ) ;
V_5 = V_21 + V_10 ;
while ( ! F_5 () ) {
F_3 ( & V_16 . V_17 , V_4 ) ;
if ( V_16 . V_22 ) {
V_16 . V_22 = 0 ;
F_4 ( & V_16 . V_17 , V_4 ) ;
V_2 -> V_23 ( V_2 ) ;
continue;
}
F_6 () ;
if ( F_7 () ) {
F_4 ( & V_16 . V_17 , V_4 ) ;
break;
}
V_3 = F_8 () ;
F_9 ( V_24 ) ;
V_12 = V_8 -> V_18 . V_19 . V_20 ;
F_4 ( & V_16 . V_17 , V_4 ) ;
if ( V_3 == '\n' )
V_3 = V_2 -> V_25 ;
if ( ! V_2 -> V_26 -> V_27 ( V_2 , V_3 ) ) {
F_10 ( F_11 ( V_12 ) ) ;
continue;
}
if ( F_12 ( V_21 , V_5 ) && ( V_3 == V_28 ) ) {
F_3 ( & V_16 . V_17 , V_4 ) ;
V_10 = V_9 -> V_18 . V_19 . V_20 ;
V_11 = V_7 -> V_18 . V_19 . V_20 ;
V_12 = V_8 -> V_18 . V_19 . V_20 ;
F_4 ( & V_16 . V_17 , V_4 ) ;
if ( V_2 -> V_26 -> V_27 ( V_2 , V_2 -> V_25 ) )
F_10 (
F_11 ( V_11 ) ) ;
else
F_10 (
F_11 ( V_12 ) ) ;
V_5 = V_21 + V_10 ;
}
F_9 ( V_29 ) ;
F_3 ( & V_16 . V_17 , V_4 ) ;
F_13 () ;
F_4 ( & V_16 . V_17 , V_4 ) ;
}
V_2 -> V_26 -> V_27 ( V_2 , V_2 -> V_25 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_26 -> V_27 ( V_2 , V_2 -> V_30 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 1 ;
return 1 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
return 1 ;
if ( F_17 ( V_2 ) > 0 ) {
V_2 -> V_31 = 1 ;
F_18 ( L_1 , V_2 -> V_32 ) ;
return 2 ;
}
F_19 ( L_2 , V_2 -> V_33 ) ;
return 0 ;
}
static void F_20 ( T_2 V_34 )
{
F_21 ( & V_35 ) ;
}
void F_22 ( void )
{
struct V_6 * V_36 ;
if ( ! V_2 -> V_31 ) {
F_23 () ;
return;
}
V_36 = F_2 ( V_37 ) ;
if ( ! F_24 ( & V_38 ) )
F_25 ( & V_38 , V_21 +
F_11 ( V_36 -> V_18 . V_19 . V_20 ) ) ;
}
void F_26 ( void )
{
if ( ! V_2 )
return;
V_16 . V_22 = 1 ;
F_23 () ;
if ( V_2 -> V_31 ) {
if ( V_39 ) {
F_18 ( L_1 , V_40 ) ;
V_39 = 0 ;
}
}
F_21 ( & V_35 ) ;
F_27 ( V_41 ) ;
}
void F_28 ( const char * V_42 , T_3 V_43 )
{
while ( V_43 -- )
F_29 ( * V_42 ++ ) ;
F_22 () ;
}
void F_18 ( const char * V_44 , ... )
{
T_4 args ;
unsigned char V_42 [ 160 ] , * V_45 ;
int V_46 ;
va_start ( args , V_44 ) ;
V_46 = vsnprintf ( V_42 , sizeof( V_42 ) , V_44 , args ) ;
va_end ( args ) ;
if ( V_46 > sizeof( V_42 ) - 1 )
V_46 = sizeof( V_42 ) - 1 ;
V_45 = V_42 ;
while ( V_46 -- )
F_29 ( * V_45 ++ ) ;
F_22 () ;
}
void F_30 ( T_5 V_47 )
{
F_29 ( V_47 ) ;
}
void F_31 ( T_5 V_47 )
{
F_29 ( V_47 ) ;
F_22 () ;
}
void F_32 ( const T_5 * V_42 )
{
const T_5 * V_45 ;
for ( V_45 = V_42 ; * V_45 ; V_45 ++ )
F_29 ( * V_45 ) ;
}
void F_33 ( const T_5 * V_42 )
{
F_32 ( V_42 ) ;
F_22 () ;
}
void F_34 ( int V_48 )
{
static int V_49 = 1 ;
if ( V_49 )
V_49 = 0 ;
else
V_2 -> V_50 () ;
V_51 = 0 ;
V_52 = V_48 ;
}
int F_35 ( void )
{
if ( V_2 -> V_50 )
return 1 ;
return 0 ;
}
void F_36 ( int V_53 )
{
int V_54 ;
if ( V_2 -> V_31 ) {
if ( V_53 == 0 ) {
V_2 -> V_55 . V_56 ++ ;
V_51 ++ ;
if ( V_2 -> V_55 . V_56 >
V_2 -> V_55 . V_57 )
V_2 -> V_55 . V_56 =
V_2 -> V_55 . V_58 ;
}
V_54 = V_2 -> V_55 . V_56 * 10 + V_53 ;
F_18 ( V_2 -> V_55 . V_59 , V_54 , V_54 ) ;
}
}
void F_37 ( int * V_60 , int * V_61 )
{
int V_62 = V_2 -> V_50 () ;
if ( V_62 ) {
V_52 = V_62 % 10 ;
if ( ( V_62 / 10 ) <= V_2 -> V_55 . V_56 )
V_51 = V_2 -> V_55 . V_56 - ( V_62 / 10 ) ;
else
V_51 = V_2 -> V_55 . V_56
- V_2 -> V_55 . V_58
+ V_2 -> V_55 . V_57 - ( V_62 / 10 ) + 1 ;
}
* V_61 = V_52 ;
* V_60 = V_51 ;
}
int F_38 ( unsigned long V_63 , unsigned long V_19 )
{
struct V_64 * V_65 = & V_66 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_68 = V_2 -> V_68 ;
V_67 . V_63 = V_63 ;
V_67 . V_69 = V_63 + V_19 - 1 ;
V_67 . V_4 = V_70 ;
return F_39 ( V_65 , & V_67 ) ;
}
int F_40 ( unsigned long V_63 , unsigned long V_19 )
{
return F_41 ( & V_67 ) ;
}
int F_42 ( char * V_71 )
{
int V_72 ;
int V_73 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_71 )
return 0 ;
if ( strcmp ( V_71 , L_3 ) == 0 ) {
F_43 ( & V_74 ) ;
F_44 () ;
F_45 ( & V_74 ) ;
return 0 ;
}
F_43 ( & V_74 ) ;
for ( V_72 = 0 ; V_72 < V_75 && V_76 [ V_72 ] ; V_72 ++ )
if ( strcmp ( V_76 [ V_72 ] -> V_68 , V_71 ) == 0 )
V_2 = V_76 [ V_72 ] ;
if ( V_2 )
V_73 = F_46 ( V_2 ) ;
else
V_73 = - V_77 ;
F_45 ( & V_74 ) ;
return V_73 ;
}
static int F_46 ( struct V_1 * V_78 )
{
struct V_6 * V_79 ;
F_44 () ;
if ( V_78 -> V_80 != V_81 )
return - V_82 ;
V_2 = V_78 ;
V_2 -> V_31 = 0 ;
F_19 ( L_4 ) ;
if ( V_2 -> V_83 ( V_2 ) < 0 ) {
F_19 ( L_5 , V_78 -> V_68 ) ;
V_2 = NULL ;
return - V_77 ;
}
V_84 [ 0 ] . V_18 . V_19 . V_20 =
V_84 [ 0 ] . V_18 . V_19 . V_85 = V_2 -> V_86 ;
V_84 [ 1 ] . V_18 . V_19 . V_20 =
V_84 [ 1 ] . V_18 . V_19 . V_85 = V_2 -> V_87 ;
V_84 [ 2 ] . V_18 . V_19 . V_20 =
V_84 [ 2 ] . V_18 . V_19 . V_85 = V_2 -> V_21 ;
V_84 [ 3 ] . V_18 . V_19 . V_20 =
V_84 [ 3 ] . V_18 . V_19 . V_85 = V_2 -> V_88 ;
F_18 ( L_1 , V_2 -> V_32 ) ;
for ( V_79 = V_2 -> V_89 ;
( V_79 -> V_90 >= 0 ) && ( V_79 -> V_90 < V_91 ) ; V_79 ++ )
F_47 ( V_79 ) ;
if ( ! V_92 )
F_18 ( L_6 , V_2 -> V_33 ) ;
if ( V_2 -> V_93 . V_68 &&
F_48 ( V_94 , & V_2 -> V_93 ) < 0 )
return - V_95 ;
V_96 = V_2 -> V_4 ;
F_21 ( & V_35 ) ;
if ( V_41 )
F_27 ( V_41 ) ;
return 0 ;
}
void F_44 ( void )
{
struct V_6 * V_79 ;
unsigned long V_4 ;
if ( ! V_2 )
return;
F_3 ( & V_16 . V_17 , V_4 ) ;
F_49 ( L_7 , V_2 -> V_68 ) ;
V_2 -> V_31 = 0 ;
F_50 ( & V_38 ) ;
F_4 ( & V_16 . V_17 , V_4 ) ;
if ( V_2 -> V_93 . V_68 )
F_51 ( V_94 , & V_2 -> V_93 ) ;
for ( V_79 = V_2 -> V_89 ; V_79 -> V_90 != V_91 ; V_79 ++ )
F_52 ( V_79 -> V_90 ) ;
V_2 -> V_97 () ;
V_2 = NULL ;
}
int F_53 ( struct V_1 * V_78 )
{
int V_72 ;
int V_98 = 0 ;
F_43 ( & V_74 ) ;
for ( V_72 = 0 ; V_72 < V_75 && V_76 [ V_72 ] ; V_72 ++ )
if ( V_78 == V_76 [ V_72 ] ) {
F_45 ( & V_74 ) ;
return 0 ;
}
if ( V_72 == V_75 ) {
F_19 ( L_8 ) ;
F_45 ( & V_74 ) ;
return - 1 ;
}
V_76 [ V_72 ++ ] = V_78 ;
V_76 [ V_72 ] = NULL ;
if ( V_78 -> V_99 )
V_98 = F_46 ( V_78 ) ;
F_45 ( & V_74 ) ;
return V_98 ;
}
void F_54 ( struct V_1 * V_78 )
{
int V_72 ;
F_43 ( & V_74 ) ;
if ( V_2 == V_78 )
F_44 () ;
for ( V_72 = 0 ; V_76 [ V_72 ] ; V_72 ++ ) {
if ( V_78 == V_76 [ V_72 ] )
break;
}
for ( ; V_76 [ V_72 ] ; V_72 ++ )
V_76 [ V_72 ] = V_76 [ V_72 + 1 ] ;
V_100 = 0 ;
F_45 ( & V_74 ) ;
}
