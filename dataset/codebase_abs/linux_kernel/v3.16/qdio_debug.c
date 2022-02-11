static T_1 * F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
T_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (entry, &qdio_dbf_list, dbf_list) {
if ( strcmp ( V_3 -> V_6 , V_1 ) == 0 ) {
V_4 = V_3 -> V_7 ;
break;
}
}
F_4 ( & V_5 ) ;
return V_4 ;
}
static void F_5 ( void )
{
struct V_2 * V_3 , * V_8 ;
F_2 ( & V_5 ) ;
F_6 (entry, tmp, &qdio_dbf_list, dbf_list) {
F_7 ( & V_3 -> V_9 ) ;
F_8 ( V_3 -> V_7 ) ;
F_9 ( V_3 ) ;
}
F_4 ( & V_5 ) ;
}
int F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
char V_14 [ V_15 ] ;
struct V_2 * V_16 ;
F_11 ( L_1 , V_11 -> V_17 ) ;
F_12 ( V_11 -> V_18 , 8 ) ;
F_11 ( L_2 , V_11 -> V_19 ) ;
F_12 ( & V_11 -> V_20 , sizeof( void * ) ) ;
F_12 ( & V_11 -> V_21 , sizeof( void * ) ) ;
F_12 ( & V_11 -> V_22 , sizeof( void * ) ) ;
F_11 ( L_3 , V_11 -> V_23 ,
V_11 -> V_24 ) ;
F_12 ( & V_11 -> V_25 , sizeof( void * ) ) ;
F_12 ( & V_11 -> V_26 , sizeof( void * ) ) ;
F_12 ( & V_11 -> V_27 , sizeof( long ) ) ;
F_12 ( & V_11 -> V_28 , sizeof( void * ) ) ;
F_12 ( & V_11 -> V_29 , sizeof( void * ) ) ;
F_11 ( L_4 , ( unsigned long ) V_13 ) ;
snprintf ( V_14 , V_15 , L_5 ,
F_13 ( & V_11 -> V_30 -> V_31 ) ) ;
V_13 -> V_32 = F_1 ( V_14 ) ;
if ( V_13 -> V_32 )
F_14 ( V_33 , V_13 , L_6 ) ;
else {
V_13 -> V_32 = F_15 ( V_14 , 2 , 1 , 16 ) ;
if ( ! V_13 -> V_32 )
return - V_34 ;
if ( F_16 ( V_13 -> V_32 ,
& V_35 ) ) {
F_8 ( V_13 -> V_32 ) ;
return - V_34 ;
}
F_17 ( V_13 -> V_32 , V_36 ) ;
F_14 ( V_33 , V_13 , L_7 ) ;
V_16 = F_18 ( sizeof( struct V_2 ) , V_37 ) ;
if ( ! V_16 ) {
F_8 ( V_13 -> V_32 ) ;
return - V_34 ;
}
F_19 ( V_16 -> V_6 , V_14 , V_15 ) ;
V_16 -> V_7 = V_13 -> V_32 ;
F_2 ( & V_5 ) ;
F_20 ( & V_16 -> V_9 , & V_38 ) ;
F_4 ( & V_5 ) ;
}
return 0 ;
}
static int F_21 ( struct V_39 * V_40 , void * V_41 )
{
unsigned char V_42 ;
struct V_43 * V_44 = V_40 -> V_45 ;
int V_46 ;
if ( ! V_44 )
return 0 ;
F_22 ( V_40 , L_8 ,
V_44 -> V_47 , V_48 ) ;
F_22 ( V_40 , L_9 ,
F_23 ( & V_44 -> V_49 ) ,
V_44 -> V_50 , V_44 -> V_51 ) ;
if ( V_44 -> V_52 ) {
F_22 ( V_40 , L_10 ,
V_44 -> V_53 . V_54 . V_55 , V_44 -> V_53 . V_54 . V_56 ,
V_44 -> V_53 . V_54 . V_57 ) ;
F_22 ( V_40 , L_11 ,
* ( V_58 * ) V_44 -> V_13 -> V_59 ,
F_24 ( V_60 ,
& V_44 -> V_53 . V_54 . V_61 ) ) ;
}
F_22 ( V_40 , L_12 ) ;
F_22 ( V_40 , L_13 ) ;
for ( V_46 = 0 ; V_46 < V_62 ; V_46 ++ ) {
F_25 ( V_44 , V_46 , & V_42 ) ;
switch ( V_42 ) {
case V_63 :
case V_64 :
F_22 ( V_40 , L_14 ) ;
break;
case V_65 :
F_22 ( V_40 , L_15 ) ;
break;
case V_66 :
case V_67 :
F_22 ( V_40 , L_16 ) ;
break;
case V_68 :
F_22 ( V_40 , L_17 ) ;
break;
case V_69 :
case V_70 :
F_22 ( V_40 , L_18 ) ;
break;
case V_71 :
case V_72 :
F_22 ( V_40 , L_19 ) ;
break;
case V_73 :
case V_74 :
F_22 ( V_40 , L_20 ) ;
break;
default:
F_22 ( V_40 , L_21 ) ;
}
if ( V_46 == 63 )
F_22 ( V_40 , L_22 ) ;
}
F_22 ( V_40 , L_22 ) ;
F_22 ( V_40 , L_23 ) ;
F_22 ( V_40 , L_24 ) ;
if ( ! V_44 -> V_13 -> V_75 ) {
F_22 ( V_40 , L_25 ) ;
return 0 ;
}
F_22 ( V_40 , L_26
L_27 ) ;
for ( V_46 = 0 ; V_46 < F_26 ( V_44 -> V_76 . V_77 ) ; V_46 ++ )
F_22 ( V_40 , L_28 , V_44 -> V_76 . V_77 [ V_46 ] ) ;
F_22 ( V_40 , L_29 ,
V_44 -> V_76 . V_78 , V_44 -> V_76 . V_79 ,
V_44 -> V_76 . V_80 ) ;
return 0 ;
}
static int F_27 ( struct V_81 * V_81 , struct V_82 * V_83 )
{
return F_28 ( V_83 , F_21 ,
F_29 ( V_83 ) -> V_84 ) ;
}
static int F_30 ( struct V_39 * V_40 , void * V_41 )
{
struct V_12 * V_13 = V_40 -> V_45 ;
unsigned int * V_85 ;
int V_46 ;
if ( ! V_13 )
return 0 ;
if ( ! V_13 -> V_75 ) {
F_22 ( V_40 , L_30 ) ;
return 0 ;
}
V_85 = ( unsigned int * ) & V_13 -> V_86 ;
for ( V_46 = 0 ; V_46 < F_26 ( V_87 ) ; V_46 ++ )
F_22 ( V_40 , L_31 ,
V_87 [ V_46 ] , * ( V_85 + V_46 ) ) ;
return 0 ;
}
static T_2 F_31 ( struct V_82 * V_82 , const char T_3 * V_88 ,
T_4 V_89 , T_5 * V_90 )
{
struct V_39 * V_91 = V_82 -> V_92 ;
struct V_12 * V_13 = V_91 -> V_45 ;
struct V_43 * V_44 ;
unsigned long V_93 ;
int V_94 , V_46 ;
if ( ! V_13 )
return 0 ;
V_94 = F_32 ( V_88 , V_89 , 10 , & V_93 ) ;
if ( V_94 )
return V_94 ;
switch ( V_93 ) {
case 0 :
V_13 -> V_75 = 0 ;
memset ( & V_13 -> V_86 , 0 , sizeof( V_13 -> V_86 ) ) ;
F_33 (irq_ptr, q, i)
memset ( & V_44 -> V_76 , 0 , sizeof( V_44 -> V_76 ) ) ;
F_34 (irq_ptr, q, i)
memset ( & V_44 -> V_76 , 0 , sizeof( V_44 -> V_76 ) ) ;
break;
case 1 :
V_13 -> V_75 = 1 ;
break;
}
return V_89 ;
}
static int F_35 ( struct V_81 * V_81 , struct V_82 * V_83 )
{
return F_28 ( V_83 , F_30 ,
F_29 ( V_83 ) -> V_84 ) ;
}
static void F_36 ( struct V_43 * V_44 )
{
char V_1 [ V_95 ] ;
snprintf ( V_1 , V_95 , L_32 ,
V_44 -> V_52 ? L_33 : L_34 ,
V_44 -> V_96 ) ;
V_44 -> V_97 = F_37 ( V_1 , V_98 | V_99 | V_100 ,
V_44 -> V_13 -> V_101 , V_44 , & V_102 ) ;
if ( F_38 ( V_44 -> V_97 ) )
V_44 -> V_97 = NULL ;
}
void F_39 ( struct V_12 * V_13 , struct V_103 * V_30 )
{
struct V_43 * V_44 ;
int V_46 ;
V_13 -> V_101 = F_40 ( F_13 ( & V_30 -> V_31 ) ,
V_104 ) ;
if ( F_38 ( V_13 -> V_101 ) )
V_13 -> V_101 = NULL ;
V_13 -> V_105 = F_37 ( L_35 ,
V_98 | V_99 | V_100 ,
V_13 -> V_101 , V_13 ,
& V_106 ) ;
if ( F_38 ( V_13 -> V_105 ) )
V_13 -> V_105 = NULL ;
F_33 (irq_ptr, q, i)
F_36 ( V_44 ) ;
F_34 (irq_ptr, q, i)
F_36 ( V_44 ) ;
}
void F_41 ( struct V_12 * V_13 )
{
struct V_43 * V_44 ;
int V_46 ;
F_33 (irq_ptr, q, i)
F_42 ( V_44 -> V_97 ) ;
F_34 (irq_ptr, q, i)
F_42 ( V_44 -> V_97 ) ;
F_42 ( V_13 -> V_105 ) ;
F_42 ( V_13 -> V_101 ) ;
}
int T_6 F_43 ( void )
{
V_104 = F_40 ( L_36 , NULL ) ;
V_107 = F_15 ( L_37 , 16 , 1 , 16 ) ;
F_16 ( V_107 , & V_35 ) ;
F_17 ( V_107 , V_108 ) ;
F_11 ( L_38 ) ;
V_109 = F_15 ( L_39 , 4 , 1 , 16 ) ;
F_16 ( V_109 , & V_35 ) ;
F_17 ( V_109 , V_108 ) ;
F_44 ( L_38 ) ;
return 0 ;
}
void F_45 ( void )
{
F_5 () ;
F_42 ( V_104 ) ;
if ( V_107 )
F_8 ( V_107 ) ;
if ( V_109 )
F_8 ( V_109 ) ;
}
