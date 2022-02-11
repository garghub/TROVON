static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 = F_4 ( V_8 -> V_9 + V_10 ) ;
if ( V_3 >= 0 ) {
V_4 &= ~ V_11 ;
V_4 |= F_5 ( V_3 + V_8 -> V_12 ) ;
} else
V_4 |= V_13 ;
F_6 ( V_8 -> V_9 + V_10 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_14 , unsigned int V_15 )
{
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
if ( V_14 == V_16 )
return;
if ( V_15 & V_17 )
F_8 ( V_14 & 0xFF , V_8 -> V_9 + V_18 ) ;
else
F_8 ( V_14 & 0xFF , V_8 -> V_9 + V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
return F_4 ( V_8 -> V_9 + V_20 ) & V_21 ;
}
static void F_10 ( struct V_1 * V_2 , int V_22 )
{
T_1 V_4 ;
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
V_4 = F_4 ( V_8 -> V_9 + V_10 ) ;
V_4 |= V_23 ;
F_6 ( V_8 -> V_9 + V_10 , V_4 ) ;
F_11 () ;
}
static int F_12 ( struct V_1 * V_2 ,
const T_2 * V_24 , T_2 * V_25 )
{
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
T_1 V_26 ;
T_3 * V_27 = ( T_3 * ) & V_26 ;
F_11 () ;
V_26 = F_4 ( V_8 -> V_9 + V_28 ) ;
V_25 [ 0 ] = V_27 [ 1 ] ;
V_25 [ 1 ] = V_27 [ 2 ] ;
V_25 [ 2 ] = V_27 [ 3 ] ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , T_3 * V_29 , int V_30 )
{
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
T_1 * V_27 = ( T_1 * ) V_29 ;
for(; V_30 > 0 ; V_30 -= 4 )
* V_27 ++ = F_4 ( V_8 -> V_9 + V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 , const T_3 * V_29 , int V_30 )
{
struct V_5 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_3 ) ;
T_1 * V_27 = ( T_1 * ) V_29 ;
for(; V_30 > 0 ; V_30 -= 4 )
F_6 ( V_8 -> V_9 + V_31 , * V_27 ++ ) ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_32 * V_33 )
{
struct V_32 * V_34 ;
struct V_5 * V_3 = & V_8 -> V_3 ;
struct V_1 * V_2 = F_16 ( V_3 ) ;
int V_35 ;
V_3 -> V_36 = V_8 -> V_9 + V_31 ;
V_3 -> V_37 = V_8 -> V_9 + V_31 ;
V_3 -> V_38 = F_7 ;
V_3 -> V_39 = F_9 ;
V_3 -> V_40 = F_1 ;
V_3 -> V_41 = 50 ;
V_3 -> V_42 = & V_8 -> V_43 ;
V_3 -> V_44 = F_13 ;
V_3 -> V_45 = F_14 ;
V_3 -> V_26 . V_46 = V_47 ;
V_3 -> V_26 . V_48 = F_10 ;
V_3 -> V_26 . V_49 = F_12 ;
V_3 -> V_26 . V_22 = V_50 ;
V_3 -> V_26 . V_51 = 256 ;
V_3 -> V_26 . V_52 = 3 ;
V_3 -> V_26 . V_53 = 1 ;
F_17 ( V_3 , V_8 ) ;
V_2 -> V_54 . V_55 = & V_8 -> V_56 -> V_54 ;
V_34 = F_18 ( V_33 , NULL ) ;
if ( ! V_34 )
return - V_57 ;
F_19 ( V_3 , V_34 ) ;
V_2 -> V_58 = F_20 ( V_59 , L_1 , F_21 ( & V_8 -> V_56 -> V_54 ) ,
V_34 -> V_58 ) ;
if ( ! V_2 -> V_58 ) {
V_35 = - V_60 ;
goto V_61;
}
V_35 = F_22 ( V_2 , 1 ) ;
if ( V_35 )
goto V_61;
V_35 = F_23 ( V_2 , NULL , 0 ) ;
V_61:
F_24 ( V_34 ) ;
if ( V_35 )
F_25 ( V_2 -> V_58 ) ;
return V_35 ;
}
static int F_26 ( struct V_62 * V_56 )
{
struct V_7 * V_8 ;
const T_4 * V_63 ;
T_5 V_4 ;
T_5 V_64 ;
int V_61 , V_30 ;
V_63 = F_27 ( V_56 -> V_54 . V_65 , L_2 , & V_30 ) ;
if ( V_63 == NULL || V_30 != 12 ) {
F_28 ( & V_56 -> V_54 , L_3 , V_30 ) ;
return - V_66 ;
}
V_64 = F_29 ( V_63 [ 0 ] ) ;
if ( V_64 >= V_67 ) {
F_28 ( & V_56 -> V_54 , L_4 , V_64 ) ;
return - V_68 ;
}
V_8 = & V_69 [ V_64 ] ;
V_8 -> V_12 = V_64 ;
F_30 ( & V_8 -> V_43 . V_70 ) ;
F_31 ( & V_8 -> V_43 . V_71 ) ;
V_8 -> V_56 = V_56 ;
F_32 ( & V_56 -> V_54 , V_8 ) ;
V_8 -> V_9 = F_33 ( V_56 -> V_54 . V_65 , 0 ) ;
if ( ! V_8 -> V_9 ) {
F_28 ( & V_56 -> V_54 , L_5 ) ;
return - V_72 ;
}
V_4 = F_5 ( V_8 -> V_12 ) ;
V_63 = F_27 ( V_56 -> V_54 . V_65 , L_6 , NULL ) ;
if ( V_63 )
V_4 |= F_34 ( V_63 ) ;
F_6 ( V_8 -> V_9 + V_10 , V_4 ) ;
V_63 = F_27 ( V_56 -> V_54 . V_65 , L_7 , NULL ) ;
if ( V_63 ) {
int V_73 = V_74 + ( V_8 -> V_12 << 2 ) ;
F_6 ( V_8 -> V_9 + V_73 , F_34 ( V_63 ) ) ;
}
V_61 = F_15 ( V_8 , V_56 -> V_54 . V_65 ) ;
if ( V_61 ) {
F_35 ( V_8 -> V_9 ) ;
return V_61 ;
}
return 0 ;
}
static int F_36 ( struct V_62 * V_56 )
{
struct V_7 * V_8 = F_37 ( & V_56 -> V_54 ) ;
struct V_1 * V_2 = F_16 ( & V_8 -> V_3 ) ;
F_38 ( V_2 ) ;
F_25 ( V_2 -> V_58 ) ;
return 0 ;
}
