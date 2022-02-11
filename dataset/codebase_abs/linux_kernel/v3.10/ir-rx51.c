static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 , 0 , 1 ,
V_3 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 , 0 , 1 ,
V_4 ) ;
}
static int F_4 ( struct V_1 * V_1 )
{
T_1 V_5 , V_6 ;
V_5 = - ( V_1 -> V_7 * 1000 / V_1 -> V_8 ) ;
V_6 = - ( V_1 -> V_9 * - V_5 / 100 ) ;
F_5 ( V_1 -> V_2 , 1 , V_5 ) ;
F_6 ( V_1 -> V_2 , 1 , V_6 ) ;
F_7 ( V_1 -> V_2 , V_10 - 2 ) ;
F_8 ( V_1 -> V_2 ) ;
F_9 ( V_1 -> V_11 , 0 ) ;
F_8 ( V_1 -> V_11 ) ;
V_1 -> V_6 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , int V_12 )
{
int V_13 ;
F_11 ( V_12 < 0 ) ;
if ( V_1 -> V_6 == 0 )
V_13 = F_12 ( V_1 -> V_11 ) ;
else
V_13 = V_1 -> V_6 ;
V_13 += ( T_1 ) ( V_1 -> V_7 * V_12 / ( 1000 ) ) ;
F_6 ( V_1 -> V_11 , 1 , V_13 ) ;
F_9 ( V_1 -> V_11 ,
V_14 ) ;
if ( F_13 ( F_12 ( V_1 -> V_11 ) ,
V_13 ) ) {
return 1 ;
}
return 0 ;
}
static T_2 F_14 ( int V_15 , void * V_16 )
{
unsigned int V_17 ;
struct V_1 * V_1 = V_16 ;
V_17 = F_15 ( V_1 -> V_11 ) ;
if ( ! V_17 )
return V_18 ;
if ( V_17 & ~ V_14 )
F_16 ( V_1 -> V_19 ,
L_1 , V_17 ) ;
F_17 ( V_1 -> V_11 ,
V_14 |
V_20 |
V_21 ) ;
if ( V_1 -> V_22 < 0 ) {
F_16 ( V_1 -> V_19 ,
L_2 ,
V_1 -> V_22 ) ;
goto V_23;
}
do {
if ( V_1 -> V_22 >= V_24 )
goto V_23;
if ( V_1 -> V_25 [ V_1 -> V_22 ] == - 1 )
goto V_23;
if ( V_1 -> V_22 % 2 )
F_3 ( V_1 ) ;
else
F_1 ( V_1 ) ;
V_17 = F_10 ( V_1 ,
V_1 -> V_25 [ V_1 -> V_22 ] ) ;
V_1 -> V_22 ++ ;
} while ( V_17 );
return V_26 ;
V_23:
F_3 ( V_1 ) ;
V_1 -> V_22 = - 1 ;
F_18 ( V_1 -> V_2 ) ;
F_18 ( V_1 -> V_11 ) ;
F_9 ( V_1 -> V_11 , 0 ) ;
F_19 ( & V_1 -> V_27 ) ;
return V_26 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_28 * V_29 ;
int V_17 , V_2 = V_1 -> V_30 ;
V_1 -> V_2 = F_21 ( V_2 ) ;
if ( V_1 -> V_2 == NULL ) {
F_22 ( V_1 -> V_19 , L_3 ,
V_2 ) ;
return - V_31 ;
}
V_1 -> V_11 = F_23 () ;
if ( V_1 -> V_11 == NULL ) {
F_22 ( V_1 -> V_19 , L_4 ) ;
V_17 = - V_31 ;
goto V_32;
}
F_24 ( V_1 -> V_2 , V_33 ) ;
F_24 ( V_1 -> V_11 ,
V_33 ) ;
F_25 ( V_1 -> V_2 ) ;
F_25 ( V_1 -> V_11 ) ;
V_1 -> V_34 = F_26 ( V_1 -> V_11 ) ;
V_17 = F_27 ( V_1 -> V_34 , F_14 ,
V_35 | V_36 ,
L_5 , V_1 ) ;
if ( V_17 ) {
F_22 ( V_1 -> V_19 , L_6 ) ;
goto V_37;
}
V_29 = F_28 ( V_1 -> V_2 ) ;
V_1 -> V_7 = V_29 -> V_38 / 1000 ;
return 0 ;
V_37:
F_29 ( V_1 -> V_11 ) ;
V_32:
F_29 ( V_1 -> V_2 ) ;
return V_17 ;
}
static int F_30 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_11 , 0 ) ;
F_31 ( V_1 -> V_34 , V_1 ) ;
F_3 ( V_1 ) ;
F_32 ( V_1 -> V_2 ) ;
F_32 ( V_1 -> V_11 ) ;
F_29 ( V_1 -> V_2 ) ;
F_29 ( V_1 -> V_11 ) ;
V_1 -> V_22 = - 1 ;
return 0 ;
}
static T_3 F_33 ( struct V_39 * V_39 , const char * V_40 ,
T_4 V_41 , T_5 * V_42 )
{
int V_43 , V_44 ;
struct V_1 * V_1 = V_39 -> V_45 ;
if ( V_41 % sizeof( int ) )
return - V_46 ;
V_43 = V_41 / sizeof( int ) ;
if ( ( V_43 > V_24 ) || ( V_43 % 2 == 0 ) )
return - V_46 ;
F_34 ( V_1 -> V_27 , V_1 -> V_22 < 0 ) ;
if ( F_35 ( V_1 -> V_25 , V_40 , V_41 ) )
return - V_47 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
if ( V_1 -> V_25 [ V_44 ] < 0 )
return - V_46 ;
F_4 ( V_1 ) ;
if ( V_43 < V_24 )
V_1 -> V_25 [ V_43 ] = - 1 ;
V_1 -> V_48 -> V_49 ( V_1 -> V_19 , 50 ) ;
F_1 ( V_1 ) ;
V_1 -> V_22 = 1 ;
F_10 ( V_1 , V_1 -> V_25 [ 0 ] ) ;
F_34 ( V_1 -> V_27 , V_1 -> V_22 < 0 ) ;
V_1 -> V_48 -> V_49 ( V_1 -> V_19 , - 1 ) ;
return V_41 ;
}
static long F_36 ( struct V_39 * V_50 ,
unsigned int V_51 , unsigned long V_52 )
{
int V_53 ;
unsigned long V_54 ;
unsigned int V_55 ;
struct V_1 * V_1 = V_50 -> V_45 ;
switch ( V_51 ) {
case V_56 :
V_53 = F_37 ( V_57 , ( unsigned long * ) V_52 ) ;
if ( V_53 )
return V_53 ;
break;
case V_58 :
V_53 = F_38 ( V_54 , ( unsigned long * ) V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_54 != V_57 )
return - V_59 ;
break;
case V_60 :
V_53 = F_37 ( 0 , ( unsigned long * ) V_52 ) ;
if ( V_53 )
return V_53 ;
break;
case V_61 :
return - V_59 ;
break;
case V_62 :
V_53 = F_38 ( V_55 , ( unsigned int * ) V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_55 <= 0 || V_55 > 100 ) {
F_22 ( V_1 -> V_19 , L_7 ,
V_55 ) ;
return - V_46 ;
}
V_1 -> V_9 = V_55 ;
break;
case V_63 :
V_53 = F_38 ( V_55 , ( unsigned int * ) V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_55 > 500000 || V_55 < 20000 ) {
F_22 ( V_1 -> V_19 , L_8 ,
V_55 ) ;
return - V_46 ;
}
V_1 -> V_8 = V_55 ;
break;
case V_64 :
V_53 = F_37 ( V_65 ,
( unsigned long * ) V_52 ) ;
if ( V_53 )
return V_53 ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_39 ( struct V_67 * V_67 , struct V_39 * V_39 )
{
struct V_1 * V_1 = F_40 ( V_39 ) ;
F_11 ( ! V_1 ) ;
V_39 -> V_45 = V_1 ;
if ( F_41 ( 1 , & V_1 -> V_68 ) )
return - V_31 ;
return F_20 ( V_1 ) ;
}
static int F_42 ( struct V_67 * V_67 , struct V_39 * V_39 )
{
struct V_1 * V_1 = V_39 -> V_45 ;
F_30 ( V_1 ) ;
F_43 ( 1 , & V_1 -> V_68 ) ;
return 0 ;
}
static int F_44 ( struct V_69 * V_19 , T_6 V_70 )
{
if ( F_41 ( 1 , & V_1 . V_68 ) )
return - V_71 ;
F_43 ( 1 , & V_1 . V_68 ) ;
return 0 ;
}
static int F_45 ( struct V_69 * V_19 )
{
return 0 ;
}
static int F_46 ( struct V_69 * V_19 )
{
V_72 . V_73 = V_65 ;
V_1 . V_48 = V_19 -> V_19 . V_74 ;
V_1 . V_30 = V_1 . V_48 -> V_2 ;
V_1 . V_19 = & V_19 -> V_19 ;
V_72 . V_19 = & V_19 -> V_19 ;
V_72 . V_75 = F_47 ( & V_72 ) ;
F_48 ( & V_1 . V_27 ) ;
if ( V_72 . V_75 < 0 ) {
F_22 ( V_1 . V_19 , L_9 ,
V_72 . V_75 ) ;
return V_72 . V_75 ;
}
F_49 ( V_1 . V_19 , L_10 ,
V_72 . V_75 , V_1 . V_30 ) ;
return 0 ;
}
static int F_50 ( struct V_69 * V_19 )
{
return F_51 ( V_72 . V_75 ) ;
}
