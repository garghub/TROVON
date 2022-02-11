T_1 F_1 ( struct V_1 * V_1 , enum V_2 V_3 )
{
return V_1 -> V_4 [ V_3 ] ;
}
void F_2 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
V_1 -> V_4 [ V_3 ] = V_5 ;
}
bool F_3 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
if ( V_5 > F_1 ( V_1 , V_3 ) ) {
F_2 ( V_1 , V_3 , V_5 ) ;
return true ;
}
return false ;
}
void F_4 ( struct V_1 * V_1 )
{
enum V_2 V_3 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_2 ( V_1 , V_3 , 0 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_7 )
{
const unsigned int V_8 = V_9 / 4 ;
if ( F_1 ( V_1 , V_7 ) < V_8 &&
! V_10 . V_11 && ! V_10 . V_12 &&
! V_10 . V_13 )
F_2 ( V_1 , V_7 , V_8 ) ;
}
void F_6 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
const unsigned int V_8 = V_9 / 4 ;
T_1 V_5 ;
if ( V_15 -> V_16 . V_17 )
F_3 ( V_1 , V_18 , V_15 -> V_16 . V_17 -> V_19 + 4 ) ;
else
F_5 ( V_1 , V_20 ) ;
V_5 = F_7 ( V_15 -> V_21 ) ;
if ( F_3 ( V_1 , V_22 , V_5 ) )
F_2 ( V_1 , V_23 , V_5 + 6 ) ;
if ( V_15 -> V_16 . V_24 ) {
V_5 = F_8 ( V_15 -> V_16 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_20 , V_5 ) ;
}
if ( V_15 -> V_25 ) {
int V_26 ;
if ( V_15 -> V_25 -> V_27 . V_17 ) {
V_26 = ( int ) V_15 -> V_25 -> V_27 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_28 , V_26 ) ;
V_26 = F_8 ( V_15 -> V_25 -> V_27 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_29 , V_26 ) ;
} else {
V_26 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_28 , V_26 ) ;
F_5 ( V_1 , V_29 ) ;
}
if ( V_15 -> V_25 -> V_30 . V_17 ) {
V_26 = ( int ) V_15 -> V_25 -> V_30 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_31 , V_26 ) ;
V_26 = F_8 ( V_15 -> V_25 -> V_30 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_32 , V_26 ) ;
} else {
V_26 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_31 , V_26 ) ;
F_5 ( V_1 , V_32 ) ;
}
}
}
void F_9 ( struct V_1 * V_1 , int V_33 )
{
struct V_34 * V_35 = F_10 ( & V_1 -> V_36 ) ;
struct V_14 * V_37 ;
int V_38 = 0 ;
F_4 ( V_1 ) ;
while ( V_35 && V_38 ++ < V_33 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_34 ) ;
if ( ! V_37 -> V_39 )
F_6 ( V_1 , V_37 ) ;
V_35 = F_12 ( & V_37 -> V_34 ) ;
}
}
static void F_13 ( struct V_14 * V_40 ,
unsigned int V_41 , T_2 V_42 )
{
switch ( V_41 ) {
case V_43 :
V_40 -> V_44 . V_45 += V_42 ;
break;
case V_46 :
V_40 -> V_44 . V_47 += V_42 ;
break;
case V_48 :
V_40 -> V_44 . V_49 += V_42 ;
break;
case V_50 :
V_40 -> V_44 . V_51 += V_42 ;
break;
default:
break;
}
}
static void F_14 ( struct V_52 * V_52 , T_2 V_42 )
{
V_52 -> V_42 += V_42 ;
V_52 -> V_53 += 1 ;
}
static void F_15 ( struct V_52 * V_54 , struct V_52 * V_55 )
{
V_54 -> V_42 += V_55 -> V_42 ;
V_54 -> V_45 += V_55 -> V_45 ;
V_54 -> V_47 += V_55 -> V_47 ;
V_54 -> V_49 += V_55 -> V_49 ;
V_54 -> V_51 += V_55 -> V_51 ;
V_54 -> V_53 += V_55 -> V_53 ;
}
static void F_16 ( struct V_14 * V_40 )
{
V_40 -> V_44 . V_42 = ( V_40 -> V_44 . V_42 * 7 ) / 8 ;
V_40 -> V_44 . V_53 = ( V_40 -> V_44 . V_53 * 7 ) / 8 ;
}
static bool F_17 ( struct V_1 * V_1 , struct V_14 * V_40 )
{
T_2 V_56 = V_40 -> V_44 . V_42 ;
if ( V_56 == 0 )
return true ;
F_16 ( V_40 ) ;
if ( ! V_40 -> V_39 )
V_1 -> V_57 . V_58 -= V_56 - V_40 -> V_44 . V_42 ;
return V_40 -> V_44 . V_42 == 0 ;
}
static void F_18 ( struct V_1 * V_1 , bool V_59 ,
bool V_60 , bool V_61 )
{
struct V_34 * V_35 = F_10 ( & V_1 -> V_36 ) ;
struct V_14 * V_37 ;
while ( V_35 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_34 ) ;
V_35 = F_12 ( & V_37 -> V_34 ) ;
if ( ( ( V_59 && V_37 -> V_62 == '.' ) ||
( V_60 && V_37 -> V_62 != '.' ) ||
F_17 ( V_1 , V_37 ) ) &&
! V_37 -> V_63 ) {
F_19 ( & V_37 -> V_34 , & V_1 -> V_36 ) ;
if ( V_64 || V_61 )
F_19 ( & V_37 -> V_65 , & V_1 -> V_66 ) ;
F_20 ( V_37 ) ;
-- V_1 -> V_67 ;
}
}
}
void F_21 ( struct V_1 * V_1 , bool V_59 , bool V_60 )
{
return F_18 ( V_1 , V_59 , V_60 , false ) ;
}
void F_22 ( struct V_1 * V_1 ,
bool V_59 , bool V_60 )
{
return F_18 ( V_1 , V_59 , V_60 , true ) ;
}
static struct V_14 * F_23 ( struct V_14 * V_68 )
{
T_3 V_69 = V_10 . V_70 ? sizeof( struct V_71 ) : 0 ;
struct V_14 * V_40 = malloc ( sizeof( * V_40 ) + V_69 ) ;
if ( V_40 != NULL ) {
* V_40 = * V_68 ;
if ( V_40 -> V_16 . V_24 )
V_40 -> V_16 . V_24 -> V_72 = true ;
if ( V_10 . V_70 )
F_24 ( V_40 -> V_73 ) ;
F_25 ( & V_40 -> V_74 . V_75 ) ;
}
return V_40 ;
}
static void F_26 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_39 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_67 ;
V_1 -> V_57 . V_58 += V_15 -> V_44 . V_42 ;
}
}
static T_4 F_27 ( const struct V_76 * V_77 )
{
if ( V_10 . V_78 && V_77 == NULL )
return 1 << V_79 ;
return 0 ;
}
static struct V_14 * F_28 ( struct V_1 * V_1 ,
struct V_14 * V_80 ,
struct V_81 * V_82 ,
T_2 V_42 )
{
struct V_34 * * V_83 ;
struct V_34 * V_77 = NULL ;
struct V_14 * V_40 ;
int V_84 ;
F_29 ( & V_1 -> V_85 ) ;
V_83 = & V_1 -> V_86 -> V_34 ;
while ( * V_83 != NULL ) {
V_77 = * V_83 ;
V_40 = F_11 ( V_77 , struct V_14 , V_65 ) ;
V_84 = F_30 ( V_80 , V_40 ) ;
if ( ! V_84 ) {
F_14 ( & V_40 -> V_44 , V_42 ) ;
if ( V_40 -> V_16 . V_24 != V_80 -> V_16 . V_24 ) {
V_40 -> V_16 . V_24 = V_80 -> V_16 . V_24 ;
if ( V_40 -> V_16 . V_24 )
V_40 -> V_16 . V_24 -> V_72 = true ;
}
goto V_87;
}
if ( V_84 < 0 )
V_83 = & ( * V_83 ) -> V_88 ;
else
V_83 = & ( * V_83 ) -> V_89 ;
}
V_40 = F_23 ( V_80 ) ;
if ( ! V_40 )
goto V_90;
F_31 ( & V_40 -> V_65 , V_77 , V_83 ) ;
F_32 ( & V_40 -> V_65 , V_1 -> V_86 ) ;
V_87:
F_13 ( V_40 , V_82 -> V_41 , V_42 ) ;
V_90:
F_33 ( & V_1 -> V_85 ) ;
return V_40 ;
}
struct V_14 * F_34 ( struct V_1 * V_91 ,
struct V_81 * V_82 ,
struct V_76 * V_92 ,
struct V_25 * V_93 ,
T_2 V_42 )
{
struct V_14 V_80 = {
. V_21 = V_82 -> V_21 ,
. V_16 = {
. V_24 = V_93 -> V_30 . V_24 ,
. V_17 = V_93 -> V_30 . V_17 ,
} ,
. V_94 = V_82 -> V_94 ,
. V_95 = V_93 -> V_30 . V_96 ,
. V_62 = V_82 -> V_62 ,
. V_44 = {
. V_42 = V_42 ,
. V_53 = 1 ,
} ,
. V_77 = V_92 ,
. V_39 = F_27 ( V_92 ) ,
. V_25 = V_93 ,
. V_1 = V_91 ,
} ;
return F_28 ( V_91 , & V_80 , V_82 , V_42 ) ;
}
struct V_14 * F_35 ( struct V_1 * V_91 ,
struct V_81 * V_82 ,
struct V_76 * V_92 , T_2 V_42 )
{
struct V_14 V_80 = {
. V_21 = V_82 -> V_21 ,
. V_16 = {
. V_24 = V_82 -> V_24 ,
. V_17 = V_82 -> V_17 ,
} ,
. V_94 = V_82 -> V_94 ,
. V_95 = V_82 -> V_96 ,
. V_62 = V_82 -> V_62 ,
. V_44 = {
. V_42 = V_42 ,
. V_53 = 1 ,
} ,
. V_77 = V_92 ,
. V_39 = F_27 ( V_92 ) ,
. V_1 = V_91 ,
} ;
return F_28 ( V_91 , & V_80 , V_82 , V_42 ) ;
}
T_5
F_30 ( struct V_14 * V_97 , struct V_14 * V_98 )
{
struct V_99 * V_100 ;
T_5 V_84 = 0 ;
F_36 (se, &hist_entry__sort_list, list) {
V_84 = V_100 -> V_101 ( V_97 , V_98 ) ;
if ( V_84 )
break;
}
return V_84 ;
}
T_5
F_37 ( struct V_14 * V_97 , struct V_14 * V_98 )
{
struct V_99 * V_100 ;
T_5 V_84 = 0 ;
F_36 (se, &hist_entry__sort_list, list) {
T_5 (* F_38)( struct V_14 * , struct V_14 * );
F_38 = V_100 -> V_102 ? : V_100 -> V_101 ;
V_84 = F_38 ( V_97 , V_98 ) ;
if ( V_84 )
break;
}
return V_84 ;
}
void F_20 ( struct V_14 * V_40 )
{
free ( V_40 -> V_25 ) ;
free ( V_40 ) ;
}
static bool F_39 ( struct V_1 * V_1 V_103 ,
struct V_104 * V_105 ,
struct V_14 * V_40 )
{
struct V_34 * * V_83 = & V_105 -> V_34 ;
struct V_34 * V_77 = NULL ;
struct V_14 * V_106 ;
T_5 V_84 ;
while ( * V_83 != NULL ) {
V_77 = * V_83 ;
V_106 = F_11 ( V_77 , struct V_14 , V_65 ) ;
V_84 = F_37 ( V_106 , V_40 ) ;
if ( ! V_84 ) {
F_15 ( & V_106 -> V_44 , & V_40 -> V_44 ) ;
if ( V_10 . V_70 ) {
F_40 ( & V_107 ) ;
F_41 ( & V_107 ,
V_106 -> V_73 ,
V_40 -> V_73 ) ;
}
F_20 ( V_40 ) ;
return false ;
}
if ( V_84 < 0 )
V_83 = & ( * V_83 ) -> V_88 ;
else
V_83 = & ( * V_83 ) -> V_89 ;
}
F_31 ( & V_40 -> V_65 , V_77 , V_83 ) ;
F_32 ( & V_40 -> V_65 , V_105 ) ;
return true ;
}
static struct V_104 * F_42 ( struct V_1 * V_1 )
{
struct V_104 * V_105 ;
F_29 ( & V_1 -> V_85 ) ;
V_105 = V_1 -> V_86 ;
if ( ++ V_1 -> V_86 > & V_1 -> V_108 [ 1 ] )
V_1 -> V_86 = & V_1 -> V_108 [ 0 ] ;
F_33 ( & V_1 -> V_85 ) ;
return V_105 ;
}
static void F_43 ( struct V_1 * V_1 , struct V_14 * V_40 )
{
F_44 ( V_1 , V_40 ) ;
F_45 ( V_1 , V_40 ) ;
F_46 ( V_1 , V_40 ) ;
}
static void F_47 ( struct V_1 * V_1 , bool V_61 )
{
struct V_104 * V_105 ;
struct V_34 * V_35 ;
struct V_14 * V_37 ;
if ( ! V_64 && ! V_61 )
return;
V_105 = F_42 ( V_1 ) ;
V_35 = F_10 ( V_105 ) ;
while ( V_35 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_65 ) ;
V_35 = F_12 ( & V_37 -> V_65 ) ;
F_19 ( & V_37 -> V_65 , V_105 ) ;
if ( F_39 ( V_1 , & V_1 -> V_66 , V_37 ) ) {
F_43 ( V_1 , V_37 ) ;
}
}
}
void F_48 ( struct V_1 * V_1 )
{
return F_47 ( V_1 , false ) ;
}
void F_49 ( struct V_1 * V_1 )
{
return F_47 ( V_1 , true ) ;
}
static void F_50 ( struct V_104 * V_36 ,
struct V_14 * V_40 ,
T_2 V_109 )
{
struct V_34 * * V_83 = & V_36 -> V_34 ;
struct V_34 * V_77 = NULL ;
struct V_14 * V_106 ;
if ( V_10 . V_70 )
V_110 . V_111 ( & V_40 -> V_112 , V_40 -> V_73 ,
V_109 , & V_110 ) ;
while ( * V_83 != NULL ) {
V_77 = * V_83 ;
V_106 = F_11 ( V_77 , struct V_14 , V_34 ) ;
if ( V_40 -> V_44 . V_42 > V_106 -> V_44 . V_42 )
V_83 = & ( * V_83 ) -> V_88 ;
else
V_83 = & ( * V_83 ) -> V_89 ;
}
F_31 ( & V_40 -> V_34 , V_77 , V_83 ) ;
F_32 ( & V_40 -> V_34 , V_36 ) ;
}
static void F_51 ( struct V_1 * V_1 , bool V_61 )
{
struct V_104 * V_105 ;
struct V_34 * V_35 ;
struct V_14 * V_37 ;
T_2 V_109 ;
V_109 = V_1 -> V_57 . V_58 * ( V_110 . V_113 / 100 ) ;
if ( V_64 || V_61 )
V_105 = & V_1 -> V_66 ;
else
V_105 = V_1 -> V_86 ;
V_35 = F_10 ( V_105 ) ;
V_1 -> V_36 = V_114 ;
V_1 -> V_67 = 0 ;
V_1 -> V_57 . V_58 = 0 ;
F_4 ( V_1 ) ;
while ( V_35 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_65 ) ;
V_35 = F_12 ( & V_37 -> V_65 ) ;
F_50 ( & V_1 -> V_36 , V_37 , V_109 ) ;
F_26 ( V_1 , V_37 ) ;
}
}
void F_52 ( struct V_1 * V_1 )
{
return F_51 ( V_1 , false ) ;
}
void F_53 ( struct V_1 * V_1 )
{
return F_51 ( V_1 , true ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_115 V_116 )
{
V_15 -> V_39 &= ~ ( 1 << V_116 ) ;
if ( V_15 -> V_39 )
return;
++ V_1 -> V_67 ;
if ( V_15 -> V_16 . V_117 )
V_1 -> V_67 += V_15 -> V_118 ;
V_15 -> V_119 = 0 ;
V_1 -> V_57 . V_58 += V_15 -> V_44 . V_42 ;
V_1 -> V_57 . V_53 [ V_120 ] += V_15 -> V_44 . V_53 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_121 != NULL &&
( V_40 -> V_16 . V_24 == NULL || V_40 -> V_16 . V_24 -> V_7 != V_1 -> V_121 ) ) {
V_40 -> V_39 |= ( 1 << V_122 ) ;
return true ;
}
return false ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_34 * V_123 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_120 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_123 = F_10 ( & V_1 -> V_36 ) ; V_123 ; V_123 = F_12 ( V_123 ) ) {
struct V_14 * V_15 = F_11 ( V_123 , struct V_14 , V_34 ) ;
if ( V_10 . V_78 && ! V_15 -> V_77 )
continue;
if ( F_44 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_122 ) ;
}
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_124 != NULL &&
V_40 -> V_21 != V_1 -> V_124 ) {
V_40 -> V_39 |= ( 1 << V_125 ) ;
return true ;
}
return false ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_34 * V_123 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_120 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_123 = F_10 ( & V_1 -> V_36 ) ; V_123 ; V_123 = F_12 ( V_123 ) ) {
struct V_14 * V_15 = F_11 ( V_123 , struct V_14 , V_34 ) ;
if ( F_45 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_125 ) ;
}
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_126 != NULL &&
( ! V_40 -> V_16 . V_17 || strstr ( V_40 -> V_16 . V_17 -> V_127 ,
V_1 -> V_126 ) == NULL ) ) {
V_40 -> V_39 |= ( 1 << V_128 ) ;
return true ;
}
return false ;
}
void F_57 ( struct V_1 * V_1 )
{
struct V_34 * V_123 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_120 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_123 = F_10 ( & V_1 -> V_36 ) ; V_123 ; V_123 = F_12 ( V_123 ) ) {
struct V_14 * V_15 = F_11 ( V_123 , struct V_14 , V_34 ) ;
if ( F_46 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_128 ) ;
}
}
int F_58 ( struct V_14 * V_40 , int V_129 , T_2 V_95 )
{
return F_59 ( V_40 -> V_16 . V_17 , V_40 -> V_16 . V_24 , V_129 , V_95 ) ;
}
int F_60 ( struct V_14 * V_40 , T_3 V_130 )
{
return F_61 ( V_40 -> V_16 . V_17 , V_40 -> V_16 . V_24 , V_130 ) ;
}
void F_62 ( struct V_1 * V_1 , T_6 type )
{
++ V_1 -> V_57 . V_53 [ 0 ] ;
++ V_1 -> V_57 . V_53 [ type ] ;
}
static struct V_14 * F_63 ( struct V_1 * V_1 ,
struct V_14 * V_131 )
{
struct V_34 * * V_83 = & V_1 -> V_36 . V_34 ;
struct V_34 * V_77 = NULL ;
struct V_14 * V_40 ;
int V_84 ;
while ( * V_83 != NULL ) {
V_77 = * V_83 ;
V_40 = F_11 ( V_77 , struct V_14 , V_34 ) ;
V_84 = F_30 ( V_131 , V_40 ) ;
if ( ! V_84 )
goto V_87;
if ( V_84 < 0 )
V_83 = & ( * V_83 ) -> V_88 ;
else
V_83 = & ( * V_83 ) -> V_89 ;
}
V_40 = F_23 ( V_131 ) ;
if ( V_40 ) {
memset ( & V_40 -> V_44 , 0 , sizeof( V_40 -> V_44 ) ) ;
V_40 -> V_1 = V_1 ;
F_31 ( & V_40 -> V_34 , V_77 , V_83 ) ;
F_32 ( & V_40 -> V_34 , & V_1 -> V_36 ) ;
F_26 ( V_1 , V_40 ) ;
}
V_87:
return V_40 ;
}
static struct V_14 * F_64 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
struct V_34 * V_37 = V_1 -> V_36 . V_34 ;
while ( V_37 ) {
struct V_14 * V_106 = F_11 ( V_37 , struct V_14 , V_34 ) ;
T_5 V_84 = F_30 ( V_40 , V_106 ) ;
if ( V_84 < 0 )
V_37 = V_37 -> V_88 ;
else if ( V_84 > 0 )
V_37 = V_37 -> V_89 ;
else
return V_106 ;
}
return NULL ;
}
void F_65 ( struct V_1 * V_132 , struct V_1 * V_133 )
{
struct V_34 * V_123 ;
struct V_14 * V_134 , * V_131 ;
for ( V_123 = F_10 ( & V_132 -> V_36 ) ; V_123 ; V_123 = F_12 ( V_123 ) ) {
V_134 = F_11 ( V_123 , struct V_14 , V_34 ) ;
V_131 = F_64 ( V_133 , V_134 ) ;
if ( V_131 )
F_66 ( V_134 , V_131 ) ;
}
}
int F_67 ( struct V_1 * V_132 , struct V_1 * V_133 )
{
struct V_34 * V_123 ;
struct V_14 * V_134 , * V_131 ;
for ( V_123 = F_10 ( & V_133 -> V_36 ) ; V_123 ; V_123 = F_12 ( V_123 ) ) {
V_134 = F_11 ( V_123 , struct V_14 , V_34 ) ;
if ( ! F_68 ( V_134 ) ) {
V_131 = F_63 ( V_132 , V_134 ) ;
if ( V_131 == NULL )
return - 1 ;
F_66 ( V_131 , V_134 ) ;
}
}
return 0 ;
}
