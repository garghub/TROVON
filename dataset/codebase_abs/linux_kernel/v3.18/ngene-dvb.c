static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
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
static T_1 F_5 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
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
static void F_8 ( T_5 * V_19 , T_5 V_20 )
{
while ( V_20 ) {
* V_19 = F_9 ( * V_19 ) ;
V_19 ++ ;
V_20 -= 4 ;
}
}
void * F_10 ( void * V_10 , void * V_2 , T_5 V_20 , T_5 clock , T_5 V_21 )
{
struct V_8 * V_9 = V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
if ( V_21 & V_22 )
F_8 ( V_2 , V_20 ) ;
if ( V_12 -> V_23 . V_24 && V_9 -> V_25 == 2 ) {
while ( V_20 >= 188 ) {
if ( memcmp ( V_2 , V_26 , sizeof V_26 ) != 0 ) {
if ( F_3 ( & V_12 -> V_17 ) >= 188 ) {
F_11 ( & V_12 -> V_17 , V_2 , 188 ) ;
F_12 ( & V_12 -> V_17 . V_14 ) ;
#ifdef F_13
V_27 ++ ;
#endif
}
#ifdef F_13
else
V_28 ++ ;
#endif
}
#ifdef F_13
else
V_29 ++ ;
if ( V_27 % 100 == 0 && V_28 )
F_14 ( V_30 L_1 , V_31 , V_27 , V_28 , V_29 ) ;
#endif
V_2 += 188 ;
V_20 -= 188 ;
}
return NULL ;
}
if ( V_9 -> V_32 > 0 )
F_15 ( & V_9 -> V_33 , V_2 , V_20 ) ;
return NULL ;
}
void * F_16 ( void * V_10 , void * V_2 , T_5 V_20 , T_5 clock , T_5 V_21 )
{
struct V_8 * V_9 = V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
T_5 V_34 ;
V_34 = F_6 ( & V_12 -> V_13 ) ;
V_34 -= V_34 % 188 ;
if ( V_34 < V_20 )
F_17 ( V_2 + V_34 , V_20 - V_34 , V_21 ) ;
else
V_34 = V_20 ;
F_18 ( & V_12 -> V_13 , V_2 , V_34 ) ;
if ( V_21 & V_22 )
F_8 ( ( T_5 * ) V_2 , V_34 ) ;
F_19 ( & V_12 -> V_13 . V_14 ) ;
return V_2 ;
}
int F_20 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_33 ;
struct V_8 * V_9 = V_38 -> V_10 ;
if ( V_9 -> V_32 == 0 ) {
if ( ! V_9 -> V_12 -> V_39 || ! V_9 -> V_40 )
F_21 ( V_9 , 1 ) ;
}
return ++ V_9 -> V_32 ;
}
int F_22 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_33 ;
struct V_8 * V_9 = V_38 -> V_10 ;
if ( -- V_9 -> V_32 )
return V_9 -> V_32 ;
if ( ! V_9 -> V_12 -> V_39 )
F_21 ( V_9 , 0 ) ;
return 0 ;
}
int F_23 ( struct V_37 * V_41 , char * V_42 ,
int (* F_24)( struct V_35 * ) ,
int (* F_25)( struct V_35 * ) ,
void * V_10 )
{
V_41 -> V_10 = V_10 ;
V_41 -> V_43 = 256 ;
V_41 -> V_44 = 256 ;
V_41 -> F_24 = F_24 ;
V_41 -> F_25 = F_25 ;
V_41 -> V_45 = NULL ;
V_41 -> V_46 . V_47 = ( V_48 |
V_49 |
V_50 ) ;
return F_26 ( V_41 ) ;
}
int F_27 ( struct V_51 * V_51 ,
struct V_37 * V_41 ,
struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_55 * V_55 )
{
int V_56 ;
V_51 -> V_43 = 256 ;
V_51 -> V_33 = & V_41 -> V_46 ;
V_51 -> V_47 = 0 ;
V_56 = F_28 ( V_51 , V_55 ) ;
if ( V_56 < 0 )
return V_56 ;
V_53 -> V_57 = V_58 ;
V_41 -> V_46 . V_59 ( & V_41 -> V_46 , V_53 ) ;
V_54 -> V_57 = V_60 ;
V_41 -> V_46 . V_59 ( & V_41 -> V_46 , V_54 ) ;
return V_41 -> V_46 . V_61 ( & V_41 -> V_46 , V_53 ) ;
}
