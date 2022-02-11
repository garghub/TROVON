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
static int F_12 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
switch ( V_51 -> V_52 ) {
case 1 :
if ( V_11 -> V_19 -> V_53 . V_54 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_2 ) ;
return - V_25 ;
}
V_11 -> V_52 = 1 ;
break;
case 2 :
if ( V_11 -> V_19 -> V_53 . V_55 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_3 ) ;
return - V_25 ;
}
V_11 -> V_52 = 2 ;
break;
default:
F_9 ( & V_4 -> V_15 , L_4 ) ;
return - V_25 ;
}
return 0 ;
}
int F_13 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
int V_8 = 0 ;
F_14 ( & V_11 -> V_14 . V_56 ) ;
if ( V_51 )
V_8 = F_12 ( V_4 , V_51 ) ;
V_8 = F_10 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_40 ) {
V_8 = F_8 ( V_4 ,
V_11 -> V_40 -> V_38 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
F_15 ( & V_4 -> V_15 , L_5 ) ;
V_8 = F_6 ( V_4 , V_11 -> V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_57 . V_31 , V_11 -> V_19 -> V_57 . V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_11 ( V_4 , V_58 ) ;
return V_8 ;
}
int F_16 ( struct V_3 * V_4 , bool V_42 )
{
int V_8 ;
T_2 V_59 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( ! V_11 -> V_19 -> V_53 . V_31 )
return 0 ;
if ( V_11 -> V_19 -> V_53 . V_60 . V_61 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_53 . V_60 . V_61 ,
V_11 -> V_19 -> V_53 . V_60 . V_62 , ( int ) V_42 ) ;
if ( V_8 < 0 )
goto V_63;
}
if ( V_11 -> V_52 == 1 )
V_59 = V_11 -> V_19 -> V_53 . V_54 ;
else
V_59 = V_11 -> V_19 -> V_53 . V_55 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_53 . V_31 , V_59 , ( int ) V_42 ) ;
V_63:
return V_8 ;
}
int F_17 ( struct V_3 * V_4 , int V_64 )
{
int V_8 = - V_25 , V_23 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_65 == V_64 ) &&
( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_65 != 0 ) ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
goto V_66;
V_8 = F_8 ( V_4 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 ) ;
V_66:
return V_8 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_67 const * V_68 , int * V_7 )
{
int V_8 ;
T_2 * V_69 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_70 = V_68 -> V_71 . V_72 >> 3 ;
V_69 = F_19 ( V_70 , V_73 ) ;
if ( ! V_69 )
return - V_74 ;
V_8 = V_11 -> V_12 -> V_75 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_68 -> V_76 , V_70 ,
V_69 , V_11 -> V_77 ) ;
if ( V_8 < 0 )
goto V_78;
if ( V_70 == 2 )
* V_7 = ( V_79 ) F_20 ( V_69 ) ;
else if ( V_70 == 3 )
* V_7 = ( V_2 ) F_1 ( V_69 ) ;
V_78:
F_21 ( V_69 ) ;
return V_8 ;
}
int F_22 ( struct V_3 * V_4 ,
struct V_67 const * V_68 , int * V_80 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_23 ( & V_4 -> V_81 ) ;
if ( V_4 -> V_82 == V_83 ) {
V_8 = - V_84 ;
goto V_85;
} else {
V_8 = F_10 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_85;
F_24 ( ( V_11 -> V_19 -> V_86 * 1000 ) / V_11 -> V_20 ) ;
V_8 = F_18 ( V_4 , V_68 , V_80 ) ;
if ( V_8 < 0 )
goto V_85;
* V_80 = * V_80 >> V_68 -> V_71 . V_87 ;
V_8 = F_10 ( V_4 , false ) ;
}
V_85:
F_25 ( & V_4 -> V_81 ) ;
return V_8 ;
}
int F_26 ( struct V_3 * V_4 ,
int V_88 , const struct V_18 * V_89 )
{
T_2 V_90 ;
int V_23 , V_91 , V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_92 , & V_90 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_4 -> V_15 , L_6 ) ;
goto V_93;
}
for ( V_23 = 0 ; V_23 < V_88 ; V_23 ++ ) {
if ( V_89 [ V_23 ] . V_90 == V_90 )
break;
}
if ( V_23 == V_88 )
goto V_94;
for ( V_91 = 0 ; V_91 < F_27 ( V_89 [ V_23 ] . V_95 ) ; V_91 ++ ) {
if ( strcmp ( V_4 -> V_96 ,
& V_89 [ V_23 ] . V_95 [ V_91 ] [ 0 ] ) == 0 )
break;
}
if ( V_91 == F_27 ( V_89 [ V_23 ] . V_95 ) ) {
F_9 ( & V_4 -> V_15 , L_7 ) ;
goto V_97;
}
V_11 -> V_19 = (struct V_18 * ) & V_89 [ V_23 ] ;
return V_23 ;
V_94:
F_9 ( & V_4 -> V_15 , L_8 , V_90 ) ;
V_97:
V_8 = - V_98 ;
V_93:
return V_8 ;
}
T_3 F_28 ( struct V_99 * V_15 ,
struct V_100 * V_101 , char * V_102 )
{
struct V_10 * V_103 = F_3 ( F_29 ( V_15 ) ) ;
return sprintf ( V_102 , L_9 , V_103 -> V_20 ) ;
}
T_3 F_30 ( struct V_99 * V_15 ,
struct V_100 * V_101 , const char * V_102 , T_4 V_104 )
{
int V_8 ;
unsigned int V_20 ;
struct V_3 * V_4 = F_29 ( V_15 ) ;
V_8 = F_31 ( V_102 , 10 , & V_20 ) ;
if ( V_8 < 0 )
goto V_105;
F_23 ( & V_4 -> V_81 ) ;
V_8 = F_6 ( V_4 , V_20 ) ;
F_25 ( & V_4 -> V_81 ) ;
V_105:
return V_8 < 0 ? V_8 : V_104 ;
}
T_3 F_32 ( struct V_99 * V_15 ,
struct V_100 * V_101 , char * V_102 )
{
int V_23 , V_106 = 0 ;
struct V_3 * V_4 = F_29 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_23 ( & V_4 -> V_81 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 == 0 )
break;
V_106 += F_33 ( V_102 + V_106 , V_107 - V_106 , L_10 ,
V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 ) ;
}
F_25 ( & V_4 -> V_81 ) ;
V_102 [ V_106 - 1 ] = '\n' ;
return V_106 ;
}
T_3 F_34 ( struct V_99 * V_15 ,
struct V_100 * V_101 , char * V_102 )
{
int V_23 , V_106 = 0 ;
struct V_3 * V_4 = F_29 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_23 ( & V_4 -> V_81 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 == 0 )
break;
V_106 += F_33 ( V_102 + V_106 , V_107 - V_106 , L_11 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_65 ) ;
}
F_25 ( & V_4 -> V_81 ) ;
V_102 [ V_106 - 1 ] = '\n' ;
return V_106 ;
}
