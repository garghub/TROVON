static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( ! ( V_6 -> V_8 & V_9 ) )
return - V_10 ;
if ( V_6 -> V_11 != V_3 )
return - V_12 ;
* V_4 = V_6 -> V_13 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_14 , T_1 V_3 , int * V_4 )
{
struct V_15 * V_16 =
F_2 ( V_2 , struct V_15 , V_7 ) ;
if ( ! ( V_16 -> V_8 & V_9 ) )
return - V_10 ;
if ( V_14 && ( V_16 -> V_17 == V_3 ) ) {
* V_4 = V_16 -> V_18 ;
return 0 ;
}
return - V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_14 , T_1 V_3 , int * V_4 )
{
struct V_19 * V_20 =
F_2 ( V_2 , struct V_19 , V_7 ) ;
if ( ! ( V_20 -> V_8 & V_9 ) )
return - V_10 ;
if ( V_14 ) {
if ( ( V_2 -> V_21 < 16 ) || ( V_20 -> V_17 != V_3 ) )
return - V_12 ;
} else if ( V_20 -> V_11 != V_3 )
return - V_12 ;
* V_4 = ( V_20 -> V_13 << 8 ) | V_20 -> V_22 ;
return 0 ;
}
static int F_5 ( int type , T_1 V_3 )
{
unsigned long V_23 , V_2 ;
static struct V_24 * V_25 ;
static int V_26 ;
int V_27 = - 1 ;
if ( ! V_26 ) {
if ( F_6 ( F_7 ( V_28 , 0 ,
(struct V_29 * * ) & V_25 ) ) )
V_25 = NULL ;
V_26 ++ ;
}
if ( ! V_25 )
return V_27 ;
V_2 = ( unsigned long ) V_25 ;
V_23 = V_2 + V_25 -> V_7 . V_21 ;
V_2 += sizeof( struct V_24 ) ;
while ( V_2 + sizeof( struct V_1 ) < V_23 ) {
struct V_1 * V_7 =
(struct V_1 * ) V_2 ;
if ( V_7 -> type == V_30 ) {
if ( ! F_1 ( V_7 , V_3 , & V_27 ) )
break;
} else if ( V_7 -> type == V_31 ) {
if ( ! F_3 ( V_7 , type , V_3 , & V_27 ) )
break;
} else if ( V_7 -> type == V_32 ) {
if ( ! F_4 ( V_7 , type , V_3 , & V_27 ) )
break;
}
V_2 += V_7 -> V_21 ;
}
return V_27 ;
}
static int F_8 ( T_2 V_33 , int type , T_1 V_3 )
{
struct V_34 V_35 = { V_36 , NULL } ;
union V_37 * V_38 ;
struct V_1 * V_7 ;
int V_27 = - 1 ;
if ( F_6 ( F_9 ( V_33 , L_1 , NULL , & V_35 ) ) )
goto exit;
if ( ! V_35 . V_21 || ! V_35 . V_39 )
goto exit;
V_38 = V_35 . V_39 ;
if ( V_38 -> type != V_40 ||
V_38 -> V_35 . V_21 < sizeof( struct V_1 ) ) {
goto exit;
}
V_7 = (struct V_1 * ) V_38 -> V_35 . V_39 ;
if ( V_7 -> type == V_30 )
F_1 ( V_7 , V_3 , & V_27 ) ;
else if ( V_7 -> type == V_32 )
F_4 ( V_7 , type , V_3 , & V_27 ) ;
else if ( V_7 -> type == V_31 )
F_3 ( V_7 , type , V_3 , & V_27 ) ;
exit:
F_10 ( V_35 . V_39 ) ;
return V_27 ;
}
int F_11 ( T_2 V_33 , int type , T_1 V_3 )
{
int V_27 ;
V_27 = F_8 ( V_33 , type , V_3 ) ;
if ( V_27 == - 1 )
V_27 = F_5 ( type , V_3 ) ;
return V_27 ;
}
int F_12 ( int V_27 , T_1 V_3 )
{
#ifdef F_13
int V_41 ;
#endif
if ( V_27 == - 1 ) {
if ( V_42 <= 1 && V_3 == 0 )
return V_3 ;
else
return V_27 ;
}
#ifdef F_13
F_14 (i) {
if ( F_15 ( V_41 ) == V_27 )
return V_41 ;
}
#else
if ( V_27 == 0 )
return V_27 ;
#endif
return - 1 ;
}
int F_16 ( T_2 V_33 , int type , T_1 V_3 )
{
int V_27 ;
V_27 = F_11 ( V_33 , type , V_3 ) ;
return F_12 ( V_27 , V_3 ) ;
}
