int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 -> V_2 , V_1 -> V_3 ,
V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
unsigned long V_7 , V_8 ;
V_7 = V_6 -> V_7 ;
V_8 = V_6 -> V_8 ;
if ( ! V_7 || ! V_8 )
return 60 ;
return F_4 ( V_6 -> clock * 1000 , V_8 * V_7 ) ;
}
static inline int F_5 ( int V_9 , int V_10 , unsigned int V_11 )
{
return V_9 * V_10 * V_11 ;
}
int F_6 ( struct V_1 * V_1 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_16 * V_17 [ 3 ] ;
unsigned long V_18 , V_19 , V_20 ;
int V_21 , V_22 ;
for ( V_22 = 0 ; V_22 < F_7 ( V_13 -> V_23 ) ; V_22 ++ ) {
V_17 [ V_22 ] = F_8 ( V_13 , V_22 ) ;
if ( ! V_17 [ V_22 ] ) {
F_9 ( L_1 , V_22 ) ;
return - V_24 ;
}
}
V_18 = V_17 [ 0 ] -> V_25 + V_13 -> V_26 [ 0 ] +
V_13 -> V_27 [ 0 ] * V_15 + ( V_13 -> V_28 >> 3 ) * V_14 ;
if ( V_18 & 0x7 ) {
F_9 ( L_2 ) ;
return - V_29 ;
}
if ( V_13 -> V_27 [ 0 ] < 1 || V_13 -> V_27 [ 0 ] > 16384 ) {
F_9 ( L_3 ) ;
return - V_29 ;
}
if ( V_1 -> V_30 && V_13 -> V_27 [ 0 ] != V_1 -> V_31 [ 0 ] ) {
F_9 ( L_4 ) ;
return - V_29 ;
}
V_1 -> V_31 [ 0 ] = V_13 -> V_27 [ 0 ] ;
switch ( V_13 -> V_23 ) {
case V_32 :
case V_33 :
V_19 = V_17 [ 1 ] -> V_25 + V_13 -> V_26 [ 1 ] +
V_13 -> V_27 [ 1 ] * V_15 / 2 + V_14 / 2 - V_18 ;
V_20 = V_17 [ 2 ] -> V_25 + V_13 -> V_26 [ 2 ] +
V_13 -> V_27 [ 2 ] * V_15 / 2 + V_14 / 2 - V_18 ;
if ( ( V_19 & 0x7 ) || ( V_20 & 0x7 ) ) {
F_9 ( L_5 ) ;
return - V_29 ;
}
if ( ( V_19 > 0xfffff8 ) || ( V_20 > 0xfffff8 ) ) {
F_9 ( L_6 ) ;
return - V_29 ;
}
if ( V_1 -> V_30 && ( ( V_1 -> V_34 != V_19 ) ||
( V_1 -> V_35 != V_20 ) ) ) {
F_9 ( L_7 ) ;
return - V_29 ;
}
if ( V_13 -> V_27 [ 1 ] != V_13 -> V_27 [ 2 ] ) {
F_9 ( L_8 ) ;
return - V_29 ;
}
if ( V_13 -> V_27 [ 1 ] < 1 || V_13 -> V_27 [ 1 ] > 16384 ) {
F_9 ( L_9 ) ;
return - V_29 ;
}
if ( V_1 -> V_30 &&
( V_1 -> V_31 [ 1 ] != V_13 -> V_27 [ 1 ] ) ) {
F_9 ( L_10 ) ;
return - V_29 ;
}
V_1 -> V_34 = V_19 ;
V_1 -> V_35 = V_20 ;
V_1 -> V_31 [ 1 ] = V_13 -> V_27 [ 1 ] ;
F_10 ( V_1 -> V_36 . V_37 -> V_37 ,
L_11 ,
& V_17 [ 0 ] -> V_25 , & V_17 [ 1 ] -> V_25 ,
& V_17 [ 2 ] -> V_25 , V_14 , V_15 ) ;
break;
default:
F_10 ( V_1 -> V_36 . V_37 -> V_37 , L_12 ,
& V_17 [ 0 ] -> V_25 , V_14 , V_15 ) ;
break;
}
if ( V_1 -> V_30 ) {
V_21 = F_11 ( V_1 -> V_3 ) ;
F_12 ( V_1 -> V_3 , ! V_21 , V_18 ) ;
F_13 ( V_1 -> V_3 , ! V_21 ) ;
} else {
F_12 ( V_1 -> V_3 , 0 , V_18 ) ;
F_12 ( V_1 -> V_3 , 1 , V_18 ) ;
}
V_1 -> V_14 = V_14 ;
V_1 -> V_15 = V_15 ;
return 0 ;
}
int F_14 ( struct V_1 * V_1 , struct V_38 * V_39 ,
struct V_5 * V_6 ,
struct V_12 * V_13 , int V_40 , int V_41 ,
unsigned int V_42 , unsigned int V_43 ,
T_1 V_44 , T_1 V_45 ,
T_1 V_46 , T_1 V_47 , bool V_48 )
{
struct V_49 * V_37 = V_1 -> V_36 . V_37 -> V_37 ;
int V_50 ;
if ( V_46 != V_42 || V_47 != V_43 )
return - V_29 ;
if ( V_40 < 0 ) {
if ( - V_40 > V_42 )
return - V_29 ;
V_44 += - V_40 ;
V_46 -= - V_40 ;
V_42 -= - V_40 ;
V_40 = 0 ;
}
if ( V_41 < 0 ) {
if ( - V_41 > V_43 )
return - V_29 ;
V_45 += - V_41 ;
V_47 -= - V_41 ;
V_43 -= - V_41 ;
V_41 = 0 ;
}
if ( V_40 + V_42 > V_6 -> V_51 ) {
if ( V_40 > V_6 -> V_51 )
return - V_29 ;
V_42 = V_6 -> V_51 - V_40 ;
V_46 = V_42 ;
}
if ( V_41 + V_43 > V_6 -> V_52 ) {
if ( V_41 > V_6 -> V_52 )
return - V_29 ;
V_43 = V_6 -> V_52 - V_41 ;
V_47 = V_43 ;
}
if ( V_42 < 13 && ( V_1 -> V_53 != V_54 ) )
return - V_29 ;
if ( V_43 < 2 )
return - V_29 ;
if ( V_1 -> V_30 ) {
if ( V_46 != V_1 -> V_55 || V_47 != V_1 -> V_56 ||
V_13 -> V_23 != V_1 -> V_36 . V_13 -> V_23 )
return - V_29 ;
return F_6 ( V_1 , V_13 , V_44 , V_45 ) ;
}
switch ( V_1 -> V_53 ) {
case V_57 :
V_50 = F_15 ( V_1 -> V_58 ,
V_59 ,
V_59 ) ;
if ( V_50 ) {
F_16 ( V_37 ,
L_13 ,
V_50 ) ;
return V_50 ;
}
F_17 ( V_1 -> V_58 , true , 0 , true ) ;
break;
case V_54 :
F_15 ( V_1 -> V_58 ,
F_18 ( V_13 -> V_23 ) ,
V_60 ) ;
F_19 ( V_1 -> V_58 , V_40 , V_41 ) ;
switch ( V_13 -> V_23 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
F_17 ( V_1 -> V_58 , false , 0 , false ) ;
break;
default:
break;
}
}
V_50 = F_20 ( V_1 -> V_70 ,
F_5 ( V_42 , V_43 ,
F_3 ( V_6 ) ) , 64 ) ;
if ( V_50 ) {
F_16 ( V_37 , L_14 , V_50 ) ;
return V_50 ;
}
F_21 ( V_1 -> V_70 , V_42 ) ;
F_22 ( V_1 -> V_3 ) ;
F_23 ( V_1 -> V_3 , V_46 , V_47 ) ;
V_50 = F_24 ( V_1 -> V_3 , V_13 -> V_23 ) ;
if ( V_50 < 0 ) {
F_16 ( V_37 , L_15 ,
V_13 -> V_23 ) ;
return V_50 ;
}
F_25 ( V_1 -> V_3 ) ;
F_26 ( V_1 -> V_3 , 1 ) ;
F_27 ( V_1 -> V_3 , V_13 -> V_27 [ 0 ] ) ;
V_50 = F_6 ( V_1 , V_13 , V_44 , V_45 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_48 )
F_28 ( V_1 -> V_3 , V_13 -> V_27 [ 0 ] ) ;
if ( V_13 -> V_23 == V_32 ) {
F_29 ( V_1 -> V_3 ,
V_1 -> V_31 [ 1 ] ,
V_1 -> V_34 ,
V_1 -> V_35 ) ;
} else if ( V_13 -> V_23 == V_33 ) {
F_29 ( V_1 -> V_3 ,
V_1 -> V_31 [ 1 ] ,
V_1 -> V_35 ,
V_1 -> V_34 ) ;
}
V_1 -> V_55 = V_46 ;
V_1 -> V_56 = V_47 ;
return 0 ;
}
void F_30 ( struct V_1 * V_1 )
{
if ( ! F_31 ( V_1 -> V_58 ) )
F_32 ( V_1 -> V_58 ) ;
if ( ! F_31 ( V_1 -> V_70 ) )
F_33 ( V_1 -> V_70 ) ;
if ( ! F_31 ( V_1 -> V_3 ) )
F_34 ( V_1 -> V_3 ) ;
}
int F_35 ( struct V_1 * V_1 )
{
int V_50 ;
V_1 -> V_3 = F_36 ( V_1 -> V_2 , V_1 -> V_71 ) ;
if ( F_37 ( V_1 -> V_3 ) ) {
V_50 = F_38 ( V_1 -> V_3 ) ;
F_39 ( L_16 , V_50 ) ;
return V_50 ;
}
V_1 -> V_70 = F_40 ( V_1 -> V_2 , V_1 -> V_71 ) ;
if ( F_37 ( V_1 -> V_70 ) ) {
V_50 = F_38 ( V_1 -> V_70 ) ;
F_39 ( L_17 , V_50 ) ;
goto V_72;
}
if ( V_1 -> V_53 >= 0 ) {
V_1 -> V_58 = F_41 ( V_1 -> V_2 , V_1 -> V_53 ) ;
if ( F_37 ( V_1 -> V_58 ) ) {
V_50 = F_38 ( V_1 -> V_58 ) ;
F_39 ( L_18 , V_50 ) ;
goto V_72;
}
}
return 0 ;
V_72:
F_30 ( V_1 ) ;
return V_50 ;
}
void F_42 ( struct V_1 * V_1 )
{
if ( V_1 -> V_58 )
F_43 ( V_1 -> V_2 ) ;
F_44 ( V_1 -> V_70 ) ;
F_45 ( V_1 -> V_3 ) ;
if ( V_1 -> V_58 )
F_46 ( V_1 -> V_58 ) ;
V_1 -> V_30 = true ;
}
void F_47 ( struct V_1 * V_1 )
{
V_1 -> V_30 = false ;
F_48 ( V_1 -> V_3 , 50 ) ;
if ( V_1 -> V_58 )
F_49 ( V_1 -> V_58 ) ;
F_50 ( V_1 -> V_3 ) ;
F_51 ( V_1 -> V_70 ) ;
if ( V_1 -> V_58 )
F_52 ( V_1 -> V_2 ) ;
}
static int F_53 ( struct V_73 * V_74 , struct V_38 * V_39 ,
struct V_12 * V_13 , int V_40 , int V_41 ,
unsigned int V_42 , unsigned int V_43 ,
T_1 V_44 , T_1 V_45 ,
T_1 V_46 , T_1 V_47 )
{
struct V_1 * V_1 = F_54 ( V_74 ) ;
int V_50 = 0 ;
F_9 ( L_19 , V_74 ) ;
if ( ! V_1 -> V_30 )
V_50 = F_35 ( V_1 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_14 ( V_1 , V_39 , & V_39 -> V_75 , V_13 ,
V_40 , V_41 , V_42 , V_43 ,
V_44 >> 16 , V_45 >> 16 , V_46 >> 16 , V_47 >> 16 ,
false ) ;
if ( V_50 < 0 ) {
F_30 ( V_1 ) ;
return V_50 ;
}
if ( V_39 != V_74 -> V_39 )
F_10 ( V_74 -> V_37 -> V_37 , L_20 ,
V_74 -> V_39 , V_39 ) ;
if ( ! V_1 -> V_30 )
F_42 ( V_1 ) ;
return 0 ;
}
static int F_55 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_54 ( V_74 ) ;
F_9 ( L_21 , __LINE__ , V_76 ) ;
if ( V_1 -> V_30 )
F_47 ( V_1 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
static void F_56 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_54 ( V_74 ) ;
F_9 ( L_21 , __LINE__ , V_76 ) ;
F_55 ( V_74 ) ;
F_57 ( V_74 ) ;
F_58 ( V_1 ) ;
}
struct V_1 * F_59 ( struct V_77 * V_37 , struct V_78 * V_2 ,
int V_71 , int V_58 , unsigned int V_79 ,
enum V_80 type )
{
struct V_1 * V_1 ;
int V_50 ;
F_9 ( L_22 ,
V_71 , V_58 , V_79 ) ;
V_1 = F_60 ( sizeof( * V_1 ) , V_81 ) ;
if ( ! V_1 ) {
F_39 ( L_23 ) ;
return F_61 ( - V_82 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_71 = V_71 ;
V_1 -> V_53 = V_58 ;
V_50 = F_62 ( V_37 , & V_1 -> V_36 , V_79 ,
& V_83 , V_84 ,
F_63 ( V_84 ) , type ,
NULL ) ;
if ( V_50 ) {
F_39 ( L_24 ) ;
F_58 ( V_1 ) ;
return F_61 ( V_50 ) ;
}
return V_1 ;
}
