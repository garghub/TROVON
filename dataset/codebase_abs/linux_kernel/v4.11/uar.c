int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 [ F_2 ( V_5 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_7 ) ] = { 0 } ;
int V_8 ;
F_3 ( V_7 , V_6 , V_9 , V_10 ) ;
V_8 = F_4 ( V_2 , V_6 , sizeof( V_6 ) , V_4 , sizeof( V_4 ) ) ;
if ( ! V_8 )
* V_3 = F_5 ( V_5 , V_4 , V_11 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 [ F_2 ( V_12 ) ] = { 0 } ;
T_1 V_6 [ F_2 ( V_13 ) ] = { 0 } ;
F_3 ( V_13 , V_6 , V_9 , V_14 ) ;
F_3 ( V_13 , V_6 , V_11 , V_3 ) ;
return F_4 ( V_2 , V_6 , sizeof( V_6 ) , V_4 , sizeof( V_4 ) ) ;
}
static int F_7 ( struct V_1 * V_15 )
{
if ( F_8 ( V_15 , V_16 ) )
return F_8 ( V_15 , V_17 ) ;
return 1 ;
}
static T_2 F_9 ( struct V_1 * V_15 , T_1 V_18 )
{
T_1 V_19 ;
if ( F_8 ( V_15 , V_16 ) )
V_19 = V_18 >> ( V_20 - V_21 ) ;
else
V_19 = V_18 ;
return ( F_10 ( V_15 -> V_22 , 0 ) >> V_20 ) + V_19 ;
}
static void F_11 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_12 ( V_23 , struct V_24 , V_26 ) ;
F_13 ( & V_25 -> V_27 ) ;
F_14 ( V_25 -> V_28 ) ;
if ( F_6 ( V_25 -> V_15 , V_25 -> V_18 ) )
F_15 ( V_25 -> V_15 , L_1 , V_25 -> V_18 ) ;
F_16 ( V_25 -> V_29 ) ;
F_16 ( V_25 -> V_30 ) ;
F_16 ( V_25 ) ;
}
static struct V_24 * F_17 ( struct V_1 * V_15 ,
bool V_31 )
{
struct V_24 * V_25 ;
int V_8 = - V_32 ;
T_3 V_33 ;
int V_34 ;
int V_35 ;
V_34 = F_7 ( V_15 ) * V_36 ;
V_25 = F_18 ( sizeof( * V_25 ) , V_37 ) ;
if ( ! V_25 )
return F_19 ( V_8 ) ;
V_25 -> V_15 = V_15 ;
V_25 -> V_29 = F_20 ( F_21 ( V_34 ) , sizeof( unsigned long ) , V_37 ) ;
if ( ! V_25 -> V_29 )
goto V_38;
V_25 -> V_30 = F_20 ( F_21 ( V_34 ) , sizeof( unsigned long ) , V_37 ) ;
if ( ! V_25 -> V_30 )
goto V_38;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ )
if ( ( V_35 % V_36 ) < V_39 )
F_22 ( V_35 , V_25 -> V_29 ) ;
else
F_22 ( V_35 , V_25 -> V_30 ) ;
V_25 -> V_34 = V_34 ;
V_25 -> V_40 = V_34 * V_41 / V_36 ;
V_25 -> V_42 = V_34 * V_39 / V_36 ;
V_8 = F_1 ( V_15 , & V_25 -> V_18 ) ;
if ( V_8 ) {
F_15 ( V_15 , L_2 , V_8 ) ;
goto V_38;
}
V_33 = F_9 ( V_15 , V_25 -> V_18 ) ;
if ( V_31 ) {
V_25 -> V_28 = F_23 ( V_33 << V_20 , V_43 ) ;
if ( ! V_25 -> V_28 ) {
V_8 = - V_44 ;
goto V_45;
}
} else {
V_25 -> V_28 = F_24 ( V_33 << V_20 , V_43 ) ;
if ( ! V_25 -> V_28 ) {
V_8 = - V_32 ;
goto V_45;
}
}
F_25 ( & V_25 -> V_26 ) ;
F_26 ( V_15 , L_3 ,
V_25 -> V_18 , V_25 -> V_34 ) ;
return V_25 ;
V_45:
if ( F_6 ( V_15 , V_25 -> V_18 ) )
F_15 ( V_15 , L_1 , V_25 -> V_18 ) ;
V_38:
F_16 ( V_25 -> V_30 ) ;
F_16 ( V_25 -> V_29 ) ;
F_16 ( V_25 ) ;
return F_19 ( V_8 ) ;
}
struct V_24 * F_27 ( struct V_1 * V_15 )
{
struct V_24 * V_46 ;
F_28 ( & V_15 -> V_47 . V_34 . V_48 . V_49 ) ;
if ( F_29 ( & V_15 -> V_47 . V_34 . V_48 . V_27 ) ) {
V_46 = F_17 ( V_15 , false ) ;
if ( F_30 ( V_46 ) ) {
V_46 = NULL ;
goto V_4;
}
F_31 ( & V_46 -> V_27 , & V_15 -> V_47 . V_34 . V_48 . V_27 ) ;
} else {
V_46 = F_32 ( & V_15 -> V_47 . V_34 . V_48 . V_27 ,
struct V_24 , V_27 ) ;
F_33 ( & V_46 -> V_26 ) ;
}
V_4:
F_34 ( & V_15 -> V_47 . V_34 . V_48 . V_49 ) ;
return V_46 ;
}
void F_35 ( struct V_1 * V_15 , struct V_24 * V_25 )
{
F_28 ( & V_15 -> V_47 . V_34 . V_48 . V_49 ) ;
F_36 ( & V_25 -> V_26 , F_11 ) ;
F_34 ( & V_15 -> V_47 . V_34 . V_48 . V_49 ) ;
}
static unsigned long F_37 ( struct V_1 * V_15 , int V_50 )
{
return V_50 / V_36 * V_51 +
( V_50 % V_36 ) *
( 1 << F_8 ( V_15 , V_52 ) ) + V_53 ;
}
static int F_38 ( struct V_1 * V_15 , struct V_54 * V_55 ,
bool V_31 , bool V_56 )
{
struct V_57 * V_34 ;
struct V_24 * V_25 ;
struct V_58 * V_59 ;
unsigned long * V_60 ;
unsigned int * V_61 ;
struct V_62 * V_49 ;
int V_50 ;
V_34 = & V_15 -> V_47 . V_34 ;
if ( V_31 ) {
V_59 = & V_34 -> V_63 . V_27 ;
V_49 = & V_34 -> V_63 . V_49 ;
} else {
V_59 = & V_34 -> V_48 . V_27 ;
V_49 = & V_34 -> V_48 . V_49 ;
}
F_28 ( V_49 ) ;
if ( F_29 ( V_59 ) ) {
V_25 = F_17 ( V_15 , V_31 ) ;
if ( F_30 ( V_25 ) ) {
F_34 ( V_49 ) ;
return F_39 ( V_25 ) ;
}
F_31 ( & V_25 -> V_27 , V_59 ) ;
} else {
V_25 = F_40 ( V_59 -> V_64 , struct V_24 , V_27 ) ;
F_33 ( & V_25 -> V_26 ) ;
}
if ( V_56 ) {
V_60 = V_25 -> V_30 ;
V_61 = & V_25 -> V_40 ;
} else {
V_60 = V_25 -> V_29 ;
V_61 = & V_25 -> V_42 ;
}
V_50 = F_41 ( V_60 , V_25 -> V_34 ) ;
F_42 ( V_50 , V_60 ) ;
( * V_61 ) -- ;
if ( ! ( * V_61 ) )
F_13 ( & V_25 -> V_27 ) ;
V_55 -> V_28 = V_25 -> V_28 + F_37 ( V_15 , V_50 ) ;
V_55 -> V_25 = V_25 ;
V_55 -> V_65 = V_31 ;
V_55 -> V_18 = V_25 -> V_18 + V_50 / V_36 ;
F_34 ( V_49 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_15 , struct V_54 * V_55 ,
bool V_31 , bool V_56 )
{
int V_8 ;
V_8 = F_38 ( V_15 , V_55 , V_31 , V_56 ) ;
if ( ! V_8 )
return 0 ;
if ( V_8 == - V_44 && V_31 )
return F_38 ( V_15 , V_55 , false , V_56 ) ;
return V_8 ;
}
static unsigned int F_44 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_54 * V_55 )
{
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
V_68 = 1 << F_8 ( V_2 , V_52 ) ;
V_66 = ( V_55 -> V_28 - V_25 -> V_28 ) >> V_21 ;
V_67 = ( ( ( V_69 ) V_55 -> V_28 % V_51 ) - V_53 ) / V_68 ;
return V_66 * V_36 + V_67 ;
}
void F_45 ( struct V_1 * V_15 , struct V_54 * V_55 )
{
struct V_57 * V_34 ;
struct V_24 * V_25 ;
struct V_62 * V_49 ;
unsigned int V_50 ;
bool V_70 ;
unsigned int * V_61 ;
unsigned long * V_60 ;
struct V_58 * V_59 ;
V_34 = & V_15 -> V_47 . V_34 ;
if ( V_55 -> V_65 ) {
V_59 = & V_34 -> V_63 . V_27 ;
V_49 = & V_34 -> V_63 . V_49 ;
} else {
V_59 = & V_34 -> V_48 . V_27 ;
V_49 = & V_34 -> V_48 . V_49 ;
}
V_25 = V_55 -> V_25 ;
V_50 = F_44 ( V_15 , V_25 , V_55 ) ;
V_70 = ( V_50 % V_36 ) >= V_39 ;
if ( V_70 ) {
V_61 = & V_25 -> V_40 ;
V_60 = V_25 -> V_30 ;
} else {
V_61 = & V_25 -> V_42 ;
V_60 = V_25 -> V_29 ;
}
F_28 ( V_49 ) ;
( * V_61 ) ++ ;
F_22 ( V_50 , V_60 ) ;
if ( * V_61 == 1 )
F_46 ( & V_25 -> V_27 , V_59 ) ;
F_36 ( & V_25 -> V_26 , F_11 ) ;
F_34 ( V_49 ) ;
}
