static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
++ V_2 -> V_9 ;
V_2 -> V_5 = V_4 ;
F_2 ( V_6 , L_1 , V_2 -> V_9 ) ;
if ( ! V_5 ) {
F_3 ( & V_4 -> V_10 , & V_2 -> V_11 ) ;
V_2 -> V_12 = V_6 ;
return;
}
if ( V_5 -> V_6 <= V_6 ) {
while ( V_5 -> V_6 <= V_6 ) {
V_8 = V_5 -> V_10 . V_13 ;
if ( V_8 == & V_2 -> V_11 ) {
F_4 ( & V_4 -> V_10 , & V_2 -> V_11 ) ;
V_2 -> V_12 = V_6 ;
return;
}
V_5 = F_5 ( V_8 , struct V_3 , V_10 ) ;
}
F_4 ( & V_4 -> V_10 , & V_5 -> V_10 ) ;
} else {
while ( V_5 -> V_6 > V_6 ) {
V_8 = V_5 -> V_10 . V_14 ;
if ( V_8 == & V_2 -> V_11 ) {
F_3 ( & V_4 -> V_10 , & V_2 -> V_11 ) ;
return;
}
V_5 = F_5 ( V_8 , struct V_3 , V_10 ) ;
}
F_3 ( & V_4 -> V_10 , & V_5 -> V_10 ) ;
}
}
static union V_15 * F_6 ( struct V_1 * V_2 ,
union V_15 * V_16 )
{
union V_15 * V_17 = NULL ;
if ( V_2 -> V_18 < V_2 -> V_19 ) {
V_17 = F_7 ( V_16 , V_16 -> V_20 . V_21 ) ;
if ( V_17 )
V_2 -> V_18 += V_16 -> V_20 . V_21 ;
}
return V_17 ;
}
static union V_15 * F_8 ( struct V_1 * V_2 ,
union V_15 * V_16 )
{
return V_2 -> V_22 ? F_6 ( V_2 , V_16 ) : V_16 ;
}
static void F_9 ( struct V_1 * V_2 , union V_15 * V_16 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_18 -= V_16 -> V_20 . V_21 ;
free ( V_16 ) ;
}
}
static struct V_3 * F_10 ( struct V_1 * V_2 ,
union V_15 * V_16 )
{
struct V_7 * V_23 = & V_2 -> V_23 ;
struct V_3 * V_4 = NULL ;
union V_15 * V_17 ;
V_17 = F_8 ( V_2 , V_16 ) ;
if ( ! V_17 )
return NULL ;
if ( ! F_11 ( V_23 ) ) {
V_4 = F_5 ( V_23 -> V_13 , struct V_3 , V_10 ) ;
F_12 ( & V_4 -> V_10 ) ;
} else if ( V_2 -> V_24 ) {
V_4 = V_2 -> V_24 + V_2 -> V_25 ;
if ( ++ V_2 -> V_25 == V_26 )
V_2 -> V_24 = NULL ;
} else if ( V_2 -> V_18 < V_2 -> V_19 ) {
T_2 V_21 = V_26 * sizeof( * V_4 ) ;
V_2 -> V_24 = malloc ( V_21 ) ;
if ( ! V_2 -> V_24 ) {
F_9 ( V_2 , V_17 ) ;
return NULL ;
}
F_13 ( L_2 V_27 L_3 V_27 L_4 ,
V_2 -> V_18 , V_21 , V_2 -> V_19 ) ;
V_2 -> V_18 += V_21 ;
F_3 ( & V_2 -> V_24 -> V_10 , & V_2 -> V_28 ) ;
V_2 -> V_25 = 2 ;
V_4 = V_2 -> V_24 + 1 ;
} else {
F_13 ( L_5 V_27 L_4 , V_2 -> V_19 ) ;
}
V_4 -> V_16 = V_17 ;
return V_4 ;
}
static struct V_3 *
F_14 ( struct V_1 * V_2 , T_1 V_6 ,
union V_15 * V_16 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( V_2 , V_16 ) ;
if ( V_4 ) {
V_4 -> V_6 = V_6 ;
F_1 ( V_2 , V_4 ) ;
}
return V_4 ;
}
void F_15 ( struct V_1 * V_2 , struct V_3 * V_16 )
{
F_16 ( & V_16 -> V_10 , & V_2 -> V_23 ) ;
V_2 -> V_9 -- ;
F_9 ( V_2 , V_16 -> V_16 ) ;
}
int F_17 ( struct V_1 * V_2 , union V_15 * V_16 ,
struct V_29 * V_30 , T_1 V_31 )
{
T_1 V_6 = V_30 -> time ;
struct V_3 * V_32 ;
if ( ! V_6 || V_6 == ~ 0ULL )
return - V_33 ;
if ( V_6 < V_2 -> V_34 ) {
F_18 ( V_6 , L_6 ) ;
F_18 ( V_2 -> V_34 , L_7 ,
V_2 -> V_35 ) ;
V_2 -> V_36 ++ ;
}
V_32 = F_14 ( V_2 , V_6 , V_16 ) ;
if ( ! V_32 ) {
F_19 ( V_2 , V_37 ) ;
V_32 = F_14 ( V_2 , V_6 , V_16 ) ;
}
if ( ! V_32 )
return - V_38 ;
V_32 -> V_31 = V_31 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_39 = & V_2 -> V_11 ;
struct V_3 * V_40 , * V_41 ;
T_1 V_42 = V_2 -> V_43 ;
T_1 V_44 = V_2 -> V_5 ? V_2 -> V_5 -> V_6 : 0ULL ;
bool V_45 = V_42 == V_46 ;
struct V_47 V_48 ;
int V_49 ;
if ( ! V_42 )
return 0 ;
if ( V_45 )
F_21 ( & V_48 , V_2 -> V_9 , L_8 ) ;
F_22 (iter, tmp, head, list) {
if ( F_23 () )
return 0 ;
if ( V_41 -> V_6 > V_42 )
break;
V_49 = V_2 -> V_50 ( V_2 , V_41 ) ;
if ( V_49 )
return V_49 ;
F_15 ( V_2 , V_41 ) ;
V_2 -> V_34 = V_41 -> V_6 ;
if ( V_45 )
F_24 ( & V_48 , 1 ) ;
}
if ( F_11 ( V_39 ) )
V_2 -> V_5 = NULL ;
else if ( V_44 <= V_42 )
V_2 -> V_5 = F_5 ( V_39 -> V_14 , struct V_3 , V_10 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , enum V_51 V_52 )
{
static const char * const V_53 [] = {
L_9 ,
L_10 ,
L_11 ,
L_12 ,
} ;
int V_54 ;
if ( V_2 -> V_9 == 0 )
return 0 ;
switch ( V_52 ) {
case V_55 :
V_2 -> V_43 = V_46 ;
break;
case V_37 :
{
struct V_3 * V_56 , * V_5 ;
struct V_7 * V_39 = & V_2 -> V_11 ;
V_56 = F_5 ( V_39 -> V_13 , struct V_3 , V_10 ) ;
V_5 = V_2 -> V_5 ;
if ( F_25 ( ! V_5 || F_11 ( V_39 ) , L_13 ) )
return 0 ;
V_2 -> V_43 = V_56 -> V_6 ;
V_2 -> V_43 += ( V_5 -> V_6 - V_56 -> V_6 ) / 2 ;
break;
}
case V_57 :
case V_58 :
default:
break;
} ;
F_18 ( V_2 -> V_43 , L_14 ,
V_53 [ V_52 ] , V_2 -> V_9 ) ;
F_18 ( V_2 -> V_12 , L_15 ) ;
V_54 = F_20 ( V_2 ) ;
if ( ! V_54 ) {
if ( V_52 == V_57 )
V_2 -> V_43 = V_2 -> V_12 ;
V_2 -> V_35 = V_52 ;
}
F_18 ( V_2 -> V_43 , L_16 ,
V_53 [ V_52 ] , V_2 -> V_9 ) ;
F_18 ( V_2 -> V_34 , L_17 ) ;
return V_54 ;
}
void F_26 ( struct V_1 * V_2 , T_3 V_50 )
{
F_27 ( & V_2 -> V_11 ) ;
F_27 ( & V_2 -> V_23 ) ;
F_27 ( & V_2 -> V_28 ) ;
V_2 -> V_19 = ( T_1 ) - 1 ;
V_2 -> V_18 = 0 ;
V_2 -> V_50 = V_50 ;
}
void F_28 ( struct V_1 * V_2 )
{
while ( ! F_11 ( & V_2 -> V_28 ) ) {
struct V_3 * V_16 ;
V_16 = F_5 ( V_2 -> V_28 . V_13 , struct V_3 , V_10 ) ;
F_12 ( & V_16 -> V_10 ) ;
F_9 ( V_2 , V_16 -> V_16 ) ;
free ( V_16 ) ;
}
}
