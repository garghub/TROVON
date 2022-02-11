static T_1
F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return V_5 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_6 * V_3 , struct V_7 * V_4 )
{
T_2 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 = 0 ;
V_8 = F_3 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_4 ( V_2 , & V_4 -> V_8 , 0 , V_12 ) ;
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_3 -> V_13 & ~ ( V_14 | V_15 | V_16 | V_17 ) )
F_5 ( V_18 ) ;
V_4 -> V_13 = V_3 -> V_13 ;
if ( V_4 -> V_13 & ( V_14 | V_15 ) ) {
V_10 = F_6 ( V_8 , V_19 ) ;
if ( F_7 ( V_10 ) ) {
int V_20 = F_8 ( V_10 ) ;
if ( V_20 == - V_21 || V_20 == - V_22 )
V_10 = NULL ;
else {
V_11 = F_9 ( V_20 ) ;
goto V_23;
}
}
if ( V_10 == NULL ) {
struct V_24 * V_24 = V_8 -> V_25 -> V_26 ;
V_10 = F_10 ( V_24 -> V_27 , V_28 ) ;
}
V_4 -> V_29 = V_10 ;
}
if ( V_4 -> V_13 & ( V_16 | V_17 ) ) {
V_10 = F_6 ( V_8 , V_30 ) ;
if ( F_7 ( V_10 ) ) {
int V_20 = F_8 ( V_10 ) ;
if ( V_20 == - V_21 || V_20 == - V_22 )
V_10 = NULL ;
else {
V_11 = F_9 ( V_20 ) ;
goto V_23;
}
}
V_4 -> V_31 = V_10 ;
}
F_5 ( 0 ) ;
V_23:
F_11 ( V_4 -> V_29 ) ;
F_11 ( V_4 -> V_31 ) ;
F_5 ( V_11 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_32 * V_3 ,
struct V_33 * V_4 )
{
T_2 * V_8 ;
T_1 V_11 = 0 ;
V_8 = F_3 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_11 = F_4 ( V_2 , & V_4 -> V_8 , 0 , V_34 ) ;
if ( ! V_11 ) {
V_11 = F_9 ( F_13 (
V_8 , V_19 , V_3 -> V_29 ) ) ;
}
if ( ! V_11 ) {
V_11 = F_9 ( F_13 (
V_8 , V_30 , V_3 -> V_31 ) ) ;
}
F_11 ( V_3 -> V_29 ) ;
F_11 ( V_3 -> V_31 ) ;
F_5 ( V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_6 * args )
{
if ( ! ( V_35 = F_15 ( V_35 , & args -> V_8 ) ) )
return 0 ;
args -> V_13 = F_16 ( * V_35 ) ; V_35 ++ ;
return F_17 ( V_2 , V_35 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_32 * args )
{
struct V_36 * V_37 = V_2 -> V_38 . V_37 ;
unsigned int V_39 ;
int V_40 ;
if ( ! ( V_35 = F_15 ( V_35 , & args -> V_8 ) ) )
return 0 ;
args -> V_13 = F_16 ( * V_35 ++ ) ;
if ( args -> V_13 & ~ ( V_14 | V_15 | V_16 | V_17 ) ||
! F_17 ( V_2 , V_35 ) )
return 0 ;
V_39 = ( char * ) V_35 - ( char * ) V_37 -> V_41 ;
V_40 = F_19 ( & V_2 -> V_38 , V_39 , NULL ,
( args -> V_13 & V_14 ) ?
& args -> V_29 : NULL ) ;
if ( V_40 > 0 )
V_40 = F_19 ( & V_2 -> V_38 , V_39 + V_40 , NULL ,
( args -> V_13 & V_16 ) ?
& args -> V_31 : NULL ) ;
return ( V_40 > 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_7 * V_4 )
{
struct V_42 * V_42 = V_4 -> V_8 . V_25 ;
V_35 = F_21 ( V_2 , V_35 , & V_4 -> V_8 ) ;
if ( V_4 -> V_43 == 0 && V_42 && V_42 -> V_26 ) {
struct V_24 * V_24 = V_42 -> V_26 ;
struct V_36 * V_37 = V_2 -> V_44 . V_37 ;
unsigned int V_39 ;
int V_40 ;
int V_45 ;
* V_35 ++ = F_22 ( V_4 -> V_13 ) ;
if ( ! F_23 ( V_2 , V_35 ) )
return 0 ;
V_39 = ( char * ) V_35 - ( char * ) V_37 -> V_41 ;
V_2 -> V_44 . V_46 = V_45 = F_24 (
( V_4 -> V_13 & V_14 ) ? V_4 -> V_29 : NULL ,
( V_4 -> V_13 & V_16 ) ? V_4 -> V_31 : NULL ) ;
while ( V_45 > 0 ) {
if ( ! V_2 -> V_47 [ V_2 -> V_48 ++ ] )
return 0 ;
V_45 -= V_49 ;
}
V_40 = F_25 ( & V_2 -> V_44 , V_39 , V_24 ,
V_4 -> V_29 ,
V_4 -> V_13 & V_14 , 0 ) ;
if ( V_40 > 0 )
V_40 = F_25 ( & V_2 -> V_44 , V_39 + V_40 , V_24 ,
V_4 -> V_31 ,
V_4 -> V_13 & V_16 ,
V_50 ) ;
if ( V_40 <= 0 )
return 0 ;
} else
if ( ! F_23 ( V_2 , V_35 ) )
return 0 ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_33 * V_4 )
{
V_35 = F_21 ( V_2 , V_35 , & V_4 -> V_8 ) ;
return F_23 ( V_2 , V_35 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_35 ,
struct V_7 * V_4 )
{
F_28 ( & V_4 -> V_8 ) ;
F_11 ( V_4 -> V_29 ) ;
F_11 ( V_4 -> V_31 ) ;
return 1 ;
}
