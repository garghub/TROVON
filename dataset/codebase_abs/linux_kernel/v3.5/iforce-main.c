static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 [ V_3 ] ;
if ( V_4 > 0 )
F_3 ( V_9 , V_7 -> V_10 ) ;
else
F_4 ( V_9 , V_7 -> V_10 ) ;
F_5 ( V_5 , V_3 , V_4 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_12 [ 3 ] ;
V_12 [ 0 ] = V_11 >> 9 ;
F_7 ( V_5 , V_13 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_12 [ 3 ] ;
V_12 [ 0 ] = 0x03 ;
V_12 [ 1 ] = V_14 >> 9 ;
F_7 ( V_5 , V_15 , V_12 ) ;
V_12 [ 0 ] = 0x04 ;
V_12 [ 1 ] = 0x01 ;
F_7 ( V_5 , V_15 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_16 * V_17 , struct V_16 * V_18 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 [ V_17 -> V_19 ] ;
int V_20 ;
if ( F_10 ( V_21 , V_7 -> V_10 ) ) {
if ( F_11 ( V_22 , V_7 -> V_10 ) )
return - V_23 ;
}
switch ( V_17 -> type ) {
case V_24 :
V_20 = F_12 ( V_5 , V_17 , V_18 ) ;
break;
case V_25 :
V_20 = F_13 ( V_5 , V_17 , V_18 ) ;
break;
case V_26 :
case V_27 :
V_20 = F_14 ( V_5 , V_17 , V_18 ) ;
break;
default:
return - V_28 ;
}
if ( V_20 == 0 ) {
F_3 ( V_22 , V_7 -> V_10 ) ;
}
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 [ V_3 ] ;
int V_29 = 0 ;
if ( F_11 ( V_30 , V_7 -> V_10 ) )
V_29 = F_16 ( & V_7 -> V_31 ) ;
if ( ! V_29 && F_11 ( V_32 , V_7 -> V_10 ) )
V_29 = F_16 ( & V_7 -> V_33 ) ;
V_7 -> V_10 [ 0 ] = 0 ;
return V_29 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_34 ) {
#ifdef F_18
case V_35 :
V_5 -> V_36 -> V_2 = V_5 -> V_37 ;
if ( F_19 ( V_5 -> V_36 , V_38 ) )
return - V_39 ;
break;
#endif
}
if ( F_11 ( V_40 , V_2 -> V_41 ) ) {
F_7 ( V_5 , V_42 , L_1 ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_43 ;
if ( F_11 ( V_40 , V_2 -> V_41 ) ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_44 -> V_45 ; V_43 ++ ) {
if ( F_11 ( V_21 , V_5 -> V_8 [ V_43 ] . V_10 ) ) {
F_21 ( & V_2 -> V_2 ,
L_2 ,
V_46 ) ;
break;
}
}
F_7 ( V_5 , V_42 , L_3 ) ;
F_22 ( V_5 -> V_47 ,
! F_11 ( V_48 , V_5 -> V_49 ) ) ;
}
switch ( V_5 -> V_34 ) {
#ifdef F_18
case V_35 :
F_23 ( V_5 -> V_36 ) ;
F_23 ( V_5 -> V_50 ) ;
F_23 ( V_5 -> V_51 ) ;
break;
#endif
#ifdef F_24
case V_52 :
break;
#endif
}
}
int F_25 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
struct V_53 * V_44 ;
unsigned char V_54 [] = L_4 ;
int V_43 , error ;
int V_55 = 0 ;
V_1 = F_26 () ;
if ( ! V_1 )
return - V_56 ;
F_27 ( & V_5 -> V_47 ) ;
F_28 ( & V_5 -> V_57 ) ;
F_29 ( & V_5 -> V_58 ) ;
V_5 -> V_59 . V_60 = V_5 -> V_61 ;
V_5 -> V_2 = V_1 ;
switch ( V_5 -> V_34 ) {
#ifdef F_18
case V_35 :
V_1 -> V_19 . V_62 = V_63 ;
V_1 -> V_2 . V_64 = & V_5 -> V_37 -> V_2 ;
break;
#endif
#ifdef F_24
case V_52 :
V_1 -> V_19 . V_62 = V_65 ;
V_1 -> V_2 . V_64 = & V_5 -> V_66 -> V_2 ;
break;
#endif
}
F_30 ( V_1 , V_5 ) ;
V_1 -> V_67 = L_5 ;
V_1 -> V_68 = F_17 ;
V_1 -> V_69 = F_20 ;
V_5 -> V_70 . V_67 = L_6 ;
V_5 -> V_70 . V_71 = 0 ;
V_5 -> V_70 . V_72 = 200 ;
V_5 -> V_70 . V_10 = V_73 ;
V_5 -> V_70 . V_64 = NULL ;
V_5 -> V_70 . V_74 = NULL ;
V_5 -> V_70 . V_75 = NULL ;
for ( V_43 = 0 ; V_43 < 20 ; V_43 ++ )
if ( ! F_31 ( V_5 , L_7 ) )
break;
if ( V_43 == 20 ) {
F_32 ( & V_1 -> V_2 ,
L_8 ) ;
error = - V_76 ;
goto V_77;
}
if ( ! F_31 ( V_5 , L_9 ) )
V_1 -> V_19 . V_78 = ( V_5 -> V_79 [ 2 ] << 8 ) | V_5 -> V_79 [ 1 ] ;
else
F_21 ( & V_5 -> V_2 -> V_2 , L_10 ) ;
if ( ! F_31 ( V_5 , L_11 ) )
V_1 -> V_19 . V_80 = ( V_5 -> V_79 [ 2 ] << 8 ) | V_5 -> V_79 [ 1 ] ;
else
F_21 ( & V_5 -> V_2 -> V_2 , L_12 ) ;
if ( ! F_31 ( V_5 , L_13 ) )
V_5 -> V_70 . V_72 = ( V_5 -> V_79 [ 2 ] << 8 ) | V_5 -> V_79 [ 1 ] ;
else
F_21 ( & V_5 -> V_2 -> V_2 , L_14 ) ;
if ( ! F_31 ( V_5 , L_15 ) )
V_55 = V_5 -> V_79 [ 1 ] ;
else
F_21 ( & V_5 -> V_2 -> V_2 , L_16 ) ;
if ( V_55 > V_81 ) {
F_21 ( & V_5 -> V_2 -> V_2 , L_17 ,
V_81 , V_55 ) ;
V_55 = V_81 ;
}
for ( V_43 = 0 ; V_54 [ V_43 ] ; V_43 ++ )
if ( ! F_31 ( V_5 , V_54 + V_43 ) )
F_33 ( L_18 , V_5 -> V_82 , V_5 -> V_79 ) ;
F_8 ( V_1 , 0 ) ;
for ( V_43 = 0 ; V_83 [ V_43 ] . V_84 ; V_43 ++ )
if ( V_83 [ V_43 ] . V_84 == V_1 -> V_19 . V_78 &&
V_83 [ V_43 ] . V_85 == V_1 -> V_19 . V_80 )
break;
V_5 -> type = V_83 + V_43 ;
V_1 -> V_67 = V_5 -> type -> V_67 ;
V_1 -> V_41 [ 0 ] = F_34 ( V_86 ) | F_34 ( V_87 ) |
F_34 ( V_88 ) ;
for ( V_43 = 0 ; V_5 -> type -> V_89 [ V_43 ] >= 0 ; V_43 ++ )
F_3 ( V_5 -> type -> V_89 [ V_43 ] , V_1 -> V_90 ) ;
F_3 ( V_91 , V_1 -> V_90 ) ;
for ( V_43 = 0 ; V_5 -> type -> abs [ V_43 ] >= 0 ; V_43 ++ ) {
signed short V_92 = V_5 -> type -> abs [ V_43 ] ;
switch ( V_92 ) {
case V_93 :
case V_94 :
case V_95 :
F_35 ( V_1 , V_92 , - 1920 , 1920 , 16 , 128 ) ;
F_3 ( V_92 , V_1 -> V_96 ) ;
break;
case V_97 :
case V_98 :
case V_99 :
F_35 ( V_1 , V_92 , 0 , 255 , 0 , 0 ) ;
break;
case V_100 :
F_35 ( V_1 , V_92 , - 128 , 127 , 0 , 0 ) ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
F_35 ( V_1 , V_92 , - 1 , 1 , 0 , 0 ) ;
break;
}
}
if ( V_55 ) {
for ( V_43 = 0 ; V_5 -> type -> V_44 [ V_43 ] >= 0 ; V_43 ++ )
F_3 ( V_5 -> type -> V_44 [ V_43 ] , V_1 -> V_96 ) ;
error = F_36 ( V_1 , V_55 ) ;
if ( error )
goto V_77;
V_44 = V_1 -> V_44 ;
V_44 -> V_105 = F_9 ;
V_44 -> V_106 = F_15 ;
V_44 -> V_107 = F_6 ;
V_44 -> V_108 = F_8 ;
V_44 -> V_109 = F_1 ;
}
error = F_37 ( V_5 -> V_2 ) ;
if ( error )
goto V_77;
return 0 ;
V_77: F_38 ( V_1 ) ;
return error ;
}
static int T_2 F_39 ( void )
{
int V_29 = 0 ;
#ifdef F_18
V_29 = F_40 ( & V_110 ) ;
if ( V_29 )
return V_29 ;
#endif
#ifdef F_24
V_29 = F_41 ( & V_111 ) ;
#ifdef F_18
if ( V_29 )
F_42 ( & V_110 ) ;
#endif
#endif
return V_29 ;
}
static void T_3 F_43 ( void )
{
#ifdef F_18
F_42 ( & V_110 ) ;
#endif
#ifdef F_24
F_44 ( & V_111 ) ;
#endif
}
