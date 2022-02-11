static const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_11 * V_12 ;
unsigned int V_3 ;
V_12 = F_5 ( V_6 , V_8 , 0 ) ;
* V_12 = V_13 ;
for ( V_3 = 1 ; V_3 < V_6 -> V_14 . V_15 ; V_3 ++ ) {
V_12 = F_5 ( V_6 , V_8 , V_3 ) ;
* V_12 = V_13 ;
V_12 -> V_2 = V_10 -> V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_17 * V_2 )
{
if ( F_7 ( V_2 -> V_18 ) ) {
struct V_9 * V_10 = F_4 ( V_6 ) ;
if ( V_2 -> V_19 )
return - V_20 ;
V_2 -> V_2 = V_10 -> V_16 ;
} else {
if ( V_2 -> V_19 >= F_2 ( V_4 ) )
return - V_20 ;
V_2 -> V_2 = V_4 [ V_2 -> V_19 ] . V_2 ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_21 * V_22 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
if ( V_22 -> V_19 )
return - V_20 ;
if ( F_9 ( V_22 -> V_18 ) ) {
const struct V_1 * V_23 =
F_1 ( V_22 -> V_2 ) ;
if ( ! V_23 )
return - V_20 ;
} else if ( V_22 -> V_2 != V_10 -> V_16 ) {
return - V_20 ;
}
V_22 -> V_24 = V_25 ;
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = V_29 ;
V_22 -> V_30 = V_31 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
V_33 -> V_34 = V_33 -> V_35 == V_36 ?
* F_5 ( V_6 , V_8 , 0 ) :
V_10 -> V_37 ;
if ( F_7 ( V_33 -> V_18 ) )
V_33 -> V_34 . V_2 = V_10 -> V_16 ;
return 0 ;
}
static void F_11 ( struct V_11 * V_33 )
{
const struct V_1 * V_23 ;
V_23 = F_1 ( V_33 -> V_2 ) ;
if ( ! V_23 )
V_33 -> V_2 = V_13 . V_2 ;
V_33 -> V_38 = F_12 ( T_1 , V_33 -> V_38 , V_25 ,
V_27 ) & ~ 1 ;
V_33 -> V_39 = F_12 ( T_1 , V_33 -> V_39 , V_29 ,
V_31 ) & ~ 1 ;
if ( V_33 -> V_40 == V_41 )
V_33 -> V_40 = V_13 . V_40 ;
F_13 ( V_33 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_11 * V_37 ;
if ( V_33 -> V_35 == V_42 ) {
if ( V_10 -> V_43 )
return - V_44 ;
V_37 = & V_10 -> V_37 ;
} else {
V_37 = F_5 ( V_6 , V_8 , 0 ) ;
}
if ( F_7 ( V_33 -> V_18 ) ) {
V_33 -> V_34 = * V_37 ;
V_33 -> V_34 . V_2 = V_10 -> V_16 ;
} else {
F_11 ( & V_33 -> V_34 ) ;
F_15 ( V_10 -> V_45 , L_1
L_2
L_3 , V_10 -> V_6 . V_46 ,
V_37 -> V_38 , V_37 -> V_39 , V_37 -> V_2 ,
V_37 -> V_47 , V_37 -> V_48 ,
V_37 -> V_49 , V_37 -> V_50 ,
V_33 -> V_34 . V_38 , V_33 -> V_34 . V_39 , V_33 -> V_34 . V_2 ,
V_33 -> V_34 . V_47 , V_33 -> V_34 . V_48 ,
V_33 -> V_34 . V_49 , V_33 -> V_34 . V_50 ) ;
* V_37 = V_33 -> V_34 ;
}
return 0 ;
}
static void F_16 ( struct V_9 * V_10 ,
unsigned int V_51 ,
unsigned int V_52 ,
unsigned int V_53 [ 3 ] )
{
unsigned int V_3 , V_19 ;
V_19 = F_17 ( V_51 , V_52 , V_10 -> V_37 . V_38 , 3 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_10 -> V_43 [ V_19 + V_3 ] = V_53 [ V_3 ] ;
}
static int F_18 ( struct V_5 * V_6 , int V_54 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
int V_55 ;
if ( V_54 ) {
const struct V_56 * V_23 ;
unsigned int V_57 ;
if ( V_10 -> V_43 )
return 0 ;
V_23 = F_19 ( V_10 -> V_16 ) ;
V_57 = V_10 -> V_37 . V_38 * V_10 -> V_37 . V_39 *
V_23 -> V_58 ;
V_23 = F_19 ( V_10 -> V_37 . V_2 ) ;
V_10 -> V_59 = V_23 -> V_58 ;
V_10 -> V_60 =
F_1 ( V_10 -> V_37 . V_2 ) ;
V_10 -> V_43 = F_20 ( V_57 ) ;
if ( ! V_10 -> V_43 )
return - V_61 ;
V_55 = F_21 ( & V_10 -> V_6 . V_14 , 1 ) ;
if ( V_55 ) {
F_22 ( V_10 -> V_43 ) ;
V_10 -> V_43 = NULL ;
return V_55 ;
}
} else {
if ( ! V_10 -> V_43 )
return 0 ;
V_55 = F_21 ( & V_10 -> V_6 . V_14 , 0 ) ;
if ( V_55 )
return V_55 ;
F_22 ( V_10 -> V_43 ) ;
V_10 -> V_43 = NULL ;
}
return 0 ;
}
static unsigned int F_23 ( const T_2 * V_62 ,
const unsigned int V_63 )
{
unsigned int V_3 ;
unsigned int V_64 = 0 ;
for ( V_3 = 0 ; V_3 < V_63 ; V_3 ++ )
V_64 = V_64 + ( V_62 [ V_3 ] << ( 8 * V_3 ) ) ;
return V_64 ;
}
static void F_24 ( struct V_9 * V_10 ,
const T_2 * V_65 ,
const unsigned int V_51 ,
const unsigned int V_52 ,
unsigned int V_53 [ 3 ] )
{
unsigned int V_3 , V_66 , V_67 , V_68 ;
unsigned int V_69 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_53 [ V_3 ] = 0 ;
V_66 = V_70 / 2 ;
F_15 ( V_10 -> V_45 ,
L_4 ,
V_10 -> V_6 . V_46 , V_51 , V_52 , V_10 -> V_37 . V_39 , V_66 ) ;
for ( V_67 = V_66 > V_51 ? 0 : V_51 - V_66 ;
V_67 < V_51 + V_66 + 1 && V_67 < V_10 -> V_37 . V_39 ;
V_67 ++ ) {
for ( V_68 = V_66 > V_52 ? 0 : V_52 - V_66 ;
V_68 < V_52 + V_66 + 1 && V_68 < V_10 -> V_37 . V_38 ;
V_68 ++ ) {
enum V_71 V_72 ;
unsigned int V_19 ;
V_72 = V_10 -> V_60 -> V_73 [ V_67 % 2 ] [ V_68 % 2 ] ;
V_19 = F_17 ( V_67 , V_68 ,
V_10 -> V_37 . V_38 ,
V_10 -> V_59 ) ;
F_15 ( V_10 -> V_45 ,
L_5 ,
V_10 -> V_6 . V_46 , V_19 , V_67 , V_68 , V_72 ) ;
V_53 [ V_72 ] = V_53 [ V_72 ] +
F_23 ( & V_65 [ V_19 ] , V_10 -> V_59 ) ;
V_69 [ V_72 ] ++ ;
F_15 ( V_10 -> V_45 , L_6 ,
V_10 -> V_6 . V_46 , V_53 [ V_72 ] , V_69 [ V_72 ] ) ;
}
}
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
F_15 ( V_10 -> V_45 ,
L_7 ,
V_10 -> V_6 . V_46 , V_51 , V_52 , V_3 , V_53 [ V_3 ] , V_69 [ V_3 ] ) ;
if ( V_69 [ V_3 ] )
V_53 [ V_3 ] = V_53 [ V_3 ] / V_69 [ V_3 ] ;
F_15 ( V_10 -> V_45 ,
L_8 ,
V_10 -> V_6 . V_46 , V_51 , V_52 , V_3 , V_53 [ V_3 ] ) ;
}
}
static void F_25 ( struct V_74 * V_75 ,
struct V_76 * V_77 ,
const void * V_78 )
{
struct V_9 * V_10 = F_26 ( V_75 , struct V_9 ,
V_75 ) ;
unsigned int V_53 [ 3 ] ;
unsigned int V_3 , V_79 ;
if ( ! V_10 -> V_43 )
return;
for ( V_3 = 0 ; V_3 < V_10 -> V_37 . V_39 ; V_3 ++ )
for ( V_79 = 0 ; V_79 < V_10 -> V_37 . V_38 ; V_79 ++ ) {
F_24 ( V_10 , V_78 , V_3 , V_79 , V_53 ) ;
V_10 -> V_80 ( V_10 , V_3 , V_79 , V_53 ) ;
}
for ( V_3 = 1 ; V_3 < V_10 -> V_6 . V_14 . V_15 ; V_3 ++ ) {
struct V_76 * V_18 = & V_10 -> V_6 . V_14 . V_81 [ V_3 ] ;
F_27 ( V_18 , V_10 -> V_43 ) ;
}
}
static void F_28 ( struct V_82 * V_83 , struct V_82 * V_84 ,
void * V_85 )
{
struct V_74 * V_75 = F_29 ( V_83 ) ;
struct V_9 * V_10 = F_26 ( V_75 , struct V_9 ,
V_75 ) ;
F_30 ( V_75 , & V_10 -> V_6 ) ;
F_31 ( V_10 ) ;
}
static int F_32 ( struct V_82 * V_83 , struct V_82 * V_84 ,
void * V_85 )
{
struct V_86 * V_87 = V_85 ;
struct V_88 * V_89 = V_83 -> V_90 ;
struct V_9 * V_10 ;
int V_55 ;
V_10 = F_33 ( sizeof( * V_10 ) , V_91 ) ;
if ( ! V_10 )
return - V_61 ;
V_55 = F_34 (&vdeb->ved, &vdeb->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 2 ,
(const unsigned long[2]) {MEDIA_PAD_FL_SINK,
MEDIA_PAD_FL_SOURCE},
&vimc_deb_ops) ;
if ( V_55 ) {
F_31 ( V_10 ) ;
return V_55 ;
}
V_10 -> V_75 . V_92 = F_25 ;
F_35 ( V_83 , & V_10 -> V_75 ) ;
V_10 -> V_45 = V_83 ;
V_10 -> V_37 = V_13 ;
V_10 -> V_16 = V_93 ;
V_10 -> V_80 = F_16 ;
return 0 ;
}
static int F_36 ( struct V_94 * V_95 )
{
return F_37 ( & V_95 -> V_45 , & V_96 ) ;
}
static int F_38 ( struct V_94 * V_95 )
{
F_39 ( & V_95 -> V_45 , & V_96 ) ;
return 0 ;
}
