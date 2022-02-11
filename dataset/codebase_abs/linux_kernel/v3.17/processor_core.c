static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 ;
if ( ! ( V_6 -> V_7 & V_8 ) )
return - V_9 ;
if ( V_6 -> V_10 != V_3 )
return - V_11 ;
* V_4 = V_6 -> V_12 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_13 , T_1 V_3 , int * V_4 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_2 ;
if ( ! ( V_15 -> V_7 & V_8 ) )
return - V_9 ;
if ( V_13 && ( V_15 -> V_16 == V_3 ) ) {
* V_4 = V_15 -> V_17 ;
return 0 ;
}
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_13 , T_1 V_3 , int * V_4 )
{
struct V_18 * V_19 =
(struct V_18 * ) V_2 ;
if ( ! ( V_19 -> V_7 & V_8 ) )
return - V_9 ;
if ( V_13 ) {
if ( ( V_2 -> V_20 < 16 ) || ( V_19 -> V_16 != V_3 ) )
return - V_11 ;
} else if ( V_19 -> V_10 != V_3 )
return - V_11 ;
* V_4 = ( V_19 -> V_12 << 8 ) | V_19 -> V_21 ;
return 0 ;
}
static int F_4 ( int type , T_1 V_3 )
{
unsigned long V_22 , V_2 ;
static struct V_23 * V_24 ;
static int V_25 ;
int V_4 = - 1 ;
if ( ! V_25 ) {
if ( F_5 ( F_6 ( V_26 , 0 ,
(struct V_27 * * ) & V_24 ) ) )
V_24 = NULL ;
V_25 ++ ;
}
if ( ! V_24 )
return V_4 ;
V_2 = ( unsigned long ) V_24 ;
V_22 = V_2 + V_24 -> V_28 . V_20 ;
V_2 += sizeof( struct V_23 ) ;
while ( V_2 + sizeof( struct V_1 ) < V_22 ) {
struct V_1 * V_28 =
(struct V_1 * ) V_2 ;
if ( V_28 -> type == V_29 ) {
if ( ! F_1 ( V_28 , V_3 , & V_4 ) )
break;
} else if ( V_28 -> type == V_30 ) {
if ( ! F_2 ( V_28 , type , V_3 , & V_4 ) )
break;
} else if ( V_28 -> type == V_31 ) {
if ( ! F_3 ( V_28 , type , V_3 , & V_4 ) )
break;
}
V_2 += V_28 -> V_20 ;
}
return V_4 ;
}
static int F_7 ( T_2 V_32 , int type , T_1 V_3 )
{
struct V_33 V_34 = { V_35 , NULL } ;
union V_36 * V_37 ;
struct V_1 * V_28 ;
int V_4 = - 1 ;
if ( F_5 ( F_8 ( V_32 , L_1 , NULL , & V_34 ) ) )
goto exit;
if ( ! V_34 . V_20 || ! V_34 . V_38 )
goto exit;
V_37 = V_34 . V_38 ;
if ( V_37 -> type != V_39 ||
V_37 -> V_34 . V_20 < sizeof( struct V_1 ) ) {
goto exit;
}
V_28 = (struct V_1 * ) V_37 -> V_34 . V_38 ;
if ( V_28 -> type == V_29 ) {
F_1 ( V_28 , V_3 , & V_4 ) ;
} else if ( V_28 -> type == V_31 ) {
F_3 ( V_28 , type , V_3 , & V_4 ) ;
} else if ( V_28 -> type == V_30 ) {
F_2 ( V_28 , type , V_3 , & V_4 ) ;
}
exit:
F_9 ( V_34 . V_38 ) ;
return V_4 ;
}
int F_10 ( T_2 V_32 , int type , T_1 V_3 )
{
int V_4 ;
V_4 = F_7 ( V_32 , type , V_3 ) ;
if ( V_4 == - 1 )
V_4 = F_4 ( type , V_3 ) ;
return V_4 ;
}
int F_11 ( int V_4 , T_1 V_3 )
{
#ifdef F_12
int V_40 ;
#endif
if ( V_4 == - 1 ) {
if ( V_41 <= 1 && V_3 == 0 )
return V_3 ;
else
return V_4 ;
}
#ifdef F_12
F_13 (i) {
if ( F_14 ( V_40 ) == V_4 )
return V_40 ;
}
#else
if ( V_4 == 0 )
return V_4 ;
#endif
return - 1 ;
}
int F_15 ( T_2 V_32 , int type , T_1 V_3 )
{
int V_4 ;
V_4 = F_10 ( V_32 , type , V_3 ) ;
return F_11 ( V_4 , V_3 ) ;
}
