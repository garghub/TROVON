static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != - V_4 )
F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
if ( V_7 > 0 && V_7 < 4 )
return - V_8 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 , const T_1 * V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_17 V_18 ;
int V_3 = - V_8 ;
if ( F_6 ( & V_18 , V_9 , V_10 ) != 0 )
goto V_19;
F_7 ( V_14 , V_20 ) ;
F_8 ( V_14 , F_9 ( V_6 ) &
V_20 ) ;
V_3 = F_10 ( V_14 , V_18 . V_21 , V_18 . V_22 ) ;
F_11 ( V_6 , F_12 ( V_14 ) &
V_23 ) ;
if ( V_3 )
goto V_24;
F_13 ( V_16 , V_20 ) ;
F_14 ( V_16 , F_9 ( V_6 ) &
V_20 ) ;
V_3 = F_15 ( V_16 , V_18 . V_25 , V_18 . V_26 ) ;
F_11 ( V_6 , F_16 ( V_16 ) &
V_23 ) ;
V_24:
return V_3 ;
V_19:
F_11 ( V_6 , V_27 ) ;
goto V_24;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 * V_31 = F_20 ( ( T_1 * ) V_30 -> V_32 ,
F_21 ( V_14 ) + 1 ) ;
unsigned int V_7 = F_22 ( V_6 ) ;
unsigned int V_33 = V_2 -> V_33 ;
unsigned int V_34 = V_2 -> V_34 ;
struct V_35 * V_36 = V_2 -> V_36 ;
T_2 V_37 [ 2 ] ;
F_23 ( V_37 , V_36 , 4 , 4 , 0 ) ;
F_23 ( V_37 + 1 , V_36 , V_33 + V_34 , 4 , 0 ) ;
F_23 ( V_37 , V_36 , 0 , 8 , 1 ) ;
F_23 ( V_31 , V_36 , V_33 + V_34 , V_7 , 1 ) ;
return 0 ;
}
static void F_24 ( struct V_38 * V_39 ,
int V_3 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
V_3 = V_3 ? : F_17 ( V_2 , 0 ) ;
F_2 ( V_2 , V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 * V_31 = F_20 ( ( T_1 * ) V_30 -> V_32 ,
F_21 ( V_14 ) + 1 ) ;
struct V_41 * V_42 = ( void * ) ( V_30 -> V_32 + V_12 -> V_43 ) ;
unsigned int V_7 = F_22 ( V_6 ) ;
unsigned int V_33 = V_2 -> V_33 ;
unsigned int V_34 = V_2 -> V_34 ;
struct V_35 * V_36 = V_2 -> V_36 ;
T_2 V_37 [ 2 ] ;
if ( ! V_7 )
return 0 ;
F_23 ( V_37 , V_36 , 0 , 8 , 0 ) ;
F_23 ( V_37 , V_36 , 4 , 4 , 1 ) ;
F_23 ( V_37 + 1 , V_36 , V_33 + V_34 , 4 , 1 ) ;
F_26 ( V_30 -> V_36 , 2 ) ;
V_36 = F_27 ( V_30 -> V_36 , V_36 , 4 ) ;
F_28 ( V_42 , V_14 ) ;
F_29 ( V_42 , V_36 , V_31 , V_33 + V_34 ) ;
F_30 ( V_42 , V_28 ,
F_24 , V_2 ) ;
return F_31 ( V_42 ) ? :
F_17 ( V_2 , F_32 ( V_2 ) ) ;
}
static void F_33 ( struct V_38 * V_2 ,
int V_3 )
{
struct V_1 * V_39 = V_2 -> V_40 ;
if ( ! V_3 )
V_3 = F_25 ( V_39 , 0 ) ;
F_1 ( V_39 , V_3 ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_44 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_45 V_46 = {
. V_47 = V_12 -> null ,
} ;
return F_35 ( & V_46 , V_2 -> V_36 , V_2 -> V_48 , V_44 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_49 * V_50 = ( void * ) ( V_30 -> V_32
+ V_12 -> V_43 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned int V_33 = V_2 -> V_33 ;
unsigned int V_34 = V_2 -> V_34 ;
struct V_35 * V_48 , * V_36 ;
int V_3 ;
F_26 ( V_30 -> V_48 , 2 ) ;
V_48 = F_27 ( V_30 -> V_48 , V_2 -> V_48 , V_33 ) ;
V_36 = V_48 ;
if ( V_2 -> V_48 != V_2 -> V_36 ) {
V_3 = F_34 ( V_2 , V_33 ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_30 -> V_36 , 2 ) ;
V_36 = F_27 ( V_30 -> V_36 , V_2 -> V_36 , V_33 ) ;
}
F_37 ( V_50 , V_16 ) ;
F_38 ( V_50 , F_32 ( V_2 ) ,
F_33 , V_2 ) ;
F_39 ( V_50 , V_48 , V_36 , V_34 , V_2 -> V_51 ) ;
V_3 = F_40 ( V_50 ) ;
if ( V_3 )
return V_3 ;
return F_25 ( V_2 , F_32 ( V_2 ) ) ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
unsigned int V_7 = F_22 ( V_6 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_49 * V_50 = ( void * ) ( V_30 -> V_32
+ V_12 -> V_43 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 * V_52 = F_20 ( ( T_1 * ) V_30 -> V_32 ,
F_21 ( V_14 ) + 1 ) ;
unsigned int V_34 = V_2 -> V_34 - V_7 ;
unsigned int V_33 = V_2 -> V_33 ;
struct V_35 * V_36 = V_2 -> V_36 ;
T_1 * V_53 = V_52 + F_42 ( V_14 ) ;
T_2 V_37 [ 2 ] ;
F_23 ( V_37 , V_36 , 4 , 4 , 0 ) ;
F_23 ( V_37 + 1 , V_36 , V_33 + V_34 , 4 , 0 ) ;
F_23 ( V_37 , V_36 , 0 , 8 , 1 ) ;
if ( F_43 ( V_53 , V_52 , V_7 ) )
return - V_54 ;
F_26 ( V_30 -> V_36 , 2 ) ;
V_36 = F_27 ( V_30 -> V_36 , V_36 , V_33 ) ;
F_37 ( V_50 , V_12 -> V_16 ) ;
F_38 ( V_50 , V_28 ,
V_2 -> V_55 . V_56 , V_2 -> V_55 . V_40 ) ;
F_39 ( V_50 , V_36 , V_36 , V_34 , V_2 -> V_51 ) ;
return F_44 ( V_50 ) ;
}
static void F_45 ( struct V_38 * V_39 ,
int V_3 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
V_3 = V_3 ? : F_41 ( V_2 , 0 ) ;
F_2 ( V_2 , V_3 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_41 * V_42 = ( void * ) ( V_30 -> V_32 + V_12 -> V_43 ) ;
unsigned int V_7 = F_22 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 * V_52 = F_20 ( ( T_1 * ) V_30 -> V_32 ,
F_21 ( V_14 ) + 1 ) ;
unsigned int V_33 = V_2 -> V_33 ;
unsigned int V_34 = V_2 -> V_34 ;
T_1 * V_53 = V_52 + F_42 ( V_14 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
T_2 V_37 [ 2 ] ;
int V_3 ;
V_34 -= V_7 ;
if ( V_2 -> V_48 != V_36 ) {
V_3 = F_34 ( V_2 , V_33 + V_34 ) ;
if ( V_3 )
return V_3 ;
}
F_23 ( V_53 , V_2 -> V_48 , V_33 + V_34 ,
V_7 , 0 ) ;
if ( ! V_7 )
goto V_32;
F_23 ( V_37 , V_36 , 0 , 8 , 0 ) ;
F_23 ( V_37 , V_36 , 4 , 4 , 1 ) ;
F_23 ( V_37 + 1 , V_36 , V_33 + V_34 , 4 , 1 ) ;
F_26 ( V_30 -> V_36 , 2 ) ;
V_36 = F_27 ( V_30 -> V_36 , V_36 , 4 ) ;
F_28 ( V_42 , V_14 ) ;
F_29 ( V_42 , V_36 , V_52 , V_33 + V_34 ) ;
F_30 ( V_42 , F_32 ( V_2 ) ,
F_45 , V_2 ) ;
V_3 = F_31 ( V_42 ) ;
if ( V_3 )
return V_3 ;
V_32:
return F_41 ( V_2 , F_32 ( V_2 ) ) ;
}
static int F_47 ( struct V_5 * V_47 )
{
struct V_57 * V_58 = F_48 ( V_47 ) ;
struct V_59 * V_60 = F_49 ( V_58 ) ;
struct V_11 * V_12 = F_5 ( V_47 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_61 * null ;
int V_3 ;
V_14 = F_50 ( & V_60 -> V_14 ) ;
if ( F_51 ( V_14 ) )
return F_52 ( V_14 ) ;
V_16 = F_53 ( & V_60 -> V_16 ) ;
V_3 = F_52 ( V_16 ) ;
if ( F_51 ( V_16 ) )
goto V_62;
null = F_54 () ;
V_3 = F_52 ( null ) ;
if ( F_51 ( null ) )
goto V_63;
V_12 -> V_14 = V_14 ;
V_12 -> V_16 = V_16 ;
V_12 -> null = null ;
V_12 -> V_43 = F_55 ( 2 * F_42 ( V_14 ) ,
F_21 ( V_14 ) + 1 ) ;
F_56 (
V_47 ,
sizeof( struct V_29 ) +
V_12 -> V_43 +
F_57 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_givcrypt_request) +
crypto_ablkcipher_reqsize(enc)) ) ;
return 0 ;
V_63:
F_58 ( V_16 ) ;
V_62:
F_59 ( V_14 ) ;
return V_3 ;
}
static void F_60 ( struct V_5 * V_47 )
{
struct V_11 * V_12 = F_5 ( V_47 ) ;
F_59 ( V_12 -> V_14 ) ;
F_58 ( V_12 -> V_16 ) ;
F_61 () ;
}
static void F_62 ( struct V_57 * V_58 )
{
struct V_59 * V_12 = F_49 ( V_58 ) ;
F_63 ( & V_12 -> V_16 ) ;
F_64 ( & V_12 -> V_14 ) ;
F_65 ( V_58 ) ;
}
static int F_66 ( struct V_64 * V_65 ,
struct V_66 * * V_67 )
{
struct V_68 * V_69 ;
struct V_57 * V_58 ;
struct V_70 * V_14 ;
struct V_71 * V_72 ;
struct V_71 * V_16 ;
struct V_59 * V_12 ;
const char * V_73 ;
int V_3 ;
V_69 = F_67 ( V_67 ) ;
if ( F_51 ( V_69 ) )
return F_52 ( V_69 ) ;
if ( ( V_69 -> type ^ V_74 ) & V_69 -> V_75 )
return - V_8 ;
V_14 = F_68 ( V_67 [ 1 ] , V_76 ,
V_77 ) ;
if ( F_51 ( V_14 ) )
return F_52 ( V_14 ) ;
V_72 = & V_14 -> V_55 ;
V_73 = F_69 ( V_67 [ 2 ] ) ;
V_3 = F_52 ( V_73 ) ;
if ( F_51 ( V_73 ) )
goto V_78;
V_58 = F_70 ( sizeof( * V_58 ) + sizeof( * V_12 ) , V_79 ) ;
V_3 = - V_80 ;
if ( ! V_58 )
goto V_78;
V_12 = F_49 ( V_58 ) ;
V_3 = F_71 ( & V_12 -> V_14 , V_14 ,
F_72 ( V_58 ) ) ;
if ( V_3 )
goto V_81;
F_73 ( & V_12 -> V_16 , F_72 ( V_58 ) ) ;
V_3 = F_74 ( & V_12 -> V_16 , V_73 , 0 ,
F_75 ( V_69 -> type ,
V_69 -> V_75 ) ) ;
if ( V_3 )
goto V_82;
V_16 = F_76 ( & V_12 -> V_16 ) ;
V_3 = - V_83 ;
if ( snprintf ( V_58 -> V_84 . V_55 . V_85 , V_86 ,
L_1 , V_72 -> V_85 ,
V_16 -> V_85 ) >= V_86 )
goto V_87;
if ( snprintf ( V_58 -> V_84 . V_55 . V_88 , V_86 ,
L_1 , V_72 -> V_88 ,
V_16 -> V_88 ) >= V_86 )
goto V_87;
V_58 -> V_84 . V_55 . V_89 = V_16 -> V_89 & V_90 ;
V_58 -> V_84 . V_55 . V_91 = V_16 -> V_91 * 10 +
V_72 -> V_91 ;
V_58 -> V_84 . V_55 . V_92 = V_16 -> V_92 ;
V_58 -> V_84 . V_55 . V_93 = V_72 -> V_93 |
V_16 -> V_93 ;
V_58 -> V_84 . V_55 . V_94 = sizeof( struct V_11 ) ;
V_58 -> V_84 . V_95 = V_16 -> V_96 . V_95 ;
V_58 -> V_84 . V_97 = V_14 -> V_98 ;
V_58 -> V_84 . V_99 = F_47 ;
V_58 -> V_84 . exit = F_60 ;
V_58 -> V_84 . V_100 = F_4 ;
V_58 -> V_84 . V_101 = F_3 ;
V_58 -> V_84 . V_102 = F_36 ;
V_58 -> V_84 . V_103 = F_46 ;
V_58 -> free = F_62 ,
V_3 = F_77 ( V_65 , V_58 ) ;
if ( V_3 )
goto V_87;
V_24:
F_78 ( V_72 ) ;
return V_3 ;
V_87:
F_63 ( & V_12 -> V_16 ) ;
V_82:
F_64 ( & V_12 -> V_14 ) ;
V_81:
F_65 ( V_58 ) ;
V_78:
goto V_24;
}
static int T_3 F_79 ( void )
{
return F_80 ( & V_104 ) ;
}
static void T_4 F_81 ( void )
{
F_82 ( & V_104 ) ;
}
