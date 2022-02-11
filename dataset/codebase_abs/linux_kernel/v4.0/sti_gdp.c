static const T_1 * F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static unsigned int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_3 ) ;
}
static int F_4 ( int V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
}
return - 1 ;
}
static int F_5 ( int V_29 )
{
switch ( V_29 ) {
case V_30 :
case V_10 :
case V_22 :
case V_12 :
return V_31 ;
}
return 0 ;
}
static struct V_32 * F_6 ( struct V_1 * V_2 )
{
int V_33 ;
struct V_34 * V_35 = F_7 ( V_2 ) ;
unsigned int V_36 ;
V_33 = F_8 ( V_2 -> V_37 + V_38 ) ;
if ( ! V_33 )
goto V_39;
for ( V_36 = 0 ; V_36 < V_40 ; V_36 ++ )
if ( ( V_33 != V_35 -> V_41 [ V_36 ] . V_42 ) &&
( V_33 != V_35 -> V_41 [ V_36 ] . V_43 ) )
return & V_35 -> V_41 [ V_36 ] ;
F_9 ( L_1 ,
F_10 ( V_2 ) , V_33 ) ;
V_39:
return & V_35 -> V_41 [ 0 ] ;
}
static
struct V_32 * F_11 ( struct V_1 * V_2 )
{
int V_33 ;
struct V_34 * V_35 = F_7 ( V_2 ) ;
unsigned int V_36 ;
V_33 = F_8 ( V_2 -> V_37 + V_38 ) ;
if ( ! V_33 )
goto V_39;
for ( V_36 = 0 ; V_36 < V_40 ; V_36 ++ )
if ( ( V_33 == V_35 -> V_41 [ V_36 ] . V_42 ) ||
( V_33 == V_35 -> V_41 [ V_36 ] . V_43 ) )
return & V_35 -> V_41 [ V_36 ] ;
V_39:
F_12 ( L_2 ,
V_33 , F_10 ( V_2 ) ) ;
return NULL ;
}
static int F_13 ( struct V_1 * V_2 , bool V_44 )
{
struct V_32 * V_45 ;
struct V_46 * V_47 , * V_48 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_51 * V_52 = V_2 -> V_52 ;
struct V_34 * V_35 = F_7 ( V_2 ) ;
struct V_53 * V_54 = F_14 ( V_52 ) ;
int V_29 ;
unsigned int V_55 , V_56 ;
int V_57 = V_50 -> clock * 1000 ;
int V_58 ;
T_2 V_59 , V_60 , V_61 , V_62 ;
V_45 = F_6 ( V_2 ) ;
V_47 = V_45 -> V_47 ;
V_48 = V_45 -> V_48 ;
F_15 ( V_52 , L_3 , V_63 ,
F_10 ( V_2 ) , V_47 , V_48 ) ;
V_47 -> V_64 = V_65 ;
V_47 -> V_66 = V_67 ;
V_29 = F_4 ( V_2 -> V_29 ) ;
if ( V_29 == - 1 ) {
F_9 ( L_4 ,
( char * ) & V_2 -> V_29 ) ;
return 1 ;
}
V_47 -> V_66 |= V_29 ;
V_47 -> V_66 |= F_5 ( V_29 ) ;
V_47 -> V_68 &= ~ V_69 ;
F_16 ( V_2 -> V_29 , & V_55 , & V_56 ) ;
V_47 -> V_70 = ( T_2 ) V_2 -> V_71 + V_2 -> V_72 [ 0 ] ;
V_47 -> V_70 += V_2 -> V_73 * ( V_56 >> 3 ) ;
V_47 -> V_70 += V_2 -> V_74 * V_2 -> V_75 [ 0 ] ;
V_47 -> V_76 = V_2 -> V_75 [ 0 ] ;
V_47 -> V_77 =
F_17 ( V_2 -> V_78 , 0 , V_79 ) << 16 |
F_17 ( V_2 -> V_80 , 0 , V_79 ) ;
V_59 = F_18 ( * V_50 , V_2 -> V_81 ) ;
V_61 = F_18 ( * V_50 , V_2 -> V_81 + V_2 -> V_82 - 1 ) ;
V_60 = F_19 ( * V_50 , V_2 -> V_83 ) ;
V_62 = F_19 ( * V_50 , V_2 -> V_83 + V_2 -> V_84 - 1 ) ;
V_47 -> V_85 = ( V_59 << 16 ) | V_60 ;
V_47 -> V_86 = ( V_61 << 16 ) | V_62 ;
memcpy ( V_48 , V_47 , sizeof( * V_48 ) ) ;
V_47 -> V_87 = V_45 -> V_42 ;
V_48 -> V_87 = V_45 -> V_43 ;
if ( V_2 -> V_50 -> V_88 & V_89 )
V_48 -> V_70 = V_47 -> V_70 +
V_2 -> V_75 [ 0 ] ;
if ( V_44 ) {
if ( F_20 ( V_2 -> V_90 == V_91 ?
V_54 -> V_92 : V_54 -> V_93 ,
& V_35 -> V_94 , V_2 -> V_90 ) ) {
F_9 ( L_5 ) ;
return 1 ;
}
if ( V_35 -> V_95 ) {
struct V_96 * V_97 ;
if ( V_2 -> V_90 == V_91 )
V_97 = V_35 -> V_98 ;
else
V_97 = V_35 -> V_99 ;
if ( V_97 )
F_21 ( V_35 -> V_95 , V_97 ) ;
V_58 = F_22 ( V_35 -> V_95 , V_57 ) ;
if ( V_58 < 0 ) {
F_9 ( L_6 ,
V_57 ) ;
return 1 ;
}
if ( F_23 ( V_35 -> V_95 ) ) {
F_9 ( L_7 ) ;
return 1 ;
}
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_32 * V_100 = F_6 ( V_2 ) ;
struct V_46 * V_101 = V_100 -> V_47 ;
struct V_46 * V_102 = V_100 -> V_48 ;
struct V_34 * V_35 = F_7 ( V_2 ) ;
T_2 V_103 = V_100 -> V_43 ;
T_2 V_104 = V_100 -> V_42 ;
struct V_32 * V_105 = F_11 ( V_2 ) ;
F_15 ( V_2 -> V_52 , L_8 , V_63 ,
F_10 ( V_2 ) ,
V_101 , V_102 ) ;
F_15 ( V_2 -> V_52 , L_9 ,
F_8 ( V_2 -> V_37 + V_38 ) ) ;
F_15 ( V_2 -> V_52 , L_10 ,
( unsigned long ) V_2 -> V_71 ,
F_8 ( V_2 -> V_37 + V_106 ) ) ;
if ( V_105 == NULL ) {
F_12 ( L_11 ,
F_10 ( V_2 ) ) ;
F_25 ( V_35 -> V_107 == true ?
V_104 : V_103 ,
V_2 -> V_37 + V_38 ) ;
return 0 ;
}
if ( V_2 -> V_50 -> V_88 & V_89 ) {
if ( V_35 -> V_107 == true ) {
V_105 -> V_48 -> V_87 = V_103 ;
} else {
F_25 ( V_103 ,
V_2 -> V_37 + V_38 ) ;
}
} else {
F_25 ( V_103 , V_2 -> V_37 + V_38 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
struct V_34 * V_35 = F_7 ( V_2 ) ;
struct V_53 * V_54 = F_14 ( V_2 -> V_52 ) ;
F_12 ( L_12 , F_10 ( V_2 ) ) ;
for ( V_36 = 0 ; V_36 < V_40 ; V_36 ++ ) {
V_35 -> V_41 [ V_36 ] . V_47 -> V_68 |= V_69 ;
V_35 -> V_41 [ V_36 ] . V_48 -> V_68 |= V_69 ;
}
if ( F_27 ( V_2 -> V_90 == V_91 ?
V_54 -> V_92 : V_54 -> V_93 , & V_35 -> V_94 ) )
F_12 ( L_13 ) ;
if ( V_35 -> V_95 )
F_28 ( V_35 -> V_95 ) ;
return 0 ;
}
int F_29 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_111 )
{
struct V_34 * V_35 = F_30 ( V_109 , struct V_34 , V_94 ) ;
switch ( V_110 ) {
case V_112 :
V_35 -> V_107 = true ;
break;
case V_113 :
V_35 -> V_107 = false ;
break;
default:
F_9 ( L_14 , V_110 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_7 ( V_2 ) ;
struct V_114 * V_115 = V_2 -> V_52 -> V_116 ;
T_3 V_117 ;
void * V_118 ;
unsigned int V_36 , V_119 ;
V_119 = sizeof( struct V_46 ) *
V_120 * V_40 ;
V_118 = F_32 ( V_2 -> V_52 ,
V_119 , & V_117 , V_121 | V_122 ) ;
if ( ! V_118 ) {
F_9 ( L_15 ) ;
return;
}
memset ( V_118 , 0 , V_119 ) ;
for ( V_36 = 0 ; V_36 < V_40 ; V_36 ++ ) {
if ( V_117 & 0xF ) {
F_9 ( L_16 ) ;
return;
}
V_35 -> V_41 [ V_36 ] . V_47 = V_118 ;
V_35 -> V_41 [ V_36 ] . V_43 = V_117 ;
F_12 ( L_17 , V_36 , V_118 ) ;
V_118 += sizeof( struct V_46 ) ;
V_117 += sizeof( struct V_46 ) ;
if ( V_117 & 0xF ) {
F_9 ( L_16 ) ;
return;
}
V_35 -> V_41 [ V_36 ] . V_48 = V_118 ;
V_35 -> V_41 [ V_36 ] . V_42 = V_117 ;
F_12 ( L_18 , V_36 , V_118 ) ;
V_118 += sizeof( struct V_46 ) ;
V_117 += sizeof( struct V_46 ) ;
}
if ( F_33 ( V_115 , L_19 ) ) {
char * V_123 ;
switch ( V_2 -> V_124 ) {
case V_125 :
V_123 = L_20 ;
break;
case V_126 :
V_123 = L_21 ;
break;
case V_127 :
V_123 = L_22 ;
break;
case V_128 :
V_123 = L_23 ;
break;
default:
F_9 ( L_24 ) ;
return;
}
V_35 -> V_95 = F_34 ( V_2 -> V_52 , V_123 ) ;
if ( F_35 ( V_35 -> V_95 ) )
F_9 ( L_25 , V_123 ) ;
V_35 -> V_98 = F_34 ( V_2 -> V_52 , L_26 ) ;
if ( F_35 ( V_35 -> V_98 ) )
F_9 ( L_27 ) ;
V_35 -> V_99 = F_34 ( V_2 -> V_52 , L_28 ) ;
if ( F_35 ( V_35 -> V_99 ) )
F_9 ( L_29 ) ;
}
}
struct V_1 * F_36 ( struct V_51 * V_52 , int V_129 )
{
struct V_34 * V_35 ;
V_35 = F_37 ( V_52 , sizeof( * V_35 ) , V_121 ) ;
if ( ! V_35 ) {
F_9 ( L_30 ) ;
return NULL ;
}
V_35 -> V_2 . V_130 = & V_131 ;
V_35 -> V_94 . V_132 = F_29 ;
return (struct V_1 * ) V_35 ;
}
