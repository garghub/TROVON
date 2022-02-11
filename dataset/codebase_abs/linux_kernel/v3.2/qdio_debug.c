void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
char V_5 [ 20 ] ;
F_2 ( L_1 , V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 , 8 ) ;
F_2 ( L_2 , V_2 -> V_8 ) ;
F_3 ( & V_2 -> V_9 , sizeof( void * ) ) ;
F_3 ( & V_2 -> V_10 , sizeof( void * ) ) ;
F_3 ( & V_2 -> V_11 , sizeof( void * ) ) ;
F_2 ( L_3 , V_2 -> V_12 ,
V_2 -> V_13 ) ;
F_3 ( & V_2 -> V_14 , sizeof( void * ) ) ;
F_3 ( & V_2 -> V_15 , sizeof( void * ) ) ;
F_3 ( & V_2 -> V_16 , sizeof( long ) ) ;
F_3 ( & V_2 -> V_17 , sizeof( void * ) ) ;
F_3 ( & V_2 -> V_18 , sizeof( void * ) ) ;
F_2 ( L_4 , ( unsigned long ) V_4 ) ;
snprintf ( V_5 , 20 , L_5 , F_4 ( & V_2 -> V_19 -> V_20 ) ) ;
V_4 -> V_21 = F_5 ( V_5 , 2 , 1 , 16 ) ;
F_6 ( V_4 -> V_21 , & V_22 ) ;
F_7 ( V_4 -> V_21 , V_23 ) ;
F_8 ( V_24 , V_4 , L_6 ) ;
}
static int F_9 ( struct V_25 * V_26 , void * V_27 )
{
unsigned char V_28 ;
struct V_29 * V_30 = V_26 -> V_31 ;
int V_32 ;
if ( ! V_30 )
return 0 ;
F_10 ( V_26 , L_7 ,
V_30 -> V_33 , V_34 ) ;
F_10 ( V_26 , L_8 ,
F_11 ( & V_30 -> V_35 ) ,
V_30 -> V_36 , V_30 -> V_37 ) ;
if ( V_30 -> V_38 ) {
F_10 ( V_26 , L_9 ,
V_30 -> V_39 . V_40 . V_41 , V_30 -> V_39 . V_40 . V_42 ,
V_30 -> V_39 . V_40 . V_43 ) ;
F_10 ( V_26 , L_10 ,
* ( V_44 * ) V_30 -> V_4 -> V_45 ,
F_12 ( V_46 ,
& V_30 -> V_39 . V_40 . V_47 ) ) ;
}
F_10 ( V_26 , L_11 ) ;
F_10 ( V_26 , L_12 ) ;
for ( V_32 = 0 ; V_32 < V_48 ; V_32 ++ ) {
F_13 ( V_30 , V_32 , & V_28 ) ;
switch ( V_28 ) {
case V_49 :
case V_50 :
F_10 ( V_26 , L_13 ) ;
break;
case V_51 :
F_10 ( V_26 , L_14 ) ;
break;
case V_52 :
case V_53 :
F_10 ( V_26 , L_15 ) ;
break;
case V_54 :
F_10 ( V_26 , L_16 ) ;
break;
case V_55 :
case V_56 :
F_10 ( V_26 , L_17 ) ;
break;
case V_57 :
case V_58 :
F_10 ( V_26 , L_18 ) ;
break;
case V_59 :
case V_60 :
F_10 ( V_26 , L_19 ) ;
break;
default:
F_10 ( V_26 , L_20 ) ;
}
if ( V_32 == 63 )
F_10 ( V_26 , L_21 ) ;
}
F_10 ( V_26 , L_21 ) ;
F_10 ( V_26 , L_22 ) ;
F_10 ( V_26 , L_23 ) ;
if ( ! V_30 -> V_4 -> V_61 ) {
F_10 ( V_26 , L_24 ) ;
return 0 ;
}
F_10 ( V_26 , L_25
L_26 ) ;
for ( V_32 = 0 ; V_32 < F_14 ( V_30 -> V_62 . V_63 ) ; V_32 ++ )
F_10 ( V_26 , L_27 , V_30 -> V_62 . V_63 [ V_32 ] ) ;
F_10 ( V_26 , L_28 ,
V_30 -> V_62 . V_64 , V_30 -> V_62 . V_65 ,
V_30 -> V_62 . V_66 ) ;
return 0 ;
}
static int F_15 ( struct V_67 * V_67 , struct V_68 * V_69 )
{
return F_16 ( V_69 , F_9 ,
V_69 -> V_70 . V_71 -> V_72 -> V_73 ) ;
}
static int F_17 ( struct V_25 * V_26 , void * V_27 )
{
struct V_3 * V_4 = V_26 -> V_31 ;
unsigned int * V_74 ;
int V_32 ;
if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_61 ) {
F_10 ( V_26 , L_29 ) ;
return 0 ;
}
V_74 = ( unsigned int * ) & V_4 -> V_75 ;
for ( V_32 = 0 ; V_32 < F_14 ( V_76 ) ; V_32 ++ )
F_10 ( V_26 , L_30 ,
V_76 [ V_32 ] , * ( V_74 + V_32 ) ) ;
return 0 ;
}
static T_1 F_18 ( struct V_68 * V_68 , const char T_2 * V_77 ,
T_3 V_78 , T_4 * V_79 )
{
struct V_25 * V_80 = V_68 -> V_81 ;
struct V_3 * V_4 = V_80 -> V_31 ;
struct V_29 * V_30 ;
unsigned long V_82 ;
int V_83 , V_32 ;
if ( ! V_4 )
return 0 ;
V_83 = F_19 ( V_77 , V_78 , 10 , & V_82 ) ;
if ( V_83 )
return V_83 ;
switch ( V_82 ) {
case 0 :
V_4 -> V_61 = 0 ;
memset ( & V_4 -> V_75 , 0 , sizeof( V_4 -> V_75 ) ) ;
F_20 (irq_ptr, q, i)
memset ( & V_30 -> V_62 , 0 , sizeof( V_30 -> V_62 ) ) ;
F_21 (irq_ptr, q, i)
memset ( & V_30 -> V_62 , 0 , sizeof( V_30 -> V_62 ) ) ;
break;
case 1 :
V_4 -> V_61 = 1 ;
break;
}
return V_78 ;
}
static int F_22 ( struct V_67 * V_67 , struct V_68 * V_69 )
{
return F_16 ( V_69 , F_17 ,
V_69 -> V_70 . V_71 -> V_72 -> V_73 ) ;
}
static void F_23 ( struct V_29 * V_30 , struct V_84 * V_19 )
{
char V_85 [ V_86 ] ;
snprintf ( V_85 , V_86 , L_31 ,
V_30 -> V_38 ? L_32 : L_33 ,
V_30 -> V_87 ) ;
V_30 -> V_88 = F_24 ( V_85 , V_89 | V_90 | V_91 ,
V_30 -> V_4 -> V_92 , V_30 , & V_93 ) ;
if ( F_25 ( V_30 -> V_88 ) )
V_30 -> V_88 = NULL ;
}
void F_26 ( struct V_3 * V_4 , struct V_84 * V_19 )
{
struct V_29 * V_30 ;
int V_32 ;
V_4 -> V_92 = F_27 ( F_4 ( & V_19 -> V_20 ) ,
V_94 ) ;
if ( F_25 ( V_4 -> V_92 ) )
V_4 -> V_92 = NULL ;
V_4 -> V_95 = F_24 ( L_34 ,
V_89 | V_90 | V_91 ,
V_4 -> V_92 , V_4 ,
& V_96 ) ;
if ( F_25 ( V_4 -> V_95 ) )
V_4 -> V_95 = NULL ;
F_20 (irq_ptr, q, i)
F_23 ( V_30 , V_19 ) ;
F_21 (irq_ptr, q, i)
F_23 ( V_30 , V_19 ) ;
}
void F_28 ( struct V_3 * V_4 , struct V_84 * V_19 )
{
struct V_29 * V_30 ;
int V_32 ;
F_20 (irq_ptr, q, i)
F_29 ( V_30 -> V_88 ) ;
F_21 (irq_ptr, q, i)
F_29 ( V_30 -> V_88 ) ;
F_29 ( V_4 -> V_95 ) ;
F_29 ( V_4 -> V_92 ) ;
}
int T_5 F_30 ( void )
{
V_94 = F_27 ( L_35 , NULL ) ;
V_97 = F_5 ( L_36 , 16 , 1 , 16 ) ;
F_6 ( V_97 , & V_22 ) ;
F_7 ( V_97 , V_98 ) ;
F_2 ( L_37 ) ;
V_99 = F_5 ( L_38 , 4 , 1 , 16 ) ;
F_6 ( V_99 , & V_22 ) ;
F_7 ( V_99 , V_98 ) ;
F_31 ( L_37 ) ;
return 0 ;
}
void F_32 ( void )
{
F_29 ( V_94 ) ;
if ( V_97 )
F_33 ( V_97 ) ;
if ( V_99 )
F_33 ( V_99 ) ;
}
