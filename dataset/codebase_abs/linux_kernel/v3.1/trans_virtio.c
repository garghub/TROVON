static unsigned int F_1 ( void * V_1 )
{
return V_2 - ( ( unsigned long ) V_1 % V_2 ) ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_3 ( & V_8 ) ;
if ( V_6 )
V_6 -> V_9 = false ;
F_4 ( & V_8 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_12 -> V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
F_6 ( V_20 , L_1 ) ;
while ( 1 ) {
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_15 = F_8 ( V_6 -> V_11 , & V_16 ) ;
if ( V_15 == NULL ) {
F_9 ( & V_6 -> V_21 , V_19 ) ;
break;
}
V_6 -> V_22 = 1 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_10 ( V_6 -> V_23 ) ;
F_6 ( V_20 , L_2 , V_15 ) ;
F_6 ( V_20 , L_3 , V_15 -> V_24 ) ;
V_18 = F_11 ( V_6 -> V_4 , V_15 -> V_24 ) ;
if ( V_18 -> V_25 -> V_26 ) {
struct V_27 * V_28 = V_18 -> V_25 -> V_26 ;
int V_29 = V_28 -> V_30 ;
F_12 ( V_28 ) ;
F_13 ( V_29 , & V_31 ) ;
F_10 ( & V_32 ) ;
if ( V_28 -> V_33 )
F_14 ( V_28 ) ;
V_18 -> V_25 -> V_26 = NULL ;
}
V_18 -> V_34 = V_35 ;
F_15 ( V_6 -> V_4 , V_18 ) ;
}
}
static int
F_16 ( struct V_36 * V_37 , int V_38 , int V_39 , char * V_1 ,
int V_40 )
{
int V_41 ;
int V_42 = V_38 ;
while ( V_40 ) {
V_41 = F_1 ( V_1 ) ;
if ( V_41 > V_40 )
V_41 = V_40 ;
F_17 ( & V_37 [ V_42 ++ ] , V_1 , V_41 ) ;
V_40 -= V_41 ;
V_1 += V_41 ;
F_18 ( V_42 > V_39 ) ;
}
return V_42 - V_38 ;
}
static int F_19 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
return 1 ;
}
static int
F_20 ( struct V_36 * V_37 , int V_38 , int V_39 , T_1 V_43 ,
struct V_44 * * V_45 , int V_40 )
{
int V_41 ;
int V_46 = 0 ;
int V_42 = V_38 ;
if ( V_43 ) {
V_41 = F_21 ( ( int ) ( V_2 - V_43 ) , V_40 ) ;
F_22 ( & V_37 [ V_42 ++ ] , V_45 [ V_46 ++ ] , V_41 , V_43 ) ;
V_40 -= V_41 ;
}
while ( V_40 ) {
F_18 ( V_42 > V_39 ) ;
V_41 = F_21 ( ( int ) V_2 , V_40 ) ;
F_22 ( & V_37 [ V_42 ++ ] , V_45 [ V_46 ++ ] , V_41 , 0 ) ;
V_40 -= V_41 ;
}
return V_42 - V_38 ;
}
static int
F_23 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_47 , V_48 , V_49 , V_50 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_19 ;
T_1 V_43 = 0 ;
struct V_27 * V_51 = NULL ;
int V_52 , V_53 = 0 ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_34 = V_54 ;
if ( V_18 -> V_25 -> V_55 && ( V_18 -> V_25 -> V_56 && V_57 ) ) {
int V_58 = F_24 ( V_18 ) ;
int V_59 = sizeof( struct V_27 ) +
sizeof( struct V_44 * ) * V_58 ;
if ( F_25 ( & V_31 ) >= V_6 -> V_60 ) {
V_52 = F_26 ( V_32 ,
F_25 ( & V_31 ) < V_6 -> V_60 ) ;
if ( V_52 == - V_61 )
return V_52 ;
F_6 ( V_20 , L_5 ) ;
}
if ( V_59 <= ( V_18 -> V_25 -> V_62 - V_18 -> V_25 -> V_63 ) ) {
V_18 -> V_25 -> V_26 = V_18 -> V_25 -> V_64 + V_18 -> V_25 -> V_63 ;
V_51 = (struct V_27 * ) V_18 -> V_25 -> V_26 ;
V_51 -> V_33 = 0 ;
} else {
V_18 -> V_25 -> V_26 = F_27 ( V_59 , V_65 ) ;
if ( ! V_18 -> V_25 -> V_26 ) {
F_6 ( V_20 , L_6
L_7 ) ;
return - V_66 ;
}
V_51 = (struct V_27 * ) V_18 -> V_25 -> V_26 ;
V_51 -> V_33 = 1 ;
}
V_52 = F_28 ( V_18 , & V_43 , & V_53 , V_58 ,
V_18 -> V_25 -> V_67 == V_68 ? 1 : 0 ) ;
if ( V_52 < 0 ) {
if ( V_51 -> V_33 )
F_14 ( V_51 ) ;
return V_52 ;
} else {
F_29 ( V_51 -> V_30 , & V_31 ) ;
}
}
V_69:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_48 = F_16 ( V_6 -> V_37 , 0 , V_70 , V_18 -> V_25 -> V_64 ,
V_18 -> V_25 -> V_63 ) ;
if ( V_18 -> V_25 -> V_55 && ( V_18 -> V_25 -> V_67 == V_71 ) ) {
if ( V_18 -> V_25 -> V_56 && V_57 ) {
V_50 = F_20 ( V_6 -> V_37 , V_48 , V_70 ,
V_43 , V_51 -> V_72 , V_53 ) ;
} else {
char * V_73 ;
if ( V_18 -> V_25 -> V_56 )
V_73 = ( V_74 char * ) V_18 -> V_25 -> V_56 ;
else
V_73 = V_18 -> V_25 -> V_75 ;
V_50 = F_16 ( V_6 -> V_37 , V_48 , V_70 , V_73 ,
V_18 -> V_25 -> V_55 ) ;
}
V_48 += V_50 ;
}
if ( V_18 -> V_25 -> V_55 &&
( ( V_18 -> V_25 -> V_67 == V_68 ) || ( V_18 -> V_25 -> V_67 == V_76 ) ) ) {
V_49 = F_16 ( V_6 -> V_37 , V_48 ,
V_70 , V_18 -> V_15 -> V_64 , 11 ) ;
if ( V_18 -> V_25 -> V_56 && V_57 ) {
V_47 = F_20 ( V_6 -> V_37 , V_48 + V_49 , V_70 ,
V_43 , V_51 -> V_72 , V_53 ) ;
} else {
char * V_73 ;
if ( V_18 -> V_25 -> V_56 )
V_73 = ( V_74 char * ) V_18 -> V_25 -> V_56 ;
else
V_73 = V_18 -> V_25 -> V_75 ;
V_47 = F_16 ( V_6 -> V_37 , V_48 + V_49 , V_70 ,
V_73 , V_18 -> V_25 -> V_55 ) ;
}
V_47 += V_49 ;
} else {
V_47 = F_16 ( V_6 -> V_37 , V_48 , V_70 ,
V_18 -> V_15 -> V_64 , V_18 -> V_15 -> V_62 ) ;
}
V_52 = F_30 ( V_6 -> V_11 , V_6 -> V_37 , V_48 , V_47 , V_18 -> V_25 ) ;
if ( V_52 < 0 ) {
if ( V_52 == - V_77 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_52 = F_26 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_52 == - V_61 )
return V_52 ;
F_6 ( V_20 , L_8 ) ;
goto V_69;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6
L_9 ) ;
if ( V_51 && V_51 -> V_33 )
F_14 ( V_51 ) ;
return - V_78 ;
}
}
F_31 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_10 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_79 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_5 * V_6 ;
struct V_84 * V_12 ;
V_12 = F_33 ( V_80 ) ;
V_6 = V_12 -> V_13 ;
return snprintf ( V_83 , V_6 -> V_85 + 1 , L_11 , V_6 -> V_24 ) ;
}
static int F_34 ( struct V_84 * V_12 )
{
T_3 V_85 ;
char * V_24 ;
int V_52 ;
struct V_5 * V_6 ;
V_6 = F_27 ( sizeof( struct V_5 ) , V_86 ) ;
if ( ! V_6 ) {
F_35 ( V_87 L_12 ) ;
V_52 = - V_66 ;
goto V_88;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_36 ( V_12 , F_5 , L_13 ) ;
if ( F_37 ( V_6 -> V_11 ) ) {
V_52 = F_38 ( V_6 -> V_11 ) ;
goto V_89;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_39 ( & V_6 -> V_21 ) ;
F_40 ( V_6 -> V_37 , V_70 ) ;
V_6 -> V_9 = false ;
if ( F_41 ( V_12 , V_90 ) ) {
V_12 -> V_91 -> V_92 ( V_12 ,
F_42 ( struct V_93 , V_85 ) ,
& V_85 , sizeof( V_85 ) ) ;
} else {
V_52 = - V_94 ;
goto V_89;
}
V_24 = F_27 ( V_85 , V_86 ) ;
if ( ! V_24 ) {
V_52 = - V_66 ;
goto V_89;
}
V_12 -> V_91 -> V_92 ( V_12 , F_42 ( struct V_93 , V_24 ) ,
V_24 , V_85 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_85 = V_85 ;
V_52 = F_43 ( & ( V_12 -> V_80 . V_95 ) , & V_96 . V_82 ) ;
if ( V_52 ) {
goto V_97;
}
V_6 -> V_23 = F_27 ( sizeof( V_98 ) , V_86 ) ;
if ( ! V_6 -> V_23 ) {
V_52 = - V_66 ;
goto V_97;
}
F_44 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_60 = F_45 () / 4 ;
F_3 ( & V_8 ) ;
F_46 ( & V_6 -> V_99 , & V_100 ) ;
F_4 ( & V_8 ) ;
return 0 ;
V_97:
F_14 ( V_24 ) ;
V_89:
V_12 -> V_91 -> V_101 ( V_12 ) ;
F_14 ( V_6 ) ;
V_88:
return V_52 ;
}
static int
F_47 ( struct V_3 * V_4 , const char * V_102 , char * args )
{
struct V_5 * V_6 ;
int V_103 = - V_104 ;
int V_105 = 0 ;
F_3 ( & V_8 ) ;
F_48 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_102 , V_6 -> V_24 , V_6 -> V_85 ) &&
strlen ( V_102 ) == V_6 -> V_85 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_105 = 1 ;
break;
}
V_103 = - V_106 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_105 ) {
F_35 ( V_87 L_14 ) ;
return V_103 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_34 = V_107 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_49 ( struct V_84 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
F_18 ( V_6 -> V_9 ) ;
V_12 -> V_91 -> V_101 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_50 ( & V_6 -> V_99 ) ;
F_4 ( & V_8 ) ;
F_51 ( & ( V_12 -> V_80 . V_95 ) , & V_96 . V_82 ) ;
F_14 ( V_6 -> V_24 ) ;
F_14 ( V_6 -> V_23 ) ;
F_14 ( V_6 ) ;
}
static int T_4 F_52 ( void )
{
F_53 ( & V_100 ) ;
F_54 ( & V_108 ) ;
return F_55 ( & V_109 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_109 ) ;
F_58 ( & V_108 ) ;
}
