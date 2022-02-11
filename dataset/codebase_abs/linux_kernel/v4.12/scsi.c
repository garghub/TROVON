void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 -> V_5 , V_3 ) ;
F_3 ( F_4 ( & V_2 -> V_6 ) ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_4 -> V_5 , V_3 ) ;
F_3 ( F_7 ( & V_2 -> V_7 ) ) ;
}
void F_8 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( F_9 ( V_9 ) ) {
V_8 = F_10 ( V_10 ,
V_11 ) ;
if ( V_8 > 1 ) {
F_11 ( V_12 , V_2 ,
L_1 , V_2 ) ;
F_12 ( V_2 ) ;
}
}
}
void F_13 ( struct V_1 * V_2 , int V_13 )
{
unsigned int V_8 ;
if ( F_9 ( V_9 ) ) {
V_8 = F_10 ( V_14 ,
V_15 ) ;
if ( ( ( V_8 > 0 ) && ( V_2 -> V_16 || V_13 != V_17 ) ) ||
( V_8 > 1 ) ) {
F_14 ( V_2 , L_2 , V_13 ) ;
F_12 ( V_2 ) ;
if ( F_15 ( V_2 -> V_16 ) & V_18 )
F_16 ( V_2 ) ;
if ( V_8 > 3 )
F_11 ( V_12 , V_2 ,
L_3 ,
F_17 ( & V_2 -> V_4 -> V_19 -> V_20 ) ,
V_2 -> V_4 -> V_19 -> V_21 ) ;
}
}
}
void F_18 ( struct V_22 * V_19 , struct V_1 * V_2 )
{
V_2 -> V_23 = V_19 -> V_24 ++ ;
if ( V_2 -> V_23 == 0 )
V_2 -> V_23 = V_19 -> V_24 ++ ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_4 ;
struct V_27 * V_28 = V_27 ( V_26 ) ;
struct V_22 * V_29 = V_26 -> V_19 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
F_20 ( V_26 ) ;
if ( F_17 ( & V_29 -> V_33 ) )
F_21 ( & V_29 -> V_33 , 0 ) ;
if ( F_17 ( & V_28 -> V_34 ) )
F_21 ( & V_28 -> V_34 , 0 ) ;
if ( F_17 ( & V_26 -> V_35 ) )
F_21 ( & V_26 -> V_35 , 0 ) ;
if ( F_22 ( V_2 ) )
V_2 -> V_16 |= ( V_36 << 24 ) ;
F_23 ( 4 , F_24 ( V_12 , V_26 ,
L_4
L_5 , V_2 -> V_16 ) ) ;
V_32 = F_25 ( V_2 ) ;
if ( ! F_26 ( V_2 -> V_37 ) ) {
int V_38 = V_32 ;
V_31 = F_27 ( V_2 ) ;
if ( V_31 -> V_39 )
V_32 = V_31 -> V_39 ( V_2 ) ;
if ( V_32 == V_38 )
V_32 -= F_28 ( V_2 ) ;
}
F_29 ( V_2 , V_32 ) ;
}
int F_30 ( struct V_25 * V_26 , int V_40 )
{
if ( V_40 > 0 ) {
V_26 -> V_41 = V_40 ;
F_31 () ;
}
if ( V_26 -> V_42 )
F_32 ( V_26 -> V_42 , V_40 ) ;
return V_26 -> V_41 ;
}
int F_33 ( struct V_25 * V_26 , int V_40 )
{
if ( ( V_43 >> 4 ) == ( V_26 -> V_44 >> 4 ) )
return 0 ;
V_26 -> V_44 = V_43 ;
if ( V_26 -> V_45 != V_40 ) {
V_26 -> V_46 = 1 ;
V_26 -> V_45 = V_40 ;
} else {
V_26 -> V_46 ++ ;
}
if ( V_26 -> V_46 <= 10 )
return 0 ;
return F_30 ( V_26 , V_40 ) ;
}
static int F_34 ( struct V_25 * V_26 , unsigned char * V_47 ,
T_1 V_48 , unsigned V_49 )
{
int V_16 ;
unsigned char V_2 [ 16 ] ;
if ( V_49 < 4 )
return - V_50 ;
V_2 [ 0 ] = V_51 ;
V_2 [ 1 ] = 1 ;
V_2 [ 2 ] = V_48 ;
V_2 [ 3 ] = V_49 >> 8 ;
V_2 [ 4 ] = V_49 & 0xff ;
V_2 [ 5 ] = 0 ;
V_16 = F_35 ( V_26 , V_2 , V_52 , V_47 ,
V_49 , NULL , 30 * V_53 , 3 , NULL ) ;
if ( V_16 )
return - V_54 ;
if ( V_47 [ 1 ] != V_48 )
return - V_54 ;
return F_36 ( & V_47 [ 2 ] ) + 4 ;
}
int F_37 ( struct V_25 * V_26 , T_1 V_48 , unsigned char * V_55 ,
int V_56 )
{
int V_57 , V_16 ;
if ( V_26 -> V_58 )
goto V_59;
V_16 = F_34 ( V_26 , V_55 , 0 , V_56 ) ;
if ( V_16 < 4 )
goto V_59;
if ( V_48 == 0 )
return 0 ;
for ( V_57 = 4 ; V_57 < F_38 ( V_16 , V_56 ) ; V_57 ++ )
if ( V_55 [ V_57 ] == V_48 )
goto V_60;
if ( V_57 < V_16 && V_57 >= V_56 )
goto V_60;
goto V_59;
V_60:
V_16 = F_34 ( V_26 , V_55 , V_48 , V_56 ) ;
if ( V_16 < 0 )
goto V_59;
return 0 ;
V_59:
return - V_50 ;
}
void F_39 ( struct V_25 * V_26 )
{
int V_16 , V_57 ;
int V_61 = V_62 ;
int V_63 = 0 ;
int V_64 = 0 ;
unsigned char T_2 * V_65 , * V_66 = NULL ;
if ( ! F_40 ( V_26 ) )
return;
V_67:
V_65 = F_41 ( V_61 , V_68 ) ;
if ( ! V_65 )
return;
V_16 = F_34 ( V_26 , V_65 , 0 , V_61 ) ;
if ( V_16 < 0 ) {
F_42 ( V_65 ) ;
return;
}
if ( V_16 > V_61 ) {
V_61 = V_16 ;
F_42 ( V_65 ) ;
goto V_67;
}
for ( V_57 = 4 ; V_57 < V_16 ; V_57 ++ ) {
if ( V_65 [ V_57 ] == 0x80 )
V_63 = 1 ;
if ( V_65 [ V_57 ] == 0x83 )
V_64 = 1 ;
}
F_42 ( V_65 ) ;
V_61 = V_62 ;
if ( V_63 ) {
V_69:
V_65 = F_41 ( V_61 , V_68 ) ;
if ( ! V_65 )
return;
V_16 = F_34 ( V_26 , V_65 , 0x80 , V_61 ) ;
if ( V_16 < 0 ) {
F_42 ( V_65 ) ;
return;
}
if ( V_16 > V_61 ) {
V_61 = V_16 ;
F_42 ( V_65 ) ;
goto V_69;
}
F_43 ( & V_26 -> V_70 ) ;
V_66 = V_26 -> V_71 ;
V_26 -> V_72 = V_16 ;
F_44 ( V_26 -> V_71 , V_65 ) ;
F_45 ( & V_26 -> V_70 ) ;
F_46 () ;
if ( V_66 ) {
F_42 ( V_66 ) ;
V_66 = NULL ;
}
V_61 = V_62 ;
}
if ( V_64 ) {
V_73:
V_65 = F_41 ( V_61 , V_68 ) ;
if ( ! V_65 )
return;
V_16 = F_34 ( V_26 , V_65 , 0x83 , V_61 ) ;
if ( V_16 < 0 ) {
F_42 ( V_65 ) ;
return;
}
if ( V_16 > V_61 ) {
V_61 = V_16 ;
F_42 ( V_65 ) ;
goto V_73;
}
F_43 ( & V_26 -> V_70 ) ;
V_66 = V_26 -> V_74 ;
V_26 -> V_75 = V_16 ;
F_44 ( V_26 -> V_74 , V_65 ) ;
F_45 ( & V_26 -> V_70 ) ;
F_46 () ;
if ( V_66 )
F_42 ( V_66 ) ;
}
}
int F_47 ( struct V_25 * V_26 , unsigned char * V_47 ,
unsigned int V_49 , unsigned char V_76 )
{
unsigned char V_2 [ 16 ] ;
struct V_77 V_78 ;
int V_16 ;
if ( V_26 -> V_79 || V_26 -> V_80 < V_81 )
return - V_50 ;
memset ( V_2 , 0 , 16 ) ;
V_2 [ 0 ] = V_82 ;
V_2 [ 1 ] = V_83 ;
V_2 [ 2 ] = 1 ;
V_2 [ 3 ] = V_76 ;
F_48 ( V_49 , & V_2 [ 6 ] ) ;
memset ( V_47 , 0 , V_49 ) ;
V_16 = F_35 ( V_26 , V_2 , V_52 , V_47 , V_49 ,
& V_78 , 30 * V_53 , 3 , NULL ) ;
if ( V_16 && F_49 ( & V_78 ) &&
V_78 . V_84 == V_85 &&
( V_78 . V_86 == 0x20 || V_78 . V_86 == 0x24 ) && V_78 . V_87 == 0x00 )
return - V_50 ;
if ( ( V_47 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_50 ( struct V_25 * V_26 )
{
if ( V_26 -> V_88 == V_89 || V_26 -> V_88 == V_90 )
goto V_59;
if ( ! F_51 ( & V_26 -> V_91 ) )
goto V_59;
if ( ! F_52 ( V_26 -> V_19 -> V_92 -> V_93 ) )
goto V_94;
return 0 ;
V_94:
F_53 ( & V_26 -> V_91 ) ;
V_59:
return - V_95 ;
}
void F_54 ( struct V_25 * V_26 )
{
F_55 ( V_26 -> V_19 -> V_92 -> V_93 ) ;
F_53 ( & V_26 -> V_91 ) ;
}
struct V_25 * F_56 ( struct V_22 * V_29 ,
struct V_25 * V_96 )
{
struct V_97 * V_6 = ( V_96 ? & V_96 -> V_98 : & V_29 -> V_99 ) ;
struct V_25 * V_100 = NULL ;
unsigned long V_3 ;
F_2 ( V_29 -> V_101 , V_3 ) ;
while ( V_6 -> V_100 != & V_29 -> V_99 ) {
V_100 = F_57 ( V_6 -> V_100 , struct V_25 , V_98 ) ;
if ( ! F_50 ( V_100 ) )
break;
V_100 = NULL ;
V_6 = V_6 -> V_100 ;
}
F_6 ( V_29 -> V_101 , V_3 ) ;
if ( V_96 )
F_54 ( V_96 ) ;
return V_100 ;
}
void F_58 ( struct V_27 * V_28 , void * V_102 ,
void (* F_59)( struct V_25 * , void * ) )
{
struct V_22 * V_29 = F_60 ( V_28 -> V_103 . V_104 ) ;
struct V_25 * V_26 ;
F_61 (sdev, shost) {
if ( ( V_26 -> V_105 == V_28 -> V_105 ) &&
( V_26 -> V_106 == V_28 -> V_106 ) )
F_59 ( V_26 , V_102 ) ;
}
}
void F_62 ( struct V_27 * V_28 , void * V_102 ,
void (* F_59)( struct V_25 * , void * ) )
{
struct V_22 * V_29 = F_60 ( V_28 -> V_103 . V_104 ) ;
struct V_25 * V_26 ;
F_63 (sdev, shost) {
if ( ( V_26 -> V_105 == V_28 -> V_105 ) &&
( V_26 -> V_106 == V_28 -> V_106 ) )
F_59 ( V_26 , V_102 ) ;
}
}
struct V_25 * F_64 ( struct V_27 * V_28 ,
T_3 V_107 )
{
struct V_25 * V_26 ;
F_65 (sdev, &starget->devices, same_target_siblings) {
if ( V_26 -> V_88 == V_89 )
continue;
if ( V_26 -> V_107 == V_107 )
return V_26 ;
}
return NULL ;
}
struct V_25 * F_66 ( struct V_27 * V_28 ,
T_3 V_107 )
{
struct V_25 * V_26 ;
struct V_22 * V_29 = F_60 ( V_28 -> V_103 . V_104 ) ;
unsigned long V_3 ;
F_2 ( V_29 -> V_101 , V_3 ) ;
V_26 = F_64 ( V_28 , V_107 ) ;
if ( V_26 && F_50 ( V_26 ) )
V_26 = NULL ;
F_6 ( V_29 -> V_101 , V_3 ) ;
return V_26 ;
}
struct V_25 * F_67 ( struct V_22 * V_29 ,
T_4 V_105 , T_4 V_106 , T_3 V_107 )
{
struct V_25 * V_26 ;
F_65 (sdev, &shost->__devices, siblings) {
if ( V_26 -> V_88 == V_89 )
continue;
if ( V_26 -> V_105 == V_105 && V_26 -> V_106 == V_106 &&
V_26 -> V_107 == V_107 )
return V_26 ;
}
return NULL ;
}
struct V_25 * F_68 ( struct V_22 * V_29 ,
T_4 V_105 , T_4 V_106 , T_3 V_107 )
{
struct V_25 * V_26 ;
unsigned long V_3 ;
F_2 ( V_29 -> V_101 , V_3 ) ;
V_26 = F_67 ( V_29 , V_105 , V_106 , V_107 ) ;
if ( V_26 && F_50 ( V_26 ) )
V_26 = NULL ;
F_6 ( V_29 -> V_101 , V_3 ) ;
return V_26 ;
}
static int T_5 F_69 ( void )
{
int error ;
error = F_70 () ;
if ( error )
return error ;
error = F_71 () ;
if ( error )
goto V_108;
error = F_72 () ;
if ( error )
goto V_109;
error = F_73 () ;
if ( error )
goto V_110;
error = F_74 () ;
if ( error )
goto V_111;
error = F_75 () ;
if ( error )
goto V_112;
F_76 () ;
F_77 ( V_113 L_6 ) ;
return 0 ;
V_112:
F_78 () ;
V_111:
F_79 () ;
V_110:
F_80 () ;
V_109:
F_81 () ;
V_108:
F_82 () ;
F_77 ( V_114 L_7 ,
- error ) ;
return error ;
}
static void T_6 F_83 ( void )
{
F_84 () ;
F_85 () ;
F_78 () ;
F_79 () ;
F_80 () ;
F_81 () ;
F_82 () ;
F_86 ( & V_115 ) ;
}
