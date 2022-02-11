static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 , V_8 ) ;
}
static void * F_4 ( const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
F_5 ( V_14 , V_15 , V_16 ) ;
if ( V_14 != NULL )
F_6 ( & V_14 -> V_17 . V_18 ) ;
else
V_14 = F_7 ( - V_19 ) ;
return V_14 ;
}
static void F_8 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_20 )
{
struct V_13 * V_14 = V_20 ;
F_9 ( F_10 ( & V_14 -> V_17 . V_18 ) ) ;
F_3 ( V_14 , V_15 ) ;
}
static void * F_11 ( const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_21 * V_14 ;
F_5 ( V_14 , V_22 , V_16 ) ;
if ( V_14 == NULL )
V_14 = F_7 ( - V_19 ) ;
return V_14 ;
}
static void F_12 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_20 )
{
struct V_21 * V_14 = V_20 ;
F_3 ( V_14 , V_22 ) ;
}
static struct V_23 * F_13 ( const struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_25 ;
struct V_26 * V_27 = F_14 ( V_24 ) ;
F_15 ( V_27 -> V_28 != NULL ) ;
if ( V_27 -> V_29 == NULL )
return NULL ;
F_16 (ld, i) {
struct V_30 * V_31 ;
V_31 = V_27 -> V_29 [ V_25 ] ;
if ( V_31 != NULL ) {
F_17 ( V_2 , F_18 ( V_31 ) ) ;
V_27 -> V_29 [ V_25 ] = NULL ;
}
}
return NULL ;
}
static int F_19 ( const struct V_1 * V_2 , struct V_23 * V_24 ,
const char * V_32 , struct V_23 * V_33 )
{
struct V_26 * V_27 = F_14 ( V_24 ) ;
int V_25 ;
int V_34 = 0 ;
F_15 ( V_24 -> V_35 != NULL ) ;
if ( V_27 -> V_29 == NULL )
return V_34 ;
F_16 (ld, i) {
struct V_30 * V_31 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_39 = V_27 -> V_28 -> V_40 [ V_25 ] ;
if ( V_39 == NULL )
continue;
V_37 = F_20 ( V_2 , V_24 -> V_35 , & V_41 ,
V_39 -> V_42 -> V_43 ) ;
if ( F_21 ( V_37 ) ) {
V_34 = F_22 ( V_37 ) ;
break;
}
V_31 = F_23 ( V_37 ) ;
V_31 -> V_44 = V_25 ;
V_31 -> V_45 = V_27 ;
V_27 -> V_29 [ V_25 ] = V_31 ;
}
if ( V_34 )
F_13 ( V_2 , V_24 ) ;
else
V_27 -> V_46 |= V_47 ;
return V_34 ;
}
static int F_24 ( const struct V_1 * V_2 , struct V_36 * V_48 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 ;
int V_51 ;
F_5 ( V_7 , V_8 , V_16 ) ;
if ( V_7 != NULL ) {
F_25 ( V_50 , & V_7 -> V_52 , V_48 , & V_53 ) ;
V_51 = 0 ;
} else
V_51 = - V_19 ;
return V_51 ;
}
static void F_26 ( struct V_54 * * V_55 , int V_56 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_56 ; ++ V_25 ) {
struct V_54 * V_57 ;
V_57 = V_55 [ V_25 ] ;
if ( V_57 != NULL ) {
F_15 ( V_57 -> V_58 . V_59 == 0 ) ;
if ( V_57 -> V_60 != NULL )
F_27 ( V_57 -> V_60 , & V_57 -> V_61 ) ;
F_28 ( V_57 ) ;
}
}
F_29 ( V_55 , V_56 * sizeof( V_55 [ 0 ] ) ) ;
}
static struct V_23 * F_30 ( const struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_26 * V_27 = F_14 ( V_24 ) ;
const int V_56 = V_27 -> V_62 ;
F_31 ( F_32 ( V_24 ) ) ;
if ( V_27 -> V_29 != NULL )
F_29 ( V_27 -> V_29 , V_56 * sizeof( V_27 -> V_29 [ 0 ] ) ) ;
if ( V_27 -> V_63 != NULL )
F_26 ( V_27 -> V_63 , V_56 ) ;
F_28 ( V_27 ) ;
return NULL ;
}
static void F_33 ( const struct V_1 * V_2 , struct V_23 * V_48 ,
T_1 V_64 )
{
struct V_26 * V_27 = F_14 ( V_48 ) ;
if ( V_27 -> V_29 [ V_64 ] != NULL ) {
F_17 ( V_2 , F_18 ( V_27 -> V_29 [ V_64 ] ) ) ;
V_27 -> V_29 [ V_64 ] = NULL ;
}
}
static struct V_54 * * F_34 ( int V_56 )
{
struct V_54 * * V_65 ;
int V_25 ;
int V_51 ;
F_35 ( V_65 , V_56 * sizeof( V_65 [ 0 ] ) ) ;
if ( V_65 == NULL )
return F_7 ( - V_19 ) ;
for ( V_51 = V_25 = 0 ; V_25 < V_56 && V_51 == 0 ; V_25 ++ ) {
struct V_54 * V_57 ;
F_36 ( V_57 ) ;
if ( V_57 != NULL ) {
V_65 [ V_25 ] = V_57 ;
F_37 ( & V_57 -> V_58 ) ;
V_57 -> V_60 = F_38 ( & V_57 -> V_61 ,
V_66 | V_67 ) ;
if ( ! F_21 ( V_57 -> V_60 ) )
V_57 -> V_60 -> V_68 . V_69 = 0x2 ;
else {
V_51 = F_22 ( V_57 -> V_60 ) ;
V_57 -> V_60 = NULL ;
}
} else
V_51 = - V_19 ;
}
if ( V_51 != 0 ) {
F_26 ( V_65 , V_56 ) ;
V_65 = F_7 ( V_51 ) ;
}
return V_65 ;
}
static int F_39 ( const struct V_1 * V_2 , struct V_26 * V_48 )
{
int V_51 ;
T_1 V_70 ;
T_1 V_71 ;
V_51 = 0 ;
V_70 = V_48 -> V_28 -> V_72 ;
V_71 = V_48 -> V_62 ;
if ( V_71 < V_70 ) {
struct V_30 * * V_73 ;
struct V_54 * * V_65 ;
const T_2 V_74 = sizeof( V_73 [ 0 ] ) ;
V_65 = F_34 ( V_70 ) ;
if ( F_21 ( V_65 ) )
return F_22 ( V_65 ) ;
F_35 ( V_73 , V_70 * V_74 ) ;
if ( V_73 != NULL ) {
F_40 ( & V_48 -> V_75 ) ;
if ( V_71 > 0 ) {
memcpy ( V_73 , V_48 -> V_29 , V_71 * V_74 ) ;
F_29 ( V_48 -> V_29 , V_71 * V_74 ) ;
}
V_48 -> V_29 = V_73 ;
V_48 -> V_62 = V_70 ;
if ( V_48 -> V_63 != NULL )
F_26 ( V_48 -> V_63 , V_71 ) ;
V_48 -> V_63 = V_65 ;
F_41 ( & V_48 -> V_75 ) ;
} else {
F_26 ( V_65 , V_70 ) ;
V_51 = - V_19 ;
}
}
return V_51 ;
}
static int F_42 ( const struct V_1 * V_2 , struct V_23 * V_48 ,
T_1 V_64 )
{
struct V_76 * V_77 = V_48 -> V_78 ;
struct V_26 * V_27 = F_14 ( V_48 ) ;
struct V_38 * V_79 ;
struct V_30 * V_31 ;
struct V_36 * V_37 ;
int V_34 ;
F_43 ( V_77 ) ;
V_79 = V_77 -> V_80 . V_81 . V_40 [ V_64 ] ;
F_15 ( V_79 != NULL ) ;
F_15 ( V_79 -> V_42 != NULL ) ;
if ( ! V_79 -> V_42 -> V_82 ) {
F_44 ( L_1 , F_45 ( & V_79 -> V_83 ) ) ;
return - V_84 ;
}
V_34 = F_39 ( V_2 , V_27 ) ;
if ( V_34 == 0 && V_27 -> V_46 & V_47 ) {
F_15 ( V_48 -> V_35 != NULL ) ;
V_37 = F_20 ( V_2 , V_48 -> V_35 , & V_41 ,
V_79 -> V_42 -> V_43 ) ;
if ( ! F_21 ( V_37 ) ) {
V_31 = F_23 ( V_37 ) ;
V_31 -> V_44 = V_64 ;
V_31 -> V_45 = V_27 ;
V_27 -> V_29 [ V_64 ] = V_31 ;
} else {
F_44 ( L_2 , V_34 ,
F_45 ( & V_79 -> V_83 ) ) ;
F_33 ( V_2 , V_48 , V_64 ) ;
V_34 = F_22 ( V_37 ) ;
}
}
F_46 ( V_77 ) ;
return V_34 ;
}
static int F_47 ( const struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_85 * V_86 )
{
struct V_76 * V_77 = V_24 -> V_78 ;
int V_87 ;
int V_34 ;
int V_88 ;
T_1 V_64 ;
F_43 ( V_77 ) ;
V_87 = V_86 -> V_89 ;
V_34 = F_48 ( V_24 -> V_78 , V_86 , & V_64 , & V_88 ) ;
if ( V_34 == 0 ) {
switch ( V_87 ) {
case V_90 :
case V_91 :
V_34 = F_42 ( V_2 , V_24 , V_64 ) ;
if ( V_34 != 0 )
F_49 ( V_24 -> V_78 , V_64 , NULL , 0 ) ;
break;
case V_92 :
F_33 ( V_2 , V_24 , V_64 ) ;
break;
}
}
F_46 ( V_77 ) ;
return V_34 ;
}
static struct V_23 * F_50 ( const struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_85 * V_86 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
struct V_76 * V_77 ;
int V_34 ;
F_36 ( V_27 ) ;
if ( V_27 == NULL )
return F_7 ( - V_19 ) ;
F_51 ( & V_27 -> V_95 , V_94 ) ;
V_24 = F_52 ( V_27 ) ;
V_24 -> V_96 = & V_97 ;
V_27 -> V_95 . V_98 = & V_99 ;
F_53 ( & V_27 -> V_75 ) ;
F_54 ( & V_27 -> V_75 , & V_100 ) ;
V_77 = F_55 ( F_56 ( V_86 , 0 ) ) ;
F_15 ( V_77 != NULL ) ;
V_34 = F_57 ( V_77 , V_86 ) ;
if ( V_34 ) {
F_30 ( V_2 , V_24 ) ;
return F_7 ( V_34 ) ;
}
V_27 -> V_28 = & V_77 -> V_80 . V_81 ;
return V_24 ;
}
