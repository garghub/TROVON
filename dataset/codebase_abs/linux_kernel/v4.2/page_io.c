static struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_3 , T_2 V_4 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , 1 ) ;
if ( V_1 ) {
V_1 -> V_5 . V_6 = F_3 ( V_3 , & V_1 -> V_7 ) ;
V_1 -> V_5 . V_6 <<= V_8 - 9 ;
V_1 -> V_9 [ 0 ] . V_10 = V_3 ;
V_1 -> V_9 [ 0 ] . V_11 = V_12 ;
V_1 -> V_9 [ 0 ] . V_13 = 0 ;
V_1 -> V_14 = 1 ;
V_1 -> V_5 . V_15 = V_12 ;
V_1 -> V_16 = V_4 ;
}
return V_1 ;
}
void F_4 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_9 [ 0 ] . V_10 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_21 L_1 ,
F_9 ( V_1 -> V_7 -> V_22 ) ,
F_10 ( V_1 -> V_7 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
F_11 ( V_3 ) ;
}
F_12 ( V_3 ) ;
F_13 ( V_1 ) ;
}
static void F_14 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_9 [ 0 ] . V_10 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_15 ( V_3 ) ;
F_8 ( V_21 L_2 ,
F_9 ( V_1 -> V_7 -> V_22 ) ,
F_10 ( V_1 -> V_7 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 . V_6 ) ;
goto V_23;
}
F_16 ( V_3 ) ;
if ( F_17 ( F_18 ( V_3 ) ) ) {
struct V_24 * V_25 ;
V_25 = F_19 ( V_3 ) ;
if ( V_25 -> V_26 & V_27 ) {
struct V_28 * V_29 = V_25 -> V_30 -> V_31 ;
if ( V_29 -> V_32 -> V_33 ) {
T_3 V_34 ;
unsigned long V_35 ;
V_34 . V_36 = F_20 ( V_3 ) ;
V_35 = F_21 ( V_34 ) ;
F_22 ( V_3 ) ;
V_29 -> V_32 -> V_33 ( V_25 -> V_30 ,
V_35 ) ;
}
}
}
V_23:
F_23 ( V_3 ) ;
F_13 ( V_1 ) ;
}
int F_24 ( struct V_24 * V_25 ,
struct V_37 * V_38 ,
T_4 * V_39 )
{
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_43 * V_43 = V_41 -> V_44 ;
unsigned V_45 ;
unsigned long V_46 ;
unsigned V_47 ;
T_4 V_48 ;
T_4 V_49 ;
T_4 V_50 = - 1 ;
T_4 V_51 = 0 ;
int V_52 = 0 ;
int V_53 ;
V_47 = V_43 -> V_54 ;
V_45 = V_12 >> V_47 ;
V_48 = 0 ;
V_46 = 0 ;
V_49 = F_25 ( V_43 ) >> V_47 ;
while ( ( V_48 + V_45 ) <= V_49 &&
V_46 < V_25 -> V_55 ) {
unsigned V_56 ;
T_4 V_57 ;
V_57 = F_26 ( V_43 , V_48 ) ;
if ( V_57 == 0 )
goto V_58;
if ( V_57 & ( V_45 - 1 ) ) {
V_48 ++ ;
goto V_59;
}
for ( V_56 = 1 ; V_56 < V_45 ;
V_56 ++ ) {
T_4 V_60 ;
V_60 = F_26 ( V_43 , V_48 + V_56 ) ;
if ( V_60 == 0 )
goto V_58;
if ( V_60 != V_57 + V_56 ) {
V_48 ++ ;
goto V_59;
}
}
V_57 >>= ( V_8 - V_47 ) ;
if ( V_46 ) {
if ( V_57 < V_50 )
V_50 = V_57 ;
if ( V_57 > V_51 )
V_51 = V_57 ;
}
V_53 = F_27 ( V_25 , V_46 , 1 , V_57 ) ;
if ( V_53 < 0 )
goto V_23;
V_52 += V_53 ;
V_46 ++ ;
V_48 += V_45 ;
V_59:
continue;
}
V_53 = V_52 ;
* V_39 = 1 + V_51 - V_50 ;
if ( V_46 == 0 )
V_46 = 1 ;
V_25 -> V_55 = V_46 ;
V_25 -> V_61 = V_46 - 1 ;
V_25 -> V_62 = V_46 - 1 ;
V_23:
return V_53 ;
V_58:
F_8 ( V_63 L_3 ) ;
V_53 = - V_64 ;
goto V_23;
}
int F_28 ( struct V_3 * V_3 , struct V_65 * V_66 )
{
int V_53 = 0 ;
if ( F_29 ( V_3 ) ) {
F_23 ( V_3 ) ;
goto V_23;
}
if ( F_30 ( V_3 ) == 0 ) {
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
F_12 ( V_3 ) ;
goto V_23;
}
V_53 = F_32 ( V_3 , V_66 , F_4 ) ;
V_23:
return V_53 ;
}
static T_4 F_33 ( struct V_3 * V_3 )
{
return ( T_4 ) F_34 ( V_3 ) << ( V_67 - 9 ) ;
}
int F_32 ( struct V_3 * V_3 , struct V_65 * V_66 ,
void (* F_35)( struct V_1 * , int ) )
{
struct V_1 * V_1 ;
int V_53 , V_68 = V_69 ;
struct V_24 * V_25 = F_19 ( V_3 ) ;
if ( V_25 -> V_26 & V_70 ) {
struct V_71 V_71 ;
struct V_37 * V_38 = V_25 -> V_38 ;
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_72 V_73 = {
. V_10 = V_3 ,
. V_11 = V_12 ,
. V_13 = 0
} ;
struct V_74 V_75 ;
F_36 ( & V_75 , V_76 | V_69 , & V_73 , 1 , V_12 ) ;
F_37 ( & V_71 , V_38 ) ;
V_71 . V_77 = F_38 ( V_3 ) ;
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
V_53 = V_41 -> V_78 -> V_79 ( & V_71 , & V_75 , V_71 . V_77 ) ;
if ( V_53 == V_12 ) {
F_39 ( V_80 ) ;
V_53 = 0 ;
} else {
F_7 ( V_3 ) ;
F_11 ( V_3 ) ;
F_40 ( L_4 ,
F_38 ( V_3 ) ) ;
}
F_12 ( V_3 ) ;
return V_53 ;
}
V_53 = F_41 ( V_25 -> V_30 , F_33 ( V_3 ) , V_3 , V_66 ) ;
if ( ! V_53 ) {
F_39 ( V_80 ) ;
return 0 ;
}
V_53 = 0 ;
V_1 = F_1 ( V_81 , V_3 , F_35 ) ;
if ( V_1 == NULL ) {
F_7 ( V_3 ) ;
F_23 ( V_3 ) ;
V_53 = - V_82 ;
goto V_23;
}
if ( V_66 -> V_83 == V_84 )
V_68 |= V_85 ;
F_39 ( V_80 ) ;
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
F_42 ( V_68 , V_1 ) ;
V_23:
return V_53 ;
}
int F_43 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_53 = 0 ;
struct V_24 * V_25 = F_19 ( V_3 ) ;
F_44 ( ! F_45 ( V_3 ) , V_3 ) ;
F_44 ( F_46 ( V_3 ) , V_3 ) ;
if ( F_47 ( V_3 ) == 0 ) {
F_16 ( V_3 ) ;
F_23 ( V_3 ) ;
goto V_23;
}
if ( V_25 -> V_26 & V_70 ) {
struct V_37 * V_38 = V_25 -> V_38 ;
struct V_40 * V_41 = V_38 -> V_42 ;
V_53 = V_41 -> V_78 -> V_86 ( V_38 , V_3 ) ;
if ( ! V_53 )
F_39 ( V_87 ) ;
return V_53 ;
}
V_53 = F_48 ( V_25 -> V_30 , F_33 ( V_3 ) , V_3 ) ;
if ( ! V_53 ) {
F_39 ( V_87 ) ;
return 0 ;
}
V_53 = 0 ;
V_1 = F_1 ( V_88 , V_3 , F_14 ) ;
if ( V_1 == NULL ) {
F_23 ( V_3 ) ;
V_53 = - V_82 ;
goto V_23;
}
F_39 ( V_87 ) ;
F_42 ( V_89 , V_1 ) ;
V_23:
return V_53 ;
}
int F_49 ( struct V_3 * V_3 )
{
struct V_24 * V_25 = F_19 ( V_3 ) ;
if ( V_25 -> V_26 & V_70 ) {
struct V_40 * V_41 = V_25 -> V_38 -> V_42 ;
return V_41 -> V_78 -> F_7 ( V_3 ) ;
} else {
return F_50 ( V_3 ) ;
}
}
