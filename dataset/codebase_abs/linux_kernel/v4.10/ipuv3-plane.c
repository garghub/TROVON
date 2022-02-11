static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
int F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_1 -> V_5 , V_1 -> V_6 ,
V_7 ) ;
}
static inline unsigned long
F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
int V_14 = V_9 -> V_15 >> 16 ;
int V_16 = V_9 -> V_17 >> 16 ;
V_13 = F_6 ( V_11 , 0 ) ;
F_7 ( ! V_13 ) ;
return V_13 -> V_18 + V_11 -> V_19 [ 0 ] + V_11 -> V_20 [ 0 ] * V_16 +
F_8 ( V_11 -> V_21 , 0 ) * V_14 ;
}
static inline unsigned long
F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_22 = F_5 ( V_9 ) ;
int V_14 = V_9 -> V_15 >> 16 ;
int V_16 = V_9 -> V_17 >> 16 ;
V_13 = F_6 ( V_11 , 1 ) ;
F_7 ( ! V_13 ) ;
V_14 /= F_10 ( V_11 -> V_21 ) ;
V_16 /= F_11 ( V_11 -> V_21 ) ;
return V_13 -> V_18 + V_11 -> V_19 [ 1 ] + V_11 -> V_20 [ 1 ] * V_16 +
F_8 ( V_11 -> V_21 , 1 ) * V_14 - V_22 ;
}
static inline unsigned long
F_12 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_22 = F_5 ( V_9 ) ;
int V_14 = V_9 -> V_15 >> 16 ;
int V_16 = V_9 -> V_17 >> 16 ;
V_13 = F_6 ( V_11 , 2 ) ;
F_7 ( ! V_13 ) ;
V_14 /= F_10 ( V_11 -> V_21 ) ;
V_16 /= F_11 ( V_11 -> V_21 ) ;
return V_13 -> V_18 + V_11 -> V_19 [ 2 ] + V_11 -> V_20 [ 2 ] * V_16 +
F_8 ( V_11 -> V_21 , 2 ) * V_14 - V_22 ;
}
void F_13 ( struct V_1 * V_1 )
{
if ( ! F_14 ( V_1 -> V_23 ) )
F_15 ( V_1 -> V_23 ) ;
if ( ! F_14 ( V_1 -> V_24 ) )
F_16 ( V_1 -> V_24 ) ;
if ( ! F_14 ( V_1 -> V_6 ) )
F_17 ( V_1 -> V_6 ) ;
}
int F_18 ( struct V_1 * V_1 )
{
int V_25 ;
V_1 -> V_6 = F_19 ( V_1 -> V_5 , V_1 -> V_26 ) ;
if ( F_20 ( V_1 -> V_6 ) ) {
V_25 = F_21 ( V_1 -> V_6 ) ;
F_22 ( L_1 , V_25 ) ;
return V_25 ;
}
V_1 -> V_24 = F_23 ( V_1 -> V_5 , V_1 -> V_26 ) ;
if ( F_20 ( V_1 -> V_24 ) ) {
V_25 = F_21 ( V_1 -> V_24 ) ;
F_22 ( L_2 , V_25 ) ;
goto V_27;
}
if ( V_1 -> V_28 >= 0 ) {
V_1 -> V_23 = F_24 ( V_1 -> V_5 , V_1 -> V_28 ) ;
if ( F_20 ( V_1 -> V_23 ) ) {
V_25 = F_21 ( V_1 -> V_23 ) ;
F_22 ( L_3 , V_25 ) ;
goto V_27;
}
}
return 0 ;
V_27:
F_13 ( V_1 ) ;
return V_25 ;
}
static void F_25 ( struct V_1 * V_1 )
{
if ( V_1 -> V_23 )
F_26 ( V_1 -> V_5 ) ;
F_27 ( V_1 -> V_24 ) ;
F_28 ( V_1 -> V_6 ) ;
if ( V_1 -> V_23 )
F_29 ( V_1 -> V_23 ) ;
}
static int F_30 ( struct V_2 * V_29 )
{
struct V_1 * V_1 = F_1 ( V_29 ) ;
F_31 ( L_4 , __LINE__ , V_30 ) ;
F_32 ( V_1 -> V_6 , 50 ) ;
if ( V_1 -> V_23 )
F_33 ( V_1 -> V_23 ) ;
F_34 ( V_1 -> V_6 ) ;
F_35 ( V_1 -> V_24 ) ;
if ( V_1 -> V_23 )
F_36 ( V_1 -> V_5 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_29 )
{
struct V_1 * V_1 = F_1 ( V_29 ) ;
F_31 ( L_4 , __LINE__ , V_30 ) ;
F_38 ( V_29 ) ;
F_39 ( V_1 ) ;
}
static int F_40 ( struct V_2 * V_29 ,
struct V_8 * V_9 )
{
struct V_8 * V_31 = V_29 -> V_9 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = V_29 -> V_35 -> V_35 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_10 * V_36 = V_31 -> V_11 ;
unsigned long V_22 , V_37 , V_38 , V_39 , V_40 ;
int V_41 , V_42 ;
if ( ! V_11 )
return 0 ;
if ( ! V_9 -> V_43 )
return - V_44 ;
V_33 =
F_41 ( V_9 -> V_9 , V_9 -> V_43 ) ;
if ( F_42 ( ! V_33 ) )
return - V_44 ;
if ( ! V_33 -> V_45 )
return - V_44 ;
if ( V_9 -> V_46 >> 16 != V_9 -> V_47 ||
V_9 -> V_48 >> 16 != V_9 -> V_49 )
return - V_44 ;
switch ( V_29 -> type ) {
case V_50 :
if ( V_9 -> V_51 || V_9 -> V_52 ||
V_9 -> V_47 != V_33 -> V_53 . V_54 ||
V_9 -> V_49 != V_33 -> V_53 . V_55 )
return - V_44 ;
if ( V_9 -> V_47 < 13 )
return - V_44 ;
break;
case V_56 :
if ( V_9 -> V_51 < 0 || V_9 -> V_52 < 0 )
return - V_44 ;
if ( V_9 -> V_51 + V_9 -> V_47 >
V_33 -> V_53 . V_54 )
return - V_44 ;
if ( V_9 -> V_52 + V_9 -> V_49 >
V_33 -> V_53 . V_55 )
return - V_44 ;
break;
default:
F_43 ( V_35 , L_5 ) ;
return - V_44 ;
}
if ( V_9 -> V_49 < 2 )
return - V_44 ;
if ( V_36 && ( V_9 -> V_46 != V_31 -> V_46 ||
V_9 -> V_48 != V_31 -> V_48 ||
V_11 -> V_21 != V_36 -> V_21 ) )
V_33 -> V_57 = true ;
V_22 = F_5 ( V_9 ) ;
if ( V_22 & 0x7 )
return - V_44 ;
if ( V_11 -> V_20 [ 0 ] < 1 || V_11 -> V_20 [ 0 ] > 16384 )
return - V_44 ;
if ( V_36 && V_11 -> V_20 [ 0 ] != V_36 -> V_20 [ 0 ] )
V_33 -> V_57 = true ;
switch ( V_11 -> V_21 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_38 = F_12 ( V_9 ) ;
if ( V_38 & 0x7 || V_38 > 0xfffff8 )
return - V_44 ;
if ( V_36 && ( V_11 -> V_21 == V_36 -> V_21 ) ) {
V_40 = F_12 ( V_31 ) ;
if ( V_38 != V_40 )
V_33 -> V_57 = true ;
}
if ( V_11 -> V_20 [ 1 ] != V_11 -> V_20 [ 2 ] )
return - V_44 ;
case V_64 :
case V_65 :
V_37 = F_9 ( V_9 ) ;
if ( V_37 & 0x7 || V_37 > 0xfffff8 )
return - V_44 ;
if ( V_36 && ( V_11 -> V_21 == V_36 -> V_21 ) ) {
V_39 = F_9 ( V_31 ) ;
if ( V_37 != V_39 )
V_33 -> V_57 = true ;
}
if ( V_11 -> V_20 [ 1 ] < 1 || V_11 -> V_20 [ 1 ] > 16384 )
return - V_44 ;
if ( V_36 && V_36 -> V_20 [ 1 ] != V_11 -> V_20 [ 1 ] )
V_33 -> V_57 = true ;
V_41 = F_10 ( V_11 -> V_21 ) ;
V_42 = F_11 ( V_11 -> V_21 ) ;
if ( ( ( V_9 -> V_15 >> 16 ) & ( V_41 - 1 ) ) ||
( ( V_9 -> V_17 >> 16 ) & ( V_42 - 1 ) ) )
return - V_44 ;
}
return 0 ;
}
static void F_44 ( struct V_2 * V_29 ,
struct V_8 * V_31 )
{
F_30 ( V_29 ) ;
}
static void F_45 ( struct V_2 * V_29 ,
struct V_8 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_29 ) ;
struct V_8 * V_9 = V_29 -> V_9 ;
struct V_32 * V_33 = V_9 -> V_43 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_22 , V_37 , V_38 ;
enum V_66 V_67 ;
int V_68 ;
V_22 = F_5 ( V_9 ) ;
if ( V_31 -> V_11 && ! F_46 ( V_33 ) ) {
V_68 = F_47 ( V_1 -> V_6 ) ;
F_48 ( V_1 -> V_6 , ! V_68 , V_22 ) ;
F_49 ( V_1 -> V_6 , ! V_68 ) ;
return;
}
switch ( V_1 -> V_28 ) {
case V_69 :
F_50 ( V_1 -> V_23 ,
V_70 ,
V_70 ) ;
F_51 ( V_1 -> V_23 , true , 0 , true ) ;
break;
case V_71 :
V_67 = F_52 ( V_9 -> V_11 -> V_21 ) ;
F_50 ( V_1 -> V_23 , V_67 ,
V_72 ) ;
F_53 ( V_1 -> V_23 , V_9 -> V_51 ,
V_9 -> V_52 ) ;
switch ( V_9 -> V_11 -> V_21 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
F_51 ( V_1 -> V_23 , false , 0 , false ) ;
break;
default:
F_51 ( V_1 -> V_23 , true , 0 , true ) ;
break;
}
}
F_54 ( V_1 -> V_24 , V_9 -> V_47 ) ;
F_55 ( V_1 -> V_6 ) ;
F_56 ( V_1 -> V_6 , V_9 -> V_46 >> 16 ,
V_9 -> V_48 >> 16 ) ;
F_57 ( V_1 -> V_6 , V_9 -> V_11 -> V_21 ) ;
F_58 ( V_1 -> V_6 ) ;
F_59 ( V_1 -> V_6 , 1 ) ;
F_60 ( V_1 -> V_6 , V_9 -> V_11 -> V_20 [ 0 ] ) ;
switch ( V_11 -> V_21 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_37 = F_9 ( V_9 ) ;
V_38 = F_12 ( V_9 ) ;
if ( V_11 -> V_21 == V_59 ||
V_11 -> V_21 == V_61 ||
V_11 -> V_21 == V_63 )
F_61 ( V_37 , V_38 ) ;
F_62 ( V_1 -> V_6 ,
V_11 -> V_20 [ 1 ] , V_37 , V_38 ) ;
F_63 ( V_1 -> V_4 . V_35 -> V_35 ,
L_6 , V_22 , V_37 , V_38 ,
V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
case V_64 :
case V_65 :
V_37 = F_9 ( V_9 ) ;
F_62 ( V_1 -> V_6 ,
V_11 -> V_20 [ 1 ] , V_37 , V_37 ) ;
F_63 ( V_1 -> V_4 . V_35 -> V_35 ,
L_7 , V_22 , V_37 ,
V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
default:
F_63 ( V_1 -> V_4 . V_35 -> V_35 , L_8 ,
V_22 , V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
}
F_48 ( V_1 -> V_6 , 0 , V_22 ) ;
F_48 ( V_1 -> V_6 , 1 , V_22 ) ;
F_25 ( V_1 ) ;
}
struct V_1 * F_64 ( struct V_82 * V_35 , struct V_83 * V_5 ,
int V_26 , int V_23 , unsigned int V_84 ,
enum V_85 type )
{
struct V_1 * V_1 ;
int V_25 ;
F_31 ( L_9 ,
V_26 , V_23 , V_84 ) ;
V_1 = F_65 ( sizeof( * V_1 ) , V_86 ) ;
if ( ! V_1 ) {
F_22 ( L_10 ) ;
return F_66 ( - V_87 ) ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_26 = V_26 ;
V_1 -> V_28 = V_23 ;
V_25 = F_67 ( V_35 , & V_1 -> V_4 , V_84 ,
& V_88 , V_89 ,
F_68 ( V_89 ) , type ,
NULL ) ;
if ( V_25 ) {
F_22 ( L_11 ) ;
F_39 ( V_1 ) ;
return F_66 ( V_25 ) ;
}
F_69 ( & V_1 -> V_4 , & V_90 ) ;
return V_1 ;
}
