static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 , V_6 = - V_7 ;
const struct V_8 * V_9 = NULL , * V_10 = NULL ;
const struct V_11 * V_12 ;
F_2 ( L_1 , V_13 ) ;
if ( F_3 ( & V_10 , L_2 ,
& V_2 -> V_14 -> V_14 ) ) {
F_4 ( & V_2 -> V_14 -> V_14 ,
L_3 , V_13 ) ;
goto V_15;
}
if ( F_3 ( & V_9 , L_4 ,
& V_2 -> V_14 -> V_14 ) ) {
F_4 ( & V_2 -> V_14 -> V_14 ,
L_5 ,
V_13 ) ;
goto V_15;
}
V_6 = 0 ;
V_5 = F_5 ( V_2 , 1 ) ;
V_12 = ( const struct V_11 * ) V_9 -> V_16 ;
while ( V_12 ) {
V_5 = F_6 ( V_2 , F_7 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_8 ( V_12 -> V_18 ) , 0xa0 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_6
L_7 ,
V_13 , V_5 , F_7 ( V_12 -> V_17 ) ,
V_12 -> V_16 , F_8 ( V_12 -> V_18 ) ) ;
break;
}
V_12 = F_9 ( V_12 ) ;
}
V_5 = F_5 ( V_2 , 0 ) ;
V_12 = ( const struct V_11 * ) V_10 -> V_16 ;
while ( V_12 && F_7 ( V_12 -> V_17 ) < 0x1b40 )
V_12 = F_9 ( V_12 ) ;
while ( V_12 ) {
V_5 = F_6 ( V_2 , F_7 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_8 ( V_12 -> V_18 ) , 0xa3 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_6
L_8
L_9 , V_13 , V_5 ,
F_7 ( V_12 -> V_17 ) , V_12 -> V_16 ,
F_8 ( V_12 -> V_18 ) ) ;
break;
}
++ V_12 ;
}
V_5 = F_5 ( V_2 , 1 ) ;
V_12 = ( const struct V_11 * ) V_10 -> V_16 ;
while ( V_12 && F_7 ( V_12 -> V_17 ) < 0x1b40 ) {
V_5 = F_6 ( V_2 , F_7 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_8 ( V_12 -> V_18 ) , 0xa0 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_6
L_10
L_9 , V_13 , V_5 ,
F_7 ( V_12 -> V_17 ) , V_12 -> V_16 ,
F_8 ( V_12 -> V_18 ) ) ;
break;
}
++ V_12 ;
}
V_6 = 0 ;
V_5 = F_5 ( V_2 , 0 ) ;
V_15:
F_10 ( V_9 ) ;
F_10 ( V_10 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_19 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
int V_6 ;
int V_29 ;
T_1 * V_30 ;
T_1 * V_31 ;
int V_32 ;
int V_33 ;
struct V_34 * V_34 ;
int V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_20 = V_2 -> V_23 [ V_40 ] ;
V_28 = F_13 ( V_2 -> V_14 ,
V_20 -> V_41 ) ;
V_30 = F_14 ( 2 , V_42 ) ;
if ( ! V_30 )
goto V_43;
V_30 [ 0 ] = V_44 ;
V_30 [ 1 ] = 0 ;
V_31 = F_14 ( sizeof( * V_27 ) + 1 , V_42 ) ;
if ( ! V_31 )
goto V_45;
F_15 ( V_2 -> V_14 , V_28 ) ;
V_6 = F_16 ( V_2 -> V_14 , V_28 , V_30 , 2 ,
& V_29 , V_46 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_11 ,
V_2 -> type -> V_47 , V_6 ) ;
goto V_48;
} else if ( V_29 != 2 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_12 ,
V_2 -> type -> V_47 , V_29 ) ;
goto V_48;
}
V_28 = F_17 ( V_2 -> V_14 ,
V_20 -> V_49 ) ;
F_15 ( V_2 -> V_14 , V_28 ) ;
V_6 = F_16 ( V_2 -> V_14 , V_28 , V_31 ,
sizeof( * V_27 ) + 1 , & V_29 , V_46 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_13 ,
V_2 -> type -> V_47 , V_6 ) ;
goto V_48;
} else if ( V_29 != sizeof( * V_27 ) + 1 ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_14 ,
V_2 -> type -> V_47 , V_29 ) ;
goto V_48;
} else if ( V_31 [ 0 ] != V_30 [ 0 ] ) {
F_4 ( & V_2 -> V_14 -> V_14 , L_15 ,
V_2 -> type -> V_47 , V_31 [ 0 ] ) ;
goto V_48;
}
V_27 = (struct V_26 * ) & V_31 [ 1 ] ;
F_18 ( & V_2 -> V_14 -> V_14 , L_16 ,
V_2 -> type -> V_47 , V_50 ,
V_27 -> V_51 , V_27 -> V_52 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_53 ; V_32 ++ ) {
V_23 = V_2 -> V_23 [ V_32 ] ;
V_25 = F_14 ( sizeof( struct V_24 ) , V_42 ) ;
if ( V_25 == NULL ) {
F_4 ( & V_23 -> V_14 ,
L_17 ,
V_2 -> type -> V_47 ) ;
goto V_54;
}
F_19 ( & V_25 -> V_55 ) ;
F_20 ( & V_25 -> V_56 ) ;
V_25 -> V_57 = 0 ;
V_25 -> V_58 = 0 ;
F_21 ( & V_25 -> V_59 , V_60 ) ;
V_25 -> V_23 = V_23 ;
F_22 ( & V_25 -> V_61 ) ;
F_22 ( & V_25 -> V_62 ) ;
F_22 ( & V_25 -> V_63 ) ;
F_22 ( & V_25 -> V_64 ) ;
F_22 ( & V_25 -> V_65 ) ;
for ( V_33 = 0 ; V_33 < V_66 ; V_33 ++ ) {
V_34 = F_23 ( 0 , V_42 ) ;
if ( ! V_34 ) {
F_4 ( & V_23 -> V_14 , L_18 ) ;
goto V_67;
}
V_35 = V_23 -> V_68 -> V_69 ;
V_34 -> V_70 = F_14 ( V_35 , V_42 ) ;
if ( ! V_34 -> V_70 ) {
F_4 ( & V_23 -> V_14 ,
L_19 ) ;
goto V_71;
}
V_37 = F_14 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 ) {
F_4 ( & V_23 -> V_14 ,
L_20 ) ;
goto V_72;
}
F_24 ( V_34 , V_2 -> V_14 ,
F_17 ( V_2 -> V_14 ,
V_23 -> V_49 ) ,
V_34 -> V_70 , V_35 ,
V_73 , V_23 ) ;
V_37 -> V_34 = V_34 ;
F_25 ( & V_37 -> V_74 , & V_25 -> V_61 ) ;
V_34 = F_23 ( 0 , V_42 ) ;
if ( ! V_34 ) {
F_4 ( & V_23 -> V_14 , L_18 ) ;
goto V_75;
}
V_35 = V_23 -> V_76 -> V_69 ;
V_34 -> V_70 = F_14 ( V_35 , V_42 ) ;
if ( ! V_34 -> V_70 ) {
F_4 ( & V_23 -> V_14 ,
L_19 ) ;
goto V_77;
}
V_37 = F_14 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 ) {
F_4 ( & V_23 -> V_14 ,
L_20 ) ;
goto V_78;
}
F_24 ( V_34 , V_2 -> V_14 ,
F_13 ( V_2 -> V_14 ,
V_23 -> V_41 ) ,
V_34 -> V_70 , V_35 ,
V_79 , V_23 ) ;
V_37 -> V_34 = V_34 ;
F_25 ( & V_37 -> V_74 , & V_25 -> V_64 ) ;
}
F_26 ( V_23 , V_25 ) ;
}
V_22 = F_14 ( sizeof( struct V_21 ) ,
V_42 ) ;
if ( V_22 == NULL ) {
F_4 ( & V_2 -> V_14 -> V_14 ,
L_17 ,
V_2 -> type -> V_47 ) ;
goto V_80;
}
F_20 ( & V_22 -> V_81 ) ;
V_22 -> V_82 = 0 ;
F_27 ( & V_22 -> V_83 ) ;
F_26 ( V_20 , V_22 ) ;
V_20 -> V_76 -> V_84 = V_85 ;
V_20 -> V_68 -> V_84 = V_86 ;
F_28 ( V_31 ) ;
F_28 ( V_30 ) ;
return 0 ;
V_48:
F_4 ( & V_2 -> V_14 -> V_14 ,
L_21 ,
V_2 -> type -> V_47 ) ;
F_4 ( & V_2 -> V_14 -> V_14 ,
L_22 ,
V_2 -> type -> V_47 ) ;
F_4 ( & V_2 -> V_14 -> V_14 ,
L_23 ,
V_2 -> type -> V_47 ) ;
F_28 ( V_31 ) ;
return - V_87 ;
V_80:
for ( V_32 = V_2 -> V_53 - 1 ; V_32 >= 0 ; V_32 -- ) {
V_23 = V_2 -> V_23 [ V_32 ] ;
V_25 = F_29 ( V_23 ) ;
for ( V_33 = V_66 - 1 ; V_33 >= 0 ; V_33 -- ) {
V_39 = F_30 ( & V_25 -> V_64 ) ;
F_31 ( V_39 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_28 ( V_37 ) ;
V_78:
F_28 ( V_34 -> V_70 ) ;
V_77:
F_33 ( V_34 ) ;
V_75:
V_39 = F_30 ( & V_25 -> V_61 ) ;
F_31 ( V_39 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_28 ( V_37 ) ;
V_72:
F_28 ( V_34 -> V_70 ) ;
V_71:
F_33 ( V_34 ) ;
V_67:
;
}
F_28 ( V_25 ) ;
V_54:
;
}
F_28 ( V_31 ) ;
V_45:
F_28 ( V_30 ) ;
V_43:
return - V_88 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_19 * V_23 ;
struct V_24 * V_25 ;
struct V_36 * V_37 ;
struct V_34 * V_34 ;
struct V_38 * V_39 ;
struct V_38 * V_89 ;
int V_32 ;
F_2 ( L_1 , V_13 ) ;
V_20 = V_2 -> V_23 [ V_40 ] ;
F_28 ( F_29 ( V_20 ) ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_53 ; V_32 ++ ) {
V_23 = V_2 -> V_23 [ V_32 ] ;
V_25 = F_29 ( V_23 ) ;
F_35 (tmp, tmp2, &info->rx_urbs_free) {
F_31 ( V_39 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_28 ( V_37 ) ;
F_28 ( V_34 -> V_70 ) ;
F_33 ( V_34 ) ;
}
F_35 (tmp, tmp2, &info->tx_urbs_free) {
F_31 ( V_39 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_28 ( V_37 ) ;
F_28 ( V_34 -> V_70 ) ;
F_33 ( V_34 ) ;
}
F_28 ( V_25 ) ;
}
}
static int F_36 ( struct V_90 * V_91 , struct V_19 * V_23 )
{
int V_92 = 0 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
V_92 = F_37 ( V_23 -> V_2 ) ;
if ( V_92 )
goto exit;
if ( V_91 )
V_91 -> V_94 = 1 ;
V_92 = F_38 ( V_23 ) ;
if ( V_92 ) {
F_39 ( V_23 -> V_2 ) ;
goto exit;
}
V_92 = F_40 ( V_23 , V_95 | V_96 ) ;
if ( V_92 ) {
F_41 ( V_23 ) ;
F_39 ( V_23 -> V_2 ) ;
goto exit;
}
if ( V_91 )
F_42 ( V_91 ) ;
F_15 ( V_23 -> V_2 -> V_14 , V_23 -> V_68 -> V_28 ) ;
F_15 ( V_23 -> V_2 -> V_14 , V_23 -> V_76 -> V_28 ) ;
V_92 = F_43 ( V_23 ) ;
if ( V_92 ) {
F_4 ( & V_23 -> V_14 ,
L_25 ,
V_13 , V_92 ) ;
F_41 ( V_23 ) ;
F_39 ( V_23 -> V_2 ) ;
goto exit;
}
exit:
F_2 ( L_26 , V_13 , V_92 ) ;
return V_92 ;
}
static void F_44 ( struct V_19 * V_23 )
{
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_36 * V_37 ;
struct V_34 * V_34 ;
struct V_38 * V_39 ;
struct V_38 * V_89 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_45 ( V_23 ) ;
F_41 ( V_23 ) ;
F_46 ( & V_25 -> V_56 ) ;
F_47 ( & V_25 -> V_55 ) ;
F_35 (tmp, tmp2, &info->rx_urbs_submitted) {
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_31 ( V_39 ) ;
F_48 ( & V_25 -> V_55 ) ;
F_49 ( V_34 ) ;
F_47 ( & V_25 -> V_55 ) ;
F_25 ( V_39 , & V_25 -> V_61 ) ;
}
F_35 (tmp, tmp2, &info->rx_urb_q)
F_50 ( V_39 , & V_25 -> V_61 ) ;
F_35 (tmp, tmp2, &info->tx_urbs_submitted) {
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_31 ( V_39 ) ;
F_48 ( & V_25 -> V_55 ) ;
F_49 ( V_34 ) ;
F_47 ( & V_25 -> V_55 ) ;
F_25 ( V_39 , & V_25 -> V_64 ) ;
}
F_48 ( & V_25 -> V_55 ) ;
F_51 ( & V_25 -> V_56 ) ;
F_39 ( V_23 -> V_2 ) ;
}
static int F_52 ( struct V_90 * V_91 ,
struct V_19 * V_23 , const unsigned char * V_97 , int V_98 )
{
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_36 * V_37 ;
struct V_34 * V_34 ;
int V_31 ;
int V_99 ;
int V_100 = 0 ;
unsigned long V_57 ;
struct V_38 * V_39 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
if ( V_98 == 0 ) {
F_2 ( L_27 , V_13 ) ;
return ( 0 ) ;
}
while ( V_98 ) {
F_53 ( & V_25 -> V_55 , V_57 ) ;
if ( F_54 ( & V_25 -> V_64 ) ) {
F_55 ( & V_25 -> V_55 , V_57 ) ;
break;
}
V_39 = F_30 ( & V_25 -> V_64 ) ;
F_31 ( V_39 ) ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
V_99 = ( V_98 > V_23 -> V_101 ) ?
V_23 -> V_101 : V_98 ;
memcpy ( V_34 -> V_70 , V_97 + V_100 , V_99 ) ;
F_56 ( V_102 , & V_23 -> V_14 ,
V_13 , V_99 , V_34 -> V_70 ) ;
V_34 -> V_69 = V_99 ;
V_31 = F_57 ( V_34 , V_103 ) ;
if ( V_31 ) {
F_4 ( & V_23 -> V_14 ,
L_28 ,
V_13 , V_31 ) ;
V_100 = V_31 ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_64 ) ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
break;
} else {
V_100 += V_99 ;
V_98 -= V_99 ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_65 ) ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
}
}
return V_100 ;
}
static int F_58 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_38 * V_39 ;
int V_105 = 0 ;
unsigned long V_57 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_59 (tmp, &info->tx_urbs_free)
V_105 ++ ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
V_105 *= V_23 -> V_101 ;
F_2 ( L_29 , V_13 , V_105 ) ;
return ( V_105 ) ;
}
static int F_60 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
unsigned int V_106 = 0 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_61 ( V_23 ) ;
if ( V_25 -> V_58 & V_107 )
V_106 |= V_108 ;
if ( V_25 -> V_58 & V_109 )
V_106 |= V_110 ;
return V_106 ;
}
static int F_62 ( struct V_90 * V_91 ,
unsigned int V_111 , unsigned int V_112 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
if ( V_111 & V_110 )
V_25 -> V_58 |= V_109 ;
if ( V_111 & V_108 )
V_25 -> V_58 |= V_107 ;
if ( V_112 & V_110 )
V_25 -> V_58 &= ~ V_109 ;
if ( V_112 & V_108 )
V_25 -> V_58 &= ~ V_107 ;
F_63 ( V_23 , V_25 -> V_58 & V_107 ) ;
F_64 ( V_23 , V_25 -> V_58 & V_109 ) ;
return 0 ;
}
static int F_65 ( struct V_90 * V_91 ,
unsigned int V_113 , unsigned long V_114 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_115 V_116 ;
void T_2 * V_117 = ( void T_2 * ) V_114 ;
F_2 ( L_30 , V_13 , V_23 -> V_93 , V_113 ) ;
switch ( V_113 ) {
case V_118 :
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . type = V_119 ;
V_116 . line = V_23 -> V_2 -> V_120 ;
V_116 . V_23 = V_23 -> V_93 ;
V_116 . V_57 = V_121 | V_122 ;
V_116 . V_123 = V_23 -> V_101 ;
V_116 . V_124 = 0 ;
V_116 . V_125 = 460800 ;
V_116 . V_126 = V_127 ;
V_116 . V_128 = V_127 ;
if ( F_66 ( V_117 , & V_116 , sizeof( V_116 ) ) )
return - V_129 ;
break;
default:
break;
}
return - V_130 ;
}
static void F_67 ( struct V_90 * V_91 ,
struct V_19 * V_23 , struct V_131 * V_132 )
{
F_42 ( V_91 ) ;
}
static void F_68 ( struct V_90 * V_91 , int V_133 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
F_69 ( V_23 , V_133 ) ;
}
static int F_70 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_38 * V_39 ;
struct V_36 * V_37 ;
int V_134 = 0 ;
unsigned long V_57 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_59 (tmp, &info->tx_urbs_submitted) {
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_134 += V_37 -> V_34 -> V_69 ;
}
F_55 ( & V_25 -> V_55 , V_57 ) ;
F_2 ( L_29 , V_13 , V_134 ) ;
return V_134 ;
}
static void F_71 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_47 ( & V_25 -> V_55 ) ;
V_25 -> V_57 |= V_135 ;
F_48 ( & V_25 -> V_55 ) ;
}
static void F_72 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
int V_136 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_47 ( & V_25 -> V_55 ) ;
V_136 = V_25 -> V_57 & V_137 ;
V_25 -> V_57 &= ~ ( V_135 | V_137 ) ;
F_48 ( & V_25 -> V_55 ) ;
if ( V_136 )
V_60 ( & V_25 -> V_59 ) ;
}
static void V_85 ( struct V_34 * V_34 )
{
int V_138 = V_34 -> V_138 ;
F_2 ( L_1 , V_13 ) ;
if ( V_138 ) {
F_2 ( L_31 , V_138 ) ;
return;
}
}
static void V_86 ( struct V_34 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_139 ;
struct V_21 * V_22 ;
int V_138 = V_34 -> V_138 ;
unsigned char * V_16 = V_34 -> V_70 ;
int V_31 ;
F_2 ( L_1 , V_13 ) ;
V_22 = F_29 ( V_20 ) ;
if ( ! V_22 ) {
F_2 ( L_32 , V_13 ) ;
return;
}
if ( V_138 ) {
F_2 ( L_33 , V_13 , V_138 ) ;
if ( V_138 != - V_7 )
V_22 -> V_140 = V_141 ;
F_73 ( & V_22 -> V_83 ) ;
return;
}
F_56 ( V_102 , & V_20 -> V_14 ,
V_13 , V_34 -> V_142 , V_16 ) ;
if ( V_16 [ 0 ] == V_143 ) {
V_22 -> V_140 = V_143 ;
F_73 ( & V_22 -> V_83 ) ;
} else if ( V_16 [ 0 ] == V_141 ) {
V_22 -> V_140 = V_141 ;
F_73 ( & V_22 -> V_83 ) ;
} else if ( V_16 [ 0 ] == V_144 ) {
F_2 ( L_34 , V_13 ) ;
} else if ( V_16 [ 0 ] == V_145 ) {
memcpy ( V_22 -> V_146 , & V_16 [ 1 ] ,
V_34 -> V_142 - 1 ) ;
V_22 -> V_140 = V_143 ;
F_73 ( & V_22 -> V_83 ) ;
} else
F_2 ( L_35 , V_13 ) ;
V_31 = F_57 ( V_20 -> V_68 , V_103 ) ;
if ( V_31 )
F_2 ( L_36 ,
V_13 , V_31 ) ;
}
static void V_73 ( struct V_34 * V_34 )
{
struct V_19 * V_23 = V_34 -> V_139 ;
struct V_36 * V_37 ;
unsigned char * V_16 = V_34 -> V_70 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
int V_138 = V_34 -> V_138 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_74 ( & V_25 -> V_55 ) ;
V_37 = F_75 ( V_34 , & V_25 -> V_62 ) ;
if ( ! V_37 ) {
F_76 ( & V_25 -> V_55 ) ;
F_4 ( & V_23 -> V_14 , L_37 , V_13 ) ;
return;
}
F_31 ( & V_37 -> V_74 ) ;
F_76 ( & V_25 -> V_55 ) ;
if ( V_138 ) {
F_2 ( L_38 ,
V_13 , V_138 ) ;
F_74 ( & V_25 -> V_55 ) ;
F_25 ( & V_37 -> V_74 , & V_25 -> V_61 ) ;
F_76 ( & V_25 -> V_55 ) ;
return;
}
F_56 ( V_102 , & V_23 -> V_14 ,
V_13 , V_34 -> V_142 , V_16 ) ;
F_74 ( & V_25 -> V_55 ) ;
F_77 ( & V_37 -> V_74 , & V_25 -> V_63 ) ;
if ( V_25 -> V_57 & V_135 ) {
V_25 -> V_57 |= V_137 ;
F_76 ( & V_25 -> V_55 ) ;
return;
}
F_76 ( & V_25 -> V_55 ) ;
F_78 ( & V_25 -> V_59 ) ;
}
static void V_79 ( struct V_34 * V_34 )
{
struct V_19 * V_23 = V_34 -> V_139 ;
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_36 * V_37 ;
int V_138 = V_34 -> V_138 ;
F_2 ( L_24 , V_13 , V_23 -> V_93 ) ;
F_74 ( & V_25 -> V_55 ) ;
V_37 = F_75 ( V_34 , & V_25 -> V_65 ) ;
if ( ! V_37 ) {
F_76 ( & V_25 -> V_55 ) ;
F_4 ( & V_23 -> V_14 , L_37 , V_13 ) ;
return;
}
F_50 ( & V_37 -> V_74 , & V_25 -> V_64 ) ;
F_76 ( & V_25 -> V_55 ) ;
if ( V_138 ) {
F_2 ( L_39 ,
V_13 , V_138 ) ;
return;
}
F_79 ( V_23 ) ;
}
static int F_80 ( struct V_19 * V_23 , T_1 V_30 ,
T_1 * V_16 , T_1 V_147 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
T_1 * V_70 ;
int V_92 = 0 ;
int V_148 ;
F_2 ( L_40 , V_13 , V_30 ) ;
V_20 = V_23 -> V_2 -> V_23 [ V_40 ] ;
V_22 = F_29 ( V_20 ) ;
F_46 ( & V_22 -> V_81 ) ;
V_22 -> V_140 = false ;
V_70 = ( T_1 * ) V_20 -> V_76 -> V_70 ;
V_70 [ 0 ] = V_30 ;
memcpy ( & V_70 [ 1 ] , V_16 , V_147 ) ;
V_20 -> V_76 -> V_69 = V_147 + 1 ;
V_92 = F_57 ( V_20 -> V_76 , V_149 ) ;
if ( V_92 ) {
F_2 ( L_41 , V_13 ) ;
goto exit;
}
V_148 = F_81 ( V_22 -> V_83 ,
( bool ) V_22 -> V_140 , V_150 ) ;
if ( ! V_148 )
F_49 ( V_20 -> V_76 ) ;
if ( V_22 -> V_140 == false ) {
F_2 ( L_42 , V_13 ) ;
V_92 = - V_151 ;
goto exit;
}
if ( V_22 -> V_140 == V_141 ) {
F_2 ( L_43 , V_13 ) ;
V_92 = - V_152 ;
goto exit;
}
if ( V_22 -> V_140 == V_143 ) {
F_2 ( L_44 , V_13 ) ;
switch ( V_30 ) {
case V_145 :
V_25 = F_29 ( V_23 ) ;
memcpy ( & V_25 -> V_58 , V_22 -> V_146 ,
sizeof( struct V_153 ) ) ;
break;
}
}
exit:
F_51 ( & V_22 -> V_81 ) ;
return V_92 ;
}
static int F_38 ( struct V_19 * V_23 )
{
struct V_154 V_155 ;
V_155 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
return F_80 ( V_23 , V_156 ,
( T_1 * ) & V_155 , sizeof( V_155 ) ) ;
}
static int F_41 ( struct V_19 * V_23 )
{
struct V_154 V_157 ;
V_157 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
return F_80 ( V_23 , V_158 ,
( T_1 * ) & V_157 , sizeof( V_157 ) ) ;
}
static void F_42 ( struct V_90 * V_91 )
{
struct V_19 * V_23 = V_91 -> V_104 ;
struct V_159 V_160 ;
unsigned int V_161 = V_91 -> V_162 -> V_163 ;
V_160 . V_23 = V_23 -> V_93 + 1 ;
switch ( V_161 & V_164 ) {
case V_165 : V_160 . V_166 = 5 ; break;
case V_167 : V_160 . V_166 = 6 ; break;
case V_168 : V_160 . V_166 = 7 ; break;
default:
case V_169 : V_160 . V_166 = 8 ; break;
}
F_2 ( L_45 , V_13 , V_160 . V_166 ) ;
if ( V_161 & V_170 )
if ( V_161 & V_171 )
if ( V_161 & V_172 )
V_160 . V_173 = V_174 ;
else
V_160 . V_173 = V_175 ;
else
if ( V_161 & V_172 )
V_160 . V_173 = V_176 ;
else
V_160 . V_173 = V_177 ;
else
V_160 . V_173 = V_178 ;
F_2 ( L_46 , V_13 , V_160 . V_173 ) ;
if ( V_161 & V_179 )
V_160 . V_180 = 2 ;
else
V_160 . V_180 = 1 ;
F_2 ( L_47 , V_13 , V_160 . V_180 ) ;
if ( V_161 & V_181 )
V_160 . V_182 = ( V_183 |
V_184 ) ;
else
V_160 . V_182 = V_185 ;
F_2 ( L_48 , V_13 ,
( V_160 . V_182 & V_183 ) ? L_49 : L_50 ,
( V_160 . V_182 & V_184 ) ? L_51 : L_50 ,
( V_160 . V_182 & V_186 ) ? L_52 : L_50 ,
( V_160 . V_182 & V_187 ) ? L_53 : L_50 ) ;
if ( F_82 ( V_91 ) )
V_160 . V_188 = V_189 ;
else
V_160 . V_188 = V_190 ;
F_2 ( L_54 , V_13 , V_160 . V_188 ) ;
V_160 . V_191 = F_83 ( V_91 ) ;
V_160 . V_192 = F_84 ( V_91 ) ;
F_2 ( L_55 ,
V_13 , V_160 . V_191 , V_160 . V_192 ) ;
V_160 . V_193 = F_85 ( V_91 ) ;
F_2 ( L_56 , V_13 , V_160 . V_193 ) ;
F_86 ( V_91 , V_160 . V_193 , V_160 . V_193 ) ;
V_160 . V_194 = 0 ;
F_80 ( V_23 , V_195 ,
( T_1 * ) & V_160 , sizeof( V_160 ) ) ;
}
static int F_64 ( struct V_19 * V_23 , T_1 V_196 )
{
struct V_197 V_198 ;
V_198 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
V_198 . V_199 = V_196 ;
return F_80 ( V_23 , V_200 ,
( T_1 * ) & V_198 , sizeof( V_198 ) ) ;
}
static int F_63 ( struct V_19 * V_23 , T_1 V_196 )
{
struct V_197 V_201 ;
V_201 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
V_201 . V_199 = V_196 ;
return F_80 ( V_23 , V_202 ,
( T_1 * ) & V_201 , sizeof( V_201 ) ) ;
}
static int F_69 ( struct V_19 * V_23 , T_1 V_196 )
{
struct V_197 V_203 ;
V_203 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
V_203 . V_199 = V_196 ;
return F_80 ( V_23 , V_204 ,
( T_1 * ) & V_203 , sizeof( V_203 ) ) ;
}
static int F_40 ( struct V_19 * V_23 , T_1 V_205 )
{
struct V_206 V_207 ;
V_207 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
V_207 . V_208 = V_205 ;
return F_80 ( V_23 , V_209 ,
( T_1 * ) & V_207 , sizeof( V_207 ) ) ;
}
static int F_61 ( struct V_19 * V_23 )
{
struct V_154 V_210 ;
V_210 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
return F_80 ( V_23 , V_145 ,
( T_1 * ) & V_210 , sizeof( V_210 ) ) ;
}
static int F_45 ( struct V_19 * V_23 )
{
struct V_154 V_157 ;
V_157 . V_23 = V_23 -> V_93 - V_23 -> V_2 -> V_120 + 1 ;
return F_80 ( V_23 , V_211 ,
( T_1 * ) & V_157 , sizeof( V_157 ) ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_92 = 0 ;
V_20 = V_2 -> V_23 [ V_40 ] ;
V_22 = F_29 ( V_20 ) ;
F_46 ( & V_22 -> V_81 ) ;
if ( ! V_22 -> V_82 ) {
F_15 ( V_2 -> V_14 , V_20 -> V_68 -> V_28 ) ;
V_92 = F_57 ( V_20 -> V_68 , V_42 ) ;
if ( V_92 ) {
F_4 ( & V_2 -> V_14 -> V_14 ,
L_25 ,
V_13 , V_92 ) ;
goto exit;
}
}
V_22 -> V_82 ++ ;
exit:
F_51 ( & V_22 -> V_81 ) ;
return V_92 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_20 = V_2 -> V_23 [ V_40 ] ;
V_22 = F_29 ( V_20 ) ;
F_46 ( & V_22 -> V_81 ) ;
V_22 -> V_82 -- ;
if ( ! V_22 -> V_82 )
F_49 ( V_20 -> V_68 ) ;
F_51 ( & V_22 -> V_81 ) ;
}
static int F_43 ( struct V_19 * V_23 )
{
struct V_24 * V_25 = F_29 ( V_23 ) ;
struct V_36 * V_37 ;
struct V_34 * V_34 ;
int V_92 = 0 ;
unsigned long V_57 ;
struct V_38 * V_39 ;
struct V_38 * V_89 ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_35 (tmp, tmp2, &info->rx_urbs_free) {
F_31 ( V_39 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
V_92 = F_57 ( V_34 , V_42 ) ;
if ( V_92 ) {
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_61 ) ;
F_35 (tmp, tmp2, &info->rx_urbs_submitted) {
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
F_31 ( V_39 ) ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
F_49 ( V_34 ) ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_61 ) ;
}
break;
}
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_62 ) ;
}
F_55 ( & V_25 -> V_55 , V_57 ) ;
return V_92 ;
}
static struct V_36 * F_75 ( struct V_34 * V_34 ,
struct V_38 * V_212 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
F_59 (tmp, head) {
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
if ( V_37 -> V_34 == V_34 )
return V_37 ;
}
return NULL ;
}
static struct V_38 * F_30 ( struct V_38 * V_212 )
{
return V_212 -> V_213 ;
}
static void V_60 ( struct V_214 * V_215 )
{
struct V_24 * V_25 =
F_87 ( V_215 , struct V_24 , V_59 ) ;
struct V_19 * V_23 = V_25 -> V_23 ;
struct V_90 * V_91 = F_88 ( & V_23 -> V_23 ) ;
struct V_36 * V_37 ;
struct V_34 * V_34 ;
unsigned long V_57 ;
struct V_38 * V_39 ;
struct V_38 * V_89 ;
int V_31 ;
int V_100 = 0 ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
if ( V_25 -> V_57 & V_135 ) {
F_55 ( & V_25 -> V_55 , V_57 ) ;
goto V_15;
}
F_35 (tmp, tmp2, &info->rx_urb_q) {
F_31 ( V_39 ) ;
F_55 ( & V_25 -> V_55 , V_57 ) ;
V_37 = F_32 ( V_39 , struct V_36 , V_74 ) ;
V_34 = V_37 -> V_34 ;
if ( V_91 && V_34 -> V_142 )
V_100 += F_89 ( V_91 ,
V_34 -> V_70 , V_34 -> V_142 ) ;
V_31 = F_57 ( V_34 , V_103 ) ;
if ( V_31 ) {
F_4 ( & V_23 -> V_14 ,
L_57 ,
V_13 , V_31 ) ;
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_61 ) ;
continue;
}
F_53 ( & V_25 -> V_55 , V_57 ) ;
F_25 ( V_39 , & V_25 -> V_62 ) ;
}
F_55 ( & V_25 -> V_55 , V_57 ) ;
if ( V_100 )
F_90 ( V_91 ) ;
V_15:
F_91 ( V_91 ) ;
}
static int T_3 F_92 ( void )
{
int V_92 ;
V_92 = F_93 ( & V_216 ) ;
if ( V_92 )
goto V_217;
V_92 = F_93 ( & V_218 ) ;
if ( V_92 )
goto V_219;
V_92 = F_94 ( & V_220 ) ;
if ( V_92 )
goto V_221;
F_95 (KERN_INFO KBUILD_MODNAME L_58 DRIVER_VERSION L_59
DRIVER_DESC L_60 ) ;
return 0 ;
V_221:
F_96 ( & V_218 ) ;
V_219:
F_96 ( & V_216 ) ;
V_217:
return V_92 ;
}
static void T_4 F_97 ( void )
{
F_98 ( & V_220 ) ;
F_96 ( & V_216 ) ;
F_96 ( & V_218 ) ;
}
