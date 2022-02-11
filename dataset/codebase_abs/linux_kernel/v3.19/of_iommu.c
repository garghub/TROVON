int F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 ,
unsigned long * V_5 , T_1 * V_6 , T_2 * V_7 )
{
const T_3 * V_8 , * V_9 ;
int V_10 , V_11 = 0 ;
char V_12 [ V_13 ] , V_14 [ V_13 ] , V_15 [ V_13 ] ;
if ( ! V_2 || ! V_6 || ! V_7 )
return - V_16 ;
if ( ! V_3 )
V_3 = L_1 ;
snprintf ( V_12 , sizeof( V_12 ) , L_2 , V_3 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_3 , V_3 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_4 , V_3 ) ;
V_8 = F_2 ( V_2 , V_12 , & V_10 ) ;
if ( ! V_8 )
return - V_17 ;
V_9 = V_8 + V_10 / sizeof( * V_8 ) ;
while ( V_8 < V_9 ) {
T_4 V_18 ;
const void * V_19 ;
if ( V_5 )
* V_5 = F_3 ( V_8 ++ ) ;
V_19 = F_2 ( V_2 , V_14 , NULL ) ;
if ( ! V_19 )
V_19 = F_2 ( V_2 , L_5 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_4 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_6 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
V_19 = F_2 ( V_2 , V_15 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_6 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_7 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
if ( V_11 ++ == V_4 )
break;
}
return 0 ;
}
void F_7 ( struct V_1 * V_20 , struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( sizeof( * V_24 ) , V_25 ) ;
if ( F_9 ( ! V_24 ) )
return;
F_10 ( & V_24 -> V_26 ) ;
V_24 -> V_20 = V_20 ;
V_24 -> V_22 = V_22 ;
F_11 ( & V_27 ) ;
F_12 ( & V_24 -> V_26 , & V_28 ) ;
F_13 ( & V_27 ) ;
}
struct V_21 * F_14 ( struct V_1 * V_20 )
{
struct V_23 * V_29 ;
struct V_21 * V_22 = NULL ;
F_11 ( & V_27 ) ;
F_15 (node, &of_iommu_list, list)
if ( V_29 -> V_20 == V_20 ) {
V_22 = V_29 -> V_22 ;
break;
}
F_13 ( & V_27 ) ;
return V_22 ;
}
struct V_21 * F_16 ( struct V_30 * V_31 )
{
struct V_32 V_33 ;
struct V_1 * V_20 ;
struct V_21 * V_22 = NULL ;
int V_34 = 0 ;
while ( ! F_17 ( V_31 -> V_35 , L_6 ,
L_7 , V_34 ,
& V_33 ) ) {
V_20 = V_33 . V_20 ;
V_22 = F_14 ( V_20 ) ;
if ( ! V_22 || ! V_22 -> V_36 || V_22 -> V_36 ( V_31 , & V_33 ) )
goto V_37;
F_18 ( V_20 ) ;
V_34 ++ ;
}
return V_22 ;
V_37:
F_18 ( V_20 ) ;
return NULL ;
}
void T_5 F_19 ( void )
{
struct V_1 * V_20 ;
const struct V_38 * V_39 , * V_40 = & V_41 ;
F_20 (np, matches, &match) {
const T_6 V_42 = V_39 -> V_43 ;
if ( V_42 ( V_20 ) )
F_21 ( L_8 ,
F_22 ( V_20 ) ) ;
}
}
