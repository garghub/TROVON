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
T_1 V_8 , int * V_9 )
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
int V_19 , T_1 V_8 , int * V_9 )
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
int V_19 , T_1 V_8 , int * V_9 )
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
static int F_8 ( int type , T_1 V_8 )
{
unsigned long V_28 , V_7 ;
int V_29 = - 1 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return V_29 ;
V_7 = ( unsigned long ) V_2 ;
V_28 = V_7 + V_2 -> V_12 . V_26 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_28 ) {
struct V_6 * V_12 =
(struct V_6 * ) V_7 ;
if ( V_12 -> type == V_30 ) {
if ( ! F_4 ( V_12 , V_8 , & V_29 ) )
break;
} else if ( V_12 -> type == V_31 ) {
if ( ! F_6 ( V_12 , type , V_8 , & V_29 ) )
break;
} else if ( V_12 -> type == V_32 ) {
if ( ! F_7 ( V_12 , type , V_8 , & V_29 ) )
break;
}
V_7 += V_12 -> V_26 ;
}
return V_29 ;
}
static int F_9 ( T_2 V_33 , int type , T_1 V_8 )
{
struct V_34 V_35 = { V_36 , NULL } ;
union V_37 * V_38 ;
struct V_6 * V_12 ;
int V_29 = - 1 ;
if ( F_2 ( F_10 ( V_33 , L_1 , NULL , & V_35 ) ) )
goto exit;
if ( ! V_35 . V_26 || ! V_35 . V_39 )
goto exit;
V_38 = V_35 . V_39 ;
if ( V_38 -> type != V_40 ||
V_38 -> V_35 . V_26 < sizeof( struct V_6 ) ) {
goto exit;
}
V_12 = (struct V_6 * ) V_38 -> V_35 . V_39 ;
if ( V_12 -> type == V_30 )
F_4 ( V_12 , V_8 , & V_29 ) ;
else if ( V_12 -> type == V_32 )
F_7 ( V_12 , type , V_8 , & V_29 ) ;
else if ( V_12 -> type == V_31 )
F_6 ( V_12 , type , V_8 , & V_29 ) ;
exit:
F_11 ( V_35 . V_39 ) ;
return V_29 ;
}
int F_12 ( T_2 V_33 , int type , T_1 V_8 )
{
int V_29 ;
V_29 = F_9 ( V_33 , type , V_8 ) ;
if ( V_29 == - 1 )
V_29 = F_8 ( type , V_8 ) ;
return V_29 ;
}
int F_13 ( int V_29 , T_1 V_8 )
{
#ifdef F_14
int V_41 ;
#endif
if ( V_29 == - 1 ) {
if ( V_42 <= 1 && V_8 == 0 )
return V_8 ;
else
return V_29 ;
}
#ifdef F_14
F_15 (i) {
if ( F_16 ( V_41 ) == V_29 )
return V_41 ;
}
#else
if ( V_29 == 0 )
return V_29 ;
#endif
return - 1 ;
}
int F_17 ( T_2 V_33 , int type , T_1 V_8 )
{
int V_29 ;
V_29 = F_12 ( V_33 , type , V_8 ) ;
return F_13 ( V_29 , V_8 ) ;
}
static int F_18 ( struct V_6 * V_7 , T_1 V_43 ,
T_3 * V_44 , int * V_45 )
{
struct V_46 * V_47 = (struct V_46 * ) V_7 ;
if ( V_47 -> V_48 != V_43 )
return 0 ;
* V_44 = V_47 -> V_49 ;
* V_45 = V_47 -> V_18 ;
return 1 ;
}
static int F_19 ( T_1 V_43 , T_3 * V_44 )
{
struct V_6 * V_50 ;
unsigned long V_28 , V_7 ;
struct V_1 * V_2 ;
int V_9 = - 1 ;
V_2 = F_1 () ;
if ( ! V_2 )
return V_9 ;
V_7 = ( unsigned long ) V_2 ;
V_28 = V_7 + V_2 -> V_12 . V_26 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_28 ) {
V_50 = (struct V_6 * ) V_7 ;
if ( V_50 -> type == V_51 &&
F_18 ( V_50 , V_43 , V_44 , & V_9 ) )
break;
else
V_7 += V_50 -> V_26 ;
}
return V_9 ;
}
static int F_20 ( T_2 V_33 , T_1 V_43 ,
T_3 * V_44 )
{
struct V_34 V_35 = { V_36 , NULL } ;
struct V_6 * V_12 ;
union V_37 * V_38 ;
int V_9 = - 1 ;
if ( F_2 ( F_10 ( V_33 , L_1 , NULL , & V_35 ) ) )
goto exit;
if ( ! V_35 . V_26 || ! V_35 . V_39 )
goto exit;
V_38 = V_35 . V_39 ;
if ( V_38 -> type != V_40 ||
V_38 -> V_35 . V_26 < sizeof( struct V_6 ) )
goto exit;
V_12 = (struct V_6 * ) V_38 -> V_35 . V_39 ;
if ( V_12 -> type == V_51 )
F_18 ( V_12 , V_43 , V_44 , & V_9 ) ;
exit:
F_11 ( V_35 . V_39 ) ;
return V_9 ;
}
int F_21 ( T_2 V_33 , T_1 V_43 , T_3 * V_44 )
{
int V_9 ;
V_9 = F_20 ( V_33 , V_43 , V_44 ) ;
if ( V_9 == - 1 )
V_9 = F_19 ( V_43 , V_44 ) ;
return V_9 ;
}
