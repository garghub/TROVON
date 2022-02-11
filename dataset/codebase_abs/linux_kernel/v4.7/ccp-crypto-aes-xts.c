static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_3 )
return V_3 ;
memcpy ( V_5 -> V_8 , V_7 -> V_9 , V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_11 * V_12 , const T_1 * V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 = F_5 ( F_6 ( V_12 ) ) ;
switch ( V_14 ) {
case V_17 * 2 :
memcpy ( V_16 -> V_18 . V_19 . V_13 , V_13 , V_14 ) ;
break;
}
V_16 -> V_18 . V_19 . V_14 = V_14 / 2 ;
F_7 ( & V_16 -> V_18 . V_19 . V_20 , V_16 -> V_18 . V_19 . V_13 , V_14 ) ;
return F_8 ( V_16 -> V_18 . V_19 . V_21 , V_13 ,
V_14 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
struct V_23 * V_12 =
F_6 ( F_10 ( V_5 ) ) ;
struct V_15 * V_16 = F_5 ( V_5 -> V_24 . V_12 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned int V_25 ;
T_2 V_26 ;
int V_3 ;
if ( ! V_16 -> V_18 . V_19 . V_14 )
return - V_27 ;
if ( V_5 -> V_28 & ( V_10 - 1 ) )
return - V_27 ;
if ( ! V_5 -> V_8 )
return - V_27 ;
V_26 = V_29 ;
if ( V_5 -> V_28 <= V_30 [ 0 ] . V_31 ) {
for ( V_25 = 0 ; V_25 < F_11 ( V_30 ) ; V_25 ++ ) {
if ( ! ( V_5 -> V_28 & ( V_30 [ V_25 ] . V_31 - 1 ) ) ) {
V_26 = V_30 [ V_25 ] . V_32 ;
break;
}
}
}
if ( ( V_26 == V_29 ) ||
( V_16 -> V_18 . V_19 . V_14 != V_17 ) ) {
F_12 ( V_5 , V_16 -> V_18 . V_19 . V_21 ) ;
V_3 = ( V_22 ) ? F_13 ( V_5 ) :
F_14 ( V_5 ) ;
F_12 ( V_5 , F_15 ( V_12 ) ) ;
return V_3 ;
}
memcpy ( V_7 -> V_9 , V_5 -> V_8 , V_10 ) ;
F_7 ( & V_7 -> V_33 , V_7 -> V_9 , V_10 ) ;
memset ( & V_7 -> V_34 , 0 , sizeof( V_7 -> V_34 ) ) ;
F_16 ( & V_7 -> V_34 . V_35 ) ;
V_7 -> V_34 . V_36 = V_37 ;
V_7 -> V_34 . V_18 . V_38 . V_39 = ( V_22 ) ? V_40
: V_41 ;
V_7 -> V_34 . V_18 . V_38 . V_26 = V_26 ;
V_7 -> V_34 . V_18 . V_38 . V_13 = & V_16 -> V_18 . V_19 . V_20 ;
V_7 -> V_34 . V_18 . V_38 . V_14 = V_16 -> V_18 . V_19 . V_14 ;
V_7 -> V_34 . V_18 . V_38 . V_9 = & V_7 -> V_33 ;
V_7 -> V_34 . V_18 . V_38 . V_42 = V_10 ;
V_7 -> V_34 . V_18 . V_38 . V_43 = V_5 -> V_43 ;
V_7 -> V_34 . V_18 . V_38 . V_44 = V_5 -> V_28 ;
V_7 -> V_34 . V_18 . V_38 . V_45 = V_5 -> V_45 ;
V_3 = F_17 ( & V_5 -> V_24 , & V_7 -> V_34 ) ;
return V_3 ;
}
static int F_18 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , 1 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , 0 ) ;
}
static int F_20 ( struct V_23 * V_12 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_11 * V_46 ;
V_16 -> V_47 = F_1 ;
V_16 -> V_18 . V_19 . V_14 = 0 ;
V_46 = F_21 ( F_22 ( V_12 ) , 0 ,
V_48 |
V_49 ) ;
if ( F_23 ( V_46 ) ) {
F_24 ( L_1 ,
F_22 ( V_12 ) ) ;
return F_25 ( V_46 ) ;
}
V_16 -> V_18 . V_19 . V_21 = V_46 ;
V_12 -> V_50 . V_51 = sizeof( struct V_6 ) +
V_46 -> V_24 . V_50 . V_51 ;
return 0 ;
}
static void F_26 ( struct V_23 * V_12 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
if ( V_16 -> V_18 . V_19 . V_21 )
F_27 ( V_16 -> V_18 . V_19 . V_21 ) ;
V_16 -> V_18 . V_19 . V_21 = NULL ;
}
static int F_28 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_3 ;
V_57 = F_29 ( sizeof( * V_57 ) , V_60 ) ;
if ( ! V_57 )
return - V_61 ;
F_16 ( & V_57 -> V_35 ) ;
V_59 = & V_57 -> V_59 ;
snprintf ( V_59 -> V_62 , V_63 , L_2 , V_55 -> V_64 ) ;
snprintf ( V_59 -> V_65 , V_63 , L_2 ,
V_55 -> V_66 ) ;
V_59 -> V_67 = V_68 | V_48 |
V_69 |
V_49 ;
V_59 -> V_70 = V_10 ;
V_59 -> V_71 = sizeof( struct V_15 ) ;
V_59 -> V_72 = V_73 ;
V_59 -> V_74 = & V_75 ;
V_59 -> V_76 . V_77 = F_4 ;
V_59 -> V_76 . V_22 = F_18 ;
V_59 -> V_76 . V_78 = F_19 ;
V_59 -> V_76 . V_79 = V_80 * 2 ;
V_59 -> V_76 . V_81 = V_82 * 2 ;
V_59 -> V_76 . V_83 = V_10 ;
V_59 -> V_84 = F_20 ;
V_59 -> V_85 = F_26 ;
V_59 -> V_86 = V_87 ;
V_3 = F_30 ( V_59 ) ;
if ( V_3 ) {
F_31 ( L_3 ,
V_59 -> V_62 , V_3 ) ;
F_32 ( V_57 ) ;
return V_3 ;
}
F_33 ( & V_57 -> V_35 , V_53 ) ;
return 0 ;
}
int F_34 ( struct V_52 * V_53 )
{
int V_88 , V_3 ;
for ( V_88 = 0 ; V_88 < F_11 ( V_89 ) ; V_88 ++ ) {
V_3 = F_28 ( V_53 , & V_89 [ V_88 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
