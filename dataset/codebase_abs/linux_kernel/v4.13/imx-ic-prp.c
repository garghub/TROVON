static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_1 ;
}
static int F_3 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_5 ;
bool V_7 ;
V_6 -> V_8 = V_6 -> V_9 -> V_8 [ V_5 -> V_10 ] ;
V_7 = ! ! ( V_6 -> V_11 -> V_12 & V_13 ) ;
F_4 ( V_6 -> V_8 , V_6 -> V_14 , V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_6 )
{
}
static struct V_15 *
F_6 ( struct V_1 * V_6 , struct V_16 * V_17 ,
unsigned int V_18 , enum V_19 V_20 )
{
struct V_4 * V_5 = V_6 -> V_5 ;
if ( V_20 == V_21 )
return F_7 ( & V_5 -> V_3 , V_17 , V_18 ) ;
else
return & V_6 -> V_22 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_15 * V_25 ;
int V_26 = 0 ;
F_9 ( & V_6 -> V_27 ) ;
switch ( V_24 -> V_18 ) {
case V_28 :
V_26 = F_10 ( & V_24 -> V_24 , V_24 -> V_29 ,
V_30 ) ;
break;
case V_31 :
case V_32 :
if ( V_24 -> V_29 != 0 ) {
V_26 = - V_33 ;
goto V_34;
}
V_25 = F_6 ( V_6 , V_17 , V_28 , V_24 -> V_20 ) ;
V_24 -> V_24 = V_25 -> V_24 ;
break;
default:
V_26 = - V_33 ;
}
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_35 * V_36 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_15 * V_37 ;
int V_26 = 0 ;
if ( V_36 -> V_18 >= V_38 )
return - V_33 ;
F_9 ( & V_6 -> V_27 ) ;
V_37 = F_6 ( V_6 , V_17 , V_36 -> V_18 , V_36 -> V_20 ) ;
if ( ! V_37 ) {
V_26 = - V_33 ;
goto V_34;
}
V_36 -> V_39 = * V_37 ;
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_35 * V_36 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_15 * V_37 , * V_25 ;
const struct V_40 * V_41 ;
int V_26 = 0 ;
T_1 V_24 ;
if ( V_36 -> V_18 >= V_38 )
return - V_33 ;
F_9 ( & V_6 -> V_27 ) ;
if ( V_6 -> V_42 > 0 ) {
V_26 = - V_43 ;
goto V_34;
}
V_25 = F_6 ( V_6 , V_17 , V_28 , V_36 -> V_20 ) ;
switch ( V_36 -> V_18 ) {
case V_28 :
F_14 ( & V_36 -> V_39 . V_44 , V_45 , V_46 ,
V_47 , & V_36 -> V_39 . V_48 ,
V_49 , V_50 , V_51 , V_52 ) ;
V_41 = F_15 ( V_36 -> V_39 . V_24 ,
V_30 ) ;
if ( ! V_41 ) {
F_10 ( & V_24 , 0 , V_30 ) ;
V_41 = F_15 ( V_24 , V_30 ) ;
V_36 -> V_39 . V_24 = V_41 -> V_53 [ 0 ] ;
}
F_16 ( & V_36 -> V_39 , V_25 ,
true ) ;
break;
case V_31 :
case V_32 :
V_36 -> V_39 = * V_25 ;
break;
}
V_37 = F_6 ( V_6 , V_17 , V_36 -> V_18 , V_36 -> V_20 ) ;
* V_37 = V_36 -> V_39 ;
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_17 ( struct V_54 * V_55 ,
const struct V_56 * V_57 ,
const struct V_56 * V_58 , T_1 V_59 )
{
struct V_2 * V_3 = F_18 ( V_55 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = V_5 -> V_1 ;
struct V_2 * V_60 ;
int V_26 = 0 ;
F_19 ( V_5 -> V_61 , L_1 , V_58 -> V_55 -> V_62 ,
V_57 -> V_55 -> V_62 ) ;
V_60 = F_18 ( V_58 -> V_55 ) ;
F_9 ( & V_6 -> V_27 ) ;
if ( V_57 -> V_59 & V_63 ) {
if ( V_59 & V_64 ) {
if ( V_6 -> V_11 ) {
V_26 = - V_43 ;
goto V_34;
}
if ( V_6 -> V_65 && ( V_60 -> V_12 &
V_13 ) ) {
V_26 = - V_33 ;
goto V_34;
}
V_6 -> V_11 = V_60 ;
} else {
V_6 -> V_11 = NULL ;
}
goto V_34;
}
if ( V_59 & V_64 ) {
switch ( V_57 -> V_29 ) {
case V_31 :
if ( V_6 -> V_65 ) {
V_26 = - V_43 ;
goto V_34;
}
if ( V_6 -> V_11 && ( V_6 -> V_11 -> V_12 &
V_13 ) ) {
V_26 = - V_33 ;
goto V_34;
}
V_6 -> V_65 = V_60 ;
break;
case V_32 :
if ( V_6 -> V_66 ) {
V_26 = - V_43 ;
goto V_34;
}
V_6 -> V_66 = V_60 ;
break;
default:
V_26 = - V_33 ;
}
} else {
switch ( V_57 -> V_29 ) {
case V_31 :
V_6 -> V_65 = NULL ;
break;
case V_32 :
V_6 -> V_66 = NULL ;
break;
default:
V_26 = - V_33 ;
}
}
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_67 * V_68 ,
struct V_35 * V_69 ,
struct V_35 * V_70 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = V_5 -> V_1 ;
struct V_71 * V_72 ;
int V_26 ;
V_26 = F_21 ( V_3 , V_68 ,
V_69 , V_70 ) ;
if ( V_26 )
return V_26 ;
V_72 = F_22 ( V_6 -> V_9 , & V_5 -> V_3 . V_55 ,
V_73 ) ;
if ( F_23 ( V_72 ) )
V_72 = NULL ;
F_9 ( & V_6 -> V_27 ) ;
if ( V_6 -> V_11 -> V_12 & V_13 ) {
if ( V_6 -> V_65 )
V_26 = - V_33 ;
goto V_34;
} else {
if ( ! V_72 ) {
V_26 = - V_33 ;
goto V_34;
}
}
if ( V_72 ) {
switch ( V_72 -> V_3 -> V_12 ) {
case V_74 :
V_6 -> V_14 = 0 ;
break;
case V_75 :
V_6 -> V_14 = 1 ;
break;
default:
V_26 = - V_33 ;
}
} else {
V_6 -> V_14 = 0 ;
}
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_24 ( struct V_2 * V_3 , int V_76 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = V_5 -> V_1 ;
int V_26 = 0 ;
F_9 ( & V_6 -> V_27 ) ;
if ( ! V_6 -> V_11 || ( ! V_6 -> V_65 && ! V_6 -> V_66 ) ) {
V_26 = - V_77 ;
goto V_34;
}
if ( V_6 -> V_42 != ! V_76 )
goto V_78;
F_19 ( V_5 -> V_61 , L_2 , V_76 ? L_3 : L_4 ) ;
if ( V_76 )
V_26 = F_3 ( V_6 ) ;
else
F_5 ( V_6 ) ;
if ( V_26 )
goto V_34;
V_26 = F_25 ( V_6 -> V_11 , V_79 , V_80 , V_76 ) ;
V_26 = ( V_26 && V_26 != - V_81 ) ? V_26 : 0 ;
if ( V_26 ) {
if ( V_76 )
F_5 ( V_6 ) ;
goto V_34;
}
V_78:
V_6 -> V_42 += V_76 ? 1 : - 1 ;
if ( V_6 -> V_42 < 0 )
V_6 -> V_42 = 0 ;
V_34:
F_11 ( & V_6 -> V_27 ) ;
return V_26 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_83 -> V_18 >= V_38 )
return - V_33 ;
F_9 ( & V_6 -> V_27 ) ;
V_83 -> V_84 = V_6 -> V_85 ;
F_11 ( & V_6 -> V_27 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_83 -> V_18 >= V_38 )
return - V_33 ;
F_9 ( & V_6 -> V_27 ) ;
V_6 -> V_85 = V_83 -> V_84 ;
F_11 ( & V_6 -> V_27 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_86 , V_26 ;
T_1 V_24 ;
V_6 -> V_9 = F_29 ( V_3 -> V_87 -> V_61 ) ;
for ( V_86 = 0 ; V_86 < V_38 ; V_86 ++ ) {
V_6 -> V_18 [ V_86 ] . V_59 = ( V_86 == V_28 ) ?
V_63 : V_88 ;
}
V_6 -> V_85 . V_89 = 1 ;
V_6 -> V_85 . V_90 = 30 ;
F_10 ( & V_24 , 0 , V_91 ) ;
V_26 = F_30 ( & V_6 -> V_22 , 640 , 480 , V_24 ,
V_92 , NULL ) ;
if ( V_26 )
return V_26 ;
return F_31 ( & V_3 -> V_55 , V_38 , V_6 -> V_18 ) ;
}
static int F_32 ( struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_33 ( V_5 -> V_61 , sizeof( * V_6 ) , V_93 ) ;
if ( ! V_6 )
return - V_94 ;
F_34 ( & V_6 -> V_27 ) ;
V_5 -> V_1 = V_6 ;
V_6 -> V_5 = V_5 ;
return 0 ;
}
static void F_35 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_1 ;
F_36 ( & V_6 -> V_27 ) ;
}
