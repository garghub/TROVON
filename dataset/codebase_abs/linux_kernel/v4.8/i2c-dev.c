static struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 ) ;
F_3 (i2c_dev, &i2c_dev_list, list) {
if ( V_1 -> V_4 -> V_5 == V_2 )
goto V_6;
}
V_1 = NULL ;
V_6:
F_4 ( & V_3 ) ;
return V_1 ;
}
static struct V_1 * F_5 ( struct V_7 * V_4 )
{
struct V_1 * V_1 ;
if ( V_4 -> V_5 >= V_8 ) {
F_6 ( V_9 L_1 ,
V_4 -> V_5 ) ;
return F_7 ( - V_10 ) ;
}
V_1 = F_8 ( sizeof( * V_1 ) , V_11 ) ;
if ( ! V_1 )
return F_7 ( - V_12 ) ;
V_1 -> V_4 = V_4 ;
F_2 ( & V_3 ) ;
F_9 ( & V_1 -> V_13 , & V_14 ) ;
F_4 ( & V_3 ) ;
return V_1 ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_2 ( & V_3 ) ;
F_11 ( & V_1 -> V_13 ) ;
F_4 ( & V_3 ) ;
F_12 ( V_1 ) ;
}
static T_1 F_13 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_1 = F_1 ( F_14 ( V_16 -> V_20 ) ) ;
if ( ! V_1 )
return - V_10 ;
return sprintf ( V_19 , L_2 , V_1 -> V_4 -> V_21 ) ;
}
static T_1 F_15 ( struct V_22 * V_22 , char T_2 * V_19 , T_3 V_23 ,
T_4 * V_24 )
{
char * V_25 ;
int V_26 ;
struct V_27 * V_28 = V_22 -> V_29 ;
if ( V_23 > 8192 )
V_23 = 8192 ;
V_25 = F_16 ( V_23 , V_11 ) ;
if ( V_25 == NULL )
return - V_12 ;
F_17 ( L_3 ,
F_18 ( F_19 ( V_22 ) ) , V_23 ) ;
V_26 = F_20 ( V_28 , V_25 , V_23 ) ;
if ( V_26 >= 0 )
V_26 = F_21 ( V_19 , V_25 , V_23 ) ? - V_30 : V_26 ;
F_12 ( V_25 ) ;
return V_26 ;
}
static T_1 F_22 ( struct V_22 * V_22 , const char T_2 * V_19 ,
T_3 V_23 , T_4 * V_24 )
{
int V_26 ;
char * V_25 ;
struct V_27 * V_28 = V_22 -> V_29 ;
if ( V_23 > 8192 )
V_23 = 8192 ;
V_25 = F_23 ( V_19 , V_23 ) ;
if ( F_24 ( V_25 ) )
return F_25 ( V_25 ) ;
F_17 ( L_4 ,
F_18 ( F_19 ( V_22 ) ) , V_23 ) ;
V_26 = F_26 ( V_28 , V_25 , V_23 ) ;
F_12 ( V_25 ) ;
return V_26 ;
}
static int F_27 ( struct V_15 * V_16 , void * V_31 )
{
struct V_27 * V_28 = F_28 ( V_16 ) ;
if ( ! V_28 || V_28 -> V_32 != * ( unsigned int * ) V_31 )
return 0 ;
return V_16 -> V_33 ? - V_34 : 0 ;
}
static int F_29 ( struct V_7 * V_35 , int V_32 )
{
struct V_7 * V_36 = F_30 ( V_35 ) ;
int V_37 ;
V_37 = F_31 ( & V_35 -> V_16 , & V_32 , F_27 ) ;
if ( ! V_37 && V_36 )
V_37 = F_29 ( V_36 , V_32 ) ;
return V_37 ;
}
static int F_32 ( struct V_15 * V_16 , void * V_31 )
{
int V_37 ;
if ( V_16 -> type == & V_38 )
V_37 = F_31 ( V_16 , V_31 ,
F_32 ) ;
else
V_37 = F_27 ( V_16 , V_31 ) ;
return V_37 ;
}
static int F_33 ( struct V_7 * V_35 , unsigned int V_32 )
{
struct V_7 * V_36 = F_30 ( V_35 ) ;
int V_37 = 0 ;
if ( V_36 )
V_37 = F_29 ( V_36 , V_32 ) ;
if ( ! V_37 )
V_37 = F_31 ( & V_35 -> V_16 , & V_32 ,
F_32 ) ;
return V_37 ;
}
static T_5 int F_34 ( struct V_27 * V_28 ,
unsigned long V_39 )
{
struct V_40 V_41 ;
struct V_42 * V_43 ;
T_6 T_2 * * V_44 ;
int V_45 , V_46 ;
if ( F_35 ( & V_41 ,
(struct V_40 T_2 * ) V_39 ,
sizeof( V_41 ) ) )
return - V_30 ;
if ( V_41 . V_47 > V_48 )
return - V_49 ;
V_43 = F_23 ( V_41 . V_50 ,
V_41 . V_47 * sizeof( struct V_42 ) ) ;
if ( F_24 ( V_43 ) )
return F_25 ( V_43 ) ;
V_44 = F_16 ( V_41 . V_47 * sizeof( T_6 T_2 * ) , V_11 ) ;
if ( V_44 == NULL ) {
F_12 ( V_43 ) ;
return - V_12 ;
}
V_46 = 0 ;
for ( V_45 = 0 ; V_45 < V_41 . V_47 ; V_45 ++ ) {
if ( V_43 [ V_45 ] . V_51 > 8192 ) {
V_46 = - V_49 ;
break;
}
V_44 [ V_45 ] = ( T_6 T_2 * ) V_43 [ V_45 ] . V_19 ;
V_43 [ V_45 ] . V_19 = F_23 ( V_44 [ V_45 ] , V_43 [ V_45 ] . V_51 ) ;
if ( F_24 ( V_43 [ V_45 ] . V_19 ) ) {
V_46 = F_25 ( V_43 [ V_45 ] . V_19 ) ;
break;
}
if ( V_43 [ V_45 ] . V_52 & V_53 ) {
if ( ! ( V_43 [ V_45 ] . V_52 & V_54 ) ||
V_43 [ V_45 ] . V_19 [ 0 ] < 1 ||
V_43 [ V_45 ] . V_51 < V_43 [ V_45 ] . V_19 [ 0 ] +
V_55 ) {
V_46 = - V_49 ;
break;
}
V_43 [ V_45 ] . V_51 = V_43 [ V_45 ] . V_19 [ 0 ] ;
}
}
if ( V_46 < 0 ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_45 ; ++ V_56 )
F_12 ( V_43 [ V_56 ] . V_19 ) ;
F_12 ( V_44 ) ;
F_12 ( V_43 ) ;
return V_46 ;
}
V_46 = F_36 ( V_28 -> V_35 , V_43 , V_41 . V_47 ) ;
while ( V_45 -- > 0 ) {
if ( V_46 >= 0 && ( V_43 [ V_45 ] . V_52 & V_54 ) ) {
if ( F_21 ( V_44 [ V_45 ] , V_43 [ V_45 ] . V_19 ,
V_43 [ V_45 ] . V_51 ) )
V_46 = - V_30 ;
}
F_12 ( V_43 [ V_45 ] . V_19 ) ;
}
F_12 ( V_44 ) ;
F_12 ( V_43 ) ;
return V_46 ;
}
static T_5 int F_37 ( struct V_27 * V_28 ,
unsigned long V_39 )
{
struct V_57 V_58 ;
union V_59 V_60 ;
int V_61 , V_46 ;
if ( F_35 ( & V_58 ,
(struct V_57 T_2 * ) V_39 ,
sizeof( struct V_57 ) ) )
return - V_30 ;
if ( ( V_58 . V_62 != V_63 ) &&
( V_58 . V_62 != V_64 ) &&
( V_58 . V_62 != V_65 ) &&
( V_58 . V_62 != V_66 ) &&
( V_58 . V_62 != V_67 ) &&
( V_58 . V_62 != V_68 ) &&
( V_58 . V_62 != V_69 ) &&
( V_58 . V_62 != V_70 ) &&
( V_58 . V_62 != V_71 ) ) {
F_38 ( & V_28 -> V_35 -> V_16 ,
L_5 ,
V_58 . V_62 ) ;
return - V_49 ;
}
if ( ( V_58 . V_72 != V_73 ) &&
( V_58 . V_72 != V_74 ) ) {
F_38 ( & V_28 -> V_35 -> V_16 ,
L_6 ,
V_58 . V_72 ) ;
return - V_49 ;
}
if ( ( V_58 . V_62 == V_64 ) ||
( ( V_58 . V_62 == V_63 ) &&
( V_58 . V_72 == V_74 ) ) )
return F_39 ( V_28 -> V_35 , V_28 -> V_32 ,
V_28 -> V_52 , V_58 . V_72 ,
V_58 . V_75 , V_58 . V_62 , NULL ) ;
if ( V_58 . V_76 == NULL ) {
F_38 ( & V_28 -> V_35 -> V_16 ,
L_7 ) ;
return - V_49 ;
}
if ( ( V_58 . V_62 == V_65 ) ||
( V_58 . V_62 == V_63 ) )
V_61 = sizeof( V_58 . V_76 -> V_77 ) ;
else if ( ( V_58 . V_62 == V_66 ) ||
( V_58 . V_62 == V_67 ) )
V_61 = sizeof( V_58 . V_76 -> V_78 ) ;
else
V_61 = sizeof( V_58 . V_76 -> V_79 ) ;
if ( ( V_58 . V_62 == V_67 ) ||
( V_58 . V_62 == V_71 ) ||
( V_58 . V_62 == V_70 ) ||
( V_58 . V_72 == V_74 ) ) {
if ( F_35 ( & V_60 , V_58 . V_76 , V_61 ) )
return - V_30 ;
}
if ( V_58 . V_62 == V_69 ) {
V_58 . V_62 = V_70 ;
if ( V_58 . V_72 == V_73 )
V_60 . V_79 [ 0 ] = V_55 ;
}
V_46 = F_39 ( V_28 -> V_35 , V_28 -> V_32 , V_28 -> V_52 ,
V_58 . V_72 , V_58 . V_75 , V_58 . V_62 , & V_60 ) ;
if ( ! V_46 && ( ( V_58 . V_62 == V_67 ) ||
( V_58 . V_62 == V_71 ) ||
( V_58 . V_72 == V_73 ) ) ) {
if ( F_21 ( V_58 . V_76 , & V_60 , V_61 ) )
return - V_30 ;
}
return V_46 ;
}
static long F_40 ( struct V_22 * V_22 , unsigned int V_80 , unsigned long V_39 )
{
struct V_27 * V_28 = V_22 -> V_29 ;
unsigned long V_81 ;
F_38 ( & V_28 -> V_35 -> V_16 , L_8 ,
V_80 , V_39 ) ;
switch ( V_80 ) {
case V_82 :
case V_83 :
if ( ( V_39 > 0x3ff ) ||
( ( ( V_28 -> V_52 & V_84 ) == 0 ) && V_39 > 0x7f ) )
return - V_49 ;
if ( V_80 == V_82 && F_33 ( V_28 -> V_35 , V_39 ) )
return - V_34 ;
V_28 -> V_32 = V_39 ;
return 0 ;
case V_85 :
if ( V_39 )
V_28 -> V_52 |= V_84 ;
else
V_28 -> V_52 &= ~ V_84 ;
return 0 ;
case V_86 :
if ( V_39 )
V_28 -> V_52 |= V_87 ;
else
V_28 -> V_52 &= ~ V_87 ;
return 0 ;
case V_88 :
V_81 = F_41 ( V_28 -> V_35 ) ;
return F_42 ( V_81 , ( unsigned long T_2 * ) V_39 ) ;
case V_89 :
return F_34 ( V_28 , V_39 ) ;
case V_90 :
return F_37 ( V_28 , V_39 ) ;
case V_91 :
V_28 -> V_35 -> V_92 = V_39 ;
break;
case V_93 :
V_28 -> V_35 -> V_94 = F_43 ( V_39 * 10 ) ;
break;
default:
return - V_95 ;
}
return 0 ;
}
static int F_44 ( struct V_96 * V_96 , struct V_22 * V_22 )
{
unsigned int V_97 = F_18 ( V_96 ) ;
struct V_27 * V_28 ;
struct V_7 * V_4 ;
V_4 = F_45 ( V_97 ) ;
if ( ! V_4 )
return - V_10 ;
V_28 = F_8 ( sizeof( * V_28 ) , V_11 ) ;
if ( ! V_28 ) {
F_46 ( V_4 ) ;
return - V_12 ;
}
snprintf ( V_28 -> V_21 , V_98 , L_9 , V_4 -> V_5 ) ;
V_28 -> V_35 = V_4 ;
V_22 -> V_29 = V_28 ;
return 0 ;
}
static int F_47 ( struct V_96 * V_96 , struct V_22 * V_22 )
{
struct V_27 * V_28 = V_22 -> V_29 ;
F_46 ( V_28 -> V_35 ) ;
F_12 ( V_28 ) ;
V_22 -> V_29 = NULL ;
return 0 ;
}
static int F_48 ( struct V_15 * V_16 , void * V_99 )
{
struct V_7 * V_4 ;
struct V_1 * V_1 ;
int V_46 ;
if ( V_16 -> type != & V_38 )
return 0 ;
V_4 = F_49 ( V_16 ) ;
V_1 = F_5 ( V_4 ) ;
if ( F_24 ( V_1 ) )
return F_25 ( V_1 ) ;
F_50 ( & V_1 -> V_100 , & V_101 ) ;
V_1 -> V_100 . V_102 = V_103 ;
V_46 = F_51 ( & V_1 -> V_100 , F_52 ( V_104 , V_4 -> V_5 ) , 1 ) ;
if ( V_46 )
goto V_105;
V_1 -> V_16 = F_53 ( V_106 , & V_4 -> V_16 ,
F_52 ( V_104 , V_4 -> V_5 ) , NULL ,
L_10 , V_4 -> V_5 ) ;
if ( F_24 ( V_1 -> V_16 ) ) {
V_46 = F_25 ( V_1 -> V_16 ) ;
goto error;
}
F_17 ( L_11 ,
V_4 -> V_21 , V_4 -> V_5 ) ;
return 0 ;
error:
F_54 ( & V_1 -> V_100 ) ;
V_105:
F_10 ( V_1 ) ;
return V_46 ;
}
static int F_55 ( struct V_15 * V_16 , void * V_99 )
{
struct V_7 * V_4 ;
struct V_1 * V_1 ;
if ( V_16 -> type != & V_38 )
return 0 ;
V_4 = F_49 ( V_16 ) ;
V_1 = F_1 ( V_4 -> V_5 ) ;
if ( ! V_1 )
return 0 ;
F_54 ( & V_1 -> V_100 ) ;
F_10 ( V_1 ) ;
F_56 ( V_106 , F_52 ( V_104 , V_4 -> V_5 ) ) ;
F_17 ( L_12 , V_4 -> V_21 ) ;
return 0 ;
}
static int F_57 ( struct V_107 * V_108 , unsigned long V_109 ,
void * V_76 )
{
struct V_15 * V_16 = V_76 ;
switch ( V_109 ) {
case V_110 :
return F_48 ( V_16 , NULL ) ;
case V_111 :
return F_55 ( V_16 , NULL ) ;
}
return 0 ;
}
static int T_7 F_58 ( void )
{
int V_46 ;
F_6 ( V_112 L_13 ) ;
V_46 = F_59 ( F_52 ( V_104 , 0 ) , V_8 , L_14 ) ;
if ( V_46 )
goto V_113;
V_106 = F_60 ( V_103 , L_15 ) ;
if ( F_24 ( V_106 ) ) {
V_46 = F_25 ( V_106 ) ;
goto V_114;
}
V_106 -> V_115 = V_116 ;
V_46 = F_61 ( & V_117 , & V_118 ) ;
if ( V_46 )
goto V_119;
F_62 ( NULL , F_48 ) ;
return 0 ;
V_119:
F_63 ( V_106 ) ;
V_114:
F_64 ( F_52 ( V_104 , 0 ) , V_8 ) ;
V_113:
F_6 ( V_9 L_16 , __FILE__ ) ;
return V_46 ;
}
static void T_8 F_65 ( void )
{
F_66 ( & V_117 , & V_118 ) ;
F_62 ( NULL , F_55 ) ;
F_63 ( V_106 ) ;
F_64 ( F_52 ( V_104 , 0 ) , V_8 ) ;
}
