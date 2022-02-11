static unsigned T_1 F_1 ( void )
{
unsigned int V_1 ;
unsigned T_1 V_2 = 0 ;
for ( V_1 = 0 ; V_1 < 8 * sizeof( V_2 ) ; V_1 ++ ) {
V_2 = ( V_2 << 1 ) | ( V_3 & 1 ) ;
V_3 >>= 1 ;
if ( V_2 & 1 )
V_3 ^= 0xD800000000000000ULL ;
}
return V_2 ;
}
static T_2 F_2 ( T_2 type )
{
unsigned long long V_4 ;
V_4 = 1ULL << ( F_3 ( F_4 ( type ) ) - 1 ) ;
V_4 = 2 * ( V_4 - 1 ) + 1 ;
if ( F_5 ( type ) )
return F_6 ( type , V_4 & F_1 () ) ;
return F_7 ( type , V_4 & F_1 () ) ;
}
static T_2 F_8 ( T_2 * V_5 , T_2 V_6 ,
T_2 args V_7 ,
int T_3 V_7 ,
bool * V_8 )
{
T_2 type ;
#if V_9 <= 4007
F_9 ( V_10 , V_11 ) * V_12 ;
#else
V_13 < V_10 , V_14 > * V_12 ;
#endif
switch ( F_10 ( * V_5 ) ) {
default:
* V_8 = true ;
error ( L_1 ,
V_6 ) ;
break;
case V_15 :
if ( F_11 ( * V_5 ) ) {
* V_8 = true ;
error ( L_2 ,
* V_5 , V_6 ) ;
break;
}
if ( ! F_12 ( * V_5 ) ) {
* V_8 = true ;
error ( L_3 ,
* V_5 , V_6 ) ;
break;
}
type = F_13 ( * V_5 ) ;
switch ( F_10 ( type ) ) {
default:
* V_8 = true ;
error ( L_4 ,
* V_5 , V_6 ) ;
break;
case V_16 : {
T_2 V_17 , V_18 = F_14 ( type ) ;
unsigned int V_19 = 0 ;
for ( V_17 = V_18 ; V_17 ; V_19 ++ , V_17 = F_15 ( V_17 ) ) {
T_2 V_20 ;
V_20 = F_13 ( V_17 ) ;
if ( F_10 ( V_20 ) == V_21 )
continue;
* V_8 = true ;
error ( L_5 ,
* V_5 , V_6 , V_17 ) ;
break;
}
if ( V_17 )
break;
#if V_9 <= 4007
V_12 = F_16 ( V_10 , V_11 , V_19 ) ;
#else
F_17 ( V_12 , V_19 ) ;
#endif
for ( V_17 = V_18 ; V_17 ; V_17 = F_15 ( V_17 ) ) {
T_2 V_22 , V_23 = F_13 ( V_17 ) ;
V_22 = F_2 ( V_23 ) ;
F_18 ( V_12 , V_17 , V_22 ) ;
}
F_11 ( * V_5 ) = F_19 ( type , V_12 ) ;
break;
}
case V_21 :
F_11 ( * V_5 ) = F_2 ( type ) ;
break;
case V_24 : {
T_2 V_25 , V_26 , V_27 ;
unsigned int V_1 , V_19 ;
T_1 V_28 , V_29 ;
V_25 = F_13 ( type ) ;
V_27 = F_20 ( F_13 ( type ) ) ;
V_26 = F_20 ( type ) ;
if ( F_10 ( V_25 ) != V_21 || ! V_26
|| F_10 ( V_26 ) != V_30 ) {
* V_8 = true ;
error ( L_6 ,
* V_5 , V_6 ) ;
break;
}
V_28 = F_3 ( V_26 ) ;
V_29 = F_3 ( V_27 ) ;
V_19 = V_28 / V_29 ;
#if V_9 <= 4007
V_12 = F_16 ( V_10 , V_11 , V_19 ) ;
#else
F_17 ( V_12 , V_19 ) ;
#endif
for ( V_1 = 0 ; V_1 < V_19 ; V_1 ++ ) {
T_2 V_31 = F_21 ( V_1 ) ;
T_2 V_32 = F_2 ( V_25 ) ;
F_18 ( V_12 , V_31 , V_32 ) ;
}
F_11 ( * V_5 ) = F_19 ( type , V_12 ) ;
break;
}
}
break;
case V_33 :
break;
}
return V_34 ;
}
static void F_22 ( void * T_4 V_7 , void * T_5 V_7 )
{
F_23 ( & V_35 ) ;
}
static bool F_24 ( void )
{
T_2 V_36 ;
if ( F_25 ( V_37 ) )
return false ;
if ( F_26 ( F_27 ( V_38 ) -> V_39 ) == 0 )
return false ;
V_36 = F_28 ( V_37 ) ;
return F_29 ( L_7 , V_36 ) != V_34 ;
}
static T_2 F_30 ( T_2 type , const char * V_6 )
{
T_2 V_40 ;
V_40 = F_31 ( type , V_6 ) ;
F_32 ( V_40 ) ;
F_33 ( V_40 ) ;
return V_40 ;
}
static enum V_41 F_34 ( T_2 * V_42 )
{
static enum V_41 V_43 ;
unsigned T_1 V_22 ;
V_22 = F_1 () ;
switch ( V_43 ) {
case V_44 :
V_43 = V_45 ;
break;
case V_45 :
if ( V_42 ) {
V_43 = V_46 ;
V_22 %= F_35 ( V_47 ) ;
break;
}
case V_46 :
default:
V_43 = V_44 ;
break;
}
if ( V_42 )
* V_42 = F_6 ( V_47 , V_22 ) ;
return V_43 ;
}
static T_6 F_36 ( enum V_41 V_48 , T_2 V_49 , T_2 V_50 ,
T_2 V_51 )
{
return F_37 ( V_48 , V_49 , V_50 , V_51 ) ;
}
static void F_38 ( T_7 V_52 , T_2 V_53 )
{
T_8 V_54 ;
T_6 V_55 ;
T_2 V_42 ;
enum V_41 V_43 ;
V_43 = F_34 ( & V_42 ) ;
V_55 = F_36 ( V_43 , V_53 , V_53 , V_42 ) ;
V_54 = F_39 ( V_52 ) ;
F_40 ( & V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
}
static void F_42 ( T_8 * V_54 ,
T_2 V_53 )
{
T_6 V_55 ;
T_2 V_57 ;
enum V_41 V_43 ;
V_57 = F_30 ( V_47 , L_8 ) ;
F_32 ( V_58 ) ;
F_33 ( V_58 ) ;
V_55 = F_43 ( V_57 , V_58 ) ;
F_40 ( V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
V_43 = F_34 ( NULL ) ;
V_55 = F_36 ( V_43 , V_57 , V_57 , V_53 ) ;
F_44 ( V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
V_55 = F_43 ( V_58 , V_57 ) ;
F_44 ( V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
}
static bool F_45 ( T_7 V_52 , T_2 V_53 )
{
T_8 V_54 ;
for ( V_54 = F_46 ( V_52 ) ; ! F_47 ( V_54 ) ; F_48 ( & V_54 ) ) {
T_9 * V_59 ;
T_6 V_60 = F_49 ( V_54 ) ;
if ( ! F_50 ( V_60 ) )
continue;
V_59 = F_51 ( V_60 ) ;
if ( ! F_52 ( V_59 ) )
continue;
F_42 ( & V_54 , V_53 ) ;
return true ;
}
return false ;
}
static void F_53 ( T_2 V_53 )
{
T_10 V_61 ;
T_11 V_62 , V_63 ;
T_7 V_64 ;
F_54 ( F_55 ( F_27 ( V_38 ) ) ) ;
V_63 = F_56 ( F_27 ( V_38 ) ) ;
F_57 (e, ei, last_bb_e->src->preds) {
if ( F_58 ( V_38 ) == V_62 -> V_65 )
continue;
if ( F_27 ( V_38 ) == V_62 -> V_65 )
continue;
F_45 ( V_62 -> V_65 , V_53 ) ;
}
V_64 = F_59 ( F_27 ( V_38 ) ) ;
if ( ! F_45 ( V_64 , V_53 ) ) {
T_8 V_54 = F_60 ( V_64 ) ;
F_42 ( & V_54 , V_53 ) ;
}
}
static void F_61 ( T_7 V_52 , T_2 V_53 )
{
T_6 V_55 , V_59 ;
T_2 V_66 , V_67 , V_68 , V_69 , V_70 ;
enum V_41 V_43 ;
unsigned T_1 V_32 ;
T_8 V_54 = F_39 ( V_52 ) ;
V_66 = F_30 ( V_71 , L_9 ) ;
V_69 = F_62 ( V_72 ) ;
V_59 = F_63 ( V_69 , 1 , V_73 ) ;
F_64 ( V_59 , V_66 ) ;
F_40 ( & V_54 , V_59 , V_56 ) ;
F_41 ( V_59 ) ;
V_70 = F_65 ( V_47 , V_66 ) ;
V_55 = F_43 ( V_53 , V_70 ) ;
F_44 ( & V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
V_68 = F_30 ( V_47 , L_8 ) ;
F_32 ( V_58 ) ;
F_33 ( V_58 ) ;
V_55 = F_43 ( V_68 , V_58 ) ;
F_44 ( & V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
V_55 = F_36 ( V_44 , V_53 , V_53 , V_68 ) ;
F_44 ( & V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
V_32 = F_1 () ;
V_67 = F_6 ( V_47 , V_32 ) ;
V_43 = F_34 ( NULL ) ;
V_55 = F_36 ( V_43 , V_53 , V_53 , V_67 ) ;
F_44 ( & V_54 , V_55 , V_56 ) ;
F_41 ( V_55 ) ;
}
static bool F_66 ( void )
{
T_12 V_5 ;
if ( V_58 != V_34 )
return true ;
F_67 (node) {
T_2 V_6 , V_40 = F_68 ( V_5 ) ;
if ( F_69 ( V_40 ) < sizeof( L_7 ) - 1 )
continue;
V_6 = F_70 ( V_40 ) ;
if ( strcmp ( F_71 ( V_6 ) , L_7 ) )
continue;
V_58 = V_40 ;
break;
}
return V_58 != V_34 ;
}
static unsigned int F_72 ( void )
{
T_7 V_52 ;
T_2 V_53 ;
if ( ! F_66 () )
return 0 ;
F_54 ( F_73 ( F_58 ( V_38 ) ) ) ;
V_52 = F_74 ( F_58 ( V_38 ) ) ;
if ( ! F_55 ( V_52 ) ) {
F_75 ( F_76 ( F_58 ( V_38 ) ) ) ;
F_54 ( F_73 ( F_58 ( V_38 ) ) ) ;
V_52 = F_74 ( F_58 ( V_38 ) ) ;
}
V_53 = F_30 ( V_47 , L_10 ) ;
F_61 ( V_52 , V_53 ) ;
V_52 = V_52 -> V_74 ;
while ( V_52 != F_27 ( V_38 ) ) {
F_38 ( V_52 , V_53 ) ;
V_52 = V_52 -> V_74 ;
} ;
F_53 ( V_53 ) ;
return 0 ;
}
static void F_77 ( void * T_13 V_7 ,
void * T_14 V_7 )
{
T_2 type , V_75 ;
int V_76 ;
V_3 = F_78 ( false ) ;
if ( V_77 )
return;
V_76 = F_79 ( V_47 ) | V_78 ;
type = F_80 ( V_47 , V_76 ) ;
V_75 = F_81 ( L_7 ) ;
V_58 = F_82 ( V_79 , V_15 , V_75 , type ) ;
F_12 ( V_58 ) = 1 ;
F_83 ( V_58 ) = 1 ;
F_84 ( V_58 ) = 1 ;
F_85 ( V_58 ) = 1 ;
F_25 ( V_58 ) = 1 ;
F_86 ( V_58 ) = 1 ;
F_87 ( V_58 ) = 1 ;
V_80 . V_81 . V_82 ( V_58 ) ;
}
T_15 int F_88 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
bool V_87 = true ;
const char * const V_88 = V_84 -> V_89 ;
const int V_90 = V_84 -> V_90 ;
const struct V_91 * const V_92 = V_84 -> V_92 ;
int V_1 ;
static const struct V_93 V_94 [] = {
{
. V_95 = & V_58 ,
. V_19 = 1 ,
. V_96 = sizeof( V_58 ) ,
. V_97 = & V_98 ,
. V_99 = & V_100
} ,
V_101
} ;
F_89 ( V_102 , L_11 , 1 , V_103 ) ;
if ( ! F_90 ( V_86 , & V_104 ) ) {
error ( F_91 ( L_12 ) ) ;
return 1 ;
}
for ( V_1 = 0 ; V_1 < V_90 ; ++ V_1 ) {
if ( ! ( strcmp ( V_92 [ V_1 ] . V_105 , L_13 ) ) ) {
V_87 = false ;
continue;
}
error ( F_91 ( L_14 ) , V_88 , V_92 [ V_1 ] . V_105 ) ;
}
F_92 ( V_88 , V_106 , NULL ,
& V_107 ) ;
if ( V_87 ) {
F_92 ( V_88 , V_108 ,
& F_77 , NULL ) ;
F_92 ( V_88 , V_109 ,
NULL , ( void * ) & V_94 ) ;
F_92 ( V_88 , V_110 , NULL ,
& V_111 ) ;
}
F_92 ( V_88 , V_112 , F_22 ,
NULL ) ;
return 0 ;
}
