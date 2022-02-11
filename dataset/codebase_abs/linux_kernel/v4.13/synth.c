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
V_2 -> V_26 -> V_30 () ;
V_2 -> V_26 -> V_27 ( V_2 , V_2 -> V_31 ) ;
}
unsigned char F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_26 -> V_32 () ;
}
int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_33 = 1 ;
return 1 ;
}
int F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 )
return 1 ;
if ( F_18 ( V_2 ) > 0 ) {
V_2 -> V_33 = 1 ;
F_19 ( L_1 , V_2 -> V_34 ) ;
return 2 ;
}
F_20 ( L_2 , V_2 -> V_35 ) ;
return 0 ;
}
static void F_21 ( T_2 V_36 )
{
F_22 ( & V_37 ) ;
}
void F_23 ( void )
{
struct V_6 * V_38 ;
if ( ! V_2 -> V_33 ) {
F_24 () ;
return;
}
V_38 = F_2 ( V_39 ) ;
if ( ! F_25 ( & V_40 ) )
F_26 ( & V_40 , V_21 +
F_11 ( V_38 -> V_18 . V_19 . V_20 ) ) ;
}
void F_27 ( void )
{
if ( ! V_2 )
return;
V_16 . V_22 = 1 ;
F_24 () ;
if ( V_2 -> V_33 ) {
if ( V_41 ) {
F_19 ( L_1 , V_42 ) ;
V_41 = 0 ;
}
}
F_22 ( & V_37 ) ;
F_28 ( V_43 ) ;
}
void F_29 ( const char * V_44 , T_3 V_45 )
{
while ( V_45 -- )
F_30 ( * V_44 ++ ) ;
F_23 () ;
}
void F_19 ( const char * V_46 , ... )
{
T_4 args ;
unsigned char V_44 [ 160 ] , * V_47 ;
int V_48 ;
va_start ( args , V_46 ) ;
V_48 = vsnprintf ( V_44 , sizeof( V_44 ) , V_46 , args ) ;
va_end ( args ) ;
if ( V_48 > sizeof( V_44 ) - 1 )
V_48 = sizeof( V_44 ) - 1 ;
V_47 = V_44 ;
while ( V_48 -- )
F_30 ( * V_47 ++ ) ;
F_23 () ;
}
void F_31 ( T_5 V_49 )
{
F_30 ( V_49 ) ;
}
void F_32 ( T_5 V_49 )
{
F_30 ( V_49 ) ;
F_23 () ;
}
void F_33 ( const T_5 * V_44 )
{
const T_5 * V_47 ;
for ( V_47 = V_44 ; * V_47 ; V_47 ++ )
F_30 ( * V_47 ) ;
}
void F_34 ( const T_5 * V_44 )
{
F_33 ( V_44 ) ;
F_23 () ;
}
void F_35 ( int V_50 )
{
static int V_51 = 1 ;
if ( V_51 )
V_51 = 0 ;
else
V_2 -> V_52 ( V_2 ) ;
V_53 = 0 ;
V_54 = V_50 ;
}
int F_36 ( void )
{
if ( V_2 -> V_52 )
return 1 ;
return 0 ;
}
void F_37 ( int V_55 )
{
int V_56 ;
if ( V_2 -> V_33 ) {
if ( V_55 == 0 ) {
V_2 -> V_57 . V_58 ++ ;
V_53 ++ ;
if ( V_2 -> V_57 . V_58 >
V_2 -> V_57 . V_59 )
V_2 -> V_57 . V_58 =
V_2 -> V_57 . V_60 ;
}
V_56 = V_2 -> V_57 . V_58 * 10 + V_55 ;
F_19 ( V_2 -> V_57 . V_61 , V_56 , V_56 ) ;
}
}
void F_38 ( int * V_62 , int * V_63 )
{
int V_64 = V_2 -> V_52 ( V_2 ) ;
if ( V_64 ) {
V_54 = V_64 % 10 ;
if ( ( V_64 / 10 ) <= V_2 -> V_57 . V_58 )
V_53 = V_2 -> V_57 . V_58 - ( V_64 / 10 ) ;
else
V_53 = V_2 -> V_57 . V_58
- V_2 -> V_57 . V_60
+ V_2 -> V_57 . V_59 - ( V_64 / 10 ) + 1 ;
}
* V_63 = V_54 ;
* V_62 = V_53 ;
}
int F_39 ( unsigned long V_65 , unsigned long V_19 )
{
struct V_66 * V_67 = & V_68 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 = V_2 -> V_70 ;
V_69 . V_65 = V_65 ;
V_69 . V_71 = V_65 + V_19 - 1 ;
V_69 . V_4 = V_72 ;
return F_40 ( V_67 , & V_69 ) ;
}
int F_41 ( unsigned long V_65 , unsigned long V_19 )
{
return F_42 ( & V_69 ) ;
}
int F_43 ( char * V_73 )
{
int V_74 ;
int V_75 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_73 )
return 0 ;
if ( strcmp ( V_73 , L_3 ) == 0 ) {
F_44 ( & V_76 ) ;
F_45 () ;
F_46 ( & V_76 ) ;
return 0 ;
}
F_44 ( & V_76 ) ;
for ( V_74 = 0 ; V_74 < V_77 && V_78 [ V_74 ] ; V_74 ++ )
if ( strcmp ( V_78 [ V_74 ] -> V_70 , V_73 ) == 0 )
V_2 = V_78 [ V_74 ] ;
if ( V_2 )
V_75 = F_47 ( V_2 ) ;
else
V_75 = - V_79 ;
F_46 ( & V_76 ) ;
return V_75 ;
}
static int F_47 ( struct V_1 * V_80 )
{
struct V_6 * V_81 ;
F_45 () ;
if ( V_80 -> V_82 != V_83 )
return - V_84 ;
V_2 = V_80 ;
V_2 -> V_33 = 0 ;
F_20 ( L_4 ) ;
if ( V_2 -> V_85 ( V_2 ) < 0 ) {
F_20 ( L_5 , V_80 -> V_70 ) ;
V_2 = NULL ;
return - V_79 ;
}
V_86 [ 0 ] . V_18 . V_19 . V_20 =
V_86 [ 0 ] . V_18 . V_19 . V_87 = V_2 -> V_88 ;
V_86 [ 1 ] . V_18 . V_19 . V_20 =
V_86 [ 1 ] . V_18 . V_19 . V_87 = V_2 -> V_89 ;
V_86 [ 2 ] . V_18 . V_19 . V_20 =
V_86 [ 2 ] . V_18 . V_19 . V_87 = V_2 -> V_21 ;
V_86 [ 3 ] . V_18 . V_19 . V_20 =
V_86 [ 3 ] . V_18 . V_19 . V_87 = V_2 -> V_90 ;
F_19 ( L_1 , V_2 -> V_34 ) ;
for ( V_81 = V_2 -> V_91 ;
( V_81 -> V_92 >= 0 ) && ( V_81 -> V_92 < V_93 ) ; V_81 ++ )
F_48 ( V_81 ) ;
if ( ! V_94 )
F_19 ( L_6 , V_2 -> V_35 ) ;
if ( V_2 -> V_95 . V_70 &&
F_49 ( V_96 , & V_2 -> V_95 ) < 0 )
return - V_97 ;
V_98 = V_2 -> V_4 ;
F_22 ( & V_37 ) ;
if ( V_43 )
F_28 ( V_43 ) ;
return 0 ;
}
void F_45 ( void )
{
struct V_6 * V_81 ;
unsigned long V_4 ;
if ( ! V_2 )
return;
F_3 ( & V_16 . V_17 , V_4 ) ;
F_50 ( L_7 , V_2 -> V_70 ) ;
V_2 -> V_33 = 0 ;
F_51 ( & V_40 ) ;
F_4 ( & V_16 . V_17 , V_4 ) ;
if ( V_2 -> V_95 . V_70 )
F_52 ( V_96 , & V_2 -> V_95 ) ;
for ( V_81 = V_2 -> V_91 ; V_81 -> V_92 != V_93 ; V_81 ++ )
F_53 ( V_81 -> V_92 ) ;
V_2 -> V_99 () ;
V_2 = NULL ;
}
int F_54 ( struct V_1 * V_80 )
{
int V_74 ;
int V_100 = 0 ;
F_44 ( & V_76 ) ;
for ( V_74 = 0 ; V_74 < V_77 && V_78 [ V_74 ] ; V_74 ++ )
if ( V_80 == V_78 [ V_74 ] ) {
F_46 ( & V_76 ) ;
return 0 ;
}
if ( V_74 == V_77 ) {
F_20 ( L_8 ) ;
F_46 ( & V_76 ) ;
return - 1 ;
}
if ( V_80 -> V_101 )
V_100 = F_47 ( V_80 ) ;
if ( ! V_100 ) {
V_78 [ V_74 ++ ] = V_80 ;
V_78 [ V_74 ] = NULL ;
}
F_46 ( & V_76 ) ;
return V_100 ;
}
void F_55 ( struct V_1 * V_80 )
{
int V_74 ;
F_44 ( & V_76 ) ;
if ( V_2 == V_80 )
F_45 () ;
for ( V_74 = 0 ; V_78 [ V_74 ] ; V_74 ++ ) {
if ( V_80 == V_78 [ V_74 ] )
break;
}
for ( ; V_78 [ V_74 ] ; V_74 ++ )
V_78 [ V_74 ] = V_78 [ V_74 + 1 ] ;
V_102 = 0 ;
F_46 ( & V_76 ) ;
}
