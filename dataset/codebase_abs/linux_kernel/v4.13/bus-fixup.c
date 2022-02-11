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
static int F_4 ( struct V_1 * V_2 )
{
const T_1 V_9 = V_10 ;
char V_11 [ V_10 ] ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned int V_18 = V_19 | V_20 ;
memset ( V_11 , 0 , V_9 ) ;
V_13 = (struct V_12 * ) V_11 ;
V_13 -> V_21 . V_22 = V_23 ;
V_13 -> V_21 . V_24 = V_25 ;
V_15 = (struct V_14 * ) V_13 -> V_26 ;
V_15 -> V_27 . V_28 = 0x0 ;
V_15 -> V_27 . V_29 = V_30 ;
V_15 -> V_31 = sizeof( * V_17 ) ;
V_17 = (struct V_16 * ) V_15 -> V_26 ;
V_17 -> V_32 = V_33 ;
return F_5 ( V_2 -> V_34 , V_11 , V_9 , V_18 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! V_2 -> V_36 -> V_37 )
return;
V_35 = F_7 ( V_2 ) ;
if ( V_35 )
return;
V_35 = F_4 ( V_2 ) ;
if ( V_35 < 0 )
F_8 ( & V_2 -> V_3 , L_2 , V_35 ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_3 . V_40 ) ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
if ( V_39 -> V_41 == V_42 ||
V_39 -> V_41 == V_43 ||
V_39 -> V_41 == V_44 )
V_2 -> V_5 -> V_6 . V_45 = 0x2 ;
V_2 -> V_8 = 1 ;
}
static inline void F_10 ( struct V_1 * V_2 ) {}
static int F_12 ( struct V_46 * V_34 ,
struct F_12 * V_47 )
{
struct V_48 * V_36 ;
struct V_49 V_50 = {
. V_24 = V_51 ,
. V_52 = 1 ,
. V_53 = V_54 ,
} ;
struct V_55 * V_56 = NULL ;
T_1 V_57 ;
int V_58 , V_35 ;
V_36 = V_34 -> V_3 ;
F_13 ( F_14 ( & V_36 -> V_59 ) ) ;
V_35 = F_5 ( V_34 , ( V_60 * ) & V_50 , sizeof( struct V_49 ) ,
V_19 ) ;
if ( V_35 < 0 ) {
F_8 ( V_36 -> V_3 , L_3 ) ;
return V_35 ;
}
V_57 = sizeof( struct V_55 ) +
sizeof( struct F_12 ) ;
V_56 = F_15 ( V_57 , V_61 ) ;
if ( ! V_56 )
return - V_62 ;
V_35 = 0 ;
V_58 = F_16 ( V_34 , ( V_60 * ) V_56 , V_57 , 0 ) ;
if ( V_58 < V_57 ) {
F_8 ( V_36 -> V_3 , L_4 ) ;
V_35 = - V_63 ;
goto V_64;
}
memcpy ( V_47 , V_56 -> V_26 , sizeof( struct F_12 ) ) ;
F_17 ( V_36 -> V_3 , L_5 ,
V_47 -> V_65 , V_47 -> V_66 , V_47 -> V_67 ) ;
V_64:
F_18 ( V_56 ) ;
return V_35 ;
}
static const char * F_19 ( struct F_12 * V_47 )
{
if ( V_47 -> V_66 == V_68 ) {
if ( V_47 -> V_67 == V_69 )
return L_6 ;
}
if ( V_47 -> V_66 == V_70 ) {
if ( V_47 -> V_67 == V_71 )
return L_7 ;
}
return NULL ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_48 * V_36 ;
struct V_46 * V_34 ;
struct V_72 * V_5 = NULL ;
struct F_12 V_47 ;
const char * V_73 = NULL ;
int V_35 ;
V_36 = V_2 -> V_36 ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
F_21 ( & V_36 -> V_59 ) ;
V_34 = F_22 ( V_36 ) ;
if ( F_23 ( V_34 ) ) {
V_35 = F_24 ( V_34 ) ;
V_34 = NULL ;
F_8 ( V_36 -> V_3 , L_8 , V_35 ) ;
goto V_74;
}
V_5 = F_25 ( V_36 , & V_75 ) ;
if ( ! V_5 ) {
V_35 = - V_76 ;
F_8 ( V_36 -> V_3 , L_9 , V_35 ) ;
goto V_74;
}
V_35 = F_26 ( V_34 , V_5 , NULL ) ;
if ( V_35 < 0 ) {
F_8 ( & V_2 -> V_3 , L_10 ,
V_35 ) ;
goto V_74;
}
F_27 ( & V_36 -> V_59 ) ;
V_35 = F_12 ( V_34 , & V_47 ) ;
if ( V_35 )
goto V_77;
V_73 = F_19 ( & V_47 ) ;
if ( ! V_73 ) {
V_35 = - V_78 ;
F_8 ( & V_2 -> V_3 , L_11 ,
V_35 ) ;
goto V_77;
}
F_2 ( V_36 -> V_3 , L_12 , V_73 ) ;
F_28 ( V_2 -> V_79 , V_73 , sizeof( V_2 -> V_79 ) ) ;
V_77:
F_21 ( & V_36 -> V_59 ) ;
if ( F_29 ( V_34 ) < 0 )
F_8 ( V_36 -> V_3 , L_13 ) ;
F_30 ( V_34 , NULL ) ;
V_74:
F_31 ( V_34 ) ;
F_27 ( & V_36 -> V_59 ) ;
F_32 ( V_5 ) ;
F_18 ( V_34 ) ;
if ( V_35 )
V_2 -> V_8 = 0 ;
F_2 ( V_36 -> V_3 , L_14 , V_2 -> V_8 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
const T_2 * V_82 = F_34 ( V_2 -> V_5 ) ;
int V_83 ;
for ( V_83 = 0 ; V_83 < F_35 ( V_84 ) ; V_83 ++ ) {
V_81 = & V_84 [ V_83 ] ;
if ( F_36 ( V_81 -> V_82 , V_85 ) == 0 ||
F_36 ( V_81 -> V_82 , * V_82 ) == 0 )
V_81 -> V_86 ( V_2 ) ;
}
}
