static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 *
F_3 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
return V_3 ? F_1 ( V_3 ) : NULL ;
}
static struct V_1 *
F_5 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = F_6 ( & V_7 -> V_4 ) ;
return V_3 ? F_1 ( V_3 ) : NULL ;
}
static struct V_1 *
F_7 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = F_8 ( & V_7 -> V_4 ) ;
return V_3 ? F_1 ( V_3 ) : NULL ;
}
static inline T_1
F_9 ( struct V_1 * V_7 )
{
return V_7 -> V_8 + V_7 -> V_9 ;
}
static struct V_1 *
F_10 ( struct V_5 * V_6 , T_1 V_10 )
{
struct V_2 * V_3 = V_6 -> V_2 ;
struct V_1 * V_7 = NULL ;
while ( V_3 ) {
V_7 = F_1 ( V_3 ) ;
if ( V_10 < V_7 -> V_8 )
V_3 = V_3 -> V_11 ;
else if ( V_10 >= F_9 ( V_7 ) )
V_3 = V_3 -> V_12 ;
else
return V_7 ;
}
if ( V_7 ) {
if ( V_10 < V_7 -> V_8 )
return V_7 ;
if ( V_10 >= F_9 ( V_7 ) )
return F_7 ( V_7 ) ;
}
return NULL ;
}
static bool
F_11 ( struct V_1 * V_13 , struct V_1 * V_14 )
{
if ( V_13 -> V_15 != V_14 -> V_15 )
return false ;
if ( V_13 -> V_16 != V_14 -> V_16 )
return false ;
if ( V_13 -> V_8 + V_13 -> V_9 != V_14 -> V_8 )
return false ;
if ( V_13 -> V_15 != V_17 &&
( V_13 -> V_18 + V_13 -> V_9 != V_14 -> V_18 ) )
return false ;
if ( V_13 -> V_15 == V_19 &&
V_13 -> V_20 != V_14 -> V_20 )
return false ;
return true ;
}
static struct V_1 *
F_12 ( struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_21 = F_5 ( V_7 ) ;
if ( V_21 && F_11 ( V_21 , V_7 ) ) {
V_21 -> V_9 += V_7 -> V_9 ;
F_13 ( & V_7 -> V_4 , V_6 ) ;
F_14 ( V_7 -> V_16 ) ;
F_15 ( V_7 ) ;
return V_21 ;
}
return V_7 ;
}
static struct V_1 *
F_16 ( struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_22 = F_7 ( V_7 ) ;
if ( V_22 && F_11 ( V_7 , V_22 ) ) {
V_7 -> V_9 += V_22 -> V_9 ;
F_13 ( & V_22 -> V_4 , V_6 ) ;
F_14 ( V_22 -> V_16 ) ;
F_15 ( V_22 ) ;
}
return V_7 ;
}
static void
F_17 ( struct V_5 * V_6 ,
struct V_1 * V_23 , bool V_24 )
{
struct V_2 * * V_25 = & V_6 -> V_2 , * V_26 = NULL ;
struct V_1 * V_7 ;
while ( * V_25 ) {
V_26 = * V_25 ;
V_7 = F_1 ( V_26 ) ;
if ( V_23 -> V_8 < V_7 -> V_8 ) {
if ( V_24 && F_11 ( V_23 , V_7 ) ) {
V_7 -> V_8 = V_23 -> V_8 ;
if ( V_7 -> V_15 != V_17 )
V_7 -> V_18 = V_23 -> V_18 ;
V_7 -> V_9 += V_23 -> V_9 ;
V_7 = F_12 ( V_6 , V_7 ) ;
goto V_27;
}
V_25 = & ( * V_25 ) -> V_11 ;
} else if ( V_23 -> V_8 >= F_9 ( V_7 ) ) {
if ( V_24 && F_11 ( V_7 , V_23 ) ) {
V_7 -> V_9 += V_23 -> V_9 ;
V_7 = F_16 ( V_6 , V_7 ) ;
goto V_27;
}
V_25 = & ( * V_25 ) -> V_12 ;
} else {
F_18 () ;
}
}
F_19 ( & V_23 -> V_4 , V_26 , V_25 ) ;
F_20 ( & V_23 -> V_4 , V_6 ) ;
return;
V_27:
F_14 ( V_23 -> V_16 ) ;
F_15 ( V_23 ) ;
}
static int
F_21 ( struct V_5 * V_6 , T_1 V_10 , T_1 V_28 )
{
struct V_1 * V_7 ;
T_1 V_29 = 0 , V_30 = 0 ;
T_1 V_31 ;
T_1 V_32 ;
V_7 = F_10 ( V_6 , V_10 ) ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_8 >= V_28 )
return 0 ;
V_31 = V_7 -> V_18 ;
V_32 = V_7 -> V_9 ;
if ( V_10 > V_7 -> V_8 )
V_29 = V_10 - V_7 -> V_8 ;
if ( F_9 ( V_7 ) > V_28 )
V_30 = F_9 ( V_7 ) - V_28 ;
if ( V_30 > 0 ) {
if ( V_29 > 0 ) {
struct V_1 * V_23 ;
V_23 = F_22 ( sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 )
return - V_34 ;
V_7 -> V_9 = V_29 ;
V_23 -> V_8 = V_28 ;
if ( V_7 -> V_15 != V_17 ) {
V_23 -> V_18 =
V_31 + V_32 - V_30 ;
}
V_23 -> V_9 = V_30 ;
V_23 -> V_15 = V_7 -> V_15 ;
V_23 -> V_20 = V_7 -> V_20 ;
V_23 -> V_16 = F_23 ( V_7 -> V_16 ) ;
F_17 ( V_6 , V_23 , true ) ;
} else {
V_7 -> V_8 = V_28 ;
if ( V_7 -> V_15 != V_17 ) {
V_7 -> V_18 =
V_31 + V_32 - V_30 ;
}
V_7 -> V_9 = V_30 ;
}
} else {
if ( V_29 > 0 ) {
V_7 -> V_9 = V_29 ;
V_7 = F_7 ( V_7 ) ;
}
while ( V_7 && F_9 ( V_7 ) <= V_28 ) {
struct V_1 * V_35 = F_7 ( V_7 ) ;
F_13 ( & V_7 -> V_4 , V_6 ) ;
F_14 ( V_7 -> V_16 ) ;
F_15 ( V_7 ) ;
V_7 = V_35 ;
}
if ( V_7 && V_7 -> V_8 < V_28 ) {
V_29 = F_9 ( V_7 ) - V_28 ;
V_7 -> V_8 = V_28 ;
if ( V_7 -> V_15 != V_17 )
V_7 -> V_18 += V_7 -> V_9 - V_29 ;
V_7 -> V_9 = V_29 ;
}
}
return 0 ;
}
int
F_24 ( struct V_36 * V_37 , struct V_1 * V_23 )
{
struct V_1 * V_7 ;
struct V_5 * V_6 ;
int V_38 = 0 ;
switch ( V_23 -> V_15 ) {
case V_39 :
case V_19 :
V_6 = & V_37 -> V_40 ;
break;
case V_41 :
case V_17 :
V_6 = & V_37 -> V_42 ;
break;
default:
F_25 ( L_1 ) ;
return - V_43 ;
}
F_26 ( & V_37 -> V_44 ) ;
V_45:
V_7 = F_10 ( V_6 , V_23 -> V_8 ) ;
if ( ! V_7 || V_7 -> V_8 >= F_9 ( V_23 ) ) {
F_17 ( V_6 , V_23 , true ) ;
} else if ( V_23 -> V_8 >= V_7 -> V_8 ) {
if ( F_9 ( V_23 ) <= F_9 ( V_7 ) ) {
F_14 ( V_23 -> V_16 ) ;
F_15 ( V_23 ) ;
} else {
T_1 V_46 = F_9 ( V_23 ) - F_9 ( V_7 ) ;
T_1 V_47 = V_23 -> V_9 - V_46 ;
V_23 -> V_8 += V_47 ;
V_23 -> V_18 += V_47 ;
V_23 -> V_9 = V_46 ;
goto V_45;
}
} else if ( F_9 ( V_23 ) <= F_9 ( V_7 ) ) {
V_23 -> V_9 = V_7 -> V_8 - V_23 -> V_8 ;
F_17 ( V_6 , V_23 , true ) ;
} else {
struct V_1 * V_48 ;
T_1 V_46 = F_9 ( V_23 ) - F_9 ( V_7 ) ;
T_1 V_47 = V_23 -> V_9 - V_46 ;
V_48 = F_27 ( V_23 , sizeof( * V_23 ) , V_33 ) ;
if ( ! V_48 ) {
V_38 = - V_43 ;
goto V_49;
}
V_48 -> V_9 = V_7 -> V_8 - V_48 -> V_8 ;
V_48 -> V_16 = F_23 ( V_23 -> V_16 ) ;
F_17 ( V_6 , V_48 , true ) ;
V_23 -> V_8 += V_47 ;
V_23 -> V_18 += V_47 ;
V_23 -> V_9 = V_46 ;
goto V_45;
}
V_49:
F_28 ( & V_37 -> V_44 ) ;
return V_38 ;
}
static bool
F_29 ( struct V_5 * V_6 , T_1 V_50 ,
struct V_1 * V_51 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
V_3 = V_6 -> V_2 ;
while ( V_3 ) {
V_7 = F_1 ( V_3 ) ;
if ( V_50 < V_7 -> V_8 )
V_3 = V_3 -> V_11 ;
else if ( V_50 >= F_9 ( V_7 ) )
V_3 = V_3 -> V_12 ;
else {
* V_51 = * V_7 ;
return true ;
}
}
return false ;
}
bool
F_30 ( struct V_36 * V_37 , T_1 V_50 ,
struct V_1 * V_51 , bool V_52 )
{
bool V_53 = false ;
F_26 ( & V_37 -> V_44 ) ;
if ( ! V_52 )
V_53 = F_29 ( & V_37 -> V_42 , V_50 , V_51 ) ;
if ( ! V_53 )
V_53 = F_29 ( & V_37 -> V_40 , V_50 , V_51 ) ;
F_28 ( & V_37 -> V_44 ) ;
return V_53 ;
}
int F_31 ( struct V_36 * V_37 , bool V_52 ,
T_1 V_10 , T_1 V_28 )
{
int V_38 , V_54 ;
F_26 ( & V_37 -> V_44 ) ;
V_38 = F_21 ( & V_37 -> V_42 , V_10 , V_28 ) ;
if ( V_52 ) {
V_54 = F_21 ( & V_37 -> V_40 , V_10 , V_28 ) ;
if ( ! V_38 )
V_38 = V_54 ;
}
F_28 ( & V_37 -> V_44 ) ;
return V_38 ;
}
static int
F_32 ( struct V_5 * V_6 , struct V_1 * V_7 ,
T_1 V_48 )
{
struct V_1 * V_23 ;
T_1 V_32 = V_7 -> V_9 ;
V_23 = F_22 ( sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 )
return - V_34 ;
V_7 -> V_9 = V_48 - V_7 -> V_8 ;
V_23 -> V_8 = V_48 ;
if ( V_7 -> V_15 != V_17 )
V_23 -> V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_23 -> V_9 = V_32 - V_7 -> V_9 ;
V_23 -> V_15 = V_7 -> V_15 ;
V_23 -> V_20 = V_7 -> V_20 ;
V_23 -> V_16 = F_23 ( V_7 -> V_16 ) ;
F_17 ( V_6 , V_23 , false ) ;
return 0 ;
}
int
F_33 ( struct V_36 * V_37 , T_1 V_10 ,
T_1 V_55 )
{
struct V_5 * V_6 = & V_37 -> V_40 ;
T_1 V_28 = V_10 + V_55 ;
struct V_1 * V_7 ;
int V_38 = 0 ;
F_26 ( & V_37 -> V_44 ) ;
V_38 = F_21 ( & V_37 -> V_42 , V_10 , V_28 ) ;
if ( V_38 )
goto V_49;
for ( V_7 = F_10 ( V_6 , V_10 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_8 >= V_28 )
break;
if ( V_7 -> V_15 != V_19 || V_7 -> V_20 )
continue;
if ( V_7 -> V_8 < V_10 ) {
struct V_1 * V_21 = F_5 ( V_7 ) ;
if ( V_21 && F_11 ( V_21 , V_7 ) ) {
T_1 V_47 = V_10 - V_7 -> V_8 ;
V_21 -> V_9 += V_47 ;
V_7 -> V_8 += V_47 ;
V_7 -> V_18 += V_47 ;
V_7 -> V_9 -= V_47 ;
} else {
V_38 = F_32 ( V_6 , V_7 , V_10 ) ;
if ( V_38 )
goto V_49;
}
}
if ( F_9 ( V_7 ) > V_28 ) {
struct V_1 * V_22 = F_7 ( V_7 ) ;
if ( V_22 && F_11 ( V_7 , V_22 ) ) {
T_1 V_47 = V_28 - V_7 -> V_8 ;
V_7 -> V_9 -= V_47 ;
V_22 -> V_8 -= V_47 ;
V_22 -> V_18 -= V_47 ;
V_22 -> V_9 += V_47 ;
} else {
V_38 = F_32 ( V_6 , V_7 , V_28 ) ;
if ( V_38 )
goto V_49;
}
}
if ( V_7 -> V_8 >= V_10 && F_9 ( V_7 ) <= V_28 ) {
V_7 -> V_20 = V_56 ;
V_7 = F_12 ( V_6 , V_7 ) ;
V_7 = F_16 ( V_6 , V_7 ) ;
}
}
V_49:
F_28 ( & V_37 -> V_44 ) ;
return V_38 ;
}
static void F_34 ( struct V_57 * V_58 ,
T_2 V_59 )
{
if ( V_58 -> V_60 != & V_58 -> V_61 ) {
int V_62 = F_35 ( V_59 , V_63 ) , V_64 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ )
F_36 ( V_58 -> V_60 [ V_64 ] ) ;
F_15 ( V_58 -> V_60 ) ;
} else {
F_36 ( V_58 -> V_61 ) ;
}
}
static int F_37 ( struct V_36 * V_37 , T_3 * V_25 ,
T_2 V_59 , T_2 * V_65 )
{
struct V_1 * V_7 ;
int V_51 = 0 ;
F_26 ( & V_37 -> V_44 ) ;
for ( V_7 = F_3 ( & V_37 -> V_40 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_56 )
continue;
( * V_65 ) ++ ;
if ( * V_65 * V_66 > V_59 ) {
V_51 = - V_67 ;
continue;
}
V_25 = F_38 ( V_25 , V_7 -> V_16 -> V_68 . V_69 ,
V_70 ) ;
V_25 = F_39 ( V_25 , V_7 -> V_8 << V_71 ) ;
V_25 = F_39 ( V_25 , V_7 -> V_9 << V_71 ) ;
V_25 = F_39 ( V_25 , 0LL ) ;
* V_25 ++ = F_40 ( V_39 ) ;
V_7 -> V_20 = V_72 ;
}
F_28 ( & V_37 -> V_44 ) ;
return V_51 ;
}
int
F_41 ( struct V_57 * V_58 )
{
struct V_36 * V_37 = F_42 ( F_43 ( V_58 -> V_73 ) -> V_74 ) ;
T_2 V_65 = 0 , V_59 = V_63 ;
T_3 * V_75 ;
int V_51 ;
F_25 ( L_2 , V_76 ) ;
V_58 -> V_61 = F_44 ( V_77 ) ;
if ( ! V_58 -> V_61 )
return - V_34 ;
V_75 = F_45 ( V_58 -> V_61 ) ;
V_58 -> V_60 = & V_58 -> V_61 ;
V_45:
V_51 = F_37 ( V_37 , V_75 + 1 , V_59 , & V_65 ) ;
if ( F_46 ( V_51 ) ) {
F_34 ( V_58 , V_59 ) ;
V_59 = sizeof( T_3 ) + V_66 * V_65 ;
V_65 = 0 ;
V_58 -> V_60 =
F_47 ( F_35 ( V_59 , V_63 ) ,
sizeof( struct V_78 * ) , V_77 ) ;
if ( ! V_58 -> V_60 )
return - V_34 ;
V_75 = F_48 ( V_59 , V_77 , V_79 ) ;
if ( ! V_75 ) {
F_15 ( V_58 -> V_60 ) ;
return - V_34 ;
}
goto V_45;
}
* V_75 = F_40 ( V_65 ) ;
V_58 -> V_80 = sizeof( T_3 ) + V_66 * V_65 ;
if ( F_46 ( V_58 -> V_60 != & V_58 -> V_61 ) ) {
T_3 * V_25 = V_75 ;
int V_64 = 0 ;
for ( V_25 = V_75 ;
V_25 < V_75 + V_58 -> V_80 ;
V_25 += V_63 ) {
V_58 -> V_60 [ V_64 ++ ] = F_49 ( V_25 ) ;
}
}
F_25 ( L_3 , V_76 , V_65 ) ;
return 0 ;
}
void
F_50 ( struct V_57 * V_58 , int V_81 )
{
struct V_36 * V_37 = F_42 ( F_43 ( V_58 -> V_73 ) -> V_74 ) ;
struct V_5 * V_6 = & V_37 -> V_40 ;
struct V_1 * V_7 ;
F_25 ( L_4 , V_76 , V_81 ) ;
F_34 ( V_58 , V_58 -> V_80 ) ;
F_26 ( & V_37 -> V_44 ) ;
for ( V_7 = F_3 ( V_6 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_72 )
continue;
if ( V_81 ) {
V_7 -> V_20 = V_56 ;
} else {
V_7 -> V_15 = V_39 ;
V_7 -> V_20 = 0 ;
}
V_7 = F_12 ( V_6 , V_7 ) ;
V_7 = F_16 ( V_6 , V_7 ) ;
}
F_28 ( & V_37 -> V_44 ) ;
}
