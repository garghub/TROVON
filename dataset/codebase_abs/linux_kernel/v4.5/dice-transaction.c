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
unsigned int V_27 ;
T_2 V_23 ;
T_3 V_28 ;
T_3 clock ;
int V_29 ;
V_29 = F_5 ( V_2 , & V_23 ) ;
if ( V_29 < 0 )
return V_29 ;
clock = F_8 ( V_23 ) ;
if ( V_26 != V_30 ) {
V_28 = V_31 ;
clock &= ~ V_28 ;
clock |= V_26 ;
}
if ( V_25 != V_30 ) {
for ( V_27 = 0 ; V_27 < F_9 ( V_32 ) ; V_27 ++ ) {
if ( V_32 [ V_27 ] == V_25 )
break;
}
if ( V_27 == F_9 ( V_32 ) )
return - V_33 ;
V_28 = V_34 ;
clock &= ~ V_28 ;
clock |= V_27 << V_35 ;
}
V_23 = F_10 ( clock ) ;
if ( F_11 ( & V_2 -> V_36 ) )
F_12 ( & V_2 -> V_36 ) ;
V_29 = F_13 ( V_2 , V_24 ,
& V_23 , 4 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( F_14 ( & V_2 -> V_36 ,
F_15 ( V_37 ) ) == 0 )
return - V_38 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
unsigned int * V_26 )
{
T_2 V_23 ;
int V_29 ;
V_29 = F_5 ( V_2 , & V_23 ) ;
if ( V_29 >= 0 )
* V_26 = F_8 ( V_23 ) & V_31 ;
return V_29 ;
}
int F_17 ( struct V_1 * V_2 , unsigned int * V_25 )
{
T_2 V_23 ;
unsigned int V_39 ;
int V_29 ;
V_29 = F_5 ( V_2 , & V_23 ) ;
if ( V_29 < 0 )
goto V_40;
V_39 = ( F_8 ( V_23 ) & V_34 ) >> V_35 ;
if ( V_39 >= V_41 ) {
V_29 = - V_42 ;
goto V_40;
}
* V_25 = V_32 [ V_39 ] ;
V_40:
return V_29 ;
}
int F_18 ( struct V_1 * V_2 , unsigned int V_25 )
{
return F_7 ( V_2 , V_25 , V_30 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
T_2 V_43 ;
int V_29 = 0 ;
if ( V_2 -> V_44 )
goto V_40;
V_43 = F_10 ( 1 ) ;
V_29 = F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_45 ) ,
& V_43 , 4 ,
V_46 | V_2 -> V_47 ) ;
if ( V_29 < 0 )
goto V_40;
V_2 -> V_44 = true ;
V_40:
return V_29 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_2 V_43 ;
V_43 = 0 ;
F_3 ( V_2 -> V_18 , V_19 ,
F_1 ( V_2 , V_13 ,
V_45 ) ,
& V_43 , 4 , V_48 |
V_46 | V_2 -> V_47 ) ;
V_2 -> V_44 = false ;
}
static void F_21 ( struct V_49 * V_50 , struct V_51 * V_52 ,
int V_53 , int V_54 , int V_26 ,
int V_55 , unsigned long long V_4 ,
void * V_56 , T_4 V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_3 V_59 ;
unsigned long V_60 ;
if ( V_53 != V_19 ) {
F_22 ( V_50 , V_52 , V_61 ) ;
return;
}
if ( ( V_4 & 3 ) != 0 ) {
F_22 ( V_50 , V_52 , V_62 ) ;
return;
}
V_59 = F_23 ( V_56 ) ;
F_24 ( & V_2 -> V_63 , V_60 ) ;
V_2 -> V_64 |= V_59 ;
F_25 ( & V_2 -> V_63 , V_60 ) ;
F_22 ( V_50 , V_52 , V_65 ) ;
if ( V_59 & V_66 )
F_26 ( & V_2 -> V_36 ) ;
F_27 ( & V_2 -> V_67 ) ;
}
static int F_28 ( struct V_1 * V_2 , bool V_68 )
{
struct V_69 * V_70 = F_29 ( V_2 -> V_18 ) ;
T_5 * V_71 ;
unsigned int V_72 ;
int V_29 ;
V_72 = ( V_68 ) ? 3 : 0 ;
V_71 = F_30 ( 2 * 8 , V_73 ) ;
if ( ! V_71 )
return - V_74 ;
for (; ; ) {
V_71 [ 0 ] = F_31 ( V_75 ) ;
V_71 [ 1 ] = F_31 (
( ( T_1 ) V_70 -> V_50 -> V_76 << V_77 ) |
V_2 -> V_78 . V_4 ) ;
V_2 -> V_47 = V_70 -> V_55 ;
F_32 () ;
V_29 = F_3 ( V_2 -> V_18 , V_79 ,
F_1 ( V_2 ,
V_13 ,
V_80 ) ,
V_71 , 2 * 8 ,
V_46 |
V_2 -> V_47 ) ;
if ( V_29 == 0 ) {
if ( V_71 [ 0 ] == F_31 ( V_75 ) )
break;
if ( V_71 [ 0 ] == V_71 [ 1 ] )
break;
F_33 ( & V_2 -> V_18 -> V_70 ,
L_1 ) ;
V_29 = - V_81 ;
}
if ( V_29 != - V_82 || V_72 -- > 0 )
break;
F_34 ( 20 ) ;
}
F_35 ( V_71 ) ;
if ( V_29 < 0 )
V_2 -> V_47 = - 1 ;
return V_29 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = F_29 ( V_2 -> V_18 ) ;
T_5 * V_71 ;
V_71 = F_30 ( 2 * 8 , V_73 ) ;
if ( V_71 == NULL )
return;
V_71 [ 0 ] = F_31 (
( ( T_1 ) V_70 -> V_50 -> V_76 << V_77 ) |
V_2 -> V_78 . V_4 ) ;
V_71 [ 1 ] = F_31 ( V_75 ) ;
F_3 ( V_2 -> V_18 , V_79 ,
F_1 ( V_2 , V_13 ,
V_80 ) ,
V_71 , 2 * 8 , V_48 |
V_46 | V_2 -> V_47 ) ;
F_35 ( V_71 ) ;
V_2 -> V_47 = - 1 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
if ( V_84 -> V_58 == NULL )
return;
F_36 ( V_2 ) ;
F_38 ( V_84 ) ;
V_84 -> V_58 = NULL ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
if ( V_84 -> V_58 == NULL )
return - V_33 ;
return F_28 ( V_2 , false ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
static const int V_85 [ 10 ] = {
10 , 0x64 / 4 ,
10 , 0x18 / 4 ,
10 , 0x18 / 4 ,
0 , 0 ,
0 , 0 ,
} ;
T_2 * V_86 ;
T_2 V_87 ;
T_3 V_56 ;
unsigned int V_27 ;
int V_29 ;
V_86 = F_41 ( F_9 ( V_85 ) , sizeof( T_2 ) ,
V_73 ) ;
if ( V_86 == NULL )
return - V_74 ;
V_29 = F_3 ( V_2 -> V_18 , V_22 ,
V_15 , V_86 ,
sizeof( T_2 ) * F_9 ( V_85 ) , 0 ) ;
if ( V_29 < 0 )
goto V_40;
for ( V_27 = 0 ; V_27 < F_9 ( V_85 ) ; ++ V_27 ) {
V_56 = F_8 ( V_86 [ V_27 ] ) ;
if ( V_56 < V_85 [ V_27 ] || V_56 >= 0x40000 ) {
V_29 = - V_88 ;
goto V_40;
}
}
V_29 = F_3 ( V_2 -> V_18 , V_21 ,
V_15 +
F_8 ( V_86 [ 0 ] ) * 4 + V_89 ,
& V_87 , sizeof( V_87 ) , 0 ) ;
if ( V_29 < 0 )
goto V_40;
if ( ( V_87 & F_10 ( 0xff000000 ) ) != F_10 ( 0x01000000 ) ) {
F_33 ( & V_2 -> V_18 -> V_70 ,
L_2 , F_8 ( V_87 ) ) ;
V_29 = - V_88 ;
goto V_40;
}
V_2 -> V_14 = F_8 ( V_86 [ 0 ] ) * 4 ;
V_2 -> V_6 = F_8 ( V_86 [ 2 ] ) * 4 ;
V_2 -> V_8 = F_8 ( V_86 [ 4 ] ) * 4 ;
V_2 -> V_10 = F_8 ( V_86 [ 6 ] ) * 4 ;
V_2 -> V_12 = F_8 ( V_86 [ 8 ] ) * 4 ;
if ( F_8 ( V_86 [ 1 ] ) * 4 >= V_90 + 4 )
V_2 -> V_91 = 1 ;
V_40:
F_35 ( V_86 ) ;
return V_29 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_78 ;
int V_29 ;
V_29 = F_40 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_84 -> V_57 = 4 ;
V_84 -> V_92 = F_21 ;
V_84 -> V_58 = V_2 ;
V_29 = F_43 ( V_84 , & V_93 ) ;
if ( V_29 < 0 ) {
V_84 -> V_58 = NULL ;
return V_29 ;
}
V_29 = F_28 ( V_2 , true ) ;
if ( V_29 < 0 ) {
F_38 ( V_84 ) ;
V_84 -> V_58 = NULL ;
}
return V_29 ;
}
