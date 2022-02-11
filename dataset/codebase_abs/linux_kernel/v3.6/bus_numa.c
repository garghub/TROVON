static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
if ( F_2 ( & V_4 ) )
return NULL ;
F_3 (info, &pci_root_infos, list)
if ( V_3 -> V_5 . V_6 == V_2 )
return V_3 ;
return NULL ;
}
void F_4 ( int V_2 , struct V_7 * V_8 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
bool V_13 = false ;
if ( ! V_3 )
goto V_14;
F_5 ( V_15 L_1 ,
V_2 ) ;
F_3 (window, resources, list)
if ( V_12 -> V_16 -> V_17 & V_18 ) {
V_13 = true ;
break;
}
if ( ! V_13 )
F_6 ( V_8 , & V_3 -> V_5 ) ;
F_3 (root_res, &info->resources, list) {
struct V_19 * V_16 ;
struct V_19 * V_20 ;
V_16 = & V_10 -> V_16 ;
F_6 ( V_8 , V_16 ) ;
if ( V_16 -> V_17 & V_21 )
V_20 = & V_22 ;
else
V_20 = & V_23 ;
F_7 ( V_20 , V_16 ) ;
}
return;
V_14:
F_5 ( V_15 L_2 , V_2 ) ;
F_6 ( V_8 , & V_22 ) ;
F_6 ( V_8 , & V_23 ) ;
}
struct V_1 T_1 * F_8 ( int V_24 , int V_25 ,
int V_26 , int V_27 )
{
struct V_1 * V_3 ;
V_3 = F_9 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
return V_3 ;
sprintf ( V_3 -> V_29 , L_3 , V_24 ) ;
F_10 ( & V_3 -> V_8 ) ;
V_3 -> V_5 . V_29 = V_3 -> V_29 ;
V_3 -> V_5 . V_6 = V_24 ;
V_3 -> V_5 . V_30 = V_25 ;
V_3 -> V_5 . V_17 = V_18 ;
V_3 -> V_26 = V_26 ;
V_3 -> V_27 = V_27 ;
F_11 ( & V_3 -> V_31 , & V_4 ) ;
return V_3 ;
}
void T_2 F_12 ( struct V_1 * V_3 , T_3 V_6 ,
T_3 V_30 , unsigned long V_17 , int V_32 )
{
struct V_19 * V_16 ;
struct V_9 * V_10 ;
if ( V_6 > V_30 )
return;
if ( V_6 == V_33 )
return;
if ( ! V_32 )
goto V_34;
F_3 (root_res, &info->resources, list) {
T_3 V_35 , V_36 ;
T_3 V_37 , V_38 ;
V_16 = & V_10 -> V_16 ;
if ( V_16 -> V_17 != V_17 )
continue;
V_37 = F_13 ( V_16 -> V_6 , V_6 ) ;
V_38 = F_14 ( V_16 -> V_30 , V_30 ) ;
if ( V_37 > V_38 + 1 )
continue;
V_35 = F_14 ( V_16 -> V_6 , V_6 ) ;
V_36 = F_13 ( V_16 -> V_30 , V_30 ) ;
V_16 -> V_6 = V_35 ;
V_16 -> V_30 = V_36 ;
return;
}
V_34:
V_10 = F_9 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 )
return;
V_16 = & V_10 -> V_16 ;
V_16 -> V_29 = V_3 -> V_29 ;
V_16 -> V_17 = V_17 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_30 = V_30 ;
F_11 ( & V_10 -> V_31 , & V_3 -> V_8 ) ;
}
