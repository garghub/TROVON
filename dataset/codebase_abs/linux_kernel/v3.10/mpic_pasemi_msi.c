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
static int F_8 ( struct V_4 * V_5 , int V_6 , int type )
{
if ( type == V_7 )
F_2 ( L_3 ) ;
return 0 ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
F_2 ( L_4 , V_5 ) ;
F_10 (entry, &pdev->msi_list, list) {
if ( V_9 -> V_3 == V_10 )
continue;
F_11 ( V_9 -> V_3 , NULL ) ;
F_12 ( & V_11 -> V_12 ,
F_13 ( V_9 -> V_3 ) , V_13 ) ;
F_14 ( V_9 -> V_3 ) ;
}
return;
}
static int F_15 ( struct V_4 * V_5 , int V_6 , int type )
{
unsigned int V_14 ;
struct V_8 * V_9 ;
struct V_15 V_16 ;
int V_17 ;
F_2 ( L_5 ,
V_5 , V_6 , type ) ;
V_16 . V_18 = 0 ;
V_16 . V_19 = V_20 ;
F_10 (entry, &pdev->msi_list, list) {
V_17 = F_16 ( & V_11 -> V_12 ,
V_13 ) ;
if ( V_17 < 0 ) {
F_2 ( L_6 ) ;
return V_17 ;
}
V_14 = F_17 ( V_11 -> V_21 , V_17 ) ;
if ( V_14 == V_10 ) {
F_2 ( L_7 ,
V_17 ) ;
F_12 ( & V_11 -> V_12 , V_17 ,
V_13 ) ;
return - V_22 ;
}
F_18 ( V_14 , 0 ) ;
F_11 ( V_14 , V_9 ) ;
F_19 ( V_14 , & V_23 ) ;
F_20 ( V_14 , V_24 ) ;
F_2 ( L_8 \
L_9 , V_14 , V_17 , V_16 . V_19 ) ;
V_16 . V_2 = V_17 - 0x200 ;
F_21 ( V_14 , & V_16 ) ;
}
return 0 ;
}
int F_22 ( struct V_25 * V_25 )
{
int V_26 ;
if ( ! V_25 -> V_21 -> V_27 ||
! F_23 ( V_25 -> V_21 -> V_27 ,
L_10 ) )
return - V_28 ;
V_26 = F_24 ( V_25 ) ;
if ( V_26 ) {
F_2 ( L_11 ) ;
return V_26 ;
}
F_2 ( L_12 ) ;
V_11 = V_25 ;
F_25 ( V_29 . V_30 ) ;
V_29 . V_30 = F_15 ;
V_29 . V_31 = F_9 ;
V_29 . V_32 = F_8 ;
return 0 ;
}
