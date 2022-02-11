static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_1 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_10 ) ;
}
static T_2
F_4 ( int V_11 , void * V_2 )
{
struct V_6 * V_1 = V_2 ;
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 ) ;
F_5 ( & V_1 -> V_2 , L_2 ) ;
V_8 -> V_10 ++ ;
return V_12 ;
}
static T_3
F_6 ( struct V_13 * V_14 , struct V_15 * V_15 )
{
struct V_7 * V_8 = V_15 -> V_16 -> V_17 ;
unsigned long V_18 , V_19 ;
void * V_20 ;
struct V_21 V_22 ;
unsigned int V_23 ;
struct V_24 V_25 ;
V_18 = V_8 -> V_26 + ( V_15 -> V_27 . V_28 <<
V_29 ) ;
V_19 = V_8 -> V_26 + V_8 -> V_30 ;
V_23 = 0 ;
F_7 (vec, bio, iter) {
if ( F_8 ( V_18 + V_22 . V_31 > V_19 ) ) {
F_9 ( V_15 ) ;
return V_32 ;
}
V_20 = F_10 ( V_22 . V_33 ) + V_22 . V_34 ;
if ( F_11 ( V_15 ) == V_35 )
memcpy ( V_20 , ( void * ) V_18 , V_22 . V_31 ) ;
else
memcpy ( ( void * ) V_18 , V_20 , V_22 . V_31 ) ;
V_18 += V_22 . V_31 ;
V_23 += V_22 . V_31 ;
}
F_12 ( V_15 ) ;
return V_32 ;
}
static long
F_13 ( struct V_7 * V_8 , T_4 V_36 , long V_37 ,
void * * V_38 , T_5 * V_39 )
{
T_6 V_40 = V_36 * V_41 ;
* V_38 = ( void * ) V_8 -> V_26 + V_40 ;
* V_39 = F_14 ( V_8 -> V_42 + V_40 , V_43 ) ;
return ( V_8 -> V_30 - V_40 ) / V_41 ;
}
static long
F_15 ( struct V_44 * V_45 , T_4 V_36 , long V_37 ,
void * * V_38 , T_5 * V_39 )
{
struct V_7 * V_8 = F_16 ( V_45 ) ;
return F_13 ( V_8 , V_36 , V_37 , V_38 , V_39 ) ;
}
static T_7 F_17 ( struct V_44 * V_45 , T_4 V_36 ,
void * V_46 , T_7 V_47 , struct V_48 * V_49 )
{
return F_18 ( V_46 , V_47 , V_49 ) ;
}
static int F_19 ( struct V_6 * V_1 )
{
static int V_50 = - 1 ;
struct V_7 * V_8 ;
struct V_51 V_51 ;
int V_52 = 0 ;
V_50 ++ ;
F_20 ( & V_1 -> V_2 , L_3 ,
V_1 -> V_2 . V_53 ) ;
V_8 = F_21 ( sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
V_1 -> V_2 . V_9 = V_8 ;
V_8 -> V_1 = V_1 ;
if ( F_22 ( V_1 -> V_2 . V_53 , 0 , & V_51 ) != 0 ) {
F_5 ( & V_1 -> V_2 , L_4 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_8 -> V_30 = F_23 ( & V_51 ) ;
if ( V_8 -> V_30 == 0 ) {
F_5 ( & V_1 -> V_2 , L_5 ,
V_58 , V_50 ) ;
V_52 = - V_59 ;
goto V_57;
}
F_20 ( & V_1 -> V_2 , L_6 ,
V_58 , V_50 , V_8 -> V_30 >> 20 ) ;
V_8 -> V_42 = V_51 . V_60 ;
V_8 -> V_26 = ( unsigned long ) F_24 (
V_8 -> V_42 , V_8 -> V_30 , V_61 ) ;
if ( V_8 -> V_26 == 0 ) {
F_5 ( & V_1 -> V_2 , L_7 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_8 -> V_62 = F_25 ( V_63 ) ;
if ( V_8 -> V_62 == NULL ) {
F_5 ( & V_1 -> V_2 , L_8 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_8 -> V_62 -> V_64 = V_65 ;
V_8 -> V_62 -> V_66 = V_67 ;
V_8 -> V_62 -> V_68 = & V_69 ;
V_8 -> V_62 -> V_17 = V_8 ;
sprintf ( V_8 -> V_62 -> V_70 , L_9 ,
V_58 , V_50 ) ;
V_8 -> V_45 = F_26 ( V_8 , V_8 -> V_62 -> V_70 ,
& V_71 ) ;
if ( ! V_8 -> V_45 ) {
V_52 = - V_55 ;
goto V_57;
}
V_8 -> V_62 -> V_14 = F_27 ( V_54 ) ;
if ( V_8 -> V_62 -> V_14 == NULL ) {
F_5 ( & V_1 -> V_2 , L_10 ) ;
V_52 = - V_56 ;
goto V_57;
}
F_28 ( V_8 -> V_62 , V_8 -> V_30 >> V_29 ) ;
F_29 ( V_8 -> V_62 -> V_14 , F_6 ) ;
F_30 ( V_8 -> V_62 -> V_14 , V_72 ) ;
F_31 ( & V_1 -> V_2 , V_8 -> V_62 ) ;
V_8 -> V_73 = F_32 ( V_1 -> V_2 . V_53 , 0 ) ;
if ( ! V_8 -> V_73 ) {
F_5 ( & V_1 -> V_2 , L_11 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_52 = F_33 ( V_8 -> V_73 , F_4 ,
V_74 , V_8 -> V_62 -> V_70 , V_1 ) ;
if ( V_52 != 0 ) {
F_5 ( & V_1 -> V_2 , L_12 ) ;
V_8 -> V_73 = 0 ;
V_52 = - V_56 ;
goto V_57;
}
V_52 = F_34 ( & V_1 -> V_2 , & V_75 ) ;
if ( V_52 != 0 ) {
F_5 ( & V_1 -> V_2 , L_13 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_67 += V_8 -> V_62 -> V_76 ;
return 0 ;
V_57:
if ( V_8 -> V_73 )
F_35 ( V_8 -> V_73 , V_1 ) ;
if ( V_8 -> V_62 != NULL ) {
if ( V_8 -> V_62 -> V_64 > 0 )
F_36 ( V_8 -> V_62 -> V_64 ,
V_8 -> V_62 -> V_70 ) ;
if ( V_8 -> V_62 -> V_77 & V_78 )
F_37 ( V_8 -> V_62 ) ;
F_38 ( V_8 -> V_62 ) ;
}
F_39 ( V_8 -> V_45 ) ;
F_40 ( V_8 -> V_45 ) ;
V_1 -> V_2 . V_9 = NULL ;
if ( V_8 -> V_26 != 0 )
F_41 ( ( void V_79 * ) V_8 -> V_26 ) ;
F_42 ( V_8 ) ;
return V_52 ;
}
static int
F_43 ( struct V_6 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 || ! V_8 -> V_62 ) ;
F_44 ( & V_1 -> V_2 , & V_75 ) ;
F_35 ( V_8 -> V_73 , V_1 ) ;
F_39 ( V_8 -> V_45 ) ;
F_40 ( V_8 -> V_45 ) ;
F_37 ( V_8 -> V_62 ) ;
F_38 ( V_8 -> V_62 ) ;
F_41 ( ( void V_79 * ) V_8 -> V_26 ) ;
F_42 ( V_8 ) ;
return 0 ;
}
static int T_8
F_45 ( void )
{
V_65 = F_46 ( V_65 , V_58 ) ;
if ( V_65 < 0 ) {
F_47 ( V_80 L_14 ,
V_81 ) ;
return - V_56 ;
}
V_67 = 0 ;
return F_48 ( & V_82 ) ;
}
static void T_9
F_49 ( void )
{
F_50 ( & V_82 ) ;
F_36 ( V_65 , V_58 ) ;
}
