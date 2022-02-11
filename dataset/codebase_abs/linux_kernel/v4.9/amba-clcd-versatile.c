struct V_1 * F_1 ( const char * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( strcmp ( V_4 [ V_3 ] -> V_5 . V_2 , V_2 ) == 0 )
break;
if ( V_3 < F_2 ( V_4 ) )
return V_4 [ V_3 ] ;
F_3 ( L_1 , V_2 ) ;
return NULL ;
}
int F_4 ( struct V_6 * V_7 , unsigned long V_8 )
{
T_1 V_9 ;
V_7 -> V_7 . V_10 = F_5 ( & V_7 -> V_11 -> V_11 , V_8 , & V_9 ,
V_12 ) ;
if ( ! V_7 -> V_7 . V_10 ) {
F_3 ( L_2 ) ;
return - V_13 ;
}
V_7 -> V_7 . V_14 . V_15 = V_9 ;
V_7 -> V_7 . V_14 . V_16 = V_8 ;
return 0 ;
}
int F_6 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
return F_7 ( & V_7 -> V_11 -> V_11 , V_18 , V_7 -> V_7 . V_10 ,
V_7 -> V_7 . V_14 . V_15 , V_7 -> V_7 . V_14 . V_16 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
F_9 ( & V_7 -> V_11 -> V_11 , V_7 -> V_7 . V_14 . V_16 , V_7 -> V_7 . V_10 ,
V_7 -> V_7 . V_14 . V_15 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = & V_7 -> V_7 . V_20 ;
T_2 V_21 ;
F_11 ( & V_7 -> V_11 -> V_11 , L_3 ) ;
V_21 = V_22 | V_23 |
V_24 | V_25 ;
if ( V_20 -> V_26 <= 8 ||
( V_20 -> V_26 == 16 && V_20 -> V_27 . V_28 == 5 ) )
V_21 |= V_29 ;
else if ( V_7 -> V_7 . V_20 . V_26 <= 16 )
V_21 |= V_30 ;
else
V_21 = 0 ;
F_12 ( V_31 ,
V_32 ,
V_33 ,
V_21 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_11 ( & V_7 -> V_11 -> V_11 , L_4 ) ;
F_12 ( V_31 ,
V_34 ,
V_35 ,
0 ) ;
if ( V_36 ) {
F_11 ( & V_7 -> V_11 -> V_11 , L_5 ) ;
F_12 ( V_36 ,
V_37 ,
V_38 ,
V_39 ) ;
}
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = & V_7 -> V_7 . V_20 ;
T_2 V_21 = 0 ;
F_11 ( & V_7 -> V_11 -> V_11 , L_6 ) ;
switch ( V_20 -> V_27 . V_28 ) {
case 5 :
V_21 |= V_40 ;
break;
case 6 :
if ( V_20 -> V_41 . V_42 == 0 )
V_21 |= V_43 ;
else
V_21 |= V_44 ;
break;
case 8 :
V_21 |= V_45 ;
break;
}
F_12 ( V_31 ,
V_34 ,
V_46 ,
V_21 ) ;
F_12 ( V_31 ,
V_34 ,
V_35 ,
V_47 | V_48 ) ;
if ( V_36 ) {
F_11 ( & V_7 -> V_11 -> V_11 , L_7 ) ;
F_12 ( V_36 ,
V_37 ,
V_38 ,
V_49 ) ;
}
}
static void F_15 ( struct V_6 * V_7 , struct V_50 * V_51 )
{
F_16 ( V_7 , V_51 ) ;
if ( V_7 -> V_7 . V_20 . V_27 . V_28 == 6 )
V_51 -> V_52 &= ~ V_53 ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_11 ( & V_7 -> V_11 -> V_11 , L_8 ) ;
F_12 ( V_31 ,
V_34 ,
V_35 ,
0 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
F_11 ( & V_7 -> V_11 -> V_11 , L_9 ) ;
F_12 ( V_31 ,
V_34 ,
V_35 ,
V_47 | V_48 ) ;
}
static void F_19 ( struct V_54 * V_11 ,
struct V_55 * V_56 )
{
struct V_57 const * V_58 = NULL ;
struct V_55 * V_59 = NULL ;
T_2 V_21 ;
int V_60 ;
int V_3 ;
V_60 = F_20 ( V_31 , V_34 , & V_21 ) ;
if ( V_60 ) {
F_21 ( V_11 , L_10 ) ;
return;
}
V_21 &= V_61 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_62 ) ; V_3 ++ ) {
V_58 = & V_62 [ V_3 ] ;
if ( V_21 == V_58 -> V_63 ) {
F_21 ( V_11 , L_11 ,
V_58 -> V_64 ) ;
break;
}
}
if ( V_3 == F_2 ( V_62 ) ) {
F_21 ( V_11 , L_12 ) ;
return;
}
V_59 = F_22 ( V_56 ) ;
if ( ! V_59 ) {
F_21 ( V_11 , L_13 ) ;
return;
}
if ( ! F_23 ( V_59 , V_58 -> V_64 ) )
F_21 ( V_11 , L_14
L_15 ) ;
if ( ! V_58 -> V_65 )
return;
V_36 = F_24 (
L_16 ) ;
if ( F_25 ( V_36 ) ) {
F_21 ( V_11 , L_17 ) ;
V_36 = NULL ;
return;
}
}
int F_26 ( struct V_6 * V_7 ,
struct V_55 * V_56 )
{
const struct V_66 * V_67 ;
enum V_68 V_69 ;
struct V_55 * V_70 ;
struct V_71 * V_72 ;
struct V_54 * V_11 = & V_7 -> V_11 -> V_11 ;
V_70 = F_27 ( NULL , V_73 ,
& V_67 ) ;
if ( ! V_70 ) {
return 0 ;
}
V_69 = (enum V_68 ) V_67 -> V_74 ;
V_72 = F_28 ( V_70 ) ;
if ( F_25 ( V_72 ) ) {
F_21 ( V_11 , L_18 ) ;
return F_29 ( V_72 ) ;
}
switch ( V_69 ) {
case V_75 :
V_31 = V_72 ;
V_7 -> V_76 -> V_77 = F_10 ;
V_7 -> V_76 -> V_78 = V_79 | V_80 |
V_81 ;
F_11 ( V_11 , L_19 ) ;
break;
case V_82 :
V_31 = V_72 ;
V_7 -> V_76 -> V_77 = F_14 ;
V_7 -> V_76 -> V_83 = F_13 ;
V_7 -> V_76 -> V_84 = F_15 ;
F_19 ( V_11 , V_56 ) ;
F_11 ( V_11 , L_20 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_31 = V_72 ;
V_7 -> V_76 -> V_77 = F_18 ;
V_7 -> V_76 -> V_83 = F_17 ;
F_11 ( V_11 , L_21 ) ;
break;
default:
F_11 ( V_11 , L_22 ) ;
break;
}
return 0 ;
}
