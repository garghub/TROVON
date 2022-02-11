static struct V_1 * F_1 ( void )
{
static struct V_1 * V_2 ;
static int V_3 ;
if ( ! V_3 ) {
if ( F_2 ( F_3 ( V_4 , 0 ,
(struct V_5 * * ) & V_2 ) ) )
V_2 = NULL ;
V_3 ++ ;
}
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 ,
T_1 V_8 , T_2 * V_9 )
{
struct V_10 * V_11 =
F_5 ( V_7 , struct V_10 , V_12 ) ;
if ( ! ( V_11 -> V_13 & V_14 ) )
return - V_15 ;
if ( V_11 -> V_16 != V_8 )
return - V_17 ;
* V_9 = V_11 -> V_18 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
int V_19 , T_1 V_8 , T_2 * V_9 )
{
struct V_20 * V_21 =
F_5 ( V_7 , struct V_20 , V_12 ) ;
if ( ! ( V_21 -> V_13 & V_14 ) )
return - V_15 ;
if ( V_19 && ( V_21 -> V_22 == V_8 ) ) {
* V_9 = V_21 -> V_23 ;
return 0 ;
}
return - V_17 ;
}
static int F_7 ( struct V_6 * V_7 ,
int V_19 , T_1 V_8 , T_2 * V_9 )
{
struct V_24 * V_25 =
F_5 ( V_7 , struct V_24 , V_12 ) ;
if ( ! ( V_25 -> V_13 & V_14 ) )
return - V_15 ;
if ( V_19 ) {
if ( ( V_7 -> V_26 < 16 ) || ( V_25 -> V_22 != V_8 ) )
return - V_17 ;
} else if ( V_25 -> V_16 != V_8 )
return - V_17 ;
* V_9 = ( V_25 -> V_18 << 8 ) | V_25 -> V_27 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
int V_19 , T_1 V_8 , T_2 * V_28 )
{
struct V_29 * V_30 =
F_5 ( V_7 , struct V_29 , V_12 ) ;
if ( ! ( V_30 -> V_31 & V_14 ) )
return - V_15 ;
if ( V_19 && ( V_30 -> V_22 == V_8 ) ) {
* V_28 = V_30 -> V_32 ;
return 0 ;
}
return - V_17 ;
}
static T_2 F_9 ( int type , T_1 V_8 )
{
unsigned long V_33 , V_7 ;
T_2 V_34 = V_35 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return V_34 ;
V_7 = ( unsigned long ) V_2 ;
V_33 = V_7 + V_2 -> V_12 . V_26 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_33 ) {
struct V_6 * V_12 =
(struct V_6 * ) V_7 ;
if ( V_12 -> type == V_36 ) {
if ( ! F_4 ( V_12 , V_8 , & V_34 ) )
break;
} else if ( V_12 -> type == V_37 ) {
if ( ! F_6 ( V_12 , type , V_8 , & V_34 ) )
break;
} else if ( V_12 -> type == V_38 ) {
if ( ! F_7 ( V_12 , type , V_8 , & V_34 ) )
break;
} else if ( V_12 -> type == V_39 ) {
if ( ! F_8 ( V_12 , type , V_8 , & V_34 ) )
break;
}
V_7 += V_12 -> V_26 ;
}
return V_34 ;
}
static T_2 F_10 ( T_3 V_40 , int type , T_1 V_8 )
{
struct V_41 V_42 = { V_43 , NULL } ;
union V_44 * V_45 ;
struct V_6 * V_12 ;
T_2 V_34 = V_35 ;
if ( F_2 ( F_11 ( V_40 , L_1 , NULL , & V_42 ) ) )
goto exit;
if ( ! V_42 . V_26 || ! V_42 . V_46 )
goto exit;
V_45 = V_42 . V_46 ;
if ( V_45 -> type != V_47 ||
V_45 -> V_42 . V_26 < sizeof( struct V_6 ) ) {
goto exit;
}
V_12 = (struct V_6 * ) V_45 -> V_42 . V_46 ;
if ( V_12 -> type == V_36 )
F_4 ( V_12 , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_38 )
F_7 ( V_12 , type , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_37 )
F_6 ( V_12 , type , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_39 )
F_8 ( V_12 , type , V_8 , & V_34 ) ;
exit:
F_12 ( V_42 . V_46 ) ;
return V_34 ;
}
T_2 F_13 ( T_3 V_40 , int type , T_1 V_8 )
{
T_2 V_34 ;
V_34 = F_10 ( V_40 , type , V_8 ) ;
if ( F_14 ( V_34 ) )
V_34 = F_9 ( type , V_8 ) ;
return V_34 ;
}
int F_15 ( T_2 V_34 , T_1 V_8 )
{
#ifdef F_16
int V_48 ;
#endif
if ( F_14 ( V_34 ) ) {
if ( V_49 <= 1 && V_8 == 0 )
return V_8 ;
else
return - V_17 ;
}
#ifdef F_16
F_17 (i) {
if ( F_18 ( V_48 ) == V_34 )
return V_48 ;
}
#else
if ( V_34 == 0 )
return V_34 ;
#endif
return - V_15 ;
}
int F_19 ( T_3 V_40 , int type , T_1 V_8 )
{
T_2 V_34 ;
V_34 = F_13 ( V_40 , type , V_8 ) ;
return F_15 ( V_34 , V_8 ) ;
}
static int F_20 ( struct V_6 * V_7 , T_1 V_50 ,
T_4 * V_51 , int * V_52 )
{
struct V_53 * V_54 = (struct V_53 * ) V_7 ;
if ( V_54 -> V_55 != V_50 )
return 0 ;
* V_51 = V_54 -> V_56 ;
* V_52 = V_54 -> V_18 ;
return 1 ;
}
static int F_21 ( T_1 V_50 , T_4 * V_51 )
{
struct V_6 * V_57 ;
unsigned long V_33 , V_7 ;
struct V_1 * V_2 ;
int V_9 = - 1 ;
V_2 = F_1 () ;
if ( ! V_2 )
return V_9 ;
V_7 = ( unsigned long ) V_2 ;
V_33 = V_7 + V_2 -> V_12 . V_26 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_33 ) {
V_57 = (struct V_6 * ) V_7 ;
if ( V_57 -> type == V_58 &&
F_20 ( V_57 , V_50 , V_51 , & V_9 ) )
break;
else
V_7 += V_57 -> V_26 ;
}
return V_9 ;
}
static int F_22 ( T_3 V_40 , T_1 V_50 ,
T_4 * V_51 )
{
struct V_41 V_42 = { V_43 , NULL } ;
struct V_6 * V_12 ;
union V_44 * V_45 ;
int V_9 = - 1 ;
if ( F_2 ( F_11 ( V_40 , L_1 , NULL , & V_42 ) ) )
goto exit;
if ( ! V_42 . V_26 || ! V_42 . V_46 )
goto exit;
V_45 = V_42 . V_46 ;
if ( V_45 -> type != V_47 ||
V_45 -> V_42 . V_26 < sizeof( struct V_6 ) )
goto exit;
V_12 = (struct V_6 * ) V_45 -> V_42 . V_46 ;
if ( V_12 -> type == V_58 )
F_20 ( V_12 , V_50 , V_51 , & V_9 ) ;
exit:
F_12 ( V_42 . V_46 ) ;
return V_9 ;
}
int F_23 ( T_3 V_40 , T_1 V_50 , T_4 * V_51 )
{
int V_9 ;
V_9 = F_22 ( V_40 , V_50 , V_51 ) ;
if ( V_9 == - 1 )
V_9 = F_21 ( V_50 , V_51 ) ;
return V_9 ;
}
