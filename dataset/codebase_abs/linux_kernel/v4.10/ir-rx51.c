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
} while ( F_12 ( V_11 ) < V_12 );
return V_21 ;
V_15:
F_3 ( V_1 ) ;
V_1 -> V_13 = - 1 ;
F_13 ( & V_1 -> V_22 ) ;
return V_23 ;
}
static T_3 F_14 ( struct V_24 * V_24 , const char * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
int V_28 , V_29 ;
struct V_1 * V_1 = V_24 -> V_30 ;
if ( V_26 % sizeof( int ) )
return - V_31 ;
V_28 = V_26 / sizeof( int ) ;
if ( ( V_28 > V_17 ) || ( V_28 % 2 == 0 ) )
return - V_31 ;
F_15 ( V_1 -> V_22 , V_1 -> V_13 < 0 ) ;
if ( F_16 ( V_1 -> V_18 , V_25 , V_26 ) )
return - V_32 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
if ( V_1 -> V_18 [ V_29 ] < 0 )
return - V_31 ;
F_5 ( V_1 ) ;
if ( V_28 < V_17 )
V_1 -> V_18 [ V_28 ] = - 1 ;
V_1 -> V_33 -> V_34 ( V_1 -> V_14 , 50 ) ;
F_1 ( V_1 ) ;
V_1 -> V_13 = 1 ;
F_17 ( & V_1 -> V_11 ,
F_18 ( 1000 * V_1 -> V_18 [ 0 ] ) ,
V_35 ) ;
F_15 ( V_1 -> V_22 , V_1 -> V_13 < 0 ) ;
V_1 -> V_33 -> V_34 ( V_1 -> V_14 , - 1 ) ;
return V_26 ;
}
static long F_19 ( struct V_24 * V_36 ,
unsigned int V_37 , unsigned long V_38 )
{
int V_39 ;
unsigned long V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 = V_36 -> V_30 ;
switch ( V_37 ) {
case V_42 :
V_39 = F_20 ( V_43 , ( unsigned long * ) V_38 ) ;
if ( V_39 )
return V_39 ;
break;
case V_44 :
V_39 = F_21 ( V_40 , ( unsigned long * ) V_38 ) ;
if ( V_39 )
return V_39 ;
if ( V_40 != V_43 )
return - V_45 ;
break;
case V_46 :
V_39 = F_20 ( 0 , ( unsigned long * ) V_38 ) ;
if ( V_39 )
return V_39 ;
break;
case V_47 :
return - V_45 ;
break;
case V_48 :
V_39 = F_21 ( V_41 , ( unsigned int * ) V_38 ) ;
if ( V_39 )
return V_39 ;
if ( V_41 <= 0 || V_41 > 100 ) {
F_22 ( V_1 -> V_14 , L_2 ,
V_41 ) ;
return - V_31 ;
}
V_1 -> V_8 = V_41 ;
break;
case V_49 :
V_39 = F_21 ( V_41 , ( unsigned int * ) V_38 ) ;
if ( V_39 )
return V_39 ;
if ( V_41 > 500000 || V_41 < 20000 ) {
F_22 ( V_1 -> V_14 , L_3 ,
V_41 ) ;
return - V_31 ;
}
V_1 -> V_7 = V_41 ;
break;
case V_50 :
V_39 = F_20 ( V_51 ,
( unsigned long * ) V_38 ) ;
if ( V_39 )
return V_39 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_23 ( struct V_53 * V_53 , struct V_24 * V_24 )
{
struct V_1 * V_1 = F_24 ( V_24 ) ;
F_25 ( ! V_1 ) ;
V_24 -> V_30 = V_1 ;
if ( F_26 ( 1 , & V_1 -> V_54 ) )
return - V_55 ;
V_1 -> V_2 = F_27 ( V_1 -> V_14 , NULL ) ;
if ( F_28 ( V_1 -> V_2 ) ) {
int V_56 = F_29 ( V_1 -> V_2 ) ;
F_22 ( V_1 -> V_14 , L_4 , V_56 ) ;
return V_56 ;
}
return 0 ;
}
static int F_30 ( struct V_53 * V_53 , struct V_24 * V_24 )
{
struct V_1 * V_1 = V_24 -> V_30 ;
F_31 ( & V_1 -> V_11 ) ;
F_3 ( V_1 ) ;
F_32 ( V_1 -> V_2 ) ;
F_33 ( 1 , & V_1 -> V_54 ) ;
return 0 ;
}
static int F_34 ( struct V_57 * V_14 , T_6 V_58 )
{
if ( F_26 ( 1 , & V_1 . V_54 ) )
return - V_59 ;
F_33 ( 1 , & V_1 . V_54 ) ;
return 0 ;
}
static int F_35 ( struct V_57 * V_14 )
{
return 0 ;
}
static int F_36 ( struct V_57 * V_14 )
{
struct V_3 * V_2 ;
V_60 . V_61 = V_51 ;
V_1 . V_33 = V_14 -> V_14 . V_62 ;
if ( ! V_1 . V_33 ) {
F_22 ( & V_14 -> V_14 , L_5 ) ;
return - V_63 ;
}
V_2 = F_27 ( & V_14 -> V_14 , NULL ) ;
if ( F_28 ( V_2 ) ) {
int V_64 = F_29 ( V_2 ) ;
if ( V_64 != - V_65 )
F_22 ( & V_14 -> V_14 , L_4 , V_64 ) ;
return V_64 ;
}
V_1 . V_7 = F_6 ( F_37 ( V_2 ) , V_6 ) ;
F_32 ( V_2 ) ;
F_38 ( & V_1 . V_11 , V_66 , V_35 ) ;
V_1 . V_11 . V_67 = F_8 ;
V_1 . V_14 = & V_14 -> V_14 ;
V_60 . V_14 = & V_14 -> V_14 ;
V_60 . V_68 = F_39 ( & V_60 ) ;
F_40 ( & V_1 . V_22 ) ;
if ( V_60 . V_68 < 0 ) {
F_22 ( V_1 . V_14 , L_6 ,
V_60 . V_68 ) ;
return V_60 . V_68 ;
}
return 0 ;
}
static int F_41 ( struct V_57 * V_14 )
{
return F_42 ( V_60 . V_68 ) ;
}
