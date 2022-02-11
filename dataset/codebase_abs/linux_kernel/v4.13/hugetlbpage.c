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
T_3 * V_8 , T_4 * V_9 )
{
T_5 * V_10 = F_7 ( V_6 , V_7 ) ;
T_2 * V_3 ;
T_1 * V_1 ;
* V_9 = V_11 ;
V_3 = F_8 ( V_10 , V_7 ) ;
V_1 = F_9 ( V_3 , V_7 ) ;
if ( ( T_3 * ) V_1 == V_8 ) {
* V_9 = V_12 ;
return V_13 ;
}
return V_14 ;
}
void F_10 ( struct V_5 * V_6 , unsigned long V_7 ,
T_3 * V_8 , T_3 V_15 )
{
T_4 V_9 ;
int V_16 ;
int V_17 ;
unsigned long V_18 ;
T_6 V_19 ;
if ( ! F_11 ( V_15 ) ) {
F_12 ( V_6 , V_7 , V_8 , V_15 ) ;
return;
}
V_17 = F_6 ( V_6 , V_7 , V_8 , & V_9 ) ;
V_18 = F_13 ( V_15 ) ;
V_19 = F_14 ( F_15 ( F_16 ( V_18 , F_14 ( 0 ) ) ) ^ F_15 ( V_15 ) ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
F_17 ( L_1 , V_20 , V_8 ,
F_15 ( F_16 ( V_18 , V_19 ) ) ) ;
F_12 ( V_6 , V_7 , V_8 , F_16 ( V_18 , V_19 ) ) ;
V_8 ++ ;
V_18 += V_9 >> V_21 ;
V_7 += V_9 ;
}
}
T_3 * F_18 ( struct V_5 * V_6 ,
unsigned long V_7 , unsigned long V_22 )
{
T_5 * V_10 ;
T_2 * V_3 ;
T_3 * V_15 = NULL ;
F_17 ( L_2 , V_20 , V_7 , V_22 ) ;
V_10 = F_7 ( V_6 , V_7 ) ;
V_3 = F_19 ( V_6 , V_10 , V_7 ) ;
if ( ! V_3 )
return NULL ;
if ( V_22 == V_23 ) {
V_15 = ( T_3 * ) V_3 ;
} else if ( V_22 == ( V_11 * V_14 ) ) {
T_1 * V_1 = F_20 ( V_6 , V_3 , V_7 ) ;
F_21 ( V_7 & ( V_22 - 1 ) ) ;
V_15 = F_22 ( V_6 , V_1 , V_7 ) ;
} else if ( V_22 == V_12 ) {
if ( F_23 ( V_24 ) &&
F_24 ( * V_3 ) )
V_15 = F_25 ( V_6 , V_7 , V_3 ) ;
else
V_15 = ( T_3 * ) F_20 ( V_6 , V_3 , V_7 ) ;
} else if ( V_22 == ( V_12 * V_13 ) ) {
T_1 * V_1 ;
V_1 = F_20 ( V_6 , V_3 , V_7 ) ;
F_21 ( V_7 & ( V_22 - 1 ) ) ;
return ( T_3 * ) V_1 ;
}
F_17 ( L_3 , V_20 , V_7 ,
V_22 , V_15 , F_15 ( * V_15 ) ) ;
return V_15 ;
}
T_3 * F_26 ( struct V_5 * V_6 ,
unsigned long V_7 , unsigned long V_22 )
{
T_5 * V_10 ;
T_2 * V_3 ;
T_1 * V_1 ;
V_10 = F_7 ( V_6 , V_7 ) ;
F_17 ( L_4 , V_20 , V_7 , V_10 ) ;
if ( ! F_27 ( * V_10 ) )
return NULL ;
V_3 = F_8 ( V_10 , V_7 ) ;
if ( F_24 ( * V_3 ) )
return NULL ;
if ( ! F_28 ( * V_3 ) || F_3 ( * V_3 ) )
return ( T_3 * ) V_3 ;
V_1 = F_9 ( V_3 , V_7 ) ;
if ( F_29 ( * V_1 ) )
return NULL ;
if ( ! F_30 ( * V_1 ) || F_1 ( * V_1 ) )
return ( T_3 * ) V_1 ;
return NULL ;
}
T_3 F_31 ( T_3 V_25 , struct V_26 * V_27 ,
struct V_28 * V_28 , int V_29 )
{
T_4 V_30 = F_32 ( F_33 ( V_27 ) ) ;
if ( V_30 == V_31 ) {
V_25 = F_34 ( V_25 ) ;
} else if ( V_30 == V_32 ) {
V_25 = F_35 ( F_36 ( F_37 ( V_25 ) ) ) ;
} else if ( V_30 != V_23 && V_30 != V_12 ) {
F_38 ( L_5 ,
V_20 , V_30 ) ;
}
return V_25 ;
}
T_3 F_39 ( struct V_5 * V_6 ,
unsigned long V_7 , T_3 * V_8 )
{
T_3 V_15 ;
if ( F_11 ( * V_8 ) ) {
int V_17 , V_16 ;
T_4 V_9 ;
bool V_33 = false ;
V_17 = F_6 ( V_6 , V_7 , V_8 , & V_9 ) ;
V_15 = F_40 ( V_6 , V_7 , V_8 ) ;
for ( V_16 = 1 , V_7 += V_9 ; V_16 < V_17 ; ++ V_16 , V_7 += V_9 ) {
++ V_8 ;
if ( F_41 ( F_40 ( V_6 , V_7 , V_8 ) ) )
V_33 = true ;
}
if ( V_33 )
return F_42 ( V_15 ) ;
else
return V_15 ;
} else {
return F_40 ( V_6 , V_7 , V_8 ) ;
}
}
int F_43 ( struct V_26 * V_27 ,
unsigned long V_7 , T_3 * V_8 ,
T_3 V_15 , int V_34 )
{
if ( F_11 ( V_15 ) ) {
int V_17 , V_16 , V_35 = 0 ;
T_4 V_9 = 0 ;
unsigned long V_18 = F_13 ( V_15 ) ;
T_6 V_19 =
F_14 ( F_15 ( F_16 ( V_18 , F_14 ( 0 ) ) ) ^
F_15 ( V_15 ) ) ;
V_18 = F_13 ( V_15 ) ;
V_17 = F_6 ( V_27 -> V_36 , V_7 , V_8 ,
& V_9 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_8 , V_7 += V_9 ) {
V_35 |= F_44 ( V_27 , V_7 , V_8 ,
F_16 ( V_18 ,
V_19 ) ,
V_34 ) ;
V_18 += V_9 >> V_21 ;
}
return V_35 ;
} else {
return F_44 ( V_27 , V_7 , V_8 , V_15 , V_34 ) ;
}
}
void F_45 ( struct V_5 * V_6 ,
unsigned long V_7 , T_3 * V_8 )
{
if ( F_11 ( * V_8 ) ) {
int V_17 , V_16 ;
T_4 V_9 = 0 ;
V_17 = F_6 ( V_6 , V_7 , V_8 , & V_9 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_8 , V_7 += V_9 )
F_46 ( V_6 , V_7 , V_8 ) ;
} else {
F_46 ( V_6 , V_7 , V_8 ) ;
}
}
void F_47 ( struct V_26 * V_27 ,
unsigned long V_7 , T_3 * V_8 )
{
if ( F_11 ( * V_8 ) ) {
int V_17 , V_16 ;
T_4 V_9 = 0 ;
V_17 = F_6 ( V_27 -> V_36 , V_7 , V_8 ,
& V_9 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 , ++ V_8 , V_7 += V_9 )
F_48 ( V_27 , V_7 , V_8 ) ;
} else {
F_48 ( V_27 , V_7 , V_8 ) ;
}
}
static T_7 int F_49 ( char * V_37 )
{
unsigned long V_38 = F_50 ( V_37 , & V_37 ) ;
if ( V_38 == V_12 ) {
F_51 ( V_39 - V_21 ) ;
} else if ( V_38 == V_23 ) {
F_51 ( V_40 - V_21 ) ;
} else {
F_52 () ;
F_53 ( L_6 , V_38 >> 10 ) ;
return 0 ;
}
return 1 ;
}
