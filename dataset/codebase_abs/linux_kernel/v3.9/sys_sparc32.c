T_1 long F_1 ( T_2 V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 , T_3 V_5 , T_2 V_6 )
{
int V_7 ;
V_7 = V_1 >> 16 ;
V_1 &= 0xffff ;
switch ( V_1 ) {
case V_8 :
if ( V_6 )
return F_2 ( ( int ) V_2 ,
F_3 ( V_5 ) , V_3 ,
F_3 ( V_6 ) ) ;
case V_9 :
return F_4 ( ( int ) V_2 , F_3 ( V_5 ) , V_3 ,
NULL ) ;
case V_10 :
return F_5 ( ( int ) V_2 , ( int ) V_3 , V_4 ) ;
case V_11 :
return F_6 ( ( int ) V_2 , ( int ) V_3 , V_4 ,
F_3 ( V_5 ) ) ;
case V_12 :
return F_7 ( ( int ) V_2 , ( int ) V_3 , V_4 ,
F_3 ( V_5 ) ) ;
case V_13 :
return F_8 ( ( int ) V_2 , V_3 , ( int ) V_6 ,
V_4 , V_7 , F_3 ( V_5 ) ) ;
case V_14 :
return F_9 ( ( int ) V_2 , V_3 ) ;
case V_15 :
return F_10 ( ( int ) V_2 , V_3 , F_3 ( V_5 ) ) ;
case V_16 :
return F_11 ( ( int ) V_2 , V_3 , V_4 , V_7 ,
F_3 ( V_5 ) ) ;
case V_17 :
return F_12 ( F_3 ( V_5 ) ) ;
case V_18 :
return F_13 ( ( int ) V_2 , V_3 , V_4 ) ;
case V_19 :
return F_14 ( ( int ) V_2 , V_3 , F_3 ( V_5 ) ) ;
default:
return - V_20 ;
}
return - V_20 ;
}
T_1 long F_15 ( const char T_4 * V_21 , unsigned long V_22 , unsigned long V_23 )
{
if ( ( int ) V_22 < 0 )
return - V_24 ;
else
return F_16 ( V_21 , ( V_22 << 32 ) | V_23 ) ;
}
T_1 long F_17 ( unsigned int V_25 , unsigned long V_22 , unsigned long V_23 )
{
if ( ( int ) V_22 < 0 )
return - V_24 ;
else
return F_18 ( V_25 , ( V_22 << 32 ) | V_23 ) ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_28 T_4 * V_29 )
{
int V_30 ;
V_30 = F_20 ( F_21 ( V_27 -> V_31 ) , & V_29 -> V_32 ) ;
V_30 |= F_20 ( V_27 -> V_33 , & V_29 -> V_34 ) ;
V_30 |= F_20 ( V_27 -> V_35 , & V_29 -> V_36 ) ;
V_30 |= F_20 ( V_27 -> V_37 , & V_29 -> V_38 ) ;
V_30 |= F_20 ( F_22 ( F_23 () , V_27 -> V_39 ) , & V_29 -> V_40 ) ;
V_30 |= F_20 ( F_24 ( F_23 () , V_27 -> V_41 ) , & V_29 -> V_42 ) ;
V_30 |= F_20 ( F_21 ( V_27 -> V_43 ) , & V_29 -> V_44 ) ;
V_30 |= F_20 ( 0 , ( unsigned long T_4 * ) & V_29 -> V_45 [ 0 ] ) ;
V_30 |= F_20 ( V_27 -> V_46 , & V_29 -> V_47 ) ;
V_30 |= F_20 ( V_27 -> V_48 , & V_29 -> V_49 ) ;
V_30 |= F_20 ( 0 , ( unsigned int T_4 * ) & V_29 -> V_50 [ 0 ] ) ;
V_30 |= F_20 ( 0 , ( unsigned int T_4 * ) & V_29 -> V_50 [ 4 ] ) ;
V_30 |= F_20 ( V_27 -> V_51 , & V_29 -> V_52 ) ;
V_30 |= F_20 ( V_27 -> V_53 . V_54 , & V_29 -> V_55 ) ;
V_30 |= F_20 ( V_27 -> V_53 . V_56 , & V_29 -> V_57 ) ;
V_30 |= F_20 ( V_27 -> V_58 . V_54 , & V_29 -> V_59 ) ;
V_30 |= F_20 ( V_27 -> V_58 . V_56 , & V_29 -> V_60 ) ;
V_30 |= F_20 ( V_27 -> ctime . V_54 , & V_29 -> V_61 ) ;
V_30 |= F_20 ( V_27 -> ctime . V_56 , & V_29 -> V_62 ) ;
V_30 |= F_20 ( 0 , & V_29 -> V_63 ) ;
V_30 |= F_20 ( 0 , & V_29 -> V_64 ) ;
return V_30 ;
}
T_1 long F_25 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_26 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_27 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_28 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_29 ( unsigned int V_25 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_30 ( V_25 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_31 ( unsigned int V_66 ,
const char T_4 * V_65 ,
struct V_28 T_4 * V_29 , int V_67 )
{
struct V_26 V_27 ;
int error ;
error = F_32 ( V_66 , V_65 , & V_27 , V_67 ) ;
if ( error )
return error ;
return F_19 ( & V_27 , V_29 ) ;
}
T_1 T_5 F_33 ( unsigned int V_25 ,
char T_4 * V_68 ,
T_6 V_69 ,
unsigned long V_70 ,
unsigned long V_71 )
{
return F_34 ( V_25 , V_68 , V_69 , ( V_70 << 32 ) | V_71 ) ;
}
T_1 T_5 F_35 ( unsigned int V_25 ,
char T_4 * V_68 ,
T_6 V_69 ,
unsigned long V_70 ,
unsigned long V_71 )
{
return F_36 ( V_25 , V_68 , V_69 , ( V_70 << 32 ) | V_71 ) ;
}
T_1 long F_37 ( int V_25 ,
unsigned long V_72 ,
unsigned long V_73 ,
T_6 V_69 )
{
return F_38 ( V_25 , ( V_72 << 32 ) | V_73 , V_69 ) ;
}
long F_39 ( int V_25 ,
unsigned long V_72 ,
unsigned long V_73 ,
T_6 V_74 , int V_75 )
{
return F_40 ( V_25 , ( V_72 << 32 ) | V_73 , V_74 , V_75 ) ;
}
long F_41 ( int V_25 ,
unsigned long V_72 , unsigned long V_73 ,
unsigned long V_76 , unsigned long V_77 ,
int V_75 )
{
return F_40 ( V_25 ,
( V_72 << 32 ) | V_73 ,
( V_76 << 32 ) | V_77 ,
V_75 ) ;
}
long F_42 ( unsigned long V_78 ,
unsigned long V_79 ,
char T_4 * V_80 , T_7 V_74 )
{
return F_43 ( ( V_78 << 32 ) | V_79 ,
V_80 , V_74 ) ;
}
long F_44 ( int V_25 , unsigned long V_81 , unsigned long V_82 , unsigned long V_83 , unsigned long V_84 , int V_85 )
{
return F_45 ( V_25 ,
( V_81 << 32 ) | V_82 ,
( V_83 << 32 ) | V_84 ,
V_85 ) ;
}
T_1 long F_46 ( int V_25 , int V_35 , T_2 V_72 , T_2 V_73 ,
T_2 V_76 , T_2 V_77 )
{
return F_47 ( V_25 , V_35 , ( ( V_86 ) V_72 << 32 ) | V_73 ,
( ( V_86 ) V_76 << 32 ) | V_77 ) ;
}
