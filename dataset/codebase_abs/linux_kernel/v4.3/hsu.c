static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
T_1 V_4 = V_5 ;
if ( V_2 -> V_6 == V_7 )
V_4 &= ~ V_8 ;
else if ( V_2 -> V_6 == V_9 )
V_4 |= V_8 ;
F_2 ( V_2 , V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_14 = 0 , V_15 = 0 ;
T_1 V_16 = V_17 | V_18 ;
unsigned int V_19 , V_20 ;
if ( V_2 -> V_6 == V_7 ) {
V_14 = V_11 -> V_21 ;
V_15 = V_11 -> V_22 ;
} else if ( V_2 -> V_6 == V_9 ) {
V_14 = V_11 -> V_23 ;
V_15 = V_11 -> V_24 ;
}
F_1 ( V_2 ) ;
F_2 ( V_2 , V_25 , 0 ) ;
F_2 ( V_2 , V_26 , V_14 ) ;
F_2 ( V_2 , V_27 , V_15 ) ;
V_20 = ( V_13 -> V_28 - V_13 -> V_29 ) % V_30 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
F_2 ( V_2 , F_5 ( V_19 ) , V_13 -> V_31 [ V_19 ] . V_32 ) ;
F_2 ( V_2 , F_6 ( V_19 ) , V_13 -> V_31 [ V_19 ] . V_33 ) ;
V_16 |= F_7 ( V_19 ) ;
V_16 |= F_8 ( V_19 ) ;
V_13 -> V_29 ++ ;
}
V_16 |= F_9 ( V_20 - 1 ) ;
V_16 |= F_10 ( V_20 - 1 ) ;
F_2 ( V_2 , V_25 , V_16 ) ;
F_3 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_2 , V_25 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = F_14 ( & V_2 -> V_36 ) ;
if ( ! V_35 ) {
V_2 -> V_13 = NULL ;
return;
}
F_15 ( & V_35 -> V_37 ) ;
V_2 -> V_13 = F_16 ( V_35 ) ;
F_12 ( V_2 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
T_1 V_39 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
V_39 = F_19 ( V_2 , V_41 ) ;
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
return V_39 ;
}
T_2 F_21 ( struct V_42 * V_43 , unsigned short V_44 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_38 ;
T_1 V_39 ;
if ( V_44 >= V_43 -> V_45 -> V_46 )
return V_47 ;
V_2 = & V_43 -> V_48 -> V_49 [ V_44 ] ;
V_39 = F_17 ( V_2 ) ;
if ( ! V_39 )
return V_47 ;
if ( V_2 -> V_6 == V_9 && ( V_39 & V_50 ) )
F_22 ( 2 ) ;
V_39 &= ~ V_50 ;
if ( ! V_39 )
return V_51 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
V_13 = V_2 -> V_13 ;
if ( V_13 ) {
if ( V_39 & V_52 ) {
V_13 -> V_53 = V_54 ;
} else if ( V_13 -> V_29 < V_13 -> V_28 ) {
F_12 ( V_2 ) ;
} else {
F_23 ( & V_13 -> V_35 ) ;
V_13 -> V_53 = V_55 ;
F_13 ( V_2 ) ;
}
}
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
return V_51 ;
}
static struct V_12 * F_24 ( unsigned int V_28 )
{
struct V_12 * V_13 ;
V_13 = F_25 ( sizeof( * V_13 ) , V_56 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_31 = F_26 ( V_28 , sizeof( * V_13 -> V_31 ) , V_56 ) ;
if ( ! V_13 -> V_31 ) {
F_27 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
static void F_28 ( struct V_34 * V_35 )
{
struct V_12 * V_13 = F_16 ( V_35 ) ;
F_27 ( V_13 -> V_31 ) ;
F_27 ( V_13 ) ;
}
static struct V_57 * F_29 (
struct V_58 * V_49 , struct V_59 * V_60 ,
unsigned int V_61 , enum V_62 V_6 ,
unsigned long V_38 , void * V_63 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
struct V_12 * V_13 ;
struct V_59 * V_31 ;
unsigned int V_19 ;
V_13 = F_24 ( V_61 ) ;
if ( ! V_13 )
return NULL ;
F_31 (sgl, sg, sg_len, i) {
V_13 -> V_31 [ V_19 ] . V_32 = F_32 ( V_31 ) ;
V_13 -> V_31 [ V_19 ] . V_33 = F_33 ( V_31 ) ;
}
V_13 -> V_28 = V_61 ;
V_13 -> V_6 = V_6 ;
V_13 -> V_53 = V_64 ;
return F_34 ( & V_2 -> V_36 , & V_13 -> V_35 , V_38 ) ;
}
static void F_35 ( struct V_58 * V_49 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
unsigned long V_38 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
if ( F_36 ( & V_2 -> V_36 ) && ! V_2 -> V_13 )
F_13 ( V_2 ) ;
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
}
static T_3 F_37 ( struct V_12 * V_13 )
{
T_3 V_65 = 0 ;
unsigned int V_19 ;
for ( V_19 = V_13 -> V_29 ; V_19 < V_13 -> V_28 ; V_19 ++ )
V_65 += V_13 -> V_31 [ V_19 ] . V_33 ;
return V_65 ;
}
static T_3 F_38 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_3 V_65 = F_37 ( V_13 ) ;
int V_19 ;
V_19 = V_13 -> V_29 % V_30 ;
do {
V_65 += F_19 ( V_2 , F_6 ( V_19 ) ) ;
} while ( -- V_19 >= 0 );
return V_65 ;
}
static enum V_66 F_39 ( struct V_58 * V_49 ,
T_4 V_67 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
struct V_34 * V_35 ;
enum V_66 V_53 ;
T_3 V_65 ;
unsigned long V_38 ;
V_53 = F_40 ( V_49 , V_67 , V_69 ) ;
if ( V_53 == V_55 )
return V_53 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
V_35 = F_41 ( & V_2 -> V_36 , V_67 ) ;
if ( V_2 -> V_13 && V_67 == V_2 -> V_13 -> V_35 . V_70 . V_67 ) {
V_65 = F_38 ( V_2 ) ;
F_42 ( V_69 , V_65 ) ;
V_53 = V_2 -> V_13 -> V_53 ;
} else if ( V_35 ) {
V_65 = F_37 ( F_16 ( V_35 ) ) ;
F_42 ( V_69 , V_65 ) ;
}
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
return V_53 ;
}
static int F_43 ( struct V_58 * V_49 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
if ( ! F_44 ( V_11 -> V_6 ) )
return - V_71 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( V_2 -> V_11 ) ) ;
return 0 ;
}
static int F_45 ( struct V_58 * V_49 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
unsigned long V_38 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_53 == V_64 ) {
F_1 ( V_2 ) ;
V_2 -> V_13 -> V_53 = V_72 ;
}
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
return 0 ;
}
static int F_46 ( struct V_58 * V_49 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
unsigned long V_38 ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_53 == V_72 ) {
V_2 -> V_13 -> V_53 = V_64 ;
F_3 ( V_2 ) ;
}
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_49 )
{
struct V_1 * V_2 = F_30 ( V_49 ) ;
unsigned long V_38 ;
F_48 ( V_73 ) ;
F_18 ( & V_2 -> V_36 . V_40 , V_38 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_13 ) {
F_28 ( & V_2 -> V_13 -> V_35 ) ;
V_2 -> V_13 = NULL ;
}
F_49 ( & V_2 -> V_36 , & V_73 ) ;
F_20 ( & V_2 -> V_36 . V_40 , V_38 ) ;
F_50 ( & V_2 -> V_36 , & V_73 ) ;
return 0 ;
}
static void F_51 ( struct V_58 * V_49 )
{
F_52 ( F_53 ( V_49 ) ) ;
}
int F_54 ( struct V_42 * V_43 )
{
struct V_74 * V_48 ;
struct V_75 * V_45 = V_43 -> V_45 ;
void T_5 * V_32 = V_43 -> V_76 + V_43 -> V_77 ;
unsigned short V_19 ;
int V_78 ;
V_48 = F_55 ( V_43 -> V_79 , sizeof( * V_48 ) , V_80 ) ;
if ( ! V_48 )
return - V_81 ;
V_43 -> V_48 = V_48 ;
if ( ! V_45 ) {
V_45 = F_55 ( V_43 -> V_79 , sizeof( * V_45 ) , V_80 ) ;
if ( ! V_45 )
return - V_81 ;
V_43 -> V_45 = V_45 ;
V_45 -> V_46 = ( V_43 -> V_82 - V_43 -> V_77 ) /
V_83 ;
}
V_48 -> V_49 = F_56 ( V_43 -> V_79 , V_45 -> V_46 ,
sizeof( * V_48 -> V_49 ) , V_80 ) ;
if ( ! V_48 -> V_49 )
return - V_81 ;
F_57 ( & V_48 -> V_84 . V_85 ) ;
for ( V_19 = 0 ; V_19 < V_45 -> V_46 ; V_19 ++ ) {
struct V_1 * V_2 = & V_48 -> V_49 [ V_19 ] ;
V_2 -> V_36 . V_86 = F_28 ;
F_58 ( & V_2 -> V_36 , & V_48 -> V_84 ) ;
V_2 -> V_6 = ( V_19 & 0x1 ) ? V_9 : V_7 ;
V_2 -> V_87 = V_32 + V_19 * V_83 ;
}
F_59 ( V_88 , V_48 -> V_84 . V_89 ) ;
F_59 ( V_90 , V_48 -> V_84 . V_89 ) ;
V_48 -> V_84 . V_91 = F_51 ;
V_48 -> V_84 . V_92 = F_29 ;
V_48 -> V_84 . V_93 = F_35 ;
V_48 -> V_84 . V_94 = F_39 ;
V_48 -> V_84 . V_95 = F_43 ;
V_48 -> V_84 . V_96 = F_45 ;
V_48 -> V_84 . V_97 = F_46 ;
V_48 -> V_84 . V_98 = F_47 ;
V_48 -> V_84 . V_99 = V_100 ;
V_48 -> V_84 . V_101 = V_100 ;
V_48 -> V_84 . V_102 = F_60 ( V_9 ) | F_60 ( V_7 ) ;
V_48 -> V_84 . V_103 = V_104 ;
V_48 -> V_84 . V_79 = V_43 -> V_79 ;
V_78 = F_61 ( & V_48 -> V_84 ) ;
if ( V_78 )
return V_78 ;
F_62 ( V_43 -> V_79 , L_1 , V_45 -> V_46 ) ;
return 0 ;
}
int F_63 ( struct V_42 * V_43 )
{
struct V_74 * V_48 = V_43 -> V_48 ;
unsigned short V_19 ;
F_64 ( & V_48 -> V_84 ) ;
for ( V_19 = 0 ; V_19 < V_43 -> V_45 -> V_46 ; V_19 ++ ) {
struct V_1 * V_2 = & V_48 -> V_49 [ V_19 ] ;
F_65 ( & V_2 -> V_36 . V_105 ) ;
}
return 0 ;
}
