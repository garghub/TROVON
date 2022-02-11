static inline void F_1 ( T_1 * V_1 , const T_1 * V_2 )
{
( ( V_3 * ) V_1 ) [ 0 ] ^= ( ( V_3 * ) V_2 ) [ 0 ] ;
( ( V_3 * ) V_1 ) [ 1 ] ^= ( ( V_3 * ) V_2 ) [ 1 ] ;
}
static inline void F_2 ( T_1 * V_1 , const T_1 * V_2 )
{
( ( V_3 * ) V_1 ) [ 0 ] ^= ( ( V_3 * ) V_2 ) [ 0 ] ;
( ( V_3 * ) V_1 ) [ 1 ] ^= ( ( V_3 * ) V_2 ) [ 1 ] ;
( ( V_3 * ) V_1 ) [ 2 ] ^= ( ( V_3 * ) V_2 ) [ 2 ] ;
( ( V_3 * ) V_1 ) [ 3 ] ^= ( ( V_3 * ) V_2 ) [ 3 ] ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 , T_2 V_10 ,
T_3 V_11 , int V_12 , void * V_13 )
{
struct V_14 V_15 , V_16 ;
const unsigned int V_17 = F_4 ( V_5 ) ;
T_1 V_18 [ V_17 ] ;
T_1 V_19 [ V_17 ] ;
if ( ! V_9 )
return 0 ;
if ( V_9 % V_17 ) {
V_5 -> V_20 |= V_21 ;
return - V_22 ;
}
F_5 ( & V_15 , V_8 ) ;
F_5 ( & V_16 , V_7 ) ;
for(; ; ) {
T_1 * V_23 , * V_24 ;
int V_25 ;
F_6 ( & V_15 ) ;
F_6 ( & V_16 ) ;
V_23 = F_7 ( & V_15 , V_17 , V_18 ) ;
V_24 = F_7 ( & V_16 , V_17 , V_19 ) ;
V_25 = F_8 ( & V_15 , & V_16 ,
V_23 , V_24 ) ;
V_9 -= V_17 ;
F_9 ( V_23 , & V_15 , V_17 , 0 ) ;
V_11 ( V_5 , V_24 , V_23 , V_10 , V_12 , V_13 , V_25 ) ;
F_10 ( & V_15 , V_9 ) ;
F_9 ( V_24 , & V_16 , V_17 , 1 ) ;
F_10 ( & V_16 , V_9 ) ;
if ( ! V_9 )
return 0 ;
F_11 ( V_5 ) ;
}
}
static void F_12 ( struct V_4 * V_5 , T_1 * V_7 , T_1 * V_8 ,
T_2 V_26 , int V_12 , void * V_13 , int V_25 )
{
T_1 * V_27 = V_13 ;
if ( ! V_27 )
return;
if ( V_12 ) {
V_5 -> V_28 . V_29 . V_30 ( V_27 , V_8 ) ;
V_26 ( F_13 ( V_5 ) , V_7 , V_27 ) ;
memcpy ( V_27 , V_7 , F_4 ( V_5 ) ) ;
} else {
T_1 V_31 [ V_25 ? F_4 ( V_5 ) : 0 ] ;
T_1 * V_32 = V_25 ? V_31 : V_7 ;
V_26 ( F_13 ( V_5 ) , V_32 , V_8 ) ;
V_5 -> V_28 . V_29 . V_30 ( V_32 , V_27 ) ;
memcpy ( V_27 , V_8 , F_4 ( V_5 ) ) ;
if ( V_32 != V_7 )
memcpy ( V_7 , V_32 , F_4 ( V_5 ) ) ;
}
}
static void F_14 ( struct V_4 * V_5 , T_1 * V_7 , T_1 * V_8 ,
T_2 V_26 , int V_12 , void * V_13 , int V_25 )
{
V_26 ( F_13 ( V_5 ) , V_7 , V_8 ) ;
}
static int F_15 ( struct V_4 * V_5 , const T_1 * V_33 , unsigned int V_34 )
{
struct V_35 * V_36 = & V_5 -> V_37 -> V_38 ;
if ( V_34 < V_36 -> V_39 || V_34 > V_36 -> V_40 ) {
V_5 -> V_20 |= V_41 ;
return - V_22 ;
} else
return V_36 -> V_42 ( F_13 ( V_5 ) , V_33 , V_34 ,
& V_5 -> V_20 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 , unsigned int V_9 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_43 ,
F_14 , 1 , NULL ) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_44 ,
F_14 , 1 , NULL ) ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_43 ,
F_12 , 1 , V_5 -> V_45 . V_46 ) ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 , T_1 * V_27 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_43 ,
F_12 , 1 , V_27 ) ;
}
static int F_20 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_44 ,
F_12 , 0 , V_5 -> V_45 . V_46 ) ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 , T_1 * V_27 )
{
return F_3 ( V_5 , V_7 , V_8 , V_9 ,
V_5 -> V_37 -> V_38 . V_44 ,
F_12 , 0 , V_27 ) ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 )
{
return - V_47 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_8 ,
unsigned int V_9 , T_1 * V_27 )
{
return - V_47 ;
}
int F_24 ( struct V_4 * V_5 , V_3 V_48 )
{
V_3 V_49 = V_48 & V_50 ;
V_5 -> V_45 . V_51 = V_49 ? V_49 : V_52 ;
if ( V_48 & V_53 )
V_5 -> V_20 = V_53 ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 )
{
int V_54 = 0 ;
struct V_55 * V_56 = & V_5 -> V_45 ;
V_56 -> V_57 = F_15 ;
switch ( V_5 -> V_45 . V_51 ) {
case V_52 :
V_56 -> V_58 = F_16 ;
V_56 -> V_59 = F_17 ;
break;
case V_60 :
V_56 -> V_58 = F_18 ;
V_56 -> V_59 = F_20 ;
V_56 -> V_61 = F_19 ;
V_56 -> V_62 = F_21 ;
break;
case V_63 :
V_56 -> V_58 = F_22 ;
V_56 -> V_59 = F_22 ;
V_56 -> V_61 = F_23 ;
V_56 -> V_62 = F_23 ;
break;
case V_64 :
V_56 -> V_58 = F_22 ;
V_56 -> V_59 = F_22 ;
V_56 -> V_61 = F_23 ;
V_56 -> V_62 = F_23 ;
break;
default:
F_26 () ;
}
if ( V_56 -> V_51 == V_60 ) {
switch ( F_4 ( V_5 ) ) {
case 8 :
V_56 -> V_30 = F_1 ;
break;
case 16 :
V_56 -> V_30 = F_2 ;
break;
default:
F_27 ( V_65 L_1 ,
F_28 ( V_5 ) ,
F_4 ( V_5 ) ) ;
V_54 = - V_22 ;
goto V_66;
}
V_56 -> V_67 = F_4 ( V_5 ) ;
V_56 -> V_46 = F_29 ( V_56 -> V_67 , V_68 ) ;
if ( V_56 -> V_46 == NULL )
V_54 = - V_69 ;
}
V_66:
return V_54 ;
}
void F_30 ( struct V_4 * V_5 )
{
F_31 ( V_5 -> V_45 . V_46 ) ;
}
