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
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_8 [ 0 ] , V_2 -> V_7 + V_11 ) ;
F_3 ( V_2 -> V_8 [ 1 ] , V_2 -> V_7 + V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_13 = F_8 ( V_2 -> V_14 ) ;
unsigned int div ;
div = F_9 ( V_13 , V_2 -> V_15 * 4 ) ;
F_1 ( V_2 , V_16 , V_17 ,
div << V_18 ) ;
F_10 ( V_2 -> V_19 , L_1 , V_20 ,
V_13 , V_2 -> V_15 , div ) ;
}
static void F_11 ( struct V_1 * V_2 , char * V_21 , int V_22 )
{
T_1 V_23 , V_24 ;
int V_25 ;
V_23 = F_2 ( V_2 -> V_7 + V_26 ) ;
V_24 = F_2 ( V_2 -> V_7 + V_27 ) ;
F_10 ( V_2 -> V_19 , L_2 , V_20 ,
V_23 , V_24 , V_22 ) ;
for ( V_25 = 0 ; V_25 < F_12 ( int , 4 , V_22 ) ; V_25 ++ )
* V_21 ++ = ( V_23 >> V_25 * 8 ) & 0xff ;
for ( V_25 = 4 ; V_25 < F_12 ( int , 8 , V_22 ) ; V_25 ++ )
* V_21 ++ = ( V_24 >> ( V_25 - 4 ) * 8 ) & 0xff ;
}
static void F_13 ( struct V_1 * V_2 , char * V_21 , int V_22 )
{
T_1 V_28 = 0 , V_29 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_12 ( int , 4 , V_22 ) ; V_25 ++ )
V_28 |= * V_21 ++ << ( V_25 * 8 ) ;
for ( V_25 = 4 ; V_25 < F_12 ( int , 8 , V_22 ) ; V_25 ++ )
V_29 |= * V_21 ++ << ( ( V_25 - 4 ) * 8 ) ;
F_3 ( V_28 , V_2 -> V_7 + V_30 ) ;
F_3 ( V_29 , V_2 -> V_7 + V_31 ) ;
F_10 ( V_2 -> V_19 , L_2 , V_20 ,
V_28 , V_29 , V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
bool V_32 = ! ( V_2 -> V_33 -> V_34 & V_35 ) ;
int V_25 ;
V_2 -> V_36 = F_12 ( int , V_2 -> V_33 -> V_22 - V_2 -> V_37 , 8 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_36 - 1 ; V_25 ++ )
F_5 ( V_2 , V_38 ) ;
if ( V_2 -> V_36 ) {
if ( V_32 || V_2 -> V_37 + V_2 -> V_36 < V_2 -> V_33 -> V_22 )
F_5 ( V_2 , V_38 ) ;
else
F_5 ( V_2 , V_39 ) ;
}
if ( V_32 )
F_13 ( V_2 , V_2 -> V_33 -> V_21 + V_2 -> V_37 , V_2 -> V_36 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_19 , L_3 , V_20 , V_2 -> V_40 ) ;
if ( V_2 -> V_40 ) {
V_2 -> V_41 = V_42 ;
F_5 ( V_2 , V_43 ) ;
} else {
V_2 -> V_41 = V_44 ;
F_16 ( & V_2 -> V_45 ) ;
}
}
static T_2 F_17 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
unsigned int V_48 ;
F_18 ( & V_2 -> V_49 ) ;
F_4 ( V_2 ) ;
V_48 = F_2 ( V_2 -> V_7 + V_16 ) ;
F_10 ( V_2 -> V_19 , L_4 ,
V_2 -> V_41 , V_2 -> V_37 , V_2 -> V_36 , V_48 ) ;
if ( V_48 & V_50 && V_2 -> V_41 != V_44 ) {
F_10 ( V_2 -> V_19 , L_5 ) ;
V_2 -> error = - V_51 ;
V_2 -> V_41 = V_44 ;
F_16 ( & V_2 -> V_45 ) ;
goto V_52;
}
switch ( V_2 -> V_41 ) {
case V_53 :
if ( V_2 -> V_36 > 0 ) {
F_11 ( V_2 , V_2 -> V_33 -> V_21 + V_2 -> V_37 ,
V_2 -> V_36 ) ;
V_2 -> V_37 += V_2 -> V_36 ;
}
if ( V_2 -> V_37 >= V_2 -> V_33 -> V_22 ) {
F_15 ( V_2 ) ;
break;
}
F_14 ( V_2 ) ;
break;
case V_54 :
V_2 -> V_37 += V_2 -> V_36 ;
if ( V_2 -> V_37 >= V_2 -> V_33 -> V_22 ) {
F_15 ( V_2 ) ;
break;
}
F_14 ( V_2 ) ;
break;
case V_42 :
V_2 -> V_41 = V_44 ;
F_16 ( & V_2 -> V_45 ) ;
break;
case V_44 :
break;
}
V_52:
if ( V_2 -> V_41 != V_44 ) {
F_6 ( V_2 ) ;
F_1 ( V_2 , V_16 , V_55 , 0 ) ;
F_1 ( V_2 , V_16 , V_55 ,
V_55 ) ;
}
F_19 ( & V_2 -> V_49 ) ;
return V_56 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_57 * V_33 )
{
int V_10 ;
V_10 = ( V_33 -> V_34 & V_35 ) ? V_58 :
V_59 ;
F_3 ( V_33 -> V_60 << 1 , V_2 -> V_7 + V_61 ) ;
F_5 ( V_2 , V_62 ) ;
F_5 ( V_2 , V_10 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_57 * V_33 ,
int V_40 )
{
unsigned long V_63 , V_34 ;
int V_64 = 0 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_37 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> error = 0 ;
F_4 ( V_2 ) ;
V_34 = ( V_33 -> V_34 & V_65 ) ? V_66 : 0 ;
F_1 ( V_2 , V_16 , V_66 , V_34 ) ;
if ( ! ( V_33 -> V_34 & V_67 ) )
F_20 ( V_2 , V_33 ) ;
V_2 -> V_41 = ( V_33 -> V_34 & V_35 ) ? V_53 : V_54 ;
F_14 ( V_2 ) ;
F_6 ( V_2 ) ;
F_22 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_16 , V_55 , V_55 ) ;
V_63 = F_23 ( V_68 ) ;
V_63 = F_24 ( & V_2 -> V_45 , V_63 ) ;
F_25 ( & V_2 -> V_49 , V_34 ) ;
F_1 ( V_2 , V_16 , V_55 , 0 ) ;
if ( ! V_63 ) {
V_2 -> V_41 = V_44 ;
V_64 = - V_69 ;
}
if ( V_2 -> error )
V_64 = V_2 -> error ;
F_26 ( & V_2 -> V_49 , V_34 ) ;
return V_64 ;
}
static int F_27 ( struct V_70 * V_71 , struct V_57 * V_72 ,
int V_73 )
{
struct V_1 * V_2 = V_71 -> V_74 ;
int V_25 , V_64 = 0 , V_36 = 0 ;
F_28 ( V_2 -> V_14 ) ;
F_7 ( V_2 ) ;
for ( V_25 = 0 ; V_25 < V_73 ; V_25 ++ ) {
V_64 = F_21 ( V_2 , V_72 + V_25 , V_25 == V_73 - 1 ) ;
if ( V_64 )
break;
V_36 ++ ;
}
F_29 ( V_2 -> V_14 ) ;
return V_64 ? V_64 : V_36 ;
}
static T_1 F_30 ( struct V_70 * V_71 )
{
return V_75 | V_76 ;
}
static int F_31 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = V_78 -> V_19 . V_81 ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
int V_64 = 0 ;
V_2 = F_32 ( & V_78 -> V_19 , sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
if ( F_33 ( V_78 -> V_19 . V_81 , L_6 ,
& V_2 -> V_15 ) )
V_2 -> V_15 = V_86 ;
V_2 -> V_19 = & V_78 -> V_19 ;
F_34 ( V_78 , V_2 ) ;
F_35 ( & V_2 -> V_49 ) ;
F_36 ( & V_2 -> V_45 ) ;
V_2 -> V_14 = F_37 ( & V_78 -> V_19 , NULL ) ;
if ( F_38 ( V_2 -> V_14 ) ) {
F_39 ( & V_78 -> V_19 , L_7 ) ;
return F_40 ( V_2 -> V_14 ) ;
}
V_83 = F_41 ( V_78 , V_87 , 0 ) ;
V_2 -> V_7 = F_42 ( & V_78 -> V_19 , V_83 ) ;
if ( F_38 ( V_2 -> V_7 ) )
return F_40 ( V_2 -> V_7 ) ;
V_2 -> V_88 = F_43 ( V_78 , 0 ) ;
if ( V_2 -> V_88 < 0 ) {
F_39 ( & V_78 -> V_19 , L_8 ) ;
return V_2 -> V_88 ;
}
V_64 = F_44 ( & V_78 -> V_19 , V_2 -> V_88 , F_17 ,
0 , F_45 ( & V_78 -> V_19 ) , V_2 ) ;
if ( V_64 < 0 ) {
F_39 ( & V_78 -> V_19 , L_9 ) ;
return V_64 ;
}
V_64 = F_46 ( V_2 -> V_14 ) ;
if ( V_64 < 0 ) {
F_39 ( & V_78 -> V_19 , L_10 ) ;
return V_64 ;
}
F_47 ( V_2 -> V_71 . V_89 , L_11 ,
sizeof( V_2 -> V_71 . V_89 ) ) ;
V_2 -> V_71 . V_90 = V_91 ;
V_2 -> V_71 . V_92 = & V_93 ;
V_2 -> V_71 . V_19 . V_94 = & V_78 -> V_19 ;
V_2 -> V_71 . V_19 . V_81 = V_80 ;
V_2 -> V_71 . V_74 = V_2 ;
F_1 ( V_2 , V_16 , V_55 , 0 ) ;
V_64 = F_48 ( & V_2 -> V_71 ) ;
if ( V_64 < 0 ) {
F_49 ( V_2 -> V_14 ) ;
return V_64 ;
}
return 0 ;
}
static int F_50 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_51 ( V_78 ) ;
F_52 ( & V_2 -> V_71 ) ;
F_49 ( V_2 -> V_14 ) ;
return 0 ;
}
