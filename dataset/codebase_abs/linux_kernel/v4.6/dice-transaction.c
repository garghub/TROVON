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
int F_7 ( struct V_1 * V_2 ,
unsigned int * V_25 )
{
T_2 V_23 ;
int V_26 ;
V_26 = F_5 ( V_2 , & V_23 ) ;
if ( V_26 >= 0 )
* V_25 = F_8 ( V_23 ) & V_27 ;
return V_26 ;
}
int F_9 ( struct V_1 * V_2 , unsigned int * V_28 )
{
T_2 V_23 ;
unsigned int V_29 ;
int V_26 ;
V_26 = F_5 ( V_2 , & V_23 ) ;
if ( V_26 < 0 )
goto V_30;
V_29 = ( F_8 ( V_23 ) & V_31 ) >> V_32 ;
if ( V_29 >= V_33 ) {
V_26 = - V_34 ;
goto V_30;
}
* V_28 = V_35 [ V_29 ] ;
V_30:
return V_26 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_2 V_36 ;
int V_26 = 0 ;
if ( V_2 -> V_37 )
goto V_30;
V_36 = F_11 ( 1 ) ;
V_26 = F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_38 ) ,
& V_36 , 4 ,
V_39 | V_2 -> V_40 ) ;
if ( V_26 < 0 )
goto V_30;
V_2 -> V_37 = true ;
V_30:
return V_26 ;
}
void F_12 ( struct V_1 * V_2 )
{
T_2 V_36 ;
V_36 = 0 ;
F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_38 ) ,
& V_36 , 4 , V_41 |
V_39 | V_2 -> V_40 ) ;
V_2 -> V_37 = false ;
}
static void F_13 ( struct V_42 * V_43 , struct V_44 * V_45 ,
int V_46 , int V_47 , int V_25 ,
int V_48 , unsigned long long V_4 ,
void * V_49 , T_3 V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
T_4 V_52 ;
unsigned long V_53 ;
if ( V_46 != V_19 ) {
F_14 ( V_43 , V_45 , V_54 ) ;
return;
}
if ( ( V_4 & 3 ) != 0 ) {
F_14 ( V_43 , V_45 , V_55 ) ;
return;
}
V_52 = F_15 ( V_49 ) ;
F_16 ( & V_2 -> V_56 , V_53 ) ;
V_2 -> V_57 |= V_52 ;
F_17 ( & V_2 -> V_56 , V_53 ) ;
F_14 ( V_43 , V_45 , V_58 ) ;
if ( V_52 & V_59 )
F_18 ( & V_2 -> V_60 ) ;
F_19 ( & V_2 -> V_61 ) ;
}
static int F_20 ( struct V_1 * V_2 , bool V_62 )
{
struct V_63 * V_64 = F_21 ( V_2 -> V_18 ) ;
T_5 * V_65 ;
unsigned int V_66 ;
int V_26 ;
V_66 = ( V_62 ) ? 3 : 0 ;
V_65 = F_22 ( 2 * 8 , V_67 ) ;
if ( ! V_65 )
return - V_68 ;
for (; ; ) {
V_65 [ 0 ] = F_23 ( V_69 ) ;
V_65 [ 1 ] = F_23 (
( ( T_1 ) V_64 -> V_43 -> V_70 << V_71 ) |
V_2 -> V_72 . V_4 ) ;
V_2 -> V_40 = V_64 -> V_48 ;
F_24 () ;
V_26 = F_3 ( V_2 -> V_18 , V_73 ,
F_1 ( V_2 ,
V_13 ,
V_74 ) ,
V_65 , 2 * 8 ,
V_39 |
V_2 -> V_40 ) ;
if ( V_26 == 0 ) {
if ( V_65 [ 0 ] == F_23 ( V_69 ) )
break;
if ( V_65 [ 0 ] == V_65 [ 1 ] )
break;
F_25 ( & V_2 -> V_18 -> V_64 ,
L_1 ) ;
V_26 = - V_75 ;
}
if ( V_26 != - V_76 || V_66 -- > 0 )
break;
F_26 ( 20 ) ;
}
F_27 ( V_65 ) ;
if ( V_26 < 0 )
V_2 -> V_40 = - 1 ;
return V_26 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = F_21 ( V_2 -> V_18 ) ;
T_5 * V_65 ;
V_65 = F_22 ( 2 * 8 , V_67 ) ;
if ( V_65 == NULL )
return;
V_65 [ 0 ] = F_23 (
( ( T_1 ) V_64 -> V_43 -> V_70 << V_71 ) |
V_2 -> V_72 . V_4 ) ;
V_65 [ 1 ] = F_23 ( V_69 ) ;
F_3 ( V_2 -> V_18 , V_73 ,
F_1 ( V_2 , V_13 ,
V_74 ) ,
V_65 , 2 * 8 , V_41 |
V_39 | V_2 -> V_40 ) ;
F_27 ( V_65 ) ;
V_2 -> V_40 = - 1 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_72 ;
if ( V_78 -> V_51 == NULL )
return;
F_28 ( V_2 ) ;
F_30 ( V_78 ) ;
V_78 -> V_51 = NULL ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_72 ;
if ( V_78 -> V_51 == NULL )
return - V_79 ;
return F_20 ( V_2 , false ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
static const int V_80 [ 10 ] = {
10 , 0x64 / 4 ,
10 , 0x18 / 4 ,
10 , 0x18 / 4 ,
0 , 0 ,
0 , 0 ,
} ;
T_2 * V_81 ;
T_2 V_82 ;
T_4 V_49 ;
unsigned int V_83 ;
int V_26 ;
V_81 = F_33 ( F_34 ( V_80 ) , sizeof( T_2 ) ,
V_67 ) ;
if ( V_81 == NULL )
return - V_68 ;
V_26 = F_3 ( V_2 -> V_18 , V_22 ,
V_15 , V_81 ,
sizeof( T_2 ) * F_34 ( V_80 ) , 0 ) ;
if ( V_26 < 0 )
goto V_30;
for ( V_83 = 0 ; V_83 < F_34 ( V_80 ) ; ++ V_83 ) {
V_49 = F_8 ( V_81 [ V_83 ] ) ;
if ( V_49 < V_80 [ V_83 ] || V_49 >= 0x40000 ) {
V_26 = - V_84 ;
goto V_30;
}
}
V_26 = F_3 ( V_2 -> V_18 , V_21 ,
V_15 +
F_8 ( V_81 [ 0 ] ) * 4 + V_85 ,
& V_82 , sizeof( V_82 ) , 0 ) ;
if ( V_26 < 0 )
goto V_30;
if ( ( V_82 & F_11 ( 0xff000000 ) ) != F_11 ( 0x01000000 ) ) {
F_25 ( & V_2 -> V_18 -> V_64 ,
L_2 , F_8 ( V_82 ) ) ;
V_26 = - V_84 ;
goto V_30;
}
V_2 -> V_14 = F_8 ( V_81 [ 0 ] ) * 4 ;
V_2 -> V_6 = F_8 ( V_81 [ 2 ] ) * 4 ;
V_2 -> V_8 = F_8 ( V_81 [ 4 ] ) * 4 ;
V_2 -> V_10 = F_8 ( V_81 [ 6 ] ) * 4 ;
V_2 -> V_12 = F_8 ( V_81 [ 8 ] ) * 4 ;
if ( F_8 ( V_81 [ 1 ] ) * 4 >= V_86 + 4 )
V_2 -> V_87 = 1 ;
V_30:
F_27 ( V_81 ) ;
return V_26 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_72 ;
int V_26 ;
V_26 = F_32 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
V_78 -> V_50 = 4 ;
V_78 -> V_88 = F_13 ;
V_78 -> V_51 = V_2 ;
V_26 = F_36 ( V_78 , & V_89 ) ;
if ( V_26 < 0 ) {
V_78 -> V_51 = NULL ;
return V_26 ;
}
V_26 = F_20 ( V_2 , true ) ;
if ( V_26 < 0 ) {
F_30 ( V_78 ) ;
V_78 -> V_51 = NULL ;
}
return V_26 ;
}
