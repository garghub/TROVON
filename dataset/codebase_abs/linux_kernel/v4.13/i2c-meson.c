static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 -> V_7 + V_3 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 & V_4 ;
F_3 ( V_6 , V_2 -> V_7 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_8 [ 0 ] = 0 ;
V_2 -> V_8 [ 1 ] = 0 ;
V_2 -> V_9 = 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_10 )
{
if ( V_2 -> V_9 < 8 )
V_2 -> V_8 [ 0 ] |= ( V_10 & 0xf ) << ( V_2 -> V_9 * 4 ) ;
else
V_2 -> V_8 [ 1 ] |= ( V_10 & 0xf ) << ( ( V_2 -> V_9 % 8 ) * 4 ) ;
V_2 -> V_9 ++ ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_11 )
{
unsigned long V_12 = F_7 ( V_2 -> V_13 ) ;
unsigned int div ;
div = F_8 ( V_12 , V_11 * 4 ) ;
if ( div >= ( 1 << 12 ) ) {
F_9 ( V_2 -> V_14 , L_1 ) ;
div = ( 1 << 12 ) - 1 ;
}
F_1 ( V_2 , V_15 , V_16 ,
( div & F_10 ( 9 , 0 ) ) << V_17 ) ;
F_1 ( V_2 , V_15 , V_18 ,
( div >> 10 ) << V_19 ) ;
F_11 ( V_2 -> V_14 , L_2 , V_20 ,
V_12 , V_11 , div ) ;
}
static void F_12 ( struct V_1 * V_2 , char * V_21 , int V_22 )
{
T_1 V_23 , V_24 ;
int V_25 ;
V_23 = F_2 ( V_2 -> V_7 + V_26 ) ;
V_24 = F_2 ( V_2 -> V_7 + V_27 ) ;
F_11 ( V_2 -> V_14 , L_3 , V_20 ,
V_23 , V_24 , V_22 ) ;
for ( V_25 = 0 ; V_25 < F_13 ( 4 , V_22 ) ; V_25 ++ )
* V_21 ++ = ( V_23 >> V_25 * 8 ) & 0xff ;
for ( V_25 = 4 ; V_25 < F_13 ( 8 , V_22 ) ; V_25 ++ )
* V_21 ++ = ( V_24 >> ( V_25 - 4 ) * 8 ) & 0xff ;
}
static void F_14 ( struct V_1 * V_2 , char * V_21 , int V_22 )
{
T_1 V_28 = 0 , V_29 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_13 ( 4 , V_22 ) ; V_25 ++ )
V_28 |= * V_21 ++ << ( V_25 * 8 ) ;
for ( V_25 = 4 ; V_25 < F_13 ( 8 , V_22 ) ; V_25 ++ )
V_29 |= * V_21 ++ << ( ( V_25 - 4 ) * 8 ) ;
F_3 ( V_28 , V_2 -> V_7 + V_30 ) ;
F_3 ( V_29 , V_2 -> V_7 + V_31 ) ;
F_11 ( V_2 -> V_14 , L_3 , V_20 ,
V_28 , V_29 , V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
bool V_32 = ! ( V_2 -> V_33 -> V_34 & V_35 ) ;
int V_25 ;
V_2 -> V_36 = F_13 ( V_2 -> V_33 -> V_22 - V_2 -> V_37 , 8 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_36 - 1 ; V_25 ++ )
F_5 ( V_2 , V_38 ) ;
if ( V_2 -> V_36 ) {
if ( V_32 || V_2 -> V_37 + V_2 -> V_36 < V_2 -> V_33 -> V_22 )
F_5 ( V_2 , V_38 ) ;
else
F_5 ( V_2 , V_39 ) ;
}
if ( V_32 )
F_14 ( V_2 , V_2 -> V_33 -> V_21 + V_2 -> V_37 , V_2 -> V_36 ) ;
if ( V_2 -> V_40 && V_2 -> V_37 + V_2 -> V_36 >= V_2 -> V_33 -> V_22 )
F_5 ( V_2 , V_41 ) ;
F_3 ( V_2 -> V_8 [ 0 ] , V_2 -> V_7 + V_42 ) ;
F_3 ( V_2 -> V_8 [ 1 ] , V_2 -> V_7 + V_43 ) ;
}
static T_2 F_16 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
unsigned int V_46 ;
F_17 ( & V_2 -> V_47 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 , V_15 , V_48 , 0 ) ;
V_46 = F_2 ( V_2 -> V_7 + V_15 ) ;
F_11 ( V_2 -> V_14 , L_4 ,
V_2 -> V_49 , V_2 -> V_37 , V_2 -> V_36 , V_46 ) ;
if ( V_2 -> V_49 == V_50 ) {
F_18 ( & V_2 -> V_47 ) ;
return V_51 ;
}
if ( V_46 & V_52 ) {
F_11 ( V_2 -> V_14 , L_5 ) ;
V_2 -> error = - V_53 ;
V_2 -> V_49 = V_50 ;
F_19 ( & V_2 -> V_54 ) ;
goto V_55;
}
if ( V_2 -> V_49 == V_56 && V_2 -> V_36 )
F_12 ( V_2 , V_2 -> V_33 -> V_21 + V_2 -> V_37 , V_2 -> V_36 ) ;
V_2 -> V_37 += V_2 -> V_36 ;
if ( V_2 -> V_37 >= V_2 -> V_33 -> V_22 ) {
V_2 -> V_49 = V_50 ;
F_19 ( & V_2 -> V_54 ) ;
goto V_55;
}
F_15 ( V_2 ) ;
F_1 ( V_2 , V_15 , V_48 , V_48 ) ;
V_55:
F_18 ( & V_2 -> V_47 ) ;
return V_57 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_58 * V_33 )
{
int V_10 ;
V_10 = ( V_33 -> V_34 & V_35 ) ? V_59 :
V_60 ;
F_3 ( V_33 -> V_61 << 1 , V_2 -> V_7 + V_62 ) ;
F_5 ( V_2 , V_63 ) ;
F_5 ( V_2 , V_10 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_58 * V_33 ,
int V_40 )
{
unsigned long V_64 , V_34 ;
int V_65 = 0 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_37 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> error = 0 ;
F_4 ( V_2 ) ;
V_34 = ( V_33 -> V_34 & V_66 ) ? V_67 : 0 ;
F_1 ( V_2 , V_15 , V_67 , V_34 ) ;
if ( ! ( V_33 -> V_34 & V_68 ) )
F_20 ( V_2 , V_33 ) ;
V_2 -> V_49 = ( V_33 -> V_34 & V_35 ) ? V_56 : V_69 ;
F_15 ( V_2 ) ;
F_22 ( & V_2 -> V_54 ) ;
F_1 ( V_2 , V_15 , V_48 , V_48 ) ;
V_64 = F_23 ( V_70 ) ;
V_64 = F_24 ( & V_2 -> V_54 , V_64 ) ;
F_25 ( & V_2 -> V_47 , V_34 ) ;
F_1 ( V_2 , V_15 , V_48 , 0 ) ;
if ( ! V_64 ) {
V_2 -> V_49 = V_50 ;
V_65 = - V_71 ;
}
if ( V_2 -> error )
V_65 = V_2 -> error ;
F_26 ( & V_2 -> V_47 , V_34 ) ;
return V_65 ;
}
static int F_27 ( struct V_72 * V_73 , struct V_58 * V_74 ,
int V_75 )
{
struct V_1 * V_2 = V_73 -> V_76 ;
int V_25 , V_65 = 0 ;
F_28 ( V_2 -> V_13 ) ;
for ( V_25 = 0 ; V_25 < V_75 ; V_25 ++ ) {
V_65 = F_21 ( V_2 , V_74 + V_25 , V_25 == V_75 - 1 ) ;
if ( V_65 )
break;
}
F_29 ( V_2 -> V_13 ) ;
return V_65 ? : V_25 ;
}
static T_1 F_30 ( struct V_72 * V_73 )
{
return V_77 | V_78 ;
}
static int F_31 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_14 . V_83 ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_86 V_87 ;
int V_88 , V_65 = 0 ;
V_2 = F_32 ( & V_80 -> V_14 , sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
F_33 ( & V_80 -> V_14 , & V_87 , true ) ;
V_2 -> V_14 = & V_80 -> V_14 ;
F_34 ( V_80 , V_2 ) ;
F_35 ( & V_2 -> V_47 ) ;
F_36 ( & V_2 -> V_54 ) ;
V_2 -> V_13 = F_37 ( & V_80 -> V_14 , NULL ) ;
if ( F_38 ( V_2 -> V_13 ) ) {
F_9 ( & V_80 -> V_14 , L_6 ) ;
return F_39 ( V_2 -> V_13 ) ;
}
V_85 = F_40 ( V_80 , V_91 , 0 ) ;
V_2 -> V_7 = F_41 ( & V_80 -> V_14 , V_85 ) ;
if ( F_38 ( V_2 -> V_7 ) )
return F_39 ( V_2 -> V_7 ) ;
V_88 = F_42 ( V_80 , 0 ) ;
if ( V_88 < 0 ) {
F_9 ( & V_80 -> V_14 , L_7 ) ;
return V_88 ;
}
V_65 = F_43 ( & V_80 -> V_14 , V_88 , F_16 , 0 , NULL , V_2 ) ;
if ( V_65 < 0 ) {
F_9 ( & V_80 -> V_14 , L_8 ) ;
return V_65 ;
}
V_65 = F_44 ( V_2 -> V_13 ) ;
if ( V_65 < 0 ) {
F_9 ( & V_80 -> V_14 , L_9 ) ;
return V_65 ;
}
F_45 ( V_2 -> V_73 . V_92 , L_10 ,
sizeof( V_2 -> V_73 . V_92 ) ) ;
V_2 -> V_73 . V_93 = V_94 ;
V_2 -> V_73 . V_95 = & V_96 ;
V_2 -> V_73 . V_14 . V_97 = & V_80 -> V_14 ;
V_2 -> V_73 . V_14 . V_83 = V_82 ;
V_2 -> V_73 . V_76 = V_2 ;
F_1 ( V_2 , V_15 , V_48 , 0 ) ;
V_65 = F_46 ( & V_2 -> V_73 ) ;
if ( V_65 < 0 ) {
F_47 ( V_2 -> V_13 ) ;
return V_65 ;
}
F_6 ( V_2 , V_87 . V_98 ) ;
return 0 ;
}
static int F_48 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_49 ( V_80 ) ;
F_50 ( & V_2 -> V_73 ) ;
F_47 ( V_2 -> V_13 ) ;
return 0 ;
}
