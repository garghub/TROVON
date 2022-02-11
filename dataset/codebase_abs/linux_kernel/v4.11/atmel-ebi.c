static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
unsigned int V_9 = V_10 / F_2 ( V_2 -> V_7 -> V_11 ) ;
struct V_12 * V_13 = & V_4 -> V_8 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
unsigned int V_16 ;
F_3 ( V_6 -> V_17 , V_4 -> V_18 , & V_16 ) ;
V_13 -> V_17 = V_16 & ~ V_19 ;
V_16 = ( V_16 & V_19 ) >> 16 ;
V_15 -> V_20 = V_9 * V_16 ;
F_3 ( V_6 -> V_21 , V_4 -> V_18 , & V_16 ) ;
V_15 -> V_22 = ( V_16 >> 24 ) & 0x1f ;
V_15 -> V_22 += ( ( V_16 >> 29 ) & 0x1 ) * 128 ;
V_15 -> V_22 *= V_9 ;
V_15 -> V_23 = ( V_16 >> 16 ) & 0x1f ;
V_15 -> V_23 += ( ( V_16 >> 21 ) & 0x1 ) * 128 ;
V_15 -> V_23 *= V_9 ;
V_15 -> V_24 = ( V_16 >> 8 ) & 0x1f ;
V_15 -> V_24 += ( ( V_16 >> 13 ) & 0x1 ) * 128 ;
V_15 -> V_24 *= V_9 ;
V_15 -> V_25 = V_16 & 0x1f ;
V_15 -> V_25 += ( ( V_16 >> 5 ) & 0x1 ) * 128 ;
V_15 -> V_25 *= V_9 ;
F_3 ( V_6 -> V_26 , V_4 -> V_18 , & V_16 ) ;
V_15 -> V_27 = ( V_16 >> 24 ) & 0x3f ;
V_15 -> V_27 += ( ( V_16 >> 30 ) & 0x1 ) * 256 ;
V_15 -> V_27 *= V_9 ;
V_15 -> V_28 = ( V_16 >> 16 ) & 0x3f ;
V_15 -> V_28 += ( ( V_16 >> 22 ) & 0x1 ) * 256 ;
V_15 -> V_28 *= V_9 ;
V_15 -> V_29 = ( V_16 >> 8 ) & 0x3f ;
V_15 -> V_29 += ( ( V_16 >> 14 ) & 0x1 ) * 256 ;
V_15 -> V_29 *= V_9 ;
V_15 -> V_30 = V_16 & 0x3f ;
V_15 -> V_30 += ( ( V_16 >> 6 ) & 0x1 ) * 256 ;
V_15 -> V_30 *= V_9 ;
F_3 ( V_6 -> V_31 , V_4 -> V_18 , & V_16 ) ;
V_15 -> V_32 = ( V_16 >> 16 ) & 0x7f ;
V_15 -> V_32 += ( ( V_16 >> 23 ) & 0x3 ) * 256 ;
V_15 -> V_32 *= V_9 ;
V_15 -> V_33 = V_16 & 0x7f ;
V_15 -> V_33 += ( ( V_16 >> 7 ) & 0x3 ) * 256 ;
V_15 -> V_33 *= V_9 ;
}
static int F_4 ( struct V_34 * V_35 , const char * V_36 ,
T_1 * V_16 , bool * V_37 )
{
if ( ! F_5 ( V_35 , V_36 , V_16 ) ) {
* V_37 = true ;
return 0 ;
}
if ( * V_37 )
return - V_38 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_14 * V_15 ,
bool * V_37 )
{
int V_39 ;
V_39 = F_4 ( V_35 , L_1 ,
& V_15 -> V_22 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_2 ,
& V_15 -> V_23 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_3 ,
& V_15 -> V_24 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_4 ,
& V_15 -> V_25 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_5 ,
& V_15 -> V_27 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_6 ,
& V_15 -> V_28 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_7 ,
& V_15 -> V_29 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_8 ,
& V_15 -> V_30 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_9 ,
& V_15 -> V_33 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_10 ,
& V_15 -> V_32 , V_37 ) ;
if ( V_39 )
goto V_40;
V_39 = F_4 ( V_35 , L_11 ,
& V_15 -> V_20 , V_37 ) ;
V_40:
if ( V_39 )
F_7 ( V_2 -> V_7 -> V_41 ,
L_12 ,
V_35 -> V_42 ) ;
return V_39 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = & V_4 -> V_8 ;
bool V_37 = false ;
const char * V_43 ;
T_1 V_44 ;
int V_39 ;
V_39 = F_5 ( V_35 , L_13 , & V_44 ) ;
if ( ! V_39 ) {
switch ( V_44 ) {
case 8 :
V_13 -> V_17 |= V_45 ;
break;
case 16 :
V_13 -> V_17 |= V_46 ;
break;
case 32 :
V_13 -> V_17 |= V_47 ;
break;
default:
return - V_38 ;
}
V_37 = true ;
}
if ( F_9 ( V_35 , L_14 ) ) {
V_13 -> V_17 |= V_48 ;
V_37 = true ;
}
V_43 = NULL ;
F_10 ( V_35 , L_15 , & V_43 ) ;
if ( V_43 && ! strcmp ( V_43 , L_16 ) ) {
V_13 -> V_17 |= V_49 ;
V_37 = true ;
}
V_43 = NULL ;
F_10 ( V_35 , L_17 , & V_43 ) ;
if ( V_43 && ! strcmp ( V_43 , L_18 ) ) {
V_13 -> V_17 |= V_50 ;
V_37 = true ;
}
V_43 = NULL ;
F_10 ( V_35 , L_19 , & V_43 ) ;
if ( V_43 && ! strcmp ( V_43 , L_20 ) ) {
V_13 -> V_17 |= V_51 ;
V_37 = true ;
}
V_43 = NULL ;
F_10 ( V_35 , L_21 , & V_43 ) ;
if ( V_43 ) {
if ( ! strcmp ( V_43 , L_22 ) )
V_13 -> V_17 |= V_52 ;
else if ( ! strcmp ( V_43 , L_23 ) )
V_13 -> V_17 |= V_53 ;
else if ( strcmp ( V_43 , L_24 ) )
return - V_38 ;
V_37 = true ;
}
V_39 = F_5 ( V_35 , L_25 , & V_44 ) ;
if ( ! V_39 ) {
switch ( V_44 ) {
case 4 :
V_13 -> V_17 |= V_54 ;
break;
case 8 :
V_13 -> V_17 |= V_55 ;
break;
case 16 :
V_13 -> V_17 |= V_56 ;
break;
case 32 :
V_13 -> V_17 |= V_57 ;
break;
default:
return - V_38 ;
}
V_13 -> V_17 |= V_58 ;
V_37 = true ;
}
V_39 = F_6 ( V_2 , V_35 , & V_13 -> V_15 ,
& V_37 ) ;
if ( V_39 )
return V_39 ;
return V_37 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_59 = F_2 ( V_2 -> V_7 -> V_11 ) ;
unsigned int V_9 = V_10 / V_59 ;
struct V_12 * V_13 = & V_4 -> V_8 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_60 ;
T_1 V_16 ;
V_60 = F_12 ( V_59 ,
V_15 -> V_22 ) ;
V_16 = F_13 ( V_60 ) ;
V_60 = F_12 ( V_59 ,
V_15 -> V_23 ) ;
V_16 |= F_14 ( V_60 ) ;
V_60 = F_12 ( V_59 ,
V_15 -> V_24 ) ;
V_16 |= F_15 ( V_60 ) ;
V_60 = F_12 ( V_59 ,
V_15 -> V_25 ) ;
V_16 |= F_16 ( V_60 ) ;
F_17 ( V_6 -> V_21 , V_4 -> V_18 , V_16 ) ;
V_60 = F_18 ( V_59 ,
V_15 -> V_27 ) ;
V_16 = F_19 ( V_60 ) ;
V_60 = F_18 ( V_59 ,
V_15 -> V_28 ) ;
V_16 |= F_20 ( V_60 ) ;
V_60 = F_18 ( V_59 ,
V_15 -> V_29 ) ;
V_16 |= F_21 ( V_60 ) ;
V_60 = F_18 ( V_59 ,
V_15 -> V_30 ) ;
V_16 |= F_22 ( V_60 ) ;
F_17 ( V_6 -> V_26 , V_4 -> V_18 , V_16 ) ;
V_60 = F_23 ( V_59 ,
V_15 -> V_32 ) ;
V_16 = F_24 ( V_60 ) ;
V_60 = F_23 ( V_59 ,
V_15 -> V_33 ) ;
V_16 |= F_25 ( V_60 ) ;
F_17 ( V_6 -> V_31 , V_4 -> V_18 , V_16 ) ;
V_16 = F_26 ( V_15 -> V_20 , V_9 ) ;
if ( V_16 > V_61 )
V_16 = V_61 ;
F_17 ( V_6 -> V_17 , V_4 -> V_18 ,
V_13 -> V_17 | F_27 ( V_16 ) ) ;
return 0 ;
}
static int F_28 ( struct V_62 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_8 ;
struct V_63 V_64 = F_29 ( 0 , 0 , 31 ) ;
V_64 . V_65 = F_30 ( V_7 -> V_66 -> V_67 ) ;
V_64 . V_68 = V_69 ;
V_64 . V_70 = F_31 ( V_71 ) ;
V_6 -> V_21 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_21 ) )
return F_34 ( V_6 -> V_21 ) ;
V_64 . V_70 = F_35 ( V_71 ) ;
V_6 -> V_26 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_26 ) )
return F_34 ( V_6 -> V_26 ) ;
V_64 . V_70 = F_36 ( V_71 ) ;
V_6 -> V_31 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_31 ) )
return F_34 ( V_6 -> V_31 ) ;
V_64 . V_70 = F_37 ( V_71 ) ;
V_6 -> V_17 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
return F_38 ( V_6 -> V_17 ) ;
}
static int F_39 ( struct V_62 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_8 ;
struct V_63 V_64 = F_29 ( 0 , 0 , 31 ) ;
V_64 . V_65 = F_30 ( V_7 -> V_66 -> V_67 ) ;
V_64 . V_68 = V_74 ;
V_64 . V_70 = F_31 ( V_75 ) ;
V_6 -> V_21 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_21 ) )
return F_34 ( V_6 -> V_21 ) ;
V_64 . V_70 = F_35 ( V_75 ) ;
V_6 -> V_26 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_26 ) )
return F_34 ( V_6 -> V_26 ) ;
V_64 . V_70 = F_36 ( V_75 ) ;
V_6 -> V_31 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
if ( F_33 ( V_6 -> V_31 ) )
return F_34 ( V_6 -> V_31 ) ;
V_64 . V_70 = F_40 ( V_75 ) ;
V_6 -> V_17 = F_32 ( V_7 -> V_41 , V_7 -> V_72 . V_73 ,
V_64 ) ;
return F_38 ( V_6 -> V_17 ) ;
}
static int F_41 ( struct V_62 * V_7 , struct V_34 * V_35 ,
int V_76 )
{
const struct V_77 * V_66 = V_7 -> V_66 ;
struct V_3 V_4 = { } ;
struct V_78 * V_41 = V_7 -> V_41 ;
struct V_1 * V_2 ;
unsigned long V_79 = 0 ;
int V_39 , V_80 = 0 , V_81 , V_82 ;
bool V_83 = false ;
T_1 V_18 ;
V_81 = F_42 ( V_35 , L_26 ,
V_76 * sizeof( T_1 ) ) ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
V_39 = F_43 ( V_35 , L_26 , V_82 * V_76 ,
& V_18 ) ;
if ( V_39 )
return V_39 ;
if ( V_18 >= V_84 ||
! ( V_7 -> V_66 -> V_67 & F_44 ( V_18 ) ) ) {
F_7 ( V_41 , L_27 ,
V_35 -> V_42 ) ;
return - V_38 ;
}
if ( ! F_45 ( V_18 , & V_79 ) )
V_80 ++ ;
}
if ( ! V_80 ) {
F_7 ( V_41 , L_27 , V_35 -> V_42 ) ;
return - V_38 ;
}
V_2 = F_46 ( V_7 -> V_41 ,
sizeof( * V_2 ) + ( V_80 * sizeof( * V_2 -> V_85 ) ) ,
V_86 ) ;
if ( ! V_2 )
return - V_87 ;
V_2 -> V_7 = V_7 ;
V_39 = V_66 -> V_88 ( V_2 , V_35 , & V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
else if ( V_39 )
V_83 = true ;
V_82 = 0 ;
F_47 (cs, &cslines, AT91_MATRIX_EBI_NUM_CS) {
V_2 -> V_85 [ V_82 ] . V_18 = V_18 ;
if ( V_83 ) {
V_4 . V_18 = V_18 ;
V_39 = V_66 -> V_89 ( V_2 , & V_4 ) ;
if ( V_39 )
return V_39 ;
}
V_66 -> V_90 ( V_2 , & V_2 -> V_85 [ V_82 ] ) ;
if ( V_7 -> V_91 && V_83 )
F_48 ( V_7 -> V_91 ,
F_44 ( V_18 ) , 0 ) ;
V_82 ++ ;
}
F_49 ( & V_2 -> V_92 , & V_7 -> V_93 ) ;
return 0 ;
}
static int F_50 ( struct V_62 * V_7 , struct V_34 * V_35 )
{
struct V_78 * V_41 = V_7 -> V_41 ;
struct V_94 * V_95 ;
V_95 = F_46 ( V_41 , sizeof( * V_95 ) , V_86 ) ;
if ( ! V_95 )
return - V_87 ;
V_95 -> V_96 = F_51 ( V_41 , L_28 , V_86 ) ;
if ( ! V_95 -> V_96 )
return - V_87 ;
V_95 -> V_97 = F_51 ( V_41 , L_24 , V_86 ) ;
if ( ! V_95 -> V_97 )
return - V_87 ;
V_95 -> V_98 = sizeof( L_24 ) ;
return F_52 ( V_35 , V_95 ) ;
}
static int F_53 ( struct V_99 * V_100 )
{
struct V_78 * V_41 = & V_100 -> V_41 ;
struct V_34 * V_101 , * V_35 = V_41 -> V_102 , * V_103 ;
const struct V_104 * V_105 ;
struct V_62 * V_7 ;
int V_39 , V_76 ;
struct V_11 * V_11 ;
T_1 V_16 ;
V_105 = F_54 ( V_106 , V_41 ) ;
if ( ! V_105 || ! V_105 -> V_107 )
return - V_38 ;
V_7 = F_46 ( V_41 , sizeof( * V_7 ) , V_86 ) ;
if ( ! V_7 )
return - V_87 ;
F_55 ( & V_7 -> V_93 ) ;
V_7 -> V_66 = V_105 -> V_107 ;
V_7 -> V_41 = V_41 ;
V_11 = F_56 ( V_41 , NULL ) ;
if ( F_33 ( V_11 ) )
return F_34 ( V_11 ) ;
V_7 -> V_11 = V_11 ;
V_103 = F_57 ( V_41 -> V_102 , L_29 , 0 ) ;
V_7 -> V_72 . V_73 = F_58 ( V_103 ) ;
if ( F_33 ( V_7 -> V_72 . V_73 ) )
return F_34 ( V_7 -> V_72 . V_73 ) ;
V_7 -> V_72 . V_11 = F_59 ( V_103 , 0 ) ;
if ( F_33 ( V_7 -> V_72 . V_11 ) ) {
if ( F_34 ( V_7 -> V_72 . V_11 ) != - V_108 )
return F_34 ( V_7 -> V_72 . V_11 ) ;
V_7 -> V_72 . V_11 = NULL ;
}
V_39 = F_60 ( V_7 -> V_72 . V_11 ) ;
if ( V_39 )
return V_39 ;
if ( V_7 -> V_66 -> V_91 ) {
V_7 -> V_109 =
F_61 ( V_35 , L_30 ) ;
if ( F_33 ( V_7 -> V_109 ) )
return F_34 ( V_7 -> V_109 ) ;
V_7 -> V_91 = F_62 ( V_7 -> V_109 ,
* V_7 -> V_66 -> V_91 ) ;
if ( F_33 ( V_7 -> V_91 ) )
return F_34 ( V_7 -> V_91 ) ;
}
V_39 = V_7 -> V_66 -> V_110 ( V_7 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_35 , L_31 , & V_16 ) ;
if ( V_39 ) {
F_7 ( V_41 , L_32 ) ;
return V_39 ;
}
V_76 = V_16 ;
V_39 = F_5 ( V_35 , L_33 , & V_16 ) ;
if ( V_39 ) {
F_7 ( V_41 , L_32 ) ;
return V_39 ;
}
V_76 += V_16 ;
F_63 (np, child) {
if ( ! F_64 ( V_101 , L_26 , NULL ) )
continue;
V_39 = F_41 ( V_7 , V_101 , V_76 ) ;
if ( V_39 ) {
F_7 ( V_41 , L_34 ,
V_101 -> V_42 ) ;
V_39 = F_50 ( V_7 , V_101 ) ;
if ( V_39 )
return V_39 ;
}
}
return F_65 ( V_35 , NULL , NULL , V_41 ) ;
}
