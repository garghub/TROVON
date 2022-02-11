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
void F_7 ( struct V_1 * V_20 , const struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( sizeof( * V_24 ) , V_25 ) ;
if ( F_9 ( ! V_24 ) )
return;
F_10 ( V_20 ) ;
F_11 ( & V_24 -> V_26 ) ;
V_24 -> V_20 = V_20 ;
V_24 -> V_22 = V_22 ;
F_12 ( & V_27 ) ;
F_13 ( & V_24 -> V_26 , & V_28 ) ;
F_14 ( & V_27 ) ;
}
const struct V_21 * F_15 ( struct V_1 * V_20 )
{
struct V_23 * V_29 ;
const struct V_21 * V_22 = NULL ;
F_12 ( & V_27 ) ;
F_16 (node, &of_iommu_list, list)
if ( V_29 -> V_20 == V_20 ) {
V_22 = V_29 -> V_22 ;
break;
}
F_14 ( & V_27 ) ;
return V_22 ;
}
static int F_17 ( struct V_30 * V_31 , T_5 V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
V_35 -> args [ 0 ] = V_32 ;
return V_35 -> V_20 == V_31 -> V_36 -> V_37 . V_38 ;
}
static const struct V_21
* F_18 ( struct V_30 * V_31 , struct V_1 * V_39 )
{
const struct V_21 * V_22 ;
struct V_34 V_35 ;
V_35 . V_40 = 1 ;
V_35 . V_20 = V_39 ;
F_19 ( V_31 , F_17 , & V_35 ) ;
V_35 . V_20 = NULL ;
if ( F_20 ( V_39 , V_35 . args [ 0 ] , L_6 ,
L_7 , & V_35 . V_20 , V_35 . args ) )
return NULL ;
V_22 = F_15 ( V_35 . V_20 ) ;
if ( ! V_22 || ! V_22 -> V_41 ||
F_21 ( & V_31 -> V_37 , & V_35 . V_20 -> V_42 , V_22 ) ||
V_22 -> V_41 ( & V_31 -> V_37 , & V_35 ) )
V_22 = NULL ;
F_22 ( V_35 . V_20 ) ;
return V_22 ;
}
const struct V_21 * F_23 ( struct V_43 * V_37 ,
struct V_1 * V_44 )
{
struct V_34 V_35 ;
struct V_1 * V_20 ;
const struct V_21 * V_22 = NULL ;
int V_45 = 0 ;
if ( F_24 ( V_37 ) )
return F_18 ( F_25 ( V_37 ) , V_44 ) ;
while ( ! F_26 ( V_44 , L_8 ,
L_9 , V_45 ,
& V_35 ) ) {
V_20 = V_35 . V_20 ;
V_22 = F_15 ( V_20 ) ;
if ( ! V_22 || ! V_22 -> V_41 ||
F_21 ( V_37 , & V_20 -> V_42 , V_22 ) ||
V_22 -> V_41 ( V_37 , & V_35 ) )
goto V_46;
F_22 ( V_20 ) ;
V_45 ++ ;
}
return V_22 ;
V_46:
F_22 ( V_20 ) ;
return NULL ;
}
static int T_6 F_27 ( void )
{
struct V_1 * V_20 ;
const struct V_47 * V_48 , * V_49 = & V_50 ;
F_28 (np, matches, &match) {
const T_7 V_51 = V_48 -> V_33 ;
if ( V_51 ( V_20 ) )
F_29 ( L_10 ,
F_30 ( V_20 ) ) ;
}
return 0 ;
}
