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
for ( V_3 = 0 ; V_3 < V_47 -> V_49 ; V_3 ++ )
for ( V_48 = 0 ; V_48 < V_47 -> V_49 ; V_48 ++ ) {
if ( V_3 == V_48 )
continue;
if ( V_47 -> V_50 [ V_3 ] . V_36 !=
V_47 -> V_50 [ V_48 ] . V_36 )
continue;
if ( V_47 -> V_50 [ V_3 ] . V_38 ==
V_47 -> V_50 [ V_48 ] . V_38 )
F_10 ( V_45 ,
L_1 ,
V_47 -> V_50 [ V_3 ] . V_36 ,
V_47 -> V_50 [ V_3 ] . V_38 ) ;
V_47 -> V_50 [ V_3 ] . V_51 = true ;
break;
}
}
static void
F_11 ( struct V_44 * V_45 , struct V_14 * V_52 )
{
if ( V_52 -> V_31 == V_53 ) {
V_52 -> V_54 = V_55 ;
return;
}
if ( V_52 -> V_33 == V_56 )
V_52 -> V_54 = V_57 ;
else
V_52 -> V_54 = V_58 ;
}
struct V_46 * F_12 ( struct V_44 * V_45 )
{
struct V_46 * V_59 ;
struct V_10 * V_11 ;
V_11 = F_13 ( V_45 ) ;
if ( F_14 ( V_11 ) )
return NULL ;
V_59 = F_15 ( V_45 , V_11 ) ;
F_16 ( V_11 ) ;
return V_59 ;
}
struct V_46 *
F_15 ( struct V_44 * V_45 , struct V_10 * V_11 )
{
union V_12 * V_60 ;
struct V_46 * V_47 ;
int V_3 , V_48 , V_59 , V_61 = 0 ;
V_60 = F_17 ( V_62 , V_63 ) ;
if ( ! V_60 )
return NULL ;
V_59 = F_18 ( V_11 , V_60 , V_62 ) ;
if ( V_59 < 0 ) {
F_19 ( V_45 , L_2 , V_59 ) ;
goto V_64;
}
for ( V_3 = 0 ; V_3 < V_65 ; V_3 ++ )
if ( V_60 [ V_3 ] . V_15 & V_66 )
V_61 ++ ;
if ( V_59 && V_59 != V_61 ) {
F_19 ( V_45 , L_3 ,
V_59 , V_61 ) ;
goto V_64;
}
V_47 = F_17 ( sizeof( * V_47 ) +
sizeof( struct V_14 ) * V_61 , V_63 ) ;
if ( ! V_47 )
goto V_64;
V_47 -> V_49 = V_61 ;
for ( V_3 = 0 , V_48 = 0 ; V_3 < V_65 ; V_3 ++ )
if ( V_60 [ V_3 ] . V_15 & V_66 )
F_5 ( V_11 , & V_60 [ V_3 ] , V_3 ,
& V_47 -> V_50 [ V_48 ++ ] ) ;
F_9 ( V_45 , V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_49 ; V_3 ++ )
F_11 ( V_45 , & V_47 -> V_50 [ V_3 ] ) ;
F_20 ( V_60 ) ;
return V_47 ;
V_64:
F_20 ( V_60 ) ;
return NULL ;
}
struct V_10 * F_21 ( struct V_44 * V_45 , unsigned int V_67 )
{
union V_12 * V_60 ;
struct V_10 * V_11 ;
int V_59 ;
V_60 = F_17 ( V_62 , V_63 ) ;
if ( ! V_60 )
return F_22 ( - V_68 ) ;
V_11 = F_13 ( V_45 ) ;
if ( F_14 ( V_11 ) ) {
F_20 ( V_60 ) ;
return V_11 ;
}
V_59 = F_18 ( V_11 , V_60 , V_62 ) ;
if ( V_59 < 0 ) {
F_19 ( V_45 , L_2 , V_59 ) ;
goto V_64;
}
if ( ! ( V_60 [ V_67 ] . V_15 & V_66 ) ) {
F_10 ( V_45 , L_4 ,
V_67 ) ;
goto V_64;
}
F_23 ( V_11 , V_60 , V_67 ) ;
return V_11 ;
V_64:
F_16 ( V_11 ) ;
F_20 ( V_60 ) ;
return F_22 ( - V_69 ) ;
}
void F_24 ( struct V_10 * V_11 )
{
union V_12 * V_60 = F_25 ( V_11 ) ;
F_26 ( V_11 , false ) ;
F_27 ( V_11 ) ;
F_16 ( V_11 ) ;
F_20 ( V_60 ) ;
}
int F_28 ( struct V_10 * V_11 )
{
union V_12 * V_60 = F_25 ( V_11 ) ;
int V_59 = 1 ;
if ( F_29 ( V_11 ) ) {
V_59 = F_30 ( V_11 , V_60 , V_62 ) ;
V_59 = V_59 < 0 ? V_59 : 0 ;
}
F_24 ( V_11 ) ;
return V_59 ;
}
int F_31 ( struct V_44 * V_45 , unsigned int V_67 , bool V_70 )
{
union V_12 * V_60 ;
struct V_10 * V_11 ;
T_2 V_71 ;
V_11 = F_21 ( V_45 , V_67 ) ;
if ( F_14 ( V_11 ) )
return F_32 ( V_11 ) ;
V_60 = F_25 ( V_11 ) ;
V_71 = F_6 ( V_60 [ V_67 ] . V_16 ) ;
if ( V_70 != F_7 ( V_72 , V_71 ) ) {
V_71 = F_6 ( V_60 [ V_67 ] . V_73 ) ;
V_71 &= ~ V_72 ;
V_71 |= F_33 ( V_72 , V_70 ) ;
V_60 [ V_67 ] . V_73 = F_34 ( V_71 ) ;
F_26 ( V_11 , true ) ;
}
return F_28 ( V_11 ) ;
}
int F_35 ( struct V_44 * V_45 , unsigned int V_67 , bool V_74 )
{
union V_12 * V_60 ;
struct V_10 * V_11 ;
T_2 V_71 ;
V_11 = F_21 ( V_45 , V_67 ) ;
if ( F_14 ( V_11 ) )
return F_32 ( V_11 ) ;
V_60 = F_25 ( V_11 ) ;
V_71 = F_6 ( V_60 [ V_67 ] . V_16 ) ;
if ( V_74 != F_7 ( V_75 , V_71 ) ) {
V_71 = F_6 ( V_60 [ V_67 ] . V_73 ) ;
V_71 &= ~ V_76 ;
V_71 |= F_33 ( V_76 , V_74 ) ;
V_60 [ V_67 ] . V_73 = F_34 ( V_71 ) ;
F_26 ( V_11 , true ) ;
}
return F_28 ( V_11 ) ;
}
static T_3 int
F_36 ( struct V_10 * V_11 , unsigned int V_77 ,
const T_2 V_78 , unsigned int V_79 , const T_2 V_80 )
{
union V_12 * V_60 = F_25 ( V_11 ) ;
unsigned int V_67 = F_37 ( V_11 ) ;
T_2 V_71 ;
if ( F_8 ( V_11 ) < 17 ) {
F_19 ( F_38 ( V_11 ) ,
L_5 ) ;
return - V_81 ;
}
V_71 = F_6 ( V_60 [ V_67 ] . V_82 [ V_77 ] ) ;
if ( V_79 == F_7 ( V_78 , V_71 ) )
return 0 ;
V_71 &= ~ V_78 ;
V_71 |= F_33 ( V_78 , V_79 ) ;
V_60 [ V_67 ] . V_82 [ V_77 ] = F_34 ( V_71 ) ;
V_60 [ V_67 ] . V_73 |= F_34 ( V_80 ) ;
F_26 ( V_11 , true ) ;
return 0 ;
}
int F_39 ( struct V_10 * V_11 , enum V_83 V_84 )
{
return F_36 ( V_11 , V_85 ,
V_43 , V_84 ,
V_86 ) ;
}
int F_40 ( struct V_10 * V_11 , unsigned int V_5 )
{
enum V_1 V_2 ;
V_2 = F_3 ( V_5 ) ;
if ( V_2 == V_6 ) {
F_10 ( F_38 ( V_11 ) ,
L_6 ,
V_5 ) ;
return - V_87 ;
}
return F_36 ( V_11 , V_85 ,
V_30 , V_2 ,
V_88 ) ;
}
int F_41 ( struct V_10 * V_11 , unsigned int V_22 )
{
return F_36 ( V_11 , V_89 , V_23 ,
V_22 , V_90 ) ;
}
