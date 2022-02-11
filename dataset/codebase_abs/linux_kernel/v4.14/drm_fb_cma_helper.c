static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void F_3 ( struct V_5 * V_6 )
{
F_4 ( V_6 ) ;
}
int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
return F_6 ( V_6 , V_8 , V_9 ) ;
}
struct V_5 * F_7 ( struct V_10 * V_11 ,
struct V_7 * V_8 , const struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
return F_8 ( V_11 , V_8 , V_13 , V_15 ) ;
}
struct V_5 * F_9 ( struct V_10 * V_11 ,
struct V_7 * V_8 , const struct V_12 * V_13 )
{
return F_10 ( V_11 , V_8 , V_13 ) ;
}
struct V_16 * F_11 ( struct V_5 * V_6 ,
unsigned int V_17 )
{
struct V_18 * V_19 ;
V_19 = F_12 ( V_6 , V_17 ) ;
if ( ! V_19 )
return NULL ;
return F_13 ( V_19 ) ;
}
T_1 F_14 ( struct V_5 * V_6 ,
struct V_20 * V_21 ,
unsigned int V_17 )
{
struct V_16 * V_22 ;
T_1 V_23 ;
V_22 = F_11 ( V_6 , V_17 ) ;
if ( ! V_22 )
return 0 ;
V_23 = V_22 -> V_23 + V_6 -> V_24 [ V_17 ] ;
V_23 += V_6 -> V_25 -> V_26 [ V_17 ] * ( V_21 -> V_27 >> 16 ) ;
V_23 += V_6 -> V_28 [ V_17 ] * ( V_21 -> V_29 >> 16 ) ;
return V_23 ;
}
int F_15 ( struct V_30 * V_17 ,
struct V_20 * V_21 )
{
return F_16 ( V_17 , V_21 ) ;
}
static void F_17 ( struct V_5 * V_6 , struct V_31 * V_32 )
{
int V_33 ;
F_18 ( V_32 , L_1 , V_6 -> V_34 , V_6 -> V_35 ,
( char * ) & V_6 -> V_25 -> V_25 ) ;
for ( V_33 = 0 ; V_33 < V_6 -> V_25 -> V_36 ; V_33 ++ ) {
F_18 ( V_32 , L_2 ,
V_33 , V_6 -> V_24 [ V_33 ] , V_6 -> V_28 [ V_33 ] ) ;
F_19 ( F_11 ( V_6 , V_33 ) , V_32 ) ;
}
}
int F_20 ( struct V_31 * V_32 , void * V_37 )
{
struct V_38 * V_39 = (struct V_38 * ) V_32 -> V_40 ;
struct V_10 * V_11 = V_39 -> V_41 -> V_11 ;
struct V_5 * V_6 ;
F_21 ( & V_11 -> V_42 . V_43 ) ;
F_22 (fb, dev)
F_17 ( V_6 , V_32 ) ;
F_23 ( & V_11 -> V_42 . V_43 ) ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
return F_25 ( V_45 -> V_48 , V_47 , V_45 -> V_49 ,
V_45 -> V_50 . V_51 , V_45 -> V_50 . V_52 ) ;
}
static int F_26 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
F_27 ( V_45 , V_47 ) ;
V_47 -> V_53 = F_28 ( V_47 -> V_53 ) ;
return 0 ;
}
static int F_29 ( struct V_44 * V_54 ,
struct V_16 * V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_57 = F_30 ( sizeof( * V_57 ) , V_60 ) ;
V_59 = F_30 ( sizeof( * V_59 ) , V_60 ) ;
if ( ! V_57 || ! V_59 ) {
F_31 ( V_57 ) ;
F_31 ( V_59 ) ;
return - V_61 ;
}
V_54 -> V_62 = V_55 -> V_63 ;
V_54 -> V_50 . V_51 = F_32 ( F_33 ( V_54 -> V_62 ) ) ;
* V_59 = * V_54 -> V_59 ;
V_54 -> V_59 = V_59 ;
V_57 -> V_64 = F_34 ( V_65 ) ;
V_57 -> V_66 = V_67 ;
V_54 -> V_57 = V_57 ;
F_35 ( V_54 ) ;
V_54 -> V_59 -> V_68 = F_26 ;
return 0 ;
}
static void F_36 ( struct V_44 * V_54 )
{
if ( ! V_54 -> V_57 )
return;
F_37 ( V_54 ) ;
F_31 ( V_54 -> V_57 ) ;
F_31 ( V_54 -> V_59 ) ;
}
static int
F_38 ( struct V_2 * V_3 ,
struct V_69 * V_70 )
{
struct V_1 * V_71 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_3 -> V_11 ;
struct V_16 * V_22 ;
struct V_5 * V_6 ;
unsigned int V_72 ;
unsigned long V_73 ;
struct V_44 * V_54 ;
T_2 V_74 ;
int V_75 ;
F_39 ( L_3 ,
V_70 -> V_76 , V_70 -> V_77 ,
V_70 -> V_78 ) ;
V_72 = F_40 ( V_70 -> V_78 , 8 ) ;
V_74 = V_70 -> V_76 * V_70 -> V_77 * V_72 ;
V_22 = F_41 ( V_11 , V_74 ) ;
if ( F_42 ( V_22 ) )
return - V_61 ;
V_54 = F_43 ( V_3 ) ;
if ( F_42 ( V_54 ) ) {
V_75 = F_44 ( V_54 ) ;
goto V_79;
}
V_6 = F_45 ( V_11 , V_70 , 0 , & V_22 -> V_80 ,
V_71 -> V_81 ) ;
if ( F_42 ( V_6 ) ) {
F_46 ( V_11 -> V_11 , L_4 ) ;
V_75 = F_44 ( V_6 ) ;
goto V_82;
}
V_3 -> V_6 = V_6 ;
V_54 -> V_83 = V_3 ;
V_54 -> V_84 = V_85 ;
V_54 -> V_59 = & V_86 ;
F_47 ( V_54 , V_6 -> V_28 [ 0 ] , V_6 -> V_25 -> V_87 ) ;
F_48 ( V_54 , V_3 , V_70 -> V_88 , V_70 -> V_89 ) ;
V_73 = V_54 -> V_90 . V_91 * V_72 ;
V_73 += V_54 -> V_90 . V_92 * V_6 -> V_28 [ 0 ] ;
V_11 -> V_42 . V_93 = ( V_94 ) V_22 -> V_23 ;
V_54 -> V_49 = V_22 -> V_63 + V_73 ;
V_54 -> V_50 . V_51 = ( unsigned long ) ( V_22 -> V_23 + V_73 ) ;
V_54 -> V_95 = V_74 ;
V_54 -> V_50 . V_52 = V_74 ;
if ( V_71 -> V_81 -> V_96 ) {
V_75 = F_29 ( V_54 , V_22 ) ;
if ( V_75 )
goto V_97;
}
return 0 ;
V_97:
F_49 ( V_6 ) ;
V_82:
F_50 ( V_3 ) ;
V_79:
F_51 ( & V_22 -> V_80 ) ;
return V_75 ;
}
struct V_1 * F_52 ( struct V_10 * V_11 ,
unsigned int V_98 , unsigned int V_99 ,
const struct V_14 * V_15 )
{
struct V_1 * V_71 ;
struct V_2 * V_3 ;
int V_75 ;
V_71 = F_30 ( sizeof( * V_71 ) , V_60 ) ;
if ( ! V_71 ) {
F_46 ( V_11 -> V_11 , L_5 ) ;
return F_53 ( - V_61 ) ;
}
V_71 -> V_81 = V_15 ;
V_3 = & V_71 -> V_4 ;
F_54 ( V_11 , V_3 , & V_100 ) ;
V_75 = F_55 ( V_11 , V_3 , V_99 ) ;
if ( V_75 < 0 ) {
F_46 ( V_11 -> V_11 , L_6 ) ;
goto V_101;
}
V_75 = F_56 ( V_3 ) ;
if ( V_75 < 0 ) {
F_46 ( V_11 -> V_11 , L_7 ) ;
goto V_102;
}
V_75 = F_57 ( V_3 , V_98 ) ;
if ( V_75 < 0 ) {
F_46 ( V_11 -> V_11 , L_8 ) ;
goto V_102;
}
return V_71 ;
V_102:
F_50 ( V_3 ) ;
V_101:
F_31 ( V_71 ) ;
return F_53 ( V_75 ) ;
}
struct V_1 * F_58 ( struct V_10 * V_11 ,
unsigned int V_98 , unsigned int V_99 )
{
return F_52 ( V_11 , V_98 ,
V_99 ,
& V_103 ) ;
}
void F_59 ( struct V_1 * V_71 )
{
F_60 ( & V_71 -> V_4 ) ;
if ( V_71 -> V_4 . V_104 )
F_36 ( V_71 -> V_4 . V_104 ) ;
if ( V_71 -> V_4 . V_6 )
F_49 ( V_71 -> V_4 . V_6 ) ;
F_50 ( & V_71 -> V_4 ) ;
F_31 ( V_71 ) ;
}
void F_61 ( struct V_1 * V_71 )
{
if ( V_71 )
F_62 ( & V_71 -> V_4 ) ;
}
void F_63 ( struct V_1 * V_71 )
{
if ( V_71 )
F_64 ( & V_71 -> V_4 ) ;
}
void F_65 ( struct V_1 * V_71 , bool V_21 )
{
if ( V_71 )
F_66 ( & V_71 -> V_4 , V_21 ) ;
}
void F_67 ( struct V_1 * V_71 ,
bool V_21 )
{
if ( V_71 )
F_68 ( & V_71 -> V_4 ,
V_21 ) ;
}
