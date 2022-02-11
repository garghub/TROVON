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
struct V_7 * V_8 = V_15 -> V_16 -> V_17 -> V_18 ;
unsigned long V_19 , V_20 ;
void * V_21 ;
struct V_22 V_23 ;
unsigned int V_24 ;
struct V_25 V_26 ;
V_19 = V_8 -> V_27 + ( V_15 -> V_28 . V_29 <<
V_30 ) ;
V_20 = V_8 -> V_27 + V_8 -> V_31 ;
V_24 = 0 ;
F_7 (vec, bio, iter) {
if ( F_8 ( V_19 + V_23 . V_32 > V_20 ) ) {
F_9 ( V_15 ) ;
return V_33 ;
}
V_21 = F_10 ( V_23 . V_34 ) + V_23 . V_35 ;
if ( F_11 ( V_15 ) == V_36 )
memcpy ( V_21 , ( void * ) V_19 , V_23 . V_32 ) ;
else
memcpy ( ( void * ) V_19 , V_21 , V_23 . V_32 ) ;
V_19 += V_23 . V_32 ;
V_24 += V_23 . V_32 ;
}
F_12 ( V_15 ) ;
return V_33 ;
}
static long
F_13 ( struct V_7 * V_8 , T_4 V_37 , long V_38 ,
void * * V_39 , T_5 * V_40 )
{
T_6 V_41 = V_37 * V_42 ;
* V_39 = ( void * ) V_8 -> V_27 + V_41 ;
* V_40 = F_14 ( V_8 -> V_43 + V_41 , V_44 ) ;
return ( V_8 -> V_31 - V_41 ) / V_42 ;
}
static long
F_15 ( struct V_45 * V_46 , T_4 V_37 , long V_38 ,
void * * V_39 , T_5 * V_40 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
return F_13 ( V_8 , V_37 , V_38 , V_39 , V_40 ) ;
}
static T_7 F_17 ( struct V_45 * V_46 , T_4 V_37 ,
void * V_47 , T_7 V_48 , struct V_49 * V_50 )
{
return F_18 ( V_47 , V_48 , V_50 ) ;
}
static int F_19 ( struct V_6 * V_1 )
{
static int V_51 = - 1 ;
struct V_7 * V_8 ;
struct V_52 V_52 ;
int V_53 = 0 ;
V_51 ++ ;
F_20 ( & V_1 -> V_2 , L_3 ,
V_1 -> V_2 . V_54 -> V_55 ) ;
V_8 = F_21 ( sizeof( struct V_7 ) , V_56 ) ;
if ( V_8 == NULL ) {
F_5 ( & V_1 -> V_2 , L_4 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_1 -> V_2 . V_9 = V_8 ;
V_8 -> V_1 = V_1 ;
if ( F_22 ( V_1 -> V_2 . V_54 , 0 , & V_52 ) != 0 ) {
F_5 ( & V_1 -> V_2 , L_5 ) ;
V_53 = - V_59 ;
goto V_58;
}
V_8 -> V_31 = F_23 ( & V_52 ) ;
if ( V_8 -> V_31 == 0 ) {
F_5 ( & V_1 -> V_2 , L_6 ,
V_60 , V_51 ) ;
V_53 = - V_61 ;
goto V_58;
}
F_20 ( & V_1 -> V_2 , L_7 ,
V_60 , V_51 , V_8 -> V_31 >> 20 ) ;
V_8 -> V_43 = V_52 . V_62 ;
V_8 -> V_27 = ( unsigned long ) F_24 (
V_8 -> V_43 , V_8 -> V_31 , V_63 ) ;
if ( V_8 -> V_27 == 0 ) {
F_5 ( & V_1 -> V_2 , L_8 ) ;
V_53 = - V_59 ;
goto V_58;
}
V_8 -> V_64 = F_25 ( V_65 ) ;
if ( V_8 -> V_64 == NULL ) {
F_5 ( & V_1 -> V_2 , L_9 ) ;
V_53 = - V_59 ;
goto V_58;
}
V_8 -> V_64 -> V_66 = V_67 ;
V_8 -> V_64 -> V_68 = V_69 ;
V_8 -> V_64 -> V_70 = & V_71 ;
V_8 -> V_64 -> V_18 = V_8 ;
sprintf ( V_8 -> V_64 -> V_72 , L_10 ,
V_60 , V_51 ) ;
V_8 -> V_46 = F_26 ( V_8 , V_8 -> V_64 -> V_72 ,
& V_73 ) ;
if ( ! V_8 -> V_46 ) {
V_53 = - V_57 ;
goto V_58;
}
V_8 -> V_64 -> V_14 = F_27 ( V_56 ) ;
if ( V_8 -> V_64 -> V_14 == NULL ) {
F_5 ( & V_1 -> V_2 , L_11 ) ;
V_53 = - V_59 ;
goto V_58;
}
F_28 ( V_8 -> V_64 , V_8 -> V_31 >> V_30 ) ;
F_29 ( V_8 -> V_64 -> V_14 , F_6 ) ;
F_30 ( V_8 -> V_64 -> V_14 , V_74 ) ;
F_31 ( & V_1 -> V_2 , V_8 -> V_64 ) ;
V_8 -> V_75 = F_32 ( V_1 -> V_2 . V_54 , 0 ) ;
if ( ! V_8 -> V_75 ) {
F_5 ( & V_1 -> V_2 , L_12 ) ;
V_53 = - V_59 ;
goto V_58;
}
V_53 = F_33 ( V_8 -> V_75 , F_4 ,
V_76 , V_8 -> V_64 -> V_72 , V_1 ) ;
if ( V_53 != 0 ) {
F_5 ( & V_1 -> V_2 , L_13 ) ;
V_8 -> V_75 = 0 ;
V_53 = - V_59 ;
goto V_58;
}
V_53 = F_34 ( & V_1 -> V_2 , & V_77 ) ;
if ( V_53 != 0 ) {
F_5 ( & V_1 -> V_2 , L_14 ) ;
V_53 = - V_59 ;
goto V_58;
}
V_69 += V_8 -> V_64 -> V_78 ;
return 0 ;
V_58:
if ( V_8 != NULL ) {
if ( V_8 -> V_75 )
F_35 ( V_8 -> V_75 , V_1 ) ;
if ( V_8 -> V_64 != NULL ) {
if ( V_8 -> V_64 -> V_66 > 0 )
F_36 ( V_8 -> V_64 -> V_66 ,
V_8 -> V_64 -> V_72 ) ;
if ( V_8 -> V_64 -> V_79 & V_80 )
F_37 ( V_8 -> V_64 ) ;
F_38 ( V_8 -> V_64 ) ;
}
F_39 ( V_8 -> V_46 ) ;
F_40 ( V_8 -> V_46 ) ;
V_1 -> V_2 . V_9 = NULL ;
if ( V_8 -> V_27 != 0 )
F_41 ( ( void V_81 * ) V_8 -> V_27 ) ;
F_42 ( V_8 ) ;
}
return V_53 ;
}
static int
F_43 ( struct V_6 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 || ! V_8 -> V_64 ) ;
F_44 ( & V_1 -> V_2 , & V_77 ) ;
F_35 ( V_8 -> V_75 , V_1 ) ;
F_39 ( V_8 -> V_46 ) ;
F_40 ( V_8 -> V_46 ) ;
F_37 ( V_8 -> V_64 ) ;
F_38 ( V_8 -> V_64 ) ;
F_41 ( ( void V_81 * ) V_8 -> V_27 ) ;
F_42 ( V_8 ) ;
return 0 ;
}
static int T_8
F_45 ( void )
{
V_67 = F_46 ( V_67 , V_60 ) ;
if ( V_67 < 0 ) {
F_47 ( V_82 L_15 ,
V_83 ) ;
return - V_59 ;
}
V_69 = 0 ;
return F_48 ( & V_84 ) ;
}
static void T_9
F_49 ( void )
{
F_50 ( & V_84 ) ;
F_36 ( V_67 , V_60 ) ;
}
