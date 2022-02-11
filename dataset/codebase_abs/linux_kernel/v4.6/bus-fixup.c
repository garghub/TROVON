static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
if ( V_2 -> V_5 -> V_6 . V_7 > 1 )
V_2 -> V_8 = 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
V_2 -> V_8 = 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 -> V_3 . V_11 ) ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
if ( V_10 -> V_12 == V_13 ||
V_10 -> V_12 == V_14 ||
V_10 -> V_12 == V_15 )
V_2 -> V_5 -> V_6 . V_16 = 0x2 ;
V_2 -> V_8 = 1 ;
}
static inline void F_4 ( struct V_1 * V_2 ) {}
static int F_6 ( struct V_17 * V_18 ,
struct F_6 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 V_23 = {
. V_24 = V_25 ,
. V_26 = 1 ,
. V_27 = V_28 ,
} ;
struct V_29 * V_30 = NULL ;
T_1 V_31 ;
int V_32 , V_33 ;
V_21 = V_18 -> V_3 ;
F_7 ( F_8 ( & V_21 -> V_34 ) ) ;
V_33 = F_9 ( V_18 , ( V_35 * ) & V_23 , sizeof( struct V_22 ) , 1 ) ;
if ( V_33 < 0 ) {
F_10 ( V_21 -> V_3 , L_2 ) ;
return V_33 ;
}
V_31 = sizeof( struct V_29 ) +
sizeof( struct F_6 ) ;
V_30 = F_11 ( V_31 , V_36 ) ;
if ( ! V_30 )
return - V_37 ;
V_33 = 0 ;
V_32 = F_12 ( V_18 , ( V_35 * ) V_30 , V_31 ) ;
if ( V_32 < 0 || V_32 < sizeof( struct V_29 ) ) {
F_10 ( V_21 -> V_3 , L_3 ) ;
V_33 = - V_38 ;
goto V_39;
}
memcpy ( V_19 , V_30 -> V_40 , sizeof( struct F_6 ) ) ;
F_13 ( V_21 -> V_3 , L_4 ,
V_19 -> V_41 , V_19 -> V_42 , V_19 -> V_43 ) ;
V_39:
F_14 ( V_30 ) ;
return V_33 ;
}
static const char * F_15 ( struct F_6 * V_19 )
{
if ( V_19 -> V_42 == V_44 ) {
if ( V_19 -> V_43 == V_45 )
return L_5 ;
}
if ( V_19 -> V_42 == V_46 ) {
if ( V_19 -> V_43 == V_47 )
return L_6 ;
}
return NULL ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_17 * V_18 ;
struct V_48 * V_5 = NULL ;
struct F_6 V_19 ;
const char * V_49 = NULL ;
int V_33 ;
V_21 = V_2 -> V_21 ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
F_17 ( & V_21 -> V_34 ) ;
V_18 = F_18 ( V_21 ) ;
if ( F_19 ( V_18 ) ) {
V_33 = F_20 ( V_18 ) ;
V_18 = NULL ;
F_10 ( V_21 -> V_3 , L_7 , V_33 ) ;
goto V_50;
}
V_5 = F_21 ( V_21 , & V_51 ) ;
if ( ! V_5 ) {
V_33 = - V_52 ;
F_10 ( V_21 -> V_3 , L_8 , V_33 ) ;
goto V_50;
}
V_33 = F_22 ( V_18 , V_5 , NULL ) ;
if ( V_33 < 0 ) {
F_10 ( & V_2 -> V_3 , L_9 ,
V_33 ) ;
goto V_50;
}
F_23 ( & V_21 -> V_34 ) ;
V_33 = F_6 ( V_18 , & V_19 ) ;
if ( V_33 )
goto V_53;
V_49 = F_15 ( & V_19 ) ;
if ( ! V_49 ) {
V_33 = - V_54 ;
F_10 ( & V_2 -> V_3 , L_10 ,
V_33 ) ;
goto V_53;
}
F_2 ( V_21 -> V_3 , L_11 , V_49 ) ;
F_24 ( V_2 -> V_55 , V_49 , sizeof( V_2 -> V_55 ) ) ;
V_53:
F_17 ( & V_21 -> V_34 ) ;
if ( F_25 ( V_18 ) < 0 )
F_10 ( V_21 -> V_3 , L_12 ) ;
F_26 ( V_18 , NULL ) ;
V_50:
F_27 ( V_18 ) ;
F_23 ( & V_21 -> V_34 ) ;
F_28 ( V_5 ) ;
F_14 ( V_18 ) ;
if ( V_33 )
V_2 -> V_8 = 0 ;
F_2 ( V_21 -> V_3 , L_13 , V_2 -> V_8 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
const T_2 * V_58 = F_30 ( V_2 -> V_5 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_31 ( V_60 ) ; V_59 ++ ) {
V_57 = & V_60 [ V_59 ] ;
if ( F_32 ( V_57 -> V_58 , V_61 ) == 0 ||
F_32 ( V_57 -> V_58 , * V_58 ) == 0 )
V_57 -> V_62 ( V_2 ) ;
}
}
