int F_1 ( T_1 V_1 )
{
return F_2 ( V_1 ) && ! ( F_2 ( V_1 ) & V_2 ) ;
}
int F_3 ( T_2 V_3 )
{
#ifndef F_4
return F_5 ( V_3 ) && ! ( F_5 ( V_3 ) & V_4 ) ;
#else
return 0 ;
#endif
}
static int F_6 ( struct V_5 * V_6 , unsigned long V_7 ,
T_3 * V_8 , T_3 V_9 , T_4 * V_10 )
{
T_5 * V_11 = F_7 ( V_6 , V_7 ) ;
T_2 * V_3 ;
T_1 * V_1 ;
* V_10 = V_12 ;
if ( ! F_8 ( V_9 ) )
return 1 ;
if ( ! F_9 ( * V_11 ) ) {
F_10 ( ! F_9 ( * V_11 ) ) ;
return 1 ;
}
V_3 = F_11 ( V_11 , V_7 ) ;
if ( ! F_12 ( * V_3 ) ) {
F_10 ( ! F_12 ( * V_3 ) ) ;
return 1 ;
}
V_1 = F_13 ( V_3 , V_7 ) ;
if ( ! F_14 ( * V_1 ) ) {
F_10 ( ! F_14 ( * V_1 ) ) ;
return 1 ;
}
if ( ( T_3 * ) V_1 == V_8 ) {
* V_10 = V_13 ;
return V_14 ;
}
return V_15 ;
}
void F_15 ( struct V_5 * V_6 , unsigned long V_7 ,
T_3 * V_8 , T_3 V_9 )
{
T_4 V_10 ;
int V_16 ;
int V_17 = F_6 ( V_6 , V_7 , V_8 , V_9 , & V_10 ) ;
unsigned long V_18 ;
T_6 V_19 ;
if ( V_17 == 1 ) {
F_16 ( V_6 , V_7 , V_8 , V_9 ) ;
return;
}
V_18 = F_17 ( V_9 ) ;
V_19 = F_18 ( F_19 ( F_20 ( V_18 , F_18 ( 0 ) ) ) ^ F_19 ( V_9 ) ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
F_21 ( L_1 , V_20 , V_8 ,
F_19 ( F_20 ( V_18 , V_19 ) ) ) ;
F_16 ( V_6 , V_7 , V_8 , F_20 ( V_18 , V_19 ) ) ;
V_8 ++ ;
V_18 += V_10 >> V_21 ;
V_7 += V_10 ;
}
}
T_3 * F_22 ( struct V_5 * V_6 ,
unsigned long V_7 , unsigned long V_22 )
{
T_5 * V_11 ;
T_2 * V_3 ;
T_3 * V_9 = NULL ;
F_21 ( L_2 , V_20 , V_7 , V_22 ) ;
V_11 = F_7 ( V_6 , V_7 ) ;
V_3 = F_23 ( V_6 , V_11 , V_7 ) ;
if ( ! V_3 )
return NULL ;
if ( V_22 == V_23 ) {
V_9 = ( T_3 * ) V_3 ;
} else if ( V_22 == ( V_12 * V_15 ) ) {
T_1 * V_1 = F_24 ( V_6 , V_3 , V_7 ) ;
F_25 ( V_7 & ( V_22 - 1 ) ) ;
V_9 = F_26 ( V_6 , NULL , V_1 , V_7 ) ;
} else if ( V_22 == V_13 ) {
if ( F_27 ( V_24 ) &&
F_28 ( * V_3 ) )
V_9 = F_29 ( V_6 , V_7 , V_3 ) ;
else
V_9 = ( T_3 * ) F_24 ( V_6 , V_3 , V_7 ) ;
} else if ( V_22 == ( V_13 * V_14 ) ) {
T_1 * V_1 ;
V_1 = F_24 ( V_6 , V_3 , V_7 ) ;
F_25 ( V_7 & ( V_22 - 1 ) ) ;
return ( T_3 * ) V_1 ;
}
F_21 ( L_3 , V_20 , V_7 ,
V_22 , V_9 , F_19 ( * V_9 ) ) ;
return V_9 ;
}
T_3 * F_30 ( struct V_5 * V_6 , unsigned long V_7 )
{
T_5 * V_11 ;
T_2 * V_3 ;
T_1 * V_1 = NULL ;
T_3 * V_9 = NULL ;
V_11 = F_7 ( V_6 , V_7 ) ;
F_21 ( L_4 , V_20 , V_7 , V_11 ) ;
if ( ! F_9 ( * V_11 ) )
return NULL ;
V_3 = F_11 ( V_11 , V_7 ) ;
if ( ! F_12 ( * V_3 ) )
return NULL ;
if ( F_3 ( * V_3 ) )
return ( T_3 * ) V_3 ;
V_1 = F_13 ( V_3 , V_7 ) ;
if ( ! F_14 ( * V_1 ) )
return NULL ;
if ( F_8 ( F_31 ( * V_1 ) ) ) {
V_1 = F_13 (
V_3 , ( V_7 & V_25 ) ) ;
return ( T_3 * ) V_1 ;
}
if ( F_1 ( * V_1 ) )
return ( T_3 * ) V_1 ;
V_9 = F_32 ( V_1 , V_7 ) ;
if ( F_33 ( * V_9 ) && F_8 ( * V_9 ) ) {
V_9 = F_32 (
V_1 , ( V_7 & V_26 ) ) ;
return V_9 ;
}
return NULL ;
}
T_3 F_34 ( T_3 V_27 , struct V_28 * V_29 ,
struct V_30 * V_30 , int V_31 )
{
T_4 V_32 = F_35 ( F_36 ( V_29 ) ) ;
if ( V_32 == V_33 ) {
V_27 = F_37 ( V_27 ) ;
} else if ( V_32 == V_34 ) {
V_27 = F_31 ( F_38 ( F_39 ( V_27 ) ) ) ;
} else if ( V_32 != V_23 && V_32 != V_13 ) {
F_40 ( L_5 ,
V_20 , V_32 ) ;
}
return V_27 ;
}
T_3 F_41 ( struct V_5 * V_6 ,
unsigned long V_7 , T_3 * V_8 )
{
T_3 V_9 ;
if ( F_8 ( * V_8 ) ) {
int V_17 , V_16 ;
T_4 V_10 ;
T_3 * V_35 ;
bool V_36 = false ;
V_35 = F_30 ( V_6 , V_7 ) ;
V_17 = F_6 ( V_6 , V_7 , V_35 , * V_35 , & V_10 ) ;
V_9 = F_42 ( V_6 , V_7 , V_35 ) ;
for ( V_16 = 1 ; V_16 < V_17 ; ++ V_16 ) {
++ V_35 ;
if ( F_43 ( F_42 ( V_6 , V_7 , V_35 ) ) )
V_36 = true ;
}
if ( V_36 )
return F_44 ( V_9 ) ;
else
return V_9 ;
} else {
return F_42 ( V_6 , V_7 , V_8 ) ;
}
}
int F_45 ( struct V_28 * V_29 ,
unsigned long V_7 , T_3 * V_8 ,
T_3 V_9 , int V_37 )
{
T_3 * V_35 ;
if ( F_8 ( V_9 ) ) {
int V_17 , V_16 , V_38 = 0 ;
T_4 V_10 = 0 ;
unsigned long V_18 = F_17 ( V_9 ) ;
T_6 V_19 =
F_18 ( F_19 ( F_20 ( V_18 , F_18 ( 0 ) ) ) ^
F_19 ( V_9 ) ) ;
V_35 = F_30 ( V_29 -> V_39 , V_7 ) ;
V_18 = F_17 ( * V_35 ) ;
V_17 = F_6 ( V_29 -> V_39 , V_7 , V_35 ,
* V_35 , & V_10 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_35 ) {
V_38 = F_46 ( V_29 , V_7 , V_35 ,
F_20 ( V_18 ,
V_19 ) ,
V_37 ) ;
V_18 += V_10 >> V_21 ;
}
return V_38 ;
} else {
return F_46 ( V_29 , V_7 , V_8 , V_9 , V_37 ) ;
}
}
void F_47 ( struct V_5 * V_6 ,
unsigned long V_7 , T_3 * V_8 )
{
if ( F_8 ( * V_8 ) ) {
int V_17 , V_16 ;
T_3 * V_35 ;
T_4 V_10 = 0 ;
V_35 = F_30 ( V_6 , V_7 ) ;
V_17 = F_6 ( V_6 , V_7 , V_35 , * V_35 , & V_10 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_35 )
F_48 ( V_6 , V_7 , V_35 ) ;
} else {
F_48 ( V_6 , V_7 , V_8 ) ;
}
}
void F_49 ( struct V_28 * V_29 ,
unsigned long V_7 , T_3 * V_8 )
{
if ( F_8 ( * V_8 ) ) {
int V_17 , V_16 ;
T_3 * V_35 ;
T_4 V_10 = 0 ;
V_35 = F_30 ( V_29 -> V_39 , V_7 ) ;
V_17 = F_6 ( V_29 -> V_39 , V_7 , V_35 ,
* V_35 , & V_10 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_35 )
F_50 ( V_29 , V_7 , V_35 ) ;
} else {
F_50 ( V_29 , V_7 , V_8 ) ;
}
}
static T_7 int F_51 ( char * V_40 )
{
unsigned long V_41 = F_52 ( V_40 , & V_40 ) ;
if ( V_41 == V_13 ) {
F_53 ( V_42 - V_21 ) ;
} else if ( V_41 == V_23 ) {
F_53 ( V_43 - V_21 ) ;
} else {
F_54 ( L_6 , V_41 >> 10 ) ;
return 0 ;
}
return 1 ;
}
