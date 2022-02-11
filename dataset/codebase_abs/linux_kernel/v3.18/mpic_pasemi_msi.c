static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( L_2 , V_2 -> V_3 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_2 ( L_3 , V_5 ) ;
F_9 (entry, &pdev->msi_list, list) {
if ( V_7 -> V_3 == V_8 )
continue;
F_10 ( V_7 -> V_3 , NULL ) ;
F_11 ( & V_9 -> V_10 ,
F_12 ( V_7 -> V_3 ) , V_11 ) ;
F_13 ( V_7 -> V_3 ) ;
}
return;
}
static int F_14 ( struct V_4 * V_5 , int V_12 , int type )
{
unsigned int V_13 ;
struct V_6 * V_7 ;
struct V_14 V_15 ;
int V_16 ;
if ( type == V_17 )
F_2 ( L_4 ) ;
F_2 ( L_5 ,
V_5 , V_12 , type ) ;
V_15 . V_18 = 0 ;
V_15 . V_19 = V_20 ;
F_9 (entry, &pdev->msi_list, list) {
V_16 = F_15 ( & V_9 -> V_10 ,
V_11 ) ;
if ( V_16 < 0 ) {
F_2 ( L_6 ) ;
return V_16 ;
}
V_13 = F_16 ( V_9 -> V_21 , V_16 ) ;
if ( V_13 == V_8 ) {
F_2 ( L_7 ,
V_16 ) ;
F_11 ( & V_9 -> V_10 , V_16 ,
V_11 ) ;
return - V_22 ;
}
F_17 ( V_13 , 0 ) ;
F_10 ( V_13 , V_7 ) ;
F_18 ( V_13 , & V_23 ) ;
F_19 ( V_13 , V_24 ) ;
F_2 ( L_8 \
L_9 , V_13 , V_16 , V_15 . V_19 ) ;
V_15 . V_2 = V_16 - 0x200 ;
F_20 ( V_13 , & V_15 ) ;
}
return 0 ;
}
int F_21 ( struct V_25 * V_25 )
{
int V_26 ;
if ( ! V_25 -> V_21 -> V_27 ||
! F_22 ( V_25 -> V_21 -> V_27 ,
L_10 ) )
return - V_28 ;
V_26 = F_23 ( V_25 ) ;
if ( V_26 ) {
F_2 ( L_11 ) ;
return V_26 ;
}
F_2 ( L_12 ) ;
V_9 = V_25 ;
F_24 ( V_29 . V_30 ) ;
V_29 . V_30 = F_14 ;
V_29 . V_31 = F_8 ;
return 0 ;
}
