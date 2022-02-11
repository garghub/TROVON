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
F_14 ( & V_28 [ V_33 ++ ] , V_1 , V_32 ) ;
V_31 -= V_32 ;
V_1 += V_32 ;
F_15 ( V_33 > V_30 ) ;
}
return V_33 - V_29 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
return 1 ;
}
static int
F_17 ( struct V_27 * V_28 , int V_29 , int V_30 ,
struct V_34 * * V_35 , int V_36 , char * V_1 , int V_31 )
{
int V_37 = 0 , V_32 ;
int V_38 ;
int V_33 = V_29 ;
F_15 ( V_36 > ( V_30 - V_29 ) ) ;
V_38 = F_18 ( V_1 ) ;
while ( V_36 ) {
V_32 = F_1 ( V_1 ) ;
if ( V_32 > V_31 )
V_32 = V_31 ;
F_19 ( & V_28 [ V_33 ++ ] , V_35 [ V_37 ++ ] , V_32 , V_38 ) ;
V_38 = 0 ;
V_1 += V_32 ;
V_31 -= V_32 ;
V_36 -- ;
}
return V_33 - V_29 ;
}
static int
F_20 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_39 ;
int V_40 , V_41 ;
unsigned long V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_6 ( V_20 , L_4 ) ;
V_18 -> V_25 = V_42 ;
V_43:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_41 = F_13 ( V_6 -> V_28 , 0 ,
V_44 , V_18 -> V_45 -> V_46 , V_18 -> V_45 -> V_47 ) ;
V_40 = F_13 ( V_6 -> V_28 , V_41 ,
V_44 , V_18 -> V_15 -> V_46 , V_18 -> V_15 -> V_48 ) ;
V_39 = F_21 ( V_6 -> V_11 , V_6 -> V_28 , V_41 , V_40 , V_18 -> V_45 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_49 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_22 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_50 )
return V_39 ;
F_6 ( V_20 , L_5 ) ;
goto V_43;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6
L_7 ) ;
return - V_51 ;
}
}
F_23 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_8 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_34 * * V_52 , char * V_1 ,
int V_36 , int V_53 , int V_54 )
{
int V_39 ;
if ( ! V_54 ) {
if ( F_25 ( & V_55 ) >= V_6 -> V_56 ) {
V_39 = F_22 ( V_57 ,
( F_25 ( & V_55 ) < V_6 -> V_56 ) ) ;
if ( V_39 == - V_50 )
return V_39 ;
}
V_39 = F_26 ( V_1 , & V_36 , V_52 , V_53 ) ;
if ( V_39 < 0 )
return V_39 ;
F_27 ( V_36 , & V_55 ) ;
} else {
int V_32 , V_33 = 0 ;
int V_31 = V_36 ;
while ( V_36 ) {
V_32 = F_1 ( V_1 ) ;
V_52 [ V_33 ++ ] = F_28 ( V_1 ) ;
V_1 += V_32 ;
V_36 -- ;
}
V_36 = V_31 ;
}
return V_36 ;
}
static int
F_29 ( struct V_3 * V_4 , struct V_17 * V_18 ,
char * V_58 , char * V_59 , int V_60 ,
int V_61 , int V_62 , int V_54 )
{
int V_40 , V_41 , V_39 ;
unsigned long V_19 ;
int V_63 = 0 , V_64 = 0 ;
struct V_34 * * V_65 = NULL , * * V_66 = NULL ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_6 ( V_20 , L_4 ) ;
if ( V_59 ) {
V_64 = F_30 ( V_59 , V_61 ) ;
V_66 = F_31 ( sizeof( struct V_34 * ) * V_64 ,
V_67 ) ;
if ( ! V_66 ) {
V_39 = - V_68 ;
goto V_69;
}
V_64 = F_24 ( V_6 , V_66 , V_59 ,
V_64 , 0 , V_54 ) ;
if ( V_64 < 0 ) {
V_39 = V_64 ;
F_32 ( V_66 ) ;
V_66 = NULL ;
goto V_69;
}
}
if ( V_58 ) {
V_63 = F_30 ( V_58 , V_60 ) ;
V_65 = F_31 ( sizeof( struct V_34 * ) * V_63 ,
V_67 ) ;
if ( ! V_65 ) {
V_39 = - V_68 ;
goto V_69;
}
V_63 = F_24 ( V_6 , V_65 , V_58 ,
V_63 , 1 , V_54 ) ;
if ( V_63 < 0 ) {
V_39 = V_63 ;
F_32 ( V_65 ) ;
V_65 = NULL ;
goto V_69;
}
}
V_18 -> V_25 = V_42 ;
V_70:
F_7 ( & V_6 -> V_21 , V_19 ) ;
V_41 = F_13 ( V_6 -> V_28 , 0 ,
V_44 , V_18 -> V_45 -> V_46 , V_18 -> V_45 -> V_47 ) ;
if ( V_66 )
V_41 += F_17 ( V_6 -> V_28 , V_41 , V_44 ,
V_66 , V_64 , V_59 , V_61 ) ;
V_40 = F_13 ( V_6 -> V_28 , V_41 ,
V_44 , V_18 -> V_15 -> V_46 , V_62 ) ;
if ( V_65 )
V_40 += F_17 ( V_6 -> V_28 , V_41 + V_40 , V_44 ,
V_65 , V_63 , V_58 , V_60 ) ;
V_39 = F_21 ( V_6 -> V_11 , V_6 -> V_28 , V_41 , V_40 , V_18 -> V_45 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_49 ) {
V_6 -> V_22 = 0 ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
V_39 = F_22 ( * V_6 -> V_23 ,
V_6 -> V_22 ) ;
if ( V_39 == - V_50 )
goto V_69;
F_6 ( V_20 , L_5 ) ;
goto V_70;
} else {
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 ,
L_6
L_7 ) ;
V_39 = - V_51 ;
goto V_69;
}
}
F_23 ( V_6 -> V_11 ) ;
F_9 ( & V_6 -> V_21 , V_19 ) ;
F_6 ( V_20 , L_8 ) ;
V_39 = F_22 ( * V_18 -> V_71 ,
V_18 -> V_25 >= V_26 ) ;
V_69:
if ( ! V_54 ) {
if ( V_65 ) {
F_33 ( V_65 , V_63 ) ;
F_34 ( V_63 , & V_55 ) ;
}
if ( V_66 ) {
F_33 ( V_66 , V_64 ) ;
F_34 ( V_64 , & V_55 ) ;
}
F_10 ( & V_57 ) ;
}
F_32 ( V_65 ) ;
F_32 ( V_66 ) ;
return V_39 ;
}
static T_1 F_35 ( struct V_72 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_5 * V_6 ;
struct V_77 * V_12 ;
V_12 = F_36 ( V_73 ) ;
V_6 = V_12 -> V_13 ;
return snprintf ( V_76 , V_6 -> V_78 + 1 , L_9 , V_6 -> V_24 ) ;
}
static int F_37 ( struct V_77 * V_12 )
{
T_2 V_78 ;
char * V_24 ;
int V_39 ;
struct V_5 * V_6 ;
V_6 = F_31 ( sizeof( struct V_5 ) , V_79 ) ;
if ( ! V_6 ) {
F_38 ( V_80 L_10 ) ;
V_39 = - V_68 ;
goto V_81;
}
V_6 -> V_12 = V_12 ;
V_6 -> V_11 = F_39 ( V_12 , F_5 , L_11 ) ;
if ( F_40 ( V_6 -> V_11 ) ) {
V_39 = F_41 ( V_6 -> V_11 ) ;
goto V_82;
}
V_6 -> V_11 -> V_12 -> V_13 = V_6 ;
F_42 ( & V_6 -> V_21 ) ;
F_43 ( V_6 -> V_28 , V_44 ) ;
V_6 -> V_9 = false ;
if ( F_44 ( V_12 , V_83 ) ) {
V_12 -> V_84 -> V_85 ( V_12 ,
F_45 ( struct V_86 , V_78 ) ,
& V_78 , sizeof( V_78 ) ) ;
} else {
V_39 = - V_87 ;
goto V_82;
}
V_24 = F_31 ( V_78 , V_79 ) ;
if ( ! V_24 ) {
V_39 = - V_68 ;
goto V_82;
}
V_12 -> V_84 -> V_85 ( V_12 , F_45 ( struct V_86 , V_24 ) ,
V_24 , V_78 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_78 = V_78 ;
V_39 = F_46 ( & ( V_12 -> V_73 . V_88 ) , & V_89 . V_75 ) ;
if ( V_39 ) {
goto V_90;
}
V_6 -> V_23 = F_31 ( sizeof( V_91 ) , V_79 ) ;
if ( ! V_6 -> V_23 ) {
V_39 = - V_68 ;
goto V_90;
}
F_47 ( V_6 -> V_23 ) ;
V_6 -> V_22 = 1 ;
V_6 -> V_56 = F_48 () / 4 ;
F_3 ( & V_8 ) ;
F_49 ( & V_6 -> V_92 , & V_93 ) ;
F_4 ( & V_8 ) ;
return 0 ;
V_90:
F_32 ( V_24 ) ;
V_82:
V_12 -> V_84 -> V_94 ( V_12 ) ;
F_32 ( V_6 ) ;
V_81:
return V_39 ;
}
static int
F_50 ( struct V_3 * V_4 , const char * V_95 , char * args )
{
struct V_5 * V_6 ;
int V_96 = - V_97 ;
int V_98 = 0 ;
F_3 ( & V_8 ) ;
F_51 (chan, &virtio_chan_list, chan_list) {
if ( ! strncmp ( V_95 , V_6 -> V_24 , V_6 -> V_78 ) &&
strlen ( V_95 ) == V_6 -> V_78 ) {
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = true ;
V_98 = 1 ;
break;
}
V_96 = - V_99 ;
}
}
F_4 ( & V_8 ) ;
if ( ! V_98 ) {
F_38 ( V_80 L_12 ) ;
return V_96 ;
}
V_4 -> V_7 = ( void * ) V_6 ;
V_4 -> V_25 = V_100 ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
static void F_52 ( struct V_77 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
F_15 ( V_6 -> V_9 ) ;
V_12 -> V_84 -> V_94 ( V_12 ) ;
F_3 ( & V_8 ) ;
F_53 ( & V_6 -> V_92 ) ;
F_4 ( & V_8 ) ;
F_54 ( & ( V_12 -> V_73 . V_88 ) , & V_89 . V_75 ) ;
F_32 ( V_6 -> V_24 ) ;
F_32 ( V_6 -> V_23 ) ;
F_32 ( V_6 ) ;
}
static int T_3 F_55 ( void )
{
F_56 ( & V_93 ) ;
F_57 ( & V_101 ) ;
return F_58 ( & V_102 ) ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_102 ) ;
F_61 ( & V_101 ) ;
}
