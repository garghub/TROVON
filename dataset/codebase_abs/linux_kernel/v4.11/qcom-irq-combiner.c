static inline int F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_1 * V_3 + V_2 ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = F_4 ( V_5 ) ;
T_1 V_1 ;
F_5 ( V_8 , V_5 ) ;
for ( V_1 = 0 ; V_1 < V_6 -> V_9 ; V_1 ++ ) {
int V_10 ;
int V_11 ;
T_1 V_2 ;
T_1 V_12 ;
V_2 = F_6 ( V_6 -> V_13 [ V_1 ] . V_14 ) ;
V_12 = V_2 & V_6 -> V_13 [ V_1 ] . V_15 ;
if ( ! V_12 )
F_7 ( L_1 ,
F_8 () , V_2 ,
V_6 -> V_13 [ V_1 ] . V_15 ,
V_6 -> V_13 [ V_1 ] . V_14 ) ;
while ( V_12 ) {
V_2 = F_9 ( V_12 ) ;
V_12 &= ~ ( 1 << V_2 ) ;
V_11 = F_1 ( V_1 , V_2 ) ;
V_10 = F_10 ( V_6 -> V_16 , V_11 ) ;
if ( V_10 > 0 )
F_11 ( V_10 ) ;
}
}
F_12 ( V_8 , V_5 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
struct V_6 * V_6 = F_14 ( V_18 ) ;
struct V_19 * V_1 = V_6 -> V_13 + V_18 -> V_11 / V_3 ;
F_15 ( V_18 -> V_11 % V_3 , & V_1 -> V_15 ) ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_6 * V_6 = F_14 ( V_18 ) ;
struct V_19 * V_1 = V_6 -> V_13 + V_18 -> V_11 / V_3 ;
F_17 ( V_18 -> V_11 % V_3 , & V_1 -> V_15 ) ;
}
static int F_18 ( struct V_20 * V_16 , unsigned int V_21 ,
T_2 V_11 )
{
F_19 ( V_21 , & V_7 , V_22 ) ;
F_20 ( V_21 , V_16 -> V_23 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
static void F_22 ( struct V_20 * V_16 , unsigned int V_21 )
{
F_23 ( F_24 ( V_21 ) ) ;
}
static int F_25 ( struct V_20 * V_24 , struct V_25 * V_26 ,
unsigned long * V_11 , unsigned int * type )
{
struct V_6 * V_6 = V_24 -> V_23 ;
if ( F_26 ( V_26 -> V_27 ) ) {
if ( F_27 ( ( V_26 -> V_28 != 2 ) ||
( V_26 -> V_29 [ 0 ] >= V_6 -> V_30 ) ||
( V_26 -> V_29 [ 1 ] & V_31 ) ||
( V_26 -> V_29 [ 1 ] & V_32 ) ) )
return - V_33 ;
* V_11 = V_26 -> V_29 [ 0 ] ;
* type = V_26 -> V_29 [ 1 ] ;
return 0 ;
}
return - V_33 ;
}
static T_3 F_28 ( struct V_34 * V_35 , void * V_36 )
{
int * V_37 = V_36 ;
if ( V_35 -> type == V_38 )
++ ( * V_37 ) ;
return V_39 ;
}
static int F_29 ( struct V_40 * V_41 )
{
T_4 V_42 = F_30 ( & V_41 -> V_43 ) ;
T_3 V_12 ;
int V_37 = 0 ;
if ( ! F_31 ( V_42 , V_44 ) )
return - V_33 ;
V_12 = F_32 ( V_42 , V_44 ,
F_28 , & V_37 ) ;
if ( F_33 ( V_12 ) )
return - V_33 ;
return V_37 ;
}
static T_3 F_34 ( struct V_34 * V_35 , void * V_36 )
{
struct V_45 * V_46 = V_36 ;
struct V_47 * V_1 ;
T_5 V_48 ;
void T_6 * V_49 ;
if ( V_35 -> type != V_38 )
return V_39 ;
V_1 = & V_35 -> V_18 . V_50 ;
V_48 = V_1 -> V_51 ;
if ( ( V_1 -> V_52 != V_53 ) ||
( V_1 -> V_54 != 0 ) ||
( V_1 -> V_55 > V_3 ) ) {
F_35 ( V_46 -> V_43 , L_2 , & V_48 ) ;
V_46 -> V_56 = - V_33 ;
return V_57 ;
}
V_49 = F_36 ( V_46 -> V_43 , V_1 -> V_51 , V_3 ) ;
if ( ! V_49 ) {
F_35 ( V_46 -> V_43 , L_3 , & V_48 ) ;
V_46 -> V_56 = - V_58 ;
return V_57 ;
}
V_46 -> V_6 -> V_13 [ V_46 -> V_6 -> V_9 ] . V_14 = V_49 ;
V_46 -> V_6 -> V_30 += V_1 -> V_55 ;
V_46 -> V_6 -> V_9 ++ ;
return V_39 ;
}
static int F_37 ( struct V_40 * V_41 , struct V_6 * V_59 )
{
T_4 V_42 = F_30 ( & V_41 -> V_43 ) ;
T_3 V_12 ;
struct V_45 V_46 ;
if ( ! F_31 ( V_42 , V_44 ) )
return - V_33 ;
V_46 . V_43 = & V_41 -> V_43 ;
V_46 . V_6 = V_59 ;
V_46 . V_56 = 0 ;
V_12 = F_32 ( V_42 , V_44 ,
F_34 , & V_46 ) ;
if ( F_33 ( V_12 ) )
return V_46 . V_56 ;
return 0 ;
}
static int T_7 F_38 ( struct V_40 * V_41 )
{
struct V_6 * V_6 ;
T_8 V_60 ;
T_1 V_9 ;
int V_56 ;
V_9 = F_29 ( V_41 ) ;
if ( V_9 <= 0 ) {
F_35 ( & V_41 -> V_43 , L_4 ) ;
return - V_33 ;
}
V_60 = sizeof( * V_6 ) + sizeof( struct V_19 ) * V_9 ;
V_6 = F_39 ( & V_41 -> V_43 , V_60 , V_61 ) ;
if ( ! V_6 )
return - V_58 ;
V_56 = F_37 ( V_41 , V_6 ) ;
if ( V_56 < 0 )
return V_56 ;
V_6 -> V_62 = F_40 ( V_41 , 0 ) ;
if ( V_6 -> V_62 <= 0 ) {
F_35 ( & V_41 -> V_43 , L_5 ) ;
return - V_63 ;
}
V_6 -> V_16 = F_41 ( V_41 -> V_43 . V_27 , V_6 -> V_30 ,
& V_64 , V_6 ) ;
if ( ! V_6 -> V_16 )
return - V_65 ;
F_42 ( V_6 -> V_62 ,
F_2 , V_6 ) ;
F_43 ( & V_41 -> V_43 , L_6 ,
V_6 -> V_62 , V_6 -> V_30 , V_6 -> V_13 [ 0 ] . V_14 ) ;
return 0 ;
}
static int T_7 F_44 ( void )
{
return F_45 ( & V_66 ) ;
}
