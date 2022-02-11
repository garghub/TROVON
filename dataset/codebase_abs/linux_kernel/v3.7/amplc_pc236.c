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
static int F_10 ( struct V_13 * V_14 , unsigned long V_30 ,
unsigned long V_31 )
{
if ( ! V_30 || ! F_11 ( V_30 , V_31 , V_32 ) ) {
F_9 ( V_14 -> V_29 , L_2 ,
V_30 , V_31 ) ;
return - V_33 ;
}
return 0 ;
}
static void F_12 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_34 * V_35 = V_14 -> V_36 ;
unsigned long V_37 ;
F_13 ( & V_14 -> V_38 , V_37 ) ;
V_35 -> V_39 = 0 ;
if ( F_2 ( V_17 ) )
F_14 ( V_40 , V_35 -> V_41 + V_42 ) ;
F_15 ( & V_14 -> V_38 , V_37 ) ;
}
static void F_16 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_34 * V_35 = V_14 -> V_36 ;
unsigned long V_37 ;
F_13 ( & V_14 -> V_38 , V_37 ) ;
V_35 -> V_39 = 1 ;
if ( F_2 ( V_17 ) )
F_14 ( V_43 , V_35 -> V_41 + V_42 ) ;
F_15 ( & V_14 -> V_38 , V_37 ) ;
}
static int F_17 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_34 * V_35 = V_14 -> V_36 ;
int V_44 = 0 ;
unsigned long V_37 ;
F_13 ( & V_14 -> V_38 , V_37 ) ;
if ( V_35 -> V_39 ) {
V_44 = 1 ;
if ( F_2 ( V_17 ) ) {
if ( ( F_18 ( V_35 -> V_41 + V_42 )
& V_45 )
== V_46 ) {
V_44 = 0 ;
} else {
F_14 ( V_43 ,
V_35 -> V_41 + V_42 ) ;
}
}
}
F_15 ( & V_14 -> V_38 , V_37 ) ;
return V_44 ;
}
static int F_19 ( struct V_13 * V_14 ,
struct V_47 * V_48 , struct V_49 * V_50 ,
unsigned int * V_51 )
{
V_51 [ 1 ] = 0 ;
return V_50 -> V_52 ;
}
static int F_20 ( struct V_13 * V_14 ,
struct V_47 * V_48 ,
struct V_53 * V_54 )
{
int V_55 = 0 ;
V_55 |= F_21 ( & V_54 -> V_56 , V_57 ) ;
V_55 |= F_21 ( & V_54 -> V_58 , V_59 ) ;
V_55 |= F_21 ( & V_54 -> V_60 , V_61 ) ;
V_55 |= F_21 ( & V_54 -> V_62 , V_63 ) ;
V_55 |= F_21 ( & V_54 -> V_64 , V_65 ) ;
if ( V_55 )
return 1 ;
if ( V_55 )
return 2 ;
if ( V_54 -> V_66 != 0 ) {
V_54 -> V_66 = 0 ;
V_55 ++ ;
}
if ( V_54 -> V_67 != 0 ) {
V_54 -> V_67 = 0 ;
V_55 ++ ;
}
if ( V_54 -> V_68 != 0 ) {
V_54 -> V_68 = 0 ;
V_55 ++ ;
}
if ( V_54 -> V_69 != 1 ) {
V_54 -> V_69 = 1 ;
V_55 ++ ;
}
if ( V_54 -> V_70 != 0 ) {
V_54 -> V_70 = 0 ;
V_55 ++ ;
}
if ( V_55 )
return 3 ;
if ( V_55 )
return 4 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 , struct V_47 * V_48 )
{
F_16 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_47 * V_48 )
{
F_12 ( V_14 ) ;
return 0 ;
}
static T_1 F_24 ( int V_71 , void * V_72 )
{
struct V_13 * V_14 = V_72 ;
struct V_47 * V_48 = & V_14 -> V_73 [ 1 ] ;
int V_74 ;
V_74 = F_17 ( V_14 ) ;
if ( V_14 -> V_75 && V_74 ) {
F_25 ( V_48 -> V_76 , 0 ) ;
V_48 -> V_76 -> V_77 |= V_78 | V_79 ;
F_26 ( V_14 , V_48 ) ;
}
return F_27 ( V_74 ) ;
}
static void F_28 ( struct V_13 * V_14 , unsigned int V_71 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_8 * V_80 = F_29 ( V_14 ) ;
char V_81 [ 60 ] ;
int V_82 ;
if ( F_1 ( V_17 ) )
V_82 = F_30 ( V_81 , sizeof( V_81 ) ,
L_3 , V_14 -> V_83 ) ;
else if ( F_2 ( V_17 ) )
V_82 = F_30 ( V_81 , sizeof( V_81 ) ,
L_4 , F_31 ( V_80 ) ) ;
else
V_82 = 0 ;
if ( V_71 )
V_82 += F_30 ( & V_81 [ V_82 ] , sizeof( V_81 ) - V_82 ,
L_5 , V_71 ,
( V_14 -> V_71 ? L_6 : L_7 ) ) ;
else
V_82 += F_30 ( & V_81 [ V_82 ] , sizeof( V_81 ) - V_82 ,
L_8 ) ;
F_32 ( V_14 -> V_29 , L_9 ,
V_14 -> V_84 , V_81 ) ;
}
static int F_33 ( struct V_13 * V_14 , unsigned long V_83 ,
unsigned int V_71 , unsigned long V_85 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
struct V_47 * V_48 ;
int V_86 ;
V_14 -> V_84 = V_17 -> V_87 ;
V_14 -> V_83 = V_83 ;
V_86 = F_34 ( V_14 , 2 ) ;
if ( V_86 )
return V_86 ;
V_48 = & V_14 -> V_73 [ 0 ] ;
V_86 = F_35 ( V_14 , V_48 , NULL , V_83 ) ;
if ( V_86 < 0 ) {
F_9 ( V_14 -> V_29 , L_10 ) ;
return V_86 ;
}
V_48 = & V_14 -> V_73 [ 1 ] ;
V_14 -> V_88 = V_48 ;
V_48 -> type = V_89 ;
F_12 ( V_14 ) ;
if ( V_71 ) {
if ( F_36 ( V_71 , F_24 , V_85 ,
V_32 , V_14 ) >= 0 ) {
V_14 -> V_71 = V_71 ;
V_48 -> type = V_90 ;
V_48 -> V_91 = V_92 | V_93 ;
V_48 -> V_94 = 1 ;
V_48 -> V_95 = 1 ;
V_48 -> V_96 = & V_97 ;
V_48 -> V_98 = F_19 ;
V_48 -> V_99 = F_20 ;
V_48 -> V_100 = F_22 ;
V_48 -> V_101 = F_23 ;
}
}
F_28 ( V_14 , V_71 ) ;
return 1 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
struct V_34 * V_35 = V_14 -> V_36 ;
unsigned long V_83 ;
int V_86 ;
F_38 ( V_14 , & V_8 -> V_14 ) ;
V_86 = F_39 ( V_8 , V_32 ) ;
if ( V_86 < 0 ) {
F_9 ( V_14 -> V_29 ,
L_11 ) ;
return V_86 ;
}
V_35 -> V_41 = F_40 ( V_8 , 1 ) ;
V_83 = F_40 ( V_8 , 2 ) ;
return F_33 ( V_14 , V_83 , V_8 -> V_71 , V_102 ) ;
}
static int F_41 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
int V_86 ;
F_32 ( V_14 -> V_29 , V_32 L_12 ) ;
V_86 = F_42 ( V_14 , sizeof( struct V_34 ) ) ;
if ( V_86 < 0 ) {
F_9 ( V_14 -> V_29 , L_10 ) ;
return V_86 ;
}
if ( F_1 ( V_17 ) ) {
unsigned long V_83 = V_16 -> V_19 [ 0 ] ;
unsigned int V_71 = V_16 -> V_19 [ 1 ] ;
V_86 = F_10 ( V_14 , V_83 , V_103 ) ;
if ( V_86 < 0 )
return V_86 ;
return F_33 ( V_14 , V_83 , V_71 , 0 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_8 ;
V_8 = F_5 ( V_14 , V_16 ) ;
if ( ! V_8 )
return - V_33 ;
return F_37 ( V_14 , V_8 ) ;
} else {
F_9 ( V_14 -> V_29 , V_32
L_13 ) ;
return - V_104 ;
}
}
static int T_2 F_43 ( struct V_13 * V_14 ,
struct V_8 * V_8 )
{
int V_86 ;
if ( ! V_6 )
return - V_104 ;
F_32 ( V_14 -> V_29 , V_32 L_14 ,
F_31 ( V_8 ) ) ;
V_86 = F_42 ( V_14 , sizeof( struct V_34 ) ) ;
if ( V_86 < 0 ) {
F_9 ( V_14 -> V_29 , L_10 ) ;
return V_86 ;
}
V_14 -> V_28 = F_3 ( V_8 ) ;
if ( V_14 -> V_28 == NULL ) {
F_9 ( V_14 -> V_29 , L_15 ) ;
return - V_104 ;
}
F_44 ( V_8 ) ;
return F_37 ( V_14 , V_8 ) ;
}
static void F_45 ( struct V_13 * V_14 )
{
const struct V_1 * V_17 = F_6 ( V_14 ) ;
if ( ! V_17 )
return;
if ( V_14 -> V_83 )
F_12 ( V_14 ) ;
if ( V_14 -> V_71 )
F_46 ( V_14 -> V_71 , V_14 ) ;
if ( V_14 -> V_73 )
F_47 ( V_14 , & V_14 -> V_73 [ 0 ] ) ;
if ( F_1 ( V_17 ) ) {
if ( V_14 -> V_83 )
F_48 ( V_14 -> V_83 , V_103 ) ;
} else if ( F_2 ( V_17 ) ) {
struct V_8 * V_80 = F_29 ( V_14 ) ;
if ( V_80 ) {
if ( V_14 -> V_83 )
F_49 ( V_80 ) ;
F_50 ( V_80 ) ;
}
}
}
static int T_2 F_51 ( struct V_8 * V_14 ,
const struct V_105 * V_106 )
{
return F_52 ( V_14 , & V_107 ) ;
}
static void T_3 F_53 ( struct V_8 * V_14 )
{
F_54 ( V_14 ) ;
}
