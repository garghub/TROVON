int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
T_1 V_6 = V_5 -> V_7 ;
T_2 V_8 = 0 ;
int V_9 = - V_10 ;
if ( F_2 ( V_2 ) )
return - V_11 ;
if ( V_5 -> V_12 != V_13 ) {
F_3 ( L_1 , V_5 -> V_12 ) ;
return V_9 ;
}
while ( V_6 > 0 ) {
V_9 = F_4 ( V_2 , V_3 , V_6 , & V_8 ) ;
if ( V_9 < 0 )
break;
V_6 -= V_9 ;
V_3 += V_9 ;
V_9 = 0 ;
}
if ( V_9 < 0 )
F_5 ( L_2 , V_9 ) ;
else
F_6 ( V_14 , L_3 , V_9 , V_2 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 , int V_15 , unsigned int V_16 ,
void * V_17 , T_3 V_18 )
{
struct V_19 * V_20 ;
if ( V_16 > V_21 ) {
F_6 ( V_22 , L_4 , V_16 ) ;
return - V_23 ;
}
if ( ! V_2 )
return - V_11 ;
V_20 = F_8 ( sizeof( * V_20 ) + V_18 , 0 ) ;
if ( ! V_20 )
return - V_24 ;
V_20 -> V_25 = V_2 ;
V_20 -> V_26 = V_15 ;
memcpy ( V_20 -> V_27 , V_17 , V_18 ) ;
F_9 ( & V_28 ) ;
if ( ! V_29 [ V_16 ] . V_30 )
F_10 ( & V_29 [ V_16 ] ) ;
F_11 ( & V_20 -> V_31 , & V_29 [ V_16 ] ) ;
F_12 ( & V_28 ) ;
F_6 ( V_14 , L_5 , V_15 , V_2 , V_16 ) ;
return 0 ;
}
int F_13 ( int V_15 , unsigned int V_16 )
{
struct V_19 * V_20 , * V_30 ;
if ( ! V_29 [ V_16 ] . V_30 )
return 0 ;
if ( ! V_15 ) {
struct V_4 V_32 ;
V_32 . V_12 = V_13 ;
V_32 . V_33 = V_34 ;
V_32 . V_35 = V_36 ;
V_32 . V_7 = sizeof( V_32 ) ;
F_14 ( V_16 , & V_32 ) ;
}
F_9 ( & V_28 ) ;
F_15 (reg, next, &kkuc_groups[group], kr_chain) {
if ( ! V_15 || ( V_15 == V_20 -> V_26 ) ) {
F_16 ( & V_20 -> V_31 ) ;
F_6 ( V_14 , L_6 ,
V_20 -> V_26 , V_20 -> V_25 , V_16 ) ;
if ( V_20 -> V_25 )
F_17 ( V_20 -> V_25 ) ;
F_18 ( V_20 ) ;
}
}
F_12 ( & V_28 ) ;
return 0 ;
}
int F_14 ( unsigned int V_16 , void * V_3 )
{
struct V_19 * V_20 ;
int V_9 = 0 ;
int V_37 = 0 ;
F_9 ( & V_28 ) ;
F_19 (reg, &kkuc_groups[group], kr_chain) {
if ( V_20 -> V_25 ) {
V_9 = F_1 ( V_20 -> V_25 , V_3 ) ;
if ( ! V_9 ) {
V_37 = 1 ;
} else if ( V_9 == - V_38 ) {
F_17 ( V_20 -> V_25 ) ;
V_20 -> V_25 = NULL ;
}
}
}
F_12 ( & V_28 ) ;
if ( V_37 )
V_9 = 0 ;
return V_9 ;
}
int F_20 ( unsigned int V_16 , T_4 V_39 ,
void * V_40 )
{
struct V_19 * V_20 ;
int V_9 = 0 ;
if ( V_16 > V_21 ) {
F_6 ( V_22 , L_4 , V_16 ) ;
return - V_23 ;
}
if ( ! V_29 [ V_16 ] . V_30 )
return 0 ;
F_21 ( & V_28 ) ;
F_19 (reg, &kkuc_groups[group], kr_chain) {
if ( V_20 -> V_25 )
V_9 = V_39 ( V_20 -> V_27 , V_40 ) ;
}
F_22 ( & V_28 ) ;
return V_9 ;
}
