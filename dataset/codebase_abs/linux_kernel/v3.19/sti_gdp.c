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
}
return - 1 ;
}
static int F_5 ( int V_25 )
{
switch ( V_25 ) {
case V_26 :
case V_8 :
case V_18 :
return V_27 ;
}
return 0 ;
}
static struct V_28 * F_6 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_30 * V_31 = F_7 ( V_2 ) ;
unsigned int V_32 ;
V_29 = F_8 ( V_2 -> V_33 + V_34 ) ;
if ( ! V_29 )
goto V_35;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
if ( ( V_29 != V_31 -> V_37 [ V_32 ] . V_38 ) &&
( V_29 != V_31 -> V_37 [ V_32 ] . V_39 ) )
return & V_31 -> V_37 [ V_32 ] ;
F_9 ( L_1 ,
F_10 ( V_2 ) , V_29 ) ;
V_35:
return & V_31 -> V_37 [ 0 ] ;
}
static
struct V_28 * F_11 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_30 * V_31 = F_7 ( V_2 ) ;
unsigned int V_32 ;
V_29 = F_8 ( V_2 -> V_33 + V_34 ) ;
if ( ! V_29 )
goto V_35;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
if ( ( V_29 == V_31 -> V_37 [ V_32 ] . V_38 ) ||
( V_29 == V_31 -> V_37 [ V_32 ] . V_39 ) )
return & V_31 -> V_37 [ V_32 ] ;
V_35:
F_12 ( L_2 ,
V_29 , F_10 ( V_2 ) ) ;
return NULL ;
}
static int F_13 ( struct V_1 * V_2 , bool V_40 )
{
struct V_28 * V_41 ;
struct V_42 * V_43 , * V_44 ;
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_47 * V_48 = V_2 -> V_48 ;
struct V_30 * V_31 = F_7 ( V_2 ) ;
struct V_49 * V_50 = F_14 ( V_48 ) ;
int V_25 ;
unsigned int V_51 , V_52 ;
int V_53 = V_46 -> clock * 1000 ;
int V_54 ;
T_2 V_55 , V_56 , V_57 , V_58 ;
V_41 = F_6 ( V_2 ) ;
V_43 = V_41 -> V_43 ;
V_44 = V_41 -> V_44 ;
F_15 ( V_48 , L_3 , V_59 ,
F_10 ( V_2 ) , V_43 , V_44 ) ;
V_43 -> V_60 = V_61 ;
V_43 -> V_62 = V_63 ;
V_25 = F_4 ( V_2 -> V_25 ) ;
if ( V_25 == - 1 ) {
F_9 ( L_4 ,
( char * ) & V_2 -> V_25 ) ;
return 1 ;
}
V_43 -> V_62 |= V_25 ;
V_43 -> V_62 |= F_5 ( V_25 ) ;
V_43 -> V_64 &= ~ V_65 ;
F_16 ( V_2 -> V_25 , & V_51 , & V_52 ) ;
V_43 -> V_66 = ( T_2 ) V_2 -> V_67 + V_2 -> V_68 [ 0 ] ;
V_43 -> V_66 += V_2 -> V_69 * ( V_52 >> 3 ) ;
V_43 -> V_66 += V_2 -> V_70 * V_2 -> V_71 [ 0 ] ;
V_43 -> V_72 = V_2 -> V_71 [ 0 ] ;
V_43 -> V_73 =
F_17 ( V_2 -> V_74 , 0 , V_75 ) << 16 |
F_17 ( V_2 -> V_76 , 0 , V_75 ) ;
V_55 = F_18 ( * V_46 , V_2 -> V_77 ) ;
V_57 = F_18 ( * V_46 , V_2 -> V_77 + V_2 -> V_78 - 1 ) ;
V_56 = F_19 ( * V_46 , V_2 -> V_79 ) ;
V_58 = F_19 ( * V_46 , V_2 -> V_79 + V_2 -> V_80 - 1 ) ;
V_43 -> V_81 = ( V_55 << 16 ) | V_56 ;
V_43 -> V_82 = ( V_57 << 16 ) | V_58 ;
memcpy ( V_44 , V_43 , sizeof( * V_44 ) ) ;
V_43 -> V_83 = V_41 -> V_38 ;
V_44 -> V_83 = V_41 -> V_39 ;
if ( V_2 -> V_46 -> V_84 & V_85 )
V_44 -> V_66 = V_43 -> V_66 +
V_2 -> V_71 [ 0 ] ;
if ( V_40 ) {
if ( F_20 ( V_2 -> V_86 == V_87 ?
V_50 -> V_88 : V_50 -> V_89 ,
& V_31 -> V_90 , V_2 -> V_86 ) ) {
F_9 ( L_5 ) ;
return 1 ;
}
if ( V_31 -> V_91 ) {
struct V_92 * V_93 ;
if ( V_2 -> V_86 == V_87 )
V_93 = V_31 -> V_94 ;
else
V_93 = V_31 -> V_95 ;
if ( V_93 )
F_21 ( V_31 -> V_91 , V_93 ) ;
V_54 = F_22 ( V_31 -> V_91 , V_53 ) ;
if ( V_54 < 0 ) {
F_9 ( L_6 ,
V_53 ) ;
return 1 ;
}
if ( F_23 ( V_31 -> V_91 ) ) {
F_9 ( L_7 ) ;
return 1 ;
}
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_96 = F_6 ( V_2 ) ;
struct V_42 * V_97 = V_96 -> V_43 ;
struct V_42 * V_98 = V_96 -> V_44 ;
struct V_30 * V_31 = F_7 ( V_2 ) ;
T_2 V_99 = V_96 -> V_39 ;
T_2 V_100 = V_96 -> V_38 ;
struct V_28 * V_101 = F_11 ( V_2 ) ;
F_15 ( V_2 -> V_48 , L_8 , V_59 ,
F_10 ( V_2 ) ,
V_97 , V_98 ) ;
F_15 ( V_2 -> V_48 , L_9 ,
F_8 ( V_2 -> V_33 + V_34 ) ) ;
F_15 ( V_2 -> V_48 , L_10 ,
( unsigned long ) V_2 -> V_67 ,
F_8 ( V_2 -> V_33 + V_102 ) ) ;
if ( V_101 == NULL ) {
F_12 ( L_11 ,
F_10 ( V_2 ) ) ;
F_25 ( V_31 -> V_103 == true ?
V_100 : V_99 ,
V_2 -> V_33 + V_34 ) ;
return 0 ;
}
if ( V_2 -> V_46 -> V_84 & V_85 ) {
if ( V_31 -> V_103 == true ) {
V_101 -> V_44 -> V_83 = V_99 ;
} else {
F_25 ( V_99 ,
V_2 -> V_33 + V_34 ) ;
}
} else {
F_25 ( V_99 , V_2 -> V_33 + V_34 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
struct V_30 * V_31 = F_7 ( V_2 ) ;
struct V_49 * V_50 = F_14 ( V_2 -> V_48 ) ;
F_12 ( L_12 , F_10 ( V_2 ) ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
V_31 -> V_37 [ V_32 ] . V_43 -> V_64 |= V_65 ;
V_31 -> V_37 [ V_32 ] . V_44 -> V_64 |= V_65 ;
}
if ( F_27 ( V_2 -> V_86 == V_87 ?
V_50 -> V_88 : V_50 -> V_89 , & V_31 -> V_90 ) )
F_12 ( L_13 ) ;
if ( V_31 -> V_91 )
F_28 ( V_31 -> V_91 ) ;
return 0 ;
}
int F_29 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_30 * V_31 = F_30 ( V_105 , struct V_30 , V_90 ) ;
switch ( V_106 ) {
case V_108 :
V_31 -> V_103 = true ;
break;
case V_109 :
V_31 -> V_103 = false ;
break;
default:
F_9 ( L_14 , V_106 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_7 ( V_2 ) ;
struct V_110 * V_111 = V_2 -> V_48 -> V_112 ;
T_3 V_113 ;
void * V_114 ;
unsigned int V_32 , V_115 ;
V_115 = sizeof( struct V_42 ) *
V_116 * V_36 ;
V_114 = F_32 ( V_2 -> V_48 ,
V_115 , & V_113 , V_117 | V_118 ) ;
if ( ! V_114 ) {
F_9 ( L_15 ) ;
return;
}
memset ( V_114 , 0 , V_115 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
if ( V_113 & 0xF ) {
F_9 ( L_16 ) ;
return;
}
V_31 -> V_37 [ V_32 ] . V_43 = V_114 ;
V_31 -> V_37 [ V_32 ] . V_39 = V_113 ;
F_12 ( L_17 , V_32 , V_114 ) ;
V_114 += sizeof( struct V_42 ) ;
V_113 += sizeof( struct V_42 ) ;
if ( V_113 & 0xF ) {
F_9 ( L_16 ) ;
return;
}
V_31 -> V_37 [ V_32 ] . V_44 = V_114 ;
V_31 -> V_37 [ V_32 ] . V_38 = V_113 ;
F_12 ( L_18 , V_32 , V_114 ) ;
V_114 += sizeof( struct V_42 ) ;
V_113 += sizeof( struct V_42 ) ;
}
if ( F_33 ( V_111 , L_19 ) ) {
char * V_119 ;
switch ( V_2 -> V_120 ) {
case V_121 :
V_119 = L_20 ;
break;
case V_122 :
V_119 = L_21 ;
break;
case V_123 :
V_119 = L_22 ;
break;
case V_124 :
V_119 = L_23 ;
break;
default:
F_9 ( L_24 ) ;
return;
}
V_31 -> V_91 = F_34 ( V_2 -> V_48 , V_119 ) ;
if ( F_35 ( V_31 -> V_91 ) )
F_9 ( L_25 , V_119 ) ;
V_31 -> V_94 = F_34 ( V_2 -> V_48 , L_26 ) ;
if ( F_35 ( V_31 -> V_94 ) )
F_9 ( L_27 ) ;
V_31 -> V_95 = F_34 ( V_2 -> V_48 , L_28 ) ;
if ( F_35 ( V_31 -> V_95 ) )
F_9 ( L_29 ) ;
}
}
struct V_1 * F_36 ( struct V_47 * V_48 , int V_125 )
{
struct V_30 * V_31 ;
V_31 = F_37 ( V_48 , sizeof( * V_31 ) , V_117 ) ;
if ( ! V_31 ) {
F_9 ( L_30 ) ;
return NULL ;
}
V_31 -> V_2 . V_126 = & V_127 ;
V_31 -> V_90 . V_128 = F_29 ;
return (struct V_1 * ) V_31 ;
}
