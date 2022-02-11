int
F_1 ( struct V_1 * V_2 , char T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 , V_8 = 0 ;
int V_9 ;
union V_10 V_11 ;
unsigned long V_12 ;
if ( V_6 == NULL || ! F_2 ( V_2 -> V_13 ) )
return - V_14 ;
while ( V_4 >= V_15 ) {
F_3 ( V_6 , V_12 ) ;
V_8 = F_4 ( V_6 , & V_11 ) ;
if ( V_8 == - V_16 &&
! F_5 ( V_2 -> V_13 ) && V_7 == 0 ) {
F_6 ( V_6 , V_12 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 , V_12 ) ;
if ( F_8 ( V_17 ) )
V_8 = - V_18 ;
else
V_8 = F_4 ( V_6 , & V_11 ) ;
}
if ( V_8 < 0 ) {
F_6 ( V_6 , V_12 ) ;
break;
}
V_9 = F_9 ( & V_11 ) ;
if ( V_9 < V_4 ) {
F_6 ( V_6 , V_12 ) ;
break;
}
F_10 ( V_6 ) ;
F_6 ( V_6 , V_12 ) ;
if ( F_11 ( V_3 , & V_11 , V_9 ) ) {
V_8 = - V_19 ;
break;
}
V_7 += V_9 ;
V_3 += V_9 ;
V_4 -= V_9 ;
}
return V_7 > 0 ? V_7 : V_8 ;
}
int
F_12 ( struct V_1 * V_2 , const char T_1 * V_3 , int V_4 , struct V_20 * V_21 )
{
int V_7 = 0 , V_8 = 0 ;
int V_22 , V_23 ;
union V_10 V_11 ;
if ( ! F_13 ( V_2 -> V_13 ) || V_2 -> V_24 == NULL )
return - V_14 ;
while ( V_4 >= V_15 ) {
if ( F_14 ( & V_11 , V_3 , V_15 ) ) {
V_8 = - V_19 ;
break;
}
if ( V_11 . V_25 . V_26 == V_27 ) {
if ( V_7 > 0 ) {
V_8 = - V_28 ;
break;
}
V_23 = ( * ( unsigned short * ) V_11 . V_29 ) & 0xffff ;
return F_15 ( V_2 , V_11 . V_25 . V_30 ,
V_23 , V_3 , 0 , V_4 ) ;
}
if ( F_16 ( & V_11 ) ) {
if ( V_11 . V_25 . V_26 == V_31 &&
V_2 -> V_32 == V_33 ) {
V_8 = - V_28 ;
break;
}
V_22 = V_34 ;
if ( V_4 < V_22 )
break;
if ( F_14 ( V_11 . V_29 + V_15 ,
V_3 + V_15 ,
V_34 - V_15 ) ) {
V_8 = - V_19 ;
break;
}
} else {
if ( V_2 -> V_32 == V_33 ) {
V_8 = - V_28 ;
break;
}
V_22 = V_15 ;
}
if ( ( V_8 = F_17 ( V_2 , & V_11 , V_21 ) ) < 0 )
break;
V_7 += V_22 ;
V_3 += V_22 ;
V_4 -= V_22 ;
}
return V_7 > 0 ? V_7 : V_8 ;
}
static int
F_17 ( struct V_1 * V_2 , union V_10 * V_11 , struct V_20 * V_21 )
{
int V_35 = 0 ;
struct V_36 V_37 ;
if ( F_18 ( V_2 -> V_38 , V_11 ) )
return 0 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . type = V_39 ;
F_19 ( V_2 , & V_37 , V_2 -> V_40 . V_41 , V_2 -> V_40 . V_42 ) ;
if ( F_20 ( V_2 , V_11 , & V_37 ) )
return 0 ;
V_37 . time . V_43 = F_21 ( V_2 -> V_38 ) ;
if ( V_2 -> V_38 -> V_44 || ! V_2 -> V_38 -> V_45 ) {
F_22 ( V_2 , & V_37 , 0 , 0 ) ;
} else {
if ( F_5 ( V_2 -> V_13 ) )
V_35 = F_23 ( V_2 -> V_46 , & V_37 , 0 , 0 ) ;
else
V_35 = F_24 ( V_2 -> V_46 , & V_37 , V_21 , 0 , 0 ) ;
}
return V_35 ;
}
unsigned int
F_25 ( struct V_1 * V_2 , struct V_20 * V_20 , T_2 * V_47 )
{
unsigned int V_48 = 0 ;
if ( V_2 -> V_6 && F_2 ( V_2 -> V_13 ) ) {
if ( F_26 ( V_2 -> V_6 , V_20 , V_47 ) )
V_48 |= V_49 | V_50 ;
}
if ( V_2 -> V_24 && F_13 ( V_2 -> V_13 ) ) {
if ( F_27 ( V_2 -> V_46 , V_20 , V_47 ) )
V_48 |= V_51 | V_52 ;
}
return V_48 ;
}
