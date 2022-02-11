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
static int F_5 ( struct V_18 * V_18 , struct V_26 * V_27 )
{
bool V_28 ;
struct V_1 V_29 ;
int V_30 = 0 ;
struct V_21 * V_22 ;
int V_20 ;
int V_31 = 0 ;
struct V_17 * V_24 ;
struct V_32 V_32 ;
F_6 ( V_33 , L_1 , V_18 ) ;
V_22 = V_18 -> V_23 ;
V_20 = V_22 -> V_34 -> V_35 - V_36 ;
V_24 = F_3 ( V_18 , V_20 ) ;
if ( ! V_24 )
return - V_37 ;
V_32 . V_38 = V_24 -> V_39 ;
V_32 . V_40 = V_20 ;
while ( 1 ) {
if ( V_24 -> V_41 == V_24 -> V_42 ) {
struct V_43 V_44 ;
int V_45 ;
F_7 ( & V_44 , V_46 | V_47 , & V_32 , 1 , V_20 ) ;
V_45 = F_8 ( V_18 -> V_23 , V_27 -> V_48 , & V_44 ,
& V_30 ) ;
if ( V_30 )
return V_30 ;
if ( V_45 == 0 )
return 0 ;
V_24 -> V_42 = 0 ;
V_24 -> V_41 = V_45 ;
}
while ( V_24 -> V_42 < V_24 -> V_41 ) {
F_2 ( & V_29 ) ;
V_30 = F_9 ( V_22 -> V_34 , V_24 -> V_39 + V_24 -> V_42 ,
V_24 -> V_41 - V_24 -> V_42 , & V_29 ) ;
if ( V_30 ) {
F_6 ( V_33 , L_2 , V_30 ) ;
F_10 ( & V_29 ) ;
return - V_49 ;
}
V_31 = V_29 . V_50 + 2 ;
V_28 = ! F_11 ( V_27 , V_29 . V_12 , strlen ( V_29 . V_12 ) ,
F_12 ( & V_29 . V_51 ) , F_1 ( & V_29 ) ) ;
F_10 ( & V_29 ) ;
if ( V_28 )
return 0 ;
V_24 -> V_42 += V_31 ;
V_27 -> V_48 += V_31 ;
}
}
}
static int F_13 ( struct V_18 * V_18 , struct V_26 * V_27 )
{
int V_30 = 0 ;
struct V_21 * V_22 ;
int V_20 ;
struct V_17 * V_24 ;
struct V_52 V_53 ;
F_6 ( V_33 , L_1 , V_18 ) ;
V_22 = V_18 -> V_23 ;
V_20 = V_22 -> V_34 -> V_35 - V_54 ;
V_24 = F_3 ( V_18 , V_20 ) ;
if ( ! V_24 )
return - V_37 ;
while ( 1 ) {
if ( V_24 -> V_41 == V_24 -> V_42 ) {
V_30 = F_14 ( V_22 , V_24 -> V_39 , V_20 ,
V_27 -> V_48 ) ;
if ( V_30 <= 0 )
return V_30 ;
V_24 -> V_42 = 0 ;
V_24 -> V_41 = V_30 ;
}
while ( V_24 -> V_42 < V_24 -> V_41 ) {
V_30 = F_15 ( V_22 -> V_34 , V_24 -> V_39 + V_24 -> V_42 ,
V_24 -> V_41 - V_24 -> V_42 ,
& V_53 ) ;
if ( V_30 < 0 ) {
F_6 ( V_33 , L_2 , V_30 ) ;
return - V_49 ;
}
if ( ! F_11 ( V_27 , V_53 . V_55 ,
strlen ( V_53 . V_55 ) ,
F_12 ( & V_53 . V_51 ) ,
V_53 . V_56 ) )
return 0 ;
V_27 -> V_48 = V_53 . V_57 ;
V_24 -> V_42 += V_30 ;
}
}
}
int F_16 ( struct V_58 * V_58 , struct V_18 * V_19 )
{
struct V_21 * V_22 ;
V_22 = V_19 -> V_23 ;
F_6 ( V_33 , L_3 ,
V_58 , V_19 , V_22 ? V_22 -> V_22 : - 1 ) ;
if ( V_22 )
F_17 ( V_22 ) ;
return 0 ;
}
