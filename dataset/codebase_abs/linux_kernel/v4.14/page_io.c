static struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_3 , T_2 V_4 )
{
int V_5 , V_6 = F_2 ( V_3 ) ;
struct V_1 * V_1 ;
V_1 = F_3 ( V_2 , V_6 ) ;
if ( V_1 ) {
struct V_7 * V_8 ;
V_1 -> V_9 . V_10 = F_4 ( V_3 , & V_8 ) ;
F_5 ( V_1 , V_8 ) ;
V_1 -> V_9 . V_10 <<= V_11 - 9 ;
V_1 -> V_12 = V_4 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
F_6 ( V_1 , V_3 + V_5 , V_13 , 0 ) ;
F_7 ( V_1 -> V_9 . V_14 != V_13 * V_6 ) ;
}
return V_1 ;
}
void F_8 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_15 [ 0 ] . V_16 ;
if ( V_1 -> V_17 ) {
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
F_11 ( L_1 ,
F_12 ( F_13 ( V_1 ) ) , F_14 ( F_13 ( V_1 ) ) ,
( unsigned long long ) V_1 -> V_9 . V_10 ) ;
F_15 ( V_3 ) ;
}
F_16 ( V_3 ) ;
F_17 ( V_1 ) ;
}
static void F_18 ( struct V_3 * V_3 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
if ( F_19 ( ! F_20 ( V_3 ) ) )
return;
V_19 = F_21 ( V_3 ) ;
if ( ! ( V_19 -> V_22 & V_23 ) )
return;
V_21 = V_19 -> V_8 -> V_24 ;
if ( V_21 -> V_25 -> F_18 ) {
T_3 V_26 ;
unsigned long V_27 ;
V_26 . V_28 = F_22 ( V_3 ) ;
V_27 = F_23 ( V_26 ) ;
F_24 ( V_3 ) ;
V_21 -> V_25 -> F_18 ( V_19 -> V_8 ,
V_27 ) ;
}
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_15 [ 0 ] . V_16 ;
struct V_29 * V_30 = V_1 -> V_31 ;
if ( V_1 -> V_17 ) {
F_9 ( V_3 ) ;
F_26 ( V_3 ) ;
F_11 ( L_2 ,
F_12 ( F_13 ( V_1 ) ) , F_14 ( F_13 ( V_1 ) ) ,
( unsigned long long ) V_1 -> V_9 . V_10 ) ;
goto V_32;
}
F_27 ( V_3 ) ;
F_18 ( V_3 ) ;
V_32:
F_28 ( V_3 ) ;
F_29 ( V_1 -> V_31 , NULL ) ;
F_17 ( V_1 ) ;
F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
}
int F_32 ( struct V_18 * V_19 ,
struct V_33 * V_34 ,
T_4 * V_35 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 * V_39 = V_37 -> V_40 ;
unsigned V_41 ;
unsigned long V_42 ;
unsigned V_43 ;
T_4 V_44 ;
T_4 V_45 ;
T_4 V_46 = - 1 ;
T_4 V_47 = 0 ;
int V_48 = 0 ;
int V_49 ;
V_43 = V_39 -> V_50 ;
V_41 = V_13 >> V_43 ;
V_44 = 0 ;
V_42 = 0 ;
V_45 = F_33 ( V_39 ) >> V_43 ;
while ( ( V_44 + V_41 ) <= V_45 &&
V_42 < V_19 -> V_51 ) {
unsigned V_52 ;
T_4 V_53 ;
F_34 () ;
V_53 = F_35 ( V_39 , V_44 ) ;
if ( V_53 == 0 )
goto V_54;
if ( V_53 & ( V_41 - 1 ) ) {
V_44 ++ ;
goto V_55;
}
for ( V_52 = 1 ; V_52 < V_41 ;
V_52 ++ ) {
T_4 V_56 ;
V_56 = F_35 ( V_39 , V_44 + V_52 ) ;
if ( V_56 == 0 )
goto V_54;
if ( V_56 != V_53 + V_52 ) {
V_44 ++ ;
goto V_55;
}
}
V_53 >>= ( V_11 - V_43 ) ;
if ( V_42 ) {
if ( V_53 < V_46 )
V_46 = V_53 ;
if ( V_53 > V_47 )
V_47 = V_53 ;
}
V_49 = F_36 ( V_19 , V_42 , 1 , V_53 ) ;
if ( V_49 < 0 )
goto V_32;
V_48 += V_49 ;
V_42 ++ ;
V_44 += V_41 ;
V_55:
continue;
}
V_49 = V_48 ;
* V_35 = 1 + V_47 - V_46 ;
if ( V_42 == 0 )
V_42 = 1 ;
V_19 -> V_51 = V_42 ;
V_19 -> V_57 = V_42 - 1 ;
V_19 -> V_58 = V_42 - 1 ;
V_32:
return V_49 ;
V_54:
F_37 ( L_3 ) ;
V_49 = - V_59 ;
goto V_32;
}
int F_38 ( struct V_3 * V_3 , struct V_60 * V_61 )
{
int V_49 = 0 ;
if ( F_39 ( V_3 ) ) {
F_28 ( V_3 ) ;
goto V_32;
}
if ( F_40 ( V_3 ) == 0 ) {
F_41 ( V_3 ) ;
F_28 ( V_3 ) ;
F_16 ( V_3 ) ;
goto V_32;
}
V_49 = F_42 ( V_3 , V_61 , F_8 ) ;
V_32:
return V_49 ;
}
static T_4 F_43 ( struct V_3 * V_3 )
{
return ( T_4 ) F_44 ( V_3 ) << ( V_11 - 9 ) ;
}
static inline void F_45 ( struct V_3 * V_3 )
{
#ifdef F_46
if ( F_19 ( F_47 ( V_3 ) ) )
F_48 ( V_62 ) ;
#endif
F_49 ( V_63 , F_2 ( V_3 ) ) ;
}
int F_42 ( struct V_3 * V_3 , struct V_60 * V_61 ,
T_2 V_64 )
{
struct V_1 * V_1 ;
int V_49 ;
struct V_18 * V_19 = F_21 ( V_3 ) ;
F_50 ( ! F_20 ( V_3 ) , V_3 ) ;
if ( V_19 -> V_22 & V_65 ) {
struct V_66 V_66 ;
struct V_33 * V_34 = V_19 -> V_34 ;
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_67 V_68 = {
. V_16 = V_3 ,
. V_69 = V_13 ,
. V_70 = 0
} ;
struct V_71 V_72 ;
F_51 ( & V_72 , V_73 | V_74 , & V_68 , 1 , V_13 ) ;
F_52 ( & V_66 , V_34 ) ;
V_66 . V_75 = F_53 ( V_3 ) ;
F_41 ( V_3 ) ;
F_28 ( V_3 ) ;
V_49 = V_37 -> V_76 -> V_77 ( & V_66 , & V_72 ) ;
if ( V_49 == V_13 ) {
F_48 ( V_63 ) ;
V_49 = 0 ;
} else {
F_10 ( V_3 ) ;
F_15 ( V_3 ) ;
F_54 ( L_4 ,
F_53 ( V_3 ) ) ;
}
F_16 ( V_3 ) ;
return V_49 ;
}
V_49 = F_55 ( V_19 -> V_8 , F_43 ( V_3 ) , V_3 , V_61 ) ;
if ( ! V_49 ) {
F_45 ( V_3 ) ;
return 0 ;
}
V_49 = 0 ;
V_1 = F_1 ( V_78 , V_3 , V_64 ) ;
if ( V_1 == NULL ) {
F_10 ( V_3 ) ;
F_28 ( V_3 ) ;
V_49 = - V_79 ;
goto V_32;
}
V_1 -> V_80 = V_81 | F_56 ( V_61 ) ;
F_45 ( V_3 ) ;
F_41 ( V_3 ) ;
F_28 ( V_3 ) ;
F_57 ( V_1 ) ;
V_32:
return V_49 ;
}
int F_58 ( struct V_3 * V_3 , bool V_82 )
{
struct V_1 * V_1 ;
int V_49 = 0 ;
struct V_18 * V_19 = F_21 ( V_3 ) ;
T_5 V_83 ;
struct V_20 * V_21 ;
F_50 ( ! F_20 ( V_3 ) , V_3 ) ;
F_50 ( ! F_59 ( V_3 ) , V_3 ) ;
F_50 ( F_60 ( V_3 ) , V_3 ) ;
if ( F_61 ( V_3 ) == 0 ) {
F_27 ( V_3 ) ;
F_28 ( V_3 ) ;
goto V_32;
}
if ( V_19 -> V_22 & V_65 ) {
struct V_33 * V_34 = V_19 -> V_34 ;
struct V_36 * V_37 = V_34 -> V_38 ;
V_49 = V_37 -> V_76 -> V_84 ( V_34 , V_3 ) ;
if ( ! V_49 )
F_48 ( V_85 ) ;
return V_49 ;
}
V_49 = F_62 ( V_19 -> V_8 , F_43 ( V_3 ) , V_3 ) ;
if ( ! V_49 ) {
if ( F_63 ( V_3 ) ) {
F_18 ( V_3 ) ;
F_28 ( V_3 ) ;
}
F_48 ( V_85 ) ;
return 0 ;
}
V_49 = 0 ;
V_1 = F_1 ( V_86 , V_3 , F_25 ) ;
if ( V_1 == NULL ) {
F_28 ( V_3 ) ;
V_49 = - V_79 ;
goto V_32;
}
V_21 = V_1 -> V_87 ;
F_64 ( V_88 ) ;
V_1 -> V_31 = V_88 ;
F_65 ( V_1 , V_89 , 0 ) ;
F_48 ( V_85 ) ;
F_66 ( V_1 ) ;
V_83 = F_57 ( V_1 ) ;
while ( V_82 ) {
F_67 ( V_90 ) ;
if ( ! F_68 ( V_1 -> V_31 ) )
break;
if ( ! F_69 ( V_21 -> V_91 , V_83 ) )
break;
}
F_70 ( V_92 ) ;
F_17 ( V_1 ) ;
V_32:
return V_49 ;
}
int F_71 ( struct V_3 * V_3 )
{
struct V_18 * V_19 = F_21 ( V_3 ) ;
if ( V_19 -> V_22 & V_65 ) {
struct V_36 * V_37 = V_19 -> V_34 -> V_38 ;
F_50 ( ! F_20 ( V_3 ) , V_3 ) ;
return V_37 -> V_76 -> F_10 ( V_3 ) ;
} else {
return F_72 ( V_3 ) ;
}
}
