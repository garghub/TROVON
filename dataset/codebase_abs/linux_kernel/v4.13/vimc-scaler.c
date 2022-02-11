static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
V_6 = F_2 ( V_2 , V_4 , 0 ) ;
* V_6 = V_8 ;
for ( V_7 = 1 ; V_7 < V_2 -> V_9 . V_10 ; V_7 ++ ) {
V_6 = F_2 ( V_2 , V_4 , V_7 ) ;
* V_6 = V_8 ;
V_6 -> V_11 = V_6 -> V_11 * V_12 ;
V_6 -> V_13 = V_6 -> V_13 * V_12 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_14 * V_15 )
{
const struct V_16 * V_17 = F_4 ( V_15 -> V_18 ) ;
if ( ! V_17 || V_17 -> V_19 )
return - V_20 ;
V_15 -> V_15 = V_17 -> V_15 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_21 * V_22 )
{
const struct V_16 * V_17 ;
if ( V_22 -> V_18 )
return - V_20 ;
V_17 = F_6 ( V_22 -> V_15 ) ;
if ( ! V_17 || V_17 -> V_19 )
return - V_20 ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = V_26 ;
if ( F_7 ( V_22 -> V_27 ) ) {
V_22 -> V_28 = V_29 ;
V_22 -> V_30 = V_31 ;
} else {
V_22 -> V_28 = V_29 * V_32 ;
V_22 -> V_30 = V_31 * V_32 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_9 ( V_2 ) ;
V_34 -> V_34 = ( V_34 -> V_37 == V_38 ) ?
* F_2 ( V_2 , V_4 , 0 ) :
V_36 -> V_39 ;
if ( F_10 ( V_34 -> V_27 ) ) {
V_34 -> V_34 . V_11 = V_36 -> V_39 . V_11 * V_12 ;
V_34 -> V_34 . V_13 = V_36 -> V_39 . V_13 * V_12 ;
}
return 0 ;
}
static void F_11 ( struct V_5 * V_40 )
{
const struct V_16 * V_17 ;
V_17 = F_6 ( V_40 -> V_15 ) ;
if ( ! V_17 || V_17 -> V_19 )
V_40 -> V_15 = V_8 . V_15 ;
V_40 -> V_11 = F_12 ( V_41 , V_40 -> V_11 , V_24 ,
V_29 ) & ~ 1 ;
V_40 -> V_13 = F_12 ( V_41 , V_40 -> V_13 , V_26 ,
V_31 ) & ~ 1 ;
if ( V_40 -> V_42 == V_43 )
V_40 -> V_42 = V_8 . V_42 ;
F_13 ( V_40 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_40 )
{
struct V_35 * V_36 = F_9 ( V_2 ) ;
struct V_5 * V_39 ;
if ( V_40 -> V_37 == V_44 ) {
if ( V_36 -> V_45 )
return - V_46 ;
V_39 = & V_36 -> V_39 ;
} else {
V_39 = F_2 ( V_2 , V_4 , 0 ) ;
}
if ( F_10 ( V_40 -> V_27 ) ) {
V_40 -> V_34 = * V_39 ;
V_40 -> V_34 . V_11 = V_39 -> V_11 * V_12 ;
V_40 -> V_34 . V_13 = V_39 -> V_13 * V_12 ;
} else {
F_11 ( & V_40 -> V_34 ) ;
F_15 ( V_36 -> V_47 , L_1
L_2
L_3 , V_36 -> V_2 . V_48 ,
V_39 -> V_11 , V_39 -> V_13 , V_39 -> V_15 ,
V_39 -> V_49 , V_39 -> V_50 ,
V_39 -> V_51 , V_39 -> V_52 ,
V_40 -> V_34 . V_11 , V_40 -> V_34 . V_13 , V_40 -> V_34 . V_15 ,
V_40 -> V_34 . V_49 , V_40 -> V_34 . V_50 ,
V_40 -> V_34 . V_51 , V_40 -> V_34 . V_52 ) ;
* V_39 = V_40 -> V_34 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_53 )
{
struct V_35 * V_36 = F_9 ( V_2 ) ;
int V_54 ;
if ( V_53 ) {
const struct V_16 * V_17 ;
unsigned int V_55 ;
if ( V_36 -> V_45 )
return 0 ;
V_17 = F_6 ( V_36 -> V_39 . V_15 ) ;
V_36 -> V_56 = V_17 -> V_56 ;
V_36 -> V_57 = V_36 -> V_39 . V_11 *
V_12 * V_36 -> V_56 ;
V_55 = V_36 -> V_57 * V_36 -> V_39 . V_13 *
V_12 ;
V_36 -> V_45 = F_17 ( V_55 ) ;
if ( ! V_36 -> V_45 )
return - V_58 ;
V_54 = F_18 ( & V_36 -> V_2 . V_9 , 1 ) ;
if ( V_54 ) {
F_19 ( V_36 -> V_45 ) ;
V_36 -> V_45 = NULL ;
return V_54 ;
}
} else {
if ( ! V_36 -> V_45 )
return 0 ;
V_54 = F_18 ( & V_36 -> V_2 . V_9 , 0 ) ;
if ( V_54 )
return V_54 ;
F_19 ( V_36 -> V_45 ) ;
V_36 -> V_45 = NULL ;
}
return 0 ;
}
static void F_20 ( T_1 * const V_59 ,
const T_1 * const V_60 ,
const unsigned int V_56 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ )
V_59 [ V_7 ] = V_60 [ V_7 ] ;
}
static void F_21 ( const struct V_35 * const V_36 ,
const unsigned int V_61 , const unsigned int V_62 ,
const T_1 * const V_63 )
{
unsigned int V_7 , V_64 , V_18 ;
const T_1 * V_60 ;
V_18 = F_22 ( V_61 , V_62 ,
V_36 -> V_39 . V_11 ,
V_36 -> V_56 ) ;
V_60 = & V_63 [ V_18 ] ;
F_15 ( V_36 -> V_47 ,
L_4 ,
V_36 -> V_2 . V_48 , V_61 , V_62 , V_18 ) ;
V_18 = F_22 ( V_61 * V_12 , V_62 * V_12 ,
V_36 -> V_39 . V_11 * V_12 , V_36 -> V_56 ) ;
F_15 ( V_36 -> V_47 , L_5 ,
V_36 -> V_2 . V_48 , V_61 * V_12 , V_62 * V_12 , V_18 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
for ( V_64 = 0 ; V_64 < V_12 * V_36 -> V_56 ; V_64 += V_36 -> V_56 ) {
F_15 ( V_36 -> V_47 ,
L_6 ,
V_36 -> V_2 . V_48 , V_18 + V_64 ) ;
F_20 ( & V_36 -> V_45 [ V_18 + V_64 ] ,
V_60 , V_36 -> V_56 ) ;
}
V_18 += V_36 -> V_57 ;
}
}
static void F_23 ( const struct V_35 * const V_36 ,
const T_1 * const V_63 )
{
unsigned int V_7 , V_64 ;
for ( V_7 = 0 ; V_7 < V_36 -> V_39 . V_13 ; V_7 ++ )
for ( V_64 = 0 ; V_64 < V_36 -> V_39 . V_11 ; V_64 ++ )
F_21 ( V_36 , V_7 , V_64 , V_63 ) ;
}
static void F_24 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const void * V_63 )
{
struct V_35 * V_36 = F_25 ( V_66 , struct V_35 ,
V_66 ) ;
unsigned int V_7 ;
if ( ! V_36 -> V_45 )
return;
F_23 ( V_36 , V_63 ) ;
for ( V_7 = 1 ; V_7 < V_36 -> V_2 . V_9 . V_10 ; V_7 ++ ) {
struct V_67 * V_27 = & V_36 -> V_2 . V_9 . V_69 [ V_7 ] ;
F_26 ( V_27 , V_36 -> V_45 ) ;
}
}
static void F_27 ( struct V_70 * V_71 , struct V_70 * V_72 ,
void * V_73 )
{
struct V_65 * V_66 = F_28 ( V_71 ) ;
struct V_35 * V_36 = F_25 ( V_66 , struct V_35 ,
V_66 ) ;
F_29 ( V_66 , & V_36 -> V_2 ) ;
F_30 ( V_36 ) ;
}
static int F_31 ( struct V_70 * V_71 , struct V_70 * V_72 ,
void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_76 * V_77 = V_71 -> V_78 ;
struct V_35 * V_36 ;
int V_54 ;
V_36 = F_32 ( sizeof( * V_36 ) , V_79 ) ;
if ( ! V_36 )
return - V_58 ;
V_54 = F_33 (&vsca->ved, &vsca->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 2 ,
(const unsigned long[2]) {MEDIA_PAD_FL_SINK,
MEDIA_PAD_FL_SOURCE},
&vimc_sca_ops) ;
if ( V_54 ) {
F_30 ( V_36 ) ;
return V_54 ;
}
V_36 -> V_66 . V_80 = F_24 ;
F_34 ( V_71 , & V_36 -> V_66 ) ;
V_36 -> V_47 = V_71 ;
V_36 -> V_39 = V_8 ;
return 0 ;
}
static int F_35 ( struct V_81 * V_82 )
{
return F_36 ( & V_82 -> V_47 , & V_83 ) ;
}
static int F_37 ( struct V_81 * V_82 )
{
F_38 ( & V_82 -> V_47 , & V_83 ) ;
return 0 ;
}
