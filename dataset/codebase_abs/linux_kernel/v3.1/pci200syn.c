static inline void F_1 ( char T_1 * V_1 , char * V_2 , int V_3 )
{
int V_4 ;
do {
V_4 = V_3 > 256 ? 256 : V_3 ;
F_2 ( V_1 , V_2 , V_4 ) ;
V_1 += V_4 ;
V_2 += V_4 ;
V_3 -= V_4 ;
F_3 ( V_1 ) ;
} while ( V_4 );
}
static void F_4 ( T_2 * V_5 )
{
T_3 * V_6 = V_5 -> V_6 ;
T_4 V_7 = F_5 ( V_5 ) ;
T_5 V_8 = V_5 -> V_8 & V_9 ;
T_5 V_10 = V_5 -> V_10 & V_9 ;
F_6 ( V_11 , ( V_5 -> V_12 ? V_13 : V_14 ) + V_15 ,
V_5 -> V_6 ) ;
switch( V_5 -> V_16 . V_17 ) {
case V_18 :
V_8 |= V_19 ;
V_10 |= V_20 | V_21 ;
break;
case V_22 :
V_8 |= V_23 ;
V_10 |= V_20 | V_19 ;
break;
case V_24 :
V_8 |= V_23 ;
V_10 |= V_20 | V_21 ;
break;
default:
V_8 |= V_23 ;
V_10 |= V_20 | V_23 ;
break;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_10 = V_10 ;
F_6 ( V_8 , V_7 + V_25 , V_6 ) ;
F_6 ( V_10 , V_7 + V_26 , V_6 ) ;
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_27 * V_28 )
{
T_2 * V_5 = F_9 ( V_28 ) ;
int V_29 = F_10 ( V_28 ) ;
if ( V_29 )
return V_29 ;
F_11 ( V_28 ) ;
F_4 ( V_5 ) ;
F_12 ( V_5 -> V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_27 * V_28 )
{
F_14 ( V_28 ) ;
F_12 ( F_9 ( V_28 ) -> V_6 ) ;
F_15 ( V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_27 * V_28 , struct V_30 * V_31 , int V_32 )
{
const T_6 V_33 = sizeof( V_34 ) ;
V_34 V_35 ;
V_34 T_7 * line = V_31 -> V_36 . V_37 . V_38 ;
T_2 * V_5 = F_9 ( V_28 ) ;
#ifdef F_17
if ( V_32 == V_39 ) {
F_18 ( V_28 ) ;
return 0 ;
}
#endif
if ( V_32 != V_40 )
return F_19 ( V_28 , V_31 , V_32 ) ;
switch( V_31 -> V_36 . type ) {
case V_41 :
V_31 -> V_36 . type = V_42 ;
if ( V_31 -> V_36 . V_33 < V_33 ) {
V_31 -> V_36 . V_33 = V_33 ;
return - V_43 ;
}
if ( F_20 ( line , & V_5 -> V_16 , V_33 ) )
return - V_44 ;
return 0 ;
case V_42 :
case V_45 :
if ( ! F_21 ( V_46 ) )
return - V_47 ;
if ( F_22 ( & V_35 , line , V_33 ) )
return - V_44 ;
if ( V_35 . V_17 != V_48 &&
V_35 . V_17 != V_24 &&
V_35 . V_17 != V_18 &&
V_35 . V_17 != V_22 )
return - V_49 ;
if ( V_35 . V_50 != 0 && V_35 . V_50 != 1 )
return - V_49 ;
memcpy ( & V_5 -> V_16 , & V_35 , V_33 ) ;
F_4 ( V_5 ) ;
F_12 ( V_5 -> V_6 ) ;
return 0 ;
default:
return F_19 ( V_28 , V_31 , V_32 ) ;
}
}
static void F_23 ( struct V_51 * V_52 )
{
int V_53 ;
T_3 * V_6 = F_24 ( V_52 ) ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ )
if ( V_6 -> V_54 [ V_53 ] . V_6 )
F_25 ( V_6 -> V_54 [ V_53 ] . V_55 ) ;
if ( V_6 -> V_56 )
F_26 ( V_6 -> V_56 , V_6 ) ;
if ( V_6 -> V_57 )
F_27 ( V_6 -> V_57 ) ;
if ( V_6 -> V_58 )
F_27 ( V_6 -> V_58 ) ;
if ( V_6 -> V_59 )
F_27 ( V_6 -> V_59 ) ;
F_28 ( V_52 ) ;
F_29 ( V_52 ) ;
F_30 ( V_52 , NULL ) ;
if ( V_6 -> V_54 [ 0 ] . V_55 )
F_31 ( V_6 -> V_54 [ 0 ] . V_55 ) ;
if ( V_6 -> V_54 [ 1 ] . V_55 )
F_31 ( V_6 -> V_54 [ 1 ] . V_55 ) ;
F_32 ( V_6 ) ;
}
static int T_8 F_33 ( struct V_51 * V_52 ,
const struct V_60 * V_61 )
{
T_3 * V_6 ;
T_9 T_1 * V_62 ;
int V_53 ;
T_9 V_63 ;
T_9 V_64 ;
T_9 V_65 ;
T_9 V_66 ;
V_53 = F_34 ( V_52 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_35 ( V_52 , L_1 ) ;
if ( V_53 ) {
F_29 ( V_52 ) ;
return V_53 ;
}
V_6 = F_36 ( sizeof( T_3 ) , V_67 ) ;
if ( V_6 == NULL ) {
F_37 ( L_2 ) ;
F_28 ( V_52 ) ;
F_29 ( V_52 ) ;
return - V_43 ;
}
F_30 ( V_52 , V_6 ) ;
V_6 -> V_54 [ 0 ] . V_55 = F_38 ( & V_6 -> V_54 [ 0 ] ) ;
V_6 -> V_54 [ 1 ] . V_55 = F_38 ( & V_6 -> V_54 [ 1 ] ) ;
if ( ! V_6 -> V_54 [ 0 ] . V_55 || ! V_6 -> V_54 [ 1 ] . V_55 ) {
F_37 ( L_2 ) ;
F_23 ( V_52 ) ;
return - V_68 ;
}
if ( F_39 ( V_52 , 0 ) != V_69 ||
F_39 ( V_52 , 2 ) != V_70 ||
F_39 ( V_52 , 3 ) < 16384 ) {
F_37 ( L_3 ) ;
F_23 ( V_52 ) ;
return - V_44 ;
}
V_66 = F_40 ( V_52 , 0 ) & V_71 ;
V_6 -> V_59 = F_41 ( V_66 , V_69 ) ;
V_65 = F_40 ( V_52 , 2 ) & V_71 ;
V_6 -> V_58 = F_41 ( V_65 , V_70 ) ;
V_64 = F_40 ( V_52 , 3 ) & V_71 ;
V_6 -> V_57 = F_42 ( V_52 , 3 ) ;
if ( V_6 -> V_59 == NULL ||
V_6 -> V_58 == NULL ||
V_6 -> V_57 == NULL ) {
F_37 ( L_4 ) ;
F_23 ( V_52 ) ;
return - V_44 ;
}
V_62 = & V_6 -> V_59 -> V_72 ;
F_43 ( F_44 ( V_62 ) | 0x40000000 , V_62 ) ;
F_44 ( V_62 ) ;
F_45 ( 1 ) ;
F_43 ( F_44 ( V_62 ) & ~ 0x40000000 , V_62 ) ;
F_44 ( V_62 ) ;
F_45 ( 1 ) ;
V_63 = F_46 ( V_6 , V_6 -> V_57 ,
F_39 ( V_52 , 3 ) ) ;
V_53 = V_63 / ( 2 * ( sizeof( V_73 ) + V_74 ) ) ;
V_6 -> V_75 = F_47 ( V_53 / 2 , V_76 ) ;
V_6 -> V_77 = V_53 - V_6 -> V_75 ;
V_6 -> V_78 = 2 * sizeof( V_73 ) * ( V_6 -> V_75 +
V_6 -> V_77 ) ;
F_48 ( L_5 ,
V_63 / 1024 , V_64 ,
V_52 -> V_56 , V_6 -> V_75 , V_6 -> V_77 ) ;
if ( V_6 -> V_75 < 1 ) {
F_37 ( L_6 ) ;
F_23 ( V_52 ) ;
return - V_44 ;
}
V_62 = & V_6 -> V_59 -> V_79 ;
F_49 ( F_50 ( V_62 ) | 0x0040 , V_62 ) ;
if ( F_51 ( V_52 -> V_56 , V_80 , V_81 , L_7 , V_6 ) ) {
F_52 ( L_8 , V_52 -> V_56 ) ;
F_23 ( V_52 ) ;
return - V_82 ;
}
V_6 -> V_56 = V_52 -> V_56 ;
F_53 ( V_6 , 0 ) ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
T_2 * V_5 = & V_6 -> V_54 [ V_53 ] ;
struct V_27 * V_28 = V_5 -> V_55 ;
T_10 * V_83 = F_54 ( V_28 ) ;
V_5 -> V_12 = V_53 ;
F_55 ( & V_5 -> V_84 ) ;
V_28 -> V_56 = V_6 -> V_56 ;
V_28 -> V_85 = V_64 ;
V_28 -> V_86 = V_64 + V_63 - 1 ;
V_28 -> V_87 = 50 ;
V_28 -> V_88 = & V_89 ;
V_83 -> V_90 = V_91 ;
V_83 -> V_92 = V_93 ;
V_5 -> V_16 . V_17 = V_48 ;
V_5 -> V_6 = V_6 ;
F_56 ( V_5 ) ;
if ( F_57 ( V_28 ) ) {
F_37 ( L_9 ) ;
V_5 -> V_6 = NULL ;
F_23 ( V_52 ) ;
return - V_43 ;
}
F_58 ( V_28 , L_10 , V_5 -> V_12 ) ;
}
F_12 ( V_6 ) ;
return 0 ;
}
static int T_11 F_59 ( void )
{
if ( V_94 < 1000000 || V_94 > 80000000 ) {
F_37 ( L_11 ) ;
return - V_49 ;
}
return F_60 ( & V_95 ) ;
}
static void T_12 F_61 ( void )
{
F_62 ( & V_95 ) ;
}
