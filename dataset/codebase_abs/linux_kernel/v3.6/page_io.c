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
V_1 -> V_14 = 0 ;
V_1 -> V_15 = V_11 ;
V_1 -> V_16 = V_4 ;
}
return V_1 ;
}
static void F_4 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_21 L_1 ,
F_9 ( V_1 -> V_6 -> V_22 ) ,
F_10 ( V_1 -> V_6 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
F_11 ( V_3 ) ;
}
F_12 ( V_3 ) ;
F_13 ( V_1 ) ;
}
void F_14 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_15 ( V_3 ) ;
F_8 ( V_21 L_2 ,
F_9 ( V_1 -> V_6 -> V_22 ) ,
F_10 ( V_1 -> V_6 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
} else {
F_16 ( V_3 ) ;
}
F_17 ( V_3 ) ;
F_13 ( V_1 ) ;
}
int F_18 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
T_3 * V_27 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_31 * V_31 = V_29 -> V_32 ;
unsigned V_33 ;
unsigned long V_34 ;
unsigned V_35 ;
T_3 V_36 ;
T_3 V_37 ;
T_3 V_38 = - 1 ;
T_3 V_39 = 0 ;
int V_40 = 0 ;
int V_41 ;
V_35 = V_31 -> V_42 ;
V_33 = V_11 >> V_35 ;
V_36 = 0 ;
V_34 = 0 ;
V_37 = F_19 ( V_31 ) >> V_35 ;
while ( ( V_36 + V_33 ) <= V_37 &&
V_34 < V_24 -> V_43 ) {
unsigned V_44 ;
T_3 V_45 ;
V_45 = F_20 ( V_31 , V_36 ) ;
if ( V_45 == 0 )
goto V_46;
if ( V_45 & ( V_33 - 1 ) ) {
V_36 ++ ;
goto V_47;
}
for ( V_44 = 1 ; V_44 < V_33 ;
V_44 ++ ) {
T_3 V_48 ;
V_48 = F_20 ( V_31 , V_36 + V_44 ) ;
if ( V_48 == 0 )
goto V_46;
if ( V_48 != V_45 + V_44 ) {
V_36 ++ ;
goto V_47;
}
}
V_45 >>= ( V_7 - V_35 ) ;
if ( V_34 ) {
if ( V_45 < V_38 )
V_38 = V_45 ;
if ( V_45 > V_39 )
V_39 = V_45 ;
}
V_41 = F_21 ( V_24 , V_34 , 1 , V_45 ) ;
if ( V_41 < 0 )
goto V_49;
V_40 += V_41 ;
V_34 ++ ;
V_36 += V_33 ;
V_47:
continue;
}
V_41 = V_40 ;
* V_27 = 1 + V_39 - V_38 ;
if ( V_34 == 0 )
V_34 = 1 ;
V_24 -> V_43 = V_34 ;
V_24 -> V_50 = V_34 - 1 ;
V_24 -> V_51 = V_34 - 1 ;
V_49:
return V_41 ;
V_46:
F_8 ( V_52 L_3 ) ;
V_41 = - V_53 ;
goto V_49;
}
int F_22 ( struct V_3 * V_3 , struct V_54 * V_55 )
{
struct V_1 * V_1 ;
int V_41 = 0 , V_56 = V_57 ;
struct V_23 * V_24 = F_23 ( V_3 ) ;
if ( F_24 ( V_3 ) ) {
F_17 ( V_3 ) ;
goto V_49;
}
if ( F_25 ( V_3 ) == 0 ) {
F_26 ( V_3 ) ;
F_17 ( V_3 ) ;
F_12 ( V_3 ) ;
goto V_49;
}
if ( V_24 -> V_58 & V_59 ) {
struct V_60 V_60 ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_61 V_62 = {
. V_63 = F_27 ( V_3 ) ,
. V_64 = V_11 ,
} ;
F_28 ( & V_60 , V_26 ) ;
V_60 . V_65 = F_29 ( V_3 ) ;
V_60 . V_66 = V_11 ;
V_60 . V_67 = V_11 ;
F_17 ( V_3 ) ;
V_41 = V_29 -> V_68 -> V_69 ( V_70 ,
& V_60 , & V_62 ,
V_60 . V_65 , 1 ) ;
F_30 ( V_3 ) ;
if ( V_41 == V_11 ) {
F_31 ( V_71 ) ;
V_41 = 0 ;
}
return V_41 ;
}
V_1 = F_1 ( V_72 , V_3 , F_4 ) ;
if ( V_1 == NULL ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
V_41 = - V_73 ;
goto V_49;
}
if ( V_55 -> V_74 == V_75 )
V_56 |= V_76 ;
F_31 ( V_71 ) ;
F_26 ( V_3 ) ;
F_17 ( V_3 ) ;
F_32 ( V_56 , V_1 ) ;
V_49:
return V_41 ;
}
int F_33 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_41 = 0 ;
struct V_23 * V_24 = F_23 ( V_3 ) ;
F_34 ( ! F_35 ( V_3 ) ) ;
F_34 ( F_36 ( V_3 ) ) ;
if ( F_37 ( V_3 ) == 0 ) {
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
goto V_49;
}
if ( V_24 -> V_58 & V_59 ) {
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_28 * V_29 = V_26 -> V_30 ;
V_41 = V_29 -> V_68 -> V_77 ( V_26 , V_3 ) ;
if ( ! V_41 )
F_31 ( V_78 ) ;
return V_41 ;
}
V_1 = F_1 ( V_79 , V_3 , F_14 ) ;
if ( V_1 == NULL ) {
F_17 ( V_3 ) ;
V_41 = - V_73 ;
goto V_49;
}
F_31 ( V_78 ) ;
F_32 ( V_80 , V_1 ) ;
V_49:
return V_41 ;
}
int F_38 ( struct V_3 * V_3 )
{
struct V_23 * V_24 = F_23 ( V_3 ) ;
if ( V_24 -> V_58 & V_59 ) {
struct V_28 * V_29 = V_24 -> V_26 -> V_30 ;
return V_29 -> V_68 -> F_7 ( V_3 ) ;
} else {
return F_39 ( V_3 ) ;
}
}
