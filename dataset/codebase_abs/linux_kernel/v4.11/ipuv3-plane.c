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
V_11 -> V_21 -> V_22 [ 0 ] * V_14 ;
}
static inline unsigned long
F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_23 = F_5 ( V_9 ) ;
int V_14 = V_9 -> V_15 >> 16 ;
int V_16 = V_9 -> V_17 >> 16 ;
V_13 = F_6 ( V_11 , 1 ) ;
F_7 ( ! V_13 ) ;
V_14 /= F_9 ( V_11 -> V_21 -> V_21 ) ;
V_16 /= F_10 ( V_11 -> V_21 -> V_21 ) ;
return V_13 -> V_18 + V_11 -> V_19 [ 1 ] + V_11 -> V_20 [ 1 ] * V_16 +
V_11 -> V_21 -> V_22 [ 1 ] * V_14 - V_23 ;
}
static inline unsigned long
F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
unsigned long V_23 = F_5 ( V_9 ) ;
int V_14 = V_9 -> V_15 >> 16 ;
int V_16 = V_9 -> V_17 >> 16 ;
V_13 = F_6 ( V_11 , 2 ) ;
F_7 ( ! V_13 ) ;
V_14 /= F_9 ( V_11 -> V_21 -> V_21 ) ;
V_16 /= F_10 ( V_11 -> V_21 -> V_21 ) ;
return V_13 -> V_18 + V_11 -> V_19 [ 2 ] + V_11 -> V_20 [ 2 ] * V_16 +
V_11 -> V_21 -> V_22 [ 2 ] * V_14 - V_23 ;
}
void F_12 ( struct V_1 * V_1 )
{
if ( ! F_13 ( V_1 -> V_24 ) )
F_14 ( V_1 -> V_24 ) ;
if ( ! F_13 ( V_1 -> V_25 ) )
F_15 ( V_1 -> V_25 ) ;
if ( ! F_13 ( V_1 -> V_6 ) )
F_16 ( V_1 -> V_6 ) ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_26 ;
V_1 -> V_6 = F_18 ( V_1 -> V_5 , V_1 -> V_27 ) ;
if ( F_19 ( V_1 -> V_6 ) ) {
V_26 = F_20 ( V_1 -> V_6 ) ;
F_21 ( L_1 , V_26 ) ;
return V_26 ;
}
V_1 -> V_25 = F_22 ( V_1 -> V_5 , V_1 -> V_27 ) ;
if ( F_19 ( V_1 -> V_25 ) ) {
V_26 = F_20 ( V_1 -> V_25 ) ;
F_21 ( L_2 , V_26 ) ;
goto V_28;
}
if ( V_1 -> V_29 >= 0 ) {
V_1 -> V_24 = F_23 ( V_1 -> V_5 , V_1 -> V_29 ) ;
if ( F_19 ( V_1 -> V_24 ) ) {
V_26 = F_20 ( V_1 -> V_24 ) ;
F_21 ( L_3 , V_26 ) ;
goto V_28;
}
}
return 0 ;
V_28:
F_12 ( V_1 ) ;
return V_26 ;
}
static void F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_24 )
F_25 ( V_1 -> V_5 ) ;
F_26 ( V_1 -> V_25 ) ;
F_27 ( V_1 -> V_6 ) ;
if ( V_1 -> V_24 )
F_28 ( V_1 -> V_24 ) ;
}
static int F_29 ( struct V_2 * V_30 )
{
struct V_1 * V_1 = F_1 ( V_30 ) ;
F_30 ( L_4 , __LINE__ , V_31 ) ;
F_31 ( V_1 -> V_6 , 50 ) ;
if ( V_1 -> V_24 )
F_32 ( V_1 -> V_24 ) ;
F_33 ( V_1 -> V_6 ) ;
F_34 ( V_1 -> V_25 ) ;
if ( V_1 -> V_24 )
F_35 ( V_1 -> V_5 ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_30 )
{
struct V_1 * V_1 = F_1 ( V_30 ) ;
F_30 ( L_4 , __LINE__ , V_31 ) ;
F_37 ( V_30 ) ;
F_38 ( V_1 ) ;
}
static int F_39 ( struct V_2 * V_30 ,
struct V_8 * V_9 )
{
struct V_8 * V_32 = V_30 -> V_9 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = V_30 -> V_36 -> V_36 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_10 * V_37 = V_32 -> V_11 ;
unsigned long V_23 , V_38 , V_39 , V_40 , V_41 ;
int V_42 , V_43 ;
if ( ! V_11 )
return 0 ;
if ( ! V_9 -> V_44 )
return - V_45 ;
V_34 =
F_40 ( V_9 -> V_9 , V_9 -> V_44 ) ;
if ( F_41 ( ! V_34 ) )
return - V_45 ;
if ( ! V_34 -> V_46 )
return - V_45 ;
if ( V_9 -> V_47 >> 16 != V_9 -> V_48 ||
V_9 -> V_49 >> 16 != V_9 -> V_50 )
return - V_45 ;
switch ( V_30 -> type ) {
case V_51 :
if ( V_9 -> V_52 || V_9 -> V_53 ||
V_9 -> V_48 != V_34 -> V_54 . V_55 ||
V_9 -> V_50 != V_34 -> V_54 . V_56 )
return - V_45 ;
if ( V_9 -> V_48 < 13 )
return - V_45 ;
break;
case V_57 :
if ( V_9 -> V_52 < 0 || V_9 -> V_53 < 0 )
return - V_45 ;
if ( V_9 -> V_52 + V_9 -> V_48 >
V_34 -> V_54 . V_55 )
return - V_45 ;
if ( V_9 -> V_53 + V_9 -> V_50 >
V_34 -> V_54 . V_56 )
return - V_45 ;
break;
default:
F_42 ( V_36 , L_5 ) ;
return - V_45 ;
}
if ( V_9 -> V_50 < 2 )
return - V_45 ;
if ( V_37 && ( V_9 -> V_47 != V_32 -> V_47 ||
V_9 -> V_49 != V_32 -> V_49 ||
V_11 -> V_21 != V_37 -> V_21 ) )
V_34 -> V_58 = true ;
V_23 = F_5 ( V_9 ) ;
if ( V_23 & 0x7 )
return - V_45 ;
if ( V_11 -> V_20 [ 0 ] < 1 || V_11 -> V_20 [ 0 ] > 16384 )
return - V_45 ;
if ( V_37 && V_11 -> V_20 [ 0 ] != V_37 -> V_20 [ 0 ] )
V_34 -> V_58 = true ;
switch ( V_11 -> V_21 -> V_21 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_39 = F_11 ( V_9 ) ;
if ( V_39 & 0x7 || V_39 > 0xfffff8 )
return - V_45 ;
if ( V_37 && ( V_11 -> V_21 == V_37 -> V_21 ) ) {
V_41 = F_11 ( V_32 ) ;
if ( V_39 != V_41 )
V_34 -> V_58 = true ;
}
if ( V_11 -> V_20 [ 1 ] != V_11 -> V_20 [ 2 ] )
return - V_45 ;
case V_65 :
case V_66 :
V_38 = F_8 ( V_9 ) ;
if ( V_38 & 0x7 || V_38 > 0xfffff8 )
return - V_45 ;
if ( V_37 && ( V_11 -> V_21 == V_37 -> V_21 ) ) {
V_40 = F_8 ( V_32 ) ;
if ( V_38 != V_40 )
V_34 -> V_58 = true ;
}
if ( V_11 -> V_20 [ 1 ] < 1 || V_11 -> V_20 [ 1 ] > 16384 )
return - V_45 ;
if ( V_37 && V_37 -> V_20 [ 1 ] != V_11 -> V_20 [ 1 ] )
V_34 -> V_58 = true ;
V_42 = F_9 ( V_11 -> V_21 -> V_21 ) ;
V_43 = F_10 ( V_11 -> V_21 -> V_21 ) ;
if ( ( ( V_9 -> V_15 >> 16 ) & ( V_42 - 1 ) ) ||
( ( V_9 -> V_17 >> 16 ) & ( V_43 - 1 ) ) )
return - V_45 ;
}
return 0 ;
}
static void F_43 ( struct V_2 * V_30 ,
struct V_8 * V_32 )
{
F_29 ( V_30 ) ;
}
static void F_44 ( struct V_2 * V_30 ,
struct V_8 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_30 ) ;
struct V_8 * V_9 = V_30 -> V_9 ;
struct V_33 * V_34 = V_9 -> V_44 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_23 , V_38 , V_39 ;
enum V_67 V_68 ;
int V_69 ;
V_23 = F_5 ( V_9 ) ;
if ( V_32 -> V_11 && ! F_45 ( V_34 ) ) {
V_69 = F_46 ( V_1 -> V_6 ) ;
F_47 ( V_1 -> V_6 , ! V_69 , V_23 ) ;
F_48 ( V_1 -> V_6 , ! V_69 ) ;
return;
}
switch ( V_1 -> V_29 ) {
case V_70 :
F_49 ( V_1 -> V_24 ,
V_71 ,
V_71 ) ;
F_50 ( V_1 -> V_24 , true , 0 , true ) ;
break;
case V_72 :
V_68 = F_51 ( V_9 -> V_11 -> V_21 -> V_21 ) ;
F_49 ( V_1 -> V_24 , V_68 ,
V_73 ) ;
F_52 ( V_1 -> V_24 , V_9 -> V_52 ,
V_9 -> V_53 ) ;
switch ( V_9 -> V_11 -> V_21 -> V_21 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
F_50 ( V_1 -> V_24 , false , 0 , false ) ;
break;
default:
F_50 ( V_1 -> V_24 , true , 0 , true ) ;
break;
}
}
F_53 ( V_1 -> V_25 , V_9 -> V_48 ) ;
F_54 ( V_1 -> V_6 ) ;
F_55 ( V_1 -> V_6 , V_9 -> V_47 >> 16 ,
V_9 -> V_49 >> 16 ) ;
F_56 ( V_1 -> V_6 , V_9 -> V_11 -> V_21 -> V_21 ) ;
F_57 ( V_1 -> V_6 ) ;
F_58 ( V_1 -> V_6 , 1 ) ;
F_59 ( V_1 -> V_6 , V_9 -> V_11 -> V_20 [ 0 ] ) ;
switch ( V_11 -> V_21 -> V_21 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_38 = F_8 ( V_9 ) ;
V_39 = F_11 ( V_9 ) ;
if ( V_11 -> V_21 -> V_21 == V_60 ||
V_11 -> V_21 -> V_21 == V_62 ||
V_11 -> V_21 -> V_21 == V_64 )
F_60 ( V_38 , V_39 ) ;
F_61 ( V_1 -> V_6 ,
V_11 -> V_20 [ 1 ] , V_38 , V_39 ) ;
F_62 ( V_1 -> V_4 . V_36 -> V_36 ,
L_6 , V_23 , V_38 , V_39 ,
V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
case V_65 :
case V_66 :
V_38 = F_8 ( V_9 ) ;
F_61 ( V_1 -> V_6 ,
V_11 -> V_20 [ 1 ] , V_38 , V_38 ) ;
F_62 ( V_1 -> V_4 . V_36 -> V_36 ,
L_7 , V_23 , V_38 ,
V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
default:
F_62 ( V_1 -> V_4 . V_36 -> V_36 , L_8 ,
V_23 , V_9 -> V_15 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
}
F_47 ( V_1 -> V_6 , 0 , V_23 ) ;
F_47 ( V_1 -> V_6 , 1 , V_23 ) ;
F_24 ( V_1 ) ;
}
struct V_1 * F_63 ( struct V_83 * V_36 , struct V_84 * V_5 ,
int V_27 , int V_24 , unsigned int V_85 ,
enum V_86 type )
{
struct V_1 * V_1 ;
int V_26 ;
F_30 ( L_9 ,
V_27 , V_24 , V_85 ) ;
V_1 = F_64 ( sizeof( * V_1 ) , V_87 ) ;
if ( ! V_1 ) {
F_21 ( L_10 ) ;
return F_65 ( - V_88 ) ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_29 = V_24 ;
V_26 = F_66 ( V_36 , & V_1 -> V_4 , V_85 ,
& V_89 , V_90 ,
F_67 ( V_90 ) , type ,
NULL ) ;
if ( V_26 ) {
F_21 ( L_11 ) ;
F_38 ( V_1 ) ;
return F_65 ( V_26 ) ;
}
F_68 ( & V_1 -> V_4 , & V_91 ) ;
return V_1 ;
}
