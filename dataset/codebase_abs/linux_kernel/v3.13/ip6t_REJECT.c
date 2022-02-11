static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_2 * V_5 ;
struct V_6 V_7 , * V_8 ;
unsigned int V_9 , V_10 ;
int V_11 , V_12 ;
const struct V_13 * V_14 = F_2 ( V_3 ) ;
struct V_13 * V_15 ;
#define F_3 0x0U
const T_1 V_16 = F_3 ;
struct V_17 * V_18 = NULL ;
T_2 V_19 ;
T_3 V_20 ;
struct V_21 V_22 ;
if ( ( ! ( F_4 ( & V_14 -> V_23 ) & V_24 ) ) ||
( ! ( F_4 ( & V_14 -> V_25 ) & V_24 ) ) ) {
F_5 ( L_1 ) ;
return;
}
V_19 = V_14 -> V_26 ;
V_11 = F_6 ( V_3 , ( ( T_2 * ) ( V_14 + 1 ) - V_3 -> V_27 ) , & V_19 , & V_20 ) ;
if ( ( V_11 < 0 ) || ( V_11 > V_3 -> V_28 ) ) {
F_5 ( L_2 ) ;
return;
}
V_9 = V_3 -> V_28 - V_11 ;
if ( V_19 != V_29 || V_9 < sizeof( struct V_6 ) ) {
F_5 ( L_3
L_4 ,
V_19 , V_9 ) ;
return;
}
if ( F_7 ( V_3 , V_11 , & V_7 , sizeof( struct V_6 ) ) )
F_8 () ;
if ( V_7 . V_30 ) {
F_5 ( L_5 ) ;
return;
}
if ( F_9 ( V_3 , V_4 , V_11 , V_29 ) ) {
F_5 ( L_6 ) ;
return;
}
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_31 = V_29 ;
V_22 . V_23 = V_14 -> V_25 ;
V_22 . V_25 = V_14 -> V_23 ;
V_22 . V_32 = V_7 . V_33 ;
V_22 . V_34 = V_7 . V_35 ;
F_10 ( V_3 , F_11 ( & V_22 ) ) ;
V_18 = F_12 ( V_1 , NULL , & V_22 ) ;
if ( V_18 == NULL || V_18 -> error ) {
F_13 ( V_18 ) ;
return;
}
V_18 = F_14 ( V_1 , V_18 , F_11 ( & V_22 ) , NULL , 0 ) ;
if ( F_15 ( V_18 ) )
return;
V_10 = ( V_18 -> V_36 -> V_37 + 15 ) & ~ 15 ;
V_5 = F_16 ( V_10 + 15 + V_18 -> V_38 + sizeof( struct V_13 )
+ sizeof( struct V_6 ) + V_18 -> V_39 ,
V_40 ) ;
if ( ! V_5 ) {
F_17 ( L_7 ) ;
F_13 ( V_18 ) ;
return;
}
F_18 ( V_5 , V_18 ) ;
F_19 ( V_5 , V_10 + V_18 -> V_38 ) ;
F_20 ( V_5 , sizeof( struct V_13 ) ) ;
F_21 ( V_5 ) ;
V_15 = F_2 ( V_5 ) ;
F_22 ( V_15 , V_16 , 0 ) ;
V_15 -> V_41 = F_23 ( V_18 ) ;
V_15 -> V_26 = V_29 ;
V_15 -> V_23 = V_14 -> V_25 ;
V_15 -> V_25 = V_14 -> V_23 ;
F_24 ( V_5 ) ;
V_8 = (struct V_6 * ) F_20 ( V_5 , sizeof( struct V_6 ) ) ;
V_8 -> V_42 = sizeof( struct V_6 ) / 4 ;
V_8 -> V_35 = V_7 . V_33 ;
V_8 -> V_33 = V_7 . V_35 ;
if ( V_7 . V_43 ) {
V_12 = 0 ;
V_8 -> V_44 = V_7 . V_45 ;
V_8 -> V_45 = 0 ;
} else {
V_12 = 1 ;
V_8 -> V_45 = F_25 ( F_26 ( V_7 . V_44 ) + V_7 . V_46 + V_7 . V_47
+ V_9 - ( V_7 . V_42 << 2 ) ) ;
V_8 -> V_44 = 0 ;
}
( ( V_48 * ) V_8 ) [ 13 ] = 0 ;
V_8 -> V_30 = 1 ;
V_8 -> V_43 = V_12 ;
V_8 -> V_49 = 0 ;
V_8 -> V_50 = 0 ;
V_8 -> V_51 = 0 ;
V_8 -> V_51 = F_27 ( & F_2 ( V_5 ) -> V_23 ,
& F_2 ( V_5 ) -> V_25 ,
sizeof( struct V_6 ) , V_29 ,
F_28 ( V_8 ,
sizeof( struct V_6 ) , 0 ) ) ;
F_29 ( V_5 , V_3 ) ;
#ifdef F_30
if ( V_3 -> V_52 ) {
struct V_53 * V_54 = F_31 ( V_3 ) ;
V_5 -> V_36 = V_3 -> V_52 -> V_55 ;
V_5 -> V_56 = F_32 ( V_57 ) ;
V_15 -> V_58 = F_32 ( sizeof( struct V_6 ) ) ;
if ( F_33 ( V_5 , V_5 -> V_36 , F_34 ( V_5 -> V_56 ) ,
V_54 -> V_59 , V_54 -> V_60 , V_5 -> V_28 ) < 0 )
return;
F_35 ( V_5 ) ;
} else
#endif
F_36 ( V_5 ) ;
}
static inline void
F_37 ( struct V_1 * V_1 , struct V_2 * V_61 , unsigned char V_62 ,
unsigned int V_63 )
{
if ( V_63 == V_64 && V_61 -> V_36 == NULL )
V_61 -> V_36 = V_1 -> V_65 ;
F_38 ( V_61 , V_66 , V_62 , 0 ) ;
}
static unsigned int
F_39 ( struct V_2 * V_67 , const struct V_68 * V_69 )
{
const struct V_70 * V_71 = V_69 -> V_72 ;
struct V_1 * V_1 = F_40 ( ( V_69 -> V_73 != NULL ) ? V_69 -> V_73 : V_69 -> V_74 ) ;
F_5 ( L_8 , V_75 ) ;
switch ( V_71 -> V_76 ) {
case V_77 :
F_37 ( V_1 , V_67 , V_78 , V_69 -> V_63 ) ;
break;
case V_79 :
F_37 ( V_1 , V_67 , V_80 , V_69 -> V_63 ) ;
break;
case V_81 :
F_37 ( V_1 , V_67 , V_82 , V_69 -> V_63 ) ;
break;
case V_83 :
F_37 ( V_1 , V_67 , V_84 , V_69 -> V_63 ) ;
break;
case V_85 :
F_37 ( V_1 , V_67 , V_86 , V_69 -> V_63 ) ;
break;
case V_87 :
break;
case V_88 :
F_1 ( V_1 , V_67 , V_69 -> V_63 ) ;
break;
default:
F_41 ( L_9 , V_71 -> V_76 ) ;
break;
}
return V_89 ;
}
static int F_42 ( const struct V_90 * V_69 )
{
const struct V_70 * V_91 = V_69 -> V_72 ;
const struct V_92 * V_93 = V_69 -> V_94 ;
if ( V_91 -> V_76 == V_87 ) {
F_43 ( L_10 ) ;
return - V_95 ;
} else if ( V_91 -> V_76 == V_88 ) {
if ( V_93 -> V_96 . V_19 != V_29 ||
( V_93 -> V_96 . V_97 & V_98 ) ) {
F_43 ( L_11 ) ;
return - V_95 ;
}
}
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_99 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_99 ) ;
}
