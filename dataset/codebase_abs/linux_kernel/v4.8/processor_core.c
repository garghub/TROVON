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
static T_2 F_9 ( struct V_1 * V_2 ,
int type , T_1 V_8 )
{
unsigned long V_33 , V_7 ;
T_2 V_34 = V_35 ;
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
T_2 T_3 F_10 ( T_1 V_8 )
{
struct V_1 * V_2 = NULL ;
T_4 V_40 ;
T_2 V_41 ;
F_11 ( V_4 , 0 ,
(struct V_5 * * ) & V_2 ,
& V_40 ) ;
if ( ! V_2 )
return V_35 ;
V_41 = F_9 ( V_2 , 1 , V_8 ) ;
F_12 ( V_2 , V_40 ) ;
return V_41 ;
}
static T_2 F_13 ( T_5 V_42 , int type , T_1 V_8 )
{
struct V_43 V_44 = { V_45 , NULL } ;
union V_46 * V_47 ;
struct V_6 * V_12 ;
T_2 V_34 = V_35 ;
if ( F_2 ( F_14 ( V_42 , L_1 , NULL , & V_44 ) ) )
goto exit;
if ( ! V_44 . V_26 || ! V_44 . V_48 )
goto exit;
V_47 = V_44 . V_48 ;
if ( V_47 -> type != V_49 ||
V_47 -> V_44 . V_26 < sizeof( struct V_6 ) ) {
goto exit;
}
V_12 = (struct V_6 * ) V_47 -> V_44 . V_48 ;
if ( V_12 -> type == V_36 )
F_4 ( V_12 , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_38 )
F_7 ( V_12 , type , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_37 )
F_6 ( V_12 , type , V_8 , & V_34 ) ;
else if ( V_12 -> type == V_39 )
F_8 ( V_12 , type , V_8 , & V_34 ) ;
exit:
F_15 ( V_44 . V_48 ) ;
return V_34 ;
}
T_2 F_16 ( T_5 V_42 , int type , T_1 V_8 )
{
T_2 V_34 ;
V_34 = F_13 ( V_42 , type , V_8 ) ;
if ( F_17 ( V_34 ) )
V_34 = F_9 ( F_1 () , type , V_8 ) ;
return V_34 ;
}
int F_18 ( T_2 V_34 , T_1 V_8 )
{
#ifdef F_19
int V_50 ;
#endif
if ( F_17 ( V_34 ) ) {
if ( V_51 <= 1 && V_8 == 0 )
return V_8 ;
else
return - V_17 ;
}
#ifdef F_19
F_20 (i) {
if ( F_21 ( V_50 ) == V_34 )
return V_50 ;
}
#else
if ( V_34 == 0 )
return V_34 ;
#endif
return - V_15 ;
}
int F_22 ( T_5 V_42 , int type , T_1 V_8 )
{
T_2 V_34 ;
V_34 = F_16 ( V_42 , type , V_8 ) ;
return F_18 ( V_34 , V_8 ) ;
}
static int F_23 ( struct V_6 * V_7 , T_1 V_52 ,
T_6 * V_53 , int * V_54 )
{
struct V_55 * V_56 = (struct V_55 * ) V_7 ;
if ( V_56 -> V_57 != V_52 )
return 0 ;
* V_53 = V_56 -> V_58 ;
* V_54 = V_56 -> V_18 ;
return 1 ;
}
static int F_24 ( T_1 V_52 , T_6 * V_53 )
{
struct V_6 * V_59 ;
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
V_59 = (struct V_6 * ) V_7 ;
if ( V_59 -> type == V_60 &&
F_23 ( V_59 , V_52 , V_53 , & V_9 ) )
break;
else
V_7 += V_59 -> V_26 ;
}
return V_9 ;
}
static int F_25 ( T_5 V_42 , T_1 V_52 ,
T_6 * V_53 )
{
struct V_43 V_44 = { V_45 , NULL } ;
struct V_6 * V_12 ;
union V_46 * V_47 ;
int V_9 = - 1 ;
if ( F_2 ( F_14 ( V_42 , L_1 , NULL , & V_44 ) ) )
goto exit;
if ( ! V_44 . V_26 || ! V_44 . V_48 )
goto exit;
V_47 = V_44 . V_48 ;
if ( V_47 -> type != V_49 ||
V_47 -> V_44 . V_26 < sizeof( struct V_6 ) )
goto exit;
V_12 = (struct V_6 * ) V_47 -> V_44 . V_48 ;
if ( V_12 -> type == V_60 )
F_23 ( V_12 , V_52 , V_53 , & V_9 ) ;
exit:
F_15 ( V_44 . V_48 ) ;
return V_9 ;
}
int F_26 ( T_5 V_42 , T_1 V_52 , T_6 * V_53 )
{
int V_9 ;
V_9 = F_25 ( V_42 , V_52 , V_53 ) ;
if ( V_9 == - 1 )
V_9 = F_24 ( V_52 , V_53 ) ;
return V_9 ;
}
