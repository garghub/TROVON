static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
if ( F_2 ( & V_4 ) )
return NULL ;
F_3 (info, &pci_root_infos, list)
if ( V_3 -> V_5 == V_2 )
return V_3 ;
return NULL ;
}
void F_4 ( int V_2 , struct V_6 * V_7 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_8 * V_9 ;
if ( ! V_3 )
goto V_10;
F_5 ( V_11 L_1 ,
V_2 ) ;
F_3 (root_res, &info->resources, list) {
struct V_12 * V_13 ;
struct V_12 * V_14 ;
V_13 = & V_9 -> V_13 ;
F_6 ( V_7 , V_13 ) ;
if ( V_13 -> V_15 & V_16 )
V_14 = & V_17 ;
else
V_14 = & V_18 ;
F_7 ( V_14 , V_13 ) ;
}
return;
V_10:
F_5 ( V_11 L_2 , V_2 ) ;
F_6 ( V_7 , & V_17 ) ;
F_6 ( V_7 , & V_18 ) ;
}
struct V_1 T_1 * F_8 ( int V_5 , int V_19 ,
int V_20 , int V_21 )
{
struct V_1 * V_3 ;
V_3 = F_9 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return V_3 ;
F_10 ( & V_3 -> V_7 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_20 = V_20 ;
V_3 -> V_21 = V_21 ;
F_11 ( & V_3 -> V_23 , & V_4 ) ;
return V_3 ;
}
void T_2 F_12 ( struct V_1 * V_3 , T_3 V_24 ,
T_3 V_25 , unsigned long V_15 , int V_26 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 ;
if ( V_24 > V_25 )
return;
if ( V_24 == V_27 )
return;
if ( ! V_26 )
goto V_28;
F_3 (root_res, &info->resources, list) {
T_3 V_29 , V_30 ;
T_3 V_31 , V_32 ;
V_13 = & V_9 -> V_13 ;
if ( V_13 -> V_15 != V_15 )
continue;
V_31 = F_13 ( V_13 -> V_24 , V_24 ) ;
V_32 = F_14 ( V_13 -> V_25 , V_25 ) ;
if ( V_31 > V_32 + 1 )
continue;
V_29 = F_14 ( V_13 -> V_24 , V_24 ) ;
V_30 = F_13 ( V_13 -> V_25 , V_25 ) ;
V_13 -> V_24 = V_29 ;
V_13 -> V_25 = V_30 ;
return;
}
V_28:
V_9 = F_9 ( sizeof( * V_9 ) , V_22 ) ;
if ( ! V_9 )
return;
V_13 = & V_9 -> V_13 ;
V_13 -> V_33 = V_3 -> V_33 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_25 = V_25 ;
F_11 ( & V_9 -> V_23 , & V_3 -> V_7 ) ;
}
