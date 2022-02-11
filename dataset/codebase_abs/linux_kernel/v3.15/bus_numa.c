static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
F_2 (info, &pci_root_infos, list)
if ( V_3 -> V_4 . V_5 == V_2 )
return V_3 ;
return NULL ;
}
int F_3 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
if ( ! V_3 )
return V_6 ;
return V_3 -> V_7 ;
}
void F_4 ( int V_2 , struct V_8 * V_9 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
bool V_14 = false ;
if ( ! V_3 )
goto V_15;
F_5 ( V_16 L_1 ,
V_2 ) ;
F_2 (window, resources, list)
if ( V_13 -> V_17 -> V_18 & V_19 ) {
V_14 = true ;
break;
}
if ( ! V_14 )
F_6 ( V_9 , & V_3 -> V_4 ) ;
F_2 (root_res, &info->resources, list) {
struct V_20 * V_17 ;
struct V_20 * V_21 ;
V_17 = & V_11 -> V_17 ;
F_6 ( V_9 , V_17 ) ;
if ( V_17 -> V_18 & V_22 )
V_21 = & V_23 ;
else
V_21 = & V_24 ;
F_7 ( V_21 , V_17 ) ;
}
return;
V_15:
F_5 ( V_16 L_2 , V_2 ) ;
F_6 ( V_9 , & V_23 ) ;
F_6 ( V_9 , & V_24 ) ;
}
struct V_1 T_1 * F_8 ( int V_25 , int V_26 ,
int V_7 , int V_27 )
{
struct V_1 * V_3 ;
V_3 = F_9 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
return V_3 ;
sprintf ( V_3 -> V_29 , L_3 , V_25 ) ;
F_10 ( & V_3 -> V_9 ) ;
V_3 -> V_4 . V_29 = V_3 -> V_29 ;
V_3 -> V_4 . V_5 = V_25 ;
V_3 -> V_4 . V_30 = V_26 ;
V_3 -> V_4 . V_18 = V_19 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_27 = V_27 ;
F_11 ( & V_3 -> V_31 , & V_32 ) ;
return V_3 ;
}
void F_12 ( struct V_1 * V_3 , T_2 V_5 ,
T_2 V_30 , unsigned long V_18 , int V_33 )
{
struct V_20 * V_17 ;
struct V_10 * V_11 ;
if ( V_5 > V_30 )
return;
if ( V_5 == V_34 )
return;
if ( ! V_33 )
goto V_35;
F_2 (root_res, &info->resources, list) {
T_2 V_36 , V_37 ;
T_2 V_38 , V_39 ;
V_17 = & V_11 -> V_17 ;
if ( V_17 -> V_18 != V_18 )
continue;
V_38 = F_13 ( V_17 -> V_5 , V_5 ) ;
V_39 = F_14 ( V_17 -> V_30 , V_30 ) ;
if ( V_38 > V_39 + 1 )
continue;
V_36 = F_14 ( V_17 -> V_5 , V_5 ) ;
V_37 = F_13 ( V_17 -> V_30 , V_30 ) ;
V_17 -> V_5 = V_36 ;
V_17 -> V_30 = V_37 ;
return;
}
V_35:
V_11 = F_9 ( sizeof( * V_11 ) , V_28 ) ;
if ( ! V_11 )
return;
V_17 = & V_11 -> V_17 ;
V_17 -> V_29 = V_3 -> V_29 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_5 = V_5 ;
V_17 -> V_30 = V_30 ;
F_11 ( & V_11 -> V_31 , & V_3 -> V_9 ) ;
}
