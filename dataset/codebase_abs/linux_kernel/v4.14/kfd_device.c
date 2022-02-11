static const struct V_1 * F_1 ( unsigned short V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 ) {
F_3 ( ! V_4 [ V_3 ] . V_5 ) ;
return V_4 [ V_3 ] . V_5 ;
}
}
F_4 ( V_6 , L_1 ,
V_2 ) ;
return NULL ;
}
struct V_7 * F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 , const struct V_12 * V_13 )
{
struct V_7 * V_14 ;
const struct V_1 * V_5 =
F_1 ( V_11 -> V_15 ) ;
if ( ! V_5 ) {
F_6 ( V_6 , L_2 ) ;
return NULL ;
}
V_14 = F_7 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_9 = V_9 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_11 = V_11 ;
V_14 -> V_17 = false ;
V_14 -> V_18 = V_13 ;
F_8 ( & V_14 -> V_19 ) ;
memset ( & V_14 -> V_20 , 0 ,
sizeof( V_14 -> V_20 ) ) ;
return V_14 ;
}
static bool F_9 ( struct V_7 * V_14 )
{
const T_2 V_21 = V_22 |
V_23 |
V_24 ;
struct V_25 V_26 ;
unsigned int V_27 ;
int V_28 ;
V_28 = V_25 ( V_14 -> V_11 , & V_26 ) ;
if ( V_28 < 0 ) {
F_6 ( V_6 ,
L_3 ) ;
return false ;
}
if ( ( V_26 . V_29 & V_21 ) != V_21 ) {
F_6 ( V_6 , L_4 ,
( V_26 . V_29 & V_22 ) != 0 ,
( V_26 . V_29 & V_23 ) != 0 ,
( V_26 . V_29 & V_24 )
!= 0 ) ;
return false ;
}
V_27 = F_10 (unsigned int,
(unsigned int)(1 << kfd->device_info->max_pasid_bits),
iommu_info.max_pasids) ;
V_27 = F_10 (unsigned int,
pasid_limit,
kfd->doorbell_process_limit - 1 ) ;
V_28 = F_11 ( V_14 -> V_11 , V_27 ) ;
if ( V_28 < 0 ) {
F_6 ( V_6 , L_5 ) ;
return false ;
}
if ( ! F_12 ( V_27 ) ) {
F_6 ( V_6 , L_6 ) ;
F_13 ( V_14 -> V_11 ) ;
return false ;
}
return true ;
}
static void F_14 ( struct V_10 * V_11 , int V_30 )
{
struct V_7 * V_31 = F_15 ( V_11 ) ;
if ( V_31 )
F_16 ( V_31 , V_30 ) ;
}
static int F_17 ( struct V_10 * V_11 , int V_30 ,
unsigned long V_32 , T_3 V_29 )
{
struct V_7 * V_31 ;
F_4 ( V_6 ,
L_7 ,
F_18 ( V_11 -> V_33 ) ,
F_19 ( V_11 -> V_33 ) ,
F_20 ( V_11 -> V_33 ) ,
V_30 ,
V_32 ,
V_29 ) ;
V_31 = F_15 ( V_11 ) ;
if ( ! F_3 ( ! V_31 ) )
F_21 ( V_31 , V_30 , V_32 ,
V_29 & V_34 , V_29 & V_35 ) ;
return V_36 ;
}
bool F_22 ( struct V_7 * V_14 ,
const struct V_37 * V_38 )
{
unsigned int V_39 ;
V_14 -> V_40 = * V_38 ;
V_39 = V_41 *
V_14 -> V_5 -> V_42 ;
V_39 += ( V_43 * sizeof( struct V_44 ) +
V_41 * sizeof( struct V_45 )
+ sizeof( struct V_46 ) ) * 2 ;
V_39 += V_47 * 2 ;
V_39 += 512 * 1024 ;
if ( V_14 -> V_18 -> V_48 (
V_14 -> V_9 , V_39 , & V_14 -> V_49 ,
& V_14 -> V_50 , & V_14 -> V_51 ) ) {
F_6 ( V_6 , L_8 , V_39 ) ;
goto V_52;
}
F_23 ( V_6 , L_9 , V_39 ) ;
if ( F_24 ( V_14 , V_39 , 512 ) != 0 ) {
F_6 ( V_6 , L_10 ) ;
goto V_53;
}
if ( F_25 ( V_14 ) ) {
F_6 ( V_6 ,
L_11 ) ;
goto V_54;
}
if ( F_26 ( V_14 ) ) {
F_6 ( V_6 , L_12 ) ;
goto V_55;
}
if ( F_27 ( V_14 ) ) {
F_6 ( V_6 , L_13 ) ;
goto V_56;
}
if ( ! F_9 ( V_14 ) ) {
F_6 ( V_6 ,
L_14 ,
V_14 -> V_11 -> V_57 , V_14 -> V_11 -> V_15 ) ;
goto V_58;
}
F_28 ( V_14 -> V_11 ,
F_14 ) ;
F_29 ( V_14 -> V_11 , F_17 ) ;
V_14 -> V_59 = F_30 ( V_14 ) ;
if ( ! V_14 -> V_59 ) {
F_6 ( V_6 , L_15 ) ;
goto V_60;
}
if ( V_14 -> V_59 -> V_61 . V_62 ( V_14 -> V_59 ) ) {
F_6 ( V_6 ,
L_16 ,
V_14 -> V_11 -> V_57 , V_14 -> V_11 -> V_15 ) ;
goto V_63;
}
V_14 -> V_64 = NULL ;
V_14 -> V_17 = true ;
F_23 ( V_6 , L_17 , V_14 -> V_11 -> V_57 ,
V_14 -> V_11 -> V_15 ) ;
F_31 ( L_18 ,
V_65 ) ;
goto V_52;
V_63:
F_32 ( V_14 -> V_59 ) ;
V_60:
F_13 ( V_14 -> V_11 ) ;
V_58:
F_33 ( V_14 ) ;
V_56:
F_34 ( V_14 ) ;
V_55:
F_35 ( V_14 ) ;
V_54:
F_36 ( V_14 ) ;
V_53:
V_14 -> V_18 -> V_66 ( V_14 -> V_9 , V_14 -> V_49 ) ;
F_6 ( V_6 ,
L_19 ,
V_14 -> V_11 -> V_57 , V_14 -> V_11 -> V_15 ) ;
V_52:
return V_14 -> V_17 ;
}
void F_37 ( struct V_7 * V_14 )
{
if ( V_14 -> V_17 ) {
F_32 ( V_14 -> V_59 ) ;
F_13 ( V_14 -> V_11 ) ;
F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
F_35 ( V_14 ) ;
F_36 ( V_14 ) ;
V_14 -> V_18 -> V_66 ( V_14 -> V_9 , V_14 -> V_49 ) ;
}
F_38 ( V_14 ) ;
}
void F_39 ( struct V_7 * V_14 )
{
if ( V_14 -> V_17 ) {
V_14 -> V_59 -> V_61 . V_67 ( V_14 -> V_59 ) ;
F_28 ( V_14 -> V_11 , NULL ) ;
F_29 ( V_14 -> V_11 , NULL ) ;
F_13 ( V_14 -> V_11 ) ;
}
}
int F_40 ( struct V_7 * V_14 )
{
unsigned int V_27 ;
int V_28 ;
V_27 = F_41 () ;
if ( V_14 -> V_17 ) {
V_28 = F_11 ( V_14 -> V_11 , V_27 ) ;
if ( V_28 < 0 ) {
F_6 ( V_6 , L_20 ) ;
return - V_68 ;
}
F_28 ( V_14 -> V_11 ,
F_14 ) ;
F_29 ( V_14 -> V_11 , F_17 ) ;
V_14 -> V_59 -> V_61 . V_62 ( V_14 -> V_59 ) ;
}
return 0 ;
}
void F_42 ( struct V_7 * V_14 , const void * V_69 )
{
if ( ! V_14 -> V_17 )
return;
F_43 ( & V_14 -> V_70 ) ;
if ( V_14 -> V_71
&& F_44 ( V_14 , V_69 )
&& F_45 ( V_14 , V_69 ) )
F_46 ( & V_14 -> V_72 ) ;
F_47 ( & V_14 -> V_70 ) ;
}
static int F_24 ( struct V_7 * V_14 , unsigned int V_73 ,
unsigned int V_74 )
{
unsigned int V_75 ;
if ( F_3 ( V_73 < V_74 ) )
return - V_76 ;
if ( F_3 ( V_73 == 0 ) )
return - V_76 ;
if ( F_3 ( V_74 == 0 ) )
return - V_76 ;
V_14 -> V_77 = V_74 ;
V_14 -> V_78 = V_73 / V_74 ;
V_75 = ( V_14 -> V_78 + V_79 - 1 ) /
V_79 ;
V_14 -> V_80 = F_48 ( V_75 , sizeof( long ) , V_16 ) ;
if ( ! V_14 -> V_80 )
return - V_81 ;
F_31 ( L_21 ,
V_14 -> V_78 , V_14 -> V_80 ) ;
F_8 ( & V_14 -> V_82 ) ;
return 0 ;
}
static void F_36 ( struct V_7 * V_14 )
{
F_49 ( & V_14 -> V_82 ) ;
F_38 ( V_14 -> V_80 ) ;
}
static inline T_4 F_50 ( T_4 V_83 ,
unsigned int V_84 ,
unsigned int V_74 )
{
return V_83 + V_84 * V_74 ;
}
static inline T_5 * F_51 ( void * V_83 ,
unsigned int V_84 ,
unsigned int V_74 )
{
return ( T_5 * ) ( ( T_4 ) V_83 + V_84 * V_74 ) ;
}
int F_52 ( struct V_7 * V_14 , unsigned int V_39 ,
struct V_85 * * V_86 )
{
unsigned int V_87 , V_88 , V_89 ;
if ( V_39 == 0 )
return - V_76 ;
if ( V_39 > V_14 -> V_78 * V_14 -> V_77 )
return - V_81 ;
* V_86 = F_53 ( sizeof( struct V_85 ) , V_16 ) ;
if ( ( * V_86 ) == NULL )
return - V_81 ;
F_31 ( L_22 , * V_86 , V_39 ) ;
V_88 = 0 ;
F_54 ( & V_14 -> V_82 ) ;
V_90:
V_87 = F_55 ( V_14 -> V_80 ,
V_14 -> V_78 ,
V_88 ) ;
F_31 ( L_23 , V_87 ) ;
if ( V_87 == V_14 -> V_78 )
goto V_91;
( * V_86 ) -> V_92 = V_87 ;
( * V_86 ) -> V_93 = V_87 ;
( * V_86 ) -> V_94 = F_50 (
V_14 -> V_50 ,
V_87 ,
V_14 -> V_77 ) ;
( * V_86 ) -> V_95 = F_51 (
V_14 -> V_51 ,
V_87 ,
V_14 -> V_77 ) ;
F_31 ( L_24 ,
( T_4 * ) ( * V_86 ) -> V_94 , ( * V_86 ) -> V_95 ) ;
if ( V_39 <= V_14 -> V_77 ) {
F_31 ( L_25 ) ;
F_56 ( V_87 , V_14 -> V_80 ) ;
goto V_96;
}
V_89 = V_39 - V_14 -> V_77 ;
do {
( * V_86 ) -> V_93 =
F_55 ( V_14 -> V_80 ,
V_14 -> V_78 , ++ V_87 ) ;
if ( ( * V_86 ) -> V_93 != V_87 ) {
V_88 = V_87 ;
goto V_90;
}
if ( V_87 == V_14 -> V_78 )
goto V_91;
if ( V_89 <= V_14 -> V_77 )
V_89 = 0 ;
else
V_89 -= V_14 -> V_77 ;
} while ( V_89 > 0 );
F_31 ( L_26 ,
( * V_86 ) -> V_92 , ( * V_86 ) -> V_93 ) ;
for ( V_87 = ( * V_86 ) -> V_92 ;
V_87 <= ( * V_86 ) -> V_93 ;
V_87 ++ )
F_56 ( V_87 , V_14 -> V_80 ) ;
V_96:
F_57 ( & V_14 -> V_82 ) ;
return 0 ;
V_91:
F_31 ( L_27 , V_86 ) ;
F_57 ( & V_14 -> V_82 ) ;
F_38 ( V_86 ) ;
return - V_81 ;
}
int F_58 ( struct V_7 * V_14 , struct V_85 * V_86 )
{
unsigned int V_97 ;
if ( ! V_86 )
return 0 ;
F_31 ( L_28 ,
V_86 , V_86 -> V_92 , V_86 -> V_93 ) ;
F_54 ( & V_14 -> V_82 ) ;
for ( V_97 = V_86 -> V_92 ;
V_97 <= V_86 -> V_93 ;
V_97 ++ )
F_59 ( V_97 , V_14 -> V_80 ) ;
F_57 ( & V_14 -> V_82 ) ;
F_38 ( V_86 ) ;
return 0 ;
}
