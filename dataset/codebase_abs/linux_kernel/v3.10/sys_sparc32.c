T_1 long F_1 ( const char T_2 * V_1 , unsigned long V_2 , unsigned long V_3 )
{
if ( ( int ) V_2 < 0 )
return - V_4 ;
else
return F_2 ( V_1 , ( V_2 << 32 ) | V_3 ) ;
}
T_1 long F_3 ( unsigned int V_5 , unsigned long V_2 , unsigned long V_3 )
{
if ( ( int ) V_2 < 0 )
return - V_4 ;
else
return F_4 ( V_5 , ( V_2 << 32 ) | V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_8 T_2 * V_9 )
{
int V_10 ;
V_10 = F_6 ( F_7 ( V_7 -> V_11 ) , & V_9 -> V_12 ) ;
V_10 |= F_6 ( V_7 -> V_13 , & V_9 -> V_14 ) ;
V_10 |= F_6 ( V_7 -> V_15 , & V_9 -> V_16 ) ;
V_10 |= F_6 ( V_7 -> V_17 , & V_9 -> V_18 ) ;
V_10 |= F_6 ( F_8 ( F_9 () , V_7 -> V_19 ) , & V_9 -> V_20 ) ;
V_10 |= F_6 ( F_10 ( F_9 () , V_7 -> V_21 ) , & V_9 -> V_22 ) ;
V_10 |= F_6 ( F_7 ( V_7 -> V_23 ) , & V_9 -> V_24 ) ;
V_10 |= F_6 ( 0 , ( unsigned long T_2 * ) & V_9 -> V_25 [ 0 ] ) ;
V_10 |= F_6 ( V_7 -> V_26 , & V_9 -> V_27 ) ;
V_10 |= F_6 ( V_7 -> V_28 , & V_9 -> V_29 ) ;
V_10 |= F_6 ( 0 , ( unsigned int T_2 * ) & V_9 -> V_30 [ 0 ] ) ;
V_10 |= F_6 ( 0 , ( unsigned int T_2 * ) & V_9 -> V_30 [ 4 ] ) ;
V_10 |= F_6 ( V_7 -> V_31 , & V_9 -> V_32 ) ;
V_10 |= F_6 ( V_7 -> V_33 . V_34 , & V_9 -> V_35 ) ;
V_10 |= F_6 ( V_7 -> V_33 . V_36 , & V_9 -> V_37 ) ;
V_10 |= F_6 ( V_7 -> V_38 . V_34 , & V_9 -> V_39 ) ;
V_10 |= F_6 ( V_7 -> V_38 . V_36 , & V_9 -> V_40 ) ;
V_10 |= F_6 ( V_7 -> ctime . V_34 , & V_9 -> V_41 ) ;
V_10 |= F_6 ( V_7 -> ctime . V_36 , & V_9 -> V_42 ) ;
V_10 |= F_6 ( 0 , & V_9 -> V_43 ) ;
V_10 |= F_6 ( 0 , & V_9 -> V_44 ) ;
return V_10 ;
}
T_1 long F_11 ( const char T_2 * V_45 ,
struct V_8 T_2 * V_9 )
{
struct V_6 V_7 ;
int error = F_12 ( V_45 , & V_7 ) ;
if ( ! error )
error = F_5 ( & V_7 , V_9 ) ;
return error ;
}
T_1 long F_13 ( const char T_2 * V_45 ,
struct V_8 T_2 * V_9 )
{
struct V_6 V_7 ;
int error = F_14 ( V_45 , & V_7 ) ;
if ( ! error )
error = F_5 ( & V_7 , V_9 ) ;
return error ;
}
T_1 long F_15 ( unsigned int V_5 ,
struct V_8 T_2 * V_9 )
{
struct V_6 V_7 ;
int error = F_16 ( V_5 , & V_7 ) ;
if ( ! error )
error = F_5 ( & V_7 , V_9 ) ;
return error ;
}
T_1 long F_17 ( unsigned int V_46 ,
const char T_2 * V_45 ,
struct V_8 T_2 * V_9 , int V_47 )
{
struct V_6 V_7 ;
int error ;
error = F_18 ( V_46 , V_45 , & V_7 , V_47 ) ;
if ( error )
return error ;
return F_5 ( & V_7 , V_9 ) ;
}
T_1 T_3 F_19 ( unsigned int V_5 ,
char T_2 * V_48 ,
T_4 V_49 ,
unsigned long V_50 ,
unsigned long V_51 )
{
return F_20 ( V_5 , V_48 , V_49 , ( V_50 << 32 ) | V_51 ) ;
}
T_1 T_3 F_21 ( unsigned int V_5 ,
char T_2 * V_48 ,
T_4 V_49 ,
unsigned long V_50 ,
unsigned long V_51 )
{
return F_22 ( V_5 , V_48 , V_49 , ( V_50 << 32 ) | V_51 ) ;
}
T_1 long F_23 ( int V_5 ,
unsigned long V_52 ,
unsigned long V_53 ,
T_4 V_49 )
{
return F_24 ( V_5 , ( V_52 << 32 ) | V_53 , V_49 ) ;
}
long F_25 ( int V_5 ,
unsigned long V_52 ,
unsigned long V_53 ,
T_4 V_54 , int V_55 )
{
return F_26 ( V_5 , ( V_52 << 32 ) | V_53 , V_54 , V_55 ) ;
}
long F_27 ( int V_5 ,
unsigned long V_52 , unsigned long V_53 ,
unsigned long V_56 , unsigned long V_57 ,
int V_55 )
{
return F_26 ( V_5 ,
( V_52 << 32 ) | V_53 ,
( V_56 << 32 ) | V_57 ,
V_55 ) ;
}
long F_28 ( unsigned int V_5 , unsigned long V_58 , unsigned long V_59 , unsigned long V_60 , unsigned long V_61 , unsigned int V_62 )
{
return F_29 ( V_5 ,
( V_58 << 32 ) | V_59 ,
( V_60 << 32 ) | V_61 ,
V_62 ) ;
}
T_1 long F_30 ( int V_5 , int V_15 , T_5 V_52 , T_5 V_53 ,
T_5 V_56 , T_5 V_57 )
{
return F_31 ( V_5 , V_15 , ( ( V_63 ) V_52 << 32 ) | V_53 ,
( ( V_63 ) V_56 << 32 ) | V_57 ) ;
}
