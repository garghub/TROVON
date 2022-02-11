static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static int F_3 ( T_1 V_5 , T_1 V_6 , T_2 V_7 )
{
T_2 V_8 ;
V_7 -= sizeof( struct V_9 ) ;
V_8 = ( V_6 + 1 ) * sizeof( struct V_10 ) ;
return V_5 + V_8 > V_7 ? 0 : 1 ;
}
static T_2 F_4 ( T_1 V_11 , T_1 * V_12 , T_1 V_13 ,
T_2 V_7 )
{
T_2 V_14 ;
V_7 -= sizeof( struct V_15 ) ;
if ( V_11 + V_13 > V_7 )
V_14 = V_7 - V_11 ;
else
V_14 = V_13 ;
if ( * V_12 && V_14 > * V_12 )
V_14 = * V_12 ;
if ( * V_12 && V_14 < * V_12 )
* V_12 = V_14 ;
return V_14 ;
}
static T_2 F_5 ( T_1 V_5 , T_1 V_6 , T_2 V_13 ,
T_2 V_7 )
{
T_2 V_8 ;
V_7 -= sizeof( struct V_9 ) ;
V_8 = ( V_6 + 1 ) * sizeof( struct V_10 ) ;
if ( V_5 + V_8 + V_13 > V_7 )
return V_7 - ( V_5 + sizeof( struct V_10 ) ) ;
return V_13 ;
}
static void F_6 ( struct V_2 * V_3 )
{
V_3 -> V_16 = NULL ;
V_3 -> V_17 = NULL ;
V_3 -> V_18 = 0 ;
V_3 -> V_19 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
static bool F_7 ( struct V_2 * V_3 )
{
struct V_22 * V_17 = V_3 -> V_17 ;
if ( ( V_3 -> V_19 + V_3 -> V_20 == V_17 -> V_13 ) ||
( V_3 -> V_18 + V_3 -> V_20 == V_17 -> V_13 ) )
return true ;
return false ;
}
static int F_8 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_22 * V_17 = V_3 -> V_17 ;
if ( V_24 -> V_25 != V_26 )
return 0 ;
if ( F_7 ( V_3 ) ) {
V_3 -> V_19 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_21 = 0 ;
if ( V_17 == F_9 ( & V_24 -> V_27 ,
struct V_22 ,
V_28 ) )
V_24 -> V_25 = V_29 ;
else
V_3 -> V_16 = F_10 ( V_17 ,
V_28 ) ;
return 0 ;
}
V_3 -> V_16 = V_17 ;
if ( V_17 -> V_30 )
V_3 -> V_19 += V_3 -> V_20 ;
if ( V_17 -> V_31 )
V_3 -> V_18 += V_3 -> V_20 ;
return 0 ;
}
static struct V_22 * F_11 ( struct V_22 * V_32 ,
struct V_23 * V_24 )
{
if ( V_32 == F_9 ( & V_24 -> V_27 , struct V_22 ,
V_28 ) )
return NULL ;
return F_10 ( V_32 , V_28 ) ;
}
static struct V_33 * F_12 ( struct V_2 * V_3 ,
struct V_34 * V_4 , struct V_23 * V_24 )
{
struct V_9 * V_35 ;
struct V_36 * V_37 = V_24 -> V_3 ;
struct V_22 * V_32 ;
struct V_10 * V_38 ;
struct V_33 * V_39 ;
T_1 V_5 = 0 , V_11 = 0 , V_6 = 0 , V_40 = 0 , V_41 ;
T_1 V_12 = 0 , V_14 = 0 , V_13 ;
T_1 V_42 = 0 ;
unsigned int V_43 ;
T_2 V_7 ;
void * V_44 ;
V_7 = F_13 ( V_4 ) ;
V_32 = V_3 -> V_16 ;
while ( V_24 -> V_25 != V_45 ) {
V_24 -> V_25 = V_46 ;
V_3 -> V_17 = V_32 ;
if ( ! V_32 -> V_30 && ! V_32 -> V_31 ) {
F_14 ( V_3 -> V_47 ,
L_1 , V_32 -> V_13 ) ;
V_24 -> V_25 = V_48 ;
return NULL ;
}
V_12 = 0 ;
V_14 = 0 ;
if ( V_32 -> V_30 ) {
V_13 = V_32 -> V_13 - V_3 -> V_19 ;
if ( ! F_3 ( V_5 , V_6 , V_7 ) )
break;
V_12 = F_5 ( V_5 , V_6 ,
V_13 , V_7 ) ;
V_3 -> V_20 = V_12 ;
}
if ( V_32 -> V_31 ) {
V_13 = V_32 -> V_13 - V_3 -> V_18 ;
V_14 = F_4 ( V_11 , & V_12 ,
V_13 , V_7 ) ;
V_3 -> V_20 = V_14 ;
}
V_5 += V_12 ;
V_11 += V_14 ;
V_42 += V_3 -> V_20 ;
V_6 ++ ;
V_32 = F_11 ( V_32 , V_24 ) ;
if ( ! V_32 || V_42 >= V_7 )
V_24 -> V_25 = V_45 ;
}
V_41 = sizeof( * V_35 ) ;
V_41 += V_6 * sizeof( * V_38 ) ;
V_41 += V_5 ;
V_39 = F_15 ( V_4 , V_49 ,
V_41 , V_11 , V_50 ) ;
if ( ! V_39 )
return NULL ;
V_35 = V_39 -> V_35 -> V_51 ;
V_35 -> V_6 = F_16 ( V_6 ) ;
V_35 -> V_52 = V_37 -> V_52 ;
V_35 -> V_53 = V_37 -> V_53 ;
V_38 = & V_35 -> V_27 [ 0 ] ;
V_44 = V_38 + V_6 ;
V_32 = V_3 -> V_16 ;
while ( V_24 -> V_25 != V_26 ) {
if ( V_32 == V_3 -> V_17 )
V_40 = V_3 -> V_20 ;
else
V_40 = V_32 -> V_13 ;
V_43 = V_40 * 8 * V_54 / V_32 -> V_55 ;
V_43 += V_56 ;
if ( V_43 > V_3 -> V_21 )
V_3 -> V_21 = V_43 ;
V_38 -> V_55 = F_17 ( V_32 -> V_55 ) ;
V_38 -> V_13 = F_17 ( V_40 ) ;
V_38 -> V_57 = F_16 ( V_32 -> V_57 ) ;
V_38 -> V_58 = V_32 -> V_58 ;
V_38 -> V_59 = V_32 -> V_59 ;
if ( V_32 -> V_30 ) {
V_38 -> V_60 |= V_61 ;
memcpy ( V_44 , V_32 -> V_30 + V_3 -> V_19 ,
V_40 ) ;
V_44 += V_40 ;
}
if ( V_32 -> V_31 )
V_38 -> V_60 |= V_62 ;
if ( V_32 == V_3 -> V_17 ) {
if ( ! F_7 ( V_3 ) )
V_38 -> V_60 |= V_63 ;
V_24 -> V_25 = V_26 ;
continue;
}
V_38 ++ ;
V_32 = F_11 ( V_32 , V_24 ) ;
}
V_24 -> V_64 += V_42 ;
return V_39 ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_15 * V_65 )
{
struct V_22 * V_32 = V_3 -> V_16 ;
void * V_66 = V_65 -> V_67 ;
T_1 V_40 ;
while ( V_32 ) {
if ( V_32 -> V_31 ) {
if ( V_32 == V_3 -> V_16 )
V_40 = V_32 -> V_13 - V_3 -> V_18 ;
else if ( V_32 == V_3 -> V_17 )
V_40 = V_3 -> V_20 ;
else
V_40 = V_32 -> V_13 ;
memcpy ( V_32 -> V_31 + V_3 -> V_18 , V_66 ,
V_40 ) ;
V_66 += V_40 ;
}
if ( V_32 == V_3 -> V_17 )
break;
V_32 = F_10 ( V_32 , V_28 ) ;
}
}
static int F_19 ( struct V_1 * V_68 ,
struct V_23 * V_24 )
{
struct V_2 * V_3 = F_20 ( V_68 ) ;
struct V_34 * V_4 = V_3 -> V_4 ;
struct V_15 * V_65 ;
struct V_33 * V_39 ;
int V_69 = 0 ;
V_3 -> V_16 = F_21 ( & V_24 -> V_27 ,
struct V_22 ,
V_28 ) ;
if ( ! V_3 -> V_16 ) {
V_69 = - V_70 ;
goto V_71;
}
V_24 -> V_25 = V_72 ;
while ( V_24 -> V_25 != V_29 &&
V_24 -> V_25 != V_48 ) {
V_39 = F_12 ( V_3 , V_4 , V_24 ) ;
if ( ! V_39 ) {
V_24 -> V_25 = V_48 ;
V_69 = - V_73 ;
continue;
}
V_69 = F_22 ( V_39 ,
V_3 -> V_21 ) ;
if ( ! V_69 ) {
V_65 = V_39 -> V_65 -> V_51 ;
if ( V_65 )
F_18 ( V_3 , V_24 , V_65 ) ;
} else {
F_14 ( V_3 -> V_47 ,
L_2 , V_69 ) ;
V_24 -> V_25 = V_48 ;
}
F_23 ( V_39 ) ;
F_8 ( V_3 , V_24 ) ;
}
V_71:
V_24 -> V_74 = V_69 ;
F_6 ( V_3 ) ;
F_24 ( V_68 ) ;
return V_69 ;
}
static int F_25 ( struct V_1 * V_68 )
{
struct V_2 * V_3 = F_20 ( V_68 ) ;
return V_3 -> V_75 -> V_76 ( V_3 -> V_47 ) ;
}
static int F_26 ( struct V_1 * V_68 )
{
struct V_2 * V_3 = F_20 ( V_68 ) ;
V_3 -> V_75 -> V_77 ( V_3 -> V_47 ) ;
return 0 ;
}
static int F_27 ( struct V_36 * V_3 )
{
return 0 ;
}
static void F_28 ( struct V_36 * V_3 )
{
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_78 V_65 ;
T_3 V_52 , V_79 ;
int V_69 ;
V_69 = F_30 ( V_3 -> V_4 , V_80 ,
NULL , 0 , & V_65 , sizeof( V_65 ) ) ;
if ( V_69 < 0 )
return V_69 ;
V_52 = F_31 ( V_65 . V_52 ) ;
V_3 -> V_52 = F_32 ( V_52 ) ;
V_79 = F_31 ( V_65 . V_79 ) ;
V_3 -> V_79 = F_33 ( V_79 ) ;
V_3 -> V_81 = F_34 ( V_65 . V_81 ) ;
V_3 -> V_82 = V_65 . V_82 ;
V_3 -> V_83 = F_34 ( V_65 . V_83 ) ;
V_3 -> V_84 = F_34 ( V_65 . V_84 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , T_4 V_85 )
{
struct V_1 * V_68 = F_1 ( V_3 ) ;
struct V_86 V_35 ;
struct V_87 V_65 ;
struct V_88 V_89 = { { 0 } } ;
struct V_36 * V_90 ;
int V_69 ;
T_4 V_91 ;
V_35 . V_53 = V_85 ;
V_69 = F_30 ( V_3 -> V_4 , V_92 ,
& V_35 , sizeof( V_35 ) ,
& V_65 , sizeof( V_65 ) ) ;
if ( V_69 < 0 )
return V_69 ;
V_91 = V_65 . V_93 ;
if ( V_91 == V_94 )
F_36 ( V_89 . V_95 , L_3 ,
sizeof( V_89 . V_95 ) ) ;
else if ( V_91 == V_96 )
F_36 ( V_89 . V_95 , L_4 ,
sizeof( V_89 . V_95 ) ) ;
else if ( V_91 == V_97 )
memcpy ( V_89 . V_95 , V_65 . V_98 ,
sizeof( V_89 . V_95 ) ) ;
else
return - V_73 ;
V_89 . V_52 = F_31 ( V_65 . V_52 ) ;
V_89 . V_99 = V_68 -> V_99 ;
V_89 . V_53 = V_85 ;
V_89 . V_84 = F_34 ( V_65 . V_84 ) ;
V_90 = F_37 ( V_68 , & V_89 ) ;
if ( ! V_90 )
return - V_73 ;
return 0 ;
}
int F_38 ( struct V_34 * V_4 , struct V_100 * V_37 ,
struct V_101 * V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_68 ;
int V_69 ;
T_4 V_102 ;
V_68 = F_39 ( V_37 , sizeof( * V_3 ) ) ;
if ( ! V_68 ) {
F_14 ( V_37 , L_5 ) ;
return - V_70 ;
}
V_3 = F_20 ( V_68 ) ;
V_3 -> V_4 = V_4 ;
F_40 ( V_4 , V_68 ) ;
V_3 -> V_47 = V_37 ;
V_3 -> V_75 = V_75 ;
V_69 = F_29 ( V_3 ) ;
if ( V_69 )
goto V_103;
V_68 -> V_99 = - 1 ;
V_68 -> V_82 = V_3 -> V_82 ;
V_68 -> V_104 = V_3 -> V_52 ;
V_68 -> V_79 = V_3 -> V_79 ;
V_68 -> V_81 = V_3 -> V_81 ;
V_68 -> V_105 = F_28 ;
V_68 -> V_106 = F_27 ;
V_68 -> V_107 = F_19 ;
if ( V_75 && V_75 -> V_76 ) {
V_68 -> V_76 =
F_25 ;
}
if ( V_75 && V_75 -> V_77 ) {
V_68 -> V_77 =
F_26 ;
}
V_68 -> V_108 = true ;
V_69 = F_41 ( V_68 ) ;
if ( V_69 < 0 )
goto V_103;
for ( V_102 = 0 ; V_102 < V_3 -> V_82 ; V_102 ++ ) {
V_69 = F_35 ( V_3 , V_102 ) ;
if ( V_69 < 0 ) {
F_14 ( V_37 , L_6 ,
V_102 , V_69 ) ;
goto V_109;
}
}
return 0 ;
V_109:
F_42 ( V_68 ) ;
V_103:
F_43 ( V_68 ) ;
return V_69 ;
}
void F_44 ( struct V_34 * V_4 )
{
struct V_1 * V_68 = F_2 ( V_4 ) ;
F_42 ( V_68 ) ;
F_43 ( V_68 ) ;
}
