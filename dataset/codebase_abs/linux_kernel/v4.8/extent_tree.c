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
static void F_17 ( struct V_23 * V_24 )
{
struct V_1 * V_7 , * V_25 ;
F_18 (be, tmp, head, be_list) {
F_14 ( V_7 -> V_16 ) ;
F_15 ( V_7 ) ;
}
}
static void
F_19 ( struct V_5 * V_6 ,
struct V_1 * V_26 , bool V_27 )
{
struct V_2 * * V_28 = & V_6 -> V_2 , * V_29 = NULL ;
struct V_1 * V_7 ;
while ( * V_28 ) {
V_29 = * V_28 ;
V_7 = F_1 ( V_29 ) ;
if ( V_26 -> V_8 < V_7 -> V_8 ) {
if ( V_27 && F_11 ( V_26 , V_7 ) ) {
V_7 -> V_8 = V_26 -> V_8 ;
if ( V_7 -> V_15 != V_17 )
V_7 -> V_18 = V_26 -> V_18 ;
V_7 -> V_9 += V_26 -> V_9 ;
V_7 = F_12 ( V_6 , V_7 ) ;
goto V_30;
}
V_28 = & ( * V_28 ) -> V_11 ;
} else if ( V_26 -> V_8 >= F_9 ( V_7 ) ) {
if ( V_27 && F_11 ( V_7 , V_26 ) ) {
V_7 -> V_9 += V_26 -> V_9 ;
V_7 = F_16 ( V_6 , V_7 ) ;
goto V_30;
}
V_28 = & ( * V_28 ) -> V_12 ;
} else {
F_20 () ;
}
}
F_21 ( & V_26 -> V_4 , V_29 , V_28 ) ;
F_22 ( & V_26 -> V_4 , V_6 ) ;
return;
V_30:
F_14 ( V_26 -> V_16 ) ;
F_15 ( V_26 ) ;
}
static int
F_23 ( struct V_5 * V_6 ,
T_1 V_10 , T_1 V_31 , struct V_23 * V_25 )
{
struct V_1 * V_7 ;
T_1 V_32 = 0 , V_33 = 0 ;
T_1 V_34 ;
T_1 V_35 ;
V_7 = F_10 ( V_6 , V_10 ) ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_8 >= V_31 )
return 0 ;
V_34 = V_7 -> V_18 ;
V_35 = V_7 -> V_9 ;
if ( V_10 > V_7 -> V_8 )
V_32 = V_10 - V_7 -> V_8 ;
if ( F_9 ( V_7 ) > V_31 )
V_33 = F_9 ( V_7 ) - V_31 ;
if ( V_33 > 0 ) {
if ( V_32 > 0 ) {
struct V_1 * V_26 ;
V_26 = F_24 ( sizeof( * V_26 ) , V_36 ) ;
if ( ! V_26 )
return - V_37 ;
V_7 -> V_9 = V_32 ;
V_26 -> V_8 = V_31 ;
if ( V_7 -> V_15 != V_17 ) {
V_26 -> V_18 =
V_34 + V_35 - V_33 ;
}
V_26 -> V_9 = V_33 ;
V_26 -> V_15 = V_7 -> V_15 ;
V_26 -> V_20 = V_7 -> V_20 ;
V_26 -> V_16 = F_25 ( V_7 -> V_16 ) ;
F_19 ( V_6 , V_26 , true ) ;
} else {
V_7 -> V_8 = V_31 ;
if ( V_7 -> V_15 != V_17 ) {
V_7 -> V_18 =
V_34 + V_35 - V_33 ;
}
V_7 -> V_9 = V_33 ;
}
} else {
if ( V_32 > 0 ) {
V_7 -> V_9 = V_32 ;
V_7 = F_7 ( V_7 ) ;
}
while ( V_7 && F_9 ( V_7 ) <= V_31 ) {
struct V_1 * V_38 = F_7 ( V_7 ) ;
F_13 ( & V_7 -> V_4 , V_6 ) ;
F_26 ( & V_7 -> V_39 , V_25 ) ;
V_7 = V_38 ;
}
if ( V_7 && V_7 -> V_8 < V_31 ) {
V_32 = F_9 ( V_7 ) - V_31 ;
V_7 -> V_8 = V_31 ;
if ( V_7 -> V_15 != V_17 )
V_7 -> V_18 += V_7 -> V_9 - V_32 ;
V_7 -> V_9 = V_32 ;
}
}
return 0 ;
}
int
F_27 ( struct V_40 * V_41 , struct V_1 * V_26 )
{
struct V_1 * V_7 ;
struct V_5 * V_6 ;
int V_42 = 0 ;
switch ( V_26 -> V_15 ) {
case V_43 :
case V_19 :
V_6 = & V_41 -> V_44 ;
break;
case V_45 :
case V_17 :
V_6 = & V_41 -> V_46 ;
break;
default:
F_28 ( L_1 ) ;
return - V_47 ;
}
F_29 ( & V_41 -> V_48 ) ;
V_49:
V_7 = F_10 ( V_6 , V_26 -> V_8 ) ;
if ( ! V_7 || V_7 -> V_8 >= F_9 ( V_26 ) ) {
F_19 ( V_6 , V_26 , true ) ;
} else if ( V_26 -> V_8 >= V_7 -> V_8 ) {
if ( F_9 ( V_26 ) <= F_9 ( V_7 ) ) {
F_14 ( V_26 -> V_16 ) ;
F_15 ( V_26 ) ;
} else {
T_1 V_50 = F_9 ( V_26 ) - F_9 ( V_7 ) ;
T_1 V_51 = V_26 -> V_9 - V_50 ;
V_26 -> V_8 += V_51 ;
V_26 -> V_18 += V_51 ;
V_26 -> V_9 = V_50 ;
goto V_49;
}
} else if ( F_9 ( V_26 ) <= F_9 ( V_7 ) ) {
V_26 -> V_9 = V_7 -> V_8 - V_26 -> V_8 ;
F_19 ( V_6 , V_26 , true ) ;
} else {
struct V_1 * V_52 ;
T_1 V_50 = F_9 ( V_26 ) - F_9 ( V_7 ) ;
T_1 V_51 = V_26 -> V_9 - V_50 ;
V_52 = F_30 ( V_26 , sizeof( * V_26 ) , V_36 ) ;
if ( ! V_52 ) {
V_42 = - V_47 ;
goto V_53;
}
V_52 -> V_9 = V_7 -> V_8 - V_52 -> V_8 ;
V_52 -> V_16 = F_25 ( V_26 -> V_16 ) ;
F_19 ( V_6 , V_52 , true ) ;
V_26 -> V_8 += V_51 ;
V_26 -> V_18 += V_51 ;
V_26 -> V_9 = V_50 ;
goto V_49;
}
V_53:
F_31 ( & V_41 -> V_48 ) ;
return V_42 ;
}
static bool
F_32 ( struct V_5 * V_6 , T_1 V_54 ,
struct V_1 * V_55 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
V_3 = V_6 -> V_2 ;
while ( V_3 ) {
V_7 = F_1 ( V_3 ) ;
if ( V_54 < V_7 -> V_8 )
V_3 = V_3 -> V_11 ;
else if ( V_54 >= F_9 ( V_7 ) )
V_3 = V_3 -> V_12 ;
else {
* V_55 = * V_7 ;
return true ;
}
}
return false ;
}
bool
F_33 ( struct V_40 * V_41 , T_1 V_54 ,
struct V_1 * V_55 , bool V_56 )
{
bool V_57 = false ;
F_29 ( & V_41 -> V_48 ) ;
if ( ! V_56 )
V_57 = F_32 ( & V_41 -> V_46 , V_54 , V_55 ) ;
if ( ! V_57 )
V_57 = F_32 ( & V_41 -> V_44 , V_54 , V_55 ) ;
F_31 ( & V_41 -> V_48 ) ;
return V_57 ;
}
int F_34 ( struct V_40 * V_41 , bool V_56 ,
T_1 V_10 , T_1 V_31 )
{
int V_42 , V_58 ;
F_35 ( V_25 ) ;
F_29 ( & V_41 -> V_48 ) ;
V_42 = F_23 ( & V_41 -> V_46 , V_10 , V_31 , & V_25 ) ;
if ( V_56 ) {
V_58 = F_23 ( & V_41 -> V_44 , V_10 , V_31 , & V_25 ) ;
if ( ! V_42 )
V_42 = V_58 ;
}
F_31 ( & V_41 -> V_48 ) ;
F_17 ( & V_25 ) ;
return V_42 ;
}
static int
F_36 ( struct V_5 * V_6 , struct V_1 * V_7 ,
T_1 V_52 )
{
struct V_1 * V_26 ;
T_1 V_35 = V_7 -> V_9 ;
V_26 = F_24 ( sizeof( * V_26 ) , V_36 ) ;
if ( ! V_26 )
return - V_37 ;
V_7 -> V_9 = V_52 - V_7 -> V_8 ;
V_26 -> V_8 = V_52 ;
if ( V_7 -> V_15 != V_17 )
V_26 -> V_18 = V_7 -> V_18 + V_7 -> V_9 ;
V_26 -> V_9 = V_35 - V_7 -> V_9 ;
V_26 -> V_15 = V_7 -> V_15 ;
V_26 -> V_20 = V_7 -> V_20 ;
V_26 -> V_16 = F_25 ( V_7 -> V_16 ) ;
F_19 ( V_6 , V_26 , false ) ;
return 0 ;
}
int
F_37 ( struct V_40 * V_41 , T_1 V_10 ,
T_1 V_59 , T_2 V_60 )
{
struct V_5 * V_6 = & V_41 -> V_44 ;
T_1 V_31 = V_10 + V_59 ;
struct V_1 * V_7 ;
int V_42 = 0 ;
F_35 ( V_25 ) ;
F_29 ( & V_41 -> V_48 ) ;
V_42 = F_23 ( & V_41 -> V_46 , V_10 , V_31 , & V_25 ) ;
if ( V_42 )
goto V_53;
for ( V_7 = F_10 ( V_6 , V_10 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_8 >= V_31 )
break;
if ( V_7 -> V_15 != V_19 || V_7 -> V_20 )
continue;
if ( V_7 -> V_8 < V_10 ) {
struct V_1 * V_21 = F_5 ( V_7 ) ;
if ( V_21 && F_11 ( V_21 , V_7 ) ) {
T_1 V_51 = V_10 - V_7 -> V_8 ;
V_21 -> V_9 += V_51 ;
V_7 -> V_8 += V_51 ;
V_7 -> V_18 += V_51 ;
V_7 -> V_9 -= V_51 ;
} else {
V_42 = F_36 ( V_6 , V_7 , V_10 ) ;
if ( V_42 )
goto V_53;
}
}
if ( F_9 ( V_7 ) > V_31 ) {
struct V_1 * V_22 = F_7 ( V_7 ) ;
if ( V_22 && F_11 ( V_7 , V_22 ) ) {
T_1 V_51 = V_31 - V_7 -> V_8 ;
V_7 -> V_9 -= V_51 ;
V_22 -> V_8 -= V_51 ;
V_22 -> V_18 -= V_51 ;
V_22 -> V_9 += V_51 ;
} else {
V_42 = F_36 ( V_6 , V_7 , V_31 ) ;
if ( V_42 )
goto V_53;
}
}
if ( V_7 -> V_8 >= V_10 && F_9 ( V_7 ) <= V_31 ) {
V_7 -> V_20 = V_61 ;
V_7 = F_12 ( V_6 , V_7 ) ;
V_7 = F_16 ( V_6 , V_7 ) ;
}
}
V_53:
if ( V_41 -> V_62 < V_60 )
V_41 -> V_62 = V_60 ;
F_31 ( & V_41 -> V_48 ) ;
F_17 ( & V_25 ) ;
return V_42 ;
}
static T_3 F_38 ( struct V_40 * V_41 , T_3 V_63 )
{
if ( V_41 -> V_64 )
return sizeof( V_65 ) + V_66 * V_63 ;
else
return sizeof( V_65 ) + V_67 * V_63 ;
}
static void F_39 ( struct V_68 * V_69 ,
T_3 V_70 )
{
if ( V_69 -> V_71 != & V_69 -> V_72 ) {
int V_73 = F_40 ( V_70 , V_74 ) , V_75 ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ )
F_41 ( V_69 -> V_71 [ V_75 ] ) ;
F_42 ( V_69 -> V_76 ) ;
F_15 ( V_69 -> V_71 ) ;
} else {
F_41 ( V_69 -> V_72 ) ;
}
}
static V_65 * F_43 ( struct V_1 * V_7 , V_65 * V_28 )
{
V_28 = F_44 ( V_28 , V_7 -> V_16 -> V_77 . V_78 ,
V_79 ) ;
V_28 = F_45 ( V_28 , V_7 -> V_8 << V_80 ) ;
V_28 = F_45 ( V_28 , V_7 -> V_9 << V_80 ) ;
V_28 = F_45 ( V_28 , 0LL ) ;
* V_28 ++ = F_46 ( V_43 ) ;
return V_28 ;
}
static V_65 * F_47 ( struct V_1 * V_7 , V_65 * V_28 )
{
V_28 = F_45 ( V_28 , V_7 -> V_8 << V_80 ) ;
return F_45 ( V_28 , V_7 -> V_9 << V_80 ) ;
}
static int F_48 ( struct V_40 * V_41 , V_65 * V_28 ,
T_3 V_70 , T_3 * V_63 , T_4 * V_81 )
{
struct V_1 * V_7 ;
int V_55 = 0 ;
F_29 ( & V_41 -> V_48 ) ;
for ( V_7 = F_3 ( & V_41 -> V_44 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_61 )
continue;
( * V_63 ) ++ ;
if ( F_38 ( V_41 , * V_63 ) > V_70 ) {
V_55 = - V_82 ;
continue;
}
if ( V_41 -> V_64 )
V_28 = F_47 ( V_7 , V_28 ) ;
else
V_28 = F_43 ( V_7 , V_28 ) ;
V_7 -> V_20 = V_83 ;
}
* V_81 = V_41 -> V_62 - 1 ;
V_41 -> V_62 = 0 ;
F_31 ( & V_41 -> V_48 ) ;
return V_55 ;
}
int
F_49 ( struct V_68 * V_69 )
{
struct V_40 * V_41 = F_50 ( F_51 ( V_69 -> V_84 ) -> V_85 ) ;
T_3 V_63 = 0 , V_70 = V_74 ;
V_65 * V_76 ;
int V_55 ;
F_28 ( L_2 , V_86 ) ;
V_69 -> V_72 = F_52 ( V_87 ) ;
if ( ! V_69 -> V_72 )
return - V_37 ;
V_76 = F_53 ( V_69 -> V_72 ) ;
V_69 -> V_71 = & V_69 -> V_72 ;
V_49:
V_55 = F_48 ( V_41 , V_76 + 1 , V_70 , & V_63 , & V_69 -> V_88 ) ;
if ( F_54 ( V_55 ) ) {
F_39 ( V_69 , V_70 ) ;
V_70 = F_38 ( V_41 , V_63 ) ;
V_63 = 0 ;
V_69 -> V_71 =
F_55 ( F_40 ( V_70 , V_74 ) ,
sizeof( struct V_89 * ) , V_87 ) ;
if ( ! V_69 -> V_71 )
return - V_37 ;
V_76 = F_56 ( V_70 , V_87 , V_90 ) ;
if ( ! V_76 ) {
F_15 ( V_69 -> V_71 ) ;
return - V_37 ;
}
goto V_49;
}
* V_76 = F_46 ( V_63 ) ;
V_69 -> V_91 = F_38 ( V_41 , V_63 ) ;
if ( F_54 ( V_69 -> V_71 != & V_69 -> V_72 ) ) {
void * V_28 = V_76 , * V_31 = V_28 + V_69 -> V_91 ;
struct V_89 * V_89 = NULL ;
int V_75 = 0 ;
V_69 -> V_76 = V_76 ;
for ( ; V_28 < V_31 ; V_28 += V_74 ) {
V_89 = F_57 ( V_28 ) ;
V_69 -> V_71 [ V_75 ++ ] = V_89 ;
F_58 ( V_89 ) ;
}
}
F_28 ( L_3 , V_86 , V_63 ) ;
return 0 ;
}
void
F_59 ( struct V_68 * V_69 , int V_92 )
{
struct V_40 * V_41 = F_50 ( F_51 ( V_69 -> V_84 ) -> V_85 ) ;
struct V_5 * V_6 = & V_41 -> V_44 ;
struct V_1 * V_7 ;
F_28 ( L_4 , V_86 , V_92 ) ;
F_39 ( V_69 , V_69 -> V_91 ) ;
F_29 ( & V_41 -> V_48 ) ;
for ( V_7 = F_3 ( V_6 ) ; V_7 ; V_7 = F_7 ( V_7 ) ) {
if ( V_7 -> V_15 != V_19 ||
V_7 -> V_20 != V_83 )
continue;
if ( V_92 ) {
V_7 -> V_20 = V_61 ;
} else {
V_7 -> V_15 = V_43 ;
V_7 -> V_20 = 0 ;
}
V_7 = F_12 ( V_6 , V_7 ) ;
V_7 = F_16 ( V_6 , V_7 ) ;
}
F_31 ( & V_41 -> V_48 ) ;
}
