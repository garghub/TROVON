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
V_18 -> V_25 = V_26 ;
F_12 ( V_6 -> V_4 , V_18 ) ;
}
}
static int F_13 ( struct V_27 * V_28 , int V_29 ,
int V_30 , char * V_1 , int V_31 )
{
int V_32 ;
int V_33 = V_29 ;
while ( V_31 ) {
V_32 = F_1 ( V_1 ) ;
if ( V_32 > V_31 )
V_32 = V_31 ;
F_14 ( V_33 > V_30 ) ;
F_15 ( & V_28 [ V_33 ] ) ;
F_16 ( & V_28 [ V_33 ++ ] , V_1 , V_32 ) ;
V_31 -= V_32 ;
V_1 += V_32 ;
}
if ( V_33 - V_29 )
F_17 ( & V_28 [ V_33 - 1 ] ) ;
return V_33 - V_29 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
return 1 ;
}
static int
F_19 ( struct V_27 * V_28 , int V_29 , int V_30 ,
struct V_34 * * V_35 , int V_36 , char * V_1 , int V_31 )
{
int V_37 = 0 , V_32 ;
int V_38 ;
int V_33 = V_29 ;
F_14 ( V_36 > ( V_30 - V_29 ) ) ;
V_38 = F_20 ( V_1 ) ;
while ( V_36 ) {
V_32 = F_1 ( V_1 ) ;
if ( V_32 > V_31 )
V_32 = V_31 ;
F_15 ( & V_28 [ V_33 ] ) ;
F_21 ( & V_28 [ V_33 ++ ] , V_35 [ V_37 ++ ] , V_32 , V_38 ) ;
V_38 = 0 ;
V_1 += V_32 ;
V_31 -= V_32 ;
V_36 -- ;
}
if ( V_33 - V_29 )
F_17 ( & V_28 [ V_33 - 1 ] ) ;
return V_33 - V_29 ;
}
static int
F_22 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_39 ;
int V_40 , V_41 , V_42 , V_43 ;
unsigned long V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_27 * V_44 [ 2 ] ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_25 = V_45 ;
V_46:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_42 = V_43 = 0 ;
V_41 = F_13 ( V_6 -> V_28 , 0 ,
V_47 , V_18 -> V_48 -> V_49 , V_18 -> V_48 -> V_50 ) ;
if ( V_41 )
V_44 [ V_42 ++ ] = V_6 -> V_28 ;
V_40 = F_13 ( V_6 -> V_28 , V_41 ,
V_47 , V_18 -> V_15 -> V_49 , V_18 -> V_15 -> V_51 ) ;
if ( V_40 )
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_28 + V_41 ;
V_39 = F_23 ( V_6 -> V_11 , V_44 , V_42 , V_43 , V_18 -> V_48 ,
V_52 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_53 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_24 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_54 )
return V_39 ;
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
struct V_34 * * V_56 , char * V_1 ,
int V_36 , int V_57 , int V_58 )
{
int V_39 ;
if ( ! V_58 ) {
if ( F_27 ( & V_59 ) >= V_6 -> V_60 ) {
V_39 = F_24 ( V_61 ,
( F_27 ( & V_59 ) < V_6 -> V_60 ) ) ;
if ( V_39 == - V_54 )
return V_39 ;
}
V_39 = F_28 ( V_1 , & V_36 , V_56 , V_57 ) ;
if ( V_39 < 0 )
return V_39 ;
F_29 ( V_36 , & V_59 ) ;
} else {
int V_32 , V_33 = 0 ;
int V_31 = V_36 ;
while ( V_36 ) {
V_32 = F_1 ( V_1 ) ;
V_56 [ V_33 ++ ] = F_30 ( V_1 ) ;
V_1 += V_32 ;
V_36 -- ;
}
V_36 = V_31 ;
}
return V_36 ;
}
static int
F_31 ( struct V_3 * V_4 , struct V_17 * V_18 ,
char * V_62 , char * V_63 , int V_64 ,
int V_65 , int V_66 , int V_58 )
{
int V_40 , V_41 , V_39 , V_42 , V_43 ;
unsigned long V_19 ;
int V_67 = 0 , V_68 = 0 ;
struct V_34 * * V_69 = NULL , * * V_70 = NULL ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_27 * V_44 [ 4 ] ;
F_6 ( V_20 , L_8 ) ;
if ( V_63 ) {
V_68 = F_32 ( V_63 , V_65 ) ;
V_70 = F_33 ( sizeof( struct V_34 * ) * V_68 ,
V_71 ) ;
if ( ! V_70 ) {
V_39 = - V_72 ;
goto V_73;
}
V_68 = F_26 ( V_6 , V_70 , V_63 ,
V_68 , 0 , V_58 ) ;
if ( V_68 < 0 ) {
V_39 = V_68 ;
F_34 ( V_70 ) ;
V_70 = NULL ;
goto V_73;
}
}
if ( V_62 ) {
V_67 = F_32 ( V_62 , V_64 ) ;
V_69 = F_33 ( sizeof( struct V_34 * ) * V_67 ,
V_71 ) ;
if ( ! V_69 ) {
V_39 = - V_72 ;
goto V_73;
}
V_67 = F_26 ( V_6 , V_69 , V_62 ,
V_67 , 1 , V_58 ) ;
if ( V_67 < 0 ) {
V_39 = V_67 ;
F_34 ( V_69 ) ;
V_69 = NULL ;
goto V_73;
}
}
V_18 -> V_25 = V_45 ;
V_74:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_42 = V_43 = 0 ;
V_41 = F_13 ( V_6 -> V_28 , 0 ,
V_47 , V_18 -> V_48 -> V_49 , V_18 -> V_48 -> V_50 ) ;
if ( V_41 )
V_44 [ V_42 ++ ] = V_6 -> V_28 ;
if ( V_70 ) {
V_44 [ V_42 ++ ] = V_6 -> V_28 + V_41 ;
V_41 += F_19 ( V_6 -> V_28 , V_41 , V_47 ,
V_70 , V_68 , V_63 , V_65 ) ;
}
V_40 = F_13 ( V_6 -> V_28 , V_41 ,
V_47 , V_18 -> V_15 -> V_49 , V_66 ) ;
if ( V_40 )
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_28 + V_41 ;
if ( V_69 ) {
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_28 + V_41 + V_40 ;
V_40 += F_19 ( V_6 -> V_28 , V_41 + V_40 , V_47 ,
V_69 , V_67 , V_62 , V_64 ) ;
}
F_14 ( V_42 + V_43 > F_35 ( V_44 ) ) ;
V_39 = F_23 ( V_6 -> V_11 , V_44 , V_42 , V_43 , V_18 -> V_48 ,
V_52 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_53 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_24 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_54 )
goto V_73;
F_6 ( V_20 , L_5 ) ;
goto V_74;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6 ) ;
V_39 = - V_55 ;
goto V_73;
}
}
F_25 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_7 ) ;
V_39 = F_24 ( * V_18 -> V_75 ,
V_18 -> V_25 >= V_26 ) ;
V_73:
if ( ! V_58 ) {
if ( V_69 ) {
F_36 ( V_69 , V_67 ) ;
F_37 ( V_67 , & V_59 ) ;
}
if ( V_70 ) {
F_36 ( V_70 , V_68 ) ;
F_37 ( V_68 , & V_59 ) ;
}
F_10 ( & V_61 ) ;
}
F_34 ( V_69 ) ;
F_34 ( V_70 ) ;
return V_39 ;
}
static T_1 F_38 ( struct V_76 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_5 * V_6 ;
struct V_81 * V_12 ;
V_12 = F_39 ( V_77 ) ;
V_6 = V_12 -> V_13 ;
return snprintf ( V_80 , V_6 -> V_82 + 1 , L_9 , V_6 -> V_24 ) ;
}
static int F_40 ( struct V_81 * V_12 )
{
T_2 V_82 ;
char * V_24 ;
int V_39 ;
struct V_5 * V_6 ;
V_6 = F_33 ( sizeof( struct V_5 ) , V_83 ) ;
if ( ! V_6 ) {
F_41 ( L_10 ) ;
V_39 = - V_72 ;
goto V_84;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_42 ( V_12 , F_5 , L_11 ) ;
if ( F_43 ( V_6 -> V_11 ) ) {
V_39 = F_44 ( V_6 -> V_11 ) ;
goto V_85;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_45 ( & V_6 -> V_21 ) ;
F_46 ( V_6 -> V_28 , V_47 ) ;
V_6 -> V_9 = false ;
if ( F_47 ( V_12 , V_86 ) ) {
V_12 -> V_87 -> V_88 ( V_12 ,
F_48 ( struct V_89 , V_82 ) ,
& V_82 , sizeof( V_82 ) ) ;
} else {
V_39 = - V_90 ;
goto V_85;
}
V_24 = F_33 ( V_82 , V_83 ) ;
if ( ! V_24 ) {
V_39 = - V_72 ;
goto V_85;
}
V_12 -> V_87 -> V_88 ( V_12 , F_48 ( struct V_89 , V_24 ) ,
V_24 , V_82 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_82 = V_82 ;
V_39 = F_49 ( & ( V_12 -> V_77 . V_91 ) , & V_92 . V_79 ) ;
if ( V_39 ) {
goto V_93;
}
V_6 -> V_23 = F_33 ( sizeof( V_94 ) , V_83 ) ;
if ( ! V_6 -> V_23 ) {
V_39 = - V_72 ;
goto V_93;
}
F_50 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_60 = F_51 () / 4 ;
F_3 ( & V_8 ) ;
F_52 ( & V_6 -> V_95 , & V_96 ) ;
F_4 ( & V_8 ) ;
F_53 ( & ( V_12 -> V_77 . V_91 ) , V_97 ) ;
return 0 ;
V_93:
F_34 ( V_24 ) ;
V_85:
V_12 -> V_87 -> V_98 ( V_12 ) ;
F_34 ( V_6 ) ;
V_84:
return V_39 ;
}
static int
F_54 ( struct V_3 * V_4 , const char * V_99 , char * args )
{
struct V_5 * V_6 ;
int V_100 = - V_101 ;
int V_102 = 0 ;
F_3 ( & V_8 ) ;
F_55 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_99 , V_6 -> V_24 , V_6 -> V_82 ) &&
strlen ( V_99 ) == V_6 -> V_82 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_102 = 1 ;
break;
}
V_100 = - V_103 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_102 ) {
F_41 ( L_12 ) ;
return V_100 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_25 = V_104 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_56 ( struct V_81 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
if ( V_6 -> V_9 )
F_2 ( V_6 -> V_4 ) ;
V_12 -> V_87 -> V_98 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_57 ( & V_6 -> V_95 ) ;
F_4 ( & V_8 ) ;
F_58 ( & ( V_12 -> V_77 . V_91 ) , & V_92 . V_79 ) ;
F_53 ( & ( V_12 -> V_77 . V_91 ) , V_97 ) ;
F_34 ( V_6 -> V_24 ) ;
F_34 ( V_6 -> V_23 ) ;
F_34 ( V_6 ) ;
}
static int T_3 F_59 ( void )
{
F_60 ( & V_96 ) ;
F_61 ( & V_105 ) ;
return F_62 ( & V_106 ) ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_106 ) ;
F_65 ( & V_105 ) ;
}
