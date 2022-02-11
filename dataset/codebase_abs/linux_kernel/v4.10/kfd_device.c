static const struct V_1 * F_1 ( unsigned short V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 ) {
F_3 ( V_4 [ V_3 ] . V_5 == NULL ) ;
return V_4 [ V_3 ] . V_5 ;
}
}
return NULL ;
}
struct V_6 * F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_6 * V_13 ;
const struct V_1 * V_5 =
F_1 ( V_10 -> V_14 ) ;
if ( ! V_5 )
return NULL ;
V_13 = F_5 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_8 = V_8 ;
V_13 -> V_5 = V_5 ;
V_13 -> V_10 = V_10 ;
V_13 -> V_16 = false ;
V_13 -> V_17 = V_12 ;
F_6 ( & V_13 -> V_18 ) ;
memset ( & V_13 -> V_19 , 0 ,
sizeof( V_13 -> V_19 ) ) ;
return V_13 ;
}
static bool F_7 ( struct V_6 * V_13 )
{
const T_2 V_20 = V_21 |
V_22 |
V_23 ;
struct V_24 V_25 ;
unsigned int V_26 ;
int V_27 ;
V_27 = V_24 ( V_13 -> V_10 , & V_25 ) ;
if ( V_27 < 0 ) {
F_8 ( V_28 ,
L_1 ) ;
return false ;
}
if ( ( V_25 . V_29 & V_20 ) != V_20 ) {
F_8 ( V_28 , L_2 ,
( V_25 . V_29 & V_21 ) != 0 ,
( V_25 . V_29 & V_22 ) != 0 ,
( V_25 . V_29 & V_23 ) != 0 ) ;
return false ;
}
V_26 = F_9 (unsigned int,
(unsigned int)1 << kfd->device_info->max_pasid_bits,
iommu_info.max_pasids) ;
V_26 = F_9 (unsigned int,
pasid_limit,
kfd->doorbell_process_limit - 1 ) ;
V_27 = F_10 ( V_13 -> V_10 , V_26 ) ;
if ( V_27 < 0 ) {
F_8 ( V_28 , L_3 ) ;
return false ;
}
if ( ! F_11 ( V_26 ) ) {
F_8 ( V_28 , L_4 ) ;
F_12 ( V_13 -> V_10 ) ;
return false ;
}
return true ;
}
static void F_13 ( struct V_9 * V_10 , int V_30 )
{
struct V_6 * V_31 = F_14 ( V_10 ) ;
if ( V_31 )
F_15 ( V_31 , V_30 ) ;
}
static int F_16 ( struct V_9 * V_10 , int V_30 ,
unsigned long V_32 , T_3 V_29 )
{
struct V_6 * V_31 ;
F_17 ( V_28 ,
L_5 ,
F_18 ( V_10 -> V_33 ) ,
F_19 ( V_10 -> V_33 ) ,
F_20 ( V_10 -> V_33 ) ,
V_30 ,
V_32 ,
V_29 ) ;
V_31 = F_14 ( V_10 ) ;
F_3 ( V_31 == NULL ) ;
F_21 ( V_31 , V_30 , V_32 ,
V_29 & V_34 , V_29 & V_35 ) ;
return V_36 ;
}
bool F_22 ( struct V_6 * V_13 ,
const struct V_37 * V_38 )
{
unsigned int V_39 ;
V_13 -> V_40 = * V_38 ;
V_39 = V_41 *
V_13 -> V_5 -> V_42 ;
V_39 += ( V_43 * sizeof( struct V_44 ) +
V_41 *
sizeof( struct V_45 ) + sizeof( struct V_46 ) ) * 2 ;
V_39 += V_47 * 2 ;
V_39 += 512 * 1024 ;
if ( V_13 -> V_17 -> V_48 (
V_13 -> V_8 , V_39 , & V_13 -> V_49 ,
& V_13 -> V_50 , & V_13 -> V_51 ) ) {
F_8 ( V_28 ,
L_6 ,
V_39 , V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_53;
}
F_23 ( V_28 ,
L_7 ,
V_39 , V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
if ( F_24 ( V_13 , V_39 , 512 ) != 0 ) {
F_8 ( V_28 ,
L_8 ) ;
goto V_54;
}
F_25 ( V_13 ) ;
if ( F_26 ( V_13 ) != 0 ) {
F_8 ( V_28 ,
L_9 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_55;
}
if ( F_27 ( V_13 ) ) {
F_8 ( V_28 ,
L_10 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_56;
}
if ( ! F_7 ( V_13 ) ) {
F_8 ( V_28 ,
L_11 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_57;
}
F_28 ( V_13 -> V_10 ,
F_13 ) ;
F_29 ( V_13 -> V_10 , F_16 ) ;
V_13 -> V_58 = F_30 ( V_13 ) ;
if ( ! V_13 -> V_58 ) {
F_8 ( V_28 ,
L_12 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_59;
}
if ( V_13 -> V_58 -> V_60 . V_61 ( V_13 -> V_58 ) != 0 ) {
F_8 ( V_28 ,
L_13 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
goto V_62;
}
V_13 -> V_63 = NULL ;
V_13 -> V_16 = true ;
F_23 ( V_28 , L_14 , V_13 -> V_10 -> V_52 ,
V_13 -> V_10 -> V_14 ) ;
F_31 ( L_15 ,
V_64 ) ;
goto V_53;
V_62:
F_32 ( V_13 -> V_58 ) ;
V_59:
F_12 ( V_13 -> V_10 ) ;
V_57:
F_33 ( V_13 ) ;
V_56:
F_34 ( V_13 ) ;
V_55:
F_35 ( V_13 ) ;
V_54:
V_13 -> V_17 -> V_65 ( V_13 -> V_8 , V_13 -> V_49 ) ;
F_8 ( V_28 ,
L_16 ,
V_13 -> V_10 -> V_52 , V_13 -> V_10 -> V_14 ) ;
V_53:
return V_13 -> V_16 ;
}
void F_36 ( struct V_6 * V_13 )
{
if ( V_13 -> V_16 ) {
F_32 ( V_13 -> V_58 ) ;
F_12 ( V_13 -> V_10 ) ;
F_33 ( V_13 ) ;
F_34 ( V_13 ) ;
F_35 ( V_13 ) ;
V_13 -> V_17 -> V_65 ( V_13 -> V_8 , V_13 -> V_49 ) ;
}
F_37 ( V_13 ) ;
}
void F_38 ( struct V_6 * V_13 )
{
F_3 ( V_13 == NULL ) ;
if ( V_13 -> V_16 ) {
V_13 -> V_58 -> V_60 . V_66 ( V_13 -> V_58 ) ;
F_28 ( V_13 -> V_10 , NULL ) ;
F_29 ( V_13 -> V_10 , NULL ) ;
F_12 ( V_13 -> V_10 ) ;
}
}
int F_39 ( struct V_6 * V_13 )
{
unsigned int V_26 ;
int V_27 ;
F_3 ( V_13 == NULL ) ;
V_26 = F_40 () ;
if ( V_13 -> V_16 ) {
V_27 = F_10 ( V_13 -> V_10 , V_26 ) ;
if ( V_27 < 0 )
return - V_67 ;
F_28 ( V_13 -> V_10 ,
F_13 ) ;
F_29 ( V_13 -> V_10 , F_16 ) ;
V_13 -> V_58 -> V_60 . V_61 ( V_13 -> V_58 ) ;
}
return 0 ;
}
void F_41 ( struct V_6 * V_13 , const void * V_68 )
{
if ( ! V_13 -> V_16 )
return;
F_42 ( & V_13 -> V_69 ) ;
if ( V_13 -> V_70
&& F_43 ( V_13 , V_68 )
&& F_44 ( V_13 , V_68 ) )
F_45 ( & V_13 -> V_71 ) ;
F_46 ( & V_13 -> V_69 ) ;
}
static int F_24 ( struct V_6 * V_13 , unsigned int V_72 ,
unsigned int V_73 )
{
unsigned int V_74 ;
F_3 ( ! V_13 ) ;
F_3 ( ! V_13 -> V_49 ) ;
F_3 ( V_72 < V_73 ) ;
F_3 ( V_72 == 0 ) ;
F_3 ( V_73 == 0 ) ;
V_13 -> V_75 = V_73 ;
V_13 -> V_76 = V_72 / V_73 ;
V_74 = V_13 -> V_76 / V_77 ;
F_3 ( V_74 == 0 ) ;
V_13 -> V_78 = F_5 ( V_74 , V_15 ) ;
if ( ! V_13 -> V_78 )
return - V_79 ;
F_31 ( L_17 ,
V_13 -> V_76 , V_13 -> V_78 ) ;
F_6 ( & V_13 -> V_80 ) ;
return 0 ;
}
static void F_35 ( struct V_6 * V_13 )
{
F_47 ( & V_13 -> V_80 ) ;
F_37 ( V_13 -> V_78 ) ;
}
static inline T_4 F_48 ( T_4 V_81 ,
unsigned int V_82 ,
unsigned int V_73 )
{
return V_81 + V_82 * V_73 ;
}
static inline T_5 * F_49 ( void * V_81 ,
unsigned int V_82 ,
unsigned int V_73 )
{
return ( T_5 * ) ( ( T_4 ) V_81 + V_82 * V_73 ) ;
}
int F_50 ( struct V_6 * V_13 , unsigned int V_39 ,
struct V_83 * * V_84 )
{
unsigned int V_85 , V_86 , V_87 ;
F_3 ( ! V_13 ) ;
if ( V_39 == 0 )
return - V_88 ;
if ( V_39 > V_13 -> V_76 * V_13 -> V_75 )
return - V_79 ;
* V_84 = F_51 ( sizeof( struct V_83 ) , V_15 ) ;
if ( ( * V_84 ) == NULL )
return - V_79 ;
F_31 ( L_18 , * V_84 , V_39 ) ;
V_86 = 0 ;
F_52 ( & V_13 -> V_80 ) ;
V_89:
V_85 = F_53 ( V_13 -> V_78 ,
V_13 -> V_76 ,
V_86 ) ;
F_31 ( L_19 , V_85 ) ;
if ( V_85 == V_13 -> V_76 )
goto V_90;
( * V_84 ) -> V_91 = V_85 ;
( * V_84 ) -> V_92 = V_85 ;
( * V_84 ) -> V_93 = F_48 (
V_13 -> V_50 ,
V_85 ,
V_13 -> V_75 ) ;
( * V_84 ) -> V_94 = F_49 (
V_13 -> V_51 ,
V_85 ,
V_13 -> V_75 ) ;
F_31 ( L_20 ,
( T_4 * ) ( * V_84 ) -> V_93 , ( * V_84 ) -> V_94 ) ;
if ( V_39 <= V_13 -> V_75 ) {
F_31 ( L_21 ) ;
F_54 ( V_85 , V_13 -> V_78 ) ;
goto V_95;
}
V_87 = V_39 - V_13 -> V_75 ;
do {
( * V_84 ) -> V_92 =
F_53 ( V_13 -> V_78 ,
V_13 -> V_76 , ++ V_85 ) ;
if ( ( * V_84 ) -> V_92 != V_85 ) {
V_86 = V_85 ;
goto V_89;
}
if ( V_85 == V_13 -> V_76 )
goto V_90;
if ( V_87 <= V_13 -> V_75 )
V_87 = 0 ;
else
V_87 -= V_13 -> V_75 ;
} while ( V_87 > 0 );
F_31 ( L_22 ,
( * V_84 ) -> V_91 , ( * V_84 ) -> V_92 ) ;
for ( V_85 = ( * V_84 ) -> V_91 ;
V_85 <= ( * V_84 ) -> V_92 ;
V_85 ++ )
F_54 ( V_85 , V_13 -> V_78 ) ;
V_95:
F_55 ( & V_13 -> V_80 ) ;
return 0 ;
V_90:
F_31 ( L_23 , V_84 ) ;
F_55 ( & V_13 -> V_80 ) ;
F_37 ( V_84 ) ;
return - V_79 ;
}
int F_56 ( struct V_6 * V_13 , struct V_83 * V_84 )
{
unsigned int V_96 ;
F_3 ( ! V_13 ) ;
if ( ! V_84 )
return 0 ;
F_31 ( L_24 ,
V_84 , V_84 -> V_91 , V_84 -> V_92 ) ;
F_52 ( & V_13 -> V_80 ) ;
for ( V_96 = V_84 -> V_91 ;
V_96 <= V_84 -> V_92 ;
V_96 ++ )
F_57 ( V_96 , V_13 -> V_78 ) ;
F_55 ( & V_13 -> V_80 ) ;
F_37 ( V_84 ) ;
return 0 ;
}
