static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_8 , V_7 ) ;
}
static void * F_4 ( const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_15 , V_16 | V_17 ) ;
if ( V_14 != NULL )
F_6 ( & V_14 -> V_18 . V_19 ) ;
else
V_14 = F_7 ( - V_20 ) ;
return V_14 ;
}
static void F_8 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_21 )
{
struct V_13 * V_14 = V_21 ;
F_9 ( F_10 ( & V_14 -> V_18 . V_19 ) ) ;
F_3 ( V_15 , V_14 ) ;
}
static void * F_11 ( const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_22 * V_14 ;
V_14 = F_5 ( V_23 , V_16 | V_17 ) ;
if ( V_14 == NULL )
V_14 = F_7 ( - V_20 ) ;
return V_14 ;
}
static void F_12 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_21 )
{
struct V_22 * V_14 = V_21 ;
F_3 ( V_23 , V_14 ) ;
}
static struct V_24 * F_13 ( const struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_26 ;
struct V_27 * V_28 = F_14 ( V_25 ) ;
F_15 ( V_28 -> V_29 != NULL ) ;
if ( V_28 -> V_30 == NULL )
return NULL ;
F_16 (ld, i) {
struct V_31 * V_32 ;
V_32 = V_28 -> V_30 [ V_26 ] ;
if ( V_32 != NULL ) {
F_17 ( V_2 , F_18 ( V_32 ) ) ;
V_28 -> V_30 [ V_26 ] = NULL ;
}
}
return NULL ;
}
static int F_19 ( const struct V_1 * V_2 , struct V_24 * V_25 ,
const char * V_33 , struct V_24 * V_34 )
{
struct V_27 * V_28 = F_14 ( V_25 ) ;
int V_26 ;
int V_35 = 0 ;
F_15 ( V_25 -> V_36 != NULL ) ;
if ( V_28 -> V_30 == NULL )
return V_35 ;
F_16 (ld, i) {
struct V_31 * V_32 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_40 = V_28 -> V_29 -> V_41 [ V_26 ] ;
if ( V_40 == NULL )
continue;
V_38 = F_20 ( V_2 , V_25 -> V_36 , & V_42 ,
V_40 -> V_43 -> V_44 ) ;
if ( F_21 ( V_38 ) ) {
V_35 = F_22 ( V_38 ) ;
break;
}
V_32 = F_23 ( V_38 ) ;
V_32 -> V_45 = V_26 ;
V_32 -> V_46 = V_28 ;
V_28 -> V_30 [ V_26 ] = V_32 ;
}
if ( V_35 )
F_13 ( V_2 , V_25 ) ;
else
V_28 -> V_47 |= V_48 ;
return V_35 ;
}
static int F_24 ( const struct V_1 * V_2 , struct V_37 * V_49 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 ;
int V_52 ;
V_7 = F_5 ( V_8 , V_16 | V_17 ) ;
if ( V_7 != NULL ) {
F_25 ( V_51 , & V_7 -> V_53 , V_49 , & V_54 ) ;
V_52 = 0 ;
} else
V_52 = - V_20 ;
return V_52 ;
}
static void F_26 ( struct V_55 * * V_56 , int V_57 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_57 ; ++ V_26 ) {
struct V_55 * V_58 ;
V_58 = V_56 [ V_26 ] ;
if ( V_58 != NULL ) {
F_15 ( V_58 -> V_59 . V_60 == 0 ) ;
if ( V_58 -> V_61 != NULL )
F_27 ( V_58 -> V_61 , & V_58 -> V_62 ) ;
F_28 ( V_58 ) ;
}
}
F_28 ( V_56 ) ;
}
static struct V_24 * F_29 ( const struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_27 * V_28 = F_14 ( V_25 ) ;
const int V_57 = V_28 -> V_63 ;
F_30 ( F_31 ( V_25 ) ) ;
F_28 ( V_28 -> V_30 ) ;
if ( V_28 -> V_64 != NULL )
F_26 ( V_28 -> V_64 , V_57 ) ;
F_28 ( V_28 ) ;
return NULL ;
}
static void F_32 ( const struct V_1 * V_2 , struct V_24 * V_49 ,
T_1 V_65 )
{
struct V_27 * V_28 = F_14 ( V_49 ) ;
if ( V_28 -> V_30 [ V_65 ] != NULL ) {
F_17 ( V_2 , F_18 ( V_28 -> V_30 [ V_65 ] ) ) ;
V_28 -> V_30 [ V_65 ] = NULL ;
}
}
static struct V_55 * * F_33 ( int V_57 )
{
struct V_55 * * V_66 ;
int V_26 ;
int V_52 ;
V_66 = F_34 ( V_57 , sizeof( V_66 [ 0 ] ) , V_16 ) ;
if ( V_66 == NULL )
return F_7 ( - V_20 ) ;
for ( V_52 = V_26 = 0 ; V_26 < V_57 && V_52 == 0 ; V_26 ++ ) {
struct V_55 * V_58 ;
V_58 = F_35 ( sizeof( * V_58 ) , V_16 ) ;
if ( V_58 != NULL ) {
V_66 [ V_26 ] = V_58 ;
F_36 ( & V_58 -> V_59 ) ;
V_58 -> V_61 = F_37 ( & V_58 -> V_62 ,
V_67 | V_68 ) ;
if ( ! F_21 ( V_58 -> V_61 ) )
V_58 -> V_61 -> V_69 . V_70 = 0x2 ;
else {
V_52 = F_22 ( V_58 -> V_61 ) ;
V_58 -> V_61 = NULL ;
}
} else
V_52 = - V_20 ;
}
if ( V_52 != 0 ) {
F_26 ( V_66 , V_57 ) ;
V_66 = F_7 ( V_52 ) ;
}
return V_66 ;
}
static int F_38 ( const struct V_1 * V_2 , struct V_27 * V_49 )
{
int V_52 ;
T_1 V_71 ;
T_1 V_72 ;
V_52 = 0 ;
V_71 = V_49 -> V_29 -> V_73 ;
V_72 = V_49 -> V_63 ;
if ( V_72 < V_71 ) {
struct V_31 * * V_74 ;
struct V_55 * * V_66 ;
const T_2 V_75 = sizeof( V_74 [ 0 ] ) ;
V_66 = F_33 ( V_71 ) ;
if ( F_21 ( V_66 ) )
return F_22 ( V_66 ) ;
V_74 = F_34 ( V_71 , V_75 , V_16 ) ;
if ( V_74 != NULL ) {
F_39 ( & V_49 -> V_76 ) ;
if ( V_72 > 0 ) {
memcpy ( V_74 , V_49 -> V_30 , V_72 * V_75 ) ;
F_28 ( V_49 -> V_30 ) ;
}
V_49 -> V_30 = V_74 ;
V_49 -> V_63 = V_71 ;
if ( V_49 -> V_64 != NULL )
F_26 ( V_49 -> V_64 , V_72 ) ;
V_49 -> V_64 = V_66 ;
F_40 ( & V_49 -> V_76 ) ;
} else {
F_26 ( V_66 , V_71 ) ;
V_52 = - V_20 ;
}
}
return V_52 ;
}
static int F_41 ( const struct V_1 * V_2 , struct V_24 * V_49 ,
T_1 V_65 )
{
struct V_77 * V_78 = V_49 -> V_79 ;
struct V_27 * V_28 = F_14 ( V_49 ) ;
struct V_39 * V_80 ;
struct V_31 * V_32 ;
struct V_37 * V_38 ;
int V_35 ;
F_42 ( V_78 ) ;
V_80 = V_78 -> V_81 . V_82 . V_41 [ V_65 ] ;
F_15 ( V_80 != NULL ) ;
F_15 ( V_80 -> V_43 != NULL ) ;
if ( ! V_80 -> V_43 -> V_83 ) {
F_43 ( L_1 , F_44 ( & V_80 -> V_84 ) ) ;
return - V_85 ;
}
V_35 = F_38 ( V_2 , V_28 ) ;
if ( V_35 == 0 && V_28 -> V_47 & V_48 ) {
F_15 ( V_49 -> V_36 != NULL ) ;
V_38 = F_20 ( V_2 , V_49 -> V_36 , & V_42 ,
V_80 -> V_43 -> V_44 ) ;
if ( ! F_21 ( V_38 ) ) {
V_32 = F_23 ( V_38 ) ;
V_32 -> V_45 = V_65 ;
V_32 -> V_46 = V_28 ;
V_28 -> V_30 [ V_65 ] = V_32 ;
} else {
F_43 ( L_2 , V_35 ,
F_44 ( & V_80 -> V_84 ) ) ;
F_32 ( V_2 , V_49 , V_65 ) ;
V_35 = F_22 ( V_38 ) ;
}
}
F_45 ( V_78 ) ;
return V_35 ;
}
static int F_46 ( const struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_86 * V_87 )
{
struct V_77 * V_78 = V_25 -> V_79 ;
int V_88 ;
int V_35 ;
int V_89 ;
T_1 V_65 ;
F_42 ( V_78 ) ;
V_88 = V_87 -> V_90 ;
V_35 = F_47 ( V_25 -> V_79 , V_87 , & V_65 , & V_89 ) ;
if ( V_35 == 0 ) {
switch ( V_88 ) {
case V_91 :
case V_92 :
V_35 = F_41 ( V_2 , V_25 , V_65 ) ;
if ( V_35 != 0 )
F_48 ( V_25 -> V_79 , V_65 , NULL , 0 ) ;
break;
case V_93 :
F_32 ( V_2 , V_25 , V_65 ) ;
break;
}
}
F_45 ( V_78 ) ;
return V_35 ;
}
static struct V_24 * F_49 ( const struct V_1 * V_2 ,
struct V_94 * V_95 ,
struct V_86 * V_87 )
{
struct V_24 * V_25 ;
struct V_27 * V_28 ;
struct V_77 * V_78 ;
int V_35 ;
V_28 = F_35 ( sizeof( * V_28 ) , V_16 ) ;
if ( ! V_28 )
return F_7 ( - V_20 ) ;
F_50 ( & V_28 -> V_96 , V_95 ) ;
V_25 = F_51 ( V_28 ) ;
V_25 -> V_97 = & V_98 ;
V_28 -> V_96 . V_99 = & V_100 ;
F_52 ( & V_28 -> V_76 ) ;
F_53 ( & V_28 -> V_76 , & V_101 ) ;
V_78 = F_54 ( F_55 ( V_87 , 0 ) ) ;
F_15 ( V_78 != NULL ) ;
V_35 = F_56 ( V_78 , V_87 ) ;
if ( V_35 ) {
F_29 ( V_2 , V_25 ) ;
return F_7 ( V_35 ) ;
}
V_28 -> V_29 = & V_78 -> V_81 . V_82 ;
return V_25 ;
}
