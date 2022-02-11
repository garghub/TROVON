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
F_12 ( V_6 -> V_4 , V_18 , V_25 ) ;
}
}
static int F_13 ( struct V_26 * V_27 , int V_28 ,
int V_29 , char * V_1 , int V_30 )
{
int V_31 ;
int V_32 = V_28 ;
while ( V_30 ) {
V_31 = F_1 ( V_1 ) ;
if ( V_31 > V_30 )
V_31 = V_30 ;
F_14 ( V_32 > V_29 ) ;
F_15 ( & V_27 [ V_32 ] ) ;
F_16 ( & V_27 [ V_32 ++ ] , V_1 , V_31 ) ;
V_30 -= V_31 ;
V_1 += V_31 ;
}
if ( V_32 - V_28 )
F_17 ( & V_27 [ V_32 - 1 ] ) ;
return V_32 - V_28 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
return 1 ;
}
static int
F_19 ( struct V_26 * V_27 , int V_28 , int V_29 ,
struct V_33 * * V_34 , int V_35 , char * V_1 , int V_30 )
{
int V_36 = 0 , V_31 ;
int V_37 ;
int V_32 = V_28 ;
F_14 ( V_35 > ( V_29 - V_28 ) ) ;
V_37 = F_20 ( V_1 ) ;
while ( V_35 ) {
V_31 = F_1 ( V_1 ) ;
if ( V_31 > V_30 )
V_31 = V_30 ;
F_15 ( & V_27 [ V_32 ] ) ;
F_21 ( & V_27 [ V_32 ++ ] , V_34 [ V_36 ++ ] , V_31 , V_37 ) ;
V_37 = 0 ;
V_1 += V_31 ;
V_30 -= V_31 ;
V_35 -- ;
}
if ( V_32 - V_28 )
F_17 ( & V_27 [ V_32 - 1 ] ) ;
return V_32 - V_28 ;
}
static int
F_22 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_38 ;
int V_39 , V_40 , V_41 , V_42 ;
unsigned long V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_26 * V_43 [ 2 ] ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_44 = V_45 ;
V_46:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_41 = V_42 = 0 ;
V_40 = F_13 ( V_6 -> V_27 , 0 ,
V_47 , V_18 -> V_48 -> V_49 , V_18 -> V_48 -> V_50 ) ;
if ( V_40 )
V_43 [ V_41 ++ ] = V_6 -> V_27 ;
V_39 = F_13 ( V_6 -> V_27 , V_40 ,
V_47 , V_18 -> V_15 -> V_49 , V_18 -> V_15 -> V_51 ) ;
if ( V_39 )
V_43 [ V_41 + V_42 ++ ] = V_6 -> V_27 + V_40 ;
V_38 = F_23 ( V_6 -> V_11 , V_43 , V_41 , V_42 , V_18 -> V_48 ,
V_52 ) ;
if ( V_38 < 0 ) {
if ( V_38 == - V_53 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_38 = F_24 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_38 == - V_54 )
return V_38 ;
F_6 ( V_20 , L_5 ) ;
goto V_46;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6 ) ;
return - V_55 ;
}
}
F_25 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_7 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_33 * * V_56 , char * V_1 ,
int V_35 , int V_57 , int V_58 )
{
int V_38 ;
if ( ! V_58 ) {
if ( F_27 ( & V_59 ) >= V_6 -> V_60 ) {
V_38 = F_24 ( V_61 ,
( F_27 ( & V_59 ) < V_6 -> V_60 ) ) ;
if ( V_38 == - V_54 )
return V_38 ;
}
V_38 = F_28 ( V_1 , & V_35 , V_56 , V_57 ) ;
if ( V_38 < 0 )
return V_38 ;
F_29 ( V_35 , & V_59 ) ;
} else {
int V_31 , V_32 = 0 ;
int V_30 = V_35 ;
while ( V_35 ) {
V_31 = F_1 ( V_1 ) ;
if ( F_30 ( V_1 ) )
V_56 [ V_32 ++ ] = F_31 ( V_1 ) ;
else
V_56 [ V_32 ++ ] = F_32 ( V_1 ) ;
V_1 += V_31 ;
V_35 -- ;
}
V_35 = V_30 ;
}
return V_35 ;
}
static int
F_33 ( struct V_3 * V_4 , struct V_17 * V_18 ,
char * V_62 , char * V_63 , int V_64 ,
int V_65 , int V_66 , int V_58 )
{
int V_39 , V_40 , V_38 , V_41 , V_42 ;
unsigned long V_19 ;
int V_67 = 0 , V_68 = 0 ;
struct V_33 * * V_69 = NULL , * * V_70 = NULL ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_26 * V_43 [ 4 ] ;
F_6 ( V_20 , L_8 ) ;
if ( V_63 ) {
V_68 = F_34 ( V_63 , V_65 ) ;
V_70 = F_35 ( sizeof( struct V_33 * ) * V_68 ,
V_71 ) ;
if ( ! V_70 ) {
V_38 = - V_72 ;
goto V_73;
}
V_68 = F_26 ( V_6 , V_70 , V_63 ,
V_68 , 0 , V_58 ) ;
if ( V_68 < 0 ) {
V_38 = V_68 ;
F_36 ( V_70 ) ;
V_70 = NULL ;
goto V_73;
}
}
if ( V_62 ) {
V_67 = F_34 ( V_62 , V_64 ) ;
V_69 = F_35 ( sizeof( struct V_33 * ) * V_67 ,
V_71 ) ;
if ( ! V_69 ) {
V_38 = - V_72 ;
goto V_73;
}
V_67 = F_26 ( V_6 , V_69 , V_62 ,
V_67 , 1 , V_58 ) ;
if ( V_67 < 0 ) {
V_38 = V_67 ;
F_36 ( V_69 ) ;
V_69 = NULL ;
goto V_73;
}
}
V_18 -> V_44 = V_45 ;
V_74:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_41 = V_42 = 0 ;
V_40 = F_13 ( V_6 -> V_27 , 0 ,
V_47 , V_18 -> V_48 -> V_49 , V_18 -> V_48 -> V_50 ) ;
if ( V_40 )
V_43 [ V_41 ++ ] = V_6 -> V_27 ;
if ( V_70 ) {
V_43 [ V_41 ++ ] = V_6 -> V_27 + V_40 ;
V_40 += F_19 ( V_6 -> V_27 , V_40 , V_47 ,
V_70 , V_68 , V_63 , V_65 ) ;
}
V_39 = F_13 ( V_6 -> V_27 , V_40 ,
V_47 , V_18 -> V_15 -> V_49 , V_66 ) ;
if ( V_39 )
V_43 [ V_41 + V_42 ++ ] = V_6 -> V_27 + V_40 ;
if ( V_69 ) {
V_43 [ V_41 + V_42 ++ ] = V_6 -> V_27 + V_40 + V_39 ;
V_39 += F_19 ( V_6 -> V_27 , V_40 + V_39 , V_47 ,
V_69 , V_67 , V_62 , V_64 ) ;
}
F_14 ( V_41 + V_42 > F_37 ( V_43 ) ) ;
V_38 = F_23 ( V_6 -> V_11 , V_43 , V_41 , V_42 , V_18 -> V_48 ,
V_52 ) ;
if ( V_38 < 0 ) {
if ( V_38 == - V_53 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_38 = F_24 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_38 == - V_54 )
goto V_73;
F_6 ( V_20 , L_5 ) ;
goto V_74;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6 ) ;
V_38 = - V_55 ;
goto V_73;
}
}
F_25 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_7 ) ;
V_38 = F_24 ( * V_18 -> V_75 ,
V_18 -> V_44 >= V_25 ) ;
V_73:
if ( ! V_58 ) {
if ( V_69 ) {
F_38 ( V_69 , V_67 ) ;
F_39 ( V_67 , & V_59 ) ;
}
if ( V_70 ) {
F_38 ( V_70 , V_68 ) ;
F_39 ( V_68 , & V_59 ) ;
}
F_10 ( & V_61 ) ;
}
F_36 ( V_69 ) ;
F_36 ( V_70 ) ;
return V_38 ;
}
static T_1 F_40 ( struct V_76 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_5 * V_6 ;
struct V_81 * V_12 ;
V_12 = F_41 ( V_77 ) ;
V_6 = V_12 -> V_13 ;
return snprintf ( V_80 , V_6 -> V_82 + 1 , L_9 , V_6 -> V_24 ) ;
}
static int F_42 ( struct V_81 * V_12 )
{
T_2 V_82 ;
char * V_24 ;
int V_38 ;
struct V_5 * V_6 ;
if ( ! V_12 -> V_83 -> V_84 ) {
F_43 ( & V_12 -> V_77 , L_10 ,
V_85 ) ;
return - V_86 ;
}
V_6 = F_35 ( sizeof( struct V_5 ) , V_87 ) ;
if ( ! V_6 ) {
F_44 ( L_11 ) ;
V_38 = - V_72 ;
goto V_88;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_45 ( V_12 , F_5 , L_12 ) ;
if ( F_46 ( V_6 -> V_11 ) ) {
V_38 = F_47 ( V_6 -> V_11 ) ;
goto V_89;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_48 ( & V_6 -> V_21 ) ;
F_49 ( V_6 -> V_27 , V_47 ) ;
V_6 -> V_9 = false ;
if ( F_50 ( V_12 , V_90 ) ) {
F_51 ( V_12 , struct V_91 , V_82 , & V_82 ) ;
} else {
V_38 = - V_86 ;
goto V_89;
}
V_24 = F_35 ( V_82 , V_87 ) ;
if ( ! V_24 ) {
V_38 = - V_72 ;
goto V_89;
}
F_52 ( V_12 , F_53 ( struct V_91 , V_24 ) ,
V_24 , V_82 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_82 = V_82 ;
V_38 = F_54 ( & ( V_12 -> V_77 . V_92 ) , & V_93 . V_79 ) ;
if ( V_38 ) {
goto V_94;
}
V_6 -> V_23 = F_35 ( sizeof( V_95 ) , V_87 ) ;
if ( ! V_6 -> V_23 ) {
V_38 = - V_72 ;
goto V_94;
}
F_55 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_60 = F_56 () / 4 ;
F_57 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_58 ( & V_6 -> V_96 , & V_97 ) ;
F_4 ( & V_8 ) ;
F_59 ( & ( V_12 -> V_77 . V_92 ) , V_98 ) ;
return 0 ;
V_94:
F_36 ( V_24 ) ;
V_89:
V_12 -> V_83 -> V_99 ( V_12 ) ;
F_36 ( V_6 ) ;
V_88:
return V_38 ;
}
static int
F_60 ( struct V_3 * V_4 , const char * V_100 , char * args )
{
struct V_5 * V_6 ;
int V_101 = - V_102 ;
int V_103 = 0 ;
F_3 ( & V_8 ) ;
F_61 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_100 , V_6 -> V_24 , V_6 -> V_82 ) &&
strlen ( V_100 ) == V_6 -> V_82 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_103 = 1 ;
break;
}
V_101 = - V_104 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_103 ) {
F_44 ( L_13 ) ;
return V_101 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_44 = V_105 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_62 ( struct V_81 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
unsigned long V_106 ;
F_3 ( & V_8 ) ;
F_63 ( & V_6 -> V_96 ) ;
V_106 = V_107 ;
while ( V_6 -> V_9 ) {
F_4 ( & V_8 ) ;
F_64 ( 250 ) ;
if ( F_65 ( V_107 , V_106 + 10 * V_108 ) ) {
F_66 ( & V_12 -> V_77 ,
L_14 ) ;
V_106 = V_107 ;
}
F_3 ( & V_8 ) ;
}
F_4 ( & V_8 ) ;
V_12 -> V_83 -> V_99 ( V_12 ) ;
F_67 ( & ( V_12 -> V_77 . V_92 ) , & V_93 . V_79 ) ;
F_59 ( & ( V_12 -> V_77 . V_92 ) , V_98 ) ;
F_36 ( V_6 -> V_24 ) ;
F_36 ( V_6 -> V_23 ) ;
F_36 ( V_6 ) ;
}
static int T_3 F_68 ( void )
{
F_69 ( & V_97 ) ;
F_70 ( & V_109 ) ;
return F_71 ( & V_110 ) ;
}
static void T_4 F_72 ( void )
{
F_73 ( & V_110 ) ;
F_74 ( & V_109 ) ;
}
