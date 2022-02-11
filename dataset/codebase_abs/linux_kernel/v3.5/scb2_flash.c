static int T_1
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_9 -> V_11 -> V_12 != V_13 ) {
F_2 (KERN_ERR MODNAME L_1 ,
cfi->cfiq->InterfaceDesc) ;
return - 1 ;
}
V_2 -> V_14 = V_6 -> V_14 ;
V_2 -> V_15 /= 2 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_16 ; V_3 ++ ) {
struct V_17 * V_18 = & V_2 -> V_19 [ V_3 ] ;
V_18 -> V_15 /= 2 ;
}
for ( V_3 = 0 ; ! V_4 && V_3 < V_2 -> V_16 ; V_3 ++ ) {
struct V_17 * V_18 = & V_2 -> V_19 [ V_3 ] ;
if ( V_18 -> V_20 * V_18 -> V_15 > V_2 -> V_14 ) {
V_18 -> V_20 = ( ( unsigned long ) V_2 -> V_14 /
V_18 -> V_15 ) ;
V_4 = 1 ;
} else {
V_18 -> V_20 = 0 ;
}
V_18 -> V_21 = 0 ;
}
return 0 ;
}
static int T_1
F_3 ( struct V_22 * V_23 , const struct V_24 * V_25 )
{
T_2 V_26 ;
F_4 ( V_23 , V_27 , & V_26 ) ;
F_5 ( V_23 , V_27 , V_26 | V_28 ) ;
if ( ! F_6 ( V_29 , V_30 , V_31 . V_32 ) ) {
F_2 (KERN_WARNING MODNAME
L_2 ) ;
V_33 = 1 ;
}
V_34 = F_7 ( V_29 , V_30 ) ;
if ( ! V_34 ) {
F_2 (KERN_ERR MODNAME L_3 ) ;
if ( ! V_33 )
F_8 ( V_29 , V_30 ) ;
return - V_35 ;
}
V_31 . V_36 = V_29 ;
V_31 . V_37 = V_34 ;
V_31 . V_14 = V_30 ;
F_9 ( & V_31 ) ;
V_38 = F_10 ( L_4 , & V_31 ) ;
if ( ! V_38 ) {
F_2 (KERN_ERR MODNAME L_5 ) ;
F_11 ( V_34 ) ;
if ( ! V_33 )
F_8 ( V_29 , V_30 ) ;
return - V_39 ;
}
V_38 -> V_40 = V_41 ;
if ( F_1 ( V_38 ) < 0 ) {
F_12 ( V_38 ) ;
F_13 ( V_38 ) ;
F_11 ( V_34 ) ;
if ( ! V_33 )
F_8 ( V_29 , V_30 ) ;
return - V_39 ;
}
F_2 (KERN_NOTICE MODNAME L_6 ,
(unsigned long long)scb2_mtd->size,
(unsigned long long)(SCB2_WINDOW - scb2_mtd->size)) ;
F_14 ( V_38 , NULL , 0 ) ;
return 0 ;
}
static void T_3
F_15 ( struct V_22 * V_23 )
{
if ( ! V_38 )
return;
F_16 ( V_38 , 0 , V_38 -> V_14 ) ;
F_12 ( V_38 ) ;
F_13 ( V_38 ) ;
F_11 ( V_34 ) ;
V_34 = NULL ;
if ( ! V_33 )
F_8 ( V_29 , V_30 ) ;
F_17 ( V_23 , NULL ) ;
}
