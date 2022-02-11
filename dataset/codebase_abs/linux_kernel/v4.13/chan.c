static int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , F_3 ( * V_5 ) , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_6 . V_5 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_8 -> V_13 . V_14 ] ;
const char * V_15 = V_16 [ V_8 -> V_13 . V_14 ] ;
int V_17 = 0 ;
if ( -- V_12 -> V_18 )
return 0 ;
if ( V_10 -> V_19 -> V_20 ) {
V_17 = V_10 -> V_19 -> V_20 ( V_10 , V_8 , V_3 ) ;
if ( V_17 ) {
F_4 ( & V_10 -> V_5 ,
L_1 , V_15 , V_17 ) ;
return V_17 ;
}
}
if ( V_12 -> V_5 ) {
V_17 = F_5 ( V_12 -> V_5 , V_3 ) ;
if ( V_17 && V_3 )
return V_17 ;
}
F_6 ( & V_10 -> V_5 , L_2 , V_15 ) ;
return V_17 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_2 ( V_2 , F_3 ( * V_5 ) , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_6 . V_5 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_8 -> V_13 . V_14 ] ;
const char * V_15 = V_16 [ V_8 -> V_13 . V_14 ] ;
int V_17 ;
if ( V_12 -> V_18 ++ )
return 0 ;
if ( V_12 -> V_5 ) {
V_17 = F_8 ( V_12 -> V_5 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_10 -> V_19 -> V_21 ) {
V_17 = V_10 -> V_19 -> V_21 ( V_10 , V_8 ) ;
if ( V_17 ) {
F_4 ( & V_10 -> V_5 ,
L_3 , V_15 , V_17 ) ;
return V_17 ;
}
}
F_6 ( & V_10 -> V_5 , L_4 , V_15 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_2 ( V_2 , F_3 ( * V_5 ) , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_6 . V_2 . V_8 ;
struct V_9 * V_10 = V_5 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_8 -> V_13 . V_14 ] ;
if ( V_10 -> V_19 -> V_22 )
V_10 -> V_19 -> V_22 ( V_10 , V_5 -> V_23 ) ;
if ( ! -- V_12 -> V_24 ) {
if ( V_10 -> V_19 -> V_25 )
V_10 -> V_19 -> V_25 ( V_10 , V_8 ) ;
F_10 ( & V_12 -> V_5 ) ;
if ( V_10 -> V_26 )
F_11 ( & V_10 -> V_26 -> V_27 [ V_8 -> V_13 . V_14 ] ) ;
}
}
static int
F_12 ( const struct V_28 * V_29 , void * V_30 , T_1 V_31 ,
struct V_32 * * V_33 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_9 * V_10 = V_9 ( V_29 -> V_34 ) ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_8 -> V_13 . V_14 ] ;
struct V_4 * V_5 ;
int V_17 = 0 ;
if ( ! ( V_5 = F_13 ( sizeof( * V_5 ) , V_35 ) ) )
return - V_36 ;
F_14 ( & V_37 , V_29 , & V_5 -> V_6 ) ;
V_5 -> V_10 = V_10 ;
* V_33 = & V_5 -> V_6 . V_2 ;
if ( ! V_12 -> V_24 ++ ) {
struct V_28 V_38 = {
. V_39 = V_29 -> V_39 ,
. V_8 = V_29 -> V_8 ,
} ;
if ( V_10 -> V_26 )
F_15 ( & V_10 -> V_26 -> V_27 [ V_8 -> V_13 . V_14 ] ) ;
if ( V_8 -> V_19 -> V_40 . V_38 ) {
V_17 = V_8 -> V_19 -> V_40 . V_38 ( V_10 , & V_38 ,
& V_12 -> V_5 ) ;
} else
if ( V_8 -> V_19 -> V_38 ) {
V_17 = F_16 ( V_8 -> V_19 -> V_38 , & V_38 ,
NULL , 0 , & V_12 -> V_5 ) ;
}
if ( V_17 )
return V_17 ;
if ( V_10 -> V_19 -> V_41 ) {
V_17 = V_10 -> V_19 -> V_41 ( V_10 , V_29 -> V_8 ,
V_12 -> V_5 ) ;
if ( V_17 )
return V_17 ;
}
}
V_17 = V_29 -> V_2 . F_17 (&(const struct nvkm_oclass) {
.base = oclass->base,
.engn = oclass->engn,
.handle = oclass->handle,
.object = oclass->object,
.client = oclass->client,
.parent = engn->object ?
engn->object :
oclass->parent,
.engine = engine,
}, data, size, &object->oproxy.object) ;
if ( V_17 )
return V_17 ;
if ( V_10 -> V_19 -> V_42 ) {
V_5 -> V_23 =
V_10 -> V_19 -> V_42 ( V_10 , V_5 -> V_6 . V_5 ) ;
if ( V_5 -> V_23 < 0 )
return V_5 -> V_23 ;
}
return 0 ;
}
static int
F_18 ( struct V_32 * V_5 , int V_14 ,
struct V_28 * V_29 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
struct V_43 * V_40 = V_10 -> V_40 ;
struct V_44 * V_45 = V_40 -> V_8 . V_13 . V_45 ;
struct V_7 * V_8 ;
T_2 V_46 = V_10 -> V_47 ;
int V_17 , V_48 , V_49 ;
for (; V_49 = 0 , V_48 = F_19 ( V_46 ) , V_46 ; V_46 &= ~ ( 1ULL << V_48 ) ) {
if ( ! ( V_8 = F_20 ( V_45 , V_48 ) ) )
continue;
V_29 -> V_8 = V_8 ;
V_29 -> V_2 . V_29 = 0 ;
if ( V_8 -> V_19 -> V_40 . V_50 ) {
V_17 = V_8 -> V_19 -> V_40 . V_50 ( V_29 , V_14 ) ;
if ( V_29 -> V_2 . V_29 ) {
if ( ! V_29 -> V_2 . F_17 )
V_29 -> V_2 . F_17 = V_51 ;
V_29 -> F_17 = F_12 ;
return 0 ;
}
V_14 -= V_17 ;
continue;
}
while ( V_8 -> V_19 -> V_50 [ V_49 ] . V_29 ) {
if ( V_49 ++ == V_14 ) {
V_29 -> V_2 = V_8 -> V_19 -> V_50 [ V_14 ] ;
if ( ! V_29 -> V_2 . F_17 )
V_29 -> V_2 . F_17 = V_51 ;
V_29 -> F_17 = F_12 ;
return 0 ;
}
}
V_14 -= V_49 ;
}
return - V_52 ;
}
static int
F_21 ( struct V_32 * V_5 , T_1 type ,
struct V_53 * * V_54 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
if ( V_10 -> V_19 -> V_55 )
return V_10 -> V_19 -> V_55 ( V_10 , type , V_54 ) ;
return - V_56 ;
}
static int
F_22 ( struct V_32 * V_5 , T_2 * V_57 , T_1 * V_31 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
* V_57 = V_10 -> V_57 ;
* V_31 = V_10 -> V_31 ;
return 0 ;
}
static int
F_23 ( struct V_32 * V_5 , T_2 V_57 , T_1 * V_30 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
if ( F_24 ( ! V_10 -> V_58 ) ) {
V_10 -> V_58 = F_25 ( V_10 -> V_57 , V_10 -> V_31 ) ;
if ( ! V_10 -> V_58 )
return - V_36 ;
}
if ( F_24 ( V_57 + 4 > V_10 -> V_31 ) )
return - V_52 ;
* V_30 = F_26 ( V_10 -> V_58 + V_57 ) ;
return 0 ;
}
static int
F_27 ( struct V_32 * V_5 , T_2 V_57 , T_1 V_30 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
if ( F_24 ( ! V_10 -> V_58 ) ) {
V_10 -> V_58 = F_25 ( V_10 -> V_57 , V_10 -> V_31 ) ;
if ( ! V_10 -> V_58 )
return - V_36 ;
}
if ( F_24 ( V_57 + 4 > V_10 -> V_31 ) )
return - V_52 ;
F_28 ( V_30 , V_10 -> V_58 + V_57 ) ;
return 0 ;
}
static int
F_29 ( struct V_32 * V_5 , bool V_3 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
V_10 -> V_19 -> V_59 ( V_10 ) ;
return 0 ;
}
static int
F_30 ( struct V_32 * V_5 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
V_10 -> V_19 -> V_60 ( V_10 ) ;
return 0 ;
}
static void *
F_31 ( struct V_32 * V_5 )
{
struct V_9 * V_10 = V_9 ( V_5 ) ;
struct V_43 * V_40 = V_10 -> V_40 ;
void * V_30 = V_10 -> V_19 -> V_61 ( V_10 ) ;
unsigned long V_62 ;
F_32 ( & V_40 -> V_63 , V_62 ) ;
if ( ! F_33 ( & V_10 -> V_64 ) ) {
F_34 ( V_10 -> V_65 , V_40 -> V_46 ) ;
F_35 ( & V_10 -> V_64 ) ;
}
F_36 ( & V_40 -> V_63 , V_62 ) ;
if ( V_10 -> V_58 )
F_37 ( V_10 -> V_58 ) ;
F_38 ( NULL , & V_10 -> V_26 , NULL ) ;
F_39 ( & V_10 -> V_66 ) ;
F_39 ( & V_10 -> V_67 ) ;
return V_30 ;
}
int
F_40 ( const struct V_68 * V_19 ,
struct V_43 * V_40 , T_1 V_31 , T_1 V_69 , bool V_70 ,
T_2 V_26 , T_2 V_66 , T_2 V_47 , int V_71 , T_1 V_2 , T_1 V_58 ,
const struct V_28 * V_29 ,
struct V_9 * V_10 )
{
struct V_72 * V_39 = V_29 -> V_39 ;
struct V_44 * V_45 = V_40 -> V_8 . V_13 . V_45 ;
struct V_73 * V_74 = V_45 -> V_74 ;
struct V_75 * V_76 ;
unsigned long V_62 ;
int V_17 ;
F_41 ( & V_68 , V_29 , & V_10 -> V_5 ) ;
V_10 -> V_19 = V_19 ;
V_10 -> V_40 = V_40 ;
V_10 -> V_47 = V_47 ;
F_42 ( & V_10 -> V_64 ) ;
V_17 = F_43 ( V_45 , V_31 , V_69 , V_70 , NULL , & V_10 -> V_67 ) ;
if ( V_17 )
return V_17 ;
if ( V_66 ) {
V_76 = F_44 ( V_39 , V_66 ) ;
if ( F_45 ( V_76 ) )
return F_46 ( V_76 ) ;
V_17 = F_47 ( & V_76 -> V_5 , V_10 -> V_67 , - 16 ,
& V_10 -> V_66 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_26 && V_74 ) {
if ( ! V_39 -> V_26 || V_39 -> V_26 -> V_74 == V_74 ) {
V_17 = F_38 ( V_39 -> V_26 , & V_10 -> V_26 , NULL ) ;
if ( V_17 )
return V_17 ;
} else {
return - V_52 ;
}
} else {
return - V_77 ;
}
F_32 ( & V_40 -> V_63 , V_62 ) ;
V_10 -> V_65 = F_48 ( V_40 -> V_46 , V_78 ) ;
if ( V_10 -> V_65 >= V_78 ) {
F_36 ( & V_40 -> V_63 , V_62 ) ;
return - V_79 ;
}
F_49 ( & V_10 -> V_64 , & V_40 -> V_10 ) ;
F_50 ( V_10 -> V_65 , V_40 -> V_46 ) ;
F_36 ( & V_40 -> V_63 , V_62 ) ;
V_10 -> V_57 = V_45 -> V_19 -> V_80 ( V_45 , V_71 ) +
V_2 + V_58 * V_10 -> V_65 ;
V_10 -> V_31 = V_58 ;
F_51 ( V_40 ) ;
return 0 ;
}
