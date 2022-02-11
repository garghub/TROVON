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
V_20 = V_13 -> V_28 - V_13 -> V_29 ;
for ( V_19 = 0 ; V_19 < V_20 && V_19 < V_30 ; V_19 ++ ) {
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
int F_17 ( struct V_38 * V_39 , unsigned short V_40 ,
T_1 * V_41 )
{
struct V_1 * V_2 ;
unsigned long V_42 ;
T_1 V_43 ;
if ( V_40 >= V_39 -> V_44 -> V_45 )
return - V_46 ;
V_2 = & V_39 -> V_44 -> V_47 [ V_40 ] ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
V_43 = F_19 ( V_2 , V_49 ) ;
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
V_43 &= ~ ( V_50 | V_51 ) ;
if ( ! V_43 )
return - V_52 ;
if ( V_43 & V_53 )
F_21 ( 2 ) ;
V_43 &= ~ V_53 ;
* V_41 = V_43 ;
return V_43 ? 0 : 1 ;
}
T_2 F_22 ( struct V_38 * V_39 , unsigned short V_40 ,
T_1 V_41 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_42 ;
if ( V_40 >= V_39 -> V_44 -> V_45 )
return V_54 ;
V_2 = & V_39 -> V_44 -> V_47 [ V_40 ] ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
V_13 = V_2 -> V_13 ;
if ( V_13 ) {
if ( V_41 & V_55 ) {
V_13 -> V_41 = V_56 ;
} else if ( V_13 -> V_29 < V_13 -> V_28 ) {
F_12 ( V_2 ) ;
} else {
F_23 ( & V_13 -> V_35 ) ;
V_13 -> V_41 = V_57 ;
F_13 ( V_2 ) ;
}
}
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
return V_58 ;
}
static struct V_12 * F_24 ( unsigned int V_28 )
{
struct V_12 * V_13 ;
V_13 = F_25 ( sizeof( * V_13 ) , V_59 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_31 = F_26 ( V_28 , sizeof( * V_13 -> V_31 ) , V_59 ) ;
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
static struct V_60 * F_29 (
struct V_61 * V_47 , struct V_62 * V_63 ,
unsigned int V_64 , enum V_65 V_6 ,
unsigned long V_42 , void * V_66 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
struct V_12 * V_13 ;
struct V_62 * V_31 ;
unsigned int V_19 ;
V_13 = F_24 ( V_64 ) ;
if ( ! V_13 )
return NULL ;
F_31 (sgl, sg, sg_len, i) {
V_13 -> V_31 [ V_19 ] . V_32 = F_32 ( V_31 ) ;
V_13 -> V_31 [ V_19 ] . V_33 = F_33 ( V_31 ) ;
V_13 -> V_67 += F_33 ( V_31 ) ;
}
V_13 -> V_28 = V_64 ;
V_13 -> V_6 = V_6 ;
V_13 -> V_41 = V_68 ;
return F_34 ( & V_2 -> V_36 , & V_13 -> V_35 , V_42 ) ;
}
static void F_35 ( struct V_61 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
if ( F_36 ( & V_2 -> V_36 ) && ! V_2 -> V_13 )
F_13 ( V_2 ) ;
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_3 V_69 = 0 ;
int V_19 ;
for ( V_19 = V_13 -> V_29 ; V_19 < V_13 -> V_28 ; V_19 ++ )
V_69 += V_13 -> V_31 [ V_19 ] . V_33 ;
V_19 = V_30 - 1 ;
do {
V_69 += F_19 ( V_2 , F_6 ( V_19 ) ) ;
} while ( -- V_19 >= 0 );
return V_69 ;
}
static enum V_70 F_38 ( struct V_61 * V_47 ,
T_4 V_71 , struct V_72 * V_73 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
struct V_34 * V_35 ;
enum V_70 V_41 ;
T_3 V_69 ;
unsigned long V_42 ;
V_41 = F_39 ( V_47 , V_71 , V_73 ) ;
if ( V_41 == V_57 )
return V_41 ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
V_35 = F_40 ( & V_2 -> V_36 , V_71 ) ;
if ( V_2 -> V_13 && V_71 == V_2 -> V_13 -> V_35 . V_74 . V_71 ) {
V_69 = F_37 ( V_2 ) ;
F_41 ( V_73 , V_69 ) ;
V_41 = V_2 -> V_13 -> V_41 ;
} else if ( V_35 ) {
V_69 = F_16 ( V_35 ) -> V_67 ;
F_41 ( V_73 , V_69 ) ;
}
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
return V_41 ;
}
static int F_42 ( struct V_61 * V_47 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
if ( ! F_43 ( V_11 -> V_6 ) )
return - V_46 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( V_2 -> V_11 ) ) ;
return 0 ;
}
static int F_44 ( struct V_61 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_41 == V_68 ) {
F_1 ( V_2 ) ;
V_2 -> V_13 -> V_41 = V_75 ;
}
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
return 0 ;
}
static int F_45 ( struct V_61 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_42 ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_41 == V_75 ) {
V_2 -> V_13 -> V_41 = V_68 ;
F_3 ( V_2 ) ;
}
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
return 0 ;
}
static int F_46 ( struct V_61 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned long V_42 ;
F_47 ( V_76 ) ;
F_18 ( & V_2 -> V_36 . V_48 , V_42 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_13 ) {
F_28 ( & V_2 -> V_13 -> V_35 ) ;
V_2 -> V_13 = NULL ;
}
F_48 ( & V_2 -> V_36 , & V_76 ) ;
F_20 ( & V_2 -> V_36 . V_48 , V_42 ) ;
F_49 ( & V_2 -> V_36 , & V_76 ) ;
return 0 ;
}
static void F_50 ( struct V_61 * V_47 )
{
F_51 ( F_52 ( V_47 ) ) ;
}
int F_53 ( struct V_38 * V_39 )
{
struct V_77 * V_44 ;
void T_5 * V_32 = V_39 -> V_78 + V_39 -> V_79 ;
unsigned short V_19 ;
int V_80 ;
V_44 = F_54 ( V_39 -> V_81 , sizeof( * V_44 ) , V_82 ) ;
if ( ! V_44 )
return - V_83 ;
V_39 -> V_44 = V_44 ;
V_44 -> V_45 = ( V_39 -> V_67 - V_39 -> V_79 ) / V_84 ;
V_44 -> V_47 = F_55 ( V_39 -> V_81 , V_44 -> V_45 ,
sizeof( * V_44 -> V_47 ) , V_82 ) ;
if ( ! V_44 -> V_47 )
return - V_83 ;
F_56 ( & V_44 -> V_85 . V_86 ) ;
for ( V_19 = 0 ; V_19 < V_44 -> V_45 ; V_19 ++ ) {
struct V_1 * V_2 = & V_44 -> V_47 [ V_19 ] ;
V_2 -> V_36 . V_87 = F_28 ;
F_57 ( & V_2 -> V_36 , & V_44 -> V_85 ) ;
V_2 -> V_6 = ( V_19 & 0x1 ) ? V_9 : V_7 ;
V_2 -> V_88 = V_32 + V_19 * V_84 ;
}
F_58 ( V_89 , V_44 -> V_85 . V_90 ) ;
F_58 ( V_91 , V_44 -> V_85 . V_90 ) ;
V_44 -> V_85 . V_92 = F_50 ;
V_44 -> V_85 . V_93 = F_29 ;
V_44 -> V_85 . V_94 = F_35 ;
V_44 -> V_85 . V_95 = F_38 ;
V_44 -> V_85 . V_96 = F_42 ;
V_44 -> V_85 . V_97 = F_44 ;
V_44 -> V_85 . V_98 = F_45 ;
V_44 -> V_85 . V_99 = F_46 ;
V_44 -> V_85 . V_100 = V_101 ;
V_44 -> V_85 . V_102 = V_101 ;
V_44 -> V_85 . V_103 = F_59 ( V_9 ) | F_59 ( V_7 ) ;
V_44 -> V_85 . V_104 = V_105 ;
V_44 -> V_85 . V_81 = V_39 -> V_81 ;
F_60 ( V_44 -> V_85 . V_81 , V_106 ) ;
V_80 = F_61 ( & V_44 -> V_85 ) ;
if ( V_80 )
return V_80 ;
F_62 ( V_39 -> V_81 , L_1 , V_44 -> V_45 ) ;
return 0 ;
}
int F_63 ( struct V_38 * V_39 )
{
struct V_77 * V_44 = V_39 -> V_44 ;
unsigned short V_19 ;
F_64 ( & V_44 -> V_85 ) ;
for ( V_19 = 0 ; V_19 < V_44 -> V_45 ; V_19 ++ ) {
struct V_1 * V_2 = & V_44 -> V_47 [ V_19 ] ;
F_65 ( & V_2 -> V_36 . V_107 ) ;
}
return 0 ;
}
