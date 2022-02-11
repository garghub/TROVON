static inline bool F_1 ( T_1 V_1 )
{
return V_1 == V_2 -> V_3 ;
}
void F_2 ( bool V_4 )
{
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 )
V_5 |= V_8 ;
else
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
void F_5 ( T_1 V_1 , T_1 V_9 , bool V_4 )
{
T_1 V_10 , V_5 ;
if ( V_1 >= V_11 )
return;
V_10 = 1 << V_9 ;
if ( ! F_1 ( V_1 ) )
V_10 <<= 4 ;
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 )
V_5 |= V_10 ;
else
V_5 &= ~ V_10 ;
F_4 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
void F_6 ( T_1 V_1 , T_1 V_9 , T_1 V_12 )
{
void T_2 * V_6 ;
if ( V_1 >= V_11 )
return;
if ( F_1 ( V_1 ) )
V_6 = V_2 -> V_6 + V_13 + ( V_9 << 2 ) ;
else
V_6 = V_2 -> V_6 + V_14 + ( V_9 << 2 ) ;
F_4 ( V_12 , V_6 ) ;
}
void F_7 ( T_1 V_1 , bool V_15 )
{
T_1 V_16 ;
if ( V_1 >= V_11 )
return;
V_16 = F_1 ( V_1 ) ? V_17 : V_18 ;
F_4 ( V_15 , V_2 -> V_6 + V_16 ) ;
}
static T_1 F_8 ( T_1 V_9 , T_1 V_1 )
{
return F_1 ( V_1 ) ?
F_9 ( V_9 )
: F_10 ( V_9 ) ;
}
int F_11 ( T_1 V_9 , T_1 V_1 )
{
int V_19 ;
T_1 V_10 = F_8 ( V_9 , V_1 ) ;
if ( V_1 >= V_11 )
return 1 ;
V_19 = F_3 ( V_2 -> V_6 + V_20 ) ;
F_12 ( L_1 ,
V_21 , V_20 , V_19 , V_10 ) ;
return V_19 & V_10 ;
}
static int F_13 ( int V_1 , T_1 * V_22 )
{
struct V_23 * V_24 = V_2 -> V_24 [ V_1 ] ;
T_1 V_25 = 0 ;
T_1 V_26 ;
V_25 = F_1 ( V_1 ) ? V_27 : V_28 ;
V_26 = F_3 ( V_2 -> V_6 + V_25 ) ;
if ( V_26 >= V_2 -> V_29 [ V_1 ] )
return - V_30 ;
V_24 += V_26 ;
* V_22 = V_24 -> V_22 ;
return 0 ;
}
static int F_14 ( int V_1 , T_1 V_22 )
{
int V_31 , V_32 = V_2 -> V_29 [ V_1 ] ;
struct V_23 * V_24 = V_2 -> V_24 [ V_1 ] ;
T_1 V_33 = 0 , V_34 = ~ 0 , V_35 ;
V_22 /= 1000 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ , V_24 ++ ) {
V_35 = V_24 -> V_22 ;
if ( V_35 >= V_22 ) {
if ( V_35 <= V_34 )
V_34 = V_35 ;
} else {
if ( V_35 >= V_33 )
V_33 = V_35 ;
}
}
if ( V_34 != ~ 0 )
return V_34 * 1000 ;
else
return V_33 * 1000 ;
}
static int F_15 ( int V_1 , T_1 V_22 )
{
int V_31 , V_32 = V_2 -> V_29 [ V_1 ] ;
struct V_23 * V_24 = V_2 -> V_24 [ V_1 ] ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ , V_24 ++ )
if ( V_24 -> V_22 == V_22 )
break;
return ( V_31 == V_32 ) ? - V_30 : V_31 ;
}
static int F_16 ( int V_36 )
{
int V_19 = F_17 (
& V_2 -> V_37 , F_18 ( V_38 ) ) ;
if ( V_19 == 0 )
V_19 = - V_39 ;
else if ( V_19 > 0 )
V_19 = V_2 -> V_40 & F_19 ( V_36 ) ? 0 : - V_41 ;
return V_19 ;
}
static int F_20 ( int V_1 , T_1 V_22 )
{
T_1 V_25 , V_42 ;
int V_19 , V_26 , V_36 ;
if ( F_1 ( V_1 ) ) {
V_36 = V_43 ;
V_25 = V_27 ;
V_42 = V_44 ;
} else {
V_36 = V_45 ;
V_25 = V_28 ;
V_42 = V_46 ;
}
V_26 = F_15 ( V_1 , V_22 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_21 ( & V_2 -> V_47 , F_18 ( V_38 ) ) )
return - V_48 ;
F_22 ( & V_2 -> V_37 ) ;
V_2 -> V_49 = F_23 ( V_36 ) ;
F_24 ( V_26 , V_2 -> V_6 + V_25 ) ;
V_19 = F_16 ( V_36 ) ;
V_2 -> V_49 = 0 ;
F_25 ( & V_2 -> V_47 ) ;
return V_19 ;
}
static int F_26 ( int V_50 , int V_51 , T_3 * V_52 )
{
int V_19 ;
if ( F_21 ( & V_2 -> V_47 , F_18 ( V_38 ) ) )
return - V_48 ;
F_22 ( & V_2 -> V_37 ) ;
V_2 -> V_49 = F_23 ( V_53 ) ;
F_24 ( V_54 | V_50 | V_51 >> 2 , V_2 -> V_6 + V_55 ) ;
V_19 = F_16 ( V_53 ) ;
if ( V_19 == 0 )
* V_52 = F_27 ( V_2 -> V_6 + V_56 ) ;
V_2 -> V_49 = 0 ;
F_25 ( & V_2 -> V_47 ) ;
return V_19 ;
}
static T_4 F_28 ( int V_57 , void * V_52 )
{
struct V_58 * V_59 = V_52 ;
T_3 V_60 = F_3 ( V_59 -> V_6 + V_61 ) ;
if ( V_2 -> V_49 & V_60 ) {
V_2 -> V_40 = V_60 ;
F_29 ( & V_59 -> V_37 ) ;
}
return V_62 ;
}
static int F_30 ( T_3 V_1 )
{
T_3 V_52 = 0 , V_63 , V_19 , V_31 ;
struct V_23 * V_24 ;
V_24 = F_31 ( sizeof( * V_24 ) * V_64 , V_65 ) ;
if ( ! V_24 )
return - V_66 ;
V_2 -> V_24 [ V_1 ] = V_24 ;
V_63 = F_1 ( V_1 ) ? V_67 : V_68 ;
for ( V_31 = 0 ; V_31 < V_64 ; V_31 ++ , V_63 += 4 , V_24 ++ ) {
V_19 = F_26 ( V_69 , V_63 , & V_52 ) ;
if ( ! V_19 ) {
V_24 -> V_22 = ( V_52 & V_70 ) * V_71 ;
V_24 -> V_72 = ( V_52 >> V_73 ) * 1000 ;
} else {
break;
}
}
V_2 -> V_29 [ V_1 ] = V_31 ;
return V_19 ;
}
static int F_32 ( struct V_74 * V_75 )
{
int V_1 ;
int V_31 , V_19 = 0 , V_32 ;
struct V_23 * V_24 ;
V_1 = F_33 ( V_75 -> V_76 ) ;
V_1 = V_1 < 0 ? 0 : V_1 ;
V_32 = V_2 -> V_29 [ V_1 ] ;
V_24 = V_2 -> V_24 [ V_1 ] ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ , V_24 ++ ) {
V_19 = F_34 ( V_75 , V_24 -> V_22 * 1000 , V_24 -> V_72 ) ;
if ( V_19 ) {
F_35 ( V_75 , L_2 ,
V_24 -> V_22 , V_24 -> V_72 ) ;
return V_19 ;
}
}
return V_19 ;
}
int T_5 F_36 ( void T_2 * V_6 , T_1 V_3 , int V_57 )
{
int V_19 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_37 ( V_77 L_3 ) ;
return - V_66 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_3 ;
if ( V_57 <= 0 ) {
F_37 ( V_77 L_4 , V_57 ) ;
F_38 ( V_2 ) ;
return - V_30 ;
}
F_22 ( & V_2 -> V_37 ) ;
F_3 ( V_2 -> V_6 + V_61 ) ;
V_19 = F_39 ( V_57 , F_28 , V_78
| V_79 , L_5 , V_2 ) ;
if ( V_19 ) {
F_37 ( V_77 L_6 , V_57 ) ;
F_38 ( V_2 ) ;
return - V_80 ;
}
F_40 ( & V_2 -> V_47 , 1 ) ;
F_41 ( V_2 ) ;
F_41 ( & V_2 ) ;
return 0 ;
}
static unsigned long F_42 ( struct V_81 * V_82 ,
unsigned long V_83 )
{
struct V_84 * V_85 = F_43 ( V_82 ) ;
T_1 V_22 ;
if ( F_13 ( V_85 -> V_1 , & V_22 ) )
return - V_41 ;
return V_22 * 1000 ;
}
static long F_44 ( struct V_81 * V_82 , unsigned long V_86 ,
unsigned long * V_83 )
{
struct V_84 * V_85 = F_43 ( V_82 ) ;
return F_14 ( V_85 -> V_1 , V_86 ) ;
}
static int F_45 ( struct V_81 * V_82 , unsigned long V_87 ,
unsigned long V_83 )
{
struct V_84 * V_85 = F_43 ( V_82 ) ;
return F_20 ( V_85 -> V_1 , V_87 / 1000 ) ;
}
static struct V_88 * F_46 ( struct V_74 * V_75 )
{
struct V_89 V_90 ;
struct V_84 * V_85 ;
V_85 = F_31 ( sizeof( * V_85 ) , V_65 ) ;
if ( ! V_85 ) {
F_37 ( L_7 ) ;
return F_47 ( - V_66 ) ;
}
V_85 -> V_82 . V_90 = & V_90 ;
V_85 -> V_1 = F_33 ( V_75 -> V_76 ) ;
V_85 -> V_1 = V_85 -> V_1 < 0 ? 0 : V_85 -> V_1 ;
V_90 . V_91 = F_48 ( V_75 ) ;
V_90 . V_92 = & V_93 ;
V_90 . V_94 = V_95 ;
V_90 . V_96 = 0 ;
return F_49 ( V_75 , & V_85 -> V_82 ) ;
}
static int T_5 F_50 ( void )
{
int V_9 ;
struct V_88 * V_88 ;
if ( ! V_2 )
return 0 ;
if ( F_30 ( 0 ) || F_30 ( 1 ) ) {
F_37 ( L_8 ) ;
return - V_80 ;
}
F_51 (cpu) {
struct V_74 * V_75 = F_52 ( V_9 ) ;
if ( ! V_75 ) {
F_53 ( L_9 , V_9 ) ;
continue;
}
V_88 = F_46 ( V_75 ) ;
if ( F_54 ( V_88 ) ) {
F_53 ( L_10 , V_9 ) ;
continue;
}
if ( F_55 ( V_88 , NULL , F_48 ( V_75 ) ) ) {
F_53 ( L_11 , V_9 ) ;
continue;
}
if ( F_32 ( V_75 ) )
F_53 ( L_12 , V_9 ) ;
}
F_56 ( L_13 , - 1 , NULL , 0 ) ;
return 0 ;
}
