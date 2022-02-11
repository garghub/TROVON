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
void * V_30 ;
struct V_31 * V_32 = F_7 ( V_2 ) ;
unsigned int V_33 ;
V_29 = F_8 ( V_2 -> V_34 + V_35 ) ;
if ( ! V_29 )
goto V_36;
V_30 = F_9 ( V_2 -> V_37 , ( V_38 ) V_29 ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ )
if ( ( V_30 != V_32 -> V_40 [ V_33 ] . V_41 ) &&
( V_30 != V_32 -> V_40 [ V_33 ] . V_42 ) )
return & V_32 -> V_40 [ V_33 ] ;
F_10 ( L_1 ,
F_11 ( V_2 ) , V_29 ) ;
V_36:
return & V_32 -> V_40 [ 0 ] ;
}
static
struct V_28 * F_12 ( struct V_1 * V_2 )
{
int V_29 ;
void * V_30 ;
struct V_31 * V_32 = F_7 ( V_2 ) ;
unsigned int V_33 ;
V_29 = F_8 ( V_2 -> V_34 + V_35 ) ;
if ( ! V_29 )
goto V_36;
V_30 = F_9 ( V_2 -> V_37 , ( V_38 ) V_29 ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ )
if ( ( V_30 == V_32 -> V_40 [ V_33 ] . V_41 ) ||
( V_30 == V_32 -> V_40 [ V_33 ] . V_42 ) )
return & V_32 -> V_40 [ V_33 ] ;
V_36:
F_13 ( L_2 ,
V_29 , F_11 ( V_2 ) ) ;
return NULL ;
}
static int F_14 ( struct V_1 * V_2 , bool V_43 )
{
struct V_28 * V_44 ;
struct V_45 * V_42 , * V_41 ;
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_48 * V_37 = V_2 -> V_37 ;
struct V_31 * V_32 = F_7 ( V_2 ) ;
struct V_49 * V_50 = F_15 ( V_37 ) ;
int V_25 ;
unsigned int V_51 , V_52 ;
int V_53 = V_47 -> clock * 1000 ;
int V_54 ;
T_2 V_55 , V_56 , V_57 , V_58 ;
V_44 = F_6 ( V_2 ) ;
V_42 = V_44 -> V_42 ;
V_41 = V_44 -> V_41 ;
F_16 ( V_37 , L_3 , V_59 ,
F_11 ( V_2 ) , V_42 , V_41 ) ;
V_42 -> V_60 = V_61 ;
V_42 -> V_62 = V_63 ;
V_25 = F_4 ( V_2 -> V_25 ) ;
if ( V_25 == - 1 ) {
F_10 ( L_4 ,
( char * ) & V_2 -> V_25 ) ;
return 1 ;
}
V_42 -> V_62 |= V_25 ;
V_42 -> V_62 |= F_5 ( V_25 ) ;
V_42 -> V_64 &= ~ V_65 ;
F_17 ( V_2 -> V_25 , & V_51 , & V_52 ) ;
V_42 -> V_66 = ( T_2 ) V_2 -> V_67 + V_2 -> V_68 [ 0 ] ;
V_42 -> V_66 += V_2 -> V_69 * ( V_52 >> 3 ) ;
V_42 -> V_66 += V_2 -> V_70 * V_2 -> V_71 [ 0 ] ;
V_42 -> V_72 = V_2 -> V_71 [ 0 ] ;
V_42 -> V_73 =
F_18 ( V_2 -> V_74 , 0 , V_75 ) << 16 |
F_18 ( V_2 -> V_76 , 0 , V_75 ) ;
V_55 = F_19 ( * V_47 , V_2 -> V_77 ) ;
V_57 = F_19 ( * V_47 , V_2 -> V_77 + V_2 -> V_78 - 1 ) ;
V_56 = F_20 ( * V_47 , V_2 -> V_79 ) ;
V_58 = F_20 ( * V_47 , V_2 -> V_79 + V_2 -> V_80 - 1 ) ;
V_42 -> V_81 = ( V_55 << 16 ) | V_56 ;
V_42 -> V_82 = ( V_57 << 16 ) | V_58 ;
memcpy ( V_41 , V_42 , sizeof( * V_41 ) ) ;
V_42 -> V_83 = F_21 ( V_37 , V_41 ) ;
V_41 -> V_83 = F_21 ( V_37 , V_42 ) ;
if ( V_2 -> V_47 -> V_84 & V_85 )
V_41 -> V_66 = V_42 -> V_66 +
V_2 -> V_71 [ 0 ] ;
if ( V_43 ) {
if ( F_22 ( V_2 -> V_86 == V_87 ?
V_50 -> V_88 : V_50 -> V_89 ,
& V_32 -> V_90 , V_2 -> V_86 ) ) {
F_10 ( L_5 ) ;
return 1 ;
}
if ( V_32 -> V_91 ) {
V_54 = F_23 ( V_32 -> V_91 , V_53 ) ;
if ( V_54 < 0 ) {
F_10 ( L_6 ,
V_53 ) ;
return 1 ;
}
if ( F_24 ( V_32 -> V_91 ) ) {
F_10 ( L_7 ) ;
return 1 ;
}
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_28 * V_92 = F_6 ( V_2 ) ;
struct V_45 * V_93 = V_92 -> V_42 ;
struct V_45 * V_94 = V_92 -> V_41 ;
struct V_31 * V_32 = F_7 ( V_2 ) ;
T_2 V_95 = F_21 ( V_2 -> V_37 , V_93 ) ;
T_2 V_96 = F_21 ( V_2 -> V_37 , V_94 ) ;
struct V_28 * V_97 = F_12 ( V_2 ) ;
F_16 ( V_2 -> V_37 , L_8 , V_59 ,
F_11 ( V_2 ) ,
V_93 , V_94 ) ;
F_16 ( V_2 -> V_37 , L_9 ,
F_8 ( V_2 -> V_34 + V_35 ) ) ;
F_16 ( V_2 -> V_37 , L_10 ,
( unsigned long ) V_2 -> V_67 ,
F_8 ( V_2 -> V_34 + V_98 ) ) ;
if ( V_97 == NULL ) {
F_13 ( L_11 ,
F_11 ( V_2 ) ) ;
F_26 ( V_32 -> V_99 == true ?
V_96 : V_95 ,
V_2 -> V_34 + V_35 ) ;
return 0 ;
}
if ( V_2 -> V_47 -> V_84 & V_85 ) {
if ( V_32 -> V_99 == true ) {
V_97 -> V_41 -> V_83 = V_95 ;
} else {
F_26 ( V_95 ,
V_2 -> V_34 + V_35 ) ;
}
} else {
F_26 ( V_95 , V_2 -> V_34 + V_35 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
struct V_31 * V_32 = F_7 ( V_2 ) ;
struct V_49 * V_50 = F_15 ( V_2 -> V_37 ) ;
F_13 ( L_12 , F_11 ( V_2 ) ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
V_32 -> V_40 [ V_33 ] . V_42 -> V_64 |= V_65 ;
V_32 -> V_40 [ V_33 ] . V_41 -> V_64 |= V_65 ;
}
if ( F_28 ( V_2 -> V_86 == V_87 ?
V_50 -> V_88 : V_50 -> V_89 , & V_32 -> V_90 ) )
F_13 ( L_13 ) ;
if ( V_32 -> V_91 )
F_29 ( V_32 -> V_91 ) ;
return 0 ;
}
int F_30 ( struct V_100 * V_101 ,
unsigned long V_102 , void * V_103 )
{
struct V_31 * V_32 = F_31 ( V_101 , struct V_31 , V_90 ) ;
switch ( V_102 ) {
case V_104 :
V_32 -> V_99 = true ;
break;
case V_105 :
V_32 -> V_99 = false ;
break;
default:
F_10 ( L_14 , V_102 ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_7 ( V_2 ) ;
struct V_106 * V_107 = V_2 -> V_37 -> V_108 ;
V_38 V_109 ;
void * V_110 ;
unsigned int V_33 , V_111 ;
V_111 = sizeof( struct V_45 ) *
V_112 * V_39 ;
V_110 = F_33 ( V_2 -> V_37 ,
V_111 , & V_109 , V_113 | V_114 ) ;
if ( ! V_110 ) {
F_10 ( L_15 ) ;
return;
}
memset ( V_110 , 0 , V_111 ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
if ( F_21 ( V_2 -> V_37 , V_110 ) & 0xF ) {
F_10 ( L_16 ) ;
return;
}
V_32 -> V_40 [ V_33 ] . V_42 = V_110 ;
F_13 ( L_17 , V_33 , V_110 ) ;
V_110 += sizeof( struct V_45 ) ;
if ( F_21 ( V_2 -> V_37 , V_110 ) & 0xF ) {
F_10 ( L_16 ) ;
return;
}
V_32 -> V_40 [ V_33 ] . V_41 = V_110 ;
F_13 ( L_18 , V_33 , V_110 ) ;
V_110 += sizeof( struct V_45 ) ;
}
if ( F_34 ( V_107 , L_19 ) ) {
char * V_115 ;
switch ( V_2 -> V_116 ) {
case V_117 :
V_115 = L_20 ;
break;
case V_118 :
V_115 = L_21 ;
break;
case V_119 :
V_115 = L_22 ;
break;
case V_120 :
V_115 = L_23 ;
break;
default:
F_10 ( L_24 ) ;
return;
}
V_32 -> V_91 = F_35 ( V_2 -> V_37 , V_115 ) ;
if ( F_36 ( V_32 -> V_91 ) )
F_10 ( L_25 , V_115 ) ;
}
}
struct V_1 * F_37 ( struct V_48 * V_37 , int V_121 )
{
struct V_31 * V_32 ;
V_32 = F_38 ( V_37 , sizeof( * V_32 ) , V_113 ) ;
if ( ! V_32 ) {
F_10 ( L_26 ) ;
return NULL ;
}
V_32 -> V_2 . V_122 = & V_123 ;
V_32 -> V_90 . V_124 = F_30 ;
return (struct V_1 * ) V_32 ;
}
