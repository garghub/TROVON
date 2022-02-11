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
F_6 ( V_14 ) ;
V_15 = F_7 ( V_21 , V_13 , NULL ) ;
return V_15 & 0xFFFF ;
}
static int F_8 ( unsigned long V_22 ,
struct V_23 * V_24 )
{
T_2 V_25 ;
F_9 ( ! F_10 ( V_24 ) ) ;
F_11 ( V_25 ) ;
V_25 += V_22 ;
F_12 ( V_26 , V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 )
{
F_12 ( V_26 , 0 ) ;
F_14 ( V_27 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_23 * V_24 )
{
union V_28 V_29 ;
V_29 . V_30 = 1 ;
V_29 . V_31 = 1 ;
V_29 . V_32 = V_33 ;
F_14 ( V_27 , V_29 . V_34 ) ;
return 0 ;
}
static void F_16 ( struct V_23 * V_35 , int V_36 )
{
V_35 -> V_37 = L_1 ;
V_35 -> V_38 = V_39 ;
V_35 -> V_40 = F_17 ( V_36 ) ;
V_35 -> V_41 = 1000 ;
V_35 -> V_42 = F_13 ;
V_35 -> V_43 = F_15 ;
V_35 -> V_44 = F_8 ;
}
int F_18 ( void )
{
int V_36 ;
V_2 . V_45 = F_19 ( sizeof( struct V_40 ) * V_46 ,
V_47 ) ;
if ( V_2 . V_45 == NULL ) {
F_20 ( L_2 ) ;
goto V_48;
}
F_21 (cpu) {
struct V_4 * V_14
= F_22 ( V_2 . V_3 , V_36 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_23 ( & V_14 -> V_49 ,
V_50 , ( unsigned long ) V_14 ) ;
V_14 -> V_51 = F_19 ( sizeof( struct V_23 ) ,
V_52 ) ;
if ( V_14 -> V_51 == NULL ) {
F_20 ( L_3 ) ;
goto V_48;
}
F_16 ( V_14 -> V_51 , V_36 ) ;
V_14 -> V_53 =
( void * ) F_24 ( V_47 ) ;
if ( V_14 -> V_53 == NULL ) {
F_20 ( L_4 ) ;
goto V_48;
}
V_14 -> V_54 = ( void * ) F_24 ( V_47 ) ;
if ( V_14 -> V_54 == NULL ) {
F_20 ( L_5 ) ;
goto V_48;
}
V_14 -> V_18 = ( void * ) F_24 ( V_47 ) ;
if ( V_14 -> V_18 == NULL ) {
F_20 ( L_6 ) ;
goto V_48;
}
F_25 ( & V_14 -> V_55 ) ;
}
return 0 ;
V_48:
return - V_5 ;
}
void F_26 ( void )
{
int V_36 ;
F_21 (cpu) {
struct V_4 * V_14
= F_22 ( V_2 . V_3 , V_36 ) ;
if ( V_14 -> V_54 )
F_27 ( ( unsigned long ) V_14 -> V_54 ) ;
if ( V_14 -> V_53 )
F_27 ( ( unsigned long ) V_14 -> V_53 ) ;
if ( V_14 -> V_18 )
F_27 ( ( unsigned long ) V_14 -> V_18 ) ;
}
F_28 ( V_2 . V_45 ) ;
}
int F_29 ( unsigned int V_36 )
{
struct V_4 * V_14
= F_22 ( V_2 . V_3 , V_36 ) ;
union V_56 V_57 ;
union V_58 V_59 ;
union V_60 V_61 ;
union V_62 V_63 ;
T_2 V_64 ;
F_30 ( V_57 . V_34 ) ;
V_57 . V_65 = 1 ;
V_57 . V_66 = F_31 ( V_14 -> V_53 )
>> V_67 ;
F_32 ( V_57 . V_34 ) ;
F_33 ( V_59 . V_34 ) ;
V_59 . V_68 = 1 ;
V_59 . V_69 = F_31 ( V_14 -> V_54 )
>> V_67 ;
F_34 ( V_59 . V_34 ) ;
F_35 ( V_70 + V_33 ,
V_61 . V_34 ) ;
V_61 . V_34 = 0 ;
V_61 . V_71 = V_72 ;
V_61 . V_73 = false ;
if ( V_74 . V_75 & V_76 )
V_61 . V_77 = false ;
else
V_61 . V_77 = true ;
F_36 ( V_70 + V_33 ,
V_61 . V_34 ) ;
F_37 ( V_63 . V_34 ) ;
V_63 . V_30 = 1 ;
F_38 ( V_63 . V_34 ) ;
V_2 . V_78 = true ;
F_39 ( V_64 ) ;
V_2 . V_64 [ V_36 ] = ( V_79 ) V_64 ;
if ( V_74 . V_38 & V_80 )
F_40 ( V_14 -> V_51 ,
V_81 ,
V_82 ,
V_83 ) ;
return 0 ;
}
void F_41 ( void )
{
int V_36 ;
if ( ! ( V_74 . V_38 & V_80 ) )
return;
F_21 (cpu) {
struct V_4 * V_14
= F_22 ( V_2 . V_3 , V_36 ) ;
F_42 ( V_14 -> V_51 , V_36 ) ;
}
}
int F_43 ( unsigned int V_36 )
{
union V_60 V_61 ;
union V_56 V_57 ;
union V_58 V_59 ;
union V_62 V_63 ;
struct V_84 * V_85 , * V_86 ;
bool V_87 = false ;
unsigned long V_88 ;
if ( ! V_2 . V_78 )
return - V_89 ;
F_44 ( & V_90 . V_91 ) ;
F_45 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_85 -> V_92 == V_36 ) {
V_87 = true ;
break;
}
F_46 ( & V_85 -> V_93 , V_88 ) ;
F_45 (sc, &channel->sc_list, sc_list) {
if ( V_86 -> V_92 == V_36 ) {
V_87 = true ;
break;
}
}
F_47 ( & V_85 -> V_93 , V_88 ) ;
if ( V_87 )
break;
}
F_48 ( & V_90 . V_91 ) ;
if ( V_87 && V_90 . V_94 == V_95 )
return - V_96 ;
if ( V_74 . V_38 & V_80 ) {
struct V_4 * V_14
= F_49 ( V_2 . V_3 ) ;
F_42 ( V_14 -> V_51 , V_36 ) ;
F_13 ( V_14 -> V_51 ) ;
F_6 ( V_14 ) ;
}
F_35 ( V_70 + V_33 ,
V_61 . V_34 ) ;
V_61 . V_73 = 1 ;
F_36 ( V_70 + V_33 ,
V_61 . V_34 ) ;
F_30 ( V_57 . V_34 ) ;
V_57 . V_65 = 0 ;
V_57 . V_66 = 0 ;
F_32 ( V_57 . V_34 ) ;
F_33 ( V_59 . V_34 ) ;
V_59 . V_68 = 0 ;
V_59 . V_69 = 0 ;
F_34 ( V_59 . V_34 ) ;
F_37 ( V_63 . V_34 ) ;
V_63 . V_30 = 0 ;
F_38 ( V_63 . V_34 ) ;
return 0 ;
}
