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
char * V_51 = ( char * ) V_18 -> V_15 + sizeof( struct V_14 ) ;
unsigned long V_19 ;
T_1 V_43 = 0 ;
struct V_27 * V_52 = NULL ;
int V_53 , V_54 = 0 ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_34 = V_55 ;
if ( V_18 -> V_25 -> V_56 && ( V_18 -> V_25 -> V_57 && V_58 ) ) {
int V_59 = F_24 ( V_18 ) ;
int V_60 = sizeof( struct V_27 ) +
sizeof( struct V_44 * ) * V_59 ;
if ( F_25 ( & V_31 ) >= V_6 -> V_61 ) {
V_53 = F_26 ( V_32 ,
F_25 ( & V_31 ) < V_6 -> V_61 ) ;
if ( V_53 == - V_62 )
return V_53 ;
F_6 ( V_20 , L_5 ) ;
}
if ( V_60 <= ( V_18 -> V_25 -> V_63 - V_18 -> V_25 -> V_64 ) ) {
V_18 -> V_25 -> V_26 = V_18 -> V_25 -> V_65 + V_18 -> V_25 -> V_64 ;
V_52 = (struct V_27 * ) V_18 -> V_25 -> V_26 ;
V_52 -> V_33 = 0 ;
} else {
V_18 -> V_25 -> V_26 = F_27 ( V_60 , V_66 ) ;
if ( ! V_18 -> V_25 -> V_26 ) {
F_6 ( V_20 , L_6
L_7 ) ;
return - V_67 ;
}
V_52 = (struct V_27 * ) V_18 -> V_25 -> V_26 ;
V_52 -> V_33 = 1 ;
}
V_53 = F_28 ( V_18 , & V_43 , & V_54 , V_59 ,
V_18 -> V_25 -> V_68 == V_69 ? 1 : 0 ) ;
if ( V_53 < 0 ) {
if ( V_52 -> V_33 )
F_14 ( V_52 ) ;
return V_53 ;
} else {
F_29 ( V_52 -> V_30 , & V_31 ) ;
}
}
V_70:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_48 = F_16 ( V_6 -> V_37 , 0 , V_71 , V_18 -> V_25 -> V_65 ,
V_18 -> V_25 -> V_64 ) ;
if ( V_18 -> V_25 -> V_56 && ( V_18 -> V_25 -> V_68 == V_72 ) ) {
if ( V_18 -> V_25 -> V_57 && V_58 ) {
V_50 = F_20 ( V_6 -> V_37 , V_48 , V_71 ,
V_43 , V_52 -> V_73 , V_54 ) ;
} else {
char * V_74 ;
if ( V_18 -> V_25 -> V_57 )
V_74 = ( V_75 char * ) V_18 -> V_25 -> V_57 ;
else
V_74 = V_18 -> V_25 -> V_76 ;
V_50 = F_16 ( V_6 -> V_37 , V_48 , V_71 , V_74 ,
V_18 -> V_25 -> V_56 ) ;
}
V_48 += V_50 ;
}
if ( V_18 -> V_25 -> V_56 &&
( ( V_18 -> V_25 -> V_68 == V_69 ) || ( V_18 -> V_25 -> V_68 == V_77 ) ) ) {
V_49 = F_16 ( V_6 -> V_37 , V_48 , V_71 , V_51 , 11 ) ;
if ( V_18 -> V_25 -> V_57 && V_58 ) {
V_47 = F_20 ( V_6 -> V_37 , V_48 + V_49 , V_71 ,
V_43 , V_52 -> V_73 , V_54 ) ;
} else {
char * V_74 ;
if ( V_18 -> V_25 -> V_57 )
V_74 = ( V_75 char * ) V_18 -> V_25 -> V_57 ;
else
V_74 = V_18 -> V_25 -> V_76 ;
V_47 = F_16 ( V_6 -> V_37 , V_48 + V_49 , V_71 ,
V_74 , V_18 -> V_25 -> V_56 ) ;
}
V_47 += V_49 ;
} else {
V_47 = F_16 ( V_6 -> V_37 , V_48 , V_71 , V_51 ,
V_4 -> V_78 ) ;
}
V_53 = F_30 ( V_6 -> V_11 , V_6 -> V_37 , V_48 , V_47 , V_18 -> V_25 ) ;
if ( V_53 < 0 ) {
if ( V_53 == - V_79 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_53 = F_26 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_53 == - V_62 )
return V_53 ;
F_6 ( V_20 , L_8 ) ;
goto V_70;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6
L_9 ) ;
if ( V_52 && V_52 -> V_33 )
F_14 ( V_52 ) ;
return - V_80 ;
}
}
F_31 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_10 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_81 * V_82 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_5 * V_6 ;
struct V_86 * V_12 ;
V_12 = F_33 ( V_82 ) ;
V_6 = V_12 -> V_13 ;
return snprintf ( V_85 , V_6 -> V_87 + 1 , L_11 , V_6 -> V_24 ) ;
}
static int F_34 ( struct V_86 * V_12 )
{
T_3 V_87 ;
char * V_24 ;
int V_53 ;
struct V_5 * V_6 ;
V_6 = F_27 ( sizeof( struct V_5 ) , V_88 ) ;
if ( ! V_6 ) {
F_35 ( V_89 L_12 ) ;
V_53 = - V_67 ;
goto V_90;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_36 ( V_12 , F_5 , L_13 ) ;
if ( F_37 ( V_6 -> V_11 ) ) {
V_53 = F_38 ( V_6 -> V_11 ) ;
goto V_91;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_39 ( & V_6 -> V_21 ) ;
F_40 ( V_6 -> V_37 , V_71 ) ;
V_6 -> V_9 = false ;
if ( F_41 ( V_12 , V_92 ) ) {
V_12 -> V_93 -> V_94 ( V_12 ,
F_42 ( struct V_95 , V_87 ) ,
& V_87 , sizeof( V_87 ) ) ;
} else {
V_53 = - V_96 ;
goto V_91;
}
V_24 = F_27 ( V_87 , V_88 ) ;
if ( ! V_24 ) {
V_53 = - V_67 ;
goto V_91;
}
V_12 -> V_93 -> V_94 ( V_12 , F_42 ( struct V_95 , V_24 ) ,
V_24 , V_87 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_87 = V_87 ;
V_53 = F_43 ( & ( V_12 -> V_82 . V_97 ) , & V_98 . V_84 ) ;
if ( V_53 ) {
goto V_99;
}
V_6 -> V_23 = F_27 ( sizeof( V_100 ) , V_88 ) ;
if ( ! V_6 -> V_23 ) {
V_53 = - V_67 ;
goto V_99;
}
F_44 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_61 = F_45 () / 4 ;
F_3 ( & V_8 ) ;
F_46 ( & V_6 -> V_101 , & V_102 ) ;
F_4 ( & V_8 ) ;
return 0 ;
V_99:
F_14 ( V_24 ) ;
V_91:
V_12 -> V_93 -> V_103 ( V_12 ) ;
F_14 ( V_6 ) ;
V_90:
return V_53 ;
}
static int
F_47 ( struct V_3 * V_4 , const char * V_104 , char * args )
{
struct V_5 * V_6 ;
int V_105 = - V_106 ;
int V_107 = 0 ;
F_3 ( & V_8 ) ;
F_48 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_104 , V_6 -> V_24 , V_6 -> V_87 ) &&
strlen ( V_104 ) == V_6 -> V_87 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_107 = 1 ;
break;
}
V_105 = - V_108 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_107 ) {
F_35 ( V_89 L_14 ) ;
return V_105 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_34 = V_109 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_49 ( struct V_86 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
F_18 ( V_6 -> V_9 ) ;
V_12 -> V_93 -> V_103 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_50 ( & V_6 -> V_101 ) ;
F_4 ( & V_8 ) ;
F_51 ( & ( V_12 -> V_82 . V_97 ) , & V_98 . V_84 ) ;
F_14 ( V_6 -> V_24 ) ;
F_14 ( V_6 -> V_23 ) ;
F_14 ( V_6 ) ;
}
static int T_4 F_52 ( void )
{
F_53 ( & V_102 ) ;
F_54 ( & V_110 ) ;
return F_55 ( & V_111 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_111 ) ;
F_58 ( & V_110 ) ;
}
