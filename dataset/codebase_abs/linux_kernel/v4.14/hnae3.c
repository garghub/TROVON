static bool F_1 ( enum V_1 V_2 ,
enum V_3 V_4 )
{
if ( ( V_4 == V_5 ) && ( V_2 == V_6 ||
V_2 == V_7 ) )
return true ;
if ( V_4 == V_8 && V_2 == V_9 )
return true ;
return false ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 , bool V_14 )
{
int V_15 ;
if ( ! ( F_1 ( V_11 -> type , V_13 -> V_4 ) &&
F_3 ( V_13 -> V_16 , V_17 ) ) ) {
return 0 ;
}
if ( V_14 ) {
V_15 = V_13 -> V_18 -> V_19 ( V_11 , V_13 ) ;
if ( V_15 )
F_4 ( & V_13 -> V_20 -> V_21 ,
L_1 ) ;
return V_15 ;
}
V_13 -> V_18 -> V_22 ( V_11 , V_13 ) ;
return 0 ;
}
int F_5 ( struct V_10 * V_11 )
{
struct V_10 * V_23 ;
struct V_12 * V_13 ;
int V_15 = 0 ;
F_6 ( & V_24 ) ;
F_7 (client_tmp, &hnae3_client_list, node) {
if ( V_23 -> type == V_11 -> type )
goto exit;
}
F_8 ( & V_11 -> V_25 , & V_26 ) ;
F_7 (ae_dev, &hnae3_ae_dev_list, node) {
V_15 = F_2 ( V_11 , V_13 , true ) ;
if ( V_15 )
F_4 ( & V_13 -> V_20 -> V_21 ,
L_2 ) ;
}
exit:
F_9 ( & V_24 ) ;
return V_15 ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
F_6 ( & V_24 ) ;
F_7 (ae_dev, &hnae3_ae_dev_list, node) {
F_2 ( V_11 , V_13 , false ) ;
}
F_11 ( & V_11 -> V_25 ) ;
F_9 ( & V_24 ) ;
}
int F_12 ( struct V_27 * V_28 )
{
const struct V_29 * V_30 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
int V_15 = 0 ;
F_6 ( & V_24 ) ;
F_8 ( & V_28 -> V_25 , & V_31 ) ;
F_7 (ae_dev, &hnae3_ae_dev_list, node) {
V_30 = F_13 ( V_28 -> V_32 , V_13 -> V_20 ) ;
if ( ! V_30 )
continue;
V_13 -> V_18 = V_28 -> V_18 ;
V_15 = V_28 -> V_18 -> V_33 ( V_13 ) ;
if ( V_15 ) {
F_4 ( & V_13 -> V_20 -> V_21 , L_3 ) ;
continue;
}
F_14 ( V_13 -> V_16 , V_17 , 1 ) ;
F_7 (client, &hnae3_client_list, node) {
V_15 = F_2 ( V_11 , V_13 , true ) ;
if ( V_15 )
F_4 ( & V_13 -> V_20 -> V_21 ,
L_4 ) ;
}
}
F_9 ( & V_24 ) ;
return V_15 ;
}
void F_15 ( struct V_27 * V_28 )
{
const struct V_29 * V_30 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
F_6 ( & V_24 ) ;
F_7 (ae_dev, &hnae3_ae_dev_list, node) {
V_30 = F_13 ( V_28 -> V_32 , V_13 -> V_20 ) ;
if ( ! V_30 )
continue;
F_7 (client, &hnae3_client_list, node)
F_2 ( V_11 , V_13 , false ) ;
V_28 -> V_18 -> V_34 ( V_13 ) ;
F_14 ( V_13 -> V_16 , V_17 , 0 ) ;
}
F_11 ( & V_28 -> V_25 ) ;
F_9 ( & V_24 ) ;
}
int F_16 ( struct V_12 * V_13 )
{
const struct V_29 * V_30 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
int V_15 = 0 ;
F_6 ( & V_24 ) ;
F_8 ( & V_13 -> V_25 , & V_35 ) ;
F_7 (ae_algo, &hnae3_ae_algo_list, node) {
V_30 = F_13 ( V_28 -> V_32 , V_13 -> V_20 ) ;
if ( ! V_30 )
continue;
V_13 -> V_18 = V_28 -> V_18 ;
if ( ! V_13 -> V_18 ) {
F_4 ( & V_13 -> V_20 -> V_21 , L_5 ) ;
goto V_36;
}
V_15 = V_13 -> V_18 -> V_33 ( V_13 ) ;
if ( V_15 ) {
F_4 ( & V_13 -> V_20 -> V_21 , L_6 ) ;
goto V_36;
}
F_14 ( V_13 -> V_16 , V_17 , 1 ) ;
break;
}
F_7 (client, &hnae3_client_list, node) {
V_15 = F_2 ( V_11 , V_13 , true ) ;
if ( V_15 )
F_4 ( & V_13 -> V_20 -> V_21 ,
L_4 ) ;
}
V_36:
F_9 ( & V_24 ) ;
return V_15 ;
}
void F_17 ( struct V_12 * V_13 )
{
const struct V_29 * V_30 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
F_6 ( & V_24 ) ;
F_7 (ae_algo, &hnae3_ae_algo_list, node) {
V_30 = F_13 ( V_28 -> V_32 , V_13 -> V_20 ) ;
if ( ! V_30 )
continue;
F_7 (client, &hnae3_client_list, node)
F_2 ( V_11 , V_13 , false ) ;
V_28 -> V_18 -> V_34 ( V_13 ) ;
F_14 ( V_13 -> V_16 , V_17 , 0 ) ;
}
F_11 ( & V_13 -> V_25 ) ;
F_9 ( & V_24 ) ;
}
