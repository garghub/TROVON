static T_1 F_1 ( struct V_1 * V_2 , enum V_3 type ,
T_1 V_4 )
{
switch ( type ) {
case V_5 :
V_4 += V_2 -> V_6 ;
break;
case V_7 :
V_4 += V_2 -> V_8 ;
break;
case V_9 :
V_4 += V_2 -> V_10 ;
break;
case V_11 :
V_4 += V_2 -> V_12 ;
break;
case V_13 :
default:
V_4 += V_2 -> V_14 ;
break;
}
V_4 += V_15 ;
return V_4 ;
}
int F_2 ( struct V_1 * V_2 ,
enum V_3 type ,
unsigned int V_4 , void * V_16 , unsigned int V_17 )
{
return F_3 ( V_2 -> V_18 ,
( V_17 == 4 ) ? V_19 :
V_20 ,
F_1 ( V_2 , type , V_4 ) , V_16 , V_17 , 0 ) ;
}
int F_4 ( struct V_1 * V_2 ,
enum V_3 type , unsigned int V_4 ,
void * V_16 , unsigned int V_17 )
{
return F_3 ( V_2 -> V_18 ,
( V_17 == 4 ) ? V_21 :
V_22 ,
F_1 ( V_2 , type , V_4 ) , V_16 , V_17 , 0 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 , T_2 * V_23 )
{
return F_6 ( V_2 , V_24 ,
V_23 , 4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_26 )
{
unsigned int V_27 = 3 ;
unsigned int V_28 ;
T_2 V_23 ;
T_3 V_29 ;
T_3 clock ;
int V_30 ;
V_31:
V_30 = F_5 ( V_2 , & V_23 ) ;
if ( V_30 < 0 )
goto V_32;
clock = F_8 ( V_23 ) ;
if ( V_26 != V_33 ) {
V_29 = V_34 ;
clock &= ~ V_29 ;
clock |= V_26 ;
}
if ( V_25 != V_33 ) {
for ( V_28 = 0 ; V_28 < F_9 ( V_35 ) ; V_28 ++ ) {
if ( V_35 [ V_28 ] == V_25 )
break;
}
if ( V_28 == F_9 ( V_35 ) ) {
V_30 = - V_36 ;
goto V_32;
}
V_29 = V_37 ;
clock &= ~ V_29 ;
clock |= V_28 << V_38 ;
}
V_23 = F_10 ( clock ) ;
if ( F_11 ( & V_2 -> V_39 ) )
F_12 ( & V_2 -> V_39 ) ;
V_30 = F_13 ( V_2 , V_24 ,
& V_23 , 4 ) ;
if ( V_30 < 0 )
goto V_32;
if ( F_14 ( & V_2 -> V_39 ,
F_15 ( V_40 ) ) == 0 ) {
if ( V_27 -- == 0 ) {
V_30 = - V_41 ;
goto V_32;
}
V_30 = F_16 ( V_2 ) ;
if ( V_30 < 0 )
goto V_32;
F_17 ( 500 ) ;
goto V_31;
}
V_32:
return V_30 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int * V_26 )
{
T_2 V_23 ;
int V_30 ;
V_30 = F_5 ( V_2 , & V_23 ) ;
if ( V_30 >= 0 )
* V_26 = F_8 ( V_23 ) & V_34 ;
return V_30 ;
}
int F_19 ( struct V_1 * V_2 , unsigned int * V_25 )
{
T_2 V_23 ;
unsigned int V_42 ;
int V_30 ;
V_30 = F_5 ( V_2 , & V_23 ) ;
if ( V_30 < 0 )
goto V_32;
V_42 = ( F_8 ( V_23 ) & V_37 ) >> V_38 ;
if ( V_42 >= V_43 ) {
V_30 = - V_44 ;
goto V_32;
}
* V_25 = V_35 [ V_42 ] ;
V_32:
return V_30 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_25 )
{
return F_7 ( V_2 , V_25 , V_33 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_45 ;
int V_30 = 0 ;
if ( V_2 -> V_46 )
goto V_32;
V_45 = F_10 ( 1 ) ;
V_30 = F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_47 ) ,
& V_45 , 4 ,
V_48 | V_2 -> V_49 ) ;
if ( V_30 < 0 )
goto V_32;
V_2 -> V_46 = true ;
V_32:
return V_30 ;
}
void F_22 ( struct V_1 * V_2 )
{
T_2 V_45 ;
V_45 = 0 ;
F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_47 ) ,
& V_45 , 4 , V_50 |
V_48 | V_2 -> V_49 ) ;
V_2 -> V_46 = false ;
}
static void F_23 ( struct V_51 * V_52 , struct V_53 * V_54 ,
int V_55 , int V_56 , int V_26 ,
int V_57 , unsigned long long V_4 ,
void * V_58 , T_4 V_59 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
T_3 V_61 ;
unsigned long V_62 ;
if ( V_55 != V_19 ) {
F_24 ( V_52 , V_54 , V_63 ) ;
return;
}
if ( ( V_4 & 3 ) != 0 ) {
F_24 ( V_52 , V_54 , V_64 ) ;
return;
}
V_61 = F_25 ( V_58 ) ;
F_26 ( & V_2 -> V_65 , V_62 ) ;
V_2 -> V_66 |= V_61 ;
F_27 ( & V_2 -> V_65 , V_62 ) ;
F_24 ( V_52 , V_54 , V_67 ) ;
if ( V_61 & V_68 )
F_28 ( & V_2 -> V_39 ) ;
F_29 ( & V_2 -> V_69 ) ;
}
static int F_30 ( struct V_1 * V_2 , bool V_31 )
{
struct V_70 * V_71 = F_31 ( V_2 -> V_18 ) ;
T_5 * V_72 ;
unsigned int V_27 ;
int V_30 ;
V_27 = ( V_31 ) ? 3 : 0 ;
V_72 = F_32 ( 2 * 8 , V_73 ) ;
if ( ! V_72 )
return - V_74 ;
for (; ; ) {
V_72 [ 0 ] = F_33 ( V_75 ) ;
V_72 [ 1 ] = F_33 (
( ( T_1 ) V_71 -> V_52 -> V_76 << V_77 ) |
V_2 -> V_78 . V_4 ) ;
V_2 -> V_49 = V_71 -> V_57 ;
F_34 () ;
V_30 = F_3 ( V_2 -> V_18 , V_79 ,
F_1 ( V_2 ,
V_13 ,
V_80 ) ,
V_72 , 2 * 8 ,
V_48 |
V_2 -> V_49 ) ;
if ( V_30 == 0 ) {
if ( V_72 [ 0 ] == F_33 ( V_75 ) )
break;
if ( V_72 [ 0 ] == V_72 [ 1 ] )
break;
F_35 ( & V_2 -> V_18 -> V_71 ,
L_1 ) ;
V_30 = - V_81 ;
}
if ( V_30 != - V_82 || V_27 -- > 0 )
break;
F_17 ( 20 ) ;
}
F_36 ( V_72 ) ;
if ( V_30 < 0 )
V_2 -> V_49 = - 1 ;
return V_30 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_31 ( V_2 -> V_18 ) ;
T_5 * V_72 ;
V_72 = F_32 ( 2 * 8 , V_73 ) ;
if ( V_72 == NULL )
return;
V_72 [ 0 ] = F_33 (
( ( T_1 ) V_71 -> V_52 -> V_76 << V_77 ) |
V_2 -> V_78 . V_4 ) ;
V_72 [ 1 ] = F_33 ( V_75 ) ;
F_3 ( V_2 -> V_18 , V_79 ,
F_1 ( V_2 , V_13 ,
V_80 ) ,
V_72 , 2 * 8 , V_50 |
V_48 | V_2 -> V_49 ) ;
F_36 ( V_72 ) ;
V_2 -> V_49 = - 1 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
if ( V_84 -> V_60 == NULL )
return;
F_37 ( V_2 ) ;
F_39 ( V_84 ) ;
V_84 -> V_60 = NULL ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
if ( V_84 -> V_60 == NULL )
return - V_36 ;
return F_30 ( V_2 , false ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
T_2 * V_85 ;
int V_30 ;
V_85 = F_32 ( sizeof( T_2 ) * 10 , V_73 ) ;
if ( V_85 == NULL )
return - V_74 ;
V_30 = F_3 ( V_2 -> V_18 , V_22 ,
V_15 ,
V_85 , sizeof( T_2 ) * 10 , 0 ) ;
if ( V_30 < 0 )
goto V_32;
V_84 -> V_59 = 4 ;
V_84 -> V_86 = F_23 ;
V_84 -> V_60 = V_2 ;
V_30 = F_41 ( V_84 , & V_87 ) ;
if ( V_30 < 0 ) {
V_84 -> V_60 = NULL ;
goto V_32;
}
V_30 = F_30 ( V_2 , true ) ;
if ( V_30 < 0 ) {
F_39 ( V_84 ) ;
V_84 -> V_60 = NULL ;
goto V_32;
}
V_2 -> V_14 = F_8 ( V_85 [ 0 ] ) * 4 ;
V_2 -> V_6 = F_8 ( V_85 [ 2 ] ) * 4 ;
V_2 -> V_8 = F_8 ( V_85 [ 4 ] ) * 4 ;
V_2 -> V_10 = F_8 ( V_85 [ 6 ] ) * 4 ;
V_2 -> V_12 = F_8 ( V_85 [ 8 ] ) * 4 ;
if ( F_8 ( V_85 [ 1 ] ) * 4 >= V_88 + 4 )
V_2 -> V_89 = 1 ;
V_32:
F_36 ( V_85 ) ;
return V_30 ;
}
