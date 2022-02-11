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
struct V_33 * * V_34 , int V_35 , T_1 V_36 , int V_30 )
{
int V_37 = 0 , V_31 ;
int V_38 = V_36 ;
int V_32 = V_28 ;
F_14 ( V_35 > ( V_29 - V_28 ) ) ;
while ( V_35 ) {
V_31 = V_2 - V_38 ;
if ( V_31 > V_30 )
V_31 = V_30 ;
F_15 ( & V_27 [ V_32 ] ) ;
F_20 ( & V_27 [ V_32 ++ ] , V_34 [ V_37 ++ ] , V_31 , V_38 ) ;
V_38 = 0 ;
V_30 -= V_31 ;
V_35 -- ;
}
if ( V_32 - V_28 )
F_17 ( & V_27 [ V_32 - 1 ] ) ;
return V_32 - V_28 ;
}
static int
F_21 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_39 ;
int V_40 , V_41 , V_42 , V_43 ;
unsigned long V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_26 * V_44 [ 2 ] ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_45 = V_46 ;
V_47:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_42 = V_43 = 0 ;
V_41 = F_13 ( V_6 -> V_27 , 0 ,
V_48 , V_18 -> V_49 -> V_50 , V_18 -> V_49 -> V_51 ) ;
if ( V_41 )
V_44 [ V_42 ++ ] = V_6 -> V_27 ;
V_40 = F_13 ( V_6 -> V_27 , V_41 ,
V_48 , V_18 -> V_15 -> V_50 , V_18 -> V_15 -> V_52 ) ;
if ( V_40 )
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_27 + V_41 ;
V_39 = F_22 ( V_6 -> V_11 , V_44 , V_42 , V_43 , V_18 -> V_49 ,
V_53 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_54 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_23 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_55 )
return V_39 ;
F_6 ( V_20 , L_5 ) ;
goto V_47;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6 ) ;
return - V_56 ;
}
}
F_24 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_7 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_33 * * * V_57 ,
struct V_58 * V_1 ,
int V_30 ,
T_1 * V_36 ,
int * V_59 )
{
int V_35 ;
int V_39 ;
if ( ! F_26 ( V_1 ) )
return 0 ;
if ( ! ( V_1 -> type & V_60 ) ) {
int V_61 ;
if ( F_27 ( & V_62 ) >= V_6 -> V_63 ) {
V_39 = F_23 ( V_64 ,
( F_27 ( & V_62 ) < V_6 -> V_63 ) ) ;
if ( V_39 == - V_55 )
return V_39 ;
}
V_61 = F_28 ( V_1 , V_57 , V_30 , V_36 ) ;
if ( V_61 < 0 )
return V_61 ;
* V_59 = 1 ;
V_35 = F_29 ( V_61 + * V_36 , V_2 ) ;
F_30 ( V_35 , & V_62 ) ;
return V_61 ;
} else {
int V_32 ;
T_1 V_16 ;
void * V_65 ;
while ( 1 ) {
V_16 = F_31 ( V_1 ) ;
if ( F_32 ( V_16 ) ) {
V_65 = V_1 -> V_66 -> V_67 + V_1 -> V_68 ;
break;
}
F_33 ( V_1 , 0 ) ;
}
if ( V_16 > V_30 )
V_16 = V_30 ;
V_35 = F_29 ( ( unsigned long ) V_65 + V_16 , V_2 ) -
( unsigned long ) V_65 / V_2 ;
* V_57 = F_34 ( sizeof( struct V_33 * ) * V_35 , V_69 ) ;
if ( ! * V_57 )
return - V_70 ;
* V_59 = 0 ;
V_65 -= ( * V_36 = ( unsigned long ) V_65 % V_2 ) ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
if ( F_35 ( V_65 ) )
( * V_57 ) [ V_32 ] = F_36 ( V_65 ) ;
else
( * V_57 ) [ V_32 ] = F_37 ( V_65 ) ;
V_65 += V_2 ;
}
return V_16 ;
}
}
static int
F_38 ( struct V_3 * V_4 , struct V_17 * V_18 ,
struct V_58 * V_71 , struct V_58 * V_72 ,
int V_73 , int V_74 , int V_75 )
{
int V_40 , V_41 , V_39 , V_42 , V_43 ;
unsigned long V_19 ;
int V_76 = 0 , V_77 = 0 ;
struct V_33 * * V_78 = NULL , * * V_79 = NULL ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_26 * V_44 [ 4 ] ;
T_1 V_36 ;
int V_59 = 0 ;
F_6 ( V_20 , L_8 ) ;
if ( V_72 ) {
int V_61 = F_25 ( V_6 , & V_79 , V_72 ,
V_74 , & V_36 , & V_59 ) ;
if ( V_61 < 0 )
return V_61 ;
V_77 = F_29 ( V_61 + V_36 , V_2 ) ;
if ( V_61 != V_74 ) {
T_2 V_80 = F_39 ( V_61 ) ;
memcpy ( & V_18 -> V_49 -> V_50 [ V_18 -> V_49 -> V_51 - 4 ] , & V_80 , 4 ) ;
V_74 = V_61 ;
}
} else if ( V_71 ) {
int V_61 = F_25 ( V_6 , & V_78 , V_71 ,
V_73 , & V_36 , & V_59 ) ;
if ( V_61 < 0 )
return V_61 ;
V_76 = F_29 ( V_61 + V_36 , V_2 ) ;
if ( V_61 != V_73 ) {
T_2 V_80 = F_39 ( V_61 ) ;
memcpy ( & V_18 -> V_49 -> V_50 [ V_18 -> V_49 -> V_51 - 4 ] , & V_80 , 4 ) ;
V_73 = V_61 ;
}
}
V_18 -> V_45 = V_46 ;
V_81:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_42 = V_43 = 0 ;
V_41 = F_13 ( V_6 -> V_27 , 0 ,
V_48 , V_18 -> V_49 -> V_50 , V_18 -> V_49 -> V_51 ) ;
if ( V_41 )
V_44 [ V_42 ++ ] = V_6 -> V_27 ;
if ( V_79 ) {
V_44 [ V_42 ++ ] = V_6 -> V_27 + V_41 ;
V_41 += F_19 ( V_6 -> V_27 , V_41 , V_48 ,
V_79 , V_77 , V_36 , V_74 ) ;
}
V_40 = F_13 ( V_6 -> V_27 , V_41 ,
V_48 , V_18 -> V_15 -> V_50 , V_75 ) ;
if ( V_40 )
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_27 + V_41 ;
if ( V_78 ) {
V_44 [ V_42 + V_43 ++ ] = V_6 -> V_27 + V_41 + V_40 ;
V_40 += F_19 ( V_6 -> V_27 , V_41 + V_40 , V_48 ,
V_78 , V_76 , V_36 , V_73 ) ;
}
F_14 ( V_42 + V_43 > F_40 ( V_44 ) ) ;
V_39 = F_22 ( V_6 -> V_11 , V_44 , V_42 , V_43 , V_18 -> V_49 ,
V_53 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_54 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_23 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_55 )
goto V_82;
F_6 ( V_20 , L_5 ) ;
goto V_81;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6 ) ;
V_39 = - V_56 ;
goto V_82;
}
}
F_24 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_7 ) ;
V_39 = F_23 ( * V_18 -> V_83 ,
V_18 -> V_45 >= V_25 ) ;
V_82:
if ( V_59 ) {
if ( V_78 ) {
F_41 ( V_78 , V_76 ) ;
F_42 ( V_76 , & V_62 ) ;
}
if ( V_79 ) {
F_41 ( V_79 , V_77 ) ;
F_42 ( V_77 , & V_62 ) ;
}
F_10 ( & V_64 ) ;
}
F_43 ( V_78 ) ;
F_43 ( V_79 ) ;
return V_39 ;
}
static T_3 F_44 ( struct V_84 * V_85 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_5 * V_6 ;
struct V_89 * V_12 ;
V_12 = F_45 ( V_85 ) ;
V_6 = V_12 -> V_13 ;
memcpy ( V_88 , V_6 -> V_24 , V_6 -> V_90 ) ;
V_88 [ V_6 -> V_90 ] = 0 ;
return V_6 -> V_90 + 1 ;
}
static int F_46 ( struct V_89 * V_12 )
{
T_4 V_90 ;
char * V_24 ;
int V_39 ;
struct V_5 * V_6 ;
if ( ! V_12 -> V_91 -> V_92 ) {
F_47 ( & V_12 -> V_85 , L_9 ,
V_93 ) ;
return - V_94 ;
}
V_6 = F_34 ( sizeof( struct V_5 ) , V_95 ) ;
if ( ! V_6 ) {
F_48 ( L_10 ) ;
V_39 = - V_70 ;
goto V_96;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_49 ( V_12 , F_5 , L_11 ) ;
if ( F_50 ( V_6 -> V_11 ) ) {
V_39 = F_51 ( V_6 -> V_11 ) ;
goto V_97;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_52 ( & V_6 -> V_21 ) ;
F_53 ( V_6 -> V_27 , V_48 ) ;
V_6 -> V_9 = false ;
if ( F_54 ( V_12 , V_98 ) ) {
F_55 ( V_12 , struct V_99 , V_90 , & V_90 ) ;
} else {
V_39 = - V_94 ;
goto V_97;
}
V_24 = F_34 ( V_90 , V_95 ) ;
if ( ! V_24 ) {
V_39 = - V_70 ;
goto V_97;
}
F_56 ( V_12 , F_57 ( struct V_99 , V_24 ) ,
V_24 , V_90 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_90 = V_90 ;
V_39 = F_58 ( & ( V_12 -> V_85 . V_100 ) , & V_101 . V_87 ) ;
if ( V_39 ) {
goto V_102;
}
V_6 -> V_23 = F_34 ( sizeof( V_103 ) , V_95 ) ;
if ( ! V_6 -> V_23 ) {
V_39 = - V_70 ;
goto V_102;
}
F_59 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_63 = F_60 () / 4 ;
F_61 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_62 ( & V_6 -> V_104 , & V_105 ) ;
F_4 ( & V_8 ) ;
F_63 ( & ( V_12 -> V_85 . V_100 ) , V_106 ) ;
return 0 ;
V_102:
F_43 ( V_24 ) ;
V_97:
V_12 -> V_91 -> V_107 ( V_12 ) ;
F_43 ( V_6 ) ;
V_96:
return V_39 ;
}
static int
F_64 ( struct V_3 * V_4 , const char * V_108 , char * args )
{
struct V_5 * V_6 ;
int V_109 = - V_110 ;
int V_111 = 0 ;
F_3 ( & V_8 ) ;
F_65 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_108 , V_6 -> V_24 , V_6 -> V_90 ) &&
strlen ( V_108 ) == V_6 -> V_90 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_111 = 1 ;
break;
}
V_109 = - V_112 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_111 ) {
F_48 ( L_12 ) ;
return V_109 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_45 = V_113 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_66 ( struct V_89 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
unsigned long V_114 ;
F_3 ( & V_8 ) ;
F_67 ( & V_6 -> V_104 ) ;
V_114 = V_115 ;
while ( V_6 -> V_9 ) {
F_4 ( & V_8 ) ;
F_68 ( 250 ) ;
if ( F_69 ( V_115 , V_114 + 10 * V_116 ) ) {
F_70 ( & V_12 -> V_85 ,
L_13 ) ;
V_114 = V_115 ;
}
F_3 ( & V_8 ) ;
}
F_4 ( & V_8 ) ;
V_12 -> V_91 -> V_117 ( V_12 ) ;
V_12 -> V_91 -> V_107 ( V_12 ) ;
F_71 ( & ( V_12 -> V_85 . V_100 ) , & V_101 . V_87 ) ;
F_63 ( & ( V_12 -> V_85 . V_100 ) , V_106 ) ;
F_43 ( V_6 -> V_24 ) ;
F_43 ( V_6 -> V_23 ) ;
F_43 ( V_6 ) ;
}
static int T_5 F_72 ( void )
{
F_73 ( & V_105 ) ;
F_74 ( & V_118 ) ;
return F_75 ( & V_119 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_119 ) ;
F_78 ( & V_118 ) ;
}
