void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
if ( F_2 ( ! V_4 ) )
return;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = 0 ;
switch ( V_6 ) {
case V_8 :
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_4 -> V_12 ;
break;
case V_13 :
V_2 -> V_9 = V_14 ;
V_2 -> V_11 = V_4 -> V_12 ;
break;
case V_15 :
V_2 -> V_9 = V_16 ;
V_2 -> V_11 = V_4 -> V_12 + 10 ;
break;
case V_17 :
V_2 -> V_9 = V_16 ;
V_2 -> V_11 = V_4 -> V_12 - 10 ;
break;
default:
F_2 ( 1 ) ;
}
}
bool F_3 ( const struct V_1 * V_2 )
{
T_1 V_18 ;
if ( ! V_2 -> V_4 )
return false ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_14 :
case V_10 :
if ( V_2 -> V_11 != V_18 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_16 :
if ( V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_19 :
if ( V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 )
return false ;
if ( ! V_2 -> V_7 )
return false ;
break;
case V_20 :
if ( V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_21 :
if ( V_2 -> V_11 != V_18 + 70 &&
V_2 -> V_11 != V_18 + 50 &&
V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 &&
V_2 -> V_11 != V_18 - 50 &&
V_2 -> V_11 != V_18 - 70 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
default:
return false ;
}
return true ;
}
static void F_4 ( const struct V_1 * V_22 ,
int * V_23 , int * V_24 )
{
int V_25 ;
switch ( V_22 -> V_9 ) {
case V_16 :
* V_23 = V_22 -> V_11 ;
* V_24 = 0 ;
break;
case V_20 :
case V_19 :
* V_24 = V_22 -> V_11 ;
V_25 = ( 30 + V_22 -> V_4 -> V_12 - V_22 -> V_11 ) / 20 ;
V_25 /= 2 ;
* V_23 = V_22 -> V_11 - 20 + 40 * V_25 ;
break;
case V_21 :
V_25 = ( 70 + V_22 -> V_4 -> V_12 - V_22 -> V_11 ) / 20 ;
V_25 /= 2 ;
* V_23 = V_22 -> V_11 - 60 + 40 * V_25 ;
V_25 /= 2 ;
* V_24 = V_22 -> V_11 - 40 + 80 * V_25 ;
break;
default:
F_5 ( 1 ) ;
}
}
const struct V_1 *
F_6 ( const struct V_1 * V_26 ,
const struct V_1 * V_27 )
{
T_1 V_28 , V_29 , V_30 , V_31 ;
if ( F_7 ( V_26 , V_27 ) )
return V_26 ;
if ( V_26 -> V_4 != V_27 -> V_4 )
return NULL ;
if ( V_26 -> V_9 == V_27 -> V_9 )
return NULL ;
if ( V_26 -> V_9 == V_10 ||
V_26 -> V_9 == V_14 )
return V_27 ;
if ( V_27 -> V_9 == V_10 ||
V_27 -> V_9 == V_14 )
return V_26 ;
F_4 ( V_26 , & V_28 , & V_29 ) ;
F_4 ( V_27 , & V_30 , & V_31 ) ;
if ( V_28 != V_30 )
return NULL ;
F_2 ( ! V_29 && ! V_31 ) ;
if ( V_29 && V_31 && V_29 != V_31 )
return NULL ;
if ( V_26 -> V_9 > V_27 -> V_9 )
return V_26 ;
return V_27 ;
}
static bool F_8 ( struct V_32 * V_32 ,
T_1 V_12 , T_1 V_33 ,
T_1 V_34 )
{
struct V_3 * V_22 ;
T_1 V_35 ;
for ( V_35 = V_12 - V_33 / 2 + 10 ;
V_35 <= V_12 + V_33 / 2 - 10 ;
V_35 += 20 ) {
V_22 = F_9 ( V_32 , V_35 ) ;
if ( ! V_22 || V_22 -> V_36 & V_34 )
return false ;
}
return true ;
}
bool F_10 ( struct V_32 * V_32 ,
const struct V_1 * V_2 ,
T_1 V_34 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
T_1 V_9 , V_18 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_38 = & V_32 -> V_41 [ V_2 -> V_4 -> V_42 ] -> V_38 ;
V_40 = & V_32 -> V_41 [ V_2 -> V_4 -> V_42 ] -> V_40 ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_14 :
if ( ! V_38 -> V_43 )
return false ;
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
if ( ! V_38 -> V_43 )
return false ;
if ( ! ( V_38 -> V_44 & V_45 ) ||
V_38 -> V_44 & V_46 )
return false ;
if ( V_2 -> V_11 < V_18 &&
V_2 -> V_4 -> V_36 & V_47 )
return false ;
if ( V_2 -> V_11 > V_18 &&
V_2 -> V_4 -> V_36 & V_48 )
return false ;
break;
case V_19 :
if ( ! ( V_40 -> V_44 & V_49 ) )
return false ;
case V_20 :
if ( ! V_40 -> V_50 )
return false ;
V_9 = 80 ;
break;
case V_21 :
if ( ! V_40 -> V_50 )
return false ;
if ( ! ( V_40 -> V_44 & V_51 ) )
return false ;
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return false ;
}
if ( V_9 > 20 )
V_34 |= V_52 ;
if ( ! F_8 ( V_32 , V_2 -> V_11 ,
V_9 , V_34 ) )
return false ;
if ( ! V_2 -> V_7 )
return true ;
return F_8 ( V_32 , V_2 -> V_7 ,
V_9 , V_34 ) ;
}
bool F_11 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
bool V_53 ;
F_12 ( V_32 , V_2 ) ;
V_53 = F_10 ( V_32 , V_2 ,
V_54 |
V_55 |
V_56 |
V_57 ) ;
F_13 ( V_53 ) ;
return V_53 ;
}
int F_14 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
if ( ! V_59 -> V_60 -> V_61 )
return - V_62 ;
if ( ! F_15 ( V_59 ) )
return - V_63 ;
return F_16 ( V_59 , V_2 ) ;
}
void
F_17 ( struct V_64 * V_65 ,
struct V_3 * * V_4 ,
enum V_66 * V_67 )
{
* V_4 = NULL ;
* V_67 = V_68 ;
F_18 ( V_65 ) ;
if ( V_65 -> V_69 && ! F_19 ( V_65 -> V_69 ) )
return;
switch ( V_65 -> V_70 ) {
case V_71 :
if ( V_65 -> V_72 ) {
* V_4 = V_65 -> V_72 -> V_73 . V_74 ;
* V_67 = V_65 -> V_75
? V_76
: V_77 ;
return;
}
case V_78 :
case V_79 :
if ( V_65 -> V_72 ) {
* V_4 = V_65 -> V_72 -> V_73 . V_74 ;
* V_67 = V_76 ;
return;
}
break;
case V_80 :
case V_81 :
if ( V_65 -> V_82 ) {
* V_4 = V_65 -> V_74 ;
* V_67 = V_76 ;
}
return;
case V_83 :
if ( V_65 -> V_84 ) {
* V_4 = V_65 -> V_74 ;
* V_67 = V_76 ;
}
return;
case V_85 :
case V_86 :
case V_87 :
return;
case V_88 :
if ( V_65 -> V_32 -> V_89 &
V_90 )
* V_67 = V_77 ;
return;
case V_91 :
case V_92 :
F_2 ( 1 ) ;
}
return;
}
