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
static struct V_58 * F_36 ( struct V_22 * V_23 , T_1 V_45 )
{
struct V_58 * V_59 ;
int V_60 = V_61 , V_12 ;
V_62:
V_59 = F_37 ( sizeof( * V_59 ) + V_60 , V_63 ) ;
if ( ! V_59 )
return NULL ;
V_12 = F_31 ( V_23 , V_59 -> V_64 , V_45 , V_60 ) ;
if ( V_12 < 0 ) {
F_38 ( V_59 ) ;
return NULL ;
}
if ( V_12 > V_60 ) {
V_60 = V_12 ;
F_38 ( V_59 ) ;
goto V_62;
}
V_59 -> V_46 = V_12 ;
return V_59 ;
}
static void F_39 ( struct V_22 * V_23 , T_1 V_45 ,
struct V_58 T_2 * * V_65 )
{
struct V_58 * V_59 ;
V_59 = F_36 ( V_23 , V_45 ) ;
if ( ! V_59 )
return;
F_40 ( & V_23 -> V_66 ) ;
F_41 ( * V_65 , V_59 ,
F_42 ( & V_23 -> V_66 ) ) ;
F_43 ( & V_23 -> V_66 ) ;
if ( V_59 )
F_44 ( V_59 , V_67 ) ;
}
void F_45 ( struct V_22 * V_23 )
{
int V_54 ;
struct V_58 * V_59 ;
if ( ! F_46 ( V_23 ) )
return;
V_59 = F_36 ( V_23 , 0 ) ;
if ( ! V_59 )
return;
for ( V_54 = 4 ; V_54 < V_59 -> V_46 ; V_54 ++ ) {
if ( V_59 -> V_64 [ V_54 ] == 0x80 )
F_39 ( V_23 , 0x80 , & V_23 -> V_68 ) ;
if ( V_59 -> V_64 [ V_54 ] == 0x83 )
F_39 ( V_23 , 0x83 , & V_23 -> V_69 ) ;
}
F_38 ( V_59 ) ;
}
int F_47 ( struct V_22 * V_23 , unsigned char * V_44 ,
unsigned int V_46 , unsigned char V_70 )
{
unsigned char V_2 [ 16 ] ;
struct V_71 V_72 ;
int V_12 ;
if ( V_23 -> V_73 || V_23 -> V_74 < V_75 )
return - V_47 ;
memset ( V_2 , 0 , 16 ) ;
V_2 [ 0 ] = V_76 ;
V_2 [ 1 ] = V_77 ;
V_2 [ 2 ] = 1 ;
V_2 [ 3 ] = V_70 ;
F_48 ( V_46 , & V_2 [ 6 ] ) ;
memset ( V_44 , 0 , V_46 ) ;
V_12 = F_32 ( V_23 , V_2 , V_49 , V_44 , V_46 ,
& V_72 , 30 * V_50 , 3 , NULL ) ;
if ( V_12 && F_49 ( & V_72 ) &&
V_72 . V_78 == V_79 &&
( V_72 . V_80 == 0x20 || V_72 . V_80 == 0x24 ) && V_72 . V_81 == 0x00 )
return - V_47 ;
if ( ( V_44 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_50 ( struct V_22 * V_23 )
{
if ( V_23 -> V_82 == V_83 || V_23 -> V_82 == V_84 )
goto V_56;
if ( ! F_51 ( & V_23 -> V_85 ) )
goto V_56;
if ( ! F_52 ( V_23 -> V_16 -> V_86 -> V_87 ) )
goto V_88;
return 0 ;
V_88:
F_53 ( & V_23 -> V_85 ) ;
V_56:
return - V_89 ;
}
void F_54 ( struct V_22 * V_23 )
{
F_55 ( V_23 -> V_16 -> V_86 -> V_87 ) ;
F_53 ( & V_23 -> V_85 ) ;
}
struct V_22 * F_56 ( struct V_19 * V_26 ,
struct V_22 * V_90 )
{
struct V_91 * V_92 = ( V_90 ? & V_90 -> V_93 : & V_26 -> V_94 ) ;
struct V_22 * V_95 = NULL ;
unsigned long V_96 ;
F_57 ( V_26 -> V_97 , V_96 ) ;
while ( V_92 -> V_95 != & V_26 -> V_94 ) {
V_95 = F_58 ( V_92 -> V_95 , struct V_22 , V_93 ) ;
if ( ! F_50 ( V_95 ) )
break;
V_95 = NULL ;
V_92 = V_92 -> V_95 ;
}
F_59 ( V_26 -> V_97 , V_96 ) ;
if ( V_90 )
F_54 ( V_90 ) ;
return V_95 ;
}
void F_60 ( struct V_24 * V_25 , void * V_64 ,
void (* F_61)( struct V_22 * , void * ) )
{
struct V_19 * V_26 = F_62 ( V_25 -> V_98 . V_99 ) ;
struct V_22 * V_23 ;
F_63 (sdev, shost) {
if ( ( V_23 -> V_100 == V_25 -> V_100 ) &&
( V_23 -> V_101 == V_25 -> V_101 ) )
F_61 ( V_23 , V_64 ) ;
}
}
void F_64 ( struct V_24 * V_25 , void * V_64 ,
void (* F_61)( struct V_22 * , void * ) )
{
struct V_19 * V_26 = F_62 ( V_25 -> V_98 . V_99 ) ;
struct V_22 * V_23 ;
F_65 (sdev, shost) {
if ( ( V_23 -> V_100 == V_25 -> V_100 ) &&
( V_23 -> V_101 == V_25 -> V_101 ) )
F_61 ( V_23 , V_64 ) ;
}
}
struct V_22 * F_66 ( struct V_24 * V_25 ,
T_3 V_102 )
{
struct V_22 * V_23 ;
F_67 (sdev, &starget->devices, same_target_siblings) {
if ( V_23 -> V_82 == V_83 )
continue;
if ( V_23 -> V_102 == V_102 )
return V_23 ;
}
return NULL ;
}
struct V_22 * F_68 ( struct V_24 * V_25 ,
T_3 V_102 )
{
struct V_22 * V_23 ;
struct V_19 * V_26 = F_62 ( V_25 -> V_98 . V_99 ) ;
unsigned long V_96 ;
F_57 ( V_26 -> V_97 , V_96 ) ;
V_23 = F_66 ( V_25 , V_102 ) ;
if ( V_23 && F_50 ( V_23 ) )
V_23 = NULL ;
F_59 ( V_26 -> V_97 , V_96 ) ;
return V_23 ;
}
struct V_22 * F_69 ( struct V_19 * V_26 ,
T_4 V_100 , T_4 V_101 , T_3 V_102 )
{
struct V_22 * V_23 ;
F_67 (sdev, &shost->__devices, siblings) {
if ( V_23 -> V_82 == V_83 )
continue;
if ( V_23 -> V_100 == V_100 && V_23 -> V_101 == V_101 &&
V_23 -> V_102 == V_102 )
return V_23 ;
}
return NULL ;
}
struct V_22 * F_70 ( struct V_19 * V_26 ,
T_4 V_100 , T_4 V_101 , T_3 V_102 )
{
struct V_22 * V_23 ;
unsigned long V_96 ;
F_57 ( V_26 -> V_97 , V_96 ) ;
V_23 = F_69 ( V_26 , V_100 , V_101 , V_102 ) ;
if ( V_23 && F_50 ( V_23 ) )
V_23 = NULL ;
F_59 ( V_26 -> V_97 , V_96 ) ;
return V_23 ;
}
static int T_5 F_71 ( void )
{
int error ;
error = F_72 () ;
if ( error )
return error ;
error = F_73 () ;
if ( error )
goto V_103;
error = F_74 () ;
if ( error )
goto V_104;
error = F_75 () ;
if ( error )
goto V_105;
error = F_76 () ;
if ( error )
goto V_106;
error = F_77 () ;
if ( error )
goto V_107;
F_78 () ;
F_79 ( V_108 L_6 ) ;
return 0 ;
V_107:
F_80 () ;
V_106:
F_81 () ;
V_105:
F_82 () ;
V_104:
F_83 () ;
V_103:
F_84 () ;
F_79 ( V_109 L_7 ,
- error ) ;
return error ;
}
static void T_6 F_85 ( void )
{
F_86 () ;
F_87 () ;
F_80 () ;
F_81 () ;
F_82 () ;
F_83 () ;
F_84 () ;
F_88 ( & V_110 ) ;
}
