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
V_29 += 512 * 1024 ;
if ( V_33 -> V_34 ( V_11 -> V_8 , V_29 ) ) {
F_7 ( V_23 ,
L_5 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
goto V_36;
}
F_16 ( V_11 ) ;
if ( F_17 ( V_11 ) != 0 ) {
F_7 ( V_23 ,
L_6 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
goto V_37;
}
if ( ! F_6 ( V_11 ) ) {
F_7 ( V_23 ,
L_7 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
goto V_38;
}
F_18 ( V_11 -> V_10 ,
F_12 ) ;
V_11 -> V_39 = F_19 ( V_11 ) ;
if ( ! V_11 -> V_39 ) {
F_7 ( V_23 ,
L_8 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
goto V_40;
}
if ( V_11 -> V_39 -> V_41 ( V_11 -> V_39 ) != 0 ) {
F_7 ( V_23 ,
L_9 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
goto V_42;
}
V_11 -> V_14 = true ;
F_20 ( V_23 , L_10 , V_11 -> V_10 -> V_35 ,
V_11 -> V_10 -> V_12 ) ;
F_21 ( L_11 ,
V_43 ) ;
goto V_36;
V_42:
F_22 ( V_11 -> V_39 ) ;
V_40:
F_11 ( V_11 -> V_10 ) ;
V_38:
F_23 ( V_11 ) ;
V_37:
V_33 -> V_44 ( V_11 -> V_8 ) ;
F_7 ( V_23 ,
L_12 ,
V_11 -> V_10 -> V_35 , V_11 -> V_10 -> V_12 ) ;
V_36:
return V_11 -> V_14 ;
}
void F_24 ( struct V_6 * V_11 )
{
if ( V_11 -> V_14 ) {
F_22 ( V_11 -> V_39 ) ;
F_11 ( V_11 -> V_10 ) ;
F_23 ( V_11 ) ;
}
F_25 ( V_11 ) ;
}
void F_26 ( struct V_6 * V_11 )
{
F_3 ( V_11 == NULL ) ;
if ( V_11 -> V_14 ) {
V_11 -> V_39 -> V_45 ( V_11 -> V_39 ) ;
F_18 ( V_11 -> V_10 , NULL ) ;
F_11 ( V_11 -> V_10 ) ;
}
}
int F_27 ( struct V_6 * V_11 )
{
unsigned int V_21 ;
int V_22 ;
F_3 ( V_11 == NULL ) ;
V_21 = F_28 () ;
if ( V_11 -> V_14 ) {
V_22 = F_9 ( V_11 -> V_10 , V_21 ) ;
if ( V_22 < 0 )
return - V_46 ;
F_18 ( V_11 -> V_10 ,
F_12 ) ;
V_11 -> V_39 -> V_41 ( V_11 -> V_39 ) ;
}
return 0 ;
}
void F_29 ( struct V_6 * V_11 , const void * V_47 )
{
}
