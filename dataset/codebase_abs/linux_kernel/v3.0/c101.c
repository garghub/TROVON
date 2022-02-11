static inline T_1 F_1 ( T_2 * V_1 )
{
return V_1 -> V_2 ;
}
static inline void F_2 ( T_2 * V_1 , T_1 V_2 )
{
V_1 -> V_2 = V_2 ;
F_3 ( V_2 , V_1 -> V_3 + V_4 ) ;
}
static inline void F_4 ( T_3 * V_5 )
{
if ( ! ( F_5 ( V_6 + V_7 , V_5 ) & V_8 ) )
F_6 ( F_7 ( V_5 ) ) ;
else
F_8 ( F_7 ( V_5 ) ) ;
}
static void F_9 ( T_3 * V_5 )
{
T_1 V_9 = F_5 ( V_10 + V_11 , V_5 ) ;
F_10 ( V_9 & ( V_12 | V_13 ) , V_10 + V_11 , V_5 ) ;
if ( V_9 & V_12 ) {
F_7 ( V_5 ) -> V_14 . V_15 ++ ;
F_7 ( V_5 ) -> V_14 . V_16 ++ ;
}
V_9 = F_5 ( V_6 + V_11 , V_5 ) ;
F_10 ( V_9 & V_13 , V_6 + V_11 , V_5 ) ;
if ( V_9 & V_13 )
F_4 ( V_5 ) ;
}
static void F_11 ( T_3 * V_5 )
{
T_1 V_17 = V_5 -> V_17 & V_18 ;
T_1 V_19 = V_5 -> V_19 & V_18 ;
switch( V_5 -> V_20 . V_21 ) {
case V_22 :
V_17 |= V_23 ;
V_19 |= V_24 ;
break;
case V_25 :
V_17 |= V_26 ;
V_19 |= V_27 ;
break;
case V_28 :
V_17 |= V_26 ;
V_19 |= V_24 ;
break;
default:
V_17 |= V_26 ;
V_19 |= V_29 ;
}
V_5 -> V_17 = V_17 ;
V_5 -> V_19 = V_19 ;
F_10 ( V_17 , V_6 + V_30 , V_5 ) ;
F_10 ( V_19 , V_6 + V_31 , V_5 ) ;
F_12 ( V_5 ) ;
}
static int F_13 ( struct V_32 * V_33 )
{
T_3 * V_5 = F_14 ( V_33 ) ;
int V_34 ;
V_34 = F_15 ( V_33 ) ;
if ( V_34 )
return V_34 ;
F_3 ( 1 , V_5 -> V_3 + V_35 ) ;
F_10 ( 0 , V_6 + V_36 , V_5 ) ;
F_16 ( V_33 ) ;
F_10 ( V_37 , V_10 + V_38 , V_5 ) ;
F_10 ( V_39 , V_10 + V_40 , V_5 ) ;
F_4 ( V_5 ) ;
F_10 ( V_41 , V_6 + V_38 , V_5 ) ;
F_10 ( V_42 , V_6 + V_40 , V_5 ) ;
F_10 ( 0x48 , V_43 , V_5 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 )
{
T_3 * V_5 = F_14 ( V_33 ) ;
F_18 ( V_33 ) ;
F_3 ( 0 , V_5 -> V_3 + V_35 ) ;
F_10 ( V_44 , V_6 + V_36 , V_5 ) ;
F_19 ( V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 , struct V_45 * V_46 , int V_47 )
{
const T_4 V_48 = sizeof( V_49 ) ;
V_49 V_50 ;
V_49 T_5 * line = V_46 -> V_51 . V_52 . V_53 ;
T_3 * V_5 = F_14 ( V_33 ) ;
#ifdef F_21
if ( V_47 == V_54 ) {
F_22 ( V_33 ) ;
F_23 ( V_55 L_1 ,
F_5 ( V_6 + V_56 , V_5 ) ,
F_5 ( V_6 + V_11 , V_5 ) ,
F_5 ( V_6 + V_57 , V_5 ) ,
F_5 ( V_6 + V_7 , V_5 ) ) ;
return 0 ;
}
#endif
if ( V_47 != V_58 )
return F_24 ( V_33 , V_46 , V_47 ) ;
switch( V_46 -> V_51 . type ) {
case V_59 :
V_46 -> V_51 . type = V_60 ;
if ( V_46 -> V_51 . V_48 < V_48 ) {
V_46 -> V_51 . V_48 = V_48 ;
return - V_61 ;
}
if ( F_25 ( line , & V_5 -> V_20 , V_48 ) )
return - V_62 ;
return 0 ;
case V_60 :
if( ! F_26 ( V_63 ) )
return - V_64 ;
if ( F_27 ( & V_50 , line , V_48 ) )
return - V_62 ;
if ( V_50 . V_21 != V_65 &&
V_50 . V_21 != V_28 &&
V_50 . V_21 != V_22 &&
V_50 . V_21 != V_25 )
return - V_66 ;
if ( V_50 . V_67 != 0 && V_50 . V_67 != 1 )
return - V_66 ;
memcpy ( & V_5 -> V_20 , & V_50 , V_48 ) ;
F_11 ( V_5 ) ;
return 0 ;
default:
return F_24 ( V_33 , V_46 , V_47 ) ;
}
}
static void F_28 ( T_2 * V_1 )
{
F_29 ( V_1 -> V_3 + V_4 ) ;
if ( V_1 -> V_68 )
F_30 ( V_1 -> V_68 , V_1 ) ;
if ( V_1 -> V_3 ) {
F_31 ( V_1 -> V_3 ) ;
F_32 ( V_1 -> V_69 , V_70 ) ;
}
F_33 ( V_1 -> V_33 ) ;
F_34 ( V_1 ) ;
}
static int T_6 F_35 ( unsigned long V_68 , unsigned long V_71 )
{
struct V_32 * V_33 ;
T_7 * V_72 ;
T_2 * V_1 ;
int V_34 ;
if ( V_68 < 3 || V_68 > 15 || V_68 == 6 ) {
F_23 ( V_73 L_2 ) ;
return - V_74 ;
}
if ( V_71 < 0xC0000 || V_71 > 0xDFFFF || ( V_71 & 0x3FFF ) != 0 ) {
F_23 ( V_73 L_3 ) ;
return - V_74 ;
}
V_1 = F_36 ( sizeof( T_2 ) , V_75 ) ;
if ( V_1 == NULL ) {
F_23 ( V_73 L_4 ) ;
return - V_61 ;
}
V_1 -> V_33 = F_37 ( V_1 ) ;
if ( ! V_1 -> V_33 ) {
F_23 ( V_73 L_4 ) ;
F_34 ( V_1 ) ;
return - V_61 ;
}
if ( F_38 ( V_68 , V_76 , 0 , V_77 , V_1 ) ) {
F_23 ( V_73 L_5 ) ;
F_28 ( V_1 ) ;
return - V_78 ;
}
V_1 -> V_68 = V_68 ;
if ( ! F_39 ( V_71 , V_70 , V_77 ) ) {
F_23 ( V_73 L_6 ) ;
F_28 ( V_1 ) ;
return - V_78 ;
}
V_1 -> V_69 = V_71 ;
V_1 -> V_3 = F_40 ( V_71 , V_70 ) ;
if ( ! V_1 -> V_3 ) {
F_23 ( V_73 L_7 ) ;
F_28 ( V_1 ) ;
return - V_62 ;
}
V_1 -> V_79 = V_80 ;
V_1 -> V_81 = V_82 ;
V_1 -> V_83 = V_84 ;
F_29 ( V_1 -> V_3 + V_4 ) ;
F_41 ( 100 ) ;
F_3 ( 0 , V_1 -> V_3 + V_4 ) ;
F_3 ( 0 , V_1 -> V_3 + V_35 ) ;
F_42 ( V_1 , 0 ) ;
V_33 = F_7 ( V_1 ) ;
V_72 = F_43 ( V_33 ) ;
F_44 ( & V_1 -> V_85 ) ;
V_33 -> V_68 = V_68 ;
V_33 -> V_86 = V_71 ;
V_33 -> V_87 = V_71 + V_70 - 1 ;
V_33 -> V_88 = 50 ;
V_33 -> V_89 = & V_90 ;
V_72 -> V_91 = V_92 ;
V_72 -> V_93 = V_94 ;
V_1 -> V_20 . V_21 = V_65 ;
V_34 = F_45 ( V_33 ) ;
if ( V_34 ) {
F_23 ( V_95 L_8 ) ;
F_28 ( V_1 ) ;
return V_34 ;
}
F_46 ( V_1 ) ;
F_4 ( V_1 ) ;
F_23 ( V_96 L_9
L_10 ,
V_33 -> V_97 , V_1 -> V_68 ,
V_1 -> V_79 , V_1 -> V_81 ) ;
* V_98 = V_1 ;
V_98 = & V_1 -> V_99 ;
return 0 ;
}
static int T_6 F_47 ( void )
{
if ( V_100 == NULL ) {
#ifdef F_48
F_23 ( V_96 L_11 ) ;
#endif
return - V_66 ;
}
F_23 ( V_96 L_12 , V_101 ) ;
do {
unsigned long V_68 , V_102 ;
V_68 = F_49 ( V_100 , & V_100 , 0 ) ;
if ( * V_100 ++ != ',' )
break;
V_102 = F_49 ( V_100 , & V_100 , 0 ) ;
if ( * V_100 == ':' || * V_100 == '\x0' )
F_35 ( V_68 , V_102 ) ;
if ( * V_100 == '\x0' )
return V_103 ? 0 : - V_66 ;
}while( * V_100 ++ == ':' );
F_23 ( V_73 L_13 ) ;
return V_103 ? 0 : - V_66 ;
}
static void T_8 F_50 ( void )
{
T_2 * V_1 = V_103 ;
while ( V_1 ) {
T_2 * V_104 = V_1 ;
V_1 = V_1 -> V_99 ;
F_51 ( F_7 ( V_104 ) ) ;
F_28 ( V_104 ) ;
}
}
