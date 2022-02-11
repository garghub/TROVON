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
struct V_19 V_20 ;
if ( ( ! ( F_4 ( & V_13 -> V_21 ) & V_22 ) ) ||
( ! ( F_4 ( & V_13 -> V_23 ) & V_22 ) ) ) {
F_5 ( L_1 ) ;
return;
}
V_18 = V_13 -> V_24 ;
V_10 = F_6 ( V_3 , ( ( T_2 * ) ( V_13 + 1 ) - V_3 -> V_25 ) , & V_18 ) ;
if ( ( V_10 < 0 ) || ( V_10 > V_3 -> V_26 ) ) {
F_5 ( L_2 ) ;
return;
}
V_8 = V_3 -> V_26 - V_10 ;
if ( V_18 != V_27 || V_8 < sizeof( struct V_5 ) ) {
F_5 ( L_3
L_4 ,
V_18 , V_8 ) ;
return;
}
if ( F_7 ( V_3 , V_10 , & V_6 , sizeof( struct V_5 ) ) )
F_8 () ;
if ( V_6 . V_28 ) {
F_5 ( L_5 ) ;
return;
}
if ( F_9 ( & V_13 -> V_21 , & V_13 -> V_23 , V_8 , V_27 ,
F_10 ( V_3 , V_10 , V_8 , 0 ) ) ) {
F_5 ( L_6 ) ;
return;
}
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_29 = V_27 ;
F_11 ( & V_20 . V_21 , & V_13 -> V_23 ) ;
F_11 ( & V_20 . V_23 , & V_13 -> V_21 ) ;
V_20 . V_30 = V_6 . V_31 ;
V_20 . V_32 = V_6 . V_33 ;
F_12 ( V_3 , F_13 ( & V_20 ) ) ;
V_17 = F_14 ( V_1 , NULL , & V_20 ) ;
if ( V_17 == NULL || V_17 -> error ) {
F_15 ( V_17 ) ;
return;
}
V_17 = F_16 ( V_1 , V_17 , F_13 ( & V_20 ) , NULL , 0 ) ;
if ( F_17 ( V_17 ) )
return;
V_9 = ( V_17 -> V_34 -> V_35 + 15 ) & ~ 15 ;
V_4 = F_18 ( V_9 + 15 + V_17 -> V_36 + sizeof( struct V_12 )
+ sizeof( struct V_5 ) + V_17 -> V_37 ,
V_38 ) ;
if ( ! V_4 ) {
if ( F_19 () )
F_5 ( L_7 ) ;
F_15 ( V_17 ) ;
return;
}
F_20 ( V_4 , V_17 ) ;
F_21 ( V_4 , V_9 + V_17 -> V_36 ) ;
F_22 ( V_4 , sizeof( struct V_12 ) ) ;
F_23 ( V_4 ) ;
V_14 = F_2 ( V_4 ) ;
* ( V_39 * ) V_14 = F_24 ( 0x60000000 | ( V_15 << 20 ) ) ;
V_14 -> V_40 = F_25 ( V_17 ) ;
V_14 -> V_24 = V_27 ;
F_11 ( & V_14 -> V_21 , & V_13 -> V_23 ) ;
F_11 ( & V_14 -> V_23 , & V_13 -> V_21 ) ;
V_7 = (struct V_5 * ) F_22 ( V_4 , sizeof( struct V_5 ) ) ;
V_7 -> V_41 = sizeof( struct V_5 ) / 4 ;
V_7 -> V_33 = V_6 . V_31 ;
V_7 -> V_31 = V_6 . V_33 ;
if ( V_6 . V_42 ) {
V_11 = 0 ;
V_7 -> V_43 = V_6 . V_44 ;
V_7 -> V_44 = 0 ;
} else {
V_11 = 1 ;
V_7 -> V_44 = F_24 ( F_26 ( V_6 . V_43 ) + V_6 . V_45 + V_6 . V_46
+ V_8 - ( V_6 . V_41 << 2 ) ) ;
V_7 -> V_43 = 0 ;
}
( ( V_47 * ) V_7 ) [ 13 ] = 0 ;
V_7 -> V_28 = 1 ;
V_7 -> V_42 = V_11 ;
V_7 -> V_48 = 0 ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = 0 ;
V_7 -> V_50 = F_9 ( & F_2 ( V_4 ) -> V_21 ,
& F_2 ( V_4 ) -> V_23 ,
sizeof( struct V_5 ) , V_27 ,
F_27 ( V_7 ,
sizeof( struct V_5 ) , 0 ) ) ;
F_28 ( V_4 , V_3 ) ;
F_29 ( V_4 ) ;
}
static inline void
F_30 ( struct V_1 * V_1 , struct V_2 * V_51 , unsigned char V_52 ,
unsigned int V_53 )
{
if ( V_53 == V_54 && V_51 -> V_34 == NULL )
V_51 -> V_34 = V_1 -> V_55 ;
F_31 ( V_51 , V_56 , V_52 , 0 ) ;
}
static unsigned int
F_32 ( struct V_2 * V_57 , const struct V_58 * V_59 )
{
const struct V_60 * V_61 = V_59 -> V_62 ;
struct V_1 * V_1 = F_33 ( ( V_59 -> V_63 != NULL ) ? V_59 -> V_63 : V_59 -> V_64 ) ;
F_5 ( L_8 , V_65 ) ;
switch ( V_61 -> V_66 ) {
case V_67 :
F_30 ( V_1 , V_57 , V_68 , V_59 -> V_53 ) ;
break;
case V_69 :
F_30 ( V_1 , V_57 , V_70 , V_59 -> V_53 ) ;
break;
case V_71 :
F_30 ( V_1 , V_57 , V_72 , V_59 -> V_53 ) ;
break;
case V_73 :
F_30 ( V_1 , V_57 , V_74 , V_59 -> V_53 ) ;
break;
case V_75 :
F_30 ( V_1 , V_57 , V_76 , V_59 -> V_53 ) ;
break;
case V_77 :
break;
case V_78 :
F_1 ( V_1 , V_57 ) ;
break;
default:
if ( F_19 () )
F_34 ( L_9 , V_61 -> V_66 ) ;
break;
}
return V_79 ;
}
static int F_35 ( const struct V_80 * V_59 )
{
const struct V_60 * V_81 = V_59 -> V_62 ;
const struct V_82 * V_83 = V_59 -> V_84 ;
if ( V_81 -> V_66 == V_77 ) {
F_34 ( L_10 ) ;
return - V_85 ;
} else if ( V_81 -> V_66 == V_78 ) {
if ( V_83 -> V_86 . V_18 != V_27 ||
( V_83 -> V_86 . V_87 & V_88 ) ) {
F_34 ( L_11 ) ;
return - V_85 ;
}
}
return 0 ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_89 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_89 ) ;
}
