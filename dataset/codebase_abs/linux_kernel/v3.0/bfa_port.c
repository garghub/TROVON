static void
F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
T_1 * V_5 = ( T_1 * ) V_4 ;
T_2 V_6 , V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < sizeof( union V_3 ) / sizeof( T_1 ) ;
V_8 += 2 ) {
V_6 = V_5 [ V_8 ] ;
V_7 = V_5 [ V_8 + 1 ] ;
#ifdef F_2
V_5 [ V_8 ] = F_3 ( V_6 ) ;
V_5 [ V_8 + 1 ] = F_3 ( V_7 ) ;
#else
V_5 [ V_8 ] = F_3 ( V_7 ) ;
V_5 [ V_8 + 1 ] = F_3 ( V_6 ) ;
#endif
}
}
static void
F_4 ( struct V_1 * V_2 , T_3 V_9 )
{
F_5 ( V_2 , V_9 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 ( V_2 -> V_13 , V_9 ) ;
}
static void
F_6 ( struct V_1 * V_2 , T_3 V_9 )
{
F_5 ( V_2 , V_9 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 ( V_2 -> V_13 , V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_3 V_9 )
{
V_2 -> V_14 = V_9 ;
V_2 -> V_15 = V_11 ;
if ( V_9 == V_16 ) {
struct V_17 V_18 ;
memcpy ( V_2 -> V_4 , V_2 -> V_19 . V_20 ,
sizeof( union V_3 ) ) ;
F_1 ( V_2 , V_2 -> V_4 ) ;
F_8 ( & V_18 ) ;
V_2 -> V_4 -> V_21 . V_22 = V_18 . V_23 - V_2 -> V_24 ;
}
if ( V_2 -> V_25 ) {
V_2 -> V_25 ( V_2 -> V_26 , V_9 ) ;
V_2 -> V_25 = NULL ;
}
}
static void
F_9 ( struct V_1 * V_2 , T_3 V_9 )
{
struct V_17 V_18 ;
V_2 -> V_14 = V_9 ;
V_2 -> V_15 = V_11 ;
F_8 ( & V_18 ) ;
V_2 -> V_24 = V_18 . V_23 ;
if ( V_2 -> V_25 ) {
V_2 -> V_25 ( V_2 -> V_26 , V_9 ) ;
V_2 -> V_25 = NULL ;
}
}
static void
F_10 ( void * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
union V_30 * V_31 ;
V_31 = (union V_30 * ) V_29 ;
F_5 ( V_2 , V_29 -> V_32 . V_33 ) ;
switch ( V_29 -> V_32 . V_33 ) {
case V_34 :
if ( V_2 -> V_10 == V_11 )
break;
F_4 ( V_2 , V_31 -> V_35 . V_9 ) ;
break;
case V_36 :
if ( V_2 -> V_10 == V_11 )
break;
F_6 ( V_2 , V_31 -> V_37 . V_9 ) ;
break;
case V_38 :
if ( V_2 -> V_15 == V_11 )
break;
F_7 ( V_2 , V_31 -> V_39 . V_9 ) ;
break;
case V_40 :
if ( V_2 -> V_15 == V_11 )
break;
F_9 ( V_2 , V_31 -> V_41 . V_9 ) ;
break;
default:
F_11 ( 1 ) ;
}
}
T_1
F_12 ( void )
{
return F_13 ( sizeof( union V_3 ) , V_42 ) ;
}
void
F_14 ( struct V_1 * V_2 , T_4 * V_43 , T_5 V_44 )
{
V_2 -> V_19 . V_20 = V_43 ;
V_2 -> V_19 . V_45 = V_44 ;
}
T_3
F_15 ( struct V_1 * V_2 , T_6 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( F_16 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_49 ) ;
return V_49 ;
}
if ( ! F_17 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_50 ) ;
return V_50 ;
}
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
V_29 = (struct V_47 * ) V_2 -> V_52 . V_53 ;
V_2 -> V_54 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_55 ;
F_18 ( V_29 -> V_32 , V_56 , V_57 ,
F_19 ( V_2 -> V_48 ) ) ;
F_20 ( V_2 -> V_48 , & V_2 -> V_52 ) ;
return V_16 ;
}
T_3
F_21 ( struct V_1 * V_2 , T_6 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( F_16 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_49 ) ;
return V_49 ;
}
if ( ! F_17 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_50 ) ;
return V_50 ;
}
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
V_29 = (struct V_47 * ) V_2 -> V_52 . V_53 ;
V_2 -> V_54 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_55 ;
F_18 ( V_29 -> V_32 , V_56 , V_58 ,
F_19 ( V_2 -> V_48 ) ) ;
F_20 ( V_2 -> V_48 , & V_2 -> V_52 ) ;
return V_16 ;
}
T_3
F_22 ( struct V_1 * V_2 , union V_3 * V_4 ,
T_7 V_46 , void * V_27 )
{
struct V_59 * V_29 ;
if ( ! F_17 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_50 ) ;
return V_50 ;
}
if ( V_2 -> V_15 ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
V_29 = (struct V_59 * ) V_2 -> V_60 . V_53 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_55 ;
F_23 ( V_29 -> V_61 , V_2 -> V_19 . V_45 ) ;
F_18 ( V_29 -> V_32 , V_56 , V_62 ,
F_19 ( V_2 -> V_48 ) ) ;
F_20 ( V_2 -> V_48 , & V_2 -> V_60 ) ;
return V_16 ;
}
T_3
F_24 ( struct V_1 * V_2 , T_7 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( ! F_17 ( V_2 -> V_48 ) ) {
F_5 ( V_2 , V_50 ) ;
return V_50 ;
}
if ( V_2 -> V_15 ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
V_29 = (struct V_47 * ) V_2 -> V_60 . V_53 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_55 ;
F_18 ( V_29 -> V_32 , V_56 , V_63 ,
F_19 ( V_2 -> V_48 ) ) ;
F_20 ( V_2 -> V_48 , & V_2 -> V_60 ) ;
return V_16 ;
}
void
F_25 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
if ( V_2 -> V_15 ) {
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 -> V_26 , V_65 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_15 = V_11 ;
}
if ( V_2 -> V_10 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 -> V_13 , V_65 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_10 = V_11 ;
}
}
void
F_26 ( struct V_1 * V_2 , struct V_66 * V_48 ,
void * V_67 , struct V_68 * V_69 )
{
struct V_17 V_18 ;
F_11 ( ! V_2 ) ;
V_2 -> V_67 = V_67 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_69 = V_69 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_25 = NULL ;
V_2 -> V_12 = NULL ;
F_27 ( V_2 -> V_48 , V_56 , F_10 , V_2 ) ;
F_28 ( & V_2 -> V_70 , F_25 , V_2 ) ;
F_29 ( & V_2 -> V_70 . V_71 , & V_2 -> V_48 -> V_72 ) ;
F_8 ( & V_18 ) ;
V_2 -> V_24 = V_18 . V_23 ;
F_5 ( V_2 , 0 ) ;
}
