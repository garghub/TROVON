static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 , unsigned int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_9 ;
T_1 V_10 ;
if ( V_5 & V_11 ) {
F_4 ( ( V_5 & V_12 ) && ( V_5 & V_13 ) ) ;
if ( V_5 & V_12 )
V_8 -> V_14 = V_6 -> V_15 + V_16 ;
else if ( V_5 & V_13 )
V_8 -> V_14 = V_6 -> V_15 + V_17 ;
else
V_8 -> V_14 = V_6 -> V_15 ;
V_10 = F_5 ( V_6 -> V_18 + V_19 ) ;
if ( V_5 & V_20 )
V_10 |= F_6 ( 0 ) ;
else
V_10 &= ~ F_6 ( 0 ) ;
F_7 ( V_10 , V_6 -> V_18 + V_19 ) ;
}
if ( V_4 != V_21 )
F_8 ( V_4 , V_8 -> V_14 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_10 ( V_6 -> V_22 -> V_23 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_24 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 ;
F_7 ( 0 , V_6 -> V_18 + V_25 ) ;
V_10 = F_5 ( V_6 -> V_18 + V_26 ) ;
V_10 |= V_27 ;
V_10 |= V_28 ;
V_10 |= V_29 ;
switch ( V_24 ) {
case V_30 :
V_10 &= ~ V_31 ;
V_6 -> V_32 = true ;
break;
case V_33 :
V_10 |= V_31 ;
V_6 -> V_32 = false ;
break;
default:
break;
}
F_7 ( V_10 , V_6 -> V_18 + V_26 ) ;
}
static int F_12 ( struct V_2 * V_3 , const T_2 * V_4 ,
T_2 * V_34 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 , V_35 ;
int V_36 ;
unsigned int V_37 = 1000 ;
static T_2 V_38 [] = { 0xcd , 0x9d , 0x90 , 0x58 , 0xf4 ,
0x8b , 0xff , 0xb7 , 0x6f } ;
if ( V_6 -> V_32 )
return 0 ;
do {
V_35 = F_5 ( V_6 -> V_18 + V_25 ) ;
} while ( ! ( V_35 & V_39 ) && -- V_37 );
if ( V_37 == 0 )
return - 1 ;
V_10 = F_5 ( V_6 -> V_18 + V_26 ) ;
V_10 &= ~ V_28 ;
F_7 ( V_10 , V_6 -> V_18 + V_26 ) ;
for ( V_36 = 0 ; V_36 < 9 ; ++ V_36 )
V_34 [ V_36 ] = F_13 ( V_6 -> V_18 + V_40 + V_36 ) ;
if ( memcmp ( V_34 , V_38 , 9 ) == 0 )
memset ( V_34 , 0xff , 9 ) ;
return 0 ;
}
static void F_14 ( T_2 * V_4 , int V_41 , int V_42 )
{
int V_43 = V_41 & 0x7 ;
T_3 V_44 ;
V_41 += ( V_41 >> 3 ) ;
V_44 = V_4 [ V_41 ] ;
V_44 |= V_4 [ V_41 + 1 ] << 8 ;
V_42 ^= ( V_44 >> V_43 ) & 0x1ff ;
V_44 &= ~ ( 0x1ff << V_43 ) ;
V_44 |= ( V_42 << V_43 ) ;
V_4 [ V_41 ] = V_44 & 0xff ;
V_4 [ V_41 + 1 ] = ( V_44 >> 8 ) & 0xff ;
}
static int F_15 ( struct V_2 * V_3 , T_2 * V_4 ,
T_2 * V_45 , T_2 * V_46 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_36 , V_47 , V_41 ;
T_1 V_10 , V_35 , error ;
T_1 V_48 ;
unsigned int V_37 = 1000 ;
V_48 = V_45 [ 0 ] ;
if ( V_48 == 0xff ) {
for ( V_36 = 1 ; V_36 < 9 ; ++ V_36 )
V_48 &= V_45 [ V_36 ] ;
V_48 &= V_4 [ 0 ] ;
V_48 &= V_4 [ V_6 -> V_8 . V_49 . V_50 / 2 ] ;
V_48 &= V_4 [ V_6 -> V_8 . V_49 . V_50 - 1 ] ;
if ( V_48 == 0xff ) {
for ( V_36 = 1 ; V_36 < V_6 -> V_8 . V_49 . V_50 - 1 ; ++ V_36 )
V_48 &= V_4 [ V_36 ] ;
if ( V_48 == 0xff )
return 0 ;
}
}
for ( V_36 = 0 ; V_36 < 9 ; ++ V_36 )
F_8 ( V_45 [ V_36 ] , V_6 -> V_18 + V_40 + V_36 ) ;
V_10 = F_5 ( V_6 -> V_18 + V_26 ) ;
V_10 |= V_51 ;
F_7 ( V_10 , V_6 -> V_18 + V_26 ) ;
do {
V_35 = F_5 ( V_6 -> V_18 + V_25 ) ;
} while ( ! ( V_35 & V_52 ) && -- V_37 );
if ( V_37 == 0 )
return - 1 ;
V_10 = F_5 ( V_6 -> V_18 + V_26 ) ;
V_10 &= ~ V_28 ;
F_7 ( V_10 , V_6 -> V_18 + V_26 ) ;
if ( V_35 & V_53 ) {
if ( V_35 & V_54 )
return - 1 ;
V_47 = ( V_35 & V_55 ) >> 29 ;
for ( V_36 = 0 ; V_36 < V_47 ; ++ V_36 ) {
error = F_5 ( V_6 -> V_18 + F_16 ( V_36 ) ) ;
V_41 = ( ( error >> 16 ) & 0x1ff ) - 1 ;
if ( V_41 >= 0 && V_41 < 512 )
F_14 ( V_4 , V_41 , error & 0x1ff ) ;
}
return V_47 ;
}
return 0 ;
}
static int F_17 ( struct V_56 * V_57 ,
const char * V_58 , struct V_59 * * V_60 , void T_4 * * V_18 )
{
int V_61 ;
* V_60 = F_18 ( V_57 , V_62 , V_58 ) ;
if ( ! * V_60 ) {
F_19 ( & V_57 -> V_63 , L_1 , V_58 ) ;
V_61 = - V_64 ;
goto V_65;
}
* V_60 = F_20 ( ( * V_60 ) -> V_66 , F_21 ( * V_60 ) ,
V_57 -> V_58 ) ;
if ( ! * V_60 ) {
F_19 ( & V_57 -> V_63 , L_2 , V_58 ) ;
V_61 = - V_67 ;
goto V_65;
}
* V_18 = F_22 ( ( * V_60 ) -> V_66 , F_21 ( * V_60 ) ) ;
if ( ! * V_18 ) {
F_19 ( & V_57 -> V_63 , L_3 , V_58 ) ;
V_61 = - V_67 ;
goto V_68;
}
return 0 ;
V_68:
F_23 ( ( * V_60 ) -> V_66 , F_21 ( * V_60 ) ) ;
V_65:
* V_60 = NULL ;
* V_18 = NULL ;
return V_61 ;
}
static int T_5 F_24 ( struct V_56 * V_57 )
{
int V_61 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_69 * V_22 = V_57 -> V_63 . V_70 ;
struct V_71 * V_72 ;
int V_73 = 0 ;
V_6 = F_25 ( sizeof( * V_6 ) , V_74 ) ;
if ( ! V_6 ) {
F_19 ( & V_57 -> V_63 , L_4 ) ;
return - V_75 ;
}
V_61 = F_17 ( V_57 , L_5 , & V_6 -> V_76 , & V_6 -> V_18 ) ;
if ( V_61 )
goto V_77;
V_61 = F_17 ( V_57 , L_6 , & V_6 -> V_78 ,
& V_6 -> V_15 ) ;
if ( V_61 )
goto V_79;
if ( V_22 && F_26 ( V_22 -> V_23 ) ) {
V_61 = F_27 ( V_22 -> V_23 , L_7 ) ;
if ( V_61 ) {
F_19 ( & V_57 -> V_63 ,
L_8 ,
V_22 -> V_23 , V_61 ) ;
goto V_80;
}
}
V_3 = & V_6 -> V_3 ;
V_8 = & V_6 -> V_8 ;
V_3 -> V_9 = V_8 ;
V_3 -> V_81 = V_82 ;
V_3 -> V_58 = L_9 ;
V_8 -> V_49 . V_83 = F_11 ;
V_8 -> V_49 . V_84 = F_12 ;
V_8 -> V_49 . V_85 = F_15 ;
V_8 -> V_49 . V_24 = V_86 ;
V_8 -> V_49 . V_50 = 512 ;
V_8 -> V_49 . V_87 = 9 ;
if ( V_22 )
V_8 -> V_49 . V_88 = V_22 -> V_89 ;
V_8 -> V_90 = 50 ;
V_8 -> V_91 = F_3 ;
if ( V_22 && F_26 ( V_22 -> V_23 ) )
V_8 -> V_92 = F_9 ;
V_8 -> V_93 = V_6 -> V_15 ;
V_8 -> V_14 = V_6 -> V_15 ;
V_6 -> V_22 = V_22 ;
F_28 ( V_57 , V_6 ) ;
F_7 ( F_29 ( 0 ) , V_6 -> V_18 + V_19 ) ;
V_61 = F_30 ( V_3 , 1 , NULL ) ;
if ( V_61 ) {
F_19 ( & V_57 -> V_63 , L_10 ) ;
goto V_94;
}
if ( V_22 && V_22 -> V_95 ) {
V_22 -> V_95 ( V_57 , V_8 , & V_22 -> V_96 ,
& V_22 -> V_73 ) ;
}
V_61 = F_31 ( V_3 ) ;
if ( V_61 ) {
F_19 ( & V_57 -> V_63 , L_10 ) ;
goto V_94;
}
#ifdef F_32
V_73 = F_33 ( V_3 , V_97 ,
& V_72 , 0 ) ;
#endif
if ( V_73 <= 0 && V_22 ) {
V_73 = V_22 -> V_73 ;
V_72 = V_22 -> V_96 ;
}
V_61 = F_34 ( V_3 , V_72 , V_73 ) ;
if ( V_61 ) {
F_19 ( & V_57 -> V_63 , L_11 ) ;
goto V_98;
}
F_35 ( & V_57 -> V_63 , L_12 ) ;
return 0 ;
V_98:
F_36 ( & V_6 -> V_3 ) ;
V_94:
F_28 ( V_57 , NULL ) ;
F_37 ( V_22 -> V_23 ) ;
V_80:
F_38 ( V_6 -> V_15 ) ;
V_79:
F_38 ( V_6 -> V_18 ) ;
V_77:
F_39 ( V_6 ) ;
return V_61 ;
}
static int T_6 F_40 ( struct V_56 * V_57 )
{
struct V_1 * V_6 = F_41 ( V_57 ) ;
F_36 ( & V_6 -> V_3 ) ;
F_7 ( 0 , V_6 -> V_18 + V_19 ) ;
F_38 ( V_6 -> V_15 ) ;
F_23 ( V_6 -> V_78 -> V_66 , F_21 ( V_6 -> V_78 ) ) ;
F_38 ( V_6 -> V_18 ) ;
F_23 ( V_6 -> V_76 -> V_66 , F_21 ( V_6 -> V_76 ) ) ;
F_28 ( V_57 , NULL ) ;
F_39 ( V_6 ) ;
return 0 ;
}
static int T_7 F_42 ( void )
{
return F_43 ( & V_99 ) ;
}
static void T_8 F_44 ( void )
{
F_45 ( & V_99 ) ;
}
