static int T_1 F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 ( V_4 L_1 ) ;
V_5 . V_6 = V_7 ;
F_3 ( V_8 | V_9 ) ;
F_4 (hose, tmp, &hose_list, list_node) {
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_10 ) ;
}
F_7 () ;
F_2 ( V_11 L_2 ) ;
return 0 ;
}
int F_8 ( struct V_12 * V_10 )
{
struct V_1 * V_2 ;
F_9 ( V_10 == NULL ) ;
if ( V_10 -> V_13 ) {
#ifdef F_10
struct V_14 * V_15 = V_10 -> V_14 [ 0 ] ;
#endif
F_11 ( L_3 ,
F_12 ( V_10 -> V_13 ) ) ;
#ifdef F_10
F_13 ( & V_16 , V_15 -> V_17 + V_18 ,
V_15 -> V_19 + V_18 + 1 ) ;
#endif
return 0 ;
}
V_2 = F_14 ( V_10 ) ;
if ( V_2 -> V_20 == NULL )
return 0 ;
F_11 ( L_4 , V_2 -> V_21 -> V_22 ) ;
F_11 ( L_5 , V_2 -> V_20 ) ;
F_15 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
V_25 = F_17 ( V_2 -> V_28 , V_29 ) ;
V_26 = F_18 ( V_2 -> V_30 , V_29 ) ;
V_2 -> V_20 = NULL ;
if ( V_2 -> V_30 == 0 || V_2 -> V_28 == 0 )
return 0 ;
V_24 = F_19 ( V_26 , 0 , V_31 , V_32 ) ;
if ( V_24 == NULL )
return - V_33 ;
V_2 -> V_20 = V_24 -> V_34 ;
V_2 -> V_35 = ( void V_36 * ) ( V_24 -> V_34 +
V_2 -> V_28 - V_25 ) ;
F_11 ( L_6 , V_2 -> V_21 -> V_22 ) ;
F_11 ( L_7 ,
V_2 -> V_28 , V_2 -> V_35 , V_2 -> V_20 ) ;
F_11 ( L_8 ,
V_2 -> V_30 , V_26 ) ;
if ( F_20 ( V_25 , V_24 -> V_34 , V_26 ,
F_21 ( F_22 ( F_23 ( 0 ) ) ) ) == NULL )
return - V_33 ;
V_27 = F_24 ( V_2 ) ;
V_2 -> V_37 . V_17 += V_27 ;
V_2 -> V_37 . V_19 += V_27 ;
F_11 ( L_9 , & V_2 -> V_37 ) ;
return 0 ;
}
int F_25 ( struct V_12 * V_10 )
{
F_9 ( V_10 == NULL ) ;
if ( V_10 -> V_13 ) {
F_11 ( L_10 ,
F_12 ( V_10 -> V_13 ) ) ;
F_11 ( L_11 ,
V_10 -> V_14 [ 0 ] -> V_17 + V_18 ,
V_10 -> V_14 [ 0 ] -> V_19 + V_18 ) ;
return 0 ;
}
return F_16 ( F_14 ( V_10 ) ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
}
long F_27 ( long V_38 , unsigned long V_39 ,
unsigned long V_40 )
{
struct V_1 * V_2 ;
struct V_12 * V_41 , * V_10 = NULL ;
struct V_42 * V_43 ;
if ( V_39 == 0 && F_28 ( L_12 ) ) {
struct V_42 * V_44 ;
V_44 = F_29 ( NULL , NULL , L_13 ) ;
if ( V_44 )
V_39 = 0xf0 ;
F_30 ( V_44 ) ;
}
F_31 (tmp_bus, &pci_root_buses, node) {
if ( V_39 >= V_41 -> V_45 &&
V_39 <= V_41 -> V_46 . V_19 ) {
V_10 = V_41 ;
break;
}
}
if ( V_10 == NULL || V_10 -> V_47 . V_48 == NULL )
return - V_49 ;
V_43 = V_10 -> V_47 . V_48 ;
V_2 = F_32 ( V_43 ) -> V_50 ;
switch ( V_38 ) {
case V_51 :
return ( long ) V_2 -> V_52 ;
case V_53 :
return ( long ) V_2 -> V_54 [ 0 ] ;
case V_55 :
return ( long ) V_2 -> V_28 ;
case V_56 :
return ( long ) V_57 ;
case V_58 :
return - V_59 ;
}
return - V_60 ;
}
int F_33 ( struct V_12 * V_10 )
{
struct V_1 * V_50 = F_14 ( V_10 ) ;
return V_50 -> V_61 ;
}
