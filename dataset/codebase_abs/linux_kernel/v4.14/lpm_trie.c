static inline int F_1 ( const T_1 * V_1 , T_2 V_2 )
{
return ! ! ( V_1 [ V_2 / 8 ] & ( 1 << ( 7 - ( V_2 % 8 ) ) ) ) ;
}
static T_2 F_2 ( const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_11 ; V_10 ++ ) {
T_2 V_12 ;
V_12 = 8 - F_3 ( V_6 -> V_1 [ V_10 ] ^ V_8 -> V_1 [ V_10 ] ) ;
V_9 += V_12 ;
if ( V_9 >= V_6 -> V_9 || V_9 >= V_8 -> V_9 )
return F_4 ( V_6 -> V_9 , V_8 -> V_9 ) ;
if ( V_12 < 8 )
break;
}
return V_9 ;
}
static void * F_5 ( struct V_13 * V_14 , void * V_15 )
{
struct V_3 * V_4 = F_6 ( V_14 , struct V_3 , V_14 ) ;
struct V_5 * V_6 , * V_16 = NULL ;
struct V_7 * V_8 = V_15 ;
for ( V_6 = F_7 ( V_4 -> V_17 ) ; V_6 ; ) {
unsigned int V_18 ;
T_2 V_19 ;
V_19 = F_2 ( V_4 , V_6 , V_8 ) ;
if ( V_19 == V_4 -> V_20 ) {
V_16 = V_6 ;
break;
}
if ( V_19 < V_6 -> V_9 )
break;
if ( ! ( V_6 -> V_21 & V_22 ) )
V_16 = V_6 ;
V_18 = F_1 ( V_8 -> V_1 , V_6 -> V_9 ) ;
V_6 = F_7 ( V_6 -> V_23 [ V_18 ] ) ;
}
if ( ! V_16 )
return NULL ;
return V_16 -> V_1 + V_4 -> V_11 ;
}
static struct V_5 * F_8 ( const struct V_3 * V_4 ,
const void * V_24 )
{
struct V_5 * V_6 ;
T_2 V_25 = sizeof( struct V_5 ) + V_4 -> V_11 ;
if ( V_24 )
V_25 += V_4 -> V_14 . V_26 ;
V_6 = F_9 ( V_25 , V_27 | V_28 ,
V_4 -> V_14 . V_29 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_21 = 0 ;
if ( V_24 )
memcpy ( V_6 -> V_1 + V_4 -> V_11 , V_24 ,
V_4 -> V_14 . V_26 ) ;
return V_6 ;
}
static int F_10 ( struct V_13 * V_14 ,
void * V_15 , void * V_24 , T_3 V_21 )
{
struct V_3 * V_4 = F_6 ( V_14 , struct V_3 , V_14 ) ;
struct V_5 * V_6 , * V_30 = NULL , * V_31 = NULL ;
struct V_5 T_4 * * V_32 ;
struct V_7 * V_8 = V_15 ;
unsigned long V_33 ;
unsigned int V_18 ;
T_2 V_19 = 0 ;
int V_34 = 0 ;
if ( F_11 ( V_21 > V_35 ) )
return - V_36 ;
if ( V_8 -> V_9 > V_4 -> V_20 )
return - V_36 ;
F_12 ( & V_4 -> V_37 , V_33 ) ;
if ( V_4 -> V_38 == V_4 -> V_14 . V_39 ) {
V_34 = - V_40 ;
goto V_41;
}
V_31 = F_8 ( V_4 , V_24 ) ;
if ( ! V_31 ) {
V_34 = - V_42 ;
goto V_41;
}
V_4 -> V_38 ++ ;
V_31 -> V_9 = V_8 -> V_9 ;
F_13 ( V_31 -> V_23 [ 0 ] , NULL ) ;
F_13 ( V_31 -> V_23 [ 1 ] , NULL ) ;
memcpy ( V_31 -> V_1 , V_8 -> V_1 , V_4 -> V_11 ) ;
V_32 = & V_4 -> V_17 ;
while ( ( V_6 = F_14 ( * V_32 ,
F_15 ( & V_4 -> V_37 ) ) ) ) {
V_19 = F_2 ( V_4 , V_6 , V_8 ) ;
if ( V_6 -> V_9 != V_19 ||
V_6 -> V_9 == V_8 -> V_9 ||
V_6 -> V_9 == V_4 -> V_20 )
break;
V_18 = F_1 ( V_8 -> V_1 , V_6 -> V_9 ) ;
V_32 = & V_6 -> V_23 [ V_18 ] ;
}
if ( ! V_6 ) {
F_16 ( * V_32 , V_31 ) ;
goto V_41;
}
if ( V_6 -> V_9 == V_19 ) {
V_31 -> V_23 [ 0 ] = V_6 -> V_23 [ 0 ] ;
V_31 -> V_23 [ 1 ] = V_6 -> V_23 [ 1 ] ;
if ( ! ( V_6 -> V_21 & V_22 ) )
V_4 -> V_38 -- ;
F_16 ( * V_32 , V_31 ) ;
F_17 ( V_6 , V_43 ) ;
goto V_41;
}
if ( V_19 == V_8 -> V_9 ) {
V_18 = F_1 ( V_6 -> V_1 , V_19 ) ;
F_16 ( V_31 -> V_23 [ V_18 ] , V_6 ) ;
F_16 ( * V_32 , V_31 ) ;
goto V_41;
}
V_30 = F_8 ( V_4 , NULL ) ;
if ( ! V_30 ) {
V_34 = - V_42 ;
goto V_41;
}
V_30 -> V_9 = V_19 ;
V_30 -> V_21 |= V_22 ;
memcpy ( V_30 -> V_1 , V_6 -> V_1 , V_4 -> V_11 ) ;
if ( F_1 ( V_8 -> V_1 , V_19 ) ) {
F_16 ( V_30 -> V_23 [ 0 ] , V_6 ) ;
F_16 ( V_30 -> V_23 [ 1 ] , V_31 ) ;
} else {
F_16 ( V_30 -> V_23 [ 0 ] , V_31 ) ;
F_16 ( V_30 -> V_23 [ 1 ] , V_6 ) ;
}
F_16 ( * V_32 , V_30 ) ;
V_41:
if ( V_34 ) {
if ( V_31 )
V_4 -> V_38 -- ;
F_18 ( V_31 ) ;
F_18 ( V_30 ) ;
}
F_19 ( & V_4 -> V_37 , V_33 ) ;
return V_34 ;
}
static int F_20 ( struct V_13 * V_14 , void * V_8 )
{
return - V_44 ;
}
static struct V_13 * F_21 ( union V_45 * V_46 )
{
struct V_3 * V_4 ;
T_3 V_47 = sizeof( * V_4 ) , V_48 ;
int V_34 ;
if ( ! F_22 ( V_49 ) )
return F_23 ( - V_50 ) ;
if ( V_46 -> V_39 == 0 ||
! ( V_46 -> V_51 & V_52 ) ||
V_46 -> V_51 & ~ V_53 ||
V_46 -> V_54 < V_55 ||
V_46 -> V_54 > V_56 ||
V_46 -> V_26 < V_57 ||
V_46 -> V_26 > V_58 )
return F_23 ( - V_36 ) ;
V_4 = F_24 ( sizeof( * V_4 ) , V_59 | V_28 ) ;
if ( ! V_4 )
return F_23 ( - V_42 ) ;
V_4 -> V_14 . V_60 = V_46 -> V_60 ;
V_4 -> V_14 . V_54 = V_46 -> V_54 ;
V_4 -> V_14 . V_26 = V_46 -> V_26 ;
V_4 -> V_14 . V_39 = V_46 -> V_39 ;
V_4 -> V_14 . V_51 = V_46 -> V_51 ;
V_4 -> V_14 . V_29 = F_25 ( V_46 ) ;
V_4 -> V_11 = V_46 -> V_54 -
F_26 ( struct V_7 , V_1 ) ;
V_4 -> V_20 = V_4 -> V_11 * 8 ;
V_48 = sizeof( struct V_5 ) +
V_46 -> V_26 + V_4 -> V_11 ;
V_47 += ( T_3 ) V_46 -> V_39 * V_48 ;
if ( V_47 >= V_61 - V_62 ) {
V_34 = - V_63 ;
goto V_64;
}
V_4 -> V_14 . V_65 = F_27 ( V_47 , V_62 ) >> V_66 ;
V_34 = F_28 ( V_4 -> V_14 . V_65 ) ;
if ( V_34 )
goto V_64;
F_29 ( & V_4 -> V_37 ) ;
return & V_4 -> V_14 ;
V_64:
F_18 ( V_4 ) ;
return F_23 ( V_34 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_6 ( V_14 , struct V_3 , V_14 ) ;
struct V_5 T_4 * * V_32 ;
struct V_5 * V_6 ;
F_31 ( & V_4 -> V_37 ) ;
for (; ; ) {
V_32 = & V_4 -> V_17 ;
for (; ; ) {
V_6 = F_14 ( * V_32 ,
F_15 ( & V_4 -> V_37 ) ) ;
if ( ! V_6 )
goto V_67;
if ( F_32 ( V_6 -> V_23 [ 0 ] ) ) {
V_32 = & V_6 -> V_23 [ 0 ] ;
continue;
}
if ( F_32 ( V_6 -> V_23 [ 1 ] ) ) {
V_32 = & V_6 -> V_23 [ 1 ] ;
continue;
}
F_18 ( V_6 ) ;
F_13 ( * V_32 , NULL ) ;
break;
}
}
V_67:
F_33 ( & V_4 -> V_37 ) ;
}
static int F_34 ( struct V_13 * V_14 , void * V_8 , void * V_68 )
{
return - V_69 ;
}
