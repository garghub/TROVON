static inline T_1 F_1 ( const T_2 * V_1 )
{
return ( V_2 ) ( ( V_1 [ 0 ] | V_1 [ 1 ] << 8 | V_1 [ 2 ] << 16 ) << 8 ) >> 8 ;
}
static int F_2 ( struct V_3 * V_4 ,
T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
int V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 , V_5 , & V_9 ) ;
if ( V_8 < 0 )
goto V_16;
V_9 = ( ( V_9 & ( ~ V_6 ) ) | ( ( V_7 << F_4 ( V_6 ) ) & V_6 ) ) ;
V_8 = V_11 -> V_12 -> V_17 ( & V_11 -> V_14 , V_11 -> V_15 , V_5 , V_9 ) ;
V_16:
return V_8 ;
}
static int F_5 ( struct V_18 * V_19 ,
unsigned int V_20 , struct V_21 * V_22 )
{
int V_23 , V_24 = - V_25 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_19 -> V_20 . V_27 [ V_23 ] . V_28 == 0 )
goto V_29;
if ( V_19 -> V_20 . V_27 [ V_23 ] . V_28 == V_20 ) {
V_22 -> V_28 = V_19 -> V_20 . V_27 [ V_23 ] . V_28 ;
V_22 -> V_30 = V_19 -> V_20 . V_27 [ V_23 ] . V_30 ;
V_24 = 0 ;
break;
}
}
V_29:
return V_24 ;
}
int F_6 ( struct V_3 * V_4 , unsigned int V_20 )
{
int V_8 ;
struct V_21 V_22 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = F_5 ( V_11 -> V_19 , V_20 , & V_22 ) ;
if ( V_8 < 0 )
goto V_29;
if ( ( V_11 -> V_19 -> V_20 . V_31 == V_11 -> V_19 -> V_32 . V_31 ) &&
( V_11 -> V_19 -> V_20 . V_6 == V_11 -> V_19 -> V_32 . V_6 ) ) {
if ( V_11 -> V_33 == true ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_20 . V_31 ,
V_11 -> V_19 -> V_20 . V_6 ,
V_22 . V_30 ) ;
} else {
V_8 = 0 ;
}
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_20 . V_31 , V_11 -> V_19 -> V_20 . V_6 ,
V_22 . V_30 ) ;
}
if ( V_8 >= 0 )
V_11 -> V_20 = V_22 . V_28 ;
V_29:
return V_8 ;
}
static int F_7 ( struct V_18 * V_19 ,
unsigned int V_34 , int * V_35 )
{
int V_23 , V_24 = - V_25 ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( V_19 -> V_34 . V_37 [ V_23 ] . V_38 == 0 )
goto V_29;
if ( V_19 -> V_34 . V_37 [ V_23 ] . V_38 == V_34 ) {
* V_35 = V_23 ;
V_24 = 0 ;
break;
}
}
V_29:
return V_24 ;
}
static int F_8 ( struct V_3 * V_4 ,
unsigned int V_34 )
{
int V_8 , V_23 = 0 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = F_7 ( V_11 -> V_19 , V_34 , & V_23 ) ;
if ( V_8 < 0 )
goto V_39;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_34 . V_31 ,
V_11 -> V_19 -> V_34 . V_6 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_30 ) ;
if ( V_8 < 0 )
goto V_39;
V_11 -> V_40 = (struct V_41 * )
& V_11 -> V_19 -> V_34 . V_37 [ V_23 ] ;
return V_8 ;
V_39:
F_9 ( & V_4 -> V_15 , L_1 ) ;
return V_8 ;
}
int F_10 ( struct V_3 * V_4 , bool V_42 )
{
T_2 V_43 ;
int V_8 = - V_25 ;
bool V_44 = false ;
struct V_21 V_22 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_42 ) {
V_43 = V_11 -> V_19 -> V_32 . V_45 ;
if ( ( V_11 -> V_19 -> V_20 . V_31 == V_11 -> V_19 -> V_32 . V_31 ) &&
( V_11 -> V_19 -> V_20 . V_6 == V_11 -> V_19 -> V_32 . V_6 ) ) {
V_8 = F_5 ( V_11 -> V_19 ,
V_11 -> V_20 , & V_22 ) ;
if ( V_8 < 0 )
goto V_46;
V_43 = V_22 . V_30 ;
V_44 = true ;
}
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_32 . V_31 ,
V_11 -> V_19 -> V_32 . V_6 , V_43 ) ;
if ( V_8 < 0 )
goto V_46;
V_11 -> V_33 = true ;
if ( V_44 )
V_11 -> V_20 = V_22 . V_28 ;
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_32 . V_31 ,
V_11 -> V_19 -> V_32 . V_6 ,
V_11 -> V_19 -> V_32 . V_47 ) ;
if ( V_8 < 0 )
goto V_46;
V_11 -> V_33 = false ;
}
V_46:
return V_8 ;
}
int F_11 ( struct V_3 * V_4 , T_2 V_48 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
return F_2 ( V_4 ,
V_11 -> V_19 -> V_49 . V_31 ,
V_11 -> V_19 -> V_49 . V_6 , V_48 ) ;
}
int F_12 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_13 ( & V_11 -> V_14 . V_52 ) ;
switch ( V_51 -> V_53 ) {
case 1 :
if ( V_11 -> V_19 -> V_54 . V_55 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_2 ) ;
V_8 = - V_25 ;
goto V_56;
}
V_11 -> V_53 = 1 ;
break;
case 2 :
if ( V_11 -> V_19 -> V_54 . V_57 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_3 ) ;
V_8 = - V_25 ;
goto V_56;
}
V_11 -> V_53 = 2 ;
break;
default:
F_9 ( & V_4 -> V_15 , L_4 ) ;
V_8 = - V_25 ;
goto V_56;
}
V_8 = F_10 ( V_4 , false ) ;
if ( V_8 < 0 )
goto V_56;
V_8 = F_8 ( V_4 ,
V_11 -> V_40 -> V_38 ) ;
if ( V_8 < 0 )
goto V_56;
V_8 = F_6 ( V_4 , V_11 -> V_20 ) ;
if ( V_8 < 0 )
goto V_56;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_58 . V_31 , V_11 -> V_19 -> V_58 . V_6 , true ) ;
if ( V_8 < 0 )
goto V_56;
V_8 = F_11 ( V_4 , V_59 ) ;
V_56:
return V_8 ;
}
int F_14 ( struct V_3 * V_4 , bool V_42 )
{
int V_8 ;
T_2 V_60 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_11 -> V_19 -> V_54 . V_61 . V_62 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_54 . V_61 . V_62 ,
V_11 -> V_19 -> V_54 . V_61 . V_63 , ( int ) V_42 ) ;
if ( V_8 < 0 )
goto V_64;
}
if ( V_11 -> V_53 == 1 )
V_60 = V_11 -> V_19 -> V_54 . V_55 ;
else
V_60 = V_11 -> V_19 -> V_54 . V_57 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_54 . V_31 , V_60 , ( int ) V_42 ) ;
V_64:
return V_8 ;
}
int F_15 ( struct V_3 * V_4 , int V_65 )
{
int V_8 = - V_25 , V_23 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_66 == V_65 ) &&
( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_66 != 0 ) ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
goto V_67;
V_8 = F_8 ( V_4 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 ) ;
V_67:
return V_8 ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_68 const * V_69 , int * V_7 )
{
int V_8 ;
T_2 * V_70 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_71 = V_69 -> V_72 . V_73 >> 3 ;
V_70 = F_17 ( V_71 , V_74 ) ;
if ( ! V_70 ) {
V_8 = - V_25 ;
goto V_75;
}
V_8 = V_11 -> V_12 -> V_76 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_69 -> V_77 , V_71 ,
V_70 , V_11 -> V_78 ) ;
if ( V_8 < 0 )
goto V_79;
if ( V_71 == 2 )
* V_7 = ( V_80 ) F_18 ( V_70 ) ;
else if ( V_71 == 3 )
* V_7 = ( V_2 ) F_1 ( V_70 ) ;
V_79:
F_19 ( V_70 ) ;
V_75:
return V_8 ;
}
int F_20 ( struct V_3 * V_4 ,
struct V_68 const * V_69 , int * V_81 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_21 ( & V_4 -> V_82 ) ;
if ( V_4 -> V_83 == V_84 ) {
V_8 = - V_85 ;
goto V_86;
} else {
V_8 = F_10 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_86;
F_22 ( ( V_11 -> V_19 -> V_87 * 1000 ) / V_11 -> V_20 ) ;
V_8 = F_16 ( V_4 , V_69 , V_81 ) ;
if ( V_8 < 0 )
goto V_86;
* V_81 = * V_81 >> V_69 -> V_72 . V_88 ;
V_8 = F_10 ( V_4 , false ) ;
}
F_23 ( & V_4 -> V_82 ) ;
return V_8 ;
V_86:
F_23 ( & V_4 -> V_82 ) ;
return V_8 ;
}
int F_24 ( struct V_3 * V_4 ,
int V_89 , const struct V_18 * V_90 )
{
T_2 V_91 ;
int V_23 , V_92 , V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_93 , & V_91 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_4 -> V_15 , L_5 ) ;
goto V_94;
}
for ( V_23 = 0 ; V_23 < V_89 ; V_23 ++ ) {
if ( V_90 [ V_23 ] . V_91 == V_91 )
break;
}
if ( V_23 == V_89 )
goto V_95;
for ( V_92 = 0 ; V_92 < F_25 ( V_90 [ V_23 ] . V_96 ) ; V_92 ++ ) {
if ( strcmp ( V_4 -> V_97 ,
& V_90 [ V_23 ] . V_96 [ V_92 ] [ 0 ] ) == 0 )
break;
}
if ( V_92 == F_25 ( V_90 [ V_23 ] . V_96 ) ) {
F_9 ( & V_4 -> V_15 , L_6 ) ;
goto V_98;
}
V_11 -> V_19 = (struct V_18 * ) & V_90 [ V_23 ] ;
return V_23 ;
V_95:
F_9 ( & V_4 -> V_15 , L_7 , V_91 ) ;
V_98:
V_8 = - V_99 ;
V_94:
return V_8 ;
}
T_3 F_26 ( struct V_100 * V_15 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_10 * V_104 = F_3 ( F_27 ( V_15 ) ) ;
return sprintf ( V_103 , L_8 , V_104 -> V_20 ) ;
}
T_3 F_28 ( struct V_100 * V_15 ,
struct V_101 * V_102 , const char * V_103 , T_4 V_105 )
{
int V_8 ;
unsigned int V_20 ;
struct V_3 * V_4 = F_27 ( V_15 ) ;
V_8 = F_29 ( V_103 , 10 , & V_20 ) ;
if ( V_8 < 0 )
goto V_106;
F_21 ( & V_4 -> V_82 ) ;
V_8 = F_6 ( V_4 , V_20 ) ;
F_23 ( & V_4 -> V_82 ) ;
V_106:
return V_8 < 0 ? V_8 : V_105 ;
}
T_3 F_30 ( struct V_100 * V_15 ,
struct V_101 * V_102 , char * V_103 )
{
int V_23 , V_107 = 0 ;
struct V_3 * V_4 = F_27 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_21 ( & V_4 -> V_82 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 == 0 )
break;
V_107 += F_31 ( V_103 + V_107 , V_108 - V_107 , L_9 ,
V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 ) ;
}
F_23 ( & V_4 -> V_82 ) ;
V_103 [ V_107 - 1 ] = '\n' ;
return V_107 ;
}
T_3 F_32 ( struct V_100 * V_15 ,
struct V_101 * V_102 , char * V_103 )
{
int V_23 , V_107 = 0 ;
struct V_3 * V_4 = F_27 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_21 ( & V_4 -> V_82 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 == 0 )
break;
V_107 += F_31 ( V_103 + V_107 , V_108 - V_107 , L_10 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_66 ) ;
}
F_23 ( & V_4 -> V_82 ) ;
V_103 [ V_107 - 1 ] = '\n' ;
return V_107 ;
}
