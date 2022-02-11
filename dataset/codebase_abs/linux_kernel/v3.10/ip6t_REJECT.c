static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 ;
struct V_5 V_6 , * V_7 ;
unsigned int V_8 , V_9 ;
int V_10 , V_11 ;
const struct V_12 * V_13 = F_2 ( V_3 ) ;
struct V_12 * V_14 ;
#define F_3 0x0U
const T_1 V_15 = F_3 ;
struct V_16 * V_17 = NULL ;
T_2 V_18 ;
T_3 V_19 ;
struct V_20 V_21 ;
if ( ( ! ( F_4 ( & V_13 -> V_22 ) & V_23 ) ) ||
( ! ( F_4 ( & V_13 -> V_24 ) & V_23 ) ) ) {
F_5 ( L_1 ) ;
return;
}
V_18 = V_13 -> V_25 ;
V_10 = F_6 ( V_3 , ( ( T_2 * ) ( V_13 + 1 ) - V_3 -> V_26 ) , & V_18 , & V_19 ) ;
if ( ( V_10 < 0 ) || ( V_10 > V_3 -> V_27 ) ) {
F_5 ( L_2 ) ;
return;
}
V_8 = V_3 -> V_27 - V_10 ;
if ( V_18 != V_28 || V_8 < sizeof( struct V_5 ) ) {
F_5 ( L_3
L_4 ,
V_18 , V_8 ) ;
return;
}
if ( F_7 ( V_3 , V_10 , & V_6 , sizeof( struct V_5 ) ) )
F_8 () ;
if ( V_6 . V_29 ) {
F_5 ( L_5 ) ;
return;
}
if ( F_9 ( & V_13 -> V_22 , & V_13 -> V_24 , V_8 , V_28 ,
F_10 ( V_3 , V_10 , V_8 , 0 ) ) ) {
F_5 ( L_6 ) ;
return;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_30 = V_28 ;
V_21 . V_22 = V_13 -> V_24 ;
V_21 . V_24 = V_13 -> V_22 ;
V_21 . V_31 = V_6 . V_32 ;
V_21 . V_33 = V_6 . V_34 ;
F_11 ( V_3 , F_12 ( & V_21 ) ) ;
V_17 = F_13 ( V_1 , NULL , & V_21 ) ;
if ( V_17 == NULL || V_17 -> error ) {
F_14 ( V_17 ) ;
return;
}
V_17 = F_15 ( V_1 , V_17 , F_12 ( & V_21 ) , NULL , 0 ) ;
if ( F_16 ( V_17 ) )
return;
V_9 = ( V_17 -> V_35 -> V_36 + 15 ) & ~ 15 ;
V_4 = F_17 ( V_9 + 15 + V_17 -> V_37 + sizeof( struct V_12 )
+ sizeof( struct V_5 ) + V_17 -> V_38 ,
V_39 ) ;
if ( ! V_4 ) {
F_18 ( L_7 ) ;
F_14 ( V_17 ) ;
return;
}
F_19 ( V_4 , V_17 ) ;
F_20 ( V_4 , V_9 + V_17 -> V_37 ) ;
F_21 ( V_4 , sizeof( struct V_12 ) ) ;
F_22 ( V_4 ) ;
V_14 = F_2 ( V_4 ) ;
F_23 ( V_14 , V_15 , 0 ) ;
V_14 -> V_40 = F_24 ( V_17 ) ;
V_14 -> V_25 = V_28 ;
V_14 -> V_22 = V_13 -> V_24 ;
V_14 -> V_24 = V_13 -> V_22 ;
F_25 ( V_4 ) ;
V_7 = (struct V_5 * ) F_21 ( V_4 , sizeof( struct V_5 ) ) ;
V_7 -> V_41 = sizeof( struct V_5 ) / 4 ;
V_7 -> V_34 = V_6 . V_32 ;
V_7 -> V_32 = V_6 . V_34 ;
if ( V_6 . V_42 ) {
V_11 = 0 ;
V_7 -> V_43 = V_6 . V_44 ;
V_7 -> V_44 = 0 ;
} else {
V_11 = 1 ;
V_7 -> V_44 = F_26 ( F_27 ( V_6 . V_43 ) + V_6 . V_45 + V_6 . V_46
+ V_8 - ( V_6 . V_41 << 2 ) ) ;
V_7 -> V_43 = 0 ;
}
( ( V_47 * ) V_7 ) [ 13 ] = 0 ;
V_7 -> V_29 = 1 ;
V_7 -> V_42 = V_11 ;
V_7 -> V_48 = 0 ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = 0 ;
V_7 -> V_50 = F_9 ( & F_2 ( V_4 ) -> V_22 ,
& F_2 ( V_4 ) -> V_24 ,
sizeof( struct V_5 ) , V_28 ,
F_28 ( V_7 ,
sizeof( struct V_5 ) , 0 ) ) ;
F_29 ( V_4 , V_3 ) ;
F_30 ( V_4 ) ;
}
static inline void
F_31 ( struct V_1 * V_1 , struct V_2 * V_51 , unsigned char V_52 ,
unsigned int V_53 )
{
if ( V_53 == V_54 && V_51 -> V_35 == NULL )
V_51 -> V_35 = V_1 -> V_55 ;
F_32 ( V_51 , V_56 , V_52 , 0 ) ;
}
static unsigned int
F_33 ( struct V_2 * V_57 , const struct V_58 * V_59 )
{
const struct V_60 * V_61 = V_59 -> V_62 ;
struct V_1 * V_1 = F_34 ( ( V_59 -> V_63 != NULL ) ? V_59 -> V_63 : V_59 -> V_64 ) ;
F_5 ( L_8 , V_65 ) ;
switch ( V_61 -> V_66 ) {
case V_67 :
F_31 ( V_1 , V_57 , V_68 , V_59 -> V_53 ) ;
break;
case V_69 :
F_31 ( V_1 , V_57 , V_70 , V_59 -> V_53 ) ;
break;
case V_71 :
F_31 ( V_1 , V_57 , V_72 , V_59 -> V_53 ) ;
break;
case V_73 :
F_31 ( V_1 , V_57 , V_74 , V_59 -> V_53 ) ;
break;
case V_75 :
F_31 ( V_1 , V_57 , V_76 , V_59 -> V_53 ) ;
break;
case V_77 :
break;
case V_78 :
F_1 ( V_1 , V_57 ) ;
break;
default:
F_35 ( L_9 , V_61 -> V_66 ) ;
break;
}
return V_79 ;
}
static int F_36 ( const struct V_80 * V_59 )
{
const struct V_60 * V_81 = V_59 -> V_62 ;
const struct V_82 * V_83 = V_59 -> V_84 ;
if ( V_81 -> V_66 == V_77 ) {
F_37 ( L_10 ) ;
return - V_85 ;
} else if ( V_81 -> V_66 == V_78 ) {
if ( V_83 -> V_86 . V_18 != V_28 ||
( V_83 -> V_86 . V_87 & V_88 ) ) {
F_37 ( L_11 ) ;
return - V_85 ;
}
}
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_89 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_89 ) ;
}
