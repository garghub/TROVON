static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * * V_8 , * V_9 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
F_3 ( V_3 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_9 = NULL ;
V_8 = & V_2 -> V_12 . V_7 ;
while ( * V_8 ) {
struct V_5 * V_13 ;
V_9 = * V_8 ;
V_13 = F_4 ( V_9 , struct V_5 , V_14 ) ;
if ( V_3 > V_13 -> V_3 )
V_8 = & V_9 -> V_15 ;
else
V_8 = & V_9 -> V_16 ;
}
F_5 ( & V_6 -> V_14 , V_9 , V_8 ) ;
F_6 ( & V_6 -> V_14 , & V_2 -> V_12 ) ;
V_9 = NULL ;
V_8 = & V_2 -> V_17 . V_7 ;
while ( * V_8 ) {
struct V_5 * V_13 ;
V_9 = * V_8 ;
V_13 = F_4 ( V_9 , struct V_5 , V_18 ) ;
if ( V_4 > V_13 -> V_4 )
V_8 = & V_9 -> V_15 ;
else
V_8 = & V_9 -> V_16 ;
}
F_5 ( & V_6 -> V_18 , V_9 , V_8 ) ;
F_6 ( & V_6 -> V_18 , & V_2 -> V_17 ) ;
return 0 ;
}
static struct V_3 * F_7 ( struct V_1 * V_2 ,
T_1 V_4 )
{
struct V_7 * V_9 ;
V_9 = V_2 -> V_17 . V_7 ;
while ( V_9 ) {
struct V_5 * V_6 ;
V_6 = F_4 ( V_9 , struct V_5 , V_18 ) ;
if ( V_6 -> V_4 == V_4 )
return V_6 -> V_3 ;
else if ( V_6 -> V_4 < V_4 )
V_9 = V_9 -> V_15 ;
else
V_9 = V_9 -> V_16 ;
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
T_1 * V_4 )
{
struct V_7 * V_9 ;
V_9 = V_2 -> V_12 . V_7 ;
while ( V_9 ) {
struct V_5 * V_6 ;
V_6 = F_4 ( V_9 , struct V_5 , V_14 ) ;
if ( V_6 -> V_3 == V_3 ) {
* V_4 = V_6 -> V_4 ;
return 0 ;
} else if ( V_6 -> V_3 < V_3 ) {
V_9 = V_9 -> V_15 ;
} else {
V_9 = V_9 -> V_16 ;
}
}
return - V_19 ;
}
static int F_9 ( struct V_3 * V_3 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
V_25 = F_10 ( sizeof( * V_25 ) , V_10 ) ;
if ( ! V_25 )
return - V_11 ;
V_25 -> V_31 = V_32 ;
V_23 -> V_28 = V_25 ;
if ( ! V_30 -> V_33 -> V_34 )
return 0 ;
return V_30 -> V_33 -> V_34 ( V_27 ) ;
}
static void F_11 ( struct V_3 * V_3 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_28 ;
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_35 * V_36 ;
if ( V_30 -> V_33 -> V_37 )
V_30 -> V_33 -> V_37 ( V_27 ) ;
if ( ! V_25 )
return;
V_36 = V_25 -> V_36 ;
if ( V_36 ) {
if ( V_25 -> V_31 != V_32 )
F_12 ( V_23 -> V_30 , V_36 -> V_38 , V_36 -> V_39 ,
V_25 -> V_31 ) ;
F_13 ( V_36 ) ;
}
F_14 ( V_36 ) ;
F_14 ( V_25 ) ;
V_23 -> V_28 = NULL ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_7 * V_9 ;
V_9 = V_2 -> V_12 . V_7 ;
while ( V_9 ) {
struct V_5 * V_6 ;
V_6 = F_4 ( V_9 , struct V_5 , V_14 ) ;
if ( V_6 -> V_3 == V_3 ) {
F_16 ( & V_6 -> V_18 , & V_2 -> V_17 ) ;
F_16 ( & V_6 -> V_14 , & V_2 -> V_12 ) ;
F_17 ( V_3 ) ;
F_14 ( V_6 ) ;
return;
} else if ( V_6 -> V_3 < V_3 ) {
V_9 = V_9 -> V_15 ;
} else {
V_9 = V_9 -> V_16 ;
}
}
}
static struct V_35 * F_18 ( struct V_22 * V_23 ,
enum V_40 V_31 )
{
struct V_24 * V_25 = V_23 -> V_28 ;
struct V_26 * V_27 = V_23 -> V_41 -> V_28 ;
struct V_35 * V_36 ;
if ( F_19 ( V_31 == V_32 || ! V_25 ) )
return F_20 ( - V_42 ) ;
if ( V_25 -> V_31 == V_31 )
return V_25 -> V_36 ;
if ( F_19 ( V_25 -> V_31 != V_32 ) )
return F_20 ( - V_43 ) ;
V_36 = V_27 -> V_30 -> V_33 -> V_44 ( V_27 ) ;
if ( ! F_21 ( V_36 ) ) {
if ( ! F_22 ( V_23 -> V_30 , V_36 -> V_38 , V_36 -> V_39 , V_31 ) ) {
F_13 ( V_36 ) ;
F_14 ( V_36 ) ;
V_36 = F_20 ( - V_11 ) ;
} else {
V_25 -> V_36 = V_36 ;
V_25 -> V_31 = V_31 ;
}
}
return V_36 ;
}
static void F_23 ( struct V_22 * V_23 ,
struct V_35 * V_36 ,
enum V_40 V_31 )
{
}
struct V_3 * F_24 ( struct V_29 * V_30 ,
struct V_45 * V_46 )
{
struct V_3 * V_3 ;
V_3 = F_25 ( V_46 ) ;
if ( ! F_21 ( V_3 ) )
F_26 ( V_30 ) ;
return V_3 ;
}
void F_27 ( struct V_3 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
F_28 ( V_27 ) ;
F_29 ( V_30 ) ;
}
static void * F_30 ( struct V_3 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
return V_30 -> V_33 -> V_47 ( V_27 ) ;
}
static void F_31 ( struct V_3 * V_3 , void * V_48 )
{
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
V_30 -> V_33 -> V_49 ( V_27 , V_48 ) ;
}
static void * F_32 ( struct V_3 * V_3 ,
unsigned long V_50 )
{
return NULL ;
}
static void F_33 ( struct V_3 * V_3 ,
unsigned long V_50 , void * V_51 )
{
}
static void * F_34 ( struct V_3 * V_3 ,
unsigned long V_50 )
{
return NULL ;
}
static void F_35 ( struct V_3 * V_3 ,
unsigned long V_50 , void * V_51 )
{
}
static int F_36 ( struct V_3 * V_3 ,
struct V_52 * V_53 )
{
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
if ( ! V_30 -> V_33 -> V_54 )
return - V_55 ;
return V_30 -> V_33 -> V_54 ( V_27 , V_53 ) ;
}
struct V_3 * F_37 ( struct V_29 * V_30 ,
struct V_26 * V_27 ,
int V_56 )
{
struct V_45 V_46 = {
. V_57 = V_58 ,
. V_59 = V_30 -> V_33 -> V_60 -> V_59 ,
. V_61 = & V_62 ,
. V_63 = V_27 -> V_63 ,
. V_56 = V_56 ,
. V_28 = V_27 ,
} ;
if ( V_30 -> V_33 -> V_64 )
V_46 . V_65 = V_30 -> V_33 -> V_64 ( V_27 ) ;
return F_24 ( V_30 , & V_46 ) ;
}
static struct V_3 * F_38 ( struct V_29 * V_30 ,
struct V_26 * V_27 ,
T_1 V_56 )
{
struct V_3 * V_41 ;
if ( V_27 -> V_66 == 0 ) {
V_41 = F_20 ( - V_19 ) ;
return V_41 ;
}
V_41 = V_30 -> V_33 -> V_67 ( V_30 , V_27 , V_56 ) ;
if ( F_21 ( V_41 ) ) {
return V_41 ;
}
V_27 -> V_3 = V_41 ;
F_3 ( V_27 -> V_3 ) ;
F_39 ( V_27 ) ;
return V_41 ;
}
int F_40 ( struct V_29 * V_30 ,
struct V_68 * V_69 , T_1 V_4 ,
T_1 V_56 ,
int * V_70 )
{
struct V_26 * V_27 ;
int V_71 = 0 ;
struct V_3 * V_41 ;
F_41 ( & V_69 -> V_72 . V_73 ) ;
V_27 = F_42 ( V_69 , V_4 ) ;
if ( ! V_27 ) {
V_71 = - V_19 ;
goto V_74;
}
V_41 = F_7 ( & V_69 -> V_72 , V_4 ) ;
if ( V_41 ) {
F_3 ( V_41 ) ;
goto V_75;
}
F_41 ( & V_30 -> V_76 ) ;
if ( V_27 -> V_77 ) {
V_41 = V_27 -> V_77 -> V_41 ;
F_3 ( V_41 ) ;
goto V_78;
}
if ( V_27 -> V_3 ) {
F_3 ( V_27 -> V_3 ) ;
V_41 = V_27 -> V_3 ;
goto V_78;
}
V_41 = F_38 ( V_30 , V_27 , V_56 ) ;
if ( F_21 ( V_41 ) ) {
V_71 = F_43 ( V_41 ) ;
F_44 ( & V_30 -> V_76 ) ;
goto V_79;
}
V_78:
V_71 = F_1 ( & V_69 -> V_72 ,
V_41 , V_4 ) ;
F_44 ( & V_30 -> V_76 ) ;
if ( V_71 )
goto V_80;
V_75:
V_71 = F_45 ( V_41 , V_56 ) ;
if ( V_71 < 0 ) {
goto V_80;
} else {
* V_70 = V_71 ;
V_71 = 0 ;
}
goto V_79;
V_80:
F_17 ( V_41 ) ;
V_79:
F_28 ( V_27 ) ;
V_74:
F_44 ( & V_69 -> V_72 . V_73 ) ;
return V_71 ;
}
struct V_26 * F_46 ( struct V_29 * V_30 ,
struct V_3 * V_3 )
{
struct V_22 * V_23 ;
struct V_35 * V_36 ;
struct V_26 * V_27 ;
int V_71 ;
if ( V_3 -> V_61 == & V_62 ) {
V_27 = V_3 -> V_28 ;
if ( V_27 -> V_30 == V_30 ) {
F_39 ( V_27 ) ;
return V_27 ;
}
}
if ( ! V_30 -> V_33 -> V_81 )
return F_20 ( - V_42 ) ;
V_23 = F_47 ( V_3 , V_30 -> V_30 ) ;
if ( F_21 ( V_23 ) )
return F_48 ( V_23 ) ;
F_3 ( V_3 ) ;
V_36 = F_49 ( V_23 , V_82 ) ;
if ( F_21 ( V_36 ) ) {
V_71 = F_43 ( V_36 ) ;
goto V_83;
}
V_27 = V_30 -> V_33 -> V_81 ( V_30 , V_23 , V_36 ) ;
if ( F_21 ( V_27 ) ) {
V_71 = F_43 ( V_27 ) ;
goto V_84;
}
V_27 -> V_77 = V_23 ;
return V_27 ;
V_84:
F_50 ( V_23 , V_36 , V_82 ) ;
V_83:
F_51 ( V_3 , V_23 ) ;
F_17 ( V_3 ) ;
return F_20 ( V_71 ) ;
}
int F_52 ( struct V_29 * V_30 ,
struct V_68 * V_69 , int V_70 ,
T_1 * V_4 )
{
struct V_3 * V_3 ;
struct V_26 * V_27 ;
int V_71 ;
V_3 = F_53 ( V_70 ) ;
if ( F_21 ( V_3 ) )
return F_43 ( V_3 ) ;
F_41 ( & V_69 -> V_72 . V_73 ) ;
V_71 = F_8 ( & V_69 -> V_72 ,
V_3 , V_4 ) ;
if ( V_71 == 0 )
goto V_85;
F_41 ( & V_30 -> V_76 ) ;
V_27 = V_30 -> V_33 -> V_86 ( V_30 , V_3 ) ;
if ( F_21 ( V_27 ) ) {
V_71 = F_43 ( V_27 ) ;
goto V_74;
}
if ( V_27 -> V_3 ) {
F_19 ( V_27 -> V_3 != V_3 ) ;
} else {
V_27 -> V_3 = V_3 ;
F_3 ( V_3 ) ;
}
V_71 = F_54 ( V_69 , V_27 , V_4 ) ;
F_28 ( V_27 ) ;
if ( V_71 )
goto V_85;
V_71 = F_1 ( & V_69 -> V_72 ,
V_3 , * V_4 ) ;
F_44 ( & V_69 -> V_72 . V_73 ) ;
if ( V_71 )
goto V_87;
F_17 ( V_3 ) ;
return 0 ;
V_87:
F_55 ( V_69 , * V_4 ) ;
F_17 ( V_3 ) ;
return V_71 ;
V_74:
F_44 ( & V_30 -> V_76 ) ;
V_85:
F_44 ( & V_69 -> V_72 . V_73 ) ;
F_17 ( V_3 ) ;
return V_71 ;
}
int F_56 ( struct V_29 * V_30 , void * V_88 ,
struct V_68 * V_69 )
{
struct V_89 * args = V_88 ;
if ( ! F_57 ( V_30 , V_90 ) )
return - V_42 ;
if ( ! V_30 -> V_33 -> V_91 )
return - V_55 ;
if ( args -> V_56 & ~ ( V_92 | V_93 ) )
return - V_42 ;
return V_30 -> V_33 -> V_91 ( V_30 , V_69 ,
args -> V_4 , args -> V_56 , & args -> V_94 ) ;
}
int F_58 ( struct V_29 * V_30 , void * V_88 ,
struct V_68 * V_69 )
{
struct V_89 * args = V_88 ;
if ( ! F_57 ( V_30 , V_90 ) )
return - V_42 ;
if ( ! V_30 -> V_33 -> V_95 )
return - V_55 ;
return V_30 -> V_33 -> V_95 ( V_30 , V_69 ,
args -> V_94 , & args -> V_4 ) ;
}
struct V_35 * F_59 ( struct V_96 * * V_97 , unsigned int V_98 )
{
struct V_35 * V_99 = NULL ;
int V_71 ;
V_99 = F_2 ( sizeof( struct V_35 ) , V_10 ) ;
if ( ! V_99 ) {
V_71 = - V_11 ;
goto V_79;
}
V_71 = F_60 ( V_99 , V_97 , V_98 , 0 ,
V_98 << V_100 , V_10 ) ;
if ( V_71 )
goto V_79;
return V_99 ;
V_79:
F_14 ( V_99 ) ;
return F_20 ( V_71 ) ;
}
int F_61 ( struct V_35 * V_36 , struct V_96 * * V_97 ,
T_2 * V_101 , int V_102 )
{
unsigned V_103 ;
struct V_104 * V_99 ;
struct V_96 * V_96 ;
T_3 V_105 ;
int V_106 ;
T_2 V_51 ;
V_106 = 0 ;
F_62 (sgt->sgl, sg, sgt->nents, count) {
V_105 = V_99 -> V_107 ;
V_96 = F_63 ( V_99 ) ;
V_51 = F_64 ( V_99 ) ;
while ( V_105 > 0 ) {
if ( F_19 ( V_106 >= V_102 ) )
return - 1 ;
V_97 [ V_106 ] = V_96 ;
if ( V_101 )
V_101 [ V_106 ] = V_51 ;
V_96 ++ ;
V_51 += V_108 ;
V_105 -= V_108 ;
V_106 ++ ;
}
}
return 0 ;
}
void F_65 ( struct V_26 * V_27 , struct V_35 * V_99 )
{
struct V_22 * V_23 ;
struct V_3 * V_3 ;
V_23 = V_27 -> V_77 ;
if ( V_99 )
F_50 ( V_23 , V_99 , V_82 ) ;
V_3 = V_23 -> V_41 ;
F_51 ( V_23 -> V_41 , V_23 ) ;
F_17 ( V_3 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_67 ( & V_2 -> V_73 ) ;
V_2 -> V_12 = V_109 ;
V_2 -> V_17 = V_109 ;
}
void F_68 ( struct V_1 * V_2 )
{
F_19 ( ! F_69 ( & V_2 -> V_12 ) ) ;
}
