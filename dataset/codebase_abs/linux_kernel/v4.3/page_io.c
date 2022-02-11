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
F_9 ( V_15 L_1 ,
F_10 ( V_1 -> V_7 -> V_16 ) ,
F_11 ( V_1 -> V_7 -> V_16 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
F_12 ( V_3 ) ;
}
F_13 ( V_3 ) ;
F_14 ( V_1 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_12 [ 0 ] . V_13 ;
if ( V_1 -> V_14 ) {
F_7 ( V_3 ) ;
F_16 ( V_3 ) ;
F_9 ( V_15 L_2 ,
F_10 ( V_1 -> V_7 -> V_16 ) ,
F_11 ( V_1 -> V_7 -> V_16 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
goto V_17;
}
F_17 ( V_3 ) ;
if ( F_18 ( F_19 ( V_3 ) ) ) {
struct V_18 * V_19 ;
V_19 = F_20 ( V_3 ) ;
if ( V_19 -> V_20 & V_21 ) {
struct V_22 * V_23 = V_19 -> V_24 -> V_25 ;
if ( V_23 -> V_26 -> V_27 ) {
T_3 V_28 ;
unsigned long V_29 ;
V_28 . V_30 = F_21 ( V_3 ) ;
V_29 = F_22 ( V_28 ) ;
F_23 ( V_3 ) ;
V_23 -> V_26 -> V_27 ( V_19 -> V_24 ,
V_29 ) ;
}
}
}
V_17:
F_24 ( V_3 ) ;
F_14 ( V_1 ) ;
}
int F_25 ( struct V_18 * V_19 ,
struct V_31 * V_32 ,
T_4 * V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_37 * V_37 = V_35 -> V_38 ;
unsigned V_39 ;
unsigned long V_40 ;
unsigned V_41 ;
T_4 V_42 ;
T_4 V_43 ;
T_4 V_44 = - 1 ;
T_4 V_45 = 0 ;
int V_46 = 0 ;
int V_47 ;
V_41 = V_37 -> V_48 ;
V_39 = V_10 >> V_41 ;
V_42 = 0 ;
V_40 = 0 ;
V_43 = F_26 ( V_37 ) >> V_41 ;
while ( ( V_42 + V_39 ) <= V_43 &&
V_40 < V_19 -> V_49 ) {
unsigned V_50 ;
T_4 V_51 ;
V_51 = F_27 ( V_37 , V_42 ) ;
if ( V_51 == 0 )
goto V_52;
if ( V_51 & ( V_39 - 1 ) ) {
V_42 ++ ;
goto V_53;
}
for ( V_50 = 1 ; V_50 < V_39 ;
V_50 ++ ) {
T_4 V_54 ;
V_54 = F_27 ( V_37 , V_42 + V_50 ) ;
if ( V_54 == 0 )
goto V_52;
if ( V_54 != V_51 + V_50 ) {
V_42 ++ ;
goto V_53;
}
}
V_51 >>= ( V_8 - V_41 ) ;
if ( V_40 ) {
if ( V_51 < V_44 )
V_44 = V_51 ;
if ( V_51 > V_45 )
V_45 = V_51 ;
}
V_47 = F_28 ( V_19 , V_40 , 1 , V_51 ) ;
if ( V_47 < 0 )
goto V_17;
V_46 += V_47 ;
V_40 ++ ;
V_42 += V_39 ;
V_53:
continue;
}
V_47 = V_46 ;
* V_33 = 1 + V_45 - V_44 ;
if ( V_40 == 0 )
V_40 = 1 ;
V_19 -> V_49 = V_40 ;
V_19 -> V_55 = V_40 - 1 ;
V_19 -> V_56 = V_40 - 1 ;
V_17:
return V_47 ;
V_52:
F_9 ( V_57 L_3 ) ;
V_47 = - V_58 ;
goto V_17;
}
int F_29 ( struct V_3 * V_3 , struct V_59 * V_60 )
{
int V_47 = 0 ;
if ( F_30 ( V_3 ) ) {
F_24 ( V_3 ) ;
goto V_17;
}
if ( F_31 ( V_3 ) == 0 ) {
F_32 ( V_3 ) ;
F_24 ( V_3 ) ;
F_13 ( V_3 ) ;
goto V_17;
}
V_47 = F_33 ( V_3 , V_60 , F_6 ) ;
V_17:
return V_47 ;
}
static T_4 F_34 ( struct V_3 * V_3 )
{
return ( T_4 ) F_35 ( V_3 ) << ( V_61 - 9 ) ;
}
int F_33 ( struct V_3 * V_3 , struct V_59 * V_60 ,
T_2 V_62 )
{
struct V_1 * V_1 ;
int V_47 , V_63 = V_64 ;
struct V_18 * V_19 = F_20 ( V_3 ) ;
if ( V_19 -> V_20 & V_65 ) {
struct V_66 V_66 ;
struct V_31 * V_32 = V_19 -> V_32 ;
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_67 V_68 = {
. V_13 = V_3 ,
. V_69 = V_10 ,
. V_70 = 0
} ;
struct V_71 V_72 ;
F_36 ( & V_72 , V_73 | V_64 , & V_68 , 1 , V_10 ) ;
F_37 ( & V_66 , V_32 ) ;
V_66 . V_74 = F_38 ( V_3 ) ;
F_32 ( V_3 ) ;
F_24 ( V_3 ) ;
V_47 = V_35 -> V_75 -> V_76 ( & V_66 , & V_72 , V_66 . V_74 ) ;
if ( V_47 == V_10 ) {
F_39 ( V_77 ) ;
V_47 = 0 ;
} else {
F_8 ( V_3 ) ;
F_12 ( V_3 ) ;
F_40 ( L_4 ,
F_38 ( V_3 ) ) ;
}
F_13 ( V_3 ) ;
return V_47 ;
}
V_47 = F_41 ( V_19 -> V_24 , F_34 ( V_3 ) , V_3 , V_60 ) ;
if ( ! V_47 ) {
F_39 ( V_77 ) ;
return 0 ;
}
V_47 = 0 ;
V_1 = F_1 ( V_78 , V_3 , V_62 ) ;
if ( V_1 == NULL ) {
F_8 ( V_3 ) ;
F_24 ( V_3 ) ;
V_47 = - V_79 ;
goto V_17;
}
if ( V_60 -> V_80 == V_81 )
V_63 |= V_82 ;
F_39 ( V_77 ) ;
F_32 ( V_3 ) ;
F_24 ( V_3 ) ;
F_42 ( V_63 , V_1 ) ;
V_17:
return V_47 ;
}
int F_43 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_47 = 0 ;
struct V_18 * V_19 = F_20 ( V_3 ) ;
F_44 ( ! F_45 ( V_3 ) , V_3 ) ;
F_44 ( F_46 ( V_3 ) , V_3 ) ;
if ( F_47 ( V_3 ) == 0 ) {
F_17 ( V_3 ) ;
F_24 ( V_3 ) ;
goto V_17;
}
if ( V_19 -> V_20 & V_65 ) {
struct V_31 * V_32 = V_19 -> V_32 ;
struct V_34 * V_35 = V_32 -> V_36 ;
V_47 = V_35 -> V_75 -> V_83 ( V_32 , V_3 ) ;
if ( ! V_47 )
F_39 ( V_84 ) ;
return V_47 ;
}
V_47 = F_48 ( V_19 -> V_24 , F_34 ( V_3 ) , V_3 ) ;
if ( ! V_47 ) {
F_39 ( V_84 ) ;
return 0 ;
}
V_47 = 0 ;
V_1 = F_1 ( V_85 , V_3 , F_15 ) ;
if ( V_1 == NULL ) {
F_24 ( V_3 ) ;
V_47 = - V_79 ;
goto V_17;
}
F_39 ( V_84 ) ;
F_42 ( V_86 , V_1 ) ;
V_17:
return V_47 ;
}
int F_49 ( struct V_3 * V_3 )
{
struct V_18 * V_19 = F_20 ( V_3 ) ;
if ( V_19 -> V_20 & V_65 ) {
struct V_34 * V_35 = V_19 -> V_32 -> V_36 ;
return V_35 -> V_75 -> F_8 ( V_3 ) ;
} else {
return F_50 ( V_3 ) ;
}
}
