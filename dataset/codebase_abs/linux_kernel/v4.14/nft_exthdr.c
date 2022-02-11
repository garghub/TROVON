static unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
if ( V_1 [ V_2 ] <= V_3 || V_1 [ V_2 + 1 ] == 0 )
return 1 ;
else
return V_1 [ V_2 + 1 ] ;
}
static void F_2 ( const struct V_4 * V_5 ,
struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_5 ) ;
T_2 * V_12 = & V_7 -> V_13 [ V_11 -> V_14 ] ;
unsigned int V_2 = 0 ;
int V_15 ;
V_15 = F_4 ( V_9 -> V_16 , & V_2 , V_11 -> type , NULL , NULL ) ;
if ( V_11 -> V_17 & V_18 ) {
* V_12 = ( V_15 >= 0 ) ;
return;
} else if ( V_15 < 0 ) {
goto V_15;
}
V_2 += V_11 -> V_2 ;
V_12 [ V_11 -> V_19 / V_20 ] = 0 ;
if ( F_5 ( V_9 -> V_16 , V_2 , V_12 , V_11 -> V_19 ) < 0 )
goto V_15;
return;
V_15:
V_7 -> V_21 . V_22 = V_23 ;
}
static void *
F_6 ( const struct V_8 * V_9 ,
unsigned int V_19 , void * V_24 , unsigned int * V_25 )
{
struct V_26 * V_27 ;
if ( ! V_9 -> V_28 || V_9 -> V_29 != V_30 )
return NULL ;
V_27 = F_7 ( V_9 -> V_16 , V_9 -> V_31 . V_32 , sizeof( * V_27 ) , V_24 ) ;
if ( ! V_27 )
return NULL ;
* V_25 = F_8 ( V_27 ) ;
if ( * V_25 < sizeof( * V_27 ) || * V_25 > V_19 )
return NULL ;
return F_7 ( V_9 -> V_16 , V_9 -> V_31 . V_32 , * V_25 , V_24 ) ;
}
static void F_9 ( const struct V_4 * V_5 ,
struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
T_1 V_33 [ sizeof( struct V_26 ) + V_34 ] ;
struct V_10 * V_11 = F_3 ( V_5 ) ;
unsigned int V_35 , V_36 , V_25 , V_2 ;
T_2 * V_12 = & V_7 -> V_13 [ V_11 -> V_14 ] ;
struct V_26 * V_27 ;
T_1 * V_1 ;
V_27 = F_6 ( V_9 , sizeof( V_33 ) , V_33 , & V_25 ) ;
if ( ! V_27 )
goto V_15;
V_1 = ( T_1 * ) V_27 ;
for ( V_35 = sizeof( * V_27 ) ; V_35 < V_25 - 1 ; V_35 += V_36 ) {
V_36 = F_1 ( V_1 , V_35 ) ;
if ( V_11 -> type != V_1 [ V_35 ] )
continue;
if ( V_35 + V_36 > V_25 || V_11 -> V_19 + V_11 -> V_2 > V_36 )
goto V_15;
V_2 = V_35 + V_11 -> V_2 ;
if ( V_11 -> V_17 & V_18 ) {
* V_12 = 1 ;
} else {
V_12 [ V_11 -> V_19 / V_20 ] = 0 ;
memcpy ( V_12 , V_1 + V_2 , V_11 -> V_19 ) ;
}
return;
}
V_15:
if ( V_11 -> V_17 & V_18 )
* V_12 = 0 ;
else
V_7 -> V_21 . V_22 = V_23 ;
}
static void F_10 ( const struct V_4 * V_5 ,
struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
T_1 V_33 [ sizeof( struct V_26 ) + V_34 ] ;
struct V_10 * V_11 = F_3 ( V_5 ) ;
unsigned int V_35 , V_36 , V_25 , V_2 ;
struct V_26 * V_27 ;
T_1 * V_1 ;
T_2 V_37 ;
V_27 = F_6 ( V_9 , sizeof( V_33 ) , V_33 , & V_25 ) ;
if ( ! V_27 )
return;
V_1 = ( T_1 * ) V_27 ;
for ( V_35 = sizeof( * V_27 ) ; V_35 < V_25 - 1 ; V_35 += V_36 ) {
union {
T_1 V_38 ;
T_3 V_39 ;
T_4 V_40 ;
} V_41 , V_42 ;
V_36 = F_1 ( V_1 , V_35 ) ;
if ( V_11 -> type != V_1 [ V_35 ] )
continue;
if ( V_35 + V_36 > V_25 || V_11 -> V_19 + V_11 -> V_2 > V_36 )
return;
if ( ! F_11 ( V_9 -> V_16 , V_9 -> V_31 . V_32 + V_35 + V_11 -> V_19 ) )
return;
V_27 = F_6 ( V_9 , sizeof( V_33 ) , V_33 ,
& V_25 ) ;
if ( ! V_27 )
return;
V_37 = V_7 -> V_13 [ V_11 -> V_43 ] ;
V_2 = V_35 + V_11 -> V_2 ;
switch ( V_11 -> V_19 ) {
case 2 :
V_41 . V_39 = F_12 ( ( V_44 * ) ( V_1 + V_2 ) ) ;
V_42 . V_39 = V_37 ;
switch ( V_11 -> type ) {
case V_45 :
if ( F_13 ( V_41 . V_39 ) <= F_13 ( V_42 . V_39 ) )
return;
break;
}
if ( V_41 . V_39 == V_42 . V_39 )
return;
F_14 ( V_42 . V_39 , ( V_44 * ) ( V_1 + V_2 ) ) ;
F_15 ( & V_27 -> V_46 , V_9 -> V_16 ,
V_41 . V_39 , V_42 . V_39 , false ) ;
break;
case 4 :
V_42 . V_40 = V_37 ;
V_41 . V_40 = F_12 ( ( T_2 * ) ( V_1 + V_2 ) ) ;
if ( V_41 . V_40 == V_42 . V_40 )
return;
F_14 ( V_42 . V_40 , ( T_2 * ) ( V_1 + V_2 ) ) ;
F_16 ( & V_27 -> V_46 , V_9 -> V_16 ,
V_41 . V_40 , V_42 . V_40 , false ) ;
break;
default:
F_17 ( 1 ) ;
break;
}
return;
}
}
static int F_18 ( const struct V_47 * V_48 ,
const struct V_4 * V_5 ,
const struct V_49 * const V_50 [] )
{
struct V_10 * V_11 = F_3 ( V_5 ) ;
T_2 V_2 , V_19 , V_17 = 0 , V_51 = V_52 ;
int V_15 ;
if ( ! V_50 [ V_53 ] ||
! V_50 [ V_54 ] ||
! V_50 [ V_55 ] ||
! V_50 [ V_56 ] )
return - V_57 ;
V_15 = F_19 ( V_50 [ V_55 ] , V_58 , & V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_19 ( V_50 [ V_56 ] , V_58 , & V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_50 [ V_59 ] ) {
V_15 = F_19 ( V_50 [ V_59 ] , V_58 , & V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_17 & ~ V_18 )
return - V_57 ;
}
if ( V_50 [ V_60 ] ) {
V_15 = F_19 ( V_50 [ V_60 ] , V_58 , & V_51 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_11 -> type = F_20 ( V_50 [ V_54 ] ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_14 = F_21 ( V_50 [ V_53 ] ) ;
V_11 -> V_17 = V_17 ;
V_11 -> V_51 = V_51 ;
return F_22 ( V_48 , V_11 -> V_14 , NULL ,
V_61 , V_11 -> V_19 ) ;
}
static int F_23 ( const struct V_47 * V_48 ,
const struct V_4 * V_5 ,
const struct V_49 * const V_50 [] )
{
struct V_10 * V_11 = F_3 ( V_5 ) ;
T_2 V_2 , V_19 , V_17 = 0 , V_51 = V_52 ;
int V_15 ;
if ( ! V_50 [ V_62 ] ||
! V_50 [ V_54 ] ||
! V_50 [ V_55 ] ||
! V_50 [ V_56 ] )
return - V_57 ;
if ( V_50 [ V_53 ] || V_50 [ V_59 ] )
return - V_57 ;
V_15 = F_19 ( V_50 [ V_55 ] , V_58 , & V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_19 ( V_50 [ V_56 ] , V_58 , & V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_2 < 2 )
return - V_63 ;
switch ( V_19 ) {
case 2 : break;
case 4 : break;
default:
return - V_63 ;
}
V_15 = F_19 ( V_50 [ V_60 ] , V_58 , & V_51 ) ;
if ( V_15 < 0 )
return V_15 ;
V_11 -> type = F_20 ( V_50 [ V_54 ] ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_43 = F_21 ( V_50 [ V_62 ] ) ;
V_11 -> V_17 = V_17 ;
V_11 -> V_51 = V_51 ;
return F_24 ( V_11 -> V_43 , V_11 -> V_19 ) ;
}
static int F_25 ( struct V_64 * V_16 , const struct V_10 * V_11 )
{
if ( F_26 ( V_16 , V_54 , V_11 -> type ) )
goto V_65;
if ( F_27 ( V_16 , V_55 , F_28 ( V_11 -> V_2 ) ) )
goto V_65;
if ( F_27 ( V_16 , V_56 , F_28 ( V_11 -> V_19 ) ) )
goto V_65;
if ( F_27 ( V_16 , V_59 , F_28 ( V_11 -> V_17 ) ) )
goto V_65;
if ( F_27 ( V_16 , V_60 , F_28 ( V_11 -> V_51 ) ) )
goto V_65;
return 0 ;
V_65:
return - 1 ;
}
static int F_29 ( struct V_64 * V_16 , const struct V_4 * V_5 )
{
const struct V_10 * V_11 = F_3 ( V_5 ) ;
if ( F_30 ( V_16 , V_53 , V_11 -> V_14 ) )
return - 1 ;
return F_25 ( V_16 , V_11 ) ;
}
static int F_31 ( struct V_64 * V_16 , const struct V_4 * V_5 )
{
const struct V_10 * V_11 = F_3 ( V_5 ) ;
if ( F_30 ( V_16 , V_62 , V_11 -> V_43 ) )
return - 1 ;
return F_25 ( V_16 , V_11 ) ;
}
static const struct V_66 *
F_32 ( const struct V_47 * V_48 ,
const struct V_49 * const V_50 [] )
{
T_2 V_51 ;
if ( ! V_50 [ V_60 ] )
return & V_67 ;
if ( V_50 [ V_62 ] && V_50 [ V_53 ] )
return F_33 ( - V_63 ) ;
V_51 = F_34 ( F_35 ( V_50 [ V_60 ] ) ) ;
switch ( V_51 ) {
case V_68 :
if ( V_50 [ V_62 ] )
return & V_69 ;
if ( V_50 [ V_53 ] )
return & V_70 ;
break;
case V_52 :
if ( V_50 [ V_53 ] )
return & V_67 ;
break;
}
return F_33 ( - V_63 ) ;
}
static int T_5 F_36 ( void )
{
return F_37 ( & V_71 ) ;
}
static void T_6 F_38 ( void )
{
F_39 ( & V_71 ) ;
}
