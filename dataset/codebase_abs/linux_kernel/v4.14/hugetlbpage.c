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
static inline T_3 F_6 ( T_4 V_5 )
{
unsigned long V_6 = F_7 ( V_5 ) ;
return F_8 ( F_9 ( F_10 ( V_6 , F_8 ( 0 ) ) ) ^ F_9 ( V_5 ) ) ;
}
static int F_11 ( struct V_7 * V_8 , unsigned long V_9 ,
T_4 * V_10 , T_5 * V_11 )
{
T_6 * V_12 = F_12 ( V_8 , V_9 ) ;
T_2 * V_3 ;
T_1 * V_1 ;
* V_11 = V_13 ;
V_3 = F_13 ( V_12 , V_9 ) ;
V_1 = F_14 ( V_3 , V_9 ) ;
if ( ( T_4 * ) V_1 == V_10 ) {
* V_11 = V_14 ;
return V_15 ;
}
return V_16 ;
}
static inline int F_15 ( unsigned long V_17 , T_5 * V_11 )
{
int V_18 = 0 ;
* V_11 = V_17 ;
switch ( V_17 ) {
#ifdef F_16
case V_19 :
#endif
case V_14 :
V_18 = 1 ;
break;
case V_20 :
* V_11 = V_14 ;
V_18 = V_15 ;
break;
case V_21 :
* V_11 = V_13 ;
V_18 = V_16 ;
break;
}
return V_18 ;
}
static T_4 F_17 ( struct V_7 * V_8 ,
unsigned long V_9 ,
T_4 * V_10 ,
unsigned long V_11 ,
unsigned long V_22 )
{
struct V_23 V_24 = { . V_25 = V_8 } ;
T_4 V_26 = F_18 ( V_10 ) ;
bool V_27 = F_19 ( V_26 ) ;
unsigned long V_28 , V_29 = V_9 ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_9 += V_11 , V_10 ++ ) {
T_4 V_5 = F_20 ( V_8 , V_9 , V_10 ) ;
if ( F_21 ( V_5 ) )
V_26 = F_22 ( V_26 ) ;
}
if ( V_27 )
F_23 ( & V_24 , V_29 , V_9 ) ;
return V_26 ;
}
static void F_24 ( struct V_7 * V_8 ,
unsigned long V_9 ,
T_4 * V_10 ,
unsigned long V_11 ,
unsigned long V_22 )
{
struct V_23 V_24 = { . V_25 = V_8 } ;
unsigned long V_28 , V_29 = V_9 ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_9 += V_11 , V_10 ++ )
F_25 ( V_8 , V_9 , V_10 ) ;
F_23 ( & V_24 , V_29 , V_9 ) ;
}
void F_26 ( struct V_7 * V_8 , unsigned long V_9 ,
T_4 * V_10 , T_4 V_5 )
{
T_5 V_11 ;
int V_28 ;
int V_22 ;
unsigned long V_6 , V_30 ;
T_3 V_31 ;
F_27 ( ! F_28 ( V_5 ) ) ;
if ( ! F_29 ( V_5 ) ) {
F_30 ( V_8 , V_9 , V_10 , V_5 ) ;
return;
}
V_22 = F_11 ( V_8 , V_9 , V_10 , & V_11 ) ;
V_6 = F_7 ( V_5 ) ;
V_30 = V_11 >> V_32 ;
V_31 = F_6 ( V_5 ) ;
F_24 ( V_8 , V_9 , V_10 , V_11 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_10 ++ , V_9 += V_11 , V_6 += V_30 ) {
F_31 ( L_1 , V_33 , V_10 ,
F_9 ( F_10 ( V_6 , V_31 ) ) ) ;
F_30 ( V_8 , V_9 , V_10 , F_10 ( V_6 , V_31 ) ) ;
}
}
void F_32 ( struct V_7 * V_8 , unsigned long V_9 ,
T_4 * V_10 , T_4 V_5 , unsigned long V_34 )
{
int V_28 , V_22 ;
T_5 V_11 ;
V_22 = F_15 ( V_34 , & V_11 ) ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_10 ++ )
F_33 ( V_10 , V_5 ) ;
}
T_4 * F_34 ( struct V_7 * V_8 ,
unsigned long V_9 , unsigned long V_34 )
{
T_6 * V_12 ;
T_2 * V_3 ;
T_4 * V_5 = NULL ;
F_31 ( L_2 , V_33 , V_9 , V_34 ) ;
V_12 = F_12 ( V_8 , V_9 ) ;
V_3 = F_35 ( V_8 , V_12 , V_9 ) ;
if ( ! V_3 )
return NULL ;
if ( V_34 == V_19 ) {
V_5 = ( T_4 * ) V_3 ;
} else if ( V_34 == ( V_13 * V_16 ) ) {
T_1 * V_1 = F_36 ( V_8 , V_3 , V_9 ) ;
F_27 ( V_9 & ( V_34 - 1 ) ) ;
V_5 = F_37 ( V_8 , V_1 , V_9 ) ;
} else if ( V_34 == V_14 ) {
if ( F_38 ( V_35 ) &&
F_39 ( * V_3 ) )
V_5 = F_40 ( V_8 , V_9 , V_3 ) ;
else
V_5 = ( T_4 * ) F_36 ( V_8 , V_3 , V_9 ) ;
} else if ( V_34 == ( V_14 * V_15 ) ) {
T_1 * V_1 ;
V_1 = F_36 ( V_8 , V_3 , V_9 ) ;
F_27 ( V_9 & ( V_34 - 1 ) ) ;
return ( T_4 * ) V_1 ;
}
F_31 ( L_3 , V_33 , V_9 ,
V_34 , V_5 , F_9 ( * V_5 ) ) ;
return V_5 ;
}
T_4 * F_41 ( struct V_7 * V_8 ,
unsigned long V_9 , unsigned long V_34 )
{
T_6 * V_12 ;
T_2 * V_3 ;
T_1 * V_1 ;
V_12 = F_12 ( V_8 , V_9 ) ;
F_31 ( L_4 , V_33 , V_9 , V_12 ) ;
if ( ! F_42 ( * V_12 ) )
return NULL ;
V_3 = F_13 ( V_12 , V_9 ) ;
if ( V_34 != V_19 && F_39 ( * V_3 ) )
return NULL ;
if ( F_3 ( * V_3 ) || ! F_43 ( * V_3 ) )
return ( T_4 * ) V_3 ;
if ( V_34 == V_20 )
V_9 &= V_36 ;
V_1 = F_14 ( V_3 , V_9 ) ;
if ( ! ( V_34 == V_14 || V_34 == V_20 ) &&
F_44 ( * V_1 ) )
return NULL ;
if ( F_1 ( * V_1 ) || ! F_45 ( * V_1 ) )
return ( T_4 * ) V_1 ;
if ( V_34 == V_21 ) {
T_4 * V_5 = F_46 ( V_1 , ( V_9 & V_37 ) ) ;
return V_5 ;
}
return NULL ;
}
T_4 F_47 ( T_4 V_38 , struct V_23 * V_24 ,
struct V_39 * V_39 , int V_40 )
{
T_5 V_41 = F_48 ( F_49 ( V_24 ) ) ;
if ( V_41 == V_21 ) {
V_38 = F_50 ( V_38 ) ;
} else if ( V_41 == V_20 ) {
V_38 = F_51 ( F_52 ( F_53 ( V_38 ) ) ) ;
} else if ( V_41 != V_19 && V_41 != V_14 ) {
F_54 ( L_5 ,
V_33 , V_41 ) ;
}
return V_38 ;
}
void F_55 ( struct V_7 * V_8 , unsigned long V_9 ,
T_4 * V_10 , unsigned long V_34 )
{
int V_28 , V_22 ;
T_5 V_11 ;
V_22 = F_15 ( V_34 , & V_11 ) ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_9 += V_11 , V_10 ++ )
F_25 ( V_8 , V_9 , V_10 ) ;
}
T_4 F_56 ( struct V_7 * V_8 ,
unsigned long V_9 , T_4 * V_10 )
{
int V_22 ;
T_5 V_11 ;
T_4 V_26 = F_18 ( V_10 ) ;
if ( ! F_29 ( V_26 ) )
return F_20 ( V_8 , V_9 , V_10 ) ;
V_22 = F_11 ( V_8 , V_9 , V_10 , & V_11 ) ;
return F_17 ( V_8 , V_9 , V_10 , V_11 , V_22 ) ;
}
int F_57 ( struct V_23 * V_24 ,
unsigned long V_9 , T_4 * V_10 ,
T_4 V_5 , int V_42 )
{
int V_22 , V_28 , V_43 = 0 ;
T_5 V_11 = 0 ;
unsigned long V_6 = F_7 ( V_5 ) , V_30 ;
T_3 V_31 ;
T_4 V_26 ;
if ( ! F_29 ( V_5 ) )
return F_58 ( V_24 , V_9 , V_10 , V_5 , V_42 ) ;
V_22 = F_11 ( V_24 -> V_25 , V_9 , V_10 , & V_11 ) ;
V_30 = V_11 >> V_32 ;
V_26 = F_17 ( V_24 -> V_25 , V_9 , V_10 , V_11 , V_22 ) ;
if ( ! F_59 ( V_26 , V_5 ) )
V_43 = 1 ;
if ( F_21 ( V_26 ) )
V_5 = F_22 ( V_5 ) ;
V_31 = F_6 ( V_5 ) ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_10 ++ , V_9 += V_11 , V_6 += V_30 )
F_30 ( V_24 -> V_25 , V_9 , V_10 , F_10 ( V_6 , V_31 ) ) ;
return V_43 ;
}
void F_60 ( struct V_7 * V_8 ,
unsigned long V_9 , T_4 * V_10 )
{
unsigned long V_6 , V_30 ;
T_3 V_31 ;
int V_22 , V_28 ;
T_5 V_11 ;
T_4 V_5 ;
if ( ! F_29 ( * V_10 ) ) {
F_61 ( V_8 , V_9 , V_10 ) ;
return;
}
V_22 = F_11 ( V_8 , V_9 , V_10 , & V_11 ) ;
V_30 = V_11 >> V_32 ;
V_5 = F_17 ( V_8 , V_9 , V_10 , V_11 , V_22 ) ;
V_5 = F_62 ( V_5 ) ;
V_31 = F_6 ( V_5 ) ;
V_6 = F_7 ( V_5 ) ;
for ( V_28 = 0 ; V_28 < V_22 ; V_28 ++ , V_10 ++ , V_9 += V_11 , V_6 += V_30 )
F_30 ( V_8 , V_9 , V_10 , F_10 ( V_6 , V_31 ) ) ;
}
void F_63 ( struct V_23 * V_24 ,
unsigned long V_9 , T_4 * V_10 )
{
T_5 V_11 ;
int V_22 ;
if ( ! F_29 ( * V_10 ) ) {
F_64 ( V_24 , V_9 , V_10 ) ;
return;
}
V_22 = F_11 ( V_24 -> V_25 , V_9 , V_10 , & V_11 ) ;
F_24 ( V_24 -> V_25 , V_9 , V_10 , V_11 , V_22 ) ;
}
static T_7 int F_65 ( char * V_44 )
{
unsigned long V_45 = F_66 ( V_44 , & V_44 ) ;
switch ( V_45 ) {
#ifdef F_16
case V_19 :
#endif
case V_14 * V_15 :
case V_14 :
case V_13 * V_16 :
F_67 ( F_68 ( V_45 ) - V_32 ) ;
return 1 ;
}
F_69 () ;
F_70 ( L_6 , V_45 >> 10 ) ;
return 0 ;
}
static T_7 int F_71 ( void )
{
if ( F_72 ( V_16 * V_13 ) == NULL )
F_67 ( V_46 ) ;
return 0 ;
}
