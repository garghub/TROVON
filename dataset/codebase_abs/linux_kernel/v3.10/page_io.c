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
} else {
F_16 ( V_3 ) ;
}
F_17 ( V_3 ) ;
F_13 ( V_1 ) ;
}
int F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
T_3 * V_26 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_30 * V_30 = V_28 -> V_31 ;
unsigned V_32 ;
unsigned long V_33 ;
unsigned V_34 ;
T_3 V_35 ;
T_3 V_36 ;
T_3 V_37 = - 1 ;
T_3 V_38 = 0 ;
int V_39 = 0 ;
int V_40 ;
V_34 = V_30 -> V_41 ;
V_32 = V_11 >> V_34 ;
V_35 = 0 ;
V_33 = 0 ;
V_36 = F_19 ( V_30 ) >> V_34 ;
while ( ( V_35 + V_32 ) <= V_36 &&
V_33 < V_23 -> V_42 ) {
unsigned V_43 ;
T_3 V_44 ;
V_44 = F_20 ( V_30 , V_35 ) ;
if ( V_44 == 0 )
goto V_45;
if ( V_44 & ( V_32 - 1 ) ) {
V_35 ++ ;
goto V_46;
}
for ( V_43 = 1 ; V_43 < V_32 ;
V_43 ++ ) {
T_3 V_47 ;
V_47 = F_20 ( V_30 , V_35 + V_43 ) ;
if ( V_47 == 0 )
goto V_45;
if ( V_47 != V_44 + V_43 ) {
V_35 ++ ;
goto V_46;
}
}
V_44 >>= ( V_7 - V_34 ) ;
if ( V_33 ) {
if ( V_44 < V_37 )
V_37 = V_44 ;
if ( V_44 > V_38 )
V_38 = V_44 ;
}
V_40 = F_21 ( V_23 , V_33 , 1 , V_44 ) ;
if ( V_40 < 0 )
goto V_48;
V_39 += V_40 ;
V_33 ++ ;
V_35 += V_32 ;
V_46:
continue;
}
V_40 = V_39 ;
* V_26 = 1 + V_38 - V_37 ;
if ( V_33 == 0 )
V_33 = 1 ;
V_23 -> V_42 = V_33 ;
V_23 -> V_49 = V_33 - 1 ;
V_23 -> V_50 = V_33 - 1 ;
V_48:
return V_40 ;
V_45:
F_8 ( V_51 L_3 ) ;
V_40 = - V_52 ;
goto V_48;
}
int F_22 ( struct V_3 * V_3 , struct V_53 * V_54 )
{
int V_40 = 0 ;
if ( F_23 ( V_3 ) ) {
F_17 ( V_3 ) ;
goto V_48;
}
if ( F_24 ( V_3 ) == 0 ) {
F_25 ( V_3 ) ;
F_17 ( V_3 ) ;
F_12 ( V_3 ) ;
goto V_48;
}
V_40 = F_26 ( V_3 , V_54 , F_4 ) ;
V_48:
return V_40 ;
}
int F_26 ( struct V_3 * V_3 , struct V_53 * V_54 ,
void (* F_27)( struct V_1 * , int ) )
{
struct V_1 * V_1 ;
int V_40 = 0 , V_55 = V_56 ;
struct V_22 * V_23 = F_28 ( V_3 ) ;
if ( V_23 -> V_57 & V_58 ) {
struct V_59 V_59 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_60 V_61 = {
. V_62 = F_29 ( V_3 ) ,
. V_63 = V_11 ,
} ;
F_30 ( & V_59 , V_25 ) ;
V_59 . V_64 = F_31 ( V_3 ) ;
V_59 . V_65 = V_11 ;
V_59 . V_66 = V_11 ;
F_25 ( V_3 ) ;
F_17 ( V_3 ) ;
V_40 = V_28 -> V_67 -> V_68 ( V_69 ,
& V_59 , & V_61 ,
V_59 . V_64 , 1 ) ;
F_32 ( V_3 ) ;
if ( V_40 == V_11 ) {
F_33 ( V_70 ) ;
V_40 = 0 ;
} else {
F_7 ( V_3 ) ;
F_11 ( V_3 ) ;
F_34 ( L_4 ,
F_31 ( V_3 ) ) ;
}
F_12 ( V_3 ) ;
return V_40 ;
}
V_1 = F_1 ( V_71 , V_3 , F_27 ) ;
if ( V_1 == NULL ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
V_40 = - V_72 ;
goto V_48;
}
if ( V_54 -> V_73 == V_74 )
V_55 |= V_75 ;
F_33 ( V_70 ) ;
F_25 ( V_3 ) ;
F_17 ( V_3 ) ;
F_35 ( V_55 , V_1 ) ;
V_48:
return V_40 ;
}
int F_36 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_40 = 0 ;
struct V_22 * V_23 = F_28 ( V_3 ) ;
F_37 ( ! F_38 ( V_3 ) ) ;
F_37 ( F_39 ( V_3 ) ) ;
if ( F_40 ( V_3 ) == 0 ) {
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
goto V_48;
}
if ( V_23 -> V_57 & V_58 ) {
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_27 * V_28 = V_25 -> V_29 ;
V_40 = V_28 -> V_67 -> V_76 ( V_25 , V_3 ) ;
if ( ! V_40 )
F_33 ( V_77 ) ;
return V_40 ;
}
V_1 = F_1 ( V_78 , V_3 , F_14 ) ;
if ( V_1 == NULL ) {
F_17 ( V_3 ) ;
V_40 = - V_72 ;
goto V_48;
}
F_33 ( V_77 ) ;
F_35 ( V_79 , V_1 ) ;
V_48:
return V_40 ;
}
int F_41 ( struct V_3 * V_3 )
{
struct V_22 * V_23 = F_28 ( V_3 ) ;
if ( V_23 -> V_57 & V_58 ) {
struct V_27 * V_28 = V_23 -> V_25 -> V_29 ;
return V_28 -> V_67 -> F_7 ( V_3 ) ;
} else {
return F_42 ( V_3 ) ;
}
}
