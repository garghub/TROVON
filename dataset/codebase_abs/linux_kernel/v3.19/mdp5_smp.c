static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static inline enum V_9 F_4 ( enum V_10 V_11 , int V_12 )
{
F_5 ( V_12 >= F_6 ( V_11 ) ) ;
switch ( V_11 ) {
case V_13 : return V_14 + V_12 ;
case V_15 : return V_16 + V_12 ;
case V_17 : return V_18 + V_12 ;
case V_19 : return V_20 ;
case V_21 : return V_22 ;
case V_23 : return V_24 ;
case V_25 : return V_26 + V_12 ;
case V_27 : return V_28 + V_12 ;
case V_29 : return V_30 + V_12 ;
case V_31 : return V_32 ;
default: return V_33 ;
}
}
static int F_7 ( struct V_2 * V_3 ,
enum V_9 V_34 , int V_35 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_36 * V_37 ;
struct V_38 * V_39 = & V_3 -> V_40 [ V_34 ] ;
int V_41 , V_42 , V_43 , V_44 , V_45 = V_3 -> V_46 ;
int V_47 ;
unsigned long V_48 ;
V_37 = F_8 ( V_1 -> V_49 ) ;
V_47 = V_37 -> V_3 . V_47 [ V_34 ] ;
F_9 ( & V_3 -> V_50 , V_48 ) ;
V_35 -= V_47 ;
if ( V_47 )
F_10 ( L_1 , V_35 , V_47 ) ;
V_43 = V_45 - F_11 ( V_3 -> V_51 , V_45 ) ;
if ( V_35 > V_43 ) {
F_12 ( V_1 -> V_6 -> V_6 , L_2 ,
V_35 , V_43 ) ;
V_42 = - V_52 ;
goto V_53;
}
V_44 = F_11 ( V_39 -> V_54 , V_45 ) ;
if ( V_35 > V_44 ) {
for ( V_41 = V_44 ; V_41 < V_35 ; V_41 ++ ) {
int V_55 = F_13 ( V_3 -> V_51 , V_45 ) ;
F_14 ( V_55 , V_39 -> V_54 ) ;
F_14 ( V_55 , V_3 -> V_51 ) ;
}
} else {
for ( V_41 = V_44 ; V_41 > V_35 ; V_41 -- ) {
int V_55 = F_15 ( V_39 -> V_54 , V_45 ) ;
F_16 ( V_55 , V_39 -> V_54 ) ;
}
}
V_53:
F_17 ( & V_3 -> V_50 , V_48 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 ,
enum V_10 V_11 , int V_35 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_56 = V_3 -> V_57 / ( 128 / V_58 ) ;
T_1 V_59 ;
V_59 = ( V_35 * V_56 ) / 4 ;
F_19 ( V_1 , F_20 ( V_11 ) , V_59 * 1 ) ;
F_19 ( V_1 , F_21 ( V_11 ) , V_59 * 2 ) ;
F_19 ( V_1 , F_22 ( V_11 ) , V_59 * 3 ) ;
}
int F_23 ( struct V_2 * V_3 , enum V_10 V_11 , T_1 V_60 , T_1 V_61 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_62 * V_6 = V_1 -> V_6 ;
int V_63 = F_24 ( V_1 -> V_49 ) ;
int V_41 , V_64 , V_65 , V_66 , V_35 , V_42 ;
V_65 = F_25 ( V_60 ) ;
V_64 = F_26 ( V_60 ) ;
V_66 = 2 ;
for ( V_41 = 0 , V_35 = 0 ; V_41 < V_65 ; V_41 ++ ) {
int V_67 , V_68 , V_69 ;
V_69 = F_27 ( V_60 , V_41 ) ;
V_68 = V_61 * V_69 / ( V_41 ? V_64 : 1 ) ;
V_67 = F_28 ( V_68 * V_66 , V_3 -> V_57 ) ;
if ( V_63 == 0 )
V_67 = F_29 ( V_67 ) ;
F_10 ( L_3 , F_30 ( V_11 ) , V_41 , V_67 ) ;
V_42 = F_7 ( V_3 , F_4 ( V_11 , V_41 ) , V_67 ) ;
if ( V_42 ) {
F_12 ( V_6 -> V_6 , L_4 ,
V_67 , V_42 ) ;
return V_42 ;
}
V_35 += V_67 ;
}
F_18 ( V_3 , V_11 , V_35 ) ;
return 0 ;
}
void F_31 ( struct V_2 * V_3 , enum V_10 V_11 )
{
int V_41 , V_35 ;
for ( V_41 = 0 , V_35 = 0 ; V_41 < F_6 ( V_11 ) ; V_41 ++ )
F_7 ( V_3 , F_4 ( V_11 , V_41 ) , 0 ) ;
F_18 ( V_3 , V_11 , 0 ) ;
}
static void F_32 ( struct V_2 * V_3 ,
enum V_9 V_34 , T_2 * V_70 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_45 = V_3 -> V_46 ;
T_1 V_55 , V_59 ;
F_33 (blk, *assigned, cnt) {
int V_71 = V_55 / 3 ;
int V_72 = V_55 % 3 ;
V_59 = F_34 ( V_1 , F_35 ( V_71 ) ) ;
switch ( V_72 ) {
case 0 :
V_59 &= ~ V_73 ;
V_59 |= F_36 ( V_34 ) ;
break;
case 1 :
V_59 &= ~ V_74 ;
V_59 |= F_37 ( V_34 ) ;
break;
case 2 :
V_59 &= ~ V_75 ;
V_59 |= F_38 ( V_34 ) ;
break;
}
F_19 ( V_1 , F_35 ( V_71 ) , V_59 ) ;
F_19 ( V_1 , F_39 ( V_71 ) , V_59 ) ;
}
}
void F_40 ( struct V_2 * V_3 , enum V_10 V_11 )
{
int V_45 = V_3 -> V_46 ;
T_2 V_70 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_6 ( V_11 ) ; V_41 ++ ) {
enum V_9 V_34 = F_4 ( V_11 , V_41 ) ;
struct V_38 * V_39 = & V_3 -> V_40 [ V_34 ] ;
F_41 ( V_70 , V_39 -> V_76 , V_39 -> V_54 , V_45 ) ;
F_32 ( V_3 , V_34 , & V_70 ) ;
}
}
void F_42 ( struct V_2 * V_3 , enum V_10 V_11 )
{
int V_45 = V_3 -> V_46 ;
T_2 V_77 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_6 ( V_11 ) ; V_41 ++ ) {
enum V_9 V_34 = F_4 ( V_11 , V_41 ) ;
struct V_38 * V_39 = & V_3 -> V_40 [ V_34 ] ;
if ( F_43 ( V_77 , V_39 -> V_76 , V_39 -> V_54 , V_45 ) ) {
unsigned long V_48 ;
F_9 ( & V_3 -> V_50 , V_48 ) ;
F_43 ( V_3 -> V_51 , V_3 -> V_51 , V_77 , V_45 ) ;
F_17 ( & V_3 -> V_50 , V_48 ) ;
F_32 ( V_3 , V_33 , & V_77 ) ;
}
F_44 ( V_39 -> V_76 , V_39 -> V_54 , V_45 ) ;
}
}
void F_45 ( struct V_2 * V_3 )
{
F_46 ( V_3 ) ;
}
struct V_2 * F_47 ( struct V_62 * V_6 , const struct V_78 * V_49 )
{
struct V_2 * V_3 = NULL ;
int V_42 ;
V_3 = F_48 ( sizeof( * V_3 ) , V_79 ) ;
if ( F_49 ( ! V_3 ) ) {
V_42 = - V_80 ;
goto V_53;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_46 = V_49 -> V_81 ;
V_3 -> V_57 = V_49 -> V_82 ;
F_44 ( V_3 -> V_51 , V_49 -> V_83 , V_3 -> V_46 ) ;
F_50 ( & V_3 -> V_50 ) ;
return V_3 ;
V_53:
if ( V_3 )
F_45 ( V_3 ) ;
return F_51 ( V_42 ) ;
}
