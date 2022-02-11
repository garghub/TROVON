static void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_8 ) ;
if ( ! V_6 )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
F_5 ( V_7 , V_6 ) ;
}
static void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_6 ;
V_6 = F_2 ( V_12 , V_8 ) ;
if ( ! V_6 )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_11 * V_6 = V_10 ;
F_5 ( V_12 , V_6 ) ;
}
static struct V_13 * F_8 ( const struct V_14 * V_15 ,
struct V_13 * V_16 )
{
int V_17 ;
struct V_18 * V_19 = F_9 ( V_16 ) ;
F_10 ( V_19 -> V_20 ) ;
if ( ! V_19 -> V_21 )
return NULL ;
F_11 (ld, i) {
struct V_22 * V_23 ;
V_23 = V_19 -> V_21 [ V_17 ] ;
if ( V_23 ) {
F_12 ( V_15 , F_13 ( V_23 ) ) ;
V_19 -> V_21 [ V_17 ] = NULL ;
}
}
return NULL ;
}
static int F_14 ( const struct V_14 * V_15 , struct V_13 * V_16 ,
const char * V_24 , struct V_13 * V_25 )
{
struct V_18 * V_19 = F_9 ( V_16 ) ;
int V_17 ;
int V_26 = 0 ;
F_10 ( V_16 -> V_27 ) ;
if ( ! V_19 -> V_21 )
return V_26 ;
F_11 (ld, i) {
struct V_22 * V_23 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
V_31 = V_19 -> V_20 -> V_32 [ V_17 ] ;
if ( ! V_31 )
continue;
V_29 = F_15 ( V_15 , V_16 -> V_27 , & V_33 ,
V_31 -> V_34 -> V_35 ) ;
if ( F_16 ( V_29 ) ) {
V_26 = F_17 ( V_29 ) ;
break;
}
V_23 = F_18 ( V_29 ) ;
V_23 -> V_36 = V_17 ;
V_23 -> V_37 = V_19 ;
V_19 -> V_21 [ V_17 ] = V_23 ;
}
if ( V_26 )
F_8 ( V_15 , V_16 ) ;
else
V_19 -> V_38 |= V_39 ;
return V_26 ;
}
static void F_19 ( struct V_40 * * V_41 , int V_42 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_42 ; ++ V_17 ) {
struct V_40 * V_43 ;
V_43 = V_41 [ V_17 ] ;
if ( V_43 ) {
F_10 ( V_43 -> V_44 . V_45 == 0 ) ;
if ( V_43 -> V_46 )
F_20 ( V_43 -> V_46 , & V_43 -> V_47 ) ;
F_21 ( V_43 ) ;
}
}
F_21 ( V_41 ) ;
}
static struct V_13 * F_22 ( const struct V_14 * V_15 ,
struct V_13 * V_16 )
{
struct V_18 * V_19 = F_9 ( V_16 ) ;
const int V_42 = V_19 -> V_48 ;
F_23 ( F_24 ( V_16 ) ) ;
F_21 ( V_19 -> V_21 ) ;
if ( V_19 -> V_49 )
F_19 ( V_19 -> V_49 , V_42 ) ;
F_21 ( V_19 ) ;
return NULL ;
}
static void F_25 ( const struct V_14 * V_15 , struct V_13 * V_50 ,
T_1 V_51 )
{
struct V_18 * V_19 = F_9 ( V_50 ) ;
if ( V_19 -> V_21 [ V_51 ] ) {
F_12 ( V_15 , F_13 ( V_19 -> V_21 [ V_51 ] ) ) ;
V_19 -> V_21 [ V_51 ] = NULL ;
}
}
static struct V_40 * * F_26 ( int V_42 )
{
struct V_40 * * V_52 ;
int V_17 ;
int V_53 ;
V_52 = F_27 ( V_42 , sizeof( V_52 [ 0 ] ) , V_8 ) ;
if ( ! V_52 )
return F_3 ( - V_9 ) ;
for ( V_53 = V_17 = 0 ; V_17 < V_42 && V_53 == 0 ; V_17 ++ ) {
struct V_40 * V_43 ;
V_43 = F_28 ( sizeof( * V_43 ) , V_8 ) ;
if ( V_43 ) {
V_52 [ V_17 ] = V_43 ;
F_29 ( & V_43 -> V_44 ) ;
V_43 -> V_46 = F_30 ( & V_43 -> V_47 ,
V_54 | V_55 ) ;
if ( ! F_16 ( V_43 -> V_46 ) ) {
V_43 -> V_46 -> V_56 . V_57 = 0x2 ;
} else {
V_53 = F_17 ( V_43 -> V_46 ) ;
V_43 -> V_46 = NULL ;
}
} else {
V_53 = - V_9 ;
}
}
if ( V_53 != 0 ) {
F_19 ( V_52 , V_42 ) ;
V_52 = F_3 ( V_53 ) ;
}
return V_52 ;
}
static int F_31 ( const struct V_14 * V_15 , struct V_18 * V_50 )
{
int V_53 ;
T_1 V_58 ;
T_1 V_59 ;
V_53 = 0 ;
V_58 = V_50 -> V_20 -> V_60 ;
V_59 = V_50 -> V_48 ;
if ( V_59 < V_58 ) {
struct V_22 * * V_61 ;
struct V_40 * * V_52 ;
const T_2 V_62 = sizeof( V_61 [ 0 ] ) ;
V_52 = F_26 ( V_58 ) ;
if ( F_16 ( V_52 ) )
return F_17 ( V_52 ) ;
V_61 = F_27 ( V_58 , V_62 , V_8 ) ;
if ( V_61 ) {
F_32 ( & V_50 -> V_63 ) ;
if ( V_59 > 0 ) {
memcpy ( V_61 , V_50 -> V_21 , V_59 * V_62 ) ;
F_21 ( V_50 -> V_21 ) ;
}
V_50 -> V_21 = V_61 ;
V_50 -> V_48 = V_58 ;
if ( V_50 -> V_49 )
F_19 ( V_50 -> V_49 , V_59 ) ;
V_50 -> V_49 = V_52 ;
F_33 ( & V_50 -> V_63 ) ;
} else {
F_19 ( V_52 , V_58 ) ;
V_53 = - V_9 ;
}
}
return V_53 ;
}
static int F_34 ( const struct V_14 * V_15 , struct V_13 * V_50 ,
T_1 V_51 )
{
struct V_64 * V_65 = V_50 -> V_66 ;
struct V_18 * V_19 = F_9 ( V_50 ) ;
struct V_30 * V_67 ;
struct V_22 * V_23 ;
struct V_28 * V_29 ;
int V_26 ;
F_35 ( V_65 ) ;
V_67 = V_65 -> V_68 . V_69 . V_32 [ V_51 ] ;
if ( ! V_67 -> V_34 -> V_70 ) {
F_36 ( L_1 , F_37 ( & V_67 -> V_71 ) ) ;
return - V_72 ;
}
V_26 = F_31 ( V_15 , V_19 ) ;
if ( V_26 == 0 && V_19 -> V_38 & V_39 ) {
F_10 ( V_50 -> V_27 ) ;
V_29 = F_15 ( V_15 , V_50 -> V_27 , & V_33 ,
V_67 -> V_34 -> V_35 ) ;
if ( ! F_16 ( V_29 ) ) {
V_23 = F_18 ( V_29 ) ;
V_23 -> V_36 = V_51 ;
V_23 -> V_37 = V_19 ;
V_19 -> V_21 [ V_51 ] = V_23 ;
} else {
F_36 ( L_2 , V_26 ,
F_37 ( & V_67 -> V_71 ) ) ;
F_25 ( V_15 , V_50 , V_51 ) ;
V_26 = F_17 ( V_29 ) ;
}
}
F_38 ( V_65 ) ;
return V_26 ;
}
static int F_39 ( const struct V_14 * V_15 ,
struct V_13 * V_16 , struct V_73 * V_74 )
{
struct V_64 * V_65 = V_16 -> V_66 ;
int V_75 ;
int V_26 ;
int V_76 ;
T_1 V_51 ;
F_35 ( V_65 ) ;
V_75 = V_74 -> V_77 ;
V_26 = F_40 ( V_16 -> V_66 , V_74 , & V_51 , & V_76 ) ;
if ( V_26 == 0 ) {
switch ( V_75 ) {
case V_78 :
case V_79 :
V_26 = F_34 ( V_15 , V_16 , V_51 ) ;
if ( V_26 != 0 )
F_41 ( V_16 -> V_66 , V_51 , NULL , 0 ) ;
break;
case V_80 :
F_25 ( V_15 , V_16 , V_51 ) ;
break;
}
}
F_38 ( V_65 ) ;
return V_26 ;
}
static struct V_13 * F_42 ( const struct V_14 * V_15 ,
struct V_81 * V_82 ,
struct V_73 * V_74 )
{
struct V_13 * V_16 ;
struct V_18 * V_19 ;
struct V_64 * V_65 ;
int V_26 ;
V_19 = F_28 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_3 ( - V_9 ) ;
F_43 ( & V_19 -> V_83 , V_82 ) ;
V_16 = F_44 ( V_19 ) ;
V_16 -> V_84 = & V_85 ;
F_45 ( & V_19 -> V_63 ) ;
F_46 ( & V_19 -> V_63 , & V_86 ) ;
V_65 = F_47 ( F_48 ( V_74 , 0 ) ) ;
F_10 ( V_65 ) ;
V_26 = F_49 ( V_65 , V_74 ) ;
if ( V_26 ) {
F_22 ( V_15 , V_16 ) ;
return F_3 ( V_26 ) ;
}
V_19 -> V_20 = & V_65 -> V_68 . V_69 ;
return V_16 ;
}
