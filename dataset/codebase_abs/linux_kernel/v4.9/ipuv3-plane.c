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
V_13 = F_6 ( V_11 , 0 ) ;
F_7 ( ! V_13 ) ;
return V_13 -> V_14 + V_11 -> V_15 [ 0 ] +
V_11 -> V_16 [ 0 ] * ( V_9 -> V_17 >> 16 ) +
( V_11 -> V_18 >> 3 ) * ( V_9 -> V_19 >> 16 ) ;
}
static inline unsigned long
F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_20 = F_5 ( V_9 ) ;
V_13 = F_6 ( V_11 , 1 ) ;
F_7 ( ! V_13 ) ;
return V_13 -> V_14 + V_11 -> V_15 [ 1 ] +
V_11 -> V_16 [ 1 ] * ( V_9 -> V_17 >> 16 ) / 2 +
( V_9 -> V_19 >> 16 ) / 2 - V_20 ;
}
static inline unsigned long
F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_20 = F_5 ( V_9 ) ;
V_13 = F_6 ( V_11 , 2 ) ;
F_7 ( ! V_13 ) ;
return V_13 -> V_14 + V_11 -> V_15 [ 2 ] +
V_11 -> V_16 [ 2 ] * ( V_9 -> V_17 >> 16 ) / 2 +
( V_9 -> V_19 >> 16 ) / 2 - V_20 ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_2 * V_21 = & V_1 -> V_4 ;
struct V_8 * V_9 = V_21 -> V_9 ;
struct V_22 * V_23 = V_9 -> V_24 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_20 , V_25 , V_26 ;
int V_27 ;
V_20 = F_5 ( V_9 ) ;
switch ( V_11 -> V_28 ) {
case V_29 :
case V_30 :
if ( ! F_11 ( V_23 ) )
break;
V_25 = F_8 ( V_9 ) ;
V_26 = F_9 ( V_9 ) ;
if ( V_11 -> V_28 == V_29 )
F_12 ( V_1 -> V_6 ,
V_11 -> V_16 [ 1 ] , V_25 , V_26 ) ;
else
F_12 ( V_1 -> V_6 ,
V_11 -> V_16 [ 1 ] , V_26 , V_25 ) ;
F_13 ( V_1 -> V_4 . V_31 -> V_31 ,
L_1 , V_20 , V_25 , V_26 ,
V_9 -> V_19 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
default:
F_13 ( V_1 -> V_4 . V_31 -> V_31 , L_2 ,
V_20 , V_9 -> V_19 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
}
if ( ! F_11 ( V_23 ) ) {
V_27 = F_14 ( V_1 -> V_6 ) ;
F_15 ( V_1 -> V_6 , ! V_27 , V_20 ) ;
F_16 ( V_1 -> V_6 , ! V_27 ) ;
} else {
F_15 ( V_1 -> V_6 , 0 , V_20 ) ;
F_15 ( V_1 -> V_6 , 1 , V_20 ) ;
}
}
void F_17 ( struct V_1 * V_1 )
{
if ( ! F_18 ( V_1 -> V_32 ) )
F_19 ( V_1 -> V_32 ) ;
if ( ! F_18 ( V_1 -> V_33 ) )
F_20 ( V_1 -> V_33 ) ;
if ( ! F_18 ( V_1 -> V_6 ) )
F_21 ( V_1 -> V_6 ) ;
}
int F_22 ( struct V_1 * V_1 )
{
int V_34 ;
V_1 -> V_6 = F_23 ( V_1 -> V_5 , V_1 -> V_35 ) ;
if ( F_24 ( V_1 -> V_6 ) ) {
V_34 = F_25 ( V_1 -> V_6 ) ;
F_26 ( L_3 , V_34 ) ;
return V_34 ;
}
V_1 -> V_33 = F_27 ( V_1 -> V_5 , V_1 -> V_35 ) ;
if ( F_24 ( V_1 -> V_33 ) ) {
V_34 = F_25 ( V_1 -> V_33 ) ;
F_26 ( L_4 , V_34 ) ;
goto V_36;
}
if ( V_1 -> V_37 >= 0 ) {
V_1 -> V_32 = F_28 ( V_1 -> V_5 , V_1 -> V_37 ) ;
if ( F_24 ( V_1 -> V_32 ) ) {
V_34 = F_25 ( V_1 -> V_32 ) ;
F_26 ( L_5 , V_34 ) ;
goto V_36;
}
}
return 0 ;
V_36:
F_17 ( V_1 ) ;
return V_34 ;
}
static void F_29 ( struct V_1 * V_1 )
{
if ( V_1 -> V_32 )
F_30 ( V_1 -> V_5 ) ;
F_31 ( V_1 -> V_33 ) ;
F_32 ( V_1 -> V_6 ) ;
if ( V_1 -> V_32 )
F_33 ( V_1 -> V_32 ) ;
}
static int F_34 ( struct V_2 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_21 ) ;
F_35 ( L_6 , __LINE__ , V_38 ) ;
F_36 ( V_1 -> V_6 , 50 ) ;
if ( V_1 -> V_32 )
F_37 ( V_1 -> V_32 ) ;
F_38 ( V_1 -> V_6 ) ;
F_39 ( V_1 -> V_33 ) ;
if ( V_1 -> V_32 )
F_40 ( V_1 -> V_5 ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_21 ) ;
F_35 ( L_6 , __LINE__ , V_38 ) ;
F_42 ( V_21 ) ;
F_43 ( V_1 ) ;
}
static int F_44 ( struct V_2 * V_21 ,
struct V_8 * V_9 )
{
struct V_8 * V_39 = V_21 -> V_9 ;
struct V_22 * V_23 ;
struct V_40 * V_31 = V_21 -> V_31 -> V_31 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_10 * V_41 = V_39 -> V_11 ;
unsigned long V_20 , V_25 , V_26 , V_42 , V_43 ;
int V_44 , V_45 ;
if ( ! V_11 )
return 0 ;
if ( ! V_9 -> V_24 )
return - V_46 ;
V_23 =
F_45 ( V_9 -> V_9 , V_9 -> V_24 ) ;
if ( F_46 ( ! V_23 ) )
return - V_46 ;
if ( ! V_23 -> V_47 )
return - V_46 ;
if ( V_9 -> V_48 >> 16 != V_9 -> V_49 ||
V_9 -> V_50 >> 16 != V_9 -> V_51 )
return - V_46 ;
switch ( V_21 -> type ) {
case V_52 :
if ( V_9 -> V_53 || V_9 -> V_54 ||
V_9 -> V_49 != V_23 -> V_55 . V_56 ||
V_9 -> V_51 != V_23 -> V_55 . V_57 )
return - V_46 ;
if ( V_9 -> V_49 < 13 )
return - V_46 ;
break;
case V_58 :
if ( V_9 -> V_53 < 0 || V_9 -> V_54 < 0 )
return - V_46 ;
if ( V_9 -> V_53 + V_9 -> V_49 >
V_23 -> V_55 . V_56 )
return - V_46 ;
if ( V_9 -> V_54 + V_9 -> V_51 >
V_23 -> V_55 . V_57 )
return - V_46 ;
break;
default:
F_47 ( V_31 , L_7 ) ;
return - V_46 ;
}
if ( V_9 -> V_51 < 2 )
return - V_46 ;
if ( V_41 && ( V_9 -> V_48 != V_39 -> V_48 ||
V_9 -> V_50 != V_39 -> V_50 ||
V_11 -> V_28 != V_41 -> V_28 ) )
V_23 -> V_59 = true ;
V_20 = F_5 ( V_9 ) ;
if ( V_20 & 0x7 )
return - V_46 ;
if ( V_11 -> V_16 [ 0 ] < 1 || V_11 -> V_16 [ 0 ] > 16384 )
return - V_46 ;
if ( V_41 && V_11 -> V_16 [ 0 ] != V_41 -> V_16 [ 0 ] )
V_23 -> V_59 = true ;
switch ( V_11 -> V_28 ) {
case V_29 :
case V_30 :
V_25 = F_8 ( V_9 ) ;
V_26 = F_9 ( V_9 ) ;
if ( ( V_25 & 0x7 ) || ( V_26 & 0x7 ) )
return - V_46 ;
if ( ( V_25 > 0xfffff8 ) || ( V_26 > 0xfffff8 ) )
return - V_46 ;
if ( V_41 &&
( V_41 -> V_28 == V_29 ||
V_41 -> V_28 == V_30 ) ) {
V_42 = F_8 ( V_39 ) ;
V_43 = F_9 ( V_39 ) ;
if ( V_25 != V_42 || V_26 != V_43 )
return - V_46 ;
}
if ( V_11 -> V_16 [ 1 ] != V_11 -> V_16 [ 2 ] )
return - V_46 ;
if ( V_11 -> V_16 [ 1 ] < 1 || V_11 -> V_16 [ 1 ] > 16384 )
return - V_46 ;
if ( V_41 && V_41 -> V_16 [ 1 ] != V_11 -> V_16 [ 1 ] )
V_23 -> V_59 = true ;
V_44 = F_48 ( V_11 -> V_28 ) ;
V_45 = F_49 ( V_11 -> V_28 ) ;
if ( ( ( V_9 -> V_19 >> 16 ) & ( V_44 - 1 ) ) ||
( ( V_9 -> V_17 >> 16 ) & ( V_45 - 1 ) ) )
return - V_46 ;
}
return 0 ;
}
static void F_50 ( struct V_2 * V_21 ,
struct V_8 * V_39 )
{
F_34 ( V_21 ) ;
}
static void F_51 ( struct V_2 * V_21 ,
struct V_8 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_21 ) ;
struct V_8 * V_9 = V_21 -> V_9 ;
enum V_60 V_61 ;
if ( V_39 -> V_11 ) {
struct V_22 * V_23 = V_9 -> V_24 -> V_9 ;
if ( ! F_11 ( V_23 ) ) {
F_10 ( V_1 ) ;
return;
}
}
switch ( V_1 -> V_37 ) {
case V_62 :
F_52 ( V_1 -> V_32 ,
V_63 ,
V_63 ) ;
F_53 ( V_1 -> V_32 , true , 0 , true ) ;
break;
case V_64 :
V_61 = F_54 ( V_9 -> V_11 -> V_28 ) ;
F_52 ( V_1 -> V_32 , V_61 ,
V_65 ) ;
F_55 ( V_1 -> V_32 , V_9 -> V_53 ,
V_9 -> V_54 ) ;
switch ( V_9 -> V_11 -> V_28 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
F_53 ( V_1 -> V_32 , false , 0 , false ) ;
break;
default:
F_53 ( V_1 -> V_32 , true , 0 , true ) ;
break;
}
}
F_56 ( V_1 -> V_33 , V_9 -> V_49 ) ;
F_57 ( V_1 -> V_6 ) ;
F_58 ( V_1 -> V_6 , V_9 -> V_48 >> 16 ,
V_9 -> V_50 >> 16 ) ;
F_59 ( V_1 -> V_6 , V_9 -> V_11 -> V_28 ) ;
F_60 ( V_1 -> V_6 ) ;
F_61 ( V_1 -> V_6 , 1 ) ;
F_62 ( V_1 -> V_6 , V_9 -> V_11 -> V_16 [ 0 ] ) ;
F_10 ( V_1 ) ;
F_29 ( V_1 ) ;
}
struct V_1 * F_63 ( struct V_75 * V_31 , struct V_76 * V_5 ,
int V_35 , int V_32 , unsigned int V_77 ,
enum V_78 type )
{
struct V_1 * V_1 ;
int V_34 ;
F_35 ( L_8 ,
V_35 , V_32 , V_77 ) ;
V_1 = F_64 ( sizeof( * V_1 ) , V_79 ) ;
if ( ! V_1 ) {
F_26 ( L_9 ) ;
return F_65 ( - V_80 ) ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_35 = V_35 ;
V_1 -> V_37 = V_32 ;
V_34 = F_66 ( V_31 , & V_1 -> V_4 , V_77 ,
& V_81 , V_82 ,
F_67 ( V_82 ) , type ,
NULL ) ;
if ( V_34 ) {
F_26 ( L_10 ) ;
F_43 ( V_1 ) ;
return F_65 ( V_34 ) ;
}
F_68 ( & V_1 -> V_4 , & V_83 ) ;
return V_1 ;
}
