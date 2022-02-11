static T_1 F_1 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
if ( F_2 ( V_12 -> V_13 . V_14 ,
F_3
( & V_12 -> V_13 ) >= V_3 ) < 0 )
return 0 ;
F_4 ( & V_12 -> V_13 , V_2 , V_3 ) ;
return V_3 ;
}
static T_1 F_5 ( struct V_1 * V_1 , char * V_2 ,
T_2 V_3 , T_3 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_15 , V_16 ;
V_15 = V_3 ;
while ( V_15 ) {
if ( F_2 (
V_12 -> V_17 . V_14 ,
F_6 ( & V_12 -> V_17 ) > 0 ) < 0 )
return - V_18 ;
V_16 = F_6 ( & V_12 -> V_17 ) ;
if ( V_16 > V_15 )
V_16 = V_15 ;
F_7 ( & V_12 -> V_17 , V_2 , V_16 ) ;
V_15 -= V_16 ;
V_2 += V_16 ;
}
return V_3 ;
}
static void F_8 ( T_4 * V_19 , T_4 V_20 )
{
while ( V_20 ) {
* V_19 = F_9 ( * V_19 ) ;
V_19 ++ ;
V_20 -= 4 ;
}
}
void * F_10 ( void * V_10 , void * V_2 , T_4 V_20 , T_4 clock , T_4 V_21 )
{
struct V_8 * V_9 = V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
if ( V_21 & V_22 )
F_8 ( V_2 , V_20 ) ;
if ( V_12 -> V_23 . V_24 && V_9 -> V_25 == 2 ) {
if ( F_3 ( & V_12 -> V_17 ) > V_20 ) {
F_4 ( & V_12 -> V_17 , V_2 , V_20 ) ;
F_11 ( & V_12 -> V_17 . V_14 ) ;
}
return 0 ;
}
if ( V_9 -> V_26 > 0 ) {
F_12 ( & V_9 -> V_27 , V_2 , V_20 ) ;
}
return NULL ;
}
void * F_13 ( void * V_10 , void * V_2 , T_4 V_20 , T_4 clock , T_4 V_21 )
{
struct V_8 * V_9 = V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
T_4 V_28 ;
V_28 = F_6 ( & V_12 -> V_13 ) ;
V_28 -= V_28 % 188 ;
if ( V_28 < V_20 )
F_14 ( V_2 + V_28 , V_20 - V_28 , V_21 ) ;
else
V_28 = V_20 ;
F_15 ( & V_12 -> V_13 , V_2 , V_28 ) ;
if ( V_21 & V_22 )
F_8 ( ( T_4 * ) V_2 , V_28 ) ;
F_11 ( & V_12 -> V_13 . V_14 ) ;
return V_2 ;
}
int F_16 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_27 ;
struct V_8 * V_9 = V_32 -> V_10 ;
if ( V_9 -> V_26 == 0 ) {
if ( ! V_9 -> V_12 -> V_33 || ! V_9 -> V_34 )
F_17 ( V_9 , 1 ) ;
}
return ++ V_9 -> V_26 ;
}
int F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_27 ;
struct V_8 * V_9 = V_32 -> V_10 ;
if ( -- V_9 -> V_26 )
return V_9 -> V_26 ;
if ( ! V_9 -> V_12 -> V_33 )
F_17 ( V_9 , 0 ) ;
return 0 ;
}
int F_19 ( struct V_31 * V_35 , char * V_36 ,
int (* F_20)( struct V_29 * ) ,
int (* F_21)( struct V_29 * ) ,
void * V_10 )
{
V_35 -> V_10 = V_10 ;
V_35 -> V_37 = 256 ;
V_35 -> V_38 = 256 ;
V_35 -> F_20 = F_20 ;
V_35 -> F_21 = F_21 ;
V_35 -> V_39 = NULL ;
V_35 -> V_40 . V_41 = ( V_42 |
V_43 |
V_44 ) ;
return F_22 ( V_35 ) ;
}
int F_23 ( struct V_45 * V_45 ,
struct V_31 * V_35 ,
struct V_46 * V_47 ,
struct V_46 * V_48 ,
struct V_49 * V_49 )
{
int V_50 ;
V_45 -> V_37 = 256 ;
V_45 -> V_27 = & V_35 -> V_40 ;
V_45 -> V_41 = 0 ;
V_50 = F_24 ( V_45 , V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
V_47 -> V_51 = V_52 ;
V_35 -> V_40 . V_53 ( & V_35 -> V_40 , V_47 ) ;
V_48 -> V_51 = V_54 ;
V_35 -> V_40 . V_53 ( & V_35 -> V_40 , V_48 ) ;
return V_35 -> V_40 . V_55 ( & V_35 -> V_40 , V_47 ) ;
}
