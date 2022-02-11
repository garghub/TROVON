static unsigned int F_1 ( enum V_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 [ V_3 ] . V_5 ;
return 0 ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_5 == V_5 )
return V_4 [ V_3 ] . V_2 ;
return V_6 ;
}
static void F_4 ( T_1 * V_7 , const T_1 * V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
V_7 [ V_9 - V_3 - 1 ] = V_8 [ V_3 ] ;
}
static void
F_5 ( struct V_10 * V_11 , const union V_12 * V_8 ,
unsigned int V_13 , struct V_14 * V_7 )
{
unsigned int V_2 ;
T_2 V_15 , V_16 ;
V_15 = F_6 ( V_8 -> V_15 ) ;
V_16 = F_6 ( V_8 -> V_16 ) ;
V_7 -> V_17 = F_7 ( V_18 , V_15 ) ;
V_7 -> V_13 = V_13 ;
V_7 -> V_19 = V_13 / V_20 ;
V_7 -> V_21 = V_13 % V_20 ;
V_7 -> V_22 = F_7 ( V_23 , V_15 ) ;
V_7 -> V_24 = F_7 ( V_25 , V_16 ) ;
V_7 -> V_26 = F_7 ( V_27 , V_16 ) ;
V_7 -> V_28 = F_7 ( V_29 , V_16 ) ;
V_2 = F_1 ( F_7 ( V_30 , V_16 ) ) ;
V_7 -> V_5 = V_7 -> V_22 * V_2 ;
V_7 -> V_31 = F_7 ( V_32 , V_16 ) ;
V_7 -> V_33 = F_7 ( V_34 , V_16 ) ;
F_4 ( V_7 -> V_35 , V_8 -> V_35 ) ;
V_7 -> V_36 = F_7 ( V_37 , V_15 ) ;
V_7 -> V_38 = F_7 ( V_39 , V_15 ) ;
if ( F_8 ( V_11 ) < 17 )
return;
V_7 -> V_40 = F_7 ( V_41 , V_16 ) ;
V_7 -> V_42 = F_7 ( V_43 , V_16 ) ;
}
static void
F_9 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
unsigned int V_3 , V_48 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_49 ; V_3 ++ ) {
V_47 -> V_50 = F_10 ( V_47 -> V_50 , V_47 -> V_51 [ V_3 ] . V_13 ) ;
for ( V_48 = 0 ; V_48 < V_47 -> V_49 ; V_48 ++ ) {
if ( V_47 -> V_51 [ V_3 ] . V_36 !=
V_47 -> V_51 [ V_48 ] . V_36 )
continue;
V_47 -> V_51 [ V_3 ] . V_52 += V_47 -> V_51 [ V_48 ] . V_22 ;
if ( V_3 == V_48 )
continue;
if ( V_47 -> V_51 [ V_3 ] . V_38 ==
V_47 -> V_51 [ V_48 ] . V_38 )
F_11 ( V_45 ,
L_1 ,
V_47 -> V_51 [ V_3 ] . V_36 ,
V_47 -> V_51 [ V_3 ] . V_38 ) ;
V_47 -> V_51 [ V_3 ] . V_53 = true ;
}
}
}
static void
F_12 ( struct V_44 * V_45 , struct V_14 * V_54 )
{
if ( V_54 -> V_31 == V_55 ) {
V_54 -> V_56 = V_57 ;
return;
}
if ( V_54 -> V_33 == V_58 )
V_54 -> V_56 = V_59 ;
else
V_54 -> V_56 = V_60 ;
}
struct V_46 * F_13 ( struct V_44 * V_45 )
{
struct V_46 * V_61 ;
struct V_10 * V_11 ;
V_11 = F_14 ( V_45 ) ;
if ( F_15 ( V_11 ) )
return NULL ;
V_61 = F_16 ( V_45 , V_11 ) ;
F_17 ( V_11 ) ;
return V_61 ;
}
struct V_46 *
F_16 ( struct V_44 * V_45 , struct V_10 * V_11 )
{
union V_12 * V_62 ;
struct V_46 * V_47 ;
int V_3 , V_48 , V_61 , V_63 = 0 ;
V_62 = F_18 ( V_64 , V_65 ) ;
if ( ! V_62 )
return NULL ;
V_61 = F_19 ( V_11 , V_62 , V_64 ) ;
if ( V_61 < 0 ) {
F_20 ( V_45 , L_2 , V_61 ) ;
goto V_66;
}
for ( V_3 = 0 ; V_3 < V_67 ; V_3 ++ )
if ( V_62 [ V_3 ] . V_15 & V_68 )
V_63 ++ ;
if ( V_61 && V_61 != V_63 ) {
F_20 ( V_45 , L_3 ,
V_61 , V_63 ) ;
goto V_66;
}
V_47 = F_18 ( sizeof( * V_47 ) +
sizeof( struct V_14 ) * V_63 , V_65 ) ;
if ( ! V_47 )
goto V_66;
V_47 -> V_49 = V_63 ;
for ( V_3 = 0 , V_48 = 0 ; V_3 < V_67 ; V_3 ++ )
if ( V_62 [ V_3 ] . V_15 & V_68 )
F_5 ( V_11 , & V_62 [ V_3 ] , V_3 ,
& V_47 -> V_51 [ V_48 ++ ] ) ;
F_9 ( V_45 , V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_49 ; V_3 ++ )
F_12 ( V_45 , & V_47 -> V_51 [ V_3 ] ) ;
F_21 ( V_62 ) ;
return V_47 ;
V_66:
F_21 ( V_62 ) ;
return NULL ;
}
struct V_10 * F_22 ( struct V_44 * V_45 , unsigned int V_69 )
{
union V_12 * V_62 ;
struct V_10 * V_11 ;
int V_61 ;
V_62 = F_18 ( V_64 , V_65 ) ;
if ( ! V_62 )
return F_23 ( - V_70 ) ;
V_11 = F_14 ( V_45 ) ;
if ( F_15 ( V_11 ) ) {
F_21 ( V_62 ) ;
return V_11 ;
}
V_61 = F_19 ( V_11 , V_62 , V_64 ) ;
if ( V_61 < 0 ) {
F_20 ( V_45 , L_2 , V_61 ) ;
goto V_66;
}
if ( ! ( V_62 [ V_69 ] . V_15 & V_68 ) ) {
F_11 ( V_45 , L_4 ,
V_69 ) ;
goto V_66;
}
F_24 ( V_11 , V_62 , V_69 ) ;
return V_11 ;
V_66:
F_17 ( V_11 ) ;
F_21 ( V_62 ) ;
return F_23 ( - V_71 ) ;
}
void F_25 ( struct V_10 * V_11 )
{
union V_12 * V_62 = F_26 ( V_11 ) ;
F_27 ( V_11 , false ) ;
F_28 ( V_11 ) ;
F_17 ( V_11 ) ;
F_21 ( V_62 ) ;
}
int F_29 ( struct V_10 * V_11 )
{
union V_12 * V_62 = F_26 ( V_11 ) ;
int V_61 = 1 ;
if ( F_30 ( V_11 ) ) {
V_61 = F_31 ( V_11 , V_62 , V_64 ) ;
V_61 = V_61 < 0 ? V_61 : 0 ;
}
F_25 ( V_11 ) ;
return V_61 ;
}
int F_32 ( struct V_44 * V_45 , unsigned int V_69 , bool V_72 )
{
union V_12 * V_62 ;
struct V_10 * V_11 ;
T_2 V_73 ;
V_11 = F_22 ( V_45 , V_69 ) ;
if ( F_15 ( V_11 ) )
return F_33 ( V_11 ) ;
V_62 = F_26 ( V_11 ) ;
V_73 = F_6 ( V_62 [ V_69 ] . V_16 ) ;
if ( V_72 != F_7 ( V_74 , V_73 ) ) {
V_73 = F_6 ( V_62 [ V_69 ] . V_75 ) ;
V_73 &= ~ V_74 ;
V_73 |= F_34 ( V_74 , V_72 ) ;
V_62 [ V_69 ] . V_75 = F_35 ( V_73 ) ;
F_27 ( V_11 , true ) ;
}
return F_29 ( V_11 ) ;
}
int F_36 ( struct V_44 * V_45 , unsigned int V_69 , bool V_76 )
{
union V_12 * V_62 ;
struct V_10 * V_11 ;
T_2 V_73 ;
V_11 = F_22 ( V_45 , V_69 ) ;
if ( F_15 ( V_11 ) )
return F_33 ( V_11 ) ;
if ( F_8 ( V_11 ) < 20 ) {
F_25 ( V_11 ) ;
return - V_77 ;
}
V_62 = F_26 ( V_11 ) ;
V_73 = F_6 ( V_62 [ V_69 ] . V_16 ) ;
if ( V_76 != F_7 ( V_78 , V_73 ) ) {
V_73 = F_6 ( V_62 [ V_69 ] . V_75 ) ;
V_73 &= ~ V_79 ;
V_73 |= F_34 ( V_79 , V_76 ) ;
V_62 [ V_69 ] . V_75 = F_35 ( V_73 ) ;
F_27 ( V_11 , true ) ;
}
return F_29 ( V_11 ) ;
}
static T_3 int
F_37 ( struct V_10 * V_11 , unsigned int V_80 ,
const T_2 V_81 , unsigned int V_82 , const T_2 V_83 )
{
union V_12 * V_62 = F_26 ( V_11 ) ;
unsigned int V_69 = F_38 ( V_11 ) ;
T_2 V_73 ;
if ( F_8 ( V_11 ) < 17 ) {
F_20 ( F_39 ( V_11 ) ,
L_5 ) ;
return - V_77 ;
}
V_73 = F_6 ( V_62 [ V_69 ] . V_84 [ V_80 ] ) ;
if ( V_82 == F_7 ( V_81 , V_73 ) )
return 0 ;
V_73 &= ~ V_81 ;
V_73 |= F_34 ( V_81 , V_82 ) ;
V_62 [ V_69 ] . V_84 [ V_80 ] = F_35 ( V_73 ) ;
V_62 [ V_69 ] . V_75 |= F_35 ( V_83 ) ;
F_27 ( V_11 , true ) ;
return 0 ;
}
int F_40 ( struct V_10 * V_11 , enum V_85 V_86 )
{
return F_37 ( V_11 , V_87 ,
V_43 , V_86 ,
V_88 ) ;
}
int F_41 ( struct V_10 * V_11 , unsigned int V_5 )
{
enum V_1 V_2 ;
V_2 = F_3 ( V_5 ) ;
if ( V_2 == V_6 ) {
F_11 ( F_39 ( V_11 ) ,
L_6 ,
V_5 ) ;
return - V_89 ;
}
return F_37 ( V_11 , V_87 ,
V_30 , V_2 ,
V_90 ) ;
}
int F_42 ( struct V_10 * V_11 , unsigned int V_22 )
{
return F_37 ( V_11 , V_91 , V_23 ,
V_22 , V_92 ) ;
}
