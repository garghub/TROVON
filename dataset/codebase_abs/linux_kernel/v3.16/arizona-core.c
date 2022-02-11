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
return V_15 ;
}
static T_1 F_13 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 [ 2 ] ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_10 , V_29 ,
& V_16 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_13 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 [ 0 ] & V_30 )
F_10 ( V_1 -> V_8 , L_14 ) ;
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
if ( V_16 [ 1 ] & V_40 )
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
return V_15 ;
}
static int F_15 ( struct V_1 * V_1 ,
int V_50 , unsigned int V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
unsigned int V_16 = 0 ;
int V_2 , V_54 ;
for ( V_54 = 0 ; V_54 < V_50 ; V_54 ++ ) {
V_2 = F_12 ( V_1 -> V_10 , V_51 , & V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_34 ,
V_51 , V_2 ) ;
continue;
}
if ( ( V_16 & V_52 ) == V_53 )
return 0 ;
F_16 ( 1 ) ;
}
F_10 ( V_1 -> V_8 , L_35 , V_51 , V_16 ) ;
return - V_55 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_15 ( V_1 , 5 , V_56 ,
V_57 , V_57 ) ;
if ( ! V_2 )
F_18 ( V_1 -> V_10 , V_58 ,
V_57 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_2 ;
}
static int F_20 ( struct V_1 * V_1 )
{
unsigned int V_59 , V_60 ;
int V_2 , V_61 ;
V_2 = F_12 ( V_1 -> V_10 , V_62 , & V_59 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_36 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_10 , V_63 , & V_60 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_37 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_62 ,
V_64 | V_65 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_38 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_15 ( V_1 , 25 , V_56 ,
V_66 ,
V_66 ) ;
if ( V_2 != 0 ) {
V_2 = - V_55 ;
goto V_67;
}
V_2 = F_18 ( V_1 -> V_10 , V_63 , 0x0144 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_39 , V_2 ) ;
goto V_67;
}
V_2 = F_18 ( V_1 -> V_10 , V_68 ,
V_69 | V_70 | 160 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_40 ,
V_2 ) ;
goto V_71;
}
V_2 = F_15 ( V_1 , 5 , V_72 ,
V_73 , 0 ) ;
if ( V_2 != 0 ) {
F_18 ( V_1 -> V_10 , V_68 ,
V_74 ) ;
V_2 = - V_55 ;
}
V_71:
V_61 = F_18 ( V_1 -> V_10 , V_63 , V_60 ) ;
if ( V_61 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_41 ,
V_61 ) ;
}
V_67:
V_61 = F_18 ( V_1 -> V_10 , V_62 , V_59 ) ;
if ( V_61 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_42 ,
V_61 ) ;
}
if ( V_2 != 0 )
return V_2 ;
else
return V_61 ;
}
static int F_21 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
int V_2 ;
F_23 ( V_1 -> V_8 , L_43 ) ;
V_2 = F_24 ( V_1 -> V_76 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_44 , V_2 ) ;
return V_2 ;
}
F_25 ( V_1 -> V_10 , false ) ;
switch ( V_1 -> type ) {
case V_77 :
if ( V_1 -> V_78 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_79 ,
V_80 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_45 , V_2 ) ;
goto V_61;
}
}
V_2 = F_26 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_46 ,
V_2 ) ;
goto V_61;
}
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_47 ,
V_2 ) ;
goto V_61;
}
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
goto V_61;
}
if ( V_1 -> V_78 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_79 ,
V_80 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_45 , V_2 ) ;
goto V_61;
}
}
break;
}
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_26 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_46 ,
V_2 ) ;
goto V_61;
}
default:
break;
}
V_2 = F_27 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_48 ) ;
goto V_61;
}
return 0 ;
V_61:
F_25 ( V_1 -> V_10 , true ) ;
F_28 ( V_1 -> V_76 ) ;
return V_2 ;
}
static int F_29 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
int V_2 ;
F_23 ( V_1 -> V_8 , L_49 ) ;
if ( V_1 -> V_78 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_79 ,
V_80 ,
V_80 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_50 ,
V_2 ) ;
return V_2 ;
}
}
F_25 ( V_1 -> V_10 , true ) ;
F_30 ( V_1 -> V_10 ) ;
F_28 ( V_1 -> V_76 ) ;
return 0 ;
}
static int F_31 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_51 ) ;
F_32 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_33 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_52 ) ;
F_34 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_35 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_53 ) ;
F_32 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_75 * V_8 )
{
struct V_1 * V_1 = F_22 ( V_8 ) ;
F_23 ( V_1 -> V_8 , L_54 ) ;
F_34 ( V_1 -> V_13 ) ;
return 0 ;
}
int F_37 ( struct V_75 * V_8 )
{
const struct V_81 * V_82 = F_38 ( V_83 , V_8 ) ;
if ( V_82 )
return ( int ) V_82 -> V_14 ;
else
return 0 ;
}
int F_39 ( struct V_1 * V_1 , const char * V_84 ,
bool V_85 )
{
int V_86 ;
V_86 = F_40 ( V_1 -> V_8 -> V_87 , V_84 , 0 ) ;
if ( V_86 < 0 ) {
if ( V_85 )
F_10 ( V_1 -> V_8 ,
L_55 ,
V_84 , V_86 ) ;
V_86 = 0 ;
}
return V_86 ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_88 * V_5 = & V_1 -> V_5 ;
int V_2 , V_54 ;
V_5 -> V_89 = F_39 ( V_1 , L_56 , true ) ;
V_2 = F_42 ( V_1 -> V_8 -> V_87 ,
L_57 ,
V_1 -> V_5 . V_90 ,
F_43 ( V_1 -> V_5 . V_90 ) ) ;
if ( V_2 >= 0 ) {
for ( V_54 = 0 ; V_54 < F_43 ( V_1 -> V_5 . V_90 ) ; V_54 ++ ) {
if ( V_1 -> V_5 . V_90 [ V_54 ] > 0xffff )
V_1 -> V_5 . V_90 [ V_54 ] = 0 ;
else if ( V_1 -> V_5 . V_90 [ V_54 ] == 0 )
V_1 -> V_5 . V_90 [ V_54 ] = 0x10000 ;
}
} else {
F_10 ( V_1 -> V_8 , L_58 ,
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
struct V_75 * V_8 = V_1 -> V_8 ;
const char * V_91 ;
unsigned int V_51 , V_16 ;
int (* F_45)( struct V_1 * ) = NULL ;
int V_2 , V_54 ;
F_46 ( V_1 -> V_8 , V_1 ) ;
F_47 ( & V_1 -> V_3 ) ;
if ( F_48 ( V_1 -> V_8 ) )
memcpy ( & V_1 -> V_5 , F_48 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
else
F_41 ( V_1 ) ;
F_25 ( V_1 -> V_10 , true ) ;
switch ( V_1 -> type ) {
case V_77 :
case V_92 :
case V_93 :
for ( V_54 = 0 ; V_54 < F_43 ( V_94 ) ; V_54 ++ )
V_1 -> V_95 [ V_54 ] . V_96
= V_94 [ V_54 ] ;
V_1 -> V_97 = F_43 ( V_94 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_59 ,
V_1 -> type ) ;
return - V_98 ;
}
V_1 -> V_78 = true ;
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_99 ,
F_43 ( V_99 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_60 , V_2 ) ;
return V_2 ;
}
V_2 = F_50 ( V_8 , V_1 -> V_97 ,
V_1 -> V_95 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_61 ,
V_2 ) ;
goto V_100;
}
V_1 -> V_76 = F_51 ( V_1 -> V_8 , L_62 ) ;
if ( F_52 ( V_1 -> V_76 ) ) {
V_2 = F_53 ( V_1 -> V_76 ) ;
F_10 ( V_8 , L_63 , V_2 ) ;
goto V_100;
}
if ( V_1 -> V_5 . V_89 ) {
V_2 = F_54 ( V_1 -> V_5 . V_89 ,
V_101 | V_102 ,
L_64 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_65 , V_2 ) ;
goto V_100;
}
}
V_2 = F_55 ( V_1 -> V_97 ,
V_1 -> V_95 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_66 ,
V_2 ) ;
goto V_100;
}
V_2 = F_24 ( V_1 -> V_76 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_44 , V_2 ) ;
goto V_103;
}
if ( V_1 -> V_5 . V_89 ) {
F_56 ( V_1 -> V_5 . V_89 , 1 ) ;
F_16 ( 1 ) ;
}
F_25 ( V_1 -> V_10 , false ) ;
V_2 = F_12 ( V_1 -> V_10 , V_104 , & V_51 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_67 , V_2 ) ;
goto V_105;
}
switch ( V_51 ) {
case 0x5102 :
case 0x5110 :
case 0x8997 :
break;
default:
F_10 ( V_1 -> V_8 , L_68 , V_51 ) ;
goto V_105;
}
if ( ! V_1 -> V_5 . V_89 ) {
F_30 ( V_1 -> V_10 ) ;
V_2 = F_18 ( V_1 -> V_10 , V_104 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_69 , V_2 ) ;
goto V_105;
}
F_16 ( 1 ) ;
V_2 = F_27 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_70 , V_2 ) ;
goto V_105;
}
}
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_12 ( V_1 -> V_10 , 0x19 , & V_16 ) ;
if ( V_2 != 0 )
F_10 ( V_8 ,
L_71 ,
V_2 ) ;
else if ( V_16 & 0x01 )
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_72 , V_2 ) ;
goto V_105;
}
break;
}
V_2 = F_12 ( V_1 -> V_10 , V_104 , & V_51 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_67 , V_2 ) ;
goto V_105;
}
V_2 = F_12 ( V_1 -> V_10 , V_106 ,
& V_1 -> V_107 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_73 , V_2 ) ;
goto V_105;
}
V_1 -> V_107 &= V_108 ;
switch ( V_51 ) {
#ifdef F_57
case 0x5102 :
V_91 = L_74 ;
if ( V_1 -> type != V_77 ) {
F_10 ( V_1 -> V_8 , L_75 ,
V_1 -> type ) ;
V_1 -> type = V_77 ;
}
F_45 = F_26 ;
V_1 -> V_107 &= 0x7 ;
break;
#endif
#ifdef F_58
case 0x5110 :
V_91 = L_76 ;
if ( V_1 -> type != V_92 ) {
F_10 ( V_1 -> V_8 , L_77 ,
V_1 -> type ) ;
V_1 -> type = V_92 ;
}
F_45 = V_109 ;
break;
#endif
#ifdef F_59
case 0x8997 :
V_91 = L_78 ;
if ( V_1 -> type != V_93 ) {
F_10 ( V_1 -> V_8 , L_79 ,
V_1 -> type ) ;
V_1 -> type = V_93 ;
}
F_45 = V_110 ;
break;
#endif
default:
F_10 ( V_1 -> V_8 , L_80 , V_51 ) ;
goto V_105;
}
F_60 ( V_8 , L_81 , V_91 , V_1 -> V_107 + 'A' ) ;
if ( F_45 ) {
V_2 = F_45 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_46 ,
V_2 ) ;
goto V_105;
}
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_20 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_47 ,
V_2 ) ;
goto V_105;
}
break;
default:
break;
}
}
for ( V_54 = 0 ; V_54 < F_43 ( V_1 -> V_5 . V_90 ) ; V_54 ++ ) {
if ( ! V_1 -> V_5 . V_90 [ V_54 ] )
continue;
F_18 ( V_1 -> V_10 , V_111 + V_54 ,
V_1 -> V_5 . V_90 [ V_54 ] ) ;
}
F_61 ( V_1 -> V_8 , 100 ) ;
F_62 ( V_1 -> V_8 ) ;
F_63 ( V_1 -> V_8 ) ;
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_112 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_112 :
F_4 ( V_1 -> V_10 , V_11 ,
V_113 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_114 :
F_4 ( V_1 -> V_10 , V_11 ,
V_113 , 2 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_82 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_98 ;
goto V_105;
}
for ( V_54 = 0 ; V_54 < V_115 ; V_54 ++ ) {
if ( ! V_1 -> V_5 . V_116 [ V_54 ] . V_117 &&
! V_1 -> V_5 . V_116 [ V_54 ] . V_118 )
continue;
if ( ! V_1 -> V_5 . V_116 [ V_54 ] . V_117 )
V_1 -> V_5 . V_116 [ V_54 ] . V_117 = 2800 ;
V_16 = ( V_1 -> V_5 . V_116 [ V_54 ] . V_117 - 1500 ) / 100 ;
V_16 <<= V_119 ;
if ( V_1 -> V_5 . V_116 [ V_54 ] . V_120 )
V_16 |= V_121 ;
if ( V_1 -> V_5 . V_116 [ V_54 ] . V_122 )
V_16 |= V_123 ;
if ( V_1 -> V_5 . V_116 [ V_54 ] . V_124 )
V_16 |= V_125 ;
if ( V_1 -> V_5 . V_116 [ V_54 ] . V_118 )
V_16 |= V_126 ;
F_4 ( V_1 -> V_10 ,
V_127 + V_54 ,
V_128 |
V_123 |
V_126 |
V_125 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_129 ; V_54 ++ ) {
V_16 = V_1 -> V_5 . V_130 [ V_54 ]
<< V_131 ;
V_16 |= V_1 -> V_5 . V_132 [ V_54 ] << V_133 ;
F_4 ( V_1 -> V_10 ,
V_134 + ( V_54 * 8 ) ,
V_135 |
V_136 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_137 ; V_54 ++ ) {
if ( V_1 -> V_5 . V_138 [ V_54 ] )
V_16 = V_139 ;
else
V_16 = 0 ;
F_4 ( V_1 -> V_10 ,
V_140 + ( V_54 * 8 ) ,
V_139 , V_16 ) ;
}
for ( V_54 = 0 ; V_54 < V_141 ; V_54 ++ ) {
if ( V_1 -> V_5 . V_142 [ V_54 ] )
F_4 ( V_1 -> V_10 ,
V_143 + ( V_54 * 2 ) ,
V_144 |
V_145 ,
V_1 -> V_5 . V_142 [ V_54 ] ) ;
if ( V_1 -> V_5 . V_146 [ V_54 ] )
F_4 ( V_1 -> V_10 ,
V_147 + ( V_54 * 2 ) ,
V_148 ,
V_1 -> V_5 . V_146 [ V_54 ] ) ;
}
V_2 = F_64 ( V_1 ) ;
if ( V_2 != 0 )
goto V_105;
F_65 ( V_1 , V_149 , L_83 ,
F_9 , V_1 ) ;
F_65 ( V_1 , V_150 , L_84 ,
F_13 , V_1 ) ;
F_65 ( V_1 , V_151 , L_85 ,
F_11 , V_1 ) ;
switch ( V_1 -> type ) {
case V_77 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_152 ,
F_43 ( V_152 ) , NULL , 0 , NULL ) ;
break;
case V_92 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_153 ,
F_43 ( V_153 ) , NULL , 0 , NULL ) ;
break;
case V_93 :
V_2 = F_49 ( V_1 -> V_8 , - 1 , V_154 ,
F_43 ( V_154 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_86 , V_2 ) ;
goto V_155;
}
#ifdef F_66
F_28 ( V_1 -> V_76 ) ;
#endif
return 0 ;
V_155:
F_67 ( V_1 ) ;
V_105:
if ( V_1 -> V_5 . V_89 ) {
F_56 ( V_1 -> V_5 . V_89 , 0 ) ;
F_68 ( V_1 -> V_5 . V_89 ) ;
}
F_28 ( V_1 -> V_76 ) ;
V_103:
F_69 ( V_1 -> V_97 ,
V_1 -> V_95 ) ;
V_100:
F_70 ( V_8 ) ;
return V_2 ;
}
int F_71 ( struct V_1 * V_1 )
{
F_70 ( V_1 -> V_8 ) ;
F_72 ( V_1 , V_151 , V_1 ) ;
F_72 ( V_1 , V_150 , V_1 ) ;
F_72 ( V_1 , V_149 , V_1 ) ;
F_73 ( V_1 -> V_8 ) ;
F_67 ( V_1 ) ;
if ( V_1 -> V_5 . V_89 )
F_56 ( V_1 -> V_5 . V_89 , 0 ) ;
F_28 ( V_1 -> V_76 ) ;
F_69 ( F_43 ( V_1 -> V_95 ) ,
V_1 -> V_95 ) ;
return 0 ;
}
