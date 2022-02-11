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
return V_43 ;
}
if ( F_14 ( & V_21 -> V_37 ) )
V_43 |= F_34 ( V_57 , V_21 ) ;
F_9 (pos, tmp, &set->set_requests) {
V_2 = F_10 ( V_24 , struct V_1 , V_30 ) ;
if ( V_2 -> V_31 != V_59 )
break;
F_35 ( & V_2 -> V_30 ) ;
V_2 -> V_4 = NULL ;
F_36 ( V_2 ) ;
}
if ( V_43 == 0 ) {
V_43 = F_14 ( & V_21 -> V_38 ) ;
if ( V_43 == 0 && V_25 -> V_39 > 0 ) {
struct V_6 * V_60 ;
struct V_3 * V_61 ;
int V_62 = V_25 -> V_63 ;
do {
V_60 = V_25 -> V_40 [ V_25 -> V_63 ++ ] ;
if ( V_25 -> V_63 >= V_25 -> V_39 )
V_25 -> V_63 = 0 ;
if ( V_60 == NULL )
continue;
F_12 ( & V_60 -> V_64 ) ;
V_61 = V_60 -> V_29 ;
if ( V_61 == NULL ) {
F_17 ( & V_60 -> V_64 ) ;
continue;
}
F_30 ( V_61 ) ;
F_17 ( & V_60 -> V_64 ) ;
if ( F_14 ( & V_61 -> V_38 ) ) {
V_43 = F_18 ( V_21 , V_61 ) ;
if ( V_43 > 0 )
F_37 ( V_65 , L_3 ,
V_43 , V_60 -> V_54 ,
V_25 -> V_54 ) ;
}
F_38 ( V_61 ) ;
} while ( V_43 == 0 && V_25 -> V_63 != V_62 );
}
}
return V_43 ;
}
static int F_39 ( void * V_66 )
{
struct V_6 * V_25 = V_66 ;
struct V_3 * V_21 = V_25 -> V_29 ;
struct V_56 V_57 = { . V_67 = NULL } ;
int V_43 , exit = 0 ;
F_40 () ;
#if F_41 ( V_68 )
if ( F_42 ( V_69 , & V_25 -> V_70 ) ) {
int V_8 = V_25 -> V_54 ;
if ( V_8 >= 0 && V_8 < F_43 () ) {
while ( ! F_44 ( V_8 ) ) {
if ( ++ V_8 >= F_43 () )
V_8 = 0 ;
}
F_45 ( V_71 ,
F_46 ( F_47 ( V_8 ) ) ) ;
}
}
#endif
V_43 = F_48 ( & V_57 . V_72 ,
V_73 | V_74 | V_75 ) ;
F_49 ( & V_25 -> V_76 ) ;
if ( V_43 != 0 )
return V_43 ;
do {
struct V_47 V_48 ;
int V_77 ;
V_77 = F_50 ( V_21 ) ;
V_48 = F_24 ( F_25 ( V_77 ? V_77 : 1 ) ,
V_78 , V_21 ) ;
F_51 ( & V_57 . V_72 ) ;
F_26 ( V_21 -> V_5 ,
F_31 ( & V_57 , V_25 ) , & V_48 ) ;
F_52 ( & V_57 . V_72 ) ;
if ( F_42 ( V_79 , & V_25 -> V_70 ) ) {
if ( F_42 ( V_80 , & V_25 -> V_70 ) )
F_53 ( V_21 ) ;
exit ++ ;
}
} while ( exit < 2 );
if ( ! F_20 ( & V_21 -> V_35 ) )
F_54 ( V_21 ) ;
F_55 ( & V_57 . V_72 ) ;
F_49 ( & V_25 -> V_81 ) ;
return 0 ;
}
static int F_56 ( int V_8 , int V_82 )
{
struct V_6 * V_25 ;
int V_43 = 0 ;
#if F_41 ( V_83 )
T_2 V_84 ;
#endif
F_2 ( V_8 <= V_82 - 1 ) ;
V_25 = & V_12 -> V_20 [ V_8 ] ;
switch ( V_85 ) {
case V_86 :
V_25 -> V_39 = - 1 ;
break;
case V_87 :
V_25 -> V_39 = 0 ;
F_57 ( V_69 , & V_25 -> V_70 ) ;
break;
case V_88 :
F_2 ( V_82 % 2 == 0 ) ;
V_25 -> V_39 = 1 ;
break;
case V_89 :
#if F_41 ( V_83 )
{
int V_28 ;
F_58 ( & V_84 , F_46 ( F_47 ( V_8 ) ) ) ;
for ( V_28 = V_82 ; V_28 < F_7 () ; V_28 ++ )
F_59 ( V_28 , & V_84 ) ;
V_25 -> V_39 = F_60 ( & V_84 ) - 1 ;
F_57 ( V_69 , & V_25 -> V_70 ) ;
}
#else
F_2 ( V_82 >= 3 ) ;
V_25 -> V_39 = 2 ;
#endif
break;
default:
F_33 ( L_4 , V_85 ) ;
V_43 = - V_90 ;
}
if ( V_43 == 0 && V_25 -> V_39 > 0 ) {
F_61 ( V_25 -> V_40 ,
sizeof( struct V_6 * ) * V_25 -> V_39 ) ;
if ( V_25 -> V_40 == NULL ) {
V_25 -> V_39 = 0 ;
V_43 = - V_91 ;
} else {
switch ( V_85 ) {
case V_88 :
if ( V_8 & 0x1 ) {
F_57 ( V_69 , & V_25 -> V_70 ) ;
V_25 -> V_40 [ 0 ] = & V_12 ->
V_20 [ V_8 - 1 ] ;
V_12 -> V_20 [ V_8 - 1 ] .
V_40 [ 0 ] = V_25 ;
}
break;
case V_89 :
#if F_41 ( V_83 )
{
struct V_6 * V_92 ;
int V_28 , V_93 ;
for ( V_93 = 0 , V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
if ( F_62 ( V_28 , & V_84 ) ) {
V_92 = & V_12 -> V_20 [ V_28 ] ;
V_25 -> V_40 [ V_93 ++ ] = V_92 ;
V_92 -> V_40 [ V_92 ->
V_39 ++ ] = V_25 ;
}
}
V_25 -> V_39 = V_93 ;
}
#else
if ( V_8 & 0x1 )
F_57 ( V_69 , & V_25 -> V_70 ) ;
if ( V_8 > 0 ) {
V_25 -> V_40 [ 0 ] = & V_12 ->
V_20 [ V_8 - 1 ] ;
V_12 -> V_20 [ V_8 - 1 ] .
V_40 [ 1 ] = V_25 ;
if ( V_8 == V_82 - 1 ) {
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
return V_43 ;
}
int F_63 ( int V_8 , int V_82 , const char * V_94 , struct V_6 * V_25 )
{
int V_43 ;
if ( F_64 ( V_95 , & V_25 -> V_70 ) ) {
F_65 ( L_5 ,
V_94 , V_25 ) ;
return 0 ;
}
V_25 -> V_54 = V_8 ;
F_66 ( & V_25 -> V_76 ) ;
F_66 ( & V_25 -> V_81 ) ;
F_67 ( & V_25 -> V_64 ) ;
F_68 ( V_25 -> V_53 , V_94 , sizeof( V_25 -> V_53 ) ) ;
V_25 -> V_29 = F_69 () ;
if ( V_25 -> V_29 == NULL ) {
V_43 = - V_91 ;
goto V_96;
}
V_43 = F_48 ( & V_25 -> V_97 . V_72 , V_73 | V_74 ) ;
if ( V_43 != 0 )
goto V_98;
{
struct V_99 * V_100 ;
if ( V_8 >= 0 ) {
V_43 = F_56 ( V_8 , V_82 ) ;
if ( V_43 < 0 )
goto V_101;
}
V_100 = F_70 ( F_39 , V_25 , L_6 , V_25 -> V_53 ) ;
if ( F_71 ( V_100 ) ) {
V_43 = F_72 ( V_100 ) ;
goto V_101;
}
F_73 ( & V_25 -> V_76 ) ;
}
return 0 ;
V_101:
F_55 ( & V_25 -> V_97 . V_72 ) ;
V_98:
if ( V_25 -> V_29 != NULL ) {
struct V_3 * V_21 = V_25 -> V_29 ;
F_12 ( & V_25 -> V_64 ) ;
V_25 -> V_29 = NULL ;
F_17 ( & V_25 -> V_64 ) ;
F_74 ( V_21 ) ;
}
F_75 ( V_69 , & V_25 -> V_70 ) ;
V_96:
F_75 ( V_95 , & V_25 -> V_70 ) ;
return V_43 ;
}
void F_76 ( struct V_6 * V_25 , int V_102 )
{
if ( ! F_42 ( V_95 , & V_25 -> V_70 ) ) {
F_65 ( L_7 , V_25 ) ;
return;
}
F_57 ( V_79 , & V_25 -> V_70 ) ;
if ( V_102 )
F_57 ( V_80 , & V_25 -> V_70 ) ;
F_3 ( & V_25 -> V_29 -> V_5 ) ;
}
void F_77 ( struct V_6 * V_25 )
{
struct V_3 * V_21 = V_25 -> V_29 ;
if ( ! F_42 ( V_95 , & V_25 -> V_70 ) ) {
F_65 ( L_7 , V_25 ) ;
goto V_96;
}
F_73 ( & V_25 -> V_81 ) ;
F_55 ( & V_25 -> V_97 . V_72 ) ;
F_12 ( & V_25 -> V_64 ) ;
V_25 -> V_29 = NULL ;
F_17 ( & V_25 -> V_64 ) ;
F_74 ( V_21 ) ;
F_75 ( V_95 , & V_25 -> V_70 ) ;
F_75 ( V_79 , & V_25 -> V_70 ) ;
F_75 ( V_80 , & V_25 -> V_70 ) ;
F_75 ( V_69 , & V_25 -> V_70 ) ;
V_96:
if ( V_25 -> V_39 > 0 ) {
F_2 ( V_25 -> V_40 != NULL ) ;
F_78 ( V_25 -> V_40 ,
sizeof( struct V_6 * ) * V_25 -> V_39 ) ;
V_25 -> V_40 = NULL ;
}
V_25 -> V_39 = 0 ;
}
static void F_79 ( void )
{
int V_28 ;
if ( V_12 != NULL ) {
for ( V_28 = 0 ; V_28 < V_12 -> V_15 ; V_28 ++ )
F_76 ( & V_12 -> V_20 [ V_28 ] , 0 ) ;
for ( V_28 = 0 ; V_28 < V_12 -> V_15 ; V_28 ++ )
F_77 ( & V_12 -> V_20 [ V_28 ] ) ;
F_76 ( & V_12 -> V_13 , 0 ) ;
F_77 ( & V_12 -> V_13 ) ;
F_78 ( V_12 , V_12 -> V_103 ) ;
V_12 = NULL ;
}
}
static int F_80 ( void )
{
int V_104 = F_7 () ;
char V_94 [ 16 ] ;
int V_105 , V_28 = - 1 , V_106 , V_43 = 0 ;
if ( V_107 > 0 && V_107 < V_104 )
V_104 = V_107 ;
if ( V_104 < 2 )
V_104 = 2 ;
if ( V_104 < 3 && V_85 == V_89 )
V_85 = V_88 ;
else if ( V_104 % 2 != 0 && V_85 == V_88 )
V_104 &= ~ 1 ;
V_105 = F_81 ( struct F_39 , V_20 [ V_104 ] ) ;
F_61 ( V_12 , V_105 ) ;
if ( V_12 == NULL ) {
V_43 = - V_91 ;
goto V_96;
}
snprintf ( V_94 , sizeof( V_94 ) , L_8 ) ;
F_57 ( V_108 , & V_12 -> V_13 . V_70 ) ;
V_43 = F_63 ( - 1 , V_104 , V_94 , & V_12 -> V_13 ) ;
if ( V_43 < 0 )
goto V_96;
for ( V_28 = 0 ; V_28 < V_104 ; V_28 ++ ) {
snprintf ( V_94 , sizeof( V_94 ) , L_9 , V_28 ) ;
V_43 = F_63 ( V_28 , V_104 , V_94 , & V_12 -> V_20 [ V_28 ] ) ;
if ( V_43 < 0 )
goto V_96;
}
V_12 -> V_103 = V_105 ;
V_12 -> V_19 = 0 ;
V_12 -> V_15 = V_104 ;
V_96:
if ( V_43 != 0 && V_12 != NULL ) {
for ( V_106 = 0 ; V_106 <= V_28 ; V_106 ++ )
F_76 ( & V_12 -> V_20 [ V_106 ] , 0 ) ;
for ( V_106 = 0 ; V_106 <= V_28 ; V_106 ++ )
F_77 ( & V_12 -> V_20 [ V_106 ] ) ;
F_76 ( & V_12 -> V_13 , 0 ) ;
F_77 ( & V_12 -> V_13 ) ;
F_78 ( V_12 , V_105 ) ;
V_12 = NULL ;
}
return 0 ;
}
int F_82 ( void )
{
int V_43 = 0 ;
F_83 ( & V_109 ) ;
if ( ++ V_110 == 1 )
V_43 = F_80 () ;
F_84 ( & V_109 ) ;
return V_43 ;
}
void F_85 ( void )
{
F_83 ( & V_109 ) ;
if ( -- V_110 == 0 )
F_79 () ;
F_84 ( & V_109 ) ;
}
