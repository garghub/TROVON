static inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_6 -> V_7 , L_1 ,
V_2 -> V_8 , V_3 & 0xf ) ;
return - V_9 ;
}
if ( V_2 -> V_10 )
V_3 = ( 1 << 4 ) | V_2 -> V_8 ;
else
V_3 = V_2 -> V_8 ;
F_4 ( V_2 -> V_4 , V_5 , V_3 ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( ( V_3 & 0xf ) != V_2 -> V_8 ) {
F_6 ( V_11 L_2 ,
V_2 -> V_8 , V_3 & 0xf ) ;
return;
}
F_4 ( V_2 -> V_4 , V_5 , 0 ) ;
}
static void F_7 ( void * V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_12 ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_17 * V_18 = V_6 -> V_7 ;
struct V_19 * V_20 = V_2 -> V_20 ;
void T_2 * V_21 = V_20 -> V_22 ;
void T_2 * V_23 = V_6 -> V_24 ;
unsigned long V_25 , V_26 , V_27 ;
F_9 ( & V_6 -> V_28 , V_26 ) ;
F_3 ( V_6 -> V_7 , L_3 ,
V_2 -> V_8 , V_2 -> V_10 ? L_4 : L_5 ) ;
if ( V_2 -> V_10 )
V_25 = F_2 ( V_21 , V_29 ) ;
else
V_25 = F_2 ( V_21 , V_30 ) ;
V_25 = F_10 ( V_25 ) ;
if ( F_11 ( V_25 > V_2 -> V_31 ) ) {
F_3 ( V_6 -> V_7 , L_6 ,
V_2 -> V_10 ? L_4 : L_5 , V_25 ) ;
V_25 = 0 ;
}
V_14 -> V_32 = V_2 -> V_31 - V_25 ;
V_27 = V_2 -> V_33 - V_14 -> V_32 ;
F_3 ( V_6 -> V_7 , L_7 , V_25 , V_2 -> V_31 ) ;
if ( V_27 > 0 && V_27 < 32 ) {
T_3 * V_34 ;
F_3 ( V_6 -> V_7 , L_8 , V_27 ) ;
V_34 = F_12 ( ( T_1 ) V_2 -> V_35 ) + V_2 -> V_31 ;
if ( V_2 -> V_10 ) {
F_13 ( V_18 , V_2 -> V_35 ,
V_2 -> V_31 ,
V_36 ) ;
F_14 ( V_20 , V_27 , V_34 ) ;
} else {
F_13 ( V_18 , V_2 -> V_35 ,
V_2 -> V_31 ,
V_37 ) ;
F_15 ( V_20 , V_27 , V_34 ) ;
}
V_14 -> V_32 += V_27 ;
}
if ( ! V_16 -> V_38 )
F_5 ( V_2 ) ;
V_14 -> V_39 = V_40 ;
F_16 ( V_6 , V_2 -> V_8 , V_2 -> V_10 ) ;
if ( ( V_2 -> V_31 < V_2 -> V_41 )
|| ( V_2 -> V_31 % V_2 -> V_41 != 0 ) ) {
T_4 V_42 ;
if ( V_2 -> V_10 ) {
F_3 ( V_6 -> V_7 , L_9 ) ;
F_17 ( V_23 , V_2 -> V_8 ) ;
V_42 = F_18 ( V_20 -> V_43 , V_44 ) ;
V_42 |= V_45 | V_46
| V_47 ;
F_19 ( V_20 -> V_43 , V_44 , V_42 ) ;
}
}
F_20 ( & V_6 -> V_28 , V_26 ) ;
}
static int F_21 ( struct V_13 * V_14 , T_4 V_41 ,
T_3 V_48 , T_5 V_35 , T_1 V_33 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_17 * V_18 = V_6 -> V_7 ;
struct V_19 * V_20 = V_2 -> V_20 ;
void T_2 * V_23 = V_6 -> V_24 ;
void T_2 * V_21 = V_20 -> V_22 ;
T_5 V_49 = V_20 -> V_50 ;
T_1 V_51 ;
T_4 V_42 ;
T_1 V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
enum V_59 V_60 ;
T_1 V_61 ;
int V_62 ;
if ( F_11 ( V_35 & 0x1 ) || ( V_33 < 32 ) || ( V_33 > V_41 ) )
return false ;
if ( V_35 & 0x2 )
return false ;
if ( V_2 -> V_10 )
V_51 = F_2 ( V_21 , V_29 ) ;
else
V_51 = F_2 ( V_21 , V_30 ) ;
V_51 = F_10 ( V_51 ) ;
if ( V_51 ) {
F_3 ( V_6 -> V_7 , L_10 ,
V_2 -> V_10 ? L_4 : L_5 , V_51 ) ;
return false ;
}
V_2 -> V_31 = V_33 & ~ 0x1f ;
if ( V_33 < V_41 )
V_2 -> V_63 = V_2 -> V_31 ;
else
V_2 -> V_63 = V_41 ;
V_54 = V_2 -> V_54 ;
if ( ! V_16 -> V_38 ) {
if ( F_1 ( V_2 ) != 0 ) {
F_3 ( V_6 -> V_7 , L_11 , V_2 -> V_8 ) ;
return false ;
}
if ( V_54 -> V_64 < 0 ) {
F_22 ( 1 ) ;
return false ;
}
}
V_2 -> V_41 = V_41 ;
V_2 -> V_33 = V_33 ;
V_14 -> V_32 = 0 ;
V_2 -> V_35 = V_35 ;
V_14 -> V_39 = V_65 ;
if ( V_2 -> V_10 ) {
V_60 = V_66 ;
F_23 ( V_18 , F_12 ( V_35 ) , V_33 ,
V_36 ) ;
} else {
V_60 = V_67 ;
F_23 ( V_18 , F_12 ( V_35 ) , V_33 ,
V_37 ) ;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
if ( ( V_35 & 0x3 ) == 0 ) {
V_58 . V_68 = V_69 ;
V_58 . V_70 = V_69 ;
V_61 = 8 ;
} else {
V_58 . V_68 = V_71 ;
V_58 . V_70 = V_71 ;
V_61 = 16 ;
V_49 = V_20 -> V_72 ;
}
F_3 ( V_6 -> V_7 ,
L_12 ,
V_2 -> V_8 , V_2 -> V_10 ? L_4 : L_5 , & V_35 ,
V_2 -> V_31 , V_33 , V_2 -> V_63 , V_41 ) ;
V_58 . V_73 = V_49 ;
V_58 . V_74 = V_49 ;
V_58 . V_75 = V_61 ;
V_58 . V_76 = V_61 ;
V_58 . V_77 = V_61 ;
V_58 . V_78 = V_61 ;
V_62 = F_24 ( V_54 -> V_79 , & V_58 ) ;
if ( V_62 ) {
F_25 ( V_6 -> V_7 , L_13 , V_62 ) ;
return false ;
}
V_56 = F_26 ( V_54 -> V_79 , V_35 ,
V_2 -> V_31 , V_60 ,
V_80 | V_81 ) ;
if ( ! V_56 ) {
F_25 ( V_6 -> V_7 , L_14 ) ;
return false ;
}
V_56 -> V_82 = F_7 ;
V_56 -> V_83 = V_14 ;
F_27 ( V_56 ) ;
F_3 ( V_6 -> V_7 ,
L_15 ,
V_2 -> V_8 , V_2 -> V_10 ? L_4 : L_5 ,
V_58 . V_68 * 8 ,
( ( V_35 & 0x3 ) == 0 ) ? L_16 : L_17 ,
( V_60 == V_66 ) ? & V_35 : & V_49 ,
( V_60 == V_66 ) ? & V_49 : & V_35 ) ;
F_17 ( V_23 , V_2 -> V_8 ) ;
if ( V_2 -> V_10 ) {
V_42 = F_18 ( V_20 -> V_43 , V_44 ) ;
V_42 |= ( V_84 | V_85
| V_86 | V_45 ) ;
V_42 &= ~ V_87 ;
F_19 ( V_20 -> V_43 , V_44 , V_42 ) ;
} else {
V_42 = F_18 ( V_20 -> V_43 , V_88 ) ;
V_42 |= V_89 ;
V_42 &= ~ ( V_90 | V_91 ) ;
F_19 ( V_20 -> V_43 , V_88 ,
V_42 | V_92 ) ;
}
F_28 ( V_54 -> V_79 ) ;
if ( V_2 -> V_10 ) {
V_52 = F_2 ( V_21 , V_93 ) ;
V_52 &= ~ 0x7ff ;
V_52 |= V_2 -> V_63 ;
F_4 ( V_21 , V_93 , V_52 ) ;
F_4 ( V_21 , V_29 ,
F_10 ( V_2 -> V_31 ) ) ;
} else {
V_52 = F_2 ( V_21 , V_93 ) ;
V_52 &= ~ ( 0x7ff << 16 ) ;
V_52 |= ( V_2 -> V_63 << 16 ) ;
F_4 ( V_21 , V_93 , V_52 ) ;
F_4 ( V_21 , V_30 ,
F_10 ( V_2 -> V_31 ) ) ;
}
return true ;
}
static int F_29 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
if ( V_2 -> V_54 )
F_30 ( V_2 -> V_54 -> V_79 ) ;
V_14 -> V_39 = V_40 ;
return 0 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
int V_94 , V_95 = - 1 ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
int V_97 = ( V_3 & ( 0xf << ( V_94 * 5 ) ) ) >> ( V_94 * 5 ) ;
if ( V_97 == 0 ) {
V_95 = V_94 ;
break;
}
}
if ( V_95 == - 1 )
return - V_9 ;
V_3 |= ( V_2 -> V_8 << ( V_95 * 5 ) ) ;
if ( V_2 -> V_10 )
V_3 |= ( ( 1 << 4 ) << ( V_95 * 5 ) ) ;
F_4 ( V_2 -> V_4 , V_5 , V_3 ) ;
V_2 -> V_54 = & V_2 -> V_16 -> V_98 [ V_95 ] ;
return 0 ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! V_2 || ! V_2 -> V_54 || V_2 -> V_54 -> V_64 < 0 )
return;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
V_3 &= ~ ( 0x1f << ( V_2 -> V_54 -> V_64 * 5 ) ) ;
F_4 ( V_2 -> V_4 , V_5 , V_3 ) ;
V_2 -> V_54 = NULL ;
}
static struct V_13 *
F_33 ( struct V_99 * V_100 ,
struct V_19 * V_20 ,
T_3 V_10 )
{
int V_62 , V_94 ;
struct V_15 * V_16 ;
struct V_6 * V_6 ;
struct V_13 * V_14 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_53 * V_54 = NULL ;
V_16 = F_34 ( V_100 , struct V_15 , V_7 ) ;
V_6 = V_16 -> V_7 . V_6 ;
if ( V_20 -> V_8 == 0 ) {
F_3 ( V_6 -> V_7 , L_18 , V_10 ? L_4 : L_5 ) ;
return NULL ;
}
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
struct V_13 * V_101 = V_102 [ V_94 ] ;
if ( V_101 -> V_39 == V_103 ) {
V_101 -> V_39 = V_40 ;
V_14 = V_101 ;
V_2 = V_101 -> V_104 ;
break;
}
}
if ( ! V_14 )
return NULL ;
V_2 -> V_6 = V_16 -> V_7 . V_6 ;
V_2 -> V_4 = V_16 -> V_4 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_8 = V_20 -> V_8 ;
V_2 -> V_105 = 0 ;
V_2 -> V_16 = V_16 ;
if ( V_10 )
V_2 -> V_10 = 1 ;
else
V_2 -> V_10 = 0 ;
V_14 -> V_106 = 0x7fffffff ;
V_14 -> V_107 = 0 ;
V_14 -> V_32 = 0 ;
if ( ! V_2 -> V_54 ) {
if ( V_16 -> V_38 ) {
V_62 = F_31 ( V_2 ) ;
if ( V_62 != 0 )
goto V_108;
} else {
V_2 -> V_54 = & V_16 -> V_98 [ 0 ] ;
}
}
V_54 = V_2 -> V_54 ;
F_3 ( V_6 -> V_7 , L_19 ,
V_2 -> V_8 ,
V_2 -> V_10 ? L_4 : L_5 ,
V_16 -> V_38 ? L_20 : L_21 ,
V_54 -> V_64 ) ;
return V_14 ;
V_108:
F_32 ( V_2 ) ;
F_3 ( V_6 -> V_7 , L_22 , V_2 -> V_8 ) ;
V_14 -> V_39 = V_103 ;
return NULL ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_6 * V_6 = V_2 -> V_6 ;
F_3 ( V_6 -> V_7 , L_23 , V_2 -> V_8 ) ;
V_14 -> V_39 = V_103 ;
F_36 ( V_2 -> V_54 -> V_79 ) ;
F_32 ( V_2 ) ;
V_14 = NULL ;
}
void F_37 ( struct V_99 * V_100 )
{
struct V_15 * V_16 ;
int V_94 ;
V_16 = F_34 ( V_100 , struct V_15 , V_7 ) ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
struct V_13 * V_101 = V_102 [ V_94 ] ;
if ( V_101 ) {
F_38 ( V_101 -> V_104 ) ;
F_38 ( V_101 ) ;
}
if ( V_16 && V_16 -> V_98 [ V_94 ] . V_79 )
F_39 ( V_16 -> V_98 [ V_94 ] . V_79 ) ;
}
F_38 ( V_16 ) ;
}
static int F_40 ( struct V_15 * V_16 )
{
struct V_6 * V_6 = V_16 -> V_7 . V_6 ;
int V_94 ;
int V_62 = 0 ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
struct V_53 * V_54 = & V_16 -> V_98 [ V_94 ] ;
if ( V_94 == 0 || V_16 -> V_38 ) {
char V_109 [ 8 ] ;
sprintf ( V_109 , L_24 , V_94 ) ;
V_54 -> V_79 = F_41 ( V_6 -> V_7 ,
V_109 ) ;
if ( F_42 ( V_54 -> V_79 ) ) {
F_25 ( V_6 -> V_7 ,
L_25 , V_109 ) ;
V_62 = F_43 ( V_54 -> V_79 ) ;
goto V_110;
}
V_54 -> V_64 = V_94 ;
} else {
V_54 -> V_64 = - 1 ;
}
}
return 0 ;
V_110:
for (; V_94 >= 0 ; V_94 -- ) {
struct V_53 * V_54 = & V_16 -> V_98 [ V_94 ] ;
if ( V_54 -> V_64 >= 0 )
F_39 ( V_54 -> V_79 ) ;
}
return V_62 ;
}
struct V_99 *
F_44 ( struct V_6 * V_6 , void T_2 * V_111 )
{
void T_2 * V_4 = V_6 -> V_112 ;
struct V_15 * V_16 ;
int V_94 ;
F_4 ( V_6 -> V_112 , V_113 , 0x7fffffff ) ;
F_4 ( V_6 -> V_112 , V_5 , 0 ) ;
F_4 ( V_4 , V_114 ,
F_45 ( 2 )
| F_46 ( 0x3f )
| F_47 ( 2 ) ) ;
V_16 = F_48 ( sizeof( struct V_15 ) , V_115 ) ;
if ( ! V_16 )
goto V_116;
V_16 -> V_7 . V_6 = V_6 ;
V_16 -> V_4 = V_6 -> V_112 ;
V_16 -> V_7 . V_117 = F_33 ;
V_16 -> V_7 . V_118 = F_35 ;
V_16 -> V_7 . V_119 = F_21 ;
V_16 -> V_7 . V_120 = F_29 ;
if ( V_6 -> V_121 >= V_122 )
V_16 -> V_38 = 1 ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
struct V_13 * V_101 ;
struct V_1 * V_2 ;
V_101 = F_48 ( sizeof( struct V_13 ) , V_115 ) ;
if ( ! V_101 )
goto V_123;
V_102 [ V_94 ] = V_101 ;
V_2 = F_48 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_2 )
goto V_123;
V_101 -> V_39 = V_103 ;
V_101 -> V_104 = V_2 ;
}
if ( F_40 ( V_16 ) )
goto V_123;
return & V_16 -> V_7 ;
V_123:
F_49 ( & V_16 -> V_7 ) ;
V_116:
return NULL ;
}
