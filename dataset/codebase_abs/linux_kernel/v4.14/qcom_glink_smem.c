static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
void * V_6 ;
T_2 V_7 ;
T_2 V_8 ;
if ( ! V_4 -> V_6 ) {
V_6 = F_3 ( V_4 -> V_9 ,
V_10 , & V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( L_1 ,
F_6 ( V_6 ) ) ;
return 0 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_11 . V_12 = V_5 ;
}
V_7 = F_7 ( * V_4 -> V_7 ) ;
V_8 = F_7 ( * V_4 -> V_8 ) ;
if ( V_7 < V_8 )
return V_4 -> V_11 . V_12 - V_8 + V_7 ;
else
return V_7 - V_8 ;
}
static void F_8 ( struct V_1 * V_2 ,
void * V_13 , unsigned int V_14 , T_1 V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_2 V_8 ;
V_8 = F_7 ( * V_4 -> V_8 ) ;
V_8 += V_14 ;
if ( V_8 >= V_4 -> V_11 . V_12 )
V_8 -= V_4 -> V_11 . V_12 ;
V_5 = F_9 ( T_1 , V_15 , V_4 -> V_11 . V_12 - V_8 ) ;
if ( V_5 ) {
F_10 ( V_13 , V_4 -> V_6 + V_8 ,
V_5 / sizeof( T_2 ) ) ;
}
if ( V_5 != V_15 ) {
F_10 ( V_13 + V_5 , V_4 -> V_6 ,
( V_15 - V_5 ) / sizeof( T_2 ) ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_8 ;
V_8 = F_7 ( * V_4 -> V_8 ) ;
V_8 += V_15 ;
if ( V_8 > V_4 -> V_11 . V_12 )
V_8 -= V_4 -> V_11 . V_12 ;
* V_4 -> V_8 = F_12 ( V_8 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_7 ;
T_2 V_8 ;
T_2 V_16 ;
V_7 = F_7 ( * V_4 -> V_7 ) ;
V_8 = F_7 ( * V_4 -> V_8 ) ;
if ( V_8 <= V_7 )
V_16 = V_4 -> V_11 . V_12 - V_7 + V_8 ;
else
V_16 = V_8 - V_7 ;
if ( V_16 < ( V_17 + V_18 ) )
V_16 = 0 ;
else
V_16 -= V_17 + V_18 ;
return V_16 ;
}
static unsigned int F_14 ( struct V_3 * V_4 ,
unsigned int V_7 ,
const void * V_13 , T_1 V_15 )
{
T_1 V_5 ;
V_5 = F_9 ( T_1 , V_15 , V_4 -> V_11 . V_12 - V_7 ) ;
if ( V_5 )
memcpy ( V_4 -> V_6 + V_7 , V_13 , V_5 ) ;
if ( V_5 != V_15 )
memcpy ( V_4 -> V_6 , V_13 + V_5 , V_15 - V_5 ) ;
V_7 += V_15 ;
if ( V_7 >= V_4 -> V_11 . V_12 )
V_7 -= V_4 -> V_11 . V_12 ;
return V_7 ;
}
static void F_15 ( struct V_1 * V_19 ,
const void * V_20 , T_1 V_21 ,
const void * V_13 , T_1 V_22 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
unsigned int V_7 ;
V_7 = F_7 ( * V_4 -> V_7 ) ;
V_7 = F_14 ( V_4 , V_7 , V_20 , V_21 ) ;
V_7 = F_14 ( V_4 , V_7 , V_13 , V_22 ) ;
V_7 = F_16 ( V_7 , 8 ) ;
if ( V_7 >= V_4 -> V_11 . V_12 )
V_7 -= V_4 -> V_11 . V_12 ;
* V_4 -> V_7 = F_12 ( V_7 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
F_18 ( V_24 ) ;
}
struct V_25 * F_19 ( struct V_23 * V_26 ,
struct V_27 * V_28 )
{
struct V_3 * V_29 ;
struct V_3 * V_30 ;
struct V_25 * V_31 ;
struct V_23 * V_24 ;
T_2 V_9 ;
T_3 * V_32 ;
T_1 V_33 ;
int V_34 ;
V_24 = F_20 ( sizeof( * V_24 ) , V_35 ) ;
if ( ! V_24 )
return F_21 ( - V_36 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_37 = V_28 ;
V_24 -> V_38 = F_17 ;
F_22 ( V_24 , L_2 , V_28 -> V_26 -> V_39 , V_28 -> V_39 ) ;
V_34 = F_23 ( V_24 ) ;
if ( V_34 ) {
F_5 ( L_3 ) ;
return F_21 ( V_34 ) ;
}
V_34 = F_24 ( V_24 -> V_37 , L_4 ,
& V_9 ) ;
if ( V_34 ) {
F_25 ( V_24 , L_5 ) ;
goto V_40;
}
V_29 = F_26 ( V_24 , sizeof( * V_29 ) , V_35 ) ;
V_30 = F_26 ( V_24 , sizeof( * V_30 ) , V_35 ) ;
if ( ! V_29 || ! V_30 ) {
V_34 = - V_36 ;
goto V_40;
}
V_34 = F_27 ( V_9 ,
V_41 , 32 ) ;
if ( V_34 && V_34 != - V_42 ) {
F_25 ( V_24 , L_6 ) ;
goto V_40;
}
V_32 = F_3 ( V_9 ,
V_41 , & V_33 ) ;
if ( F_4 ( V_32 ) ) {
F_25 ( V_24 , L_7 ) ;
V_34 = F_6 ( V_32 ) ;
goto V_40;
}
if ( V_33 != 32 ) {
F_25 ( V_24 , L_8 ) ;
V_34 = - V_43 ;
goto V_40;
}
V_30 -> V_8 = & V_32 [ 0 ] ;
V_30 -> V_7 = & V_32 [ 1 ] ;
V_29 -> V_8 = & V_32 [ 2 ] ;
V_29 -> V_7 = & V_32 [ 3 ] ;
V_34 = F_27 ( V_9 , V_44 ,
V_45 ) ;
if ( V_34 && V_34 != - V_42 ) {
F_25 ( V_24 , L_9 ) ;
goto V_40;
}
V_30 -> V_6 = F_3 ( V_9 , V_44 ,
& V_30 -> V_11 . V_12 ) ;
if ( F_4 ( V_30 -> V_6 ) ) {
F_25 ( V_24 , L_10 ) ;
V_34 = F_6 ( V_30 -> V_6 ) ;
goto V_40;
}
V_29 -> V_11 . V_16 = F_1 ;
V_29 -> V_11 . V_46 = F_8 ;
V_29 -> V_11 . V_47 = F_11 ;
V_29 -> V_9 = V_9 ;
V_30 -> V_11 . V_16 = F_13 ;
V_30 -> V_11 . V_48 = F_15 ;
V_30 -> V_9 = V_9 ;
* V_29 -> V_8 = 0 ;
* V_30 -> V_7 = 0 ;
V_31 = F_28 ( V_24 ,
V_49 ,
& V_29 -> V_11 , & V_30 -> V_11 ,
false ) ;
if ( F_4 ( V_31 ) ) {
V_34 = F_6 ( V_31 ) ;
goto V_40;
}
return V_31 ;
V_40:
F_29 ( V_24 ) ;
return F_21 ( V_34 ) ;
}
void F_30 ( struct V_25 * V_31 )
{
F_31 ( V_31 ) ;
F_32 ( V_31 ) ;
}
