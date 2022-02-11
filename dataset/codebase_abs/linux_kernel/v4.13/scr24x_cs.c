static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 ,
V_4 ) ;
F_3 ( V_3 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
T_1 V_5 ;
int V_6 = 100 ;
do {
V_5 = F_5 ( V_3 -> V_7 + V_8 ) ;
if ( ! ( V_5 & V_9 ) )
return 0 ;
F_6 ( 20 ) ;
} while ( -- V_6 );
return - V_10 ;
}
static int F_7 ( struct V_11 * V_11 , struct V_12 * V_13 )
{
struct V_2 * V_3 = F_2 ( V_11 -> V_14 ,
struct V_2 , V_15 ) ;
F_8 ( & V_3 -> V_4 ) ;
V_13 -> V_16 = V_3 ;
return F_9 ( V_11 , V_13 ) ;
}
static int F_10 ( struct V_11 * V_11 , struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_16 ;
F_11 ( & V_3 -> V_4 , F_1 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , T_2 V_17 , T_2 V_18 )
{
T_2 V_19 , V_20 ;
int V_21 ;
for ( V_19 = V_17 ; V_19 < V_18 ; V_19 += 5 ) {
F_13 ( V_22 , V_3 -> V_7 + V_8 ) ;
V_21 = F_4 ( V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
for ( V_20 = 0 ; V_20 < 5 && V_19 + V_20 < V_18 ; V_20 ++ )
V_3 -> V_23 [ V_19 + V_20 ] = F_5 ( V_3 -> V_7 + F_14 ( V_20 ) ) ;
}
return 0 ;
}
static T_3 F_15 ( struct V_12 * V_13 , char T_4 * V_23 , T_2 V_24 ,
T_5 * V_25 )
{
struct V_2 * V_3 = V_13 -> V_16 ;
int V_21 ;
int V_26 ;
if ( V_24 < V_27 )
return - V_28 ;
if ( F_16 ( & V_3 -> V_29 ) )
return - V_30 ;
if ( ! V_3 -> V_3 ) {
V_21 = - V_31 ;
goto V_32;
}
V_21 = F_4 ( V_3 ) ;
if ( V_21 < 0 )
goto V_32;
V_26 = V_27 ;
V_21 = F_12 ( V_3 , 0 , V_26 ) ;
if ( V_21 < 0 )
goto V_32;
V_26 += F_17 ( * ( V_33 * ) ( & V_3 -> V_23 [ V_34 ] ) ) ;
if ( V_26 > sizeof( V_3 -> V_23 ) ) {
V_21 = - V_10 ;
goto V_32;
}
V_21 = F_12 ( V_3 , V_27 , V_26 ) ;
if ( V_21 < 0 )
goto V_32;
if ( V_26 < V_24 )
V_24 = V_26 ;
if ( F_18 ( V_23 , V_3 -> V_23 , V_24 ) ) {
V_21 = - V_35 ;
goto V_32;
}
V_21 = V_24 ;
V_32:
F_19 ( & V_3 -> V_29 ) ;
return V_21 ;
}
static T_3 F_20 ( struct V_12 * V_13 , const char T_4 * V_23 ,
T_2 V_24 , T_5 * V_25 )
{
struct V_2 * V_3 = V_13 -> V_16 ;
T_2 V_19 , V_20 ;
int V_21 ;
if ( F_16 ( & V_3 -> V_29 ) )
return - V_30 ;
if ( ! V_3 -> V_3 ) {
V_21 = - V_31 ;
goto V_32;
}
if ( V_24 > sizeof( V_3 -> V_23 ) ) {
V_21 = - V_28 ;
goto V_32;
}
if ( F_21 ( V_3 -> V_23 , V_23 , V_24 ) ) {
V_21 = - V_35 ;
goto V_32;
}
V_21 = F_4 ( V_3 ) ;
if ( V_21 < 0 )
goto V_32;
F_13 ( V_36 , V_3 -> V_7 + V_8 ) ;
V_21 = F_4 ( V_3 ) ;
if ( V_21 < 0 )
goto V_32;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 += 5 ) {
for ( V_20 = 0 ; V_20 < 5 && V_19 + V_20 < V_24 ; V_20 ++ )
F_13 ( V_3 -> V_23 [ V_19 + V_20 ] , V_3 -> V_7 + F_14 ( V_20 ) ) ;
F_13 ( V_37 , V_3 -> V_7 + V_8 ) ;
V_21 = F_4 ( V_3 ) ;
if ( V_21 < 0 )
goto V_32;
}
V_21 = V_24 ;
V_32:
F_19 ( & V_3 -> V_29 ) ;
return V_21 ;
}
static int F_22 ( struct V_38 * V_39 , void * V_40 )
{
if ( F_23 ( V_39 -> V_41 [ V_42 ] ) != 0x11 )
return - V_31 ;
return F_24 ( V_39 ) ;
}
static int F_25 ( struct V_38 * V_39 )
{
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_26 ( sizeof( * V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_44 ;
V_3 -> V_45 = F_27 ( V_46 , V_47 ) ;
if ( V_3 -> V_45 >= V_47 ) {
V_21 = - V_48 ;
goto V_49;
}
F_28 ( & V_3 -> V_29 ) ;
F_29 ( & V_3 -> V_4 ) ;
V_39 -> V_50 = V_3 ;
V_39 -> V_51 |= V_52 | V_53 ;
V_21 = F_30 ( V_39 , F_22 , NULL ) ;
if ( V_21 < 0 )
goto V_49;
V_3 -> V_3 = & V_39 -> V_3 ;
V_3 -> V_7 = F_31 ( & V_39 -> V_3 ,
V_39 -> V_41 [ V_42 ] -> V_54 ,
F_23 ( V_39 -> V_41 [ V_42 ] ) ) ;
if ( ! V_3 -> V_7 ) {
V_21 = - V_10 ;
goto V_49;
}
F_32 ( & V_3 -> V_15 , & V_55 ) ;
V_3 -> V_15 . V_56 = V_57 ;
V_3 -> V_15 . V_58 = & V_55 ;
V_21 = F_33 ( & V_3 -> V_15 , F_34 ( F_35 ( V_59 ) , V_3 -> V_45 ) , 1 ) ;
if ( V_21 < 0 )
goto V_49;
V_21 = F_36 ( V_39 ) ;
if ( V_21 < 0 ) {
F_37 ( V_39 ) ;
goto V_49;
}
F_38 ( V_60 , NULL , F_34 ( F_35 ( V_59 ) , V_3 -> V_45 ) ,
NULL , L_1 , V_3 -> V_45 ) ;
F_39 ( & V_39 -> V_3 , L_2 ) ;
return 0 ;
V_49:
if ( V_3 -> V_45 < V_47 )
F_40 ( V_3 -> V_45 , V_46 ) ;
F_3 ( V_3 ) ;
return V_21 ;
}
static void F_41 ( struct V_38 * V_39 )
{
struct V_2 * V_3 = (struct V_2 * ) V_39 -> V_50 ;
F_42 ( V_60 , F_34 ( F_35 ( V_59 ) , V_3 -> V_45 ) ) ;
F_43 ( & V_3 -> V_29 ) ;
F_37 ( V_39 ) ;
F_44 ( & V_3 -> V_15 ) ;
F_40 ( V_3 -> V_45 , V_46 ) ;
V_3 -> V_3 = NULL ;
F_19 ( & V_3 -> V_29 ) ;
F_11 ( & V_3 -> V_4 , F_1 ) ;
}
static int T_6 F_45 ( void )
{
int V_21 ;
V_60 = F_46 ( V_57 , L_3 ) ;
if ( F_47 ( V_60 ) )
return F_48 ( V_60 ) ;
V_21 = F_49 ( & V_59 , 0 , V_47 , L_3 ) ;
if ( V_21 < 0 ) {
F_50 ( V_60 ) ;
return V_21 ;
}
V_21 = F_51 ( & V_61 ) ;
if ( V_21 < 0 ) {
F_52 ( V_59 , V_47 ) ;
F_50 ( V_60 ) ;
}
return V_21 ;
}
static void T_7 F_53 ( void )
{
F_54 ( & V_61 ) ;
F_52 ( V_59 , V_47 ) ;
F_50 ( V_60 ) ;
}
