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
static int F_17 ( struct V_6 * V_1 )
{
static int V_47 = - 1 ;
struct V_7 * V_8 ;
struct V_48 V_48 ;
int V_49 = 0 ;
V_47 ++ ;
F_18 ( & V_1 -> V_2 , L_3 ,
V_1 -> V_2 . V_50 -> V_51 ) ;
V_8 = F_19 ( sizeof( struct V_7 ) , V_52 ) ;
if ( V_8 == NULL ) {
F_5 ( & V_1 -> V_2 , L_4 ) ;
V_49 = - V_53 ;
goto V_54;
}
V_1 -> V_2 . V_9 = V_8 ;
V_8 -> V_1 = V_1 ;
if ( F_20 ( V_1 -> V_2 . V_50 , 0 , & V_48 ) != 0 ) {
F_5 ( & V_1 -> V_2 , L_5 ) ;
V_49 = - V_55 ;
goto V_54;
}
V_8 -> V_31 = F_21 ( & V_48 ) ;
if ( V_8 -> V_31 == 0 ) {
F_5 ( & V_1 -> V_2 , L_6 ,
V_56 , V_47 ) ;
V_49 = - V_57 ;
goto V_54;
}
F_18 ( & V_1 -> V_2 , L_7 ,
V_56 , V_47 , V_8 -> V_31 >> 20 ) ;
V_8 -> V_43 = V_48 . V_58 ;
V_8 -> V_27 = ( unsigned long ) F_22 (
V_8 -> V_43 , V_8 -> V_31 , V_59 ) ;
if ( V_8 -> V_27 == 0 ) {
F_5 ( & V_1 -> V_2 , L_8 ) ;
V_49 = - V_55 ;
goto V_54;
}
V_8 -> V_60 = F_23 ( V_61 ) ;
if ( V_8 -> V_60 == NULL ) {
F_5 ( & V_1 -> V_2 , L_9 ) ;
V_49 = - V_55 ;
goto V_54;
}
V_8 -> V_60 -> V_62 = V_63 ;
V_8 -> V_60 -> V_64 = V_65 ;
V_8 -> V_60 -> V_66 = & V_67 ;
V_8 -> V_60 -> V_18 = V_8 ;
sprintf ( V_8 -> V_60 -> V_68 , L_10 ,
V_56 , V_47 ) ;
V_8 -> V_46 = F_24 ( V_8 , V_8 -> V_60 -> V_68 ,
& V_69 ) ;
if ( ! V_8 -> V_46 ) {
V_49 = - V_53 ;
goto V_54;
}
V_8 -> V_60 -> V_14 = F_25 ( V_52 ) ;
if ( V_8 -> V_60 -> V_14 == NULL ) {
F_5 ( & V_1 -> V_2 , L_11 ) ;
V_49 = - V_55 ;
goto V_54;
}
F_26 ( V_8 -> V_60 , V_8 -> V_31 >> V_30 ) ;
F_27 ( V_8 -> V_60 -> V_14 , F_6 ) ;
F_28 ( V_8 -> V_60 -> V_14 , V_70 ) ;
F_29 ( & V_1 -> V_2 , V_8 -> V_60 ) ;
V_8 -> V_71 = F_30 ( V_1 -> V_2 . V_50 , 0 ) ;
if ( ! V_8 -> V_71 ) {
F_5 ( & V_1 -> V_2 , L_12 ) ;
V_49 = - V_55 ;
goto V_54;
}
V_49 = F_31 ( V_8 -> V_71 , F_4 ,
V_72 , V_8 -> V_60 -> V_68 , V_1 ) ;
if ( V_49 != 0 ) {
F_5 ( & V_1 -> V_2 , L_13 ) ;
V_8 -> V_71 = 0 ;
V_49 = - V_55 ;
goto V_54;
}
V_49 = F_32 ( & V_1 -> V_2 , & V_73 ) ;
if ( V_49 != 0 ) {
F_5 ( & V_1 -> V_2 , L_14 ) ;
V_49 = - V_55 ;
goto V_54;
}
V_65 += V_8 -> V_60 -> V_74 ;
return 0 ;
V_54:
if ( V_8 != NULL ) {
if ( V_8 -> V_71 )
F_33 ( V_8 -> V_71 , V_1 ) ;
if ( V_8 -> V_60 != NULL ) {
if ( V_8 -> V_60 -> V_62 > 0 )
F_34 ( V_8 -> V_60 -> V_62 ,
V_8 -> V_60 -> V_68 ) ;
if ( V_8 -> V_60 -> V_75 & V_76 )
F_35 ( V_8 -> V_60 ) ;
F_36 ( V_8 -> V_60 ) ;
}
F_37 ( V_8 -> V_46 ) ;
F_38 ( V_8 -> V_46 ) ;
V_1 -> V_2 . V_9 = NULL ;
if ( V_8 -> V_27 != 0 )
F_39 ( ( void V_77 * ) V_8 -> V_27 ) ;
F_40 ( V_8 ) ;
}
return V_49 ;
}
static int
F_41 ( struct V_6 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 || ! V_8 -> V_60 ) ;
F_42 ( & V_1 -> V_2 , & V_73 ) ;
F_33 ( V_8 -> V_71 , V_1 ) ;
F_37 ( V_8 -> V_46 ) ;
F_38 ( V_8 -> V_46 ) ;
F_35 ( V_8 -> V_60 ) ;
F_36 ( V_8 -> V_60 ) ;
F_39 ( ( void V_77 * ) V_8 -> V_27 ) ;
F_40 ( V_8 ) ;
return 0 ;
}
static int T_7
F_43 ( void )
{
V_63 = F_44 ( V_63 , V_56 ) ;
if ( V_63 < 0 ) {
F_45 ( V_78 L_15 ,
V_79 ) ;
return - V_55 ;
}
V_65 = 0 ;
return F_46 ( & V_80 ) ;
}
static void T_8
F_47 ( void )
{
F_48 ( & V_80 ) ;
F_34 ( V_63 , V_56 ) ;
}
