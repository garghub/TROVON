static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , L_1 , V_3 ) ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 ++ ;
V_2 -> V_8 = 0 ;
if ( V_3 )
V_2 -> V_7 = V_3 ;
F_3 ( & V_2 -> V_9 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
V_10 = F_5 ( V_2 -> V_11 + V_12 ) ;
F_6 ( V_10 & ~ V_13 , V_2 -> V_11 + V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
V_10 = F_5 ( V_2 -> V_11 + V_12 ) ;
F_6 ( V_10 | V_13 , V_2 -> V_11 + V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_6 )
{
unsigned int V_15 = ( V_6 -> V_15 & 0x7f ) << 1 ;
if ( V_6 -> V_16 & V_17 )
V_15 |= 0x1 ;
F_6 ( V_15 & 0xff , V_2 -> V_11 + V_18 ) ;
F_6 ( V_19 | V_20 , V_2 -> V_11 + V_21 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , L_2 ) ;
V_2 -> V_22 = V_23 ;
F_6 ( V_24 , V_2 -> V_11 + V_21 ) ;
F_1 ( V_2 , V_3 ) ;
F_4 ( V_2 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_7 >= ( V_2 -> V_8 - 1 ) ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_2 -> V_6 -> V_25 - 1 ;
}
static inline int F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_5 >= V_2 -> V_6 -> V_25 ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
unsigned char V_27 ;
switch ( V_2 -> V_22 ) {
case V_28 :
F_14 ( V_2 -> V_4 , L_3 , V_29 ) ;
break;
case V_23 :
F_14 ( V_2 -> V_4 , L_4 , V_29 ) ;
F_4 ( V_2 ) ;
break;
case V_30 :
if ( V_26 & V_31 &&
! ( V_2 -> V_6 -> V_16 & V_32 ) ) {
F_2 ( V_2 -> V_4 , L_5 ) ;
F_9 ( V_2 , - V_33 ) ;
break;
}
if ( V_2 -> V_6 -> V_16 & V_17 )
V_2 -> V_22 = V_34 ;
else
V_2 -> V_22 = V_35 ;
if ( F_10 ( V_2 ) && V_2 -> V_6 -> V_25 == 0 ) {
F_9 ( V_2 , 0 ) ;
break;
}
if ( V_2 -> V_22 == V_34 )
goto V_36;
case V_35 :
if ( ! ( V_2 -> V_6 -> V_16 & V_32 ) ) {
if ( V_26 & V_31 ) {
F_2 ( V_2 -> V_4 , L_6 ) ;
F_9 ( V_2 , - V_37 ) ;
break;
}
}
V_38:
if ( ! F_12 ( V_2 ) ) {
V_27 = V_2 -> V_6 -> V_39 [ V_2 -> V_5 ++ ] ;
F_15 ( V_27 , V_2 -> V_11 + V_18 ) ;
F_6 ( V_20 , V_2 -> V_11 + V_21 ) ;
} else if ( ! F_10 ( V_2 ) ) {
F_2 ( V_2 -> V_4 , L_7 ) ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 ++ ;
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 -> V_16 & V_40 ) {
if ( V_2 -> V_6 -> V_16 & V_17 ) {
F_9 ( V_2 , - V_41 ) ;
}
goto V_38;
} else {
F_8 ( V_2 , V_2 -> V_6 ) ;
V_2 -> V_22 = V_30 ;
}
} else {
F_9 ( V_2 , 0 ) ;
}
break;
case V_34 :
V_27 = F_16 ( V_2 -> V_11 + V_42 ) ;
V_2 -> V_6 -> V_39 [ V_2 -> V_5 ++ ] = V_27 ;
V_36:
if ( F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
F_6 ( V_43 | V_44 ,
V_2 -> V_11 + V_21 ) ;
} else if ( F_12 ( V_2 ) ) {
if ( F_10 ( V_2 ) ) {
F_2 ( V_2 -> V_4 , L_8 ) ;
F_9 ( V_2 , 0 ) ;
} else {
F_2 ( V_2 -> V_4 , L_9 ) ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 ++ ;
V_2 -> V_6 ++ ;
F_6 ( V_43 , V_2 -> V_11 + V_21 ) ;
}
} else {
F_6 ( V_43 , V_2 -> V_11 + V_21 ) ;
}
break;
}
}
static T_1 F_17 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
unsigned long V_47 ;
V_47 = F_5 ( V_2 -> V_11 + V_12 ) ;
F_6 ( V_47 | V_48 , V_2 -> V_11 + V_12 ) ;
if ( V_47 & V_49 ) {
F_14 ( V_2 -> V_4 , L_10 ) ;
goto V_50;
}
if ( V_2 -> V_22 == V_28 ) {
F_2 ( V_2 -> V_4 , L_11 ) ;
goto V_50;
}
F_13 ( V_2 , V_47 ) ;
V_50:
return V_51 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_52 = 400 ;
while ( V_52 -- > 0 ) {
if ( ( ( F_5 ( V_2 -> V_11 + V_53 ) & V_54 ) == V_54 ) &&
( ( F_5 ( V_2 -> V_11 + V_12 ) & V_55 ) == 0 ) ) {
return 0 ;
}
F_19 ( 1 ) ;
}
return - V_56 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_14 * V_57 , int V_58 )
{
unsigned long V_26 , V_52 ;
int V_59 = 20 ;
int V_3 ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 != 0 ) {
F_14 ( V_2 -> V_4 , L_12 , V_3 ) ;
V_3 = - V_60 ;
goto V_50;
}
F_21 ( & V_2 -> V_61 ) ;
V_2 -> V_6 = V_57 ;
V_2 -> V_8 = V_58 ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_22 = V_30 ;
F_8 ( V_2 , V_57 ) ;
F_22 ( & V_2 -> V_61 ) ;
V_52 = F_23 ( V_2 -> V_9 , V_2 -> V_8 == 0 , V_62 * 5 ) ;
V_3 = V_2 -> V_7 ;
if ( V_52 == 0 )
F_2 ( V_2 -> V_4 , L_13 ) ;
else if ( V_3 != V_58 )
F_2 ( V_2 -> V_4 , L_14 , V_3 ) ;
F_2 ( V_2 -> V_4 , L_15 ) ;
do {
V_26 = F_5 ( V_2 -> V_11 + V_12 ) ;
} while ( ( V_26 & V_55 ) && -- V_59 );
if ( ! V_59 ) {
F_19 ( 1 ) ;
V_26 = F_5 ( V_2 -> V_11 + V_12 ) ;
}
if ( V_26 & V_55 )
F_24 ( V_2 -> V_4 , L_16 ) ;
V_50:
return V_3 ;
}
static int F_25 ( struct V_63 * V_64 ,
struct V_14 * V_57 , int V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_65 ;
int V_66 ;
int V_3 ;
F_7 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_64 -> V_67 ; V_66 ++ ) {
V_3 = F_20 ( V_2 , V_57 , V_58 ) ;
if ( V_3 != - V_60 )
return V_3 ;
F_2 ( V_2 -> V_4 , L_17 , V_66 ) ;
F_26 ( 100 ) ;
}
return - V_68 ;
}
static T_2 F_27 ( struct V_63 * V_64 )
{
return V_69 | V_70 | V_71 ;
}
static int T_3 F_28 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
int V_3 ;
V_75 = V_73 -> V_4 . V_78 ;
if ( ! V_75 ) {
F_14 ( & V_73 -> V_4 , L_18 ) ;
return - V_41 ;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_2 ) {
F_14 ( & V_73 -> V_4 , L_19 ) ;
return - V_80 ;
}
F_30 ( V_2 -> V_64 . V_81 , L_20 , sizeof( V_2 -> V_64 . V_81 ) ) ;
V_2 -> V_64 . V_82 = V_83 ;
V_2 -> V_64 . V_84 = & V_85 ;
V_2 -> V_64 . V_67 = 2 ;
V_2 -> V_64 . V_86 = V_87 | V_88 ;
F_31 ( & V_2 -> V_61 ) ;
F_32 ( & V_2 -> V_9 ) ;
V_2 -> V_4 = & V_73 -> V_4 ;
V_2 -> V_89 = F_33 ( & V_73 -> V_4 , NULL ) ;
if ( F_34 ( V_2 -> V_89 ) ) {
F_14 ( & V_73 -> V_4 , L_21 ) ;
V_3 = - V_90 ;
goto V_91;
}
F_2 ( & V_73 -> V_4 , L_22 , V_2 -> V_89 ) ;
F_35 ( V_2 -> V_89 ) ;
V_77 = F_36 ( V_73 , V_92 , 0 ) ;
if ( V_77 == NULL ) {
F_14 ( & V_73 -> V_4 , L_23 ) ;
V_3 = - V_90 ;
goto V_93;
}
V_2 -> V_94 = F_37 ( V_77 -> V_95 , F_38 ( V_77 ) ,
V_73 -> V_81 ) ;
if ( V_2 -> V_94 == NULL ) {
F_14 ( & V_73 -> V_4 , L_24 ) ;
V_3 = - V_33 ;
goto V_93;
}
V_2 -> V_11 = F_39 ( V_77 -> V_95 , F_38 ( V_77 ) ) ;
if ( V_2 -> V_11 == NULL ) {
F_14 ( & V_73 -> V_4 , L_25 ) ;
V_3 = - V_33 ;
goto V_96;
}
F_2 ( & V_73 -> V_4 , L_26 ,
V_2 -> V_11 , V_2 -> V_94 , V_77 ) ;
V_2 -> V_64 . V_65 = V_2 ;
V_2 -> V_64 . V_4 . V_97 = & V_73 -> V_4 ;
F_40 ( & V_73 -> V_4 ) ;
F_41 ( V_2 -> V_89 ) ;
V_3 = ( V_2 -> V_89 . V_98 ) / ( V_75 -> V_99 * 5 ) - 1 ;
F_6 ( V_3 & 0xffff , V_2 -> V_11 + V_100 ) ;
V_2 -> V_101 = V_3 = F_42 ( V_73 , 0 ) ;
if ( V_3 <= 0 ) {
F_14 ( & V_73 -> V_4 , L_27 ) ;
goto V_102;
}
V_3 = F_43 ( V_2 -> V_101 , F_17 , V_103 | V_104 ,
F_44 ( & V_73 -> V_4 ) , V_2 ) ;
if ( V_3 != 0 ) {
F_14 ( & V_73 -> V_4 , L_28 , V_2 -> V_101 ) ;
goto V_102;
}
V_2 -> V_64 . V_105 = V_75 -> V_106 ;
V_3 = F_45 ( & V_2 -> V_64 ) ;
if ( V_3 < 0 ) {
F_14 ( & V_73 -> V_4 , L_29 ) ;
goto V_107;
}
F_46 ( V_73 , V_2 ) ;
F_47 ( & V_73 -> V_4 , L_30 ,
F_44 ( & V_2 -> V_64 . V_4 ) ) ;
return 0 ;
V_107:
F_48 ( V_2 -> V_101 , V_2 ) ;
V_102:
F_49 ( V_2 -> V_11 ) ;
V_96:
F_50 ( V_2 -> V_94 ) ;
F_51 ( V_2 -> V_94 ) ;
V_93:
F_52 ( V_2 -> V_89 ) ;
F_53 ( V_2 -> V_89 ) ;
V_91:
F_51 ( V_2 ) ;
return V_3 ;
}
static int T_4 F_54 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_55 ( V_73 ) ;
F_56 ( & V_2 -> V_64 ) ;
F_48 ( V_2 -> V_101 , V_2 ) ;
F_52 ( V_2 -> V_89 ) ;
F_53 ( V_2 -> V_89 ) ;
F_49 ( V_2 -> V_11 ) ;
F_50 ( V_2 -> V_94 ) ;
F_51 ( V_2 -> V_94 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int T_5 F_57 ( void )
{
return F_58 ( & V_108 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_108 ) ;
}
