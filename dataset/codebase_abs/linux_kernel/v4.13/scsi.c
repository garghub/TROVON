void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( F_4 ( & V_2 -> V_3 ) ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
if ( F_6 ( V_5 ) ) {
V_4 = F_7 ( V_6 ,
V_7 ) ;
if ( V_4 > 1 ) {
F_8 ( V_8 , V_2 ,
L_1 , V_2 ) ;
F_9 ( V_2 ) ;
}
}
}
void F_10 ( struct V_1 * V_2 , int V_9 )
{
unsigned int V_4 ;
if ( F_6 ( V_5 ) ) {
V_4 = F_7 ( V_10 ,
V_11 ) ;
if ( ( ( V_4 > 0 ) && ( V_2 -> V_12 || V_9 != V_13 ) ) ||
( V_4 > 1 ) ) {
F_11 ( V_2 , L_2 , V_9 ) ;
F_9 ( V_2 ) ;
if ( F_12 ( V_2 -> V_12 ) & V_14 )
F_13 ( V_2 ) ;
if ( V_4 > 3 )
F_8 ( V_8 , V_2 ,
L_3 ,
F_14 ( & V_2 -> V_15 -> V_16 -> V_17 ) ,
V_2 -> V_15 -> V_16 -> V_18 ) ;
}
}
}
void F_15 ( struct V_19 * V_16 , struct V_1 * V_2 )
{
V_2 -> V_20 = V_16 -> V_21 ++ ;
if ( V_2 -> V_20 == 0 )
V_2 -> V_20 = V_16 -> V_21 ++ ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_15 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_19 * V_26 = V_23 -> V_16 ;
struct V_27 * V_28 ;
unsigned int V_29 ;
F_17 ( V_23 ) ;
if ( F_14 ( & V_26 -> V_30 ) )
F_18 ( & V_26 -> V_30 , 0 ) ;
if ( F_14 ( & V_25 -> V_31 ) )
F_18 ( & V_25 -> V_31 , 0 ) ;
if ( F_14 ( & V_23 -> V_32 ) )
F_18 ( & V_23 -> V_32 , 0 ) ;
if ( F_19 ( V_2 ) )
V_2 -> V_12 |= ( V_33 << 24 ) ;
F_20 ( 4 , F_21 ( V_8 , V_23 ,
L_4
L_5 , V_2 -> V_12 ) ) ;
V_29 = F_22 ( V_2 ) ;
if ( ! F_23 ( V_2 -> V_34 ) ) {
int V_35 = V_29 ;
V_28 = F_24 ( V_2 ) ;
if ( V_28 -> V_36 )
V_29 = V_28 -> V_36 ( V_2 ) ;
if ( V_29 == V_35 )
V_29 -= F_25 ( V_2 ) ;
}
F_26 ( V_2 , V_29 ) ;
}
int F_27 ( struct V_22 * V_23 , int V_37 )
{
if ( V_37 > 0 ) {
V_23 -> V_38 = V_37 ;
F_28 () ;
}
if ( V_23 -> V_39 )
F_29 ( V_23 -> V_39 , V_37 ) ;
return V_23 -> V_38 ;
}
int F_30 ( struct V_22 * V_23 , int V_37 )
{
if ( ( V_40 >> 4 ) == ( V_23 -> V_41 >> 4 ) )
return 0 ;
V_23 -> V_41 = V_40 ;
if ( V_23 -> V_42 != V_37 ) {
V_23 -> V_43 = 1 ;
V_23 -> V_42 = V_37 ;
} else {
V_23 -> V_43 ++ ;
}
if ( V_23 -> V_43 <= 10 )
return 0 ;
return F_27 ( V_23 , V_37 ) ;
}
static int F_31 ( struct V_22 * V_23 , unsigned char * V_44 ,
T_1 V_45 , unsigned V_46 )
{
int V_12 ;
unsigned char V_2 [ 16 ] ;
if ( V_46 < 4 )
return - V_47 ;
V_2 [ 0 ] = V_48 ;
V_2 [ 1 ] = 1 ;
V_2 [ 2 ] = V_45 ;
V_2 [ 3 ] = V_46 >> 8 ;
V_2 [ 4 ] = V_46 & 0xff ;
V_2 [ 5 ] = 0 ;
V_12 = F_32 ( V_23 , V_2 , V_49 , V_44 ,
V_46 , NULL , 30 * V_50 , 3 , NULL ) ;
if ( V_12 )
return - V_51 ;
if ( V_44 [ 1 ] != V_45 )
return - V_51 ;
return F_33 ( & V_44 [ 2 ] ) + 4 ;
}
int F_34 ( struct V_22 * V_23 , T_1 V_45 , unsigned char * V_52 ,
int V_53 )
{
int V_54 , V_12 ;
if ( V_23 -> V_55 )
goto V_56;
V_12 = F_31 ( V_23 , V_52 , 0 , V_53 ) ;
if ( V_12 < 4 )
goto V_56;
if ( V_45 == 0 )
return 0 ;
for ( V_54 = 4 ; V_54 < F_35 ( V_12 , V_53 ) ; V_54 ++ )
if ( V_52 [ V_54 ] == V_45 )
goto V_57;
if ( V_54 < V_12 && V_54 >= V_53 )
goto V_57;
goto V_56;
V_57:
V_12 = F_31 ( V_23 , V_52 , V_45 , V_53 ) ;
if ( V_12 < 0 )
goto V_56;
return 0 ;
V_56:
return - V_47 ;
}
void F_36 ( struct V_22 * V_23 )
{
int V_12 , V_54 ;
int V_58 = V_59 ;
int V_60 = 0 ;
int V_61 = 0 ;
unsigned char T_2 * V_62 , * V_63 = NULL ;
if ( ! F_37 ( V_23 ) )
return;
V_64:
V_62 = F_38 ( V_58 , V_65 ) ;
if ( ! V_62 )
return;
V_12 = F_31 ( V_23 , V_62 , 0 , V_58 ) ;
if ( V_12 < 0 ) {
F_39 ( V_62 ) ;
return;
}
if ( V_12 > V_58 ) {
V_58 = V_12 ;
F_39 ( V_62 ) ;
goto V_64;
}
for ( V_54 = 4 ; V_54 < V_12 ; V_54 ++ ) {
if ( V_62 [ V_54 ] == 0x80 )
V_60 = 1 ;
if ( V_62 [ V_54 ] == 0x83 )
V_61 = 1 ;
}
F_39 ( V_62 ) ;
V_58 = V_59 ;
if ( V_60 ) {
V_66:
V_62 = F_38 ( V_58 , V_65 ) ;
if ( ! V_62 )
return;
V_12 = F_31 ( V_23 , V_62 , 0x80 , V_58 ) ;
if ( V_12 < 0 ) {
F_39 ( V_62 ) ;
return;
}
if ( V_12 > V_58 ) {
V_58 = V_12 ;
F_39 ( V_62 ) ;
goto V_66;
}
F_40 ( & V_23 -> V_67 ) ;
V_63 = V_23 -> V_68 ;
V_23 -> V_69 = V_12 ;
F_41 ( V_23 -> V_68 , V_62 ) ;
F_42 ( & V_23 -> V_67 ) ;
F_43 () ;
if ( V_63 ) {
F_39 ( V_63 ) ;
V_63 = NULL ;
}
V_58 = V_59 ;
}
if ( V_61 ) {
V_70:
V_62 = F_38 ( V_58 , V_65 ) ;
if ( ! V_62 )
return;
V_12 = F_31 ( V_23 , V_62 , 0x83 , V_58 ) ;
if ( V_12 < 0 ) {
F_39 ( V_62 ) ;
return;
}
if ( V_12 > V_58 ) {
V_58 = V_12 ;
F_39 ( V_62 ) ;
goto V_70;
}
F_40 ( & V_23 -> V_67 ) ;
V_63 = V_23 -> V_71 ;
V_23 -> V_72 = V_12 ;
F_41 ( V_23 -> V_71 , V_62 ) ;
F_42 ( & V_23 -> V_67 ) ;
F_43 () ;
if ( V_63 )
F_39 ( V_63 ) ;
}
}
int F_44 ( struct V_22 * V_23 , unsigned char * V_44 ,
unsigned int V_46 , unsigned char V_73 )
{
unsigned char V_2 [ 16 ] ;
struct V_74 V_75 ;
int V_12 ;
if ( V_23 -> V_76 || V_23 -> V_77 < V_78 )
return - V_47 ;
memset ( V_2 , 0 , 16 ) ;
V_2 [ 0 ] = V_79 ;
V_2 [ 1 ] = V_80 ;
V_2 [ 2 ] = 1 ;
V_2 [ 3 ] = V_73 ;
F_45 ( V_46 , & V_2 [ 6 ] ) ;
memset ( V_44 , 0 , V_46 ) ;
V_12 = F_32 ( V_23 , V_2 , V_49 , V_44 , V_46 ,
& V_75 , 30 * V_50 , 3 , NULL ) ;
if ( V_12 && F_46 ( & V_75 ) &&
V_75 . V_81 == V_82 &&
( V_75 . V_83 == 0x20 || V_75 . V_83 == 0x24 ) && V_75 . V_84 == 0x00 )
return - V_47 ;
if ( ( V_44 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_47 ( struct V_22 * V_23 )
{
if ( V_23 -> V_85 == V_86 || V_23 -> V_85 == V_87 )
goto V_56;
if ( ! F_48 ( & V_23 -> V_88 ) )
goto V_56;
if ( ! F_49 ( V_23 -> V_16 -> V_89 -> V_90 ) )
goto V_91;
return 0 ;
V_91:
F_50 ( & V_23 -> V_88 ) ;
V_56:
return - V_92 ;
}
void F_51 ( struct V_22 * V_23 )
{
F_52 ( V_23 -> V_16 -> V_89 -> V_90 ) ;
F_50 ( & V_23 -> V_88 ) ;
}
struct V_22 * F_53 ( struct V_19 * V_26 ,
struct V_22 * V_93 )
{
struct V_94 * V_95 = ( V_93 ? & V_93 -> V_96 : & V_26 -> V_97 ) ;
struct V_22 * V_98 = NULL ;
unsigned long V_99 ;
F_54 ( V_26 -> V_100 , V_99 ) ;
while ( V_95 -> V_98 != & V_26 -> V_97 ) {
V_98 = F_55 ( V_95 -> V_98 , struct V_22 , V_96 ) ;
if ( ! F_47 ( V_98 ) )
break;
V_98 = NULL ;
V_95 = V_95 -> V_98 ;
}
F_56 ( V_26 -> V_100 , V_99 ) ;
if ( V_93 )
F_51 ( V_93 ) ;
return V_98 ;
}
void F_57 ( struct V_24 * V_25 , void * V_101 ,
void (* F_58)( struct V_22 * , void * ) )
{
struct V_19 * V_26 = F_59 ( V_25 -> V_102 . V_103 ) ;
struct V_22 * V_23 ;
F_60 (sdev, shost) {
if ( ( V_23 -> V_104 == V_25 -> V_104 ) &&
( V_23 -> V_105 == V_25 -> V_105 ) )
F_58 ( V_23 , V_101 ) ;
}
}
void F_61 ( struct V_24 * V_25 , void * V_101 ,
void (* F_58)( struct V_22 * , void * ) )
{
struct V_19 * V_26 = F_59 ( V_25 -> V_102 . V_103 ) ;
struct V_22 * V_23 ;
F_62 (sdev, shost) {
if ( ( V_23 -> V_104 == V_25 -> V_104 ) &&
( V_23 -> V_105 == V_25 -> V_105 ) )
F_58 ( V_23 , V_101 ) ;
}
}
struct V_22 * F_63 ( struct V_24 * V_25 ,
T_3 V_106 )
{
struct V_22 * V_23 ;
F_64 (sdev, &starget->devices, same_target_siblings) {
if ( V_23 -> V_85 == V_86 )
continue;
if ( V_23 -> V_106 == V_106 )
return V_23 ;
}
return NULL ;
}
struct V_22 * F_65 ( struct V_24 * V_25 ,
T_3 V_106 )
{
struct V_22 * V_23 ;
struct V_19 * V_26 = F_59 ( V_25 -> V_102 . V_103 ) ;
unsigned long V_99 ;
F_54 ( V_26 -> V_100 , V_99 ) ;
V_23 = F_63 ( V_25 , V_106 ) ;
if ( V_23 && F_47 ( V_23 ) )
V_23 = NULL ;
F_56 ( V_26 -> V_100 , V_99 ) ;
return V_23 ;
}
struct V_22 * F_66 ( struct V_19 * V_26 ,
T_4 V_104 , T_4 V_105 , T_3 V_106 )
{
struct V_22 * V_23 ;
F_64 (sdev, &shost->__devices, siblings) {
if ( V_23 -> V_85 == V_86 )
continue;
if ( V_23 -> V_104 == V_104 && V_23 -> V_105 == V_105 &&
V_23 -> V_106 == V_106 )
return V_23 ;
}
return NULL ;
}
struct V_22 * F_67 ( struct V_19 * V_26 ,
T_4 V_104 , T_4 V_105 , T_3 V_106 )
{
struct V_22 * V_23 ;
unsigned long V_99 ;
F_54 ( V_26 -> V_100 , V_99 ) ;
V_23 = F_66 ( V_26 , V_104 , V_105 , V_106 ) ;
if ( V_23 && F_47 ( V_23 ) )
V_23 = NULL ;
F_56 ( V_26 -> V_100 , V_99 ) ;
return V_23 ;
}
static int T_5 F_68 ( void )
{
int error ;
error = F_69 () ;
if ( error )
return error ;
error = F_70 () ;
if ( error )
goto V_107;
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
F_75 () ;
F_76 ( V_112 L_6 ) ;
return 0 ;
V_111:
F_77 () ;
V_110:
F_78 () ;
V_109:
F_79 () ;
V_108:
F_80 () ;
V_107:
F_81 () ;
F_76 ( V_113 L_7 ,
- error ) ;
return error ;
}
static void T_6 F_82 ( void )
{
F_83 () ;
F_84 () ;
F_77 () ;
F_78 () ;
F_79 () ;
F_80 () ;
F_81 () ;
F_85 ( & V_114 ) ;
}
