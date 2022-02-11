static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ,
V_4 , F_3 ( V_2 -> V_5 ) ) ;
if ( V_2 -> V_5 -> V_6 . V_7 > 1 )
V_2 -> V_8 = 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ,
V_4 , F_3 ( V_2 -> V_5 ) ) ;
V_2 -> V_8 = 0 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct F_5 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 V_15 = {
. V_16 = V_17 ,
. V_18 = 1 ,
. V_19 = V_20 ,
} ;
struct V_21 * V_22 = NULL ;
T_1 V_23 ;
int V_24 , V_25 ;
V_13 = V_10 -> V_3 ;
F_6 ( F_7 ( & V_13 -> V_26 ) ) ;
V_25 = F_8 ( V_10 , ( V_27 * ) & V_15 , sizeof( struct V_14 ) , 1 ) ;
if ( V_25 < 0 ) {
F_9 ( V_13 -> V_3 , L_2 ) ;
return V_25 ;
}
V_23 = sizeof( struct V_21 ) +
sizeof( struct F_5 ) ;
V_22 = F_10 ( V_23 , V_28 ) ;
if ( ! V_22 )
return - V_29 ;
V_25 = 0 ;
V_24 = F_11 ( V_10 , ( V_27 * ) V_22 , V_23 ) ;
if ( V_24 < 0 || V_24 < sizeof( struct V_21 ) ) {
F_9 ( V_13 -> V_3 , L_3 ) ;
V_25 = - V_30 ;
goto V_31;
}
memcpy ( V_11 , V_22 -> V_32 , sizeof( struct F_5 ) ) ;
F_12 ( V_13 -> V_3 , L_4 ,
V_11 -> V_33 , V_11 -> V_34 , V_11 -> V_35 ) ;
V_31:
F_13 ( V_22 ) ;
return V_25 ;
}
static const char * F_14 ( struct F_5 * V_11 )
{
if ( V_11 -> V_34 == V_36 ) {
if ( V_11 -> V_35 == V_37 )
return L_5 ;
}
if ( V_11 -> V_34 == V_38 ) {
if ( V_11 -> V_35 == V_39 )
return L_6 ;
}
return NULL ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_40 * V_5 = NULL ;
struct F_5 V_11 ;
const char * V_41 = NULL ;
int V_25 ;
V_13 = V_2 -> V_13 ;
F_2 ( V_13 -> V_3 , L_7 ,
V_4 , F_3 ( V_2 -> V_5 ) , V_2 -> V_8 ) ;
F_16 ( & V_13 -> V_26 ) ;
V_10 = F_17 ( V_13 , V_42 ) ;
if ( F_18 ( V_10 ) ) {
V_25 = F_19 ( V_10 ) ;
V_10 = NULL ;
F_9 ( V_13 -> V_3 , L_8 , V_25 ) ;
goto V_43;
}
V_5 = F_20 ( V_13 , & V_44 ) ;
if ( ! V_5 ) {
V_25 = - V_45 ;
F_9 ( V_13 -> V_3 , L_9 , V_25 ) ;
goto V_43;
}
V_25 = F_21 ( V_10 , V_5 , NULL ) ;
if ( V_25 < 0 ) {
F_9 ( & V_2 -> V_3 , L_10 ,
V_25 ) ;
goto V_43;
}
F_22 ( & V_13 -> V_26 ) ;
V_25 = F_5 ( V_10 , & V_11 ) ;
if ( V_25 )
goto V_46;
V_41 = F_14 ( & V_11 ) ;
if ( ! V_41 ) {
V_25 = - V_47 ;
F_9 ( & V_2 -> V_3 , L_11 ,
V_25 ) ;
goto V_46;
}
F_2 ( V_13 -> V_3 , L_12 , V_41 ) ;
F_23 ( V_2 -> V_48 , V_41 , sizeof( V_2 -> V_48 ) ) ;
V_46:
F_16 ( & V_13 -> V_26 ) ;
if ( F_24 ( V_10 ) < 0 )
F_9 ( V_13 -> V_3 , L_13 ) ;
F_25 ( V_10 , NULL ) ;
V_43:
F_26 ( V_10 ) ;
F_22 ( & V_13 -> V_26 ) ;
F_27 ( V_5 ) ;
F_13 ( V_10 ) ;
if ( V_25 )
V_2 -> V_8 = 0 ;
F_2 ( V_13 -> V_3 , L_14 , V_2 -> V_8 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
const T_2 * V_51 = F_3 ( V_2 -> V_5 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < F_29 ( V_53 ) ; V_52 ++ ) {
V_50 = & V_53 [ V_52 ] ;
if ( F_30 ( V_50 -> V_51 , V_54 ) == 0 ||
F_30 ( V_50 -> V_51 , * V_51 ) == 0 )
V_50 -> V_55 ( V_2 ) ;
}
}
