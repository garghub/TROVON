static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_5 == 0 ) {
F_2 ( V_2 -> V_6 -> V_7 , L_1 ) ;
V_2 -> V_8 = false ;
return;
}
V_2 -> V_9 = F_3 ( 1000000ULL * ( V_10 ) V_4 -> V_11 ,
V_4 -> V_5 ) ;
F_2 ( V_2 -> V_6 -> V_7 , L_2 , V_2 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , bool V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 [ V_16 ] ;
struct V_13 * V_17 = V_2 -> V_15 [ V_18 ] ;
struct V_13 * V_19 = V_2 -> V_20 [ V_21 ] ;
struct V_13 * V_22 = V_2 -> V_20 [ V_23 ] ;
struct V_13 * V_24 = V_2 -> V_20 [ V_25 ] ;
struct V_13 * V_26 = V_2 -> V_20 [ V_27 ] ;
struct V_13 * V_28 = V_2 -> V_20 [ V_29 ] ;
if ( V_12 ) {
V_2 -> V_8 = V_19 -> V_30 . V_31 ;
V_2 -> V_32 = V_17 -> V_30 . V_31 ;
V_2 -> V_33 = V_14 -> V_30 . V_31 ;
V_2 -> V_34 = V_22 -> V_30 . V_31 ;
V_2 -> V_35 = V_24 -> V_30 . V_31 ;
V_2 -> V_36 = V_26 -> V_30 . V_31 ;
V_2 -> V_37 = V_28 -> V_30 . V_31 ;
} else {
V_2 -> V_8 = V_19 -> V_31 ;
V_2 -> V_32 = V_17 -> V_31 ;
V_2 -> V_33 = V_14 -> V_31 ;
V_2 -> V_34 = V_22 -> V_31 ;
V_2 -> V_35 = V_24 -> V_31 ;
V_2 -> V_36 = V_26 -> V_31 ;
V_2 -> V_37 = V_28 -> V_31 ;
}
if ( V_2 -> V_37 <= V_2 -> V_36 )
V_2 -> V_37 = 0 ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_35 = F_6 ( int , V_2 -> V_35 , 1 ) ;
V_2 -> V_38 = - V_2 -> V_35 ;
V_2 -> V_39 = 0 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long error )
{
static const struct V_40 V_41 = {
. type = V_42 ,
} ;
F_8 ( V_2 -> V_6 , & V_41 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned long V_45 , error , V_46 ;
bool V_47 = false ;
struct V_43 V_48 ;
if ( ! V_2 -> V_8 || ++ V_2 -> V_38 <= 0 )
goto V_49;
V_48 = F_10 ( * V_44 , V_2 -> V_50 ) ;
V_45 = V_48 . V_51 * 1000 * 1000 + V_48 . V_52 / 1000 ;
error = abs ( V_45 - V_2 -> V_9 ) ;
if ( V_2 -> V_37 && error >= V_2 -> V_37 ) {
F_2 ( V_2 -> V_6 -> V_7 ,
L_3 ,
error ) ;
V_2 -> V_38 -- ;
goto V_49;
}
V_2 -> V_39 += error ;
if ( V_2 -> V_38 == V_2 -> V_34 ) {
V_46 = F_11 ( V_2 -> V_39 , V_2 -> V_34 ) ;
if ( V_46 > V_2 -> V_36 )
V_47 = true ;
F_2 ( V_2 -> V_6 -> V_7 , L_4 ,
V_46 , V_47 ? L_5 : L_6 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
}
V_49:
V_2 -> V_50 = * V_44 ;
if ( V_47 )
F_7 ( V_2 , V_46 ) ;
}
static void F_12 ( int V_53 , void * V_54 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_54 ;
unsigned long V_55 ;
F_13 ( & V_2 -> V_56 , V_55 ) ;
F_9 ( V_2 , V_44 ) ;
if ( ! F_14 ( & V_2 -> V_57 ) )
F_15 ( & V_2 -> V_57 ) ;
F_16 ( & V_2 -> V_56 , V_55 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_57 ) ;
return F_19 ( V_2 -> V_33 ,
F_12 ,
V_2 -> V_32 , V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_33 , V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_58 ;
if ( ! V_2 -> V_8 || V_2 -> V_35 > 0 )
return;
V_58 = F_23 (
& V_2 -> V_57 ,
F_24 ( V_59 ) ) ;
if ( V_58 == 0 )
F_25 ( V_2 -> V_6 , L_7 ) ;
}
static int F_26 ( struct V_13 * V_20 )
{
struct V_1 * V_2 = F_27 ( V_20 -> V_60 ,
struct V_1 ,
V_61 ) ;
unsigned long V_55 ;
int V_58 = 0 ;
F_13 ( & V_2 -> V_56 , V_55 ) ;
switch ( V_20 -> V_62 ) {
case V_63 :
break;
case V_64 :
if ( V_2 -> V_65 )
V_58 = - V_66 ;
break;
default:
V_58 = - V_67 ;
}
if ( ! V_58 )
F_4 ( V_2 , false ) ;
F_16 ( & V_2 -> V_56 , V_55 ) ;
return V_58 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = & V_2 -> V_61 ;
int V_70 , V_58 ;
F_29 ( V_69 , V_71 + V_72 ) ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
V_2 -> V_20 [ V_70 ] = F_30 ( V_69 ,
& V_73 [ V_70 ] ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_72 ; V_70 ++ )
V_2 -> V_15 [ V_70 ] = F_30 ( V_69 ,
& V_74 [ V_70 ] ,
NULL ) ;
if ( V_69 -> error ) {
V_58 = V_69 -> error ;
goto V_75;
}
F_31 ( V_71 , V_2 -> V_20 ) ;
F_31 ( V_72 , V_2 -> V_15 ) ;
return 0 ;
V_75:
F_32 ( V_69 ) ;
return V_58 ;
}
void F_33 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned long V_55 ;
F_13 ( & V_2 -> V_56 , V_55 ) ;
if ( ! F_5 ( V_2 ) )
F_9 ( V_2 , V_44 ) ;
F_16 ( & V_2 -> V_56 , V_55 ) ;
}
int F_34 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
bool V_76 )
{
unsigned long V_55 ;
int V_58 = 0 ;
F_35 ( V_2 -> V_20 [ V_21 ] ) ;
if ( V_2 -> V_65 == V_76 )
goto V_77;
if ( V_76 ) {
F_13 ( & V_2 -> V_56 , V_55 ) ;
F_4 ( V_2 , true ) ;
F_1 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_56 , V_55 ) ;
if ( F_5 ( V_2 ) ) {
V_58 = F_17 ( V_2 ) ;
if ( V_58 )
goto V_77;
F_22 ( V_2 ) ;
}
} else {
if ( F_5 ( V_2 ) )
F_20 ( V_2 ) ;
}
V_2 -> V_65 = V_76 ;
V_77:
F_36 ( V_2 -> V_20 [ V_21 ] ) ;
return V_58 ;
}
int F_37 ( struct V_1 * V_2 )
{
return F_38 ( V_2 -> V_6 -> V_61 ,
& V_2 -> V_61 , NULL ) ;
}
struct V_1 * F_39 ( struct V_78 * V_6 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_40 ( V_6 -> V_7 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_41 ( - V_80 ) ;
V_2 -> V_81 = F_42 ( V_6 -> V_82 -> V_7 ) ;
V_2 -> V_6 = V_6 ;
F_43 ( & V_2 -> V_56 ) ;
V_58 = F_28 ( V_2 ) ;
if ( V_58 )
return F_41 ( V_58 ) ;
return V_2 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_61 ) ;
}
