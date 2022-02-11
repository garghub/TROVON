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
V_14 = F_5 ( V_15 , V_16 ) ;
if ( ! V_14 )
V_14 = F_6 ( - V_17 ) ;
return V_14 ;
}
static void F_7 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_18 )
{
struct V_13 * V_14 = V_18 ;
F_3 ( V_15 , V_14 ) ;
}
static void * F_8 ( const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_19 * V_14 ;
V_14 = F_5 ( V_20 , V_16 ) ;
if ( ! V_14 )
V_14 = F_6 ( - V_17 ) ;
return V_14 ;
}
static void F_9 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , void * V_18 )
{
struct V_19 * V_14 = V_18 ;
F_3 ( V_20 , V_14 ) ;
}
static struct V_21 * F_10 ( const struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_23 ;
struct V_24 * V_25 = F_11 ( V_22 ) ;
F_12 ( V_25 -> V_26 ) ;
if ( ! V_25 -> V_27 )
return NULL ;
F_13 (ld, i) {
struct V_28 * V_29 ;
V_29 = V_25 -> V_27 [ V_23 ] ;
if ( V_29 ) {
F_14 ( V_2 , F_15 ( V_29 ) ) ;
V_25 -> V_27 [ V_23 ] = NULL ;
}
}
return NULL ;
}
static int F_16 ( const struct V_1 * V_2 , struct V_21 * V_22 ,
const char * V_30 , struct V_21 * V_31 )
{
struct V_24 * V_25 = F_11 ( V_22 ) ;
int V_23 ;
int V_32 = 0 ;
F_12 ( V_22 -> V_33 ) ;
if ( ! V_25 -> V_27 )
return V_32 ;
F_13 (ld, i) {
struct V_28 * V_29 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
V_37 = V_25 -> V_26 -> V_38 [ V_23 ] ;
if ( ! V_37 )
continue;
V_35 = F_17 ( V_2 , V_22 -> V_33 , & V_39 ,
V_37 -> V_40 -> V_41 ) ;
if ( F_18 ( V_35 ) ) {
V_32 = F_19 ( V_35 ) ;
break;
}
V_29 = F_20 ( V_35 ) ;
V_29 -> V_42 = V_23 ;
V_29 -> V_43 = V_25 ;
V_25 -> V_27 [ V_23 ] = V_29 ;
}
if ( V_32 )
F_10 ( V_2 , V_22 ) ;
else
V_25 -> V_44 |= V_45 ;
return V_32 ;
}
static int F_21 ( const struct V_1 * V_2 , struct V_34 * V_46 ,
struct V_47 * V_48 )
{
struct V_6 * V_7 ;
int V_49 ;
V_7 = F_5 ( V_8 , V_16 ) ;
if ( V_7 ) {
F_22 ( V_48 , & V_7 -> V_50 , V_46 , & V_51 ) ;
V_49 = 0 ;
} else {
V_49 = - V_17 ;
}
return V_49 ;
}
static void F_23 ( struct V_52 * * V_53 , int V_54 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_54 ; ++ V_23 ) {
struct V_52 * V_55 ;
V_55 = V_53 [ V_23 ] ;
if ( V_55 ) {
F_12 ( V_55 -> V_56 . V_57 == 0 ) ;
if ( V_55 -> V_58 )
F_24 ( V_55 -> V_58 , & V_55 -> V_59 ) ;
F_25 ( V_55 ) ;
}
}
F_25 ( V_53 ) ;
}
static struct V_21 * F_26 ( const struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_24 * V_25 = F_11 ( V_22 ) ;
const int V_54 = V_25 -> V_60 ;
F_27 ( F_28 ( V_22 ) ) ;
F_25 ( V_25 -> V_27 ) ;
if ( V_25 -> V_61 )
F_23 ( V_25 -> V_61 , V_54 ) ;
F_25 ( V_25 ) ;
return NULL ;
}
static void F_29 ( const struct V_1 * V_2 , struct V_21 * V_46 ,
T_1 V_62 )
{
struct V_24 * V_25 = F_11 ( V_46 ) ;
if ( V_25 -> V_27 [ V_62 ] ) {
F_14 ( V_2 , F_15 ( V_25 -> V_27 [ V_62 ] ) ) ;
V_25 -> V_27 [ V_62 ] = NULL ;
}
}
static struct V_52 * * F_30 ( int V_54 )
{
struct V_52 * * V_63 ;
int V_23 ;
int V_49 ;
V_63 = F_31 ( V_54 , sizeof( V_63 [ 0 ] ) , V_16 ) ;
if ( ! V_63 )
return F_6 ( - V_17 ) ;
for ( V_49 = V_23 = 0 ; V_23 < V_54 && V_49 == 0 ; V_23 ++ ) {
struct V_52 * V_55 ;
V_55 = F_32 ( sizeof( * V_55 ) , V_16 ) ;
if ( V_55 ) {
V_63 [ V_23 ] = V_55 ;
F_33 ( & V_55 -> V_56 ) ;
V_55 -> V_58 = F_34 ( & V_55 -> V_59 ,
V_64 | V_65 ) ;
if ( ! F_18 ( V_55 -> V_58 ) ) {
V_55 -> V_58 -> V_66 . V_67 = 0x2 ;
} else {
V_49 = F_19 ( V_55 -> V_58 ) ;
V_55 -> V_58 = NULL ;
}
} else {
V_49 = - V_17 ;
}
}
if ( V_49 != 0 ) {
F_23 ( V_63 , V_54 ) ;
V_63 = F_6 ( V_49 ) ;
}
return V_63 ;
}
static int F_35 ( const struct V_1 * V_2 , struct V_24 * V_46 )
{
int V_49 ;
T_1 V_68 ;
T_1 V_69 ;
V_49 = 0 ;
V_68 = V_46 -> V_26 -> V_70 ;
V_69 = V_46 -> V_60 ;
if ( V_69 < V_68 ) {
struct V_28 * * V_71 ;
struct V_52 * * V_63 ;
const T_2 V_72 = sizeof( V_71 [ 0 ] ) ;
V_63 = F_30 ( V_68 ) ;
if ( F_18 ( V_63 ) )
return F_19 ( V_63 ) ;
V_71 = F_31 ( V_68 , V_72 , V_16 ) ;
if ( V_71 ) {
F_36 ( & V_46 -> V_73 ) ;
if ( V_69 > 0 ) {
memcpy ( V_71 , V_46 -> V_27 , V_69 * V_72 ) ;
F_25 ( V_46 -> V_27 ) ;
}
V_46 -> V_27 = V_71 ;
V_46 -> V_60 = V_68 ;
if ( V_46 -> V_61 )
F_23 ( V_46 -> V_61 , V_69 ) ;
V_46 -> V_61 = V_63 ;
F_37 ( & V_46 -> V_73 ) ;
} else {
F_23 ( V_63 , V_68 ) ;
V_49 = - V_17 ;
}
}
return V_49 ;
}
static int F_38 ( const struct V_1 * V_2 , struct V_21 * V_46 ,
T_1 V_62 )
{
struct V_74 * V_75 = V_46 -> V_76 ;
struct V_24 * V_25 = F_11 ( V_46 ) ;
struct V_36 * V_77 ;
struct V_28 * V_29 ;
struct V_34 * V_35 ;
int V_32 ;
F_39 ( V_75 ) ;
V_77 = V_75 -> V_78 . V_79 . V_38 [ V_62 ] ;
if ( ! V_77 -> V_40 -> V_80 ) {
F_40 ( L_1 , F_41 ( & V_77 -> V_81 ) ) ;
return - V_82 ;
}
V_32 = F_35 ( V_2 , V_25 ) ;
if ( V_32 == 0 && V_25 -> V_44 & V_45 ) {
F_12 ( V_46 -> V_33 ) ;
V_35 = F_17 ( V_2 , V_46 -> V_33 , & V_39 ,
V_77 -> V_40 -> V_41 ) ;
if ( ! F_18 ( V_35 ) ) {
V_29 = F_20 ( V_35 ) ;
V_29 -> V_42 = V_62 ;
V_29 -> V_43 = V_25 ;
V_25 -> V_27 [ V_62 ] = V_29 ;
} else {
F_40 ( L_2 , V_32 ,
F_41 ( & V_77 -> V_81 ) ) ;
F_29 ( V_2 , V_46 , V_62 ) ;
V_32 = F_19 ( V_35 ) ;
}
}
F_42 ( V_75 ) ;
return V_32 ;
}
static int F_43 ( const struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_83 * V_84 )
{
struct V_74 * V_75 = V_22 -> V_76 ;
int V_85 ;
int V_32 ;
int V_86 ;
T_1 V_62 ;
F_39 ( V_75 ) ;
V_85 = V_84 -> V_87 ;
V_32 = F_44 ( V_22 -> V_76 , V_84 , & V_62 , & V_86 ) ;
if ( V_32 == 0 ) {
switch ( V_85 ) {
case V_88 :
case V_89 :
V_32 = F_38 ( V_2 , V_22 , V_62 ) ;
if ( V_32 != 0 )
F_45 ( V_22 -> V_76 , V_62 , NULL , 0 ) ;
break;
case V_90 :
F_29 ( V_2 , V_22 , V_62 ) ;
break;
}
}
F_42 ( V_75 ) ;
return V_32 ;
}
static struct V_21 * F_46 ( const struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_83 * V_84 )
{
struct V_21 * V_22 ;
struct V_24 * V_25 ;
struct V_74 * V_75 ;
int V_32 ;
V_25 = F_32 ( sizeof( * V_25 ) , V_16 ) ;
if ( ! V_25 )
return F_6 ( - V_17 ) ;
F_47 ( & V_25 -> V_93 , V_92 ) ;
V_22 = F_48 ( V_25 ) ;
V_22 -> V_94 = & V_95 ;
V_25 -> V_93 . V_96 = & V_97 ;
F_49 ( & V_25 -> V_73 ) ;
F_50 ( & V_25 -> V_73 , & V_98 ) ;
V_75 = F_51 ( F_52 ( V_84 , 0 ) ) ;
F_12 ( V_75 ) ;
V_32 = F_53 ( V_75 , V_84 ) ;
if ( V_32 ) {
F_26 ( V_2 , V_22 ) ;
return F_6 ( V_32 ) ;
}
V_25 -> V_26 = & V_75 -> V_78 . V_79 ;
return V_22 ;
}
