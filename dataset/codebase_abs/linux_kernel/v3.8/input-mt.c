static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
if ( V_2 -> V_5 && F_2 ( V_4 , V_2 -> V_6 ) ) {
V_2 -> V_5 [ V_3 ] = V_2 -> V_5 [ V_4 ] ;
V_2 -> V_6 [ F_3 ( V_3 ) ] |= F_4 ( V_3 ) ;
}
}
int F_5 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
if ( ! V_7 )
return 0 ;
if ( V_10 )
return V_10 -> V_7 != V_7 ? - V_12 : 0 ;
V_10 = F_6 ( sizeof( * V_10 ) + V_7 * sizeof( * V_10 -> V_13 ) , V_14 ) ;
if ( ! V_10 )
goto V_15;
V_10 -> V_7 = V_7 ;
V_10 -> V_8 = V_8 ;
F_7 ( V_2 , V_16 , 0 , V_7 - 1 , 0 , 0 ) ;
F_7 ( V_2 , V_17 , 0 , V_18 , 0 , 0 ) ;
if ( V_8 & ( V_19 | V_20 ) ) {
F_8 ( V_21 , V_2 -> V_22 ) ;
F_8 ( V_23 , V_2 -> V_24 ) ;
F_1 ( V_2 , V_25 , V_26 ) ;
F_1 ( V_2 , V_27 , V_28 ) ;
F_1 ( V_2 , V_29 , V_30 ) ;
}
if ( V_8 & V_19 ) {
F_8 ( V_31 , V_2 -> V_24 ) ;
F_8 ( V_32 , V_2 -> V_24 ) ;
if ( V_7 >= 3 )
F_8 ( V_33 , V_2 -> V_24 ) ;
if ( V_7 >= 4 )
F_8 ( V_34 , V_2 -> V_24 ) ;
if ( V_7 >= 5 )
F_8 ( V_35 , V_2 -> V_24 ) ;
F_8 ( V_36 , V_2 -> V_37 ) ;
}
if ( V_8 & V_20 )
F_8 ( V_38 , V_2 -> V_37 ) ;
if ( V_8 & V_39 ) {
unsigned int V_40 = V_7 * V_7 ;
V_10 -> V_41 = F_9 ( V_40 , sizeof( * V_10 -> V_41 ) , V_14 ) ;
if ( ! V_10 -> V_41 )
goto V_15;
}
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ )
F_10 ( & V_10 -> V_13 [ V_11 ] , V_17 , - 1 ) ;
V_2 -> V_10 = V_10 ;
return 0 ;
V_15:
F_11 ( V_10 ) ;
return - V_42 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 ) {
F_11 ( V_2 -> V_10 -> V_41 ) ;
F_11 ( V_2 -> V_10 ) ;
}
V_2 -> V_10 = NULL ;
}
void F_13 ( struct V_1 * V_2 ,
unsigned int V_43 , bool V_44 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_45 * V_46 ;
int V_47 ;
if ( ! V_10 )
return;
V_46 = & V_10 -> V_13 [ V_10 -> V_46 ] ;
V_46 -> V_48 = V_10 -> V_48 ;
if ( ! V_44 ) {
F_14 ( V_2 , V_49 , V_17 , - 1 ) ;
return;
}
V_47 = F_15 ( V_46 , V_17 ) ;
if ( V_47 < 0 || F_15 ( V_46 , V_50 ) != V_43 )
V_47 = F_16 ( V_10 ) ;
F_14 ( V_2 , V_49 , V_17 , V_47 ) ;
F_14 ( V_2 , V_49 , V_50 , V_43 ) ;
}
void F_17 ( struct V_1 * V_2 , int V_51 )
{
F_14 ( V_2 , V_21 , V_31 , V_51 == 1 ) ;
F_14 ( V_2 , V_21 , V_32 , V_51 == 2 ) ;
F_14 ( V_2 , V_21 , V_33 , V_51 == 3 ) ;
F_14 ( V_2 , V_21 , V_34 , V_51 == 4 ) ;
F_14 ( V_2 , V_21 , V_35 , V_51 == 5 ) ;
}
void F_18 ( struct V_1 * V_2 , bool V_52 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_45 * V_53 ;
int V_54 , V_51 , V_11 ;
if ( ! V_10 )
return;
V_53 = NULL ;
V_54 = V_10 -> V_55 ;
V_51 = 0 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_7 ; ++ V_11 ) {
struct V_45 * V_56 = & V_10 -> V_13 [ V_11 ] ;
int V_47 = F_15 ( V_56 , V_17 ) ;
if ( V_47 < 0 )
continue;
if ( ( V_47 - V_54 ) & V_57 ) {
V_53 = V_56 ;
V_54 = V_47 ;
}
V_51 ++ ;
}
F_14 ( V_2 , V_21 , V_23 , V_51 > 0 ) ;
if ( V_52 )
F_17 ( V_2 , V_51 ) ;
if ( V_53 ) {
int V_58 = F_15 ( V_53 , V_26 ) ;
int V_59 = F_15 ( V_53 , V_28 ) ;
F_14 ( V_2 , V_49 , V_25 , V_58 ) ;
F_14 ( V_2 , V_49 , V_27 , V_59 ) ;
if ( F_2 ( V_30 , V_2 -> V_6 ) ) {
int V_60 = F_15 ( V_53 , V_30 ) ;
F_14 ( V_2 , V_49 , V_29 , V_60 ) ;
}
} else {
if ( F_2 ( V_30 , V_2 -> V_6 ) )
F_14 ( V_2 , V_49 , V_29 , 0 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_45 * V_61 ;
if ( ! V_10 )
return;
if ( V_10 -> V_8 & V_62 ) {
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ ) {
if ( F_20 ( V_10 , V_61 ) )
continue;
V_45 ( V_2 , V_61 - V_10 -> V_13 ) ;
F_14 ( V_2 , V_49 , V_17 , - 1 ) ;
}
}
F_18 ( V_2 , ( V_10 -> V_8 & V_19 ) ) ;
V_10 -> V_48 ++ ;
}
static int F_21 ( int * V_63 , int V_64 , int * V_65 , int V_66 )
{
int V_67 , * V_60 , V_61 , V_68 ;
if ( V_63 == V_65 )
return 0 ;
V_67 = * V_63 ;
V_60 = V_63 + V_64 ;
V_61 = V_60 == V_65 ? V_67 + 1 : * V_60 ;
for (; V_60 != V_65 ; V_60 += V_64 )
if ( * V_60 < V_67 )
V_61 = V_67 , V_67 = * V_60 ;
else if ( * V_60 < V_61 )
V_61 = * V_60 ;
V_68 = ( V_67 + V_61 + 1 ) / 2 ;
if ( V_68 == 0 || ( V_68 > 0 && ! V_66 ) )
return 0 ;
if ( V_61 < 0 )
V_68 *= 2 ;
for ( V_60 = V_63 ; V_60 != V_65 ; V_60 += V_64 )
* V_60 -= V_68 ;
return ( V_68 < V_61 && V_61 <= 0 ) || ( V_67 >= 0 && V_67 < V_68 ) ;
}
static void F_22 ( int * V_69 , int V_70 , int V_71 , int V_72 )
{
int V_11 , V_73 , V_74 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
for ( V_11 = 0 ; V_11 < V_70 ; V_11 ++ )
F_21 ( V_69 + V_11 , V_70 , V_69 + V_11 + V_72 , V_70 <= V_71 ) ;
V_74 = 0 ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 += V_70 )
V_74 += F_21 ( V_69 + V_11 , 1 , V_69 + V_11 + V_70 , V_71 <= V_70 ) ;
if ( ! V_74 )
break;
}
}
static int F_23 ( struct V_9 * V_10 ,
const struct V_75 * V_76 , int V_77 )
{
const struct V_75 * V_60 ;
struct V_45 * V_61 ;
int * V_69 = V_10 -> V_41 ;
int V_58 , V_59 ;
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ ) {
if ( ! F_24 ( V_61 ) )
continue;
V_58 = F_15 ( V_61 , V_26 ) ;
V_59 = F_15 ( V_61 , V_28 ) ;
for ( V_60 = V_76 ; V_60 != V_76 + V_77 ; V_60 ++ ) {
int V_78 = V_58 - V_60 -> V_58 , V_79 = V_59 - V_60 -> V_59 ;
* V_69 ++ = V_78 * V_78 + V_79 * V_79 ;
}
}
return V_69 - V_10 -> V_41 ;
}
static void F_25 ( struct V_9 * V_10 ,
int * V_13 , int V_77 )
{
struct V_45 * V_61 ;
int * V_69 = V_10 -> V_41 , * V_60 ;
for ( V_60 = V_13 ; V_60 != V_13 + V_77 ; V_60 ++ )
* V_60 = - 1 ;
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ ) {
if ( ! F_24 ( V_61 ) )
continue;
for ( V_60 = V_13 ; V_60 != V_13 + V_77 ; V_60 ++ )
if ( * V_69 ++ < 0 )
* V_60 = V_61 - V_10 -> V_13 ;
}
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ ) {
if ( F_24 ( V_61 ) )
continue;
for ( V_60 = V_13 ; V_60 != V_13 + V_77 ; V_60 ++ )
if ( * V_60 < 0 ) {
* V_60 = V_61 - V_10 -> V_13 ;
break;
}
}
}
int F_26 ( struct V_1 * V_2 , int * V_13 ,
const struct V_75 * V_76 , int V_77 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_72 ;
if ( ! V_10 || ! V_10 -> V_41 )
return - V_80 ;
if ( V_77 > V_10 -> V_7 )
return - V_12 ;
if ( V_77 < 1 )
return 0 ;
V_72 = F_23 ( V_10 , V_76 , V_77 ) ;
F_22 ( V_10 -> V_41 , V_77 , V_72 / V_77 , V_72 ) ;
F_25 ( V_10 , V_13 , V_77 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , int V_81 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_45 * V_61 ;
if ( ! V_10 )
return - 1 ;
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ )
if ( F_24 ( V_61 ) && V_61 -> V_81 == V_81 )
return V_61 - V_10 -> V_13 ;
for ( V_61 = V_10 -> V_13 ; V_61 != V_10 -> V_13 + V_10 -> V_7 ; V_61 ++ )
if ( ! F_24 ( V_61 ) ) {
V_61 -> V_81 = V_81 ;
return V_61 - V_10 -> V_13 ;
}
return - 1 ;
}
