int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
bool V_5 = false ;
int V_6 = - V_7 ;
if ( V_1 -> V_8 -> V_9 )
V_5 = true ;
else if ( ! V_1 -> V_8 -> V_10 )
goto V_11;
V_6 = F_3 ( V_1 , V_12 ) ;
if ( V_6 )
goto V_11;
if ( V_5 ) {
F_4 ( V_4 ) ;
} else {
V_6 = F_5 ( & V_4 -> V_13 ) ;
if ( V_6 )
goto V_11;
}
V_6 = - V_14 ;
if ( ! F_6 ( V_4 ) ) {
V_3 -> V_15 = V_1 -> V_16 ;
if ( V_5 )
V_6 = V_1 -> V_8 -> V_9 ( V_1 , V_3 ) ;
else
V_6 = V_1 -> V_8 -> V_10 ( V_1 , V_3 ) ;
V_1 -> V_16 = V_3 -> V_15 ;
F_7 ( V_1 ) ;
F_8 ( V_1 ) ;
}
if ( V_5 )
F_9 ( V_4 ) ;
else
F_10 ( V_4 ) ;
V_11:
return V_6 ;
}
static int F_11 ( struct V_2 * V_3 , const char * V_17 , int V_18 ,
T_1 V_19 , T_2 V_20 , unsigned int V_21 )
{
struct V_22 * V_23 =
F_12 ( V_3 , struct V_22 , V_3 ) ;
struct V_24 T_3 * V_25 ;
unsigned long V_26 ;
if ( V_23 -> V_27 )
return - V_28 ;
V_26 = V_20 ;
if ( sizeof( V_26 ) < sizeof( V_20 ) && V_26 != V_20 ) {
V_23 -> V_27 = - V_29 ;
return - V_29 ;
}
V_23 -> V_27 ++ ;
V_25 = V_23 -> V_25 ;
if ( ! F_13 ( V_30 , V_25 ,
( unsigned long ) ( V_25 -> V_31 + V_18 + 1 ) -
( unsigned long ) V_25 ) )
goto V_32;
if ( F_14 ( V_26 , & V_25 -> V_26 ) ||
F_14 ( V_19 , & V_25 -> V_33 ) ||
F_14 ( V_18 , & V_25 -> V_34 ) ||
F_15 ( V_25 -> V_31 , V_17 , V_18 ) ||
F_14 ( 0 , V_25 -> V_31 + V_18 ) )
goto V_32;
return 0 ;
V_32:
V_23 -> V_27 = - V_35 ;
return - V_35 ;
}
static int F_16 ( struct V_2 * V_3 , const char * V_17 , int V_18 ,
T_1 V_19 , T_2 V_20 , unsigned int V_21 )
{
struct V_36 T_3 * V_25 ;
struct V_37 * V_23 =
F_12 ( V_3 , struct V_37 , V_3 ) ;
unsigned long V_26 ;
int V_38 = F_17 ( F_18 ( struct V_36 , V_31 ) + V_18 + 2 ,
sizeof( long ) ) ;
V_23 -> error = - V_28 ;
if ( V_38 > V_23 -> V_39 )
return - V_28 ;
V_26 = V_20 ;
if ( sizeof( V_26 ) < sizeof( V_20 ) && V_26 != V_20 ) {
V_23 -> error = - V_29 ;
return - V_29 ;
}
V_25 = V_23 -> V_40 ;
if ( V_25 ) {
if ( F_19 ( V_41 ) )
return - V_42 ;
if ( F_14 ( V_19 , & V_25 -> V_43 ) )
goto V_32;
}
V_25 = V_23 -> V_44 ;
if ( F_14 ( V_26 , & V_25 -> V_26 ) )
goto V_32;
if ( F_14 ( V_38 , & V_25 -> V_45 ) )
goto V_32;
if ( F_20 ( V_25 -> V_31 , V_17 , V_18 ) )
goto V_32;
if ( F_14 ( 0 , V_25 -> V_31 + V_18 ) )
goto V_32;
if ( F_14 ( V_21 , ( char T_3 * ) V_25 + V_38 - 1 ) )
goto V_32;
V_23 -> V_40 = V_25 ;
V_25 = ( void T_3 * ) V_25 + V_38 ;
V_23 -> V_44 = V_25 ;
V_23 -> V_39 -= V_38 ;
return 0 ;
V_32:
V_23 -> error = - V_35 ;
return - V_35 ;
}
static int F_21 ( struct V_2 * V_3 , const char * V_17 , int V_18 ,
T_1 V_19 , T_2 V_20 , unsigned int V_21 )
{
struct V_46 T_3 * V_25 ;
struct V_47 * V_23 =
F_12 ( V_3 , struct V_47 , V_3 ) ;
int V_38 = F_17 ( F_18 ( struct V_46 , V_31 ) + V_18 + 1 ,
sizeof( T_2 ) ) ;
V_23 -> error = - V_28 ;
if ( V_38 > V_23 -> V_39 )
return - V_28 ;
V_25 = V_23 -> V_40 ;
if ( V_25 ) {
if ( F_19 ( V_41 ) )
return - V_42 ;
if ( F_14 ( V_19 , & V_25 -> V_43 ) )
goto V_32;
}
V_25 = V_23 -> V_44 ;
if ( F_14 ( V_20 , & V_25 -> V_26 ) )
goto V_32;
if ( F_14 ( 0 , & V_25 -> V_43 ) )
goto V_32;
if ( F_14 ( V_38 , & V_25 -> V_45 ) )
goto V_32;
if ( F_14 ( V_21 , & V_25 -> V_21 ) )
goto V_32;
if ( F_20 ( V_25 -> V_31 , V_17 , V_18 ) )
goto V_32;
if ( F_14 ( 0 , V_25 -> V_31 + V_18 ) )
goto V_32;
V_23 -> V_40 = V_25 ;
V_25 = ( void T_3 * ) V_25 + V_38 ;
V_23 -> V_44 = V_25 ;
V_23 -> V_39 -= V_38 ;
return 0 ;
V_32:
V_23 -> error = - V_35 ;
return - V_35 ;
}
static int F_22 ( struct V_2 * V_3 , const char * V_17 ,
int V_18 , T_1 V_19 , T_2 V_20 ,
unsigned int V_21 )
{
struct V_48 * V_23 =
F_12 ( V_3 , struct V_48 , V_3 ) ;
struct V_49 T_3 * V_25 ;
T_4 V_26 ;
if ( V_23 -> V_27 )
return - V_28 ;
V_26 = V_20 ;
if ( sizeof( V_26 ) < sizeof( V_20 ) && V_26 != V_20 ) {
V_23 -> V_27 = - V_29 ;
return - V_29 ;
}
V_23 -> V_27 ++ ;
V_25 = V_23 -> V_25 ;
if ( ! F_13 ( V_30 , V_25 ,
( unsigned long ) ( V_25 -> V_31 + V_18 + 1 ) -
( unsigned long ) V_25 ) )
goto V_32;
if ( F_14 ( V_26 , & V_25 -> V_26 ) ||
F_14 ( V_19 , & V_25 -> V_33 ) ||
F_14 ( V_18 , & V_25 -> V_34 ) ||
F_15 ( V_25 -> V_31 , V_17 , V_18 ) ||
F_14 ( 0 , V_25 -> V_31 + V_18 ) )
goto V_32;
return 0 ;
V_32:
V_23 -> V_27 = - V_35 ;
return - V_35 ;
}
static int F_23 ( struct V_2 * V_3 , const char * V_17 , int V_18 ,
T_1 V_19 , T_2 V_20 , unsigned int V_21 )
{
struct V_50 T_3 * V_25 ;
struct V_51 * V_23 =
F_12 ( V_3 , struct V_51 , V_3 ) ;
T_4 V_26 ;
int V_38 = F_17 ( F_18 ( struct V_50 , V_31 ) +
V_18 + 2 , sizeof( V_52 ) ) ;
V_23 -> error = - V_28 ;
if ( V_38 > V_23 -> V_39 )
return - V_28 ;
V_26 = V_20 ;
if ( sizeof( V_26 ) < sizeof( V_20 ) && V_26 != V_20 ) {
V_23 -> error = - V_29 ;
return - V_29 ;
}
V_25 = V_23 -> V_40 ;
if ( V_25 ) {
if ( F_19 ( V_41 ) )
return - V_42 ;
if ( F_14 ( V_19 , & V_25 -> V_43 ) )
goto V_32;
}
V_25 = V_23 -> V_44 ;
if ( F_14 ( V_26 , & V_25 -> V_26 ) )
goto V_32;
if ( F_14 ( V_38 , & V_25 -> V_45 ) )
goto V_32;
if ( F_20 ( V_25 -> V_31 , V_17 , V_18 ) )
goto V_32;
if ( F_14 ( 0 , V_25 -> V_31 + V_18 ) )
goto V_32;
if ( F_14 ( V_21 , ( char T_3 * ) V_25 + V_38 - 1 ) )
goto V_32;
V_23 -> V_40 = V_25 ;
V_25 = ( void T_3 * ) V_25 + V_38 ;
V_23 -> V_44 = V_25 ;
V_23 -> V_39 -= V_38 ;
return 0 ;
V_32:
V_23 -> error = - V_35 ;
return - V_35 ;
}
