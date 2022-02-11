static int
F_1 ( struct V_1 * V_2 , const unsigned char * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
T_1 V_13 ;
if ( ! V_6 -> V_14 ) {
V_6 -> V_14 = F_3 ( V_8 ,
V_8 -> V_15 +
V_16 ) ;
if ( ! V_6 -> V_14 ) {
V_11 -> V_17 ++ ;
V_11 -> V_18 ++ ;
return 0 ;
}
}
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ ) {
T_2 V_19 ;
V_19 = F_4 ( & V_6 -> V_20 ,
V_6 -> V_14 -> V_3 ,
F_5 ( V_6 -> V_14 ) ,
V_3 [ V_13 ] ) ;
switch ( V_19 ) {
case V_21 :
case V_22 :
break;
case V_23 :
F_6 ( V_8 , L_1 ) ;
V_11 -> V_17 ++ ;
V_11 -> V_18 ++ ;
break;
case V_24 :
F_6 ( V_8 , L_2 ) ;
V_11 -> V_17 ++ ;
V_11 -> V_18 ++ ;
break;
default:
V_11 -> V_25 ++ ;
V_11 -> V_26 += V_19 ;
F_7 ( V_6 -> V_14 , V_19 ) ;
V_6 -> V_14 -> V_27 = F_8 (
V_6 -> V_14 , V_6 -> V_14 -> V_28 ) ;
V_6 -> V_14 -> V_29 = V_30 ;
F_9 ( V_6 -> V_14 ) ;
V_6 -> V_14 = F_3 ( V_8 ,
V_8 -> V_15 +
V_16 ) ;
if ( ! V_6 -> V_14 ) {
F_6 ( V_8 , L_3 ) ;
V_11 -> V_17 ++ ;
return V_13 ;
}
}
}
return V_13 ;
}
static void F_10 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_11 ( V_32 , struct V_5 , V_33 ) ;
struct V_10 * V_11 = & V_6 -> V_9 -> V_12 ;
int V_34 ;
F_12 ( & V_6 -> V_35 ) ;
if ( ! F_13 ( V_6 -> V_9 ) ) {
F_14 ( & V_6 -> V_35 ) ;
return;
}
if ( V_6 -> V_36 <= 0 ) {
V_11 -> V_37 ++ ;
F_14 ( & V_6 -> V_35 ) ;
F_15 ( V_6 -> V_9 ) ;
return;
}
V_34 = F_16 ( V_6 -> V_2 , V_6 -> V_38 ,
V_6 -> V_36 ) ;
if ( V_34 > 0 ) {
V_6 -> V_36 -= V_34 ;
V_6 -> V_38 += V_34 ;
}
F_14 ( & V_6 -> V_35 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( & V_6 -> V_33 ) ;
}
static int F_19 ( struct V_7 * V_28 )
{
struct V_5 * V_6 = F_20 ( V_28 ) ;
F_21 ( V_6 -> V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_28 )
{
struct V_5 * V_6 = F_20 ( V_28 ) ;
F_23 ( V_28 ) ;
F_24 ( & V_6 -> V_33 ) ;
F_12 ( & V_6 -> V_35 ) ;
V_6 -> V_36 = 0 ;
F_14 ( & V_6 -> V_35 ) ;
return 0 ;
}
static T_3
F_25 ( struct V_39 * V_40 , struct V_7 * V_28 )
{
struct V_10 * V_11 = & V_28 -> V_12 ;
struct V_5 * V_6 = F_20 ( V_28 ) ;
T_4 V_41 = 0 ;
int V_34 ;
T_4 * V_42 ;
F_26 ( & V_6 -> V_35 ) ;
F_27 ( V_6 -> V_36 ) ;
if ( ! F_13 ( V_28 ) ) {
F_28 ( & V_6 -> V_35 ) ;
F_29 ( V_6 -> V_9 , L_4 ) ;
goto V_43;
}
V_42 = V_6 -> V_44 ;
if ( V_40 -> V_45 < V_46 )
V_41 = V_46 - V_40 -> V_45 ;
V_42 += F_30 ( V_42 , V_40 -> V_45 + V_41 ) ;
memcpy ( V_42 , V_40 -> V_3 , V_40 -> V_45 ) ;
V_42 += V_40 -> V_45 ;
if ( V_41 ) {
memset ( V_42 , 0 , V_41 ) ;
V_42 += V_41 ;
}
V_42 += F_31 ( V_42 ) ;
F_23 ( V_6 -> V_9 ) ;
V_34 = F_16 ( V_6 -> V_2 , V_6 -> V_44 ,
V_42 - V_6 -> V_44 ) ;
if ( V_34 > 0 ) {
V_6 -> V_36 = ( V_42 - V_6 -> V_44 ) - V_34 ;
V_6 -> V_38 = V_6 -> V_44 + V_34 ;
V_11 -> V_47 += V_34 ;
}
F_28 ( & V_6 -> V_35 ) ;
F_32 ( V_28 ) ;
V_43:
F_33 ( V_40 ) ;
return V_48 ;
}
static void F_34 ( struct V_7 * V_28 )
{
struct V_5 * V_6 = F_20 ( V_28 ) ;
F_35 ( V_6 -> V_9 , L_5 ,
V_49 , F_36 ( V_28 ) ) ;
V_28 -> V_12 . V_50 ++ ;
V_28 -> V_12 . V_51 ++ ;
}
static int F_37 ( struct V_7 * V_28 )
{
struct V_5 * V_6 = F_20 ( V_28 ) ;
T_1 V_45 ;
V_28 -> V_15 = V_52 ;
V_28 -> type = V_53 ;
V_45 = V_54 + V_55 + V_56 ;
V_6 -> V_44 = F_38 ( & V_6 -> V_2 -> V_28 , V_45 , V_57 ) ;
if ( ! V_6 -> V_44 )
return - V_58 ;
V_6 -> V_14 = F_3 ( V_6 -> V_9 ,
V_6 -> V_9 -> V_15 +
V_16 ) ;
if ( ! V_6 -> V_14 )
return - V_59 ;
return 0 ;
}
static void F_39 ( struct V_7 * V_28 )
{
struct V_5 * V_6 = F_20 ( V_28 ) ;
if ( V_6 -> V_14 )
F_40 ( V_6 -> V_14 ) ;
}
static void F_41 ( struct V_7 * V_28 )
{
V_28 -> V_60 = & V_61 ;
V_28 -> V_62 = V_63 ;
V_28 -> V_64 &= ~ V_65 ;
V_28 -> V_66 = 100 ;
V_28 -> V_67 = V_68 ;
V_28 -> V_69 = V_52 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_7 * V_70 = F_43 ( sizeof( struct V_5 ) ) ;
struct V_5 * V_6 ;
const char * V_71 ;
T_5 V_72 = 115200 ;
int V_73 ;
if ( ! V_70 )
return - V_58 ;
F_41 ( V_70 ) ;
F_44 ( V_70 , & V_2 -> V_28 ) ;
V_6 = F_20 ( V_70 ) ;
if ( ! V_6 ) {
F_45 ( L_6 ) ;
V_73 = - V_58 ;
goto free;
}
V_6 -> V_9 = V_70 ;
V_6 -> V_2 = V_2 ;
F_46 ( & V_6 -> V_20 ) ;
F_47 ( & V_6 -> V_35 ) ;
F_48 ( & V_6 -> V_33 , F_10 ) ;
F_49 ( V_2 -> V_28 . V_74 , L_7 , & V_72 ) ;
V_71 = F_50 ( V_2 -> V_28 . V_74 ) ;
if ( V_71 )
F_51 ( V_6 -> V_9 -> V_75 , V_71 ) ;
if ( ! F_52 ( V_6 -> V_9 -> V_75 ) ) {
F_53 ( V_6 -> V_9 ) ;
F_54 ( & V_2 -> V_28 , L_8 ,
V_6 -> V_9 -> V_75 ) ;
}
F_55 ( V_6 -> V_9 ) ;
F_56 ( V_2 , V_6 ) ;
F_57 ( V_2 , & V_76 ) ;
V_73 = F_58 ( V_2 ) ;
if ( V_73 ) {
F_59 ( & V_2 -> V_28 , L_9 ,
V_70 -> V_77 ) ;
goto free;
}
V_72 = F_60 ( V_2 , V_72 ) ;
F_54 ( & V_2 -> V_28 , L_10 , V_72 ) ;
F_61 ( V_2 , false ) ;
V_73 = F_62 ( V_70 ) ;
if ( V_73 ) {
F_59 ( & V_2 -> V_28 , L_11 ,
V_70 -> V_77 ) ;
F_63 ( V_2 ) ;
F_64 ( & V_6 -> V_33 ) ;
goto free;
}
return 0 ;
free:
F_65 ( V_70 ) ;
return V_73 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_67 ( V_6 -> V_9 ) ;
F_63 ( V_2 ) ;
F_64 ( & V_6 -> V_33 ) ;
F_65 ( V_6 -> V_9 ) ;
}
