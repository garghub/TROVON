static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
unsigned int V_9 = F_2 ( V_2 -> V_7 -> V_10 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
unsigned int V_15 ;
F_3 ( V_6 -> V_16 , V_4 -> V_17 , & V_15 ) ;
V_12 -> V_16 = V_15 & ~ V_18 ;
V_15 = ( V_15 & V_18 ) >> 16 ;
V_14 -> V_19 = V_9 * V_15 ;
F_3 ( V_6 -> V_20 , V_4 -> V_17 , & V_15 ) ;
V_14 -> V_21 = ( V_15 >> 24 ) & 0x1f ;
V_14 -> V_21 += ( ( V_15 >> 29 ) & 0x1 ) * 128 ;
V_14 -> V_21 *= V_9 ;
V_14 -> V_22 = ( V_15 >> 16 ) & 0x1f ;
V_14 -> V_22 += ( ( V_15 >> 21 ) & 0x1 ) * 128 ;
V_14 -> V_22 *= V_9 ;
V_14 -> V_23 = ( V_15 >> 8 ) & 0x1f ;
V_14 -> V_23 += ( ( V_15 >> 13 ) & 0x1 ) * 128 ;
V_14 -> V_23 *= V_9 ;
V_14 -> V_24 = V_15 & 0x1f ;
V_14 -> V_24 += ( ( V_15 >> 5 ) & 0x1 ) * 128 ;
V_14 -> V_24 *= V_9 ;
F_3 ( V_6 -> V_25 , V_4 -> V_17 , & V_15 ) ;
V_14 -> V_26 = ( V_15 >> 24 ) & 0x3f ;
V_14 -> V_26 += ( ( V_15 >> 30 ) & 0x1 ) * 256 ;
V_14 -> V_26 *= V_9 ;
V_14 -> V_27 = ( V_15 >> 16 ) & 0x3f ;
V_14 -> V_27 += ( ( V_15 >> 22 ) & 0x1 ) * 256 ;
V_14 -> V_27 *= V_9 ;
V_14 -> V_28 = ( V_15 >> 8 ) & 0x3f ;
V_14 -> V_28 += ( ( V_15 >> 14 ) & 0x1 ) * 256 ;
V_14 -> V_28 *= V_9 ;
V_14 -> V_29 = V_15 & 0x3f ;
V_14 -> V_29 += ( ( V_15 >> 6 ) & 0x1 ) * 256 ;
V_14 -> V_29 *= V_9 ;
F_3 ( V_6 -> V_30 , V_4 -> V_17 , & V_15 ) ;
V_14 -> V_31 = ( V_15 >> 16 ) & 0x7f ;
V_14 -> V_31 += ( ( V_15 >> 23 ) & 0x3 ) * 256 ;
V_14 -> V_31 *= V_9 ;
V_14 -> V_32 = V_15 & 0x7f ;
V_14 -> V_32 += ( ( V_15 >> 7 ) & 0x3 ) * 256 ;
V_14 -> V_32 *= V_9 ;
}
static int F_4 ( struct V_33 * V_34 , const char * V_35 ,
T_1 * V_15 , bool * V_36 )
{
if ( ! F_5 ( V_34 , V_35 , V_15 ) ) {
* V_36 = true ;
return 0 ;
}
if ( * V_36 )
return - V_37 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_13 * V_14 ,
bool * V_36 )
{
int V_38 ;
V_38 = F_4 ( V_34 , L_1 ,
& V_14 -> V_21 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_2 ,
& V_14 -> V_22 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_3 ,
& V_14 -> V_23 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_4 ,
& V_14 -> V_24 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_5 ,
& V_14 -> V_26 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_6 ,
& V_14 -> V_27 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_7 ,
& V_14 -> V_28 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_8 ,
& V_14 -> V_29 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_9 ,
& V_14 -> V_32 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_10 ,
& V_14 -> V_31 , V_36 ) ;
if ( V_38 )
goto V_39;
V_38 = F_4 ( V_34 , L_11 ,
& V_14 -> V_19 , V_36 ) ;
V_39:
if ( V_38 )
F_7 ( V_2 -> V_7 -> V_40 ,
L_12 ,
V_34 -> V_41 ) ;
return V_38 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_8 ;
bool V_36 = false ;
const char * V_42 ;
T_1 V_43 ;
int V_38 ;
V_38 = F_5 ( V_34 , L_13 , & V_43 ) ;
if ( ! V_38 ) {
switch ( V_43 ) {
case 8 :
V_12 -> V_16 |= V_44 ;
break;
case 16 :
V_12 -> V_16 |= V_45 ;
break;
case 32 :
V_12 -> V_16 |= V_46 ;
break;
default:
return - V_37 ;
}
V_36 = true ;
}
if ( F_9 ( V_34 , L_14 ) ) {
V_12 -> V_16 |= V_47 ;
V_36 = true ;
}
V_42 = NULL ;
F_10 ( V_34 , L_15 , & V_42 ) ;
if ( V_42 && ! strcmp ( V_42 , L_16 ) ) {
V_12 -> V_16 |= V_48 ;
V_36 = true ;
}
V_42 = NULL ;
F_10 ( V_34 , L_17 , & V_42 ) ;
if ( V_42 && ! strcmp ( V_42 , L_18 ) ) {
V_12 -> V_16 |= V_49 ;
V_36 = true ;
}
V_42 = NULL ;
F_10 ( V_34 , L_19 , & V_42 ) ;
if ( V_42 && ! strcmp ( V_42 , L_20 ) ) {
V_12 -> V_16 |= V_50 ;
V_36 = true ;
}
V_42 = NULL ;
F_10 ( V_34 , L_21 , & V_42 ) ;
if ( V_42 ) {
if ( ! strcmp ( V_42 , L_22 ) )
V_12 -> V_16 |= V_51 ;
else if ( ! strcmp ( V_42 , L_23 ) )
V_12 -> V_16 |= V_52 ;
else if ( strcmp ( V_42 , L_24 ) )
return - V_37 ;
V_36 = true ;
}
V_38 = F_5 ( V_34 , L_25 , & V_43 ) ;
if ( ! V_38 ) {
switch ( V_43 ) {
case 4 :
V_12 -> V_16 |= V_53 ;
break;
case 8 :
V_12 -> V_16 |= V_54 ;
break;
case 16 :
V_12 -> V_16 |= V_55 ;
break;
case 32 :
V_12 -> V_16 |= V_56 ;
break;
default:
return - V_37 ;
}
V_12 -> V_16 |= V_57 ;
V_36 = true ;
}
V_38 = F_6 ( V_2 , V_34 , & V_12 -> V_14 ,
& V_36 ) ;
if ( V_38 )
return V_38 ;
return V_36 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_9 = F_2 ( V_2 -> V_7 -> V_10 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_58 ;
T_1 V_15 ;
V_58 = F_12 ( V_9 ,
V_14 -> V_21 ) ;
V_15 = F_13 ( V_58 ) ;
V_58 = F_12 ( V_9 ,
V_14 -> V_22 ) ;
V_15 |= F_14 ( V_58 ) ;
V_58 = F_12 ( V_9 ,
V_14 -> V_23 ) ;
V_15 |= F_15 ( V_58 ) ;
V_58 = F_12 ( V_9 ,
V_14 -> V_24 ) ;
V_15 |= F_16 ( V_58 ) ;
F_17 ( V_6 -> V_20 , V_4 -> V_17 , V_15 ) ;
V_58 = F_18 ( V_9 ,
V_14 -> V_26 ) ;
V_15 = F_19 ( V_58 ) ;
V_58 = F_18 ( V_9 ,
V_14 -> V_27 ) ;
V_15 |= F_20 ( V_58 ) ;
V_58 = F_18 ( V_9 ,
V_14 -> V_28 ) ;
V_15 |= F_21 ( V_58 ) ;
V_58 = F_18 ( V_9 ,
V_14 -> V_29 ) ;
V_15 |= F_22 ( V_58 ) ;
F_17 ( V_6 -> V_25 , V_4 -> V_17 , V_15 ) ;
V_58 = F_23 ( V_9 ,
V_14 -> V_31 ) ;
V_15 = F_24 ( V_58 ) ;
V_58 = F_23 ( V_9 ,
V_14 -> V_32 ) ;
V_15 |= F_25 ( V_58 ) ;
F_17 ( V_6 -> V_30 , V_4 -> V_17 , V_15 ) ;
V_15 = F_26 ( V_14 -> V_19 , V_9 ) ;
if ( V_15 > V_59 )
V_15 = V_59 ;
F_17 ( V_6 -> V_16 , V_4 -> V_17 ,
V_12 -> V_16 | F_27 ( V_15 ) ) ;
return 0 ;
}
static int F_28 ( struct V_60 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_8 ;
struct V_61 V_62 = F_29 ( 0 , 0 , 31 ) ;
V_62 . V_63 = F_30 ( V_7 -> V_64 -> V_65 ) ;
V_62 . V_66 = V_67 ;
V_62 . V_68 = F_31 ( V_69 ) ;
V_6 -> V_20 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_20 ) )
return F_34 ( V_6 -> V_20 ) ;
V_62 . V_68 = F_35 ( V_69 ) ;
V_6 -> V_25 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_25 ) )
return F_34 ( V_6 -> V_25 ) ;
V_62 . V_68 = F_36 ( V_69 ) ;
V_6 -> V_30 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_30 ) )
return F_34 ( V_6 -> V_30 ) ;
V_62 . V_68 = F_37 ( V_69 ) ;
V_6 -> V_16 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
return F_38 ( V_6 -> V_16 ) ;
}
static int F_39 ( struct V_60 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_8 ;
struct V_61 V_62 = F_29 ( 0 , 0 , 31 ) ;
V_62 . V_63 = F_30 ( V_7 -> V_64 -> V_65 ) ;
V_62 . V_66 = V_71 ;
V_62 . V_68 = F_31 ( V_72 ) ;
V_6 -> V_20 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_20 ) )
return F_34 ( V_6 -> V_20 ) ;
V_62 . V_68 = F_35 ( V_72 ) ;
V_6 -> V_25 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_25 ) )
return F_34 ( V_6 -> V_25 ) ;
V_62 . V_68 = F_36 ( V_72 ) ;
V_6 -> V_30 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
if ( F_33 ( V_6 -> V_30 ) )
return F_34 ( V_6 -> V_30 ) ;
V_62 . V_68 = F_40 ( V_72 ) ;
V_6 -> V_16 = F_32 ( V_7 -> V_40 , V_7 -> V_70 , V_62 ) ;
return F_38 ( V_6 -> V_16 ) ;
}
static int F_41 ( struct V_60 * V_7 , struct V_33 * V_34 ,
int V_73 )
{
const struct V_74 * V_64 = V_7 -> V_64 ;
struct V_3 V_4 = { } ;
struct V_75 * V_40 = V_7 -> V_40 ;
struct V_1 * V_2 ;
int V_38 , V_76 = 0 , V_77 ;
bool V_78 = false ;
V_76 = F_42 ( V_34 , L_26 ,
V_73 * sizeof( T_1 ) ) ;
if ( V_76 <= 0 ) {
F_7 ( V_40 , L_27 , V_34 -> V_41 ) ;
return - V_37 ;
}
V_2 = F_43 ( V_7 -> V_40 ,
sizeof( * V_2 ) + ( V_76 * sizeof( * V_2 -> V_79 ) ) ,
V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_7 = V_7 ;
V_38 = V_64 -> V_82 ( V_2 , V_34 , & V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
else if ( V_38 )
V_78 = true ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
T_1 V_17 ;
V_38 = F_44 ( V_34 , L_26 , V_77 * V_73 ,
& V_17 ) ;
if ( V_38 )
return V_38 ;
if ( V_17 > V_83 ||
! ( V_7 -> V_64 -> V_65 & F_45 ( V_17 ) ) ) {
F_7 ( V_40 , L_27 ,
V_34 -> V_41 ) ;
return - V_37 ;
}
V_2 -> V_79 [ V_77 ] . V_17 = V_17 ;
if ( V_78 ) {
V_4 . V_17 = V_17 ;
V_38 = V_64 -> V_84 ( V_2 , & V_4 ) ;
if ( V_38 )
return V_38 ;
}
V_64 -> V_85 ( V_2 , & V_2 -> V_79 [ V_77 ] ) ;
if ( V_7 -> V_86 && V_38 )
F_46 ( V_7 -> V_86 ,
F_45 ( V_17 ) , 0 ) ;
}
F_47 ( & V_2 -> V_87 , & V_7 -> V_88 ) ;
return 0 ;
}
static int F_48 ( struct V_60 * V_7 , struct V_33 * V_34 )
{
struct V_75 * V_40 = V_7 -> V_40 ;
struct V_89 * V_90 ;
V_90 = F_43 ( V_40 , sizeof( * V_90 ) , V_80 ) ;
if ( ! V_90 )
return - V_81 ;
V_90 -> V_91 = F_49 ( V_40 , L_28 , V_80 ) ;
if ( ! V_90 -> V_91 )
return - V_81 ;
V_90 -> V_92 = F_49 ( V_40 , L_24 , V_80 ) ;
if ( ! V_90 -> V_92 )
return - V_81 ;
V_90 -> V_93 = sizeof( L_24 ) ;
return F_50 ( V_34 , V_90 ) ;
}
static int F_51 ( struct V_94 * V_95 )
{
struct V_75 * V_40 = & V_95 -> V_40 ;
struct V_33 * V_96 , * V_34 = V_40 -> V_97 ;
const struct V_98 * V_99 ;
struct V_60 * V_7 ;
int V_38 , V_73 ;
struct V_10 * V_10 ;
T_1 V_15 ;
V_99 = F_52 ( V_100 , V_40 ) ;
if ( ! V_99 || ! V_99 -> V_101 )
return - V_37 ;
V_7 = F_43 ( V_40 , sizeof( * V_7 ) , V_80 ) ;
if ( ! V_7 )
return - V_81 ;
F_53 ( & V_7 -> V_88 ) ;
V_7 -> V_64 = V_99 -> V_101 ;
V_7 -> V_40 = V_40 ;
V_10 = F_54 ( V_40 , NULL ) ;
if ( F_33 ( V_10 ) )
return F_34 ( V_10 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_70 = F_55 ( V_34 , L_29 ) ;
if ( F_33 ( V_7 -> V_70 ) )
return F_34 ( V_7 -> V_70 ) ;
if ( V_7 -> V_64 -> V_86 ) {
V_7 -> V_102 =
F_55 ( V_34 , L_30 ) ;
if ( F_33 ( V_7 -> V_102 ) )
return F_34 ( V_7 -> V_102 ) ;
V_7 -> V_86 = F_56 ( V_7 -> V_102 ,
* V_7 -> V_64 -> V_86 ) ;
if ( F_33 ( V_7 -> V_86 ) )
return F_34 ( V_7 -> V_86 ) ;
}
V_38 = V_7 -> V_64 -> V_103 ( V_7 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_5 ( V_34 , L_31 , & V_15 ) ;
if ( V_38 ) {
F_7 ( V_40 , L_32 ) ;
return V_38 ;
}
V_73 = V_15 ;
V_38 = F_5 ( V_34 , L_33 , & V_15 ) ;
if ( V_38 ) {
F_7 ( V_40 , L_32 ) ;
return V_38 ;
}
V_73 += V_15 ;
F_57 (np, child) {
if ( ! F_58 ( V_96 , L_26 , NULL ) )
continue;
V_38 = F_41 ( V_7 , V_96 , V_73 ) ;
if ( V_38 ) {
F_7 ( V_40 , L_34 ,
V_96 -> V_41 ) ;
V_38 = F_48 ( V_7 , V_96 ) ;
if ( V_38 )
return V_38 ;
}
}
return F_59 ( V_34 , NULL , NULL , V_40 ) ;
}
