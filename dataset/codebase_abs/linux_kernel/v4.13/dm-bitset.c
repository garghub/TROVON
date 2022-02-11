void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 , V_2 , & V_6 ) ;
V_4 -> V_7 = false ;
}
int F_3 ( struct V_3 * V_4 , T_1 * V_8 )
{
return F_4 ( & V_4 -> V_5 , V_8 ) ;
}
static int F_5 ( T_2 V_9 , void * V_10 , void * V_11 )
{
int V_12 ;
struct V_13 * V_14 = V_11 ;
unsigned V_15 , V_16 = F_6 ( 64u , V_14 -> V_17 - ( V_9 * 64 ) ) ;
T_3 V_18 = 0 ;
bool V_19 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_12 = V_14 -> V_20 ( V_9 * 64 + V_15 , & V_19 , V_14 -> V_11 ) ;
if ( V_12 )
return V_12 ;
if ( V_19 )
F_7 ( V_15 , ( unsigned long * ) & V_18 ) ;
else
F_8 ( V_15 , ( unsigned long * ) & V_18 ) ;
}
* ( ( V_21 * ) V_10 ) = F_9 ( V_18 ) ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 , T_1 * V_8 ,
T_2 V_22 , T_4 V_20 , void * V_11 )
{
struct V_13 V_14 ;
V_14 . V_20 = V_20 ;
V_14 . V_17 = V_22 ;
V_14 . V_11 = V_11 ;
return F_11 ( & V_4 -> V_5 , V_8 , F_12 ( V_22 , 64 ) , F_5 , & V_14 ) ;
}
int F_13 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_23 , T_2 V_24 ,
bool V_25 , T_1 * V_26 )
{
T_2 V_27 = F_12 ( V_23 , V_28 ) ;
T_2 V_29 = F_12 ( V_24 , V_28 ) ;
V_21 V_10 = V_25 ? F_9 ( ~ 0 ) : F_9 ( 0 ) ;
F_14 ( & V_10 ) ;
return F_15 ( & V_4 -> V_5 , V_8 , V_27 , V_29 ,
& V_10 , V_26 ) ;
}
int F_16 ( struct V_3 * V_4 , T_1 V_8 )
{
return F_17 ( & V_4 -> V_5 , V_8 ) ;
}
int F_18 ( struct V_3 * V_4 , T_1 V_8 ,
T_1 * V_26 )
{
int V_12 ;
V_21 V_10 ;
if ( ! V_4 -> V_7 || ! V_4 -> V_30 )
return 0 ;
V_10 = F_9 ( V_4 -> V_31 ) ;
F_14 ( & V_10 ) ;
V_12 = F_19 ( & V_4 -> V_5 , V_8 , V_4 -> V_32 ,
& V_10 , V_26 ) ;
if ( V_12 )
return V_12 ;
V_4 -> V_7 = false ;
V_4 -> V_30 = false ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_33 )
{
int V_12 ;
V_21 V_10 ;
V_12 = F_21 ( & V_4 -> V_5 , V_8 , V_33 , & V_10 ) ;
if ( V_12 )
return V_12 ;
V_4 -> V_31 = F_22 ( V_10 ) ;
V_4 -> V_7 = true ;
V_4 -> V_32 = V_33 ;
V_4 -> V_30 = false ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_9 , T_1 * V_26 )
{
int V_12 ;
unsigned V_33 = V_9 / V_28 ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_32 == V_33 )
return 0 ;
V_12 = F_18 ( V_4 , V_8 , V_26 ) ;
if ( V_12 )
return V_12 ;
}
return F_20 ( V_4 , V_8 , V_33 ) ;
}
int F_24 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_9 , T_1 * V_26 )
{
int V_12 ;
unsigned V_34 = V_9 % V_28 ;
V_12 = F_23 ( V_4 , V_8 , V_9 , V_26 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_34 , ( unsigned long * ) & V_4 -> V_31 ) ;
V_4 -> V_30 = true ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_9 , T_1 * V_26 )
{
int V_12 ;
unsigned V_34 = V_9 % V_28 ;
V_12 = F_23 ( V_4 , V_8 , V_9 , V_26 ) ;
if ( V_12 )
return V_12 ;
F_8 ( V_34 , ( unsigned long * ) & V_4 -> V_31 ) ;
V_4 -> V_30 = true ;
return 0 ;
}
int F_26 ( struct V_3 * V_4 , T_1 V_8 ,
T_2 V_9 , T_1 * V_26 , bool * V_35 )
{
int V_12 ;
unsigned V_34 = V_9 % V_28 ;
V_12 = F_23 ( V_4 , V_8 , V_9 , V_26 ) ;
if ( V_12 )
return V_12 ;
* V_35 = F_27 ( V_34 , ( unsigned long * ) & V_4 -> V_31 ) ;
return 0 ;
}
static int F_28 ( struct V_36 * V_37 )
{
int V_12 ;
V_21 * V_10 ;
V_12 = F_29 ( & V_37 -> V_38 ) ;
if ( V_12 )
return V_12 ;
F_30 ( & V_37 -> V_38 , ( void * * ) & V_10 ) ;
V_37 -> V_33 ++ ;
V_37 -> V_39 = 0 ;
V_37 -> V_31 = F_22 ( * V_10 ) ;
return 0 ;
}
int F_31 ( struct V_3 * V_4 ,
T_1 V_8 , T_2 V_40 ,
struct V_36 * V_37 )
{
int V_12 ;
V_21 * V_10 ;
if ( ! V_40 )
return - V_41 ;
V_37 -> V_4 = V_4 ;
V_37 -> V_42 = V_40 ;
V_12 = F_32 ( & V_4 -> V_5 , V_8 , & V_37 -> V_38 ) ;
if ( V_12 )
return V_12 ;
F_30 ( & V_37 -> V_38 , ( void * * ) & V_10 ) ;
V_37 -> V_33 = 0 ;
V_37 -> V_39 = 0 ;
V_37 -> V_31 = F_22 ( * V_10 ) ;
return V_12 ;
}
void F_33 ( struct V_36 * V_37 )
{
return F_34 ( & V_37 -> V_38 ) ;
}
int F_35 ( struct V_36 * V_37 )
{
int V_12 = 0 ;
if ( ! V_37 -> V_42 )
return - V_41 ;
V_37 -> V_42 -- ;
if ( ++ V_37 -> V_39 > 63 )
V_12 = F_28 ( V_37 ) ;
return V_12 ;
}
int F_36 ( struct V_36 * V_37 , T_2 V_43 )
{
int V_12 ;
V_21 * V_10 ;
T_2 V_44 ;
T_2 V_45 = 64 - V_37 -> V_39 ;
if ( V_37 -> V_42 < V_43 )
return - V_41 ;
if ( V_43 < V_45 ) {
V_37 -> V_39 += V_43 ;
V_37 -> V_42 -= V_43 ;
return 0 ;
} else {
V_37 -> V_42 -= V_45 ;
V_43 -= V_45 ;
}
V_44 = ( V_43 / 64 ) + 1 ;
V_12 = F_37 ( & V_37 -> V_38 , V_44 ) ;
if ( V_12 )
return V_12 ;
F_30 ( & V_37 -> V_38 , ( void * * ) & V_10 ) ;
V_37 -> V_42 -= V_43 ;
V_37 -> V_33 += V_44 ;
V_37 -> V_39 = V_43 & 63 ;
V_37 -> V_31 = F_22 ( * V_10 ) ;
return 0 ;
}
bool F_38 ( struct V_36 * V_37 )
{
return F_27 ( V_37 -> V_39 , ( unsigned long * ) & V_37 -> V_31 ) ;
}
