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
struct V_1 * V_1 = F_9 ( V_11 , struct V_1 , V_11 ) ;
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
V_16 = F_11 ( V_1 -> V_18 [ V_1 -> V_13 ] ) ;
F_12 ( V_11 , V_16 ) ;
V_1 -> V_13 ++ ;
V_12 = V_11 -> V_19 -> V_20 () ;
} while ( F_13 ( V_11 ) < V_12 );
return V_21 ;
V_15:
F_3 ( V_1 ) ;
V_1 -> V_13 = - 1 ;
F_14 ( & V_1 -> V_22 ) ;
return V_23 ;
}
static int F_15 ( struct V_24 * V_14 , unsigned int * V_25 ,
unsigned int V_26 )
{
struct V_1 * V_1 = V_14 -> V_27 ;
if ( V_26 > V_17 )
return - V_28 ;
memcpy ( V_1 -> V_18 , V_25 , V_26 * sizeof( unsigned int ) ) ;
F_16 ( V_1 -> V_22 , V_1 -> V_13 < 0 ) ;
F_5 ( V_1 ) ;
if ( V_26 < V_17 )
V_1 -> V_18 [ V_26 ] = - 1 ;
V_1 -> V_29 -> V_30 ( V_1 -> V_14 , 50 ) ;
F_1 ( V_1 ) ;
V_1 -> V_13 = 1 ;
F_17 ( & V_1 -> V_11 ,
F_18 ( F_11 ( V_1 -> V_18 [ 0 ] ) ) ,
V_31 ) ;
F_16 ( V_1 -> V_22 , V_1 -> V_13 < 0 ) ;
V_1 -> V_29 -> V_30 ( V_1 -> V_14 , - 1 ) ;
return V_26 ;
}
static int F_19 ( struct V_24 * V_14 )
{
struct V_1 * V_1 = V_14 -> V_27 ;
if ( F_20 ( 1 , & V_1 -> V_32 ) )
return - V_33 ;
V_1 -> V_2 = F_21 ( V_1 -> V_14 , NULL ) ;
if ( F_22 ( V_1 -> V_2 ) ) {
int V_34 = F_23 ( V_1 -> V_2 ) ;
F_24 ( V_1 -> V_14 , L_2 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static void F_25 ( struct V_24 * V_14 )
{
struct V_1 * V_1 = V_14 -> V_27 ;
F_26 ( & V_1 -> V_11 ) ;
F_3 ( V_1 ) ;
F_27 ( V_1 -> V_2 ) ;
F_28 ( 1 , & V_1 -> V_32 ) ;
}
static int F_29 ( struct V_24 * V_14 , T_3 V_4 )
{
struct V_1 * V_1 = V_14 -> V_27 ;
V_1 -> V_8 = V_4 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_14 , T_3 V_35 )
{
struct V_1 * V_1 = V_14 -> V_27 ;
if ( V_35 > 500000 || V_35 < 20000 )
return - V_28 ;
V_1 -> V_7 = V_35 ;
return 0 ;
}
static int F_31 ( struct V_36 * V_14 , T_4 V_37 )
{
if ( F_20 ( 1 , & V_1 . V_32 ) )
return - V_38 ;
F_28 ( 1 , & V_1 . V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_14 )
{
return 0 ;
}
static int F_33 ( struct V_36 * V_14 )
{
struct V_3 * V_2 ;
struct V_24 * V_39 ;
V_1 . V_29 = V_14 -> V_14 . V_40 ;
if ( ! V_1 . V_29 ) {
F_24 ( & V_14 -> V_14 , L_3 ) ;
return - V_41 ;
}
V_2 = F_21 ( & V_14 -> V_14 , NULL ) ;
if ( F_22 ( V_2 ) ) {
int V_42 = F_23 ( V_2 ) ;
if ( V_42 != - V_43 )
F_24 ( & V_14 -> V_14 , L_2 , V_42 ) ;
return V_42 ;
}
V_1 . V_7 = F_6 ( F_34 ( V_2 ) , V_6 ) ;
F_27 ( V_2 ) ;
F_35 ( & V_1 . V_11 , V_44 , V_31 ) ;
V_1 . V_11 . V_45 = F_8 ;
V_1 . V_14 = & V_14 -> V_14 ;
V_39 = F_36 ( & V_14 -> V_14 , V_46 ) ;
if ( ! V_39 )
return - V_47 ;
V_39 -> V_27 = & V_1 ;
V_39 -> V_48 = F_19 ;
V_39 -> V_49 = F_25 ;
V_39 -> V_50 = F_15 ;
V_39 -> V_51 = F_29 ;
V_39 -> V_52 = F_30 ;
V_39 -> V_53 = V_54 ;
V_1 . V_39 = V_39 ;
return F_37 ( & V_14 -> V_14 , V_1 . V_39 ) ;
}
static int F_38 ( struct V_36 * V_14 )
{
return 0 ;
}
