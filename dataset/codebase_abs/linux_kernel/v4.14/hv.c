int F_1 ( void )
{
if ( ! F_2 () )
return - V_1 ;
V_2 . V_3 = F_3 ( struct V_4 ) ;
if ( ! V_2 . V_3 )
return - V_5 ;
return 0 ;
}
int F_4 ( union V_6 V_7 ,
enum V_8 V_9 ,
void * V_10 , T_1 V_11 )
{
struct V_12 * V_13 ;
struct V_4 * V_14 ;
T_2 V_15 ;
if ( V_11 > V_16 )
return - V_17 ;
V_14 = F_5 ( V_2 . V_3 ) ;
V_13 = V_14 -> V_18 ;
V_13 -> V_19 = V_7 ;
V_13 -> V_20 = 0 ;
V_13 -> V_9 = V_9 ;
V_13 -> V_11 = V_11 ;
memcpy ( ( void * ) V_13 -> V_10 , V_10 , V_11 ) ;
V_15 = F_6 ( V_21 , V_13 , NULL ) ;
F_7 ( V_14 ) ;
return V_15 & 0xFFFF ;
}
static int F_8 ( unsigned long V_22 ,
struct V_23 * V_24 )
{
T_2 V_25 ;
F_9 ( ! F_10 ( V_24 ) ) ;
V_25 = V_26 -> V_27 ( NULL ) ;
V_25 += V_22 ;
F_11 ( V_28 , V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_24 )
{
F_11 ( V_28 , 0 ) ;
F_13 ( V_29 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
union V_30 V_31 ;
V_31 . V_32 = 1 ;
V_31 . V_33 = 1 ;
V_31 . V_34 = V_35 ;
F_13 ( V_29 , V_31 . V_36 ) ;
return 0 ;
}
static void F_15 ( struct V_23 * V_37 , int V_38 )
{
V_37 -> V_39 = L_1 ;
V_37 -> V_40 = V_41 ;
V_37 -> V_42 = F_16 ( V_38 ) ;
V_37 -> V_43 = 1000 ;
V_37 -> V_44 = F_12 ;
V_37 -> V_45 = F_14 ;
V_37 -> V_46 = F_8 ;
}
int F_17 ( void )
{
int V_38 ;
V_2 . V_47 = F_18 ( sizeof( struct V_42 ) * V_48 ,
V_49 ) ;
if ( V_2 . V_47 == NULL ) {
F_19 ( L_2 ) ;
goto V_50;
}
F_20 (cpu) {
struct V_4 * V_14
= F_21 ( V_2 . V_3 , V_38 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_22 ( & V_14 -> V_51 ,
V_52 , ( unsigned long ) V_14 ) ;
V_14 -> V_53 = F_18 ( sizeof( struct V_23 ) ,
V_54 ) ;
if ( V_14 -> V_53 == NULL ) {
F_19 ( L_3 ) ;
goto V_50;
}
F_15 ( V_14 -> V_53 , V_38 ) ;
V_14 -> V_55 =
( void * ) F_23 ( V_49 ) ;
if ( V_14 -> V_55 == NULL ) {
F_19 ( L_4 ) ;
goto V_50;
}
V_14 -> V_56 = ( void * ) F_23 ( V_49 ) ;
if ( V_14 -> V_56 == NULL ) {
F_19 ( L_5 ) ;
goto V_50;
}
V_14 -> V_18 = ( void * ) F_23 ( V_49 ) ;
if ( V_14 -> V_18 == NULL ) {
F_19 ( L_6 ) ;
goto V_50;
}
F_24 ( & V_14 -> V_57 ) ;
}
return 0 ;
V_50:
return - V_5 ;
}
void F_25 ( void )
{
int V_38 ;
F_20 (cpu) {
struct V_4 * V_14
= F_21 ( V_2 . V_3 , V_38 ) ;
if ( V_14 -> V_56 )
F_26 ( ( unsigned long ) V_14 -> V_56 ) ;
if ( V_14 -> V_55 )
F_26 ( ( unsigned long ) V_14 -> V_55 ) ;
if ( V_14 -> V_18 )
F_26 ( ( unsigned long ) V_14 -> V_18 ) ;
}
F_27 ( V_2 . V_47 ) ;
}
int F_28 ( unsigned int V_38 )
{
struct V_4 * V_14
= F_21 ( V_2 . V_3 , V_38 ) ;
union V_58 V_59 ;
union V_60 V_61 ;
union V_62 V_63 ;
union V_64 V_65 ;
F_29 ( V_59 . V_36 ) ;
V_59 . V_66 = 1 ;
V_59 . V_67 = F_30 ( V_14 -> V_55 )
>> V_68 ;
F_31 ( V_59 . V_36 ) ;
F_32 ( V_61 . V_36 ) ;
V_61 . V_69 = 1 ;
V_61 . V_70 = F_30 ( V_14 -> V_56 )
>> V_68 ;
F_33 ( V_61 . V_36 ) ;
F_34 ( V_71 + V_35 ,
V_63 . V_36 ) ;
V_63 . V_36 = 0 ;
V_63 . V_72 = V_73 ;
V_63 . V_74 = false ;
if ( V_75 . V_76 & V_77 )
V_63 . V_78 = false ;
else
V_63 . V_78 = true ;
F_35 ( V_71 + V_35 ,
V_63 . V_36 ) ;
F_36 ( V_65 . V_36 ) ;
V_65 . V_32 = 1 ;
F_37 ( V_65 . V_36 ) ;
V_2 . V_79 = true ;
if ( V_75 . V_40 & V_80 )
F_38 ( V_14 -> V_53 ,
V_81 ,
V_82 ,
V_83 ) ;
return 0 ;
}
void F_39 ( void )
{
int V_38 ;
if ( ! ( V_75 . V_40 & V_80 ) )
return;
F_20 (cpu) {
struct V_4 * V_14
= F_21 ( V_2 . V_3 , V_38 ) ;
F_40 ( V_14 -> V_53 , V_38 ) ;
}
}
int F_41 ( unsigned int V_38 )
{
union V_62 V_63 ;
union V_58 V_59 ;
union V_60 V_61 ;
union V_64 V_65 ;
struct V_84 * V_85 , * V_86 ;
bool V_87 = false ;
unsigned long V_88 ;
if ( ! V_2 . V_79 )
return - V_89 ;
F_42 ( & V_90 . V_91 ) ;
F_43 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_85 -> V_92 == V_38 ) {
V_87 = true ;
break;
}
F_44 ( & V_85 -> V_93 , V_88 ) ;
F_43 (sc, &channel->sc_list, sc_list) {
if ( V_86 -> V_92 == V_38 ) {
V_87 = true ;
break;
}
}
F_45 ( & V_85 -> V_93 , V_88 ) ;
if ( V_87 )
break;
}
F_46 ( & V_90 . V_91 ) ;
if ( V_87 && V_90 . V_94 == V_95 )
return - V_96 ;
if ( V_75 . V_40 & V_80 ) {
struct V_4 * V_14
= F_47 ( V_2 . V_3 ) ;
F_40 ( V_14 -> V_53 , V_38 ) ;
F_12 ( V_14 -> V_53 ) ;
F_7 ( V_14 ) ;
}
F_34 ( V_71 + V_35 ,
V_63 . V_36 ) ;
V_63 . V_74 = 1 ;
F_35 ( V_71 + V_35 ,
V_63 . V_36 ) ;
F_29 ( V_59 . V_36 ) ;
V_59 . V_66 = 0 ;
V_59 . V_67 = 0 ;
F_31 ( V_59 . V_36 ) ;
F_32 ( V_61 . V_36 ) ;
V_61 . V_69 = 0 ;
V_61 . V_70 = 0 ;
F_33 ( V_61 . V_36 ) ;
F_36 ( V_65 . V_36 ) ;
V_65 . V_32 = 0 ;
F_37 ( V_65 . V_36 ) ;
return 0 ;
}
