static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 . V_7 ; V_5 ++ ) {
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_4 , V_5 ) ;
* V_9 = V_10 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = F_4 ( V_12 -> V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_12 -> V_12 = V_14 -> V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * V_18 )
{
const struct V_13 * V_14 ;
if ( V_18 -> V_15 )
return - V_16 ;
V_14 = F_6 ( V_18 -> V_12 ) ;
if ( ! V_14 )
return - V_16 ;
V_18 -> V_19 = V_20 ;
V_18 -> V_21 = V_22 ;
V_18 -> V_23 = V_24 ;
V_18 -> V_25 = V_26 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 =
F_8 ( V_2 , struct V_29 , V_2 ) ;
V_28 -> V_31 = V_28 -> V_32 == V_33 ?
* F_2 ( V_2 , V_4 , V_28 -> V_34 ) :
V_30 -> V_35 ;
return 0 ;
}
static void F_9 ( struct V_29 * V_30 )
{
const struct V_13 * V_14 =
F_6 ( V_30 -> V_35 . V_12 ) ;
F_10 ( & V_30 -> V_36 , V_30 -> V_35 . V_37 ,
V_30 -> V_35 . V_38 , V_30 -> V_35 . V_39 ) ;
F_11 ( & V_30 -> V_36 , 0 , V_30 -> V_35 . V_37 * V_14 -> V_40 ) ;
F_12 ( & V_30 -> V_36 , V_30 -> V_35 . V_38 ) ;
F_13 ( & V_30 -> V_36 , V_14 -> V_41 ) ;
F_14 ( & V_30 -> V_36 , V_30 -> V_35 . V_39 , false ) ;
F_15 ( & V_30 -> V_36 , V_30 -> V_35 . V_42 ) ;
F_16 ( & V_30 -> V_36 , V_30 -> V_35 . V_43 ) ;
F_17 ( & V_30 -> V_36 , V_30 -> V_35 . V_44 ) ;
F_18 ( & V_30 -> V_36 , V_30 -> V_35 . V_45 ) ;
}
static void F_19 ( struct V_8 * V_28 )
{
const struct V_13 * V_14 ;
V_14 = F_6 ( V_28 -> V_12 ) ;
if ( ! V_14 )
V_28 -> V_12 = V_10 . V_12 ;
V_28 -> V_37 = F_20 ( V_46 , V_28 -> V_37 , V_20 ,
V_22 ) & ~ 1 ;
V_28 -> V_38 = F_20 ( V_46 , V_28 -> V_38 , V_24 ,
V_26 ) & ~ 1 ;
if ( V_28 -> V_39 == V_47 || V_28 -> V_39 == V_48 )
V_28 -> V_39 = V_10 . V_39 ;
F_21 ( V_28 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_23 ( V_2 ) ;
struct V_8 * V_9 ;
if ( V_28 -> V_32 == V_49 ) {
if ( V_30 -> V_50 )
return - V_51 ;
V_9 = & V_30 -> V_35 ;
} else {
V_9 = F_2 ( V_2 , V_4 , V_28 -> V_34 ) ;
}
F_19 ( & V_28 -> V_31 ) ;
F_24 ( V_30 -> V_52 , L_1
L_2
L_3 , V_30 -> V_2 . V_53 ,
V_9 -> V_37 , V_9 -> V_38 , V_9 -> V_12 ,
V_9 -> V_42 , V_9 -> V_44 ,
V_9 -> V_45 , V_9 -> V_43 ,
V_28 -> V_31 . V_37 , V_28 -> V_31 . V_38 , V_28 -> V_31 . V_12 ,
V_28 -> V_31 . V_42 , V_28 -> V_31 . V_44 ,
V_28 -> V_31 . V_45 , V_28 -> V_31 . V_43 ) ;
* V_9 = V_28 -> V_31 ;
return 0 ;
}
static int F_25 ( void * V_54 )
{
struct V_29 * V_30 = V_54 ;
unsigned int V_5 ;
F_26 () ;
F_27 ( V_55 ) ;
for (; ; ) {
F_28 () ;
if ( F_29 () )
break;
F_30 ( & V_30 -> V_36 , 0 , 0 , V_30 -> V_50 ) ;
for ( V_5 = 0 ; V_5 < V_30 -> V_2 . V_6 . V_7 ; V_5 ++ )
F_31 ( & V_30 -> V_2 . V_6 . V_56 [ V_5 ] ,
V_30 -> V_50 ) ;
F_32 ( V_57 / 60 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_58 )
{
struct V_29 * V_30 =
F_8 ( V_2 , struct V_29 , V_2 ) ;
int V_59 ;
if ( V_58 ) {
const struct V_13 * V_14 ;
unsigned int V_60 ;
if ( V_30 -> V_61 )
return 0 ;
V_14 = F_6 ( V_30 -> V_35 . V_12 ) ;
V_60 = V_30 -> V_35 . V_37 * V_14 -> V_40 *
V_30 -> V_35 . V_38 ;
V_30 -> V_50 = F_34 ( V_60 ) ;
if ( ! V_30 -> V_50 )
return - V_62 ;
F_9 ( V_30 ) ;
V_30 -> V_61 = F_35 ( F_25 , V_30 ,
L_4 , V_30 -> V_2 . V_63 -> V_53 ) ;
if ( F_36 ( V_30 -> V_61 ) ) {
F_37 ( V_30 -> V_52 , L_5 ,
V_30 -> V_2 . V_53 ) ;
F_38 ( V_30 -> V_50 ) ;
V_30 -> V_50 = NULL ;
return F_39 ( V_30 -> V_61 ) ;
}
} else {
if ( ! V_30 -> V_61 )
return 0 ;
V_59 = F_40 ( V_30 -> V_61 ) ;
if ( V_59 )
return V_59 ;
V_30 -> V_61 = NULL ;
F_38 ( V_30 -> V_50 ) ;
V_30 -> V_50 = NULL ;
return 0 ;
}
return 0 ;
}
static void F_41 ( struct V_64 * V_65 , struct V_64 * V_66 ,
void * V_67 )
{
struct V_68 * V_69 = F_42 ( V_65 ) ;
struct V_29 * V_30 =
F_8 ( V_69 , struct V_29 , V_69 ) ;
F_43 ( V_69 , & V_30 -> V_2 ) ;
F_44 ( & V_30 -> V_36 ) ;
F_45 ( V_30 ) ;
}
static int F_46 ( struct V_64 * V_65 , struct V_64 * V_66 ,
void * V_67 )
{
struct V_70 * V_63 = V_67 ;
struct V_71 * V_72 = V_65 -> V_73 ;
struct V_29 * V_30 ;
int V_59 ;
V_30 = F_47 ( sizeof( * V_30 ) , V_74 ) ;
if ( ! V_30 )
return - V_62 ;
V_59 = F_48 (&vsen->ved, &vsen->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 1 ,
(const unsigned long[1]) {MEDIA_PAD_FL_SOURCE},
&vimc_sen_ops) ;
if ( V_59 )
goto V_75;
F_49 ( V_65 , & V_30 -> V_69 ) ;
V_30 -> V_52 = V_65 ;
V_30 -> V_35 = V_10 ;
F_50 ( & V_30 -> V_36 , V_30 -> V_35 . V_37 ,
V_30 -> V_35 . V_38 ) ;
V_59 = F_51 ( & V_30 -> V_36 , V_22 ) ;
if ( V_59 )
goto V_76;
return 0 ;
V_76:
F_43 ( & V_30 -> V_69 , & V_30 -> V_2 ) ;
V_75:
F_45 ( V_30 ) ;
return V_59 ;
}
static int F_52 ( struct V_77 * V_78 )
{
return F_53 ( & V_78 -> V_52 , & V_79 ) ;
}
static int F_54 ( struct V_77 * V_78 )
{
F_55 ( & V_78 -> V_52 , & V_79 ) ;
return 0 ;
}
