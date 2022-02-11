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
int F_23 ( struct V_28 * V_34 )
{
return V_34 -> V_4 -> V_35 -> V_51 ( V_34 ) ;
}
static int F_24 ( struct V_3 * V_4 , int V_52 , int V_53 ,
int V_54 , bool V_55 )
{
int V_56 , V_57 , V_58 = V_55 ? V_59 : 0 ;
T_6 V_60 [ 2 ] ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
V_57 = V_55 ? V_58 - V_54 : V_58 + V_54 ;
if ( V_57 < 0 || V_57 > V_59 )
return - V_61 ;
V_60 [ 0 ] = F_25 ( V_58 ) ;
V_60 [ 1 ] = F_25 ( V_57 ) ;
switch ( F_26 ( V_4 , V_62 ,
V_52 , V_53 , V_63 ,
V_64 + V_65 ,
V_60 , 8 ) ) {
case V_66 :
return V_55 ? - V_67 : V_54 ;
case V_68 :
if ( F_27 ( V_60 ) == V_58 )
return V_54 ;
V_58 = F_27 ( V_60 ) ;
}
}
return - V_69 ;
}
static int F_28 ( struct V_3 * V_4 , int V_52 , int V_53 ,
T_7 V_70 , T_5 V_26 , bool V_55 )
{
T_6 V_71 , V_72 , V_58 ;
T_6 V_60 [ 2 ] ;
int V_29 , V_73 = - V_69 , V_74 = 5 ;
V_58 = V_72 = V_55 ? F_25 ( ~ 0 ) : 0 ;
for ( V_29 = 0 ; V_29 < 32 ; V_29 ++ ) {
if ( ! ( V_70 & 1 << V_29 ) )
continue;
V_73 = - V_61 ;
V_71 = F_25 ( 1 << ( 31 - V_29 ) ) ;
if ( ( V_58 & V_71 ) != ( V_72 & V_71 ) )
continue;
V_60 [ 0 ] = V_58 ;
V_60 [ 1 ] = V_58 ^ V_71 ;
switch ( F_26 ( V_4 , V_62 ,
V_52 , V_53 , V_63 ,
V_26 , V_60 , 8 ) ) {
case V_66 :
return V_55 ? - V_67 : V_29 ;
case V_68 :
if ( V_60 [ 0 ] == V_58 )
return V_29 ;
V_58 = V_60 [ 0 ] ;
if ( ( V_60 [ 0 ] & V_71 ) == ( V_60 [ 1 ] & V_71 ) )
continue;
default:
if ( V_74 ) {
V_74 -- ;
V_29 -- ;
} else {
V_73 = - V_69 ;
}
}
}
return V_73 ;
}
static void F_29 ( struct V_3 * V_4 , int V_52 ,
int V_53 , int V_29 )
{
T_7 V_75 ;
T_5 V_26 ;
V_75 = V_29 < 32 ? 1 << V_29 : 1 << ( V_29 - 32 ) ;
V_26 = V_29 < 32 ? V_64 + V_76 :
V_64 + V_77 ;
F_28 ( V_4 , V_52 , V_53 , V_75 , V_26 , false ) ;
}
void F_30 ( struct V_3 * V_4 , int V_53 ,
T_5 V_70 , int * V_29 , int * V_54 ,
bool V_55 )
{
T_7 V_78 = V_70 ;
T_7 V_79 = V_70 >> 32 ;
int V_52 , V_73 , V_80 = - V_81 ;
F_31 ( & V_4 -> V_82 ) ;
V_52 = V_4 -> V_83 -> V_84 ;
F_32 ( & V_4 -> V_82 ) ;
if ( V_78 )
V_80 = F_28 ( V_4 , V_52 , V_53 , V_78 ,
V_64 + V_76 ,
V_55 ) ;
if ( V_79 && V_80 < 0 ) {
V_80 = F_28 ( V_4 , V_52 , V_53 , V_79 ,
V_64 + V_77 ,
V_55 ) ;
if ( V_80 >= 0 )
V_80 += 32 ;
}
* V_29 = V_80 ;
if ( V_55 && V_70 != 0 && V_80 < 0 )
* V_54 = 0 ;
if ( * V_54 == 0 )
return;
V_73 = F_24 ( V_4 , V_52 , V_53 , * V_54 , V_55 ) ;
if ( V_73 < 0 )
* V_54 = 0 ;
if ( V_55 && V_73 < 0 ) {
if ( V_80 >= 0 )
F_29 ( V_4 , V_52 , V_53 , V_80 ) ;
* V_29 = V_73 ;
}
}
