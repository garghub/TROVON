static unsigned int F_1 ( void * V_1 )
{
return V_2 - F_2 ( V_1 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_4 ( & V_8 ) ;
if ( V_6 )
V_6 -> V_9 = false ;
F_5 ( & V_8 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_12 -> V_13 ;
unsigned int V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
F_7 ( V_18 , L_1 ) ;
while ( 1 ) {
F_8 ( & V_6 -> V_19 , V_17 ) ;
V_16 = F_9 ( V_6 -> V_11 , & V_14 ) ;
if ( V_16 == NULL ) {
F_10 ( & V_6 -> V_19 , V_17 ) ;
break;
}
V_6 -> V_20 = 1 ;
F_10 ( & V_6 -> V_19 , V_17 ) ;
F_11 ( V_6 -> V_21 ) ;
F_12 ( V_6 -> V_4 , V_16 , V_22 ) ;
}
}
static int F_13 ( struct V_23 * V_24 , int V_25 ,
int V_26 , char * V_1 , int V_27 )
{
int V_28 ;
int V_29 = V_25 ;
while ( V_27 ) {
V_28 = F_1 ( V_1 ) ;
if ( V_28 > V_27 )
V_28 = V_27 ;
F_14 ( V_29 > V_26 ) ;
F_15 ( & V_24 [ V_29 ] ) ;
F_16 ( & V_24 [ V_29 ++ ] , V_1 , V_28 ) ;
V_27 -= V_28 ;
V_1 += V_28 ;
}
if ( V_29 - V_25 )
F_17 ( & V_24 [ V_29 - 1 ] ) ;
return V_29 - V_25 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
return 1 ;
}
static int
F_19 ( struct V_23 * V_24 , int V_25 , int V_26 ,
struct V_30 * * V_31 , int V_32 , T_1 V_33 , int V_27 )
{
int V_34 = 0 , V_28 ;
int V_35 = V_33 ;
int V_29 = V_25 ;
F_14 ( V_32 > ( V_26 - V_25 ) ) ;
while ( V_32 ) {
V_28 = V_2 - V_35 ;
if ( V_28 > V_27 )
V_28 = V_27 ;
F_15 ( & V_24 [ V_29 ] ) ;
F_20 ( & V_24 [ V_29 ++ ] , V_31 [ V_34 ++ ] , V_28 , V_35 ) ;
V_35 = 0 ;
V_27 -= V_28 ;
V_32 -- ;
}
if ( V_29 - V_25 )
F_17 ( & V_24 [ V_29 - 1 ] ) ;
return V_29 - V_25 ;
}
static int
F_21 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
int V_36 ;
int V_37 , V_38 , V_39 , V_40 ;
unsigned long V_17 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_23 * V_41 [ 2 ] ;
F_7 ( V_18 , L_2 ) ;
V_16 -> V_42 = V_43 ;
V_44:
F_8 ( & V_6 -> V_19 , V_17 ) ;
V_39 = V_40 = 0 ;
V_38 = F_13 ( V_6 -> V_24 , 0 ,
V_45 , V_16 -> V_46 -> V_47 , V_16 -> V_46 -> V_48 ) ;
if ( V_38 )
V_41 [ V_39 ++ ] = V_6 -> V_24 ;
V_37 = F_13 ( V_6 -> V_24 , V_38 ,
V_45 , V_16 -> V_49 -> V_47 , V_16 -> V_49 -> V_50 ) ;
if ( V_37 )
V_41 [ V_39 + V_40 ++ ] = V_6 -> V_24 + V_38 ;
V_36 = F_22 ( V_6 -> V_11 , V_41 , V_39 , V_40 , V_16 ,
V_51 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_52 ) {
V_6 -> V_20 = 0 ;
F_10 ( & V_6 -> V_19 , V_17 ) ;
V_36 = F_23 ( * V_6 -> V_21 ,
V_6 -> V_20 ) ;
if ( V_36 == - V_53 )
return V_36 ;
F_7 ( V_18 , L_3 ) ;
goto V_44;
} else {
F_10 ( & V_6 -> V_19 , V_17 ) ;
F_7 ( V_18 ,
L_4 ) ;
return - V_54 ;
}
}
F_24 ( V_6 -> V_11 ) ;
F_10 ( & V_6 -> V_19 , V_17 ) ;
F_7 ( V_18 , L_5 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_30 * * * V_55 ,
struct V_56 * V_1 ,
int V_27 ,
T_1 * V_33 ,
int * V_57 )
{
int V_32 ;
int V_36 ;
if ( ! F_26 ( V_1 ) )
return 0 ;
if ( ! ( V_1 -> type & V_58 ) ) {
int V_59 ;
if ( F_27 ( & V_60 ) >= V_6 -> V_61 ) {
V_36 = F_23 ( V_62 ,
( F_27 ( & V_60 ) < V_6 -> V_61 ) ) ;
if ( V_36 == - V_53 )
return V_36 ;
}
V_59 = F_28 ( V_1 , V_55 , V_27 , V_33 ) ;
if ( V_59 < 0 )
return V_59 ;
* V_57 = 1 ;
V_32 = F_29 ( V_59 + * V_33 , V_2 ) ;
F_30 ( V_32 , & V_60 ) ;
return V_59 ;
} else {
int V_29 ;
T_1 V_14 ;
void * V_63 ;
while ( 1 ) {
V_14 = F_31 ( V_1 ) ;
if ( F_32 ( V_14 ) ) {
V_63 = V_1 -> V_64 -> V_65 + V_1 -> V_66 ;
break;
}
F_33 ( V_1 , 0 ) ;
}
if ( V_14 > V_27 )
V_14 = V_27 ;
V_32 = F_29 ( ( unsigned long ) V_63 + V_14 , V_2 ) -
( unsigned long ) V_63 / V_2 ;
* V_55 = F_34 ( sizeof( struct V_30 * ) * V_32 , V_67 ) ;
if ( ! * V_55 )
return - V_68 ;
* V_57 = 0 ;
V_63 -= ( * V_33 = F_2 ( V_63 ) ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
if ( F_35 ( V_63 ) )
( * V_55 ) [ V_29 ] = F_36 ( V_63 ) ;
else
( * V_55 ) [ V_29 ] = F_37 ( V_63 ) ;
V_63 += V_2 ;
}
return V_14 ;
}
}
static int
F_38 ( struct V_3 * V_4 , struct V_15 * V_16 ,
struct V_56 * V_69 , struct V_56 * V_70 ,
int V_71 , int V_72 , int V_73 )
{
int V_37 , V_38 , V_36 , V_39 , V_40 ;
unsigned long V_17 ;
int V_74 = 0 , V_75 = 0 ;
struct V_30 * * V_76 = NULL , * * V_77 = NULL ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_23 * V_41 [ 4 ] ;
T_1 V_33 ;
int V_57 = 0 ;
F_7 ( V_18 , L_6 ) ;
if ( V_70 ) {
int V_59 = F_25 ( V_6 , & V_77 , V_70 ,
V_72 , & V_33 , & V_57 ) ;
if ( V_59 < 0 )
return V_59 ;
V_75 = F_29 ( V_59 + V_33 , V_2 ) ;
if ( V_59 != V_72 ) {
T_2 V_78 = F_39 ( V_59 ) ;
memcpy ( & V_16 -> V_46 -> V_47 [ V_16 -> V_46 -> V_48 - 4 ] , & V_78 , 4 ) ;
V_72 = V_59 ;
}
} else if ( V_69 ) {
int V_59 = F_25 ( V_6 , & V_76 , V_69 ,
V_71 , & V_33 , & V_57 ) ;
if ( V_59 < 0 )
return V_59 ;
V_74 = F_29 ( V_59 + V_33 , V_2 ) ;
if ( V_59 != V_71 ) {
T_2 V_78 = F_39 ( V_59 ) ;
memcpy ( & V_16 -> V_46 -> V_47 [ V_16 -> V_46 -> V_48 - 4 ] , & V_78 , 4 ) ;
V_71 = V_59 ;
}
}
V_16 -> V_42 = V_43 ;
V_79:
F_8 ( & V_6 -> V_19 , V_17 ) ;
V_39 = V_40 = 0 ;
V_38 = F_13 ( V_6 -> V_24 , 0 ,
V_45 , V_16 -> V_46 -> V_47 , V_16 -> V_46 -> V_48 ) ;
if ( V_38 )
V_41 [ V_39 ++ ] = V_6 -> V_24 ;
if ( V_77 ) {
V_41 [ V_39 ++ ] = V_6 -> V_24 + V_38 ;
V_38 += F_19 ( V_6 -> V_24 , V_38 , V_45 ,
V_77 , V_75 , V_33 , V_72 ) ;
}
V_37 = F_13 ( V_6 -> V_24 , V_38 ,
V_45 , V_16 -> V_49 -> V_47 , V_73 ) ;
if ( V_37 )
V_41 [ V_39 + V_40 ++ ] = V_6 -> V_24 + V_38 ;
if ( V_76 ) {
V_41 [ V_39 + V_40 ++ ] = V_6 -> V_24 + V_38 + V_37 ;
V_37 += F_19 ( V_6 -> V_24 , V_38 + V_37 , V_45 ,
V_76 , V_74 , V_33 , V_71 ) ;
}
F_14 ( V_39 + V_40 > F_40 ( V_41 ) ) ;
V_36 = F_22 ( V_6 -> V_11 , V_41 , V_39 , V_40 , V_16 ,
V_51 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_52 ) {
V_6 -> V_20 = 0 ;
F_10 ( & V_6 -> V_19 , V_17 ) ;
V_36 = F_23 ( * V_6 -> V_21 ,
V_6 -> V_20 ) ;
if ( V_36 == - V_53 )
goto V_80;
F_7 ( V_18 , L_3 ) ;
goto V_79;
} else {
F_10 ( & V_6 -> V_19 , V_17 ) ;
F_7 ( V_18 ,
L_4 ) ;
V_36 = - V_54 ;
goto V_80;
}
}
F_24 ( V_6 -> V_11 ) ;
F_10 ( & V_6 -> V_19 , V_17 ) ;
F_7 ( V_18 , L_5 ) ;
V_36 = F_23 ( * V_16 -> V_81 ,
V_16 -> V_42 >= V_22 ) ;
V_80:
if ( V_57 ) {
if ( V_76 ) {
F_41 ( V_76 , V_74 ) ;
F_42 ( V_74 , & V_60 ) ;
}
if ( V_77 ) {
F_41 ( V_77 , V_75 ) ;
F_42 ( V_75 , & V_60 ) ;
}
F_11 ( & V_62 ) ;
}
F_43 ( V_76 ) ;
F_43 ( V_77 ) ;
return V_36 ;
}
static T_3 F_44 ( struct V_82 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_5 * V_6 ;
struct V_87 * V_12 ;
V_12 = F_45 ( V_83 ) ;
V_6 = V_12 -> V_13 ;
memcpy ( V_86 , V_6 -> V_88 , V_6 -> V_89 ) ;
V_86 [ V_6 -> V_89 ] = 0 ;
return V_6 -> V_89 + 1 ;
}
static int F_46 ( struct V_87 * V_12 )
{
T_4 V_89 ;
char * V_88 ;
int V_36 ;
struct V_5 * V_6 ;
if ( ! V_12 -> V_90 -> V_91 ) {
F_47 ( & V_12 -> V_83 , L_7 ,
V_92 ) ;
return - V_93 ;
}
V_6 = F_34 ( sizeof( struct V_5 ) , V_94 ) ;
if ( ! V_6 ) {
F_48 ( L_8 ) ;
V_36 = - V_68 ;
goto V_95;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_49 ( V_12 , F_6 , L_9 ) ;
if ( F_50 ( V_6 -> V_11 ) ) {
V_36 = F_51 ( V_6 -> V_11 ) ;
goto V_96;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_52 ( & V_6 -> V_19 ) ;
F_53 ( V_6 -> V_24 , V_45 ) ;
V_6 -> V_9 = false ;
if ( F_54 ( V_12 , V_97 ) ) {
F_55 ( V_12 , struct V_98 , V_89 , & V_89 ) ;
} else {
V_36 = - V_93 ;
goto V_96;
}
V_88 = F_34 ( V_89 , V_94 ) ;
if ( ! V_88 ) {
V_36 = - V_68 ;
goto V_96;
}
F_56 ( V_12 , F_57 ( struct V_98 , V_88 ) ,
V_88 , V_89 ) ;
V_6 -> V_88 = V_88 ;
V_6 -> V_89 = V_89 ;
V_36 = F_58 ( & ( V_12 -> V_83 . V_99 ) , & V_100 . V_85 ) ;
if ( V_36 ) {
goto V_101;
}
V_6 -> V_21 = F_34 ( sizeof( V_102 ) , V_94 ) ;
if ( ! V_6 -> V_21 ) {
V_36 = - V_68 ;
goto V_101;
}
F_59 ( V_6 -> V_21 ) ;
V_6 -> V_20 = 1 ;
V_6 -> V_61 = F_60 () / 4 ;
F_61 ( V_12 ) ;
F_4 ( & V_8 ) ;
F_62 ( & V_6 -> V_103 , & V_104 ) ;
F_5 ( & V_8 ) ;
F_63 ( & ( V_12 -> V_83 . V_99 ) , V_105 ) ;
return 0 ;
V_101:
F_43 ( V_88 ) ;
V_96:
V_12 -> V_90 -> V_106 ( V_12 ) ;
F_43 ( V_6 ) ;
V_95:
return V_36 ;
}
static int
F_64 ( struct V_3 * V_4 , const char * V_107 , char * args )
{
struct V_5 * V_6 ;
int V_108 = - V_109 ;
int V_110 = 0 ;
F_4 ( & V_8 ) ;
F_65 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_107 , V_6 -> V_88 , V_6 -> V_89 ) &&
strlen ( V_107 ) == V_6 -> V_89 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_110 = 1 ;
break;
}
V_108 = - V_111 ;
}
}
F_5 ( & V_8 ) ;
if ( ! V_110 ) {
F_48 ( L_10 , V_107 ) ;
return V_108 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_42 = V_112 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_66 ( struct V_87 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
unsigned long V_113 ;
F_4 ( & V_8 ) ;
F_67 ( & V_6 -> V_103 ) ;
V_113 = V_114 ;
while ( V_6 -> V_9 ) {
F_5 ( & V_8 ) ;
F_68 ( 250 ) ;
if ( F_69 ( V_114 , V_113 + 10 * V_115 ) ) {
F_70 ( & V_12 -> V_83 ,
L_11 ) ;
V_113 = V_114 ;
}
F_4 ( & V_8 ) ;
}
F_5 ( & V_8 ) ;
V_12 -> V_90 -> V_116 ( V_12 ) ;
V_12 -> V_90 -> V_106 ( V_12 ) ;
F_71 ( & ( V_12 -> V_83 . V_99 ) , & V_100 . V_85 ) ;
F_63 ( & ( V_12 -> V_83 . V_99 ) , V_105 ) ;
F_43 ( V_6 -> V_88 ) ;
F_43 ( V_6 -> V_21 ) ;
F_43 ( V_6 ) ;
}
static int T_5 F_72 ( void )
{
F_73 ( & V_104 ) ;
F_74 ( & V_117 ) ;
return F_75 ( & V_118 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_118 ) ;
F_78 ( & V_117 ) ;
}
