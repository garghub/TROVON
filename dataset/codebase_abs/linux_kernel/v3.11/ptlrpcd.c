void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 != NULL ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_1 * V_2 , T_1 V_7 , int V_8 )
{
int V_9 = 0 ;
if ( V_2 != NULL && V_2 -> V_10 != V_11 )
return & V_12 -> V_13 ;
switch ( V_7 ) {
case V_14 :
V_9 = F_5 () % V_12 -> V_15 ;
break;
case V_16 :
# ifdef F_6
# warning "fix this code to use new CPU partition APIs"
# endif
V_8 = - 1 ;
case V_17 :
if ( V_8 >= 0 && V_8 < F_7 () ) {
V_9 = V_8 % V_12 -> V_15 ;
break;
}
default:
case V_18 :
V_9 = V_12 -> V_19 + 1 ;
if ( V_9 == F_5 () )
V_9 ++ ;
V_9 %= V_12 -> V_15 ;
V_12 -> V_19 = V_9 ;
break;
}
return & V_12 -> V_20 [ V_9 ] ;
}
void F_8 ( struct V_3 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
struct V_6 * V_25 ;
struct V_3 * V_26 ;
int V_27 , V_28 ;
V_25 = F_4 ( NULL , V_16 , - 1 ) ;
V_26 = V_25 -> V_29 ;
F_9 (pos, tmp, &set->set_requests) {
struct V_1 * V_2 =
F_10 ( V_24 , struct V_1 ,
V_30 ) ;
F_2 ( V_2 -> V_31 == V_32 ) ;
V_2 -> V_4 = V_26 ;
V_2 -> V_33 = F_11 () ;
}
F_12 ( & V_26 -> V_34 ) ;
F_13 ( & V_21 -> V_35 , & V_26 -> V_36 ) ;
V_28 = F_14 ( & V_21 -> V_37 ) ;
V_27 = F_15 ( V_28 , & V_26 -> V_38 ) ;
F_16 ( & V_21 -> V_37 , 0 ) ;
F_17 ( & V_26 -> V_34 ) ;
if ( V_27 == V_28 ) {
F_3 ( & V_26 -> V_5 ) ;
for ( V_28 = 0 ; V_28 < V_25 -> V_39 ; V_28 ++ )
F_3 ( & V_25 -> V_40 [ V_28 ] -> V_29 -> V_5 ) ;
}
}
static int F_18 ( struct V_3 * V_41 ,
struct V_3 * V_42 )
{
struct V_22 * V_23 , * V_24 ;
struct V_1 * V_2 ;
int V_43 = 0 ;
F_12 ( & V_42 -> V_34 ) ;
if ( F_19 ( ! F_20 ( & V_42 -> V_36 ) ) ) {
F_9 (pos, tmp, &src->set_new_requests) {
V_2 = F_10 ( V_24 , struct V_1 ,
V_30 ) ;
V_2 -> V_4 = V_41 ;
}
F_13 ( & V_42 -> V_36 ,
& V_41 -> V_35 ) ;
V_43 = F_14 ( & V_42 -> V_38 ) ;
F_21 ( V_43 , & V_41 -> V_37 ) ;
F_16 ( & V_42 -> V_38 , 0 ) ;
}
F_17 ( & V_42 -> V_34 ) ;
return V_43 ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_7 , int V_9 )
{
struct V_6 * V_25 ;
if ( V_2 -> V_44 )
F_23 ( V_2 -> V_44 , NULL ) ;
F_12 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_46 ) {
struct V_47 V_48 = F_24 ( F_25 ( 5 ) ,
V_49 , NULL ) ;
V_2 -> V_46 = 0 ;
F_17 ( & V_2 -> V_45 ) ;
F_26 ( V_2 -> V_50 , ( V_2 -> V_4 == NULL ) , & V_48 ) ;
} else if ( V_2 -> V_4 ) {
F_2 ( V_2 -> V_31 == V_32 ) ;
F_2 ( V_2 -> V_10 == V_51 ) ;
F_27 ( & V_2 -> V_4 -> V_37 ) ;
F_17 ( & V_2 -> V_45 ) ;
F_3 ( & V_2 -> V_4 -> V_5 ) ;
return;
} else {
F_17 ( & V_2 -> V_45 ) ;
}
V_25 = F_4 ( V_2 , V_7 , V_9 ) ;
F_28 ( V_52 , V_2 , L_1 ,
V_2 , V_25 -> V_53 , V_25 -> V_54 ) ;
F_29 ( V_25 , V_2 ) ;
}
static inline void F_30 ( struct V_3 * V_21 )
{
F_27 ( & V_21 -> V_55 ) ;
}
static int F_31 ( struct V_56 * V_57 , struct V_6 * V_25 )
{
struct V_22 * V_23 , * V_24 ;
struct V_1 * V_2 ;
struct V_3 * V_21 = V_25 -> V_29 ;
int V_43 = 0 ;
int V_58 ;
V_59 ;
if ( F_14 ( & V_21 -> V_38 ) ) {
F_12 ( & V_21 -> V_34 ) ;
if ( F_19 ( ! F_20 ( & V_21 -> V_36 ) ) ) {
F_13 ( & V_21 -> V_36 ,
& V_21 -> V_35 ) ;
F_21 ( F_14 ( & V_21 -> V_38 ) ,
& V_21 -> V_37 ) ;
F_16 ( & V_21 -> V_38 , 0 ) ;
V_43 = 1 ;
}
F_17 ( & V_21 -> V_34 ) ;
}
V_58 = F_32 ( V_57 ) ;
if ( V_58 != 0 ) {
F_33 ( L_2 , V_58 ) ;
RETURN ( V_43 ) ;
}
if ( F_14 ( & V_21 -> V_37 ) )
V_43 |= F_34 ( V_57 , V_21 ) ;
if ( ! F_20 ( & V_21 -> V_35 ) ) {
F_9 (pos, tmp, &set->set_requests) {
V_2 = F_10 ( V_24 , struct V_1 ,
V_30 ) ;
if ( V_2 -> V_31 != V_60 )
continue;
F_35 ( & V_2 -> V_30 ) ;
V_2 -> V_4 = NULL ;
F_36 ( V_2 ) ;
}
}
if ( V_43 == 0 ) {
V_43 = F_14 ( & V_21 -> V_38 ) ;
if ( V_43 == 0 && V_25 -> V_39 > 0 ) {
struct V_6 * V_61 ;
struct V_3 * V_62 ;
int V_63 = V_25 -> V_64 ;
do {
V_61 = V_25 -> V_40 [ V_25 -> V_64 ++ ] ;
if ( V_25 -> V_64 >= V_25 -> V_39 )
V_25 -> V_64 = 0 ;
if ( V_61 == NULL )
continue;
F_12 ( & V_61 -> V_65 ) ;
V_62 = V_61 -> V_29 ;
if ( V_62 == NULL ) {
F_17 ( & V_61 -> V_65 ) ;
continue;
}
F_30 ( V_62 ) ;
F_17 ( & V_61 -> V_65 ) ;
if ( F_14 ( & V_62 -> V_38 ) ) {
V_43 = F_18 ( V_21 , V_62 ) ;
if ( V_43 > 0 )
F_37 ( V_66 , L_3
L_4 ,
V_43 , V_61 -> V_54 ,
V_25 -> V_54 ) ;
}
F_38 ( V_62 ) ;
} while ( V_43 == 0 && V_25 -> V_64 != V_63 );
}
}
RETURN ( V_43 ) ;
}
static int F_39 ( void * V_67 )
{
struct V_6 * V_25 = V_67 ;
struct V_3 * V_21 = V_25 -> V_29 ;
struct V_56 V_57 = { . V_68 = NULL } ;
int V_43 , exit = 0 ;
V_59 ;
F_40 () ;
#if F_41 ( V_69 )
if ( F_42 ( V_70 , & V_25 -> V_71 ) ) {
int V_8 = V_25 -> V_54 ;
if ( V_8 >= 0 && V_8 < F_43 () ) {
while ( ! F_44 ( V_8 ) ) {
if ( ++ V_8 >= F_43 () )
V_8 = 0 ;
}
F_45 ( V_72 ,
F_46 ( F_47 ( V_8 ) ) ) ;
}
}
#endif
V_43 = F_48 ( & V_57 . V_73 ,
V_74 | V_75 | V_76 ) ;
F_49 ( & V_25 -> V_77 ) ;
if ( V_43 != 0 )
RETURN ( V_43 ) ;
do {
struct V_47 V_48 ;
int V_78 ;
V_78 = F_50 ( V_21 ) ;
V_48 = F_24 ( F_25 ( V_78 ? V_78 : 1 ) ,
V_79 , V_21 ) ;
F_51 ( & V_57 . V_73 ) ;
F_26 ( V_21 -> V_5 ,
F_31 ( & V_57 , V_25 ) , & V_48 ) ;
F_52 ( & V_57 . V_73 ) ;
if ( F_42 ( V_80 , & V_25 -> V_71 ) ) {
if ( F_42 ( V_81 , & V_25 -> V_71 ) )
F_53 ( V_21 ) ;
exit ++ ;
}
} while ( exit < 2 );
if ( ! F_20 ( & V_21 -> V_35 ) )
F_54 ( V_21 ) ;
F_55 ( & V_57 . V_73 ) ;
F_49 ( & V_25 -> V_82 ) ;
return 0 ;
}
static int F_56 ( int V_8 , int V_83 )
{
struct V_6 * V_25 ;
int V_43 = 0 ;
#if F_41 ( V_84 )
T_2 V_85 ;
#endif
V_59 ;
F_2 ( V_8 <= V_83 - 1 ) ;
V_25 = & V_12 -> V_20 [ V_8 ] ;
switch ( V_86 ) {
case V_87 :
V_25 -> V_39 = - 1 ;
break;
case V_88 :
V_25 -> V_39 = 0 ;
F_57 ( V_70 , & V_25 -> V_71 ) ;
break;
case V_89 :
F_2 ( V_83 % 2 == 0 ) ;
V_25 -> V_39 = 1 ;
break;
case V_90 :
#if F_41 ( V_84 )
{
int V_28 ;
V_85 = * F_46 ( F_47 ( V_8 ) ) ;
for ( V_28 = V_83 ; V_28 < F_7 () ; V_28 ++ )
F_58 ( V_28 , V_85 ) ;
V_25 -> V_39 = F_59 ( V_85 ) - 1 ;
F_57 ( V_70 , & V_25 -> V_71 ) ;
}
#else
F_2 ( V_83 >= 3 ) ;
V_25 -> V_39 = 2 ;
#endif
break;
default:
F_33 ( L_5 , V_86 ) ;
V_43 = - V_91 ;
}
if ( V_43 == 0 && V_25 -> V_39 > 0 ) {
F_60 ( V_25 -> V_40 ,
sizeof( struct V_6 * ) * V_25 -> V_39 ) ;
if ( V_25 -> V_40 == NULL ) {
V_25 -> V_39 = 0 ;
V_43 = - V_92 ;
} else {
switch ( V_86 ) {
case V_89 :
if ( V_8 & 0x1 ) {
F_57 ( V_70 , & V_25 -> V_71 ) ;
V_25 -> V_40 [ 0 ] = & V_12 ->
V_20 [ V_8 - 1 ] ;
V_12 -> V_20 [ V_8 - 1 ] .
V_40 [ 0 ] = V_25 ;
}
break;
case V_90 :
#if F_41 ( V_84 )
{
struct V_6 * V_93 ;
int V_28 , V_94 ;
for ( V_94 = 0 , V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
if ( F_61 ( V_28 , V_85 ) ) {
V_93 = & V_12 -> V_20 [ V_28 ] ;
V_25 -> V_40 [ V_94 ++ ] = V_93 ;
V_93 -> V_40 [ V_93 ->
V_39 ++ ] = V_25 ;
}
}
V_25 -> V_39 = V_94 ;
}
#else
if ( V_8 & 0x1 )
F_57 ( V_70 , & V_25 -> V_71 ) ;
if ( V_8 > 0 ) {
V_25 -> V_40 [ 0 ] = & V_12 ->
V_20 [ V_8 - 1 ] ;
V_12 -> V_20 [ V_8 - 1 ] .
V_40 [ 1 ] = V_25 ;
if ( V_8 == V_83 - 1 ) {
V_25 -> V_40 [ 1 ] =
& V_12 -> V_20 [ 0 ] ;
V_12 -> V_20 [ 0 ] .
V_40 [ 0 ] = V_25 ;
}
}
#endif
break;
}
}
}
RETURN ( V_43 ) ;
}
int F_62 ( int V_8 , int V_83 , const char * V_95 , struct V_6 * V_25 )
{
int V_43 ;
int V_57 = 0 ;
V_59 ;
if ( F_63 ( V_96 , & V_25 -> V_71 ) ) {
F_64 ( L_6 ,
V_95 , V_25 ) ;
RETURN ( 0 ) ;
}
V_25 -> V_54 = V_8 ;
F_65 ( & V_25 -> V_77 ) ;
F_65 ( & V_25 -> V_82 ) ;
F_66 ( & V_25 -> V_65 ) ;
strncpy ( V_25 -> V_53 , V_95 , sizeof( V_25 -> V_53 ) - 1 ) ;
V_25 -> V_29 = F_67 () ;
if ( V_25 -> V_29 == NULL )
GOTO ( V_97 , V_43 = - V_92 ) ;
V_43 = F_48 ( & V_25 -> V_98 . V_73 , V_74 | V_75 ) ;
if ( V_43 != 0 )
GOTO ( V_97 , V_43 ) ;
V_57 = 1 ;
{
T_3 * V_99 ;
if ( V_8 >= 0 ) {
V_43 = F_56 ( V_8 , V_83 ) ;
if ( V_43 < 0 )
GOTO ( V_97 , V_43 ) ;
}
V_99 = F_68 ( F_39 , V_25 , V_25 -> V_53 ) ;
if ( F_69 ( V_99 ) )
GOTO ( V_97 , V_43 = F_70 ( V_99 ) ) ;
V_43 = 0 ;
F_71 ( & V_25 -> V_77 ) ;
}
V_97:
if ( V_43 ) {
if ( V_25 -> V_29 != NULL ) {
struct V_3 * V_21 = V_25 -> V_29 ;
F_12 ( & V_25 -> V_65 ) ;
V_25 -> V_29 = NULL ;
F_17 ( & V_25 -> V_65 ) ;
F_72 ( V_21 ) ;
}
if ( V_57 != 0 )
F_55 ( & V_25 -> V_98 . V_73 ) ;
F_73 ( V_70 , & V_25 -> V_71 ) ;
F_73 ( V_96 , & V_25 -> V_71 ) ;
}
RETURN ( V_43 ) ;
}
void F_74 ( struct V_6 * V_25 , int V_100 )
{
V_59 ;
if ( ! F_42 ( V_96 , & V_25 -> V_71 ) ) {
F_64 ( L_7 , V_25 ) ;
goto V_97;
}
F_57 ( V_80 , & V_25 -> V_71 ) ;
if ( V_100 )
F_57 ( V_81 , & V_25 -> V_71 ) ;
F_3 ( & V_25 -> V_29 -> V_5 ) ;
V_97:
EXIT ;
}
void F_75 ( struct V_6 * V_25 )
{
struct V_3 * V_21 = V_25 -> V_29 ;
V_59 ;
if ( ! F_42 ( V_96 , & V_25 -> V_71 ) ) {
F_64 ( L_7 , V_25 ) ;
goto V_97;
}
F_71 ( & V_25 -> V_82 ) ;
F_55 ( & V_25 -> V_98 . V_73 ) ;
F_12 ( & V_25 -> V_65 ) ;
V_25 -> V_29 = NULL ;
F_17 ( & V_25 -> V_65 ) ;
F_72 ( V_21 ) ;
F_73 ( V_96 , & V_25 -> V_71 ) ;
F_73 ( V_80 , & V_25 -> V_71 ) ;
F_73 ( V_81 , & V_25 -> V_71 ) ;
F_73 ( V_70 , & V_25 -> V_71 ) ;
V_97:
if ( V_25 -> V_39 > 0 ) {
F_2 ( V_25 -> V_40 != NULL ) ;
F_76 ( V_25 -> V_40 ,
sizeof( struct V_6 * ) * V_25 -> V_39 ) ;
V_25 -> V_40 = NULL ;
}
V_25 -> V_39 = 0 ;
EXIT ;
}
static void F_77 ( void )
{
int V_28 ;
V_59 ;
if ( V_12 != NULL ) {
for ( V_28 = 0 ; V_28 < V_12 -> V_15 ; V_28 ++ )
F_74 ( & V_12 -> V_20 [ V_28 ] , 0 ) ;
for ( V_28 = 0 ; V_28 < V_12 -> V_15 ; V_28 ++ )
F_75 ( & V_12 -> V_20 [ V_28 ] ) ;
F_74 ( & V_12 -> V_13 , 0 ) ;
F_75 ( & V_12 -> V_13 ) ;
F_76 ( V_12 , V_12 -> V_101 ) ;
V_12 = NULL ;
}
EXIT ;
}
static int F_78 ( void )
{
int V_102 = F_7 () ;
char V_95 [ 16 ] ;
int V_103 , V_28 = - 1 , V_104 , V_43 = 0 ;
V_59 ;
if ( V_105 > 0 && V_105 < V_102 )
V_102 = V_105 ;
if ( V_102 < 2 )
V_102 = 2 ;
if ( V_102 < 3 && V_86 == V_90 )
V_86 = V_89 ;
else if ( V_102 % 2 != 0 && V_86 == V_89 )
V_102 &= ~ 1 ;
V_103 = F_79 ( struct F_39 , V_20 [ V_102 ] ) ;
F_60 ( V_12 , V_103 ) ;
if ( V_12 == NULL )
GOTO ( V_97 , V_43 = - V_92 ) ;
snprintf ( V_95 , 15 , L_8 ) ;
F_57 ( V_106 , & V_12 -> V_13 . V_71 ) ;
V_43 = F_62 ( - 1 , V_102 , V_95 , & V_12 -> V_13 ) ;
if ( V_43 < 0 )
GOTO ( V_97 , V_43 ) ;
for ( V_28 = 0 ; V_28 < V_102 ; V_28 ++ ) {
snprintf ( V_95 , 15 , L_9 , V_28 ) ;
V_43 = F_62 ( V_28 , V_102 , V_95 , & V_12 -> V_20 [ V_28 ] ) ;
if ( V_43 < 0 )
GOTO ( V_97 , V_43 ) ;
}
V_12 -> V_101 = V_103 ;
V_12 -> V_19 = 0 ;
V_12 -> V_15 = V_102 ;
V_97:
if ( V_43 != 0 && V_12 != NULL ) {
for ( V_104 = 0 ; V_104 <= V_28 ; V_104 ++ )
F_74 ( & V_12 -> V_20 [ V_104 ] , 0 ) ;
for ( V_104 = 0 ; V_104 <= V_28 ; V_104 ++ )
F_75 ( & V_12 -> V_20 [ V_104 ] ) ;
F_74 ( & V_12 -> V_13 , 0 ) ;
F_75 ( & V_12 -> V_13 ) ;
F_76 ( V_12 , V_103 ) ;
V_12 = NULL ;
}
RETURN ( 0 ) ;
}
int F_80 ( void )
{
int V_43 = 0 ;
V_59 ;
F_81 ( & V_107 ) ;
if ( ++ V_108 == 1 )
V_43 = F_78 () ;
F_82 ( & V_107 ) ;
RETURN ( V_43 ) ;
}
void F_83 ( void )
{
F_81 ( & V_107 ) ;
if ( -- V_108 == 0 )
F_77 () ;
F_82 ( & V_107 ) ;
}
