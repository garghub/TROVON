static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static T_1 F_7 ( struct V_3 * V_4 , unsigned int V_5 )
{
T_2 V_6 ;
T_3 V_7 ;
T_1 V_8 ;
F_8 ( V_4 , V_5 + V_9 , & V_6 ) ;
if ( V_6 & V_10 )
return V_11 ;
F_9 ( V_4 , V_5 + V_12 , & V_7 ) ;
V_8 = V_7 & V_13 ;
F_9 ( V_4 , V_5 + V_14 , & V_7 ) ;
V_8 = V_8 | ( ( T_1 ) V_7 << 32 ) ;
return V_8 ;
}
static T_1 F_10 ( struct V_3 * V_4 , unsigned int V_15 )
{
struct V_16 * V_17 ;
unsigned int V_5 ;
for ( V_17 = V_4 -> V_17 ; V_17 && V_17 -> V_18 ; V_17 = V_17 -> V_19 ) {
V_5 = F_11 ( V_17 -> V_18 , V_20 ) ;
if ( V_5 )
return F_7 ( V_17 -> V_18 , V_5 ) ;
}
return 0 ;
}
static T_1 F_12 ( struct V_3 * V_4 , unsigned int V_15 )
{
struct V_21 * V_22 = F_13 ( V_4 -> V_17 ) ;
if ( F_14 ( V_22 -> V_23 , L_1 ) ||
F_14 ( V_22 -> V_23 , L_2 ) )
return 0xf8004000 | ( V_15 << 4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , int V_24 , int type )
{
if ( type == V_25 )
F_16 ( L_3 ) ;
if ( F_10 ( V_4 , 0 ) == 0 &&
F_12 ( V_4 , 0 ) == 0 ) {
F_16 ( L_4 ,
F_17 ( V_4 ) ) ;
return - V_26 ;
}
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_27 * V_28 ;
F_19 (entry, &pdev->msi_list, list) {
if ( V_28 -> V_29 == V_30 )
continue;
F_20 ( V_28 -> V_29 , NULL ) ;
F_21 ( & V_31 -> V_32 ,
F_22 ( V_28 -> V_29 ) , 1 ) ;
F_23 ( V_28 -> V_29 ) ;
}
return;
}
static int F_24 ( struct V_3 * V_4 , int V_24 , int type )
{
unsigned int V_33 ;
struct V_27 * V_28 ;
struct V_34 V_35 ;
T_1 V_8 ;
int V_15 ;
F_19 (entry, &pdev->msi_list, list) {
V_15 = F_25 ( & V_31 -> V_32 , 1 ) ;
if ( V_15 < 0 ) {
F_16 ( L_5 ) ;
return V_15 ;
}
V_8 = F_10 ( V_4 , V_15 ) ;
if ( V_8 == 0 )
V_8 = F_12 ( V_4 , V_15 ) ;
V_35 . V_36 = V_8 & 0xFFFFFFFF ;
V_35 . V_37 = V_8 >> 32 ;
V_33 = F_26 ( V_31 -> V_38 , V_15 ) ;
if ( V_33 == V_30 ) {
F_16 ( L_6 , V_15 ) ;
F_21 ( & V_31 -> V_32 , V_15 , 1 ) ;
return - V_39 ;
}
F_20 ( V_33 , V_28 ) ;
F_27 ( V_33 , & V_40 ) ;
F_28 ( V_33 , V_41 ) ;
F_16 ( L_7 ,
V_33 , V_15 , ( unsigned long ) V_8 ) ;
F_29 ( L_7 ,
V_33 , V_15 , ( unsigned long ) V_8 ) ;
V_35 . V_2 = V_15 ;
F_30 ( V_33 , & V_35 ) ;
V_15 ++ ;
}
return 0 ;
}
int F_31 ( struct V_42 * V_42 )
{
int V_43 ;
V_43 = F_32 ( V_42 ) ;
if ( V_43 ) {
F_16 ( L_8 ) ;
return V_43 ;
}
F_16 ( L_9 ) ;
F_33 ( V_31 ) ;
V_31 = V_42 ;
F_34 ( V_44 . V_45 ) ;
V_44 . V_45 = F_24 ;
V_44 . V_46 = F_18 ;
V_44 . V_47 = F_15 ;
return 0 ;
}
