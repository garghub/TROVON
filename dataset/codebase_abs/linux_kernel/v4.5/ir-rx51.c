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
V_35 , L_5 , V_1 ) ;
if ( V_17 ) {
F_22 ( V_1 -> V_19 , L_6 ) ;
goto V_36;
}
V_29 = F_28 ( V_1 -> V_2 ) ;
V_1 -> V_7 = V_29 -> V_37 / 1000 ;
return 0 ;
V_36:
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
static T_3 F_33 ( struct V_38 * V_38 , const char * V_39 ,
T_4 V_40 , T_5 * V_41 )
{
int V_42 , V_43 ;
struct V_1 * V_1 = V_38 -> V_44 ;
if ( V_40 % sizeof( int ) )
return - V_45 ;
V_42 = V_40 / sizeof( int ) ;
if ( ( V_42 > V_24 ) || ( V_42 % 2 == 0 ) )
return - V_45 ;
F_34 ( V_1 -> V_27 , V_1 -> V_22 < 0 ) ;
if ( F_35 ( V_1 -> V_25 , V_39 , V_40 ) )
return - V_46 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
if ( V_1 -> V_25 [ V_43 ] < 0 )
return - V_45 ;
F_4 ( V_1 ) ;
if ( V_42 < V_24 )
V_1 -> V_25 [ V_42 ] = - 1 ;
V_1 -> V_47 -> V_48 ( V_1 -> V_19 , 50 ) ;
F_1 ( V_1 ) ;
V_1 -> V_22 = 1 ;
F_10 ( V_1 , V_1 -> V_25 [ 0 ] ) ;
F_34 ( V_1 -> V_27 , V_1 -> V_22 < 0 ) ;
V_1 -> V_47 -> V_48 ( V_1 -> V_19 , - 1 ) ;
return V_40 ;
}
static long F_36 ( struct V_38 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
int V_52 ;
unsigned long V_53 ;
unsigned int V_54 ;
struct V_1 * V_1 = V_49 -> V_44 ;
switch ( V_50 ) {
case V_55 :
V_52 = F_37 ( V_56 , ( unsigned long * ) V_51 ) ;
if ( V_52 )
return V_52 ;
break;
case V_57 :
V_52 = F_38 ( V_53 , ( unsigned long * ) V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_53 != V_56 )
return - V_58 ;
break;
case V_59 :
V_52 = F_37 ( 0 , ( unsigned long * ) V_51 ) ;
if ( V_52 )
return V_52 ;
break;
case V_60 :
return - V_58 ;
break;
case V_61 :
V_52 = F_38 ( V_54 , ( unsigned int * ) V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_54 <= 0 || V_54 > 100 ) {
F_22 ( V_1 -> V_19 , L_7 ,
V_54 ) ;
return - V_45 ;
}
V_1 -> V_9 = V_54 ;
break;
case V_62 :
V_52 = F_38 ( V_54 , ( unsigned int * ) V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_54 > 500000 || V_54 < 20000 ) {
F_22 ( V_1 -> V_19 , L_8 ,
V_54 ) ;
return - V_45 ;
}
V_1 -> V_8 = V_54 ;
break;
case V_63 :
V_52 = F_37 ( V_64 ,
( unsigned long * ) V_51 ) ;
if ( V_52 )
return V_52 ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_39 ( struct V_66 * V_66 , struct V_38 * V_38 )
{
struct V_1 * V_1 = F_40 ( V_38 ) ;
F_11 ( ! V_1 ) ;
V_38 -> V_44 = V_1 ;
if ( F_41 ( 1 , & V_1 -> V_67 ) )
return - V_31 ;
return F_20 ( V_1 ) ;
}
static int F_42 ( struct V_66 * V_66 , struct V_38 * V_38 )
{
struct V_1 * V_1 = V_38 -> V_44 ;
F_30 ( V_1 ) ;
F_43 ( 1 , & V_1 -> V_67 ) ;
return 0 ;
}
static int F_44 ( struct V_68 * V_19 , T_6 V_69 )
{
if ( F_41 ( 1 , & V_1 . V_67 ) )
return - V_70 ;
F_43 ( 1 , & V_1 . V_67 ) ;
return 0 ;
}
static int F_45 ( struct V_68 * V_19 )
{
return 0 ;
}
static int F_46 ( struct V_68 * V_19 )
{
V_71 . V_72 = V_64 ;
V_1 . V_47 = V_19 -> V_19 . V_73 ;
V_1 . V_30 = V_1 . V_47 -> V_2 ;
V_1 . V_19 = & V_19 -> V_19 ;
V_71 . V_19 = & V_19 -> V_19 ;
V_71 . V_74 = F_47 ( & V_71 ) ;
F_48 ( & V_1 . V_27 ) ;
if ( V_71 . V_74 < 0 ) {
F_22 ( V_1 . V_19 , L_9 ,
V_71 . V_74 ) ;
return V_71 . V_74 ;
}
F_49 ( V_1 . V_19 , L_10 ,
V_71 . V_74 , V_1 . V_30 ) ;
return 0 ;
}
static int F_50 ( struct V_68 * V_19 )
{
return F_51 ( V_71 . V_74 ) ;
}
