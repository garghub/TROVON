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
#ifdef F_30
if ( V_3 -> V_51 ) {
struct V_52 * V_53 = F_31 ( V_3 ) ;
V_4 -> V_35 = V_3 -> V_51 -> V_54 ;
V_4 -> V_55 = F_32 ( V_56 ) ;
V_14 -> V_57 = F_32 ( sizeof( struct V_5 ) ) ;
if ( F_33 ( V_4 , V_4 -> V_35 , F_34 ( V_4 -> V_55 ) ,
V_53 -> V_58 , V_53 -> V_59 , V_4 -> V_27 ) < 0 )
return;
F_35 ( V_4 ) ;
} else
#endif
F_36 ( V_4 ) ;
}
static inline void
F_37 ( struct V_1 * V_1 , struct V_2 * V_60 , unsigned char V_61 ,
unsigned int V_62 )
{
if ( V_62 == V_63 && V_60 -> V_35 == NULL )
V_60 -> V_35 = V_1 -> V_64 ;
F_38 ( V_60 , V_65 , V_61 , 0 ) ;
}
static unsigned int
F_39 ( struct V_2 * V_66 , const struct V_67 * V_68 )
{
const struct V_69 * V_70 = V_68 -> V_71 ;
struct V_1 * V_1 = F_40 ( ( V_68 -> V_72 != NULL ) ? V_68 -> V_72 : V_68 -> V_73 ) ;
F_5 ( L_8 , V_74 ) ;
switch ( V_70 -> V_75 ) {
case V_76 :
F_37 ( V_1 , V_66 , V_77 , V_68 -> V_62 ) ;
break;
case V_78 :
F_37 ( V_1 , V_66 , V_79 , V_68 -> V_62 ) ;
break;
case V_80 :
F_37 ( V_1 , V_66 , V_81 , V_68 -> V_62 ) ;
break;
case V_82 :
F_37 ( V_1 , V_66 , V_83 , V_68 -> V_62 ) ;
break;
case V_84 :
F_37 ( V_1 , V_66 , V_85 , V_68 -> V_62 ) ;
break;
case V_86 :
break;
case V_87 :
F_1 ( V_1 , V_66 ) ;
break;
default:
F_41 ( L_9 , V_70 -> V_75 ) ;
break;
}
return V_88 ;
}
static int F_42 ( const struct V_89 * V_68 )
{
const struct V_69 * V_90 = V_68 -> V_71 ;
const struct V_91 * V_92 = V_68 -> V_93 ;
if ( V_90 -> V_75 == V_86 ) {
F_43 ( L_10 ) ;
return - V_94 ;
} else if ( V_90 -> V_75 == V_87 ) {
if ( V_92 -> V_95 . V_18 != V_28 ||
( V_92 -> V_95 . V_96 & V_97 ) ) {
F_43 ( L_11 ) ;
return - V_94 ;
}
}
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_98 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_98 ) ;
}
