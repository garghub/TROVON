struct V_1 * F_1 ( int V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] . V_9 ;
struct V_1 * V_10 = NULL ;
F_2 (report, feature_report_list, list) {
if ( V_10 -> V_2 == V_2 )
return V_10 ;
}
F_3 ( V_4 , L_1 , V_2 ) ;
return NULL ;
}
struct V_11 * F_4 ( struct V_3 * V_4 ,
int V_12 , const T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_11 * V_17 ;
struct V_1 * V_10 = F_6 ( V_12 , V_4 ) ;
unsigned long V_18 ;
int V_19 , V_20 , V_21 ;
if ( ! V_10 || ! V_16 )
return NULL ;
if ( V_16 -> V_22 & V_23 )
return NULL ;
V_17 = F_7 ( sizeof( * V_17 ) , V_24 ) ;
if ( ! V_17 )
return NULL ;
F_8 ( & V_17 -> V_25 ) ;
V_17 -> V_26 = V_10 ;
V_17 -> V_27 = NULL ;
V_17 -> V_28 = 0 ;
F_9 ( & V_16 -> V_29 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
for ( V_19 = V_21 = 0 ; V_19 < V_10 -> V_31 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < V_10 -> V_32 [ V_19 ] -> V_33 ; V_20 ++ ) {
F_11 ( V_10 -> V_32 [ V_19 ] , V_20 , V_21 < V_14 ? V_13 [ V_21 ] : 0 ) ;
V_21 ++ ;
}
if ( V_16 -> V_22 & V_23 ) {
F_12 ( V_17 ) ;
V_17 = NULL ;
} else {
V_16 -> V_34 = V_17 ;
F_13 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_14 ( & V_16 -> V_30 , V_18 ) ;
F_15 ( & V_17 -> V_25 , V_36 * 2 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
V_16 -> V_34 = NULL ;
}
F_14 ( & V_16 -> V_30 , V_18 ) ;
F_16 ( & V_16 -> V_29 ) ;
return V_17 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_1 * V_10 , T_1 * V_13 , int V_14 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
unsigned int V_37 ;
if ( V_13 [ V_19 ] == 0 )
continue;
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_38 ) ; V_20 ++ )
if ( V_16 -> V_38 [ V_20 ] == V_13 [ V_19 ] )
goto V_39;
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_38 ) ; V_20 ++ )
if ( V_16 -> V_38 [ V_20 ] == 0 ) {
V_16 -> V_38 [ V_20 ] = V_13 [ V_19 ] ;
break;
}
F_18 ( V_16 -> V_40 , V_41 , V_42 , V_13 [ V_19 ] ) ;
if ( V_13 [ V_19 ] < V_43 )
V_37 = V_16 -> V_44 [ V_13 [ V_19 ] ] ;
else
V_37 = V_45 ;
if ( V_37 != V_45 ) {
F_19 ( V_46 L_2 ,
V_13 [ V_19 ] , V_37 ) ;
F_20 ( V_16 -> V_40 , V_37 , 1 ) ;
}
F_21 ( V_16 -> V_40 ) ;
V_39:
continue;
}
for ( V_20 = 0 ; V_20 < sizeof( V_16 -> V_38 ) ; V_20 ++ ) {
unsigned int V_37 ;
if ( V_16 -> V_38 [ V_20 ] == 0 )
continue;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
if ( V_16 -> V_38 [ V_20 ] == V_13 [ V_19 ] )
goto V_47;
F_18 ( V_16 -> V_40 , V_41 , V_42 , V_16 -> V_38 [ V_20 ] ) ;
if ( V_16 -> V_38 [ V_20 ] < V_43 )
V_37 = V_16 -> V_44 [ V_16 -> V_38 [ V_20 ] ] ;
else
V_37 = V_45 ;
if ( V_37 != V_45 ) {
F_19 ( V_46 L_3 ,
V_16 -> V_38 [ V_20 ] , V_37 ) ;
F_20 ( V_16 -> V_40 , V_37 , 0 ) ;
}
F_21 ( V_16 -> V_40 ) ;
V_16 -> V_38 [ V_20 ] = 0 ;
V_47:
continue;
}
return 1 ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_11 * V_48 ;
int V_49 = 0 ;
if ( ! V_16 )
return - V_50 ;
V_48 = F_4 ( V_4 , V_51 , NULL , 0 ) ;
if ( ! V_48 ) {
F_23 ( V_4 , L_4 ) ;
return - V_50 ;
}
if ( V_48 -> V_28 == 2 ) {
V_16 -> V_52 [ 0 ] = V_48 -> V_13 [ 1 ] ;
V_16 -> V_52 [ 1 ] = V_48 -> V_13 [ 0 ] ;
if ( V_16 -> V_22 & V_53 ) {
F_24 ( V_4 , L_5 ,
V_48 -> V_13 [ 1 ] , V_48 -> V_13 [ 0 ] ) ;
} else {
F_24 ( V_4 , L_6 ,
V_48 -> V_13 [ 1 ] , V_48 -> V_13 [ 0 ] ) ;
}
} else {
F_23 ( V_4 , L_7 ) ;
V_49 = - V_54 ;
}
F_12 ( V_48 ) ;
return V_49 ;
}
int F_25 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
struct V_1 * V_10 = F_6 ( V_55 , V_4 ) ;
unsigned long V_18 ;
int error ;
if ( ! V_16 || ! V_10 || V_10 -> V_31 != 1 )
return - V_50 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_4 -> V_56 == V_57 )
V_16 -> V_22 |= V_53 ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , 1 ) ;
if ( V_16 -> V_22 & V_23 ) {
F_14 ( & V_16 -> V_30 , V_18 ) ;
return - V_50 ;
}
F_13 ( V_4 , V_10 , V_35 ) ;
F_14 ( & V_16 -> V_30 , V_18 ) ;
error = F_22 ( V_4 ) ;
if ( error )
return error ;
F_26 ( V_16 ) ;
F_27 ( V_16 ) ;
F_28 ( V_16 ) ;
F_29 ( V_16 ) ;
return 0 ;
}
static T_2 F_30 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_15 * V_16 = F_31 ( V_59 ) ;
if ( V_16 -> V_22 & V_53 )
return snprintf ( V_62 , V_63 , L_8 ) ;
else
return snprintf ( V_62 , V_63 , L_9 ) ;
}
static T_2 F_32 ( struct V_58 * V_59 ,
struct V_60 * V_61 , const char * V_62 , T_3 V_64 )
{
struct V_15 * V_16 = F_31 ( V_59 ) ;
struct V_1 * V_10 = NULL ;
T_3 V_65 = V_64 ;
int V_66 = V_16 -> V_67 ;
unsigned long V_18 ;
if ( V_65 >= 3 && strncmp ( L_10 , V_62 , 3 ) == 0 ) {
if ( V_16 -> V_22 & V_53 )
V_10 = F_6 ( V_68 , V_16 -> V_4 ) ;
V_62 += 3 ;
V_65 -= 3 ;
} else if ( V_65 >= 10 && strncmp ( L_11 , V_62 , 10 ) == 0 ) {
if ( ! ( V_16 -> V_22 & V_53 ) )
V_10 = F_6 ( V_69 , V_16 -> V_4 ) ;
V_62 += 10 ;
V_65 -= 10 ;
}
if ( ! V_10 || V_10 -> V_31 != 1 )
return - V_54 ;
while ( V_65 > 0 && ( V_62 [ V_65 - 1 ] == '\n' || V_62 [ V_65 - 1 ] == '\r' ) )
V_65 -- ;
if ( V_65 != 0 )
return - V_54 ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 0 , V_66 & 0xff ) ;
F_11 ( V_10 -> V_32 [ 0 ] , 1 , ( V_66 >> 8 ) & 0xff ) ;
F_13 ( V_16 -> V_4 , V_10 , V_35 ) ;
F_14 ( & V_16 -> V_30 , V_18 ) ;
return V_64 ;
}
static T_2 F_33 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_15 * V_16 = F_31 ( V_59 ) ;
return snprintf ( V_62 , V_63 , L_12 , V_16 -> V_67 ) ;
}
static T_2 F_34 ( struct V_58 * V_59 ,
struct V_60 * V_61 , const char * V_62 , T_3 V_64 )
{
struct V_15 * V_16 = F_31 ( V_59 ) ;
unsigned V_70 ;
if ( sscanf ( V_62 , L_13 , & V_70 ) != 1 )
return - V_54 ;
if ( V_70 > 30000 )
return - V_54 ;
else
V_16 -> V_67 = V_70 ;
return V_64 ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_1 * V_10 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
unsigned long V_18 ;
int V_49 = 0 ;
if ( ! V_16 )
return 1 ;
if ( V_10 -> V_2 == V_71 ) {
if ( V_16 -> V_40 )
V_49 = F_17 ( V_16 , V_10 , V_13 + 1 , V_14 - 1 ) ;
} else if ( V_10 -> V_2 == V_72 ) {
V_49 = F_36 ( V_16 , V_10 , V_13 + 1 , V_14 - 1 ) ;
} else {
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_16 -> V_34 ) {
memcpy ( V_16 -> V_34 -> V_13 , V_13 + 1 , V_14 - 1 ) ;
V_16 -> V_34 -> V_28 = V_14 - 1 ;
V_16 -> V_34 -> V_27 = V_10 ;
F_37 ( & V_16 -> V_34 -> V_25 ) ;
}
F_14 ( & V_16 -> V_30 , V_18 ) ;
}
F_38 ( V_16 , V_4 , V_10 , V_13 , V_14 ) ;
return 1 ;
}
static int F_39 ( struct V_3 * V_4 , T_4 V_73 )
{
if ( F_40 ( V_73 ) )
return 0 ;
F_41 ( F_5 ( V_4 ) ) ;
F_19 ( V_46 L_14 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
int V_49 ;
V_49 = F_27 ( F_5 ( V_4 ) ) ;
if ( V_49 )
F_19 ( V_46 L_15 , V_49 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 )
{
int V_49 ;
V_49 = F_25 ( V_4 ) ;
if ( V_49 )
F_19 ( V_46 L_16 , V_49 ) ;
V_49 = F_44 ( F_5 ( V_4 ) , 0 ) ;
if ( V_49 )
F_19 ( V_46 L_17 , V_49 ) ;
V_49 = F_26 ( F_5 ( V_4 ) ) ;
if ( V_49 )
F_19 ( V_46 L_18 , V_49 ) ;
V_49 = F_27 ( F_5 ( V_4 ) ) ;
if ( V_49 )
F_19 ( V_46 L_15 , V_49 ) ;
F_29 ( F_5 ( V_4 ) ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 ,
struct V_1 * V_10 )
{
struct V_3 * V_4 = V_16 -> V_4 ;
struct V_74 * V_75 ;
int error , V_19 ;
if ( ! V_10 )
return - V_50 ;
if ( V_10 -> V_31 != 1 || V_10 -> V_32 [ 0 ] -> V_33 != 2 ||
V_10 -> V_32 [ 0 ] -> V_76 != 8 ) {
F_23 ( V_4 , L_19 ) ;
return - V_54 ;
}
V_75 = F_46 () ;
if ( V_75 == NULL ) {
F_23 ( V_4 , L_20 ) ;
return - V_77 ;
}
F_47 ( V_75 , V_4 ) ;
memcpy ( V_16 -> V_44 , V_78 , sizeof( V_78 ) ) ;
V_75 -> V_79 = V_4 -> V_79 ;
V_75 -> V_80 = V_4 -> V_80 ;
V_75 -> V_81 = V_4 -> V_81 ;
V_75 -> V_2 . V_82 = V_4 -> V_83 ;
V_75 -> V_2 . V_84 = V_4 -> V_84 ;
V_75 -> V_2 . V_56 = V_4 -> V_56 ;
V_75 -> V_2 . V_52 = V_4 -> V_52 ;
V_75 -> V_59 . V_85 = & V_4 -> V_59 ;
V_75 -> V_44 = & V_16 -> V_44 ;
V_75 -> V_86 = V_43 ;
V_75 -> V_87 = sizeof( V_16 -> V_44 [ 0 ] ) ;
F_48 ( V_75 , V_41 , V_42 ) ;
F_49 ( V_88 , V_75 -> V_89 ) ;
for ( V_19 = 0 ; V_19 < V_43 ; V_19 ++ )
F_48 ( V_75 , V_90 , V_16 -> V_44 [ V_19 ] ) ;
error = F_50 ( V_75 ) ;
if ( error ) {
F_23 ( V_4 , L_21 ) ;
F_51 ( V_75 ) ;
return error ;
}
V_16 -> V_40 = V_75 ;
return 0 ;
}
static void F_52 ( struct V_15 * V_16 )
{
struct V_74 * V_75 = V_16 -> V_40 ;
V_16 -> V_40 = NULL ;
if ( V_75 )
F_53 ( V_75 ) ;
}
static int F_54 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
int error ;
error = F_45 ( V_16 , F_55 ( V_71 , V_4 ) ) ;
if ( error )
goto V_91;
error = F_56 ( V_16 , F_55 ( V_72 , V_4 ) ) ;
if ( error )
goto V_91;
error = F_57 ( V_16 ) ;
if ( error )
goto V_91;
error = F_58 ( V_16 , F_6 ( V_92 , V_4 ) ) ;
if ( error )
goto V_91;
error = F_59 ( V_16 , F_6 ( V_93 , V_4 ) ) ;
if ( error )
goto V_91;
error = F_60 ( V_16 , F_6 ( V_94 , V_4 ) ) ;
if ( error )
goto V_91;
F_61 ( V_16 , F_6 ( V_95 , V_4 ) ,
F_6 ( V_96 , V_4 ) ,
F_6 ( V_97 , V_4 ) ,
F_6 ( V_98 , V_4 ) ,
F_6 ( V_55 , V_4 ) ) ;
return 0 ;
V_91:
F_62 ( V_16 ) ;
F_63 ( V_16 ) ;
F_64 ( V_16 ) ;
F_65 ( V_16 ) ;
F_66 ( V_16 ) ;
F_52 ( V_16 ) ;
return error ;
}
static int F_67 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
F_61 ( V_16 , NULL , NULL ,
F_6 ( V_99 , V_4 ) ,
F_6 ( V_100 , V_4 ) , NULL ) ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 ,
const struct V_101 * V_2 )
{
struct V_15 * V_16 ;
int error = - V_77 ;
F_19 ( V_46 L_22 ) ;
V_16 = F_7 ( sizeof( struct V_15 ) , V_24 ) ;
if ( V_16 == NULL ) {
F_23 ( V_4 , L_23 ) ;
error = - V_77 ;
goto V_102;
}
F_69 ( & V_16 -> V_30 ) ;
F_70 ( & V_16 -> V_29 ) ;
V_16 -> V_4 = V_4 ;
V_16 -> V_67 = 5000 ;
if ( V_4 -> V_56 == V_57 )
V_16 -> V_22 |= V_53 ;
F_71 ( V_4 , V_16 ) ;
error = F_72 ( V_4 ) ;
if ( error ) {
F_23 ( V_4 , L_24 ) ;
goto V_103;
}
error = F_73 ( V_4 , 0 ) ;
if ( error ) {
F_23 ( V_4 , L_25 ) ;
goto V_103;
}
error = F_74 ( V_4 ) ;
if ( error ) {
F_23 ( V_4 , L_26 ) ;
goto V_104;
}
error = F_75 ( & V_4 -> V_59 , & V_105 ) ;
if ( error ) {
F_23 ( V_4 , L_27 ) ;
goto V_106;
}
error = F_75 ( & V_4 -> V_59 , & V_107 ) ;
if ( error ) {
F_23 ( V_4 , L_27 ) ;
goto V_108;
}
if ( V_16 -> V_22 & V_53 )
error = F_67 ( V_4 , V_16 ) ;
else
error = F_54 ( V_4 , V_16 ) ;
if ( error )
goto V_109;
F_19 ( V_46 L_28 ) ;
return 0 ;
V_109:
F_76 ( & V_4 -> V_59 , & V_107 ) ;
V_108:
F_76 ( & V_4 -> V_59 , & V_105 ) ;
V_106:
F_77 ( V_4 ) ;
V_104:
F_78 ( V_4 ) ;
V_103:
F_12 ( V_16 ) ;
V_102:
F_71 ( V_4 , NULL ) ;
return error ;
}
static void F_79 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_4 ) ;
unsigned long V_18 ;
F_19 ( V_46 L_29 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
V_16 -> V_22 |= V_23 ;
F_14 ( & V_16 -> V_30 , V_18 ) ;
F_80 ( V_16 ) ;
F_76 ( & V_4 -> V_59 , & V_107 ) ;
F_76 ( & V_4 -> V_59 , & V_105 ) ;
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
F_10 ( & V_16 -> V_30 , V_18 ) ;
if ( V_16 -> V_34 )
F_37 ( & V_16 -> V_34 -> V_25 ) ;
F_14 ( & V_16 -> V_30 , V_18 ) ;
F_62 ( V_16 ) ;
F_63 ( V_16 ) ;
F_64 ( V_16 ) ;
F_65 ( V_16 ) ;
F_66 ( V_16 ) ;
F_52 ( V_16 ) ;
F_71 ( V_4 , NULL ) ;
F_81 ( & V_16 -> V_29 ) ;
F_12 ( V_16 ) ;
}
