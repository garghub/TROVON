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
V_51 |= F_20 ( & V_50 -> V_65 , 1 ) ;
V_51 |= F_20 ( & V_50 -> V_66 , 0 ) ;
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
static T_1 F_23 ( int V_67 , void * V_68 )
{
struct V_13 * V_14 = V_68 ;
struct V_43 * V_44 = & V_14 -> V_69 [ 1 ] ;
int V_70 ;
V_70 = F_15 ( V_14 ) ;
if ( V_14 -> V_71 && V_70 ) {
F_24 ( V_44 -> V_72 , 0 ) ;
V_44 -> V_72 -> V_73 |= V_74 | V_75 ;
F_25 ( V_14 , V_44 ) ;
}
return F_26 ( V_70 ) ;
}
static void F_27 ( struct V_13 * V_14 , unsigned int V_67 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_76 = F_28 ( V_14 ) ;
char V_77 [ 60 ] ;
int V_78 ;
if ( F_1 ( V_17 ) )
V_78 = F_29 ( V_77 , sizeof( V_77 ) ,
L_2 , V_14 -> V_79 ) ;
else if ( F_2 ( V_17 ) )
V_78 = F_29 ( V_77 , sizeof( V_77 ) ,
L_3 , F_30 ( V_76 ) ) ;
else
V_78 = 0 ;
if ( V_67 )
V_78 += F_29 ( & V_77 [ V_78 ] , sizeof( V_77 ) - V_78 ,
L_4 , V_67 ,
( V_14 -> V_67 ? L_5 : L_6 ) ) ;
else
V_78 += F_29 ( & V_77 [ V_78 ] , sizeof( V_77 ) - V_78 ,
L_7 ) ;
F_31 ( V_14 -> V_29 , L_8 ,
V_14 -> V_80 , V_77 ) ;
}
static int F_32 ( struct V_13 * V_14 , unsigned long V_79 ,
unsigned int V_67 , unsigned long V_81 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_43 * V_44 ;
int V_82 ;
V_14 -> V_80 = V_17 -> V_83 ;
V_14 -> V_79 = V_79 ;
V_82 = F_33 ( V_14 , 2 ) ;
if ( V_82 )
return V_82 ;
V_44 = & V_14 -> V_69 [ 0 ] ;
V_82 = F_34 ( V_14 , V_44 , NULL , V_79 ) ;
if ( V_82 < 0 ) {
F_9 ( V_14 -> V_29 , L_9 ) ;
return V_82 ;
}
V_44 = & V_14 -> V_69 [ 1 ] ;
V_14 -> V_84 = V_44 ;
V_44 -> type = V_85 ;
F_10 ( V_14 ) ;
if ( V_67 ) {
if ( F_35 ( V_67 , F_23 , V_81 ,
V_86 , V_14 ) >= 0 ) {
V_14 -> V_67 = V_67 ;
V_44 -> type = V_87 ;
V_44 -> V_88 = V_89 | V_90 ;
V_44 -> V_91 = 1 ;
V_44 -> V_92 = 1 ;
V_44 -> V_93 = & V_94 ;
V_44 -> V_95 = F_17 ;
V_44 -> V_96 = F_18 ;
V_44 -> V_97 = F_21 ;
V_44 -> V_98 = F_22 ;
}
}
F_27 ( V_14 , V_67 ) ;
return 1 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
struct V_30 * V_31 = V_14 -> V_32 ;
unsigned long V_79 ;
int V_82 ;
F_37 ( V_14 , & V_8 -> V_14 ) ;
V_82 = F_38 ( V_14 ) ;
if ( V_82 )
return V_82 ;
V_31 -> V_37 = F_39 ( V_8 , 1 ) ;
V_79 = F_39 ( V_8 , 2 ) ;
return F_32 ( V_14 , V_79 , V_8 -> V_67 , V_99 ) ;
}
static int F_40 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_30 * V_31 ;
int V_82 ;
V_31 = F_41 ( V_14 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_100 ;
if ( F_1 ( V_17 ) ) {
V_82 = F_42 ( V_14 , V_16 -> V_19 [ 0 ] , V_101 ) ;
if ( V_82 )
return V_82 ;
return F_32 ( V_14 , V_14 -> V_79 , V_16 -> V_19 [ 1 ] , 0 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_8 ;
V_8 = F_5 ( V_14 , V_16 ) ;
if ( ! V_8 )
return - V_102 ;
return F_36 ( V_14 , V_8 ) ;
} else {
F_9 ( V_14 -> V_29 , V_86
L_10 ) ;
return - V_103 ;
}
}
static int F_43 ( struct V_13 * V_14 ,
unsigned long V_104 )
{
struct V_8 * V_8 = F_28 ( V_14 ) ;
struct V_30 * V_31 ;
if ( ! V_6 )
return - V_103 ;
F_31 ( V_14 -> V_29 , V_86 L_11 ,
F_30 ( V_8 ) ) ;
V_31 = F_41 ( V_14 , sizeof( * V_31 ) ) ;
if ( ! V_31 )
return - V_100 ;
V_14 -> V_28 = F_3 ( V_8 ) ;
if ( V_14 -> V_28 == NULL ) {
F_9 ( V_14 -> V_29 , L_12 ) ;
return - V_103 ;
}
F_44 ( V_8 ) ;
return F_36 ( V_14 , V_8 ) ;
}
static void F_45 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
if ( ! V_17 )
return;
if ( V_14 -> V_79 )
F_10 ( V_14 ) ;
if ( F_1 ( V_17 ) ) {
F_46 ( V_14 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_76 = F_28 ( V_14 ) ;
if ( V_14 -> V_67 )
F_47 ( V_14 -> V_67 , V_14 ) ;
F_48 ( V_14 ) ;
if ( V_76 )
F_49 ( V_76 ) ;
}
}
static int F_50 ( struct V_8 * V_14 ,
const struct V_105 * V_106 )
{
return F_51 ( V_14 , & V_107 ,
V_106 -> V_108 ) ;
}
