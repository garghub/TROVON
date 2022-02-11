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
static void
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
return;
}
V_21 = F_10 ( V_23 . V_33 ) + V_23 . V_34 ;
if ( F_11 ( V_15 ) == V_35 )
memcpy ( V_21 , ( void * ) V_19 , V_23 . V_32 ) ;
else
memcpy ( ( void * ) V_19 , V_21 , V_23 . V_32 ) ;
V_19 += V_23 . V_32 ;
V_24 += V_23 . V_32 ;
}
F_12 ( V_15 , 0 ) ;
}
static int
F_13 ( struct V_36 * V_1 , T_3 V_37 ,
void * * V_38 , unsigned long * V_39 )
{
struct V_7 * V_8 = V_1 -> V_17 -> V_18 ;
T_4 V_40 ;
V_40 = V_37 ;
if ( V_1 -> V_41 != NULL )
V_40 += V_1 -> V_41 -> V_42 ;
V_40 <<= V_30 ;
if ( V_40 >= V_8 -> V_31 ) {
F_5 ( & V_8 -> V_1 -> V_2 , L_3 ) ;
return - V_43 ;
}
* V_38 = ( void * ) ( V_8 -> V_44 + V_40 ) ;
* V_39 = F_14 ( V_38 ) >> V_45 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_1 )
{
static int V_46 = - 1 ;
struct V_7 * V_8 ;
struct V_47 V_47 ;
int V_48 = 0 ;
V_46 ++ ;
F_16 ( & V_1 -> V_2 , L_4 ,
V_1 -> V_2 . V_49 -> V_50 ) ;
V_8 = F_17 ( sizeof( struct V_7 ) , V_51 ) ;
if ( V_8 == NULL ) {
F_5 ( & V_1 -> V_2 , L_5 ) ;
V_48 = - V_52 ;
goto V_53;
}
V_1 -> V_2 . V_9 = V_8 ;
V_8 -> V_1 = V_1 ;
if ( F_18 ( V_1 -> V_2 . V_49 , 0 , & V_47 ) != 0 ) {
F_5 ( & V_1 -> V_2 , L_6 ) ;
V_48 = - V_54 ;
goto V_53;
}
V_8 -> V_31 = F_19 ( & V_47 ) ;
if ( V_8 -> V_31 == 0 ) {
F_5 ( & V_1 -> V_2 , L_7 ,
V_55 , V_46 ) ;
V_48 = - V_56 ;
goto V_53;
}
F_16 ( & V_1 -> V_2 , L_8 ,
V_55 , V_46 , V_8 -> V_31 >> 20 ) ;
V_8 -> V_44 = V_47 . V_57 ;
V_8 -> V_27 = ( unsigned long ) F_20 (
V_8 -> V_44 , V_8 -> V_31 , V_58 ) ;
if ( V_8 -> V_27 == 0 ) {
F_5 ( & V_1 -> V_2 , L_9 ) ;
V_48 = - V_54 ;
goto V_53;
}
V_8 -> V_59 = F_21 ( V_60 ) ;
if ( V_8 -> V_59 == NULL ) {
F_5 ( & V_1 -> V_2 , L_10 ) ;
V_48 = - V_54 ;
goto V_53;
}
V_8 -> V_59 -> V_61 = V_62 ;
V_8 -> V_59 -> V_63 = V_64 ;
V_8 -> V_59 -> V_65 = & V_66 ;
V_8 -> V_59 -> V_18 = V_8 ;
V_8 -> V_59 -> V_67 = & V_1 -> V_2 ;
sprintf ( V_8 -> V_59 -> V_68 , L_11 ,
V_55 , V_46 ) ;
V_8 -> V_59 -> V_14 = F_22 ( V_51 ) ;
if ( V_8 -> V_59 -> V_14 == NULL ) {
F_5 ( & V_1 -> V_2 , L_12 ) ;
V_48 = - V_54 ;
goto V_53;
}
F_23 ( V_8 -> V_59 , V_8 -> V_31 >> V_30 ) ;
F_24 ( V_8 -> V_59 -> V_14 , F_6 ) ;
F_25 ( V_8 -> V_59 -> V_14 , V_69 ) ;
F_26 ( V_8 -> V_59 ) ;
V_8 -> V_70 = F_27 ( V_1 -> V_2 . V_49 , 0 ) ;
if ( V_8 -> V_70 == V_71 ) {
F_5 ( & V_1 -> V_2 , L_13 ) ;
V_48 = - V_54 ;
goto V_53;
}
V_48 = F_28 ( V_8 -> V_70 , F_4 ,
V_72 , V_8 -> V_59 -> V_68 , V_1 ) ;
if ( V_48 != 0 ) {
F_5 ( & V_1 -> V_2 , L_14 ) ;
V_8 -> V_70 = V_71 ;
V_48 = - V_54 ;
goto V_53;
}
V_48 = F_29 ( & V_1 -> V_2 , & V_73 ) ;
if ( V_48 != 0 ) {
F_5 ( & V_1 -> V_2 , L_15 ) ;
V_48 = - V_54 ;
goto V_53;
}
V_64 += V_8 -> V_59 -> V_74 ;
return 0 ;
V_53:
if ( V_8 != NULL ) {
if ( V_8 -> V_70 != V_71 )
F_30 ( V_8 -> V_70 , V_1 ) ;
if ( V_8 -> V_59 != NULL ) {
if ( V_8 -> V_59 -> V_61 > 0 )
F_31 ( V_8 -> V_59 -> V_61 ,
V_8 -> V_59 -> V_68 ) ;
F_32 ( V_8 -> V_59 ) ;
}
V_1 -> V_2 . V_9 = NULL ;
if ( V_8 -> V_27 != 0 )
F_33 ( ( void V_75 * ) V_8 -> V_27 ) ;
F_34 ( V_8 ) ;
}
return V_48 ;
}
static int
F_35 ( struct V_6 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 . V_9 ;
F_3 ( ! V_8 || ! V_8 -> V_59 ) ;
F_36 ( & V_1 -> V_2 , & V_73 ) ;
F_30 ( V_8 -> V_70 , V_1 ) ;
F_32 ( V_8 -> V_59 ) ;
F_33 ( ( void V_75 * ) V_8 -> V_27 ) ;
F_34 ( V_8 ) ;
return 0 ;
}
static int T_5
F_37 ( void )
{
V_62 = F_38 ( V_62 , V_55 ) ;
if ( V_62 < 0 ) {
F_39 ( V_76 L_16 ,
V_77 ) ;
return - V_54 ;
}
V_64 = 0 ;
return F_40 ( & V_78 ) ;
}
static void T_6
F_41 ( void )
{
F_42 ( & V_78 ) ;
F_31 ( V_62 , V_55 ) ;
}
