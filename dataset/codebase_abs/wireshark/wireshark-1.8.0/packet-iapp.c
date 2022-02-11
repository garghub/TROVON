static void F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 , V_6 , V_7 ;
const T_4 * V_8 ;
T_4 V_9 [ 4 + 1 + 4 + 1 ] ;
V_4 = F_2 ( V_1 , V_10 ) ;
V_6 = F_3 ( V_2 , V_3 + 3 ) ;
for ( V_5 = 7 ; V_5 >= 0 ; V_5 -- )
{
V_7 = 1 << V_5 ;
V_8 = F_4 ( V_7 , V_11 ) ;
if ( V_8 )
{
F_5 ( V_9 , V_6 , V_7 , 8 ) ;
F_6 ( V_4 , V_2 , V_3 + 3 , 1 , L_1 ,
V_9 , V_8 , V_6 & V_7 ? L_2 : L_3 ) ;
}
}
}
static void
F_7 ( T_1 * V_12 , int type , int V_13 , T_2 * V_2 , int V_3 )
{
int V_14 , V_6 ;
F_8 ( V_12 , L_4 ) ;
switch ( type )
{
case V_15 :
F_8 ( V_12 , L_5 , F_3 ( V_2 , V_3 + 3 ) ? L_6 : L_7 ) ;
break;
case V_16 :
case V_17 :
F_8 ( V_12 , L_8 ,
F_9 ( V_2 , V_3 + 3 , V_13 ) ) ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_6 = F_10 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_9 , V_6 ) ;
break;
case V_25 :
case V_26 :
case V_27 :
V_6 = F_10 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_10 , V_6 ) ;
break;
case V_28 :
F_8 ( V_12 , L_5 , F_11 ( V_2 , V_3 + 3 ) ) ;
break;
case V_29 :
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_8 ( V_12 , L_11 , V_14 ? L_12 : L_13 ,
F_3 ( V_2 , V_3 + 3 + V_14 ) ) ;
break;
}
}
static void F_12 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_30 )
{
T_3 * V_31 ;
T_1 * V_12 ;
T_5 V_32 ;
int V_13 ;
V_31 = F_2 ( V_1 , V_33 ) ;
while ( V_30 > 0 )
{
F_13 ( V_2 , ( V_34 * ) & V_32 , V_3 , sizeof( T_5 ) ) ;
V_13 = ( ( ( int ) V_32 . V_35 ) << 8 ) + V_32 . V_36 ;
V_12 = F_6 ( V_31 , V_2 , V_3 , V_13 + 3 ,
L_14 ,
F_14 ( V_32 . V_37 , V_38 ,
L_15 ) ,
V_32 . V_37 ) ;
F_7 ( V_12 , V_32 . V_37 , V_13 , V_2 , V_3 ) ;
V_30 -= ( V_13 + 3 ) ;
V_3 += ( V_13 + 3 ) ;
}
}
static T_6
F_15 ( T_1 * V_12 , int type , int V_13 , T_2 * V_2 , int V_3 ,
T_6 V_39 )
{
int V_14 , V_6 ;
const T_4 * V_8 ;
F_8 ( V_12 , L_4 ) ;
switch ( type )
{
case V_40 :
F_8 ( V_12 , L_8 ,
F_9 ( V_2 , V_3 + 3 , V_13 ) ) ;
break;
case V_41 :
case V_42 :
case V_43 :
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_8 ( V_12 , L_11 , V_14 ? L_16 : L_13 ,
F_3 ( V_2 , V_3 + 3 + V_14 ) ) ;
break;
case V_44 :
{
int V_45 , V_46 = 1 ;
V_6 = F_3 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_17 , V_6 ) ;
for ( V_45 = 0x80 ; V_45 ; V_45 >>= 1 )
if ( V_6 & V_45 )
{
V_8 = F_4 ( V_45 , V_11 ) ;
if ( V_8 )
{
if ( ! V_46 )
F_8 ( V_12 , L_12 ) ;
F_8 ( V_12 , L_5 , V_8 ) ;
V_46 = 0 ;
}
}
F_8 ( V_12 , L_18 ) ;
break;
}
case V_47 :
V_6 = F_16 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_10 , V_6 ) ;
break;
case V_48 :
case V_49 :
V_6 = F_16 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_19 , V_6 ) ;
break;
case V_50 :
V_6 = F_16 ( V_2 , V_3 + 3 ) ;
F_8 ( V_12 , L_9 , V_6 ) ;
break;
case V_51 :
V_6 = F_3 ( V_2 , V_3 + 3 ) ;
V_8 = F_14 ( V_6 , V_52 , L_20 ) ;
F_8 ( V_12 , L_5 , V_8 ) ;
V_39 = ( V_6 == V_53 ) ;
break;
case V_54 :
V_6 = F_3 ( V_2 , V_3 + 3 ) ;
V_8 = F_14 ( V_6 , V_55 , L_20 ) ;
F_8 ( V_12 , L_5 , V_8 ) ;
break;
case V_56 :
V_6 = F_3 ( V_2 , V_3 + 3 ) ;
if ( V_39 )
F_8 ( V_12 , L_21 ,
( ( V_6 >> 6 ) & 3 ) + 1 , ( V_6 & 31 ) + 1 ) ;
else
F_8 ( V_12 , L_9 , V_6 ) ;
break;
case V_57 :
for ( V_6 = V_14 = 0 ; V_14 < 3 ; V_14 ++ )
V_6 = ( V_6 << 8 ) | F_3 ( V_2 , V_3 + 3 + V_14 ) ;
V_8 = F_14 ( V_6 , V_58 , L_20 ) ;
F_8 ( V_12 , L_5 , V_8 ) ;
break;
}
return V_39 ;
}
static void
F_17 ( T_2 * V_2 , int V_3 , T_3 * V_59 , int V_60 )
{
T_5 V_32 ;
int V_13 ;
T_1 * V_12 ;
T_6 V_39 ;
if ( ! V_60 )
{
F_6 ( V_59 , V_2 , V_3 , 0 , L_22 ) ;
return;
}
V_39 = FALSE ;
while ( V_60 > 0 )
{
F_13 ( V_2 , ( V_34 * ) & V_32 , V_3 , sizeof( T_5 ) ) ;
V_13 = ( ( ( int ) V_32 . V_35 ) << 8 ) + V_32 . V_36 ;
V_12 = F_6 ( V_59 , V_2 , V_3 , V_13 + 3 ,
L_14 ,
F_14 ( V_32 . V_37 , V_61 ,
L_15 ) ,
V_32 . V_37 ) ;
V_39 = F_15 ( V_12 , V_32 . V_37 , V_13 , V_2 ,
V_3 , V_39 ) ;
if ( V_32 . V_37 == V_44 )
F_1 ( V_12 , V_2 , V_3 ) ;
if ( V_32 . V_37 == V_62 )
F_12 ( V_12 , V_2 , V_3 + 3 , V_13 ) ;
V_60 -= ( V_13 + 3 ) ;
V_3 += ( V_13 + 3 ) ;
}
}
static void
F_18 ( T_2 * V_2 , T_7 * V_63 , T_3 * V_64 )
{
T_1 * V_12 , * V_65 ;
T_3 * V_66 , * V_59 ;
T_8 V_67 ;
int V_68 ;
int V_69 ;
const T_4 * V_70 ;
F_19 ( V_63 -> V_71 , V_72 , L_23 ) ;
F_20 ( V_63 -> V_71 , V_73 ) ;
F_13 ( V_2 , ( V_34 * ) & V_67 , 0 , sizeof( T_8 ) ) ;
V_68 = ( int ) V_67 . V_68 ;
V_69 = ( int ) V_67 . V_69 ;
V_70 = F_14 ( V_69 , V_74 , L_24 ) ;
if ( F_21 ( V_63 -> V_71 , V_73 ) )
{
F_22 ( V_63 -> V_71 , V_73 , L_25 ,
V_70 , V_69 , V_68 ) ;
}
if ( V_64 )
{
V_12 = F_23 ( V_64 , V_75 , V_2 , 0 , - 1 , V_76 ) ;
V_66 = F_2 ( V_12 , V_77 ) ;
F_24 ( V_66 , V_78 , V_2 , 0 , 1 ,
V_67 . V_68 ) ;
F_25 ( V_66 , V_79 , V_2 , 1 , 1 ,
V_67 . V_69 , L_26 , V_70 , V_69 ) ;
V_65 = F_6 ( V_66 , V_2 , 2 , - 1 ,
L_27 ) ;
V_59 = F_2 ( V_65 , V_80 ) ;
if ( V_59 )
{
F_17 ( V_2 , 2 , V_59 ,
F_26 ( V_2 , 2 ) ) ;
}
}
}
void
F_27 ( void )
{
static T_9 V_81 [] = {
{ & V_78 ,
{ L_28 , L_29 , V_82 , V_83 , NULL , 0x00 , NULL , V_84 }
} ,
{ & V_79 ,
{ L_30 , L_31 , V_82 , V_83 , NULL , 0x00 , NULL , V_84 }
} ,
} ;
static T_10 * V_85 [] = {
& V_77 ,
& V_80 ,
& V_10 ,
& V_33
} ;
V_75 = F_28 ( L_32 ,
L_23 , L_33 ) ;
F_29 ( V_75 , V_81 , F_30 ( V_81 ) ) ;
F_31 ( V_85 , F_30 ( V_85 ) ) ;
}
void
F_32 ( void )
{
T_11 V_86 ;
V_86 = F_33 ( F_18 , V_75 ) ;
F_34 ( L_34 , V_87 , V_86 ) ;
}
