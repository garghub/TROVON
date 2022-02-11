static void F_1 ( T_1 * V_1 , unsigned V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
T_2 T_3 * V_4 = V_5 ;
for (; V_2 >= 4 ; V_2 -= 4 ) {
* V_3 ++ = F_2 ( * V_4 ) ;
V_4 ++ ;
}
}
static void F_3 ( const T_1 * V_6 , unsigned V_2 )
{
const T_2 * V_3 = ( const T_2 * ) V_6 ;
T_2 T_3 * V_4 = V_5 ;
for (; V_2 >= 4 ; V_2 -= 4 ) {
F_4 ( * V_4 , * V_3 ) ;
V_3 ++ ;
V_4 ++ ;
}
}
static void F_5 ( struct V_7 * V_8 , int V_9 )
{
struct V_7 * V_10 = F_6 ( V_8 ) ;
struct V_11 * V_12 ;
unsigned int V_13 ;
if ( V_9 == - V_14 )
return;
if ( V_9 )
goto V_15;
V_12 = F_7 ( V_8 ) ;
V_13 = F_8 ( V_12 ) ;
F_3 ( V_10 -> V_16 , V_13 ) ;
if ( V_8 -> V_16 != V_10 -> V_16 )
memcpy ( V_8 -> V_16 , V_10 -> V_16 , V_13 ) ;
V_15:
if ( V_8 -> V_16 != V_10 -> V_16 )
F_9 ( V_10 -> V_16 ) ;
}
static void F_10 ( struct V_17 * V_18 ,
int V_9 )
{
struct V_7 * V_8 = V_18 -> V_19 ;
F_5 ( V_8 , V_9 ) ;
F_11 ( V_8 , V_9 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_7 ( V_8 ) ;
struct V_20 * V_21 = F_13 ( V_12 ) ;
struct V_7 * V_10 = F_6 ( V_8 ) ;
T_4 V_22 ;
void * V_19 ;
T_1 * V_23 ;
unsigned int V_13 = F_8 ( V_12 ) ;
int V_9 ;
if ( V_8 -> V_24 < V_13 )
return - V_25 ;
F_14 ( V_10 , V_21 -> V_26 ) ;
V_22 = F_10 ;
V_19 = V_8 ;
V_23 = V_8 -> V_16 ;
if ( V_8 -> V_6 != V_8 -> V_1 ) {
struct V_27 V_28 = {
. V_29 = V_21 -> null ,
} ;
V_9 = F_15 (
& V_28 , V_8 -> V_1 , V_8 -> V_6 ,
V_8 -> V_30 + V_8 -> V_24 ) ;
if ( V_9 )
return V_9 ;
}
if ( F_16 ( ! F_17 ( ( unsigned long ) V_23 ,
F_18 ( V_12 ) + 1 ) ) ) {
V_23 = F_19 ( V_13 , V_8 -> V_18 . V_31 &
V_32 ? V_33 :
V_34 ) ;
if ( ! V_23 )
return - V_35 ;
memcpy ( V_23 , V_8 -> V_16 , V_13 ) ;
}
F_20 ( V_10 , V_8 -> V_18 . V_31 , V_22 , V_19 ) ;
F_21 ( V_10 , V_8 -> V_1 , V_8 -> V_1 ,
V_8 -> V_24 , V_23 ) ;
F_22 ( V_10 , V_8 -> V_30 ) ;
F_23 ( V_23 , V_21 -> V_36 , V_13 ) ;
F_24 ( V_23 , V_8 -> V_1 , V_8 -> V_30 , V_13 , 1 ) ;
F_1 ( V_23 , V_13 ) ;
V_9 = F_25 ( V_10 ) ;
F_5 ( V_8 , V_9 ) ;
return V_9 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_7 ( V_8 ) ;
struct V_20 * V_21 = F_13 ( V_12 ) ;
struct V_7 * V_10 = F_6 ( V_8 ) ;
T_4 V_22 ;
void * V_19 ;
unsigned int V_13 = F_8 ( V_12 ) ;
if ( V_8 -> V_24 < V_13 )
return - V_25 ;
F_14 ( V_10 , V_21 -> V_26 ) ;
V_22 = V_8 -> V_18 . V_37 ;
V_19 = V_8 -> V_18 . V_19 ;
F_20 ( V_10 , V_8 -> V_18 . V_31 , V_22 , V_19 ) ;
F_21 ( V_10 , V_8 -> V_6 , V_8 -> V_1 ,
V_8 -> V_24 - V_13 , V_8 -> V_16 ) ;
F_22 ( V_10 , V_8 -> V_30 + V_13 ) ;
F_24 ( V_8 -> V_16 , V_8 -> V_6 , V_8 -> V_30 , V_13 , 0 ) ;
return F_27 ( V_10 ) ;
}
static int F_28 ( struct V_38 * V_39 ,
struct V_40 * * V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_9 ;
V_43 = F_29 ( V_39 , V_41 , 0 , 0 ) ;
if ( F_30 ( V_43 ) )
return F_31 ( V_43 ) ;
V_45 = F_32 ( V_43 ) ;
V_47 = F_33 ( V_45 ) ;
V_9 = - V_25 ;
if ( V_43 -> V_47 . V_13 & ( sizeof( T_2 ) - 1 ) ||
V_43 -> V_47 . V_13 > V_48 )
goto V_49;
V_43 -> V_47 . V_50 = F_12 ;
V_43 -> V_47 . V_51 = F_26 ;
V_43 -> V_47 . V_52 = V_53 ;
V_43 -> V_47 . exit = V_54 ;
V_43 -> V_47 . V_18 . V_55 |= F_34 ( T_2 ) - 1 ;
V_43 -> V_47 . V_18 . V_56 = sizeof( struct V_20 ) ;
V_43 -> V_47 . V_18 . V_56 += V_43 -> V_47 . V_13 ;
V_43 -> free = V_57 ;
V_9 = F_35 ( V_39 , V_43 ) ;
if ( V_9 )
goto V_49;
V_15:
return V_9 ;
V_49:
V_57 ( V_43 ) ;
goto V_15;
}
static void F_36 ( struct V_58 * V_43 )
{
V_57 ( V_42 ( V_43 ) ) ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_59 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_59 ) ;
}
