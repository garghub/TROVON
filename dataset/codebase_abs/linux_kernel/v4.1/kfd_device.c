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
bool F_16 ( struct V_6 * V_13 ,
const struct V_32 * V_33 )
{
unsigned int V_34 ;
V_13 -> V_35 = * V_33 ;
V_34 = V_36 *
V_13 -> V_5 -> V_37 ;
V_34 += ( V_38 * sizeof( struct V_39 ) +
V_36 *
sizeof( struct V_40 ) + sizeof( struct V_41 ) ) * 2 ;
V_34 += V_42 * 2 ;
V_34 += 512 * 1024 ;
if ( V_13 -> V_17 -> V_43 (
V_13 -> V_8 , V_34 , & V_13 -> V_44 ,
& V_13 -> V_45 , & V_13 -> V_46 ) ) {
F_8 ( V_28 ,
L_5 ,
V_34 , V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
goto V_48;
}
F_17 ( V_28 ,
L_6 ,
V_34 , V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
if ( F_18 ( V_13 , V_34 , 512 ) != 0 ) {
F_8 ( V_28 ,
L_7 ) ;
goto V_49;
}
F_19 ( V_13 ) ;
if ( F_20 ( V_13 ) != 0 ) {
F_8 ( V_28 ,
L_8 ,
V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
goto V_50;
}
if ( ! F_7 ( V_13 ) ) {
F_8 ( V_28 ,
L_9 ,
V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
goto V_51;
}
F_21 ( V_13 -> V_10 ,
F_13 ) ;
V_13 -> V_52 = F_22 ( V_13 ) ;
if ( ! V_13 -> V_52 ) {
F_8 ( V_28 ,
L_10 ,
V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
goto V_53;
}
if ( V_13 -> V_52 -> V_54 . V_55 ( V_13 -> V_52 ) != 0 ) {
F_8 ( V_28 ,
L_11 ,
V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
goto V_56;
}
V_13 -> V_16 = true ;
F_17 ( V_28 , L_12 , V_13 -> V_10 -> V_47 ,
V_13 -> V_10 -> V_14 ) ;
F_23 ( L_13 ,
V_57 ) ;
goto V_48;
V_56:
F_24 ( V_13 -> V_52 ) ;
V_53:
F_12 ( V_13 -> V_10 ) ;
V_51:
F_25 ( V_13 ) ;
V_50:
F_26 ( V_13 ) ;
V_49:
V_13 -> V_17 -> V_58 ( V_13 -> V_8 , V_13 -> V_44 ) ;
F_8 ( V_28 ,
L_14 ,
V_13 -> V_10 -> V_47 , V_13 -> V_10 -> V_14 ) ;
V_48:
return V_13 -> V_16 ;
}
void F_27 ( struct V_6 * V_13 )
{
if ( V_13 -> V_16 ) {
F_24 ( V_13 -> V_52 ) ;
F_12 ( V_13 -> V_10 ) ;
F_25 ( V_13 ) ;
F_26 ( V_13 ) ;
V_13 -> V_17 -> V_58 ( V_13 -> V_8 , V_13 -> V_44 ) ;
}
F_28 ( V_13 ) ;
}
void F_29 ( struct V_6 * V_13 )
{
F_3 ( V_13 == NULL ) ;
if ( V_13 -> V_16 ) {
V_13 -> V_52 -> V_54 . V_59 ( V_13 -> V_52 ) ;
F_21 ( V_13 -> V_10 , NULL ) ;
F_12 ( V_13 -> V_10 ) ;
}
}
int F_30 ( struct V_6 * V_13 )
{
unsigned int V_26 ;
int V_27 ;
F_3 ( V_13 == NULL ) ;
V_26 = F_31 () ;
if ( V_13 -> V_16 ) {
V_27 = F_10 ( V_13 -> V_10 , V_26 ) ;
if ( V_27 < 0 )
return - V_60 ;
F_21 ( V_13 -> V_10 ,
F_13 ) ;
V_13 -> V_52 -> V_54 . V_55 ( V_13 -> V_52 ) ;
}
return 0 ;
}
void F_32 ( struct V_6 * V_13 , const void * V_61 )
{
}
static int F_18 ( struct V_6 * V_13 , unsigned int V_62 ,
unsigned int V_63 )
{
unsigned int V_64 ;
F_3 ( ! V_13 ) ;
F_3 ( ! V_13 -> V_44 ) ;
F_3 ( V_62 < V_63 ) ;
F_3 ( V_62 == 0 ) ;
F_3 ( V_63 == 0 ) ;
V_13 -> V_65 = V_63 ;
V_13 -> V_66 = V_62 / V_63 ;
V_64 = V_13 -> V_66 / V_67 ;
F_3 ( V_64 == 0 ) ;
V_13 -> V_68 = F_5 ( V_64 , V_15 ) ;
if ( ! V_13 -> V_68 )
return - V_69 ;
F_23 ( L_15 ,
V_13 -> V_66 , V_13 -> V_68 ) ;
F_6 ( & V_13 -> V_70 ) ;
return 0 ;
}
static void F_26 ( struct V_6 * V_13 )
{
F_33 ( & V_13 -> V_70 ) ;
F_28 ( V_13 -> V_68 ) ;
}
static inline T_3 F_34 ( T_3 V_71 ,
unsigned int V_72 ,
unsigned int V_63 )
{
return V_71 + V_72 * V_63 ;
}
static inline T_4 * F_35 ( void * V_71 ,
unsigned int V_72 ,
unsigned int V_63 )
{
return ( T_4 * ) ( ( T_3 ) V_71 + V_72 * V_63 ) ;
}
int F_36 ( struct V_6 * V_13 , unsigned int V_34 ,
struct V_73 * * V_74 )
{
unsigned int V_75 , V_76 , V_77 ;
F_3 ( ! V_13 ) ;
if ( V_34 == 0 )
return - V_78 ;
if ( V_34 > V_13 -> V_66 * V_13 -> V_65 )
return - V_69 ;
* V_74 = F_37 ( sizeof( struct V_73 ) , V_15 ) ;
if ( ( * V_74 ) == NULL )
return - V_69 ;
F_23 ( L_16 , * V_74 , V_34 ) ;
V_76 = 0 ;
F_38 ( & V_13 -> V_70 ) ;
V_79:
V_75 = F_39 ( V_13 -> V_68 ,
V_13 -> V_66 ,
V_76 ) ;
F_23 ( L_17 , V_75 ) ;
if ( V_75 == V_13 -> V_66 )
goto V_80;
( * V_74 ) -> V_81 = V_75 ;
( * V_74 ) -> V_82 = V_75 ;
( * V_74 ) -> V_83 = F_34 (
V_13 -> V_45 ,
V_75 ,
V_13 -> V_65 ) ;
( * V_74 ) -> V_84 = F_35 (
V_13 -> V_46 ,
V_75 ,
V_13 -> V_65 ) ;
F_23 ( L_18 ,
( T_3 * ) ( * V_74 ) -> V_83 , ( * V_74 ) -> V_84 ) ;
if ( V_34 <= V_13 -> V_65 ) {
F_23 ( L_19 ) ;
F_40 ( V_75 , V_13 -> V_68 ) ;
goto V_85;
}
V_77 = V_34 - V_13 -> V_65 ;
do {
( * V_74 ) -> V_82 =
F_39 ( V_13 -> V_68 ,
V_13 -> V_66 , ++ V_75 ) ;
if ( ( * V_74 ) -> V_82 != V_75 ) {
V_76 = V_75 ;
goto V_79;
}
if ( V_75 == V_13 -> V_66 )
goto V_80;
if ( V_77 <= V_13 -> V_65 )
V_77 = 0 ;
else
V_77 -= V_13 -> V_65 ;
} while ( V_77 > 0 );
F_23 ( L_20 ,
( * V_74 ) -> V_81 , ( * V_74 ) -> V_82 ) ;
for ( V_75 = ( * V_74 ) -> V_81 ;
V_75 <= ( * V_74 ) -> V_82 ;
V_75 ++ )
F_40 ( V_75 , V_13 -> V_68 ) ;
V_85:
F_41 ( & V_13 -> V_70 ) ;
return 0 ;
V_80:
F_23 ( L_21 , V_74 ) ;
F_41 ( & V_13 -> V_70 ) ;
F_28 ( V_74 ) ;
return - V_69 ;
}
int F_42 ( struct V_6 * V_13 , struct V_73 * V_74 )
{
unsigned int V_86 ;
F_3 ( ! V_13 ) ;
if ( ! V_74 )
return 0 ;
F_23 ( L_22 ,
V_74 , V_74 -> V_81 , V_74 -> V_82 ) ;
F_38 ( & V_13 -> V_70 ) ;
for ( V_86 = V_74 -> V_81 ;
V_86 <= V_74 -> V_82 ;
V_86 ++ )
F_43 ( V_86 , V_13 -> V_68 ) ;
F_41 ( & V_13 -> V_70 ) ;
F_28 ( V_74 ) ;
return 0 ;
}
