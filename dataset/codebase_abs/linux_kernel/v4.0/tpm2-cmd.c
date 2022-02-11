int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
T_1 * V_8 ;
if ( V_3 >= V_9 )
return - V_10 ;
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
memset ( V_7 . V_14 . V_15 . V_21 , 0 ,
sizeof( V_7 . V_14 . V_15 . V_21 ) ) ;
V_7 . V_14 . V_15 . V_21 [ V_3 >> 3 ] = 1 << ( V_3 & 0x7 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_1 ) ;
if ( V_5 == 0 ) {
V_8 = V_7 . V_14 . V_22 . V_23 ;
memcpy ( V_4 , V_8 , V_24 ) ;
}
return V_5 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , const T_1 * V_25 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_26 ;
V_7 . V_14 . V_27 . V_3 = F_2 ( V_3 ) ;
V_7 . V_14 . V_27 . V_28 =
F_2 ( sizeof( struct V_29 ) ) ;
V_7 . V_14 . V_27 . V_30 . V_31 =
F_2 ( V_32 ) ;
V_7 . V_14 . V_27 . V_30 . V_33 = 0 ;
V_7 . V_14 . V_27 . V_30 . V_34 = 0 ;
V_7 . V_14 . V_27 . V_30 . V_35 = 0 ;
V_7 . V_14 . V_27 . V_36 = F_2 ( 1 ) ;
V_7 . V_14 . V_27 . V_17 = F_3 ( V_18 ) ;
memcpy ( V_7 . V_14 . V_27 . V_23 , V_25 , V_24 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_2 ) ;
return V_5 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_37 , T_2 V_38 )
{
struct V_6 V_7 ;
T_3 V_39 ;
T_3 V_40 ;
int V_41 ;
int V_42 = 0 ;
int V_43 = 5 ;
T_1 * V_44 = V_37 ;
V_40 = F_7 ( T_3 , V_38 , sizeof( V_7 . V_14 . V_45 . V_46 ) ) ;
if ( ! V_37 || ! V_40 ||
V_38 > sizeof( V_7 . V_14 . V_45 . V_46 ) )
return - V_10 ;
do {
V_7 . V_11 . V_12 = V_47 ;
V_7 . V_14 . V_48 . V_49 = F_3 ( V_40 ) ;
V_41 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_3 ) ;
if ( V_41 )
break;
V_39 = F_7 ( T_3 , F_8 ( V_7 . V_14 . V_45 . V_49 ) ,
V_40 ) ;
memcpy ( V_44 , V_7 . V_14 . V_45 . V_46 , V_39 ) ;
V_44 += V_39 ;
V_42 += V_39 ;
V_40 -= V_39 ;
} while ( V_43 -- && V_42 < V_38 );
return V_42 ? V_42 : - V_50 ;
}
T_4 F_9 ( struct V_1 * V_2 , T_3 V_51 , T_3 * V_52 ,
const char * V_53 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_54 ;
V_7 . V_14 . V_55 . V_56 = F_2 ( V_57 ) ;
V_7 . V_14 . V_55 . V_51 = F_2 ( V_51 ) ;
V_7 . V_14 . V_55 . V_58 = F_2 ( 1 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , V_53 ) ;
if ( ! V_5 )
* V_52 = V_7 . V_14 . V_59 . V_52 ;
return V_5 ;
}
int F_10 ( struct V_1 * V_2 , T_5 V_60 )
{
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_61 ;
V_7 . V_14 . V_62 . V_60 = F_3 ( V_60 ) ;
return F_4 ( V_2 , & V_7 , sizeof( V_7 ) ,
L_4 ) ;
}
void F_11 ( struct V_1 * V_2 , T_5 V_63 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_64 ;
V_7 . V_14 . V_62 . V_60 = F_3 ( V_63 ) ;
V_5 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , L_5 ) ;
if ( V_5 < 0 )
F_12 ( V_2 -> V_65 , L_6 ,
V_5 ) ;
}
unsigned long F_13 ( struct V_1 * V_2 , T_3 V_66 )
{
int V_67 = V_68 ;
int V_69 = 0 ;
if ( V_66 >= V_70 && V_66 <= V_71 )
V_67 = V_72 [ V_66 - V_70 ] ;
if ( V_67 != V_68 )
V_69 = V_2 -> V_73 . V_69 [ V_67 ] ;
if ( V_69 <= 0 )
V_69 = 2 * 60 * V_74 ;
return V_69 ;
}
static int F_14 ( struct V_1 * V_2 , bool V_75 )
{
int V_5 ;
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_76 ;
V_7 . V_14 . V_77 . V_78 = V_75 ;
V_5 = F_4 ( V_2 , & V_7 , V_79 ,
L_7 ) ;
if ( V_5 == V_80 ) {
F_12 ( V_2 -> V_65 , L_8 ) ;
V_5 = 0 ;
}
return V_5 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_81 ;
unsigned int V_82 = 100 ;
unsigned long V_69 ;
struct V_6 V_7 ;
int V_83 ;
V_69 = F_13 ( V_2 , V_84 ) ;
V_81 = F_16 ( V_69 ) / V_82 ;
V_5 = F_14 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
V_7 . V_14 . V_15 . V_21 [ 0 ] = 0x01 ;
V_7 . V_14 . V_15 . V_21 [ 1 ] = 0x00 ;
V_7 . V_14 . V_15 . V_21 [ 2 ] = 0x00 ;
V_5 = F_4 ( V_2 , ( T_1 * ) & V_7 , sizeof( V_7 ) , NULL ) ;
if ( V_5 < 0 )
break;
V_5 = F_17 ( V_7 . V_11 . V_37 . V_85 ) ;
if ( V_5 != V_80 )
break;
F_18 ( V_82 ) ;
}
return V_5 ;
}
int F_19 ( struct V_1 * V_2 )
{
T_3 V_86 ;
return F_9 ( V_2 , 0x100 , & V_86 ,
L_9 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_54 ;
V_7 . V_14 . V_55 . V_56 = F_2 ( V_57 ) ;
V_7 . V_14 . V_55 . V_51 = F_2 ( 0x100 ) ;
V_7 . V_14 . V_55 . V_58 = F_2 ( 1 ) ;
V_5 = F_21 ( V_2 , ( const char * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 < V_87 )
return - V_88 ;
if ( F_8 ( V_7 . V_11 . V_37 . V_89 ) == V_90 )
V_2 -> V_91 |= V_92 ;
return 0 ;
}
