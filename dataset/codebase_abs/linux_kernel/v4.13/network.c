bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * const V_5 = V_4 -> V_6 [ 0 ] . V_7 . V_8 ;
T_1 * const V_9 = V_4 -> V_6 [ 1 ] . V_7 . V_8 ;
char * V_10 = F_2 ( V_2 ) ;
const char * V_11 ;
if ( ! strchr ( V_10 , ':' ) &&
F_3 ( V_10 , - 1 , V_5 , '-' , & V_11 ) > 0 ) {
V_4 -> V_12 = false ;
if ( ! * V_11 )
V_4 -> V_6 [ 1 ] . V_13 [ 0 ] = V_4 -> V_6 [ 0 ] . V_13 [ 0 ] ;
else if ( * V_11 ++ != '-' ||
F_3 ( V_11 , - 1 , V_9 , '\0' , & V_11 ) <= 0 || * V_11 )
return false ;
return true ;
}
if ( F_4 ( V_10 , - 1 , V_5 , '-' , & V_11 ) > 0 ) {
V_4 -> V_12 = true ;
if ( ! * V_11 )
memmove ( V_9 , V_5 , sizeof( V_14 ) * 8 ) ;
else if ( * V_11 ++ != '-' ||
F_4 ( V_11 , - 1 , V_9 , '\0' , & V_11 ) <= 0 || * V_11 )
return false ;
return true ;
}
return false ;
}
static void F_5 ( char * V_15 , const unsigned int V_16 ,
const T_2 * V_17 , const T_2 * V_18 )
{
snprintf ( V_15 , V_16 , L_1 , V_17 ,
* V_17 == * V_18 ? '\0' : '-' , V_18 ) ;
}
static void F_6 ( char * V_15 , const unsigned int V_16 ,
const struct V_19 * V_17 ,
const struct V_19 * V_18 )
{
snprintf ( V_15 , V_16 , L_2 , V_17 ,
! memcmp ( V_17 , V_18 , 16 ) ? '\0' : '-' , V_18 ) ;
}
void F_7 ( char * V_20 , const unsigned int V_21 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_12 )
F_6 ( V_20 , V_21 , & V_4 -> V_6 [ 0 ] , & V_4 -> V_6 [ 1 ] ) ;
else
F_5 ( V_20 , V_21 , & V_4 -> V_6 [ 0 ] . V_13 [ 0 ] ,
& V_4 -> V_6 [ 1 ] . V_13 [ 0 ] ) ;
}
static bool F_8 ( const struct V_22 * V_23 ,
const struct V_22 * V_24 )
{
const struct V_25 * V_26 = F_9 ( V_23 , F_10 ( * V_26 ) , V_27 ) ;
const struct V_25 * V_28 = F_9 ( V_24 , F_10 ( * V_28 ) , V_27 ) ;
return V_26 -> V_29 == V_28 -> V_29 &&
F_11 ( & V_26 -> V_10 , & V_28 -> V_10 ) &&
F_12 ( & V_26 -> V_30 , & V_28 -> V_30 ) ;
}
static bool F_13 ( const struct V_22 * V_23 ,
const struct V_22 * V_24 )
{
const struct V_31 * V_26 = F_9 ( V_23 , F_10 ( * V_26 ) , V_27 ) ;
const struct V_31 * V_28 = F_9 ( V_24 , F_10 ( * V_28 ) , V_27 ) ;
return V_26 -> V_29 == V_28 -> V_29 &&
F_14 ( & V_26 -> V_32 , & V_28 -> V_32 ) ;
}
static bool F_15 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
const bool V_33 )
{
T_1 * const V_34 =
& F_9 ( V_23 , struct V_25 , V_27 ) -> V_35 ;
T_1 V_35 = * V_34 ;
const T_1 V_36 = F_9 ( V_24 , struct V_25 , V_27 ) -> V_35 ;
if ( V_33 )
V_35 &= ~ V_36 ;
else
V_35 |= V_36 ;
* V_34 = V_35 ;
return ! V_35 ;
}
static bool F_16 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
const bool V_33 )
{
T_1 * const V_34 =
& F_9 ( V_23 , struct V_31 , V_27 ) -> V_35 ;
T_1 V_35 = * V_34 ;
const T_1 V_36 = F_9 ( V_24 , struct V_31 , V_27 ) -> V_35 ;
if ( V_33 )
V_35 &= ~ V_36 ;
else
V_35 |= V_36 ;
* V_34 = V_35 ;
return ! V_35 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_25 V_37 = { . V_27 . type = V_38 } ;
int error = - V_39 ;
T_1 type ;
const char * V_29 = F_2 ( V_2 ) ;
const char * V_40 = F_2 ( V_2 ) ;
for ( V_37 . V_29 = 0 ; V_37 . V_29 < V_41 ; V_37 . V_29 ++ )
if ( ! strcmp ( V_29 , V_42 [ V_37 . V_29 ] ) )
break;
for ( type = 0 ; type < V_43 ; type ++ )
if ( F_18 ( V_40 , V_44 [ type ] ) )
V_37 . V_35 |= 1 << type ;
if ( V_37 . V_29 == V_41 || ! V_37 . V_35 )
return - V_39 ;
if ( V_2 -> V_45 [ 0 ] == '@' ) {
V_2 -> V_45 ++ ;
V_37 . V_10 . V_46 =
F_19 ( V_2 , V_47 ) ;
if ( ! V_37 . V_10 . V_46 )
return - V_48 ;
} else {
if ( ! F_1 ( V_2 , & V_37 . V_10 ) )
goto V_49;
}
if ( ! F_20 ( V_2 , & V_37 . V_30 ) ||
V_37 . V_30 . V_50 [ 1 ] > 65535 )
goto V_49;
error = F_21 ( & V_37 . V_27 , sizeof( V_37 ) , V_2 ,
F_8 ,
F_15 ) ;
V_49:
F_22 ( V_37 . V_10 . V_46 ) ;
F_23 ( & V_37 . V_30 ) ;
return error ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_31 V_37 = { . V_27 . type = V_51 } ;
int error ;
T_1 type ;
const char * V_29 = F_2 ( V_2 ) ;
const char * V_40 = F_2 ( V_2 ) ;
for ( V_37 . V_29 = 0 ; V_37 . V_29 < V_41 ; V_37 . V_29 ++ )
if ( ! strcmp ( V_29 , V_42 [ V_37 . V_29 ] ) )
break;
for ( type = 0 ; type < V_43 ; type ++ )
if ( F_18 ( V_40 , V_44 [ type ] ) )
V_37 . V_35 |= 1 << type ;
if ( V_37 . V_29 == V_41 || ! V_37 . V_35 )
return - V_39 ;
if ( ! F_25 ( V_2 , & V_37 . V_32 ) )
return - V_39 ;
error = F_21 ( & V_37 . V_27 , sizeof( V_37 ) , V_2 ,
F_13 ,
F_16 ) ;
F_26 ( & V_37 . V_32 ) ;
return error ;
}
static int F_27 ( struct V_52 * V_53 ,
const char * V_54 , const T_1 V_29 ,
const T_1 V_40 , const char * V_10 )
{
return F_28 ( V_53 , L_3 , V_54 ,
V_42 [ V_29 ] ,
V_44 [ V_40 ] , V_10 ) ;
}
static int F_29 ( struct V_52 * V_53 )
{
char V_20 [ 128 ] ;
int V_55 ;
const T_2 * V_10 = V_53 -> V_2 . V_56 . V_10 ;
if ( V_53 -> V_2 . V_56 . V_12 )
F_6 ( V_20 , sizeof( V_20 ) , ( const struct V_19 * )
V_10 , ( const struct V_19 * ) V_10 ) ;
else
F_5 ( V_20 , sizeof( V_20 ) , V_10 , V_10 ) ;
V_55 = strlen ( V_20 ) ;
snprintf ( V_20 + V_55 , sizeof( V_20 ) - V_55 , L_4 ,
V_53 -> V_2 . V_56 . V_30 ) ;
return F_27 ( V_53 , L_5 , V_53 -> V_2 . V_56 . V_29 ,
V_53 -> V_2 . V_56 . V_40 , V_20 ) ;
}
static int F_30 ( struct V_52 * V_53 )
{
return F_27 ( V_53 , L_6 , V_53 -> V_2 . V_57 . V_29 ,
V_53 -> V_2 . V_57 . V_40 ,
V_53 -> V_2 . V_57 . V_10 -> V_32 ) ;
}
static bool F_31 ( struct V_52 * V_53 ,
const struct V_22 * V_4 )
{
const struct V_25 * V_58 =
F_9 ( V_4 , F_10 ( * V_58 ) , V_27 ) ;
const T_1 V_21 = V_53 -> V_2 . V_56 . V_12 ? 16 : 4 ;
if ( ! ( V_58 -> V_35 & ( 1 << V_53 -> V_2 . V_56 . V_40 ) ) ||
! F_32 ( V_53 -> V_2 . V_56 . V_30 ,
& V_58 -> V_30 ) )
return false ;
if ( V_58 -> V_10 . V_46 )
return F_33
( V_53 -> V_2 . V_56 . V_12 ,
V_53 -> V_2 . V_56 . V_10 , V_58 -> V_10 . V_46 ) ;
return V_58 -> V_10 . V_12 == V_53 -> V_2 . V_56 . V_12 &&
memcmp ( & V_58 -> V_10 . V_6 [ 0 ] ,
V_53 -> V_2 . V_56 . V_10 , V_21 ) <= 0 &&
memcmp ( V_53 -> V_2 . V_56 . V_10 ,
& V_58 -> V_10 . V_6 [ 1 ] , V_21 ) <= 0 ;
}
static bool F_34 ( struct V_52 * V_53 ,
const struct V_22 * V_4 )
{
const struct V_31 * V_58 =
F_9 ( V_4 , F_10 ( * V_58 ) , V_27 ) ;
return ( V_58 -> V_35 & ( 1 << V_53 -> V_2 . V_57 . V_40 ) ) &&
F_35 ( V_53 -> V_2 . V_57 . V_10 ,
& V_58 -> V_32 ) ;
}
static int F_36 ( const struct V_59 * V_10 )
{
const int V_60 = F_37 () ;
struct V_52 V_53 ;
int error = 0 ;
const T_1 type = V_61 [ V_10 -> V_29 ] [ V_10 -> V_40 ] ;
if ( type && F_38 ( & V_53 , NULL , type )
!= V_62 ) {
V_53 . V_63 = V_38 ;
V_53 . V_2 . V_56 . V_29 = V_10 -> V_29 ;
V_53 . V_2 . V_56 . V_40 = V_10 -> V_40 ;
V_53 . V_2 . V_56 . V_12 = V_10 -> V_64 . V_12 ;
V_53 . V_2 . V_56 . V_10 = V_10 -> V_64 . V_10 ;
V_53 . V_2 . V_56 . V_30 = F_39 ( V_10 -> V_64 . V_30 ) ;
do {
F_40 ( & V_53 , F_31 ) ;
error = F_29 ( & V_53 ) ;
} while ( error == V_65 );
}
F_41 ( V_60 ) ;
return error ;
}
static int F_42 ( const struct V_66 * V_67 ,
const unsigned int V_68 ,
const V_14 V_30 ,
struct V_59 * V_10 )
{
struct V_69 * V_70 = & V_10 -> V_64 ;
switch ( V_67 -> V_71 ) {
case V_72 :
if ( V_68 < V_73 )
goto V_74;
V_70 -> V_12 = true ;
V_70 -> V_10 = ( T_2 * )
( (struct V_75 * ) V_67 ) -> V_76 . V_77 ;
V_70 -> V_30 = ( (struct V_75 * ) V_67 ) -> V_78 ;
break;
case V_79 :
if ( V_68 < sizeof( struct V_80 ) )
goto V_74;
V_70 -> V_12 = false ;
V_70 -> V_10 = ( T_2 * )
& ( (struct V_80 * ) V_67 ) -> V_81 ;
V_70 -> V_30 = ( (struct V_80 * ) V_67 ) -> V_82 ;
break;
default:
goto V_74;
}
if ( V_10 -> V_29 == V_83 )
V_70 -> V_30 = F_43 ( V_30 ) ;
return F_36 ( V_10 ) ;
V_74:
return 0 ;
}
static int F_44 ( const struct V_59 * V_10 )
{
const int V_60 = F_37 () ;
struct V_52 V_53 ;
int error = 0 ;
const T_1 type = V_84 [ V_10 -> V_29 ] [ V_10 -> V_40 ] ;
if ( type && F_38 ( & V_53 , NULL , type )
!= V_62 ) {
char * V_20 = V_10 -> V_85 . V_67 ;
int V_55 = V_10 -> V_85 . V_68 - sizeof( V_86 ) ;
if ( V_55 <= 0 ) {
V_20 = L_7 ;
V_55 = 9 ;
} else if ( V_20 [ 0 ] ) {
V_55 = F_45 ( V_20 , V_55 ) ;
}
V_20 = F_46 ( V_20 , V_55 ) ;
if ( V_20 ) {
struct V_87 V_67 ;
V_67 . V_32 = V_20 ;
F_47 ( & V_67 ) ;
V_53 . V_63 = V_51 ;
V_53 . V_2 . V_57 . V_29 = V_10 -> V_29 ;
V_53 . V_2 . V_57 . V_40 = V_10 -> V_40 ;
V_53 . V_2 . V_57 . V_10 = & V_67 ;
do {
F_40 ( & V_53 , F_34 ) ;
error = F_30 ( & V_53 ) ;
} while ( error == V_65 );
F_48 ( V_20 ) ;
} else
error = - V_48 ;
}
F_41 ( V_60 ) ;
return error ;
}
static int F_49 ( struct V_66 * V_67 ,
const unsigned int V_68 ,
struct V_59 * V_10 )
{
struct V_88 * V_89 = & V_10 -> V_85 ;
if ( V_67 -> V_71 != V_90 )
return 0 ;
V_89 -> V_67 = ( (struct V_91 * ) V_67 ) -> V_92 ;
V_89 -> V_68 = V_68 ;
return F_44 ( V_10 ) ;
}
static bool F_50 ( void )
{
return F_51 () ;
}
static T_1 F_52 ( struct V_93 * V_94 )
{
T_1 V_54 ;
if ( F_50 () )
return 0 ;
V_54 = V_94 -> V_95 ;
switch ( V_54 ) {
case V_96 :
case V_97 :
case V_98 :
return V_54 ;
default:
return 0 ;
}
}
int F_53 ( struct V_99 * V_93 )
{
struct V_59 V_10 ;
const T_1 V_54 = F_52 ( V_93 -> V_94 ) ;
const unsigned int type = V_93 -> type ;
struct V_100 V_67 ;
int V_68 ;
if ( ! V_54 || ( type != V_101 && type != V_102 ) )
return 0 ;
{
const int error = V_93 -> V_103 -> V_104 ( V_93 , (struct V_66 * )
& V_67 , & V_68 , 0 ) ;
if ( error )
return error ;
}
V_10 . V_29 = type ;
V_10 . V_40 = V_105 ;
if ( V_54 == V_98 )
return F_49 ( (struct V_66 * ) & V_67 ,
V_68 , & V_10 ) ;
return F_42 ( (struct V_66 * ) & V_67 , V_68 ,
0 , & V_10 ) ;
}
int F_54 ( struct V_99 * V_93 ,
struct V_66 * V_67 , int V_68 )
{
struct V_59 V_10 ;
const T_1 V_54 = F_52 ( V_93 -> V_94 ) ;
const unsigned int type = V_93 -> type ;
if ( ! V_54 )
return 0 ;
V_10 . V_29 = type ;
switch ( type ) {
case V_106 :
case V_83 :
V_10 . V_40 = V_107 ;
break;
case V_101 :
case V_102 :
V_10 . V_40 = V_108 ;
break;
default:
return 0 ;
}
if ( V_54 == V_98 )
return F_49 ( V_67 , V_68 , & V_10 ) ;
return F_42 ( V_67 , V_68 , V_93 -> V_94 -> V_109 ,
& V_10 ) ;
}
int F_55 ( struct V_99 * V_93 , struct V_66 * V_67 ,
int V_68 )
{
struct V_59 V_10 ;
const T_1 V_54 = F_52 ( V_93 -> V_94 ) ;
const unsigned int type = V_93 -> type ;
if ( ! V_54 )
return 0 ;
switch ( type ) {
case V_101 :
case V_106 :
case V_83 :
case V_102 :
V_10 . V_29 = type ;
V_10 . V_40 = V_110 ;
break;
default:
return 0 ;
}
if ( V_54 == V_98 )
return F_49 ( V_67 , V_68 , & V_10 ) ;
return F_42 ( V_67 , V_68 , V_93 -> V_94 -> V_109 ,
& V_10 ) ;
}
int F_56 ( struct V_99 * V_93 , struct V_111 * V_112 ,
int V_21 )
{
struct V_59 V_10 ;
const T_1 V_54 = F_52 ( V_93 -> V_94 ) ;
const unsigned int type = V_93 -> type ;
if ( ! V_112 -> V_113 || ! V_54 ||
( type != V_106 && type != V_83 ) )
return 0 ;
V_10 . V_29 = type ;
V_10 . V_40 = V_107 ;
if ( V_54 == V_98 )
return F_49 ( (struct V_66 * )
V_112 -> V_113 ,
V_112 -> V_114 , & V_10 ) ;
return F_42 ( (struct V_66 * ) V_112 -> V_113 ,
V_112 -> V_114 ,
V_93 -> V_94 -> V_109 , & V_10 ) ;
}
