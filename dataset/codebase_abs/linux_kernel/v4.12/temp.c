static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_5 . V_6 = 90 ;
V_2 -> V_3 . V_5 . V_7 = 3 ;
V_2 -> V_3 . V_8 . V_6 = 95 ;
V_2 -> V_3 . V_8 . V_7 = 3 ;
V_2 -> V_3 . V_9 . V_6 = 105 ;
V_2 -> V_3 . V_9 . V_7 = 5 ;
V_2 -> V_3 . V_10 . V_6 = 135 ;
V_2 -> V_3 . V_10 . V_7 = 5 ;
}
static void
F_2 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_3 ;
V_12 -> V_5 . V_7 = F_3 ( V_13 , V_12 -> V_5 . V_7 , 2 ) ;
V_12 -> V_8 . V_7 = F_3 ( V_13 , V_12 -> V_8 . V_7 , 2 ) ;
V_12 -> V_9 . V_7 = F_3 ( V_13 , V_12 -> V_9 . V_7 , 2 ) ;
V_12 -> V_10 . V_7 = F_3 ( V_13 , V_12 -> V_10 . V_7 , 2 ) ;
}
void
F_4 ( struct V_1 * V_2 ,
enum V_14 V_15 ,
enum V_16 V_17 )
{
V_2 -> V_18 . V_19 [ V_15 ] = V_17 ;
}
enum V_16
F_5 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
return V_2 -> V_18 . V_19 [ V_15 ] ;
}
static void
F_6 ( struct V_20 * V_21 )
{
F_7 ( true ) ;
F_8 ( V_21 ) ;
}
void
F_9 ( struct V_1 * V_2 , enum V_14 V_15 ,
enum V_22 V_23 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
bool V_26 ;
const char * V_27 [] = {
L_1 , L_2 , L_3 , L_4
} ;
int V_28 = V_2 -> V_29 -> V_30 ( V_2 ) ;
if ( V_15 < 0 || V_15 > 3 )
return;
if ( V_23 == V_31 )
F_10 ( V_25 ,
L_5 ,
V_28 , V_27 [ V_15 ] ) ;
else
F_10 ( V_25 , L_6 ,
V_28 , V_27 [ V_15 ] ) ;
V_26 = ( V_23 == V_32 ) ;
switch ( V_15 ) {
case V_33 :
if ( V_26 ) {
F_11 ( V_2 , true , 100 ) ;
F_12 ( V_2 , V_34 ) ;
}
break;
case V_35 :
if ( V_2 -> V_36 . V_37 )
V_2 -> V_36 . V_37 ( V_2 , V_26 ) ;
break;
case V_38 :
if ( V_2 -> V_36 . V_39 )
V_2 -> V_36 . V_39 ( V_2 , V_26 ) ;
break;
case V_40 :
if ( V_26 ) {
struct V_20 * V_21 ;
V_21 = F_13 ( sizeof( * V_21 ) , V_41 ) ;
if ( V_21 ) {
F_14 ( V_21 , F_6 ) ;
F_15 ( V_21 ) ;
}
}
break;
case V_42 :
break;
}
}
static void
F_16 ( struct V_1 * V_2 ,
const struct V_43 * V_15 ,
enum V_14 V_44 )
{
enum V_22 V_45 ;
enum V_16 V_46 , V_47 ;
int V_6 = V_2 -> V_29 -> V_30 ( V_2 ) ;
V_46 = F_5 ( V_2 , V_44 ) ;
if ( V_6 >= V_15 -> V_6 && V_46 == V_48 ) {
V_45 = V_32 ;
V_47 = V_49 ;
} else if ( V_6 <= V_15 -> V_6 - V_15 -> V_7 &&
V_46 == V_49 ) {
V_45 = V_31 ;
V_47 = V_48 ;
} else
return;
F_4 ( V_2 , V_44 , V_47 ) ;
F_9 ( V_2 , V_44 , V_45 ) ;
}
static void
F_17 ( struct V_50 * V_51 )
{
struct V_1 * V_2 =
F_18 ( V_51 , struct V_1 , V_18 . V_52 ) ;
struct V_11 * V_18 = & V_2 -> V_3 ;
struct V_53 * V_54 = V_2 -> V_25 . V_55 -> V_56 ;
unsigned long V_57 ;
F_19 ( & V_2 -> V_18 . V_58 , V_57 ) ;
F_16 ( V_2 , & V_18 -> V_5 ,
V_33 ) ;
F_16 ( V_2 ,
& V_18 -> V_8 ,
V_35 ) ;
F_16 ( V_2 , & V_18 -> V_9 ,
V_38 ) ;
F_16 ( V_2 , & V_18 -> V_10 ,
V_40 ) ;
F_20 ( & V_2 -> V_18 . V_58 , V_57 ) ;
if ( V_2 -> V_29 -> V_30 ( V_2 ) >= 0 )
F_21 ( V_54 , 1000000000ULL , V_51 ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_18 = & V_2 -> V_3 ;
F_23 ( & V_2 -> V_25 ,
L_7 ,
V_18 -> V_5 . V_6 ,
V_18 -> V_5 . V_7 ,
V_18 -> V_8 . V_6 ,
V_18 -> V_8 . V_7 ,
V_18 -> V_9 . V_6 ,
V_18 -> V_9 . V_7 ,
V_18 -> V_10 . V_6 ,
V_18 -> V_10 . V_7 ) ;
F_17 ( & V_2 -> V_18 . V_52 ) ;
}
int
F_24 ( struct V_1 * V_2 )
{
V_2 -> V_29 -> V_59 ( V_2 ) ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , bool V_60 )
{
struct V_53 * V_54 = V_2 -> V_25 . V_55 -> V_56 ;
if ( V_60 )
F_26 ( V_54 , & V_2 -> V_18 . V_52 ) ;
return 0 ;
}
void
F_27 ( struct V_1 * V_2 )
{
const char * V_61 = L_8 ;
if ( V_2 -> V_29 -> V_30 ( V_2 ) < 0 )
V_61 = L_9 ;
F_23 ( & V_2 -> V_25 , L_10 , V_61 ) ;
}
int
F_28 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_62 * V_63 = V_25 -> V_55 -> V_63 ;
F_29 ( & V_2 -> V_18 . V_52 , F_17 ) ;
F_1 ( V_2 ) ;
if ( F_30 ( V_63 , V_64 ,
& V_2 -> V_3 ) )
F_31 ( V_25 , L_11 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
