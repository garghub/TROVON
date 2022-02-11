struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
return NULL ;
if ( V_2 -> V_5 && V_2 -> V_5 -> V_6 )
V_2 -> V_5 -> V_6 ( V_2 ) ;
if ( V_2 -> V_7 )
F_3 ( V_2 -> V_7 ) ;
memcpy ( V_3 , V_2 , sizeof( * V_2 ) ) ;
V_3 -> V_8 = NULL ;
V_3 -> V_9 = NULL ;
V_3 -> V_10 = NULL ;
return V_3 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_5 && V_2 -> V_5 -> V_11 )
V_2 -> V_5 -> V_11 ( V_2 ) ;
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_7 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( unsigned long V_12 , unsigned long V_13 ,
struct V_1 * * V_14 , T_1 * V_15 )
{
struct V_16 * V_17 = V_18 -> V_17 ;
struct V_1 * V_2 ;
unsigned long V_19 , V_20 , V_21 ;
unsigned long V_22 , V_23 ;
T_1 V_24 = 0 ;
V_20 = V_12 ;
V_19 = V_20 & ~ V_25 ;
V_21 = V_20 + V_13 ;
V_2 = F_8 ( V_17 , V_20 ) ;
if ( V_2 == NULL || V_2 -> V_26 < V_21 )
return - V_27 ;
for ( V_23 = 0 ; V_20 < V_21 ; V_20 += V_28 ) {
int V_29 = F_9 ( V_2 , V_20 , & V_22 ) ;
if ( V_29 )
return V_29 ;
if ( V_23 == 0 )
V_24 = V_22 << V_30 ;
else if ( V_22 != V_23 + 1 )
return - V_27 ;
V_23 = V_22 ;
}
* V_14 = F_1 ( V_2 ) ;
if ( * V_14 == NULL )
return - V_31 ;
* V_15 = V_24 + V_19 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , unsigned long V_32 ,
unsigned long V_13 ,
const struct V_33 * V_5 ,
void * V_34 )
{
int V_29 ;
V_13 = F_11 (unsigned long, vma->vm_end - vma->vm_start, size) ;
V_2 -> V_35 = F_12 ( V_2 -> V_35 ) ;
V_29 = F_13 ( V_2 , V_2 -> V_36 , V_32 >> V_30 ,
V_13 , V_2 -> V_35 ) ;
if ( V_29 ) {
F_14 ( V_37 L_1 , V_29 ) ;
return V_29 ;
}
V_2 -> V_38 |= V_39 | V_40 ;
V_2 -> V_41 = V_34 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_5 -> V_6 ( V_2 ) ;
F_15 ( L_2 ,
V_42 , V_32 , V_2 -> V_36 , V_13 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_41 ;
F_15 ( L_3 ,
V_42 , V_44 , F_17 ( V_44 -> V_45 ) , V_2 -> V_36 ,
V_2 -> V_26 ) ;
F_18 ( V_44 -> V_45 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_41 ;
F_15 ( L_3 ,
V_42 , V_44 , F_17 ( V_44 -> V_45 ) , V_2 -> V_36 ,
V_2 -> V_26 ) ;
V_44 -> V_46 ( V_44 -> V_47 ) ;
}
