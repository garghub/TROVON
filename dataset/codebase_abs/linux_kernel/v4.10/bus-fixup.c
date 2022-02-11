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
int V_9 ;
const T_1 V_10 = sizeof( struct V_11 ) +
sizeof( struct V_12 ) +
sizeof( struct V_13 ) ;
T_1 V_14 = 8 ;
char V_15 [ V_10 ] ;
struct V_16 * V_17 ;
struct V_12 * V_18 ;
struct V_13 * V_19 ;
unsigned int V_20 = V_21 | V_22 ;
memset ( V_15 , 0 , V_10 ) ;
V_17 = (struct V_16 * ) V_15 ;
V_17 -> V_23 . V_24 = V_25 ;
V_17 -> V_23 . V_26 = V_27 ;
V_18 = (struct V_12 * ) V_17 -> V_28 ;
V_18 -> V_29 . V_30 = 0x0 ;
V_18 -> V_29 . V_31 = V_32 ;
V_18 -> V_33 = sizeof( * V_19 ) ;
V_19 = (struct V_13 * ) V_18 -> V_28 ;
V_19 -> V_34 = V_35 ;
V_9 = F_5 ( V_2 -> V_36 , V_15 , V_10 , V_20 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_2 -> V_36 , V_15 , V_14 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! V_2 -> V_37 -> V_38 )
return;
V_9 = F_8 ( V_2 ) ;
if ( V_9 )
return;
V_9 = F_4 ( V_2 ) ;
if ( V_9 )
F_9 ( & V_2 -> V_3 , L_2 , V_9 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_12 ( V_2 -> V_3 . V_41 ) ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
if ( V_40 -> V_42 == V_43 ||
V_40 -> V_42 == V_44 ||
V_40 -> V_42 == V_45 )
V_2 -> V_5 -> V_6 . V_46 = 0x2 ;
V_2 -> V_8 = 1 ;
}
static inline void F_11 ( struct V_1 * V_2 ) {}
static int F_13 ( struct V_47 * V_36 ,
struct F_13 * V_48 )
{
struct V_49 * V_37 ;
struct V_50 V_51 = {
. V_26 = V_52 ,
. V_53 = 1 ,
. V_54 = V_55 ,
} ;
struct V_56 * V_57 = NULL ;
T_1 V_58 ;
int V_59 , V_9 ;
V_37 = V_36 -> V_3 ;
F_14 ( F_15 ( & V_37 -> V_60 ) ) ;
V_9 = F_5 ( V_36 , ( V_61 * ) & V_51 , sizeof( struct V_50 ) ,
V_21 ) ;
if ( V_9 < 0 ) {
F_9 ( V_37 -> V_3 , L_3 ) ;
return V_9 ;
}
V_58 = sizeof( struct V_56 ) +
sizeof( struct F_13 ) ;
V_57 = F_16 ( V_58 , V_62 ) ;
if ( ! V_57 )
return - V_63 ;
V_9 = 0 ;
V_59 = F_6 ( V_36 , ( V_61 * ) V_57 , V_58 , 0 ) ;
if ( V_59 < V_58 ) {
F_9 ( V_37 -> V_3 , L_4 ) ;
V_9 = - V_64 ;
goto V_65;
}
memcpy ( V_48 , V_57 -> V_28 , sizeof( struct F_13 ) ) ;
F_17 ( V_37 -> V_3 , L_5 ,
V_48 -> V_66 , V_48 -> V_67 , V_48 -> V_68 ) ;
V_65:
F_18 ( V_57 ) ;
return V_9 ;
}
static const char * F_19 ( struct F_13 * V_48 )
{
if ( V_48 -> V_67 == V_69 ) {
if ( V_48 -> V_68 == V_70 )
return L_6 ;
}
if ( V_48 -> V_67 == V_71 ) {
if ( V_48 -> V_68 == V_72 )
return L_7 ;
}
return NULL ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_49 * V_37 ;
struct V_47 * V_36 ;
struct V_73 * V_5 = NULL ;
struct F_13 V_48 ;
const char * V_74 = NULL ;
int V_9 ;
V_37 = V_2 -> V_37 ;
F_2 ( & V_2 -> V_3 , L_1 , V_4 ) ;
F_21 ( & V_37 -> V_60 ) ;
V_36 = F_22 ( V_37 ) ;
if ( F_23 ( V_36 ) ) {
V_9 = F_24 ( V_36 ) ;
V_36 = NULL ;
F_9 ( V_37 -> V_3 , L_8 , V_9 ) ;
goto V_75;
}
V_5 = F_25 ( V_37 , & V_76 ) ;
if ( ! V_5 ) {
V_9 = - V_77 ;
F_9 ( V_37 -> V_3 , L_9 , V_9 ) ;
goto V_75;
}
V_9 = F_26 ( V_36 , V_5 , NULL ) ;
if ( V_9 < 0 ) {
F_9 ( & V_2 -> V_3 , L_10 ,
V_9 ) ;
goto V_75;
}
F_27 ( & V_37 -> V_60 ) ;
V_9 = F_13 ( V_36 , & V_48 ) ;
if ( V_9 )
goto V_78;
V_74 = F_19 ( & V_48 ) ;
if ( ! V_74 ) {
V_9 = - V_79 ;
F_9 ( & V_2 -> V_3 , L_11 ,
V_9 ) ;
goto V_78;
}
F_2 ( V_37 -> V_3 , L_12 , V_74 ) ;
F_28 ( V_2 -> V_80 , V_74 , sizeof( V_2 -> V_80 ) ) ;
V_78:
F_21 ( & V_37 -> V_60 ) ;
if ( F_29 ( V_36 ) < 0 )
F_9 ( V_37 -> V_3 , L_13 ) ;
F_30 ( V_36 , NULL ) ;
V_75:
F_31 ( V_36 ) ;
F_27 ( & V_37 -> V_60 ) ;
F_32 ( V_5 ) ;
F_18 ( V_36 ) ;
if ( V_9 )
V_2 -> V_8 = 0 ;
F_2 ( V_37 -> V_3 , L_14 , V_2 -> V_8 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
const T_2 * V_83 = F_34 ( V_2 -> V_5 ) ;
int V_84 ;
for ( V_84 = 0 ; V_84 < F_35 ( V_85 ) ; V_84 ++ ) {
V_82 = & V_85 [ V_84 ] ;
if ( F_36 ( V_82 -> V_83 , V_86 ) == 0 ||
F_36 ( V_82 -> V_83 , * V_83 ) == 0 )
V_82 -> V_87 ( V_2 ) ;
}
}
