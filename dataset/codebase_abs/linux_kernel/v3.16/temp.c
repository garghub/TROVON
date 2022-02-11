static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
V_4 -> V_5 . V_6 = 0 ;
V_4 -> V_5 . V_7 . V_8 = 90 ;
V_4 -> V_5 . V_7 . V_9 = 3 ;
V_4 -> V_5 . V_10 . V_8 = 95 ;
V_4 -> V_5 . V_10 . V_9 = 3 ;
V_4 -> V_5 . V_11 . V_8 = 105 ;
V_4 -> V_5 . V_11 . V_9 = 5 ;
V_4 -> V_5 . V_12 . V_8 = 135 ;
V_4 -> V_5 . V_12 . V_9 = 5 ;
}
static void
F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_13 * V_14 = & V_4 -> V_5 ;
V_14 -> V_7 . V_9 = F_3 ( V_15 , V_14 -> V_7 . V_9 , 2 ) ;
V_14 -> V_10 . V_9 = F_3 ( V_15 , V_14 -> V_10 . V_9 , 2 ) ;
V_14 -> V_11 . V_9 = F_3 ( V_15 , V_14 -> V_11 . V_9 , 2 ) ;
V_14 -> V_12 . V_9 = F_3 ( V_15 , V_14 -> V_12 . V_9 , 2 ) ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
enum V_18 V_19 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
V_4 -> V_20 . V_21 [ V_17 ] = V_19 ;
}
enum V_18
F_5 ( struct V_1 * V_2 ,
enum V_16 V_17 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
return V_4 -> V_20 . V_21 [ V_17 ] ;
}
static void
F_6 ( struct V_22 * V_23 )
{
F_7 ( true ) ;
F_8 ( V_23 ) ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
bool V_26 ;
const char * V_27 [] = {
L_1 , L_2 , L_3 , L_4
} ;
int V_28 = V_2 -> V_29 ( V_2 ) ;
if ( V_17 < 0 || V_17 > 3 )
return;
if ( V_25 == V_30 )
F_10 ( V_2 , L_5 ,
V_28 , V_27 [ V_17 ] ) ;
else
F_10 ( V_2 , L_6 ,
V_28 , V_27 [ V_17 ] ) ;
V_26 = ( V_25 == V_31 ) ;
switch ( V_17 ) {
case V_32 :
if ( V_26 ) {
F_11 ( V_2 , true , 100 ) ;
F_12 ( V_2 , V_33 ) ;
}
break;
case V_34 :
if ( V_4 -> V_35 . V_36 )
V_4 -> V_35 . V_36 ( V_2 , V_26 ) ;
break;
case V_37 :
if ( V_4 -> V_35 . V_38 )
V_4 -> V_35 . V_38 ( V_2 , V_26 ) ;
break;
case V_39 :
if ( V_26 ) {
struct V_22 * V_23 ;
V_23 = F_13 ( sizeof( * V_23 ) , V_40 ) ;
if ( V_23 ) {
F_14 ( V_23 , F_6 ) ;
F_15 ( V_23 ) ;
}
}
break;
case V_41 :
break;
}
}
static void
F_16 ( struct V_1 * V_2 ,
const struct V_42 * V_17 ,
enum V_16 V_43 )
{
enum V_24 V_44 ;
enum V_18 V_45 , V_46 ;
int V_8 = V_2 -> V_29 ( V_2 ) ;
V_45 = F_5 ( V_2 , V_43 ) ;
if ( V_8 >= V_17 -> V_8 && V_45 == V_47 ) {
V_44 = V_31 ;
V_46 = V_48 ;
} else if ( V_8 <= V_17 -> V_8 - V_17 -> V_9 &&
V_45 == V_48 ) {
V_44 = V_30 ;
V_46 = V_47 ;
} else
return;
F_4 ( V_2 , V_43 , V_46 ) ;
F_9 ( V_2 , V_43 , V_44 ) ;
}
static void
F_17 ( struct V_49 * V_50 )
{
struct V_3 * V_4 =
F_18 ( V_50 , struct V_3 , V_20 . V_51 ) ;
struct V_13 * V_20 = & V_4 -> V_5 ;
struct V_52 * V_53 = V_52 ( V_4 ) ;
struct V_1 * V_2 = & V_4 -> V_54 ;
unsigned long V_55 ;
F_19 ( & V_4 -> V_20 . V_56 , V_55 ) ;
F_16 ( V_2 , & V_20 -> V_7 ,
V_32 ) ;
F_16 ( V_2 , & V_20 -> V_10 ,
V_34 ) ;
F_16 ( V_2 , & V_20 -> V_11 ,
V_37 ) ;
F_16 ( V_2 , & V_20 -> V_12 ,
V_39 ) ;
F_20 ( & V_4 -> V_20 . V_56 , V_55 ) ;
if ( V_2 -> V_29 ( V_2 ) >= 0 && F_21 ( & V_50 -> V_57 ) )
V_53 -> V_50 ( V_53 , 1000000000ULL , V_50 ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_13 * V_20 = & V_4 -> V_5 ;
F_23 ( V_2 ,
L_7 ,
V_20 -> V_7 . V_8 , V_20 -> V_7 . V_9 ,
V_20 -> V_10 . V_8 ,
V_20 -> V_10 . V_9 ,
V_20 -> V_11 . V_8 , V_20 -> V_11 . V_9 ,
V_20 -> V_12 . V_8 , V_20 -> V_12 . V_9 ) ;
F_17 ( & V_4 -> V_20 . V_51 ) ;
}
int
F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
V_4 -> V_20 . V_58 ( V_2 ) ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , bool V_59 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_52 * V_53 = V_52 ( V_2 ) ;
if ( V_59 )
V_53 -> V_60 ( V_53 , & V_4 -> V_20 . V_51 ) ;
return 0 ;
}
void
F_26 ( struct V_1 * V_2 )
{
const char * V_61 = L_8 ;
if ( V_2 -> V_29 ( V_2 ) < 0 )
V_61 = L_9 ;
F_10 ( V_2 , L_10 , V_61 ) ;
}
int
F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_62 * V_63 = V_62 ( V_2 ) ;
F_28 ( & V_4 -> V_20 . V_51 , F_17 ) ;
F_1 ( V_2 ) ;
if ( F_29 ( V_63 , V_64 ,
& V_4 -> V_5 ) )
F_30 ( V_2 , L_11 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
