void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 )
{
F_2 ( V_2 ) ;
F_3 ( V_6 , V_4 ) ;
F_4 ( V_2 ) ;
}
struct V_3 * F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 ;
F_2 ( V_2 ) ;
V_4 = F_6 ( V_6 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_8 ( & V_2 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_2 -> V_10 [ V_7 ] . V_11 ) {
F_9 ( V_2 -> V_10 [ V_7 ] . V_11 ) ;
}
}
if ( F_10 ( & V_2 -> V_12 ) ) {
F_11 ( & V_2 -> V_12 ) ;
}
if ( F_10 ( & V_2 -> V_13 ) ) {
F_11 ( & V_2 -> V_13 ) ;
}
if ( F_10 ( & V_2 -> V_14 ) ) {
F_11 ( & V_2 -> V_14 ) ;
}
F_9 ( V_2 ) ;
}
T_2 F_12 ( void * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 = NULL ;
int V_18 = 0 ;
int V_7 ;
T_3 V_19 ;
T_3 V_20 [ V_21 ] ;
F_13 ( V_22 , ( L_1 ) ) ;
F_14 ( V_23 ) ;
do {
if ( ( V_2 = (struct V_1 * ) F_15 ( sizeof( struct V_1 ) ) ) == NULL ) {
F_13 ( V_24 , ( L_2 ) ) ;
V_18 = V_25 ;
break;
}
F_16 ( V_2 , sizeof( struct V_1 ) ) ;
F_17 ( & V_2 -> V_12 ) ;
F_17 ( & V_2 -> V_13 ) ;
F_17 ( & V_2 -> V_14 ) ;
F_18 ( & V_2 -> V_26 ) ;
F_18 ( & V_2 -> V_27 ) ;
V_2 -> V_8 . V_28 = V_15 ;
V_2 -> V_8 . V_29 = V_2 ;
V_2 -> V_8 . V_30 = V_31 ;
V_2 -> V_8 . V_32 = V_33 ;
V_2 -> V_34 = V_35 ;
memcpy ( & V_2 -> V_36 , V_17 , sizeof( struct V_16 ) ) ;
F_19 ( V_2 ) ;
V_18 = F_20 ( & V_2 -> V_8 ) ;
if ( V_18 ) {
break;
}
V_18 = F_21 ( V_15 , V_37 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_18 ) {
F_13 ( V_24 , ( L_3 ) ) ;
break;
}
if ( V_20 [ 1 ] > V_38 ) {
V_19 = V_20 [ 1 ] + V_39 ;
} else {
V_19 = V_38 + V_39 ;
}
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_2 -> V_10 [ V_7 ] . V_11 = F_15 ( V_19 ) ;
if ( V_2 -> V_10 [ V_7 ] . V_11 == NULL ) {
F_13 ( V_24 , ( L_2 ) ) ;
V_18 = V_25 ;
break;
}
}
if ( V_18 ) {
break;
}
for ( V_7 = 0 ; V_7 < V_40 ; V_7 ++ ) {
struct V_3 * V_41 ;
V_41 = & V_2 -> V_10 [ V_7 ] . V_42 ;
F_22 ( V_41 ,
V_2 ,
V_2 -> V_10 [ V_7 ] . V_11 ,
V_19 ,
V_43 ) ;
F_23 ( V_2 , V_41 ) ;
}
for (; V_7 < V_9 ; V_7 ++ ) {
struct V_3 * V_41 ;
V_41 = & V_2 -> V_10 [ V_7 ] . V_42 ;
F_24 ( V_41 ,
V_2 -> V_10 [ V_7 ] . V_11 ,
V_19 ) ;
F_25 ( V_2 , V_41 ) ;
}
} while ( false );
if ( V_18 ) {
if ( V_2 != NULL ) {
F_7 ( V_2 ) ;
V_2 = NULL ;
}
}
F_13 ( V_22 , ( L_4 ) ) ;
return V_2 ;
}
void F_26 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
F_13 ( V_22 , ( L_5 , ( unsigned long ) V_2 ) ) ;
F_7 ( V_2 ) ;
F_13 ( V_22 , ( L_6 ) ) ;
}
void * F_28 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
return V_2 -> V_8 . V_28 ;
}
int F_29 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
int V_18 ;
struct V_3 * V_4 = NULL ;
T_4 * V_45 ;
struct V_46 V_47 ;
struct V_48 V_49 ;
F_13 ( V_22 , ( L_7 , ( unsigned long ) V_2 ) ) ;
do {
#ifdef F_30
V_18 = F_31 ( & V_2 -> V_8 ) ;
if ( V_18 ) {
break;
}
#endif
V_18 = F_32 ( V_2 , & V_4 ) ;
if ( V_18 ) {
F_13 ( V_24 , ( L_8 ) ) ;
break;
}
V_45 = ( T_4 * ) V_4 -> V_50 ;
if ( ( V_45 -> V_51 . V_52 != V_53 ) ||
( V_4 -> V_54 < sizeof( V_55 ) ) ) {
F_33 ( false ) ;
V_18 = V_56 ;
break;
}
if ( V_45 -> V_51 . V_57 == 0 || V_45 -> V_51 . V_58 == 0 ) {
F_33 ( false ) ;
V_18 = V_56 ;
break;
}
V_2 -> V_59 = V_45 -> V_51 . V_57 ;
V_2 -> V_60 = V_45 -> V_51 . V_58 ;
F_13 ( V_61 , ( L_9 ,
V_2 -> V_59 , V_2 -> V_60 ) ) ;
if ( V_4 -> V_54 >= sizeof( T_4 ) ) {
V_2 -> V_62 = V_45 -> V_63 ;
V_2 -> V_64 = V_45 -> V_65 ;
} else {
V_2 -> V_62 = V_66 ;
V_2 -> V_64 = 0 ;
}
#ifdef F_34
V_2 -> V_62 = V_66 ;
V_2 -> V_64 = 0 ;
#endif
F_13 ( V_22 ,
( L_10 ,
( V_2 -> V_62 == V_66 ) ? L_11 : L_12 ,
V_2 -> V_62 ) ) ;
if ( V_2 -> V_64 > 0 ) {
V_2 -> V_64 = F_35 ( V_67 , V_2 -> V_64 ) ;
if ( F_36 ( & V_2 -> V_8 , V_2 -> V_64 ) ) {
V_2 -> V_64 = 0 ;
} else {
V_2 -> V_64 = F_35 ( F_37 ( & V_2 -> V_8 ) ,
V_2 -> V_64 ) ;
}
}
if ( V_2 -> V_64 > 0 ) {
F_13 ( V_22 ,
( L_13 , V_2 -> V_64 ) ) ;
if ( F_38 ( & V_2 -> V_8 ) != 0 ) {
V_2 -> V_68 = true ;
}
if ( F_39 ( & V_2 -> V_8 ) != 0 ) {
V_2 -> V_69 = true ;
}
if ( ! F_40 ( & V_2 -> V_8 , V_2 -> V_60 ) ) {
F_13 ( V_61 , ( L_14 ,
V_2 -> V_60 ) ) ;
V_2 -> V_68 = false ;
}
}
F_16 ( & V_47 , sizeof( V_47 ) ) ;
F_16 ( & V_49 , sizeof( V_49 ) ) ;
V_47 . V_70 . V_71 = V_2 ;
V_47 . V_70 . V_72 = V_73 ;
V_47 . V_70 . V_74 = V_75 ;
V_47 . V_70 . V_76 = NULL ;
V_47 . V_70 . V_77 = NULL ;
V_47 . V_78 = V_9 ;
V_47 . V_79 = V_80 ;
V_18 = F_41 ( ( T_2 ) V_2 ,
& V_47 ,
& V_49 ) ;
if ( ! V_18 ) {
break;
}
} while ( false );
if ( V_4 != NULL ) {
F_23 ( V_2 , V_4 ) ;
}
F_13 ( V_22 , ( L_15 ) ) ;
return V_18 ;
}
int F_42 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
struct V_3 * V_4 ;
int V_18 ;
F_13 ( V_22 , ( L_16 ) ) ;
F_43 ( & V_2 -> V_8 ) ;
V_2 -> V_81 = 0 ;
V_2 -> V_82 = 0 ;
while ( 1 ) {
V_4 = F_44 ( V_2 ) ;
if ( NULL == V_4 ) {
break;
}
F_45 ( ( T_2 ) V_2 , V_4 ) ;
}
do {
F_33 ( V_2 -> V_83 != NULL ) ;
F_33 ( V_2 -> V_84 != NULL ) ;
F_33 ( V_2 -> V_84 -> V_85 != NULL ) ;
V_2 -> V_83 ( V_2 -> V_86 ,
V_2 -> V_84 -> V_85 ,
V_2 -> V_59 ) ;
#ifdef F_46
if ( F_47 ( V_22 ) ) {
F_48 ( V_2 ) ;
}
#endif
V_18 = F_49 ( V_2 ) ;
if ( V_18 ) {
break;
}
V_18 = F_50 ( & V_2 -> V_8 ) ;
if ( V_18 ) {
F_51 ( V_2 ) ;
}
} while ( false );
F_13 ( V_22 , ( L_17 ) ) ;
return V_18 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_87 * V_88 ;
int V_7 ;
for ( V_7 = V_43 ; V_7 < V_35 ; V_7 ++ ) {
V_88 = & V_2 -> V_89 [ V_7 ] ;
F_16 ( & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
V_88 -> V_79 = 0 ;
V_88 -> V_91 = 0 ;
V_88 -> V_92 = 0 ;
F_16 ( & V_88 -> V_93 , sizeof( V_88 -> V_93 ) ) ;
F_18 ( & V_88 -> V_94 ) ;
F_18 ( & V_88 -> V_95 ) ;
F_18 ( & V_88 -> V_96 ) ;
V_88 -> V_2 = V_2 ;
}
V_2 -> V_84 = NULL ;
}
void F_51 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
F_13 ( V_22 , ( L_18 ) ) ;
F_2 ( V_2 ) ;
V_2 -> V_81 |= V_97 ;
F_4 ( V_2 ) ;
F_52 ( & V_2 -> V_8 ) ;
#ifdef F_53
F_54 ( 200 ) ;
#endif
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( & V_2 -> V_8 ) ;
F_19 ( V_2 ) ;
F_13 ( V_22 , ( L_19 ) ) ;
}
void F_58 ( T_2 V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
F_59 ( V_2 ) ;
F_48 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_2 -> V_8 ) ;
}
static void V_31 ( void * V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_98 ;
V_2 -> V_99 = true ;
if ( V_2 -> V_36 . V_99 != NULL ) {
V_2 -> V_36 . V_99 ( V_2 -> V_36 . V_71 , V_25 ) ;
}
}
bool F_62 ( T_2 V_44 ,
T_5 V_100 ,
T_6 V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
bool V_104 = false ;
bool V_105 = false ;
switch ( V_101 ) {
case V_106 :
V_105 = true ;
break;
case V_107 :
V_105 = true ;
V_104 = true ;
break;
case V_108 :
V_104 = true ;
break;
default:
break;
}
F_63 ( V_100 < V_35 ) ;
F_59 ( V_2 ) ;
F_64 ( V_2 ) ;
if ( V_105 ) {
F_63 ( V_103 != NULL ) ;
memcpy ( V_103 , & V_2 -> V_89 [ V_100 ] . V_93 , sizeof( struct V_102 ) ) ;
}
if ( V_104 ) {
F_16 ( & V_2 -> V_89 [ V_100 ] . V_93 , sizeof( struct V_102 ) ) ;
}
F_65 ( V_2 ) ;
F_60 ( V_2 ) ;
return true ;
}
struct V_109 * F_66 ( void * V_44 )
{
struct V_1 * V_2 = F_27 ( V_44 ) ;
return & V_2 -> V_8 ;
}
