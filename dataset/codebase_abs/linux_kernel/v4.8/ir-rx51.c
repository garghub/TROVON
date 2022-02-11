static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 ) ;
}
static inline void F_3 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_2 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = V_1 -> V_2 ;
int V_4 , V_5 = F_6 ( V_6 , V_1 -> V_7 ) ;
V_4 = F_6 ( V_1 -> V_8 * V_5 , 100 ) ;
F_7 ( V_2 , V_4 , V_5 ) ;
return 0 ;
}
static enum V_9 F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_1 =
F_9 ( V_11 , struct V_1 , V_11 ) ;
T_1 V_12 ;
if ( V_1 -> V_13 < 0 ) {
F_10 ( V_1 -> V_14 ,
L_1 ,
V_1 -> V_13 ) ;
goto V_15;
}
do {
T_2 V_16 ;
if ( V_1 -> V_13 >= V_17 )
goto V_15;
if ( V_1 -> V_18 [ V_1 -> V_13 ] == - 1 )
goto V_15;
if ( V_1 -> V_13 % 2 )
F_3 ( V_1 ) ;
else
F_1 ( V_1 ) ;
V_16 = 1000 * V_1 -> V_18 [ V_1 -> V_13 ] ;
F_11 ( V_11 , V_16 ) ;
V_1 -> V_13 ++ ;
V_12 = V_11 -> V_19 -> V_20 () ;
} while ( F_12 ( V_11 ) < V_12 . V_21 );
return V_22 ;
V_15:
F_3 ( V_1 ) ;
V_1 -> V_13 = - 1 ;
F_13 ( & V_1 -> V_23 ) ;
return V_24 ;
}
static T_3 F_14 ( struct V_25 * V_25 , const char * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
int V_29 , V_30 ;
struct V_1 * V_1 = V_25 -> V_31 ;
if ( V_27 % sizeof( int ) )
return - V_32 ;
V_29 = V_27 / sizeof( int ) ;
if ( ( V_29 > V_17 ) || ( V_29 % 2 == 0 ) )
return - V_32 ;
F_15 ( V_1 -> V_23 , V_1 -> V_13 < 0 ) ;
if ( F_16 ( V_1 -> V_18 , V_26 , V_27 ) )
return - V_33 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
if ( V_1 -> V_18 [ V_30 ] < 0 )
return - V_32 ;
F_5 ( V_1 ) ;
if ( V_29 < V_17 )
V_1 -> V_18 [ V_29 ] = - 1 ;
V_1 -> V_34 -> V_35 ( V_1 -> V_14 , 50 ) ;
F_1 ( V_1 ) ;
V_1 -> V_13 = 1 ;
F_17 ( & V_1 -> V_11 ,
F_18 ( 1000 * V_1 -> V_18 [ 0 ] ) ,
V_36 ) ;
F_15 ( V_1 -> V_23 , V_1 -> V_13 < 0 ) ;
V_1 -> V_34 -> V_35 ( V_1 -> V_14 , - 1 ) ;
return V_27 ;
}
static long F_19 ( struct V_25 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
int V_40 ;
unsigned long V_41 ;
unsigned int V_42 ;
struct V_1 * V_1 = V_37 -> V_31 ;
switch ( V_38 ) {
case V_43 :
V_40 = F_20 ( V_44 , ( unsigned long * ) V_39 ) ;
if ( V_40 )
return V_40 ;
break;
case V_45 :
V_40 = F_21 ( V_41 , ( unsigned long * ) V_39 ) ;
if ( V_40 )
return V_40 ;
if ( V_41 != V_44 )
return - V_46 ;
break;
case V_47 :
V_40 = F_20 ( 0 , ( unsigned long * ) V_39 ) ;
if ( V_40 )
return V_40 ;
break;
case V_48 :
return - V_46 ;
break;
case V_49 :
V_40 = F_21 ( V_42 , ( unsigned int * ) V_39 ) ;
if ( V_40 )
return V_40 ;
if ( V_42 <= 0 || V_42 > 100 ) {
F_22 ( V_1 -> V_14 , L_2 ,
V_42 ) ;
return - V_32 ;
}
V_1 -> V_8 = V_42 ;
break;
case V_50 :
V_40 = F_21 ( V_42 , ( unsigned int * ) V_39 ) ;
if ( V_40 )
return V_40 ;
if ( V_42 > 500000 || V_42 < 20000 ) {
F_22 ( V_1 -> V_14 , L_3 ,
V_42 ) ;
return - V_32 ;
}
V_1 -> V_7 = V_42 ;
break;
case V_51 :
V_40 = F_20 ( V_52 ,
( unsigned long * ) V_39 ) ;
if ( V_40 )
return V_40 ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_23 ( struct V_54 * V_54 , struct V_25 * V_25 )
{
struct V_1 * V_1 = F_24 ( V_25 ) ;
F_25 ( ! V_1 ) ;
V_25 -> V_31 = V_1 ;
if ( F_26 ( 1 , & V_1 -> V_55 ) )
return - V_56 ;
V_1 -> V_2 = F_27 ( V_1 -> V_14 , NULL ) ;
if ( F_28 ( V_1 -> V_2 ) ) {
int V_57 = F_29 ( V_1 -> V_2 ) ;
F_22 ( V_1 -> V_14 , L_4 , V_57 ) ;
return V_57 ;
}
return 0 ;
}
static int F_30 ( struct V_54 * V_54 , struct V_25 * V_25 )
{
struct V_1 * V_1 = V_25 -> V_31 ;
F_31 ( & V_1 -> V_11 ) ;
F_3 ( V_1 ) ;
F_32 ( V_1 -> V_2 ) ;
F_33 ( 1 , & V_1 -> V_55 ) ;
return 0 ;
}
static int F_34 ( struct V_58 * V_14 , T_6 V_59 )
{
if ( F_26 ( 1 , & V_1 . V_55 ) )
return - V_60 ;
F_33 ( 1 , & V_1 . V_55 ) ;
return 0 ;
}
static int F_35 ( struct V_58 * V_14 )
{
return 0 ;
}
static int F_36 ( struct V_58 * V_14 )
{
struct V_3 * V_2 ;
V_61 . V_62 = V_52 ;
V_1 . V_34 = V_14 -> V_14 . V_63 ;
if ( ! V_1 . V_34 ) {
F_22 ( & V_14 -> V_14 , L_5 ) ;
return - V_64 ;
}
V_2 = F_27 ( & V_14 -> V_14 , NULL ) ;
if ( F_28 ( V_2 ) ) {
int V_65 = F_29 ( V_2 ) ;
if ( V_65 != - V_66 )
F_22 ( & V_14 -> V_14 , L_4 , V_65 ) ;
return V_65 ;
}
V_1 . V_7 = F_6 ( F_37 ( V_2 ) , V_6 ) ;
F_32 ( V_2 ) ;
F_38 ( & V_1 . V_11 , V_67 , V_36 ) ;
V_1 . V_11 . V_68 = F_8 ;
V_1 . V_14 = & V_14 -> V_14 ;
V_61 . V_14 = & V_14 -> V_14 ;
V_61 . V_69 = F_39 ( & V_61 ) ;
F_40 ( & V_1 . V_23 ) ;
if ( V_61 . V_69 < 0 ) {
F_22 ( V_1 . V_14 , L_6 ,
V_61 . V_69 ) ;
return V_61 . V_69 ;
}
return 0 ;
}
static int F_41 ( struct V_58 * V_14 )
{
return F_42 ( V_61 . V_69 ) ;
}
