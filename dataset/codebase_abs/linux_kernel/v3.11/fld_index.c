int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_5 * V_9 ;
struct V_5 * V_10 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
V_14 ;
V_12 = F_2 ( & V_2 -> V_15 , & V_16 ) ;
V_10 = & V_12 -> V_17 ;
V_9 = & V_12 -> V_18 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_13 = F_3 ( V_2 , V_4 , V_6 -> V_19 , V_10 ) ;
if ( V_13 == 0 ) {
F_4 ( ( F_5 ( V_6 , V_10 ) == 0 ) ) ;
GOTO ( V_20 , V_13 = - V_21 ) ;
}
if ( V_13 != - V_22 ) {
F_6 ( L_1 V_23 L_2 ,
V_4 -> V_24 , F_7 ( V_10 ) , V_13 ) ;
GOTO ( V_20 , V_13 ) ;
}
if ( V_6 -> V_19 == V_10 -> V_25 && V_10 -> V_25 != 0 &&
F_5 ( V_6 , V_10 ) == 0 ) {
F_8 ( V_9 , V_10 ) ;
V_13 = F_9 ( V_2 , V_4 -> V_26 ,
(struct V_27 * ) & V_9 -> V_19 , V_8 ) ;
if ( V_13 ) {
F_6 ( L_3 V_23 L_4 ,
V_4 -> V_24 , F_7 ( V_10 ) , V_13 ) ;
GOTO ( V_20 , V_13 ) ;
}
memcpy ( V_9 , V_6 , sizeof( * V_6 ) ) ;
V_9 -> V_19 = V_10 -> V_19 ;
} else {
memcpy ( V_9 , V_6 , sizeof( * V_6 ) ) ;
}
F_8 ( V_9 , V_9 ) ;
V_13 = F_10 ( V_2 , V_4 -> V_26 , (struct V_28 * ) V_9 ,
(struct V_27 * ) & V_9 -> V_19 , V_8 ) ;
V_20:
RETURN ( V_13 ) ;
}
int F_11 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_5 * V_10 ;
struct V_5 * V_9 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
int V_29 = 0 ;
struct V_30 * V_31 ;
V_14 ;
V_12 = F_2 ( & V_2 -> V_15 , & V_16 ) ;
F_4 ( F_12 ( & V_4 -> V_32 ) ) ;
V_10 = & V_12 -> V_17 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_9 = & V_12 -> V_18 ;
V_13 = F_3 ( V_2 , V_4 , V_6 -> V_19 , V_10 ) ;
if ( V_13 != - V_22 ) {
V_13 = V_13 == 0 ? - V_21 : V_13 ;
GOTO ( V_20 , V_13 ) ;
}
if ( V_6 -> V_19 == V_10 -> V_25 && V_10 -> V_25 != 0 &&
F_5 ( V_6 , V_10 ) == 0 ) {
F_8 ( V_9 , V_10 ) ;
V_13 = F_13 ( V_2 , V_4 -> V_26 ,
(struct V_27 * ) & V_9 -> V_19 , V_8 ,
V_33 ) ;
if ( V_13 != 0 )
GOTO ( V_20 , V_13 ) ;
memcpy ( V_9 , V_6 , sizeof( * V_6 ) ) ;
V_9 -> V_19 = V_10 -> V_19 ;
V_29 = 1 ;
} else {
memcpy ( V_9 , V_6 , sizeof( * V_6 ) ) ;
}
F_8 ( V_9 , V_9 ) ;
V_13 = F_14 ( V_2 , V_4 -> V_26 , (struct V_28 * ) V_9 ,
(struct V_27 * ) & V_9 -> V_19 , V_8 , V_33 , 1 ) ;
if ( V_13 != 0 ) {
F_6 ( L_5 V_23 L_4 ,
V_4 -> V_24 , F_7 ( V_6 ) , V_13 ) ;
GOTO ( V_20 , V_13 ) ;
}
V_31 = F_15 ( V_6 ) ;
if ( F_16 ( V_31 ) )
GOTO ( V_20 , V_13 = F_17 ( V_31 ) ) ;
F_18 ( & V_4 -> V_34 -> V_35 ) ;
if ( V_29 )
F_19 ( V_4 -> V_34 , V_6 ) ;
V_13 = F_20 ( V_4 -> V_34 , V_31 ) ;
F_21 ( & V_4 -> V_34 -> V_35 ) ;
if ( V_13 )
F_22 ( V_31 ) ;
V_20:
RETURN ( V_13 ) ;
}
int F_3 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_36 , struct V_5 * V_10 )
{
struct V_5 * V_37 ;
struct V_11 * V_12 ;
int V_13 ;
V_14 ;
V_12 = F_2 ( & V_2 -> V_15 , & V_16 ) ;
V_37 = & V_12 -> V_38 ;
V_13 = F_23 ( V_4 -> V_34 , V_36 , V_37 ) ;
if ( V_13 == 0 ) {
* V_10 = * V_37 ;
if ( F_24 ( V_10 , V_36 ) )
V_13 = 0 ;
else
V_13 = - V_22 ;
}
F_25 ( V_39 , L_6 V_40 L_7 V_23 L_8 ,
V_4 -> V_24 , V_36 , F_7 ( V_10 ) , V_13 ) ;
RETURN ( V_13 ) ;
}
int F_26 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_10 )
{
struct V_7 * V_8 ;
int V_13 ;
V_14 ;
V_8 = F_27 ( V_2 , F_28 ( V_4 -> V_26 -> V_41 . V_42 ) ) ;
if ( F_16 ( V_8 ) )
RETURN ( F_17 ( V_8 ) ) ;
V_13 = F_1 ( V_2 , V_4 , V_10 , V_8 ) ;
if ( V_13 != 0 ) {
if ( V_13 == - V_21 )
V_13 = 0 ;
GOTO ( V_20 , V_13 ) ;
}
V_13 = F_29 ( V_2 , F_28 ( V_4 -> V_26 -> V_41 . V_42 ) ,
V_8 ) ;
if ( V_13 )
GOTO ( V_20 , V_13 ) ;
V_13 = F_11 ( V_2 , V_4 , V_10 , V_8 ) ;
if ( V_13 == - V_21 )
V_13 = 0 ;
V_20:
F_30 ( V_2 , F_28 ( V_4 -> V_26 -> V_41 . V_42 ) , V_8 ) ;
RETURN ( V_13 ) ;
}
static int F_31 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_13 ;
V_13 = F_26 ( V_2 , V_4 , & V_43 ) ;
if ( V_13 != 0 )
RETURN ( V_13 ) ;
V_13 = F_26 ( V_2 , V_4 , & V_44 ) ;
if ( V_13 != 0 )
RETURN ( V_13 ) ;
V_13 = F_26 ( V_2 , V_4 , & V_45 ) ;
RETURN ( V_13 ) ;
}
int F_32 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = NULL ;
struct V_50 V_51 ;
struct V_52 * V_53 = NULL ;
struct V_5 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_54 V_55 ;
struct V_56 * V_57 ;
const struct V_58 * V_59 ;
int V_13 ;
V_14 ;
V_12 = F_2 ( & V_2 -> V_15 , & V_16 ) ;
F_4 ( V_12 != NULL ) ;
F_33 ( & V_51 , V_60 ) ;
F_34 ( V_53 ) ;
if ( V_53 == NULL )
RETURN ( - V_61 ) ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_62 = V_63 ;
V_53 -> V_64 = V_65 | 0666 ;
V_55 . V_66 = V_67 ;
V_55 . V_68 . V_69 . V_70 = & V_71 ;
V_49 = F_35 ( V_2 , V_47 , & V_51 , & V_55 , V_53 ) ;
if ( F_16 ( V_49 ) ) {
V_13 = F_17 ( V_49 ) ;
F_6 ( L_9 , V_4 -> V_24 ,
V_72 , V_13 ) ;
V_49 = NULL ;
GOTO ( V_20 , V_13 ) ;
}
V_4 -> V_26 = V_49 ;
V_13 = V_49 -> V_73 -> V_74 ( V_2 , V_49 , & V_71 ) ;
if ( V_13 != 0 ) {
F_6 ( L_10 ,
V_4 -> V_24 , V_72 , V_13 ) ;
GOTO ( V_20 , V_13 ) ;
}
V_10 = & V_12 -> V_38 ;
V_59 = & V_49 -> V_75 -> V_76 ;
V_57 = V_59 -> V_77 ( V_2 , V_49 , 0 , NULL ) ;
if ( F_16 ( V_57 ) )
GOTO ( V_20 , V_13 = F_17 ( V_57 ) ) ;
V_13 = V_59 -> V_78 ( V_2 , V_57 , 0 ) ;
if ( V_13 < 0 )
GOTO ( V_79 , V_13 ) ;
if ( V_13 > 0 ) {
do {
V_13 = V_59 -> V_80 ( V_2 , V_57 , (struct V_28 * ) V_10 , 0 ) ;
if ( V_13 != 0 )
GOTO ( V_81 , V_13 ) ;
F_4 ( V_10 != NULL ) ;
F_36 ( V_10 , V_10 ) ;
V_13 = F_37 ( V_4 -> V_34 , V_10 ) ;
if ( V_13 != 0 )
GOTO ( V_81 , V_13 ) ;
V_13 = V_59 -> V_82 ( V_2 , V_57 ) ;
} while ( V_13 == 0 );
}
F_38 ( & V_4 -> V_32 ) ;
V_13 = F_31 ( V_2 , V_4 ) ;
F_39 ( & V_4 -> V_32 ) ;
if ( V_13 != 0 ) {
F_6 ( L_11 ,
V_4 -> V_24 , V_13 ) ;
GOTO ( V_81 , V_13 ) ;
}
V_81:
V_59 -> V_83 ( V_2 , V_57 ) ;
V_79:
V_59 -> V_84 ( V_2 , V_57 ) ;
V_20:
if ( V_53 != NULL )
F_22 ( V_53 ) ;
if ( V_13 != 0 ) {
if ( V_49 != NULL )
F_40 ( V_2 , & V_49 -> V_41 ) ;
V_4 -> V_26 = NULL ;
}
RETURN ( V_13 ) ;
}
void F_41 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
V_14 ;
if ( V_4 -> V_26 != NULL ) {
if ( ! F_16 ( V_4 -> V_26 ) )
F_40 ( V_2 , & V_4 -> V_26 -> V_41 ) ;
V_4 -> V_26 = NULL ;
}
EXIT ;
}
