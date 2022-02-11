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
int F_18 ( T_4 * V_2 , T_3 * V_21 , T_5 * V_22 )
{
if ( V_21 == NULL )
return 1 ;
if ( F_19 ( V_2 , V_21 ) <= 0 )
{
F_7 ( V_7 , L_11 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
if ( F_20 ( V_2 , V_22 ) <= 0 )
{
F_7 ( V_7 , L_12 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
if ( ! F_17 ( V_2 ) )
{
F_7 ( V_7 , L_10 ) ;
return 0 ;
}
return 1 ;
}
long T_1 F_21 ( T_6 * V_23 , int V_24 , const char * V_25 ,
int V_26 , long V_27 , long V_28 )
{
T_6 * V_29 ;
V_29 = ( T_6 * ) F_22 ( V_23 ) ;
if ( V_29 == NULL ) return ( V_28 ) ;
if ( V_24 == ( V_30 | V_31 ) )
{
F_7 ( V_29 , L_13 ,
( void * ) V_23 , V_25 , V_26 , V_28 , V_28 ) ;
F_23 ( V_29 , V_25 , ( int ) V_28 ) ;
return ( V_28 ) ;
}
else if ( V_24 == ( V_32 | V_31 ) )
{
F_7 ( V_29 , L_14 ,
( void * ) V_23 , V_25 , V_26 , V_28 , V_28 ) ;
F_23 ( V_29 , V_25 , ( int ) V_28 ) ;
}
return ( V_28 ) ;
}
void T_1 F_24 ( const T_7 * V_33 , int V_34 , int V_28 )
{
const char * V_35 ;
int V_36 ;
V_36 = V_34 & ~ V_37 ;
if ( V_36 & V_38 ) V_35 = L_15 ;
else if ( V_36 & V_39 ) V_35 = L_16 ;
else V_35 = L_17 ;
if ( V_34 & V_40 )
{
F_7 ( V_7 , L_18 , V_35 , F_25 ( V_33 ) ) ;
}
else if ( V_34 & V_41 )
{
V_35 = ( V_34 & V_42 ) ? L_19 : L_20 ;
F_7 ( V_7 , L_21 ,
V_35 ,
F_26 ( V_28 ) ,
F_27 ( V_28 ) ) ;
}
else if ( V_34 & V_43 )
{
if ( V_28 == 0 )
F_7 ( V_7 , L_22 ,
V_35 , F_25 ( V_33 ) ) ;
else if ( V_28 < 0 )
{
F_7 ( V_7 , L_23 ,
V_35 , F_25 ( V_33 ) ) ;
}
}
}
void T_1 F_28 ( int V_44 , int V_45 , int V_46 , const void * V_3 , T_8 V_47 , T_7 * V_48 , void * V_49 )
{
T_6 * V_23 = V_49 ;
const char * V_50 , * V_51 , * V_52 = L_24 , * V_53 = L_24 , * V_54 = L_24 ;
V_50 = V_44 ? L_25 : L_26 ;
switch ( V_45 )
{
case V_55 :
V_51 = L_27 ;
break;
case V_56 :
V_51 = L_28 ;
break;
case V_57 :
V_51 = L_29 ;
break;
default:
V_51 = L_30 ;
}
if ( V_45 == V_55 )
{
V_53 = L_30 ;
if ( V_47 > 0 )
{
switch ( ( ( const unsigned char * ) V_3 ) [ 0 ] )
{
case 0 :
V_53 = L_31 ;
V_54 = L_32 ;
if ( V_47 >= 3 )
{
unsigned V_5 = ( ( ( const unsigned char * ) V_3 ) [ 1 ] << 8 ) + ( ( const unsigned char * ) V_3 ) [ 2 ] ;
switch ( V_5 )
{
case 0x0001 :
V_54 = L_33 ;
break;
case 0x0002 :
V_54 = L_34 ;
break;
case 0x0004 :
V_54 = L_35 ;
break;
case 0x0006 :
V_54 = L_36 ;
break;
}
}
break;
case 1 :
V_53 = L_37 ;
break;
case 2 :
V_53 = L_38 ;
break;
case 3 :
V_53 = L_39 ;
break;
case 4 :
V_53 = L_40 ;
break;
case 5 :
V_53 = L_41 ;
break;
case 6 :
V_53 = L_42 ;
break;
case 7 :
V_53 = L_43 ;
break;
case 8 :
V_53 = L_44 ;
break;
}
}
}
if ( V_45 == V_56 || V_45 == V_57 )
{
switch ( V_46 )
{
case 20 :
V_52 = L_45 ;
break;
case 21 :
V_52 = L_46 ;
break;
case 22 :
V_52 = L_47 ;
break;
}
if ( V_46 == 21 )
{
V_53 = L_48 ;
if ( V_47 == 2 )
{
switch ( ( ( const unsigned char * ) V_3 ) [ 0 ] )
{
case 1 :
V_53 = L_49 ;
break;
case 2 :
V_53 = L_50 ;
break;
}
V_54 = L_32 ;
switch ( ( ( const unsigned char * ) V_3 ) [ 1 ] )
{
case 0 :
V_54 = L_51 ;
break;
case 10 :
V_54 = L_52 ;
break;
case 20 :
V_54 = L_53 ;
break;
case 21 :
V_54 = L_54 ;
break;
case 22 :
V_54 = L_55 ;
break;
case 30 :
V_54 = L_56 ;
break;
case 40 :
V_54 = L_57 ;
break;
case 42 :
V_54 = L_58 ;
break;
case 43 :
V_54 = L_59 ;
break;
case 44 :
V_54 = L_60 ;
break;
case 45 :
V_54 = L_61 ;
break;
case 46 :
V_54 = L_62 ;
break;
case 47 :
V_54 = L_63 ;
break;
case 48 :
V_54 = L_64 ;
break;
case 49 :
V_54 = L_65 ;
break;
case 50 :
V_54 = L_66 ;
break;
case 51 :
V_54 = L_67 ;
break;
case 60 :
V_54 = L_68 ;
break;
case 70 :
V_54 = L_69 ;
break;
case 71 :
V_54 = L_70 ;
break;
case 80 :
V_54 = L_71 ;
break;
case 90 :
V_54 = L_72 ;
break;
case 100 :
V_54 = L_73 ;
break;
}
}
}
if ( V_46 == 22 )
{
V_53 = L_30 ;
if ( V_47 > 0 )
{
switch ( ( ( const unsigned char * ) V_3 ) [ 0 ] )
{
case 0 :
V_53 = L_74 ;
break;
case 1 :
V_53 = L_75 ;
break;
case 2 :
V_53 = L_76 ;
break;
case 11 :
V_53 = L_77 ;
break;
case 12 :
V_53 = L_78 ;
break;
case 13 :
V_53 = L_79 ;
break;
case 14 :
V_53 = L_80 ;
break;
case 15 :
V_53 = L_81 ;
break;
case 16 :
V_53 = L_82 ;
break;
case 20 :
V_53 = L_83 ;
break;
}
}
}
}
F_7 ( V_23 , L_84 , V_50 , V_51 , V_52 , ( unsigned long ) V_47 , V_53 , V_54 ) ;
if ( V_47 > 0 )
{
T_8 V_58 , V_59 ;
F_7 ( V_23 , L_85 ) ;
V_58 = V_47 ;
#if 0
if (num > 16)
num = 16;
#endif
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ )
{
if ( V_59 % 16 == 0 && V_59 > 0 )
F_7 ( V_23 , L_86 ) ;
F_7 ( V_23 , L_87 , ( ( const unsigned char * ) V_3 ) [ V_59 ] ) ;
}
if ( V_59 < V_47 )
F_7 ( V_23 , L_88 ) ;
F_7 ( V_23 , L_5 ) ;
}
F_29 ( V_23 ) ;
}
