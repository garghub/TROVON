int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
T_1 V_6 = V_5 -> V_7 ;
T_2 V_8 = 0 ;
T_3 V_9 ;
int V_10 = - V_11 ;
if ( F_2 ( V_2 ) )
return - V_12 ;
if ( V_5 -> V_13 != V_14 ) {
F_3 ( L_1 , V_5 -> V_13 ) ;
return V_10 ;
}
V_9 = F_4 () ;
F_5 ( V_15 ) ;
while ( V_6 > 0 ) {
V_10 = F_6 ( V_2 , ( void V_16 V_17 * ) V_3 ,
V_6 , & V_8 ) ;
if ( V_10 < 0 )
break;
V_6 -= V_10 ;
V_3 += V_10 ;
V_10 = 0 ;
}
F_5 ( V_9 ) ;
if ( V_10 < 0 )
F_7 ( L_2 , V_10 ) ;
else
F_8 ( V_18 , L_3 , V_10 , V_2 ) ;
return V_10 ;
}
int F_9 ( struct V_1 * V_2 , int V_19 , unsigned int V_20 ,
void * V_21 , T_4 V_22 )
{
struct V_23 * V_24 ;
if ( V_20 > V_25 ) {
F_8 ( V_26 , L_4 , V_20 ) ;
return - V_27 ;
}
if ( ! V_2 )
return - V_12 ;
V_24 = F_10 ( sizeof( * V_24 ) + V_22 , 0 ) ;
if ( ! V_24 )
return - V_28 ;
V_24 -> V_29 = V_2 ;
V_24 -> V_30 = V_19 ;
memcpy ( V_24 -> V_31 , V_21 , V_22 ) ;
F_11 ( & V_32 ) ;
if ( ! V_33 [ V_20 ] . V_34 )
F_12 ( & V_33 [ V_20 ] ) ;
F_13 ( & V_24 -> V_35 , & V_33 [ V_20 ] ) ;
F_14 ( & V_32 ) ;
F_8 ( V_18 , L_5 , V_19 , V_2 , V_20 ) ;
return 0 ;
}
int F_15 ( int V_19 , unsigned int V_20 )
{
struct V_23 * V_24 , * V_34 ;
if ( ! V_33 [ V_20 ] . V_34 )
return 0 ;
if ( ! V_19 ) {
struct V_4 V_36 ;
V_36 . V_13 = V_14 ;
V_36 . V_37 = V_38 ;
V_36 . V_39 = V_40 ;
V_36 . V_7 = sizeof( V_36 ) ;
F_16 ( V_20 , & V_36 ) ;
}
F_11 ( & V_32 ) ;
F_17 (reg, next, &kkuc_groups[group], kr_chain) {
if ( ! V_19 || ( V_19 == V_24 -> V_30 ) ) {
F_18 ( & V_24 -> V_35 ) ;
F_8 ( V_18 , L_6 ,
V_24 -> V_30 , V_24 -> V_29 , V_20 ) ;
if ( V_24 -> V_29 )
F_19 ( V_24 -> V_29 ) ;
F_20 ( V_24 ) ;
}
}
F_14 ( & V_32 ) ;
return 0 ;
}
int F_16 ( unsigned int V_20 , void * V_3 )
{
struct V_23 * V_24 ;
int V_10 = 0 ;
int V_41 = 0 ;
F_11 ( & V_32 ) ;
F_21 (reg, &kkuc_groups[group], kr_chain) {
if ( V_24 -> V_29 ) {
V_10 = F_1 ( V_24 -> V_29 , V_3 ) ;
if ( ! V_10 ) {
V_41 = 1 ;
} else if ( V_10 == - V_42 ) {
F_19 ( V_24 -> V_29 ) ;
V_24 -> V_29 = NULL ;
}
}
}
F_14 ( & V_32 ) ;
if ( V_41 )
V_10 = 0 ;
return V_10 ;
}
int F_22 ( unsigned int V_20 , T_5 V_43 ,
void * V_44 )
{
struct V_23 * V_24 ;
int V_10 = 0 ;
if ( V_20 > V_25 ) {
F_8 ( V_26 , L_4 , V_20 ) ;
return - V_27 ;
}
if ( ! V_33 [ V_20 ] . V_34 )
return 0 ;
F_23 ( & V_32 ) ;
F_21 (reg, &kkuc_groups[group], kr_chain) {
if ( V_24 -> V_29 )
V_10 = V_43 ( V_24 -> V_31 , V_44 ) ;
}
F_24 ( & V_32 ) ;
return V_10 ;
}
