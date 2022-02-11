static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
int V_4 )
{
T_1 V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_4 )
return F_3 ( V_5 ) ;
return V_5 ;
}
static struct V_6 * F_4 ( struct V_1 * V_2 ,
unsigned long V_7 ,
unsigned long V_8 , int V_9 )
{
T_1 V_10 ;
int V_11 , V_12 , V_13 , V_4 = 0 ;
struct V_6 * V_14 , * V_15 ;
V_10 = F_2 ( V_2 , V_7 ) ;
if ( V_10 == V_16 ) {
if ( V_16 != F_3 ( V_16 ) )
V_4 = 1 ;
} else if ( V_10 == F_3 ( V_16 ) ) {
} else {
return F_5 ( - V_17 ) ;
}
V_10 = F_1 ( V_2 , V_7 + 4 , V_4 ) ;
V_13 = F_6 ( * ( V_18 * ) & V_10 ) ;
V_14 = F_7 ( sizeof( * V_14 ) , V_19 ) ;
if ( ! V_14 )
return F_5 ( - V_20 ) ;
V_14 -> V_21 = F_7 ( sizeof( V_14 -> V_21 [ 0 ] ) * V_13 , V_19 ) ;
V_14 -> V_22 = F_7 ( sizeof( V_14 -> V_22 [ 0 ] ) * V_13 , V_19 ) ;
if ( ! V_14 -> V_21 || ! V_14 -> V_22 ) {
F_8 ( V_14 -> V_21 ) ;
F_8 ( V_14 -> V_22 ) ;
F_8 ( V_14 ) ;
return F_5 ( - V_20 ) ;
}
V_14 -> V_23 = V_13 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_2 = V_2 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
union V_24 * V_25 ;
for ( V_12 = 0 ; V_12 < sizeof( V_14 -> V_21 [ 0 ] ) ; V_12 += 4 ) {
* ( T_1 * ) ( ( void * ) ( V_14 -> V_21 + V_11 ) + V_12 ) =
F_1 ( V_2 , V_7 + ( V_11 * 64 ) + V_12 , V_4 ) ;
}
V_25 = & V_14 -> V_21 [ V_11 ] ;
V_14 -> V_22 [ V_11 ] = F_5 ( - V_26 ) ;
if ( V_25 -> V_27 . V_28 == V_29 ) {
struct V_30 * V_31 = & V_25 -> V_32 . V_30 ;
T_2 V_33 = F_9 ( V_25 -> V_32 . V_34 ) ;
T_2 V_35 = F_9 ( V_31 -> V_36 ) ;
V_33 += V_8 ;
V_35 += V_8 ;
V_15 = F_4 ( V_2 , V_33 , V_35 ,
V_9 + 1 ) ;
V_14 -> V_22 [ V_11 ] = V_15 ;
if ( F_10 ( V_15 ) )
continue;
V_15 -> V_37 = V_14 ;
V_15 -> V_38 = V_35 ;
}
}
return V_14 ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_6 * V_39 ;
if ( V_2 -> V_40 )
return - V_41 ;
V_39 = F_4 ( V_2 , V_3 , 0 , 0 ) ;
if ( F_10 ( V_39 ) )
return F_12 ( V_39 ) ;
V_2 -> V_40 = V_39 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_14 )
{
int V_11 , V_13 ;
if ( ! V_14 )
return;
V_13 = V_14 -> V_23 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( F_10 ( V_14 -> V_22 [ V_11 ] ) )
continue;
F_13 ( V_14 -> V_22 [ V_11 ] ) ;
}
F_8 ( V_14 -> V_21 ) ;
F_8 ( V_14 -> V_22 ) ;
F_8 ( V_14 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_42 * V_43 ,
void * V_44 , unsigned long V_23 , int V_45 )
{
int V_39 ;
V_39 = V_2 -> V_46 -> V_47 ( V_2 , V_43 , V_44 , V_23 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_45 < 0 )
return V_39 ;
V_39 = F_11 ( V_2 , V_45 ) ;
if ( V_39 < 0 ) {
F_16 ( & V_2 -> V_48 , L_1 ,
V_45 ) ;
return - V_26 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_42 * V_43 , char * V_44 ,
int V_45 )
{
int V_39 ;
V_39 = V_2 -> V_46 -> V_49 ( V_2 , V_43 , V_44 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_45 < 0 )
return V_39 ;
V_39 = F_11 ( V_2 , V_45 ) ;
if ( V_39 < 0 ) {
F_16 ( & V_2 -> V_48 , L_1 ,
V_45 ) ;
return - V_26 ;
}
return 0 ;
}
void F_18 ( const struct V_1 * V_2 )
{
F_19 ( L_2 ,
V_50 ) ;
}
signed long F_20 ( struct V_6 * V_51 ,
T_2 V_52 , T_1 V_53 , unsigned long * V_54 )
{
signed long V_5 = - V_26 ;
union V_24 * V_25 ;
struct V_55 * V_56 ;
struct V_30 * V_31 ;
int V_11 , V_13 = V_51 -> V_23 ;
T_2 V_57 , V_58 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_25 = & V_51 -> V_21 [ V_11 ] ;
V_31 = & V_25 -> V_48 . V_30 ;
V_56 = & V_31 -> V_59 ;
if ( ! F_10 ( V_51 -> V_22 [ V_11 ] ) )
V_5 = F_20 ( V_51 -> V_22 [ V_11 ] ,
V_52 , V_53 , V_54 ) ;
if ( V_5 >= 0 )
return V_5 + V_51 -> V_38 ;
if ( V_25 -> V_27 . V_28 != V_60 )
continue;
if ( F_9 ( V_56 -> V_61 ) != V_52 )
continue;
if ( F_3 ( V_56 -> V_62 ) != V_53 )
continue;
V_57 = F_9 ( V_31 -> V_63 ) ;
V_58 = F_9 ( V_31 -> V_36 ) ;
if ( V_54 )
* V_54 = ( F_21 ( * V_54 ) ) ( V_57 + 1 - V_58 ) ;
return V_58 + V_51 -> V_38 ;
}
return V_5 ;
}
