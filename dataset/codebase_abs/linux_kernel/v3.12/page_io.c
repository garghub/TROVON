static struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_3 , T_2 V_4 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , 1 ) ;
if ( V_1 ) {
V_1 -> V_5 = F_3 ( V_3 , & V_1 -> V_6 ) ;
V_1 -> V_5 <<= V_7 - 9 ;
V_1 -> V_8 [ 0 ] . V_9 = V_3 ;
V_1 -> V_8 [ 0 ] . V_10 = V_11 ;
V_1 -> V_8 [ 0 ] . V_12 = 0 ;
V_1 -> V_13 = 1 ;
V_1 -> V_14 = V_11 ;
V_1 -> V_15 = V_4 ;
}
return V_1 ;
}
void F_4 ( struct V_1 * V_1 , int V_16 )
{
const int V_17 = F_5 ( V_18 , & V_1 -> V_19 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_17 ) {
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_20 L_1 ,
F_9 ( V_1 -> V_6 -> V_21 ) ,
F_10 ( V_1 -> V_6 -> V_21 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
F_11 ( V_3 ) ;
}
F_12 ( V_3 ) ;
F_13 ( V_1 ) ;
}
void F_14 ( struct V_1 * V_1 , int V_16 )
{
const int V_17 = F_5 ( V_18 , & V_1 -> V_19 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_17 ) {
F_6 ( V_3 ) ;
F_15 ( V_3 ) ;
F_8 ( V_20 L_2 ,
F_9 ( V_1 -> V_6 -> V_21 ) ,
F_10 ( V_1 -> V_6 -> V_21 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
goto V_22;
}
F_16 ( V_3 ) ;
if ( F_17 ( F_18 ( V_3 ) ) ) {
struct V_23 * V_24 ;
V_24 = F_19 ( V_3 ) ;
if ( V_24 -> V_25 & V_26 ) {
struct V_27 * V_28 = V_24 -> V_29 -> V_30 ;
if ( V_28 -> V_31 -> V_32 ) {
T_3 V_33 ;
unsigned long V_34 ;
V_33 . V_35 = F_20 ( V_3 ) ;
V_34 = F_21 ( V_33 ) ;
F_22 ( V_3 ) ;
V_28 -> V_31 -> V_32 ( V_24 -> V_29 ,
V_34 ) ;
}
}
}
V_22:
F_23 ( V_3 ) ;
F_13 ( V_1 ) ;
}
int F_24 ( struct V_23 * V_24 ,
struct V_36 * V_37 ,
T_4 * V_38 )
{
struct V_39 * V_40 = V_37 -> V_41 ;
struct V_42 * V_42 = V_40 -> V_43 ;
unsigned V_44 ;
unsigned long V_45 ;
unsigned V_46 ;
T_4 V_47 ;
T_4 V_48 ;
T_4 V_49 = - 1 ;
T_4 V_50 = 0 ;
int V_51 = 0 ;
int V_52 ;
V_46 = V_42 -> V_53 ;
V_44 = V_11 >> V_46 ;
V_47 = 0 ;
V_45 = 0 ;
V_48 = F_25 ( V_42 ) >> V_46 ;
while ( ( V_47 + V_44 ) <= V_48 &&
V_45 < V_24 -> V_54 ) {
unsigned V_55 ;
T_4 V_56 ;
V_56 = F_26 ( V_42 , V_47 ) ;
if ( V_56 == 0 )
goto V_57;
if ( V_56 & ( V_44 - 1 ) ) {
V_47 ++ ;
goto V_58;
}
for ( V_55 = 1 ; V_55 < V_44 ;
V_55 ++ ) {
T_4 V_59 ;
V_59 = F_26 ( V_42 , V_47 + V_55 ) ;
if ( V_59 == 0 )
goto V_57;
if ( V_59 != V_56 + V_55 ) {
V_47 ++ ;
goto V_58;
}
}
V_56 >>= ( V_7 - V_46 ) ;
if ( V_45 ) {
if ( V_56 < V_49 )
V_49 = V_56 ;
if ( V_56 > V_50 )
V_50 = V_56 ;
}
V_52 = F_27 ( V_24 , V_45 , 1 , V_56 ) ;
if ( V_52 < 0 )
goto V_22;
V_51 += V_52 ;
V_45 ++ ;
V_47 += V_44 ;
V_58:
continue;
}
V_52 = V_51 ;
* V_38 = 1 + V_50 - V_49 ;
if ( V_45 == 0 )
V_45 = 1 ;
V_24 -> V_54 = V_45 ;
V_24 -> V_60 = V_45 - 1 ;
V_24 -> V_61 = V_45 - 1 ;
V_22:
return V_52 ;
V_57:
F_8 ( V_62 L_3 ) ;
V_52 = - V_63 ;
goto V_22;
}
int F_28 ( struct V_3 * V_3 , struct V_64 * V_65 )
{
int V_52 = 0 ;
if ( F_29 ( V_3 ) ) {
F_23 ( V_3 ) ;
goto V_22;
}
if ( F_30 ( V_3 ) == 0 ) {
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
F_12 ( V_3 ) ;
goto V_22;
}
V_52 = F_32 ( V_3 , V_65 , F_4 ) ;
V_22:
return V_52 ;
}
int F_32 ( struct V_3 * V_3 , struct V_64 * V_65 ,
void (* F_33)( struct V_1 * , int ) )
{
struct V_1 * V_1 ;
int V_52 = 0 , V_66 = V_67 ;
struct V_23 * V_24 = F_19 ( V_3 ) ;
if ( V_24 -> V_25 & V_68 ) {
struct V_69 V_69 ;
struct V_36 * V_37 = V_24 -> V_37 ;
struct V_39 * V_40 = V_37 -> V_41 ;
struct V_70 V_71 = {
. V_72 = F_34 ( V_3 ) ,
. V_73 = V_11 ,
} ;
F_35 ( & V_69 , V_37 ) ;
V_69 . V_74 = F_36 ( V_3 ) ;
V_69 . V_75 = V_11 ;
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
V_52 = V_40 -> V_76 -> V_77 ( V_78 ,
& V_69 , & V_71 ,
V_69 . V_74 , 1 ) ;
F_37 ( V_3 ) ;
if ( V_52 == V_11 ) {
F_38 ( V_79 ) ;
V_52 = 0 ;
} else {
F_7 ( V_3 ) ;
F_11 ( V_3 ) ;
F_39 ( L_4 ,
F_36 ( V_3 ) ) ;
}
F_12 ( V_3 ) ;
return V_52 ;
}
V_1 = F_1 ( V_80 , V_3 , F_33 ) ;
if ( V_1 == NULL ) {
F_7 ( V_3 ) ;
F_23 ( V_3 ) ;
V_52 = - V_81 ;
goto V_22;
}
if ( V_65 -> V_82 == V_83 )
V_66 |= V_84 ;
F_38 ( V_79 ) ;
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
F_40 ( V_66 , V_1 ) ;
V_22:
return V_52 ;
}
int F_41 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_52 = 0 ;
struct V_23 * V_24 = F_19 ( V_3 ) ;
F_42 ( ! F_43 ( V_3 ) ) ;
F_42 ( F_44 ( V_3 ) ) ;
if ( F_45 ( V_3 ) == 0 ) {
F_16 ( V_3 ) ;
F_23 ( V_3 ) ;
goto V_22;
}
if ( V_24 -> V_25 & V_68 ) {
struct V_36 * V_37 = V_24 -> V_37 ;
struct V_39 * V_40 = V_37 -> V_41 ;
V_52 = V_40 -> V_76 -> V_85 ( V_37 , V_3 ) ;
if ( ! V_52 )
F_38 ( V_86 ) ;
return V_52 ;
}
V_1 = F_1 ( V_87 , V_3 , F_14 ) ;
if ( V_1 == NULL ) {
F_23 ( V_3 ) ;
V_52 = - V_81 ;
goto V_22;
}
F_38 ( V_86 ) ;
F_40 ( V_88 , V_1 ) ;
V_22:
return V_52 ;
}
int F_46 ( struct V_3 * V_3 )
{
struct V_23 * V_24 = F_19 ( V_3 ) ;
if ( V_24 -> V_25 & V_68 ) {
struct V_39 * V_40 = V_24 -> V_37 -> V_41 ;
return V_40 -> V_76 -> F_7 ( V_3 ) ;
} else {
return F_47 ( V_3 ) ;
}
}
