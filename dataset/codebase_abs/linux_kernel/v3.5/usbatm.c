static inline unsigned int F_1 ( unsigned int V_1 )
{
V_1 += V_2 - 1 + V_3 ;
return V_1 - V_1 % V_2 ;
}
static inline void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
if ( V_5 -> V_8 )
V_5 -> V_8 ( V_5 , V_7 ) ;
else
F_3 ( V_7 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
struct V_9 * V_9 ;
F_5 ( & V_11 -> V_12 ) ;
if ( F_6 ( & V_11 -> V_13 ) ) {
F_7 ( & V_11 -> V_12 ) ;
return NULL ;
}
V_9 = F_8 ( V_11 -> V_13 . V_14 , struct V_9 , V_15 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_7 ( & V_11 -> V_12 ) ;
return V_9 ;
}
static int F_10 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_16 ;
int V_17 ;
F_11 ( L_1 ,
V_18 , V_9 , V_9 -> V_19 ) ;
V_17 = F_12 ( V_9 , V_20 ) ;
if ( V_17 ) {
if ( F_13 () )
F_14 ( V_11 -> V_21 , L_2 ,
V_18 , V_9 , V_17 ) ;
V_9 -> V_22 = - V_23 ;
F_5 ( & V_11 -> V_12 ) ;
F_15 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_7 ( & V_11 -> V_12 ) ;
F_16 ( & V_11 -> V_24 , V_25 + F_17 ( V_26 ) ) ;
}
return V_17 ;
}
static void F_18 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_16 ;
unsigned long V_27 ;
int V_22 = V_9 -> V_22 ;
F_11 ( L_3 ,
V_18 , V_9 , V_22 , V_9 -> V_28 ) ;
F_19 ( & V_11 -> V_12 , V_27 ) ;
F_20 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_21 ( & V_11 -> V_12 , V_27 ) ;
if ( F_22 ( V_22 ) &&
( ! ( V_11 -> V_21 -> V_27 & V_29 ) ||
V_22 != - V_30 ) ) {
if ( V_22 == - V_31 )
return;
if ( F_13 () )
F_14 ( V_11 -> V_21 , L_4 ,
V_18 , V_9 , V_22 ) ;
F_16 ( & V_11 -> V_24 , V_25 + F_17 ( V_26 ) ) ;
} else
F_23 ( & V_11 -> V_32 ) ;
}
static inline struct V_33 * F_24 ( struct V_34 * V_35 ,
short V_36 , int V_37 )
{
struct V_33 * V_38 ;
F_25 (vcc_data, &instance->vcc_list, list)
if ( ( V_38 -> V_37 == V_37 ) && ( V_38 -> V_36 == V_36 ) )
return V_38 ;
return NULL ;
}
static void F_26 ( struct V_34 * V_35 , unsigned char * V_39 )
{
struct V_4 * V_5 ;
struct V_6 * V_40 ;
short V_36 = ( ( V_39 [ 0 ] & 0x0f ) << 4 ) | ( V_39 [ 1 ] >> 4 ) ;
int V_37 = ( ( V_39 [ 1 ] & 0x0f ) << 12 ) | ( V_39 [ 2 ] << 4 ) | ( V_39 [ 3 ] >> 4 ) ;
T_1 V_41 = ( ( V_39 [ 3 ] & 0xe ) >> 1 ) ;
F_11 ( L_5 , V_18 , V_36 , V_37 , V_41 ) ;
if ( ( V_37 != V_35 -> V_42 ) || ( V_36 != V_35 -> V_43 ) ) {
V_35 -> V_43 = V_36 ;
V_35 -> V_42 = V_37 ;
V_35 -> V_44 = F_24 ( V_35 , V_36 , V_37 ) ;
if ( ! V_35 -> V_44 )
F_27 ( V_35 , L_6 , V_18 , V_36 , V_37 ) ;
}
if ( ! V_35 -> V_44 )
return;
V_5 = V_35 -> V_44 -> V_5 ;
if ( V_41 == V_45 ) {
if ( F_13 () )
F_14 ( V_35 , L_7 ,
V_18 , V_36 , V_37 ) ;
F_28 ( & V_5 -> V_46 -> V_47 ) ;
return;
}
V_40 = V_35 -> V_44 -> V_40 ;
if ( V_40 -> V_48 + V_2 > V_40 -> V_49 ) {
F_27 ( V_35 , L_8 ,
V_18 , V_40 -> V_50 , V_5 ) ;
F_29 ( V_40 , 0 ) ;
F_30 ( V_35 , V_40 -> V_48 + V_2 <= V_40 -> V_49 ) ;
}
memcpy ( F_31 ( V_40 ) , V_39 + V_51 , V_2 ) ;
F_32 ( V_40 , V_2 ) ;
if ( V_41 & 1 ) {
struct V_6 * V_7 ;
unsigned int V_1 ;
unsigned int V_52 ;
V_1 = ( V_39 [ V_53 - 6 ] << 8 ) + V_39 [ V_53 - 5 ] ;
if ( V_1 > V_54 ) {
F_27 ( V_35 , L_9 ,
V_18 , V_1 , V_5 ) ;
F_28 ( & V_5 -> V_46 -> V_47 ) ;
goto V_55;
}
V_52 = F_1 ( V_1 ) ;
if ( V_40 -> V_50 < V_52 ) {
F_27 ( V_35 , L_10 ,
V_18 , V_52 , V_40 -> V_50 , V_5 ) ;
F_28 ( & V_5 -> V_46 -> V_47 ) ;
goto V_55;
}
if ( F_33 ( ~ 0 , F_31 ( V_40 ) - V_52 , V_52 ) != 0xc704dd7b ) {
F_27 ( V_35 , L_11 ,
V_18 , V_5 ) ;
F_28 ( & V_5 -> V_46 -> V_47 ) ;
goto V_55;
}
F_11 ( L_12 , V_18 , V_1 , V_52 , V_5 ) ;
if ( ! ( V_7 = F_34 ( V_1 ) ) ) {
if ( F_13 () )
F_35 ( V_35 , L_13 ,
V_18 , V_1 ) ;
F_28 ( & V_5 -> V_46 -> V_56 ) ;
goto V_55;
}
F_11 ( L_14 , V_18 , V_7 , V_7 -> V_57 ) ;
if ( ! F_36 ( V_5 , V_7 -> V_57 ) ) {
F_27 ( V_35 , L_15 ,
V_18 , V_7 -> V_57 ) ;
F_3 ( V_7 ) ;
goto V_55;
}
F_37 ( V_7 ,
F_31 ( V_40 ) - V_52 ,
V_1 ) ;
F_32 ( V_7 , V_1 ) ;
F_11 ( L_16 ,
V_18 , V_7 , V_7 -> V_50 , V_7 -> V_57 ) ;
F_38 ( V_7 -> V_58 , V_7 -> V_50 ) ;
V_5 -> V_59 ( V_5 , V_7 ) ;
F_28 ( & V_5 -> V_46 -> V_60 ) ;
V_55:
F_29 ( V_40 , 0 ) ;
}
}
static void F_39 ( struct V_34 * V_35 ,
unsigned char * V_39 , unsigned int V_61 )
{
unsigned int V_62 = V_35 -> V_63 . V_62 ;
unsigned int V_64 = V_35 -> V_64 ;
if ( V_64 > 0 ) {
unsigned char * V_65 = V_35 -> V_65 ;
unsigned int V_66 = V_62 - V_64 ;
F_30 ( V_35 , V_64 <= V_62 ) ;
if ( V_61 >= V_66 ) {
memcpy ( V_65 + V_64 , V_39 , V_66 ) ;
V_39 += V_66 ;
V_61 -= V_66 ;
F_26 ( V_35 , V_65 ) ;
V_35 -> V_64 = 0 ;
} else {
memcpy ( V_65 + V_64 , V_39 , V_61 ) ;
V_35 -> V_64 = V_64 + V_61 ;
return;
}
}
for (; V_61 >= V_62 ; V_61 -= V_62 , V_39 += V_62 )
F_26 ( V_35 , V_39 ) ;
if ( V_61 > 0 ) {
memcpy ( V_35 -> V_65 , V_39 , V_61 ) ;
V_35 -> V_64 = V_61 ;
}
}
static unsigned int F_40 ( struct V_34 * V_35 ,
struct V_6 * V_7 ,
T_1 * V_67 , unsigned int V_68 )
{
struct V_69 * V_70 = F_41 ( V_7 ) ;
struct V_4 * V_5 = V_70 -> V_71 . V_5 ;
unsigned int V_72 ;
unsigned int V_62 = V_35 -> V_73 . V_62 ;
F_11 ( L_17 , V_18 , V_7 -> V_50 , V_68 ) ;
F_30 ( V_35 , ! ( V_68 % V_62 ) ) ;
for ( V_72 = 0 ; V_72 < V_68 && V_70 -> V_50 ;
V_72 += V_62 , V_67 += V_62 ) {
unsigned int V_74 = F_42 (unsigned int, skb->len, ATM_CELL_PAYLOAD) ;
unsigned int V_75 = V_2 - V_74 ;
T_1 * V_76 = V_67 ;
V_76 [ 0 ] = V_5 -> V_36 >> 4 ;
V_76 [ 1 ] = ( V_5 -> V_36 << 4 ) | ( V_5 -> V_37 >> 12 ) ;
V_76 [ 2 ] = V_5 -> V_37 >> 4 ;
V_76 [ 3 ] = V_5 -> V_37 << 4 ;
V_76 [ 4 ] = 0xec ;
V_76 += V_51 ;
F_43 ( V_7 , V_76 , V_74 ) ;
V_76 += V_74 ;
F_44 ( V_7 , V_74 ) ;
if ( ! V_75 )
continue;
memset ( V_76 , 0 , V_75 ) ;
if ( V_75 >= V_3 ) {
T_1 * V_77 = V_67 + V_53 - V_3 ;
V_77 [ 2 ] = V_70 -> V_50 >> 8 ;
V_77 [ 3 ] = V_70 -> V_50 ;
V_70 -> V_78 = ~ F_33 ( V_70 -> V_78 , V_76 , V_75 - 4 ) ;
V_77 [ 4 ] = V_70 -> V_78 >> 24 ;
V_77 [ 5 ] = V_70 -> V_78 >> 16 ;
V_77 [ 6 ] = V_70 -> V_78 >> 8 ;
V_77 [ 7 ] = V_70 -> V_78 ;
V_67 [ 3 ] |= 0x2 ;
V_70 -> V_50 = 0 ;
} else
V_70 -> V_78 = F_33 ( V_70 -> V_78 , V_76 , V_75 ) ;
}
return V_72 ;
}
static void F_45 ( unsigned long V_58 )
{
struct V_34 * V_35 = (struct V_34 * ) V_58 ;
struct V_9 * V_9 ;
while ( ( V_9 = F_4 ( & V_35 -> V_63 ) ) ) {
F_11 ( L_18 , V_18 , V_9 ) ;
if ( F_46 ( V_9 -> V_79 ) ) {
unsigned char * V_80 = NULL ;
unsigned int V_81 = 0 ;
const unsigned int V_82 = V_35 -> V_63 . V_82 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_9 -> V_84 ; V_83 ++ ) {
if ( ! V_9 -> V_85 [ V_83 ] . V_22 ) {
unsigned int V_28 = V_9 -> V_85 [ V_83 ] . V_28 ;
F_30 ( V_35 , V_28 <= V_82 ) ;
if ( ! V_81 )
V_80 = ( unsigned char * ) V_9 -> V_86 + V_9 -> V_85 [ V_83 ] . V_87 ;
V_81 += V_28 ;
if ( V_81 && ( V_28 < V_82 ) ) {
F_39 ( V_35 , V_80 , V_81 ) ;
V_81 = 0 ;
}
} else {
F_27 ( V_35 , L_19 , V_18 , V_9 -> V_22 , V_83 ) ;
if ( V_81 )
F_39 ( V_35 , V_80 , V_81 ) ;
V_81 = 0 ;
V_35 -> V_64 = 0 ;
}
}
if ( V_81 )
F_39 ( V_35 , V_80 , V_81 ) ;
} else
if ( ! V_9 -> V_22 )
F_39 ( V_35 , V_9 -> V_86 , V_9 -> V_28 ) ;
else
V_35 -> V_64 = 0 ;
if ( F_10 ( V_9 ) )
return;
}
}
static void F_47 ( unsigned long V_58 )
{
struct V_34 * V_35 = (struct V_34 * ) V_58 ;
struct V_6 * V_7 = V_35 -> V_88 ;
struct V_9 * V_9 = NULL ;
const unsigned int V_89 = V_35 -> V_73 . V_89 ;
unsigned int V_72 = 0 ;
T_1 * V_90 = NULL ;
if ( ! V_7 )
V_7 = F_48 ( & V_35 -> V_91 ) ;
while ( V_7 ) {
if ( ! V_9 ) {
V_9 = F_4 ( & V_35 -> V_73 ) ;
if ( ! V_9 )
break;
V_90 = V_9 -> V_86 ;
V_72 = ( V_9 -> V_22 == - V_23 ) ?
V_9 -> V_19 : 0 ;
}
V_72 += F_40 ( V_35 , V_7 ,
V_90 + V_72 ,
V_89 - V_72 ) ;
F_11 ( L_20 ,
V_18 , V_72 , V_7 , V_9 ) ;
if ( ! F_41 ( V_7 ) -> V_50 ) {
struct V_4 * V_5 = F_41 ( V_7 ) -> V_71 . V_5 ;
F_2 ( V_5 , V_7 ) ;
F_28 ( & V_5 -> V_46 -> V_92 ) ;
V_7 = F_48 ( & V_35 -> V_91 ) ;
}
if ( V_72 == V_89 || ( ! V_7 && V_72 ) ) {
V_9 -> V_19 = V_72 ;
if ( F_10 ( V_9 ) )
break;
V_9 = NULL ;
}
}
V_35 -> V_88 = V_7 ;
}
static void F_49 ( struct V_34 * V_35 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 , * V_93 ;
F_50 ( V_35 , L_21 , V_18 ) ;
F_5 ( & V_35 -> V_91 . V_12 ) ;
F_51 (&instance->sndqueue, skb, n) {
if ( F_41 ( V_7 ) -> V_71 . V_5 == V_5 ) {
F_50 ( V_35 , L_22 , V_18 , V_7 ) ;
F_52 ( V_7 , & V_35 -> V_91 ) ;
F_2 ( V_5 , V_7 ) ;
}
}
F_7 ( & V_35 -> V_91 . V_12 ) ;
F_53 ( & V_35 -> V_73 . V_32 ) ;
if ( ( V_7 = V_35 -> V_88 ) && ( F_41 ( V_7 ) -> V_71 . V_5 == V_5 ) ) {
F_50 ( V_35 , L_23 , V_18 , V_7 ) ;
V_35 -> V_88 = NULL ;
F_2 ( V_5 , V_7 ) ;
}
F_54 ( & V_35 -> V_73 . V_32 ) ;
F_50 ( V_35 , L_24 , V_18 ) ;
}
static int F_55 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_34 * V_35 = V_5 -> V_94 -> V_95 ;
struct V_69 * V_70 = F_41 ( V_7 ) ;
int V_96 ;
F_11 ( L_25 , V_18 , V_7 , V_7 -> V_50 ) ;
if ( ! V_35 || V_35 -> V_97 ) {
#ifdef F_56
F_57 ( V_98 L_26 , V_18 , V_35 ? L_27 : L_28 ) ;
#endif
V_96 = - V_99 ;
goto V_100;
}
if ( V_5 -> V_101 . V_102 != V_103 ) {
F_27 ( V_35 , L_29 , V_18 , V_5 -> V_101 . V_102 ) ;
V_96 = - V_104 ;
goto V_100;
}
if ( V_7 -> V_50 > V_54 ) {
F_27 ( V_35 , L_30 ,
V_18 , V_7 -> V_50 , V_54 ) ;
V_96 = - V_104 ;
goto V_100;
}
F_38 ( V_7 -> V_58 , V_7 -> V_50 ) ;
V_70 -> V_71 . V_5 = V_5 ;
V_70 -> V_50 = V_7 -> V_50 ;
V_70 -> V_78 = F_33 ( ~ 0 , V_7 -> V_58 , V_7 -> V_50 ) ;
F_58 ( & V_35 -> V_91 , V_7 ) ;
F_23 ( & V_35 -> V_73 . V_32 ) ;
return 0 ;
V_100:
F_2 ( V_5 , V_7 ) ;
return V_96 ;
}
static void F_59 ( struct V_105 * V_105 )
{
struct V_34 * V_35 = F_60 ( V_105 , struct V_34 , V_106 ) ;
F_61 ( V_35 , L_31 , V_18 ) ;
F_62 ( & V_35 -> V_63 . V_32 ) ;
F_62 ( & V_35 -> V_73 . V_32 ) ;
F_63 ( V_35 -> V_107 ) ;
F_64 ( V_35 ) ;
}
static void F_65 ( struct V_34 * V_35 )
{
F_61 ( V_35 , L_31 , V_18 ) ;
F_66 ( & V_35 -> V_106 ) ;
}
static void F_67 ( struct V_34 * V_35 )
{
F_61 ( V_35 , L_31 , V_18 ) ;
F_68 ( & V_35 -> V_106 , F_59 ) ;
}
static void F_69 ( struct V_108 * V_108 )
{
struct V_34 * V_35 = V_108 -> V_95 ;
if ( ! V_35 )
return;
F_61 ( V_35 , L_31 , V_18 ) ;
V_108 -> V_95 = NULL ;
F_67 ( V_35 ) ;
}
static int F_70 ( struct V_108 * V_108 , T_2 * V_109 , char * V_110 )
{
struct V_34 * V_35 = V_108 -> V_95 ;
int V_75 = * V_109 ;
if ( ! V_35 )
return - V_99 ;
if ( ! V_75 -- )
return sprintf ( V_110 , L_31 , V_35 -> V_111 ) ;
if ( ! V_75 -- )
return sprintf ( V_110 , L_32 , V_108 -> V_112 ) ;
if ( ! V_75 -- )
return sprintf ( V_110 ,
L_33 ,
F_71 ( & V_108 -> V_46 . V_113 . V_92 ) ,
F_71 ( & V_108 -> V_46 . V_113 . V_114 ) ,
F_71 ( & V_108 -> V_46 . V_113 . V_60 ) ,
F_71 ( & V_108 -> V_46 . V_113 . V_47 ) ,
F_71 ( & V_108 -> V_46 . V_113 . V_56 ) ) ;
if ( ! V_75 -- ) {
if ( V_35 -> V_97 )
return sprintf ( V_110 , L_34 ) ;
else
switch ( V_108 -> signal ) {
case V_115 :
return sprintf ( V_110 , L_35 ) ;
case V_116 :
return sprintf ( V_110 , L_36 ) ;
default:
return sprintf ( V_110 , L_37 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_4 * V_5 )
{
struct V_34 * V_35 = V_5 -> V_94 -> V_95 ;
struct V_33 * V_117 = NULL ;
int V_17 ;
int V_37 = V_5 -> V_37 ;
short V_36 = V_5 -> V_36 ;
if ( ! V_35 )
return - V_99 ;
F_50 ( V_35 , L_38 , V_18 , V_36 , V_37 ) ;
if ( ( V_5 -> V_101 . V_102 != V_103 ) ) {
F_14 ( V_35 , L_29 , V_18 , V_5 -> V_101 . V_102 ) ;
return - V_104 ;
}
if ( ( V_5 -> V_101 . V_118 . V_119 < 0 ) || ( V_5 -> V_101 . V_118 . V_119 > V_54 ) ) {
F_50 ( V_35 , L_39 , V_18 , V_5 -> V_101 . V_118 . V_119 ) ;
return - V_104 ;
}
F_73 ( & V_35 -> V_120 ) ;
if ( V_35 -> V_97 ) {
F_50 ( V_35 , L_40 , V_18 ) ;
V_17 = - V_99 ;
goto V_100;
}
if ( F_24 ( V_35 , V_36 , V_37 ) ) {
F_50 ( V_35 , L_41 , V_18 , V_36 , V_37 ) ;
V_17 = - V_121 ;
goto V_100;
}
if ( ! ( V_117 = F_74 ( sizeof( struct V_33 ) , V_122 ) ) ) {
F_35 ( V_35 , L_42 , V_18 ) ;
V_17 = - V_123 ;
goto V_100;
}
V_117 -> V_5 = V_5 ;
V_117 -> V_36 = V_36 ;
V_117 -> V_37 = V_37 ;
V_117 -> V_40 = F_75 ( F_1 ( V_5 -> V_101 . V_118 . V_119 ) , V_122 ) ;
if ( ! V_117 -> V_40 ) {
F_35 ( V_35 , L_43 , V_18 ) ;
V_17 = - V_123 ;
goto V_100;
}
V_5 -> V_95 = V_117 ;
F_53 ( & V_35 -> V_63 . V_32 ) ;
V_35 -> V_44 = V_117 ;
V_35 -> V_43 = V_36 ;
V_35 -> V_42 = V_37 ;
F_15 ( & V_117 -> V_13 , & V_35 -> V_124 ) ;
F_54 ( & V_35 -> V_63 . V_32 ) ;
F_76 ( V_125 , & V_5 -> V_27 ) ;
F_76 ( V_126 , & V_5 -> V_27 ) ;
F_76 ( V_127 , & V_5 -> V_27 ) ;
F_77 ( & V_35 -> V_120 ) ;
F_50 ( V_35 , L_44 , V_18 , V_117 ) ;
return 0 ;
V_100:
F_64 ( V_117 ) ;
F_77 ( & V_35 -> V_120 ) ;
return V_17 ;
}
static void F_78 ( struct V_4 * V_5 )
{
struct V_34 * V_35 = V_5 -> V_94 -> V_95 ;
struct V_33 * V_38 = V_5 -> V_95 ;
if ( ! V_35 || ! V_38 )
return;
F_50 ( V_35 , L_21 , V_18 ) ;
F_50 ( V_35 , L_45 ,
V_18 , V_38 , V_38 -> V_36 , V_38 -> V_37 ) ;
F_49 ( V_35 , V_5 ) ;
F_73 ( & V_35 -> V_120 ) ;
F_53 ( & V_35 -> V_63 . V_32 ) ;
if ( V_35 -> V_44 == V_38 ) {
V_35 -> V_44 = NULL ;
V_35 -> V_43 = V_128 ;
V_35 -> V_42 = V_129 ;
}
F_9 ( & V_38 -> V_13 ) ;
F_54 ( & V_35 -> V_63 . V_32 ) ;
F_79 ( V_38 -> V_40 ) ;
V_38 -> V_40 = NULL ;
F_64 ( V_38 ) ;
V_5 -> V_95 = NULL ;
V_5 -> V_36 = V_128 ;
V_5 -> V_37 = V_129 ;
F_80 ( V_127 , & V_5 -> V_27 ) ;
F_80 ( V_126 , & V_5 -> V_27 ) ;
F_80 ( V_125 , & V_5 -> V_27 ) ;
F_77 ( & V_35 -> V_120 ) ;
F_50 ( V_35 , L_46 , V_18 ) ;
}
static int F_81 ( struct V_108 * V_108 , unsigned int V_130 ,
void T_3 * V_131 )
{
struct V_34 * V_35 = V_108 -> V_95 ;
if ( ! V_35 || V_35 -> V_97 )
return - V_99 ;
switch ( V_130 ) {
case V_132 :
return F_82 ( V_133 , ( int T_3 * ) V_131 ) ? - V_134 : 0 ;
default:
return - V_135 ;
}
}
static int F_83 ( struct V_34 * V_35 )
{
struct V_108 * V_108 ;
int V_17 , V_83 ;
V_108 = F_84 ( V_35 -> V_136 ,
& V_35 -> V_137 -> V_94 , & V_138 ,
- 1 , NULL ) ;
if ( ! V_108 ) {
F_85 ( V_35 , L_47 , V_18 ) ;
return - 1 ;
}
V_35 -> V_108 = V_108 ;
V_108 -> V_139 . V_140 = V_141 ;
V_108 -> V_139 . V_142 = V_141 ;
V_108 -> signal = V_143 ;
V_108 -> V_144 = 128 * 1000 / 424 ;
if ( V_35 -> V_145 -> V_146 && ( ( V_17 = V_35 -> V_145 -> V_146 ( V_35 , V_108 ) ) < 0 ) ) {
F_35 ( V_35 , L_48 , V_18 , V_17 ) ;
goto V_100;
}
F_65 ( V_35 ) ;
F_86 () ;
V_108 -> V_95 = V_35 ;
for ( V_83 = 0 ; V_83 < V_147 ; V_83 ++ )
F_10 ( V_35 -> V_148 [ V_83 ] ) ;
return 0 ;
V_100:
V_35 -> V_108 = NULL ;
F_87 ( V_108 ) ;
return V_17 ;
}
static int F_88 ( void * V_131 )
{
struct V_34 * V_35 = V_131 ;
int V_17 ;
F_89 ( V_149 ) ;
F_90 ( & V_35 -> V_150 ) ;
V_17 = V_35 -> V_145 -> V_151 ( V_35 , V_35 -> V_137 ) ;
if ( ! V_17 )
V_17 = F_83 ( V_35 ) ;
F_73 ( & V_35 -> V_120 ) ;
V_35 -> V_152 = NULL ;
F_77 ( & V_35 -> V_120 ) ;
F_91 ( & V_35 -> V_153 , V_17 ) ;
}
static int F_92 ( struct V_34 * V_35 )
{
struct V_154 * V_155 ;
V_155 = F_93 ( F_88 , V_35 ,
V_35 -> V_145 -> V_136 ) ;
if ( F_94 ( V_155 ) ) {
F_85 ( V_35 , L_49 ,
V_18 , F_95 ( V_155 ) ) ;
return F_95 ( V_155 ) ;
}
V_35 -> V_152 = V_155 ;
F_96 ( V_155 ) ;
F_97 ( & V_35 -> V_150 ) ;
return 0 ;
}
static void F_98 ( unsigned long V_58 )
{
F_23 ( (struct V_156 * ) V_58 ) ;
}
static void F_99 ( struct V_10 * V_11 )
{
F_100 ( & V_11 -> V_12 ) ;
F_101 ( & V_11 -> V_13 ) ;
V_11 -> V_24 . V_157 = F_98 ;
V_11 -> V_24 . V_58 = ( unsigned long ) & V_11 -> V_32 ;
F_102 ( & V_11 -> V_24 ) ;
}
int F_103 ( struct V_158 * V_159 , const struct V_160 * V_161 ,
struct V_162 * V_145 )
{
struct V_163 * V_94 = & V_159 -> V_94 ;
struct V_164 * V_107 = F_104 ( V_159 ) ;
struct V_34 * V_35 ;
char * V_165 ;
int error = - V_123 ;
int V_83 , V_1 ;
unsigned int V_166 , V_167 ;
F_105 ( V_94 , L_50 ,
V_18 , V_145 -> V_136 ,
F_106 ( V_107 -> V_168 . V_169 ) ,
F_106 ( V_107 -> V_168 . V_170 ) ,
V_159 -> V_171 -> V_172 . V_173 ) ;
V_35 = F_74 ( sizeof( * V_35 ) + sizeof( struct V_9 * ) * ( V_147 + V_174 ) , V_122 ) ;
if ( ! V_35 ) {
F_107 ( V_94 , L_51 , V_18 ) ;
return - V_123 ;
}
V_35 -> V_145 = V_145 ;
snprintf ( V_35 -> V_136 , sizeof( V_35 -> V_136 ) , V_145 -> V_136 ) ;
V_35 -> V_107 = V_107 ;
V_35 -> V_137 = V_159 ;
V_165 = V_35 -> V_111 ;
V_1 = sizeof( V_35 -> V_111 ) ;
if ( ( V_83 = F_108 ( V_107 , V_107 -> V_168 . V_175 , V_165 , V_1 ) ) < 0 )
goto V_176;
V_165 += V_83 ;
V_1 -= V_83 ;
V_83 = F_109 ( V_165 , V_1 , L_52 ) ;
V_165 += V_83 ;
V_1 -= V_83 ;
if ( V_1 <= 0 || ( V_83 = F_110 ( V_107 , V_165 , V_1 ) ) < 0 )
goto V_176;
V_165 += V_83 ;
V_1 -= V_83 ;
snprintf ( V_165 , V_1 , L_53 ) ;
V_176:
if ( V_145 -> V_176 && ( error = V_145 -> V_176 ( V_35 , V_159 , V_161 ) ) < 0 ) {
F_107 ( V_94 , L_54 , V_18 , error ) ;
goto V_177;
}
F_111 ( & V_35 -> V_106 ) ;
F_112 ( & V_35 -> V_120 ) ;
V_35 -> V_152 = NULL ;
F_113 ( & V_35 -> V_150 ) ;
F_113 ( & V_35 -> V_153 ) ;
F_101 ( & V_35 -> V_124 ) ;
F_114 ( & V_35 -> V_91 ) ;
F_99 ( & V_35 -> V_63 ) ;
F_99 ( & V_35 -> V_73 ) ;
F_115 ( & V_35 -> V_63 . V_32 , F_45 , ( unsigned long ) V_35 ) ;
F_115 ( & V_35 -> V_73 . V_32 , F_47 , ( unsigned long ) V_35 ) ;
V_35 -> V_63 . V_62 = V_53 + V_145 -> V_178 ;
V_35 -> V_73 . V_62 = V_53 + V_145 -> V_179 ;
V_35 -> V_63 . V_21 = V_35 -> V_73 . V_21 = V_35 ;
if ( ( V_35 -> V_27 & V_180 ) && V_145 -> V_181 )
V_35 -> V_63 . V_182 = F_116 ( V_107 , V_145 -> V_181 ) ;
else
V_35 -> V_63 . V_182 = F_117 ( V_107 , V_145 -> V_183 ) ;
V_35 -> V_73 . V_182 = F_118 ( V_107 , V_145 -> V_184 ) ;
V_35 -> V_73 . V_89 = F_119 ( V_35 -> V_73 . V_62 ,
V_185 - ( V_185 % V_35 -> V_73 . V_62 ) ) ;
V_166 = F_120 ( V_107 , V_35 -> V_63 . V_182 , 0 ) ;
if ( ( V_166 < 1 ) || ( V_166 > V_186 ) ) {
F_107 ( V_94 , L_55 , V_18 ,
F_121 ( V_35 -> V_63 . V_182 ) ) ;
error = - V_104 ;
goto V_187;
}
V_167 = F_119 ( 1U , ( V_188 + V_166 / 2 ) / V_166 ) ;
if ( V_167 * V_166 > V_186 )
V_167 -- ;
V_35 -> V_63 . V_89 = V_167 * V_166 ;
V_35 -> V_63 . V_82 = V_166 ;
#ifdef F_56
for ( V_83 = 0 ; V_83 < 2 ; V_83 ++ ) {
struct V_10 * V_11 = V_83 ?
& V_35 -> V_73 : & V_35 -> V_63 ;
F_105 ( V_94 , L_56 , V_18 , V_11 -> V_89 , V_83 ? L_57 : L_58 , V_11 ) ;
}
#endif
for ( V_83 = 0 ; V_83 < V_147 + V_174 ; V_83 ++ ) {
T_1 * V_90 ;
struct V_10 * V_11 = V_83 < V_147 ?
& V_35 -> V_63 : & V_35 -> V_73 ;
struct V_9 * V_9 ;
unsigned int V_189 = F_46 ( V_11 -> V_182 ) ? V_11 -> V_89 / V_11 -> V_82 : 0 ;
F_30 ( V_35 , ! F_46 ( V_11 -> V_182 ) || F_122 ( V_11 -> V_182 ) ) ;
V_9 = F_123 ( V_189 , V_122 ) ;
if ( ! V_9 ) {
F_107 ( V_94 , L_59 , V_18 , V_83 ) ;
error = - V_123 ;
goto V_187;
}
V_35 -> V_148 [ V_83 ] = V_9 ;
V_90 = F_74 ( V_11 -> V_89 , V_122 ) ;
if ( ! V_90 ) {
F_107 ( V_94 , L_60 , V_18 , V_83 ) ;
error = - V_123 ;
goto V_187;
}
F_124 ( V_9 , V_35 -> V_107 , V_11 -> V_182 ,
V_90 , V_11 -> V_89 , F_18 , V_11 ) ;
if ( V_189 ) {
int V_190 ;
V_9 -> V_191 = 1 ;
V_9 -> V_192 = V_193 ;
V_9 -> V_84 = V_189 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
V_9 -> V_85 [ V_190 ] . V_87 = V_11 -> V_82 * V_190 ;
V_9 -> V_85 [ V_190 ] . V_1 = V_11 -> V_82 ;
}
}
if ( V_83 >= V_147 )
F_20 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_11 ( L_61 ,
V_18 , V_9 -> V_86 , V_9 -> V_19 , V_9 ) ;
}
V_35 -> V_43 = V_128 ;
V_35 -> V_42 = V_129 ;
V_35 -> V_65 = F_125 ( V_35 -> V_63 . V_62 , V_122 ) ;
if ( ! V_35 -> V_65 ) {
F_107 ( V_94 , L_62 , V_18 ) ;
error = - V_123 ;
goto V_187;
}
if ( ! ( V_35 -> V_27 & V_194 ) && V_145 -> V_151 ) {
error = F_92 ( V_35 ) ;
} else {
F_90 ( & V_35 -> V_153 ) ;
error = F_83 ( V_35 ) ;
}
if ( error < 0 )
goto V_187;
F_126 ( V_107 ) ;
F_127 ( V_159 , V_35 ) ;
return 0 ;
V_187:
if ( V_35 -> V_145 -> V_195 )
V_35 -> V_145 -> V_195 ( V_35 , V_159 ) ;
V_177:
F_64 ( V_35 -> V_65 ) ;
for ( V_83 = 0 ; V_83 < V_147 + V_174 ; V_83 ++ ) {
if ( V_35 -> V_148 [ V_83 ] )
F_64 ( V_35 -> V_148 [ V_83 ] -> V_86 ) ;
F_128 ( V_35 -> V_148 [ V_83 ] ) ;
}
F_64 ( V_35 ) ;
return error ;
}
void F_129 ( struct V_158 * V_159 )
{
struct V_163 * V_94 = & V_159 -> V_94 ;
struct V_34 * V_35 = F_130 ( V_159 ) ;
struct V_33 * V_38 ;
int V_83 ;
F_105 ( V_94 , L_21 , V_18 ) ;
if ( ! V_35 ) {
F_105 ( V_94 , L_63 , V_18 ) ;
return;
}
F_127 ( V_159 , NULL ) ;
F_73 ( & V_35 -> V_120 ) ;
V_35 -> V_97 = 1 ;
if ( V_35 -> V_152 != NULL )
F_131 ( V_149 , V_35 -> V_152 , 1 ) ;
F_77 ( & V_35 -> V_120 ) ;
F_97 ( & V_35 -> V_153 ) ;
F_73 ( & V_35 -> V_120 ) ;
F_25 (vcc_data, &instance->vcc_list, list)
F_132 ( V_38 -> V_5 , - V_196 ) ;
F_77 ( & V_35 -> V_120 ) ;
F_53 ( & V_35 -> V_63 . V_32 ) ;
F_53 ( & V_35 -> V_73 . V_32 ) ;
for ( V_83 = 0 ; V_83 < V_147 + V_174 ; V_83 ++ )
F_133 ( V_35 -> V_148 [ V_83 ] ) ;
F_134 ( & V_35 -> V_63 . V_24 ) ;
F_134 ( & V_35 -> V_73 . V_24 ) ;
F_101 ( & V_35 -> V_63 . V_13 ) ;
F_101 ( & V_35 -> V_73 . V_13 ) ;
F_54 ( & V_35 -> V_63 . V_32 ) ;
F_54 ( & V_35 -> V_73 . V_32 ) ;
if ( V_35 -> V_108 && V_35 -> V_145 -> V_197 )
V_35 -> V_145 -> V_197 ( V_35 , V_35 -> V_108 ) ;
if ( V_35 -> V_145 -> V_195 )
V_35 -> V_145 -> V_195 ( V_35 , V_159 ) ;
V_35 -> V_198 = NULL ;
for ( V_83 = 0 ; V_83 < V_147 + V_174 ; V_83 ++ ) {
F_64 ( V_35 -> V_148 [ V_83 ] -> V_86 ) ;
F_128 ( V_35 -> V_148 [ V_83 ] ) ;
}
F_64 ( V_35 -> V_65 ) ;
if ( V_35 -> V_108 ) {
F_87 ( V_35 -> V_108 ) ;
V_35 -> V_108 = NULL ;
}
F_67 ( V_35 ) ;
}
static int T_4 F_135 ( void )
{
if ( sizeof( struct V_69 ) > F_136 ( struct V_6 , V_199 ) ) {
F_137 ( V_200 L_64 , V_201 ) ;
return - V_202 ;
}
if ( ( V_147 > V_203 )
|| ( V_174 > V_204 )
|| ( V_188 < 1 )
|| ( V_188 > V_186 )
|| ( V_185 < 1 )
|| ( V_185 > V_186 ) )
return - V_104 ;
return 0 ;
}
static void T_5 F_138 ( void )
{
}
static int F_139 ( const unsigned char * V_58 , int V_50 )
{
unsigned char V_90 [ 256 ] ;
int V_83 = 0 , V_190 = 0 ;
for ( V_83 = 0 ; V_83 < V_50 ; ) {
V_90 [ 0 ] = '\0' ;
sprintf ( V_90 , L_65 , V_83 ) ;
for ( V_190 = 0 ; ( V_190 < 16 ) && ( V_83 < V_50 ) ; V_190 ++ , V_83 ++ )
sprintf ( V_90 , L_66 , V_90 , V_58 [ V_83 ] ) ;
F_140 ( L_67 , V_90 ) ;
}
return V_83 ;
}
