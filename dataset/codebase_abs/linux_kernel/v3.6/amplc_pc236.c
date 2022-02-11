static const struct V_1 * F_1 ( struct V_2 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_5 == V_6 &&
V_2 -> V_7 == V_4 [ V_3 ] . V_8 )
return & V_4 [ V_3 ] ;
return NULL ;
}
static struct V_2 * F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_2 = NULL ;
int V_14 = V_12 -> V_15 [ 0 ] ;
int V_16 = V_12 -> V_15 [ 1 ] ;
F_5 (pci_dev) {
if ( V_14 || V_16 ) {
if ( V_14 != V_2 -> V_14 -> V_17 ||
V_16 != F_6 ( V_2 -> V_18 ) )
continue;
}
if ( V_2 -> V_19 != V_20 )
continue;
if ( V_13 -> V_21 == V_22 ) {
const struct V_1 * V_23 ;
V_23 = F_1 ( V_2 ) ;
if ( V_23 == NULL )
continue;
V_10 -> V_24 = V_23 ;
} else {
if ( V_2 -> V_7 != V_13 -> V_8 )
continue;
}
return V_2 ;
}
F_7 ( V_10 -> V_25 ,
L_1 ,
V_14 , V_16 ) ;
return NULL ;
}
static int F_8 ( struct V_9 * V_10 , unsigned long V_26 ,
unsigned long V_27 )
{
if ( ! V_26 || ! F_9 ( V_26 , V_27 , V_28 ) ) {
F_7 ( V_10 -> V_25 , L_2 ,
V_26 , V_27 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_32 ;
unsigned long V_33 ;
F_11 ( & V_10 -> V_34 , V_33 ) ;
V_31 -> V_35 = 0 ;
if ( F_12 ( V_36 ) && V_31 -> V_37 )
F_13 ( V_38 , V_31 -> V_37 + V_39 ) ;
F_14 ( & V_10 -> V_34 , V_33 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_32 ;
unsigned long V_33 ;
F_11 ( & V_10 -> V_34 , V_33 ) ;
V_31 -> V_35 = 1 ;
if ( F_12 ( V_36 ) && V_31 -> V_37 )
F_13 ( V_40 , V_31 -> V_37 + V_39 ) ;
F_14 ( & V_10 -> V_34 , V_33 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_32 ;
int V_41 = 0 ;
unsigned long V_33 ;
F_11 ( & V_10 -> V_34 , V_33 ) ;
if ( V_31 -> V_35 ) {
V_41 = 1 ;
if ( F_12 ( V_36 ) &&
V_31 -> V_37 ) {
if ( ( F_17 ( V_31 -> V_37 + V_39 )
& V_42 )
== V_43 ) {
V_41 = 0 ;
} else {
F_13 ( V_40 ,
V_31 -> V_37 + V_39 ) ;
}
}
}
F_14 ( & V_10 -> V_34 , V_33 ) ;
return V_41 ;
}
static int F_18 ( struct V_9 * V_10 ,
struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned int * V_48 )
{
V_48 [ 1 ] = 0 ;
return V_47 -> V_49 ;
}
static int F_19 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
struct V_50 * V_51 )
{
int V_52 = 0 ;
int V_53 ;
V_53 = V_51 -> V_54 ;
V_51 -> V_54 &= V_55 ;
if ( ! V_51 -> V_54 || V_53 != V_51 -> V_54 )
V_52 ++ ;
V_53 = V_51 -> V_56 ;
V_51 -> V_56 &= V_57 ;
if ( ! V_51 -> V_56 || V_53 != V_51 -> V_56 )
V_52 ++ ;
V_53 = V_51 -> V_58 ;
V_51 -> V_58 &= V_59 ;
if ( ! V_51 -> V_58 || V_53 != V_51 -> V_58 )
V_52 ++ ;
V_53 = V_51 -> V_60 ;
V_51 -> V_60 &= V_61 ;
if ( ! V_51 -> V_60 || V_53 != V_51 -> V_60 )
V_52 ++ ;
V_53 = V_51 -> V_62 ;
V_51 -> V_62 &= V_63 ;
if ( ! V_51 -> V_62 || V_53 != V_51 -> V_62 )
V_52 ++ ;
if ( V_52 )
return 1 ;
if ( V_52 )
return 2 ;
if ( V_51 -> V_64 != 0 ) {
V_51 -> V_64 = 0 ;
V_52 ++ ;
}
if ( V_51 -> V_65 != 0 ) {
V_51 -> V_65 = 0 ;
V_52 ++ ;
}
if ( V_51 -> V_66 != 0 ) {
V_51 -> V_66 = 0 ;
V_52 ++ ;
}
if ( V_51 -> V_67 != 1 ) {
V_51 -> V_67 = 1 ;
V_52 ++ ;
}
if ( V_51 -> V_68 != 0 ) {
V_51 -> V_68 = 0 ;
V_52 ++ ;
}
if ( V_52 )
return 3 ;
if ( V_52 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 , struct V_44 * V_45 )
{
F_15 ( V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_44 * V_45 )
{
F_10 ( V_10 ) ;
return 0 ;
}
static T_1 F_22 ( int V_69 , void * V_70 )
{
struct V_9 * V_10 = V_70 ;
struct V_44 * V_45 = V_10 -> V_71 + 1 ;
int V_72 ;
V_72 = F_16 ( V_10 ) ;
if ( V_10 -> V_73 && V_72 ) {
F_23 ( V_45 -> V_74 , 0 ) ;
V_45 -> V_74 -> V_75 |= V_76 | V_77 ;
F_24 ( V_10 , V_45 ) ;
}
return F_25 ( V_72 ) ;
}
static void F_26 ( struct V_9 * V_10 , unsigned int V_69 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_2 * V_78 = F_27 ( V_10 ) ;
char V_79 [ 60 ] ;
int V_80 ;
if ( F_12 ( V_81 ) &&
V_13 -> V_5 == V_82 )
V_80 = F_28 ( V_79 , sizeof( V_79 ) ,
L_3 , V_10 -> V_83 ) ;
else if ( F_12 ( V_36 ) &&
V_13 -> V_5 == V_6 ) {
V_80 = F_28 ( V_79 , sizeof( V_79 ) ,
L_4 , F_29 ( V_78 ) ) ;
} else
V_80 = 0 ;
if ( V_69 )
V_80 += F_28 ( & V_79 [ V_80 ] , sizeof( V_79 ) - V_80 ,
L_5 , V_69 ,
( V_10 -> V_69 ? L_6 : L_7 ) ) ;
else
V_80 += F_28 ( & V_79 [ V_80 ] , sizeof( V_79 ) - V_80 ,
L_8 ) ;
F_30 ( V_10 -> V_25 , L_9 ,
V_10 -> V_84 , V_79 ) ;
}
static int F_31 ( struct V_9 * V_10 , unsigned long V_83 ,
unsigned int V_69 , unsigned long V_85 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
struct V_44 * V_45 ;
int V_86 ;
V_10 -> V_84 = V_13 -> V_87 ;
V_10 -> V_83 = V_83 ;
V_86 = F_32 ( V_10 , 2 ) ;
if ( V_86 )
return V_86 ;
V_45 = V_10 -> V_71 + 0 ;
V_86 = F_33 ( V_10 , V_45 , NULL , V_83 ) ;
if ( V_86 < 0 ) {
F_7 ( V_10 -> V_25 , L_10 ) ;
return V_86 ;
}
V_45 = V_10 -> V_71 + 1 ;
V_10 -> V_88 = V_45 ;
V_45 -> type = V_89 ;
F_10 ( V_10 ) ;
if ( V_69 ) {
if ( F_34 ( V_69 , F_22 , V_85 ,
V_28 , V_10 ) >= 0 ) {
V_10 -> V_69 = V_69 ;
V_45 -> type = V_90 ;
V_45 -> V_91 = V_92 | V_93 ;
V_45 -> V_94 = 1 ;
V_45 -> V_95 = 1 ;
V_45 -> V_96 = & V_97 ;
V_45 -> V_98 = F_18 ;
V_45 -> V_99 = F_19 ;
V_45 -> V_100 = F_20 ;
V_45 -> V_101 = F_21 ;
}
}
F_26 ( V_10 , V_69 ) ;
return 1 ;
}
static int F_35 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
struct V_30 * V_31 = V_10 -> V_32 ;
unsigned long V_83 ;
int V_86 ;
F_36 ( V_10 , & V_2 -> V_10 ) ;
V_86 = F_37 ( V_2 , V_28 ) ;
if ( V_86 < 0 ) {
F_7 ( V_10 -> V_25 ,
L_11 ) ;
return V_86 ;
}
V_31 -> V_37 = F_38 ( V_2 , 1 ) ;
V_83 = F_38 ( V_2 , 2 ) ;
return F_31 ( V_10 , V_83 , V_2 -> V_69 , V_102 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
const struct V_1 * V_13 = F_4 ( V_10 ) ;
int V_86 ;
F_30 ( V_10 -> V_25 , V_28 L_12 ) ;
V_86 = F_40 ( V_10 , sizeof( struct V_30 ) ) ;
if ( V_86 < 0 ) {
F_7 ( V_10 -> V_25 , L_10 ) ;
return V_86 ;
}
if ( F_12 ( V_81 ) &&
V_13 -> V_5 == V_82 ) {
unsigned long V_83 = V_12 -> V_15 [ 0 ] ;
unsigned int V_69 = V_12 -> V_15 [ 1 ] ;
V_86 = F_8 ( V_10 , V_83 , V_103 ) ;
if ( V_86 < 0 )
return V_86 ;
return F_31 ( V_10 , V_83 , V_69 , 0 ) ;
} else if ( F_12 ( V_36 ) &&
V_13 -> V_5 == V_6 ) {
struct V_2 * V_2 ;
V_2 = F_3 ( V_10 , V_12 ) ;
if ( ! V_2 )
return - V_29 ;
return F_35 ( V_10 , V_2 ) ;
} else {
F_7 ( V_10 -> V_25 , V_28
L_13 ) ;
return - V_104 ;
}
}
static int T_2 F_41 ( struct V_9 * V_10 ,
struct V_2 * V_2 )
{
int V_86 ;
if ( ! F_12 ( V_36 ) )
return - V_104 ;
F_30 ( V_10 -> V_25 , V_28 L_14 ,
F_29 ( V_2 ) ) ;
V_86 = F_40 ( V_10 , sizeof( struct V_30 ) ) ;
if ( V_86 < 0 ) {
F_7 ( V_10 -> V_25 , L_10 ) ;
return V_86 ;
}
V_10 -> V_24 = F_1 ( V_2 ) ;
if ( V_10 -> V_24 == NULL ) {
F_7 ( V_10 -> V_25 , L_15 ) ;
return - V_104 ;
}
F_42 ( V_2 ) ;
return F_35 ( V_10 , V_2 ) ;
}
static void F_43 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_2 * V_78 = F_27 ( V_10 ) ;
if ( V_31 )
F_10 ( V_10 ) ;
if ( V_10 -> V_69 )
F_44 ( V_10 -> V_69 , V_10 ) ;
if ( V_10 -> V_71 )
F_45 ( V_10 , V_10 -> V_71 + 0 ) ;
if ( V_78 ) {
if ( V_10 -> V_83 )
F_46 ( V_78 ) ;
F_47 ( V_78 ) ;
} else {
if ( V_10 -> V_83 )
F_48 ( V_10 -> V_83 , V_103 ) ;
}
}
static int T_2 F_49 ( struct V_2 * V_10 ,
const struct V_105 * V_106 )
{
return F_50 ( V_10 , & V_107 ) ;
}
static void T_3 F_51 ( struct V_2 * V_10 )
{
F_52 ( V_10 ) ;
}
