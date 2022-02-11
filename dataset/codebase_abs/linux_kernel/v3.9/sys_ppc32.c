T_1 long F_1 ( T_2 V_1 , T_3 T_4 * V_2 ,
T_3 T_4 * V_3 , T_3 T_4 * exp ,
T_5 V_4 )
{
return F_2 ( ( int ) V_1 , V_2 , V_3 , exp , F_3 ( V_4 ) ) ;
}
long F_4 ( T_2 V_5 , T_2 V_6 , T_2 V_7 , T_2 V_8 , T_5 V_9 ,
T_2 V_10 )
{
int V_11 ;
V_11 = V_5 >> 16 ;
V_5 &= 0xffff ;
switch ( V_5 ) {
case V_12 :
if ( V_10 )
return F_5 ( ( int ) V_6 ,
F_3 ( V_9 ) , V_7 ,
F_3 ( V_10 ) ) ;
case V_13 :
return F_6 ( ( int ) V_6 , F_3 ( V_9 ) , V_7 ,
NULL ) ;
case V_14 :
return F_7 ( ( int ) V_6 , ( int ) V_7 , V_8 ) ;
case V_15 :
return F_8 ( ( int ) V_6 , ( int ) V_7 , V_8 ,
F_3 ( V_9 ) ) ;
case V_16 :
return F_9 ( ( int ) V_6 , ( int ) V_7 , V_8 ,
F_3 ( V_9 ) ) ;
case V_17 :
return F_10 ( ( int ) V_6 , V_7 , ( int ) V_10 ,
V_8 , V_11 , F_3 ( V_9 ) ) ;
case V_18 :
return F_11 ( ( int ) V_6 , V_7 ) ;
case V_19 :
return F_12 ( ( int ) V_6 , V_7 , F_3 ( V_9 ) ) ;
case V_20 :
return F_13 ( ( int ) V_6 , V_7 , V_8 , V_11 ,
F_3 ( V_9 ) ) ;
case V_21 :
return F_14 ( F_3 ( V_9 ) ) ;
case V_22 :
return F_15 ( ( int ) V_6 , V_7 , V_8 ) ;
case V_23 :
return F_16 ( ( int ) V_6 , V_7 , F_3 ( V_9 ) ) ;
default:
return - V_24 ;
}
return - V_24 ;
}
T_1 long F_17 ( T_2 V_25 , T_2 V_26 ,
T_6 T_4 * V_27 , T_2 V_28 )
{
return F_18 ( ( int ) V_25 , ( int ) V_26 , V_27 , V_28 ) ;
}
T_1 long F_19 ( T_2 V_25 , T_2 V_26 ,
T_7 T_4 * V_27 , T_2 V_28 )
{
return F_20 ( ( int ) V_25 , ( int ) V_26 ,
( V_29 T_4 * ) V_27 , V_28 ) ;
}
unsigned long F_21 ( unsigned long V_30 , T_8 V_31 ,
unsigned long V_32 , unsigned long V_33 ,
unsigned long V_34 , unsigned long V_35 )
{
return F_22 ( V_30 , V_31 , V_32 , V_33 , V_34 , V_35 << 12 ) ;
}
T_9 F_23 ( unsigned int V_34 , char T_4 * V_36 , T_10 V_28 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 )
{
return F_24 ( V_34 , V_36 , V_28 , ( ( V_40 ) V_38 << 32 ) | V_39 ) ;
}
T_9 F_25 ( unsigned int V_34 , const char T_4 * V_36 , T_10 V_28 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 )
{
return F_26 ( V_34 , V_36 , V_28 , ( ( V_40 ) V_38 << 32 ) | V_39 ) ;
}
T_9 F_27 ( int V_34 , T_2 V_41 , T_2 V_42 , T_2 V_43 , T_2 V_28 )
{
return F_28 ( V_34 , ( ( V_40 ) V_42 << 32 ) | V_43 , V_28 ) ;
}
T_1 int F_29 ( const char T_4 * V_44 , T_2 V_45 ,
unsigned long V_46 , unsigned long V_47 )
{
return F_30 ( V_44 , ( V_46 << 32 ) | V_47 ) ;
}
T_1 long F_31 ( int V_34 , int V_48 , T_2 V_42 , T_2 V_43 ,
T_2 V_49 , T_2 V_50 )
{
return F_32 ( V_34 , V_48 , ( ( V_40 ) V_42 << 32 ) | V_43 ,
( ( V_40 ) V_49 << 32 ) | V_50 ) ;
}
T_1 int F_33 ( unsigned int V_34 , T_2 V_45 , unsigned long V_46 ,
unsigned long V_47 )
{
return F_34 ( V_34 , ( V_46 << 32 ) | V_47 ) ;
}
long F_35 ( T_2 V_51 , T_2 V_52 , char T_4 * V_53 ,
T_8 V_31 )
{
return F_36 ( ( V_54 ) V_51 << 32 | V_52 ,
V_53 , V_31 ) ;
}
long F_37 ( int V_34 , T_2 V_55 , T_2 V_56 , T_2 V_57 ,
T_8 V_31 , int V_58 )
{
return F_38 ( V_34 , ( V_54 ) V_56 << 32 | V_57 , V_31 ,
V_58 ) ;
}
T_1 long F_39 ( const char T_4 * V_59 ,
const char T_4 * V_60 ,
const void T_4 * V_61 ,
T_2 V_62 ,
T_2 V_63 )
{
return F_40 ( V_59 , V_60 , V_61 , V_62 , V_63 ) ;
}
T_1 long F_41 ( const char T_4 * V_59 ,
const char T_4 * V_60 ,
const char T_4 * V_64 ,
T_2 V_65 )
{
return F_42 ( V_59 , V_60 , V_64 , V_65 ) ;
}
T_1 long F_43 ( int V_34 , unsigned int V_33 ,
unsigned V_66 , unsigned V_67 ,
unsigned V_68 , unsigned V_69 )
{
V_40 V_27 = ( ( V_40 ) V_66 << 32 ) | V_67 ;
V_40 V_70 = ( ( V_40 ) V_68 << 32 ) | V_69 ;
return F_44 ( V_34 , V_27 , V_70 , V_33 ) ;
}
T_1 long F_45 ( int V_71 , unsigned int V_33 ,
unsigned V_72 , unsigned V_73 ,
int V_74 , const char T_4 * V_75 )
{
V_54 V_76 = ( ( V_54 ) V_72 << 32 ) | V_73 ;
return F_46 ( V_71 , V_33 , V_76 , V_74 , V_75 ) ;
}
