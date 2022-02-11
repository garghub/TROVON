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
static T_2 F_34 ( T_2 V_57 )
{
return sizeof( V_58 ) +
V_59 * V_57 ;
}
static void F_35 ( struct V_60 * V_61 ,
T_2 V_62 )
{
if ( V_61 -> V_63 != & V_61 -> V_64 ) {
int V_65 = F_36 ( V_62 , V_66 ) , V_67 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
F_37 ( V_61 -> V_63 [ V_67 ] ) ;
F_38 ( V_61 -> V_68 ) ;
F_15 ( V_61 -> V_63 ) ;
} else {
F_37 ( V_61 -> V_64 ) ;
}
}
static int F_39 ( struct V_36 * V_37 , V_58 * V_25 ,
T_2 V_62 , T_2 * V_57 )
{
struct V_1 * V_7 ;
int V_51 = 0 ;
F_26 ( & V_37 -> V_44 ) ;
for ( V_7 = F_3 ( & V_37 -> V_40 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_56 )
continue;
( * V_57 ) ++ ;
if ( F_34 ( * V_57 ) > V_62 ) {
V_51 = - V_69 ;
continue;
}
V_25 = F_40 ( V_25 , V_7 -> V_16 -> V_70 . V_71 ,
V_72 ) ;
V_25 = F_41 ( V_25 , V_7 -> V_8 << V_73 ) ;
V_25 = F_41 ( V_25 , V_7 -> V_9 << V_73 ) ;
V_25 = F_41 ( V_25 , 0LL ) ;
* V_25 ++ = F_42 ( V_39 ) ;
V_7 -> V_20 = V_74 ;
}
F_28 ( & V_37 -> V_44 ) ;
return V_51 ;
}
int
F_43 ( struct V_60 * V_61 )
{
struct V_36 * V_37 = F_44 ( F_45 ( V_61 -> V_75 ) -> V_76 ) ;
T_2 V_57 = 0 , V_62 = V_66 ;
V_58 * V_68 ;
int V_51 ;
F_25 ( L_2 , V_77 ) ;
V_61 -> V_64 = F_46 ( V_78 ) ;
if ( ! V_61 -> V_64 )
return - V_34 ;
V_68 = F_47 ( V_61 -> V_64 ) ;
V_61 -> V_63 = & V_61 -> V_64 ;
V_45:
V_51 = F_39 ( V_37 , V_68 + 1 , V_62 , & V_57 ) ;
if ( F_48 ( V_51 ) ) {
F_35 ( V_61 , V_62 ) ;
V_62 = F_34 ( V_57 ) ;
V_57 = 0 ;
V_61 -> V_63 =
F_49 ( F_36 ( V_62 , V_66 ) ,
sizeof( struct V_79 * ) , V_78 ) ;
if ( ! V_61 -> V_63 )
return - V_34 ;
V_68 = F_50 ( V_62 , V_78 , V_80 ) ;
if ( ! V_68 ) {
F_15 ( V_61 -> V_63 ) ;
return - V_34 ;
}
goto V_45;
}
* V_68 = F_42 ( V_57 ) ;
V_61 -> V_81 = F_34 ( V_57 ) ;
if ( F_48 ( V_61 -> V_63 != & V_61 -> V_64 ) ) {
void * V_25 = V_68 , * V_28 = V_25 + V_61 -> V_81 ;
struct V_79 * V_79 = NULL ;
int V_67 = 0 ;
V_61 -> V_68 = V_68 ;
for ( ; V_25 < V_28 ; V_25 += V_66 ) {
V_79 = F_51 ( V_25 ) ;
V_61 -> V_63 [ V_67 ++ ] = V_79 ;
F_52 ( V_79 ) ;
}
}
F_25 ( L_3 , V_77 , V_57 ) ;
return 0 ;
}
void
F_53 ( struct V_60 * V_61 , int V_82 )
{
struct V_36 * V_37 = F_44 ( F_45 ( V_61 -> V_75 ) -> V_76 ) ;
struct V_5 * V_6 = & V_37 -> V_40 ;
struct V_1 * V_7 ;
F_25 ( L_4 , V_77 , V_82 ) ;
F_35 ( V_61 , V_61 -> V_81 ) ;
F_26 ( & V_37 -> V_44 ) ;
for ( V_7 = F_3 ( V_6 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_74 )
continue;
if ( V_82 ) {
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
