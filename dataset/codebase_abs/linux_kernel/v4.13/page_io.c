static struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_3 , T_2 V_4 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , 1 ) ;
if ( V_1 ) {
V_1 -> V_5 . V_6 = F_3 ( V_3 , & V_1 -> V_7 ) ;
V_1 -> V_5 . V_6 <<= V_8 - 9 ;
V_1 -> V_9 = V_4 ;
F_4 ( V_1 , V_3 , V_10 , 0 ) ;
F_5 ( V_1 -> V_5 . V_11 != V_10 ) ;
}
return V_1 ;
}
void F_6 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_12 [ 0 ] . V_13 ;
if ( V_1 -> V_14 ) {
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( L_1 ,
F_10 ( V_1 -> V_7 -> V_15 ) ,
F_11 ( V_1 -> V_7 -> V_15 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
F_12 ( V_3 ) ;
}
F_13 ( V_3 ) ;
F_14 ( V_1 ) ;
}
static void F_15 ( struct V_3 * V_3 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
if ( F_16 ( ! F_17 ( V_3 ) ) )
return;
V_17 = F_18 ( V_3 ) ;
if ( ! ( V_17 -> V_20 & V_21 ) )
return;
V_19 = V_17 -> V_22 -> V_23 ;
if ( V_19 -> V_24 -> F_15 ) {
T_3 V_25 ;
unsigned long V_26 ;
V_25 . V_27 = F_19 ( V_3 ) ;
V_26 = F_20 ( V_25 ) ;
F_21 ( V_3 ) ;
V_19 -> V_24 -> F_15 ( V_17 -> V_22 ,
V_26 ) ;
}
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_12 [ 0 ] . V_13 ;
struct V_28 * V_29 = V_1 -> V_30 ;
if ( V_1 -> V_14 ) {
F_7 ( V_3 ) ;
F_23 ( V_3 ) ;
F_9 ( L_2 ,
F_10 ( V_1 -> V_7 -> V_15 ) ,
F_11 ( V_1 -> V_7 -> V_15 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
goto V_31;
}
F_24 ( V_3 ) ;
F_15 ( V_3 ) ;
V_31:
F_25 ( V_3 ) ;
F_26 ( V_1 -> V_30 , NULL ) ;
F_14 ( V_1 ) ;
F_27 ( V_29 ) ;
F_28 ( V_29 ) ;
}
int F_29 ( struct V_16 * V_17 ,
struct V_32 * V_33 ,
T_4 * V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_38 = V_36 -> V_39 ;
unsigned V_40 ;
unsigned long V_41 ;
unsigned V_42 ;
T_4 V_43 ;
T_4 V_44 ;
T_4 V_45 = - 1 ;
T_4 V_46 = 0 ;
int V_47 = 0 ;
int V_48 ;
V_42 = V_38 -> V_49 ;
V_40 = V_10 >> V_42 ;
V_43 = 0 ;
V_41 = 0 ;
V_44 = F_30 ( V_38 ) >> V_42 ;
while ( ( V_43 + V_40 ) <= V_44 &&
V_41 < V_17 -> V_50 ) {
unsigned V_51 ;
T_4 V_52 ;
F_31 () ;
V_52 = F_32 ( V_38 , V_43 ) ;
if ( V_52 == 0 )
goto V_53;
if ( V_52 & ( V_40 - 1 ) ) {
V_43 ++ ;
goto V_54;
}
for ( V_51 = 1 ; V_51 < V_40 ;
V_51 ++ ) {
T_4 V_55 ;
V_55 = F_32 ( V_38 , V_43 + V_51 ) ;
if ( V_55 == 0 )
goto V_53;
if ( V_55 != V_52 + V_51 ) {
V_43 ++ ;
goto V_54;
}
}
V_52 >>= ( V_8 - V_42 ) ;
if ( V_41 ) {
if ( V_52 < V_45 )
V_45 = V_52 ;
if ( V_52 > V_46 )
V_46 = V_52 ;
}
V_48 = F_33 ( V_17 , V_41 , 1 , V_52 ) ;
if ( V_48 < 0 )
goto V_31;
V_47 += V_48 ;
V_41 ++ ;
V_43 += V_40 ;
V_54:
continue;
}
V_48 = V_47 ;
* V_34 = 1 + V_46 - V_45 ;
if ( V_41 == 0 )
V_41 = 1 ;
V_17 -> V_50 = V_41 ;
V_17 -> V_56 = V_41 - 1 ;
V_17 -> V_57 = V_41 - 1 ;
V_31:
return V_48 ;
V_53:
F_34 ( L_3 ) ;
V_48 = - V_58 ;
goto V_31;
}
int F_35 ( struct V_3 * V_3 , struct V_59 * V_60 )
{
int V_48 = 0 ;
if ( F_36 ( V_3 ) ) {
F_25 ( V_3 ) ;
goto V_31;
}
if ( F_37 ( V_3 ) == 0 ) {
F_38 ( V_3 ) ;
F_25 ( V_3 ) ;
F_13 ( V_3 ) ;
goto V_31;
}
V_48 = F_39 ( V_3 , V_60 , F_6 ) ;
V_31:
return V_48 ;
}
static T_4 F_40 ( struct V_3 * V_3 )
{
return ( T_4 ) F_41 ( V_3 ) << ( V_8 - 9 ) ;
}
int F_39 ( struct V_3 * V_3 , struct V_59 * V_60 ,
T_2 V_61 )
{
struct V_1 * V_1 ;
int V_48 ;
struct V_16 * V_17 = F_18 ( V_3 ) ;
F_42 ( ! F_17 ( V_3 ) , V_3 ) ;
if ( V_17 -> V_20 & V_62 ) {
struct V_63 V_63 ;
struct V_32 * V_33 = V_17 -> V_33 ;
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_64 V_65 = {
. V_13 = V_3 ,
. V_66 = V_10 ,
. V_67 = 0
} ;
struct V_68 V_69 ;
F_43 ( & V_69 , V_70 | V_71 , & V_65 , 1 , V_10 ) ;
F_44 ( & V_63 , V_33 ) ;
V_63 . V_72 = F_45 ( V_3 ) ;
F_38 ( V_3 ) ;
F_25 ( V_3 ) ;
V_48 = V_36 -> V_73 -> V_74 ( & V_63 , & V_69 ) ;
if ( V_48 == V_10 ) {
F_46 ( V_75 ) ;
V_48 = 0 ;
} else {
F_8 ( V_3 ) ;
F_12 ( V_3 ) ;
F_47 ( L_4 ,
F_45 ( V_3 ) ) ;
}
F_13 ( V_3 ) ;
return V_48 ;
}
V_48 = F_48 ( V_17 -> V_22 , F_40 ( V_3 ) , V_3 , V_60 ) ;
if ( ! V_48 ) {
F_46 ( V_75 ) ;
return 0 ;
}
V_48 = 0 ;
V_1 = F_1 ( V_76 , V_3 , V_61 ) ;
if ( V_1 == NULL ) {
F_8 ( V_3 ) ;
F_25 ( V_3 ) ;
V_48 = - V_77 ;
goto V_31;
}
V_1 -> V_78 = V_79 | F_49 ( V_60 ) ;
F_46 ( V_75 ) ;
F_38 ( V_3 ) ;
F_25 ( V_3 ) ;
F_50 ( V_1 ) ;
V_31:
return V_48 ;
}
int F_51 ( struct V_3 * V_3 , bool V_80 )
{
struct V_1 * V_1 ;
int V_48 = 0 ;
struct V_16 * V_17 = F_18 ( V_3 ) ;
T_5 V_81 ;
struct V_82 * V_22 ;
F_42 ( ! F_17 ( V_3 ) , V_3 ) ;
F_42 ( ! F_52 ( V_3 ) , V_3 ) ;
F_42 ( F_53 ( V_3 ) , V_3 ) ;
if ( F_54 ( V_3 ) == 0 ) {
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
goto V_31;
}
if ( V_17 -> V_20 & V_62 ) {
struct V_32 * V_33 = V_17 -> V_33 ;
struct V_35 * V_36 = V_33 -> V_37 ;
V_48 = V_36 -> V_73 -> V_83 ( V_33 , V_3 ) ;
if ( ! V_48 )
F_46 ( V_84 ) ;
return V_48 ;
}
V_48 = F_55 ( V_17 -> V_22 , F_40 ( V_3 ) , V_3 ) ;
if ( ! V_48 ) {
if ( F_56 ( V_3 ) ) {
F_15 ( V_3 ) ;
F_25 ( V_3 ) ;
}
F_46 ( V_84 ) ;
return 0 ;
}
V_48 = 0 ;
V_1 = F_1 ( V_85 , V_3 , F_22 ) ;
if ( V_1 == NULL ) {
F_25 ( V_3 ) ;
V_48 = - V_77 ;
goto V_31;
}
V_22 = V_1 -> V_7 ;
F_57 ( V_86 ) ;
V_1 -> V_30 = V_86 ;
F_58 ( V_1 , V_87 , 0 ) ;
F_46 ( V_84 ) ;
F_59 ( V_1 ) ;
V_81 = F_50 ( V_1 ) ;
while ( V_80 ) {
F_60 ( V_88 ) ;
if ( ! F_61 ( V_1 -> V_30 ) )
break;
if ( ! F_62 ( F_63 ( V_22 ) , V_81 ) )
break;
}
F_64 ( V_89 ) ;
F_14 ( V_1 ) ;
V_31:
return V_48 ;
}
int F_65 ( struct V_3 * V_3 )
{
struct V_16 * V_17 = F_18 ( V_3 ) ;
if ( V_17 -> V_20 & V_62 ) {
struct V_35 * V_36 = V_17 -> V_33 -> V_37 ;
F_42 ( ! F_17 ( V_3 ) , V_3 ) ;
return V_36 -> V_73 -> F_8 ( V_3 ) ;
} else {
return F_66 ( V_3 ) ;
}
}
