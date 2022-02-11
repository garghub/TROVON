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
F_8 ( V_11 -> V_31 ) ;
if ( ! V_11 -> V_20 )
V_23 -> V_15 ++ ;
F_18 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_32 , V_11 ) ;
}
static void F_25 ( struct V_22 * V_23 , struct V_8 * V_11 )
{
F_8 ( V_11 -> V_31 ) ;
if ( ! V_11 -> V_20 )
V_23 -> V_15 ++ ;
F_17 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_32 , V_11 ) ;
}
static void F_26 ( struct V_22 * V_23 , struct V_8 * V_21 , struct V_8 * V_11 )
{
F_8 ( V_11 -> V_31 ) ;
if ( ! V_11 -> V_20 )
V_23 -> V_15 ++ ;
F_19 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_32 , V_21 , V_11 ) ;
}
static void F_27 ( struct V_22 * V_23 , struct V_8 * V_11 )
{
F_20 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_32 , V_11 ) ;
if ( ! V_11 -> V_20 )
V_23 -> V_15 -- ;
}
static struct V_8 * F_28 ( struct V_22 * V_23 , unsigned V_33 , bool V_34 )
{
unsigned V_32 ;
struct V_8 * V_11 ;
V_33 = F_29 ( V_33 , V_23 -> V_24 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
for ( V_11 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_32 ) ; V_11 ; V_11 = F_14 ( V_23 -> V_4 , V_11 ) ) {
if ( V_11 -> V_20 ) {
if ( V_34 )
continue;
else
break;
}
return V_11 ;
}
return NULL ;
}
static struct V_8 * F_30 ( struct V_22 * V_23 )
{
struct V_8 * V_11 = F_28 ( V_23 , V_23 -> V_24 , true ) ;
if ( V_11 )
F_27 ( V_23 , V_11 ) ;
return V_11 ;
}
static struct V_8 * F_31 ( struct V_22 * V_23 , unsigned V_32 )
{
struct V_8 * V_11 ;
for (; V_32 < V_23 -> V_24 ; V_32 ++ )
for ( V_11 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_32 ) ; V_11 ; V_11 = F_14 ( V_23 -> V_4 , V_11 ) )
if ( ! V_11 -> V_20 ) {
F_20 ( V_23 -> V_4 , V_23 -> V_26 + V_11 -> V_32 , V_11 ) ;
return V_11 ;
}
return NULL ;
}
static void F_32 ( struct V_22 * V_23 , unsigned V_15 , unsigned V_35 , unsigned V_36 )
{
unsigned V_32 , V_24 , V_37 , V_38 ;
F_8 ( V_35 > V_36 ) ;
F_8 ( V_36 > V_23 -> V_24 ) ;
V_24 = V_36 - V_35 ;
V_37 = F_1 ( V_15 , V_24 ) ;
V_38 = F_2 ( V_15 , V_24 ) ;
for ( V_32 = V_35 ; V_32 < V_36 ; V_32 ++ )
V_23 -> V_27 [ V_32 ] =
( V_32 < ( V_35 + V_38 ) ) ? V_37 + 1u : V_37 ;
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
unsigned V_39 , V_32 ;
struct V_13 * V_14 , * V_40 ;
struct V_8 * V_11 ;
F_33 ( V_23 ) ;
for ( V_32 = 0u ; V_32 < V_23 -> V_24 - 1u ; V_32 ++ ) {
V_14 = V_23 -> V_26 + V_32 ;
V_39 = V_23 -> V_27 [ V_32 ] ;
while ( V_14 -> V_15 < V_39 ) {
V_11 = F_31 ( V_23 , V_32 + 1u ) ;
if ( ! V_11 ) {
break;
}
V_11 -> V_32 = V_32 ;
F_18 ( V_23 -> V_4 , V_14 , V_11 ) ;
}
V_40 = V_23 -> V_26 + V_32 + 1u ;
while ( V_14 -> V_15 > V_39 ) {
V_11 = F_21 ( V_23 -> V_4 , V_14 ) ;
if ( ! V_11 )
break;
V_11 -> V_32 = V_32 + 1u ;
F_18 ( V_23 -> V_4 , V_40 , V_11 ) ;
}
}
}
static void F_35 ( struct V_22 * V_23 , struct V_8 * V_11 , unsigned V_41 ,
struct V_8 * V_42 , struct V_8 * V_43 )
{
struct V_8 * V_44 ;
unsigned V_45 = 0 ;
unsigned V_46 = F_29 ( V_23 -> V_24 - 1u , V_11 -> V_32 + V_41 ) ;
if ( V_41 && ( V_11 -> V_32 < V_23 -> V_24 - 1u ) ) {
for ( V_44 = F_12 ( V_23 -> V_4 , V_23 -> V_26 + V_46 ) ; V_44 && V_44 -> V_20 ; V_44 = F_14 ( V_23 -> V_4 , V_44 ) )
V_45 ++ ;
if ( V_44 ) {
F_27 ( V_23 , V_44 ) ;
V_44 -> V_32 = V_11 -> V_32 ;
if ( V_42 ) {
switch ( V_45 ) {
case 0 :
F_26 ( V_23 , V_42 , V_44 ) ;
break;
case 1 :
F_26 ( V_23 , V_43 , V_44 ) ;
break;
default:
F_24 ( V_23 , V_44 ) ;
}
} else
F_24 ( V_23 , V_44 ) ;
}
}
F_27 ( V_23 , V_11 ) ;
V_11 -> V_32 = V_46 ;
F_24 ( V_23 , V_11 ) ;
}
static void F_36 ( struct V_47 * V_48 , unsigned V_24 )
{
V_48 -> V_49 = ( V_24 * 3u ) / 4u ;
V_48 -> V_50 = 0u ;
V_48 -> V_51 = 0u ;
}
static void F_37 ( struct V_47 * V_48 )
{
V_48 -> V_50 = V_48 -> V_51 = 0u ;
}
static void F_38 ( struct V_47 * V_48 , unsigned V_32 )
{
if ( V_32 >= V_48 -> V_49 )
V_48 -> V_50 ++ ;
else
V_48 -> V_51 ++ ;
}
static void F_39 ( struct V_47 * V_48 )
{
V_48 -> V_51 ++ ;
}
static enum V_52 F_40 ( struct V_47 * V_48 )
{
unsigned V_53 = F_1 ( V_48 -> V_50 << V_54 , V_48 -> V_50 + V_48 -> V_51 ) ;
if ( V_53 < V_55 )
return V_56 ;
else if ( V_53 < V_57 )
return V_58 ;
else
return V_59 ;
}
static int F_41 ( struct V_60 * V_61 , struct V_3 * V_4 , unsigned V_5 )
{
unsigned V_25 , V_62 ;
V_61 -> V_4 = V_4 ;
V_62 = F_42 ( F_43 ( V_5 / 4u , 16u ) ) ;
V_61 -> V_63 = F_44 ( V_62 ) ;
V_61 -> V_64 = F_45 ( sizeof( * V_61 -> V_64 ) * V_62 ) ;
if ( ! V_61 -> V_64 )
return - V_9 ;
for ( V_25 = 0 ; V_25 < V_62 ; V_25 ++ )
V_61 -> V_64 [ V_25 ] = V_12 ;
return 0 ;
}
static void F_46 ( struct V_60 * V_61 )
{
F_6 ( V_61 -> V_64 ) ;
}
static struct V_8 * F_47 ( struct V_60 * V_61 , unsigned V_65 )
{
return F_10 ( V_61 -> V_4 , V_61 -> V_64 [ V_65 ] ) ;
}
static struct V_8 * F_48 ( struct V_60 * V_61 , struct V_8 * V_11 )
{
return F_10 ( V_61 -> V_4 , V_11 -> V_66 ) ;
}
static void F_49 ( struct V_60 * V_61 , unsigned V_65 , struct V_8 * V_11 )
{
V_11 -> V_66 = V_61 -> V_64 [ V_65 ] ;
V_61 -> V_64 [ V_65 ] = F_9 ( V_61 -> V_4 , V_11 ) ;
}
static void F_50 ( struct V_60 * V_61 , struct V_8 * V_11 )
{
unsigned V_67 = F_51 ( F_52 ( V_11 -> V_68 ) , V_61 -> V_63 ) ;
F_49 ( V_61 , V_67 , V_11 ) ;
}
static struct V_8 * F_53 ( struct V_60 * V_61 , unsigned V_67 , T_1 V_68 ,
struct V_8 * * V_19 )
{
struct V_8 * V_11 ;
* V_19 = NULL ;
for ( V_11 = F_47 ( V_61 , V_67 ) ; V_11 ; V_11 = F_48 ( V_61 , V_11 ) ) {
if ( V_11 -> V_68 == V_68 )
return V_11 ;
* V_19 = V_11 ;
}
return NULL ;
}
static void F_54 ( struct V_60 * V_61 , unsigned V_67 ,
struct V_8 * V_11 , struct V_8 * V_19 )
{
if ( V_19 )
V_19 -> V_66 = V_11 -> V_66 ;
else
V_61 -> V_64 [ V_67 ] = V_11 -> V_66 ;
}
static struct V_8 * F_55 ( struct V_60 * V_61 , T_1 V_68 )
{
struct V_8 * V_11 , * V_19 ;
unsigned V_67 = F_51 ( F_52 ( V_68 ) , V_61 -> V_63 ) ;
V_11 = F_53 ( V_61 , V_67 , V_68 , & V_19 ) ;
if ( V_11 && V_19 ) {
F_54 ( V_61 , V_67 , V_11 , V_19 ) ;
F_49 ( V_61 , V_67 , V_11 ) ;
}
return V_11 ;
}
static void F_56 ( struct V_60 * V_61 , struct V_8 * V_11 )
{
unsigned V_67 = F_51 ( F_52 ( V_11 -> V_68 ) , V_61 -> V_63 ) ;
struct V_8 * V_19 ;
V_11 = F_53 ( V_61 , V_67 , V_11 -> V_68 , & V_19 ) ;
if ( V_11 )
F_54 ( V_61 , V_67 , V_11 , V_19 ) ;
}
static void F_57 ( struct V_69 * V_70 , struct V_3 * V_4 ,
unsigned V_6 , unsigned V_7 )
{
unsigned V_25 ;
V_70 -> V_4 = V_4 ;
V_70 -> V_71 = 0u ;
V_70 -> V_6 = V_6 ;
F_11 ( & V_70 -> free ) ;
for ( V_25 = V_6 ; V_25 != V_7 ; V_25 ++ )
F_18 ( V_70 -> V_4 , & V_70 -> free , F_7 ( V_70 -> V_4 , V_25 ) ) ;
}
static void F_58 ( struct V_8 * V_11 )
{
V_11 -> V_66 = V_12 ;
V_11 -> V_18 = V_12 ;
V_11 -> V_19 = V_12 ;
V_11 -> V_32 = 0u ;
V_11 -> V_72 = true ;
V_11 -> V_73 = true ;
V_11 -> V_20 = false ;
V_11 -> V_31 = false ;
}
static struct V_8 * F_59 ( struct V_69 * V_70 )
{
struct V_8 * V_11 ;
if ( F_16 ( & V_70 -> free ) )
return NULL ;
V_11 = F_21 ( V_70 -> V_4 , & V_70 -> free ) ;
F_58 ( V_11 ) ;
V_70 -> V_71 ++ ;
return V_11 ;
}
static struct V_8 * F_60 ( struct V_69 * V_70 , unsigned V_25 )
{
struct V_8 * V_11 = F_7 ( V_70 -> V_4 , V_70 -> V_6 + V_25 ) ;
F_8 ( V_11 -> V_73 ) ;
F_20 ( V_70 -> V_4 , & V_70 -> free , V_11 ) ;
F_58 ( V_11 ) ;
V_70 -> V_71 ++ ;
return V_11 ;
}
static void F_61 ( struct V_69 * V_70 , struct V_8 * V_11 )
{
F_8 ( ! V_70 -> V_71 ) ;
F_8 ( ! V_11 -> V_73 ) ;
V_70 -> V_71 -- ;
V_11 -> V_73 = false ;
F_18 ( V_70 -> V_4 , & V_70 -> free , V_11 ) ;
}
static bool F_62 ( struct V_69 * V_70 )
{
return F_16 ( & V_70 -> free ) ;
}
static unsigned F_63 ( struct V_69 * V_70 , struct V_8 * V_11 )
{
return F_9 ( V_70 -> V_4 , V_11 ) - V_70 -> V_6 ;
}
static struct V_8 * F_64 ( struct V_69 * V_70 , unsigned V_74 )
{
return F_7 ( V_70 -> V_4 , V_70 -> V_6 + V_74 ) ;
}
static struct V_8 * F_65 ( struct V_69 * V_70 , unsigned V_32 , bool V_75 )
{
return F_64 ( V_70 , V_75 ? V_32 : V_76 + V_32 ) ;
}
static struct V_8 * F_66 ( struct V_77 * V_78 , unsigned V_32 )
{
return F_65 ( & V_78 -> V_79 , V_32 , V_78 -> V_80 ) ;
}
static struct V_8 * F_67 ( struct V_77 * V_78 , unsigned V_32 )
{
return F_65 ( & V_78 -> V_81 , V_32 , V_78 -> V_82 ) ;
}
static void F_68 ( struct V_77 * V_78 )
{
unsigned V_32 ;
struct V_22 * V_23 = & V_78 -> V_72 ;
struct V_8 * V_20 ;
for ( V_32 = 0 ; V_32 < V_23 -> V_24 ; V_32 ++ ) {
V_20 = F_66 ( V_78 , V_32 ) ;
F_27 ( V_23 , V_20 ) ;
F_24 ( V_23 , V_20 ) ;
}
}
static void F_69 ( struct V_77 * V_78 )
{
unsigned V_32 ;
struct V_22 * V_23 = & V_78 -> V_83 ;
struct V_8 * V_20 ;
for ( V_32 = 0 ; V_32 < V_23 -> V_24 ; V_32 ++ ) {
V_20 = F_67 ( V_78 , V_32 ) ;
F_27 ( V_23 , V_20 ) ;
F_24 ( V_23 , V_20 ) ;
}
}
static void F_70 ( struct V_77 * V_78 )
{
if ( F_71 ( V_84 , V_78 -> V_85 ) ) {
V_78 -> V_85 = V_84 + V_86 ;
V_78 -> V_80 = ! V_78 -> V_80 ;
F_68 ( V_78 ) ;
}
if ( F_71 ( V_84 , V_78 -> V_87 ) ) {
V_78 -> V_87 = V_84 + V_88 ;
V_78 -> V_82 = ! V_78 -> V_82 ;
F_69 ( V_78 ) ;
}
}
static void F_72 ( struct V_77 * V_78 )
{
unsigned V_32 ;
struct V_8 * V_20 ;
for ( V_32 = 0 ; V_32 < V_76 ; V_32 ++ ) {
V_20 = F_66 ( V_78 , V_32 ) ;
V_20 -> V_32 = V_32 ;
F_24 ( & V_78 -> V_72 , V_20 ) ;
V_20 = F_67 ( V_78 , V_32 ) ;
V_20 -> V_32 = V_32 ;
F_24 ( & V_78 -> V_83 , V_20 ) ;
}
}
static void F_73 ( struct V_77 * V_78 )
{
V_78 -> V_85 = V_84 + V_86 ;
V_78 -> V_87 = V_84 + V_88 ;
V_78 -> V_80 = false ;
V_78 -> V_82 = false ;
F_72 ( V_78 ) ;
V_78 -> V_80 = ! V_78 -> V_80 ;
V_78 -> V_82 = ! V_78 -> V_82 ;
F_72 ( V_78 ) ;
}
static void F_74 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
F_27 ( V_11 -> V_72 ? & V_78 -> V_72 : & V_78 -> V_83 , V_11 ) ;
}
static void F_75 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
if ( V_11 -> V_72 )
F_24 ( & V_78 -> V_72 , V_11 ) ;
else
F_24 ( & V_78 -> V_83 , V_11 ) ;
}
static void F_76 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
F_50 ( & V_78 -> V_89 , V_11 ) ;
if ( ! V_11 -> V_31 )
F_75 ( V_78 , V_11 ) ;
}
static void F_77 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
if ( V_11 -> V_72 )
F_25 ( & V_78 -> V_72 , V_11 ) ;
else
F_25 ( & V_78 -> V_83 , V_11 ) ;
}
static void F_78 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
F_50 ( & V_78 -> V_89 , V_11 ) ;
if ( ! V_11 -> V_31 )
F_77 ( V_78 , V_11 ) ;
}
static T_2 F_79 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
return F_80 ( F_63 ( & V_78 -> V_90 , V_11 ) ) ;
}
static void F_81 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
if ( V_11 -> V_31 )
return;
if ( ! F_82 ( F_83 ( F_79 ( V_78 , V_11 ) ) , V_78 -> V_91 ) ) {
if ( ! V_11 -> V_72 ) {
F_35 ( & V_78 -> V_83 , V_11 , 1u , NULL , NULL ) ;
return;
}
F_35 ( & V_78 -> V_72 , V_11 , 1u ,
F_65 ( & V_78 -> V_79 , V_11 -> V_32 , ! V_78 -> V_80 ) ,
F_65 ( & V_78 -> V_79 , V_11 -> V_32 , V_78 -> V_80 ) ) ;
}
}
static unsigned F_84 ( struct V_77 * V_78 )
{
static unsigned V_89 [] = { 1 , 1 , 1 , 2 , 4 , 6 , 7 , 8 , 7 , 6 , 4 , 4 , 3 , 3 , 2 , 2 , 1 } ;
unsigned V_50 = V_78 -> V_92 . V_50 ;
unsigned V_51 = V_78 -> V_92 . V_51 ;
unsigned V_74 = F_1 ( V_50 << 4u , V_50 + V_51 ) ;
return V_89 [ V_74 ] ;
}
static void F_85 ( struct V_77 * V_78 )
{
unsigned V_93 = F_62 ( & V_78 -> V_90 ) ?
F_84 ( V_78 ) : ( V_94 / 2u ) ;
V_93 = F_43 ( V_93 , V_94 ) ;
switch ( F_40 ( & V_78 -> V_95 ) ) {
case V_56 :
V_93 /= 4u ;
break;
case V_58 :
V_93 /= 2u ;
break;
case V_59 :
break;
}
V_78 -> V_96 = V_94 - V_93 ;
V_78 -> V_97 = ( V_94 - V_93 ) ;
}
static void F_86 ( struct V_77 * V_78 )
{
switch ( F_40 ( & V_78 -> V_95 ) ) {
case V_56 :
V_78 -> V_98 = 4u ;
break;
case V_58 :
V_78 -> V_98 = 2u ;
break;
case V_59 :
V_78 -> V_98 = 1u ;
break;
}
}
static void F_87 ( struct V_77 * V_78 )
{
F_88 ( V_78 -> V_99 , V_78 -> V_100 ) ;
F_85 ( V_78 ) ;
if ( F_71 ( V_84 , V_78 -> V_101 ) ) {
F_86 ( V_78 ) ;
F_34 ( & V_78 -> V_102 ) ;
F_37 ( & V_78 -> V_95 ) ;
V_78 -> V_101 = V_84 + V_103 ;
}
}
static void F_89 ( struct V_77 * V_78 )
{
if ( F_71 ( V_84 , V_78 -> V_104 ) ) {
F_88 ( V_78 -> V_91 , F_83 ( V_78 -> V_105 ) ) ;
F_34 ( & V_78 -> V_72 ) ;
F_34 ( & V_78 -> V_83 ) ;
F_37 ( & V_78 -> V_92 ) ;
V_78 -> V_104 = V_84 + V_106 ;
}
}
static unsigned F_90 ( struct V_77 * V_78 , unsigned V_107 )
{
return F_83 ( V_78 -> V_105 ) * V_107 / 100u ;
}
static bool F_91 ( struct V_77 * V_78 , bool V_108 )
{
if ( V_108 ) {
return F_23 ( & V_78 -> V_72 ) == 0u ;
}
return true ;
}
static bool F_92 ( struct V_77 * V_78 )
{
unsigned V_109 ;
V_109 = F_83 ( V_78 -> V_105 ) - V_78 -> V_90 . V_71 ;
return ( V_109 + F_93 ( V_78 -> V_110 ) ) >=
F_90 ( V_78 , V_111 ) ;
}
static void F_94 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
F_8 ( V_11 -> V_20 ) ;
F_8 ( ! V_11 -> V_73 ) ;
F_8 ( V_11 -> V_31 ) ;
V_11 -> V_31 = true ;
}
static void F_95 ( struct V_77 * V_78 , struct V_8 * V_11 )
{
F_8 ( ! V_11 -> V_31 ) ;
V_11 -> V_31 = false ;
}
static void F_96 ( struct V_77 * V_78 )
{
int V_112 ;
struct V_113 V_114 ;
struct V_8 * V_11 ;
V_11 = F_28 ( & V_78 -> V_72 , V_78 -> V_72 . V_24 , ! V_78 -> V_115 ) ;
if ( V_11 ) {
F_94 ( V_78 , V_11 ) ;
F_27 ( & V_78 -> V_72 , V_11 ) ;
V_114 . V_116 = V_117 ;
V_114 . V_68 = V_11 -> V_68 ;
V_114 . V_118 = F_79 ( V_78 , V_11 ) ;
V_112 = F_97 ( V_78 -> V_110 , & V_114 , NULL ) ;
F_98 ( V_112 ) ;
}
}
static void F_99 ( struct V_77 * V_78 )
{
struct V_113 V_114 ;
struct V_8 * V_11 ;
if ( F_100 ( F_98 ( ! V_78 -> V_115 ) ) )
return;
V_11 = F_28 ( & V_78 -> V_83 , V_78 -> V_83 . V_24 / 2 , true ) ;
if ( ! V_11 ) {
if ( ! F_91 ( V_78 , true ) )
F_96 ( V_78 ) ;
return;
}
F_94 ( V_78 , V_11 ) ;
F_27 ( & V_78 -> V_83 , V_11 ) ;
V_114 . V_116 = V_119 ;
V_114 . V_68 = V_11 -> V_68 ;
V_114 . V_118 = F_79 ( V_78 , V_11 ) ;
F_97 ( V_78 -> V_110 , & V_114 , NULL ) ;
}
static void F_101 ( struct V_77 * V_78 , T_1 V_68 ,
struct V_113 * * V_120 )
{
struct V_8 * V_11 ;
struct V_113 V_114 ;
if ( ! V_78 -> V_115 )
return;
if ( F_62 ( & V_78 -> V_90 ) ) {
if ( ! F_92 ( V_78 ) )
F_99 ( V_78 ) ;
return;
}
if ( F_102 ( V_78 -> V_110 , V_68 ) )
return;
V_11 = F_59 ( & V_78 -> V_90 ) ;
F_8 ( ! V_11 ) ;
V_11 -> V_31 = true ;
V_114 . V_116 = V_121 ;
V_114 . V_68 = V_68 ;
V_114 . V_118 = F_79 ( V_78 , V_11 ) ;
F_97 ( V_78 -> V_110 , & V_114 , V_120 ) ;
}
static enum V_122 F_103 ( bool V_123 )
{
return V_123 ? V_124 : V_125 ;
}
static enum V_122 F_104 ( struct V_77 * V_78 , struct V_8 * V_126 ,
int V_127 , bool V_128 )
{
if ( V_127 == V_129 ) {
if ( ! F_62 ( & V_78 -> V_90 ) && V_128 )
return V_130 ;
return F_103 ( V_126 -> V_32 >= V_78 -> V_97 ) ;
} else
return F_103 ( V_126 -> V_32 >= V_78 -> V_96 ) ;
}
static T_1 F_105 ( struct V_77 * V_78 , T_1 V_131 )
{
T_3 V_112 = F_52 ( V_131 ) ;
( void ) F_106 ( V_112 , V_78 -> V_132 ) ;
return F_107 ( V_112 ) ;
}
static struct V_8 * F_108 ( struct V_77 * V_78 , T_1 V_131 )
{
unsigned V_133 ;
T_1 V_134 = F_105 ( V_78 , V_131 ) ;
struct V_8 * V_11 = F_55 ( & V_78 -> V_135 , V_134 ) ;
if ( V_11 ) {
F_38 ( & V_78 -> V_95 , V_11 -> V_32 ) ;
V_133 = F_63 ( & V_78 -> V_136 , V_11 ) ;
F_35 ( & V_78 -> V_102 , V_11 ,
F_82 ( V_133 , V_78 -> V_99 ) ?
0u : V_78 -> V_98 ,
NULL , NULL ) ;
} else {
F_39 ( & V_78 -> V_95 ) ;
V_11 = F_59 ( & V_78 -> V_136 ) ;
if ( ! V_11 ) {
V_11 = F_30 ( & V_78 -> V_102 ) ;
if ( V_11 ) {
F_56 ( & V_78 -> V_135 , V_11 ) ;
V_133 = F_63 ( & V_78 -> V_136 , V_11 ) ;
F_109 ( V_133 , V_78 -> V_99 ) ;
}
}
if ( V_11 ) {
V_11 -> V_68 = V_134 ;
F_24 ( & V_78 -> V_102 , V_11 ) ;
F_50 ( & V_78 -> V_135 , V_11 ) ;
}
}
return V_11 ;
}
static struct V_77 * F_110 ( struct V_137 * V_107 )
{
return F_111 ( V_107 , struct V_77 , V_138 ) ;
}
static void F_112 ( struct V_137 * V_107 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_113 ( V_78 -> V_110 ) ;
F_46 ( & V_78 -> V_135 ) ;
F_46 ( & V_78 -> V_89 ) ;
F_114 ( V_78 -> V_99 ) ;
F_114 ( V_78 -> V_91 ) ;
F_5 ( & V_78 -> V_4 ) ;
F_115 ( V_78 ) ;
}
static int F_116 ( struct V_77 * V_78 , T_1 V_68 , T_2 * V_118 ,
int V_127 , bool V_139 ,
struct V_113 * * V_114 , bool * V_140 )
{
struct V_8 * V_11 , * V_126 ;
enum V_122 V_141 ;
* V_140 = false ;
V_11 = F_55 ( & V_78 -> V_89 , V_68 ) ;
if ( V_11 ) {
F_38 ( & V_78 -> V_92 , V_11 -> V_32 ) ;
F_81 ( V_78 , V_11 ) ;
* V_118 = F_79 ( V_78 , V_11 ) ;
return 0 ;
} else {
F_39 ( & V_78 -> V_92 ) ;
V_126 = F_108 ( V_78 , V_68 ) ;
V_141 = F_104 ( V_78 , V_126 , V_127 , V_139 ) ;
if ( V_141 != V_125 ) {
F_101 ( V_78 , V_68 , V_114 ) ;
* V_140 = true ;
}
return - V_142 ;
}
}
static int F_117 ( struct V_137 * V_107 , T_1 V_68 , T_2 * V_118 ,
int V_127 , bool V_139 ,
bool * V_140 )
{
int V_112 ;
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
V_112 = F_116 ( V_78 , V_68 , V_118 ,
V_127 , V_139 ,
NULL , V_140 ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
return V_112 ;
}
static int F_120 ( struct V_137 * V_107 ,
T_1 V_68 , T_2 * V_118 ,
int V_127 , bool V_139 ,
struct V_113 * * V_114 )
{
int V_112 ;
bool V_145 ;
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
V_112 = F_116 ( V_78 , V_68 , V_118 , V_127 , V_139 , V_114 , & V_145 ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
return V_112 ;
}
static int F_121 ( struct V_137 * V_107 , bool V_108 ,
struct V_113 * * V_146 )
{
int V_112 ;
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
V_112 = F_122 ( V_78 -> V_110 , V_146 ) ;
if ( V_112 == - V_147 ) {
if ( ! F_91 ( V_78 , V_108 ) ) {
F_96 ( V_78 ) ;
V_112 = F_122 ( V_78 -> V_110 , V_146 ) ;
}
}
F_119 ( & V_78 -> V_144 , V_143 ) ;
return V_112 ;
}
static void F_123 ( struct V_77 * V_78 ,
struct V_113 * V_114 ,
bool V_148 )
{
struct V_8 * V_11 = F_64 ( & V_78 -> V_90 ,
F_83 ( V_114 -> V_118 ) ) ;
switch ( V_114 -> V_116 ) {
case V_121 :
F_95 ( V_78 , V_11 ) ;
if ( V_148 ) {
V_11 -> V_68 = V_114 -> V_68 ;
V_11 -> V_32 = V_76 - 1 ;
F_76 ( V_78 , V_11 ) ;
} else {
F_61 ( & V_78 -> V_90 , V_11 ) ;
}
break;
case V_119 :
if ( V_148 ) {
F_56 ( & V_78 -> V_89 , V_11 ) ;
F_61 ( & V_78 -> V_90 , V_11 ) ;
} else {
F_95 ( V_78 , V_11 ) ;
F_75 ( V_78 , V_11 ) ;
}
break;
case V_117 :
F_95 ( V_78 , V_11 ) ;
F_75 ( V_78 , V_11 ) ;
break;
}
F_124 ( V_78 -> V_110 , V_114 ) ;
}
static void F_125 ( struct V_137 * V_107 ,
struct V_113 * V_114 ,
bool V_148 )
{
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
F_123 ( V_78 , V_114 , V_148 ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
}
static void F_126 ( struct V_77 * V_78 , T_2 V_118 , bool V_149 )
{
struct V_8 * V_11 = F_64 ( & V_78 -> V_90 , F_83 ( V_118 ) ) ;
if ( V_11 -> V_31 )
V_11 -> V_72 = V_149 ;
else {
F_74 ( V_78 , V_11 ) ;
V_11 -> V_72 = V_149 ;
F_75 ( V_78 , V_11 ) ;
}
}
static void F_127 ( struct V_137 * V_107 , T_2 V_118 )
{
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
F_126 ( V_78 , V_118 , true ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
}
static void F_128 ( struct V_137 * V_107 , T_2 V_118 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
unsigned long V_143 ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
F_126 ( V_78 , V_118 , false ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
}
static unsigned F_129 ( T_2 V_118 )
{
return F_130 ( F_83 ( V_118 ) , 9 ) & ( V_76 - 1 ) ;
}
static int F_131 ( struct V_137 * V_107 ,
T_1 V_68 , T_2 V_118 ,
bool V_72 , T_4 V_150 , bool V_151 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
struct V_8 * V_11 ;
V_11 = F_60 ( & V_78 -> V_90 , F_83 ( V_118 ) ) ;
V_11 -> V_68 = V_68 ;
V_11 -> V_72 = V_72 ;
V_11 -> V_32 = V_151 ? F_29 ( V_150 , V_76 - 1 ) : F_129 ( V_118 ) ;
V_11 -> V_31 = false ;
F_78 ( V_78 , V_11 ) ;
return 0 ;
}
static int F_132 ( struct V_137 * V_107 , T_2 V_118 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
struct V_8 * V_11 = F_64 ( & V_78 -> V_90 , F_83 ( V_118 ) ) ;
if ( ! V_11 -> V_73 )
return - V_147 ;
F_74 ( V_78 , V_11 ) ;
F_56 ( & V_78 -> V_89 , V_11 ) ;
F_61 ( & V_78 -> V_90 , V_11 ) ;
return 0 ;
}
static T_4 F_133 ( struct V_137 * V_107 , T_2 V_118 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
struct V_8 * V_11 = F_64 ( & V_78 -> V_90 , F_83 ( V_118 ) ) ;
if ( ! V_11 -> V_73 )
return 0 ;
return V_11 -> V_32 ;
}
static T_2 F_134 ( struct V_137 * V_107 )
{
T_2 V_112 ;
unsigned long V_143 ;
struct V_77 * V_78 = F_110 ( V_107 ) ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
V_112 = F_80 ( V_78 -> V_90 . V_71 ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
return V_112 ;
}
static void F_135 ( struct V_137 * V_107 , bool V_152 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
unsigned long V_143 ;
F_118 ( & V_78 -> V_144 , V_143 ) ;
V_78 -> V_153 ++ ;
F_70 ( V_78 ) ;
F_87 ( V_78 ) ;
F_89 ( V_78 ) ;
F_119 ( & V_78 -> V_144 , V_143 ) ;
}
static void F_136 ( struct V_137 * V_107 , bool V_154 )
{
struct V_77 * V_78 = F_110 ( V_107 ) ;
V_78 -> V_115 = V_154 ;
}
static int F_137 ( struct V_137 * V_107 ,
const char * V_155 , const char * V_156 )
{
unsigned long V_157 ;
if ( F_138 ( V_156 , 10 , & V_157 ) )
return - V_158 ;
if ( ! strcasecmp ( V_155 , L_1 ) ||
! strcasecmp ( V_155 , L_2 ) ||
! strcasecmp ( V_155 , L_3 ) ||
! strcasecmp ( V_155 , L_4 ) ||
! strcasecmp ( V_155 , L_5 ) ) {
F_139 ( L_6 , V_155 ) ;
return 0 ;
}
return - V_158 ;
}
static int F_140 ( struct V_137 * V_107 , char * V_146 ,
unsigned V_159 , T_5 * V_160 )
{
T_5 V_161 = * V_160 ;
F_141 ( L_7
L_8
L_9
L_10
L_11 ) ;
* V_160 = V_161 ;
return 0 ;
}
static void F_142 ( struct V_77 * V_78 , bool V_162 )
{
V_78 -> V_138 . V_163 = F_112 ;
V_78 -> V_138 . V_164 = F_117 ;
V_78 -> V_138 . V_165 = F_120 ;
V_78 -> V_138 . V_166 = F_121 ;
V_78 -> V_138 . V_167 = F_125 ;
V_78 -> V_138 . V_168 = F_127 ;
V_78 -> V_138 . V_169 = F_128 ;
V_78 -> V_138 . V_170 = F_131 ;
V_78 -> V_138 . V_171 = F_132 ;
V_78 -> V_138 . V_172 = F_133 ;
V_78 -> V_138 . V_173 = F_134 ;
V_78 -> V_138 . V_153 = F_135 ;
V_78 -> V_138 . V_174 = F_136 ;
if ( V_162 ) {
V_78 -> V_138 . V_175 = F_137 ;
V_78 -> V_138 . V_176 = F_140 ;
}
}
static bool F_143 ( T_3 V_177 ,
T_3 V_178 ,
unsigned V_100 )
{
return ( V_178 * V_100 ) > V_177 ;
}
static void F_144 ( T_3 V_177 ,
T_3 V_179 ,
unsigned V_180 ,
T_3 * V_178 ,
unsigned * V_100 )
{
* V_178 = V_179 * 16u ;
* V_100 = F_43 ( V_180 / 4u , 1024u ) ;
while ( ( * V_178 > V_179 ) &&
F_143 ( V_177 , * V_178 , * V_100 ) )
* V_178 /= 2u ;
}
static struct V_137 * F_145 ( T_2 V_105 ,
T_3 V_177 ,
T_3 V_179 ,
bool V_162 ,
bool V_115 )
{
unsigned V_25 ;
unsigned V_181 = 2u * V_76 ;
unsigned V_182 = 2u * V_181 ;
struct V_77 * V_78 = F_146 ( sizeof( * V_78 ) , V_183 ) ;
if ( ! V_78 )
return NULL ;
F_142 ( V_78 , V_162 ) ;
V_78 -> V_105 = V_105 ;
V_78 -> V_179 = V_179 ;
F_144 ( V_177 , V_179 , F_83 ( V_105 ) ,
& V_78 -> V_178 , & V_78 -> V_100 ) ;
V_78 -> V_132 = F_147 ( V_78 -> V_178 , V_78 -> V_179 ) ;
V_78 -> V_98 = 1u ;
if ( F_3 ( & V_78 -> V_4 , V_182 + V_78 -> V_100 + F_83 ( V_105 ) ) ) {
F_148 ( L_12 ) ;
goto V_184;
}
F_57 ( & V_78 -> V_79 , & V_78 -> V_4 , 0 , V_181 ) ;
for ( V_25 = 0 ; V_25 < V_181 ; V_25 ++ )
F_64 ( & V_78 -> V_79 , V_25 ) -> V_20 = true ;
F_57 ( & V_78 -> V_81 , & V_78 -> V_4 , V_181 , V_182 ) ;
for ( V_25 = 0 ; V_25 < V_181 ; V_25 ++ )
F_64 ( & V_78 -> V_81 , V_25 ) -> V_20 = true ;
F_57 ( & V_78 -> V_136 , & V_78 -> V_4 , V_182 ,
V_182 + V_78 -> V_100 ) ;
F_57 ( & V_78 -> V_90 , & V_78 -> V_4 ,
V_182 + V_78 -> V_100 ,
V_182 + V_78 -> V_100 + F_83 ( V_105 ) ) ;
V_78 -> V_99 = F_149 ( V_78 -> V_100 ) ;
if ( ! V_78 -> V_99 ) {
F_148 ( L_13 ) ;
goto V_185;
}
F_88 ( V_78 -> V_99 , V_78 -> V_100 ) ;
if ( F_83 ( V_105 ) ) {
V_78 -> V_91 = F_149 ( F_83 ( V_105 ) ) ;
if ( ! V_78 -> V_91 ) {
F_148 ( L_14 ) ;
goto V_186;
}
F_88 ( V_78 -> V_91 , F_83 ( V_78 -> V_105 ) ) ;
} else
V_78 -> V_91 = NULL ;
V_78 -> V_153 = 0 ;
F_150 ( & V_78 -> V_144 ) ;
F_22 ( & V_78 -> V_102 , & V_78 -> V_4 , V_94 ) ;
V_78 -> V_102 . V_29 = 8 ;
V_78 -> V_102 . V_30 = F_29 ( V_78 -> V_100 / V_94 ,
F_83 ( V_78 -> V_105 ) / V_78 -> V_132 ) ;
F_22 ( & V_78 -> V_83 , & V_78 -> V_4 , V_76 ) ;
F_22 ( & V_78 -> V_72 , & V_78 -> V_4 , V_76 ) ;
F_36 ( & V_78 -> V_95 , V_94 ) ;
F_36 ( & V_78 -> V_92 , V_76 ) ;
if ( F_41 ( & V_78 -> V_89 , & V_78 -> V_4 , F_83 ( V_105 ) ) )
goto V_187;
if ( F_41 ( & V_78 -> V_135 , & V_78 -> V_4 , V_78 -> V_100 ) )
goto V_188;
F_73 ( V_78 ) ;
V_78 -> V_97 = V_78 -> V_96 = V_94 ;
V_78 -> V_101 = V_84 ;
V_78 -> V_104 = V_84 ;
V_78 -> V_110 = F_151 ( 10240 ) ;
if ( ! V_78 -> V_110 )
goto V_189;
V_78 -> V_115 = V_115 ;
return & V_78 -> V_138 ;
V_189:
F_46 ( & V_78 -> V_135 ) ;
V_188:
F_46 ( & V_78 -> V_89 ) ;
V_187:
F_114 ( V_78 -> V_91 ) ;
V_186:
F_114 ( V_78 -> V_99 ) ;
V_185:
F_5 ( & V_78 -> V_4 ) ;
V_184:
F_115 ( V_78 ) ;
return NULL ;
}
static struct V_137 * F_152 ( T_2 V_105 ,
T_3 V_177 ,
T_3 V_179 )
{
return F_145 ( V_105 , V_177 , V_179 , false , true ) ;
}
static struct V_137 * F_153 ( T_2 V_105 ,
T_3 V_177 ,
T_3 V_179 )
{
return F_145 ( V_105 , V_177 , V_179 , true , true ) ;
}
static struct V_137 * F_154 ( T_2 V_105 ,
T_3 V_177 ,
T_3 V_179 )
{
return F_145 ( V_105 , V_177 , V_179 , false , false ) ;
}
static int T_6 F_155 ( void )
{
int V_112 ;
V_112 = F_156 ( & V_190 ) ;
if ( V_112 ) {
F_148 ( L_15 , V_112 ) ;
return - V_9 ;
}
V_112 = F_156 ( & V_191 ) ;
if ( V_112 ) {
F_148 ( L_16 , V_112 ) ;
goto V_192;
}
V_112 = F_156 ( & V_193 ) ;
if ( V_112 ) {
F_148 ( L_17 , V_112 ) ;
goto V_194;
}
V_112 = F_156 ( & V_195 ) ;
if ( V_112 ) {
F_148 ( L_18 , V_112 ) ;
goto V_196;
}
return 0 ;
V_196:
F_157 ( & V_193 ) ;
V_194:
F_157 ( & V_191 ) ;
V_192:
F_157 ( & V_190 ) ;
return - V_9 ;
}
static void T_7 F_158 ( void )
{
F_157 ( & V_193 ) ;
F_157 ( & V_190 ) ;
F_157 ( & V_191 ) ;
F_157 ( & V_195 ) ;
}
