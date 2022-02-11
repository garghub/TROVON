static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
return V_2 ? V_1 / V_2 : 0u ;
}
static unsigned F_2 ( unsigned V_1 , unsigned V_2 )
{
return V_2 ? V_1 % V_2 : 0u ;
}
static int F_3 ( struct V_3 * V_4 , unsigned V_5 )
{
if ( ! V_5 ) {
V_4 -> V_6 = V_4 -> V_7 = NULL ;
return 0 ;
}
V_4 -> V_6 = F_4 ( sizeof( struct V_8 ) * V_5 ) ;
if ( ! V_4 -> V_6 )
return - V_9 ;
V_4 -> V_7 = V_4 -> V_6 + V_5 ;
return 0 ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 -> V_6 ) ;
}
static struct V_8 * F_7 ( struct V_3 * V_4 , unsigned V_10 )
{
struct V_8 * V_11 ;
V_11 = V_4 -> V_6 + V_10 ;
F_8 ( V_11 >= V_4 -> V_7 ) ;
return V_11 ;
}
static unsigned F_9 ( struct V_3 * V_4 , struct V_8 * V_11 )
{
F_8 ( V_11 < V_4 -> V_6 || V_11 >= V_4 -> V_7 ) ;
return V_11 - V_4 -> V_6 ;
}
static struct V_8 * F_10 ( struct V_3 * V_4 , unsigned V_10 )
{
if ( V_10 == V_12 )
return NULL ;
return F_7 ( V_4 , V_10 ) ;
}
static void F_11 ( struct V_13 * V_14 )
{
V_14 -> V_15 = 0 ;
V_14 -> V_16 = V_14 -> V_17 = V_12 ;
}
static struct V_8 * F_12 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
return F_10 ( V_4 , V_14 -> V_16 ) ;
}
static struct V_8 * F_13 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
return F_10 ( V_4 , V_14 -> V_17 ) ;
}
static struct V_8 * F_14 ( struct V_3 * V_4 , struct V_8 * V_11 )
{
return F_10 ( V_4 , V_11 -> V_18 ) ;
}
static struct V_8 * F_15 ( struct V_3 * V_4 , struct V_8 * V_11 )
{
return F_10 ( V_4 , V_11 -> V_19 ) ;
}
static bool F_16 ( struct V_13 * V_14 )
{
return V_14 -> V_16 == V_12 ;
}
static void F_17 ( struct V_3 * V_4 , struct V_13 * V_14 , struct V_8 * V_11 )
{
struct V_8 * V_16 = F_12 ( V_4 , V_14 ) ;
V_11 -> V_18 = V_14 -> V_16 ;
V_11 -> V_19 = V_12 ;
if ( V_16 )
V_16 -> V_19 = V_14 -> V_16 = F_9 ( V_4 , V_11 ) ;
else
V_14 -> V_16 = V_14 -> V_17 = F_9 ( V_4 , V_11 ) ;
if ( ! V_11 -> V_20 )
V_14 -> V_15 ++ ;
}
static void F_18 ( struct V_3 * V_4 , struct V_13 * V_14 , struct V_8 * V_11 )
{
struct V_8 * V_17 = F_13 ( V_4 , V_14 ) ;
V_11 -> V_18 = V_12 ;
V_11 -> V_19 = V_14 -> V_17 ;
if ( V_17 )
V_17 -> V_18 = V_14 -> V_17 = F_9 ( V_4 , V_11 ) ;
else
V_14 -> V_16 = V_14 -> V_17 = F_9 ( V_4 , V_11 ) ;
if ( ! V_11 -> V_20 )
V_14 -> V_15 ++ ;
}
static void F_19 ( struct V_3 * V_4 , struct V_13 * V_14 ,
struct V_8 * V_21 , struct V_8 * V_11 )
{
struct V_8 * V_19 = F_15 ( V_4 , V_21 ) ;
if ( ! V_19 )
F_17 ( V_4 , V_14 , V_11 ) ;
else {
V_11 -> V_19 = V_21 -> V_19 ;
V_11 -> V_18 = F_9 ( V_4 , V_21 ) ;
V_19 -> V_18 = V_21 -> V_19 = F_9 ( V_4 , V_11 ) ;
if ( ! V_11 -> V_20 )
V_14 -> V_15 ++ ;
}
}
static void F_20 ( struct V_3 * V_4 , struct V_13 * V_14 , struct V_8 * V_11 )
{
struct V_8 * V_19 = F_15 ( V_4 , V_11 ) ;
struct V_8 * V_18 = F_14 ( V_4 , V_11 ) ;
if ( V_19 )
V_19 -> V_18 = V_11 -> V_18 ;
else
V_14 -> V_16 = V_11 -> V_18 ;
if ( V_18 )
V_18 -> V_19 = V_11 -> V_19 ;
else
V_14 -> V_17 = V_11 -> V_19 ;
if ( ! V_11 -> V_20 )
V_14 -> V_15 -- ;
}
static struct V_8 * F_21 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_8 * V_11 ;
for ( V_11 = F_13 ( V_4 , V_14 ) ; V_11 ; V_11 = F_15 ( V_4 , V_11 ) )
if ( ! V_11 -> V_20 ) {
F_20 ( V_4 , V_14 , V_11 ) ;
return V_11 ;
}
return NULL ;
}
static void F_22 ( struct V_22 * V_23 , struct V_3 * V_4 , unsigned V_24 )
{
unsigned V_25 ;
V_23 -> V_4 = V_4 ;
V_23 -> V_15 = 0 ;
V_23 -> V_24 = V_24 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_24 ; V_25 ++ ) {
F_11 ( V_23 -> V_26 + V_25 ) ;
V_23 -> V_27 [ V_25 ] = 0u ;
}
V_23 -> V_28 = 0u ;
V_23 -> V_29 = 0u ;
V_23 -> V_30 = 0u ;
}
static unsigned F_23 ( struct V_22 * V_23 )
{
return V_23 -> V_15 ;
}
static void F_24 ( struct V_22 * V_23 , struct V_8 * V_11 )
{
if ( ! V_11 -> V_20 )
V_23 -> V_15 ++ ;
F_18 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_31 , V_11 ) ;
}
static void F_25 ( struct V_22 * V_23 , struct V_8 * V_21 , struct V_8 * V_11 )
{
if ( ! V_11 -> V_20 )
V_23 -> V_15 ++ ;
F_19 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_31 , V_21 , V_11 ) ;
}
static void F_26 ( struct V_22 * V_23 , struct V_8 * V_11 )
{
F_20 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_31 , V_11 ) ;
if ( ! V_11 -> V_20 )
V_23 -> V_15 -- ;
}
static struct V_8 * F_27 ( struct V_22 * V_23 , unsigned V_32 , bool V_33 )
{
unsigned V_31 ;
struct V_8 * V_11 ;
V_32 = F_28 ( V_32 , V_23 -> V_24 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
for ( V_11 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_31 ) ; V_11 ; V_11 = F_14 ( V_23 -> V_4 , V_11 ) ) {
if ( V_11 -> V_20 ) {
if ( V_33 )
continue;
else
break;
}
return V_11 ;
}
return NULL ;
}
static struct V_8 * F_29 ( struct V_22 * V_23 )
{
struct V_8 * V_11 = F_27 ( V_23 , V_23 -> V_24 , true ) ;
if ( V_11 )
F_26 ( V_23 , V_11 ) ;
return V_11 ;
}
static struct V_8 * F_30 ( struct V_22 * V_23 , unsigned V_32 )
{
struct V_8 * V_11 = F_27 ( V_23 , V_32 , false ) ;
if ( V_11 )
F_26 ( V_23 , V_11 ) ;
return V_11 ;
}
static struct V_8 * F_31 ( struct V_22 * V_23 , unsigned V_31 )
{
struct V_8 * V_11 ;
for (; V_31 < V_23 -> V_24 ; V_31 ++ )
for ( V_11 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_31 ) ; V_11 ; V_11 = F_14 ( V_23 -> V_4 , V_11 ) )
if ( ! V_11 -> V_20 ) {
F_20 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_31 , V_11 ) ;
return V_11 ;
}
return NULL ;
}
static void F_32 ( struct V_22 * V_23 , unsigned V_15 , unsigned V_34 , unsigned V_35 )
{
unsigned V_31 , V_24 , V_36 , V_37 ;
F_8 ( V_34 > V_35 ) ;
F_8 ( V_35 > V_23 -> V_24 ) ;
V_24 = V_35 - V_34 ;
V_36 = F_1 ( V_15 , V_24 ) ;
V_37 = F_2 ( V_15 , V_24 ) ;
for ( V_31 = V_34 ; V_31 < V_35 ; V_31 ++ )
V_23 -> V_27 [ V_31 ] =
( V_31 < ( V_34 + V_37 ) ) ? V_36 + 1u : V_36 ;
}
static void F_33 ( struct V_22 * V_23 )
{
if ( V_23 -> V_28 == V_23 -> V_15 )
return;
V_23 -> V_28 = V_23 -> V_15 ;
if ( V_23 -> V_29 > V_23 -> V_24 )
F_32 ( V_23 , V_23 -> V_15 , 0 , V_23 -> V_24 ) ;
else {
F_32 ( V_23 , V_23 -> V_30 ,
V_23 -> V_24 - V_23 -> V_29 , V_23 -> V_24 ) ;
if ( V_23 -> V_30 < V_23 -> V_15 )
F_32 ( V_23 , V_23 -> V_15 - V_23 -> V_30 ,
0 , V_23 -> V_24 - V_23 -> V_29 ) ;
else
F_32 ( V_23 , 0 , 0 , V_23 -> V_24 - V_23 -> V_29 ) ;
}
}
static void F_34 ( struct V_22 * V_23 )
{
unsigned V_38 , V_31 ;
struct V_13 * V_14 , * V_39 ;
struct V_8 * V_11 ;
F_33 ( V_23 ) ;
for ( V_31 = 0u ; V_31 < V_23 -> V_24 - 1u ; V_31 ++ ) {
V_14 = V_23 -> V_26 + V_31 ;
V_38 = V_23 -> V_27 [ V_31 ] ;
while ( V_14 -> V_15 < V_38 ) {
V_11 = F_31 ( V_23 , V_31 + 1u ) ;
if ( ! V_11 ) {
break;
}
V_11 -> V_31 = V_31 ;
F_18 ( V_23 -> V_4 , V_14 , V_11 ) ;
}
V_39 = V_23 -> V_26 + V_31 + 1u ;
while ( V_14 -> V_15 > V_38 ) {
V_11 = F_21 ( V_23 -> V_4 , V_14 ) ;
if ( ! V_11 )
break;
V_11 -> V_31 = V_31 + 1u ;
F_17 ( V_23 -> V_4 , V_39 , V_11 ) ;
}
}
}
static void F_35 ( struct V_22 * V_23 , struct V_8 * V_40 , struct V_8 * V_11 , unsigned V_41 )
{
struct V_8 * V_42 ;
unsigned V_43 ;
F_26 ( V_23 , V_11 ) ;
if ( V_41 && ( V_11 -> V_31 < V_23 -> V_24 - 1u ) ) {
V_43 = F_28 ( V_23 -> V_24 - 1u , V_11 -> V_31 + V_41 ) ;
for ( V_42 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_43 ) ; V_42 ; V_42 = F_14 ( V_23 -> V_4 , V_42 ) ) {
if ( V_42 -> V_20 )
continue;
F_26 ( V_23 , V_42 ) ;
V_42 -> V_31 = V_11 -> V_31 ;
if ( V_40 )
F_25 ( V_23 , V_40 , V_42 ) ;
else
F_24 ( V_23 , V_42 ) ;
break;
}
V_11 -> V_31 = V_43 ;
}
F_24 ( V_23 , V_11 ) ;
}
static void F_36 ( struct V_22 * V_23 , struct V_8 * V_11 , unsigned V_41 )
{
F_35 ( V_23 , NULL , V_11 , V_41 ) ;
}
static void F_37 ( struct V_44 * V_45 , unsigned V_24 )
{
V_45 -> V_46 = ( V_24 * 3u ) / 4u ;
V_45 -> V_47 = 0u ;
V_45 -> V_48 = 0u ;
}
static void F_38 ( struct V_44 * V_45 )
{
V_45 -> V_47 = V_45 -> V_48 = 0u ;
}
static void F_39 ( struct V_44 * V_45 , unsigned V_31 )
{
if ( V_31 >= V_45 -> V_46 )
V_45 -> V_47 ++ ;
else
V_45 -> V_48 ++ ;
}
static void F_40 ( struct V_44 * V_45 )
{
V_45 -> V_48 ++ ;
}
static enum V_49 F_41 ( struct V_44 * V_45 )
{
unsigned V_50 = F_1 ( V_45 -> V_47 << V_51 , V_45 -> V_47 + V_45 -> V_48 ) ;
if ( V_50 < V_52 )
return V_53 ;
else if ( V_50 < V_54 )
return V_55 ;
else
return V_56 ;
}
static int F_42 ( struct V_57 * V_58 , struct V_3 * V_4 , unsigned V_5 )
{
unsigned V_25 , V_59 ;
V_58 -> V_4 = V_4 ;
V_59 = F_43 ( F_44 ( V_5 / 4u , 16u ) ) ;
V_58 -> V_60 = F_45 ( V_59 ) ;
V_58 -> V_61 = F_46 ( sizeof( * V_58 -> V_61 ) * V_59 ) ;
if ( ! V_58 -> V_61 )
return - V_9 ;
for ( V_25 = 0 ; V_25 < V_59 ; V_25 ++ )
V_58 -> V_61 [ V_25 ] = V_12 ;
return 0 ;
}
static void F_47 ( struct V_57 * V_58 )
{
F_6 ( V_58 -> V_61 ) ;
}
static struct V_8 * F_48 ( struct V_57 * V_58 , unsigned V_62 )
{
return F_10 ( V_58 -> V_4 , V_58 -> V_61 [ V_62 ] ) ;
}
static struct V_8 * F_49 ( struct V_57 * V_58 , struct V_8 * V_11 )
{
return F_10 ( V_58 -> V_4 , V_11 -> V_63 ) ;
}
static void F_50 ( struct V_57 * V_58 , unsigned V_62 , struct V_8 * V_11 )
{
V_11 -> V_63 = V_58 -> V_61 [ V_62 ] ;
V_58 -> V_61 [ V_62 ] = F_9 ( V_58 -> V_4 , V_11 ) ;
}
static void F_51 ( struct V_57 * V_58 , struct V_8 * V_11 )
{
unsigned V_64 = F_52 ( F_53 ( V_11 -> V_65 ) , V_58 -> V_60 ) ;
F_50 ( V_58 , V_64 , V_11 ) ;
}
static struct V_8 * F_54 ( struct V_57 * V_58 , unsigned V_64 , T_1 V_65 ,
struct V_8 * * V_19 )
{
struct V_8 * V_11 ;
* V_19 = NULL ;
for ( V_11 = F_48 ( V_58 , V_64 ) ; V_11 ; V_11 = F_49 ( V_58 , V_11 ) ) {
if ( V_11 -> V_65 == V_65 )
return V_11 ;
* V_19 = V_11 ;
}
return NULL ;
}
static void F_55 ( struct V_57 * V_58 , unsigned V_64 ,
struct V_8 * V_11 , struct V_8 * V_19 )
{
if ( V_19 )
V_19 -> V_63 = V_11 -> V_63 ;
else
V_58 -> V_61 [ V_64 ] = V_11 -> V_63 ;
}
static struct V_8 * F_56 ( struct V_57 * V_58 , T_1 V_65 )
{
struct V_8 * V_11 , * V_19 ;
unsigned V_64 = F_52 ( F_53 ( V_65 ) , V_58 -> V_60 ) ;
V_11 = F_54 ( V_58 , V_64 , V_65 , & V_19 ) ;
if ( V_11 && V_19 ) {
F_55 ( V_58 , V_64 , V_11 , V_19 ) ;
F_50 ( V_58 , V_64 , V_11 ) ;
}
return V_11 ;
}
static void F_57 ( struct V_57 * V_58 , struct V_8 * V_11 )
{
unsigned V_64 = F_52 ( F_53 ( V_11 -> V_65 ) , V_58 -> V_60 ) ;
struct V_8 * V_19 ;
V_11 = F_54 ( V_58 , V_64 , V_11 -> V_65 , & V_19 ) ;
if ( V_11 )
F_55 ( V_58 , V_64 , V_11 , V_19 ) ;
}
static void F_58 ( struct V_66 * V_67 , struct V_3 * V_4 ,
unsigned V_6 , unsigned V_7 )
{
unsigned V_25 ;
V_67 -> V_4 = V_4 ;
V_67 -> V_68 = 0u ;
V_67 -> V_6 = V_6 ;
F_11 ( & V_67 -> free ) ;
for ( V_25 = V_6 ; V_25 != V_7 ; V_25 ++ )
F_18 ( V_67 -> V_4 , & V_67 -> free , F_7 ( V_67 -> V_4 , V_25 ) ) ;
}
static void F_59 ( struct V_8 * V_11 )
{
V_11 -> V_63 = V_12 ;
V_11 -> V_18 = V_12 ;
V_11 -> V_19 = V_12 ;
V_11 -> V_31 = 0u ;
V_11 -> V_69 = true ;
}
static struct V_8 * F_60 ( struct V_66 * V_67 )
{
struct V_8 * V_11 ;
if ( F_16 ( & V_67 -> free ) )
return NULL ;
V_11 = F_21 ( V_67 -> V_4 , & V_67 -> free ) ;
F_59 ( V_11 ) ;
V_67 -> V_68 ++ ;
return V_11 ;
}
static struct V_8 * F_61 ( struct V_66 * V_67 , unsigned V_25 )
{
struct V_8 * V_11 = F_7 ( V_67 -> V_4 , V_67 -> V_6 + V_25 ) ;
F_8 ( V_11 -> V_69 ) ;
F_20 ( V_67 -> V_4 , & V_67 -> free , V_11 ) ;
F_59 ( V_11 ) ;
V_67 -> V_68 ++ ;
return V_11 ;
}
static void F_62 ( struct V_66 * V_67 , struct V_8 * V_11 )
{
F_8 ( ! V_67 -> V_68 ) ;
F_8 ( ! V_11 -> V_69 ) ;
V_67 -> V_68 -- ;
V_11 -> V_69 = false ;
F_18 ( V_67 -> V_4 , & V_67 -> free , V_11 ) ;
}
static bool F_63 ( struct V_66 * V_67 )
{
return F_16 ( & V_67 -> free ) ;
}
static unsigned F_64 ( struct V_66 * V_67 , struct V_8 * V_11 )
{
return F_9 ( V_67 -> V_4 , V_11 ) - V_67 -> V_6 ;
}
static struct V_8 * F_65 ( struct V_66 * V_67 , unsigned V_70 )
{
return F_7 ( V_67 -> V_4 , V_67 -> V_6 + V_70 ) ;
}
static struct V_8 * F_66 ( struct V_66 * V_67 , unsigned V_31 , bool V_71 )
{
return F_65 ( V_67 , V_71 ? V_31 : V_72 + V_31 ) ;
}
static struct V_8 * F_67 ( struct V_73 * V_74 , unsigned V_31 )
{
return F_66 ( & V_74 -> V_75 , V_31 , V_74 -> V_76 ) ;
}
static struct V_8 * F_68 ( struct V_73 * V_74 , unsigned V_31 )
{
return F_66 ( & V_74 -> V_77 , V_31 , V_74 -> V_78 ) ;
}
static void F_69 ( struct V_73 * V_74 )
{
unsigned V_31 ;
struct V_22 * V_23 = & V_74 -> V_79 ;
struct V_8 * V_20 ;
for ( V_31 = 0 ; V_31 < V_23 -> V_24 ; V_31 ++ ) {
V_20 = F_67 ( V_74 , V_31 ) ;
F_26 ( V_23 , V_20 ) ;
F_24 ( V_23 , V_20 ) ;
}
}
static void F_70 ( struct V_73 * V_74 )
{
unsigned V_31 ;
struct V_22 * V_23 = & V_74 -> V_80 ;
struct V_8 * V_20 ;
for ( V_31 = 0 ; V_31 < V_23 -> V_24 ; V_31 ++ ) {
V_20 = F_68 ( V_74 , V_31 ) ;
F_26 ( V_23 , V_20 ) ;
F_24 ( V_23 , V_20 ) ;
}
}
static void F_71 ( struct V_73 * V_74 )
{
if ( F_72 ( V_81 , V_74 -> V_82 ) ) {
F_69 ( V_74 ) ;
V_74 -> V_82 = V_81 + V_83 ;
V_74 -> V_76 = ! V_74 -> V_76 ;
}
if ( F_72 ( V_81 , V_74 -> V_84 ) ) {
F_70 ( V_74 ) ;
V_74 -> V_84 = V_81 + V_85 ;
V_74 -> V_78 = ! V_74 -> V_78 ;
}
}
static void F_73 ( struct V_73 * V_74 )
{
unsigned V_31 ;
struct V_8 * V_20 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ ) {
V_20 = F_67 ( V_74 , V_31 ) ;
V_20 -> V_31 = V_31 ;
F_24 ( & V_74 -> V_79 , V_20 ) ;
V_20 = F_68 ( V_74 , V_31 ) ;
V_20 -> V_31 = V_31 ;
F_24 ( & V_74 -> V_80 , V_20 ) ;
}
}
static void F_74 ( struct V_73 * V_74 )
{
V_74 -> V_82 = V_81 + V_83 ;
V_74 -> V_84 = V_81 + V_85 ;
V_74 -> V_76 = false ;
V_74 -> V_78 = false ;
F_73 ( V_74 ) ;
V_74 -> V_76 = ! V_74 -> V_76 ;
V_74 -> V_78 = ! V_74 -> V_78 ;
F_73 ( V_74 ) ;
}
static void F_75 ( struct V_73 * V_74 , struct V_8 * V_11 )
{
struct V_22 * V_23 = V_11 -> V_79 ? & V_74 -> V_79 : & V_74 -> V_80 ;
F_51 ( & V_74 -> V_86 , V_11 ) ;
F_24 ( V_23 , V_11 ) ;
}
static void F_76 ( struct V_73 * V_74 , struct V_8 * V_11 )
{
struct V_8 * V_20 ;
F_51 ( & V_74 -> V_86 , V_11 ) ;
if ( V_11 -> V_79 ) {
V_20 = F_67 ( V_74 , V_11 -> V_31 ) ;
F_25 ( & V_74 -> V_79 , V_20 , V_11 ) ;
} else {
V_20 = F_68 ( V_74 , V_11 -> V_31 ) ;
F_25 ( & V_74 -> V_80 , V_20 , V_11 ) ;
}
}
static void F_77 ( struct V_73 * V_74 , struct V_22 * V_23 , struct V_8 * V_11 )
{
F_26 ( V_23 , V_11 ) ;
F_57 ( & V_74 -> V_86 , V_11 ) ;
}
static void F_78 ( struct V_73 * V_74 , struct V_8 * V_11 )
{
F_77 ( V_74 , V_11 -> V_79 ? & V_74 -> V_79 : & V_74 -> V_80 , V_11 ) ;
}
static struct V_8 * F_79 ( struct V_73 * V_74 , struct V_22 * V_23 , unsigned V_32 )
{
struct V_8 * V_11 = F_30 ( V_23 , V_32 ) ;
if ( V_11 )
F_57 ( & V_74 -> V_86 , V_11 ) ;
return V_11 ;
}
static T_2 F_80 ( struct V_73 * V_74 , struct V_8 * V_11 )
{
return F_81 ( F_64 ( & V_74 -> V_87 , V_11 ) ) ;
}
static void F_82 ( struct V_73 * V_74 , struct V_8 * V_11 )
{
struct V_8 * V_20 ;
if ( ! F_83 ( F_84 ( F_80 ( V_74 , V_11 ) ) , V_74 -> V_88 ) ) {
if ( V_11 -> V_79 ) {
V_20 = F_67 ( V_74 , V_11 -> V_31 ) ;
F_35 ( & V_74 -> V_79 , V_20 , V_11 , 1u ) ;
} else {
V_20 = F_68 ( V_74 , V_11 -> V_31 ) ;
F_35 ( & V_74 -> V_80 , V_20 , V_11 , 1u ) ;
}
}
}
static unsigned F_85 ( struct V_73 * V_74 )
{
static unsigned V_86 [] = { 1 , 1 , 1 , 2 , 4 , 6 , 7 , 8 , 7 , 6 , 4 , 4 , 3 , 3 , 2 , 2 , 1 } ;
unsigned V_47 = V_74 -> V_89 . V_47 ;
unsigned V_48 = V_74 -> V_89 . V_48 ;
unsigned V_70 = F_1 ( V_47 << 4u , V_47 + V_48 ) ;
return V_86 [ V_70 ] ;
}
static void F_86 ( struct V_73 * V_74 )
{
unsigned V_90 = F_63 ( & V_74 -> V_87 ) ?
F_85 ( V_74 ) : ( V_91 / 2u ) ;
switch ( F_41 ( & V_74 -> V_92 ) ) {
case V_53 :
V_90 /= 4u ;
break;
case V_55 :
V_90 /= 2u ;
break;
case V_56 :
break;
}
V_74 -> V_93 = V_91 - V_90 ;
V_74 -> V_94 = ( V_91 - V_90 ) + 2u ;
}
static void F_87 ( struct V_73 * V_74 )
{
switch ( F_41 ( & V_74 -> V_92 ) ) {
case V_53 :
V_74 -> V_95 = 4u ;
break;
case V_55 :
V_74 -> V_95 = 2u ;
break;
case V_56 :
V_74 -> V_95 = 1u ;
break;
}
}
static void F_88 ( struct V_73 * V_74 )
{
F_89 ( V_74 -> V_96 , V_74 -> V_97 ) ;
F_86 ( V_74 ) ;
if ( F_72 ( V_81 , V_74 -> V_98 ) ) {
F_87 ( V_74 ) ;
F_34 ( & V_74 -> V_99 ) ;
F_38 ( & V_74 -> V_92 ) ;
V_74 -> V_98 = V_81 + V_100 ;
}
}
static void F_90 ( struct V_73 * V_74 )
{
if ( F_72 ( V_81 , V_74 -> V_101 ) ) {
F_89 ( V_74 -> V_88 , F_84 ( V_74 -> V_102 ) ) ;
F_34 ( & V_74 -> V_79 ) ;
F_34 ( & V_74 -> V_80 ) ;
F_38 ( & V_74 -> V_89 ) ;
V_74 -> V_101 = V_81 + V_103 ;
}
}
static int F_91 ( struct V_73 * V_74 ,
struct V_104 * V_105 ,
T_1 * V_65 )
{
struct V_8 * V_106 = F_27 ( & V_74 -> V_80 , V_74 -> V_80 . V_24 , false ) ;
if ( ! V_106 )
return - V_107 ;
if ( V_105 -> V_108 ( V_105 , V_106 -> V_65 ) )
return - V_109 ;
F_78 ( V_74 , V_106 ) ;
* V_65 = V_106 -> V_65 ;
F_62 ( & V_74 -> V_87 , V_106 ) ;
return 0 ;
}
static enum V_110 F_92 ( bool V_111 )
{
return V_111 ? V_112 : V_113 ;
}
static enum V_110 F_93 ( struct V_73 * V_74 , struct V_8 * V_114 , struct V_115 * V_115 ,
bool V_116 )
{
if ( F_94 ( V_115 ) == V_117 ) {
if ( ! F_63 ( & V_74 -> V_87 ) && V_116 )
return V_118 ;
else
return F_92 ( V_114 -> V_31 >= V_74 -> V_94 ) ;
} else
return F_92 ( V_114 -> V_31 >= V_74 -> V_93 ) ;
}
static void F_95 ( struct V_73 * V_74 , T_1 V_65 ,
struct V_104 * V_105 ,
struct V_119 * V_120 , enum V_110 V_121 )
{
int V_122 ;
struct V_8 * V_11 ;
if ( F_63 ( & V_74 -> V_87 ) ) {
V_120 -> V_123 = V_124 ;
V_122 = F_91 ( V_74 , V_105 , & V_120 -> V_125 ) ;
if ( V_122 ) {
V_120 -> V_123 = V_126 ;
return;
}
} else
V_120 -> V_123 = V_127 ;
V_11 = F_60 ( & V_74 -> V_87 ) ;
F_8 ( ! V_11 ) ;
V_11 -> V_65 = V_65 ;
if ( V_121 == V_118 )
F_76 ( V_74 , V_11 ) ;
else
F_75 ( V_74 , V_11 ) ;
V_120 -> V_128 = F_80 ( V_74 , V_11 ) ;
}
static T_1 F_96 ( struct V_73 * V_74 , T_1 V_129 )
{
T_3 V_122 = F_53 ( V_129 ) ;
( void ) F_97 ( V_122 , V_74 -> V_130 ) ;
return F_98 ( V_122 ) ;
}
static struct V_8 * F_99 ( struct V_73 * V_74 , T_1 V_129 , struct V_115 * V_115 )
{
unsigned V_131 ;
T_1 V_132 = F_96 ( V_74 , V_129 ) ;
struct V_8 * V_11 = F_56 ( & V_74 -> V_133 , V_132 ) ;
if ( V_11 ) {
F_39 ( & V_74 -> V_92 , V_11 -> V_31 ) ;
V_131 = F_64 ( & V_74 -> V_134 , V_11 ) ;
F_36 ( & V_74 -> V_99 , V_11 ,
F_83 ( V_131 , V_74 -> V_96 ) ?
0u : V_74 -> V_95 ) ;
} else {
F_40 ( & V_74 -> V_92 ) ;
V_11 = F_60 ( & V_74 -> V_134 ) ;
if ( ! V_11 ) {
V_11 = F_29 ( & V_74 -> V_99 ) ;
if ( V_11 ) {
F_57 ( & V_74 -> V_133 , V_11 ) ;
V_131 = F_64 ( & V_74 -> V_134 , V_11 ) ;
F_100 ( V_131 , V_74 -> V_96 ) ;
}
}
if ( V_11 ) {
V_11 -> V_65 = V_132 ;
F_24 ( & V_74 -> V_99 , V_11 ) ;
F_51 ( & V_74 -> V_133 , V_11 ) ;
}
}
return V_11 ;
}
static int F_101 ( struct V_73 * V_74 , struct V_115 * V_115 , T_1 V_65 ,
bool V_135 , bool V_116 ,
struct V_104 * V_105 , struct V_119 * V_120 )
{
struct V_8 * V_11 , * V_114 ;
enum V_110 V_121 ;
V_114 = F_99 ( V_74 , V_65 , V_115 ) ;
V_11 = F_56 ( & V_74 -> V_86 , V_65 ) ;
if ( V_11 ) {
F_39 ( & V_74 -> V_89 , V_11 -> V_31 ) ;
F_82 ( V_74 , V_11 ) ;
V_120 -> V_123 = V_136 ;
V_120 -> V_128 = F_80 ( V_74 , V_11 ) ;
} else {
F_40 ( & V_74 -> V_89 ) ;
V_121 = F_93 ( V_74 , V_114 , V_115 , V_116 ) ;
if ( V_121 == V_113 )
V_120 -> V_123 = V_126 ;
else {
if ( ! V_135 ) {
V_120 -> V_123 = V_126 ;
return - V_137 ;
}
F_95 ( V_74 , V_65 , V_105 , V_120 , V_121 ) ;
}
}
return 0 ;
}
static struct V_73 * F_102 ( struct V_138 * V_139 )
{
return F_103 ( V_139 , struct V_73 , V_140 ) ;
}
static void F_104 ( struct V_138 * V_139 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_47 ( & V_74 -> V_133 ) ;
F_47 ( & V_74 -> V_86 ) ;
F_105 ( V_74 -> V_96 ) ;
F_105 ( V_74 -> V_88 ) ;
F_5 ( & V_74 -> V_4 ) ;
F_106 ( V_74 ) ;
}
static int F_107 ( struct V_138 * V_139 , T_1 V_65 ,
bool V_141 , bool V_135 , bool V_116 ,
struct V_115 * V_115 , struct V_104 * V_105 ,
struct V_119 * V_120 )
{
int V_122 ;
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
V_120 -> V_123 = V_126 ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_122 = F_101 ( V_74 , V_115 , V_65 , V_135 , V_116 , V_105 , V_120 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
return V_122 ;
}
static int F_110 ( struct V_138 * V_139 , T_1 V_65 , T_2 * V_128 )
{
int V_122 ;
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
struct V_8 * V_11 ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_11 = F_56 ( & V_74 -> V_86 , V_65 ) ;
if ( V_11 ) {
* V_128 = F_80 ( V_74 , V_11 ) ;
V_122 = 0 ;
} else
V_122 = - V_144 ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
return V_122 ;
}
static void F_111 ( struct V_73 * V_74 , T_1 V_65 , bool V_145 )
{
struct V_8 * V_11 ;
V_11 = F_56 ( & V_74 -> V_86 , V_65 ) ;
F_8 ( ! V_11 ) ;
F_78 ( V_74 , V_11 ) ;
V_11 -> V_79 = V_145 ;
F_76 ( V_74 , V_11 ) ;
}
static void F_112 ( struct V_138 * V_139 , T_1 V_65 )
{
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
F_111 ( V_74 , V_65 , true ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
}
static void F_113 ( struct V_138 * V_139 , T_1 V_65 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
unsigned long V_142 ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
F_111 ( V_74 , V_65 , false ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
}
static int F_114 ( struct V_138 * V_139 ,
T_1 V_65 , T_2 V_128 ,
T_4 V_146 , bool V_147 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
struct V_8 * V_11 ;
V_11 = F_61 ( & V_74 -> V_87 , F_84 ( V_128 ) ) ;
V_11 -> V_65 = V_65 ;
V_11 -> V_79 = false ;
V_11 -> V_31 = V_147 ? F_28 ( V_146 , V_72 - 1 ) : 1 ;
F_76 ( V_74 , V_11 ) ;
return 0 ;
}
static int F_115 ( struct V_73 * V_74 , struct V_22 * V_23 ,
T_5 V_108 , void * V_148 )
{
int V_122 ;
unsigned V_31 ;
struct V_8 * V_11 ;
for ( V_31 = 0 ; V_31 < V_23 -> V_24 ; V_31 ++ )
for ( V_11 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_31 ) ; V_11 ; V_11 = F_14 ( V_23 -> V_4 , V_11 ) ) {
if ( ! V_11 -> V_20 ) {
V_122 = V_108 ( V_148 , F_80 ( V_74 , V_11 ) ,
V_11 -> V_65 , V_11 -> V_31 ) ;
if ( V_122 )
return V_122 ;
}
}
return 0 ;
}
static int F_116 ( struct V_138 * V_139 , T_5 V_108 ,
void * V_148 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
int V_122 = 0 ;
V_122 = F_115 ( V_74 , & V_74 -> V_80 , V_108 , V_148 ) ;
if ( ! V_122 )
V_122 = F_115 ( V_74 , & V_74 -> V_79 , V_108 , V_148 ) ;
return V_122 ;
}
static void F_117 ( struct V_73 * V_74 , T_1 V_65 )
{
struct V_8 * V_11 ;
V_11 = F_56 ( & V_74 -> V_86 , V_65 ) ;
F_8 ( ! V_11 ) ;
F_78 ( V_74 , V_11 ) ;
F_62 ( & V_74 -> V_87 , V_11 ) ;
}
static void F_118 ( struct V_138 * V_139 , T_1 V_65 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
unsigned long V_142 ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
F_117 ( V_74 , V_65 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
}
static int F_119 ( struct V_73 * V_74 , T_2 V_128 )
{
struct V_8 * V_11 = F_65 ( & V_74 -> V_87 , F_84 ( V_128 ) ) ;
if ( ! V_11 || ! V_11 -> V_69 )
return - V_149 ;
F_78 ( V_74 , V_11 ) ;
F_62 ( & V_74 -> V_87 , V_11 ) ;
return 0 ;
}
static int F_120 ( struct V_138 * V_139 , T_2 V_128 )
{
int V_122 ;
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_122 = F_119 ( V_74 , V_128 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
return V_122 ;
}
static bool F_121 ( struct V_73 * V_74 , bool V_150 )
{
if ( V_150 ) {
unsigned V_151 = F_84 ( V_74 -> V_102 ) - F_23 ( & V_74 -> V_79 ) ;
unsigned V_38 = F_84 ( V_74 -> V_102 ) * V_152 / 100u ;
return V_151 >= V_38 ;
} else
return ! F_23 ( & V_74 -> V_79 ) ;
}
static int F_122 ( struct V_73 * V_74 , T_1 * V_65 ,
T_2 * V_128 , bool V_153 )
{
struct V_8 * V_11 = NULL ;
bool V_154 = F_121 ( V_74 , V_153 ) ;
if ( V_153 )
V_11 = F_79 ( V_74 , & V_74 -> V_79 , V_154 ? 1u : V_74 -> V_79 . V_24 ) ;
else
V_11 = F_79 ( V_74 , & V_74 -> V_79 , V_74 -> V_79 . V_24 ) ;
if ( ! V_11 )
return - V_149 ;
* V_65 = V_11 -> V_65 ;
* V_128 = F_80 ( V_74 , V_11 ) ;
V_11 -> V_79 = false ;
F_75 ( V_74 , V_11 ) ;
return 0 ;
}
static int F_123 ( struct V_138 * V_139 , T_1 * V_65 ,
T_2 * V_128 , bool V_153 )
{
int V_122 ;
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_122 = F_122 ( V_74 , V_65 , V_128 , V_153 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
return V_122 ;
}
static void F_124 ( struct V_73 * V_74 ,
T_1 V_155 , T_1 V_156 )
{
struct V_8 * V_11 = F_56 ( & V_74 -> V_86 , V_155 ) ;
if ( V_11 ) {
F_78 ( V_74 , V_11 ) ;
V_11 -> V_65 = V_156 ;
V_11 -> V_79 = true ;
F_76 ( V_74 , V_11 ) ;
}
}
static void F_125 ( struct V_138 * V_139 ,
T_1 V_155 , T_1 V_156 )
{
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
F_124 ( V_74 , V_155 , V_156 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
}
static T_2 F_126 ( struct V_138 * V_139 )
{
T_2 V_122 ;
unsigned long V_142 ;
struct V_73 * V_74 = F_102 ( V_139 ) ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_122 = F_81 ( V_74 -> V_87 . V_68 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
return V_122 ;
}
static void F_127 ( struct V_138 * V_139 , bool V_141 )
{
struct V_73 * V_74 = F_102 ( V_139 ) ;
unsigned long V_142 ;
F_108 ( & V_74 -> V_143 , V_142 ) ;
V_74 -> V_157 ++ ;
F_71 ( V_74 ) ;
F_88 ( V_74 ) ;
F_90 ( V_74 ) ;
F_109 ( & V_74 -> V_143 , V_142 ) ;
}
static void F_128 ( struct V_73 * V_74 )
{
V_74 -> V_140 . V_158 = F_104 ;
V_74 -> V_140 . F_101 = F_107 ;
V_74 -> V_140 . V_159 = F_110 ;
V_74 -> V_140 . V_160 = F_112 ;
V_74 -> V_140 . V_161 = F_113 ;
V_74 -> V_140 . V_162 = F_114 ;
V_74 -> V_140 . V_163 = F_116 ;
V_74 -> V_140 . V_164 = F_118 ;
V_74 -> V_140 . V_165 = F_120 ;
V_74 -> V_140 . V_166 = F_123 ;
V_74 -> V_140 . V_167 = F_125 ;
V_74 -> V_140 . V_168 = F_126 ;
V_74 -> V_140 . V_157 = F_127 ;
}
static bool F_129 ( T_3 V_169 ,
T_3 V_170 ,
unsigned V_97 )
{
return ( V_170 * V_97 ) > V_169 ;
}
static void F_130 ( T_3 V_169 ,
T_3 V_171 ,
unsigned V_172 ,
T_3 * V_170 ,
unsigned * V_97 )
{
* V_170 = V_171 * 16u ;
* V_97 = F_44 ( V_172 / 4u , 1024u ) ;
while ( ( * V_170 > V_171 ) &&
F_129 ( V_169 , * V_170 , * V_97 ) )
* V_170 /= 2u ;
}
static struct V_138 * F_131 ( T_2 V_102 ,
T_3 V_169 ,
T_3 V_171 )
{
unsigned V_25 ;
unsigned V_173 = 2u * V_72 ;
unsigned V_174 = 2u * V_173 ;
struct V_73 * V_74 = F_132 ( sizeof( * V_74 ) , V_175 ) ;
if ( ! V_74 )
return NULL ;
F_128 ( V_74 ) ;
V_74 -> V_102 = V_102 ;
V_74 -> V_171 = V_171 ;
F_130 ( V_169 , V_171 , F_84 ( V_102 ) ,
& V_74 -> V_170 , & V_74 -> V_97 ) ;
V_74 -> V_130 = F_133 ( V_74 -> V_170 , V_74 -> V_171 ) ;
V_74 -> V_95 = 1u ;
if ( F_3 ( & V_74 -> V_4 , V_174 + V_74 -> V_97 + F_84 ( V_102 ) ) ) {
F_134 ( L_1 ) ;
goto V_176;
}
F_58 ( & V_74 -> V_75 , & V_74 -> V_4 , 0 , V_173 ) ;
for ( V_25 = 0 ; V_25 < V_173 ; V_25 ++ )
F_65 ( & V_74 -> V_75 , V_25 ) -> V_20 = true ;
F_58 ( & V_74 -> V_77 , & V_74 -> V_4 , V_173 , V_174 ) ;
for ( V_25 = 0 ; V_25 < V_173 ; V_25 ++ )
F_65 ( & V_74 -> V_77 , V_25 ) -> V_20 = true ;
F_58 ( & V_74 -> V_134 , & V_74 -> V_4 , V_174 ,
V_174 + V_74 -> V_97 ) ;
F_58 ( & V_74 -> V_87 , & V_74 -> V_4 ,
V_174 + V_74 -> V_97 ,
V_174 + V_74 -> V_97 + F_84 ( V_102 ) ) ;
V_74 -> V_96 = F_135 ( V_74 -> V_97 ) ;
if ( ! V_74 -> V_96 ) {
F_134 ( L_2 ) ;
goto V_177;
}
F_89 ( V_74 -> V_96 , V_74 -> V_97 ) ;
if ( F_84 ( V_102 ) ) {
V_74 -> V_88 = F_135 ( F_84 ( V_102 ) ) ;
if ( ! V_74 -> V_88 ) {
F_134 ( L_3 ) ;
goto V_178;
}
F_89 ( V_74 -> V_88 , F_84 ( V_74 -> V_102 ) ) ;
} else
V_74 -> V_88 = NULL ;
V_74 -> V_157 = 0 ;
F_136 ( & V_74 -> V_143 ) ;
F_22 ( & V_74 -> V_99 , & V_74 -> V_4 , V_91 ) ;
V_74 -> V_99 . V_29 = 8 ;
V_74 -> V_99 . V_30 = F_28 ( V_74 -> V_97 / V_91 ,
F_84 ( V_74 -> V_102 ) / V_74 -> V_130 ) ;
F_22 ( & V_74 -> V_80 , & V_74 -> V_4 , V_72 ) ;
F_22 ( & V_74 -> V_79 , & V_74 -> V_4 , V_72 ) ;
F_37 ( & V_74 -> V_92 , V_91 ) ;
F_37 ( & V_74 -> V_89 , V_72 ) ;
if ( F_42 ( & V_74 -> V_86 , & V_74 -> V_4 , F_84 ( V_102 ) ) )
goto V_179;
if ( F_42 ( & V_74 -> V_133 , & V_74 -> V_4 , V_74 -> V_97 ) )
goto V_180;
F_74 ( V_74 ) ;
V_74 -> V_94 = V_74 -> V_93 = V_91 ;
V_74 -> V_98 = V_81 ;
V_74 -> V_101 = V_81 ;
return & V_74 -> V_140 ;
V_180:
F_47 ( & V_74 -> V_86 ) ;
V_179:
F_105 ( V_74 -> V_88 ) ;
V_178:
F_105 ( V_74 -> V_96 ) ;
V_177:
F_5 ( & V_74 -> V_4 ) ;
V_176:
F_106 ( V_74 ) ;
return NULL ;
}
static int T_6 F_137 ( void )
{
int V_122 ;
V_122 = F_138 ( & V_181 ) ;
if ( V_122 ) {
F_134 ( L_4 , V_122 ) ;
return - V_9 ;
}
V_122 = F_138 ( & V_182 ) ;
if ( V_122 ) {
F_134 ( L_5 , V_122 ) ;
F_139 ( & V_181 ) ;
return - V_9 ;
}
return 0 ;
}
static void T_7 F_140 ( void )
{
F_139 ( & V_181 ) ;
F_139 ( & V_182 ) ;
}
