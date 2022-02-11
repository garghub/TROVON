static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
V_5 -> V_7 |= V_8 ;
F_2 ( V_5 -> V_7 , V_5 -> V_9 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
V_5 -> V_7 &= ~ V_8 ;
F_2 ( V_5 -> V_7 , V_5 -> V_9 ) ;
}
static void
F_4 ( struct V_10 * V_11 , int V_12 )
{
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
unsigned long V_14 ;
F_5 ( V_11 -> V_15 , V_14 ) ;
if ( V_12 )
V_5 -> V_7 |= V_16 ;
else
V_5 -> V_7 &= ~ V_16 ;
F_2 ( V_5 -> V_7 , V_5 -> V_9 ) ;
F_6 ( V_11 -> V_15 , V_14 ) ;
}
static T_1
F_7 ( int V_17 , void * V_18 )
{
struct V_4 * V_5 = V_18 ;
return F_8 ( & V_5 -> V_5 ) ;
}
static T_2
F_9 ( struct V_10 * V_11 , struct V_19 * V_20 ,
T_3 V_21 , T_2 V_22 )
{
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
struct V_23 * V_24 = F_10 ( V_11 ) ;
int V_25 = V_5 -> V_5 . V_26 . V_27 ;
if ( V_25 != V_28 &&
( V_22 == V_29 || V_20 -> V_30 >= 512 ) ) {
int V_31 , V_32 , V_33 ;
V_31 = F_11 ( & V_5 -> V_34 [ 0 ] , V_20 , V_35 ) ;
if ( V_21 == V_36 )
V_32 = V_37 ,
V_33 = V_38 ;
else
V_32 = V_39 ,
V_33 = V_40 ;
F_12 ( V_24 , V_5 -> V_34 , V_31 , V_32 ) ;
F_13 ( V_25 ) ;
F_14 ( V_25 , V_5 -> V_34 , V_31 ) ;
F_15 ( V_25 , V_33 ) ;
F_16 ( V_25 ) ;
return V_29 ;
}
return V_41 ;
}
static void F_17 ( void * V_42 , int V_43 , void T_4 * V_44 )
{
const void T_4 * V_45 = V_44 + V_46 ;
const void T_4 * V_47 = V_44 + V_48 ;
const void T_4 * V_49 = V_44 + V_50 ;
register const unsigned long V_51 = 0xffff ;
do {
unsigned int V_52 ;
V_52 = F_18 ( V_45 + ( V_53 << V_54 ) ) ;
if ( V_52 & V_55 )
break;
V_52 = F_18 ( V_47 ) ;
if ( ! ( V_52 & V_56 ) )
continue;
V_52 = F_18 ( V_45 + ( V_57 << V_54 ) ) & V_58 ;
if ( V_52 > 16 )
V_52 = 16 ;
if ( V_52 > V_43 )
V_52 = V_43 ;
if ( ( ( V_59 ) V_42 ) & 2 && V_52 >= 2 ) {
* ( V_60 * ) V_42 = F_19 ( V_49 ) ;
V_42 += 2 ;
V_52 -= 2 ;
V_43 -= 2 ;
}
if ( V_52 >= 8 ) {
unsigned long V_61 , V_62 ;
V_61 = F_19 ( V_49 ) & V_51 ;
V_61 |= F_19 ( V_49 ) << 16 ;
V_62 = F_19 ( V_49 ) & V_51 ;
V_62 |= F_19 ( V_49 ) << 16 ;
* ( V_59 * ) V_42 = V_61 ;
V_42 += 4 ;
* ( V_59 * ) V_42 = V_62 ;
V_42 += 4 ;
V_43 -= 8 ;
continue;
}
if ( V_52 >= 4 ) {
unsigned long V_61 ;
V_61 = F_19 ( V_49 ) & V_51 ;
V_61 |= F_19 ( V_49 ) << 16 ;
* ( V_59 * ) V_42 = V_61 ;
V_42 += 4 ;
V_43 -= 4 ;
continue;
}
if ( V_52 >= 2 ) {
* ( V_60 * ) V_42 = F_19 ( V_49 ) ;
V_42 += 2 ;
V_43 -= 2 ;
}
} while ( V_43 );
}
static void F_20 ( void * V_42 , int V_43 , void T_4 * V_44 )
{
const void T_4 * V_45 = V_44 + V_46 ;
const void T_4 * V_47 = V_44 + V_48 ;
const void T_4 * V_49 = V_44 + V_50 ;
do {
unsigned int V_52 ;
V_52 = F_18 ( V_45 + ( V_53 << V_54 ) ) ;
if ( V_52 & V_55 )
break;
V_52 = F_18 ( V_47 ) ;
if ( ! ( V_52 & V_56 ) )
continue;
V_52 = F_18 ( V_45 + ( V_57 << V_54 ) ) & V_58 ;
if ( V_52 > 16 )
V_52 = 16 ;
V_52 = 16 - V_52 ;
if ( V_52 > V_43 )
V_52 = V_43 ;
V_52 &= ~ 1 ;
if ( ( ( V_59 ) V_42 ) & 2 && V_52 >= 2 ) {
F_21 ( * ( V_60 * ) V_42 << 16 , V_49 ) ;
V_42 += 2 ;
V_52 -= 2 ;
V_43 -= 2 ;
}
if ( V_52 >= 8 ) {
unsigned long V_61 , V_62 ;
V_61 = * ( V_59 * ) V_42 ;
V_42 += 4 ;
V_62 = * ( V_59 * ) V_42 ;
V_42 += 4 ;
F_21 ( V_61 << 16 , V_49 ) ;
F_21 ( V_61 , V_49 ) ;
F_21 ( V_62 << 16 , V_49 ) ;
F_21 ( V_62 , V_49 ) ;
V_43 -= 8 ;
continue;
}
if ( V_52 >= 4 ) {
unsigned long V_61 ;
V_61 = * ( V_59 * ) V_42 ;
V_42 += 4 ;
F_21 ( V_61 << 16 , V_49 ) ;
F_21 ( V_61 , V_49 ) ;
V_43 -= 4 ;
continue;
}
if ( V_52 >= 2 ) {
F_21 ( * ( V_60 * ) V_42 << 16 , V_49 ) ;
V_42 += 2 ;
V_43 -= 2 ;
}
} while ( V_43 );
}
static void
F_22 ( struct V_10 * V_11 , struct V_19 * V_20 ,
T_3 V_63 , int V_64 )
{
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
if ( V_63 == V_65 ) {
F_17 ( V_20 -> V_66 , V_20 -> V_30 , V_5 -> V_44 ) ;
} else {
F_20 ( V_20 -> V_66 , V_20 -> V_30 , V_5 -> V_44 ) ;
}
}
static void
F_23 ( struct V_10 * V_11 , struct V_19 * V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
if ( V_5 -> V_5 . V_26 . V_27 != V_28 )
F_13 ( V_5 -> V_5 . V_26 . V_27 ) ;
}
const char * V_4 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
static char string [ 150 ] ;
sprintf ( string , L_1 ,
V_11 -> V_67 -> V_68 , V_5 -> V_5 . V_26 . type , V_5 -> V_2 -> V_69 ,
V_70 , V_5 -> V_7 & V_16 ? L_2 : L_3 ) ;
return string ;
}
static int
F_24 ( struct V_10 * V_11 , char * V_71 , int V_43 )
{
int V_72 = V_43 ;
if ( V_43 >= 9 && strncmp ( V_71 , L_4 , 9 ) == 0 ) {
V_71 += 9 ;
V_43 -= 9 ;
if ( V_43 >= 5 && strncmp ( V_71 , L_5 , 5 ) == 0 ) {
if ( V_71 [ 5 ] == '1' )
F_4 ( V_11 , 1 ) ;
else if ( V_71 [ 5 ] == '0' )
F_4 ( V_11 , 0 ) ;
else
V_72 = - V_73 ;
} else
V_72 = - V_73 ;
} else
V_72 = - V_73 ;
return V_72 ;
}
int F_25 ( struct V_10 * V_11 , char * V_71 , char * * V_74 , T_5 V_75 ,
int V_43 , int V_76 )
{
struct V_4 * V_5 ;
char * V_77 = V_71 ;
int V_78 ;
if ( V_76 == 1 )
return F_24 ( V_11 , V_71 , V_43 ) ;
V_5 = (struct V_4 * ) V_11 -> V_13 ;
V_77 += sprintf ( V_77 , L_6 , V_70 ) ;
V_77 += F_26 ( & V_5 -> V_5 , V_77 ) ;
V_77 += sprintf ( V_77 , L_7 ,
V_5 -> V_7 & V_16 ? L_2 : L_3 ) ;
V_77 += F_27 ( & V_5 -> V_5 , V_77 ) ;
V_77 += F_28 ( & V_5 -> V_5 , V_77 ) ;
* V_74 = V_71 + V_75 ;
V_78 = V_77 - V_71 - V_75 ;
if ( V_78 > V_43 )
V_78 = V_43 ;
return V_78 ;
}
static T_6 F_29 ( struct V_23 * V_24 , struct V_79 * V_80 , char * V_42 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
struct V_10 * V_11 = F_31 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
return sprintf ( V_42 , L_8 , V_5 -> V_7 & V_16 ? 1 : 0 ) ;
}
static T_6 F_32 ( struct V_23 * V_24 , struct V_79 * V_80 , const char * V_42 , T_7 V_81 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
struct V_10 * V_11 = F_31 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
unsigned long V_14 ;
if ( V_81 > 1 ) {
F_5 ( V_11 -> V_15 , V_14 ) ;
if ( V_42 [ 0 ] != '0' ) {
V_5 -> V_7 |= V_16 ;
} else {
V_5 -> V_7 &= ~ V_16 ;
}
F_2 ( V_5 -> V_7 , V_5 -> V_9 ) ;
F_6 ( V_11 -> V_15 , V_14 ) ;
}
return V_81 ;
}
static int T_8
F_33 ( struct V_1 * V_2 , const struct V_82 * V_83 )
{
struct V_10 * V_11 ;
struct V_4 * V_5 ;
void T_4 * V_44 ;
int V_72 ;
V_72 = F_34 ( V_2 ) ;
if ( V_72 )
goto V_84;
V_44 = F_35 ( V_2 , V_85 , 0 , 0 ) ;
if ( ! V_44 ) {
V_72 = - V_86 ;
goto V_87;
}
V_11 = F_36 ( & V_88 ,
sizeof( struct V_4 ) ) ;
if ( ! V_11 ) {
V_72 = - V_86 ;
goto V_87;
}
F_37 ( V_2 , V_11 ) ;
V_5 = (struct V_4 * ) V_11 -> V_13 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_9 = V_44 + V_89 ;
V_5 -> V_7 = V_90 [ V_2 -> V_69 ] ? V_16 : 0 ;
F_2 ( V_5 -> V_7 , V_5 -> V_9 ) ;
V_5 -> V_5 . V_26 . V_91 = V_44 + V_46 ;
V_5 -> V_5 . V_26 . V_92 = V_54 ;
V_5 -> V_5 . V_26 . V_17 = V_2 -> V_17 ;
V_5 -> V_5 . V_26 . V_27 = V_2 -> V_27 ;
V_5 -> V_5 . V_93 . V_94 = 40 ;
V_5 -> V_5 . V_93 . V_95 = 255 ;
V_5 -> V_5 . V_93 . V_96 = 200 ;
V_5 -> V_5 . V_93 . V_97 = 7 ;
V_5 -> V_5 . V_93 . V_98 = V_99 | V_100 ;
V_5 -> V_5 . V_93 . V_101 = 1 ;
V_5 -> V_5 . V_93 . V_102 = 0 ;
V_5 -> V_5 . V_93 . V_103 = V_104 ;
V_5 -> V_5 . V_27 . V_105 = F_9 ;
V_5 -> V_5 . V_27 . V_106 = F_22 ;
V_5 -> V_5 . V_27 . V_107 = F_23 ;
V_2 -> V_108 = V_44 + V_48 ;
V_2 -> V_109 = V_110 ;
F_38 ( V_2 , & V_111 , V_5 ) ;
F_39 ( & V_2 -> V_24 , & V_112 ) ;
V_72 = F_40 ( V_11 ) ;
if ( V_72 )
goto V_113;
V_72 = F_41 ( V_2 -> V_17 , F_7 , 0 , L_9 , V_5 ) ;
if ( V_72 ) {
F_42 ( L_10 ,
V_11 -> V_114 , V_2 -> V_17 , V_72 ) ;
goto V_115;
}
if ( V_5 -> V_5 . V_26 . V_27 != V_28 ) {
if ( F_43 ( V_5 -> V_5 . V_26 . V_27 , L_11 ) ) {
F_42 ( L_12 ,
V_11 -> V_114 , V_5 -> V_5 . V_26 . V_27 ) ;
V_5 -> V_5 . V_26 . V_27 = V_28 ;
} else {
F_44 ( V_5 -> V_5 . V_26 . V_27 , 180 ) ;
V_5 -> V_5 . V_93 . V_103 |= V_116 ;
V_5 -> V_5 . V_93 . V_98 |= V_117 ;
}
}
V_72 = F_45 ( V_11 , & V_2 -> V_24 ) ;
if ( V_72 == 0 )
goto V_84;
if ( V_5 -> V_5 . V_26 . V_27 != V_28 )
F_46 ( V_5 -> V_5 . V_26 . V_27 ) ;
F_47 ( V_2 -> V_17 , V_11 ) ;
V_115:
F_48 ( V_11 ) ;
V_113:
F_49 ( & V_2 -> V_24 , & V_112 ) ;
F_50 ( V_11 ) ;
V_87:
F_51 ( V_2 ) ;
V_84:
return V_72 ;
}
static void T_9 F_52 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_31 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_11 -> V_13 ;
F_37 ( V_2 , NULL ) ;
F_48 ( V_11 ) ;
if ( V_5 -> V_5 . V_26 . V_27 != V_28 )
F_46 ( V_5 -> V_5 . V_26 . V_27 ) ;
F_47 ( V_2 -> V_17 , V_5 ) ;
F_49 ( & V_2 -> V_24 , & V_112 ) ;
F_53 ( V_11 ) ;
F_50 ( V_11 ) ;
F_51 ( V_2 ) ;
}
static int T_10 F_54 ( void )
{
return F_55 ( & V_118 ) ;
}
static void T_11 F_56 ( void )
{
F_57 ( & V_118 ) ;
}
