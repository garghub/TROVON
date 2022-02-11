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
}
return V_40 ;
}
static void F_25 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_39 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_67 ;
V_1 -> V_57 . V_58 += V_15 -> V_44 . V_42 ;
}
}
static T_4 F_26 ( const struct V_74 * V_75 )
{
if ( V_10 . V_76 && V_75 == NULL )
return 1 << V_77 ;
return 0 ;
}
static struct V_14 * F_27 ( struct V_1 * V_1 ,
struct V_14 * V_78 ,
struct V_79 * V_80 ,
T_2 V_42 )
{
struct V_34 * * V_81 ;
struct V_34 * V_75 = NULL ;
struct V_14 * V_40 ;
int V_82 ;
F_28 ( & V_1 -> V_83 ) ;
V_81 = & V_1 -> V_84 -> V_34 ;
while ( * V_81 != NULL ) {
V_75 = * V_81 ;
V_40 = F_11 ( V_75 , struct V_14 , V_65 ) ;
V_82 = F_29 ( V_78 , V_40 ) ;
if ( ! V_82 ) {
F_14 ( & V_40 -> V_44 , V_42 ) ;
if ( V_40 -> V_16 . V_24 != V_78 -> V_16 . V_24 ) {
V_40 -> V_16 . V_24 = V_78 -> V_16 . V_24 ;
if ( V_40 -> V_16 . V_24 )
V_40 -> V_16 . V_24 -> V_72 = true ;
}
goto V_85;
}
if ( V_82 < 0 )
V_81 = & ( * V_81 ) -> V_86 ;
else
V_81 = & ( * V_81 ) -> V_87 ;
}
V_40 = F_23 ( V_78 ) ;
if ( ! V_40 )
goto V_88;
F_30 ( & V_40 -> V_65 , V_75 , V_81 ) ;
F_31 ( & V_40 -> V_65 , V_1 -> V_84 ) ;
V_85:
F_13 ( V_40 , V_80 -> V_41 , V_42 ) ;
V_88:
F_32 ( & V_1 -> V_83 ) ;
return V_40 ;
}
struct V_14 * F_33 ( struct V_1 * V_89 ,
struct V_79 * V_80 ,
struct V_74 * V_90 ,
struct V_25 * V_91 ,
T_2 V_42 )
{
struct V_14 V_78 = {
. V_21 = V_80 -> V_21 ,
. V_16 = {
. V_24 = V_91 -> V_30 . V_24 ,
. V_17 = V_91 -> V_30 . V_17 ,
} ,
. V_92 = V_80 -> V_92 ,
. V_93 = V_91 -> V_30 . V_94 ,
. V_62 = V_80 -> V_62 ,
. V_44 = {
. V_42 = V_42 ,
. V_53 = 1 ,
} ,
. V_75 = V_90 ,
. V_39 = F_26 ( V_90 ) ,
. V_25 = V_91 ,
. V_1 = V_89 ,
} ;
return F_27 ( V_89 , & V_78 , V_80 , V_42 ) ;
}
struct V_14 * F_34 ( struct V_1 * V_89 ,
struct V_79 * V_80 ,
struct V_74 * V_90 , T_2 V_42 )
{
struct V_14 V_78 = {
. V_21 = V_80 -> V_21 ,
. V_16 = {
. V_24 = V_80 -> V_24 ,
. V_17 = V_80 -> V_17 ,
} ,
. V_92 = V_80 -> V_92 ,
. V_93 = V_80 -> V_94 ,
. V_62 = V_80 -> V_62 ,
. V_44 = {
. V_42 = V_42 ,
. V_53 = 1 ,
} ,
. V_75 = V_90 ,
. V_39 = F_26 ( V_90 ) ,
. V_1 = V_89 ,
} ;
return F_27 ( V_89 , & V_78 , V_80 , V_42 ) ;
}
T_5
F_29 ( struct V_14 * V_95 , struct V_14 * V_96 )
{
struct V_97 * V_98 ;
T_5 V_82 = 0 ;
F_35 (se, &hist_entry__sort_list, list) {
V_82 = V_98 -> V_99 ( V_95 , V_96 ) ;
if ( V_82 )
break;
}
return V_82 ;
}
T_5
F_36 ( struct V_14 * V_95 , struct V_14 * V_96 )
{
struct V_97 * V_98 ;
T_5 V_82 = 0 ;
F_35 (se, &hist_entry__sort_list, list) {
T_5 (* F_37)( struct V_14 * , struct V_14 * );
F_37 = V_98 -> V_100 ? : V_98 -> V_99 ;
V_82 = F_37 ( V_95 , V_96 ) ;
if ( V_82 )
break;
}
return V_82 ;
}
void F_20 ( struct V_14 * V_40 )
{
free ( V_40 ) ;
}
static bool F_38 ( struct V_1 * V_1 V_101 ,
struct V_102 * V_103 ,
struct V_14 * V_40 )
{
struct V_34 * * V_81 = & V_103 -> V_34 ;
struct V_34 * V_75 = NULL ;
struct V_14 * V_104 ;
T_5 V_82 ;
while ( * V_81 != NULL ) {
V_75 = * V_81 ;
V_104 = F_11 ( V_75 , struct V_14 , V_65 ) ;
V_82 = F_36 ( V_104 , V_40 ) ;
if ( ! V_82 ) {
F_15 ( & V_104 -> V_44 , & V_40 -> V_44 ) ;
if ( V_10 . V_70 ) {
F_39 ( & V_105 ) ;
F_40 ( & V_105 ,
V_104 -> V_73 ,
V_40 -> V_73 ) ;
}
F_20 ( V_40 ) ;
return false ;
}
if ( V_82 < 0 )
V_81 = & ( * V_81 ) -> V_86 ;
else
V_81 = & ( * V_81 ) -> V_87 ;
}
F_30 ( & V_40 -> V_65 , V_75 , V_81 ) ;
F_31 ( & V_40 -> V_65 , V_103 ) ;
return true ;
}
static struct V_102 * F_41 ( struct V_1 * V_1 )
{
struct V_102 * V_103 ;
F_28 ( & V_1 -> V_83 ) ;
V_103 = V_1 -> V_84 ;
if ( ++ V_1 -> V_84 > & V_1 -> V_106 [ 1 ] )
V_1 -> V_84 = & V_1 -> V_106 [ 0 ] ;
F_32 ( & V_1 -> V_83 ) ;
return V_103 ;
}
static void F_42 ( struct V_1 * V_1 , struct V_14 * V_40 )
{
F_43 ( V_1 , V_40 ) ;
F_44 ( V_1 , V_40 ) ;
F_45 ( V_1 , V_40 ) ;
}
static void F_46 ( struct V_1 * V_1 , bool V_61 )
{
struct V_102 * V_103 ;
struct V_34 * V_35 ;
struct V_14 * V_37 ;
if ( ! V_64 && ! V_61 )
return;
V_103 = F_41 ( V_1 ) ;
V_35 = F_10 ( V_103 ) ;
while ( V_35 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_65 ) ;
V_35 = F_12 ( & V_37 -> V_65 ) ;
F_19 ( & V_37 -> V_65 , V_103 ) ;
if ( F_38 ( V_1 , & V_1 -> V_66 , V_37 ) ) {
F_42 ( V_1 , V_37 ) ;
}
}
}
void F_47 ( struct V_1 * V_1 )
{
return F_46 ( V_1 , false ) ;
}
void F_48 ( struct V_1 * V_1 )
{
return F_46 ( V_1 , true ) ;
}
static void F_49 ( struct V_102 * V_36 ,
struct V_14 * V_40 ,
T_2 V_107 )
{
struct V_34 * * V_81 = & V_36 -> V_34 ;
struct V_34 * V_75 = NULL ;
struct V_14 * V_104 ;
if ( V_10 . V_70 )
V_108 . V_109 ( & V_40 -> V_110 , V_40 -> V_73 ,
V_107 , & V_108 ) ;
while ( * V_81 != NULL ) {
V_75 = * V_81 ;
V_104 = F_11 ( V_75 , struct V_14 , V_34 ) ;
if ( V_40 -> V_44 . V_42 > V_104 -> V_44 . V_42 )
V_81 = & ( * V_81 ) -> V_86 ;
else
V_81 = & ( * V_81 ) -> V_87 ;
}
F_30 ( & V_40 -> V_34 , V_75 , V_81 ) ;
F_31 ( & V_40 -> V_34 , V_36 ) ;
}
static void F_50 ( struct V_1 * V_1 , bool V_61 )
{
struct V_102 * V_103 ;
struct V_34 * V_35 ;
struct V_14 * V_37 ;
T_2 V_107 ;
V_107 = V_1 -> V_57 . V_58 * ( V_108 . V_111 / 100 ) ;
if ( V_64 || V_61 )
V_103 = & V_1 -> V_66 ;
else
V_103 = V_1 -> V_84 ;
V_35 = F_10 ( V_103 ) ;
V_1 -> V_36 = V_112 ;
V_1 -> V_67 = 0 ;
V_1 -> V_57 . V_58 = 0 ;
F_4 ( V_1 ) ;
while ( V_35 ) {
V_37 = F_11 ( V_35 , struct V_14 , V_65 ) ;
V_35 = F_12 ( & V_37 -> V_65 ) ;
F_49 ( & V_1 -> V_36 , V_37 , V_107 ) ;
F_25 ( V_1 , V_37 ) ;
}
}
void F_51 ( struct V_1 * V_1 )
{
return F_50 ( V_1 , false ) ;
}
void F_52 ( struct V_1 * V_1 )
{
return F_50 ( V_1 , true ) ;
}
static void F_53 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_113 V_114 )
{
V_15 -> V_39 &= ~ ( 1 << V_114 ) ;
if ( V_15 -> V_39 )
return;
++ V_1 -> V_67 ;
if ( V_15 -> V_16 . V_115 )
V_1 -> V_67 += V_15 -> V_116 ;
V_15 -> V_117 = 0 ;
V_1 -> V_57 . V_58 += V_15 -> V_44 . V_42 ;
V_1 -> V_57 . V_53 [ V_118 ] += V_15 -> V_44 . V_53 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_43 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_119 != NULL &&
( V_40 -> V_16 . V_24 == NULL || V_40 -> V_16 . V_24 -> V_7 != V_1 -> V_119 ) ) {
V_40 -> V_39 |= ( 1 << V_120 ) ;
return true ;
}
return false ;
}
void F_54 ( struct V_1 * V_1 )
{
struct V_34 * V_121 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_118 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_121 = F_10 ( & V_1 -> V_36 ) ; V_121 ; V_121 = F_12 ( V_121 ) ) {
struct V_14 * V_15 = F_11 ( V_121 , struct V_14 , V_34 ) ;
if ( V_10 . V_76 && ! V_15 -> V_75 )
continue;
if ( F_43 ( V_1 , V_15 ) )
continue;
F_53 ( V_1 , V_15 , V_120 ) ;
}
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_122 != NULL &&
V_40 -> V_21 != V_1 -> V_122 ) {
V_40 -> V_39 |= ( 1 << V_123 ) ;
return true ;
}
return false ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_34 * V_121 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_118 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_121 = F_10 ( & V_1 -> V_36 ) ; V_121 ; V_121 = F_12 ( V_121 ) ) {
struct V_14 * V_15 = F_11 ( V_121 , struct V_14 , V_34 ) ;
if ( F_44 ( V_1 , V_15 ) )
continue;
F_53 ( V_1 , V_15 , V_123 ) ;
}
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_14 * V_40 )
{
if ( V_1 -> V_124 != NULL &&
( ! V_40 -> V_16 . V_17 || strstr ( V_40 -> V_16 . V_17 -> V_125 ,
V_1 -> V_124 ) == NULL ) ) {
V_40 -> V_39 |= ( 1 << V_126 ) ;
return true ;
}
return false ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_34 * V_121 ;
V_1 -> V_67 = V_1 -> V_57 . V_58 = 0 ;
V_1 -> V_57 . V_53 [ V_118 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_121 = F_10 ( & V_1 -> V_36 ) ; V_121 ; V_121 = F_12 ( V_121 ) ) {
struct V_14 * V_15 = F_11 ( V_121 , struct V_14 , V_34 ) ;
if ( F_45 ( V_1 , V_15 ) )
continue;
F_53 ( V_1 , V_15 , V_126 ) ;
}
}
int F_57 ( struct V_14 * V_40 , int V_127 , T_2 V_93 )
{
return F_58 ( V_40 -> V_16 . V_17 , V_40 -> V_16 . V_24 , V_127 , V_93 ) ;
}
int F_59 ( struct V_14 * V_40 , T_3 V_128 )
{
return F_60 ( V_40 -> V_16 . V_17 , V_40 -> V_16 . V_24 , V_128 ) ;
}
void F_61 ( struct V_1 * V_1 , T_6 type )
{
++ V_1 -> V_57 . V_53 [ 0 ] ;
++ V_1 -> V_57 . V_53 [ type ] ;
}
