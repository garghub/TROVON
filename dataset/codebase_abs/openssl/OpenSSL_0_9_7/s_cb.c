int T_1 F_1 ( int V_1 , T_2 * V_2 )
{
char V_3 [ 256 ] ;
T_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 ) ;
F_5 ( F_6 ( V_4 ) , V_3 , sizeof V_3 ) ;
F_7 ( V_7 , L_1 , V_6 , V_3 ) ;
if ( ! V_1 )
{
F_7 ( V_7 , L_2 , V_5 ,
F_8 ( V_5 ) ) ;
if ( V_8 >= V_6 )
{
V_1 = 1 ;
V_9 = V_10 ;
}
else
{
V_1 = 0 ;
V_9 = V_11 ;
}
}
switch ( V_2 -> error )
{
case V_12 :
F_5 ( F_9 ( V_2 -> V_13 ) , V_3 , sizeof V_3 ) ;
F_7 ( V_7 , L_3 , V_3 ) ;
break;
case V_14 :
case V_15 :
F_7 ( V_7 , L_4 ) ;
F_10 ( V_7 , F_11 ( V_2 -> V_13 ) ) ;
F_7 ( V_7 , L_5 ) ;
break;
case V_16 :
case V_17 :
F_7 ( V_7 , L_6 ) ;
F_10 ( V_7 , F_12 ( V_2 -> V_13 ) ) ;
F_7 ( V_7 , L_5 ) ;
break;
}
F_7 ( V_7 , L_7 , V_1 ) ;
return ( V_1 ) ;
}
int F_13 ( T_4 * V_2 , char * V_18 , char * V_19 )
{
if ( V_18 != NULL )
{
if ( F_14 ( V_2 , V_18 ,
V_20 ) <= 0 )
{
F_7 ( V_7 , L_8 , V_18 ) ;
F_15 ( V_7 ) ;
return ( 0 ) ;
}
if ( V_19 == NULL ) V_19 = V_18 ;
if ( F_16 ( V_2 , V_19 ,
V_20 ) <= 0 )
{
F_7 ( V_7 , L_9 , V_19 ) ;
F_15 ( V_7 ) ;
return ( 0 ) ;
}
if ( ! F_17 ( V_2 ) )
{
F_7 ( V_7 , L_10 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
long T_1 F_18 ( T_5 * V_21 , int V_22 , const char * V_23 , int V_24 ,
long V_25 , long V_26 )
{
T_5 * V_27 ;
V_27 = ( T_5 * ) F_19 ( V_21 ) ;
if ( V_27 == NULL ) return ( V_26 ) ;
if ( V_22 == ( V_28 | V_29 ) )
{
F_7 ( V_27 , L_11 ,
V_21 , V_23 , V_24 , V_26 , V_26 ) ;
F_20 ( V_27 , V_23 , ( int ) V_26 ) ;
return ( V_26 ) ;
}
else if ( V_22 == ( V_30 | V_29 ) )
{
F_7 ( V_27 , L_12 ,
V_21 , V_23 , V_24 , V_26 , V_26 ) ;
F_20 ( V_27 , V_23 , ( int ) V_26 ) ;
}
return ( V_26 ) ;
}
void T_1 F_21 ( const T_6 * V_31 , int V_32 , int V_26 )
{
char * V_33 ;
int V_34 ;
V_34 = V_32 & ~ V_35 ;
if ( V_34 & V_36 ) V_33 = L_13 ;
else if ( V_34 & V_37 ) V_33 = L_14 ;
else V_33 = L_15 ;
if ( V_32 & V_38 )
{
F_7 ( V_7 , L_16 , V_33 , F_22 ( V_31 ) ) ;
}
else if ( V_32 & V_39 )
{
V_33 = ( V_32 & V_40 ) ? L_17 : L_18 ;
F_7 ( V_7 , L_19 ,
V_33 ,
F_23 ( V_26 ) ,
F_24 ( V_26 ) ) ;
}
else if ( V_32 & V_41 )
{
if ( V_26 == 0 )
F_7 ( V_7 , L_20 ,
V_33 , F_22 ( V_31 ) ) ;
else if ( V_26 < 0 )
{
F_7 ( V_7 , L_21 ,
V_33 , F_22 ( V_31 ) ) ;
}
}
}
void T_1 F_25 ( int V_42 , int V_43 , int V_44 , const void * V_3 , T_7 V_45 , T_6 * V_46 , void * V_47 )
{
T_5 * V_21 = V_47 ;
const char * V_48 , * V_49 , * V_50 = L_22 , * V_51 = L_22 , * V_52 = L_22 ;
V_48 = V_42 ? L_23 : L_24 ;
switch ( V_43 )
{
case V_53 :
V_49 = L_25 ;
break;
case V_54 :
V_49 = L_26 ;
break;
case V_55 :
V_49 = L_27 ;
break;
default:
V_49 = L_28 ;
}
if ( V_43 == V_53 )
{
V_51 = L_28 ;
if ( V_45 > 0 )
{
switch ( ( ( unsigned char * ) V_3 ) [ 0 ] )
{
case 0 :
V_51 = L_29 ;
V_52 = L_30 ;
if ( V_45 >= 3 )
{
unsigned V_5 = ( ( ( unsigned char * ) V_3 ) [ 1 ] << 8 ) + ( ( unsigned char * ) V_3 ) [ 2 ] ;
switch ( V_5 )
{
case 0x0001 :
V_52 = L_31 ;
break;
case 0x0002 :
V_52 = L_32 ;
break;
case 0x0004 :
V_52 = L_33 ;
break;
case 0x0006 :
V_52 = L_34 ;
break;
}
}
break;
case 1 :
V_51 = L_35 ;
break;
case 2 :
V_51 = L_36 ;
break;
case 3 :
V_51 = L_37 ;
break;
case 4 :
V_51 = L_38 ;
break;
case 5 :
V_51 = L_39 ;
break;
case 6 :
V_51 = L_40 ;
break;
case 7 :
V_51 = L_41 ;
break;
case 8 :
V_51 = L_42 ;
break;
}
}
}
if ( V_43 == V_54 || V_43 == V_55 )
{
switch ( V_44 )
{
case 20 :
V_50 = L_43 ;
break;
case 21 :
V_50 = L_44 ;
break;
case 22 :
V_50 = L_45 ;
break;
}
if ( V_44 == 21 )
{
V_51 = L_46 ;
if ( V_45 == 2 )
{
switch ( ( ( unsigned char * ) V_3 ) [ 0 ] )
{
case 1 :
V_51 = L_47 ;
break;
case 2 :
V_51 = L_48 ;
break;
}
V_52 = L_30 ;
switch ( ( ( unsigned char * ) V_3 ) [ 1 ] )
{
case 0 :
V_52 = L_49 ;
break;
case 10 :
V_52 = L_50 ;
break;
case 20 :
V_52 = L_51 ;
break;
case 21 :
V_52 = L_52 ;
break;
case 22 :
V_52 = L_53 ;
break;
case 30 :
V_52 = L_54 ;
break;
case 40 :
V_52 = L_55 ;
break;
case 42 :
V_52 = L_56 ;
break;
case 43 :
V_52 = L_57 ;
break;
case 44 :
V_52 = L_58 ;
break;
case 45 :
V_52 = L_59 ;
break;
case 46 :
V_52 = L_60 ;
break;
case 47 :
V_52 = L_61 ;
break;
case 48 :
V_52 = L_62 ;
break;
case 49 :
V_52 = L_63 ;
break;
case 50 :
V_52 = L_64 ;
break;
case 51 :
V_52 = L_65 ;
break;
case 60 :
V_52 = L_66 ;
break;
case 70 :
V_52 = L_67 ;
break;
case 71 :
V_52 = L_68 ;
break;
case 80 :
V_52 = L_69 ;
break;
case 90 :
V_52 = L_70 ;
break;
case 100 :
V_52 = L_71 ;
break;
}
}
}
if ( V_44 == 22 )
{
V_51 = L_28 ;
if ( V_45 > 0 )
{
switch ( ( ( unsigned char * ) V_3 ) [ 0 ] )
{
case 0 :
V_51 = L_72 ;
break;
case 1 :
V_51 = L_73 ;
break;
case 2 :
V_51 = L_74 ;
break;
case 11 :
V_51 = L_75 ;
break;
case 12 :
V_51 = L_76 ;
break;
case 13 :
V_51 = L_77 ;
break;
case 14 :
V_51 = L_78 ;
break;
case 15 :
V_51 = L_79 ;
break;
case 16 :
V_51 = L_80 ;
break;
case 20 :
V_51 = L_81 ;
break;
}
}
}
}
F_7 ( V_21 , L_82 , V_48 , V_49 , V_50 , ( unsigned long ) V_45 , V_51 , V_52 ) ;
if ( V_45 > 0 )
{
T_7 V_56 , V_57 ;
F_7 ( V_21 , L_83 ) ;
V_56 = V_45 ;
#if 0
if (num > 16)
num = 16;
#endif
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ )
{
if ( V_57 % 16 == 0 && V_57 > 0 )
F_7 ( V_21 , L_84 ) ;
F_7 ( V_21 , L_85 , ( ( unsigned char * ) V_3 ) [ V_57 ] ) ;
}
if ( V_57 < V_45 )
F_7 ( V_21 , L_86 ) ;
F_7 ( V_21 , L_5 ) ;
}
F_26 ( V_21 ) ;
}
