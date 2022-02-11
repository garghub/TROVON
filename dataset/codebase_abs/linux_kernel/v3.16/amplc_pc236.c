static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_3 && V_2 -> V_4 == V_5 ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return V_6 && V_2 -> V_4 == V_7 ;
}
static const struct V_1 * F_3 ( struct V_8 * V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
if ( F_2 ( & V_10 [ V_9 ] ) &&
V_8 -> V_11 == V_10 [ V_9 ] . V_12 )
return & V_10 [ V_9 ] ;
return NULL ;
}
static struct V_8 * F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_8 = NULL ;
int V_18 = V_16 -> V_19 [ 0 ] ;
int V_20 = V_16 -> V_19 [ 1 ] ;
F_7 (pci_dev) {
if ( V_18 || V_20 ) {
if ( V_18 != V_8 -> V_18 -> V_21 ||
V_20 != F_8 ( V_8 -> V_22 ) )
continue;
}
if ( V_8 -> V_23 != V_24 )
continue;
if ( V_17 -> V_25 == V_26 ) {
const struct V_1 * V_27 ;
V_27 = F_3 ( V_8 ) ;
if ( V_27 == NULL )
continue;
V_14 -> V_28 = V_27 ;
} else {
if ( V_8 -> V_11 != V_17 -> V_12 )
continue;
}
return V_8 ;
}
F_9 ( V_14 -> V_29 ,
L_1 ,
V_18 , V_20 ) ;
return NULL ;
}
static void F_10 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_30 * V_31 = V_14 -> V_32 ;
unsigned long V_33 ;
F_11 ( & V_14 -> V_34 , V_33 ) ;
V_31 -> V_35 = 0 ;
if ( F_2 ( V_17 ) )
F_12 ( V_36 , V_31 -> V_37 + V_38 ) ;
F_13 ( & V_14 -> V_34 , V_33 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_30 * V_31 = V_14 -> V_32 ;
unsigned long V_33 ;
F_11 ( & V_14 -> V_34 , V_33 ) ;
V_31 -> V_35 = 1 ;
if ( F_2 ( V_17 ) )
F_12 ( V_39 , V_31 -> V_37 + V_38 ) ;
F_13 ( & V_14 -> V_34 , V_33 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_30 * V_31 = V_14 -> V_32 ;
int V_40 = 0 ;
unsigned long V_33 ;
unsigned int V_41 ;
F_11 ( & V_14 -> V_34 , V_33 ) ;
if ( V_31 -> V_35 ) {
V_40 = 1 ;
if ( F_2 ( V_17 ) ) {
V_41 = F_16 ( V_31 -> V_37 + V_38 ) ;
if ( ! ( V_41 & V_42 ) ) {
V_40 = 0 ;
} else {
F_12 ( V_39 ,
V_31 -> V_37 + V_38 ) ;
}
}
}
F_13 ( & V_14 -> V_34 , V_33 ) ;
return V_40 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
unsigned int * V_47 )
{
V_47 [ 1 ] = 0 ;
return V_46 -> V_48 ;
}
static int F_18 ( struct V_13 * V_14 ,
struct V_43 * V_44 ,
struct V_49 * V_50 )
{
int V_51 = 0 ;
V_51 |= F_19 ( & V_50 -> V_52 , V_53 ) ;
V_51 |= F_19 ( & V_50 -> V_54 , V_55 ) ;
V_51 |= F_19 ( & V_50 -> V_56 , V_57 ) ;
V_51 |= F_19 ( & V_50 -> V_58 , V_59 ) ;
V_51 |= F_19 ( & V_50 -> V_60 , V_61 ) ;
if ( V_51 )
return 1 ;
if ( V_51 )
return 2 ;
V_51 |= F_20 ( & V_50 -> V_62 , 0 ) ;
V_51 |= F_20 ( & V_50 -> V_63 , 0 ) ;
V_51 |= F_20 ( & V_50 -> V_64 , 0 ) ;
V_51 |= F_20 ( & V_50 -> V_65 , V_50 -> V_66 ) ;
V_51 |= F_20 ( & V_50 -> V_67 , 0 ) ;
if ( V_51 )
return 3 ;
if ( V_51 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 , struct V_43 * V_44 )
{
F_14 ( V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 ,
struct V_43 * V_44 )
{
F_10 ( V_14 ) ;
return 0 ;
}
static T_1 F_23 ( int V_68 , void * V_69 )
{
struct V_13 * V_14 = V_69 ;
struct V_43 * V_44 = V_14 -> V_70 ;
int V_71 ;
V_71 = F_15 ( V_14 ) ;
if ( V_14 -> V_72 && V_71 ) {
F_24 ( V_44 , 0 ) ;
V_44 -> V_73 -> V_74 |= V_75 | V_76 ;
F_25 ( V_14 , V_44 ) ;
}
return F_26 ( V_71 ) ;
}
static int F_27 ( struct V_13 * V_14 , unsigned long V_77 ,
unsigned int V_68 , unsigned long V_78 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_43 * V_44 ;
int V_79 ;
V_14 -> V_80 = V_17 -> V_81 ;
V_14 -> V_77 = V_77 ;
V_79 = F_28 ( V_14 , 2 ) ;
if ( V_79 )
return V_79 ;
V_44 = & V_14 -> V_82 [ 0 ] ;
V_79 = F_29 ( V_14 , V_44 , NULL , V_77 ) ;
if ( V_79 )
return V_79 ;
V_44 = & V_14 -> V_82 [ 1 ] ;
V_14 -> V_70 = V_44 ;
V_44 -> type = V_83 ;
F_10 ( V_14 ) ;
if ( V_68 ) {
if ( F_30 ( V_68 , F_23 , V_78 ,
V_84 , V_14 ) >= 0 ) {
V_14 -> V_68 = V_68 ;
V_44 -> type = V_85 ;
V_44 -> V_86 = V_87 | V_88 ;
V_44 -> V_89 = 1 ;
V_44 -> V_90 = 1 ;
V_44 -> V_91 = & V_92 ;
V_44 -> V_93 = F_17 ;
V_44 -> V_94 = 1 ;
V_44 -> V_95 = F_18 ;
V_44 -> V_96 = F_21 ;
V_44 -> V_97 = F_22 ;
}
}
return 0 ;
}
static int F_31 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
struct V_30 * V_31 = V_14 -> V_32 ;
unsigned long V_77 ;
int V_79 ;
F_32 ( V_14 , & V_8 -> V_14 ) ;
V_79 = F_33 ( V_14 ) ;
if ( V_79 )
return V_79 ;
V_31 -> V_37 = F_34 ( V_8 , 1 ) ;
V_77 = F_34 ( V_8 , 2 ) ;
return F_27 ( V_14 , V_77 , V_8 -> V_68 , V_98 ) ;
}
static int F_35 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_30 * V_31 ;
int V_79 ;
V_31 = F_36 ( V_14 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_99 ;
if ( F_1 ( V_17 ) ) {
V_79 = F_37 ( V_14 , V_16 -> V_19 [ 0 ] , V_100 ) ;
if ( V_79 )
return V_79 ;
return F_27 ( V_14 , V_14 -> V_77 , V_16 -> V_19 [ 1 ] , 0 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_8 ;
V_8 = F_5 ( V_14 , V_16 ) ;
if ( ! V_8 )
return - V_101 ;
return F_31 ( V_14 , V_8 ) ;
} else {
F_9 ( V_14 -> V_29 , V_84
L_2 ) ;
return - V_102 ;
}
}
static int F_38 ( struct V_13 * V_14 ,
unsigned long V_103 )
{
struct V_8 * V_8 = F_39 ( V_14 ) ;
struct V_30 * V_31 ;
if ( ! V_6 )
return - V_102 ;
F_40 ( V_14 -> V_29 , V_84 L_3 ,
F_41 ( V_8 ) ) ;
V_31 = F_36 ( V_14 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_99 ;
V_14 -> V_28 = F_3 ( V_8 ) ;
if ( V_14 -> V_28 == NULL ) {
F_9 ( V_14 -> V_29 , L_4 ) ;
return - V_102 ;
}
F_42 ( V_8 ) ;
return F_31 ( V_14 , V_8 ) ;
}
static void F_43 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
if ( ! V_17 )
return;
if ( V_14 -> V_77 )
F_10 ( V_14 ) ;
if ( F_1 ( V_17 ) ) {
F_44 ( V_14 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_104 = F_39 ( V_14 ) ;
if ( V_14 -> V_68 )
F_45 ( V_14 -> V_68 , V_14 ) ;
F_46 ( V_14 ) ;
if ( V_104 )
F_47 ( V_104 ) ;
}
}
static int F_48 ( struct V_8 * V_14 ,
const struct V_105 * V_106 )
{
return F_49 ( V_14 , & V_107 ,
V_106 -> V_108 ) ;
}
