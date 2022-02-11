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
if ( V_9 & V_40 ) {
unsigned int V_41 = V_8 * V_8 ;
V_11 -> V_42 = F_9 ( V_41 , sizeof( * V_11 -> V_42 ) , V_15 ) ;
if ( ! V_11 -> V_42 )
goto V_16;
}
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
F_10 ( & V_11 -> V_14 [ V_12 ] , V_18 , - 1 ) ;
V_2 -> V_11 = V_11 ;
return 0 ;
V_16:
F_11 ( V_11 ) ;
return - V_43 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 ) {
F_11 ( V_2 -> V_11 -> V_42 ) ;
F_11 ( V_2 -> V_11 ) ;
}
V_2 -> V_11 = NULL ;
}
void F_13 ( struct V_1 * V_2 ,
unsigned int V_44 , bool V_45 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_46 * V_47 ;
int V_48 ;
if ( ! V_11 )
return;
V_47 = & V_11 -> V_14 [ V_11 -> V_47 ] ;
V_47 -> V_49 = V_11 -> V_49 ;
if ( ! V_45 ) {
F_14 ( V_2 , V_50 , V_18 , - 1 ) ;
return;
}
V_48 = F_15 ( V_47 , V_18 ) ;
if ( V_48 < 0 || F_15 ( V_47 , V_51 ) != V_44 )
V_48 = F_16 ( V_11 ) ;
F_14 ( V_2 , V_50 , V_18 , V_48 ) ;
F_14 ( V_2 , V_50 , V_51 , V_44 ) ;
}
void F_17 ( struct V_1 * V_2 , int V_52 )
{
F_14 ( V_2 , V_22 , V_32 , V_52 == 1 ) ;
F_14 ( V_2 , V_22 , V_33 , V_52 == 2 ) ;
F_14 ( V_2 , V_22 , V_34 , V_52 == 3 ) ;
F_14 ( V_2 , V_22 , V_35 , V_52 == 4 ) ;
F_14 ( V_2 , V_22 , V_36 , V_52 == 5 ) ;
}
void F_18 ( struct V_1 * V_2 , bool V_53 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_46 * V_54 ;
int V_55 , V_52 , V_12 ;
if ( ! V_11 )
return;
V_54 = NULL ;
V_55 = V_11 -> V_56 ;
V_52 = 0 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_8 ; ++ V_12 ) {
struct V_46 * V_57 = & V_11 -> V_14 [ V_12 ] ;
int V_48 = F_15 ( V_57 , V_18 ) ;
if ( V_48 < 0 )
continue;
if ( ( V_48 - V_55 ) & V_58 ) {
V_54 = V_57 ;
V_55 = V_48 ;
}
V_52 ++ ;
}
F_14 ( V_2 , V_22 , V_24 , V_52 > 0 ) ;
if ( V_53 )
F_17 ( V_2 , V_52 ) ;
if ( V_54 ) {
int V_59 = F_15 ( V_54 , V_27 ) ;
int V_60 = F_15 ( V_54 , V_29 ) ;
F_14 ( V_2 , V_50 , V_26 , V_59 ) ;
F_14 ( V_2 , V_50 , V_28 , V_60 ) ;
if ( F_2 ( V_31 , V_2 -> V_6 ) ) {
int V_61 = F_15 ( V_54 , V_31 ) ;
F_14 ( V_2 , V_50 , V_30 , V_61 ) ;
}
} else {
if ( F_2 ( V_31 , V_2 -> V_6 ) )
F_14 ( V_2 , V_50 , V_30 , 0 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_46 * V_62 ;
if ( ! V_11 )
return;
if ( V_11 -> V_9 & V_63 ) {
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ ) {
if ( F_20 ( V_11 , V_62 ) )
continue;
V_46 ( V_2 , V_62 - V_11 -> V_14 ) ;
F_14 ( V_2 , V_50 , V_18 , - 1 ) ;
}
}
F_18 ( V_2 , ( V_11 -> V_9 & V_20 ) ) ;
V_11 -> V_49 ++ ;
}
static int F_21 ( int * V_64 , int V_65 , int * V_66 , int V_67 )
{
int V_68 , * V_61 , V_62 , V_69 ;
if ( V_64 == V_66 )
return 0 ;
V_68 = * V_64 ;
V_61 = V_64 + V_65 ;
V_62 = V_61 == V_66 ? V_68 + 1 : * V_61 ;
for (; V_61 != V_66 ; V_61 += V_65 )
if ( * V_61 < V_68 )
V_62 = V_68 , V_68 = * V_61 ;
else if ( * V_61 < V_62 )
V_62 = * V_61 ;
V_69 = ( V_68 + V_62 + 1 ) / 2 ;
if ( V_69 == 0 || ( V_69 > 0 && ! V_67 ) )
return 0 ;
if ( V_62 < 0 )
V_69 *= 2 ;
for ( V_61 = V_64 ; V_61 != V_66 ; V_61 += V_65 )
* V_61 -= V_69 ;
return ( V_69 < V_62 && V_62 <= 0 ) || ( V_68 >= 0 && V_68 < V_69 ) ;
}
static void F_22 ( int * V_70 , int V_71 , int V_72 , int V_73 )
{
int V_12 , V_74 , V_75 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
for ( V_12 = 0 ; V_12 < V_71 ; V_12 ++ )
F_21 ( V_70 + V_12 , V_71 , V_70 + V_12 + V_73 , V_71 <= V_72 ) ;
V_75 = 0 ;
for ( V_12 = 0 ; V_12 < V_73 ; V_12 += V_71 )
V_75 += F_21 ( V_70 + V_12 , 1 , V_70 + V_12 + V_71 , V_72 <= V_71 ) ;
if ( ! V_75 )
break;
}
}
static int F_23 ( struct V_10 * V_11 ,
const struct V_76 * V_77 , int V_78 )
{
const struct V_76 * V_61 ;
struct V_46 * V_62 ;
int * V_70 = V_11 -> V_42 ;
int V_59 , V_60 ;
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ ) {
if ( ! F_24 ( V_62 ) )
continue;
V_59 = F_15 ( V_62 , V_27 ) ;
V_60 = F_15 ( V_62 , V_29 ) ;
for ( V_61 = V_77 ; V_61 != V_77 + V_78 ; V_61 ++ ) {
int V_79 = V_59 - V_61 -> V_59 , V_80 = V_60 - V_61 -> V_60 ;
* V_70 ++ = V_79 * V_79 + V_80 * V_80 ;
}
}
return V_70 - V_11 -> V_42 ;
}
static void F_25 ( struct V_10 * V_11 ,
int * V_14 , int V_78 )
{
struct V_46 * V_62 ;
int * V_70 = V_11 -> V_42 , * V_61 ;
for ( V_61 = V_14 ; V_61 != V_14 + V_78 ; V_61 ++ )
* V_61 = - 1 ;
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ ) {
if ( ! F_24 ( V_62 ) )
continue;
for ( V_61 = V_14 ; V_61 != V_14 + V_78 ; V_61 ++ )
if ( * V_70 ++ < 0 )
* V_61 = V_62 - V_11 -> V_14 ;
}
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ ) {
if ( F_24 ( V_62 ) )
continue;
for ( V_61 = V_14 ; V_61 != V_14 + V_78 ; V_61 ++ )
if ( * V_61 < 0 ) {
* V_61 = V_62 - V_11 -> V_14 ;
break;
}
}
}
int F_26 ( struct V_1 * V_2 , int * V_14 ,
const struct V_76 * V_77 , int V_78 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_73 ;
if ( ! V_11 || ! V_11 -> V_42 )
return - V_81 ;
if ( V_78 > V_11 -> V_8 )
return - V_13 ;
if ( V_78 < 1 )
return 0 ;
V_73 = F_23 ( V_11 , V_77 , V_78 ) ;
F_22 ( V_11 -> V_42 , V_78 , V_73 / V_78 , V_73 ) ;
F_25 ( V_11 , V_14 , V_78 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , int V_82 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_46 * V_62 ;
if ( ! V_11 )
return - 1 ;
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ )
if ( F_24 ( V_62 ) && V_62 -> V_82 == V_82 )
return V_62 - V_11 -> V_14 ;
for ( V_62 = V_11 -> V_14 ; V_62 != V_11 -> V_14 + V_11 -> V_8 ; V_62 ++ )
if ( ! F_24 ( V_62 ) ) {
V_62 -> V_82 = V_82 ;
return V_62 - V_11 -> V_14 ;
}
return - 1 ;
}
