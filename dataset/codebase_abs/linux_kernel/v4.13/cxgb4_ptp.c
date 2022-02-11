bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_2 -> V_5 >= V_6 &&
V_2 -> V_5 <= V_7 &&
F_3 ( V_2 -> V_8 == F_4 ( V_9 ) ) &&
F_5 ( V_2 ) -> V_8 == V_10 &&
V_4 -> V_11 == F_4 ( V_12 ) ;
}
bool F_6 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_7 ( V_14 ) ;
return ( V_16 -> V_17 && F_8 ( V_2 ) &&
F_1 ( V_2 ) ) ;
}
bool F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_18 + V_19 +
F_10 ( V_2 -> V_18 ) ) ;
return V_4 -> V_11 == F_4 ( V_12 ) &&
V_4 -> V_20 == F_4 ( V_12 ) ;
}
void F_11 ( struct V_21 * V_21 , struct V_15 * V_16 )
{
struct V_22 * V_23 = NULL ;
T_1 V_24 ;
V_23 = F_12 ( V_21 -> V_25 ) ;
V_24 = F_13 ( V_21 ,
F_14 ( V_16 -> V_26 , V_27 ) ) ;
V_24 |= ( T_1 ) F_13 ( V_21 ,
F_14 ( V_16 -> V_26 ,
V_28 ) ) << 32 ;
V_23 -> V_29 = F_15 ( V_24 ) ;
F_16 ( V_21 -> V_25 , V_23 ) ;
F_17 ( V_21 -> V_25 ) ;
F_18 ( & V_21 -> V_30 ) ;
V_21 -> V_25 = NULL ;
F_19 ( & V_21 -> V_30 ) ;
}
int F_20 ( struct V_15 * V_16 , T_2 V_31 , T_3 V_32 )
{
struct V_21 * V_21 = V_16 -> V_21 ;
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( V_31 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_42 . V_43 = V_44 ;
V_34 . V_41 . V_42 . V_32 = F_25 ( V_32 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
int F_28 ( struct V_21 * V_21 , T_2 V_31 )
{
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( V_31 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_42 . V_43 = V_48 ;
V_34 . V_41 . V_42 . V_32 = F_25 ( V_49 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
int F_29 ( struct V_21 * V_21 , struct V_15 * V_16 )
{
struct V_50 * V_51 = & V_21 -> V_50 ;
struct V_52 * V_53 = & V_51 -> V_54 [ V_16 -> V_55 ] ;
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( V_16 -> V_26 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_42 . V_43 = V_56 ;
V_34 . V_41 . V_42 . V_57 = V_16 -> V_58 ;
V_34 . V_41 . V_42 . V_59 = F_25 ( V_53 -> V_60 . V_61 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
static int F_30 ( struct V_62 * V_63 , T_4 V_64 )
{
struct V_21 * V_21 = (struct V_21 * ) F_31 ( V_63 ,
struct V_21 , V_62 ) ;
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_65 . V_43 = V_66 ;
V_34 . V_41 . V_65 . V_67 = ( V_64 < 0 ) ? 1 : 0 ;
if ( V_64 < 0 )
V_64 = - V_64 ;
V_34 . V_41 . V_65 . V_64 = F_21 ( V_64 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
static int F_32 ( struct V_21 * V_21 , T_5 V_68 )
{
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_65 . V_43 = V_69 ;
V_34 . V_41 . V_65 . V_70 = F_33 ( V_68 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
static int F_34 ( struct V_62 * V_63 , T_5 V_68 )
{
struct V_21 * V_21 =
(struct V_21 * ) F_31 ( V_63 , struct V_21 ,
V_62 ) ;
struct V_33 V_34 ;
T_5 V_67 = 1 ;
int V_35 ;
if ( V_68 < 0 )
V_67 = - 1 ;
if ( V_68 * V_67 > V_71 ) {
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_65 . V_43 = V_72 ;
V_34 . V_41 . V_65 . V_67 = ( V_68 < 0 ) ? 1 : 0 ;
if ( V_68 < 0 )
V_68 = - V_68 ;
V_34 . V_41 . V_65 . V_70 = F_33 ( V_68 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
} else {
V_35 = F_32 ( V_21 , V_68 ) ;
}
return V_35 ;
}
static int F_35 ( struct V_62 * V_63 , struct V_73 * V_65 )
{
struct V_21 * V_21 = (struct V_21 * ) F_31 ( V_63 ,
struct V_21 , V_62 ) ;
struct V_33 V_34 ;
T_1 V_74 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_75 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_65 . V_43 = V_76 ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , & V_34 ) ;
if ( V_35 < 0 ) {
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
V_74 = F_36 ( V_34 . V_41 . V_65 . V_70 ) ;
* V_65 = F_37 ( V_74 ) ;
return V_35 ;
}
static int F_38 ( struct V_62 * V_63 ,
const struct V_73 * V_65 )
{
struct V_21 * V_21 = (struct V_21 * ) F_31 ( V_63 ,
struct V_21 , V_62 ) ;
struct V_33 V_34 ;
T_1 V_74 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_65 . V_43 = V_77 ;
V_74 = F_39 ( V_65 ) ;
V_34 . V_41 . V_65 . V_70 = F_33 ( V_74 ) ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
return V_35 ;
}
static void F_40 ( struct V_21 * V_21 )
{
struct V_33 V_34 ;
int V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_36 = F_21 ( F_22 ( V_37 ) |
V_38 |
V_39 |
F_23 ( 0 ) ) ;
V_34 . V_40 = F_21 ( F_24 ( sizeof( V_34 ) / 16 ) ) ;
V_34 . V_41 . V_78 . V_43 = V_79 ;
V_35 = F_26 ( V_21 , V_21 -> V_45 , & V_34 , sizeof( V_34 ) , NULL ) ;
if ( V_35 < 0 )
F_27 ( V_21 -> V_46 ,
L_1 , V_47 , - V_35 ) ;
}
static int F_41 ( struct V_62 T_6 * V_63 ,
struct V_80 T_6 * V_81 ,
int T_6 V_82 )
{
return - V_83 ;
}
void F_42 ( struct V_21 * V_21 )
{
struct V_73 V_84 ;
if ( ! F_43 ( V_21 -> V_85 ) )
return;
V_21 -> V_25 = NULL ;
V_21 -> V_62 = V_86 ;
F_44 ( & V_21 -> V_30 ) ;
V_21 -> V_85 = F_45 ( & V_21 -> V_62 ,
& V_21 -> V_87 -> V_14 ) ;
if ( F_43 ( V_21 -> V_85 ) ) {
V_21 -> V_85 = NULL ;
F_27 ( V_21 -> V_46 ,
L_2 , V_47 ) ;
return;
}
V_84 = F_46 ( F_47 () ) ;
F_40 ( V_21 ) ;
if ( F_38 ( & V_21 -> V_62 , & V_84 ) < 0 ) {
F_48 ( V_21 -> V_85 ) ;
V_21 -> V_85 = NULL ;
}
}
void F_49 ( struct V_21 * V_21 )
{
if ( V_21 -> V_25 ) {
F_17 ( V_21 -> V_25 ) ;
V_21 -> V_25 = NULL ;
}
if ( V_21 -> V_85 ) {
F_48 ( V_21 -> V_85 ) ;
V_21 -> V_85 = NULL ;
}
}
