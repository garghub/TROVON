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
F_18 ( V_22 -> V_30 . V_31 -> V_32 ) , V_23 ) ;
V_26 = F_19 ( V_28 , V_25 , V_23 ) ;
if ( V_26 >= 0 )
V_26 = F_20 ( V_19 , V_25 , V_23 ) ? - V_33 : V_26 ;
F_12 ( V_25 ) ;
return V_26 ;
}
static T_1 F_21 ( struct V_22 * V_22 , const char T_2 * V_19 ,
T_3 V_23 , T_4 * V_24 )
{
int V_26 ;
char * V_25 ;
struct V_27 * V_28 = V_22 -> V_29 ;
if ( V_23 > 8192 )
V_23 = 8192 ;
V_25 = F_22 ( V_19 , V_23 ) ;
if ( F_23 ( V_25 ) )
return F_24 ( V_25 ) ;
F_17 ( L_4 ,
F_18 ( V_22 -> V_30 . V_31 -> V_32 ) , V_23 ) ;
V_26 = F_25 ( V_28 , V_25 , V_23 ) ;
F_12 ( V_25 ) ;
return V_26 ;
}
static int F_26 ( struct V_15 * V_16 , void * V_34 )
{
struct V_27 * V_28 = F_27 ( V_16 ) ;
if ( ! V_28 || V_28 -> V_35 != * ( unsigned int * ) V_34 )
return 0 ;
return V_16 -> V_36 ? - V_37 : 0 ;
}
static int F_28 ( struct V_7 * V_38 , int V_35 )
{
struct V_7 * V_39 = F_29 ( V_38 ) ;
int V_40 ;
V_40 = F_30 ( & V_38 -> V_16 , & V_35 , F_26 ) ;
if ( ! V_40 && V_39 )
V_40 = F_28 ( V_39 , V_35 ) ;
return V_40 ;
}
static int F_31 ( struct V_15 * V_16 , void * V_34 )
{
int V_40 ;
if ( V_16 -> type == & V_41 )
V_40 = F_30 ( V_16 , V_34 ,
F_31 ) ;
else
V_40 = F_26 ( V_16 , V_34 ) ;
return V_40 ;
}
static int F_32 ( struct V_7 * V_38 , unsigned int V_35 )
{
struct V_7 * V_39 = F_29 ( V_38 ) ;
int V_40 = 0 ;
if ( V_39 )
V_40 = F_28 ( V_39 , V_35 ) ;
if ( ! V_40 )
V_40 = F_30 ( & V_38 -> V_16 , & V_35 ,
F_31 ) ;
return V_40 ;
}
static T_5 int F_33 ( struct V_27 * V_28 ,
unsigned long V_42 )
{
struct V_43 V_44 ;
struct V_45 * V_46 ;
T_6 T_2 * * V_47 ;
int V_48 , V_49 ;
if ( F_34 ( & V_44 ,
(struct V_43 T_2 * ) V_42 ,
sizeof( V_44 ) ) )
return - V_33 ;
if ( V_44 . V_50 > V_51 )
return - V_52 ;
V_46 = F_22 ( V_44 . V_53 ,
V_44 . V_50 * sizeof( struct V_45 ) ) ;
if ( F_23 ( V_46 ) )
return F_24 ( V_46 ) ;
V_47 = F_16 ( V_44 . V_50 * sizeof( T_6 T_2 * ) , V_11 ) ;
if ( V_47 == NULL ) {
F_12 ( V_46 ) ;
return - V_12 ;
}
V_49 = 0 ;
for ( V_48 = 0 ; V_48 < V_44 . V_50 ; V_48 ++ ) {
if ( ( V_46 [ V_48 ] . V_54 > 8192 ) ||
( V_46 [ V_48 ] . V_55 & V_56 ) ) {
V_49 = - V_52 ;
break;
}
V_47 [ V_48 ] = ( T_6 T_2 * ) V_46 [ V_48 ] . V_19 ;
V_46 [ V_48 ] . V_19 = F_22 ( V_47 [ V_48 ] , V_46 [ V_48 ] . V_54 ) ;
if ( F_23 ( V_46 [ V_48 ] . V_19 ) ) {
V_49 = F_24 ( V_46 [ V_48 ] . V_19 ) ;
break;
}
}
if ( V_49 < 0 ) {
int V_57 ;
for ( V_57 = 0 ; V_57 < V_48 ; ++ V_57 )
F_12 ( V_46 [ V_57 ] . V_19 ) ;
F_12 ( V_47 ) ;
F_12 ( V_46 ) ;
return V_49 ;
}
V_49 = F_35 ( V_28 -> V_38 , V_46 , V_44 . V_50 ) ;
while ( V_48 -- > 0 ) {
if ( V_49 >= 0 && ( V_46 [ V_48 ] . V_55 & V_58 ) ) {
if ( F_20 ( V_47 [ V_48 ] , V_46 [ V_48 ] . V_19 ,
V_46 [ V_48 ] . V_54 ) )
V_49 = - V_33 ;
}
F_12 ( V_46 [ V_48 ] . V_19 ) ;
}
F_12 ( V_47 ) ;
F_12 ( V_46 ) ;
return V_49 ;
}
static T_5 int F_36 ( struct V_27 * V_28 ,
unsigned long V_42 )
{
struct V_59 V_60 ;
union V_61 V_62 ;
int V_63 , V_49 ;
if ( F_34 ( & V_60 ,
(struct V_59 T_2 * ) V_42 ,
sizeof( struct V_59 ) ) )
return - V_33 ;
if ( ( V_60 . V_64 != V_65 ) &&
( V_60 . V_64 != V_66 ) &&
( V_60 . V_64 != V_67 ) &&
( V_60 . V_64 != V_68 ) &&
( V_60 . V_64 != V_69 ) &&
( V_60 . V_64 != V_70 ) &&
( V_60 . V_64 != V_71 ) &&
( V_60 . V_64 != V_72 ) &&
( V_60 . V_64 != V_73 ) ) {
F_37 ( & V_28 -> V_38 -> V_16 ,
L_5 ,
V_60 . V_64 ) ;
return - V_52 ;
}
if ( ( V_60 . V_74 != V_75 ) &&
( V_60 . V_74 != V_76 ) ) {
F_37 ( & V_28 -> V_38 -> V_16 ,
L_6 ,
V_60 . V_74 ) ;
return - V_52 ;
}
if ( ( V_60 . V_64 == V_66 ) ||
( ( V_60 . V_64 == V_65 ) &&
( V_60 . V_74 == V_76 ) ) )
return F_38 ( V_28 -> V_38 , V_28 -> V_35 ,
V_28 -> V_55 , V_60 . V_74 ,
V_60 . V_77 , V_60 . V_64 , NULL ) ;
if ( V_60 . V_78 == NULL ) {
F_37 ( & V_28 -> V_38 -> V_16 ,
L_7 ) ;
return - V_52 ;
}
if ( ( V_60 . V_64 == V_67 ) ||
( V_60 . V_64 == V_65 ) )
V_63 = sizeof( V_60 . V_78 -> V_79 ) ;
else if ( ( V_60 . V_64 == V_68 ) ||
( V_60 . V_64 == V_69 ) )
V_63 = sizeof( V_60 . V_78 -> V_80 ) ;
else
V_63 = sizeof( V_60 . V_78 -> V_81 ) ;
if ( ( V_60 . V_64 == V_69 ) ||
( V_60 . V_64 == V_73 ) ||
( V_60 . V_64 == V_72 ) ||
( V_60 . V_74 == V_76 ) ) {
if ( F_34 ( & V_62 , V_60 . V_78 , V_63 ) )
return - V_33 ;
}
if ( V_60 . V_64 == V_71 ) {
V_60 . V_64 = V_72 ;
if ( V_60 . V_74 == V_75 )
V_62 . V_81 [ 0 ] = V_82 ;
}
V_49 = F_38 ( V_28 -> V_38 , V_28 -> V_35 , V_28 -> V_55 ,
V_60 . V_74 , V_60 . V_77 , V_60 . V_64 , & V_62 ) ;
if ( ! V_49 && ( ( V_60 . V_64 == V_69 ) ||
( V_60 . V_64 == V_73 ) ||
( V_60 . V_74 == V_75 ) ) ) {
if ( F_20 ( V_60 . V_78 , & V_62 , V_63 ) )
return - V_33 ;
}
return V_49 ;
}
static long F_39 ( struct V_22 * V_22 , unsigned int V_83 , unsigned long V_42 )
{
struct V_27 * V_28 = V_22 -> V_29 ;
unsigned long V_84 ;
F_37 ( & V_28 -> V_38 -> V_16 , L_8 ,
V_83 , V_42 ) ;
switch ( V_83 ) {
case V_85 :
case V_86 :
if ( ( V_42 > 0x3ff ) ||
( ( ( V_28 -> V_55 & V_87 ) == 0 ) && V_42 > 0x7f ) )
return - V_52 ;
if ( V_83 == V_85 && F_32 ( V_28 -> V_38 , V_42 ) )
return - V_37 ;
V_28 -> V_35 = V_42 ;
return 0 ;
case V_88 :
if ( V_42 )
V_28 -> V_55 |= V_87 ;
else
V_28 -> V_55 &= ~ V_87 ;
return 0 ;
case V_89 :
if ( V_42 )
V_28 -> V_55 |= V_90 ;
else
V_28 -> V_55 &= ~ V_90 ;
return 0 ;
case V_91 :
V_84 = F_40 ( V_28 -> V_38 ) ;
return F_41 ( V_84 , ( unsigned long T_2 * ) V_42 ) ;
case V_92 :
return F_33 ( V_28 , V_42 ) ;
case V_93 :
return F_36 ( V_28 , V_42 ) ;
case V_94 :
V_28 -> V_38 -> V_95 = V_42 ;
break;
case V_96 :
V_28 -> V_38 -> V_97 = F_42 ( V_42 * 10 ) ;
break;
default:
return - V_98 ;
}
return 0 ;
}
static int F_43 ( struct V_99 * V_99 , struct V_22 * V_22 )
{
unsigned int V_100 = F_18 ( V_99 ) ;
struct V_27 * V_28 ;
struct V_7 * V_4 ;
struct V_1 * V_1 ;
V_1 = F_1 ( V_100 ) ;
if ( ! V_1 )
return - V_10 ;
V_4 = F_44 ( V_1 -> V_4 -> V_5 ) ;
if ( ! V_4 )
return - V_10 ;
V_28 = F_8 ( sizeof( * V_28 ) , V_11 ) ;
if ( ! V_28 ) {
F_45 ( V_4 ) ;
return - V_12 ;
}
snprintf ( V_28 -> V_21 , V_101 , L_9 , V_4 -> V_5 ) ;
V_28 -> V_38 = V_4 ;
V_22 -> V_29 = V_28 ;
return 0 ;
}
static int F_46 ( struct V_99 * V_99 , struct V_22 * V_22 )
{
struct V_27 * V_28 = V_22 -> V_29 ;
F_45 ( V_28 -> V_38 ) ;
F_12 ( V_28 ) ;
V_22 -> V_29 = NULL ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 , void * V_102 )
{
struct V_7 * V_4 ;
struct V_1 * V_1 ;
int V_49 ;
if ( V_16 -> type != & V_41 )
return 0 ;
V_4 = F_48 ( V_16 ) ;
V_1 = F_5 ( V_4 ) ;
if ( F_23 ( V_1 ) )
return F_24 ( V_1 ) ;
V_1 -> V_16 = F_49 ( V_103 , & V_4 -> V_16 ,
F_50 ( V_104 , V_4 -> V_5 ) , NULL ,
L_10 , V_4 -> V_5 ) ;
if ( F_23 ( V_1 -> V_16 ) ) {
V_49 = F_24 ( V_1 -> V_16 ) ;
goto error;
}
V_49 = F_51 ( V_1 -> V_16 , & V_105 ) ;
if ( V_49 )
goto V_106;
F_17 ( L_11 ,
V_4 -> V_21 , V_4 -> V_5 ) ;
return 0 ;
V_106:
F_52 ( V_103 , F_50 ( V_104 , V_4 -> V_5 ) ) ;
error:
F_10 ( V_1 ) ;
return V_49 ;
}
static int F_53 ( struct V_15 * V_16 , void * V_102 )
{
struct V_7 * V_4 ;
struct V_1 * V_1 ;
if ( V_16 -> type != & V_41 )
return 0 ;
V_4 = F_48 ( V_16 ) ;
V_1 = F_1 ( V_4 -> V_5 ) ;
if ( ! V_1 )
return 0 ;
F_54 ( V_1 -> V_16 , & V_105 ) ;
F_10 ( V_1 ) ;
F_52 ( V_103 , F_50 ( V_104 , V_4 -> V_5 ) ) ;
F_17 ( L_12 , V_4 -> V_21 ) ;
return 0 ;
}
static int F_55 ( struct V_107 * V_108 , unsigned long V_109 ,
void * V_78 )
{
struct V_15 * V_16 = V_78 ;
switch ( V_109 ) {
case V_110 :
return F_47 ( V_16 , NULL ) ;
case V_111 :
return F_53 ( V_16 , NULL ) ;
}
return 0 ;
}
static int T_7 F_56 ( void )
{
int V_49 ;
F_6 ( V_112 L_13 ) ;
V_49 = F_57 ( V_104 , L_14 , & V_113 ) ;
if ( V_49 )
goto V_114;
V_103 = F_58 ( V_115 , L_15 ) ;
if ( F_23 ( V_103 ) ) {
V_49 = F_24 ( V_103 ) ;
goto V_116;
}
V_49 = F_59 ( & V_117 , & V_118 ) ;
if ( V_49 )
goto V_119;
F_60 ( NULL , F_47 ) ;
return 0 ;
V_119:
F_61 ( V_103 ) ;
V_116:
F_62 ( V_104 , L_14 ) ;
V_114:
F_6 ( V_9 L_16 , __FILE__ ) ;
return V_49 ;
}
static void T_8 F_63 ( void )
{
F_64 ( & V_117 , & V_118 ) ;
F_60 ( NULL , F_53 ) ;
F_61 ( V_103 ) ;
F_62 ( V_104 , L_14 ) ;
}
