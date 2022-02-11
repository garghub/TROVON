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
V_22 &= V_47 - 1 ;
break;
}
case V_46 :
default:
V_43 = V_44 ;
break;
}
if ( V_42 )
* V_42 = F_6 ( V_48 , V_22 ) ;
return V_43 ;
}
static T_6 F_35 ( enum V_41 V_49 , T_2 V_50 , T_2 V_51 ,
T_2 V_52 )
{
return F_36 ( V_49 , V_50 , V_51 , V_52 ) ;
}
static void F_37 ( T_7 V_53 , T_2 V_54 )
{
T_8 V_55 ;
T_6 V_56 ;
T_2 V_42 ;
enum V_41 V_43 ;
V_43 = F_34 ( & V_42 ) ;
V_56 = F_35 ( V_43 , V_54 , V_54 , V_42 ) ;
V_55 = F_38 ( V_53 ) ;
F_39 ( & V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
}
static void F_41 ( T_8 * V_55 ,
T_2 V_54 )
{
T_6 V_56 ;
T_2 V_58 ;
enum V_41 V_43 ;
V_58 = F_30 ( V_48 , L_8 ) ;
F_32 ( V_59 ) ;
F_33 ( V_59 ) ;
V_56 = F_42 ( V_58 , V_59 ) ;
F_39 ( V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
V_43 = F_34 ( NULL ) ;
V_56 = F_35 ( V_43 , V_58 , V_58 , V_54 ) ;
F_43 ( V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
V_56 = F_42 ( V_59 , V_58 ) ;
F_43 ( V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
}
static bool F_44 ( T_7 V_53 , T_2 V_54 )
{
T_8 V_55 ;
for ( V_55 = F_45 ( V_53 ) ; ! F_46 ( V_55 ) ; F_47 ( & V_55 ) ) {
T_9 * V_60 ;
T_6 V_61 = F_48 ( V_55 ) ;
if ( ! F_49 ( V_61 ) )
continue;
V_60 = F_50 ( V_61 ) ;
if ( ! F_51 ( V_60 ) )
continue;
F_41 ( & V_55 , V_54 ) ;
return true ;
}
return false ;
}
static void F_52 ( T_2 V_54 )
{
T_10 V_62 ;
T_11 V_63 , V_64 ;
T_7 V_65 ;
F_53 ( F_54 ( F_27 ( V_38 ) ) ) ;
V_64 = F_55 ( F_27 ( V_38 ) ) ;
F_56 (e, ei, last_bb_e->src->preds) {
if ( F_57 ( V_38 ) == V_63 -> V_66 )
continue;
if ( F_27 ( V_38 ) == V_63 -> V_66 )
continue;
F_44 ( V_63 -> V_66 , V_54 ) ;
}
V_65 = F_58 ( F_27 ( V_38 ) ) ;
if ( ! F_44 ( V_65 , V_54 ) ) {
T_8 V_55 = F_59 ( V_65 ) ;
F_41 ( & V_55 , V_54 ) ;
}
}
static void F_60 ( T_7 V_53 , T_2 V_54 )
{
T_6 V_56 , V_60 ;
T_2 V_67 , V_68 , V_69 , V_70 , V_71 ;
enum V_41 V_43 ;
unsigned T_1 V_32 ;
T_8 V_55 = F_38 ( V_53 ) ;
V_67 = F_30 ( V_72 , L_9 ) ;
V_70 = F_61 ( V_73 ) ;
V_60 = F_62 ( V_70 , 1 , V_74 ) ;
F_63 ( V_60 , V_67 ) ;
F_39 ( & V_55 , V_60 , V_57 ) ;
F_40 ( V_60 ) ;
V_71 = F_64 ( V_48 , V_67 ) ;
V_56 = F_42 ( V_54 , V_71 ) ;
F_43 ( & V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
V_69 = F_30 ( V_48 , L_8 ) ;
F_32 ( V_59 ) ;
F_33 ( V_59 ) ;
V_56 = F_42 ( V_69 , V_59 ) ;
F_43 ( & V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
V_56 = F_35 ( V_44 , V_54 , V_54 , V_69 ) ;
F_43 ( & V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
V_32 = F_1 () ;
V_68 = F_6 ( V_48 , V_32 ) ;
V_43 = F_34 ( NULL ) ;
V_56 = F_35 ( V_43 , V_54 , V_54 , V_68 ) ;
F_43 ( & V_55 , V_56 , V_57 ) ;
F_40 ( V_56 ) ;
}
static bool F_65 ( void )
{
T_12 V_5 ;
if ( V_59 != V_34 )
return true ;
F_66 (node) {
T_2 V_6 , V_40 = F_67 ( V_5 ) ;
if ( F_68 ( V_40 ) < sizeof( L_7 ) - 1 )
continue;
V_6 = F_69 ( V_40 ) ;
if ( strcmp ( F_70 ( V_6 ) , L_7 ) )
continue;
V_59 = V_40 ;
break;
}
return V_59 != V_34 ;
}
static unsigned int F_71 ( void )
{
T_7 V_53 ;
T_2 V_54 ;
if ( ! F_65 () )
return 0 ;
F_53 ( F_72 ( F_57 ( V_38 ) ) ) ;
V_53 = F_73 ( F_57 ( V_38 ) ) ;
if ( ! F_54 ( V_53 ) ) {
F_74 ( F_75 ( F_57 ( V_38 ) ) ) ;
F_53 ( F_72 ( F_57 ( V_38 ) ) ) ;
V_53 = F_73 ( F_57 ( V_38 ) ) ;
}
V_54 = F_30 ( V_48 , L_10 ) ;
F_60 ( V_53 , V_54 ) ;
V_53 = V_53 -> V_75 ;
while ( V_53 != F_27 ( V_38 ) ) {
F_37 ( V_53 , V_54 ) ;
V_53 = V_53 -> V_75 ;
} ;
F_52 ( V_54 ) ;
return 0 ;
}
static void F_76 ( void * T_13 V_7 ,
void * T_14 V_7 )
{
T_2 type , V_76 ;
int V_77 ;
V_3 = F_77 ( false ) ;
if ( V_78 )
return;
V_77 = F_78 ( V_48 ) | V_79 ;
type = F_79 ( V_48 , V_77 ) ;
V_76 = F_80 ( L_7 ) ;
V_59 = F_81 ( V_80 , V_15 , V_76 , type ) ;
F_12 ( V_59 ) = 1 ;
F_82 ( V_59 ) = 1 ;
F_83 ( V_59 ) = 1 ;
F_84 ( V_59 ) = 1 ;
F_25 ( V_59 ) = 1 ;
F_85 ( V_59 ) = 1 ;
F_86 ( V_59 ) = 1 ;
V_81 . V_82 . V_83 ( V_59 ) ;
}
T_15 int F_87 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
bool V_88 = true ;
const char * const V_89 = V_85 -> V_90 ;
const int V_91 = V_85 -> V_91 ;
const struct V_92 * const V_93 = V_85 -> V_93 ;
int V_1 ;
struct V_94 V_95 ;
V_95 . V_96 = F_88 () ;
V_95 . V_97 = L_11 ;
V_95 . V_98 = 1 ;
V_95 . V_99 = V_100 ;
static const struct V_101 V_102 [] = {
{
. V_103 = & V_59 ,
. V_19 = 1 ,
. V_104 = sizeof( V_59 ) ,
. V_105 = & V_106 ,
. V_107 = & V_108
} ,
V_109
} ;
if ( ! F_89 ( V_87 , & V_110 ) ) {
error ( F_90 ( L_12 ) ) ;
return 1 ;
}
for ( V_1 = 0 ; V_1 < V_91 ; ++ V_1 ) {
if ( ! ( strcmp ( V_93 [ V_1 ] . V_111 , L_13 ) ) ) {
V_88 = false ;
continue;
}
error ( F_90 ( L_14 ) , V_89 , V_93 [ V_1 ] . V_111 ) ;
}
F_91 ( V_89 , V_112 , NULL ,
& V_113 ) ;
if ( V_88 ) {
F_91 ( V_89 , V_114 ,
& F_76 , NULL ) ;
F_91 ( V_89 , V_115 ,
NULL , ( void * ) & V_102 ) ;
F_91 ( V_89 , V_116 , NULL ,
& V_95 ) ;
}
F_91 ( V_89 , V_117 , F_22 ,
NULL ) ;
return 0 ;
}
