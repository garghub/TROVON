static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
if ( V_2 -> V_5 && F_2 ( V_4 , V_2 -> V_6 ) ) {
V_2 -> V_5 [ V_3 ] = V_2 -> V_5 [ V_4 ] ;
V_2 -> V_5 [ V_3 ] . V_7 = 0 ;
V_2 -> V_6 [ F_3 ( V_3 ) ] |= F_4 ( V_3 ) ;
}
}
int F_5 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 ;
if ( ! V_8 )
return 0 ;
if ( V_11 )
return V_11 -> V_8 != V_8 ? - V_13 : 0 ;
V_11 = F_6 ( sizeof( * V_11 ) + V_8 * sizeof( * V_11 -> V_14 ) , V_15 ) ;
if ( ! V_11 )
goto V_16;
V_11 -> V_8 = V_8 ;
V_11 -> V_9 = V_9 ;
F_7 ( V_2 , V_17 , 0 , V_8 - 1 , 0 , 0 ) ;
F_7 ( V_2 , V_18 , 0 , V_19 , 0 , 0 ) ;
if ( V_9 & ( V_20 | V_21 ) ) {
F_8 ( V_22 , V_2 -> V_23 ) ;
F_8 ( V_24 , V_2 -> V_25 ) ;
F_1 ( V_2 , V_26 , V_27 ) ;
F_1 ( V_2 , V_28 , V_29 ) ;
F_1 ( V_2 , V_30 , V_31 ) ;
}
if ( V_9 & V_20 ) {
F_8 ( V_32 , V_2 -> V_25 ) ;
F_8 ( V_33 , V_2 -> V_25 ) ;
if ( V_8 >= 3 )
F_8 ( V_34 , V_2 -> V_25 ) ;
if ( V_8 >= 4 )
F_8 ( V_35 , V_2 -> V_25 ) ;
if ( V_8 >= 5 )
F_8 ( V_36 , V_2 -> V_25 ) ;
F_8 ( V_37 , V_2 -> V_38 ) ;
}
if ( V_9 & V_21 )
F_8 ( V_39 , V_2 -> V_38 ) ;
if ( V_9 & V_40 )
F_8 ( V_41 , V_2 -> V_38 ) ;
if ( V_9 & V_42 ) {
unsigned int V_43 = V_8 * V_8 ;
V_11 -> V_44 = F_9 ( V_43 , sizeof( * V_11 -> V_44 ) , V_15 ) ;
if ( ! V_11 -> V_44 )
goto V_16;
}
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
F_10 ( & V_11 -> V_14 [ V_12 ] , V_18 , - 1 ) ;
V_2 -> V_11 = V_11 ;
return 0 ;
V_16:
F_11 ( V_11 ) ;
return - V_45 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 ) {
F_11 ( V_2 -> V_11 -> V_44 ) ;
F_11 ( V_2 -> V_11 ) ;
}
V_2 -> V_11 = NULL ;
}
void F_13 ( struct V_1 * V_2 ,
unsigned int V_46 , bool V_47 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_48 * V_49 ;
int V_50 ;
if ( ! V_11 )
return;
V_49 = & V_11 -> V_14 [ V_11 -> V_49 ] ;
V_49 -> V_51 = V_11 -> V_51 ;
if ( ! V_47 ) {
F_14 ( V_2 , V_52 , V_18 , - 1 ) ;
return;
}
V_50 = F_15 ( V_49 , V_18 ) ;
if ( V_50 < 0 || F_15 ( V_49 , V_53 ) != V_46 )
V_50 = F_16 ( V_11 ) ;
F_14 ( V_2 , V_52 , V_18 , V_50 ) ;
F_14 ( V_2 , V_52 , V_53 , V_46 ) ;
}
void F_17 ( struct V_1 * V_2 , int V_54 )
{
F_14 ( V_2 , V_22 , V_32 , V_54 == 1 ) ;
F_14 ( V_2 , V_22 , V_33 , V_54 == 2 ) ;
F_14 ( V_2 , V_22 , V_34 , V_54 == 3 ) ;
F_14 ( V_2 , V_22 , V_35 , V_54 == 4 ) ;
F_14 ( V_2 , V_22 , V_36 , V_54 == 5 ) ;
}
void F_18 ( struct V_1 * V_2 , bool V_55 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_48 * V_56 ;
int V_57 , V_54 , V_12 ;
if ( ! V_11 )
return;
V_56 = NULL ;
V_57 = V_11 -> V_58 ;
V_54 = 0 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 ; ++ V_12 ) {
struct V_48 * V_59 = & V_11 -> V_14 [ V_12 ] ;
int V_50 = F_15 ( V_59 , V_18 ) ;
if ( V_50 < 0 )
continue;
if ( ( V_50 - V_57 ) & V_60 ) {
V_56 = V_59 ;
V_57 = V_50 ;
}
V_54 ++ ;
}
F_14 ( V_2 , V_22 , V_24 , V_54 > 0 ) ;
if ( V_55 )
F_17 ( V_2 , V_54 ) ;
if ( V_56 ) {
int V_61 = F_15 ( V_56 , V_27 ) ;
int V_62 = F_15 ( V_56 , V_29 ) ;
F_14 ( V_2 , V_52 , V_26 , V_61 ) ;
F_14 ( V_2 , V_52 , V_28 , V_62 ) ;
if ( F_2 ( V_31 , V_2 -> V_6 ) ) {
int V_63 = F_15 ( V_56 , V_31 ) ;
F_14 ( V_2 , V_52 , V_30 , V_63 ) ;
}
} else {
if ( F_2 ( V_31 , V_2 -> V_6 ) )
F_14 ( V_2 , V_52 , V_30 , 0 ) ;
}
}
static void F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 ; V_12 ++ ) {
if ( ! F_20 ( V_11 , & V_11 -> V_14 [ V_12 ] ) ) {
V_48 ( V_2 , V_12 ) ;
F_14 ( V_2 , V_52 , V_18 , - 1 ) ;
}
}
}
void F_21 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 ) {
F_19 ( V_2 , V_11 ) ;
V_11 -> V_51 ++ ;
}
}
void F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
bool V_55 = false ;
if ( ! V_11 )
return;
if ( V_11 -> V_9 & V_64 )
F_19 ( V_2 , V_11 ) ;
if ( ( V_11 -> V_9 & V_20 ) && ! ( V_11 -> V_9 & V_40 ) )
V_55 = true ;
F_18 ( V_2 , V_55 ) ;
V_11 -> V_51 ++ ;
}
static int F_23 ( int * V_65 , int V_66 , int * V_67 , int V_68 )
{
int V_69 , * V_63 , V_70 , V_71 ;
if ( V_65 == V_67 )
return 0 ;
V_69 = * V_65 ;
V_63 = V_65 + V_66 ;
V_70 = V_63 == V_67 ? V_69 + 1 : * V_63 ;
for (; V_63 != V_67 ; V_63 += V_66 )
if ( * V_63 < V_69 )
V_70 = V_69 , V_69 = * V_63 ;
else if ( * V_63 < V_70 )
V_70 = * V_63 ;
V_71 = ( V_69 + V_70 + 1 ) / 2 ;
if ( V_71 == 0 || ( V_71 > 0 && ! V_68 ) )
return 0 ;
if ( V_70 < 0 )
V_71 *= 2 ;
for ( V_63 = V_65 ; V_63 != V_67 ; V_63 += V_66 )
* V_63 -= V_71 ;
return ( V_71 < V_70 && V_70 <= 0 ) || ( V_69 >= 0 && V_69 < V_71 ) ;
}
static void F_24 ( int * V_72 , int V_73 , int V_74 , int V_75 )
{
int V_12 , V_76 , V_77 ;
for ( V_76 = 0 ; V_76 < V_75 ; V_76 ++ ) {
for ( V_12 = 0 ; V_12 < V_73 ; V_12 ++ )
F_23 ( V_72 + V_12 , V_73 , V_72 + V_12 + V_75 , V_73 <= V_74 ) ;
V_77 = 0 ;
for ( V_12 = 0 ; V_12 < V_75 ; V_12 += V_73 )
V_77 += F_23 ( V_72 + V_12 , 1 , V_72 + V_12 + V_73 , V_74 <= V_73 ) ;
if ( ! V_77 )
break;
}
}
static int F_25 ( struct V_10 * V_11 ,
const struct V_78 * V_79 , int V_80 )
{
const struct V_78 * V_63 ;
struct V_48 * V_70 ;
int * V_72 = V_11 -> V_44 ;
int V_61 , V_62 ;
for ( V_70 = V_11 -> V_14 ; V_70 != V_11 -> V_14 + V_11 -> V_8 ; V_70 ++ ) {
if ( ! F_26 ( V_70 ) )
continue;
V_61 = F_15 ( V_70 , V_27 ) ;
V_62 = F_15 ( V_70 , V_29 ) ;
for ( V_63 = V_79 ; V_63 != V_79 + V_80 ; V_63 ++ ) {
int V_81 = V_61 - V_63 -> V_61 , V_82 = V_62 - V_63 -> V_62 ;
* V_72 ++ = V_81 * V_81 + V_82 * V_82 ;
}
}
return V_72 - V_11 -> V_44 ;
}
static void F_27 ( struct V_10 * V_11 ,
int * V_14 , int V_80 )
{
struct V_48 * V_70 ;
int * V_72 = V_11 -> V_44 , * V_63 ;
for ( V_63 = V_14 ; V_63 != V_14 + V_80 ; V_63 ++ )
* V_63 = - 1 ;
for ( V_70 = V_11 -> V_14 ; V_70 != V_11 -> V_14 + V_11 -> V_8 ; V_70 ++ ) {
if ( ! F_26 ( V_70 ) )
continue;
for ( V_63 = V_14 ; V_63 != V_14 + V_80 ; V_63 ++ )
if ( * V_72 ++ < 0 )
* V_63 = V_70 - V_11 -> V_14 ;
}
for ( V_70 = V_11 -> V_14 ; V_70 != V_11 -> V_14 + V_11 -> V_8 ; V_70 ++ ) {
if ( F_26 ( V_70 ) )
continue;
for ( V_63 = V_14 ; V_63 != V_14 + V_80 ; V_63 ++ )
if ( * V_63 < 0 ) {
* V_63 = V_70 - V_11 -> V_14 ;
break;
}
}
}
int F_28 ( struct V_1 * V_2 , int * V_14 ,
const struct V_78 * V_79 , int V_80 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_75 ;
if ( ! V_11 || ! V_11 -> V_44 )
return - V_83 ;
if ( V_80 > V_11 -> V_8 )
return - V_13 ;
if ( V_80 < 1 )
return 0 ;
V_75 = F_25 ( V_11 , V_79 , V_80 ) ;
F_24 ( V_11 -> V_44 , V_80 , V_75 / V_80 , V_75 ) ;
F_27 ( V_11 , V_14 , V_80 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , int V_84 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_48 * V_70 ;
if ( ! V_11 )
return - 1 ;
for ( V_70 = V_11 -> V_14 ; V_70 != V_11 -> V_14 + V_11 -> V_8 ; V_70 ++ )
if ( F_26 ( V_70 ) && V_70 -> V_84 == V_84 )
return V_70 - V_11 -> V_14 ;
for ( V_70 = V_11 -> V_14 ; V_70 != V_11 -> V_14 + V_11 -> V_8 ; V_70 ++ )
if ( ! F_26 ( V_70 ) ) {
V_70 -> V_84 = V_84 ;
return V_70 - V_11 -> V_14 ;
}
return - 1 ;
}
