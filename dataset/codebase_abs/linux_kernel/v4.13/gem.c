static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_6 * * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_7 = V_4 -> V_7 ;
return V_4 -> V_8 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
}
static void * F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 )
return V_4 -> V_9 ;
else if ( V_4 -> V_5 . V_10 )
return F_7 ( V_4 -> V_5 . V_10 -> V_11 ) ;
else
return F_8 ( V_4 -> V_12 , V_4 -> V_13 , V_14 ,
F_9 ( V_15 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 )
return;
else if ( V_4 -> V_5 . V_10 )
F_11 ( V_4 -> V_5 . V_10 -> V_11 , V_16 ) ;
else
F_12 ( V_16 ) ;
}
static void * F_13 ( struct V_1 * V_2 , unsigned int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 )
return V_4 -> V_9 + V_17 * V_18 ;
else if ( V_4 -> V_5 . V_10 )
return F_14 ( V_4 -> V_5 . V_10 -> V_11 , V_17 ) ;
else
return F_8 ( V_4 -> V_12 + V_17 , 1 , V_14 ,
F_9 ( V_15 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_17 ,
void * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 )
return;
else if ( V_4 -> V_5 . V_10 )
F_16 ( V_4 -> V_5 . V_10 -> V_11 , V_17 , V_16 ) ;
else
F_12 ( V_16 ) ;
}
static struct V_1 * F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( & V_4 -> V_5 ) ;
return V_2 ;
}
static int F_19 ( struct V_19 * V_20 , struct V_3 * V_2 )
{
int V_21 = V_22 | V_23 ;
T_2 V_24 ;
if ( V_2 -> V_25 )
return - V_26 ;
V_2 -> V_25 = F_20 ( sizeof( * V_2 -> V_25 ) , V_27 ) ;
if ( ! V_2 -> V_25 )
return - V_28 ;
F_21 ( & V_20 -> V_29 ) ;
V_24 = F_22 ( & V_20 -> V_25 ,
V_2 -> V_25 , V_2 -> V_5 . V_30 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 ) {
F_23 ( V_20 -> V_31 -> V_32 , L_1 ,
V_24 ) ;
goto V_33;
}
V_2 -> V_8 = V_2 -> V_25 -> V_34 ;
V_24 = F_24 ( V_20 -> V_35 , V_2 -> V_8 , V_2 -> V_7 -> V_36 ,
V_2 -> V_7 -> V_37 , V_21 ) ;
if ( V_24 < 0 ) {
F_23 ( V_20 -> V_31 -> V_32 , L_2 , V_24 ) ;
goto remove;
}
V_2 -> V_30 = V_24 ;
F_25 ( & V_20 -> V_29 ) ;
return 0 ;
remove:
F_26 ( V_2 -> V_25 ) ;
V_33:
F_25 ( & V_20 -> V_29 ) ;
F_27 ( V_2 -> V_25 ) ;
return V_24 ;
}
static int F_28 ( struct V_19 * V_20 , struct V_3 * V_2 )
{
if ( ! V_2 -> V_25 )
return 0 ;
F_21 ( & V_20 -> V_29 ) ;
F_29 ( V_20 -> V_35 , V_2 -> V_8 , V_2 -> V_30 ) ;
F_26 ( V_2 -> V_25 ) ;
F_25 ( & V_20 -> V_29 ) ;
F_27 ( V_2 -> V_25 ) ;
return 0 ;
}
static struct V_3 * F_30 ( struct V_38 * V_31 ,
T_3 V_30 )
{
struct V_3 * V_2 ;
int V_24 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return F_31 ( - V_28 ) ;
F_32 ( & V_2 -> V_39 , & V_40 ) ;
V_30 = F_33 ( V_30 , V_18 ) ;
V_24 = F_34 ( V_31 , & V_2 -> V_5 , V_30 ) ;
if ( V_24 < 0 )
goto free;
V_24 = F_35 ( & V_2 -> V_5 ) ;
if ( V_24 < 0 )
goto V_41;
return V_2 ;
V_41:
F_36 ( & V_2 -> V_5 ) ;
free:
F_27 ( V_2 ) ;
return F_31 ( V_24 ) ;
}
static void F_37 ( struct V_38 * V_31 , struct V_3 * V_2 )
{
if ( V_2 -> V_12 ) {
F_38 ( & V_2 -> V_5 , V_2 -> V_12 , true , true ) ;
F_39 ( V_2 -> V_7 ) ;
F_27 ( V_2 -> V_7 ) ;
} else if ( V_2 -> V_9 ) {
F_40 ( V_31 -> V_32 , V_2 -> V_5 . V_30 , V_2 -> V_9 , V_2 -> V_8 ) ;
}
}
static int F_41 ( struct V_38 * V_31 , struct V_3 * V_2 )
{
struct V_42 * V_43 ;
unsigned int V_44 ;
V_2 -> V_12 = F_42 ( & V_2 -> V_5 ) ;
if ( F_43 ( V_2 -> V_12 ) )
return F_44 ( V_2 -> V_12 ) ;
V_2 -> V_13 = V_2 -> V_5 . V_30 >> V_45 ;
V_2 -> V_7 = F_45 ( V_2 -> V_12 , V_2 -> V_13 ) ;
if ( F_43 ( V_2 -> V_7 ) )
goto V_46;
F_46 (bo->sgt->sgl, s, bo->sgt->nents, i)
F_47 ( V_43 ) = F_48 ( V_43 ) ;
F_49 ( V_31 -> V_32 , V_2 -> V_7 -> V_36 , V_2 -> V_7 -> V_37 ,
V_47 ) ;
return 0 ;
V_46:
F_38 ( & V_2 -> V_5 , V_2 -> V_12 , false , false ) ;
return F_44 ( V_2 -> V_7 ) ;
}
static int F_50 ( struct V_38 * V_31 , struct V_3 * V_2 )
{
struct V_19 * V_20 = V_31 -> V_48 ;
int V_24 ;
if ( V_20 -> V_35 ) {
V_24 = F_41 ( V_31 , V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_19 ( V_20 , V_2 ) ;
if ( V_24 < 0 ) {
F_37 ( V_31 , V_2 ) ;
return V_24 ;
}
} else {
T_3 V_30 = V_2 -> V_5 . V_30 ;
V_2 -> V_9 = F_51 ( V_31 -> V_32 , V_30 , & V_2 -> V_8 ,
V_27 | V_49 ) ;
if ( ! V_2 -> V_9 ) {
F_23 ( V_31 -> V_32 ,
L_3 ,
V_30 ) ;
return - V_28 ;
}
}
return 0 ;
}
struct V_3 * F_52 ( struct V_38 * V_31 , T_3 V_30 ,
unsigned long V_50 )
{
struct V_3 * V_2 ;
int V_24 ;
V_2 = F_30 ( V_31 , V_30 ) ;
if ( F_43 ( V_2 ) )
return V_2 ;
V_24 = F_50 ( V_31 , V_2 ) ;
if ( V_24 < 0 )
goto V_41;
if ( V_50 & V_51 )
V_2 -> V_52 . V_53 = V_54 ;
if ( V_50 & V_55 )
V_2 -> V_50 |= V_56 ;
return V_2 ;
V_41:
F_36 ( & V_2 -> V_5 ) ;
F_27 ( V_2 ) ;
return F_31 ( V_24 ) ;
}
struct V_3 * F_53 ( struct V_57 * V_58 ,
struct V_38 * V_31 ,
T_3 V_30 ,
unsigned long V_50 ,
T_4 * V_59 )
{
struct V_3 * V_2 ;
int V_24 ;
V_2 = F_52 ( V_31 , V_30 , V_50 ) ;
if ( F_43 ( V_2 ) )
return V_2 ;
V_24 = F_54 ( V_58 , & V_2 -> V_5 , V_59 ) ;
if ( V_24 ) {
F_55 ( & V_2 -> V_5 ) ;
return F_31 ( V_24 ) ;
}
F_3 ( & V_2 -> V_5 ) ;
return V_2 ;
}
static struct V_3 * F_56 ( struct V_38 * V_31 ,
struct V_60 * V_61 )
{
struct V_19 * V_20 = V_31 -> V_48 ;
struct V_62 * V_63 ;
struct V_3 * V_2 ;
int V_24 ;
V_2 = F_30 ( V_31 , V_61 -> V_30 ) ;
if ( F_43 ( V_2 ) )
return V_2 ;
V_63 = F_57 ( V_61 , V_31 -> V_32 ) ;
if ( F_43 ( V_63 ) ) {
V_24 = F_44 ( V_63 ) ;
goto free;
}
F_58 ( V_61 ) ;
V_2 -> V_7 = F_59 ( V_63 , V_47 ) ;
if ( F_43 ( V_2 -> V_7 ) ) {
V_24 = F_44 ( V_2 -> V_7 ) ;
goto V_64;
}
if ( V_20 -> V_35 ) {
V_24 = F_19 ( V_20 , V_2 ) ;
if ( V_24 < 0 )
goto V_64;
} else {
if ( V_2 -> V_7 -> V_37 > 1 ) {
V_24 = - V_65 ;
goto V_64;
}
V_2 -> V_8 = F_47 ( V_2 -> V_7 -> V_36 ) ;
}
V_2 -> V_5 . V_10 = V_63 ;
return V_2 ;
V_64:
if ( ! F_60 ( V_2 -> V_7 ) )
F_61 ( V_63 , V_2 -> V_7 , V_47 ) ;
F_62 ( V_61 , V_63 ) ;
F_63 ( V_61 ) ;
free:
F_36 ( & V_2 -> V_5 ) ;
F_27 ( V_2 ) ;
return F_31 ( V_24 ) ;
}
void F_55 ( struct V_66 * V_5 )
{
struct V_19 * V_20 = V_5 -> V_32 -> V_48 ;
struct V_3 * V_2 = F_64 ( V_5 ) ;
if ( V_20 -> V_35 )
F_28 ( V_20 , V_2 ) ;
if ( V_5 -> V_10 ) {
F_61 ( V_5 -> V_10 , V_2 -> V_7 ,
V_47 ) ;
F_65 ( V_5 , NULL ) ;
} else {
F_37 ( V_5 -> V_32 , V_2 ) ;
}
F_36 ( V_5 ) ;
F_27 ( V_2 ) ;
}
int F_66 ( struct V_57 * V_58 , struct V_38 * V_31 ,
struct V_67 * args )
{
unsigned int V_68 = F_67 ( args -> V_69 * args -> V_70 , 8 ) ;
struct V_19 * V_20 = V_31 -> V_48 ;
struct V_3 * V_2 ;
args -> V_71 = F_33 ( V_68 , V_20 -> V_72 ) ;
args -> V_30 = args -> V_71 * args -> V_73 ;
V_2 = F_53 ( V_58 , V_31 , args -> V_30 , 0 ,
& args -> V_59 ) ;
if ( F_43 ( V_2 ) )
return F_44 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_57 * V_58 , struct V_38 * V_31 ,
T_4 V_59 , T_5 * V_74 )
{
struct V_66 * V_5 ;
struct V_3 * V_2 ;
V_5 = F_69 ( V_58 , V_59 ) ;
if ( ! V_5 ) {
F_23 ( V_31 -> V_32 , L_4 ) ;
return - V_65 ;
}
V_2 = F_64 ( V_5 ) ;
* V_74 = F_70 ( & V_2 -> V_5 . V_75 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
static int F_71 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_79 ;
struct V_66 * V_5 = V_79 -> V_80 ;
struct V_3 * V_2 = F_64 ( V_5 ) ;
struct V_17 * V_17 ;
T_6 V_74 ;
int V_24 ;
if ( ! V_2 -> V_12 )
return V_81 ;
V_74 = ( V_77 -> V_82 - V_79 -> V_83 ) >> V_45 ;
V_17 = V_2 -> V_12 [ V_74 ] ;
V_24 = F_72 ( V_79 , V_77 -> V_82 , V_17 ) ;
switch ( V_24 ) {
case - V_84 :
case 0 :
case - V_85 :
case - V_86 :
case - V_26 :
return V_87 ;
case - V_28 :
return V_88 ;
}
return V_81 ;
}
int F_73 ( struct V_58 * V_58 , struct V_78 * V_79 )
{
struct V_66 * V_5 ;
struct V_3 * V_2 ;
int V_89 ;
V_89 = F_74 ( V_58 , V_79 ) ;
if ( V_89 )
return V_89 ;
V_5 = V_79 -> V_80 ;
V_2 = F_64 ( V_5 ) ;
if ( ! V_2 -> V_12 ) {
unsigned long V_90 = V_79 -> V_90 ;
V_79 -> V_91 &= ~ V_92 ;
V_79 -> V_90 = 0 ;
V_89 = F_75 ( V_5 -> V_32 -> V_32 , V_79 , V_2 -> V_9 , V_2 -> V_8 ,
V_5 -> V_30 ) ;
if ( V_89 ) {
F_76 ( V_79 ) ;
return V_89 ;
}
V_79 -> V_90 = V_90 ;
} else {
T_7 V_21 = F_77 ( V_79 -> V_91 ) ;
V_79 -> V_91 |= V_93 ;
V_79 -> V_91 &= ~ V_92 ;
V_79 -> V_94 = F_9 ( V_21 ) ;
}
return 0 ;
}
static struct V_6 *
F_78 ( struct V_62 * V_63 ,
enum V_95 V_96 )
{
struct V_66 * V_5 = V_63 -> V_11 -> V_97 ;
struct V_3 * V_2 = F_64 ( V_5 ) ;
struct V_6 * V_7 ;
V_7 = F_79 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return NULL ;
if ( V_2 -> V_12 ) {
struct V_42 * V_98 ;
unsigned int V_44 ;
if ( F_80 ( V_7 , V_2 -> V_13 , V_27 ) )
goto free;
F_46 (sgt->sgl, sg, bo->num_pages, i)
F_81 ( V_98 , V_2 -> V_12 [ V_44 ] , V_18 , 0 ) ;
if ( F_82 ( V_63 -> V_32 , V_7 -> V_36 , V_7 -> V_37 , V_96 ) == 0 )
goto free;
} else {
if ( F_80 ( V_7 , 1 , V_27 ) )
goto free;
F_47 ( V_7 -> V_36 ) = V_2 -> V_8 ;
F_83 ( V_7 -> V_36 ) = V_5 -> V_30 ;
}
return V_7 ;
free:
F_39 ( V_7 ) ;
F_27 ( V_7 ) ;
return NULL ;
}
static void F_84 ( struct V_62 * V_63 ,
struct V_6 * V_7 ,
enum V_95 V_96 )
{
struct V_66 * V_5 = V_63 -> V_11 -> V_97 ;
struct V_3 * V_2 = F_64 ( V_5 ) ;
if ( V_2 -> V_12 )
F_85 ( V_63 -> V_32 , V_7 -> V_36 , V_7 -> V_37 , V_96 ) ;
F_39 ( V_7 ) ;
F_27 ( V_7 ) ;
}
static void F_86 ( struct V_60 * V_61 )
{
F_87 ( V_61 ) ;
}
static void * F_88 ( struct V_60 * V_61 ,
unsigned long V_17 )
{
return NULL ;
}
static void F_89 ( struct V_60 * V_61 ,
unsigned long V_17 ,
void * V_16 )
{
}
static void * F_90 ( struct V_60 * V_61 , unsigned long V_17 )
{
return NULL ;
}
static void F_91 ( struct V_60 * V_61 , unsigned long V_17 ,
void * V_16 )
{
}
static int F_92 ( struct V_60 * V_61 , struct V_78 * V_79 )
{
return - V_65 ;
}
static void * F_93 ( struct V_60 * V_61 )
{
struct V_66 * V_5 = V_61 -> V_97 ;
struct V_3 * V_2 = F_64 ( V_5 ) ;
return V_2 -> V_9 ;
}
static void F_94 ( struct V_60 * V_61 , void * V_9 )
{
}
struct V_60 * F_95 ( struct V_38 * V_31 ,
struct V_66 * V_5 ,
int V_50 )
{
F_96 ( V_99 ) ;
V_99 . V_100 = & V_101 ;
V_99 . V_30 = V_5 -> V_30 ;
V_99 . V_50 = V_50 ;
V_99 . V_97 = V_5 ;
return F_97 ( V_31 , & V_99 ) ;
}
struct V_66 * F_98 ( struct V_38 * V_31 ,
struct V_60 * V_61 )
{
struct V_3 * V_2 ;
if ( V_61 -> V_100 == & V_101 ) {
struct V_66 * V_5 = V_61 -> V_97 ;
if ( V_5 -> V_32 == V_31 ) {
F_18 ( V_5 ) ;
return V_5 ;
}
}
V_2 = F_56 ( V_31 , V_61 ) ;
if ( F_43 ( V_2 ) )
return F_99 ( V_2 ) ;
return & V_2 -> V_5 ;
}
