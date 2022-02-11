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
return F_8 ( V_16 -> V_18 . V_19 . V_21 , V_13 , V_14 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
struct V_15 * V_16 = F_5 ( V_5 -> V_23 . V_12 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned int V_24 ;
T_2 V_25 ;
int V_3 ;
if ( ! V_16 -> V_18 . V_19 . V_14 )
return - V_26 ;
if ( V_5 -> V_27 & ( V_10 - 1 ) )
return - V_26 ;
if ( ! V_5 -> V_8 )
return - V_26 ;
V_25 = V_28 ;
if ( V_5 -> V_27 <= V_29 [ 0 ] . V_30 ) {
for ( V_24 = 0 ; V_24 < F_10 ( V_29 ) ; V_24 ++ ) {
if ( ! ( V_5 -> V_27 & ( V_29 [ V_24 ] . V_30 - 1 ) ) ) {
V_25 = V_29 [ V_24 ] . V_31 ;
break;
}
}
}
if ( ( V_25 == V_28 ) ||
( V_16 -> V_18 . V_19 . V_14 != V_17 ) ) {
F_11 ( V_32 , V_16 -> V_18 . V_19 . V_21 ) ;
F_12 ( V_32 , V_16 -> V_18 . V_19 . V_21 ) ;
F_13 ( V_32 , V_5 -> V_23 . V_33 ,
NULL , NULL ) ;
F_14 ( V_32 , V_5 -> V_34 , V_5 -> V_35 ,
V_5 -> V_27 , V_5 -> V_8 ) ;
V_3 = V_22 ? F_15 ( V_32 ) :
F_16 ( V_32 ) ;
F_17 ( V_32 ) ;
return V_3 ;
}
memcpy ( V_7 -> V_9 , V_5 -> V_8 , V_10 ) ;
F_7 ( & V_7 -> V_36 , V_7 -> V_9 , V_10 ) ;
memset ( & V_7 -> V_37 , 0 , sizeof( V_7 -> V_37 ) ) ;
F_18 ( & V_7 -> V_37 . V_38 ) ;
V_7 -> V_37 . V_39 = V_40 ;
V_7 -> V_37 . V_18 . V_41 . V_42 = ( V_22 ) ? V_43
: V_44 ;
V_7 -> V_37 . V_18 . V_41 . V_25 = V_25 ;
V_7 -> V_37 . V_18 . V_41 . V_13 = & V_16 -> V_18 . V_19 . V_20 ;
V_7 -> V_37 . V_18 . V_41 . V_14 = V_16 -> V_18 . V_19 . V_14 ;
V_7 -> V_37 . V_18 . V_41 . V_9 = & V_7 -> V_36 ;
V_7 -> V_37 . V_18 . V_41 . V_45 = V_10 ;
V_7 -> V_37 . V_18 . V_41 . V_34 = V_5 -> V_34 ;
V_7 -> V_37 . V_18 . V_41 . V_46 = V_5 -> V_27 ;
V_7 -> V_37 . V_18 . V_41 . V_35 = V_5 -> V_35 ;
V_3 = F_19 ( & V_5 -> V_23 , & V_7 -> V_37 ) ;
return V_3 ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , 1 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , 0 ) ;
}
static int F_22 ( struct V_47 * V_12 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_48 * V_49 ;
V_16 -> V_50 = F_1 ;
V_16 -> V_18 . V_19 . V_14 = 0 ;
V_49 = F_23 ( L_1 , 0 ,
V_51 |
V_52 ) ;
if ( F_24 ( V_49 ) ) {
F_25 ( L_2 ) ;
return F_26 ( V_49 ) ;
}
V_16 -> V_18 . V_19 . V_21 = V_49 ;
V_12 -> V_53 . V_54 = sizeof( struct V_6 ) ;
return 0 ;
}
static void F_27 ( struct V_47 * V_12 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
F_28 ( V_16 -> V_18 . V_19 . V_21 ) ;
}
static int F_29 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_3 ;
V_60 = F_30 ( sizeof( * V_60 ) , V_63 ) ;
if ( ! V_60 )
return - V_64 ;
F_18 ( & V_60 -> V_38 ) ;
V_62 = & V_60 -> V_62 ;
snprintf ( V_62 -> V_65 , V_66 , L_3 , V_58 -> V_67 ) ;
snprintf ( V_62 -> V_68 , V_66 , L_3 ,
V_58 -> V_69 ) ;
V_62 -> V_70 = V_71 | V_51 |
V_72 |
V_52 ;
V_62 -> V_73 = V_10 ;
V_62 -> V_74 = sizeof( struct V_15 ) ;
V_62 -> V_75 = V_76 ;
V_62 -> V_77 = & V_78 ;
V_62 -> V_79 . V_80 = F_4 ;
V_62 -> V_79 . V_22 = F_20 ;
V_62 -> V_79 . V_81 = F_21 ;
V_62 -> V_79 . V_82 = V_83 * 2 ;
V_62 -> V_79 . V_84 = V_85 * 2 ;
V_62 -> V_79 . V_86 = V_10 ;
V_62 -> V_87 = F_22 ;
V_62 -> V_88 = F_27 ;
V_62 -> V_89 = V_90 ;
V_3 = F_31 ( V_62 ) ;
if ( V_3 ) {
F_32 ( L_4 ,
V_62 -> V_65 , V_3 ) ;
F_33 ( V_60 ) ;
return V_3 ;
}
F_34 ( & V_60 -> V_38 , V_56 ) ;
return 0 ;
}
int F_35 ( struct V_55 * V_56 )
{
int V_91 , V_3 ;
for ( V_91 = 0 ; V_91 < F_10 ( V_92 ) ; V_91 ++ ) {
V_3 = F_29 ( V_56 , & V_92 [ V_91 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
