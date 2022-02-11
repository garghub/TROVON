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
F_6 (window, resources)
if ( V_13 -> V_17 -> V_18 & V_19 ) {
V_14 = true ;
break;
}
if ( ! V_14 )
F_7 ( V_9 , & V_3 -> V_4 ) ;
F_2 (root_res, &info->resources, list)
F_7 ( V_9 , & V_11 -> V_17 ) ;
return;
V_15:
F_5 ( V_16 L_2 , V_2 ) ;
F_7 ( V_9 , & V_20 ) ;
F_7 ( V_9 , & V_21 ) ;
}
struct V_1 T_1 * F_8 ( int V_22 , int V_23 ,
int V_7 , int V_24 )
{
struct V_1 * V_3 ;
V_3 = F_9 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
return V_3 ;
sprintf ( V_3 -> V_26 , L_3 , V_22 ) ;
F_10 ( & V_3 -> V_9 ) ;
V_3 -> V_4 . V_26 = V_3 -> V_26 ;
V_3 -> V_4 . V_5 = V_22 ;
V_3 -> V_4 . V_27 = V_23 ;
V_3 -> V_4 . V_18 = V_19 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_24 = V_24 ;
F_11 ( & V_3 -> V_28 , & V_29 ) ;
return V_3 ;
}
void F_12 ( struct V_1 * V_3 , T_2 V_5 ,
T_2 V_27 , unsigned long V_18 , int V_30 )
{
struct V_31 * V_17 ;
struct V_10 * V_11 ;
if ( V_5 > V_27 )
return;
if ( V_5 == V_32 )
return;
if ( ! V_30 )
goto V_33;
F_2 (root_res, &info->resources, list) {
T_2 V_34 , V_35 ;
T_2 V_36 , V_37 ;
V_17 = & V_11 -> V_17 ;
if ( V_17 -> V_18 != V_18 )
continue;
V_36 = F_13 ( V_17 -> V_5 , V_5 ) ;
V_37 = F_14 ( V_17 -> V_27 , V_27 ) ;
if ( V_36 > V_37 + 1 )
continue;
V_34 = F_14 ( V_17 -> V_5 , V_5 ) ;
V_35 = F_13 ( V_17 -> V_27 , V_27 ) ;
V_17 -> V_5 = V_34 ;
V_17 -> V_27 = V_35 ;
return;
}
V_33:
V_11 = F_9 ( sizeof( * V_11 ) , V_25 ) ;
if ( ! V_11 )
return;
V_17 = & V_11 -> V_17 ;
V_17 -> V_26 = V_3 -> V_26 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_5 = V_5 ;
V_17 -> V_27 = V_27 ;
F_11 ( & V_11 -> V_28 , & V_3 -> V_9 ) ;
}
