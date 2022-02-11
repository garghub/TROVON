static inline void F_1 ( struct V_1 * V_1 ) { }
static inline void F_2 ( struct V_1 * V_1 ) { }
static inline void F_3 ( struct V_1 * V_1 , struct V_2 * V_2 ) {}
static inline void F_4 ( struct V_1 * V_1 , struct V_2 * V_2 ,
int V_3 ) {}
static inline void F_5 ( struct V_1 * V_1 , struct V_2 * V_2 ) {}
static inline void F_6 ( struct V_1 * V_1 ,
struct V_2 * V_2 ) {}
static inline void F_7 ( struct V_1 * V_1 ,
struct V_2 * V_2 ) {}
static inline void F_8 ( struct V_1 * V_1 ) {}
static inline void F_9 ( struct V_1 * V_1 ) {}
static inline void F_10 ( struct V_1 * V_1 , int V_4 ) {}
static inline void F_11 ( struct V_1 * V_1 , int V_4 ) {}
static inline void F_12 ( struct V_1 * V_1 ,
int V_5 , struct V_6 * V_6 ) {}
static inline void F_13 ( struct V_1 * V_1 ,
int V_5 , struct V_6 * V_6 , int V_7 , int V_8 ) {}
static inline struct V_9 * F_14 ( struct V_1 * V_1 ,
struct V_2 * V_2 )
{
return F_15 ( V_2 -> V_10 ) ?
& V_1 -> V_11 : & V_1 -> V_12 ;
}
static void F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_14 ( V_1 , V_2 ) -> V_13 ++ ;
}
static void F_4 ( struct V_1 * V_1 , struct V_2 * V_2 , int V_14 )
{
if ( V_14 )
F_14 ( V_1 , V_2 ) -> V_15 ++ ;
else
F_14 ( V_1 , V_2 ) -> V_16 ++ ;
}
static void F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_14 ( V_1 , V_2 ) -> V_17 ++ ;
}
static void F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_14 ( V_1 , V_2 ) -> V_18 ++ ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_14 ( V_1 , V_2 ) -> V_19 ++ ;
}
static inline void F_8 ( struct V_1 * V_1 )
{
V_1 -> V_20 . V_21 = F_16 (
++ ( V_1 -> V_20 . V_22 ) ,
V_1 -> V_20 . V_21 ) ;
}
static inline void F_9 ( struct V_1 * V_1 )
{
V_1 -> V_20 . V_22 -- ;
}
static inline void F_10 ( struct V_1 * V_1 , int V_4 )
{
V_1 -> V_23 . V_22 += V_4 ;
V_1 -> V_23 . V_21 = F_16 (
V_1 -> V_23 . V_22 ,
V_1 -> V_23 . V_21 ) ;
}
static inline void F_11 ( struct V_1 * V_1 , int V_4 )
{
V_1 -> V_23 . V_22 -= V_4 ;
}
static void F_12 ( struct V_1 * V_1 ,
int V_5 , struct V_6 * V_6 )
{
struct V_24 * V_25 = & V_1 -> V_26 [
V_1 -> V_27 ++ ] ;
V_1 -> V_27 %= F_17 ( V_1 -> V_26 ) ;
V_25 -> V_28 = V_6 -> V_5 ;
V_25 -> V_29 = V_5 ;
V_25 -> V_30 = V_6 -> V_8 ;
V_25 -> V_6 = V_6 ;
}
static inline void F_13 ( struct V_1 * V_1 ,
int V_5 , struct V_6 * V_6 , int V_7 , int V_8 )
{
struct V_24 * V_25 , * V_31 ;
int V_32 ;
int V_33 = 0 ;
V_25 = V_1 -> V_26 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_1 -> V_26 ) ; V_32 ++ , V_25 ++ ) {
if ( V_25 -> V_6 == V_6 ) {
V_25 -> V_34 = V_5 ;
V_25 -> V_35 = V_8 ;
V_25 -> V_7 = V_7 ;
V_25 -> V_6 = NULL ;
V_33 = 1 ;
break;
}
}
if ( V_33 && V_7 ) {
V_31 = & V_1 -> V_36 [
V_1 -> V_37 ++ ] ;
V_1 -> V_37 %= F_17 (
V_1 -> V_36 ) ;
* V_31 = * V_25 ;
}
}
static char * F_18 ( struct V_38 * V_39 , char * V_40 , int V_41 )
{
if ( V_39 )
snprintf ( V_40 , V_41 , L_1 ,
V_39 -> V_42 . V_43 ,
F_19 ( & V_39 -> V_42 ) ,
V_39 ) ;
else
snprintf ( V_40 , V_41 , L_2 ) ;
return V_40 ;
}
static char * F_20 ( T_1 V_22 , char * V_40 , int V_41 )
{
snprintf ( V_40 , V_41 ,
L_3 ,
V_22 & 0x7F ,
( V_22 >> V_44 ) & 0x0F ,
V_45 [ ( V_22 >> V_46 ) & 0x03 ] ,
V_47 [ ( V_22 >> V_48 ) & 0x01 ] ,
V_49 [ ( V_22 >> V_50 ) & 0x03 ] ,
( V_22 >> V_51 ) & 0x01 ) ;
return V_40 ;
}
static int F_21 ( struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_1 = V_53 -> V_55 ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 = 0 ;
int V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 0 ;
unsigned int V_62 = 0 ;
int V_32 ;
struct V_63 * V_64 ;
T_1 V_65 ;
unsigned long V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_69 ;
F_22 ( & V_1 -> V_70 , V_66 ) ;
V_65 = F_23 ( V_1 -> V_71 + V_72 ) ;
for ( V_32 = 0 , V_64 = V_1 -> V_64 ; V_32 < V_73 ; V_32 ++ , V_64 ++ ) {
if ( V_64 -> V_74 )
V_56 ++ ;
if ( V_64 -> V_2 )
V_57 ++ ;
if ( V_65 & ( 1 << V_32 ) )
V_58 ++ ;
}
F_24 (dmem, &imx21->dmem_list, list) {
V_62 += V_68 -> V_4 ;
V_59 ++ ;
}
F_24 (ep_priv, &imx21->queue_for_etd, queue)
V_60 ++ ;
F_24 (etd, &imx21->queue_for_dmem, queue)
V_61 ++ ;
F_25 ( & V_1 -> V_70 , V_66 ) ;
F_26 ( V_53 ,
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
F_23 ( V_1 -> V_71 + V_75 ) & 0xFFFF ,
V_56 , V_73 , V_1 -> V_20 . V_21 ,
V_57 ,
V_58 ,
V_62 , V_76 , V_1 -> V_23 . V_21 ,
V_59 ,
V_60 ,
V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_1 = V_53 -> V_55 ;
struct V_67 * V_68 ;
unsigned long V_66 ;
char V_77 [ 40 ] ;
F_22 ( & V_1 -> V_70 , V_66 ) ;
F_24 (dmem, &imx21->dmem_list, list)
F_26 ( V_53 ,
L_12
L_13 ,
V_68 -> V_78 , V_68 -> V_4 ,
F_18 ( V_68 -> V_39 , V_77 , sizeof( V_77 ) ) ) ;
F_25 ( & V_1 -> V_70 , V_66 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_1 = V_53 -> V_55 ;
struct V_63 * V_64 ;
char V_40 [ 60 ] ;
T_1 V_79 ;
int V_32 , V_80 ;
unsigned long V_66 ;
F_22 ( & V_1 -> V_70 , V_66 ) ;
for ( V_32 = 0 , V_64 = V_1 -> V_64 ; V_32 < V_73 ; V_32 ++ , V_64 ++ ) {
int V_81 = - 1 ;
struct V_82 * V_82 ;
if ( V_64 -> V_2 ) {
V_82 = V_64 -> V_2 -> V_83 ;
if ( V_82 )
V_81 = V_82 -> V_81 ;
}
F_26 ( V_53 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
V_32 ,
F_18 ( V_64 -> V_39 , V_40 , sizeof( V_40 ) ) ,
V_64 -> V_74 ,
V_64 -> V_8 ,
V_64 -> V_2 != NULL ,
( F_23 ( V_1 -> V_71 + V_72 ) & ( 1 << V_32 ) ) > 0 ,
V_81 ,
V_64 -> V_2 ) ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
V_79 = F_29 ( V_1 , V_32 , V_80 ) ;
switch ( V_80 ) {
case 0 :
F_20 ( V_79 , V_40 , sizeof( V_40 ) ) ;
break;
case 2 :
snprintf ( V_40 , sizeof( V_40 ) ,
L_22 , V_79 >> V_84 ) ;
break;
default:
* V_40 = 0 ;
break;
}
F_26 ( V_53 ,
L_23 ,
V_80 ,
V_64 -> V_85 [ V_80 ] ,
V_79 ,
V_40 ) ;
}
F_26 ( V_53 , L_24 ) ;
}
F_25 ( & V_1 -> V_70 , V_66 ) ;
return 0 ;
}
static void F_30 ( struct V_52 * V_53 ,
const char * V_86 , struct V_9 * V_87 )
{
F_26 ( V_53 , L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
V_86 ,
V_87 -> V_13 ,
V_87 -> V_16 ,
V_87 -> V_15 ,
V_87 -> V_17 ,
V_87 -> V_18 ,
V_87 -> V_19 ) ;
}
static int F_31 ( struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_1 = V_53 -> V_55 ;
unsigned long V_66 ;
F_22 ( & V_1 -> V_70 , V_66 ) ;
F_30 ( V_53 , L_32 , & V_1 -> V_12 ) ;
F_30 ( V_53 , L_33 , & V_1 -> V_11 ) ;
F_26 ( V_53 , L_34 , V_1 -> V_88 ) ;
F_25 ( & V_1 -> V_70 , V_66 ) ;
return 0 ;
}
static void F_32 ( struct V_52 * V_53 ,
const char * V_86 , int V_89 , struct V_24 * V_25 )
{
F_26 ( V_53 , L_35
L_36
L_37
L_38
L_39
L_40
L_41 ,
V_86 , V_89 ,
V_25 -> V_7 ,
V_25 -> V_28 , V_25 -> V_28 & 0xFFFF ,
V_25 -> V_29 , V_25 -> V_29 & 0xFFFF ,
V_25 -> V_34 , V_25 -> V_34 & 0xFFFF ,
V_25 -> V_30 ,
V_25 -> V_35 ) ;
}
static int F_33 ( struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_1 = V_53 -> V_55 ;
struct V_24 * V_25 ;
unsigned long V_66 ;
int V_32 ;
F_22 ( & V_1 -> V_70 , V_66 ) ;
V_25 = V_1 -> V_36 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_1 -> V_36 ) ; V_32 ++ , V_25 ++ )
F_32 ( V_53 , L_42 , V_32 , V_25 ) ;
V_25 = V_1 -> V_26 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_1 -> V_26 ) ; V_32 ++ , V_25 ++ )
F_32 ( V_53 , L_33 , V_32 , V_25 ) ;
F_25 ( & V_1 -> V_70 , V_66 ) ;
return 0 ;
}
static int F_34 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_35 ( V_91 , F_21 , V_90 -> V_92 ) ;
}
static int F_36 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_35 ( V_91 , F_27 , V_90 -> V_92 ) ;
}
static int F_37 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_35 ( V_91 , F_28 , V_90 -> V_92 ) ;
}
static int F_38 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_35 ( V_91 , F_31 , V_90 -> V_92 ) ;
}
static int F_39 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_35 ( V_91 , F_33 , V_90 -> V_92 ) ;
}
static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_93 = F_40 ( F_41 ( V_1 -> V_94 ) , NULL ) ;
if ( ! V_1 -> V_93 )
goto V_95;
if ( ! F_42 ( L_43 , V_96 ,
V_1 -> V_93 , V_1 , & V_97 ) )
goto V_98;
if ( ! F_42 ( L_44 , V_96 ,
V_1 -> V_93 , V_1 , & V_99 ) )
goto V_98;
if ( ! F_42 ( L_45 , V_96 ,
V_1 -> V_93 , V_1 , & V_100 ) )
goto V_98;
if ( ! F_42 ( L_46 , V_96 ,
V_1 -> V_93 , V_1 , & V_101 ) )
goto V_98;
if ( ! F_42 ( L_33 , V_96 ,
V_1 -> V_93 , V_1 , & V_102 ) )
goto V_98;
return;
V_98:
F_43 ( V_1 -> V_93 ) ;
V_95:
V_1 -> V_93 = NULL ;
}
static void F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_93 ) {
F_43 ( V_1 -> V_93 ) ;
V_1 -> V_93 = NULL ;
}
}
