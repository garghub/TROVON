int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , enum V_6 V_7 )
{
int V_8 , V_9 ;
T_1 V_10 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_11 = F_2 ( V_5 * sizeof( V_2 -> V_11 [ 0 ] ) ,
V_12 ) ;
if ( V_2 -> V_11 == NULL )
goto V_13;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 ; V_8 ++ ) {
V_2 -> V_11 [ V_8 ] = F_3 ( V_12 | V_14 | V_15 ) ;
if ( V_2 -> V_11 [ V_8 ] == NULL )
goto V_16;
V_10 = F_4 ( V_4 -> V_17 , V_2 -> V_11 [ V_8 ] ,
0 , V_18 , V_7 ) ;
if ( F_5 ( V_4 -> V_17 , V_10 ) ) {
F_6 ( V_2 -> V_11 [ V_8 ] ) ;
goto V_16;
}
F_7 ( V_2 -> V_11 [ V_8 ] , V_10 ) ;
}
return 0 ;
V_16:
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_8 ( V_2 -> V_11 [ V_9 ] ) ;
F_9 ( V_4 -> V_17 , V_10 ,
V_18 , V_7 ) ;
F_6 ( V_2 -> V_11 [ V_9 ] ) ;
}
F_10 ( V_2 -> V_11 ) ;
V_13:
V_2 -> V_11 = NULL ;
return - V_19 ;
}
int F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned long V_22 ;
int V_8 , V_23 ;
V_22 = V_21 -> V_24 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 ; V_8 ++ ) {
V_23 = F_12 ( V_21 , V_22 , V_2 -> V_11 [ V_8 ] ) ;
if ( V_23 )
return V_23 ;
V_22 += V_18 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_8 ;
T_1 V_10 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 ; V_8 ++ ) {
V_10 = F_8 ( V_2 -> V_11 [ V_8 ] ) ;
F_9 ( V_4 -> V_17 , V_10 ,
V_18 , V_2 -> V_7 ) ;
F_6 ( V_2 -> V_11 [ V_8 ] ) ;
}
F_10 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
T_2 F_14 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_8 ;
T_1 V_10 ;
T_3 V_26 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 ; V_8 ++ ) {
V_10 = F_8 ( V_2 -> V_11 [ V_8 ] ) ;
V_26 = ( T_3 ) V_25 - ( T_3 ) V_10 ;
if ( V_26 > 0 && V_26 <= V_18 )
return ( V_8 << V_27 ) + V_26 ;
}
return 0 ;
}
struct V_28 * F_15 ( struct V_3 * V_4 ,
int type , int V_29 , int V_30 , T_2 V_31 ,
T_4 V_32 , void * V_33 )
{
struct V_28 * V_34 ;
V_34 = V_4 -> V_35 -> V_36 ( V_4 ,
type , V_29 , V_31 ) ;
if ( F_16 ( V_34 ) )
return V_34 ;
V_34 -> V_4 = V_4 ;
V_34 -> type = type ;
V_34 -> V_29 = V_29 ;
V_34 -> V_30 = V_30 ;
V_34 -> V_31 = V_31 ;
V_34 -> V_32 . V_37 = V_32 ;
V_34 -> V_33 = V_33 ;
return V_34 ;
}
void F_17 ( struct V_28 * V_34 )
{
V_34 -> V_4 -> V_35 -> V_38 ( V_34 ) ;
}
int F_18 ( struct V_28 * V_34 ,
int V_39 , int V_40 , int V_41 )
{
return V_34 -> V_4 -> V_35 -> V_42 ( V_34 , V_39 , V_40 , V_41 ) ;
}
int F_19 ( struct V_28 * V_34 , T_5 * V_43 )
{
return V_34 -> V_4 -> V_35 -> V_44 ( V_34 , V_43 ) ;
}
int F_20 ( struct V_28 * V_34 ,
struct V_45 * V_46 ,
struct V_1 * V_2 ,
unsigned long V_47 )
{
return V_34 -> V_4 -> V_35 -> V_48 ( V_34 , V_46 , V_2 , V_47 ) ;
}
void F_21 ( struct V_28 * V_34 )
{
V_34 -> V_4 -> V_35 -> V_49 ( V_34 ) ;
}
int F_22 ( struct V_28 * V_34 )
{
return V_34 -> V_4 -> V_35 -> V_50 ( V_34 ) ;
}
static int F_23 ( struct V_3 * V_4 , int V_51 , int V_52 ,
int V_53 , bool V_54 )
{
int V_55 , V_56 , V_57 = V_54 ? V_58 : 0 ;
T_6 V_59 [ 2 ] ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ ) {
V_56 = V_54 ? V_57 - V_53 : V_57 + V_53 ;
if ( V_56 < 0 || V_56 > V_58 )
return - V_60 ;
V_59 [ 0 ] = F_24 ( V_57 ) ;
V_59 [ 1 ] = F_24 ( V_56 ) ;
switch ( F_25 ( V_4 , V_61 ,
V_51 , V_52 , V_62 ,
V_63 + V_64 ,
V_59 , 8 ) ) {
case V_65 :
return V_54 ? - V_66 : V_53 ;
case V_67 :
if ( F_26 ( V_59 ) == V_57 )
return V_53 ;
V_57 = F_26 ( V_59 ) ;
}
}
return - V_68 ;
}
static int F_27 ( struct V_3 * V_4 , int V_51 , int V_52 ,
T_7 V_69 , T_5 V_26 , bool V_54 )
{
T_6 V_70 , V_71 , V_57 ;
T_6 V_59 [ 2 ] ;
int V_29 , V_72 = - V_68 , V_73 = 5 ;
V_57 = V_71 = V_54 ? F_24 ( ~ 0 ) : 0 ;
for ( V_29 = 0 ; V_29 < 32 ; V_29 ++ ) {
if ( ! ( V_69 & 1 << V_29 ) )
continue;
V_72 = - V_60 ;
V_70 = F_24 ( 1 << ( 31 - V_29 ) ) ;
if ( ( V_57 & V_70 ) != ( V_71 & V_70 ) )
continue;
V_59 [ 0 ] = V_57 ;
V_59 [ 1 ] = V_57 ^ V_70 ;
switch ( F_25 ( V_4 , V_61 ,
V_51 , V_52 , V_62 ,
V_26 , V_59 , 8 ) ) {
case V_65 :
return V_54 ? - V_66 : V_29 ;
case V_67 :
if ( V_59 [ 0 ] == V_57 )
return V_29 ;
V_57 = V_59 [ 0 ] ;
if ( ( V_59 [ 0 ] & V_70 ) == ( V_59 [ 1 ] & V_70 ) )
continue;
default:
if ( V_73 ) {
V_73 -- ;
V_29 -- ;
} else {
V_72 = - V_68 ;
}
}
}
return V_72 ;
}
static void F_28 ( struct V_3 * V_4 , int V_51 ,
int V_52 , int V_29 )
{
T_7 V_74 ;
T_5 V_26 ;
V_74 = V_29 < 32 ? 1 << V_29 : 1 << ( V_29 - 32 ) ;
V_26 = V_29 < 32 ? V_63 + V_75 :
V_63 + V_76 ;
F_27 ( V_4 , V_51 , V_52 , V_74 , V_26 , false ) ;
}
void F_29 ( struct V_3 * V_4 , int V_52 ,
T_5 V_69 , int * V_29 , int * V_53 ,
bool V_54 )
{
T_7 V_77 = V_69 ;
T_7 V_78 = V_69 >> 32 ;
int V_51 , V_72 , V_79 = - V_80 ;
F_30 ( & V_4 -> V_81 ) ;
V_51 = V_4 -> V_82 -> V_83 ;
F_31 ( & V_4 -> V_81 ) ;
if ( V_77 )
V_79 = F_27 ( V_4 , V_51 , V_52 , V_77 ,
V_63 + V_75 ,
V_54 ) ;
if ( V_78 && V_79 < 0 ) {
V_79 = F_27 ( V_4 , V_51 , V_52 , V_78 ,
V_63 + V_76 ,
V_54 ) ;
if ( V_79 >= 0 )
V_79 += 32 ;
}
* V_29 = V_79 ;
if ( V_54 && V_69 != 0 && V_79 < 0 )
* V_53 = 0 ;
if ( * V_53 == 0 )
return;
V_72 = F_23 ( V_4 , V_51 , V_52 , * V_53 , V_54 ) ;
if ( V_72 < 0 )
* V_53 = 0 ;
if ( V_54 && V_72 < 0 ) {
if ( V_79 >= 0 )
F_28 ( V_4 , V_51 , V_52 , V_79 ) ;
* V_29 = V_72 ;
}
}
