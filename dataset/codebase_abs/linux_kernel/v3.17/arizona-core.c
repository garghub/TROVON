int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 ) {
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
V_2 = F_3 ( V_1 -> V_8 ) ;
if ( V_2 != 0 )
goto V_9;
break;
}
V_2 = F_4 ( V_1 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
}
V_9:
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_6 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
F_7 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 ) {
F_4 ( V_1 -> V_10 , V_11 ,
V_12 , 0 ) ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
F_8 ( V_1 -> V_8 ) ;
break;
}
}
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static T_1 F_9 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
F_10 ( V_1 -> V_8 , L_1 ) ;
return V_15 ;
}
static T_1 F_11 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_10 , V_17 ,
& V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_2 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 & V_19 )
F_10 ( V_1 -> V_8 , L_3 ) ;
if ( V_16 & V_20 )
F_10 ( V_1 -> V_8 , L_4 ) ;
if ( V_16 & V_21 )
F_10 ( V_1 -> V_8 , L_5 ) ;
if ( V_16 & V_22 )
F_10 ( V_1 -> V_8 , L_6 ) ;
if ( V_16 & V_23 )
F_10 ( V_1 -> V_8 , L_7 ) ;
if ( V_16 & V_24 )
F_10 ( V_1 -> V_8 , L_8 ) ;
if ( V_16 & V_25 )
F_10 ( V_1 -> V_8 , L_9 ) ;
if ( V_16 & V_26 )
F_10 ( V_1 -> V_8 , L_10 ) ;
if ( V_16 & V_27 )
F_10 ( V_1 -> V_8 , L_11 ) ;
if ( V_16 & V_28 )
F_10 ( V_1 -> V_8 , L_12 ) ;
if ( V_16 & V_29 )
F_10 ( V_1 -> V_8 , L_13 ) ;
return V_15 ;
}
static T_1 F_13 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 [ 2 ] ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_10 , V_30 ,
& V_16 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_14 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 [ 0 ] & V_31 )
F_10 ( V_1 -> V_8 , L_15 ) ;
if ( V_16 [ 0 ] & V_32 )
F_10 ( V_1 -> V_8 , L_16 ) ;
if ( V_16 [ 0 ] & V_33 )
F_10 ( V_1 -> V_8 , L_17 ) ;
if ( V_16 [ 0 ] & V_34 )
F_10 ( V_1 -> V_8 , L_18 ) ;
if ( V_16 [ 0 ] & V_35 )
F_10 ( V_1 -> V_8 , L_19 ) ;
if ( V_16 [ 0 ] & V_36 )
F_10 ( V_1 -> V_8 , L_20 ) ;
if ( V_16 [ 0 ] & V_37 )
F_10 ( V_1 -> V_8 , L_21 ) ;
if ( V_16 [ 0 ] & V_38 )
F_10 ( V_1 -> V_8 , L_22 ) ;
if ( V_16 [ 0 ] & V_39 )
F_10 ( V_1 -> V_8 , L_23 ) ;
if ( V_16 [ 0 ] & V_40 )
F_10 ( V_1 -> V_8 , L_24 ) ;
if ( V_16 [ 1 ] & V_41 )
F_10 ( V_1 -> V_8 , L_25 ) ;
if ( V_16 [ 1 ] & V_42 )
F_10 ( V_1 -> V_8 , L_26 ) ;
if ( V_16 [ 1 ] & V_43 )
F_10 ( V_1 -> V_8 , L_27 ) ;
if ( V_16 [ 1 ] & V_44 )
F_10 ( V_1 -> V_8 , L_28 ) ;
if ( V_16 [ 1 ] & V_45 )
F_10 ( V_1 -> V_8 , L_29 ) ;
if ( V_16 [ 1 ] & V_46 )
F_10 ( V_1 -> V_8 , L_30 ) ;
if ( V_16 [ 1 ] & V_47 )
F_10 ( V_1 -> V_8 , L_31 ) ;
if ( V_16 [ 1 ] & V_48 )
F_10 ( V_1 -> V_8 , L_32 ) ;
if ( V_16 [ 1 ] & V_49 )
F_10 ( V_1 -> V_8 , L_33 ) ;
if ( V_16 [ 1 ] & V_50 )
F_10 ( V_1 -> V_8 , L_34 ) ;
if ( V_16 [ 1 ] & V_51 )
F_10 ( V_1 -> V_8 , L_35 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_1 ,
int V_52 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
unsigned int V_16 = 0 ;
int V_2 , V_56 ;
for ( V_56 = 0 ; V_56 < V_52 ; V_56 ++ ) {
V_2 = F_12 ( V_1 -> V_10 , V_53 , & V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_36 ,
V_53 , V_2 ) ;
continue;
}
if ( ( V_16 & V_54 ) == V_55 )
return 0 ;
F_16 ( 1 ) ;
}
F_10 ( V_1 -> V_8 , L_37 , V_53 , V_16 ) ;
return - V_57 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_15 ( V_1 , 5 , V_58 ,
V_59 , V_59 ) ;
if ( ! V_2 )
F_18 ( V_1 -> V_10 , V_60 ,
V_59 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_2 ;
}
static int F_20 ( struct V_1 * V_1 )
{
unsigned int V_61 , V_62 ;
int V_2 , V_63 ;
V_2 = F_12 ( V_1 -> V_10 , V_64 , & V_61 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_38 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_10 , V_65 , & V_62 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_39 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_64 ,
V_66 | V_67 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_40 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_15 ( V_1 , 25 , V_58 ,
V_68 ,
V_68 ) ;
if ( V_2 != 0 ) {
V_2 = - V_57 ;
goto V_69;
}
V_2 = F_18 ( V_1 -> V_10 , V_65 , 0x0144 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_41 , V_2 ) ;
goto V_69;
}
V_2 = F_18 ( V_1 -> V_10 , V_70 ,
V_71 | V_72 | 160 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_42 ,
V_2 ) ;
goto V_73;
}
V_2 = F_15 ( V_1 , 5 , V_74 ,
V_75 , 0 ) ;
if ( V_2 != 0 ) {
F_18 ( V_1 -> V_10 , V_70 ,
V_76 ) ;
V_2 = - V_57 ;
}
V_73:
V_63 = F_18 ( V_1 -> V_10 , V_65 , V_62 ) ;
if ( V_63 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_43 ,
V_63 ) ;
}
V_69:
V_63 = F_18 ( V_1 -> V_10 , V_64 , V_61 ) ;
if ( V_63 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_44 ,
V_63 ) ;
}
if ( V_2 != 0 )
return V_2 ;
else
return V_63 ;
}
static int F_21 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
int V_2 ;
F_23 ( V_1 -> V_8 , L_45 ) ;
V_2 = F_24 ( V_1 -> V_78 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_46 , V_2 ) ;
return V_2 ;
}
F_25 ( V_1 -> V_10 , false ) ;
switch ( V_1 -> type ) {
case V_79 :
if ( V_1 -> V_80 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_81 ,
V_82 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_47 , V_2 ) ;
goto V_63;
}
}
V_2 = F_26 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_48 ,
V_2 ) ;
goto V_63;
}
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_49 ,
V_2 ) ;
goto V_63;
}
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
goto V_63;
}
if ( V_1 -> V_80 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_81 ,
V_82 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_47 , V_2 ) ;
goto V_63;
}
}
break;
}
switch ( V_1 -> type ) {
case V_79 :
V_2 = F_26 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_48 ,
V_2 ) ;
goto V_63;
}
default:
break;
}
V_2 = F_27 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_50 ) ;
goto V_63;
}
return 0 ;
V_63:
F_25 ( V_1 -> V_10 , true ) ;
F_28 ( V_1 -> V_78 ) ;
return V_2 ;
}
static int F_29 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
int V_2 ;
F_23 ( V_1 -> V_8 , L_51 ) ;
if ( V_1 -> V_80 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_81 ,
V_82 ,
V_82 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_52 ,
V_2 ) ;
return V_2 ;
}
}
F_25 ( V_1 -> V_10 , true ) ;
F_30 ( V_1 -> V_10 ) ;
F_28 ( V_1 -> V_78 ) ;
return 0 ;
}
static int F_31 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_53 ) ;
F_32 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_33 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_54 ) ;
F_34 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_35 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_55 ) ;
F_32 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_77 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_56 ) ;
F_34 ( V_1 -> V_13 ) ;
return 0 ;
}
unsigned long F_37 ( struct V_77 * V_8 )
{
const struct V_83 * V_84 = F_38 ( V_85 , V_8 ) ;
if ( V_84 )
return ( unsigned long ) V_84 -> V_14 ;
else
return 0 ;
}
int F_39 ( struct V_1 * V_1 , const char * V_86 ,
bool V_87 )
{
int V_88 ;
V_88 = F_40 ( V_1 -> V_8 -> V_89 , V_86 , 0 ) ;
if ( V_88 < 0 ) {
if ( V_87 )
F_10 ( V_1 -> V_8 ,
L_57 ,
V_86 , V_88 ) ;
V_88 = 0 ;
}
return V_88 ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_90 * V_5 = & V_1 -> V_5 ;
int V_2 , V_56 ;
V_5 -> V_91 = F_39 ( V_1 , L_58 , true ) ;
V_2 = F_42 ( V_1 -> V_8 -> V_89 ,
L_59 ,
V_1 -> V_5 . V_92 ,
F_43 ( V_1 -> V_5 . V_92 ) ) ;
if ( V_2 >= 0 ) {
for ( V_56 = 0 ; V_56 < F_43 ( V_1 -> V_5 . V_92 ) ; V_56 ++ ) {
if ( V_1 -> V_5 . V_92 [ V_56 ] > 0xffff )
V_1 -> V_5 . V_92 [ V_56 ] = 0 ;
else if ( V_1 -> V_5 . V_92 [ V_56 ] == 0 )
V_1 -> V_5 . V_92 [ V_56 ] = 0x10000 ;
}
} else {
F_10 ( V_1 -> V_8 , L_60 ,
V_2 ) ;
}
return 0 ;
}
static inline int F_41 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_77 * V_8 = V_1 -> V_8 ;
const char * V_93 ;
unsigned int V_53 , V_16 ;
int (* F_45)( struct V_1 * ) = NULL ;
int V_2 , V_56 ;
F_46 ( V_1 -> V_8 , V_1 ) ;
F_47 ( & V_1 -> V_3 ) ;
if ( F_48 ( V_1 -> V_8 ) )
memcpy ( & V_1 -> V_5 , F_48 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
else
F_41 ( V_1 ) ;
F_25 ( V_1 -> V_10 , true ) ;
switch ( V_1 -> type ) {
case V_79 :
case V_94 :
case V_95 :
for ( V_56 = 0 ; V_56 < F_43 ( V_96 ) ; V_56 ++ )
V_1 -> V_97 [ V_56 ] . V_98
= V_96 [ V_56 ] ;
V_1 -> V_99 = F_43 ( V_96 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_61 ,
V_1 -> type ) ;
return - V_100 ;
}
V_1 -> V_80 = true ;
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_101 ,
F_43 ( V_101 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_62 , V_2 ) ;
return V_2 ;
}
V_2 = F_50 ( V_8 , V_1 -> V_99 ,
V_1 -> V_97 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_63 ,
V_2 ) ;
goto V_102;
}
V_1 -> V_78 = F_51 ( V_1 -> V_8 , L_64 ) ;
if ( F_52 ( V_1 -> V_78 ) ) {
V_2 = F_53 ( V_1 -> V_78 ) ;
F_10 ( V_8 , L_65 , V_2 ) ;
goto V_102;
}
if ( V_1 -> V_5 . V_91 ) {
V_2 = F_54 ( V_1 -> V_5 . V_91 ,
V_103 | V_104 ,
L_66 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_67 , V_2 ) ;
goto V_105;
}
}
V_2 = F_55 ( V_1 -> V_99 ,
V_1 -> V_97 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_68 ,
V_2 ) ;
goto V_105;
}
V_2 = F_24 ( V_1 -> V_78 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_46 , V_2 ) ;
goto V_106;
}
if ( V_1 -> V_5 . V_91 ) {
F_56 ( V_1 -> V_5 . V_91 , 1 ) ;
F_16 ( 1 ) ;
}
F_25 ( V_1 -> V_10 , false ) ;
V_2 = F_12 ( V_1 -> V_10 , V_107 , & V_53 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_69 , V_2 ) ;
goto V_108;
}
switch ( V_53 ) {
case 0x5102 :
case 0x5110 :
case 0x8997 :
break;
default:
F_10 ( V_1 -> V_8 , L_70 , V_53 ) ;
goto V_108;
}
if ( ! V_1 -> V_5 . V_91 ) {
F_30 ( V_1 -> V_10 ) ;
V_2 = F_18 ( V_1 -> V_10 , V_107 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_71 , V_2 ) ;
goto V_108;
}
F_16 ( 1 ) ;
V_2 = F_27 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_72 , V_2 ) ;
goto V_108;
}
}
switch ( V_1 -> type ) {
case V_79 :
V_2 = F_12 ( V_1 -> V_10 , 0x19 , & V_16 ) ;
if ( V_2 != 0 )
F_10 ( V_8 ,
L_73 ,
V_2 ) ;
else if ( V_16 & 0x01 )
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_74 , V_2 ) ;
goto V_108;
}
break;
}
V_2 = F_12 ( V_1 -> V_10 , V_107 , & V_53 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_69 , V_2 ) ;
goto V_108;
}
V_2 = F_12 ( V_1 -> V_10 , V_109 ,
& V_1 -> V_110 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_75 , V_2 ) ;
goto V_108;
}
V_1 -> V_110 &= V_111 ;
switch ( V_53 ) {
#ifdef F_57
case 0x5102 :
V_93 = L_76 ;
if ( V_1 -> type != V_79 ) {
F_10 ( V_1 -> V_8 , L_77 ,
V_1 -> type ) ;
V_1 -> type = V_79 ;
}
F_45 = F_26 ;
V_1 -> V_110 &= 0x7 ;
break;
#endif
#ifdef F_58
case 0x5110 :
V_93 = L_78 ;
if ( V_1 -> type != V_94 ) {
F_10 ( V_1 -> V_8 , L_79 ,
V_1 -> type ) ;
V_1 -> type = V_94 ;
}
F_45 = V_112 ;
break;
#endif
#ifdef F_59
case 0x8997 :
V_93 = L_80 ;
if ( V_1 -> type != V_95 ) {
F_10 ( V_1 -> V_8 , L_81 ,
V_1 -> type ) ;
V_1 -> type = V_95 ;
}
F_45 = V_113 ;
break;
#endif
default:
F_10 ( V_1 -> V_8 , L_82 , V_53 ) ;
goto V_108;
}
F_60 ( V_8 , L_83 , V_93 , V_1 -> V_110 + 'A' ) ;
if ( F_45 ) {
V_2 = F_45 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_48 ,
V_2 ) ;
goto V_108;
}
switch ( V_1 -> type ) {
case V_79 :
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_49 ,
V_2 ) ;
goto V_108;
}
break;
default:
break;
}
}
for ( V_56 = 0 ; V_56 < F_43 ( V_1 -> V_5 . V_92 ) ; V_56 ++ ) {
if ( ! V_1 -> V_5 . V_92 [ V_56 ] )
continue;
F_18 ( V_1 -> V_10 , V_114 + V_56 ,
V_1 -> V_5 . V_92 [ V_56 ] ) ;
}
F_61 ( V_1 -> V_8 , 100 ) ;
F_62 ( V_1 -> V_8 ) ;
F_63 ( V_1 -> V_8 ) ;
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_115 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_115 :
F_4 ( V_1 -> V_10 , V_11 ,
V_116 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_117 :
F_4 ( V_1 -> V_10 , V_11 ,
V_116 , 2 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_84 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_100 ;
goto V_108;
}
for ( V_56 = 0 ; V_56 < V_118 ; V_56 ++ ) {
if ( ! V_1 -> V_5 . V_119 [ V_56 ] . V_120 &&
! V_1 -> V_5 . V_119 [ V_56 ] . V_121 )
continue;
if ( ! V_1 -> V_5 . V_119 [ V_56 ] . V_120 )
V_1 -> V_5 . V_119 [ V_56 ] . V_120 = 2800 ;
V_16 = ( V_1 -> V_5 . V_119 [ V_56 ] . V_120 - 1500 ) / 100 ;
V_16 <<= V_122 ;
if ( V_1 -> V_5 . V_119 [ V_56 ] . V_123 )
V_16 |= V_124 ;
if ( V_1 -> V_5 . V_119 [ V_56 ] . V_125 )
V_16 |= V_126 ;
if ( V_1 -> V_5 . V_119 [ V_56 ] . V_127 )
V_16 |= V_128 ;
if ( V_1 -> V_5 . V_119 [ V_56 ] . V_121 )
V_16 |= V_129 ;
F_4 ( V_1 -> V_10 ,
V_130 + V_56 ,
V_131 |
V_126 |
V_129 |
V_128 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_132 ; V_56 ++ ) {
V_16 = V_1 -> V_5 . V_133 [ V_56 ]
<< V_134 ;
V_16 |= V_1 -> V_5 . V_135 [ V_56 ] << V_136 ;
F_4 ( V_1 -> V_10 ,
V_137 + ( V_56 * 8 ) ,
V_138 |
V_139 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_140 ; V_56 ++ ) {
if ( V_1 -> V_5 . V_141 [ V_56 ] )
V_16 = V_142 ;
else
V_16 = 0 ;
F_4 ( V_1 -> V_10 ,
V_143 + ( V_56 * 8 ) ,
V_142 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_144 ; V_56 ++ ) {
if ( V_1 -> V_5 . V_145 [ V_56 ] )
F_4 ( V_1 -> V_10 ,
V_146 + ( V_56 * 2 ) ,
V_147 |
V_148 ,
V_1 -> V_5 . V_145 [ V_56 ] ) ;
if ( V_1 -> V_5 . V_149 [ V_56 ] )
F_4 ( V_1 -> V_10 ,
V_150 + ( V_56 * 2 ) ,
V_151 ,
V_1 -> V_5 . V_149 [ V_56 ] ) ;
}
V_2 = F_64 ( V_1 ) ;
if ( V_2 != 0 )
goto V_108;
F_65 ( V_1 , V_152 , L_85 ,
F_9 , V_1 ) ;
F_65 ( V_1 , V_153 , L_86 ,
F_13 , V_1 ) ;
F_65 ( V_1 , V_154 , L_87 ,
F_11 , V_1 ) ;
switch ( V_1 -> type ) {
case V_79 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_155 ,
F_43 ( V_155 ) , NULL , 0 , NULL ) ;
break;
case V_94 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_156 ,
F_43 ( V_156 ) , NULL , 0 , NULL ) ;
break;
case V_95 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_157 ,
F_43 ( V_157 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_88 , V_2 ) ;
goto V_158;
}
#ifdef F_66
F_28 ( V_1 -> V_78 ) ;
#endif
return 0 ;
V_158:
F_67 ( V_1 ) ;
V_108:
if ( V_1 -> V_5 . V_91 ) {
F_56 ( V_1 -> V_5 . V_91 , 0 ) ;
F_68 ( V_1 -> V_5 . V_91 ) ;
}
F_28 ( V_1 -> V_78 ) ;
V_106:
F_69 ( V_1 -> V_99 ,
V_1 -> V_97 ) ;
V_105:
F_70 ( V_1 -> V_78 ) ;
V_102:
F_71 ( V_8 ) ;
return V_2 ;
}
int F_72 ( struct V_1 * V_1 )
{
F_73 ( V_1 -> V_8 ) ;
F_28 ( V_1 -> V_78 ) ;
F_70 ( V_1 -> V_78 ) ;
F_71 ( V_1 -> V_8 ) ;
F_74 ( V_1 , V_154 , V_1 ) ;
F_74 ( V_1 , V_153 , V_1 ) ;
F_74 ( V_1 , V_152 , V_1 ) ;
F_67 ( V_1 ) ;
if ( V_1 -> V_5 . V_91 )
F_56 ( V_1 -> V_5 . V_91 , 0 ) ;
F_69 ( V_1 -> V_99 ,
V_1 -> V_97 ) ;
return 0 ;
}
