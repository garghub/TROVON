static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
int V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_9 = F_2 ( V_2 -> V_16 , 0 ) ;
V_10 = ( V_17 | V_18 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_9 = F_3 ( V_2 -> V_16 , 0 ) ;
V_10 = ( V_17 | V_24 ) ;
break;
default:
F_4 ( V_2 -> V_2 , L_1 , V_3 ) ;
V_8 = - V_25 ;
goto V_26;
}
if ( ! ( V_10 & V_24 ) )
memcpy ( V_2 -> V_27 , V_6 , V_7 ) ;
V_8 = F_5 ( V_2 -> V_16 , V_9 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_27 , V_7 , 1000 ) ;
F_6 ( V_2 -> V_2 , V_3 , V_10 , V_4 ,
V_5 , V_2 -> V_27 , V_7 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_2 , L_2 ,
V_8 , V_3 ) ;
goto V_26;
}
if ( V_10 & V_24 )
memcpy ( V_6 , V_2 -> V_27 , V_7 ) ;
return 0 ;
V_26:
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
int V_8 , V_30 ;
T_1 V_27 [ 8 ] , V_31 ;
unsigned int V_32 , V_33 , V_34 ;
const bool V_35 = F_8 ( V_36 , & V_2 -> V_37 ) ;
const bool V_38 = F_8 ( V_39 , & V_2 -> V_37 ) ;
static const struct {
T_3 V_40 ;
} V_41 [] = {
{ 1750000 } ,
{ 2500000 } ,
{ 3500000 } ,
{ 5000000 } ,
{ 5500000 } ,
{ 6000000 } ,
{ 7000000 } ,
{ 8000000 } ,
{ 9000000 } ,
{ 10000000 } ,
{ 12000000 } ,
{ 14000000 } ,
{ 15000000 } ,
{ 20000000 } ,
{ 24000000 } ,
{ 28000000 } ,
} ;
if ( ! V_35 && ! V_38 ) {
F_9 ( & V_29 -> V_2 , L_3 ) ;
return 0 ;
}
if ( V_35 && F_10 ( V_42 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_4 , V_2 -> V_43 ) ;
V_33 = V_2 -> V_43 ;
V_34 = 1 ;
F_11 ( V_44 , & V_2 -> V_37 ) ;
} else if ( V_38 && F_10 ( V_44 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_5 , V_2 -> V_45 ) ;
V_33 = V_2 -> V_45 ;
V_34 = 1 ;
F_11 ( V_42 , & V_2 -> V_37 ) ;
} else {
V_33 = V_34 = 0 ;
}
if ( V_33 || V_34 ) {
V_27 [ 0 ] = ( V_33 >> 0 ) & 0xff ;
V_27 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_27 [ 2 ] = ( V_33 >> 16 ) & 0xff ;
V_27 [ 3 ] = ( V_33 >> 24 ) & 0xff ;
V_27 [ 4 ] = ( V_34 >> 0 ) & 0xff ;
V_27 [ 5 ] = ( V_34 >> 8 ) & 0xff ;
V_27 [ 6 ] = ( V_34 >> 16 ) & 0xff ;
V_27 [ 7 ] = ( V_34 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_14 , 0 , 0 , V_27 , 8 ) ;
if ( V_8 )
goto V_26;
}
if ( V_35 && F_10 ( V_46 , & V_2 -> V_37 ) ) {
if ( V_2 -> V_47 -> V_48 == true )
V_32 = V_2 -> V_43 ;
else
V_32 = V_2 -> V_49 -> V_48 ;
for ( V_30 = 0 ; V_30 < F_12 ( V_41 ) ; V_30 ++ ) {
if ( V_32 <= V_41 [ V_30 ] . V_40 ) {
V_32 = V_41 [ V_30 ] . V_40 ;
break;
}
}
V_2 -> V_49 -> V_48 = V_32 ;
V_2 -> V_49 -> V_50 . V_48 = V_32 ;
F_9 ( & V_29 -> V_2 , L_6 , V_32 ) ;
F_11 ( V_51 , & V_2 -> V_37 ) ;
} else if ( V_38 && F_10 ( V_51 , & V_2 -> V_37 ) ) {
if ( V_2 -> V_52 -> V_48 == true )
V_32 = V_2 -> V_45 ;
else
V_32 = V_2 -> V_53 -> V_48 ;
for ( V_30 = 0 ; V_30 < F_12 ( V_41 ) ; V_30 ++ ) {
if ( V_32 <= V_41 [ V_30 ] . V_40 ) {
V_32 = V_41 [ V_30 ] . V_40 ;
break;
}
}
V_2 -> V_53 -> V_48 = V_32 ;
V_2 -> V_53 -> V_50 . V_48 = V_32 ;
F_9 ( & V_29 -> V_2 , L_7 , V_32 ) ;
F_11 ( V_46 , & V_2 -> V_37 ) ;
} else {
V_32 = 0 ;
}
if ( V_32 ) {
V_33 = V_34 = 0 ;
V_33 |= ( ( V_32 >> 0 ) & 0xff ) << 0 ;
V_33 |= ( ( V_32 >> 8 ) & 0xff ) << 8 ;
V_34 |= ( ( V_32 >> 16 ) & 0xff ) << 0 ;
V_34 |= ( ( V_32 >> 24 ) & 0xff ) << 8 ;
V_8 = F_1 ( V_2 , V_15 ,
V_33 , V_34 , NULL , 0 ) ;
if ( V_8 )
goto V_26;
}
if ( V_35 && F_10 ( V_54 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_8 , V_2 -> V_55 ) ;
V_33 = V_2 -> V_55 / 1000000 ;
V_34 = V_2 -> V_55 % 1000000 ;
F_11 ( V_56 , & V_2 -> V_37 ) ;
} else if ( V_38 && F_10 ( V_56 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_9 , V_2 -> V_57 ) ;
V_33 = V_2 -> V_57 / 1000000 ;
V_34 = V_2 -> V_57 % 1000000 ;
F_11 ( V_54 , & V_2 -> V_37 ) ;
} else {
V_33 = V_34 = 0 ;
}
if ( V_33 || V_34 ) {
V_27 [ 0 ] = ( V_33 >> 0 ) & 0xff ;
V_27 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_27 [ 2 ] = ( V_33 >> 16 ) & 0xff ;
V_27 [ 3 ] = ( V_33 >> 24 ) & 0xff ;
V_27 [ 4 ] = ( V_34 >> 0 ) & 0xff ;
V_27 [ 5 ] = ( V_34 >> 8 ) & 0xff ;
V_27 [ 6 ] = ( V_34 >> 16 ) & 0xff ;
V_27 [ 7 ] = ( V_34 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , V_12 , 0 , 0 , V_27 , 8 ) ;
if ( V_8 )
goto V_26;
}
if ( V_35 && F_10 ( V_58 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_10 ,
V_2 -> V_59 -> V_50 . V_48 , V_2 -> V_59 -> V_48 ) ;
V_31 = ( V_2 -> V_59 -> V_48 ) ? 1 : 0 ;
V_8 = F_1 ( V_2 , V_13 , V_31 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_26;
F_11 ( V_60 , & V_2 -> V_37 ) ;
}
if ( V_38 && F_10 ( V_60 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_11 ,
V_2 -> V_61 -> V_50 . V_48 , V_2 -> V_61 -> V_48 ) ;
V_31 = ( V_2 -> V_61 -> V_48 ) ? 1 : 0 ;
V_8 = F_1 ( V_2 , V_13 , V_31 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_26;
F_11 ( V_58 , & V_2 -> V_37 ) ;
}
if ( V_35 && F_10 ( V_62 , & V_2 -> V_37 ) ) {
F_9 ( V_2 -> V_2 , L_12 ,
V_2 -> V_63 -> V_50 . V_48 , V_2 -> V_63 -> V_48 ) ;
V_8 = F_1 ( V_2 , V_21 , 0 ,
V_2 -> V_63 -> V_48 , & V_31 , 1 ) ;
if ( V_8 )
goto V_26;
}
if ( V_35 && F_10 ( V_64 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_13 ,
V_2 -> V_65 -> V_50 . V_48 , V_2 -> V_65 -> V_48 ) ;
V_8 = F_1 ( V_2 , V_22 , 0 ,
V_2 -> V_65 -> V_48 , & V_31 , 1 ) ;
if ( V_8 )
goto V_26;
}
if ( V_38 && F_10 ( V_66 , & V_2 -> V_37 ) ) {
F_9 ( & V_29 -> V_2 , L_14 ,
V_2 -> V_67 -> V_50 . V_48 , V_2 -> V_67 -> V_48 ) ;
V_8 = F_1 ( V_2 , V_23 , 0 ,
V_2 -> V_67 -> V_48 , & V_31 , 1 ) ;
if ( V_8 )
goto V_26;
}
return 0 ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static struct V_68 * F_13 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
unsigned long V_37 ;
struct V_68 * V_71 = NULL ;
F_14 ( & V_2 -> V_72 , V_37 ) ;
if ( F_15 ( V_70 ) )
goto V_73;
V_71 = F_16 ( V_70 -> V_74 , struct V_68 , V_75 ) ;
F_17 ( & V_71 -> V_75 ) ;
V_73:
F_18 ( & V_2 -> V_72 , V_37 ) ;
return V_71 ;
}
static void F_19 ( struct V_1 * V_2 , void * V_76 , void * V_77 ,
unsigned int V_78 )
{
memcpy ( V_76 , V_77 , V_78 ) ;
if ( F_20 ( F_21 ( V_2 -> V_79 ) ) ) {
#define F_22 10000UL
unsigned int V_80 = F_23 ( V_81 -
V_2 -> V_79 + F_24 ( F_22 ) ) ;
unsigned int V_82 = V_2 -> V_83 - V_2 -> V_84 ;
V_2 -> V_79 = V_81 + F_24 ( F_22 ) ;
V_2 -> V_84 = V_2 -> V_83 ;
F_9 ( V_2 -> V_2 , L_16 ,
V_78 , V_82 , V_80 ,
V_82 * 1000UL / V_80 ) ;
}
V_2 -> V_83 += V_78 / 2 ;
}
static void F_25 ( struct V_85 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_86 ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_68 * V_71 ;
unsigned int V_87 ;
F_26 ( & V_29 -> V_2 , L_17 , V_85 -> V_88 ,
V_85 -> V_89 , V_85 -> V_90 ) ;
switch ( V_85 -> V_88 ) {
case 0 :
case - V_91 :
break;
case - V_92 :
case - V_93 :
case - V_94 :
return;
default:
F_27 ( & V_29 -> V_2 , L_18 , V_85 -> V_88 ) ;
goto V_95;
}
V_71 = F_13 ( V_2 , & V_2 -> V_96 ) ;
if ( F_20 ( V_71 == NULL ) ) {
V_2 -> V_97 ++ ;
F_28 ( & V_29 -> V_2 ,
L_19 ,
V_2 -> V_97 ) ;
goto V_95;
}
V_87 = F_29 (unsigned long, vb2_plane_size(&buffer->vb.vb2_buf, 0),
urb->actual_length) ;
F_19 ( V_2 , F_30 ( & V_71 -> V_98 . V_99 , 0 ) ,
V_85 -> V_100 , V_87 ) ;
F_31 ( & V_71 -> V_98 . V_99 , 0 , V_87 ) ;
V_71 -> V_98 . V_101 = V_2 -> V_101 ++ ;
V_71 -> V_98 . V_99 . V_102 = F_32 () ;
F_33 ( & V_71 -> V_98 . V_99 , V_103 ) ;
V_95:
F_34 ( V_85 , V_104 ) ;
}
static void F_35 ( struct V_85 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_86 ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_68 * V_71 ;
unsigned int V_87 ;
F_26 ( & V_29 -> V_2 , L_17 , V_85 -> V_88 ,
V_85 -> V_89 , V_85 -> V_90 ) ;
switch ( V_85 -> V_88 ) {
case 0 :
case - V_91 :
break;
case - V_92 :
case - V_93 :
case - V_94 :
return;
default:
F_27 ( & V_29 -> V_2 , L_18 , V_85 -> V_88 ) ;
}
V_71 = F_13 ( V_2 , & V_2 -> V_105 ) ;
if ( F_20 ( V_71 == NULL ) ) {
V_2 -> V_106 ++ ;
F_28 ( & V_29 -> V_2 ,
L_20 ,
V_2 -> V_106 ) ;
V_85 -> V_89 = 0 ;
goto V_95;
}
V_87 = F_29 (unsigned long, urb->transfer_buffer_length,
vb2_get_plane_payload(&buffer->vb.vb2_buf, 0)) ;
F_19 ( V_2 , V_85 -> V_100 ,
F_30 ( & V_71 -> V_98 . V_99 , 0 ) , V_87 ) ;
V_85 -> V_89 = V_87 ;
V_71 -> V_98 . V_101 = V_2 -> V_101 ++ ;
V_71 -> V_98 . V_99 . V_102 = F_32 () ;
F_33 ( & V_71 -> V_98 . V_99 , V_103 ) ;
V_95:
F_34 ( V_85 , V_104 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = V_2 -> V_107 - 1 ; V_30 >= 0 ; V_30 -- ) {
F_9 ( V_2 -> V_2 , L_21 , V_30 ) ;
F_37 ( V_2 -> V_108 [ V_30 ] ) ;
}
V_2 -> V_107 = 0 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_30 , V_8 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_109 ; V_30 ++ ) {
F_9 ( V_2 -> V_2 , L_22 , V_30 ) ;
V_8 = F_34 ( V_2 -> V_108 [ V_30 ] , V_104 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_23 ,
V_30 ) ;
F_36 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_107 ++ ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 & V_110 ) {
while ( V_2 -> V_111 ) {
V_2 -> V_111 -- ;
F_9 ( V_2 -> V_2 , L_24 , V_2 -> V_111 ) ;
F_40 ( V_2 -> V_16 , V_2 -> V_112 ,
V_2 -> V_113 [ V_2 -> V_111 ] ,
V_2 -> V_114 [ V_2 -> V_111 ] ) ;
}
}
V_2 -> V_37 &= ~ V_110 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
V_2 -> V_111 = 0 ;
V_2 -> V_112 = V_115 ;
F_9 ( V_2 -> V_2 , L_25 ,
V_116 * V_115 ) ;
for ( V_2 -> V_111 = 0 ; V_2 -> V_111 < V_116 ; V_2 -> V_111 ++ ) {
V_2 -> V_113 [ V_2 -> V_111 ] = F_42 ( V_2 -> V_16 ,
V_115 , V_104 ,
& V_2 -> V_114 [ V_2 -> V_111 ] ) ;
if ( ! V_2 -> V_113 [ V_2 -> V_111 ] ) {
F_9 ( V_2 -> V_2 , L_26 ,
V_2 -> V_111 ) ;
F_39 ( V_2 ) ;
return - V_117 ;
}
F_9 ( V_2 -> V_2 , L_27 , V_2 -> V_111 ,
V_2 -> V_113 [ V_2 -> V_111 ] ,
( long long ) V_2 -> V_114 [ V_2 -> V_111 ] ) ;
V_2 -> V_37 |= V_110 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_30 ;
F_36 ( V_2 ) ;
for ( V_30 = V_2 -> V_109 - 1 ; V_30 >= 0 ; V_30 -- ) {
if ( V_2 -> V_108 [ V_30 ] ) {
F_9 ( V_2 -> V_2 , L_28 , V_30 ) ;
F_44 ( V_2 -> V_108 [ V_30 ] ) ;
}
}
V_2 -> V_109 = 0 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , bool V_118 )
{
int V_30 , V_119 ;
unsigned int V_9 ;
T_4 V_120 ;
if ( V_118 ) {
V_9 = F_46 ( V_2 -> V_16 , 0x81 ) ;
V_120 = & F_25 ;
} else {
V_9 = F_47 ( V_2 -> V_16 , 0x02 ) ;
V_120 = & F_35 ;
}
for ( V_30 = 0 ; V_30 < V_116 ; V_30 ++ ) {
F_9 ( V_2 -> V_2 , L_29 , V_30 ) ;
V_2 -> V_108 [ V_30 ] = F_48 ( 0 , V_104 ) ;
if ( ! V_2 -> V_108 [ V_30 ] ) {
F_9 ( V_2 -> V_2 , L_30 ) ;
for ( V_119 = 0 ; V_119 < V_30 ; V_119 ++ )
F_44 ( V_2 -> V_108 [ V_119 ] ) ;
return - V_117 ;
}
F_49 ( V_2 -> V_108 [ V_30 ] ,
V_2 -> V_16 ,
V_9 ,
V_2 -> V_113 [ V_30 ] ,
V_115 ,
V_120 , V_2 ) ;
V_2 -> V_108 [ V_30 ] -> V_121 = V_122 ;
V_2 -> V_108 [ V_30 ] -> V_123 = V_2 -> V_114 [ V_30 ] ;
V_2 -> V_109 ++ ;
}
return 0 ;
}
static void F_50 ( struct V_28 * V_29 )
{
struct V_124 * V_125 = F_51 ( V_29 ) ;
struct V_1 * V_2 = F_52 ( V_125 , struct V_1 , V_126 ) ;
F_9 ( V_2 -> V_2 , L_31 ) ;
F_53 ( & V_2 -> V_127 ) ;
F_53 ( & V_2 -> V_128 ) ;
V_2 -> V_16 = NULL ;
F_54 ( & V_2 -> V_126 ) ;
F_55 ( & V_2 -> V_129 ) ;
F_55 ( & V_2 -> V_130 ) ;
F_56 ( & V_2 -> V_128 ) ;
F_56 ( & V_2 -> V_127 ) ;
F_57 ( & V_2 -> V_126 ) ;
}
static void F_58 ( struct V_131 * V_132 ,
enum V_133 V_134 )
{
struct V_1 * V_2 = F_59 ( V_132 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_68 * V_71 , * V_135 ;
struct V_69 * V_70 ;
unsigned long V_37 ;
F_9 ( & V_29 -> V_2 , L_31 ) ;
if ( V_132 -> type == V_136 )
V_70 = & V_2 -> V_96 ;
else
V_70 = & V_2 -> V_105 ;
F_14 ( & V_2 -> V_72 , V_37 ) ;
F_60 (buffer, node, buffer_list, list) {
F_9 ( & V_29 -> V_2 , L_32 ) ;
F_33 ( & V_71 -> V_98 . V_99 , V_134 ) ;
F_17 ( & V_71 -> V_75 ) ;
}
F_18 ( & V_2 -> V_72 , V_37 ) ;
}
static int F_61 ( struct V_131 * V_132 ,
unsigned int * V_137 ,
unsigned int * V_138 , unsigned int V_139 [] , void * V_140 [] )
{
struct V_1 * V_2 = F_59 ( V_132 ) ;
F_9 ( V_2 -> V_2 , L_33 , * V_137 ) ;
if ( V_132 -> V_141 + * V_137 < 8 )
* V_137 = 8 - V_132 -> V_141 ;
* V_138 = 1 ;
V_139 [ 0 ] = F_62 ( V_2 -> V_142 ) ;
F_9 ( V_2 -> V_2 , L_34 , * V_137 , V_139 [ 0 ] ) ;
return 0 ;
}
static void F_63 ( struct V_143 * V_98 )
{
struct V_144 * V_145 = F_64 ( V_98 ) ;
struct V_131 * V_132 = V_98 -> V_131 ;
struct V_1 * V_2 = F_59 ( V_132 ) ;
struct V_68 * V_71 = F_52 ( V_145 , struct V_68 , V_98 ) ;
struct V_69 * V_70 ;
unsigned long V_37 ;
F_26 ( & V_2 -> V_29 -> V_2 , L_31 ) ;
if ( V_132 -> type == V_136 )
V_70 = & V_2 -> V_96 ;
else
V_70 = & V_2 -> V_105 ;
F_14 ( & V_2 -> V_72 , V_37 ) ;
F_65 ( & V_71 -> V_75 , V_70 ) ;
F_18 ( & V_2 -> V_72 , V_37 ) ;
}
static int F_66 ( struct V_131 * V_132 , unsigned int V_146 )
{
struct V_1 * V_2 = F_59 ( V_132 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
int V_8 ;
unsigned int V_147 ;
F_9 ( & V_29 -> V_2 , L_35 , V_146 ) ;
F_53 ( & V_2 -> V_128 ) ;
if ( V_132 -> type == V_136 ) {
if ( F_8 ( V_39 , & V_2 -> V_37 ) ) {
V_8 = - V_148 ;
goto V_149;
}
V_147 = 1 ;
F_11 ( V_36 , & V_2 -> V_37 ) ;
} else {
if ( F_8 ( V_36 , & V_2 -> V_37 ) ) {
V_8 = - V_148 ;
goto V_149;
}
V_147 = 2 ;
F_11 ( V_39 , & V_2 -> V_37 ) ;
}
V_2 -> V_101 = 0 ;
V_8 = F_41 ( V_2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_45 ( V_2 , ( V_147 == 1 ) ) ;
if ( V_8 )
goto V_26;
V_8 = F_38 ( V_2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , V_11 , V_147 , 0 , NULL , 0 ) ;
if ( V_8 )
goto V_26;
F_56 ( & V_2 -> V_128 ) ;
return 0 ;
V_26:
F_36 ( V_2 ) ;
F_43 ( V_2 ) ;
F_39 ( V_2 ) ;
F_67 ( V_36 , & V_2 -> V_37 ) ;
F_67 ( V_39 , & V_2 -> V_37 ) ;
V_149:
F_58 ( V_132 , V_150 ) ;
F_56 ( & V_2 -> V_128 ) ;
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static void F_68 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_59 ( V_132 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_9 ( & V_29 -> V_2 , L_31 ) ;
F_53 ( & V_2 -> V_128 ) ;
F_1 ( V_2 , V_11 , 0 , 0 , NULL , 0 ) ;
F_36 ( V_2 ) ;
F_43 ( V_2 ) ;
F_39 ( V_2 ) ;
F_58 ( V_132 , V_151 ) ;
if ( V_132 -> type == V_136 )
F_67 ( V_36 , & V_2 -> V_37 ) ;
else
F_67 ( V_39 , & V_2 -> V_37 ) ;
F_56 ( & V_2 -> V_128 ) ;
}
static int F_69 ( struct V_152 * V_152 , void * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_156 * V_157 = F_71 ( V_152 ) ;
F_9 ( & V_29 -> V_2 , L_31 ) ;
if ( V_157 -> V_158 == V_159 )
V_155 -> V_160 = V_161 | V_162 |
V_163 | V_164 ;
else
V_155 -> V_160 = V_165 | V_166 |
V_163 | V_164 ;
V_155 -> V_167 = V_161 | V_162 |
V_165 | V_166 |
V_163 | V_164 |
V_168 ;
F_72 ( V_155 -> V_169 , V_170 , sizeof( V_155 -> V_169 ) ) ;
F_72 ( V_155 -> V_171 , V_2 -> V_130 . V_172 , sizeof( V_155 -> V_171 ) ) ;
F_73 ( V_2 -> V_16 , V_155 -> V_173 , sizeof( V_155 -> V_173 ) ) ;
return 0 ;
}
static int F_74 ( struct V_152 * V_152 , void * V_174 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
struct V_156 * V_157 = F_71 ( V_152 ) ;
struct V_131 * V_177 ;
int V_30 ;
F_9 ( V_2 -> V_2 , L_36 ,
( char * ) & V_176 -> V_178 . V_179 . V_180 ) ;
if ( V_157 -> V_158 == V_159 )
V_177 = & V_2 -> V_181 ;
else
V_177 = & V_2 -> V_182 ;
if ( F_75 ( V_177 ) )
return - V_148 ;
memset ( V_176 -> V_178 . V_179 . V_183 , 0 , sizeof( V_176 -> V_178 . V_179 . V_183 ) ) ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ ) {
if ( V_176 -> V_178 . V_179 . V_180 == V_185 [ V_30 ] . V_180 ) {
V_2 -> V_180 = V_185 [ V_30 ] . V_180 ;
V_2 -> V_142 = V_185 [ V_30 ] . V_142 ;
V_176 -> V_178 . V_179 . V_142 = V_185 [ V_30 ] . V_142 ;
return 0 ;
}
}
V_2 -> V_180 = V_185 [ 0 ] . V_180 ;
V_2 -> V_142 = V_185 [ 0 ] . V_142 ;
V_176 -> V_178 . V_179 . V_180 = V_185 [ 0 ] . V_180 ;
V_176 -> V_178 . V_179 . V_142 = V_185 [ 0 ] . V_142 ;
return 0 ;
}
static int F_76 ( struct V_152 * V_152 , void * V_174 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
F_9 ( V_2 -> V_2 , L_36 ,
( char * ) & V_2 -> V_180 ) ;
memset ( V_176 -> V_178 . V_179 . V_183 , 0 , sizeof( V_176 -> V_178 . V_179 . V_183 ) ) ;
V_176 -> V_178 . V_179 . V_180 = V_2 -> V_180 ;
V_176 -> V_178 . V_179 . V_142 = V_2 -> V_142 ;
return 0 ;
}
static int F_77 ( struct V_152 * V_152 , void * V_174 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
int V_30 ;
F_9 ( V_2 -> V_2 , L_36 ,
( char * ) & V_176 -> V_178 . V_179 . V_180 ) ;
memset ( V_176 -> V_178 . V_179 . V_183 , 0 , sizeof( V_176 -> V_178 . V_179 . V_183 ) ) ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ ) {
if ( V_185 [ V_30 ] . V_180 == V_176 -> V_178 . V_179 . V_180 ) {
V_176 -> V_178 . V_179 . V_142 = V_185 [ V_30 ] . V_142 ;
return 0 ;
}
}
V_176 -> V_178 . V_179 . V_180 = V_185 [ 0 ] . V_180 ;
V_176 -> V_178 . V_179 . V_142 = V_185 [ 0 ] . V_142 ;
return 0 ;
}
static int F_78 ( struct V_152 * V_152 , void * V_174 ,
struct V_186 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
F_9 ( V_2 -> V_2 , L_37 , V_176 -> V_5 ) ;
if ( V_176 -> V_5 >= V_184 )
return - V_25 ;
V_176 -> V_180 = V_185 [ V_176 -> V_5 ] . V_180 ;
return 0 ;
}
static int F_79 ( struct V_152 * V_152 , void * V_174 ,
const struct V_187 * V_125 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
int V_8 ;
F_9 ( V_2 -> V_2 , L_37 , V_125 -> V_5 ) ;
if ( V_125 -> V_5 == 0 )
V_8 = 0 ;
else if ( V_125 -> V_5 == 1 )
V_8 = 0 ;
else
V_8 = - V_25 ;
return V_8 ;
}
static int F_80 ( struct V_152 * V_152 , void * V_174 , struct V_187 * V_125 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
int V_8 ;
F_9 ( V_2 -> V_2 , L_37 , V_125 -> V_5 ) ;
if ( V_125 -> V_5 == 0 ) {
F_72 ( V_125 -> V_172 , L_38 , sizeof( V_125 -> V_172 ) ) ;
V_125 -> type = V_188 ;
V_125 -> V_189 = V_190 | V_191 ;
V_125 -> V_192 = V_193 [ 0 ] . V_192 ;
V_125 -> V_194 = V_193 [ 0 ] . V_194 ;
V_8 = 0 ;
} else if ( V_125 -> V_5 == 1 ) {
F_72 ( V_125 -> V_172 , L_39 , sizeof( V_125 -> V_172 ) ) ;
V_125 -> type = V_195 ;
V_125 -> V_189 = V_190 | V_191 ;
V_125 -> V_192 = V_196 [ 0 ] . V_192 ;
V_125 -> V_194 = V_196 [ 0 ] . V_194 ;
V_8 = 0 ;
} else {
V_8 = - V_25 ;
}
return V_8 ;
}
static int F_81 ( struct V_152 * V_152 , void * V_153 ,
const struct V_197 * V_198 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
F_9 ( V_2 -> V_2 , L_37 , V_198 -> V_5 ) ;
return V_198 -> V_5 > 1 ? - V_25 : 0 ;
}
static int F_82 ( struct V_152 * V_152 , void * V_153 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
int V_8 ;
F_9 ( V_2 -> V_2 , L_37 , V_198 -> V_5 ) ;
if ( V_198 -> V_5 == 0 ) {
F_72 ( V_198 -> V_172 , L_40 , sizeof( V_198 -> V_172 ) ) ;
V_198 -> type = V_188 ;
V_198 -> V_189 = V_190 | V_191 ;
V_198 -> V_192 = V_193 [ 0 ] . V_192 ;
V_198 -> V_194 = V_193 [ 0 ] . V_194 ;
V_8 = 0 ;
} else if ( V_198 -> V_5 == 1 ) {
F_72 ( V_198 -> V_172 , L_39 , sizeof( V_198 -> V_172 ) ) ;
V_198 -> type = V_195 ;
V_198 -> V_189 = V_190 | V_191 ;
V_198 -> V_192 = V_196 [ 0 ] . V_192 ;
V_198 -> V_194 = V_196 [ 0 ] . V_194 ;
V_8 = 0 ;
} else {
V_8 = - V_25 ;
}
return V_8 ;
}
static int F_83 ( struct V_152 * V_152 , void * V_174 ,
const struct V_199 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_156 * V_157 = F_71 ( V_152 ) ;
int V_8 ;
unsigned int V_32 ;
F_9 ( & V_29 -> V_2 , L_41 ,
V_176 -> V_200 , V_176 -> type , V_176 -> V_201 ) ;
if ( V_176 -> V_200 == 0 ) {
V_32 = F_84 ( V_176 -> V_201 , V_193 [ 0 ] . V_192 ,
V_193 [ 0 ] . V_194 ) ;
if ( V_157 -> V_158 == V_159 ) {
V_2 -> V_43 = V_32 ;
F_11 ( V_42 , & V_2 -> V_37 ) ;
} else {
V_2 -> V_45 = V_32 ;
F_11 ( V_44 , & V_2 -> V_37 ) ;
}
} else if ( V_176 -> V_200 == 1 ) {
V_32 = F_84 ( V_176 -> V_201 , V_196 [ 0 ] . V_192 ,
V_196 [ 0 ] . V_194 ) ;
if ( V_157 -> V_158 == V_159 ) {
V_2 -> V_55 = V_32 ;
F_11 ( V_54 , & V_2 -> V_37 ) ;
} else {
V_2 -> V_57 = V_32 ;
F_11 ( V_56 , & V_2 -> V_37 ) ;
}
} else {
V_8 = - V_25 ;
goto V_26;
}
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static int F_85 ( struct V_152 * V_152 , void * V_174 ,
struct V_199 * V_176 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_156 * V_157 = F_71 ( V_152 ) ;
int V_8 ;
F_9 ( V_2 -> V_2 , L_42 , V_176 -> V_200 , V_176 -> type ) ;
if ( V_176 -> V_200 == 0 ) {
V_176 -> type = V_188 ;
if ( V_157 -> V_158 == V_159 )
V_176 -> V_201 = V_2 -> V_43 ;
else
V_176 -> V_201 = V_2 -> V_45 ;
} else if ( V_176 -> V_200 == 1 ) {
V_176 -> type = V_195 ;
if ( V_157 -> V_158 == V_159 )
V_176 -> V_201 = V_2 -> V_55 ;
else
V_176 -> V_201 = V_2 -> V_57 ;
} else {
V_8 = - V_25 ;
goto V_26;
}
return 0 ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static int F_86 ( struct V_152 * V_152 , void * V_174 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_70 ( V_152 ) ;
int V_8 ;
F_9 ( V_2 -> V_2 , L_43 ,
V_203 -> V_200 , V_203 -> type , V_203 -> V_5 ) ;
if ( V_203 -> V_200 == 0 ) {
if ( V_203 -> V_5 >= F_12 ( V_193 ) ) {
V_8 = - V_25 ;
} else {
* V_203 = V_193 [ V_203 -> V_5 ] ;
V_8 = 0 ;
}
} else if ( V_203 -> V_200 == 1 ) {
if ( V_203 -> V_5 >= F_12 ( V_196 ) ) {
V_8 = - V_25 ;
} else {
* V_203 = V_196 [ V_203 -> V_5 ] ;
V_8 = 0 ;
}
} else {
V_8 = - V_25 ;
}
return V_8 ;
}
static void F_87 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_52 ( V_125 , struct V_1 , V_126 ) ;
F_9 ( V_2 -> V_2 , L_31 ) ;
F_88 ( & V_2 -> V_204 ) ;
F_88 ( & V_2 -> V_205 ) ;
F_89 ( & V_2 -> V_126 ) ;
F_90 ( V_2 ) ;
}
static int F_91 ( struct V_206 * V_207 )
{
struct V_1 * V_2 = F_52 ( V_207 -> V_208 ,
struct V_1 , V_204 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
int V_8 ;
switch ( V_207 -> V_209 ) {
case V_210 :
case V_211 :
F_11 ( V_46 , & V_2 -> V_37 ) ;
break;
case V_212 :
F_11 ( V_58 , & V_2 -> V_37 ) ;
break;
case V_213 :
F_11 ( V_62 , & V_2 -> V_37 ) ;
break;
case V_214 :
F_11 ( V_64 , & V_2 -> V_37 ) ;
break;
default:
F_9 ( & V_29 -> V_2 , L_44 ,
V_207 -> V_209 , V_207 -> V_172 ) ;
V_8 = - V_25 ;
goto V_26;
}
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static int F_92 ( struct V_206 * V_207 )
{
struct V_1 * V_2 = F_52 ( V_207 -> V_208 ,
struct V_1 , V_205 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
int V_8 ;
switch ( V_207 -> V_209 ) {
case V_210 :
case V_211 :
F_11 ( V_51 , & V_2 -> V_37 ) ;
break;
case V_213 :
F_11 ( V_66 , & V_2 -> V_37 ) ;
break;
case V_212 :
F_11 ( V_60 , & V_2 -> V_37 ) ;
break;
default:
F_9 ( & V_29 -> V_2 , L_44 ,
V_207 -> V_209 , V_207 -> V_172 ) ;
V_8 = - V_25 ;
goto V_26;
}
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
static int F_93 ( struct V_28 * V_29 ,
const struct V_215 * V_209 )
{
struct V_1 * V_2 ;
int V_8 ;
T_1 V_31 , V_27 [ V_216 ] ;
V_2 = F_94 ( sizeof( * V_2 ) , V_217 ) ;
if ( ! V_2 ) {
V_8 = - V_117 ;
goto V_26;
}
F_95 ( & V_2 -> V_128 ) ;
F_95 ( & V_2 -> V_127 ) ;
F_96 ( & V_2 -> V_72 ) ;
F_97 ( & V_2 -> V_96 ) ;
F_97 ( & V_2 -> V_105 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_2 = & V_29 -> V_2 ;
V_2 -> V_16 = F_98 ( V_29 ) ;
V_2 -> V_180 = V_185 [ 0 ] . V_180 ;
V_2 -> V_142 = V_185 [ 0 ] . V_142 ;
V_2 -> V_43 = V_193 [ 0 ] . V_192 ;
V_2 -> V_45 = V_193 [ 0 ] . V_192 ;
V_2 -> V_55 = V_196 [ 0 ] . V_192 ;
V_2 -> V_57 = V_196 [ 0 ] . V_192 ;
F_11 ( V_42 , & V_2 -> V_37 ) ;
F_11 ( V_44 , & V_2 -> V_37 ) ;
F_11 ( V_54 , & V_2 -> V_37 ) ;
F_11 ( V_56 , & V_2 -> V_37 ) ;
V_8 = F_1 ( V_2 , V_19 , 0 , 0 , & V_31 , 1 ) ;
if ( V_8 == 0 )
V_8 = F_1 ( V_2 , V_20 , 0 , 0 ,
V_27 , V_216 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_45 ) ;
goto V_218;
}
V_27 [ V_216 - 1 ] = '\0' ;
F_99 ( V_2 -> V_2 , L_46 , V_31 ) ;
F_99 ( V_2 -> V_2 , L_47 , V_27 ) ;
V_2 -> V_181 . type = V_136 ;
V_2 -> V_181 . V_219 = V_220 | V_221 | V_222 |
V_223 ;
V_2 -> V_181 . V_224 = & V_225 ;
V_2 -> V_181 . V_226 = & V_227 ;
V_2 -> V_181 . V_228 = V_2 ;
V_2 -> V_181 . V_229 = sizeof( struct V_68 ) ;
V_2 -> V_181 . V_230 = V_231 ;
V_8 = F_100 ( & V_2 -> V_181 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_48 ) ;
goto V_218;
}
V_2 -> V_182 . type = V_232 ;
V_2 -> V_182 . V_219 = V_220 | V_221 | V_222 |
V_233 ;
V_2 -> V_182 . V_224 = & V_225 ;
V_2 -> V_182 . V_226 = & V_227 ;
V_2 -> V_182 . V_228 = V_2 ;
V_2 -> V_182 . V_229 = sizeof( struct V_68 ) ;
V_2 -> V_182 . V_230 = V_231 ;
V_8 = F_100 ( & V_2 -> V_182 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_49 ) ;
goto V_218;
}
F_101 ( & V_2 -> V_204 , 5 ) ;
V_2 -> V_47 = F_102 ( & V_2 -> V_204 ,
& V_234 , V_210 ,
0 , 1 , 0 , 1 ) ;
V_2 -> V_49 = F_102 ( & V_2 -> V_204 ,
& V_234 , V_211 ,
1750000 , 28000000 , 50000 , 1750000 ) ;
F_103 ( 2 , & V_2 -> V_47 , 0 , false ) ;
V_2 -> V_59 = F_102 ( & V_2 -> V_204 ,
& V_234 , V_212 , 0 , 12 , 12 , 0 ) ;
V_2 -> V_63 = F_102 ( & V_2 -> V_204 ,
& V_234 , V_213 , 0 , 40 , 8 , 0 ) ;
V_2 -> V_65 = F_102 ( & V_2 -> V_204 ,
& V_234 , V_214 , 0 , 62 , 2 , 0 ) ;
if ( V_2 -> V_204 . error ) {
V_8 = V_2 -> V_204 . error ;
F_4 ( V_2 -> V_2 , L_50 ) ;
goto V_235;
}
F_104 ( V_2 -> V_59 , ! V_236 ) ;
F_105 ( & V_2 -> V_204 ) ;
F_101 ( & V_2 -> V_205 , 4 ) ;
V_2 -> V_52 = F_102 ( & V_2 -> V_205 ,
& V_237 , V_210 ,
0 , 1 , 0 , 1 ) ;
V_2 -> V_53 = F_102 ( & V_2 -> V_205 ,
& V_237 , V_211 ,
1750000 , 28000000 , 50000 , 1750000 ) ;
F_103 ( 2 , & V_2 -> V_52 , 0 , false ) ;
V_2 -> V_67 = F_102 ( & V_2 -> V_205 ,
& V_237 , V_213 , 0 , 47 , 1 , 0 ) ;
V_2 -> V_61 = F_102 ( & V_2 -> V_205 ,
& V_237 , V_212 , 0 , 15 , 15 , 0 ) ;
if ( V_2 -> V_205 . error ) {
V_8 = V_2 -> V_205 . error ;
F_4 ( V_2 -> V_2 , L_50 ) ;
goto V_238;
}
F_104 ( V_2 -> V_61 , ! V_236 ) ;
F_105 ( & V_2 -> V_205 ) ;
V_2 -> V_126 . V_239 = F_87 ;
V_8 = F_106 ( & V_29 -> V_2 , & V_2 -> V_126 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_51 , V_8 ) ;
goto V_238;
}
V_2 -> V_130 = V_240 ;
V_2 -> V_130 . V_241 = & V_2 -> V_181 ;
V_2 -> V_130 . V_241 -> V_242 = & V_2 -> V_127 ;
V_2 -> V_130 . V_126 = & V_2 -> V_126 ;
V_2 -> V_130 . V_243 = & V_2 -> V_204 ;
V_2 -> V_130 . V_242 = & V_2 -> V_128 ;
V_2 -> V_130 . V_158 = V_159 ;
F_107 ( & V_2 -> V_130 , V_2 ) ;
V_8 = F_108 ( & V_2 -> V_130 , V_244 , - 1 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 ,
L_52 , V_8 ) ;
goto V_245;
}
F_99 ( V_2 -> V_2 , L_53 ,
F_109 ( & V_2 -> V_130 ) ) ;
V_2 -> V_129 = V_240 ;
V_2 -> V_129 . V_241 = & V_2 -> V_182 ;
V_2 -> V_129 . V_241 -> V_242 = & V_2 -> V_127 ;
V_2 -> V_129 . V_126 = & V_2 -> V_126 ;
V_2 -> V_129 . V_243 = & V_2 -> V_205 ;
V_2 -> V_129 . V_242 = & V_2 -> V_128 ;
V_2 -> V_129 . V_158 = V_246 ;
F_107 ( & V_2 -> V_129 , V_2 ) ;
V_8 = F_108 ( & V_2 -> V_129 , V_244 , - 1 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 ,
L_52 , V_8 ) ;
goto V_247;
}
F_99 ( V_2 -> V_2 , L_53 ,
F_109 ( & V_2 -> V_129 ) ) ;
F_110 ( V_2 -> V_2 , L_54 ) ;
return 0 ;
V_247:
F_55 ( & V_2 -> V_130 ) ;
V_245:
F_89 ( & V_2 -> V_126 ) ;
V_238:
F_88 ( & V_2 -> V_205 ) ;
V_235:
F_88 ( & V_2 -> V_204 ) ;
V_218:
F_90 ( V_2 ) ;
V_26:
F_9 ( & V_29 -> V_2 , L_15 , V_8 ) ;
return V_8 ;
}
