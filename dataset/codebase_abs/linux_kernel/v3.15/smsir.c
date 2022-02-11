void F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 )
{
int V_5 ;
const T_1 * V_6 = ( const void * ) V_3 ;
for ( V_5 = 0 ; V_5 < V_4 > > 2 ; V_5 ++ ) {
F_2 ( V_7 ) ;
V_7 . V_8 = abs ( V_6 [ V_5 ] ) * 1000 ;
V_7 . V_9 = ( V_6 [ V_5 ] > 0 ) ? false : true ;
F_3 ( V_2 -> V_10 . V_11 , & V_7 ) ;
}
F_4 ( V_2 -> V_10 . V_11 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_12 ;
int V_13 = F_6 ( V_2 ) ;
struct V_14 * V_11 ;
F_7 ( L_1 ) ;
V_11 = F_8 () ;
if ( ! V_11 ) {
F_9 ( L_2 ) ;
return - V_15 ;
}
V_2 -> V_10 . V_16 = 0 ;
V_2 -> V_10 . V_17 = V_18 ;
F_7 ( L_3 ,
V_2 -> V_10 . V_16 , V_2 -> V_10 . V_17 ) ;
snprintf ( V_2 -> V_10 . V_19 , sizeof( V_2 -> V_10 . V_19 ) ,
L_4 , F_10 ( V_13 ) -> V_19 ) ;
F_11 ( V_2 -> V_10 . V_20 , V_2 -> V_21 , sizeof( V_2 -> V_10 . V_20 ) ) ;
F_12 ( V_2 -> V_10 . V_20 , L_5 , sizeof( V_2 -> V_10 . V_20 ) ) ;
V_11 -> V_22 = V_2 -> V_10 . V_19 ;
V_11 -> V_23 = V_2 -> V_10 . V_20 ;
V_11 -> V_11 . V_24 = V_2 -> V_25 ;
#if 0
dev->input_id.bustype = BUS_USB;
dev->input_id.version = 1;
dev->input_id.vendor = le16_to_cpu(dev->udev->descriptor.idVendor);
dev->input_id.product = le16_to_cpu(dev->udev->descriptor.idProduct);
#endif
V_11 -> V_26 = V_2 ;
V_11 -> V_27 = V_28 ;
F_13 ( V_11 , V_29 ) ;
V_11 -> V_30 = F_10 ( V_13 ) -> V_31 ;
V_11 -> V_32 = V_33 ;
F_7 ( L_6 , V_11 -> V_22 ) ;
V_12 = F_14 ( V_11 ) ;
if ( V_12 < 0 ) {
F_9 ( L_7 ) ;
F_15 ( V_11 ) ;
return V_12 ;
}
V_2 -> V_10 . V_11 = V_11 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_11 )
F_17 ( V_2 -> V_10 . V_11 ) ;
F_7 ( L_8 ) ;
}
