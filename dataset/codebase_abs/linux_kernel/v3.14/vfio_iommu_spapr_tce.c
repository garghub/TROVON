static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned long V_4 , V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_8 )
return - V_9 ;
if ( ! V_10 -> V_11 )
return - V_12 ;
if ( V_2 -> V_13 )
return - V_14 ;
F_2 ( & V_10 -> V_11 -> V_15 ) ;
V_6 = ( V_8 -> V_16 << V_17 ) >> V_18 ;
V_4 = V_10 -> V_11 -> V_19 + V_6 ;
V_5 = F_3 ( V_20 ) >> V_18 ;
if ( V_4 > V_5 && ! F_4 ( V_21 ) ) {
F_5 ( L_1 ,
F_3 ( V_20 ) ) ;
V_3 = - V_22 ;
} else {
V_10 -> V_11 -> V_19 += V_6 ;
V_2 -> V_13 = true ;
}
F_6 ( & V_10 -> V_11 -> V_15 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 )
return;
V_2 -> V_13 = false ;
if ( ! V_2 -> V_8 || ! V_10 -> V_11 )
return;
F_2 ( & V_10 -> V_11 -> V_15 ) ;
V_10 -> V_11 -> V_19 -= ( V_2 -> V_8 -> V_16 <<
V_17 ) >> V_18 ;
F_6 ( & V_10 -> V_11 -> V_15 ) ;
}
static void * F_8 ( unsigned long V_23 )
{
struct V_1 * V_2 ;
if ( V_23 != V_24 ) {
F_9 ( L_2 ) ;
return F_10 ( - V_25 ) ;
}
V_2 = F_11 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return F_10 ( - V_22 ) ;
F_12 ( & V_2 -> V_27 ) ;
return V_2 ;
}
static void F_13 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
F_14 ( V_2 -> V_8 && ! V_2 -> V_8 -> V_29 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_8 && V_2 -> V_8 -> V_29 )
F_15 ( V_28 , V_2 -> V_8 -> V_29 ) ;
F_16 ( & V_2 -> V_27 ) ;
F_17 ( V_2 ) ;
}
static long F_18 ( void * V_28 ,
unsigned int V_30 , unsigned long V_23 )
{
struct V_1 * V_2 = V_28 ;
unsigned long V_31 ;
long V_3 ;
switch ( V_30 ) {
case V_32 :
return ( V_23 == V_24 ) ? 1 : 0 ;
case V_33 : {
struct V_34 V_35 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( F_14 ( ! V_8 ) )
return - V_9 ;
V_31 = F_19 ( struct V_34 ,
V_36 ) ;
if ( F_20 ( & V_35 , ( void V_37 * ) V_23 , V_31 ) )
return - V_38 ;
if ( V_35 . V_39 < V_31 )
return - V_25 ;
V_35 . V_40 = V_8 -> V_41 << V_17 ;
V_35 . V_36 = V_8 -> V_16 << V_17 ;
V_35 . V_42 = 0 ;
if ( F_21 ( ( void V_37 * ) V_23 , & V_35 , V_31 ) )
return - V_38 ;
return 0 ;
}
case V_43 : {
struct V_44 V_45 ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_46 , V_47 ;
if ( ! V_8 )
return - V_9 ;
F_22 ( ! V_8 -> V_29 ) ;
V_31 = F_19 ( struct V_44 , V_48 ) ;
if ( F_20 ( & V_45 , ( void V_37 * ) V_23 , V_31 ) )
return - V_38 ;
if ( V_45 . V_39 < V_31 )
return - V_25 ;
if ( V_45 . V_42 & ~ ( V_49 |
V_50 ) )
return - V_25 ;
if ( ( V_45 . V_48 & ~ V_51 ) ||
( V_45 . V_52 & ~ V_51 ) )
return - V_25 ;
V_46 = V_45 . V_52 ;
if ( V_45 . V_42 & V_49 )
V_46 |= V_53 ;
if ( V_45 . V_42 & V_50 )
V_46 |= V_54 ;
V_3 = F_23 ( V_8 , V_45 . V_55 , V_46 ) ;
if ( V_3 )
return V_3 ;
for ( V_47 = 0 ; V_47 < ( V_45 . V_48 >> V_17 ) ; ++ V_47 ) {
V_3 = F_24 ( V_8 ,
( V_45 . V_55 >> V_17 ) + V_47 ,
V_46 ) ;
if ( V_3 )
break;
V_46 += V_56 ;
}
if ( V_3 )
F_25 ( V_8 ,
V_45 . V_55 >> V_17 , V_47 ) ;
F_26 ( V_8 ) ;
return V_3 ;
}
case V_57 : {
struct V_58 V_45 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( F_14 ( ! V_8 ) )
return - V_9 ;
V_31 = F_19 ( struct V_58 ,
V_48 ) ;
if ( F_20 ( & V_45 , ( void V_37 * ) V_23 , V_31 ) )
return - V_38 ;
if ( V_45 . V_39 < V_31 )
return - V_25 ;
if ( V_45 . V_42 )
return - V_25 ;
if ( V_45 . V_48 & ~ V_51 )
return - V_25 ;
V_3 = F_27 ( V_8 , V_45 . V_55 , 0 ,
V_45 . V_48 >> V_17 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_25 ( V_8 ,
V_45 . V_55 >> V_17 ,
V_45 . V_48 >> V_17 ) ;
F_26 ( V_8 ) ;
return V_3 ;
}
case V_59 :
F_28 ( & V_2 -> V_27 ) ;
V_3 = F_1 ( V_2 ) ;
F_29 ( & V_2 -> V_27 ) ;
return V_3 ;
case V_60 :
F_28 ( & V_2 -> V_27 ) ;
F_7 ( V_2 ) ;
F_29 ( & V_2 -> V_27 ) ;
return 0 ;
}
return - V_61 ;
}
static int F_30 ( void * V_28 ,
struct V_62 * V_62 )
{
int V_3 ;
struct V_1 * V_2 = V_28 ;
struct V_7 * V_8 = F_31 ( V_62 ) ;
F_22 ( ! V_8 ) ;
F_28 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_8 ) {
F_5 ( L_3 ,
F_32 ( V_2 -> V_8 -> V_29 ) ,
F_32 ( V_62 ) ) ;
V_3 = - V_14 ;
} else if ( V_2 -> V_13 ) {
F_9 ( L_4 ,
F_32 ( V_62 ) ) ;
V_3 = - V_14 ;
} else {
V_3 = F_33 ( V_8 ) ;
if ( ! V_3 )
V_2 -> V_8 = V_8 ;
}
F_29 ( & V_2 -> V_27 ) ;
return V_3 ;
}
static void F_15 ( void * V_28 ,
struct V_62 * V_62 )
{
struct V_1 * V_2 = V_28 ;
struct V_7 * V_8 = F_31 ( V_62 ) ;
F_22 ( ! V_8 ) ;
F_28 ( & V_2 -> V_27 ) ;
if ( V_8 != V_2 -> V_8 ) {
F_5 ( L_5 ,
F_32 ( V_62 ) ,
F_32 ( V_8 -> V_29 ) ) ;
} else {
if ( V_2 -> V_13 ) {
F_5 ( L_6 ,
F_32 ( V_8 -> V_29 ) ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_8 = NULL ;
F_34 ( V_8 ) ;
}
F_29 ( & V_2 -> V_27 ) ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_63 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_63 ) ;
}
