static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 , int V_7 , int V_8 , int V_9 , int V_10 )
{
struct V_11 V_12 ;
V_12 . V_6 = V_6 ;
V_12 . V_5 = V_5 ;
V_12 . V_8 = V_8 ;
V_12 . V_7 = V_7 ;
V_12 . V_9 = V_9 ;
V_12 . V_10 = V_10 ;
V_4 -> V_13 -> V_14 ( V_4 , & V_12 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 , int V_9 , int V_10 )
{
struct V_15 V_16 ;
int V_17 = ( V_2 -> V_18 ) ? 13 : 12 ;
int V_19 = ( V_2 -> V_18 ) ? 9 : 8 ;
V_16 . V_20 = V_2 -> V_21 &
( ( V_2 -> V_18 ) ? 0x1ff : 0xff ) ;
V_16 . V_22 = F_3 ( V_19 , V_2 , V_4 ) ;
V_16 . V_23 = F_4 ( V_17 , V_2 , V_4 ) ;
V_16 . V_6 = V_6 ;
V_16 . V_5 = V_5 ;
V_16 . V_10 = V_10 ;
V_16 . V_9 = V_9 ;
V_16 . V_24 = V_25 ;
V_4 -> V_13 -> V_26 ( V_4 , & V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned short * V_27 , int V_28 , int V_29 , int V_30 ,
int V_22 , int V_23 )
{
struct V_31 V_32 ;
unsigned short V_33 = V_2 -> V_18 ? 0x1ff : 0xff ;
int V_34 = sizeof( V_35 ) * V_28 , V_36 ;
V_32 . V_6 = V_30 ;
V_32 . V_5 = V_29 ;
V_32 . V_10 = V_28 ;
V_32 . V_9 = 1 ;
V_32 . V_22 = V_22 ;
V_32 . V_23 = V_23 ;
V_32 . V_37 = V_28 ;
V_32 . V_38 = ( V_35 * ) F_6 ( V_4 , & V_4 -> V_39 , V_34 ) ;
for ( V_36 = 0 ; V_36 < V_28 ; V_36 ++ )
V_32 . V_38 [ V_36 ] = ( V_35 ) ( F_7 ( V_27 ++ ) & V_33 ) ;
V_4 -> V_13 -> V_31 ( V_4 , & V_32 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_40 )
{
return;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_41 ,
int V_42 , int V_22 , int V_23 )
{
struct V_43 V_44 ;
int V_45 = ( V_2 -> V_46 & 0x10 ) ;
V_44 . V_6 = V_2 -> V_47 ;
V_44 . V_5 = V_2 -> V_48 ;
V_44 . V_41 = ( V_41 == V_49 || V_45 ) ? 0 : 1 ;
V_44 . V_22 = V_22 ;
V_44 . V_23 = V_23 ;
switch ( V_2 -> V_46 & 0x0f ) {
case V_50 :
V_44 . V_51 = V_52 ;
break;
case V_53 :
V_44 . V_51 = V_54 ;
break;
case V_55 :
V_44 . V_51 = V_56 ;
break;
case V_57 :
V_44 . V_51 = V_58 ;
break;
case V_59 :
V_44 . V_51 = V_60 ;
break;
case V_61 :
default:
V_44 . V_51 = V_62 ;
break;
}
V_4 -> V_13 -> V_43 ( V_4 , & V_44 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_63 * V_64 = V_4 -> V_65 ;
int V_66 ;
V_66 = F_11 ( V_4 , & V_64 -> V_67 ) ;
V_64 -> V_67 . V_68 = V_4 -> V_67 . V_68 ;
V_64 -> V_67 . V_69 = V_4 -> V_67 . V_69 ;
V_64 -> V_67 . V_70 = V_4 -> V_67 . V_70 ;
return V_66 ;
}
void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_71 V_72 ;
struct V_63 * V_64 = V_4 -> V_65 ;
V_64 -> V_73 = F_1 ;
V_64 -> V_74 = F_2 ;
V_64 -> V_75 = F_5 ;
V_64 -> V_76 = F_8 ;
V_64 -> V_44 = F_9 ;
V_64 -> V_77 = F_10 ;
if ( V_64 -> V_78 ) {
V_72 . V_10 = V_2 -> V_79 . V_10 ;
V_72 . V_9 = V_2 -> V_79 . V_9 ;
V_72 . V_80 = 1 ;
V_72 . V_37 = ( V_64 -> V_78 -> V_81 ) ?
F_13 ( V_64 -> V_78 -> V_82 ) : 256 ;
V_72 . V_83 = V_64 -> V_78 -> V_82 ;
V_4 -> V_13 -> V_84 ( V_4 , & V_72 ) ;
}
}
