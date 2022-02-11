int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = F_2 ( V_3 * sizeof( V_2 -> V_6 [ 0 ] ) ,
V_7 ) ;
if ( V_2 -> V_6 == NULL )
return - V_8 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_2 -> V_6 [ V_4 ] = F_3 ( V_7 | V_9 | V_10 ) ;
if ( V_2 -> V_6 [ V_4 ] == NULL )
break;
}
V_2 -> V_3 = V_4 ;
if ( V_4 < V_3 ) {
F_4 ( V_2 , NULL ) ;
return - V_8 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_13 V_14 )
{
T_1 V_15 ;
int V_4 ;
V_2 -> V_14 = V_14 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ ) {
V_15 = F_6 ( V_12 -> V_16 , V_2 -> V_6 [ V_4 ] ,
0 , V_17 , V_14 ) ;
if ( F_7 ( V_12 -> V_16 , V_15 ) )
break;
F_8 ( V_2 -> V_6 [ V_4 ] , V_15 ) ;
}
V_2 -> V_5 = V_4 ;
if ( V_4 < V_2 -> V_3 )
return - V_8 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_3 , enum V_13 V_14 )
{
int V_18 ;
V_18 = F_1 ( V_2 , V_3 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_5 ( V_2 , V_12 , V_14 ) ;
if ( V_18 < 0 )
F_4 ( V_2 , V_12 ) ;
return V_18 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
unsigned long V_21 ;
int V_4 , V_22 ;
V_21 = V_20 -> V_23 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ ) {
V_22 = F_11 ( V_20 , V_21 , V_2 -> V_6 [ V_4 ] ) ;
if ( V_22 )
return V_22 ;
V_21 += V_17 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_4 ;
T_1 V_15 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
V_15 = F_12 ( V_2 -> V_6 [ V_4 ] ) ;
F_13 ( V_12 -> V_16 , V_15 ,
V_17 , V_2 -> V_14 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ )
F_14 ( V_2 -> V_6 [ V_4 ] ) ;
F_15 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = 0 ;
}
T_2 F_16 ( struct V_1 * V_2 , T_1 V_24 )
{
int V_4 ;
T_1 V_15 ;
T_3 V_25 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_3 ; V_4 ++ ) {
V_15 = F_12 ( V_2 -> V_6 [ V_4 ] ) ;
V_25 = ( T_3 ) V_24 - ( T_3 ) V_15 ;
if ( V_25 > 0 && V_25 <= V_17 )
return ( V_4 << V_26 ) + V_25 ;
}
return 0 ;
}
struct V_27 * F_17 ( struct V_11 * V_12 ,
int type , int V_28 , int V_29 , T_2 V_30 ,
T_4 V_31 , void * V_32 )
{
struct V_27 * V_33 ;
V_33 = V_12 -> V_34 -> V_35 ( V_12 ,
type , V_28 , V_30 ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
V_33 -> V_12 = V_12 ;
V_33 -> type = type ;
V_33 -> V_28 = V_28 ;
V_33 -> V_29 = V_29 ;
V_33 -> V_30 = V_30 ;
V_33 -> V_31 . V_36 = V_31 ;
V_33 -> V_32 = V_32 ;
return V_33 ;
}
void F_19 ( struct V_27 * V_33 )
{
V_33 -> V_12 -> V_34 -> V_37 ( V_33 ) ;
}
int F_20 ( struct V_27 * V_33 ,
int V_38 , int V_39 , int V_40 )
{
return V_33 -> V_12 -> V_34 -> V_41 ( V_33 , V_38 , V_39 , V_40 ) ;
}
int F_21 ( struct V_27 * V_33 , T_5 * V_42 )
{
return V_33 -> V_12 -> V_34 -> V_43 ( V_33 , V_42 ) ;
}
int F_22 ( struct V_27 * V_33 ,
struct V_44 * V_45 ,
struct V_1 * V_2 ,
unsigned long V_46 )
{
return V_33 -> V_12 -> V_34 -> V_47 ( V_33 , V_45 , V_2 , V_46 ) ;
}
void F_23 ( struct V_27 * V_33 )
{
V_33 -> V_12 -> V_34 -> V_48 ( V_33 ) ;
}
int F_24 ( struct V_27 * V_33 )
{
return V_33 -> V_12 -> V_34 -> V_49 ( V_33 ) ;
}
int F_25 ( struct V_27 * V_33 )
{
return V_33 -> V_12 -> V_34 -> V_50 ( V_33 ) ;
}
static int F_26 ( struct V_11 * V_12 , int V_51 , int V_52 ,
int V_53 , bool V_54 )
{
int V_55 , V_56 , V_57 = V_54 ? V_58 : 0 ;
T_6 V_59 [ 2 ] ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ ) {
V_56 = V_54 ? V_57 - V_53 : V_57 + V_53 ;
if ( V_56 < 0 || V_56 > V_58 )
return - V_60 ;
V_59 [ 0 ] = F_27 ( V_57 ) ;
V_59 [ 1 ] = F_27 ( V_56 ) ;
switch ( F_28 ( V_12 , V_61 ,
V_51 , V_52 , V_62 ,
V_63 + V_64 ,
V_59 , 8 ) ) {
case V_65 :
return V_54 ? - V_66 : V_53 ;
case V_67 :
if ( F_29 ( V_59 ) == V_57 )
return V_53 ;
V_57 = F_29 ( V_59 ) ;
}
}
return - V_68 ;
}
static int F_30 ( struct V_11 * V_12 , int V_51 , int V_52 ,
T_7 V_69 , T_5 V_25 , bool V_54 )
{
T_6 V_70 , V_71 , V_57 ;
T_6 V_59 [ 2 ] ;
int V_28 , V_18 = - V_68 , V_72 = 5 ;
V_57 = V_71 = V_54 ? F_27 ( ~ 0 ) : 0 ;
for ( V_28 = 0 ; V_28 < 32 ; V_28 ++ ) {
if ( ! ( V_69 & 1 << V_28 ) )
continue;
V_18 = - V_60 ;
V_70 = F_27 ( 1 << ( 31 - V_28 ) ) ;
if ( ( V_57 & V_70 ) != ( V_71 & V_70 ) )
continue;
V_59 [ 0 ] = V_57 ;
V_59 [ 1 ] = V_57 ^ V_70 ;
switch ( F_28 ( V_12 , V_61 ,
V_51 , V_52 , V_62 ,
V_25 , V_59 , 8 ) ) {
case V_65 :
return V_54 ? - V_66 : V_28 ;
case V_67 :
if ( V_59 [ 0 ] == V_57 )
return V_28 ;
V_57 = V_59 [ 0 ] ;
if ( ( V_59 [ 0 ] & V_70 ) == ( V_59 [ 1 ] & V_70 ) )
continue;
default:
if ( V_72 ) {
V_72 -- ;
V_28 -- ;
} else {
V_18 = - V_68 ;
}
}
}
return V_18 ;
}
static void F_31 ( struct V_11 * V_12 , int V_51 ,
int V_52 , int V_28 )
{
T_7 V_73 ;
T_5 V_25 ;
V_73 = V_28 < 32 ? 1 << V_28 : 1 << ( V_28 - 32 ) ;
V_25 = V_28 < 32 ? V_63 + V_74 :
V_63 + V_75 ;
F_30 ( V_12 , V_51 , V_52 , V_73 , V_25 , false ) ;
}
void F_32 ( struct V_11 * V_12 , int V_52 ,
T_5 V_69 , int * V_28 , int * V_53 ,
bool V_54 )
{
T_7 V_76 = V_69 ;
T_7 V_77 = V_69 >> 32 ;
int V_51 , V_18 , V_78 = - V_79 ;
F_33 ( & V_12 -> V_80 ) ;
V_51 = V_12 -> V_81 -> V_82 ;
F_34 ( & V_12 -> V_80 ) ;
if ( V_76 )
V_78 = F_30 ( V_12 , V_51 , V_52 , V_76 ,
V_63 + V_74 ,
V_54 ) ;
if ( V_77 && V_78 < 0 ) {
V_78 = F_30 ( V_12 , V_51 , V_52 , V_77 ,
V_63 + V_75 ,
V_54 ) ;
if ( V_78 >= 0 )
V_78 += 32 ;
}
* V_28 = V_78 ;
if ( V_54 && V_69 != 0 && V_78 < 0 )
* V_53 = 0 ;
if ( * V_53 == 0 )
return;
V_18 = F_26 ( V_12 , V_51 , V_52 , * V_53 , V_54 ) ;
if ( V_18 < 0 )
* V_53 = 0 ;
if ( V_54 && V_18 < 0 ) {
if ( V_78 >= 0 )
F_31 ( V_12 , V_51 , V_52 , V_78 ) ;
* V_28 = V_18 ;
}
}
