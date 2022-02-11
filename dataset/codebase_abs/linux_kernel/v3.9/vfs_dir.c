static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_4 ;
int V_5 = V_6 ;
if ( V_3 & V_7 )
V_5 = V_8 ;
if ( V_3 & V_9 )
V_5 = V_10 ;
return V_5 ;
}
static void F_2 ( struct V_1 * V_11 )
{
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_14 = NULL ;
V_11 -> V_15 = NULL ;
V_11 -> V_16 = NULL ;
}
static struct V_17 * F_3 ( struct V_18 * V_19 , int V_20 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_24 )
V_22 -> V_24 = F_4 ( sizeof( struct V_17 ) + V_20 , V_25 ) ;
return V_22 -> V_24 ;
}
static int F_5 ( struct V_18 * V_19 , void * V_26 , T_1 V_27 )
{
int V_28 ;
struct V_1 V_29 ;
int V_30 = 0 ;
struct V_21 * V_22 ;
int V_20 ;
int V_31 = 0 ;
struct V_17 * V_24 ;
F_6 ( V_32 , L_1 , V_19 -> V_33 . V_34 -> V_35 . V_12 ) ;
V_22 = V_19 -> V_23 ;
V_20 = V_22 -> V_36 -> V_37 - V_38 ;
V_24 = F_3 ( V_19 , V_20 ) ;
if ( ! V_24 )
return - V_39 ;
while ( 1 ) {
if ( V_24 -> V_40 == V_24 -> V_41 ) {
V_30 = F_7 ( V_19 , V_24 -> V_42 , NULL ,
V_20 , V_19 -> V_43 ) ;
if ( V_30 <= 0 )
return V_30 ;
V_24 -> V_41 = 0 ;
V_24 -> V_40 = V_30 ;
}
while ( V_24 -> V_41 < V_24 -> V_40 ) {
F_2 ( & V_29 ) ;
V_30 = F_8 ( V_22 -> V_36 , V_24 -> V_42 + V_24 -> V_41 ,
V_24 -> V_40 - V_24 -> V_41 , & V_29 ) ;
if ( V_30 ) {
F_6 ( V_32 , L_2 , V_30 ) ;
F_9 ( & V_29 ) ;
return - V_44 ;
}
V_31 = V_29 . V_45 + 2 ;
V_28 = V_27 ( V_26 , V_29 . V_12 , strlen ( V_29 . V_12 ) ,
V_19 -> V_43 , F_10 ( & V_29 . V_46 ) , F_1 ( & V_29 ) ) ;
F_9 ( & V_29 ) ;
if ( V_28 )
return 0 ;
V_24 -> V_41 += V_31 ;
V_19 -> V_43 += V_31 ;
}
}
}
static int F_11 ( struct V_18 * V_19 , void * V_26 ,
T_1 V_27 )
{
int V_28 ;
int V_30 = 0 ;
struct V_21 * V_22 ;
int V_20 ;
struct V_17 * V_24 ;
struct V_47 V_48 ;
T_2 V_49 = 0 ;
F_6 ( V_32 , L_1 , V_19 -> V_33 . V_34 -> V_35 . V_12 ) ;
V_22 = V_19 -> V_23 ;
V_20 = V_22 -> V_36 -> V_37 - V_50 ;
V_24 = F_3 ( V_19 , V_20 ) ;
if ( ! V_24 )
return - V_39 ;
while ( 1 ) {
if ( V_24 -> V_40 == V_24 -> V_41 ) {
V_30 = F_12 ( V_22 , V_24 -> V_42 , V_20 ,
V_19 -> V_43 ) ;
if ( V_30 <= 0 )
return V_30 ;
V_24 -> V_41 = 0 ;
V_24 -> V_40 = V_30 ;
}
while ( V_24 -> V_41 < V_24 -> V_40 ) {
V_30 = F_13 ( V_22 -> V_36 , V_24 -> V_42 + V_24 -> V_41 ,
V_24 -> V_40 - V_24 -> V_41 ,
& V_48 ) ;
if ( V_30 < 0 ) {
F_6 ( V_32 , L_2 , V_30 ) ;
return - V_44 ;
}
V_28 = V_27 ( V_26 , V_48 . V_35 ,
strlen ( V_48 . V_35 ) ,
V_49 , F_10 ( & V_48 . V_46 ) ,
V_48 . V_51 ) ;
V_49 = V_48 . V_52 ;
if ( V_28 )
return 0 ;
V_19 -> V_43 = V_48 . V_52 ;
V_24 -> V_41 += V_30 ;
}
}
}
int F_14 ( struct V_53 * V_53 , struct V_18 * V_19 )
{
struct V_21 * V_22 ;
V_22 = V_19 -> V_23 ;
F_6 ( V_32 , L_3 ,
V_53 , V_19 , V_22 ? V_22 -> V_22 : - 1 ) ;
if ( V_22 )
F_15 ( V_22 ) ;
return 0 ;
}
