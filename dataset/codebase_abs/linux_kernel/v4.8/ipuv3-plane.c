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
static void F_10 ( struct V_1 * V_1 ,
struct V_8 * V_21 )
{
struct V_2 * V_22 = & V_1 -> V_4 ;
struct V_8 * V_9 = V_22 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_20 , V_23 , V_24 ;
int V_25 ;
V_20 = F_5 ( V_9 ) ;
switch ( V_11 -> V_26 ) {
case V_27 :
case V_28 :
if ( V_21 -> V_11 )
break;
V_23 = F_8 ( V_9 ) ;
V_24 = F_9 ( V_9 ) ;
if ( V_11 -> V_26 == V_27 )
F_11 ( V_1 -> V_6 ,
V_11 -> V_16 [ 1 ] , V_23 , V_24 ) ;
else
F_11 ( V_1 -> V_6 ,
V_11 -> V_16 [ 1 ] , V_24 , V_23 ) ;
F_12 ( V_1 -> V_4 . V_29 -> V_29 ,
L_1 , V_20 , V_23 , V_24 ,
V_9 -> V_19 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
default:
F_12 ( V_1 -> V_4 . V_29 -> V_29 , L_2 ,
V_20 , V_9 -> V_19 >> 16 , V_9 -> V_17 >> 16 ) ;
break;
}
if ( V_21 -> V_11 ) {
V_25 = F_13 ( V_1 -> V_6 ) ;
F_14 ( V_1 -> V_6 , ! V_25 , V_20 ) ;
F_15 ( V_1 -> V_6 , ! V_25 ) ;
} else {
F_14 ( V_1 -> V_6 , 0 , V_20 ) ;
F_14 ( V_1 -> V_6 , 1 , V_20 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
if ( ! F_17 ( V_1 -> V_30 ) )
F_18 ( V_1 -> V_30 ) ;
if ( ! F_17 ( V_1 -> V_31 ) )
F_19 ( V_1 -> V_31 ) ;
if ( ! F_17 ( V_1 -> V_6 ) )
F_20 ( V_1 -> V_6 ) ;
}
int F_21 ( struct V_1 * V_1 )
{
int V_32 ;
V_1 -> V_6 = F_22 ( V_1 -> V_5 , V_1 -> V_33 ) ;
if ( F_23 ( V_1 -> V_6 ) ) {
V_32 = F_24 ( V_1 -> V_6 ) ;
F_25 ( L_3 , V_32 ) ;
return V_32 ;
}
V_1 -> V_31 = F_26 ( V_1 -> V_5 , V_1 -> V_33 ) ;
if ( F_23 ( V_1 -> V_31 ) ) {
V_32 = F_24 ( V_1 -> V_31 ) ;
F_25 ( L_4 , V_32 ) ;
goto V_34;
}
if ( V_1 -> V_35 >= 0 ) {
V_1 -> V_30 = F_27 ( V_1 -> V_5 , V_1 -> V_35 ) ;
if ( F_23 ( V_1 -> V_30 ) ) {
V_32 = F_24 ( V_1 -> V_30 ) ;
F_25 ( L_5 , V_32 ) ;
goto V_34;
}
}
return 0 ;
V_34:
F_16 ( V_1 ) ;
return V_32 ;
}
static void F_28 ( struct V_1 * V_1 )
{
if ( V_1 -> V_30 )
F_29 ( V_1 -> V_5 ) ;
F_30 ( V_1 -> V_31 ) ;
F_31 ( V_1 -> V_6 ) ;
if ( V_1 -> V_30 )
F_32 ( V_1 -> V_30 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
F_34 ( V_1 -> V_6 , 50 ) ;
if ( V_1 -> V_30 )
F_35 ( V_1 -> V_30 ) ;
F_36 ( V_1 -> V_6 ) ;
F_37 ( V_1 -> V_31 ) ;
if ( V_1 -> V_30 )
F_38 ( V_1 -> V_5 ) ;
}
static int F_39 ( struct V_2 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_22 ) ;
F_40 ( L_6 , __LINE__ , V_36 ) ;
F_33 ( V_1 ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_22 ) ;
F_40 ( L_6 , __LINE__ , V_36 ) ;
F_39 ( V_22 ) ;
F_42 ( V_22 ) ;
F_43 ( V_1 ) ;
}
static int F_44 ( struct V_2 * V_22 ,
struct V_8 * V_9 )
{
struct V_8 * V_21 = V_22 -> V_9 ;
struct V_37 * V_38 ;
struct V_39 * V_29 = V_22 -> V_29 -> V_29 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_10 * V_40 = V_21 -> V_11 ;
unsigned long V_20 , V_23 , V_24 , V_41 , V_42 ;
if ( ! V_11 )
return 0 ;
if ( ! V_9 -> V_43 )
return - V_44 ;
V_38 =
F_45 ( V_9 -> V_9 , V_9 -> V_43 ) ;
if ( F_46 ( ! V_38 ) )
return - V_44 ;
if ( ! V_38 -> V_45 )
return - V_44 ;
if ( V_9 -> V_46 >> 16 != V_9 -> V_47 ||
V_9 -> V_48 >> 16 != V_9 -> V_49 )
return - V_44 ;
switch ( V_22 -> type ) {
case V_50 :
if ( V_9 -> V_51 || V_9 -> V_52 ||
V_9 -> V_47 != V_38 -> V_53 . V_54 ||
V_9 -> V_49 != V_38 -> V_53 . V_55 )
return - V_44 ;
if ( V_9 -> V_47 < 13 )
return - V_44 ;
break;
case V_56 :
if ( V_9 -> V_51 < 0 || V_9 -> V_52 < 0 )
return - V_44 ;
if ( V_9 -> V_51 + V_9 -> V_47 >
V_38 -> V_53 . V_54 )
return - V_44 ;
if ( V_9 -> V_52 + V_9 -> V_49 >
V_38 -> V_53 . V_55 )
return - V_44 ;
break;
default:
F_47 ( V_29 , L_7 ) ;
return - V_44 ;
}
if ( V_9 -> V_49 < 2 )
return - V_44 ;
if ( V_40 && ( V_9 -> V_46 != V_21 -> V_46 ||
V_9 -> V_48 != V_21 -> V_48 ||
V_11 -> V_26 != V_40 -> V_26 ) )
V_38 -> V_57 = true ;
V_20 = F_5 ( V_9 ) ;
if ( V_20 & 0x7 )
return - V_44 ;
if ( V_11 -> V_16 [ 0 ] < 1 || V_11 -> V_16 [ 0 ] > 16384 )
return - V_44 ;
if ( V_40 && V_11 -> V_16 [ 0 ] != V_40 -> V_16 [ 0 ] )
V_38 -> V_57 = true ;
switch ( V_11 -> V_26 ) {
case V_27 :
case V_28 :
V_23 = F_8 ( V_9 ) ;
V_24 = F_9 ( V_9 ) ;
if ( ( V_23 & 0x7 ) || ( V_24 & 0x7 ) )
return - V_44 ;
if ( ( V_23 > 0xfffff8 ) || ( V_24 > 0xfffff8 ) )
return - V_44 ;
if ( V_40 ) {
V_41 = F_8 ( V_21 ) ;
V_42 = F_9 ( V_21 ) ;
if ( V_23 != V_41 || V_24 != V_42 )
return - V_44 ;
}
if ( V_11 -> V_16 [ 1 ] != V_11 -> V_16 [ 2 ] )
return - V_44 ;
if ( V_11 -> V_16 [ 1 ] < 1 || V_11 -> V_16 [ 1 ] > 16384 )
return - V_44 ;
if ( V_40 && V_40 -> V_16 [ 1 ] != V_11 -> V_16 [ 1 ] )
V_38 -> V_57 = true ;
}
return 0 ;
}
static void F_48 ( struct V_2 * V_22 ,
struct V_8 * V_21 )
{
F_39 ( V_22 ) ;
}
static void F_49 ( struct V_2 * V_22 ,
struct V_8 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_22 ) ;
struct V_8 * V_9 = V_22 -> V_9 ;
enum V_58 V_59 ;
if ( V_21 -> V_11 ) {
struct V_37 * V_38 = V_9 -> V_43 -> V_9 ;
if ( ! V_38 -> V_57 ) {
F_10 ( V_1 , V_21 ) ;
return;
}
F_39 ( V_22 ) ;
}
switch ( V_1 -> V_35 ) {
case V_60 :
F_50 ( V_1 -> V_30 ,
V_61 ,
V_61 ) ;
F_51 ( V_1 -> V_30 , true , 0 , true ) ;
break;
case V_62 :
V_59 = F_52 ( V_9 -> V_11 -> V_26 ) ;
F_50 ( V_1 -> V_30 , V_59 ,
V_63 ) ;
F_53 ( V_1 -> V_30 , V_9 -> V_51 ,
V_9 -> V_52 ) ;
switch ( V_9 -> V_11 -> V_26 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
F_51 ( V_1 -> V_30 , false , 0 , false ) ;
break;
default:
break;
}
}
F_54 ( V_1 -> V_31 , V_9 -> V_47 ) ;
F_55 ( V_1 -> V_6 ) ;
F_56 ( V_1 -> V_6 , V_9 -> V_46 >> 16 ,
V_9 -> V_48 >> 16 ) ;
F_57 ( V_1 -> V_6 , V_9 -> V_11 -> V_26 ) ;
F_58 ( V_1 -> V_6 ) ;
F_59 ( V_1 -> V_6 , 1 ) ;
F_60 ( V_1 -> V_6 , V_9 -> V_11 -> V_16 [ 0 ] ) ;
F_10 ( V_1 , V_21 ) ;
F_28 ( V_1 ) ;
}
struct V_1 * F_61 ( struct V_73 * V_29 , struct V_74 * V_5 ,
int V_33 , int V_30 , unsigned int V_75 ,
enum V_76 type )
{
struct V_1 * V_1 ;
int V_32 ;
F_40 ( L_8 ,
V_33 , V_30 , V_75 ) ;
V_1 = F_62 ( sizeof( * V_1 ) , V_77 ) ;
if ( ! V_1 ) {
F_25 ( L_9 ) ;
return F_63 ( - V_78 ) ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_33 = V_33 ;
V_1 -> V_35 = V_30 ;
V_32 = F_64 ( V_29 , & V_1 -> V_4 , V_75 ,
& V_79 , V_80 ,
F_65 ( V_80 ) , type ,
NULL ) ;
if ( V_32 ) {
F_25 ( L_10 ) ;
F_43 ( V_1 ) ;
return F_63 ( V_32 ) ;
}
F_66 ( & V_1 -> V_4 , & V_81 ) ;
return V_1 ;
}
