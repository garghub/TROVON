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
struct V_6 * F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_6 * V_11 ;
const struct V_1 * V_5 =
F_1 ( V_10 -> V_12 ) ;
if ( ! V_5 )
return NULL ;
V_11 = F_5 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_10 = V_10 ;
V_11 -> V_14 = false ;
return V_11 ;
}
static bool F_6 ( struct V_6 * V_11 )
{
const T_2 V_15 = V_16 |
V_17 |
V_18 ;
struct V_19 V_20 ;
unsigned int V_21 ;
int V_22 ;
V_22 = V_19 ( V_11 -> V_10 , & V_20 ) ;
if ( V_22 < 0 ) {
F_7 ( V_23 ,
L_1 ) ;
return false ;
}
if ( ( V_20 . V_24 & V_15 ) != V_15 ) {
F_7 ( V_23 , L_2 ,
( V_20 . V_24 & V_16 ) != 0 ,
( V_20 . V_24 & V_17 ) != 0 ,
( V_20 . V_24 & V_18 ) != 0 ) ;
return false ;
}
V_21 = F_8 (unsigned int,
(unsigned int)1 << kfd->device_info->max_pasid_bits,
iommu_info.max_pasids) ;
V_21 = F_8 (unsigned int,
pasid_limit,
kfd->doorbell_process_limit - 1 ) ;
V_22 = F_9 ( V_11 -> V_10 , V_21 ) ;
if ( V_22 < 0 ) {
F_7 ( V_23 , L_3 ) ;
return false ;
}
if ( ! F_10 ( V_21 ) ) {
F_7 ( V_23 , L_4 ) ;
F_11 ( V_11 -> V_10 ) ;
return false ;
}
return true ;
}
static void F_12 ( struct V_9 * V_10 , int V_25 )
{
struct V_6 * V_26 = F_13 ( V_10 ) ;
if ( V_26 )
F_14 ( V_26 , V_25 ) ;
}
bool F_15 ( struct V_6 * V_11 ,
const struct V_27 * V_28 )
{
unsigned int V_29 ;
V_11 -> V_30 = * V_28 ;
V_29 = V_31 *
V_11 -> V_5 -> V_32 ;
V_29 += ( V_33 * sizeof( struct V_34 ) +
V_31 *
sizeof( struct V_35 ) + sizeof( struct V_36 ) ) * 2 ;
V_29 += V_37 * 2 ;
V_29 += 512 * 1024 ;
if ( V_38 -> V_39 ( V_11 -> V_8 , V_29 , & V_11 -> V_40 ,
& V_11 -> V_41 , & V_11 -> V_42 ) ) {
F_7 ( V_23 ,
L_5 ,
V_29 , V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
goto V_44;
}
F_16 ( V_23 ,
L_6 ,
V_29 , V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
if ( F_17 ( V_11 , V_29 , 512 ) != 0 ) {
F_7 ( V_23 ,
L_7 ) ;
goto V_45;
}
F_18 ( V_11 ) ;
if ( F_19 ( V_11 ) != 0 ) {
F_7 ( V_23 ,
L_8 ,
V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
goto V_46;
}
if ( ! F_6 ( V_11 ) ) {
F_7 ( V_23 ,
L_9 ,
V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
goto V_47;
}
F_20 ( V_11 -> V_10 ,
F_12 ) ;
V_11 -> V_48 = F_21 ( V_11 ) ;
if ( ! V_11 -> V_48 ) {
F_7 ( V_23 ,
L_10 ,
V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
goto V_49;
}
if ( V_11 -> V_48 -> V_50 . V_51 ( V_11 -> V_48 ) != 0 ) {
F_7 ( V_23 ,
L_11 ,
V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
goto V_52;
}
V_11 -> V_14 = true ;
F_16 ( V_23 , L_12 , V_11 -> V_10 -> V_43 ,
V_11 -> V_10 -> V_12 ) ;
F_22 ( L_13 ,
V_53 ) ;
goto V_44;
V_52:
F_23 ( V_11 -> V_48 ) ;
V_49:
F_11 ( V_11 -> V_10 ) ;
V_47:
F_24 ( V_11 ) ;
V_46:
F_25 ( V_11 ) ;
V_45:
V_38 -> V_54 ( V_11 -> V_8 , V_11 -> V_40 ) ;
F_7 ( V_23 ,
L_14 ,
V_11 -> V_10 -> V_43 , V_11 -> V_10 -> V_12 ) ;
V_44:
return V_11 -> V_14 ;
}
void F_26 ( struct V_6 * V_11 )
{
if ( V_11 -> V_14 ) {
F_23 ( V_11 -> V_48 ) ;
F_11 ( V_11 -> V_10 ) ;
F_24 ( V_11 ) ;
F_25 ( V_11 ) ;
V_38 -> V_54 ( V_11 -> V_8 , V_11 -> V_40 ) ;
}
F_27 ( V_11 ) ;
}
void F_28 ( struct V_6 * V_11 )
{
F_3 ( V_11 == NULL ) ;
if ( V_11 -> V_14 ) {
V_11 -> V_48 -> V_50 . V_55 ( V_11 -> V_48 ) ;
F_20 ( V_11 -> V_10 , NULL ) ;
F_11 ( V_11 -> V_10 ) ;
}
}
int F_29 ( struct V_6 * V_11 )
{
unsigned int V_21 ;
int V_22 ;
F_3 ( V_11 == NULL ) ;
V_21 = F_30 () ;
if ( V_11 -> V_14 ) {
V_22 = F_9 ( V_11 -> V_10 , V_21 ) ;
if ( V_22 < 0 )
return - V_56 ;
F_20 ( V_11 -> V_10 ,
F_12 ) ;
V_11 -> V_48 -> V_50 . V_51 ( V_11 -> V_48 ) ;
}
return 0 ;
}
void F_31 ( struct V_6 * V_11 , const void * V_57 )
{
}
static int F_17 ( struct V_6 * V_11 , unsigned int V_58 ,
unsigned int V_59 )
{
unsigned int V_60 ;
F_3 ( ! V_11 ) ;
F_3 ( ! V_11 -> V_40 ) ;
F_3 ( V_58 < V_59 ) ;
F_3 ( V_58 == 0 ) ;
F_3 ( V_59 == 0 ) ;
V_11 -> V_61 = V_59 ;
V_11 -> V_62 = V_58 / V_59 ;
V_60 = V_11 -> V_62 / V_63 ;
F_3 ( V_60 == 0 ) ;
V_11 -> V_64 = F_5 ( V_60 , V_13 ) ;
if ( ! V_11 -> V_64 )
return - V_65 ;
F_22 ( L_15 ,
V_11 -> V_62 , V_11 -> V_64 ) ;
F_32 ( & V_11 -> V_66 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_11 )
{
F_33 ( & V_11 -> V_66 ) ;
F_27 ( V_11 -> V_64 ) ;
}
static inline T_3 F_34 ( T_3 V_67 ,
unsigned int V_68 ,
unsigned int V_59 )
{
return V_67 + V_68 * V_59 ;
}
static inline T_4 * F_35 ( void * V_67 ,
unsigned int V_68 ,
unsigned int V_59 )
{
return ( T_4 * ) ( ( T_3 ) V_67 + V_68 * V_59 ) ;
}
int F_36 ( struct V_6 * V_11 , unsigned int V_29 ,
struct V_69 * * V_70 )
{
unsigned int V_71 , V_72 , V_73 ;
F_3 ( ! V_11 ) ;
if ( V_29 == 0 )
return - V_74 ;
if ( V_29 > V_11 -> V_62 * V_11 -> V_61 )
return - V_65 ;
* V_70 = F_37 ( sizeof( struct V_69 ) , V_13 ) ;
if ( ( * V_70 ) == NULL )
return - V_65 ;
F_22 ( L_16 , * V_70 , V_29 ) ;
V_72 = 0 ;
F_38 ( & V_11 -> V_66 ) ;
V_75:
V_71 = F_39 ( V_11 -> V_64 ,
V_11 -> V_62 ,
V_72 ) ;
F_22 ( L_17 , V_71 ) ;
if ( V_71 == V_11 -> V_62 )
goto V_76;
( * V_70 ) -> V_77 = V_71 ;
( * V_70 ) -> V_78 = V_71 ;
( * V_70 ) -> V_79 = F_34 (
V_11 -> V_41 ,
V_71 ,
V_11 -> V_61 ) ;
( * V_70 ) -> V_80 = F_35 (
V_11 -> V_42 ,
V_71 ,
V_11 -> V_61 ) ;
F_22 ( L_18 ,
( T_3 * ) ( * V_70 ) -> V_79 , ( * V_70 ) -> V_80 ) ;
if ( V_29 <= V_11 -> V_61 ) {
F_22 ( L_19 ) ;
F_40 ( V_71 , V_11 -> V_64 ) ;
goto V_81;
}
V_73 = V_29 - V_11 -> V_61 ;
do {
( * V_70 ) -> V_78 =
F_39 ( V_11 -> V_64 ,
V_11 -> V_62 , ++ V_71 ) ;
if ( ( * V_70 ) -> V_78 != V_71 ) {
V_72 = V_71 ;
goto V_75;
}
if ( V_71 == V_11 -> V_62 )
goto V_76;
if ( V_73 <= V_11 -> V_61 )
V_73 = 0 ;
else
V_73 -= V_11 -> V_61 ;
} while ( V_73 > 0 );
F_22 ( L_20 ,
( * V_70 ) -> V_77 , ( * V_70 ) -> V_78 ) ;
for ( V_71 = ( * V_70 ) -> V_77 ;
V_71 <= ( * V_70 ) -> V_78 ;
V_71 ++ )
F_40 ( V_71 , V_11 -> V_64 ) ;
V_81:
F_41 ( & V_11 -> V_66 ) ;
return 0 ;
V_76:
F_22 ( L_21 , V_70 ) ;
F_41 ( & V_11 -> V_66 ) ;
F_27 ( V_70 ) ;
return - V_65 ;
}
int F_42 ( struct V_6 * V_11 , struct V_69 * V_70 )
{
unsigned int V_82 ;
F_3 ( ! V_11 ) ;
if ( ! V_70 )
return 0 ;
F_22 ( L_22 ,
V_70 , V_70 -> V_77 , V_70 -> V_78 ) ;
F_38 ( & V_11 -> V_66 ) ;
for ( V_82 = V_70 -> V_77 ;
V_82 <= V_70 -> V_78 ;
V_82 ++ )
F_43 ( V_82 , V_11 -> V_64 ) ;
F_41 ( & V_11 -> V_66 ) ;
F_27 ( V_70 ) ;
return 0 ;
}
