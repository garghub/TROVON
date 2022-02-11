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
if ( V_1 -> V_14 ) {
F_7 ( V_3 ) ;
F_23 ( V_3 ) ;
F_9 ( L_2 ,
F_10 ( V_1 -> V_7 -> V_15 ) ,
F_11 ( V_1 -> V_7 -> V_15 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
goto V_28;
}
F_24 ( V_3 ) ;
F_15 ( V_3 ) ;
V_28:
F_25 ( V_3 ) ;
F_14 ( V_1 ) ;
}
int F_26 ( struct V_16 * V_17 ,
struct V_29 * V_30 ,
T_4 * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 * V_35 = V_33 -> V_36 ;
unsigned V_37 ;
unsigned long V_38 ;
unsigned V_39 ;
T_4 V_40 ;
T_4 V_41 ;
T_4 V_42 = - 1 ;
T_4 V_43 = 0 ;
int V_44 = 0 ;
int V_45 ;
V_39 = V_35 -> V_46 ;
V_37 = V_10 >> V_39 ;
V_40 = 0 ;
V_38 = 0 ;
V_41 = F_27 ( V_35 ) >> V_39 ;
while ( ( V_40 + V_37 ) <= V_41 &&
V_38 < V_17 -> V_47 ) {
unsigned V_48 ;
T_4 V_49 ;
V_49 = F_28 ( V_35 , V_40 ) ;
if ( V_49 == 0 )
goto V_50;
if ( V_49 & ( V_37 - 1 ) ) {
V_40 ++ ;
goto V_51;
}
for ( V_48 = 1 ; V_48 < V_37 ;
V_48 ++ ) {
T_4 V_52 ;
V_52 = F_28 ( V_35 , V_40 + V_48 ) ;
if ( V_52 == 0 )
goto V_50;
if ( V_52 != V_49 + V_48 ) {
V_40 ++ ;
goto V_51;
}
}
V_49 >>= ( V_8 - V_39 ) ;
if ( V_38 ) {
if ( V_49 < V_42 )
V_42 = V_49 ;
if ( V_49 > V_43 )
V_43 = V_49 ;
}
V_45 = F_29 ( V_17 , V_38 , 1 , V_49 ) ;
if ( V_45 < 0 )
goto V_28;
V_44 += V_45 ;
V_38 ++ ;
V_40 += V_37 ;
V_51:
continue;
}
V_45 = V_44 ;
* V_31 = 1 + V_43 - V_42 ;
if ( V_38 == 0 )
V_38 = 1 ;
V_17 -> V_47 = V_38 ;
V_17 -> V_53 = V_38 - 1 ;
V_17 -> V_54 = V_38 - 1 ;
V_28:
return V_45 ;
V_50:
F_30 ( L_3 ) ;
V_45 = - V_55 ;
goto V_28;
}
int F_31 ( struct V_3 * V_3 , struct V_56 * V_57 )
{
int V_45 = 0 ;
if ( F_32 ( V_3 ) ) {
F_25 ( V_3 ) ;
goto V_28;
}
if ( F_33 ( V_3 ) == 0 ) {
F_34 ( V_3 ) ;
F_25 ( V_3 ) ;
F_13 ( V_3 ) ;
goto V_28;
}
V_45 = F_35 ( V_3 , V_57 , F_6 ) ;
V_28:
return V_45 ;
}
static T_4 F_36 ( struct V_3 * V_3 )
{
return ( T_4 ) F_37 ( V_3 ) << ( V_8 - 9 ) ;
}
int F_35 ( struct V_3 * V_3 , struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_1 * V_1 ;
int V_45 , V_59 = V_60 ;
struct V_16 * V_17 = F_18 ( V_3 ) ;
if ( V_17 -> V_20 & V_61 ) {
struct V_62 V_62 ;
struct V_29 * V_30 = V_17 -> V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_63 V_64 = {
. V_13 = V_3 ,
. V_65 = V_10 ,
. V_66 = 0
} ;
struct V_67 V_68 ;
F_38 ( & V_68 , V_69 | V_60 , & V_64 , 1 , V_10 ) ;
F_39 ( & V_62 , V_30 ) ;
V_62 . V_70 = F_40 ( V_3 ) ;
F_34 ( V_3 ) ;
F_25 ( V_3 ) ;
V_45 = V_33 -> V_71 -> V_72 ( & V_62 , & V_68 ) ;
if ( V_45 == V_10 ) {
F_41 ( V_73 ) ;
V_45 = 0 ;
} else {
F_8 ( V_3 ) ;
F_12 ( V_3 ) ;
F_42 ( L_4 ,
F_40 ( V_3 ) ) ;
}
F_13 ( V_3 ) ;
return V_45 ;
}
V_45 = F_43 ( V_17 -> V_22 , F_36 ( V_3 ) , V_3 , V_57 ) ;
if ( ! V_45 ) {
F_41 ( V_73 ) ;
return 0 ;
}
V_45 = 0 ;
V_1 = F_1 ( V_74 , V_3 , V_58 ) ;
if ( V_1 == NULL ) {
F_8 ( V_3 ) ;
F_25 ( V_3 ) ;
V_45 = - V_75 ;
goto V_28;
}
if ( V_57 -> V_76 == V_77 )
V_59 |= V_78 ;
F_41 ( V_73 ) ;
F_34 ( V_3 ) ;
F_25 ( V_3 ) ;
F_44 ( V_59 , V_1 ) ;
V_28:
return V_45 ;
}
int F_45 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_45 = 0 ;
struct V_16 * V_17 = F_18 ( V_3 ) ;
F_46 ( ! F_47 ( V_3 ) , V_3 ) ;
F_46 ( F_48 ( V_3 ) , V_3 ) ;
if ( F_49 ( V_3 ) == 0 ) {
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
goto V_28;
}
if ( V_17 -> V_20 & V_61 ) {
struct V_29 * V_30 = V_17 -> V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
V_45 = V_33 -> V_71 -> V_79 ( V_30 , V_3 ) ;
if ( ! V_45 )
F_41 ( V_80 ) ;
return V_45 ;
}
V_45 = F_50 ( V_17 -> V_22 , F_36 ( V_3 ) , V_3 ) ;
if ( ! V_45 ) {
if ( F_51 ( V_3 ) ) {
F_15 ( V_3 ) ;
F_25 ( V_3 ) ;
}
F_41 ( V_80 ) ;
return 0 ;
}
V_45 = 0 ;
V_1 = F_1 ( V_81 , V_3 , F_22 ) ;
if ( V_1 == NULL ) {
F_25 ( V_3 ) ;
V_45 = - V_75 ;
goto V_28;
}
F_41 ( V_80 ) ;
F_44 ( V_82 , V_1 ) ;
V_28:
return V_45 ;
}
int F_52 ( struct V_3 * V_3 )
{
struct V_16 * V_17 = F_18 ( V_3 ) ;
if ( V_17 -> V_20 & V_61 ) {
struct V_32 * V_33 = V_17 -> V_30 -> V_34 ;
return V_33 -> V_71 -> F_8 ( V_3 ) ;
} else {
return F_53 ( V_3 ) ;
}
}
